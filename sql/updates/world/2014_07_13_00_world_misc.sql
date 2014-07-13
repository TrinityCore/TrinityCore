--
SET @OGUID := 5414;

DELETE FROM `gameobject` WHERE `guid` = @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 179345, 369, 1, 1, 57.43581, 1206.985, -121.5893, -2.652894, 0, 0, 0, 1, 7200, 255, 1);
