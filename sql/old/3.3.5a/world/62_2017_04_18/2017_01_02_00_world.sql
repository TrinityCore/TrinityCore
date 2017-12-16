-- Harene Plainwalker -- http://www.wowhead.com/npc=16655/harene-plainwalker#comments
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=16655;

-- Harene Plainwalker SAI
SET @ENTRY := 16655;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16655,1,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,16655,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Waypoint 1 Reached - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,3,16655,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Waypoint 3 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,7,16655,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,11,16655,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,14,16655,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Waypoint 14 Reached - Pause Waypoint"),
(@ENTRY,0,6,0,64,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1665500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,54,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Set Emote State 133"),
(@ENTRY,9,2,0,0,0,100,0,25000,25000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Set Emote State 0");

-- Actionlist SAI
SET @ENTRY := 1665501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,75,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Add Aura 'Kneel'"),
(@ENTRY,9,2,0,0,0,100,0,25000,25000,0,0,28,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harene Plainwalker - On Script - Remove Aura 'Kneel'");

DELETE FROM `waypoints` WHERE `entry`=16655;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16655, 1, 9703.85, -7267.49, 16.1144,  'Harene Plainwalker'),
(16655, 2, 9703.63, -7263.83, 15.9914,  'Harene Plainwalker'),
(16655, 3, 9706.74, -7261.86, 16.5287,  'Harene Plainwalker'),
(16655, 4, 9703.75, -7263.42, 16.0209,  'Harene Plainwalker'),
(16655, 5, 9701.5, -7261.56, 15.9065,   'Harene Plainwalker'),
(16655, 6, 9698.97, -7258.35, 15.599,   'Harene Plainwalker'),
(16655, 7, 9698.97, -7258.35, 15.599,   'Harene Plainwalker'),
(16655, 8, 9700.7, -7261.93, 15.7977,   'Harene Plainwalker'),
(16655, 9, 9703.63, -7266.76, 16.0817,  'Harene Plainwalker'),
(16655, 10, 9701.12, -7272.78, 15.8364, 'Harene Plainwalker'),
(16655, 11, 9700.66, -7278.72, 15.5704, 'Harene Plainwalker'),
(16655, 12, 9701.32, -7272.86, 15.8672, 'Harene Plainwalker'),
(16655, 13, 9703.85, -7267.49, 16.1144, 'Harene Plainwalker'),
(16655, 14, 9703.85, -7267.49, 16.1144, 'Harene Plainwalker');
