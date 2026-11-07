SET @OGUID := 4800045;

-- Gameobject templates
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=215902; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (32043);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(32043, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (215902);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(215902, 32043, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (215902);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(215902, 32043, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Longying Outpost
(@OGUID+0, 180405, 870, 5842, 6166, '0', 0, 0, 2348.529541015625, 2995.658935546875, 426.899383544921875, 1.753023743629455566, 0, 0, 0.768511772155761718, 0.639835655689239501, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Longying Outpost - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 870, 5842, 6166, '0', 0, 0, 2346.536376953125, 3003.171142578125, 426.88916015625, 2.788564443588256835, 0, 0, 0.984461784362792968, 0.175598904490470886, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Longying Outpost - Difficulty: 0) CreateObject1
(@OGUID+2, 215902, 870, 5842, 6166, '0', 0, 0, 2346.098876953125, 2993.337646484375, 421.391143798828125, 3.484081506729125976, 0, 0, -0.98537349700927734, 0.170408576726913452, 120, 255, 1, 51886); -- Candy Bucket (Area: Longying Outpost - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2);
