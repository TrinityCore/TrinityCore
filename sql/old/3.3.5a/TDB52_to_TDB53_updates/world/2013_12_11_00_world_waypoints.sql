-- Pathing for Ruuan'ok Cloudgazer Entry: 19985
SET @NPC := 71284;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3199.351,`position_y`=5308.484,`position_z`=176.2681 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3199.351,5308.484,176.2681,0,0,0,0,100,0),
(@PATH,2,3205.716,5312.342,176.2666,0,0,0,0,100,0),
(@PATH,3,3219.292,5309.295,176.2736,0,0,0,0,100,0),
(@PATH,4,3205.716,5312.342,176.2666,0,0,0,0,100,0),
(@PATH,5,3199.351,5308.484,176.2681,0,0,0,0,100,0),
(@PATH,6,3195.501,5294.078,176.2996,0,0,0,0,100,0);

-- Pathing for Ruuan'ok Cloudgazer Entry: 19985
SET @NPC := 71286;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3223.498,`position_y`=5303.222,`position_z`=176.1865 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3223.498,5303.222,176.1865,0,0,0,0,100,0),
(@PATH,2,3224.697,5292.734,176.1594,0,0,0,0,100,0),
(@PATH,3,3217.344,5285.994,176.2444,0,0,0,0,100,0),
(@PATH,4,3224.697,5292.734,176.1594,0,0,0,0,100,0);

-- Pathing for Ruuan'ok Cloudgazer Entry: 19985
SET @NPC := 71288;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3267.165,`position_y`=5372.429,`position_z`=176.2717 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3267.165,5372.429,176.2717,0,0,0,0,100,0),
(@PATH,2,3279.156,5360.639,176.2681,0,0,0,0,100,0),
(@PATH,3,3267.165,5372.429,176.2717,0,0,0,0,100,0),
(@PATH,4,3253.538,5367.658,176.0594,0,0,0,0,100,0);

-- Pathing for Ruuan'ok Cloudgazer Entry: 19985
SET @NPC := 71289;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3251.729,`position_y`=5350.106,`position_z`=175.65 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3251.729,5350.106,175.65,0,0,0,0,100,0),
(@PATH,2,3264.023,5342.778,176.1073,0,0,0,0,100,0),
(@PATH,3,3275.7,5348.174,176.2674,0,0,0,0,100,0),
(@PATH,4,3264.214,5342.665,176.091,0,0,0,0,100,0);

-- Pathing for Ruuan'ok Ravenguard Entry: 19987
SET @NPC := 71302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3234.804,`position_y`=5328.321,`position_z`=169.0338 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3234.804,5328.321,169.0338,0,0,0,0,100,0),
(@PATH,2,3220.503,5310.8,176.2796,0,0,0,0,100,0),
(@PATH,3,3234.804,5328.321,169.0338,0,0,0,0,100,0),
(@PATH,4,3249.991,5349.114,175.4366,0,0,0,0,100,0);

-- Pathing for Ruuan'ok Ravenguard Entry: 19987
SET @NPC := 71307;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3289.056,`position_y`=5337.989,`position_z`=165.6006 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3289.056,5337.989,165.6006,0,0,0,0,100,0),
(@PATH,2,3277.43,5346.705,176.2765,0,0,0,0,100,0),
(@PATH,3,3289.056,5337.989,165.6006,0,0,0,0,100,0),
(@PATH,4,3303.381,5327.979,155.5863,0,0,0,0,100,0);

-- Pathing for Bloodmaul Mauler Entry: 19993
SET @NPC := 71372;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3198.46,`position_y`=5902.458,`position_z`=-4.34794 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3198.46,5902.458,-4.34794,0,0,0,0,100,0),
(@PATH,2,3201.894,5917.879,-2.356922,0,0,0,0,100,0),
(@PATH,3,3198.46,5902.458,-4.34794,0,0,0,0,100,0),
(@PATH,4,3195.467,5887.292,-6.297141,0,0,0,0,100,0),
(@PATH,5,3202.613,5877.735,-6.282515,0,0,0,0,100,0),
(@PATH,6,3210.058,5868.283,-5.644575,0,0,0,0,100,0),
(@PATH,7,3222.229,5858.961,-4.911263,0,0,0,0,100,0),
(@PATH,8,3210.058,5868.283,-5.644575,0,0,0,0,100,0),
(@PATH,9,3202.613,5877.735,-6.282515,0,0,0,0,100,0),
(@PATH,10,3195.467,5887.292,-6.297141,0,0,0,0,100,0),
(@PATH,11,3198.46,5902.458,-4.34794,0,0,0,0,100,0),
(@PATH,12,3201.894,5917.879,-2.356922,0,0,0,0,100,0);

-- Pathing for Bloodmaul Mauler Entry: 19993
SET @NPC := 71373;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3248.543,`position_y`=5844.174,`position_z`=-1.084592 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3248.543,5844.174,-1.084592,0,0,0,0,100,0),
(@PATH,2,3233.535,5852.159,-2.972287,0,0,0,0,100,0),
(@PATH,3,3248.543,5844.174,-1.084592,0,0,0,0,100,0),
(@PATH,4,3268.851,5840.554,-2.014892,0,0,0,0,100,0),
(@PATH,5,3282.394,5844.522,-2.549926,0,0,0,0,100,0),
(@PATH,6,3291.445,5852.187,-1.510863,0,0,0,0,100,0),
(@PATH,7,3282.394,5844.522,-2.549926,0,0,0,0,100,0),
(@PATH,8,3268.851,5840.554,-2.014892,0,0,0,0,100,0);

-- Pathing for Bloodmaul Warlock Entry: 19994
SET @NPC := 71393;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3463.085,`position_y`=5733.709,`position_z`=11.79834 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3463.085,5733.709,11.79834,0,0,0,0,100,0),
(@PATH,2,3452.174,5763.84,-1.273932,0,0,0,0,100,0),
(@PATH,3,3442.229,5777.899,-0.977293,0,0,0,0,100,0),
(@PATH,4,3455.017,5759.097,-0.5055969,0,0,0,0,100,0),
(@PATH,5,3463.432,5733.145,12.09697,0,0,0,0,100,0),
(@PATH,6,3488.859,5751.386,24.1469,0,0,0,0,100,0),
(@PATH,7,3487.431,5770.356,32.22961,0,0,0,0,100,0),
(@PATH,8,3475.49,5770.881,33.30943,0,0,0,0,100,0),
(@PATH,9,3468.75,5771.593,34.02132,0,0,0,0,100,0),
(@PATH,10,3468.75,5771.593,34.02132,1.832596,25000,0,0,100,0),
(@PATH,11,3487.195,5770.171,32.17501,0,0,0,0,100,0),
(@PATH,12,3488.75,5751.26,24.07138,0,0,0,0,100,0);

-- Pathing for Bloodmaul Warlock Entry: 19994
SET @NPC := 71399;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3501.822,`position_y`=5862.582,`position_z`=17.17031 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3501.822,5862.582,17.17031,0,0,0,0,100,0),
(@PATH,2,3500.019,5853.069,10.88851,0,0,0,0,100,0),
(@PATH,3,3499.19,5844.096,5.862134,0,0,0,0,100,0),
(@PATH,4,3501.415,5828.135,1.586879,0,0,0,0,100,0),
(@PATH,5,3508.313,5819.247,1.444179,0,0,0,0,100,0),
(@PATH,6,3505.032,5809.644,1.444179,0,0,0,0,100,0),
(@PATH,7,3501.014,5838.625,2.168034,0,0,0,0,100,0),
(@PATH,8,3497.148,5854.303,11.11029,0,0,0,0,100,0),
(@PATH,9,3502.206,5866.667,19.30453,0,0,0,0,100,0),
(@PATH,10,3506.062,5870.624,22.94534,0,0,0,0,100,0),
(@PATH,11,3515.424,5873.07,25.66988,0,0,0,0,100,0),
(@PATH,12,3523.169,5862.645,25.88552,0,0,0,0,100,0),
(@PATH,13,3521.784,5852.47,25.89481,0,0,0,0,100,0),
(@PATH,14,3521.784,5852.47,25.89481,0.9599311,25000,0,0,100,0),
(@PATH,15,3521.362,5865.634,25.7237,0,0,0,0,100,0),
(@PATH,16,3512.572,5875.438,25.76649,0,0,0,0,100,0),
(@PATH,17,3506.493,5870.488,23.10028,0,0,0,0,100,0),
(@PATH,18,3501.822,5862.582,17.17031,0,0,0,0,100,0);

-- Pathing for Bloodmaul Mauler Entry: 19993
SET @NPC := 71375;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3359.918,`position_y`=5834.109,`position_z`=17.832 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3359.918,5834.109,17.832,0,0,0,0,100,0),
(@PATH,2,3359.529,5804.505,29.08768,0,0,0,0,100,0),
(@PATH,3,3375.961,5792.07,37.97398,0,0,0,0,100,0),
(@PATH,4,3384.408,5801.223,39.05558,0,0,0,0,100,0),
(@PATH,5,3387.168,5807.018,39.67704,0,0,0,0,100,0),
(@PATH,6,3387.168,5807.018,39.67704,5.550147,30000,0,0,100,0),
(@PATH,7,3376.688,5794.795,37.82664,0,0,0,0,100,0),
(@PATH,8,3361.057,5802.239,30.38775,0,0,0,0,100,0),
(@PATH,9,3359.876,5832.924,17.71298,0,0,0,0,100,0),
(@PATH,10,3388.703,5826.479,4.107426,0,0,0,0,100,0),
(@PATH,11,3402.898,5818.982,3.016188,0,0,0,0,100,0),
(@PATH,12,3409.57,5809.246,5.184645,0,0,0,0,100,0),
(@PATH,13,3397.427,5822.894,2.250224,0,0,0,0,100,0),
(@PATH,14,3380.593,5828.696,8.012256,0,0,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72814;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2747.314,`position_y`=5279.998,`position_z`=263.7417 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2747.314,5279.998,263.7417,0,0,0,0,100,0),
(@PATH,2,2766.484,5281.167,260.8009,0,0,0,0,100,0),
(@PATH,3,2778.845,5272.923,260.5821,0,0,0,0,100,0),
(@PATH,4,2791.105,5278.549,261.6206,0,0,0,0,100,0),
(@PATH,5,2807.899,5270.841,259.4217,0,0,0,0,100,0),
(@PATH,6,2820.132,5274.604,259.947,0,0,0,0,100,0),
(@PATH,7,2830.095,5280.248,262.7404,0,0,0,0,100,0),
(@PATH,8,2833.156,5285.987,263.5571,0,0,0,0,100,0),
(@PATH,9,2832.846,5295.709,263.5571,0,0,0,0,100,0),
(@PATH,10,2833.278,5280.854,263.5437,0,0,0,0,100,0),
(@PATH,11,2821.71,5274.678,260.1666,0,0,0,0,100,0),
(@PATH,12,2808.218,5271.77,259.4819,0,0,0,0,100,0),
(@PATH,13,2791.397,5280.87,261.7857,0,0,0,0,100,0),
(@PATH,14,2783.284,5273.771,260.5588,0,0,0,0,100,0),
(@PATH,15,2772.541,5277.695,261.0188,0,0,0,0,100,0),
(@PATH,16,2759.622,5281.937,261.5321,0,0,0,0,100,0),
(@PATH,17,2746.176,5282.163,263.4464,0,0,0,0,100,0),
(@PATH,18,2735.697,5281.101,263.894,0,0,0,0,100,0),
(@PATH,19,2732.458,5280.791,263.7445,0,0,0,0,100,0),
(@PATH,20,2732.458,5280.791,263.7445,2.879793,20000,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72816;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2831.291,`position_y`=5240.254,`position_z`=264.6 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2831.291,5240.254,264.6,0,0,0,0,100,0),
(@PATH,2,2834.43,5236.051,264.7007,0,0,0,0,100,0),
(@PATH,3,2839.543,5230.542,265.2141,0,0,0,0,100,0),
(@PATH,4,2846.254,5227.577,267.1809,0,0,0,0,100,0),
(@PATH,5,2853.22,5226.886,268.5766,0,0,0,0,100,0),
(@PATH,6,2855.437,5222.403,270.5766,0,0,0,0,100,0),
(@PATH,7,2850.782,5229.897,268.0141,0,0,0,0,100,0),
(@PATH,8,2859.629,5238.062,269.7938,0,0,0,0,100,0),
(@PATH,9,2860.871,5244.809,270.2007,0,0,0,0,100,0),
(@PATH,10,2860.005,5247.587,270.2007,0,0,0,0,100,0),
(@PATH,11,2847.751,5241.762,267.5786,0,0,0,0,100,0),
(@PATH,12,2839.375,5243.706,265.2953,0,0,0,0,100,0),
(@PATH,13,2829.783,5243.597,264.475,0,0,0,0,100,0),
(@PATH,14,2824.449,5244.75,264.35,0,0,0,0,100,0),
(@PATH,15,2824.449,5244.75,264.35,2.268928,6000,0,0,100,0);

-- Pathing for Razaani Raider Entry: 20601
SET @NPC := 72706;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2868.394,`position_y`=5169.124,`position_z`=265.7549 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2868.394,5169.124,265.7549,4.729842,8000,0,0,100,0),
(@PATH,2,2866.896,5161.038,265.4473,0,0,0,0,100,0),
(@PATH,3,2872.777,5133.538,263.2297,0,0,0,0,100,0),
(@PATH,4,2896.839,5113.007,263.8251,0,0,0,0,100,0),
(@PATH,5,2915.992,5118.841,262.8208,0,0,0,0,100,0),
(@PATH,6,2918.312,5123.27,262.0192,3.979351,16000,0,0,100,0),
(@PATH,7,2915.967,5116.584,263.0192,0,0,0,0,100,0),
(@PATH,8,2900.001,5113.138,263.269,0,0,0,0,100,0),
(@PATH,9,2875.748,5133.605,262.8052,0,0,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72818;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2883.068,`position_y`=5194.57,`position_z`=265.7122 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2883.068,5194.57,265.7122,0,0,0,0,100,0),
(@PATH,2,2878.952,5224.159,269.7598,0,0,0,0,100,0),
(@PATH,3,2899.996,5222.4,268.6732,0,0,0,0,100,0),
(@PATH,4,2933.143,5221.48,265.0293,0,0,0,0,100,0),
(@PATH,5,2941.658,5222.568,264.4865,0,0,0,0,100,0),
(@PATH,6,2954.74,5239.299,261.8019,0,0,0,0,100,0),
(@PATH,7,2952.646,5248.457,262.553,0,0,0,0,100,0),
(@PATH,8,2952.714,5248.16,262.5422,6.248279,25000,0,0,100,0),
(@PATH,9,2954.038,5239.832,262.0111,0,0,0,0,100,0),
(@PATH,10,2940.236,5221.063,264.817,0,0,0,0,100,0),
(@PATH,11,2899.993,5222.635,268.6732,0,0,0,0,100,0),
(@PATH,12,2878.678,5224.804,269.8372,0,0,0,0,100,0),
(@PATH,13,2882.689,5200.135,266.4232,0,0,0,0,100,0),
(@PATH,14,2880.937,5183.451,265.2586,0,0,0,0,100,0),
(@PATH,15,2876.168,5171.161,264.356,0,0,0,0,100,0),
(@PATH,16,2878.819,5176.691,264.957,0,0,0,0,100,0);

-- Pathing for Razaani Raider Entry: 20601
SET @NPC := 72702;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2791.592,`position_y`=5174.454,`position_z`=263.3 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2791.592,5174.454,263.3,0,0,0,0,100,0),
(@PATH,2,2799.62,5197.615,266.7466,0,0,0,0,100,0),
(@PATH,3,2795.16,5208.085,266.0106,0,0,0,0,100,0),
(@PATH,4,2788.055,5219.257,264.1811,0,0,0,0,100,0),
(@PATH,5,2780.895,5224.967,264.5617,0,0,0,0,100,0),
(@PATH,6,2790.619,5216.124,264.5011,0,0,0,0,100,0),
(@PATH,7,2795.216,5201.881,266.4367,0,0,0,0,100,0),
(@PATH,8,2797.372,5190.849,266.333,0,0,0,0,100,0),
(@PATH,9,2790.638,5178.778,264.4642,0,0,0,0,100,0),
(@PATH,10,2787.837,5174.005,263.5299,0,0,0,0,100,0),
(@PATH,11,2784.438,5170.09,262.5934,0,0,0,0,100,0),
(@PATH,12,2779.083,5162.935,262.5351,0,0,0,0,100,0),
(@PATH,13,2779.083,5162.935,262.5351,3.752458,20000,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72820;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2807.345,`position_y`=5184.644,`position_z`=266.707 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2807.345,5184.644,266.707,0,0,0,0,100,0),
(@PATH,2,2822.968,5177.979,267.282,0,0,0,0,100,0),
(@PATH,3,2833.178,5168.088,266.4262,0,0,0,0,100,0),
(@PATH,4,2838.222,5164.714,266.1911,0,0,0,0,100,0),
(@PATH,5,2838.222,5164.714,266.1911,2.583087,25000,0,0,100,0),
(@PATH,6,2833.368,5163.571,266.1911,0,0,0,0,100,0),
(@PATH,7,2833.632,5130.24,265.0708,0,0,0,0,100,0),
(@PATH,8,2811.64,5114.466,264.8811,0,0,0,0,100,0),
(@PATH,9,2794.348,5111.946,265.2955,0,0,0,0,100,0),
(@PATH,10,2776.199,5123.329,264.2955,0,0,0,0,100,0),
(@PATH,11,2754.535,5133.27,264.778,0,0,0,0,100,0),
(@PATH,12,2742.861,5141.46,264.9612,0,0,0,0,100,0),
(@PATH,13,2746.248,5154.773,264.7135,0,0,0,0,100,0),
(@PATH,14,2751.492,5169.116,263.2721,0,0,0,0,100,0),
(@PATH,15,2758.678,5180.823,264.1598,0,0,0,0,100,0),
(@PATH,16,2772.839,5192.492,264.4082,0,0,0,0,100,0),
(@PATH,17,2793.635,5189.519,265.6216,0,0,0,0,100,0);

-- Pathing for Razaani Raider Entry: 20601
SET @NPC := 72705;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2824.574,`position_y`=5174.435,`position_z`=267.2319 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2824.574,5174.435,267.2319,0,0,0,0,100,0),
(@PATH,2,2817.268,5174.85,266.6218,0,0,0,0,100,0),
(@PATH,3,2810.344,5171.387,265.991,0,0,0,0,100,0),
(@PATH,4,2808.21,5167.184,265.7371,0,12000,0,0,100,0),
(@PATH,5,2815.689,5173.491,266.5572,0,0,0,0,100,0),
(@PATH,6,2823.218,5173.37,266.9871,0,0,0,0,100,0),
(@PATH,7,2827.782,5173.604,266.9871,0,0,0,0,100,0),
(@PATH,8,2833.206,5173.302,266.9709,0,0,0,0,100,0),
(@PATH,9,2833.206,5173.302,266.9709,5.794493,14000,0,0,100,0);

-- Pathing for Razaani Raider Entry: 20601
SET @NPC := 72696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2676.574,`position_y`=5258.068,`position_z`=268.636 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2676.574,5258.068,268.636,0,0,0,0,100,0),
(@PATH,2,2688.415,5276.612,266.8686,0,0,0,0,100,0),
(@PATH,3,2708.661,5282.573,265.1852,0,0,0,0,100,0),
(@PATH,4,2742.16,5282.888,263.8973,0,0,0,0,100,0),
(@PATH,5,2757.027,5282.549,261.8015,0,0,0,0,100,0),
(@PATH,6,2779.005,5272.521,260.5339,0,0,0,0,100,0),
(@PATH,7,2793.131,5250.791,261.2688,0,0,0,0,100,0),
(@PATH,8,2805.42,5227.863,263.2422,0,0,0,0,100,0),
(@PATH,9,2798.738,5204.302,266.4829,0,0,0,0,100,0),
(@PATH,10,2785.566,5196.935,265.5325,0,0,0,0,100,0),
(@PATH,11,2775.052,5193.324,264.4966,0,0,0,0,100,0),
(@PATH,12,2764.669,5184.198,263.8886,0,0,0,0,100,0),
(@PATH,13,2758.268,5177.112,264.0136,0,0,0,0,100,0),
(@PATH,14,2752.054,5170.065,263.2999,0,0,0,0,100,0),
(@PATH,15,2740.5,5163.737,264.9137,0,0,0,0,100,0),
(@PATH,16,2727.267,5156.965,265.0887,0,0,0,0,100,0),
(@PATH,17,2716.005,5167.426,265.2008,0,0,0,0,100,0),
(@PATH,18,2706.868,5178.057,265.7196,0,0,0,0,100,0),
(@PATH,19,2689.939,5194.502,266.078,0,0,0,0,100,0),
(@PATH,20,2676.99,5199.604,266.9556,0,0,0,0,100,0),
(@PATH,21,2670.3,5210.75,266.1582,0,0,0,0,100,0),
(@PATH,22,2671.338,5233.865,267.8547,0,0,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2950.644,`position_y`=5172.399,`position_z`=265.1741 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2950.644,5172.399,265.1741,0,0,0,0,100,0),
(@PATH,2,2954.238,5178.42,264.9241,0,0,0,0,100,0),
(@PATH,3,2972.492,5175.019,265.8357,0,0,0,0,100,0),
(@PATH,4,2983.433,5169.014,265.583,0,0,0,0,100,0),
(@PATH,5,2978.113,5153.146,264.6109,0,0,0,0,100,0),
(@PATH,6,2972.187,5141.372,264.4199,0,0,0,0,100,0),
(@PATH,7,2994.416,5129.084,263.227,0,0,0,0,100,0),
(@PATH,8,2998.175,5137.382,264.0018,0,0,0,0,100,0),
(@PATH,9,2998.175,5137.382,264.0018,5.637414,12000,0,0,100,0),
(@PATH,10,2984.355,5133.579,263.863,0,0,0,0,100,0),
(@PATH,11,2973.601,5140.747,264.3255,0,0,0,0,100,0),
(@PATH,12,2957.57,5138.213,265.0421,0,0,0,0,100,0),
(@PATH,13,2946.302,5135.801,264.0358,0,0,0,0,100,0),
(@PATH,14,2935.337,5148.426,264.2907,0,0,0,0,100,0),
(@PATH,15,2939.809,5161.303,265.6671,0,0,0,0,100,0);

-- Pathing for Nexus Stalker Entry: 20609
SET @NPC := 72813;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2721.616,`position_y`=5273.362,`position_z`=265.3734 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2721.616,5273.362,265.3734,0,0,0,0,100,0),
(@PATH,2,2716.982,5269.973,266.8846,0,0,0,0,100,0),
(@PATH,3,2716.982,5269.973,266.8846,3.141593,23000,0,0,100,0),
(@PATH,4,2724.298,5275.242,263.912,0,0,0,0,100,0),
(@PATH,5,2724.167,5283.815,264.1429,0,0,0,0,100,0),
(@PATH,6,2721.686,5288.768,266.0814,0,0,0,0,100,0),
(@PATH,7,2721.686,5288.768,266.0814,3.089233,23000,0,0,100,0),
(@PATH,8,2721.979,5276.996,263.985,0,0,0,0,100,0),
(@PATH,9,2721.616,5273.362,265.3734,0,0,0,0,100,0);

-- Pathing for Razaani Spell-Thief Entry: 20614
SET @NPC := 72882;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2865.868,`position_y`=5210.021,`position_z`=267.2167 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2865.868,5210.021,267.2167,0,0,0,0,100,0),
(@PATH,2,2868.487,5214.209,267.5658,0,0,0,0,100,0),
(@PATH,3,2871.275,5218.956,268.3761,0,0,0,0,100,0),
(@PATH,4,2875.35,5221.989,269.3539,0,0,0,0,100,0),
(@PATH,5,2879.828,5227.542,269.9232,0,0,0,0,100,0),
(@PATH,6,2882.319,5234.739,270.184,0,0,0,0,100,0),
(@PATH,7,2884.602,5239.909,270.184,0,0,0,0,100,0),
(@PATH,8,2873.641,5237.857,270.184,0,0,0,0,100,0),
(@PATH,9,2854.845,5236.729,269.1898,0,0,0,0,100,0),
(@PATH,10,2843.063,5243.832,266.1607,0,0,0,0,100,0),
(@PATH,11,2838.622,5254.225,265.8979,0,0,0,0,100,0),
(@PATH,12,2837.759,5263.849,264.9133,0,0,0,0,100,0),
(@PATH,13,2836.029,5273.631,264.0562,0,0,0,0,100,0),
(@PATH,14,2832.068,5281.593,263.2534,0,0,0,0,100,0),
(@PATH,15,2832.068,5281.593,263.2534,4.625123,25000,0,0,100,0),
(@PATH,16,2828.788,5276.519,262.0859,0,0,0,0,100,0),
(@PATH,17,2824.646,5273.722,260.5571,0,0,0,0,100,0),
(@PATH,18,2821.867,5268.865,259.9173,0,0,0,0,100,0),
(@PATH,19,2813.289,5259.599,260.3855,0,0,0,0,100,0),
(@PATH,20,2810.32,5255.576,262.225,0,0,0,0,100,0),
(@PATH,21,2807.309,5262.661,259.8677,0,0,0,0,100,0),
(@PATH,22,2803.9,5266.601,259.9384,0,0,0,0,100,0),
(@PATH,23,2799.261,5270.037,260.8144,0,0,0,0,100,0),
(@PATH,24,2793.072,5271.663,260.5371,0,0,0,0,100,0),
(@PATH,25,2787.195,5268.139,259.7579,0,0,0,0,100,0),
(@PATH,26,2779.333,5252.357,261.4659,0,0,0,0,100,0),
(@PATH,27,2775.95,5244.858,263.4514,0,0,0,0,100,0),
(@PATH,28,2776.093,5238.111,264.6438,0,0,0,0,100,0),
(@PATH,29,2777.341,5233.657,264.6438,0,0,0,0,100,0),
(@PATH,30,2781.186,5223.515,264.5617,0,0,0,0,100,0),
(@PATH,31,2791.306,5221.588,263.3315,0,0,0,0,100,0),
(@PATH,32,2797.785,5222.131,262.8287,0,0,0,0,100,0),
(@PATH,33,2809.717,5224.459,263.9731,0,0,0,0,100,0),
(@PATH,34,2815.43,5227.806,264.5313,0,0,0,0,100,0),
(@PATH,35,2816.533,5233.999,264.6,0,0,0,0,100,0),
(@PATH,36,2819.071,5239.662,264.475,0,0,0,0,100,0),
(@PATH,37,2825.407,5238.358,264.475,0,0,0,0,100,0),
(@PATH,38,2829.861,5236.995,264.6,0,0,0,0,100,0),
(@PATH,39,2834.728,5232.177,264.7016,0,0,0,0,100,0),
(@PATH,40,2840.849,5227.285,265.9569,0,0,0,0,100,0),
(@PATH,41,2846.505,5226.701,267.3463,0,0,0,0,100,0),
(@PATH,42,2856.988,5227.479,268.7276,0,0,0,0,100,0),
(@PATH,43,2864.957,5220.388,268.3356,0,0,0,0,100,0),
(@PATH,44,2866.072,5213.004,267.5746,0,0,0,0,100,0);

-- Pathing for Bladespire Mystic Entry: 20766
SET @NPC := 73269;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2318.445,`position_y`=5726.26,`position_z`=267.4254 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2318.445,5726.26,267.4254,4.310963,3000,0,0,100,0),
(@PATH,2,2328.346,5742.23,267.8742,0,0,0,0,100,0),
(@PATH,3,2343.199,5750.309,271.1055,0,0,0,0,100,0),
(@PATH,4,2360.11,5751.934,272.0094,0,0,0,0,100,0),
(@PATH,5,2393.392,5752.299,271.9437,0,0,0,0,100,0),
(@PATH,6,2411.942,5736.872,271.7954,0,0,0,0,100,0),
(@PATH,7,2420.964,5741.567,272.2954,0,0,0,0,100,0),
(@PATH,8,2413.563,5735.228,271.7954,0,0,0,0,100,0),
(@PATH,9,2397.828,5750.455,271.9437,0,0,0,0,100,0),
(@PATH,10,2382.034,5751.93,271.6003,0,0,0,0,100,0),
(@PATH,11,2367.424,5749.731,272.1653,0,0,0,0,100,0),
(@PATH,12,2352.037,5753.432,272.0094,0,0,0,0,100,0),
(@PATH,13,2333.164,5748.944,269.0971,0,0,0,0,100,0),
(@PATH,14,2322.428,5733.196,267.5504,0,0,0,0,100,0);

-- Pathing for Bladespire Mystic Entry: 20766
SET @NPC := 73265;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2172.576,`position_y`=5693.825,`position_z`=266.2848 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2172.576,5693.825,266.2848,0,0,0,0,100,0),
(@PATH,2,2168.3,5689.393,266.4495,0,0,0,0,100,0),
(@PATH,3,2167.921,5682.331,266.6228,0,0,0,0,100,0),
(@PATH,4,2167.831,5672.204,266.5118,0,0,0,0,100,0),
(@PATH,5,2167.907,5680.204,266.7462,0,0,0,0,100,0),
(@PATH,6,2168.597,5688.244,266.4098,0,0,0,0,100,0),
(@PATH,7,2174.173,5697.236,266.0348,0,0,0,0,100,0),
(@PATH,8,2179.537,5705.76,266.2533,0,0,0,0,100,0),
(@PATH,9,2184.909,5709.139,267.148,0,0,0,0,100,0),
(@PATH,10,2178.867,5701.97,266.173,0,0,0,0,100,0);

-- Pathing for Bladespire Crusher Entry: 20765
SET @NPC := 73255;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2231.698,`position_y`=5661.139,`position_z`=268.4052 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2231.698,5661.139,268.4052,0,0,0,0,100,0),
(@PATH,2,2219.974,5668.674,268.2742,0,0,0,0,100,0),
(@PATH,3,2205.987,5675.572,268.2742,0,0,0,0,100,0),
(@PATH,4,2191.559,5678.785,268.1765,0,0,0,0,100,0),
(@PATH,5,2178.991,5678.108,267.9471,0,0,0,0,100,0),
(@PATH,6,2173.167,5677.225,267.3319,0,0,0,0,100,0),
(@PATH,7,2173.167,5677.225,267.3319,3.717551,0,0,0,100,0),
(@PATH,8,2191.559,5678.785,268.1765,0,0,0,0,100,0),
(@PATH,9,2219.5,5671.186,268.2742,0,0,0,0,100,0),
(@PATH,10,2229.442,5663.776,268.3794,0,0,0,0,100,0),
(@PATH,11,2254.88,5654.762,267.4706,0,0,0,0,100,0),
(@PATH,12,2256.178,5658.267,266.8165,0,0,0,0,100,0),
(@PATH,13,2246.031,5657.322,268.7368,0,0,0,0,100,0);

-- Pathing for Bladespire Mystic Entry: 20766
SET @NPC := 73272;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2397.284,`position_y`=5590.084,`position_z`=268.1895 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2397.284,5590.084,268.1895,0,0,0,0,100,0),
(@PATH,2,2392.438,5604.022,267.9428,0,0,0,0,100,0),
(@PATH,3,2389.101,5614.473,266.2085,0,0,0,0,100,0),
(@PATH,4,2385.002,5624.215,266.3827,0,0,0,0,100,0),
(@PATH,5,2389.101,5614.473,266.2085,0,0,0,0,100,0),
(@PATH,6,2396.292,5589.72,268.1459,0,0,0,0,100,0),
(@PATH,7,2403.723,5575.995,267.1623,0,0,0,0,100,0),
(@PATH,8,2407.044,5569.017,267.3791,0,0,0,0,100,0),
(@PATH,9,2403.723,5575.995,267.1623,0,0,0,0,100,0);

-- Pathing for Bladespire Crusher Entry: 20765
SET @NPC := 73258;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2226.816,`position_y`=5744.645,`position_z`=272.8089 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2226.816,5744.645,272.8089,0,0,0,0,100,0),
(@PATH,2,2222.008,5753.221,268.6754,0,0,0,0,100,0),
(@PATH,3,2226.787,5766.257,267.0599,0,0,0,0,100,0),
(@PATH,4,2246.691,5771.651,268.3277,0,0,0,0,100,0),
(@PATH,5,2265.497,5765.175,268.3109,0,0,0,0,100,0),
(@PATH,6,2295.209,5748.869,269.4628,0,0,0,0,100,0),
(@PATH,7,2283.825,5746.083,268.6768,0,0,0,0,100,0),
(@PATH,8,2265.497,5765.175,268.3109,0,0,0,0,100,0),
(@PATH,9,2246.691,5771.651,268.3277,0,0,0,0,100,0),
(@PATH,10,2226.787,5766.257,267.0599,0,0,0,0,100,0),
(@PATH,11,2222.008,5753.221,268.6754,0,0,0,0,100,0);

-- Pathing for Bladespire Mystic Entry: 20766
SET @NPC := 73256;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2274.694,`position_y`=5724.646,`position_z`=272.0905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2274.694,5724.646,272.0905,0,0,0,0,100,0),
(@PATH,2,2260.626,5727.031,272.283,0,0,0,0,100,0),
(@PATH,3,2245.788,5723.182,272.283,0,0,0,0,100,0),
(@PATH,4,2239.238,5717.667,272.908,0,0,0,0,100,0),
(@PATH,5,2231.945,5714.027,272.9055,0,0,0,0,100,0),
(@PATH,6,2229.416,5717.606,272.9055,0,0,0,0,100,0),
(@PATH,7,2225.324,5724.415,272.9055,0,0,0,0,100,0),
(@PATH,8,2219.869,5726.651,272.9055,0,0,0,0,100,0),
(@PATH,9,2225.324,5724.415,272.9055,0,0,0,0,100,0),
(@PATH,10,2229.416,5717.606,272.9055,0,0,0,0,100,0),
(@PATH,11,2231.945,5714.027,272.9055,0,0,0,0,100,0),
(@PATH,12,2242.075,5719.841,272.6031,0,0,0,0,100,0),
(@PATH,13,2251.203,5724.941,272.283,0,0,0,0,100,0),
(@PATH,14,2261.698,5728.143,272.283,0,0,0,0,100,0),
(@PATH,15,2271.782,5730.642,270.8441,0,0,0,0,100,0),
(@PATH,16,2286.763,5729.827,268.041,0,0,0,0,100,0),
(@PATH,17,2292.769,5725.762,268.1232,0,0,0,0,100,0),
(@PATH,18,2301.24,5724.365,267.6754,0,0,0,0,100,0),
(@PATH,19,2306.994,5726.303,267.6443,0,0,0,0,100,0),
(@PATH,20,2295.238,5725.443,268.1232,0,0,0,0,100,0),
(@PATH,21,2288.118,5728.598,267.8848,0,0,0,0,100,0);

-- Pathing for Bladespire Crusher Entry: 20765
SET @NPC := 73257;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2311.043,`position_y`=5698.255,`position_z`=266.6283 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2311.043,5698.255,266.6283,0,0,0,0,100,0),
(@PATH,2,2314.912,5716.434,267.1754,0,0,0,0,100,0),
(@PATH,3,2313.009,5698.853,266.6269,0,0,0,0,100,0),
(@PATH,4,2305.687,5690.478,266.2533,0,0,0,0,100,0),
(@PATH,5,2296.461,5682.542,265.761,0,0,0,0,100,0),
(@PATH,6,2280.856,5678.081,265.5681,0,0,0,0,100,0),
(@PATH,7,2271.578,5672.463,264.894,0,0,0,0,100,0),
(@PATH,8,2266.044,5668.968,264.967,0,0,0,0,100,0),
(@PATH,9,2257.922,5662.913,265.7163,0,0,0,0,100,0),
(@PATH,10,2257.922,5662.913,265.7163,4.642576,0,0,0,100,0),
(@PATH,11,2266.044,5668.968,264.967,0,0,0,0,100,0),
(@PATH,12,2271.578,5672.463,264.894,0,0,0,0,100,0),
(@PATH,13,2280.856,5678.081,265.5681,0,0,0,0,100,0),
(@PATH,14,2296.461,5682.542,265.761,0,0,0,0,100,0),
(@PATH,15,2302.904,5688.686,266.2082,0,0,0,0,100,0);

-- Pathing for Bladespire Mystic Entry: 20766
SET @NPC := 73274;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2432.805,`position_y`=5677.815,`position_z`=265.0823 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2432.805,5677.815,265.0823,0,0,0,0,100,0),
(@PATH,2,2428.316,5689.888,267.2553,0,0,0,0,100,0),
(@PATH,3,2419.72,5707.572,271.2796,0,0,0,0,100,0),
(@PATH,4,2417.84,5719.686,271.8582,0,0,0,0,100,0),
(@PATH,5,2420.327,5735.48,272.1156,0,0,0,0,100,0),
(@PATH,6,2420.327,5735.48,272.1156,0.6283185,0,0,0,100,0),
(@PATH,7,2418.319,5708.336,271.4334,0,0,0,0,100,0),
(@PATH,8,2427.077,5695.605,268.6273,0,0,0,0,100,0),
(@PATH,9,2428.473,5683.438,266.028,0,0,0,0,100,0),
(@PATH,10,2434.22,5673.826,264.6623,0,0,0,0,100,0),
(@PATH,11,2431.835,5659.415,265.0701,0,0,0,0,100,0),
(@PATH,12,2427.075,5647.434,265.6374,0,0,0,0,100,0),
(@PATH,13,2430.527,5630.032,266.7124,0,0,0,0,100,0);

-- Pathing for Wyrmcult Poacher Entry: 21809
SET @NPC := 76196;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3178.049,`position_y`=5557.268,`position_z`=141.3802 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3178.049,5557.268,141.3802,0,0,0,0,100,0),
(@PATH,2,3182.607,5556.395,141.7496,0,0,0,0,100,0),
(@PATH,3,3178.049,5557.268,141.3802,0,0,0,0,100,0),
(@PATH,4,3174.47,5550.705,142.4786,0,0,0,0,100,0),
(@PATH,5,3176.777,5543.423,143.0757,0,0,0,0,100,0),
(@PATH,6,3187.125,5544.939,142.1246,0,0,0,0,100,0),
(@PATH,7,3176.777,5543.423,143.0757,0,0,0,0,100,0),
(@PATH,8,3174.47,5550.705,142.4786,0,0,0,0,100,0);

-- Pathing for Wyrmcult Poacher Entry: 21809
SET @NPC := 76184;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2712.309,`position_y`=5436.154,`position_z`=136.7454 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2712.309,5436.154,136.7454,0,0,0,0,100,0),
(@PATH,2,2716.99,5439.282,136.8832,0,0,0,0,100,0),
(@PATH,3,2726.574,5436.762,137.2304,0,0,0,0,100,0),
(@PATH,4,2731.143,5428.338,136.957,0,0,0,0,100,0),
(@PATH,5,2724.835,5422.234,137.1687,0,0,0,0,100,0),
(@PATH,6,2734.54,5430.499,137.0476,0,0,0,0,100,0),
(@PATH,7,2726.574,5436.762,137.2304,0,0,0,0,100,0),
(@PATH,8,2716.99,5439.282,136.8832,0,0,0,0,100,0);

-- Pathing for Wyrmcult Poacher Entry: 21809
SET @NPC := 76193;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3133.941,`position_y`=5588.938,`position_z`=144.3686 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3133.941,5588.938,144.3686,0,0,0,0,100,0),
(@PATH,2,3127.968,5584.061,145.9625,0,0,0,0,100,0),
(@PATH,3,3118.354,5592.705,145.8571,0,0,0,0,100,0),
(@PATH,4,3121.888,5600.984,144.5413,0,0,0,0,100,0),
(@PATH,5,3131.035,5601.228,143.4163,0,0,0,0,100,0),
(@PATH,6,3121.919,5601.064,144.5332,0,0,0,0,100,0),
(@PATH,7,3118.386,5592.785,145.8871,0,0,0,0,100,0),
(@PATH,8,3127.968,5584.061,145.9625,0,0,0,0,100,0);

-- Pathing for Wyrmcult Poacher Entry: 21809
SET @NPC := 76192;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3102.847,`position_y`=5630.538,`position_z`=144.2913 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3102.847,5630.538,144.2913,0,0,0,0,100,0),
(@PATH,2,3098.793,5627.071,144.2706,0,0,0,0,100,0),
(@PATH,3,3099.693,5619.753,143.9884,0,0,0,0,100,0),
(@PATH,4,3103.867,5614.208,144.9082,0,0,0,0,100,0),
(@PATH,5,3111.378,5614.678,144.3424,0,0,0,0,100,0),
(@PATH,6,3116.698,5619.038,143.6944,0,0,0,0,100,0),
(@PATH,7,3111.378,5614.678,144.3424,0,0,0,0,100,0),
(@PATH,8,3103.867,5614.208,144.9082,0,0,0,0,100,0),
(@PATH,9,3099.693,5619.753,143.9884,0,0,0,0,100,0),
(@PATH,10,3098.793,5627.071,144.2706,0,0,0,0,100,0);

-- Pathing for Wyrmcult Poacher Entry: 21809
SET @NPC := 76189;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3047.63,`position_y`=5699.292,`position_z`=145.0271 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3047.63,5699.292,145.0271,0,0,0,0,100,0),
(@PATH,2,3053.622,5709.193,144.5295,0,0,0,0,100,0),
(@PATH,3,3049.765,5713.083,144.6085,0,0,0,0,100,0),
(@PATH,4,3043.761,5714.523,144.5324,0,0,0,0,100,0),
(@PATH,5,3049.765,5713.083,144.6085,0,0,0,0,100,0),
(@PATH,6,3053.622,5709.193,144.5295,0,0,0,0,100,0),
(@PATH,7,3047.63,5699.292,145.0271,0,0,0,0,100,0),
(@PATH,8,3035.984,5701.408,145.139,0,0,0,0,100,0),
(@PATH,9,3035.092,5707.758,144.789,0,0,0,0,100,0),
(@PATH,10,3035.984,5701.408,145.139,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2761.55,`position_y`=5437.068,`position_z`=136.6383 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2761.55,5437.068,136.6383,0,0,0,0,100,0),
(@PATH,2,2754.083,5432.378,136.4561,0,0,0,0,100,0),
(@PATH,3,2761.55,5437.068,136.6383,0,0,0,0,100,0),
(@PATH,4,2766.857,5432.17,137.064,0,0,0,0,100,0),
(@PATH,5,2765.856,5423.834,136.654,0,0,0,0,100,0),
(@PATH,6,2759.962,5421.616,136.896,0,0,0,0,100,0),
(@PATH,7,2765.856,5423.834,136.654,0,0,0,0,100,0),
(@PATH,8,2766.857,5432.17,137.064,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3218.072,`position_y`=5526.814,`position_z`=144.1231 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3218.072,5526.814,144.1231,0,0,0,0,100,0),
(@PATH,2,3222.341,5535.49,142.1417,0,0,0,0,100,0),
(@PATH,3,3218.072,5526.814,144.1231,0,0,0,0,100,0),
(@PATH,4,3210.133,5529.915,144.0798,0,0,0,0,100,0),
(@PATH,5,3208.623,5540.399,142.2348,0,0,0,0,100,0),
(@PATH,6,3210.133,5529.915,144.0798,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76249;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3381.341,`position_y`=5387.936,`position_z`=147.7524 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3381.341,5387.936,147.7524,0,0,0,0,100,0),
(@PATH,2,3388.214,5384.256,148.0874,0,0,0,0,100,0),
(@PATH,3,3395.14,5386.871,148.0642,0,0,0,0,100,0),
(@PATH,4,3388.214,5384.256,148.0874,0,0,0,0,100,0),
(@PATH,5,3381.341,5387.936,147.7524,0,0,0,0,100,0),
(@PATH,6,3381.781,5398.843,148.6405,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76252;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3392.02,`position_y`=5491.935,`position_z`=144.2147 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3392.02,5491.935,144.2147,0,0,0,0,100,0),
(@PATH,2,3397.563,5484.7,144.347,0,0,0,0,100,0),
(@PATH,3,3410.824,5486.551,143.241,0,0,0,0,100,0),
(@PATH,4,3417.64,5498.665,142.241,0,0,0,0,100,0),
(@PATH,5,3410.824,5486.551,143.241,0,0,0,0,100,0),
(@PATH,6,3397.563,5484.7,144.347,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76242;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3160.395,`position_y`=5587.131,`position_z`=142.0543 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3160.395,5587.131,142.0543,0,0,0,0,100,0),
(@PATH,2,3149.173,5589.543,143.9315,0,0,0,0,100,0),
(@PATH,3,3142.719,5587.694,144.3178,0,0,0,0,100,0),
(@PATH,4,3138.922,5588.964,144.1379,0,0,0,0,100,0),
(@PATH,5,3142.719,5587.694,144.3178,0,0,0,0,100,0),
(@PATH,6,3149.173,5589.543,143.9315,0,0,0,0,100,0),
(@PATH,7,3160.395,5587.131,142.0543,0,0,0,0,100,0),
(@PATH,8,3159.027,5598.711,142.2185,0,0,0,0,100,0),
(@PATH,9,3150.76,5603.312,143.6365,0,0,0,0,100,0),
(@PATH,10,3159.027,5598.711,142.2185,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76238;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3084.396,`position_y`=5671.77,`position_z`=143.0218 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3084.396,5671.77,143.0218,0,0,0,0,100,0),
(@PATH,2,3091.814,5670.005,143.3318,0,0,0,0,100,0),
(@PATH,3,3096.926,5661.211,142.7585,0,0,0,0,100,0),
(@PATH,4,3099.337,5653.452,143.2585,0,0,0,0,100,0),
(@PATH,5,3096.926,5661.211,142.7585,0,0,0,0,100,0),
(@PATH,6,3091.814,5670.005,143.3318,0,0,0,0,100,0),
(@PATH,7,3084.396,5671.77,143.0218,0,0,0,0,100,0),
(@PATH,8,3080.87,5677.69,142.8318,0,0,0,0,100,0),
(@PATH,9,3087.86,5681.645,143.0818,0,0,0,0,100,0),
(@PATH,10,3095.208,5676.298,142.8442,0,0,0,0,100,0),
(@PATH,11,3099.552,5668.224,142.6981,0,0,0,0,100,0),
(@PATH,12,3095.208,5676.298,142.8442,0,0,0,0,100,0),
(@PATH,13,3087.86,5681.645,143.0818,0,0,0,0,100,0),
(@PATH,14,3080.87,5677.69,142.8318,0,0,0,0,100,0);

-- Pathing for Wyrmcult Hewer Entry: 21810
SET @NPC := 76236;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3097.679,`position_y`=5650.661,`position_z`=143.2585 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3097.679,5650.661,143.2585,0,0,0,0,100,0),
(@PATH,2,3093.772,5650.761,143.1335,0,0,0,0,100,0),
(@PATH,3,3089.367,5646.542,142.8835,0,0,0,0,100,0),
(@PATH,4,3089.931,5636.272,143.2824,0,0,0,0,100,0),
(@PATH,5,3094.533,5629.466,144.3956,0,0,0,0,100,0),
(@PATH,6,3102.622,5632.66,144.1846,0,0,0,0,100,0),
(@PATH,7,3094.533,5629.466,144.3956,0,0,0,0,100,0),
(@PATH,8,3089.931,5636.272,143.2824,0,0,0,0,100,0),
(@PATH,9,3089.367,5646.542,142.8835,0,0,0,0,100,0),
(@PATH,10,3093.772,5650.761,143.1335,0,0,0,0,100,0);
