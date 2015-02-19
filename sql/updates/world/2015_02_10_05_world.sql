-- Pathing for  Entry: 25979 'TDB FORMAT' 
SET @NPC := 107300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3289.213,`position_y`=5620.369,`position_z`=51.0953 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3289.213,5620.369,51.0953,0,0,0,0,100,0),
(@PATH,2,3289.156,5612.807,51.6523,0,0,0,0,100,0),
(@PATH,3,3285.626,5645.205,51.53279,0,0,0,0,100,0),
(@PATH,4,3283.541,5652.846,52.70237,0,0,0,0,100,0),
(@PATH,5,3280.611,5683.929,54.8549,0,0,0,0,100,0),
(@PATH,6,3303.37,5707.606,60.20351,0,0,0,0,100,0),
(@PATH,7,3282.027,5687.42,56.04992,0,0,0,0,100,0),
(@PATH,8,3279.962,5672.618,53.23326,0,0,0,0,100,0),
(@PATH,9,3284.723,5649.133,52.33985,0,0,0,0,100,0);
-- 0x1C09144760195EC000000C0000579A79 .go 3289.213 5620.369 51.0953
-- Inquisitor Salrand SAI
SET @ENTRY := 25584;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,6,0,1,0,100,0,5000,5000,10000,10000,11,45777,0,0,0,0,0,10,119586,25594,0,0,0,0,0,"Inquisitor Salrand - Out of Combat - Cast 'Salrand's Beam'");

-- Pathing for  Entry: 25217 'TDB FORMAT' 
SET @NPC := 122872;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4113.013,`position_y`=6276.871,`position_z`=25.68058 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4113.013,6276.871,25.68058,0,0,0,0,100,0),
(@PATH,2,4090.676,6280.604,27.56935,0,0,0,0,100,0),
(@PATH,3,4074.31,6276.669,26.26191,0,0,0,0,100,0),
(@PATH,4,4063.338,6284.883,23.54415,0,0,0,0,100,0),
(@PATH,5,4060.495,6308.033,24.63371,0,0,0,0,100,0),
(@PATH,6,4064.796,6325.54,25.33357,0,0,0,0,100,0),
(@PATH,7,4062.167,6349.621,24.96839,0,0,0,0,100,0),
(@PATH,8,4055.423,6363.151,27.49203,0,0,0,0,100,0),
(@PATH,9,4061.251,6351.451,25.36894,0,0,0,0,100,0),
(@PATH,10,4064.368,6335.375,25.38478,0,0,0,0,100,0),
(@PATH,11,4061.08,6310.811,24.90634,0,0,0,0,100,0),
(@PATH,12,4059.284,6298.654,24.53846,0,0,0,0,100,0),
(@PATH,13,4069.346,6279.003,24.92667,0,0,0,0,100,0),
(@PATH,14,4084.886,6280.17,27.70065,0,0,0,0,100,0),
(@PATH,15,4107.833,6280.248,25.45559,0,0,0,0,100,0);
-- 0x1C0914476018A04000000C000057EEC0 .go 4113.013 6276.871 25.68058

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 57031;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2797.154,`position_y`=6620.249,`position_z`=48.24942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2797.154,6620.249,48.24942,0,0,0,0,100,0),
(@PATH,2,2807.472,6623.047,46.9419,0,0,0,0,100,0),
(@PATH,3,2822.777,6620.003,48.07745,0,0,0,0,100,0),
(@PATH,4,2828.091,6608.199,49.87174,0,0,0,0,100,0),
(@PATH,5,2829.904,6600.112,50.43536,0,0,0,0,100,0),
(@PATH,6,2825.405,6583.044,51.32146,0,0,0,0,100,0),
(@PATH,7,2812.032,6576.637,50.3959,0,0,0,0,100,0),
(@PATH,8,2808.558,6575.663,49.55042,0,0,0,0,100,0),
(@PATH,9,2791.914,6578.114,49.39709,0,0,0,0,100,0),
(@PATH,10,2790.871,6579.394,49.35609,0,0,0,0,100,0),
(@PATH,11,2793.273,6598.499,49.21821,0,0,0,0,100,0),
(@PATH,12,2797.287,6620.314,48.24408,0,0,0,0,100,0);
-- 0x1C091447601902C000000C0000588B21 .go 2797.154 6620.249 48.24942

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97489;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2755.648,`position_y`=6516.167,`position_z`=52.22083 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2755.648,6516.167,52.22083,0,0,0,0,100,0),
(@PATH,2,2739.121,6534.617,51.25744,0,0,0,0,100,0),
(@PATH,3,2736.37,6540.505,50.52654,0,0,0,0,100,0),
(@PATH,4,2736.999,6568.931,49.45178,0,0,0,0,100,0),
(@PATH,5,2745.165,6582.929,49.87815,0,0,0,0,100,0),
(@PATH,6,2749.685,6588.33,49.43536,0,0,0,0,100,0),
(@PATH,7,2764.539,6590.529,49.07096,0,0,0,0,100,0),
(@PATH,8,2783.451,6578.873,49.38116,0,0,0,0,100,0),
(@PATH,9,2790.408,6542.078,51.47867,0,0,0,0,100,0),
(@PATH,10,2781.756,6526.21,53.26818,0,0,0,0,100,0),
(@PATH,11,2759.35,6514.721,52.89858,0,0,0,0,100,0);
-- 0x1C091447601902C000000C0001588AE6 .go 2755.648 6516.167 52.22083

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97486;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2959.18,`position_y`=6518.749,`position_z`=72.95694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2959.18,6518.749,72.95694,0,0,0,0,100,0),
(@PATH,2,2943.816,6531.531,70.15851,0,0,0,0,100,0),
(@PATH,3,2922.839,6548.202,66.36589,0,0,0,0,100,0),
(@PATH,4,2905.143,6556.469,64.68446,0,0,0,0,100,0),
(@PATH,5,2886.449,6562.177,61.95524,0,0,0,0,100,0),
(@PATH,6,2870.039,6568.242,58.85592,0,0,0,0,100,0),
(@PATH,7,2849.421,6573.922,54.75926,0,0,0,0,100,0),
(@PATH,8,2864.578,6570.402,57.7508,0,0,0,0,100,0),
(@PATH,9,2880.555,6564.39,60.65393,0,0,0,0,100,0),
(@PATH,10,2900.065,6558.482,64.16826,0,0,0,0,100,0),
(@PATH,11,2916.618,6552.232,65.66638,0,0,0,0,100,0),
(@PATH,12,2939.966,6534.6,69.45979,0,0,0,0,100,0),
(@PATH,13,2950.899,6526.294,71.31409,0,0,0,0,100,0),
(@PATH,14,2978.666,6499.601,75.67303,0,0,0,0,100,0),
(@PATH,15,2959.18,6518.749,72.95694,0,0,0,0,100,0);
-- 0x1C091447601902C000000C00005893B1 .go 2959.18 6518.749 72.95694

-- Pathing for  Entry: 25611 'TDB FORMAT' 
SET @NPC := 97472;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3132.141,`position_y`=6364.85,`position_z`=87.00642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3132.141,6364.85,87.00642,0,0,0,0,100,0),
(@PATH,2,3145.254,6377.429,86.04013,0,0,0,0,100,0),
(@PATH,3,3150.995,6384.529,85.66245,0,0,0,0,100,0),
(@PATH,4,3150.954,6413.424,86.59067,0,0,0,0,100,0),
(@PATH,5,3148.383,6418.564,87.16897,0,0,0,0,100,0),
(@PATH,6,3127.888,6445.25,85.42545,0,0,0,0,100,0),
(@PATH,7,3125.299,6448.726,84.63122,0,0,0,0,100,0),
(@PATH,8,3098.482,6453.096,86.2816,0,0,0,0,100,0),
(@PATH,9,3092.813,6430.465,86.18443,0,0,0,0,100,0),
(@PATH,10,3092.439,6429.254,86.16457,0,0,0,0,100,0),
(@PATH,11,3090.803,6416.944,86.47922,0,0,0,0,100,0),
(@PATH,12,3080.703,6420.038,86.92494,0,0,0,0,100,0),
(@PATH,13,3066.926,6403.042,89.00624,0,0,0,0,100,0),
(@PATH,14,3071.34,6388.575,89.95999,0,0,0,0,100,0),
(@PATH,15,3071.793,6387.598,89.86023,0,0,0,0,100,0),
(@PATH,16,3092.656,6366.145,89.73042,0,0,0,0,100,0),
(@PATH,17,3109.781,6356.525,88.38365,0,0,0,0,100,0),
(@PATH,18,3114.204,6357.174,87.74312,0,0,0,0,100,0),
(@PATH,19,3132.181,6364.944,87.00461,0,0,0,0,100,0);
-- 0x1C091447601902C000000A000058AB81 .go 3132.141 6364.85 87.00642

-- Pathing for  Entry: 25475 'TDB FORMAT' 
SET @NPC := 107800;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2814.188,`position_y`=6720.133,`position_z`=9.794792 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2814.188,6720.133,9.794792,0,0,0,0,100,0),
(@PATH,2,2810.317,6723.547,9.082146,0,0,0,0,100,0);
-- 0x1C0914476018E0C000000C00005660EE .go 2814.188 6720.133 9.794792

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 110300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3067.602,`position_y`=6705.609,`position_z`=6.230121 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3067.602,6705.609,6.230121,0,0,0,0,100,0),
(@PATH,2,3051.766,6718.588,6.615577,0,0,0,0,100,0),
(@PATH,3,3024.569,6720.975,9.706598,0,0,0,0,100,0),
(@PATH,4,3031.904,6726.806,7.207738,0,0,0,0,100,0),
(@PATH,5,3033.154,6727.66,6.58389,0,0,0,0,100,0),
(@PATH,6,3068.976,6704.811,5.953619,0,0,0,0,100,0),
(@PATH,7,3095.539,6680.229,6.846659,0,0,0,0,100,0),
(@PATH,8,3095.83,6662.607,9.923321,0,0,0,0,100,0),
(@PATH,9,3099.785,6674.892,7.75151,0,0,0,0,100,0),
(@PATH,10,3090.089,6685.671,6.213068,0,0,0,0,100,0),
(@PATH,11,3067.523,6705.942,6.221252,0,0,0,0,100,0);
-- 0x1C0914476018E60000000C000058AEB8 .go 3067.602 6705.609 6.230121

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `id` IN (25244);
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid`=57067;

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 57066;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2431.173,`position_y`=6827.691,`position_z`=4.434509 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2431.173,6827.691,4.434509,0,0,0,0,100,0),
(@PATH,2,2417.92,6818.268,3.808835,0,0,0,0,100,0),
(@PATH,3,2401.83,6806.687,1.444491,0,0,0,0,100,0),
(@PATH,4,2397.053,6803.022,1.261812,0,0,0,0,100,0),
(@PATH,5,2415.603,6771.807,2.460288,0,0,0,0,100,0),
(@PATH,6,2444.461,6781.449,6.446399,0,0,0,0,100,0),
(@PATH,7,2448.987,6792.239,6.01413,0,0,0,0,100,0),
(@PATH,8,2466.415,6808.424,4.947993,0,0,0,0,100,0),
(@PATH,9,2479.129,6823.808,2.68948,0,0,0,0,100,0),
(@PATH,10,2480.822,6831.567,1.405943,0,0,0,0,100,0),
(@PATH,11,2481.074,6846.526,1.077314,0,0,0,0,100,0),
(@PATH,12,2453.165,6857.935,1.077329,0,0,0,0,100,0),
(@PATH,13,2438.796,6843.509,1.671256,0,0,0,0,100,0);
-- 0x1C0914476018E60000000A0000586C4C .go 2431.173 6827.691 4.434509

-- Pathing for  Entry: 25496 'TDB FORMAT' 
SET @NPC := 57059;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2414.351,`position_y`=6738.811,`position_z`=2.7648 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2414.351,6738.811,2.7648,0,0,0,0,100,0),
(@PATH,2,2411.604,6704.709,6.068311,0,0,0,0,100,0),
(@PATH,3,2411.347,6702.018,6.760894,0,0,0,0,100,0),
(@PATH,4,2452.357,6721.351,6.010249,0,0,0,0,100,0),
(@PATH,5,2466.691,6738.082,6.927616,0,0,0,0,100,0),
(@PATH,6,2495.109,6765.589,6.517776,0,0,0,0,100,0),
(@PATH,7,2513.06,6790.916,4.482207,0,0,0,0,100,0),
(@PATH,8,2523.949,6806.354,1.703682,0,0,0,0,100,0),
(@PATH,9,2532.222,6817.983,1.145756,0,0,0,0,100,0),
(@PATH,10,2546.355,6838.362,1.049538,0,0,0,0,100,0),
(@PATH,11,2548.539,6846.931,0.8498411,0,0,0,0,100,0),
(@PATH,12,2506.485,6784.912,5.38059,0,0,0,0,100,0),
(@PATH,13,2483.945,6763.865,6.803366,0,0,0,0,100,0),
(@PATH,14,2480.173,6760.685,6.7745,0,0,0,0,100,0),
(@PATH,15,2419.531,6764.058,3.010518,0,0,0,0,100,0),
(@PATH,16,2414.283,6738.649,2.879114,0,0,0,0,100,0);
-- 0x1C0914476018E60000000C0000587988 .go 2414.351 6738.811 2.7648

DELETE FROM `creature_addon` WHERE `guid` IN (110289,57070,57063, 57065, 57067,57064,57062,57068,57060,57058,57057, 57056,57061,110291,110301,110290,110285,57072);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(57063, 0, 0, 0, 0, 69, ''),
(57065, 0, 0, 0, 0, 234, ''),
(57067, 0, 0, 0, 0, 234, ''),
(57064, 0, 0, 0, 0, 234, ''),
(57062, 0, 0, 0, 0, 69, ''),
(57068, 0, 0, 0, 0, 234, ''),
(57060, 0, 0, 0, 0, 234, ''),
(57058, 0, 0, 0, 0, 234, ''),
(57057, 0, 0, 0, 0, 234, ''),
(57056, 0, 0, 0, 0, 234, ''),
(57061, 0, 0, 0, 0, 27, ''),
(110291, 0, 0, 0, 0, 27, ''),
(110301, 0, 0, 0, 0, 69, ''),
(110290, 0, 0, 0, 0, 27, ''),
(110285, 0, 0, 0, 0, 27, ''),
(57072, 0, 0, 0, 0, 69, ''),
(110289, 0, 0, 0, 0, 27, ''),
(57070, 0, 0, 0, 0, 27, '');

DELETE FROM `creature_addon` WHERE `guid` IN (112665,112663,112662,112660,112659,112666,112679,112673,112678,112671,112667,112672,56752,112741,56327,112661,112658,56325, 112668, 112670, 112669, 56322);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(56325, 0, 0, 0, 0, 4, ''),
(112668, 0, 0, 0, 0, 4, ''),
(112670, 0, 0, 0, 0, 4, ''),
(112669, 0, 0, 0, 0, 4, ''),
(56322, 0, 0, 0, 0, 4, ''),
(112661, 0, 0, 0, 0, 234, ''),
(112658, 0, 0, 0, 0, 234, ''),
(56327, 0, 0, 0, 0, 234, ''),
(112741, 0, 0, 0, 0, 27, ''),
(56752, 0, 0, 0, 0, 27, ''),
(112672, 0, 0, 1, 0, 0, ''),
-- 
(112678, 0, 0, 0, 0, 4, ''),
(112671, 0, 0, 0, 0, 4, ''),
(112667, 0, 0, 0, 0, 4, ''),
-- 
(112673, 0, 0, 1, 0, 0, ''),
(112679, 0, 0, 1, 0, 0, ''),
(112666, 0, 0, 0, 0, 234, ''),
(112665, 0, 0, 0, 0, 234, ''),
(112659, 0, 0, 0, 0, 234, ''),
(112660, 0, 0, 0, 0, 234, ''),
(112663, 0, 0, 0, 0, 234, ''),
(112662, 0, 0, 0, 0, 234, '');

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112755;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1863.071,`position_y`=5721.263,`position_z`=0.5444731 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,2,1871.592,5727.264,0.5210824,0,0,0,0,100,0),
(@PATH,3,1865.804,5766.675,0.8066133,0,0,0,0,100,0),
(@PATH,4,1861.19,5769.085,0.636929,0,0,0,0,100,0),
(@PATH,5,1853.291,5777.555,0.8031902,0,0,0,0,100,0),
(@PATH,6,1838.134,5783.222,0.6275423,0,0,0,0,100,0),
(@PATH,7,1838.138,5783.196,0.5076787,0,0,0,0,100,0),
(@PATH,8,1838.279,5783.279,0.609849,0,0,0,0,100,0),
(@PATH,9,1853.601,5777.178,0.8158144,0,0,0,0,100,0),
(@PATH,10,1872.918,5754.421,0.8373558,0,0,0,0,100,0),
(@PATH,11,1873.445,5750.554,0.7919877,0,0,0,0,100,0),
(@PATH,12,1857.673,5717.76,0.05196175,0,0,0,0,100,0),
(@PATH,13,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,14,1871.617,5727.281,0.5215871,0,0,0,0,100,0),
(@PATH,15,1865.804,5766.67,0.806583,0,0,0,0,100,0),
(@PATH,16,1861.121,5769.259,0.6014363,0,0,0,0,100,0),
(@PATH,17,1853.309,5777.537,0.8029698,0,0,0,0,100,0),
(@PATH,18,1838.146,5783.217,0.6276386,0,0,0,0,100,0),
(@PATH,19,1838.138,5783.196,0.5076787,0,0,0,0,100,0),
(@PATH,20,1838.511,5783.279,0.6102685,0,0,0,0,100,0),
(@PATH,21,1853.596,5777.181,0.8157681,0,0,0,0,100,0),
(@PATH,22,1872.897,5754.442,0.837615,0,0,0,0,100,0),
(@PATH,23,1873.44,5750.595,0.7921225,0,0,0,0,100,0),
(@PATH,24,1857.677,5717.557,0.05224757,0,0,0,0,100,0),
(@PATH,25,1863.071,5721.263,0.5444731,0,0,0,0,100,0),
(@PATH,26,1871.631,5727.291,0.5218816,0,0,0,0,100,0),
(@PATH,27,1865.809,5766.73,0.8069472,0,0,0,0,100,0),
(@PATH,28,1861.136,5769.112,0.6354876,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0000D90C39 .go 1863.071 5721.263 0.5444731

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1853.63,`position_y`=5846.966,`position_z`=2.740726 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1853.63,5846.966,2.740726,0,0,0,0,100,0),
(@PATH,2,1874.7,5836.919,4.813838,0,0,0,0,100,0),
(@PATH,3,1876.592,5812.892,4.801723,0,0,0,0,100,0),
(@PATH,4,1872.844,5797.556,3.118221,0,0,0,0,100,0),
(@PATH,5,1875.815,5806.438,3.974422,0,0,0,0,100,0),
(@PATH,6,1876.563,5816.451,5.334268,0,0,0,0,100,0),
(@PATH,7,1877.032,5828.594,4.914,0,0,0,0,100,0),
(@PATH,8,1862.273,5842.986,4.152772,0,0,0,0,100,0),
(@PATH,9,1853.646,5846.958,2.74155,0,0,0,0,100,0),
(@PATH,10,1849.364,5848.809,2.105818,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0000D90AF7 .go 1853.63 5846.966 2.740726


-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112766;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1821.645,`position_y`=5874.956,`position_z`=2.705887 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1821.645,5874.956,2.705887,0,0,0,0,100,0),
(@PATH,2,1824.808,5874.413,2.800447,0,0,0,0,100,0),
(@PATH,3,1827.45,5854.379,1.631521,0,0,0,0,100,0),
(@PATH,4,1822.537,5840.488,1.119883,0,0,0,0,100,0),
(@PATH,5,1819.79,5826.655,0.8782115,0,0,0,0,100,0),
(@PATH,6,1816.417,5813.835,0.7204496,0,0,0,0,100,0),
(@PATH,7,1816.219,5813.744,0.5043496,0,0,0,0,100,0),
(@PATH,8,1816.581,5813.962,0.5907121,0,0,0,0,100,0),
(@PATH,9,1820.05,5826.836,0.8006111,0,0,0,0,100,0),
(@PATH,10,1828.175,5856.271,1.831071,0,0,0,0,100,0),
(@PATH,11,1828.932,5859.332,2.491501,0,0,0,0,100,0),
(@PATH,12,1816.584,5895.463,0.9250998,0,0,0,0,100,0),
(@PATH,13,1821.645,5874.956,2.705887,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B000159120F .go 1821.645 5874.956 2.705887

UPDATE `creature` SET `spawndist`=10 WHERE  `guid` IN (112682, 112762);

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112761;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1869.091,`position_y`=5953.953,`position_z`=6.38201 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1869.091,5953.953,6.38201,0,0,0,0,100,0),
(@PATH,2,1879.48,5943.066,7.114405,0,0,0,0,100,0),
(@PATH,3,1905.42,5926.519,12.31866,0,0,0,0,100,0),
(@PATH,4,1907.966,5924.864,12.90823,0,0,0,0,100,0),
(@PATH,5,1907.694,5924.906,12.73229,0,0,0,0,100,0),
(@PATH,6,1888.924,5936.15,8.416003,0,0,0,0,100,0),
(@PATH,7,1885.86,5938.519,7.107553,0,0,0,0,100,0),
(@PATH,8,1879.301,5943.302,7.06257,0,0,0,0,100,0),
(@PATH,9,1863.642,5963.351,5.116355,0,0,0,0,100,0),
(@PATH,10,1848.166,5986.37,2.711081,0,0,0,0,100,0),
(@PATH,11,1856.702,5973.741,4.321182,0,0,0,0,100,0),
(@PATH,12,1868.008,5955.694,6.300377,0,0,0,0,100,0),
(@PATH,13,1869.092,5953.951,6.382379,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B00005916B8 .go 1869.091 5953.953 6.38201

-- Pathing for  Entry: 25522 'TDB FORMAT' 
SET @NPC := 112764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1949.82,`position_y`=5779.809,`position_z`=10.0687 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1949.82,5779.809,10.0687,0,0,0,0,100,0),
(@PATH,2,1949.888,5780.269,10.04539,0,0,0,0,100,0),
(@PATH,3,1959.407,5805.928,11.8103,0,0,0,0,100,0),
(@PATH,4,1955.581,5821.07,13.57725,0,0,0,0,100,0),
(@PATH,5,1949.136,5832.18,12.86915,0,0,0,0,100,0),
(@PATH,6,1947.718,5833.966,12.66496,0,0,0,0,100,0),
(@PATH,7,1944.919,5838.312,12.17096,0,0,0,0,100,0),
(@PATH,8,1945.014,5838.031,12.05043,0,0,0,0,100,0),
(@PATH,9,1945.333,5838.103,12.31259,0,0,0,0,100,0),
(@PATH,10,1950.632,5829.593,14.2812,0,0,0,0,100,0),
(@PATH,11,1959.209,5813.076,12.95494,0,0,0,0,100,0),
(@PATH,12,1958.309,5800.833,11.20766,0,0,0,0,100,0),
(@PATH,13,1953.69,5789.138,10.24553,0,0,0,0,100,0),
(@PATH,14,1952.009,5763.52,9.059128,0,0,0,0,100,0),
(@PATH,15,1949.82,5779.809,10.0687,0,0,0,0,100,0);
-- 0x1C0914476018EC8000000B0001D91590 .go 1949.82 5779.809 10.0687

-- Pathing for  Entry: 25464 'TDB FORMAT' 
SET @NPC := 132708;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2822.261,`position_y`=5519.366,`position_z`=53.74162 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2822.261,5519.366,53.74162,0,0,0,0,100,0),
(@PATH,2,2823.339,5522.105,53.3661,0,0,0,0,100,0),
(@PATH,3,2816.756,5522.176,52.7483,0,0,0,0,100,0),
(@PATH,4,2815.625,5523.958,52.19855,0,0,0,0,100,0),
(@PATH,5,2815.16,5520.309,52.78535,0,0,0,0,100,0),
(@PATH,6,2820.333,5521.584,53.39899,0,0,0,0,100,0),
(@PATH,7,2824.778,5510.136,55.34394,0,0,0,0,100,0),
(@PATH,8,2815.103,5518.417,53.53315,0,0,0,0,100,0),
(@PATH,9,2819.598,5522.154,52.91368,0,0,0,0,100,0),
(@PATH,10,2822.082,5521.53,53.60404,0,0,0,0,100,0),
(@PATH,11,2818.371,5523.108,52.66743,0,0,0,0,100,0),
(@PATH,12,2819.409,5516.978,53.96194,0,0,0,0,100,0),
(@PATH,13,2823.384,5522.104,53.37409,0,0,0,0,100,0),
(@PATH,14,2825.392,5523.739,52.87629,0,0,0,0,100,0),
(@PATH,15,2815.691,5521.912,52.45197,0,0,0,0,100,0),
(@PATH,16,2814.33,5518.599,52.92414,0,0,0,0,100,0),
(@PATH,17,2815.653,5522.167,52.41706,0,0,0,0,100,0),
(@PATH,18,2821.683,5522.525,53.24909,0,0,0,0,100,0),
(@PATH,19,2822.436,5520.497,53.40412,0,0,0,0,100,0),
(@PATH,20,2822.451,5523.602,53.0274,0,0,0,0,100,0),
(@PATH,21,2815.243,5522.016,52.44831,0,0,0,0,100,0),
(@PATH,22,2818.638,5521.292,53.17999,0,0,0,0,100,0),
(@PATH,23,2822.181,5517.789,54.00129,0,0,0,0,100,0),
(@PATH,24,2822.296,5519.241,53.7021,0,0,0,0,100,0),
(@PATH,25,2816.71,5523.35,52.70033,0,0,0,0,100,0),
(@PATH,26,2819.778,5520.425,53.55138,0,0,0,0,100,0),
(@PATH,27,2824.004,5522.665,53.19855,0,0,0,0,100,0),
(@PATH,28,2822.11,5517.678,54.01472,0,0,0,0,100,0),
(@PATH,29,2823.61,5518.823,53.80622,0,0,0,0,100,0),
(@PATH,30,2824.499,5512.02,55.12739,0,0,0,0,100,0),
(@PATH,31,2824.968,5518.775,54.21228,0,0,0,0,100,0),
(@PATH,32,2822.294,5517.814,53.99824,0,0,0,0,100,0),
(@PATH,33,2818.368,5520.58,53.24421,0,0,0,0,100,0),
(@PATH,34,2822.198,5523.147,52.89338,0,0,0,0,100,0),
(@PATH,35,2819.597,5521.721,53.0246,0,0,0,0,100,0),
(@PATH,36,2822.367,5519.021,53.98109,0,0,0,0,100,0),
(@PATH,37,2826.401,5522.089,53.23542,0,0,0,0,100,0),
(@PATH,38,2816.553,5521.619,52.96187,0,0,0,0,100,0),
(@PATH,39,2825.091,5521.14,53.50007,0,0,0,0,100,0),
(@PATH,40,2822.17,5524.09,52.63996,0,0,0,0,100,0),
(@PATH,41,2823.85,5520.973,53.41511,0,0,0,0,100,0),
(@PATH,42,2823.884,5524.132,52.88813,0,0,0,0,100,0),
(@PATH,43,2823.595,5521.119,53.4554,0,0,0,0,100,0),
(@PATH,44,2822.149,5521.591,53.26643,0,0,0,0,100,0),
(@PATH,45,2825.091,5523.302,52.98078,0,0,0,0,100,0);
-- 0x1C0914476018DE0000000B00005919F4 .go 2822.261 5519.366 53.74162

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122683;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3856.668,`position_y`=6592.438,`position_z`=165.8591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.668,6592.438,165.8591,0,0,0,0,100,0),
(@PATH,2,3845.146,6580.313,167.2839,0,0,0,0,100,0),
(@PATH,3,3819.979,6552.679,171.2212,0,0,0,0,100,0),
(@PATH,4,3834.785,6568.925,168.5641,0,0,0,0,100,0),
(@PATH,5,3856.229,6592.091,166.1844,0,0,0,0,100,0),
(@PATH,6,3856.884,6592.668,166.1273,0,0,0,0,100,0),
(@PATH,7,3856.668,6592.438,165.8591,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923F6 .go 3856.668 6592.438 165.8591

DELETE FROM `creature_formations` WHERE `leaderGUID`=122683;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122683, 122683, 0, 0, 2, 0, 0),
(122683, 122668, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122679;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3877.737,`position_y`=6617.055,`position_z`=165.4812 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3877.737,6617.055,165.4812,0,0,0,0,100,0),
(@PATH,2,3876.591,6615.319,165.2154,0,0,0,0,100,0),
(@PATH,3,3876.513,6615.291,165.0491,0,0,0,0,100,0),
(@PATH,4,3881.765,6622.608,165.9126,0,0,0,0,100,0),
(@PATH,5,3887.004,6630.904,166.6272,0,0,0,0,100,0),
(@PATH,6,3890.648,6642.739,166.3096,0,0,0,0,100,0),
(@PATH,7,3895.043,6655.15,167.9105,0,0,0,0,100,0),
(@PATH,8,3892.582,6650.448,166.6568,0,0,0,0,100,0),
(@PATH,9,3890.725,6641.271,166.7931,0,0,0,0,100,0),
(@PATH,10,3886.259,6630.026,166.4984,0,0,0,0,100,0),
(@PATH,11,3877.767,6616.941,165.558,0,0,0,0,100,0),
(@PATH,12,3876.568,6615.188,165.1826,0,0,0,0,100,0),
(@PATH,13,3876.513,6615.291,165.0491,0,0,0,0,100,0),
(@PATH,14,3881.689,6622.583,165.9073,0,0,0,0,100,0),
(@PATH,15,3886.83,6631.109,166.6665,0,0,0,0,100,0),
(@PATH,16,3890.699,6642.743,166.3585,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923E0 .go 3877.737 6617.055 165.4812

DELETE FROM `creature_formations` WHERE `leaderGUID`=122679;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122679, 122679, 0, 0, 2, 0, 0),
(122679, 122664, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122682;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3802.633,`position_y`=6610.85,`position_z`=160.9254 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3802.633,6610.85,160.9254,0,0,0,0,100,0),
(@PATH,2,3814.249,6608.161,162.6728,0,0,0,0,100,0),
(@PATH,3,3817.92,6607.578,162.962,0,0,0,0,100,0),
(@PATH,4,3817.757,6607.444,162.8091,0,0,0,0,100,0),
(@PATH,5,3809.16,6609.176,161.7681,0,0,0,0,100,0),
(@PATH,6,3794.561,6613.893,159.8145,0,0,0,0,100,0),
(@PATH,7,3787.977,6622.479,157.1806,0,0,0,0,100,0),
(@PATH,8,3777.748,6635.708,153.5259,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C000059215B .go 3802.633 6610.85 160.9254

DELETE FROM `creature_formations` WHERE `leaderGUID`=122682;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122682, 122682, 0, 0, 2, 0, 0),
(122682, 122667, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122671;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3876.684,`position_y`=6542.924,`position_z`=175.354 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3876.684,6542.924,175.354,0,0,0,0,100,0),
(@PATH,2,3865.112,6532.595,176.6299,0,0,0,0,100,0),
(@PATH,3,3868.344,6534.336,176.2356,0,0,0,0,100,0),
(@PATH,4,3880.712,6554.647,173.5269,0,0,0,0,100,0),
(@PATH,5,3880.566,6581.678,168.6076,0,0,0,0,100,0),
(@PATH,6,3881.85,6561.938,171.8416,0,0,0,0,100,0),
(@PATH,7,3876.725,6542.939,175.2055,0,0,0,0,100,0),
(@PATH,8,3864.951,6532.556,176.746,0,0,0,0,100,0),
(@PATH,9,3868.344,6534.336,176.2356,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592014 .go 3876.684 6542.924 175.354

DELETE FROM `creature_formations` WHERE `leaderGUID`=122671;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122671, 122671, 0, 0, 2, 0, 0),
(122671, 122660, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122681;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3856.668,`position_y`=6592.438,`position_z`=165.8591 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.668,6592.438,165.8591,0,0,0,0,100,0),
(@PATH,2,3845.146,6580.313,167.2839,0,0,0,0,100,0),
(@PATH,3,3819.979,6552.679,171.2212,0,0,0,0,100,0),
(@PATH,4,3834.785,6568.925,168.5641,0,0,0,0,100,0),
(@PATH,5,3856.229,6592.091,166.1844,0,0,0,0,100,0),
(@PATH,6,3856.884,6592.668,166.1273,0,0,0,0,100,0),
(@PATH,7,3856.668,6592.438,165.8591,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005923F6 .go 3856.668 6592.438 165.8591

DELETE FROM `creature_formations` WHERE `leaderGUID`=122681;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122681, 122681, 0, 0, 2, 0, 0),
(122681, 122666, 4, 0, 2, 0, 0);

UPDATE `creature` SET `spawndist`=15 WHERE  `guid`=122549;
UPDATE `creature` SET `spawndist`=20 WHERE  `guid`=122548;

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3772.382,`position_y`=6700.643,`position_z`=150.745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3772.382,6700.643,150.745,0,0,0,0,100,0),
(@PATH,2,3765.955,6706.445,152.0959,0,0,0,0,100,0),
(@PATH,3,3760.302,6711.588,152.1358,0,0,0,0,100,0),
(@PATH,4,3750.747,6726.564,151.7103,0,0,0,0,100,0),
(@PATH,5,3749.879,6729.181,151.658,0,0,0,0,100,0),
(@PATH,6,3750.81,6726.225,151.6613,0,0,0,0,100,0),
(@PATH,7,3771.484,6701.582,151.0565,0,0,0,0,100,0),
(@PATH,8,3772.745,6700.572,150.9297,0,0,0,0,100,0),
(@PATH,9,3772.382,6700.643,150.745,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592493 .go 3772.382 6700.643 150.745

DELETE FROM `creature_formations` WHERE `leaderGUID`=122675;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122675, 122675, 0, 0, 2, 0, 0),
(122675, 122661, 4, 0, 2, 0, 0);


-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122678;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3765.189,`position_y`=6646.188,`position_z`=152.2007 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3765.189,6646.188,152.2007,0,0,0,0,100,0),
(@PATH,2,3761.339,6649.458,151.591,0,0,0,0,100,0),
(@PATH,3,3761.412,6649.275,151.5081,0,0,0,0,100,0),
(@PATH,4,3775.332,6638.132,152.7523,0,0,0,0,100,0),
(@PATH,5,3784.681,6626.98,155.8878,0,0,0,0,100,0),
(@PATH,6,3791.935,6616.86,158.9415,0,0,0,0,100,0),
(@PATH,7,3802.772,6610.692,160.7068,0,0,0,0,100,0),
(@PATH,8,3814.205,6608.264,162.5391,0,0,0,0,100,0),
(@PATH,9,3817.96,6607.651,162.9075,0,0,0,0,100,0),
(@PATH,10,3817.757,6607.444,162.8091,0,0,0,0,100,0),
(@PATH,11,3809.104,6609.054,161.8425,0,0,0,0,100,0),
(@PATH,12,3794.503,6613.823,159.8757,0,0,0,0,100,0),
(@PATH,13,3788.144,6622.311,157.2462,0,0,0,0,100,0),
(@PATH,14,3777.916,6635.792,153.5504,0,0,0,0,100,0),
(@PATH,15,3765.363,6646.322,152.2002,0,0,0,0,100,0),
(@PATH,16,3761.535,6649.459,151.5641,0,0,0,0,100,0),
(@PATH,17,3761.412,6649.275,151.5081,0,0,0,0,100,0),
(@PATH,18,3775.165,6638.005,152.7578,0,0,0,0,100,0),
(@PATH,19,3784.59,6626.891,155.6862,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592B08 .go 3765.189 6646.188 152.2007

DELETE FROM `creature_formations` WHERE `leaderGUID`=122678;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122678, 122678, 0, 0, 2, 0, 0),
(122678, 122663, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122684;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3726.047,`position_y`=6604.721,`position_z`=171.6309 WHERE `guid` IN (@NPC, 122669);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3726.047,6604.721,171.6309,0,0,0,0,100,0),
(@PATH,2,3737.404,6582.727,172.9987,0,0,0,0,100,0),
(@PATH,3,3752.602,6559.511,175.07,0,0,0,0,100,0),
(@PATH,4,3757.825,6548.518,176.1503,0,0,0,0,100,0),
(@PATH,5,3741.299,6576.517,173.8608,0,0,0,0,100,0),
(@PATH,6,3731.644,6593.12,172.3642,0,0,0,0,100,0),
(@PATH,7,3725.372,6606.514,171.4347,0,0,0,0,100,0),
(@PATH,8,3726.047,6604.721,171.6309,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C0000592BE0 .go 3726.047 6604.721 171.6309

DELETE FROM `creature_formations` WHERE `leaderGUID`=122684;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122684, 122684, 0, 0, 2, 0, 0),
(122684, 122669, 4, 0, 2, 0, 0);

-- Coldarra Spellweaver SAI
SET @ENTRY := 25722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,600,5300,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellweaver - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellweaver - Out of Combat - Cast 'Arcane Channeling'");

-- Coldarra Spellbinder SAI
SET @ENTRY := 25719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3900,5800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,1700,13500,172100,172100,11,50583,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - In Combat - Cast 'Summon Frozen Spheres'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldarra Spellbinder - Out of Combat - Cast 'Arcane Channeling'");

-- Inquisitor Caleras SAI
SET @ENTRY := 25720;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,6200,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,9800,21300,18400,18400,11,32192,1,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Inquisitor Caleras - Out of Combat - Cast 'Arcane Channeling'");

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122676;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3839.049,`position_y`=6746.131,`position_z`=150.8772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3839.049,6746.131,150.8772,0,0,0,0,100,0),
(@PATH,2,3838.777,6746.075,150.6292,0,0,0,0,100,0),
(@PATH,3,3838.793,6746.344,150.9143,0,0,0,0,100,0),
(@PATH,4,3826.649,6753.63,150.9941,0,0,0,0,100,0),
(@PATH,5,3811.169,6750.051,150.4951,0,0,0,0,100,0),
(@PATH,6,3811.172,6750.112,150.299,0,0,0,0,100,0),
(@PATH,7,3811.489,6750.411,150.5408,0,0,0,0,100,0),
(@PATH,8,3826.923,6753.677,150.8951,0,0,0,0,100,0),
(@PATH,9,3839.046,6746.012,150.8834,0,0,0,0,100,0),
(@PATH,10,3838.777,6746.075,150.6292,0,0,0,0,100,0),
(@PATH,11,3838.828,6746.229,150.9149,0,0,0,0,100,0),
(@PATH,12,3826.723,6753.648,150.7468,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005924AC .go 3839.049 6746.131 150.8772

DELETE FROM `creature_formations` WHERE `leaderGUID`=122676;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122676, 122676, 0, 0, 2, 0, 0),
(122676, 122662, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122680;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3863.127,`position_y`=6753.518,`position_z`=150.5189 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3863.127,6753.518,150.5189,0,0,0,0,100,0),
(@PATH,2,3860.453,6741.29,150.7381,0,0,0,0,100,0),
(@PATH,3,3875.973,6736.009,151.0474,0,0,0,0,100,0),
(@PATH,4,3886.431,6727.403,151.3167,0,0,0,0,100,0),
(@PATH,5,3886.167,6727.198,151.1895,0,0,0,0,100,0),
(@PATH,6,3886.265,6727.485,151.3074,0,0,0,0,100,0),
(@PATH,7,3875.836,6736.28,151.0612,0,0,0,0,100,0),
(@PATH,8,3860.38,6741.66,150.7448,0,0,0,0,100,0),
(@PATH,9,3862.974,6753.514,150.6811,0,0,0,0,100,0),
(@PATH,10,3867.98,6753.716,150.6562,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005924B3 .go 3863.127 6753.518 150.5189

DELETE FROM `creature_formations` WHERE `leaderGUID`=122680;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122680, 122680, 0, 0, 2, 0, 0),
(122680, 122665, 4, 0, 2, 0, 0);

-- Pathing for  Entry: 25719 'TDB FORMAT' 
SET @NPC := 122685;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3908.275,`position_y`=6757.146,`position_z`=150.8441 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3908.275,6757.146,150.8441,0,0,0,0,100,0),
(@PATH,2,3893.045,6770.693,150.8547,0,0,0,0,100,0),
(@PATH,3,3880.528,6782.54,150.7091,0,0,0,0,100,0),
(@PATH,4,3880.478,6782.537,150.6073,0,0,0,0,100,0),
(@PATH,5,3880.76,6782.527,150.8653,0,0,0,0,100,0),
(@PATH,6,3893.34,6770.562,150.8441,0,0,0,0,100,0),
(@PATH,7,3908.603,6756.879,150.896,0,0,0,0,100,0),
(@PATH,8,3925.911,6721.284,153.766,0,0,0,0,100,0),
(@PATH,9,3920.531,6713.925,153.515,0,0,0,0,100,0),
(@PATH,10,3906.757,6706.551,151.9455,0,0,0,0,100,0),
(@PATH,11,3894.688,6701.577,151.5052,0,0,0,0,100,0),
(@PATH,12,3894.756,6701.676,151.4043,0,0,0,0,100,0),
(@PATH,13,3916.371,6709.826,152.6267,0,0,0,0,100,0),
(@PATH,14,3921.297,6714.496,153.5745,0,0,0,0,100,0),
(@PATH,15,3929.399,6745.379,151.6542,0,0,0,0,100,0),
(@PATH,16,3919.581,6752.038,150.9705,0,0,0,0,100,0),
(@PATH,17,3908.269,6757.149,150.8441,0,0,0,0,100,0),
(@PATH,18,3893.047,6770.691,150.8547,0,0,0,0,100,0),
(@PATH,19,3880.51,6782.556,150.7091,0,0,0,0,100,0);
-- 0x1C09144760191DC000000C00005932EB .go 3908.275 6757.146 150.8441

DELETE FROM `creature_formations` WHERE `leaderGUID`=122685;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(122685, 122685, 0, 0, 2, 0, 0),
(122685, 122670, 4, 0, 2, 0, 0);

UPDATE `creature` SET `spawndist`=20 WHERE  `guid`=122550;

UPDATE `creature` SET `spawndist`=15 WHERE `id`=25721;

-- Pathing for  Entry: 25717 'TDB FORMAT' 
SET @NPC := 122652;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4071.958,`position_y`=7059.748,`position_z`=166.7365 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4071.958,7059.748,166.7365,0,0,0,0,100,0),
(@PATH,2,4072.932,7060.661,166.5419,0,0,0,0,100,0),
(@PATH,3,4087.155,7066.582,166.7904,0,0,0,0,100,0),
(@PATH,4,4086.809,7066.466,166.6568,0,0,0,0,100,0),
(@PATH,5,4086.776,7066.416,166.7174,0,0,0,0,100,0),
(@PATH,6,4062.645,7049.889,167.7236,0,0,0,0,100,0),
(@PATH,7,4054.082,7027.509,166.672,0,0,0,0,100,0),
(@PATH,8,4059.144,7041.778,167.9961,0,0,0,0,100,0),
(@PATH,9,4071.981,7059.813,166.7345,0,0,0,0,100,0);
-- 0x1C09144760191D4000000C00005932C9 .go 4071.958 7059.748 166.7365

-- General Cerulean SAI
SET @ENTRY := 25716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10200,13600,10000,12000,11,15499,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Cerulean - In Combat - Cast 'Frost Shock'"),
(@ENTRY,0,1,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Cerulean - Out of Combat - Cast 'Arcane Channeling'");

UPDATE `creature` SET `spawndist`=20 WHERE  `guid` IN (122547, 122551);

-- Pathing for  Entry: 25713 'TDB FORMAT' 
SET @NPC := 122611;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3820.672,`position_y`=7153.959,`position_z`=163.4258 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3820.672,7153.959,163.4258,0,0,0,0,100,0),
(@PATH,2,3816.873,7173.65,161.3409,0,0,0,0,100,0),
(@PATH,3,3819.527,7160.829,162.4046,0,0,0,0,100,0),
(@PATH,4,3821.152,7145.412,164.2622,0,0,0,0,100,0),
(@PATH,5,3820.075,7133.457,165.5549,0,0,0,0,100,0),
(@PATH,6,3819.108,7129.334,166.0357,0,0,0,0,100,0),
(@PATH,7,3819.164,7129.457,165.8505,0,0,0,0,100,0),
(@PATH,8,3820.722,7140.354,165.1108,0,0,0,0,100,0),
(@PATH,9,3820.762,7154.072,163.3669,0,0,0,0,100,0),
(@PATH,10,3816.832,7173.758,161.5131,0,0,0,0,100,0);
-- 0x1C09144760191C4000000C0000590957 .go 3820.672 7153.959 163.4258

-- Pathing for  Entry: 25713 'TDB FORMAT' 
SET @NPC := 122643;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3715.234,`position_y`=7159.224,`position_z`=160.5815 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3715.234,7159.224,160.5815,0,0,0,0,100,0),
(@PATH,2,3712.465,7168.071,160.3927,0,0,0,0,100,0),
(@PATH,3,3711.697,7180.112,160.1553,0,0,0,0,100,0),
(@PATH,4,3712.53,7195.874,160.5102,0,0,0,0,100,0),
(@PATH,5,3712.202,7195.61,160.2491,0,0,0,0,100,0),
(@PATH,6,3712.354,7195.505,160.5099,0,0,0,0,100,0),
(@PATH,7,3711.637,7179.952,160.1052,0,0,0,0,100,0),
(@PATH,8,3712.478,7167.976,160.2884,0,0,0,0,100,0),
(@PATH,9,3715.501,7158.848,160.5296,0,0,0,0,100,0),
(@PATH,10,3715.303,7158.94,160.4226,0,0,0,0,100,0),
(@PATH,11,3715.255,7159.067,160.5904,0,0,0,0,100,0),
(@PATH,12,3712.359,7168.119,160.3639,0,0,0,0,100,0),
(@PATH,13,3711.62,7180.215,160.1398,0,0,0,0,100,0),
(@PATH,14,3712.332,7195.925,160.5264,0,0,0,0,100,0);
-- 0x1C09144760191C4000000C0000592DB7 .go 3715.234 7159.224 160.5815

-- Warbringer Goredrak SAI
SET @ENTRY := 25712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,200,16900,21200,11,50534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 'Power Sap'"),
(@ENTRY,0,1,0,0,0,100,0,5900,6700,16800,21200,11,50545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warbringer Goredrak - In Combat - Cast 'Arcane Blast'"),
(@ENTRY,0,2,0,1,0,100,0,100,100,45000,45000,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warbringer Goredrak - Out of Combat - Cast 'Arcane Channeling'");

UPDATE `creature` SET `spawndist`=10 WHERE  `guid`=122806;
UPDATE `creature` SET `spawndist`=15 WHERE  `guid` IN (122824, 122545);
-- Pathing for  Entry: 25709 'TDB FORMAT' 
SET @NPC := 122562;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3821.72,`position_y`=7226.874,`position_z`=165.7941 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3821.72,7226.874,165.7941,0,0,0,0,100,0),
(@PATH,2,3840.45,7225.532,167.5351,0,0,0,0,100,0),
(@PATH,3,3854.693,7219.692,168.801,0,0,0,0,100,0),
(@PATH,4,3872.789,7201.074,168.0432,0,0,0,0,100,0),
(@PATH,5,3877.849,7192.911,167.4686,0,0,0,0,100,0),
(@PATH,6,3853.227,7162.686,166.2984,0,0,0,0,100,0),
(@PATH,7,3831.403,7190.82,162.3192,0,0,0,0,100,0),
(@PATH,8,3821.685,7226.815,165.7664,0,0,0,0,100,0);
-- 0x1C09144760191B4000000C00005929B2 .go 3821.72 7226.874 165.7941

-- Pathing for  Entry: 25717 'TDB FORMAT' 
SET @NPC := 122655;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4158.797,`position_y`=7025.598,`position_z`=165.7506 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4158.797,7025.598,165.7506,0,0,0,0,100,0),
(@PATH,2,4158.771,7025.846,166.0288,0,0,0,0,100,0),
(@PATH,3,4149.362,7040.18,166.0216,0,0,0,0,100,0),
(@PATH,4,4141.375,7046.86,165.9186,0,0,0,0,100,0),
(@PATH,5,4128.7,7050.973,165.6986,0,0,0,0,100,0),
(@PATH,6,4128.795,7050.833,165.5718,0,0,0,0,100,0),
(@PATH,7,4129.043,7050.743,165.6772,0,0,0,0,100,0),
(@PATH,8,4141.438,7046.565,166.0175,0,0,0,0,100,0),
(@PATH,9,4149.486,7040.006,166.0294,0,0,0,0,100,0),
(@PATH,10,4159.022,7025.654,165.9743,0,0,0,0,100,0);
-- 0x1C09144760191D4000000C000059272B .go 4158.797 7025.598 165.7506
