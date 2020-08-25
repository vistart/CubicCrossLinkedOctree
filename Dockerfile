FROM registry.cn-shanghai.aliyuncs.com/vistart_public/ubuntu-cpp:20.04
LABEL maintainer "vistart <i@vistart.me>"

# Install

WORKDIR /root

RUN git clone --recurse https://github.com/vistart/CubicCrossLinkedOctree

WORKDIR /root/CubicCrossLinkedOctree/third-party/vcpkg

RUN ./bootstrap-vcpkg.sh -useSystemBinaries
COPY cmake-3.17.2-Linux-x86_64.tar.gz /root/CubicCrossLinkedOctree/third-party/vcpkg/downloads
RUN ./vcpkg install boost-asio boost-thread

WORKDIR /root

RUN cmake -B CubicCrossLinkedOctree -S . -DCMAKE_BUILD_TYPE=Debug && cmake --build CubicCrossLinkedOctree -j 4
CMD [ '/root/CubicCrossLinkedOctree/CubicCrossLinkedOctree' ]
