SET @CGUID := 10005851;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233915, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2773.9990234375, -2147.60498046875, 324.26654052734375, 2.458046913146972656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 233915, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2778.75, -2004.71630859375, 311.38922119140625, 1.384116053581237792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 233915, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2769.113525390625, -2053.062744140625, 274.881866455078125, 2.780049085617065429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+3, 233915, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2757.510009765625, -1794.84033203125, 238.030853271484375, 5.995301246643066406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 233915, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2808.4951171875, -1808.382080078125, 305.470611572265625, 0.412203013896942138, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 233915, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2803.4248046875, -2037.7911376953125, 308.584228515625, 0.864016175270080566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 233915, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2865.64306640625, -2029.2178955078125, 340.656494140625, 3.121388435363769531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Isle of Dorn - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 233915, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2860.70458984375, -1888.3275146484375, 257.39666748046875, 3.164776563644409179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Isle of Dorn - Difficulty: 0) CreateObject1
(@CGUID+8, 233915, 2552, 14717, 14775, '0', 0, 0, 0, 0, 2923.045654296875, -1822.6573486328125, 250.0455474853515625, 2.752384185791015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: Storm's Watch - Difficulty: 0) CreateObject1
(@CGUID+9, 233915, 2552, 14717, 0, '0', 0, 0, 0, 0, 2776.046142578125, -2103.76513671875, 358.573486328125, 1.24205183982849121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Stormrook (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+10, 214948, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2694.091064453125, -2806.404052734375, 456.54901123046875, 0.816207289695739746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Roaming Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+11, 214948, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2502.3173828125, -2484.278564453125, 398.08538818359375, 1.686452746391296386, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Roaming Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+12, 214948, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2687.40380859375, -2352.0322265625, 373.66009521484375, 4.459172725677490234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Roaming Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 214948, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2772.780517578125, -2897.57373046875, 443.271331787109375, 3.183101177215576171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867); -- Roaming Stormrook (Area: Dornogal - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

-- Delete a duplicate gob
DELETE FROM `gameobject` WHERE `guid`= 10001358;
DELETE FROM `gameobject_addon` WHERE `guid` = 10001358;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (233915, 214948);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(233915, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 233915 (Stormrook)
(214948, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 214948 (Roaming Stormrook)

-- Template
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=233915; -- Stormrook

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=0x30000000, `VerifiedBuild`=58867 WHERE (`Entry`=233915 AND `DifficultyID`=0); -- 233915 (Stormrook) - CanSwim, Floating

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=121824;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121824, 1.381400585174560546, 0, 0, 58867);

UPDATE `creature_model_info` SET `VerifiedBuild`=58867 WHERE `DisplayID` IN (121821, 121822, 121823);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 233915;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.9883, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2769.649, -2058.8323, 324.26654, NULL, 0),
(@PATH, 1, 2789.1145, -2045.826, 324.26654, NULL, 0),
(@PATH, 2, 2812.0754, -2041.2588, 324.26654, NULL, 0),
(@PATH, 3, 2835.0364, -2045.826, 324.26654, NULL, 0),
(@PATH, 4, 2854.502, -2058.8323, 324.26654, NULL, 0),
(@PATH, 5, 2867.5083, -2078.2979, 324.26654, NULL, 0),
(@PATH, 6, 2872.0754, -2101.2588, 324.26654, NULL, 0),
(@PATH, 7, 2867.5083, -2124.2197, 324.26654, NULL, 0),
(@PATH, 8, 2854.502, -2143.6853, 324.26654, NULL, 0),
(@PATH, 9, 2835.0364, -2156.6917, 324.26654, NULL, 0),
(@PATH, 10, 2812.0754, -2161.2588, 324.26654, NULL, 0),
(@PATH, 11, 2789.1145, -2156.6917, 324.26654, NULL, 0),
(@PATH, 12, 2769.649, -2143.6853, 324.26654, NULL, 0),
(@PATH, 13, 2756.6426, -2124.2197, 324.26654, NULL, 0),
(@PATH, 14, 2752.0754, -2101.2588, 324.26654, NULL, 0),
(@PATH, 15, 2756.6426, -2078.2979, 324.26654, NULL, 0);

UPDATE `creature` SET `position_x`=2769.649, `position_y`=-2058.8323, `position_z`=324.26654, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 233915;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.9882, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2786.19, -1984.9558, 311.38925, NULL, 0),
(@PATH, 1, 2801.8635, -1967.5658, 311.38925, NULL, 0),
(@PATH, 2, 2822.9985, -1957.4976, 311.38925, NULL, 0),
(@PATH, 3, 2846.378, -1956.2839, 311.38925, NULL, 0),
(@PATH, 4, 2868.4421, -1964.1094, 311.38925, NULL, 0),
(@PATH, 5, 2885.832, -1979.7828, 311.38925, NULL, 0),
(@PATH, 6, 2895.9004, -2000.9181, 311.38925, NULL, 0),
(@PATH, 7, 2897.114, -2024.2975, 311.38925, NULL, 0),
(@PATH, 8, 2889.2886, -2046.3617, 311.38925, NULL, 0),
(@PATH, 9, 2873.615, -2063.7517, 311.38925, NULL, 0),
(@PATH, 10, 2852.4797, -2073.8198, 311.38925, NULL, 0),
(@PATH, 11, 2829.1006, -2075.0334, 311.38925, NULL, 0),
(@PATH, 12, 2807.0364, -2067.208, 311.38925, NULL, 0),
(@PATH, 13, 2789.6462, -2051.5344, 311.38925, NULL, 0),
(@PATH, 14, 2779.5781, -2030.3993, 311.38925, NULL, 0),
(@PATH, 15, 2778.3645, -2007.0199, 311.38925, NULL, 0);

UPDATE `creature` SET `position_x`=2786.19, `position_y`=-1984.9558, `position_z`=311.38925, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+2;
SET @ENTRY := 233915;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.6573, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2763.962, -2082.0173, 274.88184, NULL, 0),
(@PATH, 1, 2774.5686, -2077.624, 274.88184, NULL, 0),
(@PATH, 2, 2778.962, -2067.0173, 274.88184, NULL, 0),
(@PATH, 3, 2774.5686, -2056.4106, 274.88184, NULL, 0),
(@PATH, 4, 2763.962, -2052.0173, 274.88184, NULL, 0),
(@PATH, 5, 2753.3552, -2056.4106, 274.88184, NULL, 0),
(@PATH, 6, 2748.962, -2067.0173, 274.88184, NULL, 0),
(@PATH, 7, 2753.3552, -2077.624, 274.88184, NULL, 0);

UPDATE `creature` SET `position_x`=2763.962, `position_y`=-2082.0173, `position_z`=274.88184, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+3;
SET @ENTRY := 233915;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.6572, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2755.9558, -1794.4883, 238.03084, NULL, 0),
(@PATH, 1, 2765.7832, -1800.4235, 238.03084, NULL, 0),
(@PATH, 2, 2768.5354, -1811.5692, 238.03084, NULL, 0),
(@PATH, 3, 2762.6, -1821.3965, 238.03084, NULL, 0),
(@PATH, 4, 2751.4543, -1824.1487, 238.03084, NULL, 0),
(@PATH, 5, 2741.6272, -1818.2135, 238.03084, NULL, 0),
(@PATH, 6, 2738.875, -1807.0677, 238.03084, NULL, 0),
(@PATH, 7, 2744.81, -1797.2405, 238.03084, NULL, 0);

UPDATE `creature` SET `position_x`=2755.9558, `position_y`=-1794.4883, `position_z`=238.03084, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+4;
SET @ENTRY := 233915;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.6572, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2810.0437, -1807.8248, 305.4706, NULL, 0),
(@PATH, 1, 2821.4392, -1809.2178, 305.4706, NULL, 0),
(@PATH, 2, 2828.5122, -1818.2607, 305.4706, NULL, 0),
(@PATH, 3, 2827.1194, -1829.6565, 305.4706, NULL, 0),
(@PATH, 4, 2818.0764, -1836.7294, 305.4706, NULL, 0),
(@PATH, 5, 2806.6807, -1835.3364, 305.4706, NULL, 0),
(@PATH, 6, 2799.6077, -1826.2935, 305.4706, NULL, 0),
(@PATH, 7, 2801.0007, -1814.8978, 305.4706, NULL, 0);

UPDATE `creature` SET `position_x`=2810.0437, `position_y`=-1807.8248, `position_z`=305.4706, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+5;
SET @ENTRY := 233915;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.5449, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2803.7087, -2090.2473, 308.58423, NULL, 0),
(@PATH, 1, 2795.8909, -2076.7395, 308.58423, NULL, 0),
(@PATH, 2, 2793.8374, -2061.268, 308.58423, NULL, 0),
(@PATH, 3, 2797.8606, -2046.1882, 308.58423, NULL, 0),
(@PATH, 4, 2807.3486, -2033.7961, 308.58423, NULL, 0),
(@PATH, 5, 2820.8567, -2025.9781, 308.58423, NULL, 0),
(@PATH, 6, 2836.3281, -2023.9246, 308.58423, NULL, 0),
(@PATH, 7, 2851.4077, -2027.948, 308.58423, NULL, 0),
(@PATH, 8, 2863.8, -2037.4359, 308.58423, NULL, 0),
(@PATH, 9, 2871.618, -2050.9438, 308.58423, NULL, 0),
(@PATH, 10, 2873.6714, -2066.4155, 308.58423, NULL, 0),
(@PATH, 11, 2869.648, -2081.495, 308.58423, NULL, 0),
(@PATH, 12, 2860.1602, -2093.8872, 308.58423, NULL, 0),
(@PATH, 13, 2846.652, -2101.7053, 308.58423, NULL, 0),
(@PATH, 14, 2831.1807, -2103.7588, 308.58423, NULL, 0),
(@PATH, 15, 2816.101, -2099.7354, 308.58423, NULL, 0);

UPDATE `creature` SET `position_x`=2803.7087, `position_y`=-2090.2473, `position_z`=308.58423, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 233915;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.9884, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2822.116, -2131.633, 340.65643, NULL, 0),
(@PATH, 1, 2841.5815, -2144.6394, 340.65643, NULL, 0),
(@PATH, 2, 2864.5425, -2149.2065, 340.65643, NULL, 0),
(@PATH, 3, 2887.5034, -2144.6394, 340.65643, NULL, 0),
(@PATH, 4, 2906.969, -2131.6328, 340.65643, NULL, 0),
(@PATH, 5, 2919.9753, -2112.1675, 340.65643, NULL, 0),
(@PATH, 6, 2924.5425, -2089.2065, 340.65643, NULL, 0),
(@PATH, 7, 2919.9753, -2066.2456, 340.65643, NULL, 0),
(@PATH, 8, 2906.9688, -2046.7802, 340.65643, NULL, 0),
(@PATH, 9, 2887.5034, -2033.7738, 340.65643, NULL, 0),
(@PATH, 10, 2864.5425, -2029.2065, 340.65643, NULL, 0),
(@PATH, 11, 2841.5815, -2033.7738, 340.65643, NULL, 0),
(@PATH, 12, 2822.116, -2046.7802, 340.65643, NULL, 0),
(@PATH, 13, 2809.1096, -2066.2456, 340.65643, NULL, 0),
(@PATH, 14, 2804.5425, -2089.2065, 340.65643, NULL, 0),
(@PATH, 15, 2809.1096, -2112.1675, 340.65643, NULL, 0);

UPDATE `creature` SET `position_x`=2822.116, `position_y`=-2131.633, `position_z`=340.65643, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 233915;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.9885, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2817.0127, -1785.9156, 257.39667, NULL, 0),
(@PATH, 1, 2836.4783, -1772.9093, 257.39667, NULL, 0),
(@PATH, 2, 2859.4392, -1768.342, 257.39667, NULL, 0),
(@PATH, 3, 2882.4001, -1772.9093, 257.39667, NULL, 0),
(@PATH, 4, 2901.8657, -1785.9156, 257.39667, NULL, 0),
(@PATH, 5, 2914.872, -1805.381, 257.39667, NULL, 0),
(@PATH, 6, 2919.4392, -1828.342, 257.39667, NULL, 0),
(@PATH, 7, 2914.872, -1851.3031, 257.39667, NULL, 0),
(@PATH, 8, 2901.8657, -1870.7684, 257.39667, NULL, 0),
(@PATH, 9, 2882.4001, -1883.7748, 257.39667, NULL, 0),
(@PATH, 10, 2859.4392, -1888.342, 257.39667, NULL, 0),
(@PATH, 11, 2836.4783, -1883.7748, 257.39667, NULL, 0),
(@PATH, 12, 2817.0127, -1870.7684, 257.39667, NULL, 0),
(@PATH, 13, 2804.0063, -1851.3031, 257.39667, NULL, 0),
(@PATH, 14, 2799.4392, -1828.342, 257.39667, NULL, 0),
(@PATH, 15, 2804.0063, -1805.3811, 257.39667, NULL, 0);

UPDATE `creature` SET `position_x`=2817.0127, `position_y`=-1785.9156, `position_z`=257.39667, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 233915;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 7.5449, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2909.9536, -1757.3702, 250.04556, NULL, 0),
(@PATH, 1, 2922.9304, -1748.6993, 250.04556, NULL, 0),
(@PATH, 2, 2938.2378, -1745.6545, 250.04556, NULL, 0),
(@PATH, 3, 2953.5452, -1748.6993, 250.04556, NULL, 0),
(@PATH, 4, 2966.522, -1757.3702, 250.04556, NULL, 0),
(@PATH, 5, 2975.1929, -1770.3472, 250.04556, NULL, 0),
(@PATH, 6, 2978.2378, -1785.6545, 250.04556, NULL, 0),
(@PATH, 7, 2975.1929, -1800.9619, 250.04556, NULL, 0),
(@PATH, 8, 2966.522, -1813.9388, 250.04556, NULL, 0),
(@PATH, 9, 2953.5452, -1822.6097, 250.04556, NULL, 0),
(@PATH, 10, 2938.2378, -1825.6545, 250.04556, NULL, 0),
(@PATH, 11, 2922.9304, -1822.6097, 250.04556, NULL, 0),
(@PATH, 12, 2909.9536, -1813.9388, 250.04556, NULL, 0),
(@PATH, 13, 2901.2827, -1800.9619, 250.04556, NULL, 0),
(@PATH, 14, 2898.2378, -1785.6545, 250.04556, NULL, 0),
(@PATH, 15, 2901.2827, -1770.3472, 250.04556, NULL, 0);

UPDATE `creature` SET `position_x`=2909.9536, `position_y`=-1757.3702, `position_z`=250.04556, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Stormrook
SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 233915;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 27.9885, 'Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2773.4023, -2130.627, 358.5735, NULL, 0),
(@PATH, 1, 2774.975, -2107.269, 358.5735, NULL, 0),
(@PATH, 2, 2785.3667, -2086.291, 358.5735, NULL, 0),
(@PATH, 3, 2802.9954, -2070.8865, 358.5735, NULL, 0),
(@PATH, 4, 2825.177, -2063.401, 358.5735, NULL, 0),
(@PATH, 5, 2848.5352, -2064.9736, 358.5735, NULL, 0),
(@PATH, 6, 2869.5132, -2075.3652, 358.5735, NULL, 0),
(@PATH, 7, 2884.9177, -2092.994, 358.5735, NULL, 0),
(@PATH, 8, 2892.4033, -2115.1758, 358.5735, NULL, 0),
(@PATH, 9, 2890.8306, -2138.5337, 358.5735, NULL, 0),
(@PATH, 10, 2880.439, -2159.5117, 358.5735, NULL, 0),
(@PATH, 11, 2862.8103, -2174.9163, 358.5735, NULL, 0),
(@PATH, 12, 2840.6284, -2182.4019, 358.5735, NULL, 0),
(@PATH, 13, 2817.2705, -2180.829, 358.5735, NULL, 0),
(@PATH, 14, 2796.2925, -2170.4375, 358.5735, NULL, 0),
(@PATH, 15, 2780.888, -2152.8088, 358.5735, NULL, 0);

UPDATE `creature` SET `position_x`=2773.4023, `position_y`=-2130.627, `position_z`=358.5735, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Roaming Stormrook
SET @MOVERGUID := @CGUID+10;
SET @ENTRY := 214948;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.8015, 'Roaming Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2695.13, -2817.9153, 443.27136, NULL, 0),
(@PATH, 1, 2702.6396, -2789.6316, 443.27136, NULL, 0),
(@PATH, 2, 2720.4011, -2766.3748, 443.27136, NULL, 0),
(@PATH, 3, 2745.711, -2751.6855, 443.27136, NULL, 0),
(@PATH, 4, 2774.7153, -2747.7998, 443.27136, NULL, 0),
(@PATH, 5, 2802.9988, -2755.3096, 443.27136, NULL, 0),
(@PATH, 6, 2826.2556, -2773.0713, 443.27136, NULL, 0),
(@PATH, 7, 2840.945, -2798.3809, 443.27136, NULL, 0),
(@PATH, 8, 2844.8306, -2827.3853, 443.27136, NULL, 0),
(@PATH, 9, 2837.321, -2855.669, 443.27136, NULL, 0),
(@PATH, 10, 2819.5593, -2878.9258, 443.27136, NULL, 0),
(@PATH, 11, 2794.2495, -2893.615, 443.27136, NULL, 0),
(@PATH, 12, 2765.245, -2897.5007, 443.27136, NULL, 0),
(@PATH, 13, 2736.9617, -2889.991, 443.27136, NULL, 0),
(@PATH, 14, 2713.7048, -2872.2292, 443.27136, NULL, 0),
(@PATH, 15, 2699.0154, -2846.9197, 443.27136, NULL, 0);

UPDATE `creature` SET `position_x`=2695.13, `position_y`=-2817.9153, `position_z`=443.27136, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Roaming Stormrook
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 214948;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.8014, 'Roaming Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2556.5906, -2380.7534, 373.66006, NULL, 0),
(@PATH, 1, 2542.9138, -2354.8826, 373.66006, NULL, 0),
(@PATH, 2, 2540.1785, -2325.747, 373.66006, NULL, 0),
(@PATH, 3, 2548.801, -2297.7827, 373.66006, NULL, 0),
(@PATH, 4, 2567.4685, -2275.2466, 373.66006, NULL, 0),
(@PATH, 5, 2593.3394, -2261.5698, 373.66006, NULL, 0),
(@PATH, 6, 2622.4749, -2258.8345, 373.66006, NULL, 0),
(@PATH, 7, 2650.4392, -2267.457, 373.66006, NULL, 0),
(@PATH, 8, 2672.9753, -2286.1245, 373.66006, NULL, 0),
(@PATH, 9, 2686.652, -2311.9954, 373.66006, NULL, 0),
(@PATH, 10, 2689.3875, -2341.1309, 373.66006, NULL, 0),
(@PATH, 11, 2680.765, -2369.0952, 373.66006, NULL, 0),
(@PATH, 12, 2662.0974, -2391.6313, 373.66006, NULL, 0),
(@PATH, 13, 2636.2266, -2405.308, 373.66006, NULL, 0),
(@PATH, 14, 2607.091, -2408.0435, 373.66006, NULL, 0),
(@PATH, 15, 2579.1267, -2399.421, 373.66006, NULL, 0);

UPDATE `creature` SET `position_x`=2556.5906, `position_y`=-2380.7534, `position_z`=373.66006, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Roaming Stormrook
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 214948;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.8014, 'Roaming Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2611.0115, -2408.8967, 398.08542, NULL, 0),
(@PATH, 1, 2633.9417, -2427.078, 398.08542, NULL, 0),
(@PATH, 2, 2648.169, -2452.6501, 398.08542, NULL, 0),
(@PATH, 3, 2651.527, -2481.7202, 398.08542, NULL, 0),
(@PATH, 4, 2643.505, -2509.8628, 398.08542, NULL, 0),
(@PATH, 5, 2625.3237, -2532.7932, 398.08542, NULL, 0),
(@PATH, 6, 2599.7515, -2547.0203, 398.08542, NULL, 0),
(@PATH, 7, 2570.6814, -2550.3784, 398.08542, NULL, 0),
(@PATH, 8, 2542.5388, -2542.3564, 398.08542, NULL, 0),
(@PATH, 9, 2519.6084, -2524.1753, 398.08542, NULL, 0),
(@PATH, 10, 2505.3813, -2498.603, 398.08542, NULL, 0),
(@PATH, 11, 2502.023, -2469.5327, 398.08542, NULL, 0),
(@PATH, 12, 2510.0452, -2441.3901, 398.08542, NULL, 0),
(@PATH, 13, 2528.2263, -2418.46, 398.08542, NULL, 0),
(@PATH, 14, 2553.7986, -2404.2327, 398.08542, NULL, 0),
(@PATH, 15, 2582.869, -2400.8745, 398.08542, NULL, 0);

UPDATE `creature` SET `position_x`=2611.0115, `position_y`=-2408.8967, `position_z`=398.08542, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);

-- Path for Roaming Stormrook
SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 214948;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.8015, 'Roaming Stormrook - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2792.9749, -2796.8845, 456.549, NULL, 0),
(@PATH, 1, 2812.8398, -2818.3728, 456.549, NULL, 0),
(@PATH, 2, 2822.9692, -2845.8274, 456.549, NULL, 0),
(@PATH, 3, 2821.8213, -2875.0684, 456.549, NULL, 0),
(@PATH, 4, 2809.5708, -2901.6443, 456.549, NULL, 0),
(@PATH, 5, 2788.0825, -2921.509, 456.549, NULL, 0),
(@PATH, 6, 2760.628, -2931.6387, 456.549, NULL, 0),
(@PATH, 7, 2731.387, -2930.4907, 456.549, NULL, 0),
(@PATH, 8, 2704.811, -2918.24, 456.549, NULL, 0),
(@PATH, 9, 2684.9463, -2896.7517, 456.549, NULL, 0),
(@PATH, 10, 2674.8167, -2869.2974, 456.549, NULL, 0),
(@PATH, 11, 2675.9646, -2840.0564, 456.549, NULL, 0),
(@PATH, 12, 2688.2153, -2813.4805, 456.549, NULL, 0),
(@PATH, 13, 2709.7036, -2793.6155, 456.549, NULL, 0),
(@PATH, 14, 2737.158, -2783.486, 456.549, NULL, 0),
(@PATH, 15, 2766.399, -2784.634, 456.549, NULL, 0);

UPDATE `creature` SET `position_x`=2792.9749, `position_y`=-2796.8845, `position_z`=456.549, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 3, 1);
