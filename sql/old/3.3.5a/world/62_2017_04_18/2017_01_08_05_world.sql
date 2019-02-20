-- 
-- Shadowmoon Valley - The Fel Pits - Rework Spawns and Pathing
SET @GUIDSTART := 106360;  -- 110 creatures added / 66 creatures removed
SET @GUID := @GUIDSTART;

-- Enraged Fire Soul [-1|+0]
SET @ENTRY := 21097;
DELETE FROM `creature` WHERE `id`=@ENTRY;

-- Corrupted Fire Elemental [-2|+0]
SET @ENTRY := 21706;
DELETE FROM `creature` WHERE `id`=@ENTRY;

-- Enraged Fire Spirit [-26|+46]
SET @ENTRY := 21061;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=21061);
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID := @GUID + 0, @ENTRY, 530, 1, 0, 0, -3968.536, 1361.080, 41.27816, 0.70625500, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3963.216, 1303.419, 39.72447, 1.64708400, 300, 0, 0, 0, 0, 2), -- x + 1
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3884.351, 1303.794, 39.86781, 3.39144300, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3950.135, 1455.504, 39.72449, 0.34084400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3834.725, 1337.655, 40.10129, 0.57602490, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3883.372, 1264.323, 39.59035, 1.22603800, 300, 0, 0, 0, 0, 2), -- x + 5
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3866.720, 1401.258, 39.69121, 4.85331100, 300, 0, 0, 0, 0, 2), -- x + 6
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3819.414, 1477.472, 43.62658, 2.45591700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3854.826, 1443.303, 40.57096, 1.32574600, 300, 0, 0, 0, 0, 2), -- x + 8
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3873.481, 1528.284, 40.61100, 3.78045200, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3806.792, 1549.519, 37.98209, 0.42071370, 300, 0, 0, 0, 0, 2), -- x + 10
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3946.140, 1516.706, 40.21125, 0.98613250, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3752.961, 1479.470, 46.97700, 1.71976500, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3778.269, 1549.228, 45.32440, 5.32436800, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3710.817, 1516.760, 48.40620, 1.64676900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3718.244, 1584.411, 43.83197, 2.12660400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3733.802, 1617.507, 40.69199, 3.29347700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3634.643, 1514.704, 85.56610, 6.18828900, 300, 0, 0, 0, 0, 2), -- x + 17
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3655.402, 1558.273, 49.42381, 3.34238400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3692.613, 1653.045, 39.56059, 5.04861900, 300, 0, 0, 0, 0, 2), -- x + 19
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3763.165, 1651.651, 39.75420, 5.16300400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3753.688, 1685.946, 40.80269, 6.00020000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3677.914, 1739.522, 39.71070, 0.77572140, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3567.777, 1687.128, 39.19603, 0.58025940, 300, 0, 0, 0, 0, 2), -- x + 23
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3607.611, 1725.361, 39.64762, 1.57953800, 300, 0, 0, 0, 0, 2), -- x + 24
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3584.378, 1581.990, 47.31120, 1.26930000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3548.881, 1617.359, 45.93129, 2.45798000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3514.874, 1579.913, 46.95868, 2.13559500, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3512.374, 1657.086, 46.50841, 0.81237940, 300, 0, 0, 0, 0, 2), -- x + 28
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3422.720, 1584.403, 47.00019, 3.21533300, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3448.423, 1550.403, 46.91026, 2.47952500, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3386.554, 1724.774, 100.8920, 0.98422700, 300, 0, 0, 0, 0, 2), -- x + 31
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3361.977, 1668.255, 94.57737, 2.76240000, 300, 0, 0, 0, 0, 2), -- x + 32
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3425.414, 1771.370, 100.9127, 3.38890700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3408.992, 1804.676, 97.31487, 4.39471400, 300, 0, 0, 0, 0, 2), -- x + 34
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3362.607, 1591.451, 47.85078, 1.63152900, 300, 0, 0, 0, 0, 2), -- x + 35
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3399.757, 1549.373, 48.05845, 0.02931504, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3381.920, 1514.206, 52.11436, 5.40148400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3346.893, 1547.978, 52.42512, 0.51249250, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3244.677, 1583.898, 49.64318, 3.05806700, 300, 0, 0, 0, 0, 2), -- x + 39
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3266.770, 1516.685, 50.80831, 4.70469900, 300, 0, 0, 0, 0, 2), -- x + 40
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3261.721, 1358.507, 50.14167, 1.72787600, 300, 0, 0, 0, 0, 2), -- x + 41
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3291.019, 1545.251, 51.10376, 2.58186800, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3282.524, 1451.430, 50.74366, 2.22636100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3191.679, 1355.129, 5.919065, 6.24723900, 300, 0, 0, 0, 0, 2), -- x + 44
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3016.804, 1379.479, 11.47956, 3.46587800, 300, 0, 0, 0, 0, 2); -- x + 45

-- Spawn of Uvuros [-1|+3]
SET @ENTRY := 21108;
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3268.571, 1355.402, 49.62804, 1.117570, 300, 0, 0, 0, 0, 2), -- x + 46
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3412.071, 1773.265, 102.8363, 5.732968, 300, 0, 0, 0, 0, 2), -- x + 47
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3876.617, 1232.423, 44.13676, 1.803640, 300, 0, 0, 0, 0, 2); -- x + 48

-- Enraged Earthen Soul [-2|+0]
SET @ENTRY := 21073;
DELETE FROM `creature` WHERE `id`=@ENTRY;

-- Enraged Earth Shard [-2|+0]
SET @ENTRY := 22115;
DELETE FROM `creature` WHERE `id`=@ENTRY;

-- Enraged Earth Spirit [-26|+52]
SET @ENTRY := 21050;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=21050);
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3866.737, 1336.028, 42.74855, 2.14247500, 300, 0, 0, 0, 0, 2), -- x + 49
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3908.297, 1395.076, 43.21666, 0.11453480, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3842.790, 1281.757, 51.66577, 4.92514000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3960.711, 1276.084, 56.77777, 0.52832060, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3933.352, 1261.858, 54.75646, 4.07941600, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3814.530, 1248.937, 78.71390, 6.01852500, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3878.596, 1180.443, 72.48586, 2.53072700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3741.470, 1281.555, 113.8274, 3.28419700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3996.543, 1337.669, 81.56582, 3.72117100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -4005.849, 1462.696, 92.27657, 6.18035600, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3902.121, 1516.603, 43.03911, 3.53872900, 300, 0, 0, 0, 0, 2), -- x + 59
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3968.619, 1563.531, 66.14909, 0.20553990, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3961.449, 1641.886, 90.49254, 1.10937400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3883.597, 1587.640, 81.93299, 4.34950700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3879.770, 1645.156, 84.84524, 5.43915200, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3819.025, 1653.583, 74.85554, 4.49788900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3814.047, 1717.877, 93.48297, 2.57838800, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3867.834, 1732.107, 101.7153, 4.01071900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3749.210, 1753.942, 83.42970, 5.96162800, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3750.264, 1813.892, 89.68528, 2.48003300, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3686.873, 1699.504, 40.89808, 2.73184800, 300, 0, 0, 0, 0, 2), -- x + 69
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3714.731, 1818.344, 76.98749, 4.29815900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3659.335, 1756.456, 40.78264, 4.51790400, 300, 0, 0, 0, 0, 2), -- x + 71
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3710.710, 1879.895, 91.27804, 4.32893600, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3747.350, 1896.423, 104.9478, 0.70170860, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3658.188, 1846.846, 61.83801, 0.71981790, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3526.231, 1923.227, 76.36613, 2.50152300, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3513.701, 1870.485, 86.74851, 3.29156400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3505.914, 1821.854, 92.69957, 2.87824100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3466.111, 1809.786, 103.9440, 6.22427100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3348.607, 1750.611, 101.4064, 0.83170590, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3418.536, 1716.530, 106.6131, 2.20875100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3328.624, 1641.063, 89.89996, 2.59388900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3286.542, 1686.468, 75.64011, 0.36694600, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3417.779, 1652.075, 111.6684, 3.50989100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3217.031, 1614.583, 70.61845, 2.13346100, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3181.773, 1512.901, 61.22135, 2.29262400, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3234.644, 1496.701, 53.61910, 2.07510800, 300, 0, 0, 0, 0, 2), -- x + 86
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3079.578, 1456.178, 14.04403, 6.10865200, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3186.007, 1480.489, 55.14701, 4.98156500, 300, 0, 0, 0, 0, 2), -- x + 88
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3084.113, 1384.975, 9.918798, 0.10219530, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3149.645, 1385.471, 12.66104, 5.95624200, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3182.702, 1314.611, 23.52866, 0.46801560, 300, 0, 0, 0, 0, 2), -- x + 91
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3254.076, 1315.386, 66.96973, 4.71238900, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3333.872, 1488.855, 60.61049, 1.52830300, 300, 0, 0, 0, 0, 2), -- x + 93
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3473.865, 1639.244, 53.92172, 1.46985300, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3593.993, 1643.338, 42.15769, 1.66699000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3523.989, 1697.715, 57.57351, 1.24426000, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3585.892, 1736.058, 40.88088, 4.44222700, 300, 0, 0, 0, 0, 2), -- x + 97
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3685.642, 1614.460, 42.17778, 0.56657210, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3768.278, 1611.409, 42.06032, 1.76326700, 300, 5, 0, 0, 0, 1),
(@GUID := @GUID + 1, @ENTRY, 530, 1, 0, 0, -3833.012, 1561.892, 42.23775, 5.18968500, 300, 0, 0, 0, 0, 2); -- x + 100

-- -----------------------------------
-- PATHING
-- -----------------------------------

DELETE FROM `waypoint_data` WHERE `id` IN (740090, 740100, 740110, 740120, 740130, 740160, 740210, 740250, 740280, 740290, 740300, 740310, 740330);
DELETE FROM `creature_addon` WHERE  `guid`=74142;
DELETE FROM `waypoint_data` WHERE `id` IN (741420);
DELETE FROM `waypoint_data` WHERE `id` IN (739290, 739310, 739370);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 1;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3966.661, 1348.314, 39.68160, 0),
(@PATH, @POINT := @POINT + 1, -3982.043, 1362.629, 39.71037, 0),
(@PATH, @POINT := @POINT + 1, -3993.894, 1368.137, 39.70597, 0),
(@PATH, @POINT := @POINT + 1, -4024.098, 1350.256, 37.81841, 0),
(@PATH, @POINT := @POINT + 1, -4047.619, 1336.134, 39.98072, 0),
(@PATH, @POINT := @POINT + 1, -4068.789, 1317.866, 41.59033, 0),
(@PATH, @POINT := @POINT + 1, -4047.619, 1336.134, 39.98072, 0),
(@PATH, @POINT := @POINT + 1, -4024.098, 1350.256, 37.81841, 0),
(@PATH, @POINT := @POINT + 1, -3993.894, 1368.137, 39.70597, 0),
(@PATH, @POINT := @POINT + 1, -3982.214, 1362.787, 39.71037, 0),
(@PATH, @POINT := @POINT + 1, -3966.661, 1348.314, 39.68160, 0),
(@PATH, @POINT := @POINT + 1, -3963.918, 1305.338, 39.68935, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 5;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3877.228, 1281.433, 39.52972, 0),
(@PATH, @POINT := @POINT + 1, -3864.557, 1301.940, 39.75750, 0),
(@PATH, @POINT := @POINT + 1, -3851.966, 1308.705, 39.75750, 0),
(@PATH, @POINT := @POINT + 1, -3844.692, 1333.741, 39.85207, 0),
(@PATH, @POINT := @POINT + 1, -3848.119, 1362.103, 40.78005, 0),
(@PATH, @POINT := @POINT + 1, -3841.732, 1375.505, 40.30152, 0),
(@PATH, @POINT := @POINT + 1, -3843.752, 1397.419, 39.35426, 0),
(@PATH, @POINT := @POINT + 1, -3843.176, 1421.318, 39.29580, 0),
(@PATH, @POINT := @POINT + 1, -3843.778, 1397.466, 39.18543, 0),
(@PATH, @POINT := @POINT + 1, -3841.732, 1375.505, 40.30152, 0),
(@PATH, @POINT := @POINT + 1, -3848.119, 1362.103, 40.78005, 0),
(@PATH, @POINT := @POINT + 1, -3844.692, 1333.741, 39.85207, 0),
(@PATH, @POINT := @POINT + 1, -3851.966, 1308.705, 39.75750, 0),
(@PATH, @POINT := @POINT + 1, -3864.557, 1301.940, 39.75750, 0),
(@PATH, @POINT := @POINT + 1, -3877.228, 1281.433, 39.52972, 0),
(@PATH, @POINT := @POINT + 1, -3884.200, 1265.161, 39.60587, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 6;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3862.637, 1372.648, 41.00941, 0),
(@PATH, @POINT := @POINT + 1, -3851.491, 1361.881, 40.48562, 0),
(@PATH, @POINT := @POINT + 1, -3844.906, 1341.203, 39.97707, 0),
(@PATH, @POINT := @POINT + 1, -3849.517, 1313.437, 39.70293, 0),
(@PATH, @POINT := @POINT + 1, -3862.557, 1305.086, 39.75750, 0),
(@PATH, @POINT := @POINT + 1, -3849.517, 1313.437, 39.70293, 0),
(@PATH, @POINT := @POINT + 1, -3844.906, 1341.203, 39.97707, 0),
(@PATH, @POINT := @POINT + 1, -3851.491, 1361.881, 40.48562, 0),
(@PATH, @POINT := @POINT + 1, -3862.637, 1372.648, 41.00941, 0),
(@PATH, @POINT := @POINT + 1, -3865.949, 1398.294, 40.02015, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 8;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3851.612, 1456.155, 39.94035, 0),
(@PATH, @POINT := @POINT + 1, -3846.642, 1464.607, 38.85209, 0),
(@PATH, @POINT := @POINT + 1, -3850.096, 1476.015, 39.08060, 0),
(@PATH, @POINT := @POINT + 1, -3859.760, 1492.439, 40.22611, 0),
(@PATH, @POINT := @POINT + 1, -3871.936, 1501.833, 40.14218, 0),
(@PATH, @POINT := @POINT + 1, -3885.933, 1498.914, 40.64204, 0),
(@PATH, @POINT := @POINT + 1, -3895.244, 1496.856, 39.95760, 0),
(@PATH, @POINT := @POINT + 1, -3885.933, 1498.914, 40.64204, 0),
(@PATH, @POINT := @POINT + 1, -3871.936, 1501.833, 40.14218, 0),
(@PATH, @POINT := @POINT + 1, -3859.760, 1492.439, 40.22611, 0),
(@PATH, @POINT := @POINT + 1, -3850.096, 1476.015, 39.08060, 0),
(@PATH, @POINT := @POINT + 1, -3846.642, 1464.607, 38.85209, 0),
(@PATH, @POINT := @POINT + 1, -3851.612, 1456.155, 39.94035, 0),
(@PATH, @POINT := @POINT + 1, -3856.105, 1444.823, 40.58195, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 10;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3798.786, 1553.103, 36.26998, 0),
(@PATH, @POINT := @POINT + 1, -3792.497, 1560.754, 34.90401, 0),
(@PATH, @POINT := @POINT + 1, -3791.767, 1579.444, 37.74704, 0),
(@PATH, @POINT := @POINT + 1, -3802.113, 1584.761, 38.04142, 0),
(@PATH, @POINT := @POINT + 1, -3820.368, 1576.584, 39.42118, 0),
(@PATH, @POINT := @POINT + 1, -3848.582, 1577.911, 39.91356, 0),
(@PATH, @POINT := @POINT + 1, -3855.335, 1561.266, 40.34032, 0),
(@PATH, @POINT := @POINT + 1, -3863.603, 1549.112, 39.87230, 0),
(@PATH, @POINT := @POINT + 1, -3869.726, 1525.698, 40.40732, 0),
(@PATH, @POINT := @POINT + 1, -3878.041, 1514.083, 39.96201, 0),
(@PATH, @POINT := @POINT + 1, -3869.726, 1525.698, 40.40732, 0),
(@PATH, @POINT := @POINT + 1, -3863.603, 1549.112, 39.87230, 0),
(@PATH, @POINT := @POINT + 1, -3855.335, 1561.266, 40.34032, 0),
(@PATH, @POINT := @POINT + 1, -3848.582, 1577.911, 39.91356, 0),
(@PATH, @POINT := @POINT + 1, -3820.368, 1576.584, 39.42118, 0),
(@PATH, @POINT := @POINT + 1, -3802.113, 1584.761, 38.04142, 0),
(@PATH, @POINT := @POINT + 1, -3791.767, 1579.444, 37.74704, 0),
(@PATH, @POINT := @POINT + 1, -3792.497, 1560.754, 34.90401, 0),
(@PATH, @POINT := @POINT + 1, -3798.786, 1553.103, 36.26998, 0),
(@PATH, @POINT := @POINT + 1, -3809.915, 1546.029, 38.62252, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 17;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3613.111, 1512.661, 84.76304, 0),
(@PATH, @POINT := @POINT + 1, -3636.142, 1513.880, 85.33750, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 19;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3685.122, 1631.567, 41.32896, 0),
(@PATH, @POINT := @POINT + 1, -3674.267, 1609.299, 42.86021, 0),
(@PATH, @POINT := @POINT + 1, -3655.034, 1594.121, 44.64022, 0),
(@PATH, @POINT := @POINT + 1, -3674.267, 1609.299, 42.86021, 0),
(@PATH, @POINT := @POINT + 1, -3685.122, 1631.567, 41.32896, 0),
(@PATH, @POINT := @POINT + 1, -3690.860, 1660.168, 39.37911, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 23;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3556.126, 1694.759, 40.17222, 0),
(@PATH, @POINT := @POINT + 1, -3562.115, 1708.797, 39.73536, 0),
(@PATH, @POINT := @POINT + 1, -3562.772, 1727.675, 39.86036, 0),
(@PATH, @POINT := @POINT + 1, -3562.615, 1747.675, 38.67850, 0),
(@PATH, @POINT := @POINT + 1, -3569.429, 1761.298, 39.56737, 0),
(@PATH, @POINT := @POINT + 1, -3579.794, 1773.608, 39.10586, 0),
(@PATH, @POINT := @POINT + 1, -3582.570, 1780.497, 39.32803, 0),
(@PATH, @POINT := @POINT + 1, -3577.259, 1787.475, 39.98086, 0),
(@PATH, @POINT := @POINT + 1, -3564.290, 1794.507, 39.65005, 0),
(@PATH, @POINT := @POINT + 1, -3577.259, 1787.475, 39.98086, 0),
(@PATH, @POINT := @POINT + 1, -3582.570, 1780.497, 39.32803, 0),
(@PATH, @POINT := @POINT + 1, -3579.794, 1773.608, 39.10586, 0),
(@PATH, @POINT := @POINT + 1, -3569.429, 1761.298, 39.56737, 0),
(@PATH, @POINT := @POINT + 1, -3562.604, 1747.943, 38.51286, 0),
(@PATH, @POINT := @POINT + 1, -3562.772, 1727.675, 39.86036, 0),
(@PATH, @POINT := @POINT + 1, -3562.115, 1708.797, 39.73536, 0),
(@PATH, @POINT := @POINT + 1, -3556.126, 1694.759, 40.17222, 0),
(@PATH, @POINT := @POINT + 1, -3565.220, 1683.332, 39.21604, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 24;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3607.786, 1745.441, 39.73397, 0),
(@PATH, @POINT := @POINT + 1, -3610.059, 1758.763, 39.10897, 0),
(@PATH, @POINT := @POINT + 1, -3606.948, 1779.317, 39.82947, 0),
(@PATH, @POINT := @POINT + 1, -3603.752, 1794.376, 39.74744, 0),
(@PATH, @POINT := @POINT + 1, -3616.517, 1802.796, 39.86226, 0),
(@PATH, @POINT := @POINT + 1, -3629.782, 1803.063, 39.58028, 0),
(@PATH, @POINT := @POINT + 1, -3644.492, 1797.165, 39.72593, 0),
(@PATH, @POINT := @POINT + 1, -3657.183, 1788.322, 39.72593, 0),
(@PATH, @POINT := @POINT + 1, -3663.814, 1778.259, 39.72593, 0),
(@PATH, @POINT := @POINT + 1, -3657.183, 1788.322, 39.72593, 0),
(@PATH, @POINT := @POINT + 1, -3644.492, 1797.165, 39.72593, 0),
(@PATH, @POINT := @POINT + 1, -3629.782, 1803.063, 39.58028, 0),
(@PATH, @POINT := @POINT + 1, -3616.517, 1802.796, 39.86226, 0),
(@PATH, @POINT := @POINT + 1, -3603.752, 1794.376, 39.74744, 0),
(@PATH, @POINT := @POINT + 1, -3606.948, 1779.317, 39.82947, 0),
(@PATH, @POINT := @POINT + 1, -3610.059, 1758.763, 39.10897, 0),
(@PATH, @POINT := @POINT + 1, -3607.786, 1745.441, 39.73397, 0),
(@PATH, @POINT := @POINT + 1, -3608.346, 1725.416, 39.56675, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 28;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3495.523, 1674.854, 54.05362, 0),
(@PATH, @POINT := @POINT + 1, -3490.152, 1696.188, 64.45596, 0),
(@PATH, @POINT := @POINT + 1, -3475.687, 1716.370, 72.83356, 0),
(@PATH, @POINT := @POINT + 1, -3459.085, 1730.499, 83.66209, 0),
(@PATH, @POINT := @POINT + 1, -3435.279, 1746.453, 98.65145, 0),
(@PATH, @POINT := @POINT + 1, -3459.085, 1730.499, 83.66209, 0),
(@PATH, @POINT := @POINT + 1, -3475.687, 1716.370, 72.83356, 0),
(@PATH, @POINT := @POINT + 1, -3490.157, 1696.191, 64.40372, 0),
(@PATH, @POINT := @POINT + 1, -3495.523, 1674.854, 54.05362, 0),
(@PATH, @POINT := @POINT + 1, -3509.487, 1658.060, 46.64849, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 31;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3377.245, 1738.781, 100.8844, 0),
(@PATH, @POINT := @POINT + 1, -3379.829, 1753.055, 100.9325, 0),
(@PATH, @POINT := @POINT + 1, -3387.415, 1755.659, 101.1016, 0),
(@PATH, @POINT := @POINT + 1, -3379.829, 1753.055, 100.9325, 0),
(@PATH, @POINT := @POINT + 1, -3377.245, 1738.781, 100.8844, 0),
(@PATH, @POINT := @POINT + 1, -3390.743, 1719.957, 100.9751, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 32;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3376.523, 1674.045, 98.72786, 0),
(@PATH, @POINT := @POINT + 1, -3394.130, 1688.848, 99.74837, 0),
(@PATH, @POINT := @POINT + 1, -3392.110, 1711.657, 101.1825, 0),
(@PATH, @POINT := @POINT + 1, -3394.130, 1688.848, 99.74837, 0),
(@PATH, @POINT := @POINT + 1, -3376.523, 1674.045, 98.72786, 0),
(@PATH, @POINT := @POINT + 1, -3361.519, 1669.541, 94.49751, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 34;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3413.367, 1791.373, 99.69798, 0),
(@PATH, @POINT := @POINT + 1, -3431.269, 1793.322, 100.5617, 0),
(@PATH, @POINT := @POINT + 1, -3438.707, 1784.378, 100.8168, 0),
(@PATH, @POINT := @POINT + 1, -3440.137, 1772.868, 100.8836, 0),
(@PATH, @POINT := @POINT + 1, -3430.415, 1756.091, 100.8905, 0),
(@PATH, @POINT := @POINT + 1, -3440.137, 1772.868, 100.8836, 0),
(@PATH, @POINT := @POINT + 1, -3438.707, 1784.378, 100.8168, 0),
(@PATH, @POINT := @POINT + 1, -3431.269, 1793.322, 100.5617, 0),
(@PATH, @POINT := @POINT + 1, -3413.411, 1791.203, 99.76389, 0),
(@PATH, @POINT := @POINT + 1, -3409.603, 1803.208, 97.50513, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 35;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3364.697, 1625.718, 67.45491, 0),
(@PATH, @POINT := @POINT + 1, -3358.170, 1645.251, 78.26536, 0),
(@PATH, @POINT := @POINT + 1, -3355.514, 1662.498, 90.43528, 0),
(@PATH, @POINT := @POINT + 1, -3358.170, 1645.251, 78.26536, 0),
(@PATH, @POINT := @POINT + 1, -3364.697, 1625.718, 67.45491, 0),
(@PATH, @POINT := @POINT + 1, -3363.971, 1594.718, 47.73098, 0),
(@PATH, @POINT := @POINT + 1, -3364.697, 1625.718, 67.14265, 0),
(@PATH, @POINT := @POINT + 1, -3358.170, 1645.251, 78.26536, 0),
(@PATH, @POINT := @POINT + 1, -3355.514, 1662.498, 90.43528, 0),
(@PATH, @POINT := @POINT + 1, -3358.170, 1645.251, 78.26536, 0),
(@PATH, @POINT := @POINT + 1, -3364.697, 1625.718, 67.45491, 0),
(@PATH, @POINT := @POINT + 1, -3363.971, 1594.718, 47.73098, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 39;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3270.670, 1586.074, 50.19849, 0),
(@PATH, @POINT := @POINT + 1, -3292.600, 1586.784, 50.24732, 0),
(@PATH, @POINT := @POINT + 1, -3317.282, 1592.559, 49.21576, 0),
(@PATH, @POINT := @POINT + 1, -3318.112, 1582.750, 49.43244, 0),
(@PATH, @POINT := @POINT + 1, -3301.980, 1578.054, 49.78742, 0),
(@PATH, @POINT := @POINT + 1, -3301.512, 1564.927, 50.64901, 0),
(@PATH, @POINT := @POINT + 1, -3316.518, 1554.231, 50.29134, 0),
(@PATH, @POINT := @POINT + 1, -3304.758, 1542.962, 49.04280, 0),
(@PATH, @POINT := @POINT + 1, -3272.580, 1544.624, 50.71184, 0),
(@PATH, @POINT := @POINT + 1, -3276.326, 1555.708, 51.05583, 0),
(@PATH, @POINT := @POINT + 1, -3267.039, 1567.807, 51.15406, 0),
(@PATH, @POINT := @POINT + 1, -3250.104, 1571.737, 51.06451, 0),
(@PATH, @POINT := @POINT + 1, -3242.369, 1579.531, 50.58331, 0),
(@PATH, @POINT := @POINT + 1, -3251.172, 1585.850, 49.27813, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 40;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3266.944, 1495.482, 50.70709, 0),
(@PATH, @POINT := @POINT + 1, -3260.746, 1475.659, 51.25534, 0),
(@PATH, @POINT := @POINT + 1, -3242.165, 1471.615, 49.59628, 0),
(@PATH, @POINT := @POINT + 1, -3218.661, 1475.549, 47.78694, 0),
(@PATH, @POINT := @POINT + 1, -3213.801, 1500.323, 48.97348, 0),
(@PATH, @POINT := @POINT + 1, -3224.212, 1521.493, 49.84909, 0),
(@PATH, @POINT := @POINT + 1, -3213.801, 1500.323, 48.97348, 0),
(@PATH, @POINT := @POINT + 1, -3218.661, 1475.549, 47.78694, 0),
(@PATH, @POINT := @POINT + 1, -3242.165, 1471.615, 49.59628, 0),
(@PATH, @POINT := @POINT + 1, -3260.746, 1475.659, 51.25534, 0),
(@PATH, @POINT := @POINT + 1, -3266.944, 1495.482, 50.70709, 0),
(@PATH, @POINT := @POINT + 1, -3265.549, 1516.259, 50.79179, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 41;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3270.971, 1376.588, 50.29376, 0),
(@PATH, @POINT := @POINT + 1, -3280.325, 1397.854, 51.23919, 0),
(@PATH, @POINT := @POINT + 1, -3289.615, 1434.420, 50.68203, 0),
(@PATH, @POINT := @POINT + 1, -3280.579, 1453.911, 50.48915, 0),
(@PATH, @POINT := @POINT + 1, -3265.446, 1437.963, 50.94470, 0),
(@PATH, @POINT := @POINT + 1, -3258.100, 1414.249, 49.12197, 0),
(@PATH, @POINT := @POINT + 1, -3264.547, 1392.286, 51.29313, 0),
(@PATH, @POINT := @POINT + 1, -3252.828, 1368.444, 49.72086, 0),
(@PATH, @POINT := @POINT + 1, -3250.914, 1354.164, 51.24254, 0),
(@PATH, @POINT := @POINT + 1, -3258.653, 1355.439, 50.72826, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 44;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3182.042, 1354.782, 5.891076, 0),
(@PATH, @POINT := @POINT + 1, -3174.273, 1361.083, 6.436242, 0),
(@PATH, @POINT := @POINT + 1, -3164.761, 1357.554, 7.730681, 0),
(@PATH, @POINT := @POINT + 1, -3157.927, 1345.460, 9.404876, 0),
(@PATH, @POINT := @POINT + 1, -3144.306, 1336.979, 7.899871, 0),
(@PATH, @POINT := @POINT + 1, -3129.863, 1332.921, 12.63351, 0),
(@PATH, @POINT := @POINT + 1, -3119.914, 1331.117, 13.21066, 0),
(@PATH, @POINT := @POINT + 1, -3105.562, 1328.574, 5.339685, 0),
(@PATH, @POINT := @POINT + 1, -3090.967, 1322.019, 3.507803, 0),
(@PATH, @POINT := @POINT + 1, -3078.913, 1318.775, 2.916128, 0),
(@PATH, @POINT := @POINT + 1, -3090.967, 1322.019, 3.507803, 0),
(@PATH, @POINT := @POINT + 1, -3105.562, 1328.574, 5.339685, 0),
(@PATH, @POINT := @POINT + 1, -3119.914, 1331.117, 13.21066, 0),
(@PATH, @POINT := @POINT + 1, -3129.732, 1332.891, 12.60800, 0),
(@PATH, @POINT := @POINT + 1, -3144.306, 1336.979, 7.899871, 0),
(@PATH, @POINT := @POINT + 1, -3157.927, 1345.460, 9.404876, 0),
(@PATH, @POINT := @POINT + 1, -3164.761, 1357.554, 7.730681, 0),
(@PATH, @POINT := @POINT + 1, -3174.273, 1361.083, 6.436242, 0),
(@PATH, @POINT := @POINT + 1, -3182.042, 1354.782, 5.891076, 0),
(@PATH, @POINT := @POINT + 1, -3192.773, 1354.919, 5.891076, 0);

-- Enraged Fire Spirit
SET @NPC := @GUIDSTART + 45;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3029.917, 1375.073, 8.104202, 0),
(@PATH, @POINT := @POINT + 1, -3038.843, 1369.191, 6.326932, 0),
(@PATH, @POINT := @POINT + 1, -3050.946, 1376.182, 6.012967, 0),
(@PATH, @POINT := @POINT + 1, -3055.799, 1393.589, 5.339383, 0),
(@PATH, @POINT := @POINT + 1, -3049.967, 1404.723, 5.382828, 0),
(@PATH, @POINT := @POINT + 1, -3044.835, 1416.556, 6.239396, 0),
(@PATH, @POINT := @POINT + 1, -3039.312, 1433.172, 5.309830, 0),
(@PATH, @POINT := @POINT + 1, -3036.245, 1451.358, 6.765009, 0),
(@PATH, @POINT := @POINT + 1, -3028.730, 1468.617, 7.079117, 0),
(@PATH, @POINT := @POINT + 1, -3036.245, 1451.358, 6.765009, 0),
(@PATH, @POINT := @POINT + 1, -3039.312, 1433.172, 5.309830, 0),
(@PATH, @POINT := @POINT + 1, -3044.835, 1416.556, 6.239396, 0),
(@PATH, @POINT := @POINT + 1, -3049.967, 1404.723, 5.382828, 0),
(@PATH, @POINT := @POINT + 1, -3055.799, 1393.589, 5.339383, 0),
(@PATH, @POINT := @POINT + 1, -3050.946, 1376.182, 6.012967, 0),
(@PATH, @POINT := @POINT + 1, -3038.843, 1369.191, 6.326932, 0),
(@PATH, @POINT := @POINT + 1, -3029.917, 1375.073, 8.104202, 0),
(@PATH, @POINT := @POINT + 1, -3013.523, 1380.948, 11.48164, 0);

-- Spawn of Uvuros
SET @NPC := @GUIDSTART + 46;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3261.052, 1370.817, 50.43204, 0),
(@PATH, @POINT := @POINT + 1, -3259.591, 1396.251, 51.30545, 0),
(@PATH, @POINT := @POINT + 1, -3260.267, 1417.615, 49.94558, 0),
(@PATH, @POINT := @POINT + 1, -3268.925, 1438.428, 50.73915, 0),
(@PATH, @POINT := @POINT + 1, -3277.157, 1454.070, 50.79006, 0),
(@PATH, @POINT := @POINT + 1, -3273.442, 1469.771, 50.80280, 0),
(@PATH, @POINT := @POINT + 1, -3268.631, 1489.467, 50.80280, 0),
(@PATH, @POINT := @POINT + 1, -3265.457, 1513.454, 50.52824, 0),
(@PATH, @POINT := @POINT + 1, -3268.582, 1547.500, 50.79436, 0),
(@PATH, @POINT := @POINT + 1, -3292.102, 1569.630, 51.72522, 0),
(@PATH, @POINT := @POINT + 1, -3312.658, 1583.314, 48.13527, 0),
(@PATH, @POINT := @POINT + 1, -3331.849, 1587.753, 52.29828, 0),
(@PATH, @POINT := @POINT + 1, -3351.814, 1591.260, 51.01516, 0),
(@PATH, @POINT := @POINT + 1, -3376.521, 1590.513, 48.12061, 0),
(@PATH, @POINT := @POINT + 1, -3401.154, 1591.178, 46.47407, 0),
(@PATH, @POINT := @POINT + 1, -3418.478, 1593.764, 46.80402, 0),
(@PATH, @POINT := @POINT + 1, -3438.720, 1598.961, 46.00710, 0),
(@PATH, @POINT := @POINT + 1, -3459.175, 1607.099, 44.76759, 0),
(@PATH, @POINT := @POINT + 1, -3477.656, 1618.874, 43.46716, 0),
(@PATH, @POINT := @POINT + 1, -3493.255, 1634.055, 43.22388, 0),
(@PATH, @POINT := @POINT + 1, -3506.059, 1646.729, 45.10381, 0),
(@PATH, @POINT := @POINT + 1, -3520.908, 1661.742, 45.64239, 0),
(@PATH, @POINT := @POINT + 1, -3540.830, 1677.818, 41.02866, 0),
(@PATH, @POINT := @POINT + 1, -3554.971, 1691.269, 40.24473, 0),
(@PATH, @POINT := @POINT + 1, -3562.589, 1703.800, 39.84192, 0),
(@PATH, @POINT := @POINT + 1, -3566.669, 1722.530, 39.90781, 0),
(@PATH, @POINT := @POINT + 1, -3567.719, 1741.610, 39.81187, 0),
(@PATH, @POINT := @POINT + 1, -3574.672, 1753.050, 39.81737, 0),
(@PATH, @POINT := @POINT + 1, -3583.069, 1759.762, 39.94237, 0),
(@PATH, @POINT := @POINT + 1, -3595.444, 1760.937, 40.31737, 0),
(@PATH, @POINT := @POINT + 1, -3615.263, 1759.552, 39.35897, 0),
(@PATH, @POINT := @POINT + 1, -3637.424, 1757.551, 40.38606, 0),
(@PATH, @POINT := @POINT + 1, -3662.133, 1747.172, 40.81453, 0),
(@PATH, @POINT := @POINT + 1, -3679.094, 1731.953, 39.74870, 0),
(@PATH, @POINT := @POINT + 1, -3700.690, 1712.346, 40.11227, 0),
(@PATH, @POINT := @POINT + 1, -3720.564, 1700.168, 39.88595, 0),
(@PATH, @POINT := @POINT + 1, -3741.941, 1695.867, 40.08457, 0),
(@PATH, @POINT := @POINT + 1, -3761.721, 1690.102, 39.73850, 0),
(@PATH, @POINT := @POINT + 1, -3776.717, 1684.102, 42.48848, 0),
(@PATH, @POINT := @POINT + 1, -3782.882, 1667.605, 44.21590, 0),
(@PATH, @POINT := @POINT + 1, -3777.177, 1651.166, 40.49483, 0),
(@PATH, @POINT := @POINT + 1, -3763.309, 1632.191, 40.09911, 0),
(@PATH, @POINT := @POINT + 1, -3735.632, 1624.778, 39.02733, 0),
(@PATH, @POINT := @POINT + 1, -3708.306, 1623.589, 40.79650, 0),
(@PATH, @POINT := @POINT + 1, -3682.398, 1614.112, 42.12840, 0),
(@PATH, @POINT := @POINT + 1, -3642.329, 1607.818, 43.93411, 0),
(@PATH, @POINT := @POINT + 1, -3622.813, 1613.005, 44.44532, 0),
(@PATH, @POINT := @POINT + 1, -3597.527, 1619.549, 44.18061, 0),
(@PATH, @POINT := @POINT + 1, -3581.189, 1613.882, 45.11066, 0),
(@PATH, @POINT := @POINT + 1, -3555.823, 1619.289, 44.40530, 0),
(@PATH, @POINT := @POINT + 1, -3534.210, 1619.247, 45.11855, 0),
(@PATH, @POINT := @POINT + 1, -3514.888, 1596.725, 45.30498, 0),
(@PATH, @POINT := @POINT + 1, -3490.427, 1582.333, 46.29775, 0),
(@PATH, @POINT := @POINT + 1, -3468.826, 1584.601, 47.17080, 0),
(@PATH, @POINT := @POINT + 1, -3444.473, 1562.420, 46.86129, 0),
(@PATH, @POINT := @POINT + 1, -3425.052, 1548.150, 47.58210, 0),
(@PATH, @POINT := @POINT + 1, -3406.093, 1541.807, 48.58210, 0),
(@PATH, @POINT := @POINT + 1, -3383.017, 1535.272, 49.26402, 0),
(@PATH, @POINT := @POINT + 1, -3348.572, 1526.081, 52.90599, 0),
(@PATH, @POINT := @POINT + 1, -3330.415, 1513.742, 53.77206, 0),
(@PATH, @POINT := @POINT + 1, -3316.707, 1496.823, 50.89009, 0),
(@PATH, @POINT := @POINT + 1, -3302.981, 1475.289, 49.69674, 0),
(@PATH, @POINT := @POINT + 1, -3295.732, 1450.932, 49.38251, 0),
(@PATH, @POINT := @POINT + 1, -3292.761, 1433.665, 50.58071, 0),
(@PATH, @POINT := @POINT + 1, -3287.547, 1413.096, 49.76452, 0),
(@PATH, @POINT := @POINT + 1, -3283.492, 1396.401, 51.95086, 0),
(@PATH, @POINT := @POINT + 1, -3283.792, 1368.525, 49.50677, 0),
(@PATH, @POINT := @POINT + 1, -3270.693, 1350.602, 50.33706, 0),
(@PATH, @POINT := @POINT + 1, -3260.033, 1350.003, 49.33507, 0);

-- Spawn of Uvuros
SET @NPC := @GUIDSTART + 47;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3396.531, 1763.735, 103.6715, 0),
(@PATH, @POINT := @POINT + 1, -3379.886, 1753.972, 100.9325, 0),
(@PATH, @POINT := @POINT + 1, -3351.075, 1731.366, 101.1027, 0),
(@PATH, @POINT := @POINT + 1, -3335.615, 1706.502, 92.09635, 0),
(@PATH, @POINT := @POINT + 1, -3313.236, 1680.902, 82.59068, 0),
(@PATH, @POINT := @POINT + 1, -3280.050, 1659.776, 76.94063, 0),
(@PATH, @POINT := @POINT + 1, -3256.454, 1644.560, 75.24611, 0),
(@PATH, @POINT := @POINT + 1, -3228.498, 1617.366, 73.30030, 0),
(@PATH, @POINT := @POINT + 1, -3203.841, 1603.456, 65.55091, 0),
(@PATH, @POINT := @POINT + 1, -3201.420, 1584.667, 64.65486, 0),
(@PATH, @POINT := @POINT + 1, -3210.530, 1554.086, 69.44525, 0),
(@PATH, @POINT := @POINT + 1, -3203.931, 1537.755, 63.10846, 0),
(@PATH, @POINT := @POINT + 1, -3191.709, 1521.932, 58.59893, 0),
(@PATH, @POINT := @POINT + 1, -3196.587, 1492.656, 56.64238, 0),
(@PATH, @POINT := @POINT + 1, -3225.277, 1459.418, 52.93445, 0),
(@PATH, @POINT := @POINT + 1, -3238.553, 1442.582, 54.95837, 0),
(@PATH, @POINT := @POINT + 1, -3247.033, 1425.069, 54.55080, 0),
(@PATH, @POINT := @POINT + 1, -3257.249, 1405.119, 49.37111, 0),
(@PATH, @POINT := @POINT + 1, -3257.781, 1372.573, 50.29313, 0),
(@PATH, @POINT := @POINT + 1, -3258.098, 1356.509, 50.86205, 0),
(@PATH, @POINT := @POINT + 1, -3276.818, 1362.266, 51.14101, 0),
(@PATH, @POINT := @POINT + 1, -3293.685, 1386.509, 54.60675, 0),
(@PATH, @POINT := @POINT + 1, -3300.835, 1403.705, 48.41467, 0),
(@PATH, @POINT := @POINT + 1, -3296.142, 1444.353, 49.72927, 0),
(@PATH, @POINT := @POINT + 1, -3299.179, 1481.897, 49.46906, 0),
(@PATH, @POINT := @POINT + 1, -3306.986, 1513.383, 49.63754, 0),
(@PATH, @POINT := @POINT + 1, -3313.588, 1545.196, 49.11946, 0),
(@PATH, @POINT := @POINT + 1, -3318.321, 1574.779, 52.82721, 0),
(@PATH, @POINT := @POINT + 1, -3333.300, 1582.579, 52.62922, 0),
(@PATH, @POINT := @POINT + 1, -3360.646, 1591.053, 48.30080, 0),
(@PATH, @POINT := @POINT + 1, -3364.933, 1616.938, 57.70552, 0),
(@PATH, @POINT := @POINT + 1, -3364.986, 1625.938, 67.14265, 0),
(@PATH, @POINT := @POINT + 1, -3360.393, 1641.267, 76.21262, 0),
(@PATH, @POINT := @POINT + 1, -3355.990, 1654.556, 85.33762, 0),
(@PATH, @POINT := @POINT + 1, -3359.185, 1667.092, 93.14179, 0),
(@PATH, @POINT := @POINT + 1, -3366.348, 1672.388, 96.57612, 0),
(@PATH, @POINT := @POINT + 1, -3382.228, 1678.242, 99.06844, 0),
(@PATH, @POINT := @POINT + 1, -3392.588, 1689.778, 100.1087, 0),
(@PATH, @POINT := @POINT + 1, -3392.004, 1707.503, 101.3446, 0),
(@PATH, @POINT := @POINT + 1, -3389.512, 1722.959, 100.9325, 0),
(@PATH, @POINT := @POINT + 1, -3395.845, 1737.874, 100.9760, 0),
(@PATH, @POINT := @POINT + 1, -3422.167, 1761.102, 100.8965, 0),
(@PATH, @POINT := @POINT + 1, -3426.048, 1779.245, 101.0012, 0),
(@PATH, @POINT := @POINT + 1, -3411.591, 1779.760, 102.7506, 0);

-- Spawn of Uvuros
SET @NPC := @GUIDSTART + 48;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3883.975, 1263.450, 39.57877, 0),
(@PATH, @POINT := @POINT + 1, -3877.299, 1295.013, 41.17059, 0),
(@PATH, @POINT := @POINT + 1, -3861.565, 1336.159, 42.57558, 0),
(@PATH, @POINT := @POINT + 1, -3856.842, 1374.854, 40.72926, 0),
(@PATH, @POINT := @POINT + 1, -3853.621, 1415.182, 41.28652, 0),
(@PATH, @POINT := @POINT + 1, -3850.096, 1449.127, 40.63004, 0),
(@PATH, @POINT := @POINT + 1, -3837.649, 1471.836, 42.25663, 0),
(@PATH, @POINT := @POINT + 1, -3812.637, 1487.339, 43.66748, 0),
(@PATH, @POINT := @POINT + 1, -3778.138, 1477.471, 45.69685, 0),
(@PATH, @POINT := @POINT + 1, -3761.435, 1481.047, 46.64577, 0),
(@PATH, @POINT := @POINT + 1, -3752.615, 1506.764, 46.73626, 0),
(@PATH, @POINT := @POINT + 1, -3760.840, 1521.903, 46.17974, 0),
(@PATH, @POINT := @POINT + 1, -3740.406, 1548.016, 45.69281, 0),
(@PATH, @POINT := @POINT + 1, -3701.556, 1555.235, 46.53735, 0),
(@PATH, @POINT := @POINT + 1, -3666.428, 1555.937, 48.74696, 0),
(@PATH, @POINT := @POINT + 1, -3641.703, 1560.784, 48.89943, 0),
(@PATH, @POINT := @POINT + 1, -3621.069, 1564.322, 49.37859, 0),
(@PATH, @POINT := @POINT + 1, -3586.438, 1575.808, 48.08504, 0),
(@PATH, @POINT := @POINT + 1, -3565.169, 1579.912, 47.44227, 0),
(@PATH, @POINT := @POINT + 1, -3544.782, 1581.799, 47.61414, 0),
(@PATH, @POINT := @POINT + 1, -3527.046, 1582.921, 46.90386, 0),
(@PATH, @POINT := @POINT + 1, -3504.064, 1581.823, 46.44817, 0),
(@PATH, @POINT := @POINT + 1, -3478.576, 1585.087, 46.27065, 0),
(@PATH, @POINT := @POINT + 1, -3460.618, 1590.825, 46.06741, 0),
(@PATH, @POINT := @POINT + 1, -3440.108, 1591.190, 46.27847, 0),
(@PATH, @POINT := @POINT + 1, -3426.212, 1578.240, 46.94013, 0),
(@PATH, @POINT := @POINT + 1, -3411.032, 1558.515, 47.33210, 0),
(@PATH, @POINT := @POINT + 1, -3404.604, 1542.934, 48.61762, 0),
(@PATH, @POINT := @POINT + 1, -3389.848, 1526.002, 51.15543, 0),
(@PATH, @POINT := @POINT + 1, -3368.523, 1513.192, 52.20939, 0),
(@PATH, @POINT := @POINT + 1, -3351.651, 1503.182, 54.91648, 0),
(@PATH, @POINT := @POINT + 1, -3351.657, 1527.715, 52.74461, 0),
(@PATH, @POINT := @POINT + 1, -3364.133, 1546.499, 48.51556, 0),
(@PATH, @POINT := @POINT + 1, -3392.952, 1570.519, 47.51637, 0),
(@PATH, @POINT := @POINT + 1, -3417.222, 1593.474, 46.98994, 0),
(@PATH, @POINT := @POINT + 1, -3445.851, 1601.562, 45.30702, 0),
(@PATH, @POINT := @POINT + 1, -3491.342, 1617.464, 44.01123, 0),
(@PATH, @POINT := @POINT + 1, -3519.079, 1613.837, 44.54689, 0),
(@PATH, @POINT := @POINT + 1, -3547.801, 1609.742, 46.08816, 0),
(@PATH, @POINT := @POINT + 1, -3567.615, 1603.953, 46.46394, 0),
(@PATH, @POINT := @POINT + 1, -3599.266, 1603.943, 46.56330, 0),
(@PATH, @POINT := @POINT + 1, -3629.512, 1602.128, 44.90650, 0),
(@PATH, @POINT := @POINT + 1, -3663.672, 1596.284, 44.14022, 0),
(@PATH, @POINT := @POINT + 1, -3684.847, 1597.485, 44.30370, 0),
(@PATH, @POINT := @POINT + 1, -3706.536, 1597.117, 43.56276, 0),
(@PATH, @POINT := @POINT + 1, -3740.229, 1592.695, 42.73486, 0),
(@PATH, @POINT := @POINT + 1, -3765.860, 1589.795, 42.14697, 0),
(@PATH, @POINT := @POINT + 1, -3776.209, 1586.297, 43.06784, 0),
(@PATH, @POINT := @POINT + 1, -3801.413, 1582.604, 38.66776, 0),
(@PATH, @POINT := @POINT + 1, -3818.088, 1579.023, 39.01566, 0),
(@PATH, @POINT := @POINT + 1, -3833.926, 1572.863, 40.53856, 0),
(@PATH, @POINT := @POINT + 1, -3853.145, 1562.179, 40.32445, 0),
(@PATH, @POINT := @POINT + 1, -3864.950, 1546.461, 39.87780, 0),
(@PATH, @POINT := @POINT + 1, -3877.748, 1532.587, 40.83701, 0),
(@PATH, @POINT := @POINT + 1, -3887.162, 1514.339, 40.20065, 0),
(@PATH, @POINT := @POINT + 1, -3897.826, 1498.679, 39.94930, 0),
(@PATH, @POINT := @POINT + 1, -3911.663, 1481.578, 40.96449, 0),
(@PATH, @POINT := @POINT + 1, -3923.059, 1472.531, 39.72596, 0),
(@PATH, @POINT := @POINT + 1, -3942.438, 1456.924, 39.64678, 0),
(@PATH, @POINT := @POINT + 1, -3951.686, 1438.097, 39.99761, 0),
(@PATH, @POINT := @POINT + 1, -3957.481, 1416.761, 41.08671, 0),
(@PATH, @POINT := @POINT + 1, -3962.978, 1389.702, 40.50446, 0),
(@PATH, @POINT := @POINT + 1, -3962.620, 1365.318, 39.93514, 0),
(@PATH, @POINT := @POINT + 1, -3958.417, 1341.775, 40.65548, 0),
(@PATH, @POINT := @POINT + 1, -3949.188, 1329.422, 39.64235, 0),
(@PATH, @POINT := @POINT + 1, -3930.227, 1332.664, 39.72723, 0),
(@PATH, @POINT := @POINT + 1, -3912.603, 1323.637, 39.72723, 0),
(@PATH, @POINT := @POINT + 1, -3905.935, 1306.785, 40.00555, 0),
(@PATH, @POINT := @POINT + 1, -3897.439, 1291.250, 39.77972, 0),
(@PATH, @POINT := @POINT + 1, -3895.385, 1274.919, 39.77972, 0),
(@PATH, @POINT := @POINT + 1, -3897.776, 1262.570, 40.61844, 0),
(@PATH, @POINT := @POINT + 1, -3894.454, 1248.885, 40.76053, 0),
(@PATH, @POINT := @POINT + 1, -3889.979, 1241.081, 41.68936, 0),
(@PATH, @POINT := @POINT + 1, -3874.964, 1239.425, 43.99124, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 49;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3885.240, 1364.806, 47.32335, 0),
(@PATH, @POINT := @POINT + 1, -3893.468, 1378.957, 44.22478, 0),
(@PATH, @POINT := @POINT + 1, -3890.696, 1403.879, 42.45049, 0),
(@PATH, @POINT := @POINT + 1, -3878.542, 1416.131, 45.03984, 0),
(@PATH, @POINT := @POINT + 1, -3868.016, 1422.589, 43.28850, 0),
(@PATH, @POINT := @POINT + 1, -3866.986, 1431.180, 44.35478, 0),
(@PATH, @POINT := @POINT + 1, -3872.096, 1444.150, 44.33565, 0),
(@PATH, @POINT := @POINT + 1, -3887.687, 1451.941, 43.10823, 0),
(@PATH, @POINT := @POINT + 1, -3904.409, 1442.322, 43.87148, 0),
(@PATH, @POINT := @POINT + 1, -3915.545, 1437.817, 42.73317, 0),
(@PATH, @POINT := @POINT + 1, -3935.223, 1430.502, 42.05680, 0),
(@PATH, @POINT := @POINT + 1, -3948.244, 1414.806, 42.20597, 0),
(@PATH, @POINT := @POINT + 1, -3949.208, 1394.731, 42.42316, 0),
(@PATH, @POINT := @POINT + 1, -3942.230, 1380.242, 48.84430, 0),
(@PATH, @POINT := @POINT + 1, -3926.847, 1369.215, 56.77013, 0),
(@PATH, @POINT := @POINT + 1, -3914.108, 1356.588, 48.61945, 0),
(@PATH, @POINT := @POINT + 1, -3901.195, 1340.179, 44.42853, 0),
(@PATH, @POINT := @POINT + 1, -3884.467, 1330.002, 42.31290, 0),
(@PATH, @POINT := @POINT + 1, -3867.133, 1337.162, 42.78844, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 59;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3914.196, 1511.538, 41.50407, 0),
(@PATH, @POINT := @POINT + 1, -3921.157, 1501.577, 41.83073, 0),
(@PATH, @POINT := @POINT + 1, -3943.445, 1494.013, 42.36216, 0),
(@PATH, @POINT := @POINT + 1, -3921.454, 1495.902, 42.89320, 0),
(@PATH, @POINT := @POINT + 1, -3910.507, 1493.047, 42.32911, 0),
(@PATH, @POINT := @POINT + 1, -3905.857, 1475.243, 42.60096, 0),
(@PATH, @POINT := @POINT + 1, -3909.167, 1494.119, 42.26332, 0),
(@PATH, @POINT := @POINT + 1, -3907.289, 1501.576, 41.53849, 0),
(@PATH, @POINT := @POINT + 1, -3901.062, 1508.516, 41.95768, 0),
(@PATH, @POINT := @POINT + 1, -3900.365, 1514.210, 42.87772, 0),
(@PATH, @POINT := @POINT + 1, -3903.610, 1517.513, 43.24992, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 69;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3709.945, 1709.525, 41.01095, 0),
(@PATH, @POINT := @POINT + 1, -3720.238, 1723.055, 43.88595, 0),
(@PATH, @POINT := @POINT + 1, -3738.680, 1715.650, 43.50869, 0),
(@PATH, @POINT := @POINT + 1, -3736.526, 1705.155, 41.14419, 0),
(@PATH, @POINT := @POINT + 1, -3727.699, 1692.519, 41.20983, 0),
(@PATH, @POINT := @POINT + 1, -3723.818, 1683.273, 41.00549, 0),
(@PATH, @POINT := @POINT + 1, -3717.185, 1677.910, 40.70983, 0),
(@PATH, @POINT := @POINT + 1, -3711.126, 1677.806, 41.08483, 0),
(@PATH, @POINT := @POINT + 1, -3703.645, 1693.281, 40.71606, 0),
(@PATH, @POINT := @POINT + 1, -3691.058, 1695.034, 40.92959, 0),
(@PATH, @POINT := @POINT + 1, -3691.011, 1699.614, 40.92959, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 71;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3665.200, 1726.542, 41.00065, 0),
(@PATH, @POINT := @POINT + 1, -3685.951, 1704.760, 40.74003, 0),
(@PATH, @POINT := @POINT + 1, -3708.052, 1711.204, 40.72897, 0),
(@PATH, @POINT := @POINT + 1, -3711.397, 1734.295, 49.12101, 0),
(@PATH, @POINT := @POINT + 1, -3690.316, 1757.645, 53.07401, 0),
(@PATH, @POINT := @POINT + 1, -3683.085, 1771.540, 52.25634, 0),
(@PATH, @POINT := @POINT + 1, -3667.904, 1764.635, 41.10392, 0),
(@PATH, @POINT := @POINT + 1, -3661.037, 1753.775, 40.54902, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 86;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3238.603, 1503.875, 53.12578, 0),
(@PATH, @POINT := @POINT + 1, -3242.168, 1516.518, 52.48369, 0),
(@PATH, @POINT := @POINT + 1, -3248.125, 1528.953, 52.95305, 0),
(@PATH, @POINT := @POINT + 1, -3248.861, 1516.293, 52.52824, 0),
(@PATH, @POINT := @POINT + 1, -3247.510, 1508.754, 53.04033, 0),
(@PATH, @POINT := @POINT + 1, -3252.998, 1499.196, 53.13034, 0),
(@PATH, @POINT := @POINT + 1, -3244.429, 1497.290, 52.85495, 0),
(@PATH, @POINT := @POINT + 1, -3236.769, 1495.461, 53.52316, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 88;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3181.236, 1463.110, 48.81565, 0),
(@PATH, @POINT := @POINT + 1, -3168.532, 1444.734, 37.02708, 0),
(@PATH, @POINT := @POINT + 1, -3166.327, 1435.308, 33.06020, 0),
(@PATH, @POINT := @POINT + 1, -3188.029, 1418.776, 26.58076, 0),
(@PATH, @POINT := @POINT + 1, -3188.216, 1403.985, 17.01582, 0),
(@PATH, @POINT := @POINT + 1, -3161.896, 1384.002, 12.73356, 0),
(@PATH, @POINT := @POINT + 1, -3137.334, 1364.318, 15.08554, 0),
(@PATH, @POINT := @POINT + 1, -3111.115, 1363.514, 11.71142, 0),
(@PATH, @POINT := @POINT + 1, -3095.935, 1342.166, 11.30849, 0),
(@PATH, @POINT := @POINT + 1, -3083.227, 1340.211, 11.49074, 0),
(@PATH, @POINT := @POINT + 1, -3068.760, 1350.527, 12.61390, 0),
(@PATH, @POINT := @POINT + 1, -3071.868, 1369.817, 10.94514, 0),
(@PATH, @POINT := @POINT + 1, -3073.509, 1402.595, 11.95168, 0),
(@PATH, @POINT := @POINT + 1, -3080.528, 1424.535, 12.57888, 0),
(@PATH, @POINT := @POINT + 1, -3068.792, 1440.774, 11.69368, 0),
(@PATH, @POINT := @POINT + 1, -3053.285, 1455.278, 15.71386, 0),
(@PATH, @POINT := @POINT + 1, -3049.059, 1481.634, 19.06850, 0),
(@PATH, @POINT := @POINT + 1, -3040.421, 1505.779, 21.51766, 0),
(@PATH, @POINT := @POINT + 1, -3060.786, 1516.275, 27.21846, 0),
(@PATH, @POINT := @POINT + 1, -3082.017, 1521.448, 31.14843, 0),
(@PATH, @POINT := @POINT + 1, -3115.762, 1517.771, 36.77888, 0),
(@PATH, @POINT := @POINT + 1, -3148.282, 1512.845, 52.54025, 0),
(@PATH, @POINT := @POINT + 1, -3179.017, 1499.947, 57.56462, 0),
(@PATH, @POINT := @POINT + 1, -3188.386, 1488.957, 56.37053, 0),
(@PATH, @POINT := @POINT + 1, -3188.365, 1476.448, 54.75310, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 91;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3169.582, 1321.246, 20.41059, 0),
(@PATH, @POINT := @POINT + 1, -3151.086, 1321.264, 18.86339, 0),
(@PATH, @POINT := @POINT + 1, -3129.894, 1308.252, 15.26388, 0),
(@PATH, @POINT := @POINT + 1, -3116.495, 1296.661, 10.75269, 0),
(@PATH, @POINT := @POINT + 1, -3103.535, 1292.129, 8.244267, 0),
(@PATH, @POINT := @POINT + 1, -3087.993, 1285.691, 7.557983, 0),
(@PATH, @POINT := @POINT + 1, -3103.535, 1292.129, 8.244267, 0),
(@PATH, @POINT := @POINT + 1, -3116.495, 1296.661, 10.75269, 0),
(@PATH, @POINT := @POINT + 1, -3129.894, 1308.252, 15.26388, 0),
(@PATH, @POINT := @POINT + 1, -3151.086, 1321.264, 18.86339, 0),
(@PATH, @POINT := @POINT + 1, -3169.582, 1321.246, 20.41059, 0),
(@PATH, @POINT := @POINT + 1, -3182.668, 1317.121, 23.24592, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 93;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3333.127, 1505.996, 56.88705, 0),
(@PATH, @POINT := @POINT + 1, -3333.297, 1531.010, 53.27084, 0),
(@PATH, @POINT := @POINT + 1, -3336.890, 1549.107, 53.41644, 0),
(@PATH, @POINT := @POINT + 1, -3359.720, 1559.841, 48.68084, 0),
(@PATH, @POINT := @POINT + 1, -3386.077, 1564.115, 47.83860, 0),
(@PATH, @POINT := @POINT + 1, -3399.071, 1572.567, 48.68861, 0),
(@PATH, @POINT := @POINT + 1, -3403.656, 1588.113, 47.37836, 0),
(@PATH, @POINT := @POINT + 1, -3410.922, 1597.664, 48.89814, 0),
(@PATH, @POINT := @POINT + 1, -3435.559, 1600.706, 46.05702, 0),
(@PATH, @POINT := @POINT + 1, -3455.617, 1598.535, 45.76723, 0),
(@PATH, @POINT := @POINT + 1, -3474.853, 1601.084, 47.08947, 0),
(@PATH, @POINT := @POINT + 1, -3487.188, 1609.624, 44.91955, 0),
(@PATH, @POINT := @POINT + 1, -3498.708, 1610.491, 45.33032, 0),
(@PATH, @POINT := @POINT + 1, -3507.274, 1622.938, 44.48219, 0),
(@PATH, @POINT := @POINT + 1, -3525.378, 1631.045, 44.88404, 0),
(@PATH, @POINT := @POINT + 1, -3540.047, 1633.398, 44.68267, 0),
(@PATH, @POINT := @POINT + 1, -3551.048, 1629.547, 45.11062, 0),
(@PATH, @POINT := @POINT + 1, -3570.073, 1627.939, 46.33479, 0),
(@PATH, @POINT := @POINT + 1, -3551.048, 1629.547, 45.11062, 0),
(@PATH, @POINT := @POINT + 1, -3540.047, 1633.398, 44.68267, 0),
(@PATH, @POINT := @POINT + 1, -3525.378, 1631.045, 44.88404, 0),
(@PATH, @POINT := @POINT + 1, -3507.274, 1622.938, 44.48219, 0),
(@PATH, @POINT := @POINT + 1, -3498.708, 1610.491, 45.33032, 0),
(@PATH, @POINT := @POINT + 1, -3487.263, 1609.681, 44.97107, 0),
(@PATH, @POINT := @POINT + 1, -3474.853, 1601.084, 47.08947, 0),
(@PATH, @POINT := @POINT + 1, -3455.617, 1598.535, 45.76723, 0),
(@PATH, @POINT := @POINT + 1, -3435.559, 1600.706, 46.05702, 0),
(@PATH, @POINT := @POINT + 1, -3411.025, 1597.808, 49.02583, 0),
(@PATH, @POINT := @POINT + 1, -3403.656, 1588.113, 47.37836, 0),
(@PATH, @POINT := @POINT + 1, -3399.125, 1572.770, 48.79957, 0),
(@PATH, @POINT := @POINT + 1, -3386.077, 1564.115, 47.83860, 0),
(@PATH, @POINT := @POINT + 1, -3359.720, 1559.841, 48.68084, 0),
(@PATH, @POINT := @POINT + 1, -3336.890, 1549.107, 53.41644, 0),
(@PATH, @POINT := @POINT + 1, -3333.297, 1531.010, 53.27084, 0),
(@PATH, @POINT := @POINT + 1, -3333.127, 1505.996, 56.88705, 0),
(@PATH, @POINT := @POINT + 1, -3331.013, 1486.700, 61.64925, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 97;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3589.718, 1722.242, 41.14121, 0),
(@PATH, @POINT := @POINT + 1, -3597.313, 1712.778, 41.14121, 0),
(@PATH, @POINT := @POINT + 1, -3618.428, 1713.334, 41.31626, 0),
(@PATH, @POINT := @POINT + 1, -3625.589, 1736.798, 40.76400, 0),
(@PATH, @POINT := @POINT + 1, -3635.015, 1739.896, 41.21443, 0),
(@PATH, @POINT := @POINT + 1, -3625.589, 1736.798, 40.76400, 0),
(@PATH, @POINT := @POINT + 1, -3618.428, 1713.334, 41.31626, 0),
(@PATH, @POINT := @POINT + 1, -3597.313, 1712.778, 41.14121, 0),
(@PATH, @POINT := @POINT + 1, -3589.718, 1722.242, 41.14121, 0),
(@PATH, @POINT := @POINT + 1, -3585.924, 1736.551, 40.81908, 0);

-- Enraged Earth Spirit
SET @NPC := @GUIDSTART + 100;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, @POINT := @POINT + 1, -3825.014, 1546.434, 42.23067, 0),
(@PATH, @POINT := @POINT + 1, -3817.830, 1531.363, 43.49965, 0),
(@PATH, @POINT := @POINT + 1, -3804.013, 1529.107, 44.79787, 0),
(@PATH, @POINT := @POINT + 1, -3794.242, 1527.443, 45.19921, 0),
(@PATH, @POINT := @POINT + 1, -3793.912, 1511.280, 45.78661, 0),
(@PATH, @POINT := @POINT + 1, -3802.640, 1500.825, 44.64186, 0),
(@PATH, @POINT := @POINT + 1, -3815.027, 1494.317, 43.41748, 0),
(@PATH, @POINT := @POINT + 1, -3843.093, 1496.748, 42.07108, 0),
(@PATH, @POINT := @POINT + 1, -3853.235, 1507.411, 42.07387, 0),
(@PATH, @POINT := @POINT + 1, -3846.999, 1533.572, 42.09203, 0),
(@PATH, @POINT := @POINT + 1, -3830.346, 1546.582, 41.71285, 0),
(@PATH, @POINT := @POINT + 1, -3828.609, 1551.348, 41.51583, 0),
(@PATH, @POINT := @POINT + 1, -3833.577, 1561.334, 42.24730, 0);

DELETE FROM `gameobject_template_addon` WHERE `entry`=300184;
