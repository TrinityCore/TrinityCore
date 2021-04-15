SET @GUID := 137789;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,16980,631,15,1,0,0,4203.70,2484.83,364.956,3.14159,604800,0,0,0,0,0,0,0,0,0), -- The Lich King
(@GUID+1,22515,631,15,1,0,0,4241.19,2557.49,364.952,4.72984,120,0,0,0,0,0,0,0,0,0), -- World Trigger
(@GUID+2,22515,631,15,1,0,0,4241.34,2411.52,364.952,1.57080,120,0,0,0,0,0,0,0,0,0), -- World Trigger
(@GUID+3,22515,631,10,1,0,0,4166.02,2557.49,364.952,4.72984,120,0,0,0,0,0,0,0,0,0), -- World Trigger
(@GUID+4,22515,631,10,1,0,0,4241.34,2411.52,364.952,1.57080,120,0,0,0,0,0,0,0,0,0); -- World Trigger
