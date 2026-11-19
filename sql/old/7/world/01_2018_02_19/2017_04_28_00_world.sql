DELETE FROM `quest_template` WHERE `ID` IN (45550 , 45549 );
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(45550, 3, 110, 0, 110, 7543, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239029, 0, 0, 0, 0, 0, 0, 37290240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5181, 0, -1, 340, 6, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 23911),
(45549, 3, 110, 0, 110, 7543, 135, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239029, 0, 0, 0, 0, 0, 0, 37290240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5181, 0, -1, 356, 6, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 23911);

UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=3, `RewardFactionValue2`=3, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43778;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43626;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43618;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=5, `RewardFactionValue2`=5, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=42799;
UPDATE `quest_template` SET `Expansion`=5, `VerifiedBuild`=23911 WHERE `ID`=37753;

DELETE FROM `quest_objectives` WHERE `ID` IN (289533 /*289533*/, 289519 /*289519*/, 289534 /*289534*/, 289518 /*289518*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `VerifiedBuild`) VALUES
(289533, 45550, 0, 1, 118661, 6, 0, 0, 0, 23911), -- 289533
(289519, 45550, 0, 0, 118676, 8, 0, 0, 0, 23911), -- 289519
(289534, 45549, 0, 1, 118661, 6, 0, 0, 0, 23911), -- 289534
(289518, 45549, 0, 0, 118676, 8, 0, 0, 0, 23911); -- 289518

UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285784; -- 285784
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286419; -- 286419
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285563; -- 285563
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285555; -- 285555
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=284770; -- 284770

DELETE FROM `quest_visual_effect` WHERE (`ID`=289533 AND `Index`=7) OR (`ID`=289533 AND `Index`=6) OR (`ID`=289533 AND `Index`=5) OR (`ID`=289533 AND `Index`=4) OR (`ID`=289533 AND `Index`=3) OR (`ID`=289533 AND `Index`=2) OR (`ID`=289533 AND `Index`=1) OR (`ID`=289533 AND `Index`=0) OR (`ID`=289534 AND `Index`=7) OR (`ID`=289534 AND `Index`=6) OR (`ID`=289534 AND `Index`=5) OR (`ID`=289534 AND `Index`=4) OR (`ID`=289534 AND `Index`=3) OR (`ID`=289534 AND `Index`=2) OR (`ID`=289534 AND `Index`=1) OR (`ID`=289534 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(289533, 7, 7121, 23911),
(289533, 6, 7120, 23911),
(289533, 5, 7119, 23911),
(289533, 4, 7118, 23911),
(289533, 3, 7117, 23911),
(289533, 2, 7116, 23911),
(289533, 1, 7115, 23911),
(289533, 0, 7114, 23911),
(289534, 7, 7121, 23911),
(289534, 6, 7120, 23911),
(289534, 5, 7119, 23911),
(289534, 4, 7118, 23911),
(289534, 3, 7117, 23911),
(289534, 2, 7116, 23911),
(289534, 1, 7115, 23911),
(289534, 0, 7114, 23911);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=285784 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=284770 AND `Index`=0);
