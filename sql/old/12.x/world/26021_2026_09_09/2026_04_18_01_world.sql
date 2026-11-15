SET @CGUID := 11000755;

SET @GGUID := 100109;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 0, 15968, 16173, '0', 0, 0, 0, 0, 9374.9423828125, -3907.795166015625, 48.11637115478515625, 2.47507643699645996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Sunstrider Isle - Difficulty: 0)
(@CGUID+1, 6491, 0, 15968, 15993, '0', 0, 0, 0, 0, 7808.87060546875, -3426.479248046875, 61.69491195678710937, 3.483087539672851562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: West Sanctum - Difficulty: 0)
(@CGUID+2, 6491, 0, 15968, 15996, '0', 0, 0, 0, 0, 6958.5400390625, -3633.835205078125, 73.06569671630859375, 1.600736141204833984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Stillwhisper Pond - Difficulty: 0)
(@CGUID+3, 6491, 0, 15968, 16060, '0', 0, 0, 0, 0, 5930.875, -3486.4775390625, 9.671380043029785156, 1.591148734092712402, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Goldenmist Village - Difficulty: 0)
(@CGUID+4, 6491, 0, 15968, 16351, '0', 0, 0, 0, 0, 5366.66162109375, -4025.37158203125, 29.11220741271972656, 0.590485632419586181, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Sunsail Anchorage - Difficulty: 0)
(@CGUID+5, 6491, 0, 15968, 0, '0', 0, 0, 0, 0, 5221.38037109375, -5004.7900390625, 86.65317535400390625, 3.14746856689453125,  120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: 0 - Difficulty: 0)
(@CGUID+6, 6491, 0, 15968, 0, '0', 0, 0, 0, 0, 5911.12841796875, -5668.392578125, 217.1766815185546875, 3.399087190628051757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: 0 - Difficulty: 0)
(@CGUID+7, 6491, 0, 15968, 16001, '0', 0, 0, 0, 0, 6204.53369140625, -4335.73779296875, 59.7386322021484375, 3.227775335311889648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Fairbreeze Village - Difficulty: 0)
(@CGUID+8, 6491, 0, 15968, 0, '0', 0, 0, 0, 0, 7220.67626953125, -4342.4755859375, 119.2178878784179687, 3.954410076141357421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: 0 - Difficulty: 0)
(@CGUID+9, 6491, 0, 15968, 16067, '0', 0, 0, 0, 0, 7573.66943359375, -5171.62841796875, 103.8119125366210937, 2.84320998191833496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838), -- Spirit Healer (Area: Farstrider Hold - Difficulty: 0)
(@CGUID+10, 6491, 0, 15968, 16073, '0', 0, 0, 0, 0, 8003.0771484375, -4471.73779296875, 27.25476264953613281, 2.608248710632324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66838); -- Spirit Healer (Area: Dawnstar Spire - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+10;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 15968, 'Eversong Woods - Sunstrider Isle'),
(@GGUID+1, 15968, 'Eversong Woods - West Sanctum'),
(@GGUID+2, 15968, 'Eversong Woods - Stillwhisper Pond'),
(@GGUID+3, 15968, 'Eversong Woods - Goldenmist Village'),
(@GGUID+4, 15968, 'Eversong Woods - Sunsail Anchorage'),
(@GGUID+5, 15968, 'Eversong Woods - South'),
(@GGUID+6, 15968, 'Eversong Woods - Far South'),
(@GGUID+7, 15968, 'Eversong Woods - Fairbreeze Village'),
(@GGUID+8, 15968, 'Eversong Woods - Central'),
(@GGUID+9, 15968, 'Eversong Woods - Farstrider Hold'),
(@GGUID+10, 15968, 'Eversong Woods - Dawnstar Spire');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+10;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 0, 9376.21, -3909.01, 48.2837, 5.611652374267578125 / (2 * PI() / 360), 'Eversong Woods - Sunstrider Isle GY'),
(@GGUID+1, 0, 7803.98, -3428.5105, 59.9622, 0.460378527641296386 / (2 * PI() / 360), 'Eversong Woods - West Sanctum GY'),
(@GGUID+2, 0, 6958.78, -3624.55, 70.2722, 4.69767618179321289 / (2 * PI() / 360), 'Eversong Woods - Stillwhisper Pond GY'),
(@GGUID+3, 0, 5930.8003, -3482.7795, 9.1327, 4.771708011627197265 / (2 * PI() / 360), 'Eversong Woods - Goldenmist Village GY'),
(@GGUID+4, 0, 5368.39, -4024.44, 27.75, 3.656412363052368164 / (2 * PI() / 360), 'Eversong Woods - Sunsail Anchorage GY'),
(@GGUID+5, 0, 5216.33, -5005.27, 86.502, 0.041590671986341476 / (2 * PI() / 360), 'Eversong Woods - South GY'),
(@GGUID+6, 0, 5905.02, -5670.85, 215.54, 0.305099248886108398 / (2 * PI() / 360), 'Eversong Woods - Far South GY'),
(@GGUID+7, 0, 6197.66, -4335.91, 58.1032, 0.049214273691177368 / (2 * PI() / 360), 'Eversong Woods - Fairbreeze Village GY'),
(@GGUID+8, 0, 7217.1484, -4345.8438, 118.03519, 0.707789361476898193 / (2 * PI() / 360), 'Eversong Woods - Central GY'),
(@GGUID+9, 0, 7569.73, -5170.35, 102.914, 5.989184379577636718 / (2 * PI() / 360), 'Eversong Woods - Farstrider Hold GY'),
(@GGUID+10, 0, 7997.83, -4469.37, 26.8877, 5.802923202514648437 / (2 * PI() / 360), 'Eversong Woods - Dawnstar Spire GY');
