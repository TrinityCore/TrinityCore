-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314431;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8662.466,`position_y`=459.6389,`position_z`=137.3642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8662.466, 459.6389, 137.3642,0,0,1,0,100,0),
(@PATH,2,-8605.771, 511.8924, 137.1582,0,0,1,0,100,0),
(@PATH,3,-8554.219, 555.0625, 131.4193,0,0,1,0,100,0),
(@PATH,4,-8519.203, 612.4913, 134.9834,0,0,1,0,100,0),
(@PATH,5,-8553.771, 712.4930, 140.2446,0,0,1,0,100,0),
(@PATH,6,-8603.802, 767.9948, 132.6537,0,0,1,0,100,0),
(@PATH,7,-8680.964, 730.2864, 143.9079,0,0,1,0,100,0),
(@PATH,8,-8822.661, 607.3577, 127.0456,0,0,1,0,100,0),
(@PATH,9,-8725.741, 449.1076, 136.5916,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314461;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8439.601,`position_y`=624.75,`position_z`=150.5282 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8439.601, 624.75, 150.5282,0,0,1,0,100,0),
(@PATH,2,-8487.333, 714.9149, 141.1533,0,0,1,0,100,0),
(@PATH,3,-8522.524, 753.908, 141.1533,0,0,1,0,100,0),
(@PATH,4,-8573.207, 814.5313, 141.1533,0,0,1,0,100,0),
(@PATH,5,-8610.96, 858.3299, 141.1533,0,0,1,0,100,0),
(@PATH,6,-8659.504, 877.3004, 141.1533,0,0,1,0,100,0),
(@PATH,7,-8808.146, 878.9827, 143.132,0,0,1,0,100,0),
(@PATH,8,-8919.663, 891.7136, 145.7839,0,0,1,0,100,0),
(@PATH,9,-8967.993, 866.4601, 143.3446,0,0,1,0,100,0),
(@PATH,10,-8968.46, 813.1979, 146.712,0,0,1,0,100,0),
(@PATH,11,-8874.938, 798.1684, 142.2095,0,0,1,0,100,0),
(@PATH,12,-8704.104, 785.7535, 142.2095,0,0,1,0,100,0),
(@PATH,13,-8619.591, 766.4514, 142.2095,0,0,1,0,100,0),
(@PATH,14,-8606.348, 686.9618, 142.2095,0,0,1,0,100,0),
(@PATH,15,-8556.601, 566.1354, 142.2095,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314418;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8557.021,`position_y`=700.4496,`position_z`=202.7837 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8557.021, 700.4496, 202.7837,0,0,1,0,100,0),
(@PATH, 2, -8396.585, 1045.873, 190.7067,0,0,1,0,100,0),
(@PATH, 3, -8655.849, 964.5104, 190.7067,0,0,1,0,100,0),
(@PATH, 4, -8731.622, 715.1285, 190.7067,0,0,1,0,100,0),
(@PATH, 5, -8601.832, 463.0347, 209.6767,0,0,1,0,100,0),
(@PATH, 6, -8483.486, 516.7639, 199.3549,0,0,1,0,100,0),
(@PATH, 7, -8401.893, 643.1545, 198.0135,0,0,1,0,100,0),
(@PATH, 8, -8245.486, 984.8472, 194.3686,0,0,1,0,100,0),
(@PATH, 9, -8170.418, 1178.47, 133.457,0,0,1,0,100,0),
(@PATH, 10, -8213.81, 1307.231, 132.4081,0,0,1,0,100,0),
(@PATH, 11, -8446.116, 1279.844, 124.3795,0,0,1,0,100,0),
(@PATH, 12, -8657.575, 1180.333, 159.3412,0,0,1,0,100,0),
(@PATH, 13, -8835.462, 1052.523, 173.4163,0,0,1,0,100,0),
(@PATH, 14, -8897.589, 790.6129, 186.8726,0,0,1,0,100,0),
(@PATH, 15, -8704.488, 463.066, 201.0162,0,0,1,0,100,0),
(@PATH, 16, -8615.969, 448.533, 206.5423,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314505;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8733.926,`position_y`=621.0643,`position_z`=145.5585 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8733.926, 621.0643, 145.5585,0,0,1,0,100,0),
(@PATH, 2, -8633.138, 668.132, 142.7698,0,0,1,0,100,0),
(@PATH, 3, -8530.951, 750.5746, 150.9892,0,0,1,0,100,0),
(@PATH, 4, -8488.743, 827.1528, 157.2262,0,0,1,0,100,0),
(@PATH, 5, -8529.739, 890.0399, 149.7343,0,0,1,0,100,0),
(@PATH, 6, -8578.462, 888.9601, 145.8967,0,0,1,0,100,0),
(@PATH, 7, -8616.542, 873.8524, 145.8967,0,0,1,0,100,0),
(@PATH, 8, -8649.06, 837.0104, 145.8967,0,0,1,0,100,0),
(@PATH, 9, -8637.366, 765.342, 145.8967,0,0,1,0,100,0),
(@PATH, 10, -8757.427, 685.4861, 145.8967,0,0,1,0,100,0),
(@PATH, 11, -8913.278, 603.2639, 185.2889,0,0,1,0,100,0),
(@PATH, 12, -8977.022, 524.0643, 185.2889,0,0,1,0,100,0),
(@PATH, 13, -8946.656, 480.6129, 185.2889,0,0,1,0,100,0),
(@PATH, 14, -8859.899, 534.0625, 170.2515,0,0,1,0,100,0),
(@PATH, 15, -8814.005, 563.5521, 151.9333,0,0,1,0,100,0),
(@PATH, 16, -8770.842, 596.7448, 145.6159,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314021;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9017.339,`position_y`=933.632,`position_z`=160.745 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1,-9017.339, 933.632, 160.745,0,0,1,0,100,0),
(@PATH, 2,-8909.113, 836.158, 152.7462,0,0,1,0,100,0),
(@PATH, 3,-8948.451, 771.125, 152.7462,0,0,1,0,100,0),
(@PATH, 4,-9004.389, 804.9254, 152.7462,0,0,1,0,100,0),
(@PATH, 5,-9014.457, 848.2379, 152.7462,0,0,1,0,100,0),
(@PATH, 6,-8957.578, 844.9948, 152.7462,0,0,1,0,100,0),
(@PATH, 7,-8849.056, 873.1059, 152.7462,0,0,1,0,100,0),
(@PATH, 8,-8826.819, 832.684, 152.7462,0,0,1,0,100,0),
(@PATH, 9,-8824.623, 782.1371, 152.7462,0,0,1,0,100,0),
(@PATH, 10,-8853.991, 763.3715, 152.7462,0,0,1,0,100,0),
(@PATH, 11,-8883.712, 802.0538, 144.0378,0,0,1,0,100,0),
(@PATH, 12,-8890.04, 847.4114, 140.2835,0,0,1,0,100,0),
(@PATH, 13,-8935.929, 902.1094, 144.7429,0,0,1,0,100,0),
(@PATH, 14,-8990.004, 968.4583, 163.7031,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314224;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8877.583,`position_y`=683.8333,`position_z`=133.6176 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8877.583, 683.8333, 133.6176,0,0,1,0,100,0),
(@PATH, 2, -8826.826, 580.1805, 126.1607,0,0,1,0,100,0),
(@PATH, 3, -8761.734, 485.974, 133.1795,0,0,1,0,100,0),
(@PATH, 4, -8708.62, 420.6927, 140.962,0,0,1,0,100,0),
(@PATH, 5, -8653.629, 413.9705, 148.6133,0,0,1,0,100,0),
(@PATH, 6, -8625.649, 443.4167, 151.1309,0,0,1,0,100,0),
(@PATH, 7, -8701.297, 550.9028, 138.3121,0,0,1,0,100,0),
(@PATH, 8, -8821.203, 704.5938, 142.4744,0,0,1,0,100,0),
(@PATH, 9, -8949.476, 844.5799, 146.7548,0,0,1,0,100,0),
(@PATH, 10, -9004.799, 815.8073, 148.9838,0,0,1,0,100,0),
(@PATH, 11, -8957.052, 747.3768, 155.1606,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314120;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8866.703,`position_y`=597.2986,`position_z`=142.0205 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8866.703, 597.2986, 142.0205,0,0,1,0,100,0),
(@PATH, 2, -8862.526, 590.6354, 142.4193,0,0,1,0,100,0),
(@PATH, 3, -8801.051, 501.2396, 147.1693,0,0,1,0,100,0),
(@PATH, 4, -8716.939, 459.8802, 175.4137,0,0,1,0,100,0),
(@PATH, 5, -8629.266, 415.6458, 227.9224,0,0,1,0,100,0),
(@PATH, 6, -8577.285, 400.4826, 245.2455,0,0,1,0,100,0),
(@PATH, 7, -8579.844, 357.7309, 228.3491,0,0,1,0,100,0),
(@PATH, 8, -8626.583, 362.5799, 206.0479,0,0,1,0,100,0),
(@PATH, 9, -8619.036, 407.8281, 195.2388,0,0,1,0,100,0),
(@PATH, 10, -8569.106, 426.9375, 181.514,0,0,1,0,100,0),
(@PATH, 11, -8506.353, 451.1042, 169.8915,0,0,1,0,100,0),
(@PATH, 12, -8436.903, 450.9583, 186.9168,0,0,1,0,100,0),
(@PATH, 13, -8360.396, 365.6146, 225.0629,0,0,1,0,100,0),
(@PATH, 14, -8324.521, 252.8576, 287.2484,0,0,1,0,100,0),
(@PATH, 15, -8367.212, 207.2569, 300.4694,0,0,1,0,100,0),
(@PATH, 16, -8410.299, 224.1944, 278.7091,0,0,1,0,100,0),
(@PATH, 17, -8399.939, 276.401, 247.6331,0,0,1,0,100,0),
(@PATH, 18, -8318.911, 306.375, 207.1502,0,0,1,0,100,0),
(@PATH, 19, -8207.629, 422.8142, 145.6021,0,0,1,0,100,0),
(@PATH, 20, -8247.208, 533.9983, 148.9318,0,0,1,0,100,0),
(@PATH, 21, -8276.895, 613.6511, 153.4474,0,0,1,0,100,0),
(@PATH, 22, -8397.348, 588.2639, 138.2286,0,0,1,0,100,0),
(@PATH, 23, -8536.107, 485.9566, 143.2422,0,0,1,0,100,0),
(@PATH, 24, -8696.92, 421.2639, 140.8822,0,0,1,0,100,0),
(@PATH, 25, -8787.848, 632.7864, 134.5134,0,0,1,0,100,0),
(@PATH, 26, -8797.828, 821.5104, 162.8442,0,0,1,0,100,0),
(@PATH, 27, -8873.406, 964.2847, 170.3814,0,0,1,0,100,0),
(@PATH, 28, -8936.486, 988.684, 159.8252,0,0,1,0,100,0),
(@PATH, 29, -9050.551, 904.8333, 167.9251,0,0,1,0,100,0),
(@PATH, 30, -9063.879, 860.3195, 169.0243,0,0,1,0,100,0),
(@PATH, 31, -9020.333, 818.0712, 164.4866,0,0,1,0,100,0),
(@PATH, 32, -8954.995, 744.6198, 159.8545,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314412;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8718.011,`position_y`=460.5035,`position_z`=139.3858 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8718.011, 460.5035, 139.3858,0,0,1,0,100,0),
(@PATH, 2, -8794.645, 345.9496, 189.6799,0,0,1,0,100,0),
(@PATH, 3, -8743.56, 309.9583, 164.2667,0,0,1,0,100,0),
(@PATH, 4, -8692.627, 366.066, 146.7253,0,0,1,0,100,0),
(@PATH, 5, -8634.229, 438.8681, 143.9013,0,0,1,0,100,0),
(@PATH, 6, -8475.569, 555.4254, 139.9419,0,0,1,0,100,0),
(@PATH, 7, -8325.558, 639.7153, 136.0228,0,0,1,0,100,0),
(@PATH, 8, -8313.203, 716.3524, 150.0648,0,0,1,0,100,0),
(@PATH, 9, -8397.439, 707.875, 146.6102,0,0,1,0,100,0),
(@PATH, 10, -8459.971, 660.6302, 146.2827,0,0,1,0,100,0),
(@PATH, 11, -8563.607, 574.5886, 141.8899,0,0,1,0,100,0);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 314462;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8699.545,`position_y`=937.3351,`position_z`=137.8757 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-8699.545,`position_y`=937.3351,`position_z`=137.8757 WHERE `guid`=314450;
UPDATE `creature` SET `position_x`=-8699.545,`position_y`=937.3351,`position_z`=137.8757 WHERE `guid`=314451;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8699.545, 937.3351, 137.8757,0,0,1,0,100,0),
(@PATH, 2, -8688.927, 744.2813, 137.8757,0,0,1,0,100,0),
(@PATH, 3, -8501.759, 616.5121, 148.3169,0,0,1,0,100,0),
(@PATH, 4, -8166.518, 462.6892, 188.4799,0,0,1,0,100,0),
(@PATH, 5, -8187.979, 317.467, 196.3669,0,0,1,0,100,0),
(@PATH, 6, -8395.191, 456.967, 202.8917,0,0,1,0,100,0),
(@PATH, 7, -8632.31, 595.4618, 200.7379,0,0,1,0,100,0),
(@PATH, 8, -8710.141, 622.4427, 175.7884,0,0,1,0,100,0),
(@PATH, 9, -8766.325, 696.184, 172.7322,0,0,1,0,100,0),
(@PATH, 10, -8787.95, 822.1996, 172.7322,0,0,1,0,100,0),
(@PATH, 11, -8863.689, 965.5799, 183.0082,0,0,1,0,100,0),
(@PATH, 12, -8965.31, 958.8837, 172.7322,0,0,1,0,100,0),
(@PATH, 13, -8933.082, 841.6059, 167.7035,0,0,1,0,100,0),
(@PATH, 14, -8847.278, 583.0608, 167.7035,0,0,1,0,100,0),
(@PATH, 15, -8837.466, 418.9583, 188.4867,0,0,1,0,100,0),
(@PATH, 16, -8812.62, 343.2639, 188.4867,0,0,1,0,100,0),
(@PATH, 17, -8657.95, 461.092, 148.253,0,0,1,0,100,0),
(@PATH, 18, -8637.933, 477.7865, 144.4239,0,0,1,0,100,0),
(@PATH, 19, -8611.147, 499.7865, 141.4831,0,0,1,0,100,0),
(@PATH, 20, -8543.81, 547.1875, 141.4831,0,0,1,0,100,0),
(@PATH, 21, -8427.136, 566.0764, 141.4831,0,0,1,0,100,0),
(@PATH, 22, -8394.967, 659.3958, 141.4831,0,0,1,0,100,0),
(@PATH, 23, -8547.891, 695.3316, 141.4831,0,0,1,0,100,0),
(@PATH, 24, -8554.257, 785.4375, 154.3844,0,0,1,0,100,0),
(@PATH, 25, -8604.158, 853.5399, 141.4831,0,0,1,0,100,0),
(@PATH, 26, -8528.238, 922.757, 141.4831,0,0,1,0,100,0),
(@PATH, 27, -8424.458, 1094.677, 57.04519,0,0,1,0,100,0),
(@PATH, 28, -8413.158, 1268.925, 57.04519,0,0,1,0,100,0),
(@PATH, 29, -8618.082, 1300.694, 57.04519,0,0,1,0,100,0),
(@PATH, 30, -8751.545, 1084.252, 102.8397,0,0,1,0,100,0);

-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=314462;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(314462,314462,0,0,2),
(314462,314450,5,90,2),
(314462,314451,5,270,2);

-- Pathing for Stormwind Gryphon Rider Entry: 51348 'TDB FORMAT' 
SET @NPC := 313936;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8985.317,`position_y`=666.3455,`position_z`=170.0036 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-8985.317,`position_y`=666.3455,`position_z`=170.0036 WHERE `guid`=313925;
UPDATE `creature` SET `position_x`=-8985.317,`position_y`=666.3455,`position_z`=170.0036 WHERE `guid`=313926;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,27913,50331648,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, -8985.317, 666.3455, 170.0036,0,0,1,0,100,0),
(@PATH, 2, -8999.299, 570.559, 146.6491,0,0,1,0,100,0),
(@PATH, 3, -9053.177, 482.4601, 153.1192,0,0,1,0,100,0),
(@PATH, 4, -9063.229, 461.7257, 152.3779,0,0,1,0,100,0),
(@PATH, 5, -9056.779, 448.6771, 152.1349,0,0,1,0,100,0),
(@PATH, 6, -9025.438, 388.7135, 158.4061,0,0,1,0,100,0),
(@PATH, 7, -8931.455, 447.842, 107.1997,0,0,1,0,100,0),
(@PATH, 8, -8854.339, 496.5121, 170.0036,0,0,1,0,100,0),
(@PATH, 9, -8922.739, 620.0313, 170.0036,0,0,1,0,100,0),
(@PATH, 10, -8985.317, 666.3455, 170.0036,0,0,1,0,100,0),
(@PATH, 11, -8999.299, 570.559, 146.6491,0,0,1,0,100,0),
(@PATH, 12, -9053.177, 482.4601, 153.1192,0,0,1,0,100,0);

-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=313936;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(313936,313936,0,0,2),
(313936,313925,5,90,2),
(313936,313926,5,270,2);
