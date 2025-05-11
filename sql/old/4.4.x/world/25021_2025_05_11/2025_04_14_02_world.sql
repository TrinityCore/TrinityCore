DELETE FROM `quest_offer_reward` WHERE `ID` IN (26915 /*The Deepest Cut*/, 26918 /*The Power of the Light*/, 26913 /*Charging into Battle*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(26915, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'ve caught on quickly, $N, and a quick mind will serve you well. Return to me as you grow in power and I will show you new techniques.', 60192), -- The Deepest Cut
(26918, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'re a quick learner, $N. Return to me as you grow stronger and I\'ll teach you more about using the Light to vanquish your enemies and strengthen your allies.', 60192), -- The Power of the Light
(26913, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'re a quick learner, $N. Return to me as you grow stronger and I\'ll show you other combat techniques.', 60192); -- Charging into Battle

UPDATE `quest_offer_reward` SET `VerifiedBuild`=60192 WHERE `ID` IN (28822, 28796, 28812, 28788, 28818, 28792, 28808, 28784, 28820, 28794, 28810, 28786, 26919, 3103, 28771, 28763, 28821, 28811, 28795, 28787, 28817, 28791, 28806, 28780, 26917, 26910, 28759, 28767, 28819, 28793, 28809, 28785, 26390, 26389, 26391, 28823, 28813, 28797, 28789, 28774, 28766);
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=26914; -- Immolation
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=60192 WHERE `ID`=3105; -- Tainted Letter
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N. You\'ve turned out to be quite an asset to this garrison. It\'s time for you to train!', `VerifiedBuild`=60192 WHERE `ID` IN (28773, 28769, 28772, 28770); -- Lions for Lambs
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve bought us a little time, $N, but we\'ve got even bigger problems to deal with now.', `VerifiedBuild`=60192 WHERE `ID` IN (28765, 28757, 28764, 28762); -- Beating Them Back!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=26916; -- Mastering the Arcane
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=60192 WHERE `ID`=3104; -- Glyphic Letter
UPDATE `quest_offer_reward` SET `RewardText`='You\'re gonna find a number of outfits that covet our skills, $N. Adventurers, SI:7... heck, even the disorganized rabble wouldn\'t mind a spy or two inside Stormwind. But you remember this: You\'re your own $gman:woman;. Don\'t let nobody bully you into doing something you don\'t wanna do! Besides, we hold all the cards... at least, we do before the game\'s done. Know what I mean?$B$BAnyway, just wanted to introduce myself and let you know that I\'m here if you need any training. Come by anytime.', `VerifiedBuild`=60192 WHERE `ID`=3102; -- Encrypted Letter
UPDATE `quest_offer_reward` SET `RewardText`='In the meantime, you should know one or two other things. You are a symbol to many here in this land--act accordingly. The Holy Light shines within you, and it will be obvious to both your allies and your enemies.$B$BAlso, as you gain in wisdom and power, you will need to train to learn new abilities. That\'s where I come in. When you feel you\'ve gained some experience here in Northshire, come back to me and I will teach you what I feel you are ready to learn. Good luck... $c!', `VerifiedBuild`=60192 WHERE `ID`=3101; -- Consecrated Letter
UPDATE `quest_offer_reward` SET `RewardText`='Get yourself squared away, learn the layout of the land, and come back to me whenever you need training. I\'ll be here night or day.$B$BThe Knights of the Silver Hand have done well in making this place fairly safe, but as you meet the other citizens, I think you\'ll find they all have problems they could use some help with--help a warrior can give them. Good luck.', `VerifiedBuild`=60192 WHERE `ID`=3100; -- Simple Letter

DELETE FROM `quest_details` WHERE `ID` IN (26916 /*Mastering the Arcane*/, 26915 /*The Deepest Cut*/, 26918 /*The Power of the Light*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26916, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Mastering the Arcane
(26915, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- The Deepest Cut
(26918, 1, 1, 0, 0, 0, 0, 0, 0, 60192); -- The Power of the Light

UPDATE `quest_details` SET `VerifiedBuild`=60192 WHERE `ID` IN (26391, 26389, 28822, 28812, 28796, 28788, 26914, 3105, 28773, 28765, 28808, 28792, 28784, 3104, 28769, 28757, 28820, 28810, 28794, 28786, 26919, 3103, 28771, 28763, 28811, 28795, 28787, 3102, 28772, 28764, 28817, 28806, 28791, 28780, 26917, 26910, 28759, 28767, 28809, 28793, 28785, 3101, 28770, 28762, 54, 26390, 28823, 28813, 28797, 28789, 26913, 3100, 28774, 28766);
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=60192 WHERE `ID`=28818; -- The Rear is Clear
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=60192 WHERE `ID`=28821; -- The Rear is Clear
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=60192 WHERE `ID`=28819; -- The Rear is Clear

DELETE FROM `quest_request_items` WHERE `ID` IN (26918 /*The Power of the Light*/, 26916 /*Mastering the Arcane*/, 26915 /*The Deepest Cut*/, 26914 /*Immolation*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26918, 0, 6, 0, 0, 'Well, did you give it a try?', 60192), -- The Power of the Light
(26916, 0, 6, 0, 0, 'Well, did you give it a try?', 60192), -- Mastering the Arcane
(26915, 0, 6, 0, 0, 'Well, did you give it a try?', 60192), -- The Deepest Cut
(26914, 0, 6, 0, 0, 'Well, did you give it a try?', 60192); -- Immolation

UPDATE `quest_request_items` SET `CompletionText`='Finally! We meet face to face, brother to $gbrother:sister;. I welcome you to Northshire. This will be your home for a short time while you learn the ins and outs of how things are done, but know that Stormwind is not far off, and sooner or later, your path will take you there. But until then, be patient... Knight of the Silver Hand.' WHERE `ID`=3101;
UPDATE `quest_request_items` SET `VerifiedBuild`=60192 WHERE `ID` IN (28813, 28812, 28811, 28810, 28809, 28808, 28806, 28797, 28796, 28795, 26391, 28794, 28793, 26390, 26389, 28792, 28791, 26919, 26917, 26913, 28774, 28773, 28772, 28771, 28770, 28769, 28767, 28763, 28759);
UPDATE `quest_request_items` SET `CompletionText`='Have you beaten back the Blackrock battle worgs?', `VerifiedBuild`=60192 WHERE `ID` IN (28765, 28764, 28762, 28757); -- Beating Them Back!

DELETE FROM `creature_queststarter` WHERE (`id`=198 AND `quest` IN (28784,26916)) OR (`id`=197 AND `quest` IN (3104,3102,3101)) OR (`id`=915 AND `quest` IN (28787,26915)) OR (`id`=925 AND `quest` IN (28785,26918));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(198, 28784, 60192), -- Join the Battle! offered by Khelden Bremen
(198, 26916, 60192), -- Mastering the Arcane offered by Khelden Bremen
(197, 3104, 60192), -- Glyphic Letter offered by Marshal McBride
(915, 28787, 60192), -- Join the Battle! offered by Jorik Kerridan
(915, 26915, 60192), -- The Deepest Cut offered by Jorik Kerridan
(197, 3102, 60192), -- Encrypted Letter offered by Marshal McBride
(925, 28785, 60192), -- Join the Battle! offered by Brother Sammuel
(925, 26918, 60192), -- The Power of the Light offered by Brother Sammuel
(197, 3101, 60192); -- Consecrated Letter offered by Marshal McBride

UPDATE `creature_queststarter` SET `VerifiedBuild`=60192 WHERE (`id`=9296 AND `quest`=26391) OR (`id`=197 AND `quest` IN (26389,3105,28773,28765,28769,28757,3103,28771,28763,28772,28764,26910,28759,28767,28770,28762,54,26390,3100,28774,28766)) OR (`id`=823 AND `quest` IN (28822,28796,28818,28792,28820,28794,28821,28795,28817,28791,28819,28793,28823,28797)) OR (`id`=951 AND `quest` IN (28812,28808,28810,28811,28806,28809,28813)) OR (`id`=459 AND `quest` IN (28788,26914)) OR (`id`=375 AND `quest` IN (28786,26919)) OR (`id`=43278 AND `quest` IN (28780,26917)) OR (`id`=911 AND `quest` IN (28789,26913));

DELETE FROM `creature_questender` WHERE (`id`=459 AND `quest`=26914) OR (`id`=198 AND `quest` IN (26916,3104)) OR (`id`=915 AND `quest` IN (26915,3102)) OR (`id`=925 AND `quest` IN (26918,3101));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(459, 26914, 60192), -- Immolation ended by Drusilla La Salle
(198, 26916, 60192), -- Mastering the Arcane ended by Khelden Bremen
(198, 3104, 60192), -- Glyphic Letter ended by Khelden Bremen
(915, 26915, 60192), -- The Deepest Cut ended by Jorik Kerridan
(915, 3102, 60192), -- Encrypted Letter ended by Jorik Kerridan
(925, 26918, 60192), -- The Power of the Light ended by Brother Sammuel
(925, 3101, 60192); -- Consecrated Letter ended by Brother Sammuel

UPDATE `creature_questender` SET `VerifiedBuild`=60192 WHERE (`id`=9296 AND `quest`=26391) OR (`id`=197 AND `quest` IN (26389,28822,28773,28765,28818,28769,28757,28820,28771,28763,28821,28772,28764,28817,28759,28767,28819,28770,28762,26390,28823,28774,28766)) OR (`id`=823 AND `quest` IN (28796,28788,28792,28784,28794,28786,28795,28787,28791,28780,28793,28785,28797,28789)) OR (`id`=951 AND `quest` IN (28812,28808,28810,28811,28806,28809,28813)) OR (`id`=459 AND `quest`=3105) OR (`id`=375 AND `quest` IN (26919,3103)) OR (`id`=43278 AND `quest` IN (26917,26910)) OR (`id`=911 AND `quest` IN (26913,3100));
