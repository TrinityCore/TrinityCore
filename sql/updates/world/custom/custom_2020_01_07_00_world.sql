DELETE FROM `creature_summon_groups` WHERE `summonerId`= 33 AND `summonerType`= 2;
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName` IN ('npc_sfk_veteran_forsaken_trooper', 'npc_sfk_high_warlord_cromush', 'npc_sfk_bloodfang_berserker', 'npc_sfk_packleader_ivar_bloodfang', 'npc_sfk_deathstalker_commander_belmont');

DELETE FROM `spawn_group_template` WHERE `groupId` IN (412, 413, 414);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(412, 'Shadowfang Keep - Alliance Entrance', 4),
(413, 'Shadowfang Keep - Horde Entrance', 4),
(414, 'Shadowfang Keep - Disease Clouds Entrance', 4);

SET @CGUID := 395108;
DELETE FROM `spawn_group` WHERE `groupId` IN (412, 413, 414);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Alliance Entrance
(412, 0, @CGUID+0),
(412, 0, @CGUID+1),
(412, 0, @CGUID+2),
(412, 0, @CGUID+3),
(412, 0, @CGUID+4),
(412, 0, @CGUID+5),
(412, 0, @CGUID+6),
-- Horde Entrance
(413, 0, @CGUID+7),
(413, 0, @CGUID+8),
(413, 0, @CGUID+9),
(413, 0, @CGUID+10),
(413, 0, @CGUID+11),
(413, 0, @CGUID+12),
(413, 0, @CGUID+13),
-- Disease Clouds Entrance
(414, 0, @CGUID+14),
(414, 0, @CGUID+15),
(414, 0, @CGUID+16),
(414, 0, @CGUID+17),
(414, 0, @CGUID+18),
(414, 0, @CGUID+19),
(414, 0, @CGUID+20),
(414, 0, @CGUID+21),
(414, 0, @CGUID+22),
(414, 0, @CGUID+23),
(414, 0, @CGUID+24),
(414, 0, @CGUID+25),
(414, 0, @CGUID+26),
(414, 0, @CGUID+27),
(414, 0, @CGUID+28),
(414, 0, @CGUID+29),
(414, 0, @CGUID+30),
(414, 0, @CGUID+31),
(414, 0, @CGUID+32),
(414, 0, @CGUID+33),
(414, 0, @CGUID+34),
(414, 0, @CGUID+35),
(414, 0, @CGUID+36),
(414, 0, @CGUID+37),
(414, 0, @CGUID+38),
(414, 0, @CGUID+39),
(414, 0, @CGUID+40),
(414, 0, @CGUID+41),
(414, 0, @CGUID+42),
(414, 0, @CGUID+43),
(414, 0, @CGUID+44),
(414, 0, @CGUID+45),
(414, 0, @CGUID+46),
(414, 0, @CGUID+47),
(414, 0, @CGUID+48),
(414, 0, @CGUID+49),
(414, 0, @CGUID+50),
(414, 0, @CGUID+51);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+51;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Alliance Entrance
(@CGUID+0, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -215.484, 2126.58, 80.70493, 4.468043, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+1, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -225.997, 2135.15, 80.93173, 4.660029, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+2, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -216.786, 2121.5, 80.34393, 4.468043, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+3, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -214.123, 2132.59, 80.90813, 4.468043, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+4, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -227.486, 2124.11, 80.37684, 4.660029, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+5, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -226.573, 2128.72, 80.74143, 4.660029, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+6, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -219.417, 2137.05, 80.97094, 4.485496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
-- Horde Entrance
(@CGUID+7, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -225.693, 2136.02, 80.95454, 4.677482, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+8, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -214.486, 2134.03, 80.94864, 4.485496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+9, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -228.497, 2122.73, 80.25184, 4.782202, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+10, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -216.899, 2120.18, 80.24763, 4.276057, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+11, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -217.365, 2122.68, 80.41753, 4.34587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+12, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -226.722, 2124.83, 80.44633, 4.625123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+13, 47293, 33, 209, 0, 3, 169, 0, 0, 0, -220.958, 2129.48, 80.78983, 4.607669, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0)
-- Disease Clouds Entrance
(@CGUID+14, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -204.96, 2104.55, 77.02894, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+15, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.318, 2102.04, 76.97733, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+16, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -232.595, 2109.81, 76.97463, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+17, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.844, 2104.05, 76.97723, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+18, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -230.3, 2131.51, 80.54034, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+19, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -233.965, 2112.36, 76.93284, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+20, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.861, 2125.93, 80.53143, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+21, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -233.111, 2110.01, 76.81664, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+22, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -232.684, 2115.75, 76.91784, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+23, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -221.415, 2106.98, 76.80504, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+24, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.427, 2104.38, 76.40823, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+25, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -211.948, 2103.17, 76.97723, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+26, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -233.917, 2113.56, 76.69134, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+27, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -212.635, 2101.51, 76.97733, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+28, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.181, 2102.54, 76.97733, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+29, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.344, 2124.69, 80.37054, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+30, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -233.686, 2114.25, 76.97353, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+31, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.344, 2123.62, 80.32754, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+32, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -221.708, 2143.04, 81.70863, 4.433136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+33, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -223.46, 2143.73, 81.47704, 4.29351, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+34, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -218.227, 2141.67, 81.38644, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+35, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.439, 2140.15, 81.69784, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+36, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -219.042, 2141.99, 81.62763, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+37, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -227.076, 2145.15, 81.34364, 4.555309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+38, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -216.286, 2140.91, 81.48534, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+39, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -230.608, 2146.54, 81.36684, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+40, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -215.217, 2140.47, 81.55943, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+41, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -222.495, 2143.35, 81.57973, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+42, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.128, 2139.61, 81.71724, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+43, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -228.818, 2145.84, 81.49213, 4.537856, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+44, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -225.245, 2144.43, 81.35064, 4.520403, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+45, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -224.319, 2144.07, 81.46143, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+46, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -228.016, 2145.52, 81.41843, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+47, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -217.28, 2141.3, 81.67484, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+48, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -219.905, 2142.33, 81.50333, 4.468043, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+49, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -220.905, 2142.73, 81.48224, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+50, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -226.214, 2144.81, 81.37144, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+51, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -229.615, 2146.15, 81.40894, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+14 AND @CGUID+51;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+14, '88198'),
(@CGUID+15, '88198'),
(@CGUID+16, '88198'),
(@CGUID+17, '88198'),
(@CGUID+18, '88198'),
(@CGUID+19, '88198'),
(@CGUID+20, '88198'),
(@CGUID+21, '88198'),
(@CGUID+22, '88198'),
(@CGUID+23, '88198'),
(@CGUID+24, '88198'),
(@CGUID+25, '88198'),
(@CGUID+26, '88198'),
(@CGUID+27, '88198'),
(@CGUID+28, '88198'),
(@CGUID+29, '88198'),
(@CGUID+30, '88198'),
(@CGUID+31, '88198'),
(@CGUID+32, '88198'),
(@CGUID+33, '88198'),
(@CGUID+34, '88198'),
(@CGUID+35, '88198'),
(@CGUID+36, '88198'),
(@CGUID+37, '88198'),
(@CGUID+38, '88198'),
(@CGUID+39, '88198'),
(@CGUID+40, '88198'),
(@CGUID+41, '88198'),
(@CGUID+42, '88198'),
(@CGUID+43, '88198'),
(@CGUID+44, '88198'),
(@CGUID+45, '88198'),
(@CGUID+46, '88198'),
(@CGUID+47, '88198'),
(@CGUID+48, '88198'),
(@CGUID+49, '88198'),
(@CGUID+50, '88198'),
(@CGUID+51, '88198');

DELETE FROM `creature_text` WHERE `CreatureID`= 47006 AND `GroupID`= 14;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47006, 14, 0, 'Crowley is a disgrace to our kind for giving in to the Forsaken. My pack will show them the true face of the worgen and the relentless fury that comes with our presence!', 12, 0, 100, 5, 0, 0, 47364, 'Packleader Ivar Bloodfang');

-- Creature Packleader Ivar Bloodfang 47006 SAI
-- Creature  -395114 SAI
SET @ENTRY := 47006;
SET @GUID := -(@CGUID+6);
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 1, 0, 100, 0, 1000, 60000, 60000, 61000, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 60000 ms (and later repeats every 60000 and 61000 ms) - Self: Talk 14 // ");
