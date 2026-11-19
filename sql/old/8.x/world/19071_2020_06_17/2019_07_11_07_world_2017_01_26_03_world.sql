-- Pathing for  Ice Steppe Bull, Ice Steppe Rhino
-- PATH 1
SET @NPC := 118284;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7423.957,`position_y`=-1296.378,`position_z`=905.7994 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7423.957,-1296.378,905.7994,0,0,0,0,100,0),
(@PATH,2,7423.207,-1294.878,905.5494,0,0,0,0,100,0),
(@PATH,3,7429.376,-1285.794,905.9041,0,0,0,0,100,0),
(@PATH,4,7430.876,-1284.544,906.4041,0,0,0,0,100,0),
(@PATH,5,7433.376,-1282.044,906.9041,0,0,0,0,100,0),
(@PATH,6,7437.555,-1277.748,907.4891,0,0,0,0,100,0),
(@PATH,7,7439.079,-1263.265,908.0903,0,0,0,0,100,0),
(@PATH,8,7433.079,-1259.765,907.3403,0,0,0,0,100,0),
(@PATH,9,7427.829,-1257.265,906.5903,0,0,0,0,100,0),
(@PATH,10,7423.579,-1254.765,906.0903,0,0,0,0,100,0),
(@PATH,11,7419.329,-1252.265,905.3403,0,0,0,0,100,0),
(@PATH,12,7420.336,-1252.72,905.65,0,0,0,0,100,0),
(@PATH,13,7424.586,-1255.22,906.15,0,0,0,0,100,0),
(@PATH,14,7428.836,-1257.47,906.9,0,0,0,0,100,0),
(@PATH,15,7434.086,-1260.47,907.4,0,0,0,0,100,0),
(@PATH,16,7439.084,-1263.665,908.0001,0,0,0,0,100,0),
(@PATH,17,7437.382,-1278.001,907.7031,0,0,0,0,100,0),
(@PATH,18,7433.882,-1281.251,906.9531,0,0,0,0,100,0),
(@PATH,19,7431.132,-1284.001,906.2031,0,0,0,0,100,0);
-- 0x203AF447601DBB4000279D00000780C3 .go 7423.957 -1296.378 905.7994

-- PATH 2
SET @NPC := 118276;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7362.583,`position_y`=-843.11,`position_z`=928.3768 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7362.583,-843.11,928.3768,0,0,0,0,100,0),
(@PATH,2,7347.104,-845.9831,928.9261,0,0,0,0,100,0),
(@PATH,3,7338.104,-862.2331,926.1761,0,0,0,0,100,0),
(@PATH,4,7335.104,-867.4831,925.4261,0,0,0,0,100,0),
(@PATH,5,7333.031,-870.6686,924.8076,0,0,0,0,100,0),
(@PATH,6,7327.781,-896.9186,920.8076,0,0,0,0,100,0),
(@PATH,7,7327.031,-900.9186,920.0576,0,0,0,0,100,0),
(@PATH,8,7326.281,-904.6686,919.5576,0,0,0,0,100,0),
(@PATH,9,7333.37,-916.5012,914.3215,0,0,0,0,100,0),
(@PATH,10,7337.124,-921.5064,912.4254,0,0,0,0,100,0),
(@PATH,11,7356.624,-931.0064,907.9254,0,0,0,0,100,0),
(@PATH,12,7358.154,-931.6561,907.7555,0,0,0,0,100,0),
(@PATH,13,7376.404,-927.9061,907.2555,0,0,0,0,100,0),
(@PATH,14,7383.091,-926.1368,907.111,0,0,0,0,100,0),
(@PATH,15,7393.841,-917.1368,907.611,0,0,0,0,100,0),
(@PATH,16,7408.091,-905.1368,908.111,0,0,0,0,100,0),
(@PATH,17,7408.076,-904.8667,908.2958,0,0,0,0,100,0),
(@PATH,18,7408.576,-904.3667,908.2958,0,0,0,0,100,0),
(@PATH,19,7400.434,-885.9966,911.2606,0,0,0,0,100,0),
(@PATH,20,7430.184,-887.4966,909.0106,0,0,0,0,100,0),
(@PATH,21,7430.371,-887.2373,909.2286,0,0,0,0,100,0),
(@PATH,22,7431.121,-887.2373,908.9786,0,0,0,0,100,0),
(@PATH,23,7448.156,-864.7871,911.5037,0,0,0,0,100,0),
(@PATH,24,7435.406,-854.2871,916.5037,0,0,0,0,100,0),
(@PATH,25,7409.506,-841.3146,924.3287,0,0,0,0,100,0),
(@PATH,26,7403.506,-841.0646,924.8287,0,0,0,0,100,0),
(@PATH,27,7369.467,-842.4135,927.8073,0,0,0,0,100,0);
-- 0x203AF447601DBB4000279D00000777C3 .go 7362.583 -843.11 928.3768

-- PATH 3
SET @NPC := 118283;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7353.815,`position_y`=-1095.602,`position_z`=906.4462 WHERE `guid`=@NPC;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7353.815,`position_y`=-1095.602,`position_z`=906.4462 WHERE `guid` IN (98760,98748);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@NPC, @NPC, 0, 0, 2, 0, 0),
(@NPC, 98760, 9, 0, 2, 0, 0),
(@NPC, 98748, 18, 0, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7353.815,-1095.602,906.4462,0,0,0,0,100,0),
(@PATH,2,7341.202,-1006.478,907.835,0,0,0,0,100,0),
(@PATH,3,7408.074,-905.8561,908.2818,0,0,0,0,100,0),
(@PATH,4,7483.605,-864.9265,907.8044,0,0,0,0,100,0),
(@PATH,5,7545.216,-867.2673,909.7717,0,0,0,0,100,0),
(@PATH,6,7547.716,-868.7673,909.0217,0,0,0,0,100,0),
(@PATH,7,7625.293,-932.828,909.2414,0,0,0,0,100,0),
(@PATH,8,7656.626,-980.0931,909.3623,0,0,0,0,100,0),
(@PATH,9,7657.245,-996.4323,909.7177,0,0,0,0,100,0),
(@PATH,10,7665.711,-1089.889,912.439,0,0,0,0,100,0),
(@PATH,11,7651.383,-1131.382,912.444,0,0,0,0,100,0),
(@PATH,12,7631.108,-1201.456,926.4985,0,0,0,0,100,0),
(@PATH,13,7517.755,-1229.047,912.5535,0,0,0,0,100,0),
(@PATH,14,7455.11,-1228.592,906.8867,0,0,0,0,100,0),
(@PATH,15,7434.986,-1208.111,904.0192,0,0,0,0,100,0);
-- 0x203AF447601DBB4000279D00000769D6 .go 7353.815 -1095.602 906.4462

-- PATH 4
SET @NPC := 109887;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7307.643,`position_y`=-1134.117,`position_z`=939.1078 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7307.643,-1134.117,939.1078,0,0,0,0,100,0),
(@PATH,2,7301.095,-1119.335,938.8877,0,0,0,0,100,0),
(@PATH,3,7294.492,-1104.6,938.9634,0,0,0,0,100,0),
(@PATH,4,7275.742,-1113.1,939.4634,0,0,0,0,100,0),
(@PATH,5,7274.2,-1113.926,939.327,0,0,0,0,100,0),
(@PATH,6,7271.113,-1125.891,939.505,0,0,0,0,100,0),
(@PATH,7,7265.632,-1134.438,939.7554,0,0,0,0,100,0),
(@PATH,8,7267.833,-1144.287,940.0276,0,0,0,0,100,0),
(@PATH,9,7277.583,-1150.787,939.5276,0,0,0,0,100,0),
(@PATH,10,7280.181,-1152.635,938.7634,0,0,0,0,100,0),
(@PATH,11,7291.931,-1167.135,931.7634,0,0,0,0,100,0),
(@PATH,12,7294.623,-1170.238,930.2782,0,0,0,0,100,0),
(@PATH,13,7301.873,-1161.238,931.0282,0,0,0,0,100,0),
(@PATH,14,7307.188,-1137.067,938.9159,0,0,0,0,100,0);
-- 0x203AF447601D250000279D000006419A .go 7307.643 -1134.117 939.1078

-- PATH 5
SET @NPC := 118277;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 7511.66, -1265.84, 916.818, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 7511.82, -1296.15, 919.053, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7508.53, -1321.7, 923.942, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 7505.44, -1342.42, 927.679, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7518.55, -1364.13, 933.83, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 7541.92, -1364.92, 939.483, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 7556.62, -1353.6, 940.324, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 7565.78, -1332.09, 936.385, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 7573.26, -1307.58, 933.275, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 7577.99, -1291.9, 931.266, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 7584.74, -1269.52, 927.317, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 7589.57, -1256.37, 926.239, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 7594.64, -1240.8, 925.904, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 7578.63, -1231.02, 921.326, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 7548.72, -1226.55, 915.25, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 7525.23, -1227.74, 912.811, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 7506.94, -1245.52, 912.742, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (98735, 98788, 98736, 98737);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@NPC, @NPC, 0, 0, 2, 0, 0),
(@NPC, 98735,  9, 80, 2, 0, 0),
(@NPC, 98788,  9, 280, 2, 0, 0),
(@NPC, 98736,  9, 40, 2, 0, 0),
(@NPC, 98737,  9, 320, 2, 0, 0);

-- PATH 6
SET @NPC := 98755;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 7445, -1219.29, 906.085, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 7405.58, -1204.4, 902.721, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7383.73, -1196.15, 903.256, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 7352.31, -1196.72, 910.659, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7333.97, -1226.38, 908.203, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 7316.98, -1254.39, 906.235, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 7306.49, -1285.16, 904.358, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 7307.28, -1315.53, 905.341, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 7333.23, -1338.96, 905.015, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 7360.98, -1364.01, 909.097, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 7386.85, -1387.37, 913.823, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 7411.13, -1409.29, 922.04, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 7432.9, -1422.78, 931.181, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 7471.18, -1414.63, 939.009, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 7503.14, -1391.24, 937.558, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 7531.38, -1359.96, 935.098, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 7562.98, -1322.33, 932.563, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 7572.99, -1286.48, 927.591, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 7567.46, -1247.23, 918.955, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 7532.45, -1234.15, 914.196, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 7487.65, -1220.75, 908.481, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 7462.13, -1217.22, 907.872, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (98753, 98754, 98752);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(@NPC, @NPC, 0, 0, 2, 0, 0),
(@NPC, 98753,  9, 80, 2, 0, 0),
(@NPC, 98754,  9, 280, 2, 0, 0),
(@NPC, 98752,  9, 40, 2, 0, 0);

-- PATH 7
SET @NPC := 118275;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@PATH, 1, 7232.42, -1382.21, 914.452, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 7202.75, -1411.63, 916.145, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7193.88, -1447.78, 917.451, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 7211.05, -1483.29, 919.087, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7235.18, -1504.52, 919.274, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 7264.65, -1523.15, 924.678, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 7289.27, -1530.74, 927.058, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 7308.62, -1510.4, 922.684, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 7324.98, -1476.8, 920.33, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 7339.45, -1442.33, 915.355, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 7352.13, -1412.13, 913.082, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 7366.06, -1380.02, 910.886, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 7351.12, -1351.01, 906.676, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 7329.06, -1317.94, 904.493, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 7310.59, -1300.14, 904.346, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 7283.2, -1305.97, 909.415, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 7264.62, -1337.6, 911.746, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`=7249.12, `position_z`=913.337, `position_y`=-1364.72, `spawndist`=0, `MovementType`=0 WHERE  `guid`IN (98738, 98745);

DELETE FROM `creature_formations` WHERE `leaderGUID`=118275;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(118275, 118275, 0, 0, 2, 0, 0),
(118275, 98738, 9, 20, 2, 0, 0),
(118275, 98745, 9, 290, 2, 0, 0);
