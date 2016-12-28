/*
--
-- [Q] Felbound Ancients -- http://wotlk.openwow.com/quest=4441
-- Eridan Bluewind SAI
SET @ENTRY := 9116;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,4441,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Quest 'Felbound Ancients' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 911600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.59669,"Eridan Bluewind - On Script - Set Orientation 2,59669"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,11,28892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Script - Cast 'Nature Channeling'"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.72271,"Eridan Bluewind - On Script - Set Orientation 2,72271"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eridan Bluewind - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `entry`=9116;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(9116, 0, 0, 'May this evil aura be banished from this artifact!', 12, 0, 100, 0, 0, 0, 8366, 'Eridan Bluewind'),
(9116, 1, 0, 'I can feel the presence of evil leaving...', 12, 0, 100, 0, 0, 0, 8367, 'Eridan Bluewind');
*/
