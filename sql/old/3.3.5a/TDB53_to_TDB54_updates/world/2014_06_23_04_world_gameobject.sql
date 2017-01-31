--
SET @GUID1 := 5380; -- Set by TDB team

DELETE FROM `gameobject` WHERE (`guid`=@GUID1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID1, 180659, 1, 1, 1, 5086.19, -5116.32, 931.162, 4.78877, 0, 0, 0.679593, -0.733589, -150, 0, 1);
