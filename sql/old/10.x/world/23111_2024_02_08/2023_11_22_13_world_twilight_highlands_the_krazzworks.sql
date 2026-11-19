SET @CGUID := 3000351;
SET @OGUID := 3006252;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208153;

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208153; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=51886 WHERE `ID`=28976;

DELETE FROM `gameobject_queststarter` WHERE `id`=208153;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208153, 28976, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208153 AND `quest`=28976);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208153;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 0, 4922, 5137, '0', 0, 0, 0, 0, -2745.97216796875, -6362.1494140625, 198.9930419921875, 0, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51886); -- Black Cat (Area: The Krazzworks - Difficulty: 0) CreateObject1

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 230736 AND 230785;
DELETE FROM `gameobject` WHERE `guid`=231999;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 230736 AND 230785;
DELETE FROM `game_event_gameobject` WHERE `guid`=231999;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+31;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180406, 0, 4922, 5137, '0', 0, 0, -2743.078125, -6412.76416015625, 242.0164337158203125, 4.904376029968261718, 0, 0, -0.636077880859375, 0.771624863147735595, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+1, 180407, 0, 4922, 5137, '0', 0, 0, -2774.532958984375, -6407.875, 231.9047088623046875, 4.991643905639648437, 0, 0, -0.60181427001953125, 0.798636078834533691, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+2, 180408, 0, 4922, 5137, '0', 0, 0, -2747.802001953125, -6358.8818359375, 199.0170440673828125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+3, 180409, 0, 4922, 5137, '0', 0, 0, -2754.34375, -6363.92724609375, 199.0292510986328125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- G_WitchBroom_01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+4, 180410, 0, 4922, 5137, '0', 0, 0, -2749.1875, -6362.22216796875, 199.00640869140625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- G_HangingSkeleton_01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+5, 180411, 0, 4922, 5137, '0', 0, 0, -2744.30908203125, -6411.3505859375, 243.2164459228515625, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 120, 255, 1, 51886), -- G_Ghost_01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+6, 180414, 0, 4922, 5137, '0', 0, 0, -2751.361083984375, -6360.43408203125, 199.0269622802734375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Cauldron (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+7, 180415, 0, 4922, 5137, '0', 0, 0, -2744.80908203125, -6362.89599609375, 198.900238037109375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+8, 180425, 0, 4922, 5137, '0', 0, 0, -2751.75341796875, -6363.21875, 199.0176544189453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- SkullCandle01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+9, 180426, 0, 4922, 5137, '0', 0, 0, -2768.467041015625, -6410.13037109375, 245.491668701171875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+10, 180426, 0, 4922, 5137, '0', 0, 0, -2760.427001953125, -6414.8369140625, 242.9449920654296875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+11, 180426, 0, 4922, 5137, '0', 0, 0, -2762.484375, -6399.38037109375, 241.7418975830078125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+12, 180427, 0, 4922, 5137, '0', 0, 0, -2774.78125, -6408.07275390625, 243.7399139404296875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+13, 180427, 0, 4922, 5137, '0', 0, 0, -2774.526123046875, -6414.015625, 245.0953521728515625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+14, 180427, 0, 4922, 5137, '0', 0, 0, -2764.538330078125, -6417.13525390625, 231.644561767578125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+15, 180471, 0, 4922, 5137, '0', 0, 0, -2742.757080078125, -6370.19775390625, 198.602142333984375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+16, 180472, 0, 4922, 5137, '0', 0, 0, -2742.83154296875, -6406.35400390625, 248.2779083251953125, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+17, 180523, 0, 4922, 5137, '0', 0, 0, -2744.092041015625, -6407.45166015625, 241.947723388671875, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 51886), -- Apple Bob (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+18, 185434, 0, 4922, 5137, '0', 0, 0, -2745.44091796875, -6369.048828125, 198.9598846435546875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Sitting Skeleton 01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+19, 185435, 0, 4922, 5137, '0', 0, 0, -2746.677001953125, -6367.69091796875, 198.9712066650390625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Sitting Skeleton 02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+20, 185436, 0, 4922, 5137, '0', 0, 0, -2747.8681640625, -6366.45849609375, 198.9819793701171875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Sitting Skeleton 03 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+21, 185437, 0, 4922, 5137, '0', 0, 0, -2743.302001953125, -6367.32666015625, 198.9544219970703125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Laying Skeleton 01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+22, 185438, 0, 4922, 5137, '0', 0, 0, -2748.819580078125, -6365.1943359375, 198.991943359375, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 51886), -- Sitting Skeleton 04 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+23, 185454, 0, 4922, 5137, '0', 0, 0, -2745.333251953125, -6365.70849609375, 198.970977783203125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Laying Skeleton 02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+24, 185455, 0, 4922, 5137, '0', 0, 0, -2746.663330078125, -6364.10400390625, 198.9063873291015625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Laying Skeleton 03 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+25, 208063, 0, 4922, 5137, '0', 0, 0, -2744.489501953125, -6408.51025390625, 245.858154296875, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 120, 255, 1, 51886), -- Web Hanging (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+26, 208063, 0, 4922, 5137, '0', 0, 0, -2744.677001953125, -6406.41650390625, 245.56768798828125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 51886), -- Web Hanging (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+27, 208064, 0, 4922, 5137, '0', 0, 0, -2751.447998046875, -6373.26416015625, 198.974365234375, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 51886), -- Web Corner (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+28, 208075, 0, 4922, 5137, '0', 0, 0, -2754.18408203125, -6371.06591796875, 198.9959564208984375, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 51886), -- Web Tall 01 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+29, 208076, 0, 4922, 5137, '0', 0, 0, -2756.84716796875, -6367.87841796875, 199.0155487060546875, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 51886), -- Web Tall 02 (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+30, 208077, 0, 4922, 5137, '0', 0, 0, -2760.239501953125, -6359.65625, 201.367156982421875, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 120, 255, 1, 51886), -- Web Wide (Area: The Krazzworks - Difficulty: 0) CreateObject1
(@OGUID+31, 208153, 0, 4922, 5137, '0', 0, 0, -2737.350830078125, -6412.0400390625, 242.3661346435546875, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 51886); -- Candy Bucket (Area: The Krazzworks - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+31;
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
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31);
