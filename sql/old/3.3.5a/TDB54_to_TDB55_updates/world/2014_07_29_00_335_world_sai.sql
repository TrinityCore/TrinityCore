SET @CGUID  := 45215;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 28355, 0, 1, 1,  -8670.599, 427.4635, 100.9918, 0.9599311, 120, 0, 0), 
(@CGUID+1, 28347, 0, 1, 1,  -8672.78, 430.8922, 100.9918, 0.6632251, 120, 0, 0); 
