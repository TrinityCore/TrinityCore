DELETE FROM `broadcast_text` WHERE `ID` BETWEEN 147322 AND 147331;
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmotesID`, `LanguageID`, `Flags`, `ConditionID`, `SoundEntriesID1`, `SoundEntriesID2`, `VerifiedBuild`) VALUES
(147322, 'That device you just destroyed helps stabilize the Legion\'s buildings.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55235, 0, 27404),
(147323, 'See if there are others around the fortress.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55236, 0, 27404),
(147324, '<Saurfang looks you up and down with narrowed eyes.>\n\nWhen Khadgar claimed we would be seeing demon hunters today, I laughed in his face. When he said I should hear you out, I laught louder.\n\nAnd yet, here you are.\n\nI will permit you alone to enter the Hold. You will leave your weapons and companions at the door. You will not speak until spoken to.\n\nOne false move and my axe will end you.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147325, 'You are the demon hunters who escaped the Vault of the Wardens?\n\nYou draw your very power from those who seek to destroy our world. Tell me, why should I possibly trust you?', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147326, 'We are indomitable. We are Illidari.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147327, 'Let nothing stand in your way.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147328, 'I don\'t have time for pleasantries, demon hunter.\n\nAs I told the other Illidari, I have much to contemplate.\n\nI must prepare our armies to take on the Legion, even as some of my allies cry out for vengeance against the Horde.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147329, 'The Aldrachi Warblades', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404),
(147330, '$n, is that you? Finally some good news.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58226, 0, 27404),
(147331, 'There is no such thing as "to many dead demons".', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27404);

DELETE FROM `spell` WHERE `ID`=197627;
INSERT INTO `spell` (`ID`,`Name`,`NameSubtext`,`Description`,`AuraDescription`,`VerifiedBuild`) VALUES
(197627,'Brood Swarm','','A Swarm of Spiders attacks nearby players, inflicting Shadow damage to all nearby enemies.','A Swarm of Spiders attacks nearby players, inflicting Shadow damage to all nearby enemies.', 26972);

DELETE FROM `spell_misc` WHERE `ID`=197627;
INSERT INTO `spell_misc` (`ID`,`CastingTimeIndex`,`DurationIndex`,`RangeIndex`,`SchoolMask`,`SpellIconFileDataID`,`Speed`,`ActiveIconFileDataID`,`LaunchDelay`,`DifficultyID`,`Attributes1`,`Attributes2`,`Attributes3`,`Attributes4`,`Attributes5`,`Attributes6`,`Attributes7`,`Attributes8`,`Attributes9`,`Attributes10`,`Attributes11`,`Attributes12`,`Attributes13`,`Attributes14`,`SpellID`,`VerifiedBuild`) VALUES
(197627,1,31,291,1,132091,0,0,0,0,327696,0,67108864,0,2048,-2147483648,8388608,25165824,1,0,0,0,0,0,223591,26972);

DELETE FROM `broadcast_text` WHERE `ID` BETWEEN 147332 AND 147339;
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmotesID`, `LanguageID`, `Flags`, `ConditionID`, `SoundEntriesID1`, `SoundEntriesID2`, `VerifiedBuild`) VALUES
(147332, '', 'Whenever you\'re ready.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64700, 0, 27404),
(147333, '', 'This way. Your forces await.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58265, 0, 27404),
(147334, '', 'The Fel Hammer is ours at last. Gaze upon the might of the Twinblades of the Deceiver!', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58266, 0, 27404),
(147335, '', 'The Ashtongue will fight beside you.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64714, 0, 27404),
(147336, '', 'You may call upon the Coilskar as well.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64715, 0, 27404),
(147337, '', 'Our mission is not yel complete. We are all yours to command.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64716, 0, 27404),
(147338, '', 'We will follow $n into battle, and we will strike down the Legion once and for all!', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58267, 0, 27404),
(147339, '', 'Glory to the Illidari!', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 58268, 0, 27404);

DELETE FROM `broadcast_text` WHERE `ID` BETWEEN 147340 AND 147342;
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmotesID`, `LanguageID`, `Flags`, `ConditionID`, `SoundEntriesID1`, `SoundEntriesID2`, `VerifiedBuild`) VALUES
(147340, 'Behold the Legion\'s primary gateway into Azeroth... the Tomb of Sargeras.', 'Behold the Legion\'s primary gateway into Azeroth... the Tomb of Sargeras.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64708, 0, 26972),
(147341, '', 'The situation is more dire than we knew. The demons have already infested the surrounding isles.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64709, 0, 26972),
(147342, '', 'We must act now, or I fear the situation will become... unsalvageable.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64710, 0, 26972);

DELETE FROM `conversation_line` WHERE `ID` BETWEEN 13028 AND 13030;
INSERT INTO `conversation_line` (`ID`, `BroadcastTextID`, `SpellVisualKitID`, `AdditionalDuration`, `NextConversationLineID`, `AnimKitID`, `SpeechType`, `StartAnimation`, `EndAnimation`, `VerifiedBuild`) VALUES
(13028, 147340, 0, 500, 13029, 0, 0, 60, 60, 26972),
(13029, 147341, 0, 500, 13030, 0, 0, 60, 60, 26972),
(13030, 147342, 0, 500, 0, 0, 0, 60, 60, 26972);
DELETE FROM `conversation_line` WHERE `ID` BETWEEN 13019 AND 13020;
INSERT INTO `conversation_line` (`ID`, `BroadcastTextID`, `SpellVisualKitID`, `AdditionalDuration`, `NextConversationLineID`, `AnimKitID`, `SpeechType`, `StartAnimation`, `EndAnimation`, `VerifiedBuild`) VALUES
(13019, 147322, 0, 0, 13020, 0, 0, 60, 60, 26972),
(13020, 147323, 0, 500, 0, 0, 0, 60, 60, 26972);