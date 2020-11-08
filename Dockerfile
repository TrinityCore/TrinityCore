# specify the node base image with your desired version
FROM ubuntu:rolling
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt update && apt upgrade -y && apt install -y \
   mysql-client\
   git\
   clang\
   cmake\
   make\
   gcc\
   g++\
   libmysqlclient-dev\
   libssl-dev\
   libbz2-dev\
   libreadline-dev\
   libncurses-dev\
   libboost-all-dev\
   default-libmysqlclient-dev\
   tzdata




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

