-- A Cleansing Song (12735)
SET @KOOSU        := 29034;
SET @HA_KHALAN    := 29018;
SET @ATHA         := 29033;

-- Spirit of Koosu
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@KOOSU;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@KOOSU;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@KOOSU;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KOOSU,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu - Set Phase 1 - on Aggro'),
(@KOOSU,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu -  Stop Moving - on Aggro'),
(@KOOSU,0,2,0,4,1,100,1,0,0,0,0,11,21971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Spirit of Koosu - Cast bolt - on Aggro'),
(@KOOSU,0,3,0,9,1,100,0,5,30,3500,4100,11,21971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Spirit of Koosu - Cast bolt - In Range'),
(@KOOSU,0,4,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu -  Start Moving - When not in bolt Range'),
(@KOOSU,0,5,0,9,1,100,0,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu - Stop Moving - 15 Yards'),
(@KOOSU,0,6,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu - Start Moving - when not in bolt Range'),
(@KOOSU,0,7,0,9,1,100,0,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Koosu - Stop Moving - when in bolt Range');

-- Spirit of Ha-Khalan
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@HA_KHALAN;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@HA_KHALAN;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@HA_KHALAN;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HA_KHALAN,0,0,0,0,0,100,0,1000,1000,125000,125000,11,50502,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Ha-Khalan - IC - Cast Thick Hide'),
(@HA_KHALAN,0,1,0,0,0,100,0,5000,10000,12000,16000,11,34370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Spirit of Ha-Khalan - IC - Cast Jagged Tooth Snap'),
(@HA_KHALAN,0,2,0,0,0,100,0,3000,5000,7000,11000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Spirit of Ha-Khalan - IC - Cast Powerful Bite');

-- Spirit of Atha
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ATHA;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ATHA;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ATHA;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ATHA,0,0,0,0,0,100,0,8000,13000,12000,16000,11,21790,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Atha - IC - Cast Aqua Jet'),
(@ATHA,0,1,0,0,0,100,0,2000,4000,5000,7000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Atha - IC - Cast Thrash');

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|8 WHERE `entry`=29018; -- Spirit of Ha-Khalan
-- Addon data for creature 29018 (Spirit of Ha-Khalan)
DELETE FROM `creature_template_addon` WHERE `entry`=29018;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29018,0,0,1,0,''); -- Spirit of Ha-Khalan
