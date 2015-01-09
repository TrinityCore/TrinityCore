SET @OGUID := 5495;
DELETE FROM `gameobject` WHERE `guid`=@OGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,201818,631,15,1,4149.65,2779.59,350.962,0,604800,0,1);
