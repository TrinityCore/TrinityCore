-- Nurse Lillian SAI -- http://wotlk.openwow.com/npc=5042
SET @ENTRY := 5042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,87000,89000,53,0,5042,1,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,3,5042,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,7,5042,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Waypoint 7 Reached - Pause Waypoint"),
(@ENTRY,0,3,0,40,0,100,0,12,5042,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Waypoint 12 Reached - Pause Waypoint"),
(@ENTRY,0,4,0,40,0,100,0,15,5042,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Waypoint 15 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 504200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Lillian - On Script - Set Emote State 0");

DELETE FROM `waypoints` WHERE `entry`=5042;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(5042, 1, -8759.62, 812.343, 97.635, 'Nurse Lillian'),
(5042, 2, -8761.61, 810.579, 97.635, 'Nurse Lillian'),
(5042, 3, -8762.09, 811.25, 97.635, 'Nurse Lillian'),
(5042, 4, -8765.12, 809.343, 97.635, 'Nurse Lillian'),
(5042, 5, -8768.82, 813.976, 97.635, 'Nurse Lillian'),
(5042, 6, -8765.6, 816.682, 97.635, 'Nurse Lillian'),
(5042, 7, -8765.49, 816.11, 97.635, 'Nurse Lillian'),
(5042, 8, -8766.14, 815.698, 97.635, 'Nurse Lillian'),
(5042, 9, -8762.85, 818.44, 97.635, 'Nurse Lillian'),
(5042, 10, -8757.2, 817.107, 97.635, 'Nurse Lillian'),
(5042, 11, -8755.51, 815.287, 97.635, 'Nurse Lillian'),
(5042, 12, -8755.65, 815.128, 97.635, 'Nurse Lillian'),
(5042, 13, -8755.62, 815.616, 97.635, 'Nurse Lillian'),
(5042, 14, -8766.1, 820.151, 97.635, 'Nurse Lillian'),
(5042, 15, -8766.37, 820.027, 97.635, 'Nurse Lillian');
