#!/usr/bin/env python3
from pathlib import Path
import argparse
import csv
from collections import defaultdict, Counter

NPC_TRAINER = 0x00000010
NPC_TRAINER_CLASS = 0x00000020
NPC_TRAINER_PROFESSION = 0x00000040
NPC_VENDOR = 0x00000080
NPC_VENDOR_AMMO = 0x00000100
NPC_VENDOR_FOOD = 0x00000200
NPC_VENDOR_POISON = 0x00000400
NPC_VENDOR_REAGENT = 0x00000800
NPC_REPAIR = 0x00001000
NPC_SPIRITHEALER = 0x00004000
NPC_SPIRITGUIDE = 0x00008000

VENDOR_MASK = (
    NPC_VENDOR | NPC_VENDOR_AMMO | NPC_VENDOR_FOOD |
    NPC_VENDOR_POISON | NPC_VENDOR_REAGENT | NPC_REPAIR
)
TRAINER_MASK = NPC_TRAINER | NPC_TRAINER_CLASS | NPC_TRAINER_PROFESSION

HOSTILE_HUMANOID_FACTIONS = {7, 17, 18, 20, 25, 26, 27}
PREDATOR_BEAST_FACTIONS = {22, 32, 38, 44}

HOSTILE_NAME_WORDS = (
    "defias", "kobold", "riverpaw", "murloc", "hogger",
    "goldtooth", "fedfennel", "gruff swiftbite", "ruklar",
    "narg the taskmaster", "morgaine the sly", "morgan the collector",
    "garrick padfoot", "dead-tooth jack", "surena caledon",
    "erlan drudgemoor", "thuros lightfingers",
)
GUARD_WORDS = ("guard", "marshal", "deputy", "sergeant")
WORKER_WORDS = (
    "peasant", "farmer", "farmhand", "lumberjack", "woodworker", "supervisor"
)
TRAVELER_WORDS = ("expeditionary", "traveler", "travelling", "traveling")
PREDATOR_WORDS = ("wolf", "prowler", "bear", "spider", "drake")
HORSE_WORDS = ("horse", "mare", "stallion", "steed", "palomino", "pinto")

MANUAL_REVIEW = {
    14388: "Rogue Black Drake: permanent dragonkin; confirm whether FULL_AGENT predator is desired.",
    1949: "Servant of Azora: permanent humanoid but likely special-purpose population; confirm role.",
    6172: "Henze Faulk: permanent humanoid with faction template 123; confirm semantic role.",
    6774: "Falkhaan Isenstrider: permanent humanoid; confirm semantic role.",
    10616: "Supervisor Raelen: classified worker supervisor; confirm Eastvale work role.",
}

TEMPLATE_FIELDS = [
    "name", "subname", "minlevel", "maxlevel", "faction_template_id",
    "template_npcflag", "rank", "creature_type", "creature_family",
    "type_flags", "template_movement_type", "template_unit_flags",
    "flags_extra", "ai_name", "script_name",
]

def to_int(v):
    if v in (None, "", "NULL"):
        return 0
    return int(v)

def has(text, words):
    t = text.lower()
    return any(w in t for w in words)

def build_templates(raw_rows):
    included = [r for r in raw_rows if r["census_scope_status"] == "INCLUDED"]
    by_entry = defaultdict(list)
    for r in included:
        by_entry[to_int(r["entry"])].append(r)

    out = []
    for entry in sorted(by_entry):
        group = by_entry[entry]
        first = group[0]

        for field in TEMPLATE_FIELDS:
            vals = {r[field] for r in group}
            if len(vals) != 1:
                raise SystemExit(
                    f"ERROR: CreatureEntry {entry}: inconsistent {field}: {sorted(vals)}"
                )

        areas = sorted({to_int(r["area_id"]) for r in group})
        movements = sorted({to_int(r["spawn_movement_type"]) for r in group})

        out.append({
            "entry": entry,
            "name": first["name"],
            "subname": "" if first["subname"] in ("", "NULL") else first["subname"],
            "included_spawn_count": len(group),
            "area_count": len(areas),
            "area_ids": "|".join(map(str, areas)),
            "negative_event_baseline_count": sum(
                to_int(r["has_negative_event"]) == 1 for r in group
            ),
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
            "spawn_movement_types": "|".join(map(str, movements)),
            "path_spawn_count": sum(
                r["path_id"] not in ("", "0", "NULL") for r in group
            ),
            "wander_spawn_count": sum(
                float(r["wander_distance"]) > 0 for r in group
            ),
        })
    return out

def classify(t):
    entry = to_int(t["entry"])
    name = t["name"].strip()
    subname = (t["subname"] or "").strip()
    text = f"{name} {subname}".strip()

    npcflag = to_int(t["template_npcflag"])
    creature_type = to_int(t["creature_type"])
    faction = to_int(t["faction_template_id"])
    spawn_count = to_int(t["included_spawn_count"])

    if npcflag & (NPC_SPIRITHEALER | NPC_SPIRITGUIDE):
        category, mode, role = "SPECIAL_SCRIPTED", "VANILLA_ONLY", "spirit_healer"
        basis = "TrinityCore spirit healer/guide NPC flag"
    elif creature_type == 7 and (
        faction in HOSTILE_HUMANOID_FACTIONS or has(text, HOSTILE_NAME_WORDS)
    ):
        category, mode, role = "HOSTILE_HUMANOID", "FULL_AGENT", "hostile_humanoid"
        basis = "humanoid + current hostile faction/name evidence"
    elif has(text, GUARD_WORDS):
        category, mode, role = "GUARD", "FULL_AGENT", "guard"
        basis = "guard/marshal/deputy/sergeant role in name"
    elif npcflag & TRAINER_MASK or "trainer" in subname.lower():
        category, mode, role = "TRAINER", "FULL_AGENT", subname or "trainer"
        basis = "TrinityCore trainer NPC flag/subname"
    elif npcflag & VENDOR_MASK:
        category, mode, role = "MERCHANT_VENDOR", "FULL_AGENT", subname or "vendor"
        basis = "TrinityCore vendor/repair NPC flag"
    elif has(text, WORKER_WORDS) or entry == 250:
        category, mode = "WORKER_FARMER", "FULL_AGENT"
        role = "farmer" if entry == 250 else ("supervisor" if "supervisor" in text.lower() else "worker")
        basis = "project-verified Pa Maclure farmer vertical slice" if entry == 250 else "worker/farmer role in name"
    elif has(text, TRAVELER_WORDS):
        category, mode, role = "TRAVELER", "FULL_AGENT", subname or "traveler"
        basis = "travel/expedition role in name"
    elif creature_type in {1, 2} and (
        faction in PREDATOR_BEAST_FACTIONS or has(text, PREDATOR_WORDS)
    ):
        category, mode, role = "PREDATOR", "FULL_AGENT", "predator"
        basis = "predatory creature name/current faction evidence"
    elif creature_type in {1, 8, 12}:
        category, mode = "PREY_FAUNA", "LIGHTWEIGHT_BACKGROUND"
        role = "domestic_mount" if has(text, HORSE_WORDS) else "fauna"
        basis = "beast/critter/non-combat-pet permanent population"
    elif creature_type == 7:
        category, mode, role = "CIVILIAN", "FULL_AGENT", subname or "civilian"
        basis = "remaining permanent humanoid"
    else:
        category, mode, role = "SPECIAL_SCRIPTED", "VANILLA_ONLY", subname or "special"
        basis = "non-standard permanent creature type"

    if spawn_count > 1 or category in {"PREY_FAUNA", "PREDATOR", "SPECIAL_SCRIPTED"}:
        unique_named = "NO"
    else:
        unique_named = "YES"

    return {
        "entry": entry,
        "name": name,
        "subname": subname,
        "included_spawn_count": spawn_count,
        "primary_category": category,
        "participation_mode": mode,
        "role_or_profession": role,
        "unique_named": unique_named,
        "review_status": "MANUAL_REVIEW" if entry in MANUAL_REVIEW else "ACCEPTED_DEFAULT",
        "classification_basis": basis,
        "notes": MANUAL_REVIEW.get(entry, ""),
    }

def write_csv(path, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        writer.writeheader()
        writer.writerows(rows)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "input",
        nargs="?",
        default="data/elwynn/census/spawns.csv",
        help="Raw 3.1 spawn census CSV with event columns",
    )
    parser.add_argument(
        "--out-dir",
        default="data/elwynn/census",
        help="Output directory",
    )
    args = parser.parse_args()

    src = Path(args.input)
    out_dir = Path(args.out_dir)

    with src.open(newline="", encoding="utf-8-sig") as f:
        raw = list(csv.DictReader(f))

    status = Counter(r["census_scope_status"] for r in raw)
    if status.get("REVIEW_EVENT", 0):
        raise SystemExit(
            f"ERROR: {status['REVIEW_EVENT']} REVIEW_EVENT rows require manual review."
        )

    templates = build_templates(raw)
    classification = [classify(t) for t in templates]
    class_by_entry = {to_int(r["entry"]): r for r in classification}

    spawn_class = []
    for r in raw:
        row = {
            "spawn_id": r["spawn_id"],
            "entry": r["entry"],
            "name": r["name"],
            "area_id": r["area_id"],
            "game_event_entries": r["game_event_entries"],
            "census_scope_status": r["census_scope_status"],
        }

        if r["census_scope_status"] == "EXCLUDED_EVENT":
            row.update({
                "primary_category": "EXCLUDED_EVENT",
                "participation_mode": "EXCLUDED",
                "role_or_profession": "",
                "unique_named": "N/A",
                "review_status": "EXCLUDED_BY_POLICY",
                "classification_source": "game_event_creature positive eventEntry",
            })
        elif r["census_scope_status"] == "INCLUDED":
            c = class_by_entry[to_int(r["entry"])]
            row.update({
                "primary_category": c["primary_category"],
                "participation_mode": c["participation_mode"],
                "role_or_profession": c["role_or_profession"],
                "unique_named": c["unique_named"],
                "review_status": c["review_status"],
                "classification_source": f"template:{r['entry']}",
            })
        else:
            raise SystemExit(
                f"ERROR: unsupported census_scope_status={r['census_scope_status']}"
            )

        spawn_class.append(row)

    write_csv(out_dir / "permanent_templates.csv", templates)
    write_csv(out_dir / "template_classification.csv", classification)
    write_csv(out_dir / "spawn_classification.csv", spawn_class)

    category_templates = Counter(r["primary_category"] for r in classification)
    category_spawns = Counter()
    mode_spawns = Counter()
    for r in classification:
        n = to_int(r["included_spawn_count"])
        category_spawns[r["primary_category"]] += n
        mode_spawns[r["participation_mode"]] += n

    manual = [r for r in classification if r["review_status"] == "MANUAL_REVIEW"]

    lines = [
        "# Elwynn Census Coverage — permanent baseline",
        "",
        "## Census disposition",
        "",
        f"- Raw `zoneId = 12` census: **{len(raw)}** spawns",
        f"- Permanent `INCLUDED`: **{status['INCLUDED']}** spawns",
        f"- `EXCLUDED_EVENT`: **{status['EXCLUDED_EVENT']}** spawns",
        f"- `REVIEW_EVENT`: **{status['REVIEW_EVENT']}** spawns",
        f"- Permanent CreatureEntry templates: **{len(templates)}**",
        "",
        "Positive `game_event_creature.eventEntry` rows are excluded.",
        "Negative-only event relations remain in the permanent baseline.",
        "Quest-giver status does not affect category or participation.",
        "",
        "## Permanent population categories",
        "",
        "| Category | Templates | Spawns |",
        "|---|---:|---:|",
    ]
    for cat in sorted(category_templates):
        lines.append(f"| {cat} | {category_templates[cat]} | {category_spawns[cat]} |")

    lines += [
        "",
        "## Participation modes",
        "",
        "| Mode | Permanent spawns |",
        "|---|---:|",
    ]
    for mode in sorted(mode_spawns):
        lines.append(f"| {mode} | {mode_spawns[mode]} |")

    lines += [
        "",
        "## Manual review",
        "",
        f"Templates requiring explicit semantic review: **{len(manual)}**.",
        "",
    ]
    for r in manual:
        lines.append(f"- `{r['entry']}` {r['name']}: {r['notes']}")

    lines += [
        "",
        "## Coverage invariant",
        "",
        f"- Final spawn-level rows: **{len(spawn_class)} / {len(raw)}**",
        f"- Explicitly excluded event rows: **{sum(r['participation_mode']=='EXCLUDED' for r in spawn_class)}**",
        f"- Permanent rows with explicit participation mode: **{sum(1 for r in spawn_class if r['census_scope_status']=='INCLUDED' and r['participation_mode'])} / {status['INCLUDED']}**",
        "",
        "This is a DRAFT 3.1 classification baseline. It is not runtime verification.",
    ]
    (out_dir / "coverage.md").write_text("\n".join(lines) + "\n", encoding="utf-8")

    print(f"Raw census: {len(raw)}")
    print(f"Permanent INCLUDED: {status['INCLUDED']}")
    print(f"EXCLUDED_EVENT: {status['EXCLUDED_EVENT']}")
    print(f"Permanent templates: {len(templates)}")
    print(f"Manual review templates: {len(manual)}")

if __name__ == "__main__":
    main()
