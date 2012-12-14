-- add spawn for Saragosa
SET @GUID := 40270;
DELETE FROM `creature` WHERE `id`=26231;
INSERT INTO creature (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,26231,571,1,1,0,0,3981.03687,7148.006,666.1618,1.037019,120,0,0,1,0,0,0,0,0);
-- Pathing for Saragosa Entry: 26231

SET @PATH = @GUID*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3972.692,7139.177,666.609,0,0,0,0,100,0),
(@PATH,2,3973.208,7140.034,666.609,0,0,0,0,100,0),
(@PATH,3,3981.671,7149.173,666.2463,0,0,0,0,100,0),
(@PATH,4,3989.375,7172.479,669.3846,0,0,0,0,100,0),
(@PATH,5,3998.89,7199.31,674.7188,0,0,0,0,100,0),
(@PATH,6,4012.167,7242.467,666.8287,0,0,0,0,100,0),
(@PATH,7,4020.924,7276.525,652.9682,0,0,0,0,100,0),
(@PATH,8,4026.488,7297.103,640.2736,0,0,0,0,100,0),
(@PATH,9,4026.488,7297.103,640.2736,0,0,0,0,100,0);
