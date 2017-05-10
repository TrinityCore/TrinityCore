DELETE FROM `quest_template` WHERE `ID` IN (44941 /*-Unknown-*/, 43938 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(44941, 2, -1, 757, 98, 7541, 0, 0, 0, 5, 1, 194000, 5, 1, 182850, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1948, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'Dances With Ravenbears (UNUSED)', 'Help the Blackfeather ravenbears perform their tribute ritual.', '<The chieftain beckons for the ravenbears to gather the tribute and gestures toward the ritual circle outside.>\n\nCaw! Caw ca-caw!\n\n<It looks like he wants you to follow.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 22995), -- -Unknown-
(43938, 2, -1, 0, 110, -406, 107, 0, 0, 1, 1, 19400, 1, 1, 0, 0, 0, 0, 81040, 0, 0, 0, 0, 1, 0, 39846144, 37748992, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 'Focusing Our Efforts', 'Complete the "Nightfall" and "Moon Guard Stronghold" storylines in Suramar, then meet Archmage Kalec in Shal''Aran.', 'The Nightfallen in Suramar were once a part of the Nightborne, but have been exiled by their former brethren and cut off from the Nightwell.$B$BI believe they could be valuable allies in our quest if you can turn them to our side. I know only that they have gone into hiding somewhere in Suramar.$B$BAfterward, seek out the Moon Guard in the northern reaches of Suramar. They, too, could be valuable allies in our cause... if they still oppose the Legion as they once did many years ago.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 22995); -- -Unknown-

UPDATE `quest_template` SET `RewardBonusMoney`=1400, `VerifiedBuild`=22995 WHERE `ID`=37799; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1400, `VerifiedBuild`=22995 WHERE `ID`=37798; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=11150, `VerifiedBuild`=22995 WHERE `ID`=37272; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2100, `VerifiedBuild`=22995 WHERE `ID`=32872; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=32809; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `VerifiedBuild`=22995 WHERE `ID`=32413; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=32005; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=32003; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=31754; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=31519; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30310; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=114000, `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=30228; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30205; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=30204; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30200; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=15, `RewardFactionValue1`=1, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=26977; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=25380; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=6, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=24879; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=14199; -- -Unknown-
UPDATE `quest_template` SET `Flags`=20488, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=0, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=13915; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=13914; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=22995 WHERE `ID`=13376; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13251; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13245; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=91500, `RewardFactionValue1`=2, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13002; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=60, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=11492; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=4500, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=11144; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=194000, `RewardBonusMoney`=182850, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=10961; -- -Unknown-
UPDATE `quest_template` SET `RewardNextQuest`=0, `Flags`=16512, `FlagsEx`=64, `RewardFactionValue1`=1, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=9639; -- -Unknown-
UPDATE `quest_template` SET `Flags`=16384, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=9520; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=9503; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18875469, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=8912; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=11000, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7871; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7630; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `VerifiedBuild`=22995 WHERE `ID`=7623; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=18000, `RewardMoneyDifficulty`=6, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=33555378, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7401; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=137150, `RewardFactionValue1`=4, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=6123; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=45700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=5637; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=4972; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=3378; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=3113; -- -Unknown-
UPDATE `quest_template` SET `Flags`=540672, `FlagsEx`=64, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=3108; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=2764; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='The harvesting of precious gems is of utmost importance to our craft, $n. Few gems are more precious than the citrine. The magical properties we imbue into our goods are amplified greatly by the presence of citrine.$B$BFor this lesson, we will fortify forty bars of mithril with four citrines. The result will be a better understanding of magical gemology and the knowledge to create ornate mithril shoulders.', `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2763; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='It is said that truesilver is stronger and more durable than mithril. Galvan does not disagree with this assessment of the minerals, but contrary to its name, truesilver is not true! Mithril is a far nobler mineral! HAH! Regardless, for this lesson you will need to find the great silver deceiver, $n.$B$BBring me forty bars of mithril and five bars of truesilver. In exchange, you will be taught the secret of ornate mithril gloves and more importantly, learn that truesilver is a liar!', `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2762; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2761; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=-1, `QuestDescription`='Listen, kid, you''re not gonna learn anything hanging around here.$B$BI know a guy who knows a guy. He hangs around the smithy in Booty Bay. If you show him this insignia, he''ll tell you all about mithril.$B$BSo whadd''ya say? Leave this kid stuff to the babies in diapers, $n -- it''s time to move on.$B$BIf you''re interested, his name''s McGavan. Show him this trinket and he''ll recognize your commitment.', `VerifiedBuild`=22995 WHERE `ID`=2757; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=85, `RewardMoneyDifficulty`=2, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=16, `VerifiedBuild`=22995 WHERE `ID`=1885; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=1389; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=607; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=170; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `AreaGroupID`=4973 WHERE `ID`=43807; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `AreaGroupID`=4973 WHERE `ID`=43807; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `StartItem`=0 WHERE `ID`=44767; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `AreaGroupID`=4973 WHERE `ID`=43807; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=1 WHERE `ID`=42903; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=1 WHERE `ID`=42901; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `StartItem`=0 WHERE `ID`=44767; -- -Unknown-
UPDATE `quest_template` SET `Flags`=37748744, `FlagsEx`=8192, `VerifiedBuild`=22995 WHERE `ID`=44734; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `AreaGroupID`=4973 WHERE `ID`=43807; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=1 WHERE `ID`=42903; -- -Unknown-
UPDATE `quest_template` SET `RewardXPMultiplier`=1 WHERE `ID`=42901; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=42193; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2250, `VerifiedBuild`=22995 WHERE `ID`=34570; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2100, `RewardFactionValue1`=6, `RewardFactionOverride1`=20000, `VerifiedBuild`=22995 WHERE `ID`=32564; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1250, `RewardFactionValue1`=5, `RewardFactionValue2`=5, `RewardFactionOverride1`=20000, `RewardFactionOverride2`=0, `VerifiedBuild`=22995 WHERE `ID`=32406; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionValue2`=5, `RewardFactionOverride1`=20000, `RewardFactionOverride2`=0, `VerifiedBuild`=22995 WHERE `ID`=32403; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=850, `Flags`=65536, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=32364; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=31762; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=31758; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=31679; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30320; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30312; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30308; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=525, `VerifiedBuild`=22995 WHERE `ID`=29229; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=220, `RewardFactionValue1`=6, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=27106; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13256; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=91500, `VerifiedBuild`=22995 WHERE `ID`=12349; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=30, `RewardFactionValue1`=8, `RewardFactionValue2`=8, `RewardFactionOverride1`=0, `RewardFactionOverride2`=0, `VerifiedBuild`=22995 WHERE `ID`=10708; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18875469, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=8912; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=8041; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=-1, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=5888; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=5887; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=18350, `RewardFactionValue1`=4, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=4822; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=18350, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18875469, `QuestDescription`='They say that Lady Jaina Proudmoore in Theramore is one of the greatest heroes the Alliance has ever had.  When I grow up, I wanna be a hero of the Alliance too!$B$BDo you know Jaina, $n?  Could you do me a favor, please?  Could you get her autograph for me?  I dunno how to ask her, and she''d probably be too busy for someone like me... but you!  You''re an adventurer just like she is!  I bet she''d give you her autograph easy!$B$BPlease?', `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=558; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=329; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=75; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=40883; -- -Unknown-
UPDATE `quest_template` SET `QuestSortID`=7503, `RewardFactionValue1`=3, `RewardFactionOverride1`=0 WHERE `ID`=44943; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=40883; -- -Unknown-
UPDATE `quest_template` SET `Flags`=37748744, `FlagsEx`=8192, `VerifiedBuild`=22995 WHERE `ID`=44734; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=43750; -- -Unknown-
UPDATE `quest_template` SET `Flags`=33554440, `VerifiedBuild`=22995 WHERE `ID`=40883; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1400, `VerifiedBuild`=22995 WHERE `ID`=37799; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1400, `VerifiedBuild`=22995 WHERE `ID`=37798; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=11150, `VerifiedBuild`=22995 WHERE `ID`=37272; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=2100, `VerifiedBuild`=22995 WHERE `ID`=32872; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=32809; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `VerifiedBuild`=22995 WHERE `ID`=32413; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=32005; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=32003; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=31754; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=3400, `VerifiedBuild`=22995 WHERE `ID`=31519; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30310; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=114000, `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=30228; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30205; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=30204; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=1700, `RewardFactionValue1`=5, `RewardFactionOverride1`=10000, `VerifiedBuild`=22995 WHERE `ID`=30200; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=15, `RewardFactionValue1`=1, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=26977; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=25380; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=6, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=24879; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=14199; -- -Unknown-
UPDATE `quest_template` SET `Flags`=20488, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=0, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=13915; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=13914; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=22995 WHERE `ID`=13376; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13251; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=180, `RewardFactionValue1`=3, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13245; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=91500, `RewardFactionValue1`=2, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=13002; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=60, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=11492; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=4500, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=11144; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=194000, `RewardBonusMoney`=182850, `RewardFactionValue1`=5, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=10961; -- -Unknown-
UPDATE `quest_template` SET `RewardNextQuest`=0, `Flags`=16512, `FlagsEx`=64, `RewardFactionValue1`=1, `RewardFactionOverride1`=0, `VerifiedBuild`=22995 WHERE `ID`=9639; -- -Unknown-
UPDATE `quest_template` SET `Flags`=16384, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=9520; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=9503; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18875469, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=8912; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=11000, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7871; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7630; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=182850, `VerifiedBuild`=22995 WHERE `ID`=7623; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=18000, `RewardMoneyDifficulty`=6, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=33555378, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=7401; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=45700, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=5637; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=4972; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=3378; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=3113; -- -Unknown-
UPDATE `quest_template` SET `Flags`=540672, `FlagsEx`=64, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=3108; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `VerifiedBuild`=22995 WHERE `ID`=2764; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='The harvesting of precious gems is of utmost importance to our craft, $n. Few gems are more precious than the citrine. The magical properties we imbue into our goods are amplified greatly by the presence of citrine.$B$BFor this lesson, we will fortify forty bars of mithril with four citrines. The result will be a better understanding of magical gemology and the knowledge to create ornate mithril shoulders.', `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2763; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestDescription`='It is said that truesilver is stronger and more durable than mithril. Galvan does not disagree with this assessment of the minerals, but contrary to its name, truesilver is not true! Mithril is a far nobler mineral! HAH! Regardless, for this lesson you will need to find the great silver deceiver, $n.$B$BBring me forty bars of mithril and five bars of truesilver. In exchange, you will be taught the secret of ornate mithril gloves and more importantly, learn that truesilver is a liar!', `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2762; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=2761; -- -Unknown-
UPDATE `quest_template` SET `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=-1, `QuestDescription`='Listen, kid, you''re not gonna learn anything hanging around here.$B$BI know a guy who knows a guy. He hangs around the smithy in Booty Bay. If you show him this insignia, he''ll tell you all about mithril.$B$BSo whadd''ya say? Leave this kid stuff to the babies in diapers, $n -- it''s time to move on.$B$BIf you''re interested, his name''s McGavan. Show him this trinket and he''ll recognize your commitment.', `VerifiedBuild`=22995 WHERE `ID`=2757; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=85, `RewardMoneyDifficulty`=2, `RewardBonusMoney`=0, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=16, `VerifiedBuild`=22995 WHERE `ID`=1885; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=1389; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=607; -- -Unknown-
UPDATE `quest_template` SET `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `QuestCompletionLog`='', `VerifiedBuild`=22995 WHERE `ID`=170; -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (287307 /*287307*/, 259361 /*259361*/, 255219 /*255219*/, 286002 /*286002*/, 286003 /*286003*/, 253505 /*253505*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(287307, 44941, 0, 0, 107502, 1, 0, 0, 0, 'Ritual Performed', 22995), -- 287307
(259361, 9503, 1, 0, 23744, 6, 0, 1, 0, '', 22995), -- 259361
(255219, 2757, 1, 0, 8663, 1, 0, 0, 0, '', 22995), -- 255219
(286002, 43938, 14, 0, 51238, 1, 2, 0, 0, '', 22995), -- 286002
(286003, 43938, 14, 1, 51240, 1, 0, 0, 0, '', 22995), -- 286003
(253505, 558, 1, 0, 18642, 1, 0, 1, 0, '', 22995); -- 253505

UPDATE `quest_objectives` SET `Amount`=10 WHERE `ID`=287303; -- 287303
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=279921; -- 279921
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=279920; -- 279920
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=276889; -- 276889
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270460; -- 270460
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270459; -- 270459
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270458; -- 270458
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=268198; -- 268198
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=267254; -- 267254
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264123; -- 264123
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264808; -- 264808
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264180; -- 264180
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264674; -- 264674
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262631; -- 262631
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253382; -- 253382
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253149; -- 253149
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252997; -- 252997
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262228; -- 262228
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262227; -- 262227
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=251676; -- 251676
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252509; -- 252509
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262536; -- 262536
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=263548; -- 263548
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259243; -- 259243
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259242; -- 259242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260662; -- 260662
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259542; -- 259542
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257516; -- 257516
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256979; -- 256979
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257176; -- 257176
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259048; -- 259048
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259311; -- 259311
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258601; -- 258601
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258600; -- 258600
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258599; -- 258599
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258784; -- 258784
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256165; -- 256165
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260101; -- 260101
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257921; -- 257921
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258226; -- 258226
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255682; -- 255682
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258672; -- 258672
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257987; -- 257987
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257418; -- 257418
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257417; -- 257417
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257273; -- 257273
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257272; -- 257272
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257480; -- 257480
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257479; -- 257479
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257905; -- 257905
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257656; -- 257656
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257655; -- 257655
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257887; -- 257887
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256838; -- 256838
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256871; -- 256871
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258716; -- 258716
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258701; -- 258701
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257711; -- 257711
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258669; -- 258669
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258668; -- 258668
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258391; -- 258391
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257724; -- 257724
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256868; -- 256868
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256867; -- 256867
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256866; -- 256866
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256865; -- 256865
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258419; -- 258419
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258667; -- 258667
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258666; -- 258666
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258428; -- 258428
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254463; -- 254463
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257133; -- 257133
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257158; -- 257158
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257157; -- 257157
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257156; -- 257156
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257155; -- 257155
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256974; -- 256974
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256716; -- 256716
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256715; -- 256715
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256874; -- 256874
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256341; -- 256341
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256542; -- 256542
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256641; -- 256641
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256728; -- 256728
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256745; -- 256745
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256873; -- 256873
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253261; -- 253261
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256664; -- 256664
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256495; -- 256495
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256383; -- 256383
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256324; -- 256324
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256068; -- 256068
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256288; -- 256288
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253138; -- 253138
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253137; -- 253137
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253136; -- 253136
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253135; -- 253135
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256200; -- 256200
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256199; -- 256199
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255881; -- 255881
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255880; -- 255880
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256077; -- 256077
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255656; -- 255656
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255780; -- 255780
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254992; -- 254992
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255970; -- 255970
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255401; -- 255401
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255759; -- 255759
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255278; -- 255278
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255109; -- 255109
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255097; -- 255097
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255130; -- 255130
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254826; -- 254826
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254799; -- 254799
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254820; -- 254820
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254829; -- 254829
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254781; -- 254781
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254566; -- 254566
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255286; -- 255286
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254959; -- 254959
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254718; -- 254718
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254437; -- 254437
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254618; -- 254618
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254817; -- 254817
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254211; -- 254211
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254752; -- 254752
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254701; -- 254701
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253906; -- 253906
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253987; -- 253987
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253908; -- 253908
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253582; -- 253582
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253823; -- 253823
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254038; -- 254038
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253708; -- 253708
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253474; -- 253474
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253349; -- 253349
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254973; -- 254973
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253368; -- 253368
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253367; -- 253367
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253366; -- 253366
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253096; -- 253096
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253247; -- 253247
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253664; -- 253664
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253663; -- 253663
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253224; -- 253224
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254762; -- 254762
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253243; -- 253243
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253242; -- 253242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253226; -- 253226
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252871; -- 252871
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252567; -- 252567
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252497; -- 252497
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252955; -- 252955
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252032; -- 252032
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257424; -- 257424
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257424; -- 257424
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257424; -- 257424
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259298; -- 259298
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258094; -- 258094
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256700; -- 256700
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255550; -- 255550
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253987; -- 253987
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253243; -- 253243
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253242; -- 253242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257424; -- 257424
UPDATE `quest_objectives` SET `Type`=0, `ObjectID`=114790, `VerifiedBuild`=22995 WHERE `ID`=287285; -- 287285
UPDATE `quest_objectives` SET `Type`=0, `ObjectID`=114790, `VerifiedBuild`=22995 WHERE `ID`=286901; -- 286901
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264144; -- 264144
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256510; -- 256510
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255813; -- 255813
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259649; -- 259649
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259648; -- 259648
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260662; -- 260662
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256206; -- 256206
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256205; -- 256205
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255721; -- 255721
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260101; -- 260101
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258672; -- 258672
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258716; -- 258716
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258419; -- 258419
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257019; -- 257019
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257013; -- 257013
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256879; -- 256879
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256878; -- 256878
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253117; -- 253117
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256242; -- 256242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256241; -- 256241
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256240; -- 256240
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255780; -- 255780
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255372; -- 255372
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255538; -- 255538
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255988; -- 255988
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255634; -- 255634
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255233; -- 255233
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254715; -- 254715
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254799; -- 254799
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254957; -- 254957
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255679; -- 255679
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253908; -- 253908
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253631; -- 253631
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253630; -- 253630
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253708; -- 253708
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253349; -- 253349
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254843; -- 254843
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253244; -- 253244
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=251899; -- 251899
UPDATE `quest_objectives` SET `Amount`=150, `VerifiedBuild`=22995 WHERE `ID`=283186; -- 283186
UPDATE `quest_objectives` SET `Type`=0, `ObjectID`=114790, `VerifiedBuild`=22995 WHERE `ID`=286901; -- 286901
UPDATE `quest_objectives` SET `Amount`=10 WHERE `ID`=287303; -- 287303
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=276889; -- 276889
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270460; -- 270460
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270459; -- 270459
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=270458; -- 270458
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=268198; -- 268198
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=267254; -- 267254
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264123; -- 264123
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264808; -- 264808
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264180; -- 264180
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=264674; -- 264674
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262631; -- 262631
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253382; -- 253382
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253149; -- 253149
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252997; -- 252997
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262228; -- 262228
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262227; -- 262227
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=251676; -- 251676
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252509; -- 252509
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=262536; -- 262536
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=263548; -- 263548
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259243; -- 259243
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259242; -- 259242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260662; -- 260662
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259542; -- 259542
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257516; -- 257516
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256979; -- 256979
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257176; -- 257176
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=259048; -- 259048
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258601; -- 258601
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258600; -- 258600
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258599; -- 258599
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256165; -- 256165
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=260101; -- 260101
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257921; -- 257921
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258226; -- 258226
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255682; -- 255682
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258672; -- 258672
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257987; -- 257987
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257418; -- 257418
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257417; -- 257417
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257273; -- 257273
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257272; -- 257272
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257480; -- 257480
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257479; -- 257479
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257905; -- 257905
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257656; -- 257656
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257655; -- 257655
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257887; -- 257887
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256838; -- 256838
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256871; -- 256871
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258716; -- 258716
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258701; -- 258701
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257711; -- 257711
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258669; -- 258669
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258668; -- 258668
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258391; -- 258391
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257724; -- 257724
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256868; -- 256868
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256867; -- 256867
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256866; -- 256866
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256865; -- 256865
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258419; -- 258419
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258667; -- 258667
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258666; -- 258666
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=258428; -- 258428
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254463; -- 254463
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257133; -- 257133
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257158; -- 257158
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257157; -- 257157
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257156; -- 257156
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=257155; -- 257155
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256974; -- 256974
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256874; -- 256874
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256341; -- 256341
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256542; -- 256542
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256641; -- 256641
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256745; -- 256745
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256873; -- 256873
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256664; -- 256664
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256495; -- 256495
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256383; -- 256383
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256324; -- 256324
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256068; -- 256068
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256288; -- 256288
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253138; -- 253138
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253137; -- 253137
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253136; -- 253136
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253135; -- 253135
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256200; -- 256200
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=256199; -- 256199
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255881; -- 255881
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255880; -- 255880
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255656; -- 255656
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255780; -- 255780
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254992; -- 254992
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255970; -- 255970
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255401; -- 255401
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255759; -- 255759
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255278; -- 255278
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255109; -- 255109
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255097; -- 255097
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255130; -- 255130
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254826; -- 254826
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254799; -- 254799
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254820; -- 254820
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254829; -- 254829
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254781; -- 254781
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254566; -- 254566
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=255286; -- 255286
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254959; -- 254959
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254718; -- 254718
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254437; -- 254437
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254618; -- 254618
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254817; -- 254817
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254211; -- 254211
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254752; -- 254752
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254701; -- 254701
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253906; -- 253906
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253987; -- 253987
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253908; -- 253908
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253582; -- 253582
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253823; -- 253823
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254038; -- 254038
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253708; -- 253708
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253474; -- 253474
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253349; -- 253349
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254973; -- 254973
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253368; -- 253368
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253367; -- 253367
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253366; -- 253366
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253096; -- 253096
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253247; -- 253247
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253664; -- 253664
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253663; -- 253663
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253224; -- 253224
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=254762; -- 254762
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253243; -- 253243
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253242; -- 253242
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=253226; -- 253226
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252871; -- 252871
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252567; -- 252567
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252497; -- 252497
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252955; -- 252955
UPDATE `quest_objectives` SET `Flags2`=1, `VerifiedBuild`=22995 WHERE `ID`=252032; -- 252032

DELETE FROM `quest_visual_effect` WHERE (`ID`=287307 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(287307, 0, 5124, 22995);
