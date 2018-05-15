-- 
DELETE FROM `quest_poi` WHERE (`QuestID`=28834 AND `id`=2) OR (`QuestID`=28834 AND `id`=1) OR (`QuestID`=28834 AND `id`=0) OR (`QuestID`=28836 AND `id`=2) OR (`QuestID`=28836 AND `id`=1) OR (`QuestID`=28836 AND `id`=0);
INSERT INTO `quest_poi` (`QuestID`, `id`, `ObjectiveIndex`, `MapID`, `WorldMapAreaId`, `Floor`, `Priority`, `Flags`, `VerifiedBuild`) VALUES
(28834, 2, 32, 643, 767, 1, 0, 0, 26365), -- Rescue the Earthspeaker!
(28834, 1, 0, 643, 767, 1, 0, 7, 26365), -- Rescue the Earthspeaker!
(28834, 0, -1, 643, 767, 1, 0, 1, 26365), -- Rescue the Earthspeaker!
(28836, 2, 32, 643, 767, 1, 0, 0, 26365), -- Sins of the Sea Witch
(28836, 1, 0, 643, 767, 2, 0, 7, 26365), -- Sins of the Sea Witch
(28836, 0, -1, 643, 767, 1, 0, 1, 26365); -- Sins of the Sea Witch

DELETE FROM `quest_poi_points` WHERE (`QuestID`=28834 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=28836 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=28836 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=28836 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(28834, 2, 0, -617, 809, 26365), -- Rescue the Earthspeaker!
(28836, 2, 0, -617, 809, 26365), -- Sins of the Sea Witch
(28836, 1, 0, 193, 803, 26365), -- Sins of the Sea Witch
(28836, 0, 0, -617, 809, 26365); -- Sins of the Sea Witch

UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=28834 AND `Idx1`=1 AND `Idx2`=0); -- Rescue the Earthspeaker!
UPDATE `quest_poi_points` SET `VerifiedBuild`=26365 WHERE (`QuestID`=28834 AND `Idx1`=0 AND `Idx2`=0); -- Rescue the Earthspeaker!

SET @CGUID:=254836;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+577;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 53488, 643, 5004, 5004, 3, 169, 0, 0, 0, -628.6702, 804.8403, 247.681, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summon Enabler Stalker (Area: Throne of the Tides - Difficulty: 2) (Auras: 99201 - Summon Enabler)
(@CGUID+1, 50276, 643, 5004, 5004, 3, 169, 0, 0, 0, -616.7604, 803.3108, 245.253, 4.747295, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+2, 50278, 643, 5004, 5004, 3, 169, 0, 0, 0, -618.2656, 819.7743, 245.4425, 1.134464, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+3, 53488, 643, 5004, 5004, 3, 169, 0, 0, 0, -598.9757, 823.3489, 244.8928, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summon Enabler Stalker (Area: Throne of the Tides - Difficulty: 2) (Auras: 99201 - Summon Enabler)
(@CGUID+4, 50276, 643, 5004, 5004, 3, 169, 0, 0, 0, -611.7274, 815.2101, 245.1277, 0.541052, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+5, 50278, 643, 5004, 5004, 3, 169, 0, 0, 0, -610.4809, 796.3316, 245.1174, 4.153883, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+6, 53488, 643, 5004, 5004, 3, 169, 0, 0, 0, -595.5052, 795.4861, 244.8928, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summon Enabler Stalker (Area: Throne of the Tides - Difficulty: 2) (Auras: 99201 - Summon Enabler)
(@CGUID+7, 50278, 643, 5004, 5004, 3, 169, 0, 0, 0, -609.007, 807.0625, 244.6244, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+8, 53488, 643, 5004, 5004, 3, 169, 0, 0, 0, -567.1198, 810.2656, 244.9734, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Summon Enabler Stalker (Area: Throne of the Tides - Difficulty: 2) (Auras: 99201 - Summon Enabler)
(@CGUID+9, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -603.6129, 827.2743, 245.388, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+10, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -524.0555, 805.6702, 256.9915, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+11, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -438.9139, 769.7037, 270.5711, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 85211 - Water Bolt)
(@CGUID+12, 45620, 643, 5004, 5004, 3, 169, 0, 0, 0, -421.722, 830.59, 262.0083, 3.473205, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: ) (possible waypoints or random movement)
(@CGUID+13, 51391, 643, 5004, 5004, 3, 169, 0, 0, 0, -560.2465, 819.1996, 245.3967, 4.904375, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Throne of Tides Teleporter (Area: Throne of the Tides - Difficulty: 2) (Auras: 95293 - Teleporter Base Visual)
(@CGUID+14, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -500.5903, 804.8386, 257.168, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+15, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -479.9549, 803.1893, 253.4132, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+16, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -457.8351, 802.7327, 249.7082, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+17, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -548.1771, 807.5104, 246.4562, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+18, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -425.698, 829.125, 261.8723, 0.5934119, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+19, 45620, 643, 5004, 5004, 3, 169, 0, 0, 0, -405.825, 769.054, 261.0923, 3.089233, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: ) (possible waypoints or random movement)
(@CGUID+20, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.3368, 802.3281, 248.7223, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+21, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -408.694, 838.417, 260.4864, 0.2094395, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+22, 45620, 643, 5004, 5004, 3, 169, 0, 0, 0, -383.538, 768.479, 267.6173, 3.089233, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: ) (possible waypoints or random movement)
(@CGUID+23, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -423.0002, 767.6939, 267.9297, 6.179363, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+24, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -586.0226, 808.3559, 245.4128, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+25, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -625.9271, 810.1198, 246.8475, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+26, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -399.1267, 806.4028, 248.1572, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+27, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -387.75, 768.861, 267.4823, 0.2094395, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+28, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -609.2257, 790.7344, 245.3671, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+29, 45620, 643, 5004, 5004, 3, 169, 0, 0, 0, -404.481, 838.036, 260.6223, 3.089233, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: ) (possible waypoints or random movement)
(@CGUID+30, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -581.4739, 784.1632, 245.3917, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+31, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -580.9375, 826.7518, 245.4122, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+32, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -410.036, 769.436, 260.9573, 0.2094395, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+33, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -361.9618, 808.1545, 257.7555, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+34, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.061, 774.641, 295.1404, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+35, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -320.656, 719.738, 281.1503, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+36, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.368, 723.863, 281.7914, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+37, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -318.366, 888.009, 253.0233, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+38, 22517, 643, 5004, 5004, 3, 169, 0, 0, 0, -293.375, 981.314, 242.2833, 4.502949, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Large AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 76345 - Water Leak)
(@CGUID+39, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.151, 835.866, 295.1404, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+40, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -311.526, 782.5868, 261.0339, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+41, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -249.599, 805.063, 384.9963, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+42, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -253.316, 801.79, 263.7803, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+43, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -252.236, 813.972, 263.7803, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+44, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -317.2448, 809.434, 261.2558, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+45, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -317.957, 928.161, 248.3153, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+46, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -310.0642, 832.566, 259.9967, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+47, 22517, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.8594, 974.8472, 246.7041, 5.427974, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Large AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 76345 - Water Leak)
(@CGUID+48, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -249.599, 805.063, 295.1404, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+49, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -285.714, 799.069, 263.7803, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+50, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -285.38, 818.372, 263.7803, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+51, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -342.7049, 809.5555, 259.3411, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+52, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.109, 887.832, 251.6793, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+53, 22517, 643, 5004, 5004, 3, 169, 0, 0, 0, -312.4514, 957.0226, 243.4756, 5.393067, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Large AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 76345 - Water Leak)
(@CGUID+54, 44581, 643, 5004, 5004, 3, 169, 0, 0, 0, -111.391, 933.094, 273.8753, 5.480334, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Vehicle (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+55, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.151, 835.866, 384.9963, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+56, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -188.321, 805.252, 295.1404, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+57, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -134.991, 940.849, 293.6703, 0.03490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+58, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -157.358, 954.346, 302.8073, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+59, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.061, 774.641, 384.9963, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+60, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -168.613, 980.859, 310.3224, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+61, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -168.722, 966.649, 306.3033, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+62, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -144.283, 983.316, 230.4773, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+63, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -171.681, 998.184, 304.9164, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+64, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -146.606, 1002.71, 310.8013, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+65, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -153.927, 1012.31, 304.4124, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+66, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -249.599, 805.063, 476.5523, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+67, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -188.321, 805.252, 476.5523, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+68, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -146.576, 987.587, 314.3933, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+69, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -143.552, 963.455, 310.5244, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+70, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -146.424, 955.934, 306.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+71, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -159.903, 996.75, 310.6373, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+72, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.151, 835.866, 476.5523, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+73, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -152.712, 982.807, 313.7444, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+74, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -188.321, 805.252, 384.9963, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+75, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -154.003, 964.913, 310.2063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+76, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -219.061, 774.641, 476.5523, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2) (Auras: 85170 - Shock Defense)
(@CGUID+77, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -105.349, 1015.8, 285.8954, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+78, 48983, 643, 5004, 5004, 3, 169, 0, 0, 0, 245.5052, 749.3125, 807.6003, 2.391101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Geyser (Area: Throne of the Tides - Difficulty: 2) (Auras: 91347 - Geyser)
(@CGUID+79, 48983, 643, 5004, 5004, 3, 169, 0, 0, 0, 244.849, 855.1302, 807.5911, 3.909538, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Geyser (Area: Throne of the Tides - Difficulty: 2) (Auras: 91347 - Geyser)
(@CGUID+80, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, 51.1059, 802.1563, 846.4826, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
-- (@CGUID+81, 40655, UNKNOWN, 5004, 5004, 3, 169, 0, 0, 0, 0, 0, 0, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat (Area: Throne of the Tides - Difficulty: 2) (Auras: ) - !!! on transport - transport template not found !!!
(@CGUID+82, 48983, 643, 5004, 5004, 3, 169, 0, 0, 0, 138.0781, 749.1441, 807.5905, 0.7504916, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Geyser (Area: Throne of the Tides - Difficulty: 2) (Auras: 91347 - Geyser)
(@CGUID+83, 36171, 643, 5004, 5004, 3, 169, 0, 0, 0, -118.108, 954.753, 298.8474, 5.794493, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Infinite AOI) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+84, 48983, 643, 5004, 5004, 3, 169, 0, 0, 0, 115.4983, 802.7986, 808.3495, 6.230825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Geyser (Area: Throne of the Tides - Difficulty: 2) (Auras: 91347 - Geyser)
(@CGUID+85, 45030, 643, 5004, 5004, 3, 169, 0, 0, 0, -74.125, 852.818, 340.5083, 0.2792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Vehicle, Big (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+86, 48983, 643, 5004, 5004, 3, 169, 0, 0, 0, 137.7569, 855.8611, 807.7711, 5.51524, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Geyser (Area: Throne of the Tides - Difficulty: 2) (Auras: 91347 - Geyser)
(@CGUID+87, 50270, 643, 5004, 5004, 3, 169, 0, 0, 0, -616.7604, 808.7518, 245.6328, 3.263766, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Captain Taylor (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+88, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4493, 770.1429, 270.0137, 6.043383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+89, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.54, 770.0549, 271.3423, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+90, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0471, 770.7629, 270.6171, 6.251368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+91, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+92, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.1181, 808.9722, 260.9349, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+93, 21252, 643, 5004, 5004, 3, 169, 0, 0, 0, -309.347, 719.599, 276.0583, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Not Immune PC) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+94, 40577, 643, 5004, 5004, 3, 169, 0, 0, 0, -285.9392, 808.0417, 260.1373, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Sentinel (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+95, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -272.7153, 807.8299, 258.9762, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+96, 21252, 643, 5004, 5004, 3, 169, 0, 0, 0, -310.635, 922.342, 238.8223, 4.677482, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Not Immune PC) (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+97, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -256.5955, 808.0364, 259.165, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
-- (@CGUID+98, 40788, UNKNOWN, 5004, 5004, 3, 169, 0, 0, 0, 0.3978609, 0, 2.68787, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Mindbender Ghur'sha (Area: Throne of the Tides - Difficulty: 2) (Auras: 76339 - Unrelenting Agony) - !!! on transport - transport template not found !!!
(@CGUID+99, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, -421.6042, 839.7882, 263.3889, 4.842506, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+100, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, -411.3646, 778.8055, 262.9503, 1.528872, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+101, 41096, 643, 5004, 5004, 3, 169, 0, 0, 0, -409.0035, 839.2552, 262.0498, 5.119945, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+102, 41096, 643, 5004, 5004, 3, 169, 0, 0, 0, -396.9653, 779.9288, 265.7069, 1.55391, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+103, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0165, 770.7618, 270.6118, 6.247449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+104, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+105, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+106, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0471, 770.7629, 270.6171, 6.251368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+107, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0395, 770.7627, 270.6158, 6.250383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+108, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 85211 - Water Bolt)
(@CGUID+109, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0012, 770.7614, 270.6093, 6.245494, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+110, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+111, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+112, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0165, 770.7618, 270.6118, 6.247449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+113, 44656, 643, 5004, 5004, 3, 169, 0, 0, 0, -103.066, 910.313, 263.1674, 2.164208, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Add Spawner (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+114, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -439.9966, 769.9376, 271.0846, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+115, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6906, 769.0088, 269.2955, 6.077271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+116, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0623, 770.7634, 270.6196, 6.253349, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+117, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+118, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6494, 769.0002, 269.2897, 6.077984, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+119, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.002, 769.9387, 271.0871, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+120, 44656, 643, 5004, 5004, 3, 169, 0, 0, 0, -65.9722, 1031.8, 257.2863, 3.926991, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Add Spawner (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+121, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+122, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0165, 770.7618, 270.6118, 6.247449, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+123, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7867, 769.029, 269.309, 6.075617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+124, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.006, 769.9396, 271.089, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+125, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0241, 770.7621, 270.6132, 6.248422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+126, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+127, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7592, 769.0231, 269.3051, 6.076094, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+128, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.0046, 769.9393, 271.0884, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+129, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7455, 769.0203, 269.3032, 6.076324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+130, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.006, 769.9396, 271.089, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+131, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -34.05556, 810.4774, 801.454, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+132, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.79167, 809.467, 805.1479, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+133, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -32.35243, 798.1597, 801.7277, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+134, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.83854, 796.2708, 805.673, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+135, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -27.95139, 805.7361, 804.0556, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+136, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.75174, 799.0087, 805.7594, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+137, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -31.125, 807.9219, 802.3655, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+138, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.20486, 799.5851, 803.6364, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+139, 39959, 643, 5004, 5004, 3, 169, 0, 0, 0, -20.19097, 802.0608, 807.5371, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lady Naz'jar (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+140, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.51736, 810.2552, 803.2809, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+141, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -30.29688, 794.8941, 803.2464, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+142, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 69.88738, 814.4952, 806.3171, 1.334788, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+143, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 65.4325, 817.1699, 806.3171, 1.551777, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+144, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -103.4774, 802.0746, 796.6592, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+145, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 71.21053, 815.938, 806.3171, 1.361175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+146, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -54.44445, 803.0816, 797.1558, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+147, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -128.7379, 802.4809, 796.9691, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+148, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 66.10126, 815.2298, 806.3171, 1.459526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+149, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -178.8802, 801.9913, 797.0841, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+150, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 71.26827, 818.0963, 806.3171, 1.426958, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+151, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -153.5156, 803.0816, 796.5791, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+152, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 61.37276, 823.2509, 806.3171, 2.426346, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+153, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 69.97628, 819.6906, 806.3171, 1.505136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+154, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -81.20834, 801.6094, 797.083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+155, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 67.80486, 813.8999, 806.3171, 1.369688, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+156, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 66.16724, 819.086, 806.3171, 1.59144, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+157, 40579, 643, 5004, 5004, 3, 169, 0, 0, 0, 67.96173, 820.0815, 806.3171, 1.568952, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+158, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.61806, 802.1458, 805.629, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+159, 51395, 643, 5004, 5004, 3, 169, 0, 0, 0, -14.53993, 796.316, 808.2356, 1.58825, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Throne of Tides Teleporter (Area: Throne of the Tides - Difficulty: 2) (Auras: 95296 - Teleporter Active Visual)
(@CGUID+160, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 38.71181, 801.5816, 805.5076, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+161, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 37.33333, 779.8646, 806.4003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+162, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, 33.43056, 801.8403, 806.4003, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+163, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, 33.64236, 797.8368, 806.4003, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+164, 41096, 643, 5004, 5004, 3, 169, 0, 0, 0, 36.59722, 810.2656, 806.4003, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+165, 40634, 643, 5004, 5004, 3, 169, 0, 0, 0, 36.03993, 794.0677, 806.4003, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+166, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 36.8507, 825.9358, 806.4003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+167, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 8.27257, 802.8143, 807.0149, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+168, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, 33.52778, 806.1667, 806.4003, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+169, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 52.02951, 753.0799, 806.193, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+170, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 65.63021, 820.4844, 806.4003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+171, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 52.17708, 854.7934, 806.0573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+172, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 60.61632, 781.7604, 806.4003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+173, 40577, 643, 5004, 5004, 3, 169, 0, 0, 0, 53.11364, 824.3899, 806.3169, 0.01476906, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Sentinel (Area: Throne of the Tides - Difficulty: 2) (Auras: ) (possible waypoints or random movement)
(@CGUID+174, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 84.90799, 801.6302, 806.4003, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+175, 40584, 643, 5004, 5004, 3, 169, 0, 0, 0, -135.0625, 772.4739, 810.089, 1.448623, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual) (possible waypoints or random movement)
(@CGUID+176, 40584, 643, 5004, 5004, 3, 169, 0, 0, 0, -135.5764, 831.9948, 808.1715, 4.39823, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual) (possible waypoints or random movement)
(@CGUID+177, 41139, 643, 5004, 5004, 3, 169, 0, 0, 0, -103.3125, 775.8559, 810.9689, 1.448623, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+178, 40584, 643, 5004, 5004, 3, 169, 0, 0, 0, -103.8837, 832.8108, 808.739, 4.572762, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+179, 41139, 643, 5004, 5004, 3, 169, 0, 0, 0, -70.23785, 774.9618, 810.3751, 1.712018, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+180, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 128.2726, 802.2448, 808.4679, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+181, 40586, 643, 5004, 5004, 3, 169, 0, 0, 0, 191.8125, 802.4305, 807.7212, 3.036873, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Lady Naz'jar (Area: Throne of the Tides - Difficulty: 2) (Auras: 90495 - Waterspout)
(@CGUID+182, 41139, 643, 5004, 5004, 3, 169, 0, 0, 0, -72.86459, 831.441, 809.7106, 4.86808, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (Auras: 74048 - Water Window Jump Through Visual)
(@CGUID+183, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, 136.4965, 797.0886, 808.4933, 3.228859, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+184, 39616, 643, 5004, 5004, 3, 169, 0, 0, 0, 136.4896, 806.0139, 808.4933, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Invader (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+185, 41096, 643, 5004, 5004, 3, 169, 0, 0, 0, 136.809, 810.0139, 808.4933, 3.228859, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+186, 40634, 643, 5004, 5004, 3, 169, 0, 0, 0, 136.6007, 801.75, 808.4933, 3.228859, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+187, 41096, 643, 5004, 5004, 3, 169, 0, 0, 0, 136.6458, 792.5677, 808.4933, 3.228859, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Naz'jar Spiritmender (Area: Throne of the Tides - Difficulty: 2) (possible waypoints or random movement)
(@CGUID+188, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 145.1441, 845.1511, 807.6957, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+189, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 148.4271, 757.5121, 807.6461, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+190, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.83854, 796.2708, 805.673, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+191, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -31.125, 807.9219, 802.3655, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+192, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -32.35243, 798.1597, 801.7277, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+193, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.75174, 799.0087, 805.7594, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+194, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -34.05556, 810.4774, 801.454, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+195, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.51736, 810.2552, 803.2809, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+196, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.20486, 799.5851, 803.6364, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+197, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.79167, 809.467, 805.1479, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+198, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -30.29688, 794.8941, 803.2464, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+199, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -27.95139, 805.7361, 804.0556, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+200, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 168.658, 802.467, 808.0177, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+201, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.51736, 810.2552, 803.2809, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+202, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -34.05556, 810.4774, 801.454, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+203, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.79167, 809.467, 805.1479, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+204, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -27.95139, 805.7361, 804.0556, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+205, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -31.125, 807.9219, 802.3655, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+206, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 193.908, 774.3281, 807.8459, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+207, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 190.8542, 830.8698, 807.873, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+208, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.75174, 799.0087, 805.7594, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+209, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.20486, 799.5851, 803.6364, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+210, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -30.29688, 794.8941, 803.2464, 3.106686, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+211, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.83854, 796.2708, 805.673, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+212, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -32.35243, 798.1597, 801.7277, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+213, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 196.4497, 802.3195, 807.7212, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+214, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 223.1389, 802.7222, 808.0499, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+215, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -25.79167, 809.467, 805.1479, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+216, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -27.95139, 805.7361, 804.0556, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+217, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -31.125, 807.9219, 802.3655, 3.176499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+218, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -29.51736, 810.2552, 803.2809, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+219, 39960, 643, 5004, 5004, 3, 169, 0, 0, 0, -34.05556, 810.4774, 801.454, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Deep Murloc Drudge (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+220, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 231.8177, 843.3507, 807.885, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+221, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, 236.5851, 757.8958, 807.5884, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+222, 44404, 643, 5004, 5004, 3, 169, 0, 0, 0, 191.1979, 745.6007, 830.6442, 1.532863, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+223, 44404, 643, 5004, 5004, 3, 169, 0, 0, 0, 191.8733, 859.5452, 831.4933, 4.705678, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+224, 40633, 643, 5004, 5004, 3, 169, 0, 0, 0, 249.9375, 802.25, 828.8116, 3.147335, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Honor Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+225, 40633, 643, 5004, 5004, 3, 169, 0, 0, 0, 249.9375, 802.25, 828.8116, 3.147335, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Honor Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+226, 44404, 643, 5004, 5004, 3, 169, 0, 0, 0, 191.8733, 859.5452, 831.4933, 4.705678, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+227, 44404, 643, 5004, 5004, 3, 169, 0, 0, 0, 191.1979, 745.6007, 830.6442, 1.532863, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Tempest Witch (Area: Throne of the Tides - Difficulty: 2) (Auras: 75808 - Water Window Break Visual)
(@CGUID+228, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -296.477, 661.01, 281.4153, 2.23188, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+229, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.7917, 671.1694, 280.5178, 2.186387, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+230, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -296.0759, 668.8297, 280.8867, 2.188809, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+231, 40936, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.3462, 664.1631, 281.7034, 2.1634, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Faceless Watcher (Area: Throne of the Tides - Difficulty: 2) (Auras: 76604 - Void Rip) (possible waypoints or random movement)
(@CGUID+232, 40792, 643, 5004, 5004, 3, 169, 0, 0, 0, -146.8663, 981.5313, 230.4787, 2.949606, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Neptulon (Area: Throne of the Tides - Difficulty: 2) (Auras: 76952 - Purify)
(@CGUID+233, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -288.911, 667.142, 282.2543, 2.14487, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+234, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -296.523, 665.198, 281.0583, 2.25458, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+235, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.146, 662.971, 281.3593, 2.202956, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+236, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.938, 659.363, 281.7794, 2.262644, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+237, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.068, 665.408, 281.9814, 2.15424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+238, 40936, 643, 5004, 5004, 3, 169, 0, 0, 0, -224.863, 642.969, 287.3143, 3.490659, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Watcher (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+239, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+240, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -251.5156, 643.8108, 285.8642, 5.270895, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2) (Auras: 76410 - Water Jet)
(@CGUID+241, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -252.4879, 646.2882, 285.6189, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+242, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+243, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.8264, 669.691, 279.9994, 2.753881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+244, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -246.6615, 643.033, 286.2367, 3.735005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2) (Auras: 76410 - Water Jet)
(@CGUID+245, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -256.1823, 637.0452, 285.7028, 2.530727, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+246, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+247, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.9045, 667.1632, 280.3178, 1.095781, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+248, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+249, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -246.9601, 638.0521, 286.1168, 2.373648, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2) (Auras: 76410 - Water Jet)
(@CGUID+250, 40936, 643, 5004, 5004, 3, 169, 0, 0, 0, -294.703, 676.158, 280.9214, 3.804818, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Watcher (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+251, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.7465, 672.2882, 279.8831, 3.661204, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+252, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+253, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+254, 40936, 643, 5004, 5004, 3, 169, 0, 0, 0, -224.618, 634.016, 287.2314, 2.879793, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Watcher (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+255, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.5799, 675.059, 279.8106, 2.304396, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+256, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -252.1979, 638.9879, 285.7877, 0.715585, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2) (Auras: 76410 - Water Jet)
(@CGUID+257, 40935, 643, 5004, 5004, 3, 169, 0, 0, 0, -254.9913, 641.8264, 285.6591, 2.897247, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Hunter (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+258, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+259, 40943, 643, 5004, 5004, 3, 169, 0, 0, 0, -248.967, 640.9132, 286.041, 2.844887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Gilgoblin Aquamage (Area: Throne of the Tides - Difficulty: 2) (Auras: 76406 - Water Jet)
(@CGUID+260, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+261, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+262, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+263, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+264, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+265, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+266, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+267, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+268, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+269, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+270, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+271, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+272, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+273, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+274, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+275, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+276, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -358.7208, 764.5826, 275.9673, 6.031887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+277, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+278, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.75, 956.075, 253.9413, 5.707227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: 82953 - Ozumat Ink)
(@CGUID+279, 40925, 643, 5004, 5004, 3, 169, 0, 0, 0, -309.1018, 915.3441, 239.4511, 4.570662, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Tainted Sentry (Area: Throne of the Tides - Difficulty: 2) (Auras: 76625 - Summon Unstable Corruptions) (possible waypoints or random movement)
(@CGUID+280, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.8, 973.512, 252.4223, 5.707227, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: 82953 - Ozumat Ink)
(@CGUID+281, 40925, 643, 5004, 5004, 3, 169, 0, 0, 0, -228.2951, 977.4132, 231.7018, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Sentry (Area: Throne of the Tides - Difficulty: 2) (Auras: 76625 - Summon Unstable Corruptions)
(@CGUID+282, 22515, 643, 5004, 5004, 3, 169, 0, 0, 0, -280.476, 986.049, 251.8123, 5.078908, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- World Trigger (Area: Throne of the Tides - Difficulty: 2) (Auras: 82953 - Ozumat Ink)
(@CGUID+283, 40925, 643, 5004, 5004, 3, 169, 0, 0, 0, -228.2483, 985.9496, 231.6591, 3.071779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Tainted Sentry (Area: Throne of the Tides - Difficulty: 2) (Auras: 76625 - Summon Unstable Corruptions)
(@CGUID+284, 40925, 643, 5004, 5004, 3, 169, 0, 0, 0, -285.6053, 964.0278, 236.4931, 3.838374, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26365), -- Tainted Sentry (Area: Throne of the Tides - Difficulty: 2) (Auras: 76625 - Summon Unstable Corruptions) (possible waypoints or random movement)
(@CGUID+285, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.9781, 770.7604, 270.6053, 6.242595, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+286, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+287, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0395, 770.7627, 270.6158, 6.250383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+288, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+289, 40765, 643, 5004, 5004, 3, 169, 0, 0, 0, 51.9911, 802.6801, 888.0374, 6.198466, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Commander Ulthok (Area: Throne of the Tides - Difficulty: 2) (Auras: 76017 - Ulthok Intro Visual State)
(@CGUID+290, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+291, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -309.7928, 912.5019, 239.8704, 1.335766, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+292, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+293, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -310.2863, 909.6929, 240.4176, 4.069224, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+294, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+295, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+296, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -310.0808, 909.6741, 240.412, 3.994689, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+297, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+298, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.8094, 952.9477, 236.2822, 5.890752, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+299, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+300, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+301, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+302, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -378.2955, 767.4971, 270.2835, 0.01471755, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+303, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -270.484, 975.3795, 236.8476, 3.852387, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+304, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -272.441, 973.3168, 236.8856, 0.4456027, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+305, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+306, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -298.1781, 954.262, 235.8903, 1.001435, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+307, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+308, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+309, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -270.9366, 977.1397, 236.8224, 2.280367, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+310, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -436.6898, 769.2233, 269.5162, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 85211 - Water Bolt)
(@CGUID+311, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+312, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+313, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+314, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4797, 770.1504, 270.0186, 6.043761, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+315, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.54, 770.0549, 271.3423, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+316, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+317, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+318, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+319, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0241, 770.7621, 270.6132, 6.248422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+320, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
-- (@CGUID+321, 92870, 643, 5004, 5004, 3, 169, 0, 0, 0, -508.3617, 804.9224, 266.9508, 0.02312139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Sindragosa's Fury (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+322, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+323, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0471, 770.7629, 270.6171, 6.251368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+324, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+325, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+326, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0395, 770.7627, 270.6158, 6.250383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+327, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+328, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+329, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+330, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+331, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+332, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+333, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+334, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+335, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+336, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+337, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+338, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+339, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+340, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -439.9966, 769.9376, 271.0846, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+341, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6769, 769.006, 269.2936, 6.077507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+342, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+343, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+344, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+345, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+346, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0471, 770.7629, 270.6171, 6.251368, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+347, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+348, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+349, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+350, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+351, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7455, 769.0203, 269.3032, 6.076324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+352, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.0073, 769.9399, 271.0896, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+353, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+354, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+355, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+356, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7181, 769.0146, 269.2993, 6.076792, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+357, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.002, 769.9387, 271.0871, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+358, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+359, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7592, 769.0231, 269.3051, 6.076094, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+360, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+361, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.0087, 769.9402, 271.0903, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+362, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+363, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+364, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+365, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+366, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+367, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+368, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+369, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+370, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+371, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+372, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+373, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4998, 770.1552, 270.0219, 6.044028, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+374, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.548, 770.0566, 271.3461, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+375, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+376, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+377, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+378, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+379, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+380, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+381, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6906, 769.0088, 269.2955, 6.077271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+382, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.0046, 769.9393, 271.0884, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+383, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+384, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+385, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+386, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+387, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4897, 770.1528, 270.0203, 6.043887, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+388, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.5413, 770.0552, 271.3429, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+389, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+390, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+391, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0241, 770.7621, 270.6132, 6.248422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+392, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+393, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+394, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+395, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+396, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+397, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4695, 770.1479, 270.017, 6.043641, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+398, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.544, 770.0558, 271.3442, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+399, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+400, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+401, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+402, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+403, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+404, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+405, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+406, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6906, 769.0088, 269.2955, 6.077271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+407, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+408, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -439.9993, 769.9382, 271.0858, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2) (Auras: 85211 - Water Bolt)
(@CGUID+409, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+410, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+411, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+412, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+413, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+414, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -439.994, 769.937, 271.0833, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+415, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6355, 768.9974, 269.2878, 6.078218, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+416, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+417, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+418, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+419, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4695, 770.1479, 270.017, 6.043641, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+420, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.5387, 770.0546, 271.3416, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+421, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+422, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+423, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+424, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+425, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.52, 770.1602, 270.0252, 6.044287, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+426, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.5438, 770.0559, 271.3448, 6.070781, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+427, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+428, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+429, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+430, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+431, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0088, 770.7616, 270.6106, 6.246471, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+432, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+433, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+434, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+435, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+436, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+437, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+438, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+439, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7181, 769.0146, 269.2993, 6.076792, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+440, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -419.548, 767.3745, 268.4773, 6.166172, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+441, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+442, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+443, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+444, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+445, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+446, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -422.8674, 767.6801, 267.9077, 6.179697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+447, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+448, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+449, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -406.9185, 767.0944, 269.2914, 6.261036, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+450, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+451, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+452, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+453, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+454, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -402.6722, 766.2968, 265.8526, 6.264995, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+455, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+456, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -398.8545, 767.8329, 271.7672, 0.0006884783, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+457, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+458, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -397.9276, 766.3483, 266.2505, 0.03699381, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+459, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -398.9358, 767.6356, 273.8051, 6.220333, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+460, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+461, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+462, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+463, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -418.0725, 767.2133, 267.123, 6.193002, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+464, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+465, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -406.2899, 767.5161, 269.9694, 6.276873, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+466, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+467, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+468, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+469, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+470, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+471, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+472, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -402.6597, 766.2965, 265.853, 6.265087, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+473, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+474, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -386.3977, 767.2345, 274.6118, 6.202915, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+475, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+476, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -397.9276, 766.3483, 266.2505, 0.03699381, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+477, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+478, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+479, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -392.8012, 767.4155, 274.3909, 6.214547, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+480, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+481, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+482, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -402.7597, 766.2983, 265.8493, 6.264351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+483, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+484, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -398.8349, 767.8334, 273.5405, 6.223954, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+485, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+486, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+487, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+488, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+489, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+490, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+491, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+492, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -397.9156, 766.3488, 266.2519, 0.03709382, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+493, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -398.8584, 767.6307, 273.8154, 6.220333, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+494, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+495, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -413.1039, 766.8049, 266.4181, 6.210011, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+496, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -411.4561, 768.2091, 270.4888, 0.004991191, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+497, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+498, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+499, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+500, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -422.8785, 767.6812, 267.9095, 6.179667, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+501, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+502, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -425.83, 768.1109, 269.0852, 6.165987, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+503, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+504, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+505, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+506, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+507, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+508, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+509, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.536, 770.0541, 271.3404, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+510, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.429, 770.138, 270.0104, 6.043131, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+511, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+512, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+513, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+514, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+515, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -439.998, 769.9379, 271.0852, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+516, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+517, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.6769, 769.006, 269.2936, 6.077507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+518, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+519, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+520, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+521, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.983, 951.62, 235.2573, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+522, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+523, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0395, 770.7627, 270.6158, 6.250383, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+524, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+525, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+526, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+527, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+528, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+529, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4797, 770.1504, 270.0186, 6.043761, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+530, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.54, 770.0549, 271.3423, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+531, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.736, 952.082, 236.1343, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+532, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.064, 942.363, 235.8433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+533, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0241, 770.7621, 270.6132, 6.248422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+534, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+535, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -282.672, 973.602, 236.0653, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+536, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -297.773, 961.759, 235.5713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+537, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.304, 948.014, 235.4513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+538, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.55, 957.932, 236.0663, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+539, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.573, 959.401, 235.4883, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+540, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+541, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4998, 770.1552, 270.0219, 6.044028, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+542, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.5427, 770.0555, 271.3435, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+543, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.705, 969.608, 235.7383, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+544, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -290.519, 966.533, 235.8633, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+545, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+546, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+547, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -292.42, 970.998, 235.9253, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+548, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -295.203, 961.87, 235.8903, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+549, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.5387, 770.0546, 271.3416, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+550, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -437.4594, 770.1454, 270.0154, 6.043514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+551, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -304.451, 955.915, 235.4123, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+552, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.918, 948.363, 235.8583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+553, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -302.899, 948.047, 235.7713, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+554, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.224, 941.321, 235.9063, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+555, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -291.816, 972.729, 235.9783, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+556, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -307.571, 947.88, 235.6393, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+557, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -308.24, 946.118, 235.7183, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+558, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -299.323, 957.382, 235.6283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+559, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -301.661, 955.981, 235.4143, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+560, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -432.7455, 769.0203, 269.3032, 6.076324, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+561, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -440.0046, 769.9393, 271.0884, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+562, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.799, 951.611, 235.7513, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+563, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -300.198, 962.085, 235.5273, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+564, 40923, 643, 5004, 5004, 3, 169, 0, 0, 0, -306.339, 951.547, 235.4433, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unstable Corruption (Area: Throne of the Tides - Difficulty: 2) (Auras: 76362 - Unstable Corruption Growth)
(@CGUID+565, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.0241, 770.7621, 270.6132, 6.248422, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+566, 45621, 643, 5004, 5004, 3, 169, 0, 0, 0, -441.082, 770.172, 271.5993, 6.070463, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Elemental Guard (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+567, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -387.9229, 766.9808, 268.0077, 0.07349079, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )
(@CGUID+568, 44864, 643, 5004, 5004, 3, 169, 0, 0, 0, -153.333, 982.807, 229.5483, 2.792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Combat Trigger (Area: Throne of the Tides - Difficulty: 2)
-- (@CGUID+569, 44950, UNKNOWN, 5004, 5004, 3, 169, 0, 0, 0, -0.6934912, -3.64126, 1.543307, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Unyielding Behemoth (Hand Visual) (Area: Throne of the Tides - Difficulty: 2) (Auras: 46598 - Ride Vehicle Hardcoded, 83976 - Shrink) - !!! on transport - transport template not found !!!
(@CGUID+570, 44566, 643, 5004, 5004, 3, 169, 0, 0, 0, -64.0677, 845.455, 310.6913, 2.181662, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat (Area: Throne of the Tides - Difficulty: 2) (Auras: 83126 - Ozumat Globe Impact Periodic)
(@CGUID+571, 44656, 643, 5004, 5004, 3, 169, 0, 0, 0, -103.066, 910.313, 263.1674, 2.164208, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ozumat Add Spawner (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+572, 44752, 643, 5004, 5004, 3, 169, 0, 0, 0, -165.0469, 1002.967, 230.5902, 5.393067, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Sapper (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+573, 44752, 643, 5004, 5004, 3, 169, 0, 0, 0, -125.7309, 1004.01, 230.3206, 3.892084, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Sapper (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+574, 44752, 643, 5004, 5004, 3, 169, 0, 0, 0, -168.4375, 962.1979, 230.2837, 0.4886922, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Faceless Sapper (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+575, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -368.6192, 766.7662, 272.7951, 6.119343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+576, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -354.9971, 763.6516, 277.2143, 6.063018, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2)
(@CGUID+577, 45672, 643, 5004, 5004, 3, 169, 0, 0, 0, -358.6903, 764.5749, 275.9777, 6.031822, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Naz'jar Soldier (Area: Throne of the Tides - Difficulty: 2) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+577;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+1, 0, 0, 0, 1, 0, '29266'), -- Naz'jar Spiritmender - 29266 - Permanent Feign Death
(@CGUID+2, 0, 0, 0, 1, 0, '29266'), -- Naz'jar Invader - 29266 - Permanent Feign Death
(@CGUID+3, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+4, 0, 0, 0, 1, 0, '29266'), -- Naz'jar Spiritmender - 29266 - Permanent Feign Death
(@CGUID+5, 0, 0, 0, 1, 0, '29266'), -- Naz'jar Invader - 29266 - Permanent Feign Death
(@CGUID+6, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+7, 0, 0, 0, 1, 0, '29266'), -- Naz'jar Invader - 29266 - Permanent Feign Death
(@CGUID+8, 0, 0, 0, 1, 0, '99201'), -- Summon Enabler Stalker - 99201 - Summon Enabler
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+10, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+11, 0, 0, 50331648, 1, 0, '85211'), -- Elemental Guard - 85211 - Water Bolt
(@CGUID+12, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+13, 0, 0, 50331648, 1, 0, '95293'), -- Throne of Tides Teleporter - 95293 - Teleporter Base Visual
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+15, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+16, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+18, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+19, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+20, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+21, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+22, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+23, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+24, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+25, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+26, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+27, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+28, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+29, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+30, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+32, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+33, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+34, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+35, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+36, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+37, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+38, 0, 0, 0, 1, 0, '76345'), -- World Trigger (Large AOI) - 76345 - Water Leak
(@CGUID+39, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+40, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+41, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+42, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+43, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+44, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+45, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+47, 0, 0, 0, 1, 0, '76345'), -- World Trigger (Large AOI) - 76345 - Water Leak
(@CGUID+48, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+49, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+50, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+52, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+53, 0, 0, 0, 1, 0, '76345'), -- World Trigger (Large AOI) - 76345 - Water Leak
(@CGUID+54, 0, 0, 50331648, 1, 0, ''), -- Ozumat Vehicle
(@CGUID+55, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+56, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+58, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+59, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+60, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+61, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+62, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+63, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+64, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+65, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+66, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+67, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+68, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+69, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+70, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+71, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+72, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+74, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+75, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+76, 0, 0, 0, 1, 0, '85170'), -- World Trigger (Infinite AOI) - 85170 - Shock Defense
(@CGUID+77, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+78, 0, 0, 0, 1, 0, '91347'), -- Geyser - 91347 - Geyser
(@CGUID+79, 0, 0, 0, 1, 0, '91347'), -- Geyser - 91347 - Geyser
(@CGUID+80, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
-- (@CGUID+81, 0, 0, 50331648, 1, 0, ''), -- Ozumat
(@CGUID+82, 0, 0, 0, 1, 0, '91347'), -- Geyser - 91347 - Geyser
(@CGUID+83, 0, 0, 0, 1, 0, ''), -- World Trigger (Infinite AOI)
(@CGUID+84, 0, 0, 0, 1, 0, '91347'), -- Geyser - 91347 - Geyser
(@CGUID+85, 0, 0, 50331648, 1, 0, ''), -- Ozumat Vehicle, Big
(@CGUID+86, 0, 0, 0, 1, 0, '91347'), -- Geyser - 91347 - Geyser
(@CGUID+87, 0, 0, 0, 1, 0, ''), -- Captain Taylor
(@CGUID+88, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+89, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+90, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+91, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+92, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+93, 0, 0, 0, 1, 0, ''), -- World Trigger (Not Immune PC)
(@CGUID+94, 0, 0, 0, 1, 0, ''), -- Naz'jar Sentinel
(@CGUID+95, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+96, 0, 0, 0, 1, 0, ''), -- World Trigger (Not Immune PC)
(@CGUID+97, 0, 0, 0, 1, 0, ''), -- World Trigger
-- (@CGUID+98, 0, 0, 0, 1, 0, '76339'), -- Mindbender Ghur'sha - 76339 - Unrelenting Agony
(@CGUID+99, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Invader - 74048 - Water Window Jump Through Visual
(@CGUID+100, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Invader - 74048 - Water Window Jump Through Visual
(@CGUID+101, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Spiritmender - 74048 - Water Window Jump Through Visual
(@CGUID+102, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Spiritmender - 74048 - Water Window Jump Through Visual
(@CGUID+103, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+104, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+105, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+106, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+107, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+108, 0, 0, 50331648, 1, 0, '85211'), -- Elemental Guard - 85211 - Water Bolt
(@CGUID+109, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+110, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+111, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+112, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+113, 0, 0, 0, 1, 0, ''), -- Ozumat Add Spawner
(@CGUID+114, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+115, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+116, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+117, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+118, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+119, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+120, 0, 0, 0, 1, 0, ''), -- Ozumat Add Spawner
(@CGUID+121, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+122, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+123, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+124, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+125, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+126, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+127, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+128, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+129, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+130, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+131, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+132, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+133, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+134, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+135, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+136, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+137, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+138, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+139, 0, 0, 0, 1, 0, ''), -- Lady Naz'jar
(@CGUID+140, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+141, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+142, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+143, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+144, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+145, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+146, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+147, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+148, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+149, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+150, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+151, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+152, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+153, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+154, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+155, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+156, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+157, 0, 0, 0, 1, 0, ''), -- Deep Murloc Hunter
(@CGUID+158, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+159, 0, 0, 50331648, 1, 0, '95296'), -- Throne of Tides Teleporter - 95296 - Teleporter Active Visual
(@CGUID+160, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+161, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+162, 0, 0, 0, 1, 0, ''), -- Naz'jar Invader
(@CGUID+163, 0, 0, 0, 1, 0, ''), -- Naz'jar Invader
(@CGUID+164, 0, 0, 0, 1, 0, ''), -- Naz'jar Spiritmender
(@CGUID+165, 0, 0, 0, 1, 0, ''), -- Naz'jar Tempest Witch
(@CGUID+166, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+167, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+168, 0, 0, 0, 1, 0, ''), -- Naz'jar Invader
(@CGUID+169, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+170, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+171, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+172, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+173, 0, 0, 0, 1, 0, ''), -- Naz'jar Sentinel
(@CGUID+174, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+175, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Invader - 74048 - Water Window Jump Through Visual
(@CGUID+176, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Invader - 74048 - Water Window Jump Through Visual
(@CGUID+177, 0, 0, 0, 1, 0, '74048'), -- Naz'jar Spiritmender - 74048 - Water Window Jump Through Visual
(@CGUID+178, 0, 0, 50331648, 1, 0, '74048'), -- Naz'jar Invader - 74048 - Water Window Jump Through Visual
(@CGUID+179, 0, 0, 0, 1, 0, '74048'), -- Naz'jar Spiritmender - 74048 - Water Window Jump Through Visual
(@CGUID+180, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+181, 0, 0, 0, 1, 0, '90495'), -- Lady Naz'jar - 90495 - Waterspout
(@CGUID+182, 0, 0, 0, 1, 0, '74048'), -- Naz'jar Spiritmender - 74048 - Water Window Jump Through Visual
(@CGUID+183, 0, 0, 0, 1, 0, ''), -- Naz'jar Invader
(@CGUID+184, 0, 0, 0, 1, 0, ''), -- Naz'jar Invader
(@CGUID+185, 0, 0, 0, 1, 0, ''), -- Naz'jar Spiritmender
(@CGUID+186, 0, 0, 0, 1, 0, ''), -- Naz'jar Tempest Witch
(@CGUID+187, 0, 0, 0, 1, 0, ''), -- Naz'jar Spiritmender
(@CGUID+188, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+189, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+190, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+191, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+192, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+193, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+194, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+195, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+196, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+197, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+198, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+199, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+200, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+201, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+202, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+203, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+204, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+205, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+206, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+207, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+208, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+209, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+210, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+211, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+212, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+213, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+214, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+215, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+216, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+217, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+218, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+219, 0, 0, 0, 1, 0, ''), -- Deep Murloc Drudge
(@CGUID+220, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+221, 0, 0, 0, 1, 0, ''), -- World Trigger
(@CGUID+222, 0, 0, 0, 1, 0, '75808'), -- Naz'jar Tempest Witch - 75808 - Water Window Break Visual
(@CGUID+223, 0, 0, 0, 1, 0, '75808'), -- Naz'jar Tempest Witch - 75808 - Water Window Break Visual
(@CGUID+224, 0, 0, 50331648, 1, 0, '75808'), -- Naz'jar Honor Guard - 75808 - Water Window Break Visual
(@CGUID+225, 0, 0, 50331648, 1, 0, '75808'), -- Naz'jar Honor Guard - 75808 - Water Window Break Visual
(@CGUID+226, 0, 0, 0, 1, 0, '75808'), -- Naz'jar Tempest Witch - 75808 - Water Window Break Visual
(@CGUID+227, 0, 0, 0, 1, 0, '75808'), -- Naz'jar Tempest Witch - 75808 - Water Window Break Visual
(@CGUID+228, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+229, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+230, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+231, 0, 0, 0, 1, 0, '76604'), -- Faceless Watcher - 76604 - Void Rip
(@CGUID+232, 0, 0, 0, 1, 0, '76952'), -- Neptulon - 76952 - Purify
(@CGUID+233, 0, 0, 0, 1, 0, ''), -- Gilgoblin Aquamage
(@CGUID+234, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+235, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+236, 0, 0, 0, 1, 0, ''), -- Gilgoblin Aquamage
(@CGUID+237, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+238, 0, 0, 0, 1, 0, ''), -- Faceless Watcher
(@CGUID+239, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+240, 0, 0, 0, 0, 0, '76410'), -- Gilgoblin Aquamage - 76410 - Water Jet
(@CGUID+241, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+242, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+243, 0, 0, 0, 1, 0, ''), -- Gilgoblin Aquamage
(@CGUID+244, 0, 0, 0, 0, 0, '76410'), -- Gilgoblin Aquamage - 76410 - Water Jet
(@CGUID+245, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+246, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+247, 0, 0, 0, 1, 0, ''), -- Gilgoblin Aquamage
(@CGUID+248, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+249, 0, 0, 0, 0, 0, '76410'), -- Gilgoblin Aquamage - 76410 - Water Jet
(@CGUID+250, 0, 0, 0, 1, 0, ''), -- Faceless Watcher
(@CGUID+251, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+252, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+253, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+254, 0, 0, 0, 1, 0, ''), -- Faceless Watcher
(@CGUID+255, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+256, 0, 0, 0, 0, 0, '76410'), -- Gilgoblin Aquamage - 76410 - Water Jet
(@CGUID+257, 0, 0, 0, 1, 0, ''), -- Gilgoblin Hunter
(@CGUID+258, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+259, 0, 0, 0, 1, 0, '76406'), -- Gilgoblin Aquamage - 76406 - Water Jet
(@CGUID+260, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+261, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+262, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+263, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+264, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+265, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+266, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+267, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+268, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+269, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+270, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+271, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+272, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+273, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+274, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+275, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+276, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+277, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+278, 0, 0, 0, 1, 0, '82953'), -- World Trigger - 82953 - Ozumat Ink
(@CGUID+279, 0, 0, 0, 1, 0, '76625'), -- Tainted Sentry - 76625 - Summon Unstable Corruptions
(@CGUID+280, 0, 0, 0, 1, 0, '82953'), -- World Trigger - 82953 - Ozumat Ink
(@CGUID+281, 0, 0, 0, 1, 0, '76625'), -- Tainted Sentry - 76625 - Summon Unstable Corruptions
(@CGUID+282, 0, 0, 0, 1, 0, '82953'), -- World Trigger - 82953 - Ozumat Ink
(@CGUID+283, 0, 0, 0, 1, 0, '76625'), -- Tainted Sentry - 76625 - Summon Unstable Corruptions
(@CGUID+284, 0, 0, 0, 1, 0, '76625'), -- Tainted Sentry - 76625 - Summon Unstable Corruptions
(@CGUID+285, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+286, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+287, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+288, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+289, 0, 0, 0, 1, 0, '76017'), -- Commander Ulthok - 76017 - Ulthok Intro Visual State
(@CGUID+290, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+291, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+292, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+293, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+294, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+295, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+296, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+297, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+298, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+299, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+300, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+301, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+302, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+303, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+304, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+305, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+306, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+307, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+308, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+309, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+310, 0, 0, 50331648, 1, 0, '85211'), -- Elemental Guard - 85211 - Water Bolt
(@CGUID+311, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+312, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+313, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+314, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+315, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+316, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+317, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+318, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+319, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+320, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
-- (@CGUID+321, 0, 0, 50331648, 1, 0, ''), -- Sindragosa's Fury
(@CGUID+322, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+323, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+324, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+325, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+326, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+327, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+328, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+329, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+330, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+331, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+332, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+333, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+334, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+335, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+336, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+337, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+338, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+339, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+340, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+341, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+342, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+343, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+344, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+345, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+346, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+347, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+348, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+349, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+350, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+351, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+352, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+353, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+355, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+356, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+357, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+358, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+359, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+360, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+361, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+362, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+363, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+364, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+365, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+366, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+367, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+368, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+369, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+370, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+371, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+372, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+373, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+374, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+375, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+376, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+377, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+378, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+379, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+380, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+381, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+382, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+383, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+384, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+385, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+386, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+387, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+388, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+389, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+390, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+391, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+392, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+393, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+394, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+395, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+396, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+397, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+398, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+399, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+400, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+401, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+402, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+403, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+404, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+405, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+406, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+407, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+408, 0, 0, 50331648, 1, 0, '85211'), -- Elemental Guard - 85211 - Water Bolt
(@CGUID+409, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+410, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+411, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+412, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+413, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+414, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+415, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+416, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+417, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+418, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+419, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+420, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+421, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+422, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+423, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+424, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+425, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+426, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+427, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+428, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+429, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+430, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+431, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+432, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+433, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+434, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+435, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+436, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+437, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+438, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+439, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+440, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+441, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+442, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+443, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+444, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+445, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+446, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+447, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+448, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+449, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+450, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+451, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+452, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+453, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+454, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+455, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+456, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+457, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+458, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+459, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+460, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+461, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+462, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+463, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+464, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+465, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+466, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+467, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+468, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+469, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+470, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+471, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+472, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+473, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+474, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+475, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+476, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+477, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+478, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+479, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+480, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+481, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+482, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+483, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+484, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+485, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+486, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+487, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+488, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+489, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+490, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+491, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+492, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+493, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+494, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+495, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+496, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+497, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+498, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+499, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+500, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+501, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+502, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+503, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+504, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+505, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+506, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+507, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+508, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+509, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+510, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+511, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+512, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+513, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+514, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+515, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+516, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+517, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+518, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+519, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+520, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+521, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+522, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+523, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+524, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+525, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+526, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+527, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+528, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+529, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+530, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+531, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+532, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+533, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+534, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+535, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+536, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+537, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+538, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+539, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+540, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+541, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+542, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+543, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+544, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+545, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+546, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+547, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+548, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+549, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+550, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+551, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+552, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+553, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+554, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+555, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+556, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+557, 0, 0, 0, 1, 0, ''), -- Unstable Corruption
(@CGUID+558, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+559, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+560, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+561, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+562, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+563, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+564, 0, 0, 0, 1, 0, '76362'), -- Unstable Corruption - 76362 - Unstable Corruption Growth
(@CGUID+565, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+566, 0, 0, 50331648, 1, 0, ''), -- Elemental Guard
(@CGUID+567, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+568, 0, 0, 0, 1, 0, ''), -- Ozumat Combat Trigger
-- (@CGUID+569, 0, 0, 50331648, 1, 0, '83976'), -- Unyielding Behemoth (Hand Visual) - 46598 - Ride Vehicle Hardcoded, 83976 - Shrink
(@CGUID+570, 0, 0, 50331648, 1, 0, '83126'), -- Ozumat - 83126 - Ozumat Globe Impact Periodic
(@CGUID+571, 0, 0, 0, 1, 0, ''), -- Ozumat Add Spawner
(@CGUID+572, 0, 0, 0, 1, 0, ''), -- Faceless Sapper
(@CGUID+573, 0, 0, 0, 1, 0, ''), -- Faceless Sapper
(@CGUID+574, 0, 0, 0, 1, 0, ''), -- Faceless Sapper
(@CGUID+575, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+576, 0, 0, 50331648, 1, 0, ''), -- Naz'jar Soldier
(@CGUID+577, 0, 0, 50331648, 1, 0, ''); -- Naz'jar Soldier

SET @OGUID:=235567;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+776;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 204963, 643, 5004, 5004, 3, 169, 0, -647.283, 806.7465, 249.3488, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Instance Portal (Party + Heroic) (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+1, 207998, 643, 5004, 5004, 3, 169, 0, -319.7966, 857.6629, 271.2394, 1.570796, 0, 0, 0.7071066, 0.7071069, 7200, 255, 1, 26365), -- Doodad_WG_Invisible_Door02 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+2, 208301, 643, 5004, 5004, 3, 169, 0, -311.465, 932.8975, 247.9267, 4.71239, 0, 0, -0.7071066, 0.7071069, 7200, 255, 1, 26365), -- Doodad_Abyssal_Leviathan_Tentacle_fromBelow01 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+3, 208302, 643, 5004, 5004, 3, 169, 0, -309.7529, 685.5665, 286.1978, 1.570796, 0, 0, 0.7071066, 0.7071069, 7200, 255, 1, 26365), -- Doodad_Abyssal_Leviathan_Tentacle01 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+4, 207997, 643, 5004, 5004, 3, 169, 0, -315.5558, 758.4044, 275.6646, 4.71239, 0, 0, -0.7071066, 0.7071069, 7200, 255, 1, 26365), -- Doodad_WG_Invisible_Door01 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+5, 204341, 643, 5004, 5004, 3, 169, 0, -211.6087, 981.8606, 229.7631, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_Abyssal_Maw_Door_04 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+6, 204340, 643, 5004, 5004, 3, 169, 0, -211.5925, 637.4172, 286.1444, 3.141593, 0, 0, -1, 0, 7200, 255, 0, 26365), -- Doodad_Abyssal_Maw_Door_03 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+7, 207209, 643, 5004, 5004, 3, 169, 0, -215.2937, 806.2046, 253.7109, 3.141593, 0, 0, -1, 0, 7200, 255, 24, 26365), -- 0 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+8, 204339, 643, 5004, 5004, 3, 169, 0, 108.324, 802.3706, 807.5527, 3.141593, 0, 0, -1, 0, 7200, 255, 0, 26365), -- Doodad_Abyssal_Maw_Door_02 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+9, 204338, 643, 5004, 5004, 3, 169, 0, -9.41391, 802.3706, 807.5527, 3.141593, 0, 0, -1, 0, 7200, 255, 1, 26365), -- Doodad_Abyssal_Maw_Door_01 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+10, 207406, 643, 5004, 5004, 3, 169, 0, -297.9132, 795.2726, 261.6193, 2.44346, 0, 0, 0.9396925, 0.3420205, 7200, 255, 1, 26365), -- Strange Fountain (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+11, 202742, 643, 5004, 5004, 3, 169, 0, -603.6129, 827.2743, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+12, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+13, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+14, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+15, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+16, 202742, 643, 5004, 5004, 3, 169, 0, -617.3641, 836.2683, 248.1258, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+17, 202742, 643, 5004, 5004, 3, 169, 0, -284.7762, 807.5505, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+18, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+19, 202742, 643, 5004, 5004, 3, 169, 0, -591.2202, 799.9266, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+20, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+21, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+22, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+23, 202742, 643, 5004, 5004, 3, 169, 0, -361.9618, 808.1545, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+24, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+25, 202742, 643, 5004, 5004, 3, 169, 0, -358.9077, 815.5439, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+26, 202742, 643, 5004, 5004, 3, 169, 0, -496.4043, 799.0345, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+27, 202742, 643, 5004, 5004, 3, 169, 0, -444.9424, 808.0842, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+28, 202742, 643, 5004, 5004, 3, 169, 0, -240.7071, 817.6274, 260.4027, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+29, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+30, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+31, 202742, 643, 5004, 5004, 3, 169, 0, -524.0555, 805.6702, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+32, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+33, 202742, 643, 5004, 5004, 3, 169, 0, -544.8745, 815.712, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+34, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+35, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+36, 202742, 643, 5004, 5004, 3, 169, 0, -235.1476, 800.8314, 261.5132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+37, 202742, 643, 5004, 5004, 3, 169, 0, -299.1781, 793.9689, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+38, 202742, 643, 5004, 5004, 3, 169, 0, -493.1612, 811.2871, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+39, 202742, 643, 5004, 5004, 3, 169, 0, -603.3486, 795.0095, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+40, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+41, 202742, 643, 5004, 5004, 3, 169, 0, -598.3884, 848.5992, 248.4784, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+42, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+43, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+44, 202742, 643, 5004, 5004, 3, 169, 0, -307.4474, 795.1099, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+45, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+46, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+47, 202742, 643, 5004, 5004, 3, 169, 0, -459.9038, 818.2845, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+48, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+49, 202742, 643, 5004, 5004, 3, 169, 0, -594.227, 818.4092, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+50, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+51, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+52, 202742, 643, 5004, 5004, 3, 169, 0, -369.568, 818.5821, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+53, 202742, 643, 5004, 5004, 3, 169, 0, -361.9618, 808.1545, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+54, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+55, 202742, 643, 5004, 5004, 3, 169, 0, -466.2964, 818.5667, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+56, 202742, 643, 5004, 5004, 3, 169, 0, -603.8947, 798.4953, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+57, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+58, 202742, 643, 5004, 5004, 3, 169, 0, -358.3351, 817.1099, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+59, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+60, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+61, 202742, 643, 5004, 5004, 3, 169, 0, -290.175, 814.1153, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+62, 202742, 643, 5004, 5004, 3, 169, 0, -556.7227, 821.95, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+63, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+64, 202742, 643, 5004, 5004, 3, 169, 0, -448.101, 799.924, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+65, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+66, 202742, 643, 5004, 5004, 3, 169, 0, -229.6048, 790.1569, 261.3102, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+67, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+68, 202742, 643, 5004, 5004, 3, 169, 0, -368.801, 818.1627, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+69, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+70, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+71, 202742, 643, 5004, 5004, 3, 169, 0, -572.4982, 788.6063, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+72, 202742, 643, 5004, 5004, 3, 169, 0, -290.5056, 806.1481, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+73, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+74, 202742, 643, 5004, 5004, 3, 169, 0, -585.6165, 824.773, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+75, 202742, 643, 5004, 5004, 3, 169, 0, -488.4996, 791.0689, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+76, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+77, 202742, 643, 5004, 5004, 3, 169, 0, -524.0555, 805.6702, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+78, 202742, 643, 5004, 5004, 3, 169, 0, -587.3433, 821.478, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+79, 202742, 643, 5004, 5004, 3, 169, 0, -425.3569, 800.3156, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+80, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+81, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+82, 202742, 643, 5004, 5004, 3, 169, 0, -391.1242, 796.3162, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+83, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+84, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+85, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+86, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+87, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+88, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+89, 202742, 643, 5004, 5004, 3, 169, 0, -226.2889, 808.7465, 262.4425, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+90, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+91, 202742, 643, 5004, 5004, 3, 169, 0, -335.619, 805.8668, 260.7825, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+92, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+93, 202742, 643, 5004, 5004, 3, 169, 0, -607.69, 836.9983, 246.2324, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+94, 202742, 643, 5004, 5004, 3, 169, 0, -299.9826, 801.5759, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+95, 202742, 643, 5004, 5004, 3, 169, 0, -621.425, 835.7364, 250.5735, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+96, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+97, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+98, 202742, 643, 5004, 5004, 3, 169, 0, -298.357, 853.6345, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+99, 202742, 643, 5004, 5004, 3, 169, 0, -457.8351, 802.7327, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+100, 202742, 643, 5004, 5004, 3, 169, 0, -605.7587, 822.4447, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+101, 202742, 643, 5004, 5004, 3, 169, 0, -311.526, 782.5868, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+102, 202742, 643, 5004, 5004, 3, 169, 0, -362.8908, 795.5602, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+103, 202742, 643, 5004, 5004, 3, 169, 0, -595.3865, 825.0136, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+104, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+105, 202742, 643, 5004, 5004, 3, 169, 0, -304.5349, 791.9608, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+106, 202742, 643, 5004, 5004, 3, 169, 0, -518.662, 809.2816, 257.7878, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+107, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+108, 202742, 643, 5004, 5004, 3, 169, 0, -588.5107, 794.9981, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+109, 202742, 643, 5004, 5004, 3, 169, 0, -342.7049, 809.5555, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+110, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+111, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+112, 202742, 643, 5004, 5004, 3, 169, 0, -225.7423, 822.6299, 261.5414, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+113, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+114, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+115, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+116, 202742, 643, 5004, 5004, 3, 169, 0, -462.7195, 816.3304, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+117, 202742, 643, 5004, 5004, 3, 169, 0, -576.1688, 820.5981, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+118, 202742, 643, 5004, 5004, 3, 169, 0, -386.6591, 810.1473, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+119, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+120, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+121, 202742, 643, 5004, 5004, 3, 169, 0, -472.6013, 814.3001, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+122, 202742, 643, 5004, 5004, 3, 169, 0, -236.5861, 804.4183, 261.4096, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+123, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+124, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+125, 202742, 643, 5004, 5004, 3, 169, 0, -616.9158, 788.9645, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+126, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+127, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+128, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+129, 202742, 643, 5004, 5004, 3, 169, 0, -427.9673, 799.2715, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+130, 202742, 643, 5004, 5004, 3, 169, 0, -142.5002, 807.4653, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+131, 202742, 643, 5004, 5004, 3, 169, 0, -359.4024, 816.0008, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+132, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+133, 202742, 643, 5004, 5004, 3, 169, 0, -545.8215, 803.1368, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+134, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+135, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+136, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+137, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+138, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+139, 202742, 643, 5004, 5004, 3, 169, 0, -304.8722, 803.3438, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+140, 202742, 643, 5004, 5004, 3, 169, 0, -595.9771, 834.451, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+141, 202742, 643, 5004, 5004, 3, 169, 0, -287.5294, 800.5106, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+142, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+143, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+144, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+145, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+146, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+147, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+148, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+149, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+150, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+151, 202742, 643, 5004, 5004, 3, 169, 0, -481.6059, 796.6169, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+152, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+153, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+154, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+155, 202742, 643, 5004, 5004, 3, 169, 0, -611.7615, 789.2568, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+156, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+157, 202742, 643, 5004, 5004, 3, 169, 0, -599.2275, 802.1318, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+158, 202742, 643, 5004, 5004, 3, 169, 0, -594.126, 850.4564, 248.2198, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+159, 202742, 643, 5004, 5004, 3, 169, 0, -557.9584, 809.366, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+160, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+161, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+162, 202742, 643, 5004, 5004, 3, 169, 0, -361.9618, 808.1545, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+163, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+164, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+165, 202742, 643, 5004, 5004, 3, 169, 0, -457.8351, 802.7327, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+166, 202742, 643, 5004, 5004, 3, 169, 0, -358.4568, 817.6851, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+167, 202742, 643, 5004, 5004, 3, 169, 0, -240.8974, 805.6653, 260.8077, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+168, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+169, 202742, 643, 5004, 5004, 3, 169, 0, -299.1329, 817.9169, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+170, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+171, 202742, 643, 5004, 5004, 3, 169, 0, -586.0226, 808.3559, 245.4128, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+172, 202742, 643, 5004, 5004, 3, 169, 0, -587.9221, 811.8238, 245.388, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+173, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+174, 202742, 643, 5004, 5004, 3, 169, 0, -560.1353, 808.0738, 256.9915, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+175, 202742, 643, 5004, 5004, 3, 169, 0, -310.2377, 796.3908, 261.6247, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+176, 202742, 643, 5004, 5004, 3, 169, 0, -588.1623, 789.9441, 245.4122, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+177, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+178, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+179, 202742, 643, 5004, 5004, 3, 169, 0, -433.7593, 809.1063, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+180, 202742, 643, 5004, 5004, 3, 169, 0, -244.1751, 805.7748, 260.2285, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+181, 202742, 643, 5004, 5004, 3, 169, 0, -382.1367, 808.9256, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+182, 202742, 643, 5004, 5004, 3, 169, 0, -371.249, 818.6626, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+183, 202742, 643, 5004, 5004, 3, 169, 0, -581.4739, 784.1632, 245.3917, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+184, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+185, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+186, 202742, 643, 5004, 5004, 3, 169, 0, -609.2257, 790.7344, 245.3671, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+187, 202742, 643, 5004, 5004, 3, 169, 0, -548.1771, 807.5104, 246.4562, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+188, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+189, 202742, 643, 5004, 5004, 3, 169, 0, -479.9549, 803.1893, 253.4132, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+190, 202742, 643, 5004, 5004, 3, 169, 0, -468.1788, 815.2173, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+191, 202742, 643, 5004, 5004, 3, 169, 0, -617.4396, 819.5039, 246.8475, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+192, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+193, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+194, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+195, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+196, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+197, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+198, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+199, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+200, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+201, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+202, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+203, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+204, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+205, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+206, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+207, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+208, 205542, 643, 5004, 5004, 3, 169, 0, 54.11389, 802.0451, 805.761, 3.188875, 0, 0, -0.9997206, 0.02363881, 7200, 255, 1, 26365), -- Doodad_Abyssal_Coral_Chunk_Ceiling01_Break01 (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+209, 202742, 643, 5004, 5004, 3, 169, 0, 23.34144, 822.1941, 807.1287, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+210, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+211, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+212, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+213, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+214, 202742, 643, 5004, 5004, 3, 169, 0, 67.83644, 808.8594, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+215, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+216, 202742, 643, 5004, 5004, 3, 169, 0, 152.8295, 807.125, 808.9501, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+217, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+218, 202742, 643, 5004, 5004, 3, 169, 0, 41.15274, 820.7129, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+219, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+220, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+221, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+222, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+223, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+224, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+225, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+226, 202742, 643, 5004, 5004, 3, 169, 0, 122.2837, 821.2411, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+227, 202742, 643, 5004, 5004, 3, 169, 0, 66.71084, 799.9061, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+228, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+229, 202742, 643, 5004, 5004, 3, 169, 0, 42.32461, 810.2007, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+230, 202742, 643, 5004, 5004, 3, 169, 0, 55.99442, 852.5627, 806.6016, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+231, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+232, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+233, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+234, 202742, 643, 5004, 5004, 3, 169, 0, 139.0025, 808.6485, 808.9529, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+235, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+236, 202742, 643, 5004, 5004, 3, 169, 0, 34.18035, 802.2026, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+237, 202742, 643, 5004, 5004, 3, 169, 0, 185.5, 823.4261, 808.7596, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+238, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+239, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+240, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+241, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+242, 202742, 643, 5004, 5004, 3, 169, 0, 54.4508, 786.307, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+243, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+244, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+245, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+246, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+247, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+248, 202742, 643, 5004, 5004, 3, 169, 0, 46.77086, 807.3769, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+249, 202742, 643, 5004, 5004, 3, 169, 0, 3.151752, 806.9824, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+250, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+251, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+252, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+253, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+254, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+255, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+256, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+257, 202742, 643, 5004, 5004, 3, 169, 0, -361.9618, 808.1545, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+258, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+259, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+260, 202742, 643, 5004, 5004, 3, 169, 0, -293.2812, 815.7661, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+261, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+262, 202742, 643, 5004, 5004, 3, 169, 0, -317.3369, 828.0981, 261.2295, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+263, 202742, 643, 5004, 5004, 3, 169, 0, 228.5578, 802.1016, 808.8599, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+264, 202742, 643, 5004, 5004, 3, 169, 0, -370.3526, 820.8972, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+265, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+266, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+267, 202742, 643, 5004, 5004, 3, 169, 0, -230.1498, 814.9638, 261.888, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+268, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+269, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+270, 202742, 643, 5004, 5004, 3, 169, 0, -289.2099, 804.3326, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+271, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+272, 202742, 643, 5004, 5004, 3, 169, 0, -225.7609, 791.6033, 261.6887, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+273, 202742, 643, 5004, 5004, 3, 169, 0, 229.2187, 751.057, 808.4615, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+274, 202742, 643, 5004, 5004, 3, 169, 0, -305.6156, 802.5328, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+275, 202742, 643, 5004, 5004, 3, 169, 0, -332.5158, 814.4702, 260.7189, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+276, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+277, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+278, 202742, 643, 5004, 5004, 3, 169, 0, -361.9618, 808.1545, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+279, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+280, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+281, 202742, 643, 5004, 5004, 3, 169, 0, -431.4555, 796.5049, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+282, 202742, 643, 5004, 5004, 3, 169, 0, -468.8807, 818.1053, 257.168, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+283, 202742, 643, 5004, 5004, 3, 169, 0, 27.38033, 819.5683, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+284, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+285, 202742, 643, 5004, 5004, 3, 169, 0, 25.24629, 805.5485, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+286, 202742, 643, 5004, 5004, 3, 169, 0, 33.70946, 772.0159, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+287, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+288, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+289, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+290, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+291, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+292, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+293, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+294, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+295, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+296, 202742, 643, 5004, 5004, 3, 169, 0, 163.3956, 826.3505, 808.8995, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+297, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+298, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+299, 202742, 643, 5004, 5004, 3, 169, 0, 49.03465, 764.1146, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+300, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+301, 202742, 643, 5004, 5004, 3, 169, 0, 40.07397, 810.2864, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+302, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+303, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+304, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+305, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+306, 202742, 643, 5004, 5004, 3, 169, 0, 49.85577, 783.4945, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+307, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+308, 202742, 643, 5004, 5004, 3, 169, 0, 117.859, 806.287, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+309, 202742, 643, 5004, 5004, 3, 169, 0, 71.9766, 790.4659, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+310, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+311, 202742, 643, 5004, 5004, 3, 169, 0, 56.07465, 822.0661, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+312, 202742, 643, 5004, 5004, 3, 169, 0, 187.6993, 818.705, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+313, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+314, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+315, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+316, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+317, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+318, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+319, 202742, 643, 5004, 5004, 3, 169, 0, 36.25398, 805.0674, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+320, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+321, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+322, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+323, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+324, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+325, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+326, 202742, 643, 5004, 5004, 3, 169, 0, -300.9183, 806.5731, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+327, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+328, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+329, 202742, 643, 5004, 5004, 3, 169, 0, -256.5955, 808.0364, 259.165, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+330, 202742, 643, 5004, 5004, 3, 169, 0, -256.5955, 808.0364, 259.165, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+331, 202742, 643, 5004, 5004, 3, 169, 0, -299.0084, 846.2816, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+332, 202742, 643, 5004, 5004, 3, 169, 0, -310.0642, 832.566, 259.9967, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+333, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+334, 202742, 643, 5004, 5004, 3, 169, 0, -309.8387, 789.3887, 261.0339, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+335, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+336, 202742, 643, 5004, 5004, 3, 169, 0, 236.8778, 835.5942, 808.5815, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+337, 202742, 643, 5004, 5004, 3, 169, 0, -317.2448, 809.434, 261.2558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+338, 202742, 643, 5004, 5004, 3, 169, 0, 219.9689, 785.3399, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+339, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+340, 202742, 643, 5004, 5004, 3, 169, 0, 219.8616, 745.4353, 808.9315, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+341, 202742, 643, 5004, 5004, 3, 169, 0, -373.566, 817.3975, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+342, 202742, 643, 5004, 5004, 3, 169, 0, -272.7153, 807.8299, 258.9762, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+343, 202742, 643, 5004, 5004, 3, 169, 0, -342.7049, 809.5555, 259.3411, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+344, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+345, 202742, 643, 5004, 5004, 3, 169, 0, -385.505, 803.7447, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+346, 202742, 643, 5004, 5004, 3, 169, 0, -295.1181, 808.9722, 260.9349, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+347, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+348, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+349, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+350, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+351, 202742, 643, 5004, 5004, 3, 169, 0, -423.7201, 799.1238, 249.7082, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+352, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+353, 202742, 643, 5004, 5004, 3, 169, 0, -387.2965, 814.9402, 257.7555, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+354, 202742, 643, 5004, 5004, 3, 169, 0, -432.3368, 802.3281, 248.7223, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+355, 202742, 643, 5004, 5004, 3, 169, 0, -399.1267, 806.4028, 248.1572, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+356, 203199, 643, 5004, 5004, 3, 169, 0, 118.4531, 798.9879, 809.069, 2.809975, 0, 0, 0.9862852, 0.1650499, 7200, 255, 0, 26365), -- Throne of Tides Defense System (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+357, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+358, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+359, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+360, 202742, 643, 5004, 5004, 3, 169, 0, 138.1355, 836.0701, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+361, 202742, 643, 5004, 5004, 3, 169, 0, 50.11511, 799.2448, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+362, 202742, 643, 5004, 5004, 3, 169, 0, 25.7226, 783.4463, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+363, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+364, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+365, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+366, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+367, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+368, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+369, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+370, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+371, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+372, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+373, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+374, 202742, 643, 5004, 5004, 3, 169, 0, 235.4976, 851.8138, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+375, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+376, 202742, 643, 5004, 5004, 3, 169, 0, 24.27828, 790.6388, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+377, 202742, 643, 5004, 5004, 3, 169, 0, 173.4377, 797.7512, 808.8982, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+378, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+379, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+380, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+381, 202742, 643, 5004, 5004, 3, 169, 0, 44.30289, 795.4138, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+382, 202742, 643, 5004, 5004, 3, 169, 0, -183.9505, 793.7863, 798.3094, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+383, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+384, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+385, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+386, 202742, 643, 5004, 5004, 3, 169, 0, 81.32465, 790.5443, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+387, 202742, 643, 5004, 5004, 3, 169, 0, 66.25199, 808.4076, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+388, 202742, 643, 5004, 5004, 3, 169, 0, 19.75219, 794.9404, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+389, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+390, 202742, 643, 5004, 5004, 3, 169, 0, 37.84798, 809.5364, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+391, 202742, 643, 5004, 5004, 3, 169, 0, 204.5055, 822.8646, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+392, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+393, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+394, 202742, 643, 5004, 5004, 3, 169, 0, 184.8169, 818.9229, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+395, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+396, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+397, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+398, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+399, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+400, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+401, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+402, 202742, 643, 5004, 5004, 3, 169, 0, 164.3785, 810.9473, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+403, 202742, 643, 5004, 5004, 3, 169, 0, 121.7077, 823.9096, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+404, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+405, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+406, 202742, 643, 5004, 5004, 3, 169, 0, -161.0122, 800.5391, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+407, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+408, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+409, 202742, 643, 5004, 5004, 3, 169, 0, 60.86016, 826.0198, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+410, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+411, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+412, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+413, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+414, 202742, 643, 5004, 5004, 3, 169, 0, 30.94499, 775.5549, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+415, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+416, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+417, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+418, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+419, 202742, 643, 5004, 5004, 3, 169, 0, 18.81054, 811.6598, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+420, 202742, 643, 5004, 5004, 3, 169, 0, -161.798, 806.3669, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+421, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+422, 202742, 643, 5004, 5004, 3, 169, 0, 37.51942, 808.0055, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+423, 202742, 643, 5004, 5004, 3, 169, 0, 32.40952, 816.1072, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+424, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+425, 202742, 643, 5004, 5004, 3, 169, 0, 48.45687, 833.707, 806.847, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+426, 202742, 643, 5004, 5004, 3, 169, 0, 101.3276, 803.9319, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+427, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+428, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+429, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+430, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+431, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+432, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+433, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+434, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+435, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+436, 202742, 643, 5004, 5004, 3, 169, 0, 56.23428, 852.5358, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+437, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+438, 202742, 643, 5004, 5004, 3, 169, 0, 220.2995, 784.8843, 808.6176, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+439, 202742, 643, 5004, 5004, 3, 169, 0, 204.1316, 789.7789, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+440, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+441, 202742, 643, 5004, 5004, 3, 169, 0, -154.8054, 807.1638, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+442, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+443, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+444, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+445, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+446, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+447, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+448, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+449, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+450, 202742, 643, 5004, 5004, 3, 169, 0, 95.39789, 807.9736, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+451, 202742, 643, 5004, 5004, 3, 169, 0, 49.11228, 810.8226, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+452, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+453, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+454, 202742, 643, 5004, 5004, 3, 169, 0, 53.19302, 825.8992, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+455, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+456, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+457, 202742, 643, 5004, 5004, 3, 169, 0, 45.14339, 798.1777, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+458, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+459, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+460, 202742, 643, 5004, 5004, 3, 169, 0, 252.7033, 837.0171, 808.6521, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+461, 202742, 643, 5004, 5004, 3, 169, 0, -233.4787, 794.2557, 261.3294, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+462, 202742, 643, 5004, 5004, 3, 169, 0, -232.4247, 817.0153, 261.5318, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+463, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+464, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+465, 202742, 643, 5004, 5004, 3, 169, 0, 15.64157, 794.6729, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+466, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+467, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+468, 202742, 643, 5004, 5004, 3, 169, 0, 163.592, 810.28, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+469, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+470, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+471, 202742, 643, 5004, 5004, 3, 169, 0, 70.80521, 825.8344, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+472, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+473, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+474, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+475, 202742, 643, 5004, 5004, 3, 169, 0, 134.3909, 783.0038, 808.9399, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+476, 202742, 643, 5004, 5004, 3, 169, 0, 224.4486, 868.4969, 808.9075, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+477, 202742, 643, 5004, 5004, 3, 169, 0, 35.29088, 789.2382, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+478, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+479, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+480, 202742, 643, 5004, 5004, 3, 169, 0, 144.6964, 800.9507, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+481, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+482, 202742, 643, 5004, 5004, 3, 169, 0, -144.5155, 802.4929, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+483, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+484, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+485, 202742, 643, 5004, 5004, 3, 169, 0, 63.66795, 812.6854, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+486, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+487, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+488, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+489, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+490, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+491, 202742, 643, 5004, 5004, 3, 169, 0, 176.6737, 798.1036, 808.8982, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+492, 202742, 643, 5004, 5004, 3, 169, 0, 49.45714, 849.3591, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+493, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+494, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+495, 202742, 643, 5004, 5004, 3, 169, 0, 138.7346, 793.4713, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+496, 202742, 643, 5004, 5004, 3, 169, 0, 46.89986, 803.9729, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+497, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+498, 202742, 643, 5004, 5004, 3, 169, 0, 158.7424, 764.696, 808.8522, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+499, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+500, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+501, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+502, 202742, 643, 5004, 5004, 3, 169, 0, 255.0835, 832.9749, 808.9399, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+503, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+504, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+505, 202742, 643, 5004, 5004, 3, 169, 0, 49.91712, 828.2465, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+506, 202742, 643, 5004, 5004, 3, 169, 0, 31.41403, 818.7122, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+507, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+508, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+509, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+510, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+511, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+512, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+513, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+514, 202742, 643, 5004, 5004, 3, 169, 0, -190.7427, 808.0786, 797.972, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+515, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+516, 202742, 643, 5004, 5004, 3, 169, 0, 153.3218, 807.6686, 808.9524, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+517, 202742, 643, 5004, 5004, 3, 169, 0, 41.92853, 810.147, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+518, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+519, 202742, 643, 5004, 5004, 3, 169, 0, 128.2265, 836.8654, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+520, 202742, 643, 5004, 5004, 3, 169, 0, 56.19157, 795.5731, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+521, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+522, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+523, 202742, 643, 5004, 5004, 3, 169, 0, 42.91511, 758.9261, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+524, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+525, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+526, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+527, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+528, 202742, 643, 5004, 5004, 3, 169, 0, 200.0507, 774.572, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+529, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+530, 202742, 643, 5004, 5004, 3, 169, 0, 173.7833, 813.332, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+531, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+532, 202742, 643, 5004, 5004, 3, 169, 0, 57.879, 835.134, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+533, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+534, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+535, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+536, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+537, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+538, 202742, 643, 5004, 5004, 3, 169, 0, 223.379, 772.0664, 808.9438, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+539, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+540, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+541, 202742, 643, 5004, 5004, 3, 169, 0, 76.34039, 802.842, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+542, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+543, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+544, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+545, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+546, 202742, 643, 5004, 5004, 3, 169, 0, 219.2139, 781.1704, 808.7433, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+547, 202742, 643, 5004, 5004, 3, 169, 0, 43.30576, 817.2437, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+548, 202742, 643, 5004, 5004, 3, 169, 0, 122.7969, 782.9244, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+549, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+550, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+551, 202742, 643, 5004, 5004, 3, 169, 0, -141.0634, 803.2926, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+552, 202742, 643, 5004, 5004, 3, 169, 0, 27.23885, 815.9766, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+553, 202742, 643, 5004, 5004, 3, 169, 0, 154.2409, 750.1065, 808.4761, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+554, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+555, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+556, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+557, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+558, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+559, 202742, 643, 5004, 5004, 3, 169, 0, 43.41222, 811.1862, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+560, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+561, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+562, 202742, 643, 5004, 5004, 3, 169, 0, 175.644, 815.9926, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+563, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+564, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+565, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+566, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+567, 202742, 643, 5004, 5004, 3, 169, 0, 133.4906, 785.5891, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+568, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+569, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+570, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+571, 202742, 643, 5004, 5004, 3, 169, 0, 226.2346, 743.9595, 808.7316, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+572, 202742, 643, 5004, 5004, 3, 169, 0, -141.6026, 793.4182, 797.7479, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+573, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+574, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+575, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+576, 202742, 643, 5004, 5004, 3, 169, 0, 242.5083, 840.6996, 808.42, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+577, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+578, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+579, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+580, 202742, 643, 5004, 5004, 3, 169, 0, 45.76748, 797.5413, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+581, 202742, 643, 5004, 5004, 3, 169, 0, 32.84404, 783.896, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+582, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+583, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+584, 202742, 643, 5004, 5004, 3, 169, 0, 35.69193, 797.364, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+585, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+586, 202742, 643, 5004, 5004, 3, 169, 0, 23.14739, 782.2534, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+587, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+588, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+589, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+590, 202742, 643, 5004, 5004, 3, 169, 0, 76.97551, 816.9681, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+591, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+592, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+593, 202742, 643, 5004, 5004, 3, 169, 0, 38.81, 808.1566, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+594, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+595, 202742, 643, 5004, 5004, 3, 169, 0, 58.84452, 792.6604, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+596, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+597, 202742, 643, 5004, 5004, 3, 169, 0, 220.7575, 837.2082, 808.9401, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+598, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+599, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+600, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+601, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+602, 202742, 643, 5004, 5004, 3, 169, 0, 215.1334, 794.4091, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+603, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+604, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+605, 202742, 643, 5004, 5004, 3, 169, 0, 81.4409, 806.8326, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+606, 202742, 643, 5004, 5004, 3, 169, 0, 70.75249, 823.026, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+607, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+608, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+609, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+610, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+611, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+612, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+613, 202742, 643, 5004, 5004, 3, 169, 0, 165.2305, 745.3442, 808.8819, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+614, 202742, 643, 5004, 5004, 3, 169, 0, 188.4053, 781.3583, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+615, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+616, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+617, 202742, 643, 5004, 5004, 3, 169, 0, 9.439528, 795.3918, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+618, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+619, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+620, 202742, 643, 5004, 5004, 3, 169, 0, 44.11723, 793.6713, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+621, 202742, 643, 5004, 5004, 3, 169, 0, 75.23912, 814.7702, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+622, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+623, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+624, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+625, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+626, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+627, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+628, 202742, 643, 5004, 5004, 3, 169, 0, 195.0128, 806.8054, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+629, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+630, 202742, 643, 5004, 5004, 3, 169, 0, 58.63293, 785.918, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+631, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+632, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+633, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+634, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+635, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+636, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+637, 202742, 643, 5004, 5004, 3, 169, 0, 48.32239, 803.2721, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+638, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+639, 202742, 643, 5004, 5004, 3, 169, 0, 200.4377, 826.8185, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+640, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+641, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+642, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+643, 202742, 643, 5004, 5004, 3, 169, 0, 234.6348, 750.9623, 808.2863, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+644, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+645, 202742, 643, 5004, 5004, 3, 169, 0, 200.4481, 773.2861, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+646, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+647, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+648, 202742, 643, 5004, 5004, 3, 169, 0, 132.0989, 774.636, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+649, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+650, 202742, 643, 5004, 5004, 3, 169, 0, 40.17184, 834.3758, 806.847, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+651, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+652, 202742, 643, 5004, 5004, 3, 169, 0, 37.45625, 803.8706, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+653, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+654, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+655, 202742, 643, 5004, 5004, 3, 169, 0, 39.93117, 791.3494, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+656, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+657, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+658, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+659, 202742, 643, 5004, 5004, 3, 169, 0, -151.5696, 811.7796, 797.6751, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+660, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+661, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+662, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+663, 202742, 643, 5004, 5004, 3, 169, 0, 42.51493, 804.5654, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+664, 202742, 643, 5004, 5004, 3, 169, 0, 40.60753, 805.2148, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+665, 202742, 643, 5004, 5004, 3, 169, 0, 223.5058, 835.8316, 808.9401, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+666, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+667, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+668, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+669, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+670, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+671, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+672, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+673, 202742, 643, 5004, 5004, 3, 169, 0, 46.42083, 790.2306, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+674, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+675, 202742, 643, 5004, 5004, 3, 169, 0, 35.415, 793.2467, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+676, 202742, 643, 5004, 5004, 3, 169, 0, 209.2919, 796.3069, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+677, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+678, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+679, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+680, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+681, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+682, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+683, 202742, 643, 5004, 5004, 3, 169, 0, 165.2075, 752.0398, 808.8794, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+684, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+685, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+686, 202742, 643, 5004, 5004, 3, 169, 0, -147.9583, 807.6516, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+687, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+688, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+689, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+690, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+691, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+692, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+693, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+694, 202742, 643, 5004, 5004, 3, 169, 0, 66.62801, 836.2322, 807.0526, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+695, 202742, 643, 5004, 5004, 3, 169, 0, 34.39502, 773.1477, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+696, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+697, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+698, 202742, 643, 5004, 5004, 3, 169, 0, 28.35011, 780.5449, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+699, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+700, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+701, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+702, 202742, 643, 5004, 5004, 3, 169, 0, 39.4081, 788.0806, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+703, 202742, 643, 5004, 5004, 3, 169, 0, 55.37197, 836.162, 806.848, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+704, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+705, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+706, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+707, 202742, 643, 5004, 5004, 3, 169, 0, -123.85, 802.1953, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+708, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+709, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+710, 202742, 643, 5004, 5004, 3, 169, 0, 168.658, 802.467, 808.0177, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+711, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+712, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+713, 202742, 643, 5004, 5004, 3, 169, 0, 43.07348, 821.6616, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+714, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+715, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+716, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+717, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+718, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+719, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+720, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+721, 202742, 643, 5004, 5004, 3, 169, 0, 91.35651, 792.2914, 807.1234, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+722, 202742, 643, 5004, 5004, 3, 169, 0, -178.8802, 801.9913, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+723, 202742, 643, 5004, 5004, 3, 169, 0, 196.4497, 802.3195, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+724, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+725, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+726, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+727, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+728, 202742, 643, 5004, 5004, 3, 169, 0, 235.7025, 831.2547, 808.7969, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+729, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+730, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+731, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+732, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+733, 202742, 643, 5004, 5004, 3, 169, 0, 61.52082, 805.3383, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+734, 202742, 643, 5004, 5004, 3, 169, 0, 34.08147, 821.5872, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+735, 202742, 643, 5004, 5004, 3, 169, 0, 41.34742, 768.7258, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+736, 202742, 643, 5004, 5004, 3, 169, 0, 223.1389, 802.7222, 808.0499, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+737, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+738, 202742, 643, 5004, 5004, 3, 169, 0, 236.5851, 757.8958, 807.5884, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+739, 202742, 643, 5004, 5004, 3, 169, 0, 171.5869, 808.459, 808.8981, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+740, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+741, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+742, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+743, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+744, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+745, 202742, 643, 5004, 5004, 3, 169, 0, 74.49322, 827.2534, 807.1271, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+746, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+747, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+748, 202742, 643, 5004, 5004, 3, 169, 0, -166.5038, 801.6523, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+749, 202742, 643, 5004, 5004, 3, 169, 0, 193.908, 774.3281, 807.8459, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+750, 202742, 643, 5004, 5004, 3, 169, 0, 190.8542, 830.8698, 807.873, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+751, 202742, 643, 5004, 5004, 3, 169, 0, -54.44445, 803.0816, 797.1558, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+752, 202742, 643, 5004, 5004, 3, 169, 0, 84.90799, 801.6302, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+753, 202742, 643, 5004, 5004, 3, 169, 0, 37.33333, 779.8646, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+754, 202742, 643, 5004, 5004, 3, 169, 0, 52.02951, 753.0799, 806.193, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+755, 202742, 643, 5004, 5004, 3, 169, 0, 157.9003, 807.3672, 808.6937, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+756, 202742, 643, 5004, 5004, 3, 169, 0, 31.56881, 779.1186, 807.0149, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+757, 202742, 643, 5004, 5004, 3, 169, 0, 148.4271, 757.5121, 807.6461, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+758, 202742, 643, 5004, 5004, 3, 169, 0, 52.17708, 854.7934, 806.0573, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+759, 202742, 643, 5004, 5004, 3, 169, 0, -103.4774, 802.0746, 796.6592, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+760, 202742, 643, 5004, 5004, 3, 169, 0, -81.20834, 801.6094, 797.083, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+761, 202742, 643, 5004, 5004, 3, 169, 0, 50.75718, 822.6475, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+762, 202742, 643, 5004, 5004, 3, 169, 0, 196.4739, 808.0817, 807.7212, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+763, 202742, 643, 5004, 5004, 3, 169, 0, -25.61806, 802.1458, 805.629, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+764, 202742, 643, 5004, 5004, 3, 169, 0, 34.17076, 800.0736, 806.4003, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+765, 202742, 643, 5004, 5004, 3, 169, 0, -128.7379, 802.4809, 796.9691, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+766, 202742, 643, 5004, 5004, 3, 169, 0, 221.8779, 757.4844, 808.7989, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+767, 202742, 643, 5004, 5004, 3, 169, 0, 217.8538, 830.1664, 808.9406, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+768, 202742, 643, 5004, 5004, 3, 169, 0, -152.0358, 802.0839, 797.0841, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+769, 202742, 643, 5004, 5004, 3, 169, 0, 38.71181, 801.5816, 805.5076, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+770, 202742, 643, 5004, 5004, 3, 169, 0, 231.8177, 843.3507, 807.885, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+771, 202742, 643, 5004, 5004, 3, 169, 0, 36.89356, 834.9725, 807.1595, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+772, 202742, 643, 5004, 5004, 3, 169, 0, 145.1441, 845.1511, 807.6957, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+773, 202742, 643, 5004, 5004, 3, 169, 0, 128.2726, 802.2448, 808.4679, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+774, 202742, 643, 5004, 5004, 3, 169, 0, -153.5156, 803.0816, 796.5791, 0, 0, 0, 0, 1, 7200, 255, 1, 26365), -- Temp Falling Rocks (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+775, 205216, 643, 5004, 5004, 3, 169, 0, -157.986, 982.238, 229.131, 2.984498, 0, 0, 0.9969168, 0.07846643, 7200, 255, 1, 26365), -- Neptulon's Cache (Area: Throne of the Tides - Difficulty: 2)
(@OGUID+776, 204964, 643, 5004, 5004, 3, 169, 0, -647.283, 806.7465, 249.3488, 0, 0, 0, 0, 1, 7200, 255, 1, 26365); -- Instance Portal (Party + Heroic) (Area: Throne of the Tides - Difficulty: 2)


DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+775;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- Doodad_WG_Invisible_Door02
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Leviathan_Tentacle_fromBelow01
(@OGUID+3, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Leviathan_Tentacle01
(@OGUID+4, 0, 0, 1, -0.00000004371139), -- Doodad_WG_Invisible_Door01
(@OGUID+5, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Maw_Door_04
(@OGUID+6, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Maw_Door_03
(@OGUID+7, 0, 0, 1, -0.00000004371139), -- 0
(@OGUID+8, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Maw_Door_02
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- Doodad_Abyssal_Maw_Door_01
(@OGUID+208, 0, 0, 1, -0.00000004371139); -- Doodad_Abyssal_Coral_Chunk_Ceiling01_Break01

DELETE FROM `creature_template_addon` WHERE `entry` IN (44752 /*44752 (Faceless Sapper)*/, 44566 /*44566 (Ozumat) - Ozumat Globe Impact Periodic*/, 44950 /*44950 (Unyielding Behemoth (Hand Visual)) - Ride Vehicle Hardcoded, Shrink*/, 44864 /*44864 (Ozumat Combat Trigger)*/, 92870 /*92870 (Sindragosa's Fury)*/, 40765 /*40765 (Commander Ulthok) - Ulthok Intro Visual State*/, 40925 /*40925 (Tainted Sentry) - Summon Unstable Corruptions*/, 40923 /*40923 (Unstable Corruption) - Unstable Corruption Growth*/, 40943 /*40943 (Gilgoblin Aquamage)*/, 40792 /*40792 (Neptulon) - Purify*/, 40936 /*40936 (Faceless Watcher) - Void Rip*/, 40935 /*40935 (Gilgoblin Hunter)*/, 40633 /*40633 (Naz'jar Honor Guard) - Water Window Break Visual*/, 44404 /*44404 (Naz'jar Tempest Witch) - Water Window Break Visual*/, 40586 /*40586 (Lady Naz'jar) - Waterspout*/, 41139 /*41139 (Naz'jar Spiritmender) - Water Window Jump Through Visual*/, 40584 /*40584 (Naz'jar Invader) - Water Window Jump Through Visual*/, 40634 /*40634 (Naz'jar Tempest Witch)*/, 51395 /*51395 (Throne of Tides Teleporter) - Teleporter Active Visual*/, 40579 /*40579 (Deep Murloc Hunter)*/, 39959 /*39959 (Lady Naz'jar)*/, 39960 /*39960 (Deep Murloc Drudge)*/, 44656 /*44656 (Ozumat Add Spawner)*/, 41096 /*41096 (Naz'jar Spiritmender) - Water Window Jump Through Visual*/, 39616 /*39616 (Naz'jar Invader) - Water Window Jump Through Visual*/, 40825 /*40825 (Erunak Stonespeaker) - Enslave*/, 40788 /*40788 (Mindbender Ghur'sha) - Unrelenting Agony*/, 40577 /*40577 (Naz'jar Sentinel)*/, 50270 /*50270 (Captain Taylor)*/, 45030 /*45030 (Ozumat Vehicle, Big)*/, 40655 /*40655 (Ozumat)*/, 48983 /*48983 (Geyser) - Geyser*/, 44581 /*44581 (Ozumat Vehicle)*/, 45672 /*45672 (Naz'jar Soldier)*/, 51391 /*51391 (Throne of Tides Teleporter) - Teleporter Base Visual*/, 45620 /*45620 (Naz'jar Soldier)*/, 45621 /*45621 (Elemental Guard) - Water Bolt*/, 50278 /*50278 (Naz'jar Invader) - Permanent Feign Death*/, 50276 /*50276 (Naz'jar Spiritmender) - Permanent Feign Death*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(44752, 0, 0, 0, 1, 0, ''), -- 44752 (Faceless Sapper)
(44566, 0, 0, 50331648, 1, 0, '83126'), -- 44566 (Ozumat) - Ozumat Globe Impact Periodic
(44950, 0, 0, 50331648, 1, 0, '83976'), -- 44950 (Unyielding Behemoth (Hand Visual)) - Ride Vehicle Hardcoded, Shrink
(44864, 0, 0, 0, 1, 0, ''), -- 44864 (Ozumat Combat Trigger)
-- (92870, 0, 0, 50331648, 1, 0, ''), -- 92870 (Sindragosa's Fury)
(40765, 0, 0, 0, 1, 0, '76017'), -- 40765 (Commander Ulthok) - Ulthok Intro Visual State
(40925, 0, 0, 0, 1, 0, '76625'), -- 40925 (Tainted Sentry) - Summon Unstable Corruptions
(40923, 0, 0, 0, 1, 0, '76362'), -- 40923 (Unstable Corruption) - Unstable Corruption Growth
(40943, 0, 0, 0, 1, 0, ''), -- 40943 (Gilgoblin Aquamage)
(40792, 0, 0, 0, 1, 0, '76952'), -- 40792 (Neptulon) - Purify
(40936, 0, 0, 0, 1, 0, '76604'), -- 40936 (Faceless Watcher) - Void Rip
(40935, 0, 0, 0, 1, 0, ''), -- 40935 (Gilgoblin Hunter)
(40633, 0, 0, 50331648, 1, 0, '75808'), -- 40633 (Naz'jar Honor Guard) - Water Window Break Visual
(44404, 0, 0, 0, 1, 0, '75808'), -- 44404 (Naz'jar Tempest Witch) - Water Window Break Visual
(40586, 0, 0, 0, 1, 0, '90495'), -- 40586 (Lady Naz'jar) - Waterspout
(41139, 0, 0, 0, 1, 0, '74048'), -- 41139 (Naz'jar Spiritmender) - Water Window Jump Through Visual
(40584, 0, 0, 50331648, 1, 0, '74048'), -- 40584 (Naz'jar Invader) - Water Window Jump Through Visual
(40634, 0, 0, 0, 1, 0, ''), -- 40634 (Naz'jar Tempest Witch)
(51395, 0, 0, 50331648, 1, 0, '95296'), -- 51395 (Throne of Tides Teleporter) - Teleporter Active Visual
(40579, 0, 0, 0, 1, 0, ''), -- 40579 (Deep Murloc Hunter)
(39959, 0, 0, 0, 1, 0, ''), -- 39959 (Lady Naz'jar)
(39960, 0, 0, 0, 1, 0, ''), -- 39960 (Deep Murloc Drudge)
(44656, 0, 0, 0, 1, 0, ''), -- 44656 (Ozumat Add Spawner)
(41096, 0, 0, 50331648, 1, 0, '74048'), -- 41096 (Naz'jar Spiritmender) - Water Window Jump Through Visual
(39616, 0, 0, 50331648, 1, 0, '74048'), -- 39616 (Naz'jar Invader) - Water Window Jump Through Visual
(40825, 0, 0, 0, 1, 0, '76616'), -- 40825 (Erunak Stonespeaker) - Enslave
(40788, 0, 0, 0, 1, 0, '76339'), -- 40788 (Mindbender Ghur'sha) - Unrelenting Agony
(40577, 0, 0, 0, 1, 0, ''), -- 40577 (Naz'jar Sentinel)
(50270, 0, 0, 0, 1, 0, ''), -- 50270 (Captain Taylor)
(45030, 0, 0, 50331648, 1, 0, ''), -- 45030 (Ozumat Vehicle, Big)
(40655, 0, 0, 50331648, 1, 0, ''), -- 40655 (Ozumat)
(48983, 0, 0, 0, 1, 0, '91347'), -- 48983 (Geyser) - Geyser
(44581, 0, 0, 50331648, 1, 0, ''), -- 44581 (Ozumat Vehicle)
(45672, 0, 0, 50331648, 1, 0, ''), -- 45672 (Naz'jar Soldier)
(51391, 0, 0, 50331648, 1, 0, '95293'), -- 51391 (Throne of Tides Teleporter) - Teleporter Base Visual
(45620, 0, 0, 50331648, 1, 0, ''), -- 45620 (Naz'jar Soldier)
(45621, 0, 0, 50331648, 1, 0, '85211'), -- 45621 (Elemental Guard) - Water Bolt
(50278, 0, 0, 0, 1, 0, '29266'), -- 50278 (Naz'jar Invader) - Permanent Feign Death
(50276, 0, 0, 0, 1, 0, '29266'); -- 50276 (Naz'jar Spiritmender) - Permanent Feign Death

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=21252; -- 21252 (World Trigger (Not Immune PC))
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=22517; -- 22517 (World Trigger (Large AOI))
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=36171; -- 36171 (World Trigger (Infinite AOI))

UPDATE `creature_model_info` SET `BoundingRadius`=1.525103 WHERE `DisplayID`=32708;
UPDATE `creature_model_info` SET `BoundingRadius`=4.129169 WHERE `DisplayID`=33792;
UPDATE `creature_model_info` SET `BoundingRadius`=1.355182 WHERE `DisplayID`=33846;
UPDATE `creature_model_info` SET `BoundingRadius`=0.05212237, `CombatReach`=0.05 WHERE `DisplayID`=33845;
UPDATE `creature_model_info` SET `BoundingRadius`=2.752779 WHERE `DisplayID`=31674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8949282 WHERE `DisplayID`=37388;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `CombatReach`=1 WHERE `DisplayID`=30408;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186 WHERE `DisplayID`=37386;
UPDATE `creature_model_info` SET `BoundingRadius`=1.198815 WHERE `DisplayID`=32578;
UPDATE `creature_model_info` SET `BoundingRadius`=1.649186 WHERE `DisplayID`=37370;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8949282 WHERE `DisplayID`=37387;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3 WHERE `DisplayID`=16925;

DELETE FROM `gossip_menu` WHERE (`MenuId`=12568 AND `TextId`=17676);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(12568, 17676); -- 50270 (Captain Taylor)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11469 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(11469, 0, 0, 'We are ready!', 41133);

DELETE FROM `creature_text` WHERE `CreatureID` IN (39959,40586,40765,40788,40792,40825);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39959, 0, 0, 'Armies of the depths, wash over our enemies as a tide of death!', 14, 0, 100, 0, 0, 18890, 50510, 'Lady Naz''jar to Player'),
(39959, 1, 0, 'Meddlesome gnats! You think us defeated so easily?', 14, 0, 100, 0, 0, 18891, 43121, 'Lady Naz''jar to Player'),
(40586, 0, 0, 'You have interfered with our plans for the last time, mortals!', 14, 0, 100, 0, 0, 18886, 50505, 'Lady Naz''jar to Player'),
(40586, 1, 0, 'Take arms, minions! Rise from the icy depths!', 14, 0, 100, 0, 0, 18892, 50513, 'Lady Naz''jar'),
(40586, 2, 0, 'Destroy these intruders! Leave them for the great dark beyond!', 14, 0, 100, 0, 0, 18893, 50514, 'Lady Naz''jar'),
(40586, 3, 0, 'Ulthok, stop them...', 14, 0, 100, 0, 0, 18889, 50509, 'Lady Naz''jar to Player'),
(40765, 0, 0, 'Iilth vwah, uhn''agth fhssh za.', 14, 0, 100, 0, 0, 18543, 50522, 'Commander Ulthok to Player'),
(40765, 1, 0, 'Where one falls, many shall take its place...', 15, 0, 100, 0, 0, 18543, 50523, 'Commander Ulthok to Player'),
(40765, 2, 0, 'Ywaq maq oou.', 14, 0, 100, 0, 0, 18542, 50529, 'Commander Ulthok to Player'),
(40788, 0, 0, 'A new host must be found.', 14, 0, 100, 0, 0, 18860, 50534, 'Mindbender Ghur''sha to Erunak Stonespeaker'),
(40788, 1, 0, 'Is. This. Reality?', 14, 0, 100, 0, 0, 18867, 50543, 'Mindbender Ghur''sha'),
(40788, 2, 0, 'They are outside the cycle...', 14, 0, 100, 0, 0, 18863, 50538, 'Mindbender Ghur''sha to Player'),
(40792, 0, 0, 'Ahh - my fearless assistants, I assume.', 14, 0, 100, 0, 0, 19469, 44263, 'Neptulon to Player'),
(40792, 1, 0, 'You may yet regret your presence here.', 14, 0, 100, 0, 0, 19470, 44264, 'Neptulon to Player'),
(40792, 2, 0, 'As I purify these waters, the servants of filth will surely be stirred. Beware!', 14, 0, 100, 0, 0, 19471, 44265, 'Neptulon to Player'),
(40792, 3, 0, 'Patience, guests. The waters are nearly cleansed.', 14, 0, 100, 0, 0, 19475, 44269, 'Neptulon to Player'),
(40792, 4, 0, 'The beast has returned! It must not pollute my waters!', 14, 0, 100, 0, 0, 19476, 44270, 'Neptulon to Player'),
(40792, 5, 0, 'Augh... Their filthiness stains me!', 14, 0, 100, 0, 0, 19472, 44266, 'Neptulon to Player'),
(40792, 6, 0, 'My waters are cleansed! Drink in their power!', 14, 0, 100, 0, 0, 19478, 44272, 'Neptulon to Player'),
(40792, 7, 0, 'Behold the power of pure water!', 14, 0, 100, 0, 0, 19477, 44271, 'Neptulon to Player'),
(40792, 8, 0, 'Ozumat is vulnerable, strike now!', 41, 0, 100, 0, 0, 19477, 50863, 'Neptulon to Player'),
(40825, 0, 0, 'I thank you, my friends. Forgive me. I... I have grown too weak to be of any assistance.', 14, 0, 100, 0, 0, 18662, 50533, 'Erunak Stonespeaker'),
(40825, 1, 0, 'I am... weary. You must carry on without me. I shall take my leave once my strength has returned.', 14, 0, 100, 0, 0, 18664, 50648, 'Erunak Stonespeaker to Player');

DELETE FROM `npc_spellclick_spells` WHERE (`npc_entry`=51391 AND `spell_id`=95284) OR (`npc_entry`=51395 AND `spell_id`=95285);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(51391, 95284, 3, 0),
(51395, 95285, 3, 0);
