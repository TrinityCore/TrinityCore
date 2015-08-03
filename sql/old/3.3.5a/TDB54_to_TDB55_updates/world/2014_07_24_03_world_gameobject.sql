--
SET @OGUID := 5417;
DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 178404, 1, 1, 1, -1382.071, 2918.795, 73.20731, 2.809975, 0, 0, 0, 1, 120, 255, 1); -- 178404 (Area: 607)
