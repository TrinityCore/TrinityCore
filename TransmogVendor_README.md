#Transmogrification Display Vendor [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=transmogvendor)](https://travis-ci.org/Rochet2/TrinityCore)

####About
Original idea by LilleCarl.
Coding work and execution by Rochet2.
Transmogrification Display Vendor allows you to change the display of an item to something else.
You can use any item display in the game, as long as it fits the requirements.
Requirements can be tweaked in the `TransmogDisplayVendor.cpp` file.
Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system.
Has a feature to work with the regular [Transmogrification](http://rochet2.github.io/Transmogrification.html). This can be enabled before compiling in `TransmogDisplayVendor.h`.
Made for 3.3.5a.<br />
Source: http://www.trinitycore.org/f/topic/7993-transmogrification-display-vendor/

Video: https://youtu.be/PIheEziN_dY

####Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/transmogvendor
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmogvendor.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmogvendor

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 transmogvendor`
- use cmake and compile

Using diff *(recommended)*:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `transmogvendor.diff` to the source root folder
- open git bash to source location
- do `git apply transmogvendor.diff`
 - if using the regular transmogrification, simply use --reject with either and overwrite the parts of the other. Order doesnt matter, as long as duplicate code doesnt exist.
- use cmake and compile

After compiling:
- Navigate to `\src\server\scripts\Custom\TransmogDisplayVendor\sql\`
- Run `characters.sql` to your characters database
 - This is same file as with the regular transmog
- Optionally you can also insert a transmogrifier NPC to your database by running `world_NPC.sql` to your world database.

####Usage
Equip an item that is suitable for transmogrification.
Talk to Transmogrifier and select the item slot. Then select the quality and then the item you want to transmogrify to.

####Bugs and Contact
Report issues and similar to http://rochet2.github.io/
