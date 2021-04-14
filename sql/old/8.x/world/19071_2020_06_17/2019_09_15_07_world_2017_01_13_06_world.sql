-- Fungal Spores -- http://wotlk.openwow.com/quest=848
-- Apothecary Helbrim SAI
SET @ENTRY := 3390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,848,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Helbrim - On Quest 'Fungal Spores' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,848,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Apothecary Helbrim - On Quest 'Fungal Spores' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 339000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.72937,"Apothecary Helbrim - On Script - Set Orientation 4.72937"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Helbrim - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Apothecary Helbrim - On Script - Set Orientation Store Target"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,8,0,0,0,0,0,0,4.72937,"Apothecary Helbrim - On Script - Add Npc Flag Questgiver"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,1,1,6000,0,0,0,0,12,1,0,0,0,0,0,0,"Apothecary Helbrim - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=3390;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(3390, 0, 0, '%s places the spores within his alchemical instruments...', 16, 0, 100, 0, 0, 0, 1076, 'Apothecary Helbrim'),
(3390, 1, 0, 'Ah, good.  These spores have rendered nicely.  Thank you, $n.', 12, 0, 100, 0, 0, 0, 1077, 'Apothecary Helbrim');
