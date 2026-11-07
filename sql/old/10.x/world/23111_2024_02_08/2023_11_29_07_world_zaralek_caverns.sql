SET @OGUID := 9003849;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (401756, 401757);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(401756, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401757, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26303, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (401756, 401757);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(401756, 35, 4, 0, 0), -- Candy Bucket
(401757, 35, 4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (75703, 75704);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75703, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75704, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (401756, 401757);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(401756, 75703, 51886),
(401757, 75704, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (401756, 401757);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(401756, 75703, 51886),
(401757, 75704, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+13;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Obsidian Rest
(@OGUID+0, 180405, 2454, 14022, 14022, '0', 0, 0, 1044.1146240234375, 2273.864501953125, -172.66583251953125, 2.373700141906738281, 0, 0, 0.927193641662597656, 0.374582380056381225, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2454, 14022, 14022, '0', 0, 0, 1067.40283203125, 2317.73779296875, -175.740432739257812, 3.74632430076599121, 0, 0, -0.95463466644287109, 0.297779500484466552, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2454, 14022, 14022, '0', 0, 0, 1055.1041259765625, 2237.517333984375, -171.868255615234375, 3.361844539642333984, 0, 0, -0.9939422607421875, 0.109903424978256225, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2454, 14022, 14022, '0', 0, 0, 1044.1910400390625, 2273.9375, -171.333236694335937, 1.971414804458618164, 0, 0, 0.833662986755371093, 0.552273511886596679, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2454, 14022, 14022, '0', 0, 0, 1051.8853759765625, 2277.098876953125, -175.552215576171875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2454, 14022, 14022, '0', 0, 0, 1042.4722900390625, 2269.1025390625, -175.566360473632812, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
(@OGUID+6, 401756, 2454, 14022, 14022, '0', 0, 0, 1047.217041015625, 2282.857666015625, -175.459060668945312, 1.10980236530303955, 0, 0, 0.526859283447265625, 0.849952518939971923, 120, 255, 1, 51886), -- Candy Bucket (Area: Zaralek Cavern - Difficulty: 0) CreateObject1
-- Loamm
(@OGUID+7, 180405, 2454, 14022, 14520, '0', 0, 0, -409.8975830078125, 1965.49658203125, -58.76666259765625, 5.435338497161865234, 0, 0, -0.41133975982666015, 0.911482095718383789, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2454, 14022, 14520, '0', 0, 0, -387.56597900390625, 2004.34033203125, -58.7471466064453125, 3.74632430076599121, 0, 0, -0.95463466644287109, 0.297779500484466552, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2454, 14022, 14520, '0', 0, 0, -348.645843505859375, 1981.7847900390625, -58.7443733215332031, 2.169034957885742187, 0, 0, 0.884078025817871093, 0.467339307069778442, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2454, 14022, 14520, '0', 0, 0, -370.91839599609375, 1943.44970703125, -58.6824684143066406, 0.495532929897308349, 0, 0, 0.2452392578125, 0.969462573528289794, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2454, 14022, 14520, '0', 0, 0, -377.114593505859375, 1986.5711669921875, -65.2900466918945312, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2454, 14022, 14520, '0', 0, 0, -371.270843505859375, 1985.94970703125, -66.2092819213867187, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Loamm - Difficulty: 0) CreateObject1
(@OGUID+13, 401757, 2454, 14022, 14520, '0', 0, 0, -400.473968505859375, 1973.3802490234375, -64.643707275390625, 1.10980236530303955, 0, 0, 0.526859283447265625, 0.849952518939971923, 120, 255, 1, 51886); -- Candy Bucket (Area: Loamm - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+13;
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
(12, @OGUID+13);
