DELETE FROM `quest_template` WHERE `ID`=30292;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(30292, 2, 90, 0, 90, 5840, 0, 0, 0, 5, 1, 114000, 5, 1, 1650, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4104, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1269, 0, 0, 0, 0, 10000, 0, 0, 0, 0, 7, 7, 7, 7, 7, 5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'Rude Awakenings', 'Kill 8 Dominated Paleblade Flesheaters.', 'The mogu are taking over the minds of the saurok at the lake to our west and turning them against us! The thing is, they were already against us, so I''m not sure they really thought this thing through fully.$B$BAnyway, Anji''s the fighter in this pair, I''m more the lover, so I''m looking for someone to do all the weapon swinging and spell flinging and war crying and such.$B$BCan you go kill some saurok for me?', '', '', 738, 0, 0, 0, 2, 0, 0, 0, '', '', '', '', 890, 878, 22522); -- -Unknown-

UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=37974; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=37754; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=37272; -- 0
UPDATE `quest_template` SET `Flags`=33570816, `FlagsEx`=320, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=35994; -- 0
UPDATE `quest_template` SET `Flags`=2097160, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=30818; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30817; -- 0
UPDATE `quest_template` SET `RewardMoney`=114000, `RewardBonusMoney`=1650, `RewardFactionValue1`=10000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30283; -- 0
UPDATE `quest_template` SET `RewardMoney`=114000, `RewardBonusMoney`=1650, `RewardFactionValue1`=10000, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=30282; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=29405; -- 0
UPDATE `quest_template` SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=26841; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=25212; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=25198; -- 0
UPDATE `quest_template` SET `RewardBonusMoney`=30, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=13097; -- 0
UPDATE `quest_template` SET `RewardBonusMoney`=73200, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=13004; -- 0
UPDATE `quest_template` SET `RewardBonusMoney`=36600, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=1024, `VerifiedBuild`=22522 WHERE `ID`=9461; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9226; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9225; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9213; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9211; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=9122; -- 0
UPDATE `quest_template` SET `RewardMoney`=5500, `RewardMoneyDifficulty`=7, `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `AllowableRaces`=-1, `QuestDescription`='The League of Arathor is sparing no expense in their move to retake Arathi.  They, and all the races of the Alliance, now stream to this distant region, intent on expanding their hold from Refuge Pointe.  We must stop them, and the best means to stop them is to take their supplies.$B$BYou can help us, $n.  Enter Arathi Basin, known for its rich mines, fertile land and skilled craftsman.  Capture and control every base you can, win the battle, and return to me with the resources you gain.', `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8162; -- 0
UPDATE `quest_template` SET `RewardMoney`=5500, `RewardMoneyDifficulty`=7, `RewardBonusMoney`=0, `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `AllowableRaces`=-1, `QuestDescription`='War must be fought with soldiers, any soldier will tell you.  They''ll also say that a battle fought with poor gear or on an empty stomach is lost before it starts!$B$BThat is why Arathi Basin is important.  There are key areas in the basin that hold essential resources.  Metals, weapons, food, lumber - all are needed, and all can be gained there.$B$BThat is what I want from you, $n.  Enter Arathi Basin, win the battle by holding more bases than the enemy, and return to me with a crate of resources.', `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=8155; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=7840; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=5321; -- 0
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=-1, `QuestDescription`='Satisfaction. It is what I draw from the hammer and the anvil. To see a proud Horde warrior protected under my steel reminds me of what it is to be alive. It is an addiction that I dare never give up, $n.$B$BI can not grant you this satisfaction, merely set you upon the path. As with all of life''s endeavors, the path of the armorsmith is a journey.$B$BIf you wish to be one of the select few, you need only to ask and I shall train, but, a task you must first complete.', `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=5301; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=4967; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=4224; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=2933; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=2866; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2609; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=2282; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=1791; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=1517; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=1369; -- 0
UPDATE `quest_template` SET `Flags`=16384, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=1276; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=1138; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=3, `VerifiedBuild`=22522 WHERE `ID`=940; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=862; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `VerifiedBuild`=22522 WHERE `ID`=646; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=434; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=4, `VerifiedBuild`=22522 WHERE `ID`=430; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=382; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=380; -- 0
UPDATE `quest_template` SET `RewardMoney`=2500, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=336; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=5, `VerifiedBuild`=22522 WHERE `ID`=224; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=158; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=6, `VerifiedBuild`=22522 WHERE `ID`=155; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=148; -- 0
UPDATE `quest_template` SET `RewardFactionValue1`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `RewardFactionOverride1`=2, `VerifiedBuild`=22522 WHERE `ID`=146; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22522 WHERE `ID`=63; -- 0
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22522 WHERE `ID`=26; -- 0

DELETE FROM `quest_objectives` WHERE `ID` IN (268146 /*268146*/, 260317 /*260317*/, 260316 /*260316*/, 259246 /*259246*/, 260130 /*260130*/, 256842 /*256842*/, 256841 /*256841*/, 256840 /*256840*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(268146, 30292, 0, 0, 63082, 8, 0, 0, '', 22522), -- 268146
(260317, 9226, 1, 1, 22524, 7, 0, 0, '', 22522), -- 260317
(260316, 9226, 1, 0, 22523, 7, 0, 0, '', 22522), -- 260316
(259246, 8162, 4, -1, 392, 297, 0, 0, '', 22522), -- 259246
(260130, 8155, 4, -1, 392, 297, 0, 0, '', 22522), -- 260130
(256842, 5301, 1, 2, 7935, 1, 0, 0, '', 22522), -- 256842
(256841, 5301, 1, 1, 7936, 2, 0, 0, '', 22522), -- 256841
(256840, 5301, 1, 0, 7937, 4, 0, 0, '', 22522); -- 256840

UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=276056; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=274474; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=264103; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=268142; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=268148; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=252338; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=266047; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=260439; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=263315; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=263314; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=263313; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=260655; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=260654; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=260720; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=260719; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=259411; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=259410; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=261260; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=261259; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=261258; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=261257; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=259301; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=258094; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=256750; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253117; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253116; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253115; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253114; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=256472; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255760; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255759; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255518; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=254820; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=254597; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=254440; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253988; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253346; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253345; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=254888; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253218; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253105; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=253104; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255378; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=252447; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=252446; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=252408; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255826; -- 0
UPDATE `quest_objectives` SET `VerifiedBuild`=22522 WHERE `ID`=255825; -- 0

UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=274474 AND `Index`=0); -- 0
UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=268142 AND `Index`=3); -- 0
UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=268142 AND `Index`=2); -- 0
UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=268142 AND `Index`=1); -- 0
UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=268142 AND `Index`=0); -- 0
UPDATE `quest_visual_effect` SET `VerifiedBuild`=22522 WHERE (`ID`=268148 AND `Index`=0); -- 0
