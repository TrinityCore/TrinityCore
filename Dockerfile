# --- Stage 1: Builder ---
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Abhängigkeiten installieren
RUN apt-get update && apt-get install -y \
    git clang cmake make gcc g++ libmariadb-dev libssl-dev \
    libbz2-dev libreadline-dev libncurses-dev \
    libboost-all-dev p7zip default-libmysqlclient-dev \
    libmariadb-dev-compat gettext curl unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src

# TrinityCore Master klonen
RUN git clone -b master --depth 1 https://github.com/TrinityCore/TrinityCore.git

WORKDIR /usr/src/TrinityCore/build

# CMake konfigurieren
RUN cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/trinitycore \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DWITH_WARNINGS=0 \
    -DTOOLS=1 \
    -DSCRIPTS=static

# Kompilieren (nutzt nproc, GitHub Action regelt RAM via Swap)
RUN make -j$(nproc) && make install

# SQL Dateien sichern
RUN cp -r /usr/src/TrinityCore/sql /opt/trinitycore/sql

# --- Stage 2: Runtime ---
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    libmariadb3 libssl3 libboost-system1.74.0 \
    libboost-filesystem1.74.0 libboost-thread1.74.0 libboost-program-options1.74.0 \
    libboost-iostreams1.74.0 libreadline8 libncurses6 \
    netcat iputils-ping \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt/trinitycore

COPY --from=builder /opt/trinitycore /opt/trinitycore

# Hier kopieren wir das Skript aus dem Ordner "scripts"
COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

RUN groupadd -r trinity && useradd -r -g trinity trinity
RUN chown -R trinity:trinity /opt/trinitycore

EXPOSE 3724 8085

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
