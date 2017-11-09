DELETE FROM `quest_template` WHERE `ID` IN (46134 /*-Unknown-*/, 43937 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(46134, 3, 110, 0, 110, 7502, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 590144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 328, 'Gemcutter Needed', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23420), -- -Unknown-
(43937, 2, -1, 0, 110, -406, 107, 0, 0, 1, 1, 19400, 1, 1, 0, 0, 0, 0, 81040, 0, 0, 0, 0, 1, 0, 39846144, 37748992, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'Seeking Refuge', 'Complete the "Nightfall" storyline in Suramar, then meet Archmage Kalec in Shal''Aran.', 'The Nightfallen in Suramar were once a part of the Nightborne, but have been exiled by their former brethren and cut off from the Nightwell.$B$BI believe they could be valuable allies in our quest if you can turn them to our side. I know only that they have gone into hiding somewhere in Suramar.$B$BIf you can convince the Nightfallen to aid us, they may be able to offer the Moon Guard and us both refuge right under the Legion''s nose.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23420); -- -Unknown-

UPDATE `quest_template` SET `Flags`=34603072, `VerifiedBuild`=23420 WHERE `ID`=45353; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=5600, `VerifiedBuild`=23420 WHERE `ID`=36206; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `RewardFactionValue1`=5, `RewardFactionOverride1`=40000, `VerifiedBuild`=23420 WHERE `ID`=32607; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=15000, `VerifiedBuild`=23420 WHERE `ID`=32139; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=6, `RewardFactionOverride1`=0, `VerifiedBuild`=23420 WHERE `ID`=24875; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=6, `RewardFactionOverride1`=0, `VerifiedBuild`=23420 WHERE `ID`=24869; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=11139; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=30, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `VerifiedBuild`=23420 WHERE `ID`=10899; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `VerifiedBuild`=23420 WHERE `ID`=9464; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=9059; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=8578; -- -Unknown-
UPDATE `quest_template` SET `QuestPackageID`=16520, `RewardMoney`=48500, `RewardChoiceItemID1`=0, `RewardChoiceItemQuantity1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=8226; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=8043; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=8042; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=18350, `RewardFactionValue1`=1, `RewardFactionOverride1`=0, `VerifiedBuild`=23420 WHERE `ID`=7670; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23420 WHERE `ID`=7622; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=7402; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=6602; -- -Unknown-
UPDATE `quest_template` SET `QuestInfoID`=21, `RewardBonusMoney`=45700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=4, `QuestDescription`='$n, your High Priest Rohan would have an audience with you in Ironforge. Make haste, my strong friend, your next test quickly approaches. Although I wish I could bear witness to your race''s own special rites, my place is here. But may the Light go with you in your travels. Rohan should still be in the Mystic Ward once you reach the city. He will be waiting.', `VerifiedBuild`=23420 WHERE `ID`=5645; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=45700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23420 WHERE `ID`=5630; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=4005; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=3125; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=2582; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=1374; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23420 WHERE `ID`=921; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=13000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23420 WHERE `ID`=864; -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (288973 /*288973*/, 286004 /*286004*/, 260564 /*260564*/, 260563 /*260563*/, 260562 /*260562*/, 260561 /*260561*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(288973, 46134, 0, 0, 118825, 1, 0, 0, 0, 'Cut an orange gem', 23420), -- 288973
(286004, 43937, 14, 0, 51242, 1, 0, 0, 0, 'Save First Arcanist Thalryssa in Suramar', 23420), -- 286004
(260564, 9059, 1, 3, 15407, 5, 0, 0, 0, '', 23420), -- 260564
(260563, 9059, 1, 2, 12360, 1, 0, 0, 0, '', 23420), -- 260563
(260562, 9059, 1, 1, 22374, 8, 0, 0, 0, '', 23420), -- 260562
(260561, 9059, 1, 0, 22364, 1, 0, 0, 0, '', 23420); -- 260561

UPDATE `quest_objectives` SET `Type`=14, `ObjectID`=58651, `VerifiedBuild`=23420 WHERE `ID`=285956; -- 285956
UPDATE `quest_objectives` SET `Type`=14, `ObjectID`=57390, `VerifiedBuild`=23420 WHERE `ID`=285578; -- 285578
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=270251; -- 270251
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255841; -- 255841
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255840; -- 255840
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=258755; -- 258755
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=259800; -- 259800
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=260081; -- 260081
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=260080; -- 260080
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=260079; -- 260079
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256961; -- 256961
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=257608; -- 257608
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256550; -- 256550
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256549; -- 256549
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256422; -- 256422
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=257213; -- 257213
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256338; -- 256338
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256571; -- 256571
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255952; -- 255952
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255587; -- 255587
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255410; -- 255410
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=256473; -- 256473
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=254457; -- 254457
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=254481; -- 254481
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23420 WHERE `ID`=255338; -- 255338

DELETE FROM `quest_visual_effect` WHERE (`ID`=288973 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(288973, 0, 4978, 23420);
