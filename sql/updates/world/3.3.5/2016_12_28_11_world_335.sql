-- [Q] Vyletongue Corruption -- http://wotlk.openwow.com/?quest=7029
-- Vark Battlescar SAI
SET @ENTRY := 11823;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,7029,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vark Battlescar - On Quest 'Vyletongue Corruption' Taken - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,7029,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vark Battlescar - On Quest 'Vyletongue Corruption' Taken - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 1182300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,5000,0,0,0,0,12,1,0,0,0,0,0,0,"Vark Battlescar - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=11823;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(11823, 0, 0, '$n, please take a look at the sample of the Vylestem vine that I took from the caverns, so that you know what to look for...', 12, 0, 100, 0, 0, 0, 8923, 'Vark Battlescar');
