-- Coldarra Rework #1

-- Magic Bound Ancient
DELETE FROM `creature` WHERE `id` IN (25707);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122544, 25707, 571, 0, 0, 1, 1, 0, 0, 3919.0464, 6772.4097, 150.95813, 0.122173048555850982, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122545, 25707, 571, 0, 0, 1, 1, 0, 0, 4069.1807, 6925.456, 164.76578, 4.269334793090820312, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122546, 25707, 571, 0, 0, 1, 1, 0, 0, 4024.9348, 7163.997, 171.60469, 2.921030044555664062, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122547, 25707, 571, 0, 0, 1, 1, 0, 0, 3737.6138, 6865.7134, 156.01257, 5.916666030883789062, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122548, 25707, 571, 0, 0, 1, 1, 0, 0, 3552.8347, 7094.2104, 212.32523, 1.812281250953674316, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122549, 25707, 571, 0, 0, 1, 1, 0, 0, 3962.9202, 6652.3413, 169.25267, 5.018960952758789062, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122550, 25707, 571, 0, 0, 1, 1, 0, 0, 3777.524, 6558.7095, 172.83856, 5.446483612060546875, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122551, 25707, 571, 0, 0, 1, 1, 0, 0, 3672.4993, 6965.212, 157.5034, 4.477772235870361328, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100873, 25707, 571, 0, 0, 1, 1, 0, 0, 3687.6763, 7116.0977, 159.97055, 1.145161628723144531, 300, 0, 0, 1, 0, 2, 0, 0, 0, '', 0);

UPDATE `creature` SET `wander_distance`=30, `MovementType`=1 WHERE `id`=25707;

-- Pathing for Magic Bound Ancient Entry: 25707
SET @NPC := 100873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3710.0786,7142.518,160.42256,NULL,0,0,0,100,0),
(@PATH,2,3685.0994,7134.016,160.31078,NULL,0,0,0,100,0),
(@PATH,3,3670.7761,7109.463,160.23125,NULL,0,0,0,100,0),
(@PATH,4,3664.274,7094.7397,160.49896,NULL,0,0,0,100,0),
(@PATH,5,3680.6907,7065.5913,158.97064,NULL,0,0,0,100,0),
(@PATH,6,3664.274,7094.7397,160.49896,NULL,0,0,0,100,0),
(@PATH,7,3670.7761,7109.463,160.23125,NULL,0,0,0,100,0),
(@PATH,8,3685.0994,7134.016,160.31078,NULL,0,0,0,100,0),
(@PATH,9,3710.0786,7142.518,160.42256,NULL,0,0,0,100,0),
(@PATH,10,3686.6892,7155.103,160.38585,NULL,0,0,0,100,0),
(@PATH,11,3710.0698,7165.4565,160.17256,NULL,0,0,0,100,0),
(@PATH,12,3686.6892,7155.103,160.38585,NULL,0,0,0,100,0);

-- Glacial Ancient
DELETE FROM `creature` WHERE `id` IN (25709);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122558, 25709, 571, 0, 0, 1, 1, 0, 0, 4011.102, 6759.718, 162.24669, 5.478335380554199218, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122559, 25709, 571, 0, 0, 1, 1, 0, 0, 4202.8525, 7043.0024, 174.90007, 0.667340993881225585, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122562, 25709, 571, 0, 0, 1, 1, 0, 0, 3839.6016, 7247.384, 170.94463, 3.838457345962524414, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122563, 25709, 571, 0, 0, 1, 1, 0, 0, 3713.2415, 6791.809, 160.78369, 3.073458194732666015, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122564, 25709, 571, 0, 0, 1, 1, 0, 0, 3613.5398, 7234.1436, 219.52881, 4.725327968597412109, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122565, 25709, 571, 0, 0, 1, 1, 0, 0, 3518.3289, 7210.9644, 234.95082, 2.488574981689453125, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122566, 25709, 571, 0, 0, 1, 1, 0, 0, 3878.6936, 6558.1514, 172.19272, 4.088553428649902343, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122557, 25709, 571, 0, 0, 1, 1, 0, 0, 3693.0813, 7306.9985, 215.94733, 2.443134784698486328, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122558;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4024.5872,6745.6895,163.52673,NULL,0,0,0,100,0),
(@PATH,2,4006.2126,6728.375,159.26367,NULL,0,0,0,100,0),
(@PATH,3,3985.254,6729.6875,156.35841,NULL,0,0,0,100,0),
(@PATH,4,3946.3862,6749.6777,152.21883,NULL,0,0,0,100,0),
(@PATH,5,3953.4023,6775.0596,153.6555,NULL,0,0,0,100,0),
(@PATH,6,3974.544,6816.7456,158.04942,NULL,0,0,0,100,0),
(@PATH,7,3995.5168,6792.0503,160.61603,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122559;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4180.837,7037.792,169.9722,NULL,0,0,0,100,0),
(@PATH,2,4204.7085,7044.4644,175.21199,NULL,0,0,0,100,0),
(@PATH,3,4180.837,7037.792,169.9722,NULL,0,0,0,100,0),
(@PATH,4,4167.1704,7031.625,167.28969,NULL,0,0,0,100,0),
(@PATH,5,4143.929,7041.769,165.49626,NULL,0,0,0,100,0),
(@PATH,6,4127.6587,7050.8364,165.5785,NULL,0,0,0,100,0),
(@PATH,7,4143.929,7041.769,165.49626,NULL,0,0,0,100,0),
(@PATH,8,4167.1704,7031.625,167.28969,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122562;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3820.2935,7231.2266,166.11594,NULL,0,0,0,100,0),
(@PATH,2,3847.4504,7223.367,167.9072,NULL,0,0,0,100,0),
(@PATH,3,3864.6272,7214.534,168.83347,NULL,0,0,0,100,0),
(@PATH,4,3877.55,7192.7876,167.33025,NULL,0,0,0,100,0),
(@PATH,5,3880.7205,7166.044,166.97966,NULL,0,0,0,100,0),
(@PATH,6,3849.6707,7162.142,165.56874,NULL,0,0,0,100,0),
(@PATH,7,3829.8633,7192.7803,161.93594,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122563;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3666.53,6794.999,168.44847,NULL,0,0,0,100,0),
(@PATH,2,3636.787,6825.888,166.18665,NULL,0,0,0,100,0),
(@PATH,3,3677.302,6810.1396,163.73308,NULL,0,0,0,100,0),
(@PATH,4,3707.7153,6799.4595,161.59258,NULL,0,0,0,100,0),
(@PATH,5,3736.927,6812.989,155.187,NULL,0,0,0,100,0),
(@PATH,6,3780.8013,6816.486,149.9789,NULL,0,0,0,100,0),
(@PATH,7,3785.376,6788.383,151.103,NULL,0,0,0,100,0),
(@PATH,8,3780.8013,6816.486,149.9789,NULL,0,0,0,100,0),
(@PATH,9,3736.927,6812.989,155.187,NULL,0,0,0,100,0),
(@PATH,10,3707.7153,6799.4595,161.59258,NULL,0,0,0,100,0),
(@PATH,11,3677.302,6810.1396,163.73308,NULL,0,0,0,100,0),
(@PATH,12,3636.787,6825.888,166.18665,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122564;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3613.847,7209.9346,220.35635,NULL,0,0,0,100,0),
(@PATH,2,3613.6116,7247.6997,220.82181,NULL,0,0,0,100,0),
(@PATH,3,3604.968,7270.3657,226.2565,NULL,0,0,0,100,0),
(@PATH,4,3596.4604,7306.0337,237.99365,NULL,0,0,0,100,0),
(@PATH,5,3624.8538,7319.283,228.70561,NULL,0,0,0,100,0),
(@PATH,6,3624.2566,7281.0615,220.67398,NULL,0,0,0,100,0),
(@PATH,7,3624.8538,7319.283,228.70561,NULL,0,0,0,100,0),
(@PATH,8,3596.4604,7306.0337,237.99365,NULL,0,0,0,100,0),
(@PATH,9,3604.968,7270.3657,226.2565,NULL,0,0,0,100,0),
(@PATH,10,3613.6116,7247.6997,220.82181,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122565;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3556.0361,7205.7764,226.74023,NULL,0,0,0,100,0),
(@PATH,2,3594.6924,7187.0776,222.85994,NULL,0,0,0,100,0),
(@PATH,3,3586.2773,7143.339,219.81506,NULL,0,0,0,100,0),
(@PATH,4,3586.2683,7119.9395,213.94754,NULL,0,0,0,100,0),
(@PATH,5,3577.9285,7101.9653,212.2963,NULL,0,0,0,100,0),
(@PATH,6,3564.4478,7090.9995,211.84886,NULL,0,0,0,100,0),
(@PATH,7,3520.8474,7092.368,211.7077,NULL,0,0,0,100,0),
(@PATH,8,3516.581,7118.4097,213.74858,NULL,0,0,0,100,0),
(@PATH,9,3507.381,7148.7075,217.62288,NULL,0,0,0,100,0),
(@PATH,10,3513.609,7184.797,226.19087,NULL,0,0,0,100,0),
(@PATH,11,3515.6133,7213.04,236.44092,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122566;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3868.9275,6544.5923,174.12137,NULL,0,0,0,100,0),
(@PATH,2,3856.2883,6523.9946,177.40477,NULL,0,0,0,100,0),
(@PATH,3,3833.472,6541.0806,172.93208,NULL,0,0,0,100,0),
(@PATH,4,3835.9966,6567.2944,168.50136,NULL,0,0,0,100,0),
(@PATH,5,3868.2712,6588.432,166.66737,NULL,0,0,0,100,0),
(@PATH,6,3882.2578,6572.7637,169.84169,NULL,0,0,0,100,0);

-- Pathing for Glacial Ancient Entry: 25709
SET @NPC := 122557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3675.5374,7306.5054,221.06854,NULL,0,0,0,100,0),
(@PATH,2,3660.6736,7334.2603,231.26143,NULL,0,0,0,100,0),
(@PATH,3,3675.5374,7306.5054,221.06854,NULL,0,0,0,100,0),
(@PATH,4,3703.817,7300.9053,212.11235,NULL,0,0,0,100,0),
(@PATH,5,3730.8315,7319.877,209.50371,NULL,0,0,0,100,0),
(@PATH,6,3754.1438,7331.085,207.86629,NULL,0,0,0,100,0),
(@PATH,7,3788.6714,7357.029,200.78316,NULL,0,0,0,100,0),
(@PATH,8,3818.655,7374.163,194.75764,NULL,0,0,0,100,0),
(@PATH,9,3848.245,7379.1143,192.71239,NULL,0,0,0,100,0),
(@PATH,10,3870.7856,7378.1753,189.21025,NULL,0,0,0,100,0),
(@PATH,11,3868.058,7345.4297,183.30672,NULL,0,0,0,100,0),
(@PATH,12,3845.2756,7312.8604,179.77147,NULL,0,0,0,100,0),
(@PATH,13,3831.3008,7284.7676,173.62045,NULL,0,0,0,100,0),
(@PATH,14,3820.2422,7242.6167,167.53392,NULL,0,0,0,100,0),
(@PATH,15,3841.4866,7223.8,167.11179,NULL,0,0,0,100,0),
(@PATH,16,3866.981,7191.7856,166.34148,NULL,0,0,0,100,0),
(@PATH,17,3851.7205,7215.319,167.19724,NULL,0,0,0,100,0),
(@PATH,18,3843.0972,7240.5337,170.16501,NULL,0,0,0,100,0),
(@PATH,19,3852.6033,7252.8604,174.3005,NULL,0,0,0,100,0),
(@PATH,20,3868.6675,7259.01,177.25177,NULL,0,0,0,100,0),
(@PATH,21,3867.086,7232.291,172.17238,NULL,0,0,0,100,0),
(@PATH,22,3887.4387,7256.7417,177.28339,NULL,0,0,0,100,0),
(@PATH,23,3858.8047,7269.803,177.80449,NULL,0,0,0,100,0),
(@PATH,24,3844.1646,7287.973,175.97807,NULL,0,0,0,100,0),
(@PATH,25,3843.5474,7303.0376,178.24095,NULL,0,0,0,100,0),
(@PATH,26,3854.0408,7325.8975,181.57103,NULL,0,0,0,100,0),
(@PATH,27,3871.6936,7351.5737,184.00484,NULL,0,0,0,100,0),
(@PATH,28,3875.567,7383.0347,189.42778,NULL,0,0,0,100,0),
(@PATH,29,3837.5652,7375.396,193.61229,NULL,0,0,0,100,0),
(@PATH,30,3807.8801,7360.4272,195.09267,NULL,0,0,0,100,0),
(@PATH,31,3776.4932,7340.2646,201.22188,NULL,0,0,0,100,0),
(@PATH,32,3748.6384,7321.0513,207.46468,NULL,0,0,0,100,0),
(@PATH,33,3729.0056,7321.6943,210.25322,NULL,0,0,0,100,0),
(@PATH,34,3713.961,7311.0557,211.42339,NULL,0,0,0,100,0),
(@PATH,35,3684.964,7295.855,216.71893,NULL,0,0,0,100,0);

-- Coldarra Mage Slayer
DELETE FROM `creature` WHERE `id` IN (25718);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122660, 25718, 571, 0, 0, 1, 1, 0, 0, 3749.9895, 6529.933, 179.39224, 3.525565147399902343, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122661, 25718, 571, 0, 0, 1, 1, 0, 0, 3780.7634, 6563.574, 171.74661, 0.436332315206527709, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122662, 25718, 571, 0, 0, 1, 1, 0, 0, 3805.0886, 6541.6396, 173.37148, 1.535889744758605957, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122663, 25718, 571, 0, 0, 1, 1, 0, 0, 3783.3113, 6507.9287, 179.10661, 0.028644446283578872, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122664, 25718, 571, 0, 0, 1, 1, 0, 0, 3829.6707, 6618.727, 163.64185, 3.916461467742919921, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122665, 25718, 571, 0, 0, 1, 1, 0, 0, 3787.7158, 6698.1685, 150.9481, 3.40339207649230957, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122667, 25718, 571, 0, 0, 1, 1, 0, 0, 3804.1025, 6747.5737, 150.38899, 2.321287870407104492, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122668, 25718, 571, 0, 0, 1, 1, 0, 0, 3778.2825, 6662.2593, 151.62486, 0.005363108124583959, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122669, 25718, 571, 0, 0, 1, 1, 0, 0, 3887.513, 6726.927, 151.28596, 6.0589599609375, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122670, 25718, 571, 0, 0, 1, 1, 0, 0, 3899.4019, 6658.005, 168.98055, 4.97418832778930664, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100866, 25718, 571, 0, 0, 1, 1, 0, 0, 3884.4146, 6691.8423, 151.48792, 2.311469078063964843, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100868, 25718, 571, 0, 0, 1, 1, 0, 0, 3849.8762, 6521.465, 177.53319, 4.690664291381835937, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100870, 25718, 571, 0, 0, 1, 1, 0, 0, 3850.0183, 6571.5786, 168.19226, 2.20652008056640625, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

-- Coldarra Spellbinder 
DELETE FROM `creature` WHERE `id` IN (25719);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122671, 25719, 571, 0, 0, 1, 1, 0, 1, 3820.597, 6679.235, 152.86505, 0.680678427219390869, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122672, 25719, 571, 0, 0, 1, 1, 0, 1, 3836.237, 6692.8613, 152.86505, 3.892084121704101562, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122673, 25719, 571, 0, 0, 1, 1, 0, 1, 3835.5317, 6677.673, 152.86505, 2.286381244659423828, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122674, 25719, 571, 0, 0, 1, 1, 0, 1, 3822.5425, 6694.84, 152.86505, 5.305800914764404296, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122675, 25719, 571, 0, 0, 1, 1, 0, 1, 3826.3528, 6615.8735, 162.87305, 3.609932661056518554, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122676, 25719, 571, 0, 0, 1, 1, 0, 1, 3789.8057, 6701.64, 150.98584, 3.84401702880859375, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122677, 25719, 571, 0, 0, 1, 1, 0, 1, 3751.8828, 6531.2563, 178.98116, 0.83150339126586914, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122678, 25719, 571, 0, 0, 1, 1, 0, 1, 3803.317, 6743.943, 150.45473, 3.379514455795288085, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122679, 25719, 571, 0, 0, 1, 1, 0, 1, 3783.0525, 6563.874, 171.4552, 1.894476652145385742, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122680, 25719, 571, 0, 0, 1, 1, 0, 1, 3782.3398, 6661.58, 151.57529, 6.056679248809814453, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122682, 25719, 571, 0, 0, 1, 1, 0, 1, 3806.3142, 6543.594, 172.99547, 0.536526143550872802, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122683, 25719, 571, 0, 0, 1, 1, 0, 1, 3784.428, 6509.242, 178.87587, 1.206540346145629882, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122684, 25719, 571, 0, 0, 1, 1, 0, 1, 3890.6963, 6726.5103, 151.2073, 6.283063411712646484, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122685, 25719, 571, 0, 0, 1, 1, 0, 1, 3894.684, 6658.401, 167.50955, 0.473483383655548095, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100865, 25719, 571, 0, 0, 1, 1, 0, 1, 3881.015, 6697.139, 151.4695, 0.683063805103302001, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100867, 25719, 571, 0, 0, 1, 1, 0, 1, 3850.5173, 6521.0615, 177.65175, 0.750826001167297363, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100869, 25719, 571, 0, 0, 1, 1, 0, 1, 3849.8481, 6573.0957, 167.9931, 1.221093654632568359, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

-- Fix Bad Entry: 25719 Coldarra Spellbinder SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25719) AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-122671,-122672,-122673,-122674) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-122671,0,0,0,0,0,100,0,0,0,3900,5800,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Frostbolt'''),
(-122671,0,1,0,0,0,100,0,1700,13500,172100,172100,0,11,50583,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Summon Frozen Spheres'''),
(-122671,0,2,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - Out of Combat - Cast ''Arcane Channeling'''),
(-122672,0,0,0,0,0,100,0,0,0,3900,5800,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Frostbolt'''),
(-122672,0,1,0,0,0,100,0,1700,13500,172100,172100,0,11,50583,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Summon Frozen Spheres'''),
(-122672,0,2,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - Out of Combat - Cast ''Arcane Channeling'''),
(-122673,0,0,0,0,0,100,0,0,0,3900,5800,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Frostbolt'''),
(-122673,0,1,0,0,0,100,0,1700,13500,172100,172100,0,11,50583,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Summon Frozen Spheres'''),
(-122673,0,2,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - Out of Combat - Cast ''Arcane Channeling'''),
(-122674,0,0,0,0,0,100,0,0,0,3900,5800,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Frostbolt'''),
(-122674,0,1,0,0,0,100,0,1700,13500,172100,172100,0,11,50583,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - In Combat - Cast ''Summon Frozen Spheres'''),
(-122674,0,2,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellbinder - Out of Combat - Cast ''Arcane Channeling''');

-- Clean up Coldarra Spellbinder to add new paths
DELETE FROM `creature_addon` WHERE `guid` IN (122671,122672,122673,122674,122675,122676,122677,122678,122679,122680,122682,122683,122684,122685,100865,100867,100869);
DELETE FROM `waypoint_data` WHERE `id` IN (1226710,1226720,1226730,1226740,1226750,1226760,1226770,1226780,1226790,1226800,1226820,1226830,1226840,1226850,1008650,1008670,1008690);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (SELECT `guid` FROM `creature` WHERE `id`=25719);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122675;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3821.605,6613.4717,162.29506,NULL,0,0,0,100,0),
(@PATH,2,3817.8389,6607.5723,162.76491,NULL,0,0,0,100,0),
(@PATH,3,3805.3313,6609.41,161.0254,NULL,0,0,0,100,0),
(@PATH,4,3793.5283,6614.155,159.35997,NULL,0,0,0,100,0),
(@PATH,5,3786.1658,6624.7095,156.22935,NULL,0,0,0,100,0),
(@PATH,6,3777.3286,6636.075,153.03854,NULL,0,0,0,100,0),
(@PATH,7,3761.4124,6649.2754,151.50812,NULL,0,0,0,100,0),
(@PATH,8,3777.3286,6636.075,153.03854,NULL,0,0,0,100,0),
(@PATH,9,3786.1658,6624.7095,156.22935,NULL,0,0,0,100,0),
(@PATH,10,3793.5283,6614.155,159.35997,NULL,0,0,0,100,0),
(@PATH,11,3805.3313,6609.41,161.0254,NULL,0,0,0,100,0),
(@PATH,12,3817.7566,6607.4443,162.8091,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122664,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122676;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3783.0166,6695.895,150.80238,NULL,0,0,0,100,0),
(@PATH,2,3772.382,6700.643,150.74503,NULL,0,0,0,100,0),
(@PATH,3,3760.1814,6711.295,151.93404,NULL,0,0,0,100,0),
(@PATH,4,3750.6533,6726.3,151.35957,NULL,0,0,0,100,0),
(@PATH,5,3744.605,6746.0625,151.95636,NULL,0,0,0,100,0),
(@PATH,6,3750.6533,6726.3,151.35957,NULL,0,0,0,100,0),
(@PATH,7,3760.1814,6711.295,151.93404,NULL,0,0,0,100,0),
(@PATH,8,3772.382,6700.643,150.74503,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122665,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122677;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3760.8455,6541.0903,176.66281,NULL,0,0,0,100,0),
(@PATH,2,3754.9446,6555.7456,175.24142,NULL,0,0,0,100,0),
(@PATH,3,3739.2432,6579.2754,173.202,NULL,0,0,0,100,0),
(@PATH,4,3729.562,6596.427,171.90732,NULL,0,0,0,100,0),
(@PATH,5,3719.5312,6619.014,170.85445,NULL,0,0,0,100,0),
(@PATH,6,3729.562,6596.427,171.90732,NULL,0,0,0,100,0),
(@PATH,7,3739.2432,6579.2754,173.202,NULL,0,0,0,100,0),
(@PATH,8,3754.9446,6555.7456,175.24142,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122660,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122678;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3798.0981,6742.6772,150.59825,NULL,0,0,0,100,0),
(@PATH,2,3811.1719,6750.1123,150.29903,NULL,0,0,0,100,0),
(@PATH,3,3826.7297,6753.6567,150.70418,NULL,0,0,0,100,0),
(@PATH,4,3838.7769,6746.0747,150.62924,NULL,0,0,0,100,0),
(@PATH,5,3848.177,6743.3345,150.61667,NULL,0,0,0,100,0),
(@PATH,6,3838.7769,6746.0747,150.62924,NULL,0,0,0,100,0),
(@PATH,7,3826.7297,6753.6567,150.70418,NULL,0,0,0,100,0),
(@PATH,8,3811.1719,6750.1123,150.29903,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122667,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122679;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3780.246,6572.221,170.30676,NULL,0,0,0,100,0),
(@PATH,2,3772.4775,6585.143,169.30359,NULL,0,0,0,100,0),
(@PATH,3,3759.273,6589.1235,170.99167,NULL,0,0,0,100,0),
(@PATH,4,3745.125,6605.8423,169.1738,NULL,0,0,0,100,0),
(@PATH,5,3727.845,6628.902,167.23409,NULL,0,0,0,100,0),
(@PATH,6,3745.125,6605.8423,169.1738,NULL,0,0,0,100,0),
(@PATH,7,3759.273,6589.1235,170.99167,NULL,0,0,0,100,0),
(@PATH,8,3772.4775,6585.143,169.30359,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122661,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122680;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3791.4854,6659.473,151.764,NULL,0,0,0,100,0),
(@PATH,2,3784.3342,6665.2134,151.33823,NULL,0,0,0,100,0),
(@PATH,3,3776,6673.0767,151.30238,NULL,0,0,0,100,0),
(@PATH,4,3776.0425,6686.368,150.75063,NULL,0,0,0,100,0),
(@PATH,5,3778.2979,6701.002,150.99503,NULL,0,0,0,100,0),
(@PATH,6,3776.0425,6686.368,150.75063,NULL,0,0,0,100,0),
(@PATH,7,3776,6673.0767,151.30238,NULL,0,0,0,100,0),
(@PATH,8,3784.3342,6665.2134,151.33823,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122668,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122682;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3817.918,6550.5127,171.41196,NULL,0,0,0,100,0),
(@PATH,2,3839.1528,6573.838,167.7162,NULL,0,0,0,100,0),
(@PATH,3,3856.668,6592.4385,165.85915,NULL,0,0,0,100,0),
(@PATH,4,3878.9563,6602.819,165.81654,NULL,0,0,0,100,0),
(@PATH,5,3856.668,6592.4385,165.85915,NULL,0,0,0,100,0),
(@PATH,6,3839.1528,6573.838,167.7162,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122662,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122683;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3786.05,6513.491,178.26642,NULL,0,0,0,100,0),
(@PATH,2,3785.958,6535.028,175.58186,NULL,0,0,0,100,0),
(@PATH,3,3802.312,6569.7188,168.85349,NULL,0,0,0,100,0),
(@PATH,4,3795.5012,6607.5024,161.04417,NULL,0,0,0,100,0),
(@PATH,5,3802.312,6569.7188,168.85349,NULL,0,0,0,100,0),
(@PATH,6,3785.958,6535.028,175.58186,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122663,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122684;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3895.2717,6726.508,151.01074,NULL,0,0,0,100,0),
(@PATH,2,3886.1675,6727.1978,151.18945,NULL,0,0,0,100,0),
(@PATH,3,3875.8408,6735.9263,150.96509,NULL,0,0,0,100,0),
(@PATH,4,3860.1545,6741.396,150.59909,NULL,0,0,0,100,0),
(@PATH,5,3862.7551,6753.569,150.34738,NULL,0,0,0,100,0),
(@PATH,6,3878.7058,6753.863,150.96509,NULL,0,0,0,100,0),
(@PATH,7,3862.7551,6753.569,150.34738,NULL,0,0,0,100,0),
(@PATH,8,3860.1545,6741.396,150.59909,NULL,0,0,0,100,0),
(@PATH,9,3875.8408,6735.9263,150.96509,NULL,0,0,0,100,0),
(@PATH,10,3886.1675,6727.1978,151.18945,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122669,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 122685;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3897.6194,6659.9067,167.76633,NULL,0,0,0,100,0),
(@PATH,2,3892.0447,6649.9893,166.04733,NULL,0,0,0,100,0),
(@PATH,3,3889.244,6634.988,166.81442,NULL,0,0,0,100,0),
(@PATH,4,3882.257,6623.3022,165.73842,NULL,0,0,0,100,0),
(@PATH,5,3876.513,6615.2905,165.04909,NULL,0,0,0,100,0),
(@PATH,6,3872.8394,6605.2915,165.1609,NULL,0,0,0,100,0),
(@PATH,7,3876.513,6615.2905,165.04909,NULL,0,0,0,100,0),
(@PATH,8,3882.257,6623.3022,165.73842,NULL,0,0,0,100,0),
(@PATH,9,3889.244,6634.988,166.81442,NULL,0,0,0,100,0),
(@PATH,10,3892.0447,6649.9893,166.04733,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,122670,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 100865;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3894.756,6701.676,151.4043,NULL,0,0,0,100,0),
(@PATH,2,3917.0793,6710.1875,152.80257,NULL,0,0,0,100,0),
(@PATH,3,3925.1907,6718.7036,153.90083,NULL,0,0,0,100,0),
(@PATH,4,3929.6848,6747.762,151.20604,NULL,0,0,0,100,0),
(@PATH,5,3908.3745,6756.9634,150.58104,NULL,0,0,0,100,0),
(@PATH,6,3893.1294,6770.4966,150.60725,NULL,0,0,0,100,0),
(@PATH,7,3880.4775,6782.5366,150.60725,NULL,0,0,0,100,0),
(@PATH,8,3854.191,6782.814,150.8109,NULL,0,0,0,100,0),
(@PATH,9,3880.4775,6782.5366,150.60725,NULL,0,0,0,100,0),
(@PATH,10,3893.1294,6770.4966,150.60725,NULL,0,0,0,100,0),
(@PATH,11,3908.3745,6756.9634,150.58104,NULL,0,0,0,100,0),
(@PATH,12,3929.6848,6747.762,151.20604,NULL,0,0,0,100,0),
(@PATH,13,3925.1907,6718.7036,153.90083,NULL,0,0,0,100,0),
(@PATH,14,3917.0793,6710.1875,152.80257,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,100866,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 100867;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3858.134,6528.1675,176.77855,NULL,0,0,0,100,0),
(@PATH,2,3875.0535,6538.5044,175.69266,NULL,0,0,0,100,0),
(@PATH,3,3882.1646,6558.691,172.25919,NULL,0,0,0,100,0),
(@PATH,4,3880.04,6583.5938,167.84169,NULL,0,0,0,100,0),
(@PATH,5,3882.1646,6558.691,172.25919,NULL,0,0,0,100,0),
(@PATH,6,3875.0535,6538.5044,175.69266,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,100868,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Pathing for Coldarra Spellbinder Entry: 25719
SET @NPC := 100869;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3852.9636,6581.6484,167.02895,NULL,0,0,0,100,0),
(@PATH,2,3866.718,6601.883,165.14162,NULL,0,0,0,100,0),
(@PATH,3,3880.8838,6629.427,165.57362,NULL,0,0,0,100,0),
(@PATH,4,3897.0703,6648.4697,166.93942,NULL,0,0,0,100,0),
(@PATH,5,3880.8838,6629.427,165.57362,NULL,0,0,0,100,0),
(@PATH,6,3866.718,6601.883,165.14162,NULL,0,0,0,100,0);
-- Formation
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,100870,4,0,515,0,0),
(@NPC,@NPC,0,0,2,0,0);

-- Coldarra Spellweaver
DELETE FROM `creature` WHERE `id` IN (25722);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122718, 25722, 571, 0, 0, 1, 1, 0, 1, 3808.5322, 6664.88, 150.62315, 0.820304751396179199, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122719, 25722, 571, 0, 0, 1, 1, 0, 1, 3849.53, 6664.405, 150.62314, 2.356194496154785156, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122720, 25722, 571, 0, 0, 1, 1, 0, 1, 3848.2744, 6707.2354, 150.81804, 3.96189737319946289, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122721, 25722, 571, 0, 0, 1, 1, 0, 1, 3808.7517, 6706.5757, 150.77339, 5.462880611419677734, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122722, 25722, 571, 0, 0, 1, 1, 0, 1, 3786.5234, 6559.35, 171.86629, 4.019807338714599609, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122723, 25722, 571, 0, 0, 1, 1, 0, 1, 3980.943, 6749.427, 156.27057, 4.433136463165283203, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122724, 25722, 571, 0, 0, 1, 1, 0, 1, 3913.8894, 6747.3813, 150.8694, 3.577924966812133789, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122725, 25722, 571, 0, 0, 1, 1, 0, 1, 3987.8186, 6814.7114, 159.98828, 1.099557399749755859, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122726, 25722, 571, 0, 0, 1, 1, 0, 1, 4050.9543, 6915.6704, 164.65192, 4.363323211669921875, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122727, 25722, 571, 0, 0, 1, 1, 0, 1, 4129.433, 6844.2646, 174.9875, 4.537856101989746093, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122737, 25722, 571, 0, 0, 1, 1, 0, 1, 4155.981, 7111.319, 171.79959, 2.076941728591918945, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122738, 25722, 571, 0, 0, 1, 1, 0, 1, 4082.9175, 7180.3735, 175.21475, 2.251474618911743164, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122739, 25722, 571, 0, 0, 1, 1, 0, 1, 4077.5894, 7055.3853, 166.26929, 4.590215682983398437, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122740, 25722, 571, 0, 0, 1, 1, 0, 1, 3883.78, 7184.1494, 167.35896, 5.445427417755126953, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122741, 25722, 571, 0, 0, 1, 1, 0, 1, 3912.869, 7341.278, 182.68802, 6.0737457275390625, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122742, 25722, 571, 0, 0, 1, 1, 0, 1, 3718.1824, 7151.8545, 160.52219, 3.438298702239990234, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122743, 25722, 571, 0, 0, 1, 1, 0, 1, 3706.058, 6760.491, 160.89233, 2.0245819091796875, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122744, 25722, 571, 0, 0, 1, 1, 0, 1, 3775.1182, 6812.512, 150.58452, 0.079252004623413085, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122745, 25722, 571, 0, 0, 1, 1, 0, 1, 3484.8, 7042.509, 205.38004, 1.93731546401977539, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122746, 25722, 571, 0, 0, 1, 1, 0, 1, 3584.2449, 7083.9897, 209.87935, 5.862161636352539062, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122747, 25722, 571, 0, 0, 1, 1, 0, 1, 3476.3396, 7186.489, 238.41824, 0.541052043437957763, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122748, 25722, 571, 0, 0, 1, 1, 0, 1, 3551.0378, 7251.9365, 240.30908, 0.4911060631275177, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122749, 25722, 571, 0, 0, 1, 1, 0, 1, 3635.675, 7247.3423, 219.80252, 0.296705961227416992, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122750, 25722, 571, 0, 0, 1, 1, 0, 1, 3643.658, 6852.053, 161.0335, 0.130744576454162597, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122751, 25722, 571, 0, 0, 1, 1, 0, 1, 3790.8745, 7338.0444, 196.90193, 1.623156189918518066, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122752, 25722, 571, 0, 0, 1, 1, 0, 1, 3672.5764, 7349.283, 233.8876, 6.2657318115234375, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122753, 25722, 571, 0, 0, 1, 1, 0, 1, 4013.7344, 6678.8345, 174.73053, 0.523598790168762207, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122754, 25722, 571, 0, 0, 1, 1, 0, 1, 4013.852, 6578.079, 183.8501, 5.044001579284667968, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122755, 25722, 571, 0, 0, 1, 1, 0, 1, 3851.5374, 7278.5825, 176.70007, 5.009094715118408203, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122756, 25722, 571, 0, 0, 1, 1, 0, 1, 3695.7043, 6584.9575, 181.99446, 5.113814830780029296, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature` SET `wander_distance`=7, `MovementType`=1 WHERE `id`=25722;

-- Fix Bad Entry: 25722 Coldarra Spellweaver SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25722) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-122718,-122719,-122720,-122721) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-122718,0,0,0,0,0,100,0,0,0,5250,5750,0,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - In Combat - Cast ''Arcane Missiles'''),
(-122718,0,1,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - Out of Combat - Cast ''Arcane Channeling'''),
(-122719,0,0,0,0,0,100,0,0,0,5250,5750,0,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - In Combat - Cast ''Arcane Missiles'''),
(-122719,0,1,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - Out of Combat - Cast ''Arcane Channeling'''),
(-122720,0,0,0,0,0,100,0,0,0,5250,5750,0,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - In Combat - Cast ''Arcane Missiles'''),
(-122720,0,1,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - Out of Combat - Cast ''Arcane Channeling'''),
(-122721,0,0,0,0,0,100,0,0,0,5250,5750,0,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - In Combat - Cast ''Arcane Missiles'''),
(-122721,0,1,0,1,0,100,0,100,100,45000,45000,0,11,39550,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Spellweaver - Out of Combat - Cast ''Arcane Channeling''');

-- Coldarra Scalesworn
DELETE FROM `creature` WHERE `id` IN (25717);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122648, 25717, 571, 0, 0, 1, 1, 0, 1, 4131.8623, 6941.9077, 167.17569, 2.780764579772949218, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122649, 25717, 571, 0, 0, 1, 1, 0, 1, 4166.3486, 7017.9785, 166.17545, 1.398103713989257812, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122650, 25717, 571, 0, 0, 1, 1, 0, 1, 4095.1367, 6954.7886, 163.3398, 2.600050926208496093, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122651, 25717, 571, 0, 0, 1, 1, 0, 1, 4156.517, 6937.306, 169.67123, 1.56685042381286621, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122652, 25717, 571, 0, 0, 1, 1, 0, 1, 4052.6267, 7023.4897, 166.05466, 1.273183345794677734, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122653, 25717, 571, 0, 0, 1, 1, 0, 1, 4178.446, 6982.742, 167.07567, 4.628220558166503906, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122654, 25717, 571, 0, 0, 1, 1, 0, 1, 4085.5503, 6934.8394, 165.18352, 4.188942909240722656, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122655, 25717, 571, 0, 0, 1, 1, 0, 1, 4131.851, 7045.613, 164.98048, 2.580271005630493164, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122656, 25717, 571, 0, 0, 1, 1, 0, 1, 4121.1094, 7080.6147, 169.36514, 5.253579139709472656, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122657, 25717, 571, 0, 0, 1, 1, 0, 0, 4061.3901, 6990.2812, 164.23734, 3.464162111282348632, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature` SET `wander_distance`=7, `MovementType`=1 WHERE `id`=25717;

-- Pathing for Coldarra Scalesworn Entry: 25717
SET @NPC := 122650;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4090.2769,6957.712,163.3145,NULL,0,0,0,100,0),
(@PATH,2,4103.7256,6946.983,163.13571,NULL,0,0,0,100,0),
(@PATH,3,4118.9824,6946.5073,163.95773,NULL,0,0,0,100,0),
(@PATH,4,4129.3066,6949.9966,164.4487,NULL,0,0,0,100,0),
(@PATH,5,4142.75,6954.478,165.01561,NULL,0,0,0,100,0),
(@PATH,6,4129.3066,6949.9966,164.4487,NULL,0,0,0,100,0),
(@PATH,7,4118.9824,6946.5073,163.95773,NULL,0,0,0,100,0),
(@PATH,8,4103.7256,6946.983,163.13571,NULL,0,0,0,100,0);

-- Pathing for Coldarra Scalesworn Entry: 25717
SET @NPC := 122652;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4061.673,7048.9272,167.58414,NULL,0,0,0,100,0),
(@PATH,2,4052.1155,7022.13,165.90814,NULL,0,0,0,100,0),
(@PATH,3,4061.673,7048.9272,167.58414,NULL,0,0,0,100,0),
(@PATH,4,4072.612,7060.5093,166.31483,NULL,0,0,0,100,0),
(@PATH,5,4086.8086,7066.4663,166.65675,NULL,0,0,0,100,0),
(@PATH,6,4100.966,7060.313,166.45924,NULL,0,0,0,100,0),
(@PATH,7,4086.8086,7066.4663,166.65675,NULL,0,0,0,100,0),
(@PATH,8,4072.612,7060.5093,166.31483,NULL,0,0,0,100,0);

-- Pathing for Coldarra Scalesworn Entry: 25717
SET @NPC := 122653;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4183.2124,6979.9243,167.78891,NULL,0,0,0,100,0),
(@PATH,2,4181.6216,6958.6025,169.8037,NULL,0,0,0,100,0),
(@PATH,3,4169.9556,6937.5195,171.119,NULL,0,0,0,100,0),
(@PATH,4,4181.58,6958.5195,169.79149,NULL,0,0,0,100,0),
(@PATH,5,4183.2124,6979.9243,167.78891,NULL,0,0,0,100,0),
(@PATH,6,4178.3457,7003.7075,167.01515,NULL,0,0,0,100,0),
(@PATH,7,4173.7397,7009.208,166.4916,NULL,0,0,0,100,0),
(@PATH,8,4178.3457,7003.7075,167.01515,NULL,0,0,0,100,0);

-- Pathing for Coldarra Scalesworn Entry: 25717
SET @NPC := 122655;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4128.7954,7050.8335,165.5718,NULL,0,0,0,100,0),
(@PATH,2,4119.0596,7053.6504,165.7848,NULL,0,0,0,100,0),
(@PATH,3,4128.7954,7050.8335,165.5718,NULL,0,0,0,100,0),
(@PATH,4,4141.301,7046.572,165.73857,NULL,0,0,0,100,0),
(@PATH,5,4149.3345,7039.96,165.81999,NULL,0,0,0,100,0),
(@PATH,6,4158.797,7025.598,165.7506,NULL,0,0,0,100,0),
(@PATH,7,4165.7056,7013.996,165.68736,NULL,0,0,0,100,0),
(@PATH,8,4158.797,7025.598,165.7506,NULL,0,0,0,100,0),
(@PATH,9,4149.3345,7039.96,165.81999,NULL,0,0,0,100,0),
(@PATH,10,4141.301,7046.572,165.73857,NULL,0,0,0,100,0);

-- Coldarra Wyrmkin
DELETE FROM `creature` WHERE `id` IN (25728);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122791, 25728, 571, 0, 0, 1, 1, 0, 1, 3789.8064, 6619.109, 157.86075, 2.442338466644287109, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122793, 25728, 571, 0, 0, 1, 1, 0, 1, 3951.994, 6716.839, 154.70415, 4.764749050140380859, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122795, 25728, 571, 0, 0, 1, 1, 0, 1, 3957.8157, 6814.3105, 156.14879, 4.118977069854736328, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122796, 25728, 571, 0, 0, 1, 1, 0, 1, 4009.6836, 6778.0356, 162.29565, 2.39110112190246582, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122797, 25728, 571, 0, 0, 1, 1, 0, 1, 3948.9075, 6781.2075, 153.77579, 3.926990747451782226, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122798, 25728, 571, 0, 0, 1, 1, 0, 1, 4019.716, 6927.5356, 166.24864, 5.305800914764404296, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122800, 25728, 571, 0, 0, 1, 1, 0, 1, 4028.99, 6890.0703, 165.12692, 3.159045934677124023, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122801, 25728, 571, 0, 0, 1, 1, 0, 1, 4052.9402, 6853.7085, 165.63936, 0.366519153118133544, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122805, 25728, 571, 0, 0, 1, 1, 0, 1, 4079.8877, 6887.2026, 167.45398, 1.640609502792358398, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122806, 25728, 571, 0, 0, 1, 1, 0, 1, 4124.304, 7091.466, 170.52448, 1.762782573699951171, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122807, 25728, 571, 0, 0, 1, 1, 0, 1, 4018.941, 7184.4287, 174.093, 3.490658521652221679, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122808, 25728, 571, 0, 0, 1, 1, 0, 1, 3848.9392, 7219.7485, 167.56384, 3.717551231384277343, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122809, 25728, 571, 0, 0, 1, 1, 0, 1, 3885.9006, 7248.7036, 176.49944, 2.7126922607421875, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122810, 25728, 571, 0, 0, 1, 1, 0, 1, 3806.1494, 7111.44, 166.6075, 6.102298259735107421, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122811, 25728, 571, 0, 0, 1, 1, 0, 1, 3715.6736, 6847.135, 156.84787, 6.126105785369873046, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122812, 25728, 571, 0, 0, 1, 1, 0, 1, 3683.4348, 6820.7197, 161.10338, 1.762782573699951171, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122813, 25728, 571, 0, 0, 1, 1, 0, 1, 3747.862, 6890.059, 153.84628, 2.757620096206665039, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122814, 25728, 571, 0, 0, 1, 1, 0, 1, 3852.097, 7149.571, 166.4159, 0.383972436189651489, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122815, 25728, 571, 0, 0, 1, 1, 0, 1, 3648.4211, 7018.436, 166.72147, 0.177451357245445251, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122820, 25728, 571, 0, 0, 1, 1, 0, 1, 3602.4346, 7151.512, 221.83325, 5.201081275939941406, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122821, 25728, 571, 0, 0, 1, 1, 0, 1, 3559.6223, 7053.407, 204.3672, 1.064650893211364746, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122822, 25728, 571, 0, 0, 1, 1, 0, 1, 3515.9084, 7074.4404, 209.15433, 0.03490658476948738, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122823, 25728, 571, 0, 0, 1, 1, 0, 1, 3530.8098, 7026.1274, 200.22536, 1.378810048103332519, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122824, 25728, 571, 0, 0, 1, 1, 0, 1, 3561.673, 7193.4707, 225.49213, 6.211803913116455078, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122825, 25728, 571, 0, 0, 1, 1, 0, 1, 3513.884, 7152.367, 217.98442, 5.009094715118408203, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122827, 25728, 571, 0, 0, 1, 1, 0, 1, 3488.7224, 7108.9414, 215.40749, 4.06836700439453125, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122831, 25728, 571, 0, 0, 1, 1, 0, 1, 3614.606, 7195.4346, 220.0825, 0, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122832, 25728, 571, 0, 0, 1, 1, 0, 1, 3579.7148, 7282.1665, 235.2417, 5.305800914764404296, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122837, 25728, 571, 0, 0, 1, 1, 0, 1, 3609.346, 7315.7876, 236.51256, 0.994646310806274414, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122839, 25728, 571, 0, 0, 1, 1, 0, 1, 3818.6506, 7251.2153, 167.88553, 0.331612557172775268, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122841, 25728, 571, 0, 0, 1, 1, 0, 1, 3882.5095, 7313.863, 181.1715, 2.617993831634521484, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122842, 25728, 571, 0, 0, 1, 1, 0, 1, 3843.1763, 7355.3115, 188.13466, 4.345870018005371093, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122843, 25728, 571, 0, 0, 1, 1, 0, 1, 3752.2805, 7295.777, 206.8527, 4.78220224380493164, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122844, 25728, 571, 0, 0, 1, 1, 0, 1, 3699.2322, 7279.154, 211.62354, 0.015896912664175033, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122845, 25728, 571, 0, 0, 1, 1, 0, 1, 3848.6824, 6754.672, 147.94876, 6.028516769409179687, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122846, 25728, 571, 0, 0, 1, 1, 0, 1, 3846.698, 6548.824, 171.8793, 0.78539818525314331, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122847, 25728, 571, 0, 0, 1, 1, 0, 1, 3979.5222, 6616.7866, 175.28133, 3.376890897750854492, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122848, 25728, 571, 0, 0, 1, 1, 0, 1, 4118.069, 6917.1646, 168.78006, 5.519952297210693359, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature` SET `wander_distance`=7, `MovementType`=1 WHERE `id`=25728;

-- Fix Bad Entry: 25728 Coldarra Wyrmkin SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25728) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25728,0,0,0,0,0,100,0,5000,12000,22000,26000,0,11,50416,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Wyrmkin - In Combat - Cast ''Frostbite Weapon'''),
(25728,0,1,0,23,0,100,0,50416,1,8000,8000,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Wyrmkin - On Aura apply - Change Equipment'),
(25728,0,2,0,23,0,100,0,50416,0,8000,8000,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Coldarra Wyrmkin - On Aura remove - Change Equipment');

-- Blue Drakonid Supplicant
DELETE FROM `creature` WHERE `id` IN (25713);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(122609, 25713, 571, 0, 0, 1, 1, 0, 1, 3755.0676, 7150.5933, 159.87473, 4.921828269958496093, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122610, 25713, 571, 0, 0, 1, 1, 0, 1, 3790.2239, 7174.326, 159.87315, 0.01745329238474369, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122611, 25713, 571, 0, 0, 1, 1, 0, 1, 3823.0647, 7163.114, 162.39896, 4.405760765075683593, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122641, 25713, 571, 0, 0, 1, 1, 0, 1, 3761.0378, 7207.8457, 159.98114, 1.623156189918518066, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122642, 25713, 571, 0, 0, 1, 1, 0, 1, 3733.8057, 7181.6953, 160.00827, 3.019419670104980468, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(122643, 25713, 571, 0, 0, 1, 1, 0, 1, 3760.3489, 7120.858, 168.2357, 3.012910366058349609, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100871, 25713, 571, 0, 0, 1, 1, 0, 1, 3717.8276, 7183.395, 159.96674, 0.907571196556091308, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0),
(100872, 25713, 571, 0, 0, 1, 1, 0, 1, 3793.808, 7224.6333, 162.24602, 2.664915323257446289, 300, 0, 0, 1, 0, 0, 0, 0, 0, '', 0);

-- Pathing for  Entry: 25713
SET @NPC := 122643;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3732.1301,7121.827,161.67773,NULL,1000,0,0,100,0),
(@PATH,2,3746.2551,7119.65,162.6052,NULL,0,0,0,100,0),
(@PATH,3,3754.9658,7117.9263,167.27829,NULL,0,0,0,100,0),
(@PATH,4,3770.4211,7117.312,164.12392,NULL,0,0,0,100,0),
(@PATH,5,3777.769,7118.2905,165.57472,NULL,0,0,0,100,0),
(@PATH,6,3786.3035,7120.761,165.64076,NULL,1000,0,0,100,0),
(@PATH,7,3777.769,7118.2905,165.57472,NULL,0,0,0,100,0),
(@PATH,8,3770.4211,7117.312,164.12392,NULL,0,0,0,100,0),
(@PATH,9,3754.9658,7117.9263,167.27829,NULL,0,0,0,100,0),
(@PATH,10,3746.2551,7119.65,162.6052,NULL,0,0,0,100,0);

-- Pathing for  Entry: 25713
SET @NPC := 100871;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3712.202,7195.61,160.24905,NULL,0,0,0,100,0),
(@PATH,2,3711.4253,7179.9194,160.00797,NULL,0,0,0,100,0),
(@PATH,3,3712.2683,7167.858,160.17752,NULL,0,0,0,100,0),
(@PATH,4,3715.3035,7158.94,160.42256,NULL,0,0,0,100,0),
(@PATH,5,3723.346,7146.8525,160.68892,NULL,0,0,0,100,0),
(@PATH,6,3715.3035,7158.94,160.42256,NULL,0,0,0,100,0),
(@PATH,7,3712.2683,7167.858,160.17752,NULL,0,0,0,100,0),
(@PATH,8,3711.4253,7179.9194,160.00797,NULL,0,0,0,100,0);


-- Pathing for  Entry: 25713
SET @NPC := 100872;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3776.136,7239.694,159.54234,NULL,0,0,0,100,0),
(@PATH,2,3760.0955,7242.0703,158.95256,NULL,0,0,0,100,0),
(@PATH,3,3776.136,7239.694,159.54234,NULL,0,0,0,100,0),
(@PATH,4,3795.7317,7232.1367,162.79013,NULL,0,0,0,100,0),
(@PATH,5,3803.4358,7223.729,163.4432,NULL,0,0,0,100,0),
(@PATH,6,3810.2483,7205.372,161.3901,NULL,0,0,0,100,0),
(@PATH,7,3803.4358,7223.729,163.4432,NULL,0,0,0,100,0),
(@PATH,8,3795.7317,7232.1367,162.79013,NULL,0,0,0,100,0);

-- Pathing for  Entry: 25713
SET @NPC := 122611;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3821.2803,7144.1484,164.29907,NULL,0,0,0,100,0),
(@PATH,2,3819.164,7129.4565,165.85046,NULL,0,0,0,100,0),
(@PATH,3,3809.9531,7121.6265,166.16516,NULL,0,0,0,100,0),
(@PATH,4,3819.164,7129.4565,165.85046,NULL,0,0,0,100,0),
(@PATH,5,3821.2847,7144.03,164.3197,NULL,0,0,0,100,0),
(@PATH,6,3820.4648,7156.006,162.79907,NULL,0,0,0,100,0),
(@PATH,7,3815.0933,7180.0327,161.03983,NULL,0,0,0,100,0),
(@PATH,8,3820.4602,7156.1245,162.76929,NULL,0,0,0,100,0);
