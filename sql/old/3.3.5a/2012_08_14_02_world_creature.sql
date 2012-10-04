SET @GUID := 42613;
SET @ENTRY := 28114; -- Mistcaller Soo-gan

DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,@ENTRY,571,1,1,0,0,6165.004,5092.975,-97.29356,0.7504916,120,0,0,117700,3809,0);

DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@ENTRY,0,0,0x10000,0x1,0,'51589 52215');

UPDATE `creature_template` SET `npcflag`=`npcflag` |1 WHERE `entry`=@ENTRY;
