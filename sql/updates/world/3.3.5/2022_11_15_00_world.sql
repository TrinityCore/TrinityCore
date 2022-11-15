-- Correct gold dropped by mobs. (Credit Vmangos)

-- These mobs have their min and max gold reversed.
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry` IN (16194, 16215, 16216);
UPDATE `creature_template` SET `mingold`=1404186, `maxgold`=11012303 WHERE `entry`=15547;

-- Update gold dropped by mobs based on classic sniffs.
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=36 && `mingold`=13; -- Harvest Golem (sample size 30)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=36 && `maxgold`=21; -- Harvest Golem (sample size 30)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=38 && `mingold`=2; -- Defias Thug (sample size 134)
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=38 && `maxgold`=7; -- Defias Thug (sample size 134)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=40 && `mingold`=5; -- Kobold Miner (sample size 65)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=46 && `mingold`=9; -- Murloc Forager (sample size 26)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=46 && `maxgold`=17; -- Murloc Forager (sample size 26)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=80 && `mingold`=2; -- Kobold Laborer (sample size 47)
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=80 && `maxgold`=8; -- Kobold Laborer (sample size 47)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=94 && `mingold`=5; -- Defias Cutpurse
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=95 && `mingold`=12; -- Defias Smuggler (sample size 60)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=95 && `maxgold`=20; -- Defias Smuggler (sample size 60)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=97 && `mingold`=8; -- Riverpaw Runt
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=98 && `maxgold`=32; -- Riverpaw Taskmaster
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=100 && `mingold`=13; -- Gruff Swiftbite
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=114 && `mingold`=16; -- Harvest Watcher (sample size 88)
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=114 && `maxgold`=26; -- Harvest Watcher (sample size 88)
UPDATE `creature_template` SET `maxgold`=42 WHERE `entry`=115 && `maxgold`=32; -- Harvest Reaper
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=116 && `mingold`=8; -- Defias Bandit (sample size 48)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=116 && `maxgold`=15; -- Defias Bandit (sample size 48)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=117 && `mingold`=12; -- Riverpaw Gnoll (sample size 26)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=117 && `maxgold`=20; -- Riverpaw Gnoll (sample size 26)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=121 && `mingold`=18; -- Defias Pathstalker
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=121 && `maxgold`=28; -- Defias Pathstalker
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=122 && `mingold`=21; -- Defias Highwayman (sample size 48)
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=122 && `maxgold`=32; -- Defias Highwayman (sample size 48)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=123 && `mingold`=14; -- Riverpaw Mongrel
UPDATE `creature_template` SET `maxgold`=28 WHERE `entry`=123 && `maxgold`=24; -- Riverpaw Mongrel
UPDATE `creature_template` SET `maxgold`=35 WHERE `entry`=124 && `maxgold`=28; -- Riverpaw Brute
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=126 && `mingold`=13; -- Murloc Coastrunner
UPDATE `creature_template` SET `maxgold`=25 WHERE `entry`=126 && `maxgold`=22; -- Murloc Coastrunner
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=127 && `mingold`=21; -- Murloc Tidehunter
UPDATE `creature_template` SET `maxgold`=47 WHERE `entry`=127 && `maxgold`=32; -- Murloc Tidehunter
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=171 && `mingold`=17; -- Murloc Warrior
UPDATE `creature_template` SET `maxgold`=36 WHERE `entry`=171 && `maxgold`=27; -- Murloc Warrior
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=202 && `mingold`=31; -- Skeletal Horror
UPDATE `creature_template` SET `maxgold`=63 WHERE `entry`=203 && `maxgold`=40; -- Skeletal Mage
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=205 && `mingold`=41; -- Nightbane Dark Runner
UPDATE `creature_template` SET `maxgold`=144 WHERE `entry`=205 && `maxgold`=58; -- Nightbane Dark Runner
UPDATE `creature_template` SET `maxgold`=169 WHERE `entry`=206 && `maxgold`=61; -- Nightbane Vile Fang
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=210 && `mingold`=37; -- Bone Chewer
UPDATE `creature_template` SET `maxgold`=143 WHERE `entry`=212 && `maxgold`=61; -- Splinter Fist Warrior
UPDATE `creature_template` SET `maxgold`=110 WHERE `entry`=215 && `maxgold`=48; -- Defias Night Runner
UPDATE `creature_template` SET `maxgold`=75 WHERE `entry`=218 && `maxgold`=47; -- Grave Robber
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=232 && `mingold`=30; -- Farmer Ray
UPDATE `creature_template` SET `maxgold`=103 WHERE `entry`=232 && `maxgold`=44; -- Farmer Ray
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=257 && `maxgold`=7; -- Kobold Worker (sample size 64)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=285 && `mingold`=5; -- Murloc (sample size 23)
UPDATE `creature_template` SET `maxgold`=118 WHERE `entry`=300 && `maxgold`=62; -- Zzarc' Vul
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=315 && `mingold`=58; -- Stalvan Mistmantle
UPDATE `creature_template` SET `maxgold`=249 WHERE `entry`=315 && `maxgold`=81; -- Stalvan Mistmantle
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=327 && `mingold`=7; -- Goldtooth
UPDATE `creature_template` SET `maxgold`=141 WHERE `entry`=391 && `maxgold`=40; -- Old Murk-Eye
UPDATE `creature_template` SET `maxgold`=1265 WHERE `entry`=412 && `maxgold`=961; -- Stitches
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=422 && `mingold`=22; -- Murloc Flesheater
UPDATE `creature_template` SET `maxgold`=58 WHERE `entry`=422 && `maxgold`=33; -- Murloc Flesheater
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=423 && `mingold`=17; -- Redridge Mongrel (sample size 21)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=423 && `maxgold`=28; -- Redridge Mongrel (sample size 21)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=424 && `mingold`=19; -- Redridge Poacher
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=424 && `maxgold`=29; -- Redridge Poacher
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=426 && `mingold`=20; -- Redridge Brute (sample size 22)
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=426 && `maxgold`=32; -- Redridge Brute (sample size 22)
UPDATE `creature_template` SET `maxgold`=82 WHERE `entry`=429 && `maxgold`=48; -- Shadowhide Darkweaver
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=430 && `mingold`=21; -- Redridge Mystic (sample size 21)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=430 && `maxgold`=32; -- Redridge Mystic (sample size 21)
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=431 && `mingold`=37; -- Shadowhide Slayer
UPDATE `creature_template` SET `maxgold`=94 WHERE `entry`=431 && `maxgold`=53; -- Shadowhide Slayer
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=432 && `maxgold`=45; -- Shadowhide Brute
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=433 && `mingold`=29; -- Shadowhide Gnoll
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=433 && `maxgold`=43; -- Shadowhide Gnoll
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=434 && `mingold`=27; -- Rabid Shadowhide Gnoll (sample size 37)
UPDATE `creature_template` SET `maxgold`=87 WHERE `entry`=434 && `maxgold`=40; -- Rabid Shadowhide Gnoll (sample size 37)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=435 && `mingold`=33; -- Blackrock Champion (sample size 38)
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=435 && `maxgold`=48; -- Blackrock Champion (sample size 38)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=437 && `mingold`=27; -- Blackrock Renegade
UPDATE `creature_template` SET `maxgold`=79 WHERE `entry`=437 && `maxgold`=40; -- Blackrock Renegade
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=440 && `mingold`=24; -- Blackrock Grunt
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=440 && `maxgold`=36; -- Blackrock Grunt
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=441 && `mingold`=19; -- Black Dragon Whelp (sample size 26)
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=441 && `maxgold`=30; -- Black Dragon Whelp (sample size 26)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=446 && `mingold`=23; -- Redridge Basher
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=448 && `mingold`=45; -- Hogger
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=449 && `mingold`=19; -- Defias Knuckleduster
UPDATE `creature_template` SET `maxgold`=47 WHERE `entry`=449 && `maxgold`=30; -- Defias Knuckleduster
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=450 && `maxgold`=29; -- Defias Renegade Mage
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=452 && `maxgold`=31; -- Riverpaw Bandit
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=453 && `mingold`=22; -- Riverpaw Mystic
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=456 && `mingold`=14; -- Murloc Minor Oracle
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=458 && `mingold`=19; -- Murloc Hunter
UPDATE `creature_template` SET `maxgold`=45 WHERE `entry`=458 && `maxgold`=30; -- Murloc Hunter
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=473 && `mingold`=10; -- Morgan the Collector
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=474 && `mingold`=10; -- Defias Rogue Wizard
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=475 && `mingold`=4; -- Kobold Tunneler (sample size 87)
UPDATE `creature_template` SET `maxgold`=11 WHERE `entry`=475 && `maxgold`=10; -- Kobold Tunneler (sample size 87)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=476 && `mingold`=6; -- Kobold Geomancer
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=478 && `mingold`=10; -- Riverpaw Outrunner (sample size 39)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=478 && `maxgold`=18; -- Riverpaw Outrunner (sample size 39)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=480 && `mingold`=10; -- Rusty Harvest Golem
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=481 && `mingold`=10; -- Defias Footpad
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=485 && `mingold`=26; -- Blackrock Outrunner
UPDATE `creature_template` SET `maxgold`=70 WHERE `entry`=485 && `maxgold`=39; -- Blackrock Outrunner
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=500 && `mingold`=13; -- Riverpaw Scout
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=500 && `maxgold`=22; -- Riverpaw Scout
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=501 && `maxgold`=26; -- Riverpaw Herbalist
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=502 && `mingold`=17; -- Benny Blaanco
UPDATE `creature_template` SET `maxgold`=110 WHERE `entry`=503 && `maxgold`=61; -- Lord Malathrom
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=504 && `mingold`=13; -- Defias Trapper (sample size 55)
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=504 && `maxgold`=22; -- Defias Trapper (sample size 55)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=506 && `mingold`=21; -- Sergeant Brashclaw
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=513 && `mingold`=16; -- Murloc Netter
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=513 && `maxgold`=26; -- Murloc Netter
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=515 && `mingold`=12; -- Murloc Raider
UPDATE `creature_template` SET `maxgold`=21 WHERE `entry`=515 && `maxgold`=20; -- Murloc Raider
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=517 && `mingold`=20; -- Murloc Oracle
UPDATE `creature_template` SET `maxgold`=53 WHERE `entry`=517 && `maxgold`=31; -- Murloc Oracle
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=519 && `mingold`=17; -- Slark
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=520 && `mingold`=23; -- Brack
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=533 && `mingold`=37; -- Nightbane Shadow Weaver
UPDATE `creature_template` SET `maxgold`=136 WHERE `entry`=533 && `maxgold`=53; -- Nightbane Shadow Weaver
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=544 && `mingold`=28; -- Murloc Nightcrawler
UPDATE `creature_template` SET `maxgold`=72 WHERE `entry`=544 && `maxgold`=41; -- Murloc Nightcrawler
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=545 && `mingold`=23; -- Murloc Tidecaller
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=545 && `maxgold`=35; -- Murloc Tidecaller
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=548 && `mingold`=20; -- Murloc Minor Tidecaller
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=548 && `maxgold`=30; -- Murloc Minor Tidecaller
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=568 && `mingold`=33; -- Shadowhide Warrior
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=568 && `maxgold`=48; -- Shadowhide Warrior
UPDATE `creature_template` SET `maxgold`=106 WHERE `entry`=570 && `maxgold`=59; -- Brain Eater
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=572 && `mingold`=23; -- Leprithus
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=578 && `mingold`=24; -- Murloc Scout
UPDATE `creature_template` SET `maxgold`=64 WHERE `entry`=578 && `maxgold`=36; -- Murloc Scout
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=579 && `maxgold`=45; -- Shadowhide Assassin
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=580 && `maxgold`=38; -- Redridge Drudger
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=584 && `mingold`=50; -- Kazon
UPDATE `creature_template` SET `maxgold`=127 WHERE `entry`=584 && `maxgold`=80; -- Kazon
UPDATE `creature_template` SET `mingold`=39 WHERE `entry`=587 && `mingold`=55; -- Bloodscalp Warrior (sample size 50)
UPDATE `creature_template` SET `maxgold`=226 WHERE `entry`=587 && `maxgold`=76; -- Bloodscalp Warrior (sample size 50)
UPDATE `creature_template` SET `maxgold`=199 WHERE `entry`=588 && `maxgold`=78; -- Bloodscalp Scout
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=589 && `mingold`=16; -- Defias Pillager (sample size 40)
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=589 && `maxgold`=26; -- Defias Pillager (sample size 40)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=590 && `mingold`=15; -- Defias Looter (sample size 41)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=590 && `maxgold`=25; -- Defias Looter (sample size 41)
UPDATE `creature_template` SET `maxgold`=243 WHERE `entry`=595 && `maxgold`=75; -- Bloodscalp Hunter
UPDATE `creature_template` SET `maxgold`=280 WHERE `entry`=597 && `maxgold`=83; -- Bloodscalp Berserker
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=598 && `mingold`=23; -- Defias Miner (sample size 48)
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=598 && `maxgold`=35; -- Defias Miner (sample size 48)
UPDATE `creature_template` SET `maxgold`=128 WHERE `entry`=604 && `maxgold`=57; -- Plague Spreader
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=615 && `mingold`=31; -- Blackrock Tracker (sample size 21)
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=615 && `maxgold`=45; -- Blackrock Tracker (sample size 21)
UPDATE `creature_template` SET `mingold`=49 WHERE `entry`=619 && `mingold`=62; -- Defias Conjurer
UPDATE `creature_template` SET `maxgold`=178 WHERE `entry`=622 && `maxgold`=119; -- Goblin Engineer
UPDATE `creature_template` SET `mingold`=26 WHERE `entry`=634 && `mingold`=77; -- Defias Overseer
UPDATE `creature_template` SET `maxgold`=158 WHERE `entry`=634 && `maxgold`=105; -- Defias Overseer
UPDATE `creature_template` SET `mingold`=49 WHERE `entry`=636 && `mingold`=89; -- Defias Blackguard
UPDATE `creature_template` SET `mingold`=51 WHERE `entry`=639 && `mingold`=318; -- Edwin VanCleef
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=641 && `mingold`=87; -- Goblin Woodcarver
UPDATE `creature_template` SET `maxgold`=161 WHERE `entry`=641 && `maxgold`=119; -- Goblin Woodcarver
UPDATE `creature_template` SET `mingold`=159 WHERE `entry`=642 && `mingold`=197; -- Sneed's Shredder
UPDATE `creature_template` SET `maxgold`=144 WHERE `entry`=643 && `maxgold`=70; -- Sneed
UPDATE `creature_template` SET `mingold`=108 WHERE `entry`=644 && `mingold`=225; -- Rhahk'Zor
UPDATE `creature_template` SET `mingold`=58 WHERE `entry`=645 && `mingold`=159; -- Cookie
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=646 && `mingold`=201; -- Mr. Smite
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=647 && `mingold`=159; -- Captain Greenskin
UPDATE `creature_template` SET `mingold`=44 WHERE `entry`=657 && `mingold`=93; -- Defias Pirate (sample size 26)
UPDATE `creature_template` SET `maxgold`=196 WHERE `entry`=657 && `maxgold`=126; -- Defias Pirate (sample size 26)
UPDATE `creature_template` SET `mingold`=43 WHERE `entry`=660 && `mingold`=54; -- Bloodscalp Witch Doctor
UPDATE `creature_template` SET `maxgold`=289 WHERE `entry`=660 && `maxgold`=75; -- Bloodscalp Witch Doctor
UPDATE `creature_template` SET `mingold`=48 WHERE `entry`=667 && `mingold`=66; -- Skullsplitter Warrior (sample size 39)
UPDATE `creature_template` SET `maxgold`=325 WHERE `entry`=667 && `maxgold`=91; -- Skullsplitter Warrior (sample size 39)
UPDATE `creature_template` SET `maxgold`=374 WHERE `entry`=669 && `maxgold`=105; -- Skullsplitter Hunter
UPDATE `creature_template` SET `mingold`=58 WHERE `entry`=670 && `mingold`=68; -- Skullsplitter Witch Doctor
UPDATE `creature_template` SET `maxgold`=358 WHERE `entry`=670 && `maxgold`=94; -- Skullsplitter Witch Doctor
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=671 && `mingold`=59; -- Bloodscalp Headhunter (sample size 31)
UPDATE `creature_template` SET `maxgold`=281 WHERE `entry`=671 && `maxgold`=83; -- Bloodscalp Headhunter (sample size 31)
UPDATE `creature_template` SET `maxgold`=448 WHERE `entry`=672 && `maxgold`=97; -- Skullsplitter Spiritchaser
UPDATE `creature_template` SET `mingold`=55 WHERE `entry`=674 && `mingold`=71; -- Venture Co. Strip Miner (sample size 38)
UPDATE `creature_template` SET `maxgold`=360 WHERE `entry`=674 && `maxgold`=98; -- Venture Co. Strip Miner (sample size 38)
UPDATE `creature_template` SET `maxgold`=249 WHERE `entry`=675 && `maxgold`=103; -- Venture Co. Foreman
UPDATE `creature_template` SET `maxgold`=340 WHERE `entry`=676 && `maxgold`=91; -- Venture Co. Surveyor
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=677 && `maxgold`=84; -- Venture Co. Tinkerer
UPDATE `creature_template` SET `maxgold`=1040 WHERE `entry`=678 && `maxgold`=391; -- Mosh'Ogg Mauler
UPDATE `creature_template` SET `maxgold`=832 WHERE `entry`=679 && `maxgold`=341; -- Mosh'Ogg Shaman
UPDATE `creature_template` SET `maxgold`=230 WHERE `entry`=694 && `maxgold`=74; -- Bloodscalp Axe Thrower (sample size 38)
UPDATE `creature_template` SET `mingold`=53 WHERE `entry`=696 && `mingold`=66; -- Skullsplitter Axe Thrower (sample size 33)
UPDATE `creature_template` SET `maxgold`=323 WHERE `entry`=696 && `maxgold`=91; -- Skullsplitter Axe Thrower (sample size 33)
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=697 && `mingold`=51; -- Bloodscalp Shaman (sample size 47)
UPDATE `creature_template` SET `maxgold`=229 WHERE `entry`=697 && `maxgold`=71; -- Bloodscalp Shaman (sample size 47)
UPDATE `creature_template` SET `maxgold`=215 WHERE `entry`=699 && `maxgold`=78; -- Bloodscalp Beastmaster
UPDATE `creature_template` SET `maxgold`=211 WHERE `entry`=701 && `maxgold`=72; -- Bloodscalp Mystic
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=702 && `mingold`=55; -- Bloodscalp Scavenger
UPDATE `creature_template` SET `maxgold`=183 WHERE `entry`=702 && `maxgold`=76; -- Bloodscalp Scavenger
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=706 && `maxgold`=7; -- Frostmane Troll Whelp (sample size 67)
UPDATE `creature_template` SET `maxgold`=934 WHERE `entry`=709 && `maxgold`=364; -- Mosh'Ogg Warmonger
UPDATE `creature_template` SET `maxgold`=1098 WHERE `entry`=710 && `maxgold`=307; -- Mosh'Ogg Spellcrafter
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=712 && `mingold`=16; -- Redridge Thrasher
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=732 && `mingold`=9; -- Murloc Lurker (sample size 39)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=732 && `maxgold`=17; -- Murloc Lurker (sample size 39)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=735 && `mingold`=5; -- Murloc Streamrunner
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=740 && `mingold`=47; -- Adolescent Whelp (sample size 36)
UPDATE `creature_template` SET `maxgold`=239 WHERE `entry`=740 && `maxgold`=66; -- Adolescent Whelp (sample size 36)
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=741 && `mingold`=50; -- Dreaming Whelp (sample size 40)
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=741 && `maxgold`=70; -- Dreaming Whelp (sample size 40)
UPDATE `creature_template` SET `maxgold`=362 WHERE `entry`=746 && `maxgold`=115; -- Elder Dragonkin
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=747 && `mingold`=74; -- Marsh Murloc (sample size 22)
UPDATE `creature_template` SET `maxgold`=346 WHERE `entry`=747 && `maxgold`=102; -- Marsh Murloc (sample size 22)
UPDATE `creature_template` SET `mingold`=59 WHERE `entry`=750 && `mingold`=75; -- Marsh Inkspewer (sample size 87)
UPDATE `creature_template` SET `maxgold`=404 WHERE `entry`=750 && `maxgold`=103; -- Marsh Inkspewer (sample size 87)
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=751 && `mingold`=78; -- Marsh Flesheater (sample size 95)
UPDATE `creature_template` SET `maxgold`=421 WHERE `entry`=751 && `maxgold`=107; -- Marsh Flesheater (sample size 95)
UPDATE `creature_template` SET `mingold`=86 WHERE `entry`=752 && `mingold`=73; -- Marsh Oracle (sample size 34)
UPDATE `creature_template` SET `maxgold`=453 WHERE `entry`=752 && `maxgold`=100; -- Marsh Oracle (sample size 34)
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=754 && `maxgold`=83; -- Rebel Watchman
UPDATE `creature_template` SET `maxgold`=228 WHERE `entry`=755 && `maxgold`=103; -- Lost One Mudlurker
UPDATE `creature_template` SET `mingold`=51 WHERE `entry`=757 && `mingold`=61; -- Lost One Fisherman
UPDATE `creature_template` SET `maxgold`=254 WHERE `entry`=757 && `maxgold`=84; -- Lost One Fisherman
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=759 && `mingold`=59; -- Lost One Hunter
UPDATE `creature_template` SET `maxgold`=276 WHERE `entry`=759 && `maxgold`=83; -- Lost One Hunter
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=760 && `mingold`=59; -- Lost One Muckdweller (sample size 22)
UPDATE `creature_template` SET `maxgold`=275 WHERE `entry`=760 && `maxgold`=83; -- Lost One Muckdweller (sample size 22)
UPDATE `creature_template` SET `maxgold`=252 WHERE `entry`=761 && `maxgold`=78; -- Lost One Seer
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=762 && `mingold`=52; -- Lost One Riftseeker
UPDATE `creature_template` SET `maxgold`=298 WHERE `entry`=762 && `maxgold`=73; -- Lost One Riftseeker
UPDATE `creature_template` SET `maxgold`=243 WHERE `entry`=763 && `maxgold`=89; -- Lost One Chieftain
UPDATE `creature_template` SET `maxgold`=294 WHERE `entry`=764 && `maxgold`=82; -- Swampwalker
UPDATE `creature_template` SET `maxgold`=332 WHERE `entry`=765 && `maxgold`=83; -- Swampwalker Elder
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=766 && `mingold`=63; -- Tangled Horror
UPDATE `creature_template` SET `maxgold`=241 WHERE `entry`=766 && `maxgold`=87; -- Tangled Horror
UPDATE `creature_template` SET `maxgold`=155 WHERE `entry`=771 && `maxgold`=70; -- Commander Felstrom
UPDATE `creature_template` SET `maxgold`=176 WHERE `entry`=775 && `maxgold`=145; -- Kurzen's Agent
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=780 && `mingold`=60; -- Skullsplitter Mystic (sample size 32)
UPDATE `creature_template` SET `maxgold`=337 WHERE `entry`=780 && `maxgold`=83; -- Skullsplitter Mystic (sample size 32)
UPDATE `creature_template` SET `maxgold`=388 WHERE `entry`=781 && `maxgold`=107; -- Skullsplitter Headhunter
UPDATE `creature_template` SET `mingold`=61 WHERE `entry`=782 && `mingold`=76; -- Skullsplitter Scout (sample size 21)
UPDATE `creature_template` SET `maxgold`=375 WHERE `entry`=782 && `maxgold`=105; -- Skullsplitter Scout (sample size 21)
UPDATE `creature_template` SET `mingold`=75 WHERE `entry`=783 && `mingold`=78; -- Skullsplitter Berserker
UPDATE `creature_template` SET `maxgold`=393 WHERE `entry`=783 && `maxgold`=107; -- Skullsplitter Berserker
UPDATE `creature_template` SET `maxgold`=324 WHERE `entry`=784 && `maxgold`=105; -- Skullsplitter Beastmaster
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=785 && `mingold`=39; -- Skeletal Warder
UPDATE `creature_template` SET `maxgold`=100 WHERE `entry`=785 && `maxgold`=55; -- Skeletal Warder
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=787 && `maxgold`=50; -- Skeletal Healer
UPDATE `creature_template` SET `maxgold`=1025 WHERE `entry`=813 && `maxgold`=345; -- Colonel Kurzen
UPDATE `creature_template` SET `mingold`=46 WHERE `entry`=814 && `mingold`=57; -- Sergeant Malthus
UPDATE `creature_template` SET `maxgold`=21 WHERE `entry`=846 && `maxgold`=19; -- Ghoul
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=861 && `maxgold`=96; -- Stonard Scout
UPDATE `creature_template` SET `maxgold`=215 WHERE `entry`=862 && `maxgold`=86; -- Stonard Explorer
UPDATE `creature_template` SET `maxgold`=399 WHERE `entry`=867 && `maxgold`=142; -- Stonard Cartographer
UPDATE `creature_template` SET `mingold`=213 WHERE `entry`=871 && `mingold`=218; -- Saltscale Warrior
UPDATE `creature_template` SET `maxgold`=741 WHERE `entry`=871 && `maxgold`=290; -- Saltscale Warrior
UPDATE `creature_template` SET `maxgold`=586 WHERE `entry`=877 && `maxgold`=290; -- Saltscale Forager
UPDATE `creature_template` SET `mingold`=132 WHERE `entry`=879 && `mingold`=218; -- Saltscale Hunter
UPDATE `creature_template` SET `maxgold`=733 WHERE `entry`=879 && `maxgold`=290; -- Saltscale Hunter
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=880 && `mingold`=7; -- Erlan Drudgemoor
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=889 && `maxgold`=52; -- Splinter Fist Ogre
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=892 && `mingold`=39; -- Splinter Fist Taskmaster
UPDATE `creature_template` SET `mingold`=26 WHERE `entry`=909 && `mingold`=35; -- Defias Night Blade
UPDATE `creature_template` SET `maxgold`=79 WHERE `entry`=909 && `maxgold`=51; -- Defias Night Blade
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=910 && `mingold`=33; -- Defias Enchanter
UPDATE `creature_template` SET `maxgold`=126 WHERE `entry`=910 && `maxgold`=48; -- Defias Enchanter
UPDATE `creature_template` SET `mingold`=26 WHERE `entry`=920 && `mingold`=42; -- Nightbane Tainted One
UPDATE `creature_template` SET `maxgold`=180 WHERE `entry`=920 && `maxgold`=60; -- Nightbane Tainted One
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=921 && `mingold`=54; -- Venture Co. Lumberjack
UPDATE `creature_template` SET `maxgold`=219 WHERE `entry`=921 && `maxgold`=75; -- Venture Co. Lumberjack
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=937 && `mingold`=50; -- Kurzen Jungle Fighter (sample size 35)
UPDATE `creature_template` SET `maxgold`=189 WHERE `entry`=937 && `maxgold`=70; -- Kurzen Jungle Fighter (sample size 35)
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=938 && `mingold`=54; -- Kurzen Commando (sample size 54)
UPDATE `creature_template` SET `maxgold`=242 WHERE `entry`=938 && `maxgold`=75; -- Kurzen Commando (sample size 54)
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=939 && `mingold`=59; -- Kurzen Elite (sample size 25)
UPDATE `creature_template` SET `maxgold`=281 WHERE `entry`=939 && `maxgold`=83; -- Kurzen Elite (sample size 25)
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=940 && `mingold`=46; -- Kurzen Medicine Man (sample size 25)
UPDATE `creature_template` SET `maxgold`=195 WHERE `entry`=940 && `maxgold`=65; -- Kurzen Medicine Man (sample size 25)
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=941 && `mingold`=49; -- Kurzen Headshrinker (sample size 37)
UPDATE `creature_template` SET `maxgold`=246 WHERE `entry`=941 && `maxgold`=69; -- Kurzen Headshrinker (sample size 37)
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=942 && `mingold`=53; -- Kurzen Witch Doctor
UPDATE `creature_template` SET `maxgold`=268 WHERE `entry`=942 && `maxgold`=74; -- Kurzen Witch Doctor
UPDATE `creature_template` SET `maxgold`=130 WHERE `entry`=947 && `maxgold`=52; -- Rohh the Silent
UPDATE `creature_template` SET `maxgold`=51 WHERE `entry`=948 && `maxgold`=50; -- Rotted One
UPDATE `creature_template` SET `maxgold`=640 WHERE `entry`=950 && `maxgold`=140; -- Swamp Talker
UPDATE `creature_template` SET `mingold`=52 WHERE `entry`=978 && `mingold`=57; -- Kurzen Subchief (sample size 36)
UPDATE `creature_template` SET `maxgold`=318 WHERE `entry`=978 && `maxgold`=79; -- Kurzen Subchief (sample size 36)
UPDATE `creature_template` SET `maxgold`=249 WHERE `entry`=979 && `maxgold`=90; -- Kurzen Shadow Hunter
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1007 && `mingold`=25; -- Mosshide Gnoll (sample size 25)
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=1007 && `maxgold`=38; -- Mosshide Gnoll (sample size 25)
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=1008 && `mingold`=27; -- Mosshide Mongrel (sample size 25)
UPDATE `creature_template` SET `maxgold`=75 WHERE `entry`=1008 && `maxgold`=40; -- Mosshide Mongrel (sample size 25)
UPDATE `creature_template` SET `maxgold`=67 WHERE `entry`=1009 && `maxgold`=40; -- Mosshide Mistweaver
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=1010 && `mingold`=29; -- Mosshide Fenrunner
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=1010 && `maxgold`=42; -- Mosshide Fenrunner
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=1011 && `mingold`=31; -- Mosshide Trapper
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=1011 && `maxgold`=45; -- Mosshide Trapper
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=1012 && `mingold`=33; -- Mosshide Brute
UPDATE `creature_template` SET `maxgold`=163 WHERE `entry`=1012 && `maxgold`=48; -- Mosshide Brute
UPDATE `creature_template` SET `maxgold`=110 WHERE `entry`=1013 && `maxgold`=49; -- Mosshide Mystic
UPDATE `creature_template` SET `maxgold`=125 WHERE `entry`=1014 && `maxgold`=56; -- Mosshide Alpha
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1024 && `mingold`=25; -- Bluegill Murloc (sample size 35)
UPDATE `creature_template` SET `maxgold`=71 WHERE `entry`=1024 && `maxgold`=38; -- Bluegill Murloc (sample size 35)
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=1025 && `mingold`=27; -- Bluegill Puddlejumper
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=1025 && `maxgold`=40; -- Bluegill Puddlejumper
UPDATE `creature_template` SET `maxgold`=76 WHERE `entry`=1026 && `maxgold`=43; -- Bluegill Forager
UPDATE `creature_template` SET `maxgold`=133 WHERE `entry`=1027 && `maxgold`=48; -- Bluegill Warrior
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=1028 && `mingold`=28; -- Bluegill Muckdweller
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=1030 && `mingold`=26; -- Black Slime
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1031 && `mingold`=33; -- Crimson Ooze
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=1032 && `mingold`=31; -- Black Ooze (sample size 31)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=1032 && `maxgold`=45; -- Black Ooze (sample size 31)
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=1034 && `mingold`=37; -- Dragonmaw Raider (sample size 42)
UPDATE `creature_template` SET `maxgold`=133 WHERE `entry`=1034 && `maxgold`=53; -- Dragonmaw Raider (sample size 42)
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=1035 && `maxgold`=57; -- Dragonmaw Swamprunner
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=1036 && `mingold`=42; -- Dragonmaw Centurion
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=1036 && `maxgold`=59; -- Dragonmaw Centurion
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=1038 && `mingold`=37; -- Dragonmaw Shadowwarder
UPDATE `creature_template` SET `maxgold`=148 WHERE `entry`=1038 && `maxgold`=53; -- Dragonmaw Shadowwarder
UPDATE `creature_template` SET `maxgold`=43 WHERE `entry`=1039 && `maxgold`=38; -- Fen Dweller
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=1040 && `mingold`=33; -- Fen Creeper
UPDATE `creature_template` SET `maxgold`=164 WHERE `entry`=1040 && `maxgold`=48; -- Fen Creeper
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=1042 && `mingold`=31; -- Red Whelp
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=1051 && `mingold`=153; -- Dark Iron Dwarf
UPDATE `creature_template` SET `maxgold`=423 WHERE `entry`=1051 && `maxgold`=205; -- Dark Iron Dwarf
UPDATE `creature_template` SET `mingold`=147 WHERE `entry`=1052 && `mingold`=159; -- Dark Iron Saboteur
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=1052 && `maxgold`=213; -- Dark Iron Saboteur
UPDATE `creature_template` SET `mingold`=119 WHERE `entry`=1053 && `mingold`=170; -- Dark Iron Tunneler
UPDATE `creature_template` SET `maxgold`=496 WHERE `entry`=1053 && `maxgold`=226; -- Dark Iron Tunneler
UPDATE `creature_template` SET `maxgold`=308 WHERE `entry`=1054 && `maxgold`=234; -- Dark Iron Demolitionist
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=1057 && `mingold`=35; -- Dragonmaw Bonewarder
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=1057 && `maxgold`=50; -- Dragonmaw Bonewarder
UPDATE `creature_template` SET `maxgold`=438 WHERE `entry`=1059 && `maxgold`=115; -- Ana'thek the Cruel
UPDATE `creature_template` SET `mingold`=236 WHERE `entry`=1060 && `mingold`=259; -- Mogh the Undying
UPDATE `creature_template` SET `mingold`=62 WHERE `entry`=1061 && `mingold`=74; -- Gan'zulah
UPDATE `creature_template` SET `maxgold`=189 WHERE `entry`=1061 && `maxgold`=102; -- Gan'zulah
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=1062 && `mingold`=61; -- Nezzliok the Dire
UPDATE `creature_template` SET `maxgold`=337 WHERE `entry`=1062 && `maxgold`=84; -- Nezzliok the Dire
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=1065 && `mingold`=13; -- Riverpaw Shaman
UPDATE `creature_template` SET `maxgold`=171 WHERE `entry`=1081 && `maxgold`=117; -- Mire Lord
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1083 && `mingold`=19; -- Murloc Shorestriker
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=1083 && `maxgold`=30; -- Murloc Shorestriker
UPDATE `creature_template` SET `maxgold`=208 WHERE `entry`=1094 && `maxgold`=75; -- Venture Co. Miner
UPDATE `creature_template` SET `maxgold`=175 WHERE `entry`=1095 && `maxgold`=83; -- Venture Co. Workboss
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=1096 && `mingold`=52; -- Venture Co. Geologist (sample size 39)
UPDATE `creature_template` SET `maxgold`=263 WHERE `entry`=1096 && `maxgold`=73; -- Venture Co. Geologist (sample size 39)
UPDATE `creature_template` SET `mingold`=44 WHERE `entry`=1097 && `mingold`=56; -- Venture Co. Mechanic
UPDATE `creature_template` SET `maxgold`=229 WHERE `entry`=1097 && `maxgold`=78; -- Venture Co. Mechanic
UPDATE `creature_template` SET `maxgold`=152 WHERE `entry`=1106 && `maxgold`=81; -- Lost One Cook
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1115 && `mingold`=8; -- Rockjaw Skullthumper (sample size 29)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=1115 && `maxgold`=15; -- Rockjaw Skullthumper (sample size 29)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1116 && `mingold`=9; -- Rockjaw Ambusher
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1117 && `mingold`=10; -- Rockjaw Bonesnapper (sample size 22)
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1118 && `mingold`=13; -- Rockjaw Backbreaker
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1120 && `mingold`=7; -- Frostmane Troll
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1121 && `mingold`=12; -- Frostmane Snowstrider
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1122 && `mingold`=9; -- Frostmane Hideskinner
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1123 && `mingold`=8; -- Frostmane Headhunter
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1134 && `mingold`=4; -- Young Wendigo
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1135 && `mingold`=6; -- Wendigo (sample size 24)
UPDATE `creature_template` SET `maxgold`=12 WHERE `entry`=1135 && `maxgold`=13; -- Wendigo (sample size 24)
UPDATE `creature_template` SET `mingold`=44 WHERE `entry`=1142 && `mingold`=62; -- Mosh'Ogg Brute (sample size 21)
UPDATE `creature_template` SET `maxgold`=275 WHERE `entry`=1142 && `maxgold`=85; -- Mosh'Ogg Brute (sample size 21)
UPDATE `creature_template` SET `maxgold`=272 WHERE `entry`=1144 && `maxgold`=74; -- Mosh'Ogg Witch Doctor
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=1157 && `mingold`=37; -- Cursed Sailor (sample size 35)
UPDATE `creature_template` SET `maxgold`=132 WHERE `entry`=1157 && `maxgold`=53; -- Cursed Sailor (sample size 35)
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=1158 && `mingold`=39; -- Cursed Marine (sample size 21)
UPDATE `creature_template` SET `maxgold`=130 WHERE `entry`=1158 && `maxgold`=56; -- Cursed Marine (sample size 21)
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=1159 && `maxgold`=60; -- First Mate Snellig
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=1160 && `mingold`=44; -- Captain Halyndor
UPDATE `creature_template` SET `maxgold`=165 WHERE `entry`=1160 && `maxgold`=62; -- Captain Halyndor
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1161 && `mingold`=12; -- Stonesplinter Trogg (sample size 117)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=1161 && `maxgold`=20; -- Stonesplinter Trogg (sample size 117)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1162 && `mingold`=12; -- Stonesplinter Scout (sample size 142)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=1162 && `maxgold`=20; -- Stonesplinter Scout (sample size 142)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1163 && `mingold`=15; -- Stonesplinter Skullthumper (sample size 92)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=1163 && `maxgold`=24; -- Stonesplinter Skullthumper (sample size 92)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1164 && `mingold`=17; -- Stonesplinter Bonesnapper (sample size 61)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=1164 && `maxgold`=27; -- Stonesplinter Bonesnapper (sample size 61)
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1165 && `mingold`=20; -- Stonesplinter Geomancer (sample size 23)
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=1165 && `maxgold`=30; -- Stonesplinter Geomancer (sample size 23)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1166 && `mingold`=14; -- Stonesplinter Seer (sample size 68)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=1166 && `maxgold`=23; -- Stonesplinter Seer (sample size 68)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1167 && `mingold`=22; -- Stonesplinter Digger (sample size 21)
UPDATE `creature_template` SET `maxgold`=60 WHERE `entry`=1167 && `maxgold`=33; -- Stonesplinter Digger (sample size 21)
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=1169 && `mingold`=22; -- Dark Iron Insurgent
UPDATE `creature_template` SET `maxgold`=60 WHERE `entry`=1169 && `maxgold`=34; -- Dark Iron Insurgent
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1172 && `mingold`=10; -- Tunnel Rat Vermin (sample size 28)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=1172 && `maxgold`=18; -- Tunnel Rat Vermin (sample size 28)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1173 && `mingold`=10; -- Tunnel Rat Scout
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1174 && `mingold`=12; -- Tunnel Rat Geomancer
UPDATE `creature_template` SET `maxgold`=25 WHERE `entry`=1174 && `maxgold`=21; -- Tunnel Rat Geomancer
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1175 && `mingold`=13; -- Tunnel Rat Digger
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=1175 && `maxgold`=22; -- Tunnel Rat Digger
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1176 && `mingold`=12; -- Tunnel Rat Forager
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=1178 && `mingold`=83; -- Mo'grosh Ogre
UPDATE `creature_template` SET `maxgold`=169 WHERE `entry`=1179 && `maxgold`=108; -- Mo'grosh Enforcer
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=1180 && `mingold`=89; -- Mo'grosh Brute
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=1181 && `mingold`=79; -- Mo'grosh Shaman
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1197 && `mingold`=17; -- Stonesplinter Shaman (sample size 39)
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=1197 && `maxgold`=27; -- Stonesplinter Shaman (sample size 39)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1202 && `mingold`=12; -- Tunnel Rat Kobold
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=1205 && `mingold`=20; -- Grawmug
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=1206 && `maxgold`=29; -- Gnasher
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=1207 && `mingold`=18; -- Brawler
UPDATE `creature_template` SET `maxgold`=46 WHERE `entry`=1207 && `maxgold`=29; -- Brawler
UPDATE `creature_template` SET `mingold`=57 WHERE `entry`=1210 && `mingold`=111; -- Chok'sul
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1211 && `mingold`=9; -- Leper Gnome (sample size 54)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=1211 && `maxgold`=17; -- Leper Gnome (sample size 54)
UPDATE `creature_template` SET `maxgold`=50 WHERE `entry`=1222 && `maxgold`=31; -- Dark Iron Sapper
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1236 && `mingold`=13; -- Kobold Digger
UPDATE `creature_template` SET `maxgold`=56 WHERE `entry`=1251 && `maxgold`=54; -- Splinter Fist Firemonger
UPDATE `creature_template` SET `maxgold`=91 WHERE `entry`=1259 && `maxgold`=42; -- Gobbler
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=1270 && `maxgold`=61; -- Fetid Corpse
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=1271 && `mingold`=44; -- Old Icebeard
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1380 && `mingold`=3; -- Saean
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=1388 && `mingold`=45; -- Vagash
UPDATE `creature_template` SET `maxgold`=63 WHERE `entry`=1393 && `maxgold`=36; -- Berserk Trogg
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1397 && `mingold`=8; -- Frostmane Seer (sample size 21)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=1397 && `maxgold`=15; -- Frostmane Seer (sample size 21)
UPDATE `creature_template` SET `maxgold`=107 WHERE `entry`=1421 && `maxgold`=69; -- Private Merle
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1426 && `mingold`=16; -- Riverpaw Miner
UPDATE `creature_template` SET `maxgold`=33 WHERE `entry`=1426 && `maxgold`=26; -- Riverpaw Miner
UPDATE `creature_template` SET `maxgold`=118 WHERE `entry`=1487 && `maxgold`=65; -- Splinter Fist Enslaver
UPDATE `creature_template` SET `mingold`=85 WHERE `entry`=1488 && `mingold`=80; -- Zanzil Zombie (sample size 27)
UPDATE `creature_template` SET `maxgold`=419 WHERE `entry`=1488 && `maxgold`=110; -- Zanzil Zombie (sample size 27)
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=1489 && `mingold`=78; -- Zanzil Hunter
UPDATE `creature_template` SET `maxgold`=413 WHERE `entry`=1489 && `maxgold`=107; -- Zanzil Hunter
UPDATE `creature_template` SET `maxgold`=428 WHERE `entry`=1490 && `maxgold`=97; -- Zanzil Witch Doctor
UPDATE `creature_template` SET `mingold`=77 WHERE `entry`=1491 && `mingold`=79; -- Zanzil Naga
UPDATE `creature_template` SET `maxgold`=376 WHERE `entry`=1491 && `maxgold`=108; -- Zanzil Naga
UPDATE `creature_template` SET `maxgold`=1181 WHERE `entry`=1492 && `maxgold`=549; -- Gorlash
UPDATE `creature_template` SET `maxgold`=4 WHERE `entry`=1501 && `maxgold`=3; -- Mindless Zombie (sample size 45)
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=1506 && `maxgold`=6; -- Scarlet Convert (sample size 52)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1520 && `mingold`=5; -- Rattlecage Soldier (sample size 22)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1522 && `mingold`=6; -- Darkeye Bonecaster (sample size 58)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1523 && `mingold`=7; -- Cracked Skull Soldier (sample size 26)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=1523 && `maxgold`=15; -- Cracked Skull Soldier (sample size 26)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1525 && `mingold`=4; -- Rotting Dead (sample size 21)
UPDATE `creature_template` SET `maxgold`=7 WHERE `entry`=1525 && `maxgold`=10; -- Rotting Dead (sample size 21)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1526 && `mingold`=5; -- Ravaged Corpse
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1527 && `mingold`=6; -- Hungering Dead
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1528 && `mingold`=8; -- Shambling Horror
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1529 && `mingold`=10; -- Bleeding Horror
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1530 && `mingold`=10; -- Rotting Ancestor (sample size 22)
UPDATE `creature_template` SET `maxgold`=16 WHERE `entry`=1530 && `maxgold`=18; -- Rotting Ancestor (sample size 22)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1531 && `mingold`=5; -- Lost Soul
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1532 && `mingold`=11; -- Wandering Spirit
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=1533 && `mingold`=8; -- Tormented Spirit
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1534 && `mingold`=9; -- Wailing Ancestor
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1535 && `mingold`=5; -- Scarlet Warrior (sample size 38)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1536 && `mingold`=7; -- Scarlet Missionary
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1537 && `mingold`=9; -- Scarlet Zealot
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1538 && `mingold`=9; -- Scarlet Friar
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1539 && `mingold`=10; -- Scarlet Neophyte
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=1540 && `mingold`=11; -- Scarlet Vanguard
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1543 && `mingold`=6; -- Vile Fin Puddlejumper
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1544 && `mingold`=7; -- Vile Fin Minor Oracle
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1545 && `mingold`=9; -- Vile Fin Muckdweller
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=1561 && `mingold`=74; -- Bloodsail Raider (sample size 30)
UPDATE `creature_template` SET `maxgold`=350 WHERE `entry`=1561 && `maxgold`=101; -- Bloodsail Raider (sample size 30)
UPDATE `creature_template` SET `mingold`=61 WHERE `entry`=1562 && `mingold`=59; -- Bloodsail Mage (sample size 31)
UPDATE `creature_template` SET `maxgold`=314 WHERE `entry`=1562 && `maxgold`=81; -- Bloodsail Mage (sample size 31)
UPDATE `creature_template` SET `mingold`=61 WHERE `entry`=1563 && `mingold`=75; -- Bloodsail Swashbuckler (sample size 57)
UPDATE `creature_template` SET `maxgold`=404 WHERE `entry`=1563 && `maxgold`=103; -- Bloodsail Swashbuckler (sample size 57)
UPDATE `creature_template` SET `maxgold`=401 WHERE `entry`=1564 && `maxgold`=86; -- Bloodsail Warlock (sample size 57)
UPDATE `creature_template` SET `mingold`=73 WHERE `entry`=1565 && `mingold`=83; -- Bloodsail Sea Dog (sample size 26)
UPDATE `creature_template` SET `maxgold`=452 WHERE `entry`=1565 && `maxgold`=114; -- Bloodsail Sea Dog (sample size 26)
UPDATE `creature_template` SET `mingold`=66 WHERE `entry`=1653 && `mingold`=68; -- Bloodsail Elder Magus (sample size 26)
UPDATE `creature_template` SET `maxgold`=444 WHERE `entry`=1653 && `maxgold`=94; -- Bloodsail Elder Magus (sample size 26)
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=1654 && `mingold`=10; -- Gregor Agamand
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1655 && `mingold`=10; -- Nissa Agamand
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=1656 && `mingold`=10; -- Thurman Agamand
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1657 && `mingold`=8; -- Devlin Agamand
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=1658 && `maxgold`=23; -- Captain Dargol
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1660 && `mingold`=7; -- Scarlet Bodyguard
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1662 && `mingold`=8; -- Captain Perrine
UPDATE `creature_template` SET `maxgold`=20 WHERE `entry`=1664 && `maxgold`=19; -- Captain Vachon
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1665 && `mingold`=13; -- Captain Melrache
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=1666 && `mingold`=153; -- Kam Deepfury
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1667 && `mingold`=3; -- Meven Korgal
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1674 && `mingold`=5; -- Rot Hide Gnoll
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1675 && `mingold`=7; -- Rot Hide Mongrel (sample size 35)
UPDATE `creature_template` SET `maxgold`=266 WHERE `entry`=1696 && `maxgold`=165; -- Targorr the Dread
UPDATE `creature_template` SET `mingold`=64 WHERE `entry`=1706 && `mingold`=121; -- Defias Prisoner (sample size 22)
UPDATE `creature_template` SET `maxgold`=323 WHERE `entry`=1706 && `maxgold`=163; -- Defias Prisoner (sample size 22)
UPDATE `creature_template` SET `mingold`=60 WHERE `entry`=1707 && `mingold`=121; -- Defias Captive
UPDATE `creature_template` SET `maxgold`=325 WHERE `entry`=1707 && `maxgold`=163; -- Defias Captive
UPDATE `creature_template` SET `mingold`=64 WHERE `entry`=1708 && `mingold`=131; -- Defias Inmate
UPDATE `creature_template` SET `maxgold`=369 WHERE `entry`=1708 && `maxgold`=176; -- Defias Inmate
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=1711 && `mingold`=127; -- Defias Convict
UPDATE `creature_template` SET `maxgold`=348 WHERE `entry`=1711 && `maxgold`=171; -- Defias Convict
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=1715 && `mingold`=133; -- Defias Insurgent
UPDATE `creature_template` SET `maxgold`=402 WHERE `entry`=1715 && `maxgold`=179; -- Defias Insurgent
UPDATE `creature_template` SET `maxgold`=368 WHERE `entry`=1716 && `maxgold`=226; -- Bazil Thredd
UPDATE `creature_template` SET `maxgold`=286 WHERE `entry`=1717 && `maxgold`=196; -- Hamhock
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=1725 && `mingold`=75; -- Defias Watchman
UPDATE `creature_template` SET `maxgold`=98 WHERE `entry`=1726 && `maxgold`=91; -- Defias Magician
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=1727 && `mingold`=20; -- Defias Worker
UPDATE `creature_template` SET `maxgold`=33 WHERE `entry`=1727 && `maxgold`=31; -- Defias Worker
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=1729 && `mingold`=77; -- Defias Evoker
UPDATE `creature_template` SET `maxgold`=156 WHERE `entry`=1729 && `maxgold`=105; -- Defias Evoker
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=1731 && `mingold`=87; -- Goblin Craftsman
UPDATE `creature_template` SET `maxgold`=174 WHERE `entry`=1731 && `maxgold`=119; -- Goblin Craftsman
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=1732 && `mingold`=80; -- Defias Squallshaper
UPDATE `creature_template` SET `maxgold`=156 WHERE `entry`=1732 && `maxgold`=110; -- Defias Squallshaper
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1753 && `mingold`=10; -- Maggot Eye
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=1763 && `mingold`=163; -- Gilnid
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1767 && `mingold`=14; -- Vile Fin Shredder (sample size 212)
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=1767 && `maxgold`=23; -- Vile Fin Shredder (sample size 212)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1768 && `mingold`=16; -- Vile Fin Tidehunter (sample size 99)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=1768 && `maxgold`=26; -- Vile Fin Tidehunter (sample size 99)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1769 && `mingold`=10; -- Moonrage Whitescalp (sample size 47)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=1769 && `maxgold`=18; -- Moonrage Whitescalp (sample size 47)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1770 && `mingold`=12; -- Moonrage Darkrunner (sample size 21)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=1770 && `maxgold`=20; -- Moonrage Darkrunner (sample size 21)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1772 && `mingold`=12; -- Rot Hide Gladerunner
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=1772 && `maxgold`=20; -- Rot Hide Gladerunner
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=1773 && `maxgold`=22; -- Rot Hide Mystic
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1779 && `mingold`=13; -- Moonrage Glutton (sample size 63)
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=1779 && `maxgold`=22; -- Moonrage Glutton (sample size 63)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1782 && `mingold`=15; -- Moonrage Darksoul (sample size 34)
UPDATE `creature_template` SET `maxgold`=28 WHERE `entry`=1782 && `maxgold`=24; -- Moonrage Darksoul (sample size 34)
UPDATE `creature_template` SET `mingold`=93 WHERE `entry`=1783 && `mingold`=101; -- Skeletal Flayer (sample size 203)
UPDATE `creature_template` SET `maxgold`=638 WHERE `entry`=1783 && `maxgold`=137; -- Skeletal Flayer (sample size 203)
UPDATE `creature_template` SET `mingold`=120 WHERE `entry`=1784 && `mingold`=93; -- Skeletal Sorcerer (sample size 28)
UPDATE `creature_template` SET `maxgold`=618 WHERE `entry`=1784 && `maxgold`=127; -- Skeletal Sorcerer (sample size 28)
UPDATE `creature_template` SET `maxgold`=716 WHERE `entry`=1785 && `maxgold`=181; -- Skeletal Terror
UPDATE `creature_template` SET `maxgold`=789 WHERE `entry`=1787 && `maxgold`=158; -- Skeletal Executioner (sample size 43)
UPDATE `creature_template` SET `maxgold`=1236 WHERE `entry`=1788 && `maxgold`=586; -- Skeletal Warlord
UPDATE `creature_template` SET `mingold`=139 WHERE `entry`=1789 && `mingold`=108; -- Skeletal Acolyte (sample size 51)
UPDATE `creature_template` SET `maxgold`=813 WHERE `entry`=1789 && `maxgold`=145; -- Skeletal Acolyte (sample size 51)
UPDATE `creature_template` SET `maxgold`=643 WHERE `entry`=1791 && `maxgold`=140; -- Slavering Ghoul (sample size 122)
UPDATE `creature_template` SET `maxgold`=722 WHERE `entry`=1793 && `maxgold`=158; -- Rotting Ghoul
UPDATE `creature_template` SET `mingold`=127 WHERE `entry`=1794 && `mingold`=102; -- Soulless Ghoul (sample size 45)
UPDATE `creature_template` SET `maxgold`=791 WHERE `entry`=1794 && `maxgold`=139; -- Soulless Ghoul (sample size 45)
UPDATE `creature_template` SET `mingold`=121 WHERE `entry`=1795 && `mingold`=108; -- Searing Ghoul (sample size 33)
UPDATE `creature_template` SET `maxgold`=825 WHERE `entry`=1795 && `maxgold`=145; -- Searing Ghoul (sample size 33)
UPDATE `creature_template` SET `maxgold`=807 WHERE `entry`=1796 && `maxgold`=165; -- Freezing Ghoul
UPDATE `creature_template` SET `maxgold`=632 WHERE `entry`=1802 && `maxgold`=171; -- Hungering Wraith
UPDATE `creature_template` SET `maxgold`=492 WHERE `entry`=1804 && `maxgold`=169; -- Wailing Death
UPDATE `creature_template` SET `mingold`=102 WHERE `entry`=1806 && `mingold`=117; -- Vile Slime
UPDATE `creature_template` SET `maxgold`=395 WHERE `entry`=1806 && `maxgold`=158; -- Vile Slime
UPDATE `creature_template` SET `maxgold`=470 WHERE `entry`=1808 && `maxgold`=165; -- Devouring Ooze
UPDATE `creature_template` SET `maxgold`=807 WHERE `entry`=1812 && `maxgold`=168; -- Rotting Behemoth
UPDATE `creature_template` SET `maxgold`=866 WHERE `entry`=1813 && `maxgold`=169; -- Decaying Horror
UPDATE `creature_template` SET `maxgold`=426 WHERE `entry`=1826 && `maxgold`=134; -- Scarlet Mage
UPDATE `creature_template` SET `mingold`=400 WHERE `entry`=1827 && `mingold`=435; -- Scarlet Sentinel
UPDATE `creature_template` SET `maxgold`=2407 WHERE `entry`=1827 && `maxgold`=573; -- Scarlet Sentinel
UPDATE `creature_template` SET `maxgold`=700 WHERE `entry`=1831 && `maxgold`=148; -- Scarlet Hunter
UPDATE `creature_template` SET `maxgold`=685 WHERE `entry`=1833 && `maxgold`=158; -- Scarlet Knight
UPDATE `creature_template` SET `maxgold`=2067 WHERE `entry`=1834 && `maxgold`=484; -- Scarlet Paladin
UPDATE `creature_template` SET `maxgold`=745 WHERE `entry`=1835 && `maxgold`=135; -- Scarlet Invoker
UPDATE `creature_template` SET `maxgold`=1198 WHERE `entry`=1836 && `maxgold`=621; -- Scarlet Cavalier
UPDATE `creature_template` SET `maxgold`=558 WHERE `entry`=1845 && `maxgold`=155; -- High Protector Tarsen
UPDATE `creature_template` SET `maxgold`=2874 WHERE `entry`=1846 && `maxgold`=558; -- High Protector Lorik
UPDATE `creature_template` SET `maxgold`=302 WHERE `entry`=1848 && `maxgold`=146; -- Lord Maldazzar
UPDATE `creature_template` SET `maxgold`=1364 WHERE `entry`=1852 && `maxgold`=603; -- Araj the Summoner
UPDATE `creature_template` SET `maxgold`=2625 WHERE `entry`=1853 && `maxgold`=2517; -- Darkmaster Gandling
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1865 && `mingold`=14; -- Ravenclaw Raider
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=1866 && `mingold`=12; -- Ravenclaw Slave
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=1866 && `maxgold`=20; -- Ravenclaw Slave
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=1867 && `mingold`=14; -- Dalaran Apprentice (sample size 26)
UPDATE `creature_template` SET `maxgold`=28 WHERE `entry`=1867 && `maxgold`=24; -- Dalaran Apprentice (sample size 26)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1868 && `mingold`=14; -- Ravenclaw Servant
UPDATE `creature_template` SET `maxgold`=25 WHERE `entry`=1868 && `maxgold`=23; -- Ravenclaw Servant
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1869 && `mingold`=16; -- Ravenclaw Champion
UPDATE `creature_template` SET `maxgold`=28 WHERE `entry`=1869 && `maxgold`=26; -- Ravenclaw Champion
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=1870 && `maxgold`=28; -- Hand of Ravenclaw
UPDATE `creature_template` SET `maxgold`=664 WHERE `entry`=1883 && `maxgold`=168; -- Scarlet Worker
UPDATE `creature_template` SET `maxgold`=769 WHERE `entry`=1884 && `maxgold`=164; -- Scarlet Lumberjack
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1888 && `mingold`=21; -- Dalaran Watcher
UPDATE `creature_template` SET `maxgold`=55 WHERE `entry`=1888 && `maxgold`=32; -- Dalaran Watcher
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=1889 && `maxgold`=33; -- Dalaran Wizard
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=1891 && `mingold`=59; -- Pyrewood Watcher
UPDATE `creature_template` SET `maxgold`=87 WHERE `entry`=1891 && `maxgold`=81; -- Pyrewood Watcher
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=1892 && `maxgold`=50; -- Moonrage Watcher
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=1893 && `maxgold`=47; -- Moonrage Sentry
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=1894 && `mingold`=63; -- Pyrewood Sentry
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=1894 && `maxgold`=88; -- Pyrewood Sentry
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=1895 && `mingold`=59; -- Pyrewood Elder
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=1895 && `maxgold`=81; -- Pyrewood Elder
UPDATE `creature_template` SET `maxgold`=101 WHERE `entry`=1896 && `maxgold`=47; -- Moonrage Elder
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=1907 && `mingold`=78; -- Naga Explorer (sample size 86)
UPDATE `creature_template` SET `maxgold`=425 WHERE `entry`=1907 && `maxgold`=107; -- Naga Explorer (sample size 86)
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=1908 && `maxgold`=43; -- Vile Fin Oracle
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=1909 && `mingold`=23; -- Vile Fin Lakestalker
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1912 && `mingold`=16; -- Dalaran Protector (sample size 41)
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=1912 && `maxgold`=26; -- Dalaran Protector (sample size 41)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1913 && `mingold`=19; -- Dalaran Warder
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=1913 && `maxgold`=30; -- Dalaran Warder
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=1914 && `mingold`=16; -- Dalaran Mage
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=1914 && `maxgold`=26; -- Dalaran Mage
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=1915 && `mingold`=19; -- Dalaran Conjuror
UPDATE `creature_template` SET `maxgold`=50 WHERE `entry`=1915 && `maxgold`=30; -- Dalaran Conjuror
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=1919 && `mingold`=3; -- Samuel Fipps
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=1924 && `mingold`=18; -- Moonrage Bloodhowler
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=1924 && `maxgold`=29; -- Moonrage Bloodhowler
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1934 && `mingold`=5; -- Tirisfal Farmer
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1935 && `mingold`=4; -- Tirisfal Farmhand
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1939 && `mingold`=20; -- Rot Hide Brute (sample size 127)
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=1939 && `maxgold`=31; -- Rot Hide Brute (sample size 127)
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=1940 && `mingold`=20; -- Rot Hide Plague Weaver (sample size 72)
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=1940 && `maxgold`=30; -- Rot Hide Plague Weaver (sample size 72)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=1941 && `mingold`=5; -- Rot Hide Graverobber (sample size 31)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1942 && `mingold`=22; -- Rot Hide Savage (sample size 40)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=1942 && `maxgold`=33; -- Rot Hide Savage (sample size 40)
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1943 && `mingold`=22; -- Raging Rot Hide (sample size 29)
UPDATE `creature_template` SET `maxgold`=58 WHERE `entry`=1943 && `maxgold`=34; -- Raging Rot Hide (sample size 29)
UPDATE `creature_template` SET `maxgold`=79 WHERE `entry`=1944 && `maxgold`=42; -- Rot Hide Bruiser
UPDATE `creature_template` SET `maxgold`=175 WHERE `entry`=1947 && `maxgold`=143; -- Thule Ravenclaw
UPDATE `creature_template` SET `maxgold`=83 WHERE `entry`=1948 && `maxgold`=47; -- Snarlmane
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=1949 && `mingold`=12; -- Servant of Azora
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1953 && `mingold`=18; -- Lake Skulker (sample size 25)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=1953 && `maxgold`=28; -- Lake Skulker (sample size 25)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=1954 && `mingold`=18; -- Elder Lake Skulker
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=1954 && `maxgold`=28; -- Elder Lake Skulker
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1955 && `mingold`=20; -- Lake Creeper
UPDATE `creature_template` SET `maxgold`=53 WHERE `entry`=1955 && `maxgold`=32; -- Lake Creeper
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=1956 && `mingold`=22; -- Elder Lake Creeper
UPDATE `creature_template` SET `maxgold`=58 WHERE `entry`=1956 && `maxgold`=34; -- Elder Lake Creeper
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=1958 && `maxgold`=33; -- Vile Fin Tidecaller
UPDATE `creature_template` SET `mingold`=11 WHERE `entry`=1971 && `mingold`=14; -- Ivar the Foul
UPDATE `creature_template` SET `maxgold`=26 WHERE `entry`=1971 && `maxgold`=23; -- Ivar the Foul
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=1972 && `mingold`=17; -- Grimson the Pale
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1973 && `mingold`=26; -- Ravenclaw Guardian (sample size 22)
UPDATE `creature_template` SET `maxgold`=70 WHERE `entry`=1973 && `maxgold`=38; -- Ravenclaw Guardian (sample size 22)
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=1974 && `mingold`=24; -- Ravenclaw Drudger
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=1974 && `maxgold`=36; -- Ravenclaw Drudger
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=1983 && `mingold`=23; -- Nightlash
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2002 && `mingold`=4; -- Rascal Sprite
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2003 && `mingold`=4; -- Shadow Sprite (sample size 21)
UPDATE `creature_template` SET `maxgold`=7 WHERE `entry`=2003 && `maxgold`=10; -- Shadow Sprite (sample size 21)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2004 && `mingold`=5; -- Dark Sprite
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2005 && `mingold`=6; -- Vicious Grell
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2006 && `mingold`=4; -- Gnarlpine Ursa
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2007 && `mingold`=4; -- Gnarlpine Gardener
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2008 && `mingold`=5; -- Gnarlpine Warrior (sample size 30)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2009 && `mingold`=6; -- Gnarlpine Shaman (sample size 105)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2010 && `mingold`=7; -- Gnarlpine Defender (sample size 66)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2011 && `mingold`=8; -- Gnarlpine Augur
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2012 && `mingold`=9; -- Gnarlpine Pathfinder
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=2013 && `mingold`=9; -- Gnarlpine Avenger
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2014 && `mingold`=10; -- Gnarlpine Totemic
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2015 && `mingold`=8; -- Bloodfeather Harpy
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2017 && `mingold`=8; -- Bloodfeather Rogue
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2018 && `mingold`=9; -- Bloodfeather Sorceress
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2019 && `mingold`=9; -- Bloodfeather Fury
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=2020 && `mingold`=9; -- Bloodfeather Wind Witch
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2021 && `mingold`=12; -- Bloodfeather Matriarch
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=2021 && `maxgold`=20; -- Bloodfeather Matriarch
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2022 && `mingold`=4; -- Timberling (sample size 68)
UPDATE `creature_template` SET `maxgold`=7 WHERE `entry`=2022 && `maxgold`=10; -- Timberling (sample size 68)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2025 && `mingold`=6; -- Timberling Bark Ripper
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2027 && `mingold`=8; -- Timberling Trampler
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2029 && `mingold`=9; -- Timberling Mire Beast
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2030 && `mingold`=10; -- Elder Timberling
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=2038 && `mingold`=7; -- Lord Melenas
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2039 && `mingold`=13; -- Ursal the Mauler
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=2044 && `mingold`=0; -- Forlorn Spirit (sample size 6)
UPDATE `creature_template` SET `maxgold`=64 WHERE `entry`=2044 && `maxgold`=0; -- Forlorn Spirit (sample size 6)
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=2053 && `maxgold`=34; -- Haggard Refugee
UPDATE `creature_template` SET `maxgold`=51 WHERE `entry`=2054 && `maxgold`=34; -- Sickly Refugee
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2066 && `mingold`=10; -- Councilman Higarth
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=2067 && `mingold`=10; -- Councilman Brunswick
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=2068 && `maxgold`=55; -- Lord Mayor Morrison
UPDATE `creature_template` SET `maxgold`=63 WHERE `entry`=2090 && `maxgold`=44; -- Ma'ruk Wyrmscale
UPDATE `creature_template` SET `mingold`=133 WHERE `entry`=2091 && `mingold`=187; -- Chieftain Nek'rosh
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=2102 && `mingold`=26; -- Dragonmaw Grunt
UPDATE `creature_template` SET `maxgold`=67 WHERE `entry`=2102 && `maxgold`=38; -- Dragonmaw Grunt
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2103 && `mingold`=23; -- Dragonmaw Scout (sample size 34)
UPDATE `creature_template` SET `maxgold`=65 WHERE `entry`=2103 && `maxgold`=35; -- Dragonmaw Scout (sample size 34)
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=2106 && `maxgold`=103; -- Apothecary Berard
UPDATE `creature_template` SET `maxgold`=87 WHERE `entry`=2120 && `maxgold`=39; -- Archmage Ataeric
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2152 && `mingold`=6; -- Gnarlpine Ambusher
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=2156 && `mingold`=21; -- Cracked Golem
UPDATE `creature_template` SET `maxgold`=58 WHERE `entry`=2156 && `maxgold`=32; -- Cracked Golem
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2157 && `mingold`=22; -- Stone Behemoth
UPDATE `creature_template` SET `maxgold`=57 WHERE `entry`=2157 && `maxgold`=33; -- Stone Behemoth
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=2158 && `maxgold`=27; -- Gravelflint Scout
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=2160 && `maxgold`=34; -- Gravelflint Geomancer
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=2166 && `mingold`=35; -- Oakenscowl
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2167 && `mingold`=13; -- Blackwood Pathfinder (sample size 23)
UPDATE `creature_template` SET `maxgold`=26 WHERE `entry`=2167 && `maxgold`=21; -- Blackwood Pathfinder (sample size 23)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2168 && `mingold`=19; -- Blackwood Warrior (sample size 22)
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=2168 && `maxgold`=29; -- Blackwood Warrior (sample size 22)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2169 && `mingold`=20; -- Blackwood Totemic
UPDATE `creature_template` SET `maxgold`=51 WHERE `entry`=2169 && `maxgold`=31; -- Blackwood Totemic
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=2170 && `mingold`=21; -- Blackwood Ursa (sample size 28)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=2170 && `maxgold`=32; -- Blackwood Ursa (sample size 28)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2171 && `mingold`=23; -- Blackwood Shaman
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=2171 && `maxgold`=34; -- Blackwood Shaman
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2176 && `mingold`=10; -- Cursed Highborne
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2177 && `mingold`=12; -- Writhing Highborne (sample size 27)
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=2177 && `maxgold`=20; -- Writhing Highborne (sample size 27)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2178 && `mingold`=13; -- Wailing Highborne
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=2178 && `maxgold`=22; -- Wailing Highborne
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=2179 && `mingold`=17; -- Stormscale Wave Rider
UPDATE `creature_template` SET `maxgold`=35 WHERE `entry`=2179 && `maxgold`=27; -- Stormscale Wave Rider
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2180 && `mingold`=18; -- Stormscale Siren
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=2180 && `maxgold`=29; -- Stormscale Siren
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=2181 && `mingold`=22; -- Stormscale Myrmidon (sample size 23)
UPDATE `creature_template` SET `maxgold`=53 WHERE `entry`=2181 && `maxgold`=33; -- Stormscale Myrmidon (sample size 23)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=2182 && `mingold`=22; -- Stormscale Sorceress
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=2182 && `maxgold`=33; -- Stormscale Sorceress
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=2183 && `mingold`=25; -- Stormscale Warrior
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=2183 && `maxgold`=38; -- Stormscale Warrior
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2189 && `mingold`=10; -- Vile Sprite (sample size 31)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=2189 && `maxgold`=18; -- Vile Sprite (sample size 31)
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=2190 && `mingold`=12; -- Wild Grell
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=2190 && `maxgold`=20; -- Wild Grell
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=2201 && `mingold`=12; -- Greymist Raider
UPDATE `creature_template` SET `maxgold`=22 WHERE `entry`=2201 && `maxgold`=20; -- Greymist Raider
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=2202 && `mingold`=13; -- Greymist Coastrunner
UPDATE `creature_template` SET `maxgold`=25 WHERE `entry`=2202 && `maxgold`=22; -- Greymist Coastrunner
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=2203 && `mingold`=14; -- Greymist Seer
UPDATE `creature_template` SET `maxgold`=28 WHERE `entry`=2203 && `maxgold`=24; -- Greymist Seer
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=2204 && `mingold`=16; -- Greymist Netter
UPDATE `creature_template` SET `maxgold`=31 WHERE `entry`=2204 && `maxgold`=26; -- Greymist Netter
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=2205 && `mingold`=17; -- Greymist Warrior (sample size 24)
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=2205 && `maxgold`=28; -- Greymist Warrior (sample size 24)
UPDATE `creature_template` SET `mingold`=11 WHERE `entry`=2206 && `mingold`=19; -- Greymist Hunter
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=2206 && `maxgold`=30; -- Greymist Hunter
UPDATE `creature_template` SET `maxgold`=45 WHERE `entry`=2207 && `maxgold`=32; -- Greymist Oracle
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=2208 && `mingold`=23; -- Greymist Tidehunter
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=2208 && `maxgold`=34; -- Greymist Tidehunter
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=2212 && `mingold`=13; -- Deth'ryll Satyr
UPDATE `creature_template` SET `maxgold`=26 WHERE `entry`=2212 && `maxgold`=22; -- Deth'ryll Satyr
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2240 && `mingold`=50; -- Syndicate Footpad (sample size 34)
UPDATE `creature_template` SET `maxgold`=190 WHERE `entry`=2240 && `maxgold`=70; -- Syndicate Footpad (sample size 34)
UPDATE `creature_template` SET `mingold`=47 WHERE `entry`=2241 && `mingold`=53; -- Syndicate Thief (sample size 30)
UPDATE `creature_template` SET `maxgold`=222 WHERE `entry`=2241 && `maxgold`=74; -- Syndicate Thief (sample size 30)
UPDATE `creature_template` SET `mingold`=39 WHERE `entry`=2242 && `mingold`=61; -- Syndicate Spy (sample size 26)
UPDATE `creature_template` SET `maxgold`=263 WHERE `entry`=2242 && `maxgold`=84; -- Syndicate Spy (sample size 26)
UPDATE `creature_template` SET `maxgold`=225 WHERE `entry`=2243 && `maxgold`=83; -- Syndicate Sentry
UPDATE `creature_template` SET `maxgold`=84 WHERE `entry`=2244 && `maxgold`=37; -- Syndicate Shadow Mage
UPDATE `creature_template` SET `maxgold`=289 WHERE `entry`=2245 && `maxgold`=86; -- Syndicate Saboteur
UPDATE `creature_template` SET `maxgold`=317 WHERE `entry`=2246 && `maxgold`=93; -- Syndicate Assassin
UPDATE `creature_template` SET `maxgold`=308 WHERE `entry`=2247 && `maxgold`=94; -- Syndicate Enforcer
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=2248 && `mingold`=46; -- Cave Yeti (sample size 64)
UPDATE `creature_template` SET `maxgold`=182 WHERE `entry`=2248 && `maxgold`=65; -- Cave Yeti (sample size 64)
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=2249 && `mingold`=49; -- Ferocious Yeti (sample size 33)
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=2249 && `maxgold`=69; -- Ferocious Yeti (sample size 33)
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2250 && `mingold`=50; -- Mountain Yeti (sample size 29)
UPDATE `creature_template` SET `maxgold`=196 WHERE `entry`=2250 && `maxgold`=70; -- Mountain Yeti (sample size 29)
UPDATE `creature_template` SET `mingold`=55 WHERE `entry`=2251 && `mingold`=53; -- Giant Yeti (sample size 56)
UPDATE `creature_template` SET `maxgold`=227 WHERE `entry`=2251 && `maxgold`=74; -- Giant Yeti (sample size 56)
UPDATE `creature_template` SET `mingold`=39 WHERE `entry`=2252 && `mingold`=54; -- Crushridge Ogre (sample size 27)
UPDATE `creature_template` SET `maxgold`=244 WHERE `entry`=2252 && `maxgold`=75; -- Crushridge Ogre (sample size 27)
UPDATE `creature_template` SET `mingold`=52 WHERE `entry`=2253 && `mingold`=59; -- Crushridge Brute
UPDATE `creature_template` SET `maxgold`=257 WHERE `entry`=2253 && `maxgold`=81; -- Crushridge Brute
UPDATE `creature_template` SET `mingold`=126 WHERE `entry`=2254 && `mingold`=228; -- Crushridge Mauler (sample size 30)
UPDATE `creature_template` SET `maxgold`=847 WHERE `entry`=2254 && `maxgold`=303; -- Crushridge Mauler (sample size 30)
UPDATE `creature_template` SET `maxgold`=894 WHERE `entry`=2255 && `maxgold`=255; -- Crushridge Mage
UPDATE `creature_template` SET `mingold`=159 WHERE `entry`=2256 && `mingold`=249; -- Crushridge Enforcer (sample size 29)
UPDATE `creature_template` SET `maxgold`=913 WHERE `entry`=2256 && `maxgold`=330; -- Crushridge Enforcer (sample size 29)
UPDATE `creature_template` SET `mingold`=281 WHERE `entry`=2257 && `mingold`=291; -- Mug'thol
UPDATE `creature_template` SET `maxgold`=487 WHERE `entry`=2257 && `maxgold`=385; -- Mug'thol
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=2260 && `mingold`=27; -- Syndicate Rogue
UPDATE `creature_template` SET `maxgold`=85 WHERE `entry`=2260 && `maxgold`=40; -- Syndicate Rogue
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=2261 && `mingold`=26; -- Syndicate Watchman (sample size 45)
UPDATE `creature_template` SET `maxgold`=71 WHERE `entry`=2261 && `maxgold`=38; -- Syndicate Watchman (sample size 45)
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=2265 && `maxgold`=48; -- Hillsbrad Apprentice Blacksmith
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=2266 && `mingold`=31; -- Hillsbrad Farmer
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=2266 && `maxgold`=45; -- Hillsbrad Farmer
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=2267 && `mingold`=32; -- Hillsbrad Peasant
UPDATE `creature_template` SET `maxgold`=106 WHERE `entry`=2267 && `maxgold`=47; -- Hillsbrad Peasant
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=2268 && `mingold`=35; -- Hillsbrad Footman (sample size 28)
UPDATE `creature_template` SET `maxgold`=120 WHERE `entry`=2268 && `maxgold`=51; -- Hillsbrad Footman (sample size 28)
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=2269 && `mingold`=37; -- Hillsbrad Miner (sample size 32)
UPDATE `creature_template` SET `maxgold`=131 WHERE `entry`=2269 && `maxgold`=53; -- Hillsbrad Miner (sample size 32)
UPDATE `creature_template` SET `mingold`=38 WHERE `entry`=2270 && `mingold`=39; -- Hillsbrad Sentry
UPDATE `creature_template` SET `maxgold`=136 WHERE `entry`=2270 && `maxgold`=56; -- Hillsbrad Sentry
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=2271 && `mingold`=49; -- Dalaran Shield Guard (sample size 46)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=2271 && `maxgold`=69; -- Dalaran Shield Guard (sample size 46)
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2272 && `mingold`=44; -- Dalaran Theurgist
UPDATE `creature_template` SET `maxgold`=194 WHERE `entry`=2272 && `maxgold`=62; -- Dalaran Theurgist
UPDATE `creature_template` SET `mingold`=158 WHERE `entry`=2287 && `mingold`=259; -- Crushridge Warmonger (sample size 32)
UPDATE `creature_template` SET `maxgold`=1007 WHERE `entry`=2287 && `maxgold`=343; -- Crushridge Warmonger (sample size 32)
UPDATE `creature_template` SET `maxgold`=96 WHERE `entry`=2305 && `maxgold`=58; -- Foreman Bonds
UPDATE `creature_template` SET `maxgold`=188 WHERE `entry`=2306 && `maxgold`=79; -- Baron Vardus
UPDATE `creature_template` SET `maxgold`=258 WHERE `entry`=2318 && `maxgold`=70; -- Argus Shadow Mage
UPDATE `creature_template` SET `maxgold`=232 WHERE `entry`=2319 && `maxgold`=66; -- Syndicate Wizard
UPDATE `creature_template` SET `mingold`=58 WHERE `entry`=2320 && `mingold`=67; -- Nagaz
UPDATE `creature_template` SET `maxgold`=309 WHERE `entry`=2320 && `maxgold`=93; -- Nagaz
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=2324 && `mingold`=15; -- Blackwood Windtalker (sample size 25)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=2324 && `maxgold`=24; -- Blackwood Windtalker (sample size 25)
UPDATE `creature_template` SET `maxgold`=40 WHERE `entry`=2332 && `maxgold`=39; -- Valdred Moray
UPDATE `creature_template` SET `maxgold`=174 WHERE `entry`=2335 && `maxgold`=57; -- Magistrate Burnside
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=2336 && `mingold`=19; -- Dark Strand Fanatic (sample size 31)
UPDATE `creature_template` SET `maxgold`=47 WHERE `entry`=2336 && `maxgold`=30; -- Dark Strand Fanatic (sample size 31)
UPDATE `creature_template` SET `maxgold`=153 WHERE `entry`=2337 && `maxgold`=53; -- Dark Strand Voidcaller
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=2338 && `mingold`=18; -- Twilight Disciple
UPDATE `creature_template` SET `maxgold`=40 WHERE `entry`=2338 && `maxgold`=29; -- Twilight Disciple
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=2339 && `mingold`=21; -- Twilight Thug
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=2339 && `maxgold`=32; -- Twilight Thug
UPDATE `creature_template` SET `mingold`=126 WHERE `entry`=2344 && `mingold`=142; -- Dun Garok Mountaineer
UPDATE `creature_template` SET `maxgold`=422 WHERE `entry`=2344 && `maxgold`=191; -- Dun Garok Mountaineer
UPDATE `creature_template` SET `mingold`=132 WHERE `entry`=2345 && `mingold`=170; -- Dun Garok Rifleman
UPDATE `creature_template` SET `maxgold`=470 WHERE `entry`=2345 && `maxgold`=226; -- Dun Garok Rifleman
UPDATE `creature_template` SET `mingold`=77 WHERE `entry`=2346 && `mingold`=153; -- Dun Garok Priest
UPDATE `creature_template` SET `maxgold`=318 WHERE `entry`=2346 && `maxgold`=204; -- Dun Garok Priest
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=2358 && `mingold`=47; -- Dalaran Summoner (sample size 42)
UPDATE `creature_template` SET `maxgold`=234 WHERE `entry`=2358 && `maxgold`=67; -- Dalaran Summoner (sample size 42)
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=2360 && `mingold`=29; -- Hillsbrad Farmhand
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=2360 && `maxgold`=43; -- Hillsbrad Farmhand
UPDATE `creature_template` SET `maxgold`=68 WHERE `entry`=2368 && `maxgold`=60; -- Daggerspine Shorestalker
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=2369 && `mingold`=46; -- Daggerspine Shorehunter (sample size 32)
UPDATE `creature_template` SET `maxgold`=181 WHERE `entry`=2369 && `maxgold`=65; -- Daggerspine Shorehunter (sample size 32)
UPDATE `creature_template` SET `maxgold`=118 WHERE `entry`=2370 && `maxgold`=58; -- Daggerspine Screamer
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2371 && `mingold`=45; -- Daggerspine Siren (sample size 43)
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=2371 && `maxgold`=63; -- Daggerspine Siren (sample size 43)
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=2372 && `mingold`=37; -- Mudsnout Gnoll
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=2372 && `maxgold`=53; -- Mudsnout Gnoll
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2373 && `mingold`=35; -- Mudsnout Shaman
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=2373 && `maxgold`=51; -- Mudsnout Shaman
UPDATE `creature_template` SET `maxgold`=149 WHERE `entry`=2374 && `maxgold`=59; -- Torn Fin Muckdweller
UPDATE `creature_template` SET `mingold`=26 WHERE `entry`=2375 && `mingold`=43; -- Torn Fin Coastrunner (sample size 25)
UPDATE `creature_template` SET `maxgold`=147 WHERE `entry`=2375 && `maxgold`=61; -- Torn Fin Coastrunner (sample size 25)
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=2376 && `mingold`=42; -- Torn Fin Oracle (sample size 43)
UPDATE `creature_template` SET `maxgold`=177 WHERE `entry`=2376 && `maxgold`=60; -- Torn Fin Oracle (sample size 43)
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=2377 && `mingold`=44; -- Torn Fin Tidehunter (sample size 52)
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=2377 && `maxgold`=63; -- Torn Fin Tidehunter (sample size 52)
UPDATE `creature_template` SET `maxgold`=122 WHERE `entry`=2387 && `maxgold`=47; -- Hillsbrad Councilman
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=2403 && `mingold`=32; -- Farmer Getz
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=2403 && `maxgold`=47; -- Farmer Getz
UPDATE `creature_template` SET `maxgold`=80 WHERE `entry`=2404 && `maxgold`=53; -- Blacksmith Verringtan
UPDATE `creature_template` SET `maxgold`=231 WHERE `entry`=2411 && `maxgold`=71; -- Ricter
UPDATE `creature_template` SET `maxgold`=190 WHERE `entry`=2412 && `maxgold`=71; -- Alina
UPDATE `creature_template` SET `maxgold`=202 WHERE `entry`=2413 && `maxgold`=75; -- Dermot
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=2414 && `mingold`=100; -- Kegan Darkmar
UPDATE `creature_template` SET `maxgold`=209 WHERE `entry`=2414 && `maxgold`=150; -- Kegan Darkmar
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=2415 && `mingold`=51; -- Warden Belamoore
UPDATE `creature_template` SET `maxgold`=154 WHERE `entry`=2415 && `maxgold`=71; -- Warden Belamoore
UPDATE `creature_template` SET `mingold`=158 WHERE `entry`=2416 && `mingold`=232; -- Crushridge Plunderer
UPDATE `creature_template` SET `maxgold`=633 WHERE `entry`=2416 && `maxgold`=308; -- Crushridge Plunderer
UPDATE `creature_template` SET `maxgold`=942 WHERE `entry`=2417 && `maxgold`=287; -- Grel'borg the Miser
UPDATE `creature_template` SET `mingold`=202 WHERE `entry`=2420 && `mingold`=402; -- Targ
UPDATE `creature_template` SET `maxgold`=681 WHERE `entry`=2420 && `maxgold`=530; -- Targ
UPDATE `creature_template` SET `maxgold`=764 WHERE `entry`=2421 && `maxgold`=345; -- Muckrake
UPDATE `creature_template` SET `maxgold`=958 WHERE `entry`=2422 && `maxgold`=332; -- Glommus
UPDATE `creature_template` SET `maxgold`=320 WHERE `entry`=2423 && `maxgold`=91; -- Lord Aliden Perenolde
UPDATE `creature_template` SET `maxgold`=56 WHERE `entry`=2427 && `maxgold`=47; -- Jailor Eston
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=2428 && `maxgold`=46; -- Jailor Marlgen
UPDATE `creature_template` SET `maxgold`=224 WHERE `entry`=2431 && `maxgold`=84; -- Jailor Borhuin
UPDATE `creature_template` SET `maxgold`=154 WHERE `entry`=2440 && `maxgold`=70; -- Drunken Footpad
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=2448 && `mingold`=37; -- Clerk Horrace Whitesteed
UPDATE `creature_template` SET `maxgold`=80 WHERE `entry`=2448 && `maxgold`=54; -- Clerk Horrace Whitesteed
UPDATE `creature_template` SET `maxgold`=71 WHERE `entry`=2449 && `maxgold`=50; -- Citizen Wilkes
UPDATE `creature_template` SET `maxgold`=114 WHERE `entry`=2450 && `maxgold`=60; -- Miner Hackett
UPDATE `creature_template` SET `maxgold`=98 WHERE `entry`=2451 && `maxgold`=50; -- Farmer Kalaba
UPDATE `creature_template` SET `maxgold`=223 WHERE `entry`=2452 && `maxgold`=83; -- Skhowl
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=2503 && `mingold`=40; -- Hillsbrad Foreman
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=2503 && `maxgold`=57; -- Hillsbrad Foreman
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=2529 && `mingold`=131; -- Son of Arugal
UPDATE `creature_template` SET `maxgold`=328 WHERE `entry`=2529 && `maxgold`=176; -- Son of Arugal
UPDATE `creature_template` SET `maxgold`=363 WHERE `entry`=2530 && `maxgold`=102; -- Yenniku
UPDATE `creature_template` SET `maxgold`=343 WHERE `entry`=2534 && `maxgold`=108; -- Zanzil the Outcast
UPDATE `creature_template` SET `maxgold`=392 WHERE `entry`=2535 && `maxgold`=110; -- Maury "Club Foot" Wilkins
UPDATE `creature_template` SET `maxgold`=288 WHERE `entry`=2536 && `maxgold`=110; -- Jon-Jon the Crow
UPDATE `creature_template` SET `maxgold`=427 WHERE `entry`=2537 && `maxgold`=110; -- Chucky "Ten Thumbs"
UPDATE `creature_template` SET `maxgold`=316 WHERE `entry`=2541 && `maxgold`=101; -- Lord Sakrasis
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=2545 && `maxgold`=94; -- "Pretty Boy" Duncan
UPDATE `creature_template` SET `mingold`=88 WHERE `entry`=2546 && `mingold`=91; -- Fleet Master Firallon
UPDATE `creature_template` SET `maxgold`=408 WHERE `entry`=2546 && `maxgold`=124; -- Fleet Master Firallon
UPDATE `creature_template` SET `maxgold`=323 WHERE `entry`=2547 && `maxgold`=107; -- Ironpatch
UPDATE `creature_template` SET `maxgold`=479 WHERE `entry`=2548 && `maxgold`=125; -- Captain Keelhaul
UPDATE `creature_template` SET `maxgold`=390 WHERE `entry`=2549 && `maxgold`=104; -- Garr Salthoof
UPDATE `creature_template` SET `maxgold`=385 WHERE `entry`=2550 && `maxgold`=108; -- Captain Stillwater
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=2551 && `mingold`=93; -- Brutus
UPDATE `creature_template` SET `maxgold`=253 WHERE `entry`=2551 && `maxgold`=126; -- Brutus
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=2552 && `mingold`=46; -- Witherbark Troll
UPDATE `creature_template` SET `maxgold`=170 WHERE `entry`=2552 && `maxgold`=65; -- Witherbark Troll
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=2553 && `mingold`=43; -- Witherbark Shadowcaster
UPDATE `creature_template` SET `maxgold`=161 WHERE `entry`=2553 && `maxgold`=61; -- Witherbark Shadowcaster
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=2554 && `mingold`=50; -- Witherbark Axe Thrower (sample size 56)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=2554 && `maxgold`=70; -- Witherbark Axe Thrower (sample size 56)
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=2555 && `mingold`=48; -- Witherbark Witch Doctor (sample size 66)
UPDATE `creature_template` SET `maxgold`=222 WHERE `entry`=2555 && `maxgold`=68; -- Witherbark Witch Doctor (sample size 66)
UPDATE `creature_template` SET `mingold`=37 WHERE `entry`=2556 && `mingold`=54; -- Witherbark Headhunter (sample size 80)
UPDATE `creature_template` SET `maxgold`=245 WHERE `entry`=2556 && `maxgold`=75; -- Witherbark Headhunter (sample size 80)
UPDATE `creature_template` SET `mingold`=43 WHERE `entry`=2557 && `mingold`=54; -- Witherbark Shadow Hunter
UPDATE `creature_template` SET `maxgold`=262 WHERE `entry`=2557 && `maxgold`=76; -- Witherbark Shadow Hunter
UPDATE `creature_template` SET `maxgold`=763 WHERE `entry`=2558 && `maxgold`=314; -- Witherbark Berserker
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=2562 && `mingold`=50; -- Boulderfist Ogre (sample size 26)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=2562 && `maxgold`=70; -- Boulderfist Ogre (sample size 26)
UPDATE `creature_template` SET `mingold`=51 WHERE `entry`=2564 && `mingold`=53; -- Boulderfist Enforcer (sample size 29)
UPDATE `creature_template` SET `maxgold`=227 WHERE `entry`=2564 && `maxgold`=74; -- Boulderfist Enforcer (sample size 29)
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=2566 && `mingold`=59; -- Boulderfist Brute (sample size 33)
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=2566 && `maxgold`=81; -- Boulderfist Brute (sample size 33)
UPDATE `creature_template` SET `mingold`=46 WHERE `entry`=2567 && `mingold`=51; -- Boulderfist Magus
UPDATE `creature_template` SET `maxgold`=281 WHERE `entry`=2567 && `maxgold`=71; -- Boulderfist Magus
UPDATE `creature_template` SET `mingold`=208 WHERE `entry`=2569 && `mingold`=238; -- Boulderfist Mauler (sample size 24)
UPDATE `creature_template` SET `maxgold`=860 WHERE `entry`=2569 && `maxgold`=316; -- Boulderfist Mauler (sample size 24)
UPDATE `creature_template` SET `maxgold`=919 WHERE `entry`=2570 && `maxgold`=285; -- Boulderfist Shaman
UPDATE `creature_template` SET `mingold`=186 WHERE `entry`=2571 && `mingold`=259; -- Boulderfist Lord
UPDATE `creature_template` SET `maxgold`=904 WHERE `entry`=2571 && `maxgold`=343; -- Boulderfist Lord
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=2572 && `mingold`=61; -- Drywhisker Kobold (sample size 79)
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=2572 && `maxgold`=84; -- Drywhisker Kobold (sample size 79)
UPDATE `creature_template` SET `mingold`=60 WHERE `entry`=2573 && `mingold`=52; -- Drywhisker Surveyor (sample size 25)
UPDATE `creature_template` SET `maxgold`=295 WHERE `entry`=2573 && `maxgold`=73; -- Drywhisker Surveyor (sample size 25)
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=2574 && `mingold`=62; -- Drywhisker Digger (sample size 50)
UPDATE `creature_template` SET `maxgold`=276 WHERE `entry`=2574 && `maxgold`=85; -- Drywhisker Digger (sample size 50)
UPDATE `creature_template` SET `maxgold`=146 WHERE `entry`=2575 && `maxgold`=63; -- Dark Iron Supplier
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=2577 && `maxgold`=61; -- Dark Iron Shadowcaster
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=2581 && `mingold`=51; -- Dabyrie Militia
UPDATE `creature_template` SET `maxgold`=191 WHERE `entry`=2581 && `maxgold`=71; -- Dabyrie Militia
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=2582 && `mingold`=46; -- Dabyrie Laborer
UPDATE `creature_template` SET `maxgold`=170 WHERE `entry`=2582 && `maxgold`=65; -- Dabyrie Laborer
UPDATE `creature_template` SET `maxgold`=429 WHERE `entry`=2583 && `maxgold`=272; -- Stromgarde Troll Hunter
UPDATE `creature_template` SET `maxgold`=855 WHERE `entry`=2584 && `maxgold`=330; -- Stromgarde Defender
UPDATE `creature_template` SET `mingold`=256 WHERE `entry`=2585 && `mingold`=259; -- Stromgarde Vindicator
UPDATE `creature_template` SET `maxgold`=569 WHERE `entry`=2585 && `maxgold`=343; -- Stromgarde Vindicator
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=2586 && `mingold`=46; -- Syndicate Highwayman (sample size 58)
UPDATE `creature_template` SET `maxgold`=181 WHERE `entry`=2586 && `maxgold`=65; -- Syndicate Highwayman (sample size 58)
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=2587 && `mingold`=50; -- Syndicate Pathstalker (sample size 32)
UPDATE `creature_template` SET `maxgold`=192 WHERE `entry`=2587 && `maxgold`=70; -- Syndicate Pathstalker (sample size 32)
UPDATE `creature_template` SET `mingold`=160 WHERE `entry`=2588 && `mingold`=228; -- Syndicate Prowler (sample size 35)
UPDATE `creature_template` SET `maxgold`=815 WHERE `entry`=2588 && `maxgold`=303; -- Syndicate Prowler (sample size 35)
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=2589 && `mingold`=49; -- Syndicate Mercenary (sample size 56)
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=2589 && `maxgold`=69; -- Syndicate Mercenary (sample size 56)
UPDATE `creature_template` SET `maxgold`=774 WHERE `entry`=2590 && `maxgold`=240; -- Syndicate Conjuror
UPDATE `creature_template` SET `maxgold`=847 WHERE `entry`=2591 && `maxgold`=255; -- Syndicate Magus
UPDATE `creature_template` SET `mingold`=46 WHERE `entry`=2595 && `mingold`=65; -- Daggerspine Raider (sample size 53)
UPDATE `creature_template` SET `maxgold`=312 WHERE `entry`=2595 && `maxgold`=90; -- Daggerspine Raider (sample size 53)
UPDATE `creature_template` SET `maxgold`=287 WHERE `entry`=2596 && `maxgold`=78; -- Daggerspine Sorceress
UPDATE `creature_template` SET `mingold`=185 WHERE `entry`=2597 && `mingold`=533; -- Lord Falconcrest
UPDATE `creature_template` SET `maxgold`=783 WHERE `entry`=2597 && `maxgold`=700; -- Lord Falconcrest
UPDATE `creature_template` SET `maxgold`=808 WHERE `entry`=2598 && `maxgold`=383; -- Darbel Montrose
UPDATE `creature_template` SET `maxgold`=179 WHERE `entry`=2600 && `maxgold`=69; -- Singer
UPDATE `creature_template` SET `maxgold`=780 WHERE `entry`=2602 && `maxgold`=590; -- Ruul Onestone
UPDATE `creature_template` SET `maxgold`=504 WHERE `entry`=2607 && `maxgold`=343; -- Prince Galen Trollbane
UPDATE `creature_template` SET `maxgold`=1122 WHERE `entry`=2611 && `maxgold`=366; -- Fozruk
UPDATE `creature_template` SET `maxgold`=611 WHERE `entry`=2612 && `maxgold`=285; -- Lieutenant Valorcall
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=2618 && `mingold`=53; -- Hammerfall Peon
UPDATE `creature_template` SET `maxgold`=188 WHERE `entry`=2618 && `maxgold`=74; -- Hammerfall Peon
UPDATE `creature_template` SET `mingold`=39 WHERE `entry`=2619 && `mingold`=54; -- Hammerfall Grunt (sample size 22)
UPDATE `creature_template` SET `maxgold`=244 WHERE `entry`=2619 && `maxgold`=75; -- Hammerfall Grunt (sample size 22)
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=2628 && `mingold`=53; -- Dalaran Worker (sample size 22)
UPDATE `creature_template` SET `maxgold`=222 WHERE `entry`=2628 && `maxgold`=74; -- Dalaran Worker (sample size 22)
UPDATE `creature_template` SET `mingold`=71 WHERE `entry`=2639 && `mingold`=86; -- Vilebranch Axe Thrower
UPDATE `creature_template` SET `maxgold`=456 WHERE `entry`=2639 && `maxgold`=118; -- Vilebranch Axe Thrower
UPDATE `creature_template` SET `maxgold`=476 WHERE `entry`=2640 && `maxgold`=108; -- Vilebranch Witch Doctor
UPDATE `creature_template` SET `maxgold`=1484 WHERE `entry`=2641 && `maxgold`=436; -- Vilebranch Headhunter
UPDATE `creature_template` SET `maxgold`=1382 WHERE `entry`=2642 && `maxgold`=355; -- Vilebranch Shadowcaster
UPDATE `creature_template` SET `mingold`=245 WHERE `entry`=2643 && `mingold`=336; -- Vilebranch Berserker
UPDATE `creature_template` SET `maxgold`=1545 WHERE `entry`=2643 && `maxgold`=444; -- Vilebranch Berserker
UPDATE `creature_template` SET `mingold`=310 WHERE `entry`=2644 && `mingold`=351; -- Vilebranch Hideskinner
UPDATE `creature_template` SET `maxgold`=1593 WHERE `entry`=2644 && `maxgold`=463; -- Vilebranch Hideskinner
UPDATE `creature_template` SET `maxgold`=1687 WHERE `entry`=2645 && `maxgold`=391; -- Vilebranch Shadow Hunter
UPDATE `creature_template` SET `mingold`=295 WHERE `entry`=2646 && `mingold`=361; -- Vilebranch Blood Drinker
UPDATE `creature_template` SET `maxgold`=1728 WHERE `entry`=2646 && `maxgold`=476; -- Vilebranch Blood Drinker
UPDATE `creature_template` SET `mingold`=337 WHERE `entry`=2647 && `mingold`=361; -- Vilebranch Soul Eater
UPDATE `creature_template` SET `maxgold`=1710 WHERE `entry`=2647 && `maxgold`=476; -- Vilebranch Soul Eater
UPDATE `creature_template` SET `mingold`=348 WHERE `entry`=2648 && `mingold`=375; -- Vilebranch Aman'zasi Guard
UPDATE `creature_template` SET `maxgold`=1888 WHERE `entry`=2648 && `maxgold`=495; -- Vilebranch Aman'zasi Guard
UPDATE `creature_template` SET `mingold`=66 WHERE `entry`=2649 && `mingold`=71; -- Witherbark Scalper
UPDATE `creature_template` SET `maxgold`=357 WHERE `entry`=2649 && `maxgold`=98; -- Witherbark Scalper
UPDATE `creature_template` SET `maxgold`=359 WHERE `entry`=2650 && `maxgold`=102; -- Witherbark Zealot
UPDATE `creature_template` SET `mingold`=79 WHERE `entry`=2651 && `mingold`=75; -- Witherbark Hideskinner (sample size 23)
UPDATE `creature_template` SET `maxgold`=392 WHERE `entry`=2651 && `maxgold`=103; -- Witherbark Hideskinner (sample size 23)
UPDATE `creature_template` SET `maxgold`=415 WHERE `entry`=2652 && `maxgold`=104; -- Witherbark Venomblood
UPDATE `creature_template` SET `maxgold`=445 WHERE `entry`=2653 && `maxgold`=111; -- Witherbark Sadist
UPDATE `creature_template` SET `mingold`=68 WHERE `entry`=2655 && `mingold`=89; -- Green Sludge (sample size 36)
UPDATE `creature_template` SET `maxgold`=294 WHERE `entry`=2655 && `maxgold`=121; -- Green Sludge (sample size 36)
UPDATE `creature_template` SET `mingold`=52 WHERE `entry`=2656 && `mingold`=94; -- Jade Ooze (sample size 26)
UPDATE `creature_template` SET `maxgold`=240 WHERE `entry`=2656 && `maxgold`=128; -- Jade Ooze (sample size 26)
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=2691 && `mingold`=78; -- Highvale Outrunner (sample size 34)
UPDATE `creature_template` SET `maxgold`=426 WHERE `entry`=2691 && `maxgold`=107; -- Highvale Outrunner (sample size 34)
UPDATE `creature_template` SET `maxgold`=440 WHERE `entry`=2692 && `maxgold`=111; -- Highvale Scout (sample size 34)
UPDATE `creature_template` SET `mingold`=84 WHERE `entry`=2693 && `mingold`=88; -- Highvale Marksman (sample size 37)
UPDATE `creature_template` SET `maxgold`=456 WHERE `entry`=2693 && `maxgold`=120; -- Highvale Marksman (sample size 37)
UPDATE `creature_template` SET `mingold`=80 WHERE `entry`=2694 && `mingold`=79; -- Highvale Ranger (sample size 32)
UPDATE `creature_template` SET `maxgold`=501 WHERE `entry`=2694 && `maxgold`=108; -- Highvale Ranger (sample size 32)
UPDATE `creature_template` SET `maxgold`=168 WHERE `entry`=2714 && `maxgold`=79; -- Forsaken Courier
UPDATE `creature_template` SET `maxgold`=147 WHERE `entry`=2716 && `maxgold`=98; -- Dustbelcher Wyrmhunter
UPDATE `creature_template` SET `maxgold`=165 WHERE `entry`=2718 && `maxgold`=92; -- Dustbelcher Shaman
UPDATE `creature_template` SET `maxgold`=243 WHERE `entry`=2721 && `maxgold`=76; -- Forsaken Bodyguard
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=2723 && `mingold`=65; -- Stone Golem
UPDATE `creature_template` SET `maxgold`=285 WHERE `entry`=2723 && `maxgold`=90; -- Stone Golem
UPDATE `creature_template` SET `maxgold`=357 WHERE `entry`=2725 && `maxgold`=91; -- Scalding Whelp
UPDATE `creature_template` SET `mingold`=183 WHERE `entry`=2726 && `mingold`=308; -- Scorched Guardian
UPDATE `creature_template` SET `maxgold`=1285 WHERE `entry`=2726 && `maxgold`=407; -- Scorched Guardian
UPDATE `creature_template` SET `maxgold`=227 WHERE `entry`=2733 && `maxgold`=85; -- Apothecary Jorell
UPDATE `creature_template` SET `maxgold`=794 WHERE `entry`=2738 && `maxgold`=308; -- Stromgarde Cavalryman
UPDATE `creature_template` SET `maxgold`=251 WHERE `entry`=2739 && `maxgold`=81; -- Shadowforge Tunneler
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=2740 && `maxgold`=71; -- Shadowforge Darkweaver
UPDATE `creature_template` SET `maxgold`=315 WHERE `entry`=2742 && `maxgold`=82; -- Shadowforge Chanter
UPDATE `creature_template` SET `mingold`=47 WHERE `entry`=2743 && `mingold`=65; -- Shadowforge Warrior
UPDATE `creature_template` SET `maxgold`=312 WHERE `entry`=2743 && `maxgold`=90; -- Shadowforge Warrior
UPDATE `creature_template` SET `maxgold`=1890 WHERE `entry`=2757 && `maxgold`=643; -- Blacklash
UPDATE `creature_template` SET `maxgold`=1698 WHERE `entry`=2759 && `maxgold`=576; -- Hematus
UPDATE `creature_template` SET `maxgold`=814 WHERE `entry`=2763 && `maxgold`=534; -- Thenan
UPDATE `creature_template` SET `mingold`=55 WHERE `entry`=2765 && `mingold`=68; -- Znort
UPDATE `creature_template` SET `maxgold`=126 WHERE `entry`=2765 && `maxgold`=94; -- Znort
UPDATE `creature_template` SET `maxgold`=306 WHERE `entry`=2779 && `maxgold`=99; -- Prince Nazjak
UPDATE `creature_template` SET `maxgold`=699 WHERE `entry`=2780 && `maxgold`=364; -- Caretaker Nevlin
UPDATE `creature_template` SET `mingold`=208 WHERE `entry`=2781 && `mingold`=275; -- Caretaker Weston
UPDATE `creature_template` SET `maxgold`=609 WHERE `entry`=2782 && `maxgold`=353; -- Caretaker Alaric
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=2793 && `maxgold`=83; -- Kor'gresh Coldrage
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=2893 && `mingold`=66; -- Stonevault Bonesnapper (sample size 38)
UPDATE `creature_template` SET `maxgold`=334 WHERE `entry`=2893 && `maxgold`=91; -- Stonevault Bonesnapper (sample size 38)
UPDATE `creature_template` SET `maxgold`=353 WHERE `entry`=2894 && `maxgold`=87; -- Stonevault Shaman
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=2906 && `maxgold`=81; -- Dustbelcher Warrior
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=2907 && `mingold`=55; -- Dustbelcher Mystic
UPDATE `creature_template` SET `maxgold`=210 WHERE `entry`=2907 && `maxgold`=77; -- Dustbelcher Mystic
UPDATE `creature_template` SET `maxgold`=346 WHERE `entry`=2927 && `maxgold`=106; -- Vicious Owlbeast
UPDATE `creature_template` SET `maxgold`=449 WHERE `entry`=2928 && `maxgold`=111; -- Primitive Owlbeast
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=2929 && `mingold`=89; -- Savage Owlbeast (sample size 48)
UPDATE `creature_template` SET `maxgold`=495 WHERE `entry`=2929 && `maxgold`=121; -- Savage Owlbeast (sample size 48)
UPDATE `creature_template` SET `mingold`=80 WHERE `entry`=2932 && `mingold`=249; -- Magregan Deepshadow
UPDATE `creature_template` SET `maxgold`=270 WHERE `entry`=2944 && `maxgold`=105; -- Boss Tho'grun
UPDATE `creature_template` SET `maxgold`=186 WHERE `entry`=2945 && `maxgold`=103; -- Murdaloc
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2949 && `mingold`=4; -- Palemane Tanner
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2950 && `mingold`=5; -- Palemane Skinner
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2951 && `mingold`=6; -- Palemane Poacher
UPDATE `creature_template` SET `maxgold`=5 WHERE `entry`=2952 && `maxgold`=7; -- Bristleback Quilboar (sample size 50)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2962 && `mingold`=6; -- Windfury Harpy (sample size 28)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2963 && `mingold`=8; -- Windfury Wind Witch
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2964 && `mingold`=8; -- Windfury Sorceress (sample size 24)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=2964 && `maxgold`=16; -- Windfury Sorceress (sample size 24)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2965 && `mingold`=10; -- Windfury Matriarch (sample size 26)
UPDATE `creature_template` SET `maxgold`=16 WHERE `entry`=2965 && `maxgold`=18; -- Windfury Matriarch (sample size 26)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2967 && `mingold`=10; -- Galak Centaur
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2975 && `mingold`=4; -- Venture Co. Hireling (sample size 24)
UPDATE `creature_template` SET `maxgold`=7 WHERE `entry`=2975 && `maxgold`=10; -- Venture Co. Hireling (sample size 24)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2976 && `mingold`=6; -- Venture Co. Laborer
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2977 && `mingold`=7; -- Venture Co. Taskmaster
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=2978 && `mingold`=8; -- Venture Co. Worker (sample size 36)
UPDATE `creature_template` SET `maxgold`=14 WHERE `entry`=2978 && `maxgold`=15; -- Venture Co. Worker (sample size 36)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=2979 && `mingold`=9; -- Venture Co. Supervisor (sample size 22)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=2979 && `maxgold`=17; -- Venture Co. Supervisor (sample size 22)
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=2989 && `mingold`=6; -- Bael'dun Digger
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=2990 && `mingold`=7; -- Bael'dun Appraiser
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=3051 && `mingold`=13; -- Supervisor Fizsprocket
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=3101 && `mingold`=2; -- Vile Familiar
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3103 && `mingold`=5; -- Makrura Clacker
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=3104 && `mingold`=5; -- Makrura Shellhide
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3111 && `mingold`=5; -- Razormane Quilboar
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3112 && `mingold`=7; -- Razormane Scout
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3113 && `mingold`=7; -- Razormane Dustrunner
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3114 && `mingold`=9; -- Razormane Battleguard
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3115 && `mingold`=8; -- Dustwind Harpy
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=3116 && `mingold`=7; -- Dustwind Pillager
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3117 && `mingold`=9; -- Dustwind Savage
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=3118 && `mingold`=11; -- Dustwind Storm Witch
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3119 && `mingold`=5; -- Kolkar Drudge
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=3128 && `mingold`=4; -- Kul Tiras Sailor
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=3129 && `mingold`=5; -- Kul Tiras Marine
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3195 && `mingold`=8; -- Burning Blade Thug
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3196 && `mingold`=9; -- Burning Blade Neophyte
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3197 && `mingold`=9; -- Burning Blade Fanatic (sample size 46)
UPDATE `creature_template` SET `maxgold`=15 WHERE `entry`=3197 && `maxgold`=17; -- Burning Blade Fanatic (sample size 46)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3198 && `mingold`=10; -- Burning Blade Apprentice (sample size 22)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=3198 && `maxgold`=18; -- Burning Blade Apprentice (sample size 22)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3199 && `mingold`=10; -- Burning Blade Cultist
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3203 && `mingold`=12; -- Fizzle Darkstorm
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=3204 && `mingold`=16; -- Gazz'uz
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=3206 && `mingold`=7; -- Voodoo Troll
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3207 && `mingold`=7; -- Hexed Troll
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3232 && `mingold`=9; -- Bristleback Interloper
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3258 && `mingold`=20; -- Bristleback Hunter
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=3258 && `maxgold`=31; -- Bristleback Hunter
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=3260 && `mingold`=18; -- Bristleback Water Seeker
UPDATE `creature_template` SET `maxgold`=47 WHERE `entry`=3260 && `maxgold`=29; -- Bristleback Water Seeker
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=3261 && `mingold`=21; -- Bristleback Thornweaver (sample size 35)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=3261 && `maxgold`=33; -- Bristleback Thornweaver (sample size 35)
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=3263 && `mingold`=22; -- Bristleback Geomancer (sample size 31)
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=3263 && `maxgold`=33; -- Bristleback Geomancer (sample size 31)
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=3265 && `mingold`=12; -- Razormane Hunter
UPDATE `creature_template` SET `maxgold`=23 WHERE `entry`=3265 && `maxgold`=20; -- Razormane Hunter
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3266 && `mingold`=13; -- Razormane Defender
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=3266 && `maxgold`=22; -- Razormane Defender
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3267 && `mingold`=11; -- Razormane Water Seeker (sample size 27)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=3267 && `maxgold`=19; -- Razormane Water Seeker (sample size 27)
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3268 && `mingold`=10; -- Razormane Thornweaver (sample size 24)
UPDATE `creature_template` SET `maxgold`=17 WHERE `entry`=3268 && `maxgold`=18; -- Razormane Thornweaver (sample size 24)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3269 && `mingold`=12; -- Razormane Geomancer
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=3269 && `maxgold`=21; -- Razormane Geomancer
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3271 && `mingold`=14; -- Razormane Mystic
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3272 && `mingold`=13; -- Kolkar Wrangler (sample size 29)
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=3272 && `maxgold`=22; -- Kolkar Wrangler (sample size 29)
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=3273 && `mingold`=15; -- Kolkar Stormer (sample size 29)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=3273 && `maxgold`=24; -- Kolkar Stormer (sample size 29)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3275 && `mingold`=17; -- Kolkar Marauder
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3276 && `mingold`=16; -- Witchwing Harpy (sample size 31)
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=3276 && `maxgold`=26; -- Witchwing Harpy (sample size 31)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=3277 && `mingold`=17; -- Witchwing Roguefeather (sample size 22)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=3277 && `maxgold`=27; -- Witchwing Roguefeather (sample size 22)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=3278 && `mingold`=19; -- Witchwing Slayer (sample size 24)
UPDATE `creature_template` SET `maxgold`=46 WHERE `entry`=3278 && `maxgold`=30; -- Witchwing Slayer (sample size 24)
UPDATE `creature_template` SET `maxgold`=47 WHERE `entry`=3280 && `maxgold`=30; -- Witchwing Windcaller
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=3282 && `mingold`=17; -- Venture Co. Mercenary
UPDATE `creature_template` SET `maxgold`=36 WHERE `entry`=3282 && `maxgold`=28; -- Venture Co. Mercenary
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=3283 && `mingold`=19; -- Venture Co. Enforcer
UPDATE `creature_template` SET `maxgold`=36 WHERE `entry`=3283 && `maxgold`=30; -- Venture Co. Enforcer
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3284 && `mingold`=16; -- Venture Co. Drudger (sample size 48)
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=3284 && `maxgold`=26; -- Venture Co. Drudger (sample size 48)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3285 && `mingold`=15; -- Venture Co. Peon (sample size 25)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=3285 && `maxgold`=24; -- Venture Co. Peon (sample size 25)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=3286 && `mingold`=20; -- Venture Co. Overseer
UPDATE `creature_template` SET `maxgold`=43 WHERE `entry`=3286 && `maxgold`=32; -- Venture Co. Overseer
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=3374 && `mingold`=27; -- Bael'dun Excavator (sample size 103)
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=3374 && `maxgold`=40; -- Bael'dun Excavator (sample size 103)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3375 && `mingold`=29; -- Bael'dun Foreman (sample size 21)
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=3375 && `maxgold`=43; -- Bael'dun Foreman (sample size 21)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=3376 && `mingold`=31; -- Bael'dun Soldier
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=3376 && `maxgold`=45; -- Bael'dun Soldier
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=3377 && `mingold`=33; -- Bael'dun Rifleman (sample size 22)
UPDATE `creature_template` SET `maxgold`=111 WHERE `entry`=3377 && `maxgold`=48; -- Bael'dun Rifleman (sample size 22)
UPDATE `creature_template` SET `maxgold`=111 WHERE `entry`=3378 && `maxgold`=52; -- Bael'dun Officer
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=3379 && `mingold`=10; -- Burning Blade Bruiser
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3380 && `mingold`=11; -- Burning Blade Acolyte
UPDATE `creature_template` SET `maxgold`=23 WHERE `entry`=3380 && `maxgold`=19; -- Burning Blade Acolyte
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=3381 && `mingold`=13; -- Southsea Brigand (sample size 38)
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=3381 && `maxgold`=22; -- Southsea Brigand (sample size 38)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=3382 && `mingold`=14; -- Southsea Cannoneer (sample size 25)
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=3382 && `maxgold`=24; -- Southsea Cannoneer (sample size 25)
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=3385 && `mingold`=17; -- Theramore Marine (sample size 58)
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=3385 && `maxgold`=28; -- Theramore Marine (sample size 58)
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=3386 && `mingold`=18; -- Theramore Preserver
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=3386 && `maxgold`=29; -- Theramore Preserver
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=3392 && `mingold`=31; -- Prospector Khazgorm
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=3392 && `maxgold`=45; -- Prospector Khazgorm
UPDATE `creature_template` SET `maxgold`=55 WHERE `entry`=3393 && `maxgold`=37; -- Captain Fairmount
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=3394 && `mingold`=18; -- Barak Kodobane
UPDATE `creature_template` SET `maxgold`=40 WHERE `entry`=3394 && `maxgold`=29; -- Barak Kodobane
UPDATE `creature_template` SET `maxgold`=29 WHERE `entry`=3397 && `maxgold`=24; -- Kolkar Bloodcharger
UPDATE `creature_template` SET `maxgold`=54 WHERE `entry`=3434 && `maxgold`=42; -- Nak
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=3435 && `mingold`=34; -- Lok Orcbane
UPDATE `creature_template` SET `maxgold`=122 WHERE `entry`=3435 && `maxgold`=49; -- Lok Orcbane
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=3436 && `mingold`=34; -- Kuz
UPDATE `creature_template` SET `maxgold`=84 WHERE `entry`=3436 && `maxgold`=49; -- Kuz
UPDATE `creature_template` SET `maxgold`=30 WHERE `entry`=3438 && `maxgold`=27; -- Kreenig Snarlsnout
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=3445 && `mingold`=21; -- Supervisor Lugwizzle
UPDATE `creature_template` SET `maxgold`=53 WHERE `entry`=3445 && `maxgold`=33; -- Supervisor Lugwizzle
UPDATE `creature_template` SET `maxgold`=46 WHERE `entry`=3454 && `maxgold`=35; -- Cannoneer Smythe
UPDATE `creature_template` SET `maxgold`=45 WHERE `entry`=3455 && `maxgold`=35; -- Cannoneer Whessan
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3456 && `mingold`=25; -- Razormane Pathfinder (sample size 22)
UPDATE `creature_template` SET `maxgold`=68 WHERE `entry`=3456 && `maxgold`=38; -- Razormane Pathfinder (sample size 22)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3457 && `mingold`=27; -- Razormane Stalker
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=3457 && `maxgold`=41; -- Razormane Stalker
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=3458 && `mingold`=29; -- Razormane Seer
UPDATE `creature_template` SET `maxgold`=104 WHERE `entry`=3458 && `maxgold`=43; -- Razormane Seer
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=3459 && `mingold`=33; -- Razormane Warfrenzy
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=3459 && `maxgold`=48; -- Razormane Warfrenzy
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=3467 && `mingold`=18; -- Baron Longshore
UPDATE `creature_template` SET `maxgold`=42 WHERE `entry`=3467 && `maxgold`=29; -- Baron Longshore
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=3470 && `mingold`=17; -- Rathorian
UPDATE `creature_template` SET `maxgold`=32 WHERE `entry`=3471 && `maxgold`=28; -- Tinkerer Sniggles
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=3530 && `mingold`=64; -- Pyrewood Tailor
UPDATE `creature_template` SET `maxgold`=79 WHERE `entry`=3533 && `maxgold`=47; -- Moonrage Leatherworker
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=3535 && `mingold`=14; -- Blackmoss the Fetid
UPDATE `creature_template` SET `maxgold`=270 WHERE `entry`=3654 && `maxgold`=248; -- Mutanus the Devourer
UPDATE `creature_template` SET `maxgold`=179 WHERE `entry`=3655 && `maxgold`=108; -- Mad Magglish
UPDATE `creature_template` SET `maxgold`=172 WHERE `entry`=3660 && `maxgold`=66; -- Athrikus Narassin
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=3664 && `maxgold`=50; -- Ilkrud Magthrull
UPDATE `creature_template` SET `maxgold`=35 WHERE `entry`=3667 && `maxgold`=28; -- Anaya Dawnrunner
UPDATE `creature_template` SET `mingold`=87 WHERE `entry`=3669 && `mingold`=125; -- Lord Cobrahn
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=3671 && `mingold`=125; -- Lady Anacondra
UPDATE `creature_template` SET `maxgold`=180 WHERE `entry`=3671 && `maxgold`=168; -- Lady Anacondra
UPDATE `creature_template` SET `maxgold`=255 WHERE `entry`=3673 && `maxgold`=209; -- Lord Serpentis
UPDATE `creature_template` SET `maxgold`=151 WHERE `entry`=3696 && `maxgold`=62; -- Ran Bloodtooth
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=3711 && `mingold`=25; -- Wrathtail Myrmidon
UPDATE `creature_template` SET `maxgold`=57 WHERE `entry`=3711 && `maxgold`=38; -- Wrathtail Myrmidon
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3712 && `mingold`=23; -- Wrathtail Razortail
UPDATE `creature_template` SET `maxgold`=43 WHERE `entry`=3712 && `maxgold`=34; -- Wrathtail Razortail
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=3713 && `mingold`=22; -- Wrathtail Wave Rider (sample size 41)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=3713 && `maxgold`=33; -- Wrathtail Wave Rider (sample size 41)
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=3715 && `mingold`=23; -- Wrathtail Sea Witch
UPDATE `creature_template` SET `maxgold`=64 WHERE `entry`=3715 && `maxgold`=34; -- Wrathtail Sea Witch
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=3717 && `mingold`=20; -- Wrathtail Sorceress (sample size 48)
UPDATE `creature_template` SET `maxgold`=60 WHERE `entry`=3717 && `maxgold`=32; -- Wrathtail Sorceress (sample size 48)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3725 && `mingold`=20; -- Dark Strand Cultist
UPDATE `creature_template` SET `maxgold`=55 WHERE `entry`=3725 && `maxgold`=32; -- Dark Strand Cultist
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3727 && `mingold`=26; -- Dark Strand Enforcer
UPDATE `creature_template` SET `maxgold`=70 WHERE `entry`=3727 && `maxgold`=38; -- Dark Strand Enforcer
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=3728 && `mingold`=21; -- Dark Strand Adept
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=3728 && `maxgold`=32; -- Dark Strand Adept
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=3730 && `mingold`=24; -- Dark Strand Excavator
UPDATE `creature_template` SET `maxgold`=51 WHERE `entry`=3730 && `maxgold`=36; -- Dark Strand Excavator
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=3732 && `mingold`=21; -- Forsaken Seeker
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=3732 && `maxgold`=32; -- Forsaken Seeker
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3733 && `mingold`=22; -- Forsaken Herbalist
UPDATE `creature_template` SET `maxgold`=53 WHERE `entry`=3733 && `maxgold`=33; -- Forsaken Herbalist
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=3734 && `mingold`=25; -- Forsaken Thug
UPDATE `creature_template` SET `maxgold`=66 WHERE `entry`=3734 && `maxgold`=37; -- Forsaken Thug
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=3737 && `mingold`=24; -- Saltspittle Puddlejumper
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=3737 && `maxgold`=36; -- Saltspittle Puddlejumper
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3739 && `mingold`=23; -- Saltspittle Warrior
UPDATE `creature_template` SET `maxgold`=61 WHERE `entry`=3739 && `maxgold`=35; -- Saltspittle Warrior
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=3740 && `mingold`=26; -- Saltspittle Muckdweller
UPDATE `creature_template` SET `maxgold`=70 WHERE `entry`=3740 && `maxgold`=38; -- Saltspittle Muckdweller
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=3742 && `maxgold`=36; -- Saltspittle Oracle
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3743 && `mingold`=35; -- Foulweald Warrior (sample size 28)
UPDATE `creature_template` SET `maxgold`=104 WHERE `entry`=3743 && `maxgold`=51; -- Foulweald Warrior (sample size 28)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=3745 && `mingold`=31; -- Foulweald Pathfinder
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=3745 && `maxgold`=45; -- Foulweald Pathfinder
UPDATE `creature_template` SET `maxgold`=68 WHERE `entry`=3746 && `maxgold`=48; -- Foulweald Den Watcher
UPDATE `creature_template` SET `maxgold`=107 WHERE `entry`=3748 && `maxgold`=45; -- Foulweald Shaman
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=3749 && `maxgold`=48; -- Foulweald Ursa
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=3750 && `mingold`=29; -- Foulweald Totemic (sample size 22)
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=3750 && `maxgold`=43; -- Foulweald Totemic (sample size 22)
UPDATE `creature_template` SET `maxgold`=156 WHERE `entry`=3752 && `maxgold`=61; -- Xavian Rogue
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=3754 && `mingold`=42; -- Xavian Betrayer
UPDATE `creature_template` SET `maxgold`=128 WHERE `entry`=3754 && `maxgold`=59; -- Xavian Betrayer
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=3755 && `mingold`=38; -- Xavian Felsworn
UPDATE `creature_template` SET `maxgold`=75 WHERE `entry`=3755 && `maxgold`=55; -- Xavian Felsworn
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=3757 && `mingold`=40; -- Xavian Hellcaller
UPDATE `creature_template` SET `maxgold`=152 WHERE `entry`=3757 && `maxgold`=57; -- Xavian Hellcaller
UPDATE `creature_template` SET `mingold`=25 WHERE `entry`=3758 && `mingold`=35; -- Felmusk Satyr
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=3758 && `maxgold`=50; -- Felmusk Satyr
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=3759 && `mingold`=37; -- Felmusk Rogue
UPDATE `creature_template` SET `maxgold`=124 WHERE `entry`=3759 && `maxgold`=53; -- Felmusk Rogue
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=3762 && `mingold`=33; -- Felmusk Felsworn (sample size 29)
UPDATE `creature_template` SET `maxgold`=121 WHERE `entry`=3762 && `maxgold`=48; -- Felmusk Felsworn (sample size 29)
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=3763 && `mingold`=37; -- Felmusk Shadowstalker (sample size 21)
UPDATE `creature_template` SET `maxgold`=128 WHERE `entry`=3763 && `maxgold`=54; -- Felmusk Shadowstalker (sample size 21)
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=3765 && `mingold`=37; -- Bleakheart Satyr (sample size 27)
UPDATE `creature_template` SET `maxgold`=129 WHERE `entry`=3765 && `maxgold`=53; -- Bleakheart Satyr (sample size 27)
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=3767 && `mingold`=40; -- Bleakheart Trickster (sample size 27)
UPDATE `creature_template` SET `maxgold`=140 WHERE `entry`=3767 && `maxgold`=57; -- Bleakheart Trickster (sample size 27)
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=3770 && `mingold`=39; -- Bleakheart Shadowstalker (sample size 28)
UPDATE `creature_template` SET `maxgold`=133 WHERE `entry`=3770 && `maxgold`=56; -- Bleakheart Shadowstalker (sample size 28)
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=3771 && `mingold`=35; -- Bleakheart Hellcaller
UPDATE `creature_template` SET `maxgold`=128 WHERE `entry`=3771 && `maxgold`=51; -- Bleakheart Hellcaller
UPDATE `creature_template` SET `maxgold`=97 WHERE `entry`=3772 && `maxgold`=43; -- Lesser Felguard
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=3780 && `mingold`=28; -- Shadethicket Moss Eater
UPDATE `creature_template` SET `maxgold`=80 WHERE `entry`=3780 && `maxgold`=41; -- Shadethicket Moss Eater
UPDATE `creature_template` SET `maxgold`=93 WHERE `entry`=3781 && `maxgold`=43; -- Shadethicket Wood Shaper
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=3782 && `mingold`=35; -- Shadethicket Stone Mover
UPDATE `creature_template` SET `maxgold`=94 WHERE `entry`=3782 && `maxgold`=51; -- Shadethicket Stone Mover
UPDATE `creature_template` SET `maxgold`=48 WHERE `entry`=3783 && `maxgold`=41; -- Shadethicket Raincaller
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=3784 && `mingold`=38; -- Shadethicket Bark Ripper
UPDATE `creature_template` SET `maxgold`=122 WHERE `entry`=3784 && `maxgold`=54; -- Shadethicket Bark Ripper
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=3789 && `mingold`=41; -- Terrowulf Fleshripper
UPDATE `creature_template` SET `maxgold`=124 WHERE `entry`=3789 && `maxgold`=59; -- Terrowulf Fleshripper
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=3791 && `mingold`=43; -- Terrowulf Shadow Weaver
UPDATE `creature_template` SET `maxgold`=123 WHERE `entry`=3791 && `maxgold`=61; -- Terrowulf Shadow Weaver
UPDATE `creature_template` SET `maxgold`=104 WHERE `entry`=3797 && `maxgold`=48; -- Cenarion Protector
UPDATE `creature_template` SET `maxgold`=133 WHERE `entry`=3799 && `maxgold`=63; -- Severed Druid
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=3801 && `mingold`=38; -- Severed Sleeper
UPDATE `creature_template` SET `maxgold`=130 WHERE `entry`=3801 && `maxgold`=55; -- Severed Sleeper
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=3802 && `mingold`=39; -- Severed Dreamer
UPDATE `creature_template` SET `maxgold`=166 WHERE `entry`=3802 && `maxgold`=55; -- Severed Dreamer
UPDATE `creature_template` SET `mingold`=37 WHERE `entry`=3803 && `mingold`=41; -- Severed Keeper
UPDATE `creature_template` SET `maxgold`=166 WHERE `entry`=3803 && `maxgold`=58; -- Severed Keeper
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=3804 && `mingold`=42; -- Forsaken Intruder
UPDATE `creature_template` SET `maxgold`=131 WHERE `entry`=3804 && `maxgold`=59; -- Forsaken Intruder
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=3806 && `mingold`=43; -- Forsaken Infiltrator
UPDATE `creature_template` SET `maxgold`=156 WHERE `entry`=3806 && `maxgold`=61; -- Forsaken Infiltrator
UPDATE `creature_template` SET `maxgold`=151 WHERE `entry`=3807 && `maxgold`=61; -- Forsaken Assassin
UPDATE `creature_template` SET `maxgold`=150 WHERE `entry`=3808 && `maxgold`=59; -- Forsaken Dark Stalker
UPDATE `creature_template` SET `maxgold`=133 WHERE `entry`=3815 && `maxgold`=53; -- Blink Dragon
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=3833 && `mingold`=36; -- Cenarion Vindicator
UPDATE `creature_template` SET `maxgold`=57 WHERE `entry`=3833 && `maxgold`=52; -- Cenarion Vindicator
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=3834 && `mingold`=40; -- Crazed Ancient
UPDATE `creature_template` SET `maxgold`=143 WHERE `entry`=3834 && `maxgold`=57; -- Crazed Ancient
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=3840 && `mingold`=89; -- Druid of the Fang
UPDATE `creature_template` SET `maxgold`=136 WHERE `entry`=3840 && `maxgold`=121; -- Druid of the Fang
UPDATE `creature_template` SET `maxgold`=154 WHERE `entry`=3849 && `maxgold`=119; -- Deathstalker Adamant
UPDATE `creature_template` SET `mingold`=59 WHERE `entry`=3850 && `mingold`=79; -- Sorcerer Ashcrombe
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=3851 && `mingold`=79; -- Shadowfang Whitescalp (sample size 26)
UPDATE `creature_template` SET `maxgold`=178 WHERE `entry`=3851 && `maxgold`=108; -- Shadowfang Whitescalp (sample size 26)
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=3853 && `mingold`=85; -- Shadowfang Moonwalker (sample size 26)
UPDATE `creature_template` SET `maxgold`=192 WHERE `entry`=3853 && `maxgold`=115; -- Shadowfang Moonwalker (sample size 26)
UPDATE `creature_template` SET `maxgold`=164 WHERE `entry`=3854 && `maxgold`=81; -- Shadowfang Wolfguard
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=3855 && `mingold`=95; -- Shadowfang Darksoul (sample size 24)
UPDATE `creature_template` SET `maxgold`=209 WHERE `entry`=3855 && `maxgold`=129; -- Shadowfang Darksoul (sample size 24)
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=3857 && `mingold`=109; -- Shadowfang Glutton
UPDATE `creature_template` SET `maxgold`=202 WHERE `entry`=3857 && `maxgold`=148; -- Shadowfang Glutton
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=3859 && `mingold`=117; -- Shadowfang Ragetooth
UPDATE `creature_template` SET `maxgold`=303 WHERE `entry`=3859 && `maxgold`=158; -- Shadowfang Ragetooth
UPDATE `creature_template` SET `mingold`=48 WHERE `entry`=3873 && `mingold`=121; -- Tormented Officer
UPDATE `creature_template` SET `maxgold`=290 WHERE `entry`=3873 && `maxgold`=163; -- Tormented Officer
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=3875 && `mingold`=99; -- Haunted Servitor (sample size 32)
UPDATE `creature_template` SET `maxgold`=215 WHERE `entry`=3875 && `maxgold`=134; -- Haunted Servitor (sample size 32)
UPDATE `creature_template` SET `mingold`=68 WHERE `entry`=3877 && `mingold`=113; -- Wailing Guardsman (sample size 21)
UPDATE `creature_template` SET `maxgold`=259 WHERE `entry`=3877 && `maxgold`=153; -- Wailing Guardsman (sample size 21)
UPDATE `creature_template` SET `maxgold`=60 WHERE `entry`=3879 && `maxgold`=34; -- Dark Strand Assassin
UPDATE `creature_template` SET `mingold`=120 WHERE `entry`=3886 && `mingold`=128; -- Razorclaw the Butcher
UPDATE `creature_template` SET `maxgold`=233 WHERE `entry`=3886 && `maxgold`=172; -- Razorclaw the Butcher
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=3887 && `mingold`=178; -- Baron Silverlaine
UPDATE `creature_template` SET `maxgold`=279 WHERE `entry`=3887 && `maxgold`=237; -- Baron Silverlaine
UPDATE `creature_template` SET `maxgold`=88 WHERE `entry`=3893 && `maxgold`=49; -- Forsaken Scout
UPDATE `creature_template` SET `maxgold`=90 WHERE `entry`=3898 && `maxgold`=52; -- Aligar the Tormentor
UPDATE `creature_template` SET `mingold`=51 WHERE `entry`=3914 && `mingold`=116; -- Rethilgore
UPDATE `creature_template` SET `maxgold`=206 WHERE `entry`=3914 && `maxgold`=156; -- Rethilgore
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=3919 && `mingold`=37; -- Withered Ancient
UPDATE `creature_template` SET `maxgold`=117 WHERE `entry`=3919 && `maxgold`=53; -- Withered Ancient
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3921 && `mingold`=31; -- Thistlefur Ursa (sample size 33)
UPDATE `creature_template` SET `maxgold`=103 WHERE `entry`=3921 && `maxgold`=45; -- Thistlefur Ursa (sample size 33)
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=3922 && `mingold`=29; -- Thistlefur Totemic (sample size 28)
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=3922 && `maxgold`=43; -- Thistlefur Totemic (sample size 28)
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3923 && `mingold`=31; -- Thistlefur Den Watcher
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=3923 && `maxgold`=45; -- Thistlefur Den Watcher
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=3924 && `mingold`=29; -- Thistlefur Shaman (sample size 26)
UPDATE `creature_template` SET `maxgold`=103 WHERE `entry`=3924 && `maxgold`=43; -- Thistlefur Shaman (sample size 26)
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=3925 && `mingold`=31; -- Thistlefur Avenger (sample size 27)
UPDATE `creature_template` SET `maxgold`=103 WHERE `entry`=3925 && `maxgold`=45; -- Thistlefur Avenger (sample size 27)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=3926 && `mingold`=31; -- Thistlefur Pathfinder
UPDATE `creature_template` SET `maxgold`=104 WHERE `entry`=3926 && `maxgold`=45; -- Thistlefur Pathfinder
UPDATE `creature_template` SET `mingold`=114 WHERE `entry`=3927 && `mingold`=222; -- Wolf Master Nandos
UPDATE `creature_template` SET `maxgold`=338 WHERE `entry`=3927 && `maxgold`=295; -- Wolf Master Nandos
UPDATE `creature_template` SET `maxgold`=123 WHERE `entry`=3931 && `maxgold`=62; -- Shadethicket Oracle
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=3932 && `mingold`=39; -- Bloodtooth Guard
UPDATE `creature_template` SET `maxgold`=145 WHERE `entry`=3932 && `maxgold`=56; -- Bloodtooth Guard
UPDATE `creature_template` SET `maxgold`=112 WHERE `entry`=3941 && `maxgold`=64; -- Uthil Mooncall
UPDATE `creature_template` SET `maxgold`=126 WHERE `entry`=3942 && `maxgold`=64; -- Mavoris Cloudsbreak
UPDATE `creature_template` SET `maxgold`=95 WHERE `entry`=3943 && `maxgold`=46; -- Ruuzel
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=3944 && `mingold`=24; -- Wrathtail Priestess
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=3944 && `maxgold`=37; -- Wrathtail Priestess
UPDATE `creature_template` SET `maxgold`=194 WHERE `entry`=3947 && `maxgold`=121; -- Goblin Shipbuilder
UPDATE `creature_template` SET `mingold`=232 WHERE `entry`=3974 && `mingold`=386; -- Houndmaster Loksey
UPDATE `creature_template` SET `maxgold`=729 WHERE `entry`=3974 && `maxgold`=509; -- Houndmaster Loksey
UPDATE `creature_template` SET `mingold`=336 WHERE `entry`=3975 && `mingold`=575; -- Herod
UPDATE `creature_template` SET `mingold`=285 WHERE `entry`=3976 && `mingold`=319; -- Scarlet Commander Mograine
UPDATE `creature_template` SET `maxgold`=773 WHERE `entry`=3977 && `maxgold`=394; -- High Inquisitor Whitemane
UPDATE `creature_template` SET `maxgold`=588 WHERE `entry`=3983 && `maxgold`=372; -- Interrogator Vishas
UPDATE `creature_template` SET `maxgold`=670 WHERE `entry`=3984 && `maxgold`=263; -- Nancy Vishas
UPDATE `creature_template` SET `maxgold`=630 WHERE `entry`=3985 && `maxgold`=271; -- Grandpa Vishas
UPDATE `creature_template` SET `maxgold`=116 WHERE `entry`=3986 && `maxgold`=45; -- Sarilus Foulborne
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=3987 && `mingold`=34; -- Dal Bloodclaw
UPDATE `creature_template` SET `maxgold`=77 WHERE `entry`=3987 && `maxgold`=50; -- Dal Bloodclaw
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=3988 && `mingold`=23; -- Venture Co. Operator (sample size 22)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=3988 && `maxgold`=35; -- Venture Co. Operator (sample size 22)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=3989 && `mingold`=22; -- Venture Co. Logger (sample size 62)
UPDATE `creature_template` SET `maxgold`=59 WHERE `entry`=3989 && `maxgold`=33; -- Venture Co. Logger (sample size 62)
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=3991 && `mingold`=22; -- Venture Co. Deforester (sample size 35)
UPDATE `creature_template` SET `maxgold`=65 WHERE `entry`=3991 && `maxgold`=33; -- Venture Co. Deforester (sample size 35)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=3992 && `mingold`=25; -- Venture Co. Engineer
UPDATE `creature_template` SET `maxgold`=65 WHERE `entry`=3992 && `maxgold`=38; -- Venture Co. Engineer
UPDATE `creature_template` SET `maxgold`=82 WHERE `entry`=3993 && `maxgold`=40; -- Venture Co. Machine Smith
UPDATE `creature_template` SET `maxgold`=66 WHERE `entry`=4003 && `maxgold`=37; -- Windshear Geomancer
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=4016 && `mingold`=31; -- Fey Dragon
UPDATE `creature_template` SET `maxgold`=65 WHERE `entry`=4016 && `maxgold`=45; -- Fey Dragon
UPDATE `creature_template` SET `maxgold`=93 WHERE `entry`=4017 && `maxgold`=50; -- Wily Fey Dragon
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=4020 && `mingold`=29; -- Sap Beast
UPDATE `creature_template` SET `mingold`=23 WHERE `entry`=4021 && `mingold`=33; -- Corrosive Sap Beast
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=4022 && `mingold`=31; -- Bloodfury Harpy (sample size 41)
UPDATE `creature_template` SET `maxgold`=104 WHERE `entry`=4022 && `maxgold`=45; -- Bloodfury Harpy (sample size 41)
UPDATE `creature_template` SET `maxgold`=121 WHERE `entry`=4023 && `maxgold`=51; -- Bloodfury Roguefeather
UPDATE `creature_template` SET `maxgold`=117 WHERE `entry`=4024 && `maxgold`=48; -- Bloodfury Slayer
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=4025 && `mingold`=26; -- Bloodfury Ambusher (sample size 36)
UPDATE `creature_template` SET `maxgold`=103 WHERE `entry`=4025 && `maxgold`=39; -- Bloodfury Ambusher (sample size 36)
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=4026 && `mingold`=31; -- Bloodfury Windcaller (sample size 39)
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=4026 && `maxgold`=45; -- Bloodfury Windcaller (sample size 39)
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=4027 && `mingold`=35; -- Bloodfury Storm Witch
UPDATE `creature_template` SET `maxgold`=115 WHERE `entry`=4027 && `maxgold`=51; -- Bloodfury Storm Witch
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=4028 && `mingold`=34; -- Charred Ancient
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=4028 && `maxgold`=49; -- Charred Ancient
UPDATE `creature_template` SET `maxgold`=116 WHERE `entry`=4029 && `maxgold`=56; -- Blackened Ancient
UPDATE `creature_template` SET `mingold`=91 WHERE `entry`=4050 && `mingold`=125; -- Cenarion Caretaker
UPDATE `creature_template` SET `maxgold`=346 WHERE `entry`=4050 && `maxgold`=168; -- Cenarion Caretaker
UPDATE `creature_template` SET `maxgold`=94 WHERE `entry`=4051 && `maxgold`=43; -- Cenarion Botanist
UPDATE `creature_template` SET `maxgold`=298 WHERE `entry`=4052 && `maxgold`=175; -- Cenarion Druid
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=4053 && `mingold`=30; -- Daughter of Cenarius
UPDATE `creature_template` SET `maxgold`=83 WHERE `entry`=4053 && `maxgold`=44; -- Daughter of Cenarius
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=4054 && `mingold`=33; -- Laughing Sister
UPDATE `creature_template` SET `maxgold`=106 WHERE `entry`=4054 && `maxgold`=48; -- Laughing Sister
UPDATE `creature_template` SET `mingold`=66 WHERE `entry`=4056 && `mingold`=143; -- Mirkfallon Keeper
UPDATE `creature_template` SET `mingold`=26 WHERE `entry`=4057 && `mingold`=33; -- Son of Cenarius
UPDATE `creature_template` SET `maxgold`=72 WHERE `entry`=4057 && `maxgold`=48; -- Son of Cenarius
UPDATE `creature_template` SET `maxgold`=349 WHERE `entry`=4061 && `maxgold`=179; -- Mirkfallon Dryad
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=4062 && `mingold`=46; -- Dark Iron Bombardier
UPDATE `creature_template` SET `maxgold`=180 WHERE `entry`=4062 && `maxgold`=65; -- Dark Iron Bombardier
UPDATE `creature_template` SET `maxgold`=225 WHERE `entry`=4063 && `maxgold`=80; -- Feeboz
UPDATE `creature_template` SET `maxgold`=66 WHERE `entry`=4070 && `maxgold`=38; -- Venture Co. Builder
UPDATE `creature_template` SET `maxgold`=68 WHERE `entry`=4073 && `maxgold`=43; -- XT:4
UPDATE `creature_template` SET `maxgold`=79 WHERE `entry`=4074 && `maxgold`=43; -- XT:9
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=4093 && `mingold`=35; -- Galak Wrangler (sample size 34)
UPDATE `creature_template` SET `maxgold`=117 WHERE `entry`=4093 && `maxgold`=50; -- Galak Wrangler (sample size 34)
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=4094 && `mingold`=32; -- Galak Scout (sample size 31)
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=4094 && `maxgold`=47; -- Galak Scout (sample size 31)
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=4095 && `mingold`=39; -- Galak Mauler
UPDATE `creature_template` SET `maxgold`=143 WHERE `entry`=4095 && `maxgold`=56; -- Galak Mauler
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=4096 && `mingold`=31; -- Galak Windchaser (sample size 36)
UPDATE `creature_template` SET `maxgold`=111 WHERE `entry`=4096 && `maxgold`=45; -- Galak Windchaser (sample size 36)
UPDATE `creature_template` SET `mingold`=20 WHERE `entry`=4097 && `mingold`=32; -- Galak Stormer
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=4097 && `maxgold`=47; -- Galak Stormer
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=4099 && `mingold`=37; -- Galak Marauder
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=4099 && `maxgold`=53; -- Galak Marauder
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=4111 && `mingold`=37; -- Gravelsnout Kobold
UPDATE `creature_template` SET `maxgold`=125 WHERE `entry`=4111 && `maxgold`=53; -- Gravelsnout Kobold
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=4112 && `mingold`=35; -- Gravelsnout Vermin
UPDATE `creature_template` SET `maxgold`=71 WHERE `entry`=4112 && `maxgold`=51; -- Gravelsnout Vermin
UPDATE `creature_template` SET `maxgold`=135 WHERE `entry`=4114 && `maxgold`=57; -- Gravelsnout Forager
UPDATE `creature_template` SET `maxgold`=154 WHERE `entry`=4116 && `maxgold`=55; -- Gravelsnout Surveyor
UPDATE `creature_template` SET `maxgold`=109 WHERE `entry`=4202 && `maxgold`=55; -- Gerenzo Wrenchwhistle
UPDATE `creature_template` SET `maxgold`=259 WHERE `entry`=4260 && `maxgold`=84; -- Venture Co. Shredder
UPDATE `creature_template` SET `mingold`=118 WHERE `entry`=4275 && `mingold`=322; -- Archmage Arugal
UPDATE `creature_template` SET `mingold`=115 WHERE `entry`=4278 && `mingold`=161; -- Commander Springvale
UPDATE `creature_template` SET `maxgold`=271 WHERE `entry`=4278 && `maxgold`=215; -- Commander Springvale
UPDATE `creature_template` SET `mingold`=65 WHERE `entry`=4279 && `mingold`=178; -- Odo the Blindwatcher
UPDATE `creature_template` SET `maxgold`=316 WHERE `entry`=4279 && `maxgold`=237; -- Odo the Blindwatcher
UPDATE `creature_template` SET `maxgold`=499 WHERE `entry`=4280 && `maxgold`=204; -- Scarlet Preserver
UPDATE `creature_template` SET `mingold`=167 WHERE `entry`=4281 && `mingold`=174; -- Scarlet Scout
UPDATE `creature_template` SET `maxgold`=339 WHERE `entry`=4281 && `maxgold`=232; -- Scarlet Scout
UPDATE `creature_template` SET `maxgold`=347 WHERE `entry`=4282 && `maxgold`=199; -- Scarlet Magician
UPDATE `creature_template` SET `mingold`=92 WHERE `entry`=4283 && `mingold`=188; -- Scarlet Sentry
UPDATE `creature_template` SET `maxgold`=528 WHERE `entry`=4283 && `maxgold`=251; -- Scarlet Sentry
UPDATE `creature_template` SET `mingold`=159 WHERE `entry`=4284 && `mingold`=167; -- Scarlet Augur
UPDATE `creature_template` SET `maxgold`=531 WHERE `entry`=4284 && `maxgold`=223; -- Scarlet Augur
UPDATE `creature_template` SET `mingold`=92 WHERE `entry`=4285 && `mingold`=167; -- Scarlet Disciple
UPDATE `creature_template` SET `maxgold`=509 WHERE `entry`=4285 && `maxgold`=223; -- Scarlet Disciple
UPDATE `creature_template` SET `mingold`=223 WHERE `entry`=4286 && `mingold`=227; -- Scarlet Soldier
UPDATE `creature_template` SET `maxgold`=787 WHERE `entry`=4286 && `maxgold`=301; -- Scarlet Soldier
UPDATE `creature_template` SET `mingold`=104 WHERE `entry`=4287 && `mingold`=185; -- Scarlet Gallant (sample size 49)
UPDATE `creature_template` SET `maxgold`=676 WHERE `entry`=4287 && `maxgold`=246; -- Scarlet Gallant (sample size 49)
UPDATE `creature_template` SET `maxgold`=604 WHERE `entry`=4288 && `maxgold`=287; -- Scarlet Beastmaster
UPDATE `creature_template` SET `maxgold`=786 WHERE `entry`=4289 && `maxgold`=242; -- Scarlet Evoker
UPDATE `creature_template` SET `mingold`=143 WHERE `entry`=4290 && `mingold`=232; -- Scarlet Guardsman
UPDATE `creature_template` SET `maxgold`=826 WHERE `entry`=4290 && `maxgold`=308; -- Scarlet Guardsman
UPDATE `creature_template` SET `mingold`=106 WHERE `entry`=4291 && `mingold`=191; -- Scarlet Diviner (sample size 35)
UPDATE `creature_template` SET `maxgold`=689 WHERE `entry`=4291 && `maxgold`=254; -- Scarlet Diviner (sample size 35)
UPDATE `creature_template` SET `mingold`=133 WHERE `entry`=4292 && `mingold`=203; -- Scarlet Protector
UPDATE `creature_template` SET `maxgold`=815 WHERE `entry`=4292 && `maxgold`=270; -- Scarlet Protector
UPDATE `creature_template` SET `maxgold`=504 WHERE `entry`=4293 && `maxgold`=349; -- Scarlet Scryer
UPDATE `creature_template` SET `mingold`=150 WHERE `entry`=4294 && `mingold`=187; -- Scarlet Sorcerer
UPDATE `creature_template` SET `maxgold`=905 WHERE `entry`=4294 && `maxgold`=250; -- Scarlet Sorcerer
UPDATE `creature_template` SET `mingold`=142 WHERE `entry`=4295 && `mingold`=243; -- Scarlet Myrmidon (sample size 48)
UPDATE `creature_template` SET `maxgold`=882 WHERE `entry`=4295 && `maxgold`=322; -- Scarlet Myrmidon (sample size 48)
UPDATE `creature_template` SET `mingold`=139 WHERE `entry`=4296 && `mingold`=185; -- Scarlet Adept
UPDATE `creature_template` SET `maxgold`=668 WHERE `entry`=4296 && `maxgold`=246; -- Scarlet Adept
UPDATE `creature_template` SET `maxgold`=488 WHERE `entry`=4297 && `maxgold`=245; -- Scarlet Conjuror
UPDATE `creature_template` SET `mingold`=206 WHERE `entry`=4298 && `mingold`=243; -- Scarlet Defender (sample size 45)
UPDATE `creature_template` SET `maxgold`=864 WHERE `entry`=4298 && `maxgold`=322; -- Scarlet Defender (sample size 45)
UPDATE `creature_template` SET `mingold`=117 WHERE `entry`=4299 && `mingold`=195; -- Scarlet Chaplain (sample size 43)
UPDATE `creature_template` SET `maxgold`=674 WHERE `entry`=4299 && `maxgold`=260; -- Scarlet Chaplain (sample size 43)
UPDATE `creature_template` SET `mingold`=137 WHERE `entry`=4300 && `mingold`=223; -- Scarlet Wizard (sample size 41)
UPDATE `creature_template` SET `maxgold`=923 WHERE `entry`=4300 && `maxgold`=296; -- Scarlet Wizard (sample size 41)
UPDATE `creature_template` SET `mingold`=151 WHERE `entry`=4301 && `mingold`=253; -- Scarlet Centurion (sample size 63)
UPDATE `creature_template` SET `maxgold`=899 WHERE `entry`=4301 && `maxgold`=335; -- Scarlet Centurion (sample size 63)
UPDATE `creature_template` SET `mingold`=209 WHERE `entry`=4302 && `mingold`=216; -- Scarlet Champion (sample size 27)
UPDATE `creature_template` SET `maxgold`=1008 WHERE `entry`=4302 && `maxgold`=287; -- Scarlet Champion (sample size 27)
UPDATE `creature_template` SET `maxgold`=984 WHERE `entry`=4303 && `maxgold`=298; -- Scarlet Abbot
UPDATE `creature_template` SET `mingold`=81 WHERE `entry`=4306 && `mingold`=184; -- Scarlet Torturer
UPDATE `creature_template` SET `maxgold`=542 WHERE `entry`=4306 && `maxgold`=245; -- Scarlet Torturer
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=4308 && `mingold`=49; -- Unfettered Spirit (sample size 87)
UPDATE `creature_template` SET `maxgold`=196 WHERE `entry`=4308 && `maxgold`=69; -- Unfettered Spirit (sample size 87)
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=4323 && `mingold`=74; -- Searing Hatchling (sample size 71)
UPDATE `creature_template` SET `maxgold`=372 WHERE `entry`=4323 && `maxgold`=102; -- Searing Hatchling (sample size 71)
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=4324 && `mingold`=67; -- Searing Whelp (sample size 63)
UPDATE `creature_template` SET `maxgold`=399 WHERE `entry`=4324 && `maxgold`=92; -- Searing Whelp (sample size 63)
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=4328 && `mingold`=72; -- Firemane Scalebane (sample size 26)
UPDATE `creature_template` SET `maxgold`=426 WHERE `entry`=4328 && `maxgold`=99; -- Firemane Scalebane (sample size 26)
UPDATE `creature_template` SET `mingold`=59 WHERE `entry`=4329 && `mingold`=74; -- Firemane Scout (sample size 42)
UPDATE `creature_template` SET `maxgold`=381 WHERE `entry`=4329 && `maxgold`=102; -- Firemane Scout (sample size 42)
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=4331 && `mingold`=67; -- Firemane Ash Tail (sample size 34)
UPDATE `creature_template` SET `maxgold`=392 WHERE `entry`=4331 && `maxgold`=92; -- Firemane Ash Tail (sample size 34)
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=4334 && `mingold`=72; -- Firemane Flamecaller
UPDATE `creature_template` SET `maxgold`=409 WHERE `entry`=4334 && `maxgold`=99; -- Firemane Flamecaller
UPDATE `creature_template` SET `maxgold`=249 WHERE `entry`=4358 && `maxgold`=145; -- Mirefin Puddlejumper
UPDATE `creature_template` SET `maxgold`=259 WHERE `entry`=4359 && `maxgold`=81; -- Mirefin Murloc
UPDATE `creature_template` SET `mingold`=55 WHERE `entry`=4360 && `mingold`=29; -- Mirefin Warrior (sample size 21)
UPDATE `creature_template` SET `maxgold`=300 WHERE `entry`=4360 && `maxgold`=145; -- Mirefin Warrior (sample size 21)
UPDATE `creature_template` SET `mingold`=44 WHERE `entry`=4361 && `mingold`=62; -- Mirefin Muckdweller (sample size 48)
UPDATE `creature_template` SET `maxgold`=276 WHERE `entry`=4361 && `maxgold`=85; -- Mirefin Muckdweller (sample size 48)
UPDATE `creature_template` SET `mingold`=46 WHERE `entry`=4362 && `mingold`=59; -- Mirefin Coastrunner (sample size 37)
UPDATE `creature_template` SET `maxgold`=266 WHERE `entry`=4362 && `maxgold`=83; -- Mirefin Coastrunner (sample size 37)
UPDATE `creature_template` SET `mingold`=48 WHERE `entry`=4363 && `mingold`=56; -- Mirefin Oracle (sample size 28)
UPDATE `creature_template` SET `maxgold`=302 WHERE `entry`=4363 && `maxgold`=78; -- Mirefin Oracle (sample size 28)
UPDATE `creature_template` SET `maxgold`=2054 WHERE `entry`=4364 && `maxgold`=654; -- Strashaz Warrior
UPDATE `creature_template` SET `maxgold`=2915 WHERE `entry`=4366 && `maxgold`=659; -- Strashaz Serpent Guard
UPDATE `creature_template` SET `maxgold`=2807 WHERE `entry`=4368 && `maxgold`=661; -- Strashaz Myrmidon
UPDATE `creature_template` SET `maxgold`=3087 WHERE `entry`=4370 && `maxgold`=562; -- Strashaz Sorceress
UPDATE `creature_template` SET `maxgold`=2727 WHERE `entry`=4371 && `maxgold`=543; -- Strashaz Siren
UPDATE `creature_template` SET `maxgold`=164 WHERE `entry`=4382 && `maxgold`=81; -- Withervine Creeper
UPDATE `creature_template` SET `maxgold`=190 WHERE `entry`=4386 && `maxgold`=145; -- Withervine Bark Ripper
UPDATE `creature_template` SET `maxgold`=186 WHERE `entry`=4391 && `maxgold`=138; -- Swamp Ooze
UPDATE `creature_template` SET `maxgold`=289 WHERE `entry`=4392 && `maxgold`=217; -- Corrosive Swamp Ooze
UPDATE `creature_template` SET `mingold`=64 WHERE `entry`=4393 && `mingold`=71; -- Acidic Swamp Ooze
UPDATE `creature_template` SET `maxgold`=318 WHERE `entry`=4401 && `maxgold`=91; -- Muckshell Clacker
UPDATE `creature_template` SET `maxgold`=215 WHERE `entry`=4402 && `maxgold`=205; -- Muckshell Snapclaw
UPDATE `creature_template` SET `maxgold`=357 WHERE `entry`=4404 && `maxgold`=95; -- Muckshell Scrabbler
UPDATE `creature_template` SET `maxgold`=375 WHERE `entry`=4405 && `maxgold`=222; -- Muckshell Razorclaw
UPDATE `creature_template` SET `maxgold`=339 WHERE `entry`=4409 && `maxgold`=173; -- Gatekeeper Kordurus
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=4416 && `mingold`=24; -- Defias Strip Miner (sample size 28)
UPDATE `creature_template` SET `maxgold`=56 WHERE `entry`=4416 && `maxgold`=36; -- Defias Strip Miner (sample size 28)
UPDATE `creature_template` SET `mingold`=66 WHERE `entry`=4417 && `mingold`=83; -- Defias Taskmaster
UPDATE `creature_template` SET `maxgold`=171 WHERE `entry`=4417 && `maxgold`=113; -- Defias Taskmaster
UPDATE `creature_template` SET `maxgold`=169 WHERE `entry`=4418 && `maxgold`=108; -- Defias Wizard
UPDATE `creature_template` SET `mingold`=156 WHERE `entry`=4420 && `mingold`=366; -- Overlord Ramtusk
UPDATE `creature_template` SET `mingold`=328 WHERE `entry`=4421 && `mingold`=457; -- Charlga Razorflank
UPDATE `creature_template` SET `mingold`=116 WHERE `entry`=4424 && `mingold`=227; -- Aggem Thorncurse
UPDATE `creature_template` SET `maxgold`=356 WHERE `entry`=4424 && `maxgold`=301; -- Aggem Thorncurse
UPDATE `creature_template` SET `mingold`=226 WHERE `entry`=4428 && `mingold`=227; -- Death Speaker Jargba
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=4435 && `mingold`=136; -- Razorfen Warrior
UPDATE `creature_template` SET `maxgold`=350 WHERE `entry`=4436 && `maxgold`=184; -- Razorfen Quilguard
UPDATE `creature_template` SET `mingold`=112 WHERE `entry`=4437 && `mingold`=133; -- Razorfen Warden
UPDATE `creature_template` SET `maxgold`=459 WHERE `entry`=4438 && `maxgold`=222; -- Razorfen Spearhide
UPDATE `creature_template` SET `maxgold`=284 WHERE `entry`=4440 && `maxgold`=199; -- Razorfen Totemic
UPDATE `creature_template` SET `maxgold`=400 WHERE `entry`=4442 && `maxgold`=205; -- Razorfen Defender
UPDATE `creature_template` SET `maxgold`=159 WHERE `entry`=4458 && `maxgold`=87; -- Murkgill Hunter
UPDATE `creature_template` SET `maxgold`=200 WHERE `entry`=4461 && `maxgold`=87; -- Murkgill Warrior
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=4463 && `mingold`=27; -- Blackrock Summoner
UPDATE `creature_template` SET `maxgold`=82 WHERE `entry`=4463 && `maxgold`=40; -- Blackrock Summoner
UPDATE `creature_template` SET `mingold`=285 WHERE `entry`=4465 && `mingold`=316; -- Vilebranch Warrior
UPDATE `creature_template` SET `maxgold`=1292 WHERE `entry`=4465 && `maxgold`=417; -- Vilebranch Warrior
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=4466 && `mingold`=89; -- Vilebranch Scalper (sample size 72)
UPDATE `creature_template` SET `maxgold`=507 WHERE `entry`=4466 && `maxgold`=121; -- Vilebranch Scalper (sample size 72)
UPDATE `creature_template` SET `mingold`=80 WHERE `entry`=4467 && `mingold`=74; -- Vilebranch Soothsayer (sample size 32)
UPDATE `creature_template` SET `maxgold`=505 WHERE `entry`=4467 && `maxgold`=102; -- Vilebranch Soothsayer (sample size 32)
UPDATE `creature_template` SET `mingold`=165 WHERE `entry`=4468 && `mingold`=340; -- Jade Sludge
UPDATE `creature_template` SET `maxgold`=890 WHERE `entry`=4468 && `maxgold`=449; -- Jade Sludge
UPDATE `creature_template` SET `mingold`=221 WHERE `entry`=4469 && `mingold`=283; -- Emerald Ooze
UPDATE `creature_template` SET `maxgold`=762 WHERE `entry`=4469 && `maxgold`=375; -- Emerald Ooze
UPDATE `creature_template` SET `maxgold`=907 WHERE `entry`=4472 && `maxgold`=153; -- Haunting Vision
UPDATE `creature_template` SET `mingold`=113 WHERE `entry`=4474 && `mingold`=114; -- Rotting Cadaver
UPDATE `creature_template` SET `maxgold`=736 WHERE `entry`=4474 && `maxgold`=154; -- Rotting Cadaver
UPDATE `creature_template` SET `maxgold`=686 WHERE `entry`=4475 && `maxgold`=145; -- Blighted Zombie
UPDATE `creature_template` SET `maxgold`=155 WHERE `entry`=4479 && `maxgold`=71; -- Fardel Dabyrie
UPDATE `creature_template` SET `maxgold`=280 WHERE `entry`=4480 && `maxgold`=160; -- Kenata Dabyrie
UPDATE `creature_template` SET `maxgold`=244 WHERE `entry`=4481 && `maxgold`=75; -- Marcel Dabyrie
UPDATE `creature_template` SET `maxgold`=823 WHERE `entry`=4493 && `maxgold`=169; -- Scarlet Avenger
UPDATE `creature_template` SET `maxgold`=845 WHERE `entry`=4494 && `maxgold`=142; -- Scarlet Spellbinder
UPDATE `creature_template` SET `maxgold`=270 WHERE `entry`=4504 && `maxgold`=145; -- Frostmaw
UPDATE `creature_template` SET `mingold`=67 WHERE `entry`=4505 && `mingold`=78; -- Bloodsail Deckhand (sample size 26)
UPDATE `creature_template` SET `maxgold`=422 WHERE `entry`=4505 && `maxgold`=107; -- Bloodsail Deckhand (sample size 26)
UPDATE `creature_template` SET `mingold`=71 WHERE `entry`=4506 && `mingold`=80; -- Bloodsail Swabby (sample size 22)
UPDATE `creature_template` SET `maxgold`=424 WHERE `entry`=4506 && `maxgold`=110; -- Bloodsail Swabby (sample size 22)
UPDATE `creature_template` SET `maxgold`=378 WHERE `entry`=4515 && `maxgold`=196; -- Death's Head Acolyte
UPDATE `creature_template` SET `mingold`=128 WHERE `entry`=4516 && `mingold`=162; -- Death's Head Adept
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=4517 && `mingold`=130; -- Death's Head Priest
UPDATE `creature_template` SET `maxgold`=298 WHERE `entry`=4517 && `maxgold`=175; -- Death's Head Priest
UPDATE `creature_template` SET `mingold`=150 WHERE `entry`=4518 && `mingold`=157; -- Death's Head Sage
UPDATE `creature_template` SET `maxgold`=424 WHERE `entry`=4518 && `maxgold`=210; -- Death's Head Sage
UPDATE `creature_template` SET `maxgold`=373 WHERE `entry`=4519 && `maxgold`=196; -- Death's Head Seer
UPDATE `creature_template` SET `mingold`=86 WHERE `entry`=4520 && `mingold`=120; -- Razorfen Geomancer
UPDATE `creature_template` SET `maxgold`=228 WHERE `entry`=4520 && `maxgold`=162; -- Razorfen Geomancer
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=4523 && `mingold`=141; -- Razorfen Groundshaker
UPDATE `creature_template` SET `maxgold`=351 WHERE `entry`=4523 && `maxgold`=189; -- Razorfen Groundshaker
UPDATE `creature_template` SET `maxgold`=355 WHERE `entry`=4525 && `maxgold`=217; -- Razorfen Earthbreaker
UPDATE `creature_template` SET `mingold`=117 WHERE `entry`=4530 && `mingold`=137; -- Razorfen Handler
UPDATE `creature_template` SET `maxgold`=314 WHERE `entry`=4531 && `maxgold`=219; -- Razorfen Beast Trainer
UPDATE `creature_template` SET `mingold`=135 WHERE `entry`=4532 && `mingold`=184; -- Razorfen Beastmaster
UPDATE `creature_template` SET `maxgold`=410 WHERE `entry`=4532 && `maxgold`=245; -- Razorfen Beastmaster
UPDATE `creature_template` SET `mingold`=125 WHERE `entry`=4540 && `mingold`=227; -- Scarlet Monk (sample size 63)
UPDATE `creature_template` SET `maxgold`=791 WHERE `entry`=4540 && `maxgold`=301; -- Scarlet Monk (sample size 63)
UPDATE `creature_template` SET `mingold`=96 WHERE `entry`=4541 && `mingold`=153; -- Blood of Agamaggan
UPDATE `creature_template` SET `mingold`=172 WHERE `entry`=4542 && `mingold`=329; -- High Inquisitor Fairbanks
UPDATE `creature_template` SET `maxgold`=497 WHERE `entry`=4542 && `maxgold`=434; -- High Inquisitor Fairbanks
UPDATE `creature_template` SET `mingold`=121 WHERE `entry`=4543 && `mingold`=386; -- Bloodmage Thalnos
UPDATE `creature_template` SET `maxgold`=720 WHERE `entry`=4543 && `maxgold`=509; -- Bloodmage Thalnos
UPDATE `creature_template` SET `mingold`=48 WHERE `entry`=4619 && `mingold`=50; -- Geltharis
UPDATE `creature_template` SET `maxgold`=134 WHERE `entry`=4619 && `maxgold`=70; -- Geltharis
UPDATE `creature_template` SET `mingold`=137 WHERE `entry`=4623 && `mingold`=180; -- Quilguard Champion
UPDATE `creature_template` SET `maxgold`=506 WHERE `entry`=4623 && `maxgold`=240; -- Quilguard Champion
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=4632 && `mingold`=46; -- Kolkar Centaur (sample size 23)
UPDATE `creature_template` SET `maxgold`=163 WHERE `entry`=4632 && `maxgold`=65; -- Kolkar Centaur (sample size 23)
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=4633 && `mingold`=46; -- Kolkar Scout (sample size 21)
UPDATE `creature_template` SET `maxgold`=182 WHERE `entry`=4633 && `maxgold`=65; -- Kolkar Scout (sample size 21)
UPDATE `creature_template` SET `mingold`=45 WHERE `entry`=4634 && `mingold`=49; -- Kolkar Mauler (sample size 21)
UPDATE `creature_template` SET `maxgold`=186 WHERE `entry`=4634 && `maxgold`=69; -- Kolkar Mauler (sample size 21)
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=4635 && `mingold`=44; -- Kolkar Windchaser
UPDATE `creature_template` SET `maxgold`=189 WHERE `entry`=4635 && `maxgold`=63; -- Kolkar Windchaser
UPDATE `creature_template` SET `maxgold`=202 WHERE `entry`=4636 && `maxgold`=70; -- Kolkar Battle Lord
UPDATE `creature_template` SET `maxgold`=174 WHERE `entry`=4637 && `maxgold`=65; -- Kolkar Destroyer
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=4638 && `mingold`=50; -- Magram Scout
UPDATE `creature_template` SET `maxgold`=185 WHERE `entry`=4638 && `maxgold`=70; -- Magram Scout
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=4639 && `mingold`=50; -- Magram Outrunner
UPDATE `creature_template` SET `maxgold`=213 WHERE `entry`=4639 && `maxgold`=70; -- Magram Outrunner
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=4640 && `mingold`=53; -- Magram Wrangler (sample size 23)
UPDATE `creature_template` SET `maxgold`=227 WHERE `entry`=4640 && `maxgold`=74; -- Magram Wrangler (sample size 23)
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=4641 && `mingold`=48; -- Magram Windchaser
UPDATE `creature_template` SET `maxgold`=167 WHERE `entry`=4641 && `maxgold`=68; -- Magram Windchaser
UPDATE `creature_template` SET `mingold`=43 WHERE `entry`=4642 && `mingold`=49; -- Magram Stormer
UPDATE `creature_template` SET `maxgold`=246 WHERE `entry`=4642 && `maxgold`=69; -- Magram Stormer
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=4644 && `mingold`=59; -- Magram Marauder
UPDATE `creature_template` SET `maxgold`=244 WHERE `entry`=4644 && `maxgold`=81; -- Magram Marauder
UPDATE `creature_template` SET `maxgold`=260 WHERE `entry`=4645 && `maxgold`=81; -- Magram Mauler
UPDATE `creature_template` SET `maxgold`=210 WHERE `entry`=4646 && `maxgold`=70; -- Gelkis Outrunner
UPDATE `creature_template` SET `mingold`=31 WHERE `entry`=4647 && `mingold`=50; -- Gelkis Scout
UPDATE `creature_template` SET `maxgold`=213 WHERE `entry`=4647 && `maxgold`=70; -- Gelkis Scout
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=4648 && `mingold`=53; -- Gelkis Stamper
UPDATE `creature_template` SET `maxgold`=213 WHERE `entry`=4648 && `maxgold`=74; -- Gelkis Stamper
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=4649 && `mingold`=48; -- Gelkis Windchaser (sample size 21)
UPDATE `creature_template` SET `maxgold`=230 WHERE `entry`=4649 && `maxgold`=68; -- Gelkis Windchaser (sample size 21)
UPDATE `creature_template` SET `mingold`=58 WHERE `entry`=4651 && `mingold`=47; -- Gelkis Earthcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=238 WHERE `entry`=4651 && `maxgold`=66; -- Gelkis Earthcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=245 WHERE `entry`=4652 && `maxgold`=81; -- Gelkis Mauler
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=4653 && `maxgold`=81; -- Gelkis Marauder
UPDATE `creature_template` SET `mingold`=44 WHERE `entry`=4654 && `mingold`=62; -- Maraudine Scout
UPDATE `creature_template` SET `maxgold`=296 WHERE `entry`=4654 && `maxgold`=86; -- Maraudine Scout
UPDATE `creature_template` SET `maxgold`=157 WHERE `entry`=4655 && `maxgold`=86; -- Maraudine Wrangler
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=4656 && `mingold`=61; -- Maraudine Mauler
UPDATE `creature_template` SET `maxgold`=207 WHERE `entry`=4656 && `maxgold`=85; -- Maraudine Mauler
UPDATE `creature_template` SET `maxgold`=268 WHERE `entry`=4657 && `maxgold`=82; -- Maraudine Windchaser
UPDATE `creature_template` SET `maxgold`=238 WHERE `entry`=4658 && `maxgold`=80; -- Maraudine Stormer
UPDATE `creature_template` SET `maxgold`=291 WHERE `entry`=4659 && `maxgold`=94; -- Maraudine Marauder
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=4663 && `mingold`=40; -- Burning Blade Augur (sample size 21)
UPDATE `creature_template` SET `maxgold`=176 WHERE `entry`=4663 && `maxgold`=58; -- Burning Blade Augur (sample size 21)
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=4664 && `mingold`=46; -- Burning Blade Reaver (sample size 25)
UPDATE `creature_template` SET `maxgold`=176 WHERE `entry`=4664 && `maxgold`=65; -- Burning Blade Reaver (sample size 25)
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=4665 && `mingold`=42; -- Burning Blade Adept (sample size 23)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=4665 && `maxgold`=60; -- Burning Blade Adept (sample size 23)
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=4666 && `mingold`=49; -- Burning Blade Felsworn (sample size 47)
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=4666 && `maxgold`=69; -- Burning Blade Felsworn (sample size 47)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=4667 && `maxgold`=62; -- Burning Blade Shadowmage
UPDATE `creature_template` SET `maxgold`=201 WHERE `entry`=4668 && `maxgold`=76; -- Burning Blade Summoner
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=4670 && `mingold`=49; -- Hatefury Rogue (sample size 23)
UPDATE `creature_template` SET `maxgold`=196 WHERE `entry`=4670 && `maxgold`=69; -- Hatefury Rogue (sample size 23)
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=4671 && `mingold`=49; -- Hatefury Trickster (sample size 35)
UPDATE `creature_template` SET `maxgold`=194 WHERE `entry`=4671 && `maxgold`=69; -- Hatefury Trickster (sample size 35)
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=4672 && `mingold`=49; -- Hatefury Felsworn (sample size 27)
UPDATE `creature_template` SET `maxgold`=193 WHERE `entry`=4672 && `maxgold`=69; -- Hatefury Felsworn (sample size 27)
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=4673 && `mingold`=50; -- Hatefury Betrayer (sample size 32)
UPDATE `creature_template` SET `maxgold`=213 WHERE `entry`=4673 && `maxgold`=70; -- Hatefury Betrayer (sample size 32)
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=4674 && `mingold`=50; -- Hatefury Shadowstalker (sample size 22)
UPDATE `creature_template` SET `maxgold`=201 WHERE `entry`=4674 && `maxgold`=70; -- Hatefury Shadowstalker (sample size 22)
UPDATE `creature_template` SET `maxgold`=211 WHERE `entry`=4675 && `maxgold`=65; -- Hatefury Hellcaller
UPDATE `creature_template` SET `mingold`=47 WHERE `entry`=4677 && `mingold`=62; -- Doomwarder
UPDATE `creature_template` SET `maxgold`=299 WHERE `entry`=4677 && `maxgold`=86; -- Doomwarder
UPDATE `creature_template` SET `maxgold`=267 WHERE `entry`=4679 && `maxgold`=78; -- Nether Maiden
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=4680 && `mingold`=65; -- Doomwarder Captain
UPDATE `creature_template` SET `maxgold`=292 WHERE `entry`=4680 && `maxgold`=90; -- Doomwarder Captain
UPDATE `creature_template` SET `mingold`=59 WHERE `entry`=4682 && `mingold`=61; -- Nether Sister
UPDATE `creature_template` SET `maxgold`=230 WHERE `entry`=4682 && `maxgold`=85; -- Nether Sister
UPDATE `creature_template` SET `maxgold`=335 WHERE `entry`=4684 && `maxgold`=78; -- Nether Sorceress
UPDATE `creature_template` SET `mingold`=93 WHERE `entry`=4686 && `mingold`=249; -- Deepstrider Giant
UPDATE `creature_template` SET `maxgold`=208 WHERE `entry`=4711 && `maxgold`=70; -- Slitherblade Naga (sample size 22)
UPDATE `creature_template` SET `maxgold`=196 WHERE `entry`=4712 && `maxgold`=62; -- Slitherblade Sorceress
UPDATE `creature_template` SET `mingold`=43 WHERE `entry`=4713 && `mingold`=53; -- Slitherblade Warrior
UPDATE `creature_template` SET `maxgold`=229 WHERE `entry`=4713 && `maxgold`=74; -- Slitherblade Warrior
UPDATE `creature_template` SET `mingold`=36 WHERE `entry`=4714 && `mingold`=54; -- Slitherblade Myrmidon (sample size 27)
UPDATE `creature_template` SET `maxgold`=239 WHERE `entry`=4714 && `maxgold`=75; -- Slitherblade Myrmidon (sample size 27)
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=4715 && `mingold`=59; -- Slitherblade Razortail (sample size 33)
UPDATE `creature_template` SET `maxgold`=264 WHERE `entry`=4715 && `maxgold`=81; -- Slitherblade Razortail (sample size 33)
UPDATE `creature_template` SET `mingold`=42 WHERE `entry`=4716 && `mingold`=53; -- Slitherblade Tidehunter
UPDATE `creature_template` SET `maxgold`=257 WHERE `entry`=4716 && `maxgold`=74; -- Slitherblade Tidehunter
UPDATE `creature_template` SET `mingold`=39 WHERE `entry`=4718 && `mingold`=49; -- Slitherblade Oracle
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=4718 && `maxgold`=69; -- Slitherblade Oracle
UPDATE `creature_template` SET `maxgold`=259 WHERE `entry`=4719 && `maxgold`=73; -- Slitherblade Sea Witch (sample size 23)
UPDATE `creature_template` SET `maxgold`=311 WHERE `entry`=4723 && `maxgold`=79; -- Foreman Cozzle
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=4788 && `mingold`=95; -- Fallenroot Satyr
UPDATE `creature_template` SET `maxgold`=203 WHERE `entry`=4788 && `maxgold`=129; -- Fallenroot Satyr
UPDATE `creature_template` SET `mingold`=95 WHERE `entry`=4789 && `mingold`=109; -- Fallenroot Rogue
UPDATE `creature_template` SET `maxgold`=227 WHERE `entry`=4789 && `maxgold`=148; -- Fallenroot Rogue
UPDATE `creature_template` SET `mingold`=48 WHERE `entry`=4798 && `mingold`=108; -- Fallenroot Shadowstalker
UPDATE `creature_template` SET `maxgold`=271 WHERE `entry`=4798 && `maxgold`=146; -- Fallenroot Shadowstalker
UPDATE `creature_template` SET `mingold`=65 WHERE `entry`=4799 && `mingold`=114; -- Fallenroot Hellcaller
UPDATE `creature_template` SET `maxgold`=225 WHERE `entry`=4799 && `maxgold`=154; -- Fallenroot Hellcaller
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=4802 && `mingold`=95; -- Blackfathom Tide Priestess
UPDATE `creature_template` SET `mingold`=55 WHERE `entry`=4803 && `mingold`=101; -- Blackfathom Oracle
UPDATE `creature_template` SET `maxgold`=185 WHERE `entry`=4803 && `maxgold`=136; -- Blackfathom Oracle
UPDATE `creature_template` SET `mingold`=53 WHERE `entry`=4805 && `mingold`=113; -- Blackfathom Sea Witch
UPDATE `creature_template` SET `maxgold`=285 WHERE `entry`=4805 && `maxgold`=152; -- Blackfathom Sea Witch
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=4807 && `mingold`=153; -- Blackfathom Myrmidon
UPDATE `creature_template` SET `maxgold`=259 WHERE `entry`=4807 && `maxgold`=205; -- Blackfathom Myrmidon
UPDATE `creature_template` SET `maxgold`=306 WHERE `entry`=4809 && `maxgold`=160; -- Twilight Acolyte
UPDATE `creature_template` SET `maxgold`=311 WHERE `entry`=4811 && `maxgold`=162; -- Twilight Aquamancer
UPDATE `creature_template` SET `maxgold`=298 WHERE `entry`=4812 && `maxgold`=154; -- Twilight Loreseeker
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=4813 && `mingold`=126; -- Twilight Shadowmage
UPDATE `creature_template` SET `maxgold`=385 WHERE `entry`=4813 && `maxgold`=170; -- Twilight Shadowmage
UPDATE `creature_template` SET `maxgold`=270 WHERE `entry`=4814 && `maxgold`=175; -- Twilight Elementalist
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=4815 && `mingold`=115; -- Murkshallow Snapclaw
UPDATE `creature_template` SET `maxgold`=262 WHERE `entry`=4815 && `maxgold`=155; -- Murkshallow Snapclaw
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=4818 && `mingold`=111; -- Blindlight Murloc
UPDATE `creature_template` SET `maxgold`=262 WHERE `entry`=4818 && `maxgold`=150; -- Blindlight Murloc
UPDATE `creature_template` SET `mingold`=68 WHERE `entry`=4819 && `mingold`=137; -- Blindlight Muckdweller
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=4820 && `mingold`=116; -- Blindlight Oracle
UPDATE `creature_template` SET `maxgold`=290 WHERE `entry`=4820 && `maxgold`=156; -- Blindlight Oracle
UPDATE `creature_template` SET `mingold`=143 WHERE `entry`=4831 && `mingold`=248; -- Lady Sarevess
UPDATE `creature_template` SET `mingold`=43 WHERE `entry`=4834 && `mingold`=59; -- Theramore Infiltrator (sample size 25)
UPDATE `creature_template` SET `maxgold`=241 WHERE `entry`=4834 && `maxgold`=81; -- Theramore Infiltrator (sample size 25)
UPDATE `creature_template` SET `mingold`=142 WHERE `entry`=4844 && `mingold`=180; -- Shadowforge Surveyor (sample size 40)
UPDATE `creature_template` SET `maxgold`=776 WHERE `entry`=4844 && `maxgold`=240; -- Shadowforge Surveyor (sample size 40)
UPDATE `creature_template` SET `mingold`=211 WHERE `entry`=4845 && `mingold`=228; -- Shadowforge Ruffian
UPDATE `creature_template` SET `maxgold`=821 WHERE `entry`=4845 && `maxgold`=303; -- Shadowforge Ruffian
UPDATE `creature_template` SET `mingold`=138 WHERE `entry`=4846 && `mingold`=222; -- Shadowforge Digger (sample size 60)
UPDATE `creature_template` SET `maxgold`=774 WHERE `entry`=4846 && `maxgold`=295; -- Shadowforge Digger (sample size 60)
UPDATE `creature_template` SET `maxgold`=930 WHERE `entry`=4848 && `maxgold`=341; -- Shadowforge Darkcaster
UPDATE `creature_template` SET `maxgold`=867 WHERE `entry`=4850 && `maxgold`=330; -- Stonevault Cave Lurker
UPDATE `creature_template` SET `mingold`=216 WHERE `entry`=4851 && `mingold`=232; -- Stonevault Rockchewer
UPDATE `creature_template` SET `maxgold`=831 WHERE `entry`=4851 && `maxgold`=308; -- Stonevault Rockchewer
UPDATE `creature_template` SET `mingold`=133 WHERE `entry`=4852 && `mingold`=200; -- Stonevault Oracle (sample size 30)
UPDATE `creature_template` SET `maxgold`=887 WHERE `entry`=4852 && `maxgold`=266; -- Stonevault Oracle (sample size 30)
UPDATE `creature_template` SET `maxgold`=911 WHERE `entry`=4853 && `maxgold`=341; -- Stonevault Geomancer
UPDATE `creature_template` SET `maxgold`=1378 WHERE `entry`=4854 && `maxgold`=512; -- Grimlok
UPDATE `creature_template` SET `mingold`=247 WHERE `entry`=4855 && `mingold`=300; -- Stonevault Brawler
UPDATE `creature_template` SET `maxgold`=1195 WHERE `entry`=4855 && `maxgold`=396; -- Stonevault Brawler
UPDATE `creature_template` SET `maxgold`=397 WHERE `entry`=4856 && `maxgold`=303; -- Stonevault Cave Hunter
UPDATE `creature_template` SET `maxgold`=1455 WHERE `entry`=4857 && `maxgold`=425; -- Stone Keeper
UPDATE `creature_template` SET `mingold`=211 WHERE `entry`=4860 && `mingold`=297; -- Stone Steward
UPDATE `creature_template` SET `maxgold`=993 WHERE `entry`=4860 && `maxgold`=393; -- Stone Steward
UPDATE `creature_template` SET `mingold`=155 WHERE `entry`=4872 && `mingold`=249; -- Obsidian Golem
UPDATE `creature_template` SET `maxgold`=92 WHERE `entry`=4969 && `maxgold`=63; -- Old Town Thug
UPDATE `creature_template` SET `maxgold`=278 WHERE `entry`=5044 && `maxgold`=132; -- Theramore Skirmisher
UPDATE `creature_template` SET `maxgold`=255 WHERE `entry`=5046 && `maxgold`=138; -- Lieutenant Caldwell
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=5184 && `mingold`=61; -- Theramore Sentry
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=5184 && `maxgold`=84; -- Theramore Sentry
UPDATE `creature_template` SET `mingold`=337 WHERE `entry`=5228 && `mingold`=349; -- Saturated Ooze
UPDATE `creature_template` SET `maxgold`=1182 WHERE `entry`=5228 && `maxgold`=461; -- Saturated Ooze
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=5229 && `mingold`=71; -- Gordunni Ogre (sample size 23)
UPDATE `creature_template` SET `maxgold`=322 WHERE `entry`=5229 && `maxgold`=98; -- Gordunni Ogre (sample size 23)
UPDATE `creature_template` SET `mingold`=62 WHERE `entry`=5232 && `mingold`=75; -- Gordunni Brute (sample size 33)
UPDATE `creature_template` SET `maxgold`=401 WHERE `entry`=5232 && `maxgold`=103; -- Gordunni Brute (sample size 33)
UPDATE `creature_template` SET `mingold`=71 WHERE `entry`=5234 && `mingold`=78; -- Gordunni Mauler (sample size 31)
UPDATE `creature_template` SET `maxgold`=422 WHERE `entry`=5234 && `maxgold`=107; -- Gordunni Mauler (sample size 31)
UPDATE `creature_template` SET `maxgold`=785 WHERE `entry`=5235 && `maxgold`=423; -- Fungal Ooze
UPDATE `creature_template` SET `mingold`=88 WHERE `entry`=5236 && `mingold`=73; -- Gordunni Shaman (sample size 23)
UPDATE `creature_template` SET `maxgold`=414 WHERE `entry`=5236 && `maxgold`=100; -- Gordunni Shaman (sample size 23)
UPDATE `creature_template` SET `mingold`=60 WHERE `entry`=5237 && `mingold`=66; -- Gordunni Ogre Mage (sample size 27)
UPDATE `creature_template` SET `maxgold`=374 WHERE `entry`=5237 && `maxgold`=91; -- Gordunni Ogre Mage (sample size 27)
UPDATE `creature_template` SET `mingold`=76 WHERE `entry`=5238 && `mingold`=86; -- Gordunni Battlemaster (sample size 28)
UPDATE `creature_template` SET `maxgold`=475 WHERE `entry`=5238 && `maxgold`=118; -- Gordunni Battlemaster (sample size 28)
UPDATE `creature_template` SET `maxgold`=467 WHERE `entry`=5239 && `maxgold`=98; -- Gordunni Mage-Lord
UPDATE `creature_template` SET `mingold`=62 WHERE `entry`=5240 && `mingold`=65; -- Gordunni Warlock (sample size 38)
UPDATE `creature_template` SET `maxgold`=421 WHERE `entry`=5240 && `maxgold`=90; -- Gordunni Warlock (sample size 38)
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=5241 && `maxgold`=121; -- Gordunni Warlord
UPDATE `creature_template` SET `maxgold`=767 WHERE `entry`=5243 && `maxgold`=423; -- Cursed Atal'ai
UPDATE `creature_template` SET `mingold`=60 WHERE `entry`=5249 && `mingold`=71; -- Woodpaw Mongrel (sample size 22)
UPDATE `creature_template` SET `maxgold`=335 WHERE `entry`=5249 && `maxgold`=98; -- Woodpaw Mongrel (sample size 22)
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=5251 && `mingold`=74; -- Woodpaw Trapper (sample size 29)
UPDATE `creature_template` SET `maxgold`=361 WHERE `entry`=5251 && `maxgold`=102; -- Woodpaw Trapper (sample size 29)
UPDATE `creature_template` SET `mingold`=57 WHERE `entry`=5253 && `mingold`=74; -- Woodpaw Brute (sample size 36)
UPDATE `creature_template` SET `maxgold`=381 WHERE `entry`=5253 && `maxgold`=102; -- Woodpaw Brute (sample size 36)
UPDATE `creature_template` SET `mingold`=66 WHERE `entry`=5254 && `mingold`=67; -- Woodpaw Mystic
UPDATE `creature_template` SET `maxgold`=386 WHERE `entry`=5254 && `maxgold`=92; -- Woodpaw Mystic
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=5255 && `mingold`=75; -- Woodpaw Reaver
UPDATE `creature_template` SET `maxgold`=398 WHERE `entry`=5255 && `maxgold`=103; -- Woodpaw Reaver
UPDATE `creature_template` SET `maxgold`=1621 WHERE `entry`=5256 && `maxgold`=468; -- Atal'ai Warrior
UPDATE `creature_template` SET `mingold`=74 WHERE `entry`=5258 && `mingold`=78; -- Woodpaw Alpha
UPDATE `creature_template` SET `maxgold`=376 WHERE `entry`=5258 && `maxgold`=107; -- Woodpaw Alpha
UPDATE `creature_template` SET `mingold`=262 WHERE `entry`=5259 && `mingold`=306; -- Atal'ai Witch Doctor (sample size 28)
UPDATE `creature_template` SET `maxgold`=1779 WHERE `entry`=5259 && `maxgold`=404; -- Atal'ai Witch Doctor (sample size 28)
UPDATE `creature_template` SET `maxgold`=1033 WHERE `entry`=5261 && `maxgold`=423; -- Enthralled Atal'ai
UPDATE `creature_template` SET `maxgold`=1450 WHERE `entry`=5263 && `maxgold`=431; -- Mummified Atal'ai
UPDATE `creature_template` SET `mingold`=259 WHERE `entry`=5267 && `mingold`=351; -- Unliving Atal'ai
UPDATE `creature_template` SET `maxgold`=1466 WHERE `entry`=5267 && `maxgold`=463; -- Unliving Atal'ai
UPDATE `creature_template` SET `maxgold`=1240 WHERE `entry`=5269 && `maxgold`=370; -- Atal'ai Priest
UPDATE `creature_template` SET `maxgold`=1672 WHERE `entry`=5270 && `maxgold`=476; -- Atal'ai Corpse Eater
UPDATE `creature_template` SET `maxgold`=1760 WHERE `entry`=5271 && `maxgold`=423; -- Atal'ai Deathwalker
UPDATE `creature_template` SET `maxgold`=1843 WHERE `entry`=5273 && `maxgold`=423; -- Atal'ai High Priest
UPDATE `creature_template` SET `maxgold`=1824 WHERE `entry`=5277 && `maxgold`=495; -- Nightmare Scalebane
UPDATE `creature_template` SET `mingold`=57 WHERE `entry`=5278 && `mingold`=72; -- Sprite Darter (sample size 92)
UPDATE `creature_template` SET `maxgold`=405 WHERE `entry`=5278 && `maxgold`=99; -- Sprite Darter (sample size 92)
UPDATE `creature_template` SET `maxgold`=1809 WHERE `entry`=5280 && `maxgold`=423; -- Nightmare Wyrmkin
UPDATE `creature_template` SET `mingold`=289 WHERE `entry`=5283 && `mingold`=361; -- Nightmare Wanderer
UPDATE `creature_template` SET `maxgold`=1196 WHERE `entry`=5283 && `maxgold`=476; -- Nightmare Wanderer
UPDATE `creature_template` SET `mingold`=65 WHERE `entry`=5292 && `mingold`=74; -- Feral Scar Yeti (sample size 50)
UPDATE `creature_template` SET `maxgold`=427 WHERE `entry`=5292 && `maxgold`=101; -- Feral Scar Yeti (sample size 50)
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=5293 && `maxgold`=123; -- Hulking Feral Scar
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=5295 && `mingold`=81; -- Enraged Feral Scar (sample size 29)
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=5295 && `maxgold`=111; -- Enraged Feral Scar (sample size 29)
UPDATE `creature_template` SET `mingold`=84 WHERE `entry`=5296 && `mingold`=89; -- Rage Scar Yeti
UPDATE `creature_template` SET `maxgold`=419 WHERE `entry`=5296 && `maxgold`=121; -- Rage Scar Yeti
UPDATE `creature_template` SET `mingold`=107 WHERE `entry`=5297 && `mingold`=95; -- Elder Rage Scar (sample size 22)
UPDATE `creature_template` SET `maxgold`=557 WHERE `entry`=5297 && `maxgold`=129; -- Elder Rage Scar (sample size 22)
UPDATE `creature_template` SET `mingold`=77 WHERE `entry`=5299 && `mingold`=92; -- Ferocious Rage Scar (sample size 32)
UPDATE `creature_template` SET `maxgold`=533 WHERE `entry`=5299 && `maxgold`=125; -- Ferocious Rage Scar (sample size 32)
UPDATE `creature_template` SET `maxgold`=1619 WHERE `entry`=5357 && `maxgold`=324; -- Land Walker
UPDATE `creature_template` SET `maxgold`=1394 WHERE `entry`=5358 && `maxgold`=326; -- Cliff Giant
UPDATE `creature_template` SET `maxgold`=571 WHERE `entry`=5362 && `maxgold`=113; -- Northspring Harpy
UPDATE `creature_template` SET `maxgold`=394 WHERE `entry`=5363 && `maxgold`=113; -- Northspring Roguefeather
UPDATE `creature_template` SET `maxgold`=573 WHERE `entry`=5364 && `maxgold`=116; -- Northspring Slayer
UPDATE `creature_template` SET `mingold`=121 WHERE `entry`=5366 && `mingold`=85; -- Northspring Windcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=603 WHERE `entry`=5366 && `maxgold`=116; -- Northspring Windcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=671 WHERE `entry`=5402 && `maxgold`=534; -- Khan Hratha
UPDATE `creature_template` SET `mingold`=155 WHERE `entry`=5469 && `mingold`=351; -- Dune Smasher
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=5471 && `mingold`=88; -- Dunemaul Ogre
UPDATE `creature_template` SET `maxgold`=442 WHERE `entry`=5471 && `maxgold`=120; -- Dunemaul Ogre
UPDATE `creature_template` SET `mingold`=78 WHERE `entry`=5472 && `mingold`=89; -- Dunemaul Enforcer (sample size 64)
UPDATE `creature_template` SET `maxgold`=502 WHERE `entry`=5472 && `maxgold`=121; -- Dunemaul Enforcer (sample size 64)
UPDATE `creature_template` SET `maxgold`=434 WHERE `entry`=5473 && `maxgold`=108; -- Dunemaul Ogre Mage
UPDATE `creature_template` SET `mingold`=79 WHERE `entry`=5474 && `mingold`=90; -- Dunemaul Brute (sample size 69)
UPDATE `creature_template` SET `maxgold`=540 WHERE `entry`=5474 && `maxgold`=123; -- Dunemaul Brute (sample size 69)
UPDATE `creature_template` SET `maxgold`=515 WHERE `entry`=5475 && `maxgold`=111; -- Dunemaul Warlock
UPDATE `creature_template` SET `maxgold`=202 WHERE `entry`=5477 && `maxgold`=91; -- Noboru the Cudgel
UPDATE `creature_template` SET `mingold`=86 WHERE `entry`=5481 && `mingold`=92; -- Thistleshrub Dew Collector (sample size 67)
UPDATE `creature_template` SET `maxgold`=528 WHERE `entry`=5481 && `maxgold`=125; -- Thistleshrub Dew Collector (sample size 67)
UPDATE `creature_template` SET `mingold`=87 WHERE `entry`=5485 && `mingold`=85; -- Thistleshrub Rootshaper (sample size 54)
UPDATE `creature_template` SET `maxgold`=603 WHERE `entry`=5485 && `maxgold`=116; -- Thistleshrub Rootshaper (sample size 54)
UPDATE `creature_template` SET `mingold`=85 WHERE `entry`=5490 && `mingold`=95; -- Gnarled Thistleshrub (sample size 44)
UPDATE `creature_template` SET `maxgold`=566 WHERE `entry`=5490 && `maxgold`=129; -- Gnarled Thistleshrub (sample size 44)
UPDATE `creature_template` SET `maxgold`=221 WHERE `entry`=5600 && `maxgold`=170; -- Khan Dez'hepah
UPDATE `creature_template` SET `maxgold`=238 WHERE `entry`=5601 && `maxgold`=184; -- Khan Jehn
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=5602 && `mingold`=150; -- Khan Shaka
UPDATE `creature_template` SET `mingold`=61 WHERE `entry`=5615 && `mingold`=78; -- Wastewander Rogue (sample size 42)
UPDATE `creature_template` SET `maxgold`=412 WHERE `entry`=5615 && `maxgold`=107; -- Wastewander Rogue (sample size 42)
UPDATE `creature_template` SET `mingold`=54 WHERE `entry`=5616 && `mingold`=71; -- Wastewander Thief (sample size 49)
UPDATE `creature_template` SET `maxgold`=351 WHERE `entry`=5616 && `maxgold`=98; -- Wastewander Thief (sample size 49)
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=5617 && `mingold`=62; -- Wastewander Shadow Mage (sample size 56)
UPDATE `creature_template` SET `maxgold`=405 WHERE `entry`=5617 && `maxgold`=86; -- Wastewander Shadow Mage (sample size 56)
UPDATE `creature_template` SET `mingold`=60 WHERE `entry`=5618 && `mingold`=74; -- Wastewander Bandit (sample size 59)
UPDATE `creature_template` SET `maxgold`=380 WHERE `entry`=5618 && `maxgold`=102; -- Wastewander Bandit (sample size 59)
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=5622 && `maxgold`=84; -- Ongeku
UPDATE `creature_template` SET `mingold`=80 WHERE `entry`=5623 && `mingold`=83; -- Wastewander Assassin (sample size 30)
UPDATE `creature_template` SET `maxgold`=453 WHERE `entry`=5623 && `maxgold`=114; -- Wastewander Assassin (sample size 30)
UPDATE `creature_template` SET `maxgold`=255 WHERE `entry`=5643 && `maxgold`=74; -- Tyranis Malem
UPDATE `creature_template` SET `maxgold`=970 WHERE `entry`=5645 && `maxgold`=383; -- Sandfury Hideskinner
UPDATE `creature_template` SET `maxgold`=878 WHERE `entry`=5647 && `maxgold`=307; -- Sandfury Firecaller
UPDATE `creature_template` SET `mingold`=221 WHERE `entry`=5648 && `mingold`=236; -- Sandfury Shadowcaster (sample size 50)
UPDATE `creature_template` SET `maxgold`=1282 WHERE `entry`=5648 && `maxgold`=313; -- Sandfury Shadowcaster (sample size 50)
UPDATE `creature_template` SET `mingold`=209 WHERE `entry`=5649 && `mingold`=306; -- Sandfury Blood Drinker (sample size 110)
UPDATE `creature_template` SET `maxgold`=1360 WHERE `entry`=5649 && `maxgold`=404; -- Sandfury Blood Drinker (sample size 110)
UPDATE `creature_template` SET `mingold`=258 WHERE `entry`=5650 && `mingold`=263; -- Sandfury Witch Doctor (sample size 74)
UPDATE `creature_template` SET `maxgold`=1346 WHERE `entry`=5650 && `maxgold`=348; -- Sandfury Witch Doctor (sample size 74)
UPDATE `creature_template` SET `mingold`=672 WHERE `entry`=5709 && `mingold`=1536; -- Shade of Eranikus
UPDATE `creature_template` SET `maxgold`=2430 WHERE `entry`=5709 && `maxgold`=2010; -- Shade of Eranikus
UPDATE `creature_template` SET `maxgold`=1598 WHERE `entry`=5710 && `maxgold`=676; -- Jammal'an the Prophet
UPDATE `creature_template` SET `maxgold`=1745 WHERE `entry`=5711 && `maxgold`=452; -- Ogom the Wretched
UPDATE `creature_template` SET `maxgold`=1994 WHERE `entry`=5712 && `maxgold`=625; -- Zolo
UPDATE `creature_template` SET `maxgold`=1058 WHERE `entry`=5713 && `maxgold`=497; -- Gasher
UPDATE `creature_template` SET `maxgold`=1771 WHERE `entry`=5714 && `maxgold`=497; -- Loro
UPDATE `creature_template` SET `maxgold`=1959 WHERE `entry`=5715 && `maxgold`=583; -- Hukku
UPDATE `creature_template` SET `mingold`=387 WHERE `entry`=5716 && `mingold`=850; -- Zul'Lor
UPDATE `creature_template` SET `maxgold`=1262 WHERE `entry`=5716 && `maxgold`=1115; -- Zul'Lor
UPDATE `creature_template` SET `maxgold`=1628 WHERE `entry`=5717 && `maxgold`=727; -- Mijan
UPDATE `creature_template` SET `maxgold`=1968 WHERE `entry`=5720 && `maxgold`=620; -- Weaver
UPDATE `creature_template` SET `maxgold`=1765 WHERE `entry`=5721 && `maxgold`=643; -- Dreamscythe
UPDATE `creature_template` SET `maxgold`=1475 WHERE `entry`=5722 && `maxgold`=785; -- Hazzas
UPDATE `creature_template` SET `mingold`=255 WHERE `entry`=5760 && `mingold`=261; -- Lord Azrethoc
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=5761 && `mingold`=89; -- Deviate Shambler
UPDATE `creature_template` SET `maxgold`=178 WHERE `entry`=5761 && `maxgold`=121; -- Deviate Shambler
UPDATE `creature_template` SET `maxgold`=354 WHERE `entry`=5771 && `maxgold`=84; -- Jugkar Grim'rod
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=5785 && `mingold`=53; -- Sister Hatelash
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=5787 && `mingold`=13; -- Enforcer Emilgund
UPDATE `creature_template` SET `maxgold`=329 WHERE `entry`=5799 && `maxgold`=247; -- Hannah Bladeleaf
UPDATE `creature_template` SET `mingold`=93 WHERE `entry`=5800 && `mingold`=192; -- Marcus Bel
UPDATE `creature_template` SET `mingold`=49 WHERE `entry`=5824 && `mingold`=72; -- Captain Flat Tusk
UPDATE `creature_template` SET `maxgold`=42 WHERE `entry`=5838 && `maxgold`=31; -- Brokespear
UPDATE `creature_template` SET `mingold`=85 WHERE `entry`=5839 && `mingold`=65; -- Dark Iron Geologist (sample size 32)
UPDATE `creature_template` SET `maxgold`=423 WHERE `entry`=5839 && `maxgold`=90; -- Dark Iron Geologist (sample size 32)
UPDATE `creature_template` SET `mingold`=83 WHERE `entry`=5840 && `mingold`=89; -- Dark Iron Steamsmith (sample size 25)
UPDATE `creature_template` SET `maxgold`=479 WHERE `entry`=5840 && `maxgold`=121; -- Dark Iron Steamsmith (sample size 25)
UPDATE `creature_template` SET `mingold`=101 WHERE `entry`=5843 && `mingold`=91; -- Slave Worker (sample size 24)
UPDATE `creature_template` SET `maxgold`=477 WHERE `entry`=5843 && `maxgold`=123; -- Slave Worker (sample size 24)
UPDATE `creature_template` SET `mingold`=70 WHERE `entry`=5844 && `mingold`=88; -- Dark Iron Slaver (sample size 142)
UPDATE `creature_template` SET `maxgold`=480 WHERE `entry`=5844 && `maxgold`=120; -- Dark Iron Slaver (sample size 142)
UPDATE `creature_template` SET `mingold`=78 WHERE `entry`=5846 && `mingold`=94; -- Dark Iron Taskmaster (sample size 135)
UPDATE `creature_template` SET `maxgold`=536 WHERE `entry`=5846 && `maxgold`=128; -- Dark Iron Taskmaster (sample size 135)
UPDATE `creature_template` SET `maxgold`=67 WHERE `entry`=5847 && `maxgold`=45; -- Heggin Stonewhisker
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=5849 && `mingold`=32; -- Digger Flameforge
UPDATE `creature_template` SET `mingold`=77 WHERE `entry`=5853 && `mingold`=88; -- Tempered War Golem
UPDATE `creature_template` SET `maxgold`=454 WHERE `entry`=5853 && `maxgold`=120; -- Tempered War Golem
UPDATE `creature_template` SET `maxgold`=540 WHERE `entry`=5854 && `maxgold`=125; -- Heavy War Golem (sample size 90)
UPDATE `creature_template` SET `mingold`=235 WHERE `entry`=5860 && `mingold`=289; -- Twilight Dark Shaman (sample size 21)
UPDATE `creature_template` SET `maxgold`=1459 WHERE `entry`=5860 && `maxgold`=383; -- Twilight Dark Shaman (sample size 21)
UPDATE `creature_template` SET `mingold`=271 WHERE `entry`=5861 && `mingold`=351; -- Twilight Fire Guard (sample size 24)
UPDATE `creature_template` SET `maxgold`=1697 WHERE `entry`=5861 && `maxgold`=463; -- Twilight Fire Guard (sample size 24)
UPDATE `creature_template` SET `maxgold`=1738 WHERE `entry`=5862 && `maxgold`=376; -- Twilight Geomancer
UPDATE `creature_template` SET `maxgold`=456 WHERE `entry`=5881 && `maxgold`=112; -- Cursed Sycamore
UPDATE `creature_template` SET `maxgold`=285 WHERE `entry`=5916 && `maxgold`=266; -- Sentinel Amarassan
UPDATE `creature_template` SET `mingold`=46 WHERE `entry`=5932 && `mingold`=161; -- Taskmaster Whipfang
UPDATE `creature_template` SET `maxgold`=433 WHERE `entry`=5974 && `maxgold`=123; -- Dreadmaul Ogre
UPDATE `creature_template` SET `maxgold`=391 WHERE `entry`=5975 && `maxgold`=99; -- Dreadmaul Ogre Mage
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=5976 && `maxgold`=124; -- Dreadmaul Brute
UPDATE `creature_template` SET `maxgold`=666 WHERE `entry`=5977 && `maxgold`=154; -- Dreadmaul Mauler
UPDATE `creature_template` SET `maxgold`=420 WHERE `entry`=5979 && `maxgold`=109; -- Wretched Lost One
UPDATE `creature_template` SET `maxgold`=644 WHERE `entry`=5981 && `maxgold`=305; -- Portal Seeker
UPDATE `creature_template` SET `mingold`=113 WHERE `entry`=6004 && `mingold`=108; -- Shadowsworn Cultist (sample size 32)
UPDATE `creature_template` SET `maxgold`=674 WHERE `entry`=6004 && `maxgold`=146; -- Shadowsworn Cultist (sample size 32)
UPDATE `creature_template` SET `maxgold`=704 WHERE `entry`=6005 && `maxgold`=150; -- Shadowsworn Thug
UPDATE `creature_template` SET `mingold`=117 WHERE `entry`=6006 && `mingold`=96; -- Shadowsworn Adept (sample size 36)
UPDATE `creature_template` SET `maxgold`=706 WHERE `entry`=6006 && `maxgold`=131; -- Shadowsworn Adept (sample size 36)
UPDATE `creature_template` SET `maxgold`=672 WHERE `entry`=6007 && `maxgold`=151; -- Shadowsworn Enforcer
UPDATE `creature_template` SET `maxgold`=614 WHERE `entry`=6008 && `maxgold`=124; -- Shadowsworn Warlock
UPDATE `creature_template` SET `maxgold`=503 WHERE `entry`=6009 && `maxgold`=136; -- Shadowsworn Dreadweaver
UPDATE `creature_template` SET `maxgold`=166 WHERE `entry`=6011 && `maxgold`=158; -- Felguard Sentry
UPDATE `creature_template` SET `maxgold`=43 WHERE `entry`=6020 && `maxgold`=36; -- Slimeshell Makrura
UPDATE `creature_template` SET `maxgold`=354 WHERE `entry`=6035 && `maxgold`=224; -- Razorfen Stalker
UPDATE `creature_template` SET `maxgold`=329 WHERE `entry`=6069 && `maxgold`=145; -- Maraudine Khan Guard
UPDATE `creature_template` SET `mingold`=85 WHERE `entry`=6116 && `mingold`=86; -- Highborne Apparition
UPDATE `creature_template` SET `maxgold`=482 WHERE `entry`=6116 && `maxgold`=118; -- Highborne Apparition
UPDATE `creature_template` SET `maxgold`=477 WHERE `entry`=6117 && `maxgold`=99; -- Highborne Lichling
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=6123 && `mingold`=9; -- Dark Iron Spy
UPDATE `creature_template` SET `mingold`=78 WHERE `entry`=6125 && `mingold`=86; -- Haldarr Satyr
UPDATE `creature_template` SET `maxgold`=411 WHERE `entry`=6125 && `maxgold`=118; -- Haldarr Satyr
UPDATE `creature_template` SET `maxgold`=457 WHERE `entry`=6126 && `maxgold`=120; -- Haldarr Trickster
UPDATE `creature_template` SET `maxgold`=396 WHERE `entry`=6127 && `maxgold`=99; -- Haldarr Felsworn
UPDATE `creature_template` SET `mingold`=101 WHERE `entry`=6132 && `mingold`=121; -- Razorfen Servitor
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=6133 && `mingold`=11; -- Shade of Elura
UPDATE `creature_template` SET `maxgold`=733 WHERE `entry`=6135 && `maxgold`=154; -- Arkkoran Clacker
UPDATE `creature_template` SET `mingold`=110 WHERE `entry`=6136 && `mingold`=114; -- Arkkoran Muckdweller
UPDATE `creature_template` SET `maxgold`=408 WHERE `entry`=6136 && `maxgold`=154; -- Arkkoran Muckdweller
UPDATE `creature_template` SET `maxgold`=729 WHERE `entry`=6137 && `maxgold`=158; -- Arkkoran Pincer
UPDATE `creature_template` SET `maxgold`=765 WHERE `entry`=6138 && `maxgold`=136; -- Arkkoran Oracle
UPDATE `creature_template` SET `maxgold`=1948 WHERE `entry`=6146 && `maxgold`=559; -- Cliff Breaker
UPDATE `creature_template` SET `maxgold`=1922 WHERE `entry`=6147 && `maxgold`=540; -- Cliff Thunderer
UPDATE `creature_template` SET `maxgold`=1788 WHERE `entry`=6148 && `maxgold`=527; -- Cliff Walker
UPDATE `creature_template` SET `mingold`=128 WHERE `entry`=6168 && `mingold`=142; -- Roogug
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=6170 && `mingold`=45; -- Gutspill
UPDATE `creature_template` SET `maxgold`=130 WHERE `entry`=6170 && `maxgold`=64; -- Gutspill
UPDATE `creature_template` SET `maxgold`=43 WHERE `entry`=6180 && `maxgold`=24; -- Defias Raider
UPDATE `creature_template` SET `mingold`=73 WHERE `entry`=6188 && `mingold`=86; -- Timbermaw Shaman
UPDATE `creature_template` SET `maxgold`=273 WHERE `entry`=6188 && `maxgold`=118; -- Timbermaw Shaman
UPDATE `creature_template` SET `maxgold`=464 WHERE `entry`=6190 && `maxgold`=124; -- Spitelash Warrior
UPDATE `creature_template` SET `maxgold`=539 WHERE `entry`=6194 && `maxgold`=113; -- Spitelash Serpent Guard
UPDATE `creature_template` SET `mingold`=122 WHERE `entry`=6195 && `mingold`=91; -- Spitelash Siren (sample size 34)
UPDATE `creature_template` SET `maxgold`=678 WHERE `entry`=6195 && `maxgold`=124; -- Spitelash Siren (sample size 34)
UPDATE `creature_template` SET `mingold`=102 WHERE `entry`=6196 && `mingold`=105; -- Spitelash Myrmidon
UPDATE `creature_template` SET `maxgold`=612 WHERE `entry`=6196 && `maxgold`=143; -- Spitelash Myrmidon
UPDATE `creature_template` SET `maxgold`=682 WHERE `entry`=6198 && `maxgold`=124; -- Blood Elf Surveyor
UPDATE `creature_template` SET `maxgold`=690 WHERE `entry`=6199 && `maxgold`=120; -- Blood Elf Reclaimer
UPDATE `creature_template` SET `mingold`=112 WHERE `entry`=6206 && `mingold`=154; -- Caverndeep Burrower
UPDATE `creature_template` SET `maxgold`=360 WHERE `entry`=6206 && `maxgold`=206; -- Caverndeep Burrower
UPDATE `creature_template` SET `maxgold`=120 WHERE `entry`=6207 && `maxgold`=50; -- Caverndeep Ambusher
UPDATE `creature_template` SET `mingold`=120 WHERE `entry`=6208 && `mingold`=133; -- Caverndeep Invader
UPDATE `creature_template` SET `maxgold`=266 WHERE `entry`=6208 && `maxgold`=179; -- Caverndeep Invader
UPDATE `creature_template` SET `maxgold`=326 WHERE `entry`=6210 && `maxgold`=176; -- Caverndeep Pillager
UPDATE `creature_template` SET `mingold`=68 WHERE `entry`=6211 && `mingold`=153; -- Caverndeep Reaver
UPDATE `creature_template` SET `maxgold`=431 WHERE `entry`=6211 && `maxgold`=205; -- Caverndeep Reaver
UPDATE `creature_template` SET `mingold`=125 WHERE `entry`=6212 && `mingold`=200; -- Dark Iron Agent
UPDATE `creature_template` SET `maxgold`=538 WHERE `entry`=6212 && `maxgold`=266; -- Dark Iron Agent
UPDATE `creature_template` SET `mingold`=105 WHERE `entry`=6213 && `mingold`=114; -- Irradiated Invader
UPDATE `creature_template` SET `maxgold`=340 WHERE `entry`=6213 && `maxgold`=154; -- Irradiated Invader
UPDATE `creature_template` SET `mingold`=29 WHERE `entry`=6218 && `mingold`=153; -- Irradiated Slime
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=6221 && `mingold`=32; -- Addled Leper (sample size 22)
UPDATE `creature_template` SET `maxgold`=113 WHERE `entry`=6221 && `maxgold`=47; -- Addled Leper (sample size 22)
UPDATE `creature_template` SET `mingold`=32 WHERE `entry`=6222 && `mingold`=45; -- Leprous Technician
UPDATE `creature_template` SET `maxgold`=166 WHERE `entry`=6222 && `maxgold`=64; -- Leprous Technician
UPDATE `creature_template` SET `mingold`=119 WHERE `entry`=6223 && `mingold`=164; -- Leprous Defender
UPDATE `creature_template` SET `maxgold`=465 WHERE `entry`=6223 && `maxgold`=219; -- Leprous Defender
UPDATE `creature_template` SET `maxgold`=169 WHERE `entry`=6224 && `maxgold`=61; -- Leprous Machinesmith
UPDATE `creature_template` SET `mingold`=125 WHERE `entry`=6225 && `mingold`=174; -- Mechano-Tank
UPDATE `creature_template` SET `maxgold`=365 WHERE `entry`=6225 && `maxgold`=232; -- Mechano-Tank
UPDATE `creature_template` SET `maxgold`=511 WHERE `entry`=6226 && `maxgold`=217; -- Mechano-Flamewalker
UPDATE `creature_template` SET `mingold`=164 WHERE `entry`=6227 && `mingold`=169; -- Mechano-Frostwalker
UPDATE `creature_template` SET `maxgold`=480 WHERE `entry`=6227 && `maxgold`=225; -- Mechano-Frostwalker
UPDATE `creature_template` SET `mingold`=72 WHERE `entry`=6233 && `mingold`=202; -- Mechanized Sentry
UPDATE `creature_template` SET `maxgold`=444 WHERE `entry`=6233 && `maxgold`=269; -- Mechanized Sentry
UPDATE `creature_template` SET `mingold`=113 WHERE `entry`=6234 && `mingold`=190; -- Mechanized Guardian
UPDATE `creature_template` SET `maxgold`=515 WHERE `entry`=6234 && `maxgold`=253; -- Mechanized Guardian
UPDATE `creature_template` SET `mingold`=231 WHERE `entry`=6243 && `mingold`=232; -- Gelihast
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=6329 && `mingold`=125; -- Irradiated Pillager
UPDATE `creature_template` SET `maxgold`=369 WHERE `entry`=6329 && `maxgold`=168; -- Irradiated Pillager
UPDATE `creature_template` SET `mingold`=116 WHERE `entry`=6350 && `mingold`=117; -- Makrinni Razorclaw
UPDATE `creature_template` SET `mingold`=90 WHERE `entry`=6426 && `mingold`=198; -- Anguished Dead (sample size 29)
UPDATE `creature_template` SET `maxgold`=541 WHERE `entry`=6426 && `maxgold`=264; -- Anguished Dead (sample size 29)
UPDATE `creature_template` SET `mingold`=95 WHERE `entry`=6427 && `mingold`=196; -- Haunting Phantasm (sample size 25)
UPDATE `creature_template` SET `maxgold`=591 WHERE `entry`=6427 && `maxgold`=261; -- Haunting Phantasm (sample size 25)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=6466 && `mingold`=25; -- Gamon
UPDATE `creature_template` SET `mingold`=230 WHERE `entry`=6487 && `mingold`=434; -- Arcanist Doan
UPDATE `creature_template` SET `maxgold`=770 WHERE `entry`=6487 && `maxgold`=572; -- Arcanist Doan
UPDATE `creature_template` SET `maxgold`=453 WHERE `entry`=6488 && `maxgold`=394; -- Fallen Champion
UPDATE `creature_template` SET `mingold`=182 WHERE `entry`=6489 && `mingold`=298; -- Ironspine
UPDATE `creature_template` SET `maxgold`=624 WHERE `entry`=6490 && `maxgold`=314; -- Azshir the Sleepless
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=6494 && `maxgold`=23; -- Tazan
UPDATE `creature_template` SET `mingold`=6 WHERE `entry`=6497 && `mingold`=19; -- Astor Hadren
UPDATE `creature_template` SET `maxgold`=643 WHERE `entry`=6517 && `maxgold`=140; -- Tar Beast (sample size 50)
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=6518 && `mingold`=111; -- Tar Lurker (sample size 56)
UPDATE `creature_template` SET `maxgold`=714 WHERE `entry`=6518 && `maxgold`=150; -- Tar Lurker (sample size 56)
UPDATE `creature_template` SET `mingold`=127 WHERE `entry`=6519 && `mingold`=99; -- Tar Lord (sample size 54)
UPDATE `creature_template` SET `maxgold`=742 WHERE `entry`=6519 && `maxgold`=135; -- Tar Lord (sample size 54)
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=6523 && `mingold`=153; -- Dark Iron Rifleman
UPDATE `creature_template` SET `maxgold`=357 WHERE `entry`=6523 && `maxgold`=205; -- Dark Iron Rifleman
UPDATE `creature_template` SET `mingold`=97 WHERE `entry`=6527 && `mingold`=91; -- Tar Creeper (sample size 55)
UPDATE `creature_template` SET `maxgold`=667 WHERE `entry`=6527 && `maxgold`=124; -- Tar Creeper (sample size 55)
UPDATE `creature_template` SET `mingold`=81 WHERE `entry`=6556 && `mingold`=95; -- Muculent Ooze
UPDATE `creature_template` SET `maxgold`=322 WHERE `entry`=6556 && `maxgold`=129; -- Muculent Ooze
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=6557 && `mingold`=103; -- Primal Ooze (sample size 37)
UPDATE `creature_template` SET `maxgold`=399 WHERE `entry`=6557 && `maxgold`=140; -- Primal Ooze (sample size 37)
UPDATE `creature_template` SET `mingold`=56 WHERE `entry`=6559 && `mingold`=113; -- Glutinous Ooze (sample size 31)
UPDATE `creature_template` SET `maxgold`=247 WHERE `entry`=6559 && `maxgold`=153; -- Glutinous Ooze (sample size 31)
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=6575 && `mingold`=13; -- Scarlet Trainee (sample size 37)
UPDATE `creature_template` SET `maxgold`=30 WHERE `entry`=6575 && `maxgold`=63; -- Scarlet Trainee (sample size 37)
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=6606 && `mingold`=18; -- Overseer Glibby
UPDATE `creature_template` SET `maxgold`=31 WHERE `entry`=6606 && `maxgold`=29; -- Overseer Glibby
UPDATE `creature_template` SET `maxgold`=62 WHERE `entry`=6668 && `maxgold`=43; -- Lord Cyrik Blackforge
UPDATE `creature_template` SET `maxgold`=947 WHERE `entry`=6733 && `maxgold`=348; -- Stonevault Basher
UPDATE `creature_template` SET `mingold`=2 WHERE `entry`=6846 && `mingold`=10; -- Defias Dockmaster
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=6866 && `mingold`=5; -- Defias Bodyguard
UPDATE `creature_template` SET `maxgold`=1116 WHERE `entry`=6906 && `maxgold`=358; -- Baelog
UPDATE `creature_template` SET `mingold`=231 WHERE `entry`=6907 && `mingold`=265; -- Eric "The Swift"
UPDATE `creature_template` SET `maxgold`=676 WHERE `entry`=6907 && `maxgold`=351; -- Eric "The Swift"
UPDATE `creature_template` SET `maxgold`=919 WHERE `entry`=6908 && `maxgold`=390; -- Olaf
UPDATE `creature_template` SET `maxgold`=696 WHERE `entry`=6910 && `maxgold`=301; -- Revelosh
UPDATE `creature_template` SET `maxgold`=304 WHERE `entry`=7011 && `maxgold`=103; -- Earthen Rocksmasher
UPDATE `creature_template` SET `maxgold`=1087 WHERE `entry`=7012 && `maxgold`=89; -- Earthen Sculptor
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=7015 && `maxgold`=29; -- Flagglemurk the Cruel
UPDATE `creature_template` SET `maxgold`=1162 WHERE `entry`=7023 && `maxgold`=549; -- Obsidian Sentinel
UPDATE `creature_template` SET `maxgold`=822 WHERE `entry`=7025 && `maxgold`=165; -- Blackrock Soldier
UPDATE `creature_template` SET `maxgold`=626 WHERE `entry`=7026 && `maxgold`=134; -- Blackrock Sorcerer
UPDATE `creature_template` SET `mingold`=124 WHERE `entry`=7027 && `mingold`=125; -- Blackrock Slayer
UPDATE `creature_template` SET `maxgold`=859 WHERE `entry`=7027 && `maxgold`=169; -- Blackrock Slayer
UPDATE `creature_template` SET `maxgold`=792 WHERE `entry`=7028 && `maxgold`=135; -- Blackrock Warlock
UPDATE `creature_template` SET `maxgold`=996 WHERE `entry`=7030 && `maxgold`=306; -- Shadowforge Geologist
UPDATE `creature_template` SET `mingold`=110 WHERE `entry`=7033 && `mingold`=114; -- Firegut Ogre (sample size 53)
UPDATE `creature_template` SET `maxgold`=636 WHERE `entry`=7033 && `maxgold`=154; -- Firegut Ogre (sample size 53)
UPDATE `creature_template` SET `mingold`=119 WHERE `entry`=7034 && `mingold`=100; -- Firegut Ogre Mage (sample size 33)
UPDATE `creature_template` SET `maxgold`=680 WHERE `entry`=7034 && `maxgold`=135; -- Firegut Ogre Mage (sample size 33)
UPDATE `creature_template` SET `mingold`=115 WHERE `entry`=7035 && `mingold`=118; -- Firegut Brute (sample size 47)
UPDATE `creature_template` SET `maxgold`=705 WHERE `entry`=7035 && `maxgold`=159; -- Firegut Brute (sample size 47)
UPDATE `creature_template` SET `maxgold`=187 WHERE `entry`=7036 && `maxgold`=154; -- Thaurissan Spy
UPDATE `creature_template` SET `maxgold`=209 WHERE `entry`=7037 && `maxgold`=154; -- Thaurissan Firewalker
UPDATE `creature_template` SET `maxgold`=714 WHERE `entry`=7038 && `maxgold`=158; -- Thaurissan Agent
UPDATE `creature_template` SET `maxgold`=2149 WHERE `entry`=7040 && `maxgold`=527; -- Black Dragonspawn
UPDATE `creature_template` SET `maxgold`=2071 WHERE `entry`=7041 && `maxgold`=413; -- Black Wyrmkin
UPDATE `creature_template` SET `maxgold`=1992 WHERE `entry`=7042 && `maxgold`=592; -- Flamescale Dragonspawn
UPDATE `creature_template` SET `maxgold`=1210 WHERE `entry`=7044 && `maxgold`=512; -- Black Drake
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=7047 && `mingold`=93; -- Black Broodling (sample size 26)
UPDATE `creature_template` SET `maxgold`=651 WHERE `entry`=7047 && `maxgold`=127; -- Black Broodling (sample size 26)
UPDATE `creature_template` SET `maxgold`=753 WHERE `entry`=7048 && `maxgold`=126; -- Scalding Broodling
UPDATE `creature_template` SET `mingold`=34 WHERE `entry`=7076 && `mingold`=52; -- Earthen Guardian
UPDATE `creature_template` SET `maxgold`=101 WHERE `entry`=7076 && `maxgold`=72; -- Earthen Guardian
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=7077 && `mingold`=51; -- Earthen Hallshaper
UPDATE `creature_template` SET `mingold`=53 WHERE `entry`=7086 && `mingold`=96; -- Cursed Ooze (sample size 21)
UPDATE `creature_template` SET `maxgold`=295 WHERE `entry`=7086 && `maxgold`=130; -- Cursed Ooze (sample size 21)
UPDATE `creature_template` SET `maxgold`=309 WHERE `entry`=7091 && `maxgold`=110; -- Shadowforge Ambusher
UPDATE `creature_template` SET `mingold`=52 WHERE `entry`=7092 && `mingold`=108; -- Tainted Ooze
UPDATE `creature_template` SET `maxgold`=296 WHERE `entry`=7092 && `maxgold`=146; -- Tainted Ooze
UPDATE `creature_template` SET `maxgold`=423 WHERE `entry`=7093 && `maxgold`=146; -- Vile Ooze
UPDATE `creature_template` SET `mingold`=111 WHERE `entry`=7100 && `mingold`=109; -- Warpwood Moss Flayer (sample size 40)
UPDATE `creature_template` SET `maxgold`=712 WHERE `entry`=7100 && `maxgold`=148; -- Warpwood Moss Flayer (sample size 40)
UPDATE `creature_template` SET `mingold`=127 WHERE `entry`=7101 && `mingold`=112; -- Warpwood Shredder (sample size 23)
UPDATE `creature_template` SET `maxgold`=725 WHERE `entry`=7101 && `maxgold`=151; -- Warpwood Shredder (sample size 23)
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=7106 && `mingold`=103; -- Jadefire Rogue
UPDATE `creature_template` SET `maxgold`=495 WHERE `entry`=7106 && `maxgold`=140; -- Jadefire Rogue
UPDATE `creature_template` SET `mingold`=112 WHERE `entry`=7107 && `mingold`=94; -- Jadefire Trickster (sample size 25)
UPDATE `creature_template` SET `maxgold`=684 WHERE `entry`=7107 && `maxgold`=128; -- Jadefire Trickster (sample size 25)
UPDATE `creature_template` SET `maxgold`=706 WHERE `entry`=7108 && `maxgold`=148; -- Jadefire Betrayer
UPDATE `creature_template` SET `mingold`=105 WHERE `entry`=7109 && `mingold`=91; -- Jadefire Felsworn (sample size 21)
UPDATE `creature_template` SET `maxgold`=630 WHERE `entry`=7109 && `maxgold`=123; -- Jadefire Felsworn (sample size 21)
UPDATE `creature_template` SET `maxgold`=609 WHERE `entry`=7110 && `maxgold`=144; -- Jadefire Shadowstalker
UPDATE `creature_template` SET `maxgold`=718 WHERE `entry`=7111 && `maxgold`=126; -- Jadefire Hellcaller
UPDATE `creature_template` SET `mingold`=102 WHERE `entry`=7112 && `mingold`=85; -- Jaedenar Cultist (sample size 51)
UPDATE `creature_template` SET `maxgold`=664 WHERE `entry`=7112 && `maxgold`=116; -- Jaedenar Cultist (sample size 51)
UPDATE `creature_template` SET `mingold`=130 WHERE `entry`=7113 && `mingold`=101; -- Jaedenar Guardian (sample size 49)
UPDATE `creature_template` SET `maxgold`=639 WHERE `entry`=7113 && `maxgold`=137; -- Jaedenar Guardian (sample size 49)
UPDATE `creature_template` SET `mingold`=104 WHERE `entry`=7114 && `mingold`=107; -- Jaedenar Enforcer (sample size 32)
UPDATE `creature_template` SET `maxgold`=706 WHERE `entry`=7114 && `maxgold`=145; -- Jaedenar Enforcer (sample size 32)
UPDATE `creature_template` SET `mingold`=127 WHERE `entry`=7115 && `mingold`=85; -- Jaedenar Adept (sample size 37)
UPDATE `creature_template` SET `maxgold`=675 WHERE `entry`=7115 && `maxgold`=116; -- Jaedenar Adept (sample size 37)
UPDATE `creature_template` SET `mingold`=168 WHERE `entry`=7118 && `mingold`=99; -- Jaedenar Darkweaver (sample size 40)
UPDATE `creature_template` SET `maxgold`=752 WHERE `entry`=7118 && `maxgold`=135; -- Jaedenar Darkweaver (sample size 40)
UPDATE `creature_template` SET `mingold`=156 WHERE `entry`=7120 && `mingold`=99; -- Jaedenar Warlock (sample size 40)
UPDATE `creature_template` SET `maxgold`=726 WHERE `entry`=7120 && `maxgold`=135; -- Jaedenar Warlock (sample size 40)
UPDATE `creature_template` SET `maxgold`=555 WHERE `entry`=7138 && `maxgold`=150; -- Irontree Wanderer
UPDATE `creature_template` SET `maxgold`=717 WHERE `entry`=7139 && `maxgold`=148; -- Irontree Stomper
UPDATE `creature_template` SET `mingold`=94 WHERE `entry`=7153 && `mingold`=93; -- Deadwood Warrior (sample size 38)
UPDATE `creature_template` SET `maxgold`=573 WHERE `entry`=7153 && `maxgold`=126; -- Deadwood Warrior (sample size 38)
UPDATE `creature_template` SET `mingold`=86 WHERE `entry`=7154 && `mingold`=82; -- Deadwood Gardener (sample size 32)
UPDATE `creature_template` SET `maxgold`=570 WHERE `entry`=7154 && `maxgold`=113; -- Deadwood Gardener (sample size 32)
UPDATE `creature_template` SET `mingold`=90 WHERE `entry`=7155 && `mingold`=96; -- Deadwood Pathfinder (sample size 24)
UPDATE `creature_template` SET `maxgold`=557 WHERE `entry`=7155 && `maxgold`=130; -- Deadwood Pathfinder (sample size 24)
UPDATE `creature_template` SET `mingold`=109 WHERE `entry`=7156 && `mingold`=112; -- Deadwood Den Watcher (sample size 26)
UPDATE `creature_template` SET `maxgold`=679 WHERE `entry`=7156 && `maxgold`=151; -- Deadwood Den Watcher (sample size 26)
UPDATE `creature_template` SET `mingold`=114 WHERE `entry`=7157 && `mingold`=117; -- Deadwood Avenger (sample size 24)
UPDATE `creature_template` SET `maxgold`=754 WHERE `entry`=7157 && `maxgold`=158; -- Deadwood Avenger (sample size 24)
UPDATE `creature_template` SET `mingold`=108 WHERE `entry`=7158 && `mingold`=99; -- Deadwood Shaman (sample size 25)
UPDATE `creature_template` SET `maxgold`=754 WHERE `entry`=7158 && `maxgold`=135; -- Deadwood Shaman (sample size 25)
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=7175 && `mingold`=54; -- Stonevault Ambusher
UPDATE `creature_template` SET `maxgold`=228 WHERE `entry`=7175 && `maxgold`=76; -- Stonevault Ambusher
UPDATE `creature_template` SET `mingold`=249 WHERE `entry`=7206 && `mingold`=454; -- Ancient Stone Keeper
UPDATE `creature_template` SET `maxgold`=904 WHERE `entry`=7206 && `maxgold`=598; -- Ancient Stone Keeper
UPDATE `creature_template` SET `mingold`=379 WHERE `entry`=7228 && `mingold`=703; -- Ironaya
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=7234 && `mingold`=7; -- Ferocitas the Dream Eater
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=7235 && `mingold`=5; -- Gnarlpine Mystic
UPDATE `creature_template` SET `maxgold`=12 WHERE `entry`=7235 && `maxgold`=11; -- Gnarlpine Mystic
UPDATE `creature_template` SET `mingold`=208 WHERE `entry`=7246 && `mingold`=273; -- Sandfury Shadowhunter (sample size 31)
UPDATE `creature_template` SET `maxgold`=1318 WHERE `entry`=7246 && `maxgold`=362; -- Sandfury Shadowhunter (sample size 31)
UPDATE `creature_template` SET `mingold`=225 WHERE `entry`=7247 && `mingold`=273; -- Sandfury Soul Eater
UPDATE `creature_template` SET `maxgold`=1403 WHERE `entry`=7247 && `maxgold`=362; -- Sandfury Soul Eater
UPDATE `creature_template` SET `mingold`=399 WHERE `entry`=7267 && `mingold`=674; -- Chief Ukorz Sandscalp
UPDATE `creature_template` SET `maxgold`=1620 WHERE `entry`=7267 && `maxgold`=885; -- Chief Ukorz Sandscalp
UPDATE `creature_template` SET `mingold`=367 WHERE `entry`=7271 && `mingold`=543; -- Witch Doctor Zum'rah
UPDATE `creature_template` SET `maxgold`=1510 WHERE `entry`=7271 && `maxgold`=714; -- Witch Doctor Zum'rah
UPDATE `creature_template` SET `maxgold`=1191 WHERE `entry`=7274 && `maxgold`=636; -- Sandfury Executioner
UPDATE `creature_template` SET `maxgold`=1320 WHERE `entry`=7275 && `maxgold`=514; -- Shadowpriest Sezz'ziz
UPDATE `creature_template` SET `mingold`=244 WHERE `entry`=7276 && `mingold`=78; -- Zul'Farrak Dead Hero (sample size 23)
UPDATE `creature_template` SET `maxgold`=1362 WHERE `entry`=7276 && `maxgold`=106; -- Zul'Farrak Dead Hero (sample size 23)
UPDATE `creature_template` SET `mingold`=183 WHERE `entry`=7286 && `mingold`=107; -- Zul'Farrak Zombie (sample size 343)
UPDATE `creature_template` SET `maxgold`=1286 WHERE `entry`=7286 && `maxgold`=534; -- Zul'Farrak Zombie (sample size 343)
UPDATE `creature_template` SET `maxgold`=1233 WHERE `entry`=7290 && `maxgold`=396; -- Shadowforge Sharpshooter
UPDATE `creature_template` SET `mingold`=415 WHERE `entry`=7291 && `mingold`=626; -- Galgann Firehammer
UPDATE `creature_template` SET `maxgold`=1324 WHERE `entry`=7291 && `maxgold`=822; -- Galgann Firehammer
UPDATE `creature_template` SET `mingold`=28 WHERE `entry`=7309 && `mingold`=47; -- Earthen Custodian
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=7318 && `mingold`=10; -- Rageclaw
UPDATE `creature_template` SET `mingold`=220 WHERE `entry`=7320 && `mingold`=310; -- Stonevault Mauler
UPDATE `creature_template` SET `maxgold`=1056 WHERE `entry`=7320 && `maxgold`=409; -- Stonevault Mauler
UPDATE `creature_template` SET `maxgold`=687 WHERE `entry`=7321 && `maxgold`=326; -- Stonevault Flameweaver
UPDATE `creature_template` SET `mingold`=105 WHERE `entry`=7327 && `mingold`=216; -- Withered Warrior
UPDATE `creature_template` SET `maxgold`=733 WHERE `entry`=7327 && `maxgold`=287; -- Withered Warrior
UPDATE `creature_template` SET `mingold`=196 WHERE `entry`=7328 && `mingold`=222; -- Withered Reaver
UPDATE `creature_template` SET `maxgold`=761 WHERE `entry`=7328 && `maxgold`=295; -- Withered Reaver
UPDATE `creature_template` SET `mingold`=129 WHERE `entry`=7329 && `mingold`=222; -- Withered Quilguard (sample size 21)
UPDATE `creature_template` SET `maxgold`=779 WHERE `entry`=7329 && `maxgold`=295; -- Withered Quilguard (sample size 21)
UPDATE `creature_template` SET `mingold`=148 WHERE `entry`=7332 && `mingold`=212; -- Withered Spearhide
UPDATE `creature_template` SET `maxgold`=711 WHERE `entry`=7332 && `maxgold`=282; -- Withered Spearhide
UPDATE `creature_template` SET `mingold`=128 WHERE `entry`=7335 && `mingold`=180; -- Death's Head Geomancer
UPDATE `creature_template` SET `maxgold`=762 WHERE `entry`=7335 && `maxgold`=240; -- Death's Head Geomancer
UPDATE `creature_template` SET `mingold`=184 WHERE `entry`=7337 && `mingold`=203; -- Death's Head Necromancer
UPDATE `creature_template` SET `maxgold`=820 WHERE `entry`=7337 && `maxgold`=270; -- Death's Head Necromancer
UPDATE `creature_template` SET `maxgold`=823 WHERE `entry`=7341 && `maxgold`=261; -- Skeletal Frostweaver
UPDATE `creature_template` SET `mingold`=153 WHERE `entry`=7342 && `mingold`=208; -- Skeletal Summoner
UPDATE `creature_template` SET `maxgold`=892 WHERE `entry`=7342 && `maxgold`=276; -- Skeletal Summoner
UPDATE `creature_template` SET `mingold`=63 WHERE `entry`=7344 && `mingold`=65; -- Splinterbone Warrior
UPDATE `creature_template` SET `maxgold`=257 WHERE `entry`=7344 && `maxgold`=89; -- Splinterbone Warrior
UPDATE `creature_template` SET `maxgold`=872 WHERE `entry`=7345 && `maxgold`=348; -- Splinterbone Captain
UPDATE `creature_template` SET `mingold`=58 WHERE `entry`=7346 && `mingold`=65; -- Splinterbone Centurion
UPDATE `creature_template` SET `maxgold`=316 WHERE `entry`=7346 && `maxgold`=90; -- Splinterbone Centurion
UPDATE `creature_template` SET `mingold`=220 WHERE `entry`=7347 && `mingold`=249; -- Boneflayer Ghoul
UPDATE `creature_template` SET `maxgold`=812 WHERE `entry`=7347 && `maxgold`=330; -- Boneflayer Ghoul
UPDATE `creature_template` SET `maxgold`=835 WHERE `entry`=7348 && `maxgold`=316; -- Thorn Eater Ghoul
UPDATE `creature_template` SET `maxgold`=995 WHERE `entry`=7353 && `maxgold`=298; -- Freezing Spirit
UPDATE `creature_template` SET `maxgold`=941 WHERE `entry`=7356 && `maxgold`=401; -- Plaguemaw the Rotting
UPDATE `creature_template` SET `mingold`=328 WHERE `entry`=7357 && `mingold`=416; -- Mordresh Fire Eye
UPDATE `creature_template` SET `maxgold`=832 WHERE `entry`=7357 && `maxgold`=548; -- Mordresh Fire Eye
UPDATE `creature_template` SET `mingold`=340 WHERE `entry`=7358 && `mingold`=496; -- Amnennar the Coldbringer
UPDATE `creature_template` SET `maxgold`=679 WHERE `entry`=7358 && `maxgold`=653; -- Amnennar the Coldbringer
UPDATE `creature_template` SET `maxgold`=626 WHERE `entry`=7361 && `maxgold`=349; -- Grubbis
UPDATE `creature_template` SET `mingold`=187 WHERE `entry`=7370 && `mingold`=195; -- Restless Shade
UPDATE `creature_template` SET `maxgold`=947 WHERE `entry`=7370 && `maxgold`=260; -- Restless Shade
UPDATE `creature_template` SET `maxgold`=422 WHERE `entry`=7396 && `maxgold`=114; -- Earthen Stonebreaker
UPDATE `creature_template` SET `maxgold`=197 WHERE `entry`=7397 && `maxgold`=97; -- Earthen Stonecarver
UPDATE `creature_template` SET `maxgold`=172 WHERE `entry`=7404 && `maxgold`=62; -- Galak Flame Guard
UPDATE `creature_template` SET `maxgold`=2337 WHERE `entry`=7437 && `maxgold`=472; -- Cobalt Mageweaver
UPDATE `creature_template` SET `mingold`=141 WHERE `entry`=7438 && `mingold`=126; -- Winterfall Ursa (sample size 91)
UPDATE `creature_template` SET `maxgold`=907 WHERE `entry`=7438 && `maxgold`=170; -- Winterfall Ursa (sample size 91)
UPDATE `creature_template` SET `mingold`=127 WHERE `entry`=7439 && `mingold`=110; -- Winterfall Shaman (sample size 51)
UPDATE `creature_template` SET `maxgold`=871 WHERE `entry`=7439 && `maxgold`=149; -- Winterfall Shaman (sample size 51)
UPDATE `creature_template` SET `mingold`=121 WHERE `entry`=7440 && `mingold`=122; -- Winterfall Den Watcher (sample size 144)
UPDATE `creature_template` SET `maxgold`=830 WHERE `entry`=7440 && `maxgold`=165; -- Winterfall Den Watcher (sample size 144)
UPDATE `creature_template` SET `mingold`=115 WHERE `entry`=7441 && `mingold`=100; -- Winterfall Totemic (sample size 100)
UPDATE `creature_template` SET `maxgold`=790 WHERE `entry`=7441 && `maxgold`=136; -- Winterfall Totemic (sample size 100)
UPDATE `creature_template` SET `mingold`=118 WHERE `entry`=7442 && `mingold`=112; -- Winterfall Pathfinder (sample size 168)
UPDATE `creature_template` SET `maxgold`=750 WHERE `entry`=7442 && `maxgold`=151; -- Winterfall Pathfinder (sample size 168)
UPDATE `creature_template` SET `mingold`=154 WHERE `entry`=7450 && `mingold`=114; -- Ragged Owlbeast (sample size 29)
UPDATE `creature_template` SET `maxgold`=724 WHERE `entry`=7450 && `maxgold`=154; -- Ragged Owlbeast (sample size 29)
UPDATE `creature_template` SET `mingold`=121 WHERE `entry`=7451 && `mingold`=122; -- Raging Owlbeast (sample size 31)
UPDATE `creature_template` SET `maxgold`=789 WHERE `entry`=7451 && `maxgold`=164; -- Raging Owlbeast (sample size 31)
UPDATE `creature_template` SET `mingold`=145 WHERE `entry`=7452 && `mingold`=125; -- Crazed Owlbeast (sample size 23)
UPDATE `creature_template` SET `maxgold`=829 WHERE `entry`=7452 && `maxgold`=169; -- Crazed Owlbeast (sample size 23)
UPDATE `creature_template` SET `mingold`=135 WHERE `entry`=7453 && `mingold`=111; -- Moontouched Owlbeast (sample size 31)
UPDATE `creature_template` SET `maxgold`=907 WHERE `entry`=7453 && `maxgold`=150; -- Moontouched Owlbeast (sample size 31)
UPDATE `creature_template` SET `maxgold`=823 WHERE `entry`=7454 && `maxgold`=176; -- Berserk Owlbeast
UPDATE `creature_template` SET `mingold`=118 WHERE `entry`=7457 && `mingold`=114; -- Rogue Ice Thistle (sample size 49)
UPDATE `creature_template` SET `maxgold`=729 WHERE `entry`=7457 && `maxgold`=154; -- Rogue Ice Thistle (sample size 49)
UPDATE `creature_template` SET `mingold`=119 WHERE `entry`=7458 && `mingold`=120; -- Ice Thistle Yeti (sample size 118)
UPDATE `creature_template` SET `maxgold`=828 WHERE `entry`=7458 && `maxgold`=162; -- Ice Thistle Yeti (sample size 118)
UPDATE `creature_template` SET `mingold`=132 WHERE `entry`=7459 && `mingold`=125; -- Ice Thistle Matriarch (sample size 46)
UPDATE `creature_template` SET `maxgold`=871 WHERE `entry`=7459 && `maxgold`=169; -- Ice Thistle Matriarch (sample size 46)
UPDATE `creature_template` SET `mingold`=135 WHERE `entry`=7460 && `mingold`=128; -- Ice Thistle Patriarch (sample size 40)
UPDATE `creature_template` SET `maxgold`=827 WHERE `entry`=7460 && `maxgold`=172; -- Ice Thistle Patriarch (sample size 40)
UPDATE `creature_template` SET `maxgold`=2858 WHERE `entry`=7461 && `maxgold`=853; -- Hederine Initiate
UPDATE `creature_template` SET `maxgold`=665 WHERE `entry`=7523 && `maxgold`=139; -- Suffering Highborne
UPDATE `creature_template` SET `maxgold`=821 WHERE `entry`=7524 && `maxgold`=145; -- Anguished Highborne
UPDATE `creature_template` SET `mingold`=88 WHERE `entry`=7584 && `mingold`=92; -- Wandering Forest Walker
UPDATE `creature_template` SET `maxgold`=434 WHERE `entry`=7584 && `maxgold`=125; -- Wandering Forest Walker
UPDATE `creature_template` SET `mingold`=22 WHERE `entry`=7603 && `mingold`=44; -- Leprous Assistant (sample size 41)
UPDATE `creature_template` SET `maxgold`=155 WHERE `entry`=7603 && `maxgold`=63; -- Leprous Assistant (sample size 41)
UPDATE `creature_template` SET `mingold`=400 WHERE `entry`=7604 && `mingold`=839; -- Sergeant Bly
UPDATE `creature_template` SET `maxgold`=1265 WHERE `entry`=7606 && `maxgold`=348; -- Oro Eyegouge
UPDATE `creature_template` SET `mingold`=243 WHERE `entry`=7608 && `mingold`=289; -- Murta Grimgut
UPDATE `creature_template` SET `maxgold`=1084 WHERE `entry`=7608 && `maxgold`=382; -- Murta Grimgut
UPDATE `creature_template` SET `maxgold`=2713 WHERE `entry`=7664 && `maxgold`=838; -- Razelikh the Defiler
UPDATE `creature_template` SET `maxgold`=2777 WHERE `entry`=7665 && `maxgold`=1406; -- Grol the Destroyer
UPDATE `creature_template` SET `mingold`=164 WHERE `entry`=7666 && `mingold`=691; -- Archmage Allistarj
UPDATE `creature_template` SET `mingold`=499 WHERE `entry`=7667 && `mingold`=990; -- Lady Sevine
UPDATE `creature_template` SET `maxgold`=755 WHERE `entry`=7668 && `maxgold`=175; -- Servant of Razelikh
UPDATE `creature_template` SET `maxgold`=693 WHERE `entry`=7669 && `maxgold`=154; -- Servant of Grol
UPDATE `creature_template` SET `maxgold`=719 WHERE `entry`=7670 && `maxgold`=161; -- Servant of Allistarj
UPDATE `creature_template` SET `maxgold`=799 WHERE `entry`=7671 && `maxgold`=168; -- Servant of Sevine
UPDATE `creature_template` SET `mingold`=99 WHERE `entry`=7725 && `mingold`=75; -- Grimtotem Raider (sample size 23)
UPDATE `creature_template` SET `maxgold`=403 WHERE `entry`=7725 && `maxgold`=103; -- Grimtotem Raider (sample size 23)
UPDATE `creature_template` SET `mingold`=73 WHERE `entry`=7726 && `mingold`=66; -- Grimtotem Naturalist (sample size 23)
UPDATE `creature_template` SET `maxgold`=373 WHERE `entry`=7726 && `maxgold`=91; -- Grimtotem Naturalist (sample size 23)
UPDATE `creature_template` SET `mingold`=61 WHERE `entry`=7727 && `mingold`=70; -- Grimtotem Shaman (sample size 21)
UPDATE `creature_template` SET `maxgold`=420 WHERE `entry`=7727 && `maxgold`=96; -- Grimtotem Shaman (sample size 21)
UPDATE `creature_template` SET `maxgold`=1414 WHERE `entry`=7728 && `maxgold`=684; -- Kirith the Damned
UPDATE `creature_template` SET `maxgold`=982 WHERE `entry`=7795 && `maxgold`=336; -- Hydromancer Velratha
UPDATE `creature_template` SET `maxgold`=723 WHERE `entry`=7800 && `maxgold`=587; -- Mekgineer Thermaplugg
UPDATE `creature_template` SET `maxgold`=360 WHERE `entry`=7805 && `maxgold`=222; -- Wastewander Scofflaw
UPDATE `creature_template` SET `maxgold`=374 WHERE `entry`=7808 && `maxgold`=222; -- Marauding Owlbeast
UPDATE `creature_template` SET `maxgold`=498 WHERE `entry`=7809 && `maxgold`=213; -- Vilebranch Ambusher
UPDATE `creature_template` SET `maxgold`=402 WHERE `entry`=7847 && `maxgold`=119; -- Caliph Scorpidsting
UPDATE `creature_template` SET `maxgold`=440 WHERE `entry`=7848 && `maxgold`=213; -- Lurking Feral Scar
UPDATE `creature_template` SET `mingold`=85 WHERE `entry`=7855 && `mingold`=81; -- Southsea Pirate (sample size 26)
UPDATE `creature_template` SET `maxgold`=446 WHERE `entry`=7855 && `maxgold`=111; -- Southsea Pirate (sample size 26)
UPDATE `creature_template` SET `mingold`=65 WHERE `entry`=7856 && `mingold`=81; -- Southsea Freebooter (sample size 30)
UPDATE `creature_template` SET `maxgold`=443 WHERE `entry`=7856 && `maxgold`=111; -- Southsea Freebooter (sample size 30)
UPDATE `creature_template` SET `mingold`=68 WHERE `entry`=7857 && `mingold`=81; -- Southsea Dock Worker (sample size 37)
UPDATE `creature_template` SET `maxgold`=422 WHERE `entry`=7857 && `maxgold`=111; -- Southsea Dock Worker (sample size 37)
UPDATE `creature_template` SET `mingold`=73 WHERE `entry`=7858 && `mingold`=81; -- Southsea Swashbuckler (sample size 44)
UPDATE `creature_template` SET `maxgold`=451 WHERE `entry`=7858 && `maxgold`=111; -- Southsea Swashbuckler (sample size 44)
UPDATE `creature_template` SET `maxgold`=424 WHERE `entry`=7864 && `maxgold`=129; -- Lingering Highborne
UPDATE `creature_template` SET `maxgold`=475 WHERE `entry`=7872 && `maxgold`=224; -- Death's Head Cultist
UPDATE `creature_template` SET `mingold`=205 WHERE `entry`=7873 && `mingold`=206; -- Razorfen Battleguard
UPDATE `creature_template` SET `maxgold`=553 WHERE `entry`=7873 && `maxgold`=274; -- Razorfen Battleguard
UPDATE `creature_template` SET `mingold`=144 WHERE `entry`=7874 && `mingold`=172; -- Razorfen Thornweaver
UPDATE `creature_template` SET `maxgold`=689 WHERE `entry`=7874 && `maxgold`=230; -- Razorfen Thornweaver
UPDATE `creature_template` SET `maxgold`=120 WHERE `entry`=7883 && `maxgold`=115; -- Andre Firebeard
UPDATE `creature_template` SET `maxgold`=386 WHERE `entry`=7885 && `maxgold`=157; -- Spitelash Battlemaster
UPDATE `creature_template` SET `maxgold`=486 WHERE `entry`=7886 && `maxgold`=136; -- Spitelash Enchantress
UPDATE `creature_template` SET `maxgold`=370 WHERE `entry`=7899 && `maxgold`=213; -- Treasure Hunting Pirate
UPDATE `creature_template` SET `maxgold`=312 WHERE `entry`=7901 && `maxgold`=213; -- Treasure Hunting Swashbuckler
UPDATE `creature_template` SET `maxgold`=296 WHERE `entry`=7902 && `maxgold`=222; -- Treasure Hunting Buccaneer
UPDATE `creature_template` SET `maxgold`=2194 WHERE `entry`=7995 && `maxgold`=569; -- Vile Priestess Hexx
UPDATE `creature_template` SET `maxgold`=1948 WHERE `entry`=7996 && `maxgold`=539; -- Qiaga the Keeper
UPDATE `creature_template` SET `maxgold`=318 WHERE `entry`=7997 && `maxgold`=100; -- Captured Sprite Darter
UPDATE `creature_template` SET `maxgold`=1908 WHERE `entry`=8075 && `maxgold`=576; -- Edana Hatetalon
UPDATE `creature_template` SET `maxgold`=1111 WHERE `entry`=8127 && `maxgold`=829; -- Antu'sul
UPDATE `creature_template` SET `maxgold`=385 WHERE `entry`=8203 && `maxgold`=125; -- Kregg Keelhaul
UPDATE `creature_template` SET `maxgold`=237 WHERE `entry`=8212 && `maxgold`=130; -- The Reak
UPDATE `creature_template` SET `maxgold`=495 WHERE `entry`=8214 && `maxgold`=130; -- Jalinde Summerdrake
UPDATE `creature_template` SET `maxgold`=1040 WHERE `entry`=8217 && `maxgold`=649; -- Mith'rethis the Enchanter
UPDATE `creature_template` SET `maxgold`=212 WHERE `entry`=8283 && `maxgold`=134; -- Slave Master Blackheart
UPDATE `creature_template` SET `maxgold`=428 WHERE `entry`=8296 && `maxgold`=107; -- Mojo the Twisted
UPDATE `creature_template` SET `maxgold`=336 WHERE `entry`=8304 && `maxgold`=170; -- Dreadscorn
UPDATE `creature_template` SET `mingold`=82 WHERE `entry`=8318 && `mingold`=91; -- Atal'ai Slave (sample size 32)
UPDATE `creature_template` SET `maxgold`=494 WHERE `entry`=8318 && `maxgold`=124; -- Atal'ai Slave (sample size 32)
UPDATE `creature_template` SET `mingold`=113 WHERE `entry`=8319 && `mingold`=98; -- Nightmare Whelp (sample size 37)
UPDATE `creature_template` SET `maxgold`=604 WHERE `entry`=8319 && `maxgold`=133; -- Nightmare Whelp (sample size 37)
UPDATE `creature_template` SET `maxgold`=384 WHERE `entry`=8337 && `maxgold`=222; -- Dark Iron Steelshifter
UPDATE `creature_template` SET `mingold`=311 WHERE `entry`=8384 && `mingold`=362; -- Deep Lurker
UPDATE `creature_template` SET `maxgold`=1615 WHERE `entry`=8384 && `maxgold`=477; -- Deep Lurker
UPDATE `creature_template` SET `mingold`=407 WHERE `entry`=8400 && `mingold`=765; -- Obsidion
UPDATE `creature_template` SET `maxgold`=632 WHERE `entry`=8408 && `maxgold`=156; -- Warlord Krellian
UPDATE `creature_template` SET `mingold`=261 WHERE `entry`=8419 && `mingold`=318; -- Twilight Idolater
UPDATE `creature_template` SET `maxgold`=1754 WHERE `entry`=8419 && `maxgold`=421; -- Twilight Idolater
UPDATE `creature_template` SET `maxgold`=1219 WHERE `entry`=8497 && `maxgold`=504; -- Nightmare Suppressor
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=8504 && `mingold`=107; -- Dark Iron Sentry
UPDATE `creature_template` SET `maxgold`=640 WHERE `entry`=8504 && `maxgold`=534; -- Dark Iron Sentry
UPDATE `creature_template` SET `maxgold`=268 WHERE `entry`=8518 && `maxgold`=215; -- Rynthariel the Keymaster
UPDATE `creature_template` SET `maxgold`=708 WHERE `entry`=8523 && `maxgold`=154; -- Scourge Soldier
UPDATE `creature_template` SET `maxgold`=751 WHERE `entry`=8524 && `maxgold`=130; -- Cursed Mage
UPDATE `creature_template` SET `maxgold`=821 WHERE `entry`=8525 && `maxgold`=143; -- Scourge Warder
UPDATE `creature_template` SET `maxgold`=441 WHERE `entry`=8527 && `maxgold`=172; -- Scourge Guard
UPDATE `creature_template` SET `maxgold`=558 WHERE `entry`=8528 && `maxgold`=143; -- Dread Weaver
UPDATE `creature_template` SET `maxgold`=998 WHERE `entry`=8529 && `maxgold`=180; -- Scourge Champion
UPDATE `creature_template` SET `mingold`=116 WHERE `entry`=8530 && `mingold`=115; -- Cannibal Ghoul (sample size 29)
UPDATE `creature_template` SET `maxgold`=789 WHERE `entry`=8530 && `maxgold`=155; -- Cannibal Ghoul (sample size 29)
UPDATE `creature_template` SET `maxgold`=754 WHERE `entry`=8531 && `maxgold`=169; -- Gibbering Ghoul
UPDATE `creature_template` SET `maxgold`=835 WHERE `entry`=8532 && `maxgold`=179; -- Diseased Flayer
UPDATE `creature_template` SET `mingold`=131 WHERE `entry`=8539 && `mingold`=128; -- Eyeless Watcher (sample size 24)
UPDATE `creature_template` SET `maxgold`=865 WHERE `entry`=8539 && `maxgold`=172; -- Eyeless Watcher (sample size 24)
UPDATE `creature_template` SET `maxgold`=673 WHERE `entry`=8540 && `maxgold`=157; -- Torn Screamer
UPDATE `creature_template` SET `maxgold`=812 WHERE `entry`=8541 && `maxgold`=165; -- Hate Shrieker
UPDATE `creature_template` SET `mingold`=131 WHERE `entry`=8542 && `mingold`=133; -- Death Singer
UPDATE `creature_template` SET `maxgold`=840 WHERE `entry`=8542 && `maxgold`=178; -- Death Singer
UPDATE `creature_template` SET `mingold`=149 WHERE `entry`=8543 && `mingold`=130; -- Stitched Horror (sample size 25)
UPDATE `creature_template` SET `maxgold`=908 WHERE `entry`=8543 && `maxgold`=175; -- Stitched Horror (sample size 25)
UPDATE `creature_template` SET `maxgold`=567 WHERE `entry`=8545 && `maxgold`=183; -- Abomination
UPDATE `creature_template` SET `mingold`=142 WHERE `entry`=8546 && `mingold`=133; -- Dark Adept (sample size 109)
UPDATE `creature_template` SET `maxgold`=959 WHERE `entry`=8546 && `maxgold`=179; -- Dark Adept (sample size 109)
UPDATE `creature_template` SET `mingold`=145 WHERE `entry`=8550 && `mingold`=111; -- Shadowmage (sample size 118)
UPDATE `creature_template` SET `maxgold`=1005 WHERE `entry`=8550 && `maxgold`=150; -- Shadowmage (sample size 118)
UPDATE `creature_template` SET `maxgold`=927 WHERE `entry`=8561 && `maxgold`=179; -- Mossflayer Shadowhunter
UPDATE `creature_template` SET `maxgold`=890 WHERE `entry`=8562 && `maxgold`=156; -- Mossflayer Cannibal
UPDATE `creature_template` SET `maxgold`=959 WHERE `entry`=8563 && `maxgold`=174; -- Woodsman
UPDATE `creature_template` SET `maxgold`=751 WHERE `entry`=8564 && `maxgold`=180; -- Ranger
UPDATE `creature_template` SET `maxgold`=905 WHERE `entry`=8565 && `maxgold`=170; -- Pathstrider
UPDATE `creature_template` SET `mingold`=80 WHERE `entry`=8566 && `mingold`=94; -- Dark Iron Lookout (sample size 64)
UPDATE `creature_template` SET `maxgold`=537 WHERE `entry`=8566 && `maxgold`=128; -- Dark Iron Lookout (sample size 64)
UPDATE `creature_template` SET `mingold`=259 WHERE `entry`=8567 && `mingold`=575; -- Glutton
UPDATE `creature_template` SET `maxgold`=873 WHERE `entry`=8567 && `maxgold`=756; -- Glutton
UPDATE `creature_template` SET `mingold`=497 WHERE `entry`=8580 && `mingold`=762; -- Atal'alarion
UPDATE `creature_template` SET `maxgold`=1757 WHERE `entry`=8580 && `maxgold`=1000; -- Atal'alarion
UPDATE `creature_template` SET `mingold`=118 WHERE `entry`=8606 && `mingold`=122; -- Living Decay
UPDATE `creature_template` SET `maxgold`=471 WHERE `entry`=8607 && `maxgold`=161; -- Rotting Sludge
UPDATE `creature_template` SET `maxgold`=437 WHERE `entry`=8637 && `maxgold`=111; -- Dark Iron Watchman
UPDATE `creature_template` SET `mingold`=103 WHERE `entry`=8766 && `mingold`=109; -- Forest Ooze
UPDATE `creature_template` SET `maxgold`=646 WHERE `entry`=8766 && `maxgold`=148; -- Forest Ooze
UPDATE `creature_template` SET `mingold`=275 WHERE `entry`=8889 && `mingold`=355; -- Anvilrage Overseer (sample size 40)
UPDATE `creature_template` SET `maxgold`=1667 WHERE `entry`=8889 && `maxgold`=468; -- Anvilrage Overseer (sample size 40)
UPDATE `creature_template` SET `mingold`=274 WHERE `entry`=8890 && `mingold`=365; -- Anvilrage Warden (sample size 68)
UPDATE `creature_template` SET `maxgold`=1820 WHERE `entry`=8890 && `maxgold`=482; -- Anvilrage Warden (sample size 68)
UPDATE `creature_template` SET `mingold`=286 WHERE `entry`=8891 && `mingold`=375; -- Anvilrage Guardsman (sample size 107)
UPDATE `creature_template` SET `maxgold`=1930 WHERE `entry`=8891 && `maxgold`=495; -- Anvilrage Guardsman (sample size 107)
UPDATE `creature_template` SET `mingold`=355 WHERE `entry`=8892 && `mingold`=394; -- Anvilrage Footman (sample size 65)
UPDATE `creature_template` SET `maxgold`=1944 WHERE `entry`=8892 && `maxgold`=519; -- Anvilrage Footman (sample size 65)
UPDATE `creature_template` SET `maxgold`=2049 WHERE `entry`=8893 && `maxgold`=594; -- Anvilrage Soldier
UPDATE `creature_template` SET `mingold`=311 WHERE `entry`=8894 && `mingold`=366; -- Anvilrage Medic
UPDATE `creature_template` SET `maxgold`=2119 WHERE `entry`=8894 && `maxgold`=483; -- Anvilrage Medic
UPDATE `creature_template` SET `maxgold`=1987 WHERE `entry`=8895 && `maxgold`=502; -- Anvilrage Officer
UPDATE `creature_template` SET `mingold`=135 WHERE `entry`=8896 && `mingold`=103; -- Shadowforge Peasant (sample size 40)
UPDATE `creature_template` SET `maxgold`=698 WHERE `entry`=8896 && `maxgold`=139; -- Shadowforge Peasant (sample size 40)
UPDATE `creature_template` SET `mingold`=108 WHERE `entry`=8897 && `mingold`=113; -- Doomforge Craftsman (sample size 40)
UPDATE `creature_template` SET `maxgold`=694 WHERE `entry`=8897 && `maxgold`=153; -- Doomforge Craftsman (sample size 40)
UPDATE `creature_template` SET `maxgold`=2149 WHERE `entry`=8898 && `maxgold`=476; -- Anvilrage Marshal
UPDATE `creature_template` SET `mingold`=339 WHERE `entry`=8899 && `mingold`=420; -- Doomforge Dragoon (sample size 26)
UPDATE `creature_template` SET `maxgold`=2373 WHERE `entry`=8899 && `maxgold`=554; -- Doomforge Dragoon (sample size 26)
UPDATE `creature_template` SET `maxgold`=611 WHERE `entry`=8900 && `maxgold`=130; -- Doomforge Arcanasmith
UPDATE `creature_template` SET `maxgold`=702 WHERE `entry`=8902 && `maxgold`=125; -- Shadowforge Citizen
UPDATE `creature_template` SET `maxgold`=1606 WHERE `entry`=8903 && `maxgold`=578; -- Anvilrage Captain
UPDATE `creature_template` SET `maxgold`=797 WHERE `entry`=8904 && `maxgold`=140; -- Shadowforge Senator
UPDATE `creature_template` SET `maxgold`=2225 WHERE `entry`=8905 && `maxgold`=540; -- Warbringer Construct
UPDATE `creature_template` SET `maxgold`=2104 WHERE `entry`=8906 && `maxgold`=565; -- Ragereaver Golem
UPDATE `creature_template` SET `maxgold`=2436 WHERE `entry`=8907 && `maxgold`=573; -- Wrath Hammer Construct
UPDATE `creature_template` SET `maxgold`=1223 WHERE `entry`=8908 && `maxgold`=789; -- Molten War Golem
UPDATE `creature_template` SET `mingold`=299 WHERE `entry`=8912 && `mingold`=324; -- Twilight's Hammer Torturer (sample size 25)
UPDATE `creature_template` SET `maxgold`=1890 WHERE `entry`=8912 && `maxgold`=428; -- Twilight's Hammer Torturer (sample size 25)
UPDATE `creature_template` SET `mingold`=109 WHERE `entry`=8913 && `mingold`=311; -- Twilight Emissary
UPDATE `creature_template` SET `maxgold`=666 WHERE `entry`=8913 && `maxgold`=411; -- Twilight Emissary
UPDATE `creature_template` SET `maxgold`=1894 WHERE `entry`=8914 && `maxgold`=463; -- Twilight Bodyguard
UPDATE `creature_template` SET `maxgold`=324 WHERE `entry`=8915 && `maxgold`=139; -- Twilight's Hammer Ambassador
UPDATE `creature_template` SET `maxgold`=642 WHERE `entry`=8916 && `maxgold`=150; -- Arena Spectator
UPDATE `creature_template` SET `mingold`=115 WHERE `entry`=8920 && `mingold`=102; -- Weapon Technician (sample size 41)
UPDATE `creature_template` SET `maxgold`=754 WHERE `entry`=8920 && `maxgold`=139; -- Weapon Technician (sample size 41)
UPDATE `creature_template` SET `maxgold`=2561 WHERE `entry`=8923 && `maxgold`=737; -- Panzor the Invincible
UPDATE `creature_template` SET `maxgold`=935 WHERE `entry`=8983 && `maxgold`=849; -- Golem Lord Argelmach
UPDATE `creature_template` SET `maxgold`=1649 WHERE `entry`=9018 && `maxgold`=644; -- High Interrogator Gerstahn
UPDATE `creature_template` SET `maxgold`=945 WHERE `entry`=9024 && `maxgold`=865; -- Pyromancer Loregrain
UPDATE `creature_template` SET `maxgold`=1784 WHERE `entry`=9027 && `maxgold`=737; -- Gorosh the Dervish
UPDATE `creature_template` SET `maxgold`=2301 WHERE `entry`=9028 && `maxgold`=713; -- Grizzle
UPDATE `creature_template` SET `maxgold`=1352 WHERE `entry`=9033 && `maxgold`=1349; -- General Angerforge
UPDATE `creature_template` SET `maxgold`=2306 WHERE `entry`=9045 && `maxgold`=487; -- Scarshield Acolyte
UPDATE `creature_template` SET `mingold`=376 WHERE `entry`=9056 && `mingold`=1279; -- Fineous Darkvire
UPDATE `creature_template` SET `mingold`=497 WHERE `entry`=9096 && `mingold`=691; -- Rage Talon Dragonspawn (sample size 21)
UPDATE `creature_template` SET `maxgold`=2819 WHERE `entry`=9096 && `maxgold`=907; -- Rage Talon Dragonspawn (sample size 21)
UPDATE `creature_template` SET `mingold`=402 WHERE `entry`=9097 && `mingold`=425; -- Scarshield Legionnaire (sample size 65)
UPDATE `creature_template` SET `maxgold`=2367 WHERE `entry`=9097 && `maxgold`=559; -- Scarshield Legionnaire (sample size 65)
UPDATE `creature_template` SET `maxgold`=2313 WHERE `entry`=9098 && `maxgold`=476; -- Scarshield Spellbinder
UPDATE `creature_template` SET `maxgold`=2000 WHERE `entry`=9156 && `maxgold`=1682; -- Ambassador Flamelash
UPDATE `creature_template` SET `maxgold`=620 WHERE `entry`=9176 && `maxgold`=153; -- Gor'tesh
UPDATE `creature_template` SET `mingold`=920 WHERE `entry`=9196 && `mingold`=1117; -- Highlord Omokk
UPDATE `creature_template` SET `maxgold`=2139 WHERE `entry`=9196 && `maxgold`=1464; -- Highlord Omokk
UPDATE `creature_template` SET `maxgold`=2274 WHERE `entry`=9197 && `maxgold`=738; -- Spirestone Battle Mage
UPDATE `creature_template` SET `mingold`=394 WHERE `entry`=9199 && `mingold`=641; -- Spirestone Enforcer
UPDATE `creature_template` SET `maxgold`=2303 WHERE `entry`=9199 && `maxgold`=842; -- Spirestone Enforcer
UPDATE `creature_template` SET `mingold`=388 WHERE `entry`=9200 && `mingold`=643; -- Spirestone Reaver
UPDATE `creature_template` SET `maxgold`=2391 WHERE `entry`=9200 && `maxgold`=845; -- Spirestone Reaver
UPDATE `creature_template` SET `maxgold`=1687 WHERE `entry`=9201 && `maxgold`=681; -- Spirestone Ogre Magus
UPDATE `creature_template` SET `maxgold`=2376 WHERE `entry`=9216 && `maxgold`=905; -- Spirestone Warlord
UPDATE `creature_template` SET `maxgold`=2245 WHERE `entry`=9219 && `maxgold`=1606; -- Spirestone Butcher
UPDATE `creature_template` SET `maxgold`=2172 WHERE `entry`=9236 && `maxgold`=1295; -- Shadow Hunter Vosh'gajin
UPDATE `creature_template` SET `maxgold`=2212 WHERE `entry`=9237 && `maxgold`=1741; -- War Master Voone
UPDATE `creature_template` SET `maxgold`=2470 WHERE `entry`=9239 && `maxgold`=495; -- Smolderthorn Mystic
UPDATE `creature_template` SET `mingold`=427 WHERE `entry`=9240 && `mingold`=371; -- Smolderthorn Shadow Priest (sample size 26)
UPDATE `creature_template` SET `maxgold`=2460 WHERE `entry`=9240 && `maxgold`=489; -- Smolderthorn Shadow Priest (sample size 26)
UPDATE `creature_template` SET `maxgold`=2378 WHERE `entry`=9241 && `maxgold`=603; -- Smolderthorn Headhunter
UPDATE `creature_template` SET `maxgold`=2228 WHERE `entry`=9257 && `maxgold`=487; -- Scarshield Warlock
UPDATE `creature_template` SET `mingold`=419 WHERE `entry`=9258 && `mingold`=439; -- Scarshield Raider
UPDATE `creature_template` SET `maxgold`=2288 WHERE `entry`=9258 && `maxgold`=578; -- Scarshield Raider
UPDATE `creature_template` SET `mingold`=474 WHERE `entry`=9259 && `mingold`=449; -- Firebrand Grunt (sample size 24)
UPDATE `creature_template` SET `maxgold`=2573 WHERE `entry`=9259 && `maxgold`=592; -- Firebrand Grunt (sample size 24)
UPDATE `creature_template` SET `maxgold`=2655 WHERE `entry`=9260 && `maxgold`=610; -- Firebrand Legionnaire
UPDATE `creature_template` SET `maxgold`=2553 WHERE `entry`=9261 && `maxgold`=514; -- Firebrand Darkweaver
UPDATE `creature_template` SET `maxgold`=2574 WHERE `entry`=9262 && `maxgold`=508; -- Firebrand Invoker
UPDATE `creature_template` SET `maxgold`=2694 WHERE `entry`=9263 && `maxgold`=527; -- Firebrand Dreadweaver
UPDATE `creature_template` SET `maxgold`=2532 WHERE `entry`=9264 && `maxgold`=522; -- Firebrand Pyromancer
UPDATE `creature_template` SET `maxgold`=2242 WHERE `entry`=9265 && `maxgold`=508; -- Smolderthorn Shadow Hunter
UPDATE `creature_template` SET `maxgold`=2611 WHERE `entry`=9266 && `maxgold`=503; -- Smolderthorn Witch Doctor
UPDATE `creature_template` SET `mingold`=379 WHERE `entry`=9267 && `mingold`=443; -- Smolderthorn Axe Thrower (sample size 29)
UPDATE `creature_template` SET `maxgold`=2466 WHERE `entry`=9267 && `maxgold`=584; -- Smolderthorn Axe Thrower (sample size 29)
UPDATE `creature_template` SET `maxgold`=2533 WHERE `entry`=9268 && `maxgold`=610; -- Smolderthorn Berserker
UPDATE `creature_template` SET `maxgold`=2594 WHERE `entry`=9269 && `maxgold`=508; -- Smolderthorn Seer
UPDATE `creature_template` SET `maxgold`=1388 WHERE `entry`=9445 && `maxgold`=737; -- Dark Guard
UPDATE `creature_template` SET `maxgold`=593 WHERE `entry`=9454 && `maxgold`=155; -- Xavathras
UPDATE `creature_template` SET `mingold`=16 WHERE `entry`=9456 && `mingold`=17; -- Warlord Krom'zar
UPDATE `creature_template` SET `maxgold`=309 WHERE `entry`=9462 && `maxgold`=166; -- Chieftain Bloodmaw
UPDATE `creature_template` SET `maxgold`=364 WHERE `entry`=9464 && `maxgold`=138; -- Overlord Ror
UPDATE `creature_template` SET `maxgold`=1133 WHERE `entry`=9476 && `maxgold`=761; -- Watchman Doomgrip
UPDATE `creature_template` SET `maxgold`=1955 WHERE `entry`=9502 && `maxgold`=1122; -- Phalanx
UPDATE `creature_template` SET `maxgold`=905 WHERE `entry`=9517 && `maxgold`=136; -- Shadow Lord Fel'dan
UPDATE `creature_template` SET `maxgold`=852 WHERE `entry`=9518 && `maxgold`=155; -- Rakaiah
UPDATE `creature_template` SET `maxgold`=27 WHERE `entry`=9523 && `maxgold`=23; -- Kolkar Stormseer
UPDATE `creature_template` SET `mingold`=14 WHERE `entry`=9524 && `mingold`=5; -- Kolkar Invader (sample size 29)
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=9524 && `maxgold`=23; -- Kolkar Invader (sample size 29)
UPDATE `creature_template` SET `maxgold`=2123 WHERE `entry`=9537 && `maxgold`=737; -- Hurley Blackbreath
UPDATE `creature_template` SET `maxgold`=1575 WHERE `entry`=9541 && `maxgold`=737; -- Blackbreath Crony
UPDATE `creature_template` SET `mingold`=240 WHERE `entry`=9543 && `mingold`=406; -- Ribbly Screwspigot
UPDATE `creature_template` SET `maxgold`=572 WHERE `entry`=9545 && `maxgold`=126; -- Grim Patron
UPDATE `creature_template` SET `maxgold`=530 WHERE `entry`=9547 && `maxgold`=107; -- Guzzling Patron
UPDATE `creature_template` SET `mingold`=377 WHERE `entry`=9554 && `mingold`=389; -- Hammered Patron
UPDATE `creature_template` SET `maxgold`=924 WHERE `entry`=9554 && `maxgold`=513; -- Hammered Patron
UPDATE `creature_template` SET `mingold`=1124 WHERE `entry`=9568 && `mingold`=1502; -- Overlord Wyrmthalak
UPDATE `creature_template` SET `mingold`=620 WHERE `entry`=9583 && `mingold`=474; -- Bloodaxe Veteran (sample size 24)
UPDATE `creature_template` SET `maxgold`=2692 WHERE `entry`=9583 && `maxgold`=624; -- Bloodaxe Veteran (sample size 24)
UPDATE `creature_template` SET `maxgold`=2688 WHERE `entry`=9596 && `maxgold`=955; -- Bannok Grimaxe
UPDATE `creature_template` SET `maxgold`=1460 WHERE `entry`=9680 && `maxgold`=681; -- Crest Killer
UPDATE `creature_template` SET `maxgold`=1732 WHERE `entry`=9692 && `maxgold`=610; -- Bloodaxe Raider
UPDATE `creature_template` SET `maxgold`=2640 WHERE `entry`=9693 && `maxgold`=546; -- Bloodaxe Evoker
UPDATE `creature_template` SET `maxgold`=2526 WHERE `entry`=9716 && `maxgold`=616; -- Bloodaxe Warmonger
UPDATE `creature_template` SET `maxgold`=2104 WHERE `entry`=9717 && `maxgold`=510; -- Bloodaxe Summoner
UPDATE `creature_template` SET `mingold`=737 WHERE `entry`=9736 && `mingold`=1677; -- Quartermaster Zigris
UPDATE `creature_template` SET `maxgold`=376 WHERE `entry`=9776 && `maxgold`=102; -- Flamekin Spitter
UPDATE `creature_template` SET `maxgold`=567 WHERE `entry`=9777 && `maxgold`=88; -- Flamekin Sprite
UPDATE `creature_template` SET `maxgold`=2911 WHERE `entry`=9817 && `maxgold`=548; -- Blackhand Dreadweaver
UPDATE `creature_template` SET `maxgold`=2937 WHERE `entry`=9818 && `maxgold`=543; -- Blackhand Summoner
UPDATE `creature_template` SET `maxgold`=3001 WHERE `entry`=9819 && `maxgold`=631; -- Blackhand Veteran
UPDATE `creature_template` SET `maxgold`=565 WHERE `entry`=9860 && `maxgold`=155; -- Salia
UPDATE `creature_template` SET `maxgold`=301 WHERE `entry`=9861 && `maxgold`=125; -- Moora
UPDATE `creature_template` SET `maxgold`=760 WHERE `entry`=9862 && `maxgold`=154; -- Jaedenar Legionnaire
UPDATE `creature_template` SET `maxgold`=797 WHERE `entry`=9877 && `maxgold`=140; -- Prince Xavalis
UPDATE `creature_template` SET `maxgold`=467 WHERE `entry`=9916 && `maxgold`=119; -- Jarquia
UPDATE `creature_template` SET `maxgold`=752 WHERE `entry`=9956 && `maxgold`=94; -- Shadowforge Flame Keeper
UPDATE `creature_template` SET `maxgold`=868 WHERE `entry`=10043 && `maxgold`=513; -- Ribbly's Crony
UPDATE `creature_template` SET `maxgold`=1307 WHERE `entry`=10082 && `maxgold`=463; -- Zerillis
UPDATE `creature_template` SET `maxgold`=2600 WHERE `entry`=10083 && `maxgold`=535; -- Rage Talon Flamescale
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=10158 && `mingold`=13; -- Moonkin
UPDATE `creature_template` SET `maxgold`=26 WHERE `entry`=10158 && `maxgold`=22; -- Moonkin
UPDATE `creature_template` SET `mingold`=9 WHERE `entry`=10160 && `mingold`=14; -- Raging Moonkin
UPDATE `creature_template` SET `maxgold`=24 WHERE `entry`=10160 && `maxgold`=23; -- Raging Moonkin
UPDATE `creature_template` SET `mingold`=193 WHERE `entry`=10316 && `mingold`=215; -- Blackhand Incarcerator
UPDATE `creature_template` SET `maxgold`=985 WHERE `entry`=10316 && `maxgold`=286; -- Blackhand Incarcerator
UPDATE `creature_template` SET `mingold`=528 WHERE `entry`=10317 && `mingold`=779; -- Blackhand Elite
UPDATE `creature_template` SET `maxgold`=3166 WHERE `entry`=10317 && `maxgold`=1022; -- Blackhand Elite
UPDATE `creature_template` SET `mingold`=766 WHERE `entry`=10318 && `mingold`=779; -- Blackhand Assassin
UPDATE `creature_template` SET `maxgold`=2658 WHERE `entry`=10318 && `maxgold`=1022; -- Blackhand Assassin
UPDATE `creature_template` SET `maxgold`=2771 WHERE `entry`=10319 && `maxgold`=800; -- Blackhand Iron Guard
UPDATE `creature_template` SET `maxgold`=55 WHERE `entry`=10323 && `maxgold`=27; -- Murkdeep
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=10358 && `mingold`=13; -- Fellicent's Shade
UPDATE `creature_template` SET `mingold`=1439 WHERE `entry`=10363 && `mingold`=1771; -- General Drakkisath
UPDATE `creature_template` SET `maxgold`=2717 WHERE `entry`=10366 && `maxgold`=1189; -- Rage Talon Dragon Guard
UPDATE `creature_template` SET `maxgold`=2568 WHERE `entry`=10371 && `maxgold`=1193; -- Rage Talon Captain
UPDATE `creature_template` SET `mingold`=619 WHERE `entry`=10372 && `mingold`=907; -- Rage Talon Fire Tongue
UPDATE `creature_template` SET `maxgold`=2979 WHERE `entry`=10372 && `maxgold`=1189; -- Rage Talon Fire Tongue
UPDATE `creature_template` SET `mingold`=423 WHERE `entry`=10381 && `mingold`=449; -- Ravaged Cadaver (sample size 34)
UPDATE `creature_template` SET `maxgold`=2614 WHERE `entry`=10381 && `maxgold`=592; -- Ravaged Cadaver (sample size 34)
UPDATE `creature_template` SET `mingold`=411 WHERE `entry`=10382 && `mingold`=435; -- Mangled Cadaver (sample size 30)
UPDATE `creature_template` SET `maxgold`=2481 WHERE `entry`=10382 && `maxgold`=573; -- Mangled Cadaver (sample size 30)
UPDATE `creature_template` SET `maxgold`=522 WHERE `entry`=10384 && `maxgold`=456; -- Spectral Citizen
UPDATE `creature_template` SET `mingold`=122 WHERE `entry`=10390 && `mingold`=112; -- Skeletal Guardian (sample size 85)
UPDATE `creature_template` SET `maxgold`=821 WHERE `entry`=10390 && `maxgold`=151; -- Skeletal Guardian (sample size 85)
UPDATE `creature_template` SET `mingold`=136 WHERE `entry`=10391 && `mingold`=108; -- Skeletal Berserker (sample size 74)
UPDATE `creature_template` SET `maxgold`=843 WHERE `entry`=10391 && `maxgold`=146; -- Skeletal Berserker (sample size 74)
UPDATE `creature_template` SET `maxgold`=2854 WHERE `entry`=10393 && `maxgold`=1728; -- Skul
UPDATE `creature_template` SET `maxgold`=2416 WHERE `entry`=10394 && `maxgold`=761; -- Black Guard Sentry
UPDATE `creature_template` SET `maxgold`=2613 WHERE `entry`=10398 && `maxgold`=502; -- Thuzadin Shadowcaster
UPDATE `creature_template` SET `mingold`=472 WHERE `entry`=10399 && `mingold`=113; -- Thuzadin Acolyte (sample size 26)
UPDATE `creature_template` SET `maxgold`=3028 WHERE `entry`=10399 && `maxgold`=153; -- Thuzadin Acolyte (sample size 26)
UPDATE `creature_template` SET `maxgold`=2812 WHERE `entry`=10400 && `maxgold`=501; -- Thuzadin Necromancer
UPDATE `creature_template` SET `mingold`=420 WHERE `entry`=10405 && `mingold`=468; -- Plague Ghoul (sample size 45)
UPDATE `creature_template` SET `maxgold`=2677 WHERE `entry`=10405 && `maxgold`=616; -- Plague Ghoul (sample size 45)
UPDATE `creature_template` SET `mingold`=547 WHERE `entry`=10406 && `mingold`=474; -- Ghoul Ravener (sample size 24)
UPDATE `creature_template` SET `maxgold`=2727 WHERE `entry`=10406 && `maxgold`=624; -- Ghoul Ravener (sample size 24)
UPDATE `creature_template` SET `maxgold`=2930 WHERE `entry`=10407 && `maxgold`=648; -- Fleshflayer Ghoul
UPDATE `creature_template` SET `maxgold`=808 WHERE `entry`=10411 && `maxgold`=143; -- Eye of Naxxramas
UPDATE `creature_template` SET `maxgold`=2663 WHERE `entry`=10414 && `maxgold`=1071; -- Patchwork Horror
UPDATE `creature_template` SET `mingold`=503 WHERE `entry`=10416 && `mingold`=735; -- Bile Spewer
UPDATE `creature_template` SET `maxgold`=2070 WHERE `entry`=10416 && `maxgold`=964; -- Bile Spewer
UPDATE `creature_template` SET `mingold`=743 WHERE `entry`=10417 && `mingold`=779; -- Venom Belcher
UPDATE `creature_template` SET `maxgold`=2721 WHERE `entry`=10417 && `maxgold`=1022; -- Venom Belcher
UPDATE `creature_template` SET `mingold`=393 WHERE `entry`=10418 && `mingold`=464; -- Crimson Guardsman (sample size 37)
UPDATE `creature_template` SET `maxgold`=2709 WHERE `entry`=10418 && `maxgold`=610; -- Crimson Guardsman (sample size 37)
UPDATE `creature_template` SET `maxgold`=2525 WHERE `entry`=10419 && `maxgold`=477; -- Crimson Conjuror
UPDATE `creature_template` SET `mingold`=460 WHERE `entry`=10420 && `mingold`=396; -- Crimson Initiate (sample size 21)
UPDATE `creature_template` SET `maxgold`=2637 WHERE `entry`=10420 && `maxgold`=522; -- Crimson Initiate (sample size 21)
UPDATE `creature_template` SET `maxgold`=2844 WHERE `entry`=10421 && `maxgold`=529; -- Crimson Defender
UPDATE `creature_template` SET `maxgold`=2364 WHERE `entry`=10422 && `maxgold`=485; -- Crimson Sorcerer
UPDATE `creature_template` SET `maxgold`=2296 WHERE `entry`=10423 && `maxgold`=485; -- Crimson Priest
UPDATE `creature_template` SET `mingold`=438 WHERE `entry`=10424 && `mingold`=416; -- Crimson Gallant (sample size 22)
UPDATE `creature_template` SET `maxgold`=2897 WHERE `entry`=10424 && `maxgold`=548; -- Crimson Gallant (sample size 22)
UPDATE `creature_template` SET `maxgold`=2054 WHERE `entry`=10425 && `maxgold`=504; -- Crimson Battle Mage
UPDATE `creature_template` SET `maxgold`=2388 WHERE `entry`=10426 && `maxgold`=532; -- Crimson Inquisitor
UPDATE `creature_template` SET `maxgold`=2654 WHERE `entry`=10435 && `maxgold`=1684; -- Magistrate Barthilas
UPDATE `creature_template` SET `maxgold`=2697 WHERE `entry`=10438 && `maxgold`=1357; -- Maleki the Pallid
UPDATE `creature_template` SET `maxgold`=1757 WHERE `entry`=10439 && `maxgold`=900; -- Ramstein the Gorger
UPDATE `creature_template` SET `mingold`=159 WHERE `entry`=10442 && `mingold`=120; -- Chromatic Whelp (sample size 21)
UPDATE `creature_template` SET `maxgold`=896 WHERE `entry`=10442 && `maxgold`=161; -- Chromatic Whelp (sample size 21)
UPDATE `creature_template` SET `mingold`=663 WHERE `entry`=10447 && `mingold`=735; -- Chromatic Dragonspawn
UPDATE `creature_template` SET `maxgold`=2288 WHERE `entry`=10447 && `maxgold`=964; -- Chromatic Dragonspawn
UPDATE `creature_template` SET `maxgold`=2746 WHERE `entry`=10463 && `maxgold`=610; -- Shrieking Banshee
UPDATE `creature_template` SET `maxgold`=2869 WHERE `entry`=10464 && `maxgold`=629; -- Wailing Banshee
UPDATE `creature_template` SET `mingold`=516 WHERE `entry`=10469 && `mingold`=402; -- Scholomance Adept (sample size 45)
UPDATE `creature_template` SET `maxgold`=2862 WHERE `entry`=10469 && `maxgold`=529; -- Scholomance Adept (sample size 45)
UPDATE `creature_template` SET `maxgold`=2748 WHERE `entry`=10470 && `maxgold`=472; -- Scholomance Neophyte
UPDATE `creature_template` SET `maxgold`=2587 WHERE `entry`=10471 && `maxgold`=510; -- Scholomance Acolyte
UPDATE `creature_template` SET `mingold`=511 WHERE `entry`=10476 && `mingold`=391; -- Scholomance Necrolyte (sample size 22)
UPDATE `creature_template` SET `maxgold`=2747 WHERE `entry`=10476 && `maxgold`=516; -- Scholomance Necrolyte (sample size 22)
UPDATE `creature_template` SET `mingold`=465 WHERE `entry`=10477 && `mingold`=406; -- Scholomance Necromancer (sample size 36)
UPDATE `creature_template` SET `maxgold`=2834 WHERE `entry`=10477 && `maxgold`=535; -- Scholomance Necromancer (sample size 36)
UPDATE `creature_template` SET `maxgold`=2653 WHERE `entry`=10478 && `maxgold`=643; -- Splintered Skeleton
UPDATE `creature_template` SET `mingold`=141 WHERE `entry`=10480 && `mingold`=133; -- Unstable Corpse (sample size 48)
UPDATE `creature_template` SET `maxgold`=940 WHERE `entry`=10480 && `maxgold`=179; -- Unstable Corpse (sample size 48)
UPDATE `creature_template` SET `mingold`=145 WHERE `entry`=10481 && `mingold`=89; -- Reanimated Corpse (sample size 23)
UPDATE `creature_template` SET `maxgold`=954 WHERE `entry`=10481 && `maxgold`=121; -- Reanimated Corpse (sample size 23)
UPDATE `creature_template` SET `mingold`=132 WHERE `entry`=10485 && `mingold`=101; -- Risen Aberration (sample size 34)
UPDATE `creature_template` SET `maxgold`=916 WHERE `entry`=10485 && `maxgold`=136; -- Risen Aberration (sample size 34)
UPDATE `creature_template` SET `mingold`=477 WHERE `entry`=10486 && `mingold`=777; -- Risen Warrior
UPDATE `creature_template` SET `maxgold`=2890 WHERE `entry`=10486 && `maxgold`=1020; -- Risen Warrior
UPDATE `creature_template` SET `maxgold`=2637 WHERE `entry`=10487 && `maxgold`=540; -- Risen Protector
UPDATE `creature_template` SET `mingold`=664 WHERE `entry`=10488 && `mingold`=776; -- Risen Construct
UPDATE `creature_template` SET `maxgold`=2707 WHERE `entry`=10488 && `maxgold`=1018; -- Risen Construct
UPDATE `creature_template` SET `mingold`=412 WHERE `entry`=10489 && `mingold`=472; -- Risen Guard (sample size 25)
UPDATE `creature_template` SET `maxgold`=2500 WHERE `entry`=10489 && `maxgold`=621; -- Risen Guard (sample size 25)
UPDATE `creature_template` SET `maxgold`=2194 WHERE `entry`=10491 && `maxgold`=535; -- Risen Bonewarder
UPDATE `creature_template` SET `mingold`=535 WHERE `entry`=10495 && `mingold`=470; -- Diseased Ghoul (sample size 25)
UPDATE `creature_template` SET `maxgold`=2844 WHERE `entry`=10495 && `maxgold`=618; -- Diseased Ghoul (sample size 25)
UPDATE `creature_template` SET `maxgold`=2832 WHERE `entry`=10498 && `maxgold`=546; -- Spectral Tutor
UPDATE `creature_template` SET `maxgold`=2285 WHERE `entry`=10499 && `maxgold`=540; -- Spectral Researcher
UPDATE `creature_template` SET `maxgold`=2640 WHERE `entry`=10500 && `maxgold`=563; -- Spectral Teacher
UPDATE `creature_template` SET `maxgold`=3038 WHERE `entry`=10502 && `maxgold`=1633; -- Lady Illucia Barov
UPDATE `creature_template` SET `maxgold`=2572 WHERE `entry`=10504 && `maxgold`=1633; -- Lord Alexei Barov
UPDATE `creature_template` SET `maxgold`=2122 WHERE `entry`=10505 && `maxgold`=2021; -- Instructor Malicia
UPDATE `creature_template` SET `mingold`=470 WHERE `entry`=10507 && `mingold`=1629; -- The Ravenian
UPDATE `creature_template` SET `maxgold`=3291 WHERE `entry`=10508 && `maxgold`=1970; -- Ras Frostwhisper
UPDATE `creature_template` SET `maxgold`=2708 WHERE `entry`=10558 && `maxgold`=774; -- Hearthsinger Forresten
UPDATE `creature_template` SET `maxgold`=727 WHERE `entry`=10580 && `maxgold`=164; -- Fetid Zombie
UPDATE `creature_template` SET `maxgold`=714 WHERE `entry`=10605 && `maxgold`=134; -- Scarlet Medic
UPDATE `creature_template` SET `maxgold`=1897 WHERE `entry`=10608 && `maxgold`=528; -- Scarlet Priest
UPDATE `creature_template` SET `mingold`=35 WHERE `entry`=10617 && `mingold`=37; -- Galak Messenger
UPDATE `creature_template` SET `maxgold`=97 WHERE `entry`=10617 && `maxgold`=53; -- Galak Messenger
UPDATE `creature_template` SET `maxgold`=135 WHERE `entry`=10640 && `maxgold`=55; -- Oakpaw
UPDATE `creature_template` SET `maxgold`=88 WHERE `entry`=10641 && `maxgold`=49; -- Branch Snapper
UPDATE `creature_template` SET `maxgold`=156 WHERE `entry`=10647 && `maxgold`=73; -- Prince Raze
UPDATE `creature_template` SET `maxgold`=712 WHERE `entry`=10648 && `maxgold`=140; -- Xavaric
UPDATE `creature_template` SET `mingold`=133 WHERE `entry`=10678 && `mingold`=130; -- Plagued Hatchling (sample size 43)
UPDATE `creature_template` SET `maxgold`=916 WHERE `entry`=10678 && `maxgold`=175; -- Plagued Hatchling (sample size 43)
UPDATE `creature_template` SET `maxgold`=1363 WHERE `entry`=10680 && `maxgold`=543; -- Summoned Blackhand Dreadweaver
UPDATE `creature_template` SET `maxgold`=903 WHERE `entry`=10683 && `maxgold`=761; -- Rookery Hatcher
UPDATE `creature_template` SET `maxgold`=2823 WHERE `entry`=10738 && `maxgold`=526; -- High Chief Winterfall
UPDATE `creature_template` SET `maxgold`=1506 WHERE `entry`=10742 && `maxgold`=648; -- Blackhand Dragon Handler
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=10758 && `mingold`=35; -- Grimtotem Bandit (sample size 35)
UPDATE `creature_template` SET `maxgold`=123 WHERE `entry`=10758 && `maxgold`=51; -- Grimtotem Bandit (sample size 35)
UPDATE `creature_template` SET `mingold`=27 WHERE `entry`=10759 && `mingold`=34; -- Grimtotem Stomper (sample size 31)
UPDATE `creature_template` SET `maxgold`=132 WHERE `entry`=10759 && `maxgold`=50; -- Grimtotem Stomper (sample size 31)
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=10760 && `mingold`=32; -- Grimtotem Geomancer (sample size 45)
UPDATE `creature_template` SET `maxgold`=121 WHERE `entry`=10760 && `maxgold`=47; -- Grimtotem Geomancer (sample size 45)
UPDATE `creature_template` SET `maxgold`=154 WHERE `entry`=10761 && `maxgold`=59; -- Grimtotem Reaver
UPDATE `creature_template` SET `maxgold`=652 WHERE `entry`=10801 && `maxgold`=153; -- Jabbering Ghoul
UPDATE `creature_template` SET `maxgold`=1414 WHERE `entry`=10802 && `maxgold`=558; -- Hitah'ya the Keeper
UPDATE `creature_template` SET `maxgold`=2828 WHERE `entry`=10808 && `maxgold`=708; -- Timmy the Cruel
UPDATE `creature_template` SET `maxgold`=2609 WHERE `entry`=10811 && `maxgold`=1189; -- Archivist Galford
UPDATE `creature_template` SET `maxgold`=3148 WHERE `entry`=10813 && `maxgold`=2307; -- Balnazzar
UPDATE `creature_template` SET `maxgold`=2830 WHERE `entry`=10814 && `maxgold`=1464; -- Chromatic Elite Guard
UPDATE `creature_template` SET `maxgold`=773 WHERE `entry`=10816 && `maxgold`=159; -- Wandering Skeleton
UPDATE `creature_template` SET `maxgold`=159 WHERE `entry`=10896 && `maxgold`=61; -- Arnak Grimtotem
UPDATE `creature_template` SET `maxgold`=1862 WHERE `entry`=10901 && `maxgold`=1633; -- Lorekeeper Polkelt
UPDATE `creature_template` SET `maxgold`=896 WHERE `entry`=10916 && `maxgold`=170; -- Winterfall Runner
UPDATE `creature_template` SET `mingold`=126 WHERE `entry`=10986 && `mingold`=59; -- Snowblind Harpy (sample size 25)
UPDATE `creature_template` SET `maxgold`=699 WHERE `entry`=10986 && `maxgold`=296; -- Snowblind Harpy (sample size 25)
UPDATE `creature_template` SET `maxgold`=488 WHERE `entry`=10991 && `maxgold`=305; -- Wildpaw Gnoll
UPDATE `creature_template` SET `maxgold`=2726 WHERE `entry`=11032 && `maxgold`=1078; -- Malor the Zealous
UPDATE `creature_template` SET `mingold`=486 WHERE `entry`=11043 && `mingold`=491; -- Crimson Monk
UPDATE `creature_template` SET `maxgold`=2365 WHERE `entry`=11043 && `maxgold`=646; -- Crimson Monk
UPDATE `creature_template` SET `maxgold`=1981 WHERE `entry`=11058 && `maxgold`=864; -- Fras Siabi
UPDATE `creature_template` SET `maxgold`=2895 WHERE `entry`=11257 && `maxgold`=554; -- Scholomance Handler
UPDATE `creature_template` SET `maxgold`=2253 WHERE `entry`=11261 && `maxgold`=1799; -- Doctor Theolen Krastinov
UPDATE `creature_template` SET `maxgold`=2857 WHERE `entry`=11284 && `maxgold`=812; -- Dark Shade
UPDATE `creature_template` SET `mingold`=110 WHERE `entry`=11290 && `mingold`=112; -- Mossflayer Zombie
UPDATE `creature_template` SET `maxgold`=741 WHERE `entry`=11290 && `maxgold`=151; -- Mossflayer Zombie
UPDATE `creature_template` SET `maxgold`=531 WHERE `entry`=11291 && `maxgold`=158; -- Unliving Mossflayer
UPDATE `creature_template` SET `mingold`=19 WHERE `entry`=11318 && `mingold`=60; -- Ragefire Trogg (sample size 24)
UPDATE `creature_template` SET `maxgold`=85 WHERE `entry`=11318 && `maxgold`=84; -- Ragefire Trogg (sample size 24)
UPDATE `creature_template` SET `mingold`=18 WHERE `entry`=11319 && `mingold`=59; -- Ragefire Shaman
UPDATE `creature_template` SET `maxgold`=82 WHERE `entry`=11319 && `maxgold`=81; -- Ragefire Shaman
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=11322 && `mingold`=59; -- Searing Blade Cultist (sample size 35)
UPDATE `creature_template` SET `maxgold`=87 WHERE `entry`=11322 && `maxgold`=81; -- Searing Blade Cultist (sample size 35)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=11323 && `mingold`=62; -- Searing Blade Enforcer (sample size 26)
UPDATE `creature_template` SET `maxgold`=87 WHERE `entry`=11323 && `maxgold`=86; -- Searing Blade Enforcer (sample size 26)
UPDATE `creature_template` SET `mingold`=30 WHERE `entry`=11324 && `mingold`=57; -- Searing Blade Warlock
UPDATE `creature_template` SET `maxgold`=84 WHERE `entry`=11324 && `maxgold`=80; -- Searing Blade Warlock
UPDATE `creature_template` SET `maxgold`=2162 WHERE `entry`=11338 && `maxgold`=1513; -- Hakkari Shadowcaster
UPDATE `creature_template` SET `mingold`=542 WHERE `entry`=11339 && `mingold`=1163; -- Hakkari Shadow Hunter
UPDATE `creature_template` SET `maxgold`=2246 WHERE `entry`=11339 && `maxgold`=1524; -- Hakkari Shadow Hunter
UPDATE `creature_template` SET `maxgold`=1290 WHERE `entry`=11340 && `maxgold`=969; -- Hakkari Blood Priest
UPDATE `creature_template` SET `mingold`=753 WHERE `entry`=11350 && `mingold`=992; -- Gurubashi Axe Thrower
UPDATE `creature_template` SET `maxgold`=3174 WHERE `entry`=11350 && `maxgold`=1300; -- Gurubashi Axe Thrower
UPDATE `creature_template` SET `mingold`=574 WHERE `entry`=11351 && `mingold`=992; -- Gurubashi Headhunter
UPDATE `creature_template` SET `maxgold`=2247 WHERE `entry`=11351 && `maxgold`=1300; -- Gurubashi Headhunter
UPDATE `creature_template` SET `maxgold`=3429 WHERE `entry`=11352 && `maxgold`=2803; -- Gurubashi Berserker
UPDATE `creature_template` SET `mingold`=476 WHERE `entry`=11353 && `mingold`=907; -- Gurubashi Blood Drinker
UPDATE `creature_template` SET `maxgold`=3084 WHERE `entry`=11353 && `maxgold`=1189; -- Gurubashi Blood Drinker
UPDATE `creature_template` SET `mingold`=693 WHERE `entry`=11356 && `mingold`=1418; -- Gurubashi Champion
UPDATE `creature_template` SET `maxgold`=3265 WHERE `entry`=11356 && `maxgold`=1857; -- Gurubashi Champion
UPDATE `creature_template` SET `maxgold`=410164 WHERE `entry`=11382 && `maxgold`=405013; -- Bloodlord Mandokir
UPDATE `creature_template` SET `maxgold`=2155 WHERE `entry`=11387 && `maxgold`=171; -- Sandfury Speaker
UPDATE `creature_template` SET `maxgold`=2571 WHERE `entry`=11391 && `maxgold`=182; -- Vilebranch Speaker
UPDATE `creature_template` SET `maxgold`=2711 WHERE `entry`=11441 && `maxgold`=905; -- Gordok Brute
UPDATE `creature_template` SET `maxgold`=1764 WHERE `entry`=11442 && `maxgold`=546; -- Gordok Mauler
UPDATE `creature_template` SET `maxgold`=511 WHERE `entry`=11443 && `maxgold`=449; -- Gordok Ogre-Mage
UPDATE `creature_template` SET `maxgold`=1812 WHERE `entry`=11444 && `maxgold`=683; -- Gordok Mage-Lord
UPDATE `creature_template` SET `maxgold`=2093 WHERE `entry`=11445 && `maxgold`=1020; -- Gordok Captain
UPDATE `creature_template` SET `mingold`=481 WHERE `entry`=11448 && `mingold`=0; -- Gordok Warlock (sample size 4)
UPDATE `creature_template` SET `maxgold`=2236 WHERE `entry`=11448 && `maxgold`=0; -- Gordok Warlock (sample size 4)
UPDATE `creature_template` SET `maxgold`=2232 WHERE `entry`=11450 && `maxgold`=1018; -- Gordok Reaver
UPDATE `creature_template` SET `maxgold`=723 WHERE `entry`=11451 && `maxgold`=578; -- Wildspawn Satyr
UPDATE `creature_template` SET `maxgold`=625 WHERE `entry`=11452 && `maxgold`=597; -- Wildspawn Rogue
UPDATE `creature_template` SET `maxgold`=2439 WHERE `entry`=11453 && `maxgold`=492; -- Wildspawn Trickster
UPDATE `creature_template` SET `maxgold`=1067 WHERE `entry`=11454 && `maxgold`=584; -- Wildspawn Betrayer
UPDATE `creature_template` SET `maxgold`=1966 WHERE `entry`=11455 && `maxgold`=451; -- Wildspawn Felsworn
UPDATE `creature_template` SET `maxgold`=1787 WHERE `entry`=11456 && `maxgold`=580; -- Wildspawn Shadowstalker
UPDATE `creature_template` SET `maxgold`=1128 WHERE `entry`=11457 && `maxgold`=503; -- Wildspawn Hellcaller
UPDATE `creature_template` SET `maxgold`=1918 WHERE `entry`=11459 && `maxgold`=1127; -- Ironbark Protector
UPDATE `creature_template` SET `maxgold`=1306 WHERE `entry`=11461 && `maxgold`=522; -- Warpwood Guardian
UPDATE `creature_template` SET `maxgold`=2236 WHERE `entry`=11462 && `maxgold`=559; -- Warpwood Treant
UPDATE `creature_template` SET `maxgold`=1996 WHERE `entry`=11464 && `maxgold`=484; -- Warpwood Tangler
UPDATE `creature_template` SET `maxgold`=1842 WHERE `entry`=11470 && `maxgold`=529; -- Eldreth Sorcerer
UPDATE `creature_template` SET `maxgold`=2405 WHERE `entry`=11471 && `maxgold`=522; -- Eldreth Apparition
UPDATE `creature_template` SET `maxgold`=2684 WHERE `entry`=11472 && `maxgold`=610; -- Eldreth Spirit
UPDATE `creature_template` SET `maxgold`=2858 WHERE `entry`=11473 && `maxgold`=529; -- Eldreth Spectre
UPDATE `creature_template` SET `maxgold`=2299 WHERE `entry`=11475 && `maxgold`=629; -- Eldreth Phantasm
UPDATE `creature_template` SET `maxgold`=780 WHERE `entry`=11476 && `maxgold`=172; -- Skeletal Highborne
UPDATE `creature_template` SET `maxgold`=416 WHERE `entry`=11477 && `maxgold`=176; -- Rotting Highborne
UPDATE `creature_template` SET `maxgold`=3263 WHERE `entry`=11486 && `maxgold`=1857; -- Prince Tortheldrin
UPDATE `creature_template` SET `maxgold`=2111 WHERE `entry`=11487 && `maxgold`=1300; -- Magister Kalendris
UPDATE `creature_template` SET `maxgold`=1222 WHERE `entry`=11488 && `maxgold`=1078; -- Illyanna Ravenoak
UPDATE `creature_template` SET `mingold`=731 WHERE `entry`=11489 && `mingold`=1502; -- Tendris Warpwood
UPDATE `creature_template` SET `mingold`=21 WHERE `entry`=11518 && `mingold`=88; -- Jergosh the Invoker
UPDATE `creature_template` SET `mingold`=33 WHERE `entry`=11519 && `mingold`=92; -- Bazzalan
UPDATE `creature_template` SET `mingold`=50 WHERE `entry`=11520 && `mingold`=109; -- Taragaman the Hungerer
UPDATE `creature_template` SET `maxgold`=294 WHERE `entry`=11559 && `maxgold`=78; -- Outcast Necromancer
UPDATE `creature_template` SET `mingold`=69 WHERE `entry`=11561 && `mingold`=62; -- Undead Ravager (sample size 41)
UPDATE `creature_template` SET `maxgold`=292 WHERE `entry`=11561 && `maxgold`=86; -- Undead Ravager (sample size 41)
UPDATE `creature_template` SET `mingold`=41 WHERE `entry`=11562 && `mingold`=46; -- Drysnap Crawler (sample size 23)
UPDATE `creature_template` SET `maxgold`=205 WHERE `entry`=11562 && `maxgold`=65; -- Drysnap Crawler (sample size 23)
UPDATE `creature_template` SET `mingold`=40 WHERE `entry`=11563 && `mingold`=51; -- Drysnap Pincer
UPDATE `creature_template` SET `maxgold`=239 WHERE `entry`=11563 && `maxgold`=72; -- Drysnap Pincer
UPDATE `creature_template` SET `maxgold`=2710 WHERE `entry`=11582 && `maxgold`=535; -- Scholomance Dark Summoner
UPDATE `creature_template` SET `maxgold`=866 WHERE `entry`=11598 && `maxgold`=326; -- Risen Guardian
UPDATE `creature_template` SET `maxgold`=615 WHERE `entry`=11611 && `maxgold`=150; -- Cavalier Durgen
UPDATE `creature_template` SET `maxgold`=788 WHERE `entry`=11613 && `maxgold`=166; -- Huntsman Radley
UPDATE `creature_template` SET `mingold`=1861 WHERE `entry`=11661 && `mingold`=3417; -- Flamewaker
UPDATE `creature_template` SET `mingold`=1989 WHERE `entry`=11662 && `mingold`=0; -- Flamewaker Priest (sample size 1)
UPDATE `creature_template` SET `maxgold`=3242 WHERE `entry`=11662 && `maxgold`=0; -- Flamewaker Priest (sample size 1)
UPDATE `creature_template` SET `mingold`=122 WHERE `entry`=11675 && `mingold`=61; -- Snowblind Windcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=638 WHERE `entry`=11675 && `maxgold`=305; -- Snowblind Windcaller (sample size 21)
UPDATE `creature_template` SET `maxgold`=675 WHERE `entry`=11678 && `maxgold`=305; -- Snowblind Ambusher
UPDATE `creature_template` SET `maxgold`=128 WHERE `entry`=11680 && `maxgold`=52; -- Horde Scout
UPDATE `creature_template` SET `maxgold`=141 WHERE `entry`=11685 && `maxgold`=79; -- Maraudine Priest
UPDATE `creature_template` SET `maxgold`=354 WHERE `entry`=11686 && `maxgold`=98; -- Ghostly Raider
UPDATE `creature_template` SET `maxgold`=256 WHERE `entry`=11687 && `maxgold`=96; -- Ghostly Marauder
UPDATE `creature_template` SET `mingold`=24 WHERE `entry`=11697 && `mingold`=40; -- Mannoroc Lasher
UPDATE `creature_template` SET `maxgold`=117 WHERE `entry`=11697 && `maxgold`=58; -- Mannoroc Lasher
UPDATE `creature_template` SET `maxgold`=58 WHERE `entry`=11714 && `maxgold`=23; -- Marosh the Devious
UPDATE `creature_template` SET `maxgold`=856 WHERE `entry`=11790 && `maxgold`=396; -- Putridus Satyr
UPDATE `creature_template` SET `mingold`=199 WHERE `entry`=11791 && `mingold`=310; -- Putridus Trickster
UPDATE `creature_template` SET `maxgold`=1008 WHERE `entry`=11791 && `maxgold`=409; -- Putridus Trickster
UPDATE `creature_template` SET `maxgold`=856 WHERE `entry`=11792 && `maxgold`=394; -- Putridus Shadowstalker
UPDATE `creature_template` SET `maxgold`=1090 WHERE `entry`=11793 && `maxgold`=362; -- Celebrian Dryad
UPDATE `creature_template` SET `maxgold`=1476 WHERE `entry`=11794 && `maxgold`=436; -- Sister of Celebrian
UPDATE `creature_template` SET `mingold`=681 WHERE `entry`=11830 && `mingold`=822; -- Hakkari Priest
UPDATE `creature_template` SET `maxgold`=2107 WHERE `entry`=11830 && `maxgold`=1078; -- Hakkari Priest
UPDATE `creature_template` SET `mingold`=877 WHERE `entry`=11831 && `mingold`=1119; -- Hakkari Witch Doctor
UPDATE `creature_template` SET `maxgold`=2480 WHERE `entry`=11831 && `maxgold`=1466; -- Hakkari Witch Doctor
UPDATE `creature_template` SET `maxgold`=721 WHERE `entry`=11837 && `maxgold`=305; -- Wildpaw Shaman
UPDATE `creature_template` SET `maxgold`=69 WHERE `entry`=11858 && `maxgold`=32; -- Grundig Darkcloud
UPDATE `creature_template` SET `maxgold`=544 WHERE `entry`=11873 && `maxgold`=159; -- Spectral Attendant
UPDATE `creature_template` SET `mingold`=131 WHERE `entry`=11880 && `mingold`=133; -- Twilight Avenger
UPDATE `creature_template` SET `maxgold`=842 WHERE `entry`=11880 && `maxgold`=179; -- Twilight Avenger
UPDATE `creature_template` SET `maxgold`=911 WHERE `entry`=11881 && `maxgold`=183; -- Twilight Geolord
UPDATE `creature_template` SET `maxgold`=549 WHERE `entry`=11883 && `maxgold`=162; -- Twilight Master
UPDATE `creature_template` SET `maxgold`=2033 WHERE `entry`=11887 && `maxgold`=305; -- Crypt Robber
UPDATE `creature_template` SET `mingold`=4 WHERE `entry`=11910 && `mingold`=16; -- Grimtotem Ruffian
UPDATE `creature_template` SET `maxgold`=34 WHERE `entry`=11910 && `maxgold`=26; -- Grimtotem Ruffian
UPDATE `creature_template` SET `mingold`=5 WHERE `entry`=11911 && `mingold`=16; -- Grimtotem Mercenary
UPDATE `creature_template` SET `maxgold`=30 WHERE `entry`=11911 && `maxgold`=26; -- Grimtotem Mercenary
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=11912 && `mingold`=17; -- Grimtotem Brute
UPDATE `creature_template` SET `maxgold`=37 WHERE `entry`=11912 && `maxgold`=28; -- Grimtotem Brute
UPDATE `creature_template` SET `mingold`=10 WHERE `entry`=11913 && `mingold`=17; -- Grimtotem Sorcerer
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=11913 && `maxgold`=27; -- Grimtotem Sorcerer
UPDATE `creature_template` SET `maxgold`=44 WHERE `entry`=11914 && `maxgold`=34; -- Gorehoof the Black
UPDATE `creature_template` SET `mingold`=7 WHERE `entry`=11915 && `mingold`=18; -- Gogger Rock Keeper (sample size 23)
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=11915 && `maxgold`=28; -- Gogger Rock Keeper (sample size 23)
UPDATE `creature_template` SET `mingold`=8 WHERE `entry`=11917 && `mingold`=18; -- Gogger Geomancer (sample size 22)
UPDATE `creature_template` SET `maxgold`=49 WHERE `entry`=11917 && `maxgold`=28; -- Gogger Geomancer (sample size 22)
UPDATE `creature_template` SET `mingold`=13 WHERE `entry`=11918 && `mingold`=20; -- Gogger Stonepounder
UPDATE `creature_template` SET `maxgold`=52 WHERE `entry`=11918 && `maxgold`=32; -- Gogger Stonepounder
UPDATE `creature_template` SET `maxgold`=458 WHERE `entry`=12046 && `maxgold`=133; -- Gor'marok the Ravager
UPDATE `creature_template` SET `maxgold`=604 WHERE `entry`=12050 && `maxgold`=352; -- Stormpike Defender
UPDATE `creature_template` SET `maxgold`=772 WHERE `entry`=12127 && `maxgold`=416; -- Stormpike Guardsman
UPDATE `creature_template` SET `maxgold`=3033 WHERE `entry`=12128 && `maxgold`=880; -- Crimson Elite
UPDATE `creature_template` SET `mingold`=1185 WHERE `entry`=12129 && `mingold`=3627; -- Onyxian Warder
UPDATE `creature_template` SET `mingold`=12 WHERE `entry`=12138 && `mingold`=0; -- Lunaclaw (sample size 1)
UPDATE `creature_template` SET `maxgold`=16 WHERE `entry`=12138 && `maxgold`=0; -- Lunaclaw (sample size 1)
UPDATE `creature_template` SET `maxgold`=513 WHERE `entry`=12178 && `maxgold`=145; -- Tortured Druid
UPDATE `creature_template` SET `maxgold`=753 WHERE `entry`=12179 && `maxgold`=166; -- Tortured Sentinel
UPDATE `creature_template` SET `maxgold`=2040 WHERE `entry`=12201 && `maxgold`=1391; -- Princess Theradras
UPDATE `creature_template` SET `mingold`=582 WHERE `entry`=12203 && `mingold`=720; -- Landslide
UPDATE `creature_template` SET `maxgold`=1360 WHERE `entry`=12203 && `maxgold`=945; -- Landslide
UPDATE `creature_template` SET `mingold`=410 WHERE `entry`=12206 && `mingold`=631; -- Primordial Behemoth
UPDATE `creature_template` SET `maxgold`=1610 WHERE `entry`=12206 && `maxgold`=829; -- Primordial Behemoth
UPDATE `creature_template` SET `maxgold`=281 WHERE `entry`=12216 && `maxgold`=89; -- Poison Sprite
UPDATE `creature_template` SET `maxgold`=267 WHERE `entry`=12217 && `maxgold`=86; -- Corruptor
UPDATE `creature_template` SET `mingold`=179 WHERE `entry`=12221 && `mingold`=292; -- Noxious Slime
UPDATE `creature_template` SET `maxgold`=866 WHERE `entry`=12221 && `maxgold`=386; -- Noxious Slime
UPDATE `creature_template` SET `mingold`=221 WHERE `entry`=12222 && `mingold`=320; -- Creeping Sludge
UPDATE `creature_template` SET `maxgold`=498 WHERE `entry`=12222 && `maxgold`=423; -- Creeping Sludge
UPDATE `creature_template` SET `maxgold`=1162 WHERE `entry`=12223 && `maxgold`=423; -- Cavern Lurker
UPDATE `creature_template` SET `maxgold`=845 WHERE `entry`=12248 && `maxgold`=184; -- Infiltrator Hameya
UPDATE `creature_template` SET `maxgold`=695 WHERE `entry`=12250 && `maxgold`=159; -- Zaeldarr the Outcast
UPDATE `creature_template` SET `maxgold`=902 WHERE `entry`=12261 && `maxgold`=305; -- Infected Mossflayer
UPDATE `creature_template` SET `maxgold`=455 WHERE `entry`=12322 && `maxgold`=204; -- Quel'Lithien Protector
UPDATE `creature_template` SET `mingold`=137 WHERE `entry`=12377 && `mingold`=234; -- Wailing Spectre (sample size 21)
UPDATE `creature_template` SET `maxgold`=897 WHERE `entry`=12377 && `maxgold`=311; -- Wailing Spectre (sample size 21)
UPDATE `creature_template` SET `mingold`=162 WHERE `entry`=12378 && `mingold`=193; -- Damned Soul
UPDATE `creature_template` SET `maxgold`=848 WHERE `entry`=12378 && `maxgold`=257; -- Damned Soul
UPDATE `creature_template` SET `mingold`=167 WHERE `entry`=12379 && `mingold`=204; -- Unliving Caretaker
UPDATE `creature_template` SET `maxgold`=946 WHERE `entry`=12379 && `maxgold`=272; -- Unliving Caretaker
UPDATE `creature_template` SET `mingold`=146 WHERE `entry`=12380 && `mingold`=211; -- Unliving Resident (sample size 25)
UPDATE `creature_template` SET `maxgold`=946 WHERE `entry`=12380 && `maxgold`=280; -- Unliving Resident (sample size 25)
UPDATE `creature_template` SET `mingold`=6610 WHERE `entry`=12468 && `mingold`=0; -- Death Talon Hatcher (sample size 1)
UPDATE `creature_template` SET `maxgold`=6720 WHERE `entry`=12468 && `maxgold`=0; -- Death Talon Hatcher (sample size 1)
UPDATE `creature_template` SET `mingold`=579 WHERE `entry`=12475 && `mingold`=3372; -- Emeraldon Tree Warder
UPDATE `creature_template` SET `mingold`=2104 WHERE `entry`=12477 && `mingold`=3502; -- Verdantine Boughguard
UPDATE `creature_template` SET `mingold`=2655 WHERE `entry`=12478 && `mingold`=2863; -- Verdantine Oracle
UPDATE `creature_template` SET `mingold`=3163 WHERE `entry`=12498 && `mingold`=3502; -- Dreamstalker
UPDATE `creature_template` SET `maxgold`=260 WHERE `entry`=12579 && `maxgold`=181; -- Bloodfury Ripper
UPDATE `creature_template` SET `mingold`=15 WHERE `entry`=12856 && `mingold`=29; -- Ashenvale Outrunner
UPDATE `creature_template` SET `maxgold`=100 WHERE `entry`=12856 && `maxgold`=43; -- Ashenvale Outrunner
UPDATE `creature_template` SET `maxgold`=809 WHERE `entry`=12865 && `maxgold`=270; -- Ambassador Malcin
UPDATE `creature_template` SET `maxgold`=68 WHERE `entry`=12896 && `maxgold`=43; -- Silverwing Sentinel
UPDATE `creature_template` SET `maxgold`=80 WHERE `entry`=12897 && `maxgold`=40; -- Silverwing Warrior
UPDATE `creature_template` SET `maxgold`=167 WHERE `entry`=12976 && `maxgold`=138; -- Kolkar Waylayer
UPDATE `creature_template` SET `maxgold`=207 WHERE `entry`=12977 && `maxgold`=145; -- Kolkar Ambusher
UPDATE `creature_template` SET `mingold`=37 WHERE `entry`=13019 && `mingold`=45; -- Burning Blade Seer
UPDATE `creature_template` SET `maxgold`=224 WHERE `entry`=13019 && `maxgold`=63; -- Burning Blade Seer
UPDATE `creature_template` SET `maxgold`=2207 WHERE `entry`=13021 && `maxgold`=1013; -- Warpwood Crusher
UPDATE `creature_template` SET `mingold`=282 WHERE `entry`=13141 && `mingold`=300; -- Deeprot Stomper
UPDATE `creature_template` SET `maxgold`=880 WHERE `entry`=13141 && `maxgold`=396; -- Deeprot Stomper
UPDATE `creature_template` SET `maxgold`=1354 WHERE `entry`=13142 && `maxgold`=409; -- Deeprot Tangler
UPDATE `creature_template` SET `maxgold`=1230 WHERE `entry`=13153 && `maxgold`=886; -- Commander Mulfort
UPDATE `creature_template` SET `maxgold`=3035 WHERE `entry`=13181 && `maxgold`=761; -- Wing Commander Mulverick
UPDATE `creature_template` SET `maxgold`=557 WHERE `entry`=13276 && `maxgold`=163; -- Wildspawn Imp
UPDATE `creature_template` SET `maxgold`=2742 WHERE `entry`=13296 && `maxgold`=786; -- Lieutenant Largent
UPDATE `creature_template` SET `maxgold`=1175 WHERE `entry`=13297 && `maxgold`=786; -- Lieutenant Stouthandle
UPDATE `creature_template` SET `maxgold`=648 WHERE `entry`=13358 && `maxgold`=326; -- Stormpike Bowman
UPDATE `creature_template` SET `maxgold`=765 WHERE `entry`=13359 && `maxgold`=326; -- Frostwolf Bowman
UPDATE `creature_template` SET `mingold`=195 WHERE `entry`=13718 && `mingold`=232; -- The Nameless Prophet
UPDATE `creature_template` SET `maxgold`=994 WHERE `entry`=13718 && `maxgold`=308; -- The Nameless Prophet
UPDATE `creature_template` SET `maxgold`=1122 WHERE `entry`=13738 && `maxgold`=534; -- Veng
UPDATE `creature_template` SET `maxgold`=540 WHERE `entry`=13739 && `maxgold`=514; -- Maraudos
UPDATE `creature_template` SET `maxgold`=622 WHERE `entry`=13740 && `maxgold`=534; -- Magra
UPDATE `creature_template` SET `maxgold`=1060 WHERE `entry`=13741 && `maxgold`=534; -- Gelk
UPDATE `creature_template` SET `maxgold`=1073 WHERE `entry`=13742 && `maxgold`=534; -- Kolk
UPDATE `creature_template` SET `maxgold`=1387 WHERE `entry`=13797 && `maxgold`=900; -- Mountaineer Boombellow
UPDATE `creature_template` SET `maxgold`=3066 WHERE `entry`=13959 && `maxgold`=786; -- Alterac Yeti
UPDATE `creature_template` SET `mingold`=1010 WHERE `entry`=13996 && `mingold`=1500; -- Blackwing Technician
UPDATE `creature_template` SET `maxgold`=99 WHERE `entry`=14221 && `maxgold`=83; -- Gravis Slipknot
UPDATE `creature_template` SET `maxgold`=195 WHERE `entry`=14267 && `maxgold`=172; -- Emogg the Crusher
UPDATE `creature_template` SET `maxgold`=50 WHERE `entry`=14270 && `maxgold`=35; -- Squiddic
UPDATE `creature_template` SET `maxgold`=38 WHERE `entry`=14271 && `maxgold`=31; -- Ribchaser
UPDATE `creature_template` SET `maxgold`=102 WHERE `entry`=14273 && `maxgold`=48; -- Boulderheart
UPDATE `creature_template` SET `maxgold`=65 WHERE `entry`=14276 && `maxgold`=62; -- Scargil
UPDATE `creature_template` SET `maxgold`=179 WHERE `entry`=14277 && `maxgold`=64; -- Lady Zephris
UPDATE `creature_template` SET `maxgold`=100 WHERE `entry`=14278 && `maxgold`=58; -- Ro'Bark
UPDATE `creature_template` SET `mingold`=17 WHERE `entry`=14281 && `mingold`=30; -- Jimmy the Bleeder
UPDATE `creature_template` SET `maxgold`=2051 WHERE `entry`=14303 && `maxgold`=544; -- Petrified Guardian
UPDATE `creature_template` SET `maxgold`=1201 WHERE `entry`=14327 && `maxgold`=1127; -- Lethtendris
UPDATE `creature_template` SET `maxgold`=147 WHERE `entry`=14425 && `maxgold`=47; -- Gnawbone
UPDATE `creature_template` SET `maxgold`=86 WHERE `entry`=14426 && `maxgold`=57; -- Harb Foulmountain
UPDATE `creature_template` SET `mingold`=1 WHERE `entry`=14428 && `mingold`=6; -- Uruson
UPDATE `creature_template` SET `mingold`=3 WHERE `entry`=14431 && `mingold`=7; -- Fury Shelda
UPDATE `creature_template` SET `maxgold`=285 WHERE `entry`=14447 && `maxgold`=107; -- Gilmorian
UPDATE `creature_template` SET `maxgold`=310 WHERE `entry`=14492 && `maxgold`=103; -- Verifonix
UPDATE `creature_template` SET `mingold`=1167 WHERE `entry`=14506 && `mingold`=2131; -- Lord Hel'nurath
UPDATE `creature_template` SET `maxgold`=401620 WHERE `entry`=14510 && `maxgold`=400563; -- High Priestess Mar'li
UPDATE `creature_template` SET `maxgold`=369259 WHERE `entry`=14515 && `maxgold`=36687; -- High Priestess Arlokk
UPDATE `creature_template` SET `maxgold`=411647 WHERE `entry`=14517 && `maxgold`=407457; -- High Priestess Jeklik
UPDATE `creature_template` SET `maxgold`=1806 WHERE `entry`=14521 && `maxgold`=838; -- Aspect of Shadow
UPDATE `creature_template` SET `maxgold`=467 WHERE `entry`=14523 && `maxgold`=145; -- Ulathek
UPDATE `creature_template` SET `maxgold`=560 WHERE `entry`=14603 && `maxgold`=205; -- Zapped Shore Strider
UPDATE `creature_template` SET `maxgold`=556 WHERE `entry`=14604 && `maxgold`=222; -- Zapped Land Walker
UPDATE `creature_template` SET `maxgold`=540 WHERE `entry`=14638 && `maxgold`=213; -- Zapped Wave Strider
UPDATE `creature_template` SET `maxgold`=603 WHERE `entry`=14639 && `maxgold`=213; -- Zapped Deep Strider
UPDATE `creature_template` SET `maxgold`=603 WHERE `entry`=14640 && `maxgold`=222; -- Zapped Cliff Giant
UPDATE `creature_template` SET `mingold`=64 WHERE `entry`=14682 && `mingold`=0; -- Sever (sample size 5)
UPDATE `creature_template` SET `maxgold`=151 WHERE `entry`=14682 && `maxgold`=0; -- Sever (sample size 5)
UPDATE `creature_template` SET `mingold`=2275 WHERE `entry`=14684 && `mingold`=0; -- Balzaphon (sample size 2)
UPDATE `creature_template` SET `maxgold`=2984 WHERE `entry`=14684 && `maxgold`=0; -- Balzaphon (sample size 2)
UPDATE `creature_template` SET `mingold`=208 WHERE `entry`=14686 && `mingold`=0; -- Lady Falther'ess (sample size 3)
UPDATE `creature_template` SET `maxgold`=378 WHERE `entry`=14686 && `maxgold`=0; -- Lady Falther'ess (sample size 3)
UPDATE `creature_template` SET `mingold`=238 WHERE `entry`=14693 && `mingold`=0; -- Scorn (sample size 4)
UPDATE `creature_template` SET `maxgold`=657 WHERE `entry`=14693 && `maxgold`=0; -- Scorn (sample size 4)
UPDATE `creature_template` SET `mingold`=1041 WHERE `entry`=14695 && `mingold`=0; -- Lord Blackwood (sample size 1)
UPDATE `creature_template` SET `maxgold`=1871 WHERE `entry`=14695 && `maxgold`=0; -- Lord Blackwood (sample size 1)
UPDATE `creature_template` SET `mingold`=271 WHERE `entry`=14697 && `mingold`=0; -- Lumbering Horror (sample size 3)
UPDATE `creature_template` SET `maxgold`=503 WHERE `entry`=14697 && `maxgold`=0; -- Lumbering Horror (sample size 3)
UPDATE `creature_template` SET `mingold`=618 WHERE `entry`=14750 && `mingold`=1418; -- Gurubashi Bat Rider
UPDATE `creature_template` SET `maxgold`=3102 WHERE `entry`=14750 && `maxgold`=1857; -- Gurubashi Bat Rider
UPDATE `creature_template` SET `mingold`=794 WHERE `entry`=14825 && `mingold`=0; -- Withered Mistress (sample size 13)
UPDATE `creature_template` SET `maxgold`=3086 WHERE `entry`=14825 && `maxgold`=0; -- Withered Mistress (sample size 13)
UPDATE `creature_template` SET `mingold`=433457 WHERE `entry`=14834 && `mingold`=450277; -- Hakkar
UPDATE `creature_template` SET `maxgold`=590558 WHERE `entry`=14834 && `maxgold`=550338; -- Hakkar
UPDATE `creature_template` SET `mingold`=598 WHERE `entry`=14882 && `mingold`=779; -- Atal'ai Mistress
UPDATE `creature_template` SET `maxgold`=3056 WHERE `entry`=14882 && `maxgold`=1022; -- Atal'ai Mistress
UPDATE `creature_template` SET `mingold`=2174 WHERE `entry`=14883 && `mingold`=0; -- Voodoo Slave (sample size 2)
UPDATE `creature_template` SET `maxgold`=2476 WHERE `entry`=14883 && `maxgold`=0; -- Voodoo Slave (sample size 2)
UPDATE `creature_template` SET `maxgold`=3270 WHERE `entry`=15111 && `maxgold`=802; -- Mad Servant
UPDATE `creature_template` SET `maxgold`=1059 WHERE `entry`=15201 && `maxgold`=181; -- Twilight Flamereaver
UPDATE `creature_template` SET `maxgold`=218688 WHERE `entry`=15204 && `maxgold`=21638; -- High Marshal Whirlaxis
UPDATE `creature_template` SET `maxgold`=830 WHERE `entry`=15213 && `maxgold`=165; -- Twilight Overlord
UPDATE `creature_template` SET `maxgold`=537463 WHERE `entry`=15543 && `maxgold`=36968; -- Princess Yauj
UPDATE `creature_template` SET `mingold`=490638 WHERE `entry`=15544 && `mingold`=0; -- Vem (sample size 2)
UPDATE `creature_template` SET `maxgold`=516334 WHERE `entry`=15544 && `maxgold`=0; -- Vem (sample size 2)
UPDATE `creature_template` SET `mingold`=1528 WHERE `entry`=15591 && `mingold`=0; -- Minion of Weavil (sample size 1)
UPDATE `creature_template` SET `maxgold`=1794 WHERE `entry`=15591 && `maxgold`=0; -- Minion of Weavil (sample size 1)
UPDATE `creature_template` SET `mingold`=258 WHERE `entry`=15685 && `mingold`=0; -- Southsea Kidnapper (sample size 1)
UPDATE `creature_template` SET `maxgold`=417 WHERE `entry`=15685 && `maxgold`=0; -- Southsea Kidnapper (sample size 1)
UPDATE `creature_template` SET `mingold`=92 WHERE `entry`=15692 && `mingold`=0; -- Dark Iron Kidnapper (sample size 14)
UPDATE `creature_template` SET `maxgold`=471 WHERE `entry`=15692 && `maxgold`=0; -- Dark Iron Kidnapper (sample size 14)
UPDATE `creature_template` SET `maxgold`=1485537 WHERE `entry`=15727 && `maxgold`=1258227; -- C'Thun
UPDATE `creature_template` SET `mingold`=47736 WHERE `entry`=15743 && `mingold`=205024; -- Colossal Anubisath Warbringer
UPDATE `creature_template` SET `maxgold`=13960 WHERE `entry`=15748 && `maxgold`=5524; -- Lesser Anubisath Warbringer
UPDATE `creature_template` SET `mingold`=6082 WHERE `entry`=15806 && `mingold`=7502; -- Qiraji Lieutenant
UPDATE `creature_template` SET `mingold`=6189 WHERE `entry`=15807 && `mingold`=2024; -- Minor Anubisath Warbringer (sample size 36)
UPDATE `creature_template` SET `maxgold`=8033 WHERE `entry`=15807 && `maxgold`=2524; -- Minor Anubisath Warbringer (sample size 36)
UPDATE `creature_template` SET `mingold`=5011 WHERE `entry`=15810 && `mingold`=1024; -- Eroded Anubisath Warbringer (sample size 104)
UPDATE `creature_template` SET `maxgold`=7488 WHERE `entry`=15810 && `maxgold`=1524; -- Eroded Anubisath Warbringer (sample size 104)
UPDATE `creature_template` SET `mingold`=5241 WHERE `entry`=15812 && `mingold`=5124; -- Qiraji Officer (sample size 44)
UPDATE `creature_template` SET `maxgold`=7158 WHERE `entry`=15812 && `maxgold`=7552; -- Qiraji Officer (sample size 44)
UPDATE `creature_template` SET `maxgold`=10862 WHERE `entry`=15813 && `maxgold`=9552; -- Qiraji Officer Zod
UPDATE `creature_template` SET `mingold`=8494 WHERE `entry`=15814 && `mingold`=9502; -- Qiraji Lieutenant Jo-rel
UPDATE `creature_template` SET `maxgold`=9596 WHERE `entry`=15980 && `maxgold`=1579; -- Naxxramas Cultist
UPDATE `creature_template` SET `maxgold`=9661 WHERE `entry`=15981 && `maxgold`=1635; -- Naxxramas Acolyte
UPDATE `creature_template` SET `maxgold`=9694 WHERE `entry`=16020 && `maxgold`=2911; -- Mad Scientist
UPDATE `creature_template` SET `maxgold`=9706 WHERE `entry`=16021 && `maxgold`=2636; -- Living Monstrosity
UPDATE `creature_template` SET `maxgold`=9796 WHERE `entry`=16022 && `maxgold`=2410; -- Surgical Assistant
UPDATE `creature_template` SET `mingold`=6445 WHERE `entry`=16025 && `mingold`=6479; -- Stitched Spewer
UPDATE `creature_template` SET `mingold`=144 WHERE `entry`=16141 && `mingold`=0; -- Ghoul Berserker (sample size 360)
UPDATE `creature_template` SET `maxgold`=659 WHERE `entry`=16141 && `maxgold`=0; -- Ghoul Berserker (sample size 360)
UPDATE `creature_template` SET `mingold`=186 WHERE `entry`=16143 && `mingold`=0; -- Shadow of Doom (sample size 15)
UPDATE `creature_template` SET `maxgold`=615 WHERE `entry`=16143 && `maxgold`=0; -- Shadow of Doom (sample size 15)
UPDATE `creature_template` SET `maxgold`=9644 WHERE `entry`=16145 && `maxgold`=5409; -- Deathknight Captain
UPDATE `creature_template` SET `maxgold`=8599 WHERE `entry`=16154 && `maxgold`=1524; -- Risen Deathknight
UPDATE `creature_template` SET `maxgold`=8752 WHERE `entry`=16163 && `maxgold`=6241; -- Deathknight Cavalier
UPDATE `creature_template` SET `maxgold`=5231 WHERE `entry`=16165 && `maxgold`=2356; -- Necro Knight
UPDATE `creature_template` SET `maxgold`=7378 WHERE `entry`=16193 && `maxgold`=2911; -- Skeletal Smith
UPDATE `creature_template` SET `mingold`=6690 WHERE `entry`=16194 && `mingold`=0; -- Unholy Axe (sample size 1)
UPDATE `creature_template` SET `maxgold`=9414 WHERE `entry`=16194 && `maxgold`=0; -- Unholy Axe (sample size 1)
UPDATE `creature_template` SET `mingold`=4506 WHERE `entry`=16244 && `mingold`=0; -- Infectious Ghoul (sample size 10)
UPDATE `creature_template` SET `maxgold`=9113 WHERE `entry`=16244 && `maxgold`=0; -- Infectious Ghoul (sample size 10)
UPDATE `creature_template` SET `mingold`=148 WHERE `entry`=16298 && `mingold`=0; -- Spectral Soldier (sample size 280)
UPDATE `creature_template` SET `maxgold`=660 WHERE `entry`=16298 && `maxgold`=0; -- Spectral Soldier (sample size 280)
UPDATE `creature_template` SET `mingold`=144 WHERE `entry`=16299 && `mingold`=0; -- Skeletal Shocktrooper (sample size 296)
UPDATE `creature_template` SET `maxgold`=658 WHERE `entry`=16299 && `maxgold`=0; -- Skeletal Shocktrooper (sample size 296)
UPDATE `creature_template` SET `maxgold`=9398 WHERE `entry`=16368 && `maxgold`=3746; -- Necropolis Acolyte
UPDATE `creature_template` SET `mingold`=482 WHERE `entry`=16380 && `mingold`=0; -- Bone Witch (sample size 2)
UPDATE `creature_template` SET `maxgold`=558 WHERE `entry`=16380 && `maxgold`=0; -- Bone Witch (sample size 2)
UPDATE `creature_template` SET `mingold`=202 WHERE `entry`=16383 && `mingold`=0; -- Flameshocker (sample size 2)
UPDATE `creature_template` SET `maxgold`=560 WHERE `entry`=16383 && `maxgold`=0; -- Flameshocker (sample size 2)
UPDATE `creature_template` SET `mingold`=3878 WHERE `entry`=16447 && `mingold`=4011; -- Plagued Ghoul
UPDATE `creature_template` SET `maxgold`=8925 WHERE `entry`=16447 && `maxgold`=5242; -- Plagued Ghoul
UPDATE `creature_template` SET `mingold`=4220 WHERE `entry`=16451 && `mingold`=5627; -- Deathknight Vindicator

-- These mobs should not drop any gold.
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=8932; -- Borer Beetle
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=9683; -- Lar'korwi Mate
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=10177; -- Spire Scarab
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=10717; -- Temporal Parasite
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=15749; -- Lesser Silithid Flayer
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=15808; -- Minor Silithid Flayer
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0 WHERE `entry`=15811; -- Faltering Silithid Flayer
