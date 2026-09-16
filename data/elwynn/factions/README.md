# Elwynn faction data

Tento adresář je versionovaný source of truth pro faction data Elwynn Forest.

Projekt odděluje dvě různé vrstvy:

```text
AI WorldFactionId
    = sociální/politická příslušnost pro vztahy, coalition eligibility,
      holdings a budoucí Living World logiku

TrinityCore Faction/FactionTemplate/FactionGroup DBC
    = gameplay reaction/combat compatibility a případná player reputation
```

`WorldFactionId` není `Faction.dbc` ID ani `FactionTemplate.dbc` ID.

## Aktuální stav

Permanentní Elwynn census má 182 creature templates / 1863 permanentních spawnů.
`world_faction_assignments.csv` má explicitní a přijaté přiřazení pro všech 182 templates.

Aktuální WorldFaction katalog je v `world_factions.csv`:

```text
1 STORMWIND_ALLIANCE
2 DEFIAS_BROTHERHOOD
3 RIVERPAW_GNOLLS
4 ELWYNN_KOBOLDS
5 ELWYNN_MURLOCS
6 ELWYNN_WOLVES
```

`NEUTRAL_UNAFFILIATED` není samostatná WorldFaction entita. Je to explicitní stav bez sociální/politické affiliation a při runtime reprezentaci odpovídá `WorldFactionId = 0` / none.

`STORMWIND_ALLIANCE` používá existující vanilla player-reputation vrstvu.
`DEFIAS_BROTHERHOOD`, `RIVERPAW_GNOLLS`, `ELWYNN_KOBOLDS` a `ELWYNN_MURLOCS` jsou kandidáti pro custom player-visible reputation.
`ELWYNN_WOLVES` je ecological/social WorldFaction pro coalition a living-world logiku a nemá mít player-visible reputation.

## Soubory

- `world_factions.csv` — stabilní katalog AI WorldFaction entit (`WorldFactionId`, key, typ, reputation policy).
- `world_faction_assignments.csv` — mapování permanentních Elwynn creature templates na WorldFaction key nebo `NEUTRAL_UNAFFILIATED`; obsahuje také aktuální TrinityCore `FactionTemplate` pro audit.
- `factions.csv` — plánované custom řádky pro `Faction.dbc`.
- `faction_templates.csv` — plánované custom řádky pro `FactionTemplate.dbc`; jeho `id` je ID používané v `creature_template.faction` nebo budoucím override mechanismu.
- `faction_groups.csv` — custom `FactionGroup.dbc` bitmasky pouze pokud se prokáže potřeba nad rámec vanilla groups.

## DBC stav

`factions.csv`, `faction_templates.csv` a `faction_groups.csv` jsou stále DRAFT data pro klient/server DBC vrstvu.
Současné rozsahy `1200+` / `2300+` jsou pouze placeholdery a nesmí být použity jako finální runtime ID, dokud je generátor neověří proti konkrétním vanilla 3.3.5a `Faction.dbc` / `FactionTemplate.dbc`.

Generátor `tools/dbc/build_elwynn_factions.py` zatím není implementovaný. Až bude hotový, vezme jako vstup vanilla DBC z `runtime/dbc-base/` a CSV z tohoto adresáře a deterministicky vytvoří server/client DBC výstupy.

Plánovaný workflow:

```text
make dbc-factions   # CSV -> runtime/data/dbc/{Faction,FactionTemplate,FactionGroup}.dbc
make client-patch   # stejné custom DBC -> runtime/client-patch/ + MPQ
make restart-world
```

## Nekomituje se

- vanilla ani vygenerované binární DBC (`runtime/dbc-base/`, `runtime/data/dbc/`),
- výsledný klientský patch/MPQ (`runtime/client-patch/`).

Do Gitu patří pouze čitelné a reprodukovatelné CSV/source soubory a generátor.
