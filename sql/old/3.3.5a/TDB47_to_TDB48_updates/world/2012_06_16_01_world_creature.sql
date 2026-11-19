-- Add missing Storm Totem spawn to Borean Tundra
SET @GUID := 12925;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,26048,571,1,1,0,0,3409.903,4128.829,18.13754,5.742133,300,0,0,1,0,0);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|16777216 WHERE `entry`=26048;
