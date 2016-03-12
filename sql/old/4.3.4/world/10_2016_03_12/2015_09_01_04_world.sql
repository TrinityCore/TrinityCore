--
SET @CGUID = 950;
SET @OLDCGUID = 1;
DELETE FROM `creature` WHERE `guid` = @CGUID;
DELETE FROM `creature` WHERE `guid` = @OLDCGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 37552, 530, 1, 1, 11792.01, -7065.793, 25.94043, 5.009095, 120, 0, 0);
