SET @CGUID := 396405;
SET @OGUID := 246399;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208119; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208119; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28989;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28989, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208119;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208119, 28989, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208119 AND `quest`=28989);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208119;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 1, 331, 414, '0', 0, 0, 0, 0, 3396.973876953125, 985.5233154296875, 5.702227592468261718, 5.139339923858642578, 120, 10, 0, 188, 0, 1, 0, 0, 0, 46366); -- Black Cat (Area: The Zoram Strand - Difficulty: 0) (possible waypoints or random movement)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228757 AND 228783;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228757 AND 228783;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 331, 414, '0', 0, 0, 3326.157958984375, 972.0399169921875, 9.42227935791015625, 2.862335443496704101, 0, 0, 0.990267753601074218, 0.139175355434417724, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+1, 180406, 1, 331, 414, '0', 0, 0, 3351.471435546875, 964.26739501953125, 7.527106285095214843, 3.473210096359252929, 0, 0, -0.98628520965576171, 0.165049895644187927, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+2, 180407, 1, 331, 2897, '0', 0, 0, 3330.87158203125, 1018.6007080078125, 3.835628032684326171, 1.780233979225158691, 0, 0, 0.7771453857421875, 0.629321098327636718, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+3, 180415, 1, 331, 2897, '0', 0, 0, 3358.15966796875, 1044.5572509765625, 3.1458282470703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+4, 180415, 1, 331, 2897, '0', 0, 0, 3355.643310546875, 1049.0364990234375, 3.053768873214721679, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+5, 180415, 1, 331, 2897, '0', 0, 0, 3357.114501953125, 1040.9375, 3.377634525299072265, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+6, 180415, 1, 331, 2897, '0', 0, 0, 3354.369873046875, 1046.045166015625, 3.305082321166992187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+7, 180415, 1, 331, 2897, '0', 0, 0, 3352.939208984375, 1053.3785400390625, 2.97654271125793457, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+8, 180415, 1, 331, 2897, '0', 0, 0, 3351.59814453125, 1050.3958740234375, 3.193860769271850585, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+9, 180415, 1, 331, 2897, '0', 0, 0, 3348.28125, 1052.4566650390625, 3.210141181945800781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Zoram'gar Outpost - Difficulty: 0)
(@OGUID+10, 180426, 1, 331, 414, '0', 0, 0, 3386.704833984375, 1005.65631103515625, 5.210733890533447265, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+11, 180426, 1, 331, 414, '0', 0, 0, 3351.9072265625, 986.27081298828125, 5.4076690673828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+12, 180426, 1, 331, 414, '0', 0, 0, 3362.537353515625, 1034.265625, 3.449913740158081054, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+13, 180426, 1, 331, 414, '0', 0, 0, 3362.8525390625, 1021.19268798828125, 3.560566425323486328, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+14, 180427, 1, 331, 414, '0', 0, 0, 3391.11376953125, 998.66668701171875, 5.279513835906982421, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+15, 180427, 1, 331, 414, '0', 0, 0, 3376.802001953125, 1005.64239501953125, 4.616852760314941406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+16, 180427, 1, 331, 414, '0', 0, 0, 3339.288330078125, 984.765625, 5.663280487060546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+17, 180427, 1, 331, 414, '0', 0, 0, 3367.884521484375, 1017.75177001953125, 3.561319589614868164, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+18, 180471, 1, 331, 414, '0', 0, 0, 3372.30029296875, 959.7569580078125, 12.19800567626953125, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+19, 180471, 1, 331, 414, '0', 0, 0, 3369.170166015625, 960.48785400390625, 12.29633808135986328, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+20, 180471, 1, 331, 414, '0', 0, 0, 3350.880126953125, 961.43402099609375, 12.25194740295410156, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+21, 180471, 1, 331, 414, '0', 0, 0, 3356.37158203125, 962.029541015625, 12.41311836242675781, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+22, 180471, 1, 331, 414, '0', 0, 0, 3353.872314453125, 961.85589599609375, 12.32870388031005859, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+23, 180471, 1, 331, 414, '0', 0, 0, 3366.09716796875, 961.47052001953125, 12.37916278839111328, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+24, 180471, 1, 331, 414, '0', 0, 0, 3363.62939453125, 962.0625, 12.5409708023071289, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+25, 180471, 1, 331, 414, '0', 0, 0, 3359.837646484375, 962.3507080078125, 12.63192939758300781, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+26, 180523, 1, 331, 414, '0', 0, 0, 3354.765625, 965.11981201171875, 7.954864501953125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+27, 185454, 1, 331, 414, '0', 0, 0, 3351.60595703125, 965.15625, 7.564345359802246093, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 46366), -- Laying Skeleton 02 (Area: The Zoram Strand - Difficulty: 0)
(@OGUID+28, 208119, 1, 331, 414, '0', 0, 0, 3362.1181640625, 950.40277099609375, 7.404267311096191406, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 46366); -- Candy Bucket (Area: The Zoram Strand - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28);
