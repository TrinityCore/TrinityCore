SET @OGUID := 10800309;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (464916, 464918, 464915, 464917);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(464915, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27765, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464916, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27766, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464917, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27767, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212), -- Candy Bucket
(464918, 2, 98384, 'Candy Bucket', '', '', '', 1, 0, 27768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 57212); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (464916, 464918, 464915, 464917);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(464918, 35, 0x4, 0, 0), -- Candy Bucket
(464917, 35, 0x4, 0, 0), -- Candy Bucket
(464916, 35, 0x4, 0, 0), -- Candy Bucket
(464915, 35, 0x4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_offer_reward` WHERE `ID` IN (84569, 84571, 84568, 84570);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(84569, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84571, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84568, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212), -- Candy Bucket
(84570, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 57212); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (464916, 464918, 464915, 464917);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(464916, 84569, 57212),
(464918, 84571, 57212),
(464915, 84568, 57212),
(464917, 84570, 57212);

DELETE FROM `gameobject_questender` WHERE `id` IN (464916, 464918, 464915, 464917);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(464916, 84569, 57212),
(464918, 84571, 57212),
(464915, 84568, 57212),
(464917, 84570, 57212);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+27;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Gundargaz
(@OGUID+0, 180405, 2601, 14795, 14796, '0', 0, 0, 2279.751708984375, -2812.038330078125, 422.097869873046875, 3.270492076873779296, 0, 0, -0.99792385101318359, 0.064405016601085662, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2601, 14795, 14796, '0', 0, 0, 2290.053955078125, -2784.807373046875, 422.12261962890625, 3.840990066528320312, 0, 0, -0.93947601318359375, 0.342614650726318359, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2601, 14795, 14796, '0', 0, 0, 2277.229248046875, -2785.282958984375, 422.12261962890625, 3.098575353622436523, 0.031404018402099609, 0.077432632446289062, 0.996319770812988281, 0.019102346152067184, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2601, 14795, 14796, '0', 0, 0, 2269.354248046875, -2843.94970703125, 419.999755859375, 2.282637834548950195, 0, 0, 0.909183502197265625, 0.416395694017410278, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2601, 14795, 14796, '0', 0, 0, 2276.897705078125, -2771.44970703125, 418.2684326171875, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2601, 14795, 14796, '0', 0, 0, 2287.822998046875, -2798.69091796875, 422.33428955078125, 5.76935577392578125, 0, 0, -0.25409793853759765, 0.96717846393585205, 120, 255, 1, 57212), -- Apple Bob (Area: Gundargaz - Difficulty: 0) CreateObject1
(@OGUID+6, 464916, 2601, 14795, 14796, '0', 0, 0, 2287.645751953125, -2804.95654296875, 422.102569580078125, 4.18001556396484375, 0, 0, -0.8682107925415039, 0.496195554733276367, 120, 255, 1, 57212), -- Candy Bucket (Area: Gundargaz - Difficulty: 0) CreateObject1
-- Shadowvein Point
(@OGUID+7, 180405, 2601, 14795, 14820, '0', 0, 0, 1599.232666015625, -3812.104248046875, 255.62255859375, 4.749365806579589843, 0, 0, -0.69391345977783203, 0.720058381557464599, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2601, 14795, 14820, '0', 0, 0, 1598.4583740234375, -3816.428955078125, 255.5192413330078125, 4.749752521514892578, 0, 0, -0.69377422332763671, 0.720192551612854003, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2601, 14795, 14820, '0', 0, 0, 1597.3992919921875, -3817.960205078125, 255.6678314208984375, 4.072836875915527343, 0.008494377136230468, -0.08312606811523437, -0.88936901092529296, 0.449489355087280273, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2601, 14795, 14820, '0', 0, 0, 1599.267333984375, -3812.1806640625, 257.0430908203125, 4.502972602844238281, -0.02341556549072265, 0.0259246826171875, -0.77670574188232421, 0.62889409065246582, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2601, 14795, 14820, '0', 0, 0, 1597.7222900390625, -3814.501708984375, 257.80535888671875, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2601, 14795, 14820, '0', 0, 0, 1606.4288330078125, -3800.9375, 277.739471435546875, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Shadowvein Point - Difficulty: 0) CreateObject1
(@OGUID+13, 464918, 2601, 14795, 14820, '0', 0, 0, 1605.328125, -3813.388916015625, 257.0888671875, 2.536118507385253906, 0, 0, 0.954524040222167968, 0.298133999109268188, 120, 255, 1, 57212), -- Candy Bucket (Area: Shadowvein Point - Difficulty: 0) CreateObject1
-- Camp Murroch
(@OGUID+14, 180405, 2601, 14795, 14814, '0', 0, 0, 746.7742919921875, -3592.8681640625, 174.9847869873046875, 3.836617946624755859, 0, 0, -0.94022274017333984, 0.340560168027877807, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+15, 180406, 2601, 14795, 14814, '0', 0, 0, 736.11456298828125, -3619.29345703125, 176.1065826416015625, 2.817041397094726562, 0, 0, 0.9868621826171875, 0.161564290523529052, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+16, 180407, 2601, 14795, 14814, '0', 0, 0, 747.69793701171875, -3619.460205078125, 175.724090576171875, 3.8984375, 0.001222610473632812, -0.08354949951171875, -0.92513561248779296, 0.370326966047286987, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+17, 180408, 2601, 14795, 14814, '0', 0, 0, 747.6024169921875, -3619.298583984375, 177.2816925048828125, 3.79250502586364746, 0, 0, -0.94750499725341796, 0.319740980863571166, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+18, 180415, 2601, 14795, 14814, '0', 0, 0, 750.013916015625, -3588.69091796875, 176.6130218505859375, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+19, 180523, 2601, 14795, 14814, '0', 0, 0, 740.72918701171875, -3639.27783203125, 168.8269805908203125, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Camp Murroch - Difficulty: 0) CreateObject1
(@OGUID+20, 464915, 2601, 14795, 14814, '0', 0, 0, 748.609375, -3639.6875, 168.82696533203125, 3.813741683959960937, 0, 0, -0.94405651092529296, 0.329783737659454345, 120, 255, 1, 57212), -- Candy Bucket (Area: Camp Murroch - Difficulty: 0) CreateObject1
-- Opportunity Point
(@OGUID+21, 180405, 2601, 14795, 14812, '0', 0, 0, 51.6805572509765625, -3938.5869140625, 121.928253173828125, 6.107064247131347656, 0, 0, -0.08794689178466796, 0.99612516164779663, 120, 255, 1, 57212), -- G_Pumpkin_01 (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+22, 180406, 2601, 14795, 14812, '0', 0, 0, 47.19444656372070312, -3933.845458984375, 121.7143936157226562, 4.749752521514892578, 0, 0, -0.69377422332763671, 0.720192551612854003, 120, 255, 1, 57212), -- G_Pumpkin_02 (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+23, 180407, 2601, 14795, 14812, '0', 0, 0, 30.765625, -3923.1181640625, 123.9784088134765625, 1.391303539276123046, 0.078999519348144531, 0.027223587036132812, 0.640431404113769531, 0.763456344604492187, 120, 255, 1, 57212), -- G_Pumpkin_03 (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+24, 180408, 2601, 14795, 14812, '0', 0, 0, 32.42534637451171875, -3920.3125, 123.827789306640625, 3.79250502586364746, 0, 0, -0.94750499725341796, 0.319740980863571166, 120, 255, 1, 57212), -- G_WitchHat_01 (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+25, 180415, 2601, 14795, 14812, '0', 0, 0, 38.67534637451171875, -3921.888916015625, 122.7741470336914062, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- CandleBlack01 (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+26, 180523, 2601, 14795, 14812, '0', 0, 0, 46.67882156372070312, -3921.328125, 121.6689224243164062, 0, 0, 0, 0, 1, 120, 255, 1, 57212), -- Apple Bob (Area: Opportunity Point - Difficulty: 0) CreateObject1
(@OGUID+27, 464917, 2601, 14795, 14812, '0', 0, 0, 31.95659828186035156, -3924.810791015625, 121.6719589233398437, 0.947317540645599365, 0, 0, 0.456145286560058593, 0.889905333518981933, 120, 255, 1, 57212); -- Candy Bucket (Area: Opportunity Point - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+27;
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
(12, @OGUID+27);
