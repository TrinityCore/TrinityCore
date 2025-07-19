SET @OGUID := 4800000;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215908; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215881; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=215907; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=215891; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215886; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215874; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215884; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215880; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215889; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32028, 32050, 32049, 32033, 32031, 32021, 32029, 32027, 32032);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32028, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32050, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32049, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32033, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32031, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32021, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32029, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32027, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32032, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215908, 215881, 215907, 215891, 215886, 215874, 215884, 215880, 215889);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215908, 32050, 51886),
(215881, 32028, 51886),
(215907, 32049, 51886),
(215891, 32033, 51886),
(215886, 32031, 51886),
(215874, 32021, 51886),
(215884, 32029, 51886),
(215880, 32027, 51886),
(215889, 32032, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215908, 215881, 215907, 215891, 215886, 215874, 215884, 215880, 215889);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215908, 32050, 51886),
(215881, 32028, 51886),
(215907, 32049, 51886),
(215891, 32033, 51886),
(215886, 32031, 51886),
(215874, 32021, 51886),
(215884, 32029, 51886),
(215880, 32027, 51886),
(215889, 32032, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Honeydew Village
(@OGUID+0, 180405, 870, 5785, 6521, '0', 0, 0, 3027.47998046875, -545.375, 248.4290924072265625, 0.853257358074188232, 0, 0, 0.413804054260253906, 0.910365998744964599, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Honeydew Village - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 870, 5785, 6521, '0', 0, 0, 3044.9306640625, -548.138916015625, 251.181854248046875, 5.71202850341796875, 0, 0, -0.28171253204345703, 0.959498822689056396, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Honeydew Village - Difficulty: 0) CreateObject1
(@OGUID+2, 215908, 870, 5785, 6521, '0', 0, 0, 3034.632080078125, -534.69268798828125, 249.027130126953125, 6.114505767822265625, 0, 0, -0.08423995971679687, 0.996445536613464355, 120, 255, 1, 51886), -- Candy Bucket (Area: Honeydew Village - Difficulty: 0) CreateObject1
-- Grookin Hill
(@OGUID+3, 180405, 870, 5785, 5950, '0', 0, 0, 1451.736083984375, -499.739593505859375, 350.0029296875, 2.117774486541748046, 0, 0, 0.8718109130859375, 0.489842534065246582, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Grookin Hill - Difficulty: 0) CreateObject1
(@OGUID+4, 180406, 870, 5785, 5950, '0', 0, 0, 1453.0086669921875, -504.420135498046875, 350.51580810546875, 1.805949091911315917, 0, 0, 0.785172462463378906, 0.619277179241180419, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Grookin Hill - Difficulty: 0) CreateObject1
(@OGUID+5, 215881, 870, 5785, 5950, '0', 0, 0, 1446.7274169921875, -504.3194580078125, 350.65362548828125, 4.038747787475585937, 0, 0, -0.90106487274169921, 0.433684319257736206, 120, 255, 1, 51886), -- Candy Bucket (Area: Grookin Hill - Difficulty: 0) CreateObject1
-- Paw'don Village
(@OGUID+6, 180405, 870, 5785, 6516, '0', 0, 0, -285.21875, -1685.3836669921875, 53.10683822631835937, 4.719578742980957031, 0, 0, -0.7045602798461914, 0.709644138813018798, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Paw'don Village - Difficulty: 0) CreateObject1
(@OGUID+7, 180406, 870, 5785, 6516, '0', 0, 0, -304.4913330078125, -1686.579833984375, 55.13893508911132812, 5.630909919738769531, 0, 0, -0.32038688659667968, 0.947286784648895263, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Paw'don Village - Difficulty: 0) CreateObject1
(@OGUID+8, 180407, 870, 5785, 6516, '0', 0, 0, -300.12847900390625, -1698.9461669921875, 55.05644607543945312, 5.217189788818359375, 0, 0, -0.50811767578125, 0.861287653446197509, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Paw'don Village - Difficulty: 0) CreateObject1
(@OGUID+9, 215907, 870, 5785, 6516, '0', 0, 0, -274.48089599609375, -1676.71875, 54.34387588500976562, 4.343193531036376953, 0, 0, -0.82488346099853515, 0.565302789211273193, 120, 255, 1, 51886), -- Candy Bucket (Area: Paw'don Village - Difficulty: 0) CreateObject1
-- Pearlfin Village
(@OGUID+10, 180406, 870, 5785, 5935, '0', 0, 0, -224.060760498046875, -2702.5625, 6.246363162994384765, 3.876449346542358398, 0, 0, -0.93325424194335937, 0.359216570854187011, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Pearlfin Village - Difficulty: 0) CreateObject1
(@OGUID+11, 180407, 870, 5785, 5935, '0', 0, 0, -220.522567749023437, -2699.5087890625, 6.246256351470947265, 4.65674591064453125, 0, 0, -0.72650337219238281, 0.68716287612915039, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Pearlfin Village - Difficulty: 0) CreateObject1
(@OGUID+12, 215891, 870, 5785, 5935, '0', 0, 0, -222.213546752929687, -2707.342041015625, 5.287766456604003906, 1.462426543235778808, 0, 0, 0.667773246765136718, 0.744364738464355468, 120, 255, 1, 51886), -- Candy Bucket (Area: Pearlfin Village - Difficulty: 0) CreateObject1
-- Sri-La Village
(@OGUID+13, 180405, 870, 5785, 6077, '0', 0, 0, 2529.02001953125, -2438.507080078125, 30.48642921447753906, 2.415773391723632812, 0, 0, 0.93486785888671875, 0.354995906352996826, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Sri-La Village - Difficulty: 0) CreateObject1
(@OGUID+14, 180406, 870, 5785, 6077, '0', 0, 0, 2509.279541015625, -2449.35595703125, 30.50494003295898437, 0.05703173205256462, 0, 0, 0.028512001037597656, 0.99959343671798706, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Sri-La Village - Difficulty: 0) CreateObject1
(@OGUID+15, 180407, 870, 5785, 6077, '0', 0, 0, 2535.1181640625, -2429.064208984375, 25.25320816040039062, 2.41216588020324707, 0, 0, 0.934226036071777343, 0.356681525707244873, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Sri-La Village - Difficulty: 0) CreateObject1
(@OGUID+16, 215886, 870, 5785, 6077, '0', 0, 0, 2516.091064453125, -2438.598876953125, 30.62947273254394531, 0.407998234033584594, 0, 0, 0.202587127685546875, 0.979264259338378906, 120, 255, 1, 51886), -- Candy Bucket (Area: Sri-La Village - Difficulty: 0) CreateObject1
-- Tian Monastery
(@OGUID+17, 180406, 870, 5785, 5855, '0', 0, 0, 2564.1103515625, -1450.5555419921875, 406.114715576171875, 5.028661251068115234, 0, 0, -0.5869302749633789, 0.809637427330017089, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Tian Monastery - Difficulty: 0) CreateObject1
(@OGUID+18, 180407, 870, 5785, 5855, '0', 0, 0, 2563.837646484375, -1457.34033203125, 406.114715576171875, 5.545736312866210937, 0, 0, -0.36042594909667968, 0.932787835597991943, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Tian Monastery - Difficulty: 0) CreateObject1
(@OGUID+19, 215874, 870, 5785, 5855, '0', 0, 0, 2575.194580078125, -1458.7899169921875, 407.125457763671875, 1.15843665599822998, 0, 0, 0.547369956970214843, 0.836890757083892822, 120, 255, 1, 51886), -- Candy Bucket (Area: Tian Monastery - Difficulty: 0) CreateObject1
-- Greenstone Village
(@OGUID+20, 180405, 870, 5785, 6204, '0', 0, 0, 2030.5035400390625, -1908.6353759765625, 207.2750701904296875, 5.603698253631591796, 0, 0, -0.33324527740478515, 0.942840158939361572, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Greenstone Village - Difficulty: 0) CreateObject1
(@OGUID+21, 180406, 870, 5785, 6204, '0', 0, 0, 2031.18408203125, -1915.4600830078125, 207.2750701904296875, 4.800759315490722656, 0, 0, -0.67518329620361328, 0.737649977207183837, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Greenstone Village - Difficulty: 0) CreateObject1
(@OGUID+22, 215884, 870, 5785, 6204, '0', 0, 0, 2040.9913330078125, -1906.060791015625, 208.3611602783203125, 4.457337379455566406, 0, 0, -0.79129505157470703, 0.611434459686279296, 120, 255, 1, 51886), -- Candy Bucket (Area: Greenstone Village - Difficulty: 0) CreateObject1
-- Dawn's Blossom
(@OGUID+23, 180405, 870, 5785, 5930, '0', 0, 0, 1611.484375, -1771.1441650390625, 262.46990966796875, 5.492883205413818359, 0, 0, -0.38494777679443359, 0.922938346862792968, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Dawn's Blossom - Difficulty: 0) CreateObject1
(@OGUID+24, 180407, 870, 5785, 5930, '0', 0, 0, 1603.4254150390625, -1768.092041015625, 262.470367431640625, 0.754918634891510009, 0, 0, 0.368559837341308593, 0.929603993892669677, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Dawn's Blossom - Difficulty: 0) CreateObject1
(@OGUID+25, 215880, 870, 5785, 5930, '0', 0, 0, 1622.6180419921875, -1744.1458740234375, 263.273345947265625, 0.090973749756813049, 0, 0, 0.04547119140625, 0.998965680599212646, 120, 255, 1, 51886), -- Candy Bucket (Area: Dawn's Blossom - Difficulty: 0) CreateObject1
-- Jade Temple Grounds
(@OGUID+26, 180405, 870, 5785, 5974, '0', 0, 0, 706.717041015625, -2371.65625, 83.56427001953125, 0.815378725528717041, 0, 0, 0.396489143371582031, 0.918039381504058837, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Jade Temple Grounds - Difficulty: 0) CreateObject1
(@OGUID+27, 180406, 870, 5785, 5974, '0', 0, 0, 713.654541015625, -2371.288330078125, 83.56427001953125, 0.086674161255359649, 0, 0, 0.043323516845703125, 0.999061107635498046, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Jade Temple Grounds - Difficulty: 0) CreateObject1
(@OGUID+28, 215889, 870, 5785, 5974, '0', 0, 0, 704.72052001953125, -2361.029541015625, 84.81015777587890625, 6.081630706787109375, 0, 0, -0.10060691833496093, 0.994926273822784423, 120, 255, 1, 51886); -- Candy Bucket (Area: Jade Temple Grounds - Difficulty: 0) CreateObject1

UPDATE `gameobject` SET `phaseUseFlags`=1 WHERE `id` IN (215908);

-- Event spawns
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
