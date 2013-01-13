-- Remove Incorrect Aggro Text actions from EAI
DELETE FROM creature_ai_scripts WHERE action1_type=1 AND creature_id IN (203,1564,3198,16873,1097,2554,2587,8566);

-- Remove old Azgalor text
DELETE FROM creature_ai_texts WHERE `comment`=17842;

-- Remove old Rage Winterchill text
DELETE FROM creature_ai_texts WHERE `comment`=17767;

-- SAI for Spectral Servant
SET @ENTRY := 16407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29540,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spectral Servant - On Aggro - Cast Curse of Past Burdens'),
(@ENTRY,0,1,0,0,0,70,0,12000,12000,30000,30000,11,29540,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spectral Servant - Combat - Cast Curse of Past Burdens'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Spectral Servant - On Death - Say random text');

-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -45 AND -43;
DELETE FROM `creature_text` WHERE `entry` IN (16407);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16407,0,0, 'No!',14,0,100,0,0,0, 'Spectral Servant - On Death Say'),
(16407,0,1, 'I am finished!',12,0,100,0,0,0, 'Spectral Servant - On Death Say'),
(16407,0,2, 'The master... will be angry...',12,0,100,0,0,0, 'Spectral Servant - On Death Say');
