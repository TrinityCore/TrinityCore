--
SET @CGUID := 49137;
DELETE FROM `creature` WHERE `guid` IN (@CGUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 30142, 571, 1, 1, 8392.7, -1970.14, 1461.84, 0.0948219, 600, 0, 0);

SET @OGUID := 5501;
DELETE FROM `gameobject` WHERE `guid`= @OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `rotation2`, `rotation3`, `animprogress`, `state`) VALUES
(@OGUID, 192243, 571, 1, 1, 8531.9, -1971.44, 1467.57, -0.837757, 300, -0.406736, 0.913546, 100, 1);

UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=29730;
