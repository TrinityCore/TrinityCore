SET @CGUID := 3000298;
SET @OGUID := 3004738;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208121; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208121; -- Candy Bucket

-- Quests
UPDATE `quest_template` SET `Expansion`=9, `VerifiedBuild`=51886 WHERE `ID`=28956; -- Candy Bucket

DELETE FROM `quest_offer_reward` WHERE `ID`=28956;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28956, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208121;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208121, 28956, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208121 AND `quest`=28956);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208121;

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 22816, 0, 3, 5564, '0', 0, 0, 0, 0, -6996.51318359375, -2528.797607421875, 241.7134552001953125, 5.925296306610107421, 120, 5, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51886); -- Black Cat (Area: Dragon's Mouth - Difficulty: 0) CreateObject1

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 231118 AND 231180;
DELETE FROM `gameobject` WHERE `guid`=232005;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 231118 AND 231180;
DELETE FROM `game_event_gameobject` WHERE `guid`=232005;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+30;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 3, 5564, '0', 0, 0, -6985.7275390625, -2529.0400390625, 241.7134552001953125, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+1, 180405, 0, 3, 5564, '0', 0, 0, -7013.7099609375, -2529.25341796875, 243.217742919921875, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+2, 180406, 0, 3, 5564, '0', 0, 0, -7035.1943359375, -2575.94970703125, 253.75103759765625, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+3, 180407, 0, 3, 5564, '0', 0, 0, -7034.7431640625, -2540.6650390625, 253.2794342041015625, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+4, 180407, 0, 3, 5564, '0', 0, 0, -6998.26220703125, -2517.55029296875, 241.7515411376953125, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+5, 180408, 0, 3, 5564, '0', 0, 0, -6993.1875, -2547.814208984375, 246.2427825927734375, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+6, 180410, 0, 3, 5564, '0', 0, 0, -7042.73779296875, -2573.5400390625, 254.078643798828125, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 51886), -- G_HangingSkeleton_01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+7, 180411, 0, 3, 5564, '0', 0, 0, -7033.21875, -2535.35595703125, 260.396881103515625, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 51886), -- G_Ghost_01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+8, 180415, 0, 3, 5564, '0', 0, 0, -7040.99853515625, -2567.53466796875, 253.3317108154296875, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 51886), -- CandleBlack01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+9, 180415, 0, 3, 5564, '0', 0, 0, -6995.91162109375, -2542.359375, 242.7194366455078125, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 120, 255, 1, 51886), -- CandleBlack01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+10, 180415, 0, 3, 5564, '0', 0, 0, -6996.251953125, -2542.382080078125, 242.7102813720703125, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 51886), -- CandleBlack01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+11, 180425, 0, 3, 5564, '0', 0, 0, -7033.125, -2549.257080078125, 252.693878173828125, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 51886), -- SkullCandle01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+12, 180425, 0, 3, 5564, '0', 0, 0, -7040.9287109375, -2565.569580078125, 254.166778564453125, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 51886), -- SkullCandle01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+13, 180425, 0, 3, 5564, '0', 0, 0, -6997.9912109375, -2544.197998046875, 242.737579345703125, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 51886), -- SkullCandle01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+14, 180426, 0, 3, 5564, '0', 0, 0, -7020.765625, -2555.935791015625, 254.18536376953125, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, 51886), -- Bat01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+15, 180426, 0, 3, 5564, '0', 0, 0, -7015.1337890625, -2552.248291015625, 256.81298828125, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 51886), -- Bat01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+16, 180426, 0, 3, 5564, '0', 0, 0, -7004.3349609375, -2540.255126953125, 247.265594482421875, 4.433136463165283203, 0, 0, -0.79863548278808593, 0.60181504487991333, 120, 255, 1, 51886), -- Bat01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+17, 180427, 0, 3, 5564, '0', 0, 0, -7008.07666015625, -2556.4375, 258.976043701171875, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 120, 255, 1, 51886), -- Bat02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+18, 180427, 0, 3, 5564, '0', 0, 0, -7016.62841796875, -2557.90283203125, 251.0806732177734375, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 120, 255, 1, 51886), -- Bat02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+19, 180427, 0, 3, 5564, '0', 0, 0, -7003.470703125, -2548.078125, 252.189910888671875, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 120, 255, 1, 51886), -- Bat02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+20, 180471, 0, 3, 5564, '0', 0, 0, -7041.31787109375, -2550.654541015625, 254.7256622314453125, 5.445427894592285156, 0, 0, -0.40673637390136718, 0.913545548915863037, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+21, 180471, 0, 3, 5564, '0', 0, 0, -7031.390625, -2544.3125, 254.70147705078125, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+22, 180471, 0, 3, 5564, '0', 0, 0, -7033.19287109375, -2552.46875, 254.742462158203125, 0.349065244197845458, 0, 0, 0.173647880554199218, 0.984807789325714111, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+23, 180471, 0, 3, 5564, '0', 0, 0, -7039.515625, -2542.49658203125, 254.7635650634765625, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+24, 180472, 0, 3, 5564, '0', 0, 0, -7036.2431640625, -2560.645751953125, 252.0963287353515625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+25, 180523, 0, 3, 5564, '0', 0, 0, -7003.7255859375, -2528.96875, 241.9618377685546875, 0.541050612926483154, 0, 0, 0.267237663269042968, 0.96363067626953125, 120, 255, 1, 51886), -- Apple Bob (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+26, 185434, 0, 3, 5564, '0', 0, 0, -7007.63916015625, -2528.928955078125, 241.7134552001953125, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 120, 255, 1, 51886), -- Sitting Skeleton 01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+27, 185435, 0, 3, 5564, '0', 0, 0, -6991.015625, -2543.057373046875, 241.7134552001953125, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 120, 255, 1, 51886), -- Sitting Skeleton 02 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+28, 185437, 0, 3, 5564, '0', 0, 0, -7011.88720703125, -2539.13720703125, 241.7134552001953125, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 120, 255, 1, 51886), -- Laying Skeleton 01 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+29, 185438, 0, 3, 5564, '0', 0, 0, -7039.8369140625, -2569.94970703125, 252.457275390625, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 120, 255, 1, 51886), -- Sitting Skeleton 04 (Area: Dragon's Mouth - Difficulty: 0) CreateObject1
(@OGUID+30, 208121, 0, 3, 5564, '0', 0, 0, -7006.34716796875, -2542.850830078125, 241.7134552001953125, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 120, 255, 1, 51886); -- Candy Bucket (Area: Dragon's Mouth - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid`=@CGUID+0;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+30;
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
(12, @OGUID+30);
