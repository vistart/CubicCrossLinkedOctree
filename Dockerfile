FROM gcc:latest
LABEL maintainer "vistart <i@vistart.me>"

RUN sed -i 's/deb.debian.org/mirror.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
RUN sed -i 's/security.debian.org/mirror.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
RUN apt-get update && apt-get upgrade -y && apt install cmake gdb build-essential -y

WORKDIR /root

RUN git clone https://github.com/vistart/CubicCrossLinkedOctree

WORKDIR /root/CubicCrossLinkedOctree

RUN cmake . DCMAKE_BUILD_TYPE=Debug && cmake --build . -j 4
CMD [./CubicCrossLinkedOctree]
