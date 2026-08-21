.PHONY: bootstrap build rebuild start stop restart-world logs world-logs shell db-shell clean-build reset-db gpu-test

COMPOSE := docker compose -f compose.yml -f compose.dev.yml
BUILD_DIR := /build
BUILD_TYPE := RelWithDebInfo
CMAKE_CONFIGURE := cmake -S /workspace -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DCMAKE_INSTALL_PREFIX=$(BUILD_DIR)

# Workflow order matters: bootstrap -> build -> start. authserver/worldserver
# expect /build/bin (the build-data volume) to already contain binaries, so
# build runs in a throwaway tc-dev container and does not require `start`
# (or tc-dev) to already be running.

## first-time setup: .env, runtime dirs, build the dev image
bootstrap:
	@test -f .env || cp .env.example .env
	@mkdir -p runtime/data/dbc runtime/data/maps runtime/data/vmaps runtime/data/mmaps runtime/logs
	$(COMPOSE) build

## incremental TrinityCore build — runs in a throwaway tc-dev container
build:
	$(COMPOSE) run --rm tc-dev bash -c "$(CMAKE_CONFIGURE) && cmake --build $(BUILD_DIR)"

## reconfigure + build without wiping the build/ccache volumes
rebuild:
	$(COMPOSE) run --rm tc-dev bash -c "$(CMAKE_CONFIGURE) && cmake --build $(BUILD_DIR) --clean-first"

## start mysql, authserver, worldserver, ai-server (requires `make build` first)
start:
	$(COMPOSE) up -d

stop:
	$(COMPOSE) down

restart-world:
	$(COMPOSE) restart worldserver

logs:
	$(COMPOSE) logs -f

world-logs:
	$(COMPOSE) logs -f worldserver

## interactive dev shell — throwaway container, independent of `start`
shell:
	$(COMPOSE) run --rm tc-dev bash

db-shell:
	$(COMPOSE) exec mysql sh -c 'mysql -u"$$TC_DB_USER" -p"$$TC_DB_PASSWORD"'

## deliberate, explicit clean build — wipes the persistent build volume
clean-build:
	$(COMPOSE) run --rm tc-dev rm -rf $(BUILD_DIR)
	$(MAKE) build

## deliberate, explicit destructive reset of the development database
reset-db:
	$(COMPOSE) stop mysql
	$(COMPOSE) rm -f mysql
	docker volume rm aitc_mysql-data
	$(COMPOSE) up -d mysql

gpu-test:
	$(COMPOSE) --profile gpu-check run --rm gpu-check
