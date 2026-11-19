-- 
SET @OGUID := 200629;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`PhaseId`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID,195206,1,1,169,-1161.73, -3605.03, 93.5951, -1.58825,0, 0, -0.71325, 0.70091, 300, 100, 1);
