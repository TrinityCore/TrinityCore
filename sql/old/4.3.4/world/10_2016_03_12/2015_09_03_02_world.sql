--
SET @CGUID:= 42568;
SET @ENTRY:= 24137; -- Dark Ranger Marrah

DELETE FROM `creature` WHERE `id` = @ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, @ENTRY, 574, 3, 1, 183.8515, -76.50119, 15.84287, 3.455082, 7200, 0, 0);
