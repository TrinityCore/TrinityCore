# DressNPCs [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=dressnpcs)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
This patch allows you to dress up armor on NPCs as well as choose their facial features.
Create unique looking NPCs by defining their gender, race, facial features, clothing and much more.
All this is done in the database. No client edits required.

Source: http://rochet2.github.io/Dress-NPCs.html

Known bugs:
- Portraits of the NPCs may not work properly at times - a client side visual bug (blizzard's fault).
- Normally NPCs have no sound replies when you talk to them. This is a client side limitation and can be fixed with a client patch. Additionally a **workaround has been included** which sends interaction sounds from the core unless disabled in CMake.

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/dressnpcs
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...dressnpcs.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...dressnpcs

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 dressnpcs`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `dressnpcs.diff` to the source root folder
- open git bash to source location
- do `git apply dressnpcs.diff`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_dressnpcs.sql` from `\sql\custom` to your databases.

#### Usage
Before compiling the core you can choose in CMake to disable sound workaround if you have a client patch for the NPC sounds.

To make an outfit create a row to `creature_template_outfits` table with your desired race, class, gender and equipped items. You can freely choose the entry number.
- The items can use positive value as item entry and negative for displayid.
- Appearances are usually between 0 and 10 and they define the look of the item. Different appearances are usually used by mythic and heroic versions of an item. An appearance only works when using an item entry (a positive value) for the equipped item definition.
- `guildid` refers to an actual guild from characters table and it is used to define the tabard looks of the creature if one is equipped.
- `npcsoundsid` refers to `NPCSounds.dbc/db2`. You can define what gossip replies to use for the NPC with the core side workaround for missing sounds for gossip. To create completely new sound combinations you can use hotfixes database or edit the DBC file.

Create an NPC. Set the `creature_template_outfits` entry to the modelID column in `creature_template`, but __make it negative__.

Clear wow cache folder, restart server and spawn the NPC. Remember to check startup errors.

The patch also adds `.reload creature_template_outfit` command. You can use it to reload the creature outfit table for testing.

#### Bugs and Contact
Report issues and similar to http://rochet2.github.io/
