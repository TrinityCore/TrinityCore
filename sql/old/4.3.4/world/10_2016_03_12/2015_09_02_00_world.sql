--
SET @CGUID := 40267; -- Set by TDB Team
SET @OLDCGUID := 128; -- 4.x
DELETE FROM `creature` WHERE `guid`=@CGUID;
DELETE FROM `creature` WHERE `guid`=@OLDCGUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID,29255,571,1,1,5900.299,505.75,641.6531,4.171337,120,0,0);
