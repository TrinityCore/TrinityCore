DELETE FROM `quest_template` WHERE `ID` IN (46360 /*-Unknown-*/, 46308 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(46360, 3, 110, 0, 110, 7543, 135, 0, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 239854, 0, 0, 0, 0, 0, 0, 41484544, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 340, 6, 'Simply Stunning', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23911), -- -Unknown-
(46308, 3, 110, 0, 110, 7543, 135, 0, 0, 6, 1, 0, 0, 0, 0, 0, 0, 0, 239842, 0, 0, 0, 0, 0, 0, 41484544, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 356, 6, 'Leave a Trail', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 23911); -- -Unknown-

UPDATE `quest_template` SET `RewardXPDifficulty`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44293; -- WANTED: Slumber
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44031; -- WANTED: Cadraeus
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardFactionValue1`=3, `RewardFactionValue2`=3, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43755; -- The Magic of Flight
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=5, `RewardFactionValue2`=5, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=42964; -- DANGER: Lagertha
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41528; -- Iridescent Aethril
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41491; -- Brimstone Destroyer
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41269; -- Lively Mossgill Perch
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41207; -- Supplies Needed: Leystone
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `RewardSkillLineID`=186, `RewardNumSkillUps`=1, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41206; -- Work Order: Leystone
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardArtifactCategoryID`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=41196; -- Leystone Basilisks
UPDATE `quest_template` SET `RewardXPDifficulty`=2, `RewardBonusMoney`=1400, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `Expansion`=5, `QuestCompletionLog`='', `VerifiedBuild`=23911 WHERE `ID`=39002; -- Ogres of the Deep
UPDATE `quest_template` SET `Expansion`=5, `VerifiedBuild`=23911 WHERE `ID`=33800; -- Darren's Bombing Run of Awesomeness
UPDATE `quest_template` SET `Expansion`=4, `VerifiedBuild`=23911 WHERE `ID`=30246; -- Upon the Ramparts
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=26958; -- Your First Lesson
UPDATE `quest_template` SET `Expansion`=2, `VerifiedBuild`=23911 WHERE `ID`=24875; -- Deprogramming
UPDATE `quest_template` SET `Expansion`=2, `VerifiedBuild`=23911 WHERE `ID`=13376; -- Total Ohmage: The Valley of Lost Hope!
UPDATE `quest_template` SET `RewardFactionValue1`=7, `RewardFactionValue2`=7, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=2, `VerifiedBuild`=23911 WHERE `ID`=13347; -- Reborn From The Ashes
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=10374; -- A Call to Arms: The Plaguelands!
UPDATE `quest_template` SET `RewardBonusMoney`=91500, `Expansion`=1, `VerifiedBuild`=23911 WHERE `ID`=9681; -- A Study in Power
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `Expansion`=1, `VerifiedBuild`=23911 WHERE `ID`=9601; -- To The Bulwark
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=9187; -- Craftsman's Writ - Runic Leather Pants
UPDATE `quest_template` SET `RewardFactionValue1`=7, `RewardFactionOverride1`=0, `VerifiedBuild`=23911 WHERE `ID`=9122; -- The Dread Citadel - Naxxramas
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=23911 WHERE `ID`=8585; -- The Isle of Dread!
UPDATE `quest_template` SET `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=23911 WHERE `ID`=8574; -- Stalwart's Battlegear
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=8572; -- Veteran's Battlegear
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=8234; -- Sealed Azure Bag
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=8182; -- The Hand of Rastakhan
UPDATE `quest_template` SET `RewardBonusMoney`=274350, `VerifiedBuild`=23911 WHERE `ID`=7643; -- Ancient Equine Spirit
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=7640; -- Exorcising Terrordale
UPDATE `quest_template` SET `RewardFactionValue1`=7, `RewardFactionOverride1`=0, `VerifiedBuild`=23911 WHERE `ID`=7505; -- Frost Shock and You
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=5941; -- Return to Chromie
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=5461; -- The Human, Ras Frostwhisper
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=5220; -- Return to Chillwind Camp
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=3450; -- An Easy Pickup
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=3370; -- In Nightmares
UPDATE `quest_template` SET `RewardNextQuest`=0, `Flags`=540672, `FlagsEx`=64, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=3097; -- Hallowed Scroll
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=2844; -- The Giant Guardian
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=2602; -- Infallible Mind
UPDATE `quest_template` SET `VerifiedBuild`=23911 WHERE `ID`=2584; -- Spirit of the Boar
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=2440; -- The Platinum Discs
UPDATE `quest_template` SET `RewardBonusMoney`=45700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=1780; -- The Tome of Divinity
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=1458; -- Reagents for Reclaimers Inc.
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=1260; -- [DEPRECATED]Morgan Stern
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=23911 WHERE `ID`=720; -- A Sign of Hope
UPDATE `quest_template` SET `RewardFactionValue1`=6, `RewardFactionValue2`=6, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `VerifiedBuild`=23911 WHERE `ID`=32; -- Rise of the Silithid
UPDATE `quest_template` SET `RewardBonusMoney`=137150, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='For your first trial, search the depths of Lake Elune''ara to locate a Shrine Bauble.  It decays rapidly, so proceed with it to the Shrine of Remulos post haste.  Use the bauble at the shrine, and then speak with Tajarri there; she is one of Moonglade''s most trusted wardens.$B$BYou only have a set amount of time to complete the task, and you may be competing against other druids searching for baubles themselves.  Mental and physical dexterity will be critical to your success.$B$BGood luck, $n.', `VerifiedBuild`=23911 WHERE `ID`=29; -- Trial of the Lake
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardFactionValue1`=4, `RewardFactionValue2`=4, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=44031; -- WANTED: Cadraeus
UPDATE `quest_template` SET `RewardXPDifficulty`=0, `RewardXPMultiplier`=0, `RewardFactionValue1`=3, `RewardFactionValue2`=3, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `Expansion`=6, `VerifiedBuild`=23911 WHERE `ID`=43755; -- The Magic of Flight

DELETE FROM `quest_objectives` WHERE `ID` IN (289314 /*289314*/, 289236 /*289236*/, 289235 /*289235*/, 289234 /*289234*/, 289233 /*289233*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(289314, 46360, 0, 4, 119984, 50, 0, 0, 0, 'Demons  stunned in the chasm', 23911), -- 289314
(289236, 46308, 0, 3, 117406, 1, 2, 0, 0, 'Gunpowder lit', 23911), -- 289236
(289235, 46308, 2, 2, 268428, 4, 2, 0, 0, 'Felfire Explosives placed', 23911), -- 289235
(289234, 46308, 2, 1, 267041, 1, 2, 0, 0, 'Fel-Infused Gunpowder acquired', 23911), -- 289234
(289233, 46308, 0, 0, 117258, 1, 0, 0, 0, 'Rappel used', 23911); -- 289233

UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286529; -- 286529
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286132; -- 286132
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285755; -- 285755
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=284924; -- 284924
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282485; -- 282485
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282441; -- 282441
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282149; -- 282149
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282022; -- 282022
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=282021; -- 282021
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=281999; -- 281999
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=278785; -- 278785
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=272009; -- 272009
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=268500; -- 268500
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=267070; -- 267070
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=267069; -- 267069
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=265071; -- 265071
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263941; -- 263941
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263940; -- 263940
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263939; -- 263939
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263938; -- 263938
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=263659; -- 263659
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259373; -- 259373
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259372; -- 259372
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=261260; -- 261260
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=261259; -- 261259
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=261258; -- 261258
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=261257; -- 261257
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259645; -- 259645
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=259644; -- 259644
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259123; -- 259123
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259122; -- 259122
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259121; -- 259121
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259120; -- 259120
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=259119; -- 259119
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258827; -- 258827
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258826; -- 258826
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258825; -- 258825
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258824; -- 258824
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=256979; -- 256979
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=259023; -- 259023
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=259022; -- 259022
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258750; -- 258750
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258749; -- 258749
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=258879; -- 258879
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=258853; -- 258853
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=255873; -- 255873
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=257686; -- 257686
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=257235; -- 257235
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=256503; -- 256503
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=253238; -- 253238
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=253237; -- 253237
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=254098; -- 254098
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=254097; -- 254097
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=254096; -- 254096
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=256338; -- 256338
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=256284; -- 256284
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=256283; -- 256283
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=23911 WHERE `ID`=251742; -- 251742
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=286132; -- 286132
UPDATE `quest_objectives` SET `VerifiedBuild`=23911 WHERE `ID`=285755; -- 285755

DELETE FROM `quest_visual_effect` WHERE (`ID`=289314 AND `Index`=0) OR (`ID`=289236 AND `Index`=2) OR (`ID`=289236 AND `Index`=1) OR (`ID`=289236 AND `Index`=0) OR (`ID`=289234 AND `Index`=0) OR (`ID`=289233 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(289314, 0, 7235, 23911),
(289236, 2, 7045, 23911),
(289236, 1, 7044, 23911),
(289236, 0, 7043, 23911),
(289234, 0, 2099, 23911),
(289233, 0, 2099, 23911);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=285755 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=285755 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=284924 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=282441 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=285755 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=23911 WHERE (`ID`=285755 AND `Index`=0);
