UPDATE `quest_offer_reward` SET `VerifiedBuild`=59185 WHERE `ID` IN (27023, 27015, 14456, 14455, 14458, 24852, 14452, 14449, 24540, 24550, 24524, 24523, 833, 861, 773, 20441, 24457, 24456, 14491, 26188, 24441, 26180, 26179, 751, 749, 11129, 24440, 743, 24459, 14438, 20440, 761, 24215, 23733, 24861, 3091, 14460, 14459, 14461, 27067, 3094, 24852, 14452, 14449, 14458, 14456, 14455);

UPDATE `quest_offer_reward` SET `RewardText`='The Grimtotem forced from Mulgore... if Baine speaks for this, you are indeed a fierce warrior.$B$BFrom this day, your strength is no longer your own. It belongs to me, and the Horde, as a weapon of war.$B$BHellscream\'s eyes are upon you, $n. Victory or death!', `VerifiedBuild`=59185 WHERE `ID`=26397; -- Walk With The Earth Mother
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for your help, $N.$B$BMy part in my brother\'s ceremony is almost complete. Giving him his headdress and witnessing the ceremony are all my duty requires of me.', `VerifiedBuild`=59185 WHERE `ID`=744; -- Preparation for Ceremony
UPDATE `quest_offer_reward` SET `RewardText`='Ahanu sent me finished products?  Very good.  There are many hunters and adventurers in Bloodhoof Village now and business is lively.  I am sure I\'ll sell these goods very soon.$B$BThank you for all your efforts, $N.  I am in your debt.', `VerifiedBuild`=59185 WHERE `ID`=6364; -- Return to Varg
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59185 WHERE `ID`=27020; -- The First Lesson
UPDATE `quest_offer_reward` SET `Emote3`=1, `RewardText`='We will meet many times in the days to come. Each time you will hopefully leave my company a little more powerful... a little more prepared. Like the Eternal Flame, your spirit will burn bright and hot.$B$BGo now, $N. Go and test yourself. I will be here for you when you need.', `VerifiedBuild`=59185 WHERE `ID`=3093; -- Rune-Inscribed Note
UPDATE `quest_offer_reward` SET `RewardText`='And it is my job to make sure you are prepared by teaching you the basics of our profession--how to tame your pet, how to fire your rifle, and many other skills that will become necessary.$B$BHunters are a strong part of our tradition and history, $N. You would do well to remember how important you are to the tribe. You will be respected and revered if you serve our people well.', `VerifiedBuild`=59185 WHERE `ID`=3092; -- Etched Note

DELETE FROM `quest_offer_reward` WHERE `ID` IN (27027 /*Primal Strike*/, 27066 /*Healing in a Flash*/, 27014 /*Hallowed Note*/, 27021 /*The Hunter's Path*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27027, 1, 1, 0, 0, 0, 0, 0, 0, 'Well done, $N. I see you will have no trouble mastering our more advanced arts as you gain experience. Return to me when you need further training.', 59185), -- Primal Strike
(27066, 1, 1, 0, 0, 0, 0, 0, 0, 'Thank you for your help in seeing to the wounded braves. I\'m sure that you will often find your healing skills in demand. Return to me when you need further instruction.', 59185), -- Healing in a Flash
(27014, 1, 1, 0, 0, 0, 0, 0, 0, 'You have arrived at last. During your training in Camp Narache, I will guide you in the ways of the priest. You have much to learn and I look forward to counting you among my students.', 59185), -- Hallowed Note
(27021, 1, 1, 0, 0, 0, 0, 0, 0, 'You have done well, $N. Return to me when you are in need of further training.', 59185); -- The Hunter's Path

UPDATE `quest_greeting` SET `VerifiedBuild`=59185 WHERE `Type`=0 AND `ID` IN (2988,36644);

UPDATE `quest_details` SET `VerifiedBuild`=59185 WHERE `ID` IN (26397, 24540, 24550, 24524, 744, 861, 773, 833, 24523, 20441, 24457, 6364, 24456, 26180, 26179, 751, 24441, 749, 11129, 26188, 14491, 743, 24440, 761, 20440, 24459, 14438, 24215, 23733, 24861, 14460, 14459, 14461, 3091, 14455, 14456, 14458, 24852, 14452, 14449, 27023, 27015, 27067, 3094, 3093, 3092);

DELETE FROM `quest_details` WHERE `ID` IN (26866 /*Enemies Below*/, 27020 /*The First Lesson*/, 27027 /*Primal Strike*/, 27066 /*Healing in a Flash*/, 27014 /*Hallowed Note*/, 27021 /*The Hunter's Path*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26866, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Enemies Below
(27020, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- The First Lesson
(27027, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Primal Strike
(27066, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Healing in a Flash
(27014, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Hallowed Note
(27021, 1, 1, 0, 0, 0, 0, 0, 0, 59185); -- The Hunter's Path

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (26188, 26180, 26179, 761, 744, 743, 20440, 14491, 11129, 24523, 14461, 14459, 14456, 14455, 861, 14452, 14438, 833, 24861, 24852, 24456, 24441, 24440);

UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6364;


DELETE FROM `quest_request_items` WHERE `ID` IN (24540 /*War Dance*/, 24524 /*Wildmane Cleansing*/, 27020 /*The First Lesson*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24540, 0, 0, 0, 0, 'I do not plan on sitting idly in Thunder Bluff while our warriors risk their lives for our home, $n. We shall meet on the battlefield. Strike out ahead of me; I will leave soon.', 59185), -- War Dance
(24524, 0, 0, 0, 0, 'The last water well remains fetid and poisonous, $N.  You must not delay!', 59185), -- Wildmane Cleansing
(27020, 0, 1, 0, 0, 'Have you mastered the charge?', 59185); -- The First Lesson

DELETE FROM `quest_request_items` WHERE `ID` IN (24540 /*War Dance*/, 24524 /*Wildmane Cleansing*/, 27023 /*The Way of the Sunwalkers*/, 27020 /*The First Lesson*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24540, 0, 0, 0, 0, 'I do not plan on sitting idly in Thunder Bluff while our warriors risk their lives for our home, $n. We shall meet on the battlefield. Strike out ahead of me; I will leave soon.', 59185), -- War Dance
(24524, 0, 0, 0, 0, 'The last water well remains fetid and poisonous, $N.  You must not delay!', 59185), -- Wildmane Cleansing
(27023, 0, 1, 0, 0, 'Have you mastered the use of your first seal and judgement?', 59185), -- The Way of the Sunwalkers
(27020, 0, 1, 0, 0, 'Have you mastered the charge?', 59185); -- The First Lesson

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (26188, 26180, 26179, 761, 744, 743, 20440, 14491, 11129, 24523, 14461, 14459, 14456, 14455, 861, 14452, 14438, 833, 24861, 24852, 24456, 24441, 24440);

UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6364;
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=27015;

DELETE FROM `quest_request_items` WHERE `ID` IN (24540 /*War Dance*/, 24524 /*Wildmane Cleansing*/, 27066 /*Healing in a Flash*/, 27027 /*Primal Strike*/, 27023 /*The Way of the Sunwalkers*/, 27021 /*The Hunter's Path*/, 27020 /*The First Lesson*/, 27014 /*Hallowed Note*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24540, 0, 0, 0, 0, 'I do not plan on sitting idly in Thunder Bluff while our warriors risk their lives for our home, $n. We shall meet on the battlefield. Strike out ahead of me; I will leave soon.', 59185), -- War Dance
(24524, 0, 0, 0, 0, 'The last water well remains fetid and poisonous, $N.  You must not delay!', 59185), -- Wildmane Cleansing
(27066, 0, 1, 0, 0, 'Have you mastered the charge?', 59185), -- Healing in a Flash
(27027, 0, 1, 0, 0, 'Have you mastered Primal Strike?', 59185), -- Primal Strike
(27023, 0, 1, 0, 0, 'Have you mastered the use of your first seal and judgement?', 59185), -- The Way of the Sunwalkers
(27021, 0, 1, 0, 0, 'Have you mastered the charge?', 59185), -- The Hunter's Path
(27020, 0, 1, 0, 0, 'Have you mastered the charge?', 59185), -- The First Lesson
(27014, 2, 0, 0, 0, 'I am pleased to meet you, $N.', 59185); -- Hallowed Note

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (26188, 26180, 26179, 761, 744, 743, 20440, 14491, 11129, 24523, 14461, 14459, 14456, 14455, 861, 14452, 14438, 833, 24861, 24852, 24456, 24441, 24440);

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=3093; -- Rune-Inscribed Note
UPDATE `quest_request_items` SET `CompletionText`='Welcome to Camp Narache, $N. I hear good things about you. Your bloodline is strong, and many of the elders consider you skilled already. But that we will test.$B$BThe plains of Mulgore will be your home for sometime--you should do your best to learn it very well. One day you will travel to unfamiliar lands to master greater skills. You must be ready.' WHERE `ID`=3092; -- Etched Note
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6364;
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=27015;

UPDATE `creature_queststarter` SET `VerifiedBuild`=59185 WHERE `id`=36648 AND `quest` IN (26397,26866,24540) OR `id`=37024 AND `quest` IN (24550,24524,24523) OR `id`=2987 AND `quest`=744 OR `id`=3052 AND `quest`=861 OR `id`=3233 AND `quest` IN (773,833) OR `id`=3054 AND `quest`=20441 OR `id`=2948 AND `quest` IN (24457,24456,24441,24440,20440) OR `id`=2995 AND `quest`=6364 OR `id`=2988 AND `quest` IN (26180,26179,749) OR `id`=23618 AND `quest`=11129 OR `id`=3055 AND `quest`=26188 OR `id`=36644 AND `quest` IN (14491,24459,14438) OR`id`=2985 AND `quest`=743 OR `id`=2947 AND `quest`=761 OR `id`=36803 AND `quest`=24215 OR `id`=2981 AND `quest` IN (23733,24861,14449) OR `id`=3059 AND `quest`=27020 OR `id`=36694 AND `quest` IN (14460,14459,14461,14455,14456) OR `id`=44927 AND `quest`=3091 OR `id`=2980 AND `quest` IN (14458,24852,14452) OR `id`=3060 AND `quest`=27067 OR `id`=44927 AND `quest` IN (3094,3093,27014,3092,27015) OR `id`=3062 AND `quest`=27027 OR `id`=37724 AND `quest`=27066 OR `id`=3061 AND `quest`=27021 OR `id`=37737 AND `quest`=27023;

UPDATE `creature_questender` SET `VerifiedBuild`=59185 WHERE `id`=36648 AND `quest` IN (24540,24550) OR `id`=37024 AND `quest` IN (24524,24523,20441) OR `id`=3233 AND `quest`=833 OR `id`=3052 AND `quest`=861 OR `id`=2987 AND `quest`=744 OR `id`=2994 AND `quest`=773 OR `id`=3054 AND `quest`=24457 OR `id`=2948 AND `quest` IN (24456,24441,24440,20440) OR `id`=36644 AND `quest` IN (14491,14438,24215) OR `id`=3055 AND `quest`=26188 OR `id`=3079 AND `quest`=6364 OR `id`=2988 AND `quest` IN (26180,26179,751,24459) OR `id`=23618 AND `quest`=11129 OR `id`=2985 AND `quest`=743 OR `id`=2947 AND `quest`=761 OR `id`=36803 AND `quest`=23733 OR  `id`=2981 AND `quest` IN (24861,14460) OR `id`=3059 AND `quest` IN (27020,3091) OR `id`=36694 AND `quest` IN (14459,14461,14455,14456,14458) OR `id`=2980 AND `quest` IN (24852,14452,14449) OR `id`=37737 AND `quest` IN (27023,27015) OR `id`=3060 AND `quest` IN (27067,3094) OR `id`=3062 AND `quest` IN (27027,3093) OR `id`=37724 AND `quest` IN (27066,27014) OR `id`=3061 AND `quest` IN (27021,3092);

DELETE FROM `creature_questender` WHERE `id`=39605 AND `quest`=26397;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(39605, 26397, 59185); -- Walk With The Earth Mother ended by Garrosh Hellscream

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=59185 WHERE `id`=2908 AND `quest`=751;

UPDATE `gameobject_questender` SET `VerifiedBuild`=59185 WHERE `id`=2908 AND `quest`=749;
