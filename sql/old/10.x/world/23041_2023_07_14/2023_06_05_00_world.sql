SET @DF_CGUID := 9003914;
SET @WOD_CGUID := 460990;

-- Creature DF
DELETE FROM `creature` WHERE `guid` = @DF_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@DF_CGUID+0, 199149, 0, 1519, 1519, '0', 0, 0, 0, 0, -8706.0322265625, 315.200103759765625, 101.2873916625976562, 3.182098627090454101, 120, 0, 0, 112919, 100, 0, 0, 0, 0, 49801); -- Sh'dorana (Area: Stormwind City - Difficulty: 0) CreateObject1 (Auras: 186810 - Stealth)

-- Creature WoD
DELETE FROM `creature` WHERE `guid` BETWEEN @WOD_CGUID+0 AND @WOD_CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@WOD_CGUID+0, 87501, 0, 1519, 5149, '0', 0, 0, 0, 1, -8685.2880859375, 454.505218505859375, 100.7089385986328125, 5.631696224212646484, 120, 0, 0, 338757, 0, 0, 0, 0, 0, 49801), -- Paulie (Area: Old Town - Difficulty: 0) CreateObject1
(@WOD_CGUID+1, 87503, 0, 1519, 5149, '0', 0, 0, 0, 0, -8682.0361328125, 455.057281494140625, 100.2331695556640625, 4.201167583465576171, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 49801); -- Champion's Treadblade (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` IN (87501 /*87501 (Paulie)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(87501, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 87501 (Paulie)

UPDATE `creature_template` SET `faction`=12, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=199149; -- Sh'dorana

-- remove wrong aura
UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 35845;

 -- Sh'dorana smart ai
SET @ENTRY := 199149;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 6, 0, 0, 11, 186810, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 6 - Self: Cast spell 186810 with flags triggered on Self'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 33, 0, 0, 28, 186810, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 33 - Self: Remove aura due to spell 186810');

-- Waypoints for Sh'dorana
SET @PATH := ((@DF_CGUID+0) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8715.694, 327.5, 101.2874, NULL, 0),
(@PATH, 1, -8725.366, 335.5382, 100.2065, NULL, 0),
(@PATH, 2, -8730.524, 343.0104, 100.853, NULL, 0),
(@PATH, 3, -8731.917, 349.7882, 101.0043, NULL, 0),
(@PATH, 4, -8737.738, 356.8698, 101.5553, NULL, 0),
(@PATH, 5, -8736.888, 369.4149, 100.9727, NULL, 0),
(@PATH, 6, -8736.464, 375.599, 101.1705, NULL, 14100),
(@PATH, 7, -8735.62, 370.8507, 100.8585, NULL, 0),
(@PATH, 8, -8734.884, 367.9601, 100.8907, NULL, 0),
(@PATH, 9, -8731.851, 364.2274, 101.0138, NULL, 0),
(@PATH, 10, -8730.842, 360.4097, 101.3312, NULL, 0),
(@PATH, 11, -8728.279, 356.4132, 101.2925, NULL, 0),
(@PATH, 12, -8726.936, 348.5234, 101.2543, NULL, 0),
(@PATH, 13, -8727.651, 343.2413, 101.0003, NULL, 0),
(@PATH, 14, -8730.377, 336.0573, 100.0043, NULL, 0),
(@PATH, 15, -8737.188, 333.9462, 100.6936, NULL, 0),
(@PATH, 16, -8740.901, 333.6493, 100.9185, NULL, 0),
(@PATH, 17, -8744.051, 327.0295, 100.7649, NULL, 0),
(@PATH, 18, -8745.833, 318.1129, 100.0015, NULL, 0),
(@PATH, 19, -8750.616, 316.3195, 100.9939, NULL, 0),
(@PATH, 20, -8754.915, 313.5087, 101.2064, NULL, 0),
(@PATH, 21, -8759.674, 313.283, 101.3899, NULL, 0),
(@PATH, 22, -8767.436, 314.7517, 101.2577, NULL, 13839),
(@PATH, 23, -8760.477, 315.5723, 101.2649, NULL, 0),
(@PATH, 24, -8754.899, 315.7847, 100.9333, NULL, 0),
(@PATH, 25, -8751.364, 317.8715, 100.8899, NULL, 0),
(@PATH, 26, -8747.493, 321.7986, 100.4672, NULL, 0),
(@PATH, 27, -8742.747, 320.651, 99.7073, NULL, 0),
(@PATH, 28, -8737.172, 320.834, 99.60073, NULL, 0),
(@PATH, 29, -8730.207, 323.6667, 99.51249, NULL, 0),
(@PATH, 30, -8728.384, 327.1111, 99.82841, NULL, 0),
(@PATH, 31, -8723.701, 330.1979, 100.0125, NULL, 0),
(@PATH, 32, -8718.599, 331.0955, 101.2874, NULL, 0),
(@PATH, 33, -8712.285, 327.5451, 101.2874, NULL, 0),
(@PATH, 34, -8703.288, 320.2257, 101.2874, NULL, 0),
(@PATH, 35, -8700.092, 316.3229, 101.2874, NULL, 0),
(@PATH, 36, -8694.518, 318.1163, 101.6238, NULL, 0),
(@PATH, 37, -8695.399, 321.2292, 103.3961, NULL, 0),
(@PATH, 38, -8695.596, 326.7292, 106.7132, NULL, 0),
(@PATH, 39, -8696.531, 328.9861, 108.1854, NULL, 0),
(@PATH, 40, -8698.566, 334.4254, 108.4749, NULL, 0),
(@PATH, 41, -8702.361, 334.2865, 108.4749, NULL, 0),
(@PATH, 42, -8705.547, 332.9688, 108.4749, NULL, 0),
(@PATH, 43, -8707.88, 327.5174, 108.4749, NULL, 0),
(@PATH, 44, -8707.79, 325.1302, 108.4749, NULL, 0),
(@PATH, 45, -8710.308, 320.2552, 108.4749, NULL, 0),
(@PATH, 46, -8715.867, 316.2034, 108.4749, NULL, 0),
(@PATH, 47, -8723.366, 311.6302, 108.4749, NULL, 0),
(@PATH, 48, -8727.207, 310.3021, 108.4749, NULL, 6770),
(@PATH, 49, -8717.063, 312.8438, 108.4749, NULL, 0),
(@PATH, 50, -8717.186, 315.3993, 108.4749, NULL, 0),
(@PATH, 51, -8712.632, 319.2413, 108.4749, NULL, 0),
(@PATH, 52, -8709.786, 321.3333, 108.4749, NULL, 0),
(@PATH, 53, -8706.219, 324.9531, 108.4749, NULL, 0),
(@PATH, 54, -8705.63, 330.4549, 108.4749, NULL, 0),
(@PATH, 55, -8704.801, 333.6528, 108.4749, NULL, 0),
(@PATH, 56, -8698.25, 335.1493, 108.4749, NULL, 0),
(@PATH, 57, -8695.926, 328.724, 107.9518, NULL, 0),
(@PATH, 58, -8696.113, 326.4931, 106.6143, NULL, 0),
(@PATH, 59, -8695.688, 320.7326, 103.1487, NULL, 0),
(@PATH, 60, -8695.976, 315.6076, 101.2874, NULL, 0),
(@PATH, 61, -8706.601, 315.1771, 101.2874, NULL, 0),
(@PATH, 62, -8709.969, 318.8663, 101.2874, NULL, 0);

UPDATE `creature` SET `position_x`= -8715.694, `position_y`= 327.5, `position_z`= 101.2874, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @DF_CGUID+0;
DELETE FROM `creature_addon` WHERE `guid`= @DF_CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@DF_CGUID+0, @PATH, 1);
