-- 
SET @GUID  =6028;
UPDATE `gameobject` SET `spawnMask`=24, `spawntimesecs`=604800 WHERE `guid`=55974;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`PhaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)VALUES 
(@GUID, 195036, 603, 24, 0, 1757.896, 87.201, 342.384, 0.649495, 0, 0, 0, 1, 604800, 255, 1);
