SET @OGUID := 4800029;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215914; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215895; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215899; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215897; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215898; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=215900; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32051, 32037, 32041, 32039, 32040, 32042);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32051, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32037, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32041, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32039, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32040, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32042, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215914, 215895, 215899, 215897, 215898, 215900);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215914, 32051, 51886),
(215895, 32037, 51886),
(215899, 32041, 51886),
(215897, 32039, 51886),
(215898, 32040, 51886),
(215900, 32042, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215914, 215895, 215899, 215897, 215898, 215900);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215914, 32051, 51886),
(215895, 32037, 51886),
(215899, 32041, 51886),
(215897, 32039, 51886),
(215898, 32040, 51886),
(215900, 32042, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Zouchin Village
(@OGUID+0, 180405, 870, 5841, 6169, '0', 0, 0, 4383.5224609375, 932.71875, 106.7772979736328125, 5.07132577896118164, 0, 0, -0.56952667236328125, 0.821972846984863281, 120, 255, 1, 57388), -- G_Pumpkin_01 (Area: Zouchin Village - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 870, 5841, 6169, '0', 0, 0, 4387.26904296875, 926.31597900390625, 106.1873626708984375, 0, 0, 0, 0, 1, 120, 255, 1, 57388), -- G_Pumpkin_02 (Area: Zouchin Village - Difficulty: 0) CreateObject1
(@OGUID+2, 215914, 870, 5841, 6169, '0', 0, 0, 4412.62744140625, 928.04339599609375, 115.977783203125, 3.247434854507446289, 0, 0, -0.99860000610351562, 0.052896320819854736, 120, 255, 1, 51886), -- Candy Bucket (Area: Zouchin Village - Difficulty: 0) CreateObject1
-- One Keg
(@OGUID+3, 180405, 870, 5841, 6085, '0', 0, 0, 3103.8759765625, 1241.9617919921875, 654.09307861328125, 0.088312231004238128, 0, 0, 0.044141769409179687, 0.999025285243988037, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: One Keg - Difficulty: 0) CreateObject1
(@OGUID+4, 215895, 870, 5841, 6085, '0', 0, 0, 3117.15625, 1244.1041259765625, 654.82440185546875, 6.008471012115478515, 0, 0, -0.13692569732666015, 0.990581333637237548, 120, 255, 1, 51886), -- Candy Bucket (Area: One Keg - Difficulty: 0) CreateObject1
-- The Grummle Bazaar
(@OGUID+5, 180405, 870, 5841, 6079, '0', 0, 0, 3074.825439453125, 791.6788330078125, 527.47979736328125, 4.247609138488769531, 0, 0, -0.85094833374023437, 0.525249421596527099, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Grummle Bazaar - Difficulty: 0) CreateObject1
(@OGUID+6, 180406, 870, 5841, 6079, '0', 0, 0, 3060.762939453125, 807.52081298828125, 529.3128662109375, 1.325608491897583007, 0, 0, 0.615329742431640625, 0.78826981782913208, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Grummle Bazaar - Difficulty: 0) CreateObject1
(@OGUID+7, 215899, 870, 5841, 6079, '0', 0, 0, 3061.89404296875, 820.98614501953125, 529.95404052734375, 1.538253307342529296, 0, 0, 0.695508003234863281, 0.718518316745758056, 120, 255, 1, 51886), -- Candy Bucket (Area: The Grummle Bazaar - Difficulty: 0) CreateObject1
-- Binan Village
(@OGUID+8, 180405, 870, 5841, 6059, '0', 0, 0, 1768.361083984375, 283.973968505859375, 481.908355712890625, 0.741004049777984619, 0, 0, 0.36208343505859375, 0.93214571475982666, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Binan Village - Difficulty: 0) CreateObject1
(@OGUID+9, 180406, 870, 5841, 6059, '0', 0, 0, 1776.6632080078125, 304.5382080078125, 481.88916015625, 3.284161090850830078, 0, 0, -0.99746036529541015, 0.071223817765712738, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Binan Village - Difficulty: 0) CreateObject1
(@OGUID+10, 215897, 870, 5841, 6059, '0', 0, 0, 1767.998291015625, 287.796875, 482.04925537109375, 2.388510704040527343, 0, 0, 0.929942131042480468, 0.367705941200256347, 120, 255, 1, 51886), -- Candy Bucket (Area: Binan Village - Difficulty: 0) CreateObject1
-- Eastwind Rest
(@OGUID+11, 180405, 870, 5841, 6094, '0', 812, 0, 2279.14404296875, 912.0711669921875, 488.42724609375, 3.521411657333374023, 0, 0, -0.98202133178710937, 0.18876996636390686, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Eastwind Rest - Difficulty: 0) CreateObject1
(@OGUID+12, 180406, 870, 5841, 6094, '0', 812, 0, 2264.5556640625, 913.013916015625, 488.064788818359375, 3.341678857803344726, 0, 0, -0.99499988555908203, 0.099876195192337036, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Eastwind Rest - Difficulty: 0) CreateObject1
(@OGUID+13, 215898, 870, 5841, 6094, '0', 812, 0, 2259.717041015625, 911.09722900390625, 481.148590087890625, 4.035845756530761718, 0, 0, -0.90169334411621093, 0.43237614631652832, 120, 255, 1, 51886), -- Candy Bucket (Area: Eastwind Rest - Difficulty: 0) CreateObject1
-- Westwind Rest
(@OGUID+14, 180405, 870, 5841, 6095, '0', 812, 0, 2159.859375, 1458.6805419921875, 494.779296875, 5.523334026336669921, 0, 0, -0.37085151672363281, 0.928692162036895751, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Westwind Rest - Difficulty: 0) CreateObject1
(@OGUID+15, 215900, 870, 5841, 6095, '0', 812, 0, 2162.932373046875, 1455.6336669921875, 487.885589599609375, 6.124776840209960937, 0, 0, -0.07912158966064453, 0.996864974498748779, 120, 255, 1, 51886); -- Candy Bucket (Area: Westwind Rest - Difficulty: 0) CreateObject1

UPDATE `gameobject` SET `phaseUseFlags`=1 WHERE `id` IN (215914);

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+15;
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
(12, @OGUID+15);
