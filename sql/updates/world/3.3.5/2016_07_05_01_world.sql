SET @CGUID := 11003;

DELETE FROM `creature` WHERE `id`=40146;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 40146, 724, 0, 0, 15, 33, 0, 0, 3156.037, 533.2656, 72.97205, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 0);
