-- [NPC][WotlK] Stormforged Saboteur, missing paths
-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC := 88115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7693.506,`position_y`=-2324.018,`position_z`=1038.417 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7693.506,-2324.018,1038.417,0,0,0,0,100,0),
(@PATH,2,7681.481,-2302.699,1024.499,0,0,0,0,100,0),
(@PATH,3,7692.982,-2323.4,1038.048,0,0,0,0,100,0),
(@PATH,4,7698.107,-2330.618,1043.213,0,0,0,0,100,0),
(@PATH,5,7733.517,-2353.724,1068.687,0,0,0,0,100,0),
(@PATH,6,7717.036,-2345.113,1058.945,0,0,0,0,100,0),
(@PATH,7,7706.17,-2339.842,1050.38,0,0,0,0,100,0),
(@PATH,8,7694.688,-2325.7,1039.569,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D000008E709 .go 7693.506 -2324.018 1038.417

-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC := 88121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7717.821,`position_y`=-2373.15,`position_z`=1076.397 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7717.821,-2373.15,1076.397,0,0,0,0,100,0),
(@PATH,2,7716.69,-2373.623,1076.546,0,0,0,0,100,0),
(@PATH,3,7713.94,-2375.873,1077.046,0,0,0,0,100,0),
(@PATH,4,7712.434,-2377.115,1077.223,0,0,0,0,100,0),
(@PATH,5,7708.74,-2383.643,1077.744,0,0,0,0,100,0),
(@PATH,6,7707.24,-2390.143,1078.244,0,0,0,0,100,0),
(@PATH,7,7708.308,-2384.875,1077.819,0,0,0,0,100,0),
(@PATH,8,7709.108,-2383.253,1077.683,0,0,0,0,100,0),
(@PATH,9,7712.659,-2376.858,1077.257,0,0,0,0,100,0),
(@PATH,10,7715.409,-2374.608,1076.757,0,0,0,0,100,0),
(@PATH,11,7716.896,-2373.736,1076.646,0,0,0,0,100,0),
(@PATH,12,7721.577,-2372.192,1075.534,0,0,0,0,100,0),
(@PATH,13,7723.327,-2371.942,1075.284,0,0,0,0,100,0),
(@PATH,14,7721.291,-2372.098,1075.588,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D000009FFF3 .go 7717.821 -2373.15 1076.397



-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC := 88116;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7716.721,`position_y`=-2417.521,`position_z`=1078.866 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7716.721,-2417.521,1078.866,0,0,0,0,100,0),
(@PATH,2,7721.32,-2423.333,1078.504,0,0,0,0,100,0),
(@PATH,3,7726.283,-2426.826,1078.622,0,0,0,0,100,0),
(@PATH,4,7734.296,-2428.488,1079.077,0,0,0,0,100,0),
(@PATH,5,7741.796,-2428.331,1079.079,0,0,0,0,100,0),
(@PATH,6,7734.083,-2428.462,1078.925,0,0,0,0,100,0),
(@PATH,7,7726.114,-2426.458,1078.75,0,0,0,0,100,0),
(@PATH,8,7721.104,-2423.094,1078.602,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D00000A6AE6 .go 7716.721 -2417.521 1078.866


-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC := 88122;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7708.882,`position_y`=-2383.844,`position_z`=1077.573 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7708.882,-2383.844,1077.573,0,0,0,0,100,0),
(@PATH,2,7712.606,-2376.904,1077.29,0,0,0,0,100,0),
(@PATH,3,7715.585,-2374.437,1076.769,0,0,0,0,100,0),
(@PATH,4,7717.085,-2373.687,1076.519,0,0,0,0,100,0),
(@PATH,5,7721.5,-2372.127,1075.651,0,0,0,0,100,0),
(@PATH,6,7723.25,-2371.877,1075.401,0,0,0,0,100,0),
(@PATH,7,7722.302,-2371.998,1075.731,0,0,0,0,100,0),
(@PATH,8,7716.878,-2373.573,1076.597,0,0,0,0,100,0),
(@PATH,9,7713.878,-2375.823,1077.097,0,0,0,0,100,0),
(@PATH,10,7712.221,-2377.236,1077.321,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D00008B704D .go 7708.882 -2383.844 1077.573


-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC := 88112;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7810.335,`position_y`=-2396.439,`position_z`=1093.944 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7810.335,-2396.439,1093.944,0,0,0,0,100,0),
(@PATH,2,7811.585,-2396.189,1094.694,0,0,0,0,100,0),
(@PATH,3,7817.335,-2396.189,1097.694,0,0,0,0,100,0),
(@PATH,4,7833.19,-2401.916,1106.79,0,0,0,0,100,0),
(@PATH,5,7830.69,-2400.916,1105.54,0,0,0,0,100,0),
(@PATH,6,7828.484,-2400.28,1103.903,0,0,0,0,100,0),
(@PATH,7,7825.484,-2399.28,1102.153,0,0,0,0,100,0),
(@PATH,8,7822.984,-2398.28,1100.653,0,0,0,0,100,0),
(@PATH,9,7820.234,-2397.28,1099.653,0,0,0,0,100,0),
(@PATH,10,7818.22,-2396.551,1098.187,0,0,0,0,100,0),
(@PATH,11,7811.454,-2396.305,1094.445,0,0,0,0,100,0),
(@PATH,12,7809.454,-2396.555,1093.445,0,0,0,0,100,0),
(@PATH,13,7806.704,-2396.805,1092.195,0,0,0,0,100,0),
(@PATH,14,7804.516,-2397.255,1090.906,0,0,0,0,100,0),
(@PATH,15,7802.516,-2397.755,1089.906,0,0,0,0,100,0),
(@PATH,16,7799.766,-2398.255,1088.656,0,0,0,0,100,0),
(@PATH,17,7802.344,-2397.896,1089.801,0,0,0,0,100,0),
(@PATH,18,7804.471,-2397.053,1090.839,0,0,0,0,100,0),
(@PATH,19,7808.221,-2396.803,1092.839,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D000288E709 .go 7810.335 -2396.439 1093.944

-- Pathing for  Entry: 31693 'TDB FORMAT' 
SET @NPC :=  88111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7594.389,`position_y`=-2281.263,`position_z`=940.06 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7594.389,-2281.263,940.06,0,0,0,0,100,0),
(@PATH,2,7590.639,-2284.263,935.81,0,0,0,0,100,0),
(@PATH,3,7583.639,-2287.263,929.31,0,0,0,0,100,0),
(@PATH,4,7587.911,-2285.628,933.4109,0,0,0,0,100,0),
(@PATH,5,7594.338,-2281.126,940.1424,0,0,0,0,100,0),
(@PATH,6,7596.588,-2278.876,942.6424,0,0,0,0,100,0),
(@PATH,7,7602.338,-2272.376,949.6424,0,0,0,0,100,0),
(@PATH,8,7606.058,-2268.674,953.5016,0,0,0,0,100,0),
(@PATH,9,7607.808,-2266.674,955.2516,0,0,0,0,100,0),
(@PATH,10,7612.058,-2262.424,961.2516,0,0,0,0,100,0),
(@PATH,11,7612.923,-2261.475,962.8279,0,0,0,0,100,0),
(@PATH,12,7617.423,-2259.975,966.5779,0,0,0,0,100,0),
(@PATH,13,7622.441,-2258.586,971.277,0,0,0,0,100,0),
(@PATH,14,7623.191,-2258.336,972.277,0,0,0,0,100,0),
(@PATH,15,7628.944,-2257.969,976.8357,0,0,0,0,100,0),
(@PATH,16,7639.093,-2262.12,985.2325,0,0,0,0,100,0),
(@PATH,17,7645.936,-2263.47,991.0493,0,0,0,0,100,0),
(@PATH,18,7653.126,-2270.09,997.1328,0,0,0,0,100,0),
(@PATH,19,7649.956,-2266.439,994.4049,0,0,0,0,100,0),
(@PATH,20,7645.541,-2263.432,990.6445,0,0,0,0,100,0),
(@PATH,21,7636.538,-2260.767,982.4916,0,0,0,0,100,0),
(@PATH,22,7633.74,-2259.331,980.5753,0,0,0,0,100,0),
(@PATH,23,7628.049,-2257.727,975.717,0,0,0,0,100,0),
(@PATH,24,7614.933,-2261.062,964.6306,0,0,0,0,100,0),
(@PATH,25,7608.933,-2265.812,956.8806,0,0,0,0,100,0),
(@PATH,26,7596.662,-2278.802,942.7743,0,0,0,0,100,0);
-- 0x203CD047601EF340000C1D000408E709 .go 7594.389 -2281.263 940.06
