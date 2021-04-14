-- Pathing for Arctic Ram Entry: 26426
SET @NPC := 133248;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3509.64,`position_y`=-750.9414,`position_z`=294.3868 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3511.387,-733.5805,299.6368,49000,0,0,100,0),
(@PATH,2,3509.64,-750.9414,294.3868,0,0,0,100,0),
(@PATH,3,3498.443,-768.702,291.2594,0,0,0,100,0),
(@PATH,4,3509.64,-750.9414,294.3868,0,0,0,100,0);

-- Pathing for Illusia Lune Entry: 27042
SET @NPC := 133617;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3647.948,`position_y`=-717.1948,`position_z`=215.0342 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3648.265,-715.3195,215.0314,0,0,0,100,0),
(@PATH,2,3644.507,-714.7984,214.2407,0,0,0,100,0),
(@PATH,3,3635.043,-713.5746,214.2407,0,0,0,100,0),
(@PATH,4,3644.625,-714.8554,214.2407,0,0,0,100,0),
(@PATH,5,3648.25,-715.2807,215.0314,0,0,0,100,0),
(@PATH,6,3647.977,-717.1859,215.0342,0,0,0,100,0),
(@PATH,7,3655.216,-718.0604,215.0296,0,0,0,100,0),
(@PATH,8,3647.948,-717.1948,215.0342,0,0,0,100,0);

-- Pathing for Ordal McLumpkins Entry: 27044
SET @NPC := 133619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=3621.722,`position_y`=-718.3648,`position_z`=215.0349 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,2,3619.423,-714.603,215.0349,35000,0,@PATH+1,100,0),
(@PATH,4,3616.081,-716.1984,215.0349,50000,0,@PATH+2,100,0),
(@PATH,6,3621.722,-718.3648,215.0349,35000,0,@PATH+2,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2,@PATH+3);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,1.466077,846),
(@PATH+1,1,2,83,69,0,847),
(@PATH+2,0,30,0,0,4.639134,848),
(@PATH+2,1,2,83,69,0,849);

-- Pathing for Hulking Jormungar Entry: 26293
SET @NPC := 113071;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4686.325,`position_y`=338.1416,`position_z`=116.9954 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4700.168,367.0156,118.5855,0,0,0,100,0),
(@PATH,2,4731.135,364.8878,126.2894,0,0,0,100,0),
(@PATH,3,4743.483,343.251,129.0478,0,0,0,100,0),
(@PATH,4,4713.793,315.9503,120.7992,0,0,0,100,0),
(@PATH,5,4686.325,338.1416,116.9954,0,0,0,100,0);

-- Pathing for Magnataur Patriarch Entry: 26295
SET @NPC := 113266;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4049.302,`position_y`=-29.04574,`position_z`=55.26999 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4047.976,-37.78185,55.98508,0,0,0,100,0),
(@PATH,2,4047.698,-50.11871,53.98508,0,0,0,100,0),
(@PATH,3,4047.976,-37.78185,55.98508,0,0,0,100,0),
(@PATH,4,4049.302,-29.04574,55.26999,0,0,0,100,0),
(@PATH,5,4047.754,-16.93381,53.89499,0,0,0,100,0),
(@PATH,6,4049.302,-29.04574,55.26999,0,0,0,100,0);

-- Pathing for Crystalline Ice Elemental Entry: 26316
SET @NPC := 115062;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4860.147,`position_y`=992.9332,`position_z`=210.192 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4869.752,1002.653,215.5425,0,0,0,100,0),
(@PATH,2,4860.147,992.9332,210.192,0,0,0,100,0),
(@PATH,3,4850.6,983.3943,204.442,0,0,0,100,0),
(@PATH,4,4844.505,971.259,198.692,0,0,0,100,0),
(@PATH,5,4858.342,938.2769,188.1321,0,0,0,100,0),
(@PATH,6,4844.505,971.259,198.692,0,0,0,100,0),
(@PATH,7,4850.6,983.3943,204.442,0,0,0,100,0),
(@PATH,8,4860.147,992.9332,210.192,0,0,0,100,0);

-- Pathing for Crystalline Ice Elemental Entry: 26316
SET @NPC := 115054;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4917.303,`position_y`=924.0703,`position_z`=223.1336 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4929.146,915.8573,220.6336,0,0,0,100,0),
(@PATH,2,4940.256,927.373,227.7124,0,0,0,100,0),
(@PATH,3,4941.91,938.2441,233.9879,0,0,0,100,0),
(@PATH,4,4938.07,947.0781,238.7379,0,0,0,100,0),
(@PATH,5,4917.303,924.0703,223.1336,0,0,0,100,0);

-- Pathing for Crystalline Ice Giant Entry: 26291
SET @NPC := 112865;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4770.23,`position_y`=469.9691,`position_z`=111.7675 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4796.084,455.2377,109.338,54000,0,@PATH+1,100,0),
(@PATH,2,4770.23,469.9691,111.7675,22000,0,@PATH+2,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,2.9147,850),
(@PATH+2,0,30,0,0,5.201081,851);

-- Pathing for Crystalline Ice Giant Entry: 26291
SET @NPC := 112866;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4874.087,`position_y`=452.3281,`position_z`=115.6979 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4888.814,445.456,118.1979,5000,0,@PATH+1,100,0),
(@PATH,2,4901.041,426.041,116.2949,0,0,0,100,0),
(@PATH,3,4901.041,426.041,116.2949,6000,0,@PATH+2,100,0),
(@PATH,4,4874.087,452.3281,115.6979,0,0,0,100,0),
(@PATH,5,4874.087,452.3281,115.6979,8000,0,@PATH+3,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2,@PATH+3);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,0.8552113,852),
(@PATH+2,0,30,0,0,0.8901179,853),
(@PATH+3,0,30,0,0,0.06981317,854);

-- Pathing for Rabbit Entry: 721
SET @NPC := 115702;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5753.539,`position_y`=772.873,`position_z`=640.8826 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5767.785,754.2614,641.7114,0,0,0,100,0),
(@PATH,2,5773.825,766.6644,640.7427,0,0,0,100,0),
(@PATH,3,5767.785,754.2614,641.7114,5000,0,0,100,0),
(@PATH,4,5753.539,772.873,640.8826,0,0,0,100,0),
(@PATH,5,5748.938,764.3101,641.9448,0,0,0,100,0),
(@PATH,6,5733.615,778.2639,641.7114,0,0,0,100,0),
(@PATH,7,5737.831,782.386,641.448,0,0,0,100,0),
(@PATH,8,5740.602,787.1411,641.0325,0,0,0,100,0),
(@PATH,9,5733.241,793.4806,640.9481,0,0,0,100,0),
(@PATH,10,5722.088,796.697,641.5259,0,0,0,100,0),
(@PATH,11,5726.339,806.3635,640.8337,0,0,0,100,0),
(@PATH,12,5722.138,815.5085,640.8914,0,0,0,100,0),
(@PATH,13,5714.45,821.5867,641.2027,0,0,0,100,0),
(@PATH,14,5700.078,828.2365,641.8647,0,0,0,100,0),
(@PATH,15,5698.136,820.8531,641.5467,0,0,0,100,0),
(@PATH,16,5709.789,810.5593,641.5497,0,0,0,100,0),
(@PATH,17,5698.065,820.5817,641.5533,0,0,0,100,0),
(@PATH,18,5700.078,828.2365,641.8647,0,0,0,100,0),
(@PATH,19,5714.45,821.5867,641.2027,0,0,0,100,0),
(@PATH,20,5722.138,815.5085,640.8914,0,0,0,100,0),
(@PATH,21,5726.339,806.3635,640.8337,0,0,0,100,0),
(@PATH,22,5722.088,796.697,641.5259,0,0,0,100,0),
(@PATH,23,5733.241,793.4806,640.9481,0,0,0,100,0),
(@PATH,24,5740.602,787.1411,641.0325,0,0,0,100,0),
(@PATH,25,5737.831,782.386,641.448,0,0,0,100,0),
(@PATH,26,5733.615,778.2639,641.7114,0,0,0,100,0),
(@PATH,27,5748.938,764.3101,641.9448,0,0,0,100,0),
(@PATH,28,5753.539,772.873,640.8826,0,0,0,100,0);

-- Pathing for Putrid Wight Entry: 23992
SET @NPC := 113344;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2668.823,`position_y`=-3746.312,`position_z`=249.9565 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2646.826,-3743.444,246.5889,0,0,0,100,0),
(@PATH,2,2629.433,-3732.29,245.4538,0,0,0,100,0),
(@PATH,3,2623.224,-3719.469,245.4964,0,0,0,100,0),
(@PATH,4,2627.88,-3711.047,246.3409,0,0,0,100,0),
(@PATH,5,2639.799,-3709.354,243.2022,0,0,0,100,0),
(@PATH,6,2647.973,-3713.873,239.3536,0,0,0,100,0),
(@PATH,7,2655.269,-3720.628,235.0643,0,0,0,100,0),
(@PATH,8,2664.609,-3723.947,230.2771,0,0,0,100,0),
(@PATH,9,2672.977,-3721.034,225.9482,0,0,0,100,0),
(@PATH,10,2680.715,-3711.313,221.8469,6000,0,0,100,0),
(@PATH,11,2677.229,-3716.424,222.8778,0,0,0,100,0),
(@PATH,12,2668.853,-3722.688,228.2985,0,0,0,100,0),
(@PATH,13,2659.52,-3723.743,232.6282,0,0,0,100,0),
(@PATH,14,2651.728,-3716.389,237.3867,0,0,0,100,0),
(@PATH,15,2643.281,-3709.406,241.6877,0,0,0,100,0),
(@PATH,16,2632.315,-3711.092,245.6459,0,0,0,100,0),
(@PATH,17,2624.75,-3717.884,245.7113,0,0,0,100,0),
(@PATH,18,2624.219,-3728.446,245.2014,0,0,0,100,0),
(@PATH,19,2631.771,-3736.979,245.6085,0,0,0,100,0),
(@PATH,20,2643.255,-3747.242,246.4638,0,0,0,100,0),
(@PATH,21,2655.134,-3751.437,248.9429,0,0,0,100,0),
(@PATH,22,2662.831,-3751.152,249.8362,0,0,0,100,0),
(@PATH,23,2668.823,-3746.312,249.9565,8000,0,0,100,0);

-- Pathing for Putrid Wight Entry: 23992
SET @NPC := 113343;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2785.402,`position_y`=-3613.447,`position_z`=250.922 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2785.402,-3613.447,250.922,0,0,0,100,0),
(@PATH,2,2785.44,-3590.348,251.3575,0,0,0,100,0),
(@PATH,3,2780.647,-3566.933,248.1158,0,0,0,100,0),
(@PATH,4,2776.989,-3563.271,247.6174,6000,0,0,100,0),
(@PATH,5,2786.118,-3579.14,249.4645,0,0,0,100,0),
(@PATH,6,2789.177,-3593.625,250.844,0,0,0,100,0),
(@PATH,7,2784.655,-3606.138,251.7757,0,0,0,100,0),
(@PATH,8,2778.348,-3606.077,253.5872,0,0,0,100,0),
(@PATH,9,2781.997,-3610.31,252.2005,0,0,0,100,0),
(@PATH,10,2789.771,-3615.286,249.8559,0,0,0,100,0),
(@PATH,11,2796.63,-3628.361,248.4757,0,0,0,100,0),
(@PATH,12,2798.595,-3636.199,247.7422,0,0,0,100,0),
(@PATH,13,2794.572,-3637.352,248.0836,0,0,0,100,0),
(@PATH,14,2806.817,-3639.35,246.4777,0,0,0,100,0),
(@PATH,15,2815.37,-3643.385,242.7697,0,0,0,100,0),
(@PATH,16,2817.436,-3655.363,242.607,0,0,0,100,0),
(@PATH,17,2803.864,-3660.431,246.2676,0,0,0,100,0),
(@PATH,18,2790.148,-3659.774,245.6176,0,0,0,100,0),
(@PATH,19,2783.257,-3650.315,241.2681,0,0,0,100,0),
(@PATH,20,2778.241,-3638.333,235.9849,0,0,0,100,0),
(@PATH,21,2771.057,-3630.219,230.9954,0,0,0,100,0),
(@PATH,22,2761.502,-3627.29,226.378,0,0,0,100,0),
(@PATH,23,2751.042,-3632.291,221.8077,6000,0,0,100,0),
(@PATH,24,2754.787,-3630.722,223.3591,0,0,0,100,0),
(@PATH,25,2766.29,-3628.396,228.8643,0,0,0,100,0),
(@PATH,26,2774.306,-3633.359,232.863,0,0,0,100,0),
(@PATH,27,2779.261,-3642.92,237.6714,0,0,0,100,0),
(@PATH,28,2785.011,-3652.979,242.7388,0,0,0,100,0),
(@PATH,29,2792.728,-3659.369,246.4393,0,0,0,100,0),
(@PATH,30,2806.87,-3658.866,245.5233,0,0,0,100,0),
(@PATH,31,2817.342,-3650.064,242.2243,0,0,0,100,0),
(@PATH,32,2799.635,-3631.787,247.9718,0,0,0,100,0),
(@PATH,33,2785.402,-3613.447,250.922,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2809.687,`position_y`=-3622.016,`position_z`=161.3961 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2814.799,-3624.542,161.3958,0,0,0,100,0),
(@PATH,2,2823.035,-3625.648,161.3949,0,0,0,100,0),
(@PATH,3,2829.876,-3624.724,161.3975,0,0,0,100,0),
(@PATH,4,2836.048,-3620.994,161.3983,0,0,0,100,0),
(@PATH,5,2841.855,-3615.051,161.3947,0,0,0,100,0),
(@PATH,6,2844.207,-3609.994,161.3975,0,0,0,100,0),
(@PATH,7,2845.186,-3601.875,161.3951,0,0,0,100,0),
(@PATH,8,2844.337,-3594.973,161.3975,0,0,0,100,0),
(@PATH,9,2840.764,-3588.99,161.3957,0,0,0,100,0),
(@PATH,10,2834.76,-3583.182,161.3952,0,0,0,100,0),
(@PATH,11,2829.575,-3580.736,161.3979,0,0,0,100,0),
(@PATH,12,2821.425,-3579.65,161.3952,0,0,0,100,0),
(@PATH,13,2814.341,-3580.5,161.4046,0,0,0,100,0),
(@PATH,14,2808.07,-3583.772,161.4029,0,0,0,100,0),
(@PATH,15,2802.685,-3590.109,161.395,0,0,0,100,0),
(@PATH,16,2800.225,-3595.279,161.3977,0,0,0,100,0),
(@PATH,17,2799.105,-3603.418,161.3947,0,0,0,100,0),
(@PATH,18,2800.01,-3610.333,161.3973,0,0,0,100,0),
(@PATH,19,2803.705,-3616.418,161.3981,0,0,0,100,0),
(@PATH,20,2809.687,-3622.016,161.3961,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97248;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2824.036,`position_y`=-3624.829,`position_z`=221.4252 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2816.773,-3623.985,221.4255,0,0,0,100,0),
(@PATH,2,2809.992,-3621.294,221.4247,0,0,0,100,0),
(@PATH,3,2803.77,-3615.729,221.4243,0,0,0,100,0),
(@PATH,4,2800.449,-3608.825,221.4259,0,0,0,100,0),
(@PATH,5,2799.794,-3601.215,221.4245,0,0,0,100,0),
(@PATH,6,2802.056,-3593.389,221.4274,0,0,0,100,0),
(@PATH,7,2806.402,-3587.211,221.4274,0,0,0,100,0),
(@PATH,8,2812.614,-3583.304,221.4273,0,0,0,100,0),
(@PATH,9,2819.016,-3581.604,221.4285,0,0,0,100,0),
(@PATH,10,2825.446,-3581.84,221.4301,0,0,0,100,0),
(@PATH,11,2831.818,-3583.644,221.4293,0,0,0,100,0),
(@PATH,12,2836.348,-3587.178,221.4313,0,0,0,100,0),
(@PATH,13,2839.835,-3592.544,221.434,0,0,0,100,0),
(@PATH,14,2842.145,-3599.79,221.4294,0,0,0,100,0),
(@PATH,15,2843.347,-3608.321,221.4291,0,0,0,100,0),
(@PATH,16,2840.997,-3614.059,221.4281,0,0,0,100,0),
(@PATH,17,2836.926,-3619.116,221.4238,0,0,0,100,0),
(@PATH,18,2831.312,-3622.841,221.4241,0,0,0,100,0),
(@PATH,19,2824.036,-3624.829,221.4252,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97260;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2586.513,`position_y`=-3756.084,`position_z`=161.398 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2594.313,-3758.43,161.3953,0,0,0,100,0),
(@PATH,2,2601.175,-3758.778,161.3977,0,0,0,100,0),
(@PATH,3,2607.68,-3756.348,161.3983,0,0,0,100,0),
(@PATH,4,2614.385,-3751.512,161.3951,0,0,0,100,0),
(@PATH,5,2617.877,-3746.704,161.3976,0,0,0,100,0),
(@PATH,6,2620.328,-3738.942,161.3956,0,0,0,100,0),
(@PATH,7,2620.506,-3731.859,161.3961,0,0,0,100,0),
(@PATH,8,2618.016,-3725.396,161.3984,0,0,0,100,0),
(@PATH,9,2612.961,-3718.617,161.3952,0,0,0,100,0),
(@PATH,10,2608.518,-3715.498,161.398,0,0,0,100,0),
(@PATH,11,2600.665,-3713.045,161.3954,0,0,0,100,0),
(@PATH,12,2593.633,-3712.684,161.4046,0,0,0,100,0),
(@PATH,13,2586.809,-3714.743,161.4106,0,0,0,100,0),
(@PATH,14,2580.48,-3720.084,161.3953,0,0,0,100,0),
(@PATH,15,2577.218,-3724.641,161.3979,0,0,0,100,0),
(@PATH,16,2574.743,-3732.453,161.3959,0,0,0,100,0),
(@PATH,17,2574.244,-3739.552,161.3972,0,0,0,100,0),
(@PATH,18,2576.927,-3746.14,161.3958,0,0,0,100,0),
(@PATH,19,2581.687,-3752.61,161.398,0,0,0,100,0),
(@PATH,20,2586.513,-3756.084,161.398,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 203503;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2603.992,`position_y`=-3713.681,`position_z`=141.3663 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2597.609,-3712.674,141.3633,0,0,0,100,0),
(@PATH,2,2593.398,-3712.327,141.3879,0,0,0,100,0),
(@PATH,3,2587.152,-3715.266,141.3655,0,0,0,100,0),
(@PATH,4,2580.309,-3720.183,141.3624,0,0,0,100,0),
(@PATH,5,2576.709,-3724.49,141.3625,0,0,0,100,0),
(@PATH,6,2574.215,-3732.656,141.3617,0,0,0,100,0),
(@PATH,7,2574.386,-3739.554,141.3635,0,0,0,100,0),
(@PATH,8,2576.045,-3746.666,141.3606,0,0,0,100,0),
(@PATH,9,2579.443,-3751.851,141.3886,0,0,0,100,0),
(@PATH,10,2584.13,-3754.667,141.3627,0,0,0,100,0),
(@PATH,11,2590.743,-3758.33,141.3646,0,0,0,100,0),
(@PATH,12,2597.277,-3758.514,141.364,0,0,0,100,0),
(@PATH,13,2605.202,-3757.24,141.363,0,0,0,100,0),
(@PATH,14,2611.11,-3754.3,141.3651,0,0,0,100,0),
(@PATH,15,2616.42,-3749.062,141.363,0,0,0,100,0),
(@PATH,16,2619.533,-3741.9,141.3637,0,0,0,100,0),
(@PATH,17,2620.534,-3736.029,141.3637,0,0,0,100,0),
(@PATH,18,2618.751,-3727.877,141.3636,0,0,0,100,0),
(@PATH,19,2616.373,-3722.089,141.3558,0,0,0,100,0),
(@PATH,20,2610.62,-3717.114,141.3638,0,0,0,100,0),
(@PATH,21,2603.992,-3713.681,141.3663,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 115178;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2810.375,`position_y`=-3582.374,`position_z`=141.3599 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2805.214,-3586.358,141.3641,0,0,0,100,0),
(@PATH,2,2801.175,-3592.824,141.363,0,0,0,100,0),
(@PATH,3,2798.759,-3600.248,141.3618,0,0,0,100,0),
(@PATH,4,2799.583,-3606.401,141.3644,0,0,0,100,0),
(@PATH,5,2802.503,-3614.063,141.3632,0,0,0,100,0),
(@PATH,6,2805.852,-3619.302,141.3641,0,0,0,100,0),
(@PATH,7,2812.384,-3623.335,141.3662,0,0,0,100,0),
(@PATH,8,2819.554,-3625.753,141.3661,0,0,0,100,0),
(@PATH,9,2825.986,-3625.251,141.364,0,0,0,100,0),
(@PATH,10,2833.809,-3622.541,141.3623,0,0,0,100,0),
(@PATH,11,2838.974,-3618.843,141.3642,0,0,0,100,0),
(@PATH,12,2843.044,-3612.401,141.3634,0,0,0,100,0),
(@PATH,13,2845.442,-3605.066,141.3624,0,0,0,100,0),
(@PATH,14,2845.091,-3598.814,141.3633,0,0,0,100,0),
(@PATH,15,2842.213,-3590.969,141.3621,0,0,0,100,0),
(@PATH,16,2838.518,-3585.883,141.3633,0,0,0,100,0),
(@PATH,17,2831.972,-3581.769,141.3635,0,0,0,100,0),
(@PATH,18,2824.755,-3579.538,141.3658,0,0,0,100,0),
(@PATH,19,2818.303,-3579.807,141.3651,0,0,0,100,0),
(@PATH,20,2810.375,-3582.374,141.3599,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97251;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2801.415,`position_y`=-3592.805,`position_z`=181.4086 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2805.63,-3586.741,181.4093,0,0,0,100,0),
(@PATH,2,2810.837,-3582.852,181.4067,0,0,0,100,0),
(@PATH,3,2818.372,-3579.891,181.4075,0,0,0,100,0),
(@PATH,4,2824.698,-3579.42,181.4061,0,0,0,100,0),
(@PATH,5,2831.986,-3581.824,181.4095,0,0,0,100,0),
(@PATH,6,2838.559,-3585.897,181.4075,0,0,0,100,0),
(@PATH,7,2842.173,-3590.988,181.4084,0,0,0,100,0),
(@PATH,8,2845.01,-3598.905,181.3987,0,0,0,100,0),
(@PATH,9,2845.163,-3605.083,181.4067,0,0,0,100,0),
(@PATH,10,2842.933,-3612.533,181.4066,0,0,0,100,0),
(@PATH,11,2839.144,-3618.943,181.4076,0,0,0,100,0),
(@PATH,12,2833.877,-3622.96,181.4045,0,0,0,100,0),
(@PATH,13,2826.177,-3625.395,181.4086,0,0,0,100,0),
(@PATH,14,2819.915,-3625.802,181.4059,0,0,0,100,0),
(@PATH,15,2812.322,-3623.443,181.3985,0,0,0,100,0),
(@PATH,16,2805.912,-3619.149,181.4085,0,0,0,100,0),
(@PATH,17,2801.737,-3614.466,181.4039,0,0,0,100,0),
(@PATH,18,2799.258,-3606.344,181.4081,0,0,0,100,0),
(@PATH,19,2798.46,-3600.148,181.4072,0,0,0,100,0),
(@PATH,20,2801.415,-3592.805,181.4086,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 115180;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2819.609,`position_y`=-3625.823,`position_z`=201.4168 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2825.926,-3625.365,201.4147,0,0,0,100,0),
(@PATH,2,2833.738,-3622.546,201.414,0,0,0,100,0),
(@PATH,3,2838.858,-3618.962,201.4162,0,0,0,100,0),
(@PATH,4,2842.757,-3612.3,201.4155,0,0,0,100,0),
(@PATH,5,2845.156,-3605.187,201.4145,0,0,0,100,0),
(@PATH,6,2845.112,-3598.919,201.4165,0,0,0,100,0),
(@PATH,7,2842.278,-3590.991,201.4143,0,0,0,100,0),
(@PATH,8,2838.798,-3585.699,201.4129,0,0,0,100,0),
(@PATH,9,2832.123,-3581.366,201.4112,0,0,0,100,0),
(@PATH,10,2824.705,-3579.036,201.4159,0,0,0,100,0),
(@PATH,11,2818.319,-3579.608,201.414,0,0,0,100,0),
(@PATH,12,2810.397,-3582.356,201.4127,0,0,0,100,0),
(@PATH,13,2805.141,-3585.997,201.4149,0,0,0,100,0),
(@PATH,14,2801.093,-3592.536,201.4165,0,0,0,100,0),
(@PATH,15,2798.692,-3600.158,201.4118,0,0,0,100,0),
(@PATH,16,2799.542,-3606.275,201.4129,0,0,0,100,0),
(@PATH,17,2802.349,-3614.061,201.4144,0,0,0,100,0),
(@PATH,18,2805.995,-3619.276,201.4165,0,0,0,100,0),
(@PATH,19,2812.382,-3623.6,201.4161,0,0,0,100,0),
(@PATH,20,2819.609,-3625.823,201.4168,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97241;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2576.456,`position_y`=-3746.067,`position_z`=201.4139 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2581.68,-3752.681,201.414,0,0,0,100,0),
(@PATH,2,2586.568,-3756.62,201.413,0,0,0,100,0),
(@PATH,3,2594.226,-3758.521,201.4138,0,0,0,100,0),
(@PATH,4,2601.322,-3758.976,201.4392,0,0,0,100,0),
(@PATH,5,2608.325,-3756.202,201.4066,0,0,0,100,0),
(@PATH,6,2614.482,-3751.383,201.4148,0,0,0,100,0),
(@PATH,7,2617.85,-3746.781,201.4146,0,0,0,100,0),
(@PATH,8,2620.605,-3739.148,201.4127,0,0,0,100,0),
(@PATH,9,2620.888,-3731.896,201.415,0,0,0,100,0),
(@PATH,10,2618.019,-3725.131,201.4144,0,0,0,100,0),
(@PATH,11,2613.131,-3718.841,201.4171,0,0,0,100,0),
(@PATH,12,2608.565,-3715.357,201.4166,0,0,0,100,0),
(@PATH,13,2600.781,-3713.322,201.4151,0,0,0,100,0),
(@PATH,14,2593.642,-3712.292,201.4142,0,0,0,100,0),
(@PATH,15,2586.736,-3714.775,201.4059,0,0,0,100,0),
(@PATH,16,2580.157,-3719.908,201.413,0,0,0,100,0),
(@PATH,17,2577.031,-3724.391,201.4146,0,0,0,100,0),
(@PATH,18,2574.256,-3732.734,201.4134,0,0,0,100,0),
(@PATH,19,2573.823,-3739.465,201.4134,0,0,0,100,0),
(@PATH,20,2576.456,-3746.067,201.4139,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97249;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2611.017,`position_y`=-3716.675,`position_z`=181.398 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2616.453,-3722.186,181.4082,0,0,0,100,0),
(@PATH,2,2619.343,-3727.752,181.4051,0,0,0,100,0),
(@PATH,3,2620.622,-3735.984,181.4042,0,0,0,100,0),
(@PATH,4,2619.866,-3742.29,181.4087,0,0,0,100,0),
(@PATH,5,2616.442,-3749.24,181.4057,0,0,0,100,0),
(@PATH,6,2611.063,-3754.8,181.4085,0,0,0,100,0),
(@PATH,7,2604.478,-3757.701,181.4068,0,0,0,100,0),
(@PATH,8,2597.286,-3758.759,181.4067,0,0,0,100,0),
(@PATH,9,2590.852,-3757.972,181.4083,0,0,0,100,0),
(@PATH,10,2584.248,-3754.43,181.4082,0,0,0,100,0),
(@PATH,11,2578.261,-3749.372,181.4069,0,0,0,100,0),
(@PATH,12,2575.873,-3743.828,181.4057,0,0,0,100,0),
(@PATH,13,2574.191,-3735.234,181.4073,0,0,0,100,0),
(@PATH,14,2575.195,-3729.327,181.4094,0,0,0,100,0),
(@PATH,15,2578.681,-3722.37,181.4084,0,0,0,100,0),
(@PATH,16,2583.938,-3716.915,181.4063,0,0,0,100,0),
(@PATH,17,2589.764,-3714.326,181.4076,0,0,0,100,0),
(@PATH,18,2597.566,-3712.55,181.4071,0,0,0,100,0),
(@PATH,19,2604.017,-3713.141,181.4054,0,0,0,100,0),
(@PATH,20,2611.017,-3716.675,181.398,0,0,0,100,0);

-- Pathing for Necrolord Entry: 24014
SET @NPC := 97250;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24014,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2585.757,`position_y`=-3717.824,`position_z`=221.4304 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2579.807,-3722.263,221.4254,0,0,0,100,0),
(@PATH,2,2575.761,-3730.515,221.4254,0,0,0,100,0),
(@PATH,3,2575.521,-3739.346,221.4455,0,0,0,100,0),
(@PATH,4,2577.731,-3745.002,221.4266,0,0,0,100,0),
(@PATH,5,2581.885,-3751.379,221.4258,0,0,0,100,0),
(@PATH,6,2588.023,-3755.677,221.4271,0,0,0,100,0),
(@PATH,7,2596.354,-3757.416,221.4265,0,0,0,100,0),
(@PATH,8,2602.154,-3756.99,221.4272,0,0,0,100,0),
(@PATH,9,2608.952,-3753.872,221.4283,0,0,0,100,0),
(@PATH,10,2613.777,-3748.49,221.4299,0,0,0,100,0),
(@PATH,11,2616.507,-3743.333,221.4301,0,0,0,100,0),
(@PATH,12,2617.603,-3736.914,221.4314,0,0,0,100,0),
(@PATH,13,2616.173,-3730.112,221.4334,0,0,0,100,0),
(@PATH,14,2611.927,-3721.691,221.432,0,0,0,100,0),
(@PATH,15,2605.345,-3717.231,221.4332,0,0,0,100,0),
(@PATH,16,2595.783,-3715.589,221.4307,0,0,0,100,0),
(@PATH,17,2585.757,-3717.824,221.4304,0,0,0,100,0);

-- Pathing for Fearsome Horror Entry: 24073
SET @NPC := 97267;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2685.435,`position_y`=-3516.336,`position_z`=161.3539 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2662.709,-3500.542,161.3926,0,0,0,100,0),
(@PATH,2,2650.608,-3502.922,161.3893,0,0,0,100,0),
(@PATH,3,2642.166,-3507.048,161.4015,0,0,0,100,0),
(@PATH,4,2640.603,-3513.472,161.4016,0,0,0,100,0),
(@PATH,5,2643.823,-3521.674,161.4016,0,0,0,100,0),
(@PATH,6,2647.113,-3529.029,161.403,0,0,0,100,0),
(@PATH,7,2655.038,-3531.975,161.4017,0,0,0,100,0),
(@PATH,8,2671.99,-3521.808,161.3573,0,0,0,100,0),
(@PATH,9,2673.333,-3507.633,161.3396,0,0,0,100,0),
(@PATH,10,2675.246,-3494.586,161.3678,0,0,0,100,0),
(@PATH,11,2685.497,-3487.036,161.3884,0,0,0,100,0),
(@PATH,12,2692.917,-3484.15,161.3961,0,0,0,100,0),
(@PATH,13,2699.012,-3487.089,161.4006,0,0,0,100,0),
(@PATH,14,2706.217,-3502.243,161.4013,0,0,0,100,0),
(@PATH,15,2703.759,-3510.093,161.4025,0,0,0,100,0),
(@PATH,16,2685.435,-3516.336,161.3539,0,0,0,100,0);

-- Pathing for Fearsome Horror Entry: 24073
SET @NPC := 97246;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2579.879,`position_y`=-3696.3,`position_z`=161.4409 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2588.232,-3690.074,161.4458,0,0,0,100,0),
(@PATH,2,2589.271,-3684.429,161.4359,0,0,0,100,0),
(@PATH,3,2585.342,-3675.472,161.4335,0,0,0,100,0),
(@PATH,4,2581.837,-3668.191,161.4327,0,0,0,100,0),
(@PATH,5,2575.887,-3666.925,161.4406,0,0,0,100,0),
(@PATH,6,2570.748,-3698.407,161.4427,0,0,0,100,0),
(@PATH,7,2579.879,-3696.3,161.4409,0,0,0,100,0);

-- Pathing for Fearsome Horror Entry: 24073
SET @NPC := 105763;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `id`=24073,`modelid`=0,`spawndist`=0,`MovementType`=2,`position_x`=2725.236,`position_y`=-3392.25,`position_z`=159.6907 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2727.104,-3390.643,159.6644,0,0,0,100,0),
(@PATH,2,2724.281,-3389.372,159.6592,0,0,0,100,0),
(@PATH,3,2721.806,-3387.376,159.6504,0,0,0,100,0),
(@PATH,4,2722.977,-3393.822,159.6598,0,0,0,100,0),
(@PATH,5,2725.236,-3392.25,159.6907,0,0,0,100,0);

-- Pathing for Fearsome Horror Entry: 24073
SET @NPC := 97252;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2813.579,`position_y`=-3620.822,`position_z`=161.4043 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2820.259,-3622.993,161.4039,0,0,0,100,0),
(@PATH,2,2825.655,-3622.695,161.4055,0,0,0,100,0),
(@PATH,3,2832.094,-3620.313,161.4071,0,0,0,100,0),
(@PATH,4,2836.655,-3616.929,161.4057,0,0,0,100,0),
(@PATH,5,2840.545,-3611.404,161.4061,0,0,0,100,0),
(@PATH,6,2842.39,-3604.52,161.4045,0,0,0,100,0),
(@PATH,7,2842.031,-3599.292,161.4063,0,0,0,100,0),
(@PATH,8,2839.814,-3592.598,161.4043,0,0,0,100,0),
(@PATH,9,2836.608,-3587.857,161.4041,0,0,0,100,0),
(@PATH,10,2830.603,-3584.255,161.4064,0,0,0,100,0),
(@PATH,11,2823.961,-3581.964,161.4031,0,0,0,100,0),
(@PATH,12,2818.599,-3582.841,161.4023,0,0,0,100,0),
(@PATH,13,2809.316,-3579.184,161.4106,0,0,0,100,0),
(@PATH,14,2801.529,-3572.713,161.4457,0,0,0,100,0),
(@PATH,15,2795.903,-3559.435,161.579,0,0,0,100,0),
(@PATH,16,2793.693,-3547.917,161.4434,0,0,0,100,0),
(@PATH,17,2794.609,-3538.025,161.6062,0,0,0,100,0),
(@PATH,18,2789.339,-3527.189,166.2076,0,0,0,100,0),
(@PATH,19,2778.46,-3527.366,166.1371,0,0,0,100,0),
(@PATH,20,2772.763,-3531.095,166.1371,0,0,0,100,0),
(@PATH,21,2765.156,-3536.607,166.1371,0,0,0,100,0),
(@PATH,22,2763.8,-3543.712,166.3489,0,0,0,100,0),
(@PATH,23,2772.348,-3554.362,161.5688,0,0,0,100,0),
(@PATH,24,2780.89,-3556.149,161.4322,0,0,0,100,0),
(@PATH,25,2791.389,-3562.775,161.5777,0,0,0,100,0),
(@PATH,26,2803.1,-3574.7,161.4174,0,0,0,100,0),
(@PATH,27,2803.814,-3581.895,161.3991,0,0,0,100,0),
(@PATH,28,2804,-3593.935,161.4066,0,0,0,100,0),
(@PATH,29,2801.798,-3600.579,161.4039,0,0,0,100,0),
(@PATH,30,2802.101,-3606.185,161.4054,0,0,0,100,0),
(@PATH,31,2804.482,-3612.46,161.4072,0,0,0,100,0),
(@PATH,32,2807.753,-3617.282,161.405,0,0,0,100,0),
(@PATH,33,2813.579,-3620.822,161.4043,0,0,0,100,0);

-- Pathing for Gjalerbron Warrior Entry: 23991
SET @NPC := 113286;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2656.009,`position_y`=-3595.201,`position_z`=205.3548 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2619.413,-3562.591,205.3707,0,0,0,100,0),
(@PATH,2,2578.914,-3535.467,206.4749,0,0,0,100,0),
(@PATH,3,2569.813,-3526.975,206.25688,0,0,0,100,0),
(@PATH,4,2547.857,-3503.03,187.9234,0,0,0,100,0),
(@PATH,5,2550.461,-3454.087,184.147,0,0,0,100,0),
(@PATH,6,2603.13,-3431.154,184.0111,0,0,0,100,0),
(@PATH,7,2618.346,-3441.865,186.16079,0,0,0,100,0),
(@PATH,8,2636.813,-3462.923,202.8718,0,0,0,100,0),
(@PATH,9,2639.909,-3468.866,206.72212,0,0,0,100,0),
(@PATH,10,2659.177,-3506.079,205.3751,0,0,0,100,0),
(@PATH,11,2684.902,-3549.402,205.3751,0,0,0,100,0),
(@PATH,12,2687.326,-3578.99,205.3152,0,0,0,100,0),
(@PATH,13,2656.009,-3595.201,205.3548,0,0,0,100,0);

-- Allerian Stronghold Fixup

-- Update position for Erick Nateson
UPDATE `creature` SET `position_x`=-2947.306,`position_y`=3982.602,`position_z`=0.04192996,`orientation`=3.493307 WHERE `id`=21399;

-- Pathing for High Elf Ranger Entry: 19000
SET @NPC := 68300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2892.84,`position_y`=3947.823,`position_z`=13.40542 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,258,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2900.541,3949.979,13.40506,8000,0,0,100,0),
(@PATH,2,-2892.84,3947.823,13.40542,16000,0,0,100,0);

-- Pathing for High Elf Ranger Entry: 19000
SET @NPC := 68302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2984.74,`position_y`=4065.979,`position_z`=16.47879 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,258,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2989.837,4072.737,16.47879,16000,0,0,100,0),
(@PATH,2,-2984.74,4065.979,16.47879,8000,0,0,100,0);

-- Pathing for High Elf Ranger Entry: 19000
SET @NPC := 68304;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3057.808,`position_y`=4017.832,`position_z`=16.17462 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,258,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3052.007,4011.99,16.17451,8000,0,0,100,0),
(@PATH,2,-3057.808,4017.832,16.17462,16000,0,0,100,0);

-- Pathing for Allerian Horseman Entry: 19003
SET @NPC := 68308;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2872.895,`position_y`=3981.621,`position_z`=5.133294 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,2404, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2862.589,3983.513,4.859164,23000,0,0,100,0),
(@PATH,2,-2877.861,3980.92,4.691218,22000,0,@PATH+1,100,0),
(@PATH,3,-2872.895,3981.621,5.133294,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,1,30,0,0,0.1919862,822);

-- Pathing for Allerian Horseman Entry: 19003
SET @NPC := 68309;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2965.397,`position_y`=4084.842,`position_z`=3.064998 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,2404, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2971.184,4089.91,4.059246,0,0,0,100,0),
(@PATH,2,-2974.546,4096.034,4.809246,0,0,0,100,0),
(@PATH,3,-2975.984,4102.904,5.563596,0,0,0,100,0),
(@PATH,4,-2976.84,4109.215,6.188596,0,0,0,100,0),
(@PATH,5,-2977.442,4116.1,6.438596,29000,0,0,100,0),
(@PATH,6,-2976.687,4106.692,6.063596,0,0,0,100,0),
(@PATH,7,-2975.544,4099.55,5.309246,0,0,0,100,0),
(@PATH,8,-2973.493,4091.829,4.309246,0,0,0,100,0),
(@PATH,9,-2969.062,4087.132,3.684246,0,0,0,100,0),
(@PATH,10,-2965.397,4084.842,3.064998,29000,0,@PATH+1,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,1,30,0,0,2.321288,823);

-- Pathing for Lemla Hopewing Entry: 19181
SET @NPC := 68626;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2981.203,`position_y`=3879.134,`position_z`=9.613096 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2992.487,3878.415,9.613096,9000,0,@PATH+1,100,0),
(@PATH,2,-2996.076,3870.127,9.613096,20000,0,0,100,0),
(@PATH,3,-2997.53,3865.11,9.484549,8000,0,0,100,0),
(@PATH,4,-2993.53,3863.55,9.484549,7000,0,0,100,0),
(@PATH,5,-2981.203,3879.134,9.613096,7000,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,1.27409,824);

-- Pathing for Allerian Defender Entry: 18999
SET @NPC := 68292;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2947.596,`position_y`=3983.544,`position_z`=-0.08307004 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2944.827,3979.540,0.041929,0,0,0,100,0),
(@PATH,2,-2942.500,3979.078,-0.20807,25000,0,@PATH+1,100,0),
(@PATH,3,-2939.759,3978.620,-0.425645,0,0,0,100,0),
(@PATH,4,-2936.500,3981.641,-0.33307,0,0,0,100,0),
(@PATH,5,-2935.938,3983.333,-0.33307,29000,0,@PATH+2,100,0),
(@PATH,6,-2935.374,3986.827,-0.594707,0,0,0,100,0),
(@PATH,7,-2937.500,3990.625,-0.58307,0,0,0,100,0),
(@PATH,8,-2940.678,3990.862,-0.70807,23000,0,@PATH+3,100,0),
(@PATH,9,-2943.362,3990.967,-0.597971,0,0,0,100,0),
(@PATH,10,-2947.396,3988.542,-0.20807,0,0,0,100,0),
(@PATH,11,-2947.596,3983.544,-0.08307004,27000,0,@PATH+4,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2,@PATH+3,@PATH+4);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,1,30,0,0,4.729842,825),
(@PATH+2,1,30,0,0,6.091199,826),
(@PATH+3,1,30,0,0,1.815142,827),
(@PATH+4,1,30,0,0,3.560472,828);

-- Pathing for Allerian Defender Entry: 18999
SET @NPC := 68296;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-3004.182,`position_y`=4059.2,`position_z`=16.47264 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-3016.535,4050.462,16.47229,0,0,0,100,0),
(@PATH,2,-3022.042,4045.356,17.46166,0,0,0,100,0),
(@PATH,3,-3030.056,4039.186,17.46166,0,0,0,100,0),
(@PATH,4,-3032.783,4036.933,16.18017,0,0,0,100,0),
(@PATH,5,-3044.368,4027.187,16.17542,12000,0,@PATH+1,100,0),
(@PATH,6,-3039.387,4030.45,16.1769,0,0,0,100,0),
(@PATH,7,-3032.683,4037.32,16.1804,0,0,0,100,0),
(@PATH,8,-3025.89,4042.386,17.46166,0,0,0,100,0),
(@PATH,9,-3019.17,4047.763,17.46166,0,0,0,100,0),
(@PATH,10,-3016.295,4049.834,16.47264,0,0,0,100,0),
(@PATH,11,-3004.042,4059.303,16.47269,12000,0,@PATH+2,100,0),
(@PATH,12,-2992.944,4066.828,16.47743,0,0,0,100,0),
(@PATH,13,-2989.875,4062.297,16.47566,0,0,0,100,0),
(@PATH,14,-2999.597,4055.534,10.61597,0,0,0,100,0),
(@PATH,15,-3008.305,4049.41,5.663261,10000,0,@PATH+3,100,0),
(@PATH,16,-3003.988,4052.784,7.524997,0,0,0,100,0),
(@PATH,17,-2989.94,4062.394,16.47567,0,0,0,100,0),
(@PATH,18,-2992.964,4066.766,16.47739,0,0,0,100,0),
(@PATH,19,-3004.182,4059.2,16.47264,12000,0,@PATH+4,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2,@PATH+3,@PATH+4);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,1,30,0,0,2.373648,829),
(@PATH+2,1,30,0,0,2.164208,830),
(@PATH+3,1,30,0,0,0.3490658,831),
(@PATH+4,1,30,0,0,2.164208,832);

-- Pathing for Allerian Defender Entry: 18999
SET @NPC := 68290;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2908.265,`position_y`=3922.398,`position_z`=13.40726 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2905.809,3933.479,7.323796,0,0,0,100,0),
(@PATH,2,-2903.188,3943.559,2.596507,11000,0,@PATH+1,100,0),
(@PATH,3,-2907.823,3925.806,12.06445,0,0,0,100,0),
(@PATH,4,-2908.265,3922.398,13.40726,0,0,0,100,0),
(@PATH,5,-2903.021,3920.76,13.40938,19000,0,@PATH+2,100,0),
(@PATH,6,-2900.368,3931.102,13.40561,0,0,0,100,0),
(@PATH,7,-2896.775,3945.807,13.40281,29000,0,@PATH+3,100,0),
(@PATH,8,-2898.747,3936.718,13.40411,0,0,0,100,0),
(@PATH,9,-2903.021,3920.76,13.40938,28000,0,@PATH+4,100,0),
(@PATH,10,-2908.265,3922.398,13.40726,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (@PATH+1,@PATH+2,@PATH+3,@PATH+4);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,1,30,0,0,2.80998,833),
(@PATH+2,1,30,0,0,6.021386,834),
(@PATH+3,1,30,0,0,6.161012,835),
(@PATH+4,1,30,0,0,6.003932,836);

-- Allerian Defender SAI
SET @ENTRY   := 18999; -- NPC entry
SET @SPELL1  := 18396; -- Dismounting Blast
SET @GUID1   := 68293; -- One Defender is scripted
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY; -- Set SAI as AI. Remove cpp ScriptName if one exist
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; -- Remove EAI if exist
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@ENTRY,-@GUID1);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Allerian Defender - On Aggro - Cast Dismounting Blast on victim'),
(-@GUID1,0,0,0,4,0,100,1,0,0,0,0,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Allerian Defender - On Aggro - Cast Dismounting Blast on victim'),
(-@GUID1,0,1,0,1,0,100,0,40000,80000,180000,180000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Allerian Defender - OOC - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.642576, 'Allerian Defender - Script - turn to'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Allerian Defender - Script - Say text 0'),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.466077, 'Allerian Defender - Script - turn to'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,10,68291,@ENTRY,0,0,0,0,0, 'Allerian Defender - Script - Say text 0');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=18999;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(18999,0,0, 'Hey, did you read the bounty on this wanted poster?',12,7,100,6,0,0, 'Allerian Defender'),
(18999,0,1, 'The Bone Wastes! I don''t care what''s being offered as a reward, I''m not going into the Bone Wastes!',12,7,100,6,0,0, 'Allerian Defender'),
(18999,0,2, 'This wanted poster says that they''re offering gold to these so-called adventurers to go kill things. Isn''t that what we do? I don''t think I''m being paid enough!',12,7,100,6,0,0, 'Allerian Defender'),
(18999,0,3, 'You want to go do the bounty off of this wanted poster after the shift is over?',12,7,100,6,0,0, 'Allerian Defender'),
(18999,0,4, 'This poster has a bounty on bonelashers. You think I should do that?',12,7,100,6,0,0, 'Allerian Defender'),
(18999,1,0, 'Is that wanted poster all that you''re going to talk about today?',12,7,100,1,0,0, 'Allerian Defender'),
(18999,1,1, 'I''m up to looking into that bounty after this shift.',12,7,100,1,0,0, 'Allerian Defender'),
(18999,1,2, 'I could use the extra money.',12,7,100,1,0,0, 'Allerian Defender'),
(18999,1,3, 'I don''t know and I don''t care.',12,7,100,1,0,0, 'Allerian Defender'),
(18999,1,4, 'The bonelashers of the wastes are no laughing matter. I hear they carry diseases!',12,7,100,1,0,0, 'Allerian Defender');
-- Remove old crappy script
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (68291,68293);
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (68291,68293);
DELETE FROM `waypoint_data` WHERE `id` IN (682910,682930);
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 170 AND 171;
DELETE FROM `db_script_string` WHERE `entry` IN (2000005046,2000005047);

-- Pathing for Allerian Peasant Entry: 19147
SET @NPC := 68470;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2983.204,`position_y`=3971.366,`position_z`=2.162047 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2981.773,3966.45,2.614914,0,0,0,100,0),
(@PATH,2,-2981.005,3960.968,2.989914,0,0,0,100,0),
(@PATH,3,-2981.881,3954.581,2.614914,0,0,0,100,0),
(@PATH,4,-2982.862,3947.319,3.114914,0,0,0,100,0),
(@PATH,5,-2986.684,3945.63,3.239914,0,0,0,100,0),
(@PATH,6,-2986.646,3950.593,3.761735,6000,0,@PATH+1,100,0),
(@PATH,7,-2986.979,3946.354,3.114914,0,0,0,100,0),
(@PATH,8,-2982.707,3945.763,3.364914,0,0,0,100,0),
(@PATH,9,-2980.747,3953.042,2.739914,0,0,0,100,0),
(@PATH,10,-2980.202,3961.786,2.864914,0,0,0,100,0),
(@PATH,11,-2983.204,3971.366,2.162047,4000,0,@PATH+2,100,0);
-- F1304ACB07BEF300 .go -2981.773 3966.45 2.614914
DELETE FROM `waypoint_scripts` WHERE `id` IN (188,189,@PATH+1,@PATH+2);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,1.413717,837),
(@PATH+1,1,2,83,381,0,838),
(@PATH+2,1,2,83,381,0,839);

-- Pathing for Allerian Peasant Entry: 19147
SET @NPC := 68468;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2977.357,`position_y`=4012.234,`position_z`=1.424733 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2978.323,4006.793,1.174733,0,0,0,100,0),
(@PATH,2,-2973.405,4002.646,1.424733,0,0,0,100,0),
(@PATH,3,-2967.158,4003.521,1.299733,0,0,0,100,0),
(@PATH,4,-2964.591,4008.163,1.124218,0,0,0,100,0),
(@PATH,5,-2966.771,4010.062,1.299733,0,0,0,100,0),
(@PATH,6,-2969.096,4008.951,1.830398,5000,0,@PATH+1,100,0),
(@PATH,7,-2966.771,4010.062,1.299733,0,0,0,100,0),
(@PATH,8,-2964.591,4008.163,1.124218,0,0,0,100,0),
(@PATH,9,-2965.665,4005.173,1.249218,0,0,0,100,0),
(@PATH,10,-2972.548,4002.835,1.424733,0,0,0,100,0),
(@PATH,11,-2977.689,4007.088,1.174733,0,0,0,100,0),
(@PATH,12,-2977.357,4012.234,1.424733,4000,0,@PATH+2,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (184,185,@PATH+1,@PATH+2);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,3.839724,840),
(@PATH+1,1,2,83,381,0,841),
(@PATH+2,1,2,83,381,0,842);

-- Pathing for Allerian Peasant Entry: 19147
SET @NPC := 68469;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-2994.862,`position_y`=4029.217,`position_z`=1.799733 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2995.501,4024.677,1.674733,0,0,0,100,0),
(@PATH,2,-2991.115,4017.175,1.424733,0,0,0,100,0),
(@PATH,3,-2986.05,4011.426,0.7997329,0,0,0,100,0),
(@PATH,4,-2980.667,4005.888,1.049733,0,0,0,100,0),
(@PATH,5,-2974.792,4001.254,1.424733,0,0,0,100,0),
(@PATH,6,-2969.111,3999.192,1.787047,0,0,0,100,0),
(@PATH,7,-2962.025,4001.197,1.249218,0,0,0,100,0),
(@PATH,8,-2955.767,4003.337,0.8742183,0,0,0,100,0),
(@PATH,9,-2949.479,4006.26,-0.5007817,0,0,0,100,0),
(@PATH,10,-2943.639,4005.681,-0.8757817,0,0,0,100,0),
(@PATH,11,-2938.82,4004.248,-0.8757817,5000,0,@PATH+2,100,0),
(@PATH,12,-2944.247,4006.454,-0.8757817,0,0,0,100,0),
(@PATH,13,-2950.113,4005.459,-0.2507817,0,0,0,100,0),
(@PATH,14,-2958.819,4002.142,1.124218,0,0,0,100,0),
(@PATH,15,-2968.181,3999.478,1.662047,0,0,0,100,0),
(@PATH,16,-2976.377,4001.348,1.424733,0,0,0,100,0),
(@PATH,17,-2982.522,4005.211,1.049733,0,0,0,100,0),
(@PATH,18,-2987.678,4011.322,0.6747329,0,0,0,100,0),
(@PATH,19,-2991.716,4016.418,1.174733,0,0,0,100,0),
(@PATH,20,-2994.956,4023.157,1.549733,0,0,0,100,0),
(@PATH,21,-2994.996,4027.696,1.799733,0,0,0,100,0),
(@PATH,22,-2994.862,4029.217,1.799733,5000,0,@PATH+1,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (186,187,@PATH+1,@PATH+2);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(@PATH+1,0,30,0,0,1.570796,843),
(@PATH+1,1,2,83,381,0,844),
(@PATH+2,1,2,83,69,0,845);
