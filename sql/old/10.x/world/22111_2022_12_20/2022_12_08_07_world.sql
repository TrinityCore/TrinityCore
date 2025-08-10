SET @CGUID := 396589;
SET @OGUID := 249802;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 38, 38, '0', 0, 0, 0, 0, -5379, -2881.03466796875, 340.30322265625, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Loch Modan - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 38, 38, '0', 0, 0, 0, 0, -5387.28662109375, -2881.864501953125, 341.30841064453125, 2.530727386474609375, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Loch Modan - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 38, 38, '0', 0, 0, -5383.65478515625, -2878.850830078125, 340.96875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+1, 179968, 0, 38, 38, '0', 0, 0, -5381.73974609375, -2876.71533203125, 340.854156494140625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+2, 179968, 0, 38, 38, '0', 0, 0, -5382.69287109375, -2883.401123046875, 340.22027587890625, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+3, 179968, 0, 38, 38, '0', 0, 0, -5372.455078125, -2879.875, 340.016448974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+4, 179968, 0, 38, 38, '0', 0, 0, -5376.986328125, -2875.567626953125, 340.470489501953125, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+5, 179968, 0, 38, 38, '0', 0, 0, -5381.41845703125, -2885.239501953125, 340.40972900390625, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+6, 179968, 0, 38, 38, '0', 0, 0, -5374.89599609375, -2876.178955078125, 340.2100830078125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+7, 179968, 0, 38, 38, '0', 0, 0, -5375.20849609375, -2886.263916015625, 340.02777099609375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+8, 179968, 0, 38, 38, '0', 0, 0, -5377.85791015625, -2886.710205078125, 340.237152099609375, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+9, 179968, 0, 38, 38, '0', 0, 0, -5372.42529296875, -2882.23095703125, 339.984375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+10, 180353, 0, 38, 38, '0', 0, 0, -5382.955078125, -2877.623291015625, 340.921875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+11, 180353, 0, 38, 38, '0', 0, 0, -5376.408203125, -2886.45654296875, 340.11285400390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+12, 180353, 0, 38, 38, '0', 0, 0, -5375.98291015625, -2875.729248046875, 340.33160400390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+13, 180353, 0, 38, 38, '0', 0, 0, -5372.392578125, -2880.991455078125, 339.994781494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+14, 180353, 0, 38, 38, '0', 0, 0, -5382.31103515625, -2884.326416015625, 340.307098388671875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Loch Modan - Difficulty: 0)
(@OGUID+15, 195164, 0, 38, 38, '0', 0, 0, -5381.759765625, -2876.760009765625, 341.510009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+16, 195164, 0, 38, 38, '0', 0, 0, -5383.56005859375, -2878.89990234375, 341.615997314453125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+17, 195164, 0, 38, 38, '0', 0, 0, -5372.5498046875, -2879.89990234375, 340.67401123046875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+18, 195164, 0, 38, 38, '0', 0, 0, -5377.91015625, -2886.639892578125, 340.897003173828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+19, 195164, 0, 38, 38, '0', 0, 0, -5381.490234375, -2885.169921875, 341.05499267578125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+20, 195164, 0, 38, 38, '0', 0, 0, -5377.02978515625, -2875.659912109375, 341.123992919921875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+21, 195164, 0, 38, 38, '0', 0, 0, -5382.64013671875, -2883.360107421875, 340.87200927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+22, 195164, 0, 38, 38, '0', 0, 0, -5375.06982421875, -2886.139892578125, 340.67498779296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+23, 195164, 0, 38, 38, '0', 0, 0, -5372.56005859375, -2882.3798828125, 340.6400146484375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+24, 195164, 0, 38, 38, '0', 0, 0, -5375.02978515625, -2876.18994140625, 340.87200927734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Loch Modan - Difficulty: 0)
(@OGUID+25, 195664, 0, 38, 38, '0', 0, 0, -5379, -2881.030029296875, 340.220001220703125, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Loch Modan - Difficulty: 0)

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
