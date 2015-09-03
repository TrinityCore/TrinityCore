--
SET @GUID := 68274;
SET @OLDGUID := 656;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDGUID AND @OLDGUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+1,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+2,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+3,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+4,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0);
