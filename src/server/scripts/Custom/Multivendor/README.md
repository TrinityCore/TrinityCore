# Multivendor [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=multivendor)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
Allows you to show gossip options that show different vendors from npc_vendor.<br />
Source: http://rochet2.github.io/Multivendor.html

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/multivendor
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...multivendor.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...multivendor

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 multivendor`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `multivendor.diff` to the source root folder
- open git bash to source location
- do `git apply multivendor.diff`
- use cmake and compile

#### Usage
Set your NPC to have gossip and vendor NPCflags (129)<br />
Add a gossip menu for him and add a new option to it.<br />
The option needs to have option_id set to 3 so it acts as a vendor button,<br />
npc_option_npcflag can be 1 or 128 (shows only if the NPC has vendor flag then)<br />
and the action_menu_id is the vendor entry from npc_vendor that you want to show to the player.<br />

YOU CAN also send menus from C++. All you need to do is to provide the vendor entry to the<br />
`void WorldSession::SendListInventory(ObjectGuid guid, uint32 vendorEntry)` function.

The npc add item command was modified so you can add items to multivendors as well.<br />
The last vendor window must have been the multivendor you want to add your item to.<br />
After opening the window you need to type `.npc add item #itemId <#maxcount><#incrtime><#extendedcost> 1`<br />
The 1 in the end specifies that you are adding the item to the multivendor currently open.<br />
Same thing works with `.npc delete item #itemId 1`
