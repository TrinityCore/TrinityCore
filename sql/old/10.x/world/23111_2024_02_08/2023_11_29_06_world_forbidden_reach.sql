SET @OGUID := 9003842;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry`=401755;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(401755, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry`=401755;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(401755, 35, 4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=75702;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75702, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=401755;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(401755, 75702, 51886);

DELETE FROM `gameobject_questender` WHERE `id`=401755;
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(401755, 75702, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 2444, 14433, 14656, '0', 0, 0, 6404.95068359375, -2487.65966796875, 18.31695365905761718, 1.329817652702331542, 0.066677093505859375, 0.091526985168457031, 0.610349655151367187, 0.783996343612670898, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2444, 14433, 14656, '0', 0, 0, 6406.93408203125, -2486.607666015625, 18.34546661376953125, 0.992532074451446533, -0.03348064422607421, -0.08083534240722656, 0.471009254455566406, 0.877778410911560058, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2444, 14433, 14656, '0', 0, 0, 6417.494140625, -2560.09033203125, 15.6829986572265625, 4.29443359375, 0, 0, -0.83841896057128906, 0.545026242733001708, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2444, 14433, 14656, '0', 0, 0, 6415.32666015625, -2496.904541015625, 29.30227279663085937, 5.917185783386230468, 0, 0, -0.18198013305664062, 0.983302235603332519, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2444, 14433, 14656, '0', 0, 0, 6421.3056640625, -2472.5625, 14.49416065216064453, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2444, 14433, 14656, '0', 0, 0, 6410.90966796875, -2468.786376953125, 13.98939228057861328, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Morqut Village - Difficulty: 0) CreateObject1
(@OGUID+6, 401755, 2444, 14433, 14656, '0', 0, 0, 6419.1484375, -2473.62841796875, 13.97084903717041015, 0.34250536561012268, 0, 0, 0.170416831970214843, 0.985372066497802734, 120, 255, 1, 51886); -- Candy Bucket (Area: Morqut Village - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6);
