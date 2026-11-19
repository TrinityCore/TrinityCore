SET @OGUID := 3004071;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=51886 WHERE `entry`=208135; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208135; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28991;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28991, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208135;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208135, 28991, 51886);

UPDATE `gameobject_questender` SET `VerifiedBuild`=51886 WHERE (`id`=208135 AND `quest`=28991);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208135;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 230567 AND 230597;
DELETE FROM `gameobject` WHERE `guid`=231997;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 230567 AND 230597;
DELETE FROM `game_event_gameobject` WHERE `guid`=231997;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+49;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 11, 5305, '0', 0, 0, -3213.479248046875, -2662.052001953125, 9.070924758911132812, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+1, 180405, 0, 11, 5305, '0', 0, 0, -3232.411376953125, -2775.147705078125, 21.12751579284667968, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+2, 180405, 0, 11, 5305, '0', 0, 0, -3332.526123046875, -2769.291748046875, 50.91151809692382812, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+3, 180405, 0, 11, 5305, '0', 0, 0, -3362.173583984375, -2760.395751953125, 50.91151046752929687, 5.462882041931152343, 0, 0, -0.39874839782714843, 0.917060375213623046, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+4, 180406, 0, 11, 5305, '0', 0, 0, -3221.060791015625, -2663.572998046875, 9.146597862243652343, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+5, 180406, 0, 11, 5305, '0', 0, 0, -3243.9306640625, -2783.625, 21.1275177001953125, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+6, 180406, 0, 11, 5305, '0', 0, 0, -3310.814208984375, -2724.295166015625, 20.48355865478515625, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+7, 180406, 0, 11, 5305, '0', 0, 0, -3323.234375, -2738.791748046875, 50.91151809692382812, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+8, 180407, 0, 11, 5305, '0', 0, 0, -3252.1025390625, -2775.182373046875, 13.22046947479248046, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 0, 11, 5305, '0', 0, 0, -3352.677001953125, -2729.61279296875, 50.91151046752929687, 4.206246376037597656, 0, 0, -0.86162853240966796, 0.50753939151763916, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+10, 180411, 0, 11, 5305, '0', 0, 0, -3324.592041015625, -2747.569580078125, 33.90011215209960937, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 120, 255, 1, 51886), -- G_Ghost_01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 0, 11, 5305, '0', 0, 0, -3248.569580078125, -2773.553955078125, 15.58920764923095703, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+12, 180415, 0, 11, 5305, '0', 0, 0, -3242.14404296875, -2765.060791015625, 13.6106119155883789, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+13, 180415, 0, 11, 5305, '0', 0, 0, -3240.859375, -2767.861083984375, 15.55647945404052734, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+14, 180415, 0, 11, 5305, '0', 0, 0, -3245.92529296875, -2776.13720703125, 17.70518302917480468, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+15, 180415, 0, 11, 5305, '0', 0, 0, -3250.772705078125, -2771.37158203125, 13.6251382827758789, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+16, 180415, 0, 11, 5305, '0', 0, 0, -3239.119873046875, -2771.40283203125, 17.81036567687988281, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+17, 180415, 0, 11, 5305, '0', 0, 0, -3237.520751953125, -2774.34375, 19.56087684631347656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+18, 180415, 0, 11, 5305, '0', 0, 0, -3236.475830078125, -2776.578125, 20.82664299011230468, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+19, 180415, 0, 11, 5305, '0', 0, 0, -3241.513916015625, -2780.322998046875, 20.86226844787597656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+20, 180415, 0, 11, 5305, '0', 0, 0, -3243.53466796875, -2778.623291015625, 19.52212715148925781, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+21, 180415, 0, 11, 5305, '0', 0, 0, -3326.447998046875, -2747.973876953125, 29.86408805847167968, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+22, 180415, 0, 11, 5305, '0', 0, 0, -3330.06591796875, -2759.635498046875, 29.86320686340332031, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+23, 180415, 0, 11, 5305, '0', 0, 0, -3324.5, -2762.130126953125, 27.62269020080566406, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+24, 180415, 0, 11, 5305, '0', 0, 0, -3327.538330078125, -2760.998291015625, 28.98279190063476562, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+25, 180415, 0, 11, 5305, '0', 0, 0, -3323.604248046875, -2748.55908203125, 28.94002342224121093, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+26, 180415, 0, 11, 5305, '0', 0, 0, -3320.611083984375, -2749.00341796875, 27.67959213256835937, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+27, 180425, 0, 11, 5305, '0', 0, 0, -3252.194580078125, -2772.4150390625, 15.58044147491455078, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 51886), -- SkullCandle01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+28, 180425, 0, 11, 5305, '0', 0, 0, -3223.494873046875, -2786.505126953125, 22.92118453979492187, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 51886), -- SkullCandle01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+29, 180426, 0, 11, 5305, '0', 0, 0, -3249.546875, -2744.600830078125, 22.19921302795410156, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+30, 180426, 0, 11, 5305, '0', 0, 0, -3286.579833984375, -2725.953125, 23.09676551818847656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+31, 180426, 0, 11, 5305, '0', 0, 0, -3259.5556640625, -2748.614501953125, 22.60544776916503906, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+32, 180426, 0, 11, 5305, '0', 0, 0, -3217.671875, -2735.954833984375, 24.28947639465332031, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+33, 180426, 0, 11, 5305, '0', 0, 0, -3275.15283203125, -2757.25, 22.51864051818847656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+34, 180426, 0, 11, 5305, '0', 0, 0, -3287.61279296875, -2752.53466796875, 23.10024452209472656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+35, 180426, 0, 11, 5305, '0', 0, 0, -3286.763916015625, -2772.708251953125, 22.26169776916503906, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+36, 180427, 0, 11, 5305, '0', 0, 0, -3228.92529296875, -2715.498291015625, 21.38068389892578125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+37, 180427, 0, 11, 5305, '0', 0, 0, -3283.015625, -2711.333251953125, 22.24781227111816406, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+38, 180427, 0, 11, 5305, '0', 0, 0, -3239.19970703125, -2735.666748046875, 21.06899452209472656, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+39, 180427, 0, 11, 5305, '0', 0, 0, -3278.0869140625, -2729.6494140625, 20.86760139465332031, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+40, 180427, 0, 11, 5305, '0', 0, 0, -3271.005126953125, -2746.65283203125, 22.30317878723144531, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+41, 180427, 0, 11, 5305, '0', 0, 0, -3280.579833984375, -2762.423583984375, 22.71308326721191406, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Bat02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+42, 180471, 0, 11, 5305, '0', 0, 0, -3234.76904296875, -2779.614501953125, 24.5140533447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+43, 180471, 0, 11, 5305, '0', 0, 0, -3238.991455078125, -2782.720458984375, 24.60868072509765625, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+44, 180471, 0, 11, 5305, '0', 0, 0, -3238.005126953125, -2782.140625, 25.26064491271972656, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+45, 180471, 0, 11, 5305, '0', 0, 0, -3235.651123046875, -2780.366455078125, 25.1731414794921875, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 120, 255, 1, 51886), -- HangingSkullLight01 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+46, 180472, 0, 11, 5305, '0', 0, 0, -3236.607666015625, -2781.638916015625, 26.77636146545410156, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+47, 180472, 0, 11, 5305, '0', 0, 0, -3333.541748046875, -2752.298583984375, 35.06074905395507812, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 51886), -- HangingSkullLight02 (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+48, 180523, 0, 11, 5305, '0', 0, 0, -3235.24658203125, -2793.890625, 21.56790351867675781, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1
(@OGUID+49, 208135, 0, 11, 5305, '0', 0, 0, -3228.350830078125, -2796.87841796875, 21.12751388549804687, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 120, 255, 1, 51886); -- Candy Bucket (Area: Greenwarden's Grove - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+49;
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
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40),
(12, @OGUID+41),
(12, @OGUID+42),
(12, @OGUID+43),
(12, @OGUID+44),
(12, @OGUID+45),
(12, @OGUID+46),
(12, @OGUID+47),
(12, @OGUID+48),
(12, @OGUID+49);
