--
-- Borean Tundra visual improvement and missing spawn
SET @GOGUID :=356; -- need 1 set by TDB
SET @OLDGOGUID :=18; -- 4.x
SET @GUID :=43460; -- need 3 set by TDB
SET @OLDGUID :=125; -- 4.x

DELETE FROM `gameobject` WHERE `guid`=@GOGUID;
DELETE FROM `gameobject` WHERE `guid`=@OLDGOGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GOGUID,187879,571,1,1,4207.366,4056.894,91.62077,2.792518,0,0,0.984807,0.1736523,300,100,1);

DELETE FROM `creature` WHERE `guid` in (@GUID+0,@GUID+1,@GUID+2);
DELETE FROM `creature` WHERE `guid` in (@OLDGUID+0,@OLDGUID+1,@OLDGUID+2);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,24021,571,1,1,21999,0,4207.475,4056.687,93.53715,2.094395,300,0,0,42,0,0,0,0,0),
(@GUID+1,23837,571,1,1,11686,0,4207.471,4056.705,93.66189,3.979351,300,0,0,42,0,0,0,0,0),
(@GUID+2,24957,571,1,1,0,0,4200.877,4056.888,92.28766,6.25263,300,0,0,7185,7196,0,0,0,0);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID+0,@GUID+1);
DELETE FROM `creature_addon` WHERE `guid` IN (@OLDGUID+0,@OLDGUID+1);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@GUID+0,0,0,1,'45797'),
(@GUID+1,0,0,1,'45797');
