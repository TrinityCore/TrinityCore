--
SET @GUID := 52323;
SET @pool_id := 1107;

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID+0, 18684, 530, 1, 1, 0, 0, -1768.23, 6737.47, -21.3348, 6.18901, 28800, 15, 9784, 5692, 1),
(@GUID+1, 18684, 530, 1, 1, 0, 0, -2585.25, 6416.29, 26.8608, 5.44446, 28800, 15, 9784, 5692, 1),
(@GUID+2, 18684, 530, 1, 1, 0, 0, -2002.52, 7622.98, -88.0942, 5.61332, 28800, 15, 9784, 5692, 1),
(@GUID+3, 18684, 530, 1, 1, 0, 0, -1200.42, 8810.52, 41.1305, 4.35118, 28800, 15, 9784, 5692, 1);

DELETE FROM `pool_template` WHERE `entry` = @pool_id;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id, 1, 'Bro''Gaz the Clanless');

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID+0, @pool_id, 0, 'Bro''Gaz the Clanless - Spawn 1'),
(@GUID+1, @pool_id, 0, 'Bro''Gaz the Clanless - Spawn 2'),
(@GUID+2, @pool_id, 0, 'Bro''Gaz the Clanless - Spawn 3'),
(@GUID+3, @pool_id, 0, 'Bro''Gaz the Clanless - Spawn 4');

SET @ENTRY := 18684;
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=0 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,7000,10000,16000,11,12468,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bro''Gaz the Clanless - IC - Cast Flamestrike'),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,12000,15000,11,15586,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bro''Gaz the Clanless IC - Cast heal'),
(@ENTRY,0,2,0,0,0,100,0,6000,10000,9000,10000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bro''Gaz the Clanless IC - Cast Pummel');
