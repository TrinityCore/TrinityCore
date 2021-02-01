SET @CGUID := 285206;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10712, -1281.68, 15.3854, 0, 1197),
(@PATH, 1, -10717.5, -1283.68, 15.3854, 0, -1094),
(@PATH, 2, -10724.5, -1282.25, 15.3854, 0, -1762),
(@PATH, 3, -10727.2, -1279.2, 15.3854, 0, -1786),
(@PATH, 4, -10730, -1282.02, 15.3854, 0, -1773),
(@PATH, 5, -10733.7, -1289.15, 15.37456, 0, -1745),
(@PATH, 6, -10740, -1285.8, 15.37456, 0, 1204),
(@PATH, 7, -10733.7, -1289.15, 15.37456, 0, -663),
(@PATH, 8, -10730, -1282.02, 15.3854, 0, -643),
(@PATH, 9, -10727.2, -1279.2, 15.3854, 0, -632),
(@PATH, 10, -10724.5, -1282.25, 15.3854, 0, -668),
(@PATH, 11, -10717.5, -1283.68, 15.3854, 0, -1329);

UPDATE `creature` SET `position_x`= -10712, `position_y`= -1281.68, `position_z`= 15.3854, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

SET @CGUID := 285203;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10726.7, -1355.81, 15.4777, 0, 472),
(@PATH, 1, -10721.5, -1356.54, 15.4777, 0, -733),
(@PATH, 2, -10716.8, -1356.81, 15.4777, 0, -1141),
(@PATH, 3, -10709.9, -1357.38, 15.4777, 0, -1682),
(@PATH, 4, -10705, -1355.07, 15.4777, 0, -1316),
(@PATH, 5, -10707.1, -1346.12, 15.4777, 0, -814),
(@PATH, 6, -10701.2, -1344.27, 15.4777, 0, 326),
(@PATH, 7, -10707.1, -1346.12, 15.4777, 0, -1292),
(@PATH, 8, -10705, -1355.07, 15.4777, 0, -773),
(@PATH, 9, -10709.9, -1357.38, 15.4777, 0, -1608),
(@PATH, 10, -10716.8, -1356.81, 15.4777, 0, -946),
(@PATH, 11, -10721.5, -1356.54, 15.4777, 0, -1348);

UPDATE `creature` SET `position_x`= -10726.7, `position_y`= -1355.81, `position_z`= 15.4777, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

SET @CGUID := 295192;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10784, -1397.36, 15.47772, 0, 1025),
(@PATH, 1, -10792.2, -1403.64, 15.39894, 0, -1377),
(@PATH, 2, -10800.6, -1410.26, 15.47772, 0, -1778),
(@PATH, 3, -10806.6, -1412.06, 15.47772, 0, -698),
(@PATH, 4, -10813.8, -1413.42, 15.47772, 0, -1484),
(@PATH, 5, -10821.1, -1414.79, 15.47772, 0, -1142),
(@PATH, 6, -10827.6, -1414.14, 15.47772, 0, 985),
(@PATH, 7, -10821.1, -1414.79, 15.47772, 0, -1502),
(@PATH, 8, -10813.8, -1413.42, 15.47772, 0, -1144),
(@PATH, 9, -10806.6, -1412.06, 15.47772, 0, -698),
(@PATH, 10, -10800.6, -1410.26, 15.47772, 0, -1778),
(@PATH, 11, -10792.2, -1403.64, 15.39894, 0, -1377);

UPDATE `creature` SET `position_x`= -10784, `position_y`= -1397.36, `position_z`= 15.47772, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

SET @CGUID := 313314;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -10860.1, -1313.22, 15.47772, 0, 1052),
(@PATH, 1, -10855.1, -1309.42, 15.47772, 0, -1367),
(@PATH, 2, -10847, -1303.65, 15.47772, 0, -1271),
(@PATH, 3, -10837.9, -1299.11, 15.44543, 0, -1365),
(@PATH, 4, -10829.6, -1297.1, 15.41835, 0, -1662),
(@PATH, 5, -10822.9, -1296.66, 15.41835, 0, 344),
(@PATH, 6, -10829.6, -1297.1, 15.41835, 0, -1626),
(@PATH, 7, -10837.9, -1299.11, 15.44543, 0, -724),
(@PATH, 8, -10847, -1303.65, 15.47772, 0, -800),
(@PATH, 9, -10855.1, -1309.42, 15.47772, 0, -1367);

UPDATE `creature` SET `position_x`= -10860.1, `position_y`= -1313.22, `position_z`= 15.47772, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `bytes2`) VALUES
(@CGUID, @PATH, 1);
