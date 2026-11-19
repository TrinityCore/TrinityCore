DELETE FROM quest_template WHERE `ID` IN (43471 /*-Unknown-*/, 43323 /*-Unknown-*/);
INSERT INTO quest_template (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(43471, 2, -1, 0, 1, -22, 0, 0, 0, 5, 1, 35, 5, 1, 146300, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18875469, 0, 'The Historians', 'Meet with Historian Llore in the Royal Library of Stormwind.', '$n, each year I visit Stormwind to help adventurers like you reflect on our shared history. While our eyes must always be trained on the future, we must be mindful of our past. Come visit me in the Stormwind Royal Library and we can speak more.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 22522), -- -Unknown-
(43323, 2, -1, 0, 1, 6757, 0, 0, 0, 8, 1, 125, 8, 1, 292550, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18875469, 0, 'A Time to Reflect', 'Correctly answer one of Llore''s questions about the history of Azeroth.', 'It is time to reflect on the events that have brought us to this moment. A celebration of our great history and the events that shape it.', '', '', 1166, 0, 0, 0, 25, 0, 0, 0, '', '', '', '', 890, 878, 22522); -- -Unknown-
UPDATE quest_template SET `RewardXPDifficulty`=2, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=37995; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=37260; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=37259; -- 0
UPDATE quest_template SET `RewardMoney`=228000, `RewardBonusMoney`=2050, `RewardFactionValue1`=20000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=32577; -- 0
UPDATE quest_template SET `RewardBonusMoney`=2050, `RewardFactionValue1`=20000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=32563; -- 0
UPDATE quest_template SET `RewardBonusMoney`=2050, `RewardFactionValue1`=20000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=32562; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32510; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32360; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32052; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32049; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32042; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=32033; -- 0
UPDATE quest_template SET `RewardBonusMoney`=1650, `RewardFactionValue1`=10000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=31760; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=31168; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=2637824, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=31147; -- 0
UPDATE quest_template SET `RewardMoney`=114000, `RewardBonusMoney`=1650, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30902; -- 0
UPDATE quest_template SET `RewardMoney`=114000, `RewardBonusMoney`=1650, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30885; -- 0
UPDATE quest_template SET `RewardMoney`=114000, `RewardBonusMoney`=1650, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30880; -- 0
UPDATE quest_template SET `RewardBonusMoney`=1650, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30645; -- 0
UPDATE quest_template SET `RewardBonusMoney`=825, `Flags`=1048584, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=30644; -- 0
UPDATE quest_template SET `RewardBonusMoney`=1650, `RewardFactionValue1`=10000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30310; -- 0
UPDATE quest_template SET `RewardBonusMoney`=1650, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30063; -- 0
UPDATE quest_template SET `Flags`=524288, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=30041; -- 0
UPDATE quest_template SET `RewardBonusMoney`=500, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=29229; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29020; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29013; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29012; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29011; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29010; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29008; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29007; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=29006; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28997; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28995; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28991; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28990; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28988; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28985; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28983; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28980; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28979; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28978; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28977; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28970; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28968; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28964; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28963; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28961; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28960; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28956; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28954; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28952; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28951; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28950; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28945; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28932; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28929; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28928; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28926; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28925; -- 0
UPDATE quest_template SET `RewardMoney`=17, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=28922; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=28308; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `RewardSpell`=0, `Flags`=2637824, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=26947; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=26915; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=2637824, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=24965; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=24752; -- 0
UPDATE quest_template SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=24494; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=13649; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13492; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13491; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13490; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13489; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13488; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13487; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13486; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13485; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13473; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13448; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13439; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13438; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13437; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13436; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13435; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13434; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13433; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13383; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12945; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12944; -- 0
UPDATE quest_template SET `QuestPackageID`=17143, `RewardChoiceItemID1`=0, `RewardChoiceItemID2`=0, `RewardChoiceItemID3`=0, `RewardChoiceItemQuantity1`=0, `RewardChoiceItemQuantity2`=0, `RewardChoiceItemQuantity3`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=12781; -- 0
UPDATE quest_template SET `RewardMoney`=2, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12753; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12360; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12359; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12358; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12357; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12356; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12355; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12354; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12353; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12352; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12351; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12350; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12349; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12348; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12347; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12345; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12344; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12343; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12342; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12341; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12340; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12339; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12338; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12337; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12336; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12335; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12334; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12333; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12332; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12331; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=12286; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11834; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11833; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11832; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11831; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11830; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11829; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11828; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11827; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11826; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11825; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11824; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11823; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11822; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11821; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11820; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11819; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11818; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11817; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11816; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11815; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11814; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11813; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11812; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11811; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11810; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11809; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11808; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11807; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11806; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11805; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11804; -- 0
UPDATE quest_template SET `RewardMoney`=8, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11583; -- 0
UPDATE quest_template SET `QuestPackageID`=16886, `RewardMoney`=2, `RewardChoiceItemID1`=0, `RewardChoiceItemID2`=0, `RewardChoiceItemID3`=0, `RewardChoiceItemQuantity1`=0, `RewardChoiceItemQuantity2`=0, `RewardChoiceItemQuantity3`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11442; -- 0
UPDATE quest_template SET `RewardMoney`=3500, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=11192; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=11177; -- 0
UPDATE quest_template SET `RewardMoney`=4000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=11147; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=11145; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=11134; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=10955; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=10794; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=10548; -- 0
UPDATE quest_template SET `RewardBonusMoney`=182850, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9735; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9665; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=9464; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=9429; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9052; -- 0
UPDATE quest_template SET `QuestPackageID`=16541, `RewardChoiceItemID1`=0, `RewardChoiceItemID2`=0, `RewardChoiceItemID3`=0, `RewardChoiceItemQuantity1`=0, `RewardChoiceItemQuantity2`=0, `RewardChoiceItemQuantity3`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8993; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=33555378, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8915; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=8767; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8761; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8344; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8332; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=8322; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=8233; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8231; -- 0
UPDATE quest_template SET `RewardMoney`=25000, `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionValue3`=0, `RewardFactionValue4`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `RewardFactionOverride2`=7, `RewardFactionOverride3`=7, `RewardFactionOverride4`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7873; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7850; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7846; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7830; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7829; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7635; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7634; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7485; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7484; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7483; -- 0
UPDATE quest_template SET `RewardMoney`=18000, `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `RewardFactionOverride2`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7363; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7201; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `RewardFactionOverride2`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7166; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `RewardFactionOverride2`=1, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6846; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6584; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6583; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6582; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=6401; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `VerifiedBuild`=22522 WHERE `ID`=6285; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=6281; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=6141; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6135; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6025; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=6004; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=5944; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=5928; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=5922; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=5862; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=5803; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=5727; -- 0
UPDATE quest_template SET `QuestInfoID`=21, `RewardBonusMoney`=36600, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='You''ve caught the attention of our superiors, $n. They''ve asked you travel to the Cathedral of Light in Stormwind as soon as possible. Apparently they feel you''ve proven yourself already and are prepared to further your training. When you get there, find High Priestess Laurena. She will be able to guide you further. Good luck, and may the Light be with you.', `VerifiedBuild`=22522 WHERE `ID`=5635; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=5481; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `RewardFactionOverride2`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=5225; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=5167; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=5084; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=5048; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=4987; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=4969; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=4904; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=4783; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=4737; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `VerifiedBuild`=22522 WHERE `ID`=4341; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=4023; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=3901; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=3801; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=3701; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=3641; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='They call themselves the Undermarket: Cutthroat traders that will sell, move, trade and do just about anything for the right price.$B$BIt gets worse, $n. They have set up a base of operations here in the Searing Gorge. Trade Master Kovic is heading up the operation and has close ties with the Dark Iron dwarves of the region.$B$BWe must strike hard and send a message to their leadership. Slay Trade Master Kovic and his minion Clunk. Bring back his trader''s satchel when the job is done.$B$BTo the Cauldron!', `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=3385; -- 0
UPDATE quest_template SET `RewardMoney`=4500, `RewardMoneyDifficulty`=5, `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `AllowableRaces`=-1, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=3124; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=2990; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2974; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=2943; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `VerifiedBuild`=22522 WHERE `ID`=2936; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2870; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2603; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2601; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2585; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2583; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2581; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2339; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18875469, `QuestDescription`='We believe there is one being that may be able to help us understand what is happening to the forests of Teldrassil. Unfortunately, getting the creature to cooperate has proven disastrous.$B$BHe hides on a branch at the outskirts of the Oracle Glade. All who have so far approached the satyr, whether through force or diplomacy, have met with doom. Perhaps stealth is the answer, $n.$B$BFind what Sethir the Ancient carries in his packs and report back to me.\n', `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2242; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `RewardFactionOverride2`=2, `VerifiedBuild`=22522 WHERE `ID`=2160; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1961; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1938; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=1823; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=1805; -- 0
UPDATE quest_template SET `RewardBonusMoney`=109700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='We was spyin'' on some of the Dark Iron dwarves that''ve bunkered down south of Helm''s Bed Lake. We knew they was up to no good, so Narm an'' me thought we''d take a closer look--got ta see their leader given orders to some o'' his men.$B$BNarm an'' me took the chance to kill a few of ''em, but they proved tougher than we thought, an'' more of ''em got the jump on us. Narm tol'' me to run an'' get support, so ''ere I am.$B$BNarm needs help, an'' I''ll not rest till he gets it.$B$BC''n ya help, $n?', `VerifiedBuild`=22522 WHERE `ID`=1783; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1689; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1681; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1516; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=1359; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=1358; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `AllowableRaces`=-1, `QuestDescription`='Well done, $n. You have passed the first portion of the Test of Lore, but there is still another question to be answered. But that question is not mine to ask.$B$BSeek out Parqual Fintallas in Lordaeron City. He was a great historian for the humans before the Plague overtook him. Now he continues to seek enlightenment, but of a different nature.$B$BHe will have another requirement of you before he asks you anything, but you have done masterfully thus far--I''m sure you will overcome his obstacle.', `VerifiedBuild`=22522 WHERE `ID`=1159; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=1152; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=1064; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=1059; -- 0
UPDATE quest_template SET `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=1030; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1027; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1012; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=900; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=885; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=1, `VerifiedBuild`=22522 WHERE `ID`=860; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `RewardFactionOverride2`=5, `VerifiedBuild`=22522 WHERE `ID`=830; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=704; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=536; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=493; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=428; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=376; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=361; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=285; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=284; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionValue2`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `RewardFactionOverride2`=6, `VerifiedBuild`=22522 WHERE `ID`=162; -- 0
UPDATE quest_template SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=96; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=66; -- 0
UPDATE quest_template SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=33; -- 0

DELETE FROM quest_objectives WHERE `ID` IN (285163 /*285163*/, 262479 /*262479*/, 261020 /*261020*/, 261019 /*261019*/, 261018 /*261018*/, 252816 /*252816*/, 252815 /*252815*/, 252814 /*252814*/, 256476 /*256476*/, 256475 /*256475*/, 256293 /*256293*/);
INSERT INTO quest_objectives (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(285163, 43323, 0, 0, 109989, 1, 0, 0, 'Answered Llore''s question', 22522), -- 285163
(262479, 9735, 1, 0, 24284, 1, 0, 0, '', 22522), -- 262479
(261020, 8915, 8, -1, 0, 200000, 0, 0, '', 22522), -- 261020
(261019, 8915, 1, 1, 16683, 1, 0, 0, '', 22522), -- 261019
(261018, 8915, 1, 0, 22381, 15, 0, 0, '', 22522), -- 261018
(252816, 3385, 1, 2, 10467, 1, 0, 0, '', 22522), -- 252816
(252815, 3385, 0, 1, 8447, 1, 0, 0, '', 22522), -- 252815
(252814, 3385, 0, 0, 8444, 1, 0, 0, '', 22522), -- 252814
(256476, 3124, 1, 1, 9619, 1, 0, 0, '', 22522), -- 256476
(256475, 3124, 1, 0, 9595, 10, 0, 0, '', 22522), -- 256475
(256293, 2242, 1, 0, 7737, 1, 0, 0, '', 22522); -- 256293
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=277283; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=277282; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=276031; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=276030; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=270085; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=270146; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=270080; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=269041; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=268199; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=268174; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=268173; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255057; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254635; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=252734; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253864; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=263772; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=251804; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=260821; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=266534; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=266533; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=266222; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=266221; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256114; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256113; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255305; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255304; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=267636; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257074; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=262592; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259068; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253071; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254102; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=252954; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=273866; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=262099; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=261540; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=261539; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=261538; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=261537; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259243; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259242; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259793; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=261303; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257768; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257767; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256210; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256209; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255930; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257176; -- 0
UPDATE quest_objectives SET `Amount`=297, `VerifiedBuild`=22522 WHERE `ID`=259412; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258984; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=260322; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=260175; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259403; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259290; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259607; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258399; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258398; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258397; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258396; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257994; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257993; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257992; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257991; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256972; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256971; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256970; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256969; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257802; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259298; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259399; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258458; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257586; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257228; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256897; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259049; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258972; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=259010; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257178; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258808; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258807; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258806; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258805; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258241; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=258495; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255682; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257617; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257616; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257290; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257289; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257288; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257287; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257522; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257227; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253557; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253556; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257232; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255850; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257482; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257515; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257514; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257513; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256642; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256728; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256895; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256383; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253300; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253299; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253010; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253009; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254317; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254316; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254315; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254177; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254176; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254175; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254106; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254105; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254104; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256220; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256219; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256218; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256217; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256012; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256291; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256290; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256066; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255705; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255704; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256192; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=256191; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255922; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255656; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255782; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255443; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254835; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254780; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254779; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254778; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254191; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254190; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254189; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253832; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=254326; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253648; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255313; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255312; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=255072; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253243; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253242; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=253210; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=252862; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=257052; -- 0
UPDATE quest_objectives SET `VerifiedBuild`=22522 WHERE `ID`=251702; -- 0

DELETE FROM quest_visual_effect WHERE (`ID`=285163 AND `Index`=0);
INSERT INTO quest_visual_effect (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(285163, 0, 505, 22522); -- 285163
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=277283 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=277282 AND `Index`=1); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=277282 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=270085 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=270146 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=270080 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=255057 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=254635 AND `Index`=0); -- 0
UPDATE quest_visual_effect SET `VerifiedBuild`=22522 WHERE (`ID`=252734 AND `Index`=0); -- 0

