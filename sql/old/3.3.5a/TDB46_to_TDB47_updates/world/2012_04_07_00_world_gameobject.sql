UPDATE `gameobject_template` SET `faction`=54 WHERE `entry`=178164;
SET @GUID := 247;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,178164,409,1,1,736.6528,-1176.32,-118.0967,-0.6806787,0,0,0,1,120,255,1); -- Hot Coal, damage
