# AIWorld — historical milestone snapshot (2026-08-25)

> Date: 2026-08-25  
> Branch: `ai-world`  
> Code baseline before this documentation commit: `f71f1dca8333a7cfb7c99c7c89fc84872933fb01`

This file preserves the accepted implementation state as of 2026-08-25, after the 2.11 farmer vertical slice and its persistence hardening. It is a historical snapshot, not the current project plan. For current milestone status, implementation history and next gates, use the single [AIWorld roadmap](AIWorld_Current_Roadmap.md).

## Architectural invariant

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
ActionRequest
    ↓
ActionSystem::Validate
    ↓
TrinityCore execution
    └──────────────→ WORLD STATE
```

AI proposes intent. `ActionSystem` validates it. TrinityCore performs world mutation. No AIWorld path may force-load a grid or carry live `Creature*` / `Player*` / `Map*` / `Unit*` across an async boundary.

## 2.10 scheduler / simulation-tier foundation

Accepted foundation used by 2.11:

- 2.10A bounded multi-agent decision admission;
- 2.10B proximity-aware cadence and fairness;
- 2.10C separate world binding (`MATERIALIZED` / `ABSTRACT`) and simulation policy (`NEARBY` / `ACTIVE` / `BACKGROUND` / `ABSTRACT`);
- 2.10D bounded deterministic coarse scheduling seam with staggered phase, no catch-up loop and no force-load.

Important: coarse `BACKGROUND` / `ABSTRACT` scheduling remains a scheduling seam, not a license to execute live gameplay or `/decision` for unloaded agents.

Known non-blocking scheduler scale work remains the all-agent materialization scan and full due-set sort before bounded prefix admission.

## 2.11 persistent farmer — CLOSED / PASS

Test NPC: Pa Maclure, kept as `AgentType::Civilian`; profession/routine behavior is separate from base agent type.

Persistent identity is `AgentId`; runtime `ObjectGuid` is incarnation-local and may change after unload/reload or restart.

### 2.11A — persistent home/work locations

Implementation: `82f9a34a7281f03f4def4c7a04a6be659922def0`

- pure-value `AgentLocation`;
- optional persistent `HomeLocation` / `WorkLocation` on `AgentRecord`;
- nullable DB columns;
- startup-only synchronous load;
- no live TrinityCore object stored in persistence state.

Runtime: Pa Maclure loads with stable persistent identity and home/work locations and can be abstract/materialized without identity loss.

### 2.11B — deterministic routine goal derivation

Feature: `3da1e46...`  
Hardening: `da5c8b3f60f6fc54368b9d32d1ee92e94a282ab9`

- deterministic synthetic-day schedule;
- `GO_TO_WORK` / `GO_HOME` routine goal state;
- `FLEE_DANGER` emergency ownership suppresses routine behavior;
- routine state is runtime-derived and rederived from persistent location + current time rather than persisted as a stale live goal.

Historical scope note: the original roadmap wording used `WORK` / `REST` goals at this stage; the implementation deliberately separated travel/routine-goal identity from later activity actions.

### 2.11C — routine movement through ActionSystem

Feature: `3020c4f8...`  
P2 fix: `4423edc29484f700a6361a029b6601189fa9e55d`

- `GO_TO_WORK` / `GO_HOME` translate to validated `MOVE_TO`;
- active deterministic needs/goals preempt routine action ownership;
- target changes stop obsolete routine movement;
- arrival tolerance prevents repeated `MOVE_TO` spam after reaching the destination;
- movement still executes only through ActionSystem / ActionExecutor / TrinityCore.

### 2.11D — derived WORK / REST activity state

Feature: `def9ee312550...`  
Hardening: `65b2597ebb9cfa0c9c06efb2d75daac0d331c5af`

Runtime-only activity state:

```cpp
enum class RoutineActivityType
{
    Work,
    Rest
};
```

Activity exists only when the actor is materialized, alive, at the correct routine target, owns no competing goal/action and is not moving. Unload, death, travel or ownership takeover clears it. Engine movement is checked authoritatively, not inferred only from AIWorld bookkeeping.

Activity itself is intentionally transient; after restart it is rederived from persistent identity/home/work plus current time and live position.

### 2.11E1 — observable WORK / REST actions

Feature: `2cf7d584049a9385a6926383899685586bf5b062`  
Hardening: `52c5dea7b117d6e11718d98051fdff6e6b16af62`

- `ActionType::Work` / `ActionType::Rest`;
- proposed once on activity transition edge;
- independently validated against routine activity provenance and target position;
- one-shot cosmetic execution only in ActionExecutor;
- explicit terminal `ActionCompletion(Succeeded, Performed)` after execution;
- no economy mutation is allowed from `Started` alone.

Runtime WORK and REST completion lifecycle passed.

### 2.11E2 — persistent economy and WORK reward

Feature: `e43a9b18647693cfb2ec9fc9ef916dcc98ae9aeb`  
Persistent work-window idempotency fix: `d818b600b086fbc69142212771f493a7d29eae1d`  
Monotonic async-write guard: `4ec4b5d0b8051619d7bb0fcfc66b8c7e31b7d8fa`  
Money widened to `uint64` / `BIGINT UNSIGNED`: `2c6d90e729adbb3a57865849eb0d89755c46e475`  
Mutation helper centralization: `e37a7c62c14459478550f7e9751ea4ce2c2fde62`  
Version bump enforced in persistence API: `f71f1dca8333a7cfb7c99c7c89fc84872933fb01`

Persistent economy state:

```cpp
struct AgentEconomyState
{
    uint64 Money = 0;
    uint32 Food = 0;
    uint32 Resource = 0;
    uint64 LastRewardedWorkWindowId = 0;
    uint64 Version = 0;
};
```

Current mutation semantics:

```text
WORK
→ SUCCEEDED / PERFORMED
→ current synthetic work-window id
→ already paid? skip
→ mutate Money + LastRewardedWorkWindowId
→ SaveEconomyState()
→ Version++ inside persistence API
→ one async monotonic UPDATE
```

`REST`, rejected WORK and failed WORK do not earn money. `Food` and `Resource` are persisted scaffolding but are not mutated yet.

The DB update writes money/food/resource/work-window marker/version as one snapshot and is guarded by `economy_version < incomingVersion`, so an older async worker result cannot overwrite a newer snapshot. `SaveEconomyState(AgentId, AgentEconomyState&)` performs the version bump itself, so a real persistence caller cannot forget the monotonic-write invariant.

### 2.11E2 runtime closure

Observed runtime acceptance included:

- first valid WORK completion increments money once;
- persistent money + work-window marker survive world restart;
- later synthetic work windows increment once each;
- targeted same-window restart test: after reward at window `1787680860000`, restart loaded the same money/marker, a second `WORK SUCCEEDED/PERFORMED` occurred in the same window, and no second economy increment was emitted.

Result:

```text
2.11E2 STATIC   PASS
2.11E2 RUNTIME  PASS
P1 = 0
P2 = 0
```

The async DB write remains intentionally fire-and-forget. This prevents world-thread DB blocking but is not an absolute process-crash durability guarantee for a write that has not reached the database yet.

## 2.11 final status

```text
2.11A home/work persistence        CLOSED / PASS
2.11B routine derivation           CLOSED / PASS
2.11C routine movement             CLOSED / PASS
2.11D WORK/REST activity           CLOSED / PASS
2.11E1 validated WORK/REST action  CLOSED / PASS
2.11E2 persistent economy          CLOSED / PASS
```

The farmer vertical slice is complete enough to move on. The implementation intentionally preserves separation between persistent identity, runtime world binding, routine policy, activity state, validated actions and persistent economy.

## NEXT — 2.12A wolf-pack aggregate identity/state

Start 2.12 narrowly with a persistent `CREATURE_GROUP` aggregate value model only.

Target first slice:

- stable aggregate `AgentId`;
- persistent pure-value group state (`Population`, home/territory identity and only the minimum fields required by the slice);
- no live `Creature*` ownership in aggregate state;
- no force-load;
- no combat mutation;
- no `/decision` from ABSTRACT state;
- no materialization policy yet;
- no hunger/resource simulation in the same initial commit unless required for identity persistence.

Subsequent slices should add deterministic ABSTRACT coarse simulation, natural materialization/reconciliation, TrinityCore-owned combat and population reconciliation after member losses.

The intended lifecycle is:

```text
persistent CREATURE_GROUP aggregate
        ↓
ABSTRACT coarse simulation
        ↓
natural TrinityCore materialization
        ↓
validated / vanilla gameplay execution
        ↓
death / world events
        ↓
aggregate reconciliation
        ↓
unload
        ↓
ABSTRACT aggregate
```

The aggregate never directly manipulates live combat state and AIWorld never loads a grid just to simulate it.
