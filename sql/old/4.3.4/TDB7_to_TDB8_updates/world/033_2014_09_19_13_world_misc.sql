-- Pathing for Fjorn Entry: 29503
SET @NPC := 88308;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7174.861,`position_y`=-3647.9,`position_z`=828.4227 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7174.861,-3647.9,828.4227,0,0,0,0,100,0),
(@PATH,2,7190.947,-3657.829,823.7313,0,0,0,0,100,0),
(@PATH,3,7203.092,-3661.859,823.8141,0,0,0,0,100,0),
(@PATH,4,7217.113,-3659.162,823.2127,2.024582,24000,0,0,100,0),
(@PATH,5,7178.155,-3646.861,826.0764,0,0,0,0,100,0),
(@PATH,6,7166.444,-3625.109,830.9739,0,0,0,0,100,0),
(@PATH,7,7166.76,-3600.556,830.7375,0,35000,0,0,100,0);
