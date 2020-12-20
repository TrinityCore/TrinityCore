# Multitrainer [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=multitrainer_3.3.5)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
This patch was coded originally by [CyberMist2](https://github.com/CyberMist2).  
Multitrainer allows you to show multiple different trainer windows on an NPC.

Source: http://rochet2.github.io/Multitrainer.html

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/multitrainer_3.3.5
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...multitrainer_3.3.5.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...multitrainer_3.3.5

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 multitrainer_3.3.5`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `multitrainer_3.3.5.diff` to the source root folder
- open git bash to source location
- do `git apply multitrainer_3.3.5.diff`
- use cmake and compile

#### Usage
The NPC is required to have `npcflag` set to `17`. The `trainer_type` can be `0`.  
In C++ you can pass the trainer entry to `SendTrainerList` function.  
In SQL in `world` database you can set the trainer entry to the `gossip_menu_option` table `ActionMenuID` column for an option that has `OptionType` set to `5`.

#### Bugs and Contact
Report issues and similar to https://rochet2.github.io/
