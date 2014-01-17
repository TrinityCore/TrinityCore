-- Spawn 4 missing Zul'Gurub Panther Triggers
SET @GUID := 48311;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`, `position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,15091,309,1,1,0,0,-11518.29,-1649.965,41.38264,5.131268,7200,0,0,1,0,0,0,0,0),
(@GUID+1,15091,309,1,1,0,0,-11518.51,-1649.303,41.38264,5.864306,7200,0,0,1,0,0,0,0,0),
(@GUID+2,15091,309,1,1,0,0,-11518.46,-1651.542,41.38264,0.2617994,7200,0,0,1,0,0,0,0,0),
(@GUID+3,15091,309,1,1,0,0,-11516.86,-1604.25,41.38264,5.288348,7200,0,0,1,0,0,0,0,0);
