SET @CGUID := 396566;
SET @OGUID := 249516;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 1, 1377, 3425, '0', 0, 0, 0, 0, -6835.02978515625, 730.1024169921875, 42.25841140747070312, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Cenarion Hold - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 1, 1377, 3425, '0', 0, 0, 0, 0, -6827.3125, 730.4149169921875, 42.51041030883789062, 0.994837641716003417, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table Hostess (Area: Cenarion Hold - Difficulty: 0)
(@CGUID+2, 34654, 1, 1377, 3425, '0', 0, 0, 0, 0, -6831.02783203125, 736.32293701171875, 42.11246490478515625, 0.994837641716003417, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Cenarion Hold - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 1, 1377, 3425, '0', 0, 0, -6831.27099609375, 735.154541015625, 42.0382080078125, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+1, 179968, 1, 1377, 3425, '0', 0, 0, -6828.80712890625, 730.904541015625, 42.34721755981445312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+2, 179968, 1, 1377, 3425, '0', 0, 0, -6838.28466796875, 733.9600830078125, 42.09693527221679687, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+3, 179968, 1, 1377, 3425, '0', 0, 0, -6831.63525390625, 725.046875, 42.19963836669921875, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+4, 179968, 1, 1377, 3425, '0', 0, 0, -6838.720703125, 727.73785400390625, 42.31250762939453125, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+5, 179968, 1, 1377, 3425, '0', 0, 0, -6832.80029296875, 735.560791015625, 41.88399887084960937, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+6, 179968, 1, 1377, 3425, '0', 0, 0, -6833.27587890625, 724.560791015625, 42.67011260986328125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+7, 179968, 1, 1377, 3425, '0', 0, 0, -6837.673828125, 726.23785400390625, 42.35245132446289062, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+8, 179968, 1, 1377, 3425, '0', 0, 0, -6839.36474609375, 732.6163330078125, 42.21748733520507812, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+9, 179968, 1, 1377, 3425, '0', 0, 0, -6828.97216796875, 729.342041015625, 42.3350830078125, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+10, 180353, 1, 1377, 3425, '0', 0, 0, -6832.01220703125, 735.41143798828125, 41.95886611938476562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+11, 180353, 1, 1377, 3425, '0', 0, 0, -6828.8193359375, 730.11981201171875, 42.34548187255859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+12, 180353, 1, 1377, 3425, '0', 0, 0, -6838.34228515625, 726.81427001953125, 42.34897232055664062, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+13, 180353, 1, 1377, 3425, '0', 0, 0, -6839.03662109375, 733.453125, 42.16347122192382812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+14, 180353, 1, 1377, 3425, '0', 0, 0, -6832.439453125, 724.68231201171875, 42.40452194213867187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+15, 195164, 1, 1377, 3425, '0', 0, 0, -6831.33349609375, 735.171875, 42.71996307373046875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+16, 195164, 1, 1377, 3425, '0', 0, 0, -6828.90087890625, 730.87677001953125, 43.03228378295898437, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+17, 195164, 1, 1377, 3425, '0', 0, 0, -6829.111328125, 729.19964599609375, 43.01491546630859375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+18, 195164, 1, 1377, 3425, '0', 0, 0, -6833.32470703125, 724.63018798828125, 43.36900711059570312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+19, 195164, 1, 1377, 3425, '0', 0, 0, -6839.267578125, 732.5711669921875, 42.89789199829101562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+20, 195164, 1, 1377, 3425, '0', 0, 0, -6837.7431640625, 726.30731201171875, 43.04446029663085937, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+21, 195164, 1, 1377, 3425, '0', 0, 0, -6838.671875, 727.78302001953125, 43.00104522705078125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+22, 195164, 1, 1377, 3425, '0', 0, 0, -6831.49658203125, 725.1649169921875, 42.86907958984375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+23, 195164, 1, 1377, 3425, '0', 0, 0, -6838.30712890625, 733.9149169921875, 42.7890472412109375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+24, 195164, 1, 1377, 3425, '0', 0, 0, -6832.84228515625, 735.467041015625, 42.57432174682617187, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Cenarion Hold - Difficulty: 0)
(@OGUID+25, 195664, 1, 1377, 3425, '0', 0, 0, -6835.02978515625, 730.1024169921875, 42.1750946044921875, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Cenarion Hold - Difficulty: 0)

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
