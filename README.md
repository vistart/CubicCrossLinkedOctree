# CubicCrossLinkedOctree

## Install

### Ubuntu 20.04

Clone repository from GitHub:

> We need to recursively clone the repos, as we refer to other code repositories as submodules.

```
git clone --recurse https://github.com/vistart/CubicCrossLinkedOctree
```

Bootstrap the [vcpkg](https://github.com/microsoft/vcpkg)

```
CubicCrossLinkedOctree/third-party/vcpkg/bootstrap-vcpkg.sh
```

The above command will download `cmake` and `ninja-build`, regardless of whether they exist in the system. If you want to use the `cmake` and `ninja-build` installed in the system, please append the `-useSystemBinaries` parameter, as follows:

```
CubicCrossLinkedOctree/third-party/vcpkg/bootstrap-vcpkg.sh -useSystemBinary
```

> Note: You need to make sure that `gcc`, `g++`, `gdb`, `build-essential`, `cmake`, `ninja-build` are available in the system. If not, you can install it with the following command:

```
sudo apt install gcc g++ gdb build-essential cmake ninja-build
```

> Note: the `cmake` installed above is not version `3.17.2` recommended by `vcpkg`, therefore, [`cmake-3.17.2`](https://github.com/Kitware/CMake/releases/download/v3.17.2/cmake-3.17.2-Linux-x86_64.tar.gz) will still be automatically downloaded and installed when third-party code packages are installed later. If you have prepared cmake-3.17.2 and don't wamnt to download it before installing the third-party code package, you can place thedownloaded `cmake-3.17.2-Linux-x86_64.tar.gz` in the following directory:

```
CubicCrossLinkedOctree/third-party/vcpkg/downloads
```






```
CubicCrossLinkedOctree/third-party/vcpkg/vcpkg install boost-asio boost-thread
```

### Windows

```
git clone --recurse https://github.com/vistart/CubicCrossLinkedOctree
CubicCrossLinkedOctree\third-party\vcpkg\bootstrap-vcpkg.bat
CubicCrossLinkedOctree\third-party\vcpkg\vcpkg install boost-asio boost-thread
```