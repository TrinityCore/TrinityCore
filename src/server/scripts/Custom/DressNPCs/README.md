#DressNPCs [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=dressnpcs_7.x)](https://travis-ci.org/Rochet2/TrinityCore)

####About
You can make an NPC, set the displays or items you want him to have and his race and gender (defines displayID) as well as facial features and skin color.
All this is done in the database. No client edits needed. Completely server side.
Source: http://rochet2.github.io/Dress-NPCs.html

Known bugs:
- Portraits of the NPCs may not work properly at times - a client side visual bug.
- NPCs have no sound replies when you talk to them. This is because of the models used and there is no fix without editing client.

####Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/dressnpcs_7.x
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...dressnpcs_7.x.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...dressnpcs_7.x

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 dressnpcs_7.x`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `dressnpcs_7.x.diff` to the source root folder
- open git bash to source location
- do `git apply dressnpcs_7.x.diff`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_dressnpcs.sql` from `\sql\custom` to your databases.

####Usage
Create a row to `creature_template_outfits` table with your desired race, class, gender and equipped items.  
***Note*** The items can use positive value as item entry and negative for displayid.  
***Note*** After wotlk the display system has changed slightly. If you want special appearance on items, find the correct displayid and use it or use an entry which has the appearance id added to it in the following way `((AppearanceModID << 32) | item_entry)`. Appearances are usually between 0 and 10.  
Create an NPC. Set the `creature_template_outfits` entry to the modelID column in `creature_template`, but __make it negative__.  
Clear wow cache folder, restart server and spawn the NPC.  
The patch also adds `.reload creature_template_outfit` command. You can use it to reload the creature outfit table again for testing.  
You should be able to reload the table with new entries of ingame creatures. Relog to update the visual look of creatures with the reloaded data.  
__Using reload is not recommended.__ (not outfit nor template) Use them only for testing and debugging purposes. Not for live servers.

####Bugs and Contact
Report issues and similar to http://rochet2.github.io/
