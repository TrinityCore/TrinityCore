DELETE FROM `creature` WHERE `guid` IN (356881, 357029, 351758);
DELETE FROM `creature_addon` WHERE `guid` IN (356881, 357029, 351758);

-- Creature Earthmender Narvra 44361 SAI
SET @ENTRY := 44361;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 80470, 0, 0, 0, 0, 0, 10, 350062, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1000 and 1000 ms) - Self: Cast spell White Braid Channel (80470) on Creature Generic Trigger LAB (Large AOI) 28332 (350062) // ");

-- Creature Earthmender Govrum 44362 SAI
SET @ENTRY := 44362;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 80470, 0, 0, 0, 0, 0, 10, 350062, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1000 and 1000 ms) - Self: Cast spell White Braid Channel (80470) on Creature Generic Trigger LAB (Large AOI) 28332 (350062) // ");

SET @CGUID := 350087;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1049.35, 522.7233, -49.33483, 0, -1161),
(@PATH, 1, 1052.5, 515.882, -49.18108, 0, -1795),
(@PATH, 2, 1047.48, 503.852, -49.24801, 0, -983),
(@PATH, 3, 1036.12, 491.123, -49.2957, 0, -604),
(@PATH, 4, 1021.74, 484.271, -49.31447, 0, -1200),
(@PATH, 5, 1007.97, 485.649, -49.28559, 0, -1200),
(@PATH, 6, 1001.14, 495.523, -49.33023, 0, -1200),
(@PATH, 7, 997.059, 503.844, -49.32661, 0, -656),
(@PATH, 8, 993.688, 507.509, -49.32198, 0, 983),
(@PATH, 9, 993.688, 507.509, -49.32198, 1.32645, 33650),
(@PATH, 10, 991.337, 519.234, -49.33482, 0, -1197),
(@PATH, 11, 991.602, 533.674, -49.30743, 0, -963),
(@PATH, 12, 993.3165, 547.1342, -49.33482, 0, -963),
(@PATH, 13, 998.828, 562.877, -49.24633, 0, -1676),
(@PATH, 14, 1015.13, 563.564, -49.25161, 0, -1200),
(@PATH, 15, 1041.96, 552.512, -49.29991, 0, -675),
(@PATH, 16, 1045.91, 543.142, -49.30189, 0, -1238),
(@PATH, 17, 1043.43, 533.576, -49.32864, 0, -1200);

UPDATE `creature` SET `position_x`= 1049.35, `position_y`= 522.7233, `position_z`= -49.33483, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`, `auras`) VALUES
(@CGUID, @PATH, 1, '42459 78148 78150 84667');

SET @CGUID := 350335;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 752.601, 847.217, -70.39709, 0, 8),
(@PATH, 1, 799.517, 838.207, -59.51084, 0, -1200),
(@PATH, 2, 867.201, 821.547, -69.87858, 0, -1200),
(@PATH, 3, 916.328, 817.208, -69.0389, 0, -1386),
(@PATH, 4, 957.316, 826.596, -66.53861, 0, -1700),
(@PATH, 5, 992.552, 844.045, -69.89233, 0, -830),
(@PATH, 6, 1030.81, 850.587, -68.28864, 0, -1574),
(@PATH, 7, 1076.79, 851.069, -67.2158, 0, -1731),
(@PATH, 8, 1116.03, 868.571, -67.62514, 0, -1468),
(@PATH, 9, 1162.63, 855.618, -65.37663, 0, -1164),
(@PATH, 10, 1189.3, 837.102, -68.95133, 0, -1743),
(@PATH, 11, 1206.66, 795.865, -70.29496, 0, -1280),
(@PATH, 12, 1222.64, 751.21, -69.58278, 0, -1242),
(@PATH, 13, 1253.34, 722.722, -70.24152, 0, -1811),
(@PATH, 14, 1277.67, 699.747, -70.03351, 0, -891),
(@PATH, 15, 1314.08, 673.962, -70.32758, 0, -1408),
(@PATH, 16, 1338.75, 636.668, -66.03678, 0, -1349),
(@PATH, 17, 1366.82, 619.253, -68.49463, 0, -884),
(@PATH, 18, 1382.75, 603.637, -68.34253, 0, -1535),
(@PATH, 19, 1424.14, 582.748, -64.56645, 0, -493),
(@PATH, 20, 1467.66, 563.814, -62.49057, 0, -1444),
(@PATH, 21, 1513.74, 545.795, -56.52704, 0, -1419),
(@PATH, 22, 1560.756, 536.1387, -46.82766, 0, 122),
(@PATH, 23, 1513.74, 545.795, -56.52704, 0, -1419),
(@PATH, 24, 1467.66, 563.814, -62.49057, 0, -1444),
(@PATH, 25, 1424.14, 582.748, -64.56645, 0, -493),
(@PATH, 26, 1382.75, 603.637, -68.34253, 0, -1535),
(@PATH, 27, 1366.82, 619.253, -68.49463, 0, -884),
(@PATH, 28, 1338.75, 636.668, -66.03678, 0, -1349),
(@PATH, 29, 1314.08, 673.962, -70.32758, 0, -1408),
(@PATH, 30, 1277.67, 699.747, -70.03351, 0, -891),
(@PATH, 31, 1253.34, 722.722, -70.24152, 0, -1811),
(@PATH, 32, 1222.64, 751.21, -69.58278, 0, -1242),
(@PATH, 33, 1206.66, 795.865, -70.29496, 0, -1280),
(@PATH, 34, 1189.3, 837.102, -68.95133, 0, -1743),
(@PATH, 35, 1162.63, 855.618, -65.37663, 0, -1164),
(@PATH, 36, 1116.03, 868.571, -67.62514, 0, -1468),
(@PATH, 37, 1076.79, 851.069, -67.2158, 0, -1731),
(@PATH, 38, 1030.81, 850.587, -68.28864, 0, -1574),
(@PATH, 39, 992.552, 844.045, -69.89233, 0, -830),
(@PATH, 40, 957.316, 826.596, -66.53861, 0, -1700),
(@PATH, 41, 916.328, 817.208, -69.0389, 0, -1386),
(@PATH, 42, 867.201, 821.547, -69.87858, 0, -1200),
(@PATH, 43, 799.517, 838.207, -59.51084, 0, -1200);

UPDATE `creature` SET `position_x`= 752.601, `position_y`= 847.217, `position_z`= -70.39709, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`, `visibilityDistanceType`) VALUES
(@CGUID, @PATH, 1, 3);

SET @CGUID := 354375;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1353.972, 509.5729, -68.92733, 0, -1829),
(@PATH, 1, 1383.082, 521.0121, -68.77572, 0, -1170),
(@PATH, 2, 1408.774, 533.5486, -69.32683, 0, -982),
(@PATH, 3, 1432.782, 547.9316, -66.81731, 0, -1364),
(@PATH, 4, 1449.686, 570.9636, -64.44874, 0, -855),
(@PATH, 5, 1462.533, 586.7969, -61.19935, 0, -972),
(@PATH, 6, 1479.483, 611.4236, -60.51506, 0, -740),
(@PATH, 7, 1490.556, 629.6979, -58.48919, 0, 138),
(@PATH, 8, 1490.556, 629.6979, -58.48919, 2.356194, 54101),
(@PATH, 9, 1474.865, 610.1979, -60.95427, 0, -1639),
(@PATH, 10, 1455.356, 590.3611, -61.31092, 0, -810),
(@PATH, 11, 1437.602, 565.2743, -66.07082, 0, -1261),
(@PATH, 12, 1411.929, 542.6927, -69.19841, 0, -1790),
(@PATH, 13, 1378.212, 525.783, -69.10079, 0, -1404),
(@PATH, 14, 1350.161, 513.6996, -68.93343, 0, -1687),
(@PATH, 15, 1328.681, 507.0972, -70.05306, 0, 46),
(@PATH, 16, 1328.681, 507.0972, -70.05306, 1.850049, 32433);

UPDATE `creature` SET `position_x`= 1353.972, `position_y`= 509.5729, `position_z`= -68.92733, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`, `visibilityDistanceType`) VALUES
(@CGUID, @PATH, 1, 4);

DELETE FROM `spell_area` WHERE `spell` IN (84117, 84955, 83322);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(84117, 5395, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84117, 5291, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84117, 5335, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84117, 5303, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84955, 5395, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84955, 5291, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84955, 5335, 0, 0, 0, 0, 2, 0x3, 64, 11),
(84955, 5303, 0, 0, 0, 0, 2, 0x3, 64, 11),
(83322, 5395, 0, 0, 0, 0, 2, 0x3, 64, 11),
(83322, 5291, 0, 0, 0, 0, 2, 0x3, 64, 11),
(83322, 5335, 0, 0, 0, 0, 2, 0x3, 64, 11),
(83322, 5303, 0, 0, 0, 0, 2, 0x3, 64, 11);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (44258);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(44258, 1, 1, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= 3547420;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(3547420, 0, 1844.5295, -212.07292, -173.11815),
(3547420, 1, 1844.9305, -234.8802, -170.85762),
(3547420, 2, 1857.1892, -255.3993, -168.03598),
(3547420, 3, 1879.8298, -268.13022, -167.62912),
(3547420, 4, 1904.4497, -267.97397, -167.73308),
(3547420, 5, 1926.4305, -253.89757, -167.34975),
(3547420, 6, 1938.8993, -224.67361, -169.80014),
(3547420, 7, 1928.4896, -191.5382, -168.29854),
(3547420, 8, 1900.4601, -174.81944, -163.85335),
(3547420, 9, 1873.7205, -175.51042, -171.29675),
(3547420, 10, 1854.2396, -191.76736, -171.98355);

UPDATE `creature_addon` SET `cyclicSplinePathId`= 3547420, `waypointPathId`= 0, `bytes1`= 50331648 WHERE `guid`= 354742;
UPDATE `creature` SET `position_x`= 1844.5295, `position_y` = -212.07292, `position_z` = -173.11815, `MovementType`= 3 WHERE `guid`= 354742;
