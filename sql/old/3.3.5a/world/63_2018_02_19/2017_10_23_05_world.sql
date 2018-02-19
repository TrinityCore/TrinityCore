--
SET @OGUID:=970;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, 192612, 530, 3433, 3509, 1, 1, 7567.479, -7359.604, 161.8884, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 14545); -- 192612 
DELETE FROM `gameobject_addon` WHERE `guid`=@OGUID;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID, 0, 0, 0.9999619, -0.00872653); -- 192612
