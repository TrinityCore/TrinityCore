SET @OGUID := 9003807;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (401714, 401723, 401724, 401725, 401726);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(401714, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26268, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401723, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401724, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26270, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401725, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401726, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (401714, 401723, 401724, 401725, 401726);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(401714, 35, 4, 0, 0), -- Candy Bucket
(401723, 35, 4, 0, 0), -- Candy Bucket
(401724, 35, 4, 0, 0), -- Candy Bucket
(401725, 35, 4, 0, 0), -- Candy Bucket
(401726, 35, 4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (75667, 75668, 75669, 75670, 75671);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75667, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75668, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75669, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75670, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75671, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (401714, 401723, 401724, 401725, 401726);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(401714, 75667, 51886),
(401723, 75668, 51886),
(401724, 75669, 51886),
(401725, 75670, 51886),
(401726, 75671, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (401714, 401723, 401724, 401725, 401726);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(401714, 75667, 51886),
(401723, 75668, 51886),
(401724, 75669, 51886),
(401725, 75670, 51886),
(401726, 75671, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+34;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Three-Falls Lookout
(@OGUID+0, 180405, 2444, 13646, 13646, '0', 0, 0, -2692.13720703125, 3455.317626953125, 445.47210693359375, 1.476740002632141113, 0, 0, 0.673083305358886718, 0.739566683769226074, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2444, 13646, 13646, '0', 0, 0, -2691.32470703125, 3460.1416015625, 449.82269287109375, 2.06798410415649414, 0, 0, 0.859347343444824218, 0.51139235496520996, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2444, 13646, 13646, '0', 0, 0, -2687.802001953125, 3441.611083984375, 443.239410400390625, 2.104104518890380859, 0, 0, 0.868442535400390625, 0.49578985571861267, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2444, 13646, 13646, '0', 0, 0, -2696.239501953125, 3458.474853515625, 446.63116455078125, 2.216573715209960937, 0, 0, 0.89493560791015625, 0.44619530439376831, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2444, 13646, 13646, '0', 0, 0, -2692.826416015625, 3453.267333984375, 447.345855712890625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2444, 13646, 13646, '0', 0, 0, -2708.322998046875, 3451.677978515625, 445.47210693359375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+6, 401726, 2444, 13646, 13646, '0', 0, 0, -2708.869873046875, 3445.353271484375, 445.47210693359375, 2.715264797210693359, 0, 0, 0.977366447448730468, 0.211553305387496948, 120, 255, 1, 51886), -- Candy Bucket (Area: The Azure Span - Difficulty: 0) CreateObject1
-- Theron's Watch
(@OGUID+7, 180405, 2444, 13646, 13860, '0', 0, 0, -2114.486083984375, -1626.2430419921875, 972.80987548828125, 2.810218334197998046, 0, 0, 0.98630523681640625, 0.164930135011672973, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2444, 13646, 13860, '0', 0, 0, -2092.822998046875, -1652.3836669921875, 972.5986328125, 4.0184478759765625, 0, 0, -0.90542030334472656, 0.424516260623931884, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2444, 13646, 13860, '0', 0, 0, -2075.87841796875, -1634.1163330078125, 973.97540283203125, 5.025073051452636718, 0, 0, -0.58838176727294921, 0.808583259582519531, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2444, 13646, 13860, '0', 0, 0, -2104.828125, -1641.41845703125, 980.6954345703125, 2.009676456451416015, 0, 0, 0.844075202941894531, 0.536224782466888427, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2444, 13646, 13860, '0', 0, 0, -2104.060791015625, -1637.73095703125, 974.04571533203125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2444, 13646, 13860, '0', 0, 0, -2110.19970703125, -1637.3333740234375, 973.16668701171875, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Upper Frostlands - Difficulty: 0) CreateObject1
(@OGUID+13, 401725, 2444, 13646, 13860, '0', 0, 0, -2106.848876953125, -1637.8785400390625, 972.77471923828125, 2.258838653564453125, 0, 0, 0.904164314270019531, 0.427184849977493286, 120, 255, 1, 51886), -- Candy Bucket (Area: Upper Frostlands - Difficulty: 0) CreateObject1
-- Camp Antonidas
(@OGUID+14, 180405, 2444, 13646, 13646, '0', 0, 0, -3840.953125, 371.19097900390625, 662.53045654296875, 4.367660045623779296, 0, 0, -0.81790637969970703, 0.575351357460021972, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+15, 180406, 2444, 13646, 13646, '0', 0, 0, -3842.064208984375, 398.814239501953125, 658.50177001953125, 4.049228668212890625, 0, 0, -0.89877986907958984, 0.438400238752365112, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+16, 180407, 2444, 13646, 13646, '0', 0, 0, -3836.28125, 414.3038330078125, 656.61236572265625, 3.410333871841430664, 0, 0, -0.99098587036132812, 0.13396647572517395, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+17, 180408, 2444, 13646, 13646, '0', 0, 0, -3847.73779296875, 415.8507080078125, 660.3275146484375, 3.165673255920410156, 0, 0, -0.99992752075195312, 0.012039870955049991, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+18, 180415, 2444, 13646, 13646, '0', 0, 0, -3856.171875, 383.411468505859375, 659.76153564453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+19, 180523, 2444, 13646, 13646, '0', 0, 0, -3852.84375, 371.4444580078125, 658.50201416015625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: The Azure Span - Difficulty: 0) CreateObject1
(@OGUID+20, 401714, 2444, 13646, 13646, '0', 0, 0, -3849.463623046875, 372.85589599609375, 658.50201416015625, 3.69903111457824707, 0, 0, -0.96140861511230468, 0.27512449026107788, 120, 255, 1, 51886), -- Candy Bucket (Area: The Azure Span - Difficulty: 0) CreateObject1
-- Iskaara
(@OGUID+21, 180405, 2444, 13646, 0, '0', 0, 0, -4514.38525390625, 4099.7890625, 10.19736480712890625, 0.481678545475006103, 0, 0, 0.23851776123046875, 0.9711381196975708, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+22, 180406, 2444, 13646, 0, '0', 0, 0, -4501.22412109375, 4101.3203125, 11.51589775085449218, 0.472588151693344116, 0, 0, 0.234101295471191406, 0.972212195396423339, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+23, 180407, 2444, 13646, 0, '0', 0, 0, -4483.4443359375, 4081.046142578125, 9.231167793273925781, 0.776706814765930175, 0, 0, 0.378664970397949218, 0.925533831119537353, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+24, 180408, 2444, 13646, 0, '0', 0, 0, -4501.236328125, 4101.548828125, 13.14325904846191406, 0.048659358173608779, 0, 0, 0.024327278137207031, 0.999704062938690185, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+25, 180415, 2444, 13646, 0, '0', 0, 0, -4515.58154296875, 4101.30029296875, 11.4425973892211914, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+26, 180523, 2444, 13646, 0, '0', 0, 0, -4504.31103515625, 4143.58251953125, -0.787750244140625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+27, 401724, 2444, 13646, 0, '0', 0, 0, -4507.75, 4145.9443359375, 0.303688317537307739, 6.198924541473388671, 0, 0, -0.04211807250976562, 0.999112606048583984, 120, 255, 1, 51886), -- Candy Bucket (Area: 0 - Difficulty: 0) CreateObject1
-- Camp Nowhere
(@OGUID+28, 180405, 2444, 13646, 13829, '0', 0, 0, -5131.7255859375, -1357.4166259765625, 536.84637451171875, 5.336071491241455078, 0, 0, -0.4560546875, 0.889951765537261962, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+29, 180406, 2444, 13646, 13829, '0', 0, 0, -5137.55029296875, -1350.15283203125, 536.77398681640625, 5.950006484985351562, 0, 0, -0.16582012176513671, 0.986155986785888671, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+30, 180407, 2444, 13646, 13829, '0', 0, 0, -5130.5400390625, -1363.7083740234375, 539.60205078125, 6.156475543975830078, 0, 0, -0.06331253051757812, 0.997993767261505126, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+31, 180408, 2444, 13646, 13829, '0', 0, 0, -5130.53662109375, -1363.71533203125, 541.10333251953125, 5.701016902923583984, 0, 0, -0.28699111938476562, 0.957933247089385986, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+32, 180415, 2444, 13646, 13829, '0', 0, 0, -5136.07275390625, -1351.7135009765625, 538.64093017578125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+33, 180523, 2444, 13646, 13829, '0', 0, 0, -5120.38525390625, -1347.3160400390625, 536.75958251953125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Timbertooth Trail - Difficulty: 0) CreateObject1
(@OGUID+34, 401723, 2444, 13646, 13829, '0', 0, 0, -5117.2099609375, -1341.6285400390625, 537.87335205078125, 5.057301521301269531, 0, 0, -0.57527637481689453, 0.817959129810333251, 120, 255, 1, 51886); -- Candy Bucket (Area: Timbertooth Trail - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+34;
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
(12, @OGUID+34);
