-- Ebon Blade Gargoyle
SET @NPC := 124428;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=8487.13,`position_y`=2648.587,`position_z`=661.3248,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,8487.13,2648.587,661.3248,0,0,0,100,0),
(@PATH,2,8489.394,2639.188,661.9919,0,0,0,100,0),
(@PATH,3,8498.239,2633.008,661.9919,0,0,0,100,0),
(@PATH,4,8514.016,2626.775,661.9919,0,0,0,100,0),
(@PATH,5,8529.975,2622.438,661.9919,0,0,0,100,0),
(@PATH,6,8556.946,2621.273,661.9919,0,0,0,100,0),
(@PATH,7,8576.765,2620.136,661.9919,0,0,0,100,0),
(@PATH,8,8584.989,2627.947,663.3527,0,0,0,100,0),
(@PATH,9,8590.352,2637.264,664.2969,0,0,0,100,0),
(@PATH,10,8597.313,2651.073,666.0464,0,0,0,100,0),
(@PATH,11,8590.045,2668.078,668.6855,0,0,0,100,0),
(@PATH,12,8577.563,2672.175,668.6855,0,0,0,100,0),
(@PATH,13,8567.869,2653.686,668.6855,0,0,0,100,0),
(@PATH,14,8559.406,2635.763,668.6855,0,0,0,100,0),
(@PATH,15,8550.115,2624.132,664.6028,0,0,0,100,0),
(@PATH,16,8538.325,2625.415,664.6028,0,0,0,100,0),
(@PATH,17,8531.294,2636.344,664.6028,0,0,0,100,0),
(@PATH,18,8536.005,2650.634,664.6028,0,0,0,100,0),
(@PATH,19,8536.659,2661.533,667.5744,0,0,0,100,0),
(@PATH,20,8528.161,2665.466,668.5468,0,0,0,100,0),
(@PATH,21,8521.834,2666.234,668.9914,0,0,0,100,0),
(@PATH,22,8506.145,2657.156,666.1024,0,0,0,100,0);

-- Ebon Blade Gargoyle
SET @NPC := 124429;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=8553.722,`position_y`=2732.757,`position_z`=672.1373,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,8553.722,2732.757,672.1373,0,0,0,100,0),
(@PATH,2,8545.085,2736.81,677.1306,0,0,0,100,0),
(@PATH,3,8538.377,2724.997,676.7698,0,0,0,100,0),
(@PATH,4,8527.725,2701.114,677.464,0,0,0,100,0),
(@PATH,5,8515.729,2672.526,676.4364,0,0,0,100,0),
(@PATH,6,8501.882,2638.781,674.6306,0,0,0,100,0),
(@PATH,7,8492.601,2619.312,672.9641,0,0,0,100,0),
(@PATH,8,8501.216,2604.361,672.7973,0,0,0,100,0),
(@PATH,9,8509.95,2597.643,672.464,0,0,0,100,0),
(@PATH,10,8516.437,2603.336,670.7147,0,0,0,100,0),
(@PATH,11,8526.045,2624.93,675.242,0,0,0,100,0),
(@PATH,12,8538.438,2654.096,677.4644,0,0,0,100,0),
(@PATH,13,8552.567,2688.411,676.0737,0,0,0,100,0),
(@PATH,14,8561.252,2709.44,676.1867,0,0,0,100,0),
(@PATH,15,8564.74,2718.366,676.9643,0,0,0,100,0),
(@PATH,16,8586.875,2713.758,677.4359,0,0,0,100,0),
(@PATH,17,8588.923,2702.79,676.2701,0,0,0,100,0),
(@PATH,18,8580.09,2682.738,673.3813,0,0,0,100,0),
(@PATH,19,8572.153,2664.409,674.4087,0,0,0,100,0),
(@PATH,20,8559.122,2635.23,674.5473,0,0,0,100,0),
(@PATH,21,8547.672,2610.971,677.3528,0,0,0,100,0),
(@PATH,22,8547.112,2593.927,677.77,0,0,0,100,0),
(@PATH,23,8556.546,2591.858,678.7695,0,0,0,100,0),
(@PATH,24,8566.203,2601.376,677.2705,0,0,0,100,0),
(@PATH,25,8576.512,2615.707,675.7764,0,0,0,100,0),
(@PATH,26,8585.419,2632.535,673.7208,0,0,0,100,0),
(@PATH,27,8596.079,2656.51,673.0544,0,0,0,100,0),
(@PATH,28,8594.222,2669.849,673.4442,0,0,0,100,0),
(@PATH,29,8595.935,2690.9,673.4711,0,0,0,100,0),
(@PATH,30,8592.354,2705.919,675.5258,0,0,0,100,0),
(@PATH,31,8571.288,2721.3,668.0258,0,0,0,100,0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=32472;

-- Vargul Plaguetalon
SET @NPC := 97634;
SET @PATH := @NPC*10;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=29453;
UPDATE `creature` SET `position_x`=5736.421,`position_y`=-1453.626,`position_z`=267.5013,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,5736.421,-1453.626,267.5013,0,0,0,100,0),
(@PATH,2,5700.896,-1467.002,263.9736,0,0,0,100,0),
(@PATH,3,5665.086,-1462.814,266.2513,0,0,0,100,0),
(@PATH,4,5623.596,-1446.303,258.3903,0,0,0,100,0),
(@PATH,5,5612.131,-1390.983,269.9736,0,0,0,100,0),
(@PATH,6,5630.01,-1325.786,252.9459,0,0,0,100,0),
(@PATH,7,5684.276,-1301.843,263.9736,0,0,0,100,0),
(@PATH,8,5717.019,-1325.604,263.9736,0,0,0,100,0),
(@PATH,9,5730.931,-1363.826,254.0014,0,0,0,100,0),
(@PATH,10,5737.854,-1429.533,273.2791,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121011;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6805.096,`position_y`=3548.115,`position_z`=785.0337,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6805.096,3548.115,785.0337,0,0,0,100,0),
(@PATH,2,6797.807,3599.297,776.1726,0,0,0,100,0),
(@PATH,3,6840.798,3607.1,769.2557,0,0,0,100,0),
(@PATH,4,6880.369,3577.403,779.5615,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121023;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6490.46,`position_y`=3498.933,`position_z`=621.7417,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6490.46,3498.933,621.7417,0,0,0,100,0),
(@PATH,2,6645.542,3512.415,678.8528,0,0,0,100,0),
(@PATH,3,6650.367,3555.357,680.6584,0,0,0,100,0),
(@PATH,4,6602.724,3563.045,661.1863,0,0,0,100,0),
(@PATH,5,6549.287,3554.462,642.825,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121019;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6653.509,`position_y`=3526.14,`position_z`=693.2337,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6653.509,3526.14,693.2337,0,0,0,100,0),
(@PATH,2,6696.053,3579.272,700.4001,0,0,0,100,0),
(@PATH,3,6744.93,3562.146,704.2611,0,0,0,100,0),
(@PATH,4,6738.125,3521.812,692.5392,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121017;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6653.104,`position_y`=3415.26,`position_z`=672.1595,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6653.104,3415.26,672.1595,0,0,0,100,0),
(@PATH,2,6717.518,3468.886,684.6567,0,0,0,100,0),
(@PATH,3,6771.674,3492.333,692.0456,0,0,0,100,0),
(@PATH,4,6728.592,3518.536,683.6566,0,0,0,100,0),
(@PATH,5,6627.954,3487.869,642.6566,0,0,0,100,0),
(@PATH,6,6571.027,3439.741,634.3512,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121014;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6641.402,`position_y`=3330.479,`position_z`=724.3008,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6641.402,3330.479,724.3008,0,0,0,100,0),
(@PATH,2,6637.165,3426.095,701.4395,0,0,0,100,0),
(@PATH,3,6701.476,3449.434,708.6896,0,0,0,100,0),
(@PATH,4,6746.966,3410.158,735.9395,0,0,0,100,0),
(@PATH,5,6697.637,3352.607,725.0784,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121025;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6590.307,`position_y`=3325.47,`position_z`=699.1288,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6590.307,3325.47,699.1288,0,0,0,100,0),
(@PATH,2,6543.557,3237.147,706.6288,0,0,0,100,0),
(@PATH,3,6518.691,3250.313,687.6565,0,0,0,100,0),
(@PATH,4,6512.266,3334.911,685.3231,0,0,0,100,0);

-- Scourgebeak Fleshripper
SET @NPC := 121007;
SET @PATH := @NPC*10;
UPDATE `creature` SET `position_x`=6459.715,`position_y`=3049.952,`position_z`=701.608,`spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`) VALUES (@NPC,@PATH,50331648,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUE
(@PATH,1,6459.715,3049.952,701.608,0,0,0,100,0),
(@PATH,2,6485.836,3103.517,681.247,0,0,0,100,0),
(@PATH,3,6445.593,3154.588,677.886,0,0,0,100,0),
(@PATH,4,6392.533,3078.925,694.2471,0,0,0,100,0);
