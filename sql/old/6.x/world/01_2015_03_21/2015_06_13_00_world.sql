SET @GUID := 325984;

DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `SpawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID, 20212, 642, 3, 0, 0, 0, 7.305609, -0.095246, 34.51022, 3.159046, 7200, 0, 0),
(@GUID+1, 20213, 641, 3, 0, 0, 0, 11.69965, 0.034146, 20.62076, 3.211406, 7200, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@GUID, 66656), -- Parachute
(@GUID+1, 66656); -- Parachute

DELETE FROM `trinity_string` WHERE `entry` IN (1999, 1204, 1205);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1999, 'You have left areatrigger %u.'),
(1204, 'You have entered areatrigger %u.'),
(1205, 'The battle will begin in 2 minutes.');
