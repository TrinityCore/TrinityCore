#Player and Item Gossip [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=playeritemgossip_7.x)](https://travis-ci.org/Rochet2/TrinityCore)

####About
Enables Item and Player gossip for TrinityCore.<br />
Source: http://rochet2.github.io/Player-and-Item-Gossip.html

####Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/playeritemgossip_7.x
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...playeritemgossip_7.x.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:master...playeritemgossip_7.x

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 playeritemgossip_7.x`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `playeritemgossip.diff` to the source root folder
- open git bash to source location
- do `git apply playeritemgossip.diff`
- use cmake and compile

####Usage
Make a gossip script for player or item like the example scripts.<br/>
If making item script, add the scriptname to DB.<br/>
Compile and test.

####Bugs and Contact
Report issues and similar to https://rochet2.github.io/
