-- Theradrim Shardling SAI
SET @ENTRY := 11783;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,50,0,0,5,7000,11000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theradrim Shardling - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,29,2,90,0,0,0,0,19,11784,10,0,0,0,0,0,"Theradrim Shardling - On Just Summoned - Start Follow Closest Creature 'Theradrim Guardian'");

-- Theradrim Guardian SAI
SET @ENTRY := 11784;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7000,12000,11,16790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Theradrim Guardian - Within 0-5 Range - Cast 'Knockdown' (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,21057,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theradrim Guardian - Out of Combat - Cast 'Summon Theradrim Shardling' (No Repeat) (Normal Dungeon)");

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55465;
DELETE FROM `creature_addon` WHERE `guid`=55465;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55465, 554650, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=554650;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(554650, 1, 248.538, -93.024, -129.62, 0, 0, 0, 0, 100, 0),
(554650, 2, 219.021, -92.1171, -129.607, 0, 0, 0, 0, 100, 0),
(554650, 3, 258.14, -97.1733, -129.619, 0, 0, 0, 0, 100, 0),
(554650, 4, 246.967, -145.304, -130.844, 0, 0, 0, 0, 100, 0),
(554650, 5, 213.934, -199.873, -131.159, 0, 0, 0, 0, 100, 0),
(554650, 6, 248.627, -140.739, -131.005, 0, 0, 0, 0, 100, 0),
(554650, 7, 259.8, -98.2245, -129.619, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature` WHERE `guid` IN (55466, 56518, 56516, 56517, 56504, 56502, 56505, 56503, 56488, 56487, 56486, 88993, 88991, 88990, 88992, 56343, 56341, 55472);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55471;
DELETE FROM `creature_addon` WHERE `guid`=55471;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55471, 554710, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=554710;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(554710, 1, 200.354, -133.505, -101.058, 0, 0, 0, 0, 100, 0),
(554710, 2, 230.841, -109.688, -88.8687, 0, 0, 0, 0, 100, 0),
(554710, 3, 278.173, -121.002, -83.4807, 0, 0, 0, 0, 100, 0),
(554710, 4, 300.187, -149.075, -69.7502, 0, 0, 0, 0, 100, 0),
(554710, 5, 298.76, -178.312, -59.8991, 0, 0, 0, 0, 100, 0),
(554710, 6, 299.577, -148.794, -69.9433, 0, 0, 0, 0, 100, 0),
(554710, 7, 276.408, -121.048, -83.6496, 0, 0, 0, 0, 100, 0),
(554710, 8, 226.955, -112.811, -89.7437, 0, 0, 0, 0, 100, 0),
(554710, 9, 199.686, -134.684, -101.541, 0, 0, 0, 0, 100, 0),
(554710, 10, 183.329, -185.544, -111.375, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=88989;
DELETE FROM `creature_addon` WHERE `guid`=88989;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(88989, 889890, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=889890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(889890, 1, 109.037, -268.553, -108.677, 0, 0, 0, 0, 100, 0),
(889890, 2, 151.884, -275.712, -108.677, 0, 0, 0, 0, 100, 0),
(889890, 3, 143.666, -231.173, -108.852, 0, 0, 0, 0, 100, 0),
(889890, 4, 156.17, -275.286, -108.676, 0, 0, 0, 0, 100, 0),
(889890, 5, 138.876, -278.577, -108.676, 0, 0, 0, 0, 100, 0),
(889890, 6, 79.5604, -259.988, -108.678, 0, 0, 0, 0, 100, 0),
(889890, 7, 62.416, -207.188, -109.659, 0, 0, 0, 0, 100, 0),
(889890, 8, 8.187, -127.348, -123.845, 0, 0, 0, 0, 100, 0),
(889890, 9, 28.705, -38.025, -128.761, 0, 0, 0, 0, 100, 0),
(889890, 10, 8.187, -127.348, -123.845, 0, 0, 0, 0, 100, 0),
(889890, 11, 62.416, -207.188, -109.659, 0, 0, 0, 0, 100, 0),
(889890, 12, 79.0383, -255.555, -108.677, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56485;
DELETE FROM `creature_addon` WHERE `guid`=56485;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56485, 564850, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=564850;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(564850, 1, 150.49, -193.898, -171.747, 0, 0, 0, 0, 100, 0),
(564850, 2, 152.233, -231.891, -170.382, 0, 0, 0, 0, 100, 0),
(564850, 3, 125.841, -257.66, -168.113, 0, 0, 0, 0, 100, 0),
(564850, 4, 155.987, -284.034, -168.989, 0, 0, 0, 0, 100, 0),
(564850, 5, 148.455, -238.759, -169.543, 0, 0, 0, 0, 100, 0),
(564850, 6, 155.062, -199.53, -171.957, 0, 0, 0, 0, 100, 0),
(564850, 7, 104.937, -185.658, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 8, 100.198, -176.082, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 9, 111.893, -160.596, -167.328, 0, 0, 0, 0, 100, 0),
(564850, 10, 121.304, -176.939, -167.457, 0, 0, 0, 0, 100, 0),
(564850, 11, 128.284, -191.12, -168.26, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56501;
DELETE FROM `creature_addon` WHERE `guid`=56501;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56501, 565010, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=565010;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(565010, 1, 177.079, -304.031, -172.328, 0, 0, 0, 0, 100, 0),
(565010, 2, 146.519, -316.403, -174.591, 0, 0, 0, 0, 100, 0),
(565010, 3, 153.733, -376.576, -175.003, 0, 0, 0, 0, 100, 0),
(565010, 4, 211.381, -381.672, -160.691, 0, 0, 0, 0, 100, 0),
(565010, 5, 156.615, -376.11, -175.002, 0, 0, 0, 0, 100, 0),
(565010, 6, 148.461, -317.13, -174.589, 0, 0, 0, 0, 100, 0);


UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=56515;
DELETE FROM `creature_addon` WHERE `guid`=56515;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56515, 565150, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=565150;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(565150, 1, 312.737, -343.241, -117.348, 0, 0, 0, 0, 100, 0),
(565150, 2, 328.91, -288.013, -118.069, 0, 0, 0, 0, 100, 0),
(565150, 3, 320.637, -268.75, -117.912, 0, 0, 0, 0, 100, 0),
(565150, 4, 337.697, -262.309, -118.049, 0, 0, 0, 0, 100, 0),
(565150, 5, 345.634, -276.933, -117.941, 0, 0, 0, 0, 100, 0),
(565150, 6, 331.665, -290.395, -118.061, 0, 0, 0, 0, 100, 0),
(565150, 7, 317.848, -331.827, -116.777, 0, 0, 0, 0, 100, 0),
(565150, 8, 325.14, -394.223, -124.867, 0, 0, 0, 0, 100, 0),
(565150, 9, 250.345, -396.668, -139.555, 0, 0, 0, 0, 100, 0),
(565150, 10, 256.965, -328.427, -140.451, 0, 0, 0, 0, 100, 0),
(565150, 11, 251.778, -396.72, -139.555, 0, 0, 0, 0, 100, 0),
(565150, 12, 319.125, -403.751, -124.866, 0, 0, 0, 0, 100, 0);

SET @GUID := 160506;
SET @ENTRY := 1211;
-- Placed NPC 12237 (Meshlok the Harvester) into a pool with its placeholder
DELETE FROM `pool_creature` WHERE `guid` IN (@GUID, @GUID +3, 54652);
INSERT INTO `pool_creature` VALUES
(@GUID, @ENTRY, 30, 'Meshlok the Harvester (Maraudon)'),
(@GUID + 3, @ENTRY, 0, 'Meshlok the Harvester placeholder (Maraudon)'),
(54652, @ENTRY, 0, 'Meshlok the Harvester placeholder (Maraudon)');

DELETE FROM `pool_template` WHERE `entry` = @ENTRY;
INSERT INTO `pool_template` VALUES
(@ENTRY, 1, 'Meshlok the Harvester (Maraudon)');

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID + 7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(@GUID, 12237, 349, 0, 0, 1, 1, 0, 1, 632.101, -92.409, -57.4999, 3.49563, 7200, 0, 0, 5757, 0, 0, 0, 0, 0, 0),
(@GUID + 1, 12224, 349, 0, 0, 1, 1, 0, 1, 748.725, -81.8362, -57.4696, 0.620471, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 2, 12224, 349, 0, 0, 1, 1, 0, 1, 632.101, -92.409, -57.4999, 3.49563, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 3, 12224, 349, 0, 0, 1, 1, 0, 1, 818.573, -215.097, -77.1489, 4.14281, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 4, 12224, 349, 0, 0, 1, 1, 0, 1, 813.453, -370.449, -59.2094, 6.02488, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0),
(@GUID + 5, 12224, 349, 0, 0, 1, 1, 0, 1, 719.899, -83.8715, -57.2155, 3.48941, 7200, 0, 0, 4434, 2301, 0, 0, 0, 0, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 1;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+1, (@GUID+1) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+1) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+1) * 10, 1, 747.806, -79.9688, -57.4744, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 2, 750.866, -86.8807, -57.4595, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 3, 741.016, -94.8653, -57.4978, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 4, 745.803, -84.0748, -57.4833, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 5, 738.607, -70.5452, -57.4977, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 6, 751.253, -70.6902, -57.3912, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 7, 744.367, -78.7708, -57.4887, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 8, 756.588, -80.4979, -57.3727, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 9, 736.461, -89.3428, -57.4996, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 10, 734.7, -80.3283, -57.4996, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 11, 744.209, -79.5844, -57.4915, 0, 0, 0, 0, 100, 0),
((@GUID+1) * 10, 12, 734.044, -71.701, -57.4977, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 2;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+2, (@GUID+2) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+2) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+2) * 10, 1, 632.101, -92.409, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 2, 642.895, -89.225, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 3, 654.193, -88.5337, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 4, 666.728, -91.7718, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 5, 675.549, -93.9197, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 6, 690.764, -89.7546, -57.4999, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 7, 702.83, -84.753, -57.4631, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 8, 715.159, -83.791, -57.1193, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 9, 708.503, -83.9885, -57.2554, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 10, 699.353, -86.647, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 11, 681.834, -93.4817, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 12, 674.938, -93.0037, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 13, 665.508, -90.6338, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 14, 652.935, -87.6942, -57.5, 0, 0, 0, 0, 100, 0),
((@GUID+2) * 10, 15, 634.167, -92.0013, -57.5, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=@GUID + 3;
DELETE FROM `creature_addon` WHERE `guid`=@GUID + 3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@GUID+3, (@GUID+3) * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=(@GUID+3) * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
((@GUID+3) * 10, 1, 818.873, -216.343, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 2, 813.487, -210.328, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 3, 806.875, -204.634, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 4, 804.811, -193.5, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 5, 806.356, -184.124, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 6, 813.319, -173.6, -77.2995, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 7, 808.847, -175.006, -77.3074, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 8, 805.501, -182.277, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 9, 804.538, -193.051, -77.1489, 0, 0, 0, 0, 100, 0),
((@GUID+3) * 10, 10, 807.906, -203.501, -77.1489, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=203506;
DELETE FROM `creature_addon` WHERE `guid`=203506;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(203506, 203506 * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=203506 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(203506 * 10, 1, 632.101, -92.409, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 2, 642.895, -89.225, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 3, 654.193, -88.5337, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 4, 666.728, -91.7718, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 5, 675.549, -93.9197, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 6, 690.764, -89.7546, -57.4999, 0, 0, 0, 0, 100, 0),
(203506 * 10, 7, 702.83, -84.753, -57.4631, 0, 0, 0, 0, 100, 0),
(203506 * 10, 8, 715.159, -83.791, -57.1193, 0, 0, 0, 0, 100, 0),
(203506 * 10, 9, 708.503, -83.9885, -57.2554, 0, 0, 0, 0, 100, 0),
(203506 * 10, 10, 699.353, -86.647, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 11, 681.834, -93.4817, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 12, 674.938, -93.0037, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 13, 665.508, -90.6338, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 14, 652.935, -87.6942, -57.5, 0, 0, 0, 0, 100, 0),
(203506 * 10, 15, 634.167, -92.0013, -57.5, 0, 0, 0, 0, 100, 0);

UPDATE `creature_template` SET `speed_walk`=0.3, `speed_run`=0.4 WHERE  `entry`=12222;

UPDATE `creature` SET `MovementType`=2 WHERE  `guid`=55118;
DELETE FROM `creature_addon` WHERE `guid`=55118;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(55118, 55118 * 10, 0, 0, 0, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=55118 * 10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(55118 * 10, 1, 560.44, 74.1416, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 2, 556.001, 97.5598, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 3, 562.821, 116.938, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 4, 558.737, 80.2023, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 5, 567.894, 47.7771, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 6, 573.623, 24.1758, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 7, 583.107, 6.90322, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 8, 597.509, 5.07898, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 9, 600.013, 21.6183, -96.3128, 0, 0, 0, 0, 100, 0),
(55118 * 10, 10, 575.202, 46.2133, -96.3128, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=55118;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(55118, 55118, 0, 0, 2, 0, 0),
(55118, 55115, 3, 0, 2, 0, 0),
(55118, 55116, 3, 70, 2, 0, 0),
(55118, 55117, 3, 290, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=54579;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(54579, 54579, 0, 0, 2, 0, 0),
(54579, 54675, 16, 270, 2, 0, 0),
(54579, 54676, 16, 90, 2, 0, 0);
