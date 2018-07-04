--
SET @OGUID := 200630;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID,203957, 0, 40, 111, 1, 169, -9848.62, 1390.5, 38.0731, 3.92641, 0, 0, 0.92399, -0.382416, 300, 255, 1);
