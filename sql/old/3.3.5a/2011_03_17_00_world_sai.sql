-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3859.662,`position_y`=3393.562,`position_z`=67.97741 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.184,3393.872,68.60241,0,0,0,100,0),
(@PATH,2,3853.398,3388.785,70.60241,0,0,0,100,0),
(@PATH,3,3856.184,3393.872,68.60241,0,0,0,100,0),
(@PATH,4,3859.662,3393.562,67.97741,0,0,0,100,0),
(@PATH,5,3865.199,3400.655,64.67162,0,0,0,100,0),
(@PATH,6,3862.853,3407.01,64.17162,0,0,0,100,0),
(@PATH,7,3864.934,3414.912,64.17162,0,0,0,100,0),
(@PATH,8,3862.853,3407.01,64.17162,0,0,0,100,0),
(@PATH,9,3865.199,3400.655,64.67162,0,0,0,100,0),
(@PATH,10,3859.662,3393.562,67.97741,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100009;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3896.402,`position_y`=3454.12,`position_z`=64.19093 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3890.689,3458.416,65.06593,0,0,0,100,0),
(@PATH,2,3878.707,3463.25,64.06593,0,0,0,100,0),
(@PATH,3,3865.527,3468.116,64.16493,0,0,0,100,0),
(@PATH,4,3867.453,3467.697,64.16493,0,0,0,100,0),
(@PATH,5,3878.97,3463.877,64.06593,0,0,0,100,0),
(@PATH,6,3896.402,3454.12,64.19093,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99955;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3849.937,`position_y`=3440.836,`position_z`=64.08922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3844.136,3430.625,64.17162,0,0,0,100,0),
(@PATH,2,3836.185,3415.533,67.29662,0,0,0,100,0),
(@PATH,3,3838.057,3414.41,67.17162,0,0,0,100,0),
(@PATH,4,3843.113,3427.501,64.29662,0,0,0,100,0),
(@PATH,5,3848.386,3439.262,64.08922,0,0,0,100,0),
(@PATH,6,3849.937,3440.836,64.08922,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99856;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3944.872,`position_y`=3387.368,`position_z`=82.84169 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3958.746,3388.819,83.46669,0,0,0,100,0),
(@PATH,2,3939.345,3406.614,80.91746,0,0,0,100,0),
(@PATH,3,3932.713,3412.609,80.93697,0,0,0,100,0),
(@PATH,4,3931.988,3409.037,80.93697,0,0,0,100,0),
(@PATH,5,3940.203,3397.782,80.96669,0,0,0,100,0),
(@PATH,6,3944.872,3387.368,82.84169,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99853;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3988.71,`position_y`=3389.023,`position_z`=84.59169 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3995.287,3398.66,83.21669,0,0,0,100,0),
(@PATH,2,3999.713,3411.761,84.47887,0,0,0,100,0),
(@PATH,3,3992.017,3414.793,83.10387,0,0,0,100,0),
(@PATH,4,3980.25,3399.608,80.96669,0,0,0,100,0),
(@PATH,5,3973.198,3392.127,81.21669,0,0,0,100,0),
(@PATH,6,3981.25,3389.583,83.71669,0,0,0,100,0),
(@PATH,7,3988.71,3389.023,84.59169,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100008;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3961.064,`position_y`=3422.165,`position_z`=80.91746 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3958.62,3407.545,80.91746,0,0,0,100,0),
(@PATH,2,3959.292,3391.561,82.09169,0,0,0,100,0),
(@PATH,3,3959.987,3394.481,81.09169,0,0,0,100,0),
(@PATH,4,3961.145,3408.606,80.91746,0,0,0,100,0),
(@PATH,5,3963.867,3424.426,80.91746,0,0,0,100,0),
(@PATH,6,3961.064,3422.165,80.91746,0,0,0,100,0);
-- 0xF13000632A00102F .go 3958.62 3407.545 80.91746

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100011;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3973.765,`position_y`=3685.582,`position_z`=63.20702 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3985.953,3658.16,62.64196,0,0,0,100,0),
(@PATH,2,3981.12,3655.121,62.51696,0,0,0,100,0),
(@PATH,3,3975.807,3676.29,63.20702,0,0,0,100,0),
(@PATH,4,3968.138,3708.388,63.14015,0,0,0,100,0),
(@PATH,5,3973.765,3685.582,63.20702,0,0,0,100,0);
-- 0xF53000632A016E01 .go 3985.953 3658.16 62.64196

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99855;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3767.44,`position_y`=3483.963,`position_z`=64.18696 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3765.76,3473.853,64.31196,0,0,0,100,0),
(@PATH,2,3767.138,3500.103,64.0854,0,0,0,100,0),
(@PATH,3,3770.234,3518.467,64.0854,0,0,0,100,0),
(@PATH,4,3769.093,3509.577,64.0854,0,0,0,100,0),
(@PATH,5,3768.024,3494.981,64.18696,0,0,0,100,0),
(@PATH,6,3767.44,3483.963,64.18696,0,0,0,100,0);
-- 0xF53000632A017C11 .go 3765.76 3473.853 64.31196

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3859.662,`position_y`=3393.562,`position_z`=67.97741 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3856.184,3393.872,68.60241,0,0,0,100,0),
(@PATH,2,3853.398,3388.785,70.60241,0,0,0,100,0),
(@PATH,3,3856.184,3393.872,68.60241,0,0,0,100,0),
(@PATH,4,3859.662,3393.562,67.97741,0,0,0,100,0),
(@PATH,5,3865.199,3400.655,64.67162,0,0,0,100,0),
(@PATH,6,3862.853,3407.01,64.17162,0,0,0,100,0),
(@PATH,7,3864.934,3414.912,64.17162,0,0,0,100,0),
(@PATH,8,3862.853,3407.01,64.17162,0,0,0,100,0),
(@PATH,9,3865.199,3400.655,64.67162,0,0,0,100,0),
(@PATH,10,3859.662,3393.562,67.97741,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100009;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3896.402,`position_y`=3454.12,`position_z`=64.19093 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3890.689,3458.416,65.06593,0,0,0,100,0),
(@PATH,2,3878.707,3463.25,64.06593,0,0,0,100,0),
(@PATH,3,3865.527,3468.116,64.16493,0,0,0,100,0),
(@PATH,4,3867.453,3467.697,64.16493,0,0,0,100,0),
(@PATH,5,3878.97,3463.877,64.06593,0,0,0,100,0),
(@PATH,6,3896.402,3454.12,64.19093,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99955;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3849.937,`position_y`=3440.836,`position_z`=64.08922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3844.136,3430.625,64.17162,0,0,0,100,0),
(@PATH,2,3836.185,3415.533,67.29662,0,0,0,100,0),
(@PATH,3,3838.057,3414.41,67.17162,0,0,0,100,0),
(@PATH,4,3843.113,3427.501,64.29662,0,0,0,100,0),
(@PATH,5,3848.386,3439.262,64.08922,0,0,0,100,0),
(@PATH,6,3849.937,3440.836,64.08922,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99856;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3944.872,`position_y`=3387.368,`position_z`=82.84169 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3958.746,3388.819,83.46669,0,0,0,100,0),
(@PATH,2,3939.345,3406.614,80.91746,0,0,0,100,0),
(@PATH,3,3932.713,3412.609,80.93697,0,0,0,100,0),
(@PATH,4,3931.988,3409.037,80.93697,0,0,0,100,0),
(@PATH,5,3940.203,3397.782,80.96669,0,0,0,100,0),
(@PATH,6,3944.872,3387.368,82.84169,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99853;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3988.71,`position_y`=3389.023,`position_z`=84.59169 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3995.287,3398.66,83.21669,0,0,0,100,0),
(@PATH,2,3999.713,3411.761,84.47887,0,0,0,100,0),
(@PATH,3,3992.017,3414.793,83.10387,0,0,0,100,0),
(@PATH,4,3980.25,3399.608,80.96669,0,0,0,100,0),
(@PATH,5,3973.198,3392.127,81.21669,0,0,0,100,0),
(@PATH,6,3981.25,3389.583,83.71669,0,0,0,100,0),
(@PATH,7,3988.71,3389.023,84.59169,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100008;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3961.064,`position_y`=3422.165,`position_z`=80.91746 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3958.62,3407.545,80.91746,0,0,0,100,0),
(@PATH,2,3959.292,3391.561,82.09169,0,0,0,100,0),
(@PATH,3,3959.987,3394.481,81.09169,0,0,0,100,0),
(@PATH,4,3961.145,3408.606,80.91746,0,0,0,100,0),
(@PATH,5,3963.867,3424.426,80.91746,0,0,0,100,0),
(@PATH,6,3961.064,3422.165,80.91746,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 100011;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3973.765,`position_y`=3685.582,`position_z`=63.20702 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3985.953,3658.16,62.64196,0,0,0,100,0),
(@PATH,2,3981.12,3655.121,62.51696,0,0,0,100,0),
(@PATH,3,3975.807,3676.29,63.20702,0,0,0,100,0),
(@PATH,4,3968.138,3708.388,63.14015,0,0,0,100,0),
(@PATH,5,3973.765,3685.582,63.20702,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99860;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3736.829,`position_y`=3590.097,`position_z`=47.62042 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3740.556,3611.562,49.59578,0,0,0,100,0),
(@PATH,2,3743.815,3598.767,46.74542,0,0,0,100,0),
(@PATH,3,3750.231,3578.953,46.87042,0,0,0,100,0),
(@PATH,4,3744.763,3577.349,46.87042,0,0,0,100,0),
(@PATH,5,3736.829,3590.097,47.62042,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99861;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3781.2,`position_y`=3555.762,`position_z`=47.13174 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3781.763,3556.428,47.13174,0,0,0,100,0),
(@PATH,2,3784.81,3570.215,46.82142,0,0,0,100,0),
(@PATH,3,3784.099,3579.592,48.19642,0,0,0,100,0),
(@PATH,4,3784.9,3578.852,48.32142,0,0,0,100,0),
(@PATH,5,3784.858,3565.897,46.63174,0,0,0,100,0),
(@PATH,6,3781.2,3555.762,47.13174,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3795.21,`position_y`=3453.815,`position_z`=82.97263 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3789.819,3445.883,82.97262,0,0,0,100,0),
(@PATH,2,3785.635,3440.609,82.97261,0,0,0,100,0),
(@PATH,3,3780.893,3429.421,82.9726,0,0,0,100,0),
(@PATH,4,3785.635,3440.609,82.97261,0,0,0,100,0),
(@PATH,5,3789.819,3445.883,82.97262,0,0,0,100,0),
(@PATH,6,3795.21,3453.815,82.97263,0,0,0,100,0);

-- Pathing for En'kilah Crypt Fiend Entry: 25386
SET @NPC := 99871;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3812.432,`position_y`=3443.979,`position_z`=82.97263 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3808.239,3432.998,82.97262,0,0,0,100,0),
(@PATH,2,3805.263,3425.894,82.97261,0,0,0,100,0),
(@PATH,3,3808.239,3432.998,82.97262,0,0,0,100,0),
(@PATH,4,3812.432,3443.979,82.97263,0,0,0,100,0);

-- Remove 2 over spawns
DELETE FROM `creature` WHERE `guid` IN (99859,99858);
DELETE FROM `creature_addon` WHERE `guid` IN (99859,99858);

