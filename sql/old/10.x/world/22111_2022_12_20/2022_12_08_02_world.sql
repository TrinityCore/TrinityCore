SET @CGUID := 396575;
SET @OGUID := 249620;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 130, 228, '0', 0, 0, 0, 0, 451.74798583984375, 1528.3599853515625, 133.024322509765625, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: The Sepulcher - Difficulty: 0) (Auras: )
(@CGUID+1, 34654, 0, 130, 228, '0', 0, 0, 0, 0, 459.553985595703125, 1527.199951171875, 132.71533203125, 5.672319889068603515, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: The Sepulcher - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 130, 228, '0', 0, 0, 458.292999267578125, 1529.52001953125, 132.3780059814453125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+1, 179968, 0, 130, 228, '0', 0, 0, 455.7760009765625, 1533.18994140625, 132.447998046875, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+2, 179968, 0, 130, 228, '0', 0, 0, 453.764007568359375, 1533.8399658203125, 132.5570068359375, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+3, 179968, 0, 130, 228, '0', 0, 0, 452.889007568359375, 1522.699951171875, 132.906005859375, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+4, 179968, 0, 130, 228, '0', 0, 0, 449.009002685546875, 1532.68994140625, 133.2599945068359375, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+5, 179968, 0, 130, 228, '0', 0, 0, 448.0570068359375, 1526.010009765625, 133.572998046875, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+6, 179968, 0, 130, 228, '0', 0, 0, 449.3280029296875, 1524.1600341796875, 133.4250030517578125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+7, 179968, 0, 130, 228, '0', 0, 0, 458.321014404296875, 1527.1800537109375, 132.6199951171875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+8, 179968, 0, 130, 228, '0', 0, 0, 447.093994140625, 1530.56005859375, 133.6060028076171875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+9, 179968, 0, 130, 228, '0', 0, 0, 455.540008544921875, 1523.1500244140625, 133.0070037841796875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+10, 180353, 0, 130, 228, '0', 0, 0, 458.358001708984375, 1528.4100341796875, 132.4709930419921875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+11, 180353, 0, 130, 228, '0', 0, 0, 454.7659912109375, 1533.6800537109375, 132.4770050048828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+12, 180353, 0, 130, 228, '0', 0, 0, 448.43798828125, 1525.0799560546875, 133.531005859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+13, 180353, 0, 130, 228, '0', 0, 0, 447.792999267578125, 1531.77001953125, 133.4770050048828125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+14, 180353, 0, 130, 228, '0', 0, 0, 454.339996337890625, 1522.949951171875, 132.9170074462890625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: The Sepulcher - Difficulty: 0)
(@OGUID+15, 195164, 0, 130, 228, '0', 0, 0, 455.714996337890625, 1533.199951171875, 133.1649932861328125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+16, 195164, 0, 130, 228, '0', 0, 0, 458.20098876953125, 1529.510009765625, 133.095001220703125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+17, 195164, 0, 130, 228, '0', 0, 0, 449.260009765625, 1524.22998046875, 134.149993896484375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+18, 195164, 0, 130, 228, '0', 0, 0, 447.191009521484375, 1530.510009765625, 134.3070068359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+19, 195164, 0, 130, 228, '0', 0, 0, 452.8389892578125, 1522.77001953125, 133.602996826171875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+20, 195164, 0, 130, 228, '0', 0, 0, 455.680999755859375, 1523.260009765625, 133.7089996337890625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+21, 195164, 0, 130, 228, '0', 0, 0, 453.72198486328125, 1533.739990234375, 133.2790069580078125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+22, 195164, 0, 130, 228, '0', 0, 0, 458.183990478515625, 1527.02001953125, 133.3300018310546875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+23, 195164, 0, 130, 228, '0', 0, 0, 448.989990234375, 1532.6500244140625, 133.977996826171875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+24, 195164, 0, 130, 228, '0', 0, 0, 448.105987548828125, 1526.050048828125, 134.2790069580078125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: The Sepulcher - Difficulty: 0)
(@OGUID+25, 195664, 0, 130, 228, '0', 0, 0, 451.74798583984375, 1528.3599853515625, 132.9409942626953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: The Sepulcher - Difficulty: 0)

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
