SET @CGUID := 850941;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8597.0087890625, 508.692718505859375, 104.2916183471679687, 2.03877878189086914, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+1, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8602.826171875, 510.328125, 104.2916183471679687, 0.10048425942659378, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+2, 140403, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8600.404296875, 510.14410400390625, 104.2916183471679687, 0.378923088312149047, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Displaced Gilnean Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+3, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8598.1923828125, 506.630218505859375, 104.2916183471679687, 1.594726920127868652, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+4, 140407, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8598.314453125, 510.807281494140625, 104.2916183471679687, 4.084970474243164062, 120, 0, 0, 17621, 0, 0, 0, 0, 0, 49343), -- Stormwind City Clerk (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+5, 140403, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8599.3076171875, 508.149322509765625, 104.2916183471679687, 1.053499102592468261, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Displaced Gilnean Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+6, 140403, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8601.36328125, 511.973968505859375, 104.2916183471679687, 5.93451547622680664, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Displaced Gilnean Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+7, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8717.244140625, 505.270294189453125, 96.26551055908203125, 5.228531360626220703, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+8, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8649.126953125, 411.052093505859375, 102.7174072265625, 2.28712320327758789, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+9, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8650.0849609375, 412.388885498046875, 102.72137451171875, 4.941145896911621093, 120, 0, 0, 119, 0, 0, 0, 0, 0, 49343); -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''); -- Darnassian Refugee

-- Waypoints for CGUID+7
SET @PATH := ((@CGUID+7) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8695.129, 477.6719, 95.49294, NULL, 0),
(@PATH, 1, -8696.893, 471.75, 95.57046, NULL, 0),
(@PATH, 2, -8701.759, 466.9722, 96.12107, NULL, 0),
(@PATH, 3, -8708.558, 461.0677, 96.85646, NULL, 0),
(@PATH, 4, -8715.837, 451.0347, 97.26711, NULL, 0),
(@PATH, 5, -8719.191, 434.3672, 97.76711, NULL, 0),
(@PATH, 6, -8724.064, 420.3073, 97.94579, NULL, 0),
(@PATH, 7, -8724.922, 409.5538, 97.76757, NULL, 0),
(@PATH, 8, -8719.696, 405.0538, 97.85046, NULL, 0),
(@PATH, 9, -8706.931, 403.6476, 100.0511, NULL, 0),
(@PATH, 10, -8695.981, 398.75, 101.6938, NULL, 0),
(@PATH, 11, -8685.014, 396.9965, 102.3116, NULL, 0),
(@PATH, 12, -8679.481, 399.3663, 103.1978, NULL, 0),
(@PATH, 13, -8669.089, 407.7118, 103.5677, NULL, 0),
(@PATH, 14, -8657.772, 416.2222, 102.728, NULL, 0),
(@PATH, 15, -8651.08, 421.5365, 102.1079, NULL, 0),
(@PATH, 16, -8643.799, 429.9132, 101.5807, NULL, 0),
(@PATH, 17, -8638.429, 438.6996, 102.2018, NULL, 0),
(@PATH, 18, -8634.88, 447.8125, 102.5006, NULL, 0),
(@PATH, 19, -8635.17, 457.007, 102.3756, NULL, 0),
(@PATH, 20, -8636.816, 464.7326, 102.3756, NULL, 0),
(@PATH, 21, -8641.882, 472.7014, 102.6313, NULL, 0),
(@PATH, 22, -8644.913, 477.4774, 102.6313, NULL, 0),
(@PATH, 23, -8642.698, 481.1701, 102.6313, NULL, 0),
(@PATH, 24, -8632.768, 488.8958, 102.6172, NULL, 0),
(@PATH, 25, -8616.739, 501.566, 103.1385, NULL, 0),
(@PATH, 26, -8611.013, 507.0972, 103.6292, NULL, 0),
(@PATH, 27, -8610.969, 511.2257, 103.7674, NULL, 0),
(@PATH, 28, -8617.31, 518.5625, 103.2635, NULL, 0),
(@PATH, 29, -8628.604, 530.6042, 101.1436, NULL, 0),
(@PATH, 30, -8641.783, 543.6077, 99.00242, NULL, 0),
(@PATH, 31, -8654.677, 551.3646, 97.13596, NULL, 0),
(@PATH, 32, -8665.066, 552.9983, 97.03342, NULL, 0),
(@PATH, 33, -8669.731, 551.3472, 97.28925, NULL, 0),
(@PATH, 34, -8673.436, 549.8854, 97.3885, NULL, 0),
(@PATH, 35, -8684.743, 544.1389, 97.77937, NULL, 0),
(@PATH, 36, -8696.864, 533.6302, 97.91535, NULL, 0),
(@PATH, 37, -8709.993, 522.5677, 97.50153, NULL, 0),
(@PATH, 38, -8719.549, 515.0695, 96.85505, NULL, 0),
(@PATH, 39, -8720.297, 510.6424, 96.6385, NULL, 0),
(@PATH, 40, -8716.375, 503.7379, 96.16608, NULL, 0),
(@PATH, 41, -8705.341, 489.7604, 95.47239, NULL, 0);

UPDATE `creature` SET `position_x`= -8695.129, `position_y`= 477.6719, `position_z`= 95.49294, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+7, @PATH, 1);
