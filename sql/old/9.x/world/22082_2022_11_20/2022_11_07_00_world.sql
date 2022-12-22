SET @OGUID := 244782;

-- Grand Expedition Yak passenger
DELETE FROM `creature` WHERE `guid`=452764 AND `id`=62821;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry` IN (208181, 208183); -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208181; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208183; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=29020;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29020, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=29019;

DELETE FROM `gameobject_queststarter` WHERE `id` IN (208181, 208183);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208181, 29019, 46366),
(208183, 29020, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208181 AND `quest`=29019);
UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208183 AND `quest`=29020);

DELETE FROM `game_event_gameobject_quest` WHERE `id` IN (208181, 208183);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+26;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180406, 646, 5042, 5303, '0', 0, 0, 1031.9930419921875, 639.1961669921875, -45.0401496887207031, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+1, 180406, 646, 5042, 5303, '0', 0, 0, 1102.609375, 441.067718505859375, -44.0304336547851562, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+2, 180407, 646, 5042, 5303, '0', 0, 0, 1090.1129150390625, 432.302093505859375, -45.9852485656738281, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+3, 180415, 646, 5042, 5303, '0', 0, 0, 1089.7379150390625, 435.546875, -46.0992469787597656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+4, 180415, 646, 5042, 5303, '0', 0, 0, 1088.4757080078125, 432.1788330078125, -46.0840339660644531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+5, 180415, 646, 5042, 5303, '0', 0, 0, 1044.59375, 639.60418701171875, -45.4796638488769531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+6, 180415, 646, 5042, 5303, '0', 0, 0, 1054.0069580078125, 637.32464599609375, -45.8671913146972656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+7, 180415, 646, 5042, 5303, '0', 0, 0, 1052.1041259765625, 639.02081298828125, -45.0377349853515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+8, 180415, 646, 5042, 5303, '0', 0, 0, 1046.482666015625, 639.92364501953125, -45.1595497131347656, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+9, 180415, 646, 5042, 5303, '0', 0, 0, 1045.6805419921875, 640.48614501953125, -44.3372077941894531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+10, 180415, 646, 5042, 5303, '0', 0, 0, 1097.8958740234375, 437.2413330078125, -45.4716987609863281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+11, 180415, 646, 5042, 5303, '0', 0, 0, 1100.9461669921875, 440.296875, -44.078521728515625, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+12, 180415, 646, 5042, 5303, '0', 0, 0, 1090.201416015625, 433.614593505859375, -45.9701347351074218, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+13, 180415, 646, 5042, 5303, '0', 0, 0, 1097.2135009765625, 439.451385498046875, -45.8959999084472656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+14, 180415, 646, 5042, 5303, '0', 0, 0, 1092.638916015625, 434.49652099609375, -44.4317512512207031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+15, 180415, 646, 5042, 5303, '0', 0, 0, 1103.2430419921875, 442.767364501953125, -43.8346443176269531, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+16, 180415, 646, 5042, 5303, '0', 0, 0, 1099.9896240234375, 442.12847900390625, -45.6885871887207031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+17, 180415, 646, 5042, 5303, '0', 0, 0, 1092.9947509765625, 437.61285400390625, -45.9322853088378906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+18, 180415, 646, 5042, 5303, '0', 0, 0, 1097.6875, 436.845489501953125, -45.2649726867675781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+19, 180415, 646, 5042, 5303, '0', 0, 0, 1095.0677490234375, 438.526031494140625, -46.0259437561035156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+20, 180471, 646, 5042, 5303, '0', 0, 0, 1053.2691650390625, 637.08856201171875, -43.53887939453125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+21, 180471, 646, 5042, 5303, '0', 0, 0, 1055.0382080078125, 637.765625, -43.5929298400878906, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+22, 180472, 646, 5042, 5303, '0', 0, 0, 1043.9913330078125, 639.92706298828125, -42.2204132080078125, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Temple of Earth - Difficulty: 0)
(@OGUID+23, 180523, 646, 5042, 5303, '0', 0, 0, 1035.017333984375, 638.42364501953125, -44.9422111511230468, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 120, 255, 1, 46366), -- Apple Bob (Area: Temple of Earth - Difficulty: 0)
(@OGUID+24, 180523, 646, 5042, 5303, '0', 0, 0, 1100.857666015625, 444.232635498046875, -45.0910224914550781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Temple of Earth - Difficulty: 0)
(@OGUID+25, 208181, 646, 5042, 5303, '0', 0, 0, 1099.2222900390625, 441.15277099609375, -45.621673583984375, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 120, 255, 1, 46366), -- Candy Bucket (Area: Temple of Earth - Difficulty: 0)
(@OGUID+26, 208183, 646, 5042, 5303, '0', 0, 0, 1037.625, 636.84552001953125, -45.4039268493652343, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, 46366); -- Candy Bucket (Area: Temple of Earth - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+26;
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
(12, @OGUID+26);
