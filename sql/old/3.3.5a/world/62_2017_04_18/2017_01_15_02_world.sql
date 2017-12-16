-- Nurse Judith -- http://wotlk.openwow.com/npc=19455
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE  `entry`=19455;

-- Nurse Judith SAI
SET @ENTRY := 19455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,19455,1,0,0,1,0,0,0,0,0,0,0,0,"Nurse Judith - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,2,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,3,0,61,0,100,0,2,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.76273,"Nurse Judith - On Waypoint 2 Reached - Set Orientation 2,76273"),
(@ENTRY,0,4,5,40,0,100,0,5,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,5,0,61,0,100,0,5,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.1529,"Nurse Judith - On Waypoint 5 Reached - Set Orientation 4,1529"),
(@ENTRY,0,5,6,40,0,100,0,7,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,6,0,61,0,100,0,7,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.25502,"Nurse Judith - On Waypoint 7 Reached - Set Orientation 4.25502"),
(@ENTRY,0,7,8,40,0,100,0,9,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,8,0,61,0,100,0,9,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.969,"Nurse Judith - On Waypoint 9 Reached - Set Orientation 2.969"),
(@ENTRY,0,9,10,40,0,100,0,12,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,10,0,61,0,100,0,12,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.17224,"Nurse Judith - On Waypoint 12 Reached - Set Orientation 4.17224"),
(@ENTRY,0,11,12,40,0,100,0,15,19455,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Waypoint 15 Reached - Run Script"),
(@ENTRY,0,12,0,61,0,100,0,15,19455,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.1529,"Nurse Judith - On Waypoint 15 Reached - Set Orientation 2.41624");

-- Actionlist SAI
SET @ENTRY := 1945500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Script - Set Flag Standstate Kneel"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nurse Judith - On Script - Remove Flag Standstate Kneel");

DELETE FROM `waypoints` WHERE `entry`=19455;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(19455, 1, -365.789, 981.419,   54.195, 'Nurse Judith'),
(19455, 2, -368.858, 982.56,   54.1727, 'Nurse Judith'),
(19455, 3, -363.252, 980.47,   54.2127, 'Nurse Judith'),
(19455, 4, -357.494, 978.322,  54.2425, 'Nurse Judith'),
(19455, 5, -358.948, 975.922,  54.243,  'Nurse Judith'),
(19455, 6, -357.512, 973.939,  54.2493, 'Nurse Judith'),
(19455, 7, -360.045, 968.102,  54.2344, 'Nurse Judith'),
(19455, 8, -358.571, 965.26,   54.2447, 'Nurse Judith'),
(19455, 9, -362.99, 962.005,   54.2135, 'Nurse Judith'),
(19455, 10, -352.415, 973.809, 54.2617, 'Nurse Judith'),
(19455, 11, -349.296, 971.591, 54.2724, 'Nurse Judith'),
(19455, 12, -349.964, 970.224, 54.2733, 'Nurse Judith'),
(19455, 13, -350.597, 974.797, 54.2635, 'Nurse Judith'),
(19455, 14, -362.665, 981.665, 54.2171, 'Nurse Judith'),
(19455, 15, -364.29, 984.89,   54.2066, 'Nurse Judith');
