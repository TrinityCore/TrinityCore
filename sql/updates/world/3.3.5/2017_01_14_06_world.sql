-- Jessera of Mac'Aree SAI
SET @ENTRY := 17663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,60000,60000,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Jessera of Mac'Aree - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=17663;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(17663, 0, 0, 'If only I could get back to the mushroom thicket. I have not seen such a mature cluster in my lifetime!', 12, 7, 100, 0, 0, 0, 14269, 'Jessera of Mac''Aree');

-- Messenger Hermesius SAI
SET @ENTRY := 17703;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,25000,20000,25000,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Messenger Hermesius - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=17703;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(17703, 0, 0, 'Don\'t you people ever check the mail?', 12, 7, 100, 0, 0, 0, 14328, 'Messenger Hermesius'),
(17703, 0, 1, 'How am I expected to deliver all of these messages?', 12, 7, 100, 0, 0, 0, 14329, 'Messenger Hermesius'),
(17703, 0, 2, 'I need to be re-assigned. This job is pushing me over the edge...', 12, 7, 100, 0, 0, 0, 14330, 'Messenger Hermesius'),
(17703, 0, 3, 'He thinks he''s so damned important. Always pushing me around... I''ll show him. I''ll show all of them!', 12, 7, 100, 0, 0, 0, 14332, 'Messenger Hermesius'),
(17703, 0, 4, 'One of these days I''m going to bust out the crystalline doomhammer and go positively orc on this town. Then they''ll be sorry...', 12, 7, 100, 0, 0, 0, 14331, 'Messenger Hermesius');
