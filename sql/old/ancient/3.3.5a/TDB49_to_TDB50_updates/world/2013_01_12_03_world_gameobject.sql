-- Add missing doors to mechanar
SET @GUID := 6032;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(@GUID,184632,554,3,1,236.4597,52.36356,1.653544,3.141593,0,0,-1,0,120,0,1),
(@GUID+1,184322,554,3,1,242.874,52.314810,1.596334,3.141593,0,0,-1,0,120,0,1),
(@GUID+2,184449,554,3,1,267.9281,52.31481,27.04254,3.141593,0,0,-1,0,120,0,1);
