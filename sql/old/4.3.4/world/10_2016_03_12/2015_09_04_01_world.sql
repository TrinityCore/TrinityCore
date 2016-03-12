--
SET @CREATURE_GUID := 85701; -- set by TDB team
DELETE FROM `creature` WHERE `guid` IN (222,223,224);
DELETE FROM `creature` WHERE `guid` IN (85701,85702,85707);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Spawn fire dummys for fire effigys
(@CREATURE_GUID+00,23537,530,1,1,0,0,-4192.38,-12268.1,2.53389,-1.72788,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+01,23537,530,1,1,0,0,-4207.84,-12276.7,4.82085,-0.069813,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+06,23537,530,1,1,0,0,9235.05,-6783.4,26.4426,1.5708,300,0,0,15260,0,0,0,0,0);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+12;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 222 AND 224;
INSERT INTO `game_event_creature` VALUES
(12,@CREATURE_GUID+00),
(12,@CREATURE_GUID+01),
(12,@CREATURE_GUID+06);
