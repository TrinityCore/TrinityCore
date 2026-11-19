SET @WOD_CGUID := 460994;
SET @LEG_CGUID := 652133;

-- Creature (Warlords of Draenor)
DELETE FROM `creature` WHERE `guid` BETWEEN @WOD_CGUID+0 AND @WOD_CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@WOD_CGUID+0, 73637, 0, 1519, 5397, '0', 0, 0, 0, 0, -8020.662109375, 730.62152099609375, 72.1986083984375, 3.878619194030761718, 120, 0, 0, 11292, 0, 0, 0, 0, 50504), -- Butterflies (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@WOD_CGUID+1, 88070, 0, 1519, 5397, '0', 0, 0, 0, 0, -8065.1162109375, 735.36456298828125, 67.4010467529296875, 2.279862403869628906, 120, 0, 0, 112919, 0, 0, 0, 0, 50504), -- Gardener Flin (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@WOD_CGUID+2, 88080, 0, 1519, 5397, '0', 0, 0, 0, 0, -8099.5498046875, 729.408935546875, 67.4694366455078125, 1.85620880126953125, 120, 0, 0, 112919, 0, 0, 0, 0, 50504), -- William Henry (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@WOD_CGUID+3, 88081, 0, 1519, 5397, '0', 0, 0, 0, 0, -8102.71630859375, 729.98858642578125, 67.3259429931640625, 1.503429770469665527, 120, 0, 0, 112919, 0, 0, 0, 0, 50504), -- Lilian Mae (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@WOD_CGUID+4, 88067, 0, 1519, 5397, '0', 0, 0, 0, 1, -8090.1796875, 754.40350341796875, 67.37990570068359375, 0.408136248588562011, 120, 0, 0, 112919, 0, 0, 0, 0, 50504), -- Landscaper Ed (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@WOD_CGUID+5, 73636, 0, 1519, 5397, '0', 0, 0, 0, 0, -8015.9287109375, 730.9698486328125, 73.25893402099609375, 3.67430734634399414, 120, 0, 0, 27, 0, 0, 0, 0, 50504); -- Jasmine (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

-- Creature (Legion)
DELETE FROM `creature` WHERE `guid` BETWEEN @LEG_CGUID+0 AND @LEG_CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@LEG_CGUID+0, 112694, 0, 1519, 5397, '0', 0, 0, 0, 0, -8092.728515625, 725.77606201171875, 67.706024169921875, 3.385909795761108398, 120, 0, 0, 5647, 0, 0, 0, 0, 50504), -- Cat (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@LEG_CGUID+1, 112686, 0, 1519, 5397, '0', 0, 0, 0, 0, -8044.4130859375, 709.87860107421875, 70.74990081787109375, 3.170430898666381835, 120, 3, 0, 5647, 0, 1, 0, 0, 50504), -- Dog (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@LEG_CGUID+2, 112694, 0, 1519, 5397, '0', 0, 0, 0, 0, -7996.875, 777.7264404296875, 68.72701263427734375, 1.570796370506286621, 120, 0, 0, 5647, 0, 0, 0, 0, 50504), -- Cat (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@LEG_CGUID+3, 112698, 0, 1519, 5397, '0', 0, 0, 0, 0, -8044.5029296875, 853.42059326171875, 67.06018829345703125, 4.156895637512207031, 120, 0, 0, 5647, 0, 0, 0, 0, 50504), -- Cat (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@LEG_CGUID+4, 112698, 0, 1519, 5397, '0', 0, 0, 0, 0, -8154.7353515625, 838.7779541015625, 74.265625, 0.46364760398864746, 120, 0, 0, 5647, 0, 0, 0, 0, 50504), -- Cat (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@LEG_CGUID+5, 112694, 0, 1519, 5397, '0', 0, 0, 0, 0, -8043.943359375, 700.2349853515625, 77.71527862548828125, 1.53862929344177246, 120, 3, 0, 5647, 0, 1, 0, 0, 50504); -- Cat (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (88067 /*88067 (Landscaper Ed)*/, 88070 /*88070 (Gardener Flin)*/, 73637 /*73637 (Butterflies)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(88067, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 88067 (Landscaper Ed)
(88070, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 88070 (Gardener Flin)
(73637, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 73637 (Butterflies)

-- Waypoints for CGUID+3
DELETE FROM `creature_formations` WHERE `leaderGUID` = (@WOD_CGUID+3);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@WOD_CGUID+3, @WOD_CGUID+3, 0, 0, 515, 0, 0),
(@WOD_CGUID+3, @WOD_CGUID+2, 3, 0, 515, 0, 0);

SET @PATH := ((@WOD_CGUID+3) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -8071.755, 776.0191, 67.46336, NULL, 0, 1),
(@PATH, 1, -8063.747, 781.7049, 67.75671, NULL, 0, 1),
(@PATH, 2, -8057.63, 791.2361, 67.39831, NULL, 0, 1),
(@PATH, 3, -8063.427, 799.2917, 67.45654, NULL, 0, 1),
(@PATH, 4, -8069.434, 802.1771, 67.28651, NULL, 0, 1),
(@PATH, 5, -8074.533, 787.4305, 67.64644, NULL, 0, 1),
(@PATH, 6, -8072.12, 782.2309, 67.60989, NULL, 0, 1),
(@PATH, 7, -8066.639, 777.3489, 67.61903, NULL, 0, 1),
(@PATH, 8, -8056.139, 776.9739, 67.88746, NULL, 0, 1),
(@PATH, 9, -8053.053, 764.5762, 67.44901, NULL, 0, 1),
(@PATH, 10, -8055.686, 757.184, 67.01964, NULL, 0, 1),
(@PATH, 11, -8061.21, 751.5452, 66.99809, NULL, 0, 1),
(@PATH, 12, -8068.075, 747.3871, 67.06148, NULL, 0, 1),
(@PATH, 13, -8077.96, 744, 67.15141, NULL, 0, 1),
(@PATH, 14, -8085.188, 739.3004, 67.74531, NULL, 0, 1),
(@PATH, 15, -8090.776, 727.7621, 67.85441, NULL, 0, 1),
(@PATH, 16, -8092.566, 722.2465, 67.65373, NULL, 0, 1),
(@PATH, 17, -8098.354, 719.4913, 67.36842, NULL, 0, 1),
(@PATH, 18, -8102.54, 732.6024, 67.33774, NULL, 0, 1),
(@PATH, 19, -8101.21, 739.9323, 67.34934, NULL, 0, 1),
(@PATH, 20, -8106.295, 745.3976, 67.21061, NULL, 0, 1),
(@PATH, 21, -8112.405, 749.0399, 67.17329, NULL, 0, 1),
(@PATH, 22, -8113.488, 760.1163, 67.28434, NULL, 0, 1),
(@PATH, 23, -8101.842, 759.1736, 67.28434, NULL, 0, 1),
(@PATH, 24, -8096.268, 755.6268, 67.28435, NULL, 0, 1),
(@PATH, 25, -8091.54, 765.6719, 67.28464, NULL, 0, 1),
(@PATH, 26, -8095.387, 770.5799, 67.28455, NULL, 0, 1),
(@PATH, 27, -8101.141, 776.2153, 67.28434, NULL, 0, 1),
(@PATH, 28, -8095.497, 783.9983, 67.28434, NULL, 0, 1),
(@PATH, 29, -8084.575, 783, 67.35561, NULL, 0, 1),
(@PATH, 30, -8080.068, 778.2118, 67.38488, NULL, 0, 1),
(@PATH, 31, -8076.231, 768.5121, 67.25999, NULL, 0, 1),
(@PATH, 32, -8078.988, 760.3577, 67.23575, NULL, 0, 1),
(@PATH, 33, -8076.549, 751.8004, 67.21597, NULL, 0, 1),
(@PATH, 34, -8067.772, 749.8038, 67.03041, NULL, 0, 1),
(@PATH, 35, -8064.45, 759.6215, 67.09222, NULL, 0, 1),
(@PATH, 36, -8070.781, 765.8837, 67.2102, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -8071.755, `position_y`= 776.0191, `position_z`= 67.46336, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @WOD_CGUID+3;
DELETE FROM `creature_addon` WHERE `guid`= @WOD_CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@WOD_CGUID+3, @PATH, 1);
