SET @OGUID := 9003523;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (401748, 401749, 401750, 401751);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(401748, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26294, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401749, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401750, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401751, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (401748, 401749, 401750, 401751);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(401748, 35, 4, 0, 0), -- Candy Bucket
(401749, 35, 4, 0, 0), -- Candy Bucket
(401750, 35, 4, 0, 0), -- Candy Bucket
(401751, 35, 4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (75695, 75696, 75697, 75698);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75695, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75696, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75697, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75698, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (401748, 401749, 401750, 401751);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(401748, 75695, 51886),
(401749, 75696, 51886),
(401750, 75697, 51886),
(401751, 75698, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (401748, 401749, 401750, 401751);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(401748, 75695, 51886),
(401749, 75696, 51886),
(401750, 75697, 51886),
(401751, 75698, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Algeth'era Court
(@OGUID+0, 180405, 2444, 13647, 13873, '0', 0, 0, 1310.5677490234375, -1944.8160400390625, 520.36663818359375, 1.39971017837524414, 0, 0, 0.644106864929199218, 0.764935493469238281, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2444, 13647, 13873, '0', 0, 0, 1313.6041259765625, -1941.6910400390625, 520.4713134765625, 0.925874292850494384, 0, 0, 0.446578025817871093, 0.894744694232940673, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2444, 13647, 13873, '0', 0, 0, 1310.2239990234375, -1941.611083984375, 520.4713134765625, 1.273770332336425781, 0, 0, 0.594694137573242187, 0.803952038288116455, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2444, 13647, 13873, '0', 0, 0, 1316.63720703125, -1944.30908203125, 520.6090087890625, 5.917185783386230468, 0, 0, -0.18198013305664062, 0.983302235603332519, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2444, 13647, 13873, '0', 0, 0, 1354.1632080078125, -1989.2691650390625, 519.24981689453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2444, 13647, 13873, '0', 0, 0, 1313.38720703125, -1944.9879150390625, 520.36663818359375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
(@OGUID+6, 401751, 2444, 13647, 13873, '0', 0, 0, 1321.8646240234375, -1951.6163330078125, 521.42132568359375, 0.34250536561012268, 0, 0, 0.170416831970214843, 0.985372066497802734, 120, 255, 1, 51886), -- Candy Bucket (Area: Steelcliff Passage - Difficulty: 0) CreateObject1
-- Gelikyr Post
(@OGUID+7, 180405, 2444, 13647, 0, '0', 0, 0, -463.861114501953125, -2188.657958984375, 1028.0235595703125, 2.625766754150390625, -0.11681652069091796, -0.01913261413574218, 0.961453437805175781, 0.248183682560920715, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2444, 13647, 0, '0', 0, 0, -463.916656494140625, -2179.470458984375, 1027.6673583984375, 1.910449147224426269, 0, 0, 0.816443443298339843, 0.57742542028427124, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2444, 13647, 0, '0', 0, 0, -485.017364501953125, -2203.47216796875, 1033.185302734375, 4.091075420379638671, 0, 0, -0.88941097259521484, 0.45710843801498413, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2444, 13647, 0, '0', 0, 0, -464.076385498046875, -2179.43408203125, 1029.263427734375, 1.482237577438354492, 0, 0, 0.675113677978515625, 0.73771369457244873, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2444, 13647, 0, '0', 0, 0, -506.416656494140625, -2190.036376953125, 1031.6568603515625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2444, 13647, 0, '0', 0, 0, -501.696197509765625, -2182.80029296875, 1030.4566650390625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+13, 401750, 2444, 13647, 0, '0', 0, 0, -506.133697509765625, -2186.798583984375, 1031.627197265625, 1.31940460205078125, 0, 0, 0.612881660461425781, 0.790174722671508789, 120, 255, 1, 51886), -- Candy Bucket (Area: 0 - Difficulty: 0) CreateObject1
-- Garden Shrine
(@OGUID+14, 180405, 2444, 13647, 13812, '0', 0, 0, -1138.3785400390625, -429.25, 1012.46588134765625, 6.133885860443115234, -0.0401010513305664, 0.1113739013671875, -0.06881332397460937, 0.990581870079040527, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+15, 180406, 2444, 13647, 13812, '0', 0, 0, -1140.6978759765625, -425.795135498046875, 1011.91357421875, 5.620652198791503906, 0, 0, -0.3252410888671875, 0.945631086826324462, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+16, 180407, 2444, 13647, 13812, '0', 0, 0, -1144.46533203125, -447.376739501953125, 1009.8446044921875, 6.102730751037597656, 0, 0, -0.09010505676269531, 0.995932281017303466, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+17, 180408, 2444, 13647, 13812, '0', 0, 0, -1139.21533203125, -430.401031494140625, 1020.273681640625, 0.045608066022396087, -0.31864070892333984, -0.11713314056396484, -0.01609992980957031, 0.940472602844238281, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+18, 180415, 2444, 13647, 13812, '0', 0, 0, -1143.8228759765625, -426.0225830078125, 1011.3751220703125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+19, 180523, 2444, 13647, 13812, '0', 0, 0, -1132.625, -430.19097900390625, 1009.78680419921875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Gardens of Unity - Difficulty: 0) CreateObject1
(@OGUID+20, 401749, 2444, 13647, 13812, '0', 0, 0, -1140.1146240234375, -433.015625, 1009.78680419921875, 5.662631034851074218, 0, 0, -0.30532264709472656, 0.952248990535736083, 120, 255, 1, 51886), -- Candy Bucket (Area: Gardens of Unity - Difficulty: 0) CreateObject1
-- Temporal Conflux
(@OGUID+21, 180405, 2444, 13647, 13818, '0', 0, 0, -1376.29345703125, -2939.907958984375, 1181.672607421875, 2.051589012145996093, 0, 0, 0.855126380920410156, 0.518419623374938964, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+22, 180406, 2444, 13647, 13818, '0', 0, 0, -1376.0538330078125, -2933.28466796875, 1181.655029296875, 1.853142142295837402, 0, 0, 0.799565315246582031, 0.600579142570495605, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+23, 180407, 2444, 13647, 13818, '0', 0, 0, -1384.77783203125, -2952.833251953125, 1174.5445556640625, 2.338095664978027343, 0, 0, 0.920378684997558593, 0.391028225421905517, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+24, 180408, 2444, 13647, 13818, '0', 0, 0, -1380.7708740234375, -2936.536376953125, 1187.302001953125, 1.816532850265502929, 0.017452716827392578, 0.003826141357421875, 0.788409233093261718, 0.614891588687896728, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+25, 180415, 2444, 13647, 13818, '0', 0, 0, -1374.8472900390625, -2931.673583984375, 1176.301025390625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+26, 180523, 2444, 13647, 13818, '0', 0, 0, -1382.54345703125, -2950.185791015625, 1174.5167236328125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Temporal Conflux - Difficulty: 0) CreateObject1
(@OGUID+27, 401748, 2444, 13647, 13818, '0', 0, 0, -1375.3367919921875, -2941.20654296875, 1174.4007568359375, 2.218640565872192382, 0, 0, 0.895396232604980468, 0.445270270109176635, 120, 255, 1, 51886); -- Candy Bucket (Area: Temporal Conflux - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+27;
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
(12, @OGUID+27);
