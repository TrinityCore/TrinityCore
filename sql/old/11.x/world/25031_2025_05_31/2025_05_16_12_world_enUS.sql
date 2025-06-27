-- 
DELETE FROM `quest_template` WHERE `ID` IN (91205 /*Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges*/, 89251 /*Running Hot!*/, 89039 /*Turbo-Boost: Powerhouse Challenges*/, 89026 /*Time is Money!!!*/, 89022 /*Loyal Customer: Diamond*/, 89021 /*Loyal Customer: Black*/, 82739 /*Twilight Scheming*/, 82355 /*Special Assignment: Cinderbee Surge*/, 81767 /*Scrounge that Scrap!*/, 81630 /*Activation Protocol*/, 81470 /*Dropping Eaves: Thieving Weave*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `FlagsEx3`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(91205, 2, 0, 2888, -645, 62, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2308000, 0x0, 0x100, 0x0, 0, 0, 0, 0, 0, 0, 237502, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges', 'Defeat any four bosses within The Liberation of Undermine raid on Looking For Raid difficulty or higher, or complete any four Mythic Dungeons.', '<Undermine has a problem. Here\'s what we need. An established group, or just a bunch a ya really, ready to help out our pals in Undermine. Help clear out the worst of the competition, and we\'ll make it worth your time.\n\nComplete the task, and collect a special reward from Consultant Wrexxle outside of the the Dornogal Treasury. Limited time offer. Some restrictions will apply.>', '', 'Return to Consultant Wrexxle outside of the Dornogal Treasury.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Ultra Prime Deluxe Turbo-Boost: Powerhouse Challenges
(89251, 0, 0, 2832, 15522, 0, 0, 0, 0, 1, 0, 1, 1226668, 0, 0, 0, 0, 1, 0, 0x2600000, 0x2080, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Running Hot!', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Running Hot!
(89039, 2, 0, 2888, -645, 62, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2308000, 0x0, 0x100, 0x0, 0, 0, 0, 0, 0, 0, 237502, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Turbo-Boost: Powerhouse Challenges', 'Defeat any four bosses within The Liberation of Undermine raid on Looking For Raid difficulty or higher, or complete any four Mythic Dungeons.', '<Undermine has a problem. Here\'s what we need. An established group, or just a bunch a ya really, ready to help out our pals in Undermine. Help clear out the worst of the competition, and we\'ll make it worth your time.\n\nComplete the task, and collect a special reward from Consultant Wrexxle outside of the the Dornogal Treasury. Limited time offer. Some restrictions will apply.>', '', 'Return to Consultant Wrexxle outside of the Dornogal Treasury.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Turbo-Boost: Powerhouse Challenges
(89026, 0, 0, 2832, 15522, 0, 0, 0, 0, 1, 0, 1, 1225542, 0, 0, 0, 0, 1, 0, 0x2200000, 0x80, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Time is Money!!!', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Time is Money!!!
(89022, 0, 0, 2832, 15522, 0, 0, 0, 0, 1, 0, 1, 1225300, 0, 0, 0, 0, 1, 0, 0x2200000, 0x80, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Loyal Customer: Diamond', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Loyal Customer: Diamond
(89021, 0, 0, 2832, 15522, 0, 0, 0, 0, 1, 0, 1, 1225300, 0, 0, 0, 0, 1, 0, 0x2200000, 0x80, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Loyal Customer: Black', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Loyal Customer: Black
(82739, 2, 0, 201, 1584, 81, 0, 0, 6, 1, 6, 1, 0, 0, 0, 63428, 0, 1, 0, 0x0, 0x0, 0x10000000, 0x0, 0, 0, 0, 0, 0, 0, 65633, 0, 0, 0, 1, 0, 0, 0, 0, 63428, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 0, 0, 6, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Twilight Scheming', 'Use the Glowing Torch to destroy 8 copies of The Twilight Creed in the Domicile of Blackrock Depths.', 'The influence of Twilight\'s Hammer grows within Blackrock Depths. They have allied with the Dark Iron dwarves and seek to convince them to strike outside the mountain.$B$BWe must destroy the instruments of the Twilight\'s Hammer agitation. Their influence over the Dark Irons must be minimized.$B$BI want you to go into Domicile portion of Blackrock Depths and use this torch to burn the books that the Twilight\'s Hammer is distributing there.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Twilight Scheming
(82355, 3, 0, 2837, 14717, 286, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x490100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2590, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8180, 0, 18446744073709551615, 10, 0, 0, 'Special Assignment: Cinderbee Surge', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Special Assignment: Cinderbee Surge
(81767, 3, 0, 2869, 14795, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2594, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Scrounge that Scrap!', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Scrounge that Scrap!
(81630, 3, 0, 2860, 14717, 289, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2390040, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Activation Protocol', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822), -- Activation Protocol
(81470, 3, 0, 2861, 14752, 0, 0, 0, 0, 1, 0, 1, 461421, 0, 0, 0, 0, 1, 0, 0x2710008, 0x8000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Dropping Eaves: Thieving Weave', '', '', '', 'Return to Bobbin in the Umbral Bazaar.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 60822); -- Dropping Eaves: Thieving Weave

UPDATE `quest_template` SET `RewardFactionID1`=0, `RewardFactionID2`=0, `RewardFactionID3`=0, `RewardFactionCapIn1`=0, `RewardFactionCapIn2`=0, `RewardFactionCapIn3`=0, `VerifiedBuild`=60822 WHERE `ID`=86853; -- Sparks of War: Undermine
UPDATE `quest_template` SET `RewardItem1`=0, `RewardAmount1`=0, `Expansion`=10, `VerifiedBuild`=60822 WHERE `ID`=78979; -- Loving Yourself, Your Way
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `VerifiedBuild`=60822 WHERE `ID`=78931; -- Technoscrying: The Mysteries of Dragonskull Island
UPDATE `quest_template` SET `QuestDescription`='The Trial of Style gives us the opportunity to look good, $c.\n\nThe camera makes sure we keep looking good. \n\nSo focus on me and my camera, follow my directions and I\'ll make sure you look fantastic!.', `VerifiedBuild`=60822 WHERE `ID`=76272; -- Work It
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (65411, 65403); -- Puzzling Situation
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=64103; -- Old Tricks Work Best
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=63833; -- Terrorizing the Tremaculum
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=62177; -- A Memorable Look
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=61813; -- Valinor, the Light of Eons
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=61524; -- The Ember Court
UPDATE `quest_template` SET `FlagsEx2`=0x10003000, `VerifiedBuild`=60822 WHERE `ID`=58952; -- Purging Flames
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=58782; -- Things Left Behind
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=58778; -- Getting Ahead
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=58754; -- Champions of the Swarm
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=56889; -- Wounded Wastewanderers
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID` IN (56749, 56747); -- Rustbolt Requisitions: Akunda's Bite
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=56402; -- Wastewander Coins
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=56364; -- Rustbolt Requisitions: Frenzied Fangtooth
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID` IN (55383, 55379); -- Rustbolt Requisitions: Star Moss
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54858; -- Glaive Consequences
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54857; -- Turning the Tides
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54839; -- Rightfully Ours
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54836; -- Commander Drald
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54829; -- Stonebinder Ssra'vess
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54816; -- Hydrath
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54700; -- Thomas Vandergrief
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54678; -- Anything We Can Salvage
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54590; -- Ragebeak
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54588; -- Overseer Krix
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54587; -- Molok the Crusher
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (54539, 54538); -- Skirmish at the Span
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54359; -- Darkshore Donations: Sand Shifter
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=60822 WHERE `ID`=54358; -- Darkshore Donations: Scarlet Diamond
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54355; -- Darkshore Donations: Mistscale
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54353; -- Darkshore Donations: Blood-Stained Bone
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54347; -- Darkshore Donations: Ultramarine Ink
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54346; -- Darkshore Donations: Gold
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54343; -- Darkshore Donations: Potion of Replenishment
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54329; -- Darkshore Donations: War Resources
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54295; -- Artillery Master Goodwin
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=54119; -- Hartford Sternbach
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53979; -- Naga Attack!
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53874; -- End Their Vigil
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53808; -- Crawl To Victory
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53755; -- Blight and Sound
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53712; -- Unfriendly Skies
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53042; -- Stormcaller
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=53040; -- Squall Squelching
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=52415; -- Work Order: Coarse Leather Barding
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=52380; -- Supplies Needed: Frenzied Fangtooth
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=52229; -- Too Much To Bear
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=52159; -- Swab This!
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (52117, 52071); -- Briarback Mountain
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51989; -- Braedan Whitewall
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51906; -- Sister Martha
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51727; -- A Shot at the Dark Iron
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51661; -- Raging Swell
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51621; -- Tidal Teachings
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51548; -- Nagative Feedback
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51467; -- Hyo'gi
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51232; -- Hundred Troll Holdout
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51228; -- Instant Meat, Ready to Eat
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51155; -- Brgl-Lrgl the Basher
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51123; -- Sirokar
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51115; -- Zunashi the Exile
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51105; -- Ak'tar
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51095; -- Ashmane
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=51084; -- Dark Chronicler
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=51005; -- Work Order: Sea Stalk
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=50507; -- Krubbs
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=50322; -- A Feathery Fad
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=49397; -- Sausage Party
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=49195; -- Greater Invasion Point: Occularus
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=49068; -- Quelling the Cove
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=49045; -- Deathscreech
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46904; -- Boon of the Command Center
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46754; -- Magical Beasts
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46264; -- Their Eyes Are Upon Us
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46236; -- Stonebound Soldiers
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46163; -- Thaz'gul
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46105; -- Arachnid Superiority
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46104; -- Arachnid Toxicity
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=46017; -- Shel'drozul
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=44293; -- WANTED: Slumber
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=44289; -- WANTED: Arru
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=44192; -- DANGER: Lysanis Shadesoul
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=44121; -- DANGER: Az'jatar
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=44022; -- WANTED: Shal'an
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=43804; -- Hate the Hatecoil
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=43758; -- Wherever I May Gloam
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=43638; -- The Arcway: Silver Serpent
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=43459; -- WANTED: Thondrax
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=43175; -- DANGER: Deepclaw
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=43027; -- DANGER: Mortiferous
UPDATE `quest_template` SET `FlagsEx2`=0x10000002, `VerifiedBuild`=60822 WHERE `ID`=42926; -- Vault of the Wardens: How'd He Get Up There?
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=42633; -- WANTED: Vorthax
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41895; -- The Master of Pets
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41666; -- Vantus Rune Work Order: Nythendra
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41665; -- Vantus Rune Work Order: Ursoc
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41645; -- Work Order: Silkweave Epaulets
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41617; -- Huge Runescale Koi
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (41573, 41563); -- Felhide
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (41551, 41262); -- Slab of Bacon
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41544; -- Foxflower Cluster
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41536; -- Pungent Fjarnskaggl
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41514; -- Felwort
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41503; -- Leystone Basilisks
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41495; -- Brilliant Leystone Seams
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41482; -- Brimstone Destroyer
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41435; -- Smooth Leystone Deposits
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41292; -- Work Order: Dreamleaf
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41290; -- Aqueous Aethril
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41271; -- Into the Whirlpool
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=41253; -- Migrating Highmountain Salmon
UPDATE `quest_template` SET `ContentTuningID`=339, `VerifiedBuild`=60822 WHERE `ID`=41017; -- Empowering Your Artifact
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=37972; -- Pet Battles Not Active
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=37866; -- Assault on Ironhold Harbor
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=32870; -- Preparing to Strike
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=32808; -- A Little Field Work
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=32184; -- Beastmaster's Quarry: The Crane
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=30736; -- Yan Quillpaw
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=30735; -- Mindel Sunspeaker
UPDATE `quest_template` SET `ContentTuningID`=80, `FlagsEx2`=0x10000000, `AllowableRaces`=18446744073709551615, `VerifiedBuild`=60822 WHERE `ID`=29405; -- The Lesson of the Iron Staff
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=25470; -- Lady Of Da Tigers
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID` IN (24846, 24838); -- A Change of Heart
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=24826; -- Path of Vengeance
UPDATE `quest_template` SET `Expansion`=10, `VerifiedBuild`=60822 WHERE `ID`=24792; -- Man on the Inside
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=13843; -- The Scrapbot Construction Kit
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=11597; -- The Defense of Warsong Hold
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=11586; -- Hellscream's Vigil
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=11524; -- Erratic Behavior
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=11172; -- [DEPRECATED]The Zeppelin Crash
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `VerifiedBuild`=60822 WHERE `ID`=10756; -- Grand Master Rohok
UPDATE `quest_template` SET `Flags`=0x4000, `FlagsEx`=0x40, `Expansion`=-2, `LogTitle`='[DEPRECATED]The Alliance Needs Your Help!', `VerifiedBuild`=60822 WHERE `ID`=10501; -- The Alliance Needs Your Help!
UPDATE `quest_template` SET `Flags`=0x4008, `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=10372; -- A Discreet Inquiry
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=8075; -- Paragons of Power: The Augur's Hauberk
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=8056; -- Paragons of Power: The Augur's Bracers
UPDATE `quest_template` SET `ContentTuningID`=433, `FlagsEx2`=0x10000000, `Expansion`=10, `VerifiedBuild`=60822 WHERE `ID`=7368; -- Defusing the Threat
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=5928; -- Heeding the Call
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=4224; -- The True Masters
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=3443; -- Forging the Shaft
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=3125; -- Faerie Dragon Muisek
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=2742; -- Rin'ji is Trapped!
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=1490; -- Nara Wildmane
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=1148; -- Parts of the Swarm
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=1044; -- Answered Questions
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=60822 WHERE `ID`=669; -- Sunken Treasure
UPDATE `quest_template` SET `FlagsEx2`=0x10000000, `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=60822 WHERE `ID`=54358; -- Darkshore Donations: Scarlet Diamond
UPDATE `quest_template` SET `RewardFactionID1`=0, `RewardFactionID2`=0, `RewardFactionID3`=0, `RewardFactionCapIn1`=0, `RewardFactionCapIn2`=0, `RewardFactionCapIn3`=0, `VerifiedBuild`=60822 WHERE `ID`=86853; -- Sparks of War: Undermine

DELETE FROM `quest_objectives` WHERE `ID` IN (459554 /*459554*/, 462322 /*462322*/, 448278 /*448278*/, 448520 /*448520*/, 448795 /*448795*/, 449890 /*449890*/, 449891 /*449891*/, 449892 /*449892*/, 449893 /*449893*/, 449894 /*449894*/, 449895 /*449895*/, 449896 /*449896*/, 449897 /*449897*/, 449898 /*449898*/, 450271 /*450271*/, 451053 /*451053*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(459554, 89039, 14, 0, 0, 210732, 1, 0, 0, 0, '', 60822), -- 459554
(462322, 91205, 14, 0, 0, 210704, 1, 0, 0, 0, '', 60822), -- 462322
(448278, 81470, 1, 1, 1, 219344, 1, 2, 1, 0, '', 60822), -- 448278
(448520, 81630, 0, 0, 0, 221084, 1, 0, 0, 0, '', 60822), -- 448520
(448795, 81767, 0, 0, 0, 221625, 6, 0, 0, 0, 'Useful Scrap located', 60822), -- 448795
(449890, 82355, 15, 0, -1, 0, 1, 0, 0, 0, 'Cinderbees subdued', 60822), -- 449890
(449891, 82355, 0, 1, 1, 222820, 9, 92, 0, 12, '', 60822), -- 449891
(449892, 82355, 0, 2, 2, 215021, 34, 92, 0, 3, '', 60822), -- 449892
(449893, 82355, 0, 3, 3, 215023, 17, 92, 0, 6, '', 60822), -- 449893
(449894, 82355, 0, 4, 4, 221126, 7, 92, 0, 15, '', 60822), -- 449894
(449895, 82355, 0, 5, 5, 222960, 10, 92, 0, 10, '', 60822), -- 449895
(449896, 82355, 0, 6, 0, 222976, 17, 92, 0, 6, '', 60822), -- 449896
(449897, 82355, 0, 7, 6, 222846, 17, 92, 0, 6, '', 60822), -- 449897
(449898, 82355, 0, 8, 7, 215024, 20, 92, 0, 5, '', 60822), -- 449898
(450271, 82739, 2, 0, 0, 207088, 8, 0, 0, 0, 'Copies of The Twilight Creed burned', 60822), -- 450271
(451053, 81470, 0, 0, 0, 220801, 1, 0, 0, 0, 'Rumor gleaned', 60822); -- 451053

UPDATE `quest_objectives` SET `Order`=1, `VerifiedBuild`=60822 WHERE `ID`=256550; -- 256550

DELETE FROM `quest_visual_effect` WHERE (`ID`=448795 AND `Index`=0) OR (`ID`=451053 AND `Index`=0) OR (`ID`=437451 AND `Index` IN (3,2,1));
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(448795, 0, 2099, 60822),
(451053, 0, 26806, 60822),
(437451, 3, 29403, 60822),
(437451, 2, 29402, 60822),
(437451, 1, 29401, 60822);

DELETE FROM `quest_reward_display_spell` WHERE (`Idx`=0 AND `QuestID` IN (89251,89026,89022,89021));
INSERT INTO `quest_reward_display_spell` (`QuestID`, `Idx`, `SpellID`, `PlayerConditionID`, `VerifiedBuild`) VALUES
(89251, 0, 1226667, 0, 60822),
(89026, 0, 1225540, 0, 60822),
(89022, 0, 1225299, 0, 60822),
(89021, 0, 1225299, 0, 60822);

DELETE FROM `quest_treasure_pickers` WHERE (`QuestID`=84429 AND `TreasurePickerID`=3184 AND `OrderIndex`=1) OR (`QuestID`=82355 AND `TreasurePickerID`=3349 AND `OrderIndex`=1) OR (`QuestID`=82355 AND `TreasurePickerID`=3179 AND `OrderIndex`=0) OR (`QuestID`=81767 AND `TreasurePickerID`=3184 AND `OrderIndex`=1) OR (`QuestID`=81767 AND `TreasurePickerID`=3173 AND `OrderIndex`=0) OR (`QuestID`=81750 AND `TreasurePickerID`=3184 AND `OrderIndex`=1) OR (`QuestID`=81656 AND `TreasurePickerID`=3184 AND `OrderIndex`=1) OR (`QuestID`=81630 AND `TreasurePickerID`=3194 AND `OrderIndex`=0) OR (`QuestID`=81470 AND `TreasurePickerID`=3153 AND `OrderIndex`=0) OR (`QuestID`=78979 AND `TreasurePickerID`=3485 AND `OrderIndex`=0) OR (`QuestID`=78931 AND `TreasurePickerID`=2914 AND `OrderIndex`=0) OR (`QuestID`=32184 AND `TreasurePickerID`=2661 AND `OrderIndex`=0);
INSERT INTO `quest_treasure_pickers` (`QuestID`, `TreasurePickerID`, `OrderIndex`) VALUES
(84429, 3184, 1), -- Construct Containment
(82355, 3349, 1), -- Special Assignment: Cinderbee Surge
(82355, 3179, 0), -- Special Assignment: Cinderbee Surge
(81767, 3184, 1), -- Scrounge that Scrap!
(81767, 3173, 0), -- Scrounge that Scrap!
(81750, 3184, 1), -- Cloud Farming
(81656, 3184, 1), -- Nothing to Waste
(81630, 3194, 0), -- Activation Protocol
(81470, 3153, 0), -- Dropping Eaves: Thieving Weave
(78979, 3485, 0), -- Loving Yourself, Your Way
(78931, 2914, 0), -- Technoscrying: The Mysteries of Dragonskull Island
(32184, 2661, 0); -- Beastmaster's Quarry: The Crane

DELETE FROM `creature_template` WHERE `entry`=240481;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `family`, `type`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(240481, 0, 0, 'Consultant Wrexxle', NULL, 'Undermine Dealer', NULL, NULL, 0, 0, 4, 0, 0, 0, 7, 0, 0, 60822); -- Consultant Wrexxle

DELETE FROM `creature_template_model` WHERE (`CreatureID`=240481 AND `Idx`=0);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(240481, 0, 128227, 1, 1, 60822); -- Consultant Wrexxle
