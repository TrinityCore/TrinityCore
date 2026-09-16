#!/usr/bin/env python3
from pathlib import Path
import argparse
import csv
from collections import defaultdict

TEMPLATE_FIELDS = [
    "name",
    "subname",
    "minlevel",
    "maxlevel",
    "faction_template_id",
    "template_npcflag",
    "rank",
    "creature_type",
    "creature_family",
    "type_flags",
    "template_movement_type",
    "template_unit_flags",
    "flags_extra",
    "ai_name",
    "script_name",
]

OUTPUT_FIELDS = [
    "entry",
    "name",
    "subname",
    "spawn_count",
    "area_count",
    "area_ids",
    "minlevel",
    "maxlevel",
    "faction_template_id",
    "template_npcflag",
    "rank",
    "creature_type",
    "creature_family",
    "type_flags",
    "template_movement_type",
    "template_unit_flags",
    "flags_extra",
    "ai_name",
    "script_name",
    "spawn_movement_types",
    "path_spawn_count",
    "wander_spawn_count",
]

def main():
    parser = argparse.ArgumentParser(
        description="Build one-row-per-CreatureEntry Elwynn template census from spawns.csv."
    )
    parser.add_argument(
        "input",
        nargs="?",
        default="data/elwynn/census/spawns.csv",
        help="Raw spawn census CSV",
    )
    parser.add_argument(
        "output",
        nargs="?",
        default="data/elwynn/census/templates.csv",
        help="Generated template census CSV",
    )
    args = parser.parse_args()

    src = Path(args.input)
    dst = Path(args.output)

    with src.open(newline="", encoding="utf-8-sig") as f:
        rows = list(csv.DictReader(f))

    groups = defaultdict(list)
    for row in rows:
        groups[int(row["entry"])].append(row)

    result = []
    for entry in sorted(groups):
        group = groups[entry]
        first = group[0]

        for field in TEMPLATE_FIELDS:
            values = {r[field] for r in group}
            if len(values) != 1:
                raise SystemExit(
                    f"ERROR: CreatureEntry {entry}: inconsistent template field "
                    f"{field}: {sorted(values)}"
                )

        exported_counts = {int(r["template_spawn_count"]) for r in group}
        if exported_counts != {len(group)}:
            raise SystemExit(
                f"ERROR: CreatureEntry {entry}: template_spawn_count mismatch: "
                f"export={sorted(exported_counts)}, actual={len(group)}"
            )

        area_ids = sorted({int(r["area_id"]) for r in group})
        movement_types = sorted({int(r["spawn_movement_type"]) for r in group})

        path_spawn_count = sum(
            1 for r in group
            if r["path_id"] not in ("", "NULL", "0")
        )
        wander_spawn_count = sum(
            1 for r in group
            if float(r["wander_distance"]) > 0
        )

        result.append({
            "entry": entry,
            "name": first["name"],
            "subname": first["subname"],
            "spawn_count": len(group),
            "area_count": len(area_ids),
            "area_ids": "|".join(map(str, area_ids)),
            "minlevel": first["minlevel"],
            "maxlevel": first["maxlevel"],
            "faction_template_id": first["faction_template_id"],
            "template_npcflag": first["template_npcflag"],
            "rank": first["rank"],
            "creature_type": first["creature_type"],
            "creature_family": first["creature_family"],
            "type_flags": first["type_flags"],
            "template_movement_type": first["template_movement_type"],
            "template_unit_flags": first["template_unit_flags"],
            "flags_extra": first["flags_extra"],
            "ai_name": first["ai_name"],
            "script_name": first["script_name"],
            "spawn_movement_types": "|".join(map(str, movement_types)),
            "path_spawn_count": path_spawn_count,
            "wander_spawn_count": wander_spawn_count,
        })

    dst.parent.mkdir(parents=True, exist_ok=True)
    with dst.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=OUTPUT_FIELDS)
        writer.writeheader()
        writer.writerows(result)

    print(
        f"Wrote {len(result)} CreatureEntry rows from {len(rows)} spawn rows "
        f"to {dst}"
    )

if __name__ == "__main__":
    main()
