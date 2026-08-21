# AI TrinityCore — Development Setup

Implements Etapa 1 (Development Infrastructure) of
[AI_TrinityCore_Roadmap_Etapa_1_2.md](AI_TrinityCore_Roadmap_Etapa_1_2.md).

## Origin

- Base: `TrinityCore/TrinityCore`, branch `3.3.5`.
- Upstream commit this project started from: `2a64b72689cc8d797e4c93a0c96dfa2dc06f64c8`
  ("Core/Misc: Reduce differences between branches", 2026-08-11).
- Git remotes:
  - `upstream` → `https://github.com/TrinityCore/TrinityCore.git` (pull only, for merging upstream 3.3.5 fixes)
  - `origin` → not yet configured; point it at your own fork before pushing
    (`git remote add origin <your-fork-url>`).
- Development branch: `ai-world`.

## Prerequisites (host)

- Git
- Docker Engine + Docker Compose plugin
- NVIDIA driver + NVIDIA Container Toolkit (for `make gpu-test` and the future `ai-server` GPU workload)

## First-time setup

```bash
make bootstrap   # creates .env from .env.example, runtime/ dirs, builds dev image
```

Edit `.env` if you need non-default ports or credentials.

## WoW game data (one-time, not committed)

`worldserver` needs `dbc`, `maps`, `vmaps` and `mmaps` extracted from your own
licensed 3.3.5a client using TrinityCore's map/vmap/mmap extractors (built as
part of `tools/` in this source tree). Place the results under:

```text
runtime/data/dbc
runtime/data/maps
runtime/data/vmaps
runtime/data/mmaps
```

This directory is gitignored and never copied into any image; it's mounted
into `worldserver` at runtime via `WOW_DATA_DIR` (see `.env.example`).

## Day-to-day workflow

```bash
make start           # bring up mysql, authserver, worldserver, ai-server, tc-dev
make build            # incremental build inside tc-dev (ccache + persistent /build volume)
make restart-world     # restart only worldserver after a rebuild
make world-logs        # tail worldserver logs
make shell              # interactive shell in the dev container
make db-shell            # mysql shell as the trinity user
```

Clean build and DB reset are explicit and destructive by design:

```bash
make clean-build   # wipe /build and rebuild from scratch
make reset-db       # drop and recreate the mysql volume
```

## GPU check

```bash
make gpu-test
```

Runs `nvidia-smi` inside a throwaway container via the `gpu-check` Compose
profile to confirm the host driver + NVIDIA Container Toolkit are wired up
correctly. `ai-server` is the only service intended to touch the GPU —
`worldserver` never runs inference directly (see roadmap section 1.10).

## Repository layout

See section [1.2](AI_TrinityCore_Roadmap_Etapa_1_2.md#12-struktura-repozitáře)
of the roadmap. `src/`, `sql/`, `cmake/` etc. are the unmodified TrinityCore
tree; `docker/`, `deploy/`, `compose*.yml`, `.env.example` and this file are
the additions for this project. `runtime/` is host-only, gitignored state.

## Status

This scaffold covers the repository/Compose/Makefile shape from Etapa 1.
The remaining checkboxes in the roadmap (DB bootstrap verification, game
data extraction docs, debugging/observability, the async AI health bridge,
and all of Etapa 2) are still open work.
