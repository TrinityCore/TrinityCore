-- Karu SAI -- http://www.wowhead.com/npc=14874/karu#comments
SET @ENTRY := 14874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14874,1,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,14874,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,0,40,0,100,0,4,14874,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,13,14874,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,4,7,40,0,100,0,13,14874,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 13 Reached - Pause Waypoint"),
(@ENTRY,0,5,0,40,0,100,0,21,14874,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 21 Reached - Pause Waypoint"),
(@ENTRY,0,6,0,40,0,100,0,9,14874,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 9 Reached - Say Line 4"),
(@ENTRY,0,7,0,61,0,100,0,13,14874,0,0,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Waypoint 13 Reached - Say Line 7");

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (4,5) AND `SourceEntry`=14874;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,14874,0,0,29,1,10685,30,0,1,0,0,"","Karu - Do not run swine sai, if no swine is in range"),
(22,4,14874,0,0,29,1,10685,30,0,0,0,0,"","Karu - Run swine sai only, if swine is in range");

-- Actionlist SAI
SET @ENTRY := 1487400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,3,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 1487401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.068783,"Karu - On Script - Set Orienation 3.068783"),
(@ENTRY,9,2,0,0,0,100,0,4000,4000,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 5"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,20181,10685,0,0,0,0,0,"Karu - On Script - Set Data 1 1"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,20186,10685,0,0,0,0,0,"Karu - On Script - Set Data 1 1"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,6,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 6");

-- Actionlist SAI
SET @ENTRY := 1487402;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Karu - On Script - Say Line 7");

-- Swine SAI
SET @GUID := -20181;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10685;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,224.228043,-2852.1977,91.3376,0.6097,"Swine - On Data Set 1 1 - Move To Position");

-- Swine SAI
SET @GUID := -20186;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10685;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,224.73065,-2850.544,91.3375,6.0917,"Swine - On Data Set 1 1 - Move To Position");

DELETE FROM `creature_text` WHERE `entry`=14874;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(14874, 0, 0, 'Trok are you hungry? I''m making some food for us to eat! ', 12, 1, 100, 0, 0, 0, 10251, 'Karu'),
(14874, 1, 0, 'Here is some food for you Trok! Trok? Why are you running around like fearful human?', 12, 1, 100, 0, 0, 0, 10252, 'Karu'),
(14874, 2, 0, 'Suit yourself, I guess you are not that hungry. You can make your own food next time!', 12, 1, 100, 0, 0, 0, 0, 'Karu'),
(14874, 3, 0, 'Yummy. I love roasted Plainstrider.', 12, 1, 100, 0, 0, 0, 10292, 'Karu'),
(14874, 4, 0, 'I wonder if the pigs are hungry...', 12, 1, 100, 0, 0, 0, 10255, 'Karu'),
(14874, 5, 0, 'Are you piggies hungry? I have some food for you...', 12, 1, 100, 0, 0, 0, 10256, 'Karu'),
(14874, 6, 0, 'I guess you were hungry! Trok was supposed to have fed you earlier... What has he been doing all this time?', 12, 1, 100, 0, 0, 0, 10257, 'Karu'),
(14874, 7, 0, 'What happened to our pigs?', 12, 1, 100, 0, 0, 0, 10305, 'Karu');


DELETE FROM `waypoints` WHERE `entry`=14874;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14874, 1, 242.249, -2902.21, 97.9634,  'Karu'),
(14874, 2, 241.339, -2907.13, 98.0129,  'Karu'),
(14874, 3, 234.215, -2901.64, 98.1816,  'Karu'),
(14874, 4, 231.002, -2901.18, 98.2032,  'Karu'),
(14874, 5, 224.344, -2899.96, 97.2719,  'Karu'),
(14874, 6, 221.426, -2894.66, 96.1361,  'Karu'),
(14874, 7, 217.204, -2889.08, 94.318,   'Karu'),
(14874, 8, 212.104, -2882.55, 92.0763,  'Karu'),
(14874, 9, 212.402, -2876.92, 92.128,   'Karu'),
(14874, 10, 215.615, -2870.7, 91.6697,  'Karu'),
(14874, 11, 221.156, -2861.38, 91.6227, 'Karu'),
(14874, 12, 226.571, -2854.09, 91.5259, 'Karu'),
(14874, 13, 226.086, -2850.93, 91.4352, 'Karu'),
(14874, 14, 224.387, -2853.99, 91.4173, 'Karu'),
(14874, 15, 216.445, -2869.58, 91.6667, 'Karu'),
(14874, 16, 212.921, -2878.2, 91.9524,  'Karu'),
(14874, 17, 213.96, -2887.12, 93.1517,  'Karu'),
(14874, 18, 219.002, -2891.98, 95.3228, 'Karu'),
(14874, 19, 224.263, -2898.76, 97.0892, 'Karu'),
(14874, 20, 231.168, -2900.84, 98.2114, 'Karu'),
(14874, 21, 241.121, -2900.6, 97.9936,  'Karu');
