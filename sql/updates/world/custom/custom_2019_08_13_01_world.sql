SET @OGUID := 237861;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 207372, 1, 5034, 0, 1, 169, 0, -11519.77, -2315.382, 608.416, 0.7077773, 0, 0, 0.3465481, 0.9380322, 120, 255, 1, 26654), -- Instance Portal
(@OGUID+1, 207373, 1, 5034, 0, 1, 169, 0, -11519.77, -2315.382, 608.416, 0.7077773, 0, 0, 0.3465481, 0.9380322, 120, 255, 1, 26654), -- Instance Portal
(@OGUID+2, 207307, 1, 5034, 0, 1, 169, 0, -11547.67, -2338.366, 625.5492, 3.83829, 0, 0, -0.9399376, 0.3413463, 120, 255, 1, 26654); -- Meeting Stone
