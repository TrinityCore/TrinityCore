SET @OGUID          := 250000;

DELETE FROM `gameobject` WHERE `id`=209849;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 209849, 757, 1, 1, 386.859, 1337.48, 170.1612, 1.570796, 0, 0, 1, -4.371139E-08, 7200, 255, 0);