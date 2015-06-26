SET @GUID := 325984;

DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `SpawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 20212, 642, 3, 0, 7.305609, -0.095246, 34.51022, 3.159046, 7200, 0, 0),
(@GUID+1, 20213, 641, 3, 0, 11.69965, 0.034146, 20.62076, 3.211406, 7200, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@GUID, '66656'), -- Parachute
(@GUID+1, '66656'); -- Parachute
