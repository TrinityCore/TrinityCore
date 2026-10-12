SET @CGUID := 10006964;

SET @GGUID := 100144;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2738, 15336, 15782, '0', 0, 0, 0, 0, -127.284721374511718, 922.51910400390625, 247.049285888671875, 4.182866096496582031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Spirit Healer (Area: Hosaas' Rest - Difficulty: 0)
(@CGUID+1, 6491, 2738, 15336, 15806, '0', 0, 0, 0, 0, 289.092010498046875, 535.546875, 118.9519882202148437, 2.619654178619384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Spirit Healer (Area: Serrated Peaks - Difficulty: 0)
(@CGUID+2, 6491, 2738, 15336, 15826, '0', 0, 0, 0, 0, 302.236114501953125, -213.835067749023437, -72.7183761596679687, 4.836814403533935546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Spirit Healer (Area: Lunnall River - Difficulty: 0)
(@CGUID+3, 6491, 2738, 15336, 15801, '0', 0, 0, 0, 0, 711.0867919921875, -1051.6978759765625, 25.51560401916503906, 0.355405241250991821, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Spirit Healer (Area: The Merciless Wastes - Difficulty: 0)
(@CGUID+4, 6491, 2738, 15336, 16002, '0', 0, 0, 0, 0, 1981.5364990234375, 116.739593505859375, -40.8567237854003906, 2.341418981552124023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Spirit Healer (Area: Khiyed Ruins - Difficulty: 0)
(@CGUID+5, 6491, 2738, 15336, 15805, '0', 0, 0, 0, 0, 1762.5208740234375, 1626.7222900390625, -289.472991943359375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876); -- Spirit Healer (Area: Shadow Point - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+5;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 15336, 'K\'aresh - Hosaas\' Rest'),
(@GGUID+1, 15336, 'K\'aresh - Serrated Peaks'),
(@GGUID+2, 15336, 'K\'aresh - Lunnall River'),
(@GGUID+3, 15336, 'K\'aresh - The Merciless Wastes'),
(@GGUID+4, 15336, 'K\'aresh - Khiyed Ruins'),
(@GGUID+5, 15336, 'K\'aresh - Shadow Point');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+5;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2738, -130.169, 917.926, 244.204, 1.029027 / (2 * PI() / 360), 'K\'aresh - Hosaas\' Rest - GY'),
(@GGUID+1, 2738, 281.335, 541.286, 116.553, 5.610727 / (2 * PI() / 360), 'K\'aresh - Serrated Peaks - GY'),
(@GGUID+2, 2738, 302.68576, -218.74654, -74.78781, 1.730694 / (2 * PI() / 360), 'K\'aresh - Lunnall River - GY'),
(@GGUID+3, 2738, 717.173, -1047.97, 22.5864, 3.664336 / (2 * PI() / 360), 'K\'aresh - The Merciless Wastes - GY'),
(@GGUID+4, 2738, 1975.54, 121.236, -43.8025, 5.638461 / (2 * PI() / 360), 'K\'aresh - Khiyed Ruins - GY'),
(@GGUID+5, 2738, 1772.66, 1625.98, -293.564, 3.047083 / (2 * PI() / 360), 'K\'aresh - Shadow Point - GY');
