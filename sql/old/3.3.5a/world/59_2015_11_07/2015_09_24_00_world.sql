-- Pathing for Death Knight Captain Entry: 16145 'TDB FORMAT' 
SET @NPC := 127640;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2556.952,`position_y`=-3294.904,`position_z`=267.5933 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2556.952,`position_y`=-3294.904,`position_z`=267.5933 WHERE `guid` IN (127685,127686,127656,127657);
DELETE FROM `creature_addon` WHERE `guid` IN (127685,127686,127656,127657);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(127685,@PATH,0,0,1,0, ''), (127686,@PATH,0,0,1,0, ''), (127656,@PATH,0,0,1,0, ''), (127657,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2556.952,-3294.904,267.5933,0,0,0,0,100,0),
(@PATH,2,2556.655,-3273.629,266.7731,0,0,0,0,100,0),
(@PATH,3,2556.505,-3258.446,260.2637,0,0,0,0,100,0),
(@PATH,4,2556.29,-3229.774,245.2207,0,0,0,0,100,0),
(@PATH,5,2555.99,-3205.854,240.5267,0,0,0,0,100,0),
(@PATH,6,2555.881,-3183.735,240.5253,0,0,0,0,100,0),
(@PATH,7,2556.055,-3164.447,240.5253,0,0,0,0,100,0),
(@PATH,8,2556.121,-3141.804,240.5253,0,0,0,0,100,0),
(@PATH,9,2556.055,-3164.447,240.5253,0,0,0,0,100,0),
(@PATH,10,2555.881,-3183.735,240.5253,0,0,0,0,100,0),
(@PATH,11,2555.99,-3205.854,240.5267,0,0,0,0,100,0),
(@PATH,12,2556.29,-3229.774,245.2207,0,0,0,0,100,0),
(@PATH,13,2556.505,-3258.446,260.2637,0,0,0,0,100,0),
(@PATH,14,2556.655,-3273.629,266.7731,0,0,0,0,100,0),
(@PATH,15,2556.952,-3294.904,267.5933,0,0,0,0,100,0),
(@PATH,16,2556.716,-3318.195,267.593,0,0,0,0,100,0),
(@PATH,17,2556.767,-3335.356,267.593,0,0,0,0,100,0),
(@PATH,18,2556.716,-3318.195,267.593,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127640);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127640,127640,0,0,2,0,0),
(127640,127685,3,360,2,8,17),
(127640,127686,3,40,2,8,17),
(127640,127656,3,320,2,8,17),
(127640,127657,3,260,2,8,17);

-- Pathing for Death Knight Captain Entry: 16145 'TDB FORMAT' 
SET @NPC := 127641;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2540.547,`position_y`=-3209.821,`position_z`=240.5256 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2540.547,`position_y`=-3209.821,`position_z`=240.5256 WHERE `guid` IN (127687,127688,127658,127659);
DELETE FROM `creature_addon` WHERE `guid` IN (127687,127688,127658,127659);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(127687,@PATH,0,0,1,0, ''), (127688,@PATH,0,0,1,0, ''), (127658,@PATH,0,0,1,0, ''), (127659,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2540.547,-3209.821,240.5256,0,0,0,0,100,0),
(@PATH,2,2550.174,-3195.296,240.5253,0,0,0,0,100,0),
(@PATH,3,2550.015,-3178.325,240.5252,0,0,0,0,100,0),
(@PATH,4,2542.807,-3161.292,240.5246,0,0,0,0,100,0),
(@PATH,5,2531.76,-3145.814,240.5244,0,0,0,0,100,0),
(@PATH,6,2526.761,-3124.435,240.5252,0,0,0,0,100,0),
(@PATH,7,2535.071,-3107.707,240.5244,0,0,0,0,100,0),
(@PATH,8,2553.146,-3099.002,240.5252,0,0,0,0,100,0),
(@PATH,9,2568.556,-3098.702,240.5253,0,0,0,0,100,0),
(@PATH,10,2586.523,-3091.121,240.5253,0,0,0,0,100,0),
(@PATH,11,2599.675,-3076.474,240.5264,0,0,0,0,100,0),
(@PATH,12,2599.267,-3055.494,240.5239,0,0,0,0,100,0),
(@PATH,13,2618.495,-3035.821,240.5235,0,0,0,0,100,0),
(@PATH,14,2634.81,-3052.702,240.5237,0,0,0,0,100,0),
(@PATH,15,2651.288,-3069.151,240.5216,0,0,0,0,100,0),
(@PATH,16,2628.244,-3086.696,240.5232,0,0,0,0,100,0),
(@PATH,17,2608.684,-3085.287,240.5264,0,0,0,0,100,0),
(@PATH,18,2595.005,-3098.484,240.5253,0,0,0,0,100,0),
(@PATH,19,2587.623,-3116.573,240.5246,0,0,0,0,100,0),
(@PATH,20,2586.39,-3131.935,240.525,0,0,0,0,100,0),
(@PATH,21,2577.873,-3150.335,240.524,0,0,0,0,100,0),
(@PATH,22,2565.028,-3163.529,240.5253,0,0,0,0,100,0),
(@PATH,23,2559.751,-3177.576,240.5253,0,0,0,0,100,0),
(@PATH,24,2559.432,-3195.028,240.5254,0,0,0,0,100,0),
(@PATH,25,2570.551,-3210.158,240.5293,0,0,0,0,100,0),
(@PATH,26,2555.933,-3210.18,240.5274,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127641);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127641,127641,0,0,2,0,0),
(127641,127687,3,360,2,0,0),
(127641,127688,3,40,2,0,0),
(127641,127658,3,320,2,0,0),
(127641,127659,3,260,2,0,0);

-- Pathing for Death Knight Captain Entry: 16145 'TDB FORMAT' 
SET @NPC := 127642;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2781.675,`position_y`=-2973.126,`position_z`=240.5271 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2781.675,`position_y`=-2973.126,`position_z`=240.5271 WHERE `guid` IN (127689,127690,127660,127661);
DELETE FROM `creature_addon` WHERE `guid` IN (127689,127690,127660,127661);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(127689,@PATH,0,0,1,0, ''), (127690,@PATH,0,0,1,0, ''), (127660,@PATH,0,0,1,0, ''), (127661,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2781.675,-2973.126,240.5271,0,0,0,0,100,0),
(@PATH,2,2781.545,-2987.27,240.5265,0,0,0,0,100,0),
(@PATH,3,2781.296,-2999.196,240.5251,0,0,0,0,100,0),
(@PATH,4,2761.818,-2991.876,240.525,0,0,0,0,100,0),
(@PATH,5,2741.577,-2996.512,240.5255,0,0,0,0,100,0),
(@PATH,6,2720.587,-3007.503,240.5255,0,0,0,0,100,0),
(@PATH,7,2702.402,-3013.772,240.5244,0,0,0,0,100,0),
(@PATH,8,2678.602,-3021.83,240.5253,0,0,0,0,100,0),
(@PATH,9,2662.359,-3033.787,240.5253,0,0,0,0,100,0),
(@PATH,10,2656.579,-3044.628,240.5232,0,0,0,0,100,0),
(@PATH,11,2654.518,-3070.607,240.5216,0,0,0,0,100,0),
(@PATH,12,2642.806,-3082.523,240.5241,0,0,0,0,100,0),
(@PATH,13,2625.915,-3067.382,240.5231,0,0,0,0,100,0),
(@PATH,14,2613.159,-3055.652,240.5243,0,0,0,0,100,0),
(@PATH,15,2603.647,-3046.96,240.5242,0,0,0,0,100,0),
(@PATH,16,2613.084,-3036.567,240.5217,0,0,0,0,100,0),
(@PATH,17,2640.296,-3028.944,240.525,0,0,0,0,100,0),
(@PATH,18,2652.006,-3024.45,240.5253,0,0,0,0,100,0),
(@PATH,19,2664.795,-3009.59,240.5253,0,0,0,0,100,0),
(@PATH,20,2670.619,-2990.552,240.5244,0,0,0,0,100,0),
(@PATH,21,2679.347,-2964.029,240.5253,0,0,0,0,100,0),
(@PATH,22,2697.98,-2955.501,240.5241,0,0,0,0,100,0),
(@PATH,23,2719.132,-2962.616,240.5251,0,0,0,0,100,0),
(@PATH,24,2741.907,-2976.874,240.5253,0,0,0,0,100,0),
(@PATH,25,2760.453,-2981.653,240.5253,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127642);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127642,127642,0,0,2,0,0),
(127642,127689,3,360,2,0,0),
(127642,127690,3,40,2,0,0),
(127642,127660,3,320,2,0,0),
(127642,127661,3,260,2,0,0);

-- Pathing for Death Knight Captain Entry: 16145 'TDB FORMAT' 
SET @NPC := 127645;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2584.613,`position_y`=-3100.685,`position_z`=240.5253 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2584.613,`position_y`=-3100.685,`position_z`=240.5253 WHERE `guid` IN (127691,127692,127664,127665);
DELETE FROM `creature_addon` WHERE `guid` IN (127691,127692,127664,127665);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(127691,@PATH,0,0,1,0, ''), (127692,@PATH,0,0,1,0, ''), (127664,@PATH,0,0,1,0, ''), (127665,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2584.613,-3100.685,240.5253,0,0,0,0,100,0),
(@PATH,2,2601.56,-3083.452,240.5258,0,0,0,0,100,0),
(@PATH,3,2629.143,-3055.421,240.5237,0,0,0,0,100,0),
(@PATH,4,2650.178,-3034.592,240.526,0,0,0,0,100,0),
(@PATH,5,2667.962,-3017.14,240.5253,0,0,0,0,100,0),
(@PATH,6,2680.883,-3004.51,240.5252,0,0,0,0,100,0),
(@PATH,7,2699.352,-2986.865,240.5253,0,0,0,0,100,0),
(@PATH,8,2680.883,-3004.51,240.5252,0,0,0,0,100,0),
(@PATH,9,2667.962,-3017.14,240.5253,0,0,0,0,100,0),
(@PATH,10,2650.178,-3034.592,240.526,0,0,0,0,100,0),
(@PATH,11,2629.143,-3055.421,240.5237,0,0,0,0,100,0),
(@PATH,12,2601.56,-3083.452,240.5258,0,0,0,0,100,0),
(@PATH,13,2584.613,-3100.685,240.5253,0,0,0,0,100,0),
(@PATH,14,2570.169,-3114.794,240.5253,0,0,0,0,100,0),
(@PATH,15,2556.747,-3128.429,240.5253,0,0,0,0,100,0),
(@PATH,16,2570.169,-3114.794,240.5253,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127645);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127645,127645,0,0,2,0,0),
(127645,127691,3,360,2,7,15),
(127645,127692,3,40,2,7,15),
(127645,127664,3,320,2,7,15),
(127645,127665,3,260,2,7,15);

-- Pathing for Death Knight Captain Entry: 16145 'TDB FORMAT' 
SET @NPC := 127649;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2871.322,`position_y`=-2985.748,`position_z`=267.593 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2871.322,`position_y`=-2985.748,`position_z`=267.593 WHERE `guid` IN (127701,127702,127670,127671);
DELETE FROM `creature_addon` WHERE `guid` IN (127701,127702,127670,127671);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(127701,@PATH,0,0,1,0, ''), (127702,@PATH,0,0,1,0, ''), (127670,@PATH,0,0,1,0, ''), (127671,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2871.322,-2985.748,267.593,0,0,0,0,100,0),
(@PATH,2,2852.31,-2985.821,267.593,0,0,0,0,100,0),
(@PATH,3,2838.662,-2985.802,264.0277,0,0,0,0,100,0),
(@PATH,4,2807.427,-2985.919,248.8516,0,0,0,0,100,0),
(@PATH,5,2784.644,-2986.206,240.5265,0,0,0,0,100,0),
(@PATH,6,2760.957,-2986.261,240.5249,0,0,0,0,100,0),
(@PATH,7,2735.987,-2986.227,240.5253,0,0,0,0,100,0),
(@PATH,8,2716.594,-2986.268,240.5253,0,0,0,0,100,0),
(@PATH,9,2700.477,-2986.242,240.525,0,0,0,0,100,0),
(@PATH,10,2716.594,-2986.268,240.5253,0,0,0,0,100,0),
(@PATH,11,2735.987,-2986.227,240.5253,0,0,0,0,100,0),
(@PATH,12,2760.708,-2986.261,240.5253,0,0,0,0,100,0),
(@PATH,13,2784.644,-2986.206,240.5265,0,0,0,0,100,0),
(@PATH,14,2807.427,-2985.919,248.8516,0,0,0,0,100,0),
(@PATH,15,2838.662,-2985.802,264.0277,0,0,0,0,100,0),
(@PATH,16,2852.31,-2985.821,267.593,0,0,0,0,100,0),
(@PATH,17,2871.322,-2985.748,267.593,0,0,0,0,100,0),
(@PATH,18,2893.314,-2985.45,267.593,0,0,0,0,100,0),
(@PATH,19,2908.467,-2985.152,267.5937,0,0,0,0,100,0),
(@PATH,20,2893.314,-2985.45,267.593,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127649);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(127649,127649,0,0,2,0,0),
(127649,127701,3,360,2,9,19),
(127649,127702,3,40,2,9,19),
(127649,127670,3,320,2,9,19),
(127649,127671,3,260,2,9,19);
