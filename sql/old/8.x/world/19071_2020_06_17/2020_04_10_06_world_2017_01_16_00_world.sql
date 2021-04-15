-- Wind Master To'bor & Warsong Wind Rider Script -- http://wotlk.openwow.com/npc=25289
-- Warsong Wind Rider SAI
SET @ENTRY := 25286;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Reset - Set Fly Off");
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=25286;

-- Warsong Wind Rider SAI
SET @GUID := -125578;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25286;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Reset - Set Fly Off"),
(@GUID,0,1,0,38,0,100,0,1,1,0,0,80,12557800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Data Set 1 1 - Run Script"),
(@GUID,0,2,3,40,0,100,0,9,125578,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 9 Reached - Set Fly On"),
(@GUID,0,3,0,61,0,100,0,9,125578,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 9 Reached - Set Run On"),
(@GUID,0,4,0,40,0,100,0,1,125578,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 1 Reached - Pause Waypoint"),
(@GUID,0,5,6,40,0,100,0,42,125578,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 42 Reached - Set Run Off"),
(@GUID,0,6,0,61,0,100,0,42,125578,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 42 Reached - Set Fly Off"),
(@GUID,0,7,8,40,0,100,0,46,125578,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.19912,"Warsong Wind Rider - On Waypoint 46 Reached - Set Orientation 2,19912"),
(@GUID,0,8,0,61,0,100,0,46,125578,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Waypoint 46 Reached - Set Active Off");

-- Actionlist SAI
SET @ENTRY := 12557800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,53,0,125578,0,0,0,1,1,0,0,0,0,0,0,0,"Warsong Wind Rider - On Script - Start Waypoint");

UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=125584;
DELETE FROM `waypoint_data` WHERE  `id`=1255840;
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=125584;

-- Wind Master To'bor SAI
SET @ENTRY := 25289;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,25289,1,0,0,1,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,0,40,0,100,0,9,25289,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Waypoint 9 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 2528900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.14906,"Wind Master To'bor - On Script - Set Orientation 5,14906"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Script - Set Active On"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,125578,25286,0,0,0,0,0,"Wind Master To'bor - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wind Master To'bor - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID` IN (25289, 25286);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(25289, 0, 0, 'Aye, solja! Lift off time!', 12, 1, 100, 1, 0, 0, 24521, 'Wind Master To''bor'),
(25286, 0, 0, 'Yes sir!', 12, 1, 100, 0, 0, 0, 24522, 'Warsong Wind Rider');

DELETE FROM `waypoints` WHERE `entry`=25289;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25289, 1, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 2, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 3, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 4, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 5, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 6, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 7, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 8, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 9, 2767.55, 6112.47, 208.234, 'Wind Master To''bor'),
(25289, 10, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 11, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 12, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 13, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 14, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 15, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 16, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 17, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 18, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 19, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 20, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 21, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 22, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 23, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 24, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 25, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 26, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 27, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 28, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 29, 2760.18, 6107.54, 208.576, 'Wind Master To''bor'),
(25289, 30, 2802.31, 6147.69, 208.197, 'Wind Master To''bor'),
(25289, 31, 2760.18, 6107.54, 208.576, 'Wind Master To''bor');

DELETE FROM `waypoints` WHERE `entry`=125578;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(125578, 1, 2772.24, 6103.7, 209.008, 'Warsong Wind Rider'),
(125578, 2, 2766.12, 6109.4, 208.372, 'Warsong Wind Rider'),
(125578, 3, 2763.93, 6113.74, 208.298, 'Warsong Wind Rider'),
(125578, 4, 2769.51, 6121.43, 208.123, 'Warsong Wind Rider'),
(125578, 5, 2793.61, 6143.72, 208.129, 'Warsong Wind Rider'),
(125578, 6, 2801.04, 6151.28, 208.13, 'Warsong Wind Rider'),
(125578, 7, 2801.21, 6154.14, 208.287, 'Warsong Wind Rider'),
(125578, 8, 2797.93, 6153.58, 208.192, 'Warsong Wind Rider'),
(125578, 9, 2785.39, 6137.84, 208.123, 'Warsong Wind Rider'),
(125578, 10, 2775.29, 6128.2, 208.123, 'Warsong Wind Rider'),
(125578, 11, 2765.01, 6118.83, 216.447, 'Warsong Wind Rider'),
(125578, 12, 2746.45, 6098.37, 238.299, 'Warsong Wind Rider'),
(125578, 13, 2724.52, 6069.8, 238.299, 'Warsong Wind Rider'),
(125578, 14, 2707, 6047.38, 238.299, 'Warsong Wind Rider'),
(125578, 15, 2680.77, 6017.05, 238.299, 'Warsong Wind Rider'),
(125578, 16, 2643.17, 5992.25, 216.577, 'Warsong Wind Rider'),
(125578, 17, 2617.43, 5969.46, 190.605, 'Warsong Wind Rider'),
(125578, 18, 2594.97, 5950.58, 168.994, 'Warsong Wind Rider'),
(125578, 19, 2577.94, 5924.14, 149.911, 'Warsong Wind Rider'),
(125578, 20, 2550.24, 5897.53, 149.911, 'Warsong Wind Rider'),
(125578, 21, 2562.29, 5866.69, 149.911, 'Warsong Wind Rider'),
(125578, 22, 2596.48, 5847.32, 149.911, 'Warsong Wind Rider'),
(125578, 23, 2626.64, 5851.95, 149.911, 'Warsong Wind Rider'),
(125578, 24, 2647.13, 5873.16, 149.911, 'Warsong Wind Rider'),
(125578, 25, 2645.8, 5899.81, 149.911, 'Warsong Wind Rider'),
(125578, 26, 2640.92, 5934.65, 149.911, 'Warsong Wind Rider'),
(125578, 27, 2627.54, 5981.53, 138.022, 'Warsong Wind Rider'),
(125578, 28, 2646.58, 6020.77, 125.022, 'Warsong Wind Rider'),
(125578, 29, 2650.72, 6063.53, 100.244, 'Warsong Wind Rider'),
(125578, 30, 2658.58, 6107.69, 80.8551, 'Warsong Wind Rider'),
(125578, 31, 2650.11, 6144.21, 80.8551, 'Warsong Wind Rider'),
(125578, 32, 2644.45, 6182.45, 80.8551, 'Warsong Wind Rider'),
(125578, 33, 2657.69, 6217.98, 91.7996, 'Warsong Wind Rider'),
(125578, 34, 2675, 6225.02, 121.827, 'Warsong Wind Rider'),
(125578, 35, 2699.94, 6246.2, 121.827, 'Warsong Wind Rider'),
(125578, 36, 2721.17, 6228.85, 152.188, 'Warsong Wind Rider'),
(125578, 37, 2731.05, 6205.52, 168.188, 'Warsong Wind Rider'),
(125578, 38, 2752.55, 6184.18, 181.438, 'Warsong Wind Rider'),
(125578, 39, 2764.62, 6189.2, 199.411, 'Warsong Wind Rider'),
(125578, 40, 2779.31, 6168.48, 221.641, 'Warsong Wind Rider'),
(125578, 41, 2792.78, 6160.51, 219.669, 'Warsong Wind Rider'),
(125578, 42, 2797.35, 6154.19, 209.197, 'Warsong Wind Rider'),
(125578, 43, 2790.22, 6145.23, 208.123, 'Warsong Wind Rider'),
(125578, 44, 2778.24, 6132.59, 208.123, 'Warsong Wind Rider'),
(125578, 45, 2764.71, 6113.99, 208.27, 'Warsong Wind Rider'),
(125578, 46, 2772.627197, 6102.89990, 209.02432, 'Warsong Wind Rider');
