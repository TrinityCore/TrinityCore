-- 
-- [Q] The Ward of Wakening -- http://wotlk.openwow.com/quest=10961
-- Morthis Whisperwing SAI
SET @ENTRY := 22832;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,10961,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Quest 'The Ward of Wakening' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,10961,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Morthis Whisperwing - On Quest 'The Ward of Wakening' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 2283200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,90,8,0,0,0,0,0,0,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,91,8,0,0,0,0,0,0,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Set Remove Standstate Kneel"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,3,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Say Line 3"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Morthis Whisperwing - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=22832;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(22832, 0, 0, 'There are few left in the world who can prepare the Ward of Waking, $N. We are fortunate that I am among them.', 12, 0, 100, 1, 0, 0, 20516, 'Morthis Whisperwing'),
(22832, 1, 0, '%s kneels, filling the vial with water from the moonwell.', 16, 0, 100, 0, 0, 0, 20512, 'Morthis Whisperwing'),
(22832, 2, 0, '%s combines the herbs with the moonwell water to create the Ward of Waking', 16, 0, 100, 0, 0, 0, 20517, 'Morthis Whisperwing'),
(22832, 3, 0, 'The potion is finished. I can only hope Clintar forgives us for interrupting his sojourn in the Emerald Dream.', 12, 0, 100, 1, 0, 0, 20513, 'Morthis Whisperwing');
