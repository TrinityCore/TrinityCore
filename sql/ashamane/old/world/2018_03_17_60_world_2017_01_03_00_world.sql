-- 
-- Remove Loot From NPC Who SHould Not Have Any
DELETE FROM `creature_loot_template` WHERE `entry` IN 
(8257,10717,10461,10536,10441,20117,
3083, -- Honor Guard
6021, -- Boar Spirit
8257, -- Oozeling
10636, -- Pack Kodo
10925, -- Rotting Worm
10943, -- Decrepit Guardian
11054, -- Crimson Rifleman
20158, -- Slime-Covered Corpse
21040, -- Outraged Raven\'s Wood Sapling
128, -- Angry Programmer Tweedle Dee
197, -- Marshal McBride
235, -- Salma Saldean
240, -- Marshal Dughan
246, -- \"Auntie\" Bernice Stonefield
255, -- Gerard Tiller
266, -- Wiley the Black
275, -- Whit Wantmal
288, -- Jitters
313, -- Theocritus
325, -- Hogan Ference
341, -- Foreman Oslow
358, -- Riding Wolf (Brown)
359, -- Riding Wolf (Winter)
379, -- Darcy
381, -- Dockmaster Baren
382, -- Marshal Marris
415, -- Verner Osgood
416, -- Imp
417, -- Felhunter
466, -- General Marcus Jonathan
467, -- The Defias Traitor
468, -- Town Crier
469, -- Lieutenant Doren
487, -- Protector Bialon
488, -- Protector Weaver
489, -- Protector Dutfield
490, -- Protector Gariel
494, -- Watcher Bukouris
495, -- Watcher Keefer
499, -- Watcher Paige
659, -- El Pollo Grande
698, -- Bloodscalp Tiger
754, -- Rebel Watchman
756, -- Skullsplitter Panther
826, -- Watcher Jan
827, -- Watcher Mocarski
828, -- Watcher Petras
853, -- Coldridge Mountaineer
866, -- Stonard Grunt
867, -- Stonard Cartographer
869, -- Protector Dorana
870, -- Protector Deni
874, -- Protector Korelor
876, -- Protector Leick
885, -- Watcher Keller
886, -- Watcher Hartin
887, -- Watcher Jordan
888, -- Watcher Dodds
932, -- Guard Ashlock
933, -- Guard Hiett
934, -- Guard Clarke
935, -- Guard Pearce
936, -- Guard Adams
999, -- Watcher Royce
1001, -- Watcher Hutchins
1064, -- Grom\'gol Grunt
1066, -- Mottled Riptooth
1071, -- Longbraid the Grim
1073, -- Ashlan Stonesmirk
1093, -- Chief Engineer Hinderweir VII
1099, -- Watcher Gelwin
1244, -- Rethiel the Greenwarden
1245, -- Kogan Forgestone
1276, -- Mountaineer Brokk
1277, -- Mountaineer Ganin
1278, -- Mountaineer Stenn
1279, -- Mountaineer Flint
1280, -- Mountaineer Droken
1281, -- Mountaineer Zaren
1282, -- Mountaineer Veek
1283, -- Mountaineer Kalmir
1327, -- Reese Langston
1329, -- Mountaineer Naarh
1330, -- Mountaineer Tyraw
1331, -- Mountaineer Luxst
1332, -- Mountaineer Morran
1334, -- Mountaineer Hammerfall
1335, -- Mountaineer Yuttha
1336, -- Mountaineer Zwarn
1337, -- Mountaineer Gwarth
1338, -- Mountaineer Dalk
1374, -- Rejold Barleybrew
1414, -- Lisan Pierce
1434, -- Menethil Sentry
1436, -- Watcher Cutford
1437, -- Thomas Booker
1476, -- Hargin Mundar
1477, -- Christoph Faral
1481, -- Bart Tidewater
1483, -- Murphy West
1497, -- Gunther Arcanus
1503, -- Wretched Zombie
1511, -- Enraged Silverback Gorilla
1516, -- Konda
1642, -- Northshire Guard
1679, -- Avarus Kharag
1733, -- Zggi
1741, -- Deathguard Bartrand
1756, -- Stormwind Royal Guard
1777, -- Dakk Blunderblast
1975, -- Eastvale Lumberjack
2044, -- Forlorn Spirit
2045, -- Gunther\'s Minion
2055, -- Master Apothecary Faranell
2058, -- Deathstalker Faerleia
2099, -- Maiden\'s Virtue Crewman
2105, -- Mountaineer Dokkin
2112, -- Farrin Daris
2153, -- Terl Arakor
2214, -- Deathstalker Lesh
2238, -- Tog\'thar
2239, -- Drull
2316, -- Gol\'dir
2333, -- Henchman Valik
2361, -- Tamara Armstrong
2362, -- Hemmit Armstrong
2363, -- Apprentice Honeywell
2378, -- Kundric Zanden
2379, -- Caretaker Smithers
2386, -- Southshore Guard
2392, -- Delia Verana
2395, -- Vinna Wayne
2396, -- Hans Zandin
2400, -- Craig Hewitt
2402, -- Shara Blazen
2466, -- Mountaineer Grugelm
2468, -- Mountaineer Thar
2469, -- Mountaineer Rharen
2470, -- Watcher Fraizer
2506, -- Mountaineer Harn
2507, -- Mountaineer Uthan
2508, -- Mountaineer Wuar
2509, -- Mountaineer Cragg
2510, -- Mountaineer Ozmok
2511, -- Mountaineer Bludd
2512, -- Mountaineer Roghan
2513, -- Mountaineer Janha
2514, -- Mountaineer Modax
2515, -- Mountaineer Fazgard
2516, -- Mountaineer Kamdar
2517, -- Mountaineer Langarr
2518, -- Mountaineer Swarth
2520, -- Remote-Controlled Golem
2524, -- Mountaineer Haggis
2525, -- Mountaineer Barn
2526, -- Mountaineer Morlic
2527, -- Mountaineer Angst
2528, -- Mountaineer Haggil
2608, -- Commander Amaren
2616, -- Privateer Groy
2676, -- Compact Harvest Reaper
2706, -- Tor\'gan
2712, -- Quae
2775, -- Daggerspine Marauder
2787, -- Zaruk
2817, -- Rigglefuzz
2852, -- Enslaved Druid of the Talon
2860, -- Sigrun Ironhew
2870, -- [UNUSED] Henria Derth
2930, -- Sentinel Glynda Nal\'Shea
2984, -- Seer Wiserunner
3193, -- Misha Tor\'kren
3338, -- Sergra Darkthorn
3341, -- Gann Stonespire
3388, -- Mahren Skyseer
3389, -- Regthar Deathgate
3421, -- Feegly the Exiled
3431, -- Grenthar
3448, -- Tonga Runetotem
3450, -- Defias Companion
3464, -- Gazrog
3465, -- Gilthares Firebough
3501, -- Horde Guard
3617, -- Lordaeron Citizen
3659, -- Jorb
3663, -- Delgren the Purifier
3691, -- Raene Wolfrunner
3692, -- Volcor
3693, -- Terenthis
3694, -- Sentinel Selarin
3695, -- Grimclaw
3702, -- Alanndarian Nightsong
3844, -- Healing Ward IV
3846, -- Talen
3897, -- Krolg
3916, -- Shael\'dryn
3939, -- Razormane Wolf
3981, -- Vorrel Sengutz
3990, -- Venture Co. Cutter
3994, -- Keeper Albagorm
4033, -- Charred Stone Spirit
4048, -- Falfindel Waywarder
4080, -- Kaela Shadowspear
4489, -- Braug Dimspirit
4510, -- Heralath Fallowbrook
4535, -- Tamed Battleboar
4661, -- Gelkis Rumbler
4787, -- Argent Guard Thaelrid
4966, -- Private Hendel
4977, -- Murkshallow Softshell
4979, -- Theramore Guard
4983, -- Ogron
4995, -- Stockade Guard
5058, -- Wolfguard Worg
5389, -- Prospector Gunstan
5414, -- Apothecary Faustin
5418, -- Deathstalker Zraedus
5433, -- Tamed Bear
5440, -- Tamed Crocolisk
5476, -- Watcher Biggs
5546, -- Grunt Zuul
5644, -- Dalinda Malem
5723, -- Warug\'s Target Dummy
5780, -- Cloned Ectoplasm
5781, -- Silithid Creeper Egg
5899, -- Brine
6013, -- Wayward Buzzard
6019, -- Hornizz Brimbuzzle
6047, -- Aqua Guardian
6086, -- Auberdine Sentinel
6087, -- Astranaar Sentinel
6141, -- Pridewing Soarer
6244, -- Takar the Seer
6250, -- Crawler
6388, -- Zanzil Skeleton
6667, -- Gelkak Gyromast
6669, -- The Threshwackonator 4100
7051, -- Malformed Defias Drone
7067, -- Venture Co. Drone
7168, -- Polly
7233, -- Taskmaster Fizzule
7287, -- Foreman Silixiz
7360, -- Dun Garok Soldier
7395, -- Cockroach
7489, -- Silverpine Deathguard
7549, -- Tree Frog
7607, -- Weegli Blastfuse
7730, -- Stonetalon Grunt
7765, -- Rockbiter
7767, -- Witherbark Felhunter
7768, -- Witherbark Bloodling
7865, -- Wildhammer Sentry
7915, -- Walking Bomb
7939, -- Feathermoon Sentinel
7957, -- Jer\'kai Moonweaver
7975, -- Mulgore Protector
7980, -- Deathguard Elite
7999, -- Tyrande Whisperwind
8015, -- Ashenvale Sentinel
8016, -- Barrens Guard
8017, -- Sen\'jin Guardian
8055, -- Thelsamar Mountaineer
8096, -- Protector of the People
8147, -- Camp Mojache Brave
8154, -- Ghost Walker Brave
8155, -- Kargath Grunt
8179, -- Greater Healing Ward
8310, -- Watcher Wollpert
8386, -- Horizon Scout Crewman
8402, -- Enslaved Archaeologist
8581, -- Blood Elf Defender
8608, -- Angered Infernal
8996, -- Voidwalker Minion
9118, -- Larion
9119, -- Muigin
9157, -- Bloodpetal Pest
9316, -- Wenikee Boltbucket
9525, -- Freewind Brave
9598, -- Arei
9676, -- Tink Sprocketwhistle
10000, -- Arugal
10036, -- Brackenwall Enforcer
10037, -- Lakeshire Guard
10038, -- Night Watch Guard
10260, -- Kibler
10261, -- Burning Felhound
10262, -- Opus
10321, -- Emberstrife
10427, -- Pao\'ka Swiftmountain
10428, -- Motega Firemane
10482, -- Risen Lackey
10619, -- Glacier
10638, -- Kanati Greycloud
10684, -- Remorseful Highborne
10696, -- Refuge Pointe Defender
10698, -- Summoned Zombie
10928, -- Succubus Minion
10940, -- Ghost of the Past
10941, -- Wizlo Bearingshiner
10951, -- Marauding Corpse
10979, -- Scarlet Hound
11040, -- Watcher Brownell
11053, -- High Priestess MacDonnell
11141, -- Spirit of Trey Lightforge
11145, -- Myolor Sunderfury
11180, -- Bloodvenom Post Brave
11195, -- Skeletal Black Warhorse
11276, -- Azshara Sentinel
11328, -- Eastvale Peasant
11347, -- Zealot Lor\'Khan
11460, -- Alzzin\'s Minion
11609, -- Alexia Ironknife
11615, -- Mickey Levine
11690, -- Gnarlpine Instigator
11701, -- Mor\'vek
11713, -- Blackwood Tracker
11718, -- Sar Browneye
11748, -- Samantha Swifthoof
11806, -- Sentinel Onaeya
11820, -- Locke Okarr
11856, -- Kaya Flathoof
11920, -- Goggeroc
11979, -- Kim Bridenbecker
11994, -- Rob Bridenbecker
12160, -- Shadowglen Sentinel
12657, -- Don Pompa
12658, -- Adam Lind
12736, -- Je\'neu Sancrea
12858, -- Torek
12859, -- Splintertree Raider
12862, -- Warsong Scout
12863, -- Warsong Runner
12903, -- Splintertree Guard
13118, -- Crimson Bodyguard
13159, -- James Clark
13533, -- Spewed Larva
13736, -- Noxxious Essence
13817, -- Voggah Deathgrip
14370, -- Cadaverous Worm
14372, -- Winterfall Ambusher
14385, -- Doomguard Minion
14872, -- Trok
14983, -- Field Marshal Oslight
14987, -- Powerful Healing Ward
14988, -- Ohgan
15041, -- Spawn of Mar\'li
15112, -- Brain Wash Totem
15117, -- Chained Spirit
15146, -- Mad Voidwalker
15288, -- Aluntir
15290, -- Arakis
15443, -- Janela Stouthammer
15449, -- Hive\'Zora Abomination
15505, -- Canal Frenzy
15620, -- Hive\'Regal Hunter-Killer
16135, -- Rayne
20555, -- Goc
20918, -- Deathforge Felstalker
21627);  -- Eclipsion Hawkstrider

UPDATE `creature_template` SET `LootId` = 0 WHERE `entry` IN
(8257,10717,10461,10536,10441,20117,
3083, -- Honor Guard
6021, -- Boar Spirit
8257, -- Oozeling
10636, -- Pack Kodo
10925, -- Rotting Worm
10943, -- Decrepit Guardian
11054, -- Crimson Rifleman
20158, -- Slime-Covered Corpse
21040, -- Outraged Raven\'s Wood Sapling
128, -- Angry Programmer Tweedle Dee
197, -- Marshal McBride
235, -- Salma Saldean
240, -- Marshal Dughan
246, -- \"Auntie\" Bernice Stonefield
255, -- Gerard Tiller
266, -- Wiley the Black
275, -- Whit Wantmal
288, -- Jitters
313, -- Theocritus
325, -- Hogan Ference
341, -- Foreman Oslow
358, -- Riding Wolf (Brown)
359, -- Riding Wolf (Winter)
379, -- Darcy
381, -- Dockmaster Baren
382, -- Marshal Marris
415, -- Verner Osgood
416, -- Imp
417, -- Felhunter
466, -- General Marcus Jonathan
467, -- The Defias Traitor
468, -- Town Crier
469, -- Lieutenant Doren
487, -- Protector Bialon
488, -- Protector Weaver
489, -- Protector Dutfield
490, -- Protector Gariel
494, -- Watcher Bukouris
495, -- Watcher Keefer
499, -- Watcher Paige
659, -- El Pollo Grande
698, -- Bloodscalp Tiger
754, -- Rebel Watchman
756, -- Skullsplitter Panther
826, -- Watcher Jan
827, -- Watcher Mocarski
828, -- Watcher Petras
853, -- Coldridge Mountaineer
866, -- Stonard Grunt
867, -- Stonard Cartographer
869, -- Protector Dorana
870, -- Protector Deni
874, -- Protector Korelor
876, -- Protector Leick
885, -- Watcher Keller
886, -- Watcher Hartin
887, -- Watcher Jordan
888, -- Watcher Dodds
932, -- Guard Ashlock
933, -- Guard Hiett
934, -- Guard Clarke
935, -- Guard Pearce
936, -- Guard Adams
999, -- Watcher Royce
1001, -- Watcher Hutchins
1064, -- Grom\'gol Grunt
1066, -- Mottled Riptooth
1071, -- Longbraid the Grim
1073, -- Ashlan Stonesmirk
1093, -- Chief Engineer Hinderweir VII
1099, -- Watcher Gelwin
1244, -- Rethiel the Greenwarden
1245, -- Kogan Forgestone
1276, -- Mountaineer Brokk
1277, -- Mountaineer Ganin
1278, -- Mountaineer Stenn
1279, -- Mountaineer Flint
1280, -- Mountaineer Droken
1281, -- Mountaineer Zaren
1282, -- Mountaineer Veek
1283, -- Mountaineer Kalmir
1327, -- Reese Langston
1329, -- Mountaineer Naarh
1330, -- Mountaineer Tyraw
1331, -- Mountaineer Luxst
1332, -- Mountaineer Morran
1334, -- Mountaineer Hammerfall
1335, -- Mountaineer Yuttha
1336, -- Mountaineer Zwarn
1337, -- Mountaineer Gwarth
1338, -- Mountaineer Dalk
1374, -- Rejold Barleybrew
1414, -- Lisan Pierce
1434, -- Menethil Sentry
1436, -- Watcher Cutford
1437, -- Thomas Booker
1476, -- Hargin Mundar
1477, -- Christoph Faral
1481, -- Bart Tidewater
1483, -- Murphy West
1497, -- Gunther Arcanus
1503, -- Wretched Zombie
1511, -- Enraged Silverback Gorilla
1516, -- Konda
1642, -- Northshire Guard
1679, -- Avarus Kharag
1733, -- Zggi
1741, -- Deathguard Bartrand
1756, -- Stormwind Royal Guard
1777, -- Dakk Blunderblast
1975, -- Eastvale Lumberjack
2044, -- Forlorn Spirit
2045, -- Gunther\'s Minion
2055, -- Master Apothecary Faranell
2058, -- Deathstalker Faerleia
2099, -- Maiden\'s Virtue Crewman
2105, -- Mountaineer Dokkin
2112, -- Farrin Daris
2153, -- Terl Arakor
2214, -- Deathstalker Lesh
2238, -- Tog\'thar
2239, -- Drull
2316, -- Gol\'dir
2333, -- Henchman Valik
2361, -- Tamara Armstrong
2362, -- Hemmit Armstrong
2363, -- Apprentice Honeywell
2378, -- Kundric Zanden
2379, -- Caretaker Smithers
2386, -- Southshore Guard
2392, -- Delia Verana
2395, -- Vinna Wayne
2396, -- Hans Zandin
2400, -- Craig Hewitt
2402, -- Shara Blazen
2466, -- Mountaineer Grugelm
2468, -- Mountaineer Thar
2469, -- Mountaineer Rharen
2470, -- Watcher Fraizer
2506, -- Mountaineer Harn
2507, -- Mountaineer Uthan
2508, -- Mountaineer Wuar
2509, -- Mountaineer Cragg
2510, -- Mountaineer Ozmok
2511, -- Mountaineer Bludd
2512, -- Mountaineer Roghan
2513, -- Mountaineer Janha
2514, -- Mountaineer Modax
2515, -- Mountaineer Fazgard
2516, -- Mountaineer Kamdar
2517, -- Mountaineer Langarr
2518, -- Mountaineer Swarth
2520, -- Remote-Controlled Golem
2524, -- Mountaineer Haggis
2525, -- Mountaineer Barn
2526, -- Mountaineer Morlic
2527, -- Mountaineer Angst
2528, -- Mountaineer Haggil
2608, -- Commander Amaren
2616, -- Privateer Groy
2676, -- Compact Harvest Reaper
2706, -- Tor\'gan
2712, -- Quae
2775, -- Daggerspine Marauder
2787, -- Zaruk
2817, -- Rigglefuzz
2852, -- Enslaved Druid of the Talon
2860, -- Sigrun Ironhew
2870, -- [UNUSED] Henria Derth
2930, -- Sentinel Glynda Nal\'Shea
2984, -- Seer Wiserunner
3193, -- Misha Tor\'kren
3338, -- Sergra Darkthorn
3341, -- Gann Stonespire
3388, -- Mahren Skyseer
3389, -- Regthar Deathgate
3421, -- Feegly the Exiled
3431, -- Grenthar
3448, -- Tonga Runetotem
3450, -- Defias Companion
3464, -- Gazrog
3465, -- Gilthares Firebough
3501, -- Horde Guard
3617, -- Lordaeron Citizen
3659, -- Jorb
3663, -- Delgren the Purifier
3691, -- Raene Wolfrunner
3692, -- Volcor
3693, -- Terenthis
3694, -- Sentinel Selarin
3695, -- Grimclaw
3702, -- Alanndarian Nightsong
3844, -- Healing Ward IV
3846, -- Talen
3897, -- Krolg
3916, -- Shael\'dryn
3939, -- Razormane Wolf
3981, -- Vorrel Sengutz
3990, -- Venture Co. Cutter
3994, -- Keeper Albagorm
4033, -- Charred Stone Spirit
4048, -- Falfindel Waywarder
4080, -- Kaela Shadowspear
4489, -- Braug Dimspirit
4510, -- Heralath Fallowbrook
4535, -- Tamed Battleboar
4661, -- Gelkis Rumbler
4787, -- Argent Guard Thaelrid
4966, -- Private Hendel
4977, -- Murkshallow Softshell
4979, -- Theramore Guard
4983, -- Ogron
4995, -- Stockade Guard
5058, -- Wolfguard Worg
5389, -- Prospector Gunstan
5414, -- Apothecary Faustin
5418, -- Deathstalker Zraedus
5433, -- Tamed Bear
5440, -- Tamed Crocolisk
5476, -- Watcher Biggs
5546, -- Grunt Zuul
5644, -- Dalinda Malem
5723, -- Warug\'s Target Dummy
5780, -- Cloned Ectoplasm
5781, -- Silithid Creeper Egg
5899, -- Brine
6013, -- Wayward Buzzard
6019, -- Hornizz Brimbuzzle
6047, -- Aqua Guardian
6086, -- Auberdine Sentinel
6087, -- Astranaar Sentinel
6141, -- Pridewing Soarer
6244, -- Takar the Seer
6250, -- Crawler
6388, -- Zanzil Skeleton
6667, -- Gelkak Gyromast
6669, -- The Threshwackonator 4100
7051, -- Malformed Defias Drone
7067, -- Venture Co. Drone
7168, -- Polly
7233, -- Taskmaster Fizzule
7287, -- Foreman Silixiz
7360, -- Dun Garok Soldier
7395, -- Cockroach
7489, -- Silverpine Deathguard
7549, -- Tree Frog
7607, -- Weegli Blastfuse
7730, -- Stonetalon Grunt
7765, -- Rockbiter
7767, -- Witherbark Felhunter
7768, -- Witherbark Bloodling
7865, -- Wildhammer Sentry
7915, -- Walking Bomb
7939, -- Feathermoon Sentinel
7957, -- Jer\'kai Moonweaver
7975, -- Mulgore Protector
7980, -- Deathguard Elite
7999, -- Tyrande Whisperwind
8015, -- Ashenvale Sentinel
8016, -- Barrens Guard
8017, -- Sen\'jin Guardian
8055, -- Thelsamar Mountaineer
8096, -- Protector of the People
8147, -- Camp Mojache Brave
8154, -- Ghost Walker Brave
8155, -- Kargath Grunt
8179, -- Greater Healing Ward
8310, -- Watcher Wollpert
8386, -- Horizon Scout Crewman
8402, -- Enslaved Archaeologist
8581, -- Blood Elf Defender
8608, -- Angered Infernal
8996, -- Voidwalker Minion
9118, -- Larion
9119, -- Muigin
9157, -- Bloodpetal Pest
9316, -- Wenikee Boltbucket
9525, -- Freewind Brave
9598, -- Arei
9676, -- Tink Sprocketwhistle
10000, -- Arugal
10036, -- Brackenwall Enforcer
10037, -- Lakeshire Guard
10038, -- Night Watch Guard
10260, -- Kibler
10261, -- Burning Felhound
10262, -- Opus
10321, -- Emberstrife
10427, -- Pao\'ka Swiftmountain
10428, -- Motega Firemane
10482, -- Risen Lackey
10619, -- Glacier
10638, -- Kanati Greycloud
10684, -- Remorseful Highborne
10696, -- Refuge Pointe Defender
10698, -- Summoned Zombie
10928, -- Succubus Minion
10940, -- Ghost of the Past
10941, -- Wizlo Bearingshiner
10951, -- Marauding Corpse
10979, -- Scarlet Hound
11040, -- Watcher Brownell
11053, -- High Priestess MacDonnell
11141, -- Spirit of Trey Lightforge
11145, -- Myolor Sunderfury
11180, -- Bloodvenom Post Brave
11195, -- Skeletal Black Warhorse
11276, -- Azshara Sentinel
11328, -- Eastvale Peasant
11347, -- Zealot Lor\'Khan
11460, -- Alzzin\'s Minion
11609, -- Alexia Ironknife
11615, -- Mickey Levine
11690, -- Gnarlpine Instigator
11701, -- Mor\'vek
11713, -- Blackwood Tracker
11718, -- Sar Browneye
11748, -- Samantha Swifthoof
11806, -- Sentinel Onaeya
11820, -- Locke Okarr
11856, -- Kaya Flathoof
11920, -- Goggeroc
11979, -- Kim Bridenbecker
11994, -- Rob Bridenbecker
12160, -- Shadowglen Sentinel
12657, -- Don Pompa
12658, -- Adam Lind
12736, -- Je\'neu Sancrea
12858, -- Torek
12859, -- Splintertree Raider
12862, -- Warsong Scout
12863, -- Warsong Runner
12903, -- Splintertree Guard
13118, -- Crimson Bodyguard
13159, -- James Clark
13533, -- Spewed Larva
13736, -- Noxxious Essence
13817, -- Voggah Deathgrip
14370, -- Cadaverous Worm
14372, -- Winterfall Ambusher
14385, -- Doomguard Minion
14872, -- Trok
14983, -- Field Marshal Oslight
14987, -- Powerful Healing Ward
14988, -- Ohgan
15041, -- Spawn of Mar\'li
15112, -- Brain Wash Totem
15117, -- Chained Spirit
15146, -- Mad Voidwalker
15288, -- Aluntir
15290, -- Arakis
15443, -- Janela Stouthammer
15449, -- Hive\'Zora Abomination
15505, -- Canal Frenzy
15620, -- Hive\'Regal Hunter-Killer
16135, -- Rayne
20555, -- Goc
20918, -- Deathforge Felstalker
21627);  -- Eclipsion Hawkstrider

-- Bonestripper Buzzard (16972) - Should Be Properly Flying
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (16972);

-- Prevent Cannon NPC From Moving
-- Fel Cannon SAI
SET @ENTRY := 19399;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Cannon - On Reset - Enable Combat Movement");

-- Legion Fel Cannon MKII SAI
SET @ENTRY := 22451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legion Fel Cannon MKII - On Respawn - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,1000,500,5000,11,36238,1,0,0,0,0,2,0,0,0,0,0,0,0,"Legion Fel Cannon MKII - In Combat - Cast 'Fel Cannon Blast'");

-- Remove wrong spawned Buzzard
/*
DELETE FROM `creature` WHERE `guid` = 6998;
*/
-- Update Position for one Buzzard
/*
UPDATE `creature` SET `position_x` = -6662.029785, `position_y` = -3660.025391, `position_z` = 255.250671, `orientation` = 6.218313 WHERE `guid` = 7607;
*/
-- Remove Non-Existant Loot - Weird Loot Drop
DELETE FROM `creature_loot_template` WHERE `entry` IN (255);
UPDATE `creature_template` SET `LootId` = 0 WHERE `LootId` IN (255);

-- Fix Plans: Ragesteel Shoulders To Drop More Blizzlike - (Current Rates are wowhead and these only drop for Blacksmith Players)
UPDATE `creature_loot_template` SET `Chance` = 1 WHERE `item` = 33174 AND `entry` IN (21050,21061);
UPDATE `creature_loot_template` SET `Chance` = 0.5 WHERE `item` = 33174 AND `entry` IN (21059,21060);
-- Fix Plans: Ragesteel Helm To Drop More Blizzlike - (Current Rates are wowhead and these only drop for Blacksmith Players)
UPDATE `creature_loot_template` SET `Chance` = 4 WHERE `item` = 23612 AND `entry` IN (16952);
UPDATE `creature_loot_template` SET `Chance` = 1 WHERE `item` = 23612 AND `entry` IN (21060,21061);
-- Fix Plans: Ragesteel Breastplate To Drop More Blizzlike - (Current Rates are wowhead and these only drop for Blacksmith Players)
UPDATE `creature_loot_template` SET `Chance` = 4 WHERE `item` = 23613 AND `entry` IN (21454);
UPDATE `creature_loot_template` SET `Chance` = 1 WHERE `item` = 23613 AND `entry` IN (23324,23305);

-- Fix Movement Speed of Ranging Flames in Mechanar - 4.3.4 Sniff Data
UPDATE `creature_template` SET `Speed_Walk` = 1 WHERE `entry` = 20481;
UPDATE `creature_template` SET `Speed_Walk` = 1 WHERE `entry` = 21538;

-- Remove Troll-Hide Bag Drops From NPC Not Level 40-52 Range
DELETE FROM `creature_loot_template` WHERE `item` = 1685 AND `entry` IN (2852,2850,7011,9445,10981,4853,7321,7320,7030,7397,4860,7396);

-- Fix Hoard of the Black Dragonflight - Should Always Drop Black Dragonflight Molt
UPDATE `item_loot_template` SET `Chance`=100 WHERE  `Entry`=10569 AND `Item`=10575;

-- Remove Boss Plans Drops From Normal NPC Loot
DELETE FROM `creature_loot_template` WHERE `item` IN (22388,22389,22390);

-- Oronok Torn-heart SAI - Add 'Chain Lightning'
SET @ENTRY := 21183;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,0,0,100,0,6700,11200,18100,24900,11,16006,64,0,0,0,0,2,0,0,0,0,0,0,0,"Oronok Torn-heart - In Combat - Cast 'Chain Lightning'");

-- DELETE Miniscule Diamond Ring FROM CHEST LOOT (VENDOR ITEM ONLY)
DELETE FROM `gameobject_loot_template` WHERE `item` IN (7339);


-- NOTE! be carefull with this unitflags 32768. Implement NPC Swimming Proper Animations
UPDATE `creature_template` SET `Unit_Flags`=`Unit_Flags`|32768 WHERE `InhabitType` IN (2);
