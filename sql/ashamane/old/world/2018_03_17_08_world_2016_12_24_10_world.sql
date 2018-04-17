-- 
-- [Q] Deciphering the Book -- http://wotlk.openwow.com/quest=9557
-- Anchorite Paetheus SAI
SET @ENTRY := 17424;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,9557,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Quest 'Deciphering the Book' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 1742400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Remove Npc Flag Questgiver"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Say Line 2"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Say Line 3"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Paetheus - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=17424;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(17424, 0, 0, 'Now, let\'s see....', 12, 0, 100, 69, 0, 0, 14281, 'Anchorite Paetheus'),
(17424, 1, 0, 'In the process of translating this, I believe I\'ve learned more about the drunken exploits of a certain \'Andrew Clementine\' than about the journal\'s author.', 12, 0, 100, 1, 0, 0, 14282, 'Anchorite Paetheus'),
(17424, 2, 0, 'But, no matter. Mister Clementine\'s... err, \'contribution\' notwithstanding, this seems to be the journal of a man named Nolkai. The entries toward the end describe a brutal battle.', 12, 0, 100, 11, 0, 0, 14283, 'Anchorite Paetheus'),
(17424, 3, 0, 'Take a look at this passage...', 12, 0, 100, 0, 0, 0, 14285, 'Anchorite Paetheus');
