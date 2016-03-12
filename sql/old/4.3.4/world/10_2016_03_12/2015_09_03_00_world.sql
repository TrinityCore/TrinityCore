--
SET @GUID := 63451;
DELETE FROM `creature` WHERE `id` IN (35597,35611,35612);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,35597,530,1,1,0,1,-1977.80212,5267.618,-41.65557,4.3982296,300,0,0,1,1,0),
(@GUID+1,35611,0,1,1,0,1,1333.57642,320.9896,-63.6309357,2.8972466,300,0,0,1,1,0),
(@GUID+2,35612,530,1,1,0,1,9855.403,-7578.021,20.61899,1.78023577,300,0,0,1,1,0);
