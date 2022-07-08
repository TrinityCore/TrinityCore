-- Waypoints for 650022 (Entry: 132659 - veiled-riftblade)
 SET @CGUID := 650022;
 SET @PATH := @CGUID * 10;
 DELETE FROM `waypoint_data` WHERE `id`= @PATH;
 INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
 (@PATH, 0, 2110.74, 3325.3, 55.0659, 0, 0, 0, 0, 100, 0),
 (@PATH, 1, 2112.68, 3325.87, 55.2172, 0, 0, 0, 0, 100, 0),
 (@PATH, 2, 2118.86, 3326.29, 54.9672, 0, 0, 0, 0, 100, 0),
 (@PATH, 3, 2123.43, 3325.14, 54.8422, 0, 0, 0, 0, 100, 0),
 (@PATH, 4, 2126.91, 3319.69, 54.7172, 0, 0, 0, 0, 100, 0),
 (@PATH, 5, 2128.23, 3313.1, 54.7172, 0, 0, 0, 0, 100, 0),
 (@PATH, 6, 2126.03, 3308.25, 55.0403, 0, 0, 0, 0, 100, 0),
 (@PATH, 7, 2123.25, 3305.33, 55.1947, 0, 0, 0, 0, 100, 0),
 (@PATH, 8, 2119.69, 3303.65, 55.0172, 0, 0, 0, 0, 100, 0),
 (@PATH, 9, 2113.92, 3304.17, 54.7172, 0, 0, 0, 0, 100, 0),
 (@PATH, 10, 2105.08, 3305.9, 54.4879, 0, 0, 0, 0, 100, 0),
 (@PATH, 11, 2097.5, 3308.19, 54.6971, 0, 0, 0, 0, 100, 0),
 (@PATH, 12, 2087.47, 3312.49, 55.4686, 0, 0, 0, 0, 100, 0),
 (@PATH, 13, 2082.64, 3314.45, 56.0273, 0, 0, 0, 0, 100, 0),
 (@PATH, 14, 2082.64, 3314.45, 56.0273, 0, 0, 0, 0, 100, 0),
 (@PATH, 15, 2082.64, 3314.45, 56.0273, 0, 0, 0, 0, 100, 0),
 (@PATH, 16, 2082.64, 3314.45, 56.0273, 0, 0, 0, 0, 100, 0),
 (@PATH, 17, 2076.78, 3318.1, 56.3617, 0, 0, 0, 0, 100, 0),
 (@PATH, 18, 2070.05, 3325.42, 57.0473, 0, 0, 0, 0, 100, 0),
 (@PATH, 19, 2061.91, 3333.73, 58.2271, 0, 0, 0, 0, 100, 0),
 (@PATH, 20, 2058.68, 3337.04, 57.9553, 0, 0, 0, 0, 100, 0),
 (@PATH, 21, 2052.94, 3344.77, 57.9228, 0, 0, 0, 0, 100, 0),
 (@PATH, 22, 2050.2, 3351.46, 58.1259, 0, 0, 0, 0, 100, 0),
 (@PATH, 23, 2049.41, 3356.56, 57.7374, 0, 0, 0, 0, 100, 0),
 (@PATH, 24, 2051.74, 3361.04, 57.4626, 0, 0, 0, 0, 100, 0),
 (@PATH, 25, 2056.82, 3363.64, 57.0072, 0, 0, 0, 0, 100, 0),
 (@PATH, 26, 2061.28, 3361.73, 56.8679, 0, 0, 0, 0, 100, 0),
 (@PATH, 27, 2063.88, 3356.53, 56.9626, 0, 0, 0, 0, 100, 0),
 (@PATH, 28, 2065.25, 3348.35, 57.2413, 0, 0, 0, 0, 100, 0),
 (@PATH, 29, 2065.1, 3342.96, 57.619, 0, 0, 0, 0, 100, 0),
 (@PATH, 30, 2069.77, 3335.83, 58.103, 0, 0, 0, 0, 100, 0),
 (@PATH, 31, 2074.22, 3330.93, 57.5512, 0, 0, 0, 0, 100, 0),
 (@PATH, 32, 2080.84, 3326.52, 56.7585, 0, 0, 0, 0, 100, 0),
 (@PATH, 33, 2087.45, 3325.22, 55.9707, 0, 0, 0, 0, 100, 0),
 (@PATH, 34, 2100.52, 3325.96, 54.8422, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2110.738, `position_y`= 3325.302, `position_z`= 55.06594, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 257);

-- Waypoints for 650020 (Entry: 132648 - rift-warden)
SET @CGUID := 650016;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 2055.53, 3388.04, 55.6295, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 2054.85, 3379.7, 55.6295, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 2054.96, 3372.37, 56.0996, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2054.88, 3362.98, 57.3199, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2055.95, 3353.85, 57.5614, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 2059.92, 3344.84, 57.2126, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2067.14, 3332.45, 57.9902, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2072.94, 3324.88, 56.8858, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2082.05, 3314.14, 56.0273, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2086.39, 3308.65, 55.5273, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 2089.58, 3304.28, 55.6141, 0, 14012, 0, 0, 100, 0),
(@PATH, 11, 2086.47, 3308.54, 55.4262, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 2082.05, 3314.14, 56.0273, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 2072.94, 3324.88, 56.8858, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 2067.14, 3332.45, 57.9902, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 2059.92, 3344.84, 57.2126, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 2055.95, 3353.85, 57.5614, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 2054.88, 3362.98, 57.3199, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 2054.96, 3372.37, 56.0996, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 2054.85, 3379.7, 55.6295, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 2055.53, 3388.04, 55.6295, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 2058.24, 3396.74, 55.6295, 0, 13252, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2055.53, `position_y`= 3388.04, `position_z`= 55.62954, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 256);

-- Waypoints for 650020 (Entry: 132648 - veiled-riftblade)
SET @CGUID := 650020;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 2074.65, 3361.83, 57.5111, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 2081.07, 3366.32, 58.2821, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 2087.66, 3370.52, 58.6123, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2096.25, 3372.34, 58.2373, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2102.29, 3372.8, 58.2044, 0, 4908, 0, 0, 100, 0),
(@PATH, 5, 2096.25, 3372.34, 58.2373, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2087.66, 3370.52, 58.6123, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2081.07, 3366.32, 58.2821, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2074.65, 3361.83, 57.5111, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2067.4, 3356.73, 56.9907, 0, 4857, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2074.649, `position_y`= 3361.826, `position_z`= 57.51105, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 256);

-- Waypoints for 650048 (Entry: 132407 - umbral-ranger)
SET @CGUID := 650048;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 2087.74, 3425.45, 74.8456, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 2093.93, 3428.3, 74.4979, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 2099.23, 3429.01, 73.8986, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2103.87, 3429.52, 73.7585, 0, 97, 0, 0, 100, 0),
(@PATH, 4, 2099.38, 3429.03, 73.9124, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 2093.93, 3428.3, 74.4979, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2087.74, 3425.45, 74.8456, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2082.82, 3420.57, 74.7094, 0, 48665, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2087.74, `position_y`= 3425.445, `position_z`= 74.84563, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 258);

-- Waypoints for 650046 (Entry: 132407 - umbral-ranger)
SET @CGUID := 650046;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 2036.53, 3379.05, 51.967, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 2036.94, 3374.17, 52.5641, 0, 4999, 0, 0, 100, 0),
(@PATH, 2, 2036.53, 3379.05, 51.967, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2036.18, 3384.9, 51.6257, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2036.26, 3391.73, 51.5781, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 2038.15, 3399.91, 51.7246, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2043.04, 3408.97, 51.448, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2046.28, 3413.06, 51.5613, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2049.61, 3416.24, 51.8443, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2052.34, 3417.68, 52.3157, 0, 3401, 0, 0, 100, 0),
(@PATH, 10, 2046.28, 3413.06, 51.5613, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 2043.04, 3408.97, 51.448, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 2038.15, 3399.91, 51.7246, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2036.533, `position_y`= 3379.05, `position_z`= 51.96703, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 258);

-- Waypoints for 650066 (Entry: 132407 - umbral-ranger)
SET @CGUID := 650066;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 1806.21, 3289.8, 88.6177, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 1806.64, 3295.07, 89.5579, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1809.53, 3301.15, 89.6783, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1812.86, 3305.64, 89.563, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1818.88, 3312, 90.081, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1823.58, 3317.65, 90.7272, 0, 4926, 0, 0, 100, 0),
(@PATH, 6, 1818.51, 3312.28, 90.1258, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1812.93, 3305.94, 89.589, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1809.45, 3301.21, 89.6994, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1806.47, 3295.67, 89.6733, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1806.08, 3290.12, 88.712, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1807.95, 3281.88, 86.5253, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1809.68, 3273.35, 84.3528, 0, 4881, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 1806.215, `position_y`= 3289.798, `position_z`= 88.61772, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 258);

-- Waypoints for 650038 (Entry: 132407 - umbral-ranger)
SET @CGUID := 650038;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 2037.19, 3261.4, 59.9423, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 2036.62, 3266.64, 59.8383, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 2037.43, 3271.47, 59.6047, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 2038.93, 3276.01, 59.3113, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 2039.08, 3280.96, 59.0656, 0, 6315, 0, 0, 100, 0),
(@PATH, 5, 2038.93, 3276.01, 59.3113, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2037.43, 3271.47, 59.6047, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 2036.62, 3266.64, 59.8383, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 2037.19, 3261.4, 59.9423, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 2038.05, 3258.44, 59.8121, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 2039.29, 3256.64, 59.6799, 0, 5084, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 2037.189, `position_y`= 3261.398, `position_z`= 59.94227, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 258);

-- creature formation (GUID: 650046 & 650047)
SET @CLEADER := 650046;
SET @CMEMBER := 650047;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CLEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CLEADER, @CLEADER, 0, 0, 515, 0, 0),
(@CLEADER, @CMEMBER, 2, 90, 515, 9, 0);

-- creature formation (GUID: 650038 & 650019)
SET @CLEADER := 650038;
SET @CMEMBER := 650019;
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CLEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CLEADER, @CLEADER, 0, 0, 515, 0, 0),
(@CLEADER, @CMEMBER, 2, 270, 515, 4, 10);
