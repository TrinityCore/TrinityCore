
/*
		VoidElf Area Beta
		clean design for Ashamane
*/

DELETE FROM `broadcast_text` WHERE `ID` IN (146517, 146098, 146099, 147276, 147272, 145895, 143583, 143589, 143586, 143585, 143587, 146516, 146362, 146090, 12528, 145898, 145897, 146920, 145896, 145890, 145892, 146148, 146006, 147271, 143615, 143203, 143205, 143206, 143204, 145893, 146231);
INSERT INTO broadcast_text (ID, Text, Text1, EmoteID1, EmoteID2, EmoteID3, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmotesID, LanguageID, Flags, ConditionID, SoundEntriesID1, SoundEntriesID2, VerifiedBuild) VALUES
(143583, 'Welcome, friend $p. I am King Anduin Wrynn. As a new member of the Alliance, I wished to greet you personally.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94909, 0, 26972),
(143589, 'The void elves may be a recent addition to our ranks, but Alleria Windrunner is one of our greatest heroes. Under her tutelage, the powers you wield will aid our cause.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94911, 0, 26972),
(143586, 'I look forward to hearing of your progress. Something tells me we will speak again soon.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94913, 0, 26972),
(143585, 'These are troubled times for Azeroth. In the days to come, you will face many trials... fight many foes. Know that you are never alone against the darkness, for the Alliance stands with you.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94912, 0, 26972),
(143587, 'Safe travels, $p. Though you walk among the shadows, you are a beacon of hope to us all.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94915, 0, 26972),
(146516, 'The void energy released when the ethereals attacked left the other islands unstable. No one is allowed beyond this point.', 'The void energy released when the ethereals attacked left the other islands unstable. No one is allowed beyond this point.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146362, 'Remain in control of your thoughts. The void cannot sway that which is immutable.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146090, 'Pristine void energy is soaked into this space... Magnificent.', 'Pristine void energy is soaked into this space... Magnificent.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(12528, 'I offer what shelter I can in our shattered lands.', 'I offer what shelter I can in our shattered lands.', 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 26972),
(145898, 'A path long denied to us is open at last.', 'A path long denied to us is open at last.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(145897, 'We need no longer fear exile for the pursuit of knowledge.', 'We need no longer fear exile for the pursuit of knowledge.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146920, 'This is a very old place. Broken by rage, yet sculpted by the threads of fate. \n\nThere is much to be learned here. I believe I might linger a while.\n\nBe seeing you.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(145896, 'Fascinating.\n\nI sensed that change was destined to find Alleria Windrunner, but I did not anticipate that her kin would undergo a similar transformation.\n\nThe implications are many. These events have given me much to ponder.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(145890, 'We''re a bit busy right now, as you can see.', 'We''re a bit busy right now, as you can see.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(145892, '<The elf''s concentration wavers momentarily and he gives you a withering look.>', '<The elf''s concentration wavers momentarily and she gives you a withering look.>', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146148, 'Maintain your focus.', 'Maintain your focus.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146006, 'Be wary of unstable void rifts and their spawn. This place is not entirely safe.', 'Be wary of unstable void rifts and their spawn. This place is not entirely safe.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(147271, '', 'Remember, control demands sacrifice. Power never comes without a price. You risk losing those closest to you in order to save them.\n\nThis is the bargain we have made.\n\n<Alleria looks away.>', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(143615, 'Together, we will prove them wrong.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94644, 0, 26972),
(143203, '', 'Some will tell you that the Light is the only path. The one weapon that can stop the enemies of Azeroth.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 94933, 26972),
(143205, 'There will be those who doubt you. Who question your resolve, your ability to harness powers that have caused the downfall of weaker wills.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94643, 0, 26972),
(143206, '', 'Use the lessons I have taught you to maintain control. Become a weapon for the Alliance... even as you skirt the edge of darkness.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 94935, 26972),
(143204, '', 'But we see alternatives. Many roads--many possibilities--that are open to us.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 94934, 26972),
(145893, 'With Alleria''s teaching, we can avoid the fate suffered by those on Mac''Aree.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(147276, 'Locus-Walker is an intriguing fellow.\n\nAlleria seems to trust him... to a point.\n\nI think we can learn much from him, so long as we remain wary of his true intentions.', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146231, 'Although broken and scattered, this rift holds many secrets. It will teach us much about the nature of the shadows.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(145895, '', 'The voices never stop. They push, they bully, they plead. They will not relent, not even for a moment.\n\nBut you are stronger than the voices. You can glean their secrets and draw upon their strength.', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(147272, '', 'Studying this rift has value, but we cannot neglect our duty.\n\nAzeroth must be defended. Our place is out there, fighting for our world.\n\nThe power that flows through us is a weapon. And weapons must be wielded.', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146517, 'The last people who ventured beyond this space were consumed by the shadows.', 'The last people who ventured beyond this space were consumed by the shadows.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146098, 'The Voidstorm is growing. It might even consume the big island entirely.', 'The Voidstorm is growing. It might even consume the big island entirely.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(146099, 'Unchecked void energies ravage the other islands. It remains too dangerous to navigate.', 'Unchecked void energies ravage the other islands. It remains too dangerous to navigate.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972);
