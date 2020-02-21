UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317756;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317757;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317748;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317753;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317681;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317776;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317766;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317781;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317783;
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `guid`= 317839;

-- Pathing for  Entry: 887 'TDB FORMAT' 
SET @NPC := 317696;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10624.589, `position_y`= -1185.5638, `position_z`= 28.968943 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10624.589, -1185.5638, 28.968943, 0, 154, 0, 0, 100, 0),
(@PATH, 2, -10648.632, -1192.0426, 28.565548, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10683.194, -1193.247, 27.458822, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10709.024, -1176.6018, 26.58296, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10736.007, -1159.654, 26.561907, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10755.747, -1144.1693, 26.936907, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -10768.78, -1129.4673, 27.876637, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10779.995, -1110.3231, 30.857838, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10784.427, -1099.5131, 33.14368, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10787.088, -1079.9607, 36.6554, 0, 367, 0, 0, 100, 0),
(@PATH, 11, -10784.427, -1099.5131, 33.14368, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -10779.995, -1110.3231, 30.857838, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -10768.78, -1129.4673, 27.876637, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -10755.747, -1144.1693, 26.936907, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -10736.007, -1159.654, 26.561907, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -10709.024, -1176.6018, 26.58296, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -10683.194, -1193.247, 27.458822, 0, 0, 0, 0, 100, 0),
(@PATH, 18, -10648.632, -1192.0426, 28.565548, 0, 0, 0, 0, 100, 0);
-- 0x20307C000000DDC00024310000349C96 .go xyz -10624.589 -1185.5638 28.968943

-- Pathing for  Entry: 828 'TDB FORMAT' 
SET @NPC := 317840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10554.391, `position_y`= -1228.8342, `position_z`= 27.530521 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10554.391, -1228.8342, 27.530521, 0, 269, 0, 0, 100, 0),
(@PATH, 2, -10553.594, -1250.2023, 32.04774, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10548.981, -1262.2749, 33.562145, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10533.537, -1283.0181, 38.771404, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10533.849, -1307.4089, 42.146812, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10546.833, -1334.7568, 47.524525, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -10539.697, -1379.275, 56.142982, 0, 382, 0, 0, 100, 0),
(@PATH, 8, -10546.816, -1334.8027, 47.615833, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10533.849, -1307.4089, 42.146812, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10533.537, -1283.0181, 38.771404, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -10548.981, -1262.2749, 33.562145, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -10553.594, -1250.2023, 32.04774, 0, 0, 0, 0, 100, 0);
-- 0x20307C000000CF000024310000349C96 .go xyz -10554.391 -1228.8342 27.530521

-- Pathing for  Entry: 576 'TDB FORMAT' 
SET @NPC := 317754;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -10584.023, `position_y`= -1180.5332, `position_z`= 27.993622 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -10584.023, -1180.5332, 27.993622, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -10573.577, -1185.8036, 27.993622, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -10570.054, -1191.732, 27.774628, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -10569.188, -1199.1808, 27.753387, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -10551.346, -1205.7352, 27.41602, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -10549.264, -1192.9121, 27.787256, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -10535.187, -1192.9082, 27.70083, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -10546.209, -1179.3162, 28.20669, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -10547.905, -1167.9598, 27.787256, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -10554.194, -1153.2107, 28.07649, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -10565.879, -1154.2136, 27.82649, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -10577.466, -1165.1613, 28.12534, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -10581.633, -1172.8923, 28.493622, 0, 0, 0, 0, 100, 0);
-- 0x20307C00000090000024310000349C96 .go xyz -10584.023 -1180.5332 27.993622

DELETE FROM `creature` WHERE `guid`= 317602;
DELETE FROM `creature_addon` WHERE `guid`= 317602;
