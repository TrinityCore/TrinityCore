SET @CGUID := 396577;
SET @OGUID := 249646;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 267, 272, '0', 0, 0, 0, 0, -60.6094017028808593, -881.36102294921875, 57.18233108520507812, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Tarren Mill - Difficulty: 0) (Auras: )
(@CGUID+1, 34654, 0, 267, 272, '0', 0, 0, 0, 0, -52.0416984558105468, -879.2860107421875, 56.73633193969726562, 0.226892799139022827, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Tarren Mill - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 267, 272, '0', 0, 0, -56.8176994323730468, -886.5889892578125, 56.7389984130859375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+1, 179968, 0, 267, 272, '0', 0, 0, -54.0364990234375, -882.5560302734375, 56.91910171508789062, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+2, 179968, 0, 267, 272, '0', 0, 0, -54.0642013549804687, -880.20001220703125, 56.90800094604492187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+3, 179968, 0, 267, 272, '0', 0, 0, -58.5937995910644531, -875.89202880859375, 56.99670028686523437, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+4, 179968, 0, 267, 272, '0', 0, 0, -63.0294990539550781, -885.56402587890625, 56.85770034790039062, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+5, 179968, 0, 267, 272, '0', 0, 0, -64.3003005981445312, -883.72601318359375, 56.9449005126953125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+6, 179968, 0, 267, 272, '0', 0, 0, -59.4687995910644531, -887.03302001953125, 56.81600189208984375, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+7, 179968, 0, 267, 272, '0', 0, 0, -63.3489990234375, -877.03997802734375, 57.28820037841796875, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+8, 179968, 0, 267, 272, '0', 0, 0, -56.5051994323730468, -876.50201416015625, 56.89149856567382812, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+9, 179968, 0, 267, 272, '0', 0, 0, -65.2639007568359375, -879.17401123046875, 57.215301513671875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+10, 180353, 0, 267, 272, '0', 0, 0, -54, -881.31402587890625, 56.90990066528320312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+11, 180353, 0, 267, 272, '0', 0, 0, -64.5642013549804687, -877.947998046875, 57.2639007568359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+12, 180353, 0, 267, 272, '0', 0, 0, -57.5919990539550781, -876.05401611328125, 56.96419906616210937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+13, 180353, 0, 267, 272, '0', 0, 0, -63.9201011657714843, -884.6510009765625, 56.88190078735351562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+14, 180353, 0, 267, 272, '0', 0, 0, -58.0173988342285156, -886.78302001953125, 56.81029891967773437, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Tarren Mill - Difficulty: 0)
(@OGUID+15, 195164, 0, 267, 272, '0', 0, 0, -54.1735992431640625, -882.70001220703125, 57.5800018310546875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+16, 195164, 0, 267, 272, '0', 0, 0, -54.1562995910644531, -880.22698974609375, 57.56499862670898437, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+17, 195164, 0, 267, 272, '0', 0, 0, -59.5191001892089843, -886.9639892578125, 57.47340011596679687, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+18, 195164, 0, 267, 272, '0', 0, 0, -56.6771011352539062, -886.47100830078125, 57.387298583984375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+19, 195164, 0, 267, 272, '0', 0, 0, -64.2517013549804687, -883.6820068359375, 57.60499954223632812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+20, 195164, 0, 267, 272, '0', 0, 0, -56.6423988342285156, -876.51702880859375, 57.570098876953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+21, 195164, 0, 267, 272, '0', 0, 0, -63.097198486328125, -885.49298095703125, 57.512298583984375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+22, 195164, 0, 267, 272, '0', 0, 0, -65.1667022705078125, -879.22100830078125, 57.8628997802734375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+23, 195164, 0, 267, 272, '0', 0, 0, -58.6353988647460937, -875.98602294921875, 57.6548004150390625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+24, 195164, 0, 267, 272, '0', 0, 0, -63.3680992126464843, -877.08502197265625, 57.9375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Tarren Mill - Difficulty: 0)
(@OGUID+25, 195664, 0, 267, 272, '0', 0, 0, -60.6094017028808593, -881.36102294921875, 57.0989990234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Tarren Mill - Difficulty: 0)

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
