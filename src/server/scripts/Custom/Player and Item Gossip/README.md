# Player and Item Gossip [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=playeritemgossip_3.3.5)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
Enables Item and Player gossip for TrinityCore.<br />
Source: http://rochet2.github.io/Player-and-Item-Gossip.html

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/playeritemgossip_3.3.5
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...playeritemgossip_3.3.5.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...playeritemgossip_3.3.5

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 playeritemgossip_3.3.5`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `playeritemgossip_3.3.5.diff` to the source root folder
- open git bash to source location
- do `git apply playeritemgossip_3.3.5.diff`
- use cmake and compile

#### Usage
Make a gossip script for player or item like the example scripts.<br/>
If making item script, add the scriptname to DB.<br/>
Compile and test.

#### Bugs and Contact
Report issues and similar to https://rochet2.github.io/
