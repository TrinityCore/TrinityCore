# specify the node base image with your desired version
FROM ubuntu:bionic

RUN apt-get update && apt-get install -y \
   mysql-client\
   git\
   clang\
   cmake\
   make\
   gcc\
   g++\
   libmysqlclient-dev\
   libssl1.0-dev\
   libreadline-dev\
   libncurses-dev\
   libboost-all-dev



# Create app directory
WORKDIR /usr/src/app

COPY . .

WORKDIR /usr/src/app/build

#default path on docker image /usr/local
RUN cmake ../ -DCMAKE_INSTALL_PREFIX=/usr/local/ -DTOOLS=0

#following compile using all procs and install the server
RUN make -j $(nproc) install
RUN make clean

WORKDIR /usr/local/bin

