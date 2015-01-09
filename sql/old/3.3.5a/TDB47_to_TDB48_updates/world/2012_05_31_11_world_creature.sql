-- Add a couple more Domesticated Felboar Spawns
SET @GUID := 42567;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,21195,530,1,1,0,0,-2678.16016,1477.65625,26.9172077,4.86340427,300,5,0,1,0,1),
(@GUID+1,21195,530,1,1,0,0,-2691.666,1525,21.3857346,0.3155697,300,5,0,1,0,1);
