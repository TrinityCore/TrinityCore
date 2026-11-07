SET @OGUID := 9003369;

-- Gameobject templates
DELETE FROM `gameobject_template` WHERE `entry` IN (401727, 401728, 401729, 401730, 401731, 401732, 401733, 401734, 401735, 401736, 401737, 407048);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(401727, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401728, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401729, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401730, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401731, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401732, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401733, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26279, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401734, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401735, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401736, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(401737, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886), -- Candy Bucket
(407048, 2, 6404, 'Candy Bucket', '', '', '', 1, 0, 26617, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 425, 51886); -- Candy Bucket

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (401727, 401728, 401729, 401730, 401731, 401732, 401733, 401734, 401735, 401736, 401737, 407048);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(401727, 35, 4, 0, 0), -- Candy Bucket
(401728, 35, 4, 0, 0), -- Candy Bucket
(401729, 35, 4, 0, 0), -- Candy Bucket
(401730, 35, 4, 0, 0), -- Candy Bucket
(401731, 35, 4, 0, 0), -- Candy Bucket
(401732, 35, 4, 0, 0), -- Candy Bucket
(401733, 35, 4, 0, 0), -- Candy Bucket
(401734, 35, 4, 0, 0), -- Candy Bucket
(401735, 35, 4, 0, 0), -- Candy Bucket
(401736, 35, 4, 0, 0), -- Candy Bucket
(401737, 35, 4, 0, 0), -- Candy Bucket
(407048, 35, 4, 0, 0); -- Candy Bucket

-- Quests
DELETE FROM `quest_template` WHERE `ID`=75681;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(75681, 0, 0, 425, -21, 0, 0, 0, 3, 1, 0, 1, 48802, 0, 0, 0, 0, 1, 0, 2097152, 0, 0, 0, 0, 0, 0, 0, 0, 37586, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 6130900294268439629, 0, 9, 0, 0, 'Candy Bucket', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 51886); -- Candy Bucket

DELETE FROM `quest_offer_reward` WHERE `ID` IN (75672, 75673, 75674, 75675, 75676, 75677, 75678, 75679, 75681, 75682, 75683, 77698);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75672, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75673, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75674, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75675, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75676, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75677, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75678, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75679, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75681, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75682, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(75683, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886), -- Candy Bucket
(77698, 0, 0, 0, 0, 0, 0, 0, 0, 'Candy buckets like this are located in inns throughout the realms. Go ahead... take some!', 51886); -- Candy Bucket

DELETE FROM `gameobject_queststarter` WHERE `id` IN (401727, 401728, 401729, 401730, 401731, 401732, 401733, 401734, 401735, 401736, 401737, 407048);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(401727, 75672, 51886),
(401728, 75673, 51886),
(401729, 75674, 51886),
(401730, 75675, 51886),
(401731, 75676, 51886),
(401732, 75677, 51886),
(401733, 75678, 51886),
(401734, 75679, 51886),
(401735, 75681, 51886),
(401736, 75682, 51886),
(401737, 75683, 51886),
(407048, 77698, 51886);

DELETE FROM `gameobject_questender` WHERE `id` IN (401727, 401728, 401729, 401730, 401731, 401732, 401733, 401734, 401735, 401736, 401737, 407048);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(401727, 75672, 51886),
(401728, 75673, 51886),
(401729, 75674, 51886),
(401730, 75675, 51886),
(401731, 75676, 51886),
(401732, 75677, 51886),
(401733, 75678, 51886),
(401734, 75679, 51886),
(401735, 75681, 51886),
(401736, 75682, 51886),
(401737, 75683, 51886),
(407048, 77698, 51886);

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+83;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Uktulut Pier
(@OGUID+0, 180405, 2444, 13644, 0, '0', 0, 0, 3944.529541015625, 981.61114501953125, 4.167758464813232421, 3.149879217147827148, 0, 0, -0.99999141693115234, 0.004143203608691692, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+1, 180406, 2444, 13644, 0, '0', 0, 0, 3942.94970703125, 983.37847900390625, 4.329401493072509765, 2.286056995391845703, 0, 0, 0.909893989562988281, 0.41484081745147705, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+2, 180407, 2444, 13644, 0, '0', 0, 0, 3942.850830078125, 981.57293701171875, 5.010061264038085937, 2.587900876998901367, -0.04013681411743164, 0.020520210266113281, 0.96083831787109375, 0.273418545722961425, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+3, 180408, 2444, 13644, 0, '0', 0, 0, 3951.28466796875, 980.3507080078125, 9.141874313354492187, 2.393614768981933593, 0.071772098541259765, 0.105350494384765625, 0.924573898315429687, 0.359044790267944335, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+4, 180415, 2444, 13644, 0, '0', 0, 0, 3919.604248046875, 960.529541015625, -6.61895132064819335, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+5, 180523, 2444, 13644, 0, '0', 0, 0, 3931.69189453125, 947.857666015625, -7.33869075775146484, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+6, 401734, 2444, 13644, 0, '0', 0, 0, 3914.783935546875, 950.24481201171875, -7.34411525726318359, 2.183901786804199218, 0, 0, 0.8875274658203125, 0.460754811763763427, 120, 255, 1, 51886), -- Candy Bucket (Area: 0 - Difficulty: 0) CreateObject1
-- Uktulut Backwater
(@OGUID+7, 180405, 2444, 13644, 0, '0', 0, 0, 3324.759521484375, 354.555572509765625, 9.249363899230957031, 2.441283226013183593, 0, 0, 0.939319610595703125, 0.343043208122253417, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+8, 180406, 2444, 13644, 0, '0', 0, 0, 3327.013916015625, 363.098968505859375, 8.457171440124511718, 1.90435802936553955, 0, 0, 0.814681053161621093, 0.579909265041351318, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+9, 180407, 2444, 13644, 0, '0', 0, 0, 3324.540771484375, 347.795135498046875, 9.398869514465332031, 1.328583002090454101, -0.0203557014465332, 0.040220260620117187, 0.615569114685058593, 0.786792635917663574, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+10, 180408, 2444, 13644, 0, '0', 0, 0, 3327.116455078125, 363.192718505859375, 9.810383796691894531, 1.341095209121704101, 0, 0, 0.621415138244628906, 0.783481478691101074, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+11, 180415, 2444, 13644, 0, '0', 0, 0, 3321.962646484375, 349.2257080078125, 10.73756217956542968, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+12, 180523, 2444, 13644, 0, '0', 0, 0, 3292.221435546875, 350.5069580078125, -2.03460669517517089, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+13, 401733, 2444, 13644, 0, '0', 0, 0, 3295.4296875, 353.477447509765625, -2.01326799392700195, 2.564196109771728515, 0, 0, 0.958615303039550781, 0.284704595804214477, 120, 255, 1, 51886), -- Candy Bucket (Area: 0 - Difficulty: 0) CreateObject1
-- Wild Coast
(@OGUID+14, 180405, 2444, 13644, 13722, '0', 0, 0, 3887.28564453125, -1759.515625, 5.414926528930664062, 1.639002203941345214, 0, 0, 0.730805397033691406, 0.682585895061492919, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+15, 180405, 2444, 13644, 13722, '0', 0, 0, 3684.0869140625, -1828.623291015625, 3.784565448760986328, 0.461849927902221679, 0, 0, 0.228878021240234375, 0.97345513105392456, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+16, 180406, 2444, 13644, 13722, '0', 0, 0, 3681.62939453125, -1827.91845703125, 4.823746204376220703, 0.444270849227905273, 0, 0, 0.220313072204589843, 0.975429236888885498, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+17, 180406, 2444, 13644, 13722, '0', 0, 0, 3898.9541015625, -1757.7135009765625, 5.544133186340332031, 0.444270849227905273, 0, 0, 0.220313072204589843, 0.975429236888885498, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+18, 180407, 2444, 13644, 13722, '0', 0, 0, 3667.74560546875, -1827.16845703125, 2.848824501037597656, 0.884279727935791015, -0.01099348068237304, 0.043717384338378906, 0.427088737487792968, 0.90308535099029541, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+19, 180407, 2444, 13644, 13722, '0', 0, 0, 3883.030517578125, -1766.55908203125, 8.98474884033203125, 0.884279727935791015, -0.01099348068237304, 0.043717384338378906, 0.427088737487792968, 0.90308535099029541, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+20, 180408, 2444, 13644, 13722, '0', 0, 0, 3889.802978515625, -1754.2742919921875, 6.843943119049072265, 0.40852782130241394, 0.011672019958496093, -0.00507164001464843, 0.202904701232910156, 0.979115784168243408, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+21, 180408, 2444, 13644, 13722, '0', 0, 0, 3666.12060546875, -1835.640625, 7.92589569091796875, 1.267269015312194824, 0.046328544616699218, 0.044078826904296875, 0.590451240539550781, 0.804535925388336181, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+22, 180415, 2444, 13644, 13722, '0', 0, 0, 3894.311767578125, -1768.21875, 6.19517374038696289, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+23, 180415, 2444, 13644, 13722, '0', 0, 0, 3681.53564453125, -1829.1475830078125, 3.860137939453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+24, 180523, 2444, 13644, 13722, '0', 0, 0, 3894.98779296875, -1754.2066650390625, 5.414926528930664062, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+25, 180523, 2444, 13644, 13722, '0', 0, 0, 3669.748291015625, -1830.57470703125, 2.73941659927368164, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+26, 401735, 2444, 13644, 13722, '0', 0, 0, 3672.473876953125, -1833.3211669921875, 2.739415407180786132, 0.783978700637817382, 0, 0, 0.382027626037597656, 0.924150943756103515, 120, 255, 1, 51886), -- Candy Bucket (Area: Wild Coast - Difficulty: 0) CreateObject1
(@OGUID+27, 401736, 2444, 13644, 13722, '0', 0, 0, 3889.193603515625, -1762.2899169921875, 5.414926528930664062, 0.783978700637817382, 0, 0, 0.382027626037597656, 0.924150943756103515, 120, 255, 1, 51886), -- Candy Bucket (Area: Wild Coast - Difficulty: 0) CreateObject1
-- Wingrest Embassy
(@OGUID+28, 180405, 2444, 13644, 0, '0', 0, 0, 3493.872314453125, -1438.0711669921875, 93.24387359619140625, 2.842466592788696289, 0, 0, 0.988836288452148437, 0.149006009101867675, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+29, 180406, 2444, 13644, 0, '0', 0, 0, 3511.46435546875, -1423.970458984375, 92.27388763427734375, 1.91261446475982666, 0, 0, 0.817068099975585937, 0.57654118537902832, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+30, 180407, 2444, 13644, 0, '0', 0, 0, 3478.01220703125, -1452.1007080078125, 97.3326263427734375, 2.724912405014038085, -0.04144763946533203, 0.017724990844726562, 0.977300643920898437, 0.207005620002746582, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+31, 180408, 2444, 13644, 0, '0', 0, 0, 3493.96435546875, -1438.0555419921875, 94.7581634521484375, 2.624079227447509765, 0.014545440673828125, 0.010375022888183593, 0.966594696044921875, 0.255686342716217041, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+32, 180415, 2444, 13644, 0, '0', 0, 0, 3480.443603515625, -1445.5972900390625, 94.26609039306640625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+33, 180523, 2444, 13644, 0, '0', 0, 0, 3477.415771484375, -1422.59033203125, 93.36519622802734375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+34, 401737, 2444, 13644, 0, '0', 0, 0, 3488.768310546875, -1426.1492919921875, 93.24254608154296875, 0.783978700637817382, 0, 0, 0.382027626037597656, 0.924150943756103515, 120, 255, 1, 51886), -- Candy Bucket (Area: 0 - Difficulty: 0) CreateObject1
-- Skytop Observatory
(@OGUID+35, 180405, 2444, 13644, 13644, '0', 0, 0, 2478.197998046875, -1409.935791015625, 344.34246826171875, 3.595022916793823242, 0, 0, -0.97441005706787109, 0.224777817726135253, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+36, 180406, 2444, 13644, 13644, '0', 0, 0, 2465.651123046875, -1411.7742919921875, 346.885650634765625, 3.531701564788818359, 0, 0, -0.98103713989257812, 0.193819820880889892, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+37, 180407, 2444, 13644, 13644, '0', 0, 0, 2465.678955078125, -1394.579833984375, 343.3701171875, 2.766544342041015625, -0.04180765151977539, 0.016858100891113281, 0.981397628784179687, 0.186618804931640625, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+38, 180408, 2444, 13644, 13644, '0', 0, 0, 2462.557373046875, -1401.6129150390625, 346.5474853515625, 3.31568455696105957, 0, 0, -0.99621391296386718, 0.08693600445985794, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+39, 180415, 2444, 13644, 13644, '0', 0, 0, 2460.76904296875, -1408.75, 348.385894775390625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+40, 180523, 2444, 13644, 13644, '0', 0, 0, 2473.088623046875, -1402.782958984375, 342.413482666015625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+41, 401732, 2444, 13644, 13644, '0', 0, 0, 2459.65966796875, -1414.9444580078125, 346.799468994140625, 2.564196109771728515, 0, 0, 0.958615303039550781, 0.284704595804214477, 120, 255, 1, 51886), -- Candy Bucket (Area: The Waking Shores - Difficulty: 0) CreateObject1
-- Life Vault Ruins
(@OGUID+42, 180405, 2444, 13644, 13644, '0', 0, 0, 2278.80029296875, -580.0555419921875, 61.32625961303710937, 1.764891743659973144, 0, 0, 0.772294998168945312, 0.635264098644256591, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+43, 180406, 2444, 13644, 13644, '0', 0, 0, 2268.4462890625, -548.779541015625, 63.82267379760742187, 0.756749153137207031, 0, 0, 0.369410514831542968, 0.929266333580017089, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+44, 180407, 2444, 13644, 13644, '0', 0, 0, 2303.927001953125, -535.97222900390625, 62.07574462890625, 0.104238264262676239, 0.012121200561523437, 0.203436851501464843, 0.046311378479003906, 0.977917075157165527, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+45, 180408, 2444, 13644, 13644, '0', 0, 0, 2268.395751953125, -548.85589599609375, 65.32402801513671875, 0.442517042160034179, 0, 0, 0.219457626342773437, 0.975622057914733886, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+46, 180415, 2444, 13644, 13644, '0', 0, 0, 2282.635498046875, -542.64581298828125, 62.68033981323242187, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+47, 180523, 2444, 13644, 13644, '0', 0, 0, 2278.986083984375, -542.75177001953125, 61.02885818481445312, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+48, 401730, 2444, 13644, 13644, '0', 0, 0, 2290.717041015625, -549.08160400390625, 61.01553726196289062, 5.636782169342041015, 0, 0, -0.31760406494140625, 0.948223412036895751, 120, 255, 1, 51886), -- Candy Bucket (Area: The Waking Shores - Difficulty: 0) CreateObject1
-- Obsidian Throne
(@OGUID+49, 180405, 2444, 13644, 13941, '0', 0, 0, 2435.04345703125, 2600.359375, 391.26165771484375, 0.824431538581848144, 0, 0, 0.400640487670898437, 0.916235327720642089, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+50, 180406, 2444, 13644, 13941, '0', 0, 0, 2429.939208984375, 2596.192626953125, 391.32049560546875, 1.201533675193786621, 0, 0, 0.565275192260742187, 0.82490241527557373, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+51, 180407, 2444, 13644, 13941, '0', 0, 0, 2421.1494140625, 2598.032958984375, 384.8995361328125, 6.207526683807373046, 0.010435104370117187, 0.043853759765625, -0.03816986083984375, 0.998254001140594482, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+52, 180408, 2444, 13644, 13941, '0', 0, 0, 2429.798583984375, 2601.846435546875, 396.477325439453125, 0.442517042160034179, 0, 0, 0.219457626342773437, 0.975622057914733886, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+53, 180415, 2444, 13644, 13941, '0', 0, 0, 2428.640625, 2600.208251953125, 385.079498291015625, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+54, 180523, 2444, 13644, 13941, '0', 0, 0, 2427.757080078125, 2593.90283203125, 383.662872314453125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Obsidian Throne - Difficulty: 0) CreateObject1
(@OGUID+55, 401731, 2444, 13644, 13941, '0', 0, 0, 2436.921875, 2599.763916015625, 383.662872314453125, 0.329071789979934692, 0, 0, 0.163794517517089843, 0.986494481563568115, 120, 255, 1, 51886), -- Candy Bucket (Area: Obsidian Throne - Difficulty: 0) CreateObject1
-- Obsidian Bulwark
(@OGUID+56, 180405, 2444, 13644, 13644, '0', 0, 0, 1837.171875, 1240.43408203125, 187.9788665771484375, 3.80979776382446289, 0, 0, -0.94470500946044921, 0.327921390533447265, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+57, 180406, 2444, 13644, 13644, '0', 0, 0, 1816.5711669921875, 1234.6458740234375, 187.919708251953125, 3.440949440002441406, 0, 0, -0.98881912231445312, 0.149119973182678222, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+58, 180407, 2444, 13644, 13644, '0', 0, 0, 1838.8819580078125, 1241.7135009765625, 187.9853363037109375, 4.352739334106445312, 0, 0, -0.82217597961425781, 0.569233357906341552, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+59, 180408, 2444, 13644, 13644, '0', 0, 0, 1832.2691650390625, 1240.076416015625, 200.4716033935546875, 3.241843223571777343, 0, 0, -0.99874401092529296, 0.050104174762964248, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+60, 180415, 2444, 13644, 13644, '0', 0, 0, 1828.1632080078125, 1215.3385009765625, 192.0497894287109375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+61, 180523, 2444, 13644, 13644, '0', 0, 0, 1830.9791259765625, 1211.7396240234375, 190.861419677734375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: The Waking Shores - Difficulty: 0) CreateObject1
(@OGUID+62, 407048, 2444, 13644, 13644, '0', 0, 0, 1825.907958984375, 1216.0347900390625, 190.861419677734375, 2.556131362915039062, 0, 0, 0.957459449768066406, 0.288567811250686645, 120, 255, 1, 51886), -- Candy Bucket (Area: The Waking Shores - Difficulty: 0) CreateObject1
-- Ruby Lifeshrine
(@OGUID+63, 180405, 2444, 13644, 13728, '0', 0, 0, 1773.498291015625, 27.40625, 128.5318145751953125, 0.090937480330467224, 0, 0, 0.045453071594238281, 0.998966515064239501, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+64, 180406, 2444, 13644, 13728, '0', 0, 0, 1805.9566650390625, 40.83159637451171875, 128.0596923828125, 3.440949440002441406, 0, 0, -0.98881912231445312, 0.149119973182678222, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+65, 180407, 2444, 13644, 13728, '0', 0, 0, 1796.49658203125, 49.30902862548828125, 128.0612030029296875, 2.570615291595458984, 0, 0, 0.959524154663085937, 0.281626343727111816, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+66, 180408, 2444, 13644, 13728, '0', 0, 0, 1856.9635009765625, 88.13021087646484375, 100.8248977661132812, 3.241843223571777343, 0, 0, -0.99874401092529296, 0.050104174762964248, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+67, 180415, 2444, 13644, 13728, '0', 0, 0, 1811.6441650390625, 46.57291793823242187, 128.0375823974609375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+68, 180523, 2444, 13644, 13728, '0', 0, 0, 1782.689208984375, 32.95659637451171875, 127.9871368408203125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
(@OGUID+69, 401729, 2444, 13644, 13728, '0', 0, 0, 1791.670166015625, 24.63888931274414062, 127.9871368408203125, 2.733020544052124023, 0, 0, 0.979206085205078125, 0.202868074178695678, 120, 255, 1, 51886), -- Candy Bucket (Area: Ruby Life Pools - Difficulty: 0) CreateObject1
-- Apex Observatory
(@OGUID+70, 180405, 2444, 13644, 13734, '0', 0, 0, 989.43927001953125, 2710.264892578125, 204.5272064208984375, 5.432066917419433593, 0, 0, -0.41283035278320312, 0.910807967185974121, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+71, 180406, 2444, 13644, 13734, '0', 0, 0, 989.5086669921875, 2694.106689453125, 210.6147003173828125, 5.259614467620849609, 0.119386672973632812, -0.10126209259033203, -0.4796457290649414, 0.863384485244750976, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+72, 180407, 2444, 13644, 13734, '0', 0, 0, 987.54168701171875, 2698.71875, 201.8315277099609375, 4.950593948364257812, 0, 0, -0.61807823181152343, 0.786116600036621093, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+73, 180408, 2444, 13644, 13734, '0', 0, 0, 1005.048583984375, 2717.462646484375, 204.9883575439453125, 5.884125232696533203, 0, 0, -0.19820880889892578, 0.98015981912612915, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+74, 180415, 2444, 13644, 13734, '0', 0, 0, 1006.890625, 2702.809814453125, 203.259124755859375, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+75, 180523, 2444, 13644, 13734, '0', 0, 0, 1005.151123046875, 2701.075439453125, 201.6615753173828125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Apex Canopy - Difficulty: 0) CreateObject1
(@OGUID+76, 401727, 2444, 13644, 13734, '0', 0, 0, 1004.61798095703125, 2704.291748046875, 201.6610107421875, 5.191855430603027343, 0, 0, -0.51898670196533203, 0.854782342910766601, 120, 255, 1, 51886), -- Candy Bucket (Area: Apex Canopy - Difficulty: 0) CreateObject1
-- Dragonscale Basecamp
(@OGUID+77, 180405, 2444, 13644, 13733, '0', 0, 0, 929.3819580078125, 855.76739501953125, 134.1906585693359375, 1.479012727737426757, 0.015749454498291015, 0.02207183837890625, 0.673563957214355468, 0.738631367683410644, 120, 255, 1, 51886), -- G_Pumpkin_01 (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+78, 180406, 2444, 13644, 13733, '0', 0, 0, 958.88543701171875, 883.50347900390625, 127.5243606567382812, 5.658230781555175781, 0, 0, -0.30741691589355468, 0.951574921607971191, 120, 255, 1, 51886), -- G_Pumpkin_02 (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+79, 180407, 2444, 13644, 13733, '0', 0, 0, 961.859375, 881.16668701171875, 127.5567626953125, 6.22019052505493164, 0, 0, -0.03149223327636718, 0.999503970146179199, 120, 255, 1, 51886), -- G_Pumpkin_03 (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+80, 180408, 2444, 13644, 13733, '0', 0, 0, 960.37152099609375, 882.9132080078125, 132.79449462890625, 0.026829570531845092, 0, 0, 0.013414382934570312, 0.99990999698638916, 120, 255, 1, 51886), -- G_WitchHat_01 (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+81, 180415, 2444, 13644, 13733, '0', 0, 0, 970.9913330078125, 874.00518798828125, 127.8414535522460937, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- CandleBlack01 (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+82, 180523, 2444, 13644, 13733, '0', 0, 0, 940.22918701171875, 841.44097900390625, 130.0926055908203125, 0, 0, 0, 0, 1, 120, 255, 1, 51886), -- Apple Bob (Area: Wild Preserve - Difficulty: 0) CreateObject1
(@OGUID+83, 401728, 2444, 13644, 13733, '0', 0, 0, 940.50518798828125, 851.11114501953125, 130.4185943603515625, 1.088459610939025878, 0, 0, 0.517759323120117187, 0.855526328086853027, 120, 255, 1, 51886); -- Candy Bucket (Area: Wild Preserve - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+83;
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
(12, @OGUID+49),
(12, @OGUID+50),
(12, @OGUID+51),
(12, @OGUID+52),
(12, @OGUID+53),
(12, @OGUID+54),
(12, @OGUID+55),
(12, @OGUID+56),
(12, @OGUID+57),
(12, @OGUID+58),
(12, @OGUID+59),
(12, @OGUID+60),
(12, @OGUID+61),
(12, @OGUID+62),
(12, @OGUID+63),
(12, @OGUID+64),
(12, @OGUID+65),
(12, @OGUID+66),
(12, @OGUID+67),
(12, @OGUID+68),
(12, @OGUID+69),
(12, @OGUID+70),
(12, @OGUID+71),
(12, @OGUID+72),
(12, @OGUID+73),
(12, @OGUID+74),
(12, @OGUID+75),
(12, @OGUID+76),
(12, @OGUID+77),
(12, @OGUID+78),
(12, @OGUID+79),
(12, @OGUID+80),
(12, @OGUID+81),
(12, @OGUID+82),
(12, @OGUID+83);
