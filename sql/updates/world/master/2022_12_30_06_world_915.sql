-- 
DELETE FROM `quest_offer_reward` WHERE `ID` IN (64271 /*A More Civilized Way*/, 63781 /*Mawsworn Battle Plans*/, 64292 /*Maelie, The Wanderer*/, 63974 /*That's Going to Sting*/, 63972 /*Just Don't Ask Me to Spell It*/, 64430 /*Spill the Tea*/, 64089 /*Teas and Tinctures*/, 59951 /*A Druid's Form*/, 62435 /*Stag Soul*/, 63965 /*Razorwing Egg Rescue*/, 64104 /*Think of the Critters*/, 63836 /*Fangcrack's Fan Club*/, 63956 /*Sealed Secrets*/, 64710 /*Whispering Felflame Crystal*/, 65026 /*Owl Soul*/, 14442 /*My Favorite Subject*/, 63610 /*Mammoth Soul*/, 65146 /*Relic Hunter*/, 65266 /*Lost Research*/, 63914 /*Cipher of Understanding*/, 63920 /*Enigmatic Decrypting Device*/, 64129 /*Charge of the Wild Hunt*/, 63778 /*We Move Forward*/, 40997 /*Lethal Efficiency*/, 40996 /*Delegation*/, 40950 /*Honoring Success*/, 42627 /*The Unseen Blade*/, 42568 /*Preparation*/, 42539 /*Cloak and Dagger*/, 42503 /*Codebreaker*/, 42501 /*Finishing the Job*/, 42502 /*No Sanctuary*/, 40840 /*A Worthy Blade*/, 65467 /*Turkey Soul*/, 61423 /*Champion: Karynmwylyann*/, 65145 /*Relic Clues*/, 63903 /*Storming the Sanctum*/, 60215 /*Doomwalkin' Has Come Knockin'*/, 57249 /*A Timely Invitation*/, 64581 /*A Gently Shaken Gift*/, 64639 /*A Winter Veil Gift*/, 65105 /*Return More Lost Souls*/, 60406 /*Training in Bastion*/, 30112 /*A Score to Settle*/, 29536 /*Heart of Rage*/, 29537 /*Mind the Gap*/, 29535 /*Make Them Bleed*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(64271, 0, 0, 0, 0, 0, 0, 0, 0, 'Your form still needs work. Thank you, for taking time out of our unending campaign to duel. We must remember, even in times of great struggle, to do things that bring us joy.', 42010), -- A More Civilized Way
(63781, 11, 0, 0, 0, 0, 0, 0, 0, 'Again, you survive. You remind me of me. I will review these plans and inform our companions.', 42010), -- Mawsworn Battle Plans
(64292, 0, 0, 0, 0, 0, 0, 0, 0, 'Take care of Maelie, Maw Walker.', 42010), -- Maelie, The Wanderer
(63974, 1, 0, 0, 0, 0, 0, 0, 0, 'I wish I could\'ve been there to see it myself!\n\nA fitting end for the Heralds...', 42010), -- That's Going to Sting
(63972, 1, 0, 0, 0, 0, 0, 0, 0, 'I have received many reports from hunters who were aided by Krrprripripkraak and her friends. Thank you for helping them.', 42010), -- Just Don't Ask Me to Spell It
(64430, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah, you\'ve all returned safely. Wonderful!', 41793), -- Spill the Tea
(64089, 0, 0, 0, 0, 0, 0, 0, 0, 'Oh my! I\'ve never even seen most of these herbs. Hum, this black one looks a bit dangerous. This green one seems promising. Well done $p!', 41793), -- Teas and Tinctures
(59951, 4, 1, 0, 0, 0, 0, 0, 0, 'Good! I can sense the blessing of the spirits flowing through you.\n\nFocus, and you should find that you can take on a new form.', 41488), -- A Druid's Form
(62435, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, the stag. This shape is now yours to call upon.', 41488), -- Stag Soul
(63965, 0, 0, 0, 0, 0, 0, 0, 0, 'Look at these wonderful eggs! I can hear their heartbeats.\n\nThis is the start of something beautiful, I just know it.', 41488), -- Razorwing Egg Rescue
(64104, 0, 0, 0, 0, 0, 0, 0, 0, 'You were able to feed some of them? Wonderful!\n\nI\'ll start saving up more food for next time. I hope that one day we can help this place heal, too.', 41488), -- Think of the Critters
(63836, 0, 0, 0, 0, 0, 0, 0, 0, 'You also joined Fangcrack\'s fan club? So did Lady Moonberry.\n\n<Prince Renathal thinks for a moment.>\n\nPerhaps I should reconsider my earlier rejection of Rendle\'s invitation to join...', 41488), -- Fangcrack's Fan Club
(63956, 0, 0, 0, 0, 0, 0, 0, 0, 'Wonderful! You brought everything that I asked for.\n\nAgain, do not worry about the contents of these boxes. They pose no threat to you.\n\nHere is the reward I promised.', 41488), -- Sealed Secrets
(64710, 1, 1, 273, 0, 0, 300, 300, 0, 'I will just put this back when it belongs. Thank you for bringing it to me, $n.', 41359), -- Whispering Felflame Crystal
(65026, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, the owl. This shape is now yours to call upon.', 41359), -- Owl Soul
(14442, 0, 0, 0, 0, 0, 0, 0, 0, 'Have you come to assist me with my work? My claws are quite dexterous, but I must reluctantly confess that my arms are debilitatingly short.', 41359), -- My Favorite Subject
(63610, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, the mammoth. This shape is now yours to call upon.', 41079), -- Mammoth Soul
(65146, 0, 0, 0, 0, 0, 0, 0, 0, 'It seems some relics have a trace or unique identifier. \n\nHere are the details, it should allow you to locate even more relics when you find a source.', 41079), -- Relic Hunter
(65266, 1, 0, 0, 0, 0, 0, 0, 0, 'The research within these repositories is invaluable. I may ask you to return to the rift again in the future.', 41079), -- Lost Research
(63914, 1, 1, 1, -1, 0, 500, 1000, 0, 'My stars! To comprehend any of these languages would allow one the insight to translate all of them. We must look into this further.', 41079), -- Cipher of Understanding
(63920, 1, 1, 1, -1, 0, 500, 1000, 0, 'Though I have only a passing understanding of its operation, this relic can strip the complexity of communication into a form that is free from subtlety, guile, or metaphor. Pure logic.', 41079), -- Enigmatic Decrypting Device
(64129, 0, 0, 0, 0, 0, 0, 0, 0, 'You and Aldermeigh make a great team! Thank you for taking him out and dispatching so many Mawsworn.\n\nOne day, I too will ride with the Wild Hunt, and we will right many wrongs.', 41079), -- Charge of the Wild Hunt
(63778, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you, my friend.\n\nEvery bit of anima we collect gives me hope that we can heal the Shadowlands. One day, we will be whole again.', 41079), -- We Move Forward
(40997, 273, 0, 0, 0, 0, 0, 0, 0, 'Great choice! We have tons of intel on that place.', 41079), -- Lethal Efficiency
(40996, 1, 0, 0, 0, 0, 0, 0, 0, 'I don\'t know nothin\' about nobody.$B$BOh, who I am I kiddin\'? I know everything about everybody! How\'s it goin\', Shadow $n?', 41079), -- Delegation
(40950, 1, 0, 0, 0, 0, 0, 0, 0, 'It seems you struck a nerve.', 41079), -- Honoring Success
(42627, 396, 0, 0, 0, 0, 0, 0, 0, 'Every second I held those blades again was torture. They\'re all yours.', 41079), -- The Unseen Blade
(42568, 396, 0, 0, 0, 0, 0, 0, 0, 'If you\'re with me, drench your blades with poison now. This is going to get bloody.', 41079), -- Preparation
(42539, 0, 0, 0, 0, 0, 0, 0, 0, '<Your next destination is clear: Stormwind. But where is Garona?>', 41079), -- Cloak and Dagger
(42503, 0, 0, 0, 0, 0, 0, 0, 0, '<This does not bode well for the citizens of Darkshire.>', 41079), -- Codebreaker
(42501, 0, 0, 0, 0, 0, 0, 0, 0, '<The coded message you found is sure to contain a lead on the cult\'s activities. You need only a way to decipher its contents.>', 41079), -- Finishing the Job
(42502, 0, 0, 0, 0, 0, 0, 0, 0, '<The cipher you found will allow you to intercept the cult\'s communications, bringing you one step closer to Garona.>', 41079), -- No Sanctuary
(40840, 1, 0, 0, 0, 0, 0, 0, 0, 'Well chosen.', 41079), -- A Worthy Blade
(65467, 1, 0, 0, 0, 0, 0, 0, 0, 'Ooh, a turkey! You can gobble like one now, too!', 41079), -- Turkey Soul
(61423, 1, 4, 0, 0, 0, 300, 0, 0, 'My memories have been restored and now I need a new path. I shall join you along yours for a time if you wish.', 41079), -- Champion: Karynmwylyann
(65145, 0, 0, 0, 0, 0, 0, 0, 0, 'The research is going so well. \n\nPreliminary findings have given me clues on how to find more relics, let me share them with you.', 41079), -- Relic Clues
(63903, 1, 1, 0, 0, 0, 0, 0, 0, 'The Jailer has what he wanted... along with Anduin at his side.\n\nOur only victory--if you can call it that--is that we have Sylvanas in custody.\n\nI pray she possesses knowledge that can give us an edge to stop whatever the Jailer is planning next.', 41079), -- Storming the Sanctum
(60215, 0, 0, 0, 0, 0, 0, 0, 0, 'Thanks for taking out Doomwalker, let\'s hope that doesn\'t happen again! It will though!', 41031), -- Doomwalkin' Has Come Knockin'
(57249, 1, 273, 0, 0, 0, 0, 0, 0, 'Welcome! It\'s that special time of year when the bronze dragonflight celebrates all that has happened over the years and you, $n, are the guest of honor!\nCome celebrate at the grand feast, get down at the \"Disco of Time\", or accept a quest to fend off some of Azeroth\'s greatest threats.', 41031), -- A Timely Invitation
(64581, 0, 0, 0, 0, 0, 0, 0, 0, 'This present looks like it has been shaken a few times. The tag on it reads:$b$bTo a very special $r $c.', 41488), -- A Gently Shaken Gift
(64639, 0, 0, 0, 0, 0, 0, 0, 0, 'A small tag on this present reads:$b$bHappy holidays, $n!', 41488), -- A Winter Veil Gift
(65105, 0, 0, 0, 0, 0, 0, 0, 0, 'Another good collection of souls. Not too broken, not too drained, and not too innocent.\n\nI know just where to send these souls on their path to redemption.', 40944), -- Return More Lost Souls
(60406, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you for showing them around today. There\'s plenty to learn still, though.', 40944), -- Training in Bastion
(30112, 66, 0, 0, 0, 0, 0, 0, 0, 'Revenge feels good.  To think that this is but a taste of what\'s to come.$B$BArthas will get what he deserves soon enough.', 40944), -- A Score to Settle
(29536, 396, 396, 0, 0, 0, 0, 0, 0, '<You tell Caza\'rez everything you saw in the Blood Furnace.>$B$BI see.$B$BIf they can do this to the Mag\'har brown orcs, they can do it to us! We must be careful lest they turn all of Thrallmar into those mindless beasts.', 40944), -- Heart of Rage
(29537, 396, 0, 0, 0, 0, 0, 0, 0, 'The interference has gone down, but we still cannot access that area. We will continue to investigate the matter. Thank you for your help.', 40944), -- Mind the Gap
(29535, 396, 0, 0, 0, 0, 0, 0, 0, 'These vials could mean the end of the fel orcs. I hope you understand just how important that is to our campaign here.', 40944); -- Make Them Bleed

UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=42010 WHERE `ID`=8670; -- Runetotem the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=42010 WHERE `ID` IN (63964, 63935, 63780, 61984, 63968, 63952, 59004, 63664, 63773, 63774, 63753, 63772, 60156, 60154, 24745, 63834, 63835, 63842);
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='It is good to know the people of this land still pay homage to the olden races.  I bid you well, $n, and offer you this token...', `VerifiedBuild`=42010 WHERE `ID`=8866; -- Bronzebeard the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='It is good to know the people of this land still pay homage to the olden races.  I bid you well, $n, and offer you this token...', `VerifiedBuild`=42010 WHERE `ID`=8653; -- Goldwell the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='It is good to know the people of this land still pay homage to the olden races.  I bid you well, $n, and offer you this token...', `VerifiedBuild`=42010 WHERE `ID`=8642; -- Silvervein the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=41793 WHERE `ID` IN (63794, 63787, 63784, 61984);
UPDATE `quest_offer_reward` SET `RewardText`='You found it!  You\'ve saved Smokywood Pastures\' Feast of Winter Veil!$B$BYou\'re a true hero to everyone here at Smokywood Pastures and to all the children, of course!', `VerifiedBuild`=41488 WHERE `ID`=6983; -- You're a Mean One...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=41488 WHERE `ID` IN (63773, 63455, 63621, 63772, 63669, 61984, 63961, 63780, 63787, 63834, 63837, 63842, 63789, 63784, 64432, 64070, 63945, 63968, 60152, 60151, 60150, 60149, 60148, 60129);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=41359 WHERE `ID` IN (61984, 64194, 63790, 64043, 63935, 64101, 14377, 14370, 14371, 14422, 14408, 14310, 14308, 14322, 14424, 14216, 14423, 14209, 14215, 14201, 14202, 29658, 29659, 29657, 24453, 24452, 14472, 29685, 29686, 29687, 11490, 29684, 14469, 14470, 14471, 14468, 14155, 14146, 14135, 14194, 14192, 14190, 14165, 14161, 14197, 63936, 63934, 63968, 63973, 63951);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=41079 WHERE `ID` IN (61984, 63787, 63782, 63791, 63669, 63773, 63455, 63621, 63772, 14128, 14118, 14127, 14117, 14134, 14129, 27850, 27848, 27076, 27070, 27071, 27068, 34673, 50335, 30984, 30969, 30983, 27847, 27844, 27842, 13166, 13165, 12801, 12800, 12779, 12778, 12757, 12756, 12755, 12754, 12751, 12738, 12724, 12727, 12725, 12723, 12717, 12716, 12720, 12722, 12719, 12715, 12714, 12706, 12701, 12700, 12698, 12697, 12679, 12687, 12678, 12680, 12711, 12733, 12670, 12850, 12657, 12641, 12636, 12848, 12842, 12619, 12593, 60418, 63841, 63839, 63835, 63833, 38641, 38377, 38322, 38225, 38235, 38381, 38147, 38145, 38144, 38143, 38455, 38246, 38922, 38142, 40573, 39384, 39383, 38382, 38384, 40122, 39861, 39731, 62860, 61095, 63783, 63780, 63957, 64070, 64432, 14452, 14449);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `RewardText`='Fordring... Yes, I know him well. If any other man or orc asked me for such a favor I would have killed you where you stood. Fordring, though, is an honored hero among orcs.$b$bVery well, Death Knight. We accept you as a member of the Horde, and embrace your order as allies.$b$bFor the Horde!', `VerifiedBuild`=41079 WHERE `ID`=13189; -- Saurfang's Blessing
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=41079 WHERE `ID`=12739; -- A Special Surprise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=41031 WHERE `ID` IN (63859, 63669, 63455, 63625, 63753, 63772, 61984, 62860);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40966 WHERE `ID` IN (62860, 63945, 63970, 63973, 63969);
UPDATE `quest_offer_reward` SET `RewardText`='What\'ve you got there?$b$bOh hey, this is big. Real big. Most of the crazy details in one little package. Thanks - you really helped us reel this all in. Good working with ya.', `VerifiedBuild`=42010 WHERE `ID`=14483; -- Something is in the Air (and it Ain't Love)
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40944 WHERE `ID` IN (61984, 61426, 63969, 63973, 63945, 63970, 60444, 13207, 29850, 29848, 29861, 29860, 29862, 62869, 11905, 11973, 29681, 29675, 29674);
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `RewardText`='Every blade we take from them is one less embedded in a soldier\'s flesh.$B$BThank you.', `VerifiedBuild`=40944 WHERE `ID`=13206; -- Disarmament
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `EmoteDelay2`=500, `VerifiedBuild`=40944 WHERE `ID`=11262; -- Ingvar Must Die!
UPDATE `quest_offer_reward` SET `RewardText`='You found it!? Yes, yes, it\'s all here.$b$bPlease, take this with my gratitude.', `VerifiedBuild`=40944 WHERE `ID`=13095; -- Have They No Shame?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=40906 WHERE `ID` IN (29574, 29575, 29573, 49933);

DELETE FROM `quest_poi` WHERE (`QuestID`=62435 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42723 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=42723 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42723 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=14310 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=14310 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=14310 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=14442 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=14442 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=24452 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=24452 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=24452 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=42019 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=42019 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=63920 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=63920 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=64129 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=64129 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=64129 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=64129 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=64129 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=14134 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=14134 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=14134 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=13166 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=13166 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=13166 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=13166 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50786 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50786 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50786 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=38235 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=38235 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=38235 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38235 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38235 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=38147 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38147 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38147 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=38246 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38246 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38246 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=38455 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38455 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38455 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=39731 AND `BlobIndex`=9 AND `Idx1`=10) OR (`QuestID`=39731 AND `BlobIndex`=8 AND `Idx1`=9) OR (`QuestID`=39731 AND `BlobIndex`=7 AND `Idx1`=8) OR (`QuestID`=39731 AND `BlobIndex`=6 AND `Idx1`=7) OR (`QuestID`=39731 AND `BlobIndex`=5 AND `Idx1`=6) OR (`QuestID`=39731 AND `BlobIndex`=4 AND `Idx1`=5) OR (`QuestID`=39731 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=39731 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=39731 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=39731 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=39731 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=40996 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=40996 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=42503 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=65020 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=65020 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=65020 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51743 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51743 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51743 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(62435, 0, 0, -1, 0, 0, 2222, 1565, 0, 0, 0, 0, 0, 2021931, 0, 41488), -- Stag Soul
(42723, 0, 2, 32, 0, 0, 1220, 630, 0, 2, 0, 0, 0, 0, 0, 41359), -- Eye of Azshara: A Tough Shell
(42723, 0, 1, 1, 284648, 96028, 1456, 713, 0, 2, 0, 0, 0, 0, 0, 41359), -- Eye of Azshara: A Tough Shell
(42723, 0, 0, 0, 284647, 101467, 1456, 713, 0, 2, 0, 0, 0, 0, 0, 41359), -- Eye of Azshara: A Tough Shell
(14310, 0, 2, 32, 0, 0, 1, 76, 0, 0, 0, 0, 0, 320081, 0, 41359), -- Segmentation Fault: Core Dumped
(14310, 0, 1, 0, 267623, 36096, 1, 76, 0, 7, 0, 0, 0, 0, 0, 41359), -- Segmentation Fault: Core Dumped
(14310, 0, 0, -1, 0, 0, 1, 76, 0, 1, 0, 0, 0, 0, 0, 41359), -- Segmentation Fault: Core Dumped
(14442, 0, 1, 32, 0, 0, 1, 76, 0, 0, 0, 0, 0, 320654, 0, 41359), -- My Favorite Subject
(14442, 0, 0, -1, 0, 0, 1, 76, 0, 1, 0, 0, 0, 0, 0, 41359), -- My Favorite Subject
(24452, 0, 2, 32, 0, 0, 1, 76, 0, 0, 0, 0, 0, 327475, 0, 41359), -- Profitability Scouting
(24452, 0, 1, 0, 267397, -1, 1, 76, 0, 2, 0, 0, 0, 0, 0, 41359), -- Profitability Scouting
(24452, 0, 0, -1, 0, 0, 1, 76, 0, 0, 0, 0, 0, 327475, 0, 41359), -- Profitability Scouting
(42019, 0, 6, 32, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 0, 0, 41359), -- Tip the Scales
(42019, 0, 5, 6, 283403, 89811, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(42019, 0, 4, 5, 283402, 89808, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(42019, 0, 3, 4, 283401, 239774, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(42019, 1, 2, 2, 283398, 89803, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(42019, 0, 1, 2, 283398, 89803, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(42019, 0, 0, 1, 283397, 89025, 1220, 630, 0, 0, 0, 0, 0, 0, 1, 41359), -- Tip the Scales
(63920, 0, 1, 32, 0, 0, 2222, 1961, 0, 0, 0, 0, 0, 2072741, 0, 41079), -- Enigmatic Decrypting Device
(63920, 0, 0, -1, 0, 0, 2222, 1961, 0, 0, 0, 0, 0, 2070863, 0, 41079), -- Enigmatic Decrypting Device
(64129, 0, 4, 32, 0, 0, 2222, 1961, 0, 2, 0, 92980, 0, 0, 0, 41079), -- Charge of the Wild Hunt
(64129, 1, 3, 1, 420648, 179408, 2222, 1961, 0, 0, 0, 0, 91182, 0, 0, 41079), -- Charge of the Wild Hunt
(64129, 0, 2, 1, 420648, 179408, 2222, 1961, 0, 2, 0, 91181, 0, 0, 0, 41079), -- Charge of the Wild Hunt
(64129, 0, 1, 0, 420647, 179404, 2222, 1961, 0, 0, 0, 91181, 0, 2082541, 0, 41079), -- Charge of the Wild Hunt
(64129, 0, 0, -1, 0, 0, 2222, 1961, 0, 0, 0, 91609, 0, 2081081, 0, 41079), -- Charge of the Wild Hunt
(14134, 0, 2, 32, 0, 0, 1, 76, 0, 0, 0, 0, 0, 312205, 0, 41079), -- The Captain's Logs
(14134, 0, 1, 0, 264603, 47050, 1, 76, 0, 7, 0, 0, 0, 0, 0, 41079), -- The Captain's Logs
(14134, 0, 0, -1, 0, 0, 1, 76, 0, 3, 0, 0, 0, 0, 0, 41079), -- The Captain's Logs
(13166, 0, 3, 32, 0, 0, 0, 23, 0, 0, 0, 0, 0, 264115, 0, 41079), -- The Battle For The Ebon Hold
(13166, 0, 2, 1, 264790, 31100, 0, 23, 0, 1, 0, 0, 0, 0, 0, 41079), -- The Battle For The Ebon Hold
(13166, 0, 1, 0, 264789, 31099, 0, 23, 0, 1, 0, 0, 0, 0, 0, 41079), -- The Battle For The Ebon Hold
(13166, 0, 0, -1, 0, 0, 0, 23, 0, 1, 0, 0, 0, 0, 0, 41079), -- The Battle For The Ebon Hold
(50786, 0, 2, 32, 0, 0, 1642, 863, 0, 2, 0, 0, 0, 0, 0, 41079), -- Revenge of Krag'wa
(50786, 0, 1, 1, 333822, 123437, 1642, 863, 0, 0, 0, 0, 0, 0, 0, 41079), -- Revenge of Krag'wa
(50786, 0, 0, 0, 333821, 134982, 1642, 863, 0, 0, 0, 0, 0, 1475213, 0, 41079), -- Revenge of Krag'wa
(38235, 0, 4, 32, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 999965, 0, 41079), -- Solid as a Rock
(38235, 0, 3, 2, 278646, 93644, 1220, 641, 0, 0, 0, 0, 0, 1020927, 0, 41079), -- Solid as a Rock
(38235, 0, 2, 1, 278645, 93640, 1220, 641, 0, 0, 0, 0, 0, 1001827, 0, 41079), -- Solid as a Rock
(38235, 0, 1, 0, 277559, 93602, 1220, 641, 0, 0, 0, 0, 0, 1000552, 0, 41079), -- Solid as a Rock
(38235, 0, 0, -1, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 999965, 0, 41079), -- Solid as a Rock
(38147, 0, 2, 32, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1000866, 0, 41079), -- Entangled Dreams
(38147, 0, 1, 1, 277536, 91045, 1220, 641, 0, 0, 0, 0, 0, 999818, 0, 41079), -- Entangled Dreams
(38147, 0, 0, -1, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1001497, 0, 41079), -- Entangled Dreams
(38246, 0, 2, 32, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1020151, 0, 41079), -- Totemic Call
(38246, 0, 1, 0, 277574, 91117, 1220, 641, 0, 0, 0, 0, 0, 1020965, 0, 41079), -- Totemic Call
(38246, 0, 0, -1, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1022887, 0, 41079), -- Totemic Call
(38455, 0, 2, 32, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1022880, 0, 41079), -- Frenzied Furbolgs
(38455, 0, 1, 0, 277952, 91288, 1220, 641, 0, 0, 0, 0, 0, 0, 0, 41079), -- Frenzied Furbolgs
(38455, 0, 0, -1, 0, 0, 1220, 641, 0, 0, 0, 0, 0, 1022880, 0, 41079), -- Frenzied Furbolgs
(39731, 9, 10, 0, 280872, 97377, 1519, 720, 0, 0, 0, 41722, 0, 1082746, 0, 41079), -- The Tranquil Forest
(39731, 8, 9, 0, 280872, 97377, 1469, 726, 0, 0, 0, 41729, 0, 1085044, 0, 41079), -- The Tranquil Forest
(39731, 7, 8, 0, 280872, 97377, 1512, 702, 0, 0, 0, 41727, 0, 1120564, 0, 41079), -- The Tranquil Forest
(39731, 6, 7, 0, 280872, 97377, 1514, 709, 0, 0, 0, 41720, 0, 1081444, 0, 41079), -- The Tranquil Forest
(39731, 5, 6, 0, 280872, 97377, 0, 24, 0, 0, 0, 41726, 0, 1055809, 0, 41079), -- The Tranquil Forest
(39731, 4, 5, 0, 280872, 97377, 1220, 747, 0, 0, 0, 41723, 0, 1068068, 0, 41079), -- The Tranquil Forest
(39731, 3, 4, 0, 280872, 97377, 1220, 739, 0, 0, 0, 41724, 0, 1078072, 0, 41079), -- The Tranquil Forest
(39731, 2, 3, 0, 280872, 97377, 1513, 734, 0, 0, 0, 41725, 0, 1126749, 0, 41079), -- The Tranquil Forest
(39731, 1, 2, 0, 280872, 97377, 1479, 695, 0, 0, 0, 41731, 0, 1050464, 0, 41079), -- The Tranquil Forest
(39731, 0, 1, 0, 280872, 97377, 1107, 717, 0, 2, 0, 41730, 0, 0, 0, 41079), -- The Tranquil Forest
(39731, 0, 0, -1, 0, 0, 1220, 627, 0, 0, 0, 0, 0, 1137954, 0, 41079), -- The Tranquil Forest
(40996, 0, 1, 32, 0, 0, 1220, 626, 0, 2, 0, 0, 0, 0, 0, 41079), -- Delegation
(40996, 0, 0, -1, 0, 0, 1220, 626, 0, 0, 0, 0, 0, 1068975, 0, 41079), -- Delegation
(42503, 0, 0, 32, 0, 0, 1220, 626, 0, 0, 0, 0, 0, 1171900, 0, 41079), -- Codebreaker
(65020, 0, 2, 32, 0, 0, 2222, 1961, 0, 0, 0, 0, 0, 2070863, 0, 41079), -- Practical Applications
(65020, 0, 1, 0, 421930, 373433, 2222, 1961, 0, 0, 0, 0, 0, 2114550, 0, 41079), -- Practical Applications
(65020, 0, 0, -1, 0, 0, 2222, 1961, 0, 0, 0, 0, 0, 2070863, 0, 41079), -- Practical Applications
(51743, 0, 2, 32, 0, 0, 1643, 896, 0, 2, 0, 0, 0, 0, 0, 40906), -- More Valuable Than Gold
(51743, 0, 1, 1, 337002, 132317, 1643, 896, 0, 0, 0, 0, 0, 0, 0, 40906), -- More Valuable Than Gold
(51743, 0, 0, 0, 337001, 160577, 1643, 896, 0, 0, 0, 0, 0, 0, 0, 40906); -- More Valuable Than Gold

UPDATE `quest_poi` SET `VerifiedBuild`=42010 WHERE (`QuestID`=63964 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=63964 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=63964 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=62633 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=41793 WHERE (`QuestID`=62633 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=41488 WHERE (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=41079 WHERE (`QuestID`=59850 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=59850 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=59850 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=59850 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=59850 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59850 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=59850 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59850 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=12715 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=12715 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=41031 WHERE (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=40944 WHERE (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60565 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60444 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60444 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60444 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=40906 WHERE (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60048 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=62435 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42723 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=42723 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42723 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=14310 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=14310 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=14310 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=14442 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=14442 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=24452 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=24452 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=24452 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=10) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=9) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=42019 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=42019 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=42019 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=42019 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=42019 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=42019 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=11) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=10) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=9) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=8) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=42019 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=63920 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=63920 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=64129 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=64129 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=64129 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=64129 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=64129 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=14134 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=14134 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=14134 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=13166 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=13166 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13166 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13166 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50786 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50786 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50786 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=38235 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=38235 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=38235 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38235 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38235 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=38147 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38147 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38147 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=38246 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38246 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38246 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=38455 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=38455 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38455 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=39731 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=40996 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=40996 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=42503 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=65020 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=65020 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=65020 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51743 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51743 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=51743 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(62435, 0, 0, -6837, 1085, 5692, 41488), -- Stag Soul
(42723, 2, 0, 6, 5745, 0, 41359), -- Eye of Azshara: A Tough Shell
(42723, 1, 0, -3484, 4360, 0, 41359), -- Eye of Azshara: A Tough Shell
(42723, 0, 0, -3229, 3746, 6, 41359), -- Eye of Azshara: A Tough Shell
(14310, 2, 0, 2536, -5790, 77, 41359), -- Segmentation Fault: Core Dumped
(14310, 1, 0, 2542, -5792, 77, 41359), -- Segmentation Fault: Core Dumped
(14310, 0, 0, 2653, -6162, 98, 41359), -- Segmentation Fault: Core Dumped
(14442, 1, 0, 2606, -5858, 82, 41359), -- My Favorite Subject
(14442, 0, 0, 2583, -5702, 110, 41359), -- My Favorite Subject
(24452, 2, 0, 3260, -4997, 131, 41359), -- Profitability Scouting
(24452, 1, 0, 3538, -5130, 84, 41359), -- Profitability Scouting
(24452, 0, 0, 3260, -4997, 131, 41359), -- Profitability Scouting
(42019, 6, 0, -81, 5791, 0, 41359), -- Tip the Scales
(42019, 5, 10, -105, 5592, 6, 41359), -- Tip the Scales
(42019, 5, 9, -212, 5661, 18, 41359), -- Tip the Scales
(42019, 5, 8, -213, 5666, 18, 41359), -- Tip the Scales
(42019, 5, 7, -210, 5669, 0, 41359), -- Tip the Scales
(42019, 5, 6, -129, 5741, 9, 41359), -- Tip the Scales
(42019, 5, 5, 63, 5875, 9, 41359), -- Tip the Scales
(42019, 5, 4, 104, 5745, 1, 41359), -- Tip the Scales
(42019, 5, 3, 98, 5714, 0, 41359), -- Tip the Scales
(42019, 5, 2, 97, 5710, 0, 41359), -- Tip the Scales
(42019, 5, 1, 57, 5604, 1, 41359), -- Tip the Scales
(42019, 5, 0, -83, 5579, 1, 41359), -- Tip the Scales
(42019, 4, 4, 44, 5678, -1, 41359), -- Tip the Scales
(42019, 4, 3, 40, 5696, 0, 41359), -- Tip the Scales
(42019, 4, 2, 95, 5691, -1, 41359), -- Tip the Scales
(42019, 4, 1, 93, 5674, 0, 41359), -- Tip the Scales
(42019, 4, 0, 79, 5662, -1, 41359), -- Tip the Scales
(42019, 3, 2, 0, 5667, 0, 41359), -- Tip the Scales
(42019, 3, 1, -1, 5673, 0, 41359), -- Tip the Scales
(42019, 3, 0, 7, 5666, 0, 41359), -- Tip the Scales
(42019, 2, 4, -149, 5627, 15, 41359), -- Tip the Scales
(42019, 2, 3, -76, 5687, 14, 41359), -- Tip the Scales
(42019, 2, 2, 16, 5645, 1, 41359), -- Tip the Scales
(42019, 2, 1, 53, 5603, 0, 41359), -- Tip the Scales
(42019, 2, 0, -102, 5590, 2, 41359), -- Tip the Scales
(42019, 1, 4, -236, 5731, 15, 41359), -- Tip the Scales
(42019, 1, 3, -236, 5743, 14, 41359), -- Tip the Scales
(42019, 1, 2, -217, 5831, 1, 41359), -- Tip the Scales
(42019, 1, 1, -128, 5813, 0, 41359), -- Tip the Scales
(42019, 1, 0, -229, 5722, 2, 41359), -- Tip the Scales
(42019, 0, 11, -82, 5476, 1, 41359), -- Tip the Scales
(42019, 0, 10, -161, 5578, 18, 41359), -- Tip the Scales
(42019, 0, 9, -208, 5665, 29, 41359), -- Tip the Scales
(42019, 0, 8, -223, 5722, 6, 41359), -- Tip the Scales
(42019, 0, 7, -238, 5808, 0, 41359), -- Tip the Scales
(42019, 0, 6, -208, 5859, 4, 41359), -- Tip the Scales
(42019, 0, 5, 69, 5996, 8, 41359), -- Tip the Scales
(42019, 0, 4, 98, 5942, 3, 41359), -- Tip the Scales
(42019, 0, 3, 98, 5905, 2, 41359), -- Tip the Scales
(42019, 0, 2, 197, 5747, 1, 41359), -- Tip the Scales
(42019, 0, 1, 108, 5503, 0, 41359), -- Tip the Scales
(42019, 0, 0, -2, 5486, 0, 41359), -- Tip the Scales
(63920, 1, 0, 2588, 6883, 4846, 41079), -- Enigmatic Decrypting Device
(63920, 0, 0, 3298, 5812, 4900, 41079), -- Enigmatic Decrypting Device
(64129, 4, 0, 3331, 5870, 4905, 41079), -- Charge of the Wild Hunt
(64129, 3, 9, 2832, 5975, 4807, 41079), -- Charge of the Wild Hunt
(64129, 3, 8, 2796, 6346, 4838, 41079), -- Charge of the Wild Hunt
(64129, 3, 7, 2792, 6399, 4832, 41079), -- Charge of the Wild Hunt
(64129, 3, 6, 2820, 6432, 4823, 41079), -- Charge of the Wild Hunt
(64129, 3, 5, 2880, 6457, 4835, 41079), -- Charge of the Wild Hunt
(64129, 3, 4, 2956, 6464, 4835, 41079), -- Charge of the Wild Hunt
(64129, 3, 3, 3045, 6198, 4829, 41079), -- Charge of the Wild Hunt
(64129, 3, 2, 3068, 6119, 4824, 41079), -- Charge of the Wild Hunt
(64129, 3, 1, 3067, 6114, 4824, 41079), -- Charge of the Wild Hunt
(64129, 3, 0, 2865, 5955, 4806, 41079), -- Charge of the Wild Hunt
(64129, 2, 0, 3329, 5870, 4905, 41079), -- Charge of the Wild Hunt
(64129, 1, 0, 3329, 5870, 4905, 41079), -- Charge of the Wild Hunt
(64129, 0, 0, 3330, 5867, 4905, 41079), -- Charge of the Wild Hunt
(14134, 2, 0, 2547, -4862, 146, 41079), -- The Captain's Logs
(14134, 1, 11, 2507, -4950, 145, 41079), -- The Captain's Logs
(14134, 1, 10, 2517, -4910, 145, 41079), -- The Captain's Logs
(14134, 1, 9, 2527, -4890, 145, 41079), -- The Captain's Logs
(14134, 1, 8, 2552, -4870, 145, 41079), -- The Captain's Logs
(14134, 1, 7, 2578, -4875, 145, 41079), -- The Captain's Logs
(14134, 1, 6, 2603, -4900, 145, 41079), -- The Captain's Logs
(14134, 1, 5, 2613, -4925, 145, 41079), -- The Captain's Logs
(14134, 1, 4, 2623, -4955, 145, 41079), -- The Captain's Logs
(14134, 1, 3, 2603, -4980, 145, 41079), -- The Captain's Logs
(14134, 1, 2, 2578, -4980, 145, 41079), -- The Captain's Logs
(14134, 1, 1, 2547, -4980, 145, 41079), -- The Captain's Logs
(14134, 1, 0, 2507, -4980, 145, 41079), -- The Captain's Logs
(14134, 0, 0, 2547, -4837, 146, 41079), -- The Captain's Logs
(13166, 3, 0, 2375, -5651, 382, 41079), -- The Battle For The Ebon Hold
(13166, 2, 9, 2404, -5581, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 8, 2425, -5559, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 7, 2441, -5548, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 6, 2471, -5534, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 5, 2495, -5558, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 4, 2523, -5604, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 3, 2495, -5627, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 2, 2478, -5639, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 1, 2449, -5652, 421, 41079), -- The Battle For The Ebon Hold
(13166, 2, 0, 2374, -5661, 382, 41079), -- The Battle For The Ebon Hold
(13166, 1, 0, 2457, -5591, 414, 41079), -- The Battle For The Ebon Hold
(13166, 0, 0, 2375, -5651, 382, 41079), -- The Battle For The Ebon Hold
(50786, 2, 0, 1695, 97, 0, 41079), -- Revenge of Krag'wa
(50786, 1, 11, 1442, 40, 1, 41079), -- Revenge of Krag'wa
(50786, 1, 10, 1374, 91, 1, 41079), -- Revenge of Krag'wa
(50786, 1, 9, 1371, 100, 1, 41079), -- Revenge of Krag'wa
(50786, 1, 8, 1409, 274, 1, 41079), -- Revenge of Krag'wa
(50786, 1, 7, 1558, 323, 4, 41079), -- Revenge of Krag'wa
(50786, 1, 6, 1595, 318, 5, 41079), -- Revenge of Krag'wa
(50786, 1, 5, 1661, 299, 5, 41079), -- Revenge of Krag'wa
(50786, 1, 4, 1697, 263, 7, 41079), -- Revenge of Krag'wa
(50786, 1, 3, 1756, 166, 14, 41079), -- Revenge of Krag'wa
(50786, 1, 2, 1750, 158, 14, 41079), -- Revenge of Krag'wa
(50786, 1, 1, 1628, 62, 0, 41079), -- Revenge of Krag'wa
(50786, 1, 0, 1453, 39, 1, 41079), -- Revenge of Krag'wa
(50786, 0, 0, 1694, 93, -1, 41079), -- Revenge of Krag'wa
(38235, 4, 0, 2387, 6914, 110, 41079), -- Solid as a Rock
(38235, 3, 0, 2199, 7194, 58, 41079), -- Solid as a Rock
(38235, 2, 0, 2171, 7049, 71, 41079), -- Solid as a Rock
(38235, 1, 0, 2374, 7168, 71, 41079), -- Solid as a Rock
(38235, 0, 0, 2387, 6914, 110, 41079), -- Solid as a Rock
(38147, 2, 0, 1729, 6832, 56, 41079), -- Entangled Dreams
(38147, 1, 0, 1633, 6876, -21, 41079), -- Entangled Dreams
(38147, 0, 0, 1965, 6911, 56, 41079), -- Entangled Dreams
(38246, 2, 0, 1858, 7057, 40, 41079), -- Totemic Call
(38246, 1, 0, 1710, 6913, 26, 41079), -- Totemic Call
(38246, 0, 0, 1855, 6939, 41, 41079), -- Totemic Call
(38455, 2, 0, 1940, 6902, 52, 41079), -- Frenzied Furbolgs
(38455, 1, 9, 1718, 6920, 32, 41079), -- Frenzied Furbolgs
(38455, 1, 8, 1722, 6963, 36, 41079), -- Frenzied Furbolgs
(38455, 1, 7, 1725, 6968, 36, 41079), -- Frenzied Furbolgs
(38455, 1, 6, 1750, 7003, 70, 41079), -- Frenzied Furbolgs
(38455, 1, 5, 1851, 7094, 62, 41079), -- Frenzied Furbolgs
(38455, 1, 4, 1856, 7095, 67, 41079), -- Frenzied Furbolgs
(38455, 1, 3, 1896, 6869, 68, 41079), -- Frenzied Furbolgs
(38455, 1, 2, 1888, 6850, 32, 41079), -- Frenzied Furbolgs
(38455, 1, 1, 1859, 6834, 28, 41079), -- Frenzied Furbolgs
(38455, 1, 0, 1848, 6829, 28, 41079), -- Frenzied Furbolgs
(38455, 0, 0, 1940, 6902, 52, 41079), -- Frenzied Furbolgs
(39731, 10, 0, 1458, 1411, 0, 41079), -- The Tranquil Forest
(39731, 9, 0, 1003, 1095, 0, 41079), -- The Tranquil Forest
(39731, 8, 0, 1232, 1344, 0, 41079), -- The Tranquil Forest
(39731, 7, 0, 769, 3580, 0, 41079), -- The Tranquil Forest
(39731, 6, 0, 2376, -5320, 0, 41079), -- The Tranquil Forest
(39731, 5, 0, 4022, 7289, 0, 41079), -- The Tranquil Forest
(39731, 4, 0, 4553, 5244, 0, 41079), -- The Tranquil Forest
(39731, 3, 0, -944, 4707, 0, 41079), -- The Tranquil Forest
(39731, 2, 0, 1083, 7229, 0, 41079), -- The Tranquil Forest
(39731, 1, 0, 3087, 819, 0, 41079), -- The Tranquil Forest
(39731, 0, 0, -826, 4294, 746, 41079), -- The Tranquil Forest
(40996, 1, 0, -956, 4548, -88, 41079), -- Delegation
(40996, 0, 0, -890, 4560, -90, 41079), -- Delegation
(42503, 0, 0, -935, 4560, -88, 41079), -- Codebreaker
(65020, 2, 0, 3298, 5812, 4900, 41079), -- Practical Applications
(65020, 1, 0, 3296, 5799, 4900, 41079), -- Practical Applications
(65020, 0, 0, 3298, 5812, 4900, 41079), -- Practical Applications
(51743, 2, 0, 78, 3288, 0, 40906), -- More Valuable Than Gold
(51743, 1, 11, 35, 3198, 233, 40906), -- More Valuable Than Gold
(51743, 1, 10, -5, 3261, 191, 40906), -- More Valuable Than Gold
(51743, 1, 9, -9, 3269, 191, 40906), -- More Valuable Than Gold
(51743, 1, 8, -12, 3280, 190, 40906), -- More Valuable Than Gold
(51743, 1, 7, -19, 3309, 183, 40906), -- More Valuable Than Gold
(51743, 1, 6, -19, 3312, 183, 40906), -- More Valuable Than Gold
(51743, 1, 5, 112, 3378, 222, 40906), -- More Valuable Than Gold
(51743, 1, 4, 117, 3373, 222, 40906), -- More Valuable Than Gold
(51743, 1, 3, 162, 3281, 234, 40906), -- More Valuable Than Gold
(51743, 1, 2, 159, 3268, 240, 40906), -- More Valuable Than Gold
(51743, 1, 1, 96, 3210, 213, 40906), -- More Valuable Than Gold
(51743, 1, 0, 40, 3190, 233, 40906), -- More Valuable Than Gold
(51743, 0, 6, 40, 3206, 235, 40906), -- More Valuable Than Gold
(51743, 0, 5, 29, 3215, 240, 40906), -- More Valuable Than Gold
(51743, 0, 4, -12, 3270, 191, 40906), -- More Valuable Than Gold
(51743, 0, 3, -2, 3309, 185, 40906), -- More Valuable Than Gold
(51743, 0, 2, 112, 3370, 222, 40906), -- More Valuable Than Gold
(51743, 0, 1, 160, 3273, 234, 40906), -- More Valuable Than Gold
(51743, 0, 0, 73, 3203, 218, 40906); -- More Valuable Than Gold

UPDATE `quest_poi_points` SET `VerifiedBuild`=42010 WHERE (`QuestID`=63964 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=63964 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=63964 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60565 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=62633 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=41793 WHERE (`QuestID`=62633 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=41488 WHERE (`QuestID`=57639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=41079 WHERE (`QuestID`=59850 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=59850 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59850 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=12715 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=12715 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=41031 WHERE (`QuestID`=57639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60565 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40944 WHERE (`QuestID`=60565 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=60565 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60444 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60444 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60444 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=40906 WHERE (`QuestID`=60048 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60048 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_greeting` WHERE (`ID`=7623 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(7623, 0, 1, 0, 'Using Stonard as our base of operations in the swamps gives us a decided advantage in exploratory missions and offensive strikes.', 40966); -- 7623

UPDATE `quest_greeting` SET `VerifiedBuild`=42010 WHERE (`Type`=0 AND `ID` IN (178829,178228,164741));
UPDATE `quest_greeting` SET `VerifiedBuild`=41488 WHERE (`Type`=0 AND `ID` IN (178228,178829));
UPDATE `quest_greeting` SET `VerifiedBuild`=41359 WHERE (`ID`=178829 AND `Type`=0);
UPDATE `quest_greeting` SET `VerifiedBuild`=41079 WHERE (`ID`=178228 AND `Type`=0);
UPDATE `quest_greeting` SET `VerifiedBuild`=40966 WHERE (`ID`=178829 AND `Type`=0);
UPDATE `quest_greeting` SET `VerifiedBuild`=40944 WHERE (`Type`=0 AND `ID` IN (178829,164741));

DELETE FROM `quest_details` WHERE `ID` IN (8873 /*The Lunar Festival*/, 24629 /*A Perfect Puff of Perfume*/, 24536 /*Something Stinks*/, 64271 /*A More Civilized Way*/, 63781 /*Mawsworn Battle Plans*/, 64292 /*Maelie, The Wanderer*/, 63972 /*Just Don't Ask Me to Spell It*/, 63974 /*That's Going to Sting*/, 24745 /*Something is in the Air (and it Ain't Love)*/, 25820 /*A Mother's Worries*/, 62200 /*Functioning Anima Core*/, 64430 /*Spill the Tea*/, 64089 /*Teas and Tinctures*/, 59951 /*A Druid's Form*/, 62435 /*Stag Soul*/, 63836 /*Fangcrack's Fan Club*/, 63956 /*Sealed Secrets*/, 65026 /*Owl Soul*/, 64710 /*Whispering Felflame Crystal*/, 14383 /*The Terrible Tinkers of the Ruined Reaches*/, 14385 /*Azsharite Experiment Number One*/, 14377 /*Befriending Giants*/, 14422 /*Raptor Raptor Rocket*/, 14408 /*Nine's Plan*/, 14371 /*A Gigantic Snack*/, 14370 /*Mysterious Azsharite*/, 14310 /*Segmentation Fault: Core Dumped*/, 14442 /*My Favorite Subject*/, 14322 /*Bad Science! Bad!*/, 14308 /*When Science Attacks*/, 14424 /*Need More Science*/, 14423 /*Dozercism*/, 14216 /*Mystery of the Sarcen Stone*/, 14215 /*Memories of the Dead*/, 14209 /*Gunk in the Trunk*/, 14202 /*Survey the Lakeshore*/, 14201 /*A Thousand Stories in the Sand*/, 24453 /*Private Chat*/, 24452 /*Profitability Scouting*/, 14472 /*In The Face!*/, 14471 /*First Degree Mortar*/, 14470 /*Military Breakthrough*/, 14469 /*Hand-me-downs*/, 14155 /*Arborcide*/, 14146 /*Defend the Gates!*/, 14135 /*Up a Tree*/, 14468 /*Another Warm Body*/, 14194 /*Refleshification*/, 14192 /*Prismbreak*/, 14190 /*The Perfect Prism*/, 64532 /*The Final Relics*/, 65020 /*Practical Applications*/, 64282 /*Full of Surprises*/, 63920 /*Enigmatic Decrypting Device*/, 63914 /*Cipher of Understanding*/, 63610 /*Mammoth Soul*/, 64129 /*Charge of the Wild Hunt*/, 63778 /*We Move Forward*/, 14165 /*Stone Cold*/, 14161 /*Basilisk Bashin'*/, 14197 /*A Quota to Meet*/, 14128 /*Return of the Highborne?*/, 14127 /*Return of the Highborne?*/, 14134 /*The Captain's Logs*/, 14117 /*The Eyes of Ashenvale*/, 14118 /*Venison for the Troops*/, 14129 /*Runaway Shredder!*/, 13189 /*Saurfang's Blessing*/, 12739 /*A Special Surprise*/, 40997 /*Lethal Efficiency*/, 40996 /*Delegation*/, 40950 /*Honoring Success*/, 42627 /*The Unseen Blade*/, 42568 /*Preparation*/, 42539 /*Cloak and Dagger*/, 42503 /*Codebreaker*/, 42502 /*No Sanctuary*/, 42501 /*Finishing the Job*/, 47591 /*Wanna Buy a Lamp?*/, 65467 /*Turkey Soul*/, 65266 /*Lost Research*/, 10279 /*To The Master's Lair*/, 13432 /*The Vials of Eternity*/, 64599 /*Sanctum of Domination - Damned If You Don't*/, 65090 /*Return More Lost Souls*/, 24655 /*Something Stinks*/, 30112 /*A Score to Settle*/, 13206 /*Disarmament*/, 11262 /*Ingvar Must Die!*/, 65105 /*Return More Lost Souls*/, 13095 /*Have They No Shame?*/, 60097 /*Wrath of the Lich King: To Northrend!*/, 29681 /*Maximum Security Breakout*/, 29675 /*Hey There Dalliah*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8873, 0, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Lunar Festival
(24629, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- A Perfect Puff of Perfume
(24536, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Something Stinks
(64271, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- A More Civilized Way
(63781, 6, 11, 378, 0, 0, 0, 0, 0, 42010), -- Mawsworn Battle Plans
(64292, 0, 0, 0, 0, 0, 0, 0, 0, 42010), -- Maelie, The Wanderer
(63972, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Just Don't Ask Me to Spell It
(63974, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- That's Going to Sting
(24745, 0, 0, 0, 0, 0, 0, 0, 0, 42010), -- Something is in the Air (and it Ain't Love)
(25820, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- A Mother's Worries
(62200, 0, 0, 0, 0, 0, 0, 0, 0, 42010), -- Functioning Anima Core
(64430, 0, 0, 0, 0, 0, 0, 0, 0, 41793), -- Spill the Tea
(64089, 0, 0, 0, 0, 0, 0, 0, 0, 41793), -- Teas and Tinctures
(59951, 2, 1, 0, 0, 0, 0, 0, 0, 41488), -- A Druid's Form
(62435, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Stag Soul
(63836, 1, 0, 0, 0, 0, 0, 0, 0, 41488), -- Fangcrack's Fan Club
(63956, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Sealed Secrets
(65026, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Owl Soul
(64710, 1, 5, 0, 0, 0, 0, 0, 0, 41359), -- Whispering Felflame Crystal
(14383, 388, 5, 0, 0, 0, 0, 0, 0, 41359), -- The Terrible Tinkers of the Ruined Reaches
(14385, 1, 5, 0, 0, 0, 0, 0, 0, 41359), -- Azsharite Experiment Number One
(14377, 396, 5, 0, 0, 0, 0, 0, 0, 41359), -- Befriending Giants
(14422, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Raptor Raptor Rocket
(14408, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Nine's Plan
(14371, 1, 273, 0, 0, 0, 0, 0, 0, 41359), -- A Gigantic Snack
(14370, 5, 6, 0, 0, 0, 0, 0, 0, 41359), -- Mysterious Azsharite
(14310, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Segmentation Fault: Core Dumped
(14442, 5, 6, 0, 0, 0, 0, 0, 0, 41359), -- My Favorite Subject
(14322, 5, 0, 0, 0, 0, 0, 0, 0, 41359), -- Bad Science! Bad!
(14308, 5, 15, 0, 0, 0, 0, 0, 0, 41359), -- When Science Attacks
(14424, 18, 5, 0, 0, 0, 0, 0, 0, 41359), -- Need More Science
(14423, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Dozercism
(14216, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Mystery of the Sarcen Stone
(14215, 432, 1, 0, 0, 0, 0, 0, 0, 41359), -- Memories of the Dead
(14209, 6, 274, 0, 0, 0, 0, 0, 0, 41359), -- Gunk in the Trunk
(14202, 275, 25, 0, 0, 0, 0, 0, 0, 41359), -- Survey the Lakeshore
(14201, 1, 273, 0, 0, 0, 0, 0, 0, 41359), -- A Thousand Stories in the Sand
(24453, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Private Chat
(24452, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Profitability Scouting
(14472, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- In The Face!
(14471, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- First Degree Mortar
(14470, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Military Breakthrough
(14469, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Hand-me-downs
(14155, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Arborcide
(14146, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Defend the Gates!
(14135, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Up a Tree
(14468, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- Another Warm Body
(14194, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Refleshification
(14192, 0, 0, 0, 0, 0, 0, 0, 0, 41359), -- Prismbreak
(14190, 1, 0, 0, 0, 0, 0, 0, 0, 41359), -- The Perfect Prism
(64532, 1, 1, 0, 0, 0, 2000, 0, 0, 41079), -- The Final Relics
(65020, 1, 1, 0, 0, 0, 2000, 0, 0, 41079), -- Practical Applications
(64282, 1, 1, 0, 0, 0, 0, 0, 0, 41079), -- Full of Surprises
(63920, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Enigmatic Decrypting Device
(63914, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Cipher of Understanding
(63610, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Mammoth Soul
(64129, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Charge of the Wild Hunt
(63778, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- We Move Forward
(14165, 1, 0, 0, 0, 0, 0, 0, 0, 41079), -- Stone Cold
(14161, 1, 6, 0, 0, 0, 0, 0, 0, 41079), -- Basilisk Bashin'
(14197, 6, 1, 0, 0, 0, 0, 0, 0, 41079), -- A Quota to Meet
(14128, 1, 25, 0, 0, 0, 0, 0, 0, 41079), -- Return of the Highborne?
(14127, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Return of the Highborne?
(14134, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- The Captain's Logs
(14117, 274, 1, 0, 0, 0, 0, 0, 0, 41079), -- The Eyes of Ashenvale
(14118, 1, 0, 0, 0, 0, 0, 0, 0, 41079), -- Venison for the Troops
(14129, 6, 0, 0, 0, 0, 0, 0, 0, 41079), -- Runaway Shredder!
(13189, 1, 1, 0, 0, 0, 0, 0, 0, 41079), -- Saurfang's Blessing
(12739, 1, 1, 1, 1, 0, 0, 0, 0, 41079), -- A Special Surprise
(40997, 1, 0, 0, 0, 0, 0, 0, 0, 41079), -- Lethal Efficiency
(40996, 1, 1, 0, 0, 0, 0, 0, 0, 41079), -- Delegation
(40950, 1, 1, 0, 0, 0, 0, 0, 0, 41079), -- Honoring Success
(42627, 1, 1, 6, 0, 0, 0, 0, 0, 41079), -- The Unseen Blade
(42568, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Preparation
(42539, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Cloak and Dagger
(42503, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Codebreaker
(42502, 1, 1, 0, 0, 0, 0, 0, 0, 41079), -- No Sanctuary
(42501, 1, 1, 1, 0, 0, 0, 0, 0, 41079), -- Finishing the Job
(47591, 574, 0, 0, 0, 0, 0, 0, 0, 41079), -- Wanna Buy a Lamp?
(65467, 0, 0, 0, 0, 0, 0, 0, 0, 41079), -- Turkey Soul
(65266, 1, 1, 0, 0, 0, 2000, 0, 0, 41079), -- Lost Research
(10279, 0, 0, 0, 0, 0, 0, 0, 0, 41031), -- To The Master's Lair
(13432, 0, 0, 0, 0, 0, 0, 0, 0, 41031), -- The Vials of Eternity
(64599, 0, 0, 0, 0, 0, 0, 0, 0, 41031), -- Sanctum of Domination - Damned If You Don't
(65090, 1, 0, 0, 0, 0, 0, 0, 0, 40966), -- Return More Lost Souls
(24655, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Something Stinks
(30112, 6, 25, 0, 0, 0, 3000, 0, 0, 40944), -- A Score to Settle
(13206, 396, 0, 0, 0, 0, 0, 0, 0, 40944), -- Disarmament
(11262, 396, 396, 0, 0, 0, 500, 0, 0, 40944), -- Ingvar Must Die!
(65105, 1, 0, 0, 0, 0, 0, 0, 0, 40944), -- Return More Lost Souls
(13095, 0, 0, 0, 0, 0, 0, 0, 0, 40944), -- Have They No Shame?
(60097, 0, 0, 0, 0, 0, 0, 0, 0, 40944), -- Wrath of the Lich King: To Northrend!
(29681, 0, 0, 0, 0, 0, 0, 0, 0, 40944), -- Maximum Security Breakout
(29675, 0, 0, 0, 0, 0, 0, 0, 0, 40944); -- Hey There Dalliah

UPDATE `quest_details` SET `VerifiedBuild`=42010 WHERE `ID` IN (14483, 63964, 63780, 63935, 63952, 63968, 59004, 63774, 63772, 63625, 60257, 8867, 59773, 63753, 63664, 63773, 60420, 60384, 60457, 60156, 60154, 53883, 63834, 63835, 63842, 63788);
UPDATE `quest_details` SET `VerifiedBuild`=41793 WHERE `ID` IN (63787, 63784, 63794, 62633);
UPDATE `quest_details` SET `VerifiedBuild`=41488 WHERE `ID` IN (27108, 27107, 27113, 27112, 6984, 63621, 63669, 63455, 63773, 63772, 63787, 63780, 63965, 64104, 63961, 63837, 63834, 63842, 63789, 63784, 64070, 64432, 60420, 63945, 63968, 60154, 60152, 60151, 60150, 60149, 60148);
UPDATE `quest_details` SET `VerifiedBuild`=41359 WHERE `ID` IN (60381, 64194, 64101, 64043, 63935, 63790, 29658, 29659, 29685, 11490, 29687, 29686, 29684, 60382, 64017, 63936, 63934, 63955, 63973, 63951, 63968);
UPDATE `quest_details` SET `VerifiedBuild`=41323 WHERE `ID` IN (63783, 64101, 63961);
UPDATE `quest_details` SET `VerifiedBuild`=41079 WHERE `ID` IN (63787, 63782, 63791, 63621, 63669, 63455, 63773, 63772, 60123, 27850, 27076, 27070, 27071, 27068, 34673, 50335, 30984, 30983, 30969, 27848, 27844, 27842, 27847, 13166, 13165, 12801, 12800, 12779, 12778, 12757, 12756, 12755, 12754, 12751, 12738, 12727, 12725, 12724, 12723, 12717, 12716, 12720, 12722, 12719, 12715, 12714, 12706, 12701, 12700, 12698, 12697, 12687, 12679, 12733, 12680, 12678, 12670, 12850, 12657, 12641, 12636, 12848, 12842, 12619, 12593, 60436, 60388, 63841, 63839, 63835, 63833, 38655, 38662, 38641, 38377, 38322, 38225, 38235, 38147, 38144, 38145, 38143, 38246, 38922, 38455, 40573, 39384, 39383, 38381, 38142, 38382, 38384, 40122, 39861, 39731, 63783, 63780, 64070, 64432, 63957, 60384, 60452, 24852, 14452, 14449, 60431, 60420);
UPDATE `quest_details` SET `VerifiedBuild`=41031 WHERE `ID` IN (63828, 63853, 63859, 14483, 60431, 63858, 63753, 63669, 63455, 63772, 63625, 60457, 60460);
UPDATE `quest_details` SET `VerifiedBuild`=40966 WHERE `ID` IN (26593, 26597, 2278, 27681, 27682, 29317, 60399, 60417, 63945, 63973, 63970, 63969);
UPDATE `quest_details` SET `VerifiedBuild`=40944 WHERE `ID` IN (62627, 62600, 63135, 63945, 63970, 63973, 63969, 57918, 13207, 29850, 29848, 29860, 29861, 29862, 60444, 60410, 60431, 11905, 11973, 11911, 29536, 29537, 29535);
UPDATE `quest_details` SET `VerifiedBuild`=40906 WHERE `ID` IN (29575, 29573, 29574, 7926, 60248, 50303, 49933, 58122);
UPDATE `quest_details` SET `VerifiedBuild`=40871 WHERE `ID`=60456;


UPDATE `quest_template` SET `VerifiedBuild`=42010 WHERE `ID` IN (54837, 53294, 54243, 51109, 54367, 53225, 48739, 44189, 45656, 45651, 45657, 45654, 50324, 52865, 54858, 53325);
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0 WHERE `ID`=54394; -- Darkshore Donations: Stringy Loins
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0 WHERE `ID`=54394; -- Darkshore Donations: Stringy Loins
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=42010 WHERE `ID`=650; -- Ripple Recovery
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=42010 WHERE `ID`=5727; -- Hidden Enemies
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=42010 WHERE `ID`=7492; -- Camp Mojache
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0 WHERE `ID`=54394; -- Darkshore Donations: Stringy Loins
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0 WHERE `ID`=54394; -- Darkshore Donations: Stringy Loins
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41793 WHERE `ID`=1701; -- Fire Hardened Mail
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=4003; -- The Royal Rescue
UPDATE `quest_template` SET `FlagsEx`=32772, `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=32862; -- Battlefield: Barrens
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=1707; -- Water Pouch Bounty
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=1690; -- Wastewander Justice
UPDATE `quest_template` SET `VerifiedBuild`=41488 WHERE `ID` IN (3362, 8365, 1691, 53326, 54243);
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=2772; -- The World At Your Feet
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=2773; -- The Mithril Kid
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=8366; -- Southsea Shakedown
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=3161; -- Gahz'ridian
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=2771; -- A Good Head On Your Shoulders
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=813; -- Finding the Antidote
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=650; -- Ripple Recovery
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41488 WHERE `ID`=3122; -- Return to Witch Doctor Uzer'i
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=41359 WHERE `ID`=45570; -- In Safer Hands
UPDATE `quest_template` SET `VerifiedBuild`=41359 WHERE `ID`=41613;
UPDATE `quest_template` SET `VerifiedBuild`=41079 WHERE `ID` IN (39042, 41210, 41448);
UPDATE `quest_template` SET `RewardCurrencyID1`=0, `RewardCurrencyQty1`=0 WHERE `ID`=54368; -- Darkshore Donations: Unstable Temporal Time Shifter
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41031 WHERE `ID`=1690; -- Wastewander Justice
UPDATE `quest_template` SET `VerifiedBuild`=41031 WHERE `ID` IN (1691, 59851, 62584);
UPDATE `quest_template` SET `ContentTuningID`=999, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18446744073709551615, `QuestDescription`='This final task will be the most difficult of all, $n. You have faced and defeated both an Old God and the Lich King\'s General, but now you must face the hand of Sargeras.$B$BTake the staff to Stratholme. It is there that you will find a piece of consecrated earth: ground where the greatest knights of Lordaeron were murdered. Place the befouled staff upon the holy ground and prepare for an entity of immense power to break from within... Defeat the demonic being that controls the staff and return to me.', `QuestCompletionLog`='', `VerifiedBuild`=41031 WHERE `ID`=9270; -- Atiesh, Greatstaff of the Guardian
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41031 WHERE `ID`=1018; -- The New Frontier
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=41031 WHERE `ID`=7492; -- Camp Mojache
UPDATE `quest_template` SET `ContentTuningID`=464, `QuestSortID`=8567, `VerifiedBuild`=41488 WHERE `ID`=53282; -- Overgrown Anchor Weed
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=40944 WHERE `ID`=10094; -- The Codex of Blood
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=40944 WHERE `ID`=10178; -- Find Spy To'gun
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=40906 WHERE `ID`=1701; -- Fire Hardened Mail
UPDATE `quest_template` SET `VerifiedBuild`=40906 WHERE `ID` IN (53325, 53313);
UPDATE `quest_template` SET `ContentTuningID`=71, `RewardFactionCapIn1`=7, `RewardFactionCapIn2`=7, `RewardFactionCapIn3`=7, `RewardFactionCapIn4`=7, `RewardFactionCapIn5`=7, `AllowableRaces`=18446744073709551615, `VerifiedBuild`=40906 WHERE `ID`=14439; -- Journey into Thunder Bluff
UPDATE `quest_template` SET `Expansion`=-2, `VerifiedBuild`=40906 WHERE `ID`=5088; -- Arikara

DELETE FROM `quest_objectives` WHERE `ID` IN (262399 /*262399*/, 262398 /*262398*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(262399, 9270, 1, 1, 1, 22737, 1, 0, 0, 0, '', 41031), -- 262399
(262398, 9270, 0, 0, 0, 16387, 1, 0, 0, 0, 'Atiesh Cleansed', 41031); -- 262398

UPDATE `quest_objectives` SET `VerifiedBuild`=42010 WHERE `ID` IN (388273, 387961, 341063, 386584, 334771, 334770, 387084, 387030, 340970, 292845, 286370, 288304, 288293, 288309, 288300, 312218, 312216, 312208, 312204, 387945, 340131, 388373, 388372, 388393, 341123);
UPDATE `quest_objectives` SET `VerifiedBuild`=41793 WHERE `ID` IN (288304, 288293, 288309, 288300, 255591, 255590, 255589, 255588);
UPDATE `quest_objectives` SET `VerifiedBuild`=41488 WHERE `ID` IN (257939, 270528, 270527, 270526, 270525, 256121, 256109, 256108, 257200, 257199, 256214, 256213, 252322, 252321, 255806, 255805, 255804, 255803, 255649, 256003, 256002, 256001, 257102, 256083, 256082, 254701, 256788, 341052, 341125, 341040, 386584, 341087);
UPDATE `quest_objectives` SET `VerifiedBuild`=41359 WHERE `ID` IN (286370, 282568);
UPDATE `quest_objectives` SET `VerifiedBuild`=41079 WHERE `ID` IN (279135, 387032, 282026, 282388);
UPDATE `quest_objectives` SET `VerifiedBuild`=41031 WHERE `ID` IN (282146, 256109, 256108, 256003, 256002, 256001, 406585, 408000, 408001, 387961);
UPDATE `quest_objectives` SET `VerifiedBuild`=40906 WHERE `ID` IN (387062, 255591, 255590, 255589, 255588, 341123, 341096, 282438, 257521, 257520);
UPDATE `quest_objectives` SET `VerifiedBuild`=40871 WHERE `ID`=387062;


UPDATE `quest_visual_effect` SET `VerifiedBuild`=42010 WHERE (`Index`=0 AND `ID` IN (341063,386584,334771,334770,286370,288304,288293,288309,288300,312218,312216,312208,312204,340131,388372,341123)) OR (`Index`=1 AND `ID` IN (334771,288309,340131)) OR (`Index`=3 AND `ID`=340131) OR (`Index`=2 AND `ID`=340131);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=41793 WHERE (`Index`=0 AND `ID` IN (288304,288293,288309,288300)) OR (`Index`=1 AND `ID`=288309);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=41488 WHERE (`Index`=0 AND `ID` IN (270528,270527,270526,270525,341052,341125,341040,386584,341087));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=41359 WHERE (`ID`=286370 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=41079 WHERE (`ID`=282026 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=41031 WHERE (`Index`=0 AND `ID` IN (282146,406585,408000));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=40906 WHERE (`Index`=0 AND `ID` IN (341123,341096,282438));

