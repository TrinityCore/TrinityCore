-- 
-- Fineous Darkvire SAI -- http://www.wowhead.com/npc=9056/fineous-darkvire
SET @ENTRY := 9056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,53,0,9056,1,0,0,2,0,0,0,0,0,0,0,0,"Fineous Darkvire - On Reset - Start Waypoint"),
(@ENTRY,0,7,0,40,0,100,0,12,9056,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,8,0,40,0,100,0,19,9056,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Waypoint 19 Reached - Run Script"),
(@ENTRY,0,9,0,40,0,100,0,24,9056,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Waypoint 24 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 905600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Set Emote State 133"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Set Emote State 0");

-- Actionlist SAI
SET @ENTRY := 905601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,173,0,0,0,0,0,0,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Set Emote State 173"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Set Emote State 0");

-- Actionlist SAI
SET @ENTRY := 905602;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fineous Darkvire - On Script - Play Emote 16");

DELETE FROM `waypoints` WHERE `entry`=9056;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(9056, 1, 975.107, -354.152, -69.1219),
(9056, 2, 984.444, -363.944, -65.9066),
(9056, 3, 984.38, -372.827, -66.4086),
(9056, 4, 976.479, -381.185, -63.9267),
(9056, 5, 962.877, -395.447, -60.8377),
(9056, 6, 950.417, -408.589, -57.1351),
(9056, 7, 941.736, -417.331, -55.0396),
(9056, 8, 931.446, -413.318, -55.3833),
(9056, 9, 923.409, -403.986, -51.104),
(9056, 10, 914.499, -394.179, -49.4412),
(9056, 11, 905.604, -403.547, -48.7295),
(9056, 12, 905.604, -403.547, -48.7295),
(9056, 13, 912.664, -392.947, -49.2744),
(9056, 14, 918.441, -398, -49.6367),
(9056, 15, 926.414, -407.296, -52.6216),
(9056, 16, 930.038, -418.35, -55.3877),
(9056, 17, 930.151, -424.848, -55.8645),
(9056, 18, 927.594, -433.715, -56.5236),
(9056, 19, 927.594, -433.715, -56.5236),
(9056, 20, 936.123, -427.94, -56.1072),
(9056, 21, 939.641, -426.605, -55.7614),
(9056, 22, 944.406, -426.659, -54.9984),
(9056, 23, 946.326, -428.053, -54.6023),
(9056, 24, 946.326, -428.053, -54.6023),
(9056, 25, 943.776, -418.105, -54.9468),
(9056, 26, 947.044, -410.439, -55.9664),
(9056, 27, 955.107, -403.439, -59.5107),
(9056, 28, 961.657, -396.63, -60.8377),
(9056, 29, 968.284, -389.058, -60.8377),
(9056, 30, 978.015, -379.612, -64.6384),
(9056, 31, 986.547, -370.816, -66.5624),
(9056, 32, 974.031, -355.625, -69.1521),
(9056, 33, 967.597, -349.477, -71.3905),
(9056, 34, 963.267, -343.735, -71.7394);
