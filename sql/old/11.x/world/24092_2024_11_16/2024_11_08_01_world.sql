SET @OGUID := 10800295;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (464914, 464913);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(464914, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27764, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464913, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27763, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (464914, 464913);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(464914, 35, 0x4, 0, 0), -- Candy Bucket
(464913, 35, 0x4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (84567, 84566);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84567, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84566, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (464914, 464913);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(464914, 84567, 57212),
(464913, 84566, 57212);

DELETE FROM `gameobject_questender` WHERE `id` IN (464914, 464913);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(464914, 84567, 57212),
(464913, 84566, 57212);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Rambleshire
(@OGUID+0, 180405, 2552, 14717, 14784, '0', 0, 0, 3551.24560546875, -3347.94970703125, 204.6703033447265625, 0.28334704041481018, 0, 0, 0.141200065612792968, 0.989981055259704589, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2552, 14717, 14784, '0', 0, 0, 3584.987060546875, -3329.864501953125, 195.0873565673828125, 5.07805633544921875, 0, 0, -0.5667572021484375, 0.823884844779968261, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2552, 14717, 14784, '0', 0, 0, 3546.171875, -3345.932373046875, 203.5988311767578125, 5.426262378692626953, 0.058678627014160156, -0.05948829650878906, -0.41189861297607421, 0.907390475273132324, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2552, 14717, 14784, '0', 0, 0, 3562.04345703125, -3359.02783203125, 204.39117431640625, 5.5171356201171875, 0, 0, -0.37372779846191406, 0.927538454532623291, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2552, 14717, 14784, '0', 0, 0, 3551.186767578125, -3351.7587890625, 202.6487884521484375, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2552, 14717, 14784, '0', 0, 0, 3593.46875, -3307.3837890625, 192.3769378662109375, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Rambleshire - Difficulty: 0) CreateObject1
(@OGUID+6, 464914, 2552, 14717, 14784, '0', 0, 0, 3596.671142578125, -3308.576416015625, 192.3769378662109375, 5.424034595489501953, 0, 0, -0.41648483276367187, 0.909142673015594482, 120, 255, 1, 57212), -- Candy Bucket (Area: Rambleshire - Difficulty: 0) CreateObject1
-- Freywold Village
(@OGUID+7, 180405, 2552, 14717, 14772, '0', 0, 0, 919.263916015625, -1919.78125, 76.5459442138671875, 4.367660045623779296, 0, 0, -0.81790637969970703, 0.575351357460021972, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2552, 14717, 14772, '0', 0, 0, 944.51910400390625, -1919.154541015625, 82.09828948974609375, 3.723055362701416015, 0, 0, -0.95803451538085937, 0.286652922630310058, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2552, 14717, 14772, '0', 0, 0, 964.42364501953125, -1921.13720703125, 81.51690673828125, 2.496774911880493164, 0, 0, 0.948474884033203125, 0.316852301359176635, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2552, 14717, 14772, '0', 0, 0, 902.64239501953125, -1898.079833984375, 79.910308837890625, 0.778629958629608154, 0, 0, 0.37955474853515625, 0.925169289112091064, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2552, 14717, 14772, '0', 0, 0, 912.546875, -1907.3211669921875, 76.46276092529296875, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2552, 14717, 14772, '0', 0, 0, 908.32989501953125, -1923.4566650390625, 75.44763946533203125, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Freywold Village - Difficulty: 0) CreateObject1
(@OGUID+13, 464913, 2552, 14717, 14772, '0', 0, 0, 904.34722900390625, -1925.6632080078125, 80.5654296875, 2.991102933883666992, 0, 0, 0.997170448303222656, 0.075173906981945037, 120, 255, 1, 57212); -- Candy Bucket (Area: Freywold Village - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+13;
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
(12, @OGUID+13);
