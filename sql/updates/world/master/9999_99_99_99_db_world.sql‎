SET @CGUID := 11000785;

SET @GGUID := 100139;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2771, 15458, 15458, '0', 0, 0, 0, 0, 1593.9947509765625, -1172.859375, -177.20916748046875, 3.897336483001708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Voidstorm - Difficulty: 0)
(@CGUID+1, 6491, 2771, 15458, 15951, '0', 0, 0, 0, 0, 912.73089599609375, -750.0625, -175.531387329101562, 3.714858770370483398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: The Howling Ridge - Difficulty: 0)
(@CGUID+2, 6491, 2771, 15458, 15458, '0', 0, 0, 0, 0, 1654.2899169921875, 500.239593505859375, -185.013275146484375, 3.932289361953735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Voidstorm - Difficulty: 0)
(@CGUID+3, 6491, 2771, 15458, 15949, '0', 0, 0, 0, 0, 1662.6771240234375, 1442.3680419921875, 0.66917884349822998, 4.633355140686035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: The Ingress - Difficulty: 0)
(@CGUID+4, 6491, 2771, 15458, 15950, '0', 0, 0, 0, 0, 541.91143798828125, 674.857666015625, -276.0716552734375, 3.932289361953735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Spirit Healer (Area: Locus Point - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+4;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 15458, 'Voidstorm - South'),
(@GGUID+1, 15458, 'Voidstorm - The Howling Ridge'),
(@GGUID+2, 15458, 'Voidstorm - Central'),
(@GGUID+3, 15458, 'Voidstorm - The Ingress'),
(@GGUID+4, 15458, 'Voidstorm - Locus Point');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+4;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2771, 1587.07, -1179.55, -177.972, 0.777699 / (2 * PI() / 360), 'Voidstorm - South - GY'),
(@GGUID+1, 2771, 905.922, -754.808, -177.127, 0.619766 / (2 * PI() / 360), 'Voidstorm - The Howling Ridge - GY'),
(@GGUID+2, 2771, 1647.85, 493.361, -186.453, 0.815430 / (2 * PI() / 360), 'Voidstorm - Central - GY'),
(@GGUID+3, 2771, 1662.43, 1427.18, -0.0721218, 1.542986 / (2 * PI() / 360), 'Voidstorm - The Ingress - GY'),
(@GGUID+4, 2771, 537.378, 669.594, -277.217, 0.857011 / (2 * PI() / 360), 'Voidstorm - Locus Point - GY');
