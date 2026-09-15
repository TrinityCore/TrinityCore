# AIWorld — Roadmap

| Kontext | Hodnota |
|---|---|
| Výchozí stav | TrinityCore `3.3.5` + Ubuntu Server + NVIDIA GPU |
| Rozsah | Etapy 1–3 + výhled Etapy 4 |
| Aktivní větev | `ai-world` |
| Stav po uzavření Etapy 2 | [`a0bd5a8834`](https://github.com/LoubekJan/WoWBehaviorAI/commit/a0bd5a8834929da95d27388f47cd9c7b71ee3253) |

Tento dokument je jediná projektová roadmapa: obsahuje aktuální stav, implementační historii, ověřovací důkazy a navazující plán. Další změny milníků se zapisují přímo sem. Starší datované statusy jsou historické snapshoty.

## Stav projektu

**Etapa 1 má splněný runtime gate. Etapa 2 je CLOSED / POC COMPLETE včetně 2.13 a finálního integračního gate 2.14. Další plánovaná práce je Etapa 3 — příprava Elwynn Forest, počínaje scope a census (3.0–3.1).**

| Etapa | Stav | Hlavní cíl | Gate pro pokračování |
|---|---|---|---|
| **1 — Development Infrastructure** | ✅ **GATE SPLNĚN** | Reprodukovatelný Docker development stack | build, DB/TDB, klient a restart/persistence |
| **2 — AI World Foundation** | ✅ **CLOSED / POC COMPLETE** | Ověřené AI subsystémy, coalition model a LLM/player vertical slices | runtime důkazy 2.12–2.13 + agregátní POC 2.14 |
| **3 — Elwynn Forest World Preparation** | ⚪ **PLANNED** | Census, sémantické lokace, frakce a opravená world data | úplné pokrytí, faction invarianty a reprodukovatelný runtime baseline |
| **4 — Living World** | ⚪ **PLANNED** | Populace, zdroje, ekonomika, vztahy, konflikty a AI questy | dlouhodobě běžící oblast s kauzálními problémy a změnami |

`2.12F4C`/`2.12F4D` zůstávají odložené do rozšíření mimo jednu lokaci; `2.12G4` se otevírá pouze při prokázané potřebě leadership/roles. Tyto položky a průběžný hardening neruší uzavření Etapy 2 jako POC.

Podrobné výsledky jednotlivých gate jsou uvedené u příslušných milníků. Historické logy a revize zachycují konkrétní ověřovací běh; například původní malá `AgentId` předcházejí migraci na `AgentId == SpawnId` v 2.12F4A2. Rozsah důkazu zůstává rozlišený na STATIC, BUILD, UNIT/SMOKE a RUNTIME.

## Obsah

- [Stav projektu](#stav-projektu)
- [Základní invariant](#základní-invariant)
- [Etapa 1 — Development Infrastructure](#etapa-1--development-infrastructure)
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
  - [2.12 — AgentGroup / coalition](#212--agentgroup--coalition)
  - [2.13 — local LLM dynamic task / player interaction vertical slice](#213--local-llm-dynamic-task--player-interaction-vertical-slice)
  - [2.14 — final Etapa 2 POC / aggregate integration gate](#214--final-etapa-2-poc--aggregate-integration-gate)
  - [2.15 — testy, diagnostika a scale hardening](#215--testy-diagnostika-a-scale-hardening)
  - [Etapa 2 — Definition of Done](#etapa-2--definition-of-done)
- [Etapa 3 — Elwynn Forest World Preparation](#etapa-3--elwynn-forest-world-preparation)
  - [3.0 Scope a source of truth](#30-scope-a-source-of-truth)
  - [3.1 Kompletní census NPC a creature spawnů](#31-kompletní-census-npc-a-creature-spawnů)
  - [3.2 Sémantická mapa lokací](#32-sémantická-mapa-lokací)
  - [3.3 Faction audit a oprava](#33-faction-audit-a-oprava)
  - [3.4 Coalition pravidla uvnitř frakcí](#34-coalition-pravidla-uvnitř-frakcí)
  - [3.5 Faction presence a pohyb po mapě](#35-faction-presence-a-pohyb-po-mapě)
  - [3.6 World DB cleanup a verifikace](#36-world-db-cleanup-a-verifikace)
  - [Etapa 3 — Definition of Done](#etapa-3--definition-of-done)
- [Etapa 4 — Living World](#etapa-4--living-world)
- [Další postup a otevřený hardening](#další-postup-a-otevřený-hardening)
  - [Nejbližší acceptance gate — 3.0–3.1](#nejbližší-acceptance-gate--3031)
- [Development / verification workflow](#development--verification-workflow)

## Základní invariant

**AI přemýšlí a navrhuje záměr. ActionSystem validuje a TrinityCore rozhoduje, co je fyzicky a pravidlově možné, a provádí změnu světa.**

```text
WORLD STATE
    ↓
EVENT
    ↓
PERCEPTION
    ↓
MEMORY
    ↓
NEED
    ↓
GOAL
    ↓
DECISION / PLANNING
    ↓
ACTION REQUEST
    ↓
ACTION SYSTEM VALIDATION
    ↓
TRINITYCORE EXECUTION
    ↓
WORLD STATE
```

Platí pro všechny další milníky:

- AI pouze navrhuje; `ActionSystem` je validační autorita a TrinityCore provádí fyzickou změnu světa.
- Žádný live `Creature*`, `Player*`, `Map*` ani `Unit*` nesmí uniknout přes async hranici nebo být uložen pro pozdější použití.
- Async inference/network dostává pouze pure/value DTO a výsledky se aplikují zpět na world threadu.
- AIWorld nikdy force-loaduje grid kvůli simulaci nebo testu.
- World binding a simulation policy jsou dvě oddělené osy.
- Materialized individual agent odpovídá reálnému TrinityCore `Creature`; unloaded agent zůstává persistentní `AgentRecord`.
- Každý individual `AgentRecord` musí odpovídat skutečnému TrinityCore creature spawnu; testy nevyrábějí ghost physical agenty.
- `RuntimeGuid` je provenance pouze aktuální materialized incarnation a nesmí být zaměněn za persistentní identity.
- `GroupId` je samostatná persistentní identity doména; dissolved GroupId se nerecykluje tak, aby stará reference mohla aliasovat novou coalition.
- `AgentGroup` je sociální/koordinační entita, nikdy 1:1 physical entity a nikdy přímo nepohybuje Creatures.
- Group intent se vždy rozkládá na návrhy pro jednotlivé `AgentId`; individual Agent vlastní fyzickou akci.
- Vyšší-prioritní individual goal/action může group coordination preemptovat.
- LLM se používá pouze tam, kde deterministic logika nestačí, a nikdy není execution authority.

---

## Etapa 1 — Development Infrastructure

**Stav: runtime gate SPLNĚN.**

Hotovo:

- Docker development image na Ubuntu 22.04, Ninja, `ccache`, `RelWithDebInfo`.
- persistentní `/build` + `/ccache`.
- Compose služby MySQL, authserver, worldserver, ai-server a GPU check.
- automatizovaný import TDB `TDB335.25101` a TrinityCore DB updater.
- versionovaný `auth.realmlist` bootstrap přes `make configure-realm`.
- runtime mount `dbc/maps/vmaps/mmaps`.
- LAN client login runtime PASS.
- NVIDIA Container Toolkit / `nvidia-smi` runtime PASS; Docker vidí dvě RTX 3090.
- restart `worldserver` přes `make restart-world` zachová DB/herní stav.
- `make build`, `make restart-world`, `make world-logs` a další základní dev workflow.

Neblokující hardening:

- [ ] přesný extraction návod `dbc/maps/vmaps/mmaps`;
- [ ] samostatný Debug target;
- [ ] měřený no-op/incremental rebuild smoke;
- [ ] `gdb` attach/breakpoint + core dump workflow;
- [ ] CUDA/PyTorch compute smoke v inference image;
- [ ] metrics backend/dashboard runtime evidence.

---

## Etapa 2 — AI World Foundation

**Stav: CLOSED — POC COMPLETE.** Foundation a vertical slices níže mají splněné popsané gate. Nezaškrtnuté rozšiřující/hardening položky v dílčích sekcích nejsou novým požadavkem na již uzavřený POC.

### Přehled milníků Etapy 2

| Oblast | Stav |
|---|---|
| 2.1–2.9 — identity, persistence, event/perception/memory/needs/goals/actions/decision protocol | **CLOSED / runtime foundation PASS** |
| 2.10 — scheduler + simulation tiers | **CLOSED** |
| 2.11 — persistent farmer vertical slice | **CLOSED** |
| 2.12A–D — AgentGroup architecture pivot + separate GroupId domain | **CLOSED** |
| 2.12E1 — Create/Join/Leave/Dissolve | **CLOSED / runtime PASS** |
| 2.12E2 — async-safe lifecycle persistence boundary | **CLOSED** |
| 2.12E3 — Loose/Stable policy | **CLOSED** |
| 2.12E4 — generic profile-driven formation + maintenance | **CLOSED** |
| 2.12F1 — generic group intent (`REGROUP`) | **CLOSED** |
| 2.12F2 — intent → per-member proposal → ActionSystem | **CLOSED** |
| 2.12F3 — integration/lifecycle runtime proof | **CLOSED / STATIC + BUILD + RUNTIME PASS** |
| 2.12F4A–F4B3 — ControlMode gate, TrinityCore-aligned identity, spawn reconciliation, scoped Elwynn population + full Control activation | **CLOSED / STATIC + BUILD + RUNTIME PASS (Elwynn: 3540/3540 `AIWorldControlled`)** |
| 2.12F4C/F4D — world-scale hardening (O(1) index, bounded recurring work) + full-world bootstrap | **DEFERRED — not required for single-location work; required before any eventual full-world rollout, see 2.12F4C's own Priorita** |
| 2.12G1 — druhý coalition profile (genericity proof) | **CLOSED / STATIC + BUILD + RUNTIME PASS** |
| 2.12G2 — generic ROAM/territory movement intent | **CLOSED / STATIC + BUILD + RUNTIME PASS** |
| 2.12G3 — generic HUNT/coordinated combat contract | **CLOSED — combat runtime PASS; lifecycle STATIC + kumulativní BUILD** ([rozsah důkazu](#212g3-lifecycle-closure)) |
| 2.12G4 — roles/leadership | **NOT NEEDED YET — viz 2.12G4's own Priorita** |
| 2.13 — local LLM dynamic task vertical slice | **CLOSED — STATIC + BUILD + UNIT 253/253 + RUNTIME PASS**, včetně restart/reconnect a negative failure-mode gate |
| 2.14 — final Etapa 2 POC / aggregate integration gate | **CLOSED — RUNTIME POC PASS. Etapa 2 CLOSED / POC COMPLETE.** |
| 2.15 — testy, diagnostika a scale hardening | **PRŮBĚŽNĚ — neblokuje uzavřený POC** |

### 2.0 Cílová architektura

```text
TrinityCore
│
├── Player / Creature / GameObject
│
└── AIWorldMgr
    ├── AgentRegistry
    ├── AgentGroupRegistry
    ├── AgentGroupLifecycleSystem
    ├── PerceptionSystem
    ├── MemorySystem
    ├── NeedsSystem
    ├── GoalSystem
    ├── ActionSystem
    ├── EventSystem
    ├── DecisionScheduler
    ├── CoarseSimulationScheduler
    ├── GroupCoarseSimulationScheduler
    └── AIClient  -------------------->  ai-server  ---> GPU
```

- [x] subsystem `src/server/game/AIWorld/`;
- [x] lifecycle integrace do `worldserver`;
- [x] AIWorld lze vypnout;
- [x] network/inference async vůči world update loopu;
- [x] response freshness/provenance validation;
- [x] group identity oddělená od physical Agent identity;
- [x] group coarse simulation má vlastní GroupId-keyed scheduler.

### 2.1 Persistentní agent

**Stav: core registry/binding DONE / runtime PASS**

- [x] stabilní `AgentId`;
- [x] `AgentRegistry`;
- [x] `AgentId ↔ Creature/ObjectGuid` binding;
- [x] unload → agent zůstává persistentní bez live `Creature`;
- [x] rematerializace bez ztráty identity/state;
- [x] `RuntimeGuid` provenance platí pouze pro aktuální materialized incarnation;
- [x] group/coalition už není `AgentType` a nevytváří fake physical agent.

`SpawnId` je persistentní spawn identity individuálního creature agenta. Od 2.12F4A2 pro persistentní non-instance/base-world Creature agenty platí také `AgentId.Value == SpawnId`; původní generovaná ID byla migrována. `RuntimeGuid` je platný pouze pro aktuální materialized runtime object. `GroupId` je samostatná sociální identity doména a nesmí být odvozována z `AgentId`, `SpawnId` ani `RuntimeGuid`.

### 2.2 Persistence

Aktuálně `characters` DB zahrnuje mimo jiné:

```text
ai_agents
ai_long_term_memories
ai_agent_groups
ai_agent_group_members
ai_agent_group_id_sequence
```

- [x] individual agent identity persistence;
- [x] long-term memory persistence + restart/load;
- [x] persistent Home/Work location;
- [x] persistent economy state + monotonic economy version;
- [x] oddělená group identity/state persistence;
- [x] persistent AgentId membership edges;
- [x] persistent monotonic GroupId high-water sequence;
- [ ] obecné relationships mimo group membership;
- [ ] active goals persistence;
- [ ] historical events/audit persistence.

### 2.3 World Event System

**Stav: první producer + EventBus DONE / runtime PASS**

- [x] `WorldEvent` s typem/časem/lokací/actor/target/payload;
- [x] interní `EventBus`;
- [x] TrinityCore producer hook;
- [x] correlation/cause id;
- [x] debug logging;
- [ ] oddělená persistentní historical event vrstva.

### 2.4 Perception System

**Stav: core sight perception DONE / runtime PASS**

- [x] nearby entity perception;
- [x] range + relevantní LoS checks;
- [x] witnessed event perception;
- [x] `Observation` DTO;
- [ ] skutečná obecná rumor/hearing propagation; directed/Rumor fallback pro quest outcome již existuje v 2.13C6C, ale není obecnou propagací zvěstí.

### 2.5 Memory System

**Stav: core memory pipeline DONE / runtime PASS**

```text
Observation
    ↓
ShortTermMemory (dedupe + TTL)
    ↓ importance threshold
LongTermMemory
    ↓ async persistence
restart/load
    ↓
deterministic relevance retrieval
    ↓
Top-N DecisionMemory
```

- [x] short-term dedupe/TTL/expiry;
- [x] deterministic importance;
- [x] persistent long-term memory;
- [x] restart/load;
- [x] relevance retrieval + semantic dedupe + deterministic Top-N;
- [x] wire-safe memory DTO před async inference hranicí.

### 2.6 Needs System

**Stav: 2.6A–2.6C DONE / runtime PASS**

`NeedsState`:

- `HealthPressure`
- `Hunger`
- `Fatigue`
- `SafetyPressure`
- `ResourcePressure`

- [x] deterministic drift;
- [x] clamp `0.0–1.0`;
- [x] live HP/combat coupling;
- [x] recent-memory-driven safety decay;
- [x] edge-triggered `HUNGER_CRITICAL`/`DANGER_HIGH` s hysteresis;
- [x] Needs → deterministic Goal candidates bez LLM.

### 2.7 Goal System

**Stav: core goals + farmer routine vertical slice DONE / runtime PASS**

Runtime implementované goal/routine koncepty:

- `GET_FOOD`
- `FLEE_DANGER`
- `GO_TO_WORK`
- `GO_HOME`

- [x] deterministic candidate generation;
- [x] utility/priority selection;
- [x] retention;
- [x] emergency interruption;
- [x] success/failure/timeout;
- [x] dead agent bez candidate/ActiveGoal;
- [x] routine goal je pod ActiveGoal a emergency goal jej preemptuje.

Poznámka k historii roadmapy: původní 2.11 návrh mluvil o `WORK/REST` goals. Implementovaný vertical slice odděluje routing (`GO_TO_WORK` / `GO_HOME`) od activity/action vrstvy (`WORK` / `REST`). Historie se tím nepřepisuje; aktuální model je přesnější a je runtime ověřený.

### 2.8 Bezpečné Action API

**Stav: deterministic action path DONE / runtime PASS**

Runtime ověřené action primitives / vertical slices:

- `FLEE`
- `MOVE_TO`
- `EAT`
- `WORK`
- `REST`
- `ATTACK` — doplněno a runtime ověřeno v 2.12G3D.

```text
GET_FOOD
    ↓
MOVE_TO validate/execute
    ↓
TrinityCore movement
    ↓
ARRIVED hard validation
    ↓
PendingEat provenance
    ↓
EAT validate/execute
    ↓
CONSUMED
    ↓
NeedsSystem::SatisfyHunger
    ↓
GET_FOOD SUCCEEDED
```

Farmer routine používá stejný ownership princip: AIWorld/routine navrhne akci, `ActionSystem` ji validuje a TrinityCore provede movement/emote. Group coordination v 2.12F/2.12G používá stejnou per-member validační cestu pro REGROUP, ROAM a HUNT; group sama fyzickou akci neprovádí.

**Pravidlo:** AI navrhuje. `ActionSystem` validuje. TrinityCore provádí.

Remote `/decision` execution zůstává dry-run, aby deterministic Goal→Action pipeline a remote AI nebyly dva vlastníci stejné akce. Samostatný `/dynamic-task` vertical slice 2.13 již vytváří serverem validované player-facing questy; nejde o převzetí ownership nad NPC akcemi.

### 2.9 AI server — decision protocol

**Stav: 2.9A–2.9E DONE.**

- [x] Protocol V2 + full `AgentContext`;
- [x] sanitizované Top-N memories;
- [x] structured `DecisionIntent`;
- [x] async transport, timeout/fallback;
- [x] request/agent/snapshot correlation;
- [x] goal-attempt + RuntimeGuid provenance;
- [x] world-thread authoritative ActionRequest translation/validation;
- [x] low-cardinality decision metrics;
- [x] multi-agent batch-shaped submit API.

Otevřené hardening:

- [ ] zúžit external DecisionContext privacy boundary (`spawn_id`);
- [ ] nahradit/hardenovat ruční C++ V2 response parser před external/LLM execution;
- [ ] metrics backend/dashboard runtime evidence;
- [ ] bezpečný transfer execution ownership na remote decision path.

### 2.10 Scheduler a úrovně simulace

#### Celkový stav

| Milník | Stav |
|---|---|
| 2.10A | DONE / PASS |
| 2.10B | DONE / PASS |
| 2.10C | DONE / PASS |
| 2.10D | DONE / static + runtime PASS |
| **2.10 celkem** | **CLOSED** |

World binding a simulation policy jsou oddělené osy. Aktuální model po group identity refactoru:

```text
AgentWorldState:
  MATERIALIZED / ABSTRACT

SimulationTier (individual AgentRecord):
  NEARBY / ACTIVE / BACKGROUND

AgentGroup:
  samostatný GroupId-keyed coarse scheduler
  není SimulationTier::ABSTRACT
```

Historicky 2.10C/2.10D zavedly i `SimulationTier::ABSTRACT` pro tehdejší aggregate-group model. 2.12D tuto část odstranila, protože group už není physical `AgentRecord`; coarse group scheduling nyní běží přes `GroupCoarseSimulationScheduler`.

#### 2.10A — bounded multi-agent decision scheduler

Implementation: `d074bc26` feat(ai-world): add bounded multi-agent decision scheduler (2.10A)

- [x] odstraněn single-test-agent decision bottleneck;
- [x] `DecisionScheduler` je pure-value selection;
- [x] per-agent scheduling state;
- [x] hard global `AIWorld.DecisionMaxInFlight`;
- [x] capacity-skipped agent zůstává due, žádná persistentní request queue;
- [x] více agentů může mít `/decision` současně in-flight;
- [x] response drain uvolňuje per-agent duplicate guard;
- [x] stale/provenance/action ownership pravidla 2.9 beze změny.

Runtime ověřeno se třemi guardy a bounded in-flight admission.

#### 2.10B — proximity-aware decision cadence + fairness

Implementation: `ed0f3408` feat(ai-world): add proximity-aware decision cadence (2.10B)

Hardening: `b6271eac` fix(ai-world): recompute cadence deadlines from live class (2.10B P2)

Defaults:

```ini
AIWorld.DecisionSchedulerIntervalMs = 250
AIWorld.DecisionNearbyIntervalMs = 1000
AIWorld.DecisionActiveIntervalMs = 5000
AIWorld.DecisionNearbyPlayerRange = 60.0
```

- [x] scheduler poll je rychlejší než per-agent cadence;
- [x] `NEARBY` ~1 s;
- [x] `ACTIVE` ~5 s;
- [x] current class recomputuje effective due time, žádný stale absolute deadline;
- [x] effective-due-first ordering zabrání permanentní starvation ACTIVE agentů;
- [x] bounded admission z 2.10A zachována;
- [x] žádné live pointery v scheduler state.

Runtime fairness ověřena i s `DecisionMaxInFlight=1`.

#### 2.10C — explicit simulation policy

Implementation: `5639c9ec` feat(ai-world): add explicit simulation tier transitions (2.10C)

Current individual derivation:

```text
live Creature + player near → NEARBY
live Creature + no player   → ACTIVE
no live Creature            → BACKGROUND
```

- [x] `AgentWorldState` nebyl nahrazen ani conflated se `SimulationTier`;
- [x] `NEARBY/ACTIVE` jsou decision-eligible;
- [x] `BACKGROUND` neposílá `/decision`;
- [x] žádný force-load;
- [x] transition logging pouze při změně;
- [x] AgentId/Needs/memory/goals se transitionem nemění;
- [x] RuntimeGuid semantics beze změny.

#### 2.10D — bounded/staggered coarse scheduling seam

Implementation: `55304729` feat(ai-world): add coarse simulation tier scheduling (2.10D)

Hardening: `3c2122a9` fix(ai-world): bound and desync coarse simulation ticks (2.10D P2)

Runtime hardening: `2cda5756` fix(ai-world): stagger coarse simulation tick phase (2.10D P2 runtime)

Default individual background cadence:

```ini
AIWorld.BackgroundSimulationIntervalMs = 60000
AIWorld.CoarseSimulationMaxPerPass = 50
```

- [x] bounded per-pass admission;
- [x] deterministic ordering podle authoritative `NextTickAtMs`, tie-break AgentId;
- [x] capacity-skipped agent zůstává due;
- [x] žádný catch-up loop;
- [x] coarse epoch reset při vstupu/re-entry do Background;
- [x] deterministic one-time phase offset přes stable AgentId hash;
- [x] po ticku pokračuje scheduling přes plain `now + interval`;
- [x] pure-value state (`LastTickAtMs`, `NextTickAtMs`), žádné live pointery;
- [x] runtime potvrzen deterministic staggering i steady-state cadence.

Historické vstupní Background tick samples (před migrací AgentId v 2.12F4A2):

```text
agent=3 tier=BACKGROUND dt=14253ms
agent=2 tier=BACKGROUND dt=21504ms
agent=1 tier=BACKGROUND dt=46762ms
```

Tyto rozdílné první fáze dokládají entry staggering; steady-state cadence pak pokračuje přibližně po `60000 ms`. Původně otevřený cadence gate je již uzavřený.

#### Známé neblokující scheduler P3

- fast scheduler poll stále prochází registry a live-probuje materializaci každého agenta; před velkou background populací bude potřeba efektivnější materialization/indexing signal;
- coarse selection vytváří/sortuje celý due set před bounded prefix admission; pro velkou populaci může později přijít heap/bucket/deadline index.

### 2.11 První experiment — persistentní farmář

**Stav: 2.11A–2.11E2 CLOSED / static + runtime PASS.**

Referenční NPC: **Pa Maclure** (`SpawnID 80683`, `Entry 250`, Elwynn / Maclure Vineyards). Zůstává `AgentType::Civilian`; profession/routine je samostatná doména, ne nový physical agent type.

#### 2.11A — persistent Home / Work

- [x] pure-value `AgentLocation`;
- [x] nullable persistent HomeLocation / WorkLocation;
- [x] restart/load;
- [x] Pa Maclure seed/runtime identity zachována přes stabilní `AgentId`.

#### 2.11B — deterministic routine

- [x] Home/Work + synthetic day → `GO_TO_WORK` / `GO_HOME`;
- [x] emergency `FLEE_DANGER` routine potlačí;
- [x] routine runtime state je oddělený od persistent AgentRecord identity;
- [x] runtime `NONE → GO_HOME → GO_TO_WORK → GO_HOME`.

#### 2.11C — routine movement přes Action layer

- [x] routine MOVE_TO jen bez aktivního vyššího goal/action ownership;
- [x] target change zastaví starý movement;
- [x] arrival range validation;
- [x] žádné opakované MOVE_TO po dosažení targetu;
- [x] TrinityCore movement zůstává executor.

#### 2.11D — WORK / REST activity state

- [x] transient `RoutineActivity` WORK/REST;
- [x] pouze materialized + alive + at target + bez aktivního goal/action + ne engine-moving;
- [x] `GET_FOOD` / `FLEE_DANGER`, unload a death activity správně preempt/clear.

#### 2.11E1 — WORK / REST ActionType

- [x] `ActionType::Work` / `ActionType::Rest`;
- [x] provenance + completion flow;
- [x] one-shot emote pouze přes ActionExecutor;
- [x] runtime WORK/REST PASS.

#### 2.11E2 — economy persistence

- [x] work-window replay suppression;
- [x] persistent Money/Food/Resource state;
- [x] Money `uint64`;
- [x] monotonic economy version;
- [x] mutation/version bump centralizovaný v persistence API;
- [x] static PASS/CLOSED.

Neblokující caveat: fire-and-forget state snapshot persistence není absolutní crash-durability transakce; pro současný economy vertical slice je to přijaté.

### 2.12 — AgentGroup / coalition

#### Architektonický model

```text
AgentGroup
  ↓
generic observations
  ↓
generic group coordination / intent
  ↓
generic intent decomposition per member
  ↓
individual Agent
  ↓
ActionSystem
  ↓
TrinityCore
```

**Group = coordination. Agent = deciding/physical entity. ActionSystem = execution authority. TrinityCore = world mutation.**

Wolf/WolfLoose je první runtime fixture/profile. Není to produktová architektura. Přidání druhého typu nesmí vést k `RunBandit...()`, `RunGuard...()`, `WolfPackIntentSystem`, `BanditMovementCoordinator` ani jiné species-specific orchestration větvi.

Každý člen má vlastní `AgentId`/spawn binding, memory, needs, goals, decisions/actions a materialized/unloaded lifecycle. `AgentGroup` vlastní pouze `GroupId`, `AgentGroupKind { Loose, Stable }`, persistent membership edges `GroupId ↔ AgentId`, territory/shared environmental resources a coordination state. Population je odvozena z membership count; není samostatnou mutable aggregate population.

#### 2.12A–2.12C — původní group experiment a pivot

**Stav: CLOSED.**

- [x] první persistent group state a coarse simulation seam;
- [x] real wolf membership/presence runtime evidence;
- [x] potvrzeno, že přirozené materialization členů nepoužívá force-load;
- [x] architecture review odmítl pseudo-group jako fake `AgentRecord`/SpawnId identity;
- [x] group-level Hunger odstraněn, protože needs patří jednotlivým členům.

#### 2.12D — oddělená AgentGroup identity

**Stav: CLOSED.**

- [x] samostatný `GroupId`;
- [x] `AgentGroupRecord` / `AgentGroupRegistry` / `AgentGroupPersistence`;
- [x] `ai_agent_groups` oddělená od `ai_agents`;
- [x] `AgentType::AgentGroup` odstraněn;
- [x] `SimulationTier::Abstract` odstraněn z individual simulation policy;
- [x] group coarse tick má `GroupCoarseSimulationScheduler` s `AIWorld.GroupSimulationMaxPerPass`;
- [x] membership loader vyžaduje existující `AgentId`;
- [x] `AgentGroupKind` load je fail-closed (`Loose`/`Stable` pouze);
- [x] group simulation běží nezávisle na tom, zda jsou členové materialized;
- [x] saturated `Resources` no-op už nezvyšuje Version ani nevydává DB write.

Historický natural presence runtime gate byl ověřen se třemi individuálními agenty (`AgentId 1,2,3` před migrací F4A2):

```text
loadedMembers=0
→ každý wolf se přirozeně materializuje jako vlastní Creature
→ loadedMembers=3
→ group coarse simulation pokračuje
```

Group se nikdy neváže 1:1 na žádný `Creature`.

#### 2.12E1 — runtime group lifecycle

**Stav: CLOSED / STATIC PASS + RUNTIME PASS.**

Implementované API:

```text
CreateGroup(...)
JoinGroup(GroupId, AgentId)
LeaveGroup(GroupId, AgentId)
DissolveGroup(GroupId)
```

- [x] `AgentGroupLifecycleSystem` je jediný owner create/join/leave/dissolve orchestrace;
- [x] join vyžaduje existující group i existující individual `AgentRecord`;
- [x] duplicate membership je odmítnut;
- [x] lifecycle nemutuje individual AgentRecord/Creature world state;
- [x] žádné fake SpawnId / pseudo physical agents;
- [x] membership add/remove DB write je potvrzen read-backem před runtime mutation;
- [x] dissolve maže memberships + group jako jednu DB transakci a runtime registry mění až po potvrzení;
- [x] `GroupId` používá persistentní monotónní `ai_agent_group_id_sequence`;
- [x] sequence load je fail-closed;
- [x] sequence musí být nonzero a `next_group_id > MAX(ai_agent_groups.group_id)` nad fyzickou DB tabulkou;
- [x] sequence reservation je potvrzená read-backem před group INSERT;
- [x] runtime smoke používá pouze existující AgentIds, nevyrábí ghost agenty;
- [x] restart/non-reuse runtime gate PASS.

Historická runtime evidence před migrací individuálních AgentId v 2.12F4A2:

```text
sequence = 2
Create GroupId 2 → Join 1,2,3 → Leave 3 → Dissolve 2 → PASS
DB: GroupId 2/memberships gone, sequence = 3
restart
load sequence = 3
Create GroupId 3 → Join 1,2,3 → Leave 3 → Dissolve 3 → PASS
```

Tím je potvrzeno, že dissolved `GroupId` se po restartu nerecykluje a individual AgentIds zůstávají nedotčené.

Persistence confirmation předchází authoritative registry mutation. Původní synchronní DB boundary 2.12E1 byla následně nahrazena async cestou v 2.12E2 níže.

#### 2.12E2 — async-safe lifecycle boundary

**Stav: CLOSED.**

Hotovo:

- runtime lifecycle nepoužívá blocking synchronous DB round-trip z recurring world-thread cesty;
- persistence requesty jsou async;
- completion se zpracovává na world threadu;
- per-GroupId operation locking/serialization brání překryvu Join/Leave/Dissolve;
- registry se mění až po confirmed persistence result;
- žádné TC live pointery přes async boundary.

Implementační detail: `TransactionCallback`/`TransactionCallbackProcessor` zpracovává completion při `Update()`; `_pendingGroupOperations` serializuje operace stejné group a zavírá orphan-membership race mezi Join a Dissolve. `AgentGroupLifecycleSystem` zůstává jediným ownerem této orchestrace.

#### 2.12E3 — Loose / Stable policy

**Stav: CLOSED.**

Hotovo:

- `AgentGroupPolicySystem` odděluje policy od persistence/orchestrace;
- `Manual` vs `AutomaticPolicy` source provenance;
- Loose podporuje automatické leave/dissolve podle policy;
- Stable je chráněná proti automatickému leave/dissolve;
- automatic caller neobchází policy gate.

`CanJoin`/`CanLeave`/`ShouldDissolve` používají kind a member bounds (`LooseGroupMinMembers`/`LooseGroupMaxMembers`). Ochrana Stable proti automatické změně neblokuje explicitní Manual lifecycle operaci.

#### 2.12E4 — generic formation + maintenance

**Stav: CLOSED / STATIC + RUNTIME PASS.**

Hotovo:

- `CoalitionFormationProfile` / `CoalitionMaintenanceProfile` jsou profile-driven data;
- generic `RunCoalitionFormation(...)` a `RunCoalitionMaintenance()` orchestrace;
- WolfLoose je pouze první profile fixture;
- deterministic candidate selection;
- async CreateGroup + Join chain;
- bounded recurring discovery/work;
- cross-profile formation reservation brání concurrent member race;
- `ProfileId` provenance je persistentní a validovaná;
- maintenance používá bounded cursor/high-water scan;
- automatic leave + below-min dissolve runtime ověřeno;
- restart neobnoví confirmed-dissolved group;
- automatic formation regression vytvořila nový real AgentGroup nad skutečnými Agents.

Implementační členění: `CoalitionFormationSystem` v 2.12E4A/B, pure `CoalitionMaintenanceSystem` v 2.12E4C1, bounded orchestrace 2.12E4C2 a generalizace 2.12E4R. `CoalitionFormationProfileId` selektuje policy data; `AgentGroupRecord::ProfileId` nese persistentní provenance. `AIWorldMgr::RunCoalitionMaintenance()` používá `AgentGroupRegistry::GetGroupsAfterUntil()`, jeden globální cursor/high-water scan s per-group profile resolution. `AIWorld.TestDissolveGroupId` je startup-only hook pro fresh-formation regression. STATIC review uzavřelo cross-profile reservation race, profile provenance, confirmed profile adoption a cursor/high-water starvation.

#### 2.12F1 — generic AgentGroup intent layer

**Stav: CLOSED / STATIC + smoke PASS.**

První intent:

```text
AgentGroupIntentType::Regroup
```

`AgentGroupIntentSystem` je pure/value a nezná species. Profile poskytuje pouze policy data, například `RegroupEnabled` a `RegroupRadius`.

Runtime/pure smoke pokryl:

- far materialized/alive member → REGROUP;
- near member → NONE;
- unloaded → NONE;
- dead → NONE;
- different map → NONE;
- disabled/invalid/mismatched profile → NONE.

Kontrakt tvoří `AgentGroupIntentType`, `AgentGroupIntent`, `AgentGroupCoordinationProfile` a `AgentGroupIntentSystem`; Kind/ProfileId/profile validation je fail-closed stejně jako u maintenance.

#### 2.12F2 — group intent → individual ActionSystem dispatch

**Stav: CLOSED / STATIC + RUNTIME PASS.**

```text
AgentGroupIntent(REGROUP)
    ↓
AgentGroupIntentProjector
    ↓
GroupMemberActionProposal
    ↓
individual ActionRequest(MOVE_TO, SourceGoal=REGROUP)
    ↓
ActionSystem::Validate
    ↓
ActionExecutor
    ↓
TrinityCore movement
```

Dispatch před akcí znovu validuje:

- Agent stále existuje;
- membership stále platí;
- group/profile/intent stále platí;
- Agent je materialized + alive;
- map/provenance sedí;
- žádný higher-priority individual owner;
- žádný conflicting active action;
- overlapping regroup-enabled membership failuje zavřeně;
- target je v ActionSystem execution range;
- žádné force-load a žádný pointer escape.

Priority:

```text
Emergency ActiveGoal
    > Normal ActiveGoal
    > RoutineGoal
    > Group REGROUP
```

Runtime bylo potvrzeno:

- generic REGROUP vytvořil per-member `MOVE_TO` request;
- `ActionSystem` vrátil `ALLOWED`;
- execution `STARTED`;
- agent dorazil k group territory;
- po arrival nevznikal duplicate REGROUP spam.

Implementační a review detaily:

- `AgentGroupIntentProjector` je pure per-member decomposition, bez TC pointerů a bez opakované derivace validací intent systému.
- `RunCoalitionCoordination()` má vlastní bounded discovery cursor, oddělený od maintenance; `DispatchGroupMemberActionProposal()` provádí dispatch-time revalidaci.
- `AgentGroupRegistry::GetGroupsOfMember()` poskytuje reverse membership index; overlap arbitration nepotřebuje per-proposal O(all groups) scan.
- Confirmed Leave/Dissolve zastavuje coordination přes `StopGroupCoordinationForMember`/`StopInFlightGroupCoordination`; confirmed Join řeší novou ambiguity přes `ReconcileGroupCoordinationForMember`.
- Formation/Leave radii zůstávají nezávislé na ActionSystem execution limitu; unreachable member se řeší až při dispatch-time reachability kontrole.
- Šest STATIC review kol uzavřelo lifecycle/pending-operation race, batch-scoped arbitration, policy/execution coupling regresi, recurring scan, confirmed-Join ambiguity a diagnostiku. Group vrstva nevolá přímo `MovePoint()` ani species-specific `RunWolfRegroup()`.

#### 2.12F3 — lifecycle / preemption integration proof

**Stav: CLOSED.**

##### Static/build gate

- finální hardened hook commit: `57c656d1f9c963c22b9b15a73b6da52b5c8f9bed`;
- poslední static review: **P1=0, P2=0, P3=0**;
- build/runtime použitý pro finální proof: **PASS**;
- hook je defaultně vypnutý a není produkční behavior path.

##### Emergency preemption proof

Skutečný běh potvrdil:

```text
REGROUP MOVE_TO running
    ↓
agent enters combat
    ↓
SafetyPressure = 1.0
    ↓
FLEE_DANGER / EMERGENCY activates
    ↓
COORDINATION_PREEMPTED_BY_GOAL
    ↓
REGROUP movement stopped
    ↓
individual FLEE request owns action
```

Tím je runtime potvrzeno, že group coordination nikdy nepřebíjí individual Emergency ownership.

##### Dissolve-during-active-REGROUP proof

`AIWorld.TestDissolveOnActiveRegroupGroupId` je one-shot proof hook. Hardened verze:

- validuje configured GroupId až po loadu registry;
- záporný/invalid GroupId failuje zavřeně;
- nekontroluje condition každý world tick, ale pouze po skutečném `RunCoalitionCoordination()` passu;
- trigger vyžaduje plnou ownership/provenance shodu:
  - `ActiveActionState::Type == MoveTo`;
  - `ActiveActionState::SourceGoal == Regroup`;
  - `GroupCoordinationGoalState::Type == Regroup`;
  - správný `SourceGroup`;
  - matching attempt timestamp identity;
  - materialized Agent;
  - transientně resolved live Creature;
  - skutečně běžící AIWorld-owned MoveTo generator;
- hook pouze zavolá authoritative `RequestDissolveGroupWithPolicy(..., Manual)`; sám nezastavuje movement, nemutuje registry a nedělá raw SQL.

Startup-only `AIWorld.TestDissolveGroupId` tento active-REGROUP race neprokazuje, protože běží před prvním coordination passem. Active hook loguje `CONFIRMED` až po committed dissolve a má self-disable latch také pro group zaniklou produkční lifecycle cestou po startupu; nezůstává pollovat mrtvý target.

Finální runtime proof na nové group potvrdil sled:

```text
formation PASSED → real group created
    ↓
REGROUP request sourceGroup=<group>
    ↓
hook observes real active REGROUP
    ↓
Manual dissolve requested
    ↓
AI agent group dissolved
    ↓
COORDINATION_STOPPED_BY_LIFECYCLE
    ↓
sourceGoal=REGROUP + matching sourceGroup
    ↓
dissolve CONFIRMED
```

To dokazuje, že pohyb zastavila existující produkční lifecycle cesta, nikoli test hook.

##### Restart / no-resurrection proof

Po confirmed dissolve, vypnutí hooku a restartu:

- dissolved GroupId se z persistence znovu nenačetl;
- nevznikl žádný stale `sourceGroup=<dissolved id>` REGROUP;
- žádné FAILED/ERROR související s tímto lifecycle proof;
- žádná duplicate group/action resurrection.

##### F3 closure

```text
2.12F3 STATIC                    PASS
2.12F3 BUILD                     PASS
2.12F3 REGROUP                   PASS
2.12F3 ARRIVAL / NO-SPAM         PASS
2.12F3 EMERGENCY PREEMPTION      PASS
2.12F3 LIFECYCLE CANCELLATION    PASS
2.12F3 GROUP PROVENANCE          PASS
2.12F3 RESTART / NO RESURRECTION PASS

2.12F3 = CLOSED
```

Po proofu mají testovací flagy zůstat vypnuté:

```ini
AIWorld.TestDissolveGroupId = 0
AIWorld.TestDissolveOnActiveRegroupGroupId = 0
AIWorld.TestGroupIntent = 0
AIWorld.TestGroupIntentProjector = 0
```

---

#### 2.12F4 — Global Agent Population

**Stav: 2.12F4A–F4B3 CLOSED pro Elwynn; 2.12F4C/F4D DEFERRED před rozšířením mimo jednu lokaci.**

Tento foundation gate předcházel 2.12G1: druhý coalition profil potřeboval reálné, reconciled spawny a explicitní control/identity boundary. Následující návrhové zdůvodnění popisuje problémy původní implementace před F4A/F4A2; aktuální výsledek a runtime evidence jsou u jednotlivých podmilníků.

##### Proč je to samostatný gate, ne jednoduchý INSERT

Dnes je „AI agent" prakticky každý řádek v `characters.ai_agents`; `LoadAgents()` při startu všechny načte a `CreateCreatureAgent()` vytváří vazbu `(map_id, spawn_id) → AgentId`. Současně ale `OwnsSpawn()` rozhoduje, jestli `Creature` dostane `AIWorldCreatureAI` místo normálního TrinityCore AI, a `AIWorldCreatureAI` při převzetí nastaví `REACT_PASSIVE` a `MoveIdle()`. Prostá registrace všech spawnů by tedy dnes převzala i guardy, vendory, quest NPC, bossy a scripted NPC a rozbila jejich vanilla/script chování.

Současná runtime vrstva navíc ještě není připravená na desetitisíce agentů — scheduler discovery, world-event perception, nearby perception, needs update a coalition candidate discovery jsou dnes lineární `_registry.GetAgents()`/`FindBySpawn()` scany nad celou registry. Existující komentář v kódu přímo říká, že lineární event scan je přijatelný pro „single-digit/dozens" a spatial index má přijít při stovkách+ agentech.

**Varianta „INSERT všechny spawny do `ai_agents` a hotovo" je zamítnutá** — v současném kódu by byla funkčně (přebití vanilla/scripted AI) i výkonnostně (recurring O(all agents) scany) nebezpečná.

##### Cílový model

```text
REAL TRINITYCORE CREATURE SPAWN (non-instance / base-world)
        ↓
persistent AgentId / AgentRecord
        ↓
ALL persistent non-instance creatures are AIWorld-known agents
        ↓
ControlMode
   ├── ObserveOnly
   └── AIWorldControlled
              ↓
        AI proposes actions
              ↓
          ActionSystem
              ↓
          TrinityCore
```

Každá reálná mobka/NPC dostane persistentní identitu (memory/relationships/group eligibility), aniž bychom zničili TrinityCore chování dřív, než pro daný typ existuje adekvátní AIWorld behavior.

**Terminologie:** enum má přesně dvě hodnoty, `ObserveOnly` a `AIWorldControlled`. Nikde jinde v tomto dokumentu ani v kódu se nepoužívá `VanillaControlled` ani `FullControl` — jsou to jména pro tutéž semantiku a vedla by ke dvěma pojmenováním jednoho konceptu.

**Bezpečné pořadí (STATIC review, P2 nálezy proti dřívější verzi tohoto gate):** `ControlMode` schema a jeho hard enforcement musí existovat *před* jakýmkoli bulk bootstrapem, ne až po něm. Dřívější pořadí (nejdřív bootstrapovat všechny `world.creature` do `AgentId`, teprve pak přidat ownership split) by samo vytvořilo přesně ten nebezpečný přechodný stav, který tento gate má odstranit — `AgentRegistry` dnes žádný `ControlMode` koncept nemá a každý načtený persistentní record považuje za běžného agenta. Proto je pořadí A→B→C→D, kde `ControlMode` (A) je prerequisite reconciliace (B), ne naopak.

**Scope: non-instance / base-world spawny (STATIC review P2 fix).** Současná identita používá pouze `(mapId, spawnId) → AgentId` a jeden `RuntimeGuid` na `AgentRecord` — to funguje pro persistentní open-world spawn, ale ne obecně pro instance/raid mapy, kde stejný `(map_id, spawn_id)` může existovat současně jako několik různých `Creature` objektů v různých instancích (runtime na řadě míst už dnes za live/materializovaného světa používá `FindBaseNonInstanceMap(record->MapId)`; event enrichment přiřazuje `AgentId` jen podle `MapId`+`SpawnId`, bez instance identity). Globální registrace instance spawnu by dvě různé incarnace namapovala na stejný `AgentId`/`RuntimeGuid` — sdílená persistent identity, smíchané eventy/memory/provenance, přímý konflikt s invariantem „individual Agent = konkrétní physical entity". **`2.12F4` scope je proto výhradně persistentní non-instance/base-world creature spawny.** Instance/raid creature zůstávají mimo, dokud nebude samostatně navržená instance-aware identity semantics — to je jiný problém, ne 2.12F4. Rozšiřovat `AgentId` o `InstanceId` v rámci tohoto gate by bylo scope creep.

**Scope predicate ≠ `FindBaseNonInstanceMap()` (STATIC review P3 fix).** `FindBaseNonInstanceMap(mapId)` nejprve volá `FindBaseMap(mapId)`, které vrátí `nullptr`, pokud daná base map ještě v procesu nebyla vytvořena — teprve pokud mapa existuje, kontroluje `Instanceable()`. Je to tedy runtime resolver nad už materializovaným světem, ne autorita pro census/reconciliation: startup reconciliation (`2.12F4B`) nesmí spawn přeskočit jen proto, že `FindBaseNonInstanceMap()` zrovna vrátil `nullptr`, protože ta konkrétní base map ještě nebyla v procesu vytvořená — to by legitimní open-world spawny vynechávalo nedeterministicky, podle toho, které mapy už byly zrovna materializované. Scope predicate pro `2.12F4B` musí být deterministický nad statickými map metadaty, nezávislý na tom, jestli je daná mapa zrovna vytvořená:

```text
MapEntry existuje
AND MapEntry::Instanceable() == false
```

`FindBaseNonInstanceMap()` zůstává tím, čím je dnes — runtime resolver pro live/materializovaný svět (perception, event enrichment, dispatch) — jen se nesmí použít jako scope filtr při `2.12F4B` census/reconciliation.

##### 2.12F4A — ControlMode foundation

**Stav: CLOSED / STATIC PASS (`967282a543`, `543a235fc8`, `416016164b`).** Build/runtime nebyly pro F4A samostatně verifikovány odděleně od navazujících F4A2–F4B3 komitů, ale ControlMode gate je od té doby beze změny součástí každého dalšího runtime-ověřeného kroku (viz F4B3 níže).

**Priorita: první krok, prerequisite všeho ostatního v tomto gate.**

Existence `AgentRecord` už nesmí sama o sobě znamenat, že AIWorld převezme TrinityCore `CreatureAI` ani že smí způsobit jakoukoli fyzickou akci nad Creature. Potřebujeme explicitní, persistentní control/ownership stav oddělený od pouhé identity:

```text
ControlMode
   ├── ObserveOnly       — AgentId/AgentRecord existuje, TrinityCore/scripted AI běží beze změny
   └── AIWorldControlled — AIWorldCreatureAI vlastní CreatureAI, AI proposes / ActionSystem / TrinityCore pipeline
```

`ObserveOnly` je tvrdý invariant, ne jen "nepřevezmi `CreatureAI`":

```text
AIWorld may observe/state-track this agent.
AIWorld MUST NOT cause physical world mutation for this agent.
```

`AgentRecord` dnes nese needs, active goal, routine goal, group coordination goal i active action — u tisíců nových `ObserveOnly` recordů nestačí zabránit jen vzniku `AIWorldCreatureAI`.

**`ActionSystem::Validate()` je mandatory authoritative gate, ne "ideální" defense-in-depth (STATIC review P2 fix proti dřívější verzi).** `ActionSystem` je už dnes explicitně definovaný jako safety boundary: *AI proposes → ActionSystem validates → ActionExecutor executes only on ALLOWED.* `ActionExecutor` je engine boundary, jehož vlastní kontrakt už dnes předpokládá, že se volá až poté, co `ActionSystem::Validate()` vrátil `Allowed` — psát `ControlMode` gate až na `ActionExecutor` by tento kontrakt obracelo. Správný pipeline:

```text
scheduler/routine/group gates
    ↓          performance + early rejection, ne safety boundary
ActionRequest
    ↓
ActionValidationContext.ControlMode
    ↓
ActionSystem::Validate()
    ↓
ObserveOnly       → REJECT
AIWorldControlled → pokračovat
    ↓
ActionExecutor
```

`ControlMode` jde do `ActionValidationContext` jako čistá hodnota — context je už dnes DTO světových faktů, které sestavuje `AIWorldMgr`, takže tím neporušíme pure/value hranici `ActionSystem`u. `ActionExecutor` nemusí znát `AgentRecord` ani `ControlMode` a zůstává třetím krokem až po úspěšné validaci.

`ControlMode` tedy gatuje na dvou různých úrovních, s různým účelem:

- **performance/early-rejection** (ne safety boundary samo o sobě) — decision scheduler / `ProcessAgent()`, routine → action proposal, group action proposal/dispatch (`DispatchGroupMemberActionProposal()` a ekvivalenty), automatic coalition membership pokud z ní může vzniknout fyzická akce — `ObserveOnly` agent se sem nemá dostat vůbec, aby se nezbytečně stavěl `ActionRequest`, který stejně skončí `REJECT`;
- **authoritative safety gate** — `ActionSystem::Validate()` přes `ActionValidationContext.ControlMode`, mandatory, ne volitelné; i kdyby některý z gatů výše selhal nebo byl obejit, `Validate()` musí `ObserveOnly` request odmítnout.

Bez tohoto gatingu na `ActionSystem` úrovni může vanilla/scripted AI stále vlastnit `CreatureAI`, zatímco AIWorld pošle stejnému `Creature` `MOVE_TO`/`FLEE`/`EAT` atd. — dual ownership nad jedním fyzickým objektem. `2.12F4C` (scale hardening) toto neřeší; ownership bezpečnost musí být hotová už zde.

Kroky:

- `ControlMode` jako persistentní pole `AgentRecord`/`ai_agents`;
- `OwnsSpawn()` (nebo ekvivalentní rozhodovací bod) se řídí `ControlMode`, ne pouhou existencí `AgentRecord`;
- `ActionValidationContext` získá `ControlMode` pole; `ActionSystem::Validate()` odmítá `ObserveOnly` bezpodmínečně, před jakoukoli per-`ActionType` validací;
- performance-gates výše (scheduler/routine/group) zůstávají, ale jsou dokumentované jako optimalizace, ne jako náhrada `ActionSystem` gate;
- migrace: současné 4 testovací mobky → `AIWorldControlled` (explicitní, ne implicitní default);
- nový/default bootstrap row → `ObserveOnly`.

Runtime gate: `ObserveOnly` agent nikdy neprojde decision schedulerem, nikdy nedostane routine/group action proposal a `ActionSystem::Validate()` odmítne jakýkoli `ActionRequest` pro `ObserveOnly` agenta i v případě, že by performance-gate výše selhal — `ActionExecutor` se pro `ObserveOnly` nikdy nezavolá, protože `Validate()` mu to nedovolí, ne protože to sám kontroluje.

##### 2.12F4A2 — TrinityCore-aligned Agent identity (`AgentId == SpawnId`)

**Stav: CLOSED / STATIC PASS (`3c910a4e2a`, `f6211fbeab`).** Invariant `AgentId == SpawnId` je od tohoto bodu vynucený fail-closed v `CreateCreatureAgent()`/`LoadAgents()`/reconciliation a runtime-ověřený navazujícími F4B/F4B2/F4B3 běhy nad reálnou populací (128849 full-world, 3540 Elwynn) beze zjištěného mismatch.

**Priorita: až po 2.12F4A, striktně před 2.12F4B.** `2.12F4B` má vytvořit řádově tisíce nových `AgentRecord`ů z `world.creature`; změna identity schématu až po tomto bulk bootstrapu by znamenala migrovat tisíce cizích klíčů napříč `ai_agents`, `ai_agent_group_members`, `ai_long_term_memories` a dalšími tabulkami místo dnešních čtyř — udělat to teď je řádově levnější a bezpečnější.

Dnešní `AgentId` je `ai_agents.agent_id`, MySQL `AUTO_INCREMENT`, nezávislý na tom, ke kterému `world.creature` spawnu patří (`AgentId 1 → spawn 80335`, ...). To je zbytečná indirection: k přečtení "který spawn/creature patří k agentovi X" je vždy nutná zpětná lookup přes `ai_agents`, a v logu/debug session `agent=1` nic neříká o tom, co reálně hledat v `creature`/`creature_template`.

Nové pravidlo pro persistentní non-instance Creature agenty:

```text
AgentId.Value == TrinityCore Creature SpawnId (world.creature.guid)
```

`AgentId` (persistentní identita v rámci AIWorld API) a `Creature::GetGUID()`/`RuntimeGuid` (aktuálně materializovaná instance té identity) zůstávají oddělené, jen numericky sladěné s `SpawnId`, ne s `RuntimeGuid`:

```text
world.creature.guid = 80683
        ↓
AgentId = 80683           ← persistentní identita, stabilní přes restart
        ↓
AgentRecord
    SpawnId     = 80683   ← provenance/binding na world.creature, viz níže
    MapId       = 0
    RuntimeGuid = <aktuální ObjectGuid nebo empty>   ← mění se mezi materializacemi/restarty
```

`AgentRecord::SpawnId` se **neruší**, i když bude číselně identické s `AgentId::Value`. Mají jiný význam — `AgentId` je identita entity uvnitř AIWorld API, `SpawnId` je explicitní provenance/foreign binding na konkrétní `world.creature` řádek. To umožňuje invariant assert (`record.Id.Value == record.SpawnId`) jako levnou debug/consistency kontrolu, ne jako redundanci k odstranění.

**Instance scope zůstává mimo tento krok.** Stejný DB spawn může mít víc současně živých instancí (`spawn 12345` → instance 17 i instance 42 zároveň) — ty nemohou sdílet jeden `AgentId 12345`, jsou to fyzicky oddělené bytosti. `2.12F4` (celé, včetně F4A2) zůstává scoped jen na non-instance/base-world spawny (viz Scope predicate výše, `MapEntry` existuje a `Instanceable() == false`) přesně proto, aby se identity-per-instance problém nemusel řešit teď. Instance identity (např. `RuntimeAgentIdentity{ SpawnId, InstanceId }` nad stejným persistentním `SpawnId`) je vlastní budoucí milestone, ne součást `2.12F4A2` — tady se kvůli instancím nesmí znovu zavést anonymní/generated `AgentId`.

Kroky:

- `AgentPersistence::CreateCreatureAgent()` už nespoléhá na MySQL `AUTO_INCREMENT` pro odvození `AgentId` u creature agentů — insert explicitně nese `agent_id = spawn_id`; read-back-by-binding disciplína (viz `FindBinding()`) zůstává, jen už neslouží k zjištění MySQL-přiděleného ID, ale k potvrzení, že řádek s očekávaným `agent_id` skutečně existuje;
- migrace existujících 4 agentů na jejich vlastní `SpawnId`: `1 → 80335`, `2 → 214023`, `3 → 214021`, `4 → 80683`, včetně navazujících řádků v `ai_agent_group_members` (`member_agent_id`) a `ai_long_term_memories` (`agent_id`) a jakékoli další tabulky, která dnes ukládá `agent_id` jako cizí klíč na `ai_agents`;
- žádné místo v kódu ani dokumentaci nesmí předpokládat `AgentId = AIWorld-generated sequence` — `AgentRegistry::Add()` dnes negeneruje/nepřiděluje nic sama, ale kdekoli se dřív implicitně počítalo s malými sekvenčními hodnotami (logy, testy, komentáře), je nutné to opravit;
- **namespace policy je rozhodnutá teď, ne odložená na 2.12F4B (P2 fix, STATIC review):** `ai_agents.agent_id` přestává být `AUTO_INCREMENT` úplně. `AgentType` dnes zahrnuje jen `Civilian`/`Guard`/`Merchant` — každý z nich reálný creature agent — takže není žádný současný důvod nechávat v tomto namespace možnost anonymní MySQL-generated hodnoty; ponechaný `AUTO_INCREMENT` by znamenal riziko kolize budoucí auto-přidělené hodnoty s reálným `spawn_id` při `2.12F4B` reconciliation. Platí natvrdo: `Creature AgentId namespace == TrinityCore SpawnId namespace, žádná náhodně generovaná ID.` Budoucí ne-creature `AgentType` (pokud kdy vznikne) musí mít vlastní oddělený namespace nebo vlastní tabulku, nikdy tichou auto-alokaci do tohoto sloupce/rozsahu;
- `AgentPersistence::CreateCreatureAgent()` a `LoadAgents()` vynucují invariant fail-closed, ne jen logují: existující binding s `agent_id != spawn_id` se odmítne znovupoužít, čerstvý INSERT jehož read-back neodpovídá `spawn_id` se odmítne vrátit, a při loadu se řádek porušující invariant do `AgentRegistry` vůbec nepřidá (quarantine, ERROR log) — žádná z těchto cest nesmí nechat běžet agenta, o kterém systém sám ví, že porušuje `AgentId == SpawnId`.

Runtime gate: pro každý persistentní non-instance Creature platí `AgentId.Value == TrinityCore Creature SpawnId`; `agent=<id>` v logu je přímo `SELECT * FROM creature WHERE guid = <id>` bez zpětné lookup přes `ai_agents`; existující 4 test agenti fungují po migraci identicky (`ControlMode`, group membership, long-term memory beze ztráty dat); jakýkoli řádek porušující invariant je fail-closed odmítnut/quarantined (nikdy tiše nefunguje dál jako platný agent) a `ai_agents.agent_id` už nikdy nepřidělí hodnotu mimo `spawn_id`-derived namespace.

##### 2.12F4B — Global spawn reconciliation

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS (`ad80db5949`, `149e400927`, `326e7a7b19`) — engine runtime-ověřen jak nad plnou světovou populací (128849, viz Runtime evidence níže), tak scoped nad Elwynn (2.12F4B2/F4B3).**

**Priorita: až po 2.12F4A a 2.12F4A2** — reconciliace smí vytvářet nové `AgentRecord`s pouze do bezpečného `ControlMode` (2.12F4A), a musí od prvního nově vytvořeného záznamu používat finální identitu `AgentId == SpawnId` (2.12F4A2) — dělat bulk bootstrap se starou `AUTO_INCREMENT` identitou a pak ji migrovat přes tisíce řádků by bylo přesně to draho/rizikové, čemu má 2.12F4A2 předejít.

Roadmap dříve specifikovala jen jednosměrný bootstrap (`world.creature` → chybějící `ai_agents`: vytvoř). To je neúplné vůči vlastnímu invariantu projektu — **každý individuální `AgentRecord` musí odpovídat skutečnému TrinityCore Creature spawnu.** `AgentRegistry` dnes drží persistentní record jako `Abstract` i bez právě načteného `Creature` a sám nepozná, že DB spawn byl definitivně odstraněn. `2.12F4B` proto musí být obousměrná reconciliace, ne pouze bootstrap — a stejně jako zbytek `2.12F4` **jen nad non-instance/base-world spawny** (viz Scope výše; instance/raid spawny se do žádné z níže uvedených tří větví nezahrnují):

```text
world.creature (non-instance) → chybí v ai_agents:
    CREATE (ControlMode = ObserveOnly, viz 2.12F4A)

ai_agents → existuje odpovídající non-instance world.creature:
    valid, beze změny

ai_agents → world.creature spawn už neexistuje:
    fail-closed / quarantine / controlled cleanup
    NESMÍ se načíst jako legitimní persistent agent
```

Bez směru "dolů" (spawn byl z TrinityCore DB odstraněn) bychom po smazání spawnu vytvořili přesně ten typ ghost persistent agenta, který architektura jinde zakazuje.

Druhý otevřený bod: **`AgentType` provenance.** `CreateCreatureAgent(AgentType type, uint32 mapId, uint64 spawnId)` vyžaduje typ a `LoadAgents()` `agent_type` načítá jako součást persistentní identity; dnes existují jen `Civilian`/`Guard`/`Merchant`. `world.creature` ale obsahuje wolves/beasts, bosses, quest creatures atd. — bulk bootstrap nesmí prostě všechno uložit jako `Civilian`. Před spuštěním `2.12F4B` je nutné explicitně rozhodnout jednu variantu:

- rozšířit identity model o obecnější typ, nebo
- mít deterministickou classification policy (např. z `creature_template`), nebo
- oddělit základní Creature-agent identitu od gameplay/archetype klasifikace.

Žádná heuristická ani fingovaná provenance — nejasný typ musí být explicitní `Unknown`/quarantine stav, ne tichý default na `Civilian`.

Kroky:

- `world.creature` (non-instance/base-world scope — `MapEntry` existuje a `Instanceable() == false`, ne `FindBaseNonInstanceMap()`, viz Scope predicate výše) je source of truth, žádné fake/synthetic spawny;
- reconciliation je idempotentní: existující `(map_id, spawn_id) → AgentId` binding se zachová, nový spawn dostane `AgentId == SpawnId` (viz 2.12F4A2, ne nově generovanou hodnotu) do `ObserveOnly`, restart nevytvoří duplicity;
- chybějící/odstraněné spawny se detekují a fail-closed karanténují, ne tiše zůstávají v `_registry` jako živý agent;
- deterministická `AgentType`/provenance politika je rozhodnutá a implementovaná před prvním bulk bootstrapem;
- temporary summons bez persistentního `SpawnId` se do reconciliace nepočítají;
- reconciliation běží jako bounded/administered krok (startup nebo explicit admin trigger), ne jako recurring per-tick world-thread práce.

Runtime gate: opakovaný restart nad stejným `world.creature` datasetem nikdy nevytvoří duplicitní `AgentId`, nikdy nevynechá nový spawn přidaný mezi restarty, a smazaný spawn nikdy nezůstane v `_registry` jako platný `AgentRecord`.

**Implementační stav:** engine je hotový (`ad80db5949` + STATIC review fixy `149e400927`, `326e7a7b19`) — census/diff/reconcile, fail-closed `AgentId`/`agent_id` collision handling, instance/out-of-scope rozlišení od skutečně smazaných spawnů, i sám bulk insert (chunked multi-row `INSERT`, ne per-row). Gated za `AIWorld.EnableSpawnReconciliation` (default 0).

**Runtime evidence (už naměřeno, ne odhad):** engine byl reálně spuštěn nad celým světem (`AIWorld.EnableSpawnReconciliation = 1`, bez zone scope) a naměřil `census=128849 valid=128849 identity mismatch=0 ObserveOnly=128845 Controlled=4` — identitní invarianty (`AgentId == SpawnId`, no ghosts, no duplicates) tedy drží i při plné světové populaci. Zároveň ale způsobil viditelné runtime zpomalení worldserveru/NPC processing. `2.12F4B2` proto NENÍ "first population proof" — ten už proběhl a byl to global stress experiment, který skončil performance FAIL před `2.12F4C`. `2.12F4B2` je navazující, bounded locality proof nad Elwynn: zjistit, jestli current dev scope (menší, ale reálná populace) funguje bez `2.12F4C`. I kdyby Elwynn proof prošel čistě, `2.12F4C` zůstává povinný krok před jakýmkoli eventual full-world rolloutem — Elwynn úspěch neznamená přeskočit scale hardening, jen dává informaci o tom, jak naléhavý/velký musí být.

##### 2.12F4B2 — Scoped rollout proof (Elwynn, zoneId 12)

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS (`e5f5043463`, `fb11e29b18`).** Finální F4B2 eligible census = `3540`, přesně odpovídá raw `zoneId = 12` počtu — rozdíl je `0`, žádná dodatečná non-instance/eligibility filtrace ho nezmenšila. `3540` nových `AgentRecord`ů vytvořeno jako `ObserveOnly`, identity invarianty (`AgentId == SpawnId`, no duplicates) drží, restart/idempotence ověřeno (druhý běh: `missing=0 created=0`), mimo-Elwynn populace nedotčena (`OutOfScopeCount` mechanismus).

**Priorita: až po 2.12F4B, před rozhodnutím o rozsahu 2.12F4C.**

**Vstupy (už naměřeno):** `world.creature` total `151822`; raw `zoneId = 12` (Elwynn) `3540`; `2.12F4B` full-world census `128849`, `PERFORMANCE FAIL`; současný `ai_agents` `4` řádky; reconciliation `OFF`.

Cesta:

```text
2.12F4B reconciliation engine (hotovo, runtime evidence: 128849 agentů, performance FAIL)
    ↓
TrinityCore Zone/Area data preparation
    ↓
2.12F4B scoped reconciliation: Elwynn zoneId=12
    ↓
runtime test nad skutečnou Elwynn populací
    ↓
podle výsledku rozhodnout rozsah 2.12F4C
```

**Zone/Area data preparation.** `creature.zoneId`/`areaId` existují jako sloupce ve world DB schema, ale `ObjectMgr::LoadCreatures()` je nenačítá do `CreatureData` a jsou populované jen pokud na dané DB někdy proběhl `Calculate.Creature.Zone.Area.Data = 1` (TrinityCore core config, ne AIWorld). Bez populovaných sloupců je jediná cesta k zone/area `Map::GetZoneAndAreaId()`, která vyžaduje live `Map*` (`sMapMgr->CreateBaseMap()`) a čte terrain/vmap data z disku — to by do census pipeline poprvé zavedlo přesně tu závislost (live `Map*`, per-spawn I/O), které se `CreatureSpawnCensus` dosud důsledně vyhýbal. Proto:

- scoped census čte `creature.zoneId` přímo přes vlastní úzký `WorldDatabase` SELECT (`SELECT guid FROM creature WHERE zoneId = ?`), nikdy nepočítá zone/area za běhu přes `Map::GetZoneAndAreaId()`;
- **precondition není jen "je populovaný", ale "je aktuálně přepočítaný pro současný stav `world.creature`" (P2 fix, STATIC review):** `Calculate.Creature.Zone.Area.Data = 1` dopočítá `zoneId`/`areaId` jen pro spawny, které `ObjectMgr::LoadCreatures()` právě načítá při daném běhu s daným configem - novější `world.creature` řádek přidaný PO posledním takovém běhu bude mít `zoneId = 0`, a `WHERE zoneId = 12` ho tiše vynechá. Výsledek pak není prázdný (což by bylo bezpečně nápadné), ale částečný a zdánlivě validní - to je horší než žádný výsledek. Administrativní pravidlo pro `2.12F4B2` test: bezprostředně před testem jednorázově spustit `Calculate.Creature.Zone.Area.Data = 1`, restartovat, ověřit v DB že cílové `world.creature` řádky mají nenulový `zoneId`, teprve pak spustit scoped reconciliation - a `Calculate.Creature.Zone.Area.Data` po testu zase vypnout (není to AIWorld config, nemá důvod zůstat trvale zapnutý kvůli tomuto testu).

Kroky:

- nová config hodnota `AIWorld.SpawnReconciliationZoneId` (default `0`), skládá se s existujícím `AIWorld.EnableSpawnReconciliation` - **fail-closed kombinace (P2 fix, STATIC review), ne implicitní fallback na global**:

  ```text
  EnableSpawnReconciliation = 0
      → OFF, žádná reconciliation (dnešní stav)

  EnableSpawnReconciliation = 1
  SpawnReconciliationZoneId = nenulová hodnota
      → scoped reconciliation jen nad tímto zoneId

  EnableSpawnReconciliation = 1
  SpawnReconciliationZoneId = 0 / neuvedeno
      → REFUSE: log ERROR, reconciliation se vůbec nespustí
  ```

  Důvod: než `2.12F4C` scale hardening existuje, nesmí být "zapomenout nastavit ZoneId" dost na to, aby se znovu spustila plná globální reconciliation (~128849 agentů) - přesně ten běh, který už reálně způsobil runtime zpomalení. Globální (`ZoneId = 0` jako explicitní "žádný scope") režim dostane samostatný, explicitní override (např. `AIWorld.SpawnReconciliationAllowGlobal`), zavedený až spolu s `2.12F4C` nebo `2.12F4D`, ne jako tichý default cesta dnešního přepínače;
- scoped census: eligible množina (`BuildCreatureSpawnCensus()`) se před předáním do `BuildReconciliationPlan()` protne s množinou guidů z `WHERE zoneId = ?`;
- `allKnownSpawnIds` (`BuildAllKnownCreatureSpawnIds()`) zůstává **neomezená** (žádný zone filtr) — existující `OutOfScopeCount` mechanismus (viz `2.12F4B` P2 fix `326e7a7b19`) tak správně pokryje i "existuje, ale mimo dnešní zone scope" bez jakékoli změny `BuildReconciliationPlan()`'s vlastní logiky: mimo-Elwynn agent nikdy neskončí jako `Orphaned`;
- žádná změna `ControlMode` chování — nové Elwynn agenty vznikají stejně jako dnes, `ObserveOnly`.

**Acceptance nesmí být `SELECT COUNT(*) FROM ai_agents` (P2 fix, STATIC review):** `ai_agents` legitimně obsahuje i historické 4 controlled agenty, mimo-Elwynn agenty, out-of-scope řádky a quarantined řádky (reconciliation je fyzicky nemaže) - celkový počet tedy obecně `≠` počet Elwynn agentů. Acceptance musí porovnávat identity sety, ne agregovaný počet:

```text
A = eligible world.creature se zoneId = 12 (podle stejného predikátu jako scoped census)
B = odpovídající ai_agents řádky (AgentId == SpawnId, MapId shoduje)

A - B = 0
a žádný NOVĚ vytvořený ai_agents řádek nepatří mimo A
```

Prakticky: uložit baseline `ai_agents` (nebo alespoň jeho identity set) před testem, po reconciliation spočítat deltu a tu porovnat proti `A`, ne spoléhat na jedno absolutní `COUNT(*)` číslo.

Runtime gate: se `AIWorld.EnableSpawnReconciliation = 1` a `AIWorld.SpawnReconciliationZoneId = 12` vytvoří reconciliation právě množinu `A` (viz acceptance výše) jako nové `AgentRecord`y, žádný mimo-Elwynn spawn se nedotkne, vanilla/scripted AI beze změny, a naměřený per-tick world-thread dopad nad touto menší, ale reálnou populací je vstup pro rozhodnutí o skutečném rozsahu/prioritě `2.12F4C` - `2.12F4C` samo zůstává povinné před jakýmkoli budoucím full-world rolloutem bez ohledu na výsledek Elwynn testu.

##### 2.12F4B3 — Scoped Control activation (Elwynn, zoneId 12)

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS (`32e5df3793`, `a4b093afb2`, `c1fc0792b9`).** `2.12F4B2` samo o sobě je bootstrap/identity/scope proof, ne cílový stav — nové agenty vznikají bez `ControlMode`, tedy schema default `ObserveOnly`. Cílový stav pro jednu lokaci je celá scoped populace `AIWorldControlled`, dosažená bezpečnou/opakovatelnou aktivační cestou v AIWorld kódu, ne jednorázovým ručním `UPDATE ai_agents SET control_mode=1`.

**Priorita: až po 2.12F4B2, před rozhodnutím o rozsahu 2.12F4C.**

```text
2.12F4B2 — world.creature zoneId=12 → 3540 AgentRecords (ObserveOnly)
    ↓
2.12F4B3 — explicit zone control activation
    ↓
3540 AgentRecords AIWorldControlled
    ↓
AIWorld owns those Creatures
    ↓
Perception / Needs / Decision / ActionSystem
```

Kroky:

- nová config hodnota `AIWorld.EnableZoneControlActivation` / `AIWorld.ControlZoneId`, stejná fail-closed kombinace jako `2.12F4B2` (`Enable=1` + `ZoneId<=0` → `REFUSE`, žádný unscoped/global promotion fallback);
- promotion set je přesně stejný scoped identity set, který `2.12F4B2` prokázala: `world.creature zoneId=12 ∩ persistent non-instance F4B eligibility ∩ AgentId == SpawnId ∩ existující AgentRecord` — nepromuje se prostě celé `ai_agents`;
- `AgentPersistence::PromoteControlModeBatch()` — `SetControlMode()` dělá jeden `UPDATE` + jeden readback na agenta, což se nedává do smyčky přes celou scoped populaci; batch promotion s jedním bulk readbackem, stejně jako batch creation v `2.12F4B`;
- **fail-closed whole-zone, ne partial (P2 fix, STATIC review):** pokud jediný scoped-eligible spawn nemá validní `AgentRecord` ještě (reconciliation pro danou zónu neproběhla), aktivace se vůbec nespustí (`ERROR` log, žádný `UPDATE`) — nikdy nepromuje jen ty kandidáty, které vyšly, a nenechá zbytek `ObserveOnly` beze změny;
- **atomicita samotného DB zápisu (P2 fix, STATIC review):** `PromoteControlModeBatch()` chunkuje `UPDATE` po `1000` id, ale všechny chunky jsou v jedné `CharacterDatabaseTransaction`/`DirectCommitTransaction()` — selhání jednoho chunku po commitu předchozích by jinak mohlo zanechat přesně ten mixed `Controlled`/`ObserveOnly` stav, kterému má whole-zone guard výše zabránit;
- `ActionSystem::Validate()`/`OwnsSpawn()` (`2.12F4A`) se neupravují — aktivace je nový orchestration entrypoint, který jim posílá víc agentů, ne nový safety mechanismus.

Acceptance (naměřeno):

```text
DB:
total Elwynn agents      3540
Controlled                3540
ObserveOnly                  0
AgentId != SpawnId            0
outside-zone promoted         0

runtime:
3540 agentů load Controlled
server ready
no ownership outside Elwynn
```

Runtime gate: `3540 / 3540 AIWorldControlled` pro Elwynn, scope správný (žádný mimo-Elwynn agent), identita správná (`AgentId == SpawnId`), restart/idempotence `PASS`, runtime přijatelný — toto je výrazně náročnější performance test než samotné `2.12F4B2` (tam šlo primárně o velikost registry/persistence u `ObserveOnly` populace; zde se poprvé zatíží decision/needs/perception/action cesty pro celou lokaci).

##### 2.12F4C — bounded/indexed runtime at world scale

**Stav: NOT STARTED. Priorita přehodnocena (STATIC review nad `c1fc0792b9`): `2.12F4C` je world-scale hardening (O(1) index, odstranění recurring full-registry scanů) motivovaný eventual populací kolem `128849` agentů, ne blocker pro jednu lokaci. `2.12F4B3`'s runtime gate (`3540 / 3540 AIWorldControlled`, decision/needs/perception/action cesty pod skutečnou zátěží) prakticky ověřil, že pro rozsah jedné lokace (Elwynn, `3540` agentů) `2.12F4C` blocker není. `2.12F4C` proto NENÍ další povinný krok před pokračováním práce nad Elwynn populací (např. `2.12G1` druhý coalition profil) — zůstává povinný teprve před jakýmkoli budoucím rozšířením na další lokace/eventual full-world rollout (`2.12F4D`), kde už `2.12F4B`'s vlastní full-world experiment (`census=128849`, `PERFORMANCE FAIL`) ukázal, že current architecture bez `2.12F4C` neobstojí.**

- minimálně O(1) index `(mapId, spawnId) → AgentId` místo současného lineárního `FindBySpawn()`, který dnes prochází celý `_agents` map;
- odstranit recurring full-registry discovery z world-thread cest (scheduler discovery, world-event perception, nearby perception, needs update, coalition candidate discovery) a nahradit bounded cursory / materialized indexes;
- práce za tick nesmí být úměrná celkovému počtu creature ve světě, jen počtu skutečně `AIWorldControlled`/decision-eligible agentů.

Runtime gate: recurring world-thread práce musí zůstat bounded a nesmí růst úměrně s celkovou `AgentRegistry` populací - `2.12F4B3` už ověřil Elwynn scoped populaci (`3540`, `PASS`); zbývá ověřit eventual full-world dataset (aktuálně ~`128849` persistentních non-instance agentů v tomto TDB, kde `2.12F4B`'s vlastní experiment už ukázal `PERFORMANCE FAIL` bez tohoto hardeningu) - ne jedno číslo předem odhadnuté.

##### 2.12F4D — Global bootstrap/runtime proof

**Priorita: až po scale gate (2.12F4C).**

- skutečné spuštění plné `ObserveOnly` populace (2.12F4A+B) v runtime;
- teprve po `2.12F4C` lze přepnout větší populace z `ObserveOnly` na `AIWorldControlled`;
- scripted/boss/pet/special TrinityCore AI musí mít explicitní policy (allowlist/denylist nebo ekvivalent), aby nebyl nechtěně přebit jen proto, že má `AgentId`;
- přechod z `ObserveOnly` na `AIWorldControlled` je vždy explicitní administered krok, nikdy implicitní vedlejší efekt existence `AgentRecord`.

Runtime gate: globální reconciliation proběhla, `ObserveOnly` populace neovlivnila vanilla/script chování (žádný `REACT_PASSIVE`, žádné `MoveIdle()`, žádná ztráta scripted AI), vybraná `AIWorldControlled` podmnožina funguje stejně jako dnešní 4 testovací mobky, a runtime práce zůstává bounded i s plnou populací.

---

##### Souhrn population a genericity proof

**2.12F4A–F4B3 je CLOSED pro jednu lokaci (Elwynn) — STATIC + BUILD + RUNTIME PASS, `3540 / 3540 AIWorldControlled`.** Cesta, kterou tento gate prošel:

```text
ControlMode schema + ActionSystem::Validate() as mandatory authoritative gate (2.12F4A)
    ↓
existing 4 test mobs → AIWorldControlled, default → ObserveOnly
    ↓
AgentId == TrinityCore Creature SpawnId for persistent non-instance agents (2.12F4A2)
    ↓
existing 4 test mobs migrated to spawn-aligned AgentId (incl. group/memory FKs)
    ↓
ALL non-instance world.creature SPAWNS reconciled ↔ ai_agents (2.12F4B)
    ↓
missing spawn → CREATE (ObserveOnly); deleted spawn → fail-closed/quarantine, no ghosts
    ↓
existing vanilla/scripted AI unaffected for ObserveOnly
    ↓
measured global run: 128849 agents, identity invariants hold, but world-thread performance FAIL
    ↓
scoped reconciliation over real Elwynn (zoneId=12) population only - 3540 AgentRecords, ObserveOnly (2.12F4B2)
    ↓
scoped Control activation over the same Elwynn population - 3540 / 3540 AIWorldControlled (2.12F4B3)
    ↓
decision/needs/perception/action runtime PASS over the real Elwynn location
```

`2.12F4C`/`2.12F4D` (O(1) spawn index + bounded recurring work, then global bootstrap/selective rollout) zůstávají **DEFERRED** — `2.12F4B3`'s vlastní runtime gate prakticky ověřil, že pro rozsah jedné lokace nejsou blocker; zůstávají povinné teprve před rozšířením na další lokace nebo eventual full-world rollout (kde `2.12F4B`'s vlastní `128849`-agent experiment už ukázal `PERFORMANCE FAIL` bez nich).

Na této foundation byl v `2.12G1` ověřen druhý coalition profil nad skutečnými `AIWorldControlled` spawny:

```text
REAL SECOND PROFILE (nad 2.12F4 reconciled spawny)
    ↓
SAME GENERIC FORMATION
    ↓
SAME GENERIC MAINTENANCE
    ↓
SAME GENERIC GROUP INTENT
    ↓
SAME PROJECTOR
    ↓
INDIVIDUAL ACTION
    ↓
ACTION SYSTEM
    ↓
TRINITYCORE
```

Tento genericity proof je CLOSED v 2.12G1. Následující ROAM a HUNT/combat v 2.12G2/G3 jsou také uzavřené; jejich konkrétní runtime evidence je uvedena níže.

---

#### 2.12G — Genericity proof a další group behavior

##### 2.12G1 — druhý skutečný coalition profile přes stejnou pipeline

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS.**

**Návaznost: provedeno po 2.12F4A–F4B3 nad reálnou Elwynn populací.**

Než přidáme složitější chování, musí být prakticky dokázáno, že současná architektura není WolfPack systém převlečený za generic API.

Cíl:

```text
second real profile
    ↓
existing generic formation/profile resolution
    ↓
AgentGroup + persistent ProfileId
    ↓
existing generic observations
    ↓
existing AgentGroupIntentSystem
    ↓
existing AgentGroupIntentProjector
    ↓
individual ActionRequest
    ↓
ActionSystem
    ↓
TrinityCore
```

Požadavky:

- druhý profil musí používat skutečné existující TrinityCore creature spawny;
- žádný fake AgentRecord ani synthetic physical member;
- candidate/profile selection může mít profile data, ale ne nový orchestration loop;
- žádný `RunBanditFormation()`, `RunGuardCoordination()`, `BanditIntentSystem`, `GuardMovementCoordinator` apod.;
- generic formation/maintenance/coordination scheduler musí obsloužit oba profily;
- `ProfileId` provenance musí persistovat a po restartu se správně obnovit;
- overlapping membership/arbitration pravidla zůstávají stejná;
- bounded scans/work budgets zůstávají společné;
- ActionSystem zůstává jediná execution autorita.

Výběr konkrétního druhého fixture profilu se má udělat podle reálných spawnů v dostupném testovacím světě (např. guard/bandit/caravan-like skupina), ne vytvořením ghost test entity jen kvůli testu.

**Vybraný profil (podle reálných dat):** `DefiasLoose`, `CreatureEntry = 38` (Defias Thug), `71` skutečných Elwynn (`zoneId = 12`) spawnů - vybráno z `SELECT ... FROM creature JOIN creature_template ... WHERE zoneId = 12 GROUP BY id HAVING COUNT(*) >= 3` nad reálným world DB, ne odhadem. `WolfLoose` zůstává beze změny jako první historický fixture/profile (jeho vlastní runtime proof z dob F/E/F1-F3 používal `CreatureEntry = 1423`, Stormwind Guard, protože skuteční wolf NPC v té době ještě nebyli `AIWorldControlled` - to není důvod k migraci/redesignu WolfLoose teď).

Acceptance gate:

```text
WolfLoose + second profile
→ oba přes stejný generic RunCoalitionFormation / maintenance / coordination path
→ oba vytvoří správný persistent AgentGroup
→ oba projdou generic intent/projector/action path
→ žádná species-specific orchestration větev
→ restart zachová identity/provenance bez duplicate group/action
```

**Silné kritérium:** pokud přidání druhého typu vyžaduje `Run<Species>...()` orchestration metodu, návrh se vrací k refactoru a 2.12G1 není splněno.

**Runtime evidence (potvrzeno):** WolfLoose i DefiasLoose mají reálné persistentní `AgentGroup`y (skuteční Elwynn members, ne ghost/test agenti), se správným persistentním `ProfileId`, vytvořené přes stejný generic `RunCoalitionFormation`/maintenance/coordination path a stejný intent/projector/`ActionSystem` pipeline. Identita/provenance obou skupin drží beze změny po restartu. Žádná species-specific orchestration větev (`RunWolfFormation()`, `RunDefiasFormation()` apod.) nevznikla.

```text
2.12G1 STATIC   PASS
2.12G1 BUILD    PASS
2.12G1 RUNTIME  PASS (WolfLoose + DefiasLoose, restart-stable)

2.12G1 = CLOSED
```

##### 2.12G2 — generic ROAM / territory movement intent

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS.**

Po G1 přidat druhé viditelné group chování, stále generic a deterministic.

Návrhový směr:

- rozšířit `AgentGroupIntentType` o generic roaming/territory movement intent;
- target vybrat z profile/territory policy, ne z hardcoded species logiky;
- group pouze vybere společný coordination target/constraint;
- projector vytvoří individual proposals;
- individual movement může používat deterministic per-member offset/spacing, aby všichni nesdíleli jeden bod, pokud to runtime ukáže jako nutné;
- ActionSystem validation + stale membership/profile/attempt revalidation zůstává stejná;
- Emergency/Normal/Routine individual ownership nadále preemptuje group movement;
- unloaded member nedostává physical action a nesmí být force-loadnut.

Runtime gate:

- group se skutečně přesune mezi dvěma validními body/anchory;
- členové používají individual actions;
- žádný duplicate movement spam;
- arrival/stop je stabilní;
- leave/dissolve/preemption během roam failuje bezpečně;
- oba profily z G1 mohou stejný intent použít pouze změnou profile data/policy.

**Runtime evidence (potvrzeno):** pure smoke `PASS` (Evaluate/Project, deterministic target, REGROUP > ROAM priority, fail-closed unknown intent); reálný runtime `PASS` pro WolfLoose (group `16`) i DefiasLoose (group `15`) — společný deterministický ROAM target, individual `MOVE_TO` request per member, validace přes `ActionSystem`, stabilní `ARRIVED`, žádný viditelný duplicate movement spam. Po testu byl systém vrácen do defaultního disabled stavu (`AIWorld.*GroupRoamEnabled = 0`).

**Lifecycle runtime evidence (potvrzeno):** `2.12G2R` deterministicky ověřilo higher-priority individual preemption, manual leave a manual dissolve během skutečně aktivního ROAM. Ve všech třech případech produkční ownership/lifecycle cesta zastavila původní `MOVE_TO`, vyčistila `GroupCoordinationGoalState` i engine movement generator a zachovala persistence/registry invarianty.

```text
2.12G2 STATIC        PASS
2.12G2 BUILD         PASS
2.12G2 WOLF ROAM     PASS
2.12G2 DEFIAS ROAM   PASS
2.12G2 PREEMPTION    PASS
2.12G2 LEAVE         PASS
2.12G2 DISSOLVE      PASS
2.12G2 SAFE-OFF      PASS
2.12G2 DB INTEGRITY  PASS

2.12G2 = CLOSED
```

##### 2.12G2R — ROAM lifecycle runtime closure

**Stav: CLOSED / STATIC + BUILD + RUNTIME PASS.**

Tři defaultně vypnuté one-shot hooky ověřily lifecycle a ownership během skutečně aktivního ROAM:

###### Higher-priority individual preemption

- agent `80237`, group `36`;
- hook počkal na skutečně aktivní ROAM;
- produkční `GET_FOOD` goal preemptoval group coordination;
- původní ROAM skončil jako `COORDINATION_PREEMPTED_BY_GOAL`;
- zaznamenaný preemptor byl skutečný individual `GET_FOOD`;
- coordination state i engine movement generator byly úplně vyčištěny.

###### Manual leave during active ROAM

- agent `80209`, group `32`;
- hook počkal na skutečně aktivní ROAM;
- zavolal produkční `RequestLeaveGroupWithPolicy(..., Manual)`;
- aktivní movement skončil jako `COORDINATION_STOPPED_BY_LIFECYCLE`;
- coordination state i engine movement generator byly vyčištěny;
- persistence potvrdila odstranění membership;
- group `32` zůstala konzistentní se členy `80210, 80224, 80226`.

###### Manual dissolve during active ROAM

- group `36`, členové `80237, 80256, 80257`;
- hook počkal, až všichni tři členové měli skutečně aktivní ROAM;
- zavolal produkční `RequestDissolveGroupWithPolicy(..., Manual)`;
- všechny tři movement akce skončily jako `COORDINATION_STOPPED_BY_LIFECYCLE`;
- coordination state i engine movement generátory byly vyčištěny;
- persistence potvrdila úplné odstranění group `36` i jejích membership edges.

###### Safety a databázová postcondition

- žádný fatal, assert, segmentation fault, DB failure ani unknown config;
- group `36` po dissolve neexistuje;
- nezůstalo žádné osiřelé membership;
- group `32` zůstala konzistentní;
- všechny testovací hooky byly po proofu vráceny na `0`.

```text
2.12G2R PREEMPTION    PASS
2.12G2R LEAVE         PASS
2.12G2R DISSOLVE      PASS
2.12G2R PERSISTENCE   PASS
2.12G2R DB INTEGRITY  PASS
2.12G2R SAFE-OFF      PASS

2.12G2R = CLOSED
```

Po proofu musí zůstat:

```ini
AIWorld.TestPreemptOnActiveRoamAgentId = 0
AIWorld.TestLeaveOnActiveRoamAgentId = 0
AIWorld.TestDissolveOnActiveRoamGroupId = 0
```

##### 2.12G3 — generic HUNT / coordinated combat preparation

**Stav: CLOSED — G3A, G3B, G3C1 a G3C2 CLOSED. G3D (real group combat) je live-confirmed PASS: skuteční group members dokončili HUNT approach → ATTACK → melee damage (`DoMeleeAttackIfReady()`) → prchající target skutečně pronásledovaný (`MoveChase()`) → `TARGET_DEFEATED` pro oba členy skupiny, phantom-FLEE_DANGER se u HUNT membera neaktivoval, žádný `NO_FLEE_SOURCE`/`COORDINATION_PREEMPTED_BY_GOAL`/fatal/pád. `G3 lifecycle closure` (Approaching/AtTarget/Engaging bezpečně obsloužené přes PREEMPTED_BY_GOAL, STOPPED_BY_LIFECYCLE, STOPPED_BY_MEMBERSHIP_AMBIGUITY, STOPPED_BY_TARGET_INVALID, PREEMPTED_BY_REGROUP a TARGET_DEFEATED) je STATIC repaired a cumulatively BUILD-verified všemi navazujícími plnými 2.13 buildy, viz `2.12G3 lifecycle closure` níže pro přesný rozsah tohoto tvrzení.**

Až po stabilním G1/G2 (tedy až po `2.12G2R` closure výše) — první commit ještě neútočí, jen navrhuje kontrakt.

Nejdřív navrhnout explicitní server-owned combat proposal/action contract. Group nesmí přímo volat combat API nad více Creatures.

```text
Group HuntIntent
    ↓
explicit target identity/provenance
    ↓
per-member HuntProposal
    ↓
ActionRequest
    ↓
target/membership/map/range revalidation
    ↓
TrinityCore execution
```

Požadavky:

- target selection vychází z generic observations + profile policy;
- target identity/provenance je explicitní a stale target failuje zavřeně;
- group intent se decomposuje na per-member combat/approach proposals;
- každý member znovu validuje alive/materialized/map/range/target/membership/action ownership;
- žádný force-load targetu ani membera;
- individual emergency/vanilla combat safety má přednost;
- ActionSystem/TrinityCore zůstává jediná fyzická execution cesta;
- duplicate/replayed attack proposals jsou potlačené;
- leave/dissolve/target death/unload během coordination bezpečně ruší stale group-owned intent.

Runtime gate má nejdřív dokazovat correctness a ownership, ne „chytré smečkové taktiky“.

**Doporučené rozdělení (ne nutně samostatné milníky, ale samostatné commity/review kroky):**

- **G3A** — pure DTO a target provenance contract (`HuntIntent`/`HuntProposal` shape, žádná orchestrace) — **CLOSED, viz `2.12G3A` níže**;
- **G3B** — intent/projector a pure smoke testy (stejná disciplína jako `2.12F1`/`2.12F2`) — **CLOSED, viz `2.12G3B` níže**;
- **G3C1** — autoritativní validační kontrakt (`GoalType::Hunt`, `ActionTargetRef`, target facts v `ActionValidationContext`, `ActionSystem::ValidateHuntTarget()`) — **CLOSED, viz `2.12G3C1` níže**;
- **G3C2** — produkční observation/dispatch wiring, ownership/preemption, lifecycle stop na invalid target — **CLOSED, viz `2.12G3C2` níže**;
- **G3D** — runtime proof, ve skutečnosti proběhlo v těchto krocích (ne přesně podle původního G3D1-G3D4 plánu níže, který ještě počítal s tím, že žádný G3D krok nepřidá `ActionType::Attack`):
  - **G3D1** — neinvazivní live approach proof: skutečná `CreatureSeen` memory → produkční `HuntIntent`/`HuntProposal` → live revalidace → `ActionSystem` `ALLOWED` → skutečný HUNT `MoveTo` generator → přesně potvrzená ownership identity, přes read-only `AIWorld.TestObserveActiveHuntAgentId` hook — **POSITIVE LIVE APPROACH PROOF: PASS, viz `2.12G3D1` níže**;
  - **fix(ai-world): retain HUNT ownership after approach arrival** — post-ARRIVED redispatch smyčka odhalená G3D1 opravena, `HuntPhase::AtTarget` retention zavedena — **CLOSED**;
  - **G3D — produkční skupinový HUNT combat** (`ActionType::Attack`, `ValidateAttack()`, `ExecuteAttack()`/`StopAttack()`, `HuntPhase::Engaging`, `AIWorldCreatureAI::UpdateAI()` volá `DoMeleeAttackIfReady()`) — po několika STATIC review kolech (damage execution, targeted combat/threat reference cleanup, live range/LOS gate na první ATTACK, phantom-FLEE_DANGER root cause i atomic-transition fix, stale chase generator po smrti cíle) — **live-confirmed PASS: oba group members ATTACK STARTED → skutečné melee poškození → prchající target skutečně pronásledovaný → `TARGET_DEFEATED` pro oba (`durationMs=9999`), žádný `NO_FLEE_SOURCE`, žádná fantomová preempce**;
  - **G3 lifecycle closure** — bezpečné chování pro Approaching/AtTarget/Engaging napříč všemi šesti ukončujícími událostmi (`PREEMPTED_BY_GOAL` teď zahrnuje i `HuntPhase::AtTarget`, dříve mezera protože blok vyžadoval `ActiveActionState`; `STOPPED_BY_LIFECYCLE`, `STOPPED_BY_MEMBERSHIP_AMBIGUITY`, `STOPPED_BY_TARGET_INVALID` a `PREEMPTED_BY_REGROUP` už byly generic přes `StopInFlightGroupCoordination()`/`ReconcileActiveHuntTargetsForGroup()`; `TARGET_DEFEATED` - jen během `Engaging`, jinak `STOPPED_BY_TARGET_INVALID` - přes `HandleActionCompletion()`) — **CLOSED / STATIC repaired + cumulatively BUILD-verified; rozsah evidence viz 2.12G3 lifecycle closure níže**.

Původní G3D2/G3D3/G3D4 dělení (`GET_FOOD` preemption zvlášť/`StoppedByTargetInvalid` zvlášť/`PreemptedByRegroup` zvlášť) bylo nahrazeno jedním `G3 lifecycle closure` commitem, protože produkční combat implementace mezitím tyto lifecycle cesty už sdílela s `StopInFlightGroupCoordination()` - žádný z nich nepotřeboval samostatný milník.

##### 2.12G3A — HUNT DTO/provenance contract

**Stav: CLOSED / STATIC + BUILD PASS.**

Pure value-only DTO vrstva pro group HUNT, ve stejném duchu jako `AgentGroupIntent`/`GroupMemberActionProposal` pro `2.12F1`/`2.12F2`:

- `HuntTargetProvenance` — explicitní identita cíle (`ObjectGuid TargetGuid`, `TargetEntry`) a honest snapshot (`MapId`/`X`/`Y`/`Z`/`Alive`/`ObservedAtMs`), nikdy live pointer;
- `HuntIntent` — group-level fakt s vlastní `StartedAtMs` attempt identitou, záměrně oddělenou od `Target.ObservedAtMs` (dvě různé stale-response otázky);
- `HuntProposal` — per-member decomposition output, `Target` nesený jako celý embedded `HuntTargetProvenance`, nikdy flattened.

Kontrakt explicitně říká: `G3A`-`G3D` HUNT je omezen na persistent non-instance/base-world targety; instance-aware target identita je mimo scope; target mimo group's base-world map musí failovat zavřeně.

Žádný system/projector/orchestrace, žádné ActionSystem, žádný combat, žádná species-specific větev.

##### 2.12G3B — pure HUNT intent/projector

**Stav: CLOSED / STATIC + BUILD + PURE SMOKE PASS.**

Pure runtime smoke potvrdil profile-driven target eligibility, GUID/entry provenance, freshness, map/LOS/range validaci, deterministický nearest-target výběr, fail-closed konfliktní observations a per-member projection bez ActionSystem nebo combat execution.

```text
2.12G3B STATIC       PASS
2.12G3B BUILD        PASS
2.12G3B INTENT       PASS
2.12G3B PROJECTOR    PASS
2.12G3B DETERMINISM  PASS
2.12G3B FAIL-CLOSED  PASS
2.12G3B ERROR CHECK  PASS

2.12G3B = CLOSED
```

Přidáno: `AgentGroupCoordinationProfile.HuntEnabled`/`HuntTargetCreatureEntry`/`HuntAcquisitionRadius`/`HuntObservationMaxAgeMs` (generic profil, žádné WolfLoose/DefiasLoose větvení); `HuntTargetObservation` (per-member world-thread sighting, pure value); `HuntIntentSystem::Evaluate()` (fail-closed profil/observer/target checks, numerická validita včetně NaN/Inf, GUID/entry binding, konfliktní-observation detekce s fail-closed exclusion, deterministický nearest-target výběr nezávislý na pořadí vstupu); `HuntIntentProjector::Project()` (per-member decomposition, bez re-selection targetu, bez membership/registry/priority/ActionSystem/combat).

`AIWorld.TestHuntIntent` zůstává default off (`0`) — pouze manual verification aid, ne feature.

Po proofu musí zůstat:

```ini
AIWorld.TestHuntIntent = 0
```

Na tento pure intent/projector krok navázal uzavřený `2.12G3C1` validační kontrakt pro HUNT approach. Samotný G3B combat execution ani `AttackStart` nepřidával; reálný combat je doložen v 2.12G3D.

##### 2.12G3C1 — HUNT approach validation contract

**Stav: CLOSED / STATIC + BUILD + RUNTIME GATE PASS.**

```text
STATIC                              PASS
BUILD/start serveru                 PASS
valid HUNT approach                 PASS
fail-closed případy                 PASS
GUID/entry binding                  PASS
REGROUP kompatibilita               PASS
fatal/assert/DB/config chyby        0

2.12G3C1 = CLOSED
```

Autoritativní validační kontrakt, který musí splnit každý budoucí HUNT approach `MOVE_TO`, ještě bez jakéhokoliv produkčního dispatch nebo fyzického pohybu:

```text
HuntProposal
    ↓
live facts converted to value context
    ↓
ActionRequest(MOVE_TO, SourceGoal=HUNT, target identity)
    ↓
ActionSystem authoritative validation
    ↓
ALLOWED / REJECTED
```

- `GoalType::Hunt` — stejná nejnižší group-coordination priorita jako Regroup/Roam (Emergency ActiveGoal > Normal ActiveGoal > RoutineGoal > Regroup/Roam/Hunt); záměrně žádný nový `AgentGroupIntentType::Hunt` (HUNT už má vlastní `HuntIntent`, viz `2.12G3A`);
- `ActionTargetRef` (`Guid`/`Entry`) + `ActionRequest::Target` — co request tvrdí o svém cíli, pure value, nikdy live pointer;
- `ActionValidationContext` rozšířen o autoritativní, fail-closed target facts (`TargetResolved`/`TargetAlive`/`TargetAttackable`/`TargetGuid`/`TargetEntry`/`TargetMapId`/`TargetX`/`Y`/`Z`) — reálně zjištěné volajícím na world threadu, nikdy tvrzení requestu;
- osm nových `ActionRejectReason` hodnot (`TargetMissing`/`TargetNotResolved`/`TargetDead`/`TargetNotAttackable`/`TargetIdentityMismatch`/`TargetEntryMismatch`/`TargetMapMismatch`/`TargetPositionMismatch`), každá s vlastním `ToString()`;
- `ActionSystem::ValidateHuntTarget()` — kromě běžné bounded MoveTo validace (sdílený `MaxCoordinationMoveToRangeYards` s Regroup/Roam) navíc: request nese reálný target claim; GUID musí být prokazatelně creature a jeho embedded entry musí odpovídat deklarovanému Entry (STATIC review fix — self-consistent, ale neplatná dvojice jinak projde); request GUID/Entry se musí shodovat s autoritativním context GUID/Entry; target je na mapě actora; destination map odpovídá target mapě; destination přesně odpovídá aktuální target pozici; všechny target souřadnice jsou finite. Request nikdy neprojde jen na základě geometricky validní destination;
- `GroupCoordinationGoal` rozšířen o `TargetGuid`/`TargetEntry`/`TargetObservedAtMs` (u Regroup/Roam defaultně prázdné) — HUNT attempt identity kontrakt pro budoucí `2.12G3C2` lifecycle gate, zatím nezapojený.

Po proofu musí zůstat:

```ini
AIWorld.TestHuntActionValidation = 0
```

Další krok je `2.12G3C2`: produkční sběr live target facts (ze `_shortTermMemory`), dispatch HUNT `MOVE_TO`, ownership/preemption a lifecycle zastavení při zneplatnění cíle. Stále bez `ActionType::Attack`, `AttackStart`, `CombatStart`, threat mutation, spell cast, damage nebo species-specific `RunWolfHunt()`/`RunDefiasHunt()`.

##### 2.12G3C2 — production HUNT observation, dispatch, ownership, preemption

**Stav: CLOSED / STATIC + BUILD + START PASS.**

```text
commit: a03a330

2.12G3C2 STATIC                                    PASS
2.12G3C2 BUILD                                      PASS
2.12G3C2 SERVER START                               PASS
2.12G3C2 DEFAULT-OFF CONFIG                         PASS
2.12G3C2 fatal/assert/segmentation/DB/config errors 0

2.12G3C2 = CLOSED
```

Build proběhl na revision `a03a33063b8b71d6784fc6b7629068f822795882`; worldserver je Up a aktivně zpracovává AI požadavky; Wolf i Defias načetli nové HUNT parametry; `huntEnabled=false` a target entry `0` potvrzují bezpečný default; žádný fatal, assert, segmentation, DB ani config error.

Skutečný live HUNT movement (produkční approach, ownership identity nad skutečně běžícím MoveTo generátorem) zatím nebyl prokázán - toto CLOSED se vztahuje pouze na STATIC/BUILD/START/default-off gate. Runtime proof samotného HUNT approach patří do `2.12G3D1`.

Přidáno:

- `CollectHuntTargetObservations()` — produkční sběr z `_shortTermMemory` (aktivní `CreatureSeen` záznamy), žádný nový spatial scan; provenance zachovává `memory.Owner`, ne loop proměnnou;
- `RunCoalitionCoordination()` priorita REGROUP > in-flight HUNT > nově vybraný HUNT > ROAM — REGROUP nejdřív aktivně zastaví běžící HUNT stejné skupiny (`CoordinationStopReason::PreemptedByRegroup`) a teprve potom dispatchuje;
- `ResolveHuntIntentForGroup()`/`HasInFlightHuntAttempt()` — in-flight identity rekonstruovaná výhradně z členů (žádný samostatný manager pin), ambiguous stav mezi členy blokuje nový dispatch; pinned target znovu prochází celým `HuntIntentSystem::Evaluate()` (staleness, observer validita, LOS/distance, entry eligibility, conflicting duplicates), nikoli zkráceným výběrem;
- `DispatchHuntProposal()` — plný fail-closed řetězec (ownership, membership, profil, materialized/alive, žádný jiný goal/action/coordination state, no cross-group overlap, live re-resolve targetu přesně podle GUID bez force-load, entry/map honesty, not-self, attackable, acquisition + coordination range, LOS, finite kontrola PŘED distance/LOS/pathing, navigable path); MOVE_TO destination je vždy aktuální live pozice targetu;
- `ReconcileActiveHuntTargetsForGroup()` — re-validace každého in-flight HUNT targetu vůči live realitě, `CoordinationStopReason::StoppedByTargetInvalid`;
- `ActiveAction.Target` a `CoordinationStopEvent.TargetGuid`/`TargetEntry` — úplná target identity ownershipu, zachycená PŘED resetem `GroupCoordinationGoalState`; HUNT completion navíc ověřuje shodu target identity, ne jen goal/timestamp;
- `CountCoordinationEnabledMemberships()`/`IsCoordinationSourceGoal()` rozšířené o HUNT — preemption a overlap arbitration zděděné automaticky, žádná nová HUNT-specific logika.

Po proofu musí zůstat:

```ini
AIWorld.WolfGroupHuntEnabled = 0
AIWorld.WolfGroupHuntTargetCreatureEntry = 0
AIWorld.DefiasGroupHuntEnabled = 0
AIWorld.DefiasGroupHuntTargetCreatureEntry = 0
```

Další krok byl `2.12G3D1`: neinvazivní live approach proof - target-aware ownership identity nad skutečně běžícím HUNT `MoveTo`, přes read-only `AIWorld.TestObserveActiveHuntAgentId` hook. Bez útoku ani `AttackStart()` - to přišlo až v `2.12G3D`'s vlastní produkční combat implementaci níže.

##### 2.12G3D1 — live approach runtime proof

**Stav: POSITIVE LIVE APPROACH PROOF: PASS.**

```text
Observation       PASS
Intent selection  PASS
Projection        PASS
Validation        ALLOWED
MOVE_TO start     PASS
Ownership proof   PASS
Engine generator  RUNNING
Arrival           PASS
Fatal/errors      0

2.12G3D1 = POSITIVE LIVE APPROACH PROOF: PASS
```

Skutečný, produkčně dispatchovaný HUNT approach proběhl end to end: skutečná `CreatureSeen` memory → produkční `HuntIntentSystem::Evaluate()` → `HuntIntentProjector::Project()` → `DispatchHuntProposal()`'s vlastní live revalidace → `ActionSystem::Validate()` `ALLOWED` → skutečný engine `MoveTo` generátor → přesně potvrzená ownership identity (`AIWorld.TestObserveActiveHuntAgentId`, read-only, nic nedispatchoval ani nezastavoval). Deterministický nearest-target výběr byl potvrzen i živě: skupina správně zvolila bližší target `214012` na `13.3yd` místo vzdálenějšího `214017` na `33.1yd`. Žádný fatal, assert ani jiná chyba.

**Zjištěný P2 problém (blokuje pokračování na G3D2):** log odhalil, že po `ARRIVED` se stejný HUNT znovu dispatchuje na vzdálenost `0.0yd` a spustí druhý `MoveTo` - `HandleActionCompletion()` dosud uvolňoval `GroupCoordinationGoalState` i pro HUNT stejně jako pro Regroup/Roam, takže další `RunCoalitionCoordination()` pass znovu vybral stále platný cíl a znovu dispatchoval. Oprava (`fix(ai-world): retain HUNT ownership after approach arrival`) zachovává po úspěšném `ARRIVED` stejnou `(group, target, StartedAtMs)` identitu, takže `DispatchHuntProposal()`'s vlastní `GroupCoordinationGoalState` kontrola (`COORDINATION_GOAL`) další dispatch odmítne - target-invalid, leave, dissolve a goal preemption zůstávají funkční beze změny.

Po proofu musí zůstat:

```ini
AIWorld.TestObserveActiveHuntAgentId = 0

AIWorld.WolfGroupHuntEnabled = 0
AIWorld.WolfGroupHuntTargetCreatureEntry = 0

AIWorld.DefiasGroupHuntEnabled = 0
AIWorld.DefiasGroupHuntTargetCreatureEntry = 0
```

Další krok byl `fix(ai-world): retain HUNT ownership after approach arrival` (opravil opakovaný nulový dispatch po ARRIVED), teprve potom skutečná produkční combat implementace níže - ne přesně podle původního `G3D2`/`G3D3`/`G3D4` dělení, které ještě počítalo s tím, že žádný G3D krok nepřidá útok.

##### 2.12G3D — produkční skupinový HUNT combat

**Stav: live-confirmed PASS.**

```text
HUNT AtTarget -> ATTACK request -> authoritative live validation -> AttackStart -> melee damage -> shared pinned target -> target dies -> HUNT ownership releases
```

Přidáno (po několika STATIC review kolech): `ActionType::Attack`, `HuntPhase::Engaging`, `ActionCompletionReason::TargetDefeated`; `ActionSystem::ValidateAttack()` (target GUID/entry binding, live range/LOS gate na první ATTACK - nikdy jen stará `HuntPhase::AtTarget`, actor-engaged-with-jiný-target reject, idempotentní stejný target); `ActionExecutor::ExecuteAttack()`/`StopAttack()` (`Unit::Attack()` + `MoveChase()` přímo, nikdy přes potlačený `AI()->AttackStart()`; cílený `AttackStop()` + nezávislé `CombatReference::EndCombat()` + nezávislé odstranění vlastního `ChaseMovementGenerator` přes jeho vlastní `GetTarget()`, nikdy přes `GetVictim()`); `AIWorldCreatureAI::UpdateAI()` volá `DoMeleeAttackIfReady()` (jediná autorizovaná per-tick engine práce, žádný nový target select); `AIWorldMgr::DispatchHuntAttack()`/`ReconcileActiveHuntTargetsForGroup()`'s `TargetDefeated` handling; oprava phantom `FLEE_DANGER` (voluntary owned HUNT combat už sám nenastaví `SafetyPressure=1.0`, `GoalSystem::GenerateCandidates()` nikdy nevytvoří neproveditelný `FleeDanger` candidate, atomická FLEE feasibility gate před commitem goal transition, gate scoped pouze na existující fyzickou akci aby `ObserveOnly` zůstal nedotčený).

Reálný skupinový boj (produkční log, ne syntetický): oba group members pokračovali v útoku, prchající target skutečně pronásledovaný, boj trval ~10s (ne jeden úder), oba `ATTACK` skončily `status=SUCCEEDED reason=TARGET_DEFEATED durationMs=9999`, `memorySafety=0.8384` u HUNT membera phantom FLEE nevyvolal, `FLEE_DANGER` patřil pouze napadenému mobovi, žádný `NO_FLEE_SOURCE`/`COORDINATION_PREEMPTED_BY_GOAL`/fatal/pád. Po zabití prvního cíle byl nalezen a opraven navazující P2 (stale `ChaseMovementGenerator` po smrti targetu blokoval další HUNT dispatch přes `ActorMovementBusy`).

Poslední otevřený kus je `G3 lifecycle closure` níže.

##### 2.12G3 lifecycle closure

**Stav: CLOSED — STATIC review PASS (P1=0/P2=0/P3=2, oba P3 opravené níže), cumulatively BUILD-verified: tento lifecycle repair commit (`b5bda315...`) předchází všechny 2.13 commity a každý pozdější plný 2.13 build (A1 přes C5) tedy kompiloval i tento kód beze změny. Není to samostatné, izolované re-verifikování všech šesti terminačních variant zvlášť — pokud je potřeba přísnější milestone-specific evidence, je nutné je znovu runtime přehrát samostatně.**

Sjednocuje bezpečné chování napříč `HuntPhase::Approaching`, `AtTarget` a `Engaging` pro všech šest ukončujících událostí:

| Událost | Výsledek |
| --- | --- |
| vyšší Active/Routine goal | `PREEMPTED_BY_GOAL` |
| member opustí group / dissolve | `STOPPED_BY_LIFECYCLE` |
| vícenásobné membership | `STOPPED_BY_MEMBERSHIP_AMBIGUITY` |
| target unload/despawn/map/attackability invalid | `STOPPED_BY_TARGET_INVALID` |
| REGROUP začne během HUNT | `PREEMPTED_BY_REGROUP` |
| target zemře BĚHEM `HuntPhase::Engaging` | `TARGET_DEFEATED` |
| target zemře PŘED `Engaging` (Approaching/AtTarget) | `STOPPED_BY_TARGET_INVALID`, nikoli `TARGET_DEFEATED` - member ho nikdy nebojoval |

Pět z šesti už bylo generic přes sdílené `StopInFlightGroupCoordination()`/`ReconcileActiveHuntTargetsForGroup()`. Jediná skutečná mezera: `UpdateNeeds()`'s vlastní preemption blok vyžadoval `record->ActiveActionState`, který `HuntPhase::AtTarget` (dwelling bez akce) nikdy nemá - member sedící `AtTarget` s nově aktivovaným individuálním goalem tedy nebyl touto větví vůbec zachycen. Oprava přesouvá podmínku na `record->GroupCoordinationGoalState` (pokrývá Approaching/AtTarget/Engaging jednotně) a engine touch (přesně cílený `StopAttack()`/`StopMoveTo()`, `LastCoordinationStop` s group/timestamp/GUID/entry) zůstává gated na stejnou `ownsAction` exact-match disciplínu jako `StopInFlightGroupCoordination()` už má - nikdy nezastaví cizí action, victim ani chase.

STATIC review (P3 x2, oba opravené): logika byla extrahována do vlastní `AIWorldMgr::PreemptInFlightGroupCoordination()` metody (self-contained, resolvuje si vlastní `Creature*` stejně jako `StopInFlightGroupCoordination()`) - `UpdateNeeds()` ji teď jen volá, žádná změna produkčního chování. Dva nové pure value-state smoke testy pokrývají přesně tu novou větev (AtTarget + individual goal aktivace, a AtTarget s unrelated action) - žádný další reálný combat test.

Žádné nové attack typy, spelly, threat manipulace, role/leadership ani další target-selection logika.

##### 2.12G4 — roles / leader pouze pokud je skutečně potřeba

**Stav: NOT NEEDED YET.** `2.12G2`'s dosavadní ROAM runtime evidence neprokázala žádnou potřebu leadera/role — shared deterministic target + generic per-member proposal stačí. G4 se nezačíná preventivně jen proto, že G2/G3 existují.

Leadership se nepřidává preventivně.

Přidat jej jen tehdy, pokud G2/G3 ukáže konkrétní potřebu, kterou nelze čistě vyřešit současným generic group state + deterministic policy.

Pokud vznikne:

- role je social metadata nad `AgentId`, ne nový physical AgentType;
- leader je member reference s explicitní stale handling;
- leader unload/death/leave nesmí rozbít group lifecycle;
- deterministic replacement/election policy;
- role/leader nikdy neobchází per-member ActionSystem ownership.

---

### 2.13 — local LLM dynamic task / player interaction vertical slice

**Stav: CLOSED — A1/A2/A3A/A3B/B/C1/C2/C3/C4/C5/C6/D všechny CLOSED. Restart/reconnect semantics a negative failure-mode agregace (2.13D) runtime otestovány a potvrzeny.**

Cíl není dát LLM kontrolu nad světem. Cíl je dokázat bezpečný řetězec:

```text
WORLD problem/event
    ↓
NPC perception + memory + goal
    ↓
sanitized QuestContext DTO
    ↓ async
local ai-server / LLM
    ↓
structured QuestProposal
    ↓
authoritative server validation
    ↓
player-facing offer/task
    ↓
player action validated by TrinityCore
    ↓
WorldEvent
    ↓
NPC memory/goal/world-state feedback
```

#### 2.13A — skutečný local-model request

- skutečný lokální model/backend za existujícím `ai-server` boundary;
- async timeout/fallback;
- strict structured output;
- correlation + snapshot/provenance;
- sanitizovaný minimální kontext;
- žádný live pointer nebo arbitrary world serialization.

##### 2.13A1 — dynamic-task protocol / DTO contract

**Stav: CLOSED — STATIC + BUILD + UNIT PASS (`4bd35df3c6`, `e168ea1814`).**

```text
BUILD=PASS
UNIT=PASS (37/37)
SMOKE=NOT APPLICABLE
RUNTIME=NOT APPLICABLE
ERROR_SCAN=PASS
```

`SMOKE`/`RUNTIME` are `NOT APPLICABLE`: A1 is a pure value-only DTO contract with no world-thread integration, no startup hook and no live agent/combat path to exercise — the same class of change the existing AIWorld smoke-test convention reserves runtime proof for, not a reason to skip the gate.

Pure value-only kontrakt pro budoucí `/dynamic-task` boundary:

- samostatný `DynamicTaskProtocolVersion`, nezávislý na `/decision` `ProtocolVersion`;
- minimální sanitizovaný `QuestContext`, bez `ObjectGuid`, `SpawnId`, live pointerů nebo arbitrary world serialization;
- request-local `QuestTargetCandidate::Token` místo model-visible engine identity;
- interní `QuestRequestProvenance` drží actor runtime identity, source-event provenance a token → authoritative target binding, ale nikdy se neserializuje;
- untrusted `QuestProposalDraft` je čistě deklarativní (`objective`, target token, count/range/expiry/reward, text), bez execution payloadu;
- `QuestContractLimits` bounduje wire contract explicitně: pevné maximum pro `RelevantEvents`/`CandidateTargets`/text délky a request-scoped `QuestProposalLimits` (max count/range/expiry/reward), které `QuestContext` předává modelu; 2.13B tato pole i tak autoritativně znovu validuje;
- žádný HTTP transport, local model, player-facing quest ani world mutation v A1.

Na A1 navázal uzavřený `2.13A2`: local-model provider za existujícím `ai-server` boundary a strict schema parsing pro tento kontrakt.

##### 2.13A2 — local-model provider v `ai-server`

**Stav: CLOSED — STATIC + DOCKER UNIT + HEALTH + WORLD REGRESSION PASS (`6cfa20ad9b`, `b9070b72e0`, `7252a24c10`).**

```text
REVISION=7252a24c10a0c3d2800cf00f05d8e7554616fc74
STATIC=PASS
AI_SERVER_DOCKER_UNIT=PASS (58/58)
AI_SERVER_HEALTH=PASS
WORLD_REGRESSION=PASS
ERROR_SCAN=PASS
```

Review prošel dvěma follow-up koly (`b9070b72e0`: field-level `strict=True`, skutečně bounded streaming request/response read, uint32/uint64 upper bounds, non-string `message.content` handling; `7252a24c10`: dokončení `strict=True` na `QuestRelevantEvent.importance`/`relevance`) — finální diff STATIC PASS, poté oficiální `docker compose ... run --rm ai-server python -m unittest ...` gate z `README_DEV.md` PASS.

Worldserver v tomto kroku vůbec není měněný — `AIClient`/`AIWorldMgr` zůstávají beze změny, zapojení patří až do `2.13A3`.

Python zrcadlo A1 kontraktu a jeden best-effort call na OpenAI-compatible backend:

- `docker/ai/app/dynamic_task.py`: pydantic modely 1:1 k C++ DTO (`DynamicTaskRequest`/`QuestContext`/`QuestProblemContext`/`QuestRelevantEvent`/`QuestTargetCandidate`/`QuestProposalLimits`/`QuestProposalDraft`/`DynamicTaskResponse`), všechny s `extra="forbid"` a `allow_inf_nan=False`; `QUEST_CONTRACT_MAX_*` konstanty odpovídají C++ `QuestContractLimits.h` (RelevantEvents ≤ 8, CandidateTargets ≤ 16, DisplayName ≤ 64, Title ≤ 80, Description ≤ 400) a jsou vynucené přímo na modelech (`Field(max_length=...)`), ne jen zdokumentované; `QuestObjectiveType` zatím povoluje jen `KILL_CREATURE`; `validate_draft_against_context()` je samostatná, request-specific kontrola (`target_token` musí být v `candidate_targets`, `required_count`/`max_range_yards`/`expiry_ms`/`reward_money_copper` musí být uvnitř `QuestContext.limits`).
- `docker/ai/app/model_provider.py`: `OpenAICompatibleTaskProvider` — jeden HTTP request (`httpx.AsyncClient`), explicitní timeout, žádný retry, kontrola HTTP statusu i velikosti odpovědi před parsováním, JSON parse → `QuestProposalDraft` validace; žádné logování celého promptu ani API key (žádná API-key proměnná zatím neexistuje — typické lokální OpenAI-compatible backendy ji nevyžadují). Konfigurace přes env (`AI_TASK_MODEL_ENABLED` default `0`, `AI_TASK_MODEL_URL`, `AI_TASK_MODEL_NAME`, `AI_TASK_MODEL_TIMEOUT_MS`, `AI_TASK_MODEL_MAX_REQUEST_BYTES`, `AI_TASK_MODEL_MAX_RESPONSE_BYTES`, `AI_TASK_MODEL_MAX_TOKENS`).
- `docker/ai/app/main.py`: nový `POST /dynamic-task` — pořadí kontrol request size → protocol version → strict request schema → feature enabled → provider configured → provider call → strict draft schema → request-specific limits → response; `request_id`/`agent_id`/`snapshot_sequence` v odpovědi vždy z původního requestu, nikdy z modelu (stejný trust pattern jako `/decision`). Fail-closed: disabled/not configured → 503, timeout → 504, non-2xx/malformed/oversized/schema-invalid/policy-invalid → 502, oversized request → 413, protocol mismatch → 400 — nikdy fallback quest. `GET /health` nově vrací `task_model_enabled`/`task_model_configured` (statická konfigurace, nikdy živě ověřená `model_ready`).
- `docker/ai/tests/test_dynamic_task.py`: fake/mock provider přes FastAPI `dependency_overrides`, `httpx.MockTransport` pro reálný provider request/parse/validate pipeline (žádný skutečný LLM); pokrývá celou minimální sadu z handoffu (disabled/not-called, valid draft, protocol mismatch, extra field, timeout, non-2xx, malformed JSON, unknown proposal field, invalid objective, NaN/Infinity, neznámý `target_token`, překročení `required_count`/`range`/`expiry`/`reward` limitů, oversized response) plus review-vyžádané doplňky (title/description too long, over-max kolekce, `/health` bez `model_ready`, string→number coercion na každém int/float poli, uint32/uint64 overflow, non-string `message.content`) — 58 testů, 58 passed.
- `docker/ai/Dockerfile`: přidán `httpx`, `tests/` se kopíruje do image; `compose.yml`: `ai-server.environment` s výchozím `AI_TASK_MODEL_ENABLED=0` a zbylými proměnnými; žádná model service není do Compose přidána automaticky. `README_DEV.md`: nový `docker compose ... run --rm ai-server python -m unittest discover -s tests -p 'test_*.py' -v` příkaz.

Co ověřeno a jak: implementace nejdřív ověřena `python -m unittest discover` proti stejným (nepinovaným) balíčkům, jaké instaluje `Dockerfile`, v izolovaném virtualenv mimo Docker (58/58), poté oficiální `docker compose -f compose.yml -f compose.dev.yml run --rm ai-server python -m unittest discover -s tests -p 'test_*.py' -v` gate z `README_DEV.md` — **AI_SERVER_DOCKER_UNIT=PASS (58/58)**. `AI_SERVER_HEALTH=PASS` (`GET /health` vrací `task_model_enabled`/`task_model_configured`, default `false`/`false`, žádné `model_ready`). `WORLD_REGRESSION=PASS` — `/decision` beze změny chování, worldserver C++ nedotčen.

Runtime gate samotného A2 nevyžadoval worldserver `/dynamic-task` call — jeho odesílání doplnilo až navazující `2.13A3`. A2 runtime proof je samotný `ai-server`: fake/mock provider testy PASS, disabled-by-default PASS, `/health` PASS; malformed/timeout/outage PASS; worldserver chování nezměněné.

##### 2.13A3A — dynamic task async transport

**Stav: CLOSED — STATIC + BUILD + UNIT + STARTUP PASS (`2ebd749a42`, `c8a82b130b`, `b885a523c9`).**

```text
REVISION=b885a523c90ea9e15b94957f6df3c15608b75f75
STATIC=PASS
BUILD=PASS
UNIT=PASS (51/51)
STARTUP=PASS
ERROR_SCAN=PASS
SMOKE=NOT APPLICABLE
RUNTIME=NOT APPLICABLE
TEST_FLAGS_RESTORED=YES
```

`SMOKE`/`RUNTIME` jsou `NOT APPLICABLE`: A3A je čistě transportní vrstva (`AIRequest`/`AIResponse`/`AIClient`/`DynamicTaskJsonCodec`), `AIWorldMgr` je beze změny (viz prázdný diff na `AIWorldMgr.cpp`/`.h` u všech tří commitů) — žádná player/world-facing cesta zatím neexistuje, takže není co runtime testovat; wiring na skutečný world state je `2.13A3B`.

Shrnutí implementace (přes tři review kola):

- `AIRequest`/`AIResponse`: nový `AIRequestType::DynamicTask`, `AIRequest::DynamicTask`/`QuestProvenance`, `AIResponse::QuestProvenance`/`DynamicTask` — stejný "client's own echo, never server's claim" pattern jako `DecisionProvenance`/`Decision`. `QuestRequestProvenance` (a její `ObjectGuid`) žije jen v paměti, nikdy na wire.
- `AIClient`: `SubmitDynamicTask()` s vlastním bounded `DynamicTasksInFlight` counterem, zcela odděleným od `DecisionsInFlight` (`maxDynamicTasksInFlight` defaultuje na `0`, takže existující 5-arg constructor call v `AIWorldMgr.cpp` zůstal beze změny). `DynamicTaskSession` zrcadlí `DecisionSession` (resolve/connect/write/read/timeout/`_completed` guard), čte přes `http::response_parser<string_body>` s `body_limit(16384)` (zrcadlí `AI_TASK_MODEL_MAX_RESPONSE_BYTES` default z A2), a po úspěšném parse ověřuje `protocol_version`/`request_id`/`agent_id`/`snapshot_sequence` proti původnímu requestu — libovolný mismatch znamená `Success=false` a `DynamicTask` zůstává prázdné.
- `DynamicTaskJsonCodec.h/.cpp` (trvalý, ne dočasný): serializer s plným JSON string escapingem pro `DisplayName`; parser je dvouvrstvý — (1) plný RFC 8259 recursive-descent grammar walker (`ParseJsonObject`/`ParseJsonArray`/`ParseJsonValue`) ověřující syntax, escaping, striktní number grammar, žádné duplicitní klíče a plnou spotřebu inputu, PŘED (2) schema extrakcí, která pole hledá výhradně jako *direct members* správného objektu (root vs. `proposal`) přes už naparsovaný member list — nikdy substring-searchem přes celý dokument. `HasExactKeySet()` vyžaduje na obou úrovních přesně deklarovanou sadu polí (žádné chybějící, žádné neznámé/extra) — stejný `extra="forbid"` kontrakt jako Python `dynamic_task.py`. Number/float parsing má striktní JSON grammar, `double→float` narrowing je bounded (`1e100` se korektně zamítne), JSON whitespace je striktně jen space/tab/LF/CR (ne `std::isspace()`).
- `tests/game/DynamicTaskJsonCodec.cpp`: trvalé Catch2 testy (auto-collected přes `CollectSourceFiles`, stejně jako zbytek `tests/game/`) — validní response, escaped quote/backslash/embedded-brace round-trip, malformed JSON (chybějící root braces/commas, trailing garbage, non-object root, duplicate keys, pole zanořená pod cizím root klíčem, neznámá/chybějící pole na obou úrovních, pořadí polí nezáleží), nepodporovaný/`INVALID` objective, uint32 overflow, `1e100` float-narrowing bug, bare `NaN`/`Infinity`, title/description limity, degenerované proposal hodnoty, vertical-tab/form-feed whitespace rejection, response-left-untouched-on-failure — 51 testů, 51 passed.

Review prošel třemi statickými kontrolami: P2=2/P3=1 → P2=1/P3=1 → P1=0/P2=0/P3=0 STATIC PASS. První review odhalilo permissive hand-written JSON parsing, `double→float` finite overflow a chybějící permanentní codec testy. Druhé review odhalilo, že validní JSON ještě nebyl validován jako přesný direct-member `DynamicTaskResponse` schema (substring search field lookup byl obejitelný zanořením pod cizí klíč) a že JSON whitespace nebyl RFC-strict (`std::isspace()` přijímal i vertical tab/form feed). Finální follow-up (`b885a523c9`) oba nálezy uzavřel.

##### 2.13A3B — world-thread provenance wiring

**Stav: CLOSED — kumulativně znovu ověřeno v 2.13B gate na revision `866e8b296c`.**

Produkční cesta nyní vede od skutečného `WorldEvent` přes `PerceptionSystem`, `ShortTermMemory`, sanitizovaný `QuestContext`, async `/dynamic-task` a world-thread response acceptance až k inertnímu `DynamicTaskCandidate`. Request provenance, runtime incarnation, snapshot, active goal attempt, source-memory identity/age, request-local target token a live target se ověřují před vytvořením candidate. Model nikdy nedostává `ObjectGuid`, `SpawnId` ani jinou trusted server identity.

Implementační/review commity: `a7b1b88e`, `a877dd2d`, `37a609b3`, `f3633005`.

#### 2.13B — `QuestProposal` validator

Trvalé meze návrhového kontraktu z původní roadmapy:

- LLM odděluje narativ (title/summary/dialogue) od mechanického objective/target/count/range/expiry/reward návrhu; server určuje skutečnou podobu úkolu.
- Objective musí být v serverovém allowlistu, target existující a známý/povolený pro NPC; amount/range/expiry mají server-side bounds.
- Reward je server-owned policy; LLM nesmí libovolně mintovat gold/item/spell/reputation.
- Žádné generované SQL, Lua/C++, arbitrary script, spell cast, spawn/delete ani jiná direct world mutation; hallucinated IDs se odmítají.
- Source-event/cause a snapshot provenance váže návrh na skutečný problém; stale, retry a replay nesmí vytvořit neplatný nebo duplicitní offer.
- Aktuální wire contract 2.13A1 používá request-local target tokeny, nikoli model-visible trusted server identity z původního schematického návrhu. Konkrétní validátor a runtime evidence jsou v této sekci.

**Stav: CLOSED — STATIC + BUILD + UNIT + RUNTIME PASS (`2bb6841c`, `d150b6e6`, `3a314917`, `866e8b296c`).**

```text
REVISION=866e8b296c1bf52203c74825332e7b5cc969cd1d
STATIC=PASS (P1=0, P2=0, P3=0)
BUILD=PASS
UNIT=PASS (full C++ suite)
RUNTIME_POSITIVE=PASS
RUNTIME_NEGATIVE_STALE_SNAPSHOT=PASS
RUNTIME_NEGATIVE_AUTHORITATIVE_VALIDATION=PASS
ERROR_SCAN=PASS
BUILD_TESTING_RESTORED=OFF
TEST_FLAGS_RESTORED=YES
```

`ValidateDynamicTaskCandidate()` je explicitní pure authoritative boundary. Znovu ověřuje pouze pravidla, která patří do materializačního rozhodnutí: podporovaný objective type, source-problem konzistenci, jednoznačný server-owned target binding, aktuální policy limity, bounded/plain text a live giver-to-target range. Nezdvojuje bez důvodu A3B response-acceptance kontroly. Výsledkem je typed `DynamicTaskValidationResult` s explicitním reject reasonem a `QuestProposal` pouze při plném úspěchu.

Runtime pozitivní běh pro request `336`, agent `214023`, snapshot `2` prokázal skutečný local-model call (`1526 ms`) a celý sled `CONTEXT_BUILT → SUBMITTED → RESPONSE_RECEIVED success=true → PROVENANCE_MATCHED → TARGET_MATCHED → VALIDATED inert=1` nad skutečným `sourceEvent=1` a target entry `525`.

Negativní běh requestu `30` skončil explicitně na `STALE_SNAPSHOT` po `1226 ms`, tedy fail-closed ještě v A3B acceptance. Běh requestu `127` prošel provenance i live target re-resolution a authoritative validator jej explicitně odmítl s `LIVE_TARGET_OUT_OF_RANGE`. Tím je negativní důkaz založený na skutečném reject výsledku, ne na absenci logu. Timing citlivost sdílené `SnapshotSequence` vůči běžnému decision scheduleru zůstává evidovaná pro 2.13D; staleness check se kvůli testu neoslabuje.

Po testu byly `AIWorld.DynamicTaskEnable`, `AIWorld.TestDynamicTaskAgentId` a dočasně změněné decision/range hodnoty vráceny na default. `BUILD_TESTING=OFF`; `ai-server /health` potvrzuje `task_model_enabled=false`.

**2.13B samo o sobě zůstává gameplay-inertní:** validace sama o sobě neprovádí žádnou player/world mutaci — `ValidateDynamicTaskCandidate()` pouze produkuje typed reject reason nebo `QuestProposal`, nikdy sama nezapisuje quest marker, DB řádek, `ActionRequest` ani jinou fyzickou akci. Downstream `2.13C` tento validovaný `QuestProposal` skutečně konzumuje přes své vlastní, nezávislé live re-validation hranice (`DynamicQuestCreation`/`DynamicQuestPlayerAcceptance`/`DynamicQuestPlayerCompletion`) — tvrzení "candidate/proposal je inertní" platí jen pro tuto B hranici samotnou, ne globálně přes celou branch od `2.13C1` dál.

#### 2.13C — player-facing dynamic quest lifecycle

**Stav: CLOSED — C1/C2/C3/C4/C5/C6 (A/B1/B2/B3/C/D) všechny CLOSED (viz níže).**

##### 2.13C1 — pure lifecycle domain

**Stav: CLOSED.**

- `Offered` / `Active` / `Completed` / `Failed` / `Expired` a explicitní legální přechody mezi nimi;
- jeden kanonický expiry predikát (`IsDynamicQuestExpired`), nezávislý na `State`;
- authoritative player binding (`AcceptedByPlayerGuid`), bez pozdější re-assignace;
- idempotentní konzumace progress eventů (`ConsumedProgressEventIds`), saturující na `RequiredCount`;
- čistě pure value-object doména — žádný live `Creature*`/`Player*`/`Map*`.

##### 2.13C2 — registry ownership / validated offer handoff

**Stav: CLOSED.**

- `DynamicQuestRegistry` vlastní všechny live instance, žádný caller-supplied transition commit (registry si vždy sama najde svou vlastní stored hodnotu, nikdy nedůvěřuje hodnotě od volajícího — uzavřelo to konkrétní STATIC nález, kde fabrikovaná `DynamicQuestInstance` se stejným Id/Revision mohla legitimně projít pure lifecycle funkcí);
- monotónní, process-lifetime `DynamicQuestId` (bez recyklace);
- `Offer()` je jediná cesta, jak nová instance vznikne — vždy fresh re-validace givera/targetu před vznikem;
- bounded registry (`AIWorld.DynamicQuestMaxLive`) + bounded/cursor-resumable maintenance reclaim expirovaných záznamů.

##### 2.13C3 — player accept boundary

**Stav: CLOSED.**

- `AcceptDynamicQuestForPlayer()` fresh re-resolvuje hráče (online/alive) i givera (AgentRecord, runtime incarnation, `Materialized`/`AIWorldControlled`/alive) — nikdy necachuje ani nedůvěřuje dřívějšímu stavu;
- giver runtime-incarnation validace (`GiverRuntimeGuid`) — despawn/respawn giver už nesmí legitimně dokončit starou nabídku;
- same-map + interaction-range gate (`AIWorld.DynamicQuestPlayerAcceptMaxRangeYards`), fail-closed na neplatnou/nekonečnou/NaN policy hodnotu;
- registry-owned `Offered → Active` přechod přes `DynamicQuestRegistry::Accept()`;
- žádná závislost na standardním TrinityCore quest logu/`QuestTemplate`.

##### 2.13C4 — visible player-facing offer + progress

**Stav: CLOSED — STATIC + BUILD + RUNTIME PASS.**

Runtime-potvrzený řetězec:

```text
real WorldEvent
    ↓
real local-model /dynamic-task request
    ↓
provenance validation
    ↓
validated QuestProposal
    ↓
Offered dynamic quest
    ↓
visible NPC gossip (vlastní UNIT_NPC_FLAG_GOSSIP overlay, nikdy nemaže native NPC flag)
    ↓
player Accept
    ↓
real direct-player KILL_CREATURE events (authoritative, ne test/fake progress)
    ↓
1/N ... N/N
    ↓
"Return to giver" player-facing feedback
```

Runtime navíc potvrzeno:

- native NPC gossip (vendor/trainer/quest-giver/DB-driven položky) zůstává funkční i pro NPC s aktivním dynamic questem — merge, ne suppress;
- kill jiného hráče nezvyšuje progress questu, který přijal první hráč — druhý hráč zabije správného moba, ale cizí quest se nehne;
- progress matchuje authoritative `TargetEntry` + `MapId`, ne exact runtime `TargetGuid` (`RequiredCount > 1` tedy znamená "N creatures daného typu", ne "jeden konkrétní spawn N-krát");
- ztracený/duplicitní kill-credit event je řešen fail-closed (oddělený `DynamicQuestKillEventBus` od lossy perception EventBusu; detekovaný drop force-failuje každý aktuální Active dynamic quest, nikdy ho nenechá tiše viset na možná špatném progressu).

Tento milník nevyžaduje standardní quest log ani `QuestTemplate` — to je vědomě mimo scope, viz `2.13C6`/`2.13D` níže pro navazující práci.

##### 2.13C5 — turn-in / completion / money reward

**Stav: CLOSED — STATIC + BUILD + UNIT + RUNTIME PASS.**

Implementováno:

- `RewardMoneyCopper` zkopírovaný jednou z už validovaného `QuestProposal` do `DynamicQuestInstance` (nikdy znovu čtený z modelu);
- `ReadyToTurnIn` gossip stav, oddělený od obyčejného `Active` (`IsDynamicQuestObjectiveComplete()` jako jeden kanonický predikát, sdílený gossip query i lifecycle commitem);
- reálná "Turn in" player akce v gossip menu, se stejnou native-gossip-merge disciplínou jako C4;
- fresh re-validace hráče/givera/bindingu/range/State/expiry před jakoukoli reward mutací — `CheckDynamicQuestPlayerCompleteApplicability()` sama kontroluje `State == Active` a expiry (ne jen `ProgressIncomplete`/money), navíc doplněná nezávislým non-committing `CompleteDynamicQuest()` preflightem jako defense-in-depth;
- `Active → Completed` výhradně přes `DynamicQuestRegistry::Complete()`;
- reward vyplacený přes `Player::ModifyMoney()`, nikdy přímý zápis pole;
- money-cap odmítnutí přesně zrcadlící reálnou `ModifyMoney()` semantiku (`player.Money + reward` musí být striktně pod `MAX_MONEY_AMOUNT`, ne `<=`);
- in-process replay/double-payout ochrana — úspěšný `Complete()` okamžitě `Remove()`uje instanci z registry, takže druhý pokus najde jen `QuestNotFound`;
- player-facing feedback i při zamítnutém turn-inu (dřív tichý gossip close);
- žádná standardní quest-log/`QuestTemplate` závislost, žádná DB persistence, žádný group/party credit.

Closure gate potvrzen:

- finální STATIC review C5 code baseline (`9f429f9f93`): PASS (P1=0/P2=0, dva advisory P3 uzavřené);
- BUILD: PASS;
- UNIT: 226/226 PASS;
- runtime: Turn in → skutečný nárůst peněz o reward → quest zmizí z gossipu (native gossip zůstává funkční) → replay stejného kliknutí nedá druhý reward/log → druhý hráč nemůže turn-inout ani vybrat reward z questu prvního hráče — potvrzeno.

`2.13C5` je tímto CLOSED. Runtime happy path (offer → accept → 1/3 → 2/3 → 3/3 → turn-in → reálný `Player::ModifyMoney()` payout) i replay/double-payout ochrana jsou provlečené a potvrzené proti C5 code baseline `9f429f9f93`.

##### 2.13C6 — quest outcome → WorldEvent / issuer feedback

**Stav: CLOSED — C6A/C6B1/C6B2/C6B3/C6C/C6D všechny CLOSED. Finální gate na ověřované revizi `1e5da22e29`: STATIC PASS, BUILD PASS, UNIT PASS 253/253, RUNTIME PASS.**

Požadavek 2.13 zahrnuje typed `WorldEvent` po completion/failure/expiry, použitelný `Perception`/`Memory`/`Goal` pipeline, a dopad na skutečný problém světa nebo stav/goal/memory issuer NPC. Samotné `2.13C5` uzavíralo player quest lifecycle + reward; `2.13C6` doplnilo návrat výsledku do AI světa přes issuer memory a viditelnou gossip reakci. Autonomní změna Goal/Action zůstává mimo tento scope.

```text
Completed / Failed / Expired
        ↓
typed authoritative WorldEvent
        ↓
Perception
        ↓
Memory
        ↓
issuer NPC / problem state
```

Vědomě vyčleněno jako vlastní produkční feature (ne testovací gate), protože jde o rozšíření, ne jen o closure existujícího scope. Rozděleno na čtyři sub-milníky:

###### 2.13C6A — pure outcome/event contract

**Stav: CLOSED — STATIC + BUILD + UNIT 236/236 PASS.**

Implementováno:

- `WorldEventType` doplněn o `DynamicQuestCompleted`/`DynamicQuestFailed`/`DynamicQuestExpired`, včetně `ToString()`;
- `QuestProposal` nese `SourceCorrelationId` vedle už existujícího `SourceEventId`/`SourceEventType`, kopírovaný v `ValidateDynamicTaskCandidate()` z `candidate.Provenance.SourceCorrelationId` (dřív se zahazoval);
- `DynamicQuestInstance` nese stejnou trojici source-provenance polí po celý lifecycle; `OfferDynamicQuest()` je jednou zkopíruje z validovaného `QuestProposal`, stejně jako `Title`/`Description`/`RewardMoneyCopper`;
- nový čistý value-only builder `Quest/DynamicQuestOutcomeEvent.h/.cpp` — `BuildDynamicQuestOutcomeWorldEvent(instance, location)`: `nullopt` pro `Offered`/`Active`; `EventId` i `OccurredAtMs` zůstávají `0` (jediný autoritativní zdroj obou je `EventBus::Publish()`); `CauseEventId`/`CorrelationId` dědí `instance.SourceEventId`/`SourceCorrelationId`; `Actor.Guid` je `AcceptedByPlayerGuid` **pouze** pro `Completed` (jediný outcome, který hráč skutečně způsobil) — pro `Failed`/`Expired` zůstává prázdný, i když hráč quest přijal, protože obojí je server-side (deadline maintenance / force-fail / replay containment), ne hráčova akce; `Target.Agent`/`Target.Guid` je giver.
- plné Catch2 pokrytí (`tests/game/DynamicQuestOutcomeEvent.cpp`): všechny tři terminal mapování, `Offered`/`Active` rejection, zachování `SourceEventId`/`SourceCorrelationId`/`SourceEventType` napříč provenance → proposal → offered instance → terminal instance, `CauseEventId`/`CorrelationId`, `EventId == 0`, `OccurredAtMs == 0`, Actor-jen-pro-Completed včetně negativních případů.

Žádná změna `AIWorldMgr`, `EventBus`, `Perception`, `Memory`, `Goal`, reward, completion ordering ani DB persistence — čistě kontrakt + provenance plumbing + testy.

###### 2.13C6B — authoritative publication (CLOSED)

Publikace `BuildDynamicQuestOutcomeWorldEvent()`u přes `EventBus`, výhradně z reálného úspěšného registry transitionu (`DynamicQuestRegistry::Complete()`/`Fail()`/`Expire()`), nikdy z preflight/non-committing výsledku. Tři oddělené terminal cesty s různými podmínkami:

- **C6B1 — Completed (CLOSED — STATIC + BUILD + UNIT + RUNTIME PASS)**: po úspěšném `_dynamicQuestRegistry.Complete(id, nowMs)` vzít výhradně `*completeResult.Instance`, publikovat před `_dynamicQuestRegistry.Remove(id)`. `WorldEventLocation` je snapshotovaná hned po `CheckDynamicQuestPlayerCompleteApplicability()` (STATIC review P2 fix) — ne re-read z `giverCreature` po `Player::ModifyMoney()`, protože ten synchronně volá `sScriptMgr->OnPlayerMoneyChanged()` ještě před vlastní mutací a hook může spustit libovolný script kód. Selhání publikace (bounded/lossy `EventBus`) nesmí rollbackovat reward ani `Completed` — pouze zalogovat `DYNAMIC_QUEST_OUTCOME_EVENT_DROPPED`. `AIWorldMgr::PublishWorldEvent()` teď vrací `bool` (výsledek `EventBus::Publish()`), existující call sites ho dál mohou ignorovat.
- **C6B2 — Expired (CLOSED — STATIC + BUILD + UNIT 237/237 + RUNTIME PASS)**: analogicky z `RunDynamicQuestMaintenance()`u, pouze pokud `_dynamicQuestRegistry.Expire(id, nowMs)` skutečně uspěje. Giver nemusí být v tu chvíli materialized, proto `DynamicQuestInstance` dostane server-owned `WorldEventLocation GiverLocationAtOffer` snapshot z okamžiku `CreateDynamicQuestOffer()` (nikdy model input) jako fallback, když live lokace není dostupná; live-current-or-offer-fallback logika navíc kontroluje `GiverRuntimeGuid` shodu, aby despawnutý/respawnutý giver pod stejným `AgentId` nikdy nezdědil pozici nové incarnation.
- **C6B3 — Failed (CLOSED — STATIC + BUILD + UNIT + RUNTIME PASS)**: `FailAllActiveInstances()`/`TerminateForReplayContainment()` rozšířeny, aby vracely value-copy skutečně-Failed instance (`DynamicQuestTerminationResult::FailedInstance`), ne jen count/bool — `AIWorldMgr` publikuje `DynamicQuestFailed` jen když `Fail()` v daném volání opravdu uspěl, nikdy fabrikovaný event pro odmítnutý/no-op transition. Sdílený `AIWorldMgr::ForceFailAllActiveDynamicQuestsForKillCreditLoss()`/`PublishDynamicQuestOutcome()`/`ResolveDynamicQuestOutcomeLocation()` sjednocují publish-then-remove sekvenci pro oba skutečné Failed production paths (kill-credit-loss force-fail i reward-compensation replay containment). Runtime ověřeno přes nový one-shot test hook `AIWorld.TestDynamicQuestKillCreditLoss` (default 0), který reprodukuje stejnou authoritative cestu bez nutnosti skutečně vyčerpat `DynamicQuestKillEventBus`u (kapacita 16 384).

Registry zůstává EventBus-unaware po celou dobu — publikuje výhradně `AIWorldMgr`.

###### 2.13C6C — issuer Perception/Memory feedback (CLOSED)

Doručení outcome eventu konkrétnímu issuer NPC přes normální `Perception`/`Memory` pipeline. Generic `PerceptionSystem::ObserveEvent()` už uměl libovolný `WorldEvent` převést na `Observation` a zachovat `EventId`/`CorrelationId`/`WorldEventType`, ale ta cesta je sight/range/LOS-based. Doplněno o `PerceptionSystem::ObserveDirectedEvent(observerId, event)` — pure value-only, žádný `Creature*`, žádný map/range/LOS gate, vyžaduje `event.Target.Agent == observerId`, `Channel = PerceptionChannel::Rumor`. `AIWorldMgr::ProcessWorldEvent()` v normální Sight smyčce sleduje, zda issuer outcome eventu (`IsDynamicQuestOutcomeEvent()`) už dostal Sight observation; pokud ne a issuer je stále registrovaný agent, dostane přesně jednu directed/Rumor fallback observation — nikdy force-load Creature/grid. Obě cesty končí ve stejném `ProcessObservation()` → `ShortTermMemory::Remember()`, takže Completed/Failed/Expired se dostane do issuer memory i když issuer není fyzicky poblíž.

###### 2.13C6D — runtime causal-loop proof (CLOSED)

Runtime důkaz celého řetězce Completed/Failed/Expired → `WorldEvent` → `Perception` (Sight nebo Rumor) → `Memory` → viditelný dopad na issuer NPC. Implementováno přes nový čistý selector `Quest/DynamicQuestOutcomeReaction.h/.cpp` — `SelectDynamicQuestOutcomeReaction(issuer, memories)` vybírá nejnovější (deterministicky tie-breaknutou přes vyšší `SourceEventId`) eligible outcome memory pro daného issuera. `AIWorldMgr::DynamicQuestGossipContent` dostal `ContentKind::RecentOutcome`, `GetDynamicQuestGossipContent()` na něj spadne, pokud pro daného givera neexistuje žádný live Active/Offered quest (nikdy čtení z `DynamicQuestRegistry` — terminal instance je už odstraněná). Nová `HasDynamicQuestGossipContentForGiver()` drží gossip flag nahoře i po dobu, kdy existuje jen recent-outcome memory (ShortTermMemory TTL, ~60s default). `AIWorldCreatureAI::OnGossipHello()` zobrazí jeden informational řádek (`FormatDynamicQuestOutcomeReaction()`) a loguje `DYNAMIC_QUEST_OUTCOME_REACTION_SHOWN`; reakce se nekonzumuje, může se zobrazit opakovaně dokud memory přirozeně neexpiruje. Runtime ověřeno end-to-end (Expired i Failed cesta, včetně unloaded/dead issuer fallbacku přes Rumor).

Žádný nový `GoalType`/`ActionType` — gossip je existující player-facing seam, čistě čte Memory-derived stav, nikdy nemutuje svět. Autonomní NPC reakce (Goal/Action) na vlastní quest outcome je vědomě mimo scope, patří do budoucího world-problem milestone.

#### Restart / persistence semantics (rozhodnuto explicitně, ne odloženo mlčky)

`DynamicQuestRegistry` je dnes čistě process-local in-memory registr — žádná DB tabulka, žádný persistence boundary. To je vědomé, ne přehlédnuté rozhodnutí pro `2.13C1`–`C5`:

- dynamic quest instance mají **process lifetime**, ne DB-backed persistenci;
- worldserver restart zahodí všechny aktuálně `Offered`/`Active` dynamic quests beze stopy (žádná orphaned DB row, protože žádná DB row nikdy nevznikla);
- reconnect **bez** restartu quest zachová — nic v `2.13C1`–`C5` necachuje hráčovu session ani live pointer přes odpojení, vazba je vždy přes `ObjectGuid`/`AgentId`, které přežijí reconnect;
- perzistentní (DB-backed, restart-survivující) dynamic quests jsou vědomě budoucí práce, ne součást `2.13C1`–`C6`. Pokud se ukáže jako potřeba, dostane vlastní explicitní milestone (např. `2.13C7`) až v okamžiku, kdy bude jasné, co přesně má přežít restart a jak se to smíří s `DynamicQuestId`'s dnešní čistě in-process monotónní alokací.

Runtime otestováno a potvrzeno jako `2.13D` closure gate: worldserver restart zahazuje `Offered`/`Active` dynamic quests beze stopy, žádný orphaned stav; reconnect bez restartu quest zachovává přes `ObjectGuid`/`AgentId`.

#### 2.13D — final end-to-end closure gate

**Stav: CLOSED.**

Runtime prokázáno přes `2.13C4`:

- real `WorldEvent`;
- real local-model `/dynamic-task` call;
- provenance validace;
- viditelná player-facing nabídka;
- real Accept;
- authoritative TrinityCore kill progress;
- objective-complete player feedback.

Runtime dále prokázáno přes `2.13C5`/`2.13C6` (turn-in/reward, a celý Completed/Failed/Expired → `WorldEvent` → `Perception` → `Memory` → viditelný issuer dopad řetězec — viz `2.13C6D` výše).

Poslední dva gate items pro `2.13D` samotné jsou nyní také runtime otestovány a potvrzeny:

- explicitní restart/reconnect semantics (viz sekce výše — `Offered`/`Active` dynamic quests process-lifetime, reconnect bez restartu quest zachová přes `ObjectGuid`/`AgentId`) — potvrzeno jako gate;
- finální agregace negative failure-mode chování (timeout/malformed/stale/provider outage) napříč `2.13A`/`2.13B` — potvrzena jako jeden explicitní end-to-end gate.

`2.13D` tímto CLOSED — neduplikovalo práci, kterou `2.13C4`/`2.13C5`/`2.13C6` reálně udělaly, jde o finální agregační gate nad tím, co bylo jinde už hotové. Celý milník `2.13` je tímto CLOSED.

---

### 2.14 — final Etapa 2 POC / aggregate integration gate

**Stav: CLOSED — RUNTIME POC PASS.**

2.14 je finální POC / integrační gate Etapy 2 nad tím, co už je hotové — ne další feature milestone. Nevyžadovalo žádný nový `WorldEventType`, consequence layer ani jinou novou produkční logiku.

Runtime test potvrdil skutečný problematický konec řetězce:

```text
real persistent Agents
    ↓
automatic WolfLoose coalition
    ↓
generic HUNT intent
    ↓
per-member ActionRequest
    ↓
ActionSystem validation ALLOWED
    ↓
TrinityCore MOVE_TO
    ↓
ARRIVED
    ↓
authoritative ATTACK validation ALLOWED
    ↓
TrinityCore ATTACK STARTED
    ↓
skutečný combat
    ↓
target skutečně zemře
    ↓
TARGET_DEFEATED
    ↓
HUNT ownership korektně skončí
```

Konkrétně group `41` měla dva členy a oba prošli: `MOVE_TO ALLOWED` → `MOVE_TO STARTED` → `ARRIVED` → `ATTACK ALLOWED` → `ATTACK STARTED` → `TARGET_DEFEATED`. To je důkaz, že coalition není jen registry/social abstrakce, ale přes generic intent → individual action → `ActionSystem` skutečně ovlivní svět.

Zbytek POC byl už runtime prokázaný z předchozích milestone:

| Řetězec | Stav |
|---|---|
| `WorldEvent` → `Perception` → `Memory` | PASS |
| Needs/Goals/Actions | PASS |
| async LLM decision protocol | PASS |
| dynamic-task local model path | PASS |
| authoritative `QuestProposal` validation | PASS |
| dynamic quest offer/accept/progress/turn-in | PASS |
| `Completed`/`Failed`/`Expired` → `WorldEvent` | PASS |
| `WorldEvent` → `Perception` → `Memory` → issuer reaction | PASS |
| restart/reconnect semantics | PASS |
| timeout/malformed/stale/provider outage fail-closed | PASS |

Společně s výše uvedeným HUNT-coalition runtime důkazem toto uzavírá Etapu 2 jako proof of concept. Žádné nové produkční chování pro `2.14` nebylo potřeba — nejde o scripted wolves→farmer story spojující všechny ověřené subsystémy do jednoho nového flow, jde o agregátní POC closure proof nad tím, co je jinde už hotové/uzavřené.

---

### 2.15 — testy, diagnostika a scale hardening

**Stav: průběžný neblokující hardening.** Runtime/verification gate potřebné pro POC jsou uzavřené v 2.12–2.14; následující seznam eviduje další pokrytí a diagnostiku.

Již ověřeno:

- [x] restart → reload memory;
- [x] structured decision/action audit logs;
- [x] simulation tier transition/tick DEBUG observability;
- [x] AgentGroup presence/coarse simulation DEBUG observability;
- [x] AgentGroup lifecycle smoke + restart/non-reuse runtime evidence;
- [x] local LLM protocol/validation, player task lifecycle, outcome feedback a negative failure-mode gate — konkrétní výsledky viz 2.13.

Průběžně doplnit:

- unit testy Goal utility selection, ActionRequest validation, persistence/serialization a group policy/intent/projector;
- integration lifecycle/coordination tests;
- debug snapshot podle `AgentId` a `GroupId`;
- metrics pro scheduler, stale responses/actions a lifecycle failures; backend/dashboard runtime verification včetně tier counts, scheduler depth a stale breakdown;
- bounded-work assertions/profiling pro registry scans a group scans;
- LLM proposal validation + malformed/stale/outage tests;
- restart/replay/duplicate suppression tests;
- action ownership audit logs s source goal/group/attempt provenance.

Scale hardening není důvod předčasně přidávat složitou infrastrukturu. Optimalizace mají následovat skutečně změřený problém, ale recurring world-thread work musí zůstat explicitně bounded už od začátku.

---

### Etapa 2 — Definition of Done

**Stav: CLOSED — POC COMPLETE.**

Etapa 2 není hotová pouze tím, že NPC umí chodit.

Hotovo:

- [x] persistent individual Agent identity;
- [x] event/perception/memory/needs/goals;
- [x] safe Action API;
- [x] async decision protocol + stale/provenance protection;
- [x] bounded multi-agent scheduler;
- [x] persistent farmer vertical slice;
- [x] separate persistent AgentGroup identity;
- [x] async-safe AgentGroup lifecycle;
- [x] Loose/Stable policy;
- [x] automatic generic profile-driven formation/maintenance;
- [x] generic group REGROUP intent;
- [x] per-member ActionSystem dispatch;
- [x] Emergency preemption of active group coordination;
- [x] leave/dissolve lifecycle cancellation of active group coordination;
- [x] restart/no-resurrection proof.

Závěrečné podmínky — splněno:

- [x] global agent population foundation gate pro jednu lokaci (2.12F4A–F4B3: `ControlMode` split, TrinityCore-aligned `AgentId == SpawnId` identity, bidirectional spawn reconciliation, scoped Elwynn population + full Control activation — `3540 / 3540 AIWorldControlled`, STATIC + BUILD + RUNTIME PASS) — `2.12F4C`/`2.12F4D` (world-scale hardening, eventual full-world bootstrap) zůstávají otevřené, ale nejsou blocker pro second-profile proof nad již reálnou, reconciled Elwynn populací;
- [x] second-profile genericity proof;
- [x] alespoň jedno další skutečné generic group behavior potřebné pro emergentní slice;
- [x] skutečný local LLM request přes async `ai-server`;
- [x] structured server-validated player task proposal;
- [x] player-facing task lifecycle;
- [x] end-to-end `WORLD → NPC → LLM/DECISION → PLAYER/TRINITYCORE → EVENT → WORLD` runtime gate;
- [x] safe fallback pro LLM outage/malformed/stale response.

Etapa 2 je tímto CLOSED — viz `2.14` výše pro finální agregátní POC runtime proof (HUNT-coalition end-to-end důkaz + shrnutí všech dříve prokázaných řetězců).

---

## Etapa 3 — Elwynn Forest World Preparation

**Stav: PLANNED — další etapa po uzavřeném POC.** Nejbližší gate je 3.0–3.1: přesný scope, reprodukovatelný census export a klasifikace všech spawnů.

2.12F4B2/F4B3 již ověřilo technickou registraci a control activation Elwynn populace (`3540` agentů, `zoneId=12`). To samo neuzavírá sémantický/faction/data-quality audit této etapy. `FULL_AGENT`, `LIGHTWEIGHT/BACKGROUND` a `VANILLA_ONLY` níže jsou plánované participation klasifikace; nejsou novými hodnotami existujícího dvouhodnotového `ControlMode`.

**Cíl:** před spuštěním komplexního živého světa vzít jednu konkrétní oblast — **Elwynn Forest** — a udělat z ní přesně zmapovaný, sémanticky popsaný a datově opravený základ. Etapa 3 není ještě simulace celé společnosti. Je to příprava herního prostoru, aby Etapa 4 nestavěla emergentní chování nad špatnými spawny, nejasnými lokacemi a nesmyslnými faction assignments.

Zásadní pravidlo Etapy 3:

> **Nejdřív musí být jasné kdo je kdo, kde žije/pracuje/působí, ke které frakci patří a jaké části mapy mají význam. Teprve potom má smysl nechat AI svět dlouhodobě měnit.**

### 3.0 Scope a source of truth

- [ ] cílová oblast je Elwynn Forest v používaném TrinityCore 3.3.5/TDB datasetu;
- [ ] přesně definovat hranici census výběru podle authoritative map/zone/area dat, ne podle ručně odhadnutého obdélníku;
- [ ] vytvořit reprodukovatelný export z world DB pro creature spawny, templates, movement/pathing, faction/faction-template, NPC flags a relevantní vazby;
- [ ] uložit odvozený audit/manifest do repozitáře v reviewovatelném formátu (např. CSV/JSON/Markdown generated report); samotný TDB dump se necommitne;
- [ ] každý ruční override musí mít důvod a být verzovaný;
- [ ] z census nesmí mizet spawn jen proto, že zatím není AI-enabled.

Minimální spawn evidence:

```text
SpawnId
Entry
Name/template
Map / Zone / Area
X/Y/Z/O
movement type / path
respawn
NPC flags / role hints
TrinityCore faction/faction-template
AI participation mode
WorldFactionId
SemanticLocationId
Home / Work / Roam anchors
notes / correction status
```

### 3.1 Kompletní census NPC a creature spawnů

Cílem je **zmapovat všechny creature/NPC spawny v Elwynn Forest**, ne jen několik testovacích agentů.

- [ ] vyexportovat 100 % spawnů v definovaném scope;
- [ ] odlišit unikátní named NPC od generických spawnů stejného template;
- [ ] klasifikovat minimálně civilians, guards, merchants/vendors, trainers, quest-related NPC, workers/farmers, travelers, hostile humanoids, predators, prey/fauna a special/scripted entities;
- [ ] u každého relevantního spawnu rozhodnout `FULL_AGENT`, `LIGHTWEIGHT/BACKGROUND`, `VANILLA_ONLY` nebo jiný explicitní participation režim;
- [ ] u AI-enabled NPC připravit role/profession metadata odděleně od physical `AgentType`;
- [ ] připravit Home/Work/Roam/Guard/Resource anchors tam, kde dávají smysl;
- [ ] identifikovat duplicity, nesmyslné spawny, chybné souřadnice, chybné movement types a entity, které se nesmí automaticky převést na persistent AI agenta;
- [ ] vytvořit coverage report, který failne gate, pokud zůstane spawn bez klasifikace nebo explicitního důvodu `VANILLA_ONLY`.

**Gate 3.1:** každý spawn v Elwynn census má explicitní klasifikaci a auditovatelný stav.

### 3.2 Sémantická mapa lokací

AI nesmí chápat svět jen jako surové `x/y/z`. Etapa 3 zavede konkrétní pojmenované lokace a jejich vztahy.

Minimálně zmapovat a runtime ověřit relevantní oblasti jako například:

- Northshire / Northshire Valley;
- Goldshire;
- Stonefield Farm;
- Maclure Vineyards;
- Eastvale Logging Camp;
- Fargodeep Mine;
- Jasperlode Mine;
- Tower of Azora;
- Mirror Lake a okolní body;
- hlavní cesty, křižovatky, mosty, lesní koridory, farmy, kempy, resource sites a danger zones, které mají význam pro simulaci.

Konkrétní seznam a hranice musí vzniknout z map/world dat a runtime kontroly; výše uvedené názvy nejsou náhradou za úplný map audit.

Pro každou semantic location připravit například:

```text
SemanticLocationId
name
type
map/zone/area
center + radius / polygon / bounded region
parent location
adjacent locations
travel connectors / routes
resource tags
danger tags
settlement/farm/mine/road/etc.
faction presence / holding capability
population capacity / role hints
```

- [ ] `HomeLocation`/`WorkLocation` postupně odkazovat na semantic locations/anchors místo náhodných magic coordinates, kde je to vhodné;
- [ ] definovat adjacency a použitelné přesuny mezi lokalitami;
- [ ] rozlišit fyzickou lokaci od politického vlastnictví — jedna location může změnit faction presence bez změny identity;
- [ ] ověřit reprezentativní pathing mezi sousedními semantic locations přes TrinityCore movement/nav data;
- [ ] vytvořit debug výpis/map report, ze kterého lze zjistit, která NPC a frakce jsou přiřazeny k dané lokaci.

### 3.3 Faction audit a oprava

Současné TrinityCore `faction`/`faction_template` hodnoty nejsou samy o sobě dostatečný sociální model AI světa a v cílové oblasti mohou být pro zamýšlenou simulaci nekonzistentní nebo věcně špatné.

Etapa 3 proto oddělí dvě věci:

```text
TrinityCore faction/faction_template
    = combat/reaction/gameplay compatibility

AI WorldFactionId
    = sociální/politická příslušnost pro vztahy,
      coalition eligibility, holdings a budoucí dynamiku světa
```

- [ ] auditovat faction/faction-template u všech Elwynn census spawnů;
- [ ] identifikovat a verzovaně opravit zjevně chybné/inconsistent TrinityCore faction assignments tam, kde ovlivňují gameplay/reaction;
- [ ] zavést explicitní persistentní `WorldFactionId` nebo ekvivalentní sociální identity layer nezávislou na `AgentGroup`;
- [ ] každý AI-enabled agent musí mít explicitní WorldFaction affiliation nebo explicitní `Neutral/Unaffiliated` stav;
- [ ] definovat první konkrétní seznam WorldFaction entit pro Elwynn podle skutečného census, nikoli podle několika předem vymyšlených typů;
- [ ] fauna/predators/humanoids nesmí být automaticky sloučeni do jedné frakce jen proto, že sdílejí combat reaction;
- [ ] faction změna nesmí implicitně přepsat `AgentId`, memory ani individual identity;
- [ ] faction relation/diplomacy matrix pro Etapu 3 může být minimální/static; komplexní změny vztahů patří do Etapy 4.

### 3.4 Coalition pravidla uvnitř frakcí

`AgentGroup`/coalition a `WorldFaction` jsou dvě různé úrovně:

```text
WorldFaction
├── Agent A ┐
├── Agent B ├── AgentGroup / Coalition #1
├── Agent C ┘
├── Agent D ┐
└── Agent E ┴── AgentGroup / Coalition #2
```

Základní invariant:

> **Jedna coalition může obsahovat pouze členy stejné `WorldFactionId`.**

- [ ] `CreateGroup`/`JoinGroup` policy musí znát WorldFaction membership;
- [ ] cross-faction `JoinGroup` failuje před persistence mutation;
- [ ] mixed-faction group se nesmí načíst z DB; invalid persistent state fail-closed / quarantine podle zvolené recovery policy;
- [ ] `Loose`/`Stable` je charakter coalition, nikoli frakce;
- [ ] jedna frakce může mít mnoho současných coalitions a mnoho agentů bez coalition;
- [ ] faction membership sama automaticky nevytváří group;
- [ ] pokud agent někdy v budoucnu změní frakci, jeho nekompatibilní group membership musí být nejprve bezpečně ukončeno/reconciled;
- [ ] runtime test musí potvrdit same-faction join PASS a cross-faction join REJECT bez side effects.

Komplexní diplomacie, přeběhnutí mezi frakcemi a hráčovy faction transitions jsou explicitně **mimo Etapu 3**.

### 3.5 Faction presence a pohyb po mapě

Frakce nesmí být modelována jako statická značka přibitá k jedné souřadnici. Etapa 3 připraví datový/runtime základ pro to, že se **přítomnost frakce může po Elwynn Forest měnit a přesouvat**.

Důležité rozlišení:

```text
WorldFaction identity
    ≠
current faction presence / holdings / occupied locations
```

- [ ] zavést nebo navrhnout `FactionPresence`/`FactionHolding` state nad `SemanticLocationId`;
- [ ] frakce může mít současně přítomnost ve více lokalitách;
- [ ] presence může mít minimálně strength/population/priority nebo jiný malý deterministic state potřebný pro budoucí simulaci;
- [ ] movement znamená přesun/redeployment konkrétních agentů/coalitions mezi semantic locations přes existující movement/action pravidla, ne teleport celé abstraktní frakce;
- [ ] unloaded/background pohyb musí mít později reconciliation na physical spawny bez force-load; Etapa 3 má připravit seam a kontrolovaný smoke, ne kompletní strategickou AI;
- [ ] faction holdings/presence změna nesmí automaticky měnit faction identity NPC, která se v lokaci právě nacházejí;
- [ ] připravit controlled runtime scenario, kde same-faction coalition/presence opustí location A a přesune se do location B se zachováním AgentIds, GroupId a WorldFactionId;
- [ ] všechny změny presence musí být auditovatelné a mít jasný source/cause pro budoucí Event System integraci.

**Etapa 3 připravuje pohyb frakcí jako mechanismus. Proč frakce expanduje, ustupuje, bojuje nebo mění vztahy, bude až dynamika Etapy 4.**

### 3.6 World DB cleanup a verifikace

Mapování není pouze dokumentace. Pokud census odhalí špatná data, musí být cílový Elwynn baseline skutečně opraven.

- [ ] opravy spawn position/orientation tam, kde jsou prokazatelně chybné;
- [ ] opravy movement/pathing/home/wander parametrů;
- [ ] odstranění nebo zdokumentování chybných/duplicitních spawnů;
- [ ] opravy faction/faction-template a dalších flags, pokud neodpovídají zamýšlenému authoritative gameplay;
- [ ] validace vendor/trainer/questgiver/special NPC flags proti skutečné roli;
- [ ] AI metadata a WorldFaction mapování držet ve vlastní versionované vrstvě, pokud není důvod měnit upstream world schema;
- [ ] všechny world DB změny dodat jako versionované TrinityCore SQL updates/migrations, nikdy jako ruční zásah do běžící DB;
- [ ] vytvořit before/after audit report a smoke checklist pro reprezentativní lokace;
- [ ] ověřit, že opravy nerozbily vanilla login, quest/NPC interaction a základní hostile/friendly reaction.

### Etapa 3 — Definition of Done

- [ ] 100 % creature/NPC spawnů v definovaném Elwynn Forest scope je v census manifestu;
- [ ] každý spawn má explicitní classification/participation status;
- [ ] každý AI-enabled agent má semantic location context a explicitní WorldFaction affiliation nebo `Neutral/Unaffiliated`;
- [ ] klíčové lokace, sublokace, cesty a resource/danger anchors jsou verzovaně zmapované;
- [ ] TrinityCore faction/faction-template audit je dokončen a nalezené chyby jsou opravené nebo explicitně zdokumentované;
- [ ] `WorldFactionId` je oddělený od `AgentGroup` i od raw TrinityCore faction template;
- [ ] same-faction coalition membership funguje a cross-faction coalition membership je fail-closed;
- [ ] existuje minimální faction presence/holding model nad semantic locations;
- [ ] controlled same-faction movement/presence test mezi dvěma Elwynn locations projde bez ztráty identity a bez force-load shortcutu;
- [ ] všechny změny world DB jsou reprodukovatelné z Git historie;
- [ ] coverage/audit report neobsahuje nevyřešené „unknown“ položky, které by blokovaly dlouhodobou simulaci;
- [ ] po clean DB bootstrapu a aplikaci updates odpovídá Elwynn runtime připravenému baseline.

> **Gate:** Etapa 3 končí ve chvíli, kdy Elwynn Forest není pro AI jen sada TrinityCore spawnů a souřadnic, ale explicitně popsaný světový prostor s NPC identitami, rolemi, lokacemi, frakcemi a bezpečnými coalition pravidly. Teprve nad tímto baseline se zapíná komplexní dynamika Etapy 4.

---

## Etapa 4 — Living World

**Stav: PLANNED — po data-quality/runtime gate Etapy 3.**

**Cíl:** z technologií ověřených v Etapě 2 a z datově připraveného Elwynn Forest z Etapy 3 vytvořit první skutečně komplexní dlouhodobě žijící oblast.

Etapa 4 bude rozvíjet zejména:

- populace a dlouhodobé population pressures;
- zdroje a jejich spotřebu/obnovu;
- ekonomiku a pracovní/obchodní vztahy;
- persistentní relationships mezi agenty;
- dynamické faction relations, konflikty, spolupráci, expanzi a ústup;
- přesuny faction populations/coalitions mezi semantic locations podle skutečných potřeb, hrozeb a příležitostí;
- problémy vznikající z world state místo z pevně napsané quest sequence;
- LLM-generované, serverem validované dynamické questy navázané na tyto skutečné problémy;
- důsledky hráčových akcí, které se vrací do economy/faction/population/memory/world state.

### Hráč a frakce — Etapa 4

Právě zde se může rozvinout myšlenka, že hráč není navždy uzamčený do jedné statické sociální vazby jen kvůli původní quest linii.

- AI questy a dlouhodobé akce hráče mohou měnit vztahy/standing k WorldFaction entitám;
- hráč se může postupně dostat od jedné frakce k jiné, pokud to dovolí serverová pravidla a kauzální historie světa;
- přechod nesmí být jednorázový LLM textový trik — musí vycházet z validovaných činů, vztahů, reputation/standing policy a world events;
- cross-faction diplomacie, defection/allegiance change a přijetí hráče jinou frakcí se řeší jako explicitní systémy;
- coalition invariant zůstává zachovaný: jedna coalition obsahuje členy jedné aktuální WorldFaction; změna faction affiliation nejprve reconciliuje starou coalition membership;
- LLM může navrhovat narativ a sociální možnosti, ale samotná faction transition je vždy server-owned a deterministicky validovaná.

**Etapa 4 už nemá být další infrastrukturní projekt. Má skládat existující technologie a opravená data do komplexního světa a nové technické změny přidávat jen tehdy, když je vyžaduje skutečné emergentní chování Elwynn Forest.**

### Původní scénář vlci → farmář

Původní návrh 2.14 používal jako ilustraci `individual wolf needs → coalition approach → per-member MOVE_TO/combat → livestock attack → LIVESTOCK_KILLED → farmer Perception/Memory → PROTECT_HOME / REQUEST_HELP → validated action/player task`. Tento konkrétní propojený příběh ani nový event/Goal/Action nejsou podmínkou uzavření Etapy 2: 2.14 byl uzavřen jako agregátní POC. Scénář zůstává návrhovým příkladem pro budoucí Living World, ne tvrzením o již implementovaném chování.

Etapa 4 má využít již ověřené identity, threading, lifecycle, action ownership a LLM safety boundary a skládat je s daty připravenými v Etapě 3.


## Další postup a otevřený hardening

### Nejbližší acceptance gate — 3.0–3.1

1. Definovat authoritative Elwynn scope a reprodukovatelný world DB export podle [3.0](#30-scope-a-source-of-truth).
2. Verzovat census manifest, klasifikaci a coverage report podle [3.1](#31-kompletní-census-npc-a-creature-spawnů); žádný spawn nezmizí jen proto, že není AI-enabled.
3. Pokračovat 3.2 sémantické lokace → 3.3 frakce → 3.4 same-faction coalition rules → 3.5 presence/movement → 3.6 DB cleanup a [Definition of Done Etapy 3](#etapa-3--definition-of-done).
4. Po uzavření Etapy 3 skládat Living World v Etapě 4.

### Odložené a podmíněné milníky

- [ ] 2.12F4C — bounded/indexed runtime at world scale (O(1) spawn index, remove recurring full-registry scans) - **DEFERRED, ne blocker pro pokračování nad Elwynn**; povinné před rozšířením na další lokace/eventual full-world (2.12F4D).
- [ ] 2.12F4D — global bootstrap/runtime proof (plná `ObserveOnly` populace, vanilla/script chování beze změny, bounded work) - až po 2.12F4C.
- [ ] 2.12G4 — roles/leadership pouze pokud G2/G3 prokáže potřebu.
- [ ] 2.15 — remaining diagnostics/scale hardening needed by measured runtime behavior.

### Průběžný vývojářský hardening

- [ ] Debugger/core dump workflow.
- [ ] Přesný extraction dokument.
- [ ] CUDA compute smoke test.
- [ ] Metrics backend/dashboard runtime evidence pro 2.9D.
- [ ] Nahradit/hardenovat ruční V2 JSON parser před external/LLM execution.
- [ ] Zúžit external DecisionContext privacy boundary (`spawn_id`).
- [ ] Centralizovat semantic identity helper pro širší multi-agent memory scénáře.
- [ ] Sjednotit starší action cancellation paths přes strukturovaný `ActionCompletion`.
- [ ] Optimalizovat fast registry/materialization scan před velkou background populací.
- [ ] Optimalizovat full-sort coarse selection před velkou populací.
- [ ] Produkční hardening historických AIWorld SQL migrací.

### Dříve evidované neblokující group P3

Převzaté otevřené body z implementační historie; před realizací ověřit jejich relevanci vůči aktuálnímu kódu:

- [ ] guard proti `uint64` overflow při `_nextGroupId + 1`;
- [ ] failed smoke-test path má udělat best-effort cleanup částečně vytvořené test group;
- [ ] stale group-scheduler entry cleanup po dissolve (dříve evidováno v README);
- [ ] historická dev-specific/destructive migration cesta před produkčním schema upgrade hardeningem.

### Historie dokončeného pořadí 2.12–2.14

<details>
<summary>Rozbalit dokončené kroky a jejich návaznost</summary>

1. [x] 2.12F3 static/build/runtime closure.
2. [x] **2.12F4A — ControlMode foundation (`ObserveOnly` vs `AIWorldControlled`, hard-gated na decision/routine/group/action cestách, existing 4 → `AIWorldControlled`, default = `ObserveOnly`).**
3. [x] **2.12F4A2 — TrinityCore-aligned Agent identity (`AgentId == SpawnId` pro persistentní non-instance Creature agenty, migrace existujících 4 + navazujících group/memory FK, před bulk bootstrapem v 2.12F4B).**
4. [x] **2.12F4B — global spawn reconciliation (non-instance `world.creature` ↔ `ai_agents` bidirectional, fail-closed na smazané spawny, deterministická `AgentType` provenance, no ghosts). Runtime-ověřeno nad plnou světovou populací (`128849`, `PERFORMANCE FAIL` bez scale hardeningu) i scoped nad Elwynn.**
5. [x] **2.12F4B2 — scoped rollout proof (Elwynn, `zoneId=12`) - `3540` eligible `AgentRecord`ů, `ObserveOnly`, identity/scope/idempotence `PASS`.**
6. [x] **2.12F4B3 — scoped Control activation (Elwynn) - `3540 / 3540 AIWorldControlled`, fail-closed whole-zone + atomická DB promotion, decision/needs/perception/action runtime `PASS`.**
7. [x] 2.12G1 — second real coalition profile přes stejnou generic pipeline (nad reálnou reconciled Elwynn populací z 2.12F4B2/F4B3).
8. [x] 2.12G2/G2R — generic ROAM včetně preemption/leave/dissolve lifecycle closure.
9. [x] 2.12G3A — pure HUNT DTO a explicitní target provenance contract.
10. [x] 2.12G3B — pure HUNT intent/projector a pure smoke testy.
11. [x] 2.12G3C1 — autoritativní HUNT approach validation contract.
12. [x] 2.12G3C2 — produkční observation/dispatch wiring, ownership/preemption, lifecycle stop na invalid target (CLOSED / STATIC + BUILD + START PASS).
13. [x] 2.12G3D1 — neinvazivní live approach runtime proof (target-aware ownership identity, `AIWorld.TestObserveActiveHuntAgentId`) - POSITIVE LIVE APPROACH PROOF: PASS.
14. [x] fix(ai-world): retain HUNT ownership after approach arrival - post-ARRIVED redispatch loop found by G3D1's own live proof, CLOSED.
15. [x] 2.12G3D — produkční skupinový HUNT combat (`ActionType::Attack`, melee damage, chase, `TARGET_DEFEATED`, phantom-FLEE_DANGER fix, stale chase cleanup) - live-confirmed PASS v reálném skupinovém boji.
16. [x] 2.12G3 lifecycle closure — Approaching/AtTarget/Engaging bezpečně obsloužené přes všech šest ukončujících událostí (PREEMPTED_BY_GOAL/STOPPED_BY_LIFECYCLE/STOPPED_BY_MEMBERSHIP_AMBIGUITY/STOPPED_BY_TARGET_INVALID/PREEMPTED_BY_REGROUP/TARGET_DEFEATED) - STATIC repaired, cumulatively BUILD-verified.
17. [x] 2.13A — actual local LLM inference path.
18. [x] 2.13B — structured `QuestProposal` + authoritative validation.
19. [x] 2.13C1 — pure dynamic quest lifecycle domain.
20. [x] 2.13C2 — registry ownership / validated offer handoff.
21. [x] 2.13C3 — authoritative player accept boundary.
22. [x] 2.13C4 — visible player-facing offer + progress (STATIC + BUILD + RUNTIME PASS).
23. [x] 2.13C5 — turn-in / completion / money reward (STATIC + BUILD + UNIT + RUNTIME PASS).
24. [x] 2.13C6 — quest outcome → WorldEvent / NPC memory/problem feedback (A/B1/B2/B3/C/D all CLOSED — STATIC + BUILD + UNIT 253/253 + RUNTIME PASS).
25. [x] 2.13D — `WORLD → NPC → LLM → PLAYER → WORLD` final end-to-end closure gate (restart/reconnect semantics + negative failure-mode aggregation runtime-tested and confirmed; 2.13 CLOSED).
26. [x] 2.14 — final Etapa 2 POC / aggregate integration gate (real WolfLoose coalition HUNT → per-member ActionSystem validation → real TrinityCore movement/combat → TARGET_DEFEATED, RUNTIME PASS; Etapa 2 CLOSED / POC COMPLETE).

</details>


## Development / verification workflow

Pro C++ AIWorld změny:

```bash
git checkout ai-world
git pull --ff-only origin ai-world
git log -1 --oneline
make build
make restart-world
make world-logs
```

Při compiler failure řešit nejdřív první compiler error block, ne následnou kaskádu.

Pro Python `ai-server` změny:

```bash
docker compose -f compose.yml -f compose.dev.yml up -d --build ai-server
make restart-world
make logs
```

Debug AIWorld používat přes `TC_LOG_DEBUG("ai.world", ...)`; DEBUG evidence hledat v `runtime/logs/Server.log`.

Po runtime proof vracet one-shot/test flags na default `0`/disabled. Destruktivní DB reset není standardní testovací krok.

---

Kompletní standardní build/test gate a vývojové prostředí: [README_DEV.md](README_DEV.md).
