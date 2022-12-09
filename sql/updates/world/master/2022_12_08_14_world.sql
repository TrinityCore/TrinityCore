SET @CGUID := 396606;
SET @OGUID := 250010;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 4, 1438, '0', 0, 0, 0, 0, -11021.099609375, -3441.179931640625, 65.196136474609375, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Nethergarde Keep - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 4, 1438, '0', 0, 0, 0, 0, -11013, -3443.419921875, 65.04773712158203125, 5.829399585723876953, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Nethergarde Keep - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 4, 1438, '0', 0, 0, -11014.5, -3440.02001953125, 65.06999969482421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+1, 179968, 0, 4, 1438, '0', 0, 0, -11014.5, -3442.3798828125, 64.99829864501953125, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+2, 179968, 0, 4, 1438, '0', 0, 0, -11017, -3436.330078125, 65.08679962158203125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+3, 179968, 0, 4, 1438, '0', 0, 0, -11019.099609375, -3435.719970703125, 65.09059906005859375, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+4, 179968, 0, 4, 1438, '0', 0, 0, -11017.2998046875, -3446.409912109375, 64.98259735107421875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+5, 179968, 0, 4, 1438, '0', 0, 0, -11023.5, -3445.389892578125, 65.13719940185546875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+6, 179968, 0, 4, 1438, '0', 0, 0, -11024.7998046875, -3443.550048828125, 65.2985992431640625, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+7, 179968, 0, 4, 1438, '0', 0, 0, -11025.7001953125, -3439, 65.5364990234375, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+8, 179968, 0, 4, 1438, '0', 0, 0, -11023.7998046875, -3436.860107421875, 65.41840362548828125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+9, 179968, 0, 4, 1438, '0', 0, 0, -11019.900390625, -3446.860107421875, 64.972198486328125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+10, 180353, 0, 4, 1438, '0', 0, 0, -11014.5, -3441.139892578125, 65.00209808349609375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+11, 180353, 0, 4, 1438, '0', 0, 0, -11025, -3437.77001953125, 65.5052032470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+12, 180353, 0, 4, 1438, '0', 0, 0, -11018.099609375, -3435.8798828125, 65.07810211181640625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+13, 180353, 0, 4, 1438, '0', 0, 0, -11018.5, -3446.60009765625, 64.9761962890625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+14, 180353, 0, 4, 1438, '0', 0, 0, -11024.400390625, -3444.469970703125, 65.2274017333984375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+15, 195164, 0, 4, 1438, '0', 0, 0, -11017.099609375, -3436.340087890625, 65.74700164794921875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+16, 195164, 0, 4, 1438, '0', 0, 0, -11014.599609375, -3440.050048828125, 65.7230987548828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+17, 195164, 0, 4, 1438, '0', 0, 0, -11023.599609375, -3445.320068359375, 65.8076019287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+18, 195164, 0, 4, 1438, '0', 0, 0, -11023.7998046875, -3436.909912109375, 66.0702972412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+19, 195164, 0, 4, 1438, '0', 0, 0, -11024.7001953125, -3443.510009765625, 65.94879913330078125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+20, 195164, 0, 4, 1438, '0', 0, 0, -11020, -3446.7900390625, 65.6240997314453125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+21, 195164, 0, 4, 1438, '0', 0, 0, -11025.599609375, -3439.0400390625, 66.1797027587890625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+22, 195164, 0, 4, 1438, '0', 0, 0, -11014.599609375, -3442.52001953125, 65.6605987548828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+23, 195164, 0, 4, 1438, '0', 0, 0, -11017.099609375, -3446.2900390625, 65.64679718017578125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+24, 195164, 0, 4, 1438, '0', 0, 0, -11019.099609375, -3435.81005859375, 65.743896484375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Nethergarde Keep - Difficulty: 0)
(@OGUID+25, 195664, 0, 4, 1438, '0', 0, 0, -11021.099609375, -3441.179931640625, 65.1110992431640625, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Nethergarde Keep - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0), 
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25);
