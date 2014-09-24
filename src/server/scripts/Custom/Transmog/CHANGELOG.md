####6.1
- Update to newest TC
- Made guid changes

####6.0
- Removed mutex locks - Different code style, works with ACE and boost, probably more efficient
- Added regex checking for preset name
- Fixed random properties not registering as item stats (Thanks Aokromes)
- Made the code / patch compatible with herbs+veins patch (Thanks Aokromes)
- Moved to bithub - Allows autogenerate patch and diff and management is easier:
- https://github.com/Rochet2/TrinityCore/tree/transmog
- Gist was at: https://gist.github.com/Rochet2/2c8765b53f8dda1e296a

####5.6
- Fixed few linux compile warnings
- Moved to GIST
- Old versions etc still available from:
https://drive.google.com/folderview?id=0Bx5knS2IsjatTlVtWHRwbUN3VlE&usp=sharing

####5.5
- Updated to latest TC  rev
- Fixed some tabs to spaces
- Fixed a warning on gcc

####5.4
- Updated to latest TC rev

####5.3
- Rewrote transmogrification logic to be blizzlike.
- Implemented multithread support.
- Tweaked saving to work so that your data is saved whenever the player is saved.
- This means that crashes can not be abused and DB wont have SQL executing and querying all the time.

####5.2
- Some logic fixes and other

####5.1
- Config options should now work properly. Please notify here if some still bug
- Can transmog bows with guns and crossbows
- Can transmog cloth to leather with config settings set
- Can transmog robes with chest pieces
- You should now be able to view the info menus with the new NPC
- Allow shirt's to be transmogrified (were shown in menu but you weren't able to before)
- Mirror image (mage spell) should now correctly copy the transmogrified outfit. Before it still got your old item displays.
- Added new config options:

####5.0
- Ripped cata branch functions and thus altered how everything is coded pretty much.
- Dropped translation support
- Added colored item links as well as icons all over the place
- Added new feature: Sets
- Added many config options, for example to allow cloth and plate to be transmogrified with each other

####4.0
- I changed all the methods to normal functions and moved them to Transmogrification.cpp
- I also updated the way transmogrifications are stored

####3.9
- Nothing was added
- Now supporting latest TDB: 0d3554d4bf
- Also tested and works on latest
- Changed diff to patch for better compability

####3.8
- Nothing was added
- Now supporting latest TDB: da9865b683

####3.7
- Quick update to the patch for latest trinitycore version

####3.6
- Updated the code to work with the new trinitycore changes
- Added config (See the bottom of worldserver.conf)
- Added token cost possibility -- in config
- Added cost modification possibility -- in config
- Added quality requirement modification possibility -- in config

####3.5
- Fixed a crash on item deletion from guild deleting and more

####3.4
- Added localization possibilities, even though I am not quite sure if it works and if it is good or good enough. Only tested that english works
- Added possibility to disable gold cost before compiling
- Cleaned all the code I could find to TrinityCore standards .. I think

####3.3
- Transformed the script into a full coremod instead of having some code in the gossip script. This allows the transmogrification methods to be used on any item anywhere.
- Changed the way fake display entries are stored in the core. Instead of having a new variable for the item class, I am now having a contained, much like locales have.
- Changed the files into one patch file like Aokromes suggested. You can find the DB table creation SQLs from sql/characters_transmogrification/
- Removed prepared statements
- Fake display entries are now loaded when the server starts up. All nonexistant item guids will be deleted before loading and when loading, all invalid item entries are deleted (deleted some custom items aye?

####3.2
- Fixed an issue with DB saving not taking action on login or server restart.

####3.1
- Corrected the quality check, which was left to return true in any case
- Fixed invisible item entries from newly created items (.additem for example)

####3.0
- It will have mailing and auction etc restrictions properly coded (yay, no more Fake owner!)
- Having its own prepared statement now
- Moved loading transmogs to the item loading part.
- The script should now be added to scriptloader by the patch. So you just need to add it to solution.
- Included an NPC sql for everyone with NPC problems :3

####2.2
- Added a few sounds, altered to use switch instead of an IF block
- Modified to have a separate table
- And more?

####2.1
- Fixed a crash when getting item template of item entry 0

####2.0
- Possibly more ..
- Implemented cost
- Changed quality checks
- Fixed few problems
- Changed some messages for more blizzlike feeling
- After trying to transmogrify or remove a transmogrification, you get to the item selection screen instead of main menu
- Added Remove Transmogrification buttons and update main menu button (removed nevermind)
- Added more checks for safety and blizzlike feeling

####1.0
- Added DB saving and remove transmogrifications option -> patch, sql and script needed