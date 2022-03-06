-- 
DELETE FROM `broadcast_text` WHERE `ID` IN (208083, 205358, 197340, 197339, 197697, 197696);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('Good luck, $p. I must say that we are quite the egg-hiding experts now!', '', 208083, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134),
('It seems you have yet to bind yourself to a Covenant.  I can bind you to one of the Covenants temporarily, for a price.  Negotiated at a later date of course.', 'It seems you have yet to bind yourself to a Covenant.  I can bind you to one of the Covenants temporarily, for a price.  Negotiated at a later date of course.', 205358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38556),
('', 'We\'ll relocate the cocoons to the groves that need them. Thank you for restoring the balance.', 197340, 0, 0, 0, 0, 0, 0, 0, 162902, 0, 0, 0, 0, 0, 0, 38134),
('', 'The moth cocoons in Shimmerbough are growing out of control! Can you help collect them from the treetops?', 197339, 0, 0, 0, 0, 0, 0, 0, 162901, 0, 0, 0, 0, 0, 0, 38134),
('', 'Today, you have proven that we will not give in to doubt. Bastion will never surrender!', 197697, 0, 0, 1, 0, 0, 0, 0, 164329, 0, 0, 0, 0, 0, 0, 38134),
('', 'The forsworn have fortified this area with their most adept warriors. Strike them down, courage be with you!', 197696, 0, 0, 1, 0, 0, 0, 0, 164328, 0, 0, 0, 0, 0, 0, 38134);
