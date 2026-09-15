# Deploy runner

Self-hosted GitHub Actions runner that executes the `deploy` job in
[.github/workflows/ci.yml](../../.github/workflows/ci.yml). It only ever
runs on `push` to `ai-world` after `build-and-test` passes on a GitHub-hosted
runner — pull requests (including from forks, since this repo is public)
never reach it. See `compose.yml` in this directory for why.

## One-time host bootstrap

Do this once on the dedicated Linux deploy server, before the runner
container is started for the first time.

1. Clone the persistent deploy checkout at the exact path the runner
   container expects (`compose.yml` bind-mounts it 1:1, host path == container
   path, so it can't move without editing that file too):

   ```
   sudo git clone https://github.com/LoubekJan/WoWBehaviorAI.git /deploy/WoWBehaviorAI
   ```

   This checkout is what the `deploy` job builds and restarts — it is kept in
   sync with `git fetch` + `git reset --hard origin/ai-world` on every deploy,
   never with `actions/checkout` (which would wipe the untracked `.env` and
   `runtime/` state below on every run).

2. Inside `/deploy/WoWBehaviorAI`, set up the app stack's own secrets and
   persistent data, same as any other deployment of this repo's
   [compose.yml](../../compose.yml):

   ```
   cd /deploy/WoWBehaviorAI
   cp .env.example .env
   # edit .env: MYSQL_ROOT_PASSWORD, TC_DB_USER/PASSWORD, ports, etc.
   mkdir -p runtime/logs runtime/data
   ```

3. Create a fine-grained GitHub PAT for this repo (Administration: read &
   write) and set up the runner's own env file:

   ```
   cd /deploy/WoWBehaviorAI/deploy/runner
   cp .env.example .env
   # edit .env: GH_RUNNER_REPO_URL, GH_RUNNER_PAT
   ```

4. Build and start the runner (run from this directory, not with `-f` from
   elsewhere, so Compose picks up the `.env` here for `GH_RUNNER_*`
   substitution):

   ```
   cd /deploy/WoWBehaviorAI/deploy/runner
   docker compose up -d --build
   ```

   Confirm it registered: GitHub → repo → Settings → Actions → Runners
   should show `wow-deploy-runner` as idle, with labels
   `self-hosted, linux, docker, wow`.

From this point on, every push to `ai-world` that passes CI will
`docker compose build && docker compose up -d` the app stack in
`/deploy/WoWBehaviorAI` automatically.

## Updating the runner itself

```
cd /deploy/WoWBehaviorAI/deploy/runner
git pull
docker compose up -d --build
```
