SET @CGUID := 396591;
SET @OGUID := 249828;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 3, 5565, '0', 0, 0, 0, 0, -6707.72021484375, -2456.89990234375, 272.859344482421875, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: New Kargath - Difficulty: 0) (Auras: )
(@CGUID+1, 34654, 0, 3, 5565, '0', 0, 0, 0, 0, -6703.10009765625, -2450.830078125, 272.843353271484375, 1.099557399749755859, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: New Kargath - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 3, 5565, '0', 0, 0, -6703.6201171875, -2452.0400390625, 272.760009765625, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+1, 179968, 0, 3, 5565, '0', 0, 0, -6701.14990234375, -2458.090087890625, 272.760009765625, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+2, 179968, 0, 3, 5565, '0', 0, 0, -6701.18017578125, -2455.739990234375, 272.760009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+3, 179968, 0, 3, 5565, '0', 0, 0, -6710.14013671875, -2461.10009765625, 272.87799072265625, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+4, 179968, 0, 3, 5565, '0', 0, 0, -6712.3798828125, -2454.7099609375, 273.983001708984375, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+5, 179968, 0, 3, 5565, '0', 0, 0, -6706.580078125, -2462.570068359375, 272.75799560546875, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+6, 179968, 0, 3, 5565, '0', 0, 0, -6711.41015625, -2459.260009765625, 273.20098876953125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+7, 179968, 0, 3, 5565, '0', 0, 0, -6705.7099609375, -2451.429931640625, 272.760009765625, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+8, 179968, 0, 3, 5565, '0', 0, 0, -6703.93017578125, -2462.1298828125, 272.769989013671875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+9, 179968, 0, 3, 5565, '0', 0, 0, -6710.4599609375, -2452.580078125, 273.37701416015625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+10, 180353, 0, 3, 5565, '0', 0, 0, -6701.10986328125, -2456.85009765625, 272.760009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+11, 180353, 0, 3, 5565, '0', 0, 0, -6711.68017578125, -2453.489990234375, 273.805999755859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+12, 180353, 0, 3, 5565, '0', 0, 0, -6711.02978515625, -2460.18994140625, 273.0360107421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+13, 180353, 0, 3, 5565, '0', 0, 0, -6704.7099609375, -2451.590087890625, 272.760009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+14, 180353, 0, 3, 5565, '0', 0, 0, -6705.1298828125, -2462.320068359375, 272.7650146484375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: New Kargath - Difficulty: 0)
(@OGUID+15, 195164, 0, 3, 5565, '0', 0, 0, -6703.759765625, -2452.06005859375, 273.4010009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+16, 195164, 0, 3, 5565, '0', 0, 0, -6701.27001953125, -2455.77001953125, 273.4010009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+17, 195164, 0, 3, 5565, '0', 0, 0, -6703.7900390625, -2462.010009765625, 273.4110107421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+18, 195164, 0, 3, 5565, '0', 0, 0, -6710.2099609375, -2461.030029296875, 273.52301025390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+19, 195164, 0, 3, 5565, '0', 0, 0, -6701.2900390625, -2458.239990234375, 273.4010009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+20, 195164, 0, 3, 5565, '0', 0, 0, -6710.47998046875, -2452.6201171875, 274.0260009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+21, 195164, 0, 3, 5565, '0', 0, 0, -6705.75, -2451.52001953125, 273.402008056640625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+22, 195164, 0, 3, 5565, '0', 0, 0, -6706.6298828125, -2462.5, 273.39801025390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+23, 195164, 0, 3, 5565, '0', 0, 0, -6711.35986328125, -2459.219970703125, 273.8380126953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+24, 195164, 0, 3, 5565, '0', 0, 0, -6712.27978515625, -2454.760009765625, 274.582000732421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: New Kargath - Difficulty: 0)
(@OGUID+25, 195664, 0, 3, 5565, '0', 0, 0, -6707.72021484375, -2456.89990234375, 272.7760009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: New Kargath - Difficulty: 0)

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
