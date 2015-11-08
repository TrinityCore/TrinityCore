-- 
SET @GUID := 24;
DELETE FROM `creature` WHERE `id` IN (31810);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`PhaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,31810,571,1,0,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0);
