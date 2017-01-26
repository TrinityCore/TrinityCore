-- Mathas Wildwood SAI
SET @ENTRY := 34041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathas Wildwood - On data set - Run Script");

-- Mathas Wildwood Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100,9,0,0,0,0,100,0, 4000, 4000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote"),
(@ENTRY*100,9,1,0,0,0,100,0,10000,10000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathas Wildwood - On Script - Set bytes1"),
(@ENTRY*100,9,2,0,0,0,100,0,10000,10000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mathas Wildwood - On Script - Remove bytes1");

-- Mathas Wildwood text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34041, 0, 0, 'What can you tell me, Keynira?', 12, 0, 100, 1, 0, 0, 34195, 'Mathas Wildwood Script'),
(34041, 1, 0, 'That will do for the moment. And the tower? What of Althalaxx?', 12, 0, 100, 273, 0, 0, 34198, 'Mathas Wildwood Script'),
(34041, 2, 0, 'That''s all you''ve got for me? I want numbers, locations, intentions - we''re as good as blind. Get back out in the field!', 12, 0, 100, 5, 0, 0, 34204, 'Mathas Wildwood Script');

-- Keynira Owlwing spawn location update
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7375.882,`position_y`=-803.6075,`position_z`=8.27469,`orientation`=2.093473 WHERE `guid`=315943;

-- Keynira Owlwing SAI
SET @ENTRY := 34103;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,1,@ENTRY,1,0,0,1,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,3,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,7,@ENTRY,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,10,@ENTRY,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 10 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,11,@ENTRY,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,22,@ENTRY,0,0,80,@ENTRY*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 22 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,26,@ENTRY,0,0,80,@ENTRY*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Waypoint 26 Reached - Run Script"),
(@ENTRY,0,7,0,64,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Gossip Hello - Pause Waypoint");

-- Keynira Owlwing Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Pause Waypoint"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,17,433,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Set emotestate"),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Add aura");

-- Keynira Owlwing Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+1 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,54,11000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Pause Waypoint"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.642576,"Keynira Owlwing - On Script - Turn to"),
(@ENTRY*100+1,9,2,0,0,0,100,0,1000,1000,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote"),
(@ENTRY*100+1,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.658063,"Keynira Owlwing - On Script - Turn to");

-- Keynira Owlwing Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+2 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Pause Waypoint"),
(@ENTRY*100+2,9,1,0,0,0,100,0,1000,1000,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote");

-- Keynira Owlwing Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+3 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,28,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Remove aura"),
(@ENTRY*100+3,9,1,0,0,0,100,0,1000,1000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Remove emotestate");

-- Keynira Owlwing Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+4 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY*100+4,9,0,0,0,0,100,0,0,0,0,0,54,26000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Pause Waypoint"),
(@ENTRY*100+4,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Turn to self"),
(@ENTRY*100+4,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,11,34041,5,0,0,0,0,0,"Keynira Owlwing - On Script - Turn to"),
(@ENTRY*100+4,9,3,0,0,0,100,0,0,0,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote"),
(@ENTRY*100+4,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,11,34041,5,0,0,0,0,0,"Keynira Owlwing - On Script - Mathas Wildwood say 0"),
(@ENTRY*100+4,9,5,0,0,0,100,0,7000,7000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - say 0"),
(@ENTRY*100+4,9,6,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - say 1"),
(@ENTRY*100+4,9,7,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,11,34041,5,0,0,0,0,0,"Keynira Owlwing - On Script - Mathas Wildwood say 1"),
(@ENTRY*100+4,9,8,0,0,0,100,0,3000,3000,0,0,5,24,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote"),
(@ENTRY*100+4,9,9,0,0,0,100,0,5000,5000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keynira Owlwing - On Script - Play emote"),
(@ENTRY*100+4,9,10,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,11,34041,5,0,0,0,0,0,"Keynira Owlwing - On Script - Mathas Wildwood say 2"),
(@ENTRY*100+4,9,11,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,34041,5,0,0,0,0,0,"Keynira Owlwing - On Script - Mathas Wildwood Set Data");

-- Keynira Owlwing text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34103, 0, 0, 'The catapults remain disabled. I''ve burned several and trapped the others.', 12, 0, 100, 1, 0, 0, 34213, 'Keynira Owlwing Script'),
(34103, 1, 0, 'I - I don''t know. There''s movement in the ruins.', 12, 0, 100, 6, 0, 0, 34214, 'Keynira Owlwing Script');

-- Keynira Owlwing Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@ENTRY,1, 7352.095, -776.1512, 8.003876, 'Keynira Owlwing'),
(@ENTRY,2, 7343.906, -768.0654, 11.25363, 'Keynira Owlwing'),
(@ENTRY,3, 7340.732, -767.2589, 13.12619, 'Keynira Owlwing'),
(@ENTRY,4, 7315.907, -780.2684, 16.69614, 'Keynira Owlwing'),
(@ENTRY,5, 7303.997, -762.7374, 19.42897, 'Keynira Owlwing'),
(@ENTRY,6, 7299.663, -759.3302, 19.91131, 'Keynira Owlwing'),
(@ENTRY,7, 7298.438, -761.9785, 20.3305, 'Keynira Owlwing'),
(@ENTRY,8, 7285.221, -758.7911, 22.2448, 'Keynira Owlwing'),
(@ENTRY,9, 7270.799, -762.6132, 24.27215, 'Keynira Owlwing'),
(@ENTRY,10, 7265.127, -772.0636, 24.9465, 'Keynira Owlwing'),
(@ENTRY,11, 7271.354, -780.7285, 24.63882, 'Keynira Owlwing'),
(@ENTRY,12, 7255.721, -776.7241, 26.05576, 'Keynira Owlwing'),
(@ENTRY,13, 7249.361, -777.6339, 26.32431, 'Keynira Owlwing'),
(@ENTRY,14, 7245.773, -781.4711, 26.44931, 'Keynira Owlwing'),
(@ENTRY,15, 7246.412, -785.9227, 26.32431, 'Keynira Owlwing'),
(@ENTRY,16, 7259.783, -761.7302, 25.76875, 'Keynira Owlwing'),
(@ENTRY,17, 7275.452, -743.2621, 24.70989, 'Keynira Owlwing'),
(@ENTRY,18, 7295.812, -740.9485, 21.23431, 'Keynira Owlwing'),
(@ENTRY,19, 7311.68, -752.866, 16.42214, 'Keynira Owlwing'),
(@ENTRY,20, 7322.447, -766.5735, 15.29714, 'Keynira Owlwing'),
(@ENTRY,21, 7329.108, -769.6451, 15.22299, 'Keynira Owlwing'),
(@ENTRY,22, 7337.935, -768.5345, 13.67477, 'Keynira Owlwing'),
(@ENTRY,23, 7349.944, -775.3535, 8.003876, 'Keynira Owlwing'),
(@ENTRY,24, 7365.521, -784.0329, 7.878876, 'Keynira Owlwing'),
(@ENTRY,25, 7369.056, -795.8342, 7.926283, 'Keynira Owlwing'),
(@ENTRY,26, 7375.882, -803.6075, 8.27469, 'Keynira Owlwing');--
--
