-- 
DELETE FROM `broadcast_text` WHERE `ID` IN (208597, 208607, 205358, 208091, 197697, 197696, 197340, 197339, 211381, 211382);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('I\'ve been bubbling up quite a collection of concoctions to assist you, Maw Walker.', '', 208597, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 40725),
('I don\'t know you, but we can still be friends.', '', 208607, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 40725),
('It seems you have yet to bind yourself to a Covenant.  I can bind you to one of the Covenants temporarily, for a price.  Negotiated at a later date of course.', 'It seems you have yet to bind yourself to a Covenant.  I can bind you to one of the Covenants temporarily, for a price.  Negotiated at a later date of course.', 205358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39653),
('Perfect! With those parts and Heirmir\'s Runes we have been able to create not just a Centurion, but a suit of armor capable of scaling the walls of the fortress!', '', 208091, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39335),
('', 'Today, you have proven that we will not give in to doubt. Bastion will never surrender!', 197697, 0, 0, 1, 0, 0, 0, 0, 164329, 0, 0, 0, 0, 0, 0, 40443),
('', 'The forsworn have fortified this area with their most adept warriors. Strike them down, courage be with you!', 197696, 0, 0, 1, 0, 0, 0, 0, 164328, 0, 0, 0, 0, 0, 0, 40443),
('', 'We\'ll relocate the cocoons to the groves that need them. Thank you for restoring the balance.', 197340, 0, 0, 0, 0, 0, 0, 0, 162902, 0, 0, 0, 0, 0, 0, 40000),
('', 'The moth cocoons in Shimmerbough are growing out of control! Can you help collect them from the treetops?', 197339, 0, 0, 0, 0, 0, 0, 0, 162901, 0, 0, 0, 0, 0, 0, 40000),
('', 'You are a welcome sight in these uncouth lands, Tubbins and Gubbins.', 211381, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39289),
('', 'Now, if you will excuse me, I must go thank Theotar in person.', 211382, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39289);
