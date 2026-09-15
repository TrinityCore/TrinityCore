# Elwynn custom faction catalog (source of truth)

Tento adresář je versionovaný zdroj pravdy pro vlastní ("custom") faction
záznamy AIWorld pro Elwynn Forest. Neobsahuje a nenahrazuje vanilla
`Faction.dbc` / `FactionTemplate.dbc` / `FactionGroup.dbc` — pouze naše
přidané řádky nad nimi.

Generátor v `tools/dbc/build_elwynn_factions.py` (zatím neimplementováno)
bere jako vstup:

- vanilla `Faction.dbc` / `FactionTemplate.dbc` / `FactionGroup.dbc`
  (v `runtime/dbc-base/`, negitované, uživatel je tam dá sám po extrakci
  klienta),
- CSV soubory v tomto adresáři,

a deterministicky z nich staví custom DBC do `runtime/data/dbc/` (server)
a `runtime/client-patch/` (klient). Binární DBC ani MPQ se do Gitu
necommitují — jen tyto CSV.

## Stav: DRAFT — čeká na census

Řádky níže jsou **ilustrační placeholder**, ne finální přiřazení. Reálný
katalog vzniká až z reprodukovatelného exportu creature spawnů Elwynn
Forestu (roadmap bod 3.2 — export ještě není hotový). ID rozsahy
(1200+ / 2300+) jsou provizorní a generator je před zápisem musí ověřit
proti skutečnému vanilla `Faction.dbc`/`FactionTemplate.dbc` z konkrétní
3.3.5a klientské instalace, aby nekolidovaly s existujícími záznamy.

## Soubory

- `factions.csv` — vlastní `Faction.dbc` záznamy (identita frakce,
  reputation index, parent).
- `faction_templates.csv` — vlastní `FactionTemplate.dbc` záznamy
  (NPC-facing template: faction_group / friend_group / enemy_group).
  `id` zde je totéž ID, které se používá jako `creature_template.faction`
  resp. v budoucí `creature_faction_override.faction`.
- `faction_groups.csv` — vlastní `FactionGroup.dbc` bitmasky, pokud je
  potřeba nová skupina nad rámec vanilla (Alliance/Horde/Monster/...).

## Workflow (až bude generator hotový)

```
make dbc-factions   # CSV -> runtime/data/dbc/{Faction,FactionTemplate,FactionGroup}.dbc
make client-patch   # totéž -> runtime/client-patch/ + MPQ balení
make restart-world
```

## Nekomituje se

- vanilla ani vygenerované binární DBC (`runtime/dbc-base/`,
  `runtime/data/dbc/`),
- výsledný klientský patch/MPQ (`runtime/client-patch/`).

Diff nad těmito CSV zůstává čitelný (`+1203,108,1200,Elwynn Kobolds`)
namísto neprůhledné binární změny.
