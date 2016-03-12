--
DELETE FROM `creature` WHERE `guid` in (43495,43497,43499,43500);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(43495, 26500, 571, 0, 0, 1, 1, 0, 0, 3386.27, -1805.43, 115.444, 4.93928, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43497, 26543, 571, 0, 0, 1, 1, 0, 0, 4243.96, -2024.81, 238.249, 1.41171, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43499, 26701, 571, 0, 0, 1, 1, 0, 0, 4523.89, -3472.86, 228.244, 4.69546, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43500, 26787, 571, 0, 0, 1, 1, 0, 0, 4599.71, -4876.9, 48.9556, 0.719772, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
