-- [Q] World of Shadows -- http://wotlk.openwow.com/quest=11004
-- Severin SAI
SET @ENTRY := 23042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11004,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Severin - On Quest 'World of Shadows' Taken - Run Script");

-- Actionlist SAI
SET @ENTRY := 2304200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,7000,0,0,0,0,19,23038,10,0,0,0,0,0,"Severin - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Severin - On Script - Play Emote 16"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Severin - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23038, 23042);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(23038, 0, 0, 'The arakkoa are hidden... everywhere!', 12, 0, 100, 0, 0, 0, 21917, 'Sky Commander Adaris'),
(23042, 0, 0, 'Rest now, Adaris. You need to recover your strength.', 12, 0, 100, 0, 0, 0, 21918, 'Severin');
