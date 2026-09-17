SET @CGUID := 8000876;

SET @GGUID := 100150;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2601, 14838, 15032, '0', 0, 0, 0, 0, 2288.421875, -1979.5086669921875, 272.81451416015625, 1.357499003410339355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Shadowmire)
(@CGUID+1, 6491, 2601, 14838, 14924, '0', 0, 0, 0, 0, 2642.052001953125, -1116.376708984375, -138.551437377929687, 3.848736047744750976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Rumshackle)
(@CGUID+2, 6491, 2601, 14838, 14854, '0', 0, 0, 0, 0, 3466.694580078125, -608.40277099609375, 55.83907699584960937, 1.89326941967010498, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Hillhelm Stead)
(@CGUID+3, 6491, 2601, 14838, 14838, '0', 0, 0, 0, 0, 2916.520751953125, -7.40625, 106.33660888671875, 1.595125317573547363, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Hallowfall - East Coast)
(@CGUID+4, 6491, 2601, 14838, 15337, '0', 0, 0, 0, 0, 2851.013916015625, 1201.779541015625, 516.1177978515625, 4.81681680679321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Priory of the Sacred Flame)
(@CGUID+5, 6491, 2601, 14838, 15337, '0', 0, 0, 0, 0, 2798.9296875, 1267.24658203125, 545.48797607421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Priory of the Sacred Flame - Upper)
(@CGUID+6, 6491, 2601, 14838, 14917, '0', 0, 0, 0, 0, 2023.8629150390625, 1068.4896240234375, 94.00238800048828125, 2.90085458755493164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Mereldar)
(@CGUID+7, 6491, 2601, 14838, 14923, '0', 0, 0, 0, 0, 2069.079833984375, -525.20660400390625, -254.526641845703125, 1.434691190719604492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Fangs)
(@CGUID+8, 6491, 2601, 14838, 15176, '0', 0, 0, 0, 0, 1586.8211669921875, -982.54864501953125, -132.1517333984375, 3.015602827072143554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Sanguine Grasps)
(@CGUID+9, 6491, 2601, 14838, 14930, '0', 0, 0, 0, 0, 1653.859375, -257.442718505859375, -122.723045349121093, 6.065942764282226562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Tenir\'s Ascent)
(@CGUID+10, 6491, 2601, 14838, 14838, '0', 0, 0, 0, 0, 718.44793701171875, 1388.6822509765625, -181.150299072265625, 0.51455467939376831, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186); -- Spirit Healer (Area: Hallowfall - West)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+10;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 14838, 'Hallowfall - Shadowmire'),
(@GGUID+1, 14838, 'Hallowfall - Rumshackle'),
(@GGUID+2, 14838, 'Hallowfall - Hillhelm Stead'),
(@GGUID+3, 14838, 'Hallowfall - East Coast'),
(@GGUID+4, 14838, 'Hallowfall - Priory of the Sacred Flame'),
(@GGUID+5, 14838, 'Hallowfall - Priory of the Sacred Flame Upper'),
(@GGUID+6, 14838, 'Hallowfall - Mereldar'),
(@GGUID+7, 14838, 'Hallowfall - The Fangs'),
(@GGUID+8, 14838, 'Hallowfall - Sanguine Grasps'),
(@GGUID+9, 14838, 'Hallowfall - Tenir\'s Ascent'),
(@GGUID+10, 14838, 'Hallowfall - West');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+10;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2601, 2289.6875, -1973.8455, 270.75815, 4.487062 / (2 * PI() / 360), 'Hallowfall - Shadowmire - GY'),
(@GGUID+1, 2601, 2637.29, -1121.158, -140.15381, 0.787905 / (2 * PI() / 360), 'Hallowfall - Rumshackle - GY'),
(@GGUID+2, 2601, 3464.9653, -605.033, 55.07029, 2.141394 / (2 * PI() / 360), 'Hallowfall - Hillhelm Stead - GY'),
(@GGUID+3, 2601, 2915.087, 1.0503472, 106.47424, 4.869191 / (2 * PI() / 360), 'Hallowfall - East Coast - GY'),
(@GGUID+4, 2601, 2852.356, 1194.0486, 515.2062, 1.729972 / (2 * PI() / 360), 'Hallowfall - Priory of the Sacred Flame - GY'),
(@GGUID+5, 2601, 2798.9296875, 1267.24658203125, 545.48797607421875, 0, 'Hallowfall - Priory Upper - GY'),
(@GGUID+6, 2601, 2016.0452, 1071.1598, 93.9256, 5.943256 / (2 * PI() / 360), 'Hallowfall - Mereldar - GY'),
(@GGUID+7, 2601, 2067.92, -525.82, -254.454, 1.268409 / (2 * PI() / 360), 'Hallowfall - The Fangs - GY'),
(@GGUID+8, 2601, 1580.0226, -981.17365, -132.72205, 6.126051 / (2 * PI() / 360), 'Hallowfall - Sanguine Grasps - GY'),
(@GGUID+9, 2601, 1659.4618, -258.21527, -124.36241, 3.024867 / (2 * PI() / 360), 'Hallowfall - Tenir\'s Ascent - GY'),
(@GGUID+10, 2601, 722.84894, 1391.1702, -182.6997, 3.599679 / (2 * PI() / 360), 'Hallowfall - West - GY');
