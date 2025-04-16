DELETE FROM `quest_offer_reward` WHERE `ID` IN (14013 /* Charge */, 14008 /*Arcane Missiles*/, 14009 /*Flash Heal*/, 14010 /*Eviscerate*/, 14007 /*Steady Shot*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(14013, 33, 0, 0, 0, 0, 0, 0, 0, 'Warrior-Matic NX-01 is programmed to serve.$B$BReturn anytime you seek more training. This unit will teach you what it knows.', 59185), -- Charge
(14008, 4, 0, 0, 0, 0, 0, 0, 0, 'There you go, boss!$B$BCome back anytime you want more training. I\'ll teach you what I know.', 59185), -- Arcane Missiles
(14009, 4, 0, 0, 0, 0, 0, 0, 0, 'There you go, boss!$B$BCome back anytime you want more training. I\'ll teach you what I know.', 59185), -- Flash Heal
(14010, 4, 0, 0, 0, 0, 0, 0, 0, 'There you go, boss!$B$BCome back anytime you want more training. I\'ll teach you what I know.', 59185), -- Eviscerate
(14007, 4, 0, 0, 0, 0, 0, 0, 0, 'There you go, boss!$B$BCome back anytime you want more training. I\'ll teach you what I know.', 59185); -- Steady Shot

UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=14012; -- Immolate

UPDATE `quest_offer_reward` SET `VerifiedBuild`=59185 WHERE `ID` IN (14011, 24741, 24671, 27139, 14245, 14445, 14326, 14242, 14241, 14240, 14236, 14235, 14234, 14233, 14021, 14248, 14014, 14019, 14473, 14126, 14123, 14121, 14122, 14124, 14120, 14115, 14153, 14110, 14070, 24520, 26711, 24503, 24502, 24488, 24567, 14071, 28349, 25473, 14075, 14138, 25099, 25098, 25066, 25058, 25024, 24958, 24952, 24946, 24945, 24942, 24940, 24937, 24929, 24925, 24901, 24868, 24864, 24858, 24859, 24856, 24817, 24816, 24744, 26807, 26806, 26804, 26803, 25214, 25213, 25207, 25204, 25201, 25200, 25184, 25125, 25122, 25123, 25110, 25109);

UPDATE `quest_offer_reward` SET `RewardText`='$N, I sure am glad you survived the trip... not everyone did!', `VerifiedBuild`=59185 WHERE `ID`=14244; -- Up, Up & Away!
UPDATE `quest_offer_reward` SET `RewardText`='You have done what few others could have, $N. Our world owes you a debt larger than you can possibly understand.', `VerifiedBuild`=59185 WHERE `ID`=14243; -- Warchief's Revenge
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N, well done. We\'ll make an orc of you yet!$B$BTime to move on. We\'d better hurry.', `VerifiedBuild`=59185 WHERE `ID`=14238; -- Infrared = Infradead
UPDATE `quest_offer_reward` SET `RewardText`='Throm-Ka, $N. We have a problem.', `VerifiedBuild`=59185 WHERE `ID`=14237; -- Forward Movement
UPDATE `quest_offer_reward` SET `RewardText`='<Aggra gives you the eye as if she doesn\'t quite believe what you are telling her.>$B$BI am not easily impressed, but if what you are telling me is true, then I have never before heard of such a thing.$B$BYou have my thanks, $N.', `VerifiedBuild`=59185 WHERE `ID`=14303; -- Back to Aggra
UPDATE `quest_offer_reward` SET `RewardText`='What are these?$B$B<Sassy examines the pictures while listening to your tale from the Kaja\'mite cavern.>$B$BClearly that pygmy witchdoctor is from some new race never seen before. Maybe we should call them $N-ians?$B$BThey must be the ones that painted all of that stuff in the cavern. I\'m not sure that I like what you\'re describing.$B$BIt sounds to me like they\'re paintings of them and us on an island with an exploding volcano!', `VerifiedBuild`=59185 WHERE `ID`=14031; -- Capturing the Unknown
UPDATE `quest_offer_reward` SET `RewardText`='Oh, thank heavens that you survived, $N! I thought for sure that you\'d drowned when I saw you go over the side!$B$B<Sassy\'s eyes fill up with tears as she hugs you.>$B$BLook at all of these folks you saved!', `VerifiedBuild`=59185 WHERE `ID`=14001; -- Goblin Escape Pods
UPDATE `quest_offer_reward` SET `RewardText`='It\'s up to you now. Are you going to come back to life and be the $g hero : heroine; that your fellow survivors need you to be, or are you going to rest for eternity here?$B$BOnly you can decide.$B$BDon\'t go into the Light, $N!', `VerifiedBuild`=59185 WHERE `ID`=14239; -- Don't Go Into the Light!
UPDATE `quest_offer_reward` SET `RewardText`='This is nothing. You should see Bilgewater Port... the whole thing is going up in flames!$B$BFine, fine, I don\'t have time to inspect this place. Here\'s the moolah from the Bilgewater Cartel\'s insurance policy.$B$BI\'ve got to find a way off the island! Good luck, $N!', `VerifiedBuild`=59185 WHERE `ID`=14125; -- 447
UPDATE `quest_offer_reward` SET `RewardText`='Well, well, well, if it isn\'t my wayward protege, $g Mr. : Ms.; $N.$B$BI\'m hurt and disappointed. You didn\'t send me an invitation to your little party out there. Sorry about the crashers... you know how pirates can be.$B$BSo, shall we get down to business?', `VerifiedBuild`=59185 WHERE `ID`=14116; -- The Uninvited Guest
UPDATE `quest_offer_reward` SET `RewardText`='I couldn\'t have done better myself. In fact, I didn\'t.$B$BI\'m sure that in no time at all we\'ll all be talking about the great and powerful, and may I add extremely wealthy, Trade $g Prince : Princess; $N!', `VerifiedBuild`=59185 WHERE `ID`=14069; -- Good Help is Hard to Find
UPDATE `quest_offer_reward` SET `RewardText`='$N?! Nice kitty.$B$BLook we don\'t have much time here. You might have noticed that the volcano is blowing?!', `VerifiedBuild`=59185 WHERE `ID`=25100; -- Let's Ride
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. The spirits of the fallen can now be put to rest.', `VerifiedBuild`=59185 WHERE `ID`=25093; -- The Heads of the SI:7
UPDATE `quest_offer_reward` SET `RewardText`='I told you we would meet again, $N.$B$B<The Warchief gives you an appraising look.>$B$BUnfortunate that it\'s under such dire circumstances.', `VerifiedBuild`=59185 WHERE `ID`=25023; -- Old Friends
UPDATE `quest_offer_reward` SET `RewardText`='Careful with those glands, $N, careful!$B$B<Grapplehammer\'s eyes light up at the sight of the fiery organs.>$B$BAnd now to load them into the refashioned shredder boot. I\'m certain that you\'ll be surprised and amazed by my genius invention.', `VerifiedBuild`=59185 WHERE `ID`=24954; -- Children of a Turtle God
UPDATE `quest_offer_reward` SET `RewardText`='$N? What are you doing wearing that pygmy helm? Looks like it\'s about to fall apart.$B$BI\'m glad that they sent you up here. I thought for sure they were going to send that jerk, Grapplehammer and his ego-enabling assistant.', `VerifiedBuild`=59185 WHERE `ID`=24924; -- Oomlot Village
UPDATE `quest_offer_reward` SET `RewardText`='$N? We\'re saved!$B$BWho am I kidding? We\'re all going to die!!!', `VerifiedBuild`=59185 WHERE `ID`=24897; -- Get Back to Town
UPDATE `quest_offer_reward` SET `RewardText`='Thrall had you deliver this?$B$B<The Warchief takes a step back, visibly shaken.>$B$BI understand the meaning of this all too well, goblin.$B$B<Garrosh points to Gobber.>$B$BThis smelly thing was caught unattended in the city and seems to recognize you.$B$BI have already put others of your kind to work in Azshara. Take it with you when you leave.$B$BFrom this day forward, you and your Bilgewater Cartel will serve the Horde!', `VerifiedBuild`=59185 WHERE `ID`=25267; -- Message for Garrosh
UPDATE `quest_offer_reward` SET `RewardText`='<The orc continues on in hushed tones.>$B$BI know who sent you. Did he give you something to deliver to me?', `VerifiedBuild`=59185 WHERE `ID`=25266; -- Warchief's Emissary
UPDATE `quest_offer_reward` SET `RewardText`='Lok\'tar! Victory, $N!', `VerifiedBuild`=59185 WHERE `ID`=25265; -- Victory!
UPDATE `quest_offer_reward` SET `RewardText`='You did it! You did it!$B$BWe\'re saved, $N!', `VerifiedBuild`=59185 WHERE `ID`=25251; -- Final Confrontation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=25244; -- What Kind of Name is Candy, Anyway?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=25202; -- The Fastest Way to His Heart

DELETE FROM `quest_details` WHERE `ID` IN (14153 /*Life of the Party*/, 14013 /*Charge*/, 14110 /*The New You*/, 26711 /*Off to the Bank*/, 26807 /*Return to Eitrigg*/, 26806 /*Reports to Orgrimmar*/, 26804 /*Flight to Razor Hill*/, 25275 /*Report to the Labor Captain*/, 25244 /*What Kind of Name is Candy, Anyway?*/, 25202 /*The Fastest Way to His Heart*/, 14012 /*Immolate*/, 14008 /*Arcane Missiles*/, 14011 /*Primal Strike*/, 14009 /*Flash Heal*/, 14010 /*Eviscerate*/, 14007 /*Steady Shot*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14153, 5, 17, 0, 0, 0, 0, 0, 0, 59185), -- Life of the Party
(14013, 34, 0, 0, 0, 0, 0, 0, 0, 59185), -- Charge
(14110, 6, 0, 0, 0, 0, 0, 0, 0, 59185), -- The New You
(26711, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Off to the Bank
(26807, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Return to Eitrigg
(26806, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Reports to Orgrimmar
(26804, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Flight to Razor Hill
(25275, 25, 1, 15, 0, 0, 0, 0, 0, 59185), -- Report to the Labor Captain
(25244, 5, 0, 0, 0, 0, 0, 0, 0, 59185), -- What Kind of Name is Candy, Anyway?
(25202, 274, 273, 0, 0, 0, 0, 0, 0, 59185), -- The Fastest Way to His Heart
(14012, 2, 25, 0, 0, 0, 0, 0, 0, 59185), -- Immolate
(14008, 2, 25, 0, 0, 0, 0, 0, 0, 59185), -- Arcane Missiles
(14011, 2, 25, 0, 0, 0, 0, 0, 0, 59185), -- Primal Strike
(14009, 2, 25, 0, 0, 0, 0, 0, 0, 59185), -- Flash Heal
(14010, 2, 25, 0, 0, 0, 0, 0, 0, 59185), -- Eviscerate
(14007, 2, 25, 0, 0, 0, 0, 0, 0, 59185); -- Steady Shot

UPDATE `quest_details` SET `VerifiedBuild`=59185 WHERE `ID` IN (24744, 24741, 24671, 27139, 14245, 14244, 14445, 14243, 14326, 14242, 14241, 14240, 14238, 14237, 14303, 14236, 14235, 14234, 14233, 14031, 14021, 14248, 14473, 14019, 14014, 14001, 14126, 14125, 14124, 14121, 14123, 14122, 14120, 14116, 14115, 24520, 24503, 24502, 24488, 14070, 24567, 14071, 28349, 25473, 14069, 14075, 14138, 25109, 25100, 25099, 25098, 25066, 25058, 25093, 25024, 25023, 24958, 24954, 24952, 24946, 24945, 24942, 24940, 24937, 24929, 24925, 24924, 24901, 24897, 24868, 24864, 24859, 24858, 24856, 24817, 24816, 26803, 25267, 25266, 25265, 25251, 25214, 25213, 25207, 25204, 25201, 25200, 25184, 25125, 25123, 25122, 25110);

DELETE FROM `quest_request_items` WHERE `ID` IN (14013 /*Charge*/, 14153 /*Life of the Party*/, 25244 /*What Kind of Name is Candy, Anyway?*/, 25204 /*Release the Valves*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(14013, 0, 33, 0, 0, 'Warrior-Matic NX-01 is online and ready, $g sir : ma\'am;.', 59185), -- Charge
(14153, 0, 6, 0, 0, 'How\'s the party going?$B$BYou look amazing! So beautiful!', 59185), -- Life of the Party
(25244, 0, 6, 0, 0, 'Are you having second thoughts?', 59185), -- What Kind of Name is Candy, Anyway?
(25204, 0, 0, 0, 0, 'You have not yet released all four of the valves. The coolant to the platform is still functioning within normal operating parameters.', 59185); -- Release the Valves

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (24741, 14238, 25093, 24817, 24901, 14124, 14123, 14122, 14121, 25066, 14115, 25058, 14021, 14019, 14014, 24868, 24864, 24859, 24858, 24946, 24945, 14075, 14071, 14070, 14069, 24925, 24744, 25214, 25200, 25110);

UPDATE `quest_request_items` SET `CompletionText`='There are still too many for us to get through.$B$BHave faith in yourself, $N. Let your true warrior heart shine through.', `VerifiedBuild`=59185 WHERE `ID`=14236; -- Weed Whacker
UPDATE `quest_request_items` SET `CompletionText`='$N, find anything interesting in the cavern?' WHERE `ID`=14233;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='$N, take it easy on Grapplehammer. He\'s a genius, but he\'s got a fragile ego.', `VerifiedBuild`=59185 WHERE `ID`=24816; -- Who's Top of the Food Chain Now?
UPDATE `quest_request_items` SET `CompletionText`='Oh, $N, it\'s you. What an unexpected surprise.$B$B<The Trade Prince rubs his hands together.>' WHERE `ID`=14126;
UPDATE `quest_request_items` SET `CompletionText`='What are you gonna do when Maxx Avalanche comes down on you, $N?! How\'s the hatchling hunting coming?', `VerifiedBuild`=59185 WHERE `ID`=14473; -- It's Our Problem Now
UPDATE `quest_request_items` SET `CompletionText`='No time like the present to be done with the simple task I put before you, $N. Wouldn\'t you agree?', `VerifiedBuild`=59185 WHERE `ID`=24954; -- Children of a Turtle God
UPDATE `quest_request_items` SET `CompletionText`='I still see some out there! Please, $N, go get them before they drown!', `VerifiedBuild`=59185 WHERE `ID`=14001; -- Goblin Escape Pods
UPDATE `quest_request_items` SET `CompletionText`='You still have a few goblin zombies to deal with, $N. Look sharp, superstar!', `VerifiedBuild`=59185 WHERE `ID`=24942; -- Zombies vs. Super Booster Rocket Boots
UPDATE `quest_request_items` SET `CompletionText`='Not enough cluckers, $N. We\'ll all starve.', `VerifiedBuild`=59185 WHERE `ID`=24671; -- Cluster Cluck
UPDATE `quest_request_items` SET `CompletionText`='There are yet more Alliance paratroopers that need to be dispatched if we\'re to get about the business of escaping from this island, $N.', `VerifiedBuild`=59185 WHERE `ID`=25024; -- Repel the Paratroopers
UPDATE `quest_request_items` SET `CompletionText`='We\'re counting on you, $N!', `VerifiedBuild`=59185 WHERE `ID`=24488; -- The Replacements
UPDATE `quest_request_items` SET `CompletionText`='$N, I still hear Yngwie yelling!', `VerifiedBuild`=59185 WHERE `ID`=24929; -- Send a Message
UPDATE `quest_request_items` SET `CompletionText`='$N, I still hear Yngwie yelling!', `VerifiedBuild`=59185 WHERE `ID`=24929; -- Send a Message
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`='$N, take it easy on Grapplehammer. He\'s a genius, but he\'s got a fragile ego.', `VerifiedBuild`=59185 WHERE `ID`=24816; -- Who's Top of the Food Chain Now?
UPDATE `quest_request_items` SET `CompletionText`='No time like the present to be done with the simple task I put before you, $N. Wouldn\'t you agree?', `VerifiedBuild`=59185 WHERE `ID`=24954; -- Children of a Turtle God
UPDATE `quest_request_items` SET `CompletionText`='There are yet more Alliance paratroopers that need to be dispatched if we\'re to get about the business of escaping from this island, $N.', `VerifiedBuild`=59185 WHERE `ID`=25024; -- Repel the Paratroopers
UPDATE `quest_request_items` SET `CompletionText`='You still have a few goblin zombies to deal with, $N. Look sharp, superstar!', `VerifiedBuild`=59185 WHERE `ID`=24942; -- Zombies vs. Super Booster Rocket Boots
UPDATE `quest_request_items` SET `CompletionText`='What is this, goblin? Your kind are not allowed inside Grommash Hold.$B$BLeave before I have to teach you your place.' WHERE `ID`=25267;
UPDATE `quest_request_items` SET `CompletionText`='What possible business could you have in Orgrimmar, goblin?' WHERE `ID`=25266;
UPDATE `quest_request_items` SET `CompletionText`='$N, you have to go deal with the Trade Prince before it\'s too late!', `VerifiedBuild`=59185 WHERE `ID`=25251; -- Final Confrontation
UPDATE `quest_request_items` SET `CompletionText`='The soulstone is the key, $N!', `VerifiedBuild`=59185 WHERE `ID`=25123; -- Throw It On the Ground!
UPDATE `quest_request_items` SET `CompletionText`='Increase their morale, $N, so that they will run to freedom!', `VerifiedBuild`=59185 WHERE `ID`=25122; -- Morale Boost
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=59185 WHERE `ID`=25202; -- The Fastest Way to His Heart
UPDATE `quest_request_items` SET `CompletionText`='Let\'s see what you have there, $N.', `VerifiedBuild`=59185 WHERE `ID`=25201; -- The Ultimate Footbomb Uniform

DELETE FROM `quest_request_items` WHERE `ID` IN (14012 /*Immolate*/, 14011 /*Primal Strike*/, 14010 /*Eviscerate*/, 14009 /*Flash Heal*/, 14008 /*Arcane Missiles*/, 14007 /*Steady Shot*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(14012, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185), -- Immolate
(14011, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185), -- Primal Strike
(14010, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185), -- Eviscerate
(14009, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185), -- Flash Heal
(14008, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185), -- Arcane Missiles
(14007, 0, 1, 0, 0, 'Whenever you\'re ready, $g sir : ma\'am;.', 59185); -- Steady Shot

UPDATE `creature_queststarter` SET `VerifiedBuild`=59185 WHERE `id`=38120 AND `quest` IN (24744, 24671, 24958, 24954, 24856, 24816) OR `id`=38122 AND `quest`=24741 OR `id`=36471 AND `quest` IN (27139, 24945) OR `id`=36470 AND `quest`=14245 OR `id`=36425 AND `quest`=14244 OR `id`=36188 AND `quest`=14445 OR `id`=36161 AND `quest`=14243 OR `id`=36145 AND `quest`=14326 OR `id`=36127 AND `quest`=14242 OR `id`=36112 AND `quest`=14241 OR `id`=35917 AND `quest` IN (14240, 14238) OR `id`=35875 AND `quest` IN (14237, 14235) OR `id`=35893 AND `quest` IN (14303, 14236) OR `id`=35650 AND `quest` IN (14234, 14248, 14014) OR `id`=35837 AND `quest`=14233 OR `id`=35769 AND `quest` IN (14031, 14021) OR `id`=35786 AND `quest`=14473 OR `id`=35758 AND `quest`=14019 OR `id`=36600 AND `quest`=14001 OR `id`=34668 AND `quest` IN (14126, 14125, 14122, 14116, 14115, 14070, 28349, 14138) OR `id`=34872 AND `quest` IN (14124, 25473, 14069, 14075) OR `id`=34874 AND `quest` IN (14121, 24567, 14071) OR `id`=34693 AND `quest`=14123 OR `id`=35222 AND `quest`=14120 OR `id`=35054 AND `quest` IN (14153, 26711) OR `id`=34697 AND `quest`=14013 OR `id`=35120 AND `quest`=14110 OR `id`=37106 AND `quest` IN (24520, 24502, 24488) OR `id`=38517 AND `quest`=25109 OR `id`=39066 AND `quest`=25100 OR `id`=38935 AND `quest` IN (25099, 25024) OR `id`=38387 AND `quest` IN (25098, 25066, 25058, 24940, 24924, 24901) OR `id`=39065 AND `quest`=25093 OR `id`=38928 AND `quest`=25023 OR `id`=38738 AND `quest` IN (24952, 24942) OR `id`=38124 AND `quest` IN (24946, 24817) OR `id`=38647 AND `quest` IN (24937, 24929, 24925) OR `id`=38432 AND `quest` IN (24897, 24868, 24864, 24858) OR `id`=38381 AND `quest`=24859 OR `id`=41140 AND `quest`=26807 OR `id`=3139 AND `quest`=26806 OR `id`=3310 AND `quest`=26804 OR `id`=39605 AND `quest`=25275 OR `id`=3144 AND `quest`=26803 OR `id`=39609 AND `quest`=25267 OR `id`=38935 AND `quest`=25266 OR `id`=38387 AND `quest` IN (25265, 25251, 25244) OR `id`=38120 AND `quest`=25214 OR `id`=38124 AND `quest` IN (25213, 25204, 25200, 25110) OR `id`=38647 AND `quest`=25202 OR `id`=38738 AND `quest`=25201 OR `id`=39341 AND `quest`=25184 OR `id`=39199 AND `quest` IN (25125, 25123, 25122) OR `id`=34696 AND `quest`=14012 OR `id`=34689 AND `quest`=14008 OR `id`=34695 AND `quest`=14011 OR `id`=34692 AND `quest`=14009 OR `id`=34693 AND `quest`=14010 OR `id`=34673 AND `quest`=14007;
DELETE FROM `creature_questender` WHERE `id`=39605 AND `quest`=25267 OR `id`=39609 AND `quest`=25266;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(39605, 25267, 59185), -- Message for Garrosh ended by Garrosh Hellscream
(39609, 25266, 59185); -- Warchief's Emissary ended by Kor'kron Loyalist

UPDATE `creature_questender` SET `VerifiedBuild`=59185 WHERE`id`=38120 AND `quest` IN (27139, 24954, 24952, 24817,  24744) OR `id`=38122 AND `quest`=24741 OR `id`=36471 AND `quest` IN (14245, 24945) OR `id`=36470 AND `quest`=14244 OR `id`=36425 AND `quest`=14445 OR `id`=36188 AND `quest`=14243 OR `id`=36161 AND `quest`=14326 OR `id`=36145 AND `quest`=14242 OR `id`=36127 AND `quest`=14241 OR `id`=36112 AND `quest`=14240 OR `id`=35917 AND `quest` IN (14238, 14237) OR `id`=35875 AND `quest` IN (14303, 14234) OR `id`=35893 AND `quest` IN (14236, 14235) OR `id`=35650 AND `quest` IN (14233, 14031, 14014, 14001) OR `id`=35769 AND `quest` IN (14021, 14248) OR `id`=35758 AND `quest`=14019 OR `id`=35786 AND `quest`=14473 OR `id`=36608 AND `quest`=14239 OR `id`=35222 AND `quest` IN (14126, 14116) OR `id`=37602 AND `quest`=14125 OR `id`=34693 AND `quest`=14123 OR `id`=34874 AND `quest` IN (14121, 14071, 28349) OR `id`=34668 AND `quest` IN (14122, 14120, 14115, 14153, 14070, 24520, 25473) OR `id`=34872 AND `quest` IN (14124, 14069, 14075, 14138) OR `id`=35054 AND `quest`=14110 OR `id`=34697 AND `quest`=14013 OR `id`=35120 AND `quest`=26711 OR `id`=37106 AND `quest` IN (24503, 24488, 24567) OR `id`=38517 AND `quest`=25100 OR `id`=39066 AND `quest`=25099 OR `id`=38935 AND `quest` IN (25098, 25024, 25023) OR `id`=38387 AND `quest` IN (25066, 25058, 24937, 24901, 24897) OR `id`=39065 AND `quest`=25093 OR `id`=38928 AND `quest`=24958 OR `id`=38124 AND `quest` IN (24946, 24816) OR `id`=38738 AND `quest` IN (24942, 24940) OR `id`=38647 AND `quest` IN (24929, 24925, 24924) OR `id`=38432 AND `quest` IN (24868, 24864, 24858, 24856) OR `id`=38381 AND `quest`=24859 OR `id`=3144 AND `quest`=26807 OR `id`=41140 AND `quest`=26806 OR `id`=3139 AND `quest`=26804 OR `id`=3310 AND `quest`=26803 OR `id`=38935 AND `quest`=25265 OR `id`=38387 AND `quest` IN (25251, 25244, 25213) OR `id`=38120 AND `quest`=25214 OR `id`=38647 AND `quest`=25202 OR `id`=38124 AND `quest` IN (25207, 25200, 25184, 25110, 25109) OR `id`=38738 AND `quest`=25201 OR `id`=39341 AND `quest`=25125 OR `id`=39199 AND `quest` IN (25122, 25123) OR `id`=34696 AND `quest`=14012 OR `id`=34689 AND `quest`=14008 OR `id`=34695 AND `quest`=14011 OR `id`=34692 AND `quest`=14009 OR `id`=34693 AND `quest`=14010 OR `id`=34673 AND `quest`=14007;

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=59185 WHERE`id`=202613 AND `quest`=25207;

UPDATE `gameobject_questender` SET `VerifiedBuild`=59185 WHERE`id`=202613 AND `quest`=25204;
