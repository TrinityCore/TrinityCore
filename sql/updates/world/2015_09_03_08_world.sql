--
SET @GUID := 43492;

DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`) VALUES
(@GUID,22919,530,3866.55,5978.68,291.792,4.10061,300,6986);
