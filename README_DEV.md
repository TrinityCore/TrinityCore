# AI TrinityCore — Development Setup

Implements Etapa 1 (Development Infrastructure) of
[AI_TrinityCore_Roadmap_Etapa_1_2.md](AI_TrinityCore_Roadmap_Etapa_1_2.md).

## Origin

- Base: `TrinityCore/TrinityCore`, branch `3.3.5`.
- Upstream commit this project started from: `2a64b72689cc8d797e4c93a0c96dfa2dc06f64c8`
  ("Core/Misc: Reduce differences between branches", 2026-08-11).
- `origin` is a real GitHub **fork** of `TrinityCore/TrinityCore`
  (`https://github.com/LoubekJan/WoWBehaviorAI.git`), created via GitHub's
  Fork button — not a fresh repo populated with `git push`. TrinityCore's
  history contains old SVN-import commits with malformed committer emails
  that GitHub's push-time `fsck` rejects unconditionally, so a plain
  `git push` of the full history to a brand-new repo cannot work; forking
  is a server-side copy and doesn't go through that check.
- Git remotes:
  - `origin` → `https://github.com/LoubekJan/WoWBehaviorAI.git` (our fork; `3.3.5`, `master`, etc. mirror upstream, `ai-world` carries our scaffold)
  - `upstream` → `https://github.com/TrinityCore/TrinityCore.git` (pull only, for merging upstream `3.3.5` fixes)
- Development branch: `ai-world`, branched from `3.3.5` at the commit above.
  `git fetch upstream && git merge upstream/3.3.5` works as a normal merge
  since `ai-world` shares real history with `upstream/3.3.5`.

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

## Database bootstrap

`deploy/mysql/01-init-users.sh` creates the `auth`/`characters`/`world`
databases and the `TC_DB_USER`/`TC_DB_PASSWORD` application user (from
`.env`) on first `mysql` start. From there, TrinityCore's own updater
applies the base schema and SQL updates on `authserver`/`worldserver`
startup (`Updates.EnableDatabases` + `Updates.AutoSetup = 1` in
`deploy/*.conf`) — that's the empty-schema bootstrap.

It does **not** import world content (creatures, quests, items — the TDB
dataset). That has to be downloaded separately and imported into `world`
before the server is actually playable; see the `TDB335.*` tags on
`upstream`/`origin` for available dataset versions, per roadmap section 1.7
("pin the initial world/TDB dataset version").

`TC_DB_USER`/`TC_DB_PASSWORD` are the single source of truth for DB
credentials — set them in `.env`, never edit them directly in
`deploy/*.conf` (those files use `__TC_DB_USER__`/`__TC_DB_PASSWORD__`
placeholders, rendered at container start by
`docker/scripts/render-conf-and-run.sh`).

## Day-to-day workflow

Order matters: `authserver`/`worldserver` run binaries out of the
persistent `/build` volume, so it needs to exist before `start`.

```bash
make bootstrap          # .env, runtime/ dirs, build the dev image
make build                # compile TrinityCore into the build-data volume (throwaway tc-dev container)
make start                  # bring up mysql, authserver, worldserver, ai-server
make restart-world             # restart only worldserver after a rebuild
make world-logs                  # tail worldserver logs
make shell                         # throwaway interactive shell in the dev container
make db-shell                        # mysql shell as the TC_DB_USER application user
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

This scaffold covers the repository/Compose/Makefile shape from Etapa 1,
with real shared history against `upstream/3.3.5`, working DB credential
plumbing, and mysql/ai-server kept off the host network by default. None
of it has been run yet — `make bootstrap && make build && make start` is
untested against an actual Docker/GPU host.

Still open: DB bootstrap verification against a real container run, TDB
dataset import, game data extraction docs, debugging/observability
(section 1.9), the async AI health bridge (1.11), and all of Etapa 2.
