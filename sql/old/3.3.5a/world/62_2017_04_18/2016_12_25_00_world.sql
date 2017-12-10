-- 
-- [Q] Into the Churning Gulch -- http://wotlk.openwow.com/quest=10715
-- Baron Sablemane SAI
SET @ENTRY := 22103;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,10715,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Quest 'Into the Churning Gulch' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 2210300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2915.57,5957.42,3.27419,2.97874,"Baron Sablemane - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Set Emote State 69"),
(@ENTRY,9,4,0,0,0,100,0,7000,7000,0,0,17,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Set Emote State 26"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2919.11,5956.93,3.16149,1.03933,"Baron Sablemane - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,2919.11,5956.93,3.16149,1.58825,"Baron Sablemane - On Script - Move To Position"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Add Npc Flag Questgiver"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Sablemane - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=22103;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(22103, 0, 0, 'There, it is completed.', 12, 0, 100, 0, 0, 0, 19808, 'Baron Sablemane');
