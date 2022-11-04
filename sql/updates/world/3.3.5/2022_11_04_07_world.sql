-- Defias Evoker
DELETE FROM `creature_formations` WHERE `leaderguid`=79244 AND `groupai` = 515;
SET @NPC := 79245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -213.047, -504.664, 50.9039, 0),
(@PATH, 2, -218.668, -498.713, 49.1948, 0),
(@PATH, 3, -223.364, -491.597, 48.0883, 0),
(@PATH, 4, -233.816, -485.034, 48.8204, 0),
(@PATH, 5, -239.75, -483.76, 49.0921, 0),
(@PATH, 6, -245.689, -483.842, 49.2077, 0),
(@PATH, 7, -254.883, -483.617, 49.4456, 0),
(@PATH, 8, -241.837, -483.706, 48.9397, 0),
(@PATH, 9, -234.516, -485.182, 48.8104, 0),
(@PATH, 10, -225.919, -491.995, 47.9344, 0),
(@PATH, 11, -222.576, -494.121, 48.2125, 0),
(@PATH, 12, -217.75, -498.868, 49.335, 0),
(@PATH, 13, -215.491, -502.696, 50.809, 0),
(@PATH, 14, -209.724, -505.442, 51.3525, 0),
(@PATH, 15, -201.66, -505.78, 52.8074, 0);
