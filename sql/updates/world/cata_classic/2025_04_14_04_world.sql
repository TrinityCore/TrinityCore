DELETE FROM `quest_offer_reward` WHERE `ID` IN (26904 /*Harnessing the Flames*/, 24526 /*Filling Up the Spellbook*/, 24496 /*Arcane Rune*/, 24527 /*Your Path Begins Here*/, 24494 /*Empowered Rune*/, 24533 /*Words of Power*/, 24528 /*The Power of the Light*/, 24531 /*Getting Battle-Ready*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(26904, 0, 0, 0, 0, 0, 0, 0, 0, 'As you continue to gain power, return to me and I will teach you new spells and techniques.', 60192), -- Harnessing the Flames
(24526, 1, 0, 0, 0, 0, 0, 0, 0, 'There we go!  One spell down, many many more to go.  Come back to me after you\'ve had some experience casting this spell, and I\'ll show you some more tricks.', 60192), -- Filling Up the Spellbook
(24496, 1, 1, 0, 0, 0, 0, 0, 0, 'The power of the arcane is everywhere, $N.  Only some of us have the ability to see it, and fewer still possess the ability to master it.$b$bYou are one of those few.', 60192), -- Arcane Rune
(24527, 1, 0, 0, 0, 0, 0, 0, 0, 'This has been but one of many footfalls on the long path of the shaman.  Come back to me after you\'ve had some experience in the field, and I will help guide you on your next step.', 60192), -- Your Path Begins Here
(24494, 1, 1, 0, 0, 0, 0, 0, 0, 'These are dark days, friend.  Look around you... even here in remote Coldridge, the spirits are rebelling.  The land is crying out for help.  Yet still, even in times such as these, the spirits will always turn an ear to those who ask for their assistance.', 60192), -- Empowered Rune
(24533, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $N.  You\'ll make a fine priest in due time.$b$bReturn to me after you\'ve proven yourself a bit more, and I\'ll reward you by teaching you another spell or two.', 60192), -- Words of Power
(24528, 1, 0, 0, 0, 0, 0, 0, 0, 'There, ya did it.  The Light favors quick learners like you.  Come back to me after you\'ve spent some time using what I\'ve taught ya, and I\'ll show ya something new.', 60192), -- The Power of the Light
(24531, 1, 0, 0, 0, 0, 0, 0, 0, 'Now we\'re getting somewhere.  You\'ve got $g quite a manly bellow, sir!:an excellent pair!  ...er, of lungs, that is.;$b$bCome back to me in a bit, and I\'ll teach you something else.', 60192); -- Getting Battle-Ready

UPDATE `quest_offer_reward` SET `RewardText`='But none of that matters. What matters is that you\'ve seen your own Holy Light! You know where power truly comes from. You realize that having our own allies is much more... prudent. Special allies. Allies that, no matter the task, will obey till their last breath.$B$BAnd that\'s where I come in, $N. I can train you in the beginnings of those special powers. Seek me out often and I will do what I can to teach you more spells.', `VerifiedBuild`=60192 WHERE `ID`=3115; -- Tainted Rune
UPDATE `quest_offer_reward` SET `VerifiedBuild`=60192 WHERE `ID` IN (24473, 24471, 24470, 24469, 3110, 24532, 3109, 3108, 24474, 24477, 3361, 24475);
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=24530; -- Oh, A Hunter's Life For Me
UPDATE `quest_offer_reward` SET `RewardText`='The humans have taught us a great deal about the Holy Light and how important their order is to them... and to protecting all of Azeroth. We have a great respect for how it is steeped in tradition, and how just one figure, one sacrifice, can make the difference between pain and salvation.$B$BThe two of us are gonna be working together for a bit.', `VerifiedBuild`=60192 WHERE `ID`=3107; -- Consecrated Rune
UPDATE `quest_offer_reward` SET `Emote1`=3, `VerifiedBuild`=60192 WHERE `ID`=24490; -- A Trip to Ironforge
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=218; -- Ice and Fire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `VerifiedBuild`=60192 WHERE `ID`=24489; -- Trolling for Information
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=182; -- The Troll Menace
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=24487; -- Whitebeard Needs Ye
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=60192 WHERE `ID`=24486; -- Make Hay While the Sun Shines
UPDATE `quest_offer_reward` SET `RewardText`='If you look around, you\'ll see a few interesting things: dwarves using magic in a fight instead of a rifle. Some of us have taken to worshipping the Holy Light like some of the humans, and, last but not least, troggs. You\'ll learn more about them later, but what you need to know now is that I\'m here to help you.', `VerifiedBuild`=60192 WHERE `ID`=3106; -- Simple Rune

DELETE FROM `quest_details` WHERE `ID` IN (26904 /*Harnessing the Flames*/, 24526 /*Filling Up the Spellbook*/, 24496 /*Arcane Rune*/, 24527 /*Your Path Begins Here*/, 24494 /*Empowered Rune*/, 24533 /*Words of Power*/, 24530 /*Oh, A Hunter's Life For Me*/, 24528 /*The Power of the Light*/, 24491 /*Follow that Gyro-Copter!*/, 24490 /*A Trip to Ironforge*/, 24489 /*Trolling for Information*/, 24487 /*Whitebeard Needs Ye*/, 24531 /*Getting Battle-Ready*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26904, 5, 0, 0, 0, 0, 0, 0, 0, 60192), -- Harnessing the Flames
(24526, 396, 0, 0, 0, 0, 0, 0, 0, 60192), -- Filling Up the Spellbook
(24496, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Arcane Rune
(24527, 396, 0, 0, 0, 0, 0, 0, 0, 60192), -- Your Path Begins Here
(24494, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Empowered Rune
(24533, 396, 0, 0, 0, 0, 0, 0, 0, 60192), -- Words of Power
(24530, 396, 0, 0, 0, 0, 0, 0, 0, 60192), -- Oh, A Hunter's Life For Me
(24528, 396, 0, 0, 0, 0, 0, 0, 0, 60192), -- The Power of the Light
(24491, 430, 1, 25, 0, 0, 0, 0, 0, 60192), -- Follow that Gyro-Copter!
(24490, 1, 5, 6, 66, 0, 0, 0, 0, 60192), -- A Trip to Ironforge
(24489, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Trolling for Information
(24487, 2, 1, 0, 0, 0, 0, 0, 0, 60192), -- Whitebeard Needs Ye
(24531, 396, 0, 0, 0, 0, 0, 0, 0, 60192); -- Getting Battle-Ready

UPDATE `quest_details` SET `VerifiedBuild`=60192 WHERE `ID` IN (3115, 24473, 24471, 24470, 24469, 3110, 24532, 3109, 3108, 24475, 3107, 24486, 24477, 24474, 218, 182, 3106);
UPDATE `quest_details` SET `Emote1`=5, `VerifiedBuild`=60192 WHERE `ID`=3361; -- A Refugee's Quandary

DELETE FROM `quest_request_items` WHERE `ID` IN (24533 /*Words of Power*/, 24531 /*Getting Battle-Ready*/, 24530 /*Oh, A Hunter's Life For Me*/, 24528 /*The Power of the Light*/, 24527 /*Your Path Begins Here*/, 24526 /*Filling Up the Spellbook*/, 26904 /*Harnessing the Flames*/, 24496 /*Arcane Rune*/, 24494 /*Empowered Rune*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24533, 0, 0, 0, 0, 'Don\'t forget, a disciplined priest will always use $g his; her: heals on his friends... not just on $g himself; herself:.', 60192), -- Words of Power
(24531, 0, 0, 0, 0, 'No, that\'s not a Charge.  Try again.', 60192), -- Getting Battle-Ready
(24530, 0, 0, 0, 0, 'I know the hunter\'s life is exctin\' now, but you jus\' wait... it gets even better.', 60192), -- Oh, A Hunter's Life For Me
(24528, 0, 0, 0, 0, 'Seal of Righteousness is great! I feel righteous right now!', 60192), -- The Power of the Light
(24527, 0, 0, 0, 0, 'You have not yet learned the Primal Strike skill.  Ask politely, and I will train you.', 60192), -- Your Path Begins Here
(24526, 0, 463, 0, 0, 'You can do this, $N.  Get out there and blast those dummies!', 60192), -- Filling Up the Spellbook
(26904, 0, 0, 0, 0, 'You\'re doing well, $N.', 60192), -- Harnessing the Flames
(24496, 6, 0, 0, 0, 'I see that Jona\'s given you my runic message.  Do you still have it with you?', 0), -- Arcane Rune
(24494, 6, 0, 0, 0, 'The spirits have forewarned me of your arrival, $n.  Have you heard them too?', 0); -- Empowered Rune

UPDATE `quest_request_items` SET `VerifiedBuild`=60192 WHERE `ID` IN (24474, 24471, 24470, 24469, 24532, 24486, 24477, 24475);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `CompletionText`='Ach! Ya made it, $N! Wonderful!$B$BI was gonna say, I was about to lose faith that ye\'d arrive at all... get it, lose faith? It\'s a joke, $glad:lass;... aww, nevermind. Ya didn\'t come here for me bad jokes anyway.' WHERE `ID`=3110; -- Hallowed Rune
UPDATE `quest_request_items` SET `CompletionText`='Blast it\'s cold today, ain\'t it? It\'s like the snow never goes away, $N.' WHERE `ID`=3106;
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=60192 WHERE `ID`=3361; -- A Refugee's Quandary
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='$n! Any luck?', `VerifiedBuild`=60192 WHERE `ID`=218; -- Ice and Fire
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='From what I\'ve learned, these trolls hail from the Frostmane clan. I\'m afraid I don\'t know much else about them that would be of any use to you, $n.', `VerifiedBuild`=60192 WHERE `ID`=182; -- The Troll Menace
UPDATE `quest_request_items` SET `CompletionText`='Wonderful! You obviously got my rune.$B$BIgnore the fools around you, $N. The Holy Light?! The sword and shield?! These aren\'t paths for ones as open minded as us. ' WHERE `ID`=3115;

UPDATE `creature_queststarter` SET `VerifiedBuild`=60192 WHERE (`id`=43455 AND `quest`=26904) OR (`id`=37087 AND `quest` IN (3115,24496,24494,3110,3109,3108,24475,3107,24474,24487,3106)) OR (`id`=37081 AND `quest` IN (24473,24470,24469)) OR (`id`=658 AND `quest`=24471) OR (`id`=37121 AND `quest`=24526) OR (`id`=37115 AND `quest`=24527) OR (`id`=837 AND `quest`=24533) OR (`id`=916 AND `quest`=24532) OR (`id`=895 AND `quest`=24530) OR (`id`=926 AND `quest`=24528) OR (`id`=1104 AND `quest` IN (24486,24477)) OR (`id`=6782 AND `quest`=24491) OR (`id`=786 AND `quest` IN (24490,218,182)) OR (`id`=1354 AND `quest`=24489) OR (`id`=8416 AND `quest`=3361) OR (`id`=912 AND `quest`=24531);
UPDATE `creature_questender` SET `VerifiedBuild`=60192 WHERE (`id`=43455 AND `quest` IN (26904,3115)) OR (`id`=37087 AND `quest` IN (24473,24475,24474)) OR (`id`=658 AND `quest`=24471) OR (`id`=37081 AND `quest` IN (24470,24469)) OR (`id`=37121 AND `quest` IN (24526,24496)) OR (`id`=37115 AND `quest` IN (24527,24494)) OR (`id`=837 AND `quest` IN (24533,3110)) OR (`id`=916 AND `quest` IN (24532,3109)) OR (`id`=895 AND `quest` IN (24530,3108)) OR (`id`=926 AND `quest` IN (24528,3107)) OR (`id`=1104 AND `quest` IN (24486,24477)) OR (`id`=6782 AND `quest`=24490) OR (`id`=786 AND `quest` IN (218,182,24487)) OR (`id`=1354 AND `quest`=24489) OR (`id`=8416 AND `quest`=3361) OR (`id`=912 AND `quest` IN (24531,3106));
