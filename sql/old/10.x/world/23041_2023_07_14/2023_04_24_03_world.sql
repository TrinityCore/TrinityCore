SET @CGUID := 850882;
SET @OGUID := 502188;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8798.09375, 794.5711669921875, 99.46814727783203125, 1.681571602821350097, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+1, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8879.544921875, 746.23614501953125, 96.85052490234375, 0.47253158688545227, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+2, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8875.609375, 747.99652099609375, 96.92919158935546875, 3.576866865158081054, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+3, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8797.06640625, 795.890625, 99.541656494140625, 3.589731216430664062, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1#
(@CGUID+4, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8883.0244140625, 741.47222900390625, 96.87177276611328125, 1.906056165695190429, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+5, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8875.2900390625, 746.92535400390625, 96.9213409423828125, 3.058384895324707031, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+6, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8876.5400390625, 745.18402099609375, 96.8824920654296875, 2.080346345901489257, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+7, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8846.1494140625, 664.04962158203125, 97.71561431884765625, 3.812569618225097656, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+8, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8879.953125, 743.93231201171875, 96.81751251220703125, 1.181711196899414062, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
(@CGUID+9, 140253, 0, 1519, 5390, '0', 11595, 0, 0, 0, -8834.8017578125, 783.1812744140625, 96.4649200439453125, 0.513175249099731445, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999); -- Darnassian Refugee (Area: The Canals - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+4, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+8, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Darnassian Refugee

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 293422, 0, 1519, 5390, '0', 11595, 0, -8877.7607421875, 746.62847900390625, 96.79808807373046875, 3.591427803039550781, 0, 0, -0.97481250762939453, 0.223025903105735778, 120, 255, 1, 48999), -- Campfire (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+1, 292771, 0, 1519, 5390, '0', 11595, 0, -8875.173828125, 747.6649169921875, 96.84838104248046875, 2.952866554260253906, 0, 0, 0.995551109313964843, 0.094223096966743469, 120, 255, 1, 48999), -- Sleeping Mat A (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+2, 292771, 0, 1519, 5390, '0', 11595, 0, -8883.2119140625, 741.27777099609375, 96.79941558837890625, 2.259133577346801757, 0, 0, 0.904227256774902343, 0.427051573991775512, 120, 255, 1, 48999), -- Sleeping Mat A (Area: The Canals - Difficulty: 0) CreateObject1
(@OGUID+3, 292774, 0, 1519, 5390, '0', 11595, 0, -8879.8212890625, 743.859375, 96.73526763916015625, 1.687471270561218261, 0, 0, 0.74713134765625, 0.664676427841186523, 120, 255, 1, 48999); -- Sleeping Mat B (Area: The Canals - Difficulty: 0) CreateObject1

-- Waypoints for CGUID+9
SET @PATH := ((@CGUID+9) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8823.207, 811.5261, 98.95956, NULL, 0),
(@PATH, 1, -8821.849, 825.2309, 98.95956, NULL, 0),
(@PATH, 2, -8821.518, 837.7014, 99.11344, NULL, 0),
(@PATH, 3, -8821.741, 849.7795, 99.15983, NULL, 0),
(@PATH, 4, -8819.639, 863.7153, 99.11344, NULL, 0),
(@PATH, 5, -8817.526, 875.4358, 98.93258, NULL, 0),
(@PATH, 6, -8818.611, 887.0746, 98.68258, NULL, 0),
(@PATH, 7, -8825.801, 900.9028, 98.48063, NULL, 0),
(@PATH, 8, -8834.411, 910.6302, 98.81559, NULL, 0),
(@PATH, 9, -8841.404, 917.5712, 100.5124, NULL, 0),
(@PATH, 10, -8844.214, 921.8871, 101.6354, NULL, 0),
(@PATH, 11, -8846.685, 926.4028, 102.2452, NULL, 0),
(@PATH, 12, -8850.978, 931.3281, 102.4424, NULL, 0),
(@PATH, 13, -8858.396, 931.059, 102.31, NULL, 0),
(@PATH, 14, -8864.974, 928.2153, 104.1025, NULL, 0),
(@PATH, 15, -8884.526, 916.9305, 109.3932, NULL, 0),
(@PATH, 16, -8892.226, 913.1302, 110.8938, NULL, 0),
(@PATH, 17, -8898.082, 915.4011, 111.8998, NULL, 0),
(@PATH, 18, -8902.683, 923.2639, 114.4177, NULL, 0),
(@PATH, 19, -8908.132, 931.8455, 116.6109, NULL, 0),
(@PATH, 20, -8915.859, 944.7083, 117.4827, NULL, 0),
(@PATH, 21, -8925.009, 949.4948, 117.4647, NULL, 0),
(@PATH, 22, -8936.054, 949.5191, 117.3027, NULL, 0),
(@PATH, 23, -8957.993, 955.2031, 117.656, NULL, 0),
(@PATH, 24, -8973.264, 958.1493, 117.3336, NULL, 0),
(@PATH, 25, -8987.072, 960.3916, 115.5421, NULL, 0),
(@PATH, 26, -8996.411, 958.8004, 113.1536, NULL, 0),
(@PATH, 27, -9002.863, 956.25, 111.4323, NULL, 0),
(@PATH, 28, -9007.279, 950.8785, 110.1642, NULL, 0),
(@PATH, 29, -9010.551, 942.7448, 109.3073, NULL, 0),
(@PATH, 30, -9013.837, 933.6893, 108.4323, NULL, 0),
(@PATH, 31, -9014.435, 923.7795, 107.6785, NULL, 0),
(@PATH, 32, -9012.018, 913.9496, 106.7939, NULL, 0),
(@PATH, 33, -9006.982, 906.2379, 106.4324, NULL, 0),
(@PATH, 34, -8994.891, 897.2066, 105.7421, NULL, 0),
(@PATH, 35, -8986.899, 891.2083, 105.7833, NULL, 0),
(@PATH, 36, -8983.212, 887.059, 105.8882, NULL, 0),
(@PATH, 37, -8977.363, 880.0278, 106.5682, NULL, 0),
(@PATH, 38, -8975.614, 875.816, 106.6895, NULL, 0),
(@PATH, 39, -8976.271, 867.6389, 106.8163, NULL, 0),
(@PATH, 40, -8976.366, 859.0886, 106.2209, NULL, 0),
(@PATH, 41, -8977.896, 850.2882, 105.6643, NULL, 0),
(@PATH, 42, -8982.188, 844.007, 105.7448, NULL, 0),
(@PATH, 43, -8989.25, 836.5538, 105.8355, NULL, 0),
(@PATH, 44, -8993.067, 830.2327, 105.5081, NULL, 0),
(@PATH, 45, -8994.497, 823.5313, 105.0306, NULL, 0),
(@PATH, 46, -8993.06, 813.1371, 103.8971, NULL, 0),
(@PATH, 47, -8990.667, 804.467, 103.2317, NULL, 0),
(@PATH, 48, -8985.636, 791.4583, 100.1733, NULL, 0),
(@PATH, 49, -8974.384, 779.0729, 96.78595, NULL, 0),
(@PATH, 50, -8965.111, 773.8004, 95.18354, NULL, 0),
(@PATH, 51, -8952.571, 771.1684, 92.32258, NULL, 0),
(@PATH, 52, -8937.104, 772.8611, 89.25166, NULL, 0),
(@PATH, 53, -8924.911, 779.6684, 87.56687, NULL, 0),
(@PATH, 54, -8913.481, 788.8871, 87.43955, NULL, 0),
(@PATH, 55, -8908.639, 789.3438, 87.80674, NULL, 0),
(@PATH, 56, -8905.071, 785.7535, 88.46152, NULL, 0),
(@PATH, 57, -8895.395, 772.441, 91.233, NULL, 0),
(@PATH, 58, -8890.278, 765.7917, 93.10377, NULL, 0),
(@PATH, 59, -8883.455, 756.3646, 95.95631, NULL, 0),
(@PATH, 60, -8879.966, 754.6545, 96.3108, NULL, 0),
(@PATH, 61, -8872.397, 760.2101, 96.9358, NULL, 0),
(@PATH, 62, -8862.462, 767.5643, 96.86636, NULL, 0),
(@PATH, 63, -8846.049, 776.8489, 96.11636, NULL, 0),
(@PATH, 64, -8833.654, 783.8281, 96.49136, NULL, 0),
(@PATH, 65, -8827.603, 789.9496, 96.84409, NULL, 0),
(@PATH, 66, -8823.927, 800.5504, 97.77573, NULL, 0);

UPDATE `creature` SET `position_x`= -8823.207, `position_y`= 811.5261, `position_z`= 98.95956, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+9, @PATH, 1);
