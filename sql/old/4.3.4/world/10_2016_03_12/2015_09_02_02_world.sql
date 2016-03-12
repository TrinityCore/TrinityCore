--
SET @GUID := 83022;
SET @OLDGUID := 148; -- 4.x

DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
DELETE FROM `creature` WHERE `guid` IN (@OLDGUID,@OLDGUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,36223,571,1,1,0,0,8540.497,986.4167,547.4177,0.01343229,120,0,0,1,0,0),
(@GUID+1,36223,571,1,1,0,0,8533.108,985.1597,547.3926,0.6806784,120,0,0,1,0,0);

SET @NPC := 83022;
SET @OLDNPC := 148;
SET @PATH := @NPC * 10;
SET @OLDPATH := @OLDNPC * 10;

UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=8537.03,`position_y`=986.37,`position_z`=547.4177 WHERE `guid`=@NPC;

DELETE FROM `creature_addon` WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@OLDNPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');

DELETE FROM `waypoint_data` WHERE `id`=@PATH;
DELETE FROM `waypoint_data` WHERE `id`=@OLDPATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,8537.03,986.37,547.4177,0,13000,0,52,100,0),
(@PATH,2,8540.497,986.4167,547.4177,0,0,0,0,100,0),
(@PATH,3,8540.497,986.4167,547.4177,5.462881,37000,0,0,100,0);
