UPDATE `creature_template` SET `AIName`="" WHERE `entry` IN (35063, 35075);
UPDATE `creature_template_addon` SET `bytes2`= 1 WHERE `entry` IN (35063, 35075);
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (35063, 35075);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35063, 35075) AND `source_type`=0;

-- Pathing for  Entry: 35075 'TDB FORMAT' 
SET @NPC := 251964;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8188.899, `position_y`= 1635.241, `position_z`= 26.67878 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8188.899, 1635.241, 26.67878, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8177.147, 1650.495, 24.34236, 0, 12575, 0, 0, 100, 0),
(@PATH, 3, -8196.395, 1626.899, 29.03152, 0, 163, 0, 0, 100, 0),
(@PATH, 4, -8196.395, 1626.899, 29.03152, 4.18879, 11766, 0, 0, 100, 0);
-- 0x203AEC51002240C0000F2500003A6BC8 .go xyz -8188.899 1635.241 26.67878


-- Pathing for  Entry: 35075 'TDB FORMAT' 
SET @NPC := 252143;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8228.665, `position_y`= 1462.786, `position_z`= 39.86687 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8228.665, 1462.786, 39.86687, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8234.759, 1457.092, 40.25389, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8247.933, 1445.405, 39.75389, 0, 156, 0, 0, 100, 0),
(@PATH, 4, -8254.413, 1437.365, 40.25389, 0, 315, 0, 0, 100, 0),
(@PATH, 5, -8254.413, 1437.365, 40.25389, 4.380776, 8906, 0, 0, 100, 0),
(@PATH, 6, -8248.556, 1442.104, 39.8933, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8241.295, 1446.17, 40.14672, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8228.63, 1456.528, 39.93279, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8216.509, 1476.658, 39.80046, 0, 10224, 0, 0, 100, 0);
-- 0x203AEC51002240C0000F250016BA6BC8 .go xyz -8228.665 1462.786 39.86687

-- Pathing for  Entry: 35075 'TDB FORMAT' 
SET @NPC := 252138;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8263.047, `position_y`= 1441.517, `position_z`= 39.75389 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8263.047, 1441.517, 39.75389, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8278.436, 1441.51, 39.83167, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8292.45, 1445.184, 41.59131, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8305.451, 1454.646, 42.85939, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8312.776, 1465.01, 45.07387, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8318.302, 1478.781, 45.63706, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8320.174, 1492.778, 45.86167, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8318.804, 1503.344, 46.76398, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8313.906, 1514.465, 46.1906, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8306.37, 1523.543, 45.674, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8294.384, 1527.951, 44.86737, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8283.156, 1528.708, 43.89508, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8271.285, 1528.349, 42.76447, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -8260.058, 1525.205, 42.44352, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -8249.575, 1518.509, 41.81096, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -8238.114, 1508.057, 40.93571, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -8230.154, 1495.748, 40.42546, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -8227.701, 1484.745, 39.94352, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -8227.294, 1476.099, 39.80046, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -8229.738, 1464.109, 39.96368, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -8233.851, 1458.457, 40.17601, 0, 0, 0, 0, 100, 0),
(@PATH, 22, -8241.936, 1449.684, 40.45905, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -8249.995, 1444.583, 39.94066, 0, 0, 0, 0, 100, 0);
-- 0x203AEC51002240C0000F250010BA6BC7 .go xyz -8263.047 1441.517 39.75389

-- Pathing for  Entry: 35075 'TDB FORMAT' 
SET @NPC := 251990;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8113.755, `position_y`= 1563.405, `position_z`= 9.484865 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8113.755, 1563.405, 9.484865, 0, 332, 0, 0, 100, 0),
(@PATH, 2, -8114.584, 1563.541, 9.692751, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8144.462, 1563.488, 16.32244, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8167.382, 1562.99, 21.69629, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8186.381, 1562.618, 26.14991, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8198.205, 1563.021, 28.96924, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8209.448, 1562.026, 31.32539, 0, 368, 0, 0, 100, 0),
(@PATH, 8, -8198.205, 1563.021, 28.96924, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8186.401, 1562.615, 26.26123, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8167.4, 1562.985, 21.64991, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8144.462, 1563.488, 16.32244, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -8125.361, 1563.78, 12.0636, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -8113.755, 1563.405, 9.484865, 0, 111, 0, 0, 100, 0);
-- 0x203AEC51002240C0000F250027BA6BC6 .go xyz -8113.755 1563.405 9.484865

-- Pathing for  Entry: 35075 'TDB FORMAT' 
SET @NPC := 251997;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8247.177, `position_y`= 1517.394, `position_z`= 41.67424 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8247.177, 1517.394, 41.67424, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8260.482, 1525.641, 42.49455, 0, 10527, 0, 0, 100, 0),
(@PATH, 3, -8232.136, 1507.826, 40.81881, 0, 166, 0, 0, 100, 0),
(@PATH, 4, -8232.136, 1507.826, 40.81881, 6.143559, 10515, 0, 0, 100, 0);
-- 0x203AEC51002240C0000F2500283A6BC8 .go xyz -8247.177 1517.394 41.67424

-- Pathing for  Entry: 35063 'TDB FORMAT' 
SET @NPC := 252105;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8321.516, `position_y`= 1501.927, `position_z`= 46.10393 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8321.516, 1501.927, 46.10393, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8339.403, 1508.09, 46.41598, 0, 28972, 0, 0, 100, 0),
(@PATH, 3, -8303.576, 1496.137, 45.1461, 6.248279, 13375, 0, 0, 100, 0);
-- 0x203AEC5100223DC0000F2500003B8529 .go xyz -8321.516 1501.927 46.10393

-- Pathing for  Entry: 35063 'TDB FORMAT' 
SET @NPC := 251744;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8169.653, `position_y`= 1295.234, `position_z`= 25.319 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8169.653, 1295.234, 25.319, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8169.5, 1280.429, 25.46936, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8171.653, 1266.861, 25.09949, 0, 13110, 0, 0, 100, 0),
(@PATH, 4, -8169.082, 1284.653, 25.4259, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8173.162, 1305.715, 27.15674, 0, 230, 0, 0, 100, 0),
(@PATH, 6, -8173.016, 1322.708, 27.60278, 0, 65, 0, 0, 100, 0),
(@PATH, 7, -8173.016, 1322.708, 27.60278, 3.071779, 10515, 0, 0, 100, 0);
-- 0x203AEC5100223DC0000F2500003CC858 .go xyz -8169.653 1295.234 25.319

-- Pathing for  Entry: 35063 'TDB FORMAT' 
SET @NPC := 251985;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8189.41, `position_y`= 1560.906, `position_z`= 27.23719 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8189.41, 1560.906, 27.23719, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -8194.478, 1577.62, 28.28757, 0, 9908, 0, 0, 100, 0),
(@PATH, 3, -8196.216, 1559.672, 28.89405, 0, 374, 0, 0, 100, 0),
(@PATH, 4, -8192.455, 1550.038, 30.49012, 0, 257, 0, 0, 100, 0),
(@PATH, 5, -8192.455, 1550.038, 30.49012, 4.45059, 13359, 0, 0, 100, 0);
-- 0x203AEC5100223DC0000F2500113A6BC8 .go xyz -8189.41 1560.906 27.23719

-- Pathing for  Entry: 35063 'TDB FORMAT' 
SET @NPC := 251823;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8118.306, `position_y`= 1652.349, `position_z`= 12.16903 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8118.306, 1652.349, 12.16903, 0, 10049, 0, 0, 100, 0),
(@PATH, 2, -8119.952, 1632.432, 13.28878, 0, 277, 0, 0, 100, 0),
(@PATH, 3, -8119.952, 1632.432, 13.28878, 4.694936, 9718, 0, 0, 100, 0);
-- 0x203AEC5100223DC0000F25002A3A6BC6 .go xyz -8118.306 1652.349 12.16903

-- Pathing for  Entry: 48984 'TDB FORMAT' 
SET @NPC := 252041;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8473.551, `position_y`= 1818.557, `position_z`= 34.51096 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8473.551, 1818.557, 34.51096, 0, 367, 0, 0, 100, 0),
(@PATH, 2, -8494.922, 1818.089, 34.91437, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8507.426, 1817.785, 35.1534, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8517.013, 1817.661, 35.30394, 0, 82, 0, 0, 100, 0),
(@PATH, 5, -8507.426, 1817.785, 35.1534, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8494.922, 1818.089, 34.91437, 0, 0, 0, 0, 100, 0);
-- 0x203AEC51002FD600000F2500003A6BC5 .go xyz -8473.551 1818.557 34.51096

-- Pathing for  Entry: 48984 'TDB FORMAT' 
SET @NPC := 252045;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8602.044, `position_y`= 1806.002, `position_z`= 46.43149 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8602.044, 1806.002, 46.43149, 0, 38, 0, 0, 100, 0),
(@PATH, 2, -8586.417, 1797.781, 46.50694, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8568.332, 1788.271, 46.59301, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8552.122, 1779.943, 46.59797, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8545.247, 1776.069, 47.8952, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8541.788, 1774.174, 47.79644, 0, 332, 0, 0, 100, 0),
(@PATH, 7, -8552.122, 1779.943, 46.59797, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8568.332, 1788.271, 46.59301, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8586.417, 1797.781, 46.50694, 0, 0, 0, 0, 100, 0);
-- 0x203AEC51002FD600000F2500033A6BC5 .go xyz -8602.044 1806.002 46.43149

-- Pathing for  Entry: 48984 'TDB FORMAT' 
SET @NPC := 252047;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8615.37, `position_y`= 1809.151, `position_z`= 54.10123 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8615.37, 1809.151, 54.10123, 0, 27, 0, 0, 100, 0),
(@PATH, 2, -8605.232, 1801.365, 55.74068, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8594.854, 1793.226, 57.37666, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8588.035, 1787.979, 58.47735, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8578.864, 1780.781, 59.92159, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8576.373, 1778.918, 61.91367, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -8573.263, 1776.535, 61.84037, 0, 130, 0, 0, 100, 0),
(@PATH, 8, -8578.864, 1780.781, 59.92159, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8588.035, 1787.979, 58.47735, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8594.854, 1793.226, 57.37666, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -8605.232, 1801.365, 55.74068, 0, 0, 0, 0, 100, 0);
-- 0x203AEC51002FD600000F250004BA6BC5 .go xyz -8615.37 1809.151 54.10123

-- Pathing for  Entry: 34693 'TDB FORMAT' 
SET @NPC := 251717;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -8431.024, `position_y`= 1324.602, `position_z`= 101.875 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '80264');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -8431.024, 1324.602, 101.875, 0, 368, 0, 0, 100, 0),
(@PATH, 2, -8424.518, 1329.443, 102.0956, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -8416.872, 1332.5, 102.375, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -8408.069, 1333.384, 102.1484, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -8398.679, 1334.172, 102.1039, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -8387.957, 1341.425, 102.1039, 0, 331, 0, 0, 100, 0),
(@PATH, 7, -8398.679, 1334.172, 102.1039, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -8408.069, 1333.384, 102.1484, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -8416.872, 1332.5, 102.375, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -8424.518, 1329.443, 102.0956, 0, 0, 0, 0, 100, 0);
-- 0x203AEC510021E140000F2500003A6BC5 .go xyz -8431.024 1324.602 101.875
