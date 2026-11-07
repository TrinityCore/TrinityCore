SET @OGUID := 4800074;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215894; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215892; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215904; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=215873; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32036, 32034, 32047, 32020);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32036, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32034, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32047, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32020, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215894, 215892, 215904, 215873);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215894, 32036, 51886),
(215892, 32034, 51886),
(215904, 32047, 51886),
(215873, 32020, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215894, 215892, 215904, 215873);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215894, 32036, 51886),
(215892, 32034, 51886),
(215904, 32047, 51886),
(215873, 32020, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Zhu's Watch
(@OGUID+0, 215894, 870, 6134, 6000, '0', 0, 0, -325.177093505859375, -610.98614501953125, 128.8326873779296875, 4.703175544738769531, 0, 0, -0.71035671234130859, 0.703841865062713623, 120, 255, 1, 51886), -- Candy Bucket (Area: Zhu's Watch - Difficulty: 0) CreateObject1
-- Marista
(@OGUID+1, 180406, 870, 6134, 6146, '0', 0, 0, -2519.491455078125, 523.21875, 11.46843433380126953, 1.120101094245910644, 0, 0, 0.531229019165039062, 0.847228288650512695, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Marista - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 870, 6134, 6146, '0', 0, 0, -2527.166748046875, 514.859375, 11.46067523956298828, 1.758742332458496093, 0, 0, 0.770338058471679687, 0.637635648250579833, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Marista - Difficulty: 0) CreateObject1
(@OGUID+3, 215892, 870, 6134, 6146, '0', 0, 0, -2525.701416015625, 538.47918701171875, 13.35631275177001953, 6.223133087158203125, 0, 0, -0.03002166748046875, 0.999549269676208496, 120, 255, 1, 51886), -- Candy Bucket (Area: Marista - Difficulty: 0) CreateObject1
-- Thunder Cleft
(@OGUID+4, 180405, 870, 6134, 6007, '0', 0, 0, -892.20660400390625, 99.70659637451171875, 15.03733634948730468, 2.924416542053222656, 0, 0, 0.994110107421875, 0.108374789357185363, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Thunder Cleft - Difficulty: 0) CreateObject1
(@OGUID+5, 215904, 870, 6134, 6007, '0', 0, 0, -896.15972900390625, 86.953125, 13.2198495864868164, 2.530906915664672851, 0, 0, 0.953743934631347656, 0.300620198249816894, 120, 255, 1, 51886), -- Candy Bucket (Area: Thunder Cleft - Difficulty: 0) CreateObject1
-- Dawnchaser Retreat
(@OGUID+6, 180405, 870, 6134, 6013, '0', 0, 0, -1699.765625, 1612.5416259765625, 15.28841114044189453, 6.259503364562988281, 0, 0, -0.0118408203125, 0.99992990493774414, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Dawnchaser Retreat - Difficulty: 0) CreateObject1
(@OGUID+7, 180406, 870, 6134, 6013, '0', 0, 0, -1693.890625, 1610.470458984375, 15.28841114044189453, 0.316155403852462768, 0, 0, 0.157420158386230468, 0.987531721591949462, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Dawnchaser Retreat - Difficulty: 0) CreateObject1
(@OGUID+8, 215873, 870, 6134, 6013, '0', 0, 0, -1695.9375, 1623.7708740234375, 15.28841114044189453, 0.058424677699804306, 0, 0, 0.029208183288574218, 0.999573349952697753, 120, 255, 1, 51886); -- Candy Bucket (Area: Dawnchaser Retreat - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8);
