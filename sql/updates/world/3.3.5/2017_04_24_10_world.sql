-- 
SET @GUID := 131324;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID + 1 AND @GUID + 23;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `npcflag`, `MovementType`) VALUES 
(@GUID + 1, 11277, 0, 0, 0, 1093.95, -2528.63, 61.2475, 5.74213, 0, 0, 0, 484, 0, 0, 0),
(@GUID + 2, 11277, 0, 0, 0, 1095.56, -2529.47, 61.1291, 2.37365, 0, 0, 0, 484, 0, 0, 0),
(@GUID + 3, 11277, 0, 0, 0, 1148.08, -2559.31, 60.1493, 4.15388, 0, 0, 0, 484, 0, 0, 0),
(@GUID + 4, 11277, 0, 0, 0, 1146.79, -2561.22, 60.1145, 0.959931, 0, 0, 0, 484, 0, 0, 0),
(@GUID + 5, 11279, 0, 0, 0, 1064.06, -2519.78, 60.2259, 3.19395, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 6, 11279, 0, 0, 0, 1056.5, -2536.54, 59.9694, 2.35619, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 7, 11279, 0, 0, 0, 1245.02, -2597.47, 90.3675, 3.52556, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 8, 11280, 0, 0, 0, 1180.07, -2536.72, 85.3681, 1.0821, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 9, 11280, 0, 0, 0, 1187.12, -2532.58, 85.3681, 2.16421, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 10, 11280, 0, 0, 0, 1208.19, -2583.32, 98.2479, 2.72271, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 11, 11282, 0, 0, 0, 1113.59, -2555.59, 59.2532, 3.50681, 0, 0, 0, 42, 0, 0, 0),
(@GUID + 12, 11283, 0, 0, 0, 1111.49, -2556.4, 59.2532, 0.365222, 0, 0, 0, 42, 0, 0, 0),
(@GUID + 13, 11316, 0, 0, 0, 1223.27, -2506.41, 72.9261, 4.10152, 0, 0, 0, 3500, 0, 0, 0),
(@GUID + 14, 11277, 0, 0, 0, 1155.4, -2383.73, 60.304, 5.43574, 300, 0, 0, 2784, 0, 0, 0),
(@GUID + 15, 11281, 0, 0, 0, 1098.49, -2523.82, 61.3707, 4.6691, 1272, 0, 0, 2371, 0, 0, 0),
(@GUID + 16, 11281, 0, 0, 0, 1031.16, -2498.27, 59.177, 4.73616, 1272, 0, 0, 2371, 0, 0, 2),
(@GUID + 17, 11281, 0, 0, 0, 1090.52, -2541.25, 59.2419, 2.70896, 1272, 0, 0, 2371, 0, 0, 2),
(@GUID + 18, 11279, 0, 0, 0, 1238.9929, -2586.8103, 90.3722, 3.695799, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 19, 11277, 0, 0, 0, 1100.1054, -2589.2932, 60.624, 0.555778, 0, 0, 0, 3632, 0, 0, 0),
(@GUID + 20, 11277, 0, 0, 0, 1127.81, -2387.71, 59.264, 1.72159, 300, 0, 0, 2784, 0, 0, 0),
(@GUID + 21, 11287, 0, 0, 0, 1081.91, -2574, 59.957, 0.301, 360, 0, 0, 1536, 0, 0, 0),
(@GUID + 22, 11277, 0, 11014, 0, 1090.52, -2541.25, 59.2419, 2.70896, 1272, 0, 0, 2784, 0, 0, 2),
(@GUID + 23, 11277, 0, 11014, 0, 1231.62939, -2558.7126, 91.04164, 4.410, 1272, 0, 0, 2784, 0, 0, 2);

SET @NPC := 131340;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,5228,0,1,0, '17622');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 1031.16, -2498.27, 59.177, 10000),
(@PATH, 2, 1034.48, -2468.77, 59.9844, 0),
(@PATH, 3, 1043.48, -2458.4, 60.4699, 0),
(@PATH, 4, 1071.23, -2443.23, 61.1634, 5000),
(@PATH, 5, 1101.41, -2409.45, 59.8655, 0),
(@PATH, 6, 1125.81, -2397.36, 59.4695, 0),
(@PATH, 7, 1183.61, -2397.16, 60.1768, 10000),
(@PATH, 8, 1126.2, -2397.42, 59.4867, 0),
(@PATH, 9, 1101.19, -2409.67, 59.8831, 0),
(@PATH, 10, 1070.91, -2443.54, 61.1405, 5000),
(@PATH, 11, 1043.16, -2458.72, 60.4674, 0),
(@PATH, 12, 1034.42, -2468.71, 59.9897, 0);

SET @NPC := 131341;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,5228,0,1,0, '17622');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 1090.52, -2541.25, 59.1419, 10000),
(@PATH, 2, 1095.36, -2543.49, 59.1418, 0),
(@PATH, 3, 1118.02, -2601.04, 59.4689, 0),
(@PATH, 4, 1132.05, -2612.48, 63.1381, 0),
(@PATH, 5, 1161.32, -2620.66, 70.9007, 0),
(@PATH, 6, 1193.38, -2629.62, 74.0911, 0),
(@PATH, 7, 1214.63, -2616.73, 83.1397, 0),
(@PATH, 8, 1221.01, -2604.11, 86.3537, 0),
(@PATH, 9, 1237.11, -2595.52, 90.1566, 10000),
(@PATH, 10, 1221.38, -2603.91, 86.4882, 0),
(@PATH, 11, 1214.67, -2616.99, 83.1357, 0),
(@PATH, 12, 1193.52, -2629.6, 74.1169, 0),
(@PATH, 13, 1161.14, -2620.61, 70.8684, 0),
(@PATH, 14, 1131.64, -2612.35, 63.038, 0),
(@PATH, 15, 1117.74, -2600.92, 59.4468, 0),
(@PATH, 16, 1095.2, -2543.02, 59.1423, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (131341);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(131341,131341,0,0,2,0,0),
(131341,131339,9,360,2,9,19);

SET @NPC := @GUID + 23;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '17622 10848');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1235.24, -2562.57, 91.3431, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 2, 1236.63, -2570.77, 91.5426, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 3, 1237.19, -2580.81, 90.9381, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 4, 1238.05, -2593.67, 90.1927, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 5, 1228.63, -2599.66, 88.6386, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 6, 1220.7, -2604.7, 86.2027, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 7, 1212.85, -2601.35, 83.4549, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 8, 1201.85, -2595.01, 78.5496, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 9, 1191.01, -2590.97, 74.6417, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 10, 1180.71, -2595.16, 72.9315, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 11, 1176.2, -2606.29, 72.8323, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 12, 1168.01, -2620.18, 71.895, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 13, 1173.01, -2612.22, 72.7501, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 14, 1182.33, -2592.46, 72.9574, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 15, 1197.4, -2592.45, 76.7622, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 16, 1219.52, -2604.41, 85.8084, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 17, 1237.83, -2592.45, 90.193, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 18, 1237.96, -2574.51, 91.5436, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 19, 1233.04, -2561.64, 90.6976, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 20, 1232.37, -2553.62, 91.4351, 0, 0, 0, 0, 100, 0);

SET @NPC := 131346; 
UPDATE `creature` SET `position_x`=1127.81, `position_y`=-2387.71, `position_z`=59.264, `orientation`=1.72159 WHERE  `guid`=@NPC;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '17622 10848');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 1130.21, -2395.8, 59.6262, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 2, 1137.21, -2395.91, 59.8531, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 3, 1158.21, -2396.22, 59.8991, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 4, 1179.21, -2396.51, 60.0552, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 5, 1203.92, -2392.72, 60.0587, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 6, 1190.1, -2394.95, 60.1484, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 7, 1169.22, -2396.95, 59.9472, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 8, 1155.23, -2396.77, 59.9844, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 9, 1124.17, -2397.18, 59.405, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 10, 1099.73, -2410.8, 59.9901, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 11, 1090.4, -2420.13, 60.9123, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 12, 1072.48, -2441.64, 61.2209, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 13, 1043.13, -2458.38, 60.4831, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 14, 1035.92, -2468.81, 59.9447, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 15, 1032.07, -2486.29, 59.3631, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 16, 1024.47, -2514.34, 59.1417, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 17, 1037.54, -2519.32, 59.1867, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 18, 1063.46, -2529.89, 59.1418, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 19, 1097.75, -2544.71, 59.1428, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 20, 1102.49, -2557.88, 59.1428, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 21, 1111.76, -2584.3, 59.1743, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 22, 1123.54, -2607.25, 61.0399, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 23, 1136.36, -2612.87, 64.1442, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 24, 1163.16, -2620.89, 71.2108, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 25, 1182.45, -2627.27, 72.8355, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 26, 1196.35, -2625.69, 74.9546, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 27, 1205.57, -2623.11, 78.4216, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 28, 1218.12, -2611.44, 84.922, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 29, 1232.4, -2596.93, 89.4579, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 30, 1218.97, -2605.37, 85.534, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 31, 1207.03, -2598.07, 80.8431, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 32, 1184.18, -2591.84, 73.0826, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 33, 1180.16, -2598.08, 72.8645, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 34, 1167.55, -2620.42, 71.8289, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 35, 1148.76, -2617.4, 67.9948, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 36, 1128.96, -2610.55, 62.3378, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 37, 1114.88, -2592.68, 59.2346, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 38, 1112, -2586.3, 59.1568, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 39, 1102.92, -2559.83, 59.142, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 40, 1093.84, -2542.81, 59.1414, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 41, 1067.78, -2532.62, 59.1415, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 42, 1035.69, -2518.67, 59.1449, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 43, 1022.34, -2513.6, 59.1417, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 44, 1029.52, -2499.31, 59.1618, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 45, 1032.82, -2480.03, 59.4609, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 46, 1040.28, -2461.78, 60.4131, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 47, 1068.44, -2444.34, 60.9293, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 48, 1089.28, -2422.64, 61.0531, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 49, 1110.43, -2404.84, 59.3954, 0, 0, 0, 0, 100, 0),                                                               
(@PATH, 50, 1125.89, -2397.4, 59.473, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template_addon` SET `mount` = 5228 WHERE `entry` = 11281;

DELETE FROM `creature_template_addon` WHERE `entry` IN (11282, 11283, 11287, 11279, 11286, 11316, 11280);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(11282, 0, 0, 0, 0, 0, '17622 10848'),
(11283, 0, 0, 0, 0, 0, '17622 10848'),
(11287, 0, 0, 0, 0, 0, '17622 10848'),
(11279, 0, 0, 0, 0, 0, '17622 10848'),
(11286, 0, 0, 0, 0, 0, '17622 10848'),
(11316, 0, 0, 0, 69, 0, '17622 10848'),
(11280, 0, 0, 0, 69, 0, '17622 10848');

UPDATE `creature_template_addon` SET `auras` = '17622 10848' WHERE `entry` = 11277;
UPDATE `creature_addon` SET `bytes1`=0, `auras` = '17622 10848' WHERE `guid` = 200140;

-- Melia SAI
SET @ENTRY := 11282;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,1,11282,1,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,5,11282,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Waypoint 5 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1128200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.495,"Melia - On Script - Set Orientation 3.495"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,1,0,2000,0,0,0,0,19,11283,100,0,0,0,0,0,"Melia - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,14000,14000,0,0,1,2,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Melia - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,1000,1000,0,0,1,1,2000,0,0,0,0,19,11283,100,0,0,0,0,0,"Melia - On Script - Say Line 1");

-- Sammy SAI
SET @ENTRY := 11283;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,1,11283,1,0,0,0,1,0,0,0,0,0,0,0,"Sammy - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,5,11283,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sammy - On Waypoint 5 Reached - Pause Waypoint");

DELETE FROM `creature_text` WHERE `entry` IN (11282, 11283);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(11282, 0, 0, 'I win!', 12, 0, 100, 0, 2000, 0, 6808, 'Melia'),
(11282, 1, 0, 'Wanna race again? Best two out of three!', 12, 0, 100, 0, 2000, 0, 6809, 'Melia'),
(11282, 2, 0, 'Ready. Set. GO!', 12, 0, 100, 0, 2000, 0, 6806, 'Melia'),
(11283, 0, 0, 'You cheated!', 12, 0, 100, 0, 2000, 0, 6810, 'Sammy'),
(11283, 1, 0, 'HEY! No fair!', 12, 0, 100, 0, 2000, 0, 6807, 'Sammy');

DELETE FROM `waypoints` WHERE `entry` IN (11282, 11283);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(11282, 1, 1120.09, -2547.57, 59.2532, 'Melia'),
(11282, 2, 1111.05, -2537.9, 59.2532, 'Melia'),
(11282, 3, 1100.43, -2547.73, 59.2532, 'Melia'),
(11282, 4, 1109.6, -2558.2, 59.2532, 'Melia'),
(11282, 5, 1113.59, -2555.59, 59.2532, 'Melia'),
(11282, 6, 1113.59, -2555.59, 59.2532, 'Melia'),
(11283, 1, 1120.72, -2548.21, 59.2532, 'Sammy'),
(11283, 2, 1110.95, -2538.51, 59.2532, 'Sammy'),
(11283, 3, 1100.73, -2547.23, 59.2532, 'Sammy'),
(11283, 4, 1109.56, -2557.59, 59.2532, 'Sammy'),
(11283, 5, 1111.49, -2556.4, 59.2532, 'Sammy'),
(11283, 6, 1111.49, -2556.4, 59.2532, 'Sammy');
