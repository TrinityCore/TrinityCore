--
SET @Guid:=6177;
DELETE FROM `gameobject` WHERE `guid` IN (@Guid+0, @Guid+1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@Guid+0, 201888, 631, 0, 0, 15, 1, 4312.29, 3025.22, 360.518, 2.92954, 0, 0, 0.994384, 0.105829, 604800, 0, 1, 0),
(@Guid+1, 201889, 631, 0, 0, 15, 1, 4403.27, 3027.19, 360.52, 0.0274907, 0, 0, 0.0137449, 0.999906, 604800, 0, 1, 0);
