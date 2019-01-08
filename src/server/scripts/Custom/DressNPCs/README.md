# DressNPCs [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=dressnpcs_master)](https://travis-ci.org/Rochet2/TrinityCore)

## About
This patch allows you to dress up armor on NPCs as well as choose their facial features.
Create unique looking NPCs by defining their gender, race, facial features, clothing and much more.
All this is done through the database. No client edits required.

Source: http://rochet2.github.io/Dress-NPCs.html

Known bugs:
- Portraits of the NPCs may not work properly at times - a client side visual bug, cannot fix.
- Some skins are not available. These are usually skins that are not available for players for a specific race. This is a client side limitation, cannot fix.
- Normally NPCs have no sound replies when you talk to them. This is a client side limitation and can be fixed with a client patch. Additionally a **workaround has been included** which sends interaction sounds from the core unless disabled in CMake.

## Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/dressnpcs_master
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...dressnpcs_master.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...dressnpcs_master

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 dressnpcs_master`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `dressnpcs_master.diff` to the source root folder
- open git bash to source location
- do `git apply dressnpcs_master.diff`
- use cmake and compile

Before compiling:
- You can choose in CMake to disable sound workaround if you have a client patch for the NPC sounds. The option is `DISABLE_DRESSNPCS_CORESOUNDS`.

After compiling:
- Make sure you have already created and updated your databases to match your TC version. You can usually do this by running the worldserver once.
- Run SQL files from `src/server/scripts/Custom/DressNPCs/new_install` to their respective databases.

## Usage
- Remember to check server startup errors, they tell when you do things wrong.
- For some skins you must use a specific class, like for death knight skins and eyes.
- Unplayable races like naga are possible to be used as race, experiment :).
- The patch also adds `.reload creature_template_outfit` command. You can use it to reload the creature outfit table for testing.

#### Use through DB
To make an outfit create a row to `creature_template_outfits` table with your desired race, class, gender and equipped items.
- You can freely choose the entry number, but it must be higher than `2147483647`. This is to avoid mixing with existing modelids.
- The items can use positive value as item entry and negative for displayid.
- Appearances are usually between 0 and 10 and they define the look of the item. Different appearances are usually used by mythic and heroic versions of an item. The appearance column takes effect only when using an item entry (a positive value) for the equipped item definition.
- `guildid` refers to an actual guild from characters table and it is used to define the tabard looks of the creature if one is equipped. So you must make a guild and set a tabard for it and use it's ID in the column for the outfit.
- `npcsoundsid` refers to `NPCSounds.dbc/db2`. In this column you can define what gossip replies to use for the NPC with the core side workaround for missing sounds for gossip. To create completely new sound combinations you can use hotfixes database `npc_sounds` table or edit the DBC file.

You can use the outfit entry as modelid in creature template, smart scripts and elsewhere in the DB and core for setting a modelid/displayid, like `creature->SetDisplayId(outfitid)`.

#### Use through C++
You can create an outfit in C++, here is an example:
```c++
#include "CreatureOutfit.h" // CreatureOutfit, shared_ptr
#include "Player.h" // EquipmentSlots
#include "SharedDefines.h" // Gender
#include "Creature.h" // Creature

// Create outfit
std::shared_ptr<CreatureOutfit> outfit(new CreatureOutfit(RACE_NIGHTELF, GENDER_MALE));
outfit->SetItemDisplay(EQUIPMENT_SLOT_SHOULDERS, 43617);
outfit->skin = 2;

// set it for a creature
creature->SetOutfit(outfit);
```

In C++ if you absolutely must change the displayid of a creature wears an outfit without removing the outfit you can use `creature->SetDisplayIdRaw(modelid);`.

## Bugs and Contact
Report issues and similar to http://rochet2.github.io/
