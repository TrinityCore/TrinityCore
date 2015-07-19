-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (25760, 25622, 25615);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(25760, 0, 0, 0, 0, 45, NULL),
(25622, 0, 0, 0, 0, 173, NULL),
(25615, 0, 0, 0, 0, 0, '45797');

UPDATE `creature_addon` SET `emote`=36 WHERE  `guid`=102838;

UPDATE `creature` SET `spawndist`=9, `MovementType`=1 WHERE  `id` IN (26202, 25715, 25668, 25791, 25792);

UPDATE `creature` SET `spawndist`=9, `MovementType`=1 WHERE  `id` IN (26126);

UPDATE `creature` SET `spawndist`=13, `MovementType`=1 WHERE  `id` IN (25452, 25615);

UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=122669;

DELETE FROM `creature_formations` WHERE `leaderGUID`=111466;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(111466, 111466, 0, 0, 0, 0, 0),
(111466, 111467, 5, 10, 0, 0, 0);

-- Pathing for  Entry: 26790 'TDB FORMAT' 
SET @NPC := 111466;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3269.226,`position_y`=4429.583,`position_z`=25.58942 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3269.226,4429.583,25.58942,0,0,0,0,100,0),
(@PATH,2,3267.759,4388,25.7008,0,0,0,0,100,0),
(@PATH,3,3267.792,4381.39,25.73712,0,0,0,0,100,0),
(@PATH,4,3278.066,4307.007,24.88556,0,0,0,0,100,0),
(@PATH,5,3279.909,4296.206,24.66411,0,0,0,0,100,0),
(@PATH,6,3295.526,4235.11,26.38262,0,0,0,0,100,0),
(@PATH,7,3300.244,4216.931,27.75196,0,0,0,0,100,0),
(@PATH,8,3318.573,4152.362,27.67955,0,0,0,0,100,0),
(@PATH,9,3325.382,4131.279,26.32579,0,0,0,0,100,0),
(@PATH,10,3332.996,4089.244,27.17685,0,0,0,0,100,0),
(@PATH,11,3343.786,4049.672,25.98749,0,0,0,0,100,0),
(@PATH,12,3363.78,4008.359,26.03116,0,0,0,0,100,0),
(@PATH,13,3366.464,4003.271,25.94505,0,0,0,0,100,0),
(@PATH,14,3425.143,4003.964,27.52853,0,0,0,0,100,0),
(@PATH,15,3476.093,4013.513,26.82531,0,0,0,0,100,0),
(@PATH,16,3515.465,4026.42,22.9796,0,0,0,0,100,0),
(@PATH,17,3530.343,4051.534,21.97854,0,0,0,0,100,0),
(@PATH,18,3552.293,4122.889,21.95212,0,0,0,0,100,0),
(@PATH,19,3590.191,4148.155,21.84193,0,0,0,0,100,0),
(@PATH,20,3620.669,4159.591,25.41138,0,0,0,0,100,0),
(@PATH,21,3659.4,4169.95,25.3229,0,0,0,0,100,0),
(@PATH,22,3700.533,4186.467,24.96351,0,0,0,0,100,0),
(@PATH,23,3743.046,4216.556,24.08723,0,0,0,0,100,0),
(@PATH,24,3771.806,4239.74,25.29598,0,0,0,0,100,0),
(@PATH,25,3820.626,4241.001,27.25442,0,0,0,0,100,0),
(@PATH,26,3848.42,4209.31,28.84864,0,0,0,0,100,0),
(@PATH,27,3840.634,4170.563,28.2758,0,0,0,0,100,0),
(@PATH,28,3804.119,4155.879,27.68908,0,0,0,0,100,0),
(@PATH,29,3767.293,4171.405,26.47837,0,0,0,0,100,0),
(@PATH,30,3739.984,4183.705,24.70092,0,0,0,0,100,0),
(@PATH,31,3695.544,4177.419,25.40162,0,0,0,0,100,0),
(@PATH,32,3690.549,4175.297,25.46773,0,0,0,0,100,0),
(@PATH,33,3664.658,4165.97,25.39618,0,0,0,0,100,0),
(@PATH,34,3608.881,4156.498,24.01619,0,0,0,0,100,0),
(@PATH,35,3562.48,4159.697,23.3773,0,0,0,0,100,0),
(@PATH,36,3545.413,4159.953,22.43779,0,0,0,0,100,0),
(@PATH,37,3526.568,4167.223,15.17734,0,0,0,0,100,0),
(@PATH,38,3522.761,4171.347,12.94395,0,0,0,0,100,0),
(@PATH,39,3513.761,4183.413,12.85036,0,0,0,0,100,0),
(@PATH,40,3521.258,4190.762,12.85036,0,0,0,0,100,0),
(@PATH,41,3529.055,4194.656,12.85036,0,0,0,0,100,0),
(@PATH,42,3537.065,4186.435,12.85036,0,0,0,0,100,0),
(@PATH,43,3549.637,4182.573,12.84298,0,0,0,0,100,0),
(@PATH,44,3560.2,4184.638,12.84456,0,0,0,0,100,0),
(@PATH,45,3551.881,4191.742,12.85036,0,0,0,0,100,0),
(@PATH,46,3552.376,4284.875,12.60797,0,0,0,0,100,0),
(@PATH,47,3537.689,4185.746,12.85036,0,0,0,0,100,0),
(@PATH,48,3535.854,4184.324,12.85036,0,0,0,0,100,0),
(@PATH,49,3526.616,4197.904,12.85036,0,0,0,0,100,0),
(@PATH,50,3514.75,4185.95,12.85036,0,0,0,0,100,0),
(@PATH,51,3487.793,4170.192,17.39668,0,0,0,0,100,0),
(@PATH,52,3474.217,4172.794,17.44868,0,0,0,0,100,0),
(@PATH,53,3466.45,4161.327,17.44301,0,0,0,0,100,0),
(@PATH,54,3463.186,4144.002,17.44657,0,0,0,0,100,0),
(@PATH,55,3461.733,4133.489,15.50942,0,0,0,0,100,0),
(@PATH,56,3461.425,4131.252,15.57042,0,0,0,0,100,0),
(@PATH,57,3440.413,4107.955,16.253,0,0,0,0,100,0),
(@PATH,58,3439.38,4106.382,16.33916,0,0,0,0,100,0),
(@PATH,59,3384.195,4062.901,19.78522,0,0,0,0,100,0),
(@PATH,60,3350.907,4085.523,26.59955,0,0,0,0,100,0),
(@PATH,61,3336.268,4101.299,25.10432,0,0,0,0,100,0),
(@PATH,62,3313.968,4123.463,25.70841,0,0,0,0,100,0),
(@PATH,63,3298.833,4136.27,25.76038,0,0,0,0,100,0),
(@PATH,64,3284.301,4171.881,25.73615,0,0,0,0,100,0),
(@PATH,65,3260.152,4249.911,26.19264,0,0,0,0,100,0),
(@PATH,66,3265.231,4272.233,25.12194,0,0,0,0,100,0),
(@PATH,67,3267.608,4324.161,25.83903,0,0,0,0,100,0),
(@PATH,68,3266.102,4333.994,26.12407,0,0,0,0,100,0),
(@PATH,69,3269.841,4402.301,25.18758,0,0,0,0,100,0),
(@PATH,70,3287.93,4442.964,24.90842,0,0,0,0,100,0),
(@PATH,71,3330.486,4488.953,25.63785,0,0,0,0,100,0),
(@PATH,72,3346.958,4513.736,25.21837,0,0,0,0,100,0),
(@PATH,73,3370.701,4574.729,28.1356,0,0,0,0,100,0),
(@PATH,74,3329.835,4909.289,31.98566,0,0,0,0,100,0),
(@PATH,75,3260.729,4889.575,31.59256,0,0,0,0,100,0),
(@PATH,76,3254.577,4883.116,30.8572,0,0,0,0,100,0),
(@PATH,77,3244.599,4836.884,30.49381,0,0,0,0,100,0),
(@PATH,78,3274.862,4794.816,31.06407,0,0,0,0,100,0),
(@PATH,79,3312.659,4774.863,32.49248,0,0,0,0,100,0),
(@PATH,80,3349.351,4758.671,31.47926,0,0,0,0,100,0),
(@PATH,81,3287.93,4442.964,24.90842,0,0,0,0,100,0),
(@PATH,82,3330.486,4488.953,25.63785,0,0,0,0,100,0),
(@PATH,83,3346.958,4513.736,25.21837,0,0,0,0,100,0),
(@PATH,84,3370.701,4574.729,28.1356,0,0,0,0,100,0);
-- 0x1C39AC47601A298000000B00005AED7E .go 3269.226 4429.583 25.58942

-- Pathing for  Entry: 25793 'TDB FORMAT' 
SET @NPC := 57171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3561.628,`position_y`=5005.68,`position_z`=-1.416187 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3561.628,5005.68,-1.416187,0,0,0,0,100,0),
(@PATH,2,3561.647,5005.603,-1.154766,0,0,0,0,100,0),
(@PATH,3,3548.455,4987.43,-1.165261,0,0,0,0,100,0),
(@PATH,4,3548.445,4987.507,-1.393345,0,0,0,0,100,0),
(@PATH,5,3548.703,4987.758,-1.156939,0,0,0,0,100,0),
(@PATH,6,3561.752,5006.026,-1.164443,0,0,0,0,100,0),
(@PATH,7,3561.628,5005.68,-1.416187,0,0,0,0,100,0);
-- 0x1C39AC47601930400000A3000065B380 .go 3561.628 5005.68 -1.416187

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC :=  57156;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3653.617,`position_y`=4706.431,`position_z`=-12.93513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3653.617,4706.431,-12.93513,0,0,0,0,100,0),
(@PATH,2,3644.772,4705.505,-13.09717,0,0,0,0,100,0),
(@PATH,3,3650.718,4705.053,-12.68797,0,0,0,0,100,0),
(@PATH,4,3657.83,4709.773,-12.6719,0,0,0,0,100,0),
(@PATH,5,3662.773,4713.923,-12.66263,0,0,0,0,100,0),
(@PATH,6,3683.912,4744.512,-13.18753,0,0,0,0,100,0),
(@PATH,7,3684.609,4746.4,-13.26137,0,0,0,0,100,0),
(@PATH,8,3681.26,4750.936,-12.83029,0,0,0,0,100,0),
(@PATH,9,3677.817,4771.657,-12.96236,0,0,0,0,100,0),
(@PATH,10,3677.802,4771.346,-13.06311,0,0,0,0,100,0),
(@PATH,11,3678.06,4771.458,-12.99139,0,0,0,0,100,0),
(@PATH,12,3683.749,4747.838,-13.2233,0,0,0,0,100,0),
(@PATH,13,3683.588,4743.549,-12.92916,0,0,0,0,100,0),
(@PATH,14,3676.425,4727.065,-12.68113,0,0,0,0,100,0),
(@PATH,15,3653.484,4706.284,-12.93378,0,0,0,0,100,0),
(@PATH,16,3644.924,4705.583,-13.21565,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C00006399A7 .go 3653.617 4706.431 -12.93513

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57154;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3668.695,`position_y`=4852.459,`position_z`=-12.74998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3668.695,4852.459,-12.74998,0,0,0,0,100,0),
(@PATH,2,3664.671,4872.002,-12.99413,0,0,0,0,100,0),
(@PATH,3,3664.699,4871.859,-13.07822,0,0,0,0,100,0),
(@PATH,4,3665.02,4871.801,-13.02737,0,0,0,0,100,0),
(@PATH,5,3675.036,4847.65,-13.24574,0,0,0,0,100,0),
(@PATH,6,3689.288,4839.663,-12.73423,0,0,0,0,100,0),
(@PATH,7,3700.295,4827.3,-13.29157,0,0,0,0,100,0),
(@PATH,8,3702.61,4824.848,-13.29076,0,0,0,0,100,0),
(@PATH,9,3702.303,4824.782,-13.54672,0,0,0,0,100,0),
(@PATH,10,3696.016,4832.376,-12.71317,0,0,0,0,100,0),
(@PATH,11,3684.51,4841.927,-13.23423,0,0,0,0,100,0),
(@PATH,12,3671.438,4849.996,-12.73423,0,0,0,0,100,0),
(@PATH,13,3668.495,4852.239,-12.74998,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C00006398F7 .go 3668.695 4852.459 -12.74998

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 97940;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3580.309,`position_y`=4549.389,`position_z`=-11.17193 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3580.309,4549.389,-11.17193,0,0,0,0,100,0),
(@PATH,2,3578.376,4553.744,-12.42194,0,0,0,0,100,0),
(@PATH,3,3568.719,4586.03,-13.21303,0,0,0,0,100,0),
(@PATH,4,3580.922,4608.78,-13.29673,0,0,0,0,100,0),
(@PATH,5,3569.915,4581.717,-12.73434,0,0,0,0,100,0),
(@PATH,6,3580.182,4549.349,-11.17194,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C0000635FEA .go 3580.309 4549.389 -11.17193

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 97945;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3638.907,`position_y`=4590.849,`position_z`=-12.90129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3638.907,4590.849,-12.90129,0,0,0,0,100,0),
(@PATH,2,3639.077,4591.158,-12.65275,0,0,0,0,100,0),
(@PATH,3,3657.039,4597.404,-12.65622,0,0,0,0,100,0),
(@PATH,4,3674.552,4584.037,-12.69051,0,0,0,0,100,0),
(@PATH,5,3691.104,4575.537,-12.92792,0,0,0,0,100,0),
(@PATH,6,3700.628,4561.468,-12.65065,0,0,0,0,100,0),
(@PATH,7,3700.406,4561.409,-12.89539,0,0,0,0,100,0),
(@PATH,8,3700.436,4561.741,-12.6833,0,0,0,0,100,0),
(@PATH,9,3690.878,4575.947,-12.68227,0,0,0,0,100,0),
(@PATH,10,3674.272,4584.251,-12.66346,0,0,0,0,100,0),
(@PATH,11,3656.891,4597.556,-12.65173,0,0,0,0,100,0),
(@PATH,12,3638.816,4591.054,-12.67964,0,0,0,0,100,0),
(@PATH,13,3638.907,4590.849,-12.90129,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000C000063960F .go 3638.907 4590.849 -12.90129

-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57150;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3540.325,`position_y`=4553.921,`position_z`=-11.9877 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3540.325,4553.921,-11.9877,0,0,0,0,100,0),
(@PATH,2,3551.097,4546.824,-12.09515,0,0,0,0,100,0),
(@PATH,3,3556.957,4542.564,-12.71872,0,0,0,0,100,0),
(@PATH,4,3572.592,4519.032,-12.57456,0,0,0,0,100,0),
(@PATH,5,3611.974,4514.621,-11.45239,0,0,0,0,100,0),
(@PATH,6,3596.514,4512.68,-11.4117,0,0,0,0,100,0),
(@PATH,7,3591.572,4513.184,-12.59506,0,0,0,0,100,0),
(@PATH,8,3572.187,4519.236,-12.62936,0,0,0,0,100,0),
(@PATH,9,3542.318,4553.094,-11.18209,0,0,0,0,100,0),
(@PATH,10,3538.412,4553.636,-12.23789,0,0,0,0,100,0),
(@PATH,11,3540.325,4553.921,-11.9877,0,0,0,0,100,0),
(@PATH,12,3551.078,4546.787,-12.28936,0,0,0,0,100,0);
-- 0x1C39AC47601904C00000A30000661A2D .go 3540.325 4553.921 -11.9877


-- Pathing for  Entry: 25619 'TDB FORMAT' 
SET @NPC := 57149;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3440.258,`position_y`=4514.217,`position_z`=-12.88582 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3440.258,4514.217,-12.88582,2,0,0,0,100,0),
(@PATH,2,3440.258,4514.217,-12.88582,2,0,0,0,100,0),
(@PATH,3,3440.896,4516.193,-12.89167,3,0,0,0,100,0),
(@PATH,4,3442.607,4496.93,-12.91095,0,0,0,0,100,0),
(@PATH,5,3447.15,4488.138,-12.65823,0,0,0,0,100,0),
(@PATH,6,3452.752,4476.723,-12.68911,0,0,0,0,100,0),
(@PATH,7,3476.311,4474.729,-12.71476,0,0,0,0,100,0),
(@PATH,8,3494.302,4476.382,-12.71264,0,0,0,0,100,0),
(@PATH,9,3494.728,4476.228,-12.96695,3,0,0,0,100,0),
(@PATH,10,3511.506,4473.141,-12.958,0,0,0,0,100,0),
(@PATH,11,3494.125,4476.339,-12.96727,0,0,0,0,100,0),
(@PATH,12,3494.088,4476.244,-12.71688,0,0,0,0,100,0),
(@PATH,13,3476.16,4474.544,-12.68911,0,0,0,0,100,0),
(@PATH,14,3444.08,4494.611,-12.66572,0,0,0,0,100,0),
(@PATH,15,3442.532,4497.133,-12.64838,0,0,0,0,100,0),
(@PATH,16,3440.716,4522.266,-12.63575,0,0,0,0,100,0),
(@PATH,17,3440.376,4522.044,-12.88582,0,0,0,0,100,0),
(@PATH,18,3440.543,4522.067,-12.6481,0,0,0,0,100,0),
(@PATH,19,3447.229,4487.997,-12.65975,0,0,0,0,100,0),
(@PATH,20,3452.721,4477.046,-12.68911,0,0,0,0,100,0);
-- 0x1C39AC47601904C000000A000063A957 .go 3440.258 4514.217 -12.88582

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104890;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3649.046,`position_y`=3947.566,`position_z`=25.10987 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3649.046,3947.566,25.10987,0,0,0,0,100,0),
(@PATH,2,3670.215,3953.261,27.32766,0,0,0,0,100,0),
(@PATH,3,3661.302,3951.949,25.85034,0,0,0,0,100,0),
(@PATH,4,3647.474,3946.993,24.98032,0,0,0,0,100,0),
(@PATH,5,3631.758,3945.262,25.08576,0,0,0,0,100,0),
(@PATH,6,3635.313,3944.982,24.81682,0,0,0,0,100,0),
(@PATH,7,3649.313,3947.802,25.10083,0,0,0,0,100,0),
(@PATH,8,3670.304,3953.393,27.30864,0,0,0,0,100,0);
-- 0x1C39AC47601919000000A3000065CBC5 .go 3649.046 3947.566 25.10987

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3612.053,`position_y`=3969.457,`position_z`=25.79908 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3612.053,3969.457,25.79908,0,0,0,0,100,0),
(@PATH,2,3612.913,3949.386,26.9285,0,0,0,0,100,0),
(@PATH,3,3606.506,3943.484,27.81473,0,0,0,0,100,0),
(@PATH,4,3599.383,3941.598,27.42816,0,0,0,0,100,0),
(@PATH,5,3613.519,3957.487,25.68642,0,0,0,0,100,0),
(@PATH,6,3610.85,3975.829,26.71345,0,0,0,0,100,0),
(@PATH,7,3610.689,3977.498,26.90823,0,0,0,0,100,0);
-- 0x1C39AC47601919000000A3000065CBB6 .go 3612.053 3969.457 25.79908

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104885;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3547.306,`position_y`=3938.455,`position_z`=28.18571 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3547.306,3938.455,28.18571,0,0,0,0,100,0),
(@PATH,2,3547.207,3940.361,28.20439,0,0,0,0,100,0),
(@PATH,3,3549.885,3950.133,28.27749,0,0,0,0,100,0),
(@PATH,4,3547.638,3926.375,28.40306,0,0,0,0,100,0),
(@PATH,5,3546.562,3908.686,26.7371,0,0,0,0,100,0);
-- 0x1C39AC47601919000000990000649C8A .go 3547.306 3938.455 28.18571

-- Pathing for  Entry: 25700 'TDB FORMAT' 
SET @NPC := 104894;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3778.342,`position_y`=3912.803,`position_z`=29.24027 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3778.342,3912.803,29.24027,0,0,0,0,100,0),
(@PATH,2,3759.181,3931.342,27.90885,0,0,0,0,100,0),
(@PATH,3,3753.393,3933.303,27.37968,0,0,0,0,100,0),
(@PATH,4,3753.327,3933.25,27.1396,0,0,0,0,100,0),
(@PATH,5,3770.313,3927.754,29.42538,0,0,0,0,100,0),
(@PATH,6,3771.412,3927.011,29.40953,0,0,0,0,100,0),
(@PATH,7,3778.897,3901.917,30.91071,0,0,0,0,100,0);
-- 0x1C39AC476019190000000A00005F9DDF .go 3778.342 3912.803 29.24027


-- Pathing for  Entry: 25615 'TDB FORMAT' 
SET @NPC := 97719;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3952.9,`position_y`=3970.767,`position_z`=60.06356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '45797');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3952.9,3970.767,60.06356,0,0,0,0,100,0),
(@PATH,2,3978.35,3999.136,62.92397,0,0,0,0,100,0),
(@PATH,3,4018.881,4028.354,68.87595,0,0,0,0,100,0),
(@PATH,4,4054.792,4041.589,78.42586,0,0,0,0,100,0),
(@PATH,5,4079.642,4057.923,86.41113,0,0,0,0,100,0),
(@PATH,6,4109.986,4083.86,91.92527,0,0,0,0,100,0),
(@PATH,7,4146.447,4095.262,94.97155,0,0,0,0,100,0),
(@PATH,8,4116.737,4088.786,92.95302,0,0,0,0,100,0),
(@PATH,9,4085.337,4060.936,87.70323,0,0,0,0,100,0),
(@PATH,10,4058.099,4043.569,79.66705,0,0,0,0,100,0),
(@PATH,11,4020.782,4029.594,69.42237,0,0,0,0,100,0),
(@PATH,12,3994.482,4012.06,64.00913,0,0,0,0,100,0),
(@PATH,13,3968.87,3988.12,59.70909,0,0,0,0,100,0),
(@PATH,14,3929.95,3947.708,63.23425,0,0,0,0,100,0),
(@PATH,15,3911.141,3924.254,62.15401,0,0,0,0,100,0),
(@PATH,16,3873.239,3894.211,53.25244,0,0,0,0,100,0),
(@PATH,17,3906.264,3919.628,61.43396,0,0,0,0,100,0),
(@PATH,18,3928.859,3946.259,63.19824,0,0,0,0,100,0),
(@PATH,19,3952.789,3970.748,60.02489,0,0,0,0,100,0);
-- 0x1C39AC47601903C00000FB00006640F7 .go 3952.9 3970.767 60.06356

-- Pathing for  Entry: 25684 'TDB FORMAT' 
SET @NPC := 103453;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4426.675,`position_y`=4548.689,`position_z`=105.0451 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4426.675,4548.689,105.0451,0,0,0,0,100,0),
(@PATH,2,4426.097,4567.237,105.0696,0,0,0,0,100,0),
(@PATH,3,4427.304,4550.866,105.1948,0,0,0,0,100,0),
(@PATH,4,4424.215,4542.484,104.0657,0,0,0,0,100,0),
(@PATH,5,4408.765,4527.845,109.2442,0,0,0,0,100,0),
(@PATH,6,4417.008,4531.223,106.1703,0,0,0,0,100,0),
(@PATH,7,4426.797,4548.548,105.0981,0,0,0,0,100,0),
(@PATH,8,4426.019,4567.411,105.0588,0,0,0,0,100,0);
-- 0x1C39AC47601915000000F80000663747 .go 4426.675 4548.689 105.0451

-- Cult Plaguebringer SAI
SET @ENTRY := 24957;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,900000,500000,700000,11,45850,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cult Plaguebringer - Out of Combat - Cast 'Ghoul Summons'"),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,"Cult Plaguebringer - On Respawn - Cast 'Plague Cauldron Beam'"),
(@ENTRY,0,2,0,0,0,30,0,1100,6300,8800,13800,11,50356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cult Plaguebringer - In Combat - Cast 'Inject Plague'"),
(@ENTRY,0,3,0,21,0,100,0,0,0,0,0,11,45820,0,0,0,0,0,9,24021,0,30,0,0,0,0,"Cult Plaguebringer - On Reached Home - Cast 'Plague Cauldron Beam'"),
(@ENTRY,0,4,0,1,0,100,0,5000,10000,10000,15000,11,45864,0,0,0,0,0,19,23837,20,0,0,0,0,0,"Cult Plaguebringer - Out of Combat - Cast 'Soul Missile'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=45864;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 45864, 0, 0, 31, 0, 3, 23837, 0, 0, 0, 0, '', 'Visual - ony targets Dummy');

DELETE FROM `waypoints` WHERE `entry`=965560;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(965560, 1,3882.081,3605.613,47.20867, 'Darkfallen Bloodbearer'),
(965560, 2,3880.675,3604.947,46.98143, 'Darkfallen Bloodbearer'),
(965560, 3,3873.556,3605.217,47.1648, 'Darkfallen Bloodbearer'),
(965560, 4,3864.232,3594.599,46.89387, 'Darkfallen Bloodbearer'),
(965560, 5,3863.215,3593.009,46.80249, 'Darkfallen Bloodbearer'),
(965560, 6,3857.541,3589.546,46.89201, 'Darkfallen Bloodbearer'),
(965560, 7,3849.738,3589.315,47.19809, 'Darkfallen Bloodbearer'),
(965560, 8,3841.684,3593.68,47.05273, 'Darkfallen Bloodbearer'),
(965560, 9,3835.923,3599.622,47.26691, 'Darkfallen Bloodbearer'),
(965560, 10,3828.859,3599.792,47.14082, 'Darkfallen Bloodbearer'),
(965560, 11,3821.26,3598.35,46.8344, 'Darkfallen Bloodbearer'),
(965560, 12,3806.117,3590.271,48.67004, 'Darkfallen Bloodbearer'),
(965560, 13,3801.333,3586.158,49.71964, 'Darkfallen Bloodbearer');

-- Darkfallen Bloodbearer SAI
SET @GUID := -96556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=26115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,25,0,100,0,0,0,0,0,53,0,965560,0,0,0,0,1,0,0,0,0,0,0,0,"Darkfallen Bloodbearer - On Reset - Start Waypoint"),
(@GUID,0,1,0,40,0,100,0,13,965560,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkfallen Bloodbearer - On Waypoint 13 Reached - Despawn In 2000 ms");
