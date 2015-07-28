-- Ilthalaine spawn(s)
SET @CGUID := 271995; -- Set by TC
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 2079, 1, 1, 1, 10312.7, 830.1215, 1326.533, 2.373648, 120, 0, 0); -- 2079 (Area: 188)
