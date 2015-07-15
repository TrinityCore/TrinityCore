-- 
-- Okla
DELETE FROM `creature_text` WHERE `entry` IN (14873, 5907);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextId`) VALUES 
(14873, 0, 0, 'Can I go collect more rocks for my necklace, Papa?', 12, 1, 100, 1, 0, 0, 'Okla',10274),
(14873, 1, 0, 'Dabu! I will be careful Papa!', 12, 1, 100, 1, 0, 0, 'Okla', 10276),
(14873, 2, 0, 'Ooohh... This rock is nice and colorful. Let\'s see if I can find more like it...', 12, 1, 100, 1, 0, 0, 'Okla', 10277),
(14873, 3, 0, 'Hmm... That rock is nice, but too small.', 12, 1, 100, 1, 0, 0, 'Okla', 10278),
(14873, 4, 0, 'This is a shiney rock. I\'ll put it in my bucket. Ok, I just need a few more...', 12, 1, 100, 1, 0, 0, 'Okla', 10279),
(14873, 5, 0, 'I bet my friend Gruk would like this rock for the spear he is making! It\'s very sharp... I hope he likes it.', 12, 1, 100, 1, 0, 0, 'Okla', 10280),
(14873, 6, 0, 'There... That should be enough rocks to make a necklace. I should probably get home now anyway.', 12, 1, 100, 1, 0, 0, 'Okla', 10281),
(5907, 0, 0, 'Yes you may, Okla. But do not stray too far from home.', 12, 1, 100, 1, 0, 0, 'Kranal Fiss', 10275);

-- Okla SAI
SET @ENTRY := 14873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,14873,1,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,14873,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,13,14873,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,18,14873,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 18 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,24,14873,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 24 Reached - Run Script"),
(@ENTRY,0,5,0,40,0,100,0,29,14873,0,0,80,@ENTRY*100+04,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 29 Reached - Run Script"),
(@ENTRY,0,6,0,40,0,100,0,35,14873,0,0,80,@ENTRY*100+05,0,0,0,0,0,1,0,0,0,0,0,0,0,"Okla - On Waypoint 35 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1487300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,21000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,1,0,0,0,0,0,0,19,5907,50,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1487301;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 1487302;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 1487303;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 1487304;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 5");

-- Actionlist SAI
SET @ENTRY := 1487305;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 6");

DELETE FROM `waypoints` WHERE `entry`=14873;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(14873, 1, 270.076, -3036.6, 97.6192),
(14873, 2, 262.171, -3043.45, 96.5053),
(14873, 3, 251.328, -3055.55, 96.1454),
(14873, 4, 246.888, -3070.92, 95.2793),
(14873, 5, 242.449, -3081.3, 91.82),
(14873, 6, 232.826, -3106.67, 93.3165),
(14873, 7, 226.41, -3120.76, 93.3475),
(14873, 8, 213.921, -3151.01, 91.2851),
(14873, 9, 221.681, -3147.9, 91.374),
(14873, 10, 214.549, -3134.64, 91.9876),
(14873, 11, 210.931, -3139.95, 91.6514),
(14873, 12, 214.059, -3139.64, 91.7),
(14873, 13, 213.426, -3131.78, 92.1297),
(14873, 14, 220.194, -3140.72, 91.7517),
(14873, 15, 225.395, -3139.1, 92.0847),
(14873, 16, 220.857, -3140.83, 91.7662),
(14873, 17, 218.769, -3132.79, 92.4983),
(14873, 18, 226.814, -3137.56, 92.169),
(14873, 19, 225.496, -3132.89, 92.7818),
(14873, 20, 213.603, -3148.39, 91.4489),
(14873, 21, 219.055, -3151.2, 91.2139),
(14873, 22, 220.469, -3141.93, 91.6344),
(14873, 23, 214.852, -3148.32, 91.4558),
(14873, 24, 218.373, -3144.99, 91.5714),
(14873, 25, 224.091, -3149.02, 91.2304),
(14873, 26, 224.591, -3145.02, 91.4801),
(14873, 27, 219.022, -3147.38, 91.4735),
(14873, 28, 220.167, -3139.75, 91.8958),
(14873, 29, 225.033, -3133.14, 92.8028),
(14873, 30, 222.021, -3128.32, 93.0422),
(14873, 31, 228.338, -3126.35, 92.9595),
(14873, 32, 229.495, -3129.22, 92.6818),
(14873, 33, 232.12, -3128.11, 92.5988),
(14873, 34, 227.003, -3137.58, 92.1461),
(14873, 35, 220.002, -3132.38, 92.659),
(14873, 36, 225.874, -3102.36, 93.6962),
(14873, 37, 233.086, -3085.54, 91.6788),
(14873, 38, 235.152, -3069.81, 91.8706),
(14873, 39, 239.821, -3061.03, 95.4022),
(14873, 40, 256.123, -3047.91, 96.2473),
(14873, 41, 267.05, -3039.04, 96.9212),
(14873, 42, 271.093, -3035.98, 97.6501),
(14873, 43, 278.975, -3029.68, 97.3919),
(14873, 44, 280.125, -3029.01, 97.3502);

UPDATE `creature_addon` SET `path_id`=59070 WHERE `guid`=13174;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=13174;
DELETE FROM `waypoint_data` WHERE `id` IN (59070);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`action_chance`,`wpguid`) VALUES
(59070,0,265.967000,-3050.670000,96.921500,0,0,0,100,0),
(59070,1,263.671661,-3047.959961,96.665161,0,0,0,100,0),
(59070,2,260.557739,-3038.177002,96.740677,0,0,0,100,0),
(59070,3,262.354950,-3036.125732,96.990982,0,0,0,100,0),
(59070,4,261.470215,-3036.779541,96.961708,0,60000,0,100,0),
(59070,5,259.890106,-3038.696045,96.572845,0,0,0,100,0),
(59070,6,265.967468,-3050.672363,96.921516,0,0,0,100,0),
(59070,7,265.967000,-3050.670000,96.921500,0,30000,0,100,0);
UPDATE `creature` SET `position_x`=280.125, `position_y`=-3029.01, `position_z`=97.3502, `orientation`= 3.764 WHERE `guid`=14873;
