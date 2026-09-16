# Elwynn Census Coverage — permanent baseline

## Census disposition

- Raw `zoneId = 12` census: **3533** spawns
- Permanent `INCLUDED`: **1863** spawns
- `EXCLUDED_EVENT`: **1670** spawns
- `REVIEW_EVENT`: **0** spawns
- Permanent CreatureEntry templates: **182**

Positive `game_event_creature.eventEntry` rows are excluded.
Negative-only event relations remain in the permanent baseline.
Quest-giver status does not affect category or participation.

## Permanent population categories

| Category | Templates | Spawns |
|---|---:|---:|
| CIVILIAN | 46 | 55 |
| GUARD | 11 | 56 |
| HOSTILE_HUMANOID | 32 | 658 |
| MERCHANT_VENDOR | 26 | 26 |
| PREDATOR | 10 | 378 |
| PREY_FAUNA | 26 | 646 |
| SPECIAL_SCRIPTED | 1 | 4 |
| TRAINER | 23 | 23 |
| TRAVELER | 2 | 2 |
| WORKER_FARMER | 5 | 15 |

## Participation modes

| Mode | Permanent spawns |
|---|---:|
| FULL_AGENT | 1213 |
| LIGHTWEIGHT_BACKGROUND | 646 |
| VANILLA_ONLY | 4 |

## Manual review

Templates requiring explicit semantic review: **5**.

- `1949` Servant of Azora: Servant of Azora: permanent humanoid but likely special-purpose population; confirm role.
- `6172` Henze Faulk: Henze Faulk: permanent humanoid with faction template 123; confirm semantic role.
- `6774` Falkhaan Isenstrider: Falkhaan Isenstrider: permanent humanoid; confirm semantic role.
- `10616` Supervisor Raelen: Supervisor Raelen: classified worker supervisor; confirm Eastvale work role.
- `14388` Rogue Black Drake: Rogue Black Drake: permanent dragonkin; confirm whether FULL_AGENT predator is desired.

## Coverage invariant

- Final spawn-level rows: **3533 / 3533**
- Explicitly excluded event rows: **1670**
- Permanent rows with explicit participation mode: **1863 / 1863**

This is a DRAFT 3.1 classification baseline. It is not runtime verification.
