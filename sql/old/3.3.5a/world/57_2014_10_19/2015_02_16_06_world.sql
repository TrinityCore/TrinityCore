-- 
DELETE FROM `creature_addon` WHERE `guid` IN (126051,125886,126038,125888,125891,125887,125967,125956,125971,125962,125960,125965,24084,125964,125963,125973,125968,125961,125954,125972,125957,125955,125970,125969,125966,125958,125897, 125902, 125900, 125899, 125894, 125895, 125898);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
-- 
(126038, 0, 0, 0, 1, 133, NULL),
(125888, 0, 0, 0, 1, 133, NULL),
(125891, 0, 0, 0, 1, 133, NULL),
(125887, 0, 0, 0, 1, 133, NULL),
(125886, 0, 0, 0, 1, 133, NULL),
(126051, 0, 0, 0, 1, 133, NULL),
-- 
(24084, 0, 0, 0, 1, 7, NULL),
(125964, 0, 0, 0, 1, 7, NULL),
(125963, 0, 0, 0, 1, 7, NULL),
(125973, 0, 0, 0, 1, 7, NULL),
(125968, 0, 0, 0, 1, 7, NULL),
(125961, 0, 0, 0, 1, 7, NULL),
(125954, 0, 0, 0, 1, 7, NULL),
(125972, 0, 0, 0, 1, 7, NULL),
(125957, 0, 0, 0, 1, 7, NULL),
(125955, 0, 0, 0, 1, 7, NULL),
(125970, 0, 0, 0, 1, 7, NULL),
(125969, 0, 0, 0, 1, 7, NULL),
(125966, 0, 0, 0, 1, 7, NULL),
(125958, 0, 0, 0, 1, 7, NULL),
(125965, 0, 0, 0, 1, 7, NULL),
(125960, 0, 0, 0, 1, 7, NULL),
(125962, 0, 0, 0, 1, 7, NULL),
(125971, 0, 0, 0, 1, 7, NULL),
(125956, 0, 0, 0, 1, 7, NULL),
(125967, 0, 0, 0, 1, 7, NULL),
-- 
(125897, 0, 0, 0, 1, 234, NULL),
(125902, 0, 0, 0, 1, 234, NULL),
(125898, 0, 0, 0, 1, 234, NULL),
(125900, 0, 0, 0, 1, 234, NULL),
(125899, 0, 0, 0, 1, 234, NULL),
(125894, 0, 0, 0, 1, 234, NULL),
(125895, 0, 0, 0, 1, 234, NULL);

-- update some addons
UPDATE `creature_addon` SET `emote`=7 WHERE  `guid` IN (126027, 126043, 126034);
UPDATE `creature_addon` SET `emote`=1 WHERE  `guid` IN (125889, 125892);

-- remove unneeded double spawned NPCs
DELETE FROM `creature` WHERE `guid` IN (125930,125917,125932,125921,125920,125918,125915,125927,125931,125914,125922,125913);
DELETE FROM `creature_addon` WHERE `guid` IN (125913,125922,125917,125918,125921,125920,125927,125930,125931,125932,125915,125914);
DELETE FROM `linked_respawn` WHERE `guid`=125913;

-- Pathing for  Entry: 24080 'TDB FORMAT' 
SET @NPC := 125909;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=344.5201,`position_y`=-55.29842,`position_z`=23.00489 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,344.5201,-55.29842,23.00489,0,0,0,0,100,0),
(@PATH,2,344.8939,-55.7041,23.00489,0,0,0,0,100,0),
(@PATH,3,320.806,-36.86301,23.00489,0,0,0,0,100,0),
(@PATH,4,302.7466,-35.83545,24.96675,0,0,0,0,100,0),
(@PATH,5,299.0615,-36.53833,24.92923,0,0,0,0,100,0),
(@PATH,6,301.0684,-37.2436,24.67861,0,0,0,0,100,0),
(@PATH,7,314.7549,-36.4743,23.21675,0,0,0,0,100,0),
(@PATH,8,337.0555,-52.25382,23.00652,0,0,0,0,100,0);
-- 0x1C16DC47C0178400002225000161EB2E .go 344.5201 -55.29842 23.00489

-- Pathing for  Entry: 24080 'TDB FORMAT' 
SET @NPC := 125906;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=257.9562,`position_y`=-66.89291,`position_z`=24.67863 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,133, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,257.9562,-66.89291,24.67863,0,0,0,0,100,0),
(@PATH,2,250.1216,-42.76279,24.92863,0,0,0,0,100,0),
(@PATH,3,249.5976,-35.35291,24.92862,0,15000,0,0,100,0),
(@PATH,4,249.2954,-37.17996,24.92863,0,0,0,0,100,0),
(@PATH,5,257.3498,-63.88337,24.92863,0,0,0,0,100,0),
(@PATH,6,258.2347,-66.07593,24.92863,0,15000,0,0,100,0);
-- 0x1C16DC47C0178400002225000061EB2E .go 257.9562 -66.89291 24.67863

-- Pathing for  Entry: 24080 'TDB FORMAT' 
SET @NPC := 125908;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,133, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 258.921, -35.9238, 24.6786, 0, 15000, 0, 0, 100, 0),
(@PATH, 2, 260.677, -43.4207, 24.6786, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 278.781, -38.9278, 24.6786, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 278.542, -38.2699, 24.6786, 0, 15000, 0, 0, 100, 0),
(@PATH, 5, 264.293, -43.8186, 24.6786, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 24080 'TDB FORMAT' 
SET @NPC := 125907;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,133, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 267.265, -61.16, 24.6786, 0, 15000, 0, 0, 100, 0),
(@PATH, 2, 265.899, -54.8942, 24.6786, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 280.857, -49.5784, 24.6786, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 281.25, -50.5522, 24.6786, 0, 15000, 0, 0, 100, 0),
(@PATH, 5, 266.912, -55.2328, 24.6786, 0, 0, 0, 0, 100, 0);

-- Dragonflayer Weaponsmith SAI
SET @ENTRY := 24080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,4,0,50,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Weaponsmith - On Aggro - Say Line 1");

DELETE FROM `creature_text` WHERE `entry`=24080;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(24080, 0, 0, 'I spit on you!', 12, 0, 100, 0, 0, 0, 30503, 0, 'Dragonflayer Weaponsmith');

-- remove dublicated mounts
UPDATE `creature_template_addon` SET `mount`=0 WHERE  `entry`=24849;

DELETE FROM `creature_formations` WHERE `leaderGUID`=126042;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126042, 126042, 0, 0, 2, 0, 0),
(126042, 126046, 0, 0, 2, 0, 0),
(126042, 126032, 0, 0, 2, 0, 0),
(126042, 126041, 0, 0, 2, 0, 0);

-- Pathing for  Entry: 23953 'TDB FORMAT' 
SET @NPC :=126025;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,5, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 188.578, 217.181, 40.8161, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 189.28, 217.307, 40.8161, 0, 5000, 0, 0, 100, 0),
(@PATH, 3, 189.676, 207.039, 40.8161, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 196.131, 196.306, 40.8161, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 196.648, 196.778, 40.8161, 0, 5000, 0, 0, 100, 0);

-- Pathing for  Entry: 24085 'TDB FORMAT' 
SET @NPC := 125976;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=91.42882,`position_y`=136.3092,`position_z`=65.76968 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,91.42882,136.3092,65.76968,0,0,0,0,100,0),
(@PATH,2,103.4925,101.8953,65.53214,0,0,0,0,100,0),
(@PATH,3,134.187,65.97398,65.85297,0,0,0,0,100,0);
-- 0x1C16DC47C0178540002225000061EB2F .go 91.42882 136.3092 65.76968

-- Pathing for  Entry: 28419 'TDB FORMAT' 
SET @NPC := 125874;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=121.963,`position_y`=76.88269,`position_z`=109.2261 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,121.963,76.88269,109.2261,0,0,1,0,100,0),
(@PATH,2,120.63,69.04591,109.1783,0,0,1,0,100,0),
(@PATH,3,104.7298,55.60048,109.2639,0,0,1,0,100,0),
(@PATH,4,97.1344,52.90959,109.2572,0,0,1,0,100,0),
(@PATH,5,111.4303,57.28569,109.2564,0,0,1,0,100,0),
(@PATH,6,122.7686,70.0456,109.2553,0,0,1,0,100,0),
(@PATH,7,119.7332,84.98322,104.3059,0,0,1,0,100,0),
(@PATH,8,115.1914,99.77232,93.62556,0,0,1,0,100,0),
(@PATH,9,112.8705,109.7669,87.9285,0,0,1,0,100,0),
(@PATH,10,102.7546,111.7725,87.55014,0,0,1,0,100,0),
(@PATH,11,91.52882,102.3952,87.59012,0,0,1,0,100,0),
(@PATH,12,96.81816,85.65864,78.54314,0,0,1,0,100,0),
(@PATH,13,98.63879,73.78115,70.11957,0,0,1,0,100,0),
(@PATH,14,104.1278,66.31367,66.21651,0,0,1,0,100,0),
(@PATH,15,116.6431,60.78297,65.94734,0,0,1,0,100,0),
(@PATH,16,122.0239,71.59913,65.95915,0,0,1,0,100,0),
(@PATH,17,110.5408,86.22773,65.63712,0,0,1,0,100,0),
(@PATH,18,101.1147,100.7187,65.54391,0,0,1,0,100,0),
(@PATH,19,94.89072,118.4349,65.71883,0,0,1,0,100,0),
(@PATH,20,89.14192,135.3132,65.73074,0,0,1,0,100,0),
(@PATH,21,84.60493,149.5575,59.07762,0,0,1,0,100,0),
(@PATH,22,79.19835,165.6029,51.65039,0,0,1,0,100,0),
(@PATH,23,78.87008,184.8075,49.66129,0,0,1,0,100,0),
(@PATH,24,81.16812,201.4986,49.43202,0,0,1,0,100,0),
(@PATH,25,82.937,212.6811,49.61001,0,0,1,0,100,0),
(@PATH,26,87.64849,237.4446,45.35562,0,0,1,0,100,0),
(@PATH,27,98.99787,249.9266,43.19844,0,0,1,0,100,0),
(@PATH,28,117.071,260.0121,43.11768,0,0,1,0,100,0),
(@PATH,29,117.3428,259.8461,43.11845,0,0,1,0,100,0),
(@PATH,30,98.82381,251.8302,43.11781,0,0,1,0,100,0),
(@PATH,31,97.55148,251.2241,43.11774,0,0,1,0,100,0),
(@PATH,32,112.3071,256.5493,43.11781,0,0,1,0,100,0),
-- 
(@PATH,63,120.63,69.04591,109.1783,0,0,1,0,100,0),
(@PATH,62,104.7298,55.60048,109.2639,0,0,1,0,100,0),
(@PATH,61,97.1344,52.90959,109.2572,0,0,1,0,100,0),
(@PATH,60,111.4303,57.28569,109.2564,0,0,1,0,100,0),
(@PATH,59,122.7686,70.0456,109.2553,0,0,1,0,100,0),
(@PATH,58,119.7332,84.98322,104.3059,0,0,1,0,100,0),
(@PATH,57,115.1914,99.77232,93.62556,0,0,1,0,100,0),
(@PATH,56,112.8705,109.7669,87.9285,0,0,1,0,100,0),
(@PATH,55,102.7546,111.7725,87.55014,0,0,1,0,100,0),
(@PATH,54,91.52882,102.3952,87.59012,0,0,1,0,100,0),
(@PATH,53,96.81816,85.65864,78.54314,0,0,1,0,100,0),
(@PATH,52,98.63879,73.78115,70.11957,0,0,1,0,100,0),
(@PATH,51,104.1278,66.31367,66.21651,0,0,1,0,100,0),
(@PATH,50,116.6431,60.78297,65.94734,0,0,1,0,100,0),
(@PATH,49,122.0239,71.59913,65.95915,0,0,1,0,100,0),
(@PATH,48,110.5408,86.22773,65.63712,0,0,1,0,100,0),
(@PATH,47,101.1147,100.7187,65.54391,0,0,1,0,100,0),
(@PATH,46,94.89072,118.4349,65.71883,0,0,1,0,100,0),
(@PATH,45,89.14192,135.3132,65.73074,0,0,1,0,100,0),
(@PATH,44,84.60493,149.5575,59.07762,0,0,1,0,100,0),
(@PATH,43,79.19835,165.6029,51.65039,0,0,1,0,100,0),
(@PATH,42,78.87008,184.8075,49.66129,0,0,1,0,100,0),
(@PATH,41,81.16812,201.4986,49.43202,0,0,1,0,100,0),
(@PATH,40,82.937,212.6811,49.61001,0,0,1,0,100,0),
(@PATH,39,87.64849,237.4446,45.35562,0,0,1,0,100,0),
(@PATH,38,98.99787,249.9266,43.19844,0,0,1,0,100,0),
(@PATH,37,117.071,260.0121,43.11768,0,0,1,0,100,0),
(@PATH,36,117.3428,259.8461,43.11845,0,0,1,0,100,0),
(@PATH,35,98.82381,251.8302,43.11781,0,0,1,0,100,0),
(@PATH,34,97.55148,251.2241,43.11774,0,0,1,0,100,0),
(@PATH,33,112.3071,256.5493,43.11781,0,0,1,0,100,0);
-- 0x1C16DC47C01BC0C00022250002E1EB2E .go 121.963 76.88269 109.2261

DELETE FROM `creature_formations` WHERE `leaderGUID`=125874;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(125874, 125874, 0, 0, 2, 0, 0),
(125874, 125876, 3, 90, 2, 0, 0),
(125874, 125875, 3, 270, 2, 0, 0);

-- Pathing for  Entry: 24085 'TDB FORMAT' 
SET @NPC := 125974;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 139.312, 280.748, 42.8666, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 150.295, 273.444, 42.8666, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 138.731, 281.758, 42.8666, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 129.301, 272.882, 42.8666, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 24085 'TDB FORMAT' 
SET @NPC := 125977;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 75.2556, 249.779, 42.8657, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 83.8848, 256.364, 42.866, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 99.3102, 261.128, 42.8661, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 84.1909, 256.288, 42.8661, 0, 0, 0, 0, 100, 0);

SET @NPC := 125883;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 77.3519, 205.89, 49.34, 0, 0, 1, 0, 100, 0),
(@PATH, 2, 86.5749, 199.366, 49.3541, 0, 0, 1, 0, 100, 0),
(@PATH, 3, 92.7536, 202.35, 49.3631, 0, 0, 1, 0, 100, 0),
(@PATH, 4, 94.5927, 208.849, 49.37, 0, 0, 1, 0, 100, 0),
(@PATH, 5, 86.0534, 216.692, 49.3855, 0, 0, 1, 0, 100, 0),
(@PATH, 6, 75.9458, 214.115, 49.361, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=125883;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(125883, 125883, 0, 0, 2, 0, 0),
(125883, 125885, 5, 90, 2, 0, 0),
(125883, 125884, 5, 270, 2, 0, 0);

SET @NPC := 125975;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 97.1818, 193.375, 49.3721, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 97.6578, 205.356, 49.375, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 96.4575, 193.39, 49.372, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 96.9237, 185.571, 49.3659, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 24085 'TDB FORMAT' 
SET @NPC := 125976;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=108.85,`position_y`=88.22916,`position_z`=65.88628 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 104.324, 101.477, 65.4325, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 99.6436, 114.531, 65.4742, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 93.3592, 132.058, 65.5217, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 91.2544, 138.023, 65.5074, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 89.0365, 144.514, 61.6515, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 83.6051, 160.412, 54.041, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 80.7065, 169.333, 49.6367, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 78.4122, 180.724, 49.3771, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 80.8062, 169.721, 49.4824, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 84.2462, 158.583, 54.9073, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 89.1532, 144.915, 61.4908, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 91.498, 137.939, 65.5082, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 96.5665, 122.362, 65.495, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 101.592, 106.919, 65.4531, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 108.985, 87.2638, 65.5996, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 119.016, 74.4927, 65.7037, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 129.481, 61.1712, 65.6985, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 136.363, 63.0702, 65.6985, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 145.165, 65.8833, 65.6865, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 154.484, 68.9137, 65.6788, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 134.651, 62.0119, 65.6977, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 121.026, 71.1032, 65.7021, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 115.277, 81.3625, 65.7034, 0, 0, 0, 0, 100, 0);

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=23956 AND `source_type`=0 AND `id`=0 AND `link`=1;
SET @NPC := 126033;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 92.0074, 91.8776, 83.1133, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 94.4268, 84.0678, 77.4261, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 97.4964, 75.2498, 71.1212, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 100.256, 67.5835, 65.7404, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 104.253, 56.1223, 65.7013, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 99.9233, 68.46, 66.1115, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 96.7413, 77.7433, 72.8654, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 93.4206, 87.9519, 80.2184, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 89.9479, 97.6074, 87.0594, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 85.3204, 111.309, 87.294, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 109.086, 121.066, 87.308, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 114.25, 108.563, 87.465, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 117.378, 100.272, 93.3328, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 119.976, 92.7572, 98.707, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 122.256, 85.8878, 103.744, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 124.757, 78.354, 108.636, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 129.66, 64.2292, 109.023, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 131.063, 60.2705, 109.027, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 108.086, 53.1456, 108.988, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 131.63, 61.4828, 109.027, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 125.35, 78.8325, 108.65, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 121.873, 88.5025, 101.93, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 117.766, 99.9247, 93.6416, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 114.768, 108.264, 87.5181, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 110.429, 120.332, 87.3079, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 85.4045, 112.781, 87.2894, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 88.3241, 102.455, 87.3183, 0, 0, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126033;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126033, 126033, 0, 0, 2, 0, 0),
(126033, 125998, 2, 270, 2, 0, 0);

SET @NPC := 125879;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 53.1848, 39.7439, 115.029, 0, 0, 1, 0, 100, 0),
(@PATH, 2, 43.585, 41.2652, 115.029, 0, 0, 1, 0, 100, 0),
(@PATH, 3, 45.878, 32.8663, 115.029, 0, 0, 1, 0, 100, 0),
(@PATH, 4, 54.3001, 30.387, 115.029, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=125879;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(125879, 125879, 0, 0, 2, 0, 0),
(125879, 125878, 3, 90, 2, 0, 0),
(125879, 125877, 2, 270, 2, 0, 0);

SET @NPC := 125882;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 40.6954, -7.59713, 118.542, 0, 0, 1, 0, 100, 0),
(@PATH, 2, 41.5325, -16.0661, 118.775, 0, 0, 1, 0, 100, 0),
(@PATH, 3, 47.1018, -17.7693, 118.775, 0, 0, 1, 0, 100, 0),
(@PATH, 4, 46.6655, -3.88553, 118.775, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=125882;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(125882, 125882, 0, 0, 2, 0, 0),
(125882, 125880, 3, 90, 2, 0, 0),
(125882, 125881, 2, 270, 2, 0, 0);
