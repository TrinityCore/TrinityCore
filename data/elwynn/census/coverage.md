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
| CIVILIAN | 53 | 275 |
| COMBATANT | 25 | 438 |
| GUARD | 11 | 56 |
| MERCHANT_VENDOR | 26 | 26 |
| PREDATOR | 10 | 378 |
| PREY_FAUNA | 26 | 646 |
| SPECIAL_SCRIPTED | 1 | 4 |
| TRAINER | 23 | 23 |
| TRAVELER | 2 | 2 |
| WORKER_FARMER | 5 | 15 |

## Identity status

`unique_named` (YES/NO) stays a simple boolean derived from category and
spawn count. `identity_status` separates the identity axis from the
physical/population axis so named-but-multi-spawn templates are not lost:

| Identity status | Templates | Spawns |
|---|---:|---:|
| GENERIC | 61 | 1725 |
| NAMED_MULTI_SPAWN | 3 | 17 |
| TECHNICAL | 1 | 4 |
| UNIQUE_NAMED | 117 | 117 |

## Participation modes

| Mode | Permanent spawns |
|---|---:|
| FULL_AGENT | 1213 |
| LIGHTWEIGHT_BACKGROUND | 646 |
| VANILLA_ONLY | 4 |

## Manual review

Templates requiring explicit semantic review: **0**.


## Resolved manual decisions

Templates explicitly accepted after manual review: **13**.

- `61` Thuros Lightfingers: Named template (Thuros Lightfingers) with 8 permanent spawns; unique_named stays NO because the entity is not unique in the census, flagged identity_status=NAMED_MULTI_SPAWN for later world-data cleanup.
- `100` Gruff Swiftbite: Named template (Gruff Swiftbite) with 5 permanent spawns; unique_named stays NO because the entity is not unique in the census, flagged identity_status=NAMED_MULTI_SPAWN for later world-data cleanup.
- `330` Princess: Single-spawn PREY_FAUNA template with an individual name (Princess); identity audit overrides the category-default unique_named=NO to YES because physical type must not determine identity.
- `471` Mother Fang: Single-spawn PREDATOR template with an individual name (Mother Fang); identity audit overrides the category-default unique_named=NO to YES because physical type must not determine identity.
- `472` Fedfennel: Named template (Fedfennel) with 4 permanent spawns; unique_named stays NO because the entity is not unique in the census, flagged identity_status=NAMED_MULTI_SPAWN for later world-data cleanup.
- `1949` Servant of Azora: Accepted as normal Alliance-aligned civilian for 3.1; final faction assignment belongs to 3.3.
- `6172` Henze Faulk: Dead quest NPC accepted as normal Alliance-aligned civilian for 3.1; quest role is ignored and final faction assignment belongs to 3.3.
- `6774` Falkhaan Isenstrider: Accepted as normal Alliance-aligned civilian for 3.1; final faction assignment belongs to 3.3.
- `6846` Defias Dockmaster: Single-spawn template name is a generic role title (Defias Dockmaster), not a personal name; identity audit overrides the single-spawn default unique_named=YES to NO.
- `10616` Supervisor Raelen: Accepted as Alliance-aligned worker/supervisor for 3.1; final faction assignment belongs to 3.3.
- `14388` Rogue Black Drake: Accepted as PREDATOR/beast for 3.1; underlying placement anomaly is deferred.
- `14390` Expeditionary Mountaineer: Single-spawn template name is a generic archetype title (Expeditionary Mountaineer), not a personal name; identity audit overrides the single-spawn default unique_named=YES to NO.
- `14393` Expeditionary Priest: Single-spawn template name is a generic archetype title (Expeditionary Priest), not a personal name; identity audit overrides the single-spawn default unique_named=YES to NO.

## Coverage invariant

- Final spawn-level rows: **3533 / 3533**
- Explicitly excluded event rows: **1670**
- Permanent rows with explicit participation mode: **1863 / 1863**

This is a DRAFT 3.1 classification baseline. It is not runtime verification.
