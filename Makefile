.PHONY: bootstrap build rebuild start stop restart-world logs world-logs shell db-shell clean-build reset-db gpu-test

COMPOSE := docker compose -f compose.yml -f compose.dev.yml
BUILD_DIR := /build
BUILD_TYPE := RelWithDebInfo

## first-time setup: .env, runtime dirs, build the dev image
bootstrap:
	@test -f .env || cp .env.example .env
	@mkdir -p runtime/data/dbc runtime/data/maps runtime/data/vmaps runtime/data/mmaps runtime/logs
	$(COMPOSE) build

## incremental TrinityCore build inside tc-dev
build:
	$(COMPOSE) exec tc-dev bash -c "cmake -S /workspace -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DCMAKE_INSTALL_PREFIX=$(BUILD_DIR) && cmake --build $(BUILD_DIR)"

## reconfigure + build without wiping the build/ccache volumes
rebuild:
	$(COMPOSE) exec tc-dev bash -c "cmake -S /workspace -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DCMAKE_INSTALL_PREFIX=$(BUILD_DIR) && cmake --build $(BUILD_DIR) --clean-first"

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

shell:
	$(COMPOSE) exec tc-dev bash

db-shell:
	$(COMPOSE) exec mysql mysql -utrinity -ptrinity

## deliberate, explicit clean build — wipes the persistent build volume
clean-build:
	$(COMPOSE) exec tc-dev rm -rf $(BUILD_DIR)
	$(MAKE) build

## deliberate, explicit destructive reset of the development database
reset-db:
	$(COMPOSE) down mysql -v
	$(COMPOSE) up -d mysql

gpu-test:
	$(COMPOSE) --profile gpu-check run --rm gpu-check
