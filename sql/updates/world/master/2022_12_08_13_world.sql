SET @CGUID := 396603;
SET @OGUID := 249984;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 0, 8, 5458, '0', 0, 0, 0, 0, -9779.4404296875, -3841.969970703125, 23.09723472595214843, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Bogpaddle - Difficulty: 0) (Auras: )
(@CGUID+1, 34653, 0, 8, 5458, '0', 0, 0, 0, 0, -9785.16015625, -3846.10009765625, 22.21903419494628906, 2.460914134979248046, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table Hostess (Area: Bogpaddle - Difficulty: 0)
(@CGUID+2, 34654, 0, 8, 5458, '0', 0, 0, 0, 0, -9783.419921875, -3834.7900390625, 23.72113418579101562, 2.30383467674255371, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Feast Hostess (Area: Bogpaddle - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 0, 8, 5458, '0', 0, 0, -9782.1298828125, -3837.639892578125, 22.87150001525878906, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+1, 179968, 0, 8, 5458, '0', 0, 0, -9781.830078125, -3846.169921875, 22.42659950256347656, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+2, 179968, 0, 8, 5458, '0', 0, 0, -9783.1298828125, -3844.330078125, 22.48439979553222656, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+3, 179968, 0, 8, 5458, '0', 0, 0, -9784.0302734375, -3839.780029296875, 22.55480003356933593, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+4, 179968, 0, 8, 5458, '0', 0, 0, -9775.6298828125, -3847.18994140625, 22.30470085144042968, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+5, 179968, 0, 8, 5458, '0', 0, 0, -9777.4404296875, -3836.5, 23.27079963684082031, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+6, 179968, 0, 8, 5458, '0', 0, 0, -9772.830078125, -3843.159912109375, 23.06229972839355468, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+7, 179968, 0, 8, 5458, '0', 0, 0, -9775.330078125, -3837.139892578125, 23.17709922790527343, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+8, 179968, 0, 8, 5458, '0', 0, 0, -9778.23046875, -3847.639892578125, 22.34900093078613281, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+9, 179968, 0, 8, 5458, '0', 0, 0, -9772.830078125, -3840.800048828125, 23.15629959106445312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+10, 180353, 0, 8, 5458, '0', 0, 0, -9782.73046875, -3845.260009765625, 22.49550056457519531, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+11, 180353, 0, 8, 5458, '0', 0, 0, -9783.330078125, -3838.550048828125, 22.69989967346191406, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+12, 180353, 0, 8, 5458, '0', 0, 0, -9772.830078125, -3841.919921875, 23.16839981079101562, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+13, 180353, 0, 8, 5458, '0', 0, 0, -9776.830078125, -3847.389892578125, 22.3264007568359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+14, 180353, 0, 8, 5458, '0', 0, 0, -9776.4404296875, -3836.659912109375, 23.23780059814453125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Bogpaddle - Difficulty: 0)
(@OGUID+15, 195164, 0, 8, 5458, '0', 0, 0, -9783.9404296875, -3839.830078125, 23.19090080261230468, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+16, 195164, 0, 8, 5458, '0', 0, 0, -9783.0302734375, -3844.2900390625, 23.12520027160644531, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+17, 195164, 0, 8, 5458, '0', 0, 0, -9772.9404296875, -3840.830078125, 23.80030059814453125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+18, 195164, 0, 8, 5458, '0', 0, 0, -9775.4404296875, -3847.080078125, 22.93490028381347656, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+19, 195164, 0, 8, 5458, '0', 0, 0, -9777.4404296875, -3836.590087890625, 23.8871002197265625, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+20, 195164, 0, 8, 5458, '0', 0, 0, -9778.330078125, -3847.570068359375, 22.98419952392578125, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+21, 195164, 0, 8, 5458, '0', 0, 0, -9782.1298828125, -3837.68994140625, 23.49130058288574218, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+22, 195164, 0, 8, 5458, '0', 0, 0, -9772.9404296875, -3843.300048828125, 23.69090080261230468, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+23, 195164, 0, 8, 5458, '0', 0, 0, -9775.4404296875, -3837.1201171875, 23.80730056762695312, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+24, 195164, 0, 8, 5458, '0', 0, 0, -9781.9404296875, -3846.10009765625, 23.05080032348632812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Bogpaddle - Difficulty: 0)
(@OGUID+25, 195664, 0, 8, 5458, '0', 0, 0, -9779.4404296875, -3841.969970703125, 23.0139007568359375, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Bogpaddle - Difficulty: 0)

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
