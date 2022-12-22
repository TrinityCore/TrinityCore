SET @OGUID := 248029;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208180; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208180; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=29018;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29018, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208180;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208180, 29018, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208180 AND `quest`=29018);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208180;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 227829 AND 227862;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 227829 AND 227862;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+34;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 490, 4882, '0', 0, 0, -7553.1943359375, -1551.6146240234375, -270.35931396484375, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+1, 180405, 1, 490, 4882, '0', 0, 0, -7500.6875, -1525.6197509765625, -262.427825927734375, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+2, 180405, 1, 490, 4882, '0', 0, 0, -7510.23974609375, -1484.720458984375, -263.798004150390625, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+3, 180406, 1, 490, 4882, '0', 0, 0, -7531.7412109375, -1540.6319580078125, -270.43572998046875, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+4, 180406, 1, 490, 4882, '0', 0, 0, -7484.546875, -1514.5833740234375, -261.67718505859375, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+5, 180406, 1, 490, 4882, '0', 0, 0, -7498.38037109375, -1488.513916015625, -265.22161865234375, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+6, 180407, 1, 490, 4882, '0', 0, 0, -7507.001953125, -1524.717041015625, -265.499420166015625, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+7, 180407, 1, 490, 4882, '0', 0, 0, -7488.048828125, -1501.9410400390625, -265.885498046875, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+8, 180410, 1, 490, 4882, '0', 0, 0, -7500.875, -1513.9149169921875, -264.225433349609375, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+9, 180415, 1, 490, 4882, '0', 0, 0, -7530.51220703125, -1537.576416015625, -270.441497802734375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+10, 180415, 1, 490, 4882, '0', 0, 0, -7531.38916015625, -1520.204833984375, -269.112213134765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+11, 180415, 1, 490, 4882, '0', 0, 0, -7534.705078125, -1542.263916015625, -270.442047119140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+12, 180415, 1, 490, 4882, '0', 0, 0, -7541.4375, -1553.77783203125, -270.13531494140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+13, 180415, 1, 490, 4882, '0', 0, 0, -7539.52587890625, -1528.4757080078125, -270.6669921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+14, 180415, 1, 490, 4882, '0', 0, 0, -7535.02099609375, -1524.07470703125, -269.573638916015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+15, 180415, 1, 490, 4882, '0', 0, 0, -7532.14404296875, -1543.157958984375, -270.195587158203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+16, 180415, 1, 490, 4882, '0', 0, 0, -7539.26220703125, -1548.7847900390625, -270.30206298828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+17, 180415, 1, 490, 4882, '0', 0, 0, -7529.22216796875, -1540.795166015625, -270.32806396484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+18, 180415, 1, 490, 4882, '0', 0, 0, -7537.001953125, -1544.7742919921875, -270.39398193359375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+19, 180426, 1, 490, 4882, '0', 0, 0, -7536.08837890625, -1539.6319580078125, -270.484130859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+20, 180426, 1, 490, 4882, '0', 0, 0, -7501.50341796875, -1504.673583984375, -263.64105224609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+21, 180426, 1, 490, 4882, '0', 0, 0, -7516, -1537.2899169921875, -268.865447998046875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+22, 180426, 1, 490, 4882, '0', 0, 0, -7515.27587890625, -1504.204833984375, -258.301239013671875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+23, 180426, 1, 490, 4882, '0', 0, 0, -7502.1494140625, -1498.4930419921875, -263.44427490234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+24, 180426, 1, 490, 4882, '0', 0, 0, -7494.421875, -1494.2603759765625, -263.35736083984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+25, 180426, 1, 490, 4882, '0', 0, 0, -7502.8505859375, -1501.267333984375, -263.51947021484375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+26, 180427, 1, 490, 4882, '0', 0, 0, -7527.4130859375, -1523.8663330078125, -269.178466796875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+27, 180427, 1, 490, 4882, '0', 0, 0, -7527.64404296875, -1535.4791259765625, -270.324462890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+28, 180427, 1, 490, 4882, '0', 0, 0, -7501.4912109375, -1504.2882080078125, -266.2427978515625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+29, 180427, 1, 490, 4882, '0', 0, 0, -7515.73095703125, -1535.62158203125, -268.985748291015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+30, 180427, 1, 490, 4882, '0', 0, 0, -7512.30224609375, -1495.3785400390625, -265.634429931640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+31, 180471, 1, 490, 4882, '0', 0, 0, -7513.00341796875, -1500.9947509765625, -262.97137451171875, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+32, 180471, 1, 490, 4882, '0', 0, 0, -7513.27099609375, -1507.8941650390625, -262.9488525390625, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+33, 180523, 1, 490, 4882, '0', 0, 0, -7505.953125, -1510.8819580078125, -265.58953857421875, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 46366), -- Apple Bob (Area: Marshal's Stand - Difficulty: 0)
(@OGUID+34, 208180, 1, 490, 4882, '0', 0, 0, -7498.859375, -1511.48095703125, -266.102935791015625, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 46366); -- Candy Bucket (Area: Marshal's Stand - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+34;
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
(12, @OGUID+34);
