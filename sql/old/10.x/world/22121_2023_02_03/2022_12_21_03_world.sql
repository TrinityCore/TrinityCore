SET @CGUID        := 1250041;
SET @NPCTEXTID    := 590017;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197287, 0, 1519, 5390, '0', 0, 0, 0, 0, -8808.9951171875, 786.828125, 98.3684234619140625, 5.193881034851074218, 120, 0, 0, 18771, 100, 0, 0, 0, 0, 46366), -- Annywn Dynaspark (Area: The Canals - Difficulty: 0)
(@CGUID+1, 198482, 0, 1519, 5390, '0', 0, 0, 0, 0, -8802.4033203125, 889.1336669921875, 99.29882049560546875, 1.352678656578063964, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Krozhalan (Area: The Canals - Difficulty: 0) (Auras: 394615 - Cosmetic - Eat)
(@CGUID+2, 198529, 0, 1519, 5390, '0', 0, 0, 0, 0, -8803.9482421875, 890.203125, 99.21649169921875, 0.663119673728942871, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Kotheshal (Area: The Canals - Difficulty: 0) (Auras: 394615 - Cosmetic - Eat)
(@CGUID+3, 198530, 0, 1519, 4411, '0', 0, 0, 0, 0, -8529.375, 1043.6458740234375, 60.08473587036132812, 5.859725475311279296, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Emishalan (Area: Stormwind Harbor - Difficulty: 0) (Auras: 147164 - Read Scroll)
(@CGUID+4, 198515, 0, 1519, 4411, '0', 0, 0, 0, 0, -8528.76953125, 1045.3975830078125, 59.97357559204101562, 2.09993290901184082, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Alzinathel (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+5, 198526, 0, 1519, 5390, '0', 0, 0, 0, 0, -8718.984375, 514.917724609375, 96.8880157470703125, 1.04470527172088623, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213); -- Nirathan (Area: The Canals - Difficulty: 0) (Auras: 147164 - Read Scroll)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (198529, 198482, 198530, 198526);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198529, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 198529 (Kotheshal)
(198482, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 198482 (Krozhalan)
(198530, 0, 0, 0, 1, 0, 0, 0, 0, 0, '147164'), -- 198530 (Emishalan) - Read Scroll
(198526, 0, 0, 0, 1, 0, 0, 0, 0, 0, '147164'); -- 198526 (Nirathan) - Read Scroll

-- Creature Template
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3340, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198529; -- Kotheshal
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=64, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=197287; -- Annywn Dynaspark
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3340, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198482; -- Krozhalan
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3340, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198530; -- Emishalan
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3340, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198515; -- Alzinathel
UPDATE `creature_template` SET `gossip_menu_id`=30141, `minlevel`=70, `maxlevel`=70, `faction`=3340, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198526; -- Nirathan

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (53716,53715));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(53716, 0, 0, 0, 303, 47213),
(53715, 0, 1, 1, 303, 47213);

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 232806, 0, 0, 0, 0, 0, 0, 0, 47213); -- 198526 (Nirathan)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30141 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30141, @NPCTEXTID+0, 47213); -- 198526 (Nirathan)

-- Waypoints for CGUID+0
SET @PATH := (@CGUID+0) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8814.507, 792.2778, 97.73765, NULL, 0),
(@PATH, 1, -8819.45, 798.9913, 97.94736, NULL, 0),
(@PATH, 2, -8820.842, 806.2621, 98.58505, NULL, 0),
(@PATH, 3, -8822.87, 820.8438, 98.95956, NULL, 0),
(@PATH, 4, -8821.888, 834.8386, 98.98161, NULL, 0),
(@PATH, 5, -8821.936, 848.8246, 99.18327, NULL, 0),
(@PATH, 6, -8821.639, 861.4236, 99.11344, NULL, 0),
(@PATH, 7, -8816.316, 868.3246, 99.20309, NULL, 0),
(@PATH, 8, -8809.826, 874.2952, 99.05758, NULL, 0),
(@PATH, 9, -8803.427, 877.934, 99.32101, NULL, 0),
(@PATH, 10, -8801.122, 879.0504, 99.18258, NULL, 0),
(@PATH, 11, -8799.665, 880.3195, 99.23142, NULL, 9994),
(@PATH, 12, -8808.078, 885.6736, 98.93258, NULL, 0),
(@PATH, 13, -8813.71, 890.5573, 98.55758, NULL, 0),
(@PATH, 14, -8821.896, 899.5243, 98.61739, NULL, 0),
(@PATH, 15, -8828.185, 906.8299, 98.68253, NULL, 0),
(@PATH, 16, -8837.42, 914.4358, 99.52372, NULL, 0),
(@PATH, 17, -8843.139, 920.0293, 101.1393, NULL, 0),
(@PATH, 18, -8850.498, 931.5295, 102.4183, NULL, 0),
(@PATH, 19, -8852.326, 934.6996, 102.5914, NULL, 0),
(@PATH, 20, -8847.835, 937.7656, 103.1135, NULL, 18357),
(@PATH, 21, -8853.259, 935.4305, 102.6791, NULL, 0),
(@PATH, 22, -8850.408, 928.625, 102.4003, NULL, 0),
(@PATH, 23, -8846.337, 920.8542, 101.5794, NULL, 0),
(@PATH, 24, -8837.514, 910.9271, 98.63798, NULL, 0),
(@PATH, 25, -8831.37, 904.3004, 98.40372, NULL, 0),
(@PATH, 26, -8818.661, 893.3004, 98.55758, NULL, 0),
(@PATH, 27, -8809.279, 885.9757, 98.93258, NULL, 0),
(@PATH, 28, -8801.634, 881.0677, 99.17379, NULL, 0),
(@PATH, 29, -8799.721, 880.1511, 99.23142, NULL, 0),
(@PATH, 30, -8799.406, 880.3889, 99.23142, NULL, 7777),
(@PATH, 31, -8806.439, 875.8125, 99.05758, NULL, 0),
(@PATH, 32, -8811.896, 871.9566, 99.23519, NULL, 0),
(@PATH, 33, -8816.747, 865.3941, 99.11344, NULL, 0),
(@PATH, 34, -8820.073, 861.5313, 99.11344, NULL, 0),
(@PATH, 35, -8821.531, 852.4427, 99.13468, NULL, 0),
(@PATH, 36, -8821.601, 844.8663, 99.11344, NULL, 0),
(@PATH, 37, -8821.207, 832.0851, 98.95956, NULL, 0),
(@PATH, 38, -8822.404, 821.1979, 98.95956, NULL, 0),
(@PATH, 39, -8823.567, 810.3941, 98.87851, NULL, 0),
(@PATH, 40, -8823.935, 797.5504, 97.61265, NULL, 0),
(@PATH, 41, -8818.752, 793.842, 97.65635, NULL, 0),
(@PATH, 42, -8813.341, 790.7083, 97.75303, NULL, 0),
(@PATH, 43, -8809.939, 788.6354, 98.3247, NULL, 0),
(@PATH, 44, -8808.995, 786.8281, 98.36842, NULL, 22745);

UPDATE `creature` SET `position_x`= -8814.507, `position_y`= 792.2778, `position_z`= 97.73765, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+0, @PATH, 1);

-- Waypoints for CGUID+3
DELETE FROM `creature_formations` WHERE `leaderGUID` = 1250044;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(1250044, 1250044, 0, 0, 515, 0, 0),
(1250044, 1250045, 2, 270, 515, 11, 19);

SET @PATH := (@CGUID+3) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8533.252, 1027.401, 59.90279, NULL, 0),
(@PATH, 1, -8522.408, 1014.59, 59.93111, NULL, 0),
(@PATH, 2, -8500.719, 1002.253, 60.96925, NULL, 0),
(@PATH, 3, -8485.212, 983.7344, 72.90278, NULL, 0),
(@PATH, 4, -8473.594, 992.0035, 79.30903, NULL, 0),
(@PATH, 5, -8467.167, 985.3229, 79.17495, NULL, 0),
(@PATH, 6, -8472.647, 980.2483, 81.29449, NULL, 0),
(@PATH, 7, -8490.598, 967.2274, 96.01039, NULL, 0),
(@PATH, 8, -8498.349, 960.5764, 95.90277, NULL, 0),
(@PATH, 9, -8502.036, 955.691, 95.90277, NULL, 0),
(@PATH, 10, -8516.408, 955.507, 95.91564, NULL, 0),
(@PATH, 11, -8515.763, 961.7882, 96.18616, NULL, 10803),
(@PATH, 12, -8497.915, 961.684, 96.06233, NULL, 0),
(@PATH, 13, -8479.681, 974.1893, 88.14774, NULL, 0),
(@PATH, 14, -8471.341, 980.4809, 80.50921, NULL, 0),
(@PATH, 15, -8466.941, 985.1979, 79.18344, NULL, 0),
(@PATH, 16, -8472.203, 991.4236, 79.29394, NULL, 0),
(@PATH, 17, -8485.833, 982.2153, 72.90278, NULL, 0),
(@PATH, 18, -8499.183, 998.5139, 62.78796, NULL, 51),
(@PATH, 19, -8529.375, 1043.646, 60.08474, NULL, 10973);

UPDATE `creature` SET `position_x`= -8533.252, `position_y`= 1027.401, `position_z`= 59.90279, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+3, @PATH, 1, '147164');

-- Waypoints for CGUID+5
SET @PATH := (@CGUID+5) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8714.966, 520.6805, 97.15485, NULL, 0),
(@PATH, 1, -8716.672, 523.1771, 97.84003, NULL, 2631),
(@PATH, 2, -8726.973, 516.7899, 97.21904, 0.63775, 9303),
(@PATH, 3, -8725.563, 510.875, 96.6385, NULL, 0),
(@PATH, 4, -8727.592, 507.6771, 96.51496, NULL, 0),
(@PATH, 5, -8730.75, 504.8108, 96.52827, NULL, 0),
(@PATH, 6, -8735.616, 500.6927, 96.67881, NULL, 2404),
(@PATH, 7, -8728.669, 507.7778, 96.5135, NULL, 0),
(@PATH, 8, -8724.848, 510.1389, 96.6385, NULL, 0),
(@PATH, 9, -8721.272, 510.6024, 96.6385, NULL, 0),
(@PATH, 10, -8719.946, 507.7587, 96.5948, NULL, 0),
(@PATH, 11, -8717.813, 504.3958, 96.3885, NULL, 2043),
(@PATH, 12, -8720.504, 512.3004, 96.80207, NULL, 0),
(@PATH, 13, -8718.976, 514.9323, 96.8885, NULL, 0),
(@PATH, 14, -8715.689, 517.3941, 96.94318, NULL, 0);

UPDATE `creature` SET `position_x`= -8714.966, `position_y`= 520.6805, `position_z`= 97.15485, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID+5, @PATH, 1, '147164');
