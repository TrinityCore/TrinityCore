-- Rage Winterchill
SET @PATH_ID := 142138;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 4896.08, -1576.35, 1333.65),
(@PATH_ID, 1, 4898.68, -1615.02, 1329.48),
(@PATH_ID, 2, 4907.12, -1667.08, 1321.00),
(@PATH_ID, 3, 4963.18, -1699.35, 1340.51),
(@PATH_ID, 4, 4989.16, -1716.67, 1335.74),
(@PATH_ID, 5, 5026.27, -1736.89, 1323.02),
(@PATH_ID, 6, 5037.77, -1770.56, 1324.36),
(@PATH_ID, 7, 5067.23, -1789.95, 1321.17);

-- Kazrogal
SET @PATH_ID := 143106;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 5492.91, -2404.61, 1462.63),
(@PATH_ID, 1, 5531.76, -2460.87, 1469.55),
(@PATH_ID, 2, 5554.58, -2514.66, 1476.12),
(@PATH_ID, 3, 5554.16, -2567.23, 1479.90),
(@PATH_ID, 4, 5540.67, -2625.99, 1480.89),
(@PATH_ID, 5, 5508.16, -2659.20, 1480.15),
(@PATH_ID, 6, 5489.62, -2704.05, 1482.18),
(@PATH_ID, 7, 5457.04, -2726.26, 1485.10);

-- Azgalor
SET @PATH_ID := 142738;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 5492.91, -2404.61, 1462.63),
(@PATH_ID, 1, 5531.76, -2460.87, 1469.55),
(@PATH_ID, 2, 5554.58, -2514.66, 1476.12),
(@PATH_ID, 3, 5554.16, -2567.23, 1479.90),
(@PATH_ID, 4, 5540.67, -2625.99, 1480.89),
(@PATH_ID, 5, 5508.16, -2659.20, 1480.15),
(@PATH_ID, 6, 5489.62, -2704.05, 1482.18),
(@PATH_ID, 7, 5457.04, -2726.26, 1485.10);

-- Anetheron
SET @PATH_ID := 142466;
DELETE FROM `waypoint_data` WHERE `id`=@PATH_ID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(@PATH_ID, 0, 4896.08, -1576.35, 1333.65),
(@PATH_ID, 1, 4898.68, -1615.02, 1329.48),
(@PATH_ID, 2, 4907.12, -1667.08, 1321.00),
(@PATH_ID, 3, 4963.18, -1699.35, 1340.51),
(@PATH_ID, 4, 4989.16, -1716.67, 1335.74),
(@PATH_ID, 5, 5026.27, -1736.89, 1323.02),
(@PATH_ID, 6, 5037.77, -1770.56, 1324.36),
(@PATH_ID, 7, 5067.23, -1789.95, 1321.17);

DELETE FROM `waypoint_data` WHERE `id` & 2;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) SELECT ((s.`entry` << 3) | 2), s.`pointid`, s.`location_x`, s.`location_y`, s.`location_z`, s.`waittime` FROM `script_waypoint` s;

DROP TABLE IF EXISTS `script_waypoint`;
