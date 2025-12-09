# --- Stage 1: Builder ---
# Automatically selects the correct architecture (amd64/arm64)
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

# Configure CMake (Release mode, Tools enabled)
# CMake detects the CPU architecture automatically
RUN cmake ../ -DCMAKE_INSTALL_PREFIX=/opt/trinitycore \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DWITH_WARNINGS=0 \
    -DTOOLS=1 \
    -DSCRIPTS=static \
    -DCMAKE_BUILD_TYPE=Release

# Compile and Install
# Using all available cores for faster compilation
RUN make -j$(nproc) && make install

# Copy SQL files for the auto-setup script
RUN cp -r /usr/src/TrinityCore/sql /opt/trinitycore/sql


# --- Stage 2: Runtime ---
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install runtime dependencies
# These packages are available for both amd64 and arm64 architectures
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

# Copy compiled artifacts from the builder stage
COPY --from=builder /opt/trinitycore /opt/trinitycore

# Create a backup of the configuration files.
# This is critical to restore files if the user mounts an empty volume to /etc.
RUN mkdir -p /opt/trinitycore/etc-backup && \
    cp -r /opt/trinitycore/etc/* /opt/trinitycore/etc-backup/

COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Create a non-root user for security
RUN groupadd -r trinity && useradd -r -g trinity trinity
RUN chown -R trinity:trinity /opt/trinitycore

EXPOSE 3724 8085

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
