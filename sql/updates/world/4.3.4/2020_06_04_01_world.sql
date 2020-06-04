-- Pathing for  Entry: 45928 'TDB FORMAT' 
SET @NPC := 368265;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -981.587, `position_y`= 503.497, `position_z`= 700.00085 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -981.587, 503.497, 700.00085, 0, 337, 0, 0, 100, 0),
(@PATH, 2, -996.74133, 487.35938, 699.9696, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1010.5278, 473.07465, 700.0321, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -996.74133, 487.35938, 699.9696, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CDA0000061A00015494F0 .go xyz -981.587 503.497 700.00085

-- Pathing for  Entry: 45915 'TDB FORMAT' 
SET @NPC := 368199;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -455.998, `position_y`= -103.161, `position_z`= 638.8203 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -455.998, -103.161, 638.8203, 0, 184, 0, 0, 100, 0),
(@PATH, 2, -471.361, -118.66, 638.8203, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -481.639, -128.589, 638.8203, 0, 126, 0, 0, 100, 0),
(@PATH, 4, -471.361, -118.66, 638.8203, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CD6C000061A0000D494F0 .go xyz -455.998 -103.161 638.8203

-- Pathing for  Entry: 45922 'TDB FORMAT' 
SET @NPC := 368238;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1127.52, `position_y`= 59.0816, `position_z`= 704.73627 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1127.52, 59.0816, 704.73627, 0, 87, 0, 0, 100, 0),
(@PATH, 2, -1114.89, 45.9167, 704.7136, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1113.55, 32.8767, 704.68176, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1116.16, 16.0365, 704.7362, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -1135.46, 5.13021, 704.73584, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1121.5857, 12.97048, 704.7357, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -1121.5857, 12.97048, 704.7357, 0.685515165328979492, 0, 0, 0, 100, 0),
(@PATH, 8, -1116.16, 16.0365, 704.7362, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -1113.55, 32.8767, 704.68176, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -1114.89, 45.9167, 704.7136, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CD88000061A00005494F3 .go xyz -1127.52 59.0816 704.73627

-- Pathing for  Entry: 45922 'TDB FORMAT' 
SET @NPC := 368235;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1023.97, `position_y`= -166.762, `position_z`= 692.2395 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1023.97, -166.762, 692.2395, 0, 144, 0, 0, 100, 0),
(@PATH, 2, -1039.87, -150.519, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1047.46, -133.795, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -1049.57, -115.957, 694.9168, 0, 142, 0, 0, 100, 0),
(@PATH, 5, -1047.46, -133.795, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -1039.87, -150.519, 694.9169, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CD88000061A00015494F0 .go xyz -1023.97 -166.762 692.2395

-- Pathing for  Entry: 45922 'TDB FORMAT' 
SET @NPC := 368232;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -948.167, `position_y`= -83.4965, `position_z`= 693.55505 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -948.167, -83.4965, 693.55505, 0, 93, 0, 0, 100, 0),
(@PATH, 2, -961.023, -72.5833, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -977.464, -65.3681, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -987.6986, -64.00897, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -994.734, -63.0747, 694.9169, 0, 99, 0, 0, 100, 0),
(@PATH, 6, -987.6986, -64.00897, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -977.464, -65.3681, 694.9169, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -961.023, -72.5833, 694.9169, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CD88000061A00025494F0 .go xyz -948.167 -83.4965 693.55505

-- Pathing for  Entry: 45922 'TDB FORMAT' 
SET @NPC := 368237;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -1101.78, `position_y`= 21.691, `position_z`= 704.68994 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -1101.78, 21.691, 704.68994, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -1101.69, 43.5503, 704.6774, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -1113.33, 62.7066, 704.73865, 0, 22, 0, 0, 100, 0),
(@PATH, 4, -1101.69, 43.5503, 704.6774, 0, 0, 0, 0, 100, 0);
-- 0x203ADC52202CD88000061A00005494F4 .go xyz -1101.78 21.691 704.68994
