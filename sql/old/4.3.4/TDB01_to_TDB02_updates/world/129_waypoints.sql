UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=16378;

DELETE FROM `creature_template_addon` WHERE `entry`=16378;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(16378, 0, 0x0, 0x1, '18950'); -- Argent Sentry - Invisibility and Stealth Detection


-- Pathing for Argent Sentry Entry: 16378
SET @NPC := 194968;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES (@NPC, @PATH, 22471, 0x0, 0x1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 2237.44, -5400.96, 117.211, 0, 0, 0, 100, 0),
(@PATH, 2, 2235.81, -5394.7, 115.99, 0, 0, 0, 100, 0),
(@PATH, 3, 2230.97, -5372.34, 115.99, 0, 0, 0, 100, 0),
(@PATH, 4, 2228.99, -5348.72, 115.99, 0, 0, 0, 100, 0),
(@PATH, 5, 2227.32, -5325.12, 115.99, 0, 0, 0, 100, 0),
(@PATH, 6, 2229.28, -5293.24, 115.99, 0, 0, 0, 100, 0),
(@PATH, 7, 2245.74, -5273.1, 117.211, 0, 0, 0, 100, 0),
(@PATH, 8, 2271.47, -5248.88, 117.211, 0, 0, 0, 100, 0),
(@PATH, 9, 2318.81, -5239.94, 117.211, 0, 0, 0, 100, 0),
(@PATH, 10, 2360.32, -5243.63, 117.211, 0, 0, 0, 100, 0),
(@PATH, 11, 2375.47, -5257.36, 117.211, 0, 0, 0, 100, 0),
(@PATH, 12, 2370.16, -5268.68, 117.211, 0, 0, 0, 100, 0),
(@PATH, 13, 2357.59, -5265.74, 117.211, 0, 0, 0, 100, 0),
(@PATH, 14, 2341.25, -5247.73, 117.211, 0, 0, 0, 100, 0),
(@PATH, 15, 2319.02, -5246.36, 117.211, 0, 0, 0, 100, 0),
(@PATH, 16, 2272.53, -5255.35, 117.211, 0, 0, 0, 100, 0),
(@PATH, 17, 2250.22, -5277.42, 117.211, 0, 0, 0, 100, 0),
(@PATH, 18, 2237.29, -5294.23, 117.211, 0, 0, 0, 100, 0),
(@PATH, 19, 2233.77, -5325.5, 117.211, 0, 0, 0, 100, 0),
(@PATH, 20, 2235.45, -5348.52, 117.211, 0, 0, 0, 100, 0),
(@PATH, 21, 2237.37, -5371.82, 117.211, 0, 0, 0, 100, 0),
(@PATH, 22, 2242.49, -5384.33, 117.211, 0, 0, 0, 100, 0),
(@PATH, 23, 2247.05, -5398.4, 117.211, 0, 0, 0, 100, 0);

-- Pathing for Argent Sentry Entry: 16378
SET @NPC := 194970;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES (@NPC, @PATH, 22471, 0x0, 0x1, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 2220.95, -5335.59, 100.981, 0, 0, 0, 100, 0),
(@PATH, 2, 2234, -5340.95, 98.9156, 0, 0, 0, 100, 0),
(@PATH, 3, 2254.38, -5336.1, 100.981, 0, 0, 0, 100, 0),
(@PATH, 4, 2281.87, -5319.98, 99.7444, 0, 0, 0, 100, 0),
(@PATH, 5, 2324.23, -5290.13, 99.5274, 0, 0, 0, 100, 0),
(@PATH, 6, 2365.94, -5259.19, 94.3286, 0, 0, 0, 100, 0),
(@PATH, 7, 2374.89, -5241.55, 94.85, 0, 0, 0, 100, 0),
(@PATH, 8, 2357.65, -5229.59, 100.98, 0, 0, 0, 100, 0),
(@PATH, 9, 2325.25, -5222.08, 100.981, 0, 0, 0, 100, 0),
(@PATH, 10, 2290.85, -5225.84, 98.0954, 0, 0, 0, 100, 0),
(@PATH, 11, 2248.95, -5251.47, 96.0214, 0, 0, 0, 100, 0),
(@PATH, 12, 2222.48, -5286.32, 96.0582, 0, 0, 0, 100, 0),
(@PATH, 13, 2213.03, -5315.6, 99.8534, 0, 0, 0, 100, 0);
