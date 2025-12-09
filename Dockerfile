# --- Stage 1: Builder ---
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    git clang cmake make gcc g++ \
    libmariadb-dev libssl-dev \
    libbz2-dev libreadline-dev libncurses-dev \
    libboost-all-dev p7zip-full \
    libmariadb-dev-compat gettext curl unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src

# Clone TrinityCore (Master Branch)
RUN git clone -b master --depth 1 https://github.com/TrinityCore/TrinityCore.git

WORKDIR /usr/src/TrinityCore/build

# Configure CMake
RUN cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/trinitycore \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DWITH_WARNINGS=0 \
    -DTOOLS=1 \
    -DSCRIPTS=static \
    -DCMAKE_BUILD_TYPE=Release

# Compile and Install
RUN make -j$(nproc) && make install

# Comment: Critical step! We delete the huge build directory BEFORE copying the SQL files.
# This prevents the "No space left on device" error during the Docker build.
RUN rm -rf /usr/src/TrinityCore/build

# Copy SQL files
RUN cp -r /usr/src/TrinityCore/sql /opt/trinitycore/sql


# --- Stage 2: Runtime ---
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    libmariadb3 \
    libssl3t64 \
    libboost-system1.83.0 \
    libboost-filesystem1.83.0 \
    libboost-thread1.83.0 \
    libboost-program-options1.83.0 \
    libboost-iostreams1.83.0 \
    libreadline8t64 \
    libncurses6 \
    netcat-openbsd iputils-ping \
    mariadb-client curl jq p7zip-full unzip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /opt/trinitycore

# Copy compiled files
COPY --from=builder /opt/trinitycore /opt/trinitycore

# Backup config files (Fix for empty volume issue)
RUN mkdir -p /opt/trinitycore/etc-backup && \
    cp -r /opt/trinitycore/etc/* /opt/trinitycore/etc-backup/

COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# User setup
RUN groupadd -r trinity && useradd -r -g trinity trinity
RUN chown -R trinity:trinity /opt/trinitycore

EXPOSE 3724 8085

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
