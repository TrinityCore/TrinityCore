-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71525;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-811.9146,`position_y`=5769.104,`position_z`=17.18619 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-811.9146,5769.104,17.18619,0,0,0,0,100,0),
(@PATH,2,-823.9103,5769.617,18.49771,0,0,0,0,100,0),
(@PATH,3,-837.1352,5761.915,13.98373,0,0,0,0,100,0),
(@PATH,4,-845.346,5746.582,15.9177,0,0,0,0,100,0),
(@PATH,5,-856.5806,5737.951,17.44125,0,0,0,0,100,0),
(@PATH,6,-870.8132,5739.455,18.25524,0,0,0,0,100,0),
(@PATH,7,-876.6976,5766.97,17.9558,0,0,0,0,100,0),
(@PATH,8,-879.2238,5786.183,17.97192,0,0,0,0,100,0),
(@PATH,9,-877.8231,5799.473,18.22192,0,0,0,0,100,0),
(@PATH,10,-875.8525,5816.587,18.1166,0,0,0,0,100,0),
(@PATH,11,-870.438,5833.134,17.8666,0,0,0,0,100,0),
(@PATH,12,-875.8525,5816.587,18.1166,0,0,0,0,100,0),
(@PATH,13,-877.8231,5799.473,18.22192,0,0,0,0,100,0),
(@PATH,14,-879.2238,5786.183,17.97192,0,0,0,0,100,0),
(@PATH,15,-876.6976,5766.97,17.9558,0,0,0,0,100,0),
(@PATH,16,-870.8132,5739.455,18.25524,0,0,0,0,100,0),
(@PATH,17,-856.5806,5737.951,17.44125,0,0,0,0,100,0),
(@PATH,18,-845.346,5746.582,15.9177,0,0,0,0,100,0),
(@PATH,19,-837.1352,5761.915,13.98373,0,0,0,0,100,0),
(@PATH,20,-823.9103,5769.617,18.49771,0,0,0,0,100,0),
(@PATH,21,-811.9146,5769.104,17.18619,0,0,0,0,100,0),
(@PATH,22,-803.7941,5777.138,19.5491,0,0,0,0,100,0),
(@PATH,23,-805.7983,5789.479,19.2897,0,0,0,0,100,0),
(@PATH,24,-813.3177,5798.603,18.38748,0,0,0,0,100,0),
(@PATH,25,-825.4734,5800.777,17.13269,0,0,0,0,100,0),
(@PATH,26,-841.5132,5803.947,14.80724,0,0,0,0,100,0),
(@PATH,27,-853.8585,5824.338,14.71092,0,0,0,0,100,0),
(@PATH,28,-864.2906,5832.222,17.76622,0,0,0,0,100,0),
(@PATH,29,-853.9316,5824.39,14.72874,0,0,0,0,100,0),
(@PATH,30,-841.5132,5803.947,14.80724,0,0,0,0,100,0),
(@PATH,31,-825.4734,5800.777,17.13269,0,0,0,0,100,0),
(@PATH,32,-813.3177,5798.603,18.38748,0,0,0,0,100,0),
(@PATH,33,-805.7983,5789.479,19.2897,0,0,0,0,100,0),
(@PATH,34,-803.7941,5777.138,19.5491,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71526;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-410.8705,`position_y`=6309.836,`position_z`=17.62405 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-410.8705,6309.836,17.62405,0,0,0,0,100,0),
(@PATH,2,-397.7162,6294.659,17.62408,0,0,0,0,100,0),
(@PATH,3,-386.2312,6282.547,17.49908,0,0,0,0,100,0),
(@PATH,4,-397.7162,6294.659,17.62408,0,0,0,0,100,0),
(@PATH,5,-410.8705,6309.836,17.62405,0,0,0,0,100,0),
(@PATH,6,-412.0008,6326.139,17.70071,0,0,0,0,100,0),
(@PATH,7,-427.5412,6351.002,17.63304,0,0,0,0,100,0),
(@PATH,8,-442.1701,6376.702,17.97111,0,0,0,0,100,0),
(@PATH,9,-440.1516,6410.867,17.4473,0,0,0,0,100,0),
(@PATH,10,-436.8709,6453.745,17.55275,0,0,0,0,100,0),
(@PATH,11,-406.3064,6458.811,17.25673,0,0,0,0,100,0),
(@PATH,12,-390.183,6444.14,17.39387,0,0,0,0,100,0),
(@PATH,13,-406.3064,6458.811,17.25673,0,0,0,0,100,0),
(@PATH,14,-436.8709,6453.745,17.55275,0,0,0,0,100,0),
(@PATH,15,-440.1516,6410.867,17.4473,0,0,0,0,100,0),
(@PATH,16,-442.1701,6376.702,17.97111,0,0,0,0,100,0),
(@PATH,17,-427.5412,6351.002,17.63304,0,0,0,0,100,0),
(@PATH,18,-412.0008,6326.139,17.70071,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71527;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-355.7398,`position_y`=6439.344,`position_z`=17.67068 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-355.7398,6439.344,17.67068,0,0,0,0,100,0),
(@PATH,2,-337.6484,6458.52,16.78129,0,0,0,0,100,0),
(@PATH,3,-355.7398,6439.344,17.67068,0,0,0,0,100,0),
(@PATH,4,-375.4502,6416.951,17.63828,0,0,0,0,100,0),
(@PATH,5,-352.3055,6382.163,17.44267,0,0,0,0,100,0),
(@PATH,6,-339.4132,6371.913,18.95378,0,0,0,0,100,0),
(@PATH,7,-320.4037,6349.353,17.49905,0,0,0,0,100,0),
(@PATH,8,-339.4132,6371.913,18.95378,0,0,0,0,100,0),
(@PATH,9,-352.3055,6382.163,17.44267,0,0,0,0,100,0),
(@PATH,10,-375.4502,6416.951,17.63828,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71528;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-320.0476,`position_y`=6163.984,`position_z`=17.62409 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-320.0476,6163.984,17.62409,0,0,0,0,100,0),
(@PATH,2,-331.2123,6150.911,17.87409,0,0,0,0,100,0),
(@PATH,3,-345.0256,6140.545,18.02436,0,0,0,0,100,0),
(@PATH,4,-360.5103,6137.307,17.89936,0,0,0,0,100,0),
(@PATH,5,-381.054,6139.517,18.19844,0,0,0,0,100,0),
(@PATH,6,-360.5103,6137.307,17.89936,0,0,0,0,100,0),
(@PATH,7,-345.0256,6140.545,18.02436,0,0,0,0,100,0),
(@PATH,8,-331.2123,6150.911,17.87409,0,0,0,0,100,0),
(@PATH,9,-320.0476,6163.984,17.62409,0,0,0,0,100,0),
(@PATH,10,-314.4604,6181.93,17.56598,0,0,0,0,100,0),
(@PATH,11,-319.6298,6200.069,17.49909,0,0,0,0,100,0),
(@PATH,12,-316.2941,6219.737,17.49909,0,0,0,0,100,0),
(@PATH,13,-316.1273,6237.474,17.49908,0,0,0,0,100,0),
(@PATH,14,-316.2941,6219.737,17.49909,0,0,0,0,100,0),
(@PATH,15,-319.6298,6200.069,17.49909,0,0,0,0,100,0),
(@PATH,16,-314.4604,6181.93,17.56598,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71529;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-410.5085,`position_y`=6255.543,`position_z`=17.44794 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-410.5085,6255.543,17.44794,0,0,0,0,100,0),
(@PATH,2,-386.918,6282.233,17.49908,0,0,0,0,100,0),
(@PATH,3,-410.5085,6255.543,17.44794,0,0,0,0,100,0),
(@PATH,4,-421.0254,6231.694,17.49909,0,0,0,0,100,0),
(@PATH,5,-453.1329,6217.985,17.48819,0,0,0,0,100,0),
(@PATH,6,-473.6789,6245.981,17.65528,0,0,0,0,100,0),
(@PATH,7,-481.439,6255.942,17.70008,0,0,0,0,100,0),
(@PATH,8,-482.8473,6271.657,17.61994,0,0,0,0,100,0),
(@PATH,9,-471.7555,6293.839,17.87409,0,0,0,0,100,0),
(@PATH,10,-456.8588,6315.148,17.00413,0,0,0,0,100,0),
(@PATH,11,-445.0121,6331.941,17.53489,0,0,0,0,100,0),
(@PATH,12,-456.8588,6315.148,17.00413,0,0,0,0,100,0),
(@PATH,13,-471.7555,6293.839,17.87409,0,0,0,0,100,0),
(@PATH,14,-482.8473,6271.657,17.61994,0,0,0,0,100,0),
(@PATH,15,-481.439,6255.942,17.70008,0,0,0,0,100,0),
(@PATH,16,-473.6789,6245.981,17.65528,0,0,0,0,100,0),
(@PATH,17,-453.1329,6217.985,17.48819,0,0,0,0,100,0),
(@PATH,18,-421.0254,6231.694,17.49909,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71530;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-523.4554,`position_y`=5876.645,`position_z`=17.92353 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-523.4554,5876.645,17.92353,0,0,0,0,100,0),
(@PATH,2,-540.7239,5876.821,17.94059,0,0,0,0,100,0),
(@PATH,3,-546.246,5885.771,17.86613,0,0,0,0,100,0),
(@PATH,4,-558.3109,5907.695,17.4421,0,0,0,0,100,0),
(@PATH,5,-570.5005,5919.63,17.4075,0,0,0,0,100,0),
(@PATH,6,-583.1713,5918.977,17.5325,0,0,0,0,100,0),
(@PATH,7,-596.1543,5918.109,17.6575,0,0,0,0,100,0),
(@PATH,8,-583.1713,5918.977,17.5325,0,0,0,0,100,0),
(@PATH,9,-570.5005,5919.63,17.4075,0,0,0,0,100,0),
(@PATH,10,-558.3109,5907.695,17.4421,0,0,0,0,100,0),
(@PATH,11,-546.246,5885.771,17.86613,0,0,0,0,100,0),
(@PATH,12,-540.7239,5876.821,17.94059,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71531;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-685.4247,`position_y`=5744.201,`position_z`=14.45076 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-685.4247,5744.201,14.45076,0,0,0,0,100,0),
(@PATH,2,-689.3704,5733.29,15.48919,0,0,0,0,100,0),
(@PATH,3,-694.3406,5721.417,15.68475,0,0,0,0,100,0),
(@PATH,4,-693.628,5710.063,17.0241,0,0,0,0,100,0),
(@PATH,5,-685.0911,5693.25,17.02255,0,0,0,0,100,0),
(@PATH,6,-664.6328,5678.895,16.09896,0,0,0,0,100,0),
(@PATH,7,-634.0374,5672.613,14.96591,0,0,0,0,100,0),
(@PATH,8,-620.5831,5687.272,16.39875,0,0,0,0,100,0),
(@PATH,9,-613.4608,5698.938,17.93769,0,0,0,0,100,0),
(@PATH,10,-616.0839,5713.076,16.13629,0,0,0,0,100,0),
(@PATH,11,-618.7032,5726.208,14.38177,0,0,0,0,100,0),
(@PATH,12,-634.3477,5740.746,9.167722,0,0,0,0,100,0),
(@PATH,13,-644.801,5754.851,13.55782,0,0,0,0,100,0),
(@PATH,14,-664.2159,5766.098,11.48791,0,0,0,0,100,0),
(@PATH,15,-676.3831,5758.203,15.53962,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71532;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-636.8377,`position_y`=5918.188,`position_z`=17.91747 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-636.8377,5918.188,17.91747,0,0,0,0,100,0),
(@PATH,2,-650.0894,5912.31,17.40759,0,0,0,0,100,0),
(@PATH,3,-649.3865,5895.695,18.2393,0,0,0,0,100,0),
(@PATH,4,-649.5691,5884.616,15.62773,0,0,0,0,100,0),
(@PATH,5,-649.3865,5895.695,18.2393,0,0,0,0,100,0),
(@PATH,6,-650.0894,5912.31,17.40759,0,0,0,0,100,0),
(@PATH,7,-636.8377,5918.188,17.91747,0,0,0,0,100,0),
(@PATH,8,-619.8817,5917.089,17.98915,0,0,0,0,100,0),
(@PATH,9,-605.9981,5915.45,17.85243,0,0,0,0,100,0),
(@PATH,10,-592.5848,5917.771,17.47745,0,0,0,0,100,0),
(@PATH,11,-605.9981,5915.45,17.85243,0,0,0,0,100,0),
(@PATH,12,-619.8817,5917.089,17.98915,0,0,0,0,100,0);

-- Pathing for Darkcrest Sentry Entry: 20079
SET @NPC := 71533;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-745.6512,`position_y`=5946.403,`position_z`=17.49909 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-745.6512,5946.403,17.49909,0,0,0,0,100,0),
(@PATH,2,-733.8559,5949.237,17.62409,0,0,0,0,100,0),
(@PATH,3,-715.53,5953.377,17.4991,0,0,0,0,100,0),
(@PATH,4,-694.0532,5951.034,17.4991,0,0,0,0,100,0),
(@PATH,5,-684.2486,5942.766,17.77119,0,0,0,0,100,0),
(@PATH,6,-674.2134,5928.139,17.84693,0,0,0,0,100,0),
(@PATH,7,-684.2486,5942.766,17.77119,0,0,0,0,100,0),
(@PATH,8,-694.0532,5951.034,17.4991,0,0,0,0,100,0),
(@PATH,9,-715.53,5953.377,17.4991,0,0,0,0,100,0),
(@PATH,10,-733.8559,5949.237,17.62409,0,0,0,0,100,0),
(@PATH,11,-745.6512,5946.403,17.49909,0,0,0,0,100,0),
(@PATH,12,-763.0795,5961.114,18.29157,0,0,0,0,100,0),
(@PATH,13,-790.5579,5959.934,17.61956,0,0,0,0,100,0),
(@PATH,14,-816.7445,5948.383,17.49907,0,0,0,0,100,0),
(@PATH,15,-839.172,5933.668,17.74907,0,0,0,0,100,0),
(@PATH,16,-846.7526,5922.306,17.63042,0,0,0,0,100,0),
(@PATH,17,-839.172,5933.668,17.74907,0,0,0,0,100,0),
(@PATH,18,-816.7445,5948.383,17.49907,0,0,0,0,100,0),
(@PATH,19,-790.5579,5959.934,17.61956,0,0,0,0,100,0),
(@PATH,20,-763.0795,5961.114,18.29157,0,0,0,0,100,0);
