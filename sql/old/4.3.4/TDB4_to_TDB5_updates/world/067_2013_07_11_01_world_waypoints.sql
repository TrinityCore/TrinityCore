-- Pathing for Illidari Fearbringer Entry: 22954
SET @NPC := 52768;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=612.1008,`position_y`=715.0594,`position_z`=77.48019 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,612.1008,715.0594,77.48019,0,0,0,0,100,0),
(@PATH,2,626.8418,715.1508,75.81075,0,0,0,0,100,0),
(@PATH,3,643.162,716.2298,70.8769,0,0,0,0,100,0),
(@PATH,4,663.4116,720.2251,70.52241,0,0,0,0,100,0),
(@PATH,5,682.2949,737.6859,68.97373,0,0,0,0,100,0),
(@PATH,6,692.6406,756.8541,66.75413,0,0,0,0,100,0),
(@PATH,7,682.2949,737.6859,68.97373,0,0,0,0,100,0),
(@PATH,8,663.4116,720.2251,70.52241,0,0,0,0,100,0),
(@PATH,9,643.162,716.2298,70.8769,0,0,0,0,100,0),
(@PATH,10,626.8418,715.1508,75.81075,0,0,0,0,100,0);

-- Pathing for Illidari Fearbringer Entry: 22954
SET @NPC := 52773;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=680.5127,`position_y`=736.589,`position_z`=68.98032 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,680.5127,736.589,68.98032,0,0,0,0,100,0),
(@PATH,2,689.7178,752.5954,67.10484,0,0,0,0,100,0),
(@PATH,3,690.7227,773.5752,65.17497,0,0,0,0,100,0),
(@PATH,4,682.0201,797.8951,63.36504,0,0,0,0,100,0),
(@PATH,5,679.8043,821.2305,61.06209,0,0,0,0,100,0),
(@PATH,6,680.7047,848.535,58.56005,0,0,0,0,100,0),
(@PATH,7,679.8043,821.2305,61.06209,0,0,0,0,100,0),
(@PATH,8,682.0201,797.8951,63.36504,0,0,0,0,100,0),
(@PATH,9,690.7438,773.907,65.11858,0,0,0,0,100,0),
(@PATH,10,689.7178,752.5954,67.10484,0,0,0,0,100,0);

-- Pathing for Illidari Fearbringer Entry: 22954
SET @NPC := 52769;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=713.0262,`position_y`=704.147,`position_z`=70.84101 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,713.0262,704.147,70.84101,0,0,0,0,100,0),
(@PATH,2,733.0706,690.4993,71.98522,0,0,0,0,100,0),
(@PATH,3,769.0543,692.4883,71.78658,0,0,0,0,100,0),
(@PATH,4,790.8868,701.6238,73.08874,0,0,0,0,100,0),
(@PATH,5,801.6542,721.7141,70.07971,0,0,0,0,100,0),
(@PATH,6,790.8868,701.6238,73.08874,0,0,0,0,100,0),
(@PATH,7,769.0543,692.4883,71.78658,0,0,0,0,100,0),
(@PATH,8,733.0706,690.4993,71.98522,0,0,0,0,100,0);

-- Pathing for Illidari Fearbringer Entry: 22954
SET @NPC := 52772;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=721.4406,`position_y`=728.4247,`position_z`=68.65119 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,721.4406,728.4247,68.65119,0,0,0,0,100,0),
(@PATH,2,721.3423,745.3929,67.11169,0,0,0,0,100,0),
(@PATH,3,716.5741,774.6444,64.54839,0,0,0,0,100,0),
(@PATH,4,724.2047,803.066,62.11536,0,0,0,0,100,0),
(@PATH,5,735.2154,833.7368,58.94956,0,0,0,0,100,0),
(@PATH,6,734.4446,863.5928,56.50595,0,0,0,0,100,0),
(@PATH,7,735.2154,833.7368,58.94956,0,0,0,0,100,0),
(@PATH,8,724.2047,803.066,62.11536,0,0,0,0,100,0),
(@PATH,9,716.5741,774.6444,64.54839,0,0,0,0,100,0),
(@PATH,10,721.3423,745.3929,67.11169,0,0,0,0,100,0);

-- Pathing for Aqueous Lord Entry: 22878
SET @NPC := 12866;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=312.8537,`position_y`=813.1077,`position_z`=-17.58058 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,312.8537,813.1077,-17.58058,0,0,0,0,100,0),
(@PATH,2,341.3598,812.8531,-6.117754,0,0,0,0,100,0),
(@PATH,3,381.8092,812.6519,9.062115,0,0,0,0,100,0),
(@PATH,4,341.4501,812.8524,-6.08468,0,0,0,0,100,0);

-- Pathing for Aqueous Lord Entry: 22878
SET @NPC := 12869;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=252.3342,`position_y`=893.9015,`position_z`=-30.78079 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,252.3342,893.9015,-30.78079,0,0,0,0,100,0),
(@PATH,2,252.6844,922.2958,-44.67338,0,0,0,0,100,0),
(@PATH,3,252.5329,943.3651,-55.76704,0,0,0,0,100,0),
(@PATH,4,252.6844,922.2958,-44.67338,0,0,0,0,100,0);

-- Pathing for Priestess of Dementia Entry: 22957
SET @NPC := 52857;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=946.3522,`position_y`=337.5683,`position_z`=191.208 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,946.3522,337.5683,191.208,0,0,0,0,100,0),
(@PATH,2,946.4788,358.0963,191.208,0,0,0,0,100,0),
(@PATH,3,946.3522,337.5683,191.208,0,0,0,0,100,0),
(@PATH,4,946.2967,310.864,191.208,0,0,0,0,100,0),
(@PATH,5,946.0381,284.1759,191.208,0,0,0,0,100,0),
(@PATH,6,945.9597,259.7708,191.208,0,0,0,0,100,0),
(@PATH,7,945.9167,242.3769,191.208,0,0,0,0,100,0),
(@PATH,8,945.6511,224.3957,191.208,0,0,0,0,100,0),
(@PATH,9,945.9167,242.3769,191.208,0,0,0,0,100,0),
(@PATH,10,945.9597,259.7708,191.208,0,0,0,0,100,0),
(@PATH,11,946.0381,284.1759,191.208,0,0,0,0,100,0),
(@PATH,12,946.2967,310.864,191.208,0,0,0,0,100,0),
(@PATH,13,946.3522,337.5683,191.208,0,0,0,0,100,0),
(@PATH,14,946.4788,358.0963,191.208,0,0,0,0,100,0);

-- Pathing for Promenade Sentinel Entry: 23394
SET @NPC := 12884;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=761.1854,`position_y`=161.5995,`position_z`=218.4323 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,761.1854,161.5995,218.4323,0,0,0,0,100,0),
(@PATH,2,762.2211,175.3375,218.453,0,0,0,0,100,0),
(@PATH,3,788.6677,173.3627,212.4686,0,0,0,0,100,0),
(@PATH,4,813.4553,170.9617,204.7675,0,0,0,0,100,0),
(@PATH,5,812.7894,149.1826,204.7681,0,0,0,0,100,0),
(@PATH,6,812.5944,127.2771,204.7675,0,0,0,0,100,0),
(@PATH,7,788.8348,125.6381,212.1583,0,0,0,0,100,0),
(@PATH,8,760.3759,122.2594,218.5355,0,0,0,0,100,0),
(@PATH,9,760.9326,144.1558,218.4856,0,0,0,0,100,0);

-- Pathing for Promenade Sentinel Entry: 23394
SET @NPC := 12886;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=624.8207,`position_y`=173.8407,`position_z`=253.2433 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,624.8207,173.8407,253.2433,0,0,0,0,100,0),
(@PATH,2,640.5691,173.9213,245.0594,0,0,0,0,100,0),
(@PATH,3,642.4141,149.8184,245.0508,0,0,0,0,100,0),
(@PATH,4,639.9938,127.3701,245.0583,0,0,0,0,100,0),
(@PATH,5,626.2823,127.0409,251.9054,0,0,0,0,100,0),
(@PATH,6,611.546,126.5545,258.8932,0,0,0,0,100,0),
(@PATH,7,606.4694,138.4668,258.7596,0,0,0,0,100,0),
(@PATH,8,607.1602,162.4693,258.7508,0,0,0,0,100,0),
(@PATH,9,613.0195,175.0303,258.9398,0,0,0,0,100,0),
(@PATH,10,624.8207,173.8407,253.2433,0,0,0,0,100,0);

-- Pathing for Promenade Sentinel Entry: 23394
SET @NPC := 12888;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=548.1619,`position_y`=222.5298,`position_z`=271.9026 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,548.1619,222.5298,271.9026,4.712389,33000,0,0,100,0),
(@PATH,2,548.1752,204.6016,265.1634,0,0,0,0,100,0),
(@PATH,3,548.1595,190.8972,258.734,0,0,0,0,100,0),
(@PATH,4,548.0938,205.5043,265.7878,0,0,0,0,100,0);

-- Pathing for Promenade Sentinel Entry: 23394
SET @NPC := 12889;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=696.7759,`position_y`=173.015,`position_z`=232.0304 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,4097,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,696.7759,173.015,232.0304,0,0,0,0,100,0),
(@PATH,2,711.6221,149.6127,231.9982,0,0,0,0,100,0),
(@PATH,3,696.7689,127.0203,232.0802,0,0,0,0,100,0),
(@PATH,4,679.1018,126.4796,239.9357,0,0,0,0,100,0),
(@PATH,5,664.3721,125.8799,245.6465,0,0,0,0,100,0),
(@PATH,6,656.2635,131.5955,245.4032,0,0,0,0,100,0),
(@PATH,7,656.2786,146.7755,245.3991,0,0,0,0,100,0),
(@PATH,8,656.2986,153.3558,245.3982,0,0,0,0,100,0),
(@PATH,9,656.5179,169.0384,245.4051,0,0,0,0,100,0),
(@PATH,10,663.8251,173.6144,245.7881,0,0,0,0,100,0),
(@PATH,11,678.0536,173.7249,240.8454,0,0,0,0,100,0);

-- Pathing for Bonechewer Behemoth Entry: 23196
SET @NPC := 52739;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=909.464,`position_y`=245.1965,`position_z`=85.64125 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,909.464,245.1965,85.64125,0,0,0,0,100,0),
(@PATH,2,936.0223,259.309,85.6412,0,0,0,0,100,0),
(@PATH,3,941.6469,283.9179,85.64117,0,0,0,0,100,0),
(@PATH,4,924.2444,298.756,86.15284,0,0,0,0,100,0),
(@PATH,5,941.6469,283.9179,85.64117,0,0,0,0,100,0),
(@PATH,6,936.0223,259.309,85.6412,0,0,0,0,100,0),
(@PATH,7,909.464,245.1965,85.64125,0,0,0,0,100,0),
(@PATH,8,881.7233,244.0528,84.85726,0,0,0,0,100,0);

-- Pathing for Bonechewer Behemoth Entry: 23196
SET @NPC := 52740;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=899.0332,`position_y`=197.8294,`position_z`=86.16103 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,899.0332,197.8294,86.16103,0,0,0,0,100,0),
(@PATH,2,897.7601,186.8322,86.16117,0,0,0,0,100,0),
(@PATH,3,899.0332,197.8294,86.16103,0,0,0,0,100,0),
(@PATH,4,897.392,207.5867,86.1609,0,0,0,0,100,0),
(@PATH,5,921.5169,224.1364,85.64123,0,0,0,0,100,0),
(@PATH,6,930.8919,235.1188,85.64124,0,0,0,0,100,0),
(@PATH,7,940.9707,239.6061,85.64124,0,0,0,0,100,0),
(@PATH,8,950.1663,237.9947,86.16045,0,0,0,0,100,0),
(@PATH,9,956.6059,230.0929,86.16039,0,0,0,0,100,0),
(@PATH,10,956.8278,213.7176,86.16056,0,0,0,0,100,0),
(@PATH,11,957.555,199.413,86.1607,0,0,0,0,100,0),
(@PATH,12,956.8278,213.7176,86.16056,0,0,0,0,100,0),
(@PATH,13,956.6059,230.0929,86.16039,0,0,0,0,100,0),
(@PATH,14,950.1663,237.9947,86.16045,0,0,0,0,100,0),
(@PATH,15,940.9707,239.6061,85.64124,0,0,0,0,100,0),
(@PATH,16,930.8919,235.1188,85.64124,0,0,0,0,100,0),
(@PATH,17,921.5169,224.1364,85.64123,0,0,0,0,100,0),
(@PATH,18,897.392,207.5867,86.1609,0,0,0,0,100,0),
(@PATH,19,899.0332,197.8294,86.16103,0,0,0,0,100,0),
(@PATH,20,897.7601,186.8322,86.16117,0,0,0,0,100,0);

-- Pathing for Bonechewer Behemoth Entry: 23196
SET @NPC := 52542;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=872.4788,`position_y`=65.84342,`position_z`=112.7412 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,872.4788,65.84342,112.7412,0,0,0,0,100,0),
(@PATH,2,935.6211,65.98904,112.7535,0,0,0,0,100,0),
(@PATH,3,899.9241,69.37424,112.7376,0,0,0,0,100,0),
(@PATH,4,869.3976,68.47385,112.7417,0,0,0,0,100,0),
(@PATH,5,826.9479,67.30523,112.7454,0,0,0,0,100,0),
(@PATH,6,869.2424,69.2244,112.7418,0,0,0,0,100,0),
(@PATH,7,863.1619,63.82265,112.7426,0,0,0,0,100,0),
(@PATH,8,868.8893,72.09175,112.7419,0,0,0,0,100,0),
(@PATH,9,861.7059,67.34996,112.7429,0,0,0,0,100,0),
(@PATH,10,867.9327,69.0042,112.742,0,0,0,0,100,0),
(@PATH,11,825.1594,65.52496,112.7448,0,0,0,0,100,0),
(@PATH,12,874.6883,67.74924,112.7409,0,0,0,0,100,0),
(@PATH,13,899.5973,69.61382,112.7372,0,0,0,0,100,0),
(@PATH,14,927.8147,64.82682,112.7534,0,0,0,0,100,0),
(@PATH,15,870.0113,69.63828,112.7417,0,0,0,0,100,0),
(@PATH,16,870.6498,66.78909,112.7415,0,0,0,0,100,0);

-- Pathing for Bonechewer Behemoth Entry: 23196
SET @NPC := 52743;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=763.4602,`position_y`=121.2597,`position_z`=112.5469 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,763.4602,121.2597,112.5469,0,0,0,0,100,0),
(@PATH,2,765.515,120.5528,112.4407,0,0,0,0,100,0),
(@PATH,3,761.6171,120.877,112.6373,0,0,0,0,100,0),
(@PATH,4,763.0114,122.1931,112.5738,0,0,0,0,100,0),
(@PATH,5,762.4429,119.6596,112.5902,0,0,0,0,100,0),
(@PATH,6,762.847,118.4683,112.5643,0,0,0,0,100,0),
(@PATH,7,764.7086,116.9735,112.464,0,0,0,0,100,0),
(@PATH,8,762.533,120.0672,112.5876,0,0,0,0,100,0),
(@PATH,9,760.8773,120.2691,112.6714,0,0,0,0,100,0),
(@PATH,10,761.802,117.5317,112.6121,0,0,0,0,100,0),
(@PATH,11,765.24,118.7345,112.4458,0,0,0,0,100,0),
(@PATH,12,762.7466,119.8271,112.5758,0,0,0,0,100,0),
(@PATH,13,759.4903,118.7799,112.7338,0,0,0,0,100,0),
(@PATH,14,760.2434,121.535,112.7092,0,0,0,0,100,0),
(@PATH,15,767.4446,120.2948,112.3428,0,0,0,0,100,0),
(@PATH,16,752.21,117.786,112.7387,0,0,0,0,100,0),
(@PATH,17,735.6179,101.9004,112.7494,0,0,0,0,100,0),
(@PATH,18,724.5951,75.40408,113.4761,0,0,0,0,100,0),
(@PATH,19,756.7452,71.75539,112.7374,0,0,0,0,100,0),
(@PATH,20,756.4152,69.2236,112.7374,0,0,0,0,100,0),
(@PATH,21,730.9688,65.39399,113.2859,0,0,0,0,100,0),
(@PATH,22,775.8292,75.42676,112.7374,0,0,0,0,100,0),
(@PATH,23,772.0274,107.9498,112.6996,0,0,0,0,100,0);

-- Pathing for Bonechewer Taskmaster Entry: 23028
SET @NPC := 53816;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=775.0792,`position_y`=766.9516,`position_z`=66.16946 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,775.0792,766.9516,66.16946,0,0,0,0,100,0),
(@PATH,2,776.4752,758.1284,68.59184,0,0,0,0,100,0),
(@PATH,3,776.7239,748.5446,70.04276,0,0,0,0,100,0),
(@PATH,4,771.1584,744.486,69.7692,0,0,0,0,100,0),
(@PATH,5,776.7239,748.5446,70.04276,0,0,0,0,100,0),
(@PATH,6,776.4752,758.1284,68.59184,0,0,0,0,100,0),
(@PATH,7,775.0792,766.9516,66.16946,0,0,0,0,100,0),
(@PATH,8,776.6424,775.2938,65.64797,0,0,0,0,100,0),
(@PATH,9,779.1,781.9779,65.93484,0,0,0,0,100,0),
(@PATH,10,776.9979,791.3973,65.63259,0,0,0,0,100,0),
(@PATH,11,779.1,781.9779,65.93484,0,0,0,0,100,0),
(@PATH,12,776.6424,775.2938,65.64797,0,0,0,0,100,0);

-- Pathing for Suffering Soul Fragment Entry: 23399
SET @NPC := 40526;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=496.5382,`position_y`=84.75467,`position_z`=108.4162 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,496.5382,84.75467,108.4162,0,0,0,0,100,0),
(@PATH,2,521.0706,76.54764,112.8559,0,0,0,0,100,0),
(@PATH,3,496.5382,84.75467,108.4162,0,0,0,0,100,0),
(@PATH,4,474.7787,75.08279,111.861,0,0,0,0,100,0);

-- Pathing for Suffering Soul Fragment Entry: 23399
SET @NPC := 52411;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=557.008,`position_y`=29.39996,`position_z`=112.4988 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,557.008,29.39996,112.4988,0,0,0,0,100,0),
(@PATH,2,519.227,48.72656,113.3207,0,0,0,0,100,0),
(@PATH,3,477.2372,27.49957,112.5984,0,0,0,0,100,0),
(@PATH,4,519.227,48.72656,113.3207,0,0,0,0,100,0);

-- Pathing for Suffering Soul Fragment Entry: 23399
SET @NPC := 46817;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=609.3162,`position_y`=98.43359,`position_z`=112.342 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,609.3162,98.43359,112.342,0,0,0,0,100,0),
(@PATH,2,580.6458,90.18815,111.1614,0,0,0,0,100,0),
(@PATH,3,609.3162,98.43359,112.342,0,0,0,0,100,0),
(@PATH,4,629.5143,77.47526,112.7921,0,0,0,0,100,0);

-- Pathing for Suffering Soul Fragment Entry: 23399
SET @NPC := 40446;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=535.6982,`position_y`=75.88596,`position_z`=112.9535 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,535.6982,75.88596,112.9535,0,0,0,0,100,0),
(@PATH,2,560.1788,80.13477,113.2281,0,0,0,0,100,0),
(@PATH,3,574.8022,104.9709,113.0734,0,0,0,0,100,0),
(@PATH,4,560.1788,80.13477,113.2281,0,0,0,0,100,0);

-- Pathing for Suffering Soul Fragment Entry: 23399
SET @NPC := 42920;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=629.0891,`position_y`=47.3309,`position_z`=112.7773 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,629.0891,47.3309,112.7773,0,0,0,0,100,0),
(@PATH,2,601.5073,37.56067,112.7347,0,0,0,0,100,0),
(@PATH,3,575.1098,56.30285,111.0313,0,0,0,0,100,0),
(@PATH,4,601.2772,37.47917,112.7411,0,0,0,0,100,0);

-- Pathing for Hungering Soul Fragment Entry: 23401
SET @NPC := 52420;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=620.9159,`position_y`=30.22016,`position_z`=112.7356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '41248');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,620.9159,30.22016,112.7356,0,0,0,0,100,0),
(@PATH,2,607.7153,64.61448,111.7263,0,0,0,0,100,0),
(@PATH,3,589.4402,39.24023,112.765,0,0,0,0,100,0),
(@PATH,4,607.5776,64.42328,111.7202,0,0,0,0,100,0);

-- Pathing for Hungering Soul Fragment Entry: 23401
SET @NPC := 52424;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=518.9474,`position_y`=74.61002,`position_z`=112.9129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '41248');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,518.9474,74.61002,112.9129,0,0,0,0,100,0),
(@PATH,2,473.2182,73.22733,111.8457,0,0,0,0,100,0);

-- Pathing for Hungering Soul Fragment Entry: 23401
SET @NPC := 52418;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=617.4402,`position_y`=102.7646,`position_z`=112.7506 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '41248');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,617.4402,102.7646,112.7506,0,0,0,0,100,0),
(@PATH,2,601.6309,74.0624,111.239,0,0,0,0,100,0),
(@PATH,3,578.1609,98.96626,113.0465,0,0,0,0,100,0),
(@PATH,4,601.5496,73.97516,111.2432,0,0,0,0,100,0);

-- Pathing for Hungering Soul Fragment Entry: 23401
SET @NPC := 52427;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=552.3234,`position_y`=97.95421,`position_z`=112.4811 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '41248');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,552.3234,97.95421,112.4811,0,0,0,0,100,0),
(@PATH,2,536.0945,78.04199,113.071,0,0,0,0,100,0),
(@PATH,3,552.3234,97.95421,112.4811,0,0,0,0,100,0),
(@PATH,4,573.4583,103.4899,113.1861,0,0,0,0,100,0);

-- Pathing for Hungering Soul Fragment Entry: 23401
SET @NPC := 52423;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=512.1553,`position_y`=30.04926,`position_z`=113.648 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '41248');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,512.1553,30.04926,113.648,0,0,0,0,100,0),
(@PATH,2,487.4863,43.71723,112.3249,0,0,0,0,100,0),
(@PATH,3,512.1553,30.04926,113.648,0,0,0,0,100,0),
(@PATH,4,550.6255,48.4656,112.5677,0,0,0,0,100,0);
