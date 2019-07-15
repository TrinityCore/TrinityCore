-- 
SET @CGUID:=254322;
DELETE FROM `creature` WHERE `map`=940;
DELETE FROM `gameobject` WHERE `map`=940;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+532;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 53488, 940, 5844, 5988, 3, 169, 0, 0, 0, 4927.545, 317.8056, 101.2931, 4.223697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Crystal Vice - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+1, 55389, 940, 5844, 5988, 3, 169, 0, 0, 0, 4937.305, 267.4792, 97.73182, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Stalker Entrance (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+2, 55389, 940, 5844, 5988, 3, 169, 0, 0, 0, 4921.635, 267.3924, 97.37373, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Stalker Entrance (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+3, 54522, 940, 5844, 5988, 3, 169, 0, 0, 0, 4893.167, 222.2674, 103.6646, 5.899213, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Glowing Eyes Stalker (Area: The Crystal Vice - Difficulty: 0) (Auras: 101913 - Glowing Eyes Stalker Visual)
(@CGUID+4, 54548, 940, 5844, 5988, 3, 169, 0, 0, 0, 4926.794, 308.8177, 98.71864, 1.570796, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Thrall (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+5, 55385, 940, 5844, 5988, 3, 169, 0, 0, 0, 4905.549, 230.9375, 99.12637, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Stalker 3 (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+6, 55971, 940, 5844, 5988, 3, 169, 0, 0, 0, 3758.178, 109.2806, 275.9532, 0.9622608, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Deathwing (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 55384, 940, 5844, 5988, 3, 169, 0, 0, 0, 4911.981, 226.6528, 99.11522, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Stalker 2 (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+8, 54560, 940, 5844, 5988, 3, 169, 0, 0, 0, 4888.436, 198.4774, 99.98913, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Stalker (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+9, 54555, 940, 5844, 5988, 3, 169, 0, 0, 0, 4921.772, 267.9514, 97.37627, 1.500983, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+10, 54555, 940, 5844, 5988, 3, 169, 0, 0, 0, 4936.924, 267.9323, 97.67499, 1.815142, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+11, 54555, 940, 5844, 5988, 3, 169, 0, 0, 0, 4905.202, 230.7309, 99.15278, 4.520403, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+12, 55559, 940, 5844, 5988, 3, 169, 0, 0, 0, 4888.479, 198.4549, 99.99197, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crystalline Elemental (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+13, 54555, 940, 5844, 5988, 3, 169, 0, 0, 0, 4911.641, 226.0347, 99.13889, 3.577925, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+14, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4878.854, 140.0469, 102.4885, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+15, 55559, 940, 5844, 5988, 3, 169, 0, 0, 0, 4879.781, 144.2947, 102.4532, 2.65841, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crystalline Elemental (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+16, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4877.969, 144.4167, 101.814, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+17, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4883.645, 138.9063, 104.0303, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+18, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4886.588, 142.8004, 104.7879, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+19, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4880.541, 147.6007, 102.6599, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+20, 55563, 940, 5844, 5988, 3, 169, 0, 0, 0, 4884.137, 147.9132, 104.0205, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Shard (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+21, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4842.169, 110.1302, 107.3551, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+22, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4834.797, 80.61111, 108.0769, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+23, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4838.941, 90.18924, 108.7896, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+24, 54522, 940, 5844, 5988, 3, 169, 0, 0, 0, 4838.181, 92.25174, 121.7298, 1.692969, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Glowing Eyes Stalker (Area: The Crystal Vice - Difficulty: 0) (Auras: 101913 - Glowing Eyes Stalker Visual)
(@CGUID+25, 54599, 940, 5844, 5988, 3, 169, 0, 0, 0, 4838.124, 89.11979, 125.5912, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Glowing Eyes Stalker (Area: The Crystal Vice - Difficulty: 0) (Auras: 101913 - Glowing Eyes Stalker Visual)
(@CGUID+26, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4796.059, 131.4323, 132.5512, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+27, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4827.03, 50.56597, 108.7141, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+28, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4771.364, 110.7431, 121.5722, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+29, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4788.47, 125.6701, 129.1958, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+30, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4776.328, 117.5503, 123.9087, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+31, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4831.258, 64.61979, 108.6366, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+32, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4784.077, 117.0191, 126.8619, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+33, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4818.981, 44.75, 106.4081, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+34, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4799.328, 38.18056, 99.88308, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+35, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4810.139, 31.5191, 104.6761, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+36, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4756.067, 103.2483, 115.0338, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+37, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4750.132, 97.3125, 112.3013, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0) (Auras: )
(@CGUID+38, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4739.719, 84.19965, 107.3137, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+39, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4737.554, 75.55382, 105.8405, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+40, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4786.283, 37.82465, 95.08319, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+41, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4751.03, 90.11285, 112.1174, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+42, 54598, 940, 5844, 5988, 3, 169, 0, 0, 0, 4777.378, 30.80903, 92.6001, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frozen Servitor Spawn Points (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+43, 57197, 940, 5844, 5988, 3, 169, 0, 0, 0, 4763.7, 61.6059, 66.4394, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arcurion Spawn Visual Stalker (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+44, 55779, 940, 5844, 5988, 3, 169, 0, 0, 0, 4864.293, 159.2448, 97.53125, 3.909538, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Thrall (Area: The Crystal Vice - Difficulty: 0) (Auras: 103251 - Icy Tomb) (possible waypoints or random movement)
(@CGUID+45, 55728, 940, 5844, 5988, 3, 169, 0, 0, 0, 4717.083, 30.24653, 75.19635, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ice Wall Exit Stalker (Area: The Crystal Vice - Difficulty: 0)
(@CGUID+46, 26483, 940, 5844, 5988, 3, 169, 0, 0, 0, 4617.502, -12.87551, 70.21095, 0.1859066, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+47, 26483, 940, 5844, 5988, 3, 169, 0, 0, 0, 4599.939, 10.4522, 83.58166, 3.972268, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+48, 54590, 940, 5844, 5988, 3, 169, 0, 0, 0, 4764.042, 61.79514, 66.45026, 0.9948376, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcurion (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 26483, 940, 5844, 5988, 3, 169, 0, 0, 0, 4607.014, -33.02474, 76.53326, 6.162838, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Crystal Vice - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4479.054, 64.96301, 87.2891, 3.844675, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4525.917, 49.15905, 83.60516, 5.973138, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+52, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4594.757, 88.81549, 89.44343, 1.943507, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+53, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4501.163, 81.5, 96.63739, 0.1919862, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+54, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4500.303, 90.75246, 98.20223, 5.182008, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+55, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4483.912, 111.1679, 86.81582, 0.5832697, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4478.549, 98.78819, 97.8424, 3.682645, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+57, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4516.943, 85.24892, 91.42188, 0.9843296, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+58, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4492.828, 130.4687, 89.5018, 5.87867, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+59, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4470.847, 109.6396, 90.10651, 5.204761, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+60, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4559.733, 154.6412, 97.10648, 2.394849, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+61, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4555.356, 228.2378, 97.78401, 4.913415, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4596.966, 263.033, 76.62727, 1.675516, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+63, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4714.113, 212.8454, 115.7402, 0.5327145, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+64, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4648.576, 352.2312, 107.0492, 4.494581, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+65, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4664.636, 414.3891, 112.1542, 5.89251, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+66, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4692.23, 401.3097, 117.0576, 1.221703, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+67, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 4691.387, 395.4393, 117.015, 5.848885, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+68, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4670.295, 283.5799, 111.452, 5.533684, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+69, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4548.087, 274.5094, 90.89059, 4.164766, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+70, 26293, 940, 5844, 5989, 3, 169, 0, 0, 0, 4511.597, 316.541, 83.89805, 5.647497, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hulking Jormungar (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 53488, 940, 5844, 5989, 3, 169, 0, 0, 0, 4443.585, 459.6424, 46.99477, 4.223697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Dragon Wastes - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+72, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4538.534, 480.2396, 67.25868, 1.937315, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+73, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4554.415, 483.2726, 66.37063, 0.6108652, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+74, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4559.021, 451.5, 69.9184, 5.288348, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+75, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4585.337, 453.592, 85.36057, 5.201081, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+76, 26492, 940, 5844, 5989, 3, 169, 0, 0, 0, 4576.901, 475.8507, 66.05868, 1.850049, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+77, 54972, 940, 5844, 5989, 3, 169, 0, 0, 0, 4407.306, 461.9635, 36.19281, 5.8294, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Thrall (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107455 - Earth-Warder) (possible waypoints or random movement)
(@CGUID+78, 55106, 940, 5844, 5989, 3, 169, 0, 0, 0, 4383.115, 425.651, 14.53479, 5.899213, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Assassin (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102921 - Stealth) (possible waypoints or random movement)
(@CGUID+79, 55106, 940, 5844, 5989, 3, 169, 0, 0, 0, 4365.505, 472.5955, -5.348724, 3.525565, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Assassin (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102921 - Stealth) (possible waypoints or random movement)
(@CGUID+80, 55106, 940, 5844, 5989, 3, 169, 0, 0, 0, 4384.54, 411.64, 10.17518, 1.905844, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Assassin (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102921 - Stealth) (possible waypoints or random movement)
(@CGUID+81, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4363.705, 319.0382, 47.28754, 1.099557, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+82, 55106, 940, 5844, 5990, 3, 169, 0, 0, 0, 4294.482, 406.3934, -7.773798, 2.91552, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Assassin (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
(@CGUID+83, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4289.38, 395.7135, -8.000034, 0.5235988, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+84, 55107, 940, 5844, 5990, 3, 169, 0, 0, 0, 4297.257, 382.8403, -8.000034, 0.5235988, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Ranger (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+85, 55112, 940, 5844, 5990, 3, 169, 0, 0, 0, 4291.359, 391.2465, -8.000034, 0.3316126, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Bruiser (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+86, 55111, 940, 5844, 5990, 3, 169, 0, 0, 0, 4294.055, 387.4861, -8.000034, 0.418879, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Thug (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+87, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4287.393, 463.434, -6.4843, 0.1745329, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+88, 55107, 940, 5844, 5990, 3, 169, 0, 0, 0, 4287.679, 460.4271, -6.472671, 0.2617994, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Ranger (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+89, 55112, 940, 5844, 5990, 3, 169, 0, 0, 0, 4285.805, 471.6615, -6.530862, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Bruiser (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+90, 55111, 940, 5844, 5990, 3, 169, 0, 0, 0, 4287.066, 467.6354, -6.545419, 0.05235988, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Thug (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+91, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4285.378, 475.5885, -6.572206, 6.126106, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+92, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4203.065, 475.8056, 42.2934, 5.986479, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+93, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4193.02, 513.8212, 12.8494, 1.151917, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+94, 55111, 940, 5844, 5990, 3, 169, 0, 0, 0, 4348.591, 603.0347, 19.76442, 4.276057, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Thug (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+95, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4350.567, 603.691, 20.43996, 4.258604, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+96, 55112, 940, 5844, 5990, 3, 169, 0, 0, 0, 4352.206, 601.9861, 19.93056, 4.223697, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Bruiser (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+97, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4354.424, 602.8403, 21.19383, 4.206244, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+98, 55107, 940, 5844, 5990, 3, 169, 0, 0, 0, 4347.438, 608.8438, 22.8941, 4.310963, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Ranger (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+99, 55106, 940, 5844, 5990, 3, 169, 0, 0, 0, 4349.037, 583.7327, 9.07904, 3.948954, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Assassin (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
(@CGUID+100, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4365.749, 664.3403, 29.03993, 4.625123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+101, 55112, 940, 5844, 5990, 3, 169, 0, 0, 0, 4233.72, 540.8368, 13.3316, 0.4712389, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Bruiser (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+102, 55109, 940, 5844, 5990, 3, 169, 0, 0, 0, 4235.142, 536.875, 12.23438, 0.541052, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Shadow-Walker (Area: Galakrond's Rest - Difficulty: 0) (Auras: 37816 - Shadowform) (possible waypoints or random movement)
(@CGUID+103, 55112, 940, 5844, 5990, 3, 169, 0, 0, 0, 4234.313, 538.6215, 12.64236, 0.4014257, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Bruiser (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+104, 55107, 940, 5844, 5990, 3, 169, 0, 0, 0, 4234.576, 538.0452, 12.49001, 0.5585054, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Ranger (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+105, 55111, 940, 5844, 5990, 3, 169, 0, 0, 0, 4233.826, 539.6146, 12.95313, 0.4712389, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Thug (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+106, 55415, 940, 5844, 5990, 3, 169, 0, 0, 0, 4114.684, 563.2726, 66.26726, 5.707227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
(@CGUID+107, 54968, 940, 5844, 5990, 3, 169, 0, 0, 0, 4222.207, 562.2708, 13.76326, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Asira Dawnslayer (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+108, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3491.109, 208.9045, 123.5809, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+109, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3602.266, 335.9549, 152.5115, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
(@CGUID+110, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3547.296, 357.1736, 176.0555, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
(@CGUID+111, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3625.172, 293.5156, 177.2349, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0) (Auras: )
-- (@CGUID+112, 55549, 940, 5844, 5990, 3, 169, 0, 0, 0, 4123.522, 571.9618, 62.19633, 5.862059, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+113, 55549, 940, 5844, 5990, 3, 169, 0, 0, 0, 4106.705, 535.6927, 60.03286, 5.995471, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+114, 55549, 940, 5844, 5990, 3, 169, 0, 0, 0, 4109.733, 548.5226, 60.69159, 6.157132, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+115, 55549, 940, 5844, 5990, 3, 169, 0, 0, 0, 4132.154, 582.9028, 62.80218, 5.654335, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+116, 55549, 940, 5844, 5990, 3, 169, 0, 0, 0, 4139.312, 589.8125, 62.38307, 5.344859, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Galakrond's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+117, 55967, 940, 5844, 5990, 3, 169, 0, 0, 0, 3751.074, 351.0553, 142.2015, 3.6444, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+118, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3598.554, 206.1892, 124.104, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+119, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3545.7, 212.625, 158.3441, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+120, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3467.604, 251.8438, 177.0426, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+121, 56126, 940, 5844, 5990, 3, 169, 0, 0, 0, 3495.505, 341.1476, 123.3985, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target Dummy (Area: Galakrond's Rest - Difficulty: 0)
-- (@CGUID+122, 55969, 940, 5844, 5990, 3, 169, 0, 0, 0, 3748.273, 424.6627, 168.469, 4.038465, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+123, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4172.114, 506.4306, 59.56597, 1.239184, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+124, 55969, 940, 5844, 5990, 3, 169, 0, 0, 0, 3709.799, 648.9181, 159.5869, 1.159848, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+125, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4046.035, 591.1163, 54.57146, 5.288348, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+126, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4158.76, 490.3958, 61.79861, 3.892084, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+127, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4040.233, 610.2705, 68.16865, 3.553325, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+128, 55636, 940, 5844, 5990, 3, 169, 0, 0, 0, 4097.642, 377.9913, 78.7017, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Drake (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+129, 55636, 940, 5844, 5990, 3, 169, 0, 0, 0, 4094.593, 388.3281, 90.80915, 2.86234, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Drake (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+130, 55969, 940, 5844, 5990, 3, 169, 0, 0, 0, 3703.941, 273.5554, 177.6739, 2.991689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+131, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4144.33, 462.4965, 78.44966, 3.612832, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+132, 55636, 940, 5844, 5990, 3, 169, 0, 0, 0, 4097.822, 359.4306, 75.85492, 2.443461, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Drake (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+133, 55969, 940, 5844, 5990, 3, 169, 0, 0, 0, 3692.507, 329.5002, 189.8567, 3.176955, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+134, 54632, 940, 5844, 5990, 3, 169, 0, 0, 0, 3906.705, 252.4688, 8.297945, 1.37881, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Brute (Area: Galakrond's Rest - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+135, 55969, 940, 5844, 5990, 3, 169, 0, 0, 0, 3703.356, 231.2969, 193.3018, 4.997601, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Galakrond's Rest - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+136, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4035.764, 553.036, 55.39008, 4.18223, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+137, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4002.908, 540.8469, 50.24938, 0.02656247, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+138, 55636, 940, 5844, 5990, 3, 169, 0, 0, 0, 4092.437, 410.6597, 96.02985, 3.351032, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Drake (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+139, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4016.903, 564.3495, 61.32147, 5.987871, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+140, 26492, 940, 5844, 5990, 3, 169, 0, 0, 0, 4181.056, 459.9254, 59.22049, 5.288348, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wastes Digger (Area: Galakrond's Rest - Difficulty: 0)
(@CGUID+141, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4024.27, 560.6443, 51.61945, 5.781762, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+142, 26483, 940, 5844, 5990, 3, 169, 0, 0, 0, 4000.885, 531.2448, 56.69263, 2.443461, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: Galakrond's Rest - Difficulty: 0)
-- (@CGUID+143, 55967, 940, 5844, 5989, 3, 169, 0, 0, 0, 3507.388, 462.0201, 143.4177, 0.4287916, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+144, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 3916.564, 529.5521, 56.66361, 2.443461, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+145, 26295, 940, 5844, 5989, 3, 169, 0, 0, 0, 4021.968, 478.7584, 46.54015, 0.3387034, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnataur Patriarch (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+146, 27279, 940, 5844, 5989, 3, 169, 0, 0, 0, 4010.855, 464.349, 43.03472, 0.1745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Snowplain Shaman (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+147, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 3912.377, 657.4757, 68.1098, 4.415683, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+148, 56143, 940, 5844, 5989, 3, 169, 0, 0, 0, 3676.181, 456.9445, 163.3529, 3.857178, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+149, 55967, 940, 5844, 5989, 3, 169, 0, 0, 0, 3686.441, 143.3845, 158.3899, 3.804565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+150, 27278, 940, 5844, 5989, 3, 169, 0, 0, 0, 4036.218, 469.5088, 51.0597, 4.807582, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Snowplain Zealot (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+151, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 3912.214, 658.0313, 68.37509, 4.415683, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+152, 54632, 940, 5844, 5989, 3, 169, 0, 0, 0, 3813.517, 324.7813, -32.36459, 5.462881, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Brute (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+153, 55636, 940, 5844, 5989, 3, 169, 0, 0, 0, 4118.82, 336.474, 93.4671, 2.286381, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Twilight Drake (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+154, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 3939.863, 683.7542, 83.53851, 1.464701, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+155, 26295, 940, 5844, 5989, 3, 169, 0, 0, 0, 4026.125, 436.6009, 48.22003, 4.84212, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnataur Patriarch (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+156, 26480, 940, 5844, 5989, 3, 169, 0, 0, 0, 4028.09, 435.1389, 48.57639, 5.794493, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnataur Youngling (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+157, 26483, 940, 5844, 5989, 3, 169, 0, 0, 0, 3965.835, 600.0608, 48.09681, 5.288348, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragonbone Condor (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+158, 27278, 940, 5844, 5989, 3, 169, 0, 0, 0, 4002.604, 540.1035, 51.19105, 3.33104, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Snowplain Zealot (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+159, 56143, 940, 5844, 5989, 3, 169, 0, 0, 0, 3724.291, 439.4125, 127.9794, 0.7378677, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+160, 26271, 940, 5844, 5989, 3, 169, 0, 0, 0, 4007.319, 576.7562, 48.57907, 3.253113, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Emaciated Mammoth Bull (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+161, 26271, 940, 5844, 5989, 3, 169, 0, 0, 0, 4035.858, 429.6563, 50.21528, 2.460914, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Emaciated Mammoth Bull (Area: The Dragon Wastes - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+162, 27278, 940, 5844, 5989, 3, 169, 0, 0, 0, 4003.056, 470.2795, 42.13876, 1.466077, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Snowplain Zealot (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+163, 27279, 940, 5844, 5989, 3, 169, 0, 0, 0, 4019.263, 463.7379, 45.96528, 4.328416, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Snowplain Shaman (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+164, 27278, 940, 5844, 5989, 3, 169, 0, 0, 0, 4000.364, 458.7798, 40.95819, 0.9576738, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Snowplain Zealot (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+165, 56140, 940, 5844, 5989, 3, 169, 0, 0, 0, 3693.226, 629.2407, 177.0334, 0.9958677, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dream Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+166, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4044.568, 271.1302, 47.05555, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+167, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3905.494, 284.0243, 4.248264, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+168, 26480, 940, 5844, 5989, 3, 169, 0, 0, 0, 4039.936, 418.7743, 50.81076, 1.32645, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnataur Youngling (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+169, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3661.929, 419.0243, 43.65706, 2.548181, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+170, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3893.859, 291.8195, -0.1436129, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+171, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4014.271, 291.8246, 29.60069, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+172, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4032.229, 290.0746, 24.05556, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+173, 26705, 940, 5844, 5989, 3, 169, 0, 0, 0, 3947.278, 366.6945, 39.89063, 2.879793, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Snowplain Disciple (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+174, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3989.995, 272.8351, 19.88889, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+175, 26481, 940, 5844, 5989, 3, 169, 0, 0, 0, 3946.962, 371.9688, 41.2743, 0.8028514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnataur Alpha (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+176, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3915.597, 278.6337, 7.514098, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+177, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3883.76, 299.8785, -6.630208, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+178, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3655.406, 431.1754, 47.26284, 4.886922, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+179, 58233, 940, 5844, 5989, 3, 169, 0, 0, 0, 3652.635, 422.0035, 45.93893, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Portal (Area: The Dragon Wastes - Difficulty: 0) (Auras: 110160 - Summon Cosmetic Siege Breaker Periodic)
(@CGUID+180, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3889.371, 298.3212, -3.866585, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+181, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3910.293, 299.2413, 4.207382, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102213 - Summon Blood)
(@CGUID+182, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4030.858, 287.7448, 37.95139, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+183, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3999.465, 285.3038, 23.68403, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+184, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3642.288, 426.6163, 47.48329, 6.021386, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+185, 58287, 940, 5844, 5989, 3, 169, 0, 0, 0, 3753.198, 427.5712, 352.3352, 4.34587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cannon [Do Not Translate] (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+186, 58287, 940, 5844, 5989, 3, 169, 0, 0, 0, 3718.373, 461.5104, 351.1619, 3.769911, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cannon [Do Not Translate] (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+187, 55911, 940, 5844, 5989, 3, 169, 0, 0, 0, 3682.21, 276.8376, 189.5891, 6.133283, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Life (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest, 105013 - Renew)
(@CGUID+188, 55911, 940, 5844, 5989, 3, 169, 0, 0, 0, 3708.22, 206.9844, 196.5025, 1.768262, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Life (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest, 105013 - Renew)
-- (@CGUID+189, 56142, UNKNOWN, 5844, 5989, 3, 169, 0, 0, 0, 2.24317, -0.000007301359, 12.20854, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest, 105124 - Step Through Time) - !!! on transport - transport template not found !!!
(@CGUID+190, 58287, 940, 5844, 5989, 3, 169, 0, 0, 0, 3724.739, 453.2899, 351.0599, 3.735005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cannon [Do Not Translate] (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+191, 56143, 940, 5844, 5989, 3, 169, 0, 0, 0, 3641.469, 402.9073, 141.5339, 5.283664, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+192, 54632, 940, 5844, 5989, 3, 169, 0, 0, 0, 3727.031, 266.5642, -92.36553, 0.7330383, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Brute (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+193, 55967, 940, 5844, 5989, 3, 169, 0, 0, 0, 3594.561, 119.19, 182.441, 5.587852, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+194, 55967, 940, 5844, 5989, 3, 169, 0, 0, 0, 3609.436, 105.6667, 186.3936, 2.398413, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+195, 58287, 940, 5844, 5989, 3, 169, 0, 0, 0, 3739.019, 438.3056, 351.1921, 4.066617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cannon [Do Not Translate] (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+196, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3611.637, 421.5885, 47.51588, 2.792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+197, 58226, 940, 5844, 5989, 3, 169, 0, 0, 0, 3595.33, 518.6059, 61.40679, 4.813023, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Morchok (Area: The Dragon Wastes - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+198, 56140, 940, 5844, 5989, 3, 169, 0, 0, 0, 3753.93, 727.0433, 202.4067, 4.141577, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+199, 56139, 940, 5844, 5989, 3, 169, 0, 0, 0, 3643.282, 398.8749, 140.2635, 1.993271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+200, 55914, 940, 5844, 5989, 3, 169, 0, 0, 0, 3672.598, 328.7959, 191.6204, 0.03536232, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+201, 58233, 940, 5844, 5989, 3, 169, 0, 0, 0, 3601.829, 422.2014, 47.88682, 0.2443461, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Portal (Area: The Dragon Wastes - Difficulty: 0) (Auras: 110160 - Summon Cosmetic Siege Breaker Periodic)
(@CGUID+202, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3602.237, 431.7743, 49.01041, 5.131268, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+203, 55914, 940, 5844, 5989, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+204, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3871.096, 287.4097, -8.789674, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+205, 54663, 940, 5844, 5989, 3, 169, 0, 0, 0, 3939.54, 291.7813, 12.20035, 5.424023, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Earthcaller Torunscar (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107773 - Earthen Ring Instakill)
(@CGUID+206, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3870.304, 270.0695, -5.486111, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+207, 54634, 940, 5844, 5989, 3, 169, 0, 0, 0, 3943.188, 288.4618, 13.49787, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thrall (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102550 - Root Thrall, 102232 - Aggro Thrall)
(@CGUID+208, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3912.801, 268.007, 7.947608, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102213 - Summon Blood)
(@CGUID+209, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3855.311, 295.8264, -16.86549, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+210, 54666, 940, 5844, 5989, 3, 169, 0, 0, 0, 3925.893, 295.4108, 11.36867, 1.410421, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stormcaller Jalara (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107773 - Earthen Ring Instakill)
(@CGUID+211, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3873.692, 297.8646, -10.33928, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+212, 54633, 940, 5844, 5989, 3, 169, 0, 0, 0, 3901.363, 251.4531, 6.676357, 1.37881, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Shadow Weaver (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+213, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3996.252, 244.5781, 22.87847, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+214, 54664, 940, 5844, 5989, 3, 169, 0, 0, 0, 3928.957, 289.5773, 10.94037, 3.396169, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tawn Winterbluff (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107773 - Earthen Ring Instakill, 79949 - Water Shield)
(@CGUID+215, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3882.969, 282.5382, -3.295139, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+216, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3861.896, 268.5434, -7.956218, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+217, 53488, 940, 5844, 5989, 3, 169, 0, 0, 0, 3900.594, 282.0729, 4.151678, 4.223697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Summon Enabler Stalker (Area: The Dragon Wastes - Difficulty: 0) (Auras: 99201 - Summon Enabler)
(@CGUID+218, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4000.179, 233.6754, 24.11238, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+219, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3904.702, 266.684, 4.96007, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+220, 54665, 940, 5844, 5989, 3, 169, 0, 0, 0, 3930.341, 293.3475, 10.49344, 2.291332, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hargoth Dimblaze (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107773 - Earthen Ring Instakill)
(@CGUID+221, 54686, 940, 5844, 5989, 3, 169, 0, 0, 0, 3908.728, 246.7587, 10.2871, 1.37881, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Shadow Borer (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+222, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3849.099, 296.434, -19.43765, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+223, 54628, 940, 5844, 5989, 3, 169, 0, 0, 0, 3904.888, 250.9427, 8.095772, 1.082104, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dark Haze (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze)
(@CGUID+224, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3893.066, 274.4792, 2.008986, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+225, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3885.166, 267.2413, 0.05433436, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+226, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4003.345, 229.8594, 28.8125, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+227, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4013.297, 227.1024, 28.84722, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
-- (@CGUID+228, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4013.297, 227.1024, 28.84722, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+229, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3787.542, 280.9323, -47.92014, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
-- (@CGUID+230, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4013.297, 227.1024, 28.84722, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+231, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3818.195, 286.6476, -35.44098, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+232, 54628, 940, 5844, 5989, 3, 169, 0, 0, 0, 3814.132, 322.7674, -32.83337, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dark Haze (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze)
(@CGUID+233, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3832.609, 270.8385, -20.07645, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+234, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4044.298, 243.0955, 27.30729, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+235, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3817.402, 269.3073, -33.4809, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+236, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3831.499, 298.4705, -26.90041, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+237, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3812.898, 268.4583, -35.84961, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
-- (@CGUID+238, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4013.297, 227.1024, 28.84722, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
-- (@CGUID+239, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4013.297, 227.1024, 28.84722, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+240, 54686, 940, 5844, 5989, 3, 169, 0, 0, 0, 3815.539, 319.0712, -33.62153, 5.51524, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Shadow Borer (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+241, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3841.242, 269.1076, -15.90799, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+242, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 3809.897, 303.2448, -40.41875, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+243, 54633, 940, 5844, 5989, 3, 169, 0, 0, 0, 3808.175, 323.7656, -36.16254, 5.550147, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Shadow Weaver (Area: The Dragon Wastes - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+244, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3842.035, 286.4479, -19.64131, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+245, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4029.29, 240.6441, 39.13368, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+246, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4023.371, 232.4236, 28.90625, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+247, 54644, 940, 5844, 5989, 3, 169, 0, 0, 0, 4042.08, 253.0469, 47.41666, 0.9948376, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+248, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3788.335, 298.2726, -51.37017, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+249, 54735, 940, 5844, 5989, 3, 169, 0, 0, 0, 3854.518, 278.4861, -12.61285, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+250, 56143, 940, 5844, 5989, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+251, 58233, 940, 5844, 5989, 3, 169, 0, 0, 0, 3659.149, 138.6719, 43.92882, 4.153883, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Portal (Area: The Dragon Wastes - Difficulty: 0) (Auras: 110160 - Summon Cosmetic Siege Breaker Periodic)
(@CGUID+252, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3665.864, 131.1042, 42.84493, 2.565634, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+253, 56144, 940, 5844, 5989, 3, 169, 0, 0, 0, 3670.278, 144.8331, 197.5574, 0.6534385, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+254, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3667.897, 145.8212, 43.0434, 3.892084, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+255, 56144, 940, 5844, 5989, 3, 169, 0, 0, 0, 3667.544, 140.1948, 167.8948, 5.576291, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Portent of Twilight (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+256, 58233, 940, 5844, 5989, 3, 169, 0, 0, 0, 3690.47, 162.0174, 39.57986, 4.328416, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Portal (Area: The Dragon Wastes - Difficulty: 0) (Auras: 110160 - Summon Cosmetic Siege Breaker Periodic)
(@CGUID+257, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3684.513, 154.349, 40.77723, 0.5934119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+258, 56140, 940, 5844, 5989, 3, 169, 0, 0, 0, 3745.229, 145.0252, 187.8996, 5.653123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dream Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+259, 55913, 940, 5844, 5989, 3, 169, 0, 0, 0, 3674.618, 134.1526, 158.3899, 0.6629725, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Time (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+260, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3698.816, 155.809, 39.62274, 2.932153, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+261, 56141, 940, 5844, 5989, 3, 169, 0, 0, 0, 3683.613, 140.5919, 130.116, 0.3517407, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+262, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3650.82, 132.8958, 43.73264, 0.4886922, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+263, 58235, 940, 5844, 5989, 3, 169, 0, 0, 0, 3697.833, 170.9392, 37.21242, 4.066617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Siege Captain (Area: The Dragon Wastes - Difficulty: 0)
(@CGUID+264, 56141, 940, 5844, 5989, 3, 169, 0, 0, 0, 3662.221, 144.9329, 43.62993, 4.70727, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arcane Warden (Area: The Dragon Wastes - Difficulty: 0)
-- (@CGUID+265, 55967, 940, 5844, 5989, 3, 169, 0, 0, 0, 3509.816, 452.6547, 144.5677, 4.966046, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+266, 55911, 940, 5844, 5989, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: The Dragon Wastes - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+267, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3765.311, 306.316, -65.74306, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0)
(@CGUID+268, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3764.518, 288.9757, -63.01736, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0)
(@CGUID+269, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+270, 56142, UNKNOWN, 5844, 5991, 3, 169, 0, 0, 0, 2.24317, -0.000007301359, 12.20854, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest, 105124 - Step Through Time) - !!! on transport - transport template not found !!!
(@CGUID+271, 55549, 940, 5844, 5991, 3, 169, 0, 0, 0, 4109.733, 548.5226, 60.69159, 6.157132, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+272, 55969, 940, 5844, 5991, 3, 169, 0, 0, 0, 3776.57, 259.974, 149.9639, 3.263766, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+273, 55549, 940, 5844, 5991, 3, 169, 0, 0, 0, 4129.012, 569.8213, 65.21024, 5.758926, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+274, 55549, 940, 5844, 5991, 3, 169, 0, 0, 0, 4106.705, 535.6927, 60.03286, 5.995471, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+275, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3622.378, 48.75519, 52.99644, 5.827101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+276, 55549, 940, 5844, 5991, 3, 169, 0, 0, 0, 4132.154, 582.9028, 62.80218, 5.654335, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+277, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3661.965, 456.9445, 164.6073, 3.909538, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+278, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3596.082, 131.9482, 191.004, 4.502035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+279, 55549, 940, 5844, 5991, 3, 169, 0, 0, 0, 4142.364, 585.5944, 66.16669, 5.363102, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+280, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3634.852, 44.20273, 145.5047, 0.6160991, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+281, 55913, 940, 5844, 5991, 3, 169, 0, 0, 0, 3611.599, 207.1007, 155.5423, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Time (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+282, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+283, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+284, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3599.86, 258.4387, 195.5957, 0.2111045, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+285, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+286, 55969, 940, 5844, 5991, 3, 169, 0, 0, 0, 3744.524, 239.866, 177.0143, 2.5109, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+287, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3704.402, 79.65972, 214.5292, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+288, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3515.82, 429.4949, 147.4117, 5.122894, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
-- (@CGUID+289, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+290, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+291, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+292, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3710.714, 18.18167, 165.6143, 0.2948519, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+293, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+294, 55969, 940, 5844, 5991, 3, 169, 0, 0, 0, 3771.046, 362.1563, 177.9916, 3.605986, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+295, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+296, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+297, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+298, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3661.965, 456.9445, 164.6073, 3.909538, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+299, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+300, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+301, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+302, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3531.884, 385.0797, 119.5295, 1.917847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0)
(@CGUID+303, 54686, 940, 5844, 5991, 3, 169, 0, 0, 0, 3729.054, 260.8542, -87.17882, 0.4712389, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Shadow Borer (Area: Path of the Titans - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
(@CGUID+304, 54628, 940, 5844, 5991, 3, 169, 0, 0, 0, 3729.343, 264.7431, -89.10324, 0.541052, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dark Haze (Area: Path of the Titans - Difficulty: 0) (Auras: 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze)
(@CGUID+305, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3555.345, 126.2349, 200.7516, 3.272371, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+306, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3717.854, 280.5191, -98.7001, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0)
(@CGUID+307, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3718.647, 297.8594, -92.14236, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+308, 54633, 940, 5844, 5991, 3, 169, 0, 0, 0, 3721.689, 265.5486, -97.21669, 0.6457718, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Faceless Shadow Weaver (Area: Path of the Titans - Difficulty: 0) (Auras: 102231 - Aggro Periodic) (possible waypoints or random movement)
-- (@CGUID+309, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+310, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+311, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+312, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3567.432, 20.07028, 131.2826, 2.812945, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+313, 54955, 940, 5844, 5991, 3, 169, 0, 0, 0, 3659.22, 284.9219, -120.084, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Holy Shield (Area: Path of the Titans - Difficulty: 0) (Auras: )
(@CGUID+314, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3685.017, 268.8976, -117.9874, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0)
(@CGUID+315, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+316, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.119, 21.54099, 131.9135, 4.347658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+317, 54735, 940, 5844, 5991, 3, 169, 0, 0, 0, 3685.81, 286.2379, -112.401, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw Loc (Area: Path of the Titans - Difficulty: 0)
-- (@CGUID+318, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+319, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3517.021, 397.5706, 138.2657, 5.584845, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
-- (@CGUID+320, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+321, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+322, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3528.58, 362.7621, 200.2676, 1.53589, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+323, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3561.482, 17.25174, 58.56401, 1.117011, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0)
(@CGUID+324, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.495, 550.0362, 143.0363, 4.245311, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0)
(@CGUID+325, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3657.872, 34.40799, 180.5735, 1.972222, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+326, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+327, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3593.981, 28.63783, 132.1968, 0.4057497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+328, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3633.406, 56.6007, 145.5047, 5.51524, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+329, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+330, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+331, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3505.002, 471.224, 142.2875, 4.966046, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+332, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+333, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+334, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+335, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+336, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3689.161, -34.84028, 160.9042, 0.4014257, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+337, 55913, 940, 5844, 5991, 3, 169, 0, 0, 0, 3611.599, 207.1007, 155.5423, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Time (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+338, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+339, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268926, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+340, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+341, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3503.699, 454.2795, 144.4827, 5.224961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+342, 55969, 940, 5844, 5991, 3, 169, 0, 0, 0, 3548.214, 491.8576, 157.8729, 4.18879, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+343, 55969, 940, 5844, 5991, 3, 169, 0, 0, 0, 3746.083, 238.7286, 176.6291, 2.512172, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+344, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3729.34, 476.045, 164.6906, 2.321086, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+345, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3633.406, 56.6007, 145.5047, 5.51524, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+346, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.627, 553.716, 202.758, 0.705901, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+347, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3629, 239.8247, 52.31074, 5.364882, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
(@CGUID+348, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3615.764, 320.3351, 52.31075, 1.755583, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
-- (@CGUID+349, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+350, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3756.943, 40.40278, 171.4171, 2.251475, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+351, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+352, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+353, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3616.367, 228.3056, 51.88017, 0.5274228, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
(@CGUID+354, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3605.263, 330.3004, 51.95376, 1.174592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
-- (@CGUID+355, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+356, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3607.682, 217.9358, 51.85659, 5.832138, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
(@CGUID+357, 55445, 940, 5844, 5991, 3, 169, 0, 0, 0, 3546.417, 272.7413, -115.8816, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Earthen Shell Target (Area: Path of the Titans - Difficulty: 0) (Auras: 104516 - Seeping Light)
(@CGUID+358, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3623.74, 130.0277, 181.7824, 3.598628, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+359, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+360, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+361, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+362, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3546.92, 180.7934, 200.7516, 4.729842, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+363, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+364, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+365, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268926, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+366, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3550.339, 488.6858, 202.758, 0.9599311, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+367, 56144, 940, 5844, 5991, 3, 169, 0, 0, 0, 3697.032, 87.69965, 213.8765, 4.720447, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+368, 55913, 940, 5844, 5991, 3, 169, 0, 0, 0, 3611.599, 207.1007, 155.5423, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Time (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+369, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3715.698, 407.1945, 127.9794, 3.577925, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+370, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+371, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+372, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+373, 56140, 940, 5844, 5991, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+374, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3623.574, 129.9463, 181.7836, 3.598628, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+375, 55911, 940, 5844, 5991, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+376, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3528.58, 362.7621, 200.2676, 1.53589, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+377, 55912, 940, 5844, 5991, 3, 169, 0, 0, 0, 3546.92, 180.7934, 200.7516, 4.729842, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+378, 54938, 940, 5844, 5991, 3, 169, 0, 0, 0, 3550.029, 273.4061, -115.9574, 0.2217666, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Archbishop Benedictus (Area: Path of the Titans - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+379, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3550.339, 488.6858, 202.758, 0.9599311, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+380, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+381, 56142, 940, 5844, 5991, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+382, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3670.462, -7.152937, 160.9042, 6.120526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+383, 55967, 940, 5844, 5991, 3, 169, 0, 0, 0, 3505.002, 471.224, 142.2875, 5.480334, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+384, 56141, 940, 5844, 5991, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+385, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3594.438, 205.7882, 51.85197, 5.42351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
(@CGUID+386, 57261, 940, 5844, 5991, 3, 169, 0, 0, 0, 3585.009, 341.8993, 59.47065, 0.6300759, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Path of the Titans - Difficulty: 0)
-- (@CGUID+387, 56139, 940, 5844, 5991, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+388, 56143, 940, 5844, 5991, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Path of the Titans - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+389, 55914, 940, 5844, 5991, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Path of the Titans - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+390, 57261, 940, 5844, 5845, 3, 169, 0, 0, 0, 3566.124, 357.4132, 53.35905, 0.4811312, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Wyrmrest Temple - Difficulty: 0)
(@CGUID+391, 57261, 940, 5844, 5845, 3, 169, 0, 0, 0, 3582.976, 196.9045, 52.22137, 0.03100692, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siege Breaker Stalker (Area: Wyrmrest Temple - Difficulty: 0)
(@CGUID+392, 56144, 940, 5844, 5845, 3, 169, 0, 0, 0, 3442.225, 449.0211, 193.9658, 5.949467, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Portent of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+393, 56144, 940, 5844, 5845, 3, 169, 0, 0, 0, 3424.787, 420.4621, 179.4149, 0.6740164, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+394, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+395, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+396, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+397, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3624.3, 130.3033, 181.7782, 3.598628, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+398, 54971, 940, 5844, 5845, 3, 169, 0, 0, 0, 3563.01, 274.5903, -115.8816, 3.316126, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Thrall (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 108437 - Lavaburst Trigger) (possible waypoints or random movement)
(@CGUID+399, 56144, 940, 5844, 5845, 3, 169, 0, 0, 0, 3475.47, 458.0712, 159.9131, 4.13643, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+400, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268926, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+401, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3746.067, 238.7405, 176.6331, 2.512151, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+402, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3546.92, 180.7934, 200.7516, 4.729841, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+403, 55914, 940, 5844, 5845, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+404, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3770.322, 361.7937, 178.1011, 3.605941, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+405, 56140, 940, 5844, 5845, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+406, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+407, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3709.563, 100.6805, 163.978, 2.236958, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+408, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3505.002, 471.224, 142.2875, 4.966046, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+409, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+410, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+411, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+412, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3626.248, 233.217, 199.0118, 5.794493, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+413, 55914, 940, 5844, 5845, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+414, 56143, 940, 5844, 5845, 3, 169, 0, 0, 0, 3575.697, 17.25174, 130.0734, 1.169371, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+415, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+416, 56140, 940, 5844, 5845, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+417, 56143, 940, 5844, 5845, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+418, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3801.656, 378.8733, 141.4534, 5.585053, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+419, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+420, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3659.875, 540.5076, 163.974, 4.540646, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+421, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+422, 56139, 940, 5844, 5845, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+423, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+424, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3528.58, 362.7621, 200.2676, 1.53589, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+425, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+426, 55913, 940, 5844, 5845, 3, 169, 0, 0, 0, 3611.599, 207.1007, 155.5423, 0, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Time (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+427, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3653.143, 280.599, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+428, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3505.002, 471.224, 142.2875, 4.966046, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+429, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3697.681, 115.7969, 162.1124, 2.236958, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+430, 56139, 940, 5844, 5845, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+431, 56143, 940, 5844, 5845, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.70526, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+432, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3746.248, 422.1333, 169.3043, 4.036637, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+433, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3528.58, 362.7621, 200.2676, 1.53589, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+434, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3744.878, 239.6075, 176.9267, 2.511128, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+435, 55914, 940, 5844, 5845, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+436, 56140, 940, 5844, 5845, 3, 169, 0, 0, 0, 3601.843, 189.3194, 196.2446, 6.161012, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Dream Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+437, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+438, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3533.663, 372.4201, 129.9822, 1.710423, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+439, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3548.882, 329.0486, -120.0617, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+440, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3557.027, 266.382, -83.55221, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+441, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3607.753, 278.908, -93.28233, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+442, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3558.378, 243.2135, -82.2213, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+443, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3606.719, 278.9653, -120.066, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+444, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3559.381, 310.1684, -112.8441, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+445, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3526.161, 307.1962, -112.5398, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+446, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3594.221, 232.0174, -119.9657, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+447, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3592.08, 238.8038, -87.0628, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+448, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3537.407, 235.6007, -112.5398, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+449, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3563.151, 304.6129, -67.62148, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+450, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3578.839, 246.309, -82.38911, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+451, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3547.855, 285.7621, -82.90279, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+452, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3504.145, 269.3629, -115.2265, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+453, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3567.516, 238.8264, -110.1267, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+454, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3513.352, 251.1292, -112.5398, 4.734643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+455, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3583.09, 318.5208, -90.59857, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+456, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3598.683, 306.6476, -80.48533, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+457, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3567.423, 264.8611, -83.14768, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+458, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3587.463, 276.4254, -115.6276, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+459, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3586.22, 309.8038, -120.0634, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+460, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3503.891, 315.7604, -120.0557, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+461, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3555.947, 322.8455, -83.68659, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+462, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3567.516, 238.8264, -110.1267, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+463, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3536.733, 329.9635, -83.5424, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+464, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3599.555, 208.0347, -89.1302, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+465, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3558.087, 209.1389, -103.9093, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+466, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3522.991, 282.6823, -44.52893, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+467, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3499.632, 294.1597, -45.83688, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+468, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3499.279, 235.2899, -55.32615, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+469, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3518.57, 213.6632, -98.48595, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+470, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3492.693, 328.5868, -106.5376, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+471, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3521.927, 217.0243, -59.39108, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+472, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3541.425, 205.9045, -86.03066, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+473, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3520.503, 204.9948, -79.75146, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+474, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3650.376, 283.2465, -120.0693, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+475, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3496.333, 345.441, -78.1769, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+476, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3590.21, 195.9271, -106.245, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+477, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3617.406, 245.9635, -101.9168, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+478, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3558.394, 218.5191, -119.9715, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+479, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3483.068, 264.7604, -59.52269, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+480, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3512.046, 224.6354, -120.0638, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+481, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3516.707, 320.2986, -74.2921, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+482, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3525.107, 338.8455, -105.3405, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+483, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3475.728, 284.8663, -99.83769, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+484, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3488.352, 266.6215, -120.0612, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+485, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3541.892, 250.2865, -52.80919, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+486, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3505.04, 217.7899, -94.90804, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+487, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3582.161, 347.0174, -103.2659, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+488, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3490.37, 236.5139, -86.96399, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+489, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3673.695, 297.6406, -114.6939, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+490, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3705.938, 296.691, -98.68146, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+491, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3712.707, 279.6667, -101.8106, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+492, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3677.234, 277.7031, -118.3822, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
(@CGUID+493, 55466, 940, 5844, 5845, 3, 290, 0, 0, 0, 3454.995, 263.3802, -84.04791, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Spark (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 103766 - Unstable Twilight)
-- (@CGUID+494, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3521.534, 417.9076, 139.2989, 5.114944, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
(@CGUID+495, 56139, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.094, 85.78177, 51.85146, 3.925944, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Warden (Area: Wyrmrest Temple - Difficulty: 0)
-- (@CGUID+496, 55912, 940, 5844, 5845, 3, 169, 0, 0, 0, 3530.097, 397.7976, 129.9822, 1.944368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Magic (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest, 105066 - Arcane Missile Barrage)
(@CGUID+497, 56141, 940, 5844, 5845, 3, 169, 0, 0, 0, 3680.231, 139.3507, 41.59485, 5.864306, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arcane Warden (Area: Wyrmrest Temple - Difficulty: 0)
(@CGUID+498, 56139, 940, 5844, 5845, 3, 169, 0, 0, 0, 3642.769, 236.9653, 128.5655, 5.08747, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Life Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
(@CGUID+499, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3695.274, 290.2301, 175.5551, 1.266711, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0)
(@CGUID+500, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3675.102, 207.8954, 196.907, 0.7914703, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+501, 55914, 940, 5844, 5845, 3, 169, 0, 0, 0, 3635.384, 388.3803, 189.6254, 1.444807, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+502, 56141, 940, 5844, 5845, 3, 169, 0, 0, 0, 3680.768, 141.6928, 130.116, 1.345388, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arcane Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+503, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3372.045, 411.2145, 181.0819, 0.05590937, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest)
(@CGUID+504, 56144, 940, 5844, 5845, 3, 169, 0, 0, 0, 3654.416, 43.55386, 145.5047, 1.473356, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Portent of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+505, 55911, 940, 5844, 5845, 3, 169, 0, 0, 0, 3672.365, 279.5916, 203.9358, 6.230825, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of Life (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+506, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3502.849, 360.8993, 198.5521, 2.268928, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+507, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3770.352, 361.8086, 178.0966, 3.60594, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+508, 56143, 940, 5844, 5845, 3, 169, 0, 0, 0, 3748.74, 142.4653, 187.2045, 2.12243, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Force of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+509, 56141, 940, 5844, 5845, 3, 169, 0, 0, 0, 3588.877, 180.0243, 130.116, 5.864306, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Arcane Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+510, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3576.018, 182.4879, 200.6583, 5.358161, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+511, 55914, 940, 5844, 5845, 3, 169, 0, 0, 0, 3621.424, 329.0278, 192.7293, 6.265732, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Champion of the Emerald Dream (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+512, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3624.027, 130.1691, 181.7802, 3.598628, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
(@CGUID+513, 56142, 940, 5844, 5845, 3, 169, 0, 0, 0, 3596.389, -39.72275, 64.64384, 0.5350131, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Time Warden (Area: Wyrmrest Temple - Difficulty: 0)
-- (@CGUID+514, 55967, 940, 5844, 5845, 3, 169, 0, 0, 0, 3505.002, 471.224, 142.2875, 5.480334, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Harbinger of Destruction (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest) (possible waypoints or random movement)
-- (@CGUID+515, 55969, 940, 5844, 5845, 3, 169, 0, 0, 0, 3744.999, 239.5188, 176.8966, 2.51121, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Harbinger of Twilight (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107577 - Attack Wyrmrest)
-- (@CGUID+516, 56139, 940, 5844, 5845, 3, 169, 0, 0, 0, 3563.393, 170.3941, 128.5655, 4.904375, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 15595); -- Life Warden (Area: Wyrmrest Temple - Difficulty: 0) (Auras: 107576 - Defend Wyrmrest) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+516;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+1, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Stalker Entrance
(@CGUID+2, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Stalker Entrance
(@CGUID+3, 0, 0, 0, 1, 0, '101913'), -- Glowing Eyes Stalker - 101913 - Glowing Eyes Stalker Visual
(@CGUID+4, 0, 0, 0, 1, 0, ''), -- Thrall
(@CGUID+5, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Stalker 3
(@CGUID+6, 0, 0, 50331648, 1, 0, ''), -- Deathwing
(@CGUID+7, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Stalker 2
(@CGUID+8, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Stalker
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- Frozen Servitor
(@CGUID+10, 0, 0, 0, 1, 0, ''), -- Frozen Servitor
(@CGUID+11, 0, 0, 0, 1, 0, ''), -- Frozen Servitor
(@CGUID+12, 0, 0, 0, 1, 0, ''), -- Crystalline Elemental
(@CGUID+13, 0, 0, 0, 1, 0, ''), -- Frozen Servitor
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+15, 0, 0, 0, 1, 0, ''), -- Crystalline Elemental
(@CGUID+16, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+18, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+19, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+20, 0, 0, 0, 1, 0, ''), -- Frozen Shard
(@CGUID+21, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+22, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+23, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+24, 0, 0, 0, 1, 0, '101913'), -- Glowing Eyes Stalker - 101913 - Glowing Eyes Stalker Visual
(@CGUID+25, 0, 0, 0, 1, 0, '101913'), -- Glowing Eyes Stalker - 101913 - Glowing Eyes Stalker Visual
(@CGUID+26, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+27, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+28, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+29, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+30, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+32, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+33, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+34, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+35, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+36, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+37, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+38, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+39, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+40, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+41, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+42, 0, 0, 0, 1, 0, ''), -- Frozen Servitor Spawn Points
(@CGUID+43, 0, 0, 0, 1, 0, ''), -- Arcurion Spawn Visual Stalker
(@CGUID+44, 0, 0, 0, 1, 0, '103251'), -- Thrall - 103251 - Icy Tomb
(@CGUID+45, 0, 0, 0, 1, 0, ''), -- Ice Wall Exit Stalker
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- Arcurion
(@CGUID+49, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+50, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+52, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+53, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+54, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+55, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+56, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+58, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+59, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+60, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+61, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+62, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+63, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+64, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+65, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+66, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+67, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+68, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+69, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+70, 0, 0, 0, 1, 0, ''), -- Hulking Jormungar
(@CGUID+71, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+72, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+74, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+75, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+76, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+77, 0, 0, 8, 1, 0, '107455'), -- Thrall - 107455 - Earth-Warder
(@CGUID+78, 0, 0, 0, 1, 0, '102921'), -- Twilight Assassin - 102921 - Stealth
(@CGUID+79, 0, 0, 0, 1, 0, '102921'), -- Twilight Assassin - 102921 - Stealth
(@CGUID+80, 0, 0, 0, 1, 0, '102921'), -- Twilight Assassin - 102921 - Stealth
(@CGUID+81, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+82, 0, 0, 0, 1, 0, ''), -- Twilight Assassin
(@CGUID+83, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+84, 0, 0, 0, 1, 0, ''), -- Twilight Ranger
(@CGUID+85, 0, 0, 0, 1, 0, ''), -- Twilight Bruiser
(@CGUID+86, 0, 0, 0, 1, 0, ''), -- Twilight Thug
(@CGUID+87, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+88, 0, 0, 0, 1, 0, ''), -- Twilight Ranger
(@CGUID+89, 0, 0, 0, 1, 0, ''), -- Twilight Bruiser
(@CGUID+90, 0, 0, 0, 1, 0, ''), -- Twilight Thug
(@CGUID+91, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+92, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+93, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+94, 0, 0, 0, 1, 0, ''), -- Twilight Thug
(@CGUID+95, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+96, 0, 0, 0, 1, 0, ''), -- Twilight Bruiser
(@CGUID+97, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+98, 0, 0, 0, 1, 0, ''), -- Twilight Ranger
(@CGUID+99, 0, 0, 0, 1, 0, ''), -- Twilight Assassin
(@CGUID+100, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+101, 0, 0, 0, 1, 0, ''), -- Twilight Bruiser
(@CGUID+102, 0, 0, 0, 1, 0, '37816'), -- Twilight Shadow-Walker - 37816 - Shadowform
(@CGUID+103, 0, 0, 0, 1, 0, ''), -- Twilight Bruiser
(@CGUID+104, 0, 0, 0, 1, 0, ''), -- Twilight Ranger
(@CGUID+105, 0, 0, 0, 1, 0, ''), -- Twilight Thug
(@CGUID+106, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+107, 0, 0, 0, 1, 0, ''), -- Asira Dawnslayer
(@CGUID+108, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+109, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+110, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+111, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+112, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+113, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+114, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+115, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+116, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+117, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+118, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+119, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+120, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+121, 0, 0, 50331648, 1, 0, ''), -- Target Dummy
(@CGUID+122, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+123, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+124, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+125, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+126, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+127, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+128, 0, 0, 50331648, 1, 0, ''), -- Twilight Drake
(@CGUID+129, 0, 0, 50331648, 1, 0, ''), -- Twilight Drake
(@CGUID+130, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+131, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+132, 0, 0, 50331648, 1, 0, ''), -- Twilight Drake
(@CGUID+133, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+134, 0, 0, 0, 1, 0, '102231'), -- Faceless Brute - 102231 - Aggro Periodic
(@CGUID+135, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+136, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+137, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+138, 0, 0, 50331648, 1, 0, ''), -- Twilight Drake
(@CGUID+139, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+140, 0, 0, 0, 1, 0, ''), -- Wastes Digger
(@CGUID+141, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+142, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+143, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+144, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+145, 0, 0, 0, 1, 0, ''), -- Magnataur Patriarch
(@CGUID+146, 0, 0, 0, 1, 0, ''), -- Snowplain Shaman
(@CGUID+147, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+148, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+149, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+150, 0, 0, 0, 1, 0, ''), -- Snowplain Zealot
(@CGUID+151, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+152, 0, 0, 0, 1, 0, '102231'), -- Faceless Brute - 102231 - Aggro Periodic
(@CGUID+153, 0, 0, 50331648, 1, 0, ''), -- Twilight Drake
(@CGUID+154, 0, 0, 0, 1, 0, ''), -- Dragonbone Condor
(@CGUID+155, 0, 0, 0, 1, 0, ''), -- Magnataur Patriarch
(@CGUID+156, 0, 0, 0, 1, 0, ''), -- Magnataur Youngling
(@CGUID+157, 0, 0, 1, 1, 0, ''), -- Dragonbone Condor
(@CGUID+158, 0, 0, 0, 1, 0, ''), -- Snowplain Zealot
(@CGUID+159, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+160, 0, 0, 0, 1, 0, ''), -- Emaciated Mammoth Bull
(@CGUID+161, 0, 0, 0, 1, 0, '29266'), -- Emaciated Mammoth Bull - 29266 - Permanent Feign Death
(@CGUID+162, 0, 0, 0, 1, 0, ''), -- Snowplain Zealot
(@CGUID+163, 0, 0, 0, 1, 0, ''), -- Snowplain Shaman
(@CGUID+164, 0, 0, 0, 1, 0, ''), -- Snowplain Zealot
(@CGUID+165, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+166, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+167, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+168, 0, 0, 0, 1, 0, ''), -- Magnataur Youngling
(@CGUID+169, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+170, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+171, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+172, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+173, 0, 0, 0, 1, 0, ''), -- Snowplain Disciple
(@CGUID+174, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+175, 0, 0, 0, 1, 0, ''), -- Magnataur Alpha
(@CGUID+176, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+177, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+178, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+179, 0, 0, 50331648, 1, 0, '110160'), -- Twilight Portal - 110160 - Summon Cosmetic Siege Breaker Periodic
(@CGUID+180, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+181, 0, 0, 0, 1, 0, '102213'), -- Blood - 102213 - Summon Blood
(@CGUID+182, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+183, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+184, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+185, 0, 0, 50331648, 1, 0, ''), -- Cannon [Do Not Translate]
(@CGUID+186, 0, 0, 50331648, 1, 0, ''), -- Cannon [Do Not Translate]
(@CGUID+187, 0, 0, 50331648, 1, 0, '107576 105013'), -- Champion of Life - 107576 - Defend Wyrmrest, 105013 - Renew
(@CGUID+188, 0, 0, 50331648, 1, 0, '107576 105013'), -- Champion of Life - 107576 - Defend Wyrmrest, 105013 - Renew
(@CGUID+189, 0, 0, 50331648, 1, 0, '107576 105124'), -- Time Warden - 107576 - Defend Wyrmrest, 105124 - Step Through Time
(@CGUID+190, 0, 0, 50331648, 1, 0, ''), -- Cannon [Do Not Translate]
(@CGUID+191, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+192, 0, 0, 0, 1, 0, '102231'), -- Faceless Brute - 102231 - Aggro Periodic
(@CGUID+193, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+194, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+195, 0, 0, 50331648, 1, 0, ''), -- Cannon [Do Not Translate]
(@CGUID+196, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+197, 0, 0, 0, 1, 0, ''), -- Morchok
(@CGUID+198, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+199, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+200, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+201, 0, 0, 50331648, 1, 0, '110160'), -- Twilight Portal - 110160 - Summon Cosmetic Siege Breaker Periodic
(@CGUID+202, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+203, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+204, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+205, 0, 0, 0, 1, 0, '107773'), -- Earthcaller Torunscar - 107773 - Earthen Ring Instakill
(@CGUID+206, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+207, 0, 0, 0, 1, 0, '102550 102232'), -- Thrall - 102550 - Root Thrall, 102232 - Aggro Thrall
(@CGUID+208, 0, 0, 0, 1, 0, '102213'), -- Blood - 102213 - Summon Blood
(@CGUID+209, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+210, 0, 0, 0, 1, 0, '107773'), -- Stormcaller Jalara - 107773 - Earthen Ring Instakill
(@CGUID+211, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+212, 0, 0, 0, 1, 0, '102231'), -- Faceless Shadow Weaver - 102231 - Aggro Periodic
(@CGUID+213, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+214, 0, 0, 0, 1, 0, '107773 79949'), -- Tawn Winterbluff - 107773 - Earthen Ring Instakill, 79949 - Water Shield
(@CGUID+215, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+216, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+217, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+218, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+219, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+220, 0, 0, 0, 1, 0, '107773'), -- Hargoth Dimblaze - 107773 - Earthen Ring Instakill
(@CGUID+221, 0, 0, 0, 1, 0, '102231'), -- Shadow Borer - 102231 - Aggro Periodic
(@CGUID+222, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+223, 0, 0, 0, 1, 0, '102254 102255 102287'), -- Dark Haze - 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze
(@CGUID+224, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+225, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+226, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+227, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+228, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+229, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+230, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+231, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+232, 0, 0, 0, 1, 0, '102254 102255 102287'), -- Dark Haze - 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze
(@CGUID+233, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+234, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+235, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+236, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+237, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+238, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+239, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+240, 0, 0, 0, 1, 0, '102231'), -- Shadow Borer - 102231 - Aggro Periodic
(@CGUID+241, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+242, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+243, 0, 0, 0, 1, 0, '102231'), -- Faceless Shadow Weaver - 102231 - Aggro Periodic
(@CGUID+244, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+245, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+246, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+247, 0, 0, 0, 1, 0, ''), -- Blood
(@CGUID+248, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+249, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+250, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+251, 0, 0, 50331648, 1, 0, '110160'), -- Twilight Portal - 110160 - Summon Cosmetic Siege Breaker Periodic
(@CGUID+252, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+253, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+254, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+255, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+256, 0, 0, 50331648, 1, 0, '110160'), -- Twilight Portal - 110160 - Summon Cosmetic Siege Breaker Periodic
(@CGUID+257, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+258, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+259, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Time - 107576 - Defend Wyrmrest
(@CGUID+260, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+261, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+262, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+263, 0, 0, 0, 1, 0, ''), -- Twilight Siege Captain
(@CGUID+264, 0, 0, 50331648, 1, 0, ''), -- Arcane Warden
(@CGUID+265, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+266, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+267, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+268, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+269, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+270, 0, 0, 50331648, 1, 0, '107576 105124'), -- Time Warden - 107576 - Defend Wyrmrest, 105124 - Step Through Time
(@CGUID+271, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+272, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+273, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+274, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+275, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+276, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+277, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+278, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+279, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+280, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+281, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Time - 107576 - Defend Wyrmrest
(@CGUID+282, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+283, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+284, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+285, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+286, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+287, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+288, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+289, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+290, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+291, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+292, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+293, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+294, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+295, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+296, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+297, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+298, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+299, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+300, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+301, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+302, 0, 0, 50331648, 1, 0, ''), -- Champion of Magic
(@CGUID+303, 0, 0, 0, 1, 0, '102231'), -- Shadow Borer - 102231 - Aggro Periodic
(@CGUID+304, 0, 0, 0, 1, 0, '102254 102255 102287'), -- Dark Haze - 102254 - Pooled Blood Puddle Visual, 102255 - Grow Visual, 102287 - Dark Haze
(@CGUID+305, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+306, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+307, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+308, 0, 0, 0, 1, 0, '102231'), -- Faceless Shadow Weaver - 102231 - Aggro Periodic
(@CGUID+309, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+310, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+311, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+312, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+313, 0, 0, 0, 1, 0, ''), -- Holy Shield
(@CGUID+314, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+315, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+316, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+317, 0, 0, 0, 1, 0, ''), -- Throw Loc
(@CGUID+318, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+319, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+320, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+321, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+322, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+323, 0, 0, 50331648, 1, 0, ''), -- Force of Destruction
(@CGUID+324, 0, 0, 50331648, 1, 0, ''), -- Time Warden
(@CGUID+325, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+326, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+327, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+328, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+329, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+330, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+331, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+332, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+333, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+334, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+335, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+336, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+337, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Time - 107576 - Defend Wyrmrest
(@CGUID+338, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+339, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+340, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+341, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+342, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+343, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+344, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+345, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+346, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+347, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+348, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+349, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+350, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+351, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+352, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+353, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+355, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+356, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+357, 0, 0, 0, 1, 0, '104516'), -- Earthen Shell Target - 104516 - Seeping Light
(@CGUID+358, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+359, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+360, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+361, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+362, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+363, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+364, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+365, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+366, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+367, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+368, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Time - 107576 - Defend Wyrmrest
(@CGUID+369, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+370, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+371, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+372, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+373, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+374, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+375, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+376, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+377, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+378, 0, 0, 0, 1, 0, ''), -- Archbishop Benedictus
(@CGUID+379, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+380, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+381, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+382, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+383, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+384, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+385, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+386, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+387, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+388, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+389, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+390, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+391, 0, 0, 0, 1, 0, ''), -- Siege Breaker Stalker
(@CGUID+392, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+393, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+394, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+395, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+396, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+397, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+398, 0, 0, 0, 1, 0, '108437'), -- Thrall - 108437 - Lavaburst Trigger
(@CGUID+399, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+400, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+401, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+402, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+403, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+404, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+405, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+406, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+407, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+408, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+409, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+410, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+411, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+412, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+413, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+414, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+415, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+416, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+417, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+418, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+419, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+420, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+421, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+422, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+423, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+424, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+425, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+426, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Time - 107576 - Defend Wyrmrest
(@CGUID+427, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+428, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+429, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+430, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+431, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+432, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+433, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+434, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+435, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+436, 0, 0, 50331648, 1, 0, '107576'), -- Dream Warden - 107576 - Defend Wyrmrest
(@CGUID+437, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+438, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Magic - 107576 - Defend Wyrmrest
(@CGUID+439, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+440, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+441, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+442, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+443, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+444, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+445, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+446, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+447, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+448, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+449, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+450, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+451, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+452, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+453, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+454, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+455, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+456, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+457, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+458, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+459, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+460, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+461, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+462, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+463, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+464, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+465, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+466, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+467, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+468, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+469, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+470, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+471, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+472, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+473, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+474, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+475, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+476, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+477, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+478, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+479, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+480, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+481, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+482, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+483, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+484, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+485, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+486, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+487, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+488, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+489, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+490, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+491, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+492, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+493, 0, 0, 50331648, 1, 0, '103766'), -- Twilight Spark - 103766 - Unstable Twilight
(@CGUID+494, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+495, 0, 0, 50331648, 1, 0, ''), -- Life Warden
(@CGUID+496, 0, 0, 50331648, 1, 0, '107576 105066'), -- Champion of Magic - 107576 - Defend Wyrmrest, 105066 - Arcane Missile Barrage
(@CGUID+497, 0, 0, 50331648, 1, 0, ''), -- Arcane Warden
(@CGUID+498, 0, 0, 50331648, 1, 0, '107576'), -- Life Warden - 107576 - Defend Wyrmrest
(@CGUID+499, 0, 0, 50331648, 1, 0, ''), -- Champion of Life
(@CGUID+500, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+501, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+502, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+503, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+504, 0, 0, 50331648, 1, 0, '107577'), -- Portent of Twilight - 107577 - Attack Wyrmrest
(@CGUID+505, 0, 0, 50331648, 1, 0, '107576'), -- Champion of Life - 107576 - Defend Wyrmrest
(@CGUID+506, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+507, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+508, 0, 0, 50331648, 1, 0, '107577'), -- Force of Destruction - 107577 - Attack Wyrmrest
(@CGUID+509, 0, 0, 50331648, 1, 0, '107576'), -- Arcane Warden - 107576 - Defend Wyrmrest
(@CGUID+510, 0, 0, 50331648, 1, 0, '107576'), -- Time Warden - 107576 - Defend Wyrmrest
(@CGUID+511, 0, 0, 50331648, 1, 0, '107576'), -- Champion of the Emerald Dream - 107576 - Defend Wyrmrest
(@CGUID+512, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+513, 0, 0, 50331648, 1, 0, ''), -- Time Warden
(@CGUID+514, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Destruction - 107577 - Attack Wyrmrest
(@CGUID+515, 0, 0, 50331648, 1, 0, '107577'), -- Harbinger of Twilight - 107577 - Attack Wyrmrest
(@CGUID+516, 0, 0, 50331648, 1, 0, '107576'); -- Life Warden - 107576 - Defend Wyrmrest

SET @OGUID:= 203029;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 210096, 940, 5844, 5988, 3, 169,0, 4927.73, 331.5791, 107.9786, 4.83123, 0, 0, -0.663867, 0.7478507, 7200, 255, 1, 15595), -- Violett (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+1, 190236, 940, 5844, 5988, 3, 169,0, 4926.086, 1554.962, 222.3158, 4.017567, 0, 0, -0.9056072, 0.4241174, 7200, 255, 1, 15595), -- Gate (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+2, 210048, 940, 5844, 5988, 3, 169,0, 4711.874, 33.50868, 64.559, 0.4712385, 0, 0, 0.2334452, 0.97237, 7200, 255, 1, 15595), -- Icewall (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+3, 210082, 940, 5844, 5988, 3, 169,0, 3305.245, 59.69271, 344.3333, 5.445428, 0, 0, -0.4067364, 0.9135455, 7200, 255, 1, 15595), -- Horde Ship (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+4, 210026, 940, 5844, 5988, 3, 169,0, 4915.979, 291.8976, 95.59838, 0.4886916, -0.05324173, -0.02820015, 0.2406588, 0.9687381, 7200, 255, 1, 15595), -- Portal (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+5, 190352, 940, 5844, 5988, 3, 169,0, 3790.596, -690.3749, 223.0954, 5.916668, 0, 0, -0.1822348, 0.983255, 7200, 255, 0, 15595), -- Doodad_HU_Portcullis03 (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+6, 210049, 940, 5844, 5988, 3, 169,0, 4864.135, 146.3802, 95.80873, 3.831001, 0, 0, -0.9411755, 0.3379182, 7200, 255, 0, 15595), -- Icewall (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+7, 210095, 940, 5844, 5988, 3, 169,0, 4927.73, 331.5791, 107.9786, 4.83123, 0, 0, -0.663867, 0.7478507, 7200, 255, 1, 15595), -- Schädel (Area: The Crystal Vice - Difficulty: 0)
(@OGUID+8, 210081, 940, 5844, 5988, 3, 169,0, 3748.939, 485.1094, 349.7552, 2.330013, 0, 0, 0.9187908, 0.3947448, 7200, 255, 1, 15595); -- Alliance Ship (Area: The Crystal Vice - Difficulty: 0)
-- 
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371139), -- Violett
(@OGUID+1, 0, 0, 0.9999986, -0.001654906), -- Gate
-- (@OGUID+3, 0, 0, 0, -2.421879), -- Horde Ship
(@OGUID+5, 0, 0, -0.1822356, 0.9832549), -- Doodad_HU_Portcullis03
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- Schädel
(@OGUID+8, 0, 0, 0, 1); -- Alliance Ship

DELETE FROM `creature_template_addon` WHERE `entry` IN (55466 /*55466 (Twilight Spark) - Unstable Twilight*/, 54971 /*54971 (Thrall) - Lavaburst Trigger*/, 54938 /*54938 (Archbishop Benedictus)*/, 55445 /*55445 (Earthen Shell Target) - Seeping Light*/, 54955 /*54955 (Holy Shield)*/, 54628 /*54628 (Dark Haze) - Pooled Blood Puddle Visual, Grow Visual, Dark Haze*/, 54686 /*54686 (Shadow Borer) - Aggro Periodic*/, 54665 /*54665 (Hargoth Dimblaze) - Earthen Ring Instakill*/, 54664 /*54664 (Tawn Winterbluff) - Earthen Ring Instakill, Water Shield*/, 54633 /*54633 (Faceless Shadow Weaver) - Aggro Periodic*/, 54666 /*54666 (Stormcaller Jalara) - Earthen Ring Instakill*/, 54634 /*54634 (Thrall) - Root Thrall, Aggro Thrall*/, 54663 /*54663 (Earthcaller Torunscar) - Earthen Ring Instakill*/, 58226 /*58226 (Morchok)*/, 58233 /*58233 (Twilight Portal) - Summon Cosmetic Siege Breaker Periodic*/, 26481 /*26481 (Magnataur Alpha)*/, 26705 /*26705 (Snowplain Disciple)*/, 58235 /*58235 (Twilight Siege Captain)*/, 54735 /*54735 (Throw Loc)*/, 54644 /*54644 (Blood)*/, 26271 /*26271 (Emaciated Mammoth Bull)*/, 26480 /*26480 (Magnataur Youngling)*/, 27278 /*27278 (Snowplain Zealot)*/, 27279 /*27279 (Snowplain Shaman)*/, 26295 /*26295 (Magnataur Patriarch)*/, 54632 /*54632 (Faceless Brute) - Aggro Periodic*/, 55636 /*55636 (Twilight Drake)*/, 55549 /*55549 (Life Warden)*/, 54968 /*54968 (Asira Dawnslayer)*/, 55415 /*55415 (Life Warden)*/, 55111 /*55111 (Twilight Thug)*/, 55112 /*55112 (Twilight Bruiser)*/, 55107 /*55107 (Twilight Ranger)*/, 55109 /*55109 (Twilight Shadow-Walker) - Shadowform*/, 55106 /*55106 (Twilight Assassin) - Stealth*/, 54972 /*54972 (Thrall) - Earth-Warder*/, 26492 /*26492 (Wastes Digger)*/, 26293 /*26293 (Hulking Jormungar)*/, 54590 /*54590 (Arcurion)*/, 26483 /*26483 (Dragonbone Condor)*/, 55728 /*55728 (Ice Wall Exit Stalker)*/, 55779 /*55779 (Thrall) - Icy Tomb*/, 57197 /*57197 (Arcurion Spawn Visual Stalker)*/, 54599 /*54599 (Glowing Eyes Stalker) - Glowing Eyes Stalker Visual*/, 54598 /*54598 (Frozen Servitor Spawn Points)*/, 55563 /*55563 (Frozen Shard)*/, 55559 /*55559 (Crystalline Elemental)*/, 54555 /*54555 (Frozen Servitor)*/, 54560 /*54560 (Frozen Servitor Spawn Stalker)*/, 55384 /*55384 (Frozen Servitor Spawn Stalker 2)*/, 55385 /*55385 (Frozen Servitor Spawn Stalker 3)*/, 54548 /*54548 (Thrall)*/, 54522 /*54522 (Glowing Eyes Stalker) - Glowing Eyes Stalker Visual*/, 55389 /*55389 (Frozen Servitor Spawn Stalker Entrance)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(55466, 0, 0, 50331648, 1, 0, '103766'), -- 55466 (Twilight Spark) - Unstable Twilight
(54971, 0, 0, 0, 1, 0, '108437'), -- 54971 (Thrall) - Lavaburst Trigger
(54938, 0, 0, 0, 1, 0, ''), -- 54938 (Archbishop Benedictus)
(55445, 0, 0, 0, 1, 0, '104516'), -- 55445 (Earthen Shell Target) - Seeping Light
(54955, 0, 0, 0, 1, 0, ''), -- 54955 (Holy Shield)
(54628, 0, 0, 0, 1, 0, '102254 102255 102287'), -- 54628 (Dark Haze) - Pooled Blood Puddle Visual, Grow Visual, Dark Haze
(54686, 0, 0, 0, 1, 0, '102231'), -- 54686 (Shadow Borer) - Aggro Periodic
(54665, 0, 0, 0, 1, 0, '107773'), -- 54665 (Hargoth Dimblaze) - Earthen Ring Instakill
(54664, 0, 0, 0, 1, 0, '107773 79949'), -- 54664 (Tawn Winterbluff) - Earthen Ring Instakill, Water Shield
(54633, 0, 0, 0, 1, 0, '102231'), -- 54633 (Faceless Shadow Weaver) - Aggro Periodic
(54666, 0, 0, 0, 1, 0, '107773'), -- 54666 (Stormcaller Jalara) - Earthen Ring Instakill
(54634, 0, 0, 0, 1, 0, '102550 102232'), -- 54634 (Thrall) - Root Thrall, Aggro Thrall
(54663, 0, 0, 0, 1, 0, '107773'), -- 54663 (Earthcaller Torunscar) - Earthen Ring Instakill
(58226, 0, 0, 0, 1, 0, ''), -- 58226 (Morchok)
(58233, 0, 0, 50331648, 1, 0, '110160'), -- 58233 (Twilight Portal) - Summon Cosmetic Siege Breaker Periodic
(26481, 0, 0, 0, 1, 0, ''), -- 26481 (Magnataur Alpha)
(26705, 0, 0, 0, 1, 0, ''), -- 26705 (Snowplain Disciple)
(58235, 0, 0, 0, 1, 0, ''), -- 58235 (Twilight Siege Captain)
(54735, 0, 0, 0, 1, 0, ''), -- 54735 (Throw Loc)
(54644, 0, 0, 0, 1, 0, ''), -- 54644 (Blood)
(26271, 0, 0, 0, 1, 0, ''), -- 26271 (Emaciated Mammoth Bull)
(26480, 0, 0, 0, 1, 0, ''), -- 26480 (Magnataur Youngling)
(27278, 0, 0, 0, 1, 0, ''), -- 27278 (Snowplain Zealot)
(27279, 0, 0, 0, 1, 0, ''), -- 27279 (Snowplain Shaman)
(26295, 0, 0, 0, 1, 0, ''), -- 26295 (Magnataur Patriarch)
(54632, 0, 0, 0, 1, 0, '102231'), -- 54632 (Faceless Brute) - Aggro Periodic
(55636, 0, 0, 50331648, 1, 0, ''), -- 55636 (Twilight Drake)
(55549, 0, 0, 50331648, 1, 0, ''), -- 55549 (Life Warden)
(54968, 0, 0, 0, 1, 0, ''), -- 54968 (Asira Dawnslayer)
(55415, 0, 0, 50331648, 1, 0, ''), -- 55415 (Life Warden)
(55111, 0, 0, 0, 1, 0, ''), -- 55111 (Twilight Thug)
(55112, 0, 0, 0, 1, 0, ''), -- 55112 (Twilight Bruiser)
(55107, 0, 0, 0, 1, 0, ''), -- 55107 (Twilight Ranger)
(55109, 0, 0, 0, 1, 0, '37816'), -- 55109 (Twilight Shadow-Walker) - Shadowform
(55106, 0, 0, 0, 1, 0, '102921'), -- 55106 (Twilight Assassin) - Stealth
(54972, 0, 0, 8, 1, 0, '107455'), -- 54972 (Thrall) - Earth-Warder
(26492, 0, 0, 0, 1, 0, ''), -- 26492 (Wastes Digger)
(26293, 0, 0, 0, 1, 0, ''), -- 26293 (Hulking Jormungar)
(54590, 0, 0, 0, 1, 0, ''), -- 54590 (Arcurion)
(26483, 0, 0, 0, 1, 0, ''), -- 26483 (Dragonbone Condor)
(55728, 0, 0, 0, 1, 0, ''), -- 55728 (Ice Wall Exit Stalker)
(55779, 0, 0, 0, 1, 0, '103251'), -- 55779 (Thrall) - Icy Tomb
(57197, 0, 0, 0, 1, 0, ''), -- 57197 (Arcurion Spawn Visual Stalker)
(54599, 0, 0, 0, 1, 0, '101913'), -- 54599 (Glowing Eyes Stalker) - Glowing Eyes Stalker Visual
(54598, 0, 0, 0, 1, 0, ''), -- 54598 (Frozen Servitor Spawn Points)
(55563, 0, 0, 0, 1, 0, ''), -- 55563 (Frozen Shard)
(55559, 0, 0, 0, 1, 0, ''), -- 55559 (Crystalline Elemental)
(54555, 0, 0, 0, 1, 0, ''), -- 54555 (Frozen Servitor)
(54560, 0, 0, 0, 1, 0, ''), -- 54560 (Frozen Servitor Spawn Stalker)
(55384, 0, 0, 0, 1, 0, ''), -- 55384 (Frozen Servitor Spawn Stalker 2)
(55385, 0, 0, 0, 1, 0, ''), -- 55385 (Frozen Servitor Spawn Stalker 3)
(54548, 0, 0, 0, 1, 0, ''), -- 54548 (Thrall)
(54522, 0, 0, 0, 1, 0, '101913'), -- 54522 (Glowing Eyes Stalker) - Glowing Eyes Stalker Visual
(55389, 0, 0, 0, 1, 0, ''); -- 55389 (Frozen Servitor Spawn Stalker Entrance)

UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=22479; -- 22479 (Sab'aoth)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=20515; -- 20515 (Harpax)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22491; -- 22491 (Kerpow Blastwrench)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='19818 34623' WHERE `entry`=18733; -- 18733 (Fel Reaver)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=22494; -- 22494 (Cosmowrench Bruiser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18884; -- 18884 (Warp Chaser)
UPDATE `creature_template_addon` SET `auras`='107576 105124' WHERE `entry`=56142; -- 56142 (Time Warden)
UPDATE `creature_template_addon` SET `auras`='107576 105013' WHERE `entry`=55911; -- 55911 (Champion of Life)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=56126; -- 56126 (Target Dummy)

UPDATE `creature_model_info` SET `BoundingRadius`=0.62 WHERE `DisplayID`=34274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5 WHERE `DisplayID`=16925;

UPDATE `creature_template` SET `npcflag`=3203 WHERE `entry`=22479; -- Sab'aoth
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.7142857 WHERE `entry`=54634; -- Thrall
UPDATE `creature_template` SET `unit_flags2`=2048, `dynamicflags`=0 WHERE `entry`=26271; -- Emaciated Mammoth Bull

DELETE FROM `vehicle_template_accessory` WHERE `entry`=55967;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(55967, 56142, 0, 1, 'Harbinger of Destruction - Time Warden', 8, 0); -- Harbinger of Destruction - Time Warden

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=55549 AND `spell_id`=103989;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=55967 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55549, 103989, 1, 0),
(55967, 46598, 1, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (254816,254760,254759,254758,254757,254756,254755,254753,254752,254750,254749,254748,254747,254746,254745,254744,254743,254741,254739,254738,254737,254736,254735,254734,254733,254732,254731,254730,254729,254728,254727,254725,254724,254723,254722,254719,254718,254717,254716,254711,254710,254709,254706,254705,254703,254702,254701,254699,254698,254697,254696,254695,254694,254693,254692,254690,254687,254686,254685,254683,254682,254681,254677,254674,254673,254671,254667,254665,254662,254661,254660,254659,254656,254655,254654,254653,254652,254651,254648,254643,254642,254640,254633,254632,254631,254623,254622,254621,254620,254619,254618,254616,254615,254613,254611,254605,254604,254592,254587,254561,254560,254552,254550,254511,254465,254435,254434,254436,254437,254438,254444,254818,254827,254828,254829,254830,254831,254832,254833,254834,254836,254837,254838,254839,254840,254841,254842,254843,254844,254845,254846,254847,254848,254849,254850,254851,254852,254853,254854);
DELETE FROM `gameobject_addon` WHERE `guid` IN (222212,222213,222215,222217,222219,222220);
