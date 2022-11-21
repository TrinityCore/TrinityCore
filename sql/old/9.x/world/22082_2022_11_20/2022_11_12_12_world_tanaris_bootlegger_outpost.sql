SET @OGUID := 247992;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208177; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208177; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=29014;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29014, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208177;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208177, 29014, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208177 AND `quest`=29014);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208177;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227793 AND 227828;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227793 AND 227828;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+36;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 440, 5062, '0', 0, 0, -8692.076171875, -4080.00341796875, 40.27819061279296875, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+1, 180406, 1, 440, 5062, '0', 0, 0, -8693.7236328125, -4068.37841796875, 40.42780685424804687, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+2, 180406, 1, 440, 5062, '0', 0, 0, -8694.1630859375, -4088.757080078125, 40.47179794311523437, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+3, 180407, 1, 440, 5062, '0', 0, 0, -8678.435546875, -4041.463623046875, 43.67625808715820312, 0.366517573595046997, 0, 0, 0.182234764099121093, 0.98325502872467041, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+4, 180410, 1, 440, 5062, '0', 0, 0, -8701.1357421875, -4075.017333984375, 41.59624099731445312, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+5, 180415, 1, 440, 5062, '0', 0, 0, -8690.498046875, -4090.579833984375, 41.64896774291992187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+6, 180415, 1, 440, 5062, '0', 0, 0, -8688.3544921875, -4091.260498046875, 41.60406494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+7, 180415, 1, 440, 5062, '0', 0, 0, -8689.4482421875, -4090.354248046875, 41.47544097900390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+8, 180415, 1, 440, 5062, '0', 0, 0, -8695.8681640625, -4088.026123046875, 41.52730941772460937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+9, 180415, 1, 440, 5062, '0', 0, 0, -8692.154296875, -4089.689208984375, 41.11940383911132812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+10, 180415, 1, 440, 5062, '0', 0, 0, -8696.794921875, -4087.295166015625, 40.47179794311523437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+11, 180415, 1, 440, 5062, '0', 0, 0, -8677.2158203125, -4043.017333984375, 43.583343505859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+12, 180415, 1, 440, 5062, '0', 0, 0, -8673.6044921875, -4043.083251953125, 45.49809646606445312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+13, 180415, 1, 440, 5062, '0', 0, 0, -8677.1875, -4039.130126953125, 46.61213302612304687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+14, 180415, 1, 440, 5062, '0', 0, 0, -8675.6474609375, -4041.885498046875, 46.47837448120117187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+15, 180415, 1, 440, 5062, '0', 0, 0, -8681.701171875, -4042.401123046875, 42.83848190307617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+16, 180415, 1, 440, 5062, '0', 0, 0, -8679.7392578125, -4038.104248046875, 44.92335128784179687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+17, 180426, 1, 440, 5062, '0', 0, 0, -8672.158203125, -4066.444580078125, 47.80141448974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+18, 180426, 1, 440, 5062, '0', 0, 0, -8632.685546875, -4053.52783203125, 45.95989990234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+19, 180426, 1, 440, 5062, '0', 0, 0, -8662.7275390625, -4070.640625, 47.48949432373046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+20, 180426, 1, 440, 5062, '0', 0, 0, -8651.70703125, -4065.826416015625, 46.93803024291992187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+21, 180426, 1, 440, 5062, '0', 0, 0, -8646.140625, -4090.225830078125, 42.43922042846679687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+22, 180426, 1, 440, 5062, '0', 0, 0, -8640.1455078125, -4069.569580078125, 43.80381393432617187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+23, 180427, 1, 440, 5062, '0', 0, 0, -8653.4970703125, -4078.657958984375, 38.92481613159179687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+24, 180427, 1, 440, 5062, '0', 0, 0, -8648.25390625, -4081.75, 43.91880416870117187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+25, 180427, 1, 440, 5062, '0', 0, 0, -8646.876953125, -4091.548583984375, 36.0577392578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+26, 180427, 1, 440, 5062, '0', 0, 0, -8655.734375, -4068.36279296875, 41.03221511840820312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+27, 180427, 1, 440, 5062, '0', 0, 0, -8639.2158203125, -4065.73779296875, 37.85643386840820312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+28, 180471, 1, 440, 5062, '0', 0, 0, -8695.658203125, -4067.507080078125, 44.84920120239257812, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+29, 180471, 1, 440, 5062, '0', 0, 0, -8694.0068359375, -4081.013916015625, 45.167572021484375, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+30, 180471, 1, 440, 5062, '0', 0, 0, -8693.4462890625, -4080.09375, 45.180572509765625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+31, 180471, 1, 440, 5062, '0', 0, 0, -8694.904296875, -4068.197998046875, 44.83955764770507812, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+32, 180472, 1, 440, 5062, '0', 0, 0, -8694.2294921875, -4074.15625, 46.11717605590820312, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+33, 180523, 1, 440, 5062, '0', 0, 0, -8698.6826171875, -4084.744873046875, 40.90895462036132812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+34, 208056, 1, 440, 5062, '0', 0, 0, -8706.109375, -4082.12158203125, 44.41543197631835937, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 120, 255, 1, 46366), -- G_Ghost_01 (Scale 0.5) (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+35, 208064, 1, 440, 5062, '0', 0, 0, -8706.7080078125, -4082.40966796875, 43.11758804321289062, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, 46366), -- Web Corner (Area: Bootlegger Outpost - Difficulty: 0)
(@OGUID+36, 208177, 1, 440, 5062, '0', 0, 0, -8702.171875, -4080.111083984375, 40.45697784423828125, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46366); -- Candy Bucket (Area: Bootlegger Outpost - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+36;
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
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36);
