SET @CGUID := SET_VALUE_MANUALLY_HERE;

SET @GGUID := SET_VALUE_MANUALLY_HERE;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 169999, 2222, 11510, 0, '0', 0, 0, 0, 0, -6051.40966796875, -381.8194580078125, 5609.87451171875, 0.490071713924407958, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Ardenweald - South - Difficulty: 0)
(@CGUID+1, 169999, 2222, 11510, 13237, '0', 0, 0, 0, 0, -6803.2744140625, 58.17708206176757812, 5457.33740234375, 0.071523986756801605, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Starlit Overlook - Difficulty: 0)
(@CGUID+2, 169999, 2222, 11510, 11512, '0', 0, 0, 0, 0, -6653.85595703125, 866.08856201171875, 5637.7763671875, 5.734578132629394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Shrouded Mire - Difficulty: 0)
(@CGUID+3, 169999, 2222, 11510, 11519, '0', 0, 0, 0, 0, -6188.8525390625, 1609.296875, 5582.57421875, 0.933535933494567871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Dreamsong Fenn - Difficulty: 0)
(@CGUID+4, 169999, 2222, 11510, 11531, '0', 0, 0, 0, 0, -6917.6494140625, 1659.4879150390625, 5584.33642578125, 4.453207015991210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Hibernal Hollow - Difficulty: 0)
(@CGUID+5, 169999, 2222, 11510, 11515, '0', 0, 0, 0, 0, -7602.7900390625, 654.68231201171875, 5543.1611328125, 2.236736774444580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Spirit Obelisk (Area: Tirna Vaal - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+5;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 11510, 'Ardenweald - South'),
(@GGUID+1, 11510, 'Ardenweald - Starlit Overlook'),
(@GGUID+2, 11510, 'Ardenweald - Shrouded Mire'),
(@GGUID+3, 11510, 'Ardenweald - Dreamsong Fenn'),
(@GGUID+4, 11510, 'Ardenweald - Hibernal Hollow'),
(@GGUID+5, 11510, 'Ardenweald - Tirna Vaal');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+5;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2222, -6042.172, -376.44446, 5607.861, 3.566833734512329101 / (2 * PI() / 360), 'Ardenweald - South - GY'),
(@GGUID+1, 2222, -6814.0312, 55.555557, 5456.5474, 0.296855121850967407 / (2 * PI() / 360), 'Ardenweald - Starlit Overlook - GY'),
(@GGUID+2, 2222, -6665.924, 872.05206, 5637.428, 5.86382913589477539 / (2 * PI() / 360), 'Ardenweald - Shrouded Mire - GY'),
(@GGUID+3, 2222, -6182.2656, 1616.4966, 5581.9673, 3.90133523941040039 / (2 * PI() / 360), 'Ardenweald - Dreamsong Fenn - GY'),
(@GGUID+4, 2222, -6917.936, 1672.6476, 5583.316, 4.999139785766601562 / (2 * PI() / 360), 'Ardenweald - Hibernal Hollow - GY'),
(@GGUID+5, 2222, -7596.3613, 648.01215, 5542.1313, 2.392802715301513671 / (2 * PI() / 360), 'Ardenweald - Tirna Vaal - GY');