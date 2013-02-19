SET @GUID := 95035 ; -- set guid by TDB

-- Spawn for Rotting Frost Giant in 25 man instances
DELETE FROM `creature` WHERE `id`=38494;
INSERT INTO `creature`
(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES
(@GUID,38494,631,10,1,0,0,-452.366,2354.51,191.242,0.778178,86400,0,0,1,0,0,2,0,0,0);

-- Correct spawn mask for Rotting Frost Giant in 10 man instances (10/10 Heroic)
UPDATE `creature` SET `spawnmask`=5 WHERE `id`=38490;

-- add a path to the creature
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID,2087860,0,0,0,0, '');
