SET @CGUID := 396599;
SET @OGUID := 249932;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 40, 108, '0', 0, 0, 0, 0, -10538.2001953125, 1022.94000244140625, 56.68903350830078125, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Sentinel Hill - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 40, 108, '0', 0, 0, 0, 0, -10541.5, 1017.58001708984375, 56.52773284912109375, 3.839724302291870117, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Sentinel Hill - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 40, 108, '0', 0, 0, -10541, 1027.260009765625, 56.60570144653320312, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+1, 179968, 0, 40, 108, '0', 0, 0, -10542.900390625, 1025.1300048828125, 56.60570144653320312, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+2, 179968, 0, 40, 108, '0', 0, 0, -10541.900390625, 1020.58001708984375, 56.60509872436523437, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+3, 179968, 0, 40, 108, '0', 0, 0, -10540.599609375, 1018.739990234375, 56.55030059814453125, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+4, 179968, 0, 40, 108, '0', 0, 0, -10534.099609375, 1027.800048828125, 56.60580062866210937, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+5, 179968, 0, 40, 108, '0', 0, 0, -10531.7001953125, 1024.0999755859375, 56.60580062866210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+6, 179968, 0, 40, 108, '0', 0, 0, -10531.599609375, 1021.75, 56.60580062866210937, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+7, 179968, 0, 40, 108, '0', 0, 0, -10536.2001953125, 1028.4100341796875, 56.60580062866210937, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+8, 179968, 0, 40, 108, '0', 0, 0, -10534.400390625, 1017.71002197265625, 56.60589981079101562, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+9, 179968, 0, 40, 108, '0', 0, 0, -10537.099609375, 1017.27001953125, 56.60570144653320312, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+10, 180353, 0, 40, 108, '0', 0, 0, -10541.5, 1019.6500244140625, 56.55080032348632812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+11, 180353, 0, 40, 108, '0', 0, 0, -10542.2001953125, 1026.3499755859375, 56.60570144653320312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+12, 180353, 0, 40, 108, '0', 0, 0, -10531.599609375, 1022.989990234375, 56.60580062866210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+13, 180353, 0, 40, 108, '0', 0, 0, -10535.2001953125, 1028.25, 56.60580062866210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+14, 180353, 0, 40, 108, '0', 0, 0, -10535.599609375, 1017.52001953125, 56.60580062866210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+15, 195164, 0, 40, 108, '0', 0, 0, -10542.7998046875, 1025.0799560546875, 57.27659988403320312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+16, 195164, 0, 40, 108, '0', 0, 0, -10541.900390625, 1020.6199951171875, 57.27579879760742187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+17, 195164, 0, 40, 108, '0', 0, 0, -10540.7001953125, 1018.80999755859375, 57.2212982177734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+18, 195164, 0, 40, 108, '0', 0, 0, -10534.2998046875, 1027.7900390625, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+19, 195164, 0, 40, 108, '0', 0, 0, -10531.7998046875, 1021.5999755859375, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+20, 195164, 0, 40, 108, '0', 0, 0, -10531.7998046875, 1024.0699462890625, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+21, 195164, 0, 40, 108, '0', 0, 0, -10541, 1027.219970703125, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+22, 195164, 0, 40, 108, '0', 0, 0, -10536.2001953125, 1028.31005859375, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+23, 195164, 0, 40, 108, '0', 0, 0, -10534.2998046875, 1017.83001708984375, 57.27679824829101562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+24, 195164, 0, 40, 108, '0', 0, 0, -10537.099609375, 1017.34002685546875, 57.27669906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Sentinel Hill - Difficulty: 0)
(@OGUID+25, 195664, 0, 40, 108, '0', 0, 0, -10538.2001953125, 1022.94000244140625, 56.60570144653320312, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Sentinel Hill - Difficulty: 0)

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
