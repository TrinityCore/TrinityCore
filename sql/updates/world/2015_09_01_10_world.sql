--
SET @CGUID := 86054; -- 86059 to 86064 free
SET @OLDCGUID := 104;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 20869, 552, 3, 1, 264.2865, -61.32112, 22.45335, 5.288348, 7200, 0, 0),
(@CGUID+1, 20869, 552, 3, 1, 336.5143, 27.42666, 48.42604, 3.839724, 7200, 0, 0),
(@CGUID+2, 20869, 552, 3, 1, 253.942, 131.8811, 22.39496, 0.7679449, 7200, 0, 0),
(@CGUID+3, 20869, 552, 3, 1, 255.4978, 158.9143, 22.36194, 5.410521, 7200, 0, 0),
(@CGUID+4, 20869, 552, 3, 1, 395.413, 18.19484, 48.29602, 2.495821, 7200, 0, 0);
