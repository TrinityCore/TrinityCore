-- SAI for Rhahk'Zor
SET @ENTRY := 644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rhahk''Zor - On Aggro - Say text'),
(@ENTRY,0,1,0,0,0,100,2,800,8500,17000,27200,11,6304,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rhahk''Zor - Combat - Cast Battle Shout'),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,34,1,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Rhahk''Zor - On Death - Set Instance Data');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry=-22;
DELETE FROM `creature_text` WHERE `entry` IN (644);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(644,0,0, 'VanCleef pay big for your heads!',14,0,100,0,0,5774, 'Rhahk''Zor - Aggro Say');
