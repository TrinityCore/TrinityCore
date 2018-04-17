-- 
DELETE FROM `gameobject` WHERE `guid` IN (200003,200004,200005,200006);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(200003, 204284, 0, 4922, 5470, 1, 1, 169, 0, -8597.54, 1355.16, -56.1717, 0.7853968, 0, 0, 0.3826828, 0.9238798, 120, 255, 1, 26365), -- Stormwind Lobster Trap (Area: Victor's Point - Difficulty: 0)
(200004, 205144, 0, 4922, 5470, 1, 1, 169, 0, -8445.49, 1226.98, 5.23025, 2.687807, 0, 0, 0.97437, 0.2249513, 120, 255, 1, 26365), -- Missing Parts (Area: Victor's Point - Difficulty: 0)
(200005, 205144, 0, 4922, 5470, 1, 1, 169, 0, -8448.61, 1213.67, 5.14314, 0, 0, 0, 0, 1, 120, 255, 1, 26365), -- Missing Parts (Area: Victor's Point - Difficulty: 0)
(200006, 205144, 0, 4922, 5470, 1, 1, 169, 0, -8442.75, 1187.77, 5.83535, 0, 0, 0, 0, 1, 120, 255, 1, 26365); -- Missing Parts (Area: Victor's Point - Difficulty: 0)

DELETE FROM `creature` WHERE `guid`=252243 AND `id`=29712 AND `VerifiedBuild`=26365;
UPDATE `creature` SET `guid`=252243 WHERE `guid`=313754;
