-- Stormpeak Wyrm proper spawning and waypoints

DELETE FROM `creature` WHERE `guid` IN (101053,101062,101074,101075,101077,101116,101087);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(101053,29753,571,1,1,7452.299,-1354.762,942.6544,1.972222,120,0,0),
(101062,29753,571,1,1,7236.676,-1416.466,931.475,0.1919862,120,0,0),
(101074,29753,571,1,1,7353.788,-1644.01,1141.247,1.745329,120,0,0),
(101075,29753,571,1,1,7248.159,-1659.583,1080.83,1.099557,120,0,0),
(101077,29753,571,1,1,6998.847,-1445.083,984.7883,6.126106,120,0,0),
(101116,29753,571,1,1,7144.828,-1255.926,1100.343,5.77704,120,0,0),
(101087,29753,571,1,1,7135.227,-1283.292,1091.594,5.72468,120,0,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7584.947,`position_y`=-1634.492,`position_z`=1212.406,`orientation`=2.059489 WHERE `guid`=101123;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7694.302,`position_y`=-1493.291,`position_z`=1177.766,`orientation`=2.70526 WHERE `guid`=101124;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7596.796,`position_y`=-1506.441,`position_z`=1053.565,`orientation`=2.199115 WHERE `guid`=101125;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7684.877,`position_y`=-1422.165,`position_z`=1176.521,`orientation`=2.80998 WHERE `guid`=101126;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=7477.212,`position_y`=-1534.251,`position_z`=1038.112,`orientation`=2.146755 WHERE `guid`=101127;

DELETE FROM `creature_addon` WHERE `guid` IN (101123,101124,101125,101126,101127,101053,101062,101074,101075,101077,101116,101087);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`auras`) VALUES 
(101123,50331649,1, ''),(101124,50331649,1, ''),(101125,50331649,1, ''),(101126,50331649,1, ''),(101127,50331649,1, ''),(101053,50331649,1, ''),
(101062,50331649,1, ''),(101074,50331649,1, ''),(101075,50331649,1, ''),(101077,50331649,1, ''),(101116,50331649,1, ''),(101087,50331649,1, '');

DELETE FROM `waypoint_data` WHERE `id` IN (1011090,1011110,1011120,1011210,1011230,1011240);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101000;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7501.124,`position_y`=-1449.262,`position_z`=1017.798 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7501.124,-1449.262,1017.798,0,0,1,0,100,0),
(@PATH,2,7376.508,-1303.557,1049.854,0,0,1,0,100,0),
(@PATH,3,7325.549,-1146.471,1046.354,0,0,1,0,100,0),
(@PATH,4,7422.022,-1135.82,1033.438,0,0,1,0,100,0),
(@PATH,5,7518.522,-1237.663,1056.826,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101107;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7286.94,`position_y`=-1422.521,`position_z`=978.0876 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7286.94,-1422.521,978.0876,0,0,1,0,100,0),
(@PATH,2,7141.904,-1431.155,978.0876,0,0,1,0,100,0),
(@PATH,3,7141.696,-1557.372,978.0876,0,0,1,0,100,0),
(@PATH,4,7391.402,-1533.6,1071.171,0,0,1,0,100,0),
(@PATH,5,7711.191,-1351.858,1194.367,0,0,1,0,100,0),
(@PATH,6,7616.785,-1342.911,1117.866,0,0,1,0,100,0),
(@PATH,7,7441.751,-1377.483,985.6154,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101108;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7451.667,`position_y`=-1273.214,`position_z`=958.2651 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7451.667,-1273.214,958.2651,0,0,1,0,100,0),
(@PATH,2,7438.734,-1387.923,990.5983,0,0,1,0,100,0),
(@PATH,3,7339.777,-1394.429,954.5706,0,0,1,0,100,0),
(@PATH,4,7277.429,-1311.084,941.7929,0,0,1,0,100,0),
(@PATH,5,7389.834,-1218.347,954.5706,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101109;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7361.022,`position_y`=-1158.353,`position_z`=980.812 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7361.022,-1158.353,980.812,0,0,1,0,100,0),
(@PATH,2,7505.094,-1216.21,980.812,0,0,1,0,100,0),
(@PATH,3,7458.424,-1438.003,1005.173,0,0,1,0,100,0),
(@PATH,4,7528.125,-1725.565,1300.173,0,0,1,0,100,0),
(@PATH,5,7422.311,-1569.981,1141.312,0,0,1,0,100,0),
(@PATH,6,7330.956,-1412.603,980.812,0,0,1,0,100,0),
(@PATH,7,7303.932,-1283.664,980.812,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101110;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7468.895,`position_y`=-1421.992,`position_z`=1035.363 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7468.895,-1421.992,1035.363,0,0,1,0,100,0),
(@PATH,2,7499.714,-1349.263,1035.363,0,0,1,0,100,0),
(@PATH,3,7436.533,-1280.687,1035.363,0,0,1,0,100,0),
(@PATH,4,7396.054,-1281.403,1035.363,0,0,1,0,100,0),
(@PATH,5,7298.188,-1334.745,1035.363,0,0,1,0,100,0),
(@PATH,6,7306.776,-1409.522,1035.363,0,0,1,0,100,0),
(@PATH,7,7403.804,-1456.458,1035.363,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7146.302,`position_y`=-1430.093,`position_z`=1026.784 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7146.302,-1430.093,1026.784,0,0,1,0,100,0),
(@PATH,2,7277.046,-1312.483,941.7841,0,0,1,0,100,0),
(@PATH,3,7350.68,-1247.736,932.9788,0,0,1,0,100,0),
(@PATH,4,7462.04,-1145.189,1073.34,0,0,1,0,100,0),
(@PATH,5,7534.368,-1192.623,1109.757,0,0,1,0,100,0),
(@PATH,6,7491.979,-1297.336,1075.256,0,0,1,0,100,0),
(@PATH,7,7435.823,-1388.198,963.8117,0,0,1,0,100,0),
(@PATH,8,7374.318,-1466.145,951.8396,0,0,1,0,100,0),
(@PATH,9,7270.311,-1513.188,983.5063,0,0,1,0,100,0),
(@PATH,10,7186.261,-1542.495,999.2841,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101112;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7265.552,`position_y`=-1393.914,`position_z`=944.9113 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7265.552,-1393.914,944.9113,0,0,1,0,100,0),
(@PATH,2,7286.167,-1323.842,960.5223,0,0,1,0,100,0),
(@PATH,3,7397.717,-1365.071,953.9946,0,0,1,0,100,0),
(@PATH,4,7411.863,-1480.148,974.6611,0,0,1,0,100,0),
(@PATH,5,7293.046,-1491.665,952.7723,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101113;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7415.385,`position_y`=-1216.037,`position_z`=904.5762 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7415.385,-1216.037,904.5762,0,0,1,0,100,0),
(@PATH,2,7414.542,-1215.5,904.5762,0,0,1,0,100,0),
(@PATH,3,7133.187,-1316.918,1033.504,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101114;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7325.963,`position_y`=-1333.517,`position_z`=1030.937 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7325.963,-1333.517,1030.937,0,0,1,0,100,0),
(@PATH,2,7292.63,-1292.261,1030.937,0,0,1,0,100,0),
(@PATH,3,7242.074,-1296.146,1030.937,0,0,1,0,100,0),
(@PATH,4,7221.022,-1309.755,1030.937,0,0,1,0,100,0),
(@PATH,5,7184.733,-1362.635,1030.937,0,0,1,0,100,0),
(@PATH,6,7258.752,-1422.953,1030.937,0,0,1,0,100,0),
(@PATH,7,7322.385,-1391.359,1030.937,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7324.458,`position_y`=-1450.861,`position_z`=1008.698 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7324.458,-1450.861,1008.698,0,0,1,0,100,0),
(@PATH,2,7325.36,-1451.292,1008.698,0,0,1,0,100,0),
(@PATH,3,7386.206,-1228.145,918.316,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7136.357,`position_y`=-1325.542,`position_z`=1034.863 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7136.357,-1325.542,1034.863,0,0,1,0,100,0),
(@PATH,2,7135.358,-1325.567,1034.863,0,0,1,0,100,0),
(@PATH,3,7313.184,-1221.475,952.9126,0,0,1,0,100,0),
(@PATH,4,7282.429,-1268.767,952.9125,0,0,1,0,100,0),
(@PATH,5,7309.16,-1330.981,952.9125,0,0,1,0,100,0),
(@PATH,6,7367.971,-1345.04,952.9125,0,0,1,0,100,0),
(@PATH,7,7421.329,-1313.719,952.9125,0,0,1,0,100,0),
(@PATH,8,7452.836,-1261.122,952.9125,0,0,1,0,100,0),
(@PATH,9,7428.057,-1204.526,952.9125,0,0,1,0,100,0),
(@PATH,10,7386.783,-1192.458,952.9125,0,0,1,0,100,0),
(@PATH,11,7339.101,-1202.982,952.9125,0,0,1,0,100,0),
(@PATH,12,7313.184,-1221.475,952.9126,0,0,1,0,100,0),
(@PATH,13,7282.429,-1268.767,952.9125,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101118;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7232.853,`position_y`=-1552.436,`position_z`=1018.612 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7232.853,-1552.436,1018.612,0,0,1,0,100,0),
(@PATH,2,7307.723,-1450.282,1031.335,0,0,1,0,100,0),
(@PATH,3,7331.675,-1329.285,1071.668,0,0,1,0,100,0),
(@PATH,4,7358.584,-1200.453,1095.084,0,0,1,0,100,0),
(@PATH,5,7466.604,-1189.773,1087.835,0,0,1,0,100,0),
(@PATH,6,7551.937,-1306.039,1036.918,0,0,1,0,100,0),
(@PATH,7,7448.903,-1429.033,989.2788,0,0,1,0,100,0),
(@PATH,8,7265.264,-1460.603,924.7513,0,0,1,0,100,0),
(@PATH,9,7092.603,-1462.597,1039.613,0,0,1,0,100,0),
(@PATH,10,6996.566,-1627.143,1060.558,0,0,1,0,100,0),
(@PATH,11,7050.83,-1759.601,1026.474,0,0,1,0,100,0),
(@PATH,12,7171.794,-1623.425,1024.391,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101119;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7259.109,`position_y`=-1469.671,`position_z`=987.5555 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7259.109,-1469.671,987.5555,0,0,1,0,100,0),
(@PATH,2,7301.777,-1415.748,987.5555,0,0,1,0,100,0),
(@PATH,3,7272.482,-1346.15,987.5555,0,0,1,0,100,0),
(@PATH,4,7209.799,-1353.067,987.5555,0,0,1,0,100,0),
(@PATH,5,7162.837,-1385.03,987.5555,0,0,1,0,100,0),
(@PATH,6,7167.143,-1445.456,987.5555,0,0,1,0,100,0),
(@PATH,7,7194.672,-1478.044,987.5555,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101120;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7327.854,`position_y`=-1587.84,`position_z`=1019.788 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7327.854,-1587.84,1019.788,0,0,1,0,100,0),
(@PATH,2,7289.005,-1581.716,1019.788,0,0,1,0,100,0),
(@PATH,3,7237.962,-1537.732,1019.788,0,0,1,0,100,0),
(@PATH,4,7256.116,-1485.327,1019.788,0,0,1,0,100,0),
(@PATH,5,7329.179,-1461.23,1019.788,0,0,1,0,100,0),
(@PATH,6,7373.025,-1497.708,1019.788,0,0,1,0,100,0),
(@PATH,7,7376.84,-1544.165,1019.788,0,0,1,0,100,0),
(@PATH,8,7361.692,-1568.81,1019.788,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7199.313,`position_y`=-1325.969,`position_z`=978.4598 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7199.313,-1325.969,978.4598,0,0,1,0,100,0),
(@PATH,2,7170.299,-1447.351,1015.265,0,0,1,0,100,0),
(@PATH,3,7248.966,-1581.538,1015.265,0,0,1,0,100,0),
(@PATH,4,7413.176,-1485.288,1031.738,0,0,1,0,100,0),
(@PATH,5,7400.03,-1300.325,978.4598,0,0,1,0,100,0),
(@PATH,6,7290.922,-1270.148,1009.015,0,0,1,0,100,0);

-- Pathing for Stormpeak Wyrm Entry: 29753
SET @NPC := 101122;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7202.806,`position_y`=-1459.161,`position_z`=960.2362 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`auras`) VALUES (@NPC,@PATH,50331648,1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7202.806,-1459.161,960.2362,0,0,1,0,100,0),
(@PATH,2,7251.087,-1367.685,984.6526,0,0,1,0,100,0),
(@PATH,3,7332.536,-1407.866,956.3196,0,0,1,0,100,0),
(@PATH,4,7354.014,-1492.446,984.6526,0,0,1,0,100,0),
(@PATH,5,7307.592,-1550.958,984.6525,0,0,1,0,100,0),
(@PATH,6,7252.655,-1530.636,984.6526,0,0,1,0,100,0);
