--
SET @OGUID := 6409;
DELETE FROM `gameobject` WHERE `guid` IN (@OGUID+0,@OGUID+1,@OGUID+2,@OGUID+3);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,193988,615,3,1,3246.47,515.266,58.6196,1.54789,0,0,0.698963,0.715158,-300,0,1),
(@OGUID+1,193988,615,3,1,3154.78,515.889,90.9767,3.18872,0,0,0.999722,-0.0235612,-300,0,1),
(@OGUID+2,193988,615,3,1,3216.13,648.325,87.0783,0.693027,0,0,0.339621,0.940562,-300,0,1),
(@OGUID+3,193988,615,3,1,3383.81,532.522,96.971,3.43866,0,0,0.988989,-0.147986,-300,0,1);
