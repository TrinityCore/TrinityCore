--
SET @CGUID := 86442;
DELETE FROM `creature` WHERE `guid` IN (549,550,86442,86443);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 26806, 571, 1, 1, 4668.349, -4849.098, 35.56351, 3.106686, 300, 0, 0),
(@CGUID+1, 26806, 571, 1, 1, 4669.264, -4869.123, 35.5635, 3.263766, 300, 0, 0);
