--
SET @guid:=235190;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @guid+0 AND @guid+2;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@guid+0, 207389, 329, 3, 169, 3457.544, -3106.003, 137.8965, 1.902409, 0, 0, 0, 1, 7200, 255, 1), -- 207389 (Area: 0)
(@guid+1, 182187, 0, 1, 169, -11369.6, -2163.95, 24.3, 0, 0, 0, 0, 180, 0, 1, 0),
(@guid+2, 182187, 0, 1, 169, -11170.3, -1900.21, -17.78, 0, 0, 0, 0, 180, 0, 1, 0);
