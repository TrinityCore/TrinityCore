SET @OGUID := 247542;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=190104; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=190104; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12398;

DELETE FROM `gameobject_queststarter` WHERE `id`=190104;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190104, 12398, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190104 AND `quest`=12398);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190104;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227389 AND 227396;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227389 AND 227396;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 15, 4010, '0', 0, 0, -4568.92626953125, -3176.9208984375, 39.69365310668945312, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+1, 180406, 1, 15, 4010, '0', 0, 0, -4598.62939453125, -3176.501708984375, 38.29652786254882812, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+2, 180407, 1, 15, 4010, '0', 0, 0, -4598.18896484375, -3170.33984375, 38.37108993530273437, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+3, 180411, 1, 15, 4010, '0', 0, 0, -4623.16650390625, -3167.2421875, 42.21464920043945312, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+4, 180472, 1, 15, 4010, '0', 0, 0, -4602.04541015625, -3172.749267578125, 47.08140945434570312, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+5, 180472, 1, 15, 4010, '0', 0, 0, -4586.39794921875, -3186.8603515625, 41.13997268676757812, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Mudsprocket - Difficulty: 0)
(@OGUID+6, 180523, 1, 15, 4010, '0', 0, 0, -4628.17822265625, -3169.177001953125, 35.2819976806640625, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 120, 255, 1, 46366), -- Apple Bob (Area: Mudsprocket - Difficulty: 0)
(@OGUID+7, 190104, 1, 15, 4010, '0', 0, 0, -4626.43603515625, -3172.865966796875, 41.2522125244140625, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 46366); -- Candy Bucket (Area: Mudsprocket - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7);
