-- Pathing for Redfang Elder Entry: 26436
SET @NPC := 102310;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3466.93,`position_y`=-4594.270,`position_z`=231.273 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3462.383,-4612.148,231.4899,0,0,0,100,0),
(@PATH,2,3455.436,-4622.705,231.2399,0,0,0,100,0),
(@PATH,3,3431.224,-4629.703,231.8959,0,0,0,100,0),
(@PATH,4,3417.972,-4627.66,231.7709,0,0,0,100,0),
(@PATH,5,3407.802,-4618.447,231.8959,0,0,0,100,0),
(@PATH,6,3404.309,-4602.283,231.6459,0,0,0,100,0),
(@PATH,7,3407.839,-4586.454,231.6536,0,0,0,100,0),
(@PATH,8,3418.060,-4573.690,231.466,0,0,0,100,0),
(@PATH,9,3434.690,-4569.920,231.300,0,0,0,100,0),
(@PATH,10,3450.15,-4570.980,231.293,0,0,0,100,0),
(@PATH,11,3462.95,-4577.800,231.405,0,0,0,100,0),
(@PATH,12,3466.93,-4594.270,231.273,0,0,0,100,0);

-- Pathing for Sorlof Entry: 24914
SET @NPC := 103278;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=234.3479,`position_y`=-3839.657,`position_z`=6.546998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,260.008,-3825.02,5.059539,0,0,0,100,0),
(@PATH,2,279.0299,-3805.746,4.302778,0,0,0,100,0),
(@PATH,3,307.1137,-3802.395,2.265985,0,0,0,100,0),
(@PATH,4,327.6607,-3807.026,2.515985,0,0,0,100,0),
(@PATH,5,356.2998,-3801.84,1.635767,0,0,0,100,0),
(@PATH,6,390.8152,-3765.867,0.9720907,0,0,0,100,0),
(@PATH,7,376.6523,-3827.153,2.452734,0,0,0,100,0),
(@PATH,8,341.8276,-3860.943,5.220708,0,0,0,100,0),
(@PATH,9,317.3375,-3872.974,3.487318,0,0,0,100,0),
(@PATH,10,299.2409,-3881.008,1.03899,0,0,0,100,0),
(@PATH,11,281.0217,-3887.393,5.197232,0,0,0,100,0),
(@PATH,12,242.4368,-3911.016,4.672004,0,0,0,100,0),
(@PATH,13,234.3479,-3839.657,6.546998,0,0,0,100,0);

-- Pathing for Defias Tower Sentry Entry: 7056
SET @NPC := 66994;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11155.1,`position_y`=537.7078,`position_z`=61.61254 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11149.68,531.8951,61.64723,0,0,0,100,0),
(@PATH,2,-11145.47,530.3519,61.64816,0,0,0,100,0),
(@PATH,3,-11142.67,529.801,61.65041,0,0,0,100,0),
(@PATH,4,-11140.16,529.242,61.64826,0,0,0,100,0),
(@PATH,5,-11135.57,530.644,61.6618,0,0,0,100,0),
(@PATH,6,-11131.79,533.377,61.64826,0,0,0,100,0),
(@PATH,7,-11130.45,537.5435,61.64826,0,0,0,100,0),
(@PATH,8,-11129.11,544.0456,61.61562,0,0,0,100,0),
(@PATH,9,-11131.18,551.2862,61.6304,0,0,0,100,0),
(@PATH,10,-11133.83,554.506,61.63765,0,0,0,100,0),
(@PATH,11,-11137.87,556.6643,61.64382,0,0,0,100,0),
(@PATH,12,-11144.09,557.5725,61.63416,0,0,0,100,0),
(@PATH,13,-11150.33,555.5367,61.60638,0,0,0,100,0),
(@PATH,14,-11154.31,552.1038,61.62201,0,0,0,100,0),
(@PATH,15,-11156.64,544.7747,61.62113,0,0,0,100,0),
(@PATH,16,-11155.1,537.7078,61.61254,0,0,0,100,0);

-- Pathing for Defias Tower Patroller Entry: 7052
SET @NPC := 66988;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11152.27,`position_y`=552.6809,`position_z`=55.89178 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11149.12,554.4658,55.80492,0,0,0,100,0),
(@PATH,2,-11144.68,556.6826,55.13705,0,0,0,100,0),
(@PATH,3,-11140.38,556.8944,53.87344,0,0,0,100,0),
(@PATH,4,-11136,554.8301,52.57347,0,0,0,100,0),
(@PATH,5,-11131.66,549.8716,50.37294,0,0,0,100,0),
(@PATH,6,-11130.73,546.1309,49.47009,0,0,0,100,0),
(@PATH,7,-11131.66,549.8716,50.37294,0,0,0,100,0),
(@PATH,8,-11136,554.8301,52.57347,0,0,0,100,0),
(@PATH,9,-11140.38,556.8944,53.87344,0,0,0,100,0),
(@PATH,10,-11144.68,556.6826,55.13705,0,0,0,100,0),
(@PATH,11,-11149.12,554.4658,55.80492,0,0,0,100,0),
(@PATH,12,-11152.27,552.6809,55.89178,0,0,0,100,0);

-- Pathing for Malformed Defias Drone Entry: 7051
SET @NPC := 90331;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11147.35,`position_y`=512.5392,`position_z`=32.61861 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11155.68,519.0281,32.36861,0,0,0,100,0),
(@PATH,2,-11147.35,512.5392,32.61861,0,0,0,100,0),
(@PATH,3,-11135.54,503.5617,31.61861,0,0,0,100,0),
(@PATH,4,-11120.64,505.8491,31.42709,0,0,0,100,0),
(@PATH,5,-11107.24,507.4966,30.92709,0,0,0,100,0),
(@PATH,6,-11120.64,505.8491,31.42709,0,0,0,100,0),
(@PATH,7,-11135.54,503.5617,31.61861,0,0,0,100,0),
(@PATH,8,-11147.35,512.5392,32.61861,0,0,0,100,0);

-- Pathing for Blackrock Scout Entry: 4064
SET @NPC := 28337;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9293.198,`position_y`=-2943.878,`position_z`=163.8473 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9294.498,-2942.447,163.8475,0,0,0,100,0),
(@PATH,2,-9295.34,-2940.965,163.8479,0,0,0,100,0),
(@PATH,3,-9295.685,-2939.59,163.8468,0,0,0,100,0),
(@PATH,4,-9295.738,-2938.026,163.8467,0,0,0,100,0),
(@PATH,5,-9295.759,-2936.388,163.847,0,0,0,100,0),
(@PATH,6,-9295.278,-2935.375,163.8471,0,0,0,100,0),
(@PATH,7,-9294.543,-2934.205,163.8473,0,0,0,100,0),
(@PATH,8,-9294.007,-2933.157,163.8473,0,0,0,100,0),
(@PATH,9,-9292.805,-2932.29,163.8473,0,0,0,100,0),
(@PATH,10,-9291.458,-2931.706,163.8473,0,0,0,100,0),
(@PATH,11,-9290.221,-2931.361,163.8473,0,0,0,100,0),
(@PATH,12,-9289.213,-2931.191,163.8473,0,0,0,100,0),
(@PATH,13,-9288.1,-2930.992,163.8473,0,0,0,100,0),
(@PATH,14,-9287.005,-2931.001,163.8473,0,0,0,100,0),
(@PATH,15,-9285.914,-2931.289,163.8473,0,0,0,100,0),
(@PATH,16,-9284.389,-2931.998,163.8473,0,0,0,100,0),
(@PATH,17,-9283.646,-2933.005,163.8473,0,0,0,100,0),
(@PATH,18,-9282.956,-2934.348,163.8473,0,0,0,100,0),
(@PATH,19,-9282.225,-2935.459,163.8473,0,0,0,100,0),
(@PATH,20,-9281.658,-2936.635,163.8473,0,0,0,100,0),
(@PATH,21,-9281.364,-2937.675,163.8473,0,0,0,100,0),
(@PATH,22,-9281.658,-2936.635,163.8473,0,0,0,100,0),
(@PATH,23,-9282.225,-2935.459,163.8473,0,0,0,100,0),
(@PATH,24,-9282.956,-2934.348,163.8473,0,0,0,100,0),
(@PATH,25,-9283.646,-2933.005,163.8473,0,0,0,100,0),
(@PATH,26,-9284.389,-2931.998,163.8473,0,0,0,100,0),
(@PATH,27,-9285.914,-2931.289,163.8473,0,0,0,100,0),
(@PATH,28,-9287.005,-2931.001,163.8473,0,0,0,100,0),
(@PATH,29,-9288.1,-2930.992,163.8473,0,0,0,100,0),
(@PATH,30,-9289.213,-2931.191,163.8473,0,0,0,100,0),
(@PATH,31,-9290.221,-2931.361,163.8473,0,0,0,100,0),
(@PATH,32,-9291.458,-2931.706,163.8473,0,0,0,100,0),
(@PATH,33,-9292.805,-2932.29,163.8473,0,0,0,100,0),
(@PATH,34,-9294.007,-2933.157,163.8473,0,0,0,100,0),
(@PATH,35,-9294.543,-2934.205,163.8473,0,0,0,100,0),
(@PATH,36,-9295.278,-2935.375,163.8471,0,0,0,100,0),
(@PATH,37,-9295.759,-2936.388,163.847,0,0,0,100,0),
(@PATH,38,-9295.738,-2938.026,163.8467,0,0,0,100,0),
(@PATH,39,-9295.685,-2939.59,163.8468,0,0,0,100,0),
(@PATH,40,-9295.391,-2940.761,163.8475,0,0,0,100,0),
(@PATH,41,-9294.498,-2942.447,163.8475,0,0,0,100,0),
(@PATH,42,-9293.198,-2943.878,163.8473,0,0,0,100,0),
(@PATH,43,-9291.648,-2944.502,163.8473,0,0,0,100,0),
(@PATH,44,-9289.801,-2945.168,163.8473,0,0,0,100,0),
(@PATH,45,-9288.234,-2945.503,163.8473,0,0,0,100,0),
(@PATH,46,-9286.938,-2945.095,163.8473,0,0,0,100,0),
(@PATH,47,-9285.65,-2944.349,163.8473,0,0,0,100,0),
(@PATH,48,-9284.43,-2943.57,163.8473,0,0,0,100,0),
(@PATH,49,-9283.33,-2942.828,163.8473,0,0,0,100,0),
(@PATH,50,-9282.16,-2941.825,163.8473,0,0,0,100,0),
(@PATH,51,-9283.208,-2942.748,163.8473,0,0,0,100,0),
(@PATH,52,-9284.43,-2943.57,163.8473,0,0,0,100,0),
(@PATH,53,-9285.65,-2944.349,163.8473,0,0,0,100,0),
(@PATH,54,-9286.938,-2945.095,163.8473,0,0,0,100,0),
(@PATH,55,-9288.209,-2945.509,163.8473,0,0,0,100,0),
(@PATH,56,-9289.801,-2945.168,163.8473,0,0,0,100,0),
(@PATH,57,-9291.648,-2944.502,163.8473,0,0,0,100,0),
(@PATH,58,-9293.198,-2943.878,163.8473,0,0,0,100,0);

-- Pathing for Blackrock Tracker Entry: 615
SET @NPC := 17316;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8726,`position_y`=-2374.531,`position_z`=157.9322 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8720.093,-2371.032,156.9322,0,0,0,100,0),
(@PATH,2,-8714.607,-2362.74,156.7913,0,0,0,100,0),
(@PATH,3,-8706.662,-2347.766,156.1663,0,0,0,100,0),
(@PATH,4,-8694.753,-2337.18,156.0414,0,0,0,100,0),
(@PATH,5,-8681.48,-2329.154,156.0413,0,0,0,100,0),
(@PATH,6,-8676.822,-2318.932,156.0413,0,0,0,100,0),
(@PATH,7,-8682.414,-2311.587,156.0413,0,0,0,100,0),
(@PATH,8,-8691.346,-2314.592,156.6663,0,0,0,100,0),
(@PATH,9,-8697.195,-2324.672,157.0413,0,0,0,100,0),
(@PATH,10,-8704.646,-2338.616,156.0413,0,0,0,100,0),
(@PATH,11,-8712.913,-2350.304,156.1663,0,0,0,100,0),
(@PATH,12,-8751.018,-2372.175,157.9172,0,0,0,100,0),
(@PATH,13,-8759.117,-2380.215,156.7922,0,0,0,100,0),
(@PATH,14,-8773.799,-2405.039,156.4857,0,0,0,100,0),
(@PATH,15,-8767.317,-2393.249,156.0413,0,0,0,100,0),
(@PATH,16,-8757.157,-2380.358,157.0422,0,0,0,100,0),
(@PATH,17,-8744.273,-2377.308,158.5422,0,0,0,100,0),
(@PATH,18,-8735.471,-2378.812,159.4172,0,0,0,100,0),
(@PATH,19,-8726,-2374.531,157.9322,0,0,0,100,0);

-- Pathing for Redridge Mongrel Entry: 423
SET @NPC := 16227;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=423,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=-9621.853,`position_y`=-2534.608,`position_z`=59.30342 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9611.43,-2537.291,59.55342,0,0,0,100,0),
(@PATH,2,-9596.484,-2523.148,62.104,0,0,0,100,0),
(@PATH,3,-9595.624,-2513.513,59.729,0,0,0,100,0),
(@PATH,4,-9578.707,-2505.862,59.229,0,0,0,100,0),
(@PATH,5,-9595.624,-2513.513,59.729,0,0,0,100,0),
(@PATH,6,-9596.484,-2523.148,62.104,0,0,0,100,0),
(@PATH,7,-9611.43,-2537.291,59.55342,0,0,0,100,0),
(@PATH,8,-9621.853,-2534.608,59.30342,0,0,0,100,0),
(@PATH,9,-9631.005,-2520.389,59.22416,0,0,0,100,0),
(@PATH,10,-9626.435,-2493.965,61.77357,0,0,0,100,0),
(@PATH,11,-9615.699,-2482.903,60.27357,0,0,0,100,0),
(@PATH,12,-9600.611,-2478.035,59.14857,0,0,0,100,0),
(@PATH,13,-9615.699,-2482.903,60.27357,0,0,0,100,0),
(@PATH,14,-9626.435,-2493.965,61.77357,0,0,0,100,0),
(@PATH,15,-9631.005,-2520.389,59.22416,0,0,0,100,0),
(@PATH,16,-9621.853,-2534.608,59.30342,0,0,0,100,0);

-- Pathing for Redridge Mongrel Entry: 423
SET @NPC := 16349;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9539.159,`position_y`=-1908.932,`position_z`=73.13508 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9515.88,-1927.064,76.08606,0,0,0,100,0),
(@PATH,2,-9539.159,-1908.932,73.13508,0,0,0,100,0),
(@PATH,3,-9535.29,-1892.516,74.76267,0,0,0,100,0),
(@PATH,4,-9488.921,-1881.527,82.08475,0,0,0,100,0),
(@PATH,5,-9479.733,-1869.828,84.58475,0,0,0,100,0),
(@PATH,6,-9488.921,-1881.527,82.08475,0,0,0,100,0),
(@PATH,7,-9535.29,-1892.516,74.76267,0,0,0,100,0),
(@PATH,8,-9539.159,-1908.932,73.13508,0,0,0,100,0);

-- Pathing for Redridge Mongrel Entry: 423
SET @NPC := 15218;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9632.086,`position_y`=-2441.966,`position_z`=63.98378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9606.604,-2486.99,60.02357,0,0,0,100,0),
(@PATH,2,-9602.279,-2502.665,59.72416,0,0,0,100,0),
(@PATH,3,-9609.739,-2488.236,60.27357,0,0,0,100,0),
(@PATH,4,-9625.794,-2448.716,63.23378,0,0,0,100,0),
(@PATH,5,-9632.086,-2441.966,63.98378,0,0,0,100,0);

-- Pathing for Redridge Poacher Entry: 424
SET @NPC := 15219;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9622.567,`position_y`=-2470.478,`position_z`=60.27357 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9609.739,-2488.236,60.27357,0,0,0,100,0),
(@PATH,2,-9606.604,-2486.99,60.02357,0,0,0,100,0),
(@PATH,3,-9602.279,-2502.665,59.72416,0,0,0,100,0),
(@PATH,4,-9609.739,-2488.236,60.27357,0,0,0,100,0),
(@PATH,5,-9622.567,-2470.478,60.27357,0,0,0,100,0),
(@PATH,6,-9625.794,-2448.716,63.23378,0,0,0,100,0),
(@PATH,7,-9622.567,-2470.478,60.27357,0,0,0,100,0);

-- Pathing for Redridge Poacher Entry: 424
SET @NPC := 16224;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9605.831,`position_y`=-2504.101,`position_z`=59.84916 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9617.936,-2505.087,60.59916,0,0,0,100,0),
(@PATH,2,-9624.509,-2515.335,59.47416,0,0,0,100,0),
(@PATH,3,-9638.779,-2525.417,59.05296,0,0,0,100,0),
(@PATH,4,-9628.489,-2516.524,59.34916,0,0,0,100,0),
(@PATH,5,-9615.57,-2504.555,60.34916,0,0,0,100,0),
(@PATH,6,-9605.831,-2504.101,59.84916,0,0,0,100,0),
(@PATH,7,-9602.604,-2510.273,59.34916,8000,0,0,100,0),
(@PATH,8,-9605.831,-2504.101,59.84916,0,0,0,100,0);

-- Pathing for Redridge Brute Entry: 426
SET @NPC := 10109;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9129.793,`position_y`=-2061.262,`position_z`=128.7022 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9129.67,-2045.571,128.7022,0,0,0,100,0),
(@PATH,2,-9136.09,-2034.611,128.5107,0,0,0,100,0),
(@PATH,3,-9129.67,-2045.571,128.7022,0,0,0,100,0),
(@PATH,4,-9129.793,-2061.262,128.7022,0,0,0,100,0),
(@PATH,5,-9102.493,-2073.968,128.7588,0,0,0,100,0),
(@PATH,6,-9081.025,-2073.283,128.7137,0,0,0,100,0),
(@PATH,7,-9061.23,-2083.464,129.3531,0,0,0,100,0),
(@PATH,8,-9081.025,-2073.283,128.7137,0,0,0,100,0),
(@PATH,9,-9102.493,-2073.968,128.7588,0,0,0,100,0),
(@PATH,10,-9129.793,-2061.262,128.7022,0,0,0,100,0);

-- Pathing for Redridge Brute Entry: 426
SET @NPC := 26003;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9081.852,`position_y`=-2446.575,`position_z`=123.6152 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9068.523,-2439.98,127.2402,0,0,0,100,0),
(@PATH,2,-9055.93,-2434.33,127.9016,0,0,0,100,0),
(@PATH,3,-9043.435,-2417.14,128.5205,0,0,0,100,0),
(@PATH,4,-9055.781,-2434.121,127.9016,0,0,0,100,0),
(@PATH,5,-9068.496,-2439.973,127.2402,0,0,0,100,0),
(@PATH,6,-9080.561,-2445.323,124.1152,0,0,0,100,0),
(@PATH,7,-9095.229,-2447.28,120.7402,0,0,0,100,0),
(@PATH,8,-9081.852,-2446.575,123.6152,0,0,0,100,0);

-- Pathing for Redridge Mystic Entry: 430
SET @NPC := 10108;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9085.817,`position_y`=-2041.056,`position_z`=129.4007 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9093.47,-2023.117,128.7757,0,0,0,100,0),
(@PATH,2,-9085.817,-2041.056,129.4007,0,0,0,100,0),
(@PATH,3,-9098.341,-2060.571,128.7757,0,0,0,100,0),
(@PATH,4,-9121.283,-2054.603,128.7022,0,0,0,100,0),
(@PATH,5,-9098.341,-2060.571,128.7757,0,0,0,100,0),
(@PATH,6,-9085.817,-2041.056,129.4007,0,0,0,100,0);

-- Pathing for Blackrock Champion Entry: 435
SET @NPC := 10171;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8719.215,`position_y`=-2162.265,`position_z`=157.9493 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8732.552,-2168.392,159.3678,0,0,0,100,0),
(@PATH,2,-8746.09,-2167.292,158.6607,0,0,0,100,0),
(@PATH,3,-8732.552,-2168.392,159.3678,0,0,0,100,0),
(@PATH,4,-8719.215,-2162.265,157.9493,0,0,0,100,0),
(@PATH,5,-8696.335,-2161.937,157.3559,0,0,0,100,0),
(@PATH,6,-8692.609,-2182.1,156.5922,0,0,0,100,0),
(@PATH,7,-8701.185,-2195.719,154.9269,0,0,0,100,0),
(@PATH,8,-8702.752,-2227.732,154.6221,0,0,0,100,0),
(@PATH,9,-8713.253,-2240.955,154.7007,0,0,0,100,0),
(@PATH,10,-8732.683,-2250.81,154.3486,0,0,0,100,0),
(@PATH,11,-8713.253,-2240.955,154.7007,0,0,0,100,0),
(@PATH,12,-8702.752,-2227.732,154.6221,0,0,0,100,0),
(@PATH,13,-8701.185,-2195.719,154.9269,0,0,0,100,0),
(@PATH,14,-8692.609,-2182.1,156.5922,0,0,0,100,0),
(@PATH,15,-8696.276,-2161.936,157.3557,0,0,0,100,0),
(@PATH,16,-8719.215,-2162.265,157.9493,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 10126;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8856.583,`position_y`=-1959.49,`position_z`=122.6195 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8869.44,-1973.048,123.1989,0,0,0,100,0),
(@PATH,2,-8872.306,-1987.248,125.6125,0,0,0,100,0),
(@PATH,3,-8871.035,-1998.969,123.9351,0,0,0,100,0),
(@PATH,4,-8874.864,-2010.225,123.8613,0,0,0,100,0),
(@PATH,5,-8881.981,-2014.834,124.7159,0,0,0,100,0),
(@PATH,6,-8890.29,-2014.196,125.0285,0,0,0,100,0),
(@PATH,7,-8882.051,-2014.828,124.7096,0,0,0,100,0),
(@PATH,8,-8874.864,-2010.225,123.8613,0,0,0,100,0),
(@PATH,9,-8871.035,-1998.969,123.9351,0,0,0,100,0),
(@PATH,10,-8872.306,-1987.248,125.6125,0,0,0,100,0),
(@PATH,11,-8869.474,-1973.084,123.2088,0,0,0,100,0),
(@PATH,12,-8856.583,-1959.49,122.6195,0,0,0,100,0),
(@PATH,13,-8854.203,-1933.718,124.2242,0,0,0,100,0),
(@PATH,14,-8849.34,-1913.927,126.1551,0,0,0,100,0),
(@PATH,15,-8874.792,-1914.902,132.0751,0,0,0,100,0),
(@PATH,16,-8889.941,-1926.165,135.8921,0,0,0,100,0),
(@PATH,17,-8903.536,-1951.488,137.975,0,0,0,100,0),
(@PATH,18,-8889.941,-1926.165,135.8921,0,0,0,100,0),
(@PATH,19,-8874.792,-1914.902,132.0751,0,0,0,100,0),
(@PATH,20,-8849.34,-1913.927,126.1551,0,0,0,100,0),
(@PATH,21,-8854.203,-1933.718,124.2242,0,0,0,100,0),
(@PATH,22,-8856.583,-1959.49,122.6195,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 16422;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8996.826,`position_y`=-2085.873,`position_z`=132.5694 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8962.664,-2081.184,132.5694,0,0,0,100,0),
(@PATH,2,-8996.826,-2085.873,132.5694,0,0,0,100,0),
(@PATH,3,-9022.803,-2096.318,132.0085,0,0,0,100,0),
(@PATH,4,-8996.826,-2085.873,132.5694,0,0,0,100,0);

-- Pathing for Redridge Drudger Entry: 580
SET @NPC := 11897;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8795.307,`position_y`=-1973.387,`position_z`=126.7356 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8801.047,-1955.703,126.1625,0,0,0,100,0),
(@PATH,2,-8795.307,-1973.387,126.7356,0,0,0,100,0),
(@PATH,3,-8782.728,-1980.681,128.0934,0,0,0,100,0),
(@PATH,4,-8772.052,-1993.34,129.6344,0,0,0,100,0),
(@PATH,5,-8768.62,-2016.962,130.0639,0,0,0,100,0),
(@PATH,6,-8786.789,-2040.241,127.6738,0,0,0,100,0),
(@PATH,7,-8804.953,-2054.536,129.402,0,0,0,100,0),
(@PATH,8,-8786.789,-2040.241,127.6738,0,0,0,100,0),
(@PATH,9,-8768.62,-2016.962,130.0639,0,0,0,100,0),
(@PATH,10,-8772.052,-1993.34,129.6344,0,0,0,100,0),
(@PATH,11,-8782.728,-1980.681,128.0934,0,0,0,100,0),
(@PATH,12,-8795.307,-1973.387,126.7356,0,0,0,100,0);

-- Pathing for Redridge Basher Entry: 446
SET @NPC := 11679;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9008.022,`position_y`=-2015.315,`position_z`=135.5978 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9013.389,-2001.146,135.8478,0,0,0,100,0),
(@PATH,2,-9020.631,-1992.944,136.1136,0,0,0,100,0),
(@PATH,3,-9032.95,-1992.436,138.1136,0,0,0,100,0),
(@PATH,4,-9020.631,-1992.944,136.1136,0,0,0,100,0),
(@PATH,5,-9013.389,-2001.146,135.8478,0,0,0,100,0),
(@PATH,6,-9008.022,-2015.315,135.5978,0,0,0,100,0),
(@PATH,7,-9000.12,-2022.714,135.7228,0,0,0,100,0),
(@PATH,8,-8983.734,-2024.047,135.9675,0,0,0,100,0),
(@PATH,9,-8976.881,-2007.302,135.8149,0,0,0,100,0),
(@PATH,10,-8945.093,-1989.848,138.4766,0,0,0,100,0),
(@PATH,11,-8928.801,-1979.029,139.8955,0,0,0,100,0),
(@PATH,12,-8918.683,-1984.234,140.0949,0,0,0,100,0),
(@PATH,13,-8893.354,-1992.97,136.0317,0,0,0,100,0),
(@PATH,14,-8918.683,-1984.234,140.0949,0,0,0,100,0),
(@PATH,15,-8928.801,-1979.029,139.8955,0,0,0,100,0),
(@PATH,16,-8944.557,-1989.485,138.5895,0,0,0,100,0),
(@PATH,17,-8976.881,-2007.302,135.8149,0,0,0,100,0),
(@PATH,18,-8983.734,-2024.047,135.9675,0,0,0,100,0),
(@PATH,19,-9000.12,-2022.714,135.7228,0,0,0,100,0),
(@PATH,20,-9008.022,-2015.315,135.5978,0,0,0,100,0);

-- Pathing for Redridge Mongrel Entry: 423
SET @NPC := 10095;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9475.37,`position_y`=-1934.13,`position_z`=80.3683 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9471.528,-1924.836,81.67286,0,0,0,100,0),
(@PATH,2,-9466.015,-1923.353,82.18614,0,0,0,100,0),
(@PATH,3,-9460.636,-1918.143,82.68614,0,0,0,100,0),
(@PATH,4,-9458.96,-1909.725,82.56114,0,0,0,100,0),
(@PATH,5,-9460.59,-1901.123,82.43614,0,0,0,100,0),
(@PATH,6,-9492.081,-1893.237,80.33475,0,0,0,100,0),
(@PATH,7,-9510.62,-1931.774,76.58606,0,0,0,100,0),
(@PATH,8,-9524.609,-1944.812,74.45707,0,0,0,100,0),
(@PATH,9,-9523.66,-1956.9,74.2286,0,0,0,100,0),
(@PATH,10,-9508.4,-1957.79,77.6211,0,0,0,100,0),
(@PATH,11,-9492.42,-1952.17,79.3943,0,0,0,100,0),
(@PATH,12,-9480.27,-1944.86,79.5265,0,0,0,100,0),
(@PATH,13,-9475.37,-1934.13,80.3683,0,0,0,100,0);

-- Pathing for Rabid Shadowhide Gnoll Entry: 434
SET @NPC := 10053;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9265.055,`position_y`=-3209.41,`position_z`=102.3781 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9292.012,-3240.249,100.6492,0,0,0,100,0),
(@PATH,2,-9310.653,-3233.226,100.8562,0,0,0,100,0),
(@PATH,3,-9343.33,-3233.92,95.33384,0,0,0,100,0),
(@PATH,4,-9376.466,-3260.896,88.62462,4000,0,0,100,0),
(@PATH,5,-9343.33,-3233.92,95.33384,0,0,0,100,0),
(@PATH,6,-9310.653,-3233.226,100.8562,0,0,0,100,0),
(@PATH,7,-9292.012,-3240.249,100.6492,0,0,0,100,0),
(@PATH,8,-9265.055,-3209.41,102.3781,0,0,0,100,0);

-- Pathing for Bone Chewer Entry: 210
SET @NPC := 5973;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10222.43,`position_y`=143.7129,`position_z`=2.255024 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10243.54,161.2734,0.0465889,0,0,0,100,0),
(@PATH,2,-10274.24,166.031,1.11338,0,0,0,100,0),
(@PATH,3,-10275.96,150.4307,1.513012,0,0,0,100,0),
(@PATH,4,-10261.48,138.3093,2.175644,0,0,0,100,0),
(@PATH,5,-10222.57,178.1452,0.4510765,0,0,0,100,0),
(@PATH,6,-10209.76,180.1912,1.390846,0,0,0,100,0),
(@PATH,7,-10204.68,164.0327,1.472527,0,0,0,100,0),
(@PATH,8,-10206.47,150.2491,1.775291,0,0,0,100,0),
(@PATH,9,-10222.43,143.7129,2.255024,0,0,0,100,0);

-- Pathing for Bone Chewer Entry: 210
SET @NPC := 4394;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=210,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=-10224.68,`position_y`=214.6403,`position_z`=2.800045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10221.75,199.632,2.804298,0,0,0,100,0),
(@PATH,2,-10224.68,214.6403,2.800045,0,0,0,100,0),
(@PATH,3,-10222.65,233.476,2.799393,0,0,0,100,0),
(@PATH,4,-10224.83,251.8642,2.799393,0,0,0,100,0),
(@PATH,5,-10236.47,256.503,2.799393,0,0,0,100,0),
(@PATH,6,-10240.21,269.6581,2.799393,0,0,0,100,0),
(@PATH,7,-10238.13,284.0669,2.799393,0,0,0,100,0),
(@PATH,8,-10229.13,286.6407,2.799393,0,0,0,100,0),
(@PATH,9,-10209.48,282.851,2.16798,0,0,0,100,0),
(@PATH,10,-10205.71,282.0735,2.416508,0,0,0,100,0),
(@PATH,11,-10201.7,282.9867,2.54327,0,0,0,100,0),
(@PATH,12,-10196.69,286.0379,2.193909,0,0,0,100,0),
(@PATH,13,-10195.89,292.459,2.453735,0,0,0,100,0),
(@PATH,14,-10200.42,308.0852,4.772118,0,0,0,100,0),
(@PATH,15,-10195.89,292.459,2.453735,0,0,0,100,0),
(@PATH,16,-10196.69,286.0379,2.193909,0,0,0,100,0),
(@PATH,17,-10201.7,282.9867,2.54327,0,0,0,100,0),
(@PATH,18,-10205.71,282.0735,2.416508,0,0,0,100,0),
(@PATH,19,-10209.48,282.851,2.16798,0,0,0,100,0),
(@PATH,20,-10229.13,286.6407,2.799393,0,0,0,100,0),
(@PATH,21,-10238.13,284.0669,2.799393,0,0,0,100,0),
(@PATH,22,-10240.21,269.6581,2.799393,0,0,0,100,0),
(@PATH,23,-10236.47,256.503,2.799393,0,0,0,100,0),
(@PATH,24,-10224.83,251.8642,2.799393,0,0,0,100,0),
(@PATH,25,-10222.65,233.476,2.799393,0,0,0,100,0),
(@PATH,26,-10224.68,214.6403,2.800045,0,0,0,100,0);

-- Pathing for Blackrock Outrunner Entry: 485
SET @NPC := 31809;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9164.028,`position_y`=-2442.941,`position_z`=110.9322 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9162.086,-2442.718,109.9972,10000,1,0,100,0),
(@PATH,2,-9140.406,-2451.874,110.0572,0,1,0,100,0),
(@PATH,3,-9112.781,-2462.785,119.0318,0,1,0,100,0),
(@PATH,4,-9107.47,-2472.122,120.0782,0,1,0,100,0),
(@PATH,5,-9110.72,-2477.348,119.7032,10000,1,0,100,0),
(@PATH,6,-9110.416,-2471.354,119.5782,0,1,0,100,0),
(@PATH,7,-9119.938,-2462.73,117.2818,0,1,0,100,0),
(@PATH,8,-9135.719,-2453.595,111.1822,0,1,0,100,0),
(@PATH,9,-9154.232,-2450.505,110.5572,0,1,0,100,0),
(@PATH,10,-9164.028,-2442.941,110.9322,0,1,0,100,0);
DELETE FROM `creature` WHERE `guid` IN (31833,31807);
DELETE FROM `creature_addon` WHERE `guid` IN (31833,31807);

-- Pathing for Watcher Ladimore Entry: 576
SET @NPC := 4211;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10577.47,`position_y`=-1165.161,`position_z`=28.14966 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10581.63,-1172.892,28.49362,0,0,0,100,0),
(@PATH,2,-10584.04,-1180.587,27.99362,0,0,0,100,0),
(@PATH,3,-10573.58,-1185.804,27.99362,0,0,0,100,0),
(@PATH,4,-10570.05,-1191.732,27.86862,0,0,0,100,0),
(@PATH,5,-10569.19,-1199.181,27.74362,0,0,0,100,0),
(@PATH,6,-10551.35,-1205.735,27.56617,0,0,0,100,0),
(@PATH,7,-10549.26,-1192.892,27.66226,0,0,0,100,0),
(@PATH,8,-10535.19,-1192.908,27.66226,0,0,0,100,0),
(@PATH,9,-10546.21,-1179.316,28.16226,0,0,0,100,0),
(@PATH,10,-10547.91,-1167.96,27.78726,0,0,0,100,0),
(@PATH,11,-10554.19,-1153.211,28.07649,0,0,0,100,0),
(@PATH,12,-10565.88,-1154.214,27.57649,0,0,0,100,0),
(@PATH,13,-10577.47,-1165.161,28.14966,0,0,0,100,0);

-- Pathing for Calor Entry: 663
SET @NPC := 4176;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10572.92,`position_y`=-1211.979,`position_z`=26.21894 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10581.87,-1200.016,27.71894,0,0,0,100,0),
(@PATH,2,-10581.5,-1199.797,27.74362,56000,0,0,100,0),
(@PATH,3,-10572.92,-1211.979,26.21894,8000,0,0,100,0);

-- Pathing for Morg Gnarltree Entry: 226
SET @NPC := 4082;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10596.64,`position_y`=-1163.852,`position_z`=30.05967 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10596.3,-1164.096,30.05967,0,0,0,100,0),
(@PATH,2,-10590.63,-1156.783,30.05967,0,0,0,100,0),
(@PATH,3,-10590.52,-1155.93,30.05967,55000,0,0,100,0),
(@PATH,4,-10590.21,-1156.136,30.05967,0,0,0,100,0),
(@PATH,5,-10596.64,-1163.852,30.05967,14000,0,0,100,0);

-- Pathing for Chef Grual Entry: 272
SET @NPC := 4192;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10499.35,`position_y`=-1157.982,`position_z`=28.08655 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10494.12,-1160.191,28.37647,45000,0,0,100,0),
(@PATH,2,-10498.6,-1160.361,28.08655,0,0,0,100,0),
(@PATH,3,-10498.77,-1161.604,28.08655,9000,0,0,100,0),
(@PATH,4,-10498.77,-1161.249,28.08655,0,0,0,100,0),
(@PATH,5,-10507.73,-1161.963,28.09953,0,0,0,100,0),
(@PATH,6,-10509.7,-1160.204,28.09953,6000,0,0,100,0),
(@PATH,7,-10509.61,-1160.543,28.09953,0,0,0,100,0),
(@PATH,8,-10507.16,-1161.83,28.09953,0,0,0,100,0),
(@PATH,9,-10499.27,-1159.314,28.08655,0,0,0,100,0),
(@PATH,10,-10499.35,-1157.982,28.08655,18000,0,0,100,0);
