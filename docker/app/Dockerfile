FROM debian:stretch

LABEL maintainer="Jonas Kervin Hansen"

WORKDIR /usr/src

ENV TZ=UTC
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update \
    && apt -y install \
        git \
        clang cmake make gcc g++ \
        libmariadbclient-dev mariadb-server \
        libssl1.0-dev libbz2-dev libreadline-dev libncurses-dev libboost-all-dev \
        p7zip

RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang 100

EXPOSE 8085
EXPOSE 3724

COPY start-build.sh /usr/local/bin/start-build
RUN chmod +x /usr/local/bin/start-build

COPY start-container /usr/local/bin/start-container
RUN chmod +x /usr/local/bin/start-container

ENTRYPOINT ["start-container"]
