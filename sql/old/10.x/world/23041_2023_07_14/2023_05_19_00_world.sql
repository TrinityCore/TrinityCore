SET @CGUID := 1051938;
SET @WSLID := 100034;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2175, 10424, 10453, '0', 0, 0, 0, 0, -478.505218505859375, -2612.904541015625, 5.295620441436767578, 3.854274272918701171, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 49570), -- Spirit Healer (Area: Murloc Hideaway - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+1, 6491, 2175, 10424, 10452, '0', 0, 0, 0, 0, -237.892364501953125, -2533.05029296875, 27.45990371704101562, 3.953300237655639648, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 49570), -- Spirit Healer (Area: Abandoned Camp - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+2, 6491, 2175, 10424, 10530, '0', 0, 0, 0, 0, 353.3125, -2019.8055419921875, 128.1133575439453125, 2.39936065673828125, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 49570), -- Spirit Healer (Area: Darkmaul Citadel - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost; 10848 - Shroud of Death)
(@CGUID+3, 6491, 2175, 10424, 10528, '0', 0, 0, 0, 0, 380.86285400390625, -2469.350830078125, 131.0778656005859375, 3.077357292175292968, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 49570), -- Spirit Healer (Area: Harpy Roost - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 10848 - Shroud of Death)
(@CGUID+4, 6491, 2175, 10424, 10527, '0', 0, 0, 0, 0, 114.0989608764648437, -2258.46533203125, 97.72139739990234375, 5.696815967559814453, 120, 0, 0, 152441, 0, 0, 0, 0, 0, 49570); -- Spirit Healer (Area: Hrun's Barrow - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost; 10848 - Shroud of Death)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @WSLID+0 AND @WSLID+5;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(@WSLID+0, 10424, 0, 'Exile Reach (NPE) - Murloc Hideaway'),
(@WSLID+1, 10424, 0, 'Exile Reach (NPE) - Abandoned Camp'),
(@WSLID+2, 10424, 0, 'Exile Reach (NPE) - Darkmaul Plains'),
(@WSLID+3, 10424, 0, 'Exile Reach (NPE) - Darkmaul Citadel'),
(@WSLID+4, 10424, 0, 'Exile Reach (NPE) - Harpy Roost'),
(@WSLID+5, 10424, 0, 'Exile Reach (NPE) - Hruns Barrow');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WSLID+0 AND @WSLID+5;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WSLID+0, 2175, -486.2882, -2619.8682, 3.454493, 0.723377, 'Exile Reach (NPE) - Murloc Hideaway - GY'),
(@WSLID+1, 2175, -246.226, -2542.43, 27.2975, 0.827541, 'Exile Reach (NPE) - Abandoned Camp - GY'),
(@WSLID+2, 2175, 68.642365, -2411.6545, 95.67349, 0.714451, 'Exile Reach (NPE) - Darkmaul Plains - GY'),
(@WSLID+3, 2175, 339.64584, -2005.9601, 128.22858, 5.503711, 'Exile Reach (NPE) - Darkmaul Plains - GY'),
(@WSLID+4, 2175, 367.4045, -2468.4966, 131.25175, 6.214745, 'Exile Reach (NPE) - Harpy Roost - GY'),
(@WSLID+5, 2175, 126.362, -2267.02, 97.3479, 2.476121, 'Exile Reach (NPE) - Hruns Barrow - GY');
