SET @OGUID := 4800048;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215875; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=215915; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215903; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32022, 32052, 32044);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32022, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32052, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32044, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215875, 215915, 215903);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215875, 32022, 51886),
(215915, 32052, 51886),
(215903, 32044, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215875, 215915, 215903);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215875, 32022, 51886),
(215915, 32052, 51886),
(215903, 32044, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Shrine of Two Moons
(@OGUID+0, 180405, 870, 6554, 6554, '0', 0, 0, 1675.2760009765625, 903.560791015625, 490.689300537109375, 2.511412620544433593, 0, 0, 0.950768470764160156, 0.309902071952819824, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Shrine of Two Moons - Difficulty: 0) CreateObject1
(@OGUID+1, 215875, 870, 6554, 6554, '0', 0, 0, 1673.5416259765625, 911.04864501953125, 490.689239501953125, 5.287477970123291015, 0, 0, -0.47754096984863281, 0.87860947847366333, 120, 255, 1, 51886), -- Candy Bucket (Area: Shrine of Two Moons - Difficulty: 0) CreateObject1
-- Shrine of Seven Stars
(@OGUID+2, 180405, 870, 6142, 6142, '0', 0, 0, 781.80206298828125, 292.09027099609375, 508.124725341796875, 0.998298346996307373, 0, 0, 0.478678703308105468, 0.877990126609802246, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Shrine of Seven Stars - Difficulty: 0) CreateObject1
(@OGUID+3, 180406, 870, 6142, 6142, '0', 0, 0, 785.9444580078125, 295.17535400390625, 508.121917724609375, 1.055283308029174804, 0, 0, 0.503497123718261718, 0.863996922969818115, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Shrine of Seven Stars - Difficulty: 0) CreateObject1
(@OGUID+4, 180407, 870, 6142, 6142, '0', 0, 0, 788.5225830078125, 280.111114501953125, 503.418182373046875, 3.32104349136352539, 0, 0, -0.99597740173339843, 0.089604929089546203, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Shrine of Seven Stars - Difficulty: 0) CreateObject1
(@OGUID+5, 215915, 870, 6142, 6142, '0', 0, 0, 785.45660400390625, 276.588531494140625, 503.419158935546875, 4.718334197998046875, 0, 0, -0.7050018310546875, 0.709205508232116699, 120, 255, 1, 51886), -- Candy Bucket (Area: Shrine of Seven Stars - Difficulty: 0) CreateObject1
-- Mistfall Village
(@OGUID+6, 180405, 870, 5840, 6031, '0', 0, 0, 681.545166015625, 1595.1146240234375, 387.092071533203125, 1.526481986045837402, 0, 0, 0.691267013549804687, 0.722599446773529052, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Mistfall Village - Difficulty: 0) CreateObject1
(@OGUID+7, 180406, 870, 5840, 6031, '0', 0, 0, 682.0555419921875, 1581.1336669921875, 387.092437744140625, 2.501868724822998046, 0, 0, 0.949278831481933593, 0.314435482025146484, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Mistfall Village - Difficulty: 0) CreateObject1
(@OGUID+8, 180407, 870, 5840, 6031, '0', 0, 0, 673.39239501953125, 1595.513916015625, 389.208099365234375, 0.368232548236846923, 0, 0, 0.183077812194824218, 0.983098447322845458, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Mistfall Village - Difficulty: 0) CreateObject1
(@OGUID+9, 215903, 870, 5840, 6031, '0', 0, 0, 635.34375, 1591.154541015625, 387.681304931640625, 2.292711257934570312, 0, 0, 0.911269187927246093, 0.41181117296218872, 120, 255, 1, 51886); -- Candy Bucket (Area: Mistfall Village - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+9;
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
(12, @OGUID+9);
