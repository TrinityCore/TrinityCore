# Elwynn Census Classification Coverage

## Status

DRAFT automatic proposal for Etapa 3.1. This report does not close 3.1.

## Input coverage

- CreatureEntry rows: 276
- Spawn rows represented by those entries: 3533
- Classified CreatureEntry rows: 276 / 276 (100%)
- High-confidence automatic proposals: 245
- Manual-review rows: 31

## Template categories

| Category | Templates | Spawns |
|---|---:|---:|
| CIVILIAN | 26 | 35 |
| GUARD | 10 | 55 |
| HOSTILE_HUMANOID | 31 | 657 |
| MERCHANT_VENDOR | 29 | 29 |
| PREDATOR | 9 | 375 |
| PREY_FAUNA | 26 | 2093 |
| QUEST_RELATED | 22 | 22 |
| SPECIAL_SCRIPTED | 88 | 216 |
| TRAINER | 29 | 35 |
| TRAVELER | 2 | 2 |
| WORKER_FARMER | 4 | 14 |

## Participation proposal

| Mode | Templates | Spawns |
|---|---:|---:|
| FULL_AGENT | 161 | 1223 |
| LIGHTWEIGHT_BACKGROUND | 24 | 2090 |
| REVIEW_REQUIRED | 4 | 7 |
| VANILLA_ONLY | 87 | 213 |

## Important limitations

- Classification is derived from the exported template census plus deterministic rules.
- `QUEST_RELATED` currently detects questgiver NPC flags; the current CSV does not contain quest-target/reference tables, so quest targets cannot be proven from this file alone.
- `faction_candidate` is only a 3.1 working hint. It is not the final 3.3 custom faction assignment.
- `participation_mode` is a design proposal, not a runtime-verified setting.
- Rows marked `MANUAL_REVIEW` need explicit human review before the census classification can be treated as accepted.
- Spawn-specific exceptions belong in a later `spawn_overrides.csv`; this file only provides template defaults.

## Next acceptance work

1. Review every `MANUAL_REVIEW` row.
2. Add quest-relation evidence from world DB tables before claiming complete quest-related coverage.
3. Create spawn-specific overrides where one CreatureEntry is not semantically uniform.
4. Generate final spawn-level coverage and require every raw spawn to resolve to exactly one accepted classification.
