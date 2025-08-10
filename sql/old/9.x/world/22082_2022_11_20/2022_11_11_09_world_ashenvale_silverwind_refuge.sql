SET @OGUID := 246350;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208117; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208117; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28953;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28953, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208117;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208117, 28953, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208117 AND `quest`=28953);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208117;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228712 AND 228739;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228712 AND 228739;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+29;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 331, 420, '0', 0, 0, 2165.048583984375, -1149.1302490234375, 97.37541961669921875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+1, 180406, 1, 331, 420, '0', 0, 0, 2147.364501953125, -1215.4722900390625, 96.401611328125, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+2, 180407, 1, 331, 420, '0', 0, 0, 2132.76220703125, -1197.203125, 100.5833969116210937, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+3, 180408, 1, 331, 420, '0', 0, 0, 2165.036376953125, -1149.04345703125, 98.99346160888671875, 3.874631166458129882, 0, 0, -0.93358039855957031, 0.358368009328842163, 120, 255, 1, 46366), -- G_WitchHat_01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+4, 180410, 1, 331, 420, '0', 0, 0, 2138.517333984375, -1210.8350830078125, 98.14609527587890625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+5, 180411, 1, 331, 420, '0', 0, 0, 2118.244873046875, -1190.2742919921875, 106.9416732788085937, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+6, 180414, 1, 331, 420, '0', 0, 0, 2162.84033203125, -1150.654541015625, 97.14914703369140625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Cauldron (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+7, 180415, 1, 331, 420, '0', 0, 0, 2084.185791015625, -1200.5625, 102.8491134643554687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+8, 180415, 1, 331, 420, '0', 0, 0, 2080.916748046875, -1185.7586669921875, 102.8990936279296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+9, 180415, 1, 331, 420, '0', 0, 0, 2079.03125, -1198.4896240234375, 102.921356201171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+10, 180415, 1, 331, 420, '0', 0, 0, 2080.272705078125, -1180.2760009765625, 102.8286514282226562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+11, 180415, 1, 331, 420, '0', 0, 0, 2081.069580078125, -1195.8228759765625, 102.8893203735351562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+12, 180415, 1, 331, 420, '0', 0, 0, 2080.8056640625, -1201.6302490234375, 102.8531875610351562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+13, 180415, 1, 331, 420, '0', 0, 0, 2084.036376953125, -1184.55908203125, 102.8518829345703125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+14, 180415, 1, 331, 420, '0', 0, 0, 2084.213623046875, -1197.0347900390625, 102.8878402709960937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+15, 180415, 1, 331, 420, '0', 0, 0, 2078.475830078125, -1183.2569580078125, 102.8043670654296875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+16, 180415, 1, 331, 420, '0', 0, 0, 2083.87841796875, -1181.4322509765625, 102.8462371826171875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+17, 180425, 1, 331, 420, '0', 0, 0, 2086.93408203125, -1182.3316650390625, 102.4078292846679687, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 120, 255, 1, 46366), -- SkullCandle01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+18, 180426, 1, 331, 420, '0', 0, 0, 2159.704833984375, -1187.8489990234375, 93.67913055419921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+19, 180426, 1, 331, 420, '0', 0, 0, 2141.098876953125, -1187.9791259765625, 96.94974517822265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+20, 180426, 1, 331, 420, '0', 0, 0, 2151.35595703125, -1180.1666259765625, 94.19057464599609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+21, 180427, 1, 331, 420, '0', 0, 0, 2142.3212890625, -1187.5242919921875, 96.51727294921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+22, 180427, 1, 331, 420, '0', 0, 0, 2144.28125, -1191.3472900390625, 95.89453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+23, 180427, 1, 331, 420, '0', 0, 0, 2147.111083984375, -1188.3367919921875, 95.15750885009765625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+24, 180471, 1, 331, 420, '0', 0, 0, 2125.826416015625, -1196.310791015625, 108.2275772094726562, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+25, 180471, 1, 331, 420, '0', 0, 0, 2125.826416015625, -1196.310791015625, 106.6285171508789062, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 120, 255, 1, 46366), -- HangingSkullLight01 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+26, 180472, 1, 331, 420, '0', 0, 0, 2126.0087890625, -1183.1319580078125, 109.2207794189453125, 6.230826377868652343, 0, 0, -0.02617645263671875, 0.999657332897186279, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+27, 180523, 1, 331, 420, '0', 0, 0, 2088.73095703125, -1200.6146240234375, 102.2795791625976562, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Apple Bob (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+28, 185436, 1, 331, 420, '0', 0, 0, 2163.015625, -1151.1319580078125, 97.89810943603515625, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 46366), -- Sitting Skeleton 03 (Area: Silverwind Refuge - Difficulty: 0)
(@OGUID+29, 208117, 1, 331, 420, '0', 0, 0, 2087.255126953125, -1197.8697509765625, 101.7149734497070312, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 46366); -- Candy Bucket (Area: Silverwind Refuge - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+29;
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
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29);
