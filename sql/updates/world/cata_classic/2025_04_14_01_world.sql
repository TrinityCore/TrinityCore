DELETE FROM `quest_offer_reward` WHERE `ID` IN (24968 /*Dark Deeds*/, 24966 /*Of Light and Shadows*/, 24967 /*Stab!*/, 26920 /*The Battle for Andorhal*/, 24969 /*Charging into Battle*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(24968, 1, 1, 0, 0, 0, 0, 0, 0, 'Congratulations... you\'re one step closer to being a master of the dark arts.  Go practice a bit, and return when you\'re stronger.  I\'ll have more to teach you then.', 59185), -- Dark Deeds
(24966, 1, 1, 0, 0, 0, 0, 0, 0, 'You\'re a good student, $n.  You\'ll go far.  If you ever need any further training, return to me and I\'ll happily oblige.', 59185), -- Of Light and Shadows
(24967, 1, 1, 0, 0, 0, 0, 0, 0, 'Trust me, this\'ll be worth the money.  And hey - if you need any more training, stop by any time.', 59185), -- Stab!
(26920, 396, 0, 0, 0, 0, 0, 0, 0, 'It\'s about time you arrived, $c.', 59185), -- The Battle for Andorhal
(24969, 1, 1, 0, 0, 0, 0, 0, 0, 'You have the makings of a great warrior, $n.  Go, practice what we\'ve discussed, and return when you are stronger.  Then I may have more to teach you.', 59185); -- Charging into Battle

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='I mentioned a slave still being a slave, no matter the master. Do you remember? We both know that it is that type of control--that type of power--that now drives us. We seek to have creatures serve us. We know we are more powerful and deserve more respect than others give us... and so now we look to take it.$B$BI will be your ally in this struggle--the struggle for our own freedom. Freedom to seek our own allegiances. When you feel ready, return to me and I will teach you all I know.', `VerifiedBuild`=59185 WHERE `ID`=3099; -- Tainted Scroll
UPDATE `quest_offer_reward` SET `RewardText`='Great work $N.  I knew you weren\'t useless.$b$bHere, take one of these.  We deathguards have piles of these things just sitting around.', `VerifiedBuild`=59185 WHERE `ID`=26800; -- Recruitment
UPDATE `quest_offer_reward` SET `RewardText`='Not even the power of the val\'kyr was enough to save these creatures.  They were doomed from the beginning.$b$bI have obtained some equipment for you, $N.  It\'s not much, but it will help.  Please, take your pick.', `VerifiedBuild`=59185 WHERE `ID`=26799; -- Those That Couldn't Be Saved
UPDATE `quest_offer_reward` SET `RewardText`='Exactly what I needed.  You\'ll be an asset to the Forsaken, $N.$b$bYou know, word has it that you were quite the $c in your previous life.  Perhaps I should assign you to a more exciting task.', `VerifiedBuild`=59185 WHERE `ID`=28608; -- The Shadow Grave
UPDATE `quest_offer_reward` SET `RewardText`='Hello there.  You must be... $N?', `VerifiedBuild`=59185 WHERE `ID`=24959; -- Fresh out of the Grave
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `Emote3`=1, `RewardText`='There is only one thing you must know: we have survived through will alone. It is faith in ourselves that separates us from others, and with our powers, we will cause great change in all of Azeroth. The weak will come to lean on you. The lepers will call you $gLord:Lady;. And the ignorant will look to you for guidance. It is my duty to make sure you have the necessary tools so when the time comes, you are prepared. As you grow in experience, seek me out. I will teach you greater powers if you are ready.', `VerifiedBuild`=59185 WHERE `ID`=3097; -- Hallowed Scroll
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59185 WHERE `ID`=3096; -- Encrypted Scroll
UPDATE `quest_offer_reward` SET `RewardText`='May the Dark Lady watch over you, $N.', `VerifiedBuild`=59185 WHERE `ID`=28651; -- Novice Elreth
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59185 WHERE `ID`=24964; -- The Thrill of the Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59185 WHERE `ID`=24962; -- Trail-Worn Scroll
UPDATE `quest_offer_reward` SET `RewardText`='Welcome back, $N.  I\'ve heard stories from the east.  Who would have thought that a young $r $c like you would have been the one to wipe out the last whimpering remnants of the Scarlet Crusade?', `VerifiedBuild`=59185 WHERE `ID`=25012; -- Take to the Skies
UPDATE `quest_offer_reward` SET `RewardText`='Ah, this venom will do perfectly, $N.  Everything else has been added to my concoction and boiled down.  Thank you, $c!', `VerifiedBuild`=59185 WHERE `ID`=25013; -- A Little Oomph
UPDATE `quest_offer_reward` SET `RewardText`='From birth to grave to undeath, we all have our own path to follow.  Some are easier than others.  It sounds like this Voss girl has had a rough path so far.$b$bHopefully she ultimately chooses to join us and follow the Dark Lady.  With power like hers, we could do incredible things.$b$bBy the way, $N... excellent work out there.  If you\'re ever ready and willing, I may have some more work for you in the Plaguelands.', `VerifiedBuild`=59185 WHERE `ID`=25046; -- A Daughter's Embrace
UPDATE `quest_offer_reward` SET `RewardText`='Devlin Agamand?  Is that him you carry in your sack there?  Ha!$b$bYes, I know what Coleman wants to try, and I want to try it too.  I hope you\'re prepared, $N.', `VerifiedBuild`=59185 WHERE `ID`=25005; -- Speak with Sevren
UPDATE `quest_offer_reward` SET `RewardText`='Your efforts are appreciated, $N.  I will not thank you for doing what is necessary, but I will remember your name.', `VerifiedBuild`=59185 WHERE `ID`=25004; -- The Mills Overrun
UPDATE `quest_offer_reward` SET `RewardText`='Your actions struck a telling blow against the Scourge.  And your victory will not go unnoticed - not by the Forsaken, nor by our enemies.$B$BContinue the struggle as we all do, $N, and one day the Forsaken will have the dominion over Azeroth that they are owed!', `VerifiedBuild`=59185 WHERE `ID`=25003; -- The Family Crypt
UPDATE `quest_offer_reward` SET `RewardText`='Did they run from you, $N?  Good.  This is better than killing them... if they live to tell the tale, then future generations of murlocs will learn to fear us.', `VerifiedBuild`=59185 WHERE `ID`=24999; -- Planting the Seed of Fear
UPDATE `quest_offer_reward` SET `RewardText`='The scales are perfect, $N. Exactly what I needed for this concoction.', `VerifiedBuild`=59185 WHERE `ID`=24995; -- Off the Scales
UPDATE `quest_offer_reward` SET `RewardText`='Ah, my doom weed. Excellent!$B$B<Apothecary Jerrod rubs his hands together greedily.>$B$BThese will come in quite handy. You\'ve done me, uh, the Lady, a fine service today, $N. As promised, here is the reward that you deserve.', `VerifiedBuild`=59185 WHERE `ID`=24994; -- Doom Weed
UPDATE `quest_offer_reward` SET `RewardText`='Expertly done, $N.  The Scourge are mistaken if they think they can use those corpses against us, and the fluid you gathered from the Rot Hide slaves will be studied by my master.  It may have secrets we can use against them.', `VerifiedBuild`=59185 WHERE `ID`=24997; -- Graverobbers
UPDATE `quest_offer_reward` SET `RewardText`='I appreciate your efforts, $N.  May Sylvanas recognize your bravery one day. . . .', `VerifiedBuild`=59185 WHERE `ID`=24988; -- The Chill of Death
UPDATE `quest_offer_reward` SET `RewardText`='You have done well, $N and I thank you for your efforts.', `VerifiedBuild`=59185 WHERE `ID`=24990; -- Darkhound Pounding
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  Now comes the fun part.', `VerifiedBuild`=59185 WHERE `ID`=24976; -- Variety is the Spice of Death
UPDATE `quest_offer_reward` SET `RewardText`='$N.  You made it.$b$bYou see those tents up there?  That\'s where we\'re headed.  The battle\'s probably already started.', `VerifiedBuild`=59185 WHERE `ID`=24970; -- No Better Than the Zombies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59185 WHERE `ID`=3095; -- Simple Scroll

DELETE FROM `quest_details` WHERE `ID` IN (24968 /*Dark Deeds*/, 3099 /*Tainted Scroll*/, 24966 /*Of Light and Shadows*/, 3097 /*Hallowed Scroll*/, 24967 /*Stab!*/, 3096 /*Encrypted Scroll*/, 24964 /*The Thrill of the Hunt*/, 24962 /*Trail-Worn Scroll*/, 26920 /*The Battle for Andorhal*/, 12752 /*Desperate Research*/, 24969 /*Charging into Battle*/, 3095 /*Simple Scroll*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(24968, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Dark Deeds
(3099, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Tainted Scroll
(24966, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Of Light and Shadows
(3097, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Hallowed Scroll
(24967, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Stab!
(3096, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Encrypted Scroll
(24964, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Thrill of the Hunt
(24962, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Trail-Worn Scroll
(26920, 1, 1, 1, 0, 0, 0, 0, 0, 59185), -- The Battle for Andorhal
(12752, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Desperate Research
(24969, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Charging into Battle
(3095, 1, 0, 0, 0, 0, 0, 0, 0, 59185); -- Simple Scroll

DELETE FROM `quest_request_items` WHERE `ID` IN (24973 /*Night Web's Hollow*/, 24969 /*Charging into Battle*/, 24968 /*Dark Deeds*/, 24967 /*Stab!*/, 24966 /*Of Light and Shadows*/, 24964 /*The Thrill of the Hunt*/, 26800 /*Recruitment*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24973, 0, 1, 0, 0, 'Be wary of the spiders\' venom, $n. If you feel a sharp burning, you may want to have it looked at.', 59185), -- Night Web's Hollow
(24969, 0, 1, 0, 0, 'We will continue only once you have learned the art of the charge.', 59185), -- Charging into Battle
(24968, 0, 1, 0, 0, 'Are you not interested in training?', 59185), -- Dark Deeds
(24967, 0, 1, 0, 0, 'Shh!  Quiet down!', 59185), -- Stab!
(24966, 0, 1, 0, 0, 'We must train before we can move on, $n.', 59185), -- Of Light and Shadows
(24964, 0, 1, 0, 0, 'There\'ll be time for idle chat later, $n.  For now, we must train.', 59185), -- The Thrill of the Hunt
(26800, 0, 6, 0, 0, 'Have you managed to scavenge up some corpses?', 59185); -- Recruitment

UPDATE `quest_request_items` SET `CompletionText`='Do you have some venom from a Vicious Night Web Spider yet, $N?  It\'s the final component I need in order to test my experiment.', `VerifiedBuild`=59185 WHERE `ID`=25013; -- A Little Oomph
UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (25009, 26978, 25006, 24998, 24997, 24994, 24981, 24980, 24976, 24974, 26934, 26933, 24961, 26931, 24960, 25090, 28608, 25056, 25029, 26799);
UPDATE `quest_request_items` SET `CompletionText`='Our battles with the Scourge wage on, $N.  Do your part and throw those cursed, mindless undead back into the Plaguelands!', `VerifiedBuild`=59185 WHERE `ID`=25004; -- The Mills Overrun
UPDATE `quest_request_items` SET `CompletionText`='Time is not a luxury we have, $N.  With each passing hour, the Scourge\'s hold on Tirisfal Glades grows more firm.', `VerifiedBuild`=59185 WHERE `ID`=25003; -- The Family Crypt
UPDATE `quest_request_items` SET `CompletionText`='Chase them until they pass out in fear, $N.  Let them grow up in fear of the Forsaken.', `VerifiedBuild`=59185 WHERE `ID`=24999; -- Planting the Seed of Fear
UPDATE `quest_request_items` SET `CompletionText`='$N, were you able to obtain those scales from the murlocs?', `VerifiedBuild`=59185 WHERE `ID`=24995; -- Off the Scales
UPDATE `quest_request_items` SET `CompletionText`='Have you collected the darkhound blood yet, $N? Time is fleeting!', `VerifiedBuild`=59185 WHERE `ID`=24990; -- Darkhound Pounding
UPDATE `quest_request_items` SET `CompletionText`='Do you have five duskbat pelts yet, $N?', `VerifiedBuild`=59185 WHERE `ID`=24988; -- The Chill of Death
UPDATE `quest_request_items` SET `CompletionText`='You\'ve not yet completed my task, $N.  It is time for the harvesters to become the harvested!', `VerifiedBuild`=59185 WHERE `ID`=24978; -- Reaping the Reapers
UPDATE `quest_request_items` SET `CompletionText`='Were you able to gather 10 pumpkins yet, $N?', `VerifiedBuild`=59185 WHERE `ID`=24975; -- Fields of Grief
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `CompletionText`='I bid you welcome, $Gbrother:sister;. I knew you would come. It was only a matter of time.$B$BWhat I said interested you, didn\'t it? I hit a chord... something inside you knew what I claimed was truth. Good.$B$BKnow this though: I am no traitor to Sylvanas. If anything, she would appreciate my claims, considering it was her own beliefs that have put the Forsaken in the position it is now.' WHERE `ID`=3099; -- Tainted Scroll
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59185 WHERE `ID`=24965; -- Magic Training
UPDATE `quest_request_items` SET `CompletionText`='Ah, so between fire, plague, rioting, and much worse, one more of the \"faithful\" comes to my door. Well, let me bid you welcome, $c. And allow me a moment to explain a thing or two before you decide it\'s time for you to seek whatever drives you forward: the Holy Light no longer concerns you, the spirits of your forefathers are fairy tales, and creatures from the Nether don\'t want you.$B$BDo you understand me so far?' WHERE `ID`=3097;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=3096;
UPDATE `quest_request_items` SET `CompletionText`='Ah, so you\'ve arrived. Good. I overheard that a few others were able to escape \"death\" and were heading into town. Perhaps that resilience will pay off in the future also.$B$BYou may thank Sylvanas for your freedom... freedom of mind and body. Though you still remain tortured by the plague and its effects, you are now free to come and go as you see fit.' WHERE `ID`=3095;
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=24962;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `VerifiedBuild`=59185 WHERE `ID`=25038; -- Gordo's Task
UPDATE `quest_request_items` SET `EmoteOnComplete`=4 WHERE `ID`=6322;
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=59185 WHERE `ID`=26802; -- The Damned
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `VerifiedBuild`=59185 WHERE `ID`=26801; -- Scourge on our Perimeter

DELETE FROM `creature_queststarter` WHERE (`id`=2126 AND `quest`=24968) OR (`id`=1569 AND `quest` IN (3099,3098,3097,3096,24962,3095)) OR (`id`=2124 AND `quest`=24965) OR (`id`=2123 AND `quest`=24966) OR (`id`=2122 AND `quest`=24967) OR (`id`=38911 AND `quest`=24964) OR (`id`=2119 AND `quest`=24969);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(2126, 24968, 59185), -- Dark Deeds offered by Maximillion
(1569, 3099, 59185), -- Tainted Scroll offered by Shadow Priest Sarvis
(2124, 24965, 59185), -- Magic Training offered by Isabella
(1569, 3098, 59185), -- Glyphic Scroll offered by Shadow Priest Sarvis
(2123, 24966, 59185), -- Of Light and Shadows offered by Dark Cleric Duesten
(1569, 3097, 59185), -- Hallowed Scroll offered by Shadow Priest Sarvis
(2122, 24967, 59185), -- Stab! offered by David Trias
(1569, 3096, 59185), -- Encrypted Scroll offered by Shadow Priest Sarvis
(38911, 24964, 59185), -- The Thrill of the Hunt offered by Xavier the Huntsman
(1569, 24962, 59185), -- Trail-Worn Scroll offered by Shadow Priest Sarvis
(19178, 12752, 59185), -- Desperate Research offered by Forsaken Commoner
(2119, 24969, 59185), -- Charging into Battle offered by Dannal Stern
(1569, 3095, 59185); -- Simple Scroll offered by Shadow Priest Sarvis

DELETE FROM `creature_questender` WHERE (`id`=2126 AND `quest` IN (24968,3099)) OR (`id`=2124 AND `quest` IN (24965,3098)) OR (`id`=2123 AND `quest` IN (24966,3097)) OR (`id`=2122 AND `quest` IN (24967,3096)) OR (`id`=38911 AND `quest` IN (24964,24962)) OR (`id`=2119 AND `quest` IN (24969,3095));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(2126, 24968, 59185), -- Dark Deeds ended by Maximillion
(2126, 3099, 59185), -- Tainted Scroll ended by Maximillion
(2124, 24965, 59185), -- Magic Training ended by Isabella
(2124, 3098, 59185), -- Glyphic Scroll ended by Isabella
(2123, 24966, 59185), -- Of Light and Shadows ended by Dark Cleric Duesten
(2123, 3097, 59185), -- Hallowed Scroll ended by Dark Cleric Duesten
(2122, 24967, 59185), -- Stab! ended by David Trias
(2122, 3096, 59185), -- Encrypted Scroll ended by David Trias
(38911, 24964, 59185), -- The Thrill of the Hunt ended by Xavier the Huntsman
(38911, 24962, 59185), -- Trail-Worn Scroll ended by Xavier the Huntsman
(2119, 24969, 59185), -- Charging into Battle ended by Dannal Stern
(2119, 3095, 59185); -- Simple Scroll ended by Dannal Stern
