-- Historian Karnik SAI
SET @ENTRY := 2916;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,724,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Quest 'Prospect of Faith' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 291600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,2915,3,25000,0,0,0,8,0,0,0,-4633.1416,-1324.990,503.3826,5.41487,"Historian Karnik - On Script - Summon Creature 'Hammertoe's Spirit'"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,2915,20,0,0,0,0,0,"Historian Karnik - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,2915,20,0,0,0,0,0,"Historian Karnik - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Historian Karnik - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `entry` IN (2916, 2915);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(2915, 0, 0, 'Karnik, me friend, I wish I could see you with me own eyes again, but we need''ta talk of Ragnaros. His influence is spreading.', 12, 0, 100, 0, 0, 0, 916, 'Hammertoe''s Spirit'),
(2915, 1, 0, 'I''ll tell you more, Karnik, in time. But first, send this traveler''ta Belgrum--there''s more business''ta attend to.', 12, 0, 100, 0, 0, 0, 918, 'Hammertoe''s Spirit'),
(2916, 0, 0, 'Ragnaros? Terrible news indeed...', 12, 0, 100, 0, 0, 0, 956, 'Historian Karnik'),
(2916, 1, 0, 'You heard him, traveler. Speak to me again when you''re ready to speak to Belgrum.', 12, 0, 100, 0, 0, 0, 958, 'Historian Karnik');
