SET @CGUID := 3000246;
SET @OGUID := 3004024;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208136; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208136; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28990;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28990, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208136;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208136, 28990, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208136 AND `quest`=28990);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208136;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 0, 11, 5304, '0', 0, 0, 0, 0, -2870.8140625, -1486.9669189453125, 9.818784332275390625, 4.822881221771240234, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51886); -- Black Cat (Area: Swiftgear Station - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+46;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 11, 5304, '0', 0, 0, -2871.520751953125, -1475.826416015625, 10.35446643829345703, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 0, 11, 5304, '0', 0, 0, -2863.147705078125, -1489.1754150390625, 10.36012172698974609, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 0, 11, 5304, '0', 0, 0, -2887.572998046875, -1500.888916015625, 10.53237438201904296, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 0, 11, 5304, '0', 0, 0, -2871.435791015625, -1475.80908203125, 11.98334980010986328, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 0, 11, 5304, '0', 0, 0, -2868.685791015625, -1509.7760009765625, 14.44237422943115234, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+5, 180415, 0, 11, 5304, '0', 0, 0, -2862.513916015625, -1518.3472900390625, 14.45221614837646484, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+6, 180415, 0, 11, 5304, '0', 0, 0, -2880.203125, -1491.095458984375, 11.87953567504882812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+7, 180415, 0, 11, 5304, '0', 0, 0, -2867.8525390625, -1522.3489990234375, 14.44019603729248046, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+8, 180415, 0, 11, 5304, '0', 0, 0, -2880.5869140625, -1479.3125, 12.23726844787597656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+9, 180415, 0, 11, 5304, '0', 0, 0, -2863.272705078125, -1512.657958984375, 14.44959831237792968, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+10, 180415, 0, 11, 5304, '0', 0, 0, -2877.557373046875, -1480, 11.96598625183105468, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 0, 11, 5304, '0', 0, 0, -2874.010498046875, -1513.439208984375, 14.44103813171386718, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+12, 180415, 0, 11, 5304, '0', 0, 0, -2881.38720703125, -1486.109375, 11.737091064453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+13, 180415, 0, 11, 5304, '0', 0, 0, -2879.092041015625, -1488.2379150390625, 11.72139739990234375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+14, 180415, 0, 11, 5304, '0', 0, 0, -2873.380126953125, -1519.34375, 14.45655536651611328, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+15, 180415, 0, 11, 5304, '0', 0, 0, -2851.666748046875, -1484.0711669921875, 11.46669292449951171, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+16, 180415, 0, 11, 5304, '0', 0, 0, -2874.710205078125, -1480.578125, 11.8100128173828125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+17, 180415, 0, 11, 5304, '0', 0, 0, -2860.548583984375, -1473.857666015625, 12.30389690399169921, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+18, 180415, 0, 11, 5304, '0', 0, 0, -2854.517333984375, -1486.359375, 11.2798776626586914, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+19, 180415, 0, 11, 5304, '0', 0, 0, -2864.932373046875, -1473.5208740234375, 12.31827831268310546, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+20, 180415, 0, 11, 5304, '0', 0, 0, -2860.64404296875, -1475.09375, 11.71836280822753906, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+21, 180415, 0, 11, 5304, '0', 0, 0, -2872.654541015625, -1478.0677490234375, 11.818939208984375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+22, 180415, 0, 11, 5304, '0', 0, 0, -2862.380126953125, -1487.28125, 11.5845956802368164, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+23, 180415, 0, 11, 5304, '0', 0, 0, -2865, -1474.7379150390625, 11.74198341369628906, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+24, 180415, 0, 11, 5304, '0', 0, 0, -2859.223876953125, -1486.8802490234375, 11.61402606964111328, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+25, 180426, 0, 11, 5304, '0', 0, 0, -2892.838623046875, -1496.1822509765625, 12.88392925262451171, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+26, 180426, 0, 11, 5304, '0', 0, 0, -2879.94091796875, -1492.217041015625, 10.54752254486083984, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+27, 180426, 0, 11, 5304, '0', 0, 0, -2844.62158203125, -1494.5242919921875, 10.80093860626220703, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+28, 180427, 0, 11, 5304, '0', 0, 0, -2886.838623046875, -1496.5694580078125, 10.93411159515380859, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+29, 180427, 0, 11, 5304, '0', 0, 0, -2892.541748046875, -1499.8836669921875, 10.63610267639160156, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+30, 180427, 0, 11, 5304, '0', 0, 0, -2841.208251953125, -1500.107666015625, 9.833813667297363281, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+31, 180471, 0, 11, 5304, '0', 0, 0, -2862.939208984375, -1502.0504150390625, 13.86891746520996093, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+32, 180471, 0, 11, 5304, '0', 0, 0, -2862.94970703125, -1501.3350830078125, 13.84463977813720703, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+33, 180471, 0, 11, 5304, '0', 0, 0, -2857.947998046875, -1496.0208740234375, 13.79524612426757812, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+34, 180471, 0, 11, 5304, '0', 0, 0, -2858.76904296875, -1473.578125, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+35, 180471, 0, 11, 5304, '0', 0, 0, -2861.322998046875, -1473.375, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+36, 180471, 0, 11, 5304, '0', 0, 0, -2866.859375, -1472.98095703125, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+37, 180471, 0, 11, 5304, '0', 0, 0, -2858.541748046875, -1496.032958984375, 13.80309104919433593, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+38, 180471, 0, 11, 5304, '0', 0, 0, -2865.7587890625, -1473.045166015625, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+39, 180471, 0, 11, 5304, '0', 0, 0, -2864.49658203125, -1473.0555419921875, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+40, 180471, 0, 11, 5304, '0', 0, 0, -2860.010498046875, -1473.4444580078125, 16.10841751098632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+41, 180472, 0, 11, 5304, '0', 0, 0, -2862.8369140625, -1473.1910400390625, 16.86874008178710937, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+42, 180523, 0, 11, 5304, '0', 0, 0, -2859.296875, -1470.263916015625, 12.07879161834716796, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+43, 185434, 0, 11, 5304, '0', 0, 0, -2865.798583984375, -1474.7899169921875, 10.15371227264404296, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 51886), -- Sitting Skeleton 01 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+44, 185436, 0, 11, 5304, '0', 0, 0, -2868.145751953125, -1474.3629150390625, 10.193450927734375, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 120, 255, 1, 51886), -- Sitting Skeleton 03 (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+45, 208088, 0, 11, 5304, '0', 0, 0, -2867.85595703125, -1474.970458984375, 10.71336174011230468, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 51886), -- Web Wide (Scale 0.5) (Area: Swiftgear Station - Difficulty: 0) CreateObject1
(@OGUID+46, 208136, 0, 11, 5304, '0', 0, 0, -2864.1494140625, -1467.638916015625, 11.66132831573486328, 0.24434557557106018, 0, 0, 0.121869087219238281, 0.9925462007522583, 120, 255, 1, 51886); -- Candy Bucket (Area: Swiftgear Station - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+46;
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
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46);
