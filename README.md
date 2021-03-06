# CubicCrossLinkedOctree

## Install

### Ubuntu 20.04

Clone repository from GitHub:

> We need to recursively clone the repos, as we refer to other code repositories as submodules.

```
git clone --recurse https://github.com/vistart/CubicCrossLinkedOctree
```

Switch to the `third-party/vcpkg` directory:

```
cd CubicCrossLinkedOctree/third-party/vcpkg
```

Bootstrap the [vcpkg](https://github.com/microsoft/vcpkg)

```
./bootstrap-vcpkg.sh
```

The above command will download `cmake` and `ninja-build`, regardless of whether they exist in the system. If you want to use the `cmake` and `ninja-build` installed in the system, please append the `-useSystemBinaries` parameter, as follows:

```
./bootstrap-vcpkg.sh -useSystemBinary
```

> Note: You need to make sure that `gcc`, `g++`, `gdb`, `build-essential`, `cmake`, `ninja-build` are available in the system. If not, you can install it with the following command:

```
sudo apt install gcc g++ gdb build-essential cmake ninja-build
```

> Note: the `cmake` installed above is not version `3.17.2` recommended by `vcpkg`, therefore, [`cmake-3.17.2`](https://github.com/Kitware/CMake/releases/download/v3.17.2/cmake-3.17.2-Linux-x86_64.tar.gz) will still be automatically downloaded and installed when third-party code packages are installed later. If you have prepared cmake-3.17.2 and don't want to download it before installing the third-party code package, you can place the downloaded `cmake-3.17.2-Linux-x86_64.tar.gz` in the following directory:

```
CubicCrossLinkedOctree/third-party/vcpkg/downloads
```

Then execute the installation command, as follows:

```
CubicCrossLinkedOctree/third-party/vcpkg/vcpkg install boost-asio boost-thread
```

> Note: The above command will automatically install the code package adapted to the current platform, such as `x64-linux`. If the code package you need does not match the current platform, you can specify the platform name after the code package name, as follows:

```
CubicCrossLinkedOctree/third-party/vcpkg/vcpkg install boost-asio:x64-osx boost-thread:x64-osx
```

Available architecture triplets:

VCPKG built-in triplets:

- `arm-uwp`
- `arm64-windows`
- `x64-linux`
- `x64-osx`
- `x64-urp`
- `x64-windows-static`
- `x64-windows`
- `x86-windows`

VCPKG community triplets:

- `arm-ios`
- `arm-mingw-dynamic`
- `arm-mingw-static`
- `arm-windows`
- `arm64-ios`
- `arm64-mingw-dynamic`
- `arm64-mingw-static`
- `arm64-osx`
- `arm64-uwp`
- `arm64-windows-static`
- `s390x-linux`
- `wasm32-emscripten`
- `x64-ios`
- `x64-mingw-dynamic`
- `x64-mingw-static`
- `x64-osx-dynamic`
- `x64-windows-static-md`
- `x86-ios`
- `x86-mingw-dynamic`
- `x86-mingw-static`
- `x86-uwp`
- `x86-windows-static-md`
- `x86-windows-static`

### Windows

> Note: It is highly recommended to use [PowerShell](https://github.com/powershell/powershell).

Clone repository from GitHub:

```
git clone https://github.com/Microsoft/vcpkg
```

Switch to the `vcpkg` directory:

```
cd vcpkg
```

Bootstrap the [vcpkg](https://github.com/microsoft/vcpkg)

```
./bootstrap-vcpkg.bat
```

Then execute the integration command and installation command, as follows:

```
.\vcpkg.exe integrate powershell
```

> Maybe you need to start a new PowerShell prompt window to take effect the change.

```
.\vcpkg.exe install boost-asio boost-thread pybind11
```

> Note: The x86 code package is downloaded by default, regardless of whether you have an x86 or x86_64 architecture. If you want to use the x86_64 code package, please append `x64-windows` to the package name, as shown below:

```
.\vcpkg install boost-asio:x64-windows boost-thread:x64-windows pybind11:x64-windows
```
