#!/usr/bin/env python3
"""Generate world.ai_world_faction_relations from world_faction_relations.csv.

WorldFactionRelationCatalog vertical slice (AIWorld_Current_Roadmap.md):
the static WorldFaction <-> WorldFaction diplomacy layer, keyed by directed
(from, to) pairs - a bidirectional relationship is expressed as two explicit
CSV rows, never inferred by symmetry (see world_faction_relations.csv's own
header/README). Same-faction Friendly is implicit (WorldFactionRelationCatalog::
Resolve()'s own rule 1) and never stored as a row here. Do not hand-edit the
generated SQL migration; regenerate it from that CSV if the matrix changes.

Mirrors the shape of the existing ai_world_faction_entry_defaults migration
(sql/updates/world/3.3.5/2026_09_19_00_world.sql) - CREATE TABLE IF NOT
EXISTS, then DELETE + bulk INSERT, keyed by (from, to) here.
"""
from pathlib import Path
import argparse
import csv

# Must stay in sync with src/server/game/AIWorld/Faction/WorldFactionRelation.h.
RELATION_VALUES = {
    "NEUTRAL": 0,
    "FRIENDLY": 1,
    "HOSTILE": 2,
}

HEADER = """-- AI WorldFaction diplomacy matrix (AIWorld_Current_Roadmap.md -
-- WorldFactionRelationCatalog vertical slice). Generated from
-- data/elwynn/factions/world_faction_relations.csv (see
-- tools/elwynn/build_world_faction_relations_defaults.py) - the versioned,
-- reviewed source of truth for these {count} directed (from, to) rows. Do
-- not hand-edit this table's content; regenerate it from that CSV if the
-- matrix changes.
--
-- Deliberately directional, never symmetric: a bidirectional relationship
-- (e.g. Stormwind <-> Defias) is two explicit rows, never inferred from
-- one. Same-faction Friendly is never a row here - it is
-- WorldFactionRelationCatalog::Resolve()'s own implicit rule 1, computed
-- without a table lookup. WorldFactionRelationCatalog::Resolve() falls
-- back to Neutral for any (from, to) pair not present here - see that
-- class's own comment and data/elwynn/factions/README.md's "Nevypsaný
-- cross-faction vztah je NEUTRAL" note.
CREATE TABLE IF NOT EXISTS `ai_world_faction_relations` (
    `from_world_faction_id` INT UNSIGNED NOT NULL,
    `to_world_faction_id` INT UNSIGNED NOT NULL,
    `relation` TINYINT UNSIGNED NOT NULL,
    PRIMARY KEY (`from_world_faction_id`, `to_world_faction_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_world_faction_relations`;
INSERT INTO `ai_world_faction_relations` (`from_world_faction_id`, `to_world_faction_id`, `relation`) VALUES
"""

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "input",
        nargs="?",
        default="data/elwynn/factions/world_faction_relations.csv",
    )
    parser.add_argument(
        "output",
        nargs="?",
        default="sql/updates/world/3.3.5/2026_09_20_00_world.sql",
    )
    args = parser.parse_args()

    with Path(args.input).open(newline="", encoding="utf-8") as f:
        rows = list(csv.DictReader(f))

    values = []
    for row in rows:
        from_id = int(row["from_world_faction_id"])
        to_id = int(row["to_world_faction_id"])
        relation = row["relation"]
        if relation not in RELATION_VALUES:
            raise SystemExit(
                f"ERROR: ({from_id}, {to_id}): unmapped relation={relation!r} "
                "- add it to RELATION_VALUES before generating."
            )
        values.append((from_id, to_id, RELATION_VALUES[relation]))

    values.sort(key=lambda v: (v[0], v[1]))

    lines = [HEADER.format(count=len(values)).rstrip("\n")]
    for i, (from_id, to_id, relation) in enumerate(values):
        suffix = "," if i < len(values) - 1 else ";"
        lines.append(f"({from_id}, {to_id}, {relation}){suffix}")

    Path(args.output).write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {len(values)} rows to {args.output}")

if __name__ == "__main__":
    main()
