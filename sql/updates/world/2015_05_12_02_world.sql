-- Grizzlyhills Pathing/Events -1
SET @NPC := 105919;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2659.377,`position_y`=-2080.199,`position_z`=4.346071 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2659.377,-2080.199,4.346071,0,0,0,0,100,0),
(@PATH,2,2666.377,-2073.199,4.346071,0,0,0,0,100,0),
(@PATH,3,2670.377,-2068.949,4.346071,0,0,0,0,100,0),
(@PATH,4,2672.989,-2066.296,4.340314,0,0,0,0,100,0),
(@PATH,5,2675.489,-2062.546,4.340314,0,0,0,0,100,0),
(@PATH,6,2677.239,-2060.296,4.340314,0,0,0,0,100,0),
(@PATH,7,2678.989,-2057.796,4.340314,0,0,0,0,100,0),
(@PATH,8,2677.343,-2060.426,4.340314,0,0,0,0,100,0),
(@PATH,9,2675.593,-2062.676,4.340314,0,0,0,0,100,0),
(@PATH,10,2672.564,-2066.647,4.346634,0,0,0,0,100,0),
(@PATH,11,2670.314,-2068.897,4.346634,0,0,0,0,100,0),
(@PATH,12,2666.814,-2072.397,4.346634,0,0,0,0,100,0),
(@PATH,13,2659.411,-2080.233,4.331409,0,0,0,0,100,0),
(@PATH,14,2654.911,-2084.233,4.331409,0,0,0,0,100,0),
(@PATH,15,2653.411,-2085.733,4.331409,0,0,0,0,100,0),
(@PATH,16,2648.899,-2089.858,4.311839,0,0,0,0,100,0),
(@PATH,17,2646.649,-2091.858,4.311839,0,0,0,0,100,0),
(@PATH,18,2643.899,-2094.108,4.311839,0,0,0,0,100,0),
(@PATH,19,2640.707,-2096.753,4.415871,0,0,0,0,100,0),
(@PATH,20,2638.457,-2098.503,4.415871,0,0,0,0,100,0),
(@PATH,21,2634.457,-2101.253,5.165871,0,0,0,0,100,0),
(@PATH,22,2634.269,-2101.723,5.301712,0,0,0,0,100,0),
(@PATH,23,2632.769,-2102.723,5.551712,0,0,0,0,100,0),
(@PATH,24,2629.269,-2105.473,6.301712,0,0,0,0,100,0),
(@PATH,25,2629.244,-2105.614,6.409963,0,0,0,0,100,0),
(@PATH,26,2633.158,-2102.466,5.38058,0,0,0,0,100,0),
(@PATH,27,2634.658,-2101.466,5.13058,0,0,0,0,100,0),
(@PATH,28,2638.408,-2098.466,4.38058,0,0,0,0,100,0);

-- Pathing for  Entry: 27501 'TDB FORMAT' 
SET @NPC := 105928;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2650.357,`position_y`=-2025.178,`position_z`=4.323929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2650.357,-2025.178,4.323929,0,0,0,0,100,0),
(@PATH,2,2653.107,-2027.178,4.323929,0,0,0,0,100,0),
(@PATH,3,2661.607,-2033.178,4.323929,0,0,0,0,100,0),
(@PATH,4,2664.357,-2035.323,4.346634,0,0,0,0,100,0),
(@PATH,5,2666.857,-2037.323,4.346634,0,0,0,0,100,0),
(@PATH,6,2666.913,-2037.288,4.346634,0,0,0,0,100,0),
(@PATH,7,2664.103,-2035.223,4.346634,0,0,0,0,100,0),
(@PATH,8,2661.603,-2033.223,4.346634,0,0,0,0,100,0),
(@PATH,9,2652.902,-2026.893,4.187136,0,0,0,0,100,0),
(@PATH,10,2650.152,-2024.893,4.187136,0,0,0,0,100,0),
(@PATH,11,2646.152,-2022.143,4.187136,0,0,0,0,100,0),
(@PATH,12,2644.652,-2021.143,3.937136,0,0,0,0,100,0),
(@PATH,13,2641.632,-2018.958,4.027632,0,0,0,0,100,0),
(@PATH,14,2641.649,-2019.105,3.777639,0,0,0,0,100,0),
(@PATH,15,2641.879,-2019.022,3.937136,0,0,0,0,100,0),
(@PATH,16,2644.629,-2021.022,3.937136,0,0,0,0,100,0),
(@PATH,17,2645.879,-2022.022,4.187136,0,0,0,0,100,0),
(@PATH,18,2650.129,-2025.022,4.187136,0,0,0,0,100,0);

-- Pathing for  Entry: 27501 'TDB FORMAT' 
SET @NPC := 105904;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2606.301,`position_y`=-2092.257,`position_z`=7.300018 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2606.301,-2092.257,7.300018,0,0,0,0,100,0),
(@PATH,2,2614.706,-2104.54,7.32203,0,0,0,0,100,0),
(@PATH,3,2614.56,-2104.616,7.087479,0,0,0,0,100,0),
(@PATH,4,2614.464,-2104.489,7.307891,0,0,0,0,100,0),
(@PATH,5,2606.464,-2092.739,7.307891,0,0,0,0,100,0),
(@PATH,6,2606.129,-2092.514,7.232858,0,0,0,0,100,0),
(@PATH,7,2605.879,-2092.014,7.232858,0,0,0,0,100,0),
(@PATH,8,2603.379,-2088.014,6.982858,0,0,0,0,100,0),
(@PATH,9,2599.288,-2081.792,7.103763,0,0,0,0,100,0),
(@PATH,10,2596.038,-2076.792,7.103763,0,0,0,0,100,0),
(@PATH,11,2593.906,-2073.879,6.877389,0,0,0,0,100,0),
(@PATH,12,2592.156,-2070.879,6.877389,0,0,0,0,100,0),
(@PATH,13,2591.965,-2070.718,6.863516,0,0,0,0,100,0),
(@PATH,14,2594.261,-2073.978,6.842519,0,0,0,0,100,0),
(@PATH,15,2595.761,-2076.728,7.092519,0,0,0,0,100,0),
(@PATH,16,2599.636,-2081.92,7.189054,0,0,0,0,100,0),
(@PATH,17,2603.386,-2087.92,7.189054,0,0,0,0,100,0);

-- Westfall Brigade Marine SAI
SET @ENTRY := 27501;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,10000,10000,10000,49,0,0,0,0,0,0,19,27500,10,0,0,0,0,0,"Westfall Brigade Marine - Out of Combat - Start Attacking");

-- Conquest Hold Berserker SAI
SET @ENTRY := 27500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,2,0,1,0,100,0,10000,10000,10000,10000,49,0,0,0,0,0,0,19,27501,10,0,0,0,0,0,"Conquest Hold Berserker - Out of Combat - Start Attacking");

UPDATE `creature_template` SET `AIName`="" WHERE `entry`=27131;
-- Grizzly Bear SAI
SET @ENTRY := 27131;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 2713100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Enable Combat Movement"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Play Emote 7"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Play Emote 7"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Disable Combat Movement"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,89,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Bear - On Script - Start Random Movement");

-- allow movement
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid` IN (27259, 26679) AND `source_type`=0 AND `id`=0 AND `link`=0;
-- Dragonflayer Flamebinder SAI
SET @ENTRY := 27259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=14;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,14,0,1,0,100,0,5000,8000,5000,8000,11,48213,0,0,0,0,0,19,26785,25,0,0,0,0,0,"Dragonflayer Flamebinder - Out of Combat - Cast 'Dragonflayer Crone Fire'");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=48213;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 48213, 0, 0, 31, 0, 3, 26785, 0, 0, 0, 0, '', 'Flame - only targets Bunny');

DELETE FROM `creature_addon` WHERE `guid` IN (103389, 103390, 107363, 110490, 107373, 110493, 11049, 110494, 110492, 116277, 116275, 116274, 116276, 116278, 110489);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(116277,0,0,8,1,0, ''),
(116275,0,0,8,1,0, ''),
(116274,0,0,8,1,0, ''),
(116276,0,0,8,1,0, ''),
(116278,0,0,8,1,0, ''),
(110489,0,0,0,1,214, ''),
(110492,0,0,0,1,214, ''),
(110494,0,0,0,1,214, ''),
(110490,0,0,0,1,214, ''),
(110493,0,0,0,1,214, ''),
(107363,0,0,1,1,0, ''),
(103389,0,0,0,1,1, ''),
(103390,0,0,0,1,1, ''),
(107373,0,0,1,1,0, '');

-- Graymist Hunter SAI
SET @ENTRY := 26592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,15000,20000,15000,20000,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,"Graymist Hunter - Out of Combat - Play Emote 53");

-- Pathing for  Entry: 26679 'TDB FORMAT' 
SET @NPC := 100911;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4346.669,`position_y`=-2484.654,`position_z`=240.982 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4346.669,-2484.654,240.982,0,0,0,0,100,0),
(@PATH,2,4347.169,-2484.904,240.982,0,0,0,0,100,0),
(@PATH,3,4348.169,-2488.654,241.982,0,0,0,0,100,0),
(@PATH,4,4349.169,-2492.404,242.232,0,0,0,0,100,0),
(@PATH,5,4350.169,-2495.154,242.982,0,0,0,0,100,0),
(@PATH,6,4351.169,-2498.904,243.732,0,0,0,0,100,0),
(@PATH,7,4352.729,-2503.633,244.4913,0,0,0,0,100,0),
(@PATH,8,4352.479,-2508.633,244.7413,0,0,0,0,100,0),
(@PATH,9,4352.229,-2516.383,245.4913,0,0,0,0,100,0),
(@PATH,10,4352.513,-2516.505,245.5218,0,0,0,0,100,0),
(@PATH,11,4352.513,-2519.755,245.5218,0,0,0,0,100,0),
(@PATH,12,4353.422,-2530.827,245.4402,0,0,0,0,100,0),
(@PATH,13,4353.167,-2531.085,245.3185,0,0,0,0,100,0),
(@PATH,14,4353.443,-2530.941,245.3693,0,0,0,0,100,0),
(@PATH,15,4352.554,-2519.469,245.4435,0,0,0,0,100,0),
(@PATH,16,4352.554,-2508.719,244.9435,0,0,0,0,100,0),
(@PATH,17,4352.496,-2503.444,244.2976,0,0,0,0,100,0),
(@PATH,18,4351.496,-2499.694,243.5476,0,0,0,0,100,0),
(@PATH,19,4350.246,-2495.944,243.0476,0,0,0,0,100,0),
(@PATH,20,4349.746,-2493.194,242.5476,0,0,0,0,100,0),
(@PATH,21,4348.746,-2490.194,242.0476,0,0,0,0,100,0),
(@PATH,22,4347.996,-2487.444,241.2976,0,0,0,0,100,0),
(@PATH,23,4346.94,-2484.907,240.7707,0,0,0,0,100,0),
(@PATH,24,4343.19,-2483.907,240.2707,0,0,0,0,100,0),
(@PATH,25,4339.44,-2482.907,239.7707,0,0,0,0,100,0),
(@PATH,26,4339.217,-2482.614,239.4836,0,0,0,0,100,0),
(@PATH,27,4337.717,-2482.114,239.2336,0,0,0,0,100,0),
(@PATH,28,4325.967,-2481.114,238.9836,0,0,0,0,100,0),
(@PATH,29,4320.836,-2480.163,238.4939,0,0,0,0,100,0),
(@PATH,30,4327.4,-2469.229,238.7592,0,0,0,0,100,0),
(@PATH,31,4339.832,-2457.689,239.1528,0,0,0,0,100,0),
(@PATH,32,4339.467,-2457.954,239.0422,0,0,0,0,100,0),
(@PATH,33,4339.559,-2457.928,239.3148,0,0,0,0,100,0),
(@PATH,34,4327.204,-2469.653,238.7065,0,0,0,0,100,0),
(@PATH,35,4320.694,-2480.362,238.713,0,0,0,0,100,0),
(@PATH,36,4330.444,-2481.362,239.213,0,0,0,0,100,0),
(@PATH,37,4337.947,-2482.492,239.5395,0,0,0,0,100,0),
(@PATH,38,4342.447,-2483.492,240.0395,0,0,0,0,100,0),
(@PATH,39,4346.447,-2484.492,240.5395,0,0,0,0,100,0);

SET @NPC := 100914;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4316.283,`position_y`=-2489.055,`position_z`=238.5876 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4316.283,-2489.055,238.5876,0,0,0,0,100,0),
(@PATH,2,4316.529,-2488.824,238.7166,0,0,0,0,100,0),
(@PATH,3,4320.335,-2479.741,238.3421,0,0,0,0,100,0),
(@PATH,4,4316.585,-2474.241,237.8421,0,0,0,0,100,0),
(@PATH,5,4313.78,-2470.097,237.5021,0,0,0,0,100,0),
(@PATH,6,4309.78,-2469.847,237.0021,0,0,0,0,100,0),
(@PATH,7,4306.03,-2469.347,236.5021,0,0,0,0,100,0),
(@PATH,8,4305.914,-2469.415,236.0416,0,0,0,0,100,0),
(@PATH,9,4303.414,-2469.165,235.5416,0,0,0,0,100,0),
(@PATH,10,4300.414,-2469.415,235.0416,0,0,0,0,100,0),
(@PATH,11,4297.414,-2469.915,234.2916,0,0,0,0,100,0),
(@PATH,12,4294.664,-2470.165,234.0416,0,0,0,0,100,0),
(@PATH,13,4290.664,-2470.415,233.2916,0,0,0,0,100,0),
(@PATH,14,4285.664,-2471.165,232.5416,0,0,0,0,100,0),
(@PATH,15,4285.473,-2471.28,232.3787,0,0,0,0,100,0),
(@PATH,16,4285.223,-2471.28,232.1287,0,0,0,0,100,0),
(@PATH,17,4277.473,-2472.28,231.8787,0,0,0,0,100,0),
(@PATH,18,4273.628,-2472.75,231.6418,0,0,0,0,100,0),
(@PATH,19,4267.374,-2468.811,231.65,0,0,0,0,100,0),
(@PATH,20,4263.313,-2458.705,231.5937,0,0,0,0,100,0),
(@PATH,21,4260.986,-2447.287,231.4928,0,0,0,0,100,0),
(@PATH,22,4258.986,-2445.537,231.4928,0,0,0,0,100,0),
(@PATH,23,4257.986,-2444.537,231.4928,0,0,0,0,100,0),
(@PATH,24,4257.986,-2443.787,231.4928,0,0,0,0,100,0),
(@PATH,25,4257.486,-2441.787,231.4928,0,0,0,0,100,0),
(@PATH,26,4257.564,-2441.543,231.4707,0,0,0,0,100,0),
(@PATH,27,4258.564,-2443.043,231.4707,0,0,0,0,100,0),
(@PATH,28,4258.814,-2444.543,231.4707,0,0,0,0,100,0),
(@PATH,29,4258.814,-2445.543,231.4707,0,0,0,0,100,0),
(@PATH,30,4259.061,-2445.944,231.3457,0,0,0,0,100,0),
(@PATH,31,4261.061,-2447.694,231.3457,0,0,0,0,100,0),
(@PATH,32,4263.474,-2458.961,231.6339,0,0,0,0,100,0),
(@PATH,33,4267.657,-2468.89,231.6431,0,0,0,0,100,0),
(@PATH,34,4273.792,-2472.652,231.7187,0,0,0,0,100,0),
(@PATH,35,4284.542,-2471.152,232.2187,0,0,0,0,100,0),
(@PATH,36,4284.735,-2471.201,232.4085,0,0,0,0,100,0),
(@PATH,37,4285.485,-2471.201,232.4085,0,0,0,0,100,0),
(@PATH,38,4289.235,-2470.701,233.1585,0,0,0,0,100,0),
(@PATH,39,4292.985,-2470.451,233.6585,0,0,0,0,100,0),
(@PATH,40,4296.985,-2469.951,234.4085,0,0,0,0,100,0),
(@PATH,41,4299.985,-2469.451,234.9085,0,0,0,0,100,0),
(@PATH,42,4303.572,-2469.107,235.8506,0,0,0,0,100,0),
(@PATH,43,4306.572,-2469.357,236.3506,0,0,0,0,100,0),
(@PATH,44,4311.322,-2469.857,237.1006,0,0,0,0,100,0),
(@PATH,45,4314.023,-2470.285,237.6709,0,0,0,0,100,0),
(@PATH,46,4318.273,-2476.535,238.1709,0,0,0,0,100,0),
(@PATH,47,4320.4,-2480.026,238.3305,0,0,0,0,100,0),
(@PATH,48,4316.393,-2488.953,238.7333,0,0,0,0,100,0),
(@PATH,49,4316.283,-2489.055,238.5876,0,0,0,0,100,0);

SET @NPC := 100910;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4338.308,`position_y`=-2566.474,`position_z`=245.7152 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4338.308,-2566.474,245.7152,0,0,0,0,100,0),
(@PATH,2,4339.808,-2567.724,245.7152,0,0,0,0,100,0),
(@PATH,3,4341.308,-2568.724,245.7152,0,0,0,0,100,0),
(@PATH,4,4342.308,-2569.724,245.7152,0,0,0,0,100,0),
(@PATH,5,4342.308,-2570.724,245.7152,0,0,0,0,100,0),
(@PATH,6,4345.808,-2573.724,245.7152,0,0,0,0,100,0),
(@PATH,7,4346.808,-2574.724,245.7152,0,0,0,0,100,0),
(@PATH,8,4345.922,-2575.817,245.7339,0,0,0,0,100,0),
(@PATH,9,4344.672,-2574.817,245.7339,0,0,0,0,100,0),
(@PATH,10,4342.422,-2570.817,245.7339,0,0,0,0,100,0),
(@PATH,11,4342.422,-2569.817,245.7339,0,0,0,0,100,0),
(@PATH,12,4341.422,-2568.817,245.7339,0,0,0,0,100,0),
(@PATH,13,4340.922,-2566.567,245.7339,0,0,0,0,100,0),
(@PATH,14,4340.74,-2566.308,245.6353,0,0,0,0,100,0),
(@PATH,15,4337.99,-2566.308,245.6353,0,0,0,0,100,0),
(@PATH,16,4326.376,-2555.018,245.3248,0,0,0,0,100,0),
(@PATH,17,4317.626,-2555.518,244.8248,0,0,0,0,100,0),
(@PATH,18,4313.838,-2555.828,244.4903,0,0,0,0,100,0),
(@PATH,19,4310.838,-2556.578,243.9903,0,0,0,0,100,0),
(@PATH,20,4308.088,-2557.078,243.4903,0,0,0,0,100,0),
(@PATH,21,4305.229,-2558.031,242.7213,0,0,0,0,100,0),
(@PATH,22,4304.324,-2561.028,243.1423,0,0,0,0,100,0),
(@PATH,23,4306.574,-2564.278,243.6423,0,0,0,0,100,0),
(@PATH,24,4309.324,-2568.528,244.1423,0,0,0,0,100,0),
(@PATH,25,4311.824,-2572.278,244.6423,0,0,0,0,100,0),
(@PATH,26,4314.824,-2576.528,245.3923,0,0,0,0,100,0),
(@PATH,27,4319.487,-2583.055,246.6341,0,0,0,0,100,0),
(@PATH,28,4322.487,-2587.055,247.1341,0,0,0,0,100,0),
(@PATH,29,4324.737,-2590.055,247.6341,0,0,0,0,100,0),
(@PATH,30,4327.237,-2593.055,248.1341,0,0,0,0,100,0),
(@PATH,31,4328.737,-2595.055,248.6341,0,0,0,0,100,0),
(@PATH,32,4304.205,-2560.936,242.7079,0,0,0,0,100,0),
(@PATH,33,4305.315,-2557.807,243.0027,0,0,0,0,100,0),
(@PATH,34,4308.065,-2557.307,243.5027,0,0,0,0,100,0),
(@PATH,35,4310.815,-2556.557,244.0027,0,0,0,0,100,0),
(@PATH,36,4314.014,-2555.685,244.613,0,0,0,0,100,0),
(@PATH,37,4320.764,-2555.435,245.113,0,0,0,0,100,0),
(@PATH,38,4326.62,-2555.132,245.2907,0,0,0,0,100,0),
(@PATH,39,4338.271,-2566.441,245.7103,0,0,0,0,100,0);

SET @NPC := 100930;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4243.639,`position_y`=-2493.448,`position_z`=231.605 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4243.639,-2493.448,231.605,0,0,0,0,100,0),
(@PATH,2,4245.705,-2503.654,231.4428,0,0,0,0,100,0),
(@PATH,3,4239.67,-2514.717,231.6307,0,0,0,0,100,0),
(@PATH,4,4239.557,-2514.651,231.5394,0,0,0,0,100,0),
(@PATH,5,4239.811,-2514.36,231.6327,0,0,0,0,100,0),
(@PATH,6,4245.605,-2503.552,231.3878,0,0,0,0,100,0),
(@PATH,7,4243.532,-2493.164,231.6278,0,0,0,0,100,0),
(@PATH,8,4237.666,-2485.062,231.6341,0,0,0,0,100,0);

SET @NPC := 98081;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3677.196,`position_y`=-3262.262,`position_z`=271.4974 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3677.196,-3262.262,271.4974,0,0,0,0,100,0),
(@PATH,2,3675.946,-3263.512,270.4974,0,0,0,0,100,0),
(@PATH,3,3673.446,-3266.012,267.7474,0,0,0,0,100,0),
(@PATH,4,3672.196,-3267.262,266.4974,0,0,0,0,100,0),
(@PATH,5,3670.696,-3268.762,264.4974,0,0,0,0,100,0),
(@PATH,6,3669.344,-3269.899,262.9258,0,0,0,0,100,0),
(@PATH,7,3665.594,-3268.399,259.1758,0,0,0,0,100,0),
(@PATH,8,3664.594,-3267.899,258.1758,0,0,0,0,100,0),
(@PATH,9,3657.594,-3265.399,252.4258,0,0,0,0,100,0),
(@PATH,10,3656.094,-3264.742,251.3945,0,0,0,0,100,0),
(@PATH,11,3648.844,-3264.492,245.1445,0,0,0,0,100,0),
(@PATH,12,3647.094,-3264.242,243.6445,0,0,0,0,100,0),
(@PATH,13,3642.363,-3263.935,240.8384,0,0,0,0,100,0),
(@PATH,14,3642.113,-3265.185,239.8384,0,0,0,0,100,0),
(@PATH,15,3640.613,-3270.685,237.3384,0,0,0,0,100,0),
(@PATH,16,3638.873,-3276.277,236.2841,0,0,0,0,100,0),
(@PATH,17,3637.873,-3283.027,235.7841,0,0,0,0,100,0),
(@PATH,18,3637.623,-3284.527,235.5341,0,0,0,0,100,0),
(@PATH,19,3637.542,-3284.433,235.5938,0,0,0,0,100,0),
(@PATH,20,3637.792,-3282.933,235.5938,0,0,0,0,100,0),
(@PATH,21,3639.209,-3276.042,236.5234,0,0,0,0,100,0),
(@PATH,22,3640.459,-3271.292,237.2734,0,0,0,0,100,0),
(@PATH,23,3641.709,-3265.792,239.5234,0,0,0,0,100,0),
(@PATH,24,3642.543,-3264.088,240.9962,0,0,0,0,100,0),
(@PATH,25,3646.543,-3264.338,243.2462,0,0,0,0,100,0),
(@PATH,26,3649.043,-3264.588,245.2462,0,0,0,0,100,0),
(@PATH,27,3656.203,-3264.957,251.5793,0,0,0,0,100,0),
(@PATH,28,3657.703,-3265.457,252.5793,0,0,0,0,100,0),
(@PATH,29,3664.453,-3267.957,258.0793,0,0,0,0,100,0),
(@PATH,30,3665.453,-3268.457,259.0793,0,0,0,0,100,0),
(@PATH,31,3669.533,-3269.755,263.1148,0,0,0,0,100,0),
(@PATH,32,3670.783,-3268.755,264.6148,0,0,0,0,100,0),
(@PATH,33,3672.283,-3267.255,266.1148,0,0,0,0,100,0),
(@PATH,34,3673.033,-3266.005,267.8648,0,0,0,0,100,0),
(@PATH,35,3675.783,-3263.505,270.3648,0,0,0,0,100,0),
(@PATH,36,3676.181,-3263.232,270.6315,0,0,0,0,100,0),
(@PATH,37,3677.431,-3261.982,271.8815,0,0,0,0,100,0),
(@PATH,38,3679.931,-3259.982,274.1315,0,0,0,0,100,0),
(@PATH,39,3683.181,-3256.982,276.8815,0,0,0,0,100,0),
(@PATH,40,3683.275,-3257.129,276.9308,0,0,0,0,100,0),
(@PATH,41,3680.025,-3259.629,274.4308,0,0,0,0,100,0),
(@PATH,42,3677.151,-3262.089,271.6892,0,0,0,0,100,0);

SET @NPC := 98083;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3608.663,`position_y`=-3311.686,`position_z`=224.8323 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3608.663,-3311.686,224.8323,0,0,0,0,100,0),
(@PATH,2,3610.913,-3313.436,224.5823,0,0,0,0,100,0),
(@PATH,3,3612.413,-3314.436,224.5823,0,0,0,0,100,0),
(@PATH,4,3621.448,-3320.278,226.055,0,0,0,0,100,0),
(@PATH,5,3624.948,-3320.278,226.555,0,0,0,0,100,0),
(@PATH,6,3630.948,-3320.278,227.055,0,0,0,0,100,0),
(@PATH,7,3632.198,-3320.278,227.555,0,0,0,0,100,0),
(@PATH,8,3631.236,-3320.25,227.2929,0,0,0,0,100,0),
(@PATH,9,3632.486,-3320.25,227.7929,0,0,0,0,100,0),
(@PATH,10,3633.486,-3320.25,228.2929,0,0,0,0,100,0),
(@PATH,11,3637.236,-3317,229.5429,0,0,0,0,100,0),
(@PATH,12,3637.84,-3316.242,229.9589,0,0,0,0,100,0),
(@PATH,13,3633.259,-3320.148,227.9277,0,0,0,0,100,0),
(@PATH,14,3632.259,-3320.148,227.4277,0,0,0,0,100,0),
(@PATH,15,3631.009,-3320.148,227.1777,0,0,0,0,100,0),
(@PATH,16,3624.759,-3320.398,226.4277,0,0,0,0,100,0),
(@PATH,17,3621.314,-3320.251,225.9905,0,0,0,0,100,0),
(@PATH,18,3613.064,-3315.001,224.7405,0,0,0,0,100,0),
(@PATH,19,3611.064,-3313.501,224.7405,0,0,0,0,100,0),
(@PATH,20,3608.404,-3311.755,224.6184,0,0,0,0,100,0),
(@PATH,21,3605.154,-3300.005,224.3684,0,0,0,0,100,0);

-- drakkari event
DELETE FROM `creature` where `id` IN (26582, 26583) and `guid` NOT IN (116602);

-- Horrified Drakkari Shaman SAI
SET @GUID := -116602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26583;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,2000,1000,2000,88,11660200,11660201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - Out of Combat - Run Random Script"),
(@GUID,0,1,2,63,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Active On"),
(@GUID,0,2,3,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Visibility On"),
(@GUID,0,3,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Reset - Set Reactstate Aggressive");

-- Actionlist SAI
SET @ENTRY := 11660200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,26583,3,120000,0,0,0,8,0,0,0,4690.051270,-2045.848755,194.348404,3.160445,"On Script - Summon Creature 'Horrified Drakkari Shaman'");

-- Actionlist SAI
SET @ENTRY := 11660201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,12,26582,3,120000,0,0,0,8,0,0,0,4690.051270,-2045.848755,194.348404,3.160445,"On Script - Summon Creature 'Horrified Drakkari Warrior'");

-- Horrified Drakkari Shaman SAI
SET @ENTRY := 26582;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Just Created - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,1,0,0,0,88,2658200,2658201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Data Set 1 0 - Run Random Script"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Just Created - Say Line 0"),
(@ENTRY,0,3,0,40,0,100,0,20,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Warrior - On Waypoint 20 Reached - Despawn Instant");

-- Horrified Drakkari Shaman SAI
SET @ENTRY := 26583;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,63,0,100,0,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Set Active On"),
(@ENTRY,0,1,2,61,0,100,0,1,0,0,0,88,2658200,2658201,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Run Random Script"),
(@ENTRY,0,2,0,61,0,100,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Just Created - Say Line 0"),
(@ENTRY,0,3,0,40,0,100,0,20,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrified Drakkari Shaman - On Waypoint 20 Reached - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 2658200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,1,2658200,0,0,3000,0,0,0,0,0,0,0,0,0,"On Script - Start Waypoint");

-- Actionlist SAI
SET @ENTRY := 2658201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,53,1,2658201,0,0,3000,0,0,0,0,0,0,0,0,0,"On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=2658200;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(2658200, 1, 4680.19, -2044.68, 189.441),
(2658200, 2, 4662.73, -2045.93, 184.189),
(2658200, 3, 4651.83, -2051.77, 184.368),
(2658200, 4, 4643.71, -2060.59, 184.18),
(2658200, 5, 4635.04, -2061.83, 184.1),
(2658200, 6, 4617.55, -2061.84, 184.182),
(2658200, 7, 4596.55, -2061.57, 184.186),
(2658200, 8, 4579.06, -2061.36, 184.186),
(2658200, 9, 4562.37, -2062.32, 184.167),
(2658200, 10, 4551.87, -2062.12, 178.315),
(2658200, 11, 4534.37, -2062.09, 168.354),
(2658200, 12, 4523.88, -2061.96, 162.377),
(2658200, 13, 4509.88, -2062.05, 160.823),
(2658200, 14, 4498.51, -2063.27, 160.823),
(2658200, 15, 4490.23, -2069.98, 160.823),
(2658200, 16, 4492.74, -2078.85, 160.823),
(2658200, 17, 4496.31, -2094.72, 160.8),
(2658200, 18, 4506.59, -2103.06, 160.831),
(2658200, 19, 4518.52, -2110.39, 160.833),
(2658200, 20, 4533.43, -2119.56, 160.845),
(2658200, 21, 4545.35, -2130.19, 160.842);

DELETE FROM `waypoints` WHERE `entry`=2658201;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(2658201, 1, 4692.36, -2045.14, 195.516),
(2658201, 2, 4674.86, -2044.91, 186.46),
(2658201, 3, 4671.36, -2044.89, 185.043),
(2658201, 4, 4659.89, -2044.58, 184.318),
(2658201, 5, 4648.06, -2033.35, 184.184),
(2658201, 6, 4641.49, -2028.73, 183.862),
(2658201, 7, 4630.25, -2028.22, 184.182),
(2658201, 8, 4612.76, -2028.2, 184.185),
(2658201, 9, 4591.76, -2027.91, 184.189),
(2658201, 10, 4574.26, -2027.67, 184.185),
(2658201, 11, 4563.76, -2027.47, 184.166),
(2658201, 12, 4556.77, -2027.4, 180.928),
(2658201, 13, 4539.27, -2027.25, 170.966),
(2658201, 14, 4525.27, -2027.07, 162.997),
(2658201, 15, 4511.28, -2026.61, 160.823),
(2658201, 16, 4494.03, -2024.8, 160.824),
(2658201, 17, 4488.19, -2012.02, 161.055),
(2658201, 18, 4492.56, -1993.64, 160.824),
(2658201, 19, 4503.51, -1980.34, 160.824),
(2658201, 20, 4517.17, -1973.46, 160.824);

DELETE FROM `creature_text` WHERE `entry` IN (26583, 26582);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(26583, 0, 0, 'Drak\'Tharon be lost, mon!', 12, 0, 100, 0, 0, 0, 25857, 0, 'Horrified Drakkari'),
(26583, 0, 1, 'Da Scourge be everywhere, mon!', 12, 0, 100, 0, 0, 0, 25853, 0, 'Horrified Drakkari'),
(26583, 0, 2, 'Every troll for himself, mon!', 12, 0, 100, 0, 0, 0, 25855, 0, 'Horrified Drakkari'),
(26583, 0, 3, 'Ruuun!', 12, 0, 100, 0, 0, 0, 25859, 0, 'Horrified Drakkari'),
-- 
(26582, 0, 0, 'Drak\'Tharon be lost, mon!', 12, 0, 100, 0, 0, 0, 25857, 0, 'Horrified Drakkari'),
(26582, 0, 1, 'Da Scourge be everywhere, mon!', 12, 0, 100, 0, 0, 0, 25853, 0, 'Horrified Drakkari'),
(26582, 0, 2, 'Every troll for himself, mon!', 12, 0, 100, 0, 0, 0, 25855, 0, 'Horrified Drakkari'),
(26582, 0, 3, 'Ruuun!', 12, 0, 100, 0, 0, 0, 25859, 0, 'Horrified Drakkari');
