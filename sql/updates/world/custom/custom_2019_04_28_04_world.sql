-- Pathing for  Entry: 39931 'TDB FORMAT' 
SET @NPC := 386110;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 5156.017, `position_y`= -1780.247, `position_z`= 1337.995 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 5156.017, -1780.247, 1337.995, 0, 383, 1, 0, 100, 0),
(@PATH, 2, 5156.017, -1780.247, 1337.995, 2.391101, 29547, 1, 0, 100, 0),
(@PATH, 3, 5141.944, -1792.207, 1337.741, 0, 426, 1, 0, 100, 0),
(@PATH, 4, 5141.944, -1792.207, 1337.741, 1.448623, 29563, 1, 0, 100, 0);
-- 0x201F70002026FEC0001B990000255F68 .go xyz 5156.017 -1780.247 1337.995

-- Pathing for  Entry: 39931 'TDB FORMAT' 
SET @NPC := 386111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 5097.709, `position_y`= -1805.946, `position_z`= 1333.304 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 5097.709, -1805.946, 1333.304, 0, 16455, 1, 0, 100, 0),
(@PATH, 2, 5111.306, -1786.733, 1334.786, 0, 18021, 1, 0, 100, 0);
-- 0x201F70002026FEC0001B990000255F69 .go xyz 5097.709 -1805.946 1333.304

-- Pathing for  Entry: 39931 'TDB FORMAT' 
SET @NPC := 386148;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 5068.707, `position_y`= -1729, `position_z`= 1328.554 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 5068.707, -1729, 1328.554, 0, 46339, 1, 0, 100, 0),
(@PATH, 2, 5111.411, -1727.234, 1333.157, 0, 12733, 1, 0, 100, 0),
(@PATH, 3, 5089.875, -1728.929, 1330.764, 0, 23892, 1, 0, 100, 0),
(@PATH, 4, 5068.707, -1729, 1328.554, 0, 20807, 1, 0, 100, 0),
(@PATH, 5, 5083.771, -1755.79, 1330.788, 0, 6157, 1, 0, 100, 0),
(@PATH, 6, 5111.411, -1727.234, 1333.157, 0, 13890, 1, 0, 100, 0),
(@PATH, 7, 5089.875, -1728.929, 1330.764, 0, 25204, 1, 0, 100, 0);
-- 0x201F70002026FEC0001B990000A55F68 .go xyz 5068.707 -1729 1328.554

-- Pathing for  Entry: 39931 'TDB FORMAT' 
SET @NPC := 386117;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 5123.82, `position_y`= -1768.519, `position_z`= 1334.406 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 5123.82, -1768.519, 1334.406, 2.80998, 26703, 1, 0, 100, 0),
(@PATH, 2, 5107.418, -1770.833, 1333.512, 0, 10061, 1, 0, 100, 0),
(@PATH, 3, 5123.858, -1773.108, 1334.921, 0, 0, 1, 0, 100, 0),
(@PATH, 4, 5123.643, -1765.507, 1334.475, 0, 0, 1, 0, 100, 0),
(@PATH, 5, 5115.462, -1758.25, 1334.334, 0, 0, 1, 0, 100, 0),
(@PATH, 6, 5109.454, -1754.026, 1333.945, 0, 0, 1, 0, 100, 0),
(@PATH, 7, 5111.233, -1764.17, 1333.248, 0, 0, 1, 0, 100, 0),
(@PATH, 8, 5118.84, -1768.224, 1333.971, 0, 0, 1, 0, 100, 0),
(@PATH, 9, 5123.82, -1768.519, 1334.406, 0, 16356, 1, 0, 100, 0);
-- 0x201F70002026FEC0001B990001255F68 .go xyz 5123.82 -1768.519 1334.406

-- Pathing for  Entry: 39931 'TDB FORMAT' 
SET @NPC := 386133;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 5225.712, `position_y`= -1739.309, `position_z`= 1346.01 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 5225.712, -1739.309, 1346.01, 0, 10496, 1, 0, 100, 0),
(@PATH, 2, 5162.268, -1711.752, 1343.358, 0, 10293, 1, 0, 100, 0),
(@PATH, 3, 5187.59, -1734.229, 1340.069, 0, 6210, 1, 0, 100, 0),
(@PATH, 4, 5147.952, -1747.608, 1335.356, 0, 14116, 1, 0, 100, 0);
-- 0x201F70002026FEC0001B990002A55F68 .go xyz 5225.712 -1739.309 1346.01
