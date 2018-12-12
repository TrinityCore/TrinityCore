

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278192 /*Sethrak Weapon*/, 278190 /*Sethrak Weapon*/, 278193 /*Sethrak Weapon*/, 278191 /*Sethrak Weapon*/, 277910 /*Sethrak Cage*/, 284411 /*Treasure Chest*/, 282461 /*Lightning Focus*/, 290783 /*Faithless Barrier*/, 290784 /*Faithless Barrier*/, 290756 /*Sethraliss Sight Stone*/, 282451 /*Rebirth Creed*/, 290757 /*Blood of the Fallen Loa*/, 290755 /*Skull of the First Skycaller*/, 282430 /*Fire*/, 278447 /*Faithless Trapper's Spear*/, 278368 /*Tattered Note*/, 281664 /*Faithless Supplies*/, 281667 /*Faithless Supplies*/, 278370 /*Skeleton*/, 290707 /*Suppression Spire*/, 287006 /*Faithless Weapon Rack*/, 252247 /*Instance Portal*/, 296579 /*Brian's Broken Compass*/, 296585 /*Damarcus' Backpack*/, 282645 /*Beastbreaker Cage*/, 276623 /*Rich Platinum Deposit*/, 284415 /*Treasure Chest*/, 282646 /*Mysterious Trashpile*/, 271869 /*Boiled Scorpid Blood*/, 278277 /*Sandy Tortillas*/, 278278 /*Box of Slightly Used Bandages*/, 278279 /*Very Uncomfortable Bed*/, 278276 /*Oasis Water*/, 278242 /*Whistlebloom Juicy Fruit*/, 281559 /*Pterrordax Perch*/, 271810 /*Boiled Scorpid Blood*/, 271793 /*Grenja*/, 280525 /*Zandalari Drum*/, 271792 /*Man'zul*/, 271795 /*Volni*/, 279362 /*[DNT] Bottle*/, 271847 /*Cheese 6HU_INN_CHEESE01.m2*/, 271794 /*Zulsan*/, 284413 /*Treasure Chest*/, 271134 /*Man'zul*/, 271745 /*Banana*/, 287442 /*Wanted: Cobra Excursion Participants*/, 281863 /*Magic Barrier*/, 271615 /*Plank 7SG_SEAGIANT_DEBRIS_PLANK01.M2 (Scale 0.5)*/, 292597 /*Cooking Cauldron*/, 271741 /*Grenja*/, 271620 /*Bucket 6HU_PETSTABLE_EMPTYBUCKET03.M2  (Scale 1.5)*/, 271846 /*7XP_FishSkeleton_Huge_Red01.m2*/, 271111 /*Drum*/, 271617 /*Plank 6HU_LUMBERMILL_WOODENPLANK02.M2*/, 271848 /*Dynamite Bundle*/, 271744 /*Volni*/, 271568 /*Skull Candle*/, 297495 /*Tales of de Loa: Akunda*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(278192, 0, 4), -- Sethrak Weapon
(278190, 0, 4), -- Sethrak Weapon
(278193, 0, 4), -- Sethrak Weapon
(278191, 0, 4), -- Sethrak Weapon
(277910, 0, 262144), -- Sethrak Cage
(284411, 0, 278528), -- Treasure Chest
(282461, 0, 262144), -- Lightning Focus
(290783, 0, 32), -- Faithless Barrier
(290784, 0, 32), -- Faithless Barrier
(290756, 0, 4), -- Sethraliss Sight Stone
(282451, 0, 4), -- Rebirth Creed
(290757, 0, 4), -- Blood of the Fallen Loa
(290755, 0, 4), -- Skull of the First Skycaller
(282430, 1375, 32), -- Fire
(278447, 0, 4), -- Faithless Trapper's Spear
(278368, 0, 4), -- Tattered Note
(281664, 0, 262144), -- Faithless Supplies
(281667, 0, 262144), -- Faithless Supplies
(278370, 0, 8192), -- Skeleton
(290707, 0, 262144), -- Suppression Spire
(287006, 0, 4), -- Faithless Weapon Rack
(252247, 0, 32), -- Instance Portal
(296579, 0, 2113568), -- Brian's Broken Compass
(296585, 0, 2113568), -- Damarcus' Backpack
(282645, 0, 262144), -- Beastbreaker Cage
(276623, 94, 278528), -- Rich Platinum Deposit
(284415, 0, 278528), -- Treasure Chest
(282646, 0, 262144), -- Mysterious Trashpile
(271869, 0, 262144), -- Boiled Scorpid Blood
(278277, 0, 262144), -- Sandy Tortillas
(278278, 0, 262144), -- Box of Slightly Used Bandages
(278279, 0, 262144), -- Very Uncomfortable Bed
(278276, 0, 262144), -- Oasis Water
(278242, 0, 2113540), -- Whistlebloom Juicy Fruit
(281559, 0, 8192), -- Pterrordax Perch
(271810, 0, 262144), -- Boiled Scorpid Blood
(271793, 0, 2113540), -- Grenja
(280525, 0, 262144), -- Zandalari Drum
(271792, 0, 2113540), -- Man'zul
(271795, 0, 2113540), -- Volni
(279362, 114, 0), -- [DNT] Bottle
(271847, 114, 0), -- Cheese 6HU_INN_CHEESE01.m2
(271794, 0, 2113540), -- Zulsan
(284413, 0, 278528), -- Treasure Chest
(271134, 0, 262144), -- Man'zul
(271745, 114, 0), -- Banana
(287442, 0, 4), -- Wanted: Cobra Excursion Participants
(281863, 0, 8192), -- Magic Barrier
(271615, 114, 0), -- Plank 7SG_SEAGIANT_DEBRIS_PLANK01.M2 (Scale 0.5)
(292597, 35, 0), -- Cooking Cauldron
(271741, 0, 262144), -- Grenja
(271620, 114, 0), -- Bucket 6HU_PETSTABLE_EMPTYBUCKET03.M2  (Scale 1.5)
(271846, 114, 0), -- 7XP_FishSkeleton_Huge_Red01.m2
(271111, 0, 262144), -- Drum
(271617, 114, 0), -- Plank 6HU_LUMBERMILL_WOODENPLANK02.M2
(271848, 114, 0), -- Dynamite Bundle
(271744, 0, 262144), -- Volni
(271568, 114, 0), -- Skull Candle
(297495, 0, 262144); -- Tales of de Loa: Akunda

DELETE FROM `scene_template` WHERE (`SceneId`=2134 AND `ScriptPackageID`=2077) OR (`SceneId`=1928 AND `ScriptPackageID`=2064);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(2134, 11, 2077),
(1928, 27, 2064);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (50702 /*-Unknown-*/, 50904 /*-Unknown-*/, 50617 /*-Unknown-*/, 50751 /*-Unknown-*/, 49437 /*-Unknown-*/, 50757 /*-Unknown-*/, 49668 /*-Unknown-*/, 50550 /*-Unknown-*/, 50752 /*-Unknown-*/, 50750 /*-Unknown-*/, 49003 /*-Unknown-*/, 50748 /*-Unknown-*/, 49141 /*-Unknown-*/, 48329 /*-Unknown-*/, 50746 /*-Unknown-*/, 49666 /*-Unknown-*/, 49665 /*-Unknown-*/, 49667 /*-Unknown-*/, 49664 /*-Unknown-*/, 50745 /*-Unknown-*/, 49662 /*-Unknown-*/, 48330 /*-Unknown-*/, 49139 /*-Unknown-*/, 48331 /*-Unknown-*/, 48335 /*-Unknown-*/, 49001 /*-Unknown-*/, 48332 /*-Unknown-*/, 48334 /*-Unknown-*/, 48840 /*-Unknown-*/, 48322 /*-Unknown-*/, 48321 /*-Unknown-*/, 47564 /*-Unknown-*/, 48320 /*-Unknown-*/, 47638 /*-Unknown-*/, 50328 /*-Unknown-*/, 51718 /*-Unknown-*/, 47503 /*-Unknown-*/, 51164 /*-Unknown-*/, 47502 /*-Unknown-*/, 51717 /*-Unknown-*/, 47498 /*-Unknown-*/, 47501 /*-Unknown-*/, 47497 /*-Unknown-*/, 48327 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50702, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s a miracle we survived...', 27843), -- -Unknown-
(50904, 1, 0, 0, 0, 0, 0, 0, 0, 'Jakra\'zet has already begun the ritual. We must stop him before it\'s too late!', 27843), -- -Unknown-
(50617, 1, 0, 0, 0, 0, 0, 0, 0, 'We must hurry. Your friends are already inside!', 27843), -- -Unknown-
(50751, 1, 0, 0, 0, 0, 0, 0, 0, 'We\'re too late. The keys are gone. \n\nSethraliss... What have I done?', 27843), -- -Unknown-
(49437, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ve heard the other vulpera whisper Shath\'kar\'s name in fear. Thank you for ridding us of him.', 27843), -- -Unknown-
(50757, 1, 0, 0, 0, 0, 0, 0, 0, 'The Faithless will be nursing that wound for awhile. Well done.', 27843), -- -Unknown-
(49668, 1, 0, 0, 0, 0, 0, 0, 0, 'The fires are spreading quickly. Let\'s hurry, while the Faithless are distracted.', 27843), -- -Unknown-
(50550, 1, 0, 0, 0, 0, 0, 0, 0, 'Do not waste time mourning my old friend now. His foolish crusade has left us a larger problem that demands our full, immediate attention.', 27843), -- -Unknown-
(50752, 1, 0, 0, 0, 0, 0, 0, 0, 'Incredible! I remember when some of these were first found...\n\nYou\'ve done all followers of Sethraliss a kindness this day, $p.', 27843), -- -Unknown-
(50750, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent. Now we may focus on Emperor Korthek without distractions.', 27843), -- -Unknown-
(49003, 1, 0, 0, 0, 0, 0, 0, 0, 'Emperor Korthek is certainly on his way to us by now. We must prepare quickly.', 27843), -- -Unknown-
(50748, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent! Rakjan appears willing to aid us, so we will certainly make good use of these.', 27843), -- -Unknown-
(49141, 1, 0, 0, 0, 0, 0, 0, 0, '<Vorrik smiles as he takes the staff back from you.>\n\nThank you, $p. I must confess I was anxious for your return. It\'s been many years since this staff has left my side.\n\nMy trust in you was well placed, however. The staff is practically rippling with power.', 27843), -- -Unknown-
(48329, 0, 0, 0, 0, 0, 0, 0, 0, '<Rakjan lowers his head in respect.>', 27843), -- -Unknown-
(50746, 1, 0, 0, 0, 0, 0, 0, 0, 'I can hear the vulpera battle cries from here. It seems your friends have given us a window of opportunity. We musn\'t waste it.\n\nI have a plan.', 27843), -- -Unknown-
(49666, 396, 0, 0, 0, 0, 0, 0, 0, 'And that\'s just the start! Now the Faithless know who\'s coming for \'em.', 27843), -- -Unknown-
(49665, 396, 0, 0, 0, 0, 0, 0, 0, 'Look at my people fighting! The Faithless don\'t stand a chance!', 27843), -- -Unknown-
(49667, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, thank you, thank you!\n\nThese children have already experienced more hate and pain than anyone ever should. I\'ll make sure they feel love in equal measure.', 27843), -- -Unknown-
(49664, 1, 0, 0, 0, 0, 0, 0, 0, '$p?! We gotta stop meeting in places like this.$B$BActually, let\'s ALWAYS meet in places like this!$B$BYou up for killing some Faithless?', 27843), -- -Unknown-
(50745, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s unconventional, but I believe Sethraliss would be pleased to see her shrine used to protect innocents in need.$B$BAnd if these vulpera are fighting the Faithless, they will be useful allies.', 27843), -- -Unknown-
(49662, 396, 0, 0, 0, 0, 0, 0, 0, 'We are surrounded by Faithless out here, $p. We must move quickly.', 27843), -- -Unknown-
(48330, 1, 0, 0, 0, 0, 0, 0, 0, 'With Zak\'rajan out of the way, we\'ve got first claim on all the treasure he\'s been hoarding here!$B$BYou get your fair share, of course. A worker\'s worth his wage.', 27843), -- -Unknown-
(49139, 1, 0, 0, 0, 0, 0, 0, 0, 'You and I make a good team, $p.$B$BHave a little extra reward, on me.', 27843), -- -Unknown-
(48331, 1, 0, 0, 0, 0, 0, 0, 0, 'See? I told you that the soulcatcher totem would make it easy. A tool for every problem, I say.', 27843), -- -Unknown-
(48335, 1, 0, 0, 0, 0, 0, 0, 0, 'Not every treasure is gold, $p. We vulpera have learned to recognize value wherever it hides in Vol\'dun.', 27843), -- -Unknown-
(49001, 1, 0, 0, 0, 0, 0, 0, 0, 'Well, you\'re good at killing. I could tell that even from back here. Welcome to the crew.', 27843), -- -Unknown-
(48332, 1, 0, 0, 0, 0, 0, 0, 0, 'Can\'t say I\'ve seen someone carry that many stomachs at once.$B$BI don\'t know if I\'m impressed or disgusted.', 27843), -- -Unknown-
(48334, 1, 0, 0, 0, 0, 0, 0, 0, 'The golems are powered by souls? Hmm... $B$BWe\'re dealing with a very powerful enemy. We should take extra precautions.', 27843), -- -Unknown-
(48840, 661, 0, 0, 0, 0, 0, 0, 0, '<Kenzou looks skeptically at the leaf you handed him.>$B$BNo, I will not be going there. But are you looking for some real work?', 27843), -- -Unknown-
(48322, 1, 0, 0, 0, 0, 0, 0, 0, 'De Goldtusk Inn be open to all exiles. We stick together out here.', 27843), -- -Unknown-
(48321, 1, 0, 0, 0, 0, 0, 0, 0, 'Oh yeah, I can work with dis.', 27843), -- -Unknown-
(47564, 1, 0, 0, 0, 0, 0, 0, 0, 'Breakfast is served!', 27843), -- -Unknown-
(48320, 1, 0, 0, 0, 0, 0, 0, 0, 'Dere are still plenty of things for our guests to kill for recreation. At least now, dey won\'t be hunted on their way in.', 27843), -- -Unknown-
(47638, 1, 0, 0, 0, 0, 0, 0, 0, 'You are a Goldtusk now, $p. Welcome home.', 27843), -- -Unknown-
(50328, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank de loa dat de Sandfury didn\'t kill you and take dese.\n\nDe drinks are almost ready and dey really add the perfect flavor.', 27843), -- -Unknown-
(51718, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'ll just take me a moment to get the honey out of these.', 27843), -- -Unknown-
(47503, 1, 0, 0, 0, 0, 0, 0, 0, 'Dat\'ll teach de Sandfury to fear de Goldtusk Gang!', 27843), -- -Unknown-
(51164, 6, 1, 0, 0, 0, 3000, 0, 0, 'You killed de giant snake? Congratulations!\n\nGuess I\'d better update the brochure excursion list.', 27843), -- -Unknown-
(47502, 1, 0, 0, 0, 0, 0, 0, 0, 'Ya one of us now, $p.', 27843), -- -Unknown-
(51717, 1, 0, 0, 0, 0, 0, 0, 0, 'Rhan\'ka sent you? He still owes me for the last batch of honey I sold him!', 27843), -- -Unknown-
(47498, 22, 0, 0, 0, 0, 0, 0, 0, 'Thank de spirits you found Zulsan. Sandfury trolls kidnapped de rest of de gang!', 27843), -- -Unknown-
(47501, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ll hold onto dis blood until we can get back to de inn to make de drinks.\n\nDon\'t worry, I won\'t let you miss out on dem. I know you\'re excited to try my famous scorpid blood drinks!', 27843), -- -Unknown-
(47497, 1, 0, 0, 0, 0, 0, 0, 0, 'Don\'t mind half of what those trolls say. Dey don\'t really mean it.', 27843), -- -Unknown-
(48327, 1, 0, 0, 0, 0, 0, 0, 0, '<Rhan\'ka closely inspects the pineapple.>$B$B This... is... the perfect pineapple!', 27843); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=50551 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50551 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=50551 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50551 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50703 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50703 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50702 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=50702 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50702 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50904 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=50904 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50904 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50904 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50904 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50617 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=50617 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50617 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49437 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49437 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49437 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50757 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50757 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50757 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49669 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49669 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49669 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50805 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50805 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50805 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50751 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50751 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50550 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=50550 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50550 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50550 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50550 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50752 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50750 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50750 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50750 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49003 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49003 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49003 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49003 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49003 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49002 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49002 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49002 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48329 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48329 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48329 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50748 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=50748 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50748 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=50748 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49141 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49141 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49141 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=49141 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49668 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49668 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49668 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49668 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49668 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50746 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50746 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49666 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49666 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49666 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49665 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49665 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49665 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49665 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49667 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49667 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49667 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49664 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49664 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50745 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50745 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48330 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48330 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48330 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49139 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49139 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49139 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49139 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48331 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48331 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48331 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48335 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48335 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48335 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48332 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48332 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48332 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48334 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48334 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48334 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49001 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49001 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49001 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48840 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48840 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48322 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48320 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48320 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48320 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48321 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48321 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48321 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47564 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47564 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47564 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47638 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47638 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47638 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50328 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50328 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51718 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51718 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51718 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51717 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51717 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47503 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47503 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47503 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47502 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=47502 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47502 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47502 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47502 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47498 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47498 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47498 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47501 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47501 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47501 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51164 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=51164 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51164 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=51164 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=51164 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47497 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=47497 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47497 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47497 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47497 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(50551, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478230, 0, 27843), -- -Unknown-
(50551, 1, 2, 0, 333484, 67127, 1877, 1043, 0, 0, 0, 0, 1456853, 0, 27843), -- -Unknown-
(50551, 0, 1, 0, 333484, 67127, 1642, 864, 0, 2, 0, 62214, 0, 0, 27843), -- -Unknown-
(50551, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1478230, 0, 27843), -- -Unknown-
(50703, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477326, 0, 27843), -- -Unknown-
(50703, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 1578474, 0, 27843), -- -Unknown-
(50702, 1, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1473182, 0, 27843), -- -Unknown-
(50702, 0, 1, 0, 333569, 134781, 1642, 864, 0, 0, 0, 0, 1473659, 0, 27843), -- -Unknown-
(50702, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477326, 0, 27843), -- -Unknown-
(50904, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1482171, 0, 27843), -- -Unknown-
(50904, 0, 3, 2, 334274, 135737, 1642, 1009, 0, 0, 0, 0, 1483249, 0, 27843), -- -Unknown-
(50904, 0, 2, 1, 334273, 135694, 1642, 1009, 0, 0, 0, 0, 1483173, 0, 27843), -- -Unknown-
(50904, 0, 1, 0, 334236, 135664, 1642, 864, 0, 0, 0, 0, 1482171, 0, 27843), -- -Unknown-
(50904, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1473182, 0, 27843), -- -Unknown-
(50617, 1, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1469725, 0, 27843), -- -Unknown-
(50617, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478230, 0, 27843), -- -Unknown-
(50617, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1482171, 0, 27843), -- -Unknown-
(49437, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1409662, 0, 27843), -- -Unknown-
(49437, 0, 1, 0, 294662, 129754, 1642, 864, 0, 0, 0, 0, 1410582, 0, 27843), -- -Unknown-
(49437, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477681, 0, 27843), -- -Unknown-
(50757, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477698, 0, 27843), -- -Unknown-
(50757, 0, 1, 0, 333744, 129772, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50757, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477698, 0, 27843), -- -Unknown-
(49669, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477698, 0, 27843), -- -Unknown-
(49669, 0, 1, 0, 295058, 135042, 1642, 864, 0, 0, 0, 0, 1523725, 0, 27843), -- -Unknown-
(49669, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477698, 0, 27843), -- -Unknown-
(50805, 0, 2, 32, 0, 0, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(50805, 0, 1, 3, 334040, 140031, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(50805, 0, 0, 1, 333851, 282461, 1642, 864, 0, 0, 0, 0, 0, 1, 27843), -- -Unknown-
(50751, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479612, 0, 27843), -- -Unknown-
(50751, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1469725, 0, 27843), -- -Unknown-
(50550, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(50550, 0, 3, 1, 333888, 134601, 1642, 864, 0, 0, 0, 0, 1479609, 0, 27843), -- -Unknown-
(50550, 0, 2, 0, 333068, 135111, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(50550, 0, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479612, 0, 27843), -- -Unknown-
(50550, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479860, 0, 27843), -- -Unknown-
(50752, 0, 5, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(50752, 0, 4, 3, 336681, 160528, 1642, 864, 0, 0, 0, 0, 1478894, 0, 27843), -- -Unknown-
(50752, 0, 3, 2, 336680, 160527, 1642, 864, 0, 0, 0, 0, 1478895, 0, 27843), -- -Unknown-
(50752, 0, 2, 1, 336679, 160526, 1642, 864, 0, 0, 0, 0, 1478891, 0, 27843), -- -Unknown-
(50752, 0, 1, 0, 333710, 158722, 1642, 864, 0, 0, 0, 0, 1478896, 0, 27843), -- -Unknown-
(50752, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(50750, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(50750, 0, 1, 0, 333698, 135969, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50750, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(49003, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478284, 0, 27843), -- -Unknown-
(49003, 0, 3, 2, 294758, 135214, 1642, 864, 0, 0, 0, 0, 1478293, 0, 27843), -- -Unknown-
(49003, 0, 2, 1, 294754, 135186, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49003, 0, 1, 0, 294750, 129763, 1642, 864, 0, 0, 0, 0, 1412020, 0, 27843), -- -Unknown-
(49003, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1522075, 0, 27843), -- -Unknown-
(49002, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1412270, 0, 27843), -- -Unknown-
(49002, 0, 1, 0, 294703, 129848, 1642, 864, 0, 0, 0, 0, 1411847, 0, 27843), -- -Unknown-
(49002, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1412020, 0, 27843), -- -Unknown-
(48329, 0, 2, 1, 336618, 129881, 1642, 864, 0, 0, 0, 0, 1412020, 0, 27843), -- -Unknown-
(48329, 0, 1, 0, 336617, 138362, 1642, 864, 0, 0, 0, 0, 1514454, 0, 27843), -- -Unknown-
(48329, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1412020, 0, 27843), -- -Unknown-
(50748, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1478284, 0, 27843), -- -Unknown-
(50748, 0, 2, 0, 333691, 154896, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50748, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 63759, 1469230, 0, 27843), -- -Unknown-
(50748, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 63758, 1478284, 0, 27843), -- -Unknown-
(49141, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1469230, 0, 27843), -- -Unknown-
(49141, 0, 2, 0, 294697, 138337, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49141, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 63759, 1469230, 0, 27843), -- -Unknown-
(49141, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 63758, 1478284, 0, 27843), -- -Unknown-
(49668, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(49668, 0, 3, 2, 334060, 135454, 1642, 864, 0, 0, 0, 0, 1523495, 0, 27843), -- -Unknown-
(49668, 0, 2, 1, 334059, 135453, 1642, 864, 0, 0, 0, 0, 1523480, 0, 27843), -- -Unknown-
(49668, 0, 1, 0, 295035, 134564, 1642, 864, 0, 0, 0, 0, 1523428, 0, 27843), -- -Unknown-
(49668, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477698, 0, 27843), -- -Unknown-
(50746, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(50746, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1469230, 0, 27843), -- -Unknown-
(49666, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(49666, 0, 1, 0, 295008, 135348, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49666, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(49665, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(49665, 0, 2, 1, 334452, 159470, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49665, 0, 1, 0, 295001, 130354, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49665, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(49667, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1477681, 0, 27843), -- -Unknown-
(49667, 0, 1, 0, 295031, 130396, 1642, 864, 0, 0, 0, 0, 1417919, 0, 27843), -- -Unknown-
(49667, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1477681, 0, 27843), -- -Unknown-
(49664, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1469230, 0, 27843), -- -Unknown-
(49664, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1479410, 0, 27843), -- -Unknown-
(50745, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1510401, 0, 27843), -- -Unknown-
(50745, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1469230, 0, 27843), -- -Unknown-
(48330, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(48330, 0, 1, 0, 294552, 129434, 1642, 864, 0, 0, 0, 0, 1408391, 0, 27843), -- -Unknown-
(48330, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(49139, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(49139, 0, 2, 1, 294550, 129506, 1642, 864, 0, 0, 0, 0, 1418391, 0, 27843), -- -Unknown-
(49139, 0, 1, 0, 294549, 129507, 1642, 864, 0, 0, 0, 0, 1408414, 0, 27843), -- -Unknown-
(49139, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(48331, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408592, 0, 27843), -- -Unknown-
(48331, 0, 1, 0, 294546, 129530, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48331, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408592, 0, 27843), -- -Unknown-
(48335, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408596, 0, 27843), -- -Unknown-
(48335, 0, 1, 0, 294544, 153699, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48335, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408596, 0, 27843), -- -Unknown-
(48332, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(48332, 0, 1, 0, 294538, 154713, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48332, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408595, 0, 27843), -- -Unknown-
(48334, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408592, 0, 27843), -- -Unknown-
(48334, 0, 1, 0, 294540, 138923, 1642, 864, 0, 0, 0, 0, 1526422, 0, 27843), -- -Unknown-
(48334, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408592, 0, 27843), -- -Unknown-
(49001, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408596, 0, 27843), -- -Unknown-
(49001, 0, 1, 0, 294616, 129672, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49001, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408596, 0, 27843), -- -Unknown-
(48840, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(48840, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408596, 0, 27843), -- -Unknown-
(48322, 0, 6, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(48322, 0, 5, 4, 294471, 129328, 1642, 864, 0, 0, 0, 0, 1407034, 0, 27843), -- -Unknown-
(48322, 0, 4, 3, 294470, 129326, 1642, 864, 0, 0, 0, 0, 1407025, 0, 27843), -- -Unknown-
(48322, 0, 3, 2, 294469, 129327, 1642, 864, 0, 0, 0, 0, 1407026, 0, 27843), -- -Unknown-
(48322, 0, 2, 1, 294468, 129325, 1642, 864, 0, 0, 0, 0, 1407024, 0, 27843), -- -Unknown-
(48322, 0, 1, 0, 294467, 129324, 1642, 864, 0, 0, 0, 0, 1407253, 0, 27843), -- -Unknown-
(48322, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(48320, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1408078, 0, 27843), -- -Unknown-
(48320, 0, 1, 0, 294445, 133888, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48320, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1408078, 0, 27843), -- -Unknown-
(48321, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1407418, 0, 27843), -- -Unknown-
(48321, 0, 1, 0, 294447, 153593, 1642, 864, 0, 0, 0, 0, 1461146, 0, 27843), -- -Unknown-
(48321, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1407418, 0, 27843), -- -Unknown-
(47564, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1407420, 0, 27843), -- -Unknown-
(47564, 0, 1, 0, 290578, 151022, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47564, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1407420, 0, 27843), -- -Unknown-
(47638, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1463715, 0, 27843), -- -Unknown-
(47638, 0, 1, 0, 290855, 129282, 1642, 864, 0, 0, 0, 0, 1406968, 0, 27843), -- -Unknown-
(47638, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(50328, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1460785, 0, 27843), -- -Unknown-
(50328, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(51718, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1460785, 0, 27843), -- -Unknown-
(51718, 0, 1, 0, 336924, 157541, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51718, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1460785, 0, 27843), -- -Unknown-
(51717, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1524859, 0, 27843), -- -Unknown-
(51717, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1460785, 0, 27843), -- -Unknown-
(47503, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(47503, 0, 1, 0, 290514, 133924, 1642, 864, 0, 0, 0, 0, 1461836, 0, 27843), -- -Unknown-
(47503, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(47502, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(47502, 0, 3, 2, 290834, 151220, 1642, 864, 0, 0, 0, 0, 1337157, 0, 27843), -- -Unknown-
(47502, 0, 2, 1, 290833, 151219, 1642, 864, 0, 0, 0, 0, 1337156, 0, 27843), -- -Unknown-
(47502, 0, 1, 0, 290517, 151218, 1642, 864, 0, 0, 0, 0, 1337158, 0, 27843), -- -Unknown-
(47502, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(47498, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(47498, 0, 1, 0, 290510, 150916, 1642, 864, 0, 0, 0, 0, 1406124, 0, 27843), -- -Unknown-
(47498, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1524859, 0, 27843), -- -Unknown-
(47501, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(47501, 0, 1, 0, 290511, 150923, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47501, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1524859, 0, 27843), -- -Unknown-
(51164, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1492255, 0, 27843), -- -Unknown-
(51164, 0, 3, 0, 334933, 136593, 1642, 864, 0, 0, 0, 0, 1491769, 0, 27843), -- -Unknown-
(51164, 2, 2, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843), -- -Unknown-
(51164, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1352959, 0, 27843), -- -Unknown-
(51164, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1463715, 0, 27843), -- -Unknown-
(47497, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1463715, 0, 27843), -- -Unknown-
(47497, 0, 3, 2, 290509, 123645, 1642, 864, 0, 0, 0, 0, 1332974, 0, 27843), -- -Unknown-
(47497, 0, 2, 1, 290508, 123643, 1642, 864, 0, 0, 0, 0, 1331849, 0, 27843), -- -Unknown-
(47497, 0, 1, 0, 290507, 123644, 1642, 864, 0, 0, 0, 0, 1336298, 0, 27843), -- -Unknown-
(47497, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1336269, 0, 27843); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=50551 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50551 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50551 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50551 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50703 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50703 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50702 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50702 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50702 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50904 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=50904 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50904 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50904 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50904 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50617 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50617 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50617 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49437 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49437 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49437 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50757 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50757 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50757 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49669 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49669 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49669 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50805 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50805 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=7) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=6) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=5) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=4) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=3) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=2) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=1) OR (`QuestID`=50805 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50751 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50751 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50550 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=50550 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50550 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50550 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50550 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50752 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50750 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50750 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50750 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49003 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49003 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=49003 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49003 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49003 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49002 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49002 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49002 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48329 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48329 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48329 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50748 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=50748 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50748 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50748 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49141 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=49141 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49141 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49141 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49668 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49668 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49668 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49668 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49668 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50746 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50746 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49666 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=49666 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49666 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49665 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49665 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=49665 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=49665 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=49665 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=49665 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=49665 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49665 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49667 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49667 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49667 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49664 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49664 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50745 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50745 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48330 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48330 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48330 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49139 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49139 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49139 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49139 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48331 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48331 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48331 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48335 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48335 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48335 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48332 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48332 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48332 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48334 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48334 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48334 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49001 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=49001 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49001 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48840 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48840 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48322 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48320 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48320 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48320 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48321 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48321 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48321 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47564 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47564 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47564 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47638 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47638 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47638 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50328 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50328 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51718 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51718 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51718 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51717 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51717 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47503 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47503 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47503 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47502 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=47502 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47502 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47502 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47502 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47498 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47498 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47498 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47501 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47501 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47501 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51164 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=51164 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51164 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51164 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51164 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47497 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=47497 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47497 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47497 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47497 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(50551, 3, 0, 1950, 4844, 27843), -- -Unknown-
(50551, 2, 0, 4162, 3673, 27843), -- -Unknown-
(50551, 1, 0, 3197, 3154, 27843), -- -Unknown-
(50551, 0, 0, 1950, 4844, 27843), -- -Unknown-
(50703, 1, 0, 1947, 4844, 27843), -- -Unknown-
(50703, 0, 0, -1127, 818, 27843), -- -Unknown-
(50702, 2, 0, 1454, 3589, 27843), -- -Unknown-
(50702, 1, 0, 1456, 3510, 27843), -- -Unknown-
(50702, 0, 0, 1947, 4845, 27843), -- -Unknown-
(50904, 4, 0, 1240, 3757, 27843), -- -Unknown-
(50904, 3, 0, 1321, 3614, 27843), -- -Unknown-
(50904, 2, 0, 1215, 3671, 27843), -- -Unknown-
(50904, 1, 0, 1240, 3757, 27843), -- -Unknown-
(50904, 0, 0, 1454, 3589, 27843), -- -Unknown-
(50617, 2, 0, 1950, 4844, 27843), -- -Unknown-
(50617, 1, 0, 1949, 4842, 27843), -- -Unknown-
(50617, 0, 0, 1240, 3757, 27843), -- -Unknown-
(49437, 2, 0, 2781, 2986, 27843), -- -Unknown-
(49437, 1, 0, 2833, 2979, 27843), -- -Unknown-
(49437, 0, 0, 2677, 3420, 27843), -- -Unknown-
(50757, 2, 0, 2747, 2913, 27843), -- -Unknown-
(50757, 1, 6, 2764, 2858, 27843), -- -Unknown-
(50757, 1, 5, 2768, 2872, 27843), -- -Unknown-
(50757, 1, 4, 2807, 2916, 27843), -- -Unknown-
(50757, 1, 3, 2890, 2917, 27843), -- -Unknown-
(50757, 1, 2, 2964, 2844, 27843), -- -Unknown-
(50757, 1, 1, 2970, 2833, 27843), -- -Unknown-
(50757, 1, 0, 2892, 2754, 27843), -- -Unknown-
(50757, 0, 0, 2747, 2913, 27843), -- -Unknown-
(49669, 2, 0, 2747, 2913, 27843), -- -Unknown-
(49669, 1, 0, 2940, 2922, 27843), -- -Unknown-
(49669, 0, 0, 2747, 2913, 27843), -- -Unknown-
(50805, 2, 0, 3136, 2971, 27843), -- -Unknown-
(50805, 1, 6, 3087, 2902, 27843), -- -Unknown-
(50805, 1, 5, 3060, 3033, 27843), -- -Unknown-
(50805, 1, 4, 3111, 3070, 27843), -- -Unknown-
(50805, 1, 3, 3189, 3054, 27843), -- -Unknown-
(50805, 1, 2, 3238, 2924, 27843), -- -Unknown-
(50805, 1, 1, 3232, 2894, 27843), -- -Unknown-
(50805, 1, 0, 3204, 2885, 27843), -- -Unknown-
(50805, 0, 7, 3207, 2893, 27843), -- -Unknown-
(50805, 0, 6, 3086, 2899, 27843), -- -Unknown-
(50805, 0, 5, 3079, 2908, 27843), -- -Unknown-
(50805, 0, 4, 3077, 2911, 27843), -- -Unknown-
(50805, 0, 3, 3107, 3059, 27843), -- -Unknown-
(50805, 0, 2, 3166, 3048, 27843), -- -Unknown-
(50805, 0, 1, 3247, 2902, 27843), -- -Unknown-
(50805, 0, 0, 3229, 2891, 27843), -- -Unknown-
(50751, 1, 0, 3079, 3147, 27843), -- -Unknown-
(50751, 0, 0, 1950, 4844, 27843), -- -Unknown-
(50550, 4, 0, 3035, 3150, 27843), -- -Unknown-
(50550, 3, 0, 3125, 3150, 27843), -- -Unknown-
(50550, 2, 0, 3035, 3150, 27843), -- -Unknown-
(50550, 1, 0, 3079, 3148, 27843), -- -Unknown-
(50550, 0, 0, 3079, 3148, 27843), -- -Unknown-
(50752, 5, 0, 3035, 3150, 27843), -- -Unknown-
(50752, 4, 0, 3231, 3313, 27843), -- -Unknown-
(50752, 3, 0, 3150, 3403, 27843), -- -Unknown-
(50752, 2, 0, 3125, 3266, 27843), -- -Unknown-
(50752, 1, 0, 3043, 3291, 27843), -- -Unknown-
(50752, 0, 0, 3035, 3150, 27843), -- -Unknown-
(50750, 2, 0, 3035, 3150, 27843), -- -Unknown-
(50750, 1, 11, 3097, 3090, 27843), -- -Unknown-
(50750, 1, 10, 3048, 3094, 27843), -- -Unknown-
(50750, 1, 9, 3026, 3122, 27843), -- -Unknown-
(50750, 1, 8, 3017, 3167, 27843), -- -Unknown-
(50750, 1, 7, 3032, 3282, 27843), -- -Unknown-
(50750, 1, 6, 3118, 3403, 27843), -- -Unknown-
(50750, 1, 5, 3147, 3409, 27843), -- -Unknown-
(50750, 1, 4, 3214, 3360, 27843), -- -Unknown-
(50750, 1, 3, 3225, 3319, 27843), -- -Unknown-
(50750, 1, 2, 3224, 3312, 27843), -- -Unknown-
(50750, 1, 1, 3189, 3093, 27843), -- -Unknown-
(50750, 1, 0, 3167, 3088, 27843), -- -Unknown-
(50750, 0, 0, 3035, 3150, 27843), -- -Unknown-
(49003, 4, 0, 2560, 3474, 27843), -- -Unknown-
(49003, 3, 0, 2998, 3150, 27843), -- -Unknown-
(49003, 2, 6, 2672, 2927, 27843), -- -Unknown-
(49003, 2, 5, 2627, 3556, 27843), -- -Unknown-
(49003, 2, 4, 2882, 3532, 27843), -- -Unknown-
(49003, 2, 3, 2924, 3455, 27843), -- -Unknown-
(49003, 2, 2, 2929, 3435, 27843), -- -Unknown-
(49003, 2, 1, 2931, 3139, 27843), -- -Unknown-
(49003, 2, 0, 2778, 2860, 27843), -- -Unknown-
(49003, 1, 0, 2551, 3476, 27843), -- -Unknown-
(49003, 0, 0, 3035, 3150, 27843), -- -Unknown-
(49002, 2, 0, 2580, 3481, 27843), -- -Unknown-
(49002, 1, 0, 2647, 3391, 27843), -- -Unknown-
(49002, 0, 0, 2551, 3476, 27843), -- -Unknown-
(48329, 2, 0, 2551, 3476, 27843), -- -Unknown-
(48329, 1, 0, 2528, 3424, 27843), -- -Unknown-
(48329, 0, 0, 2551, 3476, 27843), -- -Unknown-
(50748, 3, 0, 2560, 3473, 27843), -- -Unknown-
(50748, 2, 11, 2425, 3553, 27843), -- -Unknown-
(50748, 2, 10, 2458, 3620, 27843), -- -Unknown-
(50748, 2, 9, 2521, 3676, 27843), -- -Unknown-
(50748, 2, 8, 2611, 3653, 27843), -- -Unknown-
(50748, 2, 7, 2635, 3628, 27843), -- -Unknown-
(50748, 2, 6, 2685, 3542, 27843), -- -Unknown-
(50748, 2, 5, 2686, 3487, 27843), -- -Unknown-
(50748, 2, 4, 2679, 3428, 27843), -- -Unknown-
(50748, 2, 3, 2657, 3356, 27843), -- -Unknown-
(50748, 2, 2, 2642, 3311, 27843), -- -Unknown-
(50748, 2, 1, 2640, 3310, 27843), -- -Unknown-
(50748, 2, 0, 2577, 3285, 27843), -- -Unknown-
(50748, 1, 0, 2685, 3422, 27843), -- -Unknown-
(50748, 0, 0, 2560, 3473, 27843), -- -Unknown-
(49141, 3, 0, 2685, 3422, 27843), -- -Unknown-
(49141, 2, 7, 2420, 3559, 27843), -- -Unknown-
(49141, 2, 6, 2485, 3634, 27843), -- -Unknown-
(49141, 2, 5, 2547, 3646, 27843), -- -Unknown-
(49141, 2, 4, 2615, 3625, 27843), -- -Unknown-
(49141, 2, 3, 2685, 3534, 27843), -- -Unknown-
(49141, 2, 2, 2679, 3466, 27843), -- -Unknown-
(49141, 2, 1, 2658, 3345, 27843), -- -Unknown-
(49141, 2, 0, 2571, 3288, 27843), -- -Unknown-
(49141, 1, 0, 2685, 3422, 27843), -- -Unknown-
(49141, 0, 0, 2560, 3473, 27843), -- -Unknown-
(49668, 4, 0, 2833, 3538, 27843), -- -Unknown-
(49668, 3, 0, 2831, 3040, 27843), -- -Unknown-
(49668, 2, 0, 2839, 3122, 27843), -- -Unknown-
(49668, 1, 0, 2846, 3226, 27843), -- -Unknown-
(49668, 0, 0, 2747, 2897, 27843), -- -Unknown-
(50746, 1, 0, 2833, 3538, 27843), -- -Unknown-
(50746, 0, 0, 2685, 3422, 27843), -- -Unknown-
(49666, 2, 0, 2833, 3538, 27843), -- -Unknown-
(49666, 1, 7, 2832, 3344, 27843), -- -Unknown-
(49666, 1, 6, 2818, 3435, 27843), -- -Unknown-
(49666, 1, 5, 2825, 3475, 27843), -- -Unknown-
(49666, 1, 4, 2840, 3497, 27843), -- -Unknown-
(49666, 1, 3, 2946, 3565, 27843), -- -Unknown-
(49666, 1, 2, 2938, 3432, 27843), -- -Unknown-
(49666, 1, 1, 2928, 3369, 27843), -- -Unknown-
(49666, 1, 0, 2874, 3316, 27843), -- -Unknown-
(49666, 0, 0, 2833, 3538, 27843), -- -Unknown-
(49665, 3, 0, 2833, 3538, 27843), -- -Unknown-
(49665, 2, 4, 2812, 3442, 27843), -- -Unknown-
(49665, 2, 3, 2844, 3502, 27843), -- -Unknown-
(49665, 2, 2, 2937, 3560, 27843), -- -Unknown-
(49665, 2, 1, 2939, 3435, 27843), -- -Unknown-
(49665, 2, 0, 2929, 3377, 27843), -- -Unknown-
(49665, 1, 6, 2832, 3347, 27843), -- -Unknown-
(49665, 1, 5, 2829, 3407, 27843), -- -Unknown-
(49665, 1, 4, 2838, 3496, 27843), -- -Unknown-
(49665, 1, 3, 2953, 3584, 27843), -- -Unknown-
(49665, 1, 2, 2939, 3431, 27843), -- -Unknown-
(49665, 1, 1, 2916, 3358, 27843), -- -Unknown-
(49665, 1, 0, 2876, 3317, 27843), -- -Unknown-
(49665, 0, 0, 2833, 3538, 27843), -- -Unknown-
(49667, 2, 0, 2677, 3420, 27843), -- -Unknown-
(49667, 1, 0, 2876, 3388, 27843), -- -Unknown-
(49667, 0, 0, 2677, 3420, 27843), -- -Unknown-
(49664, 1, 0, 2685, 3422, 27843), -- -Unknown-
(49664, 0, 0, 2833, 3538, 27843), -- -Unknown-
(50745, 1, 0, 2715, 3766, 27843), -- -Unknown-
(50745, 0, 0, 2685, 3422, 27843), -- -Unknown-
(48330, 2, 0, 2241, 3598, 27843), -- -Unknown-
(48330, 1, 0, 2446, 3470, 27843), -- -Unknown-
(48330, 0, 0, 2241, 3598, 27843), -- -Unknown-
(49139, 3, 0, 2241, 3598, 27843), -- -Unknown-
(49139, 2, 0, 2398, 3548, 27843), -- -Unknown-
(49139, 1, 0, 2320, 3396, 27843), -- -Unknown-
(49139, 0, 0, 2241, 3598, 27843), -- -Unknown-
(48331, 2, 0, 2242, 3597, 27843), -- -Unknown-
(48331, 1, 8, 2266, 3393, 27843), -- -Unknown-
(48331, 1, 7, 2253, 3465, 27843), -- -Unknown-
(48331, 1, 6, 2259, 3529, 27843), -- -Unknown-
(48331, 1, 5, 2280, 3566, 27843), -- -Unknown-
(48331, 1, 4, 2305, 3573, 27843), -- -Unknown-
(48331, 1, 3, 2365, 3570, 27843), -- -Unknown-
(48331, 1, 2, 2387, 3534, 27843), -- -Unknown-
(48331, 1, 1, 2417, 3439, 27843), -- -Unknown-
(48331, 1, 0, 2299, 3356, 27843), -- -Unknown-
(48331, 0, 0, 2242, 3597, 27843), -- -Unknown-
(48335, 2, 0, 2240, 3597, 27843), -- -Unknown-
(48335, 1, 9, 2293, 3321, 27843), -- -Unknown-
(48335, 1, 8, 2289, 3324, 27843), -- -Unknown-
(48335, 1, 7, 2248, 3359, 27843), -- -Unknown-
(48335, 1, 6, 2242, 3439, 27843), -- -Unknown-
(48335, 1, 5, 2256, 3584, 27843), -- -Unknown-
(48335, 1, 4, 2305, 3629, 27843), -- -Unknown-
(48335, 1, 3, 2359, 3670, 27843), -- -Unknown-
(48335, 1, 2, 2368, 3598, 27843), -- -Unknown-
(48335, 1, 1, 2362, 3319, 27843), -- -Unknown-
(48335, 1, 0, 2359, 3314, 27843), -- -Unknown-
(48335, 0, 0, 2240, 3597, 27843), -- -Unknown-
(48332, 2, 0, 2241, 3598, 27843), -- -Unknown-
(48332, 1, 8, 2059, 3279, 27843), -- -Unknown-
(48332, 1, 7, 2054, 3286, 27843), -- -Unknown-
(48332, 1, 6, 1981, 3469, 27843), -- -Unknown-
(48332, 1, 5, 1996, 3527, 27843), -- -Unknown-
(48332, 1, 4, 2057, 3566, 27843), -- -Unknown-
(48332, 1, 3, 2185, 3607, 27843), -- -Unknown-
(48332, 1, 2, 2205, 3531, 27843), -- -Unknown-
(48332, 1, 1, 2225, 3447, 27843), -- -Unknown-
(48332, 1, 0, 2064, 3278, 27843), -- -Unknown-
(48332, 0, 0, 2241, 3598, 27843), -- -Unknown-
(48334, 2, 0, 2242, 3597, 27843), -- -Unknown-
(48334, 1, 0, 2043, 3487, 27843), -- -Unknown-
(48334, 0, 0, 2242, 3597, 27843), -- -Unknown-
(49001, 2, 0, 2240, 3597, 27843), -- -Unknown-
(49001, 1, 8, 2020, 3338, 27843), -- -Unknown-
(49001, 1, 7, 2019, 3339, 27843), -- -Unknown-
(49001, 1, 6, 1981, 3425, 27843), -- -Unknown-
(49001, 1, 5, 1982, 3503, 27843), -- -Unknown-
(49001, 1, 4, 1986, 3505, 27843), -- -Unknown-
(49001, 1, 3, 2124, 3586, 27843), -- -Unknown-
(49001, 1, 2, 2211, 3584, 27843), -- -Unknown-
(49001, 1, 1, 2226, 3421, 27843), -- -Unknown-
(49001, 1, 0, 2131, 3333, 27843), -- -Unknown-
(49001, 0, 0, 2240, 3597, 27843), -- -Unknown-
(48840, 1, 0, 1603, 3725, 27843), -- -Unknown-
(48840, 0, 0, 2240, 3597, 27843), -- -Unknown-
(48322, 6, 0, 1603, 3725, 27843), -- -Unknown-
(48322, 5, 0, 1614, 3732, 27843), -- -Unknown-
(48322, 4, 0, 1608, 3733, 27843), -- -Unknown-
(48322, 3, 0, 1609, 3715, 27843), -- -Unknown-
(48322, 2, 0, 1593, 3726, 27843), -- -Unknown-
(48322, 1, 0, 1550, 3746, 27843), -- -Unknown-
(48322, 0, 0, 1603, 3725, 27843), -- -Unknown-
(48320, 2, 0, 1557, 3745, 27843), -- -Unknown-
(48320, 1, 9, 1439, 3733, 27843), -- -Unknown-
(48320, 1, 8, 1392, 3839, 27843), -- -Unknown-
(48320, 1, 7, 1394, 4002, 27843), -- -Unknown-
(48320, 1, 6, 1395, 4006, 27843), -- -Unknown-
(48320, 1, 5, 1555, 4079, 27843), -- -Unknown-
(48320, 1, 4, 1558, 4075, 27843), -- -Unknown-
(48320, 1, 3, 1603, 4005, 27843), -- -Unknown-
(48320, 1, 2, 1589, 3863, 27843), -- -Unknown-
(48320, 1, 1, 1524, 3752, 27843), -- -Unknown-
(48320, 1, 0, 1446, 3726, 27843), -- -Unknown-
(48320, 0, 0, 1557, 3745, 27843), -- -Unknown-
(48321, 2, 0, 1618, 3721, 27843), -- -Unknown-
(48321, 1, 0, 1440, 3776, 27843), -- -Unknown-
(48321, 0, 0, 1618, 3721, 27843), -- -Unknown-
(47564, 2, 0, 1603, 3712, 27843), -- -Unknown-
(47564, 1, 5, 1493, 3775, 27843), -- -Unknown-
(47564, 1, 4, 1460, 3881, 27843), -- -Unknown-
(47564, 1, 3, 1485, 3935, 27843), -- -Unknown-
(47564, 1, 2, 1544, 3938, 27843), -- -Unknown-
(47564, 1, 1, 1537, 3813, 27843), -- -Unknown-
(47564, 1, 0, 1524, 3744, 27843), -- -Unknown-
(47564, 0, 0, 1603, 3712, 27843), -- -Unknown-
(47638, 2, 0, 1595, 3724, 27843), -- -Unknown-
(47638, 1, 0, 1592, 3725, 27843), -- -Unknown-
(47638, 0, 0, 1603, 3725, 27843), -- -Unknown-
(50328, 1, 0, 1823, 3934, 27843), -- -Unknown-
(50328, 0, 0, 1601, 3712, 27843), -- -Unknown-
(51718, 2, 0, 1823, 3934, 27843), -- -Unknown-
(51718, 1, 11, 1751, 3799, 27843); -- -Unknown-

INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(51718, 1, 10, 1726, 3856, 27843), -- -Unknown-
(51718, 1, 9, 1746, 3896, 27843), -- -Unknown-
(51718, 1, 8, 1785, 3971, 27843), -- -Unknown-
(51718, 1, 7, 1821, 4004, 27843), -- -Unknown-
(51718, 1, 6, 1872, 3988, 27843), -- -Unknown-
(51718, 1, 5, 1897, 3940, 27843), -- -Unknown-
(51718, 1, 4, 1916, 3893, 27843), -- -Unknown-
(51718, 1, 3, 1916, 3892, 27843), -- -Unknown-
(51718, 1, 2, 1909, 3827, 27843), -- -Unknown-
(51718, 1, 1, 1825, 3768, 27843), -- -Unknown-
(51718, 1, 0, 1784, 3763, 27843), -- -Unknown-
(51718, 0, 0, 1823, 3934, 27843), -- -Unknown-
(51717, 1, 0, 2017, 4141, 27843), -- -Unknown-
(51717, 0, 0, 1823, 3934, 27843), -- -Unknown-
(47503, 2, 0, 1601, 3712, 27843), -- -Unknown-
(47503, 1, 0, 1667, 3468, 27843), -- -Unknown-
(47503, 0, 0, 1601, 3712, 27843), -- -Unknown-
(47502, 4, 0, 1601, 3712, 27843), -- -Unknown-
(47502, 3, 0, 1700, 3461, 27843), -- -Unknown-
(47502, 2, 0, 1709, 3524, 27843), -- -Unknown-
(47502, 1, 0, 1623, 3482, 27843), -- -Unknown-
(47502, 0, 0, 1601, 3712, 27843), -- -Unknown-
(47498, 2, 0, 1603, 3725, 27843), -- -Unknown-
(47498, 1, 0, 2047, 4174, 27843), -- -Unknown-
(47498, 0, 0, 2017, 4141, 27843), -- -Unknown-
(47501, 2, 0, 1603, 3725, 27843), -- -Unknown-
(47501, 1, 8, 1809, 4135, 27843), -- -Unknown-
(47501, 1, 7, 1807, 4142, 27843), -- -Unknown-
(47501, 1, 6, 1796, 4195, 27843), -- -Unknown-
(47501, 1, 5, 1982, 4393, 27843), -- -Unknown-
(47501, 1, 4, 2038, 4374, 27843), -- -Unknown-
(47501, 1, 3, 2122, 4252, 27843), -- -Unknown-
(47501, 1, 2, 2125, 4220, 27843), -- -Unknown-
(47501, 1, 1, 2050, 4074, 27843), -- -Unknown-
(47501, 1, 0, 2022, 4047, 27843), -- -Unknown-
(47501, 0, 0, 2017, 4141, 27843), -- -Unknown-
(51164, 4, 0, 1615, 3716, 27843), -- -Unknown-
(51164, 3, 0, 1642, 3980, 27843), -- -Unknown-
(51164, 2, 0, 1603, 3725, 27843), -- -Unknown-
(51164, 1, 0, 1601, 3712, 27843), -- -Unknown-
(51164, 0, 0, 1595, 3723, 27843), -- -Unknown-
(47497, 4, 0, 1595, 3723, 27843), -- -Unknown-
(47497, 3, 0, 1616, 3716, 27843), -- -Unknown-
(47497, 2, 0, 1606, 3733, 27843), -- -Unknown-
(47497, 1, 0, 1597, 3715, 27843), -- -Unknown-
(47497, 0, 0, 1603, 3725, 27843); -- -Unknown-


DELETE FROM `quest_details` WHERE `ID` IN (50551 /*-Unknown-*/, 50703 /*-Unknown-*/, 50702 /*-Unknown-*/, 50904 /*-Unknown-*/, 50617 /*-Unknown-*/, 49437 /*-Unknown-*/, 50757 /*-Unknown-*/, 49669 /*-Unknown-*/, 50751 /*-Unknown-*/, 50550 /*-Unknown-*/, 50752 /*-Unknown-*/, 50750 /*-Unknown-*/, 49003 /*-Unknown-*/, 49002 /*-Unknown-*/, 48329 /*-Unknown-*/, 50748 /*-Unknown-*/, 49141 /*-Unknown-*/, 49668 /*-Unknown-*/, 50746 /*-Unknown-*/, 49666 /*-Unknown-*/, 49665 /*-Unknown-*/, 49667 /*-Unknown-*/, 49664 /*-Unknown-*/, 50745 /*-Unknown-*/, 48330 /*-Unknown-*/, 49139 /*-Unknown-*/, 48331 /*-Unknown-*/, 48335 /*-Unknown-*/, 48332 /*-Unknown-*/, 48334 /*-Unknown-*/, 49001 /*-Unknown-*/, 48840 /*-Unknown-*/, 48322 /*-Unknown-*/, 48320 /*-Unknown-*/, 48321 /*-Unknown-*/, 47564 /*-Unknown-*/, 47638 /*-Unknown-*/, 50328 /*-Unknown-*/, 51718 /*-Unknown-*/, 51717 /*-Unknown-*/, 47503 /*-Unknown-*/, 47502 /*-Unknown-*/, 47498 /*-Unknown-*/, 47501 /*-Unknown-*/, 51164 /*-Unknown-*/, 47497 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(50551, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50703, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50702, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50904, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50617, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49437, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50757, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49669, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50751, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50550, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50752, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50750, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49003, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49002, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48329, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50748, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49141, 396, 396, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(49668, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50746, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49666, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49665, 396, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49667, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49664, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50745, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48330, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49139, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48331, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48335, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48332, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48334, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49001, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48840, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48322, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48320, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48321, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47564, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47638, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50328, 1, 1, 0, 0, 0, 1000, 0, 0, 27843), -- -Unknown-
(51718, 1, 1, 0, 0, 0, 1000, 0, 0, 27843), -- -Unknown-
(51717, 1, 1, 0, 0, 0, 1000, 0, 0, 27843), -- -Unknown-
(47503, 1, 1, 0, 0, 0, 1000, 0, 0, 27843), -- -Unknown-
(47502, 1, 603, 0, 0, 0, 1000, 0, 0, 27843), -- -Unknown-
(47498, 1, 11, 6, 0, 0, 2000, 2000, 0, 27843), -- -Unknown-
(47501, 1, 1, 0, 0, 0, 2000, 0, 0, 27843), -- -Unknown-
(51164, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47497, 1, 0, 0, 0, 0, 0, 0, 0, 27843); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (50752 /*-Unknown-*/, 50748 /*-Unknown-*/, 48335 /*-Unknown-*/, 48332 /*-Unknown-*/, 48321 /*-Unknown-*/, 47564 /*-Unknown-*/, 51718 /*-Unknown-*/, 47502 /*-Unknown-*/, 47498 /*-Unknown-*/, 47501 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(50752, 1, 0, 0, 0, 'Do you have the artifacts?', 27843), -- -Unknown-
(50748, 0, 0, 0, 0, 'There are no end to the Faithless, so grab as many as you can carry.', 27843), -- -Unknown-
(48335, 1, 0, 0, 0, 'Don\'t even bother trying to tear it. You can\'t do it.', 27843), -- -Unknown-
(48332, 1, 0, 0, 0, 'It looks like you\'ve still got all your fingers. That\'s good.', 27843), -- -Unknown-
(48321, 1, 0, 0, 0, 'If dis doesn\'t work, we can always be de Bloody Rib Gang.', 27843), -- -Unknown-
(47564, 1, 0, 0, 0, 'Dis buffet is going to be a disaster if we don\'t get dat fruit!', 27843), -- -Unknown-
(51718, 1, 0, 0, 0, 'Don\'t fret if some sand gets mixed in. It\'ll taste the same either way.', 27843), -- -Unknown-
(47502, 1, 0, 0, 0, 'We nothin\' without our gang.', 27843), -- -Unknown-
(47498, 1, 0, 0, 0, 'Did you find Zulsan yet?', 27843), -- -Unknown-
(47501, 0, 0, 0, 0, 'My scorpid blood drinks are famous in de Goldtusk Gang!', 27843); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`ID`=265351 AND `EffectIndex`=3) OR (`ID`=265902 AND `EffectIndex`=1);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(265351, 3, 1642, 1949.92, 4848.09, 101.84, 27843), -- Spell: Cutscene Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(265902, 1, 1642, 3088.1, 3150.7, 111.4, 27843); -- Spell: Teleport for Korthek Scene (DNT) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (135133, 135134, 134810, 138601, 134803, 134846, 134857, 134808, 134858, 135738, 135735, 138594, 128946, 135695, 135732, 135676, 135625, 134640, 140401, 129588, 136926, 128691, 134611, 136925, 128996, 130429, 128683, 130427, 130434, 129120, 128681, 128685, 129180, 128678, 137681, 124681, 124683, 136191, 129638, 129650, 129772, 135099, 129781, 130513, 138519, 129776, 135094, 134713, 135287, 135390, 134601, 135396, 138411, 135957, 129778, 135968, 135970, 135965, 135966, 135967, 134610, 135243, 135093, 135990, 135111, 135193, 135214, 135191, 135188, 135187, 135186, 129910, 129763, 129798, 129787, 135537, 130603, 129903, 134745, 142485, 142484, 129754, 138596, 138600, 134709, 134820, 135298, 135027, 134621, 135018, 134618, 134625, 135292, 130514, 129784, 135110, 134563, 134556, 135352, 138233, 138234, 138235, 134561, 134557, 138209, 129647, 134562, 130396, 135123, 135355, 138151, 138240, 135354, 134324, 138218, 138214, 135385, 134560, 130342, 138159, 134559, 134558, 135090, 137981, 135172, 135128, 135132, 137970, 139361, 136553, 129549, 129542, 129544, 129856, 129848, 129761, 129799, 129831, 134971, 129874, 129821, 129927, 129759, 129811, 129434, 129506, 129500, 129507, 129476, 138923, 127908, 129457, 129473, 129464, 129672, 137721, 135727, 124211, 129436, 130070, 129497, 129453, 129450, 129451, 129496, 124795, 129505, 129499, 129667, 129474, 136596, 135742, 129411, 135743, 129410, 129357, 129354, 129319, 129365, 133986, 122725, 123728, 123729, 123730, 143661, 133930, 133946, 133947, 133938, 133924, 133931, 139121, 139132, 139157, 139158, 139159, 139138, 139153, 139154, 139155, 124187, 133838, 133833, 124172, 124182, 124183, 130270, 142449, 124526, 128682, 128978, 138749, 122750, 128686, 130409, 134116, 129259, 124627, 122749, 123571, 123572, 124177, 124536, 124179, 139752, 139749, 133929, 122723, 137356, 136593, 133853, 129297, 129299, 129288, 133897, 133896, 133901, 133904, 129287, 129289, 133887);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(135133, 110, 120, 0, 0, 27843),
(135134, 110, 120, 0, 0, 27843),
(134810, 110, 120, 0, 0, 27843),
(138601, 110, 120, 0, 0, 27843),
(134803, 110, 120, 0, 0, 27843),
(134846, 110, 120, 0, 0, 27843),
(134857, 110, 120, 0, 0, 27843),
(134808, 110, 120, 0, 0, 27843),
(134858, 110, 120, 0, 0, 27843),
(135738, 110, 120, 0, 0, 27843),
(135735, 110, 120, 0, 0, 27843),
(138594, 110, 120, 0, 0, 27843),
(128946, 110, 120, 0, 0, 27843),
(135695, 110, 120, 0, 0, 27843),
(135732, 110, 120, 0, 0, 27843),
(135676, 110, 120, 0, 0, 27843),
(135625, 110, 120, 0, 0, 27843),
(134640, 110, 120, 0, 0, 27843),
(140401, 110, 120, 0, 0, 27843),
(129588, 110, 120, 0, 0, 27843),
(136926, 110, 120, 0, 0, 27843),
(128691, 110, 120, 0, 0, 27843),
(134611, 110, 120, 0, 0, 27843),
(136925, 110, 120, 0, 0, 27843),
(128996, 110, 120, 0, 0, 27843),
(130429, 110, 120, 0, 0, 27843),
(128683, 110, 120, 0, 0, 27843),
(130427, 110, 120, 0, 0, 27843),
(130434, 110, 120, 0, 0, 27843),
(129120, 110, 120, 0, 0, 27843),
(128681, 110, 120, 0, 0, 27843),
(128685, 110, 120, 0, 0, 27843),
(129180, 110, 120, 0, 0, 27843),
(128678, 110, 120, 0, 0, 27843),
(137681, 110, 120, 0, 0, 27843),
(124681, 110, 120, 0, 0, 27843),
(124683, 110, 120, 0, 0, 27843),
(136191, 110, 120, 0, 0, 27843),
(129638, 110, 120, 0, 0, 27843),
(129650, 110, 120, 0, 0, 27843),
(129772, 110, 120, 0, 0, 27843),
(135099, 110, 120, 0, 0, 27843),
(129781, 110, 120, 0, 0, 27843),
(130513, 110, 120, 0, 0, 27843),
(138519, 110, 120, 0, 0, 27843),
(129776, 110, 120, 0, 0, 27843),
(135094, 110, 120, 0, 0, 27843),
(134713, 110, 120, 0, 0, 27843),
(135287, 110, 120, 0, 0, 27843),
(135390, 110, 120, 0, 0, 27843),
(134601, 110, 120, 0, 0, 27843),
(135396, 110, 120, 0, 0, 27843),
(138411, 110, 120, 0, 0, 27843),
(135957, 110, 120, 0, 0, 27843),
(129778, 110, 120, 0, 0, 27843),
(135968, 110, 120, 0, 0, 27843),
(135970, 110, 120, 0, 0, 27843),
(135965, 110, 120, 0, 0, 27843),
(135966, 110, 120, 0, 0, 27843),
(135967, 110, 120, 0, 0, 27843),
(134610, 110, 120, 0, 0, 27843),
(135243, 110, 120, 0, 0, 27843),
(135093, 110, 120, 0, 0, 27843),
(135990, 110, 120, 0, 0, 27843),
(135111, 110, 120, 0, 0, 27843),
(135193, 110, 120, 0, 0, 27843),
(135214, 110, 120, 0, 0, 27843),
(135191, 110, 120, 0, 0, 27843),
(135188, 110, 120, 0, 0, 27843),
(135187, 110, 120, 0, 0, 27843),
(135186, 110, 120, 0, 0, 27843),
(129910, 110, 120, 0, 0, 27843),
(129763, 110, 120, 0, 0, 27843),
(129798, 110, 120, 0, 0, 27843),
(129787, 110, 120, 0, 0, 27843),
(135537, 110, 120, 0, 0, 27843),
(130603, 110, 120, 0, 0, 27843),
(129903, 110, 120, 0, 0, 27843),
(134745, 110, 120, 0, 0, 27843),
(142485, 110, 120, 0, 0, 27843),
(142484, 120, 120, 0, 0, 27843),
(129754, 110, 120, 0, 0, 27843),
(138596, 110, 120, 0, 0, 27843),
(138600, 110, 120, 0, 0, 27843),
(134709, 110, 120, 0, 0, 27843),
(134820, 110, 120, 0, 0, 27843),
(135298, 110, 120, 0, 0, 27843),
(135027, 110, 120, 0, 0, 27843),
(134621, 110, 120, 0, 0, 27843),
(135018, 110, 120, 0, 0, 27843),
(134618, 110, 120, 0, 0, 27843),
(134625, 110, 120, 0, 0, 27843),
(135292, 110, 120, 0, 0, 27843),
(130514, 110, 120, 0, 0, 27843),
(129784, 110, 120, 0, 0, 27843),
(135110, 110, 120, 0, 0, 27843),
(134563, 110, 120, 0, 0, 27843),
(134556, 110, 120, 0, 0, 27843),
(135352, 110, 120, 0, 0, 27843),
(138233, 110, 120, 0, 0, 27843),
(138234, 110, 120, 0, 0, 27843),
(138235, 110, 120, 0, 0, 27843),
(134561, 110, 120, 0, 0, 27843),
(134557, 110, 120, 0, 0, 27843),
(138209, 110, 120, 0, 0, 27843),
(129647, 110, 120, 0, 0, 27843),
(134562, 110, 120, 0, 0, 27843),
(130396, 110, 120, 0, 0, 27843),
(135123, 110, 120, 0, 0, 27843),
(135355, 110, 120, 0, 0, 27843),
(138151, 110, 120, 0, 0, 27843),
(138240, 110, 120, 0, 0, 27843),
(135354, 110, 120, 0, 0, 27843),
(134324, 110, 120, 0, 0, 27843),
(138218, 110, 120, 0, 0, 27843),
(138214, 110, 120, 0, 0, 27843),
(135385, 110, 120, 0, 0, 27843),
(134560, 110, 120, 0, 0, 27843),
(130342, 110, 120, 0, 0, 27843),
(138159, 110, 120, 0, 0, 27843),
(134559, 110, 120, 0, 0, 27843),
(134558, 110, 120, 0, 0, 27843),
(135090, 110, 120, 0, 0, 27843),
(137981, 110, 120, 0, 0, 27843),
(135172, 110, 120, 0, 0, 27843),
(135128, 110, 120, 0, 0, 27843),
(135132, 110, 120, 0, 0, 27843),
(137970, 110, 120, 0, 0, 27843),
(139361, 110, 120, 0, 0, 27843),
(136553, 110, 120, 0, 0, 27843),
(129549, 110, 120, 0, 0, 27843),
(129542, 110, 120, 0, 0, 27843),
(129544, 110, 120, 0, 0, 27843),
(129856, 110, 120, 0, 0, 27843),
(129848, 110, 120, 0, 0, 27843),
(129761, 110, 120, 0, 0, 27843),
(129799, 110, 120, 0, 0, 27843),
(129831, 110, 120, 0, 0, 27843),
(134971, 110, 120, 0, 0, 27843),
(129874, 110, 120, 0, 0, 27843),
(129821, 110, 120, 0, 0, 27843),
(129927, 110, 120, 0, 0, 27843),
(129759, 110, 120, 0, 0, 27843),
(129811, 110, 120, 0, 0, 27843),
(129434, 110, 120, 0, 0, 27843),
(129506, 110, 120, 0, 0, 27843),
(129500, 110, 120, 0, 0, 27843),
(129507, 110, 120, 0, 0, 27843),
(129476, 110, 120, 0, 0, 27843),
(138923, 110, 120, 0, 0, 27843),
(127908, 110, 120, 0, 0, 27843),
(129457, 110, 120, 0, 0, 27843),
(129473, 110, 120, 0, 0, 27843),
(129464, 110, 120, 0, 0, 27843),
(129672, 110, 120, 0, 0, 27843),
(137721, 110, 120, 0, 0, 27843),
(135727, 110, 120, 0, 0, 27843),
(124211, 110, 120, 0, 0, 27843),
(129436, 110, 120, 0, 0, 27843),
(130070, 110, 120, 0, 0, 27843),
(129497, 110, 120, 0, 0, 27843),
(129453, 110, 120, 0, 0, 27843),
(129450, 110, 120, 0, 0, 27843),
(129451, 110, 120, 0, 0, 27843),
(129496, 110, 120, 0, 0, 27843),
(124795, 110, 120, 0, 0, 27843),
(129505, 110, 120, 0, 0, 27843),
(129499, 110, 120, 0, 0, 27843),
(129667, 110, 120, 0, 0, 27843),
(129474, 110, 120, 0, 0, 27843),
(136596, 110, 120, 0, 0, 27843),
(135742, 110, 120, 0, 0, 27843),
(129411, 110, 120, 0, 0, 27843),
(135743, 110, 120, 0, 0, 27843),
(129410, 110, 120, 0, 0, 27843),
(129357, 110, 120, 0, 0, 27843),
(129354, 110, 120, 0, 0, 27843),
(129319, 110, 120, 0, 0, 27843),
(129365, 110, 120, 0, 0, 27843),
(133986, 110, 120, 0, 0, 27843),
(122725, 110, 120, 0, 0, 27843),
(123728, 110, 120, 0, 0, 27843),
(123729, 110, 120, 0, 0, 27843),
(123730, 110, 120, 0, 0, 27843),
(143661, 110, 120, 0, 0, 27843),
(133930, 110, 120, 0, 0, 27843),
(133946, 110, 120, 0, 0, 27843),
(133947, 110, 120, 0, 0, 27843),
(133938, 110, 120, 0, 0, 27843),
(133924, 110, 120, 0, 0, 27843),
(133931, 110, 120, 0, 0, 27843),
(139121, 110, 120, 0, 0, 27843),
(139132, 110, 120, 0, 0, 27843),
(139157, 110, 120, 0, 0, 27843),
(139158, 110, 120, 0, 0, 27843),
(139159, 110, 120, 0, 0, 27843),
(139138, 110, 120, 0, 0, 27843),
(139153, 110, 120, 0, 0, 27843),
(139154, 110, 120, 0, 0, 27843),
(139155, 110, 120, 0, 0, 27843),
(124187, 110, 120, 0, 0, 27843),
(133838, 110, 120, 0, 0, 27843),
(133833, 110, 120, 0, 0, 27843),
(124172, 110, 120, 0, 0, 27843),
(124182, 110, 120, 0, 0, 27843),
(124183, 110, 120, 0, 0, 27843),
(130270, 110, 120, 0, 0, 27843),
(142449, 110, 120, 0, 0, 27843),
(124526, 110, 120, 0, 0, 27843),
(128682, 110, 120, 0, 0, 27843),
(128978, 110, 120, 0, 0, 27843),
(138749, 110, 120, 0, 0, 27843),
(122750, 110, 120, 0, 0, 27843),
(128686, 110, 120, 0, 0, 27843),
(130409, 110, 120, 0, 0, 27843),
(134116, 110, 120, 0, 0, 27843),
(129259, 110, 120, 0, 0, 27843),
(124627, 110, 120, 0, 0, 27843),
(122749, 110, 120, 0, 0, 27843),
(123571, 110, 120, 0, 0, 27843),
(123572, 110, 120, 0, 0, 27843),
(124177, 110, 120, 0, 0, 27843),
(124536, 110, 120, 0, 0, 27843),
(124179, 110, 120, 0, 0, 27843),
(139752, 120, 120, 1, 1, 27843),
(139749, 120, 120, 1, 1, 27843),
(133929, 110, 120, 0, 0, 27843),
(122723, 110, 120, 0, 0, 27843),
(137356, 110, 120, 0, 0, 27843),
(136593, 110, 120, 0, 0, 27843),
(133853, 110, 120, 0, 0, 27843),
(129297, 110, 120, 0, 0, 27843),
(129299, 110, 120, 0, 0, 27843),
(129288, 110, 120, 0, 0, 27843),
(133897, 110, 120, 0, 0, 27843),
(133896, 110, 120, 0, 0, 27843),
(133901, 110, 120, 0, 0, 27843),
(133904, 110, 120, 0, 0, 27843),
(129287, 110, 120, 0, 0, 27843),
(129289, 110, 120, 0, 0, 27843),
(133887, 110, 120, 0, 0, 27843);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (83590, 83912, 83244, 83615, 84403, 84367, 84350, 83900, 83899, 80646, 80626, 83785, 80664, 80424, 85438, 78190, 78191, 80875, 85767, 83751, 75594, 75592, 83731, 83730, 84190, 84192, 83655, 83708, 83714, 83727, 83715, 83711, 83709, 83712, 83726, 83713, 83710, 83725, 83719, 78650, 78854, 78853, 78855, 84595, 80882, 76912, 78593, 76668, 80898, 84705, 84096, 80876, 80063, 83840, 84618, 84617, 85771, 83752, 84214, 80692, 83728, 77686, 79720, 83729, 83754, 83732, 83757, 83700, 83760, 78218, 84217, 84216, 83702, 83701, 83718, 82117, 83716, 83755, 83721, 83722, 83758, 83703, 80899, 83748, 82397, 83743, 83745, 83759, 83747, 82398, 84146, 84147, 84151, 84148, 83741, 83694, 83738, 83735, 83742, 76913, 84409, 85781, 84101, 83538, 82396, 83746, 85744, 83744, 85320, 84362, 83737, 83736, 84098, 80496, 80494, 80493, 83739, 83740, 83733, 84097, 77753, 80880, 80874, 80872, 80064, 77078, 80886, 77023, 79868, 80879, 77957, 80900, 80917, 80873, 80916, 80871, 80869, 80918, 80915, 77081, 80870, 80299, 80189, 80406, 80618, 79458, 80818, 80815, 80817, 80819, 80609, 80607, 80608, 85463, 84839, 77289, 80585, 83345, 80704, 76996, 77576, 77577, 77578, 83243, 85325, 83246, 83245, 85322, 83237, 85324, 86173, 86155, 86151, 86152, 86153, 86154, 86156, 86157, 86159, 83283, 83185, 77752, 80573, 83351, 80476, 83281, 80021, 86487, 86486, 76991, 77493, 78251, 83197, 80518, 77475, 82990, 80032, 81104, 82991, 80502, 80027);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(83590, 1.075765, 3, 0, 27843),
(83912, 1.35, 2.025, 0, 27843),
(83244, 0.306, 1.5, 0, 27843),
(83615, 0.6454591, 1.8, 0, 27843),
(84403, 1.546783, 2.4, 0, 27843),
(84367, 1, 1, 0, 27843),
(84350, 0.062, 2, 0, 27843),
(83900, 0.8592955, 0.4, 0, 27843),
(83899, 0.8592955, 0.4, 0, 27843),
(80646, 0.8073308, 1, 0, 27843),
(80626, 0.9344095, 1.5, 0, 27843),
(83785, 0.8073308, 1, 0, 27843),
(80664, 0.9344095, 1.5, 0, 27843),
(80424, 1.121291, 1.5, 0, 27843),
(85438, 5.855165, 7.5, 0, 27843),
(78190, 0.5669019, 1.35, 0, 27843),
(78191, 0.5669019, 1.35, 0, 27843),
(80875, 0.9344095, 1.5, 0, 27843),
(85767, 0.306, 1.5, 0, 27843),
(83751, 0.9344095, 1.5, 0, 27843),
(75594, 2.623784, 4, 0, 27843),
(75592, 2.623784, 4, 0, 27843),
(83731, 0.7265977, 0.9, 0, 27843),
(83730, 0.7265977, 0.9, 0, 27843),
(84190, 0.9344095, 1.5, 0, 27843),
(84192, 0.9344095, 1.5, 0, 27843),
(83655, 1.401614, 1.5, 0, 27843),
(83708, 0.8073308, 1, 0, 27843),
(83714, 0.7265977, 0.9, 0, 27843),
(83727, 0.8073308, 1, 0, 27843),
(83715, 0.7265977, 0.9, 0, 27843),
(83711, 0.8073308, 1, 0, 27843),
(83709, 0.8073308, 1, 0, 27843),
(83712, 0.7265977, 0.9, 0, 27843),
(83726, 0.8073308, 1, 0, 27843),
(83713, 0.7265977, 0.9, 0, 27843),
(83710, 0.8073308, 1, 0, 27843),
(83725, 0.8073308, 1, 0, 27843),
(83719, 0.9344095, 1.5, 0, 27843),
(78650, 1.469839, 2.2, 0, 27843),
(78854, 1.469839, 2.2, 0, 27843),
(78853, 1.469839, 2.2, 0, 27843),
(78855, 1.469839, 2.2, 0, 27843),
(84595, 118.1871, 1.5, 0, 27843),
(80882, 0.9344095, 1.5, 0, 27843),
(76912, 1.806657, 3, 0, 27843),
(78593, 6.02219, 10, 0, 27843),
(76668, 1.354993, 2.25, 0, 27843),
(80898, 0.8409685, 1.5, 0, 27843),
(84705, 0.9344095, 1.5, 0, 27843),
(84096, 0.306, 1.5, 0, 27843),
(80876, 0.9344095, 1.5, 0, 27843),
(80063, 0.9033285, 1.5, 0, 27843),
(83840, 0.968797, 1.2, 0, 27843),
(84618, 0.389, 1.5, 0, 27843),
(84617, 0.306, 1.5, 0, 27843),
(85771, 0.208, 1.5, 0, 27843),
(83752, 0.9344095, 1.5, 0, 27843),
(84214, 0.306, 1.5, 0, 27843),
(80692, 0.8073308, 1, 0, 27843),
(83728, 0.8073308, 1, 0, 27843),
(77686, 1.140607, 1.5, 0, 27843),
(79720, 1.140607, 1.5, 0, 27843),
(83729, 0.7265977, 0.9, 0, 27843),
(83754, 0.9344095, 1.5, 0, 27843),
(83732, 0.7265977, 0.9, 0, 27843),
(83757, 0.8073308, 1, 0, 27843),
(83700, 0.8409685, 1.5, 0, 27843),
(83760, 0.8073308, 1, 0, 27843),
(78218, 1.140607, 1.5, 0, 27843),
(84217, 0.306, 1.5, 0, 27843),
(84216, 0.306, 1.5, 0, 27843),
(83702, 0.8409685, 1.5, 0, 27843),
(83701, 0.8409685, 1.5, 0, 27843),
(83718, 0.9344095, 1.5, 0, 27843),
(82117, 1.464601, 3.24, 0, 27843),
(83716, 0.9344095, 1.5, 0, 27843),
(83755, 0.9344095, 1.5, 0, 27843),
(83721, 0.8409685, 1.5, 0, 27843),
(83722, 0.8409685, 1.5, 0, 27843),
(83758, 0.8073308, 1, 0, 27843),
(83703, 0.8409685, 1.5, 0, 27843),
(80899, 0.8409685, 1.5, 0, 27843),
(83748, 0.9344095, 1.5, 0, 27843),
(82397, 0.347222, 1.5, 0, 27843),
(83743, 0.8073308, 1, 0, 27843),
(83745, 0.9344095, 1.5, 0, 27843),
(83759, 0.8073308, 1, 0, 27843),
(83747, 0.9344095, 1.5, 0, 27843),
(82398, 0.347222, 1.5, 0, 27843),
(84146, 0.221527, 1.5, 0, 27843),
(84147, 0.221527, 1.5, 0, 27843),
(84151, 0.221527, 1.5, 0, 27843),
(84148, 0.221527, 1.5, 0, 27843),
(83741, 0.8073308, 1, 0, 27843),
(83694, 0.968797, 1.2, 0, 27843),
(83738, 0.8409685, 1.5, 0, 27843),
(83735, 0.8073308, 1, 0, 27843),
(83742, 0.8073308, 1, 0, 27843),
(76913, 1.806657, 3, 0, 27843),
(84409, 0.306, 1.5, 0, 27843),
(85781, 0.306, 1.5, 0, 27843),
(84101, 0.306, 1.5, 0, 27843),
(83538, 0.3, 1, 0, 27843),
(82396, 0.347222, 1.5, 0, 27843),
(83746, 0.9344095, 1.5, 0, 27843),
(85744, 0.306, 1.5, 0, 27843),
(83744, 0.8073308, 1, 0, 27843),
(85320, 0.306, 1.5, 0, 27843),
(84362, 3.732205, 3, 0, 27843),
(83736, 0.8073308, 1, 0, 27843),
(84098, 0.306, 1.5, 0, 27843),
(80496, 0.347222, 1.5, 0, 27843),
(80494, 0.347222, 1.5, 0, 27843),
(80493, 0.347222, 1.5, 0, 27843),
(83739, 0.8409685, 1.5, 0, 27843),
(83740, 0.8409685, 1.5, 0, 27843),
(83733, 0.8073308, 1, 0, 27843),
(84097, 0.306, 1.5, 0, 27843),
(77753, 0.7871352, 1.2, 0, 27843),
(80880, 0.9344095, 1.5, 0, 27843),
(80874, 0.9344095, 1.5, 0, 27843),
(80872, 0.9344095, 1.5, 0, 27843),
(80064, 0.9033285, 1.5, 0, 27843),
(77078, 4.516642, 7.5, 0, 27843),
(80886, 0.8073308, 1, 0, 27843),
(77023, 3.011095, 5, 0, 27843),
(79868, 0.9033285, 1.5, 0, 27843),
(80879, 0.9344095, 1.5, 0, 27843),
(77957, 1.806657, 3, 0, 27843),
(80900, 0.8409685, 1.5, 0, 27843),
(80917, 0.8073308, 1, 0, 27843),
(80873, 0.9344095, 1.5, 0, 27843),
(80916, 0.8073308, 1, 0, 27843),
(80871, 0.9344095, 1.5, 0, 27843),
(80869, 0.9344095, 1.5, 0, 27843),
(80918, 0.8073308, 1, 0, 27843),
(80915, 0.8073308, 1, 0, 27843),
(77081, 3.011095, 5, 0, 27843),
(80870, 0.9344095, 1.5, 0, 27843),
(80299, 3.053412, 2.1, 0, 27843),
(80189, 2.181009, 1.5, 0, 0),
(80406, 0.2896474, 0.275, 0, 27843),
(80618, 3.673298, 5.6, 0, 27843),
(79458, 0.496, 3.2, 0, 27843),
(80818, 0.347222, 1.5, 0, 27843),
(80815, 0.347222, 1.5, 0, 27843),
(80817, 0.347222, 1.5, 0, 27843),
(80819, 0.347222, 1.5, 0, 27843),
(80609, 0.306, 1.5, 0, 27843),
(80607, 0.306, 1.5, 0, 27843),
(80608, 0.306, 1.5, 0, 27843),
(85463, 0.306, 1.5, 0, 27843),
(84839, 1.214732, 1.5, 0, 27843),
(77289, 0.5365, 0.75, 0, 27843),
(80585, 0.4340275, 1.875, 0, 27843),
(83345, 0.347222, 1.5, 0, 27843),
(80704, 2.107766, 3.5, 0, 27843),
(76996, 0.347222, 1.5, 0, 27843),
(77576, 0.347222, 1.5, 0, 27843),
(77577, 0.347222, 1.5, 0, 27843),
(77578, 0.347222, 1.5, 0, 27843),
(83243, 0.306, 1.5, 0, 27843),
(85325, 0.347222, 1.5, 0, 27843),
(83246, 0.306, 1.5, 0, 27843),
(83245, 0.306, 1.5, 0, 27843),
(85322, 0.306, 1.5, 0, 27843),
(83237, 0.306, 1.5, 0, 27843),
(85324, 0.306, 1.5, 0, 27843),
(86173, 0.306, 1.5, 0, 27843),
(86155, 0.383, 1.5, 0, 27843),
(86151, 0.4464, 1.8, 0, 27843),
(86152, 0.383, 1.5, 0, 27843),
(86153, 0.383, 1.5, 0, 27843),
(86154, 0.383, 1.5, 0, 27843),
(86156, 0.8725, 3.75, 0, 27843),
(86157, 0.9747, 4.05, 0, 27843),
(86159, 0.306, 1.5, 0, 27843),
(83283, 2.581474, 1.25, 0, 27843),
(83185, 0.306, 1.5, 0, 27843),
(77752, 1.967838, 3, 0, 27843),
(80573, 0.9344095, 1.5, 0, 27843),
(83351, 0.9344095, 1.5, 0, 27843),
(80476, 2, 4, 0, 27843),
(83281, 1.239107, 0.6, 0, 27843),
(80021, 1.342366, 0.65, 0, 27843),
(86487, 0.383, 1.5, 0, 27843),
(86486, 0.306, 1.5, 0, 27843),
(76991, 0.347222, 1.5, 0, 27843),
(77493, 1.992649, 2.2, 0, 27843),
(78251, 3, 3.75, 0, 27843),
(83197, 2.988973, 3.3, 0, 27843),
(80518, 0.3375, 1.125, 0, 27843),
(77475, 3.128136, 6, 0, 27843),
(82990, 0.347222, 1.5, 0, 27843),
(80032, 1.548884, 0.75, 0, 27843),
(81104, 0.7885087, 1.5, 0, 27843),
(82991, 0.347222, 1.5, 0, 27843),
(80502, 1.239107, 0.6, 0, 27843),
(80027, 1.548884, 0.75, 0, 27843);

UPDATE `creature_model_info` SET `BoundingRadius`=2.318543, `CombatReach`=3.85 WHERE `DisplayID`=80970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `VerifiedBuild`=27843 WHERE `DisplayID`=441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.27, `VerifiedBuild`=27843 WHERE `DisplayID`=1762;
UPDATE `creature_model_info` SET `BoundingRadius`=0.27, `VerifiedBuild`=27843 WHERE `DisplayID`=3619;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3171547, `CombatReach`=0.40625 WHERE `DisplayID`=80264;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375, `VerifiedBuild`=27843 WHERE `DisplayID`=983;
UPDATE `creature_model_info` SET `BoundingRadius`=1.342116, `VerifiedBuild`=27843 WHERE `DisplayID`=641;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9033285, `CombatReach`=1.5 WHERE `DisplayID`=80065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5266316, `CombatReach`=0.5 WHERE `DisplayID`=76382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3686421, `CombatReach`=0.35 WHERE `DisplayID`=76383;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288943, `CombatReach`=0.6 WHERE `DisplayID`=35132;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=45494;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288943, `CombatReach`=0.6 WHERE `DisplayID`=46898;
UPDATE `creature_model_info` SET `BoundingRadius`=2.148239, `CombatReach`=1 WHERE `DisplayID`=26774;
UPDATE `creature_model_info` SET `BoundingRadius`=2.018418, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=47620;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5266316, `CombatReach`=0.5 WHERE `DisplayID`=76384;
UPDATE `creature_model_info` SET `BoundingRadius`=1.679492, `CombatReach`=1.35, `VerifiedBuild`=27843 WHERE `DisplayID`=34159;

DELETE FROM `npc_vendor` WHERE (`entry`=138151 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=138151 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138151 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123730 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(138151, 10, 163203, 0, 6426, 1, 0, 0, 27843), -- Hypersensitive Azeritometer Sensor
(138151, 9, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(138151, 8, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(138151, 7, 160298, 0, 0, 1, 0, 0, 27843), -- Durable Flux
(138151, 6, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(138151, 5, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(138151, 4, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(138151, 3, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(138151, 2, 160502, 0, 0, 1, 0, 0, 27843), -- Chemical Blasting Cap
(138151, 1, 163569, 0, 0, 1, 0, 0, 27843), -- Insulated Wiring
(123730, 1, 37460, 0, 0, 1, 0, 0, 27843); -- Rope Pet Leash


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=135133 AND `ID`=1) OR (`CreatureID`=135134 AND `ID`=1) OR (`CreatureID`=134803 AND `ID`=1) OR (`CreatureID`=134808 AND `ID`=1) OR (`CreatureID`=135735 AND `ID`=1) OR (`CreatureID`=135732 AND `ID`=1) OR (`CreatureID`=136926 AND `ID`=1) OR (`CreatureID`=136925 AND `ID`=1) OR (`CreatureID`=128681 AND `ID`=1) OR (`CreatureID`=128685 AND `ID`=1) OR (`CreatureID`=128678 AND `ID`=1) OR (`CreatureID`=136191 AND `ID`=1) OR (`CreatureID`=129650 AND `ID`=1) OR (`CreatureID`=129772 AND `ID`=1) OR (`CreatureID`=135099 AND `ID`=1) OR (`CreatureID`=129781 AND `ID`=1) OR (`CreatureID`=130513 AND `ID`=1) OR (`CreatureID`=138519 AND `ID`=1) OR (`CreatureID`=129776 AND `ID`=1) OR (`CreatureID`=135094 AND `ID`=1) OR (`CreatureID`=135287 AND `ID`=1) OR (`CreatureID`=135390 AND `ID`=1) OR (`CreatureID`=134601 AND `ID`=1) OR (`CreatureID`=135396 AND `ID`=1) OR (`CreatureID`=138411 AND `ID`=2) OR (`CreatureID`=138411 AND `ID`=1) OR (`CreatureID`=129778 AND `ID`=1) OR (`CreatureID`=135968 AND `ID`=1) OR (`CreatureID`=135970 AND `ID`=1) OR (`CreatureID`=135965 AND `ID`=1) OR (`CreatureID`=135966 AND `ID`=1) OR (`CreatureID`=135243 AND `ID`=1) OR (`CreatureID`=135093 AND `ID`=1) OR (`CreatureID`=135990 AND `ID`=1) OR (`CreatureID`=135111 AND `ID`=1) OR (`CreatureID`=135191 AND `ID`=1) OR (`CreatureID`=135188 AND `ID`=1) OR (`CreatureID`=135187 AND `ID`=1) OR (`CreatureID`=135186 AND `ID`=1) OR (`CreatureID`=130603 AND `ID`=1) OR (`CreatureID`=129903 AND `ID`=1) OR (`CreatureID`=134745 AND `ID`=1) OR (`CreatureID`=142485 AND `ID`=1) OR (`CreatureID`=142484 AND `ID`=1) OR (`CreatureID`=129754 AND `ID`=1) OR (`CreatureID`=134709 AND `ID`=1) OR (`CreatureID`=135298 AND `ID`=1) OR (`CreatureID`=135292 AND `ID`=1) OR (`CreatureID`=130514 AND `ID`=1) OR (`CreatureID`=134561 AND `ID`=1) OR (`CreatureID`=138209 AND `ID`=1) OR (`CreatureID`=129647 AND `ID`=1) OR (`CreatureID`=130396 AND `ID`=1) OR (`CreatureID`=135123 AND `ID`=1) OR (`CreatureID`=138214 AND `ID`=1) OR (`CreatureID`=134560 AND `ID`=1) OR (`CreatureID`=134559 AND `ID`=1) OR (`CreatureID`=134558 AND `ID`=1) OR (`CreatureID`=135090 AND `ID`=1) OR (`CreatureID`=137981 AND `ID`=1) OR (`CreatureID`=135132 AND `ID`=3) OR (`CreatureID`=135132 AND `ID`=2) OR (`CreatureID`=135132 AND `ID`=1) OR (`CreatureID`=137970 AND `ID`=1) OR (`CreatureID`=129549 AND `ID`=1) OR (`CreatureID`=129542 AND `ID`=1) OR (`CreatureID`=129544 AND `ID`=1) OR (`CreatureID`=129848 AND `ID`=1) OR (`CreatureID`=129831 AND `ID`=1) OR (`CreatureID`=129874 AND `ID`=1) OR (`CreatureID`=129821 AND `ID`=1) OR (`CreatureID`=129927 AND `ID`=1) OR (`CreatureID`=129811 AND `ID`=1) OR (`CreatureID`=129453 AND `ID`=1) OR (`CreatureID`=129450 AND `ID`=1) OR (`CreatureID`=129451 AND `ID`=1) OR (`CreatureID`=136596 AND `ID`=1) OR (`CreatureID`=129354 AND `ID`=1) OR (`CreatureID`=122725 AND `ID`=1) OR (`CreatureID`=133930 AND `ID`=1) OR (`CreatureID`=133938 AND `ID`=1) OR (`CreatureID`=133924 AND `ID`=1) OR (`CreatureID`=139132 AND `ID`=1) OR (`CreatureID`=139157 AND `ID`=1) OR (`CreatureID`=139158 AND `ID`=1) OR (`CreatureID`=139159 AND `ID`=1) OR (`CreatureID`=139138 AND `ID`=1) OR (`CreatureID`=139153 AND `ID`=1) OR (`CreatureID`=139154 AND `ID`=1) OR (`CreatureID`=139155 AND `ID`=1) OR (`CreatureID`=128682 AND `ID`=1) OR (`CreatureID`=128978 AND `ID`=1) OR (`CreatureID`=128686 AND `ID`=1) OR (`CreatureID`=133929 AND `ID`=1) OR (`CreatureID`=122723 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(135133, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(135134, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(134803, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(134808, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(135735, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(135732, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(136926, 1, 14873, 0, 0, 0, 0, 0, 0, 0, 0), -- Tideflat Seer
(136925, 1, 116483, 0, 0, 0, 0, 0, 0, 0, 0), -- Tideflat Gillmonger
(128681, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Warbringer
(128685, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Mender
(128678, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Skycaller
(136191, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Suppressor
(129650, 1, 156876, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Beastlord
(129772, 1, 0, 0, 0, 0, 0, 0, 156712, 0, 0), -- Faithless Deadeye
(135099, 1, 155284, 0, 0, 155300, 0, 0, 0, 0, 0), -- Kiro
(129781, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Scrollkeeper
(130513, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Acolyte
(138519, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Vorrik
(129776, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Spireguard
(135094, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(135287, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Guardian
(135390, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Vorrik
(134601, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Emperor Korthek
(135396, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(138411, 2, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Vorrik
(138411, 1, 0, 0, 0, 151335, 0, 0, 0, 0, 0), -- Vorrik
(129778, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Skycaller
(135968, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Scrollkeeper
(135970, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Spireguard
(135965, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Acolyte
(135966, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Scrollkeeper
(135243, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Vulpera Slave
(135093, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(135990, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Eradicator
(135111, 1, 0, 0, 0, 151335, 0, 0, 0, 0, 0), -- Vorrik
(135191, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Vulpera Slave
(135188, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Faithless Slaver
(135187, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Ravager
(135186, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Oppressor
(130603, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Beastbreaker Hakid
(129903, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Muzzler
(134745, 1, 160050, 0, 0, 0, 0, 0, 0, 0, 0), -- Skycarver Krakit
(142485, 1, 0, 0, 0, 0, 0, 0, 37249, 0, 0), -- 7th Legion Scout
(142484, 1, 1493, 0, 0, 143, 0, 0, 2552, 0, 0), -- 7th Legion Marine
(129754, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Shath'kar
(134709, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Skycaller
(135298, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Skycaller Apprentice
(135292, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Champion
(130514, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Champion Aspirant
(134561, 1, 0, 0, 0, 0, 0, 0, 156712, 0, 0), -- Faithless Raider
(138209, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Oppressor
(129647, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Faithless Stalker
(130396, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Appraiser Versik
(135123, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Watcher
(138214, 1, 0, 0, 0, 0, 0, 0, 156712, 0, 0), -- Faithless Raider
(134560, 1, 156876, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Auditor
(134559, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Faithless Slaver
(134558, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Oppressor
(135090, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(137981, 1, 155284, 0, 0, 155300, 0, 0, 0, 0, 0), -- Kiro
(135132, 3, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Defiant Scrapper
(135132, 2, 155277, 0, 0, 0, 0, 0, 0, 0, 0), -- Defiant Scrapper
(135132, 1, 1906, 0, 0, 0, 0, 0, 0, 0, 0), -- Defiant Scrapper
(137970, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Vorrik
(129549, 1, 134779, 0, 0, 134779, 0, 0, 0, 0, 0), -- Omi
(129542, 1, 60765, 0, 0, 0, 0, 0, 0, 0, 0), -- Kenzou
(129544, 1, 1904, 0, 0, 151606, 0, 0, 0, 0, 0), -- Tacha
(129848, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Fangcaller Hrillik
(129831, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Ridge Subjugator
(129874, 1, 0, 0, 0, 0, 0, 0, 156712, 0, 0), -- Faithless Trapper
(129821, 1, 0, 0, 0, 0, 0, 0, 156712, 0, 0), -- Ridge Muzzler
(129927, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Ridge Skycaller
(129811, 1, 157852, 0, 0, 157852, 0, 0, 0, 0, 0), -- Ridge Beastbreaker
(129453, 1, 60765, 0, 0, 0, 0, 0, 0, 0, 0), -- Kenzou
(129450, 1, 1904, 0, 0, 151606, 0, 0, 0, 0, 0), -- Tacha
(129451, 1, 134779, 0, 0, 134779, 0, 0, 0, 0, 0), -- Omi
(136596, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(129354, 1, 0, 0, 0, 12745, 0, 0, 0, 0, 0), -- Rhan'ka
(122725, 1, 129189, 0, 0, 0, 0, 0, 0, 0, 0), -- Zulsan
(133930, 1, 95647, 0, 0, 0, 0, 0, 0, 0, 0), -- Sandfury Mindthief
(133938, 1, 2089, 0, 0, 2089, 0, 0, 0, 0, 0), -- Sandfury Bandit
(133924, 1, 116536, 0, 0, 0, 0, 0, 0, 0, 0), -- Gozda'kun the Slaver
(139132, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139157, 1, 126433, 0, 0, 126433, 0, 0, 0, 0, 0), -- Commander Grogash
(139158, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139159, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139138, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139153, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139154, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(139155, 1, 136595, 0, 0, 136595, 0, 0, 0, 0, 0), -- Horde Scout
(128682, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Defender
(128978, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Warbringer
(128686, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Kamid the Trapper
(133929, 1, 2089, 0, 0, 2089, 0, 0, 0, 0, 0), -- Sandfury Bandit
(122723, 1, 0, 0, 0, 12745, 0, 0, 0, 0, 0); -- Rhan'ka


DELETE FROM `gossip_menu` WHERE (`MenuId`=22433 AND `TextId`=34418) OR (`MenuId`=22402 AND `TextId`=34364) OR (`MenuId`=22361 AND `TextId`=35048) OR (`MenuId`=22678 AND `TextId`=35046) OR (`MenuId`=22369 AND `TextId`=35013) OR (`MenuId`=21830 AND `TextId`=33360) OR (`MenuId`=22368 AND `TextId`=35045) OR (`MenuId`=22376 AND `TextId`=34181) OR (`MenuId`=22356 AND `TextId`=35044) OR (`MenuId`=22471 AND `TextId`=34508) OR (`MenuId`=22472 AND `TextId`=34509) OR (`MenuId`=22651 AND `TextId`=34320) OR (`MenuId`=22406 AND `TextId`=34368) OR (`MenuId`=22405 AND `TextId`=34367) OR (`MenuId`=22404 AND `TextId`=34366) OR (`MenuId`=22403 AND `TextId`=34365) OR (`MenuId`=21393 AND `TextId`=33253) OR (`MenuId`=22264 AND `TextId`=34126) OR (`MenuId`=21767 AND `TextId`=33252) OR (`MenuId`=22699 AND `TextId`=35083) OR (`MenuId`=21140 AND `TextId`=33235) OR (`MenuId`=22258 AND `TextId`=34113) OR (`MenuId`=21140 AND `TextId`=32046) OR (`MenuId`=21229 AND `TextId`=32210) OR (`MenuId`=21228 AND `TextId`=32209) OR (`MenuId`=21230 AND `TextId`=32211);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(22433, 34418, 27843), -- 135625 (Vorrik)
(22402, 34364, 27843), -- 135355 (Meerah)
(22361, 35048, 27843), -- 135099 (Kiro)
(22678, 35046, 27843), -- 138411 (Vorrik)
(22369, 35013, 27843), -- 135111 (Vorrik)
(21830, 33360, 27843), -- 129763 (Rakjan the Unbroken)
(22368, 35045, 27843), -- 135110 (Vorrik)
(22376, 34181, 27843), -- 135172 (Vorrik)
(22356, 35044, 27843), -- 135090 (Nisha)
(22471, 34508, 27843), -- 130342 (Vulpera Slave)
(22472, 34509, 27843), -- 130342 (Vulpera Slave)
(22651, 34320, 27843), -- 137981 (Kiro)
(22406, 34368, 27843), -- 135355 (Meerah)
(22405, 34367, 27843), -- 135355 (Meerah)
(22404, 34366, 27843), -- 135355 (Meerah)
(22403, 34365, 27843), -- 135355 (Meerah)
(21393, 33253, 27843), -- 123730 (Man'zul)
(22264, 34126, 27843), -- 129330 (Bladeguard Tarkaj)
(21767, 33252, 27843), -- 123728 (Grenja)
(22699, 35083, 27843), -- 123728 (Grenja)
(21140, 33235, 27843), -- 122723 (Rhan'ka)
(22258, 34113, 27843), -- 138749 (Rhan'ka)
(21140, 32046, 27843), -- 122723 (Rhan'ka)
(21229, 32210, 27843), -- 271741
(21228, 32209, 27843), -- 271744
(21230, 32211, 27843); -- 271134

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=21797 AND `OptionIndex`=0) OR (`MenuId`=22433 AND `OptionIndex`=0) OR (`MenuId`=22402 AND `OptionIndex`=1) OR (`MenuId`=22402 AND `OptionIndex`=0) OR (`MenuId`=22678 AND `OptionIndex`=0) OR (`MenuId`=21830 AND `OptionIndex`=0) OR (`MenuId`=22471 AND `OptionIndex`=0) OR (`MenuId`=22471 AND `OptionIndex`=2) OR (`MenuId`=22402 AND `OptionIndex`=3) OR (`MenuId`=22402 AND `OptionIndex`=2) OR (`MenuId`=22406 AND `OptionIndex`=0) OR (`MenuId`=22405 AND `OptionIndex`=0) OR (`MenuId`=22404 AND `OptionIndex`=0) OR (`MenuId`=22403 AND `OptionIndex`=0) OR (`MenuId`=21393 AND `OptionIndex`=2) OR (`MenuId`=21393 AND `OptionIndex`=1) OR (`MenuId`=21229 AND `OptionIndex`=3) OR (`MenuId`=21229 AND `OptionIndex`=2) OR (`MenuId`=21229 AND `OptionIndex`=1) OR (`MenuId`=21229 AND `OptionIndex`=0) OR (`MenuId`=21228 AND `OptionIndex`=3) OR (`MenuId`=21228 AND `OptionIndex`=2) OR (`MenuId`=21228 AND `OptionIndex`=1) OR (`MenuId`=21230 AND `OptionIndex`=3) OR (`MenuId`=21230 AND `OptionIndex`=2) OR (`MenuId`=21230 AND `OptionIndex`=1) OR (`MenuId`=21230 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21797, 0, 0, 'Who are the Faithless?', 140439, 27843),
(22433, 0, 0, 'I\'m ready. Let\'s go find the others.', 150472, 27843),
(22402, 1, 0, 'How do you sneak the slaves out?', 149758, 27843),
(22402, 0, 0, 'What are you doing here?', 136428, 27843), -- OptionBroadcastTextID: 35775 - 38471 - 57803 - 57891 - 66486 - 81341 - 86824 - 123345 - 156063 - 149757 - 136428
(22678, 0, 0, 'Vorrik, I\'m ready to face Emperor Korthek.', 149778, 27843),
(21830, 0, 0, 'Let\'s ride.', 141183, 27843), -- OptionBroadcastTextID: 77608 - 128180 - 141183
(22471, 0, 0, '<Free the slave and give them a weapon to fight with.>', 151277, 27843), -- OptionBroadcastTextID: 151279 - 151277
(22471, 2, 0, 'I\'ll return when I find a weapon for you.', 151289, 27843),
(22402, 3, 0, 'Where is Kiro?', 149759, 27843),
(22402, 2, 0, 'Where is Nisha?', 149760, 27843),
(22406, 0, 0, 'I want to ask about something else.', 149761, 27843),
(22405, 0, 0, 'I want to ask about something else.', 149761, 27843),
(22404, 0, 0, 'I want to ask about something else.', 149761, 27843),
(22403, 0, 0, 'I want to ask about something else.', 149761, 27843),
(21393, 2, 0, 'I\'d like to heal and revive my battle pets.', 64115, 27843),
(21393, 1, 1, 'I\'m looking for a lost companion.', 56613, 27843),
(21229, 3, 0, '<Introduce yourself politely.>', 132672, 27843), -- OptionBroadcastTextID: 133960 - 133959 - 132672
(21229, 2, 0, '<Attempt to beat Grenja in a staring contest.>', 132677, 27843),
(21229, 1, 0, 'I bet you\'d make a great doorstop.', 132676, 27843),
(21229, 0, 0, 'Well met!', 132675, 27843), -- OptionBroadcastTextID: 128918 - 155850 - 132675
(21228, 3, 0, '<Introduce yourself politely.>', 132672, 27843), -- OptionBroadcastTextID: 133960 - 133959 - 132672
(21228, 2, 0, '<Mumble something about how crazy this is.>', 132671, 27843),
(21228, 1, 0, 'I like your hat.', 132670, 27843),
(21230, 3, 0, '<Introduce yourself politely.>', 132672, 27843), -- OptionBroadcastTextID: 133960 - 133959 - 132672
(21230, 2, 0, '<Whisper that you think his eyepatch is stupid.>', 132681, 27843),
(21230, 1, 0, 'Can I have your stuff?', 132680, 27843),
(21230, 0, 0, 'Your eyepatch is very fearsome.', 132679, 27843);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionIcon`=0, `OptionText`='Umm... Hello?', `OptionBroadcastTextId`=132669, `VerifiedBuild`=27843 WHERE (`MenuId`=21228 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=22471 AND `OptionIndex`=2) OR (`MenuId`=22406 AND `OptionIndex`=0) OR (`MenuId`=22402 AND `OptionIndex`=3) OR (`MenuId`=22405 AND `OptionIndex`=0) OR (`MenuId`=22402 AND `OptionIndex`=2) OR (`MenuId`=22404 AND `OptionIndex`=0) OR (`MenuId`=22402 AND `OptionIndex`=1) OR (`MenuId`=22403 AND `OptionIndex`=0) OR (`MenuId`=22402 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(22471, 2, 22472, 0),
(22406, 0, 22402, 0),
(22402, 3, 22406, 1),
(22405, 0, 22402, 0),
(22402, 2, 22405, 1),
(22404, 0, 22402, 0),
(22402, 1, 22404, 1),
(22403, 0, 22402, 0),
(22402, 0, 22403, 1);





UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=135133; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=135134; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=495, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=134810; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2136, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138601; -- Crypt Fungarian
UPDATE `creature_template` SET `gossip_menu_id`=21306, `minlevel`=120, `maxlevel`=120, `faction`=2714, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=134803; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555264, `unit_flags2`=2048 WHERE `entry`=134958; -- Personal Phase Controller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_walk`=0.4, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2099200 WHERE `entry`=134846; -- General Jakra'zet
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=134857; -- Sandfury Troll
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=134808; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2099200 WHERE `entry`=134858; -- Sandfury Troll
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=135738; -- Entangling Tendrils
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=135735; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138594; -- Crypt Fungling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128946; -- N'raqi Eradicator
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=18432 WHERE `entry`=135695; -- Entangling Tendrils
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=135732; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=135676; -- Faceless Tendril
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.4, `speed_run`=0.2857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134826; -- Cavern Hatchling
UPDATE `creature_template` SET `gossip_menu_id`=22433, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135625; -- Vorrik
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=134595; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=134640; -- Serrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=140401; -- Sandfury Assassin
UPDATE `creature_template` SET `gossip_menu_id`=21797, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129588; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136926; -- Tideflat Seer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128691; -- Izarn
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=134611; -- Seriah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136925; -- Tideflat Gillmonger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128996; -- Brineshell Crab
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130429; -- Ranishu Swarmer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128683; -- Faithless Bonepicker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130427; -- Ranishu Devourer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130434; -- Ranishu Scorcher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480, `dynamicflags`=128 WHERE `entry`=129120; -- Temple Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128681; -- Faithless Warbringer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128685; -- Faithless Mender
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129180; -- Warbringer Hozzik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128678; -- Faithless Skycaller
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=137681; -- King Clickyclack
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2030, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124681; -- Bonepicker Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124683; -- Bonepicker Pup
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136191; -- Faithless Suppressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=18432, `VehicleId`=5870 WHERE `entry`=129638; -- Tamed Krolusk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129650; -- Faithless Beastlord
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129772; -- Faithless Deadeye
UPDATE `creature_template` SET `gossip_menu_id`=22361, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135099; -- Kiro
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=134633; -- (Bunny) Location: Temple of Sethraliss
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129781; -- Faithless Scrollkeeper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130513; -- Faithless Acolyte
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138519; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129776; -- Faithless Spireguard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135094; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134713; -- Korthek's Student
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135287; -- Faithless Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2117, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135390; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134601; -- Emperor Korthek
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2981, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135396; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=138411; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2628, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=51200, `unit_flags3`=1 WHERE `entry`=135957; -- Sethrak Cannon
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129778; -- Faithless Skycaller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135968; -- Faithless Scrollkeeper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135970; -- Faithless Spireguard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135965; -- Faithless Acolyte
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135966; -- Faithless Scrollkeeper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135967; -- Korthek's Student
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=134610; -- Faithless Skycaller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=135243; -- Vulpera Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2981, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135093; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135990; -- Faithless Eradicator
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135111; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2633, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=135193; -- Released Crawg
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=104859648, `unit_flags3`=1 WHERE `entry`=138398; -- (Bunny) Barrier
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1375, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=71305216 WHERE `entry`=135214; -- Electric Wall
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2633, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=135191; -- Vulpera Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=135188; -- Faithless Slaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=135187; -- Faithless Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=135186; -- Faithless Oppressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129910; -- Scion of Rakjan
UPDATE `creature_template` SET `gossip_menu_id`=21830, `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129763; -- Rakjan the Unbroken
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129798; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=129787; -- Scion of Rakjan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=32768, `unit_flags3`=1 WHERE `entry`=135537; -- Wounded Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=130603; -- Beastbreaker Hakid
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=134626; -- (Bunny) Location: Crackling Ridge Cave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129903; -- Faithless Muzzler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134745; -- Skycarver Krakit
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=142485; -- 7th Legion Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1802, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=142484; -- 7th Legion Marine
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129754; -- Shath'kar
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138596; -- Gutgut
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=138600; -- Vulpera Prisoner
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134709; -- Faithless Skycaller
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=138585; -- East Slave Market
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=134820; -- Wounded Slave
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=135485; -- (Bunny) Market Fires - East Large
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135298; -- Skycaller Apprentice
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=135463; -- (Bunny) Market Fires - East Small Fire Visual
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135027; -- Faithless Dealer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=138584; -- Central Slave Market
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=134621; -- Tortollan Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135018; -- Faithless Dealer
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=135484; -- (Bunny) Market Fires - Central - Large
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=134618; -- Vulpera Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134625; -- Warmother Captive
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=135462; -- (Bunny) Market Fires - Central - Small Fire
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135292; -- Faithless Champion
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130514; -- Champion Aspirant
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=138580; -- West Slave Market
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=134568; -- (Bunny) Market Fire - West - Small Fire
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=135482; -- (Bunny - Quest Spell Target) Market Fire - West - Large
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129784; -- Faithless Citizen
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135110; -- Vorrik
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=138337; -- (Bunny) Suppression Spire KILL CREDIT
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134563; -- Captured Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134556; -- Faithless Dealer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135352; -- Rescued Kid
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138233; -- Rescued Kid
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138234; -- Rescued Kid
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138235; -- Rescued Kid
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134561; -- Faithless Raider
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=126893; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=134557; -- Maimed Krolusk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138209; -- Faithless Oppressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129647; -- Faithless Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134562; -- Captured Krolusk
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138239; -- Vulpera Kid
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138238; -- Vulpera Kid
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138236; -- Vulpera Kid
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138237; -- Vulpera Kid
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=130396; -- Appraiser Versik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=135123; -- Faithless Watcher
UPDATE `creature_template` SET `gossip_menu_id`=22402, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135355; -- Meerah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=138151; -- Tinkerin' Taji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=138240; -- Rescued Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=135354; -- Rescued Slave
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=119, `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=131072, `unit_flags3`=17 WHERE `entry`=134324; -- Training Dummy
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138218; -- Captured Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138214; -- Faithless Raider
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=8192, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=135385; -- Lugo the Windrider
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134560; -- Faithless Auditor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=130342; -- Vulpera Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `HoverHeight`=2 WHERE `entry`=138159; -- Trained Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134559; -- Faithless Slaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134558; -- Faithless Oppressor
UPDATE `creature_template` SET `gossip_menu_id`=22356, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135090; -- Nisha
UPDATE `creature_template` SET `gossip_menu_id`=22651, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137981; -- Kiro
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135172; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=135128; -- Faithless Centurion
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135132; -- Defiant Scrapper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=137970; -- Vorrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=634, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139361; -- Krolusk Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136553; -- Saltspine Krolusk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=129549; -- Omi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=129542; -- Kenzou
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `BaseAttackTime`=1000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=33556480 WHERE `entry`=129544; -- Tacha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2099200, `VehicleId`=5687 WHERE `entry`=129856; -- Hrillik's Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587264, `unit_flags2`=2048 WHERE `entry`=129848; -- Fangcaller Hrillik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=5686 WHERE `entry`=129761; -- Subjugated Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129799; -- Pterrordax Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129831; -- Ridge Subjugator
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=134971; -- Defender of Rakjan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129874; -- Faithless Trapper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129821; -- Ridge Muzzler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129927; -- Ridge Skycaller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816, `unit_flags3`=1, `VehicleId`=6006 WHERE `entry`=129759; -- Imprisoned Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129811; -- Ridge Beastbreaker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=129434; -- Zak'rajan the Undying
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129506; -- Specter of Mugabu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129500; -- Sandspinner Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129507; -- Specter of Jam'jen
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129476; -- Bloated Krolusk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=138923; -- Malfunctioning Golem
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=127908; -- Ranishu
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129457; -- Lifeless Guardian
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=5668 WHERE `entry`=129465; -- Ranishu Vehicle - Eat Side
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129473; -- Ranishu Nibbler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129464; -- Ranishu Nibbler
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=5670 WHERE `entry`=129472; -- Ranishu Vehicle - Eat Down
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129672; -- Tortured Spirit
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137721; -- Ruincrawler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135727; -- Ranishu Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=31, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124211; -- Ruincrawler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129436; -- Soul-Trapped Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=130070; -- Canyon Vulture
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=5604 WHERE `entry`=127855; -- Ranishu Vehicle - Eat Side
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=129497; -- Sandspinner Spiderling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=129453; -- Kenzou
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129450; -- Tacha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129451; -- Omi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2573, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129496; -- Sandspinner Weaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570688256, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124795; -- Bonepicker Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129505; -- Sandspinner Hunter
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000 WHERE `entry`=129499; -- Sandspinner Egg
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129667; -- Lifeless Golem
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=142054; -- Kusa
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129474; -- Ranishu Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=136596; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135742; -- Risen Anklebiter
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129411; -- Zunashi the Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=135743; -- Risen Ravasaur
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129410; -- Risen Ravasaur
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=129357; -- Grenja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=66179, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129354; -- Rhan'ka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2976, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=129319; -- Bladeguard Tarkaj
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=8192, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=129365; -- Volni
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=133986; -- Screaming Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122725; -- Zulsan
UPDATE `creature_template` SET `gossip_menu_id`=22699, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123728; -- Grenja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123729; -- Volni
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123730; -- Man'zul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2944, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2052 WHERE `entry`=143661; -- Kidnapped Mind Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133930; -- Sandfury Mindthief
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133946; -- Kidnapped Mind Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133947; -- Kidnapped Mind Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133938; -- Sandfury Bandit
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=133924; -- Gozda'kun the Slaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2944, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2052 WHERE `entry`=133931; -- Kidnapped Mind Slave
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1732, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139121; -- Arcanist Elleryn
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139132; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139157; -- Commander Grogash
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139158; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139159; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139138; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139153; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139154; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2201, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139155; -- Horde Scout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=124187; -- Bilewing Queen
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133838; -- Drained Bilewing Worker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=714, `npcflag`=642, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=133833; -- Rikati
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=124172; -- Bilewing Infester
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192, `VehicleId`=5659 WHERE `entry`=124182; -- Infested Saurolisk
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=131072 WHERE `entry`=124183; -- Bilewing Egg
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=130270; -- Loose Bilewing Hive
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142449; -- Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124526; -- Krolusk Dunecrawler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128682; -- Faithless Defender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128978; -- Faithless Warbringer
UPDATE `creature_template` SET `gossip_menu_id`=22258, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138749; -- Rhan'ka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=163840, `unit_flags2`=2048 WHERE `entry`=122750; -- Deathsnap Hatchling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128686; -- Kamid the Trapper
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=129479; -- (Bunny) Sessile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130409; -- Bonebeak Fledgling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2900, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=134116; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=129259; -- Deathsnap Elder
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124627; -- Bonepicker Hyena
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=5431 WHERE `entry`=122749; -- Deathsnap Caretaker
UPDATE `creature_template` SET `unit_flags`=570688256 WHERE `entry`=123473; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123571; -- Deathsnap Carver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123572; -- Deathsnap Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=124177; -- Bilewing Creeper
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=124536; -- Bilewing Crippler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124179; -- Bloated Saurolisk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1602, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=139752; -- Elisa Veilsong
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2162, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=139749; -- Daxx Bombhand
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133929; -- Sandfury Bandit
UPDATE `creature_template` SET `gossip_menu_id`=21140, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122723; -- Rhan'ka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137356; -- Whistlebloom Hatchling
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=100665344, `unit_flags3`=1 WHERE `entry`=129404; -- Tarkaj Revive Location - Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=136593; -- Sevriss
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=133853; -- Bloodcrest
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192, `VehicleId`=5657 WHERE `entry`=129297; -- Infested Saurolisk
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=131072 WHERE `entry`=129299; -- Whistlebloom Egg
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=129288; -- Whistlebloom Sentry
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2136, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133897; -- Thirsty Calf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2136, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133896; -- Defiant Riverbeast
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=16, `unit_flags2`=2048 WHERE `entry`=133901; -- Whistlebloom Impaler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=133904; -- Loose Whistlebloom Hive
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=129287; -- Whistlebloom Drone
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=129289; -- Whistlebloom Harvester
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133887; -- Whistlebloom Hatchling
UPDATE `creature_template` SET `unit_flags`=33849344 WHERE `entry`=126645; -- -Unknown-

DELETE FROM `quest_template` WHERE `ID` IN (50551 /*-Unknown-*/, 49766 /*-Unknown-*/, 50703 /*-Unknown-*/, 50702 /*-Unknown-*/, 50904 /*-Unknown-*/, 50617 /*-Unknown-*/, 49437 /*-Unknown-*/, 50757 /*-Unknown-*/, 49669 /*-Unknown-*/, 50805 /*-Unknown-*/, 50751 /*-Unknown-*/, 50550 /*-Unknown-*/, 50752 /*-Unknown-*/, 50750 /*-Unknown-*/, 49003 /*-Unknown-*/, 49002 /*-Unknown-*/, 48329 /*-Unknown-*/, 50748 /*-Unknown-*/, 49141 /*-Unknown-*/, 49668 /*-Unknown-*/, 50746 /*-Unknown-*/, 49666 /*-Unknown-*/, 49665 /*-Unknown-*/, 49667 /*-Unknown-*/, 49664 /*-Unknown-*/, 50745 /*-Unknown-*/, 48330 /*-Unknown-*/, 49139 /*-Unknown-*/, 48331 /*-Unknown-*/, 48335 /*-Unknown-*/, 48332 /*-Unknown-*/, 48334 /*-Unknown-*/, 49001 /*-Unknown-*/, 48840 /*-Unknown-*/, 48322 /*-Unknown-*/, 48320 /*-Unknown-*/, 48321 /*-Unknown-*/, 47564 /*-Unknown-*/, 47638 /*-Unknown-*/, 50328 /*-Unknown-*/, 51718 /*-Unknown-*/, 51717 /*-Unknown-*/, 47503 /*-Unknown-*/, 47502 /*-Unknown-*/, 47498 /*-Unknown-*/, 47501 /*-Unknown-*/, 51164 /*-Unknown-*/, 47497 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `ScalingFactionGroup`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(50551, 2, -1, 5, 120, 0, 110, -441, 81, 0, 0, 8, 3, 824000, 8, 1, 746550, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Temple of Sethraliss: Avatar of the Loa', 'Enter the Temple of Sethraliss and heal the avatar of the loa.', 'We cannot let Mythrax bring his destruction upon this world once more. \n\nWe need our loa now more than ever, but she has yet to return to us.\n\nThe time of her rebirth has passed. Someone, or something, must be preventing her awakening.\n\nEnter her resting place and see what you can uncover.', '', '', 1553, 0, 0, 0, 600, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49766, 0, -1, 5, 120, 0, 110, 8499, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Your Next Move', 'Choose your next move in Zandalar.', 'We have some thoughts on the best way to win over the Zandalari.\n\nThe princess is heading to Nazmir to take the fight to the blood trolls. Her voice carries much weight with the council and her father.\n\nGeneral Jakra\'zet detests the Horde. Removing his voice from the Zanchuli Council will greatly improve our chances here.\n\nWe should also keep working on winning over the King here in Zuldazar. This city is vast and has many secrets.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50703, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 20600, 1, 1, 12450, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Informing the Horde', 'Speak with Baine Bloodhoof.', 'General Jakra\'zet has been defeated, but his plan to summon Mythrax succeeded despite our best efforts.\n\nWere it not for the mercy of Sethraliss, I doubt we would have made it out of Atul\'Aman alive.\n\nWe must inform our allies of what has transpired in Vol\'dun.\n\nI\'ll speak with princess Talanji myself. You should go and speak with the Horde. We need all the help we can get now.\n\nI\'m sure our paths will cross again, $n. It was an honor fighting with you.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50702, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 7, 1, 412000, 6, 1, 186650, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 6, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 924, 7, 'Defeat Jakra\'zet', 'Defeat Jakra\'zet.', 'Jakra\'zet is summoning Mythrax the Unraveler!\n\nWe cannot allow the ritual to continue. Jakra\'zet must be stopped before it\'s too late!\n\nLead the way, $n. We\'ll be right behind you.\n\nLet\'s go!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50904, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 0, 0, 1, 12450, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 574619656, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Abandoned Passage', 'Find Bladeguard Kaja and Warguard Rakera in Atul\'Aman.', 'My people have known about this ancient passageway for generations, but none have dared enter before now.\n\nThe tunnel leads to the tomb of Mythrax the Unraveler and it is said that his power still radiates within the cavern. Who knows what horrors await us inside...\n\nIt appears that your friends have already gone inside to face Jakra\'zet and stop him from raising Mythrax from the dead.\n\nWe don\'t have time to waste. We must find Kaja and Rakera before they confront Jakra\'zet on their own!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50617, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 0, 0, 1, 12450, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Atul\'Aman', 'Meet Vorrik at Atul\'Aman.', 'Jakra\'zet and his troops attacked while we were away. \n\nSerrik fought well, but it wasn\'t enough. The keys are gone, and it\'s only a matter of time before the barrier is broken.\n\nYour friends have already given chase. \n\nJakra\'zet must not be allowed to resurrect Mythrax the Unraveler. He must be stopped before it\'s too late!\n\nWe don\'t have much time. \n\nMeet me at Atul\'Aman! We must catch up with Kaja and Rakera and stop the ritual!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49437, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 412000, 6, 1, 155550, 0, 0, 0, 280305, 0, 0, 0, 0, 1, 0, 169869320, 0, 0, 0, 0, 80692, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Tattered Note', 'Slay Shath\'kar in the Slithering Gulch.', '<The short, hand-written note is scrawled in blood.>\n\nThey captured me soon after I was exiled. I was too weak to be a slave and too starved to be food for the beasts.\n\nThey were going to kill me, but one called Shath\'kar intervened. He said it would be amusing to watch me starve to death among his prisoners.\n\nI have not lived a good life. I deserve nothing. But, to any fellow Zandalari who finds this, I have one request...\n\nStick a blade in Shath\'kar\'s belly and twist it until the snake is dead!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Sethrak trapper who enjoys watching prisoners suffer.', 'Shath\'kar', '', '', 890, 878, 27843), -- -Unknown-
(50757, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 206000, 5, 1, 124400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7340040, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Untame Slaughter', 'Kill $1oa Faithless within the Feeding Pits.', 'The Faithless rely on their krolusks for everything. They are mounts, battle companions, beasts of burden, and often even food to fuel the sethrak empire.\n\nIf we can disrupt their krolusks, we\'ll disrupt their whole empire. One broken wheel stops the caravan, eh?\n\nTake out as many of their krolusk tamers as you can. That\'ll have a longer impact than just killing the krolusks.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49669, 2, -1, 5, 120, 18790, 110, 8501, 0, 0, 0, 6, 1, 412000, 6, 1, 155550, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 175112200, 8192, 0, 0, 0, 84058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Unleash the Beasts', 'Kill Tamer Traskniss to release the crawgs.', 'The Faithless are arrogant hoarders, capturing people and beasts that can never be truly tamed. All to fuel their endless lust for war.\n\nI\'ve even seen their slavers dragging blood trolls and other dark monsters from the swamps of Nazmir.\n\nI heard terrible noises coming out of a cave while I was scouting the feeding pits up ahead.\n\nWhatever monsters they are hiding in there, find a way to free them and let them exact revenge on the Faithless.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Kill Crawg Tamer Traskniss to unleash a horde of crawgs!', 'Crawg Tamer Traskniss', '', '', 890, 878, 27843), -- -Unknown-
(50805, 3, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 2, 412000, 5, 2, 248850, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34275328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 5714, 0, 12261800583900083122, 0, 7, 'Skycaller Shutdown', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50751, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 103000, 3, 1, 62250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Sanctuary Under Siege', 'Meet Vorrik at the Sanctuary of the Devoted.', 'I fear that Emperor Korthek was not lying when he boasted of his foolish plan.\n\nIf General Jakra\'zet attacked the Sanctuary of the Devoted while we were away, there is a good chance that he now has everything needed to resurrect Mythrax.\n\nWe must hurry to the Sanctuary and stop Jakra\'zet. Mythrax must not be reborn!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50550, 2, -1, 5, 120, 18775, 110, 8501, 0, 0, 0, 7, 1, 618000, 7, 1, 186650, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 705691656, 8192, 0, 0, 0, 83655, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Fall of Emperor Korthek', 'Defeat Emperor Korthek.', 'Korthek finally approaches.\n\nIt\'s been many years since I\'ve faced him in battle. When he first rose to power, I failed my people. I will not falter again.\n\nI am prepared to do what must be done. What I should have done long ago.\n\nWe must kill Korthek and take his key to prevent him, Jakra\'zet, or anyone else from ever resurrecting Mythrax.\n\nWhen you are prepared, we will face him together.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Slay Emperor Korthek and retrieve the key to prevent Mythrax\'s summoning!', '', '', '', 890, 878, 27843), -- -Unknown-
(50752, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 272319, 0, 0, 0, 0, 1, 0, 39845896, 8194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Relics of Sethraliss', 'Recover the Skull of the First Skycaller, Rebirth Creed, Sethraliss Sight Stone, and Blood of the Fallen Loa.', 'It may surprise you to learn that the Faithless hoard ancient relics of Sethraliss. I assure you that they do not do so out of reverence or respect, as is proper.\n\nKorthek\'s brood is driven only by greed and an insatiable lust for power. They rip whatever magic they can from the relics, even if it means destroying them in the process.\n\nRescue the ancient artifacts of Sethraliss in the Sacred Sands nearby. We will honor and preserve them in the Sanctuary of the Devoted.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50750, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 272319, 0, 0, 0, 0, 1, 0, 39845896, 8194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Infuriating the Emperor', 'Use Vorrik\'s Bulwark to defeat $1oa Faithless within the Sacred Sands.', 'It seems I underestimated Korthek\'s cowardice. I expected him to be behind the barrier, ready to ambush us. Yet, still he hides.\n\nThat allows us a few moments to prepare. We musn\'t waste them.\n\nWhile I siphon power off of these immense crystals, you must thin the numbers of the Faithless here. I will grant you a powerful boon to speed you in your task.\n\nWhen Korthek arrives, he will require our full attention.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49003, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Vengeance From Above', 'Ride Rakjan the Unbroken and kill Faithless.', 'Emperor Korthek hides deep in his stolen temple below ground. We must create such chaos that he has no choice but to emerge to face us.\n\nThe vulpera riot is a good start, but it will not be enough. Alone, they are no match for the Faithless army.\n\nThankfully, they are not alone.\n\nWe will ride the mighty Rakjan through the skies. While you throw lightning bombs, I\'ll use my charged staff to blast the Faithless armies below.\n\nLet us hope that is enough to lure out Korthek. I am eager to finish this.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49002, 2, -1, 5, 120, 18855, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 154893, 0, 1, 0, 172097544, 8192, 0, 0, 0, 80886, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 154893, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Forced Grounding', 'Use the Faithless Trapper\'s Spear to pull Fangcaller Hrillik\'s pterrordax down from the sky above you, and kill him.', '<This is one of the spears that Faithless trappers use to pull pterrordaxes to the ground. It has a long chain attached to its base.\n\nWith good aim, you could use it to pull a Faithless pterrordax rider to the ground so you could fight them.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Sethrak commander riding a large pterrordax in the sky.', 'Fangcaller Hrillik', '', '', 890, 878, 27843), -- -Unknown-
(48329, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 404000, 6, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Beaten But Not Broken', 'Free the Scion of Rakjan and lead him to Rakjan the Unbroken.', '<Beastbreaker Hakid\'s crystal-encrusted key looks like it will open the large cage nearby.\n\nThe pterrordax inside that cage, Scion of Rakjan, is stronger than the other hatchlings you\'ve seen in the Crackling Ridge. He holds his head high and doesn\'t seem bothered by the myriad scars and fresh wounds that cover his body.\n\nIf you release him, he\'ll likely want to return to Rakjan the Unbroken at the top peak of Crackling Ridge.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50748, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Don\'t Drop It... Yet', 'Collect $1oa Volatile Lightning Bombs from Faithless.', 'The Faithless are training pterrordaxes as mounts so that they can rain down death from the skies.\n\nTheir skycallers have developed a means of storing volatile lightning magic into fragile crystals. Lightning bombs, in the simplest sense. The magic behind it is quite brilliant, really.\n\nThe bombs will be exceptionally useful if we can secure the aid of Rakjan, the powerful and fierce pterrordax at the top of this mountain.\n\nAcquire as many as you can carry, while I will do my best to recruit Rakjan.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49141, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 49003, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 160510, 0, 1, 0, 307232776, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160510, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Diplomacy and Dominance', 'Use Vorrik\'s Staff to drain power from $1oa Faithless Suppression Spires.', 'May I entrust you with my staff, $p? I do not offer this lightly, so do not accept it lightly either.\n\nWe will need every advantage when we face Emperor Korthek, and I\'ve identified an opportunity to increase the power at our disposal.\n\nThe Faithless maintain a series of suppression spires on the ridge above us to subjugate the pterrordax. My staff can drain power from the spires to bolster its own potency.\n\nMeanwhile, I will recruit a much-needed ally for the next stage of our mission.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49668, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 158896, 0, 1, 0, 38928392, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158896, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Light Up the Gulch', 'Torch the slave auction sites in Slithering Gulch.', 'Don\'t mistake my caution for hesitance, $p. I will defend the vulpera with my dying breath... I\'d just prefer to avoid taking that breath today.\n\nWhile Nisha rushes to the front line, I work behind them to ensure our success.\n\nMeet me at the Faithless beast pens if you\'d like to help.\n\nOh, and take this torch. You\'ll be going through their marketplace, where they auction off slaves.\n\nStarting a few well-placed and metaphorically poignant fires along your route will make things easier for all of us.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50746, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Crater Conquered', 'Return to Vorrik.', 'I can take it from here, $p. I\'ll rally these vulpera and march through the trenches creating chaos. Korthek and his armies will be forced to deal with us!\n\nIf you and Vorrik are going to make a move, you should do it now.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49666, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 158884, 0, 1, 0, 40894472, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158884, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Make Them Fear Us', 'Plant $1oa Vulpera Banners into dead Faithless.', 'I carry this banner into every battle because I want the Faithless to fear it. To fear my people.\n\nIf I die in the battlefield, surrounded by Faithless, I will die happy.\n\nOn that day, I will not need a burial or prayers. But I will need someone to pick up my banner and carry it into the next battle.\n\nIf you are of the same mind, plant these banners into the corpse of every Faithless you slay. Let the survivors know who\'s coming for them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49665, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37879816, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Ready to Riot', 'Free and arm $1oa Vulpera Slaves in cages.', 'Do you remember how we met, $p? You were trapped in a Faithless cage, just like the ones in the crater below.\n\nTogether, we slaughtered Faithless and earned your freedom in blood.\n\nThe vulpera trapped in shackles below can do the same. They just need to be given the chance.\n\nSteal Faithless weapons and give them to the vulpera slaves below. They\'ll rise up and help you fight the Faithless.\n\nWe\'re going to start a revolt right under their arrogant noses.', '', '', 1560, 0, 0, 0, 50, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49667, 2, -1, 5, 120, 18785, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 279975, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Little Ones', 'Kill Appraiser Versik and lead the vulpera kids back to Meerah.', 'Just when I thought the Faithless couldn\'t get any worse, I find out that they\'re keeping vulpera children trapped down in that crater!\n\nThe other vulpera we rescued told me that a big sethrak, Appraiser Versik, is inspecting them on the central platform to determine what he can sell them for.\n\nSelling vulpera kids! Oooh, those Faithless make me so angry!\n\nPlease, $p. I\'m no fighter. I can\'t rescue those kids. But if you bring them up here to me, I promise I\'ll get them out of here safely.', '', 'Lead the Vulpera Kids back to Meerah.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49664, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5242888, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Allies in Anarchy', 'Speak with Nisha.', 'Even after all these years, I can feel the ancient power of Sethraliss in this place. My loa endures.\n\nOur task ahead is great and I will need a clear, focused mind to accomplish it. Allow me a few moments to meditate here, like I did in ages past.\n\nIn the meantime, you should help the vulpera stir up trouble however you can. They seem to know you, and a large enough disturbance will distract the Faithless from our mission.\n\nMeet me back here when you\'re done and we\'ll proceed together.', '', 'Speak with Nisha on the nearby ridge.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50745, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 49664, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 5242888, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Infiltrating the Empire', 'Accompany Vorrik to his sanctum.', 'The heart of the Faithless empire rests just beyond this ridge. We will need to move swiftly and quietly to avoid detection once inside.\n\nThankfully, my former dwelling is nearby. I know a passage that should allow us to advance into the fortress with minimal resistance. When you are ready, speak with me and I will show you the way.\n\n<Vorrik looks around suspiciously.>\n\nI expected the Faithless to patrol this area... Keep your eyes open for anything suspicious along the path.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48330, 2, -1, 5, 120, 18776, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 175112200, 8192, 0, 0, 0, 80299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Zandalari Treasure Trove', 'Kill Zak\'rajan the Undying in his throne room.', 'We\'ve looted some quality goods already, but the real reward is still ahead. The big chamber in the back of the ruins is filled with powerful artifacts.\n\nA treasure trove like that is the sort of thing that can save lives and sell for a fortune out here in Vol\'dun.\n\nBut those specters you killed weren\'t lying. Their master or king or whatever is very well-protected in there.\n\nWe\'ll have to take this one down as a group. Let me know when you\'re ready to head up to the chamber.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'The specter of a long-dead Zandalari ruler, protected by the souls he\'s enslaved.', 'Zak\'rajan the Undying', '', '', 890, 878, 27843), -- -Unknown-
(49139, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48330, 5, 1, 404000, 6, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'An Army\'s Arsenal', 'Kill the specters of Mugabu and Jam\'jen, so Omi can ransack the storehouses.', 'It\'s my job to scout out the ruins to identify threats and figure out the best way in.\n\nTwo storehouses contain the majority of the valuable weaponry in the ruins.\n\nUnfortunately, they\'re guarded by specters, powerful Zandalari spirits bound to this place.\n\nI... we need those weapons. Take out the specters so I... we can get to them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48331, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 404000, 6, 1, 82250, 0, 0, 0, 0, 0, 0, 154051, 0, 1, 0, 37879816, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 154051, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Siphoning Souls', 'Kill $1oa Soul-Trapped Guardians and use the Soulcatcher Totem to siphon their souls from their corpse.', '<Tacha rummages through her sack of scavenged supplies.>\n\nSo these golems are powered by Zandalari souls?\n\nNo problem... I\'ve had to deal with that before... I\'ve got just the tool for it.\n\n<Tacha pulls out an eerie Zandalari totem.>\n\nHere it is! Found this ol\' soulcatcher totem in one of the southern ruins years ago. It\'s gotten us out of a few jams.\n\nDisable the golems and throw down this totem next to it. It\'ll siphon off the souls.\n\nKeep the totem. We\'ll need it later.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48335, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Strongest Rope in Vol\'dun', 'Collect $1oa Sandspinner Silks.', 'You ever tried tying up a sethrak with vulture string? Won\'t hold \'em for long.\n\nWhen you really gotta keep something, or someone, tied down, you need sandspinner silk.\n\nThick, pliable, and not as sticky as you\'d think.\n\nThis isn\'t a tailoring lesson. Omi\'s scouting report showed a lot of sandspinners inside the ruin courtyard. Get their silk and bring it back to me.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48332, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 49139, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Ranishu Are Resources', 'Collect $1oa Intact Ranishu Stomachs.', 'We can\'t afford to waste resources out here.\n\nOver time, we\'ve learned to take anything that looks even remotely useful, and be creative using what we have. I\'ve turned a skull into a boat and a sethrak into a tent flap.\n\nI can\'t spit dust when it comes to magic, but I can mix poisons and potions with the best of \'em.\n\nRanishu stomach acid makes wicked poison, but it\'s nasty to collect. Don\'t try to bottle it. Just bring me their stomachs whole and intact. No leaks!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48334, 2, -1, 5, 120, 18782, 110, 8501, 0, 0, 48331, 5, 1, 404000, 6, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 171966472, 8192, 0, 0, 0, 79458, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'They\'ve Got Golems', 'Find a Malfunctioning Golem and discover its power source.', 'I\'ve sacked countless ruins across Vol\'dun. Everything from saurolisk-infested dens to the cursed Port of Zem\'lan.\n\nI don\'t say this to brag. I want you to understand that I know what I\'m doing.\n\nI\'ve survived this long because I take my time, avoid risks, and only take what I need.\n\nThat\'s what we\'ll be doing here today.\n\nOmi reported heavy golem activity on her first scouting trip into the ruins. Zandalari golems are formidable. We need to learn what\'s powering them before we head in.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Powerful golems guard the Court of Zak\'rajan.', 'Malfunctioning Golem', '', '', 890, 878, 27843), -- -Unknown-
(49001, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48335, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Inconvenient Spirits', 'Kill $1oa Tortured Spirits.', 'The sethrak have oppressed vulpera like me for countless generations.\n\nYou can\'t fight \'em. Trust me, $pr. My caravan tried.\n\nI took that beating as a lesson, and then I found a new pack to run with.\n\nHere, we keep our distance from the sethrak and scavenge ruins like this one for anything valuable we can use or trade.\n\nYou want in? We could use a fourth. This one\'s protected by nasty spirits that keep harassing us.\n\nTake them out and you\'re in.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48840, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 49001, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 0, 0, 0, 159676, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159676, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Ruins-Level Marketing', 'Deliver the Goldtusk Inn coupon to Kenzou.', 'Now dat de Goldtusk Inn be open for business, we gotta make sure everyone in Vol\'dun knows about it!\n\nI think we should focus on those wagon-riding vulpera first. Dey don\'t even have real homes!\n\nIn fact, I saw a pack of vulpera up at de ruins to de north de other day, and dey barely had anything.\n\nTake dem dis coupon and tell dem to stop by for a free first stay.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48322, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48840, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Goldtusk Greeting', 'Greet the approaching guest and show them around the Goldtusk Inn.', 'Thanks to you, de Goldtusk Inn has never looked better!\n\nWe got food, we got beds, we got piles of dead Sandfury nearby. Dis is everything I ever dreamed it be!\n\n<Rhan\'ka looks out into the oasis.>\n\nYou hear dat? Sound like we got our first guest of de day!\n\nWhy don\'t you greet dis one? Show \'em all de great amenities ya built here!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48320, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Best Kill is Overkill', 'Kill $1oa predators in the Whistlebloom Oasis.', 'I watched you kill those Sandfury earlier, $p. You have blood instinct. I like dat.\n\nI bet de others have you hunting frivolous luxuries for de inn. I\'ll give you an assignment worth your talents.\n\nDis oasis is full of dangerous beasts dat\'ll scare away guests and harrass my pterrordaxes flying in and out.\n\nKill dem.\n\nOnce de skies are clear, my pterrordaxes can fly you wherever you want.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48321, 2, -1, 5, 120, 18780, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 167772168, 0, 0, 0, 0, 83197, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Creative Marketing', 'Collect Bloodcrest\'s Giant Rib in the Whistlebloom Oasis.', 'De Goldtusk Gang is de best gang in all of Zandalar.\n\nI know dat. You know dat. Everyone in de gang knows dat.\n\nBut we need to make sure dat everyone who sees our inn knows dat too.\n\nWe need something big... Something like a massive gold tusk!\n\nI don\'t know where we\'d find one of those, but I got a plan.\n\nDere\'s a huge saurolisk in de oasis. Bring me one of its giant bones and I\'ll take care of de rest.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Large saurolisk who pounces on his prey from above.', 'Bloodcrest', '', '', 890, 878, 27843), -- -Unknown-
(47564, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Restocking the Buffet', 'Collect $1oa Whistlebloom Juicy Fruit.', 'Imagine for a moment, $p. You wake up in de Goldtusk Inn after a long day of drinking scorpid blood, slaughtering Sandfury, and sharing jokes with your best friend Zulsan.\n\nYa not fully awake yet, and not feeling ya best. What do you need most at dat exact moment?\n\nAn all-you-can-eat breakfast buffet, of course!\n\nI\'m working on it, but I need some fruit to balance out my menu. Luckily, I\'ve seen some in de oasis outside.\n\nBring me some, and I\'ll give you lifetime access to de buffet.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47638, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Powerful Spirits', 'Participate in the Goldtusk Gang initiation ritual.', 'You prove your worth, $p. We be willin\' to initiate you into de ranks of de Goldtusk Gang, if you wanna join.\n\nDe ritual drink is ready. Boiled scorpid blood spiked with bilewing honey!\n\nDon\'t mind de smell, it\'s mostly delicious. It\'s not terrible. It won\'t kill you. Usually.\n\nWhen you are ready to join de Goldtusk Gang, let me know. I\'ll unite you with de whole gang. It\'s time you see what we see.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50328, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 263311, 0, 0, 160665, 0, 1, 0, 39845896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160665, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Unconventional Aromatics', 'Deliver the Batch of Bilewing \"Honey\" to Rhan\'ka at the Goldtusk Inn.', 'A deal\'s a deal. You got the stingers for me, so here\'s that big batch of honey I promised.\n\nI hope you and Rhan\'ka enjoy it... slowly. Seriously, do not eat this all at once.\n\nOh, and I\'m always looking to trade. Swing by anytime you got something to sell or want to pick up some more honey!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51718, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Harvesting \"Honey\"', 'Collect $1oa Bilewing Stingers.', 'I don\'t know what Rhan\'ka\'s doing down in that oasis with all of the honey he\'s bought from me. Frankly, I suspect I don\'t even want to know.\n\nBut whatever his reasons, Rhan\'ka is my best customer.\n\nSo even though my supply\'s getting low, because Rhan\'ka sent you, I\'ll give you a special deal.\n\nThe wasps here keep all their honey stored in their stingers. Bring some to me, so I can drain them for honey and I\'ll give you a big batch of the sticky stuff to take back to Rhan\'ka.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51717, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 20200, 1, 1, 8200, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Best Honey In Vol\'dun', 'Meet Rikati at The Four Stingers.', 'If you can handle rescuin\' de others by yourself, Zulsan and I will head back to de inn and start cleanin\' up de place.\n\nDon\'t worry, I still be cookin\' up a special batch of my famous scorpid blood drinks for you.\n\nIn fact, you gonna be runnin\' right past my friend Rikati. He sells de best honey in all of Vol\'dun!\n\nBring back a few bottles of it for me and let\'s add some sweetness to de drinks!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47503, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 404000, 6, 1, 102800, 0, 0, 0, 263311, 0, 0, 0, 0, 1, 0, 175112200, 0, 0, 0, 0, 83237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Gozda\'kun the Slaver', 'Kill Gozda\'kun the Slaver in the Sandfury Hideout.', 'Dat\'s it. De Sandfury are officially banned from de Goldtusk Inn!\n\nYou can\'t just ransack a place, kidnap its staff, and mock its owner with an assortment of fruits and vegetables and expect to get away with it!\n\nWe gotta teach those thugs what happens when you mess with de Goldtusk Gang!\n\nGozda\'kun de Slaver was bossing around de rest of de Sandfury during de attack.\n\nTake him out, and leave some Sandfury behind to spread de word.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Sadistic slaver who leads the local Sandfury bandits.', 'Gozda\'kun the Slaver', '', '', 890, 878, 27843), -- -Unknown-
(47502, 2, -1, 5, 120, 18858, 110, 8501, 0, 0, 47638, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 263311, 0, 0, 0, 0, 1, 0, 40894472, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Great Cranium Caper', 'Rescue the kidnapped members of the Goldtusk Gang in the Sandfury Hideout.', 'Sandfury thugs attacked de inn after you left and kidnapped de whole Goldtusk Gang!\n\nWe gotta get dem back.\n\nMan\'zul was usually de brains behind our thefts back in Zuldazar, but I\'ll try to come up with a plan to get dem outta dis mess.\n\n<Rhan\'ka thinks for awhile.>\n\nI got it! You rescue \'em all!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47498, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Rhan\'ka\'s Lost Friend', 'Find Zulsan in Dead Man\'s Pass.', 'When you head up to Dead Man\'s Pass, be sure to say hello to Zulsan.\n\nHe\'s my best friend, even if he doesn\'t want to be near me most of de time. Ha!\n\nSeriously, though, he\'s been up on de cliffs for days. If you find him, convince him to come back down to de inn. We need him to restock our breakfast buffet.\n\nOh, and a completely unrelated question dat has nothing to do with you not being able to find Zulsan and my needing to replace him: How wide is ya head?', '', '', 1553, 0, 0, 0, 100, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47501, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 202000, 5, 1, 82250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Dirty Work for Dirty Drinks', 'Collect $1oa Caustic Scorpid Blood from deathsnap scorpids in Dead Man\'s Pass.', 'Guests gotta earn their keep at de Goldtusk Inn. What say you help me clear out some scorpids at one of our off-site excursion locations? De delightful Dead Man\'s Pass!\n\nNormally, you\'d need to purchase our Warlord Package to be allowed access, but I\'ll make an exception dis time.\n\nI\'ll even throw in our Scorpid King Package. Unlimited scorpid blood drinks all day, every day!\n\nDere\'s one catch: we\'re out of scorpid blood. Bring some back and I\'ll whip up a batch of drinks for us.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51164, 2, -1, 5, 120, 0, 110, 8501, 1, 3, 0, 7, 1, 606000, 7, 1, 123400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 167772168, 0, 0, 0, 0, 78251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'WANTED: Cobra Excursion Participants', 'Kill Sevriss.', 'Attention guests of the Goldtusk Inn:\n\nWe\'re proud to announce a surprise new addition to our lineup of excursion activities!\n\nThe new Giant Deadly Unstoppable Killer Cobra Experience is now available!\n\nThere\'s no need to sign up, you\'ve all been automatically volunteered for this activity.\n\nTo participate, simply travel into the dunes north of the inn and try not to be killed by the massive cobra now patrolling the area.\n\nWe are not currently offering guided tours for this activity. Have fun!', '', '', 1553, 0, 0, 0, 115, 0, 0, 0, 'Deadly cobra or fun vacationing activity?', 'Sevriss', '', '', 890, 878, 27843), -- -Unknown-
(47497, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 101000, 3, 1, 41150, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Meet the Goldtusk Gang', 'Meet the staff of the Goldtusk Inn.', 'Greetings, traveler, and welcome to de Goldtusk Inn!\n\nUnless you\'re here to kill us... In which case, get out.\n\nOtherwise, sit down and enjoy de mess!\n\nI mean, don\'t mind de mess. EAT DE MESS! No, don\'t eat de mess. Ignore it!\n\n<Rhan\'ka turns to the skull with the eyepatch and shouts furiously in Zandalari.>\n\nHa, don\'t mind him. All exiles are welcome to rest at de Goldtusk Inn, de only luxury lodge in dese harsh dunes.\n\nCome, let me introduce you to de staff.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843); -- -Unknown-


DELETE FROM `quest_objectives` WHERE `ID` IN (333484 /*333484*/, 333569 /*333569*/, 334274 /*334274*/, 334273 /*334273*/, 334236 /*334236*/, 294662 /*294662*/, 333744 /*333744*/, 295058 /*295058*/, 338061 /*338061*/, 334040 /*334040*/, 333852 /*333852*/, 333851 /*333851*/, 333850 /*333850*/, 333888 /*333888*/, 333068 /*333068*/, 336681 /*336681*/, 336680 /*336680*/, 336679 /*336679*/, 333710 /*333710*/, 333698 /*333698*/, 336670 /*336670*/, 294758 /*294758*/, 294754 /*294754*/, 294750 /*294750*/, 294703 /*294703*/, 336618 /*336618*/, 336617 /*336617*/, 333691 /*333691*/, 294697 /*294697*/, 334060 /*334060*/, 334059 /*334059*/, 295035 /*295035*/, 295008 /*295008*/, 334452 /*334452*/, 295001 /*295001*/, 295031 /*295031*/, 294552 /*294552*/, 294550 /*294550*/, 294549 /*294549*/, 294546 /*294546*/, 294544 /*294544*/, 294538 /*294538*/, 294540 /*294540*/, 294616 /*294616*/, 294471 /*294471*/, 294470 /*294470*/, 294469 /*294469*/, 294468 /*294468*/, 294467 /*294467*/, 294445 /*294445*/, 294447 /*294447*/, 290578 /*290578*/, 332925 /*332925*/, 290855 /*290855*/, 336924 /*336924*/, 290514 /*290514*/, 290834 /*290834*/, 290833 /*290833*/, 290517 /*290517*/, 336930 /*336930*/, 290510 /*290510*/, 336928 /*336928*/, 290511 /*290511*/, 334933 /*334933*/, 290509 /*290509*/, 290508 /*290508*/, 290507 /*290507*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(333484, 50551, 14, 0, 0, 67127, 1, 1, 0, 0, 'Avatar of Sethraliss healed', 27843), -- 333484
(333569, 50702, 0, 0, 2, 134781, 1, 0, 0, 0, 'Jakra\'zet slain', 27843), -- 333569
(334274, 50904, 0, 2, 2, 135737, 1, 0, 0, 0, 'Rakera found', 27843), -- 334274
(334273, 50904, 0, 1, 1, 135694, 1, 2, 0, 0, 'Kaja found', 27843), -- 334273
(334236, 50904, 0, 0, 0, 135664, 1, 0, 0, 0, 'Speak with Vorrik', 27843), -- 334236
(294662, 49437, 0, 0, 0, 129754, 1, 1, 0, 0, '', 27843), -- 294662
(333744, 50757, 0, 0, 0, 129772, 8, 0, 0, 0, 'Faithless slain', 27843), -- 333744
(295058, 49669, 0, 0, 3, 135042, 1, 1, 0, 0, '', 27843), -- 295058
(338061, 50805, 0, 4, 3, 135748, 7, 92, 0, 15, '', 27843), -- 338061
(334040, 50805, 0, 3, 6, 140031, 13, 92, 0, 8, '', 27843), -- 334040
(333852, 50805, 0, 2, 0, 140032, 20, 92, 0, 5, 'Pick Up Staff', 27843), -- 333852
(333851, 50805, 2, 1, 2, 282461, 20, 92, 0, 5, 'Destroy Crystal', 27843), -- 333851
(333850, 50805, 15, 0, -1, 0, 1, 0, 0, 0, 'Disrupt the Skycallers\' Spire', 27843), -- 333850
(333888, 50550, 0, 1, 0, 134601, 1, 3, 0, 0, '', 27843), -- 333888
(333068, 50550, 0, 0, 1, 135111, 1, 0, 0, 0, 'Speak with Vorrik', 27843), -- 333068
(336681, 50752, 1, 3, 3, 160528, 1, 0, 1, 0, '', 27843), -- 336681
(336680, 50752, 1, 2, 2, 160527, 1, 0, 1, 0, '', 27843), -- 336680
(336679, 50752, 1, 1, 1, 160526, 1, 0, 1, 0, '', 27843), -- 336679
(333710, 50752, 1, 0, 0, 158722, 1, 0, 1, 0, '', 27843), -- 333710
(333698, 50750, 0, 0, 0, 135969, 75, 0, 0, 0, 'Faithless purged', 27843), -- 333698
(336670, 49003, 0, 3, 5, 138406, 1, 0, 0, 0, 'Spire barrier destroyed', 27843), -- 336670
(294758, 49003, 0, 2, 2, 135214, 1, 24, 0, 0, '', 27843), -- 294758
(294754, 49003, 0, 1, 0, 135186, 60, 2, 0, 0, 'Faithless slain', 27843), -- 294754
(294750, 49003, 0, 0, 1, 129763, 1, 0, 0, 0, 'Rakjan the Unbroken mounted', 27843), -- 294750
(294703, 49002, 0, 0, 0, 129848, 1, 1, 0, 0, '', 27843), -- 294703
(336618, 48329, 0, 1, 1, 129881, 1, 2, 0, 0, 'Scion of Rakjan escorted', 27843), -- 336618
(336617, 48329, 0, 0, 0, 138362, 1, 0, 0, 0, 'Scion of Rakjan freed', 27843), -- 336617
(333691, 50748, 1, 0, 1, 154896, 6, 0, 1, 0, '', 27843), -- 333691
(294697, 49141, 0, 0, 0, 138337, 6, 0, 0, 0, 'Suppression Spire drained', 27843), -- 294697
(334060, 49668, 0, 2, 2, 135454, 1, 0, 0, 0, 'East slave market burned', 27843), -- 334060
(334059, 49668, 0, 1, 1, 135453, 1, 0, 0, 0, 'Central slave market burned', 27843), -- 334059
(295035, 49668, 0, 0, 0, 134564, 1, 0, 0, 0, 'West slave market burned', 27843), -- 295035
(295008, 49666, 0, 0, 0, 135348, 12, 0, 0, 0, 'Vulpera Banners planted', 27843), -- 295008
(334452, 49665, 1, 1, 1, 159470, 99, 28, 1, 0, '', 27843), -- 334452
(295001, 49665, 0, 0, 0, 130354, 8, 0, 0, 0, 'Slaves Armed', 27843), -- 295001
(295031, 49667, 0, 0, 1, 130396, 1, 1, 0, 0, '', 27843), -- 295031
(294552, 48330, 0, 0, 0, 129434, 1, 1, 0, 0, '', 27843), -- 294552
(294550, 49139, 0, 1, 1, 129506, 1, 1, 0, 0, '', 27843), -- 294550
(294549, 49139, 0, 0, 0, 129507, 1, 1, 0, 0, '', 27843), -- 294549
(294546, 48331, 0, 0, 0, 129530, 5, 0, 0, 0, 'Golem souls siphoned', 27843), -- 294546
(294544, 48335, 1, 0, 0, 153699, 6, 0, 1, 0, '', 27843), -- 294544
(294538, 48332, 1, 0, 0, 154713, 25, 0, 1, 0, '', 27843), -- 294538
(294540, 48334, 0, 0, 0, 138923, 1, 1, 0, 0, 'Golem power source revealed', 27843), -- 294540
(294616, 49001, 0, 0, 0, 129672, 8, 0, 0, 0, '', 27843), -- 294616
(294471, 48322, 0, 4, 4, 129328, 1, 2, 0, 0, 'Show Bladeguard Tarkaj his bed', 27843), -- 294471
(294470, 48322, 0, 3, 2, 129326, 1, 0, 0, 0, 'Bladeguard Tarkaj fed', 27843), -- 294470
(294469, 48322, 0, 2, 3, 129327, 1, 0, 0, 0, 'Bladeguard Tarkaj bandaged', 27843), -- 294469
(294468, 48322, 0, 1, 1, 129325, 1, 2, 0, 0, 'Bladeguard Tarkaj hydrated', 27843), -- 294468
(294467, 48322, 0, 0, 0, 129324, 1, 0, 0, 0, 'Bladeguard Tarkaj resuscitated', 27843), -- 294467
(294445, 48320, 0, 0, 0, 133888, 15, 0, 0, 0, 'Whistlebloom predators slain', 27843), -- 294445
(294447, 48321, 1, 0, 0, 153593, 1, 1, 1, 0, '', 27843), -- 294447
(290578, 47564, 1, 0, 1, 151022, 10, 0, 1, 0, '', 27843), -- 290578
(332925, 47638, 0, 1, 0, 134054, 1, 28, 0, 0, '', 27843), -- 332925
(290855, 47638, 0, 0, 1, 129282, 1, 0, 0, 0, 'Boiled Scorpid Blood drank', 27843), -- 290855
(336924, 51718, 1, 0, 0, 157541, 12, 0, 1, 0, '', 27843), -- 336924
(290514, 47503, 0, 0, 0, 133924, 1, 1, 0, 0, '', 27843), -- 290514
(290834, 47502, 1, 2, 3, 151220, 1, 0, 1, 0, '', 27843), -- 290834
(290833, 47502, 1, 1, 2, 151219, 1, 0, 1, 0, '', 27843), -- 290833
(290517, 47502, 1, 0, 1, 151218, 1, 0, 1, 0, '', 27843), -- 290517
(336930, 47498, 0, 1, 1, 138760, 1, 28, 0, 0, '', 27843), -- 336930
(290510, 47498, 1, 0, 0, 150916, 1, 0, 1, 0, '', 27843), -- 290510
(336928, 47501, 0, 1, 1, 138760, 1, 28, 0, 0, '', 27843), -- 336928
(290511, 47501, 1, 0, 0, 150923, 20, 0, 1, 0, '', 27843), -- 290511
(334933, 51164, 0, 0, 0, 136593, 1, 1, 0, 0, '', 27843), -- 334933
(290509, 47497, 0, 2, 2, 123645, 1, 0, 0, 0, 'Meet Man\'zul', 27843), -- 290509
(290508, 47497, 0, 1, 1, 123643, 1, 0, 0, 0, 'Meet Volni', 27843), -- 290508
(290507, 47497, 0, 0, 0, 123644, 1, 0, 0, 0, 'Meet Grenja', 27843); -- 290507


DELETE FROM `quest_visual_effect` WHERE (`ID`=334274 AND `Index`=0) OR (`ID`=334273 AND `Index`=0) OR (`ID`=334236 AND `Index`=0) OR (`ID`=294662 AND `Index`=0) OR (`ID`=295058 AND `Index`=0) OR (`ID`=333852 AND `Index`=0) OR (`ID`=333851 AND `Index`=0) OR (`ID`=333888 AND `Index`=0) OR (`ID`=333068 AND `Index`=0) OR (`ID`=336681 AND `Index`=0) OR (`ID`=336680 AND `Index`=0) OR (`ID`=336679 AND `Index`=0) OR (`ID`=333710 AND `Index`=0) OR (`ID`=294750 AND `Index`=0) OR (`ID`=294703 AND `Index`=0) OR (`ID`=336618 AND `Index`=1) OR (`ID`=336618 AND `Index`=0) OR (`ID`=336617 AND `Index`=0) OR (`ID`=294697 AND `Index`=0) OR (`ID`=334060 AND `Index`=0) OR (`ID`=334059 AND `Index`=0) OR (`ID`=295035 AND `Index`=0) OR (`ID`=295008 AND `Index`=6) OR (`ID`=295008 AND `Index`=5) OR (`ID`=295008 AND `Index`=4) OR (`ID`=295008 AND `Index`=3) OR (`ID`=295008 AND `Index`=2) OR (`ID`=295008 AND `Index`=1) OR (`ID`=295008 AND `Index`=0) OR (`ID`=334452 AND `Index`=0) OR (`ID`=295001 AND `Index`=0) OR (`ID`=295031 AND `Index`=0) OR (`ID`=294552 AND `Index`=0) OR (`ID`=294550 AND `Index`=0) OR (`ID`=294549 AND `Index`=0) OR (`ID`=294546 AND `Index`=0) OR (`ID`=294540 AND `Index`=0) OR (`ID`=294471 AND `Index`=0) OR (`ID`=294470 AND `Index`=0) OR (`ID`=294469 AND `Index`=0) OR (`ID`=294468 AND `Index`=0) OR (`ID`=294467 AND `Index`=1) OR (`ID`=294467 AND `Index`=0) OR (`ID`=294447 AND `Index`=0) OR (`ID`=290578 AND `Index`=0) OR (`ID`=290855 AND `Index`=0) OR (`ID`=290514 AND `Index`=0) OR (`ID`=290834 AND `Index`=0) OR (`ID`=290833 AND `Index`=0) OR (`ID`=290517 AND `Index`=0) OR (`ID`=290510 AND `Index`=0) OR (`ID`=334933 AND `Index`=0) OR (`ID`=290509 AND `Index`=0) OR (`ID`=290508 AND `Index`=0) OR (`ID`=290507 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(334274, 0, 9149, 27843),
(334273, 0, 9148, 27843),
(334236, 0, 9140, 27843),
(294662, 0, 2101, 27843),
(295058, 0, 9523, 27843),
(333852, 0, 9734, 27843),
(333851, 0, 9733, 27843),
(333888, 0, 2101, 27843),
(333068, 0, 10348, 27843),
(336681, 0, 9493, 27843),
(336680, 0, 9492, 27843),
(336679, 0, 9491, 27843),
(333710, 0, 9086, 27843),
(294750, 0, 8320, 27843),
(294703, 0, 8306, 27843),
(336618, 1, 9511, 27843),
(336618, 0, 8317, 27843),
(336617, 0, 9484, 27843),
(294697, 0, 9477, 27843),
(334060, 0, 9115, 27843),
(334059, 0, 9114, 27843),
(295035, 0, 9113, 27843),
(295008, 6, 10335, 27843),
(295008, 5, 10334, 27843),
(295008, 4, 10333, 27843),
(295008, 3, 10332, 27843),
(295008, 2, 10331, 27843),
(295008, 1, 10330, 27843),
(295008, 0, 10329, 27843),
(334452, 0, 9458, 27843),
(295001, 0, 9190, 27843),
(295031, 0, 2101, 27843),
(294552, 0, 8284, 27843),
(294550, 0, 8282, 27843),
(294549, 0, 8281, 27843),
(294546, 0, 8280, 27843),
(294540, 0, 2101, 27843),
(294471, 0, 8240, 27843),
(294470, 0, 8238, 27843),
(294469, 0, 8239, 27843),
(294468, 0, 8237, 27843),
(294467, 1, 9391, 27843),
(294467, 0, 8236, 27843),
(294447, 0, 8235, 27843),
(290578, 0, 2100, 27843),
(290855, 0, 8894, 27843),
(290514, 0, 2101, 27843),
(290834, 0, 8234, 27843),
(290833, 0, 8233, 27843),
(290517, 0, 8232, 27843),
(290510, 0, 8231, 27843),
(334933, 0, 2101, 27843),
(290509, 0, 8230, 27843),
(290508, 0, 8229, 27843),
(290507, 0, 8228, 27843);


DELETE FROM `creature_template_model` WHERE (`CreatureID`=61420 AND `CreatureDisplayID`=42365) OR (`CreatureID`=62034 AND `CreatureDisplayID`=32791);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(61420, 0, 42365, 1, 1, 27843), -- Ash Spiderling
(62034, 0, 32791, 1, 1, 27843); -- Spirit Crab

UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=67071 AND `CreatureDisplayID`=40358); -- Wary Forest Prowler
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=38453 AND `CreatureDisplayID`=31094); -- Arcturis
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=17286 AND `CreatureDisplayID`=15435); -- Invisible Man
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=50138 AND `CreatureDisplayID`=36726); -- Karoma
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=82521 AND `CreatureDisplayID`=57047); -- Defile

DELETE FROM `gameobject_template` WHERE `entry` IN (282387 /*Cave Rock*/, 294322 /*Fire Pit*/, 294321 /*Anvil*/, 278193 /*Sethrak Weapon*/, 278191 /*Sethrak Weapon*/, 278192 /*Sethrak Weapon*/, 278190 /*Sethrak Weapon*/, 277910 /*Sethrak Cage*/, 284411 /*Treasure Chest*/, 294135 /*Campfire*/, 282461 /*Lightning Focus*/, 290533 /*Meeting Stone*/, 290783 /*Faithless Barrier*/, 290784 /*Faithless Barrier*/, 290756 /*Sethraliss Sight Stone*/, 282451 /*Rebirth Creed*/, 290757 /*Blood of the Fallen Loa*/, 290755 /*Skull of the First Skycaller*/, 282430 /*Fire*/, 278447 /*Faithless Trapper's Spear*/, 290726 /*Faithless Cage (Scale 1.7)*/, 278368 /*Tattered Note*/, 294327 /*Forge*/, 281664 /*Faithless Supplies*/, 294326 /*Forge*/, 281667 /*Faithless Supplies*/, 294141 /*Fire Pit*/, 282623 /*Jar of Oil*/, 278370 /*Skeleton*/, 282622 /*Jar of Oil*/, 282621 /*Jar of Oil*/, 294139 /*Fire Pit*/, 290707 /*Suppression Spire*/, 290549 /*Faithless Weapon Rack (Empty)*/, 287006 /*Faithless Weapon Rack*/, 294137 /*Fire Pit*/, 298856 /*Sethrak Scroll Stack*/, 298855 /*Sethrak Rug*/, 298854 /*Sethrak Snake Brazier*/, 298852 /*Sethrak Hatchery (Scale 0.35)*/, 298850 /*Sethrak Brazier (Scale 0.5)*/, 277856 /*Table*/, 298851 /*Sethrak Hanging Crystal*/, 298857 /*Sethrak Hookah*/, 298853 /*Sethrak Hanging Lamp*/, 287527 /*Pillow*/, 292745 /*Anvil*/, 292744 /*Forge*/, 292743 /*Chair*/, 292742 /*Chair*/, 292741 /*Fire Pit*/, 292746 /*Mailbox*/, 277307 /*Skeleton 01*/, 296579 /*Brian's Broken Compass*/, 296585 /*Damarcus' Backpack*/, 282645 /*Beastbreaker Cage*/, 276623 /*Rich Platinum Deposit*/, 281286 /*[DNT] Altar*/, 292645 /*Zandalari Jug*/, 292644 /*Zandalari Mask (Scale 2)*/, 292643 /*Water Trench*/, 292642 /*Mounted Zandalari Sword (Scale 3)*/, 292638 /*Urns*/, 292635 /*Zandalari Altar Offering*/, 292633 /*Zandalari Altar*/, 292640 /*Zandalari Skull Pile*/, 292639 /*Shrine*/, 292637 /*Zandalari Crate (Scrolls)*/, 292636 /*Zandalari Crate (Books)*/, 284447 /*Zandalari Idol*/, 278397 /*Zandalari Weapon Rack*/, 284415 /*Treasure Chest*/, 282646 /*Mysterious Trashpile*/, 278553 /*Buried Artifact*/, 278292 /*Goldtusk Inn Mailbox*/, 271869 /*Boiled Scorpid Blood*/, 278271 /*The Goldtusk*/, 278277 /*Sandy Tortillas*/, 278269 /*All-You-Can-Eat Breakfast Buffet*/, 278267 /*All-You-Can-Eat Breakfast Buffet*/, 278268 /*All-You-Can-Eat Breakfast Buffet*/, 278278 /*Box of Slightly Used Bandages*/, 278280 /*Pillow*/, 278279 /*Very Uncomfortable Bed*/, 278276 /*Oasis Water*/, 278242 /*Whistlebloom Juicy Fruit*/, 281559 /*Pterrordax Perch*/, 292594 /*Anvil*/, 292593 /*Forge*/, 271810 /*Boiled Scorpid Blood*/, 291062 /*Campfire*/, 280525 /*Zandalari Drum*/, 271793 /*Grenja*/, 287318 /*Sandfury Reserve*/, 279362 /*[DNT] Bottle*/, 272399 /*Zandalari Spear*/, 271795 /*Volni*/, 271792 /*Man'zul*/, 281443 /*Stone Spear*/, 271742 /*Zulsan*/, 271847 /*Cheese 6HU_INN_CHEESE01.m2*/, 281460 /*Zandalari Urn (Blue, Broken)*/, 281462 /*Zandalari Urn (Green, Broken)*/, 281454 /*Zandalari Basket (Destroyed)*/, 281456 /*Zandalari Crate (Destroyed)*/, 281458 /*Zandalari Crate (Open)*/, 272686 /*Empty Cauldron (Scale 1.3)*/, 289669 /*Drum*/, 271794 /*Zulsan*/, 284413 /*Treasure Chest*/, 271745 /*Banana*/, 271134 /*Man'zul*/, 287442 /*Wanted: Cobra Excursion Participants*/, 281863 /*Magic Barrier*/, 292597 /*Cooking Cauldron*/, 281463 /*Zandalari Crate Stack (Tall)*/, 271615 /*Plank 7SG_SEAGIANT_DEBRIS_PLANK01.M2 (Scale 0.5)*/, 271741 /*Grenja*/, 271620 /*Bucket 6HU_PETSTABLE_EMPTYBUCKET03.M2  (Scale 1.5)*/, 271111 /*Drum*/, 271846 /*7XP_FishSkeleton_Huge_Red01.m2*/, 271617 /*Plank 6HU_LUMBERMILL_WOODENPLANK02.M2*/, 271848 /*Dynamite Bundle*/, 271744 /*Volni*/, 281461 /*Zandalari Urn (Green)*/, 271136 /*Mask*/, 281465 /*Zandalari Urn (Bottle) - Scale 0.5*/, 271568 /*Skull Candle*/, 271135 /*Pile of Skulls*/, 292596 /*Rubble (Zandalari, Desert, Large)*/, 281459 /*Zandalari Urn (Blue)*/, 281457 /*Zandalari Crate*/, 281455 /*Zandalari Basket*/, 271112 /*Incense*/, 297495 /*Tales of de Loa: Akunda*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(282387, 5, 29478, 'Cave Rock', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cave Rock
(294322, 8, 48976, 'Fire Pit', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(294321, 8, 23400, 'Anvil', '', '', '', 0.99, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(278193, 3, 45612, 'Sethrak Weapon', 'questinteract', 'Collecting', '', 1.25, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77318, 0, 0, 0, 0, 27843), -- Sethrak Weapon
(278191, 3, 45610, 'Sethrak Weapon', 'questinteract', 'Collecting', '', 1.1, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77318, 0, 0, 0, 0, 27843), -- Sethrak Weapon
(278192, 3, 45611, 'Sethrak Weapon', 'questinteract', 'Collecting', '', 1.25, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77318, 0, 0, 0, 0, 27843), -- Sethrak Weapon
(278190, 3, 45609, 'Sethrak Weapon', 'questinteract', 'Collecting', '', 1.25, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77318, 0, 0, 0, 0, 27843), -- Sethrak Weapon
(277910, 10, 49138, 'Sethrak Cage', 'questinteract', 'Unlocking', '', 1.5, 1690, 0, 0, 1, 0, 0, 0, 0, 0, 0, 255799, 0, 0, 0, 24815, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Cage
(284411, 50, 48632, 'Treasure Chest', '', '', '', 0.5, 1690, 87477, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2815, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(294135, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(282461, 10, 48453, 'Lightning Focus', 'questinteract', 'Destroying', '', 0.5, 2741, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 264391, 0, 0, 0, 24585, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Lightning Focus
(290533, 23, 46089, 'Meeting Stone', '', '', '', 1, 110, 120, 9527, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Meeting Stone
(290783, 5, 48813, 'Faithless Barrier', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Barrier
(290784, 5, 48813, 'Faithless Barrier', '', '', '', 0.7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Barrier
(290756, 3, 45539, 'Sethraliss Sight Stone', 'questinteract', 'Collecting', '', 1.5, 1691, 0, 1, 0, 0, 0, 0, 0, 50752, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88167, 1, 0, 0, 0, 27843), -- Sethraliss Sight Stone
(282451, 3, 48716, 'Rebirth Creed', 'questinteract', 'Collecting', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 50752, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87261, 1, 0, 0, 0, 27843), -- Rebirth Creed
(290757, 3, 49801, 'Blood of the Fallen Loa', 'questinteract', 'Collecting', '', 3, 1691, 0, 1, 0, 0, 0, 0, 0, 50752, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88168, 1, 0, 0, 0, 27843), -- Blood of the Fallen Loa
(290755, 3, 46361, 'Skull of the First Skycaller', 'questinteract', 'Collecting', '', 2, 1691, 0, 1, 0, 0, 0, 0, 0, 50752, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88166, 1, 0, 0, 0, 27843), -- Skull of the First Skycaller
(282430, 5, 24564, 'Fire', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire
(278447, 2, 45610, 'Faithless Trapper\'s Spear', 'quest', '', '', 1, 0, 21604, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Trapper's Spear
(290726, 5, 43228, 'Faithless Cage (Scale 1.7)', '', '', '', 1.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Cage (Scale 1.7)
(278368, 2, 19417, 'Tattered Note', 'quest', '', '', 1, 0, 21597, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Tattered Note
(294327, 8, 51336, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(281664, 10, 44628, 'Faithless Supplies', 'questinteract', 'Burning', '', 2, 2742, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 155781, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Supplies
(294326, 8, 51336, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(281667, 10, 47742, 'Faithless Supplies', 'questinteract', 'Burning', '', 2, 2742, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30602, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Supplies
(294141, 8, 48976, 'Fire Pit', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(282623, 5, 43082, 'Jar of Oil', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Jar of Oil
(278370, 5, 43302, 'Skeleton', '', '', '', 0.8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skeleton
(282622, 5, 43082, 'Jar of Oil', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Jar of Oil
(282621, 5, 43082, 'Jar of Oil', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Jar of Oil
(294139, 8, 48976, 'Fire Pit', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(290707, 10, 45524, 'Suppression Spire', 'questinteract', '', '', 0.8, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 272153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 56965, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Suppression Spire
(290549, 5, 43314, 'Faithless Weapon Rack (Empty)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Weapon Rack (Empty)
(287006, 3, 45608, 'Faithless Weapon Rack', 'questinteract', 'Taking', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112825, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87515, 1, 0, 0, 0, 27843), -- Faithless Weapon Rack
(294137, 8, 48976, 'Fire Pit', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(298856, 5, 48716, 'Sethrak Scroll Stack', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Scroll Stack
(298855, 5, 51980, 'Sethrak Rug', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Rug
(298854, 5, 45544, 'Sethrak Snake Brazier', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Snake Brazier
(298852, 5, 51975, 'Sethrak Hatchery (Scale 0.35)', '', '', '', 0.35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Hatchery (Scale 0.35)
(298850, 5, 45228, 'Sethrak Brazier (Scale 0.5)', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Brazier (Scale 0.5)
(277856, 5, 45526, 'Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Table
(298851, 5, 48223, 'Sethrak Hanging Crystal', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Hanging Crystal
(298857, 5, 51981, 'Sethrak Hookah', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Hookah
(298853, 5, 51977, 'Sethrak Hanging Lamp', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Hanging Lamp
(287527, 5, 48977, 'Pillow', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pillow
(292745, 8, 23400, 'Anvil', '', '', '', 0.57, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(292744, 8, 50269, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(292743, 7, 44318, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(292742, 7, 44320, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(292741, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(292746, 19, 50268, 'Mailbox', '', '', '', 1, 923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mailbox
(277307, 5, 44344, 'Skeleton 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skeleton 01
(296579, 3, 48480, 'Brian\'s Broken Compass', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90585, 0, 0, 0, 0, 27843), -- Brian's Broken Compass
(296585, 3, 7144, 'Damarcus\' Backpack', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90591, 0, 0, 0, 0, 27843), -- Damarcus' Backpack
(282645, 10, 43249, 'Beastbreaker Cage', 'questinteract', '', '', 2, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 272224, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Beastbreaker Cage
(276623, 50, 50072, 'Rich Platinum Deposit', '', '', '', 1, 2870, 76263, 0, 0, 185, 200, 30, 0, 0, 0, 0, 0, 292, 1, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Rich Platinum Deposit
(281286, 5, 44416, '[DNT] Altar', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- [DNT] Altar
(292645, 5, 48803, 'Zandalari Jug', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Jug
(292644, 5, 50299, 'Zandalari Mask (Scale 2)', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Mask (Scale 2)
(292643, 5, 50298, 'Water Trench', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Water Trench
(292642, 5, 50297, 'Mounted Zandalari Sword (Scale 3)', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mounted Zandalari Sword (Scale 3)
(292638, 5, 45753, 'Urns', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Urns
(292635, 5, 49096, 'Zandalari Altar Offering', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Altar Offering
(292633, 5, 50294, 'Zandalari Altar', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Altar
(292640, 5, 47681, 'Zandalari Skull Pile', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Skull Pile
(292639, 5, 44416, 'Shrine', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Shrine
(292637, 5, 50296, 'Zandalari Crate (Scrolls)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate (Scrolls)
(292636, 5, 50295, 'Zandalari Crate (Books)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate (Books)
(284447, 5, 48671, 'Zandalari Idol', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Idol
(278397, 5, 45932, 'Zandalari Weapon Rack', 'questinteract', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Weapon Rack
(284415, 50, 46516, 'Treasure Chest', '', '', '', 0.5, 1690, 87481, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2819, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(282646, 10, 29547, 'Mysterious Trashpile', 'questinteract', 'Rummaging', '', 2, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 266123, 0, 0, 0, 103044, 0, 0, 0, 0, 0, 1, 0, 56322, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mysterious Trashpile
(278553, 3, 41626, 'Buried Artifact', 'interact', 'Collecting', '', 1, 1691, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254698, 0, 0, 0, 77862, 1, 0, 0, 0, 27843), -- Buried Artifact
(278292, 19, 45386, 'Goldtusk Inn Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Goldtusk Inn Mailbox
(271869, 10, 10296, 'Boiled Scorpid Blood', 'interact', '', '', 1, 0, 0, 62793, 10000, 0, 0, 0, 0, 0, 0, 256094, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 50414, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Boiled Scorpid Blood
(278271, 5, 17808, 'The Goldtusk', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- The Goldtusk
(278277, 10, 45691, 'Sandy Tortillas', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 256178, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 55683, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sandy Tortillas
(278269, 22, 16773, 'All-You-Can-Eat Breakfast Buffet', '', '', '', 0.7, 273057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- All-You-Can-Eat Breakfast Buffet
(278267, 22, 40717, 'All-You-Can-Eat Breakfast Buffet', '', '', '', 1, 273057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- All-You-Can-Eat Breakfast Buffet
(278268, 22, 45658, 'All-You-Can-Eat Breakfast Buffet', '', '', '', 1, 273057, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- All-You-Can-Eat Breakfast Buffet
(278278, 10, 41702, 'Box of Slightly Used Bandages', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 256176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 55682, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Box of Slightly Used Bandages
(278280, 5, 41700, 'Pillow', 'questinteract', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pillow
(278279, 10, 45693, 'Very Uncomfortable Bed', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 256180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 55680, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Very Uncomfortable Bed
(278276, 10, 45692, 'Oasis Water', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 256173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 55681, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Oasis Water
(278242, 3, 45649, 'Whistlebloom Juicy Fruit', 'questinteract', 'Collecting', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77389, 1, 0, 0, 0, 27843), -- Whistlebloom Juicy Fruit
(281559, 5, 47951, 'Pterrordax Perch', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pterrordax Perch
(292594, 8, 48031, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(292593, 8, 48585, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(271810, 10, 10296, 'Boiled Scorpid Blood', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 256093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 55652, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Boiled Scorpid Blood
(291062, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(280525, 10, 45286, 'Zandalari Drum', 'openhandglow', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 270134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Drum
(271793, 3, 43112, 'Grenja', 'questinteract', 'Rescuing', '', 0.7, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74293, 1, 0, 0, 0, 27843), -- Grenja
(287318, 3, 48259, 'Sandfury Reserve', '', 'Opening', '', 1, 57, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 705, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2902, 87631, 0, 0, 0, 108, 27843), -- Sandfury Reserve
(279362, 5, 46057, '[DNT] Bottle', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- [DNT] Bottle
(272399, 5, 41625, 'Zandalari Spear', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Spear
(271795, 3, 42701, 'Volni', 'questinteract', 'Rescuing', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74291, 1, 0, 0, 0, 27843), -- Volni
(271792, 3, 41685, 'Man\'zul', 'questinteract', 'Rescuing', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74290, 1, 0, 0, 0, 27843), -- Man'zul
(281443, 5, 47767, 'Stone Spear', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stone Spear
(271742, 5, 47953, 'Zulsan', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zulsan
(271847, 5, 43248, 'Cheese 6HU_INN_CHEESE01.m2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cheese 6HU_INN_CHEESE01.m2
(281460, 5, 47787, 'Zandalari Urn (Blue, Broken)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Urn (Blue, Broken)
(281462, 5, 47788, 'Zandalari Urn (Green, Broken)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Urn (Green, Broken)
(281454, 5, 47592, 'Zandalari Basket (Destroyed)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Basket (Destroyed)
(281456, 5, 47591, 'Zandalari Crate (Destroyed)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate (Destroyed)
(281458, 5, 45694, 'Zandalari Crate (Open)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate (Open)
(272686, 5, 7199, 'Empty Cauldron (Scale 1.3)', '', '', '', 1.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Empty Cauldron (Scale 1.3)
(289669, 5, 13561, 'Drum', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Drum
(271794, 3, 47953, 'Zulsan', 'questinteract', 'Rescuing', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74292, 1, 0, 0, 0, 27843), -- Zulsan
(284413, 50, 48632, 'Treasure Chest', '', '', '', 0.5, 1690, 87479, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2817, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(271745, 5, 22716, 'Banana', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Banana
(271134, 10, 41685, 'Man\'zul', 'speak', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21230, 1, 0, 61604, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Man'zul
(287442, 2, 45786, 'Wanted: Cobra Excursion Participants', '', '', '', 1, 0, 22055, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Wanted: Cobra Excursion Participants
(281863, 5, 48795, 'Magic Barrier', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Magic Barrier
(292597, 8, 7411, 'Cooking Cauldron', '', '', '', 3, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Cooking Cauldron
(281463, 5, 47789, 'Zandalari Crate Stack (Tall)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate Stack (Tall)
(271615, 5, 30435, 'Plank 7SG_SEAGIANT_DEBRIS_PLANK01.M2 (Scale 0.5)', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Plank 7SG_SEAGIANT_DEBRIS_PLANK01.M2 (Scale 0.5)
(271741, 10, 43112, 'Grenja', 'speak', '', '', 0.7, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21229, 1, 0, 61604, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Grenja
(271620, 5, 43013, 'Bucket 6HU_PETSTABLE_EMPTYBUCKET03.M2  (Scale 1.5)', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bucket 6HU_PETSTABLE_EMPTYBUCKET03.M2  (Scale 1.5)
(271111, 10, 13561, 'Drum', 'openhandglow', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 270077, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Drum
(271846, 5, 43247, '7XP_FishSkeleton_Huge_Red01.m2', '', '', '', 0.03, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- 7XP_FishSkeleton_Huge_Red01.m2
(271617, 5, 15799, 'Plank 6HU_LUMBERMILL_WOODENPLANK02.M2', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Plank 6HU_LUMBERMILL_WOODENPLANK02.M2
(271848, 5, 9539, 'Dynamite Bundle', '', '', '', 0.6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Dynamite Bundle
(271744, 10, 42701, 'Volni', 'speak', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21228, 1, 0, 61604, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Volni
(281461, 5, 45756, 'Zandalari Urn (Green)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Urn (Green)
(271136, 5, 9680, 'Mask', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mask
(281465, 5, 45755, 'Zandalari Urn (Bottle) - Scale 0.5', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Urn (Bottle) - Scale 0.5
(271568, 5, 6406, 'Skull Candle', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skull Candle
(271135, 5, 293, 'Pile of Skulls', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Pile of Skulls
(292596, 5, 50264, 'Rubble (Zandalari, Desert, Large)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Rubble (Zandalari, Desert, Large)
(281459, 5, 45754, 'Zandalari Urn (Blue)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Urn (Blue)
(281457, 5, 41702, 'Zandalari Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Crate
(281455, 5, 41770, 'Zandalari Basket', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Basket
(271112, 5, 7472, 'Incense', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Incense
(297495, 10, 47839, 'Tales of de Loa: Akunda', 'inspect', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 7839, 0, 5, 280875, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843); -- Tales of de Loa: Akunda

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=278193 AND `Idx`=0) OR (`GameObjectEntry`=278191 AND `Idx`=0) OR (`GameObjectEntry`=278192 AND `Idx`=0) OR (`GameObjectEntry`=278190 AND `Idx`=0) OR (`GameObjectEntry`=290756 AND `Idx`=0) OR (`GameObjectEntry`=282451 AND `Idx`=0) OR (`GameObjectEntry`=290757 AND `Idx`=0) OR (`GameObjectEntry`=290755 AND `Idx`=0) OR (`GameObjectEntry`=287006 AND `Idx`=0) OR (`GameObjectEntry`=278242 AND `Idx`=0) OR (`GameObjectEntry`=271793 AND `Idx`=0) OR (`GameObjectEntry`=271795 AND `Idx`=0) OR (`GameObjectEntry`=271792 AND `Idx`=0) OR (`GameObjectEntry`=271794 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(278193, 0, 153556, 27843), -- Sethrak Weapon
(278191, 0, 153556, 27843), -- Sethrak Weapon
(278192, 0, 153556, 27843), -- Sethrak Weapon
(278190, 0, 153556, 27843), -- Sethrak Weapon
(290756, 0, 160527, 27843), -- Sethraliss Sight Stone
(282451, 0, 158722, 27843), -- Rebirth Creed
(290757, 0, 160528, 27843), -- Blood of the Fallen Loa
(290755, 0, 160526, 27843), -- Skull of the First Skycaller
(287006, 0, 159470, 27843), -- Faithless Weapon Rack
(278242, 0, 151022, 27843), -- Whistlebloom Juicy Fruit
(271793, 0, 151220, 27843), -- Grenja
(271795, 0, 151219, 27843), -- Volni
(271792, 0, 151218, 27843), -- Man'zul
(271794, 0, 150916, 27843); -- Zulsan


DELETE FROM `npc_text` WHERE `ID` IN (34418 /*34418*/, 35048 /*35048*/, 35046 /*35046*/, 35013 /*35013*/, 35045 /*35045*/, 33360 /*33360*/, 34181 /*34181*/, 34509 /*34509*/, 35044 /*35044*/, 34320 /*34320*/, 34508 /*34508*/, 34368 /*34368*/, 34367 /*34367*/, 34366 /*34366*/, 34365 /*34365*/, 34364 /*34364*/, 33253 /*33253*/, 34126 /*34126*/, 33252 /*33252*/, 35083 /*35083*/, 33235 /*33235*/, 34113 /*34113*/, 32210 /*32210*/, 32209 /*32209*/, 32211 /*32211*/, 32046 /*32046*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(34418, 1, 0, 0, 0, 0, 0, 0, 0, 150471, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34418
(35048, 1, 0, 0, 0, 0, 0, 0, 0, 156350, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35048
(35046, 1, 0, 0, 0, 0, 0, 0, 0, 156347, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35046
(35013, 1, 0, 0, 0, 0, 0, 0, 0, 155790, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35013
(35045, 1, 0, 0, 0, 0, 0, 0, 0, 156338, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35045
(33360, 1, 0, 0, 0, 0, 0, 0, 0, 141136, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33360
(34181, 1, 0, 0, 0, 0, 0, 0, 0, 148318, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34181
(34509, 1, 0, 0, 0, 0, 0, 0, 0, 151291, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34509
(35044, 1, 0, 0, 0, 0, 0, 0, 0, 141619, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35044
(34320, 1, 0, 0, 0, 0, 0, 0, 0, 149450, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34320
(34508, 1, 1, 1, 1, 1, 1, 1, 1, 151266, 151267, 151268, 151269, 151270, 151271, 151273, 151275, 27843), -- 34508
(34368, 1, 0, 0, 0, 0, 0, 0, 0, 149765, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34368
(34367, 1, 0, 0, 0, 0, 0, 0, 0, 149764, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34367
(34366, 1, 0, 0, 0, 0, 0, 0, 0, 149763, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34366
(34365, 1, 0, 0, 0, 0, 0, 0, 0, 149762, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34365
(34364, 1, 0, 0, 0, 0, 0, 0, 0, 149756, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34364
(33253, 1, 0, 0, 0, 0, 0, 0, 0, 140313, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33253
(34126, 1, 0, 0, 0, 0, 0, 0, 0, 147947, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34126
(33252, 1, 0, 0, 0, 0, 0, 0, 0, 140312, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33252
(35083, 1, 0, 0, 0, 0, 0, 0, 0, 156476, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35083
(33235, 1, 0, 0, 0, 0, 0, 0, 0, 139987, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33235
(34113, 1, 0, 0, 0, 0, 0, 0, 0, 147826, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34113
(32210, 1, 0, 0, 0, 0, 0, 0, 0, 132674, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32210
(32209, 1, 0, 0, 0, 0, 0, 0, 0, 132667, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32209
(32211, 1, 0, 0, 0, 0, 0, 0, 0, 132678, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32211
(32046, 1, 0, 0, 0, 0, 0, 0, 0, 131674, 0, 0, 0, 0, 0, 0, 0, 27843); -- 32046


