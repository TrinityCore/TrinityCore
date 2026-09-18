#!/usr/bin/env python3
"""Generate world.ai_spawn_participation_defaults from the Elwynn census.

Runtime participation/scope boundary fix (AIWorld_Current_Roadmap.md, Etapa
3): AIWorldMgr::RunSpawnReconciliation() reconciled against the RAW zoneId=12
creature census (3533 spawns) instead of the curated permanent census (1863
spawns) - EXCLUDED_EVENT spawns (1670, event-gated) could silently become
permanent AgentRecords. SpawnParticipationCatalog (src/server/game/AIWorld/
Reconciliation/SpawnParticipationCatalog.h) is the runtime fix; this script
generates its backing world DB table from data/elwynn/census/
spawn_classification.csv's own participation_mode column - the versioned,
reviewed source of truth. Do not hand-edit the generated SQL migration;
regenerate it from that CSV if the classification changes.

Unlike build_agent_type_defaults.py (keyed by CreatureEntry), this is keyed
by spawn_id: participation is a spawn-level distinction, not an entry-level
one (the same CreatureEntry can have some spawns permanent and others
event-gated).

Mirrors the shape of the existing ai_agent_type_entry_defaults migration
(sql/updates/world/3.3.5/2026_09_19_00_world.sql) - CREATE TABLE IF NOT
EXISTS, then DELETE + bulk INSERT, this time keyed by spawn_id.
"""
from pathlib import Path
import argparse
import csv

# Must stay in sync with src/server/game/AIWorld/Reconciliation/SpawnParticipationMode.h.
PARTICIPATION_MODE_VALUES = {
    "FULL_AGENT": 0,
    "LIGHTWEIGHT_BACKGROUND": 1,
    "VANILLA_ONLY": 2,
    "EXCLUDED": 3,
}

HEADER = """-- AI spawn participation defaults (AIWorld_Current_Roadmap.md, Etapa 3
-- - runtime participation/scope boundary fix). Generated from
-- data/elwynn/census/spawn_classification.csv's own participation_mode
-- column (see tools/elwynn/build_agent_participation_defaults.py) - the
-- versioned, reviewed source of truth for these {count} zoneId=12 spawns
-- (both the 1863 permanent census spawns and the 1670 EXCLUDED_EVENT
-- spawns). Do not hand-edit this table's content; regenerate it from that
-- CSV if the classification changes.
--
-- Keyed by spawn_id (creature.guid), NOT creature_entry - unlike
-- ai_agent_type_entry_defaults/ai_world_faction_entry_defaults,
-- participation is a spawn-level distinction (the same CreatureEntry can
-- have some spawns permanent and others event-gated).
--
-- SpawnParticipationCatalog::Resolve() (src/server/game/AIWorld/
-- Reconciliation/) falls back to 3 (Excluded) for any spawn_id not present
-- here - the OPPOSITE fail-closed direction from WorldFactionCatalog/
-- AgentTypeCatalog (which fall back to a harmless "unknown" value): here,
-- "no data" must mean "never treat this as a permanent agent". Every
-- EXCLUDED row is included anyway so every one of the {count} spawns has an
-- explicit, auditable row, matching spawn_classification.csv's own row
-- count.
CREATE TABLE IF NOT EXISTS `ai_spawn_participation_defaults` (
    `spawn_id` BIGINT UNSIGNED NOT NULL,
    `participation_mode` TINYINT UNSIGNED NOT NULL,
    PRIMARY KEY (`spawn_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_spawn_participation_defaults`;
INSERT INTO `ai_spawn_participation_defaults` (`spawn_id`, `participation_mode`) VALUES
"""

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "input",
        nargs="?",
        default="data/elwynn/census/spawn_classification.csv",
    )
    parser.add_argument(
        "output",
        nargs="?",
        default="sql/updates/world/3.3.5/2026_09_19_01_world.sql",
    )
    args = parser.parse_args()

    with Path(args.input).open(newline="", encoding="utf-8") as f:
        rows = list(csv.DictReader(f))

    values = []
    for row in rows:
        spawn_id = int(row["spawn_id"])
        mode = row["participation_mode"]
        if mode not in PARTICIPATION_MODE_VALUES:
            raise SystemExit(
                f"ERROR: spawn_id {spawn_id}: unmapped participation_mode={mode!r} "
                "- add it to PARTICIPATION_MODE_VALUES before generating."
            )
        values.append((spawn_id, PARTICIPATION_MODE_VALUES[mode]))

    values.sort(key=lambda v: v[0])

    lines = [HEADER.format(count=len(values)).rstrip("\n")]
    for i, (spawn_id, mode) in enumerate(values):
        suffix = "," if i < len(values) - 1 else ";"
        lines.append(f"({spawn_id}, {mode}){suffix}")

    Path(args.output).write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {len(values)} rows to {args.output}")

if __name__ == "__main__":
    main()
