# AI TrinityCore — Roadmap

> **Výchozí stav:** TrinityCore `3.3.5` + Ubuntu Server + NVIDIA GPU  
> **Rozsah dokumentu:** Etapa 1 — Development Infrastructure, Etapa 2 — AI World Foundation

## Obsah

- [Základní princip](#základní-princip)
- [Přehled etap](#přehled-etap)
- [Etapa 1 — Development Infrastructure](#etapa-1--development-infrastructure)
  - [1.0 Git a výchozí stav](#10-git-a-výchozí-stav)
  - [1.1 Ubuntu host](#11-ubuntu-host)
  - [1.2 Struktura repozitáře](#12-struktura-repozitáře)
  - [1.3 TrinityCore development image](#13-trinitycore-development-image)
  - [1.4 Incremental build a cache](#14-incremental-build-a-cache)
  - [1.5 Docker Compose stack](#15-docker-compose-stack)
  - [1.6 Databáze a bootstrap](#16-databáze-a-bootstrap)
  - [1.7 WoW game data](#17-wow-game-data)
  - [1.8 Developer UX](#18-developer-ux)
  - [1.9 Debugging a observability](#19-debugging-a-observability)
  - [1.10 GPU infrastruktura](#110-gpu-infrastruktura)
  - [1.11 Prázdný AI bridge](#111-prázdný-ai-bridge)
  - [Etapa 1 — Definition of Done](#etapa-1--definition-of-done)
- [Etapa 2 — AI World Foundation](#etapa-2--ai-world-foundation)
  - [2.0 Cílová architektura](#20-cílová-architektura)
  - [2.1 Persistentní agent](#21-persistentní-agent)
  - [2.2 Persistence](#22-persistence)
  - [2.3 World Event System](#23-world-event-system)
  - [2.4 Perception System](#24-perception-system)
  - [2.5 Memory System](#25-memory-system)
  - [2.6 Needs System](#26-needs-system)
  - [2.7 Goal System](#27-goal-system)
  - [2.8 Bezpečné Action API](#28-bezpečné-action-api)
  - [2.9 AI server — decision protocol](#29-ai-server--decision-protocol)
  - [2.10 Scheduler a úrovně simulace](#210-scheduler-a-úrovně-simulace)
  - [2.11 První experiment — persistentní farmář](#211-první-experiment--persistentní-farmář)
  - [2.12 První experiment — wolf pack](#212-první-experiment--wolf-pack)
  - [2.13 První emergentní end-to-end událost](#213-první-emergentní-end-to-end-událost)
  - [2.14 Testy a diagnostika](#214-testy-a-diagnostika)
  - [Etapa 2 — Definition of Done](#etapa-2--definition-of-done)
- [Doporučené pořadí implementace](#doporučené-pořadí-implementace)

---

## Základní princip

Nejdříve vytvořit rychlé a reprodukovatelné vývojové prostředí. Teprve potom budovat persistentní AI vrstvu.

**AI navrhuje rozhodnutí. TrinityCore a simulační engine vždy rozhodují, zda je akce platná a jak se provede.**

> **Předpoklad:** počítá se s větví TrinityCore `3.3.5`. WoW client data, databázové dumpy a AI modely se neukládají do Git repozitáře.

## Přehled etap

| Etapa | Hlavní cíl | Výstup | Gate pro pokračování |
|---|---|---|---|
| **1** | Reprodukovatelný Docker development stack | TrinityCore lze rychle buildit, spustit, debugovat a přistupovat ke GPU | Fresh clone → build → login do světa |
| **2** | AI World Foundation | Persistentní agent, události, paměť, cíle, Action API a async AI bridge | Wolf attack → memory → goal → decision → action |

---

# Etapa 1 — Development Infrastructure

**Cíl:** dostat projekt do stavu, kdy je vývoj rychlý, opakovatelný a bezpečný. Změna jednoho C++ souboru nesmí znamenat znovu sestavovat celý image nebo ručně opravovat konfiguraci serveru.

## 1.0 Git a výchozí stav

- [ ] Používat TrinityCore branch `3.3.5`.
- [ ] Zaznamenat výchozí upstream commit, ze kterého projekt vznikl.
- [ ] Nastavit `origin` na náš fork a `upstream` na `TrinityCore/TrinityCore`.
- [ ] Vytvořit hlavní vývojovou branch, například `ai-world`.
- [ ] Zachovat možnost průběžně mergovat změny z upstream `3.3.5`.
- [ ] Přidat build output, runtime data, DB volumes, tajné hodnoty a AI modely do `.gitignore`.

## 1.1 Ubuntu host

Host má obsahovat jen infrastrukturu, kterou dává smysl držet mimo kontejnery.

- [ ] Nainstalovat Git.
- [ ] Nainstalovat Docker Engine.
- [ ] Nainstalovat Docker Compose plugin.
- [ ] Nainstalovat a ověřit NVIDIA driver.
- [ ] Nainstalovat NVIDIA Container Toolkit.
- [ ] Ověřit `nvidia-smi` na hostu.
- [ ] Ověřit přístup ke GPU z testovacího containeru.
- [ ] Nastavit běžný development bez nutnosti spouštět vše pod rootem.

```bash
nvidia-smi
docker compose version
docker version
```

## 1.2 Struktura repozitáře

Navrhovaná struktura:

```text
TrinityCore/
├── src/
├── sql/
├── cmake/
├── docker/
│   ├── trinitycore/
│   │   ├── Dockerfile.dev
│   │   └── Dockerfile.runtime
│   ├── ai/
│   │   └── Dockerfile
│   └── scripts/
├── deploy/
│   ├── worldserver.conf
│   ├── authserver.conf
│   └── mysql/
├── runtime/
│   ├── data/
│   │   ├── dbc/
│   │   ├── maps/
│   │   ├── vmaps/
│   │   └── mmaps/
│   └── logs/
├── compose.yml
├── compose.dev.yml
├── .env.example
├── Makefile
└── README_DEV.md
```

- [ ] Adresář `runtime/` necommitovat.
- [ ] Konfiguraci držet verzovanou jako šablony nebo development defaults.
- [ ] Tajné hodnoty držet pouze v `.env`; commitnout jen `.env.example`.

## 1.3 TrinityCore development image

- [ ] Vytvořit `Dockerfile.dev` založený na stabilní Ubuntu verzi.
- [ ] Nainstalovat compiler toolchain, CMake, Boost, OpenSSL, MySQL development knihovny, Git, debugger a `ccache`.
- [ ] Používat source tree z hostu přes bind mount do `/workspace`.
- [ ] Samotný TrinityCore source nekopírovat do development image při každém buildu.
- [ ] Připravit samostatný runtime image až jako druhý krok; development image má prioritně optimalizovat iteraci.

```text
host source              → /workspace
persistent build volume  → /build
persistent ccache volume → /ccache
```

## 1.4 Incremental build a cache

- [ ] Použít oddělený `/build` adresář v Docker named volume.
- [ ] Zapnout `ccache` a uložit cache do persistentního volume.
- [ ] Použít Ninja nebo Make tak, aby se po změně kompilovaly pouze dotčené translation units.
- [ ] Připravit build profil `Debug`.
- [ ] Připravit build profil `RelWithDebInfo` pro běžný vývoj.
- [ ] Ověřit čistý build od nuly.
- [ ] Ověřit druhý build bez změn — prakticky okamžitý.
- [ ] Ověřit build po změně jednoho `.cpp` — pouze incremental rebuild.

> **Požadovaný workflow:** editace kódu na hostu → `make build` → restart pouze `worldserver`. Clean build se spouští jen explicitně.

## 1.5 Docker Compose stack

Minimální development stack:

```text
docker compose
├── mysql
├── authserver
├── worldserver
├── tc-dev
├── ai-server   # zatím prázdná služba
└── gpu-check   # profil / diagnostika
```

- [ ] MySQL 8 s persistentním volume.
- [ ] Healthcheck databáze.
- [ ] Databáze `auth`, `characters` a `world`.
- [ ] `authserver` jako samostatná service.
- [ ] `worldserver` jako samostatná service.
- [ ] Konfigurace a logy připojit přes bind mount nebo volume.
- [ ] Services nesmí záviset na ručním pořadí spouštění.
- [ ] AI server přidat už do topologie, i když v Etapě 1 pouze odpovídá na healthcheck.

## 1.6 Databáze a bootstrap

- [ ] Automatizovat vytvoření databází a uživatelů.
- [ ] Automatizovat iniciální import potřebných TrinityCore SQL dat.
- [ ] Pinovat verzi použitého počátečního world/TDB datasetu.
- [ ] Nechat TrinityCore aplikovat standardní SQL updates.
- [ ] Ověřit bootstrap proti úplně prázdnému MySQL volume.
- [ ] Přidat `make reset-db` pro vědomý destruktivní reset development databáze.

## 1.7 WoW game data

- [ ] Připravit postup pro extrakci `dbc`, `maps`, `vmaps` a `mmaps` z vlastního 3.3.5a klienta.
- [ ] Výsledky ukládat do `runtime/data`.
- [ ] Data necommitovat a nekopírovat do běžného source image.
- [ ] `worldserver` předat cestu k datům přes volume/bind mount.
- [ ] Zdokumentovat jednorázový extraction bootstrap v `README_DEV.md`.

## 1.8 Developer UX

`Makefile` má skrýt opakující se Docker/CMake příkazy a zkrátit běžný development cyklus.

| Příkaz | Účel |
|---|---|
| `make bootstrap` | první příprava volumes, configu a adresářů |
| `make build` | incremental build TrinityCore |
| `make rebuild` | reconfigure + build bez smazání cache |
| `make start` | spuštění stacku |
| `make stop` | zastavení stacku |
| `make restart-world` | restart jen `worldserver` |
| `make logs` | společné logy |
| `make world-logs` | jen `worldserver` logy |
| `make shell` | development shell |
| `make db-shell` | MySQL shell |
| `make clean-build` | vědomý clean build |
| `make reset-db` | vědomý reset development DB |
| `make gpu-test` | test přístupu ke GPU |

## 1.9 Debugging a observability

- [ ] Build s debug symboly.
- [ ] Funkční `gdb` uvnitř development containeru.
- [ ] Možnost pustit `worldserver` interaktivně.
- [ ] Možnost attachnout debugger na běžící `worldserver`.
- [ ] Povolit core dumps pro development.
- [ ] Persistovat crash logy.
- [ ] Připravit logging kategorie:
  - `ai.world`
  - `ai.agent`
  - `ai.player`
  - `ai.simulation`
  - `ai.inference`
- [ ] Ověřit testovací breakpoint a čitelný stack trace.

## 1.10 GPU infrastruktura

- [ ] Přidat `gpu-check` Compose profil.
- [ ] Ověřit `nvidia-smi` uvnitř containeru.
- [ ] Ověřit dostupnost CUDA runtime v budoucí AI službě.
- [ ] Ověřit viditelnou VRAM a jméno GPU.
- [ ] Spustit jednoduchý GPU workload.
- [ ] Nedávat GPU inference přímo do procesu `worldserver`.

```text
worldserver  <---- async network / IPC ---->  ai-server  ---->  GPU
```

## 1.11 Prázdný AI bridge

- [ ] AI služba běží jako samostatný container.
- [ ] Přidat health endpoint.
- [ ] `worldserver` umí neblokujícím způsobem zjistit, zda je AI service dostupná.
- [ ] Nastavit timeouty a reconnect strategii.
- [ ] Výpadek AI služby nesmí shodit ani zablokovat `worldserver`.
- [ ] Zalogovat latency a stav spojení.

> **Gate:** dokud toto není stabilní, neimplementovat gameplay AI. Infrastruktura musí být nudná, předvídatelná a rychlá.

## Etapa 1 — Definition of Done

- [ ] Fresh clone projektu lze připravit podle `README_DEV.md` bez ruční instalace TrinityCore dependencies na hostu.
- [ ] Docker sestaví TrinityCore.
- [ ] Incremental C++ build funguje a používá persistentní cache.
- [ ] MySQL se inicializuje automaticky.
- [ ] `authserver` a `worldserver` se spustí přes Compose.
- [ ] WoW 3.3.5a klient se připojí, vytvoří postavu a vstoupí do světa.
- [ ] Restart `worldserver` nesmaže postavy ani DB stav.
- [ ] Debugger a stack traces jsou použitelné.
- [ ] GPU je dostupné uvnitř Dockeru.
- [ ] Prázdný `ai-server` je dostupný po interní Docker síti.
- [ ] Výpadek `ai-server` nemá vliv na stabilitu běžné hry.

---

# Etapa 2 — AI World Foundation

**Cíl:** vytvořit persistentní vrstvu nad TrinityCore, ve které mohou NPC a další entity existovat jako dlouhodobí agenti se stavem, pamětí, cíli a omezenou sadou akcí.

GPU/AI služba se používá pro rozhodování tam, kde dává smysl. Fyziku a pravidla světa stále vynucuje TrinityCore.

## 2.0 Cílová architektura

```text
TrinityCore
│
├── Player / Creature / GameObject
│
└── AIWorldMgr
    ├── AgentRegistry
    ├── PerceptionSystem
    ├── MemorySystem
    ├── NeedsSystem
    ├── GoalSystem
    ├── ActionSystem
    ├── EventSystem
    ├── Scheduler
    └── AIClient  -------------------->  ai-server  ---> GPU
```

- [ ] Vytvořit nový subsystem `src/server/game/AIWorld/`.
- [ ] `AIWorld` se inicializuje při startu `worldserver` a korektně se ukončí při shutdownu.
- [ ] Normální TrinityCore gameplay musí fungovat i při vypnutém `AIWorld`.

## 2.1 Persistentní agent

Oddělit dočasný TrinityCore objekt od dlouhodobé identity agenta. `Creature` může zmizet z aktivní mapy, ale agent stále existuje v simulaci.

```text
AIAgent
├── AgentId
├── WorldBinding (Creature / Player / Abstract)
├── Identity
├── Personality
├── Needs
├── Goals
├── Memory
├── Relationships
├── Economy
└── RuntimeState
```

- [ ] Zavést stabilní `AgentId`.
- [ ] Vytvořit `AgentRegistry`.
- [ ] Umět propojit `AgentId` s aktuálním `Creature/ObjectGuid`.
- [ ] Umět agenta odpojit od `Creature` a ponechat jej jako abstraktní stav.
- [ ] Umět agenta znovu materializovat do světa.
- [ ] Připravit typy agentů minimálně:
  - `CIVILIAN`
  - `GUARD`
  - `MERCHANT`
  - `CREATURE_GROUP`

## 2.2 Persistence

AI stav musí přežít restart `worldserver`.

Navrhované tabulky:

```text
ai_agents
ai_agent_memory
ai_agent_relationships
ai_agent_goals
ai_events
ai_locations
```

- [ ] Navrhnout DB schema s verzováním/migracemi.
- [ ] Persistovat identitu, základní stav a vazbu na svět.
- [ ] Persistovat dlouhodobou paměť.
- [ ] Persistovat vztahy mezi agenty a hráči.
- [ ] Persistovat aktivní cíle.
- [ ] Persistovat důležité world events pro audit a replay/debug.
- [ ] Ověřit save → restart → load jednoho agenta.

## 2.3 World Event System

Události jsou základ kauzality. AI nemá dostávat náhodný příběh; má reagovat na skutečné změny stavu světa.

První typy událostí:

```text
CreatureKilled
NPCInjured
PlayerSeen
ItemStolen
TradeCompleted
LivestockKilled
WolfPackMoved
FoodShortage
NPCDied
```

- [ ] Definovat `WorldEvent` s typem, časem, lokací, aktorem, cílem a payloadem.
- [ ] Vytvořit `EventBus` uvnitř `AIWorld`.
- [ ] Napojit první TrinityCore hooky na vznik událostí.
- [ ] Oddělit transient event od persistentní historické události.
- [ ] Přidat `correlation/cause id`, aby šlo sledovat řetězec příčina → následek.
- [ ] Přidat debug log událostí.

## 2.4 Perception System

- [ ] Agent nesmí automaticky vědět globální stav světa.
- [ ] Přidat nearby entity perception.
- [ ] Přidat základní range check.
- [ ] Tam, kde je vhodné, respektovat line-of-sight.
- [ ] Přidat perception událostí, kterých byl agent svědkem.
- [ ] Přidat přípravu pro informace z rozhovorů/rumorů v pozdější etapě.
- [ ] Z perception vytvářet `Observation` objekty použitelné pro memory a decision context.

## 2.5 Memory System

```text
ShortTermMemory
LongTermMemory
Knowledge
Relationships
```

- [ ] Implementovat krátkodobou paměť s expirací.
- [ ] Implementovat dlouhodobou paměť pro důležité události.
- [ ] Přidat importance score.
- [ ] Přidat čas a zdroj informace.
- [ ] Přidat vazbu na osoby, lokaci a událost.
- [ ] Připravit retrieval relevantních vzpomínek podle aktuální situace.
- [ ] LLM nikdy neposílat celou historii; posílat pouze vybrané relevantní záznamy.

## 2.6 Needs System

- [ ] Zavést minimální potřeby:
  - `health`
  - `hunger`
  - `fatigue`
  - `safety`
  - `money/resource pressure`
- [ ] Potřeby aktualizovat deterministicky v simulation ticku.
- [ ] Potřeby omezit do definovaného rozsahu, například `0.0–1.0`.
- [ ] Přidat threshold events, například `HUNGER_CRITICAL` nebo `DANGER_HIGH`.
- [ ] Nechat potřeby generovat kandidáty na cíle bez LLM.

## 2.7 Goal System

První katalog cílů:

```text
SURVIVE
GET_FOOD
MAKE_MONEY
PROTECT_HOME
HELP_FAMILY
FLEE_DANGER
WORK
REST
INVESTIGATE
REQUEST_HELP
```

- [ ] Definovat `Goal` objekt s prioritou/utility, zdrojem, timeoutem a success condition.
- [ ] Implementovat základní Utility AI pro volbu mezi jednoduchými cíli.
- [ ] Oddělit volbu cíle od konkrétní akce.
- [ ] Přidat možnost cíl přerušit při nouzové situaci.
- [ ] Přidat success/failure stav.
- [ ] LLM/GPU použít až pro komplexnější plánování nebo výběr mezi nestrukturovanými variantami.

## 2.8 Bezpečné Action API

AI nemá přístup k libovolnému C++ ani k přímým zápisům do světa. Smí pouze požádat o akci z povoleného katalogu.

```text
MOVE_TO
FOLLOW
ATTACK
FLEE
TALK
TRADE
EAT
SLEEP
WORK
INVESTIGATE
REQUEST_HELP
```

- [ ] Definovat `ActionRequest` a `ActionResult`.
- [ ] Pro každou akci implementovat serverovou validaci.
- [ ] Ověřit existenci cíle, stav agenta, pathing/range/LoS podle typu akce.
- [ ] Nevalidní AI odpověď nikdy nesmí rozbít stav serveru.
- [ ] Přidat timeout a cancel pro dlouhé akce.
- [ ] Přidat fallback behavior při chybě AI služby.

> **Pravidlo:** AI navrhuje. `ActionSystem` validuje. TrinityCore provádí.

## 2.9 AI server — decision protocol

```text
AgentContext
    │
    ▼
DecisionRequest
    │
    ▼
ai-server / GPU
    │
    ▼
Decision
    │
    ▼
Action validation
```

- [ ] Definovat verzovaný request/response kontrakt.
- [ ] Posílat jen informace, které agent smí znát.
- [ ] Posílat dostupné akce explicitně.
- [ ] Rozhodování volat asynchronně.
- [ ] `worldserver` nesmí čekat na inference.
- [ ] Přidat `request_id`, `agent_id`, deadline a model/version metadata.
- [ ] Měřit latency, queue time, timeout rate a invalid decision rate.
- [ ] Připravit API pro batching více agentů.

## 2.10 Scheduler a úrovně simulace

| Stav agenta | Orientační cadence | Účel |
|---|---:|---|
| Combat / reflex | 50–200 ms | rychlá pravidla na CPU; minimální nebo žádné LLM |
| Vedle hráče | 250–1000 ms | reakce a krátkodobé taktické volby |
| Aktivní NPC | 2–5 s | cíle, plánování, běžný život |
| Background agent | 30–120 s | agregované změny stavu |
| Abstraktní skupina | minuty | populace, zdroje, teritorium |

- [ ] Implementovat scheduler tak, aby AI neměla jeden globální tick pro všechny entity.
- [ ] Prioritizovat agenty poblíž reálného hráče.
- [ ] Drahou inference nikdy nepouštět v combat hot path.
- [ ] Připravit backpressure při přetížení AI queue.
- [ ] Umět přesunout agenta mezi `ACTIVE`, `NEARBY`, `BACKGROUND` a `ABSTRACT` stavem.

## 2.11 První experiment — persistentní farmář

Vybrat jedno NPC v malé testovací oblasti a dát mu jednoduchý, pozorovatelný denní cyklus.

- [ ] Agent má home lokaci.
- [ ] Agent má working lokaci.
- [ ] Agent má money/food/resource stav.
- [ ] Agent má potřeby a základní cíle.
- [ ] Ráno jde pracovat.
- [ ] Při nebezpečí uteče nebo požádá o pomoc.
- [ ] Večer se vrátí domů a odpočívá.
- [ ] Pamatuje si jednu důležitou událost i po restartu serveru.

## 2.12 První experiment — wolf pack

```text
WolfPack #1
├── population
├── territory
├── hunger
├── fear
├── home
└── current_goal
```

- [ ] Modelovat smečku jako skupinového agenta mimo bezprostřední combat.
- [ ] Hlad postupně roste.
- [ ] Smečka vyhledává potravu podle dostupných zdrojů.
- [ ] Při nedostatku potravy zvyšuje toleranci rizika.
- [ ] Smečka se může přiblížit k farmě.
- [ ] Při materializaci použít normální TrinityCore `Creature` / combat logiku.
- [ ] Po ztrátě členů aktualizovat `population` state.

## 2.13 První emergentní end-to-end událost

Etapa 2 má skončit prvním skutečným kauzálním řetězcem, který nebyl napsán jako klasický quest.

```text
WolfPack hunger rises
        │
        ▼
wolves move toward farm
        │
        ▼
livestock is attacked
        │
        ▼
WorldEvent: LIVESTOCK_KILLED
        │
        ▼
Farmer perceives event
        │
        ▼
Memory is created
        │
        ▼
Goal: PROTECT_HOME
        │
        ▼
Decision: REQUEST_HELP
        │
        ▼
validated TrinityCore action
```

## 2.14 Testy a diagnostika

- [ ] Unit testy pro utility výběr cílů.
- [ ] Unit testy validace `ActionRequest`.
- [ ] Unit testy serializace/persistence agenta.
- [ ] Integration test AI request → mock response → action result.
- [ ] Integration test restart → reload memory.
- [ ] Structured log pro každé AI decision.
- [ ] Možnost vypsat debug snapshot jednoho agenta podle `AgentId`.
- [ ] Metrics:
  - agent count podle tieru,
  - event rate,
  - inference queue,
  - timeouts,
  - invalid actions.

## Etapa 2 — Definition of Done

- [ ] `AIWorldMgr` se stabilně inicializuje a ukončuje s `worldserver`.
- [ ] Existuje persistentní `AgentId` a `AgentRegistry`.
- [ ] Minimálně jeden NPC agent přežije restart se zachovanou pamětí a stavem.
- [ ] `WorldEvent` system zachytí vybranou událost z TrinityCore.
- [ ] Perception určí, který agent událost viděl.
- [ ] `MemorySystem` z události vytvoří relevantní vzpomínku.
- [ ] Needs/Goal system vytvoří nebo upraví cíl.
- [ ] AI server obdrží `AgentContext` asynchronně a vrátí rozhodnutí.
- [ ] `ActionSystem` rozhodnutí validuje a provede pouze povolenou akci.
- [ ] Výpadek AI serveru nezablokuje `worldserver`.
- [ ] Scheduler umí různé update cadence a abstraktní agent state.
- [ ] Wolf pack → livestock attack → farmer memory → protect goal → request help funguje end-to-end.

> **Gate:** po Etapě 2 máme skutečnou smyčku  
> `WORLD STATE → EVENT → PERCEPTION → MEMORY → GOAL → DECISION → ACTION → WORLD STATE`.

---

# Doporučené pořadí implementace

1. [ ] Docker host + GPU runtime
2. [ ] Development image + persistentní build / `ccache`
3. [ ] Compose: MySQL + `authserver` + `worldserver`
4. [ ] DB bootstrap + game data
5. [ ] Developer `Makefile` + debugging
6. [ ] Prázdný `ai-server` + async health bridge
7. [ ] `AIWorldMgr` + `AgentRegistry`
8. [ ] Persistence
9. [ ] World Events
10. [ ] Perception + Memory
11. [ ] Needs + Goals
12. [ ] Action API
13. [ ] AI decision protocol + scheduler
14. [ ] Persistentní farmář
15. [ ] Wolf pack
16. [ ] End-to-end emergentní událost

## Co bude následovat

**Etapa 3:** jedna živá oblast (například Elwynn Forest) s populacemi, zdroji, ekonomikou, vztahy, frakcemi a dynamickými problémy/questy.
