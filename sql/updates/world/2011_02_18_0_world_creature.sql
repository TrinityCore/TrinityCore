SET @GUID := 137743;
DELETE FROM `creature` WHERE `id` IN (38471,38501,38551);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,38471,631,15,1,0,0,-504.949,2184.24,62.3048,0.450047,86400,0,0,0,0,0,0,0,0,0),
(@GUID+1,38501,631,15,1,0,0,4247.040,2753.25,348.996,0.227759,86400,0,0,0,0,0,0,0,0,0),
(@GUID+2,38551,631,15,1,0,0,4466.260,2787.99,348.954,3.349720,86400,0,0,0,0,0,0,0,0,0);
