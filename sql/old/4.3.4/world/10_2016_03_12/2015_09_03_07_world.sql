--
SET @Thane :=    26405;
SET @Guid :=     43467;

DELETE FROM `creature` WHERE `id`=@Thane;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)  VALUES
(@Guid,@Thane ,571,1,1,0,1,3317.76,-5112.08,300.462,1.78269,300,0,0,12762,3561,0,0,0,0); -- spawn NPC if there isn't, GUID is random
