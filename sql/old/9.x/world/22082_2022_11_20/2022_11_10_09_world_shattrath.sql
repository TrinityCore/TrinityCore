SET @CGUID := 222668;
SET @OGUID := 166221;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35258; -- Ghostly Aldor Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60 WHERE `entry`=35259; -- Ghostly Scryer Celebrant
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35260; -- Cheerful Aldor Spirit
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35261; -- Cheerful Scryer Spirit

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=35261; -- 35261 (Cheerful Scryer Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=35260; -- 35260 (Cheerful Aldor Spirit)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35259; -- 35259 (Ghostly Scryer Celebrant)
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35258; -- 35258 (Ghostly Aldor Celebrant)

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (35261,35260,35259,35258));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35261, 0, 0, 0, 414, 46366),
(35260, 0, 0, 0, 414, 46366),
(35259, 0, 0, 0, 414, 46366),
(35258, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (21854,19687));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (35261,35259,19687,35260,35258,21854)) OR (`Idx`=3 AND `CreatureID` IN (35259,19687,35258)) OR (`Idx`=2 AND `CreatureID` IN (35259,19687,35258)) OR (`Idx`=1 AND `CreatureID` IN (35259,19687,35258));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (29733, 29732, 16878, 20170);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29730, 29728, 29729, 29726, 29723, 29724);

-- Quests
DELETE FROM `creature_queststarter` WHERE `id` IN (35260, 35261);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(35260, 14172, 46366),
(35261, 14173, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id` IN (35260, 35261);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 144903 AND 144917;
DELETE FROM `creature` WHERE `guid` IN (144843, 145027, 145035);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 144903 AND 144917;
DELETE FROM `game_event_creature` WHERE `guid` IN (144843, 145027, 145035);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 530, 3519, 3519, '0', 0, 0, 0, 1, -1788.236083984375, 4925.75244140625, -21.6491146087646484, 2.460914134979248046, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+1, 34383, 530, 3519, 3519, '0', 0, 0, 0, 1, -1792.2708740234375, 4921.30810546875, -21.5448799133300781, 2.58308720588684082, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+2, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1824.8941650390625, 4920.689453125, -21.8328437805175781, 1.01229095458984375, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+3, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1832.876708984375, 4923.1708984375, -21.4524955749511718, 1.134464025497436523, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+4, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1785.263916015625, 4938.56494140625, -22.5346794128417968, 3.281219005584716796, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+5, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1828.8385009765625, 4923.3515625, -21.8637142181396484, 1.064650893211364746, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+6, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1837.7239990234375, 4927.68505859375, -21.1529521942138671, 1.29154360294342041, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+7, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1781.51220703125, 4932.91845703125, -22.36956787109375, 3.857177734375, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+8, 35258, 530, 3519, 3519, '0', 0, 0, 0, 0, -1834.5208740234375, 4926.9765625, -21.4531154632568359, 0.977384388446807861, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Aldor Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+9, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1815.9166259765625, 4913.81005859375, -21.4253044128417968, 1.535889744758605957, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+10, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1803.751708984375, 4906.93994140625, -21.3884010314941406, 2.356194496154785156, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+11, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1797.486083984375, 4914.01025390625, -21.7077884674072265, 1.500983119010925292, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+12, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1803.53125, 4911.09716796875, -21.7488002777099609, 2.740166902542114257, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+13, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1792, 4913.0546875, -21.3998279571533203, 2.007128715515136718, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+14, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1794.4617919921875, 4911.29345703125, -21.4007549285888671, 2.111848354339599609, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+15, 35259, 530, 3519, 3519, '0', 0, 0, 0, 0, -1812.2760009765625, 4911.76220703125, -21.3407649993896484, 0.907571196556091308, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366), -- Ghostly Scryer Celebrant (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+16, 35260, 530, 3519, 3519, '0', 0, 0, 0, 0, -1784.904541015625, 4934.78662109375, -22.4792404174804687, 3.543018341064453125, 120, 0, 0, 18771, 2434, 0, 0, 0, 0, 46366), -- Cheerful Aldor Spirit (Area: Terokkar Forest - Difficulty: 0)
(@CGUID+17, 35261, 530, 3519, 3519, '0', 0, 0, 0, 0, -1801.1197509765625, 4913.8818359375, -21.8948688507080078, 2.268928050994873046, 120, 0, 0, 15017, 5751, 0, 0, 0, 0, 46366); -- Cheerful Scryer Spirit (Area: Terokkar Forest - Difficulty: 0)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 76291 AND 76296;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 76395 AND 76412;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78442 AND 78448;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78499 AND 78502;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78523 AND 78525;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78568 AND 78570;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78608 AND 78610;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78644 AND 78646;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78882 AND 78906;
DELETE FROM `gameobject` WHERE `guid` IN (76257, 77918, 77919, 78413, 78681, 78682, 78727, 78728);
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 76291 AND 76296;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 76395 AND 76412;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78442 AND 78448;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78499 AND 78502;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78523 AND 78525;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78568 AND 78570;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78608 AND 78610;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78644 AND 78646;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78882 AND 78906;
DELETE FROM `game_event_gameobject` WHERE `guid` IN (76257, 77918, 77919, 78413, 78681, 78682, 78727, 78728);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+52;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 530, 3519, 3519, '0', 0, 0, -1796.407958984375, 4911.3671875, -21.4001941680908203, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+1, 180338, 530, 3519, 3519, '0', 0, 0, -1801.5538330078125, 4910.69775390625, -21.4004974365234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+2, 180338, 530, 3519, 3519, '0', 0, 0, -1802.3211669921875, 4907.9697265625, -21.3995800018310546, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+3, 180338, 530, 3519, 3519, '0', 0, 0, -1799.0382080078125, 4912.0703125, -21.3997955322265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+4, 180338, 530, 3519, 3519, '0', 0, 0, -1791.6475830078125, 4910.95849609375, -21.366556167602539, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+5, 180338, 530, 3519, 3519, '0', 0, 0, -1829.2413330078125, 4919.93408203125, -21.4281139373779296, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+6, 180338, 530, 3519, 3519, '0', 0, 0, -1783.845458984375, 4936.49853515625, -22.6233253479003906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+7, 180338, 530, 3519, 3519, '0', 0, 0, -1783.579833984375, 4937.41845703125, -22.8770580291748046, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+8, 180338, 530, 3519, 3519, '0', 0, 0, -1787.1441650390625, 4926.236328125, -21.7487049102783203, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+9, 180338, 530, 3519, 3519, '0', 0, 0, -1779.8524169921875, 4937.52197265625, -20.6380138397216796, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+10, 180338, 530, 3519, 3519, '0', 0, 0, -1837.9739990234375, 4921.6484375, -19.051055908203125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+11, 180338, 530, 3519, 3519, '0', 0, 0, -1836.6285400390625, 4922.9287109375, -21.123300552368164, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+12, 180338, 530, 3519, 3519, '0', 0, 0, -1779.859375, 4938.296875, -20.5743331909179687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+13, 180339, 530, 3519, 3519, '0', 0, 0, -1792.3836669921875, 4920.32666015625, -21.6460552215576171, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+14, 180339, 530, 3519, 3519, '0', 0, 0, -1816.1597900390625, 4909.69091796875, -16.4784355163574218, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+15, 180339, 530, 3519, 3519, '0', 0, 0, -1830.4791259765625, 4917.7587890625, -18.8396148681640625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+16, 180339, 530, 3519, 3519, '0', 0, 0, -1790.857666015625, 4909.4208984375, -16.4114818572998046, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+17, 180339, 530, 3519, 3519, '0', 0, 0, -1837.953125, 4921.16162109375, -18.8750038146972656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+18, 180339, 530, 3519, 3519, '0', 0, 0, -1779.32470703125, 4938.2880859375, -20.3574466705322265, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+19, 180340, 530, 3519, 3519, '0', 0, 0, -1815.4010009765625, 4912.05322265625, -21.4139518737792968, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+20, 180340, 530, 3519, 3519, '0', 0, 0, -1792.657958984375, 4910.359375, -21.3714733123779296, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+21, 180340, 530, 3519, 3519, '0', 0, 0, -1788.9461669921875, 4925.1318359375, -21.7120437622070312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+22, 180340, 530, 3519, 3519, '0', 0, 0, -1791.435791015625, 4921.8994140625, -21.6634464263916015, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+23, 180340, 530, 3519, 3519, '0', 0, 0, -1830.7552490234375, 4918.10400390625, -18.9402980804443359, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+24, 180340, 530, 3519, 3519, '0', 0, 0, -1830.763916015625, 4920.1474609375, -21.452362060546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+25, 180340, 530, 3519, 3519, '0', 0, 0, -1782.326416015625, 4934.6650390625, -22.6272411346435546, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 03 (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+26, 182807, 530, 3519, 3519, '0', 0, 0, -1783.0885009765625, 4936.236328125, -22.6301651000976562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+27, 182807, 530, 3519, 3519, '0', 0, 0, -1836.095458984375, 4923.36279296875, -21.2411785125732421, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+28, 182807, 530, 3519, 3519, '0', 0, 0, -1791.9254150390625, 4910.330078125, -21.3478565216064453, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+29, 195063, 530, 3519, 3519, '0', 0, 0, -1791.9566650390625, 4916.51904296875, -21.0255775451660156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+30, 195063, 530, 3519, 3519, '0', 0, 0, -1791.41845703125, 4919.37255859375, -21.0256156921386718, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+31, 195063, 530, 3519, 3519, '0', 0, 0, -1815.7413330078125, 4911.44970703125, -21.2438621520996093, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+32, 195063, 530, 3519, 3519, '0', 0, 0, -1790.3194580078125, 4921.7265625, -21.0877933502197265, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+33, 195063, 530, 3519, 3519, '0', 0, 0, -1783.1336669921875, 4926.90966796875, -21.1390628814697265, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+34, 195063, 530, 3519, 3519, '0', 0, 0, -1836.826416015625, 4923.66259765625, -21.1737899780273437, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+35, 195066, 530, 3519, 3519, '0', 0, 0, -1835.9114990234375, 4922.8037109375, -21.2072257995605468, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+36, 195066, 530, 3519, 3519, '0', 0, 0, -1782.203125, 4935.56494140625, -22.6640510559082031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+37, 195067, 530, 3519, 3519, '0', 0, 0, -1814.9097900390625, 4911.5078125, -21.3174991607666015, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+38, 195067, 530, 3519, 3519, '0', 0, 0, -1782.921875, 4936.822265625, -22.6595134735107421, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+39, 195067, 530, 3519, 3519, '0', 0, 0, -1829.6197509765625, 4920.39697265625, -21.5714244842529296, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+40, 195068, 530, 3519, 3519, '0', 0, 0, -1835.9149169921875, 4922.8203125, -21.208261489868164, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+41, 195068, 530, 3519, 3519, '0', 0, 0, -1782.2535400390625, 4935.55029296875, -22.6603317260742187, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+42, 195069, 530, 3519, 3519, '0', 0, 0, -1788.5833740234375, 4923.9052734375, -21.0877628326416015, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candy Skulls (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+43, 195069, 530, 3519, 3519, '0', 0, 0, -1789.04345703125, 4923.306640625, -21.0878314971923828, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 46366), -- Candy Skulls (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+44, 195069, 530, 3519, 3519, '0', 0, 0, -1785.7864990234375, 4925.87353515625, -21.1390743255615234, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candy Skulls (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+45, 195069, 530, 3519, 3519, '0', 0, 0, -1785.0538330078125, 4926.18408203125, -21.1391162872314453, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 120, 255, 1, 46366), -- Candy Skulls (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+46, 195087, 530, 3519, 3519, '0', 0, 0, -1790.765625, 4923.8974609375, -21.7850627899169921, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+47, 195090, 530, 3519, 3519, '0', 0, 0, -1789.701416015625, 4922.515625, -21.0878028869628906, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Spirit Candle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+48, 195090, 530, 3519, 3519, '0', 0, 0, -1791.73095703125, 4917.93603515625, -21.0255756378173828, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 46366), -- Spirit Candle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+49, 195090, 530, 3519, 3519, '0', 0, 0, -1784.0103759765625, 4926.54443359375, -21.1391143798828125, 1.937312245368957519, 0, 0, 0.824125289916992187, 0.566407561302185058, 120, 255, 1, 46366), -- Spirit Candle (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+50, 195307, 530, 3519, 3519, '0', 0, 0, -1789.3541259765625, 4922.8515625, -21.0877628326416015, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+51, 195307, 530, 3519, 3519, '0', 0, 0, -1784.595458984375, 4926.28662109375, -21.1390972137451171, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)
(@OGUID+52, 195307, 530, 3519, 3519, '0', 0, 0, -1830.345458984375, 4920.56884765625, -21.528116226196289, 0.436331570148468017, 0, 0, 0.216439247131347656, 0.976296067237854003, 120, 255, 1, 46366); -- Orange Marigolds (Area: Terokkar Forest - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(51, @CGUID+0), 
(51, @CGUID+1), 
(51, @CGUID+2), 
(51, @CGUID+3), 
(51, @CGUID+4), 
(51, @CGUID+5), 
(51, @CGUID+6), 
(51, @CGUID+7), 
(51, @CGUID+8), 
(51, @CGUID+9), 
(51, @CGUID+10),
(51, @CGUID+11),
(51, @CGUID+12),
(51, @CGUID+13),
(51, @CGUID+14),
(51, @CGUID+15),
(51, @CGUID+16),
(51, @CGUID+17);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+52;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(51, @OGUID+0),
(51, @OGUID+1),
(51, @OGUID+2),
(51, @OGUID+3),
(51, @OGUID+4),
(51, @OGUID+5),
(51, @OGUID+6),
(51, @OGUID+7),
(51, @OGUID+8),
(51, @OGUID+9),
(51, @OGUID+10),
(51, @OGUID+11),
(51, @OGUID+12),
(51, @OGUID+13),
(51, @OGUID+14),
(51, @OGUID+15),
(51, @OGUID+16),
(51, @OGUID+17),
(51, @OGUID+18),
(51, @OGUID+19),
(51, @OGUID+20),
(51, @OGUID+21),
(51, @OGUID+22),
(51, @OGUID+23),
(51, @OGUID+24),
(51, @OGUID+25),
(51, @OGUID+26),
(51, @OGUID+27),
(51, @OGUID+28),
(51, @OGUID+29),
(51, @OGUID+30),
(51, @OGUID+31),
(51, @OGUID+32),
(51, @OGUID+33),
(51, @OGUID+34),
(51, @OGUID+35),
(51, @OGUID+36),
(51, @OGUID+37),
(51, @OGUID+38),
(51, @OGUID+39),
(51, @OGUID+40),
(51, @OGUID+41),
(51, @OGUID+42),
(51, @OGUID+43),
(51, @OGUID+44),
(51, @OGUID+45),
(51, @OGUID+46),
(51, @OGUID+47),
(51, @OGUID+48),
(51, @OGUID+49),
(51, @OGUID+50),
(51, @OGUID+51),
(51, @OGUID+52);
