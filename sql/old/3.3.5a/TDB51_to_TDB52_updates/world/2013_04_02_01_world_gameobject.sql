SET @OGUID := 1160;

DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 202275, 530, 1, 1, -2186.307, -12341.81, 56.27893, 0, 0, 0, 0, 1, 120, 255, 1); -- Wrathscale Fountain
