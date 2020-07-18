-- Horde Laborer SAI
SET @GUID := -14429;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,180000,180000,80,1442900,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Aggro - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 1442900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.39941,"Horde Laborer - On Script - Set Orientation 4.39941"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 173"),
(@ENTRY,9,2,0,0,0,100,0,117000,117000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.19849,"Horde Laborer - On Script - Set Orientation 1.19849");

-- Horde Laborer SAI
SET @GUID := -14431;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,180000,180000,80,1443100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Aggro - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 1443100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.17085,"Horde Laborer - On Script - Set Orientation 4.17085"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 173"),
(@ENTRY,9,2,0,0,0,100,0,117000,117000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.882199,"Horde Laborer - On Script - Set Orientation 0.882199");

-- Horde Laborer SAI
SET @GUID := -14432;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,180000,180000,80,1443200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Aggro - Say Line 0");


-- Actionlist SAI
SET @ENTRY := 1443200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.17085,"Horde Laborer - On Script - Set Orientation 4.17085"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 173"),
(@ENTRY,9,2,0,0,0,100,0,117000,117000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.882199,"Horde Laborer - On Script - Set Orientation 0.882199");

-- Horde Laborer SAI
SET @GUID := -14430;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,0,0,180000,180000,80,1443000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - Out of Combat - Run Script"),
(@GUID,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Aggro - Say Line 0");


-- Actionlist SAI
SET @ENTRY := 1443000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.17085,"Horde Laborer - On Script - Set Orientation 4.17085"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 173"),
(@ENTRY,9,2,0,0,0,100,0,117000,117000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.882199,"Horde Laborer - On Script - Set Orientation 0.882199");

DELETE FROM `creature_text` WHERE `entry`=14718;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(14718, 0, 0, '%s attempts to get help!', 16, 0, 100, 0, 0, 0, 6311, 'Horde Laborer');

-- Horde Laborer SAI
SET @GUID := -14428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Aggro - Say Line 0"),
(@GUID,0,1,0,25,0,100,0,0,0,0,0,53,0,14718,1,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Reset - Start Waypoint"),
(@GUID,0,2,0,40,0,100,0,8,14718,0,0,80,1442800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Waypoint 8 Reached - Run Script"),
(@GUID,0,3,0,40,0,100,0,14,14718,0,0,80,1442801,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Waypoint 14 Reached - Run Script"),
(@GUID,0,4,0,40,0,100,0,20,14718,0,0,80,1442802,2,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Waypoint 20 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1442800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,13000,13000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Horde Laborer - On Script - Play Emote 1");

-- Actionlist SAI
SET @ENTRY := 1442801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.08029,"Horde Laborer - On Script - Set Orientation 1.08029"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,0,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 69"),
(@ENTRY,9,3,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.8455,"Horde Laborer - On Script - Set Orientation 4.8455"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 69"),
(@ENTRY,9,6,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,7,0,0,0,100,0,1000,1000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Play Emote 1");

-- Actionlist SAI
SET @ENTRY := 1442802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Set Emote State 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Laborer - On Script - Play Emote 1");

DELETE FROM `waypoints` WHERE `entry`=14718;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14718, 1, 1034.29, -2112.98, 122.946,  'Horde Laborer'),
(14718, 2, 1034.5, -2115.07, 122.946,   'Horde Laborer'),
(14718, 3, 1034.06, -2125.55, 122.953,  'Horde Laborer'),
(14718, 4, 1033.47, -2136.03, 122.94,   'Horde Laborer'),
(14718, 5, 1033.66, -2148.56, 122.9,    'Horde Laborer'),
(14718, 6, 1032.68, -2152.52, 122.948,  'Horde Laborer'),
(14718, 7, 1030.98, -2152.07, 122.97,   'Horde Laborer'),
(14718, 8, 1029.92, -2150.68, 123.052,  'Horde Laborer'), -- work 1
(14718, 9, 1033.3, -2150.87, 122.922,   'Horde Laborer'),
(14718, 10, 1035.12, -2146.2, 122.907,  'Horde Laborer'),
(14718, 11, 1034.46, -2142.76, 122.858, 'Horde Laborer'),
(14718, 12, 1033.41, -2135.26, 122.941, 'Horde Laborer'),
(14718, 13, 1039.67, -2130.72, 123.491, 'Horde Laborer'),
(14718, 14, 1044.52, -2130.13, 124.082, 'Horde Laborer'), -- work 2
(14718, 15, 1044.52, -2130.13, 124.082, 'Horde Laborer'),
(14718, 16, 1034.41, -2128.47, 122.967, 'Horde Laborer'),
(14718, 17, 1034.34, -2124.97, 122.987, 'Horde Laborer'),
(14718, 18, 1034.2, -2114.47, 122.947,  'Horde Laborer'),
(14718, 19, 1032.9, -2106.12, 122.947,  'Horde Laborer'),
(14718, 20, 1029.66, -2104.47, 122.947, 'Horde Laborer'); -- work 3
