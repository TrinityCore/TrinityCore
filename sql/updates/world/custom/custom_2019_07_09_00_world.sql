UPDATE `creature` SET `spawndist`= 10, `MovementType`= 1 WHERE `id` IN (46508, 46569, 46605, 47182);
UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `id` IN (46507, 46630, 446989, 47657);
UPDATE `creature` SET `spawndist`= 2, `MovementType`= 1 WHERE `id`= 46509;

-- Pathing for  Entry: 46597 'TDB FORMAT' 
SET @NPC := 291134;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -432.307, `position_y`= 1878.55, `position_z`= 46.57799 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -432.307, 1878.55, 46.57799, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -424.212, 1854.49, 46.5528, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -423.806, 1834.49, 46.5528, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -432.858, 1822.56, 46.50397, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -451.028, 1811.49, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -474.845, 1808.78, 46.6778, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -502.033, 1806.61, 48.09459, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -516.01, 1805.14, 49.70116, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -538.149, 1801.64, 52.30355, 0, 293, 0, 0, 100, 0),
(@PATH, 10, -516.01, 1805.14, 49.70116, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -502.033, 1806.61, 48.09459, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -474.845, 1808.78, 46.6778, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -451.028, 1811.49, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -432.858, 1822.56, 46.50397, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -423.806, 1834.49, 46.5528, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -424.212, 1854.49, 46.5528, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -432.307, 1878.55, 46.57799, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -446.361, 1895.53, 46.93295, 0, 270, 0, 0, 100, 0);
-- 0x2016FC5B802D8140003C430000166C93 .go xyz -432.307 1878.55 46.57799

UPDATE `creature` SET `position_x`= -432.307, `position_y`= 1878.55, `position_z`= 46.57799 WHERE `guid`= 291133;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 291134;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(291134, 291134, 0, 0, 515, 0, 0),
(291134, 291133, 2, 90, 515, 0, 0);


-- Pathing for  Entry: 46597 'TDB FORMAT' 
SET @NPC := 291109;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -518.523, `position_y`= 1710.23, `position_z`= 49.82735 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -518.523, 1710.23, 49.82735, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -532.674, 1689.7, 49.23832, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -552.545, 1673.77, 49.28449, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -571.596, 1666.55, 49.79349, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -594.29, 1665.36, 49.61783, 0, 318, 0, 0, 100, 0),
(@PATH, 6, -571.596, 1666.55, 49.79349, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -552.545, 1673.77, 49.28449, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -532.674, 1689.7, 49.23832, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -518.523, 1710.23, 49.82735, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -514.628, 1730.98, 49.77023, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -515.847, 1756.91, 50.10582, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -524.214, 1776.58, 51.07809, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -547.639, 1798.79, 53.01313, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -578.292, 1810.6, 53.85814, 0, 187, 0, 0, 100, 0),
(@PATH, 15, -547.639, 1798.79, 53.01313, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -524.214, 1776.58, 51.07809, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -515.847, 1756.91, 50.10582, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -514.628, 1730.98, 49.77023, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D8140003C43000016A860 .go xyz -518.523 1710.23 49.82735

UPDATE `creature` SET `position_x`= -432.307, `position_y`= 1878.55, `position_z`= 46.57799 WHERE `guid`= 291108;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 291109;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(291109, 291109, 0, 0, 515, 0, 0),
(291109, 291108, 2, 90, 515, 0, 0);

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291163;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -527.814, `position_y`= 1654.7, `position_z`= 47.3966 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -527.814, 1654.7, 47.3966, 0, 25563, 0, 0, 100, 0),
(@PATH, 2, -526.405, 1645.78, 45.9755, 0, 24359, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C4300001611FE .go xyz -527.814 1654.7 47.3966

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291135;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -510.563, `position_y`= 1924.17, `position_z`= 47.17791 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -510.563, 1924.17, 47.17791, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -519.184, 1934.13, 48.77297, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -531.293, 1950.048, 48.94155, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -549.908, 1949.97, 48.74329, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -558.385, 1943.07, 48.81873, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -560.536, 1927.36, 49.05378, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -559.307, 1917.48, 48.26716, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -559.358, 1909.1, 47.23811, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -566.429, 1899.76, 47.21198, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -579.293, 1887.44, 47.41489, 0, 275, 0, 0, 100, 0),
(@PATH, 11, -566.429, 1899.76, 47.21198, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -559.358, 1909.1, 47.23811, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -559.307, 1917.48, 48.26716, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -560.536, 1927.36, 49.05378, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -558.385, 1943.07, 48.81873, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -549.908, 1949.97, 48.74329, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -531.293, 1950.048, 48.94155, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -519.184, 1934.13, 48.77297, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C4300001611FF .go xyz -510.563 1924.17 47.17791


-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291115;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -506.384, `position_y`= 1753.58, `position_z`= 48.67394 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -506.384, 1753.58, 48.67394, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -513.833, 1743.63, 49.86437, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -514.255, 1726.48, 49.85055, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -534.976, 1724.12, 52.53273, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -552.007, 1715.76, 56.62013, 0, 358, 0, 0, 100, 0),
(@PATH, 6, -534.976, 1724.12, 52.53273, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -514.255, 1726.48, 49.85055, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -513.833, 1743.63, 49.86437, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -506.384, 1753.58, 48.67394, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -494.236, 1754.93, 47.13978, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -467.2891, 1756.459, 45.64393, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -446.896, 1758.67, 41.48767, 0, 76, 0, 0, 100, 0),
(@PATH, 13, -467.2891, 1756.459, 45.64393, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -494.236, 1754.93, 47.13978, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430000166C43 .go xyz -506.384 1753.58 48.67394

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291143;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -511.46, `position_y`= 1772.13, `position_z`= 48.73532 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -511.46, 1772.13, 48.73532, 0, 368, 0, 0, 100, 0),
(@PATH, 2, -522.8, 1789.08, 51.10775, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -520.4805, 1810.951, 49.7882, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -528.089, 1820.59, 48.12157, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -538.729, 1825.33, 48.59921, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -554.936, 1822.4, 50.83151, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -567.769, 1817.39, 52.75438, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -584.253, 1819.66, 52.76463, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -599.679, 1823.65, 51.68077, 0, 288, 0, 0, 100, 0),
(@PATH, 10, -584.253, 1819.66, 52.76463, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -567.769, 1817.39, 52.75438, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -554.936, 1822.4, 50.83151, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -538.729, 1825.33, 48.59921, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -528.089, 1820.59, 48.12157, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -520.493, 1811.01, 49.79235, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -522.8, 1789.08, 51.10775, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430000166CC6 .go xyz -511.46 1772.13 48.73532

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291121;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -445.969, `position_y`= 1864.02, `position_z`= 47.46938 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -445.969, 1864.02, 47.46938, 0, 85, 0, 0, 100, 0),
(@PATH, 2, -443.929, 1852.41, 46.8854, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -437.637, 1848.34, 47.50381, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -436.219, 1838.82, 47.24844, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -437.781, 1835.33, 47.31557, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -443.045, 1834.02, 47.34438, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -452.578, 1834.77, 46.95742, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -463.163, 1834.02, 46.46938, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -465.274, 1829.28, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -465.938, 1823.6, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -471.335, 1819.19, 46.67561, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -480.191, 1817.76, 46.8028, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -494.951, 1816.19, 47.67255, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -501.833, 1819.93, 47.32067, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -503.024, 1825.74, 46.9132, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -510.233, 1826.88, 46.50011, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -520.523, 1827.84, 46.93859, 0, 103, 0, 0, 100, 0),
(@PATH, 18, -510.233, 1826.88, 46.50011, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -503.024, 1825.74, 46.9132, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -501.833, 1819.93, 47.32067, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -494.951, 1816.19, 47.67255, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -480.191, 1817.76, 46.8028, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -471.335, 1819.19, 46.67561, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -465.938, 1823.6, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -465.274, 1829.28, 46.44185, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -463.163, 1834.02, 46.46938, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -452.578, 1834.77, 46.95742, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -443.045, 1834.02, 47.34438, 0, 0, 0, 0, 100, 0),
(@PATH, 29, -437.781, 1835.33, 47.31557, 0, 0, 0, 0, 100, 0),
(@PATH, 30, -436.219, 1838.82, 47.24844, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -437.637, 1848.34, 47.50381, 0, 0, 0, 0, 100, 0),
(@PATH, 32, -443.929, 1852.41, 46.8854, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430000169221 .go xyz -445.969 1864.02 47.46938


-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291158;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -632.151, `position_y`= 1648.88, `position_z`= 47.38609 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -632.151, 1648.88, 47.38609, 0, 245, 0, 0, 100, 0),
(@PATH, 2, -642.931, 1654.93, 47.37844, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -652.233, 1662.75, 47.90628, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -652.335, 1670.94, 48.63116, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -657.148, 1678.91, 48.38555, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -661.542, 1687.02, 48.48833, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -667.462, 1685.63, 47.58488, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -675.51, 1719.13, 48.61787, 0, 149, 0, 0, 100, 0),
(@PATH, 9, -667.462, 1685.63, 47.58488, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -661.627, 1687.001, 48.43096, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -657.148, 1678.91, 48.38555, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -652.335, 1670.94, 48.63116, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -652.233, 1662.75, 47.90628, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -642.931, 1654.93, 47.37844, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430000169CC3 .go xyz -632.151 1648.88 47.38609

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291151;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -619.856, `position_y`= 1755.32, `position_z`= 67.22987 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -619.856, 1755.32, 67.22987, 0, 293, 0, 0, 100, 0),
(@PATH, 2, -630.556, 1750.84, 64.20302, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -640.007, 1753.16, 57.75431, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -644.637, 1749.06, 54.93034, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -648.661, 1737.73, 51.0446, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -647.594, 1726.76, 51.72429, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -642.24, 1726.94, 54.66227, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -638.635, 1713.37, 55.0341, 0, 120, 0, 0, 100, 0),
(@PATH, 9, -642.24, 1726.94, 54.66227, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -647.594, 1726.76, 51.72429, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -648.661, 1737.73, 51.0446, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -644.6523, 1749.039, 55.06901, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -640.007, 1753.16, 57.75431, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -641.6602, 1751.695, 57.19401, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430000169D88 .go xyz -619.856 1755.32 67.22987

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291155;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -575.745, `position_y`= 1583.2, `position_z`= 47.35447 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -575.745, 1583.2, 47.35447, 0, 91, 0, 0, 100, 0),
(@PATH, 2, -584.533, 1593.54, 48.71079, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -591.377, 1620.83, 48.08953, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -596.971, 1649.24, 48.87003, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -584.097, 1672.19, 51.12768, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -584.057, 1684.45, 54.76684, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -576.398, 1697.97, 58.64087, 0, 117, 0, 0, 100, 0),
(@PATH, 8, -584.057, 1684.45, 54.76684, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -584.097, 1672.19, 51.12768, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -596.971, 1649.24, 48.87003, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -591.377, 1620.83, 48.08953, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -584.533, 1593.54, 48.71079, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C43000016A89E .go xyz -575.745 1583.2 47.35447

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291125;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -463.219, `position_y`= 1944.21, `position_z`= 49.87934 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -463.219, 1944.21, 49.87934, 0, 351, 0, 0, 100, 0),
(@PATH, 2, -451.125, 1949.59, 50.79353, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -437.901, 1943.29, 51.23994, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -422.644, 1934.32, 50.95979, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -427.514, 1916.63, 49.43731, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -432.22, 1906.59, 49.10089, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -427.583, 1898.54, 48.21776, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -415.002, 1890.89, 48.5902, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -407.266, 1879.67, 50.32592, 0, 116, 0, 0, 100, 0),
(@PATH, 10, -415.002, 1890.89, 48.5902, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -427.583, 1898.54, 48.21776, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -432.22, 1906.59, 49.10089, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -427.514, 1916.63, 49.43731, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -422.644, 1934.32, 50.95979, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -437.901, 1943.29, 51.23994, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -451.125, 1949.59, 50.79353, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C4300011611FF .go xyz -463.219 1944.21 49.87934

-- Pathing for  Entry: 46586 'TDB FORMAT' 
SET @NPC := 291144;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -561.318, `position_y`= 1775.09, `position_z`= 66.34772 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -561.318, 1775.09, 66.34772, 0, 32, 0, 0, 100, 0),
(@PATH, 2, -567.642, 1784.5, 65.15083, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -571.927, 1793.26, 60.54475, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -578.523, 1797.59, 58.42281, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -585.403, 1799.31, 57.53035, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -597.936, 1798.75, 57.74165, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -608.778, 1794.51, 59.36853, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -614.325, 1789.69, 61.48852, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -617.823, 1780.19, 64.1698, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -619.778, 1768.89, 66.92688, 0, 362, 0, 0, 100, 0),
(@PATH, 11, -617.823, 1780.19, 64.1698, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -614.325, 1789.69, 61.48852, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -608.778, 1794.51, 59.36853, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -597.936, 1798.75, 57.74165, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -585.403, 1799.31, 57.53035, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -578.523, 1797.59, 58.42281, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -571.927, 1793.26, 60.54475, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -567.642, 1784.5, 65.15083, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D7E80003C430001161200 .go xyz -561.318 1775.09 66.34772

-- Pathing for  Entry: 46597 'TDB FORMAT' 
SET @NPC := 291132;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -556.359, `position_y`= 1672.88, `position_z`= 49.41657 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -556.359, 1672.88, 49.41657, 0, 196, 0, 0, 100, 0),
(@PATH, 2, -596.438, 1665.56, 49.67484, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -631.731, 1681.9, 48.74969, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -657.835, 1741.23, 50.06901, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -653.134, 1772.32, 51.88462, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -634.451, 1797.44, 53.76865, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -599.863, 1812.2, 54.10814, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -582.906, 1811.03, 54.11937, 0, 50, 0, 0, 100, 0),
(@PATH, 9, -599.863, 1812.2, 54.10814, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -634.451, 1797.44, 53.76865, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -653.134, 1772.32, 51.88462, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -657.835, 1741.23, 50.06901, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -631.731, 1681.9, 48.74969, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -596.438, 1665.56, 49.67484, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D8140003C430000169CC3 .go xyz -556.359 1672.88 49.41657

UPDATE `creature` SET `position_x`= -556.359, `position_y`= 1672.88, `position_z`= 49.41657 WHERE `guid`= 291131;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 291132;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(291132, 291132, 0, 0, 515, 0, 0),
(291132, 291131, 2, 90, 515, 0, 0);

-- Pathing for  Entry: 46630 'TDB FORMAT' 
SET @NPC := 291294;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -197.691, `position_y`= 1878.81, `position_z`= 2.387666 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -197.691, 1878.81, 2.387666, 0, 281, 0, 0, 100, 0),
(@PATH, 2, -205.474, 1882.64, 2.507594, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -231.005, 1887.03, 12.75759, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -233.842, 1888.82, 12.75613, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -234.097, 1896.09, 12.7576, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -237.283, 1902.72, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -239.023, 1913.8, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -245.733, 1929.6, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -240.082, 1942.8, 12.72665, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -228.049, 1947.8, 12.46952, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -219.894, 1947.64, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -213.438, 1949.86, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -209.741, 1974.99, 13.37646, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -209.988, 2013.15, 6.945767, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -209.741, 1974.99, 13.37646, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -213.438, 1949.86, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -219.894, 1947.64, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -228.049, 1947.8, 12.46952, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -240.082, 1942.8, 12.72665, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -245.733, 1929.6, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -239.023, 1913.8, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -237.283, 1902.72, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -234.097, 1896.09, 12.7576, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -233.842, 1888.82, 12.75613, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -231.005, 1887.03, 12.75759, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -205.474, 1882.64, 2.507594, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D8980003C430000166F23 .go xyz -197.691 1878.81 2.387666

-- Pathing for  Entry: 46630 'TDB FORMAT' 
SET @NPC := 291308;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -209.024, `position_y`= 1899.69, `position_z`= 2.507594 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -209.024, 1899.69, 2.507594, 0, 22, 0, 0, 100, 0),
(@PATH, 2, -209.203, 1912.39, 2.454234, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -208.634, 1933.88, 12.92856, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -209.585, 1939.17, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -214.953, 1944.55, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -227.151, 1945, 12.59452, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -237.891, 1940.54, 12.72665, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -243.069, 1929.36, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -236.804, 1915.63, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -234.642, 1903.13, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -231.401, 1891.09, 12.75759, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -237.106, 1872.23, 12.7576, 0, 68, 0, 0, 100, 0),
(@PATH, 13, -231.401, 1891.09, 12.75759, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -234.642, 1903.13, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -236.804, 1915.63, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -243.069, 1929.36, 12.681, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -237.891, 1940.54, 12.72665, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -227.151, 1945, 12.59452, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -214.953, 1944.55, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -209.585, 1939.17, 12.71952, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -208.634, 1933.88, 12.92856, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -209.203, 1912.39, 2.454234, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D8980003C4300001681BA .go xyz -209.024 1899.69 2.507594

-- Pathing for  Entry: 46630 'TDB FORMAT' 
SET @NPC := 291295;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -135.563, `position_y`= 1859.13, `position_z`= 2.718268 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -135.563, 1859.13, 2.718268, 0, 79, 0, 0, 100, 0),
(@PATH, 2, -140.127, 1871.11, 2.77913, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -139.191, 1879.78, 2.752518, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -136.578, 1883.21, 2.752518, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -115.642, 1882.92, 13.53632, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -105.448, 1883, 13.65793, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -93.6944, 1893, 13.47695, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -85.9601, 1899.81, 13.35195, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -80.6684, 1900.52, 13.09463, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -73.842, 1901.68, 13.31741, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -65.3281, 1908.23, 13.4998, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -53.5347, 1909.78, 13.4998, 0, 5050, 0, 0, 100, 0),
(@PATH, 13, -73.842, 1901.68, 13.31741, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -80.6684, 1900.52, 13.09463, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -85.9601, 1899.81, 13.35195, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -93.6944, 1893, 13.47695, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -105.448, 1883, 13.65793, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -115.642, 1882.92, 13.53632, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -136.578, 1883.21, 2.752518, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -139.191, 1879.78, 2.752518, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -140.127, 1871.11, 2.77913, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802D8980003C43000016ABD1 .go xyz -135.563 1859.13 2.718268

-- Pathing for  Entry: 46641 'TDB FORMAT' 
SET @NPC := 291315;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -193.5799, `position_y`= 1924.366, `position_z`= 2.85798 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -193.5799, 1924.366, 2.85798, 0, 2963, 0, 0, 100, 0),
(@PATH, 2, -206.583, 1897.67, 2.3826, 0, 402, 0, 0, 100, 0),
(@PATH, 3, -206.583, 1897.67, 2.3826, 4.18879, 3250, 0, 0, 100, 0);
-- 0x2016FC5B802D8C40003C430000168184 .go xyz -193.5799 1924.366 2.85798

-- Pathing for  Entry: 46641 'TDB FORMAT' 
SET @NPC := 291300;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -115.406, `position_y`= 1909.93, `position_z`= 2.3826 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -115.406, 1909.93, 2.3826, 0, 2199, 0, 0, 100, 0),
(@PATH, 2, -116.677, 1930.69, 2.3826, 0, 349, 0, 0, 100, 0),
(@PATH, 3, -116.677, 1930.69, 2.3826, 0.3839724, 2031, 0, 0, 100, 0);
-- 0x2016FC5B802D8C40003C43000016A229 .go xyz -115.406 1909.93 2.3826

-- Pathing for  Entry: 46641 'TDB FORMAT' 
SET @NPC := 291318;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -207.531, `position_y`= 1870.97, `position_z`= 2.38259 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -207.531, 1870.97, 2.38259, 0, 3121, 0, 0, 100, 0),
(@PATH, 2, -135.0642, 1857.872, 2.591071, 0, 2236, 0, 0, 100, 0);
-- 0x2016FC5B802D8C40003C43000016AC14 .go xyz -207.531 1870.97 2.38259

-- Pathing for  Entry: 46643 'TDB FORMAT' 
SET @NPC := 291305;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -133.293, `position_y`= 1928.82, `position_z`= 3.106574 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -133.293, 1928.82, 3.106574, 2.879793, 32813, 0, 0, 100, 0),
(@PATH, 2, -140.781, 1903.53, 2.3826, 0, 225, 0, 0, 100, 0),
(@PATH, 3, -140.781, 1903.53, 2.3826, 4.276057, 56078, 0, 0, 100, 0),
(@PATH, 4, -133.293, 1928.82, 3.106574, 0, 361, 0, 0, 100, 0);
-- 0x2016FC5B802D8CC0003C43000016A267 .go xyz -133.293 1928.82 3.106574

-- Pathing for  Entry: 46643 'TDB FORMAT' 
SET @NPC := 291312;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -169.441, `position_y`= 1884.25, `position_z`= 2.42477 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -169.441, 1884.25, 2.42477, 3.612832, 0, 0, 0, 100, 0),
(@PATH, 2, -156.811, 1881.25, 3.257401, 0, 201, 0, 0, 100, 0),
(@PATH, 3, -156.811, 1881.25, 3.257401, 2.129302, 86140, 0, 0, 100, 0),
(@PATH, 4, -169.441, 1884.25, 2.42477, 0, 159, 0, 0, 100, 0);
-- 0x2016FC5B802D8CC0003C43000016A2A3 .go xyz -169.441 1884.25 2.42477

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291402;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -74.4878, `position_y`= 1625.83, `position_z`= 25.69848 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -74.4878, 1625.83, 25.69848, 0, 19, 0, 0, 100, 0),
(@PATH, 2, -45.7552, 1622.89, 27.21007, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -27.7674, 1624.33, 27.09699, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -11.5243, 1628.42, 27.26521, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -4.73611, 1631.28, 27.09699, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 2.43576, 1637.69, 27.07699, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 12.0087, 1646.48, 27.13192, 0, 300, 0, 0, 100, 0),
(@PATH, 8, 2.43576, 1637.69, 27.07699, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -4.73611, 1631.28, 27.09699, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -11.5243, 1628.42, 27.26521, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -27.7674, 1624.33, 27.09699, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -45.7552, 1622.89, 27.21007, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C430000162556 .go xyz -74.4878 1625.83 25.69848

DELETE FROM `creature` WHERE `guid`= 252434;
DELETE FROM `creature_addon` WHERE `guid`= 252434;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(252434, 46989, 732, 5389, 5539, 1, 169, 0, 0, 0, -34.45447, 1682.912, 34.91486, 3.910952, 120, 10, 0, 0, 0, 1, 0, 0, 0, 30948); -- 46989 (Area: 5539 - Difficulty: 0) (Auras: 81219 - 81219) (possible waypoints or random movement)

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 252434;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -112.3837, `position_y`= 1608.026, `position_z`= 20.93827 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -112.3837, 1608.026, 20.93827, 0, 125, 0, 0, 100, 0),
(@PATH, 2, -97.05903, 1618.705, 23.42113, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -86.1944, 1625.49, 24.91747, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -74.7344, 1634.71, 25.63339, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -67.342, 1643.84, 26.33163, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -62.1337, 1651.88, 26.71007, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -56.0972, 1660.79, 27.06737, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -48.625, 1669.24, 27.38764, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -29.8559, 1687.35, 35.16945, 0, 209, 0, 0, 100, 0),
(@PATH, 10, -48.625, 1669.24, 27.38764, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -56.0972, 1660.79, 27.06737, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -62.1337, 1651.88, 26.71007, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -67.342, 1643.84, 26.33163, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -74.7344, 1634.71, 25.63339, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -86.1944, 1625.49, 24.91747, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -97.05903, 1618.705, 23.42113, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300001691C3 .go xyz -112.3837 1608.026 20.93827

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291372;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 61.6267, `position_y`= 1725.3, `position_z`= 45.5695 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 61.6267, 1725.3, 45.5695, 0, 233, 0, 0, 100, 0),
(@PATH, 2, 53.7587, 1718.76, 45.57327, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 39.2153, 1705.36, 37.91397, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 35, 1703.6, 37.44353, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 33.5399, 1705.61, 37.44574, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 35.5903, 1710.65, 37.45058, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 42.3819, 1718.56, 37.44552, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 48.6146, 1724.68, 37.43624, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 51.4878, 1729.76, 37.43892, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 45.67454, 1737.664, 37.43991, 0, 314, 0, 0, 100, 0),
(@PATH, 11, 51.4878, 1729.76, 37.43892, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 48.6146, 1724.68, 37.43624, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 42.3819, 1718.56, 37.44552, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 35.5903, 1710.65, 37.45058, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 33.5399, 1705.61, 37.44574, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 35, 1703.6, 37.44353, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 39.2153, 1705.36, 37.91397, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 53.7587, 1718.76, 45.57327, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300001692A3 .go xyz 61.6267 1725.3 45.5695

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291395;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -23.6701, `position_y`= 1691.16, `position_z`= 35.00612 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -23.6701, 1691.16, 35.00612, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -12.8663, 1699.89, 35.00612, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 7.09201, 1717.53, 37.46117, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 17.3385, 1727.93, 36.42525, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 7.09201, 1717.53, 37.46117, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -12.8663, 1699.89, 35.00612, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300001696C3 .go xyz -23.6701 1691.16 35.00612

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291357;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -11.8594, `position_y`= 1735.56, `position_z`= 58.51897 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -11.8594, 1735.56, 58.51897, 0, 331, 0, 0, 100, 0),
(@PATH, 2, 14.8872, 1759.1, 58.51928, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 23.8438, 1764.43, 58.51914, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 32.0955, 1758.3, 58.52008, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 42.2049, 1757.77, 58.51899, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 47.0694, 1752.72, 58.51874, 0, 184, 0, 0, 100, 0),
(@PATH, 7, 42.2049, 1757.77, 58.51899, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 32.0955, 1758.3, 58.52008, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 23.8438, 1764.43, 58.51914, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 14.8872, 1759.1, 58.51928, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300009611FF .go xyz -11.8594 1735.56 58.51897

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291396;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -83.06424, `position_y`= 1742.663, `position_z`= 28.93508 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -83.06424, 1742.663, 28.93508, 0, 292, 0, 0, 100, 0),
(@PATH, 2, -90.6892, 1727.56, 27.05898, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -95.625, 1712.37, 27.12929, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -97.2014, 1698.18, 27.30846, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -95.5191, 1683.14, 26.80846, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -92.2708, 1675.91, 26.68346, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -86.816, 1661.44, 26.63339, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -82.3663, 1647.66, 26.38339, 0, 217, 0, 0, 100, 0),
(@PATH, 9, -86.816, 1661.44, 26.63339, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -92.2708, 1675.91, 26.68346, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -95.5191, 1683.14, 26.80846, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -97.2014, 1698.18, 27.30846, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -95.625, 1712.37, 27.12929, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -90.6892, 1727.56, 27.05898, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300011611FE .go xyz -83.06424 1742.663 28.93508

-- Pathing for  Entry: 46989 'TDB FORMAT' 
SET @NPC := 291371;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 47.1806, `position_y`= 1752.3, `position_z`= 58.51886 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 47.1806, 1752.3, 58.51886, 0, 55, 0, 0, 100, 0),
(@PATH, 2, 52.5278, 1744.64, 58.51919, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 50.8507, 1734.55, 58.51938, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 57.3038, 1725.82, 58.51858, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 21.6927, 1696.04, 58.51942, 0, 92, 0, 0, 100, 0),
(@PATH, 6, 57.3038, 1725.82, 58.51858, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 50.8507, 1734.55, 58.51938, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 52.5278, 1744.64, 58.51919, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802DE340003C4300019611FE .go xyz 47.1806 1752.3 58.51886

-- Pathing for  Entry: 47287 'TDB FORMAT' 
SET @NPC := 291603;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 281.476, `position_y`= 1517.05, `position_z`= 3.340633 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 281.476, 1517.05, 3.340633, 0, 213, 0, 0, 100, 0),
(@PATH, 2, 276.477, 1519.79, 3.310882, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 273.981, 1523.42, 2.952342, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 272.641, 1527.12, 2.715258, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 270.615, 1530.6, 2.475533, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 266.665, 1534.48, 2.173009, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 262.656, 1538.36, 1.916586, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 265.602, 1536, 2.003402, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 270.962, 1532.51, 2.055044, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 275.969, 1531.59, 1.55694, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 281.495, 1532.36, 0.8890591, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 286.273, 1531.79, 0.6701895, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 292.108, 1527.75, 1.092078, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 293.484, 1523.97, 1.53198, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 292.819, 1519.05, 2.310554, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 293.484, 1523.97, 1.53198, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 292.108, 1527.75, 1.092078, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 286.273, 1531.79, 0.6701895, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 281.495, 1532.36, 0.8890591, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 275.969, 1531.59, 1.55694, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 270.962, 1532.51, 2.055044, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 265.602, 1536, 2.003402, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 262.656, 1538.36, 1.916586, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 266.665, 1534.48, 2.173009, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 270.615, 1530.6, 2.475533, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 272.641, 1527.12, 2.715258, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 273.981, 1523.42, 2.952342, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 276.477, 1519.79, 3.310882, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E2DC0003C43000016AAB5 .go xyz 281.476 1517.05 3.340633

-- Pathing for  Entry: 47627 'TDB FORMAT' 
SET @NPC := 291598;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 68.2691, `position_y`= 1210.83, `position_z`= 3.740685 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '10022 77806');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 68.2691, 1210.83, 3.740685, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 65.7326, 1221.05, 3.774713, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 64.033, 1243.77, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 56.5017, 1249.3, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 46.9497, 1253.29, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 34.3299, 1256.62, 15.14971, 0, 392, 0, 0, 100, 0),
(@PATH, 7, 46.9497, 1253.29, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 56.5017, 1249.3, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 64.033, 1243.77, 15.14971, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 65.7326, 1221.05, 3.774713, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 68.2691, 1210.83, 3.740685, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 64.809, 1202.53, 3.774713, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 57.7743, 1196.55, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 58.9306, 1190.03, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 64.7396, 1177.56, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 62.1024, 1169.85, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 52.8559, 1165.06, 3.836599, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 37.6753, 1161.91, 4.951602, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 13.8229, 1161.6, 15.18124, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -3.90972, 1160.16, 15.17712, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -15.4375, 1160.77, 15.17712, 0, 93, 0, 0, 100, 0),
(@PATH, 22, -3.90972, 1160.16, 15.17712, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 13.8229, 1161.6, 15.18124, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 37.6753, 1161.91, 4.951602, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 52.8559, 1165.06, 3.836599, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 62.1024, 1169.85, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 64.7396, 1177.56, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 58.9306, 1190.03, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 57.7743, 1196.55, 3.858737, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 64.809, 1202.53, 3.774713, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E82C0003C4300001695E5 .go xyz 68.2691 1210.83 3.740685

-- Pathing for  Entry: 47181 'TDB FORMAT' 
SET @NPC := 291654;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -267.931, `position_y`= 952.361, `position_z`= 49.02018 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -267.931, 952.361, 49.02018, 0, 324, 0, 0, 100, 0),
(@PATH, 2, -270.351, 940.764, 49.02018, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -267.241, 927.887, 49.03061, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -261.247, 915.767, 51.44914, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -253.825, 909.168, 55.27702, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -241.592, 904.8, 58.71672, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -224.8574, 901.7451, 62.64518, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -207.387, 904.276, 66.79655, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -190.941, 912.267, 70.49189, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -173.839, 928.655, 73.06916, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -160.668, 948.7178, 78.00007, 0, 364, 0, 0, 100, 0),
(@PATH, 12, -173.8398, 928.6553, 72.94306, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -190.941, 912.267, 70.49189, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -207.387, 904.276, 66.79655, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -224.866, 901.745, 62.55241, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -241.592, 904.8, 58.71672, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -253.825, 909.168, 55.27702, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -261.247, 915.767, 51.44914, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -267.241, 927.887, 49.03061, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -270.351, 940.764, 49.02018, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E1340003C4300001681B7 .go xyz -267.931 952.361 49.02018

-- Pathing for  Entry: 47181 'TDB FORMAT' 
SET @NPC := 291674;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -152.467, `position_y`= 1040.89, `position_z`= 24.06372 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -152.467, 1040.89, 24.06372, 0, 113, 0, 0, 100, 0),
(@PATH, 2, -159.837, 1032.83, 26.73275, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -167.2734, 1027.759, 29.87608, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -176.47, 1024.32, 33.11216, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -187.488, 1021.29, 36.20249, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -199.738, 1015.15, 40.43259, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -208.33, 1005.49, 43.11534, 0, 281, 0, 0, 100, 0),
(@PATH, 8, -199.738, 1015.15, 40.43259, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -187.488, 1021.29, 36.20249, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -176.47, 1024.32, 33.11216, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -167.299, 1027.74, 29.87022, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -159.8633, 1032.812, 26.75057, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E1340003C43000016A11D .go xyz -152.467 1040.89 24.06372

-- Pathing for  Entry: 47181 'TDB FORMAT' 
SET @NPC := 291669;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -209.677, `position_y`= 1001.88, `position_z`= 43.80931 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '33900');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -209.677, 1001.88, 43.80931, 0, 67, 0, 0, 100, 0),
(@PATH, 2, -212.785, 990.922, 46.59952, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -215.825, 980.094, 48.52542, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -223.097, 968.073, 48.94913, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -234.227, 962.507, 48.97738, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -246.8, 959.516, 49.02303, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -259.358, 959.49, 48.97738, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -271.748, 959.974, 49.02018, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -283.816, 957.372, 49.02018, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -301.444, 951.788, 50.88474, 0, 10, 0, 0, 100, 0),
(@PATH, 11, -283.816, 957.372, 49.02018, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -271.748, 959.974, 49.02018, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -259.358, 959.49, 48.97738, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -246.8, 959.516, 49.02303, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -234.227, 962.507, 48.97738, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -223.097, 968.073, 48.94913, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -215.825, 980.094, 48.52542, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -212.785, 990.922, 46.59952, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E1340003C43000016A13A .go xyz -209.677 1001.88 43.80931

-- Pathing for  Entry: 48252 'TDB FORMAT' 
SET @NPC := 291430;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -325.0556, `position_y`= 1046.905, `position_z`= 22.14745 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -325.0556, 1046.905, 22.14745, 6.143559, 32906, 0, 0, 100, 0),
(@PATH, 2, -329.2535, 1048.979, 22.07445, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -330.0382, 1052.233, 21.98021, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -329.7396, 1055.45, 22.17467, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -330.5885, 1061.323, 22.03929, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -331.9271, 1064.12, 21.89745, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -331.5764, 1066.754, 21.93965, 0, 122, 0, 0, 100, 0),
(@PATH, 8, -331.2135, 1067.708, 21.98311, 0, 12, 0, 0, 100, 0),
(@PATH, 9, -331.2162, 1067.701, 21.98262, 0.715585, 35375, 0, 0, 100, 0),
(@PATH, 10, -330.6129, 1060.071, 22.02245, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -329.8889, 1056.663, 22.01122, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -330.0885, 1052.682, 21.97435, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -328.9063, 1048.701, 21.9912, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -325.0556, 1046.905, 22.14745, 0, 1528, 0, 0, 100, 0);
-- 0x2016FC5B802F1F00003C430000961200 .go xyz -325.0556 1046.905 22.14745


-- Pathing for  Entry: 48252 'TDB FORMAT' 
SET @NPC := 291445;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -396.309, `position_y`= 1087.964, `position_z`= 28.10337 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -396.309, 1087.964, 28.10337, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -400.1007, 1087.726, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -402.2743, 1085.269, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -404.3299, 1081.174, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -406.9132, 1076.311, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -408.9427, 1075.889, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -411.0729, 1075.641, 28.01686, 0, 149, 0, 0, 100, 0),
(@PATH, 8, -411.3715, 1075.922, 28.01686, 0, 288, 0, 0, 100, 0),
(@PATH, 9, -411.3715, 1075.922, 28.01686, 2.164208, 58156, 0, 0, 100, 0),
(@PATH, 10, -404.0191, 1078.964, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -403.5955, 1084.135, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -400.8333, 1088.28, 28.01686, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -396.6267, 1088.648, 28.10337, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -394.2274, 1089.564, 28.10337, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -393.8056, 1092.219, 28.10337, 0, 1896, 0, 0, 100, 0),
(@PATH, 16, -393.8056, 1092.219, 28.10337, 2.408554, 47454, 0, 0, 100, 0);
-- 0x2016FC5B802F1F00003C430001161200 .go xyz -396.309 1087.964 28.10337

-- Pathing for  Entry: 48252 'TDB FORMAT' 
SET @NPC := 291458;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -378.9392, `position_y`= 1056.418, `position_z`= 21.92636 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -378.9392, 1056.418, 21.92636, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -374.7153, 1057.92, 21.92636, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -369.3368, 1058.675, 21.80136, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -363.3507, 1058.394, 22.1531, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -354.6823, 1057.835, 22.13772, 0, 94, 0, 0, 100, 0),
(@PATH, 6, -354.092, 1057.757, 22.13772, 0, 168, 0, 0, 100, 0),
(@PATH, 7, -354.092, 1057.757, 22.13772, 0.3316126, 39438, 0, 0, 100, 0),
(@PATH, 8, -362.2708, 1061.733, 22.01272, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -366.2049, 1063.976, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -371.1285, 1064.123, 21.80869, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -375.3177, 1063.307, 21.92636, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -378.4792, 1060.351, 21.92636, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -381.9167, 1054.24, 21.4802, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -381.3646, 1050.552, 21.52353, 0, 1884, 0, 0, 100, 0),
(@PATH, 15, -381.3646, 1050.552, 21.52353, 5.899213, 37765, 0, 0, 100, 0);
-- 0x2016FC5B802F1F00003C4300021611FF .go xyz -378.9392 1056.418 21.92636


-- Pathing for  Entry: 48253 'TDB FORMAT' 
SET @NPC := 291429;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -343.7083, `position_y`= 1073.292, `position_z`= 21.35921 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -343.7083, 1073.292, 21.35921, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -338.7743, 1068.306, 21.49336, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -334.0365, 1060.42, 21.86575, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -332.5243, 1054.642, 22.02245, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -336.3333, 1045.595, 21.85378, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -344.3264, 1042.731, 21.56594, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -354.3264, 1043.92, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -359.6632, 1045.901, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -363.1406, 1049.899, 21.90212, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -366.533, 1056.254, 22.01272, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -367.4618, 1060.483, 21.80136, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -363.8108, 1065.535, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -358.8576, 1068.865, 21.85921, 0, 39, 0, 0, 100, 0),
(@PATH, 14, -363.8108, 1065.535, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -367.4618, 1060.483, 21.80136, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -366.533, 1056.254, 22.01272, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -363.1406, 1049.899, 21.90212, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -359.6632, 1045.901, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -354.3264, 1043.92, 21.88772, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -344.3264, 1042.731, 21.56594, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -336.3333, 1045.595, 21.85378, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -332.5243, 1054.642, 22.02245, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -334.0365, 1060.42, 21.86575, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -338.7743, 1068.306, 21.49336, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -343.7083, 1073.292, 21.35921, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -350.6337, 1072.78, 21.53023, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -358.6962, 1069.132, 21.85921, 0, 108, 0, 0, 100, 0),
(@PATH, 28, -350.6337, 1072.78, 21.53023, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802F1F40003C4300021611FF .go xyz -343.7083 1073.292 21.35921

-- Pathing for  Entry: 47373 'TDB FORMAT' 
SET @NPC := 291617;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -316.219, `position_y`= 1116.13, `position_z`= 22.16045 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -316.219, 1116.13, 22.16045, 0, 256, 0, 0, 100, 0),
(@PATH, 2, -275.427, 1109.56, 22.16956, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -242.674, 1115.02, 22.09247, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -226.771, 1121.29, 22.10858, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -207.047, 1138.09, 22.07293, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -185.113, 1162.29, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -165.28, 1180.56, 22.10073, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -148.693, 1187.69, 22.10073, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -134.899, 1200.73, 22.14982, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -117.153, 1226.32, 22.1016, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -101.201, 1261.06, 22.0841, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -97.4792, 1278.52, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -100.083, 1302.07, 22.12739, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -96.0712, 1320.12, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -86.3229, 1333.95, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -83.592, 1349.68, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -89.0868, 1357.39, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -116.438, 1385.48, 22.12938, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -148.745, 1416.43, 22.16376, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -154.557, 1435.91, 22.09671, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -149.028, 1473.34, 20.89518, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -151.865, 1498.08, 20.59098, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -160.325, 1511.38, 20.86832, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -181.049, 1534.5, 21.03051, 0, 121, 0, 0, 100, 0),
(@PATH, 25, -160.325, 1511.38, 20.86832, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -151.865, 1498.08, 20.59098, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -149.028, 1473.34, 20.89518, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -154.557, 1435.91, 22.09671, 0, 0, 0, 0, 100, 0),
(@PATH, 29, -148.745, 1416.43, 22.16376, 0, 0, 0, 0, 100, 0),
(@PATH, 30, -116.438, 1385.48, 22.12938, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -89.0868, 1357.39, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 32, -83.592, 1349.68, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 33, -86.3229, 1333.95, 22.16791, 0, 0, 0, 0, 100, 0),
(@PATH, 34, -96.0712, 1320.12, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 35, -100.083, 1302.07, 22.12739, 0, 0, 0, 0, 100, 0),
(@PATH, 36, -97.4792, 1278.52, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 37, -101.201, 1261.06, 22.0841, 0, 0, 0, 0, 100, 0),
(@PATH, 38, -117.153, 1226.32, 22.1016, 0, 0, 0, 0, 100, 0),
(@PATH, 39, -134.899, 1200.73, 22.14982, 0, 0, 0, 0, 100, 0),
(@PATH, 40, -148.693, 1187.69, 22.10073, 0, 0, 0, 0, 100, 0),
(@PATH, 41, -165.28, 1180.56, 22.10073, 0, 0, 0, 0, 100, 0),
(@PATH, 42, -185.113, 1162.29, 22.17459, 0, 0, 0, 0, 100, 0),
(@PATH, 43, -207.047, 1138.09, 22.07293, 0, 0, 0, 0, 100, 0),
(@PATH, 44, -226.771, 1121.29, 22.10858, 0, 0, 0, 0, 100, 0),
(@PATH, 45, -242.674, 1115.02, 22.09247, 0, 0, 0, 0, 100, 0),
(@PATH, 46, -275.427, 1109.56, 22.16956, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E4340003C430000166DB2 .go xyz -316.219 1116.13 22.16045

UPDATE `creature` SET `position_x`= -316.219, `position_y`= 1116.13, `position_z`= 22.16045 WHERE `guid` IN (291615, 291616);
DELETE FROM `creature_formations` WHERE `leaderGUID`= 291617;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(291617, 291617, 0, 0, 515, 0, 0),
(291617, 291615, 3, 90, 515, 0, 0),
(291617, 291616, 3, 270, 515, 0, 0);

-- Pathing for  Entry: 48357 'TDB FORMAT' 
SET @NPC := 291093;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -588.283, `position_y`= 1413.08, `position_z`= 21.82862 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -588.283, 1413.08, 21.82862, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -592.0695, 1418.498, 22.09596, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -596.1198, 1422.194, 21.97096, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -600.783, 1424.571, 22.03314, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -605.5712, 1422.887, 22.06194, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -609.1371, 1420.264, 22.02203, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -612.5, 1419.807, 22.14703, 0, 1444, 0, 0, 100, 0),
(@PATH, 8, -612.5, 1419.807, 22.14703, 3.071779, 34031, 0, 0, 100, 0),
(@PATH, 9, -605.6042, 1423.542, 22.14446, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -599.9601, 1422.309, 21.83546, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -596.3316, 1419.694, 21.72364, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -591.4636, 1415.813, 21.89283, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -587.6354, 1412.495, 21.53285, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -584.6424, 1410.597, 21.58546, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -583.1493, 1413.08, 21.93775, 0, 402, 0, 0, 100, 0),
(@PATH, 16, -584.0816, 1413.517, 22.06861, 0, 384, 0, 0, 100, 0),
(@PATH, 17, -584.0816, 1413.517, 22.06861, 2.042035, 37797, 0, 0, 100, 0),
(@PATH, 18, -588.283, 1413.08, 21.82862, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802F3940003C4300011611FE .go xyz -588.283 1413.08 21.82862

-- Pathing for  Entry: 48355 'TDB FORMAT' 
SET @NPC := 291084;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -597.83, `position_y`= 1388.18, `position_z`= 21.77352 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -597.83, 1388.18, 21.77352, 0, 259, 0, 0, 100, 0),
(@PATH, 2, -586.71, 1393.01, 21.94979, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -583.828, 1399.85, 21.6263, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -584.356, 1404.66, 21.22096, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -587.26, 1409.4, 21.25282, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -591.799, 1411.8, 21.22096, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -594.566, 1415.61, 21.62135, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -603.036, 1420.21, 21.6347, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -609.142, 1415.94, 21.77203, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -613.37, 1408.18, 21.89703, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -612.542, 1396.95, 21.59211, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -608.04, 1389.65, 21.45417, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -600.998, 1387.88, 21.66669, 0, 97, 0, 0, 100, 0),
(@PATH, 14, -608.04, 1389.65, 21.45417, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -612.542, 1396.95, 21.59211, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -613.37, 1408.18, 21.89703, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -609.142, 1415.94, 21.77203, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -603.036, 1420.21, 21.6347, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -594.566, 1415.61, 21.62135, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -591.799, 1411.8, 21.22096, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -587.26, 1409.4, 21.25282, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -584.356, 1404.66, 21.22096, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -583.828, 1399.85, 21.6263, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -586.71, 1393.01, 21.94979, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802F38C0003C4300031611FF .go xyz -597.83 1388.18 21.77352

-- Pathing for  Entry: 47428 'TDB FORMAT' 
SET @NPC := 291412;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -549.736, `position_y`= 1404.97, `position_z`= 22.17466 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -549.736, 1404.97, 22.17466, 0, 57, 0, 0, 100, 0),
(@PATH, 2, -551.622, 1425.57, 22.17466, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -548.583, 1441.58, 22.17466, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -537.281, 1462.61, 22.17466, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -517.382, 1482.6, 22.05471, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -500.002, 1488.41, 22.05471, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -492.458, 1489.5, 22.0671, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -480.549, 1499.03, 22.0671, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -464.622, 1515.71, 22.1433, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -452.667, 1528.71, 22.1433, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -435.63, 1546.38, 22.06501, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -424.465, 1552.81, 22.13989, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -413.161, 1553.1, 22.13989, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -412.684, 1546.5, 22.13989, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -413.009, 1550.996, 22.13989, 0, 23547, 0, 0, 100, 0),
(@PATH, 16, -400.479, 1541.89, 39.246, 0, 812, 0, 0, 100, 0),
(@PATH, 17, -400.749, 1542.347, 38.62517, 0, 23861, 0, 0, 100, 0),
(@PATH, 18, -365.99, 1545.47, 22.0496, 0, 468, 0, 0, 100, 0),
(@PATH, 19, -350.035, 1553.92, 22.15549, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -342.965, 1566.05, 22.15549, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -340.234, 1576.92, 22.03049, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -330.358, 1589.77, 22.101, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -313.413, 1620.84, 22.35157, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -312.306, 1611.77, 22.19459, 0, 0, 0, 0, 100, 0),
(@PATH, 25, -296.78, 1626.1, 22.12645, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -286.172, 1629.14, 22.12645, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -242.245, 1614.67, 22.18179, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -196.661, 1595.17, 22.11063, 0, 0, 0, 0, 100, 0),
(@PATH, 29, -182.632, 1588.22, 20.80253, 0, 71, 0, 0, 100, 0),
(@PATH, 30, -196.661, 1595.17, 22.11063, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -242.245, 1614.67, 22.18179, 0, 0, 0, 0, 100, 0),
(@PATH, 32, -286.172, 1629.14, 22.12645, 0, 0, 0, 0, 100, 0),
(@PATH, 33, -296.78, 1626.1, 22.12645, 0, 0, 0, 0, 100, 0),
(@PATH, 34, -312.306, 1611.77, 22.19459, 0, 0, 0, 0, 100, 0),
(@PATH, 35, -313.413, 1620.84, 22.35157, 0, 0, 0, 0, 100, 0),
(@PATH, 36, -330.358, 1589.77, 22.101, 0, 0, 0, 0, 100, 0),
(@PATH, 37, -340.234, 1576.92, 22.03049, 0, 0, 0, 0, 100, 0),
(@PATH, 38, -342.965, 1566.05, 22.15549, 0, 0, 0, 0, 100, 0),
(@PATH, 39, -350.035, 1553.92, 22.15549, 0, 0, 0, 0, 100, 0),
(@PATH, 40, -365.99, 1545.47, 22.15549, 0, 0, 0, 0, 100, 0),
(@PATH, 41, -362.6935, 1547.216, 22.17709, 0, 23625, 0, 0, 100, 0),
(@PATH, 42, -400.479, 1541.89, 39.246, 0, 734, 0, 0, 100, 0),
(@PATH, 43, -400.749, 1542.347, 38.62517, 0, 23986, 0, 0, 100, 0),
(@PATH, 44, -412.684, 1546.5, 38.1917, 0, 468, 0, 0, 100, 0),
(@PATH, 45, -413.161, 1553.1, 22.13989, 0, 0, 0, 0, 100, 0),
(@PATH, 46, -424.465, 1552.81, 22.13989, 0, 0, 0, 0, 100, 0),
(@PATH, 47, -435.63, 1546.38, 22.06501, 0, 0, 0, 0, 100, 0),
(@PATH, 48, -452.667, 1528.71, 22.1433, 0, 0, 0, 0, 100, 0),
(@PATH, 49, -464.622, 1515.71, 22.1433, 0, 0, 0, 0, 100, 0),
(@PATH, 50, -480.549, 1499.03, 22.0671, 0, 0, 0, 0, 100, 0),
(@PATH, 51, -492.458, 1489.5, 22.0671, 0, 0, 0, 0, 100, 0),
(@PATH, 52, -500.002, 1488.41, 22.05471, 0, 0, 0, 0, 100, 0),
(@PATH, 53, -517.382, 1482.6, 22.05471, 0, 0, 0, 0, 100, 0),
(@PATH, 54, -537.281, 1462.61, 22.17466, 0, 0, 0, 0, 100, 0),
(@PATH, 55, -548.583, 1441.58, 22.17466, 0, 0, 0, 0, 100, 0),
(@PATH, 56, -551.622, 1425.57, 22.17466, 0, 0, 0, 0, 100, 0);
-- 0x2016FC5B802E5100003C430000166D69 .go xyz -549.736 1404.97 22.17466

UPDATE `creature` SET`position_x`= -549.736, `position_y`= 1404.97, `position_z`= 22.17466 WHERE `guid` IN (291419, 291411);
DELETE FROM `creature_formations` WHERE `leaderGUID`= 291412;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(291412, 291412, 0, 0, 515, 0, 0),
(291412, 291419, 3, 90, 515, 0, 0),
(291412, 291411, 3, 270, 515, 0, 0);
