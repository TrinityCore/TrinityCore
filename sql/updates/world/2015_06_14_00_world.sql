TRUNCATE TABLE `access_requirement`;

INSERT INTO `access_requirement`(`mapId`,`difficulty`,`level_min`,`level_max`,`item`,`item2`,`quest_done_A`,`quest_done_H`,`completed_achievement`,`quest_failed_text`,`comment`) VALUES
-- Shadowfang Keep 
(33,1,11,0,0,0,0,0,0,NULL,'Shadowfang Keep (Entrance)'),
(33,2,85,0,0,0,0,0,0,NULL,'Shadowfang Keep (Entrance) - HC'),
-- Stormwind Stockades
(34,1,15,0,0,0,0,0,0,NULL,'Stormwind Stockades (Entrance)'),
-- Deadmines
(36,1,10,0,0,0,0,0,0,NULL,'Deadmines (Entrance)'),
(36,2,85,0,0,0,0,0,0,NULL,'Deadmines (Entrance) - HC'),
-- Wailing Caverns
(43,1,10,0,0,0,0,0,0,NULL,'Wailing Caverns (Entrance)'),
-- Razorfen Kraul
(47,1,25,0,0,0,0,0,0,NULL,'Razorfen Kraul (Entrance)'),
-- Blackfathom Deeps
(48,1,15,0,0,0,0,0,0,NULL,'Blackfathom Deeps (Entrance)'),
-- Uldaman
(70,1,30,0,0,0,0,0,0,NULL,'Uldaman (Entrance)'),
-- Gnomeregan
(90,1,19,0,0,0,0,0,0,NULL,'Gnomeregan (Entrance)'),
-- Sunken Temple
(109,1,45,0,0,0,0,0,0,NULL,'Sunken Temple (Entrance)'),
-- Razorfen Downs
(129,1,35,0,0,0,0,0,0,NULL,'Razorfen Downs (Entrance)'),
-- Scarlet Monastery
(189,1,20,0,0,0,0,0,0,NULL,'Scarlet Monastery - Graveyard (Entrance)'),
-- Zul'Farrak
(209,1,39,0,0,0,0,0,0,NULL,'Zul''Farrak (Entrance)'),
-- Blackrock Spire
(229,1,48,0,0,0,0,0,0,NULL,'Blackrock Spire (Entrance)'),
-- Blackrock Depths
(230,1,42,0,0,0,0,0,0,NULL,'Blackrock Depths (Entrance)'),
-- Black Morass
(269,1,65,0,0,0,10285,10285,0,'You must complete the quest \"Return to Andormu\" before entering the Black Morass.','Black Morass (Entrance)'),
(269,2,65,0,0,0,10285,10285,0,'You must complete the quest \"Return to Andormu\" and be level 65 before entering the Heroic difficulty of the Black Morass.','Black Morass (Entrance) - HC'),
-- Stratholme
(329,1,37,0,0,0,0,0,0,NULL,'Stratholme (Entrance)'),
-- Maraudon
(349,1,25,0,0,0,0,0,0,NULL,'Maraudon (Entrance)'),
-- Ragefire Chasm
(389,1,10,0,0,0,0,0,0,NULL,'Ragefire Chasm (Entrance)'),
-- Dire Maul
(429,1,31,0,0,0,0,0,0,NULL,'Dire Maul'),
-- The Shattered Halls
(540,1,65,0,0,0,0,0,0,NULL,'The Shattered Halls (Entrance)'),
(540,2,65,0,0,0,0,0,0,NULL,'The Shattered Halls (Entrance) - HC'),
-- The Blood Furnace
(542,1,58,0,0,0,0,0,0,NULL,'The Blood Furnace (Entrance)'),
(542,2,58,0,0,0,0,0,0,NULL,'The Blood Furnace (Entrance) - HC'),
-- Hellfire Ramparts
(543,1,57,0,0,0,0,0,0,NULL,'Hellfire Ramparts (Entrance)'),
(543,2,57,0,0,0,0,0,0,NULL,'Hellfire Ramparts (Entrance) - HC'),
-- The Steamvault
(545,1,65,0,0,0,0,0,0,NULL,'The Steamvault (Entrance)'),
(545,2,65,0,0,0,0,0,0,NULL,'The Steamvault (Entrance) - HC'),
-- The Underbog
(546,1,60,0,0,0,0,0,0,NULL,'The Underbog (Entrance)'),
(546,2,60,0,0,0,0,0,0,NULL,'The Underbog (Entrance) - HC'),
-- The Slave Pens
(547,1,59,0,0,0,0,0,0,NULL,'The Slave Pens (Entrance)'),
(547,2,59,0,0,0,0,0,0,NULL,'The Slave Pens (Entrance) - HC'),
-- The Arcatraz
(552,1,65,0,0,0,0,0,0,NULL,'The Arcatraz (Entrance)'),
(552,2,65,0,0,0,0,0,0,NULL,'The Arcatraz (Entrance) - HC'),
-- The Botanica
(553,1,65,0,0,0,0,0,0,NULL,'The Botanica (Entrance)'),
(553,2,65,0,0,0,0,0,0,NULL,'The Botanica (Entrance) - HC'),
-- The Mechanar
(554,1,65,0,0,0,0,0,0,NULL,'The Mechanar (Entrance)'),
(554,2,65,0,0,0,0,0,0,NULL,'The Mechanar (Entrance) - HC'),
-- Shadow Labyrinth
(555,1,65,0,0,0,0,0,0,NULL,'Shadow Labyrinth (Entrance)'),
(555,2,65,0,0,0,0,0,0,NULL,'Shadow Labyrinth (Entrance) - HC'),
-- Sethekk Halls
(556,1,63,0,0,0,0,0,0,NULL,'Sethekk Halls (Entrance)'),
(556,2,63,0,0,0,0,0,0,NULL,'Sethekk Halls (Entrance) - HC'),
-- Mana Tombs
(557,1,61,0,0,0,0,0,0,NULL,'Mana Tombs (Entrance)'),
(557,2,61,0,0,0,0,0,0,NULL,'Mana Tombs (Entrance) - HC'),
-- Auchenai Crypts
(558,1,62,0,0,0,0,0,0,NULL,'Auchenai Crypts (Entrance)'),
(558,2,62,0,0,0,0,0,0,NULL,'Auchenai Crypts (Entrance) - HC'),
-- Old Hillsbrad Foothils
(560,1,63,0,0,0,0,0,0,NULL,'Old Hillsbrad Foothills (Entrance)'),
(560,2,63,0,0,0,0,0,0,NULL,'Old Hillsbrad Foothills (Entrance) - HC'),
-- Zul'Aman
(568,1,85,0,0,0,0,0,0,NULL,'Zul''Aman (Entrance)'),
(568,2,85,0,0,0,0,0,0,NULL,'Zul''Aman (Entrance) - HC'),
-- Utgarde Keep
(574,1,67,0,0,0,0,0,0,NULL,'Utgarde Keep (entrance)'),
(574,2,80,0,0,0,0,0,0,NULL,'Utgarde Keep (entrance) - HC'),
-- Utgarde Pinnacle
(575,1,75,0,0,0,0,0,0,NULL,'Utgarde Pinnacle (entrance)'),
(575,2,80,0,0,0,0,0,0,NULL,'Utgarde Pinnacle (entrance) - HC'),
-- The Nexus
(576,1,68,0,0,0,0,0,0,NULL,'The Nexus (entrance)'),
(576,2,80,0,0,0,0,0,0,NULL,'The Nexus (entrance) - HC'),
-- The Oculus
(578,1,75,0,0,0,0,0,0,NULL,'The Oculus (entrance)'),
(578,2,80,0,0,0,0,0,0,NULL,'The Oculus (entrance) - HC'),
-- Magisters Terrace
(585,1,65,0,0,0,0,0,0,NULL,'Magisters'' Terrace (Entrance)'),
(585,2,65,0,0,0,0,0,0,NULL,'Magisters'' Terrace (Entrance) - HC'),
-- Culling of Stratholme
(595,1,75,0,0,0,0,0,0,NULL,'Culling of Stratholme (Entrance)'),
(595,2,80,0,0,0,0,0,0,NULL,'Culling of Stratholme (Entrance) - HC'),
-- Halls of Stone
(599,1,74,0,0,0,0,0,0,NULL,'Halls of Stone (Entrance)'),
(599,2,80,0,0,0,0,0,0,NULL,'Halls of Stone (Entrance) - HC'),
-- Drak'Tharon Keep
(600,1,71,0,0,0,0,0,0,NULL,'Drak''Tharon Keep (Entrance)'),
(600,2,80,0,0,0,0,0,0,NULL,'Drak''Tharon Keep (Entrance) - HC'),
-- Azjol-Nerub
(601,1,69,0,0,0,0,0,0,NULL,'Azjol-Nerub (Entrance)'),
(601,2,80,0,0,0,0,0,0,NULL,'Azjol-Nerub (Entrance) - HC'),
-- Halls of Lightning
(602,1,75,0,0,0,0,0,0,NULL,'Halls of Lightning (Entrance)'),
(602,2,80,0,0,0,0,0,0,NULL,'Halls of Lightning (Entrance) - HC'),
-- Gundrak
(604,1,73,0,0,0,0,0,0,NULL,'Gundrak (Entrance)'),
(604,2,80,0,0,0,0,0,0,NULL,'Gundrak (Entrance) - HC'),
-- Violet Hold
(608,1,72,0,0,0,0,0,0,NULL,'Violet Hold (Entrance)'),
(608,2,80,0,0,0,0,0,0,NULL,'Violet Hold (Entrance) - HC'),
-- Ahn'Kahet
(619,1,70,0,0,0,0,0,0,NULL,'Ahn''Kahet (Entrance)'),
(619,2,80,0,0,0,0,0,0,NULL,'Ahn''Kahet (Entrance) - HC'),
-- Forge of Souls
(632,1,75,0,0,0,0,0,0,NULL,'Forge of Souls (Entrance)'),
(632,2,80,0,0,0,0,0,0,NULL,'Forge of Souls (Entrance) - HC'),
-- Throne of the Tides
(643,1,77,0,0,0,0,0,0,NULL,'Throne of the Tides (Entrance)'),
(643,2,85,0,0,0,0,0,0,NULL,'Throne of the Tides (Entrance) - HC'),
-- Halls of Origination
(644,1,83,0,0,0,0,0,0,NULL,'Halls of Origination (Entrance)'),
(644,2,85,0,0,0,0,0,0,NULL,'Halls of Origination (Entrance) - HC'),
-- Blackrock Caverns
(645,1,77,0,0,0,0,0,0,NULL,'Blackrock Caverns (Entrance)'),
(645,2,85,0,0,0,0,0,0,NULL,'Blackrock Caverns (Entrance) - HC'),
-- Trial of the Champion
(650,1,75,0,0,0,0,0,0,NULL,'Trial of the Champion (Entrance)'),
(650,2,80,0,0,0,0,0,0,NULL,'Trial of the Champion (Entrance) - HC'),
-- The Vortex Pinnacle
(657,1,80,0,0,0,0,0,0,NULL,'The Vortex Pinnacle (Entrance)'),
(657,2,85,0,0,0,0,0,0,NULL,'The Vortex Pinnacle (Entrance) - HC'),
-- Pit of Saron
(658,1,75,0,0,0,24499,24511,0,NULL,'Pit of Saron (Entrance)'),
(658,2,80,0,0,0,24499,24511,0,NULL,'Pit of Saron (Entrance) - HC'),
-- Halls of Reflection
(668,1,75,0,0,0,24710,24712,0,NULL,'Halls of Reflection (Entrance)'),
(668,2,80,0,0,0,24710,24712,0,NULL,'Halls of Reflection (Entrance) - HC'),
-- Grim Batol
(670,1,83,0,0,0,0,0,0,NULL,'Grim Batol (Entrance)'),
(670,2,85,0,0,0,0,0,0,NULL,'Grim Batol (Entrance) - HC'),
-- The Stonecore
(725,1,80,0,0,0,0,0,0,NULL,'The Stonecore (Entrance)'),
(725,2,85,0,0,0,0,0,0,NULL,'The Stonecore (Entrance) - HC'),
-- Lost City of the Tol'vir
(755,1,83,0,0,0,0,0,0,NULL,'Lost City of the Tol''vir (Entrance)'),
(755,2,85,0,0,0,0,0,0,NULL,'Lost City of the Tol''vir (Entrance) - HC'),
-- Zul Gurub
(859,1,85,0,0,0,0,0,0,NULL,'Zul''Gurub (Entrance)'),
(859,2,85,0,0,0,0,0,0,NULL,'Zul''Gurub (Entrance) - HC'),
-- End Time
(938,2,85,0,0,0,0,0,0,NULL,'End Time (Entrance) - HC'),
-- Well of Eternity
(939,2,85,0,0,0,0,0,6117,NULL,'Well of Eternity (Entrance) - HC'),
-- Hour of Twilight
(940,2,85,0,0,0,0,0,6118,NULL,'Hour of Twilight (Entrance) - HC'),
-- Shado-Pan Monastery
(959,1,87,0,0,0,0,0,0,NULL,'Shado-Pan Monastery (Entrance)'),
(959,2,90,0,0,0,0,0,0,NULL,'Shado-Pan Monastery (Entrance) - HC'),
-- Temple of the Jade Serpent
(960,1,85,0,0,0,0,0,0,NULL,'Temple of the Jade Serpent (Entrance)'),
(960,2,90,0,0,0,0,0,0,NULL,'Temple of the Jade Serpent (Entrance) - HC'),
-- Temple of the Jade Serpent
(961,1,85,0,0,0,0,0,0,NULL,'Stormstout Brewery (Entrance)'),
(961,2,90,0,0,0,0,0,0,NULL,'Stormstout Brewery (Entrance) - HC'),
-- Gate of the Setting Sun
(962,2,90,0,0,0,0,0,0,NULL,'Gate of the Setting Sun (Entrance) - HC'),
-- Mogu'shan Palace
(994,1,87,0,0,0,0,0,0,NULL,'Mogu''shan Palace (Entrance)'),
(994,2,90,0,0,0,0,0,0,NULL,'Mogu''shan Palace (Entrance) - HC'),
-- Scarlet Halls
(1001,1,21,0,0,0,0,0,0,NULL,'Scarlet Halls (Entrance)'),
(1001,2,90,0,0,0,0,0,0,NULL,'Scarlet Halls (Entrance) - HC'),
-- Scarlet Monastery
(1004,1,21,0,0,0,0,0,0,NULL,'Scarlet Monastery (Entrance)'),
(1004,2,90,0,0,0,0,0,0,NULL,'Scarlet Monastery (Entrance) - HC'),
-- Scholomance
(1007,1,33,0,0,0,0,0,0,NULL,'Scholomance (Entrance)'),
(1007,2,90,0,0,0,0,0,0,NULL,'Scholomance (Entrance) - HC'),
-- Siege of Niuzao Temple
(1011,1,87,0,0,0,0,0,0,NULL,'Siege of Niuzao Temple (Entrance)'),
(1011,2,90,0,0,0,0,0,0,NULL,'Siege of Niuzao Temple (Entrance) - HC'),
-- Bloodmaul Slag Mines
(1175,1,90,0,0,0,0,0,0,NULL,'Bloodmaul Slag Mines (Entrance)'),
(1175,2,100,0,0,0,0,0,0,NULL,'Bloodmaul Slag Mines (Entrance) - HC'),
-- Bloodmaul Slag Mines
(1176,1,100,0,0,0,0,0,0,NULL,'Shadowmoon Burial Grounds (Entrance)'),
(1176,2,100,0,0,0,0,0,0,NULL,'Shadowmoon Burial Grounds (Entrance) - HC'),
-- Auchindoun
(1182,1,94,0,0,0,0,0,0,NULL,'Auchindoun (Entrance)'),
(1182,2,100,0,0,0,0,0,0,NULL,'Auchindoun (Entrance) - HC'),
-- Iron Docks
(1195,1,92,0,0,0,0,0,0,NULL,'Iron Docks (Entrance)'),
(1195,2,100,0,0,0,0,0,0,NULL,'Iron Docks (Entrance) - HC'),
-- Grimrail Depot
(1208,1,100,0,0,0,0,0,0,NULL,'Grimrail Depot (Entrance)'),
(1208,2,100,0,0,0,0,0,0,NULL,'Grimrail Depot (Entrance) - HC'),
-- Skyreach
(1209,1,96,0,0,0,0,0,0,NULL,'Skyreach (Entrance)'),
(1209,2,100,0,0,0,0,0,0,NULL,'Skyreach (Entrance) - HC'),
-- The Everbloom
(1279,1,100,0,0,0,0,0,0,NULL,'The Everbloom (Entrance)'),
(1279,2,100,0,0,0,0,0,0,NULL,'The Everbloom (Entrance) - HC'),
-- Upper Blackrock Spire
(1358,1,100,0,0,0,0,0,0,NULL,'Upper Blackrock Spire (Entrance)'),
(1358,2,100,0,0,0,0,0,0,NULL,'Upper Blackrock Spire (Entrance) - HC'),

-- Onyxia Lair
(249,3,80,0,0,0,0,0,0,NULL,'Onyxia''s Lair (Entrance) - 10N'),
(249,4,80,0,0,0,0,0,0,NULL,'Onyxia''s Lair (Entrance) - 25N'),
-- Molten Core
(409,9,50,0,0,0,0,0,0,NULL,'Molten Core (Entrance) - 40N'),
-- Blackwing Lair
(469,9,60,0,0,0,0,0,0,NULL,'Blackwing Lair (Entrance) - 40N'),
-- Ruins of Ahn'Qiraj
(509,3,50,0,0,0,0,0,0,NULL,'Ruins Of Ahn''Qiraj (Outside) - 10N'),
-- Ahn'Qiraj Temple
(531,9,50,0,0,0,0,0,0,NULL,'Ahn''Qiraj Temple (Outside) - 40N'),
-- Naxxramas
(533,3,80,0,0,0,0,0,0,NULL,'Naxxramas - 10N'),
(533,4,80,0,0,0,0,0,0,NULL,'Naxxramas - 25N'),
-- Karazhan
(532,3,68,0,0,0,0,0,0,NULL,'Karazhan,Main (Entrance) - 10N'),
-- Battle Of Mount Hyjal
(534,4,70,0,0,0,0,0,0,NULL,'Battle Of Mount Hyjal, Alliance Base (Entrance) - 25N'),
-- Magtheridon's Lair
(544,4,65,0,0,0,0,0,0,NULL,'Magtheridon''s Lair (Entrance) - 25N'),
-- Serpentshrine Cavern
(548,4,68,0,0,0,0,0,0,NULL,'Serpentshrine Cavern (Entrance) - 25N'),
-- The Eye
(550,4,70,0,0,0,0,0,0,NULL,'The Eye (Entrance) - 25N'),
-- Black Temple
(564,4,70,0,0,0,0,0,0,NULL,'Black Temple (Entrance) - 25N'),
-- Gruls Lair
(565,4,70,0,0,0,0,0,0,NULL,'Gruul''s Lair (Entrance) - 25N'),
-- Sunwell Plateau
(580,4,70,0,0,0,0,0,0,NULL,'Sunwell Plateau (Entrance) - 25N'),
-- Ulduar
(603,3,80,0,0,0,0,0,0,NULL,'Ulduar Raid (Entrance) - 10N'),
(603,4,80,0,0,0,0,0,0,NULL,'Ulduar Raid (Entrance) - 25N'),
-- Obsidian Sanctum
(615,3,80,0,0,0,0,0,0,NULL,'Obsidian Sanctum (entrance) - 10N'),
(615,4,80,0,0,0,0,0,0,NULL,'Obsidian Sanctum (entrance) - 25N'),
-- The Eye of Eternity
(616,3,80,0,0,0,0,0,0,NULL,'The Eye of Eternity (entrance) - 10N'),
(616,4,80,0,0,0,0,0,0,NULL,'The Eye of Eternity (entrance) - 25N'),
-- Vault of Archavon
(624,3,80,0,0,0,0,0,0,NULL,'Vault of Archavon (Entrance) - 10N'),
(624,4,80,0,0,0,0,0,0,NULL,'Vault of Archavon (Entrance) - 25N'),
-- Icecrown Citadel
(631,3,80,0,0,0,0,0,0,NULL,'Icecrown Citadel (Entrance) - 10N'),
(631,4,80,0,0,0,0,0,0,NULL,'Icecrown Citadel (Entrance) - 25N'),
(631,5,80,0,0,0,0,0,4530,NULL,'IceCrown Citadel (Entrance) - 10HC'),
(631,6,80,0,0,0,0,0,4597,NULL,'IceCrown Citadel (Entrance) - 25HC'),
-- Trial of the Crusader
(649,3,80,0,0,0,0,0,0,NULL,'Trial of the Crusader - 10N'),
(649,4,80,0,0,0,0,0,0,NULL,'Trial of the Crusader - 25N'),
(649,5,80,0,0,0,0,0,0,NULL,'Trial of the Crusader - 10HC'),
(649,6,80,0,0,0,0,0,0,NULL,'Trial of the Crusader - 25HC'),
-- Blackwing Descent
(669,3,85,0,0,0,0,0,0,NULL,'Blackwing Descent (Entrance) - 10N'),
(669,4,85,0,0,0,0,0,0,NULL,'Blackwing Descent (Entrance) - 25N'),
(669,5,85,0,0,0,0,0,4842,NULL,'Blackwing Descent (Entrance) - 10H'),
(669,6,85,0,0,0,0,0,4842,NULL,'Blackwing Descent (Entrance) - 25H'),
-- The Bastion of Twilight
(671,3,85,0,0,0,0,0,0,NULL,'The Bastion of Twilight (Entrance) - 10N'),
(671,4,85,0,0,0,0,0,0,NULL,'The Bastion of Twilight (Entrance) - 25N'),
(671,5,85,0,0,0,0,0,4850,NULL,'The Bastion of Twilight (Entrance) - 10H'),
(671,6,85,0,0,0,0,0,4850,NULL,'The Bastion of Twilight (Entrance) - 25H'),
-- Firelands
(720,3,85,0,0,0,0,0,0,NULL,'Firelands (Entrance) - 10N'),
(720,4,85,0,0,0,0,0,0,NULL,'Firelands (Entrance) - 25N'),
(720,5,85,0,0,0,0,0,5802,NULL,'Firelands (Entrance) - 10H'),
(720,6,85,0,0,0,0,0,5802,NULL,'Firelands (Entrance) - 25H'),
-- Ruby Sanctum
(724,3,80,0,0,0,0,0,0,NULL,'The Ruby Sanctum (Entrance) - 10N'),
(724,4,80,0,0,0,0,0,0,NULL,'The Ruby Sanctum (Entrance) - 25N'),
(724,5,80,0,0,0,0,0,0,NULL,'The Ruby Sanctum (Entrance) - 10HC'),
(724,6,80,0,0,0,0,0,0,NULL,'The Ruby Sanctum (Entrance) - 25HC'),
-- Throne of the Four Winds
(754,3,85,0,0,0,0,0,0,NULL,'Throne of the Four Winds (Entrance) - 10N'),
(754,4,85,0,0,0,0,0,0,NULL,'Throne of the Four Winds (Entrance) - 25N'),
(754,5,85,0,0,0,0,0,4851,NULL,'Throne of the Four Winds (Entrance) - 10HC'),
(754,6,85,0,0,0,0,0,4851,NULL,'Throne of the Four Winds (Entrance) - 25HC'),
-- Baradin Hold
(757,3,85,0,0,0,0,0,0,NULL,'Baradin Hold (Entrance) - 10N'),
(757,4,85,0,0,0,0,0,0,NULL,'Baradin Hold (Entrance) - 25N'),
-- Dragon Soul
(967,3,85,0,0,0,0,0,0,NULL,'Dragon Soul (Entrance) - 10N'),
(967,4,85,0,0,0,0,0,0,NULL,'Dragon Soul (Entrance) - 25N'),
(967,5,85,0,0,0,0,0,6177,NULL,'Dragon Soul (Entrance) - 10H'),
(967,6,85,0,0,0,0,0,6177,NULL,'Dragon Soul (Entrance) - 25H'),
-- Terrace of Endless Spring
(996,3,90,0,0,0,0,0,0,NULL,'Terrace of Endless Spring (Entrance) - 10N'),
(996,4,90,0,0,0,0,0,0,NULL,'Terrace of Endless Spring (Entrance) - 25N'),
(996,5,90,0,0,0,0,0,0,NULL,'Terrace of Endless Spring (Entrance) - 10HC'), -- TODO: access only after killing final boss in normal mode
(996,6,90,0,0,0,0,0,0,NULL,'Terrace of Endless Spring (Entrance) - 25HC'), -- TODO: access only after killing final boss in normal mode
-- Mogu'shan Vaults
(1008,3,90,0,0,0,0,0,0,NULL,'Mogu''shan Vaults (Entrance) - 10N'),
(1008,4,90,0,0,0,0,0,0,NULL,'Mogu''shan Vaults (Entrance) - 25N'),
(1008,5,90,0,0,0,0,0,0,NULL,'Mogu''shan Vaults (Entrance) - 10HC'), -- TODO: access only after killing final boss in normal mode
(1008,6,90,0,0,0,0,0,0,NULL,'Mogu''shan Vaults (Entrance) - 25HC'), -- TODO: access only after killing final boss in normal mode
-- Heart of Fear
(1009,3,90,0,0,0,0,0,0,NULL,'Heart of Fear (Entrance) - 10N'),
(1009,4,90,0,0,0,0,0,0,NULL,'Heart of Fear (Entrance) - 25N'),
(1009,5,90,0,0,0,0,0,0,NULL,'Heart of Fear (Entrance) - 10HC'), -- TODO: access only after killing final boss in normal mode
(1009,6,90,0,0,0,0,0,0,NULL,'Heart of Fear (Entrance) - 25HC'), -- TODO: access only after killing final boss in normal mode
-- Throne of Thunder
(1098,3,90,0,0,0,0,0,0,NULL,'Throne of Thunder (Entrance) - 10N'),
(1098,4,90,0,0,0,0,0,0,NULL,'Throne of Thunder (Entrance) - 25N'),
(1098,5,90,0,0,0,0,0,0,NULL,'Throne of Thunder (Entrance) - 10HC'),
(1098,6,90,0,0,0,0,0,0,NULL,'Throne of Thunder (Entrance) - 25HC'),
-- Siege of Orgrimmar
(1136,14,90,0,0,0,0,0,0,NULL,'Siege of Orgrimmar (Entrance) - 30N'),
(1136,15,90,0,0,0,0,0,0,NULL,'Siege of Orgrimmar (Entrance) - 30HC'),
(1136,16,90,0,0,0,0,0,0,NULL,'Siege of Orgrimmar (Entrance) - 20MC'),
(1136,17,90,0,0,0,0,0,0,NULL,'Siege of Orgrimmar (Entrance) - 20LFR'),
-- Blackrock Foundry
(1205,14,100,0,0,0,0,0,0,NULL,'Blackrock Foundry (Entrance) - 30N'),
(1205,15,100,0,0,0,0,0,0,NULL,'Blackrock Foundry (Entrance) - 30HC'),
(1205,16,100,0,0,0,0,0,0,NULL,'Blackrock Foundry (Entrance) - 20MC'),
(1205,17,100,0,0,0,0,0,0,NULL,'Blackrock Foundry (Entrance) - 20LFR'),
-- Highmaul
(1228,14,100,0,0,0,0,0,0,NULL,'Highmaul (Entrance) - 30N'),
(1228,15,100,0,0,0,0,0,0,NULL,'Highmaul (Entrance) - 30HC'),
(1228,16,100,0,0,0,0,0,0,NULL,'Highmaul (Entrance) - 20MC'),
(1228,17,100,0,0,0,0,0,0,NULL,'Highmaul (Entrance) - 20LFR');
