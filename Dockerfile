FROM registry.cn-shanghai.aliyuncs.com/vistart_public/ubuntu-cpp:20.04
LABEL maintainer "vistart <i@vistart.me>"

# Install

RUN git clone --recurse https://github.com/vistart/CubicCrossLinkedOctree

WORKDIR /root/CubicCrossLinkedOctree/third-party/vcpkg

RUN ./bootstrap-vcpkg.sh
RUN ./vcpkg install boost-asio boost-thread

RUN cmake -B CubicCrossLinkedOctree -S . -DCMAKE_BUILD_TYPE=Debug && cmake --build CubicCrossLinkedOctree -j 4
CMD [ './CubicCrossLinkedOctree/CubicCrossLinkedOctree' ]
