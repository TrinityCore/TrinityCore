DELETE FROM `quest_template` WHERE `ID` IN (47015, 46945);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(47015, 0, -1, 0, 110, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 240985, 0, 0, 240686, 0, 0, 0, 0, 1, 0, 39845888, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 350, 6, 'Boon of the Nether Disruptor', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23911),
(46945, 3, 110, 0, 110, 7543, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 218041, 0, 0, 0, 0, 0, 0, 37290304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5219, 0, -1, 359, 6, 'Si''vash', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23911);

UPDATE `quest_template` SET `RewardItem2`=147203, `RewardItem3`=137642, `RewardAmount2`=1, `RewardAmount3`=3, `LogDescription`='Win a PvP Brawl.' WHERE `ID`=47148;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=45071;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44294;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44289;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `RewardArtifactXPMultiplier`=0, `Flags`=37290240, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44054;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardFactionValue1`=3, `RewardFactionValue2`=3, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44018;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43622;
UPDATE `quest_template` SET `Flags`=38797376 WHERE `ID`=42377;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41573;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41565;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41523;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41516;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41484;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41445;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41442;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41433;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41260;
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=26976;
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=24837;
UPDATE `quest_template` SET `Expansion`=2, `VerifiedBuild`=23911 WHERE `ID`=24795;
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=14176;
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=4743;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardFactionValue1`=3, `RewardFactionValue2`=3, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44018;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44294;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44289;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41516;
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardBonusMoney`=0, `RewardArtifactXPMultiplier`=0, `Flags`=37290240, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44054;

DELETE FROM `quest_objectives` WHERE `ID`=289867;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(289867, 46945, 0, 6, 117470, 1, 0, 0, 0, '', 23911); -- 289867

UPDATE `quest_objectives` SET `ObjectID`=59821, `Description`='PvP Brawl won' WHERE `ID`=290090; -- 290090
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=287485; -- 287485
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286530; -- 286530
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286513; -- 286513
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286193; -- 286193
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286204; -- 286204
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286192; -- 286192
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286195; -- 286195
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286203; -- 286203
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286191; -- 286191
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286116; -- 286116
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285559; -- 285559
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282530; -- 282530
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282522; -- 282522
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282479; -- 282479
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282472; -- 282472
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282435; -- 282435
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282385; -- 282385
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282382; -- 282382
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282372; -- 282372
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282139; -- 282139
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=267028; -- 267028
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=267027; -- 267027
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=255356; -- 255356
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=255355; -- 255355
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=265542; -- 265542
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263521; -- 263521
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258391; -- 258391
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286116; -- 286116
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286530; -- 286530
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286513; -- 286513
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282472; -- 282472
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286193; -- 286193
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286204; -- 286204
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286192; -- 286192
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286195; -- 286195
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286203; -- 286203
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286191; -- 286191

DELETE FROM `quest_visual_effect` WHERE (`ID`=289867 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(289867, 0, 2101, 23911);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=287485 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=282435 AND `Index`=0);
