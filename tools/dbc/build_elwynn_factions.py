#!/usr/bin/env python3
"""Generates runtime/data/dbc/Faction.dbc from data/elwynn/factions/factions.csv.

V1 scope (see data/elwynn/factions/README.md): this script appends the
custom "player reputation" Faction.dbc rows for the AI WorldFactionId
social layer's four player-visible factions (Defias Brotherhood, Riverpaw
Gnolls, Elwynn Kobolds, Elwynn Murlocs). It does NOT touch
FactionTemplate.dbc or FactionGroup.dbc - faction_templates.csv is still
DRAFT/deferred reaction-design data, not a runtime input yet, and
creature_template.faction is not changed by this script. A separate
generator takes that on once the TrinityCore FactionTemplate reaction audit
this directory's README describes is actually done.

Faction.dbc (3.3.5a) is a 57-field, 228-byte-per-record WDBC file - see
src/server/shared/DataStores/DBCStructure.h's own FactionEntry comment and
DBCfmt.h's FactionEntryfmt ("niiiiiiiiiiiiiiiiiiffiissssssssssssssssxxxxxxxxxxxxxxxxxx",
57 characters) for the authoritative field layout this script mirrors byte
for byte:

  field  0        ID                          uint32
  field  1        ReputationIndex             int32
  fields 2-5      ReputationRaceMask[4]       uint32
  fields 6-9      ReputationClassMask[4]      uint32
  fields 10-13    ReputationBase[4]           int32
  fields 14-17    ReputationFlags[4]          uint32
  field  18       ParentFactionID             uint32
  fields 19-20    ParentFactionMod[2]         float
  fields 21-22    ParentFactionCap[2]         uint32
  fields 23-38    Name_lang[16]               uint32 (string block offsets)
  field  39       Name_lang_mask              uint32
  fields 40-55    Description_lang[16]        uint32 (string block offsets)
  field  56       Description_lang_mask       uint32

TrinityCore's own server-side FactionEntry struct never reads fields 39/
40-55/56 (FactionEntryfmt marks them 'x' = skipped) - this script still
writes valid-shaped bytes for them (zeroed) so the file stays a structurally
correct WDBC record for any OTHER consumer (a future client-side MPQ patch
step, not implemented here - see data/elwynn/factions/README.md's own
"DBC stav" section). Only RaceMask/ClassMask/Base/Flags SLOT 0 is populated
per row: ReputationMgr::GetFactionDataIndexForRaceAndClass() (src/server/
game/Reputation/ReputationMgr.cpp) requires a slot's own RaceMask to
directly intersect the player's race bit to ever select that slot at all -
an all-zero RaceMask/ClassMask slot NEVER matches any player, so "available
to every playable race" means RaceMask[0] = RACEMASK_ALL_PLAYABLE
(SharedDefines.h), not 0.
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from pathlib import Path

MAGIC = b"WDBC"
HEADER_FORMAT = "<4sIIII"
HEADER_SIZE = 20

FIELD_COUNT = 57
RECORD_SIZE = FIELD_COUNT * 4  # 228 bytes - see this file's own module docstring
LOCALE_STRING_COLUMNS = 16

# SharedDefines.h RACEMASK_ALL_PLAYABLE (races 1 Human, 2 Orc, 3 Dwarf,
# 4 NightElf, 5 Undead, 6 Tauren, 7 Gnome, 8 Troll, 10 BloodElf, 11 Draenei -
# race 9 Goblin is not a playable 3.3.5a race). Recomputed here from the same
# bit values rather than hand-copied, so a future SharedDefines.h edit is the
# only place that could silently invalidate this constant.
_PLAYABLE_RACE_IDS = (1, 2, 3, 4, 5, 6, 7, 8, 10, 11)
RACEMASK_ALL_PLAYABLE = sum(1 << (race_id - 1) for race_id in _PLAYABLE_RACE_IDS)

# ReputationFlags::Visible (src/server/game/Reputation/ReputationMgr.h).
REPUTATION_FLAG_VISIBLE = 0x0001


class DbcValidationError(SystemExit):
    pass


def read_dbc(path: Path) -> tuple[int, bytes, bytes]:
    data = path.read_bytes()
    if len(data) < HEADER_SIZE:
        raise DbcValidationError(f"{path}: file too small to be a WDBC file ({len(data)} bytes)")

    magic, record_count, field_count, record_size, string_block_size = struct.unpack_from(HEADER_FORMAT, data, 0)
    if magic != MAGIC:
        raise DbcValidationError(f"{path}: not a WDBC file (magic={magic!r})")
    if field_count != FIELD_COUNT or record_size != RECORD_SIZE:
        raise DbcValidationError(
            f"{path}: unexpected Faction.dbc layout fieldCount={field_count} recordSize={record_size} "
            f"(expected {FIELD_COUNT}/{RECORD_SIZE} - see this script's own module docstring)"
        )

    records_end = HEADER_SIZE + record_count * record_size
    records_bytes = data[HEADER_SIZE:records_end]
    string_block = data[records_end:records_end + string_block_size]
    if len(records_bytes) != record_count * record_size or len(string_block) != string_block_size:
        raise DbcValidationError(f"{path}: truncated file (records or string block shorter than the header claims)")
    if not string_block[:1] == b"\x00":
        raise DbcValidationError(
            f"{path}: string block does not start with the mandatory empty string (0x00) - "
            "refusing to append onto an unexpected layout"
        )

    return record_count, records_bytes, string_block


def existing_ids_and_reputation_indexes(record_count: int, records_bytes: bytes) -> tuple[set[int], set[int]]:
    ids: set[int] = set()
    reputation_indexes: set[int] = set()
    for i in range(record_count):
        offset = i * RECORD_SIZE
        record_id, reputation_index = struct.unpack_from("<Ii", records_bytes, offset)
        ids.add(record_id)
        if reputation_index >= 0:
            reputation_indexes.add(reputation_index)
    return ids, reputation_indexes


def load_rows(csv_path: Path) -> list[dict[str, str]]:
    with csv_path.open(encoding="utf-8") as f:
        data_lines = [line for line in f if not line.lstrip().startswith("#")]
    return list(csv.DictReader(data_lines))


def load_world_faction_keys(world_factions_csv: Path) -> set[str]:
    with world_factions_csv.open(newline="", encoding="utf-8") as f:
        return {row["key"] for row in csv.DictReader(f)}


def validate_rows(rows: list[dict[str, str]], existing_ids: set[int], existing_reputation_indexes: set[int],
                   world_faction_keys: set[str]) -> None:
    seen_ids: set[int] = set()
    seen_reputation_indexes: set[int] = set()

    for row in rows:
        row_id = int(row["id"])
        reputation_index = int(row["reputation_index"])

        if row_id in existing_ids:
            raise DbcValidationError(f"Faction.dbc id {row_id} already exists in the base DBC - refusing to duplicate it")
        if row_id in seen_ids:
            raise DbcValidationError(f"Faction.dbc id {row_id} is duplicated within factions.csv itself")
        seen_ids.add(row_id)

        if reputation_index in existing_reputation_indexes:
            raise DbcValidationError(
                f"ReputationIndex {reputation_index} (id {row_id}) is already used by an existing Faction.dbc row - "
                "refusing to create a colliding reputation slot"
            )
        if reputation_index in seen_reputation_indexes:
            raise DbcValidationError(f"ReputationIndex {reputation_index} is duplicated within factions.csv itself")
        seen_reputation_indexes.add(reputation_index)

        world_faction = row["world_faction"]
        if world_faction not in world_faction_keys:
            raise DbcValidationError(
                f"factions.csv row id={row_id} references world_faction={world_faction!r}, "
                "which is not a key in world_factions.csv (audit-only cross-reference, see factions.csv's own comment)"
            )


def build_record(row: dict[str, str], name_offset: int) -> bytes:
    row_id = int(row["id"])
    reputation_index = int(row["reputation_index"])
    base_reputation = int(row["base_reputation"])
    visible = row["visible"].strip() in ("1", "true", "True", "yes")
    parent_id = int(row["parent_id"])

    reputation_race_mask = [RACEMASK_ALL_PLAYABLE, 0, 0, 0]
    reputation_class_mask = [0, 0, 0, 0]
    reputation_base = [base_reputation, 0, 0, 0]
    reputation_flags = [REPUTATION_FLAG_VISIBLE if visible else 0, 0, 0, 0]

    name_lang = [name_offset] * LOCALE_STRING_COLUMNS
    name_lang_mask = 0
    description_lang = [0] * LOCALE_STRING_COLUMNS
    description_lang_mask = 0

    packed = struct.pack(
        "<Ii4I4I4i4IIff2I16II16II",
        row_id,
        reputation_index,
        *reputation_race_mask,
        *reputation_class_mask,
        *reputation_base,
        *reputation_flags,
        parent_id,
        0.0, 0.0,
        0, 0,
        *name_lang,
        name_lang_mask,
        *description_lang,
        description_lang_mask,
    )

    if len(packed) != RECORD_SIZE:
        raise AssertionError(f"internal error: built a {len(packed)}-byte record, expected {RECORD_SIZE}")
    return packed


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--csv", default="data/elwynn/factions/factions.csv", type=Path)
    parser.add_argument("--world-factions-csv", default="data/elwynn/factions/world_factions.csv", type=Path)
    parser.add_argument("--base", default="runtime/dbc-base/Faction.dbc", type=Path,
                         help="vanilla Faction.dbc this script appends onto (never modified in place)")
    parser.add_argument("--out", default="runtime/data/dbc/Faction.dbc", type=Path)
    args = parser.parse_args()

    if not args.base.exists():
        raise DbcValidationError(f"{args.base} does not exist - see README.md's own workflow section")

    record_count, records_bytes, string_block = read_dbc(args.base)
    existing_ids, existing_reputation_indexes = existing_ids_and_reputation_indexes(record_count, records_bytes)

    rows = load_rows(args.csv)
    world_faction_keys = load_world_faction_keys(args.world_factions_csv)
    validate_rows(rows, existing_ids, existing_reputation_indexes, world_faction_keys)

    # Every row's Name is appended to the string block once, all 16 locale
    # columns pointing at the same offset - see this file's own module
    # docstring for why per-locale text is out of scope for V1 (the server
    # itself never reads these fields at all).
    string_block_out = bytearray(string_block)
    name_offsets: dict[str, int] = {}
    for row in rows:
        name = row["name"]
        if name not in name_offsets:
            name_offsets[name] = len(string_block_out)
            string_block_out += name.encode("utf-8") + b"\x00"

    new_records = b"".join(build_record(row, name_offsets[row["name"]]) for row in rows)

    out_record_count = record_count + len(rows)
    out_records_bytes = records_bytes + new_records
    header = struct.pack(HEADER_FORMAT, MAGIC, out_record_count, FIELD_COUNT, RECORD_SIZE, len(string_block_out))

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes(header + out_records_bytes + bytes(string_block_out))

    print(f"Wrote {args.out}: {record_count} base + {len(rows)} custom = {out_record_count} records")
    for row in rows:
        print(f"  id={row['id']} reputationIndex={row['reputation_index']} worldFaction={row['world_faction']} name={row['name']!r}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
