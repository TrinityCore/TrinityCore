-- Pathing for  Entry: 36602 'TDB FORMAT' 
SET @NPC := 255575;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2194.741, `position_y`= 2291.962, `position_z`= 7.864716 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2194.741, 2291.962, 7.864716, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2225, 2293.229, 7.518183, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2232.035, 2295.972, 6.486444, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2245.835, 2301.55, 5.613362, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2257.273, 2307.658, 5.426106, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2278.813, 2327.274, 5.529029, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -2290.639, 2331.924, 4.694418, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -2301.132, 2326.5, 2.868995, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -2309.076, 2318.417, 1.048316, 0, 4, 0, 0, 100, 0),
(@PATH, 10, -2301.132, 2326.5, 2.868995, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -2290.639, 2331.924, 4.694418, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -2279.007, 2327.247, 5.528661, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -2257.273, 2307.658, 5.426106, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -2245.835, 2301.55, 5.613362, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -2232.035, 2295.972, 6.486444, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -2225.646, 2293.498, 7.470819, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -2194.741, 2291.962, 7.864716, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -2184.188, 2289.774, 8.699677, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -2175.34, 2287.26, 9.318817, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -2169.406, 2287.519, 9.783539, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -2165.29, 2288.321, 10.19825, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -2165.399, 2294.276, 9.74281, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -2173.533, 2309.679, 7.470339, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -2184.582, 2325.38, 4.580813, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -2193.455, 2341.358, 2.922411, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -2195.497, 2358.366, 1.422411, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -2193.556, 2379.188, 1.99852, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -2182.62, 2393.875, 5.182358, 0, 0, 0, 0, 100, 0),
(@PATH, 29, -2168.689, 2405.677, 10.59824, 0, 396, 0, 0, 100, 0),
(@PATH, 30, -2182.62, 2393.875, 5.182358, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -2193.556, 2379.188, 1.99852, 0, 0, 0, 0, 100, 0),
(@PATH, 32, -2195.497, 2358.366, 1.422411, 0, 0, 0, 0, 100, 0),
(@PATH, 33, -2193.455, 2341.358, 2.922411, 0, 0, 0, 0, 100, 0),
(@PATH, 34, -2184.582, 2325.38, 4.580813, 0, 0, 0, 0, 100, 0),
(@PATH, 35, -2173.533, 2309.679, 7.470339, 0, 0, 0, 0, 100, 0),
(@PATH, 36, -2165.399, 2294.276, 9.74281, 0, 0, 0, 0, 100, 0),
(@PATH, 37, -2165.29, 2288.321, 10.19825, 0, 0, 0, 0, 100, 0),
(@PATH, 38, -2169.406, 2287.519, 9.783539, 0, 0, 0, 0, 100, 0),
(@PATH, 39, -2175.34, 2287.26, 9.318817, 0, 0, 0, 0, 100, 0),
(@PATH, 40, -2184.188, 2289.774, 8.699677, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C023BE80000A5200057BE97A .go xyz -2194.741 2291.962 7.864716

-- Pathing for  Entry: 36602 'TDB FORMAT' 
SET @NPC := 255495;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1934.457, `position_y`= 2199.648, `position_z`= 29.0159 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1934.457, 2199.648, 29.0159, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1935.224, 2212.201, 32.56932, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1931.167, 2222.351, 35.47858, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1920.16, 2233.92, 39.22011, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1911.747, 2242.193, 41.96523, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1920.16, 2233.92, 39.22011, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1931.167, 2222.351, 35.47858, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1935.224, 2212.201, 32.56932, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C023BE80000A520005FBE97A .go xyz -1934.457 2199.648 29.0159

-- Pathing for  Entry: 36602 'TDB FORMAT' 
SET @NPC := 255484;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1946.13, `position_y`= 2319.274, `position_z`= 34.76398 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1946.13, 2319.274, 34.76398, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1943.356, 2333.33, 34.26447, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1937.304, 2351.054, 32.67007, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1946.13, 2319.274, 34.76398, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1947.467, 2314.467, 34.95734, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1953.241, 2308.766, 34.68781, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1970.977, 2317.913, 31.41698, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1988.578, 2321.609, 28.85362, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1976.986, 2319.983, 30.47459, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1953.944, 2308.573, 34.60358, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1951.418, 2302.773, 35.63654, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1947.424, 2291.991, 37.5909, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1939.96, 2282.712, 40.22494, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1947.424, 2291.991, 37.5909, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1951.418, 2302.773, 35.63654, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1953.944, 2308.573, 34.60358, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -1970.977, 2317.913, 31.41698, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -1988.578, 2321.609, 28.85362, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -1976.986, 2319.983, 30.47459, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -1953.944, 2308.573, 34.60358, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -1947.467, 2314.467, 34.95734, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C023BE80000A5200067BE97A .go xyz -1946.13 2319.274 34.76398

-- Pathing for  Entry: 36602 'TDB FORMAT' 
SET @NPC := 255580;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2091.122, `position_y`= 2395.448, `position_z`= 9.130095 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2091.122, 2395.448, 9.130095, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2101.681, 2395.776, 9.618845, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2113.665, 2397.951, 11.11884, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2101.681, 2395.776, 9.618845, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2091.122, 2395.448, 9.130095, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2079.682, 2398.889, 9.380095, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -2066.559, 2403.736, 10.71501, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -2053.122, 2405.689, 12.20256, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -2038.358, 2405.059, 13.80474, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -2027.08, 2402.998, 15.03127, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -2010.54, 2395.877, 18.18131, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1996.842, 2393.722, 20.54385, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1982.078, 2389.585, 23.77822, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1996.842, 2393.722, 20.54385, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -2010.54, 2395.877, 18.18131, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -2027.08, 2402.998, 15.03127, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -2038.358, 2405.059, 13.80474, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -2053.122, 2405.689, 12.20256, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -2066.559, 2403.736, 10.71501, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -2079.682, 2398.889, 9.380095, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C023BE80000A520006FBE97A .go xyz -2091.122 2395.448 9.130095

-- Pathing for  Entry: 36453 'TDB FORMAT' 
SET @NPC := 255464;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0, `position_x`= -1894.193, `position_y`= 2257.021, `position_z`= 42.44826, `spawntimesecs`= 10 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -1894.193, 2257.021, 42.44826),
(@PATH, 2, -1916.847, 2239.845, 40.91469),
(@PATH, 3, -1927.254, 2227.689, 36.98933),
(@PATH, 4, -1939.424, 2230.359, 36.1411),
(@PATH, 5, -1941.524, 2248.212, 35.74326);
-- 0x2016DC51C0239940000A5200007C732F .go xyz -1894.193 2257.021 42.44826

-- Creature Duskhaven Villager 36453 SAI
SET @ENTRY := 36453;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -255464;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 53, 0, 2554640, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Start path #2554640, walk, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 5, 2554640, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 5 of path 2554640 reached - Self: Despawn instantly // ");

-- Pathing for  Entry: 36453 'TDB FORMAT' 
SET @NPC := 255608;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1873.366, `position_y`= 2279.368, `position_z`= 42.2726 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1873.366, 2279.368, 42.2726, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1860.163, 2292.927, 42.37807, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1842.648, 2312.363, 39.95538, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1855.878, 2297.681, 42.34389, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1860.163, 2292.927, 42.37807, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1873.366, 2279.368, 42.2726, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1887.168, 2264.307, 42.44826, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1894.903, 2256.849, 42.44826, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1903.941, 2248.106, 42.43593, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1894.903, 2256.849, 42.44826, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1887.168, 2264.307, 42.44826, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C0239940000A5200067BE97A .go xyz -1873.366 2279.368 42.2726

-- Pathing for  Entry: 36528 'TDB FORMAT' 
SET @NPC := 255888;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2191.427, `position_y`= 2210.014, `position_z`= 16.85409 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2191.427, 2210.014, 16.85409, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2192.771, 2240.549, 10.35777, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2191.427, 2210.014, 16.85409, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2180.431, 2185.913, 17.17649, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2143.8, 2179.517, 21.92157, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2180.431, 2185.913, 17.17649, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C023AC00000A5200007BE97A .go xyz -2191.427 2210.014 16.85409

-- Pathing for  Entry: 37499 'TDB FORMAT' 
SET @NPC := 256175;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2429.564, `position_y`= 1519.872, `position_z`= 16.55267 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2429.564, 1519.872, 16.55267, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2441.924, 1518.691, 16.8201, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2429.564, 1519.872, 16.55267, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2402.613, 1519.833, 9.752254, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2372.38, 1512.417, 3.916122, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2402.613, 1519.833, 9.752254, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C0249EC0000A520000FBE97A .go xyz -2429.564 1519.872 16.55267

-- Pathing for  Entry: 37499 'TDB FORMAT' 
SET @NPC := 256149;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2474.689, `position_y`= 1504.384, `position_z`= 16.57015 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2474.689, 1504.384, 16.57015, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2474.722, 1522.802, 16.65865, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2475.073, 1549.606, 16.56605, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2475.033, 1569.531, 16.46894, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2475.073, 1549.606, 16.56605, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2474.722, 1522.802, 16.65865, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C0249EC0000A5200047BE97A .go xyz -2474.689 1504.384 16.57015

-- Pathing for  Entry: 37716 'TDB FORMAT' 
SET @NPC := 256376;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1920.988, `position_y`= 915.0052, `position_z`= 80.65214 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1920.988, 915.0052, 80.65214, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1940.851, 919.7361, 77.1021, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1920.988, 915.0052, 80.65214, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1904.314, 919.3108, 81.12821, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1877.561, 940.7153, 78.46329, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1883.273, 971.4636, 76.76004, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1886.76, 988.5417, 75.08572, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1880.538, 1013.764, 69.19176, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1879.96, 1030.516, 65.19395, 0, 147, 0, 0, 100, 0),
(@PATH, 10, -1880.538, 1013.764, 69.19176, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1886.76, 988.5417, 75.08572, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1883.273, 971.4636, 76.76004, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1877.561, 940.7153, 78.46329, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1904.314, 919.3108, 81.12821, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D500000A5200007C3E2C .go xyz -1920.988 915.0052 80.65214

UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0, `position_x`= -1920.988, `position_y`= 915.0052, `position_z`= 80.65214 WHERE `guid`= 256377;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 256376;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(256376, 256376, 0, 0, 515, 0, 0),
(256376, 256377, 3.5, 45, 515, 0, 0);

-- Pathing for  Entry: 37716 'TDB FORMAT' 
SET @NPC := 256338;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1994.333, `position_y`= 901.1597, `position_z`= 57.28863 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1994.333, 901.1597, 57.28863, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1987.087, 884.1893, 60.00602, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1977.618, 866.3299, 64.44198, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1977.663, 850.1233, 64.31698, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1993.066, 835.0243, 66.02936, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2004.243, 827.3108, 66.02936, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1993.066, 835.0243, 66.02936, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1977.663, 850.1233, 64.31698, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1977.618, 866.3299, 64.44198, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1987.087, 884.1893, 60.00602, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D500000A5200007C6A37 .go xyz -1994.333 901.1597 57.28863

UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0, `position_x`= -1994.333, `position_y`= 901.1597, `position_z`= 57.28863 WHERE `guid`= 256339;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 256338;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(256338, 256338, 0, 0, 515, 0, 0),
(256338, 256339, 3.5, 45, 515, 0, 0);

-- Pathing for  Entry: 37716 'TDB FORMAT' 
SET @NPC := 256335;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2067.856, `position_y`= 969.2118, `position_z`= 68.70877 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2067.856, 969.2118, 68.70877, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2078.332, 985.2656, 65.64993, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -2088.236, 996.8246, 63.32449, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2078.332, 985.2656, 65.64993, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2067.856, 969.2118, 68.70877, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2056.203, 951.6406, 70.049, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -2038.592, 942.6163, 69.044, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -2019.125, 939.7743, 64.905, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -2009.146, 933.618, 62.09396, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -2019.125, 939.7743, 64.905, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -2038.592, 942.6163, 69.044, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -2056.203, 951.6406, 70.049, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D500000A5200007C777B .go xyz -2067.856 969.2118 68.70877

UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0, `position_x`= -2067.856, `position_y`= 969.2118, `position_z`= 68.70877 WHERE `guid`= 256337;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 256335;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(256335, 256335, 0, 0, 515, 0, 0),
(256335, 256337, 3.5, 45, 515, 0, 0);

-- Pathing for  Entry: 37735 'TDB FORMAT' 
SET @NPC := 256380;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -2092.382, `position_y`= 765.0938, `position_z`= 94.48202 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -2092.382, 765.0938, 94.48202, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -2090.931, 753.4097, 94.33138, 0, 138, 0, 0, 100, 0),
(@PATH, 3, -2092.382, 765.0938, 94.48202, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -2098.059, 774.8611, 94.13759, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -2100.215, 785.7813, 90.1011, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -2102.316, 790.4809, 89.92068, 0, 46, 0, 0, 100, 0),
(@PATH, 7, -2100.215, 785.7813, 90.1011, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -2098.088, 774.9854, 94.13808, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D9C0000A5200007C75FB .go xyz -2092.382 765.0938 94.48202

-- Pathing for  Entry: 37733 'TDB FORMAT' 
SET @NPC := 256416;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1903.321, `position_y`= 956.8455, `position_z`= 76.66547 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1903.321, 956.8455, 76.66547, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1893.905, 945.5469, 77.56022, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1903.321, 956.8455, 76.66547, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1908.823, 970.6042, 76.37778, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1919.597, 983.7222, 77.73883, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1924.319, 979.8802, 77.73791, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1929.385, 984.1337, 77.73791, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1921.168, 992.6024, 86.8955, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1917.144, 988.3177, 86.89632, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1921.254, 982.8958, 86.89243, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1917.144, 988.3177, 86.89632, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1921.168, 992.6024, 86.8955, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1929.385, 984.1337, 77.73791, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1924.319, 979.8802, 77.73791, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1919.597, 983.7222, 77.73883, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1908.823, 970.6042, 76.37778, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D940000A5200007C750C .go xyz -1903.321 956.8455 76.66547

-- Pathing for  Entry: 37803 'TDB FORMAT' 
SET @NPC := 256557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1371.585, `position_y`= 1207.505, `position_z`= 35.66685 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1371.585, 1207.505, 35.66685, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1375.611, 1217.569, 35.66685, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1373.533, 1228.219, 35.66685, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1375.611, 1217.569, 35.66685, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1371.585, 1207.505, 35.66685, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1367.905, 1198.311, 35.60542, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024EAC0000A5200007BE97A .go xyz -1371.585 1207.505 35.66685

-- Pathing for  Entry: 37692 'TDB FORMAT' 
SET @NPC := 256546;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1161.3, `position_y`= 1159.146, `position_z`= 24.30762 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1161.3, 1159.146, 24.30762, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1168.967, 1147.288, 24.40761, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1174.701, 1136.983, 24.40761, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1188.795, 1129.389, 26.53261, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1202.111, 1125.109, 31.01379, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1188.91, 1129.323, 26.53969, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1174.701, 1136.983, 24.40761, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1168.967, 1147.288, 24.40761, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1161.3, 1159.146, 24.30762, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1147.311, 1167.064, 24.2856, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024CF00000A5200007C7A04 .go xyz -1161.3 1159.146 24.30762

-- Pathing for  Entry: 37692 'TDB FORMAT' 
SET @NPC := 256536;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1121.595, `position_y`= 1087.806, `position_z`= 24.21713 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1121.595, 1087.806, 24.21713, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1113.825, 1080.91, 25.50626, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1106.036, 1077.946, 25.5035, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1113.825, 1080.91, 25.50626, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1121.595, 1087.806, 24.21713, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1139.198, 1106.674, 24.40304, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1149.453, 1123.134, 24.40304, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1139.198, 1106.674, 24.40304, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024CF00000A5200007C7B48 .go xyz -1121.595 1087.806 24.21713

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256482;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1174.153, `position_y`= 931.5764, `position_z`= 24.65535 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1174.153, 931.5764, 24.65535, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1182.519, 938.8629, 26.71802, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1174.153, 931.5764, 24.65535, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1156.22, 931.8021, 24.43024, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1142.063, 924.1719, 24.92024, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1133.828, 913.3368, 25.76561, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1142.063, 924.1719, 24.92024, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1156.22, 931.8021, 24.43024, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C6735 .go xyz -1174.153 931.5764 24.65535

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256489;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1174.266, `position_y`= 910.8073, `position_z`= 22.33742 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1174.266, 910.8073, 22.33742, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1167.611, 904.9045, 22.40444, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1164.054, 893.3577, 22.43097, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1151.313, 870.2066, 25.02729, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1138.495, 860.7379, 28.21266, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1151.313, 870.2066, 25.02729, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1164.054, 893.3577, 22.43097, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1167.611, 904.9045, 22.40444, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C6D39 .go xyz -1174.266 910.8073 22.33742

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256525;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1032.212, `position_y`= 990.5695, `position_z`= 39.35429 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1032.212, 990.5695, 39.35429, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1026.731, 990.283, 39.00252, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1032.212, 990.5695, 39.35429, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1051.504, 984.1771, 43.06197, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C6D40 .go xyz -1032.212 990.5695 39.35429

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256503;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1166.602, `position_y`= 859.5695, `position_z`= 24.81995 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1166.602, 859.5695, 24.81995, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1153.026, 865.8733, 25.39171, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1143.53, 864.0608, 26.33944, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1136.766, 856.5573, 29.62898, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1143.53, 864.0608, 26.33944, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1153.026, 865.8733, 25.39171, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1166.602, 859.5695, 24.81995, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1181.953, 852.1424, 25.12563, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1194.964, 853.4114, 24.8287, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1181.953, 852.1424, 25.12563, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C6DA2 .go xyz -1166.602 859.5695 24.81995

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256468;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1216.549, `position_y`= 1039.929, `position_z`= 39.58936 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1216.549, 1039.929, 39.58936, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1220.865, 1017.769, 43.51139, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1206.929, 998.3368, 45.30154, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1220.865, 1017.769, 43.51139, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1216.549, 1039.929, 39.58936, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1205.917, 1056.165, 37.96485, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1197.384, 1073.109, 35.93882, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1196.642, 1081.526, 35.72037, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1197.396, 1081.771, 35.72037, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1203.436, 1087.87, 35.71577, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1217.953, 1092.246, 34.99638, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1203.436, 1087.87, 35.71577, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1197.396, 1081.771, 35.72037, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1196.642, 1081.526, 35.72037, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -1197.384, 1073.109, 35.93882, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -1205.917, 1056.165, 37.96485, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C78D7 .go xyz -1216.549 1039.929 39.58936

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256474;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1178.582, `position_y`= 1022.448, `position_z`= 42.33801 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1178.582, 1022.448, 42.33801, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1186.76, 1033.207, 41.87118, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1178.582, 1022.448, 42.33801, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1158.873, 1024.286, 43.32338, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1148.368, 1021.017, 43.39351, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1158.873, 1024.286, 43.32338, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C78F9 .go xyz -1178.582 1022.448 42.33801

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256514;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1094.542, `position_y`= 996.0764, `position_z`= 46.33026 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1094.542, 996.0764, 46.33026, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1082.139, 1000.153, 46.48643, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1073.005, 1004.438, 46.67006, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1066.443, 996.1389, 45.25841, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1059.972, 985.7327, 45.06297, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1056.95, 971.7188, 44.89788, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1059.948, 962.8559, 45.02491, 0, 322, 0, 0, 100, 0),
(@PATH, 8, -1056.95, 971.7188, 44.89788, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1059.91, 985.4459, 45.05038, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1066.443, 996.1389, 45.25841, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -1072.948, 1004.365, 46.66784, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -1082.139, 1000.153, 46.48643, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -1094.542, 996.0764, 46.33026, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -1103.339, 994.1389, 45.45895, 0, 9, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C7A08 .go xyz -1094.542 996.0764 46.33026

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256496;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1112.424, `position_y`= 946.7031, `position_z`= 39.90021 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1112.424, 946.7031, 39.90021, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1101.115, 942.191, 39.40974, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1083.464, 941.9739, 39.45651, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1101.115, 942.191, 39.40974, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1112.424, 946.7031, 39.90021, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1123.457, 949.6511, 40.60905, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1134.141, 951.1198, 41.30095, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1123.584, 949.6686, 40.6466, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C7A2F .go xyz -1112.424 946.7031 39.90021

-- Pathing for  Entry: 37701 'TDB FORMAT' 
SET @NPC := 256510;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1086.516, `position_y`= 887.8559, `position_z`= 37.05409 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1086.516, 887.8559, 37.05409, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1081.691, 896.4653, 36.73196, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1075.509, 912.9132, 35.19082, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1072.684, 927.7639, 38.62774, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1069.144, 938.9653, 41.08496, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1072.588, 928.0688, 38.70449, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1075.509, 912.9132, 35.19082, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -1081.691, 896.4653, 36.73196, 0, 0, 0, 0, 100, 0);
-- 0x2016DC51C024D140000A5200007C7A4A .go xyz -1086.516 887.8559 37.05409
