SET @CGUID := 370837;
SET @OGUID := 233411;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 19007, 530, 1, -278.1424, 936.0903, 84.46306, 5.337643, 120, 0, 0),
(@CGUID+1, 19007, 530, 1, -272.0104, 926.9375, 84.46307, 2.178597, 120, 0, 0),
(@CGUID+2, 19006, 530, 1, -217.7188, 934.5504, 84.46307, 4.108852, 120, 0, 0),
(@CGUID+3, 19006, 530, 1, -225.4236, 926.5052, 84.46307, 0.722914, 120, 0, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 195139, 530, 1, -274.9913, 931.8889, 84.37974, 0.2412808, 0, 0, 0, 1, 120, 255, 1),
(@OGUID+1, 195140, 530, 1, -221.974, 931.4427, 84.37974, 2.276257, 0, 0, 0, 1, 120, 255, 1);

UPDATE `creature_template_addon` SET `auras`='32783' WHERE `entry` IN (19006, 19007);
