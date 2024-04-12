-- Template
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (101790, 101787, 101789, 101788); -- Demon Hunter
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=96501; -- Ashtongue Mystic
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=96504; -- Shivarra Destroyer
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=96502; -- Coilskar Myrmidon
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=2048 WHERE `entry`=96503; -- Coilskar Sea-Caller
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=96500; -- Ashtongue Warrior

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_jayce_darkweaver_cryptic_hollow' WHERE `entry` = 96436;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_demon_hunter_hidden_no_more_private' WHERE `entry` IN (101787, 101788, 101789, 101790);
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_basic_hidden_no_more_private' WHERE `entry` IN (96501, 96502, 96503, 96500);

UPDATE `creature` SET `StringId` = 'CrypticHollowDh01' WHERE `guid` = 6000987;
UPDATE `creature` SET `StringId` = 'CrypticHollowDh02' WHERE `guid` = 6000983;
UPDATE `creature` SET `StringId` = 'CrypticHollowDh03' WHERE `guid` = 6000985;
UPDATE `creature` SET `StringId` = 'CrypticHollowDh04' WHERE `guid` = 6000973;
UPDATE `creature` SET `StringId` = 'CrypticHollowDh05' WHERE `guid` = 6000977;

UPDATE `creature` SET `StringId` = 'CrypticHollowCoilskar01' WHERE `guid` = 6000979;
UPDATE `creature` SET `StringId` = 'CrypticHollowCoilskar02' WHERE `guid` = 6000986;
UPDATE `creature` SET `StringId` = 'CrypticHollowCoilskar03' WHERE `guid` = 6000974;

UPDATE `creature` SET `StringId` = 'CrypticHollowAshtongue01' WHERE `guid` = 6000984;
UPDATE `creature` SET `StringId` = 'CrypticHollowAshtongue02' WHERE `guid` = 6000978;
UPDATE `creature` SET `StringId` = 'CrypticHollowAshtongue03' WHERE `guid` = 6000982;

UPDATE `quest_template_addon` SET `ScriptName` = 'quest_hidden_no_more' WHERE `ID` = 39495;

-- Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 96502;

DELETE FROM `creature_addon` WHERE `guid` = 6000861;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(6000861, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474');

-- Spelltarget
DELETE FROM `spell_target_position` WHERE (`ID`=194376 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(194376, 0, 1481, 1267.8499755859375, 1633.199951171875, 102.1699981689453125, 53913); -- Spell: 194376 (Hidden No More: Quest Abandon) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Creature text
DELETE FROM `creature_text` WHERE (`CreatureID` = 96436 AND `GroupID` = 1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96436, 1, 0, 'They won\'t escape us. Illidari, attack!', 14, 0, 100, 397, 0, 55234, 98271, 0, 'Jace Darkweaver to Player');

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96436 AND `DifficultyID`=0); -- Jace Darkweaver
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`DifficultyID`=0 AND `Entry` IN (101790,101787,101789,101788)); -- Demon Hunter
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96501 AND `DifficultyID`=0); -- Ashtongue Mystic
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96504 AND `DifficultyID`=0); -- Shivarra Destroyer
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96502 AND `DifficultyID`=0); -- Coilskar Myrmidon
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96503 AND `DifficultyID`=0); -- Coilskar Sea-Caller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53913 WHERE (`Entry`=96500 AND `DifficultyID`=0); -- Ashtongue Warrior

-- convert SAI to c++
DELETE FROM `smart_scripts` WHERE `entryorguid` = 96436;

-- Path for Jayce Darkweaver
SET @ENTRY := 96436;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Jace Darkweaver - After jump into the Cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1231.3232, 1646.1763, 102.104324, NULL, 0),
(@PATH, 1, 1228.3232, 1648.1763, 101.854324, NULL, 0),
(@PATH, 2, 1226.3232, 1649.4263, 101.854324, NULL, 0),
(@PATH, 3, 1226.0732, 1649.6763, 101.854324, NULL, 0),
(@PATH, 4, 1221.8232, 1654.6763, 101.354324, NULL, 0),
(@PATH, 5, 1221.5732, 1654.9263, 101.354324, NULL, 0),
(@PATH, 6, 1220.5732, 1655.4263, 101.104324, NULL, 0),
(@PATH, 7, 1220.3232, 1655.9263, 100.854324, NULL, 0),
(@PATH, 8, 1219.5732, 1657.1763, 100.604324, NULL, 0),
(@PATH, 9, 1218.2778, 1659.1702, 99.27652, NULL, 0);

-- Path for 101797
SET @ENTRY := 101787;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Demon Hunter - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1241.542, 1637.384, 101.2027, NULL, 0),
(@PATH, 1, 1235.507, 1640.899, 101.6234, NULL, 0),
(@PATH, 2, 1225.911, 1648.651, 101.7546, NULL, 0),
(@PATH, 3, 1219.118, 1656.618, 100.1757, NULL, 0);

SET @ENTRY := 101787;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Demon Hunter - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1244.908, 1643.186, 101.196, NULL, 0),
(@PATH, 1, 1230.847, 1647.148, 101.9025, NULL, 0),
(@PATH, 2, 1220.007, 1657.832, 100.4984, NULL, 0);

-- Path for 101788
SET @ENTRY := 101788;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Demon Hunter - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1244.205, 1637.681, 101.2138, NULL, 0),
(@PATH, 1, 1236.271, 1641.434, 101.5777, NULL, 0),
(@PATH, 2, 1219.974, 1656.036, 100.7595, NULL, 0);

-- Path for 101789
SET @ENTRY := 101789;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Demon Hunter - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1243.12, 1641.931, 101.1786, NULL, 0),
(@PATH, 1, 1226.87, 1649.651, 101.8028, NULL, 0),
(@PATH, 2, 1220.248, 1657.264, 100.7088, NULL, 0);

-- Path for 101790
SET @ENTRY := 101790;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Demon Hunter - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1241.443, 1634.038, 101.2182, NULL, 0),
(@PATH, 1, 1225.241, 1647.274, 101.8225, NULL, 0),
(@PATH, 2, 1218.104, 1656.582, 99.6631, NULL, 0);

-- Path for 96502
SET @ENTRY := 96502;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Coilskar Myrmidon - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1243.377, 1637.101, 101.212, NULL, 0),
(@PATH, 1, 1235.771, 1641.097, 101.608, NULL, 0),
(@PATH, 2, 1227.807, 1647.467, 101.8113, NULL, 0),
(@PATH, 3, 1218.911, 1657.052, 99.96143, NULL, 0);

-- Path for 96502
SET @ENTRY := 96502;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Coilskar Myrmidon - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1240.778, 1643.863, 101.1712, NULL, 0),
(@PATH, 1, 1236.285, 1644.309, 101.3833, NULL, 0),
(@PATH, 2, 1230.906, 1647.694, 101.8904, NULL, 0);

-- Path for 96503
SET @ENTRY := 96503;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Coilskar Sea Caller - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1241.052, 1635.955, 101.2086, NULL, 0),
(@PATH, 1, 1234.972, 1640.257, 101.6277, NULL, 0),
(@PATH, 2, 1226.205, 1647.845, 101.7648, NULL, 0),
(@PATH, 3, 1216.569, 1658.924, 98.47334, NULL, 0);

-- Path for 96500
SET @ENTRY := 96500;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Ashtongue Warrior - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1239.401, 1643.233, 101.2989, NULL, 0),
(@PATH, 1, 1230.3, 1646.729, 101.9243, NULL, 0),
(@PATH, 2, 1218.313, 1660.059, 99.27374, NULL, 0);

-- Path for 96500
SET @ENTRY := 96500;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Ashtongue Warrior - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1249.576, 1642.826, 101.2186, NULL, 0),
(@PATH, 1, 1240.368, 1642.8, 101.1937, NULL, 0),
(@PATH, 2, 1230.075, 1646.575, 101.9319, NULL, 0),
(@PATH, 3, 1221.061, 1655.795, 101.1307, NULL, 0),
(@PATH, 4, 1216.111, 1661.177, 97.98268, NULL, 0);

-- Path for 96501
SET @ENTRY := 96501;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Ashtongue Mystic - Cryptic Hollow - run into cave');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1249.021, 1643.977, 101.215, NULL, 0),
(@PATH, 1, 1237.769, 1643.149, 101.3568, NULL, 0),
(@PATH, 2, 1228.896, 1647.661, 101.8191, NULL, 0),
(@PATH, 3, 1216.691, 1661.094, 98.30368, NULL, 0);
