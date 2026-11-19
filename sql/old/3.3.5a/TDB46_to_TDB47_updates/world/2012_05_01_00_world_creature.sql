-- Add missing Challe & Orphan Matron Aria Spawns
SET @GUID := 41876;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+1;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,23101,530,1,1,0,0,-480.4989,7499.029,181.2889,3.560472,120,0,0,1,0,0),
(@GUID+1,34365,571,1,1,0,0,5716.604,642.8611,646.2927,5.88176,120,0,0,1,0,0);
-- Add to game event creature
DELETE FROM `game_event_creature` WHERE `guid`=@GUID+1;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES (10,@GUID+1);
