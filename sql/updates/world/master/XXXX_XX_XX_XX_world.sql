SET @CGUID := SET_VALUE_MANUALLY_HERE;

SET @GGUID := SET_VALUE_MANUALLY_HERE;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 169999, 2222, 10413, 10982, '0', 0, 0, 0, 0, -3201.12158203125, 5422.6787109375, 4238.765625, 3.592809438705444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Pridefall Hamlet - Difficulty: 0)
(@CGUID+1, 169999, 2222, 10413, 10979, '0', 0, 0, 0, 0, -2696.265625, 5880.171875, 4099.6884765625, 6.263263702392578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Darkhaven - Difficulty: 0)
(@CGUID+2, 169999, 2222, 10413, 10995, '0', 0, 0, 0, 0, -2112.979248046875, 5190.88037109375, 4126.58251953125, 6.108309745788574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Halls of Atonement - Difficulty: 0)
(@CGUID+3, 169999, 2222, 10413, 10998, '0', 0, 0, 0, 0, -1754.5504150390625, 5312.02978515625, 4047.477783203125, 3.607606410980224609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Crypt of the Forgotten - Difficulty: 0)
(@CGUID+4, 169999, 2222, 10413, 10990, '0', 0, 0, 0, 0, -1491.6285400390625, 6444.55908203125, 4227.8115234375, 1.57718360424041748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Menagerie of the Master - Difficulty: 0)
(@CGUID+5, 169999, 2222, 10413, 10989, '0', 0, 0, 0, 0, -1174.07470703125, 7422.611328125, 4203.197265625, 2.384433507919311523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Dominance Keep - Difficulty: 0)
(@CGUID+6, 169999, 2222, 10413, 10986, '0', 0, 0, 0, 0, -1959.1024169921875, 7710.12158203125, 4269.76318359375, 3.084634065628051757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Sinfall - Difficulty: 0)
(@CGUID+7, 169999, 2222, 10413, 10985, '0', 0, 0, 0, 0, -2827.625, 7403.02197265625, 4060.321533203125, 3.089113473892211914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Ember Ward - Difficulty: 0)
(@CGUID+8, 169999, 2222, 10413, 11006, '0', 0, 0, 0, 0, -3073.267333984375, 6987.31103515625, 4032.755615234375, 3.071916818618774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Spirit Obelisk (Area: Dredhollow - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+8;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 10413, 'Revendreth - Pridefall Hamlet'),
(@GGUID+1, 10413, 'Revendreth - Darkhaven'),
(@GGUID+2, 10413, 'Revendreth - Halls of Atonement'),
(@GGUID+3, 10413, 'Revendreth - Crypt of the Forgotten'),
(@GGUID+4, 10413, 'Revendreth - Menagerie of the Master'),
(@GGUID+5, 10413, 'Revendreth - Dominance Keep'),
(@GGUID+6, 10413, 'Revendreth - Sinfall'),
(@GGUID+7, 10413, 'Revendreth - Ember Ward'),
(@GGUID+8, 10413, 'Revendreth - Dredhollow');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+8;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2222, -3207.7048, 5419.117, 4238.563, 0.495892852544784545 / (2 * PI() / 360), 'Revendreth - Pridefall Hamlet - GY'),
(@GGUID+1, 2222, -2690.8057, 5879.607, 4099.5923, 3.038470745086669921 / (2 * PI() / 360), 'Revendreth - Darkhaven - GY'),
(@GGUID+2, 2222, -2116.88, 5190.88, 4126.66, 0, 'Revendreth - Halls of Atonement - GY'),
(@GGUID+3, 2222, -1760.0642, 5309.6797, 4047.3025, 0.37753450870513916 / (2 * PI() / 360), 'Revendreth - Crypt of the Forgotten - GY'),
(@GGUID+4, 2222, -1491.5192, 6451.0728, 4227.1025, 4.699847698211669921 / (2 * PI() / 360), 'Revendreth - Menagerie of the Master - GY'),
(@GGUID+5, 2222, -1180.1077, 7427.6807, 4203.118, 5.50079202651977539 / (2 * PI() / 360), 'Revendreth - Dominance Keep - GY'),
(@GGUID+6, 2222, -1966.6442, 7709.897, 4268.9478, 6.25460052490234375 / (2 * PI() / 360), 'Revendreth - Sinfall - GY'),
(@GGUID+7, 2222, -2824.0122, 7405.4697, 4060.4253, 6.107666015625 / (2 * PI() / 360), 'Revendreth - Ember Ward - GY'),
(@GGUID+8, 2222, -3068.17, 6986.67, 4032.46, 3.056385517120361328 / (2 * PI() / 360), 'Revendreth - Dredhollow - GY');