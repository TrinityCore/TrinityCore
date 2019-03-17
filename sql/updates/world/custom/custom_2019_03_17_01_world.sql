-- Pathing for  Entry: 56350 'TDB FORMAT' 
SET @NPC := 266710;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 236.9635, `position_y`= 1343.188, `position_z`= 170.1917 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 236.9635, 1343.188, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 238.0156, 1329.345, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 242.6129, 1317.776, 170.1963, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 256.1823, 1308.615, 170.1904, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 271.3889, 1304.927, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 285.2847, 1309.561, 170.1935, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 297.7969, 1319.905, 170.1975, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 302.4792, 1333.38, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 301.2708, 1343.939, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 296.8856, 1352.706, 170.196, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 289.0851, 1360.248, 170.1952, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 279.1858, 1366.885, 170.1917, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 269.7049, 1369.038, 170.1916, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 261.2604, 1366.5, 170.1916, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 252.3611, 1362.264, 170.1977, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 243.1771, 1352.363, 170.1959, 0, 0, 0, 0, 100, 0);
-- 0x20307C5EA0370780002BF40000D87C37 .go xyz 236.9635 1343.188 170.1917
