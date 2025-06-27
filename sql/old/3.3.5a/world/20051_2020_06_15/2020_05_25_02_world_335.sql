--
UPDATE `creature` SET `position_x` = 117.8646, `position_y` = 923.6945, `position_z` = 33.97255, `orientation` = 1.58825 WHERE `guid` = 89357 AND `id` = 24239;
UPDATE `creature` SET `position_x` = 119.9806, `position_y` = 674.2449, `position_z` = 51.82448, `orientation` = 1.466077 WHERE `guid` = 89358 AND `id` = 23863;
UPDATE `creature` SET `position_x` = 301.1223, `position_y` = 1385.6, `position_z` = 57.75306, `orientation` = 3.263766 WHERE `guid` = 89283 AND `id` = 24549;
UPDATE `creature` SET `position_x` = 206.9213, `position_y` = 1473.42, `position_z` = 26.00007, `orientation` = 3.961897 WHERE `guid` = 89281 AND `id` = 24175;
UPDATE `creature` SET `position_x` = 347.3426, `position_y` = 1398.941, `position_z` = 74.42841, `orientation` = 4.066617 WHERE `guid` = 89208 AND `id` = 23814;
UPDATE `creature` SET `position_x` = 369.8111, `position_y` = 1088.396, `position_z` = 6.595592, `orientation` = 4.764749 WHERE `guid` = 27948 AND `id` = 23815;
UPDATE `creature` SET `position_x` = 232.7488, `position_y` = 1428.699, `position_z` = 28.82419, `orientation` = 1.832596 WHERE `guid` = 89311 AND `id` = 24180;
UPDATE `creature` SET `position_x` = 223.8005, `position_y` = 1424.94, `position_z` = 29.46985, `orientation` = 1.169371 WHERE `guid` = 1107 AND `id` = 24179;

DELETE FROM `creature` WHERE `guid` IN (89266, 89267, 89272, 89275, 91245, 91246, 130793, 130795, 130797, 130799, 130800, 130807, 130808, 130814, 130815, 130816, 130817, 130821, 130822, 130823, 130826, 130828, 130832, 130834, 130835, 130836, 130838, 130840, 130842, 130846);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(89266, 24223, 568, 1, 1, 0, 227.8884, 1452.763, 26.00041, 3.001966, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(89267, 24223, 568, 1, 1, 0, 231.7856, 1477.332, 26.00007, 0.541052, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(89272, 24223, 568, 1, 1, 0, 228.4806, 1433.126, 27.38743, 2.583087, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(89275, 24223, 568, 1, 1, 0, 227.03, 1417.474, 32.81706, 2.75762, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(91245, 24223, 568, 1, 1, 0, 227.6509, 1404.276, 37.13389, 2.321288, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(91246, 24223, 568, 1, 1, 0, 227.5511, 1382.419, 44.78124, 0.1745329, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130793, 24223, 568, 1, 1, 0, 245.9202, 1374.849, 49.40488, 3.403392, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130795, 24223, 568, 1, 1, 0, 229.5756, 1361.475, 49.16213, 5.218534, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130797, 24223, 568, 1, 1, 0, 246.9738, 1356.473, 49.40504, 1.204277, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130799, 24223, 568, 1, 1, 0, 253.9278, 1429.991, 49.40504, 2.181662, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130800, 24223, 568, 1, 1, 0, 261.4551, 1402.299, 49.40504, 2.024582, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130807, 24223, 568, 1, 1, 0, 281.3025, 1430.996, 61.60976, 0.08726646, 7200, 0, 0), -- Eagle Trash Aggro Trigger (Area: 0)
(130808, 24551, 568, 1, 1, 0, 409.0086, 1417.029, 74.39153, 0.6457718, 7200, 0, 0), -- Eagle Event Deactivation Trigger (Area: 0)
(130814, 21252, 568, 1, 1, 0, -34.71929, 1149.694, 19.2254, 6.038839, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: 0)
(130815, 24549, 568, 1, 1, 1, 114.8588, 992.1212, 30.54751, 0.6108652, 7200, 0, 0), -- Amani'shi Tempest (Area: 0) (possible waypoints or random movement)
(130816, 23581, 568, 1, 1, 1, 120.3534, 992.8157, 30.74231, 2.373648, 7200, 0, 0), -- Amani'shi Medicine Man (Area: 0) (possible waypoints or random movement)
(130817, 23596, 568, 1, 1, 1, 121.9231, 996.9573, 30.77481, 3.420845, 7200, 0, 0), -- Amani'shi Flame Caster (Area: 0) (possible waypoints or random movement)
(130821, 23597, 568, 1, 1, 1, 116.2163, 997.4488, 30.57613, 5.393067, 7200, 0, 0), -- Amani'shi Guardian (Area: 0) (possible waypoints or random movement)
(130822, 24179, 568, 1, 1, 1, 231.7972, 1393.424, 40.58874, 1.692969, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(130823, 24179, 568, 1, 1, 1, 246.9084, 1375.147, 49.40504, 2.897247, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(130826, 24179, 568, 1, 1, 1, 284.0443, 1372.319, 49.40504, 2.775074, 7200, 0, 0), -- Amani'shi Wind Walker (Area: 0) (possible waypoints or random movement)
(130828, 24180, 568, 1, 1, 1, 224.0694, 1394.261, 40.19848, 1.308997, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(130832, 24180, 568, 1, 1, 1, 244.807, 1367.658, 48.94979, 2.617994, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(130834, 24180, 568, 1, 1, 1, 274.3584, 1385.163, 49.40504, 3.752458, 7200, 0, 0), -- Amani'shi Protector (Area: 0) (possible waypoints or random movement)
(130835, 23586, 568, 1, 1, 1, -219.3753, 1380.724, 0.03532434, 1.047198, 7200, 0, 0), -- Amani'shi Scout (Area: 0) (possible waypoints or random movement)
(130836, 23597, 568, 1, 1, 1, 411.5532, 1022.259, 9.605077, 4.782202, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(130838, 23597, 568, 1, 1, 1, 400.7974, 1022.438, 9.605576, 4.660029, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(130840, 23597, 568, 1, 1, 1, 397.7076, 1048.77, 9.604503, 6.108652, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(130842, 23597, 568, 1, 1, 1, 406.0692, 1044.394, 9.60488, 2.356194, 7200, 0, 0), -- Amani'shi Guardian (Area: 0)
(130846, 24065, 568, 1, 1, 1, 406.4329, 1054.867, 9.604886, 4.520403, 7200, 0, 0); -- Amani'shi Handler (Area: 0)

DELETE FROM `linked_respawn` WHERE `guid` IN (130815, 130816, 130817, 130821, 130822, 130823, 130826, 130828, 130832, 130834, 130835, 130836, 130838, 130840, 130842, 130846);
INSERT INTO `linked_respawn` (`guid`, `linkedGuid`, `linkType`) VALUES
(130815,89357,0),
(130816,89357,0),
(130817,89357,0),
(130821,89357,0),
(130822,86494,0),
(130823,86494,0),
(130826,86494,0),
(130828,86494,0),
(130832,86494,0),
(130834,86494,0),
(130835,89322,0),
(130836,86195,0),
(130838,86195,0),
(130840,86195,0),
(130842,86195,0),
(130846,86195,0);

