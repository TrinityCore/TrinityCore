# Elwynn Forest scope

## Status

Etapa 3.0 — authoritative scope definition.

## Dataset

TrinityCore 3.3.5
TDB335.25101

## Authoritative creature scope

Elwynn Forest is selected from the current world DB by:

    creature.zoneId = 12

The scope is not defined by a manually selected coordinate rectangle,
CreatureEntry list, AIWorld ControlMode, faction or NPC classification.

Every creature spawn matching `zoneId = 12` is part of the raw Elwynn
census unless a future explicit, versioned override states otherwise.

## Area breakdown

`areas.csv` records the current observed `areaId` distribution inside
`zoneId = 12`.

Area counts are audit metadata, not the authoritative scope predicate.

## Baseline counts

Historical Etapa 2 runtime evidence used 3540 Elwynn creature spawns.

The current count must always be regenerated from the world DB.
A hardcoded spawn count is not used to define membership in Elwynn.

## Overrides

No scope overrides are currently defined.

Any future exclusion or inclusion override must be versioned and contain
an explicit reason.
