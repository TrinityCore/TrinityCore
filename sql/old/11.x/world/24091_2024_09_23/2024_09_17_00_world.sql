SET @CGUID := 10001963;

SET @NPCTEXTID := 600024;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 220943, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2674.58251953125, -2526.857666015625, 220.9528350830078125, 1.612689495086669921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Reliquary Researcher (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 397765 - Cosmetic - Reading Book, Standing)
(@CGUID+1, 227038, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2686.865478515625, -2546.708251953125, 221.8681488037109375, 5.574454307556152343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Scouting Map (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 228605, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2685.818603515625, -2545.510498046875, 221.061431884765625, 5.307927131652832031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Elise Starseeker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+3, 220944, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2673.244873046875, -2548.68408203125, 220.9528350830078125, 3.533936023712158203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Expedition Scout (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+4, 226250, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2668.065185546875, -2533.210205078125, 220.98095703125, 4.542886734008789062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Reno Jackson (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+5, 226696, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2700.791748046875, -2559.767333984375, 220.56622314453125, 5.42346048355102539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Seasonal Delver's Dirigible (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+6, 208070, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2689.7197265625, -2529.7744140625, 223.552276611328125, 4.117716789245605468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Sir Finley Mrrgglton (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+7, 220943, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2684.435791015625, -2548.397705078125, 221.06097412109375, 1.7767106294631958, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Reliquary Researcher (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 369560 - Conversation Aura: Talk/Question/Flex/Salute [DNT])
(@CGUID+8, 226742, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2711.345458984375, -2522.69970703125, 221.3472137451171875, 3.844373226165771484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Rhukah (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+9, 226743, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2707.93408203125, -2522.16845703125, 221.1195220947265625, 5.10699462890625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Nargut (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+10, 220944, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2683.953125, -2546.0869140625, 220.98095703125, 5.070031166076660156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Expedition Scout (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 369560 - Conversation Aura: Talk/Question/Flex/Salute [DNT])
(@CGUID+11, 226749, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2709.197998046875, -2526.225830078125, 220.844268798828125, 1.769900679588317871, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Abohba (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+12, 220796, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2655.7431640625, -2560.619873046875, 220.8387298583984375, 3.952522993087768554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Delver's Dirigible (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+13, 223858, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2681.3056640625, -2530.729248046875, 222.2698516845703125, 5.34864044189453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Explorers' League Supplies (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+14, 220943, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2666.21875, -2545.0869140625, 220.9528350830078125, 0.214867562055587768, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Reliquary Researcher (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+15, 227675, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2675.671142578125, -2531.095458984375, 222.270172119140625, 5.058915138244628906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Delver's Guide (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+16, 206017, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2678.22998046875, -2528.64404296875, 220.9528350830078125, 5.063085079193115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513), -- Brann Bronzebeard (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+17, 220943, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2673.58251953125, -2546.564208984375, 220.9528350830078125, 3.969540596008300781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56513); -- Reliquary Researcher (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 397765 - Cosmetic - Reading Book, Standing)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '397765'), -- Reliquary Researcher - 397765 - Cosmetic - Reading Book, Standing
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, ''), -- Elise Starseeker
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 25374, 0, 0, 0, ''), -- Expedition Scout
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369560'), -- Reliquary Researcher - 369560 - Conversation Aura: Talk/Question/Flex/Salute [DNT]
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369560'), -- Expedition Scout - 369560 - Conversation Aura: Talk/Question/Flex/Salute [DNT]
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 882, 0, 0, 0, 0, ''), -- Abohba
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Reliquary Researcher
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '397765'); -- Reliquary Researcher - 397765 - Cosmetic - Reading Book, Standing

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (226743 /*226743 (Nargut)*/, 226742 /*226742 (Rhukah)*/, 226250 /*226250 (Reno Jackson)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226743, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226743 (Nargut)
(226742, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226742 (Rhukah)
(226250, 0, 0, 0, 0, 0, 1, 0, 0, 14533, 0, 0, 0, ''); -- 226250 (Reno Jackson)

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226833; -- Matron Ossela
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226834; -- Nelur Lightsown
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226832; -- Saedelin Whitedawn
UPDATE `creature_template` SET `faction`=3407, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1073741824 WHERE `entry`=226287; -- Ellerdin
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222162; -- High Elven Magi
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219542; -- Bronze Timekeeper
UPDATE `creature_template` SET `faction`=35, `npcflag`=4294967296, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219225; -- Cuzolth
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222294; -- Dark Iron Flameguard
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=224714; -- Dornogal Patron
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222245; -- Sunreaver Sorcerer
UPDATE `creature_template` SET `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219226; -- Vaskarn
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=224713; -- Bronzebeard Patron
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=222610; -- [DNT] Kill Credit
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=224712; -- Dark Iron Patron
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=227321; -- Silver Covenant Mage
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=224711; -- Wildhammer Patron
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=229336; -- Overseer Hyggred
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222138; -- Troll Headhunter

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=228605 AND `MenuID`=36095) OR (`CreatureID`=208070 AND `MenuID`=35291) OR (`CreatureID`=227675 AND `MenuID`=35770) OR (`CreatureID`=206017 AND `MenuID` IN (37121,32391,36013)) OR (`CreatureID`=226250 AND `MenuID`=35290);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(228605, 36095, 56513), -- Elise Starseeker
(208070, 35291, 56513), -- Sir Finley Mrrgglton
(227675, 35770, 56513), -- Delver's Guide
(206017, 32391, 56513), -- Brann Bronzebeard
(226250, 35290, 56513); -- Reno Jackson

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+6;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 276521, 0, 0, 0, 0, 0, 0, 0, 56513), -- 206017 (Brann Bronzebeard)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 269559, 0, 0, 0, 0, 0, 0, 0, 56513), -- 206017 (Brann Bronzebeard)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 249018, 0, 0, 0, 0, 0, 0, 0, 56513), -- 206017 (Brann Bronzebeard)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 269906, 0, 0, 0, 0, 0, 0, 0, 56513), -- 228605 (Elise Starseeker)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 268818, 0, 0, 0, 0, 0, 0, 0, 56513), -- 227675 (Delver's Guide)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 266872, 0, 0, 0, 0, 0, 0, 0, 56513), -- 226250 (Reno Jackson)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 266875, 0, 0, 0, 0, 0, 0, 0, 56513); -- 208070 (Sir Finley Mrrgglton)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37121 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36013 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=32391 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=36095 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=35770 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=35290 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=35291 AND `TextID`=@NPCTEXTID+6);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37121, @NPCTEXTID+0, 56513), -- 206017 (Brann Bronzebeard)
(36013, @NPCTEXTID+1, 56513), -- 206017 (Brann Bronzebeard)
(32391, @NPCTEXTID+2, 56513), -- 206017 (Brann Bronzebeard)
(36095, @NPCTEXTID+3, 56513), -- 228605 (Elise Starseeker)
(35770, @NPCTEXTID+4, 56513), -- 227675 (Delver's Guide)
(35290, @NPCTEXTID+5, 56513), -- 226250 (Reno Jackson)
(35291, @NPCTEXTID+6, 56513); -- 208070 (Sir Finley Mrrgglton)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID` IN (35290,35291)) OR (`OptionID`=0 AND `MenuID` IN (35770,36013)) OR (`OptionID`=4 AND `MenuID`=32391) OR (`OptionID`=2 AND `MenuID`=32391);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35290, 122953, 1, 1, 'I wish to browse your wares.', 4424, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513), -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
(35770, 123493, 0, 0, '<Review information on your current delve progress.>', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(35291, 122954, 1, 1, 'I wish to browse your wares.', 4424, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513), -- OptionBroadcastTextID: 4424 - 9818 - 12631 - 13966 - 14925 - 15955 - 16125 - 16127 - 17085 - 18217 - 19466 - 38807
(36013, 123746, 0, 0, 'Thanks, Brann. Let\'s talk about something else.', 0, 0, 0, 32391, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(32391, 125297, 4, 0, 'How do I earn progress towards the Delver\'s Journey?', 0, 0, 0, 37121, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513),
(32391, 123745, 2, 0, 'What are delves and the Delver\'s Headquarters?', 0, 0, 0, 36013, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56513);

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=226833 AND `DifficultyID`=0); -- 226833 (Matron Ossela) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=226834 AND `DifficultyID`=0); -- 226834 (Nelur Lightsown) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=226832 AND `DifficultyID`=0); -- 226832 (Saedelin Whitedawn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56513 WHERE (`Entry`=226287 AND `DifficultyID`=0); -- 226287 (Ellerdin) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=219225 AND `DifficultyID`=0); -- 219225 (Cuzolth) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=226270 AND `DifficultyID`=0); -- 226270 (Watchful Peacekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=222294 AND `DifficultyID`=0); -- 222294 (Dark Iron Flameguard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=224714 AND `DifficultyID`=0); -- 224714 (Dornogal Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=222245 AND `DifficultyID`=0); -- 222245 (Sunreaver Sorcerer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=219226 AND `DifficultyID`=0); -- 219226 (Vaskarn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=224713 AND `DifficultyID`=0); -- 224713 (Bronzebeard Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `VerifiedBuild`=56513 WHERE (`Entry`=222610 AND `DifficultyID`=0); -- 222610 ([DNT] Kill Credit) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=224712 AND `DifficultyID`=0); -- 224712 (Dark Iron Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=227321 AND `DifficultyID`=0); -- 227321 (Silver Covenant Mage) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=224711 AND `DifficultyID`=0); -- 224711 (Wildhammer Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=229336 AND `DifficultyID`=0); -- 229336 (Overseer Hyggred) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56513 WHERE (`Entry`=222138 AND `DifficultyID`=0); -- 222138 (Troll Headhunter) - CanSwim

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=208070 AND `item`=211040 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211041 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211046 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211047 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211048 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211059 AND `ExtendedCost`=9022 AND `type`=1) OR (`entry`=208070 AND `item`=219351 AND `ExtendedCost`=9022 AND `type`=1) OR (`entry`=208070 AND `item`=219352 AND `ExtendedCost`=9022 AND `type`=1) OR (`entry`=208070 AND `item`=219354 AND `ExtendedCost`=9022 AND `type`=1) OR (`entry`=208070 AND `item`=219353 AND `ExtendedCost`=9022 AND `type`=1) OR (`entry`=208070 AND `item`=219355 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=219356 AND `ExtendedCost`=9021 AND `type`=1) OR (`entry`=208070 AND `item`=211052 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211051 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211061 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211063 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211062 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211007 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211006 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=211005 AND `ExtendedCost`=9020 AND `type`=1) OR (`entry`=208070 AND `item`=224839 AND `ExtendedCost`=8450 AND `type`=1) OR (`entry`=208070 AND `item`=224840 AND `ExtendedCost`=8450 AND `type`=1) OR (`entry`=208070 AND `item`=224844 AND `ExtendedCost`=8449 AND `type`=1) OR (`entry`=208070 AND `item`=224814 AND `ExtendedCost`=8449 AND `type`=1) OR (`entry`=208070 AND `item`=224841 AND `ExtendedCost`=8449 AND `type`=1) OR (`entry`=208070 AND `item`=224842 AND `ExtendedCost`=8448 AND `type`=1) OR (`entry`=208070 AND `item`=224845 AND `ExtendedCost`=8448 AND `type`=1) OR (`entry`=208070 AND `item`=224843 AND `ExtendedCost`=8448 AND `type`=1) OR (`entry`=208070 AND `item`=221502 AND `ExtendedCost`=8589 AND `type`=1) OR (`entry`=208070 AND `item`=226259 AND `ExtendedCost`=9098 AND `type`=1) OR (`entry`=208070 AND `item`=226258 AND `ExtendedCost`=9099 AND `type`=1) OR (`entry`=208070 AND `item`=211931 AND `ExtendedCost`=9013 AND `type`=1) OR (`entry`=208070 AND `item`=228413 AND `ExtendedCost`=9013 AND `type`=1) OR (`entry`=208070 AND `item`=225910 AND `ExtendedCost`=9013 AND `type`=1) OR (`entry`=208070 AND `item`=222974 AND `ExtendedCost`=8492 AND `type`=1) OR (`entry`=208070 AND `item`=224770 AND `ExtendedCost`=9008 AND `type`=1) OR (`entry`=208070 AND `item`=224768 AND `ExtendedCost`=9008 AND `type`=1) OR (`entry`=208070 AND `item`=224769 AND `ExtendedCost`=9014 AND `type`=1) OR (`entry`=208070 AND `item`=224771 AND `ExtendedCost`=9015 AND `type`=1) OR (`entry`=208070 AND `item`=232498 AND `ExtendedCost`=8452 AND `type`=1) OR (`entry`=208070 AND `item`=232497 AND `ExtendedCost`=8452 AND `type`=1) OR (`entry`=208070 AND `item`=232496 AND `ExtendedCost`=8452 AND `type`=1) OR (`entry`=226250 AND `item`=225508 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225507 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225506 AND `ExtendedCost`=9044 AND `type`=1) OR (`entry`=226250 AND `item`=225505 AND `ExtendedCost`=9044 AND `type`=1) OR (`entry`=226250 AND `item`=225504 AND `ExtendedCost`=9044 AND `type`=1) OR (`entry`=226250 AND `item`=225503 AND `ExtendedCost`=9044 AND `type`=1) OR (`entry`=226250 AND `item`=225502 AND `ExtendedCost`=9044 AND `type`=1) OR (`entry`=226250 AND `item`=225501 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225500 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225499 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225498 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225497 AND `ExtendedCost`=9045 AND `type`=1) OR (`entry`=226250 AND `item`=225411 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225410 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225409 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225408 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225407 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225406 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225405 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225404 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225403 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225412 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225386 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225380 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225385 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225384 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225383 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225382 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225381 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225379 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225413 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225402 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225401 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225400 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225399 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225398 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225397 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225396 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225395 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225414 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225394 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225393 AND `ExtendedCost`=9042 AND `type`=1) OR (`entry`=226250 AND `item`=225392 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225391 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225390 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=225389 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225388 AND `ExtendedCost`=9043 AND `type`=1) OR (`entry`=226250 AND `item`=225387 AND `ExtendedCost`=8493 AND `type`=1) OR (`entry`=226250 AND `item`=223312 AND `ExtendedCost`=9016 AND `type`=1) OR (`entry`=226250 AND `item`=224981 AND `ExtendedCost`=9016 AND `type`=1) OR (`entry`=226250 AND `item`=224979 AND `ExtendedCost`=9016 AND `type`=1) OR (`entry`=226250 AND `item`=224980 AND `ExtendedCost`=9016 AND `type`=1) OR (`entry`=226250 AND `item`=224982 AND `ExtendedCost`=9016 AND `type`=1) OR (`entry`=226250 AND `item`=224960 AND `ExtendedCost`=9016 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(208070, 45, 211040, 0, 9021, 1, 124049, 1, 56513), -- Unhinged Vault-Hatch
(208070, 44, 211041, 0, 9021, 1, 124049, 1, 56513), -- Brilliant Beacon
(208070, 43, 211046, 0, 9021, 1, 124049, 1, 56513), -- Umbral Artist's Chisel
(208070, 42, 211047, 0, 9021, 1, 124049, 1, 56513), -- Lapidarius Gemcutter
(208070, 41, 211048, 0, 9021, 1, 124049, 1, 56513), -- Pathfinder's Stonecarver
(208070, 40, 211059, 0, 9022, 1, 124049, 1, 56513), -- Luminous Lampspire
(208070, 39, 219351, 0, 9022, 1, 124049, 1, 56513), -- Mana-Lined Slab Slicer
(208070, 38, 219352, 0, 9022, 1, 124049, 1, 56513), -- Skypiercing Drillstaff
(208070, 37, 219354, 0, 9022, 1, 124049, 1, 56513), -- Mountain Shaper's Greataxe
(208070, 36, 219353, 0, 9022, 1, 124049, 1, 56513), -- Trailblazer's Hookshoot
(208070, 35, 219355, 0, 9021, 1, 124049, 1, 56513), -- Bedrock Breaker
(208070, 34, 219356, 0, 9021, 1, 124049, 1, 56513), -- Torchlit Pickaxe
(208070, 33, 211052, 0, 9020, 1, 124049, 1, 56513), -- Olden Signet
(208070, 32, 211051, 0, 9020, 1, 124049, 1, 56513), -- Loop of Vestigial Power
(208070, 31, 211061, 0, 9020, 1, 124049, 1, 56513), -- Unearthed Relic Band
(208070, 30, 211063, 0, 9020, 1, 124049, 1, 56513), -- Long-Lost Choker
(208070, 29, 211062, 0, 9020, 1, 124049, 1, 56513), -- Treasure-Seeker's Shawl
(208070, 28, 211007, 0, 9020, 1, 124049, 1, 56513), -- Torchbearer's Greatcloak
(208070, 27, 211006, 0, 9020, 1, 124049, 1, 56513), -- Secret-Dredger's Cloak
(208070, 26, 211005, 0, 9020, 1, 124049, 1, 56513), -- Cave Topographer's Drape
(208070, 25, 224839, 0, 8450, 1, 124049, 1, 56513), -- Adventurer's Warbound Wrists
(208070, 24, 224840, 0, 8450, 1, 124049, 1, 56513), -- Adventurer's Warbound Waist
(208070, 23, 224844, 0, 8449, 1, 124049, 1, 56513), -- Adventurer's Warbound Gloves
(208070, 22, 224814, 0, 8449, 1, 124049, 1, 56513), -- Adventurer's Warbound Boots
(208070, 21, 224841, 0, 8449, 1, 124049, 1, 56513), -- Adventurer's Warbound Shoulders
(208070, 20, 224842, 0, 8448, 1, 124049, 1, 56513), -- Adventurer's Warbound Legs
(208070, 19, 224845, 0, 8448, 1, 124049, 1, 56513), -- Adventurer's Warbound Chestpiece
(208070, 18, 224843, 0, 8448, 1, 124049, 1, 56513), -- Adventurer's Warbound Headpiece
(208070, 17, 221502, 0, 8589, 1, 124049, 0, 56513), -- Adventurer's Warbound Battlegear Drop
(208070, 16, 226259, 0, 9098, 1, 0, 0, 56513), -- Delver's Pouch of Resonance Crystals
(208070, 15, 226258, 0, 9099, 1, 0, 0, 56513), -- Delver's Pouch of Reagents
(208070, 14, 211931, 0, 9013, 1, 0, 0, 56513), -- Abyss Caller Horn
(208070, 13, 228413, 0, 9013, 1, 0, 0, 56513), -- Lampyridae Lure
(208070, 12, 225910, 0, 9013, 1, 0, 0, 56513), -- Pileus Delight
(208070, 11, 222974, 0, 8492, 1, 0, 0, 56513), -- Sir Shady Mrrgglton Junior
(208070, 10, 224770, 0, 9008, 1, 0, 0, 56513), -- Delver's Dirigible Schematic: Front-Mounted Propeller
(208070, 9, 224768, 0, 9008, 1, 0, 0, 56513), -- Delver's Dirigible Schematic: Wing-Mounted Propeller
(208070, 8, 224769, 0, 9014, 1, 0, 0, 56513), -- Delver's Dirigible Schematic: Rotor Blades
(208070, 7, 224771, 0, 9015, 1, 0, 0, 56513), -- Delver's Dirigible Schematic: Empennage
(208070, 6, 232498, 0, 8452, 1, 130624, 0, 56513), -- -Unknown-
(208070, 5, 232497, 0, 8452, 1, 130623, 0, 56513), -- -Unknown-
(208070, 4, 232496, 0, 8452, 1, 130622, 0, 56513), -- -Unknown-
(226250, 54, 225508, 0, 9045, 1, 0, 0, 56513), -- Unhinged Vault-Hatch
(226250, 53, 225507, 0, 9045, 1, 0, 0, 56513), -- Brilliant Beacon
(226250, 52, 225506, 0, 9044, 1, 0, 0, 56513), -- Mana-Lined Slab Slicer
(226250, 51, 225505, 0, 9044, 1, 0, 0, 56513), -- Luminous Lampspire
(226250, 50, 225504, 0, 9044, 1, 0, 0, 56513), -- Skypiercing Drillstaff
(226250, 49, 225503, 0, 9044, 1, 0, 0, 56513), -- Trailblazer's Hookshoot
(226250, 48, 225502, 0, 9044, 1, 0, 0, 56513), -- Mountain Shaper's Greataxe
(226250, 47, 225501, 0, 9045, 1, 0, 0, 56513), -- Pathfinder's Stonecarver
(226250, 46, 225500, 0, 9045, 1, 0, 0, 56513), -- Bedrock Breaker
(226250, 45, 225499, 0, 9045, 1, 0, 0, 56513), -- Lapidarius Gemcutter
(226250, 44, 225498, 0, 9045, 1, 0, 0, 56513), -- Umbral Artist's Chisel
(226250, 43, 225497, 0, 9045, 1, 0, 0, 56513), -- Torchlit Pickaxe
(226250, 42, 225411, 0, 9042, 1, 0, 0, 56513), -- Secret-Dredger's Cloak
(226250, 41, 225410, 0, 9042, 1, 0, 1, 56513), -- Secret-Dredger's Armplates
(226250, 40, 225409, 0, 9042, 1, 0, 1, 56513), -- Secret-Dredger's Girdle
(226250, 39, 225408, 0, 9043, 1, 0, 1, 56513), -- Secret-Dredger's Mantle
(226250, 38, 225407, 0, 8493, 1, 0, 1, 56513), -- Secret-Dredger's Legguards
(226250, 37, 225406, 0, 8493, 1, 0, 1, 56513), -- Secret-Dredger's Helm
(226250, 36, 225405, 0, 9043, 1, 0, 1, 56513), -- Secret-Dredger's Gauntlets
(226250, 35, 225404, 0, 9043, 1, 0, 1, 56513), -- Secret-Dredger's Sabatons
(226250, 34, 225403, 0, 8493, 1, 0, 1, 56513), -- Secret-Dredger's Breastplate
(226250, 33, 225412, 0, 9042, 1, 0, 0, 56513), -- Torchbearer's Greatcloak
(226250, 32, 225386, 0, 9042, 1, 0, 1, 56513), -- Torchbearer's Bracers
(226250, 31, 225380, 0, 9042, 1, 0, 1, 56513), -- Torchbearer's Cinch
(226250, 30, 225385, 0, 9043, 1, 0, 1, 56513), -- Torchbearer's Shoulderguards
(226250, 29, 225384, 0, 8493, 1, 0, 1, 56513), -- Torchbearer's Greaves
(226250, 28, 225383, 0, 8493, 1, 0, 1, 56513), -- Torchbearer's Coif
(226250, 27, 225382, 0, 9043, 1, 0, 1, 56513), -- Torchbearer's Grips
(226250, 26, 225381, 0, 9043, 1, 0, 1, 56513), -- Torchbearer's Striders
(226250, 25, 225379, 0, 8493, 1, 0, 1, 56513), -- Torchbearer's Chainmail
(226250, 24, 225413, 0, 9042, 1, 0, 0, 56513), -- Treasure-Seeker's Shawl
(226250, 23, 225402, 0, 9042, 1, 0, 1, 56513), -- Treasure-Seeker's Bindings
(226250, 22, 225401, 0, 9042, 1, 0, 1, 56513), -- Treasure-Seeker's Sash
(226250, 21, 225400, 0, 9043, 1, 0, 1, 56513), -- Treasure-Seeker's Epaulets
(226250, 20, 225399, 0, 8493, 1, 0, 1, 56513), -- Treasure-Seeker's Breeches
(226250, 19, 225398, 0, 8493, 1, 0, 1, 56513), -- Treasure-Seeker's Helm
(226250, 18, 225397, 0, 9043, 1, 0, 1, 56513), -- Treasure-Seeker's Grips
(226250, 17, 225396, 0, 9043, 1, 0, 1, 56513), -- Treasure-Seeker's Boots
(226250, 16, 225395, 0, 8493, 1, 0, 1, 56513), -- Treasure-Seeker's Vest
(226250, 15, 225414, 0, 9042, 1, 0, 0, 56513), -- Cave Topographer's Drape
(226250, 14, 225394, 0, 9042, 1, 0, 1, 56513), -- Cave Topographer's Cuffs
(226250, 13, 225393, 0, 9042, 1, 0, 1, 56513), -- Cave Topographer's Cord
(226250, 12, 225392, 0, 9043, 1, 0, 1, 56513), -- Cave Topographer's Shoulders
(226250, 11, 225391, 0, 8493, 1, 0, 1, 56513), -- Cave Topographer's Leggings
(226250, 10, 225390, 0, 8493, 1, 0, 1, 56513), -- Cave Topographer's Cowl
(226250, 9, 225389, 0, 9043, 1, 0, 1, 56513), -- Cave Topographer's Handwraps
(226250, 8, 225388, 0, 9043, 1, 0, 1, 56513), -- Cave Topographer's Sandals
(226250, 7, 225387, 0, 8493, 1, 0, 1, 56513), -- Cave Topographer's Vestment
(226250, 6, 223312, 0, 9016, 1, 124105, 0, 56513), -- Trusty Hat
(226250, 5, 224981, 0, 9016, 1, 124150, 0, 56513), -- Delver's Dirigible Schematic: Brown Paint
(226250, 4, 224979, 0, 9016, 1, 124148, 0, 56513), -- Delver's Dirigible Schematic: Zeppelin
(226250, 3, 224980, 0, 9016, 1, 124149, 0, 56513), -- Delver's Dirigible Schematic: Front-Mounted Lantern
(226250, 2, 224982, 0, 9016, 1, 124151, 0, 56513), -- Delver's Dirigible Schematic: Exhaust
(226250, 1, 224960, 0, 9016, 1, 124147, 0, 56513); -- Delver's Dirigible Schematic: Lantern Wing
