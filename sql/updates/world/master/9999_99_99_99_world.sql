SET @PATHID := 105116100;
SET @CGUID := 1051161;

DELETE FROM `waypoint_path` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID, 0, 0, 2.8608252772677196, 'Sharpbeak Hawk - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID, 0, -135.85672, -2624.6638, 60.741047, NULL, 0),
(@PATHID, 1, -143.37067, -2626.1196, 60.741047, NULL, 0),
(@PATHID, 2, -149.7132, -2621.8357, 60.741047, NULL, 0),
(@PATHID, 3, -151.16895, -2614.3218, 60.741047, NULL, 0),
(@PATHID, 4, -146.88515, -2607.9792, 60.741047, NULL, 0),
(@PATHID, 5, -139.3712, -2606.5234, 60.741047, NULL, 0),
(@PATHID, 6, -133.02867, -2610.8074, 60.741047, NULL, 0),
(@PATHID, 7, -131.57292, -2618.3213, 60.741047, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`) VALUES
(@CGUID, @PATHID);

UPDATE `creature` SET `position_x`=-131.55737, `position_y`=-2618.2983, `position_z`=60.741047, `orientation`=4.11835, `MovementType`=3 WHERE `guid`=@CGUID;

-- Core Hound
SET @CGUID := 387385;
SET @PATHID := @CGUID * 100;

DELETE FROM `waypoint_path` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID, 0, 0, 2.820225494707777, 'Core Hound - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID, 0, 4558.1597, -2488.9983, 1130.482, NULL, 0),
(@PATHID, 1, 4569.21, -2482.0017, 1129.8171, NULL, 0),
(@PATHID, 2, 4572.83, -2470.4358, 1130.5739, NULL, 0),
(@PATHID, 3, 4568.532, -2460.158, 1133.3096, NULL, 0),
(@PATHID, 4, 4555.538, -2457.4446, 1133.1881, NULL, 0),
(@PATHID, 5, 4538.316, -2460.4775, 1135.0574, NULL, 0),
(@PATHID, 6, 4532.652, -2474.4844, 1134.0675, NULL, 0),
(@PATHID, 7, 4544.508, -2486.6807, 1131.982, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`) VALUES
(@CGUID, @PATHID);

UPDATE `creature` SET `position_x`=4549.402, `position_y`=-2489.0364, `position_z`=1131.2559, `orientation`=0.00434, `MovementType`=3 WHERE `guid`=@CGUID;

-- Glittergill Grouper
SET @CGUID := 341988;
SET @PATHID := @CGUID * 100;

DELETE FROM `waypoint_path` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID, 0, 0, 2.7494579921520845, 'Glittergill Grouper - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID, 0, -5016.3267, 3544.8872, -119.37827, NULL, 0),
(@PATHID, 1, -5016.5645, 3536.2517, -123.90611, NULL, 0),
(@PATHID, 2, -5008.0645, 3520.6423, -121.90605, NULL, 0),
(@PATHID, 3, -4995.712, 3509.211, -121.07278, NULL, 0),
(@PATHID, 4, -4983.097, 3514.0051, -119.37827, NULL, 0),
(@PATHID, 5, -4971.8315, 3527.8254, -119.37827, NULL, 0),
(@PATHID, 6, -4979.0347, 3554.2354, -119.37827, NULL, 0),
(@PATHID, 7, -4999.866, 3559.216, -119.37827, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`) VALUES
(@CGUID, @PATHID);

UPDATE `creature` SET `position_x`=-5016.434, `position_y`=3537.3472, `position_z`=-121.40834, `orientation`=4.59393, `MovementType`=3 WHERE `guid`=@CGUID;

-- Wisp
SET @CGUID := 313293;
SET @PATHID := @CGUID * 100;

DELETE FROM `waypoint_path` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID, 0, 0, 1.3725631103740557*6, 'Wisp - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID, 0, 10342.868, 814.7153, 1332.4296, NULL, 0),
(@PATHID, 1, 10344.305, 808.2639, 1331.617, NULL, 0),
(@PATHID, 2, 10352.113, 809.58856, 1331.9805, NULL, 0),
(@PATHID, 3, 10351.073, 818.63367, 1327.3499, NULL, 0),
(@PATHID, 4, 10345.139, 820.0781, 1327.3499, NULL, 0),
(@PATHID, 5, 10342.410, 814.58856, 1327.3499, NULL, 0),
(@PATHID, 6, 10347.016, 810.86456, 1330.6635, NULL, 0),
(@PATHID, 7, 10352.333, 813.91144, 1331.3212, NULL, 0),
(@PATHID, 8, 10349.232, 819.77606, 1332.3054, NULL, 0),
(@PATHID, 9, 10343.367, 818.8264, 1333.3867, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`) VALUES
(@CGUID, @PATHID);

UPDATE `creature` SET `position_x`=10342.415, `position_y`=814.56323, `position_z`=1327.359, `orientation`=4.92827, `MovementType`=3 WHERE `guid`=@CGUID;

-- Blazewing
SET @CGUID := 386006;
SET @PATHID := @CGUID * 100;

DELETE FROM `waypoint_path` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATHID, 0, 0, NULL, 'Blazewing - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATHID;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATHID, 0, 4508.3613, -2872.606, 1152.7754, NULL, 0),
(@PATHID, 1, 4531.6816, -2916.1997, 1090.5006, NULL, 0),
(@PATHID, 2, 4577.663, -2946.3125, 1082.5386, NULL, 0),
(@PATHID, 3, 4649.4243, -2979.0852, 1084.9604, NULL, 0),
(@PATHID, 4, 4703.94, -3045.4688, 1087.3351, NULL, 0),
(@PATHID, 5, 4717.001, -3095.8977, 1082.3636, NULL, 0),
(@PATHID, 6, 4698.288, -3180.3923, 1067.9191, NULL, 0),
(@PATHID, 7, 4692.2915, -3255.2048, 1064.2457, NULL, 0),
(@PATHID, 8, 4678.7485, -3340.7136, 1051.6335, NULL, 0),
(@PATHID, 9, 4624.0225, -3401.712, 1040.5078, NULL, 0),
(@PATHID, 10, 4553.8726, -3471.5278, 1024.8987, NULL, 0),
(@PATHID, 11, 4534.2734, -3529.2083, 1006.541, NULL, 0),
(@PATHID, 12, 4536.8926, -3588.408, 998.77594, NULL, 0),
(@PATHID, 13, 4592.4253, -3628.8281, 981.64825, NULL, 0),
(@PATHID, 14, 4622.4946, -3659.1182, 973.34125, NULL, 0),
(@PATHID, 15, 4646.809, -3719.3923, 969.6917, NULL, 0),
(@PATHID, 16, 4642.46, -3804.0696, 959.3814, NULL, 0),
(@PATHID, 17, 4615.2085, -3855.8594, 975.701, NULL, 0),
(@PATHID, 18, 4617.1353, -3875.915, 991.73004, NULL, 0),
(@PATHID, 19, 4665.2446, -3883.019, 1009.7701, NULL, 0),
(@PATHID, 20, 4695.2466, -3725.7239, 1006.8547, NULL, 0),
(@PATHID, 21, 4689.4316, -3681.2344, 998.38293, NULL, 0),
(@PATHID, 22, 4602.0366, -3626.1145, 981.7348, NULL, 0),
(@PATHID, 23, 4537.4185, -3526.9028, 1032.3766, NULL, 0),
(@PATHID, 24, 4557.408, -3432.212, 1028.0961, NULL, 0),
(@PATHID, 25, 4570.808, -3366.2795, 1021.5486, NULL, 0),
(@PATHID, 26, 4576.5938, -3312.507, 1021.5486, NULL, 0),
(@PATHID, 27, 4562.2925, -3207.2605, 1052.6993, NULL, 0),
(@PATHID, 28, 4611.52, -3085.6128, 1052.6993, NULL, 0),
(@PATHID, 29, 4579.8125, -3048.698, 1108.1998, NULL, 0),
(@PATHID, 30, 4515.78, -2911.4253, 1082.4323, NULL, 0),
(@PATHID, 31, 4479.0737, -2827.9932, 1091.5817, NULL, 0),
(@PATHID, 32, 4453.007, -2765.8525, 1105.681, NULL, 0),
(@PATHID, 33, 4509.798, -2724.8176, 1140.3057, NULL, 0),
(@PATHID, 34, 4557.8735, -2744.1199, 1198.1444, NULL, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`) VALUES
(@CGUID, @PATHID);

UPDATE `creature` SET `position_x`=4467.1147, `position_y`=-2747.5183, `position_z`=1115.3634, `orientation`=0.70506334, `MovementType`=3 WHERE `guid`=@CGUID;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1`|0x20000000 WHERE `entry`=50057;
