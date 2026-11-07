SET @OGUID := 3005998;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208141; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=208141; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28981;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28981, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208141;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208141, 28981, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208141 AND `quest`=28981);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208141;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 231976 AND 231990;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 231976 AND 231990;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 4815, 5058, '0', 0, 0, -5140.9755859375, 3301.190185546875, -118.638153076171875, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 0, 4815, 5058, '0', 0, 0, -5128.27587890625, 3276.7109375, -118.262252807617187, 4.328419685363769531, 0, 0, -0.82903671264648437, 0.559194147586822509, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 0, 4815, 5058, '0', 0, 0, -5154.8056640625, 3284.842041015625, -118.572822570800781, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+3, 180411, 0, 4815, 5058, '0', 0, 0, -5144.44775390625, 3277.48779296875, -113.983566284179687, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 51886), -- G_Ghost_01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 0, 4815, 5058, '0', 0, 0, -5142.25537109375, 3302.0009765625, -118.863853454589843, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+5, 180415, 0, 4815, 5058, '0', 0, 0, -5142.52978515625, 3302.4140625, -118.856613159179687, 1.815141916275024414, 0, 0, 0.788010597229003906, 0.615661680698394775, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+6, 180415, 0, 4815, 5058, '0', 0, 0, -5145.5400390625, 3289.786376953125, -117.817031860351562, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+7, 180415, 0, 4815, 5058, '0', 0, 0, -5143.34716796875, 3289.389892578125, -111.512001037597656, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+8, 180415, 0, 4815, 5058, '0', 0, 0, -5142.04150390625, 3302.447998046875, -118.633956909179687, 1.884953022003173828, 0, 0, 0.809016227722167968, 0.587786316871643066, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+9, 180415, 0, 4815, 5058, '0', 0, 0, -5141.125, 3290.96875, -115.1085205078125, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+10, 180415, 0, 4815, 5058, '0', 0, 0, -5144.45166015625, 3290.58251953125, -117.813331604003906, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 51886), -- CandleBlack01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+11, 180425, 0, 4815, 5058, '0', 0, 0, -5155.673828125, 3286.34033203125, -118.482032775878906, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 120, 255, 1, 51886), -- SkullCandle01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 0, 4815, 5058, '0', 0, 0, -5145.40283203125, 3286.828125, -118.987159729003906, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 120, 255, 1, 51886), -- Apple Bob (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+13, 185437, 0, 4815, 5058, '0', 0, 0, -5140.75, 3300.479248046875, -118.887657165527343, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 120, 255, 1, 51886), -- Laying Skeleton 01 (Area: Deepmist Grotto - Difficulty: 0) CreateObject1
(@OGUID+14, 208141, 0, 4815, 5058, '0', 0, 0, -5143.12158203125, 3291.525146484375, -119.164093017578125, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 51886); -- Candy Bucket (Area: Deepmist Grotto - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+14;
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
(12, @OGUID+14);
