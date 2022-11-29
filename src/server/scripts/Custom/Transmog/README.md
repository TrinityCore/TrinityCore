# Transmogrification

#### About
Transmogrification allows you to change the display of an item to something else.
The appearance of items you collect is automatically stored for use on your account.
Requirements can be tweaked in the server configuration file.
Any item should work with transmogrification. Custom items as well. No item is hardcoded to the system.
Has a feature to store sets of displays. This can be removed before compiling or in the configuration file.
Made for 3.3.5a.<br />
Source: http://rochet2.github.io/Transmogrification.html

Video: https://youtu.be/mCHAAfM4Rkg

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/transmog_legion_3.3.5
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog_legion_3.3.5.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog_legion_3.3.5

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 transmog_legion_3.3.5`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `transmog.diff` to the source root folder
- open git bash to source location
- do `git apply transmog.diff`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_transmog.sql` from `\sql\custom` to your databases.
- Optionally you can also insert a transmogrifier NPC to your database by running `\src\server\scripts\Custom\Transmog\sql\world_NPC.sql` to your world database.
- Change the settings to your liking in `worldserver.conf` (Note that you should copy over the new config created from compiling)

#### Usage
Acquire an item visual by looting items.
Equip an item that is suitable for transmogrification.
Talk to a Transmogrifier and select the item slot. Then select the item you want to transmogrify to.
Click to proceed when prompted and your items are transmogrified.
Currently the default settings are according to this: http://wowwiki.wikia.com/Transmogrification#Current_rules
Tweak the settings if you need in worldserver.conf

#### Changelog: [Changelog](https://github.com/Rochet2/TrinityCore/blob/transmog_legion_3.3.5/src/server/scripts/Custom/Transmog/CHANGELOG.md)

#### Bugs and Contact
Report issues and similar to https://rochet2.github.io/
