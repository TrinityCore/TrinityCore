#!/usr/bin/env python3
"""Generate world.ai_agent_type_entry_defaults from the Elwynn census.

AgentType identity fix (AIWorld_Current_Roadmap.md, Etapa 3): AgentTypeCatalog
(src/server/game/AIWorld/Agent/AgentTypeCatalog.h) is the single runtime
source of truth for CreatureEntry -> AgentType, replacing the old npcflag-only
DeriveCreatureAgentType() heuristic. Its backing world DB table is generated
here from data/elwynn/census/template_classification.csv's own
primary_category column - do not hand-edit the generated SQL migration;
regenerate it from that CSV if a category or the mapping below changes.

Mirrors the shape of the existing world_faction_assignments.csv ->
ai_world_faction_entry_defaults migration (sql/updates/world/3.3.5/
2026_09_16_00_world.sql) - CREATE TABLE IF NOT EXISTS, then DELETE + bulk
INSERT keyed by creature_entry.
"""
from pathlib import Path
import argparse
import csv

# Must stay in sync with src/server/game/AIWorld/Agent/AgentType.h.
AGENT_TYPE_VALUES = {
    "Civilian": 0,
    "Guard": 1,
    "Merchant": 2,
    "Unclassified": 4,
    "Combatant": 5,
    "Predator": 6,
    "Prey": 7,
}

# primary_category (data/elwynn/census/template_classification.csv) -> AgentType.
# SPECIAL_SCRIPTED (spirit healer/guide, 4 spawns) stays Unclassified -
# fail-closed, never guessed, the same discipline AgentTypeCatalog::Resolve()
# itself applies to any entry absent from the table.
CATEGORY_TO_AGENT_TYPE = {
    "CIVILIAN": "Civilian",
    "TRAINER": "Civilian",
    "WORKER_FARMER": "Civilian",
    "TRAVELER": "Civilian",
    "GUARD": "Guard",
    "MERCHANT_VENDOR": "Merchant",
    "COMBATANT": "Combatant",
    "PREDATOR": "Predator",
    "PREY_FAUNA": "Prey",
    "SPECIAL_SCRIPTED": "Unclassified",
}

HEADER = """-- AI AgentType per-CreatureEntry defaults (AIWorld_Current_Roadmap.md,
-- Etapa 3 - AgentType identity fix). Generated from
-- data/elwynn/census/template_classification.csv's own primary_category
-- column (see tools/elwynn/build_agent_type_defaults.py) - the versioned,
-- reviewed source of truth for these {count} permanent Elwynn creature
-- template assignments. Do not hand-edit this table's content; regenerate
-- it from that CSV if the classification changes.
--
-- AgentTypeCatalog::Resolve() (src/server/game/AIWorld/Agent/) falls back
-- to 4 (Unclassified) for any creature_entry not present here, so an
-- explicit agent_type = 4 row below (SPECIAL_SCRIPTED) is functionally
-- redundant with that fallback - included anyway so every one of the
-- {count} accepted template assignments has an explicit, auditable row,
-- matching template_classification.csv's own row count.
CREATE TABLE IF NOT EXISTS `ai_agent_type_entry_defaults` (
    `creature_entry` INT UNSIGNED NOT NULL,
    `agent_type` TINYINT UNSIGNED NOT NULL,
    PRIMARY KEY (`creature_entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_agent_type_entry_defaults`;
INSERT INTO `ai_agent_type_entry_defaults` (`creature_entry`, `agent_type`) VALUES
"""

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "input",
        nargs="?",
        default="data/elwynn/census/template_classification.csv",
    )
    parser.add_argument(
        "output",
        nargs="?",
        default="sql/updates/world/3.3.5/2026_09_19_00_world.sql",
    )
    args = parser.parse_args()

    with Path(args.input).open(newline="", encoding="utf-8") as f:
        rows = list(csv.DictReader(f))

    values = []
    for row in rows:
        entry = int(row["entry"])
        category = row["primary_category"]
        if category not in CATEGORY_TO_AGENT_TYPE:
            raise SystemExit(
                f"ERROR: CreatureEntry {entry}: unmapped primary_category={category!r} "
                "- add it to CATEGORY_TO_AGENT_TYPE before generating."
            )
        agent_type = AGENT_TYPE_VALUES[CATEGORY_TO_AGENT_TYPE[category]]
        values.append((entry, agent_type))

    values.sort(key=lambda v: v[0])

    lines = [HEADER.format(count=len(values)).rstrip("\n")]
    for i, (entry, agent_type) in enumerate(values):
        suffix = "," if i < len(values) - 1 else ";"
        lines.append(f"({entry}, {agent_type}){suffix}")

    Path(args.output).write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {len(values)} rows to {args.output}")

if __name__ == "__main__":
    main()
