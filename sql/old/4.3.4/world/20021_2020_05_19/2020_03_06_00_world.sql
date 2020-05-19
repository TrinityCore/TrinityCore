SET @CGUID := 395389;
SET @OGUID := 239511;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+799;

-- Hyjal Defenders
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `phaseMask`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1089.48, 301.932, 18.5056, 4.62512, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+1, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1093.54, 303.269, 18.5073, 5.37561, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
-- (@CGUID+2, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1129.15, 369.186, 16.6745, 6.17594, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+3, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1127.54, 400.194, 17.1954, 5.79449, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+4, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1200.25, 368.311, 16.1389, 0.244346, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+5, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1096.58, 367.764, 24.6001, 6.10865, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+6, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1084.13, 338.056, 25.734, 5.02655, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
-- (@CGUID+7, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1128.16, 373.306, 16.8165, 0.10472, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+8, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1156.76, 388.132, 16.8072, 5.1773, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+9, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1196.79, 362.599, 16.1766, 5.65487, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+10, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1046.9, 359.62, 39.2197, 0.20944, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+11, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1046.64, 378.134, 41.1028, 5.97897, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+12, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1095.07, 384.969, 24.2604, 1.13446, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+13, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1121.78, 377.078, 16.8165, 0.279253, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+14, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1162.4, 391.719, 16.4541, 6.12611, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+15, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1124.08, 411.109, 16.8211, 0.365929, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+16, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1129.21, 374.802, 16.8029, 0.960947, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+17, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1126.4, 351.285, 16.7562, 5.79449, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+18, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1133.52, 358.498, 16.757, 6.05629, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+19, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1098.31, 413.776, 18.1482, 5.93006, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+20, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1079.78, 302.023, 18.5599, 4.71239, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+21, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1122.73, 394.325, 16.8663, 5.6986, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+22, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1100.81, 310.507, 18.5056, 5.74213, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+23, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1145.66, 324.717, 16.6566, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+24, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1125.66, 418.672, 16.8185, 0.279253, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+25, 52500, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1145.21, 330.54, 16.8793, 0.174533, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595);

DELETE FROM `creature_template_addon` WHERE `entry`= 52500;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`) VALUES
(52500, 0, 1, 375);

-- Hyjal Marksman
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+26 AND @CGUID+40;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `phaseMask`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+26, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1056.11, 387.335, 43.2464, 5.21853, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+27, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1106.39, 392.451, 24.3324, 6.0912, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+28, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1045.69, 381.345, 41.1214, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+29, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1107.87, 342.7, 26.6209, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+30, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1077.31, 310.954, 20.095, 4.57433, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+31, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1043.82, 352.014, 40.9931, 0.453786, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+32, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1087.08, 401.764, 24.166, 0.15708, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+33, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1113.09, 396.161, 20.3708, 6.02925, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+34, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1110.37, 369.561, 20.6299, 0.211954, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+35, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1091.05, 311.964, 20.201, 5.14872, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+36, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1109.73, 363.42, 20.7458, 6.05629, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+37, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1115.81, 347.297, 22.1217, 6.0912, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+38, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1069.48, 409.049, 39.2919, 5.86431, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+39, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1078.54, 319.8, 23.1769, 4.90438, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+40, 52502, 861, 0, 0, 1, 0, 1, 169, 0, -1, 0, 0, 1096.08, 322.057, 22.2551, 5.0091, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595);

DELETE FROM `creature_template_addon` WHERE `entry`= 52502;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`) VALUES
(52502, 0, 2, 376);

-- Hyjal Druid
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+40 AND @CGUID+58;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `phaseMask`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+40, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1157.15, 392.266, 16.4541, 6.03884, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+41, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1194.4, 163.514, 60.262, 2.79504, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+42, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1181.74, 140.5, 63.6397, 0.820305, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+43, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1199.58, 141.179, 60.0417, 2.16421, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+44, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1179.96, 141.521, 63.6447, 0.567778, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+45, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1193.03, 364.83, 16.6227, 6.00357, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+46, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1019.04, 345.167, 41.0756, 0.750492, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+47, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1086.53, 313.285, 20.1108, 4.12128, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+48, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1054.49, 385.224, 43.1511, 5.23599, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+49, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1016.9, 365.049, 41.0756, 6.12611, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+50, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1026, 387.634, 41.1541, 5.48033, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+51, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1044.06, 377.668, 41.1214, 5.81195, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+52, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1108.95, 366.318, 20.6238, 5.98648, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+53, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1114.14, 407.759, 16.8274, 6.19592, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+54, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1142.07, 326.96, 16.419, 0.15708, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+55, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1023.3, 339.212, 42.7625, 1.06465, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+56, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1043.31, 356.217, 39.8482, 0.261799, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+57, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1015.33, 376.422, 41.0756, 0.471239, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595),
(@CGUID+58, 52501, 861, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0, 1043.36, 360.498, 39.4176, 0.15708, 120, 0, 0, 0, 0, 0, 0, 0, 0, '', 15595);

DELETE FROM `creature_template_addon` WHERE `entry`= 52501;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`) VALUES
(52501, 0, 1, 425);

-- Hyjal Enforcer
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+59 AND @CGUID+66;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+59, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1025.299, 346.4668, 41.07563, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), 
(@CGUID+60, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1028.601, 388.0451, 41.18068, 5.375614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+61, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1011.995, 367.9722, 41.09397, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+62, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1011.408, 373.4115, 41.33314, 6.10212, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+63, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1031.312, 340.7866, 41.07563, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+64, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1029.228, 344.4977, 41.07563, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+65, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1025.883, 383.7605, 41.07563, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595),
(@CGUID+66, 52703, 861, 0, 0, 1, 169, 0, 0, 0, 1019.217, 382.2726, 41.07563, 5.794493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595);

DELETE FROM `creature_template_addon` WHERE `entry`= 52703;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`) VALUES
(52703, 0, 1, 425);

-- Furnace Bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+67 AND @CGUID+210;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+67, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1076.231, 434.4809, 42.18635, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+68, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1090.455, 439.9045, 42.99031, 0.5061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+69, 54039, 861, 0, 0, 1,  0, 606, 0, 0, 1080.71, 427.8455, 41.95254, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+70, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1082.925, 442.2188, 42.48731, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+71, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1061.741, 446.5243, 43.10235, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+72, 54036, 861, 0, 0, 1,  0, 606, 0, 0, 1065.533, 441.9392, 42.556, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+73, 54040, 861, 0, 0, 1,  0, 606, 0, 0, 1074.563, 445.9879, 42.41491, 4.537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+74, 54036, 861, 0, 0, 1,  0, 606, 0, 0, 1069.363, 440.9167, 42.85727, 1.815142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+75, 54040, 861, 0, 0, 1,  0, 606, 0, 0, 1081.25, 431.2274, 42.186, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+76, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1078.955, 439.224, 42.16354, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+77, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1080.111, 433.75, 42.27803, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+78, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1067.951, 437.2292, 42.42865, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+79, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1066.318, 447.0764, 43.00167, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+80, 53213, 861, 0, 0, 1,  0, 606, 0, 0, 1076.573, 430.1858, 42.14859, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+81, 54037, 861, 0, 0, 1,  0, 606, 0, 0, 1086.422, 432.2049, 41.98438, 0.1919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+82, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1083.811, 465.0972, 46.4921, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+83, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1078.483, 467.1962, 47.55935, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+84, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1074.177, 453.3924, 42.71467, 5.742133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+85, 54040, 861, 0, 0, 1,  0, 606, 0, 0, 1120.526, 476.8507, 56.90104, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+86, 54037, 861, 0, 0, 1,  0, 606, 0, 0, 1076.679, 458.2639, 44.01144, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+87, 54039, 861, 0, 0, 1,  0, 606, 0, 0, 1091.597, 476.0729, 52.22635, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+88, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1095.28, 466, 48.81746, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+89, 54039, 861, 0, 0, 1,  0, 606, 0, 0, 1128.939, 469.257, 56.59722, 5.131268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+90, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1081.328, 470.6111, 49.32977, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+91, 54039, 861, 0, 0, 1,  0, 606, 0, 0, 1091.896, 464.8594, 47.64025, 1.780236, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+92, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1113.082, 456.875, 50.8469, 5.026548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+93, 53212, 861, 0, 0, 1,  0, 606, 0, 0, 1067.642, 452.8507, 43.77317, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+94, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1086.736, 468.2969, 48.10769, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+95, 54040, 861, 0, 0, 1,  0, 606, 0, 0, 1097.281, 455.8941, 46.83507, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+96, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1110.316, 454.8785, 49.90754, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+97, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1061.891, 450.6875, 43.94786, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+98, 52948, 861, 0, 0, 1,  0, 606, 0, 0, 1111.458, 469.3281, 53.71875, 3.281219, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+99, 54038, 861, 0, 0, 1,  0, 606, 0, 0, 1103.788, 458.658, 49.07639, 2.583087, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+100, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1113.524, 463.4774, 52.32515, 5.323254, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+101, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1094.563, 460.9375, 47.6684, 3.944444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+102, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1091.849, 450.6597, 44.4342, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+103, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1107.149, 462.1806, 50.53771, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+104, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1090.37, 457.7344, 45.85642, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+105, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1093.042, 481.5972, 53.54049, 1.692969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+106, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1110.806, 460.8229, 51.28594, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+107, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1119.457, 467.4618, 54.71099, 3.316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+108, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1087.345, 455.7639, 44.63862, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+109, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1068.441, 448.4271, 42.90757, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+110, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1068.172, 460.7726, 45.76734, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+111, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1080.932, 446.5035, 42.09896, 1.780236, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+112, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1087.125, 463.467, 46.41113, 1.919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+113, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1082.234, 454.2535, 43.12772, 1.22173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+114, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1123.276, 471.908, 56.39685, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+115, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1109.333, 479.8576, 57.0243, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+116, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1098.738, 480.3559, 54.64008, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+117, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1099.408, 485.5174, 56.29221, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+118, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1090.576, 470.2274, 48.90746, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+119, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1114.196, 467.5521, 53.78986, 5.393067, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+120, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1105.417, 455.9653, 49.26563, 5.742133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+121, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1087.352, 448.184, 43.08978, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+122, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1111.004, 474.8333, 55.74305, 3.892084, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+123, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1082.762, 462.0313, 45.62255, 5.166174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+124, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1122.556, 484.2049, 58.68445, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+125, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1113.41, 485.526, 57.35357, 2.80998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+126, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1120.543, 491.7153, 59.2228, 4.258604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+127, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1146.038, 479.7552, 58.65248, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+128, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1127.589, 483.9219, 59.44618, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+129, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1137.285, 479.5781, 59.27626, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+130, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1126.885, 488.3958, 59.4453, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+131, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1108.747, 497.7222, 59.60855, 0.8028514, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+132, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1112.953, 491.0746, 58.08902, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+133, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1107.792, 484.6215, 56.516, 3.455752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+134, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1105.224, 497.0521, 58.77833, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+135, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1139.345, 483.257, 59.36685, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+136, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1117.67, 480.3472, 57.14945, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+137, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1098.205, 490.0625, 56.63777, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+138, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1122.448, 486.7552, 59.33854, 3.839724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+139, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1105.411, 487.9254, 57.29563, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+140, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1135.017, 485.9236, 59.48264, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+141, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1130.368, 478.6441, 59.12674, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+142, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1148.708, 492.7882, 59.25174, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+143, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1141.295, 495.5816, 59.52778, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+144, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1125.665, 502.0174, 60.33223, 3.700098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+145, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1132.333, 492.4705, 59.59201, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+146, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1135.139, 505.0121, 59.1889, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+147, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1127.023, 494.7813, 59.65467, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+148, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1127.158, 510.6945, 59.26778, 1.692969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+149, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1106.967, 508.4792, 59.90445, 2.268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+150, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1137.5, 495.8611, 59.55298, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+151, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1111.214, 518.6667, 62.47556, 1.727876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+152, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1133.047, 500.2552, 59.52871, 4.520403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+153, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1156.347, 482.2483, 59.93576, 6.056293, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+154, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1117.854, 514.2604, 60.61055, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+155, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1109.337, 515.9479, 61.79886, 4.258604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+156, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1116.163, 500.3576, 58.20738, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+157, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1113.665, 506.1858, 62.00477, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+158, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1159.92, 486.3455, 60.33424, 4.886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+159, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1151.63, 478.6337, 58.20787, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+160, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1152.477, 484.6736, 59.34757, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+161, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1147.17, 486.151, 59.25694, 3.700098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+162, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1120.774, 507.7014, 60.7093, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+163, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1122.655, 515.0781, 59.72903, 6.126106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+164, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1124.189, 527.6823, 60.25385, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+165, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1145.665, 509.382, 57.39351, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+166, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1136.479, 517.5504, 58.59042, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+167, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1139.757, 517.5156, 57.59806, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+168, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1105.629, 522.3004, 62.23191, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+169, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1110.957, 532.8108, 62.57749, 1.972222, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+170, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1156.052, 490.2222, 59.55208, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+171, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1168.589, 490.6945, 59.25868, 2.617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+172, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1168.656, 485.25, 59.25868, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+173, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1166.335, 493.0313, 59.21899, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+174, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1183.483, 473.0625, 59.25922, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+175, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1187.469, 469.6302, 59.28452, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+176, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1119.53, 527.3715, 61.19855, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+177, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1175.92, 477.5556, 59.38715, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+178, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1178.967, 484.7865, 59.40799, 5.8294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+179, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1121.347, 522.8455, 60.20536, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+180, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1173.191, 476.0087, 59.63303, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+181, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1171.91, 487.8021, 59.33311, 4.886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+182, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1127.788, 515.0504, 59.16091, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+183, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1147.557, 504.7778, 58.25801, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire; 86877 - Generic Quest Invisibility 14)
(@CGUID+184, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1141.983, 509.3264, 58.61356, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+185, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1183.236, 477.0504, 59.27985, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+186, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1190.208, 469.4392, 59.26566, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+187, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1115.486, 523.5104, 61.25924, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+188, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1191.372, 488.1806, 59.16243, 3.333579, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+189, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1143.366, 516.7309, 56.90799, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+190, 53212, 861, 0, 0, 1, 0, 606, 0, 0, 1195.031, 483.4722, 59.19097, 5.759586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+191, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1198.707, 469.3195, 59.25936, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+192, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1164.688, 500.6441, 59.82986, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+193, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1197.538, 474.4496, 59.25817, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+194, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1178.005, 491.5885, 59.28874, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+195, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1130.005, 525.1424, 58.88179, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+196, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1182.595, 491.0121, 59.19444, 3.333579, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+197, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1188.401, 476.0521, 59.26215, 4.310963, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+198, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1195.135, 467.1649, 59.26167, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+199, 54036, 861, 0, 0, 1, 0, 606, 0, 0, 1191.681, 477.6076, 59.2506, 3.333579, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+200, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1190.455, 483.3889, 59.20564, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+201, 54038, 861, 0, 0, 1, 0, 606, 0, 0, 1199.122, 462.9879, 59.26445, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+202, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1173.533, 497.2951, 59.21875, 2.146755, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+203, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1197.849, 491.1597, 59.16284, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+204, 54040, 861, 0, 0, 1, 0, 606, 0, 0, 1203.283, 486.6354, 59.19097, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire B, 1.6 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100608 - Furnace Fire B, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+205, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1205.139, 480.0712, 59.2507, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+206, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1214.47, 480.7656, 58.35161, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+207, 54039, 861, 0, 0, 1, 0, 606, 0, 0, 1207.717, 490.6476, 58.99305, 3.438299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+208, 54037, 861, 0, 0, 1, 0, 606, 0, 0, 1212.559, 484.7917, 58.55729, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire C, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100610 - Furnace Fire C, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+209, 53213, 861, 0, 0, 1, 0, 606, 0, 0, 1219.009, 484.9392, 58.45329, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Furnace Bunny, Fire A, 0.8 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)
(@CGUID+210, 52948, 861, 0, 0, 1, 0, 606, 0, 0, 1207.549, 483.1962, 59.22916, 0.4712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Furnace Bunny, Fire A, 1.0 scale (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97921 - Furnace Fire A, 96824 - Furnace Fire, 86877 - Generic Quest Invisibility 14)

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry` IN (53213, 54037, 54039, 52948, 54040, 54038, 54036, 53212, 52531);
DELETE FROM `creature_template_addon` WHERE `entry` IN (53213, 54037, 54039, 52948, 54040, 54038, 54036, 53212);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(53213, 0, 0, '97921 96824 86877'),
(54037, 0, 0, '100610 96824 86877'),
(54039, 0, 0, '100610 96824 86877'),
(52948, 0, 0, '97921 96824 86877'),
(54040, 0, 0, '100608 96824 86877'),
(54038, 0, 0, '100608 96824 86877'),
(54036, 0, 0, '100608 96824 86877'),
(53212, 0, 0, '97921 96824 86877');

-- Unique creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+211 AND @CGUID+230;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+211, 52476, 861, 0, 0, 1, 169, 0, 0, 0, 1008.733, 327.4601, 41.55301, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Keeper Krothis (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+212, 44775, 861, 0, 0, 1, 0, 606, 0, 0, 1027.809, 333.3871, 53.24817, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Generic Bunny - PRK (Large AOI) (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+213, 52825, 861, 0, 0, 1, 169, 0, 0, 0, 980.0677, 303.0208, 45.78178, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Theresa Barkskin (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+214, 52489, 861, 0, 0, 1, 169, 0, 0, 0, 1009.43, 330.7587, 41.47743, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Avrilla (Area: Malfurion's Breach - Difficulty: 0) (Auras: 87872 - Generic Quest Invisibility 22)
(@CGUID+215, 52467, 861, 0, 0, 1, 169, 0, 0, 0, 1017.439, 356.1042, 41.07563, 0.3316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rayne Feathersong (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+216, 52822, 861, 0, 0, 1, 169, 0, 0, 0, 979.8785, 375.066, 38.06409, 3.455752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Zen'Vorka (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84886 - Generic Quest Invisibility 9)
(@CGUID+217, 52135, 861, 0, 0, 1, 169, 0, 0, 0, 976.8629, 373.974, 38.10543, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Malfurion Stormrage (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84886 - Generic Quest Invisibility 9)
(@CGUID+218, 53080, 861, 0, 0, 1, 169, 0, 0, 0, 1018.276, 390.474, 42.24274, 5.67232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Irontree (Area: Malfurion's Breach - Difficulty: 0) (Auras: 84886 - Generic Quest Invisibility 9)
(@CGUID+219, 52824, 861, 0, 0, 1, 169, 0, 0, 0, 1020.842, 390.9931, 42.21557, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- General Taldris Moonfall (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+220, 32520, 861, 0, 0, 1, 0, 606, 0, 0, 1184.007, 370.9826, 28.12957, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totally Generic Bunny (All Phase) (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+221, 53261, 861, 0, 0, 1, 0, 606, 0, 0, 1353.642, 648.3455, 34.93684, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fall Recovery Primary Controller (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+222, 44775, 861, 0, 0, 1, 169, 0, 0, 0, 1175.681, 525.2621, 54.10263, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Generic Bunny - PRK (Large AOI) (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+223, 53911, 861, 0, 0, 1, 0, 606, 0, 0, 1302.45, 254.7795, 24.36014, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shadow Warden (Area: The Widow's Clutch - Difficulty: 0) (Auras: 89304 - Generic Quest Invisibility 29)
(@CGUID+224, 53911, 861, 0, 0, 1, 0, 606, 0, 0, 1311.995, 256.7847, 23.99809, 4.433136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shadow Warden (Area: The Widow's Clutch - Difficulty: 0) (Auras: 89304 - Generic Quest Invisibility 29)
(@CGUID+225, 44403, 861, 0, 0, 1, 0, 606, 0, 0, 1174.094, 134.7778, 101.9068, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Generic Controller Bunny, Gigantic (CSA) (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+226, 52444, 861, 0, 0, 1, 169, 0, 0, 0, 1228.293, 427.4514, -52.88596, 4.485496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thisalee Crow (Area: Magma Springs - Difficulty: 0)
(@CGUID+227, 53269, 861, 0, 0, 1, 0, 606, 0, 0, 1294.293, 538.9809, 19.72514, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fall Recovery Secondary Controller (Area: Magma Springs - Difficulty: 0)
(@CGUID+228, 53866, 861, 0, 0, 1, 169, 0, 0, 0, 1496.881, 331.5285, 62.87962, 1.766324, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Torrent Channel Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+229, 53074, 861, 0, 0, 1, 169, 0, 0, 0, 1482.957, 365.2899, 63.02688, 5.846853, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Witherbranch (Area: Magma Springs - Difficulty: 0) (Auras: )
(@CGUID+230, 53771, 861, 0, 0, 1, 169, 0, 0, 0, 1546.898, 334.3351, 62.11619, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Ancient Smoldering Behemoth (Area: Magma Springs - Difficulty: 0) (Auras: 99997 - Smoldering Aura)


DELETE FROM `creature_template_addon` WHERE `entry` IN (52135, 52822, 53080, 52489, 52825, 52531, 54339, 53911, 53152);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52135, 0, 1, 0, '84886'),
(52822, 0, 1, 0, '84886'),
(53080, 0, 1, 0, '84886'),
(52489, 0, 1, 0, '87872'),
(52531, 0, 1, 0, '97124'),
(54339, 0, 1, 0, '42648'),
(53152, 3, 1, 0, '96007'),
(52825, 1, 1, 0, ''),
(53911, 0, 1, 333, '89304');

-- Wounded Hyjal Defenders
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+231 AND @CGUID+267;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+231, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1076.342, 372.0972, 29.77001, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+232, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1077.436, 308.026, 19.29234, 1.07466, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+233, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1118.411, 359.5781, 18.36292, 5.77704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+234, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1092.656, 321.2309, 22.14217, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+235, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1118.174, 388.2656, 16.82421, 0.4712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+236, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1113.149, 314.7292, 16.56043, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+237, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1122.698, 330.5174, 16.7562, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+238, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1128.778, 342.7795, 16.7562, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+239, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1101.523, 284.9236, 16.84482, 0.3316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+240, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1129.504, 422.4653, 16.95681, 0.2792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+241, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1139.694, 402.0799, 17.00271, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+242, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1066.974, 301.6962, 17.54938, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+243, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1096.762, 373.9132, 24.37115, 5.8294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+244, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1097.11, 305.4873, 18.387, 1.873099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+245, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1103.469, 394.2535, 24.24515, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+246, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1151.549, 343.5017, 17.13454, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+247, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1147.337, 416.9219, 16.84356, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+248, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1160.455, 394.224, 16.45613, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+249, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1169.505, 408.9184, 16.45415, 5.340707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+250, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1171.561, 382.5764, 16.45414, 4.328416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+251, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1177.79, 360.033, 16.48182, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+252, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1187.286, 388.0573, 17.06078, 0.8552113, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+253, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1182.634, 310.6424, 16.45414, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+254, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1113.059, 272.757, 16.84489, 6.091199, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+255, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1221.418, 375.1493, 16.16428, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+256, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1181.958, 333.1163, 16.55524, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+257, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1113.059, 272.757, 16.84489, 6.091199, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+258, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1107.967, 416.5729, 16.90097, 5.794493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+259, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1136.269, 297.2865, 16.68684, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+260, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1155.571, 311.7188, 16.45414, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+261, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1094.887, 335.8594, 24.25784, 4.485496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+262, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1118.174, 388.2656, 16.82421, 0.4712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
-- (@CGUID+263, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1118.411, 359.5781, 18.36292, 5.77704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+264, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1175.219, 422.5799, 16.0786, 0.3316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+265, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1160.455, 394.224, 16.45613, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)
(@CGUID+266, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1112.102, 257.4132, 16.75098, 0.4537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned, 97868 - Wounded Defender Healing Tracker Proc)
(@CGUID+267, 52834, 861, 0, 0, 1, 169, 0, 0, 0, 1154.941, 292.4965, 16.45927, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Wounded Hyjal Defender (Area: Ashen Fields - Difficulty: 0) (Auras: 97664 - Burned)

DELETE FROM `creature_template_addon` WHERE `entry`= 52834;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52834, 0, 0, 7, 1, 0, '97664 97868'); -- 52834 (Wounded Hyjal Defender) - Burned, Wounded Defender Healing Tracker Proc

-- Fire Attacker Portals
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+268 AND @CGUID+277;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+268, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1081.134, 276.2014, 16.80696, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+269, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1141.222, 307.4757, 16.45033, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+270, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1126.03, 262.0295, 16.84405, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+271, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1211.403, 337.2274, 16.66133, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+272, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1187.948, 319.6094, 16.45414, 2.495821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+273, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1175.085, 289.0781, 16.45414, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+274, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1157.981, 431.8785, 16.81647, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+275, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1167.734, 371.5521, 16.45414, 3.263766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+276, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1192.656, 426.5556, 16.09549, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)
(@CGUID+277, 52531, 861, 5733, 5738, 1, 169, 0, 0, 0, 1243.337, 371.5521, 16.04734, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Fire Attacker Portal (Area: Malfurion's Breach - Difficulty: 0) (Auras: 97124 - Fire Attacker Portal)

DELETE FROM `creature_template_addon` WHERE `entry`= 52531;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52531, 0, 0, 0, 1, 0, '97124'); -- Fire Attacker Portal - 97124 - Fire Attacker Portal

-- Molten Behemoths
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+278 AND @CGUID+281;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+278, 52552, 861, 0, 0, 1, 169, 0, 0, 0, 1345.871, 295.1208, 23.20313, 4.982472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Behemoth (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+279, 52552, 861, 0, 0, 1, 169, 0, 0, 0, 1303.054, 396.2969, 22.19297, 0.9273899, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Behemoth (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+280, 52552, 861, 0, 0, 1, 169, 0, 0, 0, 1373.016, 412.066, 22.64066, 2.532379, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Molten Behemoth (Area: Magma Springs - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+281, 52552, 861, 0, 0, 1, 169, 0, 0, 0, 1244.9, 314.7551, 22.7172, 1.228935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Molten Behemoth (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)

UPDATE `creature_template` SET `speed_walk`= 0.714 WHERE `entry`= 52552;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 52552;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(52552, 1, 1, 0, 0);

SET @NPC := @CGUID+279;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1287.009, `position_y`= 343.1996, `position_z`= 22.46727 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1287.009, 343.1996, 22.46727, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1291.063, 355.6389, 22.35228, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1287.576, 367.5781, 22.48815, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1292.188, 381.8056, 22.11315, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1303.054, 396.2969, 22.19297, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1314.986, 403.0504, 22.76329, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1327.201, 398.941, 22.50755, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1314.986, 403.0504, 22.76329, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1303.054, 396.2969, 22.19297, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1292.188, 381.8056, 22.11315, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1287.576, 367.5781, 22.48815, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1291.063, 355.6389, 22.35228, 0, 0, 0, 0, 100, 0);

SET @NPC := @CGUID+280;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1366.715, `position_y`= 414.4948, `position_z`= 23.12293 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1366.715, 414.4948, 23.12293, 0, 310, 0, 0, 100, 0),
(@PATH, 2, 1350.259, 427.9445, 22.69363, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1337.858, 437.5851, 21.70608, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1320.139, 440.9167, 22.54078, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1308.243, 433.2049, 22.51329, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1299.757, 419.3837, 22.82616, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1308.243, 433.2049, 22.51329, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1320.139, 440.9167, 22.54078, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1337.858, 437.5851, 21.70608, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1350.259, 427.9445, 22.69363, 0, 1326, 0, 0, 100, 0);

SET @NPC := @CGUID+281;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1282.637, `position_y`= 290.6771, `position_z`= 22.55657 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1282.637, 290.6771, 22.55657, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1268.049, 289.5399, 22.55657, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1251.295, 297.7465, 23.30657, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1243.524, 310.8889, 22.60312, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1249.288, 327.0885, 22.64316, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1266.689, 329.8542, 23.11852, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1278.547, 329.5556, 22.76488, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1266.689, 329.8542, 23.11852, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1249.288, 327.0885, 22.64316, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1243.524, 310.8889, 22.60312, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1251.295, 297.7465, 23.30657, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1268.049, 289.5399, 22.55657, 0, 0, 0, 0, 100, 0);

-- Charhounds
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+282 AND @CGUID+317;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+282, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1189.357, 334.1671, -54.41698, 2.370203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+283, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1203.75, 273.0417, 22.74296, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+284, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1202.064, 264.5347, 22.74358, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+285, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1258.772, 305.0995, -59.25844, 0.06000056, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+286, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1257.819, 466.1389, 22.79657, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+287, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1248.254, 467.0521, 22.48565, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+288, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1281.958, 447.8854, -65.39896, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+289, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1279.899, 441.2413, -64.82159, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+291, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1281.201, 445.151, -65.19241, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+292, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1281.618, 437.2396, -64.31211, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Ashen Fields - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+293, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1345.13, 443.3816, -75.04237, 3.510773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+294, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1299.832, 450.507, -65.31692, 4.24115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+295, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1313.042, 423.592, -66.47401, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+296, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1311.198, 420.4496, -66.37706, 1.745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+297, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1303.507, 450.8108, -65.56994, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+298, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1306.979, 449.0677, -65.66402, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+299, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1354.595, 453.6563, -75.09992, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+300, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1352.738, 452.0781, -74.77138, 5.323254, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+301, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1363.632, 456.6528, -75.3287, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+302, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1367.688, 455.5347, -75.44988, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+303, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1373.191, 455.0434, -75.20802, 5.201081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+304, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1386.58, 470.9688, 22.72085, 4.939282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+305, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1386.497, 459.0851, 22.36938, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+306, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1377.804, 436.9774, -75.34423, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+307, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1397.219, 455.2379, 27.03736, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+308, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1377.2, 432.191, -75.45647, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 96007 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+309, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1362.609, 326.5182, -90.66522, 4.728752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+310, 53152, 861, 0, 0, 1, 169, 0, 0, 0, 1276.564, 291.6537, -60.67185, 3.916294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Charhound (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+311, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1468.76, 257.2639, 66.80433, 4.799655, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+312, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1508.962, 424.6354, 64.22333, 3.490659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+313, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1493.814, 407.316, 63.00013, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+314, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1505.271, 413.1927, 63.05653, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+315, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1521.238, 404.4306, 63.13229, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Ragnaros' Reach - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+316, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1501.047, 255.7031, 63.58174, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)
(@CGUID+317, 54339, 861, 0, 0, 1, 169, 0, 0, 0, 1518.582, 263.7639, 63.3829, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Ancient Charhound (Area: Magma Springs - Difficulty: 0) (Auras: 42648 - Sleeping Sleep)

UPDATE `creature_template` SET `speed_walk`= 0.714 WHERE `entry`= 54339;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 54339;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(54339, 1, 0, 0, 0);

-- Emberspit Scorpions
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+318 AND @CGUID+341;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+318, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1162.104, 343.6962, 15.96599, 2.110546, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+319, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1146.564, 282.4635, 16.76283, 4.288733, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+320, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1191.661, 422.0779, 16.039, 2.012725, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+321, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1211.879, 368.4263, 16.06498, 1.642275, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+322, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1228.798, 437.633, 22.82865, 5.528505, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+323, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1254.988, 337.8632, 22.9148, 0.7177285, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+324, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1213.293, 279.2897, 23.21468, 3.88138, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+325, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1276.684, 375.8025, 22.48815, 2.852547, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+326, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1261.25, 449.8093, 22.84545, 6.244105, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+327, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1285.159, 331.1065, 22.87389, 5.253618, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+328, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1254.234, 295.8524, 23.16988, 3.829485, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+329, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1241.457, 408.8911, 23.05866, 2.501021, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+330, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1233.911, 499.613, 59.25913, 2.536382, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+331, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1293.246, 417.1491, 22.70116, 4.886279, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+332, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1319.86, 440.3935, 22.49455, 3.942883, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+333, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1304.796, 436.692, 22.6118, 0.5169653, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+334, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1330.706, 456.8116, 22.86786, 3.666875, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+335, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1373.723, 430.907, 22.56617, 4.584233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+336, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1379.982, 381.3627, 23.00622, 1.448439, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+337, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1399.815, 366.8298, 25.35803, 0.3341883, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+338, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1332.591, 310.2502, 22.84645, 1.608107, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+339, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1377.449, 321.5759, 23.99363, 2.030077, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+340, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1340.781, 271.5968, 22.54432, 4.369473, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+341, 53240, 861, 0, 0, 1, 169, 0, 0, 0, 1274.415, 271.4523, 21.92388, 5.800279, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638); -- Emberspit Scorpion (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)

UPDATE `creature_template` SET `speed_walk`= 0.714 WHERE `entry`= 53240;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 53240;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53240, 1, 0, 0, 0);

-- Alysrazor
DELETE FROM `creature` WHERE `guid`= @CGUID+342;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+342, 54097, 861, 0, 0, 1, 169, 0, 0, 0, 1270.565, 177.7076, 234.948, 2.902698, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Alysrazor (Area: Malfurion's Breach - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 54097;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(54097, 0, 0, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry`= 54097;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(54097, 0, 0, 50331648, 1, 0, ''); 

UPDATE `creature_template` SET `speed_run`= 2 WHERE `entry`= 54097;

-- Fire Hawks
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+343 AND @CGUID+355;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+343, 53245, 861, 0, 0, 1, 169, 0, 0, 0, 1317.781, 614.2501, 132.4035, 5.485844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Magma Springs - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+344, 53249, 861, 0, 0, 1, 169, 0, 0, 0, 1349.537, 615.1747, 181.4017, 2.627448, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk Matriarch (Area: Magma Springs - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+345, 53245, 861, 0, 0, 1, 169, 0, 0, 0, 1456.769, 580.397, 109.2777, 3.904864, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Magma Springs - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+346, 53245, 861, 0, 0, 1, 169, 0, 0, 0, 1315.887, 584.1399, 119.3712, 2.576464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: The Furnace - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+347, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1325.412, 599.9398, 101.482, 4.606694, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: The Furnace - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+348, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1292.948, 642.493, 78.48246, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)
(@CGUID+349, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1400.835, 622.7285, 116.157, 3.648655, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+350, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1293.448, 685.3264, 90.05167, 3.420845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)
(@CGUID+351, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1382.948, 691.5851, 116.8967, 6.021386, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)
(@CGUID+352, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1441.172, 684.7646, 108.7288, 1.42379, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)
(@CGUID+353, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1471.215, 687.2153, 93.90851, 3.839724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)
(@CGUID+354, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1424.841, 582.0341, 94.43237, 1.309251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic) (possible waypoints or random movement)
(@CGUID+355, 52660, 861, 0, 0, 1, 169, 0, 0, 0, 1462.311, 566.4774, 79.15678, 2.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Fire Hawk (Area: Fireplume Peak - Difficulty: 0) (Auras: 100712 - Fire Hawk Smoke Cosmetic)

DELETE FROM `creature_template_addon` WHERE `entry` IN (53245, 53249, 52660);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(53245, 0, 0, 50331648, 1, 0, '100712'), 
(53249, 0, 0, 50331648, 1, 0, '100712'), 
(52660, 0, 0, 0, 1, 0, '100712');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (53245, 53249, 52660);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53245, 1, 0, 1, 0),
(53249, 1, 0, 1, 0),
(52660, 1, 0, 0, 0);

SET @NPC := @CGUID+349;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1416.245, `position_y`= 635.1805, `position_z`= 116.5779 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1416.245, 635.1805, 116.5779, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1407.925, 626.658, 116.4213, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1394.983, 619.4774, 116.11, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1383.859, 609.967, 116.11, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1394.983, 619.4774, 116.11, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1407.925, 626.658, 116.4213, 0, 0, 0, 0, 100, 0);

SET @NPC := @CGUID+352;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1438.629, `position_y`= 698.3264, `position_z`= 107.9638 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1438.629, 698.3264, 107.9638, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1442.115, 691.1511, 108.0368, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1440.345, 679.1805, 109.2868, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1442.91, 670.9948, 109.7868, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1446.125, 663.3073, 109.9396, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1442.91, 670.9948, 109.7868, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1440.345, 679.1805, 109.2868, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1442.115, 691.1511, 108.0368, 0, 0, 0, 0, 100, 0);

SET @NPC := @CGUID+347;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1340.102, `position_y`= 575.0903, `position_z`= 97.77375 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1340.102, 575.0903, 97.77375, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1328.064, 581.1111, 99.342, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1324.385, 590.2674, 100.6908, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1326.179, 607.168, 102.0881, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1324.385, 590.2674, 100.6908, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1328.064, 581.1111, 99.342, 0, 0, 0, 0, 100, 0);

SET @NPC := @CGUID+354;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 1436.991, `position_y`= 599.25, `position_z`= 94.94402 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 1436.991, 599.25, 94.94402, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1426.786, 589.2952, 95.03023, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1424.009, 578.9236, 93.97188, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1422.203, 567.8837, 92.21565, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1415.733, 562.9305, 90.87311, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1422.203, 567.8837, 92.21565, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1424.009, 578.9236, 93.97188, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1426.786, 589.2952, 95.03023, 0, 0, 0, 0, 100, 0);

-- Obsidium Punishers
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+356 AND @CGUID+375;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+356, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1298.227, 573.1548, 78.84943, 5.217115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: The Furnace - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+357, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1364.226, 553.7501, 80.18021, 2.461361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: The Furnace - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+358, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1292.708, 620.8327, 78.96117, 0.6726058, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: The Furnace - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+359, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1384.515, 585.3746, 103.621, 5.040599, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+360, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1376.196, 609.1771, 116.2848, 5.748292, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+361, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1418.407, 595.9277, 95.03023, 3.703545, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+362, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1338.382, 716.5446, 90.91, 0.5678048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0)
(@CGUID+363, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1360.126, 722.6771, 90.8243, 1.071831, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0)
(@CGUID+364, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1357.1, 744.1531, 79.2944, 3.667278, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0)
(@CGUID+365, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1296.482, 728.302, 78.96789, 2.630321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+366, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1404.161, 725.6265, 99.19599, 3.563289, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+367, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1443.459, 741.0803, 78.7735, 2.852559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+368, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1425.582, 739.7334, 79.84058, 3.211995, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+369, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1445.775, 638.498, 104.3824, 3.999628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (Auras: 98589 - Rage)
(@CGUID+370, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1446.115, 620.6222, 104.1834, 5.455062, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0)
(@CGUID+371, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1491.25, 712.4604, 79.18922, 3.176788, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+372, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1486.221, 639.3647, 87.51781, 5.199444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+373, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1506.876, 699.1264, 79.74502, 2.650429, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+374, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1484.153, 596.0414, 79.36323, 4.962311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+375, 52107, 861, 0, 0, 1, 169, 0, 0, 0, 1441.472, 547.1444, 79.31902, 4.898247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Obsidium Punisher (Area: Fireplume Peak - Difficulty: 0) (possible waypoints or random movement)

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 8 WHERE `guid` BETWEEN @CGUID+356 AND @CGUID+375;

-- Thermal Pocket Bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+376 AND @CGUID+393;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+376, 53353, 861, 5733, 5745, 1, 0, 606, 0, 0, 1165.866, 536.4688, -48.24665, 4.939282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: The Furnace - Difficulty: 0) (Auras: 98835 - Thermal Vent Pulse)
(@CGUID+377, 53228, 861, 5733, 5745, 1, 0, 606, 0, 0, 1216.97, 469.875, -62.89493, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: The Furnace - Difficulty: 0) (Auras: 98579 - Thermal Vent Pulse)
(@CGUID+378, 53230, 861, 5733, 5745, 1, 0, 606, 0, 0, 1204.91, 363.2014, -51.2598, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: The Furnace - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+379, 53230, 861, 5733, 5739, 1, 0, 606, 0, 0, 1205.892, 339.8958, -35.58958, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Ashen Fields - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+380, 53230, 861, 5733, 5739, 1, 0, 606, 0, 0, 1209.148, 311.3142, -37.64207, 3.647738, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Ashen Fields - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+381, 52985, 861, 5733, 5742, 1, 0, 606, 0, 0, 1170.545, 138.1302, 4.378791, 4.572762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Forlorn Spire - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+382, 52985, 861, 5733, 5742, 1, 0, 606, 0, 0, 1219.347, 114, 6.298612, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Forlorn Spire - Difficulty: 0) (Auras: 97968 - Thermal Vent Pulse)
(@CGUID+383, 53230, 861, 5733, 5740, 1, 0, 606, 0, 0, 1314.273, 341.0087, -53.83078, 6.021386, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+384, 53228, 861, 5733, 5740, 1, 0, 606, 0, 0, 1321.976, 387.7778, -69.99695, 1.727876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98579 - Thermal Vent Pulse)
(@CGUID+385, 53230, 861, 5733, 5740, 1, 0, 606, 0, 0, 1326.707, 367.3507, -64.25178, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+386, 53228, 861, 5733, 5740, 1, 0, 606, 0, 0, 1276.837, 351.0972, -61.4355, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98579 - Thermal Vent Pulse)
(@CGUID+387, 53228, 861, 5733, 5740, 1, 0, 606, 0, 0, 1266.495, 356.3958, -53.19359, 5.916666, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98579 - Thermal Vent Pulse)
(@CGUID+388, 53228, 861, 5733, 5740, 1, 0, 606, 0, 0, 1262.674, 366.3212, -45.74084, 4.328416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98579 - Thermal Vent Pulse)
(@CGUID+389, 52162, 861, 5733, 5740, 1, 0, 606, 0, 0, 1380.306, 520.8629, 80.77985, 1.396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 97963 - Thermal Vent Pulse)
(@CGUID+390, 54515, 861, 5733, 5740, 1, 0, 606, 0, 0, 1326.09, 508.2517, 69.21304, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 101851 - Thermal Vent Pulse)
(@CGUID+391, 54515, 861, 5733, 5740, 1, 0, 606, 0, 0, 1276.035, 544.6458, 75.05025, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 101851 - Thermal Vent Pulse)
(@CGUID+392, 53230, 861, 5733, 5740, 1, 0, 606, 0, 0, 1255.608, 379.8958, -38.6323, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Thermal Pocket Bunny (Area: Magma Springs - Difficulty: 0) (Auras: 98586 - Thermal Vent Pulse)
(@CGUID+393, 52984, 861, 5733, 5748, 1, 0, 606, 0, 0, 1420.712, 553.184, 81.28659, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Thermal Pocket Bunny (Area: Fireplume Peak - Difficulty: 0) (Auras: 97966 - Thermal Vent Pulse)

DELETE FROM `creature_template_addon` WHERE `entry` IN (53353, 53228, 53230, 52985, 52162, 54515, 52984);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(53353, 0, 0, 50331648, 1, 0, '98835'),
(53228, 0, 0, 50331648, 1, 0, '98579'),
(53230, 0, 0, 50331648, 1, 0, '98586'),
(52985, 0, 0, 50331648, 1, 0, '97968'),
(52162, 0, 0, 50331648, 1, 0, '97963'),
(54515, 0, 0, 50331648, 1, 0, '101851'),
(52984, 0, 0, 50331648, 1, 0, '97966');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (53353, 53228, 53230, 52985, 52162, 54515, 52984);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53353, 0, 0, 1, 1),
(53228, 0, 0, 1, 1),
(53230, 0, 0, 1, 1),
(52985, 0, 0, 1, 1),
(52162, 0, 0, 1, 1),
(54515, 0, 0, 1, 1),
(52984, 0, 0, 1, 1);

-- Flamewakers
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+394 AND @CGUID+415;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+394, 53143, 861, 0, 0, 1, 169, 0, 0, 0, 1171.13, 354.1858, -54.12783, 1.317112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Hunter (Area: Malfurion's Breach - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+395, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1180.764, 353.9862, -54.80293, 1.27683, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+396, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1196.014, 323.2101, -56.11116, 3.517164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+397, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1203.507, 323.0938, -56.71355, 5.375614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Malfurion's Breach - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+398, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1161.741, 333.4601, -54.21024, 3.543018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Malfurion's Breach - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+399, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1227.809, 349.4965, -55.02076, 5.46012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+400, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1252.8, 291.0695, -60.95547, 3.508112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Ashen Fields - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+401, 53143, 861, 0, 0, 1, 169, 0, 0, 0, 1284.032, 298.1964, -60.79362, 0.7249299, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Hunter (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+402, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1298.915, 292.934, -62.63201, 2.75762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Ashen Fields - Difficulty: 0)
(@CGUID+403, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1307.905, 384.6233, -67.62801, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Ashen Fields - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+404, 53143, 861, 0, 0, 1, 169, 0, 0, 0, 1298.203, 326.7361, -61.52197, 0.9936522, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Hunter (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+405, 53143, 861, 0, 0, 1, 169, 0, 0, 0, 1333.63, 438.7775, -73.51795, 3.641032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Hunter (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+406, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1324.76, 286.7893, -76.4168, 3.400625, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Ashen Fields - Difficulty: 0)
(@CGUID+407, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1356.949, 395.3258, -78.07729, 3.035006, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Ashen Fields - Difficulty: 0)
(@CGUID+408, 53085, 861, 0, 0, 1, 169, 0, 0, 0, 1349.595, 301.6163, -88.55928, 0.7330383, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Sentinel (Area: Ashen Fields - Difficulty: 0)
(@CGUID+409, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1354.566, 346.1736, -91.18085, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Ashen Fields - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+410, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1337.017, 282.2639, -81.82017, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Ashen Fields - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+411, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1355.745, 328.3889, -90.59319, 2.80998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Ashen Fields - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+412, 53143, 861, 0, 0, 1, 169, 0, 0, 0, 1384.382, 315.2462, -90.85716, 0.4461097, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Hunter (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+413, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1408.024, 378.5434, -89.47787, 5.707227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Magma Springs - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+414, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1408.566, 350.3629, -90.90744, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flamewaker Shaman (Area: Magma Springs - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)
(@CGUID+415, 53093, 861, 0, 0, 1, 169, 0, 0, 0, 1392.033, 308.9913, -91.92988, 5.096361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Flamewaker Shaman (Area: Magma Springs - Difficulty: 0) (Auras: 83811 - Cosmetic - Fire Channel)

-- Druids of the Flame
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+416 AND @CGUID+439;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+416, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1302.268, 217.3612, 83.42004, 4.35088, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+417, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1199.616, 204.3353, 90.9993, 1.337717, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+418, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1361.409, 193.2654, 94.88407, 5.233003, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+419, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1267.887, 175.3429, 107.9063, 3.00527, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+420, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1301.317, 148.9002, 114.4859, 4.015952, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+421, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1390.121, 230.9245, 69.63394, 5.827021, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+422, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1264.461, 175.5867, 108.2607, 3.124217, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+423, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1301.61, 124.7014, 94.86179, 0.5836288, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+424, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1327.531, 110.2386, 99.64909, 3.991398, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+425, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1246.504, 60.97388, 85.81327, 5.233866, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+426, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1271.536, 33.57859, 80.98611, 1.745152, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+427, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1304.381, 70.72769, 106.4927, 1.424886, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+428, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1332.264, 28.72778, 78.75912, 1.790758, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+429, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1367.199, 80.73509, 89.70053, 0.8561572, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+430, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1373.119, 114.4097, 63.89763, 6.162633, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+431, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1357.491, 45.72222, 68.71637, 4.171337, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (Auras: )
(@CGUID+432, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1366.281, 78.85078, 67.09875, 4.389327, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+433, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1389.219, 100.4948, 68.66251, 5.462881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (Auras: )
(@CGUID+434, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1390.066, 82.16319, 68.8507, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (Auras: )
(@CGUID+435, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1381.728, 86.70245, 88.21121, 1.888507, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+436, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1414.47, 128.0777, 63.0629, 3.208031, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Wildflame Point - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+437, 52661, 861, 0, 0, 1, 169, 0, 0, 0, 1445.198, 125.9837, 76.59258, 1.606483, 120, 10, 0, 0, 0, 1, 0, 0, 0, 32638), -- Druid of the Flame (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+438, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1407.179, 99.1441, 68.50386, 3.874631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Druid of the Flame (Area: Wildflame Point - Difficulty: 0) (Auras: )
(@CGUID+439, 52122, 861, 0, 0, 1, 169, 0, 0, 0, 1408.356, 81.55903, 68.36261, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Druid of the Flame (Area: Wildflame Point - Difficulty: 0) (Auras: )

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 52661;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(52661, 1, 0, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry`= 52661;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52661, 0, 0, 50331648, 1, 0, '');

-- Solar Core Channel Bunny
DELETE FROM `creature` WHERE `guid`= @CGUID+440;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+440, 53662, 861, 0, 0, 1, 169, 0, 0, 0, 1398.677, 91.1684, 71.22095, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Solar Core Channel Bunny (Area: Wildflame Point - Difficulty: 0) (Auras: )

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 53662;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53662, 0, 0, 1, 0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 53388;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53388, 0, 0, 1, 0);

UPDATE `creature_template` SET `unit_flags`= 33554688 WHERE `entry`= 53388;

-- Wave Genesis Bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+441 AND @CGUID+480;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+441, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1145.726, 351.2847, -55.40242, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: The Furnace - Difficulty: 0)
(@CGUID+442, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1157.033, 329.7483, -54.72156, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+443, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1169.519, 314.5139, -54.55349, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+444, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1188.014, 312.6823, -56.15493, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+445, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1209.944, 315.4063, -57.49419, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+446, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1222.377, 324.724, -57.69511, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+447, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1240.163, 378.9913, -52.48727, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+448, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1246.132, 347.2379, -57.18493, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+449, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1241.703, 365.9688, -54.19694, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+450, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1271.123, 337.6979, -62.0975, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+451, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1254.672, 327.7708, -61.25337, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+452, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1248.493, 288.6007, -60.84779, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+453, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1239.681, 308.8958, -60.51078, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+454, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1272.634, 282.3785, -60.56466, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+455, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1294.828, 278.3299, -64.50604, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+456, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1282.63, 355.1476, -62.34419, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+457, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1285.66, 368.4844, -65.36169, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+458, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1304.335, 377.217, -66.58224, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+459, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1303.95, 347.1927, -64.26096, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+460, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1333.946, 298.5243, -85.06005, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+461, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1273.504, 387.8368, -65.33408, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+462, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1305.078, 303.3038, -65.42709, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+463, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1305.634, 326.4653, -63.46103, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+464, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1324.257, 276.5278, -76.58285, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+465, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1343.589, 318.0226, -90.63527, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+466, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1340.823, 277.2326, -84.3278, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+467, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1279.629, 381.9965, -64.86365, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+468, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1315.46, 382.7274, -68.66995, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+469, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1357.955, 381.0642, -82.7172, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+470, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1368.887, 366.1215, -90.48558, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+471, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1343.403, 383.8038, -77.80916, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+472, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1349.792, 341.3837, -91.5909, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+473, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1352.797, 359.9479, -90.58923, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+474, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1395.719, 304.75, -91.87983, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+475, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1378.84, 295.5052, -91.49333, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+476, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1360.146, 283.9826, -88.03622, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+477, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1417.898, 315.2014, -91.42863, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+478, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1423.505, 336.3212, -91.54066, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+479, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1409.509, 374.0764, -90.36641, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+480, 53099, 861, 0, 0, 1, 169, 0, 0, 0, 1412.356, 354.5833, -91.39684, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Wave Genesis Bunny (Area: Magma Springs - Difficulty: 0)

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 53099;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(53099, 0, 0, 1, 0);

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 53099;

-- Molten Splash Origin Bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+481 AND @CGUID+512;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+481, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1154.898, 166.0365, 1.837862, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+482, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1239.066, 233.1806, 1.56264, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+483, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1193.188, 199.724, 1.423576, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+484, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1231.127, 231.5, 1.578868, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+485, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1206.271, 205.3594, 1.49514, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+486, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1216.014, 197.7483, 1.496979, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+487, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1256.29, 196.2014, 1.403468, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+488, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1259.458, 221.8281, 1.581942, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+489, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1263.879, 227.7309, 1.492846, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+490, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1213.615, 184.2257, 1.47725, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+491, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1308.797, 177.0104, 1.475007, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+492, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1215.038, 145.4757, 1.650143, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+493, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1298.196, 174.0156, 1.492671, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+494, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1259.325, 164.1545, 1.66712, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+495, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1255.757, 148.625, 1.349961, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+496, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1275.653, 163.0243, 1.409448, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+497, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1206.75, 153.5104, 1.58804, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+498, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1260.254, 180.7969, 1.576199, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+499, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1260.455, 139.5504, 1.437304, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+500, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1271.023, 188.0851, 1.385704, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+501, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1172.955, 156.5486, 1.69613, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+502, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1164.799, 142.6233, 1.85929, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+503, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1247.894, 181.6059, 1.413241, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+504, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1254.491, 140.0833, 0.5653547, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+505, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1220.28, 134.1372, 1.433551, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+506, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1180.58, 154.1528, 1.57882, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+507, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1260.908, 139.8368, 0.2243515, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+508, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1250.191, 132.6302, 1.523422, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+509, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1257.965, 116.5104, 1.638085, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+510, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1208.01, 113.0538, 1.630399, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Ashen Fields - Difficulty: 0)
(@CGUID+511, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1226.248, 94.82118, 1.59332, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Molten Splash Origin Bunny (Area: Magma Springs - Difficulty: 0)
(@CGUID+512, 52893, 861, 0, 0, 1, 0, 606, 0, 0, 1212.712, 98.93924, 1.51492, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Molten Splash Origin Bunny (Area: Magma Springs - Difficulty: 0)

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 52893;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(52893, 0, 0, 1, 0);

UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 52893;

-- Obsidian Monstrosities
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+513 AND @CGUID+520;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+513, 53384, 861, 5733, 5738, 1, 404, 0, 0, 0, 1094.307, 385.6927, 24.2658, 3.74147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+514, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1085.365, 327.0695, 23.76921, 2.034426, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+515, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1091.04, 328.5, 23.7752, 2.154429, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+516, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1108.595, 367.9809, 20.57964, 3.346306, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0) (Auras: )
(@CGUID+517, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1055.688, 421.4479, 41.64957, 3.806647, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+518, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1046.684, 431.6111, 40.92262, 4.193661, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+519, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1059.231, 418.9618, 41.35825, 4.046693, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+520, 53384, 861, 5733, 5738, 1, 440, 0, 0, 0, 1108.398, 359.9896, 20.43433, 3.147131, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Obsidian Monstrosity (Area: Malfurion's Breach - Difficulty: 0)

-- Obsidian Slag Lord
DELETE FROM `creature` WHERE `guid`= @CGUID+521;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+521, 53381, 861, 5733, 5738, 1, 440, 0, 0, 0, 1027.851, 341.941, 41.52015, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Obsidian Slaglord (Area: Malfurion's Breach - Difficulty: 0) (Auras: 98979 - Obsidian Devastation)

-- Intro Phase Allied Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+522 AND @CGUID+549;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+522, 53411, 861, 5733, 5738, 1, 440, 0, 0, 0, 1078.672, 361.375, 29.85348, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+523, 53411, 861, 5733, 5738, 1, 440, 0, 0, 0, 1031.891, 403.6233, 41.60601, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+524, 53412, 861, 5733, 5738, 1, 440, 0, 0, 0, 1023.734, 395.3073, 42.24274, 1.134464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+525, 53411, 861, 5733, 5738, 1, 440, 0, 0, 0, 1070.595, 369.9201, 31.71989, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+526, 53413, 861, 5733, 5738, 1, 440, 0, 0, 0, 1042.13, 389.2465, 41.27313, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Marksman (Area: Malfurion's Breach - Difficulty: 0) (Auras: )
(@CGUID+527, 53412, 861, 5733, 5738, 1, 440, 0, 0, 0, 1073.269, 357.6719, 30.95464, 5.951573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+528, 53411, 861, 5733, 5738, 1, 440, 0, 0, 0, 1039.917, 394.3681, 41.69286, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+529, 53365, 861, 5733, 5738, 1, 440, 0, 0, 0, 1034.347, 342.8698, 41.0774, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- General Taldris Moonfall (Area: Malfurion's Breach - Difficulty: 0) (Auras: )
(@CGUID+530, 53364, 861, 5733, 5738, 1, 440, 0, 0, 0, 1023.163, 338.026, 42.7625, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Malfurion Stormrage (Area: Malfurion's Breach - Difficulty: 0) (Auras: 100854 - Tranquility)
(@CGUID+531, 53411, 861, 5733, 5738, 1, 440, 0, 0, 0, 1074.12, 351.7135, 29.55215, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79877 - Bloodthirst)
(@CGUID+532, 53413, 861, 5733, 5738, 1, 440, 0, 0, 0, 1017.795, 313.5226, 40.94373, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Marksman (Area: Malfurion's Breach - Difficulty: 0) (Auras: )
(@CGUID+533, 53412, 861, 5733, 5738, 1, 440, 0, 0, 0, 1067.938, 371.1406, 32.33867, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+534, 53412, 861, 5733, 5739, 1, 440, 0, 0, 0, 1010.415, 326.1806, 41.61065, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Ashen Fields - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+535, 53080, 861, 5733, 5738, 1, 440, 0, 0, 0, 987.6441, 375.6476, 38.64213, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Captain Irontree (Area: Malfurion's Breach - Difficulty: 0) (Auras: 78718 - Generic Quest Invisibility 8)
(@CGUID+536, 52936, 861, 5733, 5738, 1, 440, 0, 0, 0, 985.8524, 376.3924, 38.49483, 0.8552113, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Druid of the Flame (Area: Malfurion's Breach - Difficulty: 0) (Auras: 96733 - Permanent Feign Death (Stun), 78718 - Generic Quest Invisibility 8)
(@CGUID+537, 52822, 861, 5733, 5738, 1, 440, 0, 0, 0, 984.066, 376.8299, 38.33475, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Zen'Vorka (Area: Malfurion's Breach - Difficulty: 0) (Auras: 78718 - Generic Quest Invisibility 8)
(@CGUID+538, 53365, 861, 5733, 5738, 1, 450, 0, 0, 0, 1034.347, 342.8698, 41.0774, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- General Taldris Moonfall (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+539, 53413, 861, 5733, 5738, 1, 450, 0, 0, 0, 1017.795, 313.5226, 40.94373, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Marksman (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+540, 53411, 861, 5733, 5738, 1, 450, 0, 0, 0, 1039.917, 394.3681, 41.69286, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+541, 53411, 861, 5733, 5738, 1, 450, 0, 0, 0, 1070.595, 369.9201, 31.71989, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+542, 53411, 861, 5733, 5738, 1, 450, 0, 0, 0, 1074.12, 351.7135, 29.55215, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+543, 53412, 861, 5733, 5738, 1, 450, 0, 0, 0, 1023.734, 395.3073, 42.24274, 1.134464, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+544, 53411, 861, 5733, 5738, 1, 450, 0, 0, 0, 1031.891, 403.6233, 41.60601, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+545, 53413, 861, 5733, 5738, 1, 450, 0, 0, 0, 1042.13, 389.2465, 41.27313, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Marksman (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+546, 53412, 861, 5733, 5738, 1, 450, 0, 0, 0, 1010.415, 326.1806, 41.61065, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+547, 53412, 861, 5733, 5738, 1, 450, 0, 0, 0, 1073.269, 357.6719, 30.95464, 5.951573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)
(@CGUID+548, 53411, 861, 5733, 5738, 1, 450, 0, 0, 0, 1078.672, 361.375, 29.85348, 0.01745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Hyjal Defender (Area: Malfurion's Breach - Difficulty: 0)
(@CGUID+549, 53412, 861, 5733, 5738, 1, 450, 0, 0, 0, 1067.938, 371.1406, 32.33867, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Hyjal Druid (Area: Malfurion's Breach - Difficulty: 0) (Auras: 79833 - Mark of the Wild)

-- Cinderlings
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+550 AND @CGUID+633;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+550, 53697, 861, 5733, 5739, 1, 169, 0, 0, 0, 1178.179, 197.8019, 54.73366, 3.122575, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+551, 53697, 861, 5733, 5739, 1, 169, 0, 0, 0, 1217.001, 228.5572, 54.2291, 5.334832, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+552, 53697, 861, 5733, 5739, 1, 169, 0, 0, 0, 1217.845, 224.7002, 54.20273, 4.747075, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+553, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1289.71, 222.3737, 54.22658, 5.848917, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+554, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1229.538, 209.9657, 57.09446, 6.180294, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+555, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1283.95, 211.7152, 54.22658, 4.387964, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+556, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1239.583, 204.166, 57.83494, 0.4124404, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+557, 53697, 861, 5733, 5739, 1, 169, 0, 0, 0, 1214.193, 188.1641, 55.06216, 5.187513, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+558, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1305.794, 190.3665, 52.75506, 0.4947799, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+559, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1336.702, 196.7851, 49.02479, 0.9844576, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+560, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1325.811, 192.4614, 49.13006, 5.500931, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+561, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1320.833, 187.5, 49.94256, 3.505255, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+562, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1325.167, 191.9347, 49.28534, 3.419627, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+563, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1337.895, 198.6293, 49.19257, 6.048628, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+564, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1300.16, 175.1251, 52.75506, 1.740288, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+565, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1303.632, 172.4149, 52.11119, 3.874631, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+566, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1378.875, 209.0326, 56.26792, 1.331032, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+567, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1309.333, 167.9188, 49.13018, 2.060639, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+568, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1374.678, 209.5629, 56.17324, 6.094435, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+569, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1352.967, 180.8938, 50.88367, 2.814316, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+570, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1366.204, 209.1019, 56.16646, 5.702567, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+571, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1344.615, 186.9316, 49.52479, 5.71498, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+572, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1349.884, 190.9841, 49.02479, 5.662807, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+573, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1324.915, 164.0027, 49.20216, 0.7437112, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+574, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1333.091, 163.2914, 49.02479, 3.749555, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+575, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1331.744, 162.203, 49.02479, 3.049222, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+576, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1328.078, 168.3944, 49.41119, 4.384466, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+577, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1334.6, 169.1851, 49.02479, 3.77983, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+578, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1314.925, 166.3446, 49.07292, 3.194597, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+579, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1279.153, 164.0104, 57.92151, 3.874631, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+580, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1338.909, 170.3633, 49.15589, 1.00122, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+581, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1266.268, 173.2301, 54.6479, 5.916313, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+582, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1377.947, 180.1919, 57.7728, 0.02383069, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+583, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1388.094, 192.3027, 56.90446, 1.198995, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+584, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1246.512, 172.5391, 54.21845, 1.434374, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+585, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1284.972, 145.6077, 61.7035, 4.782384, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+586, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1279.152, 131.4495, 63.70436, 3.395927, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+587, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1282.63, 131.2312, 63.53397, 6.259048, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+588, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1273.094, 121.8873, 65.01551, 2.166952, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+589, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1389.051, 185.2285, 57.73032, 1.561074, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+590, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1346.757, 130.6399, 61.47342, 6.193159, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+591, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1326.691, 118.1831, 62.21179, 4.442841, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+592, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1342.102, 130.6927, 61.69537, 3.874631, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+593, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1351.022, 123.8277, 62.34464, 2.574742, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+594, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1344.83, 115.5971, 62.34816, 1.39837, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+595, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1330.652, 106.6277, 62.96362, 3.84879, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+596, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1343.182, 112.4079, 62.66371, 1.107149, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+597, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1350.266, 119.0602, 62.24049, 3.961125, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+598, 53697, 861, 5733, 5741, 1, 169, 0, 0, 0, 1294.308, 85.01921, 68.21794, 3.783054, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+599, 53697, 861, 5733, 5742, 1, 169, 0, 0, 0, 1281.25, 72.91602, 69.12273, 0.7202879, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+600, 53697, 861, 5733, 5742, 1, 169, 0, 0, 0, 1279.526, 74.06757, 69.5927, 1.051644, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+601, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1347.832, 49.4704, 68.71809, 5.514549, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+602, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1350.005, 47.8564, 68.58233, 6.164974, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+603, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1354.167, 54.16602, 68.4976, 3.926991, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+604, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1360.935, 53.50636, 68.37285, 3.02748, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+605, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1363.162, 47.67662, 68.56569, 3.086477, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+606, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1364.786, 45.91422, 68.60735, 3.784015, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+607, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1353.149, 50.77045, 68.63369, 2.576544, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+608, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1384.992, 88.39361, 68.73497, 4.842166, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+609, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1385.983, 88.94965, 68.83441, 3.874631, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+610, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1391.805, 141.5697, 62.52158, 5.055404, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+611, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1394.546, 99.30664, 68.84837, 3.787295, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+612, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1392.683, 142.0615, 62.63132, 0.4156931, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+613, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1402.014, 143.2026, 62.45831, 4.925303, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+614, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1403.409, 145.7727, 62.59647, 4.808005, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+615, 53697, 861, 5733, 5743, 1, 169, 0, 0, 0, 1422.81, 159.513, 62.46207, 2.010059, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: The Widow's Clutch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+616, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1439.032, 137.6139, 62.33924, 2.642833, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+617, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1442.395, 135.9586, 62.29847, 4.423066, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+618, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1412.269, 94.24795, 68.79524, 6.085598, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+619, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1435.336, 116.9723, 64.43794, 3.421263, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+620, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1433.018, 143.6276, 63.09049, 4.149153, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+621, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1439.701, 110.3815, 64.95124, 4.594824, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+622, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1412.644, 97.91482, 68.29903, 3.358881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+623, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1403.258, 76.17469, 68.33272, 6.225134, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+624, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1402.3, 81.05598, 68.78352, 5.474565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+625, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1434.082, 78.73371, 67.05524, 3.486193, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+626, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1435.857, 84.68945, 66.76099, 2.030431, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+627, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1423.952, 69.82249, 68.00777, 3.263495, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+628, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1420.814, 68.10141, 67.21834, 1.906995, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+629, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1440.218, 84.87667, 66.02662, 3.110413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+630, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1378.011, 49.24386, 69.03722, 4.789141, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+631, 53697, 861, 5733, 5744, 1, 169, 0, 0, 0, 1386.27, 45.34177, 68.09455, 0.08776706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+632, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1378.646, 208.334, 56.17324, 4.374047, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderling (Area: Magma Springs - Difficulty: 0)
(@CGUID+633, 53697, 861, 5733, 5740, 1, 169, 0, 0, 0, 1379.691, 178.4836, 57.91599, 1.974056, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderling (Area: Magma Springs - Difficulty: 0)

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 4 WHERE `guid` BETWEEN @CGUID+550 AND @CGUID+633;

-- Cinderweb Cocoons
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+634 AND @CGUID+675;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+634, 52784, 861, 5733, 5739, 1, 169, 0, 0, 0, 1218.332, 229.5504, 55.749, 3.595378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Ashen Fields - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+635, 52751, 861, 5733, 5739, 1, 169, 0, 0, 0, 1235.438, 226.8663, 56.47276, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Ashen Fields - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+636, 52989, 861, 5733, 5740, 1, 169, 0, 0, 0, 1295.97, 218.7708, 64.60729, 2.70526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+637, 52992, 861, 5733, 5740, 1, 169, 0, 0, 0, 1300.781, 219.526, 65.57326, 0.6283185, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+638, 52784, 861, 5733, 5740, 1, 169, 0, 0, 0, 1239.549, 202.1215, 60.18753, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+639, 52751, 861, 5733, 5740, 1, 169, 0, 0, 0, 1335.778, 229.7951, 56.08848, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+640, 52784, 861, 5733, 5740, 1, 169, 0, 0, 0, 1321.476, 194.6927, 50.03663, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+641, 52751, 861, 5733, 5740, 1, 169, 0, 0, 0, 1378.642, 206.4913, 58.38434, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+642, 52991, 861, 5733, 5740, 1, 169, 0, 0, 0, 1374.481, 202.2899, 74.50113, 2.670354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Magma Springs - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+643, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1310.29, 164.1458, 49.27796, 1.343904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+644, 52989, 861, 5733, 5741, 1, 169, 0, 0, 0, 1366.101, 182.9826, 61.8412, 4.363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+645, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1345.892, 167.8854, 52.48146, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+646, 52751, 861, 5733, 5741, 1, 169, 0, 0, 0, 1273.573, 159.1111, 61.5289, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+647, 52783, 861, 5733, 5741, 1, 169, 0, 0, 0, 1347.146, 158.9063, 58.82116, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+648, 52751, 861, 5733, 5741, 1, 169, 0, 0, 0, 1255.252, 167.5833, 62.29554, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+649, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1282.316, 154.1389, 63.94584, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+650, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1387.816, 198.8264, 55.2949, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+651, 52991, 861, 5733, 5741, 1, 169, 0, 0, 0, 1322.743, 152.9236, 55.51886, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+652, 52783, 861, 5733, 5741, 1, 169, 0, 0, 0, 1384.792, 183.9809, 56.87328, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+653, 52991, 861, 5733, 5741, 1, 169, 0, 0, 0, 1266.507, 153.8264, 75.00729, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+654, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1270.012, 123.8385, 65.40876, 4.799655, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+655, 52751, 861, 5733, 5741, 1, 169, 0, 0, 0, 1342.16, 115.651, 61.84163, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+656, 52989, 861, 5733, 5741, 1, 169, 0, 0, 0, 1342.285, 126.0694, 72.14193, 1.308997, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+657, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1308.608, 82.72569, 68.10225, 0.8726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+658, 52751, 861, 5733, 5741, 1, 169, 0, 0, 0, 1296.194, 81.30556, 69.53432, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+659, 52992, 861, 5733, 5741, 1, 169, 0, 0, 0, 1246.542, 148.5677, 98.47504, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+660, 52989, 861, 5733, 5741, 1, 169, 0, 0, 0, 1253.066, 144.4879, 105.9522, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+661, 52992, 861, 5733, 5741, 1, 169, 0, 0, 0, 1253.585, 142.8177, 107.057, 0.3316126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+662, 52989, 861, 5733, 5743, 1, 169, 0, 0, 0, 1248.493, 144.4514, 110.0195, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+663, 52751, 861, 5733, 5742, 1, 169, 0, 0, 0, 1230.934, 68.68056, 74.4147, 5.707227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: Forlorn Spire - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+664, 52751, 861, 5733, 5743, 1, 169, 0, 0, 0, 1300.727, 68.14931, 72.30009, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)
(@CGUID+665, 52783, 861, 5733, 5743, 1, 169, 0, 0, 0, 1277.217, 131.3351, 63.91787, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon)
(@CGUID+666, 52784, 861, 5733, 5743, 1, 169, 0, 0, 0, 1329.648, 123.7188, 62.07615, 3.944444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon)
(@CGUID+667, 52783, 861, 5733, 5743, 1, 169, 0, 0, 0, 1336.354, 131.1788, 63.05054, 1.867502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon)
(@CGUID+668, 52783, 861, 5733, 5743, 1, 169, 0, 0, 0, 1319.05, 149.7101, 60.66432, 4.799655, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon)
(@CGUID+669, 52784, 861, 5733, 5743, 1, 169, 0, 0, 0, 1283.188, 146.5347, 62.58172, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon)
(@CGUID+670, 52784, 861, 5733, 5743, 1, 169, 0, 0, 0, 1302.262, 115.5417, 65.59122, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon)
(@CGUID+671, 52783, 861, 5733, 5743, 1, 169, 0, 0, 0, 1335.47, 111.5243, 62.57986, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97535 - Cinderweb Cocoon)
(@CGUID+672, 52751, 861, 5733, 5743, 1, 169, 0, 0, 0, 1336.623, 165.1649, 50.84542, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon)
(@CGUID+673, 52751, 861, 5733, 5743, 1, 169, 0, 0, 0, 1323.561, 203.8767, 55.88696, 2.460914, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon)
(@CGUID+674, 52751, 861, 5733, 5743, 1, 169, 0, 0, 0, 1372.521, 179.8368, 58.81996, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Cocoon (Area: The Widow's Clutch - Difficulty: 0) (Auras: 97503 - Cinderweb Cocoon)
(@CGUID+675, 52784, 861, 5733, 5741, 1, 169, 0, 0, 0, 1223.267, 207.6997, 57.38671, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderweb Cocoon (Area: Igneous Depths - Difficulty: 0) (Auras: 97539 - Cinderweb Cocoon, 97999 - Wicked Web Sparkle)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (52784, 52751, 52783, 52989);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(52784, 0, 0, 1, 1),
(52751, 0, 0, 1, 1),
(52783, 0, 0, 1, 1),
(52989, 0, 0, 1, 1);

-- Cinderweb Creepers
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+676 AND @CGUID+694;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+676, 52648, 861, 5733, 5739, 1, 169, 0, 0, 0, 1218.17, 218.776, 54.42673, 0.8364646, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+677, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1297.274, 229.8264, 56.38478, 2.358568, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+678, 52648, 861, 5733, 5739, 1, 169, 0, 0, 0, 1197.4, 206.9218, 54.55704, 0.4985679, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Ashen Fields - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+679, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1336.652, 215.6509, 55.3971, 5.630111, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+680, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1304.84, 204.2383, 55.6681, 4.598837, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+681, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1322.684, 168.1476, 49.73577, 5.798249, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+682, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1372.715, 220.3663, 56.29108, 1.532989, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+683, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1310.837, 179.7517, 51.06549, 0.7633722, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+684, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1330.916, 182.9677, 49.42194, 2.78648, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+685, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1296.16, 155.4045, 60.36671, 4.044805, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+686, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1253.193, 181.6684, 54.26441, 5.299404, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+687, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1334.661, 142.8613, 59.89979, 2.656039, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+688, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1270.836, 110.9274, 66.14393, 5.604993, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+689, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1310.29, 115.7743, 64.99109, 4.238372, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+690, 52648, 861, 5733, 5741, 1, 169, 0, 0, 0, 1264.155, 77.34722, 69.40537, 0.1009899, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+691, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1409.497, 193.9722, 58.24613, 0.7032777, 120, 10, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+692, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1334.602, 218.6484, 56.18507, 1.891621, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0)
-- (@CGUID+693, 52648, 861, 5733, 5740, 1, 169, 0, 0, 0, 1371.408, 218.84, 56.37148, 4.004398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Creeper (Area: Magma Springs - Difficulty: 0)
-- (@CGUID+694, 52648, 861, 5733, 5743, 1, 169, 0, 0, 0, 1335.608, 140.9378, 59.89979, 4.013091, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderweb Creeper (Area: The Widow's Clutch - Difficulty: 0)

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid` BETWEEN @CGUID+676 AND @CGUID+694;

-- Cinderweb Spinners
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+695 AND @CGUID+735;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+695, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1242.231, 230.5608, 66.69836, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+696, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1293.967, 219.8872, 63.47049, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+697, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1299.141, 212.1892, 70.75788, 5.742133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+698, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1305.788, 217.7431, 63.12412, 3.612832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+699, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1227.146, 200.276, 72.08092, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+700, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1331.78, 202.8299, 60.63742, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+701, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1356.722, 202.5608, 71.53149, 5.270895, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+702, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1355.069, 187.9132, 63.03679, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+703, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1369.7, 204.7951, 75.39964, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+704, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1373.563, 196.2361, 88.70942, 4.904375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+705, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1364.743, 185.9844, 71.57078, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+706, 52981, 861, 5733, 5740, 1, 169, 0, 0, 0, 1375.042, 200.7431, 83.13981, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Magma Springs - Difficulty: 0)
(@CGUID+707, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1325.181, 158.1927, 53.34721, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+708, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1263.474, 164.7344, 68.37067, 1.029744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+709, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1344.184, 165.8108, 66.80658, 2.303835, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+710, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1310.92, 158.2899, 63.10141, 0.8726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+711, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1279.979, 154.6198, 75.39706, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+712, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1250.043, 164.8906, 91.06998, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+713, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1272.201, 156.974, 91.59418, 2.548181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+714, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1265.365, 160.566, 75.30422, 4.34587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+715, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1241.766, 165.3594, 72.97275, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+716, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1280.918, 146.8663, 82.99105, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+717, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1281.401, 136.9149, 78.62451, 4.939282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+718, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1235.313, 158.7917, 81.61862, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+719, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1270.681, 128.2517, 80.29505, 5.253441, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+720, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1240.418, 135.8247, 82.55222, 1.082104, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+721, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1236.611, 146.8681, 87.53996, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+722, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1257.623, 127.6024, 82.32114, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+723, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1256.438, 153.6615, 99.69111, 4.660029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+724, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1275.979, 141.2882, 94.74725, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+725, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1249.667, 133.1111, 92.9393, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+726, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1267.061, 134.0747, 95.03967, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+727, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1329.736, 116.5313, 78.21581, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+728, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1243.604, 154.474, 97.45322, 5.218534, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+729, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1257.13, 146.4931, 106.1598, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+730, 52981, 861, 5733, 5741, 1, 169, 0, 0, 0, 1257.797, 142.1094, 106.1271, 3.630285, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Igneous Depths - Difficulty: 0)
(@CGUID+731, 52981, 861, 5733, 5743, 1, 169, 0, 0, 0, 1250.531, 146.1233, 115.7219, 4.101524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+732, 52981, 861, 5733, 5743, 1, 169, 0, 0, 0, 1253.193, 140.6771, 113.2215, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+733, 52981, 861, 5733, 5742, 1, 169, 0, 0, 0, 1290.563, 77.03993, 85.87921, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Forlorn Spire - Difficulty: 0)
(@CGUID+734, 52981, 861, 5733, 5742, 1, 169, 0, 0, 0, 1300.189, 83.40625, 77.82433, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Spinner (Area: Forlorn Spire - Difficulty: 0)
(@CGUID+735, 52981, 861, 5733, 5742, 1, 169, 0, 0, 0, 1300.571, 75.72222, 93.57031, 1.605703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderweb Spinner (Area: Forlorn Spire - Difficulty: 0)

-- Cinderweb Broodlings
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+736 AND @CGUID+789;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+736, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1264.854, 233.5781, 55.04795, 4.326959, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+737, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1263.538, 235.158, 55.01041, 4.178762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+738, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1261.446, 232.3299, 55.33854, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+739, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1260.03, 232.9896, 54.82582, 4.214151, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+740, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1263.014, 230.3507, 55.60243, 4.223252, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+741, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1259.849, 230.9774, 55.50521, 4.257485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+742, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1263.059, 233.4201, 55.14063, 4.245949, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+743, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1260.007, 234.8698, 54.8491, 4.092848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+744, 53753, 861, 5733, 5741, 1, 169, 0, 0, 0, 1261.837, 235.1337, 55.04203, 4.135142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Igneous Depths - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+745, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1403.234, 210.8958, 56.72396, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+746, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1405.064, 211.1597, 56.5911, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+747, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1404.674, 208.3559, 56.78299, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+748, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1403.257, 209.0156, 56.7066, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+749, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1403.076, 207.0035, 56.80903, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+750, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1408.082, 209.6042, 56.73264, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+751, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1406.766, 211.184, 56.45833, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+752, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1406.286, 209.4462, 56.58552, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+753, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1406.241, 206.3767, 56.79861, 4.223697, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+754, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1400.503, 185.7905, 58.32002, 4.735489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+755, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1400.737, 180.8875, 58.78621, 4.454618, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+756, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1399.512, 182.6207, 58.51513, 4.375807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+757, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1398.347, 177.5388, 58.4329, 4.210316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+758, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1396.381, 179.0289, 57.88731, 4.29595, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+759, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1398.632, 180.0153, 58.45218, 4.1656, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+760, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1397.51, 181.9361, 58.21119, 4.375807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+761, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1396.381, 179.0289, 57.88731, 4.29595, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+762, 53753, 861, 5733, 5744, 1, 169, 0, 0, 0, 1396.381, 179.0289, 57.88731, 4.29595, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Wildflame Point - Difficulty: 0)
(@CGUID+763, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1322.611, 76.85243, 68.2309, 1.775443, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+764, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1320.644, 79.20834, 68.36806, 1.743499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+765, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1325.87, 77.74827, 67.77952, 1.610695, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+766, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1323.455, 80.80209, 67.8925, 1.784107, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+767, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1324.665, 76.35416, 67.9375, 1.645972, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+768, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1321.361, 75.56077, 68.38889, 1.850797, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+769, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1323.389, 75.22916, 68.11879, 1.694263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+770, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1324.625, 79.16319, 67.86137, 1.737478, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+771, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1323.123, 78.7309, 68.08743, 1.455494, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+772, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1288.423, 130.0055, 64.43385, 0.8337243, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+773, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1290.572, 132.5957, 64.07935, 0.8372548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+774, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1287.978, 127.242, 63.96485, 0.878339, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+775, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1296.108, 138.0099, 62.32068, 1.16398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+776, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1294.818, 153.5234, 60.51555, 2.14027, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+777, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1297.984, 139.9478, 61.91425, 1.206078, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+778, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1293.435, 140.6891, 61.8693, 1.121128, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+779, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1293.271, 136.7993, 62.46668, 1.219107, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+780, 53753, 861, 5733, 5742, 1, 169, 0, 0, 0, 1294.439, 138.6256, 62.19211, 1.217516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Forlorn Spire - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+781, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1311.547, 209.0204, 56.04328, 0.5370632, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+782, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1304.86, 208.1663, 55.54542, 0.2972684, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+783, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1300.2, 207.9648, 54.77479, 0.2225231, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+784, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1309.744, 211.5676, 55.89979, 0.3573864, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+785, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1302.165, 204.7167, 55.08985, 0.6506813, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+786, 53753, 861, 5733, 5740, 1, 169, 0, 0, 0, 1302.569, 201.8943, 55.22645, 0.6428849, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: Magma Springs - Difficulty: 0)
(@CGUID+787, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1317.162, 211.4309, 56.3693, 0.5787358, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+788, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1317.139, 211.4467, 56.36906, 0.5787069, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)
(@CGUID+789, 53753, 861, 5733, 5743, 1, 169, 0, 0, 0, 1317.163, 211.4308, 56.36938, 0.5786256, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Cinderweb Broodling (Area: The Widow's Clutch - Difficulty: 0)

-- Chain Bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+790 AND @CGUID+791;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+790, 52976, 861, 5733, 5741, 1, 169, 0, 0, 0, 1160.717, 161.2865, 62.40697, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Chain Bunny (Area: Igneous Depths - Difficulty: 0) (Auras: )
(@CGUID+791, 52976, 861, 5733, 5741, 1, 169, 0, 0, 0, 1156.116, 167.1198, 62.3163, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Chain Bunny (Area: Igneous Depths - Difficulty: 0) (Auras: )

-- Flame Protection Runes
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+790 AND @CGUID+799;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+792, 52884, 861, 5733, 5741, 1, 169, 0, 0, 0, 1317.427, 203.0156, 14.57971, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras: 97751  - Flame Protection Rune, 49414 - Generic Quest Invisibility 1)
(@CGUID+793, 52889, 861, 5733, 5741, 1, 169, 0, 0, 0, 1281.872, 200.4306, 3.880525, 3.787364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras: 97770  - Flame Protection Rune, 82358 - Generic Quest Invisibility 6)
(@CGUID+794, 52888, 861, 5733, 5741, 1, 169, 0, 0, 0, 1225.686, 213.1754, 4.150037, 4.24115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras:  97769  - Flame Protection Rune, 80797 - Generic Quest Invisibility 5)
(@CGUID+795, 52885, 861, 5733, 5741, 1, 169, 0, 0, 0, 1287.79, 144.0816, 4.344028, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras:  97766  - Flame Protection Rune, 49415 - Generic Quest Invisibility 2)
(@CGUID+796, 52890, 861, 5733, 5741, 1, 169, 0, 0, 0, 1231.351, 163.3281, 10.80713, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras: 97772  - Flame Protection Rune, 78718 - Generic Quest Invisibility 8)
(@CGUID+797, 52886, 861, 5733, 5741, 1, 169, 0, 0, 0, 1239.108, 114.2344, 4.342485, 3.01942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras:  97767  - Flame Protection Rune, 60921 - Generic Quest Invisibility 3)
(@CGUID+798, 52887, 861, 5733, 5741, 1, 169, 0, 0, 0, 1177.724, 170.0608, 4.470245, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638), -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras: 97768  - Flame Protection Rune, 82343 - Generic Quest Invisibility 4)
(@CGUID+799, 53887, 861, 5733, 5741, 1, 169, 0, 0, 0, 1174.266, 123.0313, 4.33702, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 32638); -- Flame Protection Rune (Area: Igneous Depths - Difficulty: 0) (Auras: 100337 - Flame Protection Rune, 85096 - Generic Quest Invisibility 7)

DELETE FROM `creature_template_addon` WHERE `entry` IN (52135, 52822, 53080, 52489, 52825, 52531, 54339, 53911, 52884, 52889, 52888, 52885, 52890, 52886, 52887, 53887, 52784, 52751, 52989, 52992);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52135, 0, 1, 0, '84886'),
(52822, 0, 1, 0, '84886'),
(53080, 0, 1, 0, '84886'),
(52489, 0, 1, 0, '87872'),
(52531, 0, 1, 0, '97124'),
(54339, 0, 1, 0, '42648'),
(52825, 1, 1, 0, ''),
(53911, 0, 1, 333, '89304'),
(52884, 0, 1, 0, '97751 49414'),
(52889, 0, 1, 0, '97770 82358'),
(52888, 0, 1, 0, '97769 80797'),
(52885, 0, 1, 0, '97766 49415'),
(52890, 0, 1, 0, '97772 78718'),
(52886, 0, 1, 0, '97767 60921'),
(52887, 0, 1, 0, '97768 82343'),
(53887, 0, 1, 0, '100337 85096'),
(52784, 0, 1, 0, '97539 97999'),
(52751, 0, 1, 0, '97503 97999'),
(52989, 0, 1, 0, '97539 97999'),
(52992, 0, 1, 0, '97503 97999');

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+187;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 208586, 861, 0, 0, 1, 0, 606, 983.4531, 373.2691, 39.03386, 2.696529, 0, 0, 0.9753418,0.2206997, 120, 255, 1, 15595), -- Sentinel Tree (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+1, 208552, 861, 0, 0, 1, 0, 606, 1038.191, 301.4392, 41.43575, 1.954769, 0, 0, 0.8290377, 0.5591928, 120, 255, 1, 15595), -- Portal to Mount Hyjal (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+2, 208529, 861, 0, 0, 1, 0, 606, 1165.922, 128.1129, 56.71014, 0.6806777, 0.0033741, -0.0009078979, 0.3338099, 0.9426339, 120, 255, 1, 15595), -- Forlorn Spire (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+3, 208596, 861, 0, 0, 1, 169, 0, 1233.524, 187.4358, 10.2227, 2.44346, 0, 0, 0.9396925, 0.3420205, 120, 255, 1, 15595), -- Flame Druid Idol Trap (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+4, 208596, 861, 0, 0, 1, 169, 0, 1177.054, 116.3646, 3.885709, 2.775069, 0, 0, 0.9832544, 0.182238, 120, 255, 1, 15595), -- Flame Druid Idol Trap (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+5, 208427, 861, 0, 0, 1, 169, 0, 1165.839, 533.7188, 53.53424, 3.106652, 0, 0, 0.9998474, 0.01746928, 120, 255, 1, 15595), -- Furnace Door (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+6, 208601, 861, 0, 0, 1, 0, 606, 1274.774, 529.2535, 70.66697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+7, 208600, 861, 0, 0, 1, 0, 606, 1304.679, 524.7899, 64.12486, 0.122173, 0, 0, 0.06104851, 0.9981348, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+8, 208601, 861, 0, 0, 1, 0, 606, 1280.658, 516.8559, 56.63413, 1.623156, 0, 0, 0.7253742, 0.6883547, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+9, 208599, 861, 0, 0, 1, 0, 606, 1297, 532.9601, 68.63535, 1.361356, 0, 0, 0.6293201, 0.7771462, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+10, 208600, 861, 0, 0, 1, 0, 606, 1308.314, 503.382, 66.32652, 1.256636, 0, 0, 0.5877848, 0.8090174, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+11, 208598, 861, 0, 0, 1, 0, 606, 1215.71, 678.066, 67.59092, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+12, 208599, 861, 0, 0, 1, 0, 606, 1310.998, 510.2014, 64.94956, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 0, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+13, 208600, 861, 0, 0, 1, 0, 606, 1274.285, 535.2153, 72.58718, 5.585054, 0, 0, -0.34202, 0.9396927, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+14, 208337, 861, 0, 0, 1, 0, 606, 1299.293, 501.0087, 54.98239, 0.4363316, 0, 0, 0.2164392, 0.9762961, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+15, 208601, 861, 0, 0, 1, 0, 606, 1295.573, 539.8871, 68.6303, 2.199115, 0, 0, 0.8910065, 0.4539906, 120, 255, 0, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+16, 208598, 861, 0, 0, 1, 0, 606, 1280.872, 533.6511, 71.54182, 6.161013, 0, 0, -0.06104851, 0.9981348, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+17, 208601, 861, 0, 0, 1, 0, 606, 1271.222, 539.3924, 73.80917, 1.466076, 0, 0, 0.6691303, 0.743145, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+18, 208598, 861, 0, 0, 1, 0, 606, 1319.705, 524.2674, 68.29909, 1.448622, 0, 0, 0.6626196, 0.7489561, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+19, 208600, 861, 0, 0, 1, 0, 606, 1304.481, 508.0799, 64.81101, 5.585054, 0, 0, -0.34202, 0.9396927, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+20, 208600, 861, 0, 0, 1, 0, 606, 1292.444, 505.8403, 55.18653, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+21, 208601, 861, 0, 0, 1, 0, 606, 1306.439, 514.3611, 63.67892, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+22, 208600, 861, 0, 0, 1, 0, 606, 1303.161, 519.0313, 62.62799, 5.340709, 0, 0, -0.45399, 0.8910068, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+23, 208598, 861, 0, 0, 1, 0, 606, 1276.918, 522.2743, 55.78998, 1.082103, 0, 0, 0.5150375, 0.8571676, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+24, 208599, 861, 0, 0, 1, 0, 606, 1290.969, 513.1788, 56.19556, 1.361356, 0, 0, 0.6293201, 0.7771462, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+25, 208600, 861, 0, 0, 1, 0, 606, 1319.745, 500.4445, 68.76932, 1.797689, 0, 0, 0.782608, 0.6225148, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+26, 208598, 861, 0, 0, 1, 0, 606, 1287.835, 541.3403, 53.5155, 1.082103, 0, 0, 0.5150375, 0.8571676, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+27, 208600, 861, 0, 0, 1, 0, 606, 1409.943, 498.4323, 69.73815, 1.256636, 0, 0, 0.5877848, 0.8090174, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+28, 208596, 861, 0, 0, 1, 169, 0, 1302.613, 163.3385, 5.783576, 1.012289, 0, 0, 0.4848089, 0.8746201, 120, 255, 1, 15595), -- Flame Druid Idol Trap (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+29, 208600, 861, 0, 0, 1, 0, 606, 1286.335, 517.9271, 57.56302, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+30, 208601, 861, 0, 0, 1, 0, 606, 1307.55, 530.4861, 65.36221, 1.623156, 0, 0, 0.7253742, 0.6883547, 120, 255, 0, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+31, 208337, 861, 0, 0, 1, 0, 606, 1377.797, 504.224, 77.68762, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+32, 208596, 861, 0, 0, 1, 169, 0, 1241.227, 138.033, 8.703369, 1.937312, 0, 0, 0.8241253, 0.5664076, 120, 255, 1, 15595), -- Flame Druid Idol Trap (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+33, 208598, 861, 0, 0, 1, 0, 606, 1275.634, 544.4792, 74.892, 6.161013, 0, 0, -0.06104851, 0.9981348, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+34, 208599, 861, 0, 0, 1, 0, 606, 1209.755, 669.6268, 63.34755, 5.497789, 0, 0, -0.3826828, 0.9238798, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+35, 208337, 861, 0, 0, 1, 0, 606, 1324.028, 506.4358, 69.59717, 0.4363316, 0, 0, 0.2164392, 0.9762961, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+36, 208598, 861, 0, 0, 1, 0, 606, 1279.734, 510.7066, 55.78998, 4.398232, 0, 0, -0.8090162, 0.5877863, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+37, 208601, 861, 0, 0, 1, 0, 606, 1292.375, 518.9792, 58.96901, 1.623156, 0, 0, 0.7253742, 0.6883547, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+38, 208599, 861, 0, 0, 1, 0, 606, 1314.177, 529.5261, 66.71404, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+39, 208600, 861, 0, 0, 1, 0, 606, 1264.629, 578.066, 66.32529, 0.5235979, 0, 0, 0.2588186, 0.9659259, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+40, 208599, 861, 0, 0, 1, 0, 606, 1281.821, 528.3611, 54.81091, 1.361356, 0, 0, 0.6293201, 0.7771462, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+41, 208599, 861, 0, 0, 1, 0, 606, 1297.757, 509.6181, 54.78472, 0.5061446, 0, 0, 0.2503796, 0.9681478, 120, 255, 0, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+42, 208600, 861, 0, 0, 1, 0, 606, 1287.747, 533.1545, 53.38426, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+43, 208599, 861, 0, 0, 1, 0, 606, 1348.623, 496.4861, 38.41882, 5.497789, 0, 0, -0.3826828, 0.9238798, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+44, 208599, 861, 0, 0, 1, 0, 606, 1388.49, 484.9688, 59.48045, 5.497789, 0, 0, -0.3826828, 0.9238798, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+45, 208601, 861, 0, 0, 1, 0, 606, 1301.793, 529.757, 65.36221, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+46, 208598, 861, 0, 0, 1, 0, 606, 1255.951, 608.9879, 72.42764, 1.082103, 0, 0, 0.5150375, 0.8571676, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+47, 208601, 861, 0, 0, 1, 0, 606, 1284.903, 642.8038, 79.31062, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+48, 208599, 861, 0, 0, 1, 0, 606, 1313.474, 499.2865, 67.81162, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+49, 208601, 861, 0, 0, 1, 0, 606, 1344.849, 588.8004, 95.65179, 4.694937, 0, 0, -0.7132502, 0.7009096, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+50, 208599, 861, 0, 0, 1, 0, 606, 1281.514, 536.4983, 53.41334, 0.5061446, 0, 0, 0.2503796, 0.9681478, 120, 255, 0, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+51, 208598, 861, 0, 0, 1, 0, 606, 1288.854, 535.4184, 70.31609, 1.082103, 0, 0, 0.5150375, 0.8571676, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+52, 208598, 861, 0, 0, 1, 0, 606, 1298.335, 523.8976, 61.32526, 1.884953, 0, 0, 0.8090162, 0.5877863, 120, 255, 1, 15595), -- Jumping Rock, 0.9 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+53, 208600, 861, 0, 0, 1, 0, 606, 1289.967, 524.5104, 60.30908, 0.5235979, 0, 0, 0.2588186, 0.9659259, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+54, 208337, 861, 0, 0, 1, 0, 606, 1303.83, 537.6493, 66.86414, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+55, 208337, 861, 0, 0, 1, 0, 606, 1272.554, 573.0781, 68.88896, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+56, 208600, 861, 0, 0, 1, 0, 606, 1421.497, 501.5017, 75.04331, 5.585054, 0, 0, -0.34202, 0.9396927, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+57, 208601, 861, 0, 0, 1, 0, 606, 1343.431, 594.8125, 97.24117, 2.042035, 0, 0, 0.8526402, 0.5224986, 120, 255, 1, 15595), -- Jumping Rock, 0.6 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+58, 208599, 861, 0, 0, 1, 0, 606, 1425.873, 495.5035, 73.86761, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 1, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+59, 208337, 861, 0, 0, 1, 0, 606, 1421.328, 487.5278, 72.84309, 0.4363316, 0, 0, 0.2164392, 0.9762961, 120, 255, 1, 15595), -- Jumping Rock, 1.0 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+60, 208599, 861, 0, 0, 1, 0, 606, 1428.014, 503.6233, 75.49563, 6.108654, 0, 0, -0.08715534, 0.9961947, 120, 255, 0, 15595), -- Jumping Rock, 0.8 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+61, 208600, 861, 0, 0, 1, 0, 606, 1338.752, 599.9757, 98.85905, 2.268925, 0, 0, 0.9063072, 0.4226195, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+62, 208600, 861, 0, 0, 1, 0, 606, 1297.875, 656.6771, 103.6256, 5.585054, 0, 0, -0.34202, 0.9396927, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+63, 208600, 861, 0, 0, 1, 0, 606, 1422.413, 508.1337, 76.30202, 0.9773831, 0, 0, 0.469471, 0.8829479, 120, 255, 1, 15595), -- Jumping Rock, 0.7 (Area: Malfurion's Breach - Difficulty: 0)
(@OGUID+64, 208540, 861, 0, 0, 1, 169, 0, 1211.924, 378.0625, 15.85501, 3.176533, 0, 0, -0.9998474, 0.01746928, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+65, 208551, 861, 0, 0, 1, 169, 0, 1208.474, 309.1024, -37.79697, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+66, 208540, 861, 0, 0, 1, 169, 0, 1259.648, 319.0903, 21.33871, 3.351047, 0, 0, -0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+67, 208540, 861, 0, 0, 1, 169, 0, 1275.172, 343.8767, 21.35103, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+68, 208540, 861, 0, 0, 1, 169, 0, 1271.635, 358.0313, 21.41639, 2.635444, 0, 0, 0.9681473, 0.2503814, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+69, 208540, 861, 0, 0, 1, 169, 0, 1262.526, 267.6597, 21.58265, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+70, 208543, 861, 0, 0, 1, 169, 0, 1255.965, 278.5504, 21.60331, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+71, 208540, 861, 0, 0, 1, 169, 0, 1277.163, 305.2865, 21.60974, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+72, 208551, 861, 0, 0, 1, 169, 0, 1264.012, 279.1597, -62.22378, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+73, 208551, 861, 0, 0, 1, 169, 0, 1235.068, 311.2639, -61.92418, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+74, 208540, 861, 0, 0, 1, 169, 0, 1285.891, 282.4479, 21.32485, 1.989672, 0, 0, 0.8386698, 0.5446402, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+75, 208540, 861, 0, 0, 1, 169, 0, 1288.389, 313.3368, 21.49362, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+76, 208543, 861, 0, 0, 1, 169, 0, 1270.089, 276.7344, 21.38225, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+77, 208544, 861, 0, 0, 1, 169, 0, 1270.089, 276.7344, 21.38225, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+78, 208541, 861, 0, 0, 1, 169, 0, 1291.28, 300.3924, 21.46335, 4.468043, 0, 0, -0.7880106, 0.6156617, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+79, 208540, 861, 0, 0, 1, 169, 0, 1318.863, 318.6962, 21.39287, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+80, 208540, 861, 0, 0, 1, 169, 0, 1305.576, 349.4983, 21.41405, 1.937312, 0, 0, 0.8241253, 0.5664076, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+81, 208541, 861, 0, 0, 1, 169, 0, 1323.901, 274.3611, 21.40743, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+82, 208374, 861, 0, 0, 1, 169, 0, 1279.791, 238.127, 1.315115, 4.380776, 0, 0, -0.8141155, 0.580703, 120, 255, 1, 15595), -- Doodad_StratholmeFloatingEmbers47 (Area: Ashen Fields - Difficulty: 0)
(@OGUID+83, 208541, 861, 0, 0, 1, 169, 0, 1316.377, 293.3906, 21.72006, 2.740162, 0, 0, 0.9799242, 0.1993704, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+84, 208592, 861, 0, 0, 1, 169, 0, 1214.05, 209.2049, 1.693483, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Reagent Pouch (Area: Ashen Fields - Difficulty: 0)
(@OGUID+85, 208551, 861, 0, 0, 1, 169, 0, 1278.325, 362.3767, -65.06773, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+86, 208544, 861, 0, 0, 1, 169, 0, 1336.094, 287.5295, 21.43216, 3.47321, 0, 0, -0.9862852, 0.1650499, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+87, 208551, 861, 0, 0, 1, 169, 0, 1332.455, 330.5972, -85.83827, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+88, 208551, 861, 0, 0, 1, 169, 0, 1337.382, 317.276, -90.35398, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+89, 208551, 861, 0, 0, 1, 169, 0, 1307.96, 275.6094, -65.15971, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+90, 208431, 861, 0, 0, 1, 169, 0, 1225.507, 205.1806, 65.13346, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Ashen Fields - Difficulty: 0)
(@OGUID+91, 208423, 861, 0, 0, 1, 169, 0, 1303.641, 215.8715, 63.13576, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Ashen Fields - Difficulty: 0)
(@OGUID+92, 208543, 861, 0, 0, 1, 169, 0, 1336.094, 287.5295, 21.43216, 3.47321, 0, 0, -0.9862852, 0.1650499, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+93, 208541, 861, 0, 0, 1, 169, 0, 1335.469, 328.6927, 21.29414, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+94, 208543, 861, 0, 0, 1, 169, 0, 1334.712, 342.7326, 21.72712, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Ashen Fields - Difficulty: 0)
(@OGUID+95, 208551, 861, 0, 0, 1, 169, 0, 1339.667, 340.5399, -91.79433, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Ashen Fields - Difficulty: 0)
(@OGUID+96, 208426, 861, 0, 0, 1, 169, 0, 1303.641, 215.8715, 63.13576, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac - Spiderling Trap (Area: Ashen Fields - Difficulty: 0)
(@OGUID+97, 208543, 861, 0, 0, 1, 169, 0, 1285.589, 397.4514, 21.55001, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+98, 208540, 861, 0, 0, 1, 169, 0, 1338.75, 362.3438, 21.86309, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+99, 208544, 861, 0, 0, 1, 169, 0, 1285.589, 397.4514, 21.55001, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+100, 208540, 861, 0, 0, 1, 169, 0, 1316.04, 385.7621, 21.50863, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+101, 208540, 861, 0, 0, 1, 169, 0, 1326.141, 370.9826, 21.4063, 2.932139, 0, 0, 0.9945211, 0.1045355, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+102, 208540, 861, 0, 0, 1, 169, 0, 1333.932, 408.9462, 21.37553, 4.118979, 0, 0, -0.882947, 0.4694727, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+103, 208541, 861, 0, 0, 1, 169, 0, 1292.759, 435.4705, 21.46152, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+104, 208540, 861, 0, 0, 1, 169, 0, 1351.295, 366.0191, 21.78085, 5.794494, 0, 0, -0.2419214, 0.9702958, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+105, 208540, 861, 0, 0, 1, 169, 0, 1350.061, 341.842, 21.32804, 1.797689, 0, 0, 0.782608, 0.6225148, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+106, 208540, 861, 0, 0, 1, 169, 0, 1338.469, 424.349, 21.42077, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+107, 208540, 861, 0, 0, 1, 169, 0, 1359.049, 398.3229, 21.32373, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+108, 208541, 861, 0, 0, 1, 169, 0, 1321.825, 422.5816, 21.3744, 4.24115, 0, 0, -0.8526402, 0.5224986, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+109, 208551, 861, 0, 0, 1, 169, 0, 1348.12, 356.1059, -93.22936, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+110, 208540, 861, 0, 0, 1, 169, 0, 1356.045, 443.6129, 21.48311, 3.595379, 0, 0, -0.97437, 0.2249513, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+111, 208540, 861, 0, 0, 1, 169, 0, 1358.366, 300.6597, 21.45538, 3.630291, 0, 0, -0.970295, 0.241925, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+112, 208551, 861, 0, 0, 1, 169, 0, 1345.806, 336.4722, -93.30862, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+113, 208551, 861, 0, 0, 1, 169, 0, 1313.021, 421.632, -66.88352, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+114, 208540, 861, 0, 0, 1, 169, 0, 1365.595, 291.8871, 21.38124, 4.97419, 0, 0, -0.6087608, 0.7933538, 120, 255, 1, 15595), -- Magmolia (Area: Magma Springs - Difficulty: 0)
(@OGUID+115, 208551, 861, 0, 0, 1, 169, 0, 1388.651, 287.1129, -93.54748, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+116, 208551, 861, 0, 0, 1, 169, 0, 1396.313, 294.6649, -93.54749, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+117, 208551, 861, 0, 0, 1, 169, 0, 1368.418, 282.4514, -92.90231, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+118, 208551, 861, 0, 0, 1, 169, 0, 1426.302, 302.3785, -93.54747, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+119, 208551, 861, 0, 0, 1, 169, 0, 1425.109, 360.6354, -93.46253, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+120, 208551, 861, 0, 0, 1, 169, 0, 1423.012, 363.6233, -93.43127, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+121, 208551, 861, 0, 0, 1, 169, 0, 1414.684, 376.3594, -93.53828, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+122, 208551, 861, 0, 0, 1, 169, 0, 1429.604, 367.1094, -93.03025, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+123, 208551, 861, 0, 0, 1, 169, 0, 1432.917, 368.6354, -92.71294, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+124, 208551, 861, 0, 0, 1, 169, 0, 1428.023, 347.934, -93.54749, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+125, 208431, 861, 0, 0, 1, 169, 0, 1384.826, 204.3229, 56.22684, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+126, 208431, 861, 0, 0, 1, 169, 0, 1363.802, 207.0035, 56.14547, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+127, 208431, 861, 0, 0, 1, 169, 0, 1359.167, 200.0573, 71.63898, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+128, 208431, 861, 0, 0, 1, 169, 0, 1371.62, 201.6354, 75.31632, 1.710422, 0, 0, 0.7547092, 0.6560594, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+129, 208431, 861, 0, 0, 1, 169, 0, 1335.988, 200.7326, 48.97005, 6.0912, 0, 0, -0.09584522, 0.9953963, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+130, 208426, 861, 0, 0, 1, 169, 0, 1374.635, 207.4826, 56.21738, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac - Spiderling Trap (Area: Magma Springs - Difficulty: 0)
(@OGUID+131, 208431, 861, 0, 0, 1, 169, 0, 1370.167, 202.0347, 75.31632, 3.211419, 0, 0, -0.9993906, 0.03490613, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+132, 208423, 861, 0, 0, 1, 169, 0, 1374.635, 207.4826, 56.21738, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+133, 208431, 861, 0, 0, 1, 169, 0, 1370.406, 188.5781, 72.27261, 4.956738, 0, 0, -0.6156607, 0.7880114, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+134, 208431, 861, 0, 0, 1, 169, 0, 1319.344, 192.7344, 49.1246, 4.450591, 0, 0, -0.7933531, 0.6087617, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+135, 208431, 861, 0, 0, 1, 169, 0, 1375.924, 196.8889, 78.68041, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+136, 208431, 861, 0, 0, 1, 169, 0, 1356.389, 192.6667, 66.5559, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+137, 208423, 861, 0, 0, 1, 169, 0, 1378.504, 192.4254, 63.85621, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+138, 208589, 861, 0, 0, 1, 169, 0, 1312.54, 215.316, 14.8863, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Spellbook (Area: Magma Springs - Difficulty: 0)
(@OGUID+139, 208431, 861, 0, 0, 1, 169, 0, 1383.444, 192.0156, 56.89549, 0.4537851, 0, 0, 0.2249508, 0.9743701, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+140, 208588, 861, 0, 0, 1, 169, 0, 1310.389, 197.1858, 14.33254, 2.513274, 0, 0, 0.9510565, 0.3090171, 120, 255, 1, 15595), -- Flame Druid Staff (Area: Magma Springs - Difficulty: 0)
(@OGUID+141, 208431, 861, 0, 0, 1, 169, 0, 1324.188, 195.5434, 48.90119, 3.316144, 0, 0, -0.9961939, 0.08716504, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+142, 208431, 861, 0, 0, 1, 169, 0, 1330.884, 197.4896, 48.90089, 3.316144, 0, 0, -0.9961939, 0.08716504, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+143, 208592, 861, 0, 0, 1, 169, 0, 1318.748, 215.0417, 15.0395, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Flame Druid Reagent Pouch (Area: Magma Springs - Difficulty: 0)
(@OGUID+144, 208426, 861, 0, 0, 1, 169, 0, 1378.504, 192.4254, 63.85621, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac - Spiderling Trap (Area: Magma Springs - Difficulty: 0)
(@OGUID+145, 208431, 861, 0, 0, 1, 169, 0, 1365.939, 191.3941, 71.97045, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+146, 208431, 861, 0, 0, 1, 169, 0, 1370.516, 187.2309, 72.29803, 5.93412, 0, 0, -0.1736479, 0.9848078, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+147, 208370, 861, 0, 0, 1, 169, 0, 1295.778, 178.0465, 1.529634, 3.874631, 0, 0, -0.9335804, 0.358368, 120, 255, 1, 15595), -- Doodad_StratholmeFloatingEmbers41 (Area: Magma Springs - Difficulty: 0)
(@OGUID+148, 208431, 861, 0, 0, 1, 169, 0, 1335.769, 164.0295, 48.89979, 3.857183, 0, 0, -0.9366713, 0.3502098, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+149, 208431, 861, 0, 0, 1, 169, 0, 1306.601, 160.9097, 60.01364, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+150, 208431, 861, 0, 0, 1, 169, 0, 1390.208, 152.6024, 87.31174, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+151, 208431, 861, 0, 0, 1, 169, 0, 1321.196, 159.6267, 48.90133, 3.019413, 0, 0, 0.9981346, 0.06105176, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+152, 208431, 861, 0, 0, 1, 169, 0, 1279.943, 158.8194, 59.45721, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+153, 208431, 861, 0, 0, 1, 169, 0, 1394.255, 150.2656, 81.47406, 3.857183, 0, 0, -0.9366713, 0.3502098, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+154, 208431, 861, 0, 0, 1, 169, 0, 1391.569, 152.658, 87.23801, 1.884953, 0, 0, 0.8090162, 0.5877863, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: Magma Springs - Difficulty: 0)
(@OGUID+155, 208593, 861, 0, 0, 1, 169, 0, 1302.613, 163.3385, 5.783576, 1.012289, 0, 0, 0.4848089, 0.8746201, 120, 255, 1, 15595), -- Flame Druid Idol (Area: Magma Springs - Difficulty: 0)
(@OGUID+156, 208431, 861, 0, 0, 1, 169, 0, 1328.792, 119.0799, 62.40609, 4.310966, 0, 0, -0.8338852, 0.5519379, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+157, 208431, 861, 0, 0, 1, 169, 0, 1341.184, 129.5347, 61.86413, 4.118979, 0, 0, -0.882947, 0.4694727, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+158, 208431, 861, 0, 0, 1, 169, 0, 1329.835, 121.1476, 62.43651, 1.658062, 0, 0, 0.737277, 0.6755905, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+159, 208426, 861, 0, 0, 1, 169, 0, 1332.417, 126.6997, 70.16744, 2.82743, 0, 0, 0.9876881, 0.1564362, 120, 255, 1, 15595), -- Cinderweb Egg Sac - Spiderling Trap (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+160, 208431, 861, 0, 0, 1, 169, 0, 1348.132, 125.7517, 62.39841, 2.216565, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+161, 208431, 861, 0, 0, 1, 169, 0, 1332.964, 122.7101, 81.92757, 0.4014249, 0, 0, 0.1993675, 0.9799248, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+162, 208431, 861, 0, 0, 1, 169, 0, 1329.929, 119.8385, 62.42866, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+163, 208431, 861, 0, 0, 1, 169, 0, 1336.109, 125.1215, 82.18307, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+164, 208431, 861, 0, 0, 1, 169, 0, 1277.604, 153.0903, 75.36688, 0.157079, 0, 0, 0.07845879, 0.9969174, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+165, 208431, 861, 0, 0, 1, 169, 0, 1342.609, 115.2274, 62.40245, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+166, 208423, 861, 0, 0, 1, 169, 0, 1332.417, 126.6997, 70.16744, 2.82743, 0, 0, 0.9876881, 0.1564362, 120, 255, 1, 15595), -- Cinderweb Egg Sac (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+167, 208373, 861, 0, 0, 1, 169, 0, 1305.741, 140.851, 1.315115, 2.487093, 0, 0, 0.9469299, 0.32144, 120, 255, 1, 15595), -- Doodad_StratholmeFloatingEmbers48 (Area: The Widow's Clutch - Difficulty: 0)
(@OGUID+168, 208551, 861, 0, 0, 1, 169, 0, 1201.486, 315.5851, -40.06277, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Lucifern (Area: Magma Springs - Difficulty: 0)
(@OGUID+169, 208630, 861, 0, 0, 1, 169, 0, 1368.25, 645.5, 133.5969, 0.5759573, 0, 0, 0.2840147, 0.9588199, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+170, 208630, 861, 0, 0, 1, 169, 0, 1374.446, 645.059, 133.3709, 4.206246, 0, 0, -0.8616285, 0.5075394, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+171, 208630, 861, 0, 0, 1, 169, 0, 1365.889, 651.2604, 134.417, 3.47321, 0, 0, -0.9862852, 0.1650499, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+172, 208630, 861, 0, 0, 1, 169, 0, 1364.78, 646.1042, 133.4029, 0.3316107, 0, 0, 0.1650467, 0.9862857, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+173, 208630, 861, 0, 0, 1, 169, 0, 1365.422, 649.8611, 134.2038, 1.884953, 0, 0, 0.8090162, 0.5877863, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+174, 208630, 861, 0, 0, 1, 169, 0, 1363.845, 646.9011, 133.5004, 6.213374, 0, 0, -0.03489876, 0.9993908, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+175, 208630, 861, 0, 0, 1, 169, 0, 1373.667, 645.7917, 133.3206, 5.323256, 0, 0, -0.4617481, 0.8870111, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+176, 208630, 861, 0, 0, 1, 169, 0, 1373.385, 644.8785, 133.4334, 0.5934101, 0, 0, 0.2923708, 0.956305, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+177, 208630, 861, 0, 0, 1, 169, 0, 1370.438, 658.4705, 133.3579, 2.408554, 0, 0, 0.9335804, 0.358368, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+178, 208630, 861, 0, 0, 1, 169, 0, 1378.163, 645.3594, 133.7084, 3.490667, 0, 0, -0.984807, 0.1736523, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+179, 208630, 861, 0, 0, 1, 169, 0, 1378.252, 651.5764, 133.5032, 0.8203033, 0, 0, 0.3987484, 0.9170604, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+180, 208630, 861, 0, 0, 1, 169, 0, 1379.661, 646.4323, 133.539, 6.0912, 0, 0, -0.09584522, 0.9953963, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+181, 208630, 861, 0, 0, 1, 169, 0, 1372.526, 659.2621, 133.5942, 4.310966, 0, 0, -0.8338852, 0.5519379, 120, 255, 1, 32638), -- Fire Hawk Egg (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+182, 208803, 861, 0, 0, 1, 169, 0, 1448.747, 640.4843, 104.0646, 3.401946, 0, 0, -0.991539, 0.1298091, 120, 255, 1, 32638), -- Living Obsidium Chip (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+183, 208802, 861, 0, 0, 1, 169, 0, 1444.853, 632.2931, 104.3084, 3.401946, 0, 0, -0.991539, 0.1298091, 120, 255, 1, 32638), -- Living Obsidium Chip (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+184, 208803, 861, 0, 0, 1, 169, 0, 1443.39, 627.9875, 104.1834, 3.401946, 0, 0, -0.991539, 0.1298091, 120, 255, 1, 32638), -- Living Obsidium Chip (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+185, 208802, 861, 0, 0, 1, 169, 0, 1459.152, 645.1588, 104.0646, 3.401946, 0, 0, -0.991539, 0.1298091, 120, 255, 1, 32638), -- Living Obsidium Chip (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+186, 208802, 861, 0, 0, 1, 169, 0, 1444.955, 625.3069, 104.0584, 3.401946, 0, 0, -0.991539, 0.1298091, 120, 255, 1, 32638), -- Living Obsidium Chip (Area: Fireplume Peak - Difficulty: 0)
(@OGUID+187, 209278, 861, 0, 0, 1, 169, 0, 1023.075, 415.6441, 42.217, 0.01064305, 0, 0, 0.005321503, 0.9999858, 120, 255, 1, 32638); -- Pre Moonwell (Area: Igneous Depths - Difficulty: 0)


DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+168;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+82, 0, 0, 0.01745239, 0.9998477), -- Doodad_StratholmeFloatingEmbers47
(@OGUID+147, 0, 0, 0.01745239, 0.9998477), -- Doodad_StratholmeFloatingEmbers41
(@OGUID+167, 0, 0, 0.01745239, 0.9998477); -- Doodad_StratholmeFloatingEmbers48

-- Spell area data
DELETE FROM `spell_area` WHERE `area` IN (5733, 5738, 5745);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `flags`) VALUES
(98549, 5733, 2, 3), -- See Quest Invis 14
(98513, 5733, 2, 3), -- See Quest Invis 13
(98071, 5733, 2, 3), -- See Quest Invis 18
(99040, 5738, 2, 3), -- See Quest Invis 9
(99040, 5745, 2, 3), -- See Quest Invis 9
(98413, 5733, 2, 3); -- (Serverside/Non-DB2) See Quest Invis 22

UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (208600, 208601, 208599, 208337);
SET @ENTRY := (@OGUID+9) * -1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 60, 0, 100, 0, 31000, 31000, 31000, 31000, 93, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 31000 and 31000 ms) - Self: Play custom animation (only gameobject) // "),
(@ENTRY, 1, 1, 0, 60, 0, 100, 0, 39000, 39000, 31000, 31000, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 39000 and 39000 ms) - Self: Activate (only gameobject) // "),
(@ENTRY, 1, 2, 0, 60, 0, 100, 0, 52000, 52000, 31000, 31000, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 52000 and 52000 ms) - Self: Reset (gameobject) // ");

SET @ENTRY := (@OGUID+45) * -1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 60, 0, 100, 0, 31000, 31000, 31000, 31000, 93, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 31000 and 31000 ms) - Self: Play custom animation (only gameobject) // "),
(@ENTRY, 1, 1, 0, 60, 0, 100, 0, 39000, 39000, 31000, 31000, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 39000 and 39000 ms) - Self: Activate (only gameobject) // "),
(@ENTRY, 1, 2, 0, 60, 0, 100, 0, 52000, 52000, 31000, 31000, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 52000 and 52000 ms) - Self: Reset (gameobject) // ");

SET @ENTRY := (@OGUID+56) * -1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 60, 0, 100, 0, 31000, 31000, 31000, 31000, 93, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 31000 and 31000 ms) - Self: Play custom animation (only gameobject) // "),
(@ENTRY, 1, 1, 0, 60, 0, 100, 0, 39000, 39000, 31000, 31000, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 39000 and 39000 ms) - Self: Activate (only gameobject) // "),
(@ENTRY, 1, 2, 0, 60, 0, 100, 0, 52000, 52000, 31000, 31000, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 52000 and 52000 ms) - Self: Reset (gameobject) // ");

SET @ENTRY := (@OGUID+55) * -1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 60, 0, 100, 0, 31000, 31000, 31000, 31000, 93, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 31000 and 31000 ms) - Self: Play custom animation (only gameobject) // "),
(@ENTRY, 1, 1, 0, 60, 0, 100, 0, 39000, 39000, 31000, 31000, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 39000 and 39000 ms) - Self: Activate (only gameobject) // "),
(@ENTRY, 1, 2, 0, 60, 0, 100, 0, 52000, 52000, 31000, 31000, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 52000 and 52000 ms) - Self: Reset (gameobject) // ");

SET @ENTRY := (@OGUID+19) * -1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 60, 0, 100, 0, 31000, 31000, 31000, 31000, 93, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 31000 and 31000 ms) - Self: Play custom animation (only gameobject) // "),
(@ENTRY, 1, 1, 0, 60, 0, 100, 0, 39000, 39000, 31000, 31000, 9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 39000 and 39000 ms) - Self: Activate (only gameobject) // "),
(@ENTRY, 1, 2, 0, 60, 0, 100, 0, 52000, 52000, 31000, 31000, 32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 31000 and 31000 ms (for the first time, timer between 52000 and 52000 ms) - Self: Reset (gameobject) // ");

-- Visibilities
UPDATE `creature_template_addon` SET `visibilityDistanceType`= 3 WHERE `entry` IN (52531, 53245, 53249, 53212, 52948, 53212, 54040, 54036, 54037);
UPDATE `creature_template_addon` SET `visibilityDistanceType`= 5 WHERE `entry`= 54421;
