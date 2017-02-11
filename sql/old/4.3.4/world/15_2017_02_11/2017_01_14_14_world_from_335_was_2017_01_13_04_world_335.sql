/*
-- The Demon Seed -- http://wotlk.openwow.com/quest=924
-- Ak'Zeloth SAI
SET @ENTRY := 3521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,924,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ak'Zeloth - On Quest 'The Demon Seed' Taken - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,924,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ak'Zeloth - On Quest 'The Demon Seed' Taken - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 352100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.115413,"On Script - Set Orientation 0,115413"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,6000,0,0,0,0,12,1,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.305800,"On Script - Set Orientation 5,305800");

DELETE FROM `creature_text` WHERE `entry`=3521;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(3521, 0, 0, 'Take a stone from the table, $n.  You will need it for your quest.', 12, 1, 100, 25, 0, 0, 1115, 'Ak''Zeloth');
*/
