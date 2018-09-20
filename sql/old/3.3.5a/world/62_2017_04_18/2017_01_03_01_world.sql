-- ========================================
-- Caverns of Time: Old Hillsbrad Foothills
-- ========================================

-- ========================================================
-- All Bosses and Heroic Bosses Are Immune To Crowd Control -- Daze, Horror, Shackle, Banish, Polymorph, Knockout, Freeze, Stun, Snare, Sleep, Silence, Pacify, Root, Fear, Distract, Disarm, Confused, Charm
-- ========================================================
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|16384 WHERE `entry` IN (17848,20535,17862,20521,18096,20531);
-- =========================================
-- REMOVE NPC SPAWNS (WILL REUSE GUID)
-- =========================================
-- Removed Spawns - Reuse GUID
DELETE FROM `creature` WHERE `guid` IN (83932,83972,84001);
DELETE FROM `creature_addon` WHERE `guid` IN (83932,83972,84001);
-- =========================================
-- Dungeon Aggro Linking and Missing Pathing
-- =========================================
-- First Sentry
UPDATE `creature` SET `position_x` = 2076.810547, `position_y` = 221.063431, `position_z` = 64.874046, `orientation` = 2.525145 WHERE `guid` = 83909;

-- Group Inside Left Side
UPDATE `creature` SET `position_x` = 2120.338867, `position_y` = 218.720917, `position_z` = 64.943527, `orientation` = 1.668277 WHERE `guid` = 83904;
UPDATE `creature` SET `position_x` = 2119.321777, `position_y` = 223.663712, `position_z` = 64.875153, `orientation` = 4.992080 WHERE `guid` = 83903;

DELETE FROM `creature_formations` WHERE `leaderGUID`=83904;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83904, 83904, 0, 0, 2, 0, 0),
(83904, 83903, 0, 0, 2, 0, 0);

-- Patrol Left Side
DELETE FROM `creature_formations` WHERE `leaderGUID`=83910;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83910, 83910, 0, 0, 2, 0, 0),
(83910, 83911, 3, 0, 2, 0, 0);

SET @NPC := 83910;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2125.69, 244.969, 64.8252, 0),
(@PATH, 2, 2131.14, 252.046, 64.6015, 0),
(@PATH, 3, 2139.33, 256.24, 64.7451, 0),
(@PATH, 4, 2150.85, 267.235, 64.6691, 0),
(@PATH, 5, 2155.83, 274.518, 64.5514, 0),
(@PATH, 6, 2163.31, 279.487, 64.169, 0),
(@PATH, 7, 2175.15, 282.002, 64.6837, 0),
(@PATH, 8, 2163.53, 279.529, 64.0731, 0),
(@PATH, 9, 2155.76, 274, 64.4975, 0),
(@PATH, 10, 2150.68, 266.361, 64.7104, 0),
(@PATH, 11, 2139.27, 255.903, 64.7643, 0),
(@PATH, 12, 2131.48, 252.035, 64.5098, 0),
(@PATH, 13, 2125.25, 244.493, 64.8279, 0),
(@PATH, 14, 2119.97, 233.879, 64.8725, 0),
(@PATH, 15, 2112.98, 230.424, 65.0613, 0),
(@PATH, 16, 2106.37, 226.722, 65.8853, 0),
(@PATH, 17, 2120.01, 233.507, 64.8737, 0);

-- 2 Guards on Bridge
DELETE FROM `creature_formations` WHERE `leaderGUID`=83901;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83901, 83901, 0, 0, 2, 0, 0),
(83901, 83902, 0, 0, 2, 0, 0);

-- 2 Guards on Bridge
DELETE FROM `creature_formations` WHERE `leaderGUID`=83912;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83912, 83912, 0, 0, 2, 0, 0),
(83912, 83913, 0, 0, 2, 0, 0);

-- NPC Pathing Over Bridge Up Hill
DELETE FROM `creature_formations` WHERE `leaderGUID`=83907;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83907, 83907, 0, 0, 2, 0, 0),
(83907, 83906, 3, 0, 2, 0, 0);

SET @NPC := 83907;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2133.25, 175.897, 68.2518, 0),
(@PATH, 2, 2142.45, 168.965, 66.2217, 0),
(@PATH, 3, 2143.95, 162.492, 65.283, 0),
(@PATH, 4, 2139.32, 154.392, 67.4044, 0),
(@PATH, 5, 2138.23, 143.395, 70.7358, 0),
(@PATH, 6, 2139.97, 132.573, 74.0745, 0),
(@PATH, 7, 2142.59, 126.72, 75.6225, 0),
(@PATH, 8, 2146.19, 125.347, 76.3226, 0),
(@PATH, 9, 2153.81, 128.848, 79.1896, 0),
(@PATH, 10, 2161.36, 135.221, 83.6257, 0),
(@PATH, 11, 2169.32, 144.168, 87.0686, 0),
(@PATH, 12, 2176.57, 157.486, 87.5667, 0),
(@PATH, 13, 2182.25, 166.023, 88.0925, 0),
(@PATH, 14, 2190.15, 171.974, 88.9953, 0),
(@PATH, 15, 2198.18, 175.07, 90.0099, 0),
(@PATH, 16, 2211.11, 177.332, 93.1255, 0),
(@PATH, 17, 2218.76, 179.856, 96.8824, 0),
(@PATH, 18, 2211.71, 177.317, 93.3128, 0),
(@PATH, 19, 2198.41, 175.057, 90.0273, 0),
(@PATH, 20, 2190.48, 171.961, 89.0125, 0),
(@PATH, 21, 2182.36, 165.732, 88.0739, 0),
(@PATH, 22, 2176.82, 157.265, 87.5719, 0),
(@PATH, 23, 2169.84, 144.243, 87.1995, 0),
(@PATH, 24, 2161.79, 135.187, 83.7742, 0),
(@PATH, 25, 2153.85, 128.339, 79.1086, 0),
(@PATH, 26, 2146.26, 125.303, 76.3378, 0),
(@PATH, 27, 2142.64, 126.864, 75.6126, 0),
(@PATH, 28, 2139.95, 133.04, 73.9752, 0),
(@PATH, 29, 2138.51, 143.182, 70.7858, 0),
(@PATH, 30, 2139.87, 154.51, 67.3187, 0),
(@PATH, 31, 2144.53, 162.434, 65.2721, 0),
(@PATH, 32, 2142.94, 168.955, 66.2216, 0),
(@PATH, 33, 2133.65, 175.448, 68.0162, 0),
(@PATH, 34, 2121.96, 184.319, 69.1957, 0),
(@PATH, 35, 2111.52, 191.525, 66.2216, 0),
(@PATH, 36, 2105.32, 194.886, 65.1854, 0),
(@PATH, 37, 2097.08, 196.945, 65.2138, 0),
(@PATH, 38, 2087.51, 206.91, 64.8803, 0),
(@PATH, 39, 2073.1, 218.576, 64.8744, 0),
(@PATH, 40, 2087.7, 206.877, 64.8792, 0),
(@PATH, 41, 2097.34, 196.53, 65.2196, 0),
(@PATH, 42, 2106.11, 194.526, 65.4583, 0),
(@PATH, 43, 2111.96, 191.221, 66.2215, 0),
(@PATH, 44, 2119.36, 186.393, 68.9396, 0);

-- Spectator Pit
UPDATE `creature` SET `position_x` = 2175.081055, `position_y` = 53.507755, `position_z` = 66.141853, `orientation` = 4.365011 WHERE `guid` = 83979;
UPDATE `creature` SET `position_x` = 2179.469482, `position_y` = 52.001755, `position_z` = 66.185760, `orientation` = 4.242488 WHERE `guid` = 83978;
UPDATE `creature` SET `position_x` = 2184.879639, `position_y` = 50.181683, `position_z` = 66.242325, `orientation` = 4.201647 WHERE `guid` = 83981;
UPDATE `creature` SET `position_x` = 2192.822998, `position_y` = 12.869001, `position_z` = 66.117027, `orientation` = 2.702322 WHERE `guid` = 83983;
UPDATE `creature` SET `position_x` = 2175.076904, `position_y` = 1.1307310, `position_z` = 66.122726, `orientation` = 1.262686 WHERE `guid` = 83984;
UPDATE `creature` SET `position_x` = 2171.402344, `position_y` = 5.1749520, `position_z` = 64.843498, `orientation` = 1.235983 WHERE `guid` = 83985;

-- Rifleman Pathing In First Pit
DELETE FROM `creature_formations` WHERE `leaderGUID`=83930;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83930, 83930, 0, 0, 2, 0, 0),
(83930, 83931, 3, 0, 2, 0, 0);

SET @NPC := 83930;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2097.15, 78.6796, 53.0115, 0),
(@PATH, 2, 2084, 97.0058, 53.0813, 0),
(@PATH, 3, 2085.25, 114.295, 52.441, 0),
(@PATH, 4, 2095.02, 133.882, 52.9715, 0),
(@PATH, 5, 2093.37, 143.542, 52.4456, 0),
(@PATH, 6, 2086.79, 145.567, 52.562, 0),
(@PATH, 7, 2078.89, 146.163, 52.8694, 0),
(@PATH, 8, 2070.16, 149.051, 55.0808, 0),
(@PATH, 9, 2063.53, 144.524, 54.8516, 0),
(@PATH, 10, 2056.3, 129.417, 54.886, 0),
(@PATH, 11, 2051.2, 117.43, 55.0246, 0),
(@PATH, 12, 2048.74, 106.082, 53.8027, 0),
(@PATH, 13, 2048.45, 90.0419, 53.1851, 0),
(@PATH, 14, 2050.02, 77.0256, 52.9052, 0),
(@PATH, 15, 2054.85, 66.9206, 52.6482, 0),
(@PATH, 16, 2061.25, 59.5255, 53.1247, 0),
(@PATH, 17, 2069.13, 53.5553, 53.9244, 0),
(@PATH, 18, 2080.77, 46.2151, 54.041, 0),
(@PATH, 19, 2092.03, 40.4852, 52.8246, 0),
(@PATH, 20, 2105.15, 34.4171, 52.6789, 0),
(@PATH, 21, 2114.6, 29.6927, 53.7685, 0),
(@PATH, 22, 2123.67, 31.693, 52.861, 0),
(@PATH, 23, 2132.42, 42.8707, 52.6342, 0),
(@PATH, 24, 2131.65, 53.1806, 52.441, 0),
(@PATH, 25, 2120.27, 60.1946, 52.4814, 0),
(@PATH, 26, 2112.77, 67.7052, 52.5274, 0);

SET @NPC := 83934;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2068.01, 74.9858, 53.7438, 0),
(@PATH, 2, 2064.53, 81.5845, 54.0444, 0),
(@PATH, 3, 2061.73, 86.8158, 54.1236, 0),
(@PATH, 4, 2059.31, 88.1866, 54.1046, 0),
(@PATH, 5, 2055.28, 86.614, 54.1177, 0),
(@PATH, 6, 2065.6, 90.6067, 54.099, 0),
(@PATH, 7, 2067.63, 84.4378, 54.0945, 0),
(@PATH, 8, 2065.46, 78.7869, 53.9266, 0),
(@PATH, 9, 2069.08, 72.6753, 53.646, 0),
(@PATH, 10, 2071.68, 67.8529, 53.761, 0),
(@PATH, 11, 2075.62, 68.0539, 53.7892, 0),
(@PATH, 12, 2081.12, 70.4489, 53.7591, 0),
(@PATH, 13, 2076.01, 68.0177, 53.7933, 0),
(@PATH, 14, 2072.07, 67.7785, 53.767, 0);

-- Third Hut Guards
UPDATE `creature` SET `position_x` = 2066.639893, `position_y` = 142.899033, `position_z` = 53.258968, `orientation` = 2.797679 WHERE `guid` = 83924;
UPDATE `creature` SET `position_x` = 2072.268311, `position_y` = 105.922432, `position_z` = 53.294781, `orientation` = 5.891366 WHERE `guid` = 83922;

-- Guards Under The Bridge
UPDATE `creature` SET `position_x` = 2126.438477, `position_y` = 175.292297, `position_z` = 53.516026, `orientation` = 1.561665 WHERE `guid` = 83945;
UPDATE `creature` SET `position_x` = 2129.196533, `position_y` = 177.595200, `position_z` = 54.084316, `orientation` = 3.192937 WHERE `guid` = 83944;
UPDATE `creature` SET `position_x` = 2121.649658, `position_y` = 179.502533, `position_z` = 53.181751, `orientation` = 0.586199 WHERE `guid` = 83942;
UPDATE `creature` SET `position_x` = 2124.063232, `position_y` = 183.331512, `position_z` = 52.779934, `orientation` = 4.016817 WHERE `guid` = 83943;

DELETE FROM `creature_formations` WHERE `leaderGUID`=83945;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83945, 83945, 0, 0, 2, 0, 0),
(83945, 83942, 0, 0, 2, 0, 0),
(83945, 83943, 0, 0, 2, 0, 0),
(83945, 83944, 0, 0, 2, 0, 0);

-- Pathing Sentry in Orc Pit
DELETE FROM `creature_formations` WHERE `leaderGUID`=83950;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83950, 83950, 0, 0, 2, 0, 0),
(83950, 83951, 3, 0, 2, 0, 0);

SET @NPC := 83950;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2194.76, 228.093, 53.2216, 0),
(@PATH, 2, 2177.35, 222.908, 52.5617, 0),
(@PATH, 3, 2155.81, 211.125, 52.9491, 0),
(@PATH, 4, 2136.14, 190.397, 52.6035, 0),
(@PATH, 5, 2123.86, 177.449, 52.5751, 0),
(@PATH, 6, 2118.74, 164.827, 52.473, 0),
(@PATH, 7, 2111.26, 150.577, 52.441, 0),
(@PATH, 8, 2109.52, 133.664, 52.441, 0),
(@PATH, 9, 2112.11, 113.823, 52.5069, 0),
(@PATH, 10, 2116.1, 88.3774, 52.5566, 0),
(@PATH, 11, 2119.94, 64.779, 52.668, 0),
(@PATH, 12, 2126.07, 55.7297, 52.4422, 0),
(@PATH, 13, 2142.26, 44.6962, 52.5726, 0),
(@PATH, 14, 2126.15, 55.8954, 52.441, 0),
(@PATH, 15, 2119.89, 64.841, 52.6693, 0),
(@PATH, 16, 2119.19, 77.1831, 52.6315, 0),
(@PATH, 17, 2114.45, 101.229, 52.4411, 0),
(@PATH, 18, 2110.13, 129.652, 52.4412, 0),
(@PATH, 19, 2109.8, 142.596, 52.4415, 0),
(@PATH, 20, 2111.71, 151, 52.4422, 0),
(@PATH, 21, 2118.62, 163.934, 52.4958, 0),
(@PATH, 22, 2124.02, 177.071, 52.6379, 0),
(@PATH, 23, 2128.47, 184.045, 52.8829, 0),
(@PATH, 24, 2141.11, 193.758, 52.4788, 0),
(@PATH, 25, 2155.71, 210.856, 52.963, 0),
(@PATH, 26, 2166.12, 216.871, 52.784, 0);


-- Pathing Sentry in Orc Pit
DELETE FROM `creature_formations` WHERE `leaderGUID`=83962;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83962, 83962, 0, 0, 2, 0, 0),
(83962, 83963, 3, 0, 2, 0, 0);

SET @NPC := 83962;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2179.58, 272.553, 53.7907, 0),
(@PATH, 2, 2174.51, 273.75, 54.7804, 0),
(@PATH, 3, 2167.73, 270.116, 53.8525, 0),
(@PATH, 4, 2158.07, 262.467, 54.2476, 0),
(@PATH, 5, 2148.58, 254.01, 53.6444, 0),
(@PATH, 6, 2142.06, 248.19, 54.5281, 0),
(@PATH, 7, 2141.05, 241.971, 54.0081, 0),
(@PATH, 8, 2151.24, 228.01, 52.5662, 0),
(@PATH, 9, 2157.59, 225.422, 52.5796, 0),
(@PATH, 10, 2163.86, 228.987, 52.4411, 0),
(@PATH, 11, 2171.11, 238.58, 52.4803, 0),
(@PATH, 12, 2186.56, 250.708, 52.672, 0),
(@PATH, 13, 2195.97, 250.156, 52.441, 0),
(@PATH, 14, 2204.23, 245.158, 53.3357, 0),
(@PATH, 15, 2220.32, 235.855, 52.5448, 0),
(@PATH, 16, 2225.11, 237.303, 53.2101, 0),
(@PATH, 17, 2231.1, 247.145, 53.7591, 0),
(@PATH, 18, 2233.59, 253.688, 54.8861, 0),
(@PATH, 19, 2233.58, 256.145, 55.5751, 0),
(@PATH, 20, 2228.66, 260.389, 54.1031, 0),
(@PATH, 21, 2226.51, 259.921, 53.4273, 0),
(@PATH, 22, 2222.34, 253.34, 53.7322, 0),
(@PATH, 23, 2206.44, 263.036, 54.0515, 0),
(@PATH, 24, 2196.3, 260.947, 54.0427, 0),
(@PATH, 25, 2194.69, 256.858, 54.0644, 0),
(@PATH, 26, 2191.63, 251.755, 52.4522, 0),
(@PATH, 27, 2189.27, 255.95, 52.4471, 0),
(@PATH, 28, 2184.46, 262.837, 52.4412, 0),
(@PATH, 29, 2187.25, 272.681, 52.8813, 0);

-- Fifth Hut Guards
UPDATE `creature` SET `position_x` = 2224.243652, `position_y` = 261.026978, `position_z` = 52.870918, `orientation` = 1.083381 WHERE `guid` = 83956;
UPDATE `creature` SET `position_x` = 2228.397461, `position_y` = 258.271484, `position_z` = 53.144829, `orientation` = 1.235748 WHERE `guid` = 83955;

SET @NPC := 83958;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2202.6, 261.304, 54.0827, 0),
(@PATH, 2, 2210.13, 261.506, 53.8936, 0),
(@PATH, 3, 2222.63, 253.593, 53.7344, 0),
(@PATH, 4, 2226.35, 258.649, 53.6825, 0),
(@PATH, 5, 2222.54, 252.893, 53.7423, 0),
(@PATH, 6, 2215.13, 253.523, 53.6058, 0),
(@PATH, 7, 2203.69, 260.036, 54.0857, 0),
(@PATH, 8, 2196.83, 260.845, 54.0447, 0),
(@PATH, 9, 2194.18, 256.059, 54.0261, 0),
(@PATH, 10, 2196.6, 259.593, 54.0522, 0);

-- Group of 4 NPC at Top of Hill
DELETE FROM `creature_formations` WHERE `leaderGUID`=83966;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83966, 83966, 0, 0, 2, 0, 0),
(83966, 83967, 0, 0, 2, 0, 0),
(83966, 83968, 0, 0, 2, 0, 0),
(83966, 83969, 0, 0, 2, 0, 0);

-- Group of 4 NPC In Front of Castle
DELETE FROM `creature_formations` WHERE `leaderGUID`=83935;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83935, 83935, 0, 0, 2, 0, 0),
(83935, 83936, 0, 0, 2, 0, 0),
(83935, 83937, 0, 0, 2, 0, 0),
(83935, 83938, 0, 0, 2, 0, 0);

-- Sentry Pathing in Castle
DELETE FROM `creature_formations` WHERE `leaderGUID`=83940;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83940, 83940, 0, 0, 2, 0, 0),
(83940, 83941, 3, 0, 2, 0, 0);

SET @NPC := 83940;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2205.2, 105.548, 89.4549, 0),
(@PATH, 2, 2198.16, 109.399, 89.4549, 0),
(@PATH, 3, 2203.92, 119.75, 89.4549, 0),
(@PATH, 4, 2208.63, 128.602, 87.9559, 0),
(@PATH, 5, 2197.29, 135.558, 88.2163, 0),
(@PATH, 6, 2177.38, 147.178, 88.2163, 0),
(@PATH, 7, 2197.46, 135.325, 88.2164, 0),
(@PATH, 8, 2209.19, 128.465, 87.9552, 0),
(@PATH, 9, 2214.03, 138.222, 89.4554, 0),
(@PATH, 10, 2219.53, 148.379, 89.4554, 0),
(@PATH, 11, 2230.54, 142.295, 89.4554, 0),
(@PATH, 12, 2224.32, 132.35, 89.4554, 0),
(@PATH, 13, 2221.97, 128.721, 89.4554, 0),
(@PATH, 14, 2229.83, 124.014, 89.4554, 0),
(@PATH, 15, 2234.85, 117.573, 89.4554, 0),
(@PATH, 16, 2230.33, 109.712, 93.3835, 0),
(@PATH, 17, 2217.21, 116.93, 98.2768, 0),
(@PATH, 18, 2211.69, 106.844, 98.2768, 0),
(@PATH, 19, 2195.58, 116.127, 103.378, 0),
(@PATH, 20, 2204.6, 131.978, 103.378, 0),
(@PATH, 21, 2213.31, 147.498, 103.378, 0),
(@PATH, 22, 2229.43, 138.021, 98.2767, 0),
(@PATH, 23, 2217.65, 116.955, 98.2767, 0),
(@PATH, 24, 2230.53, 109.677, 93.3836, 0),
(@PATH, 25, 2234.87, 117.489, 89.455, 0),
(@PATH, 26, 2229.99, 124.125, 89.455, 0),
(@PATH, 27, 2222.32, 128.306, 89.455, 0),
(@PATH, 28, 2209.61, 106.255, 89.455, 0);

-- Guards Sleeping In Castle
UPDATE `creature` SET `position_x` = 2230.499756, `position_y` = 96.335007, `position_z` = 91.719383, `orientation` = 1.130164 WHERE `guid` = 83457;
UPDATE `creature` SET `position_x` = 2222.566895, `position_y` = 88.888351, `position_z` = 91.591484, `orientation` = 2.629882 WHERE `guid` = 83977;

DELETE FROM `creature_formations` WHERE `leaderGUID`=83457;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83457, 83457, 0, 0, 2, 0, 0),
(83457, 83977, 0, 0, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (83457,83977);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83457,0,0,3,0,0, ''),
(83977,0,0,3,0,0, '');

-- NPC Upstairs in Castle
UPDATE `creature` SET `position_x` = 2207.863525, `position_y` = 125.211838, `position_z` = 103.378456, `orientation` = 1.097563 WHERE `guid` = 83976;
UPDATE `creature` SET `position_x` = 2209.415283, `position_y` = 126.366081, `position_z` = 103.378456, `orientation` = 4.006677 WHERE `guid` = 83975;

DELETE FROM `creature_formations` WHERE `leaderGUID`=83976;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83976, 83976, 0, 0, 2, 0, 0),
(83976, 83975, 0, 0, 2, 0, 0),
(83976, 83973, 0, 0, 2, 0, 0),
(83976, 83974, 0, 0, 2, 0, 0);

-- Group of 4 NPC Main Floor of Castle
UPDATE `creature` SET `position_x` = 2218.045166, `position_y` = 125.936539, `position_z` = 89.454872, `orientation` = 5.212229 WHERE `guid` = 83997;
UPDATE `creature` SET `position_x` = 2224.622559, `position_y` = 123.511497, `position_z` = 89.454872, `orientation` = 4.141731 WHERE `guid` = 83996;

-- Guards In Tower Near Castle
DELETE FROM `creature_formations` WHERE `leaderGUID`=42939;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(42939, 42939, 0, 0, 2, 0, 0),
(42939, 48019, 0, 0, 2, 0, 0),
(42939, 48020, 0, 0, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=41813;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(41813, 41813, 0, 0, 2, 0, 0),
(41813, 48017, 0, 0, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=48015;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(48015, 48015, 0, 0, 2, 0, 0),
(48015, 48016, 0, 0, 2, 0, 0);

-- ONLY USE THESE GUIDS PLEASE :) (already rechecked them on clean tc with free-guid-searcher, some spawns in the instance had to be removed and reinserted again)
-- the used guids are assigned to some waypoints later
DELETE FROM `creature` WHERE `guid` IN (83932, 83972, 83933, 77820, 77854, 83959, 77819, 83923, 77818, 83926, 77817, 77816, 83928, 83929, 6998, 77806);
DELETE FROM `creature_addon` WHERE `guid` IN (83932, 83972, 83933, 77820, 77854, 83959, 77819, 83923, 77818, 83926, 77817, 77816, 83928, 83929, 6998, 77806);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES 
(6998, 17819, 560, 3, 0, 0, 2257.46, 259.449, 65.0975, 1.53443, 86400, 0, 0, 17736, 0, 0),
(77806, 17819, 560, 3, 0, 0, 2256.79, 264.135, 64.8945, 4.74278, 86400, 0, 0, 17736, 0, 0),
(77816, 17819, 560, 3, 0, 0, 2090.35, 44.7203, 52.4421, 4.33673, 86400, 0, 0, 18345, 0, 0),
(77817, 17819, 560, 3, 0, 0, 2055.22, 83.8672, 52.4861, 3.67686, 86400, 0, 0, 18345, 0, 0),
(77818, 17820, 560, 3, 0, 0, 2068.6, 112.257, 54.68, 1.89859, 86400, 0, 0, 17736, 0, 0),
(77819, 17833, 560, 3, 0, 0, 2160.93, 236.505, 53.8958, 2.18764, 86400, 0, 0, 14674, 14665, 0),
(77820, 17820, 560, 3, 0, 0, 2191.83, 256.39, 52.4411, 4.17236, 86400, 0, 0, 18345, 0, 0),
(77854, 17833, 560, 3, 0, 0, 2195.78, 253.736, 52.441, 4.13466, 86400, 0, 0, 14674, 14665, 0),
(83923, 17833, 560, 3, 0, 0, 2074.58, 110.82, 53.3224, 5.9597, 86400, 0, 0, 14674, 14665, 0),
(83926, 17833, 560, 3, 0, 0, 2082.72, 73.9288, 52.442, 0.525837, 86400, 0, 0, 14674, 14665, 0),
(83928, 17820, 560, 3, 0, 0, 2117.43, 54.716, 52.5916, 1.17158, 86400, 0, 0, 17736, 0, 0),
(83929, 17833, 560, 3, 0, 0, 2122.75, 52.3503, 52.441, 1.11189, 86400, 0, 0, 14674, 14665, 0),
(83932, 18598, 560, 3, 0, 0, 2086.52, 95.0915, 52.9514, 5.15978, 86400, 10, 0, 5914, 0, 1),
(83933, 17860, 560, 3, 0, 0, 2217.04, 123.922, 89.4549, 0.339619, 86400, 0, 0, 18345, 0, 0),
(83959, 17819, 560, 3, 0, 0, 2170.79, 268.471, 52.9163, 2.42404, 86400, 0, 0, 17736, 0, 0),
(83972, 17815, 560, 3, 0, 0, 2321.19, 886.26, 92.7589, 5.98453, 86400, 0, 0, 17151, 0, 2);

DELETE FROM `creature_formations` WHERE `leaderGUID`=6998;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(6998, 6998, 0, 0, 2, 0, 0),
(6998, 77806, 0, 0, 2, 0, 0);

-- enable movement for these fuckers
-- Durnholde Rifleman SAI
SET @ENTRY := 17820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,5,30,9000,15000,11,31942,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Within 5-30 Range - Cast 'Multi-Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,5,30,9000,15000,11,38383,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durnholde Rifleman - Within 5-30 Range - Cast 'Multi-Shot' (Heroic Dungeon)"),
(@ENTRY,0,4,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durnholde Rifleman - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)");

DELETE FROM `creature_formations` WHERE `leaderGUID`=83929;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83929, 83929, 0, 0, 2, 0, 0),
(83929, 83928, 0, 0, 2, 0, 0),
(83929, 83986, 0, 0, 2, 0, 0),
(83929, 77816, 0, 0, 2, 0, 0);

SET @NPC := 77818;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2067.58, 120.639, 54.6068, 0),
(@PATH, 2, 2068.65, 124.579, 54.4448, 0),
(@PATH, 3, 2073.17, 136.186, 54.3431, 0),
(@PATH, 4, 2067.19, 140.195, 54.3051, 0),
(@PATH, 5, 2074.04, 136.275, 54.3549, 0),
(@PATH, 6, 2069.37, 129.214, 54.2632, 0),
(@PATH, 7, 2065.92, 119.088, 54.6917, 0),
(@PATH, 8, 2067.54, 110.605, 54.6653, 0),
(@PATH, 9, 2071.76, 108.894, 54.6828, 0),
(@PATH, 10, 2069.07, 110.515, 54.6717, 0);

SET @NPC := 77819;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2157.48, 240.365, 53.8761, 0),
(@PATH, 2, 2157.15, 245.379, 53.9002, 0),
(@PATH, 3, 2163.3, 256.598, 53.5643, 0),
(@PATH, 4, 2172.27, 263.614, 53.5644, 0),
(@PATH, 5, 2169.42, 266.65, 53.5095, 0),
(@PATH, 6, 2176.24, 257.534, 53.5725, 0),
(@PATH, 7, 2166.49, 248.773, 53.6714, 0),
(@PATH, 8, 2157.53, 240.79, 53.88, 0),
(@PATH, 9, 2161.49, 235.735, 53.8969, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=83971;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83971, 83971, 0, 0, 2, 0, 0),
(83971, 83996, 0, 0, 2, 0, 0),
(83971, 83997, 0, 0, 2, 0, 0),
(83971, 83933, 0, 0, 2, 0, 0);

-- The Cook in the Castle
SET @NPC := 83970;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2200.8, 154.304, 89.4549, 0),
(@PATH, 2, 2201.31, 153.99, 89.455, 10000),
(@PATH, 3, 2201.6, 156.055, 89.455, 0),
(@PATH, 4, 2201.02, 156.09, 89.455, 10000),
(@PATH, 5, 2202.06, 156.634, 89.455, 0),
(@PATH, 6, 2204.48, 160.807, 89.455, 0),
(@PATH, 7, 2204.82, 160.47, 89.4549, 10000);

-- Armorer Pathing in Castle
SET @NPC := 83939;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2186.46, 118.12, 89.4552, 0),
(@PATH, 2, 2188.81, 120.799, 89.4552, 12000),
(@PATH, 3, 2180.05, 118.042, 89.4552, 12000),
(@PATH, 4, 2183.88, 115.816, 89.4552, 0),
(@PATH, 5, 2182.72, 111.643, 89.4552, 12000);

-- =======================
-- Outside of Castle Stuff
-- =======================

-- enable movement for these fuckers
-- Lordaeron Sentry SAI
SET @ENTRY := 17815;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,5000,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,2300,5000,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lordaeron Sentry - In Combat CMC - Cast 'Shoot' (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lordaeron Sentry - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)");

-- On Castle
SET @NPC := 83972;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2325.11, 885.167, 90.6113, 0),
(@PATH, 2, 2331.89, 884.099, 87.1758, 0),
(@PATH, 3, 2332.94, 887.052, 86.7539, 0),
(@PATH, 4, 2331.14, 890.154, 85.6413, 0),
(@PATH, 5, 2327.28, 892.536, 83.7337, 0),
(@PATH, 6, 2323.33, 892.184, 81.9012, 0),
(@PATH, 7, 2318.98, 887.176, 81.6081, 0),
(@PATH, 8, 2318.69, 882.293, 79.2719, 0),
(@PATH, 9, 2320.56, 879.062, 77.5579, 0),
(@PATH, 10, 2325.94, 876.844, 76.9868, 0),
(@PATH, 11, 2330.77, 877.674, 75.7722, 0),
(@PATH, 12, 2335, 882.021, 72.2668, 0),
(@PATH, 13, 2333.83, 889.01, 71.3798, 0),
(@PATH, 14, 2332.53, 893.004, 70.1646, 0),
(@PATH, 15, 2326.51, 894.765, 67.1477, 0),
(@PATH, 16, 2322.01, 894.088, 65.5546, 0),
(@PATH, 17, 2317.43, 890.326, 65.1353, 0),
(@PATH, 18, 2316.2, 886.194, 63.7357, 0),
(@PATH, 19, 2318.93, 879.756, 62.315, 0),
(@PATH, 20, 2323.42, 876.041, 59.9463, 0),
(@PATH, 21, 2328.9, 876.302, 57.6755, 0),
(@PATH, 22, 2333.22, 882.887, 57.671, 0),
(@PATH, 23, 2330.23, 891.656, 57.6677, 0),
(@PATH, 24, 2330.97, 895.891, 57.6647, 0),
(@PATH, 25, 2333.62, 903.478, 57.6647, 0),
(@PATH, 26, 2327.67, 905.549, 57.6647, 0),
(@PATH, 27, 2316.2, 902.56, 57.569, 0),
(@PATH, 28, 2310.06, 898.124, 57.6648, 0),
(@PATH, 29, 2306.3, 891.68, 57.6648, 0),
(@PATH, 30, 2305.38, 884.853, 57.6648, 0),
(@PATH, 31, 2306.64, 877.848, 57.5939, 0),
(@PATH, 32, 2311.01, 870.276, 57.6642, 0),
(@PATH, 33, 2318.98, 865.217, 57.5566, 0),
(@PATH, 34, 2328.33, 863.818, 57.6633, 0),
(@PATH, 35, 2336.48, 867.295, 57.574, 0),
(@PATH, 36, 2343.45, 873.318, 57.663, 0),
(@PATH, 37, 2346.58, 879.571, 57.663, 0),
(@PATH, 38, 2346.54, 888.088, 57.5692, 0),
(@PATH, 39, 2343.96, 895.954, 57.6645, 0),
(@PATH, 40, 2339.83, 900.705, 57.6645, 0),
(@PATH, 41, 2333.78, 903.467, 57.6645, 0),
(@PATH, 42, 2330.4, 896.083, 57.6645, 0),
(@PATH, 43, 2329.77, 889.734, 57.6676, 0),
(@PATH, 44, 2331.14, 878.867, 57.6683, 0),
(@PATH, 45, 2328.35, 875.736, 57.8588, 0),
(@PATH, 46, 2323.37, 875.52, 59.9245, 0),
(@PATH, 47, 2319.42, 878.762, 61.8416, 0),
(@PATH, 48, 2316.99, 883.931, 62.4409, 0),
(@PATH, 49, 2316.51, 886.569, 63.8636, 0),
(@PATH, 50, 2318.53, 890.77, 65.1821, 0),
(@PATH, 51, 2322.68, 893.593, 65.555, 0),
(@PATH, 52, 2327.67, 893.958, 67.6509, 0),
(@PATH, 53, 2331.42, 891.878, 69.8271, 0),
(@PATH, 54, 2334.07, 888.412, 71.3795, 0),
(@PATH, 55, 2334.68, 882.853, 71.8615, 0),
(@PATH, 56, 2333.31, 879.767, 73.7331, 0),
(@PATH, 57, 2329.96, 877.462, 76.232, 0),
(@PATH, 58, 2326.87, 877.048, 76.9683, 0),
(@PATH, 59, 2321.05, 879.39, 77.3211, 0),
(@PATH, 60, 2319.01, 882.819, 79.3952, 0),
(@PATH, 61, 2319.14, 886.792, 81.5905, 0),
(@PATH, 62, 2323.52, 891.644, 81.8, 0),
(@PATH, 63, 2326.09, 892.595, 83.1418, 0),
(@PATH, 64, 2329.49, 891.449, 84.9086, 0),
(@PATH, 65, 2331.62, 888.864, 86.2302, 0),
(@PATH, 66, 2332.31, 886.586, 87.176, 0),
(@PATH, 67, 2331.76, 884.452, 87.176, 0),
(@PATH, 68, 2322.23, 885.951, 92.7589, 0);

-- Group of 3 walking on Path Near Castle
DELETE FROM `creature_formations` WHERE `leaderGUID`=31799;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(31799, 31799, 0, 0, 2, 0, 0),
(31799, 48021, 3, 60, 2, 0, 0),
(31799, 48022, 3, 300, 2, 0, 0);

SET @NPC := 31799;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2018.19, 313.412, 66.0958, 0),
(@PATH, 2, 2027.78, 329.65, 66.0986, 0),
(@PATH, 3, 2039.14, 346.798, 66.072, 0),
(@PATH, 4, 2050.96, 374.133, 65.9613, 0),
(@PATH, 5, 2058.06, 390.457, 66.0772, 0),
(@PATH, 6, 2068.54, 411.057, 66.0615, 0),
(@PATH, 7, 2073.09, 421.154, 66.1363, 0),
(@PATH, 8, 2079.13, 440.491, 66.2517, 0),
(@PATH, 9, 2087.18, 466.869, 65.9002, 0),
(@PATH, 10, 2093.36, 483.083, 64.6249, 0),
(@PATH, 11, 2100.55, 496.159, 62.1489, 0),
(@PATH, 12, 2111.38, 509.983, 59.3541, 0),
(@PATH, 13, 2124.28, 522.055, 56.8856, 0),
(@PATH, 14, 2136.51, 535.415, 54.6722, 0),
(@PATH, 15, 2151.66, 551.229, 50.4063, 0),
(@PATH, 16, 2161.32, 566.353, 46.8987, 0),
(@PATH, 17, 2168.07, 588.288, 42.1267, 0),
(@PATH, 18, 2171.31, 606.029, 39.5882, 0),
(@PATH, 19, 2172.69, 622.375, 36.9113, 0),
(@PATH, 20, 2175.5, 641.143, 33.8056, 0),
(@PATH, 21, 2172.7, 627.72, 35.6883, 0),
(@PATH, 22, 2170.41, 607.085, 39.4374, 0),
(@PATH, 23, 2167.23, 590.177, 41.9199, 0),
(@PATH, 24, 2161.95, 569.422, 46.211, 0),
(@PATH, 25, 2158.41, 562.069, 48.0236, 0),
(@PATH, 26, 2148.92, 549.403, 50.956, 0),
(@PATH, 27, 2136.91, 535.789, 54.5421, 0),
(@PATH, 28, 2130.16, 527.157, 56.0405, 0),
(@PATH, 29, 2108.82, 509.232, 59.6871, 0),
(@PATH, 30, 2098.32, 493.48, 62.7374, 0),
(@PATH, 31, 2087.92, 471.897, 65.8437, 0),
(@PATH, 32, 2083.84, 458.354, 66.1229, 0),
(@PATH, 33, 2078.36, 437.542, 66.2739, 0),
(@PATH, 34, 2072.13, 419.858, 66.1159, 0),
(@PATH, 35, 2057.47, 392.51, 66.058, 0),
(@PATH, 36, 2047.37, 367.993, 66.0416, 0),
(@PATH, 37, 2037.51, 345.576, 66.064, 0),
(@PATH, 38, 2023.41, 323.477, 66.0973, 0),
(@PATH, 39, 2014.63, 305.342, 66.0953, 0),
(@PATH, 40, 2002.65, 287.829, 66.1836, 0),
(@PATH, 41, 1991.13, 272.215, 66.9844, 0),
(@PATH, 42, 1975.02, 253.234, 67.4879, 0),
(@PATH, 43, 1987.19, 267.878, 67.0954, 0),
(@PATH, 44, 2001.88, 284.088, 66.153, 0),
(@PATH, 45, 2011.98, 301.219, 66.0991, 0);

-- Group of 3 walking on Path From Southshore
DELETE FROM `creature_formations` WHERE `leaderGUID`=40161;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(40161, 40161, 0, 0, 2, 0, 0),
(40161, 48010, 3, 60, 2, 0, 0),
(40161, 48011, 3, 300, 2, 0, 0);

SET @NPC := 40161;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2033.7, 1037.71, 27.2622, 0),
(@PATH, 2, 2052.69, 1027.51, 29.9964, 0),
(@PATH, 3, 2064.05, 1024.49, 31.3459, 0),
(@PATH, 4, 2081.15, 1024.77, 32.6441, 0),
(@PATH, 5, 2094.54, 1028.74, 32.789, 0),
(@PATH, 6, 2111.75, 1036.15, 34.8223, 0),
(@PATH, 7, 2127.78, 1039.11, 37.3397, 0),
(@PATH, 8, 2142.51, 1040.35, 39.4863, 0),
(@PATH, 9, 2151.24, 1038.85, 40.903, 0),
(@PATH, 10, 2163.97, 1033.92, 43.0773, 0),
(@PATH, 11, 2179.02, 1029.86, 45.5233, 0),
(@PATH, 12, 2193.08, 1024.2, 48.0107, 0),
(@PATH, 13, 2209.97, 1019.79, 50.8105, 0),
(@PATH, 14, 2232.14, 1015.33, 53.6278, 0),
(@PATH, 15, 2236.86, 1000.05, 54.3589, 0),
(@PATH, 16, 2239.94, 983.671, 54.5024, 0),
(@PATH, 17, 2243.15, 967.012, 54.4995, 0),
(@PATH, 18, 2250.3, 950.466, 54.4995, 0),
(@PATH, 19, 2257.66, 929.562, 54.5, 0),
(@PATH, 20, 2266.9, 907.928, 54.5, 0),
(@PATH, 21, 2272.49, 895.354, 54.5, 0),
(@PATH, 22, 2277.79, 879.701, 54.5, 0),
(@PATH, 23, 2283.3, 862.612, 54.5, 0),
(@PATH, 24, 2286.78, 846.443, 54.5038, 0),
(@PATH, 25, 2287.27, 836.662, 54.5816, 0),
(@PATH, 26, 2285.96, 818.884, 54.5465, 0),
(@PATH, 27, 2300.59, 826.601, 54.2136, 0),
(@PATH, 28, 2315.28, 833.688, 54.0844, 0),
(@PATH, 29, 2329.23, 838.29, 53.7169, 0),
(@PATH, 30, 2338.8, 843.829, 53.9952, 0),
(@PATH, 31, 2360.41, 850.112, 55.0492, 0),
(@PATH, 32, 2374.82, 854.797, 56.1393, 0),
(@PATH, 33, 2389.13, 859.729, 56.593, 0),
(@PATH, 34, 2406.24, 863.134, 57.4308, 0),
(@PATH, 35, 2425.77, 870.367, 59.3746, 0),
(@PATH, 36, 2440.46, 874.494, 60.7434, 0),
(@PATH, 37, 2455.4, 877.09, 61.6139, 0),
(@PATH, 38, 2468.96, 879.393, 62.7986, 0),
(@PATH, 39, 2481.63, 882.154, 63.3108, 0),
(@PATH, 40, 2500.23, 883.53, 63.8125, 0),
(@PATH, 41, 2524.92, 884.253, 64.5644, 0),
(@PATH, 42, 2549.01, 885.228, 65.2615, 0),
(@PATH, 43, 2570.57, 885.702, 66.6194, 0),
(@PATH, 44, 2590.25, 883.441, 68.0443, 0),
(@PATH, 45, 2609.47, 883.434, 68.4157, 0),
(@PATH, 46, 2627.08, 883.115, 68.7522, 0),
(@PATH, 47, 2638.72, 884.668, 69.4879, 0),
(@PATH, 48, 2647.3, 886.344, 69.9081, 0),
(@PATH, 49, 2648.6, 864.03, 66.5179, 0),
(@PATH, 50, 2644.51, 848.334, 63.7446, 0),
(@PATH, 51, 2644.42, 832.861, 61.2474, 0),
(@PATH, 52, 2650, 812.135, 59.5327, 0),
(@PATH, 53, 2648.28, 798.034, 58.7606, 0),
(@PATH, 54, 2641, 787.92, 57.6733, 0),
(@PATH, 55, 2626.84, 778.887, 57.2837, 0),
(@PATH, 56, 2617.82, 770.64, 56.741, 0),
(@PATH, 57, 2612.9, 757.971, 56.3436, 0),
(@PATH, 58, 2612.32, 742.239, 56.0196, 0),
(@PATH, 59, 2618.59, 729.8, 55.5448, 0),
(@PATH, 60, 2631.64, 717.81, 56.124, 0),
(@PATH, 61, 2637.24, 709.656, 56.0667, 0),
(@PATH, 62, 2640.55, 701.856, 55.9947, 0),
(@PATH, 63, 2637.22, 712.487, 56.1679, 0),
(@PATH, 64, 2623.09, 726.894, 55.695, 0),
(@PATH, 65, 2615.24, 734.875, 55.5676, 0),
(@PATH, 66, 2612.66, 743.85, 56.0761, 0),
(@PATH, 67, 2612.93, 755.628, 56.358, 0),
(@PATH, 68, 2616.75, 766.374, 56.679, 0),
(@PATH, 69, 2621.31, 773.14, 57.0131, 0),
(@PATH, 70, 2630.75, 781.124, 57.4799, 0),
(@PATH, 71, 2640.96, 787.68, 57.6649, 0),
(@PATH, 72, 2650.15, 800.171, 58.9708, 0),
(@PATH, 73, 2650.52, 811.561, 59.5219, 0),
(@PATH, 74, 2645.37, 829.821, 60.8724, 0),
(@PATH, 75, 2643.37, 842.616, 62.7975, 0),
(@PATH, 76, 2644.93, 852.378, 64.4211, 0),
(@PATH, 77, 2649.51, 864.861, 66.7019, 0),
(@PATH, 78, 2648.1, 877.58, 68.9693, 0),
(@PATH, 79, 2644.34, 884.823, 69.6378, 0),
(@PATH, 80, 2635.53, 884.284, 69.2843, 0),
(@PATH, 81, 2620.1, 883.128, 68.5394, 0),
(@PATH, 82, 2595.87, 882.61, 67.9833, 0),
(@PATH, 83, 2574.96, 885.401, 67.11, 0),
(@PATH, 84, 2547.6, 885.501, 65.1863, 0),
(@PATH, 85, 2517.31, 884.012, 64.3204, 0),
(@PATH, 86, 2487.24, 883.374, 63.4703, 0),
(@PATH, 87, 2467.93, 880.227, 62.7723, 0),
(@PATH, 88, 2446.76, 875.248, 61.0426, 0),
(@PATH, 89, 2431.02, 873.251, 60.0043, 0),
(@PATH, 90, 2411.9, 865.704, 57.8424, 0),
(@PATH, 91, 2403.27, 862.833, 57.1985, 0),
(@PATH, 92, 2385.71, 860.395, 56.5602, 0),
(@PATH, 93, 2359.36, 850.036, 54.9632, 0),
(@PATH, 94, 2335.95, 842.985, 53.888, 0),
(@PATH, 95, 2311.06, 831.342, 54.1764, 0),
(@PATH, 96, 2298.28, 825.996, 54.2442, 0),
(@PATH, 97, 2284.59, 818.734, 54.5651, 0),
(@PATH, 98, 2286.06, 833.548, 54.6597, 0),
(@PATH, 99, 2284.14, 854.313, 54.4979, 0),
(@PATH, 100, 2280.29, 869.203, 54.4995, 0),
(@PATH, 101, 2271, 892.06, 54.4995, 0),
(@PATH, 102, 2259.09, 921.511, 54.501, 0),
(@PATH, 103, 2249.62, 946.579, 54.5057, 0),
(@PATH, 104, 2243.4, 964.173, 54.5007, 0),
(@PATH, 105, 2235.9, 989.626, 54.5012, 0),
(@PATH, 106, 2232.97, 1005.62, 54.1029, 0),
(@PATH, 107, 2227.72, 1015.88, 53.4782, 0),
(@PATH, 108, 2211.84, 1020.49, 51.1169, 0),
(@PATH, 109, 2192.95, 1024.61, 47.9657, 0),
(@PATH, 110, 2172.81, 1032.27, 44.4531, 0),
(@PATH, 111, 2153.53, 1037.24, 41.3712, 0),
(@PATH, 112, 2140.79, 1040.89, 39.1775, 0),
(@PATH, 113, 2123.12, 1039.6, 36.6713, 0),
(@PATH, 114, 2103.49, 1035.02, 33.4594, 0),
(@PATH, 115, 2086.92, 1026.77, 32.6743, 0),
(@PATH, 116, 2072.26, 1023.99, 31.9935, 0),
(@PATH, 117, 2056.05, 1025.72, 30.5415, 0),
(@PATH, 118, 2040.42, 1032.48, 27.9721, 0),
(@PATH, 119, 2027.22, 1039.55, 26.6217, 0),
(@PATH, 120, 2009.61, 1041, 25.8193, 0),
(@PATH, 121, 1994.01, 1036.6, 25.2784, 0),
(@PATH, 122, 1978.52, 1028.8, 24.9676, 0),
(@PATH, 123, 1966.82, 1030.89, 24.0734, 0),
(@PATH, 124, 1958.48, 1036.2, 22.866, 0),
(@PATH, 125, 1947.24, 1048.57, 20.7007, 0),
(@PATH, 126, 1937.04, 1052.57, 20.1663, 0),
(@PATH, 127, 1912.11, 1051.93, 18.6749, 0),
(@PATH, 128, 1887.93, 1055.78, 18.1049, 0),
(@PATH, 129, 1877.56, 1060.81, 17.4922, 0),
(@PATH, 130, 1861.06, 1069.78, 15.7649, 0),
(@PATH, 131, 1846.73, 1077.79, 13.6887, 0),
(@PATH, 132, 1833.61, 1077.49, 11.9939, 0),
(@PATH, 133, 1817.89, 1071.35, 10.6397, 0),
(@PATH, 134, 1792.63, 1059.22, 7.83287, 0),
(@PATH, 135, 1774.94, 1059.42, 6.82387, 0),
(@PATH, 136, 1795.92, 1060.08, 8.12069, 0),
(@PATH, 137, 1808.4, 1064.97, 9.29659, 0),
(@PATH, 138, 1826.46, 1074.14, 11.2145, 0),
(@PATH, 139, 1837.32, 1077.6, 12.5392, 0),
(@PATH, 140, 1847.23, 1077.42, 13.785, 0),
(@PATH, 141, 1858.66, 1071.86, 15.5919, 0),
(@PATH, 142, 1872.94, 1061.59, 16.8176, 0),
(@PATH, 143, 1889.64, 1056.42, 18.0499, 0),
(@PATH, 144, 1900.68, 1053.04, 17.9079, 0),
(@PATH, 145, 1926.7, 1051.99, 19.5382, 0),
(@PATH, 146, 1940.56, 1051.1, 20.25, 0),
(@PATH, 147, 1954.66, 1042.69, 21.7026, 0),
(@PATH, 148, 1966.41, 1032.81, 23.8429, 0),
(@PATH, 149, 1978.57, 1029.18, 24.9264, 0),
(@PATH, 150, 1984.57, 1030.46, 25.3086, 0),
(@PATH, 151, 2003.85, 1040.57, 25.4607, 0);

-- Group of 3 NPC pathing main Path between Southshore and Tarren Mill
DELETE FROM `creature_formations` WHERE `leaderGUID`=31931;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(31931, 31931, 0, 0, 2, 0, 0),
(31931, 47895, 3, 300, 2, 0, 0),
(31931, 47896, 3, 60, 2, 0, 0);

SET @NPC := 31931;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2297.26, 826.454, 54.2536, 0),
(@PATH, 2, 2318.02, 835.456, 53.9879, 0),
(@PATH, 3, 2341.06, 844.537, 54.0672, 0),
(@PATH, 4, 2368.06, 853.36, 55.6975, 0),
(@PATH, 5, 2388.34, 859.967, 56.5967, 0),
(@PATH, 6, 2407.29, 863.278, 57.523, 0),
(@PATH, 7, 2429.46, 871.776, 59.8363, 0),
(@PATH, 8, 2451.91, 876.067, 61.3264, 0),
(@PATH, 9, 2474.39, 881.111, 63.0555, 0),
(@PATH, 10, 2501.4, 883.295, 63.8419, 0),
(@PATH, 11, 2526.21, 885.033, 64.6203, 0),
(@PATH, 12, 2551.5, 885.4, 65.2762, 0),
(@PATH, 13, 2570.97, 885.675, 66.6719, 0),
(@PATH, 14, 2591.48, 882.584, 68.0358, 0),
(@PATH, 15, 2628.4, 884.012, 68.849, 0),
(@PATH, 16, 2658.91, 888.509, 71.2081, 0),
(@PATH, 17, 2672.56, 890.768, 72.7702, 0),
(@PATH, 18, 2693.86, 885.752, 74.1806, 0),
(@PATH, 19, 2713.38, 884.501, 76.1029, 0),
(@PATH, 20, 2732.82, 888.404, 78.4829, 0),
(@PATH, 21, 2755.95, 883.583, 81.4612, 0),
(@PATH, 22, 2785.64, 885.325, 86.028, 0),
(@PATH, 23, 2804.28, 891.622, 89.6307, 0),
(@PATH, 24, 2814.42, 899.85, 91.8807, 0),
(@PATH, 25, 2830.66, 915.238, 96.5334, 0),
(@PATH, 26, 2866.3, 920.68, 105.739, 0),
(@PATH, 27, 2899.02, 946.215, 117.103, 0),
(@PATH, 28, 2941.42, 947.916, 130.207, 0),
(@PATH, 29, 2952.49, 953.108, 133.123, 0),
(@PATH, 30, 2933.55, 946.743, 127.665, 0),
(@PATH, 31, 2912.45, 947.439, 120.768, 0),
(@PATH, 32, 2894.96, 944.572, 115.928, 0),
(@PATH, 33, 2887.02, 939.921, 113.319, 0),
(@PATH, 34, 2870.86, 923.593, 107.219, 0),
(@PATH, 35, 2860.04, 919.649, 103.829, 0),
(@PATH, 36, 2832.34, 917.115, 97.0985, 0),
(@PATH, 37, 2823.7, 912.33, 94.8206, 0),
(@PATH, 38, 2811.53, 898.344, 91.292, 0),
(@PATH, 39, 2798.25, 888.481, 88.2803, 0),
(@PATH, 40, 2786.07, 884.969, 86.0852, 0),
(@PATH, 41, 2768.53, 883.895, 83.3232, 0),
(@PATH, 42, 2750.42, 885.691, 80.8465, 0),
(@PATH, 43, 2731.02, 888.331, 78.2216, 0),
(@PATH, 44, 2708.53, 885.886, 75.4766, 0),
(@PATH, 45, 2692.26, 885.711, 74.0608, 0),
(@PATH, 46, 2674.56, 891.05, 72.9436, 0),
(@PATH, 47, 2656.87, 890.577, 71.0586, 0),
(@PATH, 48, 2643.22, 886.547, 69.736, 0),
(@PATH, 49, 2620.6, 882.848, 68.5394, 0),
(@PATH, 50, 2601.61, 882.172, 68.1294, 0),
(@PATH, 51, 2582.66, 883.452, 67.743, 0),
(@PATH, 52, 2569.63, 886.578, 66.4967, 0),
(@PATH, 53, 2539.69, 885.352, 64.7605, 0),
(@PATH, 54, 2518.36, 884.463, 64.3804, 0),
(@PATH, 55, 2501.75, 884.356, 63.7759, 0),
(@PATH, 56, 2476.52, 882.351, 63.1364, 0),
(@PATH, 57, 2457.38, 877.412, 61.8321, 0),
(@PATH, 58, 2437.14, 874.718, 60.5453, 0),
(@PATH, 59, 2416.18, 867.191, 58.1515, 0),
(@PATH, 60, 2405.78, 863.337, 57.3958, 0),
(@PATH, 61, 2385.29, 859.648, 56.5073, 0),
(@PATH, 62, 2366.22, 853.921, 55.574, 0),
(@PATH, 63, 2340.44, 844.064, 54.0407, 0),
(@PATH, 64, 2321.49, 836.288, 53.8379, 0),
(@PATH, 65, 2304.05, 828.219, 54.167, 0),
(@PATH, 66, 2284.63, 819.081, 54.5629, 0),
(@PATH, 67, 2276.49, 806.015, 54.5062, 0),
(@PATH, 68, 2259.45, 782.432, 53.9581, 0),
(@PATH, 69, 2248.1, 764.237, 52.6681, 0),
(@PATH, 70, 2227.61, 742.088, 47.3814, 0),
(@PATH, 71, 2211.48, 719.391, 41.8384, 0),
(@PATH, 72, 2196.17, 701.104, 37.2442, 0),
(@PATH, 73, 2186.72, 682.881, 34.477, 0),
(@PATH, 74, 2183.15, 671.171, 34.0323, 0),
(@PATH, 75, 2191.46, 692.237, 35.6717, 0),
(@PATH, 76, 2204.3, 712.019, 39.6665, 0),
(@PATH, 77, 2223.15, 734.204, 45.6636, 0),
(@PATH, 78, 2238.43, 754.221, 50.8206, 0),
(@PATH, 79, 2252.94, 770.293, 53.2999, 0),
(@PATH, 80, 2271.29, 798.227, 54.5908, 0),
(@PATH, 81, 2284.63, 817.792, 54.572, 0),
(@PATH, 82, 2286.83, 831.371, 54.5761, 0),
(@PATH, 83, 2285.96, 848.028, 54.5205, 0),
(@PATH, 84, 2283.72, 858.862, 54.4995, 0),
(@PATH, 85, 2277.61, 875.464, 54.4994, 0),
(@PATH, 86, 2266.79, 902.231, 54.4994, 0),
(@PATH, 87, 2258.17, 922.595, 54.5014, 0),
(@PATH, 88, 2254.14, 937.694, 54.5014, 0),
(@PATH, 89, 2247.62, 954.305, 54.4998, 0),
(@PATH, 90, 2241.64, 970.8, 54.4998, 0),
(@PATH, 91, 2236.29, 990.011, 54.5018, 0),
(@PATH, 92, 2230.51, 1015.88, 53.58, 0),
(@PATH, 93, 2226.99, 1040.78, 52.9566, 0),
(@PATH, 94, 2225.38, 1066.21, 50.8387, 0),
(@PATH, 95, 2224.57, 1092.67, 47.9604, 0),
(@PATH, 96, 2221.17, 1118.32, 47.3289, 0),
(@PATH, 97, 2215.23, 1142.62, 47.3363, 0),
(@PATH, 98, 2206.52, 1160.95, 47.3294, 0),
(@PATH, 99, 2191.01, 1180.19, 47.3334, 0),
(@PATH, 100, 2176.06, 1200.97, 47.3576, 0),
(@PATH, 101, 2153.58, 1232.91, 47.3083, 0),
(@PATH, 102, 2137.4, 1265.68, 47.3415, 0),
(@PATH, 103, 2117.78, 1296.4, 47.2391, 0),
(@PATH, 104, 2105.55, 1331, 47.311, 0),
(@PATH, 105, 2099.06, 1343.26, 47.3169, 0),
(@PATH, 106, 2106.72, 1327.73, 47.2684, 0),
(@PATH, 107, 2118.71, 1298.89, 47.2623, 0),
(@PATH, 108, 2129.37, 1279.65, 47.3572, 0),
(@PATH, 109, 2142, 1260.53, 47.3312, 0),
(@PATH, 110, 2151.32, 1240.71, 47.2761, 0),
(@PATH, 111, 2163.63, 1218.81, 47.3292, 0),
(@PATH, 112, 2181.68, 1197.19, 47.3568, 0),
(@PATH, 113, 2201.05, 1172.65, 47.3118, 0),
(@PATH, 114, 2211.89, 1155.51, 47.3104, 0),
(@PATH, 115, 2218.39, 1140.43, 47.3378, 0),
(@PATH, 116, 2225.45, 1110.72, 47.206, 0),
(@PATH, 117, 2226.69, 1088.6, 48.2767, 0),
(@PATH, 118, 2227.51, 1061.13, 51.162, 0),
(@PATH, 119, 2229.3, 1040.74, 52.9542, 0),
(@PATH, 120, 2232.73, 1016.29, 53.6401, 0),
(@PATH, 121, 2238.52, 992.95, 54.498, 0),
(@PATH, 122, 2244.92, 960.982, 54.501, 0),
(@PATH, 123, 2256.49, 934.401, 54.5, 0),
(@PATH, 124, 2272.51, 894.714, 54.5, 0),
(@PATH, 125, 2279.98, 869.234, 54.5, 0),
(@PATH, 126, 2286.45, 846.302, 54.5178, 0),
(@PATH, 127, 2287.17, 829.612, 54.5198, 0),
(@PATH, 128, 2285.48, 818.834, 54.5455, 0);

-- Group of 3 NPC pathing main Path between Tarren Mill and Southshore
DELETE FROM `creature_formations` WHERE `leaderGUID`=38051;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(38051, 38051, 0, 0, 2, 0, 0),
(38051, 48006, 3, 60, 2, 0, 0),
(38051, 48007, 3, 300, 2, 0, 0);

SET @NPC := 38051;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2405.29, 863.545, 57.358, 0),
(@PATH, 2, 2389.6, 860.732, 56.6579, 0),
(@PATH, 3, 2370.87, 854.003, 55.8788, 0),
(@PATH, 4, 2342.21, 845.899, 54.1098, 0),
(@PATH, 5, 2322.7, 836.199, 53.8074, 0),
(@PATH, 6, 2302.11, 828.377, 54.1732, 0),
(@PATH, 7, 2285.29, 818.678, 54.5502, 0),
(@PATH, 8, 2286.14, 836.791, 54.6453, 0),
(@PATH, 9, 2284.46, 852.418, 54.509, 0),
(@PATH, 10, 2279.3, 869.348, 54.498, 0),
(@PATH, 11, 2269.94, 893.051, 54.5021, 0),
(@PATH, 12, 2263.07, 909.73, 54.5019, 0),
(@PATH, 13, 2255.3, 934.26, 54.501, 0),
(@PATH, 14, 2247.8, 950.238, 54.4582, 0),
(@PATH, 15, 2243.19, 964.782, 54.4998, 0),
(@PATH, 16, 2237.24, 983.533, 54.5095, 0),
(@PATH, 17, 2233.59, 1000.86, 54.3187, 0),
(@PATH, 18, 2229.28, 1014.61, 53.5769, 0),
(@PATH, 19, 2221.45, 1018.46, 52.9309, 0),
(@PATH, 20, 2203, 1022.28, 49.5684, 0),
(@PATH, 21, 2180.63, 1029.22, 45.8132, 0),
(@PATH, 22, 2163.91, 1033.35, 43.1132, 0),
(@PATH, 23, 2147.39, 1039.4, 40.2942, 0),
(@PATH, 24, 2130.86, 1040.3, 37.7083, 0),
(@PATH, 25, 2114.52, 1037.05, 35.2203, 0),
(@PATH, 26, 2099.97, 1032.09, 33.0175, 0),
(@PATH, 27, 2085.48, 1024.85, 32.7897, 0),
(@PATH, 28, 2067.1, 1023.42, 31.5893, 0),
(@PATH, 29, 2053.53, 1026.31, 30.1988, 0),
(@PATH, 30, 2030.91, 1038.02, 27.0364, 0),
(@PATH, 31, 2017.57, 1040.71, 25.9681, 0),
(@PATH, 32, 2004.12, 1039.63, 25.5061, 0),
(@PATH, 33, 1993.23, 1036.26, 25.2964, 0),
(@PATH, 34, 1980, 1030.16, 25.0028, 0),
(@PATH, 35, 1971.42, 1030.94, 24.2482, 0),
(@PATH, 36, 1959.98, 1036.36, 22.9669, 0),
(@PATH, 37, 1948.68, 1047.78, 20.8565, 0),
(@PATH, 38, 1937.34, 1052.4, 20.1837, 0),
(@PATH, 39, 1925.76, 1053.7, 19.4854, 0),
(@PATH, 40, 1905.6, 1053.15, 18.1491, 0),
(@PATH, 41, 1888.62, 1055.3, 18.0517, 0),
(@PATH, 42, 1868.76, 1064.87, 16.3555, 0),
(@PATH, 43, 1846.84, 1077.65, 13.7145, 0),
(@PATH, 44, 1835.61, 1078.54, 12.2458, 0),
(@PATH, 45, 1817.8, 1071.93, 10.6522, 0),
(@PATH, 46, 1796.05, 1060.56, 8.13385, 0),
(@PATH, 47, 1789.08, 1059.15, 7.65879, 0),
(@PATH, 48, 1774.32, 1059.31, 6.80622, 0),
(@PATH, 49, 1788.97, 1058.6, 7.63011, 0),
(@PATH, 50, 1801.99, 1062.31, 8.54349, 0),
(@PATH, 51, 1823.33, 1073.43, 11.1419, 0),
(@PATH, 52, 1837.23, 1076.53, 12.5762, 0),
(@PATH, 53, 1851.52, 1075.54, 14.5757, 0),
(@PATH, 54, 1862.81, 1069.95, 15.9675, 0),
(@PATH, 55, 1877.71, 1059.18, 17.4732, 0),
(@PATH, 56, 1888.84, 1054.67, 18.0092, 0),
(@PATH, 57, 1904.79, 1052.51, 18.12, 0),
(@PATH, 58, 1939.39, 1050.96, 20.2504, 0),
(@PATH, 59, 1951.26, 1045.59, 21.1385, 0),
(@PATH, 60, 1965.78, 1032.34, 23.8575, 0),
(@PATH, 61, 1986.59, 1028.48, 25.645, 0),
(@PATH, 62, 2002.26, 1037.34, 25.438, 0),
(@PATH, 63, 2014.81, 1040.37, 25.9989, 0),
(@PATH, 64, 2033.74, 1037.58, 27.2585, 0),
(@PATH, 65, 2050.87, 1029.07, 29.6277, 0),
(@PATH, 66, 2063.27, 1024.33, 31.3215, 0),
(@PATH, 67, 2072.66, 1023.3, 32.046, 0),
(@PATH, 68, 2086.48, 1026.12, 32.7105, 0),
(@PATH, 69, 2106.57, 1033.64, 34.0726, 0),
(@PATH, 70, 2121.53, 1039.27, 36.4285, 0),
(@PATH, 71, 2141.18, 1040.22, 39.2886, 0),
(@PATH, 72, 2149.33, 1039.93, 40.538, 0),
(@PATH, 73, 2166.01, 1033.61, 43.3866, 0),
(@PATH, 74, 2192.56, 1024.79, 47.8952, 0),
(@PATH, 75, 2223.67, 1018.16, 53.1731, 0),
(@PATH, 76, 2232.56, 1009.46, 53.865, 0),
(@PATH, 77, 2240.66, 982.041, 54.5019, 0),
(@PATH, 78, 2247.14, 957.74, 54.5019, 0),
(@PATH, 79, 2254.1, 940.466, 54.4827, 0),
(@PATH, 80, 2264.73, 913.689, 54.5, 0),
(@PATH, 81, 2275.35, 886.915, 54.5, 0),
(@PATH, 82, 2282.61, 864.421, 54.5, 0),
(@PATH, 83, 2286.83, 848.53, 54.5075, 0),
(@PATH, 84, 2286.98, 836.984, 54.5962, 0),
(@PATH, 85, 2285.43, 818.579, 54.5534, 0),
(@PATH, 86, 2299.92, 826.916, 54.2152, 0),
(@PATH, 87, 2323.04, 836.71, 53.7918, 0),
(@PATH, 88, 2342.12, 844.995, 54.1024, 0),
(@PATH, 89, 2369.56, 854.127, 55.7927, 0),
(@PATH, 90, 2401.18, 863.514, 57.0901, 0),
(@PATH, 91, 2413.96, 866.099, 57.992, 0),
(@PATH, 92, 2460.26, 878.534, 62.1424, 0),
(@PATH, 93, 2477.08, 882.264, 63.1521, 0),
(@PATH, 94, 2496.16, 884.711, 63.766, 0),
(@PATH, 95, 2526.3, 884.571, 64.6078, 0),
(@PATH, 96, 2549.14, 885.522, 65.2781, 0),
(@PATH, 97, 2570.91, 884.899, 66.6748, 0),
(@PATH, 98, 2593.72, 883.698, 68.0105, 0),
(@PATH, 99, 2611.25, 881.574, 68.365, 0),
(@PATH, 100, 2623.99, 883.132, 68.6387, 0),
(@PATH, 101, 2647.38, 885.993, 69.8835, 0),
(@PATH, 102, 2648.69, 863.374, 66.4059, 0),
(@PATH, 103, 2643.39, 846.464, 63.4591, 0),
(@PATH, 104, 2645.2, 828.609, 60.7574, 0),
(@PATH, 105, 2650.3, 807.324, 59.3795, 0),
(@PATH, 106, 2647.34, 796.666, 58.6261, 0),
(@PATH, 107, 2636.73, 784.647, 57.6502, 0),
(@PATH, 108, 2622.12, 774.868, 57.0314, 0),
(@PATH, 109, 2614.77, 761.206, 56.4657, 0),
(@PATH, 110, 2613.46, 745.3, 56.1324, 0),
(@PATH, 111, 2617.36, 732.602, 55.5625, 0),
(@PATH, 112, 2626.33, 723.16, 55.8659, 0),
(@PATH, 113, 2634.97, 714.328, 56.1839, 0),
(@PATH, 114, 2640.5, 701.619, 55.9892, 0),
(@PATH, 115, 2634.83, 714.57, 56.1825, 0),
(@PATH, 116, 2616.87, 732.558, 55.5504, 0),
(@PATH, 117, 2613.24, 745.347, 56.1345, 0),
(@PATH, 118, 2615.79, 763.247, 56.5672, 0),
(@PATH, 119, 2621.52, 774.199, 57.0032, 0),
(@PATH, 120, 2635.18, 782.875, 57.5838, 0),
(@PATH, 121, 2649.14, 799.158, 58.8695, 0),
(@PATH, 122, 2651.07, 809.314, 59.4608, 0),
(@PATH, 123, 2644.77, 833.17, 61.2945, 0),
(@PATH, 124, 2645.05, 850.54, 64.1148, 0),
(@PATH, 125, 2648.81, 862.532, 66.2628, 0),
(@PATH, 126, 2648.37, 877.794, 69.0155, 0),
(@PATH, 127, 2644.96, 885.466, 69.7138, 0),
(@PATH, 128, 2630.96, 883.18, 68.9351, 0),
(@PATH, 129, 2610.28, 881.989, 68.3692, 0),
(@PATH, 130, 2585.17, 884.121, 67.9368, 0),
(@PATH, 131, 2552.44, 885.579, 65.2571, 0),
(@PATH, 132, 2531.61, 884.104, 64.6916, 0),
(@PATH, 133, 2504.17, 883.352, 63.879, 0),
(@PATH, 134, 2485.41, 883.278, 63.4378, 0),
(@PATH, 135, 2463.75, 879.443, 62.4912, 0),
(@PATH, 136, 2445.75, 875.207, 60.9997, 0),
(@PATH, 137, 2429.46, 871.952, 59.8412, 0);

-- Group of 3 NPC pathing main Path between Tarren Mill and Southshore
DELETE FROM `creature_formations` WHERE `leaderGUID`=38497;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(38497, 38497, 0, 0, 2, 0, 0),
(38497, 48008, 3, 60, 2, 0, 0),
(38497, 48009, 3, 300, 2, 0, 0);

SET @NPC := 38497;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2623.64, 882.626, 68.6133, 0),
(@PATH, 2, 2600.13, 882.822, 68.0922, 0),
(@PATH, 3, 2580.55, 883.611, 67.6017, 0),
(@PATH, 4, 2567.45, 885.735, 66.2376, 0),
(@PATH, 5, 2532.34, 884.413, 64.6915, 0),
(@PATH, 6, 2504.99, 883.813, 63.8629, 0),
(@PATH, 7, 2484.41, 882.641, 63.4126, 0),
(@PATH, 8, 2464.69, 879.085, 62.5522, 0),
(@PATH, 9, 2438.99, 875.143, 60.6649, 0),
(@PATH, 10, 2412.51, 866.219, 57.8843, 0),
(@PATH, 11, 2400.56, 862.671, 57.0296, 0),
(@PATH, 12, 2381.6, 858.764, 56.4373, 0),
(@PATH, 13, 2361.56, 851.541, 55.1672, 0),
(@PATH, 14, 2342.78, 845.588, 54.1166, 0),
(@PATH, 15, 2324.92, 837.409, 53.7317, 0),
(@PATH, 16, 2305.99, 829.468, 54.1501, 0),
(@PATH, 17, 2296.63, 825.295, 54.2967, 0),
(@PATH, 18, 2282.82, 816.84, 54.5995, 0),
(@PATH, 19, 2285.59, 830.712, 54.6387, 0),
(@PATH, 20, 2285.34, 850.387, 54.5222, 0),
(@PATH, 21, 2279.74, 868.564, 54.4983, 0),
(@PATH, 22, 2271.64, 888.568, 54.4999, 0),
(@PATH, 23, 2262.19, 911.921, 54.5229, 0),
(@PATH, 24, 2253.29, 935.335, 54.5011, 0),
(@PATH, 25, 2246.47, 955.744, 54.4992, 0),
(@PATH, 26, 2240.17, 975.643, 54.4938, 0),
(@PATH, 27, 2236.17, 997.163, 54.4527, 0),
(@PATH, 28, 2231.74, 1016.9, 53.6181, 0),
(@PATH, 29, 2210.78, 1020.64, 50.9163, 0),
(@PATH, 30, 2189.62, 1026.27, 47.3583, 0),
(@PATH, 31, 2155.27, 1036.57, 41.6736, 0),
(@PATH, 32, 2137.13, 1040.63, 38.6119, 0),
(@PATH, 33, 2117.75, 1037.24, 35.7503, 0),
(@PATH, 34, 2099.38, 1030.87, 33.0353, 0),
(@PATH, 35, 2076.36, 1024.7, 32.3428, 0),
(@PATH, 36, 2058.17, 1025.24, 30.8303, 0),
(@PATH, 37, 2040.36, 1033.63, 27.92, 0),
(@PATH, 38, 2022.57, 1039.79, 26.231, 0),
(@PATH, 39, 2005.44, 1039.58, 25.6047, 0),
(@PATH, 40, 1990.56, 1034.27, 25.3473, 0),
(@PATH, 41, 1978.21, 1029.65, 24.8705, 0),
(@PATH, 42, 1967.42, 1032.02, 23.9704, 0),
(@PATH, 43, 1954.63, 1041.74, 21.7939, 0),
(@PATH, 44, 1942.43, 1050.73, 20.3123, 0),
(@PATH, 45, 1933.61, 1052.95, 20.0561, 0),
(@PATH, 46, 1911.5, 1053.02, 18.556, 0),
(@PATH, 47, 1890.89, 1055.17, 17.9183, 0),
(@PATH, 48, 1873.91, 1063.11, 16.998, 0),
(@PATH, 49, 1852.8, 1075.69, 14.7824, 0),
(@PATH, 50, 1835.4, 1077.69, 12.2362, 0),
(@PATH, 51, 1822.26, 1073.72, 11.1149, 0),
(@PATH, 52, 1807.7, 1066.44, 9.26395, 0),
(@PATH, 53, 1792.85, 1059.36, 7.84803, 0),
(@PATH, 54, 1774.69, 1059.29, 6.81798, 0),
(@PATH, 55, 1792.6, 1059.07, 7.8329, 0),
(@PATH, 56, 1808.74, 1067.03, 9.4278, 0),
(@PATH, 57, 1823.02, 1073.86, 11.1345, 0),
(@PATH, 58, 1836.03, 1077.81, 12.3188, 0),
(@PATH, 59, 1849.01, 1076.66, 14.1002, 0),
(@PATH, 60, 1861.43, 1069.11, 15.7692, 0),
(@PATH, 61, 1874.49, 1062.7, 17.0596, 0),
(@PATH, 62, 1890.24, 1055.5, 17.9729, 0),
(@PATH, 63, 1904.57, 1053.95, 18.0479, 0),
(@PATH, 64, 1916.55, 1053.18, 18.9363, 0),
(@PATH, 65, 1933.4, 1052.95, 20.0517, 0),
(@PATH, 66, 1943.01, 1050.55, 20.3518, 0),
(@PATH, 67, 1955.44, 1041.45, 21.9159, 0),
(@PATH, 68, 1967.87, 1031.84, 24.0051, 0),
(@PATH, 69, 1979.65, 1030.46, 24.9749, 0),
(@PATH, 70, 1991.58, 1035.13, 25.3171, 0),
(@PATH, 71, 2004.26, 1040.18, 25.5059, 0),
(@PATH, 72, 2017.05, 1040.72, 25.9712, 0),
(@PATH, 73, 2029.5, 1038.99, 26.9065, 0),
(@PATH, 74, 2042.05, 1032.85, 28.1192, 0),
(@PATH, 75, 2055.96, 1026.3, 30.4824, 0),
(@PATH, 76, 2070.42, 1024.65, 31.8006, 0),
(@PATH, 77, 2086.33, 1025.68, 32.7406, 0),
(@PATH, 78, 2100.96, 1032, 33.1382, 0),
(@PATH, 79, 2114.52, 1037.04, 35.2198, 0),
(@PATH, 80, 2132.59, 1039.75, 37.9587, 0),
(@PATH, 81, 2144.46, 1040.52, 39.7703, 0),
(@PATH, 82, 2153.53, 1037.96, 41.3082, 0),
(@PATH, 83, 2167.6, 1033.48, 43.6209, 0),
(@PATH, 84, 2187.08, 1026.78, 46.943, 0),
(@PATH, 85, 2204.22, 1021.93, 49.7543, 0),
(@PATH, 86, 2223.61, 1017.27, 53.1783, 0),
(@PATH, 87, 2232.01, 1015.26, 53.6222, 0),
(@PATH, 88, 2236.23, 999.343, 54.3852, 0),
(@PATH, 89, 2239.38, 984.686, 54.5012, 0),
(@PATH, 90, 2242.49, 971.639, 54.5014, 0),
(@PATH, 91, 2248.3, 955.438, 54.5014, 0),
(@PATH, 92, 2254.99, 938.768, 54.4779, 0),
(@PATH, 93, 2261.07, 922.135, 54.5, 0),
(@PATH, 94, 2266.88, 905.883, 54.5, 0),
(@PATH, 95, 2274.21, 888.239, 54.5, 0),
(@PATH, 96, 2279.37, 874.616, 54.5, 0),
(@PATH, 97, 2284.17, 858.54, 54.5, 0),
(@PATH, 98, 2287.07, 842.492, 54.5179, 0),
(@PATH, 99, 2285.06, 822.339, 54.5329, 0),
(@PATH, 100, 2280.85, 810.904, 54.6746, 0),
(@PATH, 101, 2271.04, 797.561, 54.6055, 0),
(@PATH, 102, 2259.76, 781.45, 53.8876, 0),
(@PATH, 103, 2248.5, 765.984, 52.8455, 0),
(@PATH, 104, 2236.45, 751.637, 50.1543, 0),
(@PATH, 105, 2225.2, 738.288, 46.4978, 0),
(@PATH, 106, 2213.97, 724.141, 42.9242, 0),
(@PATH, 107, 2202.25, 709.473, 39.0475, 0),
(@PATH, 108, 2194.26, 696.874, 36.4775, 0),
(@PATH, 109, 2186.81, 684.001, 34.5315, 0),
(@PATH, 110, 2183.46, 671.279, 34.0336, 0),
(@PATH, 111, 2187.66, 685.597, 34.7246, 0),
(@PATH, 112, 2193.64, 696.274, 36.3443, 0),
(@PATH, 113, 2201.04, 707.84, 38.69, 0),
(@PATH, 114, 2211.41, 720.413, 41.9614, 0),
(@PATH, 115, 2220.05, 732.154, 44.9148, 0),
(@PATH, 116, 2231.68, 746.231, 48.6348, 0),
(@PATH, 117, 2243.47, 759.741, 51.9549, 0),
(@PATH, 118, 2255.85, 775.368, 53.5629, 0),
(@PATH, 119, 2266.82, 791.228, 54.4124, 0),
(@PATH, 120, 2279.62, 808.93, 54.6154, 0),
(@PATH, 121, 2288.49, 820.299, 54.508, 0),
(@PATH, 122, 2303.16, 828.045, 54.171, 0),
(@PATH, 123, 2322.33, 836.623, 53.8113, 0),
(@PATH, 124, 2338.3, 843.771, 53.9838, 0),
(@PATH, 125, 2356.31, 849.242, 54.7057, 0),
(@PATH, 126, 2372.63, 855.509, 56.0487, 0),
(@PATH, 127, 2392.92, 860.918, 56.7245, 0),
(@PATH, 128, 2403.8, 863.428, 57.2484, 0),
(@PATH, 129, 2417.72, 868.716, 58.2846, 0),
(@PATH, 130, 2431.94, 873.159, 60.0873, 0),
(@PATH, 131, 2453.95, 877.012, 61.4676, 0),
(@PATH, 132, 2471.19, 880.03, 62.9147, 0),
(@PATH, 133, 2488.42, 883.049, 63.5039, 0),
(@PATH, 134, 2513.13, 884.144, 64.1431, 0),
(@PATH, 135, 2534.12, 884.568, 64.6657, 0),
(@PATH, 136, 2555.08, 885.304, 65.2048, 0),
(@PATH, 137, 2569.07, 885.554, 66.4459, 0),
(@PATH, 138, 2582.07, 884.088, 67.696, 0),
(@PATH, 139, 2593.98, 882.95, 68.0114, 0),
(@PATH, 140, 2614.98, 882.582, 68.4484, 0),
(@PATH, 141, 2625.81, 882.393, 68.6676, 0),
(@PATH, 142, 2633.1, 883.922, 69.0972, 0),
(@PATH, 143, 2646.96, 884.471, 69.7285, 0),
(@PATH, 144, 2648.23, 865.67, 66.7963, 0),
(@PATH, 145, 2644.19, 848.839, 63.8337, 0),
(@PATH, 146, 2644.26, 834.261, 61.4547, 0),
(@PATH, 147, 2650.22, 812.238, 59.5396, 0),
(@PATH, 148, 2648.97, 801.635, 59.0204, 0),
(@PATH, 149, 2640.9, 787.801, 57.6706, 0),
(@PATH, 150, 2626.1, 777.72, 57.2633, 0),
(@PATH, 151, 2616.67, 767.457, 56.6651, 0),
(@PATH, 152, 2613.49, 757.029, 56.3742, 0),
(@PATH, 153, 2613.37, 741.667, 55.9822, 0),
(@PATH, 154, 2619.74, 729.303, 55.5678, 0),
(@PATH, 155, 2630.88, 717.435, 56.0887, 0),
(@PATH, 156, 2639.41, 707.385, 56.074, 0),
(@PATH, 157, 2640.33, 701.769, 56.002, 0),
(@PATH, 158, 2638, 711.757, 56.1583, 0),
(@PATH, 159, 2627.47, 721.829, 55.9278, 0),
(@PATH, 160, 2618, 732.662, 55.6043, 0),
(@PATH, 161, 2612.4, 747.203, 56.2022, 0),
(@PATH, 162, 2615.04, 762.187, 56.5118, 0),
(@PATH, 163, 2619.29, 771.77, 56.8562, 0),
(@PATH, 164, 2626.66, 778.108, 57.286, 0),
(@PATH, 165, 2644.28, 790.759, 57.9907, 0),
(@PATH, 166, 2649.74, 800.614, 58.9864, 0),
(@PATH, 167, 2650.19, 813.604, 59.6128, 0),
(@PATH, 168, 2647.7, 823.968, 60.3343, 0),
(@PATH, 169, 2644.31, 836.22, 61.7544, 0),
(@PATH, 170, 2644.69, 847.637, 63.6237, 0),
(@PATH, 171, 2648.54, 860.659, 65.9248, 0),
(@PATH, 172, 2646.93, 878.184, 69.0024, 0),
(@PATH, 173, 2644.64, 885.239, 69.6836, 0);

-- Aged Dalaran Wizard pathing main Path between Tarren Mill and Southshore
DELETE FROM `creature_formations` WHERE `leaderGUID`=83476;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(83476, 83476, 0, 0, 2, 0, 0),
(83476, 83477, 2, 270, 2, 0, 0);

SET @NPC := 83476;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2484.44, 882.836, 63.4156, 0),
(@PATH, 2, 2510.93, 884.306, 63.9832, 0),
(@PATH, 3, 2539.44, 884.782, 64.7488, 0),
(@PATH, 4, 2564.57, 885.359, 65.7858, 0),
(@PATH, 5, 2580.22, 884.448, 67.5697, 0),
(@PATH, 6, 2600.64, 882.524, 68.1024, 0),
(@PATH, 7, 2618.57, 882.459, 68.4928, 0),
(@PATH, 8, 2646.56, 885.349, 69.7791, 0),
(@PATH, 9, 2647.94, 862.361, 66.1963, 0),
(@PATH, 10, 2644.15, 843.683, 62.9245, 0),
(@PATH, 11, 2645.15, 829.603, 60.8501, 0),
(@PATH, 12, 2649.89, 809.554, 59.4495, 0),
(@PATH, 13, 2647.55, 798.667, 58.7754, 0),
(@PATH, 14, 2638.41, 786, 57.6675, 0),
(@PATH, 15, 2625.34, 776.466, 57.2481, 0),
(@PATH, 16, 2615.74, 765.931, 56.5869, 0),
(@PATH, 17, 2611.94, 751.53, 56.3252, 0),
(@PATH, 18, 2613.24, 738.202, 55.7307, 0),
(@PATH, 19, 2621.66, 727.464, 55.6185, 0),
(@PATH, 20, 2635.37, 713.483, 56.1676, 0),
(@PATH, 21, 2640.86, 702.72, 56.0097, 0),
(@PATH, 22, 2639.43, 692.111, 55.5087, 0),
(@PATH, 23, 2633.71, 674.388, 54.4811, 0),
(@PATH, 24, 2619.19, 672.633, 54.8655, 0),
(@PATH, 25, 2624.72, 672.28, 54.4806, 300000),
(@PATH, 26, 2634.5, 674.4, 54.4789, 0),
(@PATH, 27, 2640.02, 686.749, 55.1281, 0),
(@PATH, 28, 2641.53, 699.248, 55.8583, 0),
(@PATH, 29, 2639.61, 708.263, 56.0874, 0),
(@PATH, 30, 2630.65, 719.151, 56.0962, 0),
(@PATH, 31, 2620.88, 728.317, 55.5883, 0),
(@PATH, 32, 2614.01, 737.448, 55.7114, 0),
(@PATH, 33, 2612.71, 746.896, 56.1872, 0),
(@PATH, 34, 2614.34, 758.087, 56.4286, 0),
(@PATH, 35, 2620.39, 771.216, 56.9779, 0),
(@PATH, 36, 2630.91, 779.742, 57.4555, 0),
(@PATH, 37, 2642.88, 791.11, 57.9629, 0),
(@PATH, 38, 2650.38, 802.874, 59.1506, 0),
(@PATH, 39, 2649.7, 812.675, 59.575, 0),
(@PATH, 40, 2644.98, 829.942, 60.8814, 0),
(@PATH, 41, 2644.41, 840.724, 62.4603, 0),
(@PATH, 42, 2646.98, 855.456, 64.9715, 0),
(@PATH, 43, 2648.87, 870.519, 67.7707, 0),
(@PATH, 44, 2646.21, 884.709, 69.7036, 0),
(@PATH, 45, 2631.29, 884.261, 69.0209, 0),
(@PATH, 46, 2615.04, 883.348, 68.4797, 0),
(@PATH, 47, 2597.47, 883.854, 68.0493, 0),
(@PATH, 48, 2583.38, 884.076, 67.7796, 0),
(@PATH, 49, 2569.03, 885.343, 66.4438, 0),
(@PATH, 50, 2551.47, 885.757, 65.2873, 0),
(@PATH, 51, 2529.49, 884.877, 64.7253, 0),
(@PATH, 52, 2515.88, 884.324, 64.27, 0),
(@PATH, 53, 2494.9, 883.438, 63.7383, 0),
(@PATH, 54, 2476.21, 882.07, 63.1265, 0),
(@PATH, 55, 2463.86, 879.17, 62.4931, 0),
(@PATH, 56, 2437.2, 874.755, 60.551, 0),
(@PATH, 57, 2415.99, 867.724, 58.1546, 0),
(@PATH, 58, 2401.85, 862.609, 57.106, 0),
(@PATH, 59, 2384.78, 859.055, 56.4635, 0),
(@PATH, 60, 2365.69, 852.577, 55.5241, 0),
(@PATH, 61, 2347.16, 847.12, 54.2153, 0),
(@PATH, 62, 2324.49, 837.671, 53.7492, 0),
(@PATH, 63, 2305.17, 829.589, 54.1504, 0),
(@PATH, 64, 2283.7, 819.391, 54.5816, 0),
(@PATH, 65, 2285.78, 832.717, 54.6634, 0),
(@PATH, 66, 2285.61, 848.997, 54.5251, 0),
(@PATH, 67, 2281.22, 866.684, 54.4996, 0),
(@PATH, 68, 2274.42, 886.65, 54.4996, 0),
(@PATH, 69, 2271.8, 896.994, 54.4996, 0),
(@PATH, 70, 2283.58, 912.005, 54.3671, 0),
(@PATH, 71, 2293.96, 921.826, 55.279, 0),
(@PATH, 72, 2309.65, 924.832, 56.0533, 0),
(@PATH, 73, 2326.83, 928.12, 55.0895, 0),
(@PATH, 74, 2338.55, 925.683, 54.7203, 0),
(@PATH, 75, 2338.17, 915.167, 55.198, 0),
(@PATH, 76, 2334.54, 907.066, 57.6645, 0),
(@PATH, 77, 2328.35, 889.876, 57.6674, 0),
(@PATH, 78, 2321.92, 887.23, 57.6692, 0),
(@PATH, 79, 2323.55, 888.326, 57.6692, 300000),
(@PATH, 80, 2329.57, 892.875, 57.6662, 0),
(@PATH, 81, 2334.01, 903.506, 57.6648, 0),
(@PATH, 82, 2340.36, 921.749, 54.5965, 0),
(@PATH, 83, 2334.77, 929.846, 54.9493, 0),
(@PATH, 84, 2316.57, 926.323, 55.4144, 0),
(@PATH, 85, 2300.02, 923.086, 55.9156, 0),
(@PATH, 86, 2282.16, 920.261, 54.368, 0),
(@PATH, 87, 2258.17, 928.854, 54.4995, 0),
(@PATH, 88, 2252.08, 944.634, 54.4912, 0),
(@PATH, 89, 2245.8, 960.966, 54.4995, 0),
(@PATH, 90, 2240.95, 978.309, 54.4996, 0),
(@PATH, 91, 2235.7, 999.538, 54.3791, 0),
(@PATH, 92, 2229.54, 1016.37, 53.5518, 0),
(@PATH, 93, 2213.16, 1020.04, 51.3927, 0),
(@PATH, 94, 2189.38, 1025.91, 47.3435, 0),
(@PATH, 95, 2171.27, 1032.24, 44.2345, 0),
(@PATH, 96, 2148.13, 1040.17, 40.3426, 0),
(@PATH, 97, 2127.85, 1040.17, 37.3234, 0),
(@PATH, 98, 2110.52, 1036.07, 34.628, 0),
(@PATH, 99, 2090.02, 1027.34, 32.6423, 0),
(@PATH, 100, 2072.19, 1024.75, 31.9712, 0),
(@PATH, 101, 2053.09, 1027.53, 30.0452, 0),
(@PATH, 102, 2029.54, 1038.47, 26.9195, 0),
(@PATH, 103, 2009.98, 1040.73, 25.853, 0),
(@PATH, 104, 2001.2, 1039.51, 25.2896, 0),
(@PATH, 105, 1979.32, 1030.49, 24.9552, 0),
(@PATH, 106, 1965.54, 1033.01, 23.7563, 0),
(@PATH, 107, 1951.36, 1045.57, 21.1473, 0),
(@PATH, 108, 1939.54, 1052.06, 20.2084, 0),
(@PATH, 109, 1920.73, 1052.65, 19.2175, 0),
(@PATH, 110, 1904.22, 1053.3, 18.0501, 0),
(@PATH, 111, 1886.72, 1055.3, 18.0974, 0),
(@PATH, 112, 1871.29, 1064.12, 16.6739, 0),
(@PATH, 113, 1846.86, 1076.66, 13.798, 0),
(@PATH, 114, 1837.21, 1077.89, 12.5072, 0),
(@PATH, 115, 1821.72, 1073.54, 11.108, 0),
(@PATH, 116, 1805.24, 1065.43, 8.95542, 0),
(@PATH, 117, 1790.37, 1058.89, 7.72108, 0),
(@PATH, 118, 1765.72, 1060.38, 6.87971, 0),
(@PATH, 119, 1770.31, 1059.76, 6.87971, 120000),
(@PATH, 120, 1783.56, 1058.86, 7.42003, 0),
(@PATH, 121, 1794.47, 1058.99, 7.97726, 0),
(@PATH, 122, 1807.51, 1065.96, 9.21146, 0),
(@PATH, 123, 1825.51, 1074.67, 11.1986, 0),
(@PATH, 124, 1836.73, 1077.79, 12.4331, 0),
(@PATH, 125, 1848.64, 1076.24, 14.0606, 0),
(@PATH, 126, 1858.05, 1071.44, 15.4975, 0),
(@PATH, 127, 1880.12, 1058.81, 17.7728, 0),
(@PATH, 128, 1894.45, 1053.66, 17.8059, 0),
(@PATH, 129, 1913.2, 1053.16, 18.6841, 0),
(@PATH, 130, 1931.36, 1052.92, 19.8936, 0),
(@PATH, 131, 1944.75, 1049.13, 20.5239, 0),
(@PATH, 132, 1954, 1042.49, 21.6457, 0),
(@PATH, 133, 1964.44, 1033.57, 23.6144, 0),
(@PATH, 134, 1975.82, 1029.8, 24.6549, 0),
(@PATH, 135, 1983.12, 1030.86, 25.2257, 0),
(@PATH, 136, 1993.08, 1035.62, 25.3041, 0),
(@PATH, 137, 2007.14, 1040.49, 25.6891, 0),
(@PATH, 138, 2018.65, 1039.88, 26.0706, 0),
(@PATH, 139, 2032.41, 1037.2, 27.1894, 0),
(@PATH, 140, 2047.44, 1029.89, 29.103, 0),
(@PATH, 141, 2062.67, 1025.82, 31.2087, 0),
(@PATH, 142, 2076.92, 1025.55, 32.3808, 0),
(@PATH, 143, 2095.31, 1029.02, 32.8091, 0),
(@PATH, 144, 2105.21, 1033.11, 33.8701, 0),
(@PATH, 145, 2119.91, 1038.25, 36.1388, 0),
(@PATH, 146, 2135.67, 1040.77, 38.3721, 0),
(@PATH, 147, 2145.66, 1040.17, 39.9787, 0),
(@PATH, 148, 2163.14, 1034.74, 42.9007, 0),
(@PATH, 149, 2176.48, 1030.5, 45.1048, 0),
(@PATH, 150, 2193.16, 1025.21, 47.957, 0),
(@PATH, 151, 2206.78, 1021.86, 50.168, 0),
(@PATH, 152, 2217.89, 1019.03, 52.3635, 0),
(@PATH, 153, 2230.66, 1015.18, 53.5869, 0),
(@PATH, 154, 2234.51, 999.913, 54.3663, 0),
(@PATH, 155, 2239.39, 979.488, 54.5038, 0),
(@PATH, 156, 2242.45, 967.077, 54.4997, 0),
(@PATH, 157, 2249.13, 949.697, 54.4922, 0),
(@PATH, 158, 2256.55, 926.348, 54.4994, 0),
(@PATH, 159, 2264.17, 904.88, 54.5049, 0),
(@PATH, 160, 2271.78, 885.601, 54.5015, 0),
(@PATH, 161, 2278.94, 865.297, 54.4758, 0),
(@PATH, 162, 2282.9, 846.983, 54.6272, 0),
(@PATH, 163, 2283.47, 830.009, 54.7596, 0),
(@PATH, 164, 2281.13, 816.505, 54.6117, 0),
(@PATH, 165, 2276.22, 806.486, 54.5153, 0),
(@PATH, 166, 2265.45, 790.047, 54.3814, 0),
(@PATH, 167, 2256.38, 776.214, 53.6021, 0),
(@PATH, 168, 2246.84, 764.769, 52.64, 0),
(@PATH, 169, 2232.98, 748.998, 49.2838, 0),
(@PATH, 170, 2221.36, 734.463, 45.4158, 0),
(@PATH, 171, 2210.83, 720.879, 41.9219, 0),
(@PATH, 172, 2198.42, 706.344, 38.1333, 0),
(@PATH, 173, 2190.49, 692.252, 35.5654, 0),
(@PATH, 174, 2184.56, 676.787, 34.1533, 0),
(@PATH, 175, 2179.64, 658.68, 34.6227, 0),
(@PATH, 176, 2175.14, 641.688, 33.7795, 0),
(@PATH, 177, 2171.76, 621.264, 37.1826, 0),
(@PATH, 178, 2169.33, 603.94, 40.0493, 0),
(@PATH, 179, 2164.37, 580.871, 43.7035, 0),
(@PATH, 180, 2159.85, 568.293, 46.738, 0),
(@PATH, 181, 2151.5, 554.339, 50.1121, 0),
(@PATH, 182, 2139.26, 538.204, 53.8114, 0),
(@PATH, 183, 2124.7, 524.492, 56.6386, 0),
(@PATH, 184, 2112.09, 512.415, 58.9956, 0),
(@PATH, 185, 2101.86, 500.054, 61.4978, 0),
(@PATH, 186, 2093.21, 485.163, 64.4652, 0),
(@PATH, 187, 2087.71, 474.389, 65.8823, 0),
(@PATH, 188, 2081.22, 453.773, 66.213, 0),
(@PATH, 189, 2075.88, 433.463, 66.2423, 0),
(@PATH, 190, 2069.13, 416.607, 66.1058, 0),
(@PATH, 191, 2060.92, 398.711, 66.0681, 0),
(@PATH, 192, 2052.46, 379.493, 65.8712, 0),
(@PATH, 193, 2043.56, 358.103, 66.1094, 0),
(@PATH, 194, 2032.41, 336.363, 66.0943, 0),
(@PATH, 195, 2021.8, 319.675, 66.0953, 0),
(@PATH, 196, 2008.19, 296.626, 66.1349, 0),
(@PATH, 197, 1998.81, 281.854, 66.3684, 0),
(@PATH, 198, 1988.77, 269.184, 67.0842, 0),
(@PATH, 199, 1974.87, 253.446, 67.4902, 0),
(@PATH, 200, 1964.27, 238.185, 67.6519, 0),
(@PATH, 201, 1951.3, 219.171, 68.1409, 0),
(@PATH, 202, 1960.73, 232.116, 67.995, 0),
(@PATH, 203, 1971.48, 247.189, 67.5766, 0),
(@PATH, 204, 1983.39, 261.055, 67.2802, 0),
(@PATH, 205, 1993.67, 273.103, 66.8403, 0),
(@PATH, 206, 2005.65, 288.315, 66.0724, 0),
(@PATH, 207, 2017.05, 307.801, 66.096, 0),
(@PATH, 208, 2028.96, 327.909, 66.1042, 0),
(@PATH, 209, 2037.46, 342.5, 66.0831, 0),
(@PATH, 210, 2042.81, 354.123, 66.1165, 0),
(@PATH, 211, 2051.01, 372.133, 65.9799, 0),
(@PATH, 212, 2059.64, 391.626, 66.0603, 0),
(@PATH, 213, 2067.55, 408.235, 66.0527, 0),
(@PATH, 214, 2073.75, 420.632, 66.1428, 0),
(@PATH, 215, 2076.29, 429.107, 66.2477, 0),
(@PATH, 216, 2080.9, 442.242, 66.309, 0),
(@PATH, 217, 2086.34, 460.101, 66.0378, 0),
(@PATH, 218, 2091.98, 476.118, 65.3368, 0),
(@PATH, 219, 2099.79, 491.783, 62.9201, 0),
(@PATH, 220, 2107.42, 503.331, 60.6828, 0),
(@PATH, 221, 2118.76, 515.219, 58.1502, 0),
(@PATH, 222, 2131.15, 527.571, 55.8886, 0),
(@PATH, 223, 2140.79, 537.176, 53.7152, 0),
(@PATH, 224, 2144.44, 542.761, 52.4192, 0),
(@PATH, 225, 2154.29, 554.481, 49.7551, 0),
(@PATH, 226, 2162.78, 568.52, 46.297, 0),
(@PATH, 227, 2167.29, 582.38, 43.1949, 0),
(@PATH, 228, 2170.78, 595.639, 41.1054, 0),
(@PATH, 229, 2172.34, 615.971, 38.0711, 0),
(@PATH, 230, 2175.06, 634.978, 34.2314, 0),
(@PATH, 231, 2175.95, 643.187, 33.7847, 0),
(@PATH, 232, 2179.23, 655.55, 34.7027, 0),
(@PATH, 233, 2183.32, 670.979, 34.0321, 0),
(@PATH, 234, 2187.82, 683.788, 34.6194, 0),
(@PATH, 235, 2195.17, 695.803, 36.5461, 0),
(@PATH, 236, 2202.93, 707.461, 38.9909, 0),
(@PATH, 237, 2210.51, 717.339, 41.4097, 0),
(@PATH, 238, 2219.58, 728.004, 44.3297, 0),
(@PATH, 239, 2228.47, 739.519, 47.1595, 0),
(@PATH, 240, 2237.1, 750.536, 50.0677, 0),
(@PATH, 241, 2245.74, 761.556, 52.2765, 0),
(@PATH, 242, 2253.97, 771.231, 53.3686, 0),
(@PATH, 243, 2263.02, 783.428, 54.0886, 0),
(@PATH, 244, 2272.15, 797.066, 54.6196, 0),
(@PATH, 245, 2280.73, 809.495, 54.6687, 0),
(@PATH, 246, 2289.92, 821.383, 54.4901, 0),
(@PATH, 247, 2301.29, 827.138, 54.2022, 0),
(@PATH, 248, 2317.03, 833.522, 54.0437, 0),
(@PATH, 249, 2330.66, 838.962, 53.6741, 0),
(@PATH, 250, 2343.41, 845.529, 54.1241, 0),
(@PATH, 251, 2356.85, 849.453, 54.7519, 0),
(@PATH, 252, 2370.29, 853.377, 55.8436, 0),
(@PATH, 253, 2385.63, 858.48, 56.4489, 0),
(@PATH, 254, 2395.35, 860.76, 56.7646, 0),
(@PATH, 255, 2407.88, 863.791, 57.5737, 0),
(@PATH, 256, 2423.09, 869.003, 59.0037, 0),
(@PATH, 257, 2434.44, 872.88, 60.3057, 0),
(@PATH, 258, 2449.86, 876.148, 61.1585, 0),
(@PATH, 259, 2464.5, 879.114, 62.5365, 0);

SET @NPC := 48018;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2051.33, 534.764, 73.7314, 0),
(@PATH, 2, 2051.37, 537.969, 75.5968, 0),
(@PATH, 3, 2052.96, 540.417, 76.9039, 0),
(@PATH, 4, 2055.73, 542.917, 79.0258, 0),
(@PATH, 5, 2062.07, 543.762, 79.1671, 0),
(@PATH, 6, 2065.1, 542.501, 80.8321, 0),
(@PATH, 7, 2067.21, 540.755, 82.38, 0),
(@PATH, 8, 2068.8, 537.769, 84.3815, 0),
(@PATH, 9, 2068.38, 534.491, 84.7589, 0),
(@PATH, 10, 2065.29, 529.092, 85.5457, 0),
(@PATH, 11, 2061.58, 528.074, 87.6418, 0),
(@PATH, 12, 2058.9, 528.056, 89.2877, 0),
(@PATH, 13, 2056.76, 529.256, 89.4443, 0),
(@PATH, 14, 2053.23, 533.893, 89.8688, 0),
(@PATH, 15, 2053.36, 536.69, 91.3677, 0),
(@PATH, 16, 2055.02, 539.629, 92.9179, 0),
(@PATH, 17, 2056.98, 541.084, 93.927, 0),
(@PATH, 18, 2059.3, 541.865, 94.5266, 0),
(@PATH, 19, 2061.57, 541.285, 94.9473, 0),
(@PATH, 20, 2060.64, 535.156, 97.747, 0),
(@PATH, 21, 2059.31, 530.842, 100.531, 0),
(@PATH, 22, 2060.54, 535.707, 97.4071, 0),
(@PATH, 23, 2061.93, 541.194, 94.9474, 0),
(@PATH, 24, 2059.73, 541.924, 94.9474, 0),
(@PATH, 25, 2057.16, 541.141, 94.0179, 0),
(@PATH, 26, 2055.08, 539.1, 92.7484, 0),
(@PATH, 27, 2053.35, 535.673, 90.6795, 0),
(@PATH, 28, 2053.57, 533.008, 89.5515, 0),
(@PATH, 29, 2056.91, 529.125, 89.4441, 0),
(@PATH, 30, 2059.6, 527.72, 88.9857, 0),
(@PATH, 31, 2062.49, 528.05, 87.0064, 0),
(@PATH, 32, 2066.5, 529.085, 85.2376, 0),
(@PATH, 33, 2068.44, 534.399, 84.7585, 0),
(@PATH, 34, 2068.97, 537.733, 84.4412, 0),
(@PATH, 35, 2067.32, 540.688, 82.4334, 0),
(@PATH, 36, 2065.05, 542.714, 80.7385, 0),
(@PATH, 37, 2061.49, 543.768, 79.1515, 0),
(@PATH, 38, 2056.66, 542.996, 79.1417, 0),
(@PATH, 39, 2052.79, 540.14, 76.7666, 0),
(@PATH, 40, 2051.49, 537.149, 75.2349, 0),
(@PATH, 41, 2051.51, 534, 73.454, 0),
(@PATH, 42, 2053.59, 529.433, 73.3263, 0),
(@PATH, 43, 2056.51, 526.283, 72.3833, 0),
(@PATH, 44, 2059.3, 525.417, 71.1581, 0),
(@PATH, 45, 2065.27, 527.393, 70.1031, 0),
(@PATH, 46, 2065.1, 541.582, 65.4417, 0),
(@PATH, 47, 2051.87, 540.313, 65.4373, 0),
(@PATH, 48, 2038.58, 546.649, 65.4359, 0),
(@PATH, 49, 2052.26, 540.102, 65.4373, 0),
(@PATH, 50, 2065.8, 541.531, 65.4401, 0),
(@PATH, 51, 2070, 536.38, 65.7323, 0),
(@PATH, 52, 2069.49, 531.268, 67.8543, 0),
(@PATH, 53, 2065.26, 526.944, 70.2077, 0),
(@PATH, 54, 2059.02, 525.775, 71.3116, 0),
(@PATH, 55, 2056.32, 527.167, 72.5036, 0),
(@PATH, 56, 2053.58, 529.718, 73.3264, 0);

-- -------------Guard
-- Guards In Tower Near Southshore and Terran Mill
DELETE FROM `creature_formations` WHERE `leaderGUID`=44653;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(44653, 44653, 0, 0, 2, 0, 0),
(44653, 44656, 0, 0, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=46842;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(46842, 46842, 0, 0, 2, 0, 0),
(46842, 46850, 0, 0, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=31908;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(31908, 31908, 0, 0, 2, 0, 0),
(31908, 47583, 0, 0, 2, 0, 0),
(31908, 47894, 0, 0, 2, 0, 0);

-- Innkeeper in Terran Mill
SET @NPC := 83455;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2659.13, 661.505, 57.1724, 0),
(@PATH, 2, 2666.43, 656.46, 57.6475, 0),
(@PATH, 3, 2665.61, 653.988, 57.6495, 0),
(@PATH, 4, 2666.8, 656.365, 57.6495, 0),
(@PATH, 5, 2662.14, 659.49, 57.1598, 0),
(@PATH, 6, 2659.78, 661.332, 57.1711, 0),
(@PATH, 7, 2656.51, 662.994, 57.1711, 0),
(@PATH, 8, 2661.96, 673.283, 57.1711, 0),
(@PATH, 9, 2657.29, 664.071, 57.1711, 0),
(@PATH, 10, 2651.64, 666.535, 57.1711, 0),
(@PATH, 11, 2654.13, 671.54, 57.1711, 0),
(@PATH, 12, 2651.96, 667.148, 57.1711, 0),
(@PATH, 13, 2654.05, 665.667, 57.1711, 0),
(@PATH, 14, 2653.07, 662.969, 57.1724, 5000),
(@PATH, 15, 2654.46, 665.262, 57.1724, 0),
(@PATH, 16, 2658.31, 661.64, 57.1724, 0),
(@PATH, 17, 2666.47, 656.886, 57.6466, 8000),
(@PATH, 18, 2661.97, 659.914, 57.1601, 0),
(@PATH, 19, 2659.86, 657.466, 57.1623, 5000),
(@PATH, 20, 2661.44, 662.396, 57.1711, 8000),
(@PATH, 21, 2657.02, 663.077, 57.1711, 0);

-- ===========
-- Orcs In Pit
-- ===========
UPDATE `creature` SET `position_x` = 2115.998779, `position_y` = 42.767368, `position_z` = 54.557854, `orientation` = 3.667591 WHERE `guid` = 83918;
DELETE FROM `creature_addon` WHERE `guid` IN (83918);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83918,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2104.535889, `position_y` = 56.620735, `position_z` = 54.242908, `orientation` = 4.917089 WHERE `guid` = 83916;
DELETE FROM `creature_addon` WHERE `guid` IN (83916);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83916,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2066.981934, `position_y` = 67.596283, `position_z` = 54.343513, `orientation` = 6.107752 WHERE `guid` = 83925;
DELETE FROM `creature_addon` WHERE `guid` IN (83925);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83925,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2072.802490, `position_y` = 88.352287, `position_z` = 54.845284, `orientation` = 3.299170 WHERE `guid` = 83946;
DELETE FROM `creature_addon` WHERE `guid` IN (83946);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83946,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2062.651367, `position_y` = 112.068413, `position_z` = 55.389854, `orientation` = 1.968705 WHERE `guid` = 83919;
DELETE FROM `creature_addon` WHERE `guid` IN (83919);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83919,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2058.154053, `position_y` = 117.512825, `position_z` = 55.403820, `orientation` = 5.780243 WHERE `guid` = 83920;
DELETE FROM `creature_addon` WHERE `guid` IN (83920);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83920,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2208.021240, `position_y` = 267.573883, `position_z` = 54.778271, `orientation` = 4.669735 WHERE `guid` = 83964;
DELETE FROM `creature_addon` WHERE `guid` IN (83964);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83964,0,0,3,0,0, '');

UPDATE `creature` SET `position_x` = 2224.651367, `position_y` = 247.469345, `position_z` = 53.833801, `orientation` = 2.452557 WHERE `guid` = 83965;
DELETE FROM `creature_addon` WHERE `guid` IN (83965);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83965,0,0,1,0,0, '');

UPDATE `creature` SET `position_x` = 2105.004150, `position_y` = 90.833382, `position_z` = 53.709354, `orientation` = 2.033894 WHERE `guid` = 83456;
DELETE FROM `creature_addon` WHERE `guid` IN (83456);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83456,0,0,1,0,0, '');

UPDATE `creature` SET `position_x` = 2106.529785, `position_y` = 99.617836, `position_z` = 53.004929, `orientation` = 3.877224 WHERE `guid` = 83915;
DELETE FROM `creature_addon` WHERE `guid` IN (83915);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83915,0,0,1,0,0, '');

UPDATE `creature` SET `position_x` = 2097.408936, `position_y` = 96.302238, `position_z` = 53.166386, `orientation` = 6.253055 WHERE `guid` = 83914;
DELETE FROM `creature_addon` WHERE `guid` IN (83914);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83914,0,0,1,0,0, '');

UPDATE `creature` SET `position_x` = 2178.179443, `position_y` = 235.513840, `position_z` = 52.484241, `orientation` = 5.307471 WHERE `guid` = 83952;
DELETE FROM `creature_addon` WHERE `guid` IN (83952);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(83952,0,0,1,0,0, '');

UPDATE `creature` SET `position_x` = 2070.596924, `position_y` = 128.493576, `position_z` = 54.269028, `orientation` = 1.757468, `SpawnDist` = 5, `MovementType` = 1 WHERE `guid` = 83921;

UPDATE `creature` SET `position_x` = 2103.312012, `position_y` = 79.108421, `position_z` = 52.891743, `orientation` = 2.787092, `SpawnDist`=10, `MovementType`=1 WHERE `guid` = 83917;

UPDATE `creature` SET `SpawnDist` = 5, `MovementType` = 1 WHERE `guid` IN (83953,83954,83957);

SET @NPC := 83947;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH, 1, 2180.82, 233.922, 52.4421, 0),
(@PATH, 2, 2190.96, 246.4, 52.5535, 0),
(@PATH, 3, 2183.91, 242.109, 52.8828, 0),
(@PATH, 4, 2178.55, 227.63, 52.4409, 0),
(@PATH, 5, 2158.69, 218.061, 52.536, 0),
(@PATH, 6, 2147.28, 209.24, 52.8493, 0),
(@PATH, 7, 2137.69, 195.197, 52.4411, 0),
(@PATH, 8, 2128.08, 184.306, 52.7819, 0),
(@PATH, 9, 2121.61, 171.933, 52.7363, 0),
(@PATH, 10, 2111.17, 158.333, 52.441, 0),
(@PATH, 11, 2105.6, 139.581, 52.8057, 0),
(@PATH, 12, 2094.98, 124.519, 52.4842, 0),
(@PATH, 13, 2092.72, 96.002, 52.4763, 0),
(@PATH, 14, 2091.2, 76.6567, 52.8143, 0),
(@PATH, 15, 2078.5, 69.1538, 53.7881, 0),
(@PATH, 16, 2072.3, 67.2213, 53.7802, 0),
(@PATH, 17, 2068.55, 74.1697, 53.7048, 0),
(@PATH, 18, 2061.92, 89.1792, 54.1012, 0),
(@PATH, 19, 2067.51, 74.6493, 53.7406, 0),
(@PATH, 20, 2072.52, 67.0591, 53.7853, 0),
(@PATH, 21, 2080.31, 69.6531, 53.7724, 0),
(@PATH, 22, 2089.71, 73.7002, 52.751, 0),
(@PATH, 23, 2105.1, 66.6614, 52.5804, 0),
(@PATH, 24, 2115.84, 65.2019, 52.6007, 0),
(@PATH, 25, 2107.39, 83.1457, 53.3359, 0),
(@PATH, 26, 2093.76, 89.7505, 52.4537, 0),
(@PATH, 27, 2096.11, 107.581, 52.7549, 0),
(@PATH, 28, 2101.5, 127.271, 52.5706, 0),
(@PATH, 29, 2108.5, 146.257, 52.4418, 0),
(@PATH, 30, 2115.04, 159.756, 52.5111, 0),
(@PATH, 31, 2120.53, 167.026, 52.6508, 0),
(@PATH, 32, 2124.68, 178.425, 52.634, 0),
(@PATH, 33, 2131.69, 188.464, 52.5914, 0),
(@PATH, 34, 2141.64, 198.599, 52.4418, 0),
(@PATH, 35, 2153.1, 209.287, 53.1284, 0),
(@PATH, 36, 2167.16, 227.906, 52.4409, 0),
(@PATH, 37, 2163.87, 233.083, 52.4411, 0),
(@PATH, 38, 2157.18, 241.131, 53.8787, 0),
(@PATH, 39, 2158.75, 247.807, 53.9186, 0),
(@PATH, 40, 2166.33, 247.603, 53.7073, 0),
(@PATH, 41, 2158.31, 238.862, 53.8797, 0),
(@PATH, 42, 2167.1, 228.618, 52.4411, 0),
(@PATH, 43, 2180.26, 229.167, 52.4411, 0),
(@PATH, 44, 2187.37, 241.135, 52.6137, 0);

-- ======================
-- Gameobject Spawn Fixes 
-- ======================
-- Minerals and Herbs Not Spawned in Heroic Mode
UPDATE `gameobject` SET `SpawnMask` = 3, `SpawnTimeSecs` = 86400 WHERE `map`=560 AND `ID` IN (181270,181275,181276,181278,181556,181569);

-- ===========================================
-- Creature Spawn Time Fixes (24 Hour Respawn) - Confirmed No Special Short Spawn Time NPC
-- ===========================================
UPDATE `creature` SET `SpawnTimeSecs` = 86400 WHERE `map` IN (560);
UPDATE `creature` SET `SpawnTimeSecs` = 180 WHERE `map` IN (560) AND id IN (2350,2385,2408,2354);
