-- Add missing Gan'jo spawn to Grizzly Hills
SET @GUID  := 42187;
SET @ENTRY := 26924;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,@ENTRY,571,1,2,0,0,4834.98,-4754.5,32.5689,3.97935,180,0,0,1,0,0);
-- Add Aura to Gan'jo
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'17327');
