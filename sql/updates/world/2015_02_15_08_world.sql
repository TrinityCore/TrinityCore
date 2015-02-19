-- Infiltrator Marksen SAI
SET @ENTRY := 5416;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,1391,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Quest 'Nothing But The Truth' Finished - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Just Died - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 541600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Say Line 3"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,3,0,10973,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Morph To Model 10973"),
(@ENTRY,9,5,0,0,0,100,0,100,100,0,0,89,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Start Random Movement"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infiltrator Marksen - On Script - Kill Self");

DELETE FROM `creature_text` WHERE `entry`=5416;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(5416, 0, 0, '%s takes a big swig of ale.', 16, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019),
(5416, 1, 0, 'That was refreshing. Now there\'s information that needs to be told...', 12, 0, 100, 1, 0, 0, 'Infiltrator Marksen',18019),
(5416, 2, 0, 'I believe the Forsaken are misleading the allies of the Horde.... wait... I feel so... dizzy...', 12, 0, 100, 1, 0, 0, 'Infiltrator Marksen',18019),
(5416, 3, 0, '%s writhes in pain.', 16, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019),
(5416, 4, 0, 'AAAAAAAAAAAAAAAAARGH!', 12, 0, 100, 0, 0, 0, 'Infiltrator Marksen',18019);
