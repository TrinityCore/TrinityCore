DELETE FROM `spawn_group_template` WHERE `groupId` IN (415, 416, 417, 418);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(415, 'Shadowfang Keep - Disease Clouds Baron Ashbury', 4),
(416, 'Shadowfang Keep - Disease Clouds Baron Silverlaine', 4),
(417, 'Shadowfang Keep - Disease Clouds Commander Springvale', 4),
(418, 'Shadowfang Keep - Disease Clouds Lord Walden', 4);

SET @CGUID := 395160;
DELETE FROM `spawn_group` WHERE `groupId` IN (415, 416, 417, 418);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Disease Clouds Baron Ashbury
(415, 0, @CGUID+0),
(415, 0, @CGUID+1),
(415, 0, @CGUID+2),
(415, 0, @CGUID+3),
(415, 0, @CGUID+4),
(415, 0, @CGUID+5),
(415, 0, @CGUID+6),
(415, 0, @CGUID+7),
(415, 0, @CGUID+8),
(415, 0, @CGUID+9),
(415, 0, @CGUID+10),
(415, 0, @CGUID+11),
(415, 0, @CGUID+12),
(415, 0, @CGUID+13),
(415, 0, @CGUID+14),
(415, 0, @CGUID+15),
(415, 0, @CGUID+16),
(415, 0, @CGUID+17),
(415, 0, @CGUID+18),
(415, 0, @CGUID+19),
(415, 0, @CGUID+20),
(415, 0, @CGUID+21),
(415, 0, @CGUID+22),
(415, 0, @CGUID+23),
(415, 0, @CGUID+24),
(415, 0, @CGUID+25),
(415, 0, @CGUID+26),
(415, 0, @CGUID+27),
(415, 0, @CGUID+28),
(415, 0, @CGUID+29),
-- Disease Clouds Baron Silverlaine
(416, 0, @CGUID+30),
(416, 0, @CGUID+31),
(416, 0, @CGUID+32),
(416, 0, @CGUID+33),
(416, 0, @CGUID+34),
(416, 0, @CGUID+35),
(416, 0, @CGUID+36),
(416, 0, @CGUID+37),
(416, 0, @CGUID+38),
(416, 0, @CGUID+39),
(416, 0, @CGUID+40),
(416, 0, @CGUID+41),
(416, 0, @CGUID+42),
(416, 0, @CGUID+43),
(416, 0, @CGUID+44),
(416, 0, @CGUID+45),
(416, 0, @CGUID+46),
(416, 0, @CGUID+47),
(416, 0, @CGUID+48),
(416, 0, @CGUID+49),
(416, 0, @CGUID+50),
(416, 0, @CGUID+51),
(416, 0, @CGUID+52),
(416, 0, @CGUID+53),
(416, 0, @CGUID+54),
(416, 0, @CGUID+55),
(416, 0, @CGUID+56),
(416, 0, @CGUID+57),
(416, 0, @CGUID+58),
(416, 0, @CGUID+59),
(416, 0, @CGUID+60),
(416, 0, @CGUID+61),
(416, 0, @CGUID+62),
(416, 0, @CGUID+63),
(416, 0, @CGUID+64),
(416, 0, @CGUID+65),
(416, 0, @CGUID+66),
(416, 0, @CGUID+67),
(416, 0, @CGUID+68),
(416, 0, @CGUID+69),
(416, 0, @CGUID+70),
(416, 0, @CGUID+71),
(416, 0, @CGUID+72),
(416, 0, @CGUID+73),
(416, 0, @CGUID+74),
(416, 0, @CGUID+75),
(416, 0, @CGUID+76),
(416, 0, @CGUID+77),
(416, 0, @CGUID+78),
(416, 0, @CGUID+79),
(416, 0, @CGUID+80),
(416, 0, @CGUID+81),
(416, 0, @CGUID+82),
-- Disease Clouds Commander Springvale
(417, 0, @CGUID+83),
(417, 0, @CGUID+84),
(417, 0, @CGUID+85),
(417, 0, @CGUID+86),
(417, 0, @CGUID+87),
(417, 0, @CGUID+88),
(417, 0, @CGUID+89),
(417, 0, @CGUID+90),
(417, 0, @CGUID+91),
(417, 0, @CGUID+92),
(417, 0, @CGUID+93),
(417, 0, @CGUID+94),
(417, 0, @CGUID+95),
(417, 0, @CGUID+96),
(417, 0, @CGUID+97),
(417, 0, @CGUID+98),
(417, 0, @CGUID+99),
(417, 0, @CGUID+100),
(417, 0, @CGUID+101),
(417, 0, @CGUID+102),
(417, 0, @CGUID+103),
(417, 0, @CGUID+104),
(417, 0, @CGUID+105),
(417, 0, @CGUID+106),
(417, 0, @CGUID+107),
(417, 0, @CGUID+108),
(417, 0, @CGUID+109),
(417, 0, @CGUID+110),
(417, 0, @CGUID+111),
(417, 0, @CGUID+112),
(417, 0, @CGUID+113),
(417, 0, @CGUID+114),
(417, 0, @CGUID+115),
(417, 0, @CGUID+116),
(417, 0, @CGUID+117),
(417, 0, @CGUID+118),
(417, 0, @CGUID+119),
(417, 0, @CGUID+120),
(417, 0, @CGUID+121),
(417, 0, @CGUID+122),
(417, 0, @CGUID+123),
-- Disease Clouds Lord Walde
(418, 0, @CGUID+124),
(418, 0, @CGUID+125),
(418, 0, @CGUID+126),
(418, 0, @CGUID+127),
(418, 0, @CGUID+128),
(418, 0, @CGUID+129),
(418, 0, @CGUID+130),
(418, 0, @CGUID+131),
(418, 0, @CGUID+132),
(418, 0, @CGUID+133),
(418, 0, @CGUID+134),
(418, 0, @CGUID+135),
(418, 0, @CGUID+136),
(418, 0, @CGUID+137),
(418, 0, @CGUID+138),
(418, 0, @CGUID+139),
(418, 0, @CGUID+140),
(418, 0, @CGUID+141),
(418, 0, @CGUID+142),
(418, 0, @CGUID+143),
(418, 0, @CGUID+144),
(418, 0, @CGUID+145),
(418, 0, @CGUID+146),
(418, 0, @CGUID+147),
(418, 0, @CGUID+148),
(418, 0, @CGUID+149),
(418, 0, @CGUID+150),
(418, 0, @CGUID+151),
(418, 0, @CGUID+152),
(418, 0, @CGUID+153),
(418, 0, @CGUID+154),
(418, 0, @CGUID+155),
(418, 0, @CGUID+156),
(418, 0, @CGUID+157),
(418, 0, @CGUID+158),
(418, 0, @CGUID+159),
(418, 0, @CGUID+160),
(418, 0, @CGUID+161);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+161;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Disease Clouds Baron Ashbury
(@CGUID+0, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -198.984, 2109.59, 81.20223, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+1, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -245.837, 2149.73, 90.58404, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+2, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -192.332, 2138.53, 81.58394, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+3, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.46, 2127.16, 87.09354, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+4, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.908, 2150.54, 90.70734, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+5, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -209.188, 2128.17, 86.58434, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+6, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -193.012, 2137.23, 81.58414, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+7, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.332, 2148.02, 90.70734, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+8, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -211.467, 2145.36, 90.60223, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+9, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -195.33, 2139.63, 81.65154, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+10, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -193.042, 2138.81, 81.67624, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+11, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.49, 2127.21, 86.99274, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+12, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.747, 2149.55, 90.70734, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+13, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -209.547, 2127.47, 86.58434, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+14, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -194.257, 2139.17, 81.76923, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+15, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -244.672, 2149.47, 90.51843, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+16, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -242.214, 2149.84, 90.70734, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+17, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -210.578, 2127.44, 86.58394, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+18, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -191.642, 2125.76, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+19, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -189.962, 2124.26, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+20, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -196.08, 2110.17, 81.14014, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+21, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -196.424, 2111.61, 81.14014, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+22, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -189.167, 2125.87, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+23, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -198.033, 2110.79, 81.14014, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+24, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -191.422, 2124.09, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+25, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -195.901, 2108.78, 81.14014, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+26, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -190.896, 2127.02, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+27, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -187.273, 2140.47, 83.16393, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+28, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -197.415, 2109.11, 81.14014, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+29, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -189.793, 2125.31, 81.58504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
-- Disease Clouds Baron Silverlaine
(@CGUID+30, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -216.3368, 2286.54, 77.03741, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+31, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -221.995, 2272.82, 77.13573, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+32, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -202.156, 2273.49, 78.73904, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+33, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.132, 2270.7, 77.15324, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+34, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -202.627, 2250.4, 76.28464, 2.897247, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+35, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -217.625, 2287.2, 76.94003, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+36, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.359, 2271.83, 76.76674, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+37, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -202.703, 2272.38, 78.76473, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+38, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.703, 2271.25, 76.86504, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+39, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -194.781, 2263.11, 76.28464, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+40, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -217.373, 2278.09, 77.13573, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+41, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.488, 2271.35, 78.61384, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+42, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -202.089, 2249.86, 76.28464, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+43, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.177, 2259.62, 83.15204, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+44, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -194.944, 2263.74, 76.28464, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+45, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -221.891, 2273.96, 77.13573, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+46, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -204.274, 2271.15, 77.01453, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+47, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -203.111, 2272.61, 77.20544, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+48, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -226.057, 2205.81, 79.76114, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+49, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -198.583, 2229.32, 82.26794, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+50, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.297, 2192.14, 82.56724, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+51, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -199.908, 2230.16, 81.84364, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+52, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -212.054, 2192.07, 79.84814, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+53, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -180.087, 2243.93, 76.43644, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+54, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.875, 2190.87, 82.37473, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+55, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.41, 2192.32, 79.84804, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+56, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -226.271, 2204.88, 80.11623, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+57, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -197.302, 2228.6, 82.07034, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+58, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -215.231, 2190.72, 79.84843, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+59, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -201.847, 2248.88, 76.28464, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+60, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -180.616, 2244.9, 76.29803, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+61, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.165, 2191.37, 82.32024, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+62, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -212.493, 2191.66, 79.84814, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+63, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -226.009, 2206.58, 79.79234, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+64, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.929, 2191.35, 83.98174, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+65, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -177.997, 2212.55, 80.18803, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+66, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.632, 2191.24, 81.98494, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+67, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -175.674, 2228.62, 76.18094, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+68, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -192.259, 2205.29, 79.84174, 2.70526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+69, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.997, 2192.38, 79.84834, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+70, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.839, 2191.37, 79.84834, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+71, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.503, 2193.08, 79.84804, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+72, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -181.095, 2245.94, 76.26663, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+73, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.444, 2190.19, 79.84834, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+74, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -176.701, 2211.61, 79.95013, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+75, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -174.637, 2212.59, 80.13503, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+76, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -212.069, 2190.69, 79.84834, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+77, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -175.649, 2212.22, 80.07214, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+78, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.594, 2191.03, 84.28364, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+79, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -212.434, 2190.51, 79.84834, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+80, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -213.547, 2189.75, 79.84843, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+81, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -214.299, 2190.41, 82.36844, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+82, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -177.424, 2211.92, 80.33204, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
-- Disease Clouds Commander Springvale
(@CGUID+83, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.642, 2271.03, 79.38973, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+84, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.606, 2271.08, 81.91404, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+85, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.913, 2271.82, 83.70203, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+86, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.689, 2270.63, 85.55144, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+87, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.745, 2270.58, 79.31924, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+88, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.625, 2270.98, 87.19463, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+89, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.677, 2271.35, 83.54284, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+90, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.849, 2271.91, 85.65854, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+91, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.872, 2271.81, 80.15474, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+92, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.74, 2270.33, 79.46603, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+93, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.793, 2270.24, 85.63374, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+94, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.694, 2270.53, 87.15884, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+95, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.691, 2270.7, 81.82224, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+96, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.707, 2270.96, 83.63573, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+97, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.568, 2271.45, 85.53744, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+98, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.606, 2271.42, 79.42104, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+99, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.826, 2271.71, 87.31614, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+100, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.788, 2270.23, 87.21204, 1.186824, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+101, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.762, 2270.24, 81.89844, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+102, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.752, 2270.49, 83.55624, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+103, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.658, 2271.03, 85.75993, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+104, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.851, 2271.97, 82.00774, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+105, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.578, 2271.34, 87.07004, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+106, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.79, 2270.2, 83.57374, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+107, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.398, 2293.67, 74.87874, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+108, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -235.42, 2292.5, 75.16534, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+109, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -273.075, 2303.02, 76.08714, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+110, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -278.142, 2292.59, 76.36253, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+111, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.783, 2284.6, 76.40653, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+112, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.253, 2293.27, 75.01884, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+113, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -275.306, 2300.97, 76.03973, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+114, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -273.957, 2302.89, 76.30494, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+115, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -234.957, 2281.38, 76.41393, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+116, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -274.693, 2301.93, 76.17313, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+117, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -277.2, 2294.35, 76.47643, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+118, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -256.679, 2290.18, 76.35844, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+119, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -237.962, 2293.74, 75.38184, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+120, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -272.161, 2302.71, 76.23653, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+121, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -278.066, 2293.6, 76.22614, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+122, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -240.549, 2284.13, 76.39734, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+123, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -199.486, 2159.17, 79.84794, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
-- Disease Clouds Lord Walden
(@CGUID+124, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -111.708, 2170.45, 101.6033, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+125, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -191.729, 2116.32, 97.06424, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+126, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -167.948, 2227.94, 79.81364, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+127, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -190.245, 2119.68, 97.36363, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+128, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -177.8, 2254.03, 86.64744, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+129, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -114.059, 2149.79, 101.6033, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+130, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -153.753, 2172.67, 99.59763, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+131, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -131.578, 2155.47, 94.12394, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+132, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -131.606, 2179.23, 94.12674, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+133, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -190.63, 2118.51, 97.27174, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+134, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -179.493, 2254.72, 86.79384, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+135, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -132.089, 2184.87, 113.2153, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+136, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -126.002, 2174.99, 94.13094, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+137, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -184.908, 2191.11, 114.0683, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+138, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -133.547, 2178.24, 94.83314, 4.991642, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+139, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -191.156, 2117.4, 97.08774, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+140, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -132.151, 2185.77, 113.2153, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+141, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -126.72, 2177, 94.13013, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+142, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -170.438, 2182.84, 94.94584, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+143, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -121.74, 2152.12, 101.6023, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+144, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -131.191, 2183.35, 113.2153, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+145, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -235.347, 2144.11, 100.1123, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+146, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -236.884, 2208.89, 97.25004, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+147, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -236.405, 2210.15, 97.58244, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+148, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -225.432, 2257.02, 102.8393, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+149, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -246.519, 2188.93, 93.84444, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+150, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -245.3229, 2189.37, 93.61277, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+151, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -248.462, 2188.46, 93.82413, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+152, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -247.786, 2189.25, 93.80784, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+153, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -246.54, 2190.07, 93.90604, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+154, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -256.259, 2168.7, 93.98884, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+155, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -239.667, 2245.22, 101.0163, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+156, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -255.774, 2169.76, 94.06554, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+157, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -238.844, 2245.65, 101.0493, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+158, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -256.59, 2167.6, 94.15224, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+159, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -257.156, 2166.52, 94.15434, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+160, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -245.323, 2128.09, 100.1123, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)
(@CGUID+161, 23837, 33, 209, 0, 3, 169, 0, 0, 0, -241.432, 2127.75, 100.5973, 4.206244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- ELM General Purpose Bunny (Area: 0 - Difficulty: 0) (Auras: 88198 - Disease Cloud)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+161;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+0, '88198'),
(@CGUID+1, '88198'),
(@CGUID+2, '88198'),
(@CGUID+3, '88198'),
(@CGUID+4, '88198'),
(@CGUID+5, '88198'),
(@CGUID+6, '88198'),
(@CGUID+7, '88198'),
(@CGUID+8, '88198'),
(@CGUID+9, '88198'),
(@CGUID+10, '88198'),
(@CGUID+11, '88198'),
(@CGUID+12, '88198'),
(@CGUID+13, '88198'),
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
(@CGUID+51, '88198'),
(@CGUID+52, '88198'),
(@CGUID+53, '88198'),
(@CGUID+54, '88198'),
(@CGUID+55, '88198'),
(@CGUID+56, '88198'),
(@CGUID+57, '88198'),
(@CGUID+58, '88198'),
(@CGUID+59, '88198'),
(@CGUID+60, '88198'),
(@CGUID+61, '88198'),
(@CGUID+62, '88198'),
(@CGUID+63, '88198'),
(@CGUID+64, '88198'),
(@CGUID+65, '88198'),
(@CGUID+66, '88198'),
(@CGUID+67, '88198'),
(@CGUID+68, '88198'),
(@CGUID+69, '88198'),
(@CGUID+70, '88198'),
(@CGUID+71, '88198'),
(@CGUID+72, '88198'),
(@CGUID+73, '88198'),
(@CGUID+74, '88198'),
(@CGUID+75, '88198'),
(@CGUID+76, '88198'),
(@CGUID+77, '88198'),
(@CGUID+78, '88198'),
(@CGUID+79, '88198'),
(@CGUID+80, '88198'),
(@CGUID+81, '88198'),
(@CGUID+82, '88198'),
(@CGUID+83, '88198'),
(@CGUID+84, '88198'),
(@CGUID+85, '88198'),
(@CGUID+86, '88198'),
(@CGUID+87, '88198'),
(@CGUID+88, '88198'),
(@CGUID+89, '88198'),
(@CGUID+90, '88198'),
(@CGUID+91, '88198'),
(@CGUID+92, '88198'),
(@CGUID+93, '88198'),
(@CGUID+94, '88198'),
(@CGUID+95, '88198'),
(@CGUID+96, '88198'),
(@CGUID+97, '88198'),
(@CGUID+98, '88198'),
(@CGUID+99, '88198'),
(@CGUID+100, '88198'),
(@CGUID+101, '88198'),
(@CGUID+102, '88198'),
(@CGUID+103, '88198'),
(@CGUID+104, '88198'),
(@CGUID+105, '88198'),
(@CGUID+106, '88198'),
(@CGUID+107, '88198'),
(@CGUID+108, '88198'),
(@CGUID+109, '88198'),
(@CGUID+110, '88198'),
(@CGUID+111, '88198'),
(@CGUID+112, '88198'),
(@CGUID+113, '88198'),
(@CGUID+114, '88198'),
(@CGUID+115, '88198'),
(@CGUID+116, '88198'),
(@CGUID+117, '88198'),
(@CGUID+118, '88198'),
(@CGUID+119, '88198'),
(@CGUID+120, '88198'),
(@CGUID+121, '88198'),
(@CGUID+122, '88198'),
(@CGUID+123, '88198'),
(@CGUID+124, '88198'),
(@CGUID+125, '88198'),
(@CGUID+126, '88198'),
(@CGUID+127, '88198'),
(@CGUID+128, '88198'),
(@CGUID+129, '88198'),
(@CGUID+130, '88198'),
(@CGUID+131, '88198'),
(@CGUID+132, '88198'),
(@CGUID+133, '88198'),
(@CGUID+134, '88198'),
(@CGUID+135, '88198'),
(@CGUID+136, '88198'),
(@CGUID+137, '88198'),
(@CGUID+138, '88198'),
(@CGUID+139, '88198'),
(@CGUID+140, '88198'),
(@CGUID+141, '88198'),
(@CGUID+142, '88198'),
(@CGUID+143, '88198'),
(@CGUID+144, '88198'),
(@CGUID+145, '88198'),
(@CGUID+146, '88198'),
(@CGUID+147, '88198'),
(@CGUID+148, '88198'),
(@CGUID+149, '88198'),
(@CGUID+150, '88198'),
(@CGUID+151, '88198'),
(@CGUID+152, '88198'),
(@CGUID+153, '88198'),
(@CGUID+154, '88198'),
(@CGUID+155, '88198'),
(@CGUID+156, '88198'),
(@CGUID+157, '88198'),
(@CGUID+158, '88198'),
(@CGUID+159, '88198'),
(@CGUID+160, '88198'),
(@CGUID+161, '88198');
