-- Pathing for  Entry: 32478 'TDB FORMAT' 
SET @NPC := 88139;
SET @PATH := @NPC * 10;

UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8877.512,`position_y`=-1358.266,`position_z`=1033.88 WHERE `guid`=@NPC;

DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8877.512,-1358.266,1033.88,0,0,0,0,100,0),
(@PATH,2,8877.512,-1359.266,1033.88,0,0,0,0,100,0),
(@PATH,3,8876.762,-1360.266,1033.63,0,0,0,0,100,0),
(@PATH,4,8876.447,-1360.297,1033.653,0,0,0,0,100,0),
(@PATH,5,8875.947,-1362.047,1033.653,0,0,0,0,100,0),
(@PATH,6,8873.364,-1366.144,1033.657,1.099557,120000,0,0,100,0),
(@PATH,7,8873.255,-1358.092,1033.895,0,0,0,0,100,0),
(@PATH,8,8873.492,-1357.932,1034.002,0,0,0,0,100,0),
(@PATH,9,8873.856,-1353.284,1034.383,0,0,0,0,100,0),
(@PATH,10,8878.05,-1356.542,1033.729,0,0,0,0,100,0),
(@PATH,11,8878.05,-1356.542,1033.729,0.541052,120000,0,0,100,0);
-- 0x203CD047601FB780000C1D000008E709 .go 8877.512 -1358.266 1033.88
