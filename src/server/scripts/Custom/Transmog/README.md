#Transmogrification [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=transmog)](https://travis-ci.org/Rochet2/TrinityCore)

####About
Transmogrification allows you to change the display of an item to something else.
You can use any item in your bags as source of display, as long as it fits the requirements.
Requirements can be tweaked in the server configuration file.
Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system.
Has a feature to store sets of displays. This can be removed before compiling or in the configuration file.
Made for 3.3.5a.<br />
Source: http://rochet2.github.io/Transmogrification.html

Video: https://youtu.be/xtH4ogz12iM

####Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/transmog
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 transmog`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `transmog.diff` to the source root folder
- open git bash to source location
- do `git apply transmog.diff`
- use cmake and compile

After compiling:
- Navigate to `\src\server\scripts\Custom\Transmog\sql\`
- Run `characters.sql` to your characters database
- Run `world_texts.sql` to your world database
 - optionally you can also insert a transmogrifier NPC to your database by running `world_NPC.sql` to your world database.
- Change the settings to your liking in `worldserver.conf` (Note that you should copy over the new config created)

####Usage
Equip an item that is suitable for transmogrification.
Have an item in your bags that is suitable to be used to transmogrify the equipped item
Talk to Transmogrifier and select the item slot. Then select the item you want to transmogrify to.
Click to proceed when prompted and your items are transmogrified.
Currently the default settings are according to this: http://wowwiki.wikia.com/Transmogrification#Current_rules
Tweak the settings if you need in worldserver.conf

####Changelog: [Changelog](https://github.com/Rochet2/TrinityCore/blob/transmog/src/server/scripts/Custom/Transmog/CHANGELOG.md)

####Bugs and Contact
Report issues and similar to https://rochet2.github.io/
