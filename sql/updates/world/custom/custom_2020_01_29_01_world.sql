-- Pathing for  Entry: 42383 'TDB FORMAT' 
SET @NPC := 274657;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11036.81, `position_y`= 1507.757, `position_z`= 43.30658 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11036.81, 1507.757, 43.30658, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -11035.87, 1515.606, 43.05658, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11022.051, 1520.1267, 43.141426, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11008.533, 1513.9462, 43.141426, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11020.614, 1494.6442, 43.255836, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11023.71, 1470.6788, 43.130836, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11022.524, 1449.4375, 43.111294, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -11015.036, 1435.2692, 42.978237, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -11006.29, 1423.5192, 43.24757, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10990.455, 1412.2587, 43.178925, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -10975.337, 1412.132, 42.85678, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -10957.153, 1423.0608, 43.24745, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -10943.674, 1425.2882, 43.318253, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -10917.571, 1420.3073, 42.87828, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -10920.165, 1420.9896, 42.87889, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -10946.478, 1424.8212, 43.41774, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -10957, 1423.2865, 43.27455, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -10975.176, 1412.1354, 42.87558, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -10991.604, 1412.5452, 42.97812, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -11007.243, 1423.8923, 43.304455, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -11020.172, 1442.7812, 43.111294, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -11023.989, 1464.224, 42.986294, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -11023.747, 1491.3716, 43.255836, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002963C00000020000310C1D .go xyz -11036.81 1507.757 43.30658

-- Pathing for  Entry: 42383 'TDB FORMAT' 
SET @NPC := 274427;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11134.238, `position_y`= 1508.3317, `position_z`= 23.994234 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11134.238, 1508.3317, 23.994234, 0, 89, 0, 0, 100, 0),
(@PATH, 2, -11124.228, 1499.0104, 23.828375, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11107.288, 1498.7795, 25.058445, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11097.757, 1509.3959, 28.063509, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11092.054, 1517.9236, 29.755865, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11098.384, 1525.9531, 30.100548, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11108.323, 1519.3055, 30.716576, 0, 111, 0, 0, 100, 0),
(@PATH, 8, -11098.384, 1525.9531, 30.100548, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -11092.054, 1517.9236, 29.755865, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -11097.757, 1509.3959, 28.063509, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -11107.288, 1498.7795, 25.058445, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -11124.228, 1499.0104, 23.828375, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002963C00000020002B10C08 .go xyz -11134.238 1508.3317 23.994234

-- Pathing for  Entry: 42383 'TDB FORMAT' 
SET @NPC := 274351;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11239.393, `position_y`= 1638.0858, `position_z`= 27.146315 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11239.393, 1638.0858, 27.146315, 0, 226, 0, 0, 100, 0),
(@PATH, 2, -11246.916, 1649.819, 31.273176, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11251.044, 1657.8959, 33.573162, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11236.33, 1661.2899, 33.471973, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11228.361, 1655.8351, 33.924007, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11225.116, 1644.316, 33.89678, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11225.328, 1627.283, 34.126522, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -11225.295, 1609.6997, 32.786697, 0, 246, 0, 0, 100, 0),
(@PATH, 9, -11225.328, 1627.283, 34.126522, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -11225.116, 1644.316, 33.89678, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -11228.361, 1655.8351, 33.924007, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -11236.33, 1661.2899, 33.471973, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -11251.044, 1657.8959, 33.573162, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -11246.939, 1649.856, 31.306616, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002963C00000020003310C08 .go xyz -11239.393 1638.0858 27.146315

-- Pathing for  Entry: 42383 'TDB FORMAT' 
SET @NPC := 274424;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11103.81, `position_y`= 1487.8247, `position_z`= 33.163437 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11103.81, 1487.8247, 33.163437, 0, 405, 0, 0, 100, 0),
(@PATH, 2, -11118.897, 1480.7101, 33.164227, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11125.839, 1479.9236, 34.23399, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11131.406, 1483.4567, 34.175297, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11134.348, 1491.6754, 35.194145, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11131.44, 1496.7616, 36.16809, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11126.339, 1505.6493, 36.173203, 0, 279, 0, 0, 100, 0),
(@PATH, 8, -11131.366, 1496.8923, 36.212345, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -11134.348, 1491.6754, 35.194145, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -11131.406, 1483.4567, 34.175297, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -11125.839, 1479.9236, 34.23399, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -11118.897, 1480.7101, 33.164227, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002963C00000020003B10C08 .go xyz -11103.81 1487.8247 33.163437

-- Pathing for  Entry: 42400 'TDB FORMAT' 
SET @NPC := 274441;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11098.462, `position_y`= 1498.4618, `position_z`= 49.973198 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11098.462, 1498.4618, 49.973198, 0, 200, 0, 0, 100, 0),
(@PATH, 2, -11097.685, 1516.118, 49.973198, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11093.029, 1514.9497, 49.948242, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11092.933, 1501.6216, 49.9732, 0, 188, 0, 0, 100, 0),
(@PATH, 5, -11092.944, 1503.1992, 49.9732, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11097.685, 1516.118, 49.973198, 0, 0, 0, 0, 100, 0);
-- 0x2416D400002968000000020000310C08 .go xyz -11098.462 1498.4618 49.973198

-- Pathing for  Entry: 42383 'TDB FORMAT' 
SET @NPC := 274454;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11075.125, `position_y`= 1498.0781, `position_z`= 42.9732 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79143');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11075.125, 1498.0781, 42.9732, 0, 73, 0, 0, 100, 0),
(@PATH, 2, -11076.451, 1503.7916, 43.027317, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11082.401, 1505.0278, 43.0148, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11081.807, 1521.0142, 43.5732, 0, 171, 0, 0, 100, 0),
(@PATH, 5, -11082.401, 1505.0278, 43.0148, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11076.451, 1503.7916, 43.027317, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002963C00000020000310C0F .go xyz -11075.125 1498.0781 42.9732

-- Pathing for  Entry: 42400 'TDB FORMAT' 
SET @NPC := 274372;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11213.417, `position_y`= 1571.7726, `position_z`= 30.049128 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11213.417, 1571.7726, 30.049128, 0, 256, 0, 0, 100, 0),
(@PATH, 2, -11193.351, 1581.8317, 27.935528, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11178.163, 1572.776, 23.184837, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11172.842, 1557.4098, 20.790623, 0, 269, 0, 0, 100, 0),
(@PATH, 5, -11178.163, 1572.776, 23.184837, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -11193.351, 1581.8317, 27.935528, 0, 0, 0, 0, 100, 0);
-- 0x2416D400002968000000020000310C12 .go xyz -11213.417 1571.7726 30.049128

-- Pathing for  Entry: 42400 'TDB FORMAT' 
SET @NPC := 274382;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11167.911, `position_y`= 1533.7118, `position_z`= 20.145185 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11167.911, 1533.7118, 20.145185, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -11171.504, 1542.6875, 20.558144, 0, 13, 0, 0, 100, 0),
(@PATH, 3, -11167.911, 1533.7118, 20.145185, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11156.196, 1529.1406, 19.40713, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11158.679, 1530.1093, 19.572702, 0, 4, 0, 0, 100, 0),
(@PATH, 6, -11156.196, 1529.1406, 19.40713, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11167.911, 1533.7118, 20.145185, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -11171.504, 1542.6875, 20.558144, 0, 17, 0, 0, 100, 0),
(@PATH, 9, -11167.911, 1533.7118, 20.145185, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -11156.196, 1529.1406, 19.40713, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -11137.79, 1513.1146, 23.362255, 0, 53, 0, 0, 100, 0),
(@PATH, 12, -11156.196, 1529.1406, 19.40713, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -11153.926, 1527.1638, 19.5732, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -11171.504, 1542.6875, 20.558144, 0, 137, 0, 0, 100, 0),
(@PATH, 15, -11167.911, 1533.7118, 20.145185, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -11156.196, 1529.1406, 19.40713, 0, 0, 0, 0, 100, 0);
-- 0x2416D400002968000000020000310C16 .go xyz -11167.911 1533.7118 20.145185

-- Pathing for  Entry: 42400 'TDB FORMAT' 
SET @NPC := 274368;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11230.761, `position_y`= 1554.7379, `position_z`= 34.73255 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79143');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11230.761, 1554.7379, 34.73255, 0, 187, 0, 0, 100, 0),
(@PATH, 2, -11259.129, 1558.4271, 34.454914, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -11255.139, 1579.4479, 34.44177, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11248.591, 1590.4236, 34.076702, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -11228.671, 1595.7623, 32.217243, 0, 400, 0, 0, 100, 0),
(@PATH, 6, -11231.41, 1595.0281, 32.490036, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -11255.139, 1579.4479, 34.44177, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -11259.129, 1558.4271, 34.454914, 0, 0, 0, 0, 100, 0);
-- 0x2416D400002968000000020000310C19 .go xyz -11230.761 1554.7379 34.73255

-- Pathing for  Entry: 42400 'TDB FORMAT' 
SET @NPC := 274591;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10937.196, `position_y`= 1537.2048, `position_z`= 46.683098 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '79116');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10937.196, 1537.2048, 46.683098, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -10942.736, 1519.7535, 44.636894, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10952.351, 1516.0192, 43.451714, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10980.549, 1516.1719, 43.118317, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10988.396, 1529.4202, 44.772003, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10995.185, 1549.7622, 44.62092, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -10998.007, 1577.1406, 45.989323, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10984.364, 1583.4062, 45.989323, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10961.995, 1585.1389, 46.72698, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10946.411, 1584.6719, 48.648, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -10936.478, 1573.1372, 47.54302, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -10938.024, 1552.8942, 45.669304, 0, 0, 0, 0, 100, 0);
-- 0x2416D400002968000000020000B10C1F .go xyz -10937.196 1537.2048 46.683098

-- Pathing for  Entry: 42407 'TDB FORMAT' 
SET @NPC := 274760;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10916.342, `position_y`= 1520.9185, `position_z`= 51.557682 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10916.342, 1520.9185, 51.557682, 0, 272, 0, 0, 100, 0),
(@PATH, 2, -10910.208, 1533.3854, 53.97356, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10904.083, 1540.1632, 54.555347, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10884.02, 1540.0677, 54.58401, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10873.125, 1536.4341, 53.7908, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10863.913, 1526.2692, 49.79083, 0, 124, 0, 0, 100, 0),
(@PATH, 7, -10873.125, 1536.4341, 53.7908, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10884.02, 1540.0677, 54.58401, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10904.083, 1540.1632, 54.555347, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10910.208, 1533.3854, 53.97356, 0, 0, 0, 0, 100, 0);
-- 0x2016D400002969C00000020001B10C08 .go xyz -10916.342 1520.9185 51.557682

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 3 WHERE `guid` IN (274453, 274446, 274449, 274462, 274451, 274434, 274425, 274447, 274450, 274428, 274385, 274387, 274386, 274383, 274377, 274379, 274373, 274361, 274360, 274370, 274352, 274353, 274725, 274539, 274614, 274497, 274524, 274496);
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 2 WHERE `guid`= 274435;
DELETE FROM `creature_addon` WHERE `guid` IN (274443, 274439, 274429, 274423, 274426, 274445, 274444, 274440, 274431, 274384, 274380, 274381, 274378, 274376, 274375, 274374, 274362, 274360, 274371, 274369, 274354, 274356, 274349, 274355, 274358, 274532);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES
(274443, 1, 1, ''),
(274439, 1, 1, ''),
(274429, 1, 1, ''),
(274423, 3, 1, ''),
(274426, 3, 1, ''),
(274445, 1, 1, ''),
(274444, 1, 1, ''),
(274440, 1, 1, ''),
(274431, 1, 1, ''),
(274384, 1, 1, ''),
(274380, 1, 1, ''),
(274381, 3, 1, ''),
(274378, 1, 1, ''),
(274376, 1, 1, ''),
(274375, 1, 1, ''),
(274374, 1, 1, ''),
(274358, 3, 1, ''),
(274362, 1, 1, ''),
(274360, 1, 1, ''),
(274371, 3, 1, ''),
(274369, 1, 1, ''),
(274354, 3, 1, ''),
(274356, 3, 1, ''),
(274349, 1, 1, ''),
(274355, 3, 1, ''),
(274532, 1, 1, '');

-- Correct npc flags
UPDATE `creature_template` SET `npcflag`= 0 WHERE `entry` IN (42386, 42384, 42391);
