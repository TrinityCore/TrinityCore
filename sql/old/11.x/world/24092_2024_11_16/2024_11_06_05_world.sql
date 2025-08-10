SET @OGUID := 4800058;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215879; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215905; -- Candy Bucket
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215906; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32026, 32048, 32046);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32026, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32048, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(32046, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215879, 215905, 215906);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215879, 32026, 51886),
(215905, 32048, 51886),
(215906, 32046, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215879, 215905, 215906);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215879, 32026, 51886),
(215905, 32048, 51886),
(215906, 32046, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Tavern in the Mists
(@OGUID+0, 180405, 870, 6006, 6375, '0', 0, 0, 809.22222900390625, -178.248260498046875, 415.836212158203125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Tavern in the Mists - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 870, 6006, 6375, '0', 0, 0, 814.4288330078125, -181.048614501953125, 416.157135009765625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Tavern in the Mists - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 870, 6006, 6375, '0', 0, 0, 797.34893798828125, -196.961807250976562, 408.662261962890625, 4.923078536987304687, 0, 0, -0.62883472442626953, 0.777539014816284179, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Tavern in the Mists - Difficulty: 0) CreateObject1
(@OGUID+3, 215879, 870, 6006, 6375, '0', 0, 0, 825.78125, -176.067703247070312, 415.22259521484375, 0.050529133528470993, 0, 0, 0.025261878967285156, 0.999680876731872558, 120, 255, 1, 51886), -- Candy Bucket (Area: Tavern in the Mists - Difficulty: 0) CreateObject1
-- Pang's Stead
(@OGUID+4, 180405, 870, 5805, 5936, '0', 0, 0, 539.41839599609375, -604.4930419921875, 261.584503173828125, 5.786715984344482421, 0, 0, -0.24569320678710937, 0.969347655773162841, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Pang's Stead - Difficulty: 0) CreateObject1
(@OGUID+5, 180407, 870, 5805, 5936, '0', 0, 0, 546.11456298828125, -614.15277099609375, 261.590362548828125, 5.825096607208251953, 0, 0, -0.22704696655273437, 0.973883807659149169, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Pang's Stead - Difficulty: 0) CreateObject1
(@OGUID+6, 215905, 870, 5805, 5936, '0', 0, 0, 568.921875, -603.78472900390625, 263.461822509765625, 4.660985469818115234, 0, 0, -0.72504520416259765, 0.688701272010803222, 120, 255, 1, 51886), -- Candy Bucket (Area: Pang's Stead - Difficulty: 0) CreateObject1
-- Stoneplow
(@OGUID+7, 180405, 870, 5805, 5968, '0', 0, 0, -380.20660400390625, 1907.9635009765625, 143.5151824951171875, 4.960309982299804687, 0, 0, -0.61425209045410156, 0.789109885692596435, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Stoneplow - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 870, 5805, 5968, '0', 0, 0, -400.180572509765625, 1900.373291015625, 132.6475677490234375, 4.333057403564453125, 0, 0, -0.82773780822753906, 0.561115026473999023, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Stoneplow - Difficulty: 0) CreateObject1
(@OGUID+9, 215906, 870, 5805, 5968, '0', 0, 0, -363.578125, 1899.201416015625, 142.7747039794921875, 4.240642547607421875, 0, 0, -0.85277271270751953, 0.522282183170318603, 120, 255, 1, 51886); -- Candy Bucket (Area: Stoneplow - Difficulty: 0) CreateObject1

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
