-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126942; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269420, 1, 1336.35, 97.1842, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 2, 1337.76, 97.2226, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 3, 1339.43, 101.827, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 4, 1337.51, 102.338, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 5, 1337.45, 101.881, 40.1805, 0, 4000, 0, 0, 100, 0),
(1269420, 6, 1327.41, 101.553, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 7, 1327.35, 100.975, 40.1805, 0, 4000, 0, 0, 100, 0),
(1269420, 8, 1325.64, 100.623, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 9, 1325.01, 96.4632, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 10, 1327.11, 96.4808, 40.1805, 0, 0, 0, 0, 100, 0),
(1269420, 11, 1327.07, 96.8291, 40.1805, 0, 4000, 0, 0, 100, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (28582, 30974);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(28582, 0, 0, 0, 0, 69, ''),
(30974, 0, 0, 0, 0, 69, '');

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126926; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269260, 1, 1377.28, 64.533, 48.8931, 0, 0, 0, 0, 100, 0),
(1269260, 2, 1377.69, 64.9436, 48.8931, 0, 6000, 0, 0, 100, 0),
(1269260, 3, 1359.25, 81.9585, 41.0455, 0, 0, 0, 0, 100, 0),
(1269260, 4, 1359.68, 82.5069, 41.0204, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126915; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269150, 1, 1393.45, 47.8648, 50.0383, 0, 6000, 0, 0, 100, 0),
(1269150, 2, 1401.61, 46.3271, 50.0383, 0, 0, 0, 0, 100, 0),
(1269150, 3, 1401.81, 45.7834, 50.0383, 0, 6000, 0, 0, 100, 0),
(1269150, 4, 1394.37, 48.5111, 50.0383, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126925; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269250, 1, 1414.64, 32.7402, 50.2271, 0, 0, 0, 0, 100, 0),
(1269250, 2, 1419.4, 32.7552, 53.1143, 0, 0, 0, 0, 100, 0),
(1269250, 3, 1429.45, 32.845, 58.7644, 0, 0, 0, 0, 100, 0),
(1269250, 4, 1433.53, 32.8176, 58.7671, 0, 0, 0, 0, 100, 0),
(1269250, 5, 1434.02, 32.0269, 58.7671, 0, 6000, 0, 0, 100, 0),
(1269250, 6, 1430.18, 32.2594, 58.7671, 0, 0, 0, 0, 100, 0),
(1269250, 7, 1422.24, 32.287, 54.8356, 0, 0, 0, 0, 100, 0),
(1269250, 8, 1414.43, 32.6758, 50.0945, 0, 0, 0, 0, 100, 0),
(1269250, 9, 1407.78, 32.7916, 50.0383, 0, 0, 0, 0, 100, 0),
(1269250, 10, 1406.76, 32.718, 50.0383, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126924; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269240, 1, 1358.66, -8.12641, 41.1612, 0, 0, 0, 0, 100, 0),
(1269240, 2, 1359.22, -8.72624, 41.1518, 0, 6000, 0, 0, 100, 0),
(1269240, 3, 1376.27, 9.68446, 48.9541, 0, 0, 0, 0, 100, 0),
(1269240, 4, 1376.68, 9.25245, 48.95, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126933; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269330, 1, 1353.19, 3.42894, 42.4993, 0, 0, 0, 0, 100, 0),
(1269330, 2, 1352.77, 3.83879, 42.4978, 0, 6000, 0, 0, 100, 0),
(1269330, 3, 1368.11, 18.3238, 49.0597, 0, 0, 0, 0, 100, 0),
(1269330, 4, 1367.63, 18.8363, 49.0662, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126939; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269390, 1, 1324.11, -36.4178, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 2, 1320.59, -33.3142, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 3, 1322.34, -31.4373, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 4, 1323.13, -32.1258, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 5, 1321.68, -35.1774, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 6, 1324.78, -37.6497, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 7, 1340.48, -36.3091, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 8, 1341.82, -34.5498, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 9, 1342.51, -31.7143, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 10, 1343.71, -26.8389, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 11, 1343.06, -26.1627, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 12, 1341.99, -31.7877, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 13, 1341.6, -32.2199, 40.1806, 0, 6000, 0, 0, 100, 0),
(1269390, 14, 1341.2, -36.4011, 40.1806, 0, 0, 0, 0, 100, 0),
(1269390, 15, 1325.72, -38.8983, 40.1806, 0, 0, 0, 0, 100, 0);


-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126941; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269410, 1, 1267.08, -35.0841, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 2, 1253.98, -31.204, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 3, 1252.76, -28.9487, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 4, 1255.2, -33.8478, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 5, 1256.82, -34.5311, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269410, 6, 1256.49, -38.1348, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 7, 1259.85, -39.4856, 33.5057, 0, 0, 0, 0, 100, 0),
(1269410, 8, 1264.16, -36.9788, 33.5057, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126917; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269170, 1, 1268.62, 32.3739, 33.5057, 0, 0, 0, 0, 100, 0),
(1269170, 2, 1270.03, 32.3423, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269170, 3, 1269.46, 0.489199, 33.5057, 0, 0, 0, 0, 100, 0),
(1269170, 4, 1269.81, 0.525176, 33.5057, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126940; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269400, 1, 1269.07, 39.2463, 33.5055, 0, 0, 0, 0, 100, 0),
(1269400, 2, 1269.94, 39.279, 33.5055, 0, 6000, 0, 0, 100, 0),
(1269400, 3, 1269, 68.7823, 33.5055, 0, 0, 0, 0, 100, 0),
(1269400, 4, 1269.8, 68.7924, 33.5055, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126919; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269190, 1, 1254.43, 38.9632, 33.5056, 0, 0, 0, 0, 100, 0),
(1269190, 2, 1254.33, 32.6571, 35.0186, 0, 0, 0, 0, 100, 0),
(1269190, 3, 1254.73, 9.53858, 33.5056, 0, 0, 0, 0, 100, 0),
(1269190, 4, 1254.26, 9.55597, 33.5056, 0, 6000, 0, 0, 100, 0),
(1269190, 5, 1254.61, 28.5055, 33.8212, 0, 0, 0, 0, 100, 0),
(1269190, 6, 1254.59, 33.0582, 35.0141, 0, 0, 0, 0, 100, 0),
(1269190, 7, 1254.56, 55.7588, 33.5058, 0, 0, 0, 0, 100, 0),
(1269190, 8, 1254.14, 55.7403, 33.5058, 0, 6000, 0, 0, 100, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126918; 
SET @PATH := 1269180;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1269180, 1, 1252.42, 106.457, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 2, 1249.45, 101.782, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 3, 1250.39, 100.591, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 4, 1251.37, 101.803, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 5, 1250.43, 104.446, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 6, 1259.91, 113.097, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 7, 1265.25, 112.968, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 8, 1273.82, 106.516, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 9, 1274.95, 101.531, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 10, 1272.59, 100.018, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 11, 1272.4, 100.808, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 12, 1275.02, 103.29, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 13, 1273.92, 106.241, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 14, 1267.23, 108.337, 33.5057, 0, 0, 0, 0, 100, 0),
(1269180, 15, 1264.99, 108.96, 33.5057, 0, 6000, 0, 0, 100, 0),
(1269180, 16, 1263.4, 112.342, 33.5057, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id`=28585;
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (28825, 28547, 28584, 28583);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 126954;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1311.234,`position_y`=-158.9818,`position_z`=52.27496 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1311.234,-158.9818,52.27496,0,0,0,0,100,0),
(@PATH,2,1312.317,-174.7872,52.27221,0,0,0,0,100,0),
(@PATH,3,1328.705,-186.7419,52.27302,0,0,0,0,100,0),
(@PATH,4,1341.044,-184.8856,52.27322,0,0,0,0,100,0),
(@PATH,5,1354.387,-173.1809,52.27328,0,0,0,0,100,0),
(@PATH,6,1354.742,-169.7169,52.27325,0,0,0,0,100,0),
(@PATH,7,1348.927,-148.5091,52.27411,0,0,0,0,100,0),
(@PATH,8,1335.543,-142.5214,52.27379,0,0,0,0,100,0),
(@PATH,9,1318.144,-146.4185,52.31124,0,0,0,0,100,0),
(@PATH,10,1311.167,-158.8409,52.27437,0,0,0,0,100,0);
-- 0x1C307C4B401BE9C000021700025672BB .go 1311.234 -158.9818 52.27496

DELETE FROM `creature_formations` WHERE `leaderGUID`=126954;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126954, 126954, 0, 0, 2, 0, 0),
(126954, 126955, 3, 0, 2, 0, 0);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 76296;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(762960, 1, 1176.14, -298.09, 52.3436, 0, 0, 0, 0, 100, 0),
(762960, 2, 1176.3, -246.576, 52.3528, 0, 0, 0, 0, 100, 0);

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 76297;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(762970, 1, 1180.57, -315.473, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 2, 1171.95, -315.333, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 3, 1171.02, -327.394, 52.6927, 0, 0, 0, 0, 100, 0),
(762970, 4, 1183.75, -330.38, 52.3378, 0, 0, 0, 0, 100, 0),
(762970, 5, 1183.62, -317.868, 52.3378, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `spawndist`=8,`MovementType`=1 WHERE `guid`=76298;
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=28547 AND `source_type`=0 AND `id`=0 AND `link`=0;

-- Pathing for  Entry: 28583 'TDB FORMAT' 
SET @NPC := 126874;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(1268740, 1, 1118.22, -248.207, 56.8882, 0, 0, 1, 0, 100, 0),
(1268740, 2, 1118.62, -274.988, 56.8831, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');

DELETE FROM `creature_addon` WHERE `guid` IN (126904, 126921, 126903, 126911, 126928, 126929, 126930, 126931, 126912);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(126911, 0, 0, 0, 1, 69, ''),
(126928, 0, 0, 0, 1, 69, ''),
(126929, 0, 0, 0, 1, 69, ''),
(126930, 0, 0, 0, 1, 69, ''),
(126931, 0, 0, 0, 1, 69, ''),
(126912, 0, 0, 0, 1, 69, ''),
(126903, 0, 0, 0, 1, 69, ''),
(126921, 0, 0, 0, 1, 69, ''),
(126904, 0, 0, 0, 1, 69, '');


UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=28838 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- Pathing for  Entry: 28838 'TDB FORMAT' 
SET @NPC := 126938;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1096.845,`position_y`=-166.1139,`position_z`=58.68692 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1096.845,-166.1139,58.68692,0,0,0,0,100,0),
(@PATH,2,1091.599,-152.8187,61.33255,0,0,0,0,100,0),
(@PATH,3,1076.235,-141.8798,61.18824,0,0,0,0,100,0),
(@PATH,4,1060.763,-145.9723,61.39173,0,0,0,0,100,0),
(@PATH,5,1049.471,-171.0271,58.53773,0,0,0,0,100,0),
(@PATH,6,1055.509,-189.0143,58.94555,0,0,0,0,100,0),
(@PATH,7,1073.278,-198.3343,59.91864,0,0,0,0,100,0),
(@PATH,8,1091.632,-153.0076,61.24912,0,0,0,0,100,0),
(@PATH,9,1076.185,-141.7971,61.18842,0,0,0,0,100,0),
(@PATH,10,1060.682,-145.9083,61.35257,0,0,0,0,100,0),
(@PATH,11,1049.497,-171.1528,58.5324,0,0,0,0,100,0),
(@PATH,12,1055.636,-188.8313,58.83115,0,0,0,0,100,0),
(@PATH,13,1073.335,-198.4241,59.88276,0,0,0,0,100,0),
(@PATH,14,1083.434,-195.9087,59.84556,0,0,0,0,100,0),
(@PATH,15,1095.76,-180.6208,58.73315,0,0,0,0,100,0),
(@PATH,16,1096.683,-166.0892,58.71755,0,0,0,0,100,0),
(@PATH,17,1091.595,-152.9597,61.3679,0,0,0,0,100,0),
(@PATH,18,1076.179,-141.7626,61.18819,0,0,0,0,100,0),
(@PATH,19,1060.637,-145.9161,61.39425,0,0,0,0,100,0),
(@PATH,20,1049.585,-171.0794,58.53699,0,0,0,0,100,0),
(@PATH,21,1055.467,-188.91,58.98404,0,0,0,0,100,0),
(@PATH,22,1073.328,-198.439,59.93514,0,0,0,0,100,0),
(@PATH,23,1083.423,-195.8686,59.93195,0,0,0,0,100,0),
(@PATH,24,1095.775,-180.6299,58.52916,0,0,0,0,100,0),
(@PATH,25,1096.451,-166.0939,58.80622,0,0,0,0,100,0),
(@PATH,26,1091.409,-152.9162,61.46411,0,0,0,0,100,0),
(@PATH,27,1076.1,-141.8916,61.18857,0,0,0,0,100,0),
(@PATH,28,1060.651,-145.9504,61.40473,0,0,0,0,100,0),
(@PATH,29,1049.581,-171.0241,58.53423,0,0,0,0,100,0),
(@PATH,30,1055.498,-188.95,59.02743,0,0,0,0,100,0),
(@PATH,31,1073.29,-198.3899,60.07246,0,0,0,0,100,0),
(@PATH,32,1083.527,-195.7341,59.79642,0,0,0,0,100,0),
(@PATH,33,1095.63,-180.5483,58.69926,0,0,0,0,100,0),
(@PATH,34,1096.488,-165.9498,58.67723,0,0,0,0,100,0),
(@PATH,35,1091.622,-152.8619,61.2616,0,0,0,0,100,0),
(@PATH,36,1076.115,-141.9001,61.18835,0,0,0,0,100,0),
(@PATH,37,1060.789,-145.8449,61.36668,0,0,0,0,100,0),
(@PATH,38,1049.622,-171.201,58.53172,0,0,0,0,100,0),
(@PATH,39,1055.608,-188.9287,58.85689,0,0,0,0,100,0),
(@PATH,40,1073.355,-198.4655,59.88638,0,0,0,0,100,0),
(@PATH,41,1083.45,-195.9156,59.8475,0,0,0,0,100,0),
(@PATH,42,1095.778,-180.6123,58.73478,0,0,0,0,100,0),
(@PATH,43,1096.679,-166.0957,58.71638,0,0,0,0,100,0),
(@PATH,44,1091.597,-152.9846,61.35995,0,0,0,0,100,0),
(@PATH,45,1076.191,-141.7885,61.1882,0,0,0,0,100,0),
(@PATH,46,1060.679,-145.9348,61.39341,0,0,0,0,100,0),
(@PATH,47,1049.618,-171.0668,58.53717,0,0,0,0,100,0),
(@PATH,48,1055.49,-188.8295,58.96278,0,0,0,0,100,0),
(@PATH,49,1073.294,-198.3665,59.92146,0,0,0,0,100,0),
(@PATH,50,1083.419,-195.9023,59.84375,0,0,0,0,100,0),
(@PATH,51,1095.709,-180.6607,58.52328,0,0,0,0,100,0),
(@PATH,52,1096.673,-166.108,58.71417,0,0,0,0,100,0),
(@PATH,53,1091.596,-152.9702,61.36453,0,0,0,0,100,0),
(@PATH,54,1076.134,-141.7107,61.1886,0,0,0,0,100,0),
(@PATH,55,1060.718,-145.7299,61.40303,0,0,0,0,100,0),
(@PATH,56,1049.66,-170.9935,58.53466,0,0,0,0,100,0),
(@PATH,57,1055.598,-189.0659,59.09127,0,0,0,0,100,0),
(@PATH,58,1073.295,-198.3694,59.92171,0,0,0,0,100,0),
(@PATH,59,1083.648,-195.8578,59.9237,0,0,0,0,100,0),
(@PATH,60,1095.808,-180.5819,58.69283,0,0,0,0,100,0),
(@PATH,61,1096.681,-166.0555,58.68321,0,0,0,0,100,0),
(@PATH,62,1091.416,-153.0063,61.45639,0,0,0,0,100,0),
(@PATH,63,1076.171,-141.768,61.18841,0,0,0,0,100,0),
(@PATH,64,1060.65,-145.894,61.35575,0,0,0,0,100,0),
(@PATH,65,1049.462,-171.1664,58.5322,0,0,0,0,100,0),
(@PATH,66,1055.634,-188.8381,58.83295,0,0,0,0,100,0),
(@PATH,67,1073.464,-198.508,59.93453,0,0,0,0,100,0),
(@PATH,68,1083.448,-195.6998,59.78678,0,0,0,0,100,0),
(@PATH,69,1095.786,-180.5919,58.69092,0,0,0,0,100,0),
(@PATH,70,1096.673,-166.0698,58.68402,0,0,0,0,100,0),
(@PATH,71,1091.631,-152.9937,61.25031,0,0,0,0,100,0),
(@PATH,72,1076.178,-141.7825,61.18841,0,0,0,0,100,0),
(@PATH,73,1060.676,-145.9058,61.35313,0,0,0,0,100,0),
(@PATH,74,1049.458,-171.1682,58.53218,0,0,0,0,100,0),
(@PATH,75,1055.627,-188.8615,58.83912,0,0,0,0,100,0),
(@PATH,76,1070.503,-200.296,61.23225,0,0,0,0,100,0);
-- 0x1C16DC4B401C2980000A1E0001563CBC .go 1096.845 -166.1139 58.68692

DELETE FROM `creature_formations` WHERE `leaderGUID`=126938;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126938, 126938, 0, 0, 2, 0, 0),
(126938, 126937, 5, 90, 2, 0, 0);

-- Pathing for  Entry: 28838 'TDB FORMAT' 
SET @NPC := 126935;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1049.899,`position_y`=-99.5955,`position_z`=59.38226 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1049.899,-99.5955,59.38226,0,0,0,0,100,0),
(@PATH,2,1050.742,-83.34245,58.92643,0,0,0,0,100,0),
(@PATH,3,1055.898,-75.28898,59.04939,0,0,0,0,100,0),
(@PATH,4,1066.186,-64.55377,61.31993,0,0,0,0,100,0),
(@PATH,5,1083.335,-68.16859,59.77402,0,0,0,0,100,0),
(@PATH,6,1095.981,-92.44127,57.85799,0,0,0,0,100,0),
(@PATH,7,1097.756,-106.9242,61.43462,0,0,0,0,100,0),
(@PATH,8,1097.813,-109.0895,61.5177,0,0,0,0,100,0),
(@PATH,9,1073.511,-124.8458,61.22898,0,0,0,0,100,0),
(@PATH,10,1063.165,-119.7333,61.23046,0,0,0,0,100,0),
(@PATH,11,1052.941,-108.3153,61.3854,0,0,0,0,100,0);
-- 0x1C307C4B401C29800002170000D672BB .go 1049.899 -99.5955 59.38226

DELETE FROM `creature_formations` WHERE `leaderGUID`=126935;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126935, 126935, 0, 0, 2, 0, 0),
(126935, 126936, 5, 270, 2, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=29048;
UPDATE `creature` SET `spawndist`=40 WHERE `id`=29048;

-- Pathing for  Entry: 28835 'TDB FORMAT' 
SET @NPC := 126892;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1053.155,`position_y`=78.30748,`position_z`=61.44365 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1053.155,78.30748,61.44365,0,0,0,0,100,0),
(@PATH,2,1050.469,75.66108,61.44365,0,0,0,0,100,0),
(@PATH,3,1034.158,48.75368,59.26595,0,0,0,0,100,0),
(@PATH,4,1033.885,12.18762,61.27556,0,0,0,0,100,0),
(@PATH,5,1041.208,0.1274123,61.39244,0,0,0,0,100,0),
(@PATH,6,1052.702,-9.815857,61.43917,0,0,0,0,100,0),
(@PATH,7,1053.008,-10.01389,61.44186,0,0,0,0,100,0),
(@PATH,8,1041.027,0.347192,61.39876,0,0,0,0,100,0),
(@PATH,9,1032.457,20.25849,58.73366,0,0,0,0,100,0),
(@PATH,10,1050.469,75.66108,61.44365,0,0,0,0,100,0),
(@PATH,11,1034.158,48.75368,59.26595,0,0,0,0,100,0);
-- 0x1C307C4B401C28C000021700015672BB .go 1053.155 78.30748 61.44365

-- Pathing for  Entry: 28920 'TDB FORMAT' 
SET @NPC := 126984;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1098.968,`position_y`=19.55447,`position_z`=53.64101 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1098.968,19.55447,53.64101,0,0,0,0,100,0),
(@PATH,2,1080.878,7.88341,53.63377,0,0,0,0,100,0),
(@PATH,3,1066.863,12.70812,53.63047,0,0,0,0,100,0),
(@PATH,4,1078.049,8.259874,53.6311,0,0,0,0,100,0),
(@PATH,5,1091.877,12.4073,53.63206,0,0,0,0,100,0);
-- 0x1C307C4B401C3E0000021700005672BB .go 1098.968 19.55447 53.64101

-- Pathing for  Entry: 28920 'TDB FORMAT' 
SET @NPC := 126983;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1098.049,`position_y`=54.05235,`position_z`=53.65234 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1098.049,54.05235,53.65234,0,0,0,0,100,0),
(@PATH,2,1085.831,60.05393,53.65328,0,0,0,0,100,0),
(@PATH,3,1067.126,53.06633,53.64429,0,0,0,0,100,0),
(@PATH,4,1068.714,55.26102,53.64336,0,0,0,0,100,0),
(@PATH,5,1090.947,60.23857,53.65356,0,0,0,0,100,0),
(@PATH,6,1100.346,51.25973,53.65813,0,0,0,0,100,0);
-- 0x1C307C4B401C3E000002170000D672BB .go 1098.049 54.05235 53.65234
