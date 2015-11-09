-- Dark Iron Brewer
SET @GUID := 12482;
DELETE FROM `creature` WHERE `guid`= @GUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,28067,230,1,1,0,0,891.271,-174.899,-43.925,0.445,180,0,0,2215,0,0);
