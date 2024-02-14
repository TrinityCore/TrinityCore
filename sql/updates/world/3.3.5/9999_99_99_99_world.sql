SET @GUID := 11011; -- (unused GUID from TDB 335.24011)

DELETE FROM `gameobject` WHERE `guid` = @GUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES 
(@GUID, 149431, 109, 0, 0, 1, 1, -518.154, -85.2353, -74.488, 3.14159, -0, -0, -1, -0.00000126759, 43200, 100, 1, '', 0);
