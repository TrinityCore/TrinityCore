--
SET @DAY = 86400;
SET @CGUID = 111214; -- creature GUIDs (4 creature);
DELETE FROM `creature` WHERE `guid` BETWEEN 700300 AND 700303;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+03;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+00, 27915, 595, 3, 1, 1813.298, 1283.578, 142.3258, 3.878161, @DAY, 0, 0),
(@CGUID+01, 28340, 595, 3, 1, 2398.715, 1207.334, 134.1223, 5.270895, @DAY, 0, 0),
(@CGUID+02, 28340, 595, 3, 1, 2401.265, 1202.789, 134.1039, 1.466077, @DAY, 0, 0),
(@CGUID+03, 28341, 595, 3, 1, 2402.654, 1205.786, 134.1223, 2.897247, @DAY, 0, 0);
