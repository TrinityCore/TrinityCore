-- -------------------------------------------
-- DEADMINES
-- -------------------------------------------
-- DB/Creature: Deadmines Pathing
-- Todesminen - Rufer der Defias - Vorarbeiter der Defias - Zuchtmeister der Defias - Hexer der Defias - Wellenformer der Defias 
SET @NPC := 79139;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -58.1086, -394.012, 54.3026, 0),
(@PATH, 2, -55.9432, -400.184, 54.5487, 0),
(@PATH, 3, -67.441, -401.846, 54.3231, 0),
(@PATH, 4, -65.5066, -395.733, 54.4282, 0),
(@PATH, 5, -59.4698, -391.136, 53.7281, 0),
(@PATH, 6, -57.744, -386.926, 53.9151, 0),
(@PATH, 7, -57.6061, -381.321, 54.0338, 0),
(@PATH, 8, -68.0747, -382.217, 53.8005, 0),
(@PATH, 9, -75.5928, -378.18, 55.1468, 0),
(@PATH, 10, -87.6686, -376.04, 57.5502, 0),
(@PATH, 11, -97.0305, -377.378, 58.0518, 0),
(@PATH, 12, -103.849, -380.893, 57.4528, 0),
(@PATH, 13, -94.3324, -377.236, 57.7877, 0),
(@PATH, 14, -82.0819, -376.835, 56.2085, 0),
(@PATH, 15, -68.3509, -374.365, 55.0867, 0),
(@PATH, 16, -60.5492, -376.377, 54.3032, 0),
(@PATH, 17, -54.3384, -379.355, 54.2581, 0),
(@PATH, 18, -58.7368, -385.684, 53.8661, 0),
(@PATH, 19, -57.8513, -390.019, 53.7836, 0);

SET @NPC := 79144;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -49.1406, -380.152, 54.8732, 0),
(@PATH, 2, -44.0293, -383.437, 55.5099, 0),
(@PATH, 3, -48.0472, -391.257, 55.8773, 0),
(@PATH, 4, -52.4945, -401.038, 55.5619, 0),
(@PATH, 5, -59.1642, -403.186, 53.9912, 0),
(@PATH, 6, -69.0763, -401.558, 54.7464, 0),
(@PATH, 7, -68.6572, -397.85, 55.1056, 0),
(@PATH, 8, -58.4723, -392.667, 54.1193, 0),
(@PATH, 9, -53.6889, -382.146, 54.6699, 0),
(@PATH, 10, -49.8211, -373.639, 55.291, 0),
(@PATH, 11, -57.1299, -367.638, 55.3325, 0),
(@PATH, 12, -62.892, -358.569, 54.3333, 0),
(@PATH, 13, -62.7853, -349.7, 55.955, 0),
(@PATH, 14, -63.644, -358.635, 54.3321, 0),
(@PATH, 15, -63.6918, -366.936, 55.0531, 0),
(@PATH, 16, -68.797, -369.171, 55.6588, 0),
(@PATH, 17, -75.1762, -373.704, 55.0443, 0),
(@PATH, 18, -76.815, -378.574, 55.231, 0),
(@PATH, 19, -67.4685, -383.845, 53.6905, 0),
(@PATH, 20, -60.7481, -384.712, 53.679, 0),
(@PATH, 21, -53.467, -377.178, 54.2938, 0);

SET @NPC := 79152;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -108.408, -401.056, 59.7252, 0),
(@PATH, 2, -118.798, -408.026, 59.1646, 0),
(@PATH, 3, -120.495, -414.875, 58.2067, 0),
(@PATH, 4, -115.331, -424.561, 55.383, 0),
(@PATH, 5, -107.488, -431.728, 55.1959, 0),
(@PATH, 6, -114.273, -441.777, 54.9943, 0),
(@PATH, 7, -119.865, -438.626, 54.718, 0),
(@PATH, 8, -116.703, -429.971, 54.9343, 0),
(@PATH, 9, -118.322, -422.801, 55.9285, 0),
(@PATH, 10, -124.19, -418.18, 57.6147, 0),
(@PATH, 11, -131.87, -410.675, 57.9201, 0),
(@PATH, 12, -125.211, -405.184, 58.613, 0),
(@PATH, 13, -119.058, -408.537, 59.0034, 0);

SET @NPC := 79188;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -106.372, -395.356, 57.7169, 0),
(@PATH, 2, -115.118, -396.449, 56.9909, 0),
(@PATH, 3, -123.272, -404.099, 58.503, 0),
(@PATH, 4, -118.284, -393.568, 56.6597, 0),
(@PATH, 5, -113.248, -383.834, 57.4938, 0),
(@PATH, 6, -110.754, -376.43, 58.3853, 0),
(@PATH, 7, -102.981, -375.647, 58.5188, 0),
(@PATH, 8, -100.981, -385.969, 58.2247, 0),
(@PATH, 9, -95.2868, -395.073, 59.1373, 0),
(@PATH, 10, -91.1278, -400.994, 58.2928, 0);

SET @NPC := 79189;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -94.8127, -396.214, 58.8776, 0),
(@PATH, 2, -103.299, -389.301, 57.3192, 0),
(@PATH, 3, -107.61, -382.619, 56.955, 0),
(@PATH, 4, -122.753, -383.213, 59.2935, 0),
(@PATH, 5, -125.399, -390.451, 58.8986, 0),
(@PATH, 6, -130, -398.722, 59.154, 0),
(@PATH, 7, -125.478, -403.119, 58.6467, 0),
(@PATH, 8, -116.097, -397.341, 57.1664, 0),
(@PATH, 9, -105.905, -394.793, 57.6366, 0),
(@PATH, 10, -100.374, -398.889, 58.6393, 0),
(@PATH, 11, -98.5197, -399.054, 58.4361, 0);

SET @NPC := 79229;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -278.114, -589.212, 50.569, 0),
(@PATH, 2, -283.429, -595.717, 49.8643, 0),
(@PATH, 3, -292.615, -600.322, 47.4784, 0),
(@PATH, 4, -297.727, -600.82, 47.6354, 0),
(@PATH, 5, -301.5, -597.342, 48.1357, 0),
(@PATH, 6, -302.42, -590.862, 47.866, 0),
(@PATH, 7, -296.284, -579.45, 48.5055, 0),
(@PATH, 8, -294.959, -575.836, 48.5461, 0),
(@PATH, 9, -289.625, -569.041, 49.1442, 0),
(@PATH, 10, -289.323, -560.17, 48.915, 0),
(@PATH, 11, -289.52, -548.415, 49.4453, 0),
(@PATH, 12, -288.878, -558.425, 48.9413, 0),
(@PATH, 13, -290.469, -567.745, 49.1461, 0),
(@PATH, 14, -293.706, -574.747, 48.6738, 0),
(@PATH, 15, -299.01, -581.124, 46.9888, 0),
(@PATH, 16, -302.881, -589.499, 47.6864, 0),
(@PATH, 17, -302.658, -595.325, 48.1197, 0),
(@PATH, 18, -298.651, -601.31, 47.7165, 0),
(@PATH, 19, -291.182, -601.608, 47.7367, 0),
(@PATH, 20, -284.572, -597.881, 49.3179, 0),
(@PATH, 21, -279.79, -590.679, 51.0235, 0),
(@PATH, 22, -273.983, -582.924, 50.2455, 0),
(@PATH, 23, -268.471, -578.609, 50.2878, 0),
(@PATH, 24, -264.631, -577.207, 50.572, 0),
(@PATH, 25, -255.102, -576.79, 51.1499, 0),
(@PATH, 26, -264.063, -577.211, 50.6017, 0),
(@PATH, 27, -269.527, -578.503, 50.0964, 0),
(@PATH, 28, -271.887, -581.544, 49.9768, 0);

SET @NPC := 79230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -268.146, -579.628, 50.2867, 0),
(@PATH, 2, -261.925, -576.253, 50.6762, 0),
(@PATH, 3, -262.645, -581.918, 50.6558, 0),
(@PATH, 4, -269.838, -582.501, 49.7938, 0),
(@PATH, 5, -275.048, -585.149, 50.206, 0),
(@PATH, 6, -279.743, -591.974, 51.1174, 0),
(@PATH, 7, -289.329, -599.613, 47.8713, 0),
(@PATH, 8, -303.126, -591.521, 47.8429, 0),
(@PATH, 9, -306.46, -600.112, 47.9633, 0),
(@PATH, 10, -298.557, -600.93, 47.7391, 0),
(@PATH, 11, -292.697, -604.317, 47.6708, 0),
(@PATH, 12, -283.382, -600.72, 49.8817, 0),
(@PATH, 13, -279.163, -589.875, 50.833, 0),
(@PATH, 14, -271.047, -581.964, 49.9021, 0);

SET @NPC := 79244;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -208.388, -504.123, 51.6638, 0),
(@PATH, 2, -216.747, -496.224, 49.2585, 0),
(@PATH, 3, -223.846, -486.092, 48.5716, 0),
(@PATH, 4, -235.5, -479.669, 49.2839, 0),
(@PATH, 5, -255.621, -480.855, 49.444, 0),
(@PATH, 6, -238.023, -480.745, 49.1653, 0),
(@PATH, 7, -228.454, -484.15, 48.8135, 0),
(@PATH, 8, -221.895, -489.782, 48.5886, 0),
(@PATH, 9, -217.476, -496.934, 49.2432, 0),
(@PATH, 10, -212.497, -501.494, 51.2166, 0),
(@PATH, 11, -206.973, -504.283, 51.9107, 0),
(@PATH, 12, -202.654, -504.281, 52.8393, 0);

SET @NPC := 79245;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -213.047, -504.664, 50.9039, 0),
(@PATH, 2, -218.668, -498.713, 49.1948, 0),
(@PATH, 3, -223.364, -491.597, 48.0883, 0),
(@PATH, 4, -233.816, -485.034, 48.8204, 0),
(@PATH, 5, -239.75, -483.76, 49.0921, 0),
(@PATH, 6, -245.689, -483.842, 49.2077, 0),
(@PATH, 7, -254.883, -483.617, 49.4456, 0),
(@PATH, 8, -241.837, -483.706, 48.9397, 0),
(@PATH, 9, -234.516, -485.182, 48.8104, 0),
(@PATH, 10, -225.919, -491.995, 47.9344, 0),
(@PATH, 11, -222.576, -494.121, 48.2125, 0),
(@PATH, 12, -217.75, -498.868, 49.335, 0),
(@PATH, 13, -215.491, -502.696, 50.809, 0),
(@PATH, 14, -209.724, -505.442, 51.3525, 0),
(@PATH, 15, -201.66, -505.78, 52.8074, 0);

SET @NPC := 79260;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -126.057, -637.441, 12.9147, 0),
(@PATH, 2, -131.207, -632.538, 13.5732, 0),
(@PATH, 3, -133.335, -622.248, 13.5651, 0),
(@PATH, 4, -133.871, -610.818, 13.8859, 0),
(@PATH, 5, -133.472, -601.267, 15.7631, 0),
(@PATH, 6, -132.348, -593.642, 17.6534, 0),
(@PATH, 7, -133.976, -587.795, 18.5455, 0),
(@PATH, 8, -138.885, -581.29, 18.3326, 0),
(@PATH, 9, -144.945, -580.472, 18.7264, 0),
(@PATH, 10, -137.154, -584.373, 18.0452, 0),
(@PATH, 11, -134.3, -588.078, 18.6262, 0),
(@PATH, 12, -132.542, -595.351, 16.9984, 0),
(@PATH, 13, -134.872, -606.677, 14.7144, 0),
(@PATH, 14, -134.189, -619.154, 13.7979, 0),
(@PATH, 15, -130.385, -630.688, 13.2223, 0),
(@PATH, 16, -126.983, -636.548, 12.9847, 0),
(@PATH, 17, -119.175, -640.513, 11.1588, 0),
(@PATH, 18, -114.638, -642.051, 10.2214, 0),
(@PATH, 19, -111.363, -646.713, 8.38844, 0);

SET @NPC := 79273;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -181.386, -491.686, 54.0401, 0),
(@PATH, 2, -180.97, -498.254, 53.4632, 0),
(@PATH, 3, -183.791, -502.539, 53.3808, 0),
(@PATH, 4, -193.579, -506.077, 53.1769, 0),
(@PATH, 5, -193.943, -496.426, 53.2004, 0),
(@PATH, 6, -192.361, -490.083, 53.539, 0),
(@PATH, 7, -187.413, -492.182, 53.5523, 0);

SET @NPC := 79280;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -178.516, -501.169, 53.9117, 0),
(@PATH, 2, -170.62, -506.242, 53.6692, 0),
(@PATH, 3, -159.051, -509.527, 53.3194, 0),
(@PATH, 4, -155.555, -512.44, 52.9296, 0),
(@PATH, 5, -153.638, -522.172, 52.0989, 0),
(@PATH, 6, -156.642, -511.144, 53.1215, 0),
(@PATH, 7, -163.563, -507.506, 53.2078, 0),
(@PATH, 8, -170.199, -507.066, 53.6323, 0),
(@PATH, 9, -177.721, -502.582, 53.9113, 0),
(@PATH, 10, -185.891, -502.888, 52.9808, 0),
(@PATH, 11, -192.141, -503.736, 53.1611, 0);

SET @NPC := 79283;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -235.978, -578.03, 51.2275, 0),
(@PATH, 2, -232.709, -566.546, 51.2354, 0),
(@PATH, 3, -226.826, -558.412, 51.2295, 0),
(@PATH, 4, -216.463, -551.683, 51.2295, 0),
(@PATH, 5, -206.377, -549.712, 51.2295, 0),
(@PATH, 6, -190.661, -554.203, 51.2295, 0),
(@PATH, 7, -194.537, -559.695, 51.2295, 0),
(@PATH, 8, -204.265, -556.918, 51.2295, 0),
(@PATH, 9, -212.195, -557.29, 51.2295, 0),
(@PATH, 10, -221.252, -562.377, 51.2295, 0),
(@PATH, 11, -227.049, -571.138, 51.2295, 0),
(@PATH, 12, -228.723, -581.277, 51.2264, 0),
(@PATH, 13, -235.13, -580.892, 51.222, 0);

SET @NPC := 79284;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -228.812, -569.757, 51.2314, 0),
(@PATH, 2, -225.332, -562.401, 51.23, 0),
(@PATH, 3, -220.089, -556.916, 51.23, 0),
(@PATH, 4, -211.182, -553.736, 51.23, 0),
(@PATH, 5, -203.248, -553.507, 51.23, 0),
(@PATH, 6, -194.853, -555.999, 51.23, 0),
(@PATH, 7, -187.356, -561.157, 51.23, 0),
(@PATH, 8, -182.826, -567.105, 51.072, 0),
(@PATH, 9, -179.251, -573.939, 48.0013, 0),
(@PATH, 10, -179.25, -581.854, 45.0103, 0),
(@PATH, 11, -180.508, -588.861, 42.1844, 0),
(@PATH, 12, -185.547, -596.173, 38.7453, 0),
(@PATH, 13, -193.62, -601.311, 34.4809, 0),
(@PATH, 14, -202.36, -605.164, 30.8329, 0),
(@PATH, 15, -212.195, -603.824, 26.463, 0),
(@PATH, 16, -219.832, -602.784, 23.3996, 0),
(@PATH, 17, -226.192, -596.772, 20.6368, 0),
(@PATH, 18, -228.849, -592.655, 19.4674, 0),
(@PATH, 19, -222.017, -602.068, 22.7777, 0),
(@PATH, 20, -215.955, -606.225, 25.5062, 0),
(@PATH, 21, -206.392, -607.716, 28.9385, 0),
(@PATH, 22, -195.975, -605.079, 33.3159, 0),
(@PATH, 23, -190.92, -602.234, 35.448, 0),
(@PATH, 24, -186.186, -599.686, 37.3745, 0),
(@PATH, 25, -181.845, -593.462, 40.1753, 0),
(@PATH, 26, -179.362, -585.189, 43.6891, 0),
(@PATH, 27, -180.207, -574.755, 47.8364, 0),
(@PATH, 28, -183.317, -567.58, 51.0124, 0),
(@PATH, 29, -188.935, -559.687, 51.2296, 0),
(@PATH, 30, -195.706, -554.703, 51.2296, 0),
(@PATH, 31, -204.469, -552.705, 51.2296, 0),
(@PATH, 32, -213.906, -554.141, 51.2296, 0),
(@PATH, 33, -222.241, -558.84, 51.2296, 0),
(@PATH, 34, -227.752, -566.248, 51.2296, 0),
(@PATH, 35, -230.554, -574.552, 51.223, 0),
(@PATH, 36, -230.624, -583.197, 51.2233, 0);

SET @NPC := 79294;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -95.7338, -697.73, 8.60488, 0),
(@PATH, 2, -96.7789, -688.803, 8.02651, 0),
(@PATH, 3, -96.152, -701.601, 8.81298, 0),
(@PATH, 4, -96.7254, -714.553, 8.68129, 0),
(@PATH, 5, -97.0199, -721.203, 8.4492, 0),
(@PATH, 6, -85.5141, -726.596, 8.9113, 0),
(@PATH, 7, -81.3754, -728.198, 8.96114, 0),
(@PATH, 8, -92.5992, -723.622, 8.55044, 0),
(@PATH, 9, -96.1957, -718.586, 8.52734, 0),
(@PATH, 10, -95.9761, -709.85, 8.78773, 0);

SET @NPC := 79302;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -74.2432, -730.129, 8.67827, 0),
(@PATH, 2, -77.1636, -729.474, 8.95225, 0),
(@PATH, 3, -68.9657, -731.816, 8.11165, 0),
(@PATH, 4, -58.8156, -731.452, 8.9764, 0),
(@PATH, 5, -46.8796, -729.33, 9.11806, 0),
(@PATH, 6, -36.0463, -729.314, 8.83626, 0),
(@PATH, 7, -23.478, -732.327, 8.36514, 0),
(@PATH, 8, -16.3456, -736.548, 8.74717, 0),
(@PATH, 9, -9.58846, -743.481, 8.97899, 0),
(@PATH, 10, -3.01404, -752.841, 8.79292, 0),
(@PATH, 11, -12.3875, -740.906, 9.06114, 0),
(@PATH, 12, -22.1426, -731.855, 8.36183, 0),
(@PATH, 13, -30.9523, -727.807, 8.45316, 0),
(@PATH, 14, -43.1824, -726.996, 8.89525, 0),
(@PATH, 15, -53.4473, -729.108, 9.3, 0),
(@PATH, 16, -61.0866, -731.592, 8.76967, 0);

SET @NPC := 79310;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -79.8256, -783.363, 26.461, 0),
(@PATH, 2, -84.7052, -786.976, 26.2062, 0),
(@PATH, 3, -98.3674, -791.023, 27.8132, 0),
(@PATH, 4, -103.96, -792.568, 28.1713, 0),
(@PATH, 5, -92.1138, -786.301, 27.0584, 0),
(@PATH, 6, -83.4001, -782.925, 26.476, 0),
(@PATH, 7, -84.0784, -776.535, 26.7875, 0),
(@PATH, 8, -88.5902, -777.037, 26.4027, 0),
(@PATH, 9, -97.0735, -778.529, 22.3356, 0),
(@PATH, 10, -102.923, -781.45, 22.1074, 0),
(@PATH, 11, -112.949, -786.457, 17.2807, 0),
(@PATH, 12, -118.473, -790.736, 17.1538, 0),
(@PATH, 13, -109.865, -784.406, 18.4495, 0),
(@PATH, 14, -102.652, -780.832, 22.1535, 0),
(@PATH, 15, -95.9249, -778.518, 22.3439, 0),
(@PATH, 16, -86.3046, -776.903, 26.7781, 0),
(@PATH, 17, -82.7019, -776.492, 26.7884, 0);

SET @NPC := 79313;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -47.0207, -783.364, 18.4, 0),
(@PATH, 2, -57.6274, -780.952, 18.0084, 0),
(@PATH, 3, -67.8561, -779.966, 17.6858, 0),
(@PATH, 4, -78.7342, -780.823, 17.4011, 0),
(@PATH, 5, -87.9715, -783.347, 17.2087, 0),
(@PATH, 6, -99.7804, -787.733, 17.0235, 0),
(@PATH, 7, -117.292, -795.731, 16.8259, 0),
(@PATH, 8, -121.205, -790.938, 17.1427, 0),
(@PATH, 9, -128.615, -793.822, 17.1852, 0),
(@PATH, 10, -123.136, -796.65, 16.7944, 0),
(@PATH, 11, -120.107, -799.226, 16.8365, 0),
(@PATH, 12, -107.485, -791.94, 16.9355, 0),
(@PATH, 13, -98.2183, -786.068, 17.0327, 0),
(@PATH, 14, -90.2045, -783.179, 17.1543, 0),
(@PATH, 15, -82.5683, -782.137, 17.3244, 0),
(@PATH, 16, -75.9856, -780.132, 17.4616, 0),
(@PATH, 17, -63.743, -780.858, 17.8108, 0),
(@PATH, 18, -56.1258, -782.532, 18.0567, 0);

SET @NPC := 79322;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -120.628, -803.27, 16.9074, 0),
(@PATH, 2, -108.965, -794.554, 16.9476, 0),
(@PATH, 3, -98.7241, -790.001, 17.0705, 0),
(@PATH, 4, -87.8975, -787.106, 17.236, 0),
(@PATH, 5, -76.0205, -785.218, 17.4743, 0),
(@PATH, 6, -64.5553, -783.844, 17.7829, 0),
(@PATH, 7, -53.9866, -784.947, 18.1333, 0),
(@PATH, 8, -46.1769, -784.534, 18.4305, 0),
(@PATH, 9, -38.5092, -787.698, 18.7604, 0),
(@PATH, 10, -31.5202, -795.86, 19.0579, 0),
(@PATH, 11, -40.4254, -786.469, 18.68, 0),
(@PATH, 12, -47.8866, -784.107, 18.3624, 0),
(@PATH, 13, -57.419, -784.738, 18.0015, 0),
(@PATH, 14, -67.7957, -782.45, 17.6857, 0),
(@PATH, 15, -84.9486, -784.841, 17.2894, 0),
(@PATH, 16, -99.947, -789.274, 17.039, 0),
(@PATH, 17, -111.081, -795.188, 16.9254, 0);

SET @NPC := 79352;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -117.106, -839.009, 16.9045, 0),
(@PATH, 2, -122.192, -831.302, 16.944, 0),
(@PATH, 3, -123.001, -826.456, 16.9273, 0),
(@PATH, 4, -121.999, -834.271, 16.902, 0),
(@PATH, 5, -115.461, -840.748, 16.9072, 0),
(@PATH, 6, -101.85, -849.963, 17.0177, 0),
(@PATH, 7, -87.6209, -854.885, 17.2528, 0),
(@PATH, 8, -78.4275, -856.52, 17.4395, 0),
(@PATH, 9, -66.7588, -856.625, 17.1192, 0),
(@PATH, 10, -56.7404, -856.366, 18.0792, 0),
(@PATH, 11, -44.1896, -853.147, 18.5486, 0),
(@PATH, 12, -36.0581, -849.06, 18.9014, 0),
(@PATH, 13, -28.4667, -841.478, 19.2514, 0),
(@PATH, 14, -24.0773, -834.352, 19.4557, 0),
(@PATH, 15, -20.3287, -825.712, 19.6396, 0),
(@PATH, 16, -25.5192, -835.12, 19.3762, 0),
(@PATH, 17, -34.3872, -844.244, 18.952, 0),
(@PATH, 18, -43.7533, -850.723, 18.5518, 0),
(@PATH, 19, -53.5531, -853.393, 18.1786, 0),
(@PATH, 20, -67.8261, -854.946, 17.0763, 0),
(@PATH, 21, -80.7533, -854.221, 17.4013, 0),
(@PATH, 22, -86.6403, -853.322, 17.2865, 0),
(@PATH, 23, -100.089, -847.089, 17.0872, 0),
(@PATH, 24, -107.973, -842.11, 17.019, 0),
(@PATH, 25, -116.381, -837.35, 16.9481, 0);

SET @NPC := 79361;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -115.531, -640.289, 10.332, 0),
(@PATH, 2, -119.61, -637.165, 11.9972, 0),
(@PATH, 3, -125.722, -634.24, 12.863, 0),
(@PATH, 4, -129.801, -627.561, 13.2444, 0),
(@PATH, 5, -131.164, -621.045, 13.0536, 0),
(@PATH, 6, -130.259, -612.687, 13.65, 0),
(@PATH, 7, -131.342, -604.735, 15.2594, 0),
(@PATH, 8, -131.868, -596.116, 16.6263, 0),
(@PATH, 9, -132.668, -589.162, 18.4356, 0),
(@PATH, 10, -137.081, -581.72, 17.9692, 0),
(@PATH, 11, -144.153, -579.298, 18.7887, 0),
(@PATH, 12, -135.828, -582.273, 18.0063, 0),
(@PATH, 13, -132.765, -587.922, 18.3614, 0),
(@PATH, 14, -131.508, -595.588, 16.8821, 0),
(@PATH, 15, -132.487, -606.489, 14.5759, 0),
(@PATH, 16, -131.772, -617.091, 13.2291, 0),
(@PATH, 17, -130.21, -625.345, 13.0998, 0),
(@PATH, 18, -124.713, -635.075, 12.7965, 0),
(@PATH, 19, -116.702, -640.322, 10.5276, 0),
(@PATH, 20, -110.439, -643.186, 9.0142, 0),
(@PATH, 21, -107.318, -649.43, 6.96608, 0);

SET @NPC := 79360;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -101.323, -648.082, 6.95428, 0),
(@PATH, 2, -106.893, -643.256, 8.25241, 0),
(@PATH, 3, -116.156, -638.283, 10.5795, 0),
(@PATH, 4, -123.216, -635.846, 12.7492, 0),
(@PATH, 5, -127.748, -630.052, 13.1721, 0),
(@PATH, 6, -125.632, -621.187, 12.7552, 0),
(@PATH, 7, -121.634, -617.784, 13.6787, 0),
(@PATH, 8, -112.41, -617.57, 13.3277, 0),
(@PATH, 9, -121.307, -615.05, 14.0148, 0),
(@PATH, 10, -131.972, -613.742, 13.2048, 0),
(@PATH, 11, -135.859, -619.815, 14.3729, 0),
(@PATH, 12, -128.42, -626.904, 13.3199, 0),
(@PATH, 13, -127.534, -633.981, 12.8688, 0),
(@PATH, 14, -121.512, -637.325, 12.6194, 0),
(@PATH, 15, -112.917, -639.004, 10.0211, 0),
(@PATH, 16, -108.466, -642.414, 8.67491, 0),
(@PATH, 17, -110.735, -651.05, 7.17773, 0);

SET @NPC := 79373;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -158.903, -399.895, 56.3324, 0),
(@PATH, 2, -151.984, -402.043, 56.9471, 0),
(@PATH, 3, -144.297, -403.96, 57.6147, 0),
(@PATH, 4, -154.368, -401.496, 56.7647, 0),
(@PATH, 5, -161.632, -400.326, 56.6994, 0),
(@PATH, 6, -167.493, -401.874, 57.0191, 0),
(@PATH, 7, -170.658, -405.778, 57.1812, 0),
(@PATH, 8, -179.541, -417.187, 55.0673, 0),
(@PATH, 9, -172.693, -407.324, 56.4777, 0),
(@PATH, 10, -169.554, -402.835, 57.1019, 0);

SET @NPC := 79374;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -167.042, -399.26, 57.2689, 0),
(@PATH, 2, -157.894, -397.54, 56.2972, 0),
(@PATH, 3, -150.114, -399.496, 56.8607, 0),
(@PATH, 4, -142.306, -402.254, 57.9221, 0),
(@PATH, 5, -152.106, -398.53, 56.6912, 0),
(@PATH, 6, -161.718, -397.32, 56.6253, 0),
(@PATH, 7, -168.749, -400.742, 57.2089, 0),
(@PATH, 8, -173.918, -404.355, 56.7423, 0),
(@PATH, 9, -182.801, -416.518, 54.9347, 0),
(@PATH, 10, -177.175, -408.341, 55.6547, 0),
(@PATH, 11, -172.19, -403.093, 57.0664, 0),
(@PATH, 12, -169.061, -399.799, 57.253, 0);

SET @NPC := 79376;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -272.555, -584.816, 50.3737, 0),
(@PATH, 2, -276.013, -589.511, 50.5626, 0),
(@PATH, 3, -280.155, -596.561, 50.7085, 0),
(@PATH, 4, -284.985, -600.429, 49.1995, 0),
(@PATH, 5, -294.598, -604.058, 47.5833, 0),
(@PATH, 6, -300.205, -604.022, 47.6767, 0),
(@PATH, 7, -303.986, -595.353, 48.1082, 0),
(@PATH, 8, -304.541, -589.661, 47.556, 0),
(@PATH, 9, -299.254, -582.531, 46.9581, 0),
(@PATH, 10, -297.696, -577.169, 47.9851, 0),
(@PATH, 11, -293.229, -569.243, 48.8091, 0),
(@PATH, 12, -292.196, -562.316, 48.993, 0),
(@PATH, 13, -292.548, -549.596, 49.4471, 0),
(@PATH, 14, -292.54, -555.878, 49.4473, 0),
(@PATH, 15, -294.605, -566.301, 48.6513, 0),
(@PATH, 16, -297.839, -573.818, 48.18, 0),
(@PATH, 17, -304.166, -583.905, 48.0411, 0),
(@PATH, 18, -307.088, -591.915, 47.7115, 0),
(@PATH, 19, -304.936, -599.439, 48.0508, 0),
(@PATH, 20, -299.129, -602.931, 47.6307, 0),
(@PATH, 21, -287.287, -601.839, 48.4487, 0),
(@PATH, 22, -283.396, -599.706, 49.8093, 0),
(@PATH, 23, -279.445, -593.227, 50.9235, 0),
(@PATH, 24, -274.212, -587.13, 50.5272, 0),
(@PATH, 25, -268.536, -581.925, 50.0732, 0),
(@PATH, 26, -261.97, -579.867, 50.5795, 0),
(@PATH, 27, -256.205, -579.168, 51.1499, 0),
(@PATH, 28, -264.283, -578.689, 50.5239, 0);

SET @NPC := 79378;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -212.814, -554.361, 19.3065, 0),
(@PATH, 2, -218.746, -556.944, 19.3065, 0),
(@PATH, 3, -223.087, -559.872, 19.3065, 0),
(@PATH, 4, -226.844, -563.376, 19.3065, 0),
(@PATH, 5, -231.155, -571.766, 19.3065, 0),
(@PATH, 6, -232.115, -577.525, 19.3065, 0),
(@PATH, 7, -231.803, -584.413, 19.3065, 0),
(@PATH, 8, -231.942, -577.026, 19.3065, 0),
(@PATH, 9, -229.256, -568.698, 19.3065, 0),
(@PATH, 10, -226.79, -563.796, 19.3065, 0),
(@PATH, 11, -221.51, -559.031, 19.3065, 0),
(@PATH, 12, -215.367, -555.433, 19.3065, 0),
(@PATH, 13, -209.962, -553.943, 19.3065, 0),
(@PATH, 14, -202.732, -554.291, 19.3065, 0),
(@PATH, 15, -195.872, -555.719, 19.3065, 0),
(@PATH, 16, -191.306, -558.311, 19.3065, 0),
(@PATH, 17, -186.76, -561.962, 19.3065, 0),
(@PATH, 18, -183.302, -567.237, 19.3069, 0),
(@PATH, 19, -188.236, -561.17, 19.3069, 0),
(@PATH, 20, -193.608, -557.227, 19.3069, 0),
(@PATH, 21, -199.561, -554.525, 19.3069, 0),
(@PATH, 22, -205.59, -553.829, 19.3069, 0);

SET @NPC := 79379;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -213.462, -552.205, 19.3069, 0),
(@PATH, 2, -218.541, -554.302, 19.3069, 0),
(@PATH, 3, -223.459, -556.979, 19.3069, 0),
(@PATH, 4, -227.632, -561.386, 19.3069, 0),
(@PATH, 5, -231.301, -566.23, 19.3069, 0),
(@PATH, 6, -233.369, -572.188, 19.3069, 0),
(@PATH, 7, -234.456, -578.159, 19.3069, 0),
(@PATH, 8, -234.281, -584.575, 19.3069, 0),
(@PATH, 9, -233.902, -579.447, 19.3069, 0),
(@PATH, 10, -233.019, -572.849, 19.3069, 0),
(@PATH, 11, -231.265, -567.039, 19.3069, 0),
(@PATH, 12, -228.422, -563.335, 19.3069, 0),
(@PATH, 13, -224.399, -558.634, 19.3069, 0),
(@PATH, 14, -218.11, -554.816, 19.3069, 0),
(@PATH, 15, -213.458, -552.633, 19.3069, 0),
(@PATH, 16, -206.749, -551.075, 19.3069, 0),
(@PATH, 17, -200.565, -551.295, 19.3069, 0),
(@PATH, 18, -194.766, -553.086, 19.3069, 0),
(@PATH, 19, -188.36, -557.568, 19.3069, 0),
(@PATH, 20, -183.78, -561.905, 19.3069, 0),
(@PATH, 21, -180.807, -566.232, 19.3072, 0);

SET @NPC := 79380;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, -209.205, -552.38, 19.3072, 0),
(@PATH, 2, -213.383, -553.387, 19.3072, 0),
(@PATH, 3, -218.492, -555.682, 19.3072, 0),
(@PATH, 4, -222.232, -557.608, 19.3072, 0),
(@PATH, 5, -225.394, -560.198, 19.3072, 0),
(@PATH, 6, -228.666, -564.743, 19.3072, 0),
(@PATH, 7, -231.182, -568.937, 19.3072, 0),
(@PATH, 8, -232.432, -571.965, 19.3072, 0),
(@PATH, 9, -233.102, -577.876, 19.3072, 0),
(@PATH, 10, -232.975, -582.662, 19.3072, 0),
(@PATH, 11, -232.797, -584.057, 19.3072, 0),
(@PATH, 12, -233.272, -578.126, 19.3072, 0),
(@PATH, 13, -232.335, -572.492, 19.3072, 0),
(@PATH, 14, -229.983, -566.768, 19.3072, 0),
(@PATH, 15, -225.726, -561.212, 19.3072, 0),
(@PATH, 16, -221.409, -557.108, 19.3072, 0),
(@PATH, 17, -215.71, -554.406, 19.3072, 0),
(@PATH, 18, -210.331, -552.845, 19.3072, 0),
(@PATH, 19, -204.152, -552.711, 19.3072, 0),
(@PATH, 20, -198.758, -553.724, 19.3072, 0),
(@PATH, 21, -193.812, -555.45, 19.3072, 0),
(@PATH, 22, -190.047, -557.31, 19.3072, 0),
(@PATH, 23, -186.283, -560.27, 19.3072, 0),
(@PATH, 24, -182.695, -565.735, 19.3072, 0),
(@PATH, 25, -186.463, -560.21, 19.3072, 0),
(@PATH, 26, -191.284, -556.552, 19.3072, 0),
(@PATH, 27, -195.167, -554.404, 19.3072, 0),
(@PATH, 28, -200.723, -553.018, 19.3072, 0),
(@PATH, 29, -205.954, -552.576, 19.3072, 0);
