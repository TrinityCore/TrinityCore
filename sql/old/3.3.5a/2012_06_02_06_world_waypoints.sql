-- Azure Drake
-- Delete old spawns
DELETE FROM `creature` WHERE `id` IN (27682,27608);
UPDATE `creature_template` SET `speed_walk`=9/2,`speed_run`=17/7,`InhabitType`=4 WHERE `entry`=26838;

SET @NPC := 99078;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3433.348,274.121,192.7347,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3441.997,218.066,169.347,0,0,0,100,0),
(@PATH,2,3495.446,178.1635,169.347,0,0,0,100,0),
(@PATH,3,3562.124,172.6228,169.347,0,0,0,100,0),
(@PATH,4,3645.859,193.9786,169.347,0,0,0,100,0),
(@PATH,5,3689.068,295.8872,169.347,0,0,0,100,0),
(@PATH,6,3624.446,375.1689,169.347,0,0,0,100,0),
(@PATH,7,3510.095,372.0045,169.347,0,0,0,100,0),
(@PATH,8,3446.488,300.4381,169.347,0,0,0,100,0),
(@PATH,9,3420.008,195.1058,169.347,0,0,0,100,0),
(@PATH,10,3474.376,103.4208,169.347,0,0,0,100,0),
(@PATH,11,3587.787,78.41341,169.347,0,0,0,100,0),
(@PATH,12,3680.552,168.1343,169.347,0,0,0,100,0),
(@PATH,13,3682.222,340.8562,169.347,0,0,0,100,0),
(@PATH,14,3563.545,458.4753,169.347,0,0,0,100,0),
(@PATH,15,3452.104,480.9653,169.347,0,0,0,100,0),
(@PATH,16,3344.437,382.5979,169.347,0,0,0,100,0),
(@PATH,17,3232.114,340.6778,169.347,0,0,0,100,0),
(@PATH,18,3127.326,347.8484,169.347,0,0,0,100,0),
(@PATH,19,3027.017,384.9972,169.347,0,0,0,100,0),
(@PATH,20,2989.474,458.5701,169.347,0,0,0,100,0),
(@PATH,21,3013.37,539.2202,169.347,0,0,0,100,0),
(@PATH,22,3066.603,566.7353,169.347,0,0,0,100,0),
(@PATH,23,3134.078,551.7691,169.347,0,0,0,100,0),
(@PATH,24,3244.26,486.8306,169.347,0,0,0,100,0),
(@PATH,25,3327.64,383.2903,169.347,0,0,0,100,0),
(@PATH,26,3382.149,279.6307,169.347,0,0,0,100,0);

SET @NPC := 99079;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3434.632,268.5218,212.5722,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3449.962,350.2704,185.3083,0,0,0,100,0),
(@PATH,2,3546.571,399.454,185.3083,0,0,0,100,0),
(@PATH,3,3649.095,344.2626,185.3083,0,0,0,100,0),
(@PATH,4,3648.6,203.3825,185.3083,0,0,0,100,0),
(@PATH,5,3557.447,156.6613,185.3083,0,0,0,100,0),
(@PATH,6,3438.763,197.2433,185.3083,0,0,0,100,0),
(@PATH,7,3364.301,251.3537,185.3083,0,0,0,100,0),
(@PATH,8,3245.05,295.2606,185.3083,0,0,0,100,0),
(@PATH,9,3127.677,330.6631,185.3083,0,0,0,100,0),
(@PATH,10,3045.42,426.6257,185.3083,0,0,0,100,0),
(@PATH,11,3033.423,500.1823,185.3083,0,0,0,100,0),
(@PATH,12,3074.555,584.5701,185.3083,0,0,0,100,0),
(@PATH,13,3167.413,579.3245,185.3083,0,0,0,100,0),
(@PATH,14,3254.766,477.3121,185.3083,0,0,0,100,0),
(@PATH,15,3328.997,355.7176,185.3083,0,0,0,100,0),
(@PATH,16,3403.051,340.1719,185.3083,0,0,0,100,0),
(@PATH,17,3446.086,384.896,185.3083,0,0,0,100,0),
(@PATH,18,3503.323,407.0888,185.3083,0,0,0,100,0),
(@PATH,19,3593.65,392.4026,185.3083,0,0,0,100,0),
(@PATH,20,3658.26,283.8229,185.3083,0,0,0,100,0),
(@PATH,21,3604.809,176.3996,185.3083,0,0,0,100,0),
(@PATH,22,3500.686,159.6379,185.3083,0,0,0,100,0),
(@PATH,23,3441.441,249.5543,185.3083,0,0,0,100,0);

SET @NPC := 99083;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3639.789,321.911,195.744,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3654.995,228.2284,204.7075,0,0,0,100,0),
(@PATH,2,3750.065,190.3719,204.7075,0,0,0,100,0),
(@PATH,3,3793.781,239.5784,204.7075,0,0,0,100,0),
(@PATH,4,3793.007,322.9862,204.7075,0,0,0,100,0),
(@PATH,5,3712.435,337.7213,204.7075,0,0,0,100,0),
(@PATH,6,3649.212,273.7653,204.7075,0,0,0,100,0),
(@PATH,7,3627.809,181.2728,204.7075,0,0,0,100,0),
(@PATH,8,3575.202,116.1518,204.7075,0,0,0,100,0),
(@PATH,9,3452.9,157.833,204.7075,0,0,0,100,0),
(@PATH,10,3395.156,279.1096,204.7075,0,0,0,100,0),
(@PATH,11,3459.034,403.4866,204.7075,0,0,0,100,0),
(@PATH,12,3610.543,437.9186,204.7075,0,0,0,100,0),
(@PATH,13,3715.638,355.6098,204.7075,0,0,0,100,0),
(@PATH,14,3721.246,203.5534,204.7075,0,0,0,100,0),
(@PATH,15,3583.16,147.8227,204.7075,0,0,0,100,0),
(@PATH,16,3467.958,184.451,204.7075,0,0,0,100,0),
(@PATH,17,3341.041,241.3563,204.7075,0,0,0,100,0),
(@PATH,18,3259.652,326.3573,204.7075,0,0,0,100,0),
(@PATH,19,3325.962,453.1619,204.7075,0,0,0,100,0),
(@PATH,20,3430.271,470.1731,204.7075,0,0,0,100,0),
(@PATH,21,3474.818,389.2108,204.7075,0,0,0,100,0),
(@PATH,22,3422.128,277.9353,204.7075,0,0,0,100,0),
(@PATH,23,3278.513,235.3488,204.7075,0,0,0,100,0),
(@PATH,24,3139.333,309.1593,204.7075,0,0,0,100,0),
(@PATH,25,3124.315,442.8726,204.7075,0,0,0,100,0),
(@PATH,26,3166.636,500.1602,204.7075,0,0,0,100,0),
(@PATH,27,3252.777,537.1607,204.7075,0,0,0,100,0),
(@PATH,28,3365.404,500.6408,204.7075,0,0,0,100,0),
(@PATH,29,3497.347,437.8124,204.7075,0,0,0,100,0),
(@PATH,30,3610.069,345.1742,204.7075,0,0,0,100,0);

SET @NPC := 99084;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3419.562,219.4669,185.8007,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3476.15,177.9767,151.9461,0,0,0,100,0),
(@PATH,2,3545.193,113.4851,151.9461,0,0,0,100,0),
(@PATH,3,3639.261,157.7231,151.9461,0,0,0,100,0),
(@PATH,4,3676.142,330.9362,151.9461,0,0,0,100,0),
(@PATH,5,3568.025,452.4464,151.9461,0,0,0,100,0),
(@PATH,6,3440.924,381.5191,151.9461,0,0,0,100,0),
(@PATH,7,3406.76,247.0661,151.9461,0,0,0,100,0),
(@PATH,8,3489.703,142.3122,151.9461,0,0,0,100,0),
(@PATH,9,3573.337,130.2329,151.9461,0,0,0,100,0),
(@PATH,10,3668.767,202.5275,151.9461,0,0,0,100,0),
(@PATH,11,3660.667,365.0258,151.9461,0,0,0,100,0),
(@PATH,12,3546.228,441.4885,151.9461,0,0,0,100,0),
(@PATH,13,3414.354,479.1683,151.9461,0,0,0,100,0),
(@PATH,14,3298.711,513.6075,151.9461,0,0,0,100,0),
(@PATH,15,3152.929,563.3295,151.9461,0,0,0,100,0),
(@PATH,16,3061.01,598.1893,151.9461,0,0,0,100,0),
(@PATH,17,3028.564,548.2512,151.9461,0,0,0,100,0),
(@PATH,18,3066.851,499.9897,151.9461,0,0,0,100,0),
(@PATH,19,3126.102,457.3964,151.9461,0,0,0,100,0),
(@PATH,20,3209.258,379.5157,151.9461,0,0,0,100,0),
(@PATH,21,3290.067,313.6936,151.9461,0,0,0,100,0),
(@PATH,22,3381.995,245.4414,151.9461,0,0,0,100,0);

SET @NPC := 99085;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3431.814,203.5959,199.4538,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3469.755,211.1012,252.1057,0,0,0,100,0),
(@PATH,2,3543.436,184.6182,282.9112,0,0,0,100,0),
(@PATH,3,3605.144,211.1016,313.2445,0,0,0,100,0),
(@PATH,4,3629.088,281.4026,342.355,0,0,0,100,0),
(@PATH,5,3586.889,335.8259,342.355,0,0,0,100,0),
(@PATH,6,3534.959,340.7828,342.355,0,0,0,100,0),
(@PATH,7,3488.181,299.2897,342.355,0,0,0,100,0),
(@PATH,8,3490.962,242.9244,342.355,0,0,0,100,0),
(@PATH,9,3544.176,216.1916,342.355,0,0,0,100,0),
(@PATH,10,3607.393,238.2059,342.355,0,0,0,100,0),
(@PATH,11,3606.415,315.159,342.355,0,0,0,100,0),
(@PATH,12,3529.92,347.5442,342.355,0,0,0,100,0),
(@PATH,13,3442.581,379.9305,309.9662,0,0,0,100,0),
(@PATH,14,3363.314,409.6005,272.7996,0,0,0,100,0),
(@PATH,15,3271.624,451.7768,231.7996,0,0,0,100,0),
(@PATH,16,3222.875,508.5536,210.5774,0,0,0,100,0),
(@PATH,17,3178.339,552.9731,195.4663,0,0,0,100,0),
(@PATH,18,3119.579,592.5015,182.2996,0,0,0,100,0),
(@PATH,19,3079.527,558.9856,175.383,0,0,0,100,0),
(@PATH,20,3110.969,495.2063,173.9941,0,0,0,100,0),
(@PATH,21,3133.366,466.6834,176.5779,0,0,0,100,0),
(@PATH,22,3236.847,383.9943,176.5779,0,0,0,100,0),
(@PATH,23,3382.743,269.2179,222.0501,0,0,0,100,0);

SET @NPC := 99086;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3408.915,276.3928,180.561,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3451.428,175.6206,154.7629,0,0,0,100,0),
(@PATH,2,3461.289,67.8521,154.7629,0,0,0,100,0),
(@PATH,3,3401.216,31.08062,154.7629,0,0,0,100,0),
(@PATH,4,3348.744,62.37424,154.7629,0,0,0,100,0),
(@PATH,5,3352.888,148.2122,154.7629,0,0,0,100,0),
(@PATH,6,3405.2,335.0623,154.7629,0,0,0,100,0),
(@PATH,7,3399.393,397.5138,154.7629,0,0,0,100,0),
(@PATH,8,3346.986,426.0631,154.7629,0,0,0,100,0),
(@PATH,9,3262.085,383.6502,154.7629,0,0,0,100,0),
(@PATH,10,3156.926,352.7438,154.7629,0,0,0,100,0),
(@PATH,11,3057.544,393.0464,154.7629,0,0,0,100,0),
(@PATH,12,3000.647,466.7132,154.7629,0,0,0,100,0),
(@PATH,13,2989.147,516.5572,154.7629,0,0,0,100,0),
(@PATH,14,3049.945,587.7933,154.7629,0,0,0,100,0),
(@PATH,15,3160.802,556.4007,154.7629,0,0,0,100,0),
(@PATH,16,3268.329,422.1047,154.7629,0,0,0,100,0);

SET @NPC := 99087;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3748.954,236.7544,178.6408,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3712.221,418.183,178.6408,0,0,0,100,0),
(@PATH,2,3540.502,499.2345,178.6408,0,0,0,100,0),
(@PATH,3,3358.373,445.1452,178.6408,0,0,0,100,0),
(@PATH,4,3200.13,472.7363,178.6408,0,0,0,100,0),
(@PATH,5,3101.38,584.3835,178.6408,0,0,0,100,0),
(@PATH,6,3040.255,596.7429,178.6408,0,0,0,100,0),
(@PATH,7,2997.37,550.3453,178.6408,0,0,0,100,0),
(@PATH,8,2999.847,500.0373,178.6408,0,0,0,100,0),
(@PATH,9,3048.254,460.723,178.6408,0,0,0,100,0),
(@PATH,10,3140.818,390.9225,178.6408,0,0,0,100,0),
(@PATH,11,3219.294,333.4928,178.6408,0,0,0,100,0),
(@PATH,12,3318.04,264.8529,178.6408,0,0,0,100,0),
(@PATH,13,3436.765,193.0778,178.6408,0,0,0,100,0),
(@PATH,14,3552.843,154.3912,178.6408,0,0,0,100,0),
(@PATH,15,3668.381,197.8079,178.6408,0,0,0,100,0),
(@PATH,16,3711.96,284.6768,178.6408,0,0,0,100,0),
(@PATH,17,3627.375,410.4442,178.6408,0,0,0,100,0),
(@PATH,18,3466.029,404.0347,178.6408,0,0,0,100,0),
(@PATH,19,3375.764,293.2045,178.6408,0,0,0,100,0),
(@PATH,20,3426.16,142.911,178.6408,0,0,0,100,0),
(@PATH,21,3611.036,90.26421,178.6408,0,0,0,100,0),
(@PATH,22,3748.954,236.7544,178.6408,0,0,0,100,0);


SET @NPC := 99088;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3412.463,216.0972,212.123,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3412.65,215.8015,241.2928,0,0,0,100,0),
(@PATH,2,3544.712,83.40093,241.2928,0,0,0,100,0),
(@PATH,3,3729.527,148.4322,241.2928,0,0,0,100,0),
(@PATH,4,3770.91,456.7697,241.2928,0,0,0,100,0),
(@PATH,5,3592.973,601.0773,241.2928,0,0,0,100,0),
(@PATH,6,3431.349,566.7643,241.2928,0,0,0,100,0),
(@PATH,7,3298.04,548.691,241.2928,0,0,0,100,0),
(@PATH,8,3180.431,663.6898,241.2928,0,0,0,100,0),
(@PATH,9,3069.867,677.9128,241.2928,0,0,0,100,0),
(@PATH,10,2984.272,605.6987,241.2928,0,0,0,100,0),
(@PATH,11,3000.096,533.4483,241.2928,0,0,0,100,0),
(@PATH,12,3144.4,405.446,241.2928,0,0,0,100,0),
(@PATH,13,3301.554,308.331,241.2928,0,0,0,100,0);

SET @NPC := 99089;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3100.95,567.1441,118.4118,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3100.912,567.1385,122.3331,0,0,0,100,0),
(@PATH,2,3214.064,524.5076,122.3331,0,0,0,100,0),
(@PATH,3,3307.77,498.1685,122.3331,0,0,0,100,0),
(@PATH,4,3399.335,473.5195,122.3331,0,0,0,100,0),
(@PATH,5,3545.675,446.1954,122.3331,0,0,0,100,0),
(@PATH,6,3631.807,357.087,122.3331,0,0,0,100,0),
(@PATH,7,3640.708,229.0423,122.3331,0,0,0,100,0),
(@PATH,8,3616.36,137.7545,122.3331,0,0,0,100,0),
(@PATH,9,3558.458,113.3069,122.3331,0,0,0,100,0),
(@PATH,10,3457.288,142.8311,122.3331,0,0,0,100,0),
(@PATH,11,3387.124,248.1035,122.3331,0,0,0,100,0),
(@PATH,12,3419.464,398.1638,122.3331,0,0,0,100,0),
(@PATH,13,3366.308,507.4259,122.3331,0,0,0,100,0),
(@PATH,14,3243.456,494.2254,122.3331,0,0,0,100,0),
(@PATH,15,3121.018,428.1757,122.3331,0,0,0,100,0),
(@PATH,16,3003.428,487.8239,122.3331,0,0,0,100,0),
(@PATH,17,3001.53,566.4896,122.3331,0,0,0,100,0),
(@PATH,18,3059.883,577.261,122.3331,0,0,0,100,0);

-- static
DELETE FROM `creature` WHERE `guid` IN (99090,99091);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(99090,27682,571,1,1,24743,0,2954.845,625.8646,146.2928,2.094395,120,0,0,38440,0,0),
(99091,27682,571,1,1,24743,0,3256.357,585.8403,136.8419,0.4363323,120,0,0,38440,0,0);

-- waypoints
SET @NPC := 99092;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3017.465,301.0079,204.943,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3014.38,371.552,204.943,0,0,0,100,0),
(@PATH,2,3066.132,433.5229,204.943,0,0,0,100,0),
(@PATH,3,3168.017,532.116,204.943,0,0,0,100,0),
(@PATH,4,3341.228,644.3932,204.943,0,0,0,100,0),
(@PATH,5,3480.533,600.2273,204.943,0,0,0,100,0),
(@PATH,6,3485.514,465.1431,204.943,0,0,0,100,0),
(@PATH,7,3362.191,369.4394,204.943,0,0,0,100,0),
(@PATH,8,3193.452,330.4968,204.943,0,0,0,100,0),
(@PATH,9,3117.152,256.1553,204.943,0,0,0,100,0),
(@PATH,10,3017.465,301.0079,204.943,0,0,0,100,0);

SET @NPC := 99094;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3138.133,520.6823,53.44044,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3120.694,487.4651,73.32948,0,0,0,100,0),
(@PATH,2,3094.569,488.8283,89.30162,0,0,0,100,0),
(@PATH,3,3076.394,504.3694,101.9128,0,0,0,100,0),
(@PATH,4,3073.121,536.1434,118.3021,0,0,0,100,0),
(@PATH,5,3100.686,550.8791,135.0522,0,0,0,100,0),
(@PATH,6,3133.567,533.2503,156.4133,0,0,0,100,0),
(@PATH,7,3128.940,498.2000,185.3022,0,0,0,100,0),
(@PATH,8,3104.875,485.1591,211.9410,0,0,0,100,0),
(@PATH,9,3078.965,493.2044,233.2187,0,0,0,100,0),
(@PATH,10,3077.378,529.8601,246.1916,0,0,0,100,0),
(@PATH,11,3104.640,532.739,246.1916,0,0,0,100,0),
(@PATH,12,3124.398,511.3354,246.1916,0,0,0,100,0),
(@PATH,13,3106.461,485.7477,246.1916,0,0,0,100,0),
(@PATH,14,3074.75,501.1113,246.1916,0,0,0,100,0),
(@PATH,15,3080.605,533.5042,222.6366,0,0,0,100,0),
(@PATH,16,3108.456,548.174,194.8869,0,0,0,100,0),
(@PATH,17,3138.865,510.0685,159.4426,0,0,0,100,0),
(@PATH,18,3107.084,484.058,121.3038,0,0,0,100,0),
(@PATH,19,3066.059,511.5332,94.97042,0,0,0,100,0),
(@PATH,20,3084.679,555.8902,74.52598,0,0,0,100,0),
(@PATH,21,3128.865,543.4575,51.55369,0,0,0,100,0),
(@PATH,22,3132.671,497.0408,51.55369,0,0,0,100,0),
(@PATH,23,3083.713,484.3025,51.55369,0,0,0,100,0),
(@PATH,24,3062.465,530.1815,51.55369,0,0,0,100,0),
(@PATH,25,3100.407,561.9063,51.55369,0,0,0,100,0),
(@PATH,26,3138.133,520.6823,53.44044,0,0,0,100,0);

SET @NPC := 99095;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3199.019,490.8836,212.5729,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3131.874,451.6094,212.5729,0,0,0,100,0),
(@PATH,2,3066.175,466.9917,212.5729,0,0,0,100,0),
(@PATH,3,3015.529,515.9183,212.5729,0,0,0,100,0),
(@PATH,4,3032.398,624.4706,212.5729,0,0,0,100,0),
(@PATH,5,3123.448,648.5508,212.5729,0,0,0,100,0),
(@PATH,6,3201.826,572.715,212.5729,0,0,0,100,0),
(@PATH,7,3199.019,490.8836,212.5729,0,0,0,100,0);

SET @NPC := 99096;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3214.422,579.9131,196.0033,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3133.856,625.1009,196.0033,0,0,0,100,0),
(@PATH,2,3066.991,599.8026,196.0033,0,0,0,100,0),
(@PATH,3,3045.829,536.076,196.0033,0,0,0,100,0),
(@PATH,4,3064.8,436.205,196.0033,0,0,0,100,0),
(@PATH,5,3149.34,424.2586,196.0033,0,0,0,100,0),
(@PATH,6,3217.921,481.3083,196.0033,0,0,0,100,0),
(@PATH,7,3214.422,579.9131,196.0033,0,0,0,100,0);

SET @NPC := 99097;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3106.429,348.3322,212.4711,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3184.002,431.2766,212.4711,0,0,0,100,0),
(@PATH,2,3166.134,532.8875,212.4711,0,0,0,100,0),
(@PATH,3,3080.641,574.7059,212.4711,0,0,0,100,0),
(@PATH,4,2963.504,564.834,212.4711,0,0,0,100,0),
(@PATH,5,2918.588,502.0504,212.4711,0,0,0,100,0),
(@PATH,6,2949.235,405.6514,212.4711,0,0,0,100,0),
(@PATH,7,3106.429,348.3322,212.4711,0,0,0,100,0);

SET @NPC := 99098;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3129.027,582.4556,247.3863,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3188.686,528.622,247.3863,0,0,0,100,0),
(@PATH,2,3166.479,466.4643,247.3863,0,0,0,100,0),
(@PATH,3,3107.782,429.4197,247.3863,0,0,0,100,0),
(@PATH,4,3030.916,459.3344,247.3863,0,0,0,100,0),
(@PATH,5,3014.312,531.3731,247.3863,0,0,0,100,0),
(@PATH,6,3058.55,581.8262,247.3863,0,0,0,100,0),
(@PATH,7,3129.027,582.4556,247.3863,0,0,0,100,0);

SET @NPC := 99099;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3691.676,352.0933,342.2254,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3662.692,328.2304,338.4197,0,0,0,100,0),
(@PATH,2,3648.806,293.8063,321.0587,0,0,0,100,0),
(@PATH,3,3677.441,213.8859,320.1976,0,0,0,100,0),
(@PATH,4,3615.31,209.5691,324.1698,0,0,0,100,0),
(@PATH,5,3637.643,254.0089,332.7251,0,0,0,100,0),
(@PATH,6,3699.886,260.6509,327.8641,0,0,0,100,0),
(@PATH,7,3720.373,308.941,337.7808,0,0,0,100,0),
(@PATH,8,3691.676,352.0933,342.2254,0,0,0,100,0);

SET @NPC := 99093;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3036.494,602.2036,179.671,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3100.145,600.0773,179.671,0,0,0,100,0),
(@PATH,2,3230.972,531.9783,179.671,0,0,0,100,0),
(@PATH,3,3261.28,445.4492,179.671,0,0,0,100,0),
(@PATH,4,3185.334,349.6381,179.671,0,0,0,100,0),
(@PATH,5,3031.361,375.153,179.671,0,0,0,100,0),
(@PATH,6,2951.565,490.5297,179.671,0,0,0,100,0),
(@PATH,7,3006.273,602.823,179.671,0,0,0,100,0),
(@PATH,8,3140.882,604.8052,179.671,0,0,0,100,0),
(@PATH,9,3279.177,536.7864,179.671,0,0,0,100,0),
(@PATH,10,3342.035,451.1805,179.671,0,0,0,100,0),
(@PATH,11,3373.871,409.5802,179.671,0,0,0,100,0),
(@PATH,12,3418.399,323.2935,179.671,0,0,0,100,0),
(@PATH,13,3432.266,253.5685,179.671,0,0,0,100,0),
(@PATH,14,3376.006,177.8496,179.671,0,0,0,100,0),
(@PATH,15,3328.437,226.3789,179.671,0,0,0,100,0),
(@PATH,16,3336.244,307.4113,179.671,0,0,0,100,0),
(@PATH,17,3381.182,333.7066,179.671,0,0,0,100,0),
(@PATH,18,3478.52,398.1222,179.671,0,0,0,100,0),
(@PATH,19,3574.011,383.5956,179.671,0,0,0,100,0),
(@PATH,20,3661.792,400.2125,179.671,0,0,0,100,0),
(@PATH,21,3700.764,494.1714,179.671,0,0,0,100,0),
(@PATH,22,3602.784,552.9866,179.671,0,0,0,100,0),
(@PATH,23,3539.342,521.9033,179.671,0,0,0,100,0),
(@PATH,24,3523.356,456.0128,179.671,0,0,0,100,0),
(@PATH,25,3618.041,362.6289,179.671,0,0,0,100,0),
(@PATH,26,3723.684,327.7586,179.671,0,0,0,100,0),
(@PATH,27,3773.446,249.6754,179.671,0,0,0,100,0),
(@PATH,28,3749.611,152.5128,179.671,0,0,0,100,0),
(@PATH,29,3695.312,141.0493,179.671,0,0,0,100,0),
(@PATH,30,3651.431,217.0924,179.671,0,0,0,100,0),
(@PATH,31,3683.438,319.0038,179.671,0,0,0,100,0),
(@PATH,32,3748.601,338.1269,179.671,0,0,0,100,0),
(@PATH,33,3792.042,245.4839,179.671,0,0,0,100,0),
(@PATH,34,3735.548,180.4323,179.671,0,0,0,100,0),
(@PATH,35,3618.281,171.1228,179.671,0,0,0,100,0),
(@PATH,36,3474.684,137.1242,179.671,0,0,0,100,0),
(@PATH,37,3479.782,49.90799,179.671,0,0,0,100,0),
(@PATH,38,3558.278,30.76975,179.671,0,0,0,100,0),
(@PATH,39,3629.689,60.77876,179.671,0,0,0,100,0),
(@PATH,40,3630.145,127.0798,179.671,0,0,0,100,0),
(@PATH,41,3490.695,175.1472,179.671,0,0,0,100,0),
(@PATH,42,3366.718,224.9415,179.671,0,0,0,100,0),
(@PATH,43,3212.591,294.8876,179.671,0,0,0,100,0),
(@PATH,44,3076.071,364.5977,179.671,0,0,0,100,0),
(@PATH,45,2990.75,457.3708,179.671,0,0,0,100,0),
(@PATH,46,2984.907,530.0489,179.671,0,0,0,100,0),
(@PATH,47,3036.494,602.2036,179.671,0,0,0,100,0);

SET @NPC := 99103;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3065.57,646.0688,229.7383,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3133.651,599.4818,229.7383,0,0,0,100,0),
(@PATH,2,3196.173,510.7455,229.7383,0,0,0,100,0),
(@PATH,3,3310.401,346.2189,229.7383,0,0,0,100,0),
(@PATH,4,3407.27,144.2138,229.7383,0,0,0,100,0),
(@PATH,5,3526.717,72.89225,229.7383,0,0,0,100,0),
(@PATH,6,3672.079,141.219,229.7383,0,0,0,100,0),
(@PATH,7,3713.506,314.0188,229.7383,0,0,0,100,0),
(@PATH,8,3602.6,431.6985,229.7383,0,0,0,100,0),
(@PATH,9,3408.532,364.4567,229.7383,0,0,0,100,0),
(@PATH,10,3217.656,309.1964,229.7383,0,0,0,100,0),
(@PATH,11,3061.193,324.0175,229.7383,0,0,0,100,0),
(@PATH,12,2959.836,412.4154,229.7383,0,0,0,100,0),
(@PATH,13,2945.925,545.2357,229.7383,0,0,0,100,0),
(@PATH,14,3065.57,646.0688,229.7383,0,0,0,100,0);

SET @NPC := 99104;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3112.661,560.2861,197.5214,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3166.947,533.783,197.5214,0,0,0,100,0),
(@PATH,2,3204.218,503.2988,197.5214,0,0,0,100,0),
(@PATH,3,3258.251,466.3165,197.5214,0,0,0,100,0),
(@PATH,4,3367.959,364.4092,197.5214,0,0,0,100,0),
(@PATH,5,3407.955,305.4363,197.5214,0,0,0,100,0),
(@PATH,6,3451.267,201.594,197.5214,0,0,0,100,0),
(@PATH,7,3508.874,166.8426,197.5214,0,0,0,100,0),
(@PATH,8,3633.496,151.127,197.5214,0,0,0,100,0),
(@PATH,9,3678.77,73.99848,197.5214,0,0,0,100,0),
(@PATH,10,3653.132,23.86263,197.5214,0,0,0,100,0),
(@PATH,11,3582.038,62.69965,197.5214,0,0,0,100,0),
(@PATH,12,3586.156,134.1242,197.5214,0,0,0,100,0),
(@PATH,13,3645.95,187.412,197.5214,0,0,0,100,0),
(@PATH,14,3699.768,345.5867,197.5214,0,0,0,100,0),
(@PATH,15,3755.733,466.6079,197.5214,0,0,0,100,0),
(@PATH,16,3695.944,599.8013,197.5214,0,0,0,100,0),
(@PATH,17,3631.838,570.2178,197.5214,0,0,0,100,0),
(@PATH,18,3620.732,470.3869,197.5214,0,0,0,100,0),
(@PATH,19,3653.033,441.836,197.5214,0,0,0,100,0),
(@PATH,20,3726.417,408.7439,197.5214,0,0,0,100,0),
(@PATH,21,3768.67,340.4243,197.5214,0,0,0,100,0),
(@PATH,22,3734.631,281.2856,197.5214,0,0,0,100,0),
(@PATH,23,3670.002,288.5108,197.5214,0,0,0,100,0),
(@PATH,24,3637.37,399.2112,197.5214,0,0,0,100,0),
(@PATH,25,3572.382,439.8372,197.5214,0,0,0,100,0),
(@PATH,26,3485.629,383.2211,197.5214,0,0,0,100,0),
(@PATH,27,3408.692,361.6136,197.5214,0,0,0,100,0),
(@PATH,28,3363.01,438.3368,197.5214,0,0,0,100,0),
(@PATH,29,3435.608,478.5367,197.5214,0,0,0,100,0),
(@PATH,30,3498.484,443.0669,197.5214,0,0,0,100,0),
(@PATH,31,3470.396,344.2875,197.5214,0,0,0,100,0),
(@PATH,32,3372.963,191.8817,197.5214,0,0,0,100,0),
(@PATH,33,3290.335,164.9094,197.5214,0,0,0,100,0),
(@PATH,34,3226.219,218.6132,197.5214,0,0,0,100,0),
(@PATH,35,3232.448,290.6222,197.5214,0,0,0,100,0),
(@PATH,36,3304.077,350.0902,197.5214,0,0,0,100,0),
(@PATH,37,3418.385,307.068,197.5214,0,0,0,100,0),
(@PATH,38,3440.642,196.0552,197.5214,0,0,0,100,0),
(@PATH,39,3388.76,137.5194,197.5214,0,0,0,100,0),
(@PATH,40,3299.691,166.3526,197.5214,0,0,0,100,0),
(@PATH,41,3197.989,286.0815,197.5214,0,0,0,100,0),
(@PATH,42,3124.057,342.0608,197.5214,0,0,0,100,0),
(@PATH,43,3029.794,412.821,197.5214,0,0,0,100,0),
(@PATH,44,3027.204,518.2308,197.5214,0,0,0,100,0),
(@PATH,45,3112.661,560.2861,197.5214,0,0,0,100,0);

SET @NPC := 99105;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27682,571,1,1,24743,0,3040.376,545.7573,223.7107,1.91463,120,0,0,38440,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3066.4,533.701,223.7107,0,0,0,100,0),
(@PATH,2,3184.873,458.7727,223.7107,0,0,0,100,0),
(@PATH,3,3308.346,361.982,223.7107,0,0,0,100,0),
(@PATH,4,3472.517,346.546,223.7107,0,0,0,100,0),
(@PATH,5,3580.564,383.8688,223.7107,0,0,0,100,0),
(@PATH,6,3656.45,349.4831,223.7107,0,0,0,100,0),
(@PATH,7,3671.57,291.0071,223.7107,0,0,0,100,0),
(@PATH,8,3637.499,197.3902,223.7107,0,0,0,100,0),
(@PATH,9,3527.828,157.279,223.7107,0,0,0,100,0),
(@PATH,10,3449.215,208.4113,223.7107,0,0,0,100,0),
(@PATH,11,3406.054,178.4773,223.7107,0,0,0,100,0),
(@PATH,12,3456.503,129.8825,223.7107,0,0,0,100,0),
(@PATH,13,3570.421,124.2369,223.7107,0,0,0,100,0),
(@PATH,14,3636.482,214.1168,223.7107,0,0,0,100,0),
(@PATH,15,3649.198,312.7206,223.7107,0,0,0,100,0),
(@PATH,16,3584.864,367.9254,223.7107,0,0,0,100,0),
(@PATH,17,3498.865,377.1867,223.7107,0,0,0,100,0),
(@PATH,18,3446.663,323.5181,223.7107,0,0,0,100,0),
(@PATH,19,3418.987,266.998,223.7107,0,0,0,100,0),
(@PATH,20,3325.219,278.7927,223.7107,0,0,0,100,0),
(@PATH,21,3246.293,325.4047,223.7107,0,0,0,100,0),
(@PATH,22,3136.991,394.2709,223.7107,0,0,0,100,0),
(@PATH,23,3057.987,457.7468,223.7107,0,0,0,100,0),
(@PATH,24,3007.479,511.7082,223.7107,0,0,0,100,0),
(@PATH,25,3012.345,538.7167,223.7107,0,0,0,100,0),
(@PATH,26,3040.376,545.7573,223.7107,0,0,0,100,0);

-- Azure Dragon
UPDATE `creature_template` SET `speed_walk`=7/2,`speed_run`=15/7,`InhabitType`=4 WHERE `entry`=27608;

SET @NPC := 99105;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3177.857,623.9463,234.0692,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3062.52,435.5133,234.0692,0,0,0,100,0),
(@PATH,2,3125.572,288.5948,234.0692,0,0,0,100,0),
(@PATH,3,3411.13,158.2311,234.0692,0,0,0,100,0),
(@PATH,4,3681.013,161.0803,234.0692,0,0,0,100,0),
(@PATH,5,3815.275,311.0847,234.0692,0,0,0,100,0),
(@PATH,6,3773.807,472.041,234.0692,0,0,0,100,0),
(@PATH,7,3576.037,531.0521,234.0692,0,0,0,100,0),
(@PATH,8,3435.667,344.3725,234.0692,0,0,0,100,0),
(@PATH,9,3480.011,109.5501,234.0692,0,0,0,100,0),
(@PATH,10,3702.724,-30.66547,234.0692,0,0,0,100,0),
(@PATH,11,3889.816,54.52344,234.0692,0,0,0,100,0),
(@PATH,12,3914.841,319.0804,234.0692,0,0,0,100,0),
(@PATH,13,3695.273,610.4755,234.0692,0,0,0,100,0),
(@PATH,14,3389.431,691.5984,234.0692,0,0,0,100,0),
(@PATH,15,3177.857,623.9463,234.0692,0,0,0,100,0);

SET @NPC := 99106;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,2980.341,629.1049,218.5251,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3128.300,641.3470,218.5251,0,0,0,100,0),
(@PATH,2,3231.236,534.2712,218.5251,0,0,0,100,0),
(@PATH,3,3229.198,417.0781,218.5251,0,0,0,100,0),
(@PATH,4,3131.435,332.9997,218.5251,0,0,0,100,0),
(@PATH,5,2990.912,336.3741,206.4763,0,0,0,100,0),
(@PATH,6,2871.583,422.1004,206.4763,0,0,0,100,0),
(@PATH,7,2881.663,578.8079,206.4763,0,0,0,100,0),
(@PATH,8,2980.341,629.1049,218.5251,0,0,0,100,0);

SET @NPC := 99107;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3488.651,-5.619141,169.4104,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3338.837,206.9924,169.4104,0,0,0,100,0),
(@PATH,2,3077.402,282.2865,169.4104,0,0,0,100,0),
(@PATH,3,2799.517,249.9982,169.4104,0,0,0,100,0),
(@PATH,4,2641.98,389.0734,169.4104,0,0,0,100,0),
(@PATH,5,2739.034,565.4708,169.4104,0,0,0,100,0),
(@PATH,6,3044.569,485.4482,169.4104,0,0,0,100,0),
(@PATH,7,3169.199,460.6385,169.4104,0,0,0,100,0),
(@PATH,8,3336.106,465.7545,169.4104,0,0,0,100,0),
(@PATH,9,3630.246,386.4513,169.4104,0,0,0,100,0),
(@PATH,10,3803.202,250.7272,169.4104,0,0,0,100,0),
(@PATH,11,3770.406,24.9643,169.4104,0,0,0,100,0),
(@PATH,12,3488.651,-5.619141,169.4104,0,0,0,100,0);

SET @NPC := 99108;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3542.247,134.1484,169.6936,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3506.288,141.7649,169.6936,0,0,0,100,0),
(@PATH,2,3378.177,251.381,169.6936,0,0,0,100,0),
(@PATH,3,3448.559,417.0887,169.6936,0,0,0,100,0),
(@PATH,4,3659.633,429.129,169.6936,0,0,0,100,0),
(@PATH,5,3726.806,236.8274,169.6936,0,0,0,100,0),
(@PATH,6,3554.261,69.58746,169.6936,0,0,0,100,0),
(@PATH,7,3337.373,175.2911,169.6936,0,0,0,100,0),
(@PATH,8,3292.872,421.84,169.6936,0,0,0,100,0),
(@PATH,9,3355.351,609.4697,169.6936,0,0,0,100,0),
(@PATH,10,3233.689,777.6954,207.249,0,0,0,100,0),
(@PATH,11,3049.014,721.6703,224.4991,0,0,0,100,0),
(@PATH,12,3044.268,566.5984,169.6936,0,0,0,100,0),
(@PATH,13,3142.397,481.2142,169.6936,0,0,0,100,0),
(@PATH,14,3328.336,435.8111,169.6936,0,0,0,100,0),
(@PATH,15,3583.232,539.7742,169.6936,0,0,0,100,0),
(@PATH,16,3799.81,460.638,169.6936,0,0,0,100,0),
(@PATH,17,3717.946,244.38,169.6936,0,0,0,100,0),
(@PATH,18,3542.247,134.1484,169.6936,0,0,0,100,0);

SET @NPC := 99109;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3590.88,69.88932,149.1064,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3349.674,233.3671,149.1064,0,0,0,100,0),
(@PATH,2,3050.534,331.2801,149.1064,0,0,0,100,0),
(@PATH,3,2982.76,530.9803,149.1064,0,0,0,100,0),
(@PATH,4,3091.488,621.5792,149.1064,0,0,0,100,0),
(@PATH,5,3227.927,595.5925,149.1064,0,0,0,100,0),
(@PATH,6,3467.181,481.7014,149.1064,0,0,0,100,0),
(@PATH,7,3708.623,396.748,149.1064,0,0,0,100,0),
(@PATH,8,3763.585,194.9491,149.1064,0,0,0,100,0),
(@PATH,9,3590.88,69.88932,149.1064,0,0,0,100,0);

SET @NPC := 99110;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3424.549,257.6351,132.4231,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3523.625,148.6501,132.4231,0,0,0,100,0),
(@PATH,2,3671.965,176.3331,132.4231,0,0,0,100,0),
(@PATH,3,3721.304,302.0294,132.4231,0,0,0,100,0),
(@PATH,4,3586.378,436.0151,132.4231,0,0,0,100,0),
(@PATH,5,3398.783,363.715,132.4231,0,0,0,100,0),
(@PATH,6,3201.002,184.2853,132.4231,0,0,0,100,0),
(@PATH,7,3033.273,261.4108,132.4231,0,0,0,100,0),
(@PATH,8,3020.73,417.366,132.4231,0,0,0,100,0),
(@PATH,9,3134.54,559.4572,132.4231,0,0,0,100,0),
(@PATH,10,3286.472,590.3685,132.4231,0,0,0,100,0),
(@PATH,11,3370.537,476.4369,132.4231,0,0,0,100,0),
(@PATH,12,3424.549,257.6351,132.4231,0,0,0,100,0);

SET @NPC := 99111;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3485.543,172.4427,356.9669,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3617.296,247.1156,357.3557,0,0,0,100,0),
(@PATH,2,3589.83,487.236,356.9669,0,0,0,100,0),
(@PATH,3,3417.021,598.9542,356.9669,0,0,0,100,0),
(@PATH,4,3230.356,615.1475,346.9949,0,0,0,100,0),
(@PATH,5,3061.912,567.3838,332.8835,0,0,0,100,0),
(@PATH,6,2990.214,429.7983,332.8835,0,0,0,100,0),
(@PATH,7,3203.85,198.3223,332.8835,0,0,0,100,0),
(@PATH,8,3485.543,172.4427,356.9669,0,0,0,100,0);

SET @NPC := 99112;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3037.007,696.7842,221.9052,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3232.783,646.5775,221.9052,0,0,0,100,0),
(@PATH,2,3397.601,486.7037,221.9052,0,0,0,100,0),
(@PATH,3,3619.899,375.7408,221.9052,0,0,0,100,0),
(@PATH,4,3828.234,403.8529,221.9052,0,0,0,100,0),
(@PATH,5,3950.75,272.4162,221.9052,0,0,0,100,0),
(@PATH,6,3930.549,80.84885,221.9052,0,0,0,100,0),
(@PATH,7,3731.407,15.2053,221.9052,0,0,0,100,0),
(@PATH,8,3520.57,124.0501,221.9052,0,0,0,100,0),
(@PATH,9,3319.81,205.5578,221.9052,0,0,0,100,0),
(@PATH,10,3141.857,364.067,221.9052,0,0,0,100,0),
(@PATH,11,3020.412,487.4164,211.0165,0,0,0,100,0),
(@PATH,12,2956.715,583.454,211.0165,0,0,0,100,0),
(@PATH,13,3037.007,696.7842,221.9052,0,0,0,100,0);

SET @NPC := 99113;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3723.934,203.8074,149.416,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3679.447,16.12554,149.416,0,0,0,100,0),
(@PATH,2,3507.391,-64.8457,149.416,0,0,0,100,0),
(@PATH,3,3313.535,24.35514,149.416,0,0,0,100,0),
(@PATH,4,3106.862,208.8542,149.416,0,0,0,100,0),
(@PATH,5,2972.297,312.9027,149.416,0,0,0,100,0),
(@PATH,6,2980.743,486.7836,149.416,0,0,0,100,0),
(@PATH,7,3066.302,566.5879,149.416,0,0,0,100,0),
(@PATH,8,3202.917,598.3837,149.416,0,0,0,100,0),
(@PATH,9,3404.993,515.3446,149.416,0,0,0,100,0),
(@PATH,10,3425.663,255.2629,149.416,0,0,0,100,0),
(@PATH,11,3211.951,114.9269,149.416,0,0,0,100,0),
(@PATH,12,3000.342,217.3278,149.416,0,0,0,100,0),
(@PATH,13,2963.022,422.1858,149.416,0,0,0,100,0),
(@PATH,14,3166.04,544.8924,149.416,0,0,0,100,0),
(@PATH,15,3358.634,487.4157,149.416,0,0,0,100,0),
(@PATH,16,3582.295,398.5222,149.416,0,0,0,100,0),
(@PATH,17,3723.934,203.8074,149.416,0,0,0,100,0);

SET @NPC := 99114;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3737.246,441.4471,163.1518,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3681.252,275.5609,163.1518,0,0,0,100,0),
(@PATH,2,3715.161,150.0893,163.1518,0,0,0,100,0),
(@PATH,3,3533.266,-10.55339,163.1518,0,0,0,100,0),
(@PATH,4,3173.073,184.9491,151.4297,0,0,0,100,0),
(@PATH,5,2936.554,340.61,144.8464,0,0,0,100,0),
(@PATH,6,2956.506,455.4837,133.5686,0,0,0,100,0),
(@PATH,7,3032.773,515.5552,122.4019,0,0,0,100,0),
(@PATH,8,3178.638,523.1923,126.2074,0,0,0,100,0),
(@PATH,9,3413.29,470.1859,126.2074,0,0,0,100,0),
(@PATH,10,3572.062,487.1479,144.1519,0,0,0,100,0),
(@PATH,11,3523.323,611.9957,144.1519,0,0,0,100,0),
(@PATH,12,3655.581,727.4493,168.9574,0,0,0,100,0),
(@PATH,13,3772.614,626.3416,163.1518,0,0,0,100,0),
(@PATH,14,3737.246,441.4471,163.1518,0,0,0,100,0);

SET @NPC := 99115;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3490.259,76.95345,197.2588,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3733.682,129.7717,197.2588,0,0,0,100,0),
(@PATH,2,3864.96,508.5689,197.2588,0,0,0,100,0),
(@PATH,3,3552.458,522.002,197.2588,0,0,0,100,0),
(@PATH,4,3285.309,616.7151,197.2588,0,0,0,100,0),
(@PATH,5,3036.671,572.0858,197.2588,0,0,0,100,0),
(@PATH,6,2932.137,492.1258,197.2588,0,0,0,100,0),
(@PATH,7,2908.21,365.3067,197.2588,0,0,0,100,0),
(@PATH,8,3001.178,249.2961,197.2588,0,0,0,100,0),
(@PATH,9,3292.851,156.1309,197.2588,0,0,0,100,0),
(@PATH,10,3490.259,76.95345,197.2588,0,0,0,100,0);

SET @NPC := 99116;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3484.9,77.65061,181.4013,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3231.553,144.962,181.4013,0,0,0,100,0),
(@PATH,2,3093.218,232.0598,181.4013,0,0,0,100,0),
(@PATH,3,3055.291,416.8134,181.4013,0,0,0,100,0),
(@PATH,4,3167.159,544.8934,181.4013,0,0,0,100,0),
(@PATH,5,3351.382,640.3859,181.4013,0,0,0,100,0),
(@PATH,6,3588.236,561.4211,181.4013,0,0,0,100,0),
(@PATH,7,3702.199,377.5353,181.4013,0,0,0,100,0),
(@PATH,8,3664.586,182.5018,181.4013,0,0,0,100,0),
(@PATH,9,3484.9,77.65061,181.4013,0,0,0,100,0);

SET @NPC := 99117;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,2938.209,403.6825,200.0642,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3000.396,533.5293,200.0642,0,0,0,100,0),
(@PATH,2,3148.834,635.804,200.0642,0,0,0,100,0),
(@PATH,3,3307.068,630.108,200.0642,0,0,0,100,0),
(@PATH,4,3393.553,425.3046,200.0642,0,0,0,100,0),
(@PATH,5,3413.431,212.6353,200.0642,0,0,0,100,0),
(@PATH,6,3566.631,98.43479,200.0642,0,0,0,100,0),
(@PATH,7,3729.045,218.3996,200.0642,0,0,0,100,0),
(@PATH,8,3698.444,417.5869,200.0642,0,0,0,100,0),
(@PATH,9,3524.363,494.4065,200.0642,0,0,0,100,0),
(@PATH,10,3335.302,374.7052,200.0642,0,0,0,100,0),
(@PATH,11,3255.138,189.5002,200.0642,0,0,0,100,0),
(@PATH,12,3111.794,148.6386,200.0642,0,0,0,100,0),
(@PATH,13,2979.718,214.2472,200.0642,0,0,0,100,0),
(@PATH,14,2938.209,403.6825,200.0642,0,0,0,100,0);

SET @NPC := 99118;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,27608,571,1,1,24140,0,3756.611,216.3398,142.0742,1.91463,120,0,0,92538,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3746.663,468.0216,142.0742,0,0,0,100,0),
(@PATH,2,3489.741,512.316,142.0742,0,0,0,100,0),
(@PATH,3,3277.682,558.9236,142.0742,0,0,0,100,0),
(@PATH,4,3152.218,477.8159,142.0742,0,0,0,100,0),
(@PATH,5,3082.888,432.7688,142.0742,0,0,0,100,0),
(@PATH,6,3016.838,481.925,142.0742,0,0,0,100,0),
(@PATH,7,3033.647,560.426,142.0742,0,0,0,100,0),
(@PATH,8,3162.152,562.8186,142.0742,0,0,0,100,0),
(@PATH,9,3240.709,468.0213,142.0742,0,0,0,100,0),
(@PATH,10,3371.026,259.9583,142.0742,0,0,0,100,0),
(@PATH,11,3535.323,122.4076,142.0742,0,0,0,100,0),
(@PATH,12,3756.611,216.3398,142.0742,0,0,0,100,0);

-- Wyrmrest Temple Drake

DELETE FROM `creature` WHERE `guid` IN (100170,100206,100207,100208,100209,100210,100213,100215,100216,100226,130999,131000,131001,131002,131003,131006,131004,131005,131007,131008,131009);

UPDATE `creature_template` SET `speed_walk`=9/2,`speed_run`=17/7,`InhabitType`=4 WHERE `entry`=26925;

SET @NPC := 100170;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3423.212,279.9993,128.0342,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3423.212,279.9993,128.0342,0,0,0,100,0),
(@PATH,2,3452.103,334.373,128.0342,0,0,0,100,0),
(@PATH,3,3463.885,390.2345,128.0342,0,0,0,100,0),
(@PATH,4,3459.316,448.6561,128.0342,0,0,0,100,0),
(@PATH,5,3390.542,472.8465,128.0342,0,0,0,100,0),
(@PATH,6,3343.515,429.0621,128.0342,0,0,0,100,0),
(@PATH,7,3319.781,350.6016,128.0342,0,0,0,100,0),
(@PATH,8,3342.761,276.0052,128.0342,0,0,0,100,0),
(@PATH,9,3381.065,257.5826,128.0342,0,0,0,100,0);

SET @NPC := 100206;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3662.692,328.2304,338.4197,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3662.692,328.2304,338.4197,0,0,0,100,0),
(@PATH,2,3648.806,293.8063,321.0587,0,0,0,100,0),
(@PATH,3,3677.441,213.8859,320.1976,0,0,0,100,0),
(@PATH,4,3615.31,209.5691,324.1698,0,0,0,100,0),
(@PATH,5,3637.643,254.0089,332.7251,0,0,0,100,0),
(@PATH,6,3699.886,260.6509,327.8641,0,0,0,100,0),
(@PATH,7,3720.373,308.941,337.7808,0,0,0,100,0),
(@PATH,8,3691.676,352.0933,342.2254,0,0,0,100,0);

SET @NPC := 100207;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3657.962,213.0957,169.3146,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3657.962,213.0957,169.3146,0,0,0,100,0),
(@PATH,2,3667.34,194.262,169.3146,0,0,0,100,0),
(@PATH,3,3675.021,149.4151,169.3146,0,0,0,100,0),
(@PATH,4,3676.687,103.2968,169.3146,0,0,0,100,0),
(@PATH,5,3657.863,59.17426,169.3146,0,0,0,100,0),
(@PATH,6,3622.093,33.20833,169.3146,0,0,0,100,0),
(@PATH,7,3595.094,36.79308,169.3146,0,0,0,100,0),
(@PATH,8,3578.594,58.34657,169.3146,0,0,0,100,0),
(@PATH,9,3553.642,84.92133,169.3146,0,0,0,100,0),
(@PATH,10,3558.182,112.2144,169.3146,0,0,0,100,0),
(@PATH,11,3570.514,135.5537,169.3146,0,0,0,100,0),
(@PATH,12,3596.293,162.6956,169.3146,0,0,0,100,0),
(@PATH,13,3618.115,186.3872,169.3146,0,0,0,100,0),
(@PATH,14,3648.757,225.0738,169.3146,0,0,0,100,0);

SET @NPC := 100208;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3606.596,396.9579,205.5612,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3606.596,396.9579,205.5612,0,0,0,100,0),
(@PATH,2,3633.08,397.3744,205.5612,0,0,0,100,0),
(@PATH,3,3650.996,425.418,205.5612,0,0,0,100,0),
(@PATH,4,3610.396,457.8707,205.5612,0,0,0,100,0),
(@PATH,5,3510.082,450.9809,205.5612,0,0,0,100,0),
(@PATH,6,3435.127,411.1036,205.5612,0,0,0,100,0),
(@PATH,7,3388.161,429.3571,205.5612,0,0,0,100,0),
(@PATH,8,3406.552,481.8189,205.5612,0,0,0,100,0),
(@PATH,9,3518.298,499.1305,205.5612,0,0,0,100,0),
(@PATH,10,3568.027,418.6763,205.5612,0,0,0,100,0);

SET @NPC := 100209;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3648.806,293.8063,321.0587,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3648.806,293.8063,321.0587,0,0,0,100,0),
(@PATH,2,3677.441,213.8859,320.1976,0,0,0,100,0),
(@PATH,3,3615.31,209.5691,324.1698,0,0,0,100,0),
(@PATH,4,3637.643,254.0089,332.7251,0,0,0,100,0),
(@PATH,5,3699.886,260.6509,327.8641,0,0,0,100,0),
(@PATH,6,3720.373,308.941,337.7808,0,0,0,100,0),
(@PATH,7,3691.676,352.0933,342.2254,0,0,0,100,0),
(@PATH,8,3662.692,328.2304,338.4197,0,0,0,100,0);

SET @NPC := 100210;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3452.103,334.373,128.0342,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3452.103,334.373,128.0342,0,0,0,100,0),
(@PATH,2,3334.853,530.1229,197.2842,0,0,0,100,0),
(@PATH,3,3325.103,359.123,195.7842,0,0,0,100,0),
(@PATH,4,3499.853,334.623,195.0342,0,0,0,100,0),
(@PATH,5,3263.353,527.8729,197.2842,0,0,0,100,0),
(@PATH,6,3706.853,80.87296,195.7842,0,0,0,100,0),
(@PATH,7,3499.853,334.623,195.0342,0,0,0,100,0),
(@PATH,8,3495.603,493.623,197.2842,0,0,0,100,0),
(@PATH,9,3218.353,177.623,195.7842,0,0,0,100,0);

SET @NPC := 100213;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3648.806,293.8063,321.0587,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3648.806,293.8063,321.0587,0,0,0,100,0),
(@PATH,2,3588.806,84.30627,390.3087,0,0,0,100,0),
(@PATH,3,3827.556,468.8063,388.3087,0,0,0,100,0),
(@PATH,4,3731.556,38.55627,388.5587,0,0,0,100,0),
(@PATH,5,3454.556,53.30627,390.3087,0,0,0,100,0),
(@PATH,6,3756.306,434.3063,388.3087,0,0,0,100,0),
(@PATH,7,3503.556,54.30627,388.5587,0,0,0,100,0),
(@PATH,8,3795.056,64.55627,390.3087,0,0,0,100,0);

SET @NPC := 100215;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3606.596,396.9579,205.5612,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3606.596,396.9579,205.5612,0,0,0,100,0),
(@PATH,2,3688.846,165.4579,274.8112,0,0,0,100,0),
(@PATH,3,3601.846,450.2079,273.3112,0,0,0,100,0),
(@PATH,4,3585.346,505.2079,272.8112,0,0,0,100,0),
(@PATH,5,3602.096,174.2079,274.8112,0,0,0,100,0),
(@PATH,6,3446.596,562.4579,273.3112,0,0,0,100,0),
(@PATH,7,3585.346,505.2079,272.8112,0,0,0,100,0),
(@PATH,8,3500.346,153.9579,274.8112,0,0,0,100,0),
(@PATH,9,3571.096,180.2079,273.3112,0,0,0,100,0),
(@PATH,10,3585.346,505.2079,272.8112,0,0,0,100,0);

SET @NPC := 100216;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3772.475,266.6113,254.1891,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3772.475,266.6113,254.1891,0,0,0,100,0),
(@PATH,2,3887.975,92.86133,323.4391,0,0,0,100,0),
(@PATH,3,3532.475,436.8613,321.6891,0,0,0,100,0),
(@PATH,4,3798.725,252.1113,321.4391,0,0,0,100,0),
(@PATH,5,3886.225,81.11133,323.4391,0,0,0,100,0),
(@PATH,6,3636.975,32.11133,321.6891,0,0,0,100,0),
(@PATH,7,3798.725,252.1113,321.4391,0,0,0,100,0),
(@PATH,8,3747.725,77.61133,323.4391,0,0,0,100,0),
(@PATH,9,3772.475,165.6113,321.6891,0,0,0,100,0),
(@PATH,10,3798.725,252.1113,321.4391,0,0,0,100,0),
(@PATH,11,3899.725,81.86133,323.4391,0,0,0,100,0),
(@PATH,12,3936.975,216.1113,321.6891,0,0,0,100,0),
(@PATH,13,3798.725,252.1113,321.4391,0,0,0,100,0),
(@PATH,14,3755.975,93.86133,323.4391,0,0,0,100,0),
(@PATH,15,3785.475,362.1113,321.9391,0,0,0,100,0),
(@PATH,16,3798.725,252.1113,321.4391,0,0,0,100,0);

SET @NPC := 100226;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3447.796,171.34,125.7842,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3447.796,171.34,125.7842,0,0,0,100,0),
(@PATH,2,3456.033,100.7345,125.7842,0,0,0,100,0),
(@PATH,3,3388.28,76.85818,125.7842,0,0,0,100,0),
(@PATH,4,3360.649,126.0434,125.7842,0,0,0,100,0),
(@PATH,5,3368.991,199.87,125.7842,0,0,0,100,0),
(@PATH,6,3432.052,296.2538,125.7842,0,0,0,100,0),
(@PATH,7,3465.493,406.8654,125.7842,0,0,0,100,0),
(@PATH,8,3397.028,457.6761,125.7842,0,0,0,100,0),
(@PATH,9,3354.537,408.359,125.7842,0,0,0,100,0),
(@PATH,10,3384.226,319.0551,125.7842,0,0,0,100,0),
(@PATH,11,3433.646,226.0049,125.7842,0,0,0,100,0);

SET @NPC := 130999;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26925,571,1,1,6376,0,3750.984,407.8766,254.1891,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3750.984,407.8766,254.1891,0,0,0,100,0),
(@PATH,2,3786.711,439.0684,254.1891,0,0,0,100,0),
(@PATH,3,3830.952,442.1341,254.1891,0,0,0,100,0),
(@PATH,4,3862.503,430.8392,254.1891,0,0,0,100,0),
(@PATH,5,3882.549,422.6376,254.1891,0,0,0,100,0),
(@PATH,6,3890.228,394.8426,254.1891,0,0,0,100,0),
(@PATH,7,3871.091,383.1622,254.1891,0,0,0,100,0),
(@PATH,8,3860.575,369.1732,254.1891,0,0,0,100,0),
(@PATH,9,3840.769,340.5143,257.8279,0,0,0,100,0),
(@PATH,10,3832.232,320.8624,264.8557,0,0,0,100,0),
(@PATH,11,3801.307,290.9948,262.5502,0,0,0,100,0),
(@PATH,12,3775.203,268.874,254.1891,0,0,0,100,0),
(@PATH,13,3772.475,266.6113,254.1891,0,0,0,100,0),
(@PATH,14,3748.613,298.5957,254.1891,0,0,0,100,0),
(@PATH,15,3725.111,325.421,254.1891,0,0,0,100,0),
(@PATH,16,3718.476,358.75,254.1891,0,0,0,100,0),
(@PATH,17,3726.624,371.3951,254.1891,0,0,0,100,0);

-- Wyrmrest Guardian

DELETE FROM `creature` WHERE `guid` IN (100823,100824,100825,100826,131035,131036,131037,131038,131039,131040,131041,131042,131043,131044,131045,131046,131047,131048,131049,131050);
UPDATE `creature_template` SET `speed_walk`=7/2,`speed_run`=15/7,`InhabitType`=4 WHERE `entry`=26933;

SET @NPC := 100823;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3791.882,255.4148,152.3366,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3791.882,255.4148,152.3366,0,0,0,100,0),
(@PATH,2,3834.405,230.3203,152.3366,0,0,0,100,0),
(@PATH,3,3876.825,233.7821,152.3366,0,0,0,100,0),
(@PATH,4,3900.443,242.9511,152.3366,0,0,0,100,0),
(@PATH,5,3916.114,280.9176,152.3366,0,0,0,100,0),
(@PATH,6,3906.543,328.6796,152.3366,0,0,0,100,0),
(@PATH,7,3897.018,362.4748,152.3366,0,0,0,100,0),
(@PATH,8,3881.718,402.3574,152.3366,0,0,0,100,0),
(@PATH,9,3858.27,431.4729,152.3366,0,0,0,100,0),
(@PATH,10,3816.65,448.8396,152.3366,0,0,0,100,0),
(@PATH,11,3767.092,457.8965,152.3366,0,0,0,100,0),
(@PATH,12,3720.177,443.4765,152.3366,0,0,0,100,0),
(@PATH,13,3699.901,410.0056,152.3366,0,0,0,100,0),
(@PATH,14,3723.531,374.0899,152.3366,0,0,0,100,0),
(@PATH,15,3739.026,327.0149,152.3366,0,0,0,100,0),
(@PATH,16,3762.99,312.7233,152.3366,0,0,0,100,0),
(@PATH,17,3774.031,299.9361,152.3366,0,0,0,100,0),
(@PATH,18,3786.234,277.9988,152.3366,0,0,0,100,0);

SET @NPC := 100824;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3559.792,412.912,244.8625,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3559.792,412.912,244.8625,0,0,0,100,0),
(@PATH,2,3625.949,456.7731,244.8625,0,0,0,100,0),
(@PATH,3,3683.285,437.189,244.8625,0,0,0,100,0),
(@PATH,4,3727.341,385.3615,244.8625,0,0,0,100,0),
(@PATH,5,3786.656,388.9702,244.8625,0,0,0,100,0),
(@PATH,6,3811.097,463.1342,244.8625,0,0,0,100,0),
(@PATH,7,3769.007,516.1342,244.8625,0,0,0,100,0),
(@PATH,8,3685.209,493.7117,244.8625,0,0,0,100,0),
(@PATH,9,3589.482,475.7777,244.8625,0,0,0,100,0),
(@PATH,10,3491.84,496.9259,244.8625,0,0,0,100,0),
(@PATH,11,3406.895,485.8197,244.8625,0,0,0,100,0),
(@PATH,12,3370.333,427.0351,244.8625,0,0,0,100,0),
(@PATH,13,3411.417,366.7467,244.8625,0,0,0,100,0),
(@PATH,14,3479.214,376.5652,244.8625,0,0,0,100,0);

SET @NPC := 100825;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3424.446,300.7501,194.3189,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3424.446,300.7501,194.3189,0,0,0,100,0),
(@PATH,2,3427.025,177.7048,194.3189,0,0,0,100,0),
(@PATH,3,3508.415,97.62153,194.3189,0,0,0,100,0),
(@PATH,4,3635.289,110.5046,194.3189,0,0,0,100,0),
(@PATH,5,3728.01,244.8104,194.3189,0,0,0,100,0),
(@PATH,6,3655.76,402.0861,194.3189,0,0,0,100,0),
(@PATH,7,3513.567,405.2664,194.3189,0,0,0,100,0);

SET @NPC := 100826;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3457.605,232.8917,280.631,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3457.605,232.8917,280.631,0,0,0,100,0),
(@PATH,2,3414.099,307.4206,280.631,0,0,0,100,0),
(@PATH,3,3470.344,415.2286,280.631,0,0,0,100,0),
(@PATH,4,3607.002,418.6074,280.631,0,0,0,100,0),
(@PATH,5,3711.957,340.5557,280.631,0,0,0,100,0),
(@PATH,6,3720.49,226.3188,280.631,0,0,0,100,0),
(@PATH,7,3642.503,140.184,280.631,0,0,0,100,0),
(@PATH,8,3516.544,159.0889,280.631,0,0,0,100,0);

SET @NPC := 131035;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3559.792,412.912,244.8625,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3559.792,412.912,244.8625,0,0,0,100,0),
(@PATH,2,3625.949,456.7731,244.8625,0,0,0,100,0),
(@PATH,3,3683.285,437.189,244.8625,0,0,0,100,0),
(@PATH,4,3727.341,385.3615,244.8625,0,0,0,100,0),
(@PATH,5,3786.656,388.9702,244.8625,0,0,0,100,0),
(@PATH,6,3811.097,463.1342,244.8625,0,0,0,100,0),
(@PATH,7,3769.007,516.1342,244.8625,0,0,0,100,0),
(@PATH,8,3685.209,493.7117,244.8625,0,0,0,100,0),
(@PATH,9,3589.482,475.7777,244.8625,0,0,0,100,0),
(@PATH,10,3491.84,496.9259,244.8625,0,0,0,100,0),
(@PATH,11,3406.895,485.8197,244.8625,0,0,0,100,0),
(@PATH,12,3370.333,427.0351,244.8625,0,0,0,100,0),
(@PATH,13,3411.417,366.7467,244.8625,0,0,0,100,0),
(@PATH,14,3479.214,376.5652,244.8625,0,0,0,100,0);

SET @NPC := 131036;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3438.608,283.5485,224.3952,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3438.608,283.5485,224.3952,0,0,0,100,0),
(@PATH,2,3422.991,341.0565,224.3952,0,0,0,100,0),
(@PATH,3,3372.117,385.6395,224.3952,0,0,0,100,0),
(@PATH,4,3315.855,342.7029,224.3952,0,0,0,100,0),
(@PATH,5,3294.378,270.6668,224.3952,0,0,0,100,0),
(@PATH,6,3321.572,194.6726,224.3952,0,0,0,100,0),
(@PATH,7,3385.174,162.3308,224.3952,0,0,0,100,0),
(@PATH,8,3437.712,218.1042,224.3952,0,0,0,100,0);

SET @NPC := 131037;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3337.373,175.2911,169.6936,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3337.373,175.2911,169.6936,0,0,0,100,0),
(@PATH,2,3292.872,421.84,169.6936,0,0,0,100,0),
(@PATH,3,3355.351,609.4697,169.6936,0,0,0,100,0),
(@PATH,4,3233.689,777.6954,207.249,0,0,0,100,0),
(@PATH,5,3049.014,721.6703,224.4991,0,0,0,100,0),
(@PATH,6,3044.268,566.5984,169.6936,0,0,0,100,0),
(@PATH,7,3142.397,481.2142,169.6936,0,0,0,100,0),
(@PATH,8,3328.336,435.8111,169.6936,0,0,0,100,0),
(@PATH,9,3583.232,539.7742,169.6936,0,0,0,100,0),
(@PATH,10,3799.81,460.638,169.6936,0,0,0,100,0),
(@PATH,11,3717.946,244.38,169.6936,0,0,0,100,0),
(@PATH,12,3542.247,134.1484,169.6936,0,0,0,100,0),
(@PATH,13,3378.177,251.381,169.6936,0,0,0,100,0),
(@PATH,14,3448.559,417.0887,169.6936,0,0,0,100,0),
(@PATH,15,3659.633,429.129,169.6936,0,0,0,100,0),
(@PATH,16,3726.806,236.8274,169.6936,0,0,0,100,0),
(@PATH,17,3554.261,69.58746,169.6936,0,0,0,100,0);

SET @NPC := 131038;
SET @PATH := @NPC*10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,26933,571,1,1,0,0,3738.288,310.6056,206.0655,1.91463,120,0,0,1,0,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`) VALUES (@NPC,@PATH,50331648);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3738.288,310.6056,206.0655,0,0,0,100,0),
(@PATH,1,3775.943,320.1521,206.0655,0,0,0,100,0),
(@PATH,1,3791.984,364.0035,206.0655,0,0,0,100,0),
(@PATH,1,3821.821,375.4122,206.0655,0,0,0,100,0),
(@PATH,1,3862.769,402.7154,206.0655,0,0,0,100,0),
(@PATH,1,3833.872,426.7561,206.0655,0,0,0,100,0),
(@PATH,1,3796.899,413.8476,206.0655,0,0,0,100,0),
(@PATH,1,3780.125,433.8598,206.0655,0,0,0,100,0),
(@PATH,1,3736.043,443.3744,206.0655,0,0,0,100,0),
(@PATH,1,3713.603,445.3026,206.0655,0,0,0,100,0),
(@PATH,1,3683.613,406.9387,206.0655,0,0,0,100,0),
(@PATH,1,3706.474,364.4982,206.0655,0,0,0,100,0),
(@PATH,1,3712.073,324.8767,206.0655,0,0,0,100,0);
