SET @CGUID := 396597;
SET @OGUID := 249906;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 44, 69, '0', 0, 0, 0, 0, -9305.8095703125, -2329.3798828125, 61.32783126831054687, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Lakeshire - Difficulty: 0)
(@CGUID+1, 34653, 0, 44, 69, '0', 0, 0, 0, 0, -9301.2099609375, -2322.8701171875, 61.32783126831054687, 0.890117883682250976, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Lakeshire - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 44, 69, '0', 0, 0, -9299.240234375, -2330.570068359375, 61.24449920654296875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+1, 179968, 0, 44, 69, '0', 0, 0, -9301.7099609375, -2324.52001953125, 61.24449920654296875, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+2, 179968, 0, 44, 69, '0', 0, 0, -9299.26953125, -2328.219970703125, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+3, 179968, 0, 44, 69, '0', 0, 0, -9310.4697265625, -2327.18994140625, 61.24449920654296875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+4, 179968, 0, 44, 69, '0', 0, 0, -9302.01953125, -2334.610107421875, 61.24449920654296875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+5, 179968, 0, 44, 69, '0', 0, 0, -9308.5498046875, -2325.06005859375, 61.24449920654296875, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+6, 179968, 0, 44, 69, '0', 0, 0, -9308.23046875, -2333.580078125, 61.24449920654296875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+7, 179968, 0, 44, 69, '0', 0, 0, -9304.669921875, -2335.050048828125, 61.24449920654296875, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+8, 179968, 0, 44, 69, '0', 0, 0, -9303.7998046875, -2323.909912109375, 61.24449920654296875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+9, 179968, 0, 44, 69, '0', 0, 0, -9309.5, -2331.739990234375, 61.24449920654296875, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+10, 180353, 0, 44, 69, '0', 0, 0, -9299.2099609375, -2329.340087890625, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+11, 180353, 0, 44, 69, '0', 0, 0, -9309.76953125, -2325.969970703125, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+12, 180353, 0, 44, 69, '0', 0, 0, -9309.1201171875, -2332.669921875, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+13, 180353, 0, 44, 69, '0', 0, 0, -9302.7900390625, -2324.070068359375, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+14, 180353, 0, 44, 69, '0', 0, 0, -9303.2197265625, -2334.800048828125, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lakeshire - Difficulty: 0)
(@OGUID+15, 195164, 0, 44, 69, '0', 0, 0, -9299.3603515625, -2328.25, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+16, 195164, 0, 44, 69, '0', 0, 0, -9299.3798828125, -2330.719970703125, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+17, 195164, 0, 44, 69, '0', 0, 0, -9303.83984375, -2324.010009765625, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+18, 195164, 0, 44, 69, '0', 0, 0, -9308.5703125, -2325.10009765625, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+19, 195164, 0, 44, 69, '0', 0, 0, -9309.4599609375, -2331.699951171875, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+20, 195164, 0, 44, 69, '0', 0, 0, -9301.8798828125, -2334.489990234375, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+21, 195164, 0, 44, 69, '0', 0, 0, -9304.7197265625, -2334.97998046875, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+22, 195164, 0, 44, 69, '0', 0, 0, -9308.2998046875, -2333.510009765625, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+23, 195164, 0, 44, 69, '0', 0, 0, -9310.3701171875, -2327.239990234375, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+24, 195164, 0, 44, 69, '0', 0, 0, -9301.849609375, -2324.530029296875, 61.96820068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lakeshire - Difficulty: 0)
(@OGUID+25, 195664, 0, 44, 69, '0', 0, 0, -9305.8095703125, -2329.3798828125, 61.24449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Lakeshire - Difficulty: 0)

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
