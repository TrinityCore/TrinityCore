-- [Q] Welcoming the Wolf Spirit -- http://wotlk.openwow.com/quest=10791
DELETE FROM `event_scripts` WHERE `id`=12650;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(12650, 0, 10, 19616, 300000, 0, -2645.3957, 4402.211, 35.6738, 3.9440),
(12650, 43, 8, 18384, 30, 0, 0, 0, 0, 0);

-- Malukaz SAI
SET @ENTRY := 18384;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Data Set 1 1 - Run Script"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Data Set 2 2 - Run Script");

-- Terokkar Wolf Spirit SAI
SET @ENTRY := 19616;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokkar Wolf Spirit - On Just Created - Set Visibility Off"),
(@ENTRY,0,1,5,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,65789,18384,0,0,0,0,0,"Terokkar Wolf Spirit - On Just Created - Set Data 1 1"),
(@ENTRY,0,2,4,38,0,100,0,1,1,0,0,53,1,19616,0,0,0,0,1,0,0,0,0,0,0,0,"Terokkar Wolf Spirit - On Data Set 1 1 - Start Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,2,19616,0,0,45,2,2,0,0,0,0,10,65789,18384,0,0,0,0,0,"Terokkar Wolf Spirit - On Waypoint 2 Reached - Set Data 2 2"),
(@ENTRY,0,4,0,61,0,100,0,1,1,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokkar Wolf Spirit - On Data Set 1 1 - Set Visibility On"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terokkar Wolf Spirit - On Just Created - Set Active On");

DELETE FROM `waypoints` WHERE `entry`=19616;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19616, 1, -2655.9,  4391.12, 36.1316, 'Terokkar Wolf Spirit'),
(19616, 2, -2668.96, 4376.09, 35.9556, 'Terokkar Wolf Spirit');

-- Actionlist SAI
SET @ENTRY := 1838400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Set Npc Flag 0"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,11,34317,2,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Cast 'Transform Malukaz'"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,11,28892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Cast 'Nature Channeling'"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,1,1,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 1"),
(@ENTRY,9,6,0,0,0,100,0,4000,4000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 2"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 3"),
(@ENTRY,9,8,0,0,0,100,0,500,500,0,0,28,28892,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Remove Aura 'Nature Channeling'"),
(@ENTRY,9,9,0,0,0,100,0,1000,1000,0,0,11,34312,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Cast 'Summon Terokkar Wolf Spirit'"),
(@ENTRY,9,10,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,19616,100,0,0,0,0,0,"Malukaz - On Script - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 1838401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,5,393,0,0,0,0,0,19,19616,20,0,0,0,0,0,"Malukaz - On Script - Play Emote 393"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,19616,20,0,0,0,0,0,"Malukaz - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,19616,20,0,0,0,0,0,"Malukaz - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Play Emote 2"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 4"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,41,1,0,0,0,0,0,19,19616,20,0,0,0,0,0,"Malukaz - On Script - Despawn Instant"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Say Line 5"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,11,34319,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Cast 'Transform Malukaz Back'"),
(@ENTRY,9,8,0,0,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Set Npc Flag 3"),
(@ENTRY,9,9,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malukaz - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID` IN (18384, 19616);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
-- Malukaz
(18384, 0, 0, '%s dons his wolf-fur vestments.', 16, 0, 100, 0, 0, 0, 17039, 'Malukaz'),
(18384, 1, 0, 'Wolf spirit of the forest, hear me!', 12, 0, 100, 0, 0, 0, 17044, 'Malukaz'),
(18384, 2, 0, 'Long ago, you were a companion to my people. We gave ourselves to evil and you were forgotten.', 12, 0, 100, 0, 0, 0, 17046, 'Malukaz'),
(18384, 3, 0, 'But we have returned, spirit! We have returned to honor you again. Favor us with your presence once more.', 12, 0, 100, 0, 0, 0, 17047, 'Malukaz'),
(18384, 4, 0, 'May our bond with you never be broken again, spirit.', 12, 0, 100, 0, 0, 0, 17055, 'Malukaz'),
(18384, 5, 0, 'We have done it! Thrall would be proud.', 12, 0, 100, 0, 0, 0, 17066, 'Malukaz'),
-- Terokkar Wolf Spirit
(19616, 0, 0, '%s howls in response to Malukaz''s call.', 16, 0, 100, 0, 0, 0, 17051, 'Terokkar Wolf Spirit'),
(19616, 1, 0, '%s expresses its approval.', 16, 0, 100, 0, 0, 0, 17086, 'Terokkar Wolf Spirit');
