--
SET @GUID=18; -- Set by TDB team
SET @OLDGUID=115; -- Set by TDB team (4.x changed)

-- Sergeant Kregga (31440)
DELETE FROM `creature` WHERE `guid`=@GUID AND `id`=31440;
DELETE FROM `creature` WHERE `guid`=@OLDGUID AND `id`=31440;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,31440,571,1,8,0,0,5874.2,1948.5,516.1,2.8,300,0,0,32000,0,0,0,0,0);
