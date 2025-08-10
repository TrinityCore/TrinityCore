SET @CGUID := 396555;
SET @OGUID := 249406;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Theramore Isle
(@CGUID+0, 32823, 1, 15, 513, '0', 0, 0, 0, 0, -3811.5625, -4544.955078125, 10.61968326568603515, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Theramore Isle - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 1, 15, 513, '0', 0, 0, 0, 0, -3809.473876953125, -4537.19970703125, 10.38020801544189453, 2.513274192810058593, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table Hostess (Area: Theramore Isle - Difficulty: 0)
-- Brackenwall Village
(@CGUID+2, 32823, 1, 15, 496, '0', 0, 0, 0, 0, -3137.666748046875, -2848.48095703125, 34.66145706176757812, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Brackenwall Village - Difficulty: 0) (Auras: )
(@CGUID+3, 34654, 1, 15, 496, '0', 0, 0, 0, 0, -3133.8125, -2842.036376953125, 34.3038177490234375, 1.239183783531188964, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Brackenwall Village - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Theramore Isle
(@OGUID+0, 179968, 1, 15, 513, '0', 0, 0, -3815.897705078125, -4542.44091796875, 10.125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+1, 179968, 1, 15, 513, '0', 0, 0, -3809.333251953125, -4539.49658203125, 10.5463113784790039, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+2, 179968, 1, 15, 513, '0', 0, 0, -3814.817626953125, -4541.09716796875, 10.14099311828613281, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+3, 179968, 1, 15, 513, '0', 0, 0, -3815.25341796875, -4547.3193359375, 10.24652767181396484, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+4, 179968, 1, 15, 513, '0', 0, 0, -3807.803955078125, -4539.90283203125, 10.66493034362792968, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+5, 179968, 1, 15, 513, '0', 0, 0, -3808.16845703125, -4550.01025390625, 10.26839160919189453, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+6, 179968, 1, 15, 513, '0', 0, 0, -3814.20654296875, -4548.8193359375, 10.18003559112548828, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+7, 179968, 1, 15, 513, '0', 0, 0, -3805.34033203125, -4544.15283203125, 10.64409732818603515, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+8, 179968, 1, 15, 513, '0', 0, 0, -3805.505126953125, -4545.71533203125, 10.55902767181396484, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+9, 179968, 1, 15, 513, '0', 0, 0, -3809.80908203125, -4550.49658203125, 10.13715267181396484, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+10, 180353, 1, 15, 513, '0', 0, 0, -3808.545166015625, -4539.64599609375, 10.60784053802490234, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+11, 180353, 1, 15, 513, '0', 0, 0, -3815.569580078125, -4541.60400390625, 10.10506725311279296, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+12, 180353, 1, 15, 513, '0', 0, 0, -3805.3525390625, -4544.9375, 10.59895801544189453, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+13, 180353, 1, 15, 513, '0', 0, 0, -3814.875, -4548.2431640625, 10.21354198455810546, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+14, 180353, 1, 15, 513, '0', 0, 0, -3808.97216796875, -4550.375, 10.1875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Theramore Isle - Difficulty: 0)
(@OGUID+15, 195164, 1, 15, 513, '0', 0, 0, -3814.84033203125, -4541.142578125, 10.85353946685791015, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+16, 195164, 1, 15, 513, '0', 0, 0, -3805.64404296875, -4545.85791015625, 11.26132583618164062, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+17, 195164, 1, 15, 513, '0', 0, 0, -3815.204833984375, -4547.2744140625, 10.96383857727050781, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+18, 195164, 1, 15, 513, '0', 0, 0, -3808.029541015625, -4549.892578125, 10.98400688171386718, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+19, 195164, 1, 15, 513, '0', 0, 0, -3815.80029296875, -4542.486328125, 10.85578346252441406, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+20, 195164, 1, 15, 513, '0', 0, 0, -3807.866455078125, -4539.88525390625, 11.36843109130859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+21, 195164, 1, 15, 513, '0', 0, 0, -3814.276123046875, -4548.75, 10.89290046691894531, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+22, 195164, 1, 15, 513, '0', 0, 0, -3809.857666015625, -4550.42724609375, 10.85578346252441406, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+23, 195164, 1, 15, 513, '0', 0, 0, -3809.375, -4539.59033203125, 11.25806331634521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+24, 195164, 1, 15, 513, '0', 0, 0, -3805.43408203125, -4544.1806640625, 11.35239505767822265, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Theramore Isle - Difficulty: 0)
(@OGUID+25, 195664, 1, 15, 513, '0', 0, 0, -3811.56005859375, -4544.9599609375, 10.53639984130859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- [DND] Collision Thanksgiving Table Size (Area: Theramore Isle - Difficulty: 0)
-- Brackenwall Village
(@OGUID+26, 179968, 1, 15, 496, '0', 0, 0, -3133.907958984375, -2843.428955078125, 34.3305816650390625, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+27, 179968, 1, 15, 496, '0', 0, 0, -3131.609375, -2849.241455078125, 34.7274322509765625, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+28, 179968, 1, 15, 496, '0', 0, 0, -3135.4375, -2843.022705078125, 34.31423568725585937, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+29, 179968, 1, 15, 496, '0', 0, 0, -3131.444580078125, -2847.678955078125, 34.66319656372070312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+30, 179968, 1, 15, 496, '0', 0, 0, -3141.357666015625, -2850.845458984375, 34.49334335327148437, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+31, 179968, 1, 15, 496, '0', 0, 0, -3142.001708984375, -2845.967041015625, 34.53655624389648437, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+32, 179968, 1, 15, 496, '0', 0, 0, -3134.272705078125, -2853.536376953125, 34.7743072509765625, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+33, 179968, 1, 15, 496, '0', 0, 0, -3135.913330078125, -2854.022705078125, 34.71007156372070312, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+34, 179968, 1, 15, 496, '0', 0, 0, -3140.310791015625, -2852.345458984375, 34.51569366455078125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+35, 179968, 1, 15, 496, '0', 0, 0, -3140.921875, -2844.623291015625, 34.5094757080078125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+36, 180353, 1, 15, 496, '0', 0, 0, -3131.45654296875, -2848.463623046875, 34.69791793823242187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+37, 180353, 1, 15, 496, '0', 0, 0, -3134.6494140625, -2843.171875, 34.31317520141601562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+38, 180353, 1, 15, 496, '0', 0, 0, -3141.673583984375, -2845.130126953125, 34.53819656372070312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+39, 180353, 1, 15, 496, '0', 0, 0, -3135.076416015625, -2853.901123046875, 34.74479293823242187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+40, 180353, 1, 15, 496, '0', 0, 0, -3140.979248046875, -2851.76904296875, 34.49645614624023437, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+41, 195164, 1, 15, 496, '0', 0, 0, -3131.538330078125, -2847.70654296875, 34.66145706176757812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+42, 195164, 1, 15, 496, '0', 0, 0, -3131.748291015625, -2849.3837890625, 34.72916793823242187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+43, 195164, 1, 15, 496, '0', 0, 0, -3133.970458984375, -2843.411376953125, 34.32986068725585937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+44, 195164, 1, 15, 496, '0', 0, 0, -3135.479248046875, -2843.116455078125, 34.31944656372070312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+45, 195164, 1, 15, 496, '0', 0, 0, -3141.30908203125, -2850.80029296875, 34.49587249755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+46, 195164, 1, 15, 496, '0', 0, 0, -3134.1337890625, -2853.41845703125, 34.78125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+47, 195164, 1, 15, 496, '0', 0, 0, -3141.904541015625, -2846.01220703125, 34.53682327270507812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+48, 195164, 1, 15, 496, '0', 0, 0, -3135.9619140625, -2853.953125, 34.70833206176757812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+49, 195164, 1, 15, 496, '0', 0, 0, -3140.380126953125, -2852.276123046875, 34.515625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+50, 195164, 1, 15, 496, '0', 0, 0, -3140.944580078125, -2844.66845703125, 34.51215362548828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+51, 195664, 1, 15, 496, '0', 0, 0, -3137.666748046875, -2848.48095703125, 34.578125, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Brackenwall Village - Difficulty: 0)

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
