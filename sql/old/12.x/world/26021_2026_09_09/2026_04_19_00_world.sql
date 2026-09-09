SET @CGUID := 11000766;

SET @GGUID := 100120;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 0, 15947, 16193, '0', 0, 0, 0, 0, 4322.298828125, -5850.21533203125, 316.27362060546875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Revantusk Sedge - Difficulty: 0)
(@CGUID+1, 6491, 0, 15947, 16586, '0', 0, 0, 0, 0, 3785.23095703125, -6570.1162109375, 278.759765625, 6.261571884155273437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Torntusk Overlook - Difficulty: 0)
(@CGUID+2, 6491, 0, 15947, 16183, '0', 0, 0, 0, 0, 4016.4072265625, -7884.48974609375, 138.60888671875, 0.284975796937942504, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Amani\'Zar Village - Difficulty: 0)
(@CGUID+3, 6491, 0, 15947, 16197, '0', 0, 0, 0, 0, 4895.703125, -7722.64599609375, 25.20861625671386718, 4.344826221466064453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Leech Bog - Difficulty: 0)
(@CGUID+4, 6491, 0, 15947, 16418, '0', 0, 0, 0, 0, 6311.267578125, -7594.8994140625, 110.4436492919921875, 5.562023639678955078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Shadebasin Watch - Difficulty: 0)
(@CGUID+5, 6491, 0, 15947, 16203, '0', 0, 0, 0, 0, 6896.072265625, -7908.24462890625, 18.76618385314941406, 5.394932746887207031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384), -- Spirit Healer (Area: Camp Stonewash - Difficulty: 0)
(@CGUID+6, 6491, 0, 15947, 16202, '0', 0, 0, 0, 0, 6686.62158203125, -6895.94970703125, 228.8734283447265625, 3.161827325820922851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66384); -- Spirit Healer (Area: Witherbark Bluffs - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+6;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 15947, 'Zul\'Aman - Revantusk Sedge'),
(@GGUID+1, 15947, 'Zul\'Aman - Torntusk Overlook'),
(@GGUID+2, 15947, 'Zul\'Aman - Amani\'Zar Village'),
(@GGUID+3, 15947, 'Zul\'Aman - Leech Bog'),
(@GGUID+4, 15947, 'Zul\'Aman - Shadebasin Watch'),
(@GGUID+5, 15947, 'Zul\'Aman - Camp Stonewash'),
(@GGUID+6, 15947, 'Zul\'Aman - Witherbark Bluffs');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+6;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 0, 4327.963, -5850.1235, 315.71902, 3.139775 / (2 * PI() / 360), 'Zul\'Aman - Revantusk Sedge - GY'),
(@GGUID+1, 0, 3790.0547, -6569.9673, 278.44855, 3.119978 / (2 * PI() / 360), 'Zul\'Aman - Torntusk Overlook - GY'),
(@GGUID+2, 0, 4020.1667, -7882.382, 137.26036, 3.566720 / (2 * PI() / 360), 'Zul\'Aman - Amani\'Zar Village - GY'),
(@GGUID+3, 0, 4893.7847, -7728.405, 24.079035, 1.247167 / (2 * PI() / 360), 'Zul\'Aman - Leech Bog - GY'),
(@GGUID+4, 0, 6316.858, -7599.759, 109.01029, 2.394900 / (2 * PI() / 360), 'Zul\'Aman - Shadebasin Watch - GY'),
(@GGUID+5, 0, 6900.098, -7911.436, 17.159529, 2.420027 / (2 * PI() / 360), 'Zul\'Aman - Camp Stonewash - GY'),
(@GGUID+6, 0, 6680.788, -6894.6562, 228.4579, 6.124285 / (2 * PI() / 360), 'Zul\'Aman - Witherbark Bluffs - GY');
