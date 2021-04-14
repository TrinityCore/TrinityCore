-- [NPC][WotlK] Stormpeak Wyrm and Stormpeak Hatchling, missing spawn loc/paths 
SET @CGUID     := 77906;
SET @STARTGUID := 77906; -- same as @CGUID NEEDED for pathing count
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+30;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6702.472, -1717.436, 1017.982, 3.461327, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6584.669, -1863.858, 1124.625, 1.053664, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6606.026, -1891.246, 1124.73, 1.646154, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6624.332, -1906.393, 1124.682, 3.227196, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6654.758, -1880.619, 1129.904, 1.774444, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6647.856, -1868.564, 1130.787, 3.21784, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6663.677, -1849.586, 1137.775, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6702.392, -1787.708, 1241.829, 3.389814, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6623.111, -1881.081, 1126.43, 0.7088594, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6592.55, -1937.618, 1141.2, 5.359461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6706.382, -1858.719, 1171.235, 4.301496, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6659.203, -1907.712, 1198.667, 1.739203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6641.829, -1902.576, 1127.733, 5.402813, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6703.102, -1881.274, 1174.934, 2.311058, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6653.121, -1945.861, 1092.432, 0.8252114, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6738.855, -1768.719, 1050.008, 3.132955, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6627.002, -1934.763, 1095.329, 4.835973, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6742.735, -1892.179, 1170.546, 0.3574165, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6609.623, -1944.848, 1098.387, 2.28892, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6719.074, -1874.407, 1174.091, 2.4817, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6709.758, -1905.579, 1173.996, 4.177607, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6635.503, -1958.078, 1092.354, 5.541065, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6727.401, -1891.871, 1172.438, 0.2411875, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6657.97, -1966.302, 1092.598, 0.2578183, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6725.333, -1919.483, 1174.418, 1.603005, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29755, 571, 0, 0, '0', 0, 0, 0, 6759.403, -1872.74, 1165.541, 0.2627409, 120, 10, 0, 0, 0, 1, 0, 0, 0, 23360), -- Stormpeak Hatchling (Area: -Unknown-) (Auras: 55474 - Cosmetic - Sleep Zzz) (possible waypoints or random movement)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6714.704, -1939.753, 1178.629, 4.415683, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: -Unknown-)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6739.319, -2010.099, 1001.349, 3.309717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: Dragonspine Peaks)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6579.054, -1990.699, 1001.39, 2.154689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Stormpeak Wyrm (Area: Dragonspine Peaks)
((@CGUID := @CGUID + 1), 29753, 571, 0, 0, '0', 0, 0, 0, 6719.48, -2017.726, 1084.87, 3.389115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Stormpeak Wyrm (Area: Dragonspine Peaks)

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=29753;

SET @NPC := @STARTGUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6664.07, -1734.11, 1014.73, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6593.72, -1787.24, 1005.44, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6555.17, -1855.48, 999.627, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6544.82, -1932.54, 994.279, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6570.23, -2001.89, 989.825, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6642.51, -2028.4, 988.566, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6714.3, -2019.07, 992.488, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6807.61, -1984.05, 1001.25, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6879.51, -1926.31, 1008.88, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6910.83, -1838.63, 1014.48, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6838.5, -1791.28, 1017.8, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6776.07, -1765.69, 1020.64, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6623.41, -1827.2, 1124.49, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6690.06, -1793.75, 1126.43, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6765.92, -1809.18, 1128.83, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6843.11, -1852.82, 1132.01, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6868.63, -1910.23, 1134.35, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6827.05, -1947.56, 1137.96, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6744.83, -1990.75, 1142.39, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6661.92, -1989.16, 1150.07, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6611.29, -1952.89, 1143.81, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6576.13, -1901.62, 1135.17, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6648.75, -1820.89, 1239.4, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6612.79, -1880.13, 1216.25, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6626.44, -1972.88, 1198.35, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6696.29, -2006.6, 1186.58, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6768.9, -1975.57, 1183.6, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6814.09, -1914.58, 1181.51, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6821.88, -1830.42, 1192.73, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6772.17, -1782.08, 1210.37, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6727.59, -1779.75, 1222.19, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6559.05, -1917.65, 1139.79, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6563.95, -1859.65, 1141.79, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6596.99, -1823.85, 1139.46, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6659.41, -1782.94, 1138.3, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6743.22, -1783.55, 1137.88, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6819.72, -1823.24, 1136.66, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6863.88, -1893.62, 1137.74, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6837.98, -1963.16, 1139.45, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6777.24, -1992.62, 1141.84, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6701.15, -2004.17, 1138.72, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6634.47, -1983.39, 1137.37, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6595.44, -1943.42, 1140.54, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+12;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6663.83, -1880.47, 1193.37, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6681.71, -1835.25, 1186.42, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6724.54, -1800.8, 1181.59, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6789.73, -1825.07, 1185.46, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6824.47, -1883.24, 1191.69, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6796.86, -1944.61, 1197.32, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6747.05, -1970.08, 1199.45, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6699.25, -1980.81, 1201.23, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6663.67, -1963.75, 1200.66, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6654.2, -1925.16, 1199.25, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+16;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6706.17, -1767.35, 1048.7, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6659.79, -1770.09, 1045.76, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6596.15, -1803.66, 1040.4, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6551.15, -1860.84, 1035.17, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6544.47, -1936.37, 1031.49, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6570.64, -2007.34, 1027.26, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6639.43, -2034.93, 1025.13, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6720.01, -2028.1, 1024.55, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6809.4, -1994.39, 1024.95, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6875.24, -1939.19, 1025.57, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6894.75, -1868.78, 1025.61, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6851.48, -1811.2, 1026.28, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 6790.69, -1777.88, 1035.32, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+28;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6761.82, -2003.27, 1001.86, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6866.07, -1952.84, 1000.4, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6905.48, -1882.59, 997.332, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6877.42, -1818.47, 992.867, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6808.45, -1763.34, 985.68, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6713.76, -1719.05, 976.127, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6625.2, -1715.7, 962.356, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6557.86, -1794.87, 947.555, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6534.37, -1877.36, 940.603, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6551.02, -1976.4, 941.838, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6618.87, -2023.64, 952.617, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6693.76, -2023.46, 968.826, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 6747.23, -2007.64, 997.992, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+29;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6560.91, -1970.01, 995.594, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6531.29, -1910.65, 986.135, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6534.96, -1823.19, 974.145, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6578.82, -1744.33, 961.861, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6650.2, -1702.88, 951.805, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6734.1, -1721.55, 953.691, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6823.63, -1759.25, 961.591, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6889.71, -1827.3, 970.154, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6917.85, -1924.46, 979.394, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6869.09, -1994.21, 986.278, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6790.42, -2019.82, 1001.1, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6707.89, -2031.19, 1002.5, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 6633.6, -2025.72, 1000.73, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

SET @NPC := @STARTGUID+30;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 6794.45, -1975.59, 1085.44, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 6865.38, -1912.3, 1080.59, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 6883.89, -1839.89, 1078.57, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 6825.73, -1782.05, 1076.21, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 6746.68, -1756.41, 1080.96, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 6666.52, -1775.16, 1087.72, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 6581.76, -1819.17, 1091.91, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 6550.79, -1887.92, 1092.18, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 6561.05, -1964.98, 1092.69, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 6620.37, -2023.02, 1091.4, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 6687.27, -2033.47, 1086.79, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 6717.19, -2020.14, 1086.59, 0, 0, 0, 0, 100, 0);

UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`= @PATH;

-- Stormpeak Hatchling
UPDATE `creature` SET `modelid`=26726, `spawndist`=4, `curhealth`=3150, `MovementType`=1 WHERE  `id`=29755;
-- idivisual correction
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (@STARTGUID+4);

-- Stormpeak Hatchling SAI
SET @ENTRY := 29755;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,61554,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpeak Hatchling - In Combat - Cast 'Wing Smash'"),
(@ENTRY,0,1,0,1,0,100,0,20000,90000,180000,180000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - Out of Combat - Run Script"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Aggro - Set Rooted Off"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,55474,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Aggro - Remove Aura 'Cosmetic - Sleep Zzz'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Remove Flag Standstate Sleep");

-- Actionlist SAI
SET @ENTRY := 2975500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Set Rooted On"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,11,55474,2,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Cast 'Cosmetic - Sleep Zzz'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Set Flag Standstate Sleep"),
(@ENTRY,9,4,0,0,0,100,0,60000,60000,0,0,28,55474,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Remove Aura 'Cosmetic - Sleep Zzz'"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Set Rooted Off"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Remove Flag Standstate Sleep"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormpeak Hatchling - On Script - Set Active Off");
