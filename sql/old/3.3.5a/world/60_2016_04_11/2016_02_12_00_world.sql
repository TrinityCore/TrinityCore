-- 
-- Spawn creature ID 16399 Bloodsail Traitor:
SET @CGUID := 1528; -- selected by TC team

DELETE FROM `creature` WHERE `id` = 16399;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(@CGUID, 16399, 0, 0, 0, 1, 1, 2557, 1, -14184.4, 192.764, 20.6905, 3.735, 300, 0, 0, 2059, 0, 0, 0, 0, 0, 0);
