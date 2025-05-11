DELETE FROM `quest_offer_reward` WHERE `ID` IN (25149 /*Arcane Missiles*/, 25138 /*Glyphic Parchment*/, 25147 /*Charge*/, 25141 /*Eviscerate*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(25149, 1, 1, 1, 0, 0, 0, 0, 0, 'Good.  Now we practice.', 59185), -- Arcane Missiles
(25138, 1, 1, 1, 0, 0, 0, 0, 0, 'Ahh, where to start... introductions!  I\'m Acrypha - the one who sent you that parchment - I\'ve spent the last several years in an Undercity library, my head in a book.  I learned everything I could about the arcane, and now I\'ve returned home to share it with grunts like yourself.$b$bShall we begin?', 59185), -- Glyphic Parchment
(25147, 1, 1, 0, 0, 0, 0, 0, 0, 'You understand now?  Good, let\'s try it out.', 59185), -- Charge
(25141, 1, 1, 0, 0, 0, 0, 0, 0, 'You won\'t be sorry.  The ability to capitalize on the opportunities created by previous attacks is one of our greatest strengths.', 59185); -- Eviscerate

UPDATE `quest_offer_reward` SET `VerifiedBuild`=59185 WHERE `ID` IN (25189, 25187, 25227, 25177, 25178, 25176, 25173, 25171, 25169, 25165, 25168, 25167, 25170, 25133, 25132, 25135, 25130, 25131, 25129, 25128, 25127, 25136, 25134, 25172, 25126, 25152, 25139, 25143, 3089, 25145, 3090, 25264, 26642, 25648, 25263, 25262, 25259, 25257, 25256, 25206, 25236, 25260, 25205, 25196, 835, 834, 25232, 25188, 25195, 25194, 25192, 25190, 25193);

UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Hah!  I guess she liked it!  Nothing brings red to a lady\'s cheeks like a big, juicy steak!$B$BThank you, $N.  You\'ve done me a great service.  Here is some money for your trouble, and don\'t be surprised if I invite you to my wedding!', `VerifiedBuild`=59185 WHERE `ID`=6386; -- Return to Razor Hill
UPDATE `quest_offer_reward` SET `RewardText`='I\'ve already spoken with several orcs that have returned from the beach.  All of them told me that you were the one who saved them.$b$bYou\'ve done a noble task today, $N.  Lok\'tar ogar!  For the Horde!', `VerifiedBuild`=59185 WHERE `ID`=25179; -- Loss Reduction
UPDATE `quest_offer_reward` SET `RewardText`='Ah, that\'s my parchment.  I heard you\'d be coming to the Valley, $N.  I\'m glad to see you made it--let\'s hope you survive the trials ahead.', `VerifiedBuild`=59185 WHERE `ID`=2383; -- Simple Parchment
UPDATE `quest_offer_reward` SET `RewardText`='As a hunter, my skill rivals the arcane powers of the mages, the martial prowess of the warriors, or even the blessed acts of our beloved shaman.  To be a hunter requires focus and dedication.  Let us continue.', `VerifiedBuild`=59185 WHERE `ID`=3087; -- Etched Parchment
UPDATE `quest_offer_reward` SET `RewardText`='Now that you know where I\'m holding up, I should let you know: the Shattered Hand\'s asked me to look out for you. They want me to train you and keep you informed of anything they might need. Even if you\'re not interested in helping them yet--which you\'d be a fool not to be--I\'ll do what I can to train you... for a small fee.', `VerifiedBuild`=59185 WHERE `ID`=3088; -- Encrypted Parchment
UPDATE `quest_offer_reward` SET `RewardText`='I\'m at a crossroads now, $N... you defeated him easily in combat, but then again, I did get him for free, and he\'s pretty cheap to feed.  Maybe we\'ll keep him around for a bit.', `VerifiedBuild`=59185 WHERE `ID`=25258; -- Griswold Hanniston
UPDATE `quest_offer_reward` SET `RewardText`='Welcome, $N.  Word reached me of your coming, and of your exploits in Durotar.$B$BYou are a $c of growing skill and renown.$B$BStay on the pure path, and your future will be great indeed.', `VerifiedBuild`=59185 WHERE `ID`=25261; -- Margoz

UPDATE `quest_greeting` SET `VerifiedBuild`=59185 WHERE `Type`=0 AND `ID` IN (3188,3143) OR `ID`=3143 AND `Type`=0;

DELETE FROM `quest_greeting` WHERE `ID`=3287 AND `Type`=0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(3287, 0, 0, 0, '', 59185); -- Hana'zua

UPDATE `quest_details` SET `VerifiedBuild`=59185 WHERE `ID` IN (25190, 25189, 25193, 25188, 25187, 6386, 25227, 25179, 25178, 25177, 25176, 25173, 25232, 25171, 25169, 25168, 25165, 25170, 25167, 25133, 25135, 25132, 25130, 25131, 25128, 25127, 25129, 25134, 25172, 25126, 25152, 2383, 25139, 3087, 3088, 25143, 3089, 25136, 25145, 3090, 871, 25264, 26311, 26642, 25924, 25263, 25259, 25258, 25257, 25256, 25262, 25261, 25206, 25205, 25236, 25260, 835, 834, 25196, 25195, 25194, 25192);

DELETE FROM `quest_details` WHERE `ID` IN (25149 /*Arcane Missiles*/, 25138 /*Glyphic Parchment*/, 25147 /*Charge*/, 25141 /*Eviscerate*/, 25648 /*Beyond Durotar*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25149, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Arcane Missiles
(25138, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Glyphic Parchment
(25147, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Charge
(25141, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Eviscerate
(25648, 1, 274, 1, 0, 0, 0, 0, 0, 59185); -- Beyond Durotar

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (25178, 25177, 25176, 25173, 25172, 25260, 25259, 25170, 25258, 25169, 25257, 25168, 25167, 25165, 25136, 25135, 25134, 835, 25132, 834, 25131, 25129, 25127, 25126, 25206, 25205, 25195, 25194, 25193, 25192, 25190, 25188, 25187, 25145);

UPDATE `quest_request_items` SET `CompletionText`='Have you yet entered Skull Rock, $N?  Do you have the Searing Collars?', `VerifiedBuild`=59185 WHERE `ID`=25262; -- Skull Rock
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='Have you returned from Orgrimmar?  Did Gryshka like the meat I sent her?' WHERE `ID`=6386; -- Return to Razor Hill
UPDATE `quest_request_items` SET `CompletionText`='I need that canyon clean, $N.  Water is normally scarce in Durotar... we should take advantage of this.', `VerifiedBuild`=59185 WHERE `ID`=25236; -- Thunder Down Under
UPDATE `quest_request_items` SET `CompletionText`='The scrolls, $N, the scrolls!', `VerifiedBuild`=59185 WHERE `ID`=25232; -- The Burning Blade
UPDATE `quest_request_items` SET `EmoteOnComplete`=4 WHERE `ID`=25138;
UPDATE `quest_request_items` SET `CompletionText`='Shhh, not so loud.  The enemy has ears everywhere.' WHERE `ID`=3088; -- Encrypted Parchment
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=2, `VerifiedBuild`=59185 WHERE `ID`=25139; -- Steady Shot
UPDATE `quest_request_items` SET `CompletionText`='What\'s that you have there?  A parchment?  You\'re not a scholar, I hope... ' WHERE `ID`=2383;
UPDATE `quest_request_items` SET `CompletionText`='Have you yet entered Skull Rock, $N?  Do you have the Searing Collars?', `VerifiedBuild`=59185 WHERE `ID`=25262; -- Skull Rock
UPDATE `quest_request_items` SET `CompletionText`='I need that canyon clean, $N.  Water is normally scarce in Durotar... we should take advantage of this.', `VerifiedBuild`=59185 WHERE `ID`=25236; -- Thunder Down Under

DELETE FROM `quest_request_items` WHERE `ID` IN (25149 /*Arcane Missiles*/, 25147 /*Charge*/, 25143 /*Primal Strike*/, 25141 /*Eviscerate*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25149, 0, 4, 0, 0, 'You\'ll have to learn SOMETHING before we move forward, $N.  Ha!', 59185), -- Arcane Missiles
(25147, 0, 6, 0, 0, 'After we train, then we will test your abilities.', 59185), -- Charge
(25143, 0, 2, 0, 0, 'We must continue your training before pressing forward, young $n.', 59185), -- Primal Strike
(25141, 0, 2, 0, 0, 'We don\'t move forward until I get paid.', 59185); -- Eviscerate

UPDATE `creature_queststarter` SET `VerifiedBuild`=59185 WHERE `id`=39326 AND `quest` IN (25190,25192) OR `id`=39325 AND `quest`=25189 OR `id`=3193 AND `quest`=25193 OR `id`=39323 AND `quest` IN (25188,25187) OR `id`=3310 AND `quest`=6386 OR `id`=39423 AND `quest` IN (25227,25178,25176) OR `id`=3139 AND `quest` IN (25177,25173) OR `id`=3142 AND `quest` IN (25232,25196) OR `id`=3188 AND `quest` IN (25171,25168,25167) OR `id`=3140 AND `quest`=25169 OR `id`=10578 AND `quest` IN (25165,25170) OR `id`=3145 AND `quest` IN (25133,25132,25131) OR `id`=11378 AND `quest` IN (25135,25134) OR `id`=3287 AND `quest` IN (25130,25129) OR `id`=5887 AND `quest`=25128 OR `id`=3143 AND `quest` IN (25127,25172,25126) OR `id`=9796 AND `quest`=25136 OR `id`=10176 AND `quest`=25152 OR `id`=3337 AND `quest`=871 OR `id`=3216 AND `quest`=25264 OR `id`=42637 AND `quest`=26311 OR `id`=35068 AND `quest`=26642 OR `id`=41621 AND `quest`=25924 OR `id`=3208 AND `quest` IN (25263,25262) OR `id`=39590 AND `quest` IN (25259,25258,25257) OR `id`=39604 AND `quest`=25256 OR `id`=39379 AND `quest` IN (25648,25261,25206,25236,25260) OR `id`=39380 AND `quest`=25205 OR `id`=3293 AND `quest` IN (835,834) OR `id`=39324 AND `quest` IN (25195,25194) OR `id`=3143 AND `quest` IN (3089,3090) OR `id`=3157 AND `quest`=25143 OR `id`=3156 AND `quest`=25145;

DELETE FROM `creature_queststarter` WHERE `id`=39206 AND `quest`=25149 OR `id`=3143 AND `quest`=25138 OR `id`=3153 AND `quest`=25147 OR `id`=3143 AND `quest` IN (2383,3087,3088) OR `id`=39214 AND `quest`=25139 OR `id`=3155 AND `quest`=25141;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(39206, 25149, 59185), -- Arcane Missiles offered by Acrypha
(3143, 25138, 59185), -- Glyphic Parchment offered by Gornek
(3153, 25147, 59185), -- Charge offered by Frang
(3143, 2383, 59185), -- Simple Parchment offered by Gornek
(39214, 25139, 59185), -- Steady Shot offered by Karranisha
(3143, 3087, 59185), -- Etched Parchment offered by Gornek
(3155, 25141, 59185), -- Eviscerate offered by Rwag
(3143, 3088, 59185); -- Encrypted Parchment offered by Gornek

UPDATE `creature_questender` SET `VerifiedBuild`=59185 WHERE `id`=39326 AND `quest` IN (25189,25192,25190) OR `id`=3193 AND `quest`=25193 OR `id`=39323 AND `quest` IN (25188,25187,25227) OR `id`=3881 AND `quest`=6386 OR `id`=3139 AND `quest` IN (25179,25177,25173,25171) OR `id`=39423 AND `quest` IN (25178,25176) OR `id`=3142 AND `quest`=25232 OR `id`=3140 AND `quest`=25169 OR `id`=10578 AND `quest` IN (25165,25170) OR `id`=3188 AND `quest` IN (25168,25167,25133) OR `id`=3145 AND `quest` IN (25132,25131) OR `id`=11378 AND `quest` IN (25135,25134) OR `id`=3143 AND `quest` IN (25130,25127,25172,25126,25152) OR `id`=3287 AND `quest` IN (25129,25128) OR `id`=9796 AND `quest`=25136 OR `id`=3521 AND `quest`=25264 OR `id`=3337 AND `quest`=26642 OR `id`=8576 AND `quest`=25648 OR `id`=3216 AND `quest`=25263 OR `id`=3208 AND `quest` IN (25262,25261) OR `id`=39590 AND `quest` IN (25259,25258,25257,25256) OR `id`=39379 AND `quest` IN (25206,25236,25260,25196) OR `id`=39380 AND `quest`=25205 OR `id`=3293 AND `quest` IN (835,834) OR `id`=39324 AND `quest` IN (25195,25194) OR`id`=3157 AND `quest` IN (25143,3089) OR `id`=3156 AND `quest` IN (25145,3090);

DELETE FROM `creature_questender` WHERE `id`=39206 AND `quest` IN (25149,25138) OR `id`=3153 AND `quest` IN (25147,2383) OR `id`=39214 AND `quest` IN (25139,3087) OR `id`=3155 AND `quest` IN (25141,3088);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(39206, 25149, 59185), -- Arcane Missiles ended by Acrypha
(39206, 25138, 59185), -- Glyphic Parchment ended by Acrypha
(3153, 25147, 59185), -- Charge ended by Frang
(3153, 2383, 59185), -- Simple Parchment ended by Frang
(39214, 25139, 59185), -- Steady Shot ended by Karranisha
(39214, 3087, 59185), -- Etched Parchment ended by Karranisha
(3155, 25141, 59185), -- Eviscerate ended by Rwag
(3155, 3088, 59185); -- Encrypted Parchment ended by Rwag
