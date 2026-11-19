SET @CGUID := 396524;
SET @OGUID := 249045;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 530, 3525, 3584, '0', 0, 0, 0, 0, -2037.1319580078125, -11902.91015625, 46.08014678955078125, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Blood Watch - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 530, 3525, 3584, '0', 0, 0, 0, 0, -2034.6302490234375, -11895.7919921875, 46.21881866455078125, 0.994837641716003417, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Blood Watch - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 530, 3525, 3584, '0', 0, 0, -2030.9097900390625, -11902.107421875, 46.33854293823242187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+1, 179968, 530, 3525, 3584, '0', 0, 0, -2034.90283203125, -11897.451171875, 45.978515625, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+2, 179968, 530, 3525, 3584, '0', 0, 0, -2033.373291015625, -11897.857421875, 45.92424392700195312, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+3, 179968, 530, 3525, 3584, '0', 0, 0, -2040.38720703125, -11899.0517578125, 46.5243072509765625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+4, 179968, 530, 3525, 3584, '0', 0, 0, -2035.3785400390625, -11908.451171875, 45.76068878173828125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+5, 179968, 530, 3525, 3584, '0', 0, 0, -2040.8228759765625, -11905.2744140625, 46.63888931274414062, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+6, 179968, 530, 3525, 3584, '0', 0, 0, -2031.07470703125, -11903.669921875, 46.42013931274414062, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+7, 179968, 530, 3525, 3584, '0', 0, 0, -2033.7379150390625, -11907.9658203125, 45.84375, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+8, 179968, 530, 3525, 3584, '0', 0, 0, -2039.7760009765625, -11906.7744140625, 46.37847137451171875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+9, 179968, 530, 3525, 3584, '0', 0, 0, -2041.467041015625, -11900.396484375, 46.59722137451171875, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+10, 180353, 530, 3525, 3584, '0', 0, 0, -2034.1146240234375, -11897.6025390625, 45.95160293579101562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+11, 180353, 530, 3525, 3584, '0', 0, 0, -2034.5416259765625, -11908.330078125, 45.80382156372070312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+12, 180353, 530, 3525, 3584, '0', 0, 0, -2041.138916015625, -11899.5595703125, 46.56076431274414062, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+13, 180353, 530, 3525, 3584, '0', 0, 0, -2040.4444580078125, -11906.1982421875, 46.51041793823242187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+14, 180353, 530, 3525, 3584, '0', 0, 0, -2030.921875, -11902.892578125, 46.39583206176757812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Blood Watch - Difficulty: 0)
(@OGUID+15, 195164, 530, 3525, 3584, '0', 0, 0, -2034.9444580078125, -11897.544921875, 46.62501907348632812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+16, 195164, 530, 3525, 3584, '0', 0, 0, -2033.435791015625, -11897.8408203125, 46.574005126953125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+17, 195164, 530, 3525, 3584, '0', 0, 0, -2035.4271240234375, -11908.3837890625, 46.40788650512695312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+18, 195164, 530, 3525, 3584, '0', 0, 0, -2040.7742919921875, -11905.228515625, 47.29101943969726562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+19, 195164, 530, 3525, 3584, '0', 0, 0, -2033.5989990234375, -11907.84765625, 46.50245285034179687, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+20, 195164, 530, 3525, 3584, '0', 0, 0, -2040.4097900390625, -11899.09765625, 47.17122650146484375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+21, 195164, 530, 3525, 3584, '0', 0, 0, -2031.2135009765625, -11903.8134765625, 47.04970169067382812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+22, 195164, 530, 3525, 3584, '0', 0, 0, -2031.0035400390625, -11902.1357421875, 46.97157669067382812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+23, 195164, 530, 3525, 3584, '0', 0, 0, -2039.845458984375, -11906.705078125, 47.05317306518554687, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+24, 195164, 530, 3525, 3584, '0', 0, 0, -2041.3697509765625, -11900.44140625, 47.24414443969726562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Blood Watch - Difficulty: 0)
(@OGUID+25, 195664, 530, 3525, 3584, '0', 0, 0, -2037.1319580078125, -11902.91015625, 45.99681472778320312, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Blood Watch - Difficulty: 0)

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
