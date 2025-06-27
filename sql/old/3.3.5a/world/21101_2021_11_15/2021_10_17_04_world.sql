--
DELETE FROM `gameobject` WHERE `guid` IN (81120,81129,81155) AND `id` BETWEEN 123215 AND 123217;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(81120, 123215, 0, 1, 0, 1, 1, -4020.328125, -1407.0064697265625, 155.45361328125, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 12340), -- 123215 (Area: 0 - Difficulty: 0)
(81129, 123216, 0, 1, 0, 1, 1, -4020.04638671875, -1407.160888671875, 155.462860107421875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 12340), -- 123216 (Area: 0 - Difficulty: 0)
(81155, 123217, 0, 1, 0, 1, 1, -4020.05029296875, -1407.00830078125, 155.43743896484375, 0.008724239654839038, 0, 0, 0.004362106323242187, 0.999990463256835937, 120, 255, 1, 12340); -- 123217 (Area: 0 - Difficulty: 0)
