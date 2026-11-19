--
DELETE FROM `quest_offer_reward` WHERE `ID`=63447;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(63447, 273, 4, 0, 0, 0, 0, 0, 0, 'I think you now understand the power of the Light. The Light giveth hope, $g brother:sister; and the Light taketh from the darkness! BLESSED BE THE LIGHT!', 53441); -- Fear No Evil

UPDATE `quest_offer_reward` SET `VerifiedBuild`=53441 WHERE `ID` IN (29083, 29081, 29082, 29080, 29078, 31145, 31144, 31143, 31140, 31139, 28819, 28793, 28809, 28785, 28770, 28762, 28822, 28796, 28812, 28788, 28773, 28765, 28820, 28794, 28810, 28786, 28771, 28763, 28821, 28795, 28811, 28787, 28772, 28764, 28818, 28792, 28808, 28784, 28769, 28757, 28817, 28791, 28806, 28780, 28759, 28767, 37112, 26389, 26391, 28823, 28797, 28813, 28789, 28774, 28766);
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $n. You\'ve turned out to be quite an asset to this garrison.$B$BFeel free to speak with any of our trainers within and around the abbey if you need to sharpen any of your combat skills.$B$BWhen you\'re ready, I have another assignment for you...', `VerifiedBuild`=53441 WHERE `ID`=29079; -- Lions for Lambs
UPDATE `quest_offer_reward` SET `RewardText`='Well, it says here that you\'ve been awarded Acting Deputy Status with the Stormwind Marshals. Congratulations.\n\nAnd good luck. Keeping Elwynn safe is no picnic... what with most the army busy doing who knows what for who knows which noble!\n\nIt\'s hard to keep track of politics in these dark days...', `VerifiedBuild`=53441 WHERE `ID`=54; -- Report to Goldshire
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='With Kurtok slain, we are safe once again from the orcish hordes. I will send peasants to the pass in an attempt to seal the passage so that no more orcs may come through into our territory.$B$BYou have the thanks of Stormwind and of the Alliance, hero!', `VerifiedBuild`=53441 WHERE `ID`=26390; -- Ending the Invasion!

DELETE FROM `quest_details` WHERE `ID` IN (26389 /*Blackrock Invasion*/, 29083 /*The Rear is Clear*/, 29082 /*Fear No Evil*/, 29081 /*They Sent Assassins*/, 29080 /*Join the Battle!*/, 29079 /*Lions for Lambs*/, 29078 /*Beating Them Back!*/, 31145 /*The Rear is Clear*/, 63447 /*Fear No Evil*/, 31144 /*They Sent Assassins*/, 31143 /*Join the Battle!*/, 31140 /*Lions for Lambs*/, 31139 /*Beating Them Back!*/, 28819 /*The Rear is Clear*/, 28809 /*Fear No Evil*/, 28793 /*They Sent Assassins*/, 28785 /*Join the Battle!*/, 28770 /*Lions for Lambs*/, 28762 /*Beating Them Back!*/, 28822 /*The Rear is Clear*/, 28812 /*Fear No Evil*/, 28796 /*They Sent Assassins*/, 28788 /*Join the Battle!*/, 28773 /*Lions for Lambs*/, 28765 /*Beating Them Back!*/, 28820 /*The Rear is Clear*/, 28810 /*Fear No Evil*/, 28821 /*The Rear is Clear*/, 28811 /*Fear No Evil*/, 28795 /*They Sent Assassins*/, 28787 /*Join the Battle!*/, 28772 /*Lions for Lambs*/, 28818 /*The Rear is Clear*/, 26391 /*Extinguishing Hope*/, 28817 /*The Rear is Clear*/, 28806 /*Fear No Evil*/, 28791 /*They Sent Assassins*/, 28780 /*Join the Battle!*/, 28759 /*Lions for Lambs*/, 28767 /*Beating Them Back!*/, 37112 /*Rest and Relaxation*/, 26390 /*Ending the Invasion!*/, 28823 /*The Rear is Clear*/, 28813 /*Fear No Evil*/, 28797 /*They Sent Assassins*/, 28789 /*Join the Battle!*/, 28774 /*Lions for Lambs*/, 28766 /*Beating Them Back!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26389, 1, 1, 1, 0, 0, 0, 0, 0, 53441), -- Blackrock Invasion
(29083, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(29082, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(29081, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(29080, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(29079, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(29078, 6, 2, 1, 5, 0, 0, 0, 0, 53441), -- Beating Them Back!
(31145, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(63447, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(31144, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(31143, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(31140, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(31139, 6, 2, 1, 5, 0, 0, 0, 0, 53441), -- Beating Them Back!
(28819, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28809, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28793, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(28785, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(28770, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(28762, 6, 2, 1, 5, 0, 0, 0, 0, 53441), -- Beating Them Back!
(28822, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28812, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28796, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(28788, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(28773, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(28765, 6, 2, 1, 5, 0, 0, 0, 0, 53441), -- Beating Them Back!
(28820, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28810, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28821, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28811, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28795, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(28787, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(28772, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(28818, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(26391, 1, 1, 20, 0, 0, 0, 0, 0, 53441), -- Extinguishing Hope
(28817, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28806, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28791, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(28780, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(28759, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(28767, 6, 2, 1, 5, 0, 0, 0, 0, 53441), -- Beating Them Back!
(37112, 1, 1, 0, 0, 0, 0, 0, 0, 53441), -- Rest and Relaxation
(26390, 1, 1, 0, 0, 0, 0, 0, 0, 53441), -- Ending the Invasion!
(28823, 273, 0, 0, 0, 0, 0, 0, 0, 53441), -- The Rear is Clear
(28813, 6, 5, 5, 20, 0, 0, 0, 0, 53441), -- Fear No Evil
(28797, 0, 0, 0, 0, 0, 0, 0, 0, 53441), -- They Sent Assassins
(28789, 1, 1, 1, 1, 0, 0, 0, 0, 53441), -- Join the Battle!
(28774, 274, 1, 25, 5, 0, 0, 0, 0, 53441), -- Lions for Lambs
(28766, 6, 2, 1, 5, 0, 0, 0, 0, 53441); -- Beating Them Back!

UPDATE `quest_details` SET `VerifiedBuild`=53441 WHERE `ID` IN (28794, 28786, 28771, 28763, 28764, 28808, 28792, 28784, 28769, 28757, 54);

DELETE FROM `quest_request_items` WHERE `ID` IN (63447 /*Fear No Evil*/, 26391 /*Extinguishing Hope*/, 26390 /*Ending the Invasion!*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(63447, 0, 5, 0, 0, 'Rescue our soldiers!', 53441), -- Fear No Evil
(26391, 0, 6, 0, 0, 'Have you put out the fires?', 53441), -- Extinguishing Hope
(26390, 0, 6, 0, 0, 'Have you found Kurtok?', 53441); -- Ending the Invasion!

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=5, `CompletionText`='Rescue our soldiers!', `VerifiedBuild`=53441 WHERE `ID` IN (28809, 28806, 29082, 28813, 28812, 28811, 28810); -- Fear No Evil
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=53441 WHERE `ID`=26389; -- Blackrock Invasion
UPDATE `quest_request_items` SET `CompletionText`='Kill the goblin assassins!', `VerifiedBuild`=53441 WHERE `ID` IN (31144, 28797, 28796, 28795, 28794, 28793, 28792, 28791, 29081); -- They Sent Assassins
UPDATE `quest_request_items` SET `CompletionText`='You have word from McBride? Northshire is a garden compared to Elwynn Forest, but I wonder what Marshal McBride has to report.\n\nHere, let me have his papers...' WHERE `ID`=54;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=5, `VerifiedBuild`=53441 WHERE `ID` IN (31140, 28774, 28773, 28772, 28771, 28770, 28769, 28759, 29079); -- Lions for Lambs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=53441 WHERE `ID` IN (31139, 28767, 28766, 28765, 28764, 28763, 28762, 28757, 29078); -- Beating Them Back!

DELETE FROM `creature_queststarter` WHERE (`id`=951 AND `quest`=63447) OR (`id`=6774 AND `quest`=37112);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(951, 63447, 53441), -- Fear No Evil offered by Brother Paxton
(6774, 37112, 53441); -- Rest and Relaxation offered by Falkhaan Isenstrider

UPDATE `creature_queststarter` SET `VerifiedBuild`=53441 WHERE (`id`=197 AND `quest` IN (26389,29080,29079,29078,31143,31140,31139,28785,28770,28762,28788,28773,28765,28786,28771,28763,28787,28772,28764,28784,28769,28757,28780,28759,28767,54,26390,28789,28774,28766)) OR (`id`=823 AND `quest` IN (29083,29081,31145,31144,28819,28793,28822,28796,28820,28794,28821,28795,28818,28792,28817,28791,28823,28797)) OR (`id`=951 AND `quest` IN (29082,28809,28812,28810,28811,28808,28806,28813)) OR (`id`=9296 AND `quest`=26391);

DELETE FROM `creature_questender` WHERE (`id`=951 AND `quest`=63447);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(951, 63447, 53441); -- Fear No Evil ended by Brother Paxton

UPDATE `creature_questender` SET `VerifiedBuild`=53441 WHERE (`id`=197 AND `quest` IN (29083,29079,29078,31145,31140,31139,28819,28770,28762,28822,28773,28765,26389,28820,28771,28763,28821,28772,28764,28818,28769,28757,28817,28759,28767,26390,28823,28774,28766)) OR (`id`=823 AND `quest` IN (29081,29080,31144,31143,28793,28785,28796,28788,28794,28786,28795,28787,28792,28784,28791,28780,28797,28789)) OR (`id`=951 AND `quest` IN (29082,28809,28812,28810,28811,28808,28806,28813)) OR (`id`=9296 AND `quest`=26391) OR (`id`=295 AND `quest`=37112) OR (`id`=240 AND `quest`=54);
