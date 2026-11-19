SET @OGUID := 10800375;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (464923, 464924, 464925);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(464923, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27773, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464924, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27774, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464925, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27775, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (464923, 464924, 464925);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(464925, 35, 0x4, 0, 0), -- Candy Bucket
(464924, 35, 0x4, 0, 0), -- Candy Bucket
(464923, 35, 0x4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (84576, 84577, 84578);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84576, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84577, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84578, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (464923, 464924, 464925);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(464923, 84576, 57212),
(464924, 84577, 57212),
(464925, 84578, 57212);

DELETE FROM `gameobject_questender` WHERE `id` IN (464923, 464924, 464925);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(464923, 84576, 57212),
(464924, 84577, 57212),
(464925, 84578, 57212);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+23;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Umbral Bazzar
(@OGUID+0, 180405, 2601, 14753, 14791, '0', 0, 0, -1778.5660400390625, -913.5555419921875, -1242.5491943359375, 5.65765237808227539, 0.015139579772949218, 0.01043701171875, -0.30779552459716796, 0.951274812221527099, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2601, 14753, 14791, '0', 0, 0, -1795.9896240234375, -928.828125, -1242.05517578125, 0.703214287757873535, 0, 0, 0.344407081604003906, 0.938820421695709228, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2601, 14753, 14791, '0', 0, 0, -1789.2586669921875, -913.69097900390625, -1242.5426025390625, 0.732989370822906494, -0.00004053115844726, 0.011440277099609375, 0.358281135559082031, 0.933543682098388671, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2601, 14753, 14791, '0', 0, 0, -1796, -928.77777099609375, -1240.632568359375, 0.372776746749877929, 0.001995563507080078, 0.029156684875488281, 0.185027122497558593, 0.982298791408538818, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2601, 14753, 14791, '0', 0, 0, -1784.62158203125, -882.90277099609375, -1241.0360107421875, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+5, 180415, 2601, 14752, 14766, '0', 0, 0, -1783.842041015625, -883.0225830078125, -1241.0074462890625, 6.229013919830322265, 0, 0, -0.02708244323730468, 0.999633193016052246, 120, 255, 1, 57212), -- CandleBlack01 (Area: Wildcamp Ul'ar - Difficulty: 0) CreateObject1
(@OGUID+6, 180523, 2601, 14752, 14766, '0', 0, 0, -1767.888916015625, -888.982666015625, -1242.5517578125, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Wildcamp Ul'ar - Difficulty: 0) CreateObject1
(@OGUID+7, 464925, 2601, 14753, 14791, '0', 0, 0, -1789.435791015625, -877.25347900390625, -1242.5113525390625, 5.825554847717285156, 0, 0, -0.22682380676269531, 0.97393578290939331, 120, 255, 1, 57212), -- Candy Bucket (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
-- High Hollows
(@OGUID+8, 180405, 2601, 14753, 14794, '0', 0, 0, -2108.447998046875, -1166.8194580078125, -1231.913330078125, 0.782090365886688232, 0.004787921905517578, 0.017754554748535156, 0.380939483642578125, 0.924417078495025634, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+9, 180406, 2601, 14753, 14794, '0', 0, 0, -2097.263916015625, -1164.1510009765625, -1231.9871826171875, 0.607090711593627929, 0, 0, 0.298905372619628906, 0.954282760620117187, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+10, 180407, 2601, 14753, 14794, '0', 0, 0, -2102.838623046875, -1165.66845703125, -1232.2191162109375, 0.676983535289764404, 0.083531856536865234, -0.00211334228515625, 0.333100318908691406, 0.939181625843048095, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+11, 180408, 2601, 14753, 14794, '0', 0, 0, -2102.802001953125, -1165.767333984375, -1230.7255859375, 0.234233617782592773, 0.004008769989013671, 0.028948783874511718, 0.1165924072265625, 0.992749810218811035, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+12, 180415, 2601, 14753, 14794, '0', 0, 0, -2109.725830078125, -1133.5208740234375, -1241.5865478515625, 6.229013919830322265, 0, 0, -0.02708244323730468, 0.999633193016052246, 120, 255, 1, 57212), -- CandleBlack01 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+13, 180415, 2601, 14753, 14794, '0', 0, 0, -2112.9619140625, -1134.373291015625, -1241.664306640625, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+14, 180523, 2601, 14753, 14794, '0', 0, 0, -2097.020751953125, -1154.626708984375, -1244.2135009765625, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: The Burrows - Difficulty: 0) CreateObject1
(@OGUID+15, 464923, 2601, 14753, 14794, '0', 0, 0, -2095.1337890625, -1172.4722900390625, -1244.2147216796875, 0.151667013764381408, 0, 0, 0.075760841369628906, 0.99712604284286499, 120, 255, 1, 57212), -- Candy Bucket (Area: The Burrows - Difficulty: 0) CreateObject1
-- The Burrows
(@OGUID+16, 180405, 2601, 14753, 14791, '0', 0, 0, -2118.125, -1009.90631103515625, -1325.1065673828125, 3.927073955535888671, 0.017762660980224609, -0.00475788116455078, -0.92376995086669921, 0.382506102323532104, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+17, 180406, 2601, 14753, 14791, '0', 0, 0, -2108.328125, -991.935791015625, -1325.4862060546875, 4.905394554138183593, 0, 0, -0.63568496704101562, 0.771948575973510742, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+18, 180407, 2601, 14753, 14791, '0', 0, 0, -2033.782958984375, -1040.2291259765625, -1321.7027587890625, 4.767629146575927734, 0.062750816345214843, -0.18103694915771484, -0.66337299346923828, 0.723342418670654296, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+19, 180408, 2601, 14753, 14791, '0', 0, 0, -2043.810791015625, -1051.3802490234375, -1320.969482421875, 4.918757438659667968, 0.023548603057861328, 0.017308235168457031, -0.63040542602539062, 0.77571570873260498, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+20, 180415, 2601, 14753, 14791, '0', 0, 0, -2054.55908203125, -1072.7379150390625, -1324.7830810546875, 6.229013919830322265, 0, 0, -0.02708244323730468, 0.999633193016052246, 120, 255, 1, 57212), -- CandleBlack01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+21, 180415, 2601, 14753, 14791, '0', 0, 0, -2054.803955078125, -1072.9478759765625, -1324.4805908203125, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+22, 180523, 2601, 14753, 14791, '0', 0, 0, -2091.6806640625, -1073.876708984375, -1323.7366943359375, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@OGUID+23, 464924, 2601, 14753, 14791, '0', 0, 0, -2049.085205078125, -1061.8472900390625, -1325.8602294921875, 4.237780094146728515, 0, 0, -0.85351943969726562, 0.5210610032081604, 120, 255, 1, 57212); -- Candy Bucket (Area: Umbral Bazaar - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+23;
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
(12, @OGUID+23);
