FROM gcc:latest
LABEL maintainer "vistart <i@vistart.me>"

RUN sed -i 's/deb.debian.org/mirror.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
RUN sed -i 's/security.debian.org/mirror.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
RUN apt-get update && apt-get upgrade -y && apt install cmake gdb build-essential tar curl zip unzip -y

WORKDIR /root

# Install vcpkg

RUN git clone -b 2020.06 https://github.com/microsoft/vcpkg && ./vcpkg/bootstrap-vcpkg.sh && ./vcpkg/vcpkg install boost-asio boost-thread

WORKDIR /root

# Install

RUN git clone https://github.com/vistart/CubicCrossLinkedOctree

RUN cmake -B CubicCrossLinkedOctree -S . -DCMAKE_TOOLCHAIN_FILE=/root/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Debug && cmake --build CubicCrossLinkedOctree -j 4
CMD [ './CubicCrossLinkedOctree/CubicCrossLinkedOctree' ]
