-- Pathing for Firewing Bloodwarder Entry: 1410
SET @NPC := 78283;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=1410,`spawndist`=0,`MovementType`=2,`position_x`=-2300.636,`position_y`=3100.041,`position_z`=147.3982 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2299.969,3105.141,149.6725,0,0,0,100,0),
(@PATH,2,-2292.289,3110.856,152.6214,0,0,0,100,0),
(@PATH,3,-2283.752,3110.493,152.8172,0,0,0,100,0),
(@PATH,4,-2276.066,3103.917,152.8172,0,0,0,100,0),
(@PATH,5,-2283.752,3110.493,152.8172,0,0,0,100,0),
(@PATH,6,-2292.289,3110.856,152.6214,0,0,0,100,0),
(@PATH,7,-2299.969,3105.141,149.6725,0,0,0,100,0),
(@PATH,8,-2300.636,3100.041,147.3982,0,0,0,100,0),
(@PATH,9,-2300.859,3092.531,144.2333,0,0,0,100,0),
(@PATH,10,-2296.14,3085.783,141.8156,0,0,0,100,0),
(@PATH,11,-2289.155,3083.634,139.7564,0,0,0,100,0),
(@PATH,12,-2281.993,3085.269,138.7524,0,0,0,100,0),
(@PATH,13,-2277.662,3092.126,138.7524,0,0,0,100,0),
(@PATH,14,-2281.993,3085.269,138.7524,0,0,0,100,0),
(@PATH,15,-2289.155,3083.634,139.7564,0,0,0,100,0),
(@PATH,16,-2296.14,3085.783,141.8156,0,0,0,100,0),
(@PATH,17,-2300.859,3092.531,144.2333,0,0,0,100,0),
(@PATH,18,-2300.636,3100.041,147.3982,0,0,0,100,0);

-- Pathing for Firewing Bloodwarder Entry: 1410
SET @NPC := 7758;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2242.387,`position_y`=3202.843,`position_z`=22.8518 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2239.479,3214.478,22.85181,0,0,0,100,0),
(@PATH,2,-2242.496,3225.877,22.8518,0,0,0,100,0),
(@PATH,3,-2251.287,3234.036,22.8518,0,0,0,100,0),
(@PATH,4,-2263.125,3235.337,22.8518,0,0,0,100,0),
(@PATH,5,-2272.588,3231.565,22.85181,0,0,0,100,0),
(@PATH,6,-2277.569,3226.189,22.8518,0,0,0,100,0),
(@PATH,7,-2272.588,3231.565,22.85181,0,0,0,100,0),
(@PATH,8,-2263.125,3235.337,22.8518,0,0,0,100,0),
(@PATH,9,-2251.486,3234.058,22.85181,0,0,0,100,0),
(@PATH,10,-2242.496,3225.877,22.8518,0,0,0,100,0),
(@PATH,11,-2239.404,3214.779,22.8518,0,0,0,100,0),
(@PATH,12,-2242.387,3202.843,22.8518,0,0,0,100,0),
(@PATH,13,-2249.017,3196.804,22.80147,0,0,0,100,0),
(@PATH,14,-2260.803,3194.38,22.85367,0,0,0,100,0),
(@PATH,15,-2271.738,3198.11,22.85364,0,0,0,100,0),
(@PATH,16,-2277.687,3205.128,22.85181,0,0,0,100,0),
(@PATH,17,-2271.738,3198.11,22.85364,0,0,0,100,0),
(@PATH,18,-2260.803,3194.38,22.85367,0,0,0,100,0),
(@PATH,19,-2249.017,3196.804,22.80147,0,0,0,100,0),
(@PATH,20,-2242.387,3202.843,22.8518,0,0,0,100,0);

-- Pathing for Firewing Bloodwarder Entry: 1410
SET @NPC := 7756;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2254.217,`position_y`=3224.904,`position_z`=5.111827 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2260.976,3226.1,5.349664,0,0,0,100,0),
(@PATH,2,-2254.217,3224.904,5.111827,0,0,0,100,0),
(@PATH,3,-2249.498,3219.329,2.661798,0,0,0,100,0),
(@PATH,4,-2248.54,3212.486,0.2007978,0,0,0,100,0),
(@PATH,5,-2251.302,3207.916,-1.99811,0,0,0,100,0),
(@PATH,6,-2257.676,3204.946,-4.053215,0,0,0,100,0),
(@PATH,7,-2251.302,3207.916,-1.99811,0,0,0,100,0),
(@PATH,8,-2248.54,3212.486,0.2007978,0,0,0,100,0),
(@PATH,9,-2249.494,3219.303,2.65062,0,0,0,100,0),
(@PATH,10,-2254.217,3224.904,5.111827,0,0,0,100,0);

-- Pathing for Firewing Bloodwarder Entry: 1410
SET @NPC := 7763;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2345.06,`position_y`=3365.858,`position_z`=-3.307672 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2349.435,3351.335,-2.557672,0,0,0,100,0),
(@PATH,2,-2351.637,3330.967,-2.123725,0,0,0,100,0),
(@PATH,3,-2352.411,3313.604,-1.498725,0,0,0,100,0),
(@PATH,4,-2348.645,3294.924,-0.8494196,0,0,0,100,0),
(@PATH,5,-2347.5,3285.576,-0.4744196,0,0,0,100,0),
(@PATH,6,-2348.645,3294.924,-0.8494196,0,0,0,100,0),
(@PATH,7,-2352.411,3313.604,-1.498725,0,0,0,100,0),
(@PATH,8,-2351.637,3330.967,-2.123725,0,0,0,100,0),
(@PATH,9,-2349.435,3351.335,-2.557672,0,0,0,100,0),
(@PATH,10,-2345.06,3365.858,-3.307672,0,0,0,100,0),
(@PATH,11,-2336.654,3375.736,-4.585965,0,0,0,100,0),
(@PATH,12,-2345.06,3365.858,-3.307672,0,0,0,100,0);

-- Pathing for Firewing Bloodwarder Entry: 1410
SET @NPC := 7746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2411.25,`position_y`=3154.885,`position_z`=12.51691 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2425.553,3163.988,17.89025,0,0,0,100,0),
(@PATH,2,-2429.365,3184.917,18.08286,0,0,0,100,0),
(@PATH,3,-2421.878,3196.283,18.09011,0,0,0,100,0),
(@PATH,4,-2409.75,3196.483,18.08351,0,0,0,100,0),
(@PATH,5,-2401.37,3186.509,18.08373,0,0,0,100,0),
(@PATH,6,-2403.097,3176.193,18.08514,0,0,0,100,0),
(@PATH,7,-2411.921,3170.701,18.0846,0,0,0,100,0),
(@PATH,8,-2421.156,3170.403,18.0838,0,0,0,100,0),
(@PATH,9,-2424.846,3168.233,18.08307,0,0,0,100,0),
(@PATH,10,-2417.574,3160.759,15.48733,0,0,0,100,0),
(@PATH,11,-2409.663,3157.18,11.92867,0,0,0,100,0),
(@PATH,12,-2399.892,3160.786,8.800606,0,0,0,100,0),
(@PATH,13,-2390.157,3169.781,3.500476,0,0,0,100,0),
(@PATH,14,-2388.426,3169.413,3.038804,0,0,0,100,0),
(@PATH,15,-2400.481,3157.432,9.245301,0,0,0,100,0),
(@PATH,16,-2411.25,3154.885,12.51691,0,0,0,100,0);

-- Pathing for Firewing Defender Entry: 5355
SET @NPC := 35071;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2373.031,`position_y`=3204.094,`position_z`=-1.114177 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2362.045,3196.487,-1.458659,0,0,0,100,0),
(@PATH,2,-2349.351,3192.811,-1.458659,0,0,0,100,0),
(@PATH,3,-2338.471,3193.571,-1.333659,0,0,0,100,0),
(@PATH,4,-2326.477,3197.87,-1.377604,0,0,0,100,0),
(@PATH,5,-2317.173,3205.313,-1.375597,0,0,0,100,0),
(@PATH,6,-2310.82,3213.454,-1.125597,0,0,0,100,0),
(@PATH,7,-2307.583,3222.53,-1.500597,0,0,0,100,0),
(@PATH,8,-2306.818,3235.682,-1.325006,0,0,0,100,0),
(@PATH,9,-2308.267,3246.324,-0.9500055,0,0,0,100,0),
(@PATH,10,-2314.036,3256.474,-1.075006,0,0,0,100,0),
(@PATH,11,-2320.906,3264.052,-1.075006,0,0,0,100,0),
(@PATH,12,-2330.98,3271.191,-1.087267,0,0,0,100,0),
(@PATH,13,-2339.27,3275.36,-0.9744196,0,0,0,100,0),
(@PATH,14,-2346.198,3276.744,-1.09942,0,0,0,100,0),
(@PATH,15,-2354.26,3274.702,-1.34942,0,0,0,100,0),
(@PATH,16,-2364.516,3268.476,-1.47442,0,0,0,100,0),
(@PATH,17,-2374.687,3260.501,-1.125597,0,0,0,100,0),
(@PATH,18,-2382.419,3248.859,-1.250597,0,0,0,100,0),
(@PATH,19,-2385.263,3238.87,-1.375597,0,0,0,100,0),
(@PATH,20,-2385.077,3224.941,-1.239177,0,0,0,100,0),
(@PATH,21,-2382.88,3215.065,-1.114177,0,0,0,100,0),
(@PATH,22,-2373.031,3204.094,-1.114177,0,0,0,100,0);

