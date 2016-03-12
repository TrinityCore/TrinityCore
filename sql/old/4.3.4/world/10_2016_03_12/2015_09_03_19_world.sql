--
DELETE FROM `creature` WHERE `guid` IN (144231,144232,144233);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(144231, 30382, 571, 0, 0, 1, 1, 0, 0, 7525.7, -971.724, 478.799, 5.63741, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(144232, 30383, 571, 0, 0, 1, 1, 0, 0, 7515.81, -975.284, 467.498, 3.85718, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(144233, 30401, 571, 0, 0, 1, 1, 0, 0, 6647.17, -310.257, 989.53, 1.2511, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
