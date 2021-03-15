-- Mogg SAI
SET @ENTRY := 14908;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14908,1,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,5,14908,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 5 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,6,14908,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,7,14908,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 7 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,17,14908,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 17 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,27,14908,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 27 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,28,14908,0,0,80,@ENTRY*100+05,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 28 Reached - Run Script"),
(@ENTRY,0,7,8,40,0,100,0,29,14908,0,0,80,@ENTRY*100+06,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Waypoint 29 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1490800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,89,5,0,0,0,0,0,19,14909,50,0,0,0,0,0,"Mogg - On Script - Start Random Movement"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1490801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 2"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Set Run On");

-- Actionlist SAI
SET @ENTRY := 1490802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 1490803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 5");

-- Actionlist SAI
SET @ENTRY := 1490804;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,6000,0,0,0,0,0,10,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Set Run Off"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,6,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 6");

-- Actionlist SAI
SET @ENTRY := 1490805;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,14909,50,0,0,0,0,0,"Mogg - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mogg - On Script - Say Line 7");

-- Actionlist SAI
SET @ENTRY := 1490806;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,80000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,8,5000,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 8"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,19,14909,50,0,0,0,0,0,"On Script - Set Data 2 2");

-- Pooka SAI
SET @ENTRY := 14909;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Data Set 1 1 - Run Script"),
(@ENTRY,0,1,2,38,0,100,0,2,2,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Data Set 2 2 - Set Run Off"),
(@ENTRY,0,2,3,61,0,100,0,2,2,0,0,53,0,14909,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Data Set 2 2 - Start Waypoint"),
(@ENTRY,0,3,0,61,0,100,0,2,2,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Data Set 2 2 - Say Line 1"),
(@ENTRY,0,4,0,40,0,100,0,6,14909,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Waypoint 6 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,12,14909,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Waypoint 12 Reached - Start Random Movement");

-- Actionlist SAI
SET @ENTRY := 1490900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Script - Start Random Movement"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,1021.28,-2233.42,93.33,5.05,"Pooka - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Script - Set Run Off"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,1013.24,-2221.47,92.9837,2.5,"Pooka - On Script - Move To Position"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,8,0,0,0,1017.95,-2224.33,93.08,4.7,"Pooka - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pooka - On Script - Start Random Movement");

-- Actionlist SAI
SET @ENTRY := 1490901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 18"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 18");

DELETE FROM `creature_text` WHERE `CreatureID` IN (14908, 14909);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(14908, 0, 0, 'I am going to practice and become a warrior like my father!', 12, 0, 100, 1, 0, 0, 10293, 'Mogg'),
(14908, 1, 0, 'Now to find an unsuspecting Harpy!', 12, 0, 100, 1, 0, 0, 10294, 'Mogg'),
(14908, 2, 0, 'There''s one! For the Horde!', 12, 0, 100, 1, 0, 0, 10295, 'Mogg'),
(14908, 3, 0, 'Take that you mangy Harpy! Hyaa!', 12, 0, 100, 1, 0, 0, 10296, 'Mogg'),
(14908, 4, 0, 'You can''t get away from a warrior of the Horde! Take that! And that!', 12, 0, 100, 1, 0, 0, 10297, 'Mogg'),
(14908, 5, 0, 'Now go back home where you belong!', 12, 0, 100, 1, 0, 0, 10298, 'Mogg'),
(14908, 6, 0, 'Aaahhh... Another glorious victory for The Horde!', 12, 0, 100, 1, 0, 0, 10299, 'Mogg'),
(14908, 7, 0, 'Yes right away momma!', 12, 0, 100, 1, 0, 0, 10301, 'Mogg'),
(14908, 8, 0, 'When is poppa coming back from the fights in Warsong? It has been so long...', 12, 0, 100, 1, 0, 0, 10303, 'Mogg'),

(14909, 0, 0, 'Mogg, get inside. It is not safe out there while your father is gone.', 12, 0, 100, 1, 0, 0, 10300, 'Pooka'),
(14909, 1, 0, 'Soon child... Very soon.', 12, 0, 100, 1, 0, 0, 10304, 'Pooka');

DELETE FROM `waypoints` WHERE `entry`=14908;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14908,1,1022.24,-2235.11,93.3114,     'Mogg'),
(14908,2,1023.37,-2238.18,92.3744,     'Mogg'),
(14908,3,1024.2,-2243.96,92.4697,      'Mogg'),
(14908,4,1022.05,-2244.86,92.3385,     'Mogg'),
(14908,5,1020.21,-2242.92,92.2321,     'Mogg'),
(14908,6,1034.19,-2250.56,92.8656,     'Mogg'),
(14908,7,1033.85,-2258.61,93.6338,     'Mogg'),
(14908,8,1037.68,-2262.02,93.8145,     'Mogg'),
(14908,9,1036.96,-2269.7,93.7554,      'Mogg'),
(14908,10,1042,-2273.46,93.6932,       'Mogg'),
(14908,11,1042.7,-2275.52,93.5781,     'Mogg'),
(14908,12,1046.52,-2274.46,93.6045,    'Mogg'),
(14908,13,1050.26,-2270.44,93.4986,    'Mogg'),
(14908,14,1049.74,-2266.86,93.3475,    'Mogg'),
(14908,15,1048.05,-2263.53,93.2249,    'Mogg'),
(14908,16,1041.05,-2258.77,93.4525,    'Mogg'),
(14908,17,1039.14,-2253.68,92.9611,    'Mogg'),
(14908,18,1032.8,-2253.55,93.3633,     'Mogg'),
(14908,19,1025.83,-2258.54,93.1641,    'Mogg'),
(14908,20,1021.94,-2266.24,92.8306,    'Mogg'),
(14908,21,1022.81,-2272.14,92.6617,    'Mogg'),
(14908,22,1027.02,-2277.89,92.6709,    'Mogg'),
(14908,23,1036.56,-2280.12,93.1197,    'Mogg'),
(14908,24,1046.66,-2275.73,93.5356,    'Mogg'),
(14908,25,1049.61,-2269.77,93.5509,    'Mogg'),
(14908,26,1045.76,-2261.03,93.2522,    'Mogg'),
(14908,27,1038.3,-2254.31,93.1039,     'Mogg'),
(14908,28,1028.89,-2245.04,92.4171,    'Mogg'),
(14908,29,1016.87,-2225.77,93.1025,    'Mogg');

DELETE FROM `waypoints` WHERE `entry`=14909;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14909, 1, 1025.19, -2239.77, 92.4462,  'Pooka'),
(14909, 2, 1032.77, -2242.09, 92.1655,  'Pooka'),
(14909, 3, 1040.45, -2241.81, 91.9457,  'Pooka'),
(14909, 4, 1040.65, -2233.18, 91.735,   'Pooka'),
(14909, 5, 1037.72, -2227.49, 91.8037,  'Pooka'),
(14909, 6, 1035.65, -2224.96, 91.9576,  'Pooka'), -- cry
(14909, 7, 1039.38, -2231.71, 91.7299,  'Pooka'),
(14909, 8, 1041.05, -2240.78, 91.9556,  'Pooka'),
(14909, 9, 1031.51, -2241.51, 92.1757,  'Pooka'),
(14909, 10, 1025.37, -2240.84, 92.4583, 'Pooka'),
(14909, 11, 1020.98, -2232.5, 93.3069,  'Pooka'),
(14909, 12, 1014.45, -2225.92, 93.0579, 'Pooka'); -- move rndm
