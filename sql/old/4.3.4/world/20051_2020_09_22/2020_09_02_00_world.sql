UPDATE `creature` SET `modelid`= 31736 WHERE `id`= 52924;

SET @PATH := 52924 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 117.73489, 1662.7703, 42.021564, 0, 0, 1, 0, 100, 0),
(@PATH, 2, 132.13078, 1645.1361, 42.021576, 0, 0, 1, 0, 100, 0);

SET @PATH := 52924 * 100 + 1;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 122.48868, 1639.4692, 42.1047, 0, 0, 1, 0, 100, 0);

SET @PATH := 52924 * 100 + 2;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 121.03993, 1672.1962, 42.02157, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_text` WHERE `CreatureID`= 24363;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(24363, 0, 0, 'Da spirits gonna feast today! Begin da ceremonies, sacrifice da prisoners... make room for our new guests!', 14, 0, 100, 0, 0, 12053, 23253, 'Hex Lord Malacrass'),
(24363, 1, 0, 'Don\'t be shy. Thousands have come before you. Ya not be alone in your service.', 14, 0, 100, 0, 0, 12055, 23317, 'Hex Lord Malacrass'),
(24363, 2, 0, 'Ya gonna fail, strangers. Many try before you, but dey only make us stronger!', 14, 0, 100, 0, 0, 12056, 23318, 'Hex Lord Malacrass');
UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 24363;

-- Pathing for  Entry: 23774 'TDB FORMAT' 
SET @NPC := 339492;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -180.443, `position_y`= 1242.61, `position_z`= 2.1280074 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -180.443, 1242.61, 2.1280074, 4.729842185974121093, 3672, 1, 0, 100, 0),
(@PATH, 2, -204.02148, 1247.1338, 1.448443, 0, 217, 1, 0, 100, 0),
(@PATH, 3, -204.02148, 1247.1338, 1.4484429, 5.672319889068603515, 4484, 1, 0, 100, 0),
(@PATH, 4, -200.48438, 1242.8473, 1.0690485, 0, 411, 1, 0, 100, 0),
(@PATH, 5, -200.48438, 1242.8473, 1.0690485, 0.593411922454833984, 422, 1, 0, 100, 0),
(@PATH, 6, -200.48438, 1242.8473, 1.0690485, 0.209439516067504882, 3437, 1, 0, 100, 0),
(@PATH, 7, -190.551, 1236.19, 0.49617147, 0, 3863, 1, 0, 100, 0),
(@PATH, 8, -180.443, 1242.61, 2.1280074, 0, 0, 1, 0, 100, 0);
-- 0x2041004700173780001C8700007ECDE7 .go xyz -180.443 1242.61 2.1280074

-- Pathing for  Entry: 23774 'TDB FORMAT' 
SET @NPC := 329126;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -222.16797, `position_y`= 1131.9479, `position_z`= -1.6283163 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -222.16797, 1131.9479, -1.6283163, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -211.82857, 1136.8333, -1.9116962, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -210.5931, 1146.4077, -1.9181659, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -225.59148, 1148.1578, -1.8781269, 0, 0, 0, 0, 100, 0);
-- 0x2041004700173780001C8700007ECDE8 .go xyz -222.16797 1131.9479 -1.6283163

-- Pathing for  Entry: 23774 'TDB FORMAT' 
SET @NPC := 339142;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -165.23297, `position_y`= 1113.8899, `position_z`= 0.12499935 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -165.23297, 1113.8899, 0.12499935, 0, 367, 0, 0, 100, 0),
(@PATH, 2, -171.59407, 1116.7018, 0.124147296, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -181.63933, 1117.8892, 0.124147296, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -196.2499, 1109.3352, 0.2491473, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -217.72395, 1108.2024, -0.14772546, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -213.77246, 1131.3308, -1.8509725, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -216.44846, 1156.3108, -1.9116962, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -206.4719, 1176.8019, -0.5678997, 0, 10263, 0, 0, 100, 0),
(@PATH, 9, -203.00826, 1155.8253, -0.9969013, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -197.7297, 1135.4039, -0.9588605, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -184.39062, 1120.7157, 0.124147296, 0, 0, 0, 0, 100, 0);
-- 0x2041004700173780001C8700007ECDE9 .go xyz -165.23297 1113.8899 0.12499935

-- Pathing for  Entry: 23774 'TDB FORMAT' 
SET @NPC := 339082;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -217.07715, `position_y`= 1126.6138, `position_z`= -1.8509725 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -217.07715, 1126.6138, -1.8509725, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -208.20735, 1130.927, -1.7259725, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -208.23557, 1120.8994, -1.5033163, 0, 0, 0, 0, 100, 0);
-- 0x2041004700173780001C870000FECDE7 .go xyz -217.07715 1126.6138 -1.8509725

-- Pathing for  Entry: 23774 'TDB FORMAT' 
SET @NPC := 339132;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -198.46822, `position_y`= 1154.9237, `position_z`= -0.3548566 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -198.46822, 1154.9237, -0.3548566, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -208.29861, 1163.7311, -1.2200458, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -226.81152, 1160.5486, -1.9116962, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -233.97852, 1148.4395, -0.98271775, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -226.84235, 1119.8912, -0.37563074, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -209.14638, 1109.8043, -0.62514246, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -187.0677, 1114.8241, 0.124147296, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -197.60515, 1131.2767, -0.8668195, 0, 0, 0, 0, 100, 0);
-- 0x2041004700173780001C870000FECDE8 .go xyz -198.46822 1154.9237 -0.3548566
