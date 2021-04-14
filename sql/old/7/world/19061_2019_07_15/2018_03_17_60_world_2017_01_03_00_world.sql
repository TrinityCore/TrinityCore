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

-- All Mechanical NPC Are Immune To Bleed Effects  
-- UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|16384 WHERE `type` = 9;

-- DB/Creature: Anathemus - Movement
/*
SET @NPC := 27567;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -7095.56, -2718.91, 241.823),
(@PATH, 2, -7067.39, -2756.06, 242.343),
(@PATH, 3, -7037.44, -2790.59, 241.668),
(@PATH, 4, -7018.55, -2835.34, 244.453),
(@PATH, 5, -6984.54, -2869.52, 243.404),
(@PATH, 6, -6938.39, -2890.16, 241.667),
(@PATH, 7, -6905.93, -2928.64, 245.614),
(@PATH, 8, -6854.77, -2984.54, 244.127),
(@PATH, 9, -6836.56, -3004.44, 242.001),
(@PATH, 10, -6807.97, -3077.38, 241.258),
(@PATH, 11, -6787.47, -3129.66, 240.549),
(@PATH, 12, -6764.01, -3175.88, 240.743),
(@PATH, 13, -6745.73, -3211.91, 240.743),
(@PATH, 14, -6708.56, -3249.22, 240.743),
(@PATH, 15, -6693.82, -3306.64, 240.985),
(@PATH, 16, -6720.17, -3363.87, 241.645),
(@PATH, 17, -6774.04, -3394.9, 241.667),
(@PATH, 18, -6846.93, -3401.71, 241.762),
(@PATH, 19, -6905.98, -3407.23, 243.235),
(@PATH, 20, -6961.35, -3397.87, 241.796),
(@PATH, 21, -6999.34, -3391.44, 241.667),
(@PATH, 22, -7039.67, -3397.01, 243.935),
(@PATH, 23, -7064.13, -3400.84, 245.275),
(@PATH, 24, -7110.78, -3375.07, 242.97),
(@PATH, 25, -7113.36, -3322.06, 242.365),
(@PATH, 26, -7098.28, -3284.59, 242.883),
(@PATH, 27, -7095.63, -3246.03, 242.983),
(@PATH, 28, -7085.7, -3202.78, 241.97),
(@PATH, 29, -7072.35, -3144.63, 241.67),
(@PATH, 30, -7061.88, -3098.99, 242.684),
(@PATH, 31, -7015.89, -3040.38, 242.25),
(@PATH, 32, -6970.5, -2981.02, 241.666),
(@PATH, 33, -6934.33, -2905.91, 241.816),
(@PATH, 34, -6913.11, -2861.83, 241.894),
(@PATH, 35, -6874.86, -2825.65, 241.667),
(@PATH, 36, -6859.87, -2776.27, 241.975),
(@PATH, 37, -6842.13, -2717.85, 241.729),
(@PATH, 38, -6846.45, -2667.72, 241.51),
(@PATH, 39, -6851.46, -2607.44, 240.745),
(@PATH, 40, -6852.08, -2566.73, 240.743),
(@PATH, 41, -6880.82, -2550.47, 240.743),
(@PATH, 42, -6920.74, -2512.13, 240.743),
(@PATH, 43, -6957.01, -2459.73, 240.743),
(@PATH, 44, -6968.86, -2436.17, 240.743),
(@PATH, 45, -6985.18, -2427.13, 242.407),
(@PATH, 46, -7032.28, -2403.95, 240.308),
(@PATH, 47, -7070.29, -2406.17, 243.718),
(@PATH, 48, -7132.2, -2394.94, 241.667),
(@PATH, 49, -7165.06, -2398.26, 240.663),
(@PATH, 50, -7188.31, -2426.48, 242.147),
(@PATH, 51, -7194.06, -2475.31, 245.94),
(@PATH, 52, -7197.13, -2523.31, 248.631),
(@PATH, 53, -7185.88, -2555.67, 245.846),
(@PATH, 54, -7191.35, -2594.02, 246.023),
(@PATH, 55, -7175.23, -2639.84, 244.411),
(@PATH, 56, -7164.76, -2655.17, 243.481),
(@PATH, 57, -7143.76, -2663.97, 241.977),
(@PATH, 58, -7120.74, -2667.13, 241.845);
*/

-- Somnus Rare NPC Movement 
/*
UPDATE `creature` SET `position_x` = -10666, `position_y` = -3923, `position_z` = 18.438, `orientation` = 6.218313 WHERE `guid` = 42880;
SET @NPC := 42880;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH,1,-10666,-3923,18.438),
(@PATH,2,-10674.5,-3909.81,17.3732),
(@PATH,3,-10703.7,-3916.17,17.3732),
(@PATH,4,-10770,-4007.98,17.9099),
(@PATH,5,-10722.1,-4038.75,17.6482),
(@PATH,6,-10654.9,-4061.03,17.3742),
(@PATH,7,-10591.6,-4027.09,17.3742),
(@PATH,8,-10568.6,-4002.12,17.3853),
(@PATH,9,-10575.8,-3978.89,17.4333),
(@PATH,10,-10624.2,-3924.85,17.5842);
*/

-- Rok'Alim the Pounder -- Pathing
/*
SET @NPC := 21591;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -5204.92, -1565.98, -48.1972),
(@PATH, 2, -5214.62, -1555.88, -49.2243),
(@PATH, 3, -5230.7, -1546.65, -49.3283),
(@PATH, 4, -5241.37, -1540.68, -50.6353),
(@PATH, 5, -5257.24, -1534.29, -51.2466),
(@PATH, 6, -5269.84, -1529.99, -52.025),
(@PATH, 7, -5282.4, -1525.82, -53.1763),
(@PATH, 8, -5288.3, -1522.98, -56.4051),
(@PATH, 9, -5286.83, -1503.93, -56.481),
(@PATH, 10, -5270.15, -1482.05, -56.3993),
(@PATH, 11, -5254.26, -1461.2, -56.0616),
(@PATH, 12, -5241.19, -1442.79, -55.4567),
(@PATH, 13, -5221.53, -1416.03, -53.8072),
(@PATH, 14, -5198.85, -1395.52, -52.7577),
(@PATH, 15, -5181.67, -1374.63, -51.8565),
(@PATH, 16, -5169.68, -1349.39, -50.6463),
(@PATH, 17, -5154.09, -1328.35, -49.6798),
(@PATH, 18, -5133.36, -1309.61, -49.4684),
(@PATH, 19, -5128.83, -1305.52, -49.5074),
(@PATH, 20, -5116.85, -1280.28, -49.9129),
(@PATH, 21, -5102.61, -1250.27, -49.9234),
(@PATH, 22, -5092.12, -1228.17, -52.6244),
(@PATH, 23, -5069.58, -1197.09, -55.3233),
(@PATH, 24, -5062.96, -1184.76, -56.1412),
(@PATH, 25, -5039.98, -1165.97, -56.9965),
(@PATH, 26, -5016.58, -1158.92, -55.1305),
(@PATH, 27, -5006.19, -1139.71, -52.2228),
(@PATH, 28, -4991.9, -1125.57, -50.647),
(@PATH, 29, -4960.86, -1102.84, -52.0625),
(@PATH, 30, -4946.76, -1092.52, -52.4456),
(@PATH, 31, -4928.1, -1087.96, -53.0811),
(@PATH, 32, -4911.55, -1088.84, -54.6845),
(@PATH, 33, -4892.69, -1085.17, -58.7394),
(@PATH, 34, -4862.62, -1069.22, -58.5493),
(@PATH, 35, -4841.79, -1058.18, -58.3265),
(@PATH, 36, -4832.77, -1054.99, -58.5381),
(@PATH, 37, -4810.17, -1040.02, -58.7495),
(@PATH, 38, -4781.03, -1020.73, -58.7479),
(@PATH, 39, -4763.55, -1010.94, -58.3438),
(@PATH, 40, -4745.84, -1003.38, -58.7489),
(@PATH, 41, -4731.81, -989.059, -56.4676),
(@PATH, 42, -4718.22, -969.831, -52.847),
(@PATH, 43, -4702.23, -952.577, -50.7703),
(@PATH, 44, -4687.36, -943.465, -49.807),
(@PATH, 45, -4676.14, -938.654, -49.1061),
(@PATH, 46, -4664.32, -929.672, -50.7595),
(@PATH, 47, -4638.64, -916.618, -56.6334),
(@PATH, 48, -4625.96, -902.198, -54.0504),
(@PATH, 49, -4617.08, -882.245, -51.521),
(@PATH, 50, -4597.35, -850.377, -53.6356),
(@PATH, 51, -4579.89, -855.902, -52.0292),
(@PATH, 52, -4589.98, -867.978, -52.0226),
(@PATH, 53, -4601.74, -889.439, -50.6814),
(@PATH, 54, -4605.17, -901.682, -52.4203),
(@PATH, 55, -4610.44, -918.339, -57.6121),
(@PATH, 56, -4606.58, -931.714, -56.7672),
(@PATH, 57, -4596.94, -945.123, -52.9157),
(@PATH, 58, -4581.9, -955.52, -50.9032),
(@PATH, 59, -4572.11, -966.669, -49.0426),
(@PATH, 60, -4560.31, -987.143, -54.2615),
(@PATH, 61, -4541.68, -1003.01, -54.449),
(@PATH, 62, -4552.6, -1011.68, -55.3938),
(@PATH, 63, -4553.95, -1015.83, -55.5415),
(@PATH, 64, -4551.73, -1033.16, -56.3598),
(@PATH, 65, -4554.74, -1051.2, -55.7008),
(@PATH, 66, -4576.43, -1062.38, -52.3882),
(@PATH, 67, -4595.78, -1072.35, -47.8427),
(@PATH, 68, -4614.09, -1084.25, -50.2251),
(@PATH, 69, -4635.17, -1096.57, -53.1295),
(@PATH, 70, -4655.15, -1116.11, -54.7833),
(@PATH, 71, -4670.11, -1111.43, -52.6073),
(@PATH, 72, -4696.82, -1098.49, -52.938),
(@PATH, 73, -4708.96, -1097.21, -54.7856),
(@PATH, 74, -4727.26, -1112.01, -50.8514),
(@PATH, 75, -4730.2, -1135.72, -42.7862),
(@PATH, 76, -4734.1, -1146.39, -39.9821),
(@PATH, 77, -4742.57, -1153.98, -39.8057),
(@PATH, 78, -4748.47, -1163.7, -41.1494),
(@PATH, 79, -4753.23, -1182.36, -46.3681),
(@PATH, 80, -4754.96, -1211.99, -53.963),
(@PATH, 81, -4745.96, -1249.27, -54.0574),
(@PATH, 82, -4746.93, -1265.88, -52.9851),
(@PATH, 83, -4754.48, -1290.02, -48.5838),
(@PATH, 84, -4764.33, -1304.45, -48.6753),
(@PATH, 85, -4769.15, -1327.53, -49.0466),
(@PATH, 86, -4775, -1341.23, -53.1682),
(@PATH, 87, -4778.21, -1369.85, -53.8389),
(@PATH, 88, -4786.3, -1377.76, -53.4634),
(@PATH, 89, -4804.32, -1371.1, -54.4526),
(@PATH, 90, -4830.07, -1375.97, -53.9953),
(@PATH, 91, -4863.88, -1412.53, -52.4747),
(@PATH, 92, -4876.27, -1423.62, -50.5087),
(@PATH, 93, -4883.91, -1453.15, -50.5943),
(@PATH, 94, -4875.09, -1489.66, -47.697),
(@PATH, 95, -4868.9, -1500.25, -47.3607),
(@PATH, 96, -4864.04, -1520.62, -47.5608),
(@PATH, 97, -4840.64, -1540.3, -47.1878),
(@PATH, 98, -4813.21, -1563.37, -49.0607),
(@PATH, 99, -4798.37, -1586.05, -51.2704),
(@PATH, 100, -4797.3, -1611.32, -49.8867),
(@PATH, 101, -4802.75, -1637.81, -49.9839),
(@PATH, 102, -4811.28, -1665.36, -50.9323),
(@PATH, 103, -4829.82, -1672.43, -47.6692),
(@PATH, 104, -4850.17, -1677.41, -38.4677),
(@PATH, 105, -4868.01, -1681.78, -33.1823),
(@PATH, 106, -4885.85, -1686.15, -35.8888),
(@PATH, 107, -4907.88, -1691.54, -45.483),
(@PATH, 108, -4922.81, -1704.92, -53.1108),
(@PATH, 109, -4937.51, -1726.61, -57.509),
(@PATH, 110, -4969.21, -1749.86, -60.1434),
(@PATH, 111, -4994.72, -1763.31, -64.3609),
(@PATH, 112, -5028.79, -1764.86, -65.5336),
(@PATH, 113, -5065.95, -1759.59, -66.5919),
(@PATH, 114, -5093.52, -1770.39, -62.2996),
(@PATH, 115, -5105.65, -1775.34, -61.0208),
(@PATH, 116, -5123.93, -1792.82, -57.2378),
(@PATH, 117, -5149.56, -1806.05, -57.8151),
(@PATH, 118, -5173.42, -1831.56, -58.1518),
(@PATH, 119, -5186.01, -1870.63, -57.7254),
(@PATH, 120, -5197.27, -1905.54, -57.034),
(@PATH, 121, -5211.94, -1929.84, -62.5757),
(@PATH, 122, -5217.61, -1963.41, -63.2077),
(@PATH, 123, -5213.49, -1995.46, -61.1058),
(@PATH, 124, -5224.94, -2025.67, -60.3056),
(@PATH, 125, -5267.7, -2047.58, -61.7613),
(@PATH, 126, -5298.28, -2054.79, -60.6321),
(@PATH, 127, -5335.13, -2041.09, -61.2567),
(@PATH, 128, -5370.89, -2042.4, -62.2819),
(@PATH, 129, -5404.02, -2043.62, -63.9917),
(@PATH, 130, -5427.96, -2038.56, -64.7203),
(@PATH, 131, -5443.81, -2022.38, -63.5722),
(@PATH, 132, -5460.12, -1994.54, -58.3875),
(@PATH, 133, -5478.17, -1979.38, -58.9688),
(@PATH, 134, -5501.73, -1950.11, -60.4141),
(@PATH, 135, -5524.73, -1937.53, -59.9879),
(@PATH, 136, -5533.82, -1917.68, -59.0687),
(@PATH, 137, -5530.9, -1890.73, -58.5037),
(@PATH, 138, -5520.29, -1865.83, -57.9582),
(@PATH, 139, -5516.68, -1848.78, -57.2414),
(@PATH, 140, -5506.58, -1830.44, -56.6996),
(@PATH, 141, -5491.7, -1830.59, -56.4063),
(@PATH, 142, -5470.03, -1839.83, -54.3328),
(@PATH, 143, -5457.09, -1829.48, -50.7656),
(@PATH, 144, -5463.51, -1817.04, -48.0715),
(@PATH, 145, -5481.32, -1806.02, -49.6301),
(@PATH, 146, -5483.3, -1791.35, -45.245),
(@PATH, 147, -5480.45, -1769.64, -33.9141),
(@PATH, 148, -5475.24, -1759.54, -25.6579),
(@PATH, 149, -5471.3, -1747.98, -19.724),
(@PATH, 150, -5469.04, -1741.36, -17.7276),
(@PATH, 151, -5465.97, -1728.89, -21.8808),
(@PATH, 152, -5452.89, -1712.47, -31.4806),
(@PATH, 153, -5438.73, -1694.68, -39.2293),
(@PATH, 154, -5415, -1665.24, -52.9235),
(@PATH, 155, -5404.21, -1650.38, -54.0433),
(@PATH, 156, -5382.14, -1619.96, -55.4564),
(@PATH, 157, -5359.21, -1581.86, -54.3701),
(@PATH, 158, -5335.16, -1551.91, -54.5505),
(@PATH, 159, -5307.35, -1526.65, -56.18),
(@PATH, 160, -5277.19, -1490.33, -56.4778),
(@PATH, 161, -5254.46, -1467.41, -56.1179),
(@PATH, 162, -5234.6, -1435.62, -54.6556),
(@PATH, 163, -5208.81, -1408.3, -52.7023),
(@PATH, 164, -5186.86, -1376.82, -52.0997),
(@PATH, 165, -5161.9, -1341.03, -50.2505),
(@PATH, 166, -5111.66, -1355.74, -50.9843),
(@PATH, 167, -5094.4, -1380.98, -51.8489),
(@PATH, 168, -5073.89, -1397.17, -52.37),
(@PATH, 169, -5064.51, -1427.11, -52.3102),
(@PATH, 170, -5052.49, -1465.43, -50.1334),
(@PATH, 171, -5033.77, -1492.85, -49.7627),
(@PATH, 172, -5044.56, -1524.25, -48.7018),
(@PATH, 173, -5066.05, -1540.68, -48.0147),
(@PATH, 174, -5084.74, -1554.96, -47.1104),
(@PATH, 175, -5105.14, -1565.01, -46.4026),
(@PATH, 176, -5129.66, -1571.52, -49.5441),
(@PATH, 177, -5154.97, -1578.25, -54.2102),
(@PATH, 178, -5181.09, -1576.09, -53.6363);
*/

-- RFK fixes and improvements
-- Update NPC For Proper Type and Add Waypoint Movement
UPDATE `creature` SET `id` = 4436, `SpawnDist` = 0, `MovementType` = 2 WHERE `guid` = 87296;
SET @NPC := 87296;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1,1984.9,1601.33,79.6094, 0),
(@PATH,2,1976.46,1601.48,80.0231,0),
(@PATH,3,1967.94,1601.07,80.4888,0),
(@PATH,4,1961.14,1599.4,81.1372, 0),
(@PATH,5,1955.46,1595.81,81.9168,0),
(@PATH,6,1951.26,1583.76,81.8884,0),
(@PATH,7,1955.19,1594.79,82.0734,0),
(@PATH,8,1963.58,1599.38,80.8979,0),
(@PATH,9,1968.28,1601.08,80.4596,0),
(@PATH,10,1986.78,1601.08,79.783,0);

-- Move NPC into Proper Position
UPDATE `creature` SET `position_x` = 2008.055786, `position_y` = 1569.062988, `position_z` = 81.737740, `orientation` = 2.060939 WHERE `guid` = 87292;

-- NPC NPC Into Position and Change to Correct Type
UPDATE `creature` SET `id` = 4530, `spawndist` = 0, `MovementType` = 0, `position_x` = 2000.325195, `position_y` = 1558.828735, `position_z` = 82.008972, `orientation` = 0.571824 WHERE `guid` = 87293;

-- Fix Hogger Movement (Random)
/*
UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `guid`=80531;
*/

-- Fix Gnomeregan Teleport XYZ -- Correct XYZ to better location and not off the ground
/*
UPDATE `areatrigger_teleport` SET `target_position_x` = -327.5286, `target_position_y` = -4.6991, `target_position_z` = -152.84598, `target_orientation` = 3.02761 WHERE `id` = 324;
*/

-- NOTE! be carefull with this unitflags 32768. Implement NPC Swimming Proper Animations
UPDATE `creature_template` SET `Unit_Flags`=`Unit_Flags`|32768 WHERE `InhabitType` IN (2);
