SET @OGUID := 4800068;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215877; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215876; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32024, 32023);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32024, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32023, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215877, 215876);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215877, 32024, 51886),
(215876, 32023, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215877, 215876);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215877, 32024, 51886),
(215876, 32023, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Klaxxi'vess
(@OGUID+0, 180405, 870, 6138, 6315, '0', 0, 0, 263.798614501953125, 3144.053955078125, 218.592315673828125, 3.662270069122314453, 0, 0, -0.96630287170410156, 0.257407814264297485, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Klaxxi'vess - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 870, 6138, 6315, '0', 0, 0, 258.01214599609375, 3145.791748046875, 221.2231903076171875, 3.447491168975830078, 0, 0, -0.98832607269287109, 0.152353525161743164, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Klaxxi'vess - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 870, 6138, 6315, '0', 0, 0, 268.013885498046875, 3146.882080078125, 221.335357666015625, 4.325025081634521484, 0, 0, -0.82998466491699218, 0.557786226272583007, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Klaxxi'vess - Difficulty: 0) CreateObject1
(@OGUID+3, 215877, 870, 6138, 6315, '0', 0, 0, 264.986114501953125, 3146.104248046875, 214.5009918212890625, 0.611063480377197265, 0, 0, 0.300800323486328125, 0.953687131404876708, 120, 255, 1, 51886), -- Candy Bucket (Area: Klaxxi'vess - Difficulty: 0) CreateObject1
-- Soggy's Gamble
(@OGUID+4, 180406, 870, 6138, 6368, '0', 0, 0, -1125.78125, 3181.5400390625, 5.737205982208251953, 0.426158696413040161, 0, 0, 0.211470603942871093, 0.977384388446807861, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Soggy's Gamble - Difficulty: 0) CreateObject1
(@OGUID+5, 215876, 870, 6138, 6368, '0', 0, 0, -1124.2379150390625, 3184.3994140625, 5.534190177917480468, 4.853007793426513671, 0, 0, -0.65568447113037109, 0.755035042762756347, 120, 255, 1, 51886); -- Candy Bucket (Area: Soggy's Gamble - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5);
