-- Remove some waypoint errors
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (57763,57764,57765,57766);
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (57763,57764,57765,57766);
DELETE FROM `waypoint_data` WHERE `id` IN (577630,577640,577650,577660);
DELETE FROM `waypoint_scripts` WHERE `id` IN (48,49,50,51);

-- Mature Netherwing Drake Pathing From sniff 1 added.
SET @NPC := 75541;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4134.369,`position_y`=850.2852,`position_z`=61.26378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4120.351,883.5854,61.26378,0,0,0,100,0),
(@PATH,2,-4085.13,900.4695,61.26378,0,0,0,100,0),
(@PATH,3,-4048.586,884.7811,61.26378,0,0,0,100,0),
(@PATH,4,-4033.683,852.1551,61.26378,0,0,0,100,0),
(@PATH,5,-4050.652,818.6749,61.26378,0,0,0,100,0),
(@PATH,6,-4085.118,799.5022,61.26378,0,0,0,100,0),
(@PATH,7,-4117.451,815.256,61.26378,0,0,0,100,0),
(@PATH,8,-4134.369,850.2852,61.26378,0,0,0,100,0);

SET @NPC := 75542;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4066.473,`position_y`=752.3994,`position_z`=43.04424 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4083.436,721.6484,43.04424,0,0,0,100,0),
(@PATH,2,-4109.103,700.2794,43.04424,0,0,0,100,0),
(@PATH,3,-4114.49,699.9313,43.04424,0,0,0,100,0),
(@PATH,4,-4149.18,716.9812,43.04424,0,0,0,100,0),
(@PATH,5,-4164.394,749.7984,44.87757,0,0,0,100,0),
(@PATH,6,-4147.782,783.0017,46.62758,0,0,0,100,0),
(@PATH,7,-4117.128,799.6888,51.93314,0,0,0,100,0),
(@PATH,8,-4082.698,785.6704,50.3498,0,0,0,100,0),
(@PATH,9,-4066.473,752.3994,43.04424,0,0,0,100,0);

SET @NPC := 75543;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4148.391,`position_y`=766.8653,`position_z`=66.01289 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4183.416,753.0403,72.09624,0,0,0,100,0),
(@PATH,2,-4199.977,716.2882,82.67956,0,0,0,100,0),
(@PATH,3,-4183.724,684.1388,70.56844,0,0,0,100,0),
(@PATH,4,-4148.917,666.9986,63.51288,0,0,0,100,0),
(@PATH,5,-4116.004,684.5375,61.51288,0,0,0,100,0),
(@PATH,6,-4099.94,716.4078,62.09623,0,0,0,100,0),
(@PATH,7,-4116.647,749.6686,61.59621,0,0,0,100,0),
(@PATH,8,-4148.391,766.8653,66.01289,0,0,0,100,0);

SET @NPC := 75544;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4084.089,`position_y`=683.0483,`position_z`=59.55887 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4067.996,652.302,59.55887,0,0,0,100,0),
(@PATH,2,-4084.038,618.9259,59.55887,0,0,0,100,0),
(@PATH,3,-4117.386,599.9404,59.55887,0,0,0,100,0),
(@PATH,4,-4149.88,616.7292,59.55887,0,0,0,100,0),
(@PATH,5,-4165.804,652.2473,59.55887,0,0,0,100,0),
(@PATH,6,-4150.054,685.6966,59.55887,0,0,0,100,0),
(@PATH,7,-4118.107,699.7501,59.55887,0,0,0,100,0),
(@PATH,8,-4084.089,683.0483,59.55887,0,0,0,100,0);

SET @NPC := 75545;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4083.681,`position_y`=848.0616,`position_z`=58.43416 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4117.843,866.6574,58.43417,0,0,0,100,0),
(@PATH,2,-4149.746,851.1995,68.6286,0,0,0,100,0),
(@PATH,3,-4167.114,815.8797,74.48971,0,0,0,100,0),
(@PATH,4,-4150.918,786.3128,65.07306,0,0,0,100,0),
(@PATH,5,-4116.956,766.7995,70.51749,0,0,0,100,0),
(@PATH,6,-4085.521,784.5572,76.90639,0,0,0,100,0),
(@PATH,7,-4067.243,818.4576,64.35083,0,0,0,100,0),
(@PATH,8,-4083.681,848.0616,58.43416,0,0,0,100,0);

SET @NPC := 75546;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4133.319,`position_y`=918.6325,`position_z`=70.3725 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4117.341,884.8878,62.09472,0,0,0,100,0),
(@PATH,2,-4084.125,867.1631,52.70584,0,0,0,100,0),
(@PATH,3,-4050.462,883.2648,46.84472,0,0,0,100,0),
(@PATH,4,-4033.427,917.2786,54.8725,0,0,0,100,0),
(@PATH,5,-4049.515,951.7986,62.20583,0,0,0,100,0),
(@PATH,6,-4082.625,966.6864,69.48361,0,0,0,100,0),
(@PATH,7,-4116.243,949.7843,72.2614,0,0,0,100,0),
(@PATH,8,-4133.319,918.6325,70.3725,0,0,0,100,0);

SET @NPC := 75547;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4000.944,`position_y`=650.089,`position_z`=84.74791 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4015.128,680.8443,72.16458,0,0,0,100,0),
(@PATH,2,-4047.654,700.2465,60.27572,0,0,0,100,0),
(@PATH,3,-4082.378,686.9391,58.8868,0,0,0,100,0),
(@PATH,4,-4099.23,649.127,67.30346,0,0,0,100,0),
(@PATH,5,-4083.47,615.1847,74.74792,0,0,0,100,0),
(@PATH,6,-4047.911,600.5391,92.52572,0,0,0,100,0),
(@PATH,7,-4016.922,616.1044,98.47014,0,0,0,100,0),
(@PATH,8,-4000.944,650.089,84.74791,0,0,0,100,0);

SET @NPC := 75548;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4052.34,`position_y`=716.3079,`position_z`=48.66938 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4019.384,700.1765,47.08604,0,0,0,100,0),
(@PATH,2,-3983.657,716.8768,52.75271,0,0,0,100,0),
(@PATH,3,-3967.16,750.4713,65.47495,0,0,0,100,0),
(@PATH,4,-3982.856,783.4985,67.83604,0,0,0,100,0),
(@PATH,5,-4017.322,800.1605,65.75271,0,0,0,100,0),
(@PATH,6,-4048.333,784.6697,60.58604,0,0,0,100,0),
(@PATH,7,-4067.148,750.3481,53.25271,0,0,0,100,0),
(@PATH,8,-4052.34,716.3079,48.66938,0,0,0,100,0);

SET @NPC := 75549;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3949.365,`position_y`=819.178,`position_z`=51.50261 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3933.805,784.3923,51.50261,0,0,0,100,0),
(@PATH,2,-3951.698,751.0433,51.50261,0,0,0,100,0),
(@PATH,3,-3980.543,733.1439,58.86372,0,0,0,100,0),
(@PATH,4,-4016.032,747.1483,64.55817,0,0,0,100,0),
(@PATH,5,-4032.366,782.211,60.08595,0,0,0,100,0),
(@PATH,6,-4017.203,816.9814,53.30817,0,0,0,100,0),
(@PATH,7,-3985.723,832.2205,51.50261,0,0,0,100,0),
(@PATH,8,-3949.365,819.178,51.50261,0,0,0,100,0);

SET @NPC := 75550;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3916.397,`position_y`=883.2978,`position_z`=81.9971 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3948.779,899.8286,68.13598,0,0,0,100,0),
(@PATH,2,-3982.235,885.5906,61.1082,0,0,0,100,0),
(@PATH,3,-3999.414,851.4448,62.69153,0,0,0,100,0),
(@PATH,4,-3983.74,817.0834,58.96931,0,0,0,100,0),
(@PATH,5,-3950.159,800.5572,63.10819,0,0,0,100,0),
(@PATH,6,-3918.94,815.5467,72.46931,0,0,0,100,0),
(@PATH,7,-3900.264,851.1897,81.30264,0,0,0,100,0),
(@PATH,8,-3916.397,883.2978,81.9971,0,0,0,100,0);

SET @NPC := 75551;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4084.883,`position_y`=914.0491,`position_z`=72.2939 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4099.644,950.2539,69.2939,0,0,0,100,0),
(@PATH,2,-4086.421,983.3143,71.12724,0,0,0,100,0),
(@PATH,3,-4050.086,1000.082,74.32168,0,0,0,100,0),
(@PATH,4,-4018.68,983.5675,74.32168,0,0,0,100,0),
(@PATH,5,-4001.11,950.1692,74.32168,0,0,0,100,0),
(@PATH,6,-4016.584,917.4998,74.32168,0,0,0,100,0),
(@PATH,7,-4048.498,899.8286,74.32168,0,0,0,100,0),
(@PATH,8,-4084.883,914.0491,72.2939,0,0,0,100,0);

SET @NPC := 75552;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3915.657,`position_y`=833.4163,`position_z`=47.38418 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3948.898,849.9359,47.38418,0,0,0,100,0),
(@PATH,2,-3964.938,879.6131,47.38418,0,0,0,100,0),
(@PATH,3,-3948.945,916.1858,47.38418,0,0,0,100,0),
(@PATH,4,-3916.809,932.6107,48.16196,0,0,0,100,0),
(@PATH,5,-3886.793,916.5725,53.96752,0,0,0,100,0),
(@PATH,6,-3866.807,883.3404,60.02308,0,0,0,100,0),
(@PATH,7,-3884.739,849.9593,54.30085,0,0,0,100,0),
(@PATH,8,-3915.657,833.4163,47.38418,0,0,0,100,0);

SET @NPC := 75553;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4047.742,`position_y`=1066.566,`position_z`=106.1299 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4082.141,1050.517,104.5466,0,0,0,100,0),
(@PATH,2,-4099.718,1017.106,98.4355,0,0,0,100,0),
(@PATH,3,-4082.201,985.4608,87.46328,0,0,0,100,0),
(@PATH,4,-4048.188,966.8837,78.15773,0,0,0,100,0),
(@PATH,5,-4017.819,980.5856,72.37994,0,0,0,100,0),
(@PATH,6,-4000.326,1016.784,86.21326,0,0,0,100,0),
(@PATH,7,-4014.791,1050.645,97.40771,0,0,0,100,0),
(@PATH,8,-4047.742,1066.566,106.1299,0,0,0,100,0);

SET @NPC := 75554;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3900.323,`position_y`=984.7424,`position_z`=60.60864 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3918.999,953.8466,58.96975,0,0,0,100,0),
(@PATH,2,-3950.793,934.2088,58.96975,0,0,0,100,0),
(@PATH,3,-3982.866,950.2649,58.96975,0,0,0,100,0),
(@PATH,4,-4000.046,985.8019,61.02531,0,0,0,100,0),
(@PATH,5,-3981.982,1017.846,58.96975,0,0,0,100,0),
(@PATH,6,-3949.962,1033.053,56.85864,0,0,0,100,0),
(@PATH,7,-3918.825,1014.746,58.33086,0,0,0,100,0),
(@PATH,8,-3900.323,984.7424,60.60864,0,0,0,100,0);

SET @NPC := 75555;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3950.083,`position_y`=985.4277,`position_z`=83.53654 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3965.832,952.775,76.7032,0,0,0,100,0),
(@PATH,2,-3951.587,918.8143,71.53653,0,0,0,100,0),
(@PATH,3,-3916.848,899.7321,72.39764,0,0,0,100,0),
(@PATH,4,-3885.93,916.5598,83.34209,0,0,0,100,0),
(@PATH,5,-3867.241,951.6891,90.39765,0,0,0,100,0),
(@PATH,6,-3882.38,983.3097,81.48098,0,0,0,100,0),
(@PATH,7,-3915.022,1000.09,72.17542,0,0,0,100,0),
(@PATH,8,-3950.083,985.4277,83.53654,0,0,0,100,0);

SET @NPC := 75556;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3966.719,`position_y`=1048.378,`position_z`=69.52766 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3983.504,1016.722,67.94434,0,0,0,100,0),
(@PATH,2,-4015.046,1002.573,69.52766,0,0,0,100,0),
(@PATH,3,-4049.708,1017.723,72.13878,0,0,0,100,0),
(@PATH,4,-4066.48,1048.968,72.66656,0,0,0,100,0),
(@PATH,5,-4048.204,1083.848,71.19434,0,0,0,100,0),
(@PATH,6,-4016.47,1100.259,72.47211,0,0,0,100,0),
(@PATH,7,-3985.822,1082.684,70.97211,0,0,0,100,0),
(@PATH,8,-3966.719,1048.378,69.52766,0,0,0,100,0);

SET @NPC := 75557;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3950.767,`position_y`=1000.512,`position_z`=87.49402 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3918.137,1015.368,90.16069,0,0,0,100,0),
(@PATH,2,-3900.402,1050.901,91.7718,0,0,0,100,0),
(@PATH,3,-3917.262,1083.885,99.32737,0,0,0,100,0),
(@PATH,4,-3949.68,1100.575,106.7718,0,0,0,100,0),
(@PATH,5,-3981.045,1082.341,107.8829,0,0,0,100,0),
(@PATH,6,-3999.798,1048.804,99.57736,0,0,0,100,0),
(@PATH,7,-3985.399,1018.346,91.7718,0,0,0,100,0),
(@PATH,8,-3950.767,1000.512,87.49402,0,0,0,100,0);

SET @NPC := 75558;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4066.473,`position_y`=752.3994,`position_z`=43.04424 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4083.436,721.6484,43.04424,0,0,0,100,0),
(@PATH,2,-4109.103,700.2794,43.04424,0,0,0,100,0),
(@PATH,3,-4114.49,699.9313,43.04424,0,0,0,100,0),
(@PATH,4,-4149.18,716.9812,43.04424,0,0,0,100,0),
(@PATH,5,-4164.394,749.7984,44.87757,0,0,0,100,0),
(@PATH,6,-4147.782,783.0017,46.62758,0,0,0,100,0),
(@PATH,7,-4117.128,799.6888,51.93314,0,0,0,100,0),
(@PATH,8,-4082.698,785.6704,50.3498,0,0,0,100,0),
(@PATH,9,-4066.473,752.3994,43.04424,0,0,0,100,0);

SET @NPC := 86103;
SET @PATH := @NPC*10;
UPDATE `creature` SET `id`=21648,`spawndist`=0,`MovementType`=2,`position_x`=-3981.939,`position_y`=1200.395,`position_z`=108.2629 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4015.405,1186.572,107.8463,0,0,0,100,0),
(@PATH,2,-4032.093,1150.835,100.8185,0,0,0,100,0),
(@PATH,3,-4016.442,1117.503,95.84628,0,0,0,100,0),
(@PATH,4,-3982.193,1100.35,95.62405,0,0,0,100,0),
(@PATH,5,-3950.59,1116.853,99.12405,0,0,0,100,0),
(@PATH,6,-3933.569,1150.704,103.263,0,0,0,100,0),
(@PATH,7,-3949.776,1184.953,106.8185,0,0,0,100,0),
(@PATH,8,-3981.939,1200.395,108.2629,0,0,0,100,0);
