-- Onslaught Warhorse SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (27213,27206);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27213,27206);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27213,0,0,0,11,0,100,0,0,0,0,0,12,27206,8,0,0,0,0,1,0,0,0,0,0,0,0,'Onslaught Warhorse - On Spawn - Summon Onslaught Knight'),
(27206,0,0,0,1,0,100,1,500,500,500,500,11,43671,3,0,0,0,0,19,27213,0,0,0,0,0,0,'Onslaught Knight - OOC once - Cast Ride Vehicle on Onslaught Warhorse');

-- Remove spawned Onslaught Knights
DELETE FROM `creature_addon` WHERE `guid` IN (Select `guid` FROM `creature` WHERE `id`=27206);
DELETE FROM `creature` WHERE `id`=27206;

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102716;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2508.58,`position_y`=-290.6462,`position_z`=-0.1427202 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2519.424,-279.186,-0.7677202,0,0,0,100,0),
(@PATH,2,2530.539,-279.0238,-0.7677202,0,0,0,100,0),
(@PATH,3,2539.442,-270.758,-0.3258755,0,0,0,100,0),
(@PATH,4,2540.027,-251.3916,-0.06487894,0,0,0,100,0),
(@PATH,5,2539.442,-270.758,-0.3258755,0,0,0,100,0),
(@PATH,6,2530.539,-279.0238,-0.7677202,0,0,0,100,0),
(@PATH,7,2519.424,-279.186,-0.7677202,0,0,0,100,0),
(@PATH,8,2508.58,-290.6462,-0.1427202,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102717;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2587.305,`position_y`=-291.1189,`position_z`=3.032966 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2601.257,-273.5315,1.532966,0,0,0,100,0),
(@PATH,2,2618.792,-253.0176,2.282767,0,0,0,100,0),
(@PATH,3,2633.199,-245.2131,4.532767,0,0,0,100,0),
(@PATH,4,2618.873,-252.9083,2.282767,0,0,0,100,0),
(@PATH,5,2601.339,-273.4219,1.532966,0,0,0,100,0),
(@PATH,6,2587.305,-291.1189,3.032966,0,0,0,100,0),
(@PATH,7,2575.844,-304.2566,3.642326,0,0,0,100,0),
(@PATH,8,2570.643,-318.0563,3.767326,0,0,0,100,0),
(@PATH,9,2571.61,-332.3442,3.767326,0,0,0,100,0),
(@PATH,10,2570.399,-357.3963,3.884323,0,0,0,100,0),
(@PATH,11,2571.61,-332.3442,3.767326,0,0,0,100,0),
(@PATH,12,2570.643,-318.0563,3.767326,0,0,0,100,0),
(@PATH,13,2575.844,-304.2566,3.642326,0,0,0,100,0),
(@PATH,14,2587.305,-291.1189,3.032966,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102719;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2538.552,`position_y`=-475.1394,`position_z`=0.6403183 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2515.825,-450.3543,0.282984,0,0,0,100,0),
(@PATH,2,2538.552,-475.1394,0.6403183,0,0,0,100,0),
(@PATH,3,2562.629,-487.9083,0.7653183,0,0,0,100,0),
(@PATH,4,2569.465,-510.7032,0.8169425,0,0,0,100,0),
(@PATH,5,2575.739,-523.7434,1.191942,0,0,0,100,0),
(@PATH,6,2601.065,-534.6965,0.9285774,0,0,0,100,0),
(@PATH,7,2575.739,-523.7434,1.191942,0,0,0,100,0),
(@PATH,8,2569.465,-510.7032,0.8169425,0,0,0,100,0),
(@PATH,9,2562.629,-487.9083,0.7653183,0,0,0,100,0),
(@PATH,10,2538.552,-475.1394,0.6403183,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102721;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2582.436,`position_y`=-222.4737,`position_z`=-0.4052925 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2579.515,-214.4551,-0.5302925,0,0,0,100,0),
(@PATH,2,2580.979,-202.8364,0.3447075,0,0,0,100,0),
(@PATH,3,2579.515,-214.4551,-0.5302925,0,0,0,100,0),
(@PATH,4,2582.436,-222.4737,-0.4052925,0,0,0,100,0),
(@PATH,5,2561.902,-230.8203,-0.3034239,0,0,0,100,0),
(@PATH,6,2582.436,-222.4737,-0.4052925,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2838.992,`position_y`=-178.4683,`position_z`=137.0378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2837.595,-191.9704,137.9128,0,0,0,100,0),
(@PATH,2,2842.86,-215.9774,136.6075,0,0,0,100,0),
(@PATH,3,2837.595,-191.9704,137.9128,0,0,0,100,0),
(@PATH,4,2838.992,-178.4683,137.0378,0,0,0,100,0),
(@PATH,5,2836.44,-170.251,138.1628,0,0,0,100,0),
(@PATH,6,2829.992,-167.1136,138.761,0,0,0,100,0),
(@PATH,7,2820.281,-166.5459,138.6697,0,0,0,100,0),
(@PATH,8,2829.992,-167.1136,138.761,0,0,0,100,0),
(@PATH,9,2836.44,-170.251,138.1628,0,0,0,100,0),
(@PATH,10,2838.992,-178.4683,137.0378,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102724;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2712.161,`position_y`=-564.5253,`position_z`=9.693825 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2693.882,-580.2343,7.060011,0,0,0,100,0),
(@PATH,2,2672.807,-596.9056,9.185011,0,0,0,100,0),
(@PATH,3,2662.762,-603.8812,9.776094,0,0,0,100,0),
(@PATH,4,2648.289,-604.2076,10.40109,0,0,0,100,0),
(@PATH,5,2662.762,-603.8812,9.776094,0,0,0,100,0),
(@PATH,6,2672.807,-596.9056,9.185011,0,0,0,100,0),
(@PATH,7,2693.882,-580.2343,7.060011,0,0,0,100,0),
(@PATH,8,2712.161,-564.5253,9.693825,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102725;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2688.144,`position_y`=-181.5894,`position_z`=138.8123 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2690.253,-211.2009,138.7873,0,0,0,100,0),
(@PATH,2,2711.088,-233.0926,141.4496,0,0,0,100,0),
(@PATH,3,2691.518,-247.295,142.4064,0,0,0,100,0),
(@PATH,4,2690.253,-211.2009,138.7873,0,0,0,100,0),
(@PATH,5,2688.144,-181.5894,138.8123,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102726;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2832.563,`position_y`=-258.2318,`position_z`=133.0783 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2823.757,-269.6722,132.6919,0,0,0,100,0),
(@PATH,2,2810.606,-274.9349,132.6919,0,0,0,100,0),
(@PATH,3,2798.263,-267.8378,132.7004,0,0,0,100,0),
(@PATH,4,2795.204,-255.2375,132.6619,0,0,0,100,0),
(@PATH,5,2815.456,-249.9233,133.0783,0,0,0,100,0),
(@PATH,6,2841.983,-244.2453,135.4677,0,0,0,100,0),
(@PATH,7,2815.456,-249.9233,133.0783,0,0,0,100,0),
(@PATH,8,2795.204,-255.2375,132.6619,0,0,0,100,0),
(@PATH,9,2798.263,-267.8378,132.7004,0,0,0,100,0),
(@PATH,10,2810.606,-274.9349,132.6919,0,0,0,100,0),
(@PATH,11,2823.757,-269.6722,132.6919,0,0,0,100,0),
(@PATH,12,2832.563,-258.2318,133.0783,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102727;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2655.115,`position_y`=-139.6238,`position_z`=73.46788 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2656.776,-155.0757,66.71788,0,0,0,100,0),
(@PATH,2,2655.572,-172.0843,62.16366,0,0,0,100,0),
(@PATH,3,2650.678,-180.1066,63.41366,0,0,0,100,0),
(@PATH,4,2656.032,-164.1928,64.71788,0,0,0,100,0),
(@PATH,5,2656.646,-150.7192,68.46788,0,0,0,100,0),
(@PATH,6,2654.885,-130.6351,77.12984,0,0,0,100,0),
(@PATH,7,2659.214,-115.5115,82.62984,0,0,0,100,0),
(@PATH,8,2659.958,-93.19423,87.00713,0,0,0,100,0),
(@PATH,9,2666.549,-83.81207,89.50713,0,0,0,100,0),
(@PATH,10,2681.103,-87.36887,92.43093,0,0,0,100,0),
(@PATH,11,2700.115,-95.54926,101.8188,0,0,0,100,0),
(@PATH,12,2718.652,-104.436,110.9657,0,0,0,100,0),
(@PATH,13,2731.385,-117.8694,116.5907,0,0,0,100,0),
(@PATH,14,2726.709,-128.2827,120.8407,0,0,0,100,0),
(@PATH,15,2714.232,-134.095,125.4612,0,0,0,100,0),
(@PATH,16,2684.606,-134.3662,125.9815,0,0,0,100,0),
(@PATH,17,2705.027,-135.4983,127.8362,0,0,0,100,0),
(@PATH,18,2719.343,-131.1707,122.8407,0,0,0,100,0),
(@PATH,19,2731.655,-119.8017,117.2157,0,0,0,100,0),
(@PATH,20,2725.038,-106.6583,113.3407,0,0,0,100,0),
(@PATH,21,2703.98,-99.18321,103.9438,0,0,0,100,0),
(@PATH,22,2680.189,-88.67188,92.05593,0,0,0,100,0),
(@PATH,23,2665.09,-83.62039,89.38213,0,0,0,100,0),
(@PATH,24,2660.516,-94.05186,87.00713,0,0,0,100,0),
(@PATH,25,2659.939,-112.8213,83.37984,0,0,0,100,0),
(@PATH,26,2658.327,-126.0295,79.12984,0,0,0,100,0),
(@PATH,27,2655.115,-139.6238,73.46788,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102728;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2809.652,`position_y`=-404.1015,`position_z`=118.2837 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2820.063,-404.6535,118.2837,0,0,0,100,0),
(@PATH,2,2808.515,-405.1523,118.2837,0,0,0,100,0),
(@PATH,3,2793.463,-420.3747,118.3209,0,0,0,100,0),
(@PATH,4,2779.776,-437.7538,118.6404,0,0,0,100,0),
(@PATH,5,2775.378,-463.4759,116.1404,0,0,0,100,0),
(@PATH,6,2767.986,-472.3566,116.8041,0,0,0,100,0),
(@PATH,7,2755.093,-477.2342,121.6782,0,0,0,100,0),
(@PATH,8,2773.319,-467.1881,116.1791,0,0,0,100,0),
(@PATH,9,2778.031,-447.918,118.3904,0,0,0,100,0),
(@PATH,10,2785.59,-429.4701,118.3209,0,0,0,100,0),
(@PATH,11,2800.177,-413.79,118.2837,0,0,0,100,0),
(@PATH,12,2809.652,-404.1015,118.2837,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102729;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2750.5,`position_y`=-154.7686,`position_z`=139.4088 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2741.167,-164.7871,139.1588,0,0,0,100,0),
(@PATH,2,2750.5,-154.7686,139.4088,0,0,0,100,0),
(@PATH,3,2759.093,-161.0407,138.9088,0,0,0,100,0),
(@PATH,4,2771.567,-152.4166,139.9017,0,0,0,100,0),
(@PATH,5,2781.019,-154.3085,140.5267,0,0,0,100,0),
(@PATH,6,2791.13,-161.2096,139.1517,0,0,0,100,0),
(@PATH,7,2802.436,-164.2816,137.4197,0,0,0,100,0),
(@PATH,8,2791.13,-161.2096,139.1517,0,0,0,100,0),
(@PATH,9,2781.019,-154.3085,140.5267,0,0,0,100,0),
(@PATH,10,2771.567,-152.4166,139.9017,0,0,0,100,0),
(@PATH,11,2759.093,-161.0407,138.9088,0,0,0,100,0),
(@PATH,12,2750.5,-154.7686,139.4088,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102730;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2712.018,`position_y`=-465.3528,`position_z`=85.87247 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2722.812,-487.2094,91.62904,0,0,0,100,0),
(@PATH,2,2726.125,-504.7564,94.96687,0,0,0,100,0),
(@PATH,3,2720.495,-521.4435,91.71687,0,0,0,100,0),
(@PATH,4,2727.937,-503.8876,95.59187,0,0,0,100,0),
(@PATH,5,2725.637,-491.6325,93.62904,0,0,0,100,0),
(@PATH,6,2715.711,-476.3229,88.62904,0,0,0,100,0),
(@PATH,7,2704.701,-454.9398,81.12247,0,0,0,100,0),
(@PATH,8,2692.514,-431.9863,72.42125,0,0,0,100,0),
(@PATH,9,2672.562,-431.7496,64.54625,0,0,0,100,0),
(@PATH,10,2649.395,-432.2932,52.79884,0,0,0,100,0),
(@PATH,11,2643.88,-442.8751,50.55303,0,0,0,100,0),
(@PATH,12,2652.563,-431.4375,54.42384,0,0,0,100,0),
(@PATH,13,2682.649,-431.7939,69.17125,0,0,0,100,0),
(@PATH,14,2693.424,-434.0273,73.17553,0,0,0,100,0),
(@PATH,15,2703.067,-449.0695,79.62247,0,0,0,100,0),
(@PATH,16,2712.018,-465.3528,85.87247,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102731;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2534.057,`position_y`=-419.9908,`position_z`=3.277672 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2543.743,-400.441,2.027672,0,0,0,100,0),
(@PATH,2,2555.679,-395.5271,2.825949,0,0,0,100,0),
(@PATH,3,2543.743,-400.441,2.027672,0,0,0,100,0),
(@PATH,4,2534.057,-419.9908,3.277672,0,0,0,100,0),
(@PATH,5,2532.219,-440.2344,3.032984,0,0,0,100,0),
(@PATH,6,2532.378,-470.4768,0.8200397,0,0,0,100,0),
(@PATH,7,2548.762,-479.3864,0.5153183,0,0,0,100,0),
(@PATH,8,2532.378,-470.4768,0.8200397,0,0,0,100,0),
(@PATH,9,2532.219,-440.2344,3.032984,0,0,0,100,0),
(@PATH,10,2534.057,-419.9908,3.277672,0,0,0,100,0);

-- Pathing for Onslaught Warhorse Entry: 27213
SET @NPC := 102734;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2684.26,`position_y`=-287.8797,`position_z`=127.2792 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2728.101,-295.6697,132.1564,0,0,0,100,0),
(@PATH,2,2698.353,-312.0914,133.1807,0,0,0,100,0),
(@PATH,3,2689.288,-321.3154,132.3057,0,0,0,100,0),
(@PATH,4,2675.345,-320.4376,131.9307,0,0,0,100,0),
(@PATH,5,2654.261,-324.0862,132.1816,0,0,0,100,0),
(@PATH,6,2675.345,-320.4376,131.9307,0,0,0,100,0),
(@PATH,7,2689.288,-321.3154,132.3057,0,0,0,100,0),
(@PATH,8,2698.353,-312.0914,133.1807,0,0,0,100,0),
(@PATH,9,2728.101,-295.6697,132.1564,0,0,0,100,0),
(@PATH,10,2684.26,-287.8797,127.2792,0,0,0,100,0);
