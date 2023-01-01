-- 
SET @NPC := 117750;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6540.331,`position_y`=1877.259,`position_z`=629.551 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6540.331, 1877.259, 629.551,0,0,0,100,0),
(@PATH,2,6540.283, 1859.994, 629.551,0,0,0,100,0),
(@PATH,3,6540.533, 1835.495, 629.551,0,0,0,100,0),
(@PATH,4,6540.854, 1803.997, 629.551,0,0,0,100,0),
(@PATH,5,6542.359, 1762.052, 629.551,0,0,0,100,0),
(@PATH,6,6543.607, 1716.575, 629.551,0,0,0,100,0),
(@PATH,7,6545.014, 1667.600, 629.551,0,0,0,100,0),
(@PATH,8,6543.607, 1716.575, 629.551,0,0,0,100,0),
(@PATH,9,6542.359, 1762.052, 629.551,0,0,0,100,0),
(@PATH,10,6540.854, 1803.997, 629.551,0,0,0,100,0),
(@PATH,11,6540.533, 1835.495, 629.551,0,0,0,100,0),
(@PATH,12,6540.283, 1859.994, 629.551,0,0,0,100,0),
(@PATH,13,6540.331, 1877.259, 629.551,0,0,0,100,0);

SET @NPC := 118162;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6553.124,`position_y`=1872.903,`position_z`=629.551 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6553.124, 1872.903, 629.551,0,0,0,100,0),
(@PATH,2,6554.411, 1844.666, 629.551,0,0,0,100,0),
(@PATH,3,6554.749, 1807.204, 629.551,0,0,0,100,0),
(@PATH,4,6555.443, 1768.718, 629.551,0,0,0,100,0),
(@PATH,5,6556.322, 1741.605, 629.551,0,0,0,100,0),
(@PATH,6,6557.329, 1702.747, 629.551,0,0,0,100,0),
(@PATH,7,6559.170, 1665.608, 629.551,0,0,0,100,0),
(@PATH,8,6557.329, 1702.747, 629.551,0,0,0,100,0),
(@PATH,9,6556.322, 1741.605, 629.551,0,0,0,100,0),
(@PATH,10,6555.443, 1768.718, 629.551,0,0,0,100,0),
(@PATH,11,6554.749, 1807.204, 629.551,0,0,0,100,0),
(@PATH,12,6554.411, 1844.666, 629.551,0,0,0,100,0),
(@PATH,13,6553.124, 1872.903, 629.551,0,0,0,100,0);

SET @NPC := 118174;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6552.371,`position_y`=1661.322,`position_z`=629.551 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 6552.371, 1661.322, 629.551,0,0,0,100,0),
(@PATH,2, 6551.883, 1687.767, 629.551,0,0,0,100,0),
(@PATH,3, 6551.104, 1715.581, 629.551,0,0,0,100,0),
(@PATH,4, 6550.197, 1742.424, 629.551,0,0,0,100,0),
(@PATH,5, 6549.316, 1784.414, 629.551,0,0,0,100,0),
(@PATH,6, 6548.214, 1821.399, 629.551,0,0,0,100,0),
(@PATH,7, 6546.878, 1869.975, 629.551,0,0,0,100,0),
(@PATH,8, 6548.214, 1821.399, 629.551,0,0,0,100,0),
(@PATH,9, 6549.316, 1784.414, 629.551,0,0,0,100,0),
(@PATH,10,6550.197, 1742.424, 629.551,0,0,0,100,0),
(@PATH,11,6551.104, 1715.581, 629.551,0,0,0,100,0),
(@PATH,12,6551.883, 1687.767, 629.551,0,0,0,100,0),
(@PATH,13,6552.371, 1661.322, 629.551,0,0,0,100,0);

SET @NPC := 118509;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6243.9291,`position_y`=1933.757,`position_z`=631.488 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 6243.9291, 1933.757, 631.488,0,0,0,100,0),
(@PATH,2, 6261.2890, 1935.936, 631.294,0,0,0,100,0),
(@PATH,3, 6282.0932, 1938.780, 631.299,0,0,0,100,0),
(@PATH,4, 6299.4321, 1941.150, 631.311,0,0,0,100,0),
(@PATH,5, 6327.7592, 1946.117, 631.769,0,0,0,100,0),
(@PATH,6, 6344.0156, 1948.286, 631.652,0,0,0,100,0),
(@PATH,7, 6327.7592, 1946.117, 631.769,0,0,0,100,0),
(@PATH,8, 6299.4321, 1941.150, 631.311,0,0,0,100,0),
(@PATH,9, 6282.0932, 1938.780, 631.299,0,0,0,100,0),
(@PATH,10,6261.2890, 1935.936, 631.294,0,0,0,100,0),
(@PATH,11,6243.9291, 1933.757, 631.488,0,0,0,100,0);

SET @NPC := 118510;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6448.0307,`position_y`=1963.665,`position_z`=631.467 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 6448.0307, 1963.665, 631.467,0,0,0,100,0),
(@PATH,2, 6433.8559, 1961.587, 631.294,0,0,0,100,0),
(@PATH,3, 6417.3081, 1959.175, 631.290,0,0,0,100,0),
(@PATH,4, 6406.9223, 1957.630, 631.290,0,0,0,100,0),
(@PATH,5, 6375.7651, 1952.996, 631.295,0,0,0,100,0),
(@PATH,6, 6351.5317, 1949.392, 631.651,0,0,0,100,0),
(@PATH,7, 6375.7651, 1952.996, 631.295,0,0,0,100,0),
(@PATH,8, 6406.9223, 1957.630, 631.290,0,0,0,100,0),
(@PATH,9, 6417.3081, 1959.175, 631.290,0,0,0,100,0),
(@PATH,10,6433.8559, 1961.587, 631.294,0,0,0,100,0),
(@PATH,11,6448.0307, 1963.665, 631.467,0,0,0,100,0);

SET @NPC := 117322;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6031.1064,`position_y`=1891.639,`position_z`=632.728 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1, 6031.1064, 1891.639, 632.728,0,0,0,100,0),
(@PATH,2, 6027.9648, 1900.913, 632.578,0,0,0,100,0),
(@PATH,3, 6026.6318, 1908.389, 632.578,0,0,0,100,0),
(@PATH,4, 6026.8745, 1917.646, 632.578,0,0,0,100,0),
(@PATH,5, 6028.2607, 1925.807, 632.578,0,0,0,100,0),
(@PATH,6, 6031.6225, 1932.734, 632.578,0,0,0,100,0),
(@PATH,7, 6036.9467, 1940.311, 632.578,0,0,0,100,0),
(@PATH,8, 6044.6274, 1946.779, 632.578,0,0,0,100,0),
(@PATH,9, 6054.3950, 1953.400, 632.578,0,0,0,100,0),
(@PATH,10, 6065.2382, 1956.441, 632.578,0,0,0,100,0),
(@PATH,11, 6075.9316, 1957.244, 632.578,0,0,0,100,0),
(@PATH,12, 6086.1391, 1955.381, 632.578,0,0,0,100,0),
(@PATH,13, 6094.7128, 1950.652, 632.578,0,0,0,100,0),
(@PATH,14, 6102.5820, 1944.056, 632.578,0,0,0,100,0),
(@PATH,15, 6094.7128, 1950.652, 632.578,0,0,0,100,0),
(@PATH,16, 6086.1391, 1955.381, 632.578,0,0,0,100,0),
(@PATH,17, 6075.9316, 1957.244, 632.578,0,0,0,100,0),
(@PATH,18, 6065.2382, 1956.441, 632.578,0,0,0,100,0),
(@PATH,19, 6054.3950, 1953.400, 632.578,0,0,0,100,0),
(@PATH,20, 6044.6274, 1946.779, 632.578,0,0,0,100,0),
(@PATH,21, 6036.9467, 1940.311, 632.578,0,0,0,100,0),
(@PATH,22, 6031.6225, 1932.734, 632.578,0,0,0,100,0),
(@PATH,23, 6028.2607, 1925.807, 632.578,0,0,0,100,0),
(@PATH,24, 6026.8745, 1917.646, 632.578,0,0,0,100,0),
(@PATH,25, 6026.6318, 1908.389, 632.578,0,0,0,100,0),
(@PATH,26, 6027.9648, 1900.913, 632.578,0,0,0,100,0),
(@PATH,27, 6031.1064, 1891.639, 632.728,0,0,0,100,0);

SET @NPC := 118448;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6074.5600,`position_y`=1938.180,`position_z`=632.578 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6074.5600, 1938.180, 632.578,0,0,0,100,0),
(@PATH,2,6080.9282, 1926.485, 632.578,0,0,0,100,0),
(@PATH,3,6086.5986, 1910.617, 632.656,0,0,0,100,0),
(@PATH,4,6080.9282, 1926.485, 632.578,0,0,0,100,0),
(@PATH,5,6080.9282, 1926.485, 632.578,0,0,0,100,0);

SET @NPC := 118434;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6406.2749,`position_y`=1718.5131,`position_z`=508.602 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6406.2749, 1718.5131, 508.602,0,0,0,100,0),
(@PATH,2,6409.1572, 1730.0246, 508.600,0,0,0,100,0),
(@PATH,3,6415.0971, 1737.3723, 508.600,0,0,0,100,0),
(@PATH,4,6429.7802, 1739.8724, 508.600,0,0,0,100,0),
(@PATH,5,6440.0083, 1735.0406, 508.600,0,0,0,100,0),
(@PATH,6,6429.7802, 1739.8724, 508.600,0,0,0,100,0),
(@PATH,7,6415.0971, 1737.3723, 508.600,0,0,0,100,0),
(@PATH,8,6409.1572, 1730.0246, 508.600,0,0,0,100,0),
(@PATH,9,6406.2749, 1718.5131, 508.602,0,0,0,100,0);

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=118270;

SET @NPC := 124270;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=6278.0361,`position_y`=1841.138,`position_z`=521.659 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (@NPC,@PATH,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6278.0361, 1841.138, 521.659,0,0,0,100,0),
(@PATH,2,6299.3081, 1841.890, 509.418,0,0,0,100,0),
(@PATH,3,6313.1914, 1832.766, 508.601,0,0,0,100,0),
(@PATH,4,6323.3486, 1828.048, 509.711,0,0,0,100,0),
(@PATH,5,6334.1923, 1822.355, 508.600,0,0,0,100,0),
(@PATH,6,6323.3486, 1828.048, 509.711,0,0,0,100,0),
(@PATH,7,6313.1914, 1832.766, 508.601,0,0,0,100,0),
(@PATH,8,6299.3081, 1841.890, 509.418,0,0,0,100,0),
(@PATH,9,6278.0361, 1841.138, 521.659,0,0,0,100,0);
