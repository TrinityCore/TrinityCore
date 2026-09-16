#!/usr/bin/env python3
"""Generates runtime/data/dbc/{Faction,FactionTemplate}.dbc from
data/elwynn/factions/{factions,faction_templates}.csv.

V1 scope (see data/elwynn/factions/README.md): produces the custom "player
reputation" Faction.dbc rows for the AI WorldFactionId social layer's four
player-visible factions (Defias Brotherhood, Riverpaw Gnolls, Elwynn
Kobolds, Elwynn Murlocs), AND the FactionTemplate.dbc CLONES needed to point
specific creature templates at them without touching anyone else's vanilla
reaction. It does NOT generate FactionGroup.dbc, does NOT touch
creature_template.faction itself (see sql/updates/world/3.3.5/
2026_09_16_01_world.sql for that), and does NOT produce a client-side MPQ
patch - see README.md's own "DBC stav" section for what is still open.

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
step, not implemented here). Only RaceMask/ClassMask/Base/Flags SLOT 0 is
populated per row: ReputationMgr::GetFactionDataIndexForRaceAndClass()
(src/server/game/Reputation/ReputationMgr.cpp) requires a slot's own
RaceMask to directly intersect the player's race bit to ever select that
slot at all - an all-zero RaceMask/ClassMask slot NEVER matches any player,
so "available to every playable race" means RaceMask[0] =
RACEMASK_ALL_PLAYABLE (SharedDefines.h), not 0.

FactionTemplate.dbc (3.3.5a) is a 14-field, 56-byte-per-record WDBC file
(no string block content beyond the mandatory empty string) - see
DBCStructure.h's own FactionTemplateEntry comment and DBCfmt.h's
FactionTemplateEntryfmt ("niiiiiiiiiiiii", 14 characters):

  field 0         ID                          uint32
  field 1         Faction                     uint32 (Faction.dbc id)
  field 2         Flags                       uint32
  field 3         FactionGroup                uint32
  field 4         FriendGroup                 uint32
  field 5         EnemyGroup                  uint32
  fields 6-9      Enemies[4]                  uint32 (other rows' Faction ids)
  fields 10-13    Friend[4]                   uint32 (other rows' Faction ids)

Each custom row in faction_templates.csv is a byte-for-byte CLONE of its own
source_template_id's CURRENT vanilla record - every field except Faction is
copied straight from runtime/dbc-base/FactionTemplate.dbc at generation
time, never hand-transcribed into the CSV (see that file's own header
comment for why). Enemies/Friend are copied unchanged even though they
reference OLD Faction ids (e.g. a Defias clone's Friend list still points at
vanilla Faction 15) - deliberately: this keeps the clone mutually
friendly/hostile with any other FactionTemplate that still carries that
same original Faction id (other vanilla Defias content elsewhere in the
world), which is exactly "clone preserves relationships", not a bug.
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


class DbcValidationError(SystemExit):
    pass


def read_dbc(path: Path, expected_field_count: int, expected_record_size: int) -> tuple[int, bytes, bytes]:
    data = path.read_bytes()
    if len(data) < HEADER_SIZE:
        raise DbcValidationError(f"{path}: file too small to be a WDBC file ({len(data)} bytes)")

    magic, record_count, field_count, record_size, string_block_size = struct.unpack_from(HEADER_FORMAT, data, 0)
    if magic != MAGIC:
        raise DbcValidationError(f"{path}: not a WDBC file (magic={magic!r})")
    if field_count != expected_field_count or record_size != expected_record_size:
        raise DbcValidationError(
            f"{path}: unexpected layout fieldCount={field_count} recordSize={record_size} "
            f"(expected {expected_field_count}/{expected_record_size} - see this script's own module docstring)"
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


def load_csv_rows(csv_path: Path) -> list[dict[str, str]]:
    # factions.csv/faction_templates.csv both carry a '#'-prefixed
    # documentation preamble before the real header row - filtered out here
    # rather than requiring every caller to know that convention.
    with csv_path.open(encoding="utf-8") as f:
        data_lines = [line for line in f if not line.lstrip().startswith("#")]
    return list(csv.DictReader(data_lines))


def load_world_faction_keys(world_factions_csv: Path) -> set[str]:
    with world_factions_csv.open(newline="", encoding="utf-8") as f:
        return {row["key"] for row in csv.DictReader(f)}


def write_dbc(out_path: Path, out_record_count: int, field_count: int, record_size: int,
              out_records_bytes: bytes, string_block_out: bytes) -> None:
    header = struct.pack(HEADER_FORMAT, MAGIC, out_record_count, field_count, record_size, len(string_block_out))
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(header + out_records_bytes + string_block_out)


# --- Faction.dbc ------------------------------------------------------------

FACTION_FIELD_COUNT = 57
FACTION_RECORD_SIZE = FACTION_FIELD_COUNT * 4  # 228 bytes
FACTION_LOCALE_STRING_COLUMNS = 16

# SharedDefines.h RACEMASK_ALL_PLAYABLE (races 1 Human, 2 Orc, 3 Dwarf,
# 4 NightElf, 5 Undead, 6 Tauren, 7 Gnome, 8 Troll, 10 BloodElf, 11 Draenei -
# race 9 Goblin is not a playable 3.3.5a race). Recomputed here from the same
# bit values rather than hand-copied, so a future SharedDefines.h edit is the
# only place that could silently invalidate this constant.
_PLAYABLE_RACE_IDS = (1, 2, 3, 4, 5, 6, 7, 8, 10, 11)
RACEMASK_ALL_PLAYABLE = sum(1 << (race_id - 1) for race_id in _PLAYABLE_RACE_IDS)

# ReputationFlags::Visible (src/server/game/Reputation/ReputationMgr.h).
REPUTATION_FLAG_VISIBLE = 0x0001


def existing_faction_ids_and_reputation_indexes(record_count: int, records_bytes: bytes) -> tuple[set[int], set[int]]:
    ids: set[int] = set()
    reputation_indexes: set[int] = set()
    for i in range(record_count):
        offset = i * FACTION_RECORD_SIZE
        record_id, reputation_index = struct.unpack_from("<Ii", records_bytes, offset)
        ids.add(record_id)
        if reputation_index >= 0:
            reputation_indexes.add(reputation_index)
    return ids, reputation_indexes


def validate_faction_rows(rows: list[dict[str, str]], existing_ids: set[int], existing_reputation_indexes: set[int],
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


def build_faction_record(row: dict[str, str], name_offset: int) -> bytes:
    row_id = int(row["id"])
    reputation_index = int(row["reputation_index"])
    base_reputation = int(row["base_reputation"])
    visible = row["visible"].strip() in ("1", "true", "True", "yes")
    parent_id = int(row["parent_id"])

    reputation_race_mask = [RACEMASK_ALL_PLAYABLE, 0, 0, 0]
    reputation_class_mask = [0, 0, 0, 0]
    reputation_base = [base_reputation, 0, 0, 0]
    reputation_flags = [REPUTATION_FLAG_VISIBLE if visible else 0, 0, 0, 0]

    name_lang = [name_offset] * FACTION_LOCALE_STRING_COLUMNS
    name_lang_mask = 0
    description_lang = [0] * FACTION_LOCALE_STRING_COLUMNS
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

    if len(packed) != FACTION_RECORD_SIZE:
        raise AssertionError(f"internal error: built a {len(packed)}-byte Faction.dbc record, expected {FACTION_RECORD_SIZE}")
    return packed


def generate_faction_dbc(csv_path: Path, world_factions_csv: Path, base_path: Path, out_path: Path) -> None:
    if not base_path.exists():
        raise DbcValidationError(f"{base_path} does not exist - see README.md's own workflow section")

    record_count, records_bytes, string_block = read_dbc(base_path, FACTION_FIELD_COUNT, FACTION_RECORD_SIZE)
    existing_ids, existing_reputation_indexes = existing_faction_ids_and_reputation_indexes(record_count, records_bytes)

    rows = load_csv_rows(csv_path)
    world_faction_keys = load_world_faction_keys(world_factions_csv)
    validate_faction_rows(rows, existing_ids, existing_reputation_indexes, world_faction_keys)

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

    new_records = b"".join(build_faction_record(row, name_offsets[row["name"]]) for row in rows)
    out_record_count = record_count + len(rows)
    write_dbc(out_path, out_record_count, FACTION_FIELD_COUNT, FACTION_RECORD_SIZE,
              records_bytes + new_records, bytes(string_block_out))

    print(f"Wrote {out_path}: {record_count} base + {len(rows)} custom = {out_record_count} records")
    for row in rows:
        print(f"  id={row['id']} reputationIndex={row['reputation_index']} worldFaction={row['world_faction']} name={row['name']!r}")


# --- FactionTemplate.dbc -----------------------------------------------------

FACTION_TEMPLATE_FIELD_COUNT = 14
FACTION_TEMPLATE_RECORD_SIZE = FACTION_TEMPLATE_FIELD_COUNT * 4  # 56 bytes
FACTION_TEMPLATE_STRUCT_FORMAT = "<14I"  # ID, Faction, Flags, FactionGroup, FriendGroup, EnemyGroup, Enemies[4], Friend[4]


def index_faction_templates_by_id(record_count: int, records_bytes: bytes) -> dict[int, tuple[int, ...]]:
    by_id: dict[int, tuple[int, ...]] = {}
    for i in range(record_count):
        offset = i * FACTION_TEMPLATE_RECORD_SIZE
        fields = struct.unpack_from(FACTION_TEMPLATE_STRUCT_FORMAT, records_bytes, offset)
        by_id[fields[0]] = fields
    return by_id


def validate_faction_template_rows(rows: list[dict[str, str]], existing_by_id: dict[int, tuple[int, ...]],
                                    valid_faction_ids: set[int], world_faction_keys: set[str]) -> None:
    seen_ids: set[int] = set()

    for row in rows:
        row_id = int(row["id"])
        source_id = int(row["source_template_id"])
        faction_id = int(row["faction_id"])

        if row_id in existing_by_id:
            raise DbcValidationError(f"FactionTemplate.dbc id {row_id} already exists in the base DBC - refusing to duplicate it")
        if row_id in seen_ids:
            raise DbcValidationError(f"FactionTemplate.dbc id {row_id} is duplicated within faction_templates.csv itself")
        seen_ids.add(row_id)

        if source_id not in existing_by_id:
            raise DbcValidationError(
                f"faction_templates.csv row id={row_id} clones source_template_id={source_id}, "
                "which does not exist in the base FactionTemplate.dbc"
            )

        if faction_id not in valid_faction_ids:
            raise DbcValidationError(
                f"faction_templates.csv row id={row_id} references faction_id={faction_id}, "
                "which is not one of factions.csv's own ids - clones must point at an accepted custom Faction.dbc row"
            )

        world_faction = row["world_faction"]
        if world_faction not in world_faction_keys:
            raise DbcValidationError(
                f"faction_templates.csv row id={row_id} references world_faction={world_faction!r}, "
                "which is not a key in world_factions.csv (audit-only cross-reference)"
            )


def build_faction_template_record(row: dict[str, str], source_fields: tuple[int, ...]) -> bytes:
    row_id = int(row["id"])
    faction_id = int(row["faction_id"])

    # Byte-for-byte clone of the source row - only ID and Faction change.
    # source_fields = (ID, Faction, Flags, FactionGroup, FriendGroup, EnemyGroup, *Enemies[4], *Friend[4])
    _source_id, _source_faction, flags, faction_group, friend_group, enemy_group = source_fields[0:6]
    enemies = source_fields[6:10]
    friends = source_fields[10:14]

    packed = struct.pack(
        FACTION_TEMPLATE_STRUCT_FORMAT,
        row_id, faction_id, flags, faction_group, friend_group, enemy_group,
        *enemies, *friends,
    )

    if len(packed) != FACTION_TEMPLATE_RECORD_SIZE:
        raise AssertionError(f"internal error: built a {len(packed)}-byte FactionTemplate.dbc record, expected {FACTION_TEMPLATE_RECORD_SIZE}")
    return packed


def generate_faction_template_dbc(csv_path: Path, factions_csv: Path, world_factions_csv: Path,
                                   base_path: Path, out_path: Path) -> None:
    if not base_path.exists():
        raise DbcValidationError(f"{base_path} does not exist - see README.md's own workflow section")

    record_count, records_bytes, string_block = read_dbc(base_path, FACTION_TEMPLATE_FIELD_COUNT, FACTION_TEMPLATE_RECORD_SIZE)
    existing_by_id = index_faction_templates_by_id(record_count, records_bytes)

    rows = load_csv_rows(csv_path)
    valid_faction_ids = {int(r["id"]) for r in load_csv_rows(factions_csv)}
    world_faction_keys = load_world_faction_keys(world_factions_csv)
    validate_faction_template_rows(rows, existing_by_id, valid_faction_ids, world_faction_keys)

    new_records = b"".join(build_faction_template_record(row, existing_by_id[int(row["source_template_id"])]) for row in rows)
    out_record_count = record_count + len(rows)
    write_dbc(out_path, out_record_count, FACTION_TEMPLATE_FIELD_COUNT, FACTION_TEMPLATE_RECORD_SIZE,
              records_bytes + new_records, bytes(string_block))

    print(f"Wrote {out_path}: {record_count} base + {len(rows)} custom = {out_record_count} records")
    for row in rows:
        source_fields = existing_by_id[int(row["source_template_id"])]
        print(f"  id={row['id']} clonedFrom={row['source_template_id']} faction={row['faction_id']} "
              f"flags={source_fields[2]} factionGroup={source_fields[3]} friendGroup={source_fields[4]} enemyGroup={source_fields[5]} "
              f"worldFaction={row['world_faction']}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--factions-csv", default="data/elwynn/factions/factions.csv", type=Path)
    parser.add_argument("--faction-templates-csv", default="data/elwynn/factions/faction_templates.csv", type=Path)
    parser.add_argument("--world-factions-csv", default="data/elwynn/factions/world_factions.csv", type=Path)
    parser.add_argument("--dbc-base-dir", default="runtime/dbc-base", type=Path,
                         help="vanilla DBC directory this script appends onto (never modified in place)")
    parser.add_argument("--out-dir", default="runtime/data/dbc", type=Path)
    args = parser.parse_args()

    generate_faction_dbc(
        args.factions_csv, args.world_factions_csv,
        args.dbc_base_dir / "Faction.dbc", args.out_dir / "Faction.dbc",
    )
    generate_faction_template_dbc(
        args.faction_templates_csv, args.factions_csv, args.world_factions_csv,
        args.dbc_base_dir / "FactionTemplate.dbc", args.out_dir / "FactionTemplate.dbc",
    )

    return 0


if __name__ == "__main__":
    sys.exit(main())
