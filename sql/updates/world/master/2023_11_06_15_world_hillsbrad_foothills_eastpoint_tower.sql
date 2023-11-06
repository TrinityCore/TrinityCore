SET @CGUID := 3000244;
SET @OGUID := 3003621;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208145; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208145; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28962;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28962, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208145;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208145, 28962, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208145 AND `quest`=28962);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208145;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 0, 267, 267, '0', 0, 0, 0, 0, -572.05365673828125, -1084.0196533203125, 61.66269692993164062, 1.999523639678955078, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51886); -- Black Cat (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 230358 AND 230380;
DELETE FROM `gameobject` WHERE `guid`=231994;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 230358 AND 230380;
DELETE FROM `game_event_gameobject` WHERE `guid`=231994;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 267, 267, '0', 0, 0, -573.0225830078125, -1055.782958984375, 61.02981948852539062, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 0, 267, 267, '0', 0, 0, -622.02606201171875, -1058.673583984375, 65.68636322021484375, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 0, 267, 267, '0', 0, 0, -573.625, -1095.704833984375, 61.52630615234375, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 0, 267, 267, '0', 0, 0, -573.01739501953125, -1055.75, 62.6433258056640625, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+4, 180411, 0, 267, 267, '0', 0, 0, -616.98614501953125, -1058.6492919921875, 70.426666259765625, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 120, 255, 1, 51886), -- G_Ghost_01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+5, 180414, 0, 267, 267, '0', 0, 0, -576.5850830078125, -1067.4774169921875, 61.83576202392578125, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 51886), -- Cauldron (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+6, 180415, 0, 267, 267, '0', 0, 0, -576.98614501953125, -1071.4583740234375, 63.10279083251953125, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 120, 255, 1, 51886), -- CandleBlack01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+7, 180415, 0, 267, 267, '0', 0, 0, -576.74481201171875, -1071.7100830078125, 62.99906539916992187, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 51886), -- CandleBlack01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+8, 180425, 0, 267, 267, '0', 0, 0, -576.5850830078125, -1071.2725830078125, 63.07996368408203125, 5.864306926727294921, 0, 0, -0.20791149139404296, 0.978147625923156738, 120, 255, 1, 51886), -- SkullCandle01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+9, 180426, 0, 267, 267, '0', 0, 0, -607.5225830078125, -1062.607666015625, 99.010162353515625, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 51886), -- Bat01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+10, 180426, 0, 267, 267, '0', 0, 0, -605.38018798828125, -1064.9271240234375, 98.2997589111328125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+11, 180426, 0, 267, 267, '0', 0, 0, -607.78643798828125, -1064.21533203125, 101.6134033203125, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 51886), -- Bat01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+12, 180427, 0, 267, 267, '0', 0, 0, -604.4757080078125, -1064.017333984375, 87.59879302978515625, 2.635444164276123046, 0, 0, 0.96814727783203125, 0.250381410121917724, 120, 255, 1, 51886), -- Bat02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+13, 180427, 0, 267, 267, '0', 0, 0, -606.1805419921875, -1060.642333984375, 93.02291107177734375, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 120, 255, 1, 51886), -- Bat02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+14, 180427, 0, 267, 267, '0', 0, 0, -605.59027099609375, -1066.34033203125, 85.75673675537109375, 5.724681377410888671, 0, 0, -0.27563667297363281, 0.961261868476867675, 120, 255, 1, 51886), -- Bat02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+15, 180427, 0, 267, 267, '0', 0, 0, -609.42535400390625, -1066.9166259765625, 85.75673675537109375, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 120, 255, 1, 51886), -- Bat02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+16, 180427, 0, 267, 267, '0', 0, 0, -606.41143798828125, -1068.6041259765625, 93.07080841064453125, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 51886), -- Bat02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+17, 180471, 0, 267, 267, '0', 0, 0, -583.28472900390625, -1091.0711669921875, 65.45624542236328125, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+18, 180471, 0, 267, 267, '0', 0, 0, -576.54339599609375, -1096.99658203125, 65.57852935791015625, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+19, 180471, 0, 267, 267, '0', 0, 0, -582.76214599609375, -1097.454833984375, 65.53986358642578125, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+20, 180472, 0, 267, 267, '0', 0, 0, -576.9444580078125, -1090.74658203125, 67.08074951171875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+21, 180523, 0, 267, 267, '0', 0, 0, -576.64581298828125, -1076.890625, 61.94430923461914062, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+22, 185438, 0, 267, 267, '0', 0, 0, -576.48785400390625, -1067.4254150390625, 62.5225982666015625, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 51886), -- Sitting Skeleton 04 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+23, 185454, 0, 267, 267, '0', 0, 0, -573.3125, -1094.91845703125, 61.53342819213867187, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 120, 255, 1, 51886), -- Laying Skeleton 02 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+24, 208070, 0, 267, 267, '0', 0, 0, -617.015625, -1058.6944580078125, 67.40525054931640625, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, 51886), -- Web Hanging Scale 2.0 (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1
(@OGUID+25, 208145, 0, 267, 267, '0', 0, 0, -584.96875, -1080.1771240234375, 65.88028717041015625, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 51886); -- Candy Bucket (Area: Hillsbrad Foothills - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+25;
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
(12, @OGUID+25);
