SET @CGUID := 396559;
SET @OGUID := 249458;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 1, 400, 5041, '0', 0, 0, 0, 0, -6089.18017578125, -3869.889892578125, 6.274813652038574218, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 1, 400, 5041, '0', 0, 0, 0, 0, -6092.9501953125, -3879.18994140625, 6.274813652038574218, 2.757620096206665039, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table Hostess (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@CGUID+2, 34654, 1, 400, 5041, '0', 0, 0, 0, 0, -6097.5, -3875.4599609375, 6.274813652038574218, 5.183627605438232421, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 1, 400, 5041, '0', 0, 0, -6092.8701171875, -3872.25, 6.191480159759521484, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+1, 179968, 1, 400, 5041, '0', 0, 0, -6086.9501953125, -3864.429931640625, 6.191480159759521484, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+2, 179968, 1, 400, 5041, '0', 0, 0, -6083.1201171875, -3870.64990234375, 6.191480159759521484, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+3, 179968, 1, 400, 5041, '0', 0, 0, -6087.43017578125, -3875.429931640625, 6.191480159759521484, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+4, 179968, 1, 400, 5041, '0', 0, 0, -6082.9599609375, -3869.080078125, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+5, 179968, 1, 400, 5041, '0', 0, 0, -6092.43994140625, -3866.030029296875, 6.191480159759521484, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+6, 179968, 1, 400, 5041, '0', 0, 0, -6093.52001953125, -3867.3701171875, 6.191480159759521484, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+7, 179968, 1, 400, 5041, '0', 0, 0, -6085.7900390625, -3874.93994140625, 6.191480159759521484, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+8, 179968, 1, 400, 5041, '0', 0, 0, -6091.81982421875, -3873.75, 6.191480159759521484, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+9, 179968, 1, 400, 5041, '0', 0, 0, -6085.419921875, -3864.830078125, 6.191480159759521484, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+10, 180353, 1, 400, 5041, '0', 0, 0, -6086.58984375, -3875.31005859375, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+11, 180353, 1, 400, 5041, '0', 0, 0, -6082.97021484375, -3869.8701171875, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+12, 180353, 1, 400, 5041, '0', 0, 0, -6093.18994140625, -3866.530029296875, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+13, 180353, 1, 400, 5041, '0', 0, 0, -6086.16015625, -3864.580078125, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+14, 180353, 1, 400, 5041, '0', 0, 0, -6092.490234375, -3873.169921875, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+15, 195164, 1, 400, 5041, '0', 0, 0, -6087.47900390625, -3875.361083984375, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+16, 195164, 1, 400, 5041, '0', 0, 0, -6091.890625, -3873.6806640625, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+17, 195164, 1, 400, 5041, '0', 0, 0, -6085.47900390625, -3864.819580078125, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+18, 195164, 1, 400, 5041, '0', 0, 0, -6083.26025390625, -3870.7900390625, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+19, 195164, 1, 400, 5041, '0', 0, 0, -6083.05029296875, -3869.111083984375, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+20, 195164, 1, 400, 5041, '0', 0, 0, -6092.8193359375, -3872.19970703125, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+21, 195164, 1, 400, 5041, '0', 0, 0, -6085.6494140625, -3874.819580078125, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+22, 195164, 1, 400, 5041, '0', 0, 0, -6086.98974609375, -3864.520751953125, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+23, 195164, 1, 400, 5041, '0', 0, 0, -6092.4599609375, -3866.069580078125, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+24, 195164, 1, 400, 5041, '0', 0, 0, -6093.42041015625, -3867.420166015625, 6.873746395111083984, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)
(@OGUID+25, 195664, 1, 400, 5041, '0', 0, 0, -6089.18017578125, -3869.8798828125, 6.191480159759521484, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Fizzle & Pozzik's Speedbarge - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0), 
(@EVENT, @CGUID+1),
(@EVENT, @CGUID+2);

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
