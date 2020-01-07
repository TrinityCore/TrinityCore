DELETE FROM `spawn_group_template` WHERE `groupId` IN (419, 420, 421, 422);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(419, 'Shadowfang Keep - Lord Godfrey Dead Alliance Troups', 4),
(420, 'Shadowfang Keep - Lord Godfrey Dead Horde Troups', 4),
(421, 'Shadowfang Keep - Baron Ashbury Alliance Troups', 4),
(422, 'Shadowfang Keep - Baron Ashbury Horde Troups', 4);

SET @CGUID := 395322;
DELETE FROM `spawn_group` WHERE `groupId` IN (419, 420, 421, 422);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Lord Godfrey Dead Alliance Troups
(419, 0, @CGUID+7),
(419, 0, @CGUID+8),
(419, 0, @CGUID+9),
(419, 0, @CGUID+10),
(419, 0, @CGUID+11),
(419, 0, @CGUID+12),
-- Lord Godfrey Dead Horde Troups
(420, 0, @CGUID+0),
(420, 0, @CGUID+1),
(420, 0, @CGUID+2),
(420, 0, @CGUID+3),
(420, 0, @CGUID+4),
(420, 0, @CGUID+5),
(420, 0, @CGUID+6),
-- Baron Ashbury Alliance Troups
(421, 0, @CGUID+13),
(421, 0, @CGUID+14),
(421, 0, @CGUID+15),
(421, 0, @CGUID+16),
(421, 0, @CGUID+17),
(421, 0, @CGUID+18),
(421, 0, @CGUID+19),
-- Baron Ashbury Horde Troups
(422, 0, @CGUID+20),
(422, 0, @CGUID+21),
(422, 0, @CGUID+22),
(422, 0, @CGUID+23),
(422, 0, @CGUID+24),
(422, 0, @CGUID+25),
(422, 0, @CGUID+26);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Lord Godfrey Dead Horde Troups
(@CGUID+0, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -87.6441, 2126.23, 145.0043, 2.443461, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -102.142, 2123.2, 155.7383, 5.864306, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+2, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -111.995, 2133.53, 145.0043, 1.692969, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+3, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -94.2517, 2138.56, 145.0043, 5.148721, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+4, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -75.3976, 2143.99, 155.6093, 3.577925, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+5, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -91.5174, 2148.32, 145.0043, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+6, 47294, 33, 209, 0, 3, 169, 0, 0, 0, -110.026, 2158.99, 155.7623, 6.178465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- High Warlord Cromush (Area: 0 - Difficulty: 0)
-- Lord Godfrey Dead Alliance Troups
(@CGUID+7, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -76.5694, 2138.99, 154.2303, 0.296706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+8, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -87.4427, 2152.68, 145.0043, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+9, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -92.4045, 2141.42, 145.0043, 0.296706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+10, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -74.6024, 2152.2, 155.7893, 2.827433, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+11, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -94.9236, 2128.72, 145.0043, 3.665191, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
(@CGUID+12, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -109.05, 2132.08, 145.0043, 1.710423, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2) (Auras: 29266 - Permanent Feign Death)
-- Baron Ashbury Alliance Troups
(@CGUID+13, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -235.01, 2136.48, 87.09804, 4.719248, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+14, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -247.602, 2112.6, 87.09563, 2.775074, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+15, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -246.389, 2112.02, 87.09373, 2.775074, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+16, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -229.707, 2144.31, 90.70734, 2.792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+17, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -248.965, 2113.26, 87.09624, 2.984513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+18, 47027, 33, 209, 209, 3, 169, 0, 0, 0, -227.457, 2149.91, 90.70734, 2.792527, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bloodfang Berserker (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+19, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -239.936, 2116.16, 87.08714, 2.740167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
-- Baron Ashbury Horde Troups
(@CGUID+20, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -237.592, 2150.78, 90.70734, 4.555309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+21, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -233.04, 2149.04, 90.70734, 4.34587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+22, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -233.597, 2140.91, 87.09624, 4.39823, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+23, 47030, 33, 209, 0, 3, 169, 0, 0, 0, -240.047, 2143.16, 87.09624, 4.45059, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veteran Forsaken Trooper (Area: 0 - Difficulty: 0)
(@CGUID+24, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -218.477, 2146.08, 90.70734, 2.897247, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+25, 47031, 33, 209, 0, 3, 169, 0, 0, 0, -220.705, 2140.32, 90.70734, 2.75762, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Blightspreader (Area: 0 - Difficulty: 0)
(@CGUID+26, 47293, 33, 209, 0, 3, 169, 0, 0, 0, -240.5535, 2130.556, 87.04115, 4.047379, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+0, 0, 1, '29266'),
(@CGUID+1, 0, 1, '29266'),
(@CGUID+2, 0, 1, '29266'),
(@CGUID+3, 0, 1, '29266'),
(@CGUID+4, 0, 1, '29266'),
(@CGUID+5, 0, 1, '29266'),
(@CGUID+6, 8, 1, ''),
(@CGUID+7, 0, 1, '29266'),
(@CGUID+8, 0, 1, '29266'),
(@CGUID+9, 0, 1, '29266'),
(@CGUID+10, 0, 1, '29266'),
(@CGUID+11, 0, 1, '29266'),
(@CGUID+12, 0, 1, '29266');
