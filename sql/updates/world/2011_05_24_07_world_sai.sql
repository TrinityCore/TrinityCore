-- Pathing for Venom Stalker Entry: 15976
SET @NPC := 127864; -- 127865 should be in formation with him
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3310.01,`position_y`=-3862.94,`position_z`=294.662 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3321.301,-3868.157,294.6607,0,0,0,100,0),
(@PATH,2,3328.406,-3877.447,294.6608,0,0,0,100,0),
(@PATH,3,3327.705,-3889.598,294.6607,0,0,0,100,0),
(@PATH,4,3312.01,-3901.51,294.6607,0,0,0,100,0),
(@PATH,5,3297.603,-3897.307,294.6607,0,0,0,100,0),
(@PATH,6,3292.267,-3890.234,294.6607,0,0,0,100,0),
(@PATH,7,3290.384,-3882.75,294.6607,0,0,0,100,0),
(@PATH,8,3279.155,-3882.98,294.6607,0,0,0,100,0),
(@PATH,9,3260.253,-3882.767,294.6603,0,0,0,100,0),
(@PATH,10,3241.78,-3882.872,292.3388,0,0,0,100,0),
(@PATH,11,3221.214,-3882.398,282.8664,0,0,0,100,0),
(@PATH,12,3207.818,-3881.953,275.8379,0,0,0,100,0),
(@PATH,13,3166.121,-3882.08,267.5934,0,0,0,100,0),
(@PATH,14,3142.54,-3882.999,267.5932,0,0,0,100,0),
(@PATH,15,3118.083,-3883.491,267.593,0,0,0,100,0),
(@PATH,16,3114.162,-3894.186,267.5924,0,0,0,100,0),
(@PATH,17,3104.3,-3900.575,267.593,0,0,0,100,0),
(@PATH,18,3093.041,-3899.523,267.593,0,0,0,100,0),
(@PATH,19,3083.292,-3890.907,267.5929,0,0,0,100,0),
(@PATH,20,3082.536,-3878.924,267.593,0,0,0,100,0),
(@PATH,21,3088.724,-3868.493,267.593,0,0,0,100,0),
(@PATH,22,3103.835,-3863.884,267.593,0,0,0,100,0),
(@PATH,23,3114.156,-3873.857,267.5919,0,0,0,100,0),
(@PATH,24,3118.014,-3882.239,267.5925,0,0,0,100,0),
(@PATH,25,3142.844,-3882.002,267.5931,0,0,0,100,0),
(@PATH,26,3166.121,-3882.08,267.5934,0,0,0,100,0),
(@PATH,27,3207.818,-3881.953,275.8379,0,0,0,100,0),
(@PATH,28,3221.214,-3882.398,282.8664,0,0,0,100,0),
(@PATH,29,3241.78,-3882.872,292.3388,0,0,0,100,0),
(@PATH,30,3260.253,-3882.767,294.6603,0,0,0,100,0),
(@PATH,31,3279.155,-3882.98,294.6607,0,0,0,100,0),
(@PATH,32,3290.384,-3882.75,294.6607,0,0,0,100,0),
(@PATH,33,3291.66,-3875.24,294.662,0,0,0,100,0),
(@PATH,34,3295.71,-3868.95,294.662,0,0,0,100,0),
(@PATH,35,3302.22,-3864.56,294.662,0,0,0,100,0),
(@PATH,36,3310.01,-3862.94,294.662,0,0,0,100,0);

-- Pathing for Venom Stalker Entry: 15976
SET @NPC := 127863; -- 127862 should be in formation with him
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3252.581,`position_y`=-3730.202,`position_z`=279.2595 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3234.624,-3733.446,282.4044,0,0,0,100,0),
(@PATH,2,3234.132,-3743.128,280.9408,0,0,0,100,0),
(@PATH,3,3247.629,-3762.814,277.5423,0,0,0,100,0),
(@PATH,4,3232.144,-3779.076,273.1304,0,0,0,100,0),
(@PATH,5,3247.629,-3762.814,277.5423,0,0,0,100,0),
(@PATH,6,3234.124,-3743.281,280.9517,0,0,0,100,0),
(@PATH,7,3234.624,-3733.446,282.4044,0,0,0,100,0),
(@PATH,8,3252.519,-3730.217,279.2638,0,0,0,100,0),
(@PATH,9,3276.249,-3724.284,275.8947,0,0,0,100,0),
(@PATH,10,3309.417,-3714.943,266.8448,0,0,0,100,0),
(@PATH,11,3322.029,-3700.557,262.8869,0,0,0,100,0),
(@PATH,12,3298.23,-3700.239,271.5263,0,0,0,100,0),
(@PATH,13,3280.485,-3698.461,278.4746,0,0,0,100,0),
(@PATH,14,3298.23,-3700.239,271.5263,0,0,0,100,0),
(@PATH,15,3321.937,-3700.525,262.8836,0,0,0,100,0),
(@PATH,16,3309.417,-3714.943,266.8448,0,0,0,100,0),
(@PATH,17,3276.249,-3724.284,275.8947,0,0,0,100,0),
(@PATH,18,3252.581,-3730.202,279.2595,0,0,0,100,0);

-- Pathing for Noth the Plaguebringer Entry: 15954
SET @NPC := 127801;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2671.649,`position_y`=-3489.11,`position_z`=261.3754 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2666.34,-3502.596,261.2903,0,0,0,100,0),
(@PATH,2,2670.345,-3514.169,261.2776,0,0,0,100,0),
(@PATH,3,2676.189,-3520.29,261.2623,0,0,0,100,0),
(@PATH,4,2670.345,-3514.169,261.2776,0,0,0,100,0),
(@PATH,5,2666.34,-3502.596,261.2903,0,0,0,100,0),
(@PATH,6,2671.649,-3489.11,261.3754,0,0,0,100,0),
(@PATH,7,2676.566,-3484.499,261.3998,0,0,0,100,0),
(@PATH,8,2671.649,-3489.11,261.3754,0,0,0,100,0);

-- Pathing for Grobbulus Entry: 15931
SET @NPC := 127781;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3227.579,`position_y`=-3378.296,`position_z`=311.3255 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3228.724,-3363.874,304.4799,0,0,0,100,0),
(@PATH,2,3228.579,-3342.257,293.1313,0,0,0,100,0),
(@PATH,3,3228.15,-3327.913,292.5951,0,0,0,100,0),
(@PATH,4,3232.389,-3309.209,292.5951,0,0,0,100,0),
(@PATH,5,3252.036,-3310.178,292.5951,0,0,0,100,0),
(@PATH,6,3249.856,-3309.415,292.5951,60000,0,0,100,0),
(@PATH,7,3230.975,-3315.273,292.5951,0,0,0,100,0),
(@PATH,8,3229.008,-3330.244,292.5951,0,0,0,100,0),
(@PATH,9,3228.291,-3352.366,298.4386,0,0,0,100,0),
(@PATH,10,3228.85,-3367.867,306.5768,0,0,0,100,0),
(@PATH,11,3229.231,-3377.598,311.3294,0,0,0,100,0),
(@PATH,12,3222.958,-3389.251,311.3295,0,0,0,100,0),
(@PATH,13,3211.568,-3389.394,311.3405,0,0,0,100,0),
(@PATH,14,3205.059,-3380.847,311.3312,0,0,0,100,0),
(@PATH,15,3205.269,-3368.451,313.6086,0,0,0,100,0),
(@PATH,16,3205.238,-3346.578,318.9844,0,0,0,100,0),
(@PATH,17,3209.54,-3326.247,320.3741,0,0,0,100,0),
(@PATH,18,3209.07,-3314,320.337,0,0,0,100,0),
(@PATH,19,3200.387,-3306.898,320.325,0,0,0,100,0),
(@PATH,20,3186.123,-3306.752,320.2604,0,0,0,100,0),
(@PATH,21,3174.501,-3306.841,319.6423,60000,0,0,100,0),
(@PATH,22,3188.372,-3305.996,320.2764,0,0,0,100,0),
(@PATH,23,3201.267,-3305.621,320.3262,0,0,0,100,0),
(@PATH,24,3208.785,-3314.216,320.3366,0,0,0,100,0),
(@PATH,25,3211.18,-3328.448,320.3932,0,0,0,100,0),
(@PATH,26,3203.891,-3342.488,320.0162,0,0,0,100,0),
(@PATH,27,3204.194,-3365.331,314.3783,0,0,0,100,0),
(@PATH,28,3204.95,-3382.075,311.3327,0,0,0,100,0),
(@PATH,29,3211.571,-3388.579,311.3394,0,0,0,100,0),
(@PATH,30,3227.579,-3378.296,311.3255,0,0,0,100,0);

-- Pathing for Plague Beast Entry: 16034
SET @NPC := 128177;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2727.223,`position_y`=-3594.056,`position_z`=258.8858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2723.637,-3604.718,259.6959,0,0,0,100,0),
(@PATH,2,2720.893,-3620.152,260.07,0,0,0,100,0),
(@PATH,3,2723.637,-3604.718,259.6959,0,0,0,100,0),
(@PATH,4,2727.223,-3594.056,258.8858,0,0,0,100,0),
(@PATH,5,2736.519,-3591.672,257.9183,0,0,0,100,0),
(@PATH,6,2743.838,-3597.846,257.6706,0,0,0,100,0),
(@PATH,7,2752.585,-3595.404,257.0601,0,0,0,100,0),
(@PATH,8,2755.268,-3585.129,256.3048,0,0,0,100,0),
(@PATH,9,2757.008,-3575.477,255.6362,0,0,0,100,0),
(@PATH,10,2755.268,-3585.129,256.3048,0,0,0,100,0),
(@PATH,11,2752.585,-3595.404,257.0601,0,0,0,100,0),
(@PATH,12,2743.837,-3597.847,257.6707,0,0,0,100,0),
(@PATH,13,2736.519,-3591.672,257.9183,0,0,0,100,0),
(@PATH,14,2727.223,-3594.056,258.8858,0,0,0,100,0);

-- Pathing for Plague Beast Entry: 16034
SET @NPC := 128178;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2847.407,`position_y`=-3611.501,`position_z`=261.8609 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2857.005,-3599.331,263.6793,0,0,0,100,0),
(@PATH,2,2873.124,-3590.235,267.1259,0,0,0,100,0),
(@PATH,3,2887.852,-3592.763,270.6516,0,0,0,100,0),
(@PATH,4,2897.192,-3605.39,273.3059,0,0,0,100,0),
(@PATH,5,2899.383,-3619.342,275.0363,0,0,0,100,0),
(@PATH,6,2891.756,-3631.639,274.1991,0,0,0,100,0),
(@PATH,7,2879.466,-3638.177,273.2885,0,0,0,100,0),
(@PATH,8,2866.484,-3640.015,271.3249,0,0,0,100,0),
(@PATH,9,2879.466,-3638.177,273.2885,0,0,0,100,0),
(@PATH,10,2891.756,-3631.639,274.1991,0,0,0,100,0),
(@PATH,11,2899.383,-3619.342,275.0363,0,0,0,100,0),
(@PATH,12,2897.192,-3605.39,273.3059,0,0,0,100,0),
(@PATH,13,2887.852,-3592.763,270.6516,0,0,0,100,0),
(@PATH,14,2873.124,-3590.235,267.1259,0,0,0,100,0),
(@PATH,15,2857.005,-3599.331,263.6793,0,0,0,100,0),
(@PATH,16,2847.407,-3611.501,261.8609,0,0,0,100,0);

-- Pathing for Plague Beast Entry: 16034
SET @NPC := 128179;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2777.605,`position_y`=-3575.896,`position_z`=253.7501 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2790.739,-3564.992,251.512,0,0,0,100,0),
(@PATH,2,2806.231,-3568.648,252.5588,0,0,0,100,0),
(@PATH,3,2817.801,-3583.097,254.5759,0,0,0,100,0),
(@PATH,4,2822.715,-3595.134,257.7653,0,0,0,100,0),
(@PATH,5,2829.62,-3612.201,259.9153,0,0,0,100,0),
(@PATH,6,2822.715,-3595.134,257.7653,0,0,0,100,0),
(@PATH,7,2817.801,-3583.097,254.5759,0,0,0,100,0),
(@PATH,8,2806.231,-3568.648,252.5588,0,0,0,100,0),
(@PATH,9,2790.979,-3565.049,251.5594,0,0,0,100,0),
(@PATH,10,2777.605,-3575.896,253.7501,0,0,0,100,0),
(@PATH,11,2767.949,-3589.933,256.7042,0,0,0,100,0),
(@PATH,12,2777.605,-3575.896,253.7501,0,0,0,100,0);

-- Pathing for Plague Beast Entry: 16034
SET @NPC := 128183;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2897.484,`position_y`=-3671.875,`position_z`=280.3942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2900.623,-3683.831,284.0013,0,0,0,100,0),
(@PATH,2,2894.853,-3698.01,285.4735,0,0,0,100,0),
(@PATH,3,2881.999,-3708.828,285.7333,0,0,0,100,0),
(@PATH,4,2865.732,-3705.732,284.1666,0,0,0,100,0),
(@PATH,5,2858.935,-3691.243,281.1445,0,0,0,100,0),
(@PATH,6,2846.578,-3686.145,278.5287,0,0,0,100,0),
(@PATH,7,2827.884,-3686.887,275.8904,0,0,0,100,0),
(@PATH,8,2846.578,-3686.145,278.5287,0,0,0,100,0),
(@PATH,9,2858.935,-3691.243,281.1445,0,0,0,100,0),
(@PATH,10,2865.732,-3705.732,284.1666,0,0,0,100,0),
(@PATH,11,2881.999,-3708.828,285.7333,0,0,0,100,0),
(@PATH,12,2894.65,-3698.181,285.4753,0,0,0,100,0),
(@PATH,13,2900.623,-3683.831,284.0013,0,0,0,100,0),
(@PATH,14,2897.484,-3671.875,280.3942,0,0,0,100,0),
(@PATH,15,2884.267,-3662.161,277.4121,0,0,0,100,0),
(@PATH,16,2867.519,-3655.968,274.4418,0,0,0,100,0),
(@PATH,17,2884.267,-3662.161,277.4121,0,0,0,100,0),
(@PATH,18,2897.484,-3671.875,280.3942,0,0,0,100,0);

-- Pathing for Bile Retcher Entry: 16018
SET @NPC := 128082;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3042.894,`position_y`=-3210.451,`position_z`=293.3452 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3045.409,-3229.587,293.3453,0,0,0,100,0),
(@PATH,2,3042.894,-3210.451,293.3452,0,0,0,100,0),
(@PATH,3,3044.73,-3193.168,293.345,0,0,0,100,0),
(@PATH,4,3050.198,-3175.146,293.3451,0,0,0,100,0),
(@PATH,5,3057.628,-3160.267,293.3452,0,0,0,100,0),
(@PATH,6,3070.946,-3144.958,293.3451,0,0,0,100,0),
(@PATH,7,3085.224,-3133.8,293.3451,0,0,0,100,0),
(@PATH,8,3100.719,-3125.13,293.3454,0,0,0,100,0),
(@PATH,9,3115.583,-3120.971,293.3454,0,0,0,100,0),
(@PATH,10,3123.499,-3119.894,293.3453,0,0,0,100,0),
(@PATH,11,3115.583,-3120.971,293.3454,0,0,0,100,0),
(@PATH,12,3100.719,-3125.13,293.3454,0,0,0,100,0),
(@PATH,13,3085.224,-3133.8,293.3451,0,0,0,100,0),
(@PATH,14,3070.946,-3144.958,293.3451,0,0,0,100,0),
(@PATH,15,3057.628,-3160.267,293.3452,0,0,0,100,0),
(@PATH,16,3050.198,-3175.146,293.3451,0,0,0,100,0),
(@PATH,17,3044.73,-3193.168,293.345,0,0,0,100,0),
(@PATH,18,3042.894,-3210.451,293.3452,0,0,0,100,0);

-- Pathing for Bile Retcher Entry: 16018
SET @NPC := 128080;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3033.41,`position_y`=-3103.28,`position_z`=294.0816 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3042.117,-3111.578,294.0787,0,0,0,100,0),
(@PATH,2,3054.847,-3117.892,294.0732,0,0,0,100,0),
(@PATH,3,3064.48,-3116.37,294.0733,0,0,0,100,0),
(@PATH,4,3071.523,-3110.154,294.0739,0,0,0,100,0),
(@PATH,5,3073.239,-3096.89,294.0799,0,0,0,100,0),
(@PATH,6,3070.978,-3083.671,294.0771,0,0,0,100,0),
(@PATH,7,3069.906,-3072.977,294.0717,0,0,0,100,0),
(@PATH,8,3070.978,-3083.671,294.0771,0,0,0,100,0),
(@PATH,9,3073.239,-3096.89,294.0799,0,0,0,100,0),
(@PATH,10,3071.523,-3110.154,294.0739,0,0,0,100,0),
(@PATH,11,3064.48,-3116.37,294.0733,0,0,0,100,0),
(@PATH,12,3054.985,-3117.871,294.0741,0,0,0,100,0),
(@PATH,13,3042.117,-3111.578,294.0787,0,0,0,100,0),
(@PATH,14,3033.41,-3103.28,294.0816,0,0,0,100,0);

-- Pathing for Bile Retcher Entry: 16018
SET @NPC := 128077;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3142.82,`position_y`=-3289.663,`position_z`=293.6283 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3133.79,-3280.204,293.6283,0,0,0,100,0),
(@PATH,2,3124.373,-3283.016,293.6283,0,0,0,100,0),
(@PATH,3,3115.834,-3292.965,293.6283,0,0,0,100,0),
(@PATH,4,3107.542,-3301.675,293.6283,0,0,0,100,0),
(@PATH,5,3100.092,-3309.104,293.6283,0,0,0,100,0),
(@PATH,6,3096.534,-3315.12,293.6284,0,0,0,100,0),
(@PATH,7,3098.168,-3321.916,293.6283,0,0,0,100,0),
(@PATH,8,3105.722,-3329.35,293.6283,0,0,0,100,0),
(@PATH,9,3096.036,-3342.595,294.4876,0,0,0,100,0),
(@PATH,10,3089.529,-3352.048,299.1511,0,0,0,100,0),
(@PATH,11,3080.938,-3360.322,298.3178,0,0,0,100,0),
(@PATH,12,3090.223,-3352.669,299.1137,0,0,0,100,0),
(@PATH,13,3098.557,-3345.29,294.5518,0,0,0,100,0),
(@PATH,14,3110.563,-3333.553,293.6283,0,0,0,100,0),
(@PATH,15,3119.627,-3342.392,293.6283,0,0,0,100,0),
(@PATH,16,3126.197,-3344.948,293.6283,0,0,0,100,0),
(@PATH,17,3132.594,-3340.744,293.6283,0,0,0,100,0),
(@PATH,18,3139.652,-3333.695,293.6254,0,0,0,100,0),
(@PATH,19,3147.054,-3325.681,293.6215,0,0,0,100,0),
(@PATH,20,3156.757,-3316.759,293.6283,0,0,0,100,0),
(@PATH,21,3159.579,-3307.466,293.6283,0,0,0,100,0),
(@PATH,22,3151.304,-3298.503,293.6283,0,0,0,100,0),
(@PATH,23,3142.82,-3289.663,293.6283,0,0,0,100,0);

-- Pathing for Bile Retcher Entry: 16018
SET @NPC := 128083;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3014.116,`position_y`=-3151.28,`position_z`=294.0802 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3006.086,-3148.801,294.0794,0,0,0,100,0),
(@PATH,2,2998.345,-3143.183,294.0745,0,0,0,100,0),
(@PATH,3,3006.086,-3148.801,294.0794,0,0,0,100,0),
(@PATH,4,3014.116,-3151.28,294.0802,0,0,0,100,0),
(@PATH,5,3021.593,-3152.803,294.0765,0,0,0,100,0),
(@PATH,6,3029.989,-3151.037,294.0749,0,0,0,100,0),
(@PATH,7,3035.378,-3146.691,294.0736,0,0,0,100,0),
(@PATH,8,3037.918,-3141.474,294.0722,0,0,0,100,0),
(@PATH,9,3037.771,-3135.391,294.0739,0,0,0,100,0),
(@PATH,10,3032.81,-3126.448,294.0777,0,0,0,100,0),
(@PATH,11,3027.861,-3119.256,294.0811,0,0,0,100,0),
(@PATH,12,3023.261,-3113.858,294.0814,0,0,0,100,0),
(@PATH,13,3027.861,-3119.256,294.0811,0,0,0,100,0),
(@PATH,14,3032.81,-3126.448,294.0777,0,0,0,100,0),
(@PATH,15,3037.771,-3135.391,294.0739,0,0,0,100,0),
(@PATH,16,3037.918,-3141.474,294.0722,0,0,0,100,0),
(@PATH,17,3035.378,-3146.691,294.0736,0,0,0,100,0),
(@PATH,18,3029.989,-3151.037,294.0749,0,0,0,100,0),
(@PATH,19,3021.593,-3152.803,294.0765,0,0,0,100,0),
(@PATH,20,3014.116,-3151.28,294.0802,0,0,0,100,0);

-- Pathing for Patchwerk Entry: 16028 Goodbye YTDB waypoints :)
SET @NPC := 128135;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3256.364,`position_y`=-3230.328,`position_z`=294.0628 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3294.435,-3232.726,294.0628,0,0,0,100,0),
(@PATH,2,3259.98,-3230.881,294.0628,0,0,0,100,0),
(@PATH,3,3239.911,-3221.095,294.0628,0,0,0,100,0),
(@PATH,4,3217.512,-3195.807,294.0628,0,0,0,100,0),
(@PATH,5,3191.55,-3171.159,294.0628,0,0,0,100,0),
(@PATH,6,3163.729,-3148.403,294.0628,0,0,0,100,0),
(@PATH,7,3135.152,-3140.675,294.0628,0,0,0,100,0),
(@PATH,8,3102.748,-3145.538,294.0628,0,0,0,100,0),
(@PATH,9,3132.792,-3139.218,294.0628,0,0,0,100,0),
(@PATH,10,3158.633,-3145.425,294.0628,0,0,0,100,0),
(@PATH,11,3183.093,-3161.458,294.0628,0,0,0,100,0),
(@PATH,12,3207.656,-3187.538,294.0628,0,0,0,100,0),
(@PATH,13,3231.767,-3210.727,294.0628,0,0,0,100,0),
(@PATH,14,3256.364,-3230.328,294.0628,0,0,0,100,0);

-- Pathing for Sludge Belcher Entry: 16029
SET @NPC := 128136;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3118.057,`position_y`=-3238.513,`position_z`=294.0628 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3110.502,-3233.311,294.0628,0,0,0,100,0),
(@PATH,2,3104.615,-3222.995,294.062,0,0,0,100,0),
(@PATH,3,3102.009,-3217.843,294.0619,0,0,0,100,0),
(@PATH,4,3088.782,-3219.72,294.2053,0,0,0,100,0),
(@PATH,5,3062.66,-3225.544,294.0628,0,0,0,100,0),
(@PATH,6,3088.782,-3219.72,294.2053,0,0,0,100,0),
(@PATH,7,3102.009,-3217.843,294.0619,0,0,0,100,0),
(@PATH,8,3104.615,-3222.995,294.062,0,0,0,100,0),
(@PATH,9,3110.502,-3233.311,294.0628,0,0,0,100,0),
(@PATH,10,3118.057,-3238.513,294.0628,0,0,0,100,0),
(@PATH,11,3132.468,-3243.824,294.0882,0,0,0,100,0),
(@PATH,12,3132.824,-3258.017,294.5639,0,0,0,100,0),
(@PATH,13,3134.089,-3269.027,294.4024,0,0,0,100,0),
(@PATH,14,3145.958,-3276.273,294.7125,0,0,0,100,0),
(@PATH,15,3159.74,-3284.686,294.9083,0,0,0,100,0),
(@PATH,16,3165.632,-3293.163,294.7399,0,0,0,100,0),
(@PATH,17,3170.729,-3299.799,294.5983,0,0,0,100,0),
(@PATH,18,3176.233,-3307.651,294.5355,0,0,0,100,0),
(@PATH,19,3174.618,-3318.042,294.5306,0,0,0,100,0),
(@PATH,20,3165.177,-3325.201,294.523,0,0,0,100,0),
(@PATH,21,3174.617,-3318.042,294.5306,0,0,0,100,0),
(@PATH,22,3176.233,-3307.651,294.5355,0,0,0,100,0),
(@PATH,23,3170.73,-3299.8,294.5983,0,0,0,100,0),
(@PATH,24,3165.632,-3293.163,294.7399,0,0,0,100,0),
(@PATH,25,3159.74,-3284.686,294.9083,0,0,0,100,0),
(@PATH,26,3145.958,-3276.273,294.7125,0,0,0,100,0),
(@PATH,27,3134.089,-3269.027,294.4024,0,0,0,100,0),
(@PATH,28,3132.824,-3258.017,294.5639,0,0,0,100,0),
(@PATH,29,3132.468,-3243.824,294.0882,0,0,0,100,0),
(@PATH,30,3118.057,-3238.513,294.0628,0,0,0,100,0);

-- Pathing for Sludge Belcher Entry: 16029
SET @NPC := 97736;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=16029,`modelid`=0,`map`=533,`spawnMask`=3,`spawndist`=0,`MovementType`=2,`position_x`=2992.316,`position_y`=-3175.448,`position_z`=294.0716 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2985.661,-3189.97,294.0675,0,0,0,100,0),
(@PATH,2,2992.316,-3175.448,294.0716,0,0,0,100,0),
(@PATH,3,2998.143,-3166.825,294.0744,0,0,0,100,0),
(@PATH,4,3007.454,-3161.701,294.0769,0,0,0,100,0),
(@PATH,5,3021.642,-3159.072,294.0751,0,0,0,100,0),
(@PATH,6,3033.026,-3156.022,294.0723,0,0,0,100,0),
(@PATH,7,3047.169,-3147.989,294.0677,0,0,0,100,0),
(@PATH,8,3061.901,-3133.495,294.0666,0,0,0,100,0),
(@PATH,9,3075.713,-3122.531,294.0668,0,0,0,100,0),
(@PATH,10,3088.894,-3113.645,294.0691,0,0,0,100,0),
(@PATH,11,3102.977,-3108.005,294.0687,0,0,0,100,0),
(@PATH,12,3115.019,-3104.743,294.0686,0,0,0,100,0),
(@PATH,13,3102.98,-3108.004,294.0687,0,0,0,100,0),
(@PATH,14,3088.894,-3113.645,294.0691,0,0,0,100,0),
(@PATH,15,3075.713,-3122.531,294.0668,0,0,0,100,0),
(@PATH,16,3061.901,-3133.495,294.0666,0,0,0,100,0),
(@PATH,17,3047.169,-3147.989,294.0677,0,0,0,100,0),
(@PATH,18,3033.026,-3156.022,294.0723,0,0,0,100,0),
(@PATH,19,3021.642,-3159.072,294.0751,0,0,0,100,0),
(@PATH,20,3007.454,-3161.701,294.0769,0,0,0,100,0),
(@PATH,21,2998.143,-3166.825,294.0744,0,0,0,100,0),
(@PATH,22,2992.316,-3175.448,294.0716,0,0,0,100,0);

-- Pathing for Sludge Belcher Entry: 16029
SET @NPC := 97718;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=16029,`modelid`=0,`map`=533,`spawnMask`=3,`spawndist`=0,`MovementType`=2,`position_x`=3008.161,`position_y`=-3239.027,`position_z`=294.0628 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3012.525,-3243.854,294.0628,0,0,0,100,0),
(@PATH,2,3022.682,-3242.966,294.0628,0,0,0,100,0),
(@PATH,3,3028.833,-3236.661,294.0628,0,0,0,100,0),
(@PATH,4,3032.736,-3219.687,294.0628,0,0,0,100,0),
(@PATH,5,3028.816,-3207.798,294.0628,0,0,0,100,0),
(@PATH,6,3021.306,-3202.189,294.0628,0,0,0,100,0),
(@PATH,7,3006.159,-3199.062,294.0689,0,0,0,100,0),
(@PATH,8,2991.62,-3203.322,294.0628,0,0,0,100,0),
(@PATH,9,2985.41,-3218.486,294.0628,0,0,0,100,0),
(@PATH,10,2988.189,-3227.132,294.0628,0,0,0,100,0),
(@PATH,11,3001.484,-3232.543,294.0628,0,0,0,100,0),
(@PATH,12,3008.161,-3239.027,294.0628,0,0,0,100,0);

-- Pathing for Sludge Belcher Entry: 16029
SET @NPC := 97724;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=16029,`modelid`=0,`map`=533,`spawnMask`=3,`spawndist`=0,`MovementType`=2,`position_x`=3103.862,`position_y`=-3199.295,`position_z`=294.0628 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3110.057,-3189.071,294.0628,0,0,0,100,0),
(@PATH,2,3117.292,-3183.439,294.0628,0,0,0,100,0),
(@PATH,3,3124.222,-3180.931,294.0628,0,0,0,100,0),
(@PATH,4,3134.678,-3179.746,294.0628,0,0,0,100,0),
(@PATH,5,3147.699,-3183.069,294.0628,0,0,0,100,0),
(@PATH,6,3156.941,-3191.08,294.0628,0,0,0,100,0),
(@PATH,7,3163.032,-3198.683,294.0628,0,0,0,100,0),
(@PATH,8,3165.123,-3211.401,294.0628,0,0,0,100,0),
(@PATH,9,3162.973,-3223.654,294.0628,0,0,0,100,0),
(@PATH,10,3155.372,-3234.195,294.0628,0,0,0,100,0),
(@PATH,11,3146.969,-3240.264,294.0867,0,0,0,100,0),
(@PATH,12,3138.718,-3243.327,294.088,0,0,0,100,0),
(@PATH,13,3146.969,-3240.264,294.0867,0,0,0,100,0),
(@PATH,14,3155.372,-3234.195,294.0628,0,0,0,100,0),
(@PATH,15,3162.97,-3223.67,294.0628,0,0,0,100,0),
(@PATH,16,3165.123,-3211.401,294.0628,0,0,0,100,0),
(@PATH,17,3163.032,-3198.683,294.0628,0,0,0,100,0),
(@PATH,18,3156.941,-3191.08,294.0628,0,0,0,100,0),
(@PATH,19,3147.699,-3183.069,294.0628,0,0,0,100,0),
(@PATH,20,3134.678,-3179.746,294.0628,0,0,0,100,0),
(@PATH,21,3124.222,-3180.931,294.0628,0,0,0,100,0),
(@PATH,22,3117.292,-3183.439,294.0628,0,0,0,100,0),
(@PATH,23,3110.057,-3189.071,294.0628,0,0,0,100,0),
(@PATH,24,3103.862,-3199.295,294.0628,0,0,0,100,0),
(@PATH,25,3102.404,-3208.719,294.0627,0,0,0,100,0),
(@PATH,26,3103.862,-3199.295,294.0628,0,0,0,100,0);

-- Pathing for Sludge Belcher Entry: 16029
SET @NPC := 97747;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=16029,`modelid`=0,`map`=533,`spawnMask`=3,`spawndist`=0,`MovementType`=2,`position_x`=3112.745,`position_y`=-3093.264,`position_z`=294.0749 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3119.318,-3086.976,294.0759,0,0,0,100,0),
(@PATH,2,3126.585,-3076.191,294.0714,0,0,0,100,0),
(@PATH,3,3119.318,-3086.976,294.0759,0,0,0,100,0),
(@PATH,4,3112.745,-3093.264,294.0749,0,0,0,100,0),
(@PATH,5,3103.091,-3093.424,294.076,0,0,0,100,0),
(@PATH,6,3096.566,-3090.718,294.0785,0,0,0,100,0),
(@PATH,7,3089.514,-3081.602,294.08,0,0,0,100,0),
(@PATH,8,3086.157,-3071.268,294.0743,0,0,0,100,0),
(@PATH,9,3089.514,-3081.602,294.08,0,0,0,100,0),
(@PATH,10,3096.566,-3090.718,294.0785,0,0,0,100,0),
(@PATH,11,3103.091,-3093.424,294.076,0,0,0,100,0),
(@PATH,12,3112.745,-3093.264,294.0749,0,0,0,100,0);

-- Set random movement to Embalming Slime, Patchwork Golem, Maggot, Frenzied Bat, Plagued Bat, Diseased Maggot, Rotting Maggot, Larva Entry, Risen Squire
UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `id` IN (16017,16024,16030,16036,16037,16056,16057,16068,16154);

-- Pathing for Death Knight Cavalier Entry: 16163
SET @NPC := 127752;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2827.984,`position_y`=-3152.95,`position_z`=273.787 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2827.984,`position_y`=-3152.95,`position_z`=273.787 WHERE `guid`=127751;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,25278, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2828.418,-3128.86,273.8279,0,0,0,100,0),
(@PATH,2,2828.67,-3097.49,273.8293,0,0,0,100,0),
(@PATH,3,2824.122,-3127.451,273.8248,0,0,0,100,0),
(@PATH,4,2813.568,-3143.734,273.7569,0,0,0,100,0),
(@PATH,5,2801.097,-3163.161,273.7858,0,0,0,100,0),
(@PATH,6,2799.644,-3189.22,273.787,0,0,0,100,0),
(@PATH,7,2820.002,-3202.299,273.8145,0,0,0,100,0),
(@PATH,8,2844.853,-3200.758,273.787,0,0,0,100,0),
(@PATH,9,2848.53,-3180.427,273.787,0,0,0,100,0),
(@PATH,10,2827.984,-3152.95,273.787,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=127752;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(127752,127752,5,90,2),
(127752,127751,5,90,2);

-- Pathing for Death Knight Cavalier Entry: 16163
SET @NPC := 127745;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2709.55,`position_y`=-3013.26,`position_z`=240.524 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2709.55,`position_y`=-3013.26,`position_z`=240.524 WHERE `guid`=127744;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,25278, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2724.357,-3002.94,240.5246,0,0,0,100,0),
(@PATH,2,2734.208,-2991.862,240.525,0,0,0,100,0),
(@PATH,3,2744.237,-2985.519,240.5257,0,0,0,100,0),
(@PATH,4,2763.189,-2986.039,240.5255,0,0,0,100,0),
(@PATH,5,2781.199,-2986.169,240.5265,0,0,0,100,0),
(@PATH,6,2791.35,-2986.05,240.528,0,0,0,100,0),
(@PATH,7,2811.443,-2985.972,250.953,0,0,0,100,0),
(@PATH,8,2830.531,-2985.851,260.8194,0,0,0,100,0),
(@PATH,9,2847.362,-2985.841,267.593,0,0,0,100,0),
(@PATH,10,2870.534,-2986.177,267.5924,0,0,0,100,0),
(@PATH,11,2882.414,-2997.007,267.5921,0,0,0,100,0),
(@PATH,12,2895.966,-3012.106,267.5932,0,0,0,100,0),
(@PATH,13,2915.716,-3014.353,267.594,0,0,0,100,0),
(@PATH,14,2931.21,-3007.478,267.5924,0,0,0,100,0),
(@PATH,15,2938.199,-2994.229,267.5921,0,0,0,100,0),
(@PATH,16,2937.735,-2977.154,267.5934,0,0,0,100,0),
(@PATH,17,2916.35,-2957.36,267.592,0,0,0,100,0),
(@PATH,18,2904.34,-2957.15,267.592,0,0,0,100,0),
(@PATH,19,2892.14,-2962.4,267.592,0,0,0,100,0),
(@PATH,20,2884.039,-2971.864,267.5926,0,0,0,100,0),
(@PATH,21,2870.617,-2985.568,267.5924,0,0,0,100,0),
(@PATH,22,2847.519,-2985.616,267.593,0,0,0,100,0),
(@PATH,23,2831.011,-2985.781,260.82,0,0,0,100,0),
(@PATH,24,2811.443,-2985.972,250.953,0,0,0,100,0),
(@PATH,25,2791.35,-2986.05,240.528,0,0,0,100,0),
(@PATH,26,2781.199,-2986.169,240.5265,0,0,0,100,0),
(@PATH,27,2763.189,-2986.039,240.5255,0,0,0,100,0),
(@PATH,28,2744.237,-2985.519,240.5257,0,0,0,100,0),
(@PATH,29,2734.137,-2977.427,240.5255,0,0,0,100,0),
(@PATH,30,2722.754,-2967.005,240.5243,0,0,0,100,0),
(@PATH,31,2708.031,-2957.228,240.5254,0,0,0,100,0),
(@PATH,32,2691.098,-2957.404,240.5251,0,0,0,100,0),
(@PATH,33,2676.669,-2966.855,240.5253,0,0,0,100,0),
(@PATH,34,2671.321,-2976.635,240.5246,0,0,0,100,0),
(@PATH,35,2671.421,-2993.49,240.5249,0,0,0,100,0),
(@PATH,36,2680.976,-3008.883,240.5253,0,0,0,100,0),
(@PATH,37,2696.83,-3014.89,240.524,0,0,0,100,0),
(@PATH,38,2709.55,-3013.26,240.524,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=127745;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(127745,127745,5,90,2),
(127745,127744,5,90,2);

-- Pathing for Death Knight Cavalier Entry: 16163
SET @NPC := 127743;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2787.864,`position_y`=-3320.589,`position_z`=267.6845 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=2787.864,`position_y`=-3320.589,`position_z`=267.6845 WHERE `guid`=127742;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,25278, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2787.931,-3363.628,267.6847,0,0,0,100,0),
(@PATH,2,2787.864,-3320.606,267.6845,0,0,0,100,0),
(@PATH,3,2787.388,-3287.191,267.6845,0,0,0,100,0),
(@PATH,4,2787.864,-3320.589,267.6845,0,0,0,100,0);
-- F1303F2316ADF300 .go 2787.931 -3363.628 267.6847

DELETE FROM `creature_formations` WHERE `leaderGUID`=127743;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(127743,127743,5,90,2),
(127743,127742,5,90,2);

-- Pathing for Death Knight Cavalier Entry: 16163
SET @NPC := 127754;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2911.993,`position_y`=-3204.611,`position_z`=273.3833 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2911.993,`position_y`=-3204.611,`position_z`=273.3833 WHERE `guid`=127753;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,25278, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2926.023,-3200.403,273.4004,0,0,0,100,0),
(@PATH,2,2931.457,-3188.328,273.3847,0,0,0,100,0),
(@PATH,3,2925.778,-3167.298,273.787,0,0,0,100,0),
(@PATH,4,2907.542,-3166.655,273.787,0,0,0,100,0),
(@PATH,5,2873.219,-3165.419,273.787,0,0,0,100,0),
(@PATH,6,2861.632,-3165.088,273.787,0,0,0,100,0),
(@PATH,7,2860.526,-3185.717,273.787,0,0,0,100,0),
(@PATH,8,2860.435,-3203.401,273.787,0,0,0,100,0),
(@PATH,9,2875.204,-3203.906,273.4075,0,0,0,100,0),
(@PATH,10,2892.834,-3204.38,273.3951,0,0,0,100,0),
(@PATH,11,2911.993,-3204.611,273.3833,0,0,0,100,0);
-- F1303F2317A7F300 .go 2926.023 -3200.403 273.4004
DELETE FROM `creature_formations` WHERE `leaderGUID`=127754;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(127754,127754,5,90,2),
(127754,127753,5,90,2);

-- Pathing for Shade of Naxxramas Entry: 16164
SET @NPC := 127756;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2892.747,`position_y`=-3294.521,`position_z`=298.1457 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2881.74,-3294.004,298.1457,0,0,0,100,0),
(@PATH,2,2870.605,-3303.931,298.1457,0,0,0,100,0),
(@PATH,3,2867.386,-3319,298.1457,0,0,0,100,0),
(@PATH,4,2863.142,-3340.528,298.1457,0,0,0,100,0),
(@PATH,5,2867.386,-3319,298.1457,0,0,0,100,0),
(@PATH,6,2870.605,-3303.931,298.1457,0,0,0,100,0),
(@PATH,7,2881.74,-3294.004,298.1457,0,0,0,100,0),
(@PATH,8,2892.747,-3294.521,298.1457,0,0,0,100,0),
(@PATH,9,2915.861,-3295.495,298.547,0,0,0,100,0),
(@PATH,10,2892.747,-3294.521,298.1457,0,0,0,100,0);

-- Pathing for Bony Construct Entry: 16167
SET @NPC := 127764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2845.056,`position_y`=-3296.362,`position_z`=298.1237 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2847.821,-3308.784,298.1465,0,0,0,100,0),
(@PATH,2,2838.797,-3321.935,298.1519,0,0,0,100,0),
(@PATH,3,2847.821,-3308.784,298.1465,0,0,0,100,0),
(@PATH,4,2845.056,-3296.362,298.1237,0,0,0,100,0),
(@PATH,5,2832.532,-3295.221,298.1501,0,0,0,100,0),
(@PATH,6,2845.056,-3296.362,298.1237,0,0,0,100,0);

-- Pathing for Bony Construct Entry: 16167
SET @NPC := 127767;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2835.764,`position_y`=-3331.32,`position_z`=299.3642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2830.406,-3329.089,304.8374,0,0,0,100,0),
(@PATH,2,2835.764,-3331.32,299.3642,0,0,0,100,0),
(@PATH,3,2842.907,-3323.556,298.1545,0,0,0,100,0),
(@PATH,4,2852.525,-3333.609,298.1457,0,0,0,100,0),
(@PATH,5,2854.874,-3350.62,298.1457,0,0,0,100,0),
(@PATH,6,2852.525,-3333.609,298.1457,0,0,0,100,0),
(@PATH,7,2842.907,-3323.556,298.1545,0,0,0,100,0),
(@PATH,8,2835.764,-3331.32,299.3642,0,0,0,100,0);

-- Pathing for Stoneskin Gargoyle Entry: 16168
SET @NPC := 127775;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2854.793,`position_y`=-3489.831,`position_z`=297.8863 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2872.719,-3489.734,297.6203,0,0,0,100,0),
(@PATH,2,2855.09,-3489.832,297.8829,0,0,0,100,0),
(@PATH,3,2836.616,-3489.816,297.8643,0,0,0,100,0),
(@PATH,4,2809.425,-3490.459,285.9723,0,0,0,100,0),
(@PATH,5,2775.243,-3489.796,274.0275,0,0,0,100,0),
(@PATH,6,2728.599,-3490.62,262.1311,0,0,0,100,0),
(@PATH,7,2775.243,-3489.796,274.0275,0,0,0,100,0),
(@PATH,8,2809.425,-3490.459,285.9723,0,0,0,100,0),
(@PATH,9,2836.616,-3489.816,297.8643,0,0,0,100,0),
(@PATH,10,2854.793,-3489.831,297.8863,0,0,0,100,0);

-- Pathing for Stoneskin Gargoyle Entry: 16168
SET @NPC := 127772;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2864.621,`position_y`=-3468.973,`position_z`=297.8703 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2871.249,-3500.704,297.6192,0,0,0,100,0),
(@PATH,2,2888.541,-3522.788,297.6146,0,0,0,100,0),
(@PATH,3,2905.121,-3519.568,297.863,0,0,0,100,0),
(@PATH,4,2921.399,-3509.922,297.4822,0,0,0,100,0),
(@PATH,5,2944.054,-3494.677,297.6308,0,0,0,100,0),
(@PATH,6,2921.399,-3509.922,297.4822,0,0,0,100,0),
(@PATH,7,2905.121,-3519.568,297.863,0,0,0,100,0),
(@PATH,8,2888.541,-3522.788,297.6146,0,0,0,100,0),
(@PATH,9,2871.249,-3500.704,297.6192,0,0,0,100,0),
(@PATH,10,2864.621,-3468.973,297.8703,0,0,0,100,0);

-- Pathing for Skeletal Smith Entry: 16193
SET @NPC := 127791;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2882.137,`position_y`=-3275.976,`position_z`=298.1409 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2899.501,-3263.09,298.1457,0,0,0,100,0),
(@PATH,2,2899.086,-3280.568,298.547,0,0,0,100,0),
(@PATH,3,2902.461,-3288.92,298.547,0,0,0,100,0),
(@PATH,4,2889.017,-3298.332,298.1457,0,0,0,100,0),
(@PATH,5,2879.739,-3293.503,298.1457,0,0,0,100,0),
(@PATH,6,2882.137,-3275.976,298.1409,0,0,0,100,0);

-- Pathing for Skeletal Smith Entry: 16193
SET @NPC := 127792;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2910.939,`position_y`=-3290.127,`position_z`=298.547 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2902.236,-3293.143,298.547,0,0,0,100,0),
(@PATH,2,2899.265,-3299.745,298.1457,0,0,0,100,0),
(@PATH,3,2902.873,-3306.907,298.1457,0,0,0,100,0),
(@PATH,4,2911.011,-3309.07,298.1457,0,0,0,100,0),
(@PATH,5,2920.521,-3308.821,298.1457,0,0,0,100,0),
(@PATH,6,2920.324,-3301.099,298.547,0,0,0,100,0),
(@PATH,7,2915.13,-3296.642,298.547,0,0,0,100,0),
(@PATH,8,2910.939,-3290.127,298.547,0,0,0,100,0);
