-- Pathing for  Entry: 43662 'TDB FORMAT' 
SET @NPC := 340450;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1024.542,`position_y`=849.5343,`position_z`=298.6647 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,971.488,880.601,305.9347,0,0,1,0,100,0),
(@PATH,2,971.431,894.707,306.6,0,0,1,0,100,0),
(@PATH,3,983.392,904.229,306.2977,0,0,1,0,100,0),
(@PATH,4,1007.39,883.028,301.3122,0,0,1,0,100,0),
(@PATH,5,1038.13,881.785,297.10,1,0,1,0,100,0),
(@PATH,6,1029.69,851.0083,298.0182,0,0,1,0,100,0),
(@PATH,7,994.264,861.425,301.936,0,0,1,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`= 340450;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(340450, 340450, 0, 0, 515, 0, 0),
(340450, 340451, 3, 315, 515, 0, 0),
(340450, 340452, 4, 360, 515, 0, 0),
(340450, 340453, 3, 45, 515, 0, 0);
