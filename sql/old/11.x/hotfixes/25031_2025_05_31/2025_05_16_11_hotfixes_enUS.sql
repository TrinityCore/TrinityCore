-- 
DELETE FROM `broadcast_text` WHERE `VerifiedBuild`>0 AND `ID` IN (285883, 285821, 278494, 274772, 274769, 264858, 264191, 264190, 263821, 261565, 260978, 260977, 260929, 260926, 260925);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('<The post reads:\n\n\"To the brave citizens and new comers of Dornogal, the treasury is requesting aid with a handful of matters. These tasks are time sensitive. These tasks may not be for all. But these tasks will grant rewards from the depth of Dornogal\'s vaults.\"\n\nSeveral tasks are presented.>', '<The post reads:\n\n\"To the brave citizens and new comers of Dornogal, the treasury is requesting aid with a handful of matters. These tasks are time sensitive. These tasks may not be for all. But these tasks will grant rewards from the depth of Dornogal\'s vaults.\"\n\nSeveral tasks are presented.>', 285883, 0, 0, 0, 256, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822),
('Hey, whatcha need?', 'Hey, whatcha need?', 285821, 0, 0, 0, 256, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822),
('We learn much from past mistakes. Do you wish to reflect on the history of the Dark Iron clan?', '', 278494, 0, 0, 0, 256, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822),
('', 'My emissary brings you power. Take it.', 274772, 0, 0, 0, 0, 0, 4, 0, 269300, 0, 0, 0, 0, 0, 0, 60822),
('', 'A willing sacrifice has been prepared.', 274769, 0, 0, 0, 0, 0, 4, 0, 269303, 0, 0, 0, 0, 0, 0, 60822),
('', 'Another outbreak of violence. Time to stand up and shut this down.', 264858, 0, 0, 0, 0, 0, 4, 0, 250958, 0, 0, 0, 0, 0, 0, 60822),
('Thanks for your assistance! With your help, we can calm them down and guide them back to their honey-making duties.', '', 264191, 0, 0, 0, 0, 0, 4, 251946, 0, 0, 0, 0, 0, 0, 0, 60822),
('Cinderbees! Stunning yet perilous creatures. When their numbers surge, honey production halts, triggering extreme aggression instead!', '', 264190, 0, 0, 0, 0, 0, 4, 251945, 0, 0, 0, 0, 0, 0, 0, 60822),
('', 'My friend\'s almost as good at scrounging as kobold! Almost. We\'ll put scrap to good use.', 263821, 0, 0, 1, 0, 0, 4, 0, 250894, 0, 0, 0, 0, 0, 0, 60822),
('', 'New things come down rivers and sky holes. Too much! Help us out. Point out any good scrap.', 261565, 0, 0, 1, 0, 0, 4, 0, 250893, 0, 0, 0, 0, 0, 0, 60822),
('Gracefully executed, as always. I will see if this unit can be repaired. No sense in wasting a good tool, is there?', '', 260978, 0, 0, 669, 0, 0, 13, 251934, 0, 0, 0, 0, 0, 0, 0, 60822),
('These constructs once protected the isle but this one\'s programming has been damaged. It will not distinguish between friend and foe.', '', 260977, 0, 0, 669, 0, 0, 13, 251933, 0, 0, 0, 0, 0, 0, 0, 60822),
('', 'They probably hauled them away to the Hollows, collecting dust in the Magistrate\'s Office. Tssk... What a waste.', 260929, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822),
('', 'The finest silks in my store, and those Sureki wretches take them away like they own the entire Bazaar!', 260926, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822),
('', 'The silksinger chitters and grunts in apparent frustration.', 260925, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 60822);

UPDATE `broadcast_text` SET `Text1`='<Lady Ilinca glares at you.>\n\nI thought I told you not to find me.', `VerifiedBuild`=60822 WHERE `VerifiedBuild`>0 AND `ID`=200282;
UPDATE `broadcast_text` SET `VoiceOverPriorityID`=15, `VerifiedBuild`=60822 WHERE `VerifiedBuild`>0 AND `ID`=189189;
