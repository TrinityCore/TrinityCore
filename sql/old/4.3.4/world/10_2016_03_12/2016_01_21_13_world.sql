--
SET @OGUID := 21622;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 202211, 668, 4820, 4820, 3, 1, 5242.83, 1623.45, 784.15, 5.81195, 0, 0, 0, 1, -7200, 255, 1, 15595),
(@OGUID+1, 202211, 668, 4820, 4820, 3, 1, 5225.2, 1589.1, 808.551, 5.81195, 0, 0, 0, 1, -7200, 255, 1, 15595),
(@OGUID+2, 202211, 668, 4820, 4820, 3, 1, 5233.98, 1606.31, 796.254, 5.81195, 0, 0, 0, 1, -7200, 255, 1, 15595);
