-- Armorer Orkuruk --
UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid`=125542;
DELETE FROM `waypoint_data` WHERE  `id`=1255420;
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=125542;

-- Armorer Orkuruk SAI
SET @ENTRY := 25274;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,25274,1,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Gossip Hello - Pause Waypoint"),
(@ENTRY,0,2,3,40,0,100,0,17,25274,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Waypoint 17 Reached - Run Script"),
(@ENTRY,0,3,0,61,0,100,0,17,25274,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.38169,"Armorer Orkuruk - On Waypoint 17 Reached - Set Orientation 3,38169"),
(@ENTRY,0,4,5,40,0,100,0,71,25274,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Waypoint 71 Reached - Run Script"),
(@ENTRY,0,5,0,61,0,100,0,71,25274,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.88465,"Armorer Orkuruk - On Waypoint 71 Reached - Set Orientation 2,88465");

-- Actionlist SAI
SET @ENTRY := 2527400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Script - Play Emote 5"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Armorer Orkuruk - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=25274;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(25274, 0, 0, 'Keep ''em hot you big dummy!', 12, 1, 100, 0, 0, 0, 25133, 'Armorer Orkuruk'),
(25274, 0, 1, 'Those weapons ain''t gonna build themselves! Faster!', 12, 1, 100, 0, 0, 0, 25134, 'Armorer Orkuruk'),
(25274, 0, 2, 'You call that a hammer strike? What kind of amateurs am I workin'' with here?', 12, 1, 100, 0, 0, 0, 25135, 'Armorer Orkuruk'),
(25274, 0, 3, 'You keep that garbage up and I''ll ship you back to your momma in a box with a note strapped to your chest that reads: FAILURE.', 12, 1, 100, 0, 0, 0, 25136, 'Armorer Orkuruk'),
(25274, 0, 4, 'And WHAT are our soldiers supposed to do with that shoddy piece of junk?', 12, 1, 100, 0, 0, 0, 25137, 'Armorer Orkuruk'),
(25274, 0, 5, 'You''re an embarassment to this entire operation! Pack up your stuff and get out!', 12, 1, 100, 0, 0, 0, 25138, 'Armorer Orkuruk');

DELETE FROM `waypoints` WHERE `entry`=25274;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25274, 1, 2761.85, 6187.82, 83.448, 'Armorer Orkuruk'),
(25274, 2, 2763.1, 6203.83, 83.4409, 'Armorer Orkuruk'),
(25274, 3, 2765.37, 6209.65, 83.4451, 'Armorer Orkuruk'),
(25274, 4, 2772.92, 6217.22, 83.4475, 'Armorer Orkuruk'),
(25274, 5, 2766.39, 6211.48, 83.437, 'Armorer Orkuruk'),
(25274, 6, 2762.96, 6202.62, 83.4409, 'Armorer Orkuruk'),
(25274, 7, 2762.31, 6187.53, 83.4546, 'Armorer Orkuruk'),
(25274, 8, 2765.22, 6178.21, 83.4565, 'Armorer Orkuruk'),
(25274, 9, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 10, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 11, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 12, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 13, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 14, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 15, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 16, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 17, 2764.09, 6182.25, 83.4576, 'Armorer Orkuruk'),
(25274, 18, 2762.03, 6188.66, 83.4549, 'Armorer Orkuruk'),
(25274, 19, 2763.21, 6203.82, 83.4422, 'Armorer Orkuruk'),
(25274, 20, 2766.87, 6211.5, 83.4422, 'Armorer Orkuruk'),
(25274, 21, 2773.88, 6218.09, 83.4497, 'Armorer Orkuruk'),
(25274, 22, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 23, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 24, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 25, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 26, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 27, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 28, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 29, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 30, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 31, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 32, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 33, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 34, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 35, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 36, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 37, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 38, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 39, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 40, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 41, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 42, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 43, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 44, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 45, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 46, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 47, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 48, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 49, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 50, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 51, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 52, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 53, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 54, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 55, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 56, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 57, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 58, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 59, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 60, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 61, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 62, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 63, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 64, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 65, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 66, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 67, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 68, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 69, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 70, 2766.07, 6210.93, 83.4391, 'Armorer Orkuruk'),
(25274, 71, 2762.53, 6207.16, 83.4206, 'Armorer Orkuruk'),
(25274, 72, 2762.16, 6187.79, 83.4531, 'Armorer Orkuruk'),
(25274, 73, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk'),
(25274, 74, 2761.85, 6187.82, 83.448, 'Armorer Orkuruk'),
(25274, 75, 2763.1, 6203.83, 83.4409, 'Armorer Orkuruk'),
(25274, 76, 2765.37, 6209.65, 83.4451, 'Armorer Orkuruk'),
(25274, 77, 2772.92, 6217.22, 83.4475, 'Armorer Orkuruk'),
(25274, 78, 2766.39, 6211.48, 83.437, 'Armorer Orkuruk'),
(25274, 79, 2762.96, 6202.62, 83.4409, 'Armorer Orkuruk'),
(25274, 80, 2762.31, 6187.53, 83.4546, 'Armorer Orkuruk'),
(25274, 81, 2765.22, 6178.21, 83.4565, 'Armorer Orkuruk'),
(25274, 82, 2762.24, 6188.36, 83.4575, 'Armorer Orkuruk'),
(25274, 83, 2763.33, 6204.33, 83.4432, 'Armorer Orkuruk'),
(25274, 84, 2766.61, 6211.59, 83.4381, 'Armorer Orkuruk'),
(25274, 85, 2773.5, 6217.87, 83.4484, 'Armorer Orkuruk'),
(25274, 86, 2765.7, 6210.09, 83.4438, 'Armorer Orkuruk'),
(25274, 87, 2762.77, 6202.1, 83.4395, 'Armorer Orkuruk'),
(25274, 88, 2762.54, 6187.41, 83.4578, 'Armorer Orkuruk'),
(25274, 89, 2765.46, 6178.01, 83.4598, 'Armorer Orkuruk');
