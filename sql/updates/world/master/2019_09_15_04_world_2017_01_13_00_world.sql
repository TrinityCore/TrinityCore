-- Kudrii -- http://wotlk.openwow.com/npc=16742
-- Kudrii SAI
SET @ENTRY := 16742;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,16742,1,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,5,16742,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,10,16742,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Waypoint 10 Reached - Run Script"),
(@ENTRY,0,3,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Gossip Hello - Pause Waypoint");

-- Actionlist SAI
SET @ENTRY := 1674200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,55000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.05848,"Kudrii - On Script - Set Orientation 5,05848"),
(@ENTRY,9,1,0,0,0,100,0,24000,24000,0,0,11,32990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Script - Cast 'Enchanting Cast Visual'");

-- Actionlist SAI
SET @ENTRY := 1674201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.87756,"Kudrii - On Script - Set Orientation 4,87756"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Script - Play Emote 1"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kudrii - On Script - Play Emote 273");

DELETE FROM `waypoints` WHERE `entry`=16742;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16742, 1, -3890.7,   -11487,   -136.197, 'Kudrii'),
(16742, 2, -3889.1,   -11488.2, -136.184, 'Kudrii'),
(16742, 3, -3887.77,  -11490.4, -136.174, 'Kudrii'),
(16742, 4, -3888.51,  -11493.6, -136.194, 'Kudrii'),
(16742, 5, -3889.43,  -11495,   -136.209, 'Kudrii'),
(16742, 6, -3888.03,  -11493.2, -136.188, 'Kudrii'),
(16742, 7, -3887.68,  -11490.2, -136.175, 'Kudrii'),
(16742, 8, -3889.3,   -11487.8, -136.183, 'Kudrii'),
(16742, 9, -3890.98,  -11486.6, -136.2,   'Kudrii'),
(16742, 10, -3893.26, -11486.4, -136.225, 'Kudrii');
