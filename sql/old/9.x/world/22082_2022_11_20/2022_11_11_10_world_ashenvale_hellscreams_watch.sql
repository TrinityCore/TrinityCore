SET @OGUID := 246380;

-- Gameobject templates
UPDATE `gameobject_template` SET `Data6`=0, `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=208118; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=208118; -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID`=28958;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28958, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 46366); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id`=208118;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(208118, 28958, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=208118 AND `quest`=28958);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=208118;

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 228740 AND 228756;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 228740 AND 228756;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 1, 331, 4691, '0', 0, 0, 3003.99658203125, -481.645843505859375, 204.9393310546875, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+1, 180405, 1, 331, 4691, '0', 0, 0, 3041.913330078125, -496.395843505859375, 205.6269073486328125, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 120, 255, 1, 46366), -- G_Pumpkin_01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+2, 180406, 1, 331, 4691, '0', 0, 0, 2995.953125, -475.755218505859375, 204.8974609375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- G_Pumpkin_02 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+3, 180407, 1, 331, 4691, '0', 0, 0, 3037.11376953125, -541.529541015625, 205.6391754150390625, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+4, 180408, 1, 331, 4691, '0', 0, 0, 2989.84716796875, -510.84375, 199.8038482666015625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- G_WitchHat_01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+5, 180415, 1, 331, 4691, '0', 0, 0, 3042.66064453125, -534.87847900390625, 205.6391754150390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+6, 180415, 1, 331, 4691, '0', 0, 0, 3043.99560546875, -535.4375, 205.6391754150390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+7, 180415, 1, 331, 4691, '0', 0, 0, 3043.185791015625, -533.5711669921875, 205.6391754150390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- CandleBlack01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+8, 180425, 1, 331, 4691, '0', 0, 0, 3044.537353515625, -533.89410400390625, 207.7189178466796875, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 46366), -- SkullCandle01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+9, 180426, 1, 331, 4691, '0', 0, 0, 3012.491455078125, -503.782989501953125, 203.0664825439453125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+10, 180426, 1, 331, 4691, '0', 0, 0, 3006.896728515625, -509.59027099609375, 201.7289581298828125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+11, 180426, 1, 331, 4691, '0', 0, 0, 3028.29248046875, -515.703125, 203.3932952880859375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+12, 180427, 1, 331, 4691, '0', 0, 0, 3015.93408203125, -530.6875, 206.3615264892578125, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+13, 180427, 1, 331, 4691, '0', 0, 0, 3007.53564453125, -510.723968505859375, 201.748626708984375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+14, 180427, 1, 331, 4691, '0', 0, 0, 3017.497314453125, -515.69793701171875, 203.260833740234375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bat02 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+15, 180472, 1, 331, 4691, '0', 0, 0, 3045.37060546875, -533.763916015625, 211.114501953125, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+16, 180523, 1, 331, 4691, '0', 0, 0, 3044.5390625, -523.30902099609375, 206.0875701904296875, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 46366), -- Apple Bob (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+17, 185434, 1, 331, 4691, '0', 0, 0, 3043.869873046875, -534.421875, 205.6391754150390625, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 46366), -- Sitting Skeleton 01 (Area: Hellscream's Watch - Difficulty: 0)
(@OGUID+18, 208118, 1, 331, 4691, '0', 0, 0, 3045.42529296875, -529.10589599609375, 205.6391754150390625, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 46366); -- Candy Bucket (Area: Hellscream's Watch - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+18;
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
(12, @OGUID+18);
