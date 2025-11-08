-- Quests
DELETE FROM `quest_template` WHERE `ID` IN (85834 /*Endangered Specimens*/, 85822 /*Making a Market*/, 86367 /*Grub Stompin'*/, 86821 /*Phase Diving: Unmoored and Unwell*/, 86391 /*Taking Back our Power*/, 86584 /*Overwhelm Them with Mandatory Time Off*/, 86872 /*Phase Diving: Experimental Extermination*/, 86456 /*An Elegy for a Silent World*/, 91089 /*Defeating Ky'veza*/, 91781 /*Seasonal Reminder*/, 91780 /*Ethereal Delves*/, 84896 /*The Next Dimension*/, 91525 /*Head Hunting: Loom'ithar*/, 89274 /*The Ugly Mirror*/, 89293 /*Special Assignment: Overshadowed*/, 91782 /*Repossessed!*/, 89291 /*Phase Diving: Oath-Breaker Desamirah*/, 85855 /*Anything to Declare?*/, 84901 /*[DNT] CH04Q05p*/, 84905 /*To Walk Among Shadow*/, 89238 /*Follow-up Appointment*/, 89240 /*Dream-Dream-Dream-Dream-Dreameringeding!*/, 89056 /*Ray-ket Ball, Redux*/, 85462 /*A Challenge for Dominance*/, 85481 /*Ridge Racer*/, 86184 /*Diminishing Returns*/, 86352 /*Hunting for a Good Author*/, 88974 /*Eco-Stability*/, 86183 /*The Power of Gods*/, 86610 /*Nor Void of Night*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `FlagsEx3`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(85834, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Endangered Specimens', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Endangered Specimens
(85822, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 232578, 232625, 232626, 232627, 20, 20, 20, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8439, 0, 18446744073709551615, 10, 0, 0, 'Making a Market', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Making a Market
(86367, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790000, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8583, 0, 18446744073709551615, 10, 0, 0, 'Grub Stompin\'', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Grub Stompin'
(86821, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 1239449, 0, 0, 0, 0, 1, 0, 0x2790100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Phase Diving: Unmoored and Unwell', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Phase Diving: Unmoored and Unwell
(86391, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790000, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8586, 0, 18446744073709551615, 10, 0, 0, 'Taking Back our Power', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Taking Back our Power
(86584, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2390100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8442, 0, 18446744073709551615, 10, 0, 0, 'Overwhelm Them with Mandatory Time Off', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Overwhelm Them with Mandatory Time Off
(86872, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 1217318, 0, 0, 0, 0, 1, 0, 0x2790100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Phase Diving: Experimental Extermination', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62438), -- Phase Diving: Experimental Extermination
(86456, 2, 0, 3008, 15336, 0, 0, 86457, 5, 1, 5, 1, 0, 0, 0, 234273, 0, 1, 0, 0x2700000, 0x2004, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 234273, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'An Elegy for a Silent World', 'Bring the Dimmed Crystal to Ve\'nari in the Oasis.', '<The crystal you are holding vibrates faintly in your hand. The energy it emits feels like it is holding your hand, trying to reach out and never let go--like it wants you to hold it, to bring it to safety. You can hear a faint song in the back of your mind--a song of fear, confusion, and longing for life.\n\nMaybe Ve\'nari would know more about it?>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- An Elegy for a Silent World
(91089, 2, 0, 2677, -652, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2300008, 0x0, 0x0, 0x0, 0, 0, 131377, 0, 0, 0, 244470, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Defeating Ky\'veza', 'Increase your item level to challenge Ky\'veza in her tier 8 delve on K\'aresh.', 'So she\'s here to collect a bounty, eh?\n\nDid nae one tell her it\'s rude to try and kill a Champion of Azeroth? Or a Bronzebeard, for that matter?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'A talented ethereal assassin looking to collect a price on your head.', 'Nexus-Princess Ky\'veza', '', '', 890, 878, 62493), -- Defeating Ky'veza
(91781, 2, 0, 2677, 15329, 282, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0x2300008, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Seasonal Reminder', 'Learn about Season 3 of Delves from the Delver\'s Documents, then purchase supplies from Reno Jackson and Sir Finley Mrrgglton.', 'We\'re back tae uncovering even more things within delves! \n\nLet\'s get ye up to speed on what\'s new first.\n\nAfter that I\'ll need your help with a wee problem of my own...', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Seasonal Reminder
(91780, 2, 0, 2824, 15329, 282, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0x2380000, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Ethereal Delves', 'Meet Brann Bronzebeard within Dornogal.', 'There\'s even more tae do in delves, $n! \n\nMeet me in Dornogal. There\'s loads to discuss!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Ethereal Delves
(84896, 2, 0, 3008, 15336, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0x2700008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'The Next Dimension', 'Meet with Soul-Scribe in Shan\'dorah on K\'aresh.', 'By the Songs of K\'aresh, I will join you to face the Shadowguard and Dimensius in battle. Let those that would prey on Untamed K\'aresh fear his followers!\n\nMy scouts have tracked your comrades setting a foothold in Shadowguard territory. They will need our assistance. \n\nK\'aresh lives! Our cause is just! Our oaths are unbroken!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- The Next Dimension
(91525, 2, 0, 3228, 16178, 62, 0, 0, 6, 1, 6, 1, 0, 0, 0, 0, 0, 1, 0, 0x2780140, 0x2080, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 245510, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8682, 0, 18446744073709551615, 10, 0, 0, 'Head Hunting: Loom\'ithar', 'Defeat Loom\'ithar within Manaforge Omega on any difficulty.', 'Our intelligence describes a colossal beast within the Manaforge, responsible for producing the fabric that gives the Shadowguard their very form. Take it down and we\'ll hinder their ability to produce reinforcements. Oh, and Ba\'choso says to bring some of the silk back with you - he may be able to fashion it into something useful.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Head Hunting: Loom'ithar
(89274, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 1227993, 0, 0, 0, 0, 1, 0, 0x2790100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8451, 0, 18446744073709551615, 10, 0, 0, 'The Ugly Mirror', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- The Ugly Mirror
(89293, 3, 0, 3008, 15336, 286, 5, 0, 5, 1, 0, 1, 1231857, 0, 0, 0, 0, 1, 0, 0x2790100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Special Assignment: Overshadowed', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Special Assignment: Overshadowed
(91782, 2, 0, 2677, 15329, 0, 0, 0, 5, 1, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0x2700008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Repossessed!', 'Recover Brann\'s lost gear.', 'I think ye may have guessed what my problem is by now, $n.\n\nMy clothes, my tools, my curios! Everything but my boots and hat, which I\'m nae giving up again.\n\nAll repossessed by some cartel thug who said I was delinquent on my void storage payments, if ye can believe it.\n\nWould ye be willing to help Ol\' Brann out of this pickle? I\'m sure if ye just explain that this is all some sort of mistake, they\'ll give back all my hard earned gear.\n\nOr at least me britches.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Repossessed!
(89291, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 1239449, 0, 0, 0, 0, 1, 0, 0x2790100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Phase Diving: Oath-Breaker Desamirah', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Phase Diving: Oath-Breaker Desamirah
(85855, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2790100, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8447, 0, 18446744073709551615, 10, 0, 0, 'Anything to Declare?', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Anything to Declare?
(84901, 2, 0, 3008, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2300008, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, '[DNT] CH04Q05p', '', 'Priest unique quest, do the same objective but mind control an enemy who will help you kill them first.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- [DNT] CH04Q05p
(84905, 2, 0, 3008, 15336, 0, 0, 0, 5, 1, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0x2700008, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'To Walk Among Shadow', 'Help Locus-Walker disable Shadow Point: Torment at Shadow Point on K\'aresh.', 'We must continue disabling or destroying these buildings. I am loathe to destroy the technology of my people, but when used for such dire purpose, there is no choice!\n\nFrom here on out, hold nothing back. Let us raze the works of the Shadowguard.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- To Walk Among Shadow
(89238, 2, 0, 3007, 15792, 0, 0, 0, 3, 1, 3, 1, 1225194, 0, 0, 238913, 0, 1, 0, 0x600008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 238913, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Follow-up Appointment', 'Shrink and collect $1oa Domineering K\'arrocs.', 'There is much medical data to be gleaned in the evaluation of the k\'arrocs.\n\nPlease take the condenser disc to shrink them and then pick the little ones up for easy transport.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Follow-up Appointment
(89240, 2, 0, 3007, 15792, 0, 0, 0, 3, 1, 3, 1, 1225190, 0, 0, 238912, 0, 1, 0, 0x600008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 238912, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Dream-Dream-Dream-Dream-Dreameringeding!', 'Collect $1oa Blood Samples from Regal Thorntails.', 'We need to check how the thorntails are progressing. Would you be so kind as to gather more blood samples?\n\nAs before, use the darts to put them to sleep and then retrieve the dart with the blood on it.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Dream-Dream-Dream-Dream-Dreameringeding!
(89056, 2, 0, 3007, 15792, 0, 0, 0, 3, 1, 3, 1, 1225197, 0, 0, 238915, 0, 1, 0, 0x600008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 238915, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Ray-ket Ball, Redux', 'Catch a ball $1oa times while playing with your Necroray Pup.', 'Time again to test the reflexes of our newborn. \n\nPerhaps you could play more ray-ket ball?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Ray-ket Ball, Redux
(85462, 2, 0, 3007, 15792, 0, 0, 0, 6, 1, 6, 1, 1225189, 0, 0, 0, 0, 1, 0, 0x2200008, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'A Challenge for Dominance', 'Challenge the Slateback Alpha.', 'Our slateback alpha has been getting a bit... testy recently. I believe he is looking for a challenge. \n\nYou are the most combat capable of us. Go give him one.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- A Challenge for Dominance
(85481, 2, 0, 3007, 15792, 0, 0, 0, 3, 1, 3, 1, 1225189, 0, 0, 0, 0, 1, 0, 0x2600008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Ridge Racer', 'Race the Slateback Alpha.', 'Our Slateback Alpha needs to burn off some energy. I believe he is looking for a race.\n\nHe seems to enjoy you the most. Would you race with him?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Ridge Racer
(86184, 2, 0, 3007, 15792, 0, 0, 0, 3, 1, 3, 1, 472963, 0, 0, 232432, 0, 1, 0, 0x2600008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 232432, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Diminishing Returns', 'Shrink and collect $1oa Slateback Roamers.', 'The machine has its uses, but the slatebacks must start breeding so they can sustain themselves. Thus far, they have shown no inclination to do so.\n\nTake this device and use it to collect the slatebacks for testing. Om\'talad will review the data.', '', 'Return to Om\'talad in the Oasis.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Diminishing Returns
(86352, 2, 0, 3007, 15792, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0x20400008, 0x2000, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Hunting for a Good Author', 'Look for Hemet Nesingwary in the Azure Span on the Dragon Isles.', 'I am growing concerned that we may be in danger of overbalancing the ecosystem. We require a consultant. \n\nHave you read \"The Green Hills of Stranglethorn?\" I enjoyed it a great deal. The author appears to have turned from hunter to conservationist. Do not ask how I acquired this information. \n\nHowever, these are precisely the two skills I need. Retrieve him. Last I heard, he was in the Azure Span on the Dragon Isles. Use the portal to travel there.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Hunting for a Good Author
(88974, 0, 0, 3007, 15792, 0, 0, 0, 7, 1, 7, 1, 0, 0, 0, 0, 0, 1, 0, 0x2300008, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'Eco-Stability', 'Help with hatching the snakelets.', 'Speakin\' o\' eggs, I checked an\' Ember has laid her clutch. It\'s almost time ta hatch some babies!\n\nMeet me back at tha nest an\' we can welcome our first snakelets ta K\'aresh.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- Eco-Stability
(86183, 2, 0, 3007, 15792, 0, 0, 86184, 3, 1, 3, 1, 472959, 0, 0, 0, 0, 1, 0, 0x600008, 0x2004, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 10, 0, 0, 'The Power of Gods', 'Help Ve\'nari use her machine to create life in the Oasis.', 'Today, we create life. \n\nAssuming my calculations are correct--which they are--we can use the essence you gathered along with the data we have collected to create new slatebacks.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493), -- The Power of Gods
(86610, 3, 0, 3008, 15336, 109, 0, 0, 5, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0x2390100, 0x0, 0x0, 0x0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 8363, 0, 18446744073709551615, 10, 0, 0, 'Nor Void of Night', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 62493); -- Nor Void of Night

DELETE FROM `quest_details` WHERE `ID` IN (85018 /*Packets of Promises*/, 84974 /*Shards of Hope*/, 84973 /*Of Motes and Husks*/, 91525 /*Head Hunting: Loom'ithar*/, 92031 /*Meet the Vandals*/, 89343 /*The Untethered Void*/, 89561 /*Wrapped Up*/, 89380 /*Another World*/, 84910 /*The Tabiqa*/, 87337 /*Custodian Duties*/, 87290 /*The Oasis*/, 91093 /*More Than Just a Phase*/, 89345 /*The Untethered Horror*/, 89344 /*What Doesn't See You*/, 86364 /*Crests from the Ether*/, 86363 /*The Better Part of Valorstones*/, 91451 /*Stalk Market*/, 84879 /*Restoring Hope*/, 84883 /*K'aresh That Was*/, 84876 /*The Oasis*/, 86332 /*Distribution of Power*/, 84867 /*Stalking Stalkers*/, 84848 /*Before the Void*/, 84838 /*Enemies of Enemies*/, 84869 /*Hunting on Glass*/, 84834 /*Tempest Clefts*/, 86327 /*The Tempest Fields*/, 85730 /*Salvaging What's Left*/, 84831 /*The Rhovan Infestation*/, 84827 /*The Shattered Dome*/, 84826 /*Eco-Dome: Rhovan*/, 90517 /*My Part of the Deal*/, 86946 /*Unwrapped and Unraveled*/, 84866 /*To Purchase Safety*/, 84865 /*Divide and Conquer*/, 84864 /*Her Dark Side*/, 84863 /*Counter Measures*/, 84862 /*Void Alliance*/, 84861 /*This Is Our Dome!*/, 84860 /*Eco-Stabilizing*/, 84859 /*Damage Report 101*/, 84858 /*System Restart*/, 84857 /*Eco-Dome: Primus*/, 84856 /*Where the Void Gathers*/, 86495 /*The Reshii Ribbon*/, 84855 /*Dead Silence*/, 85961 /*Moving the Pawns*/, 85032 /*What Is Left of Home*/, 84967 /*The Shadowguard Shattered*/, 86835 /*Regroup!*/, 84965 /*Core Contributions*/, 84963 /*Sealing the Shadows*/, 84964 /*Heroes Among Shadow*/, 84961 /*Barriers to Entry*/, 84960 /*The Darkness Among Us*/, 84959 /*Lost Lines of Defense*/, 85039 /*Compromised Containment*/, 84958 /*Beasts Unbound*/, 85003 /*Restoring Operational Efficiency*/, 84972 /*Chipping the Void*/, 86820 /*Manaforge Omega: Dimensius Looms*/, 85037 /*That's a Wrap*/, 84906 /*Nexus Regicide*/, 84905 /*To Walk Among Shadow*/, 84904 /*And We Will Answer*/, 84902 /*Adverse Instantiation*/, 84903 /*Until the Sands Bleed Void*/, 84900 /*Like a Knife Through Aether*/, 84899 /*Shadowguard Diffusion*/, 84898 /*The Sands of K'aresh*/, 84897 /*The Calm Before We Storm*/, 84896 /*The Next Dimension*/, 91780 /*Ethereal Delves*/, 91044 /*Hunger of the Void*/, 89327 /*Chaos*/, 89326 /*Distilled Darkness*/, 89325 /*The Void Confluence*/, 89324 /*A Piece of Something Greater*/, 89323 /*Wasted Lands*/, 86786 /*The Void Hunter*/, 91454 /*Phase-Lost Adventurer*/, 90972 /*A Common Cause*/, 91314 /*Untethered Potential*/, 85722 /*Making a Deposit*/, 84765 /*Of Bonds and Boughs*/, 84820 /*By Oath and Blood*/, 84762 /*We Are Our Words*/, 84760 /*A Friendly Warning*/, 84761 /*Toil and Trespass*/, 86193 /*Life for Life*/, 85241 /*A Once-Proud Priest*/, 85240 /*Only Hunger Remains*/, 85239 /*A New Devouring*/, 85238 /*Stranger on the Steps*/, 84759 /*Ill-met in Starlight*/, 84741 /*Signs in the Sands*/, 84915 /*Clearing the Dunes*/, 84740 /*Bridge to Nowhere*/, 86201 /*Watch me Make These Bugs Expire*/, 86200 /*Give me Fire*/, 86196 /*Give me Fuel*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(85018, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Packets of Promises
(84974, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Shards of Hope
(84973, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Of Motes and Husks
(91525, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Head Hunting: Loom'ithar
(92031, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Meet the Vandals
(89343, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Untethered Void
(89561, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Wrapped Up
(89380, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Another World
(84910, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Tabiqa
(87337, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Custodian Duties
(87290, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- The Oasis
(91093, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- More Than Just a Phase
(89345, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Untethered Horror
(89344, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- What Doesn't See You
(86364, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Crests from the Ether
(86363, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Better Part of Valorstones
(91451, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Stalk Market
(84879, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Restoring Hope
(84883, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- K'aresh That Was
(84876, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Oasis
(86332, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Distribution of Power
(84867, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Stalking Stalkers
(84848, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Before the Void
(84838, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Enemies of Enemies
(84869, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Hunting on Glass
(84834, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Tempest Clefts
(86327, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Tempest Fields
(85730, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Salvaging What's Left
(84831, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Rhovan Infestation
(84827, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Shattered Dome
(84826, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Eco-Dome: Rhovan
(90517, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- My Part of the Deal
(86946, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Unwrapped and Unraveled
(84866, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- To Purchase Safety
(84865, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Divide and Conquer
(84864, 378, 0, 0, 0, 0, 0, 0, 0, 62438), -- Her Dark Side
(84863, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Counter Measures
(84862, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Void Alliance
(84861, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- This Is Our Dome!
(84860, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Eco-Stabilizing
(84859, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Damage Report 101
(84858, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- System Restart
(84857, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Eco-Dome: Primus
(84856, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Where the Void Gathers
(86495, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Reshii Ribbon
(84855, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Dead Silence
(85961, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Moving the Pawns
(85032, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- What Is Left of Home
(84967, 1, 273, 5, 0, 0, 0, 0, 0, 62438), -- The Shadowguard Shattered
(86835, 1, 1, 0, 0, 0, 0, 0, 0, 62438), -- Regroup!
(84965, 1, 1, 0, 0, 0, 0, 0, 0, 62438), -- Core Contributions
(84963, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Sealing the Shadows
(84964, 1, 5, 0, 0, 0, 0, 0, 0, 62438), -- Heroes Among Shadow
(84961, 1, 603, 273, 0, 0, 0, 0, 0, 62438), -- Barriers to Entry
(84960, 1, 5, 1, 0, 0, 0, 0, 0, 62438), -- The Darkness Among Us
(84959, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Lost Lines of Defense
(85039, 1, 6, 0, 0, 0, 0, 0, 0, 62438), -- Compromised Containment
(84958, 1, 1022, 0, 0, 0, 0, 0, 0, 62438), -- Beasts Unbound
(85003, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Restoring Operational Efficiency
(84972, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chipping the Void
(86820, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Manaforge Omega: Dimensius Looms
(85037, 11, 0, 0, 0, 0, 0, 0, 0, 62493), -- That's a Wrap
(84906, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Nexus Regicide
(84905, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- To Walk Among Shadow
(84904, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- And We Will Answer
(84902, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Adverse Instantiation
(84903, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Until the Sands Bleed Void
(84900, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Like a Knife Through Aether
(84899, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- Shadowguard Diffusion
(84898, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- The Sands of K'aresh
(84897, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- The Calm Before We Storm
(84896, 1, 0, 0, 0, 0, 0, 0, 0, 62493), -- The Next Dimension
(91780, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Ethereal Delves
(91044, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- Hunger of the Void
(89327, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- Chaos
(89326, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- Distilled Darkness
(89325, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Void Confluence
(89324, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- A Piece of Something Greater
(89323, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- Wasted Lands
(86786, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- The Void Hunter
(91454, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Phase-Lost Adventurer
(90972, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- A Common Cause
(91314, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Untethered Potential
(85722, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Making a Deposit
(84765, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Of Bonds and Boughs
(84820, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- By Oath and Blood
(84762, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- We Are Our Words
(84760, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- A Friendly Warning
(84761, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Toil and Trespass
(86193, 603, 0, 0, 0, 0, 0, 0, 0, 62438), -- Life for Life
(85241, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- A Once-Proud Priest
(85240, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Only Hunger Remains
(85239, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- A New Devouring
(85238, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Stranger on the Steps
(84759, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Ill-met in Starlight
(84741, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Signs in the Sands
(84915, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Clearing the Dunes
(84740, 1, 0, 0, 0, 0, 0, 0, 0, 62438), -- Bridge to Nowhere
(86201, 0, 0, 0, 0, 0, 0, 0, 0, 62438), -- Watch me Make These Bugs Expire
(86200, 273, 0, 0, 0, 0, 0, 0, 0, 62438), -- Give me Fire
(86196, 273, 0, 0, 0, 0, 0, 0, 0, 62438); -- Give me Fuel

DELETE FROM `quest_offer_reward` WHERE `ID` IN (85018 /*Packets of Promises*/, 84974 /*Shards of Hope*/, 84973 /*Of Motes and Husks*/, 92031 /*Meet the Vandals*/, 89345 /*The Untethered Horror*/, 89344 /*What Doesn't See You*/, 89343 /*The Untethered Void*/, 86363 /*The Better Part of Valorstones*/, 91451 /*Stalk Market*/, 84876 /*The Oasis*/, 84867 /*Stalking Stalkers*/, 86332 /*Distribution of Power*/, 84848 /*Before the Void*/, 84838 /*Enemies of Enemies*/, 84869 /*Hunting on Glass*/, 84834 /*Tempest Clefts*/, 86327 /*The Tempest Fields*/, 85730 /*Salvaging What's Left*/, 84827 /*The Shattered Dome*/, 84831 /*The Rhovan Infestation*/, 84826 /*Eco-Dome: Rhovan*/, 90517 /*My Part of the Deal*/, 86946 /*Unwrapped and Unraveled*/, 84866 /*To Purchase Safety*/, 84863 /*Counter Measures*/, 84864 /*Her Dark Side*/, 84865 /*Divide and Conquer*/, 84861 /*This Is Our Dome!*/, 84862 /*Void Alliance*/, 84860 /*Eco-Stabilizing*/, 84859 /*Damage Report 101*/, 84858 /*System Restart*/, 84857 /*Eco-Dome: Primus*/, 84856 /*Where the Void Gathers*/, 86495 /*The Reshii Ribbon*/, 84855 /*Dead Silence*/, 85961 /*Moving the Pawns*/, 85032 /*What Is Left of Home*/, 84967 /*The Shadowguard Shattered*/, 86835 /*Regroup!*/, 84965 /*Core Contributions*/, 84964 /*Heroes Among Shadow*/, 84963 /*Sealing the Shadows*/, 84961 /*Barriers to Entry*/, 84960 /*The Darkness Among Us*/, 85003 /*Restoring Operational Efficiency*/, 84958 /*Beasts Unbound*/, 85039 /*Compromised Containment*/, 84959 /*Lost Lines of Defense*/, 84957 /*Return to the Veiled Market*/, 89561 /*Wrapped Up*/, 89380 /*Another World*/, 84910 /*The Tabiqa*/, 84879 /*Restoring Hope*/, 84883 /*K'aresh That Was*/, 87290 /*The Oasis*/, 86364 /*Crests from the Ether*/, 91624 /*Spark of Starlight*/, 84972 /*Chipping the Void*/, 85037 /*That's a Wrap*/, 84906 /*Nexus Regicide*/, 84905 /*To Walk Among Shadow*/, 84903 /*Until the Sands Bleed Void*/, 84902 /*Adverse Instantiation*/, 84904 /*And We Will Answer*/, 84900 /*Like a Knife Through Aether*/, 84899 /*Shadowguard Diffusion*/, 84898 /*The Sands of K'aresh*/, 84897 /*The Calm Before We Storm*/, 84896 /*The Next Dimension*/, 91044 /*Hunger of the Void*/, 89327 /*Chaos*/, 89326 /*Distilled Darkness*/, 89325 /*The Void Confluence*/, 89324 /*A Piece of Something Greater*/, 89323 /*Wasted Lands*/, 86786 /*The Void Hunter*/, 90972 /*A Common Cause*/, 91314 /*Untethered Potential*/, 91454 /*Phase-Lost Adventurer*/, 85722 /*Making a Deposit*/, 84765 /*Of Bonds and Boughs*/, 84820 /*By Oath and Blood*/, 84762 /*We Are Our Words*/, 84760 /*A Friendly Warning*/, 84761 /*Toil and Trespass*/, 84759 /*Ill-met in Starlight*/, 86193 /*Life for Life*/, 85241 /*A Once-Proud Priest*/, 85240 /*Only Hunger Remains*/, 85239 /*A New Devouring*/, 85238 /*Stranger on the Steps*/, 84741 /*Signs in the Sands*/, 84915 /*Clearing the Dunes*/, 84740 /*Bridge to Nowhere*/, 86201 /*Watch me Make These Bugs Expire*/, 86200 /*Give me Fire*/, 86196 /*Give me Fuel*/, 91093 /*More Than Just a Phase*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(85018, 1, 0, 0, 0, 0, 0, 0, 0, 'Well? Is he ready to apologize and get back to work? \n\n<You hand him the satchel of seeds.>\n\nWhat\'s this, now?', 62438), -- Packets of Promises
(84974, 1, 0, 0, 0, 0, 0, 0, 0, 'Well? Let me see what you procured.', 62438), -- Shards of Hope
(84973, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, you return with motes and husks for me?', 62438), -- Of Motes and Husks
(92031, 0, 0, 0, 0, 0, 0, 0, 0, 'Hero! Your reputation for toppling tyrants precedes you. Let\'s see about adding one more to that list.', 62493), -- Meet the Vandals
(89345, 1, 0, 0, 0, 0, 0, 0, 0, 'Netherdeath is no more. Our exploration of Untethered Space can proceed. I knew you were the right person to help us in our endeavors, $p.\n\nWe would be honored if you would continue to work with us in our exploration.', 62438), -- The Untethered Horror
(89344, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $n. These predators from the Void ambush us and consume the very energy we use to power the eco-domes.', 62438), -- What Doesn't See You
(89343, 1, 0, 0, 0, 0, 0, 0, 0, 'You learn quickly. Good. Untethered Space devours the foolish and unwise.', 62438), -- The Untethered Void
(86363, 0, 0, 0, 0, 0, 0, 0, 0, 'My friend! I knew I could count on you. Please take these tokens for your effort.', 62438), -- The Better Part of Valorstones
(91451, 1, 0, 0, 0, 0, 0, 0, 0, '<Om\'mit turns the plant over in his hands.>\n\nA void-infused stalk from a dead wasteland? This is utterly useless to you. In fact, let me take it off your hands in exchange for plants with more... familiar properties.\n\nOther Cartel Om members in the Veiled Market may also be interested in trading wares, should you come across them.', 62438), -- Stalk Market
(84876, 1, 0, 0, 0, 0, 0, 0, 0, 'This is most irregular. Ve\'nari may have asked that we extend all courtesy to the Harbinger and her champion. But these Wastelander barbarians? \n\nI hope Ve\'nari knows what she\'s doing.', 62438), -- The Oasis
(84867, 1, 0, 0, 0, 0, 0, 0, 0, 'Word has filtered up through my camp about what you have done for us. My daughter has always been too trusting, but your efforts do not go unnoticed.', 62438), -- Stalking Stalkers
(86332, 1, 0, 0, 0, 0, 0, 0, 0, 'Your help does not go unnoticed. My people will live another day, and hopefully many more, thanks to the energy that\'s in those crates.', 62438), -- Distribution of Power
(84848, 1, 0, 0, 0, 0, 0, 0, 0, 'We would gladly war against the Shadowguard. But I cannot give up this Reshii Ribbon to someone I don\'t trust.\n\nPromises of revenge are easy. Trust is hard won among the Wastelanders.', 62438), -- Before the Void
(84838, 1, 0, 0, 0, 0, 0, 0, 0, 'Dimensius destroyed K\'aresh. Here in the wastes of Merciless K\'aresh, we mete out punishment for all who failed him. You say your oaths align with ours? Let us talk.', 62438), -- Enemies of Enemies
(84869, 1, 0, 0, 0, 0, 0, 0, 0, 'These Wastelanders respect strength and violence. I think we\'re going to get along quite well.', 62438), -- Hunting on Glass
(84834, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, my champion. We shall use this to draw out our prey.', 62438), -- Tempest Clefts
(86327, 1, 0, 0, 0, 0, 0, 0, 0, 'The aura of Dimensius is tearing what\'s left of K\'aresh apart. Soon he will draw in what remains of this little world.\n\nOur time to stop him grows shorter by the hour.', 62438), -- The Tempest Fields
(85730, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for retrieving the crates. Om\'bera\'s research will help us find a stable biome in time.', 62438), -- Salvaging What's Left
(84827, 1, 0, 0, 0, 0, 0, 0, 0, 'The Wastelanders killed Om\'bera and took her Reshii Ribbon. These fallen oracles have harried all members of the Ravel since the Devouring War. This is a grim day.', 62438), -- The Shattered Dome
(84831, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you. Those creatures would soon overwhelm us if left unchecked.\n\nIt\'s amazing they can survive without the protective barrier of the dome, without becoming energy as the K\'areshi did. I wonder if such resilient traits could be transferred to the few native species in our domes?', 62438), -- The Rhovan Infestation
(84826, 1, 0, 0, 0, 0, 0, 0, 0, 'The dome is shattered and Om\'bera may be in danger! I can see the scavengers from the wastelands of K\'aresh within it now. \n\nOm\'bera may yet live. We must find her, and her Reshii Ribbon.', 62438), -- Eco-Dome: Rhovan
(90517, 1, 0, 0, 0, 0, 0, 0, 0, 'You have my ribbon. Go--track down the rest. Have Locus-Walker contact the other members of the Ravel. Ask the Harbinger if she knows any ancient horrors that have acquired one. Remember rule twelve--it\'s who you know.', 62438), -- My Part of the Deal
(86946, 1, 0, 0, 0, 0, 0, 0, 0, 'This is just like the Harbinger to fulfill her oaths to the letter, but leave her allies devastated. If there was any other way to stop the All-Devouring from rising once more...\n\nWith my Reshii Ribbon, you are a step closer toward reaching Dimensius. But you will need at least twice as many to get a force large enough past his dread aura. Good luck, $n. Watch the Harbinger\'s every move.', 62438), -- Unwrapped and Unraveled
(84866, 1, 0, 0, 0, 0, 0, 0, 0, 'With that necessary violence taken care of, the three of us can talk. You are correct, Alleria. Great secrets have been kept from you. Secrets that were not mine to reveal but should have been revealed to you years ago.', 62438), -- To Purchase Safety
(84863, 1, 0, 0, 0, 0, 0, 0, 0, 'Good job, $n. That should satisfy Ve\'nari.', 62438), -- Counter Measures
(84864, 1, 0, 0, 0, 0, 0, 0, 0, 'I feel like there is something Locus-Walker and Ve\'nari are keeping from me. Some secret during the Devouring War that they don\'t want me to know. Xal\'atath is pulling on this doubt to manipulate me. \n\nLet\'s defeat the Shadowguard, then we can uncover the truth.', 62438), -- Her Dark Side
(84865, 1, 0, 0, 0, 0, 0, 0, 0, 'Without their cannons, the Shadowguard\'s attacks on the eco-dome are doomed to failure. Ve\'nari won\'t have need of her Reshii Ribbon. \n\nI\'m more and more unsettled by this plan of ours, though--the secrets... this Alliance with Xal\'atath... I fear Locus-Walker made a mistake thousands of years ago, and we cannot escape that ancient mistake.', 62438), -- Divide and Conquer
(84861, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. That will buy us enough time to secure this dome.', 62438), -- This Is Our Dome!
(84862, 1, 0, 0, 0, 0, 0, 0, 0, 'That should secure this dome. But will Ve\'nari make us float through any more hoops?', 62438), -- Void Alliance
(84860, 1, 0, 0, 0, 0, 0, 0, 0, 'Good work, $n.\n\nThe interior of the dome is stabilized. All the eco-dome systems are functioning. My investment in the eco-domes will continue to pay dividends. Unless the Shadowguard attack again.', 62438), -- Eco-Stabilizing
(84859, 1, 0, 0, 0, 0, 0, 0, 0, 'Are they alive? Good. Next time they forget to check in, they won\'t be.\n\n<Ve\'nari skims through the reports.>\n\nIt looks like there was minimal damage, if any at all, to most of the facility. The Shadowguard saboteurs were focused on rerouting our energy reserves to the outer conduits. They have ignored the environmental and secondary systems.', 62438), -- Damage Report 101
(84858, 1, 0, 0, 0, 0, 0, 0, 0, 'Environmental support may be back up and running, but don\'t get complacent. That was merely the first of the many problems plaguing this eco-dome.', 62438), -- System Restart
(84857, 1, 0, 0, 0, 0, 0, 0, 0, 'The Shadowguard attacked the eco-dome. They must covet the vast stores of energy needed to shield the delicate biomes from the Void of K\'aresh.', 62438), -- Eco-Dome: Primus
(84856, 1, 0, 0, 0, 0, 0, 0, 0, 'Through this, you have learned what I already knew. \n\nDimensius is a terrible threat. We must work together, $p, if we are to survive.', 62438), -- Where the Void Gathers
(86495, 1, 0, 0, 0, 0, 0, 0, 0, 'She agreed?\n\nAlleria listens to you, my champion. You are indeed our savior.', 62438), -- The Reshii Ribbon
(84855, 1, 0, 0, 0, 0, 0, 0, 0, 'Raz\'ida was a Shadowguard agent? I\'ve trusted her for thousands of years. How did they break her loyalty? \n\nIf she could be turned, then any of the Trust\'s agents could as well. It is vital that we get the information about their base, and we can only rely upon the four of us to do so.', 62438), -- Dead Silence
(85961, 1, 0, 0, 0, 0, 0, 0, 0, 'I hope my scouts have found a way to safely enter the manaforge.', 62438), -- Moving the Pawns
(85032, 1, 0, 0, 0, 0, 0, 0, 0, 'This is what we are fighting for, $n. We can only save fragments of K\'aresh, but we can prevent other worlds from sharing our dreadful fate.', 62438), -- What Is Left of Home
(84967, 274, 1, 0, 0, 0, 0, 0, 0, 'Without their leader, the Shadowguard\'s assault on Tazavesh is crippled! For that, you have my gratitude.\n\n<He pauses for a weighty moment.>\n\nHowever, do not let this victory lull you into a false sense of security. There are darker forces at play--far more dangerous than the Shadowguard. \n\nTo resist them, we will need every advantage we can get... even those we would normally not consider.', 62438), -- The Shadowguard Shattered
(86835, 1, 603, 0, 0, 0, 0, 0, 0, 'I found our quarry, but unfortunately not before they broke into this shelter.', 62438), -- Regroup!
(84965, 1, 1, 603, 0, 0, 0, 0, 0, 'Excellent! That\'ll go a long way toward securing the city.', 62438), -- Core Contributions
(84964, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. We made a difference here!', 62438), -- Heroes Among Shadow
(84963, 1, 273, 0, 0, 0, 0, 0, 0, 'These look like they\'re in good condition! Okay, let\'s go ahead and move on to the next phase of this plan.', 62438), -- Sealing the Shadows
(84961, 1, 1, 0, 0, 0, 0, 0, 0, 'Well done. The shield around the city looks stronger already. \n\nThat should buy us some time against the Shadowguard.', 62438), -- Barriers to Entry
(84960, 1, 1, 0, 0, 0, 0, 0, 0, 'The Shadowguard! Of course those void-addled fools are behind this. I should have known.', 62438), -- The Darkness Among Us
(85003, 1, 6, 0, 0, 0, 0, 0, 0, 'All the problems are solved. At least, all the problems that were on my ledger that I was responsible for.', 62438), -- Restoring Operational Efficiency
(84958, 1, 6, 1, 0, 0, 0, 0, 0, 'You\'ve returned them! Excellent work. \n\nHere is your reward, as promised.', 62438), -- Beasts Unbound
(85039, 1, 1, 273, 0, 0, 0, 0, 0, 'You sealed the artifact? Excellent! The remaining creatures should dissipate in time. \n\nYou\'ve handled the danger with remarkable skill. As promised, here are your rewards.', 62438), -- Compromised Containment
(84959, 1, 6, 0, 0, 0, 0, 0, 0, 'Excellent! With these projectors, we can once again secure our homeland. \n\nAnyway, you have my thanks for your assistance.', 62438), -- Lost Lines of Defense
(84957, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome to Tazavesh, both of you.\n\nWe have much to discuss. Your assistance is crucial, as always.', 62438), -- Return to the Veiled Market
(89561, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $p. Your adventures in Untethered Space will help clear the way for our Phase Divers to recover the energy that would have been lost to the Void.', 62438), -- Wrapped Up
(89380, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for accepting our offer, $n. This is dangerous work that will push you beyond the limits of our reality. But with risk we find profit, and with profit we can change the world.', 62438), -- Another World
(84910, 1, 0, 0, 0, 0, 0, 0, 0, 'And the pieces fall together. Perhaps we have enough strength to take on the Shadowguard, my champion.\n\nLet me tip the scales further. With the power of these Reshii Ribbons,  I will infuse these Reshii Wraps with enough to empower you to explore Untethered Space... and gather strength for the fight ahead.\n\nYou\'re welcome.', 62438), -- The Tabiqa
(84879, 1, 0, 0, 0, 0, 0, 0, 0, 'We have a lot riding on this Tabiqa ritual going exactly to plan. Having to kill her to get her ribbon would be inconvenient.', 62438), -- Restoring Hope
(84883, 1, 0, 0, 0, 0, 0, 0, 0, 'To hold these blossoms in my hands again... I never thought I would see the day.', 62438), -- K'aresh That Was
(87290, 1, 0, 0, 0, 0, 0, 0, 0, 'Ve\'nari did not tell me she was hiring offworlders. Good help is so hard to find. I suppose you will have to do.', 62493), -- The Oasis
(86364, 0, 0, 0, 0, 0, 0, 0, 0, 'This is wonderful. I\'m excited for you to grow in power! And to advance my research, of course. But yes, your power growth!', 62438), -- Crests from the Ether
(91624, 0, 0, 0, 0, 0, 0, 0, 0, 'This is a fractured spark of starlight.\n\nEvery week, one of these fragments will appear while on your adventures. In its current state it\'s rather useless, but combining it with another fragment will grant it power. Reagents like these are malleable, robust, and the prize for many crafters.\n\nCombining two of these fractured fragments will create a unique crafting material that can help an item achieve expertise beyond that of mortal ability.', 62438), -- Spark of Starlight
(84972, 1, 0, 0, 0, 0, 0, 0, 0, 'Well? Let me see what you procured.', 62438), -- Chipping the Void
(85037, 1, 0, 0, 0, 0, 0, 0, 0, 'Stay vigilant my friend. Xal\'atath\'s games have not yet unfolded. \n\nWe must be prepared for her inevitable betrayal.', 62493), -- That's a Wrap
(84906, 1, 0, 0, 0, 0, 0, 0, 0, 'Hmmph.\n\nI grow tired of this lesson, $n. Always when we get close to someone they betray us. They falter. They turn. They die. Always we put them in danger and we fail to protect them.\n\nLet no one else stand in our path. You and me, $n. We will finish this.', 62493), -- Nexus Regicide
(84905, 1, 0, 0, 0, 0, 0, 0, 0, 'There is only more darkness ahead of us. Be prepared for anything.', 62493), -- To Walk Among Shadow
(84903, 0, 0, 0, 0, 0, 0, 0, 0, 'Is this the fate of the ren\'dorei? Given long enough, will we too serve the very forces we fight today? I had always looked to Locus-Walker as an example we can emulate, but it appears the ren\'dorei must find their own path.', 62493), -- Until the Sands Bleed Void
(84902, 1, 0, 0, 0, 0, 0, 0, 0, 'My people\'s technomancy could be put to great and beneficial use, yet time and time again we use it for great evil. As Dimensius\'s power grows, we are all diminished.', 62493), -- Adverse Instantiation
(84904, 0, 0, 0, 0, 0, 0, 0, 0, 'How many were lost, do you think?\n\nI have a duty to my people. Let us finish this so none are forced to serve the All-Devouring again.', 62493), -- And We Will Answer
(84900, 378, 0, 0, 0, 0, 0, 0, 0, 'Two more to go. Two more places for the ribbon to be hidden.', 62493), -- Like a Knife Through Aether
(84899, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $n. If the Shadowguard bled, I am certain the sands would be soaked.\n\nMany more lay before us on the path to victory. There will be time for celebrations yet.', 62493), -- Shadowguard Diffusion
(84898, 1, 0, 0, 0, 0, 0, 0, 0, 'These will do. They are still as sharp as ever. I will arm my people and your allies. For K\'aresh, $n.', 62493), -- The Sands of K'aresh
(84897, 1, 0, 0, 0, 0, 0, 0, 0, 'These elves are more resilient than I thought. Perhaps our people have both been tempered by adversity?', 62493), -- The Calm Before We Storm
(84896, 1, 0, 0, 0, 0, 0, 0, 0, 'I did not know there were this many void-touched from your world. How do they shield their souls from its madness?', 62493), -- The Next Dimension
(91044, 5, 0, 0, 0, 0, 0, 0, 0, 'I sincerely hope that Adarus is well, and that he doesn\'t blame us. The ren\'dorei have enough enemies as it is.\n\nI am excited that Leona has made a breakthrough. Though she never would have succeeded without your help.', 62438), -- Hunger of the Void
(89327, 5, 0, 0, 0, 0, 0, 0, 0, 'I didn\'t have the time or focus to pick a destination for that portal, $n. He could be anywhere.', 62438), -- Chaos
(89326, 5, 0, 0, 0, 0, 0, 0, 0, 'Well done. I\'ll take it from here.', 62438), -- Distilled Darkness
(89325, 1, 0, 0, 0, 0, 0, 0, 0, 'We\'re nearly prepared. Although I can\'t help but wonder if Adarus\' reach exceeds his grasp.', 62438), -- The Void Confluence
(89324, 5, 0, 0, 0, 0, 0, 0, 0, 'Retain the fragment for now.\n\nI will need it soon.', 62438), -- A Piece of Something Greater
(89323, 5, 0, 0, 0, 0, 0, 0, 0, 'Its power begs to be released. Can\'t you hear it?', 62438), -- Wasted Lands
(86786, 6, 0, 0, 0, 0, 0, 0, 0, 'You\'ve been helpful so far. And in return, I\'ll allow you to take part in making history on this discarded, broken corpse of a planet.', 62438), -- The Void Hunter
(90972, 5, 0, 0, 0, 0, 0, 0, 0, 'Adarus sent you? \n\nHis lack of faith in my abilities and desire to delegate speak volumes.', 62438), -- A Common Cause
(91314, 1, 0, 0, 0, 0, 0, 0, 0, 'This will provide a lot to forward my research on Untethered Space. I thank you.\n\nI can\'t imagine what discoveries we can begin to unravel about K\'aresh.', 62438), -- Untethered Potential
(91454, 0, 0, 0, 0, 0, 0, 0, 0, '<Essarae flips to a random page in the journal.>\n\nThis is brimming with knowledge of Untethered Space. I would like to read it further. \n\nThank you for aiding my research.', 62438), -- Phase-Lost Adventurer
(85722, 1, 0, 0, 0, 0, 0, 0, 0, 'An impressive kill. An even more impressive trade.\n\nYou will be rewarded. I will not have myself in your debt.', 62438), -- Making a Deposit
(84765, 0, 0, 0, 0, 0, 0, 0, 0, 'After all this time, I thought it would feel different when we honored the oath. \n\nMaybe now\'s the time to stop thinking on the past. Thank you.', 62438), -- Of Bonds and Boughs
(84820, 0, 0, 0, 0, 0, 0, 0, 0, 'I almost didn\'t expect her to come for me, especially not like that. Even so, the surveyor\'s damaged and Shahata\'s supplies went up in flames. Maybe I shouldn\'t have come home.', 62438), -- By Oath and Blood
(84762, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s all gone. Months of supplies up in flames. If Fennad isn\'t dead already, he will be soon. The Sufaadi won\'t be forgiving, especially after what we\'ve done.', 62438), -- We Are Our Words
(84760, 1, 0, 0, 0, 0, 0, 0, 0, 'Hopefully that will be enough to scare them off--at least for a while.', 62438), -- A Friendly Warning
(84761, 1, 0, 0, 0, 0, 0, 0, 0, 'Is this all you found? They didn\'t waste any time using up my supplies. Still, it\'s something.', 62438), -- Toil and Trespass
(84759, 1, 0, 0, 0, 0, 0, 0, 0, 'I hadn\'t expected to see Fennad again. He\'s a bit late to help with mother\'s funeral rites. The tree is gone along with the grave, and now he comes to ask for favors?', 62438), -- Ill-met in Starlight
(86193, 1, 0, 0, 0, 0, 0, 0, 0, 'Are you alright? I tried to protect you from the blast.\n\n<Om\'taha flickers in and out of sight.>\n\nSorry. That took a lot. I just need a moment.', 62438), -- Life for Life
(85241, 1, 0, 0, 0, 0, 0, 0, 0, 'No. He\'s dead. Why hasn\'t it stopped? It\'s only growing stronger.', 62438), -- A Once-Proud Priest
(85240, 0, 0, 0, 0, 0, 0, 0, 0, 'Even if we fail here, this might give our defenders a chance.', 62438), -- Only Hunger Remains
(85239, 1, 0, 0, 0, 0, 0, 0, 0, 'That will slow them down, but I worry it\'s not enough. We need to end this before they destroy all of our work.', 62438), -- A New Devouring
(85238, 1, 0, 0, 0, 0, 0, 0, 0, 'I heard him fall. I should have stopped for him. Instead, I kept running.\n\nWe have to make this right. We turned the machine into a weapon for the Wastelanders. It won\'t help rejuvenate the land--it will kill everything.', 62438), -- Stranger on the Steps
(84741, 1, 0, 0, 0, 0, 0, 0, 0, 'I don\'t know what I expected. She\'s right. I did break my oath, and now the village is gone.... She\'s still here, though. \n\nIf she has anything that belonged to our mother, then there\'s still a chance the surveyor can trace it to the grave.', 62438), -- Signs in the Sands
(84915, 1, 0, 0, 0, 0, 0, 0, 0, 'It seems only the most vicious creatures survive outside of the eco-domes. When we find my sister, I\'ll bring her back to Tazavesh where it\'s safe.', 62438), -- Clearing the Dunes
(84740, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $p. I think I have my bearings now. You see how much life used to be here? It\'s hard to imagine Shahata surviving here for so long... No. We\'ll find her. We have to.', 62438), -- Bridge to Nowhere
(86201, 0, 0, 0, 0, 0, 0, 0, 0, 'The eco-dome shield integrity is returning to normal levels. I knew I could count on your race\'s predilection for fire, $r.', 62438), -- Watch me Make These Bugs Expire
(86200, 5, 0, 0, 0, 0, 0, 0, 0, 'Excellent. I hope you\'re ready to bring the wrath of the brokers down onto these troublesome creatures.', 62438), -- Give me Fire
(86196, 5, 0, 0, 0, 0, 0, 0, 0, 'Perfect, $c. With our equipment, we\'ll be able to unlock the power within this humble plant.', 62438), -- Give me Fuel
(91093, 1, 0, 0, 0, 0, 0, 0, 0, 'Your assistance is most appreciated, $r. The Trust was wise in appointing you to aid our efforts.', 62438); -- More Than Just a Phase

DELETE FROM `quest_request_items` WHERE `ID` IN (84900 /*Like a Knife Through Aether*/, 84897 /*The Calm Before We Storm*/, 84883 /*K'aresh That Was*/, 84879 /*Restoring Hope*/, 84869 /*Hunting on Glass*/, 84867 /*Stalking Stalkers*/, 84865 /*Divide and Conquer*/, 84864 /*Her Dark Side*/, 84863 /*Counter Measures*/, 84862 /*Void Alliance*/, 84861 /*This Is Our Dome!*/, 84860 /*Eco-Stabilizing*/, 84859 /*Damage Report 101*/, 84858 /*System Restart*/, 84856 /*Where the Void Gathers*/, 85241 /*A Once-Proud Priest*/, 85238 /*Stranger on the Steps*/, 85039 /*Compromised Containment*/, 85037 /*That's a Wrap*/, 84838 /*Enemies of Enemies*/, 85032 /*What Is Left of Home*/, 84834 /*Tempest Clefts*/, 84831 /*The Rhovan Infestation*/, 84827 /*The Shattered Dome*/, 86201 /*Watch me Make These Bugs Expire*/, 86200 /*Give me Fire*/, 85018 /*Packets of Promises*/, 86196 /*Give me Fuel*/, 86786 /*The Void Hunter*/, 89345 /*The Untethered Horror*/, 91314 /*Untethered Potential*/, 89344 /*What Doesn't See You*/, 89343 /*The Untethered Void*/, 85003 /*Restoring Operational Efficiency*/, 89327 /*Chaos*/, 89326 /*Distilled Darkness*/, 89324 /*A Piece of Something Greater*/, 91093 /*More Than Just a Phase*/, 86364 /*Crests from the Ether*/, 84974 /*Shards of Hope*/, 84973 /*Of Motes and Husks*/, 84972 /*Chipping the Void*/, 84967 /*The Shadowguard Shattered*/, 84965 /*Core Contributions*/, 84964 /*Heroes Among Shadow*/, 84963 /*Sealing the Shadows*/, 84961 /*Barriers to Entry*/, 84960 /*The Darkness Among Us*/, 84762 /*We Are Our Words*/, 84959 /*Lost Lines of Defense*/, 84761 /*Toil and Trespass*/, 84958 /*Beasts Unbound*/, 84760 /*A Friendly Warning*/, 86332 /*Distribution of Power*/, 85730 /*Salvaging What's Left*/, 84741 /*Signs in the Sands*/, 84740 /*Bridge to Nowhere*/, 91044 /*Hunger of the Void*/, 86495 /*The Reshii Ribbon*/, 84915 /*Clearing the Dunes*/, 84910 /*The Tabiqa*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(84900, 0, 0, 0, 0, 'A few more of these and we might even have a chance. Do not relent, $n. You are capable of this and so much more.', 0), -- Like a Knife Through Aether
(84897, 0, 0, 0, 0, 'We have spent a long time preparing for this moment. I will not let it slip.', 62438), -- The Calm Before We Storm
(84883, 0, 0, 0, 0, 'Did you find the components for the Tabiqa ritual? Do they even still exist?', 62438), -- K'aresh That Was
(84879, 0, 0, 0, 0, 'The Void creeps further and further into K\'aresh every day. Dimensius\'s power grows ever stronger.', 62438), -- Restoring Hope
(84869, 0, 0, 0, 0, 'Dimensius\'s power grows and the Wastelanders are feeling the pinch. Let us ease the pressure for them a bit.', 62438), -- Hunting on Glass
(84867, 0, 0, 0, 0, 'I will do what my oaths dictate, but I am not convinced that your plan is the way to go.', 62438), -- Stalking Stalkers
(84865, 0, 1, 0, 0, 'Taking out these cannons will force the Shadowguard\'s retreat. I would not listen to Xal\'atath\'s ideas on ethics of command, though.', 62438), -- Divide and Conquer
(84864, 0, 0, 0, 0, 'Now the Shadowguard will have to retreat.', 62438), -- Her Dark Side
(84863, 0, 1, 0, 0, 'The Shadowguard are still attacking. Did you decimate their numbers yet?', 62438), -- Counter Measures
(84862, 0, 1, 0, 0, 'Have you placed the crystals I gave you? Ve\'nari won\'t give up her ribbon until her dome is secure.', 62438), -- Void Alliance
(84861, 0, 1, 0, 0, 'Did you get them all? Or are there still Shadowguard hiding around the perimeter, damaging my dome?', 62438), -- This Is Our Dome!
(84860, 0, 1, 0, 0, 'Are all the consoles operational? No? Go switch them on!', 62438), -- Eco-Stabilizing
(84859, 1, 1, 0, 0, 'I hire the best. I am sure Om\'nittar and Om\'door have the information I need.', 62438), -- Damage Report 101
(84858, 1, 1, 0, 0, 'This eco-dome will fail if the environmental support system stops. We must stabilize it!', 62438), -- System Restart
(84856, 0, 1, 0, 0, 'We will need more than one Reshii Ribbon if we want to reach Dimensius with a force capable of stopping his emergence.', 62438), -- Where the Void Gathers
(85241, 0, 1, 0, 0, 'Killing him should stop the ritual. It has to.', 62438), -- A Once-Proud Priest
(85238, 0, 1, 0, 0, 'Oh, my friends. What have we done?', 62438), -- Stranger on the Steps
(85039, 0, 0, 0, 0, 'Have you completed your assignment?', 62438), -- Compromised Containment
(85037, 0, 0, 0, 0, 'What is Xal\'atath\'s game here? She had ample opportunity to trick us.', 62438), -- That's a Wrap
(84838, 0, 0, 0, 0, 'You are not welcome here, stranger.', 62438), -- Enemies of Enemies
(85032, 0, 1, 0, 0, 'There will be a day when K\'aresh is restored.', 62438), -- What Is Left of Home
(84834, 0, 0, 0, 0, 'Many denizens of the Void are voracious consumers of energy. They greedily flock to pockets of coalesced energy like moths to a flame.', 62438), -- Tempest Clefts
(84831, 0, 0, 0, 0, 'This was once a thriving eco-dome of the Trust. Our research worked toward the restoration of K\'aresh.', 62438), -- The Rhovan Infestation
(84827, 0, 0, 0, 0, 'Could Om\'bera still be somewhere within the wreckage?', 62438), -- The Shattered Dome
(86201, 0, 0, 0, 0, 'Have you cleansed the eco-dome with the flame I\'ve provided?', 62438), -- Watch me Make These Bugs Expire
(86200, 0, 1, 0, 0, 'Just place the firebud pollen into the containers on the console, and we\'ll get it refined into something we can use.', 62438), -- Give me Fire
(85018, 0, 0, 0, 0, 'Driruj is a fool! He\'s likely to burn through his wrappings with his hot-headedness. He\'ll be back.', 62438), -- Packets of Promises
(86196, 1, 1, 0, 0, 'Have you gathered enough pollen for me?', 62438), -- Give me Fuel
(86786, 0, 1, 0, 0, 'Wrap this up quickly, $c. I have more important matters to attend to.', 62438), -- The Void Hunter
(89345, 0, 1, 0, 0, 'Have you rid Untethered Space of this predator?', 62438), -- The Untethered Horror
(91314, 1, 1, 0, 0, 'Were you able to collect the Phase-Altered essence?', 62438), -- Untethered Potential
(89344, 1, 1, 0, 0, 'Fascinating, isn\'t it?', 62438), -- What Doesn't See You
(89343, 0, 1, 0, 0, 'Untethered Space is beautiful to visit, but dangerous for those that are trapped there.', 62438), -- The Untethered Void
(85003, 0, 0, 0, 0, 'How goes the various projects of the Trust?', 62438), -- Restoring Operational Efficiency
(89327, 0, 1, 0, 0, 'When you\'re ready, $n.', 62438), -- Chaos
(89326, 0, 1, 0, 0, 'Move quickly, $n. Time is of the essence.', 62438), -- Distilled Darkness
(89324, 1, 1, 0, 0, 'You\'ve proved yourself useful so far, $c. Continue to do so.', 62438), -- A Piece of Something Greater
(91093, 0, 0, 0, 0, 'I dream of a day when we K\'areshi can roam these lands freely and without fear.', 62438), -- More Than Just a Phase
(86364, 0, 0, 0, 0, 'If you\'re having a hard time finding Weathered Ethereal Crests, you can search for hidden treasures around Khaz Algar, Undermine, or K\'aresh. There\'s no shortage of those treasures!', 62438), -- Crests from the Ether
(84974, 0, 0, 0, 0, 'There are many potential uses, and therefore potential markets, for newly created void glass. If we can get this right, I should be set up comfortably in a new home by week\'s end!\n\nIf you hold the device while standing in the void surges, the energy from the motes should help create more stable fragments.', 62438), -- Shards of Hope
(84973, 0, 0, 0, 0, 'Anything can be turned into profit, if you have the right market. It\'s all about knowing your buyers and finding that which they most desire. \n\nI still think the void glass will be the most lucrative for me, but it needs to be able to hold together more solidly.', 62438), -- Of Motes and Husks
(84972, 0, 0, 0, 0, 'I am preparing to move off world before what\'s left of K\'aresh crumbles away. There are many potential uses, and therefore potential markets, for this newly created void glass. \n\nPotential equals profit, and profit means I can make a new life on a less volatile world.', 62438), -- Chipping the Void
(84967, 0, 0, 0, 0, 'Go. We will come as soon as we can.', 62438), -- The Shadowguard Shattered
(84965, 0, 0, 0, 0, 'Any of the guardians we activate should help stabilize the situation.', 62438), -- Core Contributions
(84964, 0, 0, 0, 0, 'The people are still out there, $n!', 62438), -- Heroes Among Shadow
(84963, 0, 0, 0, 0, 'Got those cores that Om\'en wanted?', 0), -- Sealing the Shadows
(84961, 0, 0, 0, 0, 'Did you place the barrier projectors? We need to slow down the invasion. Quickly!', 62438), -- Barriers to Entry
(84960, 0, 0, 0, 0, 'We need to find the hidden Shadowguard, $n.', 62438), -- The Darkness Among Us
(84762, 1, 1, 0, 0, 'What happened? Where\'s Fennad?', 62438), -- We Are Our Words
(84959, 0, 0, 0, 0, 'Have you located my barrier projectors?', 62438), -- Lost Lines of Defense
(84761, 1, 1, 0, 0, 'Hopefully they haven\'t used everything up.', 62438), -- Toil and Trespass
(84958, 0, 0, 0, 0, 'Have you finished capturing the escaped beasts?', 62438), -- Beasts Unbound
(84760, 0, 1, 0, 0, 'Hard to believe they were once priests.', 62438), -- A Friendly Warning
(86332, 0, 0, 0, 0, 'In the wastes of Merciless K\'aresh, survival is all-important. We take what we need to ensure our future.', 0), -- Distribution of Power
(85730, 0, 0, 0, 0, 'I don\'t understand the Wastelanders. I thought they were once oracles of Untamed K\'aresh. Nature worshipers. Why do they steal from our domes and prevent the Trust\'s mission?', 0), -- Salvaging What's Left
(84741, 0, 1, 0, 0, 'This can\'t be it! There must be something left.', 62438), -- Signs in the Sands
(84740, 0, 1, 0, 0, 'It\'s all so different from what I remember.', 62438), -- Bridge to Nowhere
(91044, 0, 1, 0, 0, 'I could feel the void energies roiling from here, $c. What exactly happened?', 62438), -- Hunger of the Void
(86495, 0, 1, 0, 0, 'Every moment spent debating or arguing is a moment closer to Dimensius emerging.', 62438), -- The Reshii Ribbon
(84915, 0, 1, 0, 0, 'Is it safe yet?', 62438), -- Clearing the Dunes
(84910, 0, 0, 0, 0, 'It has been too long since we were this close to K\'aresh. It is but an echo of what once was, but the memories that it brings back...', 62438); -- The Tabiqa

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5602,5598,5593,5572,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416,5605,5597,5563,5903)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5717,5715,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5669,5668,5663,5662,5661,5660,5659,5642,5641,5631,5617,5615,5614,5903)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5697,5691,5690,5684,5673,5617)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690)) OR (`UIMapId`=2369 AND `QuestLineId` IN (5953,5770,5732,5696,5672,5671,5602,5563,5526)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5900,5803,5799,5791,5782,5780,5779,5776,5772,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5678,5673,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5617,5615,5614));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(2371, 5953, 62438),
(2371, 5906, 62438),
(2371, 5900, 62438),
(2371, 5803, 62438),
(2371, 5799, 62438),
(2371, 5791, 62438),
(2371, 5782, 62438),
(2371, 5780, 62438),
(2371, 5779, 62438),
(2371, 5776, 62438),
(2371, 5772, 62438),
(2371, 5770, 62438),
(2371, 5763, 62438),
(2371, 5744, 62438),
(2371, 5742, 62438),
(2371, 5741, 62438),
(2371, 5735, 62438),
(2371, 5734, 62438),
(2371, 5733, 62438),
(2371, 5732, 62438),
(2371, 5717, 62438),
(2371, 5716, 62438),
(2371, 5715, 62438),
(2371, 5711, 62438),
(2371, 5705, 62438),
(2371, 5703, 62438),
(2371, 5699, 62438),
(2371, 5697, 62438),
(2371, 5696, 62438),
(2371, 5695, 62438),
(2371, 5694, 62438),
(2371, 5693, 62438),
(2371, 5691, 62438),
(2371, 5690, 62438),
(2371, 5686, 62438),
(2371, 5685, 62438),
(2371, 5684, 62438),
(2371, 5683, 62438),
(2371, 5673, 62438),
(2371, 5672, 62438),
(2371, 5671, 62438),
(2371, 5670, 62438),
(2371, 5669, 62438),
(2371, 5668, 62438),
(2371, 5666, 62438),
(2371, 5664, 62438),
(2371, 5663, 62438),
(2371, 5662, 62438),
(2371, 5661, 62438),
(2371, 5660, 62438),
(2371, 5659, 62438),
(2371, 5642, 62438),
(2371, 5641, 62438),
(2371, 5638, 62438),
(2371, 5631, 62438),
(2371, 5630, 62438),
(2371, 5627, 62438),
(2371, 5617, 62438),
(2371, 5615, 62438),
(2371, 5614, 62438),
(2371, 5609, 62438),
(2371, 5602, 62438),
(2371, 5598, 62438),
(2371, 5593, 62438),
(2371, 5572, 62438),
(2371, 5558, 62438),
(2371, 5551, 62438),
(2371, 5550, 62438),
(2371, 5544, 62438),
(2371, 5540, 62438),
(2371, 5539, 62438),
(2371, 5535, 62438),
(2371, 5534, 62438),
(2371, 5533, 62438),
(2371, 5531, 62438),
(2371, 5530, 62438),
(2371, 5529, 62438),
(2371, 5526, 62438),
(2371, 5525, 62438),
(2371, 5523, 62438),
(2371, 5521, 62438),
(2371, 5520, 62438),
(2371, 5513, 62438),
(2371, 5506, 62438),
(2371, 1416, 62438),
(2371, 5605, 62493),
(2371, 5597, 62493),
(2371, 5563, 62493),
(2248, 5953, 62438),
(2248, 5906, 62438),
(2248, 5900, 62438),
(2248, 5803, 62438),
(2248, 5799, 62438),
(2248, 5791, 62438),
(2248, 5782, 62438),
(2248, 5780, 62438),
(2248, 5779, 62438),
(2248, 5776, 62438),
(2248, 5772, 62438),
(2248, 5770, 62438),
(2248, 5763, 62438),
(2248, 5744, 62438),
(2248, 5742, 62438),
(2248, 5741, 62438),
(2248, 5735, 62438),
(2248, 5734, 62438),
(2248, 5733, 62438),
(2248, 5717, 62438),
(2248, 5715, 62438),
(2248, 5705, 62438),
(2248, 5697, 62438),
(2248, 5696, 62438),
(2248, 5694, 62438),
(2248, 5693, 62438),
(2248, 5691, 62438),
(2248, 5690, 62438),
(2248, 5686, 62438),
(2248, 5685, 62438),
(2248, 5684, 62438),
(2248, 5683, 62438),
(2248, 5678, 62438),
(2248, 5673, 62438),
(2248, 5669, 62438),
(2248, 5668, 62438),
(2248, 5663, 62438),
(2248, 5662, 62438),
(2248, 5661, 62438),
(2248, 5660, 62438),
(2248, 5659, 62438),
(2248, 5642, 62438),
(2248, 5641, 62438),
(2248, 5631, 62438),
(2248, 5617, 62438),
(2248, 5615, 62438),
(2248, 5614, 62438),
(2339, 5799, 62438),
(2339, 5697, 62438),
(2339, 5691, 62438),
(2339, 5690, 62438),
(2339, 5684, 62438),
(2339, 5673, 62438),
(2339, 5617, 62438),
(2371, 5903, 62438),
(2472, 5780, 62438),
(2472, 5703, 62438),
(2472, 5699, 62438),
(2472, 5695, 62438),
(2472, 5690, 62438),
(2248, 5903, 62438),
(2369, 5953, 62493),
(2369, 5770, 62493),
(2369, 5732, 62493),
(2369, 5696, 62493),
(2369, 5672, 62493),
(2369, 5671, 62493),
(2369, 5602, 62493),
(2369, 5563, 62493),
(2369, 5526, 62493),
(2214, 5900, 62438),
(2214, 5803, 62438),
(2214, 5799, 62438),
(2214, 5791, 62438),
(2214, 5782, 62438),
(2214, 5780, 62438),
(2214, 5779, 62438),
(2214, 5776, 62438),
(2214, 5772, 62438),
(2214, 5763, 62438),
(2214, 5744, 62438),
(2214, 5742, 62438),
(2214, 5741, 62438),
(2214, 5736, 62438),
(2214, 5734, 62438),
(2214, 5733, 62438),
(2214, 5732, 62438),
(2214, 5717, 62438),
(2214, 5716, 62438),
(2214, 5705, 62438),
(2214, 5697, 62438),
(2214, 5696, 62438),
(2214, 5695, 62438),
(2214, 5694, 62438),
(2214, 5693, 62438),
(2214, 5691, 62438),
(2214, 5690, 62438),
(2214, 5686, 62438),
(2214, 5685, 62438),
(2214, 5684, 62438),
(2214, 5678, 62438),
(2214, 5673, 62438),
(2214, 5669, 62438),
(2214, 5668, 62438),
(2214, 5666, 62438),
(2214, 5664, 62438),
(2214, 5663, 62438),
(2214, 5662, 62438),
(2214, 5661, 62438),
(2214, 5660, 62438),
(2214, 5659, 62438),
(2214, 5642, 62438),
(2214, 5641, 62438),
(2214, 5638, 62438),
(2214, 5631, 62438),
(2214, 5630, 62438),
(2214, 5617, 62438),
(2214, 5615, 62438),
(2214, 5614, 62438);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62438 WHERE (`UIMapId`=2248 AND `QuestLineId` IN (5732,5716,5711,5672,5671,5670,5666,5664,5638,5630,5627,5609,5602,5598,5593,5572,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5732,5716,5664,5630,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5711,5671,5670,5627,5609,5602,5598,5593,5572,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62493 WHERE (`UIMapId`=2339 AND `QuestLineId` IN (5732,5716,5664,5630,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5732,5716,5711,5672,5671,5670,5666,5664,5638,5630,5627,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416));

DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2371 AND `QuestId` IN (84680,84248,85962,85960,85945,85913,81692,83531,82448,83538,83048,82518,82256,82254,81620,85051,86707,86800,86178,86177,86180,85554,82778,81854,83537,82552,81656,83101,83715,84429,82258,83028,82288,86610,82580)) OR (`UIMapId`=2248 AND `QuestId` IN (84680,84248,86707,86800,85962,85960,85945,85913,81692,82448,83101,83715,82256,85051,86178,86177,86180,85554,82778,81854,83537,82552,83028,82518,82254,81620)) OR (`UIMapId`=2339 AND `QuestId` IN (82448,81854)) OR (`UIMapId`=2472 AND `QuestId` IN (86800,86707)) OR (`UIMapId`=2369 AND `QuestId` IN (85051,86707,86800,81692,82778)) OR (`UIMapId`=2214 AND `QuestId` IN (84680,84248,85962,85960,85945,85913,81692,83538,83028,82518,81656,82288,82254,81620));
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2371, 84680, 62438), -- Rock 'n Stone Revival
(2371, 84248, 62438), -- A Ritual of Runes
(2371, 85962, 62438), -- Side Gig: Unseemly Reagents
(2371, 85960, 62438), -- Side Gig: Lost in the Sauce
(2371, 85945, 62438), -- Side Gig: Blood-B-Gone
(2371, 85913, 62438), -- Side Gig: Cleanup Detail
(2371, 81692, 62438), -- The Flame Within
(2371, 83531, 62438), -- Hallowfall Fishing Derby
(2371, 82448, 62438), -- Book It to the Library
(2371, 83538, 62438), -- Excavation Liberation
(2371, 83048, 62438), -- Wayward Walkers
(2371, 82518, 62438), -- Pipe Patcher
(2371, 82256, 62438), -- Capturing the Cataract's Creatures
(2371, 82254, 62438), -- Aquacalypse
(2371, 81620, 62438), -- Recovery Job
(2371, 85051, 62493), -- Beach Comber
(2371, 86707, 62493), -- The Shadowguard Resurgence
(2371, 86800, 62493), -- Swipe 'Em
(2371, 86178, 62493), -- Side Gig: Cleanin' the Coast
(2371, 86177, 62493), -- Side Gig: The Tides Provide
(2371, 86180, 62493), -- Side Gig: Infested Waters
(2371, 85554, 62493), -- Side Gig: It's Always Sunny Side Up
(2371, 82778, 62493), -- Hallowfall Fishing Derby
(2371, 81854, 62493), -- Coreway Maintenance Request
(2371, 83537, 62493), -- Geothermal Gem Treatment
(2371, 82552, 62493), -- All Worked Up
(2371, 81656, 62493), -- Nothing to Waste
(2248, 84680, 62438), -- Rock 'n Stone Revival
(2248, 84248, 62438), -- A Ritual of Runes
(2248, 86707, 62438), -- The Shadowguard Resurgence
(2248, 86800, 62438), -- Swipe 'Em
(2248, 85962, 62438), -- Side Gig: Unseemly Reagents
(2248, 85960, 62438), -- Side Gig: Lost in the Sauce
(2248, 85945, 62438), -- Side Gig: Blood-B-Gone
(2248, 85913, 62438), -- Side Gig: Cleanup Detail
(2248, 81692, 62438), -- The Flame Within
(2248, 82448, 62438), -- Book It to the Library
(2248, 83101, 62438), -- Reaching for Resources
(2248, 83715, 62438), -- Claimed Salvage
(2248, 82256, 62438), -- Capturing the Cataract's Creatures
(2339, 82448, 62438), -- Book It to the Library
(2371, 83101, 62438), -- Reaching for Resources
(2371, 83715, 62438), -- Claimed Salvage
(2472, 86800, 62438), -- Swipe 'Em
(2371, 84429, 62438), -- Construct Containment
(2371, 82258, 62438), -- Sieging Siege Weapons
(2472, 86707, 62493), -- The Shadowguard Resurgence
(2339, 81854, 62493), -- Coreway Maintenance Request
(2369, 85051, 62493), -- Beach Comber
(2369, 86707, 62493), -- The Shadowguard Resurgence
(2369, 86800, 62493), -- Swipe 'Em
(2369, 81692, 62493), -- The Flame Within
(2369, 82778, 62493), -- Hallowfall Fishing Derby
(2248, 85051, 62493), -- Beach Comber
(2248, 86178, 62493), -- Side Gig: Cleanin' the Coast
(2248, 86177, 62493), -- Side Gig: The Tides Provide
(2248, 86180, 62493), -- Side Gig: Infested Waters
(2248, 85554, 62493), -- Side Gig: It's Always Sunny Side Up
(2248, 82778, 62493), -- Hallowfall Fishing Derby
(2248, 81854, 62493), -- Coreway Maintenance Request
(2248, 83537, 62493), -- Geothermal Gem Treatment
(2248, 82552, 62493), -- All Worked Up
(2214, 84680, 62438), -- Rock 'n Stone Revival
(2214, 84248, 62438), -- A Ritual of Runes
(2214, 85962, 62438), -- Side Gig: Unseemly Reagents
(2214, 85960, 62438), -- Side Gig: Lost in the Sauce
(2214, 85945, 62438), -- Side Gig: Blood-B-Gone
(2214, 85913, 62438), -- Side Gig: Cleanup Detail
(2214, 81692, 62438), -- The Flame Within
(2214, 83538, 62438), -- Excavation Liberation
(2214, 83028, 62438), -- Thieving Snufflers
(2214, 82518, 62438), -- Pipe Patcher
(2214, 81656, 62438), -- Nothing to Waste
(2214, 82288, 62438), -- Work Hard, Play Hard
(2214, 82254, 62438), -- Aquacalypse
(2214, 81620, 62438), -- Recovery Job
(2248, 83028, 62438), -- Thieving Snufflers
(2248, 82518, 62438), -- Pipe Patcher
(2248, 82254, 62438), -- Aquacalypse
(2248, 81620, 62438), -- Recovery Job
(2371, 83028, 62438), -- Thieving Snufflers
(2371, 82288, 62438), -- Work Hard, Play Hard
(2371, 86610, 62493), -- Nor Void of Night
(2371, 82580, 62493); -- Courier Mission: Ore Recovery
