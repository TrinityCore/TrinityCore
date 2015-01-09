-- Pathing for Foreman Tionn Entry: 24006 "4XX Path"
SET @NPC := 156316;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3764.7,`position_y`=-4324.11,`position_z`=9.854144 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3755.87,-4341.73,10.77343,0,0,0,0,100,0),
(@PATH,2,-3750.141,-4347.877,10.64843,0,0,0,0,100,0),
(@PATH,3,-3755.87,-4341.73,10.77343,0,0,0,0,100,0),
(@PATH,4,-3764.7,-4324.11,9.854144,0,0,0,0,100,0),
(@PATH,5,-3771.77,-4313.51,9.952533,0,0,0,0,100,0),
(@PATH,6,-3777.95,-4300.42,9.569232,0,0,0,0,100,0),
(@PATH,7,-3771.77,-4313.51,9.952533,0,0,0,0,100,0),
(@PATH,8,-3764.7,-4324.11,9.854144,0,0,0,0,100,0);
-- .go -3755.87 -4341.73 10.77343
