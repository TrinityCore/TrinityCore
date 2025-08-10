SET @CGUID := 396601;
SET @OGUID := 249958;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 10, 42, '0', 0, 0, 0, 0, -10507.1884765625, -1263.1927490234375, 41.16492843627929687, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Darkshire - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 10, 42, '0', 0, 0, 0, 0, -10512.1923828125, -1266.1163330078125, 41.16327667236328125, 3.001966238021850585, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Darkshire - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 10, 42, '0', 0, 0, -10506.044921875, -1268.8680419921875, 41.11111068725585937, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+1, 179968, 0, 10, 42, '0', 0, 0, -10510.8798828125, -1265.55908203125, 41.078125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+2, 179968, 0, 10, 42, '0', 0, 0, -10509.6064453125, -1267.3975830078125, 41.12673568725585937, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+3, 179968, 0, 10, 42, '0', 0, 0, -10500.642578125, -1262.032958984375, 40.8269500732421875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+4, 179968, 0, 10, 42, '0', 0, 0, -10505.173828125, -1257.7257080078125, 41.12673568725585937, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+5, 179968, 0, 10, 42, '0', 0, 0, -10500.61328125, -1264.388916015625, 40.878204345703125, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+6, 179968, 0, 10, 42, '0', 0, 0, -10511.841796875, -1261.0086669921875, 41.3055572509765625, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+7, 179968, 0, 10, 42, '0', 0, 0, -10503.396484375, -1268.421875, 41.11815643310546875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+8, 179968, 0, 10, 42, '0', 0, 0, -10503.0830078125, -1258.3367919921875, 41.07291793823242187, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+9, 179968, 0, 10, 42, '0', 0, 0, -10509.9267578125, -1258.873291015625, 41.2899322509765625, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+10, 180353, 0, 10, 42, '0', 0, 0, -10510.498046875, -1266.484375, 41.1180572509765625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+11, 180353, 0, 10, 42, '0', 0, 0, -10504.169921875, -1257.88720703125, 41.11632156372070312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+12, 180353, 0, 10, 42, '0', 0, 0, -10504.595703125, -1268.6146240234375, 41.11126327514648437, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+13, 180353, 0, 10, 42, '0', 0, 0, -10511.142578125, -1259.78125, 41.3125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+14, 180353, 0, 10, 42, '0', 0, 0, -10500.580078125, -1263.1492919921875, 40.84093475341796875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Darkshire - Difficulty: 0)
(@OGUID+15, 195164, 0, 10, 42, '0', 0, 0, -10509.67578125, -1267.326416015625, 41.8396759033203125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+16, 195164, 0, 10, 42, '0', 0, 0, -10510.830078125, -1265.515625, 41.79106521606445312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+17, 195164, 0, 10, 42, '0', 0, 0, -10503.220703125, -1258.3489990234375, 41.78831100463867187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+18, 195164, 0, 10, 42, '0', 0, 0, -10505.2138671875, -1257.8211669921875, 41.84314727783203125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+19, 195164, 0, 10, 42, '0', 0, 0, -10506.0986328125, -1268.796875, 41.82578659057617187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+20, 195164, 0, 10, 42, '0', 0, 0, -10509.9462890625, -1258.91845703125, 42.00286865234375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+21, 195164, 0, 10, 42, '0', 0, 0, -10503.2548828125, -1268.3021240234375, 41.83446502685546875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+22, 195164, 0, 10, 42, '0', 0, 0, -10500.732421875, -1262.060791015625, 41.54319000244140625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+23, 195164, 0, 10, 42, '0', 0, 0, -10500.75, -1264.532958984375, 41.60356521606445312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+24, 195164, 0, 10, 42, '0', 0, 0, -10511.7451171875, -1261.0538330078125, 42.00807571411132812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Darkshire - Difficulty: 0)
(@OGUID+25, 195664, 0, 10, 42, '0', 0, 0, -10507.2001953125, -1263.18994140625, 41.08160018920898437, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Darkshire - Difficulty: 0)

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
