SET @OGUID := 248107;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208178; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208178; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=29016;

DELETE FROM `gameobject_queststarter` WHERE `id`=208178;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208178, 29016, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208178 AND `quest`=29016);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208178;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227944 AND 227981;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227944 AND 227981;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 5034, 5670, '0', 0, 0, -8351.7412109375, 793.748291015625, 151.393096923828125, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+1, 180406, 1, 5034, 5670, '0', 0, 0, -8330.091796875, 777.4913330078125, 153.266876220703125, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+2, 180407, 1, 5034, 5670, '0', 0, 0, -8341.8076171875, 762.5242919921875, 152.337432861328125, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+3, 180410, 1, 5034, 5670, '0', 0, 0, -8353.4033203125, 790.16668701171875, 152.741455078125, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+4, 180415, 1, 5034, 5670, '0', 0, 0, -8344.8212890625, 802.84375, 152.3376922607421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+5, 180415, 1, 5034, 5670, '0', 0, 0, -8348.2861328125, 799.77081298828125, 152.1962738037109375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+6, 180415, 1, 5034, 5670, '0', 0, 0, -8347.357421875, 800.78125, 151.5987091064453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+7, 180415, 1, 5034, 5670, '0', 0, 0, -8328.39453125, 789.57464599609375, 153.7097015380859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+8, 180426, 1, 5034, 5670, '0', 0, 0, -8357.5380859375, 776.5086669921875, 151.1910400390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+9, 180426, 1, 5034, 5670, '0', 0, 0, -8345.48828125, 778.75177001953125, 152.2094268798828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+10, 180426, 1, 5034, 5670, '0', 0, 0, -8336.654296875, 786.87847900390625, 152.3829803466796875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+11, 180426, 1, 5034, 5670, '0', 0, 0, -8331.03515625, 792.77777099609375, 152.2923126220703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+12, 180427, 1, 5034, 5670, '0', 0, 0, -8347.6318359375, 769.779541015625, 152.0199737548828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+13, 180427, 1, 5034, 5670, '0', 0, 0, -8348.3095703125, 772.295166015625, 151.9667510986328125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+14, 180427, 1, 5034, 5670, '0', 0, 0, -8332.638671875, 784.5555419921875, 152.713165283203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+15, 180453, 1, 5034, 5670, '0', 0, 0, -8323.091796875, 726.4375, -68.7809600830078125, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 46366), -- Hive'Regal Glyphed Crystal (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+16, 180471, 1, 5034, 5670, '0', 0, 0, -8343.2158203125, 805.47393798828125, 153.664886474609375, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+17, 180471, 1, 5034, 5670, '0', 0, 0, -8343.03125, 806.140625, 153.6729736328125, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+18, 180472, 1, 5034, 5670, '0', 0, 0, -8348.7158203125, 801.57293701171875, 154.4049835205078125, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+19, 180523, 1, 5034, 5670, '0', 0, 0, -8333.017578125, 792.58856201171875, 152.48291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Oasis of Vir'sar - Difficulty: 0)
(@OGUID+20, 208178, 1, 5034, 5670, '0', 0, 0, -8327.9931640625, 795.092041015625, 152.361541748046875, 5.044002056121826171, 0, 0, -0.58070278167724609, 0.814115643501281738, 120, 255, 1, 46366); -- Candy Bucket (Area: Oasis of Vir'sar - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+20;
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
(12, @OGUID+20);
