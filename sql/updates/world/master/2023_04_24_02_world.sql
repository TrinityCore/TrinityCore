SET @CGUID := 9003510;
SET @OGUID := 9000356;

SET @NPCTEXTID := 590063;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 201312, 0, 1519, 5390, '0', 0, 0, 0, 1, -8834.4306640625, 846.55731201171875, 100.0329742431640625, 2.239473342895507812, 120, 0, 0, 271005, 21588, 0, 0, 0, 0, 48999), -- Warpweaver Taxoss (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+1, 198579, 0, 1519, 5390, '0', 0, 0, 0, 1, -8826.6044921875, 868.62677001953125, 98.93257904052734375, 0, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48999), -- Valarian (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+2, 198589, 0, 1519, 5390, '0', 0, 0, 0, 0, -8816.67578125, 831.04168701171875, 99.0924224853515625, 6.227503776550292968, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48999), -- Dilya (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+3, 185468, 0, 1519, 5390, '0', 0, 0, 0, 0, -8828.15625, 837.295166015625, 99.56524658203125, 4.694650173187255859, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999), -- Tawny Seabraid (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+4, 198581, 0, 1519, 5390, '0', 0, 0, 0, 0, -8812.6181640625, 841.07293701171875, 99.1856536865234375, 1.522986412048339843, 120, 0, 0, 225838, 0, 0, 0, 0, 0, 48999), -- Sam Corff (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+5, 185467, 0, 1519, 5390, '0', 0, 0, 0, 0, -8830.7412109375, 835.4132080078125, 99.60166168212890625, 5.549360275268554687, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Wilder Seabraid (Area: The Canals - Difficulty: 0) CreateObject1

-- remove old worker spawn
DELETE FROM `creature` WHERE `guid` = 1051065;
DELETE FROM `creature_addon` WHERE `guid` = 1051065;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 377200, 0, 1519, 5390, '0', 0, 0, -8833.8857421875, 831.6319580078125, 99.2657012939453125, 5.746389389038085937, 0, 0, -0.26518726348876953, 0.96419692039489746, 120, 255, 1, 48999), -- Collector's Cache (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+1, 386352, 0, 1519, 5390, '0', 0, 0, -8825.72265625, 836.734375, 101.3313369750976562, 3.658707380294799804, -0.18628168106079101, 0.66533660888671875, -0.70127487182617187, 0.175612986087799072, 120, 255, 1, 48999); -- Trading Post Post (Area: The Canals - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (386352 /*Trading Post Post*/, 377200 /*Collector's Cache*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(386352, 0, 262144, 0, 0), -- Trading Post Post
(377200, 0, 262144, 0, 0); -- Collector's Cache

DELETE FROM `gameobject_template` WHERE `entry` IN (377200 /*Collector's Cache*/, 386352 /*Trading Post Post*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(377200, 62, 79144, 'Collector\'s Cache', '', '', '', 1, 77779, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 444, 48999), -- Collector's Cache
(386352, 10, 79862, 'Trading Post Post', '', '', '', 0.300000011920928955, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30556, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 444, 48999); -- Trading Post Post

-- Creature Template
UPDATE `creature_template` SET `faction`=12, `npcflag`=2251799813685249, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=185467; -- Wilder Seabraid
UPDATE `creature_template` SET `faction`=12, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=198581; -- Sam Corff
UPDATE `creature_template` SET `faction`=12, `npcflag`=2251799813685251, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=185468; -- Tawny Seabraid
UPDATE `creature_template` SET `faction`=12, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=198589; -- Dilya
UPDATE `creature_template` SET `faction`=35, `npcflag`=268435585, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=201312; -- Warpweaver Taxoss
UPDATE `creature_template` SET `faction`=12, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=198579; -- Valarian

-- Creature Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (198579,201312));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(198579, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0, 48999), -- Valarian
(201312, 1, 71739, 0, 0, 71741, 0, 0, 0, 0, 0, 48999); -- Warpweaver Taxoss

-- Gossip & Text
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=201312 AND `MenuID`=21043) OR (`CreatureID`=198579 AND `MenuID`=30210) OR (`CreatureID`=198589 AND `MenuID`=30123) OR (`CreatureID`=198581 AND `MenuID`=30124) OR (`CreatureID`=185467 AND `MenuID`=30312) OR (`CreatureID`=185468 AND `MenuID`=30315);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(201312, 21043, 48999), -- Warpweaver Taxoss
(198579, 30210, 48999), -- Valarian
(198589, 30123, 48999), -- Dilya
(198581, 30124, 48999), -- Sam Corff
(185467, 30312, 48999), -- Wilder Seabraid
(185468, 30315, 48999); -- Tawny Seabraid

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+8;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 232985, 0, 0, 0, 0, 0, 0, 0, 48999), -- 198579 (Valarian)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 232693, 0, 0, 0, 0, 0, 0, 0, 48999), -- 198589 (Dilya)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 232694, 0, 0, 0, 0, 0, 0, 0, 48999), -- 198581 (Sam Corff)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 233637, 0, 0, 0, 0, 0, 0, 0, 48999), -- 185467 (Wilder Seabraid)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 234629, 0, 0, 0, 0, 0, 0, 0, 48999), -- 185468 (Tawny Seabraid)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 235387, 0, 0, 0, 0, 0, 0, 0, 48999), -- 386352 (Trading Post Post)
(@NPCTEXTID+6, 1, 0, 0, 0, 0, 0, 0, 0, 235388, 0, 0, 0, 0, 0, 0, 0, 48999), -- 386352 (Trading Post Post)
(@NPCTEXTID+7, 1, 0, 0, 0, 0, 0, 0, 0, 235389, 0, 0, 0, 0, 0, 0, 0, 48999), -- 386352 (Trading Post Post)
(@NPCTEXTID+8, 1, 0, 0, 0, 0, 0, 0, 0, 235391, 0, 0, 0, 0, 0, 0, 0, 48999); -- 386352 (Trading Post Post)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30210 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30123 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=30124 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=30312 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=30315 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=30556 AND `TextID`=@NPCTEXTID+5) OR (`MenuID`=30557 AND `TextID`=@NPCTEXTID+6) OR (`MenuID`=30558 AND `TextID`=@NPCTEXTID+7) OR (`MenuID`=30560 AND `TextID`=@NPCTEXTID+8);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30210, @NPCTEXTID+0, 48999), -- 198579 (Valarian)
(30123, @NPCTEXTID+1, 48999), -- 198589 (Dilya)
(30124, @NPCTEXTID+2, 48999), -- 198581 (Sam Corff)
(30312, @NPCTEXTID+3, 48999), -- 185467 (Wilder Seabraid)
(30315, @NPCTEXTID+4, 48999), -- 185468 (Tawny Seabraid)
(30556, @NPCTEXTID+5, 48999), -- 386352 (Trading Post Post)
(30557, @NPCTEXTID+6, 48999), -- 386352 (Trading Post Post)
(30558, @NPCTEXTID+7, 48999), -- 386352 (Trading Post Post)
(30560, @NPCTEXTID+8, 48999); -- 386352 (Trading Post Post)

DELETE FROM `gossip_menu_option` WHERE (`OptionID` IN (0, 1, 3) AND `MenuID` IN (30312,30315,30556));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(107824, 30312, 0, 47, 'I\'d like to see what you have to offer this month.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999),
(107827, 30315, 0, 47, 'I\'d like to see what you have to offer this month.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999),
(108167, 30556, 0, 0, '<Read the section about \"Goods\">', 0, 0, 30557, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999),
(108166, 30556, 1, 0, '<Read the section about \"Activities\">', 0, 0, 30558, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999),
(108164, 30556, 3, 0, '<Read the section about \"Purchasing\">', 0, 0, 30560, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999);

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`Entry`=199731 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(199731, 0, 0, 0, 864, 48999);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (14438,133704,111190,185467,152643,133509,198482,30730,51348,1312,49701,5494,30713,42288,338,198529,5493,198581,32520,42339,1318,185669,140253,185468,1976,198589,1317,197287,49893,46180,185670,49540,198579,11068,5386,1316,52031,201312,183978,185672,199602,1315));

DELETE FROM `creature_model_info` WHERE `DisplayID`=104792;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(104792, 5.723157882690429687, 6, 0, 48999);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=201312 AND `item`=202308 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202307 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202306 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202305 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202304 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202303 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202301 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=202300 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=202298 AND `ExtendedCost`=7856 AND `type`=1) OR (`entry`=201312 AND `item`=202297 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=202296 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=202295 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=190888 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190858 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190830 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190803 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190697 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190686 AND `ExtendedCost`=7854 AND `type`=1) OR (`entry`=201312 AND `item`=190673 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190544 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190429 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190202 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190167 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=190064 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=189870 AND `ExtendedCost`=7855 AND `type`=1) OR (`entry`=201312 AND `item`=188249 AND `ExtendedCost`=7234 AND `type`=1) OR (`entry`=201312 AND `item`=188248 AND `ExtendedCost`=7234 AND `type`=1) OR (`entry`=201312 AND `item`=188244 AND `ExtendedCost`=7235 AND `type`=1) OR (`entry`=201312 AND `item`=188243 AND `ExtendedCost`=7235 AND `type`=1) OR (`entry`=201312 AND `item`=188237 AND `ExtendedCost`=7236 AND `type`=1) OR (`entry`=201312 AND `item`=188236 AND `ExtendedCost`=7236 AND `type`=1) OR (`entry`=201312 AND `item`=151116 AND `ExtendedCost`=6211 AND `type`=1) OR (`entry`=201312 AND `item`=151120 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=151119 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=151118 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=151117 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=157577 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=157576 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=157574 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=157573 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=164378 AND `ExtendedCost`=6444 AND `type`=1) OR (`entry`=201312 AND `item`=168061 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=168060 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=168059 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=201312 AND `item`=168058 AND `ExtendedCost`=6188 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(201312, 45, 202308, 0, 7856, 1, 0, 0, 48999), -- Alley Skulker's Bandana
(201312, 44, 202307, 0, 7856, 1, 0, 0, 48999), -- Well-Worn Tricorne
(201312, 43, 202306, 0, 7856, 1, 0, 0, 48999), -- Dread Captain's Chapeau
(201312, 42, 202305, 0, 7856, 1, 0, 0, 48999), -- Stevedore's Skullcap
(201312, 41, 202304, 0, 7856, 1, 0, 0, 48999), -- Green Beanie
(201312, 40, 202303, 0, 7856, 1, 0, 0, 48999), -- Crimson Beanie
(201312, 39, 202301, 0, 7854, 1, 0, 0, 48999), -- Focalized Mana Accelerator
(201312, 38, 202300, 0, 7854, 1, 0, 0, 48999), -- Zealot's Prayer Staff
(201312, 37, 202298, 0, 7856, 1, 0, 0, 48999), -- Trader's Bicorne
(201312, 36, 202297, 0, 7854, 1, 0, 0, 48999), -- Jade Arcus
(201312, 35, 202296, 0, 7854, 1, 0, 0, 48999), -- Deathmantle Ripper
(201312, 34, 202295, 0, 7854, 1, 0, 0, 48999), -- Anointed Crusader's Claymore
(201312, 33, 190888, 0, 7855, 1, 0, 0, 48999), -- Embrace of the Great Dark Beyond
(201312, 32, 190858, 0, 7855, 1, 0, 0, 48999), -- Girdle of Chilled Embers
(201312, 31, 190830, 0, 7855, 1, 0, 0, 48999), -- Mad Thief's Boots
(201312, 30, 190803, 0, 7855, 1, 0, 0, 48999), -- Lost Acolyte's Boots
(201312, 29, 190697, 0, 7855, 1, 0, 0, 48999), -- Boots of a Broken World
(201312, 28, 190686, 0, 7854, 1, 0, 0, 48999), -- Anetheron's Edge
(201312, 27, 190673, 0, 7855, 1, 0, 0, 48999), -- Waistguard of the Infernal Eye
(201312, 26, 190544, 0, 7855, 1, 0, 0, 48999), -- Ultramafic Girdle
(201312, 25, 190429, 0, 7855, 1, 0, 0, 48999), -- Clasp of Ursine Rage
(201312, 24, 190202, 0, 7855, 1, 0, 0, 48999), -- Scoundrel's Missing Boots
(201312, 23, 190167, 0, 7855, 1, 0, 0, 48999), -- Vault Stalker's Greaves
(201312, 22, 190064, 0, 7855, 1, 0, 0, 48999), -- Ymirjar Berserker's Girdle
(201312, 21, 189870, 0, 7855, 1, 0, 0, 48999), -- Arcanofire Wrap
(201312, 20, 188249, 0, 7234, 1, 0, 0, 48999), -- Freezing Footguards
(201312, 19, 188248, 0, 7234, 1, 0, 0, 48999), -- Searing Stompers
(201312, 18, 188244, 0, 7235, 1, 0, 0, 48999), -- Virulent Gravetreaders
(201312, 17, 188243, 0, 7235, 1, 0, 0, 48999), -- Shadow-Stitched Stalkers
(201312, 16, 188237, 0, 7236, 1, 0, 0, 48999), -- Conjuror's Slippers
(201312, 15, 188236, 0, 7236, 1, 0, 0, 48999), -- Patroller's Footwear
(201312, 14, 151116, 0, 6211, 1, 50225, 0, 48999), -- Fashionable Undershirt
(201312, 13, 151120, 0, 6188, 1, 9206, 0, 48999), -- Ensemble: Righteous Battleplate
(201312, 12, 151119, 0, 6188, 1, 4617, 0, 48999), -- Ensemble: Der'izu Armor
(201312, 11, 151118, 0, 6188, 1, 17097, 0, 48999), -- Ensemble: Obsidian Prowler's Garb
(201312, 10, 151117, 0, 6188, 1, 0, 0, 48999), -- Ensemble: Mana-Etched Regalia
(201312, 9, 157577, 0, 6188, 1, 9206, 0, 48999), -- Ensemble: Goldspine Plate
(201312, 8, 157576, 0, 6188, 1, 4617, 0, 48999), -- Ensemble: Crimson Sentinel Garb
(201312, 7, 157574, 0, 6188, 1, 17097, 0, 48999), -- Ensemble: Tundraspite Armor
(201312, 6, 157573, 0, 6188, 1, 0, 0, 48999), -- Ensemble: Mindwrack Raiment
(201312, 5, 164378, 0, 6444, 1, 0, 0, 48999), -- Letter from an Admirer
(201312, 4, 168061, 0, 6188, 1, 9206, 0, 48999), -- Ensemble: Amaranthine Path Armor
(201312, 3, 168060, 0, 6188, 1, 4617, 0, 48999), -- Ensemble: Chainmail of the Timeless Hunt
(201312, 2, 168059, 0, 6188, 1, 17097, 0, 48999), -- Ensemble: Restless Dreambound Battlegear
(201312, 1, 168058, 0, 6188, 1, 0, 0, 48999); -- Ensemble: Tranquil Spiritbind Regalia
