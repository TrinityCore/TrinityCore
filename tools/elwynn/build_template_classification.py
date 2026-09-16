#!/usr/bin/env python3
from pathlib import Path
import argparse
import csv
from collections import Counter

NPC_GOSSIP = 0x00000001
NPC_QUESTGIVER = 0x00000002
NPC_TRAINER = 0x00000010
NPC_TRAINER_CLASS = 0x00000020
NPC_TRAINER_PROFESSION = 0x00000040
NPC_VENDOR = 0x00000080
NPC_VENDOR_AMMO = 0x00000100
NPC_VENDOR_FOOD = 0x00000200
NPC_VENDOR_POISON = 0x00000400
NPC_VENDOR_REAGENT = 0x00000800
NPC_REPAIR = 0x00001000
NPC_FLIGHTMASTER = 0x00002000
NPC_SPIRITHEALER = 0x00004000
NPC_SPIRITGUIDE = 0x00008000
NPC_INNKEEPER = 0x00010000
NPC_BANKER = 0x00020000
NPC_PETITIONER = 0x00040000
NPC_TABARDDESIGNER = 0x00080000
NPC_BATTLEMASTER = 0x00100000
NPC_AUCTIONEER = 0x00200000
NPC_STABLEMASTER = 0x00400000
NPC_GUILD_BANKER = 0x00800000
NPC_SPELLCLICK = 0x01000000

SEASONAL_FACTIONS = {1555, 774, 775, 1732, 534, 84, 114, 14}

SEASONAL_KEYWORDS = [
    "darkmoon", "brewfest", "midsummer", "noblegarden", "pilgrim",
    "day of the dead", "winter reveler", "spring collector",
    "headless horseman", "costumed orphan", "touring orphan",
    "bountiful", "crown lackey", "crown supply", "pink elekk",
    "fire eater", "elder stormbrow", "ghostly human celebrant",
    "cheerful human spirit", "ribbon pole", "faire cannon",
    "chemical wagon", "[dnd]", "debug target",
]

TEMPORARY_ARENA_KEYWORDS = [
    "arena battlemaster", "arena organizer", "beastmaster",
    "weapons vendor", "paymaster", "fight promoter",
    "druid trainer", "hunter trainer", "shaman trainer",
]

HOSTILE_KEYWORDS = [
    "defias", "kobold", "riverpaw", "murloc", "hogger", "goldtooth",
    "gruff swiftbite", "fedfennel", "narg the taskmaster",
    "ruklar the trapper", "morgaine the sly", "morgan the collector",
    "garrick padfoot", "dead-tooth jack", "surena caledon",
    "erlan drudgemoor", "thuros lightfingers",
]

GUARD_KEYWORDS = ["guard", "marshal", "deputy", "protector", "watchman", "sentinel"]
WORKER_KEYWORDS = ["peasant", "farmer", "farmhand", "lumberjack", "woodworker"]
TRAVELER_KEYWORDS = ["traveling", "traveller", "traveler", "messenger", "expeditionary"]
PREDATOR_KEYWORDS = ["wolf", "prowler", "bear", "spider", "drake", "panther", "cougar"]
PREY_KEYWORDS = [
    "boar", "longsnout", "turkey", "rabbit", "deer", "fawn", "sheep",
    "chicken", "cow", "frog", "cat", "mare", "horse", "steed", "stallion",
    "palomino", "ram", "cockatrice",
]

GENERIC_NAME_KEYWORDS = [
    "guard", "peasant", "worker", "laborer", "miner", "tunneler",
    "geomancer", "bandit", "thug", "cutpurse", "wizard", "dockworker",
    "dockmaster", "runt", "outrunner", "murloc", "wolf", "bear", "spider",
    "boar", "rabbit", "deer", "fawn", "sheep", "chicken", "cow", "frog",
    "cat", "trainer", "vendor", "spirit healer", "reveler", "celebrant",
    "carnie", "apprentice", "collector", "lackey", "sentry", "battlemaster",
    "organizer", "mountaineer", "priest", "table", "barrel", "trigger",
    "bunny", "bonfire", "horse", "mare", "steed", "stallion", "ram",
    "cockatrice", "turkey",
]

def has_any(text, keywords):
    lower = text.lower()
    return any(keyword in lower for keyword in keywords)

def normalize_subname(value):
    if value in (None, "", "NULL"):
        return ""
    return value.strip()

def decoded_role_tags(flag, ai_name, script_name):
    tags = []
    for mask, label in [
        (NPC_GOSSIP, "gossip"),
        (NPC_QUESTGIVER, "questgiver"),
        (NPC_TRAINER, "trainer"),
        (NPC_TRAINER_CLASS, "class_trainer"),
        (NPC_TRAINER_PROFESSION, "profession_trainer"),
        (NPC_VENDOR, "vendor"),
        (NPC_VENDOR_AMMO, "ammo_vendor"),
        (NPC_VENDOR_FOOD, "food_vendor"),
        (NPC_VENDOR_POISON, "poison_vendor"),
        (NPC_VENDOR_REAGENT, "reagent_vendor"),
        (NPC_REPAIR, "repair"),
        (NPC_FLIGHTMASTER, "flightmaster"),
        (NPC_SPIRITHEALER, "spirit_healer"),
        (NPC_SPIRITGUIDE, "spirit_guide"),
        (NPC_INNKEEPER, "innkeeper"),
        (NPC_BANKER, "banker"),
        (NPC_PETITIONER, "petitioner"),
        (NPC_TABARDDESIGNER, "tabard_designer"),
        (NPC_BATTLEMASTER, "battlemaster"),
        (NPC_AUCTIONEER, "auctioneer"),
        (NPC_STABLEMASTER, "stable_master"),
        (NPC_GUILD_BANKER, "guild_banker"),
        (NPC_SPELLCLICK, "spellclick"),
    ]:
        if flag & mask:
            tags.append(label)
    if ai_name:
        tags.append(ai_name.lower())
    if script_name:
        tags.append("scripted")
    return tags

def classify(row):
    entry = int(row["entry"])
    name = row["name"].strip()
    subname = normalize_subname(row["subname"])
    text = f"{name} {subname}".strip()
    lower = text.lower()

    spawn_count = int(row["spawn_count"])
    faction = int(row["faction_template_id"] or 0)
    npcflag = int(row["template_npcflag"] or 0)
    creature_type = int(row["creature_type"] or 0)
    ai_name = row["ai_name"].strip()
    script_name = row["script_name"].strip()

    tags = decoded_role_tags(npcflag, ai_name, script_name)
    role = "TBD"
    notes = ""

    event = faction in SEASONAL_FACTIONS or has_any(text, SEASONAL_KEYWORDS)
    if 26000 <= entry <= 26799 and has_any(text, TEMPORARY_ARENA_KEYWORDS):
        event = True
    if entry in {34382, 34383}:
        event = True

    if entry == 250 and name == "Pa Maclure":
        category = "WORKER_FARMER"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN"
        confidence = "HIGH"
        basis = "repo_verified: persistent farmer vertical slice"
        role = "farmer"
        tags.append("worker")
        notes = "Project README identifies Pa Maclure as the persistent farmer fixture."

    elif event:
        category = "SPECIAL_SCRIPTED"
        mode = "VANILLA_ONLY"
        faction_candidate = "EVENT_VANILLA"
        confidence = "HIGH"
        basis = "seasonal/event/debug evidence"
        role = subname or "event_entity"
        tags.append("seasonal_or_event")

    elif npcflag & (NPC_SPIRITHEALER | NPC_SPIRITGUIDE | NPC_BATTLEMASTER |
                    NPC_PETITIONER | NPC_AUCTIONEER):
        category = "SPECIAL_SCRIPTED"
        mode = "VANILLA_ONLY"
        faction_candidate = "NEUTRAL_SPECIAL"
        confidence = "HIGH"
        basis = "special TrinityCore NPC flag"
        role = next(
            (tag for tag in tags if tag in {
                "spirit_healer", "spirit_guide", "battlemaster",
                "petitioner", "auctioneer"
            }),
            "special_service"
        )

    elif creature_type == 10:
        category = "SPECIAL_SCRIPTED"
        mode = "VANILLA_ONLY"
        faction_candidate = "NEUTRAL_SPECIAL"
        confidence = "HIGH"
        basis = "object/trigger-like creature type"
        role = subname or "scripted_object"

    elif has_any(text, HOSTILE_KEYWORDS) or (creature_type == 7 and faction in {17, 18, 20, 25, 26, 27}):
        category = "HOSTILE_HUMANOID"
        mode = "FULL_AGENT"
        confidence = "HIGH"
        basis = "hostile group name/current faction evidence"
        role = "hostile_humanoid"
        tags.append("hostile")
        if "defias" in lower or faction in {17, 27}:
            faction_candidate = "DEFIAS"
        elif "kobold" in lower or faction in {25, 26}:
            faction_candidate = "KOBOLDS"
        elif "murloc" in lower or faction == 18:
            faction_candidate = "MURLOCS"
        elif "riverpaw" in lower or faction == 20:
            faction_candidate = "RIVERPAW_GNOLLS"
        else:
            faction_candidate = "HOSTILE_HUMANOID_TBD"

    elif has_any(text, GUARD_KEYWORDS):
        category = "GUARD"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN"
        confidence = "HIGH"
        basis = "guard/marshal role in name"
        role = "guard"
        tags.append("guard")

    elif npcflag & (NPC_TRAINER | NPC_TRAINER_CLASS | NPC_TRAINER_PROFESSION) or "trainer" in subname.lower():
        category = "TRAINER"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN" if faction in {11, 12, 123} else "TBD"
        confidence = "HIGH"
        basis = "trainer NPC flag/subname"
        role = subname or "trainer"

    elif npcflag & NPC_VENDOR or any(
        token in subname.lower()
        for token in [
            "merchant", "supplies", "vintner", "fishmonger", "breeder",
            "bartender", "salesman", "seller", "goods", "clothier",
            "bowyer", "armorer", "weaponsmith"
        ]
    ):
        category = "MERCHANT_VENDOR"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN" if faction in {11, 12, 123} else "TBD"
        confidence = "HIGH"
        basis = "vendor NPC flag/subname"
        role = subname or "vendor"

    elif has_any(text, WORKER_KEYWORDS):
        category = "WORKER_FARMER"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN" if faction in {11, 12} else "TBD"
        confidence = "HIGH"
        basis = "worker/farmer role in name"
        role = "worker"
        tags.append("worker")

    elif has_any(text, TRAVELER_KEYWORDS):
        category = "TRAVELER"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN" if faction in {11, 12, 57} else "TBD"
        confidence = "MEDIUM"
        basis = "travel/expedition role in name"
        role = "traveler"
        tags.append("traveler")

    elif creature_type == 1 and (has_any(text, PREDATOR_KEYWORDS) or faction in {22, 38, 32, 44}):
        category = "PREDATOR"
        mode = "FULL_AGENT"
        confidence = "HIGH"
        basis = "predatory beast name/current faction evidence"
        role = "predator"
        tags.append("predator")
        if "wolf" in lower or "prowler" in lower or faction in {38, 32}:
            faction_candidate = "ELWYNN_WOLVES"
        elif "bear" in lower or faction == 44:
            faction_candidate = "ELWYNN_BEARS"
        elif "spider" in lower or faction == 22:
            faction_candidate = "ELWYNN_SPIDERS"
        else:
            faction_candidate = "PREDATOR_TBD"

    elif creature_type in {1, 8, 12} and (has_any(text, PREY_KEYWORDS) or faction in {31, 188, 189, 190}):
        category = "PREY_FAUNA"
        mode = "LIGHTWEIGHT_BACKGROUND"
        confidence = "HIGH"
        basis = "fauna/domestic/non-combat creature evidence"
        role = "fauna"
        tags.append("fauna")
        if faction == 189 or "boar" in lower or "longsnout" in lower:
            faction_candidate = "ELWYNN_BOARS"
        else:
            faction_candidate = "ELWYNN_FAUNA"

    elif creature_type in {8, 12}:
        category = "PREY_FAUNA"
        mode = "LIGHTWEIGHT_BACKGROUND"
        faction_candidate = "ELWYNN_FAUNA"
        confidence = "MEDIUM"
        basis = "critter/non-combat pet creature type"
        role = "fauna"
        tags.append("fauna")

    elif npcflag & NPC_QUESTGIVER:
        category = "QUEST_RELATED"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN" if faction in {11, 12, 123} else "TBD"
        confidence = "HIGH"
        basis = "questgiver NPC flag"
        role = subname or "questgiver"

    elif creature_type == 7 and faction in {11, 12, 123}:
        category = "CIVILIAN"
        mode = "FULL_AGENT"
        faction_candidate = "STORMWIND_ELWYNN"
        confidence = "MEDIUM"
        basis = "humanoid aligned with current Elwynn/Stormwind faction template"
        role = subname or "TBD"

    elif creature_type == 7:
        category = "CIVILIAN"
        mode = "REVIEW_REQUIRED"
        faction_candidate = "TBD"
        confidence = "LOW"
        basis = "humanoid without enough role evidence"
        role = subname or "TBD"

    elif creature_type == 1:
        category = "PREY_FAUNA"
        mode = "REVIEW_REQUIRED"
        faction_candidate = "TBD"
        confidence = "LOW"
        basis = "beast without enough ecological role evidence"
        role = "TBD"

    else:
        category = "SPECIAL_SCRIPTED"
        mode = "REVIEW_REQUIRED"
        faction_candidate = "TBD"
        confidence = "LOW"
        basis = "insufficient evidence"
        role = subname or "TBD"

    if spawn_count != 1 or creature_type != 7 or category == "SPECIAL_SCRIPTED":
        unique_named = "NO"
    elif any(keyword in name.lower() for keyword in GENERIC_NAME_KEYWORDS) or name.startswith("["):
        unique_named = "REVIEW"
    else:
        unique_named = "YES"

    tags = list(dict.fromkeys(tags))
    review_status = "AUTO_HIGH_CONFIDENCE" if confidence == "HIGH" else "MANUAL_REVIEW"

    return {
        "entry": entry,
        "name": name,
        "subname": subname,
        "spawn_count": spawn_count,
        "primary_category": category,
        "participation_mode": mode,
        "role_or_profession_candidate": role,
        "faction_candidate": faction_candidate,
        "unique_named_candidate": unique_named,
        "role_tags": "|".join(tags),
        "confidence": confidence,
        "review_status": review_status,
        "classification_basis": basis,
        "source_faction_template_id": faction,
        "source_npcflag": npcflag,
        "source_creature_type": creature_type,
        "source_ai_name": ai_name,
        "source_script_name": script_name,
        "notes": notes,
    }

def write_coverage(classified, output):
    category_templates = Counter(row["primary_category"] for row in classified)
    mode_templates = Counter(row["participation_mode"] for row in classified)
    confidence_templates = Counter(row["confidence"] for row in classified)
    review_templates = Counter(row["review_status"] for row in classified)

    category_spawns = Counter()
    mode_spawns = Counter()
    for row in classified:
        count = int(row["spawn_count"])
        category_spawns[row["primary_category"]] += count
        mode_spawns[row["participation_mode"]] += count

    total_templates = len(classified)
    total_spawns = sum(int(row["spawn_count"]) for row in classified)

    lines = [
        "# Elwynn Census Classification Coverage",
        "",
        "## Status",
        "",
        "DRAFT automatic proposal for Etapa 3.1. This report does not close 3.1.",
        "",
        "## Input coverage",
        "",
        f"- CreatureEntry rows: {total_templates}",
        f"- Spawn rows represented by those entries: {total_spawns}",
        f"- Classified CreatureEntry rows: {total_templates} / {total_templates} (100%)",
        f"- High-confidence automatic proposals: {confidence_templates['HIGH']}",
        f"- Manual-review rows: {review_templates['MANUAL_REVIEW']}",
        "",
        "## Template categories",
        "",
        "| Category | Templates | Spawns |",
        "|---|---:|---:|",
    ]
    for category in sorted(category_templates):
        lines.append(f"| {category} | {category_templates[category]} | {category_spawns[category]} |")

    lines += [
        "",
        "## Participation proposal",
        "",
        "| Mode | Templates | Spawns |",
        "|---|---:|---:|",
    ]
    for mode in sorted(mode_templates):
        lines.append(f"| {mode} | {mode_templates[mode]} | {mode_spawns[mode]} |")

    lines += [
        "",
        "## Important limitations",
        "",
        "- Classification is derived from the exported template census plus deterministic rules.",
        "- `QUEST_RELATED` currently detects questgiver NPC flags; the current CSV does not contain quest-target/reference tables, so quest targets cannot be proven from this file alone.",
        "- `faction_candidate` is only a 3.1 working hint. It is not the final 3.3 custom faction assignment.",
        "- `participation_mode` is a design proposal, not a runtime-verified setting.",
        "- Rows marked `MANUAL_REVIEW` need explicit human review before the census classification can be treated as accepted.",
        "- Spawn-specific exceptions belong in a later `spawn_overrides.csv`; this file only provides template defaults.",
        "",
        "## Next acceptance work",
        "",
        "1. Review every `MANUAL_REVIEW` row.",
        "2. Add quest-relation evidence from world DB tables before claiming complete quest-related coverage.",
        "3. Create spawn-specific overrides where one CreatureEntry is not semantically uniform.",
        "4. Generate final spawn-level coverage and require every raw spawn to resolve to exactly one accepted classification.",
    ]
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("input", nargs="?", default="data/elwynn/census/templates.csv")
    parser.add_argument("output", nargs="?", default="data/elwynn/census/template_classification.csv")
    parser.add_argument("--coverage", default="data/elwynn/census/coverage.md")
    args = parser.parse_args()

    with Path(args.input).open(newline="", encoding="utf-8-sig") as f:
        source = list(csv.DictReader(f))

    classified = [classify(row) for row in source]
    fields = list(classified[0].keys())

    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fields)
        writer.writeheader()
        writer.writerows(classified)

    coverage = Path(args.coverage)
    coverage.parent.mkdir(parents=True, exist_ok=True)
    write_coverage(classified, coverage)

    review_count = sum(row["review_status"] == "MANUAL_REVIEW" for row in classified)
    total_spawns = sum(int(row["spawn_count"]) for row in classified)
    print(f"Wrote {len(classified)} templates / {total_spawns} spawns.")
    print(f"Manual-review rows: {review_count}")
    print(output)
    print(coverage)

if __name__ == "__main__":
    main()
