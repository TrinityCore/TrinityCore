-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339741;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -549.5816, `position_y`= -233.3767, `position_z`= 276.416 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -549.5816, -233.3767, 276.416, 0, 228, 1, 0, 100, 0),
(@PATH, 2, -549.5816, -233.3767, 276.416, 2.268928, 11375, 1, 0, 100, 0),
(@PATH, 3, -551.2315, -217.704, 284.3045, 0, 10447, 1, 0, 100, 0);
-- 0x202F5453C026868000116B00012E0B73 .go xyz -549.5816 -233.3767 276.416

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339744;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -553.885, `position_y`= -232.431, `position_z`= 276.4297 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -553.885, -232.431, 276.4297, 0, 10247, 1, 0, 100, 0),
(@PATH, 2, -553.885, -251.5, 276.3315, 0, 122, 1, 0, 100, 0),
(@PATH, 3, -553.885, -251.5, 276.3315, 4.223697, 11375, 1, 0, 100, 0);
-- 0x202F5453C026868000116B0001AE0B73 .go xyz -553.885 -232.431 276.4297

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339748;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -551.127, `position_y`= -256.137, `position_z`= 276.4077 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -551.127, -256.137, 276.4077, 0, 11221, 1, 0, 100, 0),
(@PATH, 2, -532.023, -245.892, 276.3661, 0, 252, 1, 0, 100, 0),
(@PATH, 3, -532.023, -245.892, 276.3661, 0.2268928, 10969, 1, 0, 100, 0);
-- 0x202F5453C026868000116B00022E0B73 .go xyz -551.127 -256.137 276.4077


-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 340029;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -731.9739, `position_y`= -624.7604, `position_z`= 278.0298 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -731.9739, -624.7604, 278.0298, 0, 10509, 1, 0, 100, 0),
(@PATH, 2, -729.2518, -640.342, 280.0197, 0, 10913, 1, 0, 100, 0);
-- 0x202F5453C026868000116B000AAE0B73 .go xyz -731.9739 -624.7604 278.0298

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 340169;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -729.6111, `position_y`= -649.7847, `position_z`= 277.8875 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -729.6111, -649.7847, 277.8875, 0, 10630, 1, 0, 100, 0),
(@PATH, 2, -720.6285, -658.4097, 273.5714, 0, 10270, 1, 0, 100, 0);
-- 0x202F5453C026868000116B000BAE0B73 .go xyz -729.6111 -649.7847 277.8875

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 340159;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -519.9045, `position_y`= -233.4462, `position_z`= 297.1301 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -519.9045, -233.4462, 297.1301, 0, 11141, 1, 0, 100, 0),
(@PATH, 2, -517.5625, -251.0451, 286.7873, 0, 11013, 1, 0, 100, 0);
-- 0x202F5453C026868000116B0013AE0B73 .go xyz -519.9045 -233.4462 297.1301

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339749;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -520.9948, `position_y`= -224.5434, `position_z`= 294.451 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -520.9948, -224.5434, 294.451, 0, 797, 1, 0, 100, 0),
(@PATH, 2, -520.9948, -224.5434, 294.451, 2.268928, 58469, 1, 0, 100, 0),
(@PATH, 3, -540.219, -209.313, 299.756, 0, 35797, 1, 0, 100, 0),
(@PATH, 4, -520.9948, -224.5434, 294.451, 0, 687, 1, 0, 100, 0);
-- 0x202F5453C026868000116B00142E0B73 .go xyz -520.9948 -224.5434 294.451

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339742;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -560.4835, `position_y`= -249.8244, `position_z`= 276.4507 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -560.4835, -249.8244, 276.4507, 4.904375, 11265, 1, 0, 100, 0),
(@PATH, 2, -533, -240.8, 276.4019, 0, 10556, 1, 0, 100, 0),
(@PATH, 3, -560.4835, -249.8244, 276.4507, 0, 526, 1, 0, 100, 0);
-- 0x202F5453C026868000116B0014AE0B73 .go xyz -560.4835 -249.8244 276.4507

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 340028;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -733.7552, `position_y`= -634.5504, `position_z`= 275.276 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -733.7552, -634.5504, 275.276, 0, 10709, 1, 0, 100, 0),
(@PATH, 2, -725.6354, -639.1667, 274.2885, 0, 10497, 1, 0, 100, 0);
-- 0x202F5453C026868000116B00162E0B73 .go xyz -733.7552 -634.5504 275.276

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339737;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -556.1163, `position_y`= -214.7118, `position_z`= 284.0871 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -556.1163, -214.7118, 284.0871, 0, 719, 1, 0, 100, 0),
(@PATH, 2, -556.1163, -214.7118, 284.0871, 2.268928, 58359, 1, 0, 100, 0),
(@PATH, 3, -548.408, -204.111, 303.19, 0, 35985, 1, 0, 100, 0);
-- 0x202F5453C026868000116B001C2E0B73 .go xyz -556.1163 -214.7118 284.0871

-- Pathing for  Entry: 39450 'TDB FORMAT' 
SET @NPC := 339746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -525.533, `position_y`= -227.4132, `position_z`= 286.8284 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -525.533, -227.4132, 286.8284, 2.268928, 58359, 1, 0, 100, 0),
(@PATH, 2, -517.892, -220.328, 301.94, 0, 35985, 1, 0, 100, 0),
(@PATH, 3, -525.533, -227.4132, 286.8284, 0, 609, 1, 0, 100, 0);
-- 0x202F5453C026868000116B001D2E0B73 .go xyz -525.533 -227.4132 286.8284

-- Pathing for  Entry: 39854 'TDB FORMAT' 
SET @NPC := 339793;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -558.052, `position_y`= -363.764, `position_z`= 268.7674 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -558.052, -363.764, 268.7674, 0, 182, 0, 0, 100, 0),
(@PATH, 2, -558.052, -363.764, 268.7674, 3.560472, 9953, 0, 0, 100, 0),
(@PATH, 3, -533.4236, -362.5191, 268.7673, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -511.104, -358.878, 268.7673, 0, 417, 0, 0, 100, 0),
(@PATH, 5, -511.104, -358.878, 268.7673, 5.637414, 10047, 0, 0, 100, 0),
(@PATH, 6, -537.1441, -361.3507, 268.7673, 0, 0, 0, 0, 100, 0);
-- 0x202F5453C026EB8000116B00022E0B73 .go xyz -558.052 -363.764 268.7674

-- Pathing for  Entry: 39381 'TDB FORMAT' 
SET @NPC := 339766;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -507.4653, `position_y`= -313.276, `position_z`= 268.7674 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -507.4653, -313.276, 268.7674, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -533.3299, -312.3976, 268.7674, 0, 295, 0, 0, 100, 0),
(@PATH, 3, -533.3299, -312.3976, 268.7674, 1.675516, 16078, 0, 0, 100, 0),
(@PATH, 4, -509.974, -315.316, 268.7674, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -478.2483, -320.7813, 268.7462, 0, 328, 0, 0, 100, 0),
(@PATH, 6, -478.2483, -320.7813, 268.7462, 2.80998, 15844, 0, 0, 100, 0);
-- 0x202F5453C026754000116B00022E0B73 .go xyz -507.4653 -313.276 268.7674

DELETE FROM `creature_formations` WHERE `leaderGUID`= 339766;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339766, 339766, 0, 0, 515, 0, 0),
(339766, 339765, 8, 135, 515, 3, 6),
(339766, 339761, 8, 225, 515, 3, 6);

-- Pathing for  Entry: 39381 'TDB FORMAT' 
SET @NPC := 339791;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -687.3055, `position_y`= -406.059, `position_z`= 268.7676 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -687.3055, -406.059, 268.7676, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -699.0851, -392.0938, 268.7683, 0, 202, 0, 0, 100, 0),
(@PATH, 3, -699.0851, -392.0938, 268.7683, 3.176499, 10922, 0, 0, 100, 0),
(@PATH, 4, -685.2049, -413.5885, 268.7673, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -676.464, -423.938, 268.7678, 0, 165, 0, 0, 100, 0),
(@PATH, 6, -676.464, -423.938, 268.7678, 5.078908, 10938, 0, 0, 100, 0);
-- 0x202F5453C026754000116B0002AE0B73 .go xyz -687.3055 -406.059 268.7676

-- Pathing for  Entry: 39890 'TDB FORMAT' 
SET @NPC := 339908;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -679.882, `position_y`= -372.1337, `position_z`= 268.7679 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -679.882, -372.1337, 268.7679, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -658.8229, -353.6736, 268.7666, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -639.8733, -341.0347, 268.7674, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -658.8229, -353.6736, 268.7666, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -679.882, -372.1337, 268.7679, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -689.7066, -380.4063, 268.7683, 0, 142, 0, 0, 100, 0);
-- 0x202F5453C026F48000116B00032E0B73 .go xyz -679.882 -372.1337 268.7679

DELETE FROM `creature_formations` WHERE `leaderGUID`= 339908;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339908, 339908, 0, 0, 515, 0, 0),
(339908, 339763, 5, 0, 515, 3, 6),
(339908, 339910, 5, 45, 515, 3, 6),
(339908, 339909, 5, 90, 515, 3, 6);

-- Pathing for  Entry: 39909 'TDB FORMAT' 
SET @NPC := 340076;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -695.4045, `position_y`= -636.9028, `position_z`= 269.1182 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -695.4045, -636.9028, 269.1182, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -698.9913, -650.8663, 268.7691, 0, 7216, 0, 0, 100, 0),
(@PATH, 3, -687.0521, -687.0677, 268.7674, 0, 26046, 0, 0, 100, 0),
(@PATH, 4, -697.0104, -611.3264, 268.7641, 0, 482, 0, 0, 100, 0),
(@PATH, 5, -697.0104, -611.3264, 268.7641, 2.617994, 7531, 0, 0, 100, 0);
-- 0x202F5453C026F94000116B0001AE0B73 .go xyz -695.4045 -636.9028 269.1182

-- Pathing for  Entry: 40319 'TDB FORMAT' 
SET @GUID := 340123;
SET @NPC := 40319;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0, `position_x`= -425.7691, `position_y`= -687.3577, `position_z`= 268.2985 WHERE `guid`= @GUID;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -425.7691, -687.3577, 268.2985, 0, 25446, 0, 0, 100, 0),
(@PATH, 2, -425.7691, -687.3577, 268.2985, 2.984513, 6266, 0, 0, 100, 0),
(@PATH, 3, -450.0261, -670.7372, 269.1197, 0, 383, 0, 0, 100, 0),
(@PATH, 4, -450.0261, -670.7372, 269.1197, 1.850049, 5484, 0, 0, 100, 0);
-- 0x202F5453C0275FC000116B00002E0B73 .go xyz -425.7691 -687.3577 268.2985
