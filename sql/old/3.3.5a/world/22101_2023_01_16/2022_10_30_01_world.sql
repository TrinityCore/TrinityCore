-- Pathing for Razorspine Entry: 23841
SET @NPC := 39309;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=-2667.589,`position_y`=-4017.5479,`position_z`=1.7994823 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2667.589,-4017.5479,1.7994823,NULL,0,0,0,100,0),
(@PATH,2,-2682.1023,-4013.1038,7.623457,NULL,0,0,0,100,0),
(@PATH,3,-2701.14,-4009.6328,17.22806,NULL,0,0,0,100,0),
(@PATH,4,-2722.923,-4008.8137,29.876986,NULL,0,0,0,100,0),
(@PATH,5,-2737.096,-4004.9934,33.11826,NULL,0,0,0,100,0),
(@PATH,6,-2722.923,-4008.8137,29.876986,NULL,0,0,0,100,0),
(@PATH,7,-2701.14,-4009.6328,17.22806,NULL,0,0,0,100,0),
(@PATH,8,-2682.1023,-4013.1038,7.623457,NULL,0,0,0,100,0);
