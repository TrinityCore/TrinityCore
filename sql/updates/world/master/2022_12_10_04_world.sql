SET @CGUID := 396612;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4046.663330078125, 6348.13720703125, 13.20008659362792968, 1.936677932739257812, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73104 - Citizen Costume)
(@CGUID+1, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4048.8056640625, 6351.314453125, 13.20008659362792968, 5.706589698791503906, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+2, 55348, 974, 5861, 5870, '0', 0, 0, 0, 0, -4027.979248046875, 6338.5556640625, 13.20008563995361328, 5.996942520141601562, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73815 - Citizen Costume)
(@CGUID+3, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4046.467041015625, 6351.80908203125, 13.20008659362792968, 4.554671287536621093, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+4, 55348, 974, 5861, 5870, '0', 0, 0, 0, 0, -4024.364501953125, 6339.2490234375, 13.20009040832519531, 3.659704208374023437, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73815 - Citizen Costume)
(@CGUID+5, 55348, 974, 5861, 5870, '0', 0, 0, 0, 0, -4026.935791015625, 6336.40087890625, 13.20008468627929687, 1.261948466300964355, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Horde Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 71084 - Citizen Costume)
(@CGUID+6, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4018.98779296875, 6366.7119140625, 13.20009040832519531, 4.435286998748779296, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+7, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4018.265625, 6363.1025390625, 13.20009136199951171, 2.098049402236938476, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73809 - Citizen Costume)
(@CGUID+8, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4021.135498046875, 6365.6484375, 13.20009040832519531, 5.983478546142578125, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+9, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4085.885498046875, 6320.24462890625, 11.04891586303710937, 3.857727289199829101, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73810 - Citizen Costume)
(@CGUID+10, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4088.007080078125, 6318.6240234375, 11.74756717681884765, 1.196440577507019042, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 70764 - Citizen Costume)
(@CGUID+11, 55347, 974, 5861, 5870, '0', 0, 0, 0, 0, -4087.994873046875, 6321.36962890625, 11.16493034362792968, 5.009645462036132812, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Alliance Citizen (Area: The Darkmoon Faire - Difficulty: 0) (Auras: 73811 - Citizen Costume)
(@CGUID+12, 68402, 974, 5861, 5870, '0', 0, 0, 0, 1, -4058.213623046875, 6331.0244140625, 11.71875, 4.511098861694335937, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 46924), -- Kae Ti (Area: The Darkmoon Faire - Difficulty: 0)
(@CGUID+13, 68407, 974, 5861, 5870, '0', 0, 0, 0, 0, -4047.119873046875, 6341.11669921875, 13.01276016235351562, 4.00434112548828125, 120, 0, 0, 27, 0, 0, 0, 0, 0, 46924); -- "Olive" Ya (Area: The Darkmoon Faire - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73104'), -- Alliance Citizen - 73104 - Citizen Costume
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73815'), -- Horde Citizen - 73815 - Citizen Costume
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73815'), -- Horde Citizen - 73815 - Citizen Costume
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, 0, '71084'), -- Horde Citizen - 71084 - Citizen Costume
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73809'), -- Alliance Citizen - 73809 - Citizen Costume
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, 0, '70764'), -- Alliance Citizen - 70764 - Citizen Costume
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, 0, '73810'), -- Alliance Citizen - 73810 - Citizen Costume
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, 0, '70764'); -- Alliance Citizen - 70764 - Citizen Costume

-- Waypoints for CGUID+13
SET @PATH := (@CGUID+13) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4017.691, 6336.815, 13.16664, NULL, 0),
(@PATH, 1, -4028.326, 6331.984, 13.19014, NULL, 0),
(@PATH, 2, -4035.635, 6331.594, 13.11833, NULL, 0),
(@PATH, 3, -4041.825, 6334.296, 13.16664, NULL, 0),
(@PATH, 4, -4046.74, 6336.051, 13.16664, NULL, 0),
(@PATH, 5, -4049.885, 6333.23, 12.69475, NULL, 0),
(@PATH, 6, -4053.911, 6329.064, 11.22209, NULL, 0),
(@PATH, 7, -4055.25, 6324.245, 11.36833, NULL, 0),
(@PATH, 8, -4047.262, 6315.127, 11.4251, NULL, 0),
(@PATH, 9, -4037.238, 6311.301, 13.53691, NULL, 0),
(@PATH, 10, -4033.38, 6308.745, 13.49333, NULL, 0),
(@PATH, 11, -4034.019, 6304.787, 13.46574, NULL, 0),
(@PATH, 12, -4037.47, 6303.75, 12.59123, NULL, 0),
(@PATH, 13, -4041.148, 6305.401, 11.57817, NULL, 0),
(@PATH, 14, -4048.965, 6312.557, 10.44377, NULL, 0),
(@PATH, 15, -4054.491, 6318.771, 10.83183, NULL, 0),
(@PATH, 16, -4056.321, 6324.629, 11.31499, NULL, 0),
(@PATH, 17, -4054.177, 6329.696, 11.36943, NULL, 0),
(@PATH, 18, -4050.306, 6334.001, 12.61061, NULL, 0),
(@PATH, 19, -4047.526, 6337.846, 13.16664, NULL, 0),
(@PATH, 20, -4038.274, 6342.155, 13.16664, NULL, 0),
(@PATH, 21, -4032.359, 6340.044, 13.16664, NULL, 0),
(@PATH, 22, -4026.103, 6340.779, 13.16664, NULL, 0),
(@PATH, 23, -4021.148, 6345.004, 13.16664, NULL, 0),
(@PATH, 24, -4018.573, 6350.762, 13.16664, NULL, 0),
(@PATH, 25, -4019.752, 6357.356, 13.16664, NULL, 0),
(@PATH, 26, -4024.097, 6362.542, 13.16664, NULL, 0),
(@PATH, 27, -4029.814, 6364.646, 13.16664, NULL, 0),
(@PATH, 28, -4036.738, 6363.67, 13.16664, NULL, 0),
(@PATH, 29, -4040.858, 6359.434, 13.16664, NULL, 0),
(@PATH, 30, -4043.59, 6352.838, 13.16664, NULL, 0),
(@PATH, 31, -4041.915, 6347.196, 13.16664, NULL, 0),
(@PATH, 32, -4050.728, 6336.908, 12.87465, NULL, 0),
(@PATH, 33, -4056.141, 6330.427, 11.4572, NULL, 0),
(@PATH, 34, -4059.637, 6328.071, 11.20537, NULL, 0),
(@PATH, 35, -4065.585, 6329.223, 10.32182, NULL, 0),
(@PATH, 36, -4070.446, 6334.002, 10.31155, NULL, 0),
(@PATH, 37, -4083.464, 6347.912, 11.05887, NULL, 0),
(@PATH, 38, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 39, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 40, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 41, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 42, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 43, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 44, -4089.753, 6352.374, 11.53518, NULL, 0),
(@PATH, 45, -4094.649, 6354.988, 11.6387, NULL, 0),
(@PATH, 46, -4104.555, 6359.779, 11.07596, NULL, 0),
(@PATH, 47, -4106.196, 6361.928, 11.99539, NULL, 0),
(@PATH, 48, -4102.519, 6371.447, 13.23885, NULL, 0),
(@PATH, 49, -4097.8, 6374.787, 13.24175, NULL, 0),
(@PATH, 50, -4099.963, 6378.29, 13.24175, NULL, 0),
(@PATH, 51, -4104.144, 6379.275, 13.23885, NULL, 0),
(@PATH, 52, -4106.068, 6372.806, 13.23885, NULL, 0),
(@PATH, 53, -4109.181, 6363.05, 12.05838, NULL, 0),
(@PATH, 54, -4107.097, 6359.782, 10.996, NULL, 0),
(@PATH, 55, -4092.875, 6352.223, 11.10611, NULL, 0),
(@PATH, 56, -4084.425, 6346.792, 10.61233, NULL, 0),
(@PATH, 57, -4071.79, 6333.202, 10.02347, NULL, 0),
(@PATH, 58, -4065.653, 6328.105, 10.42851, NULL, 0),
(@PATH, 59, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 60, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 61, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 62, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 63, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 64, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 65, -4059.219, 6327.222, 11.19756, NULL, 0),
(@PATH, 66, -4056.253, 6330.985, 11.52409, NULL, 0),
(@PATH, 67, -4051.106, 6337.88, 12.89992, NULL, 0),
(@PATH, 68, -4052.497, 6344.082, 13.16664, NULL, 0),
(@PATH, 69, -4054.438, 6351.719, 13.16664, NULL, 0),
(@PATH, 70, -4052.939, 6357.502, 13.16664, NULL, 0),
(@PATH, 71, -4047.134, 6367.213, 13.24175, NULL, 0),
(@PATH, 72, -4042.03, 6372.264, 13.24175, NULL, 0),
(@PATH, 73, -4035.177, 6374.056, 13.24175, NULL, 0),
(@PATH, 74, -4027.082, 6374.905, 13.23439, NULL, 0),
(@PATH, 75, -4019.608, 6374.435, 13.23439, NULL, 0),
(@PATH, 76, -4013.865, 6370.941, 13.23439, NULL, 0),
(@PATH, 77, -4010.34, 6365.042, 13.16664, NULL, 0),
(@PATH, 78, -4008.863, 6357.522, 13.16664, NULL, 0),
(@PATH, 79, -4009.24, 6350.943, 13.16664, NULL, 0),
(@PATH, 80, -4011.603, 6345.24, 13.16664, NULL, 0);

UPDATE `creature` SET `position_x`= -4017.691, `position_y`= 6336.815, `position_z`= 13.16664, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+13;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+13, @PATH, 1);
