-- Karen I Don't Caribou the Culler SAI
SET @ENTRY := 25803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,10000,10000,15000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,15000,21000,11,48280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - In Combat - Cast 'Whirlwind'"),
(@ENTRY,0,2,0,9,0,100,0,8,25,10000,10000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - Within 8-25 Range - Cast 'Intercept'"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,53,0,25803,1,0,0,2,1,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - On Reset - Start Waypoint"),
(@ENTRY,0,4,5,40,0,100,0,15,25803,0,0,54,26000,0,0,0,0,0,0,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - On Waypoint 15 Reached - Pause Waypoint"),
(@ENTRY,0,5,6,61,0,100,0,15,25803,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.698295,"Karen I Don't Caribou the Culler - On Waypoint 15 Reached - Set Orientation 0.698295"),
(@ENTRY,0,6,0,61,0,100,0,15,25803,0,0,11,46147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karen I Don't Caribou the Culler - On Waypoint 15 Reached - Cast 'Karen Eats'");

DELETE FROM `waypoints` WHERE `entry`=25803;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25803, 1, 2732.85, 5267, 70.526, 'Karen I Don''t Caribou the Cullerr'),
(25803, 2, 2726.15, 5264.63, 71.5126, 'Karen I Don''t Caribou the Cullerr'),
(25803, 3, 2721.45, 5267.05, 71.632, 'Karen I Don''t Caribou the Cullerr'),
(25803, 4, 2721.44, 5276.07, 70.8437, 'Karen I Don''t Caribou the Cullerr'),
(25803, 5, 2729.39, 5276.17, 71.4764, 'Karen I Don''t Caribou the Cullerr'),
(25803, 6, 2732.85, 5267, 70.526, 'Karen I Don''t Caribou the Cullerr'),
(25803, 7, 2726.15, 5264.63, 71.5126, 'Karen I Don''t Caribou the Cullerr'),
(25803, 8, 2721.45, 5267.05, 71.632, 'Karen I Don''t Caribou the Cullerr'),
(25803, 9, 2721.44, 5276.07, 70.8437, 'Karen I Don''t Caribou the Cullerr'),
(25803, 10, 2729.39, 5276.17, 71.4764, 'Karen I Don''t Caribou the Cullerr'),
(25803, 11, 2732.85, 5267, 70.526, 'Karen I Don''t Caribou the Cullerr'),
(25803, 12, 2726.15, 5264.63, 71.5126, 'Karen I Don''t Caribou the Cullerr'),
(25803, 13, 2721.45, 5267.05, 71.632, 'Karen I Don''t Caribou the Cullerr'),
(25803, 14, 2721.44, 5276.07, 70.8437, 'Karen I Don''t Caribou the Cullerr'),
(25803, 15, 2728.34, 5281.66, 71.0141, 'Karen I Don''t Caribou the Cullerr'),
(25803, 16, 2729.39, 5276.17, 71.4764, 'Karen I Don''t Caribou the Cullerr'),
(25803, 17, 2732.85, 5267, 70.526, 'Karen I Don''t Caribou the Cullerr'),
(25803, 18, 2726.15, 5264.63, 71.5126, 'Karen I Don''t Caribou the Cullerr'),
(25803, 19, 2721.45, 5267.05, 71.632, 'Karen I Don''t Caribou the Cullerr'),
(25803, 20, 2721.44, 5276.07, 70.8437, 'Karen I Don''t Caribou the Cullerr'),
(25803, 21, 2729.39, 5276.17, 71.4764, 'Karen I Don''t Caribou the Cullerr'),
(25803, 22, 2732.85, 5267, 70.526, 'Karen I Don''t Caribou the Cullerr'),
(25803, 23, 2726.15, 5264.63, 71.5126, 'Karen I Don''t Caribou the Cullerr'),
(25803, 24, 2721.45, 5267.05, 71.632, 'Karen I Don''t Caribou the Cullerr'),
(25803, 25, 2721.44, 5276.07, 70.8437, 'Karen I Don''t Caribou the Cullerr'),
(25803, 26, 2729.39, 5276.17, 71.4764, 'Karen I Don''t Caribou the Cullerr');
