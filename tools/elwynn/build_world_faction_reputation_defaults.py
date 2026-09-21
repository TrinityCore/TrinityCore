#!/usr/bin/env python3
"""Generate world.ai_world_faction_reputation_defaults - the WorldFactionId
-> Trinity Faction.dbc id mapping the login/allegiance-change ReputationMgr
bridge needs (AIWorld_Current_Roadmap.md, architectural audit 2026-09-21:
TrinityCore's own WorldObject::GetReactionTo()/ReputationMgr stays the sole
gameplay reaction authority - this table only feeds a one-time, explicit
ReputationMgr::ApplyForceReaction() sync on login/allegiance change, never a
per-interaction resolver).

Deliberately does NOT duplicate the DEFIAS/RIVERPAW/KOBOLDS/MURLOCS -> 1201-1204
mapping that data/elwynn/factions/factions.csv already carries in its own
`world_faction` column - that would be a second source of truth for the same
four facts. Instead this script JOINS world_factions.csv (the WorldFaction
catalog) against factions.csv (custom Faction.dbc ids) for those four, and
against the new world_faction_vanilla_reputation.csv for the one vanilla
exception (STORMWIND_ALLIANCE -> the real Stormwind Faction.dbc id, not a
custom one - Stormwind uses the existing vanilla player-reputation layer, see
README.md). ELWYNN_WOLVES has no row in either source and is deliberately
skipped - it is ecological/social only and must never get a player-visible
reputation (README.md's own design note).

The vanilla Stormwind id is cross-checked against the actual base
runtime/dbc-base/Faction.dbc at generation time - never trusted as a bare
constant - mirroring tools/dbc/build_elwynn_factions.py's own "verify
against the real DBC, don't just assume" discipline.
"""
from pathlib import Path
import argparse
import csv
import struct

MAGIC = b"WDBC"
HEADER_FORMAT = "<4sIIII"
HEADER_SIZE = 20
FACTION_FIELD_COUNT = 57
FACTION_RECORD_SIZE = FACTION_FIELD_COUNT * 4

HEADER = """-- AI WorldFactionId -> Trinity Faction.dbc id bridge table
-- (AIWorld_Current_Roadmap.md - login/allegiance-change ReputationMgr
-- bridge). Generated from data/elwynn/factions/factions.csv,
-- world_faction_vanilla_reputation.csv and world_factions.csv (see
-- tools/elwynn/build_world_faction_reputation_defaults.py) - the versioned,
-- reviewed source of truth for these {count} rows. Do not hand-edit this
-- table's content; regenerate it from those CSVs if the mapping changes.
--
-- Deliberately NOT every WorldFaction: ELWYNN_WOLVES has no row (ecological/
-- social only, never player-visible reputation - README.md's own design
-- note). WorldFactionReputationCatalog::TryResolve() returns false for any
-- WorldFactionId not present here - fail-closed, never guessed.
CREATE TABLE IF NOT EXISTS `ai_world_faction_reputation_defaults` (
    `world_faction_id` INT UNSIGNED NOT NULL,
    `faction_id` INT UNSIGNED NOT NULL,
    PRIMARY KEY (`world_faction_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DELETE FROM `ai_world_faction_reputation_defaults`;
INSERT INTO `ai_world_faction_reputation_defaults` (`world_faction_id`, `faction_id`) VALUES
"""

def load_csv_rows(csv_path):
    # factions.csv carries a '#'-prefixed documentation preamble before the
    # real header row (same convention tools/dbc/build_elwynn_factions.py
    # already documents/handles) - filtered out here too.
    with csv_path.open(encoding="utf-8") as f:
        data_lines = [line for line in f if not line.lstrip().startswith("#")]
    return list(csv.DictReader(data_lines))

def verify_vanilla_faction_id_exists(dbc_base_path, faction_id):
    data = dbc_base_path.read_bytes()
    if len(data) < HEADER_SIZE:
        raise SystemExit(f"ERROR: {dbc_base_path}: file too small to be a WDBC file ({len(data)} bytes)")

    magic, record_count, field_count, record_size, string_block_size = struct.unpack_from(HEADER_FORMAT, data, 0)
    if magic != MAGIC:
        raise SystemExit(f"ERROR: {dbc_base_path}: not a WDBC file (magic={magic!r})")
    if field_count != FACTION_FIELD_COUNT or record_size != FACTION_RECORD_SIZE:
        raise SystemExit(
            f"ERROR: {dbc_base_path}: unexpected layout fieldCount={field_count} recordSize={record_size} "
            f"(expected {FACTION_FIELD_COUNT}/{FACTION_RECORD_SIZE})"
        )

    records_end = HEADER_SIZE + record_count * record_size
    records_bytes = data[HEADER_SIZE:records_end]
    if len(records_bytes) != record_count * record_size:
        raise SystemExit(f"ERROR: {dbc_base_path}: truncated file (records shorter than the header claims)")

    for i in range(record_count):
        offset = i * FACTION_RECORD_SIZE
        record_id, = struct.unpack_from("<I", records_bytes, offset)
        if record_id == faction_id:
            return

    raise SystemExit(
        f"ERROR: Faction.dbc id {faction_id} (world_faction_vanilla_reputation.csv) "
        f"does not exist in {dbc_base_path} - refusing to bridge to a nonexistent faction."
    )

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--world-factions", default="data/elwynn/factions/world_factions.csv")
    parser.add_argument("--factions", default="data/elwynn/factions/factions.csv")
    parser.add_argument("--vanilla-reputation", default="data/elwynn/factions/world_faction_vanilla_reputation.csv")
    parser.add_argument("--dbc-base", default="runtime/dbc-base/Faction.dbc")
    parser.add_argument("output", nargs="?", default="sql/updates/world/3.3.5/2026_09_21_02_world.sql")
    args = parser.parse_args()

    with Path(args.world_factions).open(newline="", encoding="utf-8") as f:
        world_factions = list(csv.DictReader(f))

    custom_by_key = {row["world_faction"]: int(row["id"]) for row in load_csv_rows(Path(args.factions))}

    with Path(args.vanilla_reputation).open(newline="", encoding="utf-8") as f:
        vanilla_by_key = {row["world_faction"]: int(row["faction_id"]) for row in csv.DictReader(f)}

    for key, faction_id in vanilla_by_key.items():
        verify_vanilla_faction_id_exists(Path(args.dbc_base), faction_id)

    known_keys = {row["key"] for row in world_factions}
    unknown_custom = set(custom_by_key) - known_keys
    if unknown_custom:
        raise SystemExit(f"ERROR: factions.csv world_faction value(s) not in world_factions.csv: {sorted(unknown_custom)}")
    unknown_vanilla = set(vanilla_by_key) - known_keys
    if unknown_vanilla:
        raise SystemExit(f"ERROR: world_faction_vanilla_reputation.csv world_faction value(s) not in world_factions.csv: {sorted(unknown_vanilla)}")
    overlap = set(custom_by_key) & set(vanilla_by_key)
    if overlap:
        raise SystemExit(f"ERROR: WorldFaction(s) defined in both factions.csv and world_faction_vanilla_reputation.csv: {sorted(overlap)}")

    values = []
    for row in world_factions:
        key = row["key"]
        world_faction_id = int(row["world_faction_id"])
        if key in custom_by_key:
            values.append((world_faction_id, custom_by_key[key]))
        elif key in vanilla_by_key:
            values.append((world_faction_id, vanilla_by_key[key]))
        # else: no player-visible reputation for this WorldFaction (e.g. ELWYNN_WOLVES) - no row emitted.

    values.sort(key=lambda v: v[0])

    lines = [HEADER.format(count=len(values)).rstrip("\n")]
    for i, (world_faction_id, faction_id) in enumerate(values):
        suffix = "," if i < len(values) - 1 else ";"
        lines.append(f"({world_faction_id}, {faction_id}){suffix}")

    Path(args.output).write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Wrote {len(values)} rows to {args.output}")

if __name__ == "__main__":
    main()
