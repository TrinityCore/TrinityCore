# AI TrinityCore — Development Setup

Development guide for the WoWBehaviorAI fork of TrinityCore `3.3.5`.

For architecture and milestone history see [AIWorld_Current_Roadmap.md](AIWorld_Current_Roadmap.md).

## Current status

The development stack has been exercised on a real Ubuntu/NVIDIA host. The old README status that said Docker/GPU runtime was untested is no longer true.

Runtime-verified infrastructure includes:

- TrinityCore build/install in Docker with persistent `/build` and `ccache` volumes;
- MySQL bootstrap and TDB import;
- `authserver`, `worldserver`, MySQL and `ai-server` through Compose;
- mounted `dbc/maps/vmaps/mmaps` game data;
- LAN WoW 3.3.5a client login;
- versioned realm configuration via `make configure-realm`;
- worldserver restart without losing DB state;
- NVIDIA Container Toolkit visibility from Docker.

Etapa 2 is CLOSED / POC COMPLETE, including the scheduler/tier foundation, farmer, group coordination and local LLM dynamic quest vertical slices. The next planned work is Etapa 3 — Elwynn scope and complete spawn census. The roadmap above owns detailed milestone status and evidence.

## Origin

- Base: `TrinityCore/TrinityCore`, branch `3.3.5`.
- Upstream starting commit: `2a64b72689cc8d797e4c93a0c96dfa2dc06f64c8`.
- `origin`: `https://github.com/LoubekJan/WoWBehaviorAI.git`.
- `upstream`: `https://github.com/TrinityCore/TrinityCore.git`.
- Development branch: `ai-world`.

The repository keeps TrinityCore history, so normal upstream merges remain possible.

## Prerequisites

Host requirements:

- Git
- Docker Engine
- Docker Compose plugin
- NVIDIA driver + NVIDIA Container Toolkit for GPU checks/future inference
- legally obtained WoW 3.3.5a client data for `dbc/maps/vmaps/mmaps`

## First-time setup

```bash
make bootstrap
```

This creates `.env` from `.env.example` when needed, prepares runtime directories and builds the development image.

Edit `.env` before first real startup. DB credentials and realm/network settings should come from `.env`, not hand-edited deployment files.

## WoW game data

Place extracted client data under:

```text
runtime/data/dbc
runtime/data/maps
runtime/data/vmaps
runtime/data/mmaps
```

`runtime/` is host-only, gitignored state and is mounted into `worldserver`.

A precise step-by-step extraction document is still a hardening backlog item.

## Database bootstrap

`deploy/mysql/01-init-users.sh` creates the TrinityCore databases and application DB user on first MySQL start. TrinityCore's own updater applies schema updates from the mounted `sql/` tree.

Import a pinned TDB world dataset before first useful worldserver startup:

```bash
make db-import-tdb TDB_VERSION=TDB335.25101 TDB_SHA256=<sha256>
```

The import helper waits for MySQL and verifies the checksum when provided.

### Realm address

Set the realm values in `.env`, then run:

```bash
make configure-realm
```

For a client on another machine, `REALM_ADDRESS` must be a reachable server address, not `127.0.0.1`.

## Day-to-day workflow

Typical C++ workflow:

```bash
git checkout ai-world
git pull --ff-only origin ai-world
git log -1 --oneline
make build
make restart-world
make world-logs
```

Useful targets:

| Command | Purpose |
|---|---|
| `make bootstrap` | prepare `.env`, runtime dirs and dev image |
| `make build` | incremental configure/build/install |
| `make rebuild` | clean-first rebuild without deleting DB state |
| `make start` | start the Compose stack |
| `make stop` | stop the stack |
| `make restart-world` | restart only worldserver |
| `make logs` | follow all services |
| `make world-logs` | follow worldserver container stdout/stderr |
| `make shell` | development container shell |
| `make db-shell` | MySQL shell as application user |
| `make gpu-test` | run `nvidia-smi` through the GPU profile |
| `make db-import-tdb` | import pinned TDB |
| `make configure-realm` | update `auth.realmlist` from `.env` |

`make clean-build` and `make reset-db` are intentionally destructive. Use them only when a clean build or DB reset is explicitly intended.

## Standard build and test gate

Run all commands from the repository root. The normal order for a C++ change is:

```text
confirm revision → build → automated tests → restart → smoke/runtime test → error scan → disable test hooks
```

### 1. Confirm the revision

```bash
git status --short
git checkout ai-world
git pull --ff-only origin ai-world
git log -1 --oneline
```

Review any output from `git status --short`; do not discard unrelated local changes. Record the tested commit SHA so runtime evidence can be tied to the exact code.

### 2. Build and install TrinityCore

The standard incremental build is:

```bash
make build
```

This configures CMake, builds with Ninja and installs the binaries into the persistent `/build` volume. An `Up-to-date` result is a valid successful incremental build. The command must exit with status `0` and contain no compile or link failure.

Use a clean-first rebuild only when the incremental build is insufficient:

```bash
make rebuild
```

Do not use `make clean-build` routinely: it deletes the contents of the persistent build volume before rebuilding. It does not reset the database, but it makes the next build substantially longer.

### 3. Run the C++ unit tests

`make build` does not run Catch2 tests because `BUILD_TESTING` is `OFF` by default. Enable the test target explicitly, build it and run CTest:

```bash
docker compose -f compose.yml -f compose.dev.yml run --rm tc-dev bash -c \
  "cmake -S /workspace -B /build -G Ninja \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_INSTALL_PREFIX=/build \
    -DBUILD_TESTING=ON && \
   cmake --build /build --target tests && \
   ctest --test-dir /build --output-on-failure"
```

The expected final result is `100% tests passed, 0 tests failed`. `BUILD_TESTING` is cached in the persistent build directory. To return to the normal default after testing, reconfigure it to `OFF`:

```bash
docker compose -f compose.yml -f compose.dev.yml run --rm tc-dev bash -c \
  "cmake -S /workspace -B /build -G Ninja \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_INSTALL_PREFIX=/build \
    -DBUILD_TESTING=OFF"
```

### 4. Restart and verify worldserver startup

If the stack is not running yet:

```bash
make start
```

After a successful C++ build:

```bash
make restart-world
make world-logs
```

Wait until worldserver has completed startup, then leave the live log with `Ctrl-C`. Detailed AIWorld DEBUG output is written to `runtime/logs/Server.log`.

Scan the latest startup window for serious errors:

```bash
tail -n 500 runtime/logs/Server.log | grep -Ei \
"fatal|assert|segmentation|database.*failed|unknown.*config"
```

For a clean startup this command prints nothing. If it prints a match, inspect the surrounding log before accepting the build.

### 5. Run an AIWorld smoke test

Startup smoke hooks are disabled by default. When a change has a dedicated hook:

1. Set only the required `AIWorld.Test...` option to `1` in `deploy/worldserver.conf`.
2. Restart worldserver.
3. Filter the detailed log by the test's exact prefix and the common error signatures.
4. Require every case and the final summary to say `PASSED`, with no `FAILED` or error match.
5. Return the option to `0` and restart worldserver again.

Standard command shape:

```bash
make restart-world

grep -E \
"AI <test name>.*(PASSED|FAILED)|fatal|assert|segmentation|database.*failed|unknown.*config" \
runtime/logs/Server.log
```

After restoring the flag to `0`:

```bash
make restart-world

grep -E \
"AI <test name>|unknown.*config" \
runtime/logs/Server.log
```

The second check must not show a new execution of that smoke test. Never commit a local test hook enabled.

### 6. Run the feature-specific live test

Pure/unit smoke tests do not replace a live runtime proof when the change owns movement, combat, lifecycle, persistence or world-thread integration. Exercise the exact scenario required by the milestone and capture a narrow evidence window, for example:

```bash
grep -E \
"<feature marker>|sourceGoal=<GOAL>|fatal|assert|segmentation|database.*failed|unknown.*config" \
runtime/logs/Server.log | tail -n 300
```

The feature test must prove the requested successful path and its required stop/failure paths. Do not treat the absence of log lines as a pass.

### 7. Record the gate result

Use this summary in the review or roadmap entry:

```text
REVISION=<tested commit SHA>
BUILD=PASS
UNIT=PASS | NOT APPLICABLE
SMOKE=PASS | NOT APPLICABLE
RUNTIME=PASS | NOT APPLICABLE
ERROR_SCAN=PASS
TEST_FLAGS_RESTORED=YES
```

`NOT APPLICABLE` must be justified by the change scope; it does not mean that a required test was skipped.

## Python ai-server workflow

When Python decision-service code changes, rebuild that service:

```bash
docker compose -f compose.yml -f compose.dev.yml up -d --build ai-server
make restart-world
make logs
```

There is no separate `make restart-ai` workflow.

Run the ai-server's own unit tests (no real LLM required - see `docker/ai/tests/test_dynamic_task.py`) against the built image:

```bash
docker compose -f compose.yml -f compose.dev.yml run --rm ai-server \
  python -m unittest discover -s tests -p 'test_*.py' -v
```

Expect every test to report `ok` and a final `OK` summary line.

## AIWorld configuration

AIWorld settings are versioned in `deploy/worldserver.conf` and mirrored in `src/server/worldserver/worldserver.conf.dist`.

The subsystem can be disabled:

```ini
AIWorld.Enable = 0
```

Current scheduler controls include:

```ini
AIWorld.DecisionSchedulerIntervalMs = 250
AIWorld.DecisionNearbyIntervalMs = 1000
AIWorld.DecisionActiveIntervalMs = 5000
AIWorld.DecisionNearbyPlayerRange = 60.0
AIWorld.DecisionMaxInFlight = 4
AIWorld.BackgroundSimulationIntervalMs = 60000
AIWorld.AbstractSimulationIntervalMs = 300000
AIWorld.CoarseSimulationMaxPerPass = 50
```

Semantics:

```text
NEARBY     → materialized, player near, ~1 s decision cadence
ACTIVE     → materialized, no nearby player, ~5 s decision cadence
BACKGROUND → unloaded ordinary agent, coarse scheduler seam
ABSTRACT   → future aggregate/group agent, coarse scheduler seam
```

`BACKGROUND/ABSTRACT` never send `/decision`, execute actions or force-load grids in the current 2.10D scope.

## Logging

Primary categories used by the current AIWorld implementation include:

```text
ai.world
ai.agent
```

`make world-logs` follows the worldserver container console. Detailed AIWorld DEBUG records are normally written to the file appender at:

```text
runtime/logs/Server.log
```

Useful runtime checks:

```bash
grep "AI simulation tier" runtime/logs/Server.log
grep "AI simulation tick" runtime/logs/Server.log
```

The console appender may filter DEBUG messages even when the `ai.world` logger itself is configured at DEBUG level, so `Server.log` is the preferred source for detailed tier/scheduler evidence.

## Scheduler runtime evidence

2.10A–2.10D are CLOSED. Deterministic Background entry staggering and steady-state cadence were runtime verified; this is no longer a pending handoff. Historical samples and known scaling work are retained in [roadmap 2.10](AIWorld_Current_Roadmap.md#210-scheduler-a-úrovně-simulace).

## Debugging and metrics hardening

Still open:

- exact game-data extraction walkthrough;
- convenient Debug build target;
- measured no-op/incremental rebuild smoke;
- `gdb` attach/breakpoint workflow;
- core dump/crash artifact workflow;
- CUDA/PyTorch compute smoke;
- Influx/metrics backend runtime evidence;
- scaling improvements for the fast registry/materialization scan and full-sort coarse due selection.

## Persistence

Project-specific persistent state currently uses the `characters` database.

Implemented tables include:

```text
ai_agents
ai_long_term_memories
```

Persistent `AgentId` is separate from runtime `ObjectGuid`. A spawn can unload/reload or produce a new runtime Creature incarnation while the logical agent persists.

## Safety invariants for development

When changing AIWorld code, preserve these rules:

- no live TrinityCore pointer across async boundaries;
- no blocking network/DB work on the world thread;
- no force-loading grids to simulate agents;
- async responses are consumed on the world thread;
- `RuntimeGuid` provenance must protect runtime Creature incarnation changes;
- AI proposes, `ActionSystem` validates, TrinityCore executes;
- do not create duplicate execution ownership between deterministic and remote decision paths;
- prefer deterministic logic and use LLM/inference only when it adds real value.
