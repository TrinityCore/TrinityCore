-- NPC entry 40405 Kieupid, Pet Trainer in Silvermoon City (map: 530, zone ID 0, area ID 0)
SET @CGUID = 12547;

DELETE FROM `creature` WHERE `id` = 40405;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(@CGUID,40405,530,0,0,1,1,0,0, 9924.067, -7400.503, 13.71723, 6.073746, 120,0,0,0,0,0,0,0,0,12340);
