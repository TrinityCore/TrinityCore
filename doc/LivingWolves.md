# Living wolves — first runtime pilot

The implementation is limited to AIWorld-controlled creatures matching
`AIWorld.WolfGroupCreatureEntry` and the WolfLoose faction. The deployment
configuration uses entry **69 (Diseased Timber Wolf)** and prey entry **525**.
Other species retain their existing behavior. Roaming and hunting still require
membership in a valid WolfLoose group; a lone wolf can defend or flee but does
not acquire prey independently in this pilot.

## Behavior

- Idle packs use the existing path-checked territory roaming (enabled in the
  deployment configuration).
- Hunger grows by 0.003/second of materialized simulation. A hungry member can
  initiate a hunt at 0.65 (about 217 seconds from empty hunger). Satiated members
  do not join a new hunt. Ordinary GET_FOOD no longer interrupts this cohort's
  hunt to look for civilian food locations.
- Healthy hunters continue fighting their prey. An attacked wolf can defend
  against the actual threat, including a player; this does not enable proactive
  hunting of players. Defense is bounded to 30 seconds or 30 yards from its start.
- At 30% health or below, wolves flee. The recovery threshold is above 50% health.
  A short escape also ends an overlong defense; the resolved previous attacker
  can sustain that escape for up to eight seconds after combat cleanup.
- A successful hunt offers a meal only to an engaged participant within five
  yards of the resolved corpse. Eating takes five seconds, with corpse, range,
  line-of-sight and combat revalidation before nutrition is awarded.
- A completed meal clears hunger, then starts twenty seconds of sleep. Danger
  interrupts eating/sleep; interrupted eating grants no nutrition. Completed
  sleep clears fatigue. Group movement becomes eligible again after waking.
- Meals and individual actions are tied to the materialized incarnation and
  cleared on unload/rebind. They are not persisted across a server restart.

## Configuration

`AIWorld.LivingWolvesEnabled = 1` is enabled in `deploy/worldserver.conf`; the
upstream-style `worldserver.conf.dist` retains a default of `0`. The existing
WolfGroupAutoFormation, CoalitionMaintenance, GroupCoordination and
WolfGroupHuntEnabled settings must remain enabled. WolfGroupRoamEnabled is now
also enabled in the deployment configuration. Apply configuration through the
project's normal render/build/restart workflow; editing the tracked file alone
does not alter a running server.

## Automated verification

`tests/game/LivingWolf.cpp` is included in the normal Catch2 suite. It can also
exercise the real ActionSystem and policy without a full server build:

```bash
mkdir -p runtime
g++ -std=c++20 -DAIWORLD_STANDALONE_TEST \
  -Isrc/common -Isrc/common/Utilities \
  -Isrc/server/game/Entities/Object -Isrc/server/game/AIWorld \
  tests/game/LivingWolf.cpp \
  src/server/game/AIWorld/Action/ActionSystem.cpp \
  src/server/game/AIWorld/Action/ArrivalTolerance.cpp \
  -o runtime/living-wolf-tests
./runtime/living-wolf-tests
```

Local result (2026-09-22): MSVC compiled and ran the standalone test successfully,
44 checks passed. This covers thresholds/hysteresis, timers, defense authority,
control mode, stale goal identity, movement conflicts, corpse identity,
combat/distance/LOS meal rejection, and rest validation. It does **not** exercise
live TrinityCore movement, animation, group formation, or the manager lifecycle.
Full server CMake configuration is blocked locally by missing Boost >= 1.78.

## Required runtime acceptance (pending)

1. Build the server and run the full test suite using README_DEV's normal gate.
2. Observe a materialized entry-69 pack with valid prey nearby for at least five
   minutes: territory movement, hungry hunt, corpse feeding, sleep, then movement.
3. Confirm `AI living wolf ... action=FEED`, `meal=CONSUMED`, and
   `action=WILDLIFE_REST` in DEBUG-level `ai.world` logging and compare with the
   client/telemetry. Verify the animal model actually renders the animations.
4. Attack a healthy wolf: it defends. Lower its health below 30%: its owned chase
   ends and it flees. Stop attacking: it eventually becomes eligible for its
   group's ordinary movement again.
5. Interrupt feeding and sleeping with an attack. No meal credit on interrupted
   feeding; no residual sleep pose while defending/fleeing.
6. Despawn/unload the prey during feeding and unload/reload the wolf during an
   individual action. No delayed nutrition or stale action may survive.
7. Check another creature species and ObserveOnly agents retain their behavior.

No runtime PASS or deployment is claimed by the local unit-test result.

## Diagnosing `.aiworld group status`

The status command now uses brace-aware formatting, so it prints actual IDs
and values instead of literal `{}`. It also prints the selected creature's
entry/spawn, control mode, health, hunger, current goal/action, and a read-only
snapshot of WolfLoose formation eligibility.

- `ENTRY_MISMATCH`: compare `entry` with `expectedEntry`. In the pilot, entry 525
  is the configured hunt target; only entry 69 is a WolfLoose member candidate.
- `OBSERVE_ONLY`: the agent is registered but AIWorld does not control it.
- `FACTION_MISMATCH`: its AI world faction does not match the wolf profile.
- `ALREADY_IN_LOOSE_GROUP`: the membership lines below identify that group.
- `AUTOFORMATION_DISABLED` / `AIWORLD_DISABLED`: a required runtime setting is off.
- `MEMBER_RESERVED`, `PROFILE_FORMATION_IN_FLIGHT`, `GLOBAL_FORMATION_BUDGET_BUSY`:
  a formation operation is pending; check again after the next few passes.
- `NO_FORMATION_PROPOSAL`: the production selector cannot currently form any
  eligible WolfLoose group. The nearby count includes the selected agent and
  excludes existing Loose members and reserved candidates.
- `IN_CURRENT_FORMATION_PROPOSAL` / `NOT_IN_CURRENT_FORMATION_PROPOSAL`: the
  selected agent is/is not included in the selector's first current proposal.
  This is not confirmation of a completed database join.

Nearby counts are shown only when proposal evaluation was reached. Radius and
minimum member count come from the running server, not hard-coded assumptions.
The command does not create groups, force membership, or load grids. An absent
group alone is not proof of a behavior bug. Capture the entire status output
for the same selected wolf when investigating a failed formation.
