-- PATH 1
SET @NPC := 44961;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, 1900.23, 1551.08, 88.9628, 5.97202, 40000, 0),                                                               
(@PATH, 2, 1906.85, 1549.28, 88.9631, 0.059717, 0, 0),                                                               
(@PATH, 3, 1918.24, 1550.21, 86.8964, 1.09251, 0, 0),                                                               
(@PATH, 4, 1921.96, 1559.95, 86.1943, 0.815268, 0, 0),                                                               
(@PATH, 5, 1934.78, 1577.86, 82.6267, 0.907945, 40000, 0),                                                               
(@PATH, 6, 1915.65, 1587.77, 84.535, 3.18717, 0, 0),                                                               
(@PATH, 7, 1889.43, 1586.55, 88.8601, 2.76541, 4000, 0);

-- Mindless Zombie SAI
SET @GUID := -44961;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,34,0,100,0,2,6,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mindless Zombie - On Reached Point 6 - Set Faction 21"),
(@GUID,0,1,0,61,0,100,0,2,6,0,0,49,0,0,0,0,0,0,19,1736,20,0,0,0,0,0,"Mindless Zombie - On Reached Point 6 - Start Attacking");

-- PATH 2
SET @NPC := 44958;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, 1908.16, 1561.51, 87.9566, 0.576077, 0, 0),                                                               
(@PATH, 2, 1923.33, 1571.39, 85.1808, 0.876885, 0, 0),                                                               
(@PATH, 3, 1926.58, 1584, 83.058, 2.7697, 0, 0),                                                               
(@PATH, 4, 1910.97, 1588.5, 85.4029, 3.1192, 0, 0),                                                               
(@PATH, 5, 1894.6, 1587.11, 88.0001, 2.89772, 5000, 0);

-- Wretched Ghoul SAI
SET @GUID := -44958;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1502;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,34,0,100,0,2,4,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Reached Point 4 - Set Faction 21"),
(@GUID,0,1,0,61,0,100,0,2,4,0,0,49,0,0,0,0,0,0,19,1736,20,0,0,0,0,0,"Wretched Ghoul - On Reached Point 4 - Start Attacking");

-- PATH 3
SET @NPC := 44962;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, 1970.38, 1496.6, 86.5755, 1.58563, 0, 0),                                                               
(@PATH, 2, 1959.61, 1505.71, 88.0769, 2.631, 0, 0),                                                               
(@PATH, 3, 1933.58, 1520.06, 88.0768, 2.61451, 0, 0),                                                               
(@PATH, 4, 1918.64, 1531.43, 86.9021, 1.85345, 0, 0),                                                               
(@PATH, 5, 1918.2, 1546.97, 86.9222, 1.39007, 0, 0),                                                               
(@PATH, 6, 1921.22, 1557.97, 86.371, 1.0401, 0, 0),                                                               
(@PATH, 7, 1936.24, 1578.17, 82.4023, 0.740866, 0, 0),                                                               
(@PATH, 8, 1950.07, 1584.96, 81.1354, 0.082702, 0, 0),                                                               
(@PATH, 9, 1967.7, 1583.2, 81.7346, 6.00382, 0, 0),                                                               
(@PATH, 10, 1975.87, 1575.03, 79.1618, 5.40299, 0, 0),                                                               
(@PATH, 11, 1993.59, 1557.52, 78.3874, 5.4022, 0, 0),                                                               
(@PATH, 12, 1998.18, 1550.03, 78.1416, 5.24198, 0, 0),                                                               
(@PATH, 13, 2003.49, 1535.84, 76.7181, 5.06134, 0, 0),                                                               
(@PATH, 14, 2007.71, 1522.96, 75.7106, 4.90033, 0, 0),                                                               
(@PATH, 15, 2005.73, 1501.61, 72.9365, 4.05996, 0, 0),                                                               
(@PATH, 16, 2000.68, 1496.71, 73.0049, 3.50311, 0, 0),                                                               
(@PATH, 17, 1987.96, 1493.4, 82.1718, 3.36489, 0, 0),                                                               
(@PATH, 18, 1978.23, 1488.28, 85.0991, 3.67512, 0, 0),                                                               
(@PATH, 19, 1966.66, 1484.12, 83.4741, 3.17639, 10000, 0);

-- PATH 4
SET @NPC := 44965;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 1, 1972.64, 1595.26, 82.325, 4.48871, 30000, 0),                                                               
(@PATH, 2, 1972.51, 1594.35, 82.3245, 4.33198, 0, 0),                                                               
(@PATH, 3, 1968.3, 1586.97, 82.1956, 3.36752, 0, 0),                                                               
(@PATH, 4, 1951.04, 1587.19, 81.5231, 3.64363, 0, 0),                                                               
(@PATH, 5, 1938.35, 1579.9, 81.948, 3.29491, 0, 0),                                                               
(@PATH, 6, 1922.04, 1586.48, 83.6347, 2.95876, 0, 0),                                                               
(@PATH, 7, 1904.48, 1587.06, 86.3556, 3.13783, 0, 0),                                                               
(@PATH, 8, 1893.63, 1584.73, 88.2344, 2.6878, 5000, 0);                                                          

-- Wretched Ghoul SAI
SET @GUID := -44965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1502;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,1,34,0,100,0,2,7,0,0,2,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Reached Point 7 - Set Faction 21"),
(@GUID,0,1,0,61,0,100,0,2,7,0,0,49,0,0,0,0,0,0,19,1736,20,0,0,0,0,0,"Wretched Ghoul - On Reached Point 7 - Start Attacking");

UPDATE `creature` SET `spawntimesecs`=100 WHERE  `guid` IN (44961, 44958, 44965);
