SET @OGUID := 245913;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208115; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=208115; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28951;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28951, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208115;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208115, 28951, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208115 AND `quest`=28951);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208115;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 148, 4659, '0', 0, 0, 7411.1162109375, -278.234375, 8.934340476989746093, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+1, 180406, 1, 148, 4659, '0', 0, 0, 7381.33251953125, -263.53125, 12.09750843048095703, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+2, 180407, 1, 148, 4659, '0', 0, 0, 7394.3125, -250.383682250976562, 7.181427001953125, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Lor'danel - Difficulty: 0)
(@OGUID+3, 180408, 1, 148, 4659, '0', 0, 0, 7381.2958984375, -263.614593505859375, 13.7848825454711914, 4.014260292053222656, 0, 0, -0.90630722045898437, 0.422619491815567016, 120, 255, 1, 46366), -- G_WitchHat_01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+4, 180410, 1, 148, 4659, '0', 0, 0, 7435.2978515625, -264.880218505859375, 13.7694549560546875, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 46366), -- G_HangingSkeleton_01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+5, 180411, 1, 148, 4659, '0', 0, 0, 7410.98095703125, -272.861114501953125, 13.40834999084472656, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- G_Ghost_01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+6, 180415, 1, 148, 4659, '0', 0, 0, 7395.01806640625, -262.899322509765625, 7.42963409423828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+7, 180415, 1, 148, 4659, '0', 0, 0, 7395.0244140625, -261.642364501953125, 7.437504291534423828, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+8, 180415, 1, 148, 4659, '0', 0, 0, 7393.76806640625, -261.6319580078125, 7.419237613677978515, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+9, 180415, 1, 148, 4659, '0', 0, 0, 7393.78564453125, -262.883697509765625, 7.425035953521728515, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+10, 180425, 1, 148, 4659, '0', 0, 0, 7394.38525390625, -262.25347900390625, 7.56592559814453125, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 120, 255, 1, 46366), -- SkullCandle01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+11, 180426, 1, 148, 4659, '0', 0, 0, 7373.4912109375, -250.699661254882812, 7.587674617767333984, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+12, 180426, 1, 148, 4659, '0', 0, 0, 7367.265625, -263.35589599609375, 8.791996002197265625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+13, 180426, 1, 148, 4659, '0', 0, 0, 7370.84375, -261.857635498046875, 7.386890888214111328, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+14, 180426, 1, 148, 4659, '0', 0, 0, 7354.90966796875, -244.26910400390625, 8.128786087036132812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+15, 180427, 1, 148, 4659, '0', 0, 0, 7371.91748046875, -252.482635498046875, 7.57148599624633789, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+16, 180427, 1, 148, 4659, '0', 0, 0, 7360.20654296875, -266.84722900390625, 7.565318584442138671, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+17, 180427, 1, 148, 4659, '0', 0, 0, 7379.4384765625, -246.286453247070312, 7.336325645446777343, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+18, 180427, 1, 148, 4659, '0', 0, 0, 7355.89404296875, -248.864578247070312, 7.988028526306152343, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+19, 180472, 1, 148, 4659, '0', 0, 0, 7446.35400390625, -271.11285400390625, 17.94329833984375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Lor'danel - Difficulty: 0)
(@OGUID+20, 208115, 1, 148, 4659, '0', 0, 0, 7408.3193359375, -267.013885498046875, 8.931618690490722656, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 120, 255, 1, 46366); -- Candy Bucket (Area: Lor'danel - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+20;
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
(12, @OGUID+20);
