-- 
DELETE FROM `gameobject` WHERE `guid` IN (9375,9378);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9375, 185116, 548, 3607, 0, 1, 1, 348.987, -684.119, -12.39, 0.004, 0, 0, -0.00199676, -0.999998, 300, 0, 1, 15595), -- 184571 (Area: 0 - Difficulty: 0)
(9378, 184956, 548, 3607, 0, 1, 1, 38.6884, -418.089, -19.8813, 5.53269, 0, 0, -1, 0, 10, 0, 1, 15595); -- 184571 (Area: 0 - Difficulty: 0)
