-- Complete UP Movement
SET @NPC := 126159;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=408.6479,`position_y`=-247.8646,`position_z`=105.1593 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,408.6479,-247.8646,105.1593,0,0,0,0,100,0),
(@PATH,2,413.1479,-247.3646,105.4093,0,0,0,0,100,0),
(@PATH,3,417.3979,-247.1146,105.4093,0,0,0,0,100,0),
(@PATH,4,421.3979,-246.8646,105.1593,0,0,0,0,100,0),
(@PATH,5,424.6479,-246.8646,105.4093,0,0,0,0,100,0),
(@PATH,6,431.6479,-246.3646,105.1593,0,0,0,0,100,0),
(@PATH,7,437.3979,-245.8646,105.1593,0,0,0,0,100,0),
(@PATH,8,439.8979,-245.6146,105.1593,0,6000,0,0,100,0),
(@PATH,9,439.8979,-245.6146,105.1593,0,0,0,0,100,0),
(@PATH,10,437.3979,-245.8646,105.1593,0,0,0,0,100,0),
(@PATH,11,431.6479,-246.3646,105.1593,0,0,0,0,100,0),
(@PATH,12,424.6479,-246.8646,105.4093,0,0,0,0,100,0),
(@PATH,13,421.3979,-246.8646,105.1593,0,0,0,0,100,0),
(@PATH,14,417.3979,-247.1146,105.4093,0,0,0,0,100,0),
(@PATH,15,413.1479,-247.3646,105.4093,0,0,0,0,100,0),
(@PATH,16,408.6479,-247.8646,105.1593,0,6000,0,0,100,0);

SET @NPC := 126083;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=281.2139,`position_y`=-383.5794,`position_z`=90.28523 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 10, 273.909, -398.059, 90.1069, 0, 10, 0, 0, 100, 0),
(@PATH, 9, 262.177, -400.701, 83.5446, 0, 10, 0, 0, 100, 0),
(@PATH, 8, 248.65, -398.957, 75.1077, 0, 10, 0, 0, 100, 0),
(@PATH, 7, 262.177, -400.701, 83.5446, 0, 10, 0, 0, 100, 0),
(@PATH, 6, 273.909, -398.059, 90.1069, 0, 10, 0, 0, 100, 0),
(@PATH, 5, 281.51, -396.934, 89.9561, 0, 10, 0, 0, 100, 0),
(@PATH, 4, 281.066, -384.517, 90.0477, 0, 10, 0, 0, 100, 0),
(@PATH, 3, 263.144, -381.767, 96.7176, 0, 10, 0, 0, 100, 0),
(@PATH, 2, 248.789, -383.987, 104.753, 0, 10, 0, 0, 100, 0),
(@PATH, 1, 263.144, -381.767, 96.7176, 0, 10, 0, 0, 100, 0);

UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=26670 AND `source_type`=0 AND `id`=0 AND `link`=1;

DELETE FROM `creature_formations` WHERE `leaderGUID`=126083;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126083, 126087, 3, 270, 2, 0, 0),
(126083, 126088, 3, 90, 2, 0, 0),
(126083, 126083, 0, 0, 2, 0, 0);


SET @NPC := 126086;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 8, 238.128, -450.66, 104.736, 0, 10, 0, 0, 100, 0),
(@PATH, 7, 236.583, -435.635, 104.736, 0, 10, 0, 0, 100, 0),
(@PATH, 6, 236.444, -449.692, 104.736, 0, 10, 0, 0, 100, 0),
(@PATH, 5, 238.128, -450.66, 104.736, 0, 10, 0, 0, 100, 0),
(@PATH, 4, 309.006, -451.589, 104.718, 0, 10, 0, 0, 100, 0),
(@PATH, 3, 310.79, -451.589, 104.718, 0, 10, 0, 0, 100, 0),
(@PATH, 2, 310.682, -467.433, 104.718, 0, 10, 0, 0, 100, 0),
(@PATH, 1, 310.79, -451.589, 104.718, 0, 10, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126086;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126086, 126078, 5, 180, 2, 0, 0),
(126086, 126081, 5, 90, 2, 0, 0),
(126086, 126082, 5, 270, 2, 0, 0),
(126086, 126086, 0, 0, 2, 0, 0);

SET @NPC := 126111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 7, 368.053, -432.959, 75.1209, 0, 10, 0, 0, 100, 0),
(@PATH, 6, 402.875, -428.319, 75.1263, 0, 10, 0, 0, 100, 0),
(@PATH, 5, 407.49, -441.521, 75.0988, 0, 10, 0, 0, 100, 0),
(@PATH, 4, 429.311, -447.42, 75.1166, 0, 10, 0, 0, 100, 0),
(@PATH, 3, 428.506, -467.335, 75.1153, 0, 10, 0, 0, 100, 0),
(@PATH, 2, 400.957, -455.234, 75.1132, 0, 10, 0, 0, 100, 0),
(@PATH, 1, 372.02, -450.569, 75.1308, 0, 10, 0, 0, 100, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126111;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126111, 126110, 3, 280, 2, 0, 0),
(126111, 126111, 0, 0, 2, 0, 0);
