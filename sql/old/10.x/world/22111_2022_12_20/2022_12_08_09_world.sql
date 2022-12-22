SET @CGUID := 396593;
SET @OGUID := 249854;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Morgan's Vigil
(@CGUID+0, 32823, 0, 46, 2418, '0', 0, 0, 0, 0, -8394.126953125, -2780.55029296875, 194.885406494140625, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Morgan's Vigil - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 46, 2418, '0', 0, 0, 0, 0, -8388.9111328125, -2774.779541015625, 194.25384521484375, 0.733038306236267089, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table Hostess (Area: Morgan's Vigil - Difficulty: 0)
-- Flame Crest
(@CGUID+2, 32823, 0, 46, 250, '0', 0, 0, 0, 0, -7650.32666015625, -2140.34716796875, 135.62152099609375, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Ruins of Thaurissan - Difficulty: 0) (Auras: )
(@CGUID+3, 34654, 0, 46, 250, '0', 0, 0, 0, 0, -7642.24658203125, -2139.220458984375, 135.622955322265625, 0.03490658476948738, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Ruins of Thaurissan - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Morgan's Vigil
(@OGUID+0, 179968, 0, 46, 2418, '0', 0, 0, -8390.0224609375, -2775.694580078125, 194.4027862548828125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+1, 179968, 0, 46, 2418, '0', 0, 0, -8398.78125, -2778.366455078125, 194.80035400390625, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+2, 179968, 0, 46, 2418, '0', 0, 0, -8396.8662109375, -2776.23095703125, 194.8125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+3, 179968, 0, 46, 2418, '0', 0, 0, -8392.11328125, -2775.083251953125, 194.5355072021484375, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+4, 179968, 0, 46, 2418, '0', 0, 0, -8392.984375, -2786.225830078125, 194.782989501953125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+5, 179968, 0, 46, 2418, '0', 0, 0, -8396.546875, -2784.755126953125, 194.796875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+6, 179968, 0, 46, 2418, '0', 0, 0, -8390.3349609375, -2785.779541015625, 194.888885498046875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+7, 179968, 0, 46, 2418, '0', 0, 0, -8387.58203125, -2779.390625, 194.6215362548828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+8, 179968, 0, 46, 2418, '0', 0, 0, -8397.8193359375, -2782.916748046875, 194.796875, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+9, 179968, 0, 46, 2418, '0', 0, 0, -8387.5517578125, -2781.74658203125, 194.81597900390625, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+10, 180353, 0, 46, 2418, '0', 0, 0, -8391.109375, -2775.244873046875, 194.4618072509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+11, 180353, 0, 46, 2418, '0', 0, 0, -8398.08203125, -2777.138916015625, 194.796875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+12, 180353, 0, 46, 2418, '0', 0, 0, -8391.53515625, -2785.97216796875, 194.8333282470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+13, 180353, 0, 46, 2418, '0', 0, 0, -8387.51953125, -2780.507080078125, 194.7100677490234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+14, 180353, 0, 46, 2418, '0', 0, 0, -8397.4375, -2783.842041015625, 194.796875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+15, 195164, 0, 46, 2418, '0', 0, 0, -8392.1533203125, -2775.178955078125, 195.241729736328125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+16, 195164, 0, 46, 2418, '0', 0, 0, -8387.671875, -2779.41845703125, 195.317657470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+17, 195164, 0, 46, 2418, '0', 0, 0, -8390.1943359375, -2785.65966796875, 195.5897979736328125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+18, 195164, 0, 46, 2418, '0', 0, 0, -8396.8857421875, -2776.276123046875, 195.50299072265625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+19, 195164, 0, 46, 2418, '0', 0, 0, -8396.6142578125, -2784.68408203125, 195.48736572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+20, 195164, 0, 46, 2418, '0', 0, 0, -8393.0380859375, -2786.154541015625, 195.4752044677734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+21, 195164, 0, 46, 2418, '0', 0, 0, -8390.16015625, -2775.70654296875, 195.107666015625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+22, 195164, 0, 46, 2418, '0', 0, 0, -8397.76953125, -2782.873291015625, 195.48736572265625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+23, 195164, 0, 46, 2418, '0', 0, 0, -8398.6845703125, -2778.411376953125, 195.4908294677734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+24, 195164, 0, 46, 2418, '0', 0, 0, -8387.689453125, -2781.890625, 195.5272979736328125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Morgan's Vigil - Difficulty: 0)
(@OGUID+25, 195664, 0, 46, 2418, '0', 0, 0, -8394.1298828125, -2780.550048828125, 194.802001953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- [DND] Collision Thanksgiving Table Size (Area: Morgan's Vigil - Difficulty: 0)
-- Flame Crest
(@OGUID+26, 179968, 0, 46, 250, '0', 0, 0, -7648.31103515625, -2134.87841796875, 135.5035247802734375, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+27, 179968, 0, 46, 250, '0', 0, 0, -7646.22216796875, -2135.48779296875, 135.5280609130859375, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+28, 179968, 0, 46, 250, '0', 0, 0, -7643.78125, -2139.185791015625, 135.5396270751953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+29, 179968, 0, 46, 250, '0', 0, 0, -7646.53466796875, -2145.57470703125, 135.482635498046875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+30, 179968, 0, 46, 250, '0', 0, 0, -7653.06591796875, -2136.026123046875, 135.4325714111328125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+31, 179968, 0, 46, 250, '0', 0, 0, -7649.18603515625, -2146.01904296875, 135.5121612548828125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+32, 179968, 0, 46, 250, '0', 0, 0, -7654.017578125, -2142.7119140625, 135.5396270751953125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+33, 179968, 0, 46, 250, '0', 0, 0, -7652.74658203125, -2144.55029296875, 135.5391845703125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+34, 179968, 0, 46, 250, '0', 0, 0, -7654.98095703125, -2138.15966796875, 135.5290985107421875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+35, 179968, 0, 46, 250, '0', 0, 0, -7643.75341796875, -2141.541748046875, 135.5396270751953125, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+36, 180353, 0, 46, 250, '0', 0, 0, -7647.30908203125, -2135.0400390625, 135.532623291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+37, 180353, 0, 46, 250, '0', 0, 0, -7643.71728515625, -2140.30029296875, 135.5396270751953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+38, 180353, 0, 46, 250, '0', 0, 0, -7647.734375, -2145.76904296875, 135.4951019287109375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+39, 180353, 0, 46, 250, '0', 0, 0, -7654.28125, -2136.93408203125, 135.4705047607421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+40, 180353, 0, 46, 250, '0', 0, 0, -7653.63720703125, -2143.63720703125, 135.5396270751953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+41, 195164, 0, 46, 250, '0', 0, 0, -7643.87353515625, -2139.213623046875, 136.2120208740234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+42, 195164, 0, 46, 250, '0', 0, 0, -7646.359375, -2135.50341796875, 136.2015380859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+43, 195164, 0, 46, 250, '0', 0, 0, -7646.39404296875, -2145.45654296875, 136.155029296875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+44, 195164, 0, 46, 250, '0', 0, 0, -7649.236328125, -2145.94970703125, 136.188018798828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+45, 195164, 0, 46, 250, '0', 0, 0, -7654.8837890625, -2138.20654296875, 136.203643798828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+46, 195164, 0, 46, 250, '0', 0, 0, -7652.814453125, -2144.479248046875, 136.2120208740234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+47, 195164, 0, 46, 250, '0', 0, 0, -7648.3525390625, -2134.97216796875, 136.178863525390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+48, 195164, 0, 46, 250, '0', 0, 0, -7653.0849609375, -2136.0712890625, 136.1085052490234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+49, 195164, 0, 46, 250, '0', 0, 0, -7643.890625, -2141.685791015625, 136.211944580078125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+50, 195164, 0, 46, 250, '0', 0, 0, -7653.96875, -2142.66845703125, 136.2120208740234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Ruins of Thaurissan - Difficulty: 0)
(@OGUID+51, 195664, 0, 46, 250, '0', 0, 0, -7650.330078125, -2140.35009765625, 135.537994384765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Ruins of Thaurissan - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0), 
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2),
(@EVENT, @CGUID+3);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+51;
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
(@EVENT, @OGUID+25),
(@EVENT, @OGUID+26),
(@EVENT, @OGUID+27),
(@EVENT, @OGUID+28),
(@EVENT, @OGUID+29),
(@EVENT, @OGUID+30),
(@EVENT, @OGUID+31),
(@EVENT, @OGUID+32),
(@EVENT, @OGUID+33),
(@EVENT, @OGUID+34),
(@EVENT, @OGUID+35),
(@EVENT, @OGUID+36),
(@EVENT, @OGUID+37),
(@EVENT, @OGUID+38),
(@EVENT, @OGUID+39),
(@EVENT, @OGUID+40),
(@EVENT, @OGUID+41),
(@EVENT, @OGUID+42),
(@EVENT, @OGUID+43),
(@EVENT, @OGUID+44),
(@EVENT, @OGUID+45),
(@EVENT, @OGUID+46),
(@EVENT, @OGUID+47),
(@EVENT, @OGUID+48),
(@EVENT, @OGUID+49),
(@EVENT, @OGUID+50),
(@EVENT, @OGUID+51);
