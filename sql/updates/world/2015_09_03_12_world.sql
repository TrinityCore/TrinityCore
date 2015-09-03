--
SET @GUID := 63373;
SET @OLDGUID := 225;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2);
DELETE FROM `creature` WHERE `guid` IN (@OLDGUID,@OLDGUID+1,@OLDGUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,29369,571,1,1,0,1,7842.542,-110.6463,882.8068,5.88176,300,0,0,1,0,0),
(@GUID+1,29369,571,1,1,0,1,7827.683,-77.09928,882.7308,5.88176,300,0,0,1,0,0),
(@GUID+2,29369,571,1,1,0,1,7834.078,-130.5392,882.3082,5.88176,300,0,0,1,0,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID;
SET @OLDNPC := @OLDGUID;
SET @PATH := @NPC * 10;
SET @OLDPATH := @OLDNPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7842.542,`position_y`=-110.6463,`position_z`=882.8068 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@OLDNPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
DELETE FROM `waypoint_data` WHERE `id`=@OLDPATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7842.542,-110.6463,882.8068,0,0,0,0,100,0),
(@PATH,2,7839.237,-106.3565,882.6854,0,0,0,0,100,0),
(@PATH,3,7833.708,-100.7408,881.3173,0,0,0,0,100,0),
(@PATH,4,7827.768,-96.58257,881.0281,0,0,0,0,100,0),
(@PATH,5,7822.916,-90.53754,880.5125,0,0,0,0,100,0),
(@PATH,6,7822.845,-83.79515,881.5299,0,0,0,0,100,0),
(@PATH,7,7822.916,-90.48802,880.5093,0,0,0,0,100,0),
(@PATH,8,7827.694,-96.49003,881.0132,0,0,0,0,100,0),
(@PATH,9,7833.708,-100.7408,881.3173,0,0,0,0,100,0),
(@PATH,10,7839.095,-106.2119,882.6039,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID+1;
SET @OLDNPC := @OLDGUID+1;
SET @PATH := @NPC * 10;
SET @OLDPATH := @OLDNPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7827.683,`position_y`=-77.09928,`position_z`=882.7308 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@OLDNPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
DELETE FROM `waypoint_data` WHERE `id`=@OLDPATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7827.683,-77.09928,882.7308,0,0,0,0,100,0),
(@PATH,2,7824.653,-79.73319,882.5463,0,0,0,0,100,0),
(@PATH,3,7827.683,-77.09928,882.7308,0,0,0,0,100,0),
(@PATH,4,7832.377,-77.63552,881.9279,0,0,0,0,100,0),
(@PATH,5,7837.402,-75.31012,880.0537,0,0,0,0,100,0),
(@PATH,6,7832.377,-77.63552,881.9279,0,0,0,0,100,0);

-- Pathing for Stormforged Taskmaster Entry: 29369
SET @NPC := @GUID+2;
SET @OLDNPC := @OLDGUID+2;
SET @PATH := @NPC * 10;
SET @OLDPATH := @OLDNPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7842.921,`position_y`=-124.6453,`position_z`=880.9332 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@OLDNPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
DELETE FROM `waypoint_data` WHERE `id`=@OLDPATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7834.078,-130.5392,882.3082,0,0,0,0,100,0),
(@PATH,2,7842.921,-124.6453,880.9332,0,0,0,0,100,0),
(@PATH,3,7851.019,-120.6835,880.8082,0,0,0,0,100,0),
(@PATH,4,7856.965,-115.7509,881.3082,0,0,0,0,100,0),
(@PATH,5,7850.458,-124.2621,880.1832,0,0,0,0,100,0),
(@PATH,6,7856.965,-115.7509,881.3082,0,0,0,0,100,0),
(@PATH,7,7851.019,-120.6835,880.8082,0,0,0,0,100,0),
(@PATH,8,7842.921,-124.6453,880.9332,0,0,0,0,100,0);
