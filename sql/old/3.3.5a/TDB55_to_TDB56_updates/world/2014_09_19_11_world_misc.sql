-- Pathing for Creteus Entry: 30052
SET @NPC := 104811;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7364.138,`position_y`=-963.9908,`position_z`=906.1143 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7364.138,-963.9908,906.1143,0,0,0,0,100,0),
(@PATH,2,7354.389,-990.3735,907.1021,0,0,0,0,100,0),
(@PATH,3,7344.142,-1026.269,907.1985,0,0,0,0,100,0),
(@PATH,4,7346.274,-1065.193,908.5342,0,0,0,0,100,0),
(@PATH,5,7344.142,-1026.269,907.1985,0,0,0,0,100,0),
(@PATH,6,7354.389,-990.3735,907.1021,0,0,0,0,100,0),
(@PATH,7,7364.138,-963.9908,906.1143,0,0,0,0,100,0),
(@PATH,8,7374.346,-935.5877,906.896,0,0,0,0,100,0),
(@PATH,9,7393.324,-923.742,907.4128,0,0,0,0,100,0),
(@PATH,10,7420.953,-909.6816,908.7245,0,0,0,0,100,0),
(@PATH,11,7393.313,-923.7285,907.2764,0,0,0,0,100,0),
(@PATH,12,7374.346,-935.5877,906.896,0,0,0,0,100,0);
