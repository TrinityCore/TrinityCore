-- 
-- [Q] Gamel the Cruel -- http://wotlk.openwow.com/quest=11619
-- Karuk SAI
SET @ENTRY := 25435;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,11619,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Karuk - On Quest 'Gamel the Cruel' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 2543500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,26450,1,15000,0,0,0,8,0,0,0,2003.83,5851.17,36.2061,2.75762,"Karuk - On Script - Summon Creature 'Ariut'"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,10000,0,0,0,0,19,26450,20,0,0,0,0,0,"Karuk - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=26450;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(26450, 0, 0, 'The fallen of Pal\'ea will not rest, son.  Find the naga priestess!', 12, 0, 100, 1, 0, 0, 25684, 'Ariut');
