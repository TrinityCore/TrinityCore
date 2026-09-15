# Self-hosted GitHub Actions runner for the deploy job in .github/workflows/ci.yml.
# Base image handles registration/deregistration with GitHub; we add the
# Docker CLI + compose plugin so the runner can drive the host's Docker
# daemon over the mounted /var/run/docker.sock (see compose.yml in this dir).
#
# Verify current tags at https://github.com/myoung34/docker-github-actions-runner
# before building — ubuntu-jammy (22.04) is used here as the stable baseline.
FROM ghcr.io/myoung34/github-runner:ubuntu-jammy

RUN apt-get update && apt-get install -y --no-install-recommends \
      ca-certificates curl gnupg \
    && install -m 0755 -d /etc/apt/keyrings \
    && curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc \
    && chmod a+r /etc/apt/keyrings/docker.asc \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu $(. /etc/os-release && echo $VERSION_CODENAME) stable" \
       > /etc/apt/sources.list.d/docker.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends docker-ce-cli docker-compose-plugin \
    && rm -rf /var/lib/apt/lists/*
