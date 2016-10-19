DELETE FROM `quest_template` WHERE `ID` IN (30313 /*-Unknown-*/, 30291 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(30313, 2, 90, 0, 90, 5840, 0, 0, 0, 5, 1, 114000, 5, 1, 4900, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4104, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1269, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 7, 7, 7, 7, 7, 5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'The Moving Mists', 'Kill 8 Fog Walkers.', '<He looks down at the dead fog creature at his feet, looks up at you, then points out into the mists surrounding the lake. It seems he wants you to find and kill more of these fog creatures.>', '', '', 738, 0, 0, 0, 2, 0, 0, 0, '', '', '', '', 890, 878, 22498), -- -Unknown-
(30291, 2, 90, 0, 90, 5840, 0, 0, 0, 5, 1, 114000, 5, 1, 4900, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4104, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1269, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 7, 7, 7, 7, 7, 5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'Stunning Display', 'Collect 12 Stunned Whitepetal Carp.', 'I''ve been talking to Tantan here... again... and he insists that fishing is some kind of fabulous. I was skeptical, but I gave it another go. I''m not a big fan of that whole holding a stick and waiting method though, so I tried something a bit more direct.$B$BWould you be a doll and go collect any of the still intact fish floating belly up in the lake for me?', '', '', 738, 0, 0, 0, 2, 0, 0, 0, '', '', '', '', 890, 878, 22498); -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (268126 /*268126*/, 268109 /*268109*/, 264117 /*264117*/, 254453 /*254453*/, 254452 /*254452*/, 254451 /*254451*/, 254450 /*254450*/, 260116 /*260116*/, 259725 /*259725*/, 255328 /*255328*/, 260664 /*260664*/, 260663 /*260663*/, 260662 /*260662*/, 260738 /*260738*/, 260737 /*260737*/, 260736 /*260736*/, 254816 /*254816*/, 259212 /*259212*/, 259000 /*259000*/, 259341 /*259341*/, 258465 /*258465*/, 255017 /*255017*/, 259457 /*259457*/, 258571 /*258571*/, 256585 /*256585*/, 256584 /*256584*/, 256583 /*256583*/, 256606 /*256606*/, 256605 /*256605*/, 256604 /*256604*/, 256444 /*256444*/, 256443 /*256443*/, 256442 /*256442*/, 256726 /*256726*/, 256725 /*256725*/, 252322 /*252322*/, 252321 /*252321*/, 256214 /*256214*/, 256213 /*256213*/, 256083 /*256083*/, 256082 /*256082*/, 256252 /*256252*/, 256251 /*256251*/, 256196 /*256196*/, 256195 /*256195*/, 253238 /*253238*/, 253237 /*253237*/, 256277 /*256277*/, 255074 /*255074*/, 255916 /*255916*/, 252371 /*252371*/, 252370 /*252370*/, 252369 /*252369*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(268126, 30313, 0, 0, 58672, 8, 0, 0, '', 22498), -- 268126
(268109, 30291, 1, 0, 84656, 12, 0, 0, '', 22498), -- 268109
(264117, 13915, 0, 0, 34327, 15, 0, 0, 'Fresh Dinosaur Meat fed to Venomhide Hatchling', 22498), -- 264117
(254453, 9736, 1, 3, 18335, 1, 0, 0, '', 22498), -- 254453
(254452, 9736, 1, 2, 12800, 1, 0, 0, '', 22498), -- 254452
(254451, 9736, 1, 1, 24285, 1, 0, 0, '', 22498), -- 254451
(254450, 9736, 1, 0, 24286, 1, 0, 0, '', 22498), -- 254450
(260116, 9586, 0, 0, 17551, 1, 0, 0, 'Heal Tavara', 22498), -- 260116
(259725, 9504, 1, 0, 23750, 1, 0, 0, '', 22498), -- 259725
(255328, 8949, 1, 0, 21982, 25, 0, 0, '', 22498), -- 255328
(260664, 8912, 8, -1, 0, 200000, 0, 0, '', 22498), -- 260664
(260663, 8912, 1, 1, 16735, 1, 0, 0, '', 22498), -- 260663
(260662, 8912, 1, 0, 21928, 15, 0, 0, '', 22498), -- 260662
(260738, 8907, 8, -1, 0, 200000, 0, 0, '', 22498), -- 260738
(260737, 8907, 1, 1, 16683, 1, 0, 0, '', 22498), -- 260737
(260736, 8907, 1, 0, 21928, 15, 0, 0, '', 22498), -- 260736
(254816, 8730, 1, 0, 21138, 1, 0, 0, '', 22498), -- 254816
(259212, 8154, 4, -1, 392, 297, 0, 0, '', 22498), -- 259212
(259000, 7872, 4, -1, 392, 297, 0, 0, '', 22498), -- 259000
(259341, 7738, 1, 0, 18972, 1, 0, 0, '', 22498), -- 259341
(258465, 7504, 1, 0, 18362, 1, 0, 0, '', 22498), -- 258465
(255017, 7463, 1, 0, 18299, 1, 0, 0, '', 22498), -- 255017
(259457, 7401, 1, 0, 18206, 1, 0, 0, '', 22498), -- 259457
(258571, 6146, 1, 0, 13852, 1, 0, 0, '', 22498), -- 258571
(256585, 2852, 1, 2, 8153, 2, 0, 0, '', 22498), -- 256585
(256584, 2852, 1, 1, 8198, 2, 0, 0, '', 22498), -- 256584
(256583, 2852, 1, 0, 8191, 2, 0, 0, '', 22498), -- 256583
(256606, 2850, 1, 2, 8153, 1, 0, 0, '', 22498), -- 256606
(256605, 2850, 1, 1, 8176, 2, 0, 0, '', 22498), -- 256605
(256604, 2850, 1, 0, 8175, 2, 0, 0, '', 22498), -- 256604
(256444, 2849, 1, 2, 8153, 1, 0, 0, '', 22498), -- 256444
(256443, 2849, 1, 1, 8187, 2, 0, 0, '', 22498), -- 256443
(256442, 2849, 1, 0, 8189, 2, 0, 0, '', 22498), -- 256442
(256726, 2848, 1, 1, 8153, 1, 0, 0, '', 22498), -- 256726
(256725, 2848, 1, 0, 8173, 6, 0, 0, '', 22498), -- 256725
(252322, 2773, 1, 1, 7927, 1, 0, 0, '', 22498), -- 252322
(252321, 2773, 1, 0, 7930, 2, 0, 0, '', 22498), -- 252321
(256214, 2772, 1, 1, 7926, 1, 0, 0, '', 22498), -- 256214
(256213, 2772, 1, 0, 7933, 2, 0, 0, '', 22498), -- 256213
(256083, 2771, 1, 1, 7928, 1, 0, 0, '', 22498), -- 256083
(256082, 2771, 1, 0, 7931, 2, 0, 0, '', 22498), -- 256082
(256252, 2763, 1, 1, 3864, 4, 0, 0, '', 22498), -- 256252
(256251, 2763, 1, 0, 3860, 40, 0, 0, '', 22498), -- 256251
(256196, 2762, 1, 1, 6037, 5, 0, 0, '', 22498), -- 256196
(256195, 2762, 1, 0, 3860, 40, 0, 0, '', 22498), -- 256195
(253238, 2602, 1, 1, 8396, 2, 0, 0, '', 22498), -- 253238
(253237, 2602, 1, 0, 8394, 10, 0, 0, '', 22498), -- 253237
(256277, 1957, 0, 0, 6550, 12, 0, 0, '', 22498), -- 256277
(255074, 1858, 1, 0, 7295, 1, 0, 0, '', 22498), -- 255074
(255916, 1710, 1, 0, 6849, 20, 0, 0, '', 22498), -- 255916
(252371, 49, 1, 2, 740, 1, 0, 0, '', 22498), -- 252371
(252370, 49, 1, 1, 739, 1, 0, 0, '', 22498), -- 252370
(252369, 49, 1, 0, 738, 1, 0, 0, '', 22498); -- 252369

DELETE FROM `quest_visual_effect` WHERE (`ID`=268109 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(268109, 0, 925, 22498); -- 268109
