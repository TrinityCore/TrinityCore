-- Add Missing Ice Wall, Pit of Saron
SET @GUID := 305;
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,201885,658,3,1,932.2674,-80.6684,591.6761,2.286379,0,0,0,0,300,100,1);
