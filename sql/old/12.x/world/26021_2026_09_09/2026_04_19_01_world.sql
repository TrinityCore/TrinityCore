SET @CGUID := 11000773;

SET @GGUID := 100127;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2694, 15355, 15936, '0', 0, 0, 0, 0, -27.244791030883789, -1053.673583984375, 833.57562255859375, 0.833971023559570312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Vale of Mists - Difficulty: 0)
(@CGUID+1, 6491, 2694, 15355, 15919, '0', 0, 0, 0, 0, -601.53302001953125, -1082.625, 691.46820068359375, 4.485179901123046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Rift of Aln - Difficulty: 0)
(@CGUID+2, 6491, 2694, 15355, 15918, '0', 0, 0, 0, 0, -915.6805419921875, -1994.482666015625, 973.13519287109375, 1.452231884002685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: The Grudge Pit - Difficulty: 0)
(@CGUID+3, 6491, 2694, 15355, 15922, '0', 0, 0, 0, 0, -180.078125, -1757.5399169921875, 1046.0924072265625, 3.823839187622070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Amirdrassil Roots - Difficulty: 0)
(@CGUID+4, 6491, 2694, 15355, 15924, '0', 0, 0, 0, 0, 1069.232666015625, -1232.2117919921875, 1071.973876953125, 3.327277421951293945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Har\'kuai - Difficulty: 0)
(@CGUID+5, 6491, 2694, 15355, 15926, '0', 0, 0, 0, 0, 1019.31597900390625, -90.6180572509765625, 1211.1806640625, 4.397915363311767578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Fungal Cleft - Difficulty: 0)
(@CGUID+6, 6491, 2694, 15355, 16583, '0', 0, 0, 0, 0, 1294.6458740234375, 655.46527099609375, 1349.7320556640625, 2.389351844787597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Nai\'theren Grotto - Difficulty: 0)
(@CGUID+7, 6491, 2694, 15355, 15930, '0', 0, 0, 0, 0, -5.49652767181396484, 715.40106201171875, 1204.791015625, 4.418189525604248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Den of Echoes - Difficulty: 0)
(@CGUID+8, 6491, 2694, 15355, 15932, '0', 0, 0, 0, 0, -553.8211669921875, 1039.8646240234375, 1260.7052001953125, 3.541134357452392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Har\'alnor - Difficulty: 0)
(@CGUID+9, 6491, 2694, 15355, 15934, '0', 0, 0, 0, 0, -1346.77783203125, 1436.625, 1117.765625, 4.209364891052246093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: The Tangleknot - Difficulty: 0)
(@CGUID+10, 6491, 2694, 15355, 15931, '0', 0, 0, 0, 0, -1075.48095703125, 182.9930572509765625, 1173.6124267578125, 0.524458467960357666, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Fungara Village - Difficulty: 0)
(@CGUID+11, 6491, 2694, 15355, 16401, '0', 0, 0, 0, 0, -439.223968505859375, 120.9670181274414062, 1095.1474609375, 4.397915363311767578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Spirit Healer (Area: Ahl\'ua Wetland - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+11;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 15355, 'Harandar - Vale of Mists'),
(@GGUID+1, 15355, 'Harandar - Rift of Aln'),
(@GGUID+2, 15355, 'Harandar - The Grudge Pit'),
(@GGUID+3, 15355, 'Harandar - Amirdrassil Roots'),
(@GGUID+4, 15355, 'Harandar - Har\'kuai'),
(@GGUID+5, 15355, 'Harandar - Fungal Cleft'),
(@GGUID+6, 15355, 'Harandar - Nai\'theren Grotto'),
(@GGUID+7, 15355, 'Harandar - Den of Echoes'),
(@GGUID+8, 15355, 'Harandar - Har\'alnor'),
(@GGUID+9, 15355, 'Harandar - The Tangleknot'),
(@GGUID+10, 15355, 'Harandar - Fungara Village'),
(@GGUID+11, 15355, 'Harandar - Ahl\'ua Wetland');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+11;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2694, -24.097223, -1049.9358, 832.8518, 3.989635 / (2 * PI() / 360), 'Harandar - Vale of Mists - GY'),
(@GGUID+1, 2694, -601.48267, -1085.4635, 690.5884, 1.354963 / (2 * PI() / 360), 'Harandar - Rift of Aln - GY'),
(@GGUID+2, 2694, -914.8941, -1988.0521, 971.7842, 4.589202 / (2 * PI() / 360), 'Harandar - The Grudge Pit - GY'),
(@GGUID+3, 2694, -184.98438, -1762.408, 1044.9977, 0.746800 / (2 * PI() / 360), 'Harandar - Amirdrassil Roots - GY'),
(@GGUID+4, 2694, 1063.7743, -1233.2778, 1070.9078, 0.136646 / (2 * PI() / 360), 'Harandar - Har\'kuai - GY'),
(@GGUID+5, 2694, 1017.7344, -97.829865, 1210.1818, 1.312315 / (2 * PI() / 360), 'Harandar - Fungal Cleft - GY'),
(@GGUID+6, 2694, 1291.0469, 657.8559, 1349.154, 5.585413 / (2 * PI() / 360), 'Harandar - Nai\'theren Grotto - GY'),
(@GGUID+7, 2694, -7.326389, 710.4132, 1204.3298, 1.226624 / (2 * PI() / 360), 'Harandar - Den of Echoes - GY'),
(@GGUID+8, 2694, -558.434, 1037.8629, 1259.4742, 0.407112 / (2 * PI() / 360), 'Harandar - Har\'alnor - GY'),
(@GGUID+9, 2694, -1348.6198, 1431.4601, 1117.3082, 1.221099 / (2 * PI() / 360), 'Harandar - The Tangleknot - GY'),
(@GGUID+10, 2694, -1073.1858, 185.0625, 1172.3722, 3.833610 / (2 * PI() / 360), 'Harandar - Fungara Village - GY'),
(@GGUID+11, 2694, -440.5816, 116.30556, 1094.4996, 1.277388 / (2 * PI() / 360), 'Harandar - Ahl\'ua Wetland - GY');
