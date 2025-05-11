DELETE FROM `quest_offer_reward` WHERE `ID` IN (28284 /*What's that Rattle?*/, 26878 /*Disciples of Naralex*/, 25556 /*Into Zul'Farrak*/, 26067 /*Jin'Zil's Blessing*/, 26068 /*Kobold Fury!*/, 26066 /*Reinforcements...*/, 26062 /*Da Voodoo: Resonite Crystal*/, 26064 /*Fight On Their Stomachs*/, 26061 /*Da Voodoo: Ram Horns*/, 26060 /*Da Voodoo: Stormer Heart*/, 26059 /*Eyes and Ears: Malaka'jin*/, 26058 /*In Defense of Krom'gar Fortress*/, 26048 /*Spare Parts Up In Here!*/, 26047 /*And That's Why They Call Them Peons...*/, 26045 /*I Got Your Parts Right Here...*/, 26046 /*Between a Rock and a Hard Place*/, 26044 /*Where Are the Parts?*/, 26020 /*Report to Bombgutz*/, 26011 /*Enemy of the Horde: Marshal Paltrow*/, 26028 /*Mr. D's Wild Ride*/, 26026 /*Dream of a Better Tomorrow*/, 26010 /*Ashes to Ashes*/, 28084 /*Might of the Krom'gar*/, 26004 /*Krom'gar Fortress*/, 26002 /*Alliance Attack Plans*/, 26003 /*Lessons from the Lost Isles*/, 26001 /*The Missing Blastgineer*/, 25999 /*Barrier to Entry*/, 28859 /*The Dunes of Silithus*/, 27130 /*Saving Warpwood*/, 27134 /*Ogre in the Field*/, 27132 /*The Highborne*/, 25356 /*To the Summit*/, 25945 /*We're Here to Do One Thing, Maybe Two...*/, 26894 /*Blackfathom Deeps*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28284, 0, 0, 0, 0, 0, 0, 0, 0, 'Interesting....', 59297), -- What's that Rattle?
(26878, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes, $c? What brings you to this place?', 59297), -- Disciples of Naralex
(25556, 11, 0, 0, 0, 0, 0, 0, 0, '<Mazoga\'s ghost gives you a blood-smeared grin.>$B$BHow you doin\', mon?', 59069), -- Into Zul'Farrak
(26067, 4, 25, 0, 0, 0, 0, 0, 0, 'Victory, at last! Though it stands to reason that without a stable supply line this victory will be short lived. Enjoy it while it lasts, $N.', 59297), -- Jin'Zil's Blessing
(26068, 11, 273, 1, 0, 0, 0, 0, 0, '<Devo laughs.>$B$BFascinating tale, friend. It would seem that our newfound kobold allies might be somewhat useful after all!', 59297), -- Kobold Fury!
(26066, 1, 1, 0, 0, 0, 0, 0, 0, 'In times of crisis, a desperate act may be all that is needed to secure victory. Sending a swarm of kobolds at the enemy may be the edge that we need to win.', 59297), -- Reinforcements...
(26062, 5, 1, 0, 0, 0, 0, 0, 0, 'Finally! Now I will create the charm that will hold the voodoo enchantment!', 59297), -- Da Voodoo: Resonite Crystal
(26064, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $N. These eggs should get us through the week.', 59297), -- Fight On Their Stomachs
(26061, 21, 1, 0, 0, 0, 0, 0, 0, 'Excellent. Once I have everything I need I will mix it all together and unleash the voodoo! Woe unto our enemies!', 59297), -- Da Voodoo: Ram Horns
(26060, 4, 1, 0, 0, 0, 0, 0, 0, 'Excellent. Once I have everything I need I will mix it all together and unleash the voodoo! Woe unto our enemies!', 59297), -- Da Voodoo: Stormer Heart
(26059, 1, 1, 0, 0, 0, 0, 0, 0, 'I see that Krom\'gar has sent his best!$B$BGood, we have much work to do. The filth that is the Alliance have entered into a treaty with the Grimtotem. Now we fend off attacks from both forces.$B$BWe are spread thin across the Greatwood Vale and will soon fall beneath the concerted effort of our enemies. There is only one hope: VOODOO!', 59297), -- Eyes and Ears: Malaka'jin
(26058, 5, 66, 0, 0, 0, 0, 0, 0, 'I have never seen such an act of bravery. You saved the base, sergeant - or should I say legionnaire! Lok\'tar!', 59297), -- In Defense of Krom'gar Fortress
(26048, 5, 0, 0, 0, 0, 0, 0, 0, 'Just in time! The flying machines are starting to mass. Attack is imminent!', 59297), -- Spare Parts Up In Here!
(26047, 4, 1, 0, 0, 0, 0, 0, 0, 'I knew it! You are a hero! If I have anything to do with it, you\'ll be promoted to legionnaire!', 59297), -- And That's Why They Call Them Peons...
(26045, 5, 0, 0, 0, 0, 0, 0, 0, 'I\'ll be damned! You managed to get the parts and not die. How are you only a sergeant?', 59297), -- I Got Your Parts Right Here...
(26046, 1, 1, 0, 0, 0, 0, 0, 0, 'Get the parts, kill the elementals and rescue the peons... We get all of that done and we\'re as good as promoted!', 59297), -- Between a Rock and a Hard Place
(26044, 1, 5, 0, 0, 0, 0, 0, 0, 'Um... Well you see, it\'s quite simple... THIS CAVE IS SWARMING WITH SOULLESS KILLING MACHINES!', 59297), -- Where Are the Parts?
(26020, 6, 5, 0, 0, 0, 0, 0, 0, 'Properly motivated? Wha... what does that mean? Listen, Sergeant, I have a built in mechanism for survival called self-interest. That is, it\'s in my best interest to NOT DIE. With that said, there\'s no fixing these guns without the right materials.', 59297), -- Report to Bombgutz
(26011, 6, 1, 0, 0, 0, 0, 0, 0, 'Did you find any suspicious documents at Paltrow\'s camp? Perhaps on his rotting corpse? Any insight into the Alliance\'s attack patterns would be extremely helpful in the battle for Stonetalon.', 59297), -- Enemy of the Horde: Marshal Paltrow
(26028, 1, 1, 0, 0, 0, 0, 0, 0, '<Overlord Krom\'gar coughs.>$B$BI am - perhaps for the first time in my life - at a loss for words.$B$BI am really not sure where Clarissa even came from...', 59297), -- Mr. D's Wild Ride
(26026, 1, 0, 0, 0, 0, 0, 0, 0, '<Clarissa claps excitedly.>$B$BMr. D you\'re gonna be ok! Hooray!$B$B<Clarissa expertly places all of the parts you collected into Large Daddy.>$B$BOh, Mr. D! I knew it!', 59297), -- Dream of a Better Tomorrow
(26010, 4, 5, 15, 0, 0, 0, 0, 0, 'Lok\'tar! Alliance pigs!$B$B<Overlord Krom\'gar spits on the ground.>$B$BEnjoy the victory for it shall be short lived. Your bravery has given us more time to prepare, nothing more.', 59297), -- Ashes to Ashes
(28084, 1, 15, 0, 0, 0, 0, 0, 0, 'You may now make use of the Krom\'gar stockpile, $N! For a small fee I will sell you armaments of battle, useful for crushing your enemies! The availability of what I sell depends upon your rank in the army. Visit my shop whenever you earn a new rank.$B$BLOK\'TAR OGAR!', 59297), -- Might of the Krom'gar
(26004, 1, 5, 15, 0, 0, 0, 0, 0, '<Overlord Krom\'gar takes the plans from you.>$B$BHmm. Perhaps this grunt is more than $g he:she; would appear. Perhaps this grunt is in actuality a sergeant.$B$BLook now upon Krom\'gar Sergeant $N, soldiers. $g He:She; has come to serve warning of a cowardly Alliance attack. An attack that we will CRUSH!', 59297), -- Krom'gar Fortress
(26002, 1, 15, 1, 25, 0, 0, 0, 0, 'Damn shame... He was a good goblin.$B$B<Saurboz shakes his fist.>$B$BAs for you, $N, you\'ve done well. These attack plans will help us prepare. I want you to deliver the plans to Overlord Krom\'gar personally! There\'s sure to be a promotion in it for you.', 59297), -- Alliance Attack Plans
(26003, 1, 4, 0, 0, 0, 0, 0, 0, 'Well done, $g brother:sister;! Now they will know that they cannot sneak up on the Horde!', 59297), -- Lessons from the Lost Isles
(26001, 0, 0, 0, 0, 0, 0, 0, 0, 'Blastgineer Fuzzwhistle is definitely dead. It\'s probably for the best.$B$BIt looks like he\'s holding a note in his hand.', 59297), -- The Missing Blastgineer
(25999, 1, 25, 0, 0, 0, 0, 0, 0, '<Saurboz looks you over.>$B$BYou have all of your limbs intact. This is a first.', 59297), -- Barrier to Entry
(28859, 2, 25, 0, 0, 0, 0, 0, 0, 'Welcome to Cenarion Hold, traveler.', 59185), -- The Dunes of Silithus
(27130, 0, 0, 0, 0, 0, 0, 0, 0, 'Your face shows signs of desperate conflict. I honor your presence, brave $c.', 59297), -- Saving Warpwood
(27134, 0, 0, 0, 0, 0, 0, 0, 0, 'These ogres no pushovers. I need you help me finish Orhan\'s task, $r. ', 59297), -- Ogre in the Field
(27132, 0, 0, 0, 0, 0, 0, 0, 0, 'I sensed your coming all the way from Camp Mojache. Your assistance would be most welcome.', 59297), -- The Highborne
(25356, 0, 0, 0, 0, 0, 0, 0, 0, 'Jawn sent you? Good! We need your help, now!', 59297), -- To the Summit
(25945, 1, 25, 5, 0, 0, 0, 0, 0, 'While you remain in Stonetalon and fight as a Krom\'gar soldier you will remain suited up! Am I clear? DO you hear me, grunt? If I see you without Hellscream\'s beloved tabard I will put my foot so far up your backside that you\'ll be spitting up laces.', 59297), -- We're Here to Do One Thing, Maybe Two...
(26894, 1, 0, 0, 0, 0, 0, 0, 0, 'Did Commander Grimfang send you? I\'ve asked him to find suitable recruits to aid me here.', 59297); -- Blackfathom Deeps

UPDATE `quest_offer_reward` SET `RewardText`='You have our thanks, $N.', `VerifiedBuild`=59069 WHERE `ID`=28842; -- Umbranse's Deliverance
UPDATE `quest_offer_reward` SET `RewardText`='<Haleh applies the water to your dreamcatcher.>$b$bYou\'ve done well, $N.', `VerifiedBuild`=59069 WHERE `ID`=28840; -- Winterwater
UPDATE `quest_offer_reward` SET `RewardText`='You are $N, yes?$b$bGood, you will serve well. I require the aid of a $c such as yourself.', `VerifiedBuild`=59069 WHERE `ID`=28847; -- The Pursuit of Umbranse
UPDATE `quest_offer_reward` SET `RewardText`='Hell-Hoot is slain, and her meat is just as succulent as you\'d expect.$b$bToday, we eat a legend.  Thank you, $N.', `VerifiedBuild`=59069 WHERE `ID`=28782; -- A Bird of Legend
UPDATE `quest_offer_reward` SET `RewardText`='<Francis smacks his lips.>$b$bYou\'ve got to try some of this, $N.  These maulers are perfectly tenderized... possibly because of the pummeling you delivered.', `VerifiedBuild`=59069 WHERE `ID`=28719; -- A Little Gamy
UPDATE `quest_offer_reward` SET `RewardText`='They may not look like much to you, but these relics hold great value to the people of Starfall.  You are kind, $N.', `VerifiedBuild`=59069 WHERE `ID`=28701; -- Out of Harm's Way
UPDATE `quest_offer_reward` SET `RewardText`='Hah! She\'ll think twice before making fun of my ideas again!$B$BThanks for your help, $N. I couldn\'t have had so much fun without you!', `VerifiedBuild`=59069 WHERE `ID`=28722; -- Yetiphobia
UPDATE `quest_offer_reward` SET `RewardText`='These furs are perfect, $N. We\'re off to a great start here!', `VerifiedBuild`=59069 WHERE `ID`=28629; -- Are We There, Yeti?
UPDATE `quest_offer_reward` SET `RewardText`='Yes, if you let me examine this for a while, I might be able to translate it for you.$B$B<Kelek flips through the pages.>$B$BWhen I am able to look over this fully, I will send word to you.$B$BThank you for sharing this with me, $N. Very little is known about the Winterfall furbolg.', `VerifiedBuild`=59069 WHERE `ID`=28472; -- Words of the High Chief
UPDATE `quest_offer_reward` SET `RewardText`='Thank you so much, $N. I hope to get back to my studies without worry that I will be ambushed. Please accept this as a reward.', `VerifiedBuild`=59069 WHERE `ID`=28470; -- High Chief Winterfall
UPDATE `quest_offer_reward` SET `RewardText`='Thanks so much, $N! Now I can get back to work here.$B$BDid you find anything of interest at the Winterfall camp?', `VerifiedBuild`=59069 WHERE `ID`=28460; -- Threat of the Winterfall
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for what you have done, as saddening as it is.  Accept this as a token of thanks.$B$BI would ask of you to please continue helping us, $N.  We have very few allies on which to call upon, and without your aid, the threats against my tribe would surely be too much for us to handle alone.', `VerifiedBuild`=59069 WHERE `ID`=28522; -- Winterfall Activity
UPDATE `quest_offer_reward` SET `RewardText`='I have been watching you, $N.  Your arrival was not unforeseen.$b$bIn fact, your arrival here has been predetermined for some time now.', `VerifiedBuild`=59069 WHERE `ID`=24694; -- The Shaper's Terrace
UPDATE `quest_offer_reward` SET `RewardText`='A pylon in the west?  And a relationship between titans and dinosaurs?  This is a lot to take in, $N.', `VerifiedBuild`=59069 WHERE `ID`=24723; -- The Western Pylon
UPDATE `quest_offer_reward` SET `RewardText`='You think this may be related to the attacks on Marshal\'s Refuge, $N?', `VerifiedBuild`=59069 WHERE `ID`=24722; -- The Northern Pylon
UPDATE `quest_offer_reward` SET `RewardText`='I knew it!  Durrin HAS been digging around here.  And he\'s been excavating what could be the archaeological find of the century!  Now I just have to find out where he\'s stashing the bones...$b$bThanks $N.  You\'ve been a great help.', `VerifiedBuild`=59069 WHERE `ID`=24709; -- A Tale of Two Shovels
UPDATE `quest_offer_reward` SET `RewardText`='Our duty is fulfilled.  Even so, it troubles me that the people of today are less than gracious...   Perhaps tomorrow we shall experience proper thankfulness.$b$bNow we must ride.  More adventures await!', `VerifiedBuild`=59069 WHERE `ID`=24705; -- Town Dwellers Were Made to be Saved
UPDATE `quest_offer_reward` SET `RewardText`='Wow, 2 of each color!  You\'re certainly an overachiever, $N.  My companions and I could use a $r like you around here.  Ever consider a career in profiteering?', `VerifiedBuild`=59069 WHERE `ID`=24717; -- The Apes of Un'Goro
UPDATE `quest_offer_reward` SET `RewardText`='She decided to stay?  Fascinating... I\'ll have to look over this data and find out why.$B$BThank you again, $N. I really appreciate it.', `VerifiedBuild`=59069 WHERE `ID`=24926; -- Serving A-Me 01
UPDATE `quest_offer_reward` SET `RewardText`='Now I will continue my experiments! Thank you, $N.', `VerifiedBuild`=59069 WHERE `ID`=24720; -- Crystals of Power
UPDATE `quest_offer_reward` SET `RewardText`='Brilliant!  We\'re on the cusp of something big here, $N.  Here\'s your share of the inevitably huge profits.$b$bNow, on to other matters...', `VerifiedBuild`=59069 WHERE `ID`=24691; -- Peculiar Delicacies
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve completed a remarkable task, $N.  You are truly worthy of commendation.  Thank you, and congratulations!', `VerifiedBuild`=59069 WHERE `ID`=24692; -- The Fledgling Colossus
UPDATE `quest_offer_reward` SET `RewardText`='At last, Blazerunner is dispatched.  Thanks, $N... he was driving me batty.', `VerifiedBuild`=59069 WHERE `ID`=24690; -- Blazerunner
UPDATE `quest_offer_reward` SET `RewardText`='Ringo\'s not in the best shape, $N, but I am glad to have him back in one piece!$B$BThank you for finding him.', `VerifiedBuild`=59069 WHERE `ID`=24735; -- A Little Help From My Friends
UPDATE `quest_offer_reward` SET `RewardText`='You were right to bring this pylon to my attention, $N.  This is just the sort of thing I\'ve been studying.', `VerifiedBuild`=59069 WHERE `ID`=24721; -- The Eastern Pylon
UPDATE `quest_offer_reward` SET `RewardText`='The Earth Mother be praised! You\'ve done it! Fair play to you, $N. You have proven to be a great hunter in your own right. Your spirit is strong. Your bravery unmatched. And your strength has been fortified. I bow down to your skills.$B$BOnly the greatest of my ancestors could have accomplished something so incredible. Congratulations.', `VerifiedBuild`=59069 WHERE `ID`=24733; -- The Bait for Lar'korwi
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  Now we\'re a bit safer from dinosaur attacks... plus I\'ve got all this fresh meat to serve to my men.', `VerifiedBuild`=59069 WHERE `ID`=24697; -- How to Make Meat Fresh Again
UPDATE `quest_offer_reward` SET `RewardText`='Hmm... yes, these seeds will do nicely.  You have the gratitude of the Cenarion Circle, $N.', `VerifiedBuild`=59069 WHERE `ID`=24686; -- Carried on the Waves
UPDATE `quest_offer_reward` SET `RewardText`='Ah, fine specimens, $N. The two pieces you\'ve found should be perfect for baiting Lar\'korwi into the open. I cannot wait to see the outcome of your fight with the monster. He is a massive thing with claws as sharp as the finest blades. You will look into his eyes and you will know death.', `VerifiedBuild`=59069 WHERE `ID`=24732; -- The Scent of Lar'korwi
UPDATE `quest_offer_reward` SET `RewardText`='This will do nicely, $N. It seems Lar\'korwi eats well these days. Although, I wonder where he found a threshadon in this area. Odd.$B$BRegardless, I will hold onto this until you are ready for your confrontation with the beast. Do not worry for my safety--I am sure you\'ve angered Lar\'korwi enough that he will not kill me until after he\'s tasted your flesh.', `VerifiedBuild`=59069 WHERE `ID`=24731; -- The Fare of Lar'korwi
UPDATE `quest_offer_reward` SET `RewardText`='My mentor says that sometimes you have to take away from nature before you can give back.  These raptors... I feel that they died for good cause.$b$bThank you, $N.', `VerifiedBuild`=59069 WHERE `ID`=24719; -- Claws of White
UPDATE `quest_offer_reward` SET `RewardText`='Wow, she\'s evil! But, what does it mean, $N? Is Magatha going to destroy us? Is she in charge of the Twilight\'s Hammer now?$B$BWhatever happens, you\'ve delivered us from our enemies. Please allow me to show you our gratitude.', `VerifiedBuild`=59297 WHERE `ID`=28161; -- Spread the Word
UPDATE `quest_offer_reward` SET `RewardText`='<Lakota looks worried about the condition of the armor, especially the bloodstains.>$B$BYou sure don\'t fool around, do you, $N? Well, it\'ll have to do.', `VerifiedBuild`=59297 WHERE `ID`=28125; -- Something to Wear
UPDATE `quest_offer_reward` SET `RewardText`='The pridelings did what? They must love you deeply for freeing them.$B$BThank you, $N. You\'ve saved Highperch!', `VerifiedBuild`=59297 WHERE `ID`=28098; -- The Twilight Skymaster
UPDATE `quest_offer_reward` SET `RewardText`='The great Heartrazor is a majestic creature. He has told me of his gratitude and fondness for you, $N.', `VerifiedBuild`=59297 WHERE `ID`=28088; -- Release Heartrazor
UPDATE `quest_offer_reward` SET `RewardText`='<The brave gives you an appraising look.>$B$BThere is something special about you, $N. That much is certain.', `VerifiedBuild`=59297 WHERE `ID`=27324; -- Grimtotem Chiefs: Grundig Darkcloud
UPDATE `quest_offer_reward` SET `RewardText`='Surely that was the voice of the Elder Crone!$B$BWe must be very careful, $N. Great danger lies ahead if Magatha Grimtotem has taken notice of you.', `VerifiedBuild`=59297 WHERE `ID`=27326; -- The Drums of War
UPDATE `quest_offer_reward` SET `RewardText`='This is very exciting and also worrisome, $N. What are these artifacts doing here? Are they being used as a weapons against us by the Grimtotem?$B$BThe wind serpent flew northwest to that next bluff. Maybe that\'s where the drums are?', `VerifiedBuild`=59297 WHERE `ID`=27321; -- The Writ of History
UPDATE `quest_offer_reward` SET `RewardText`='I am honored by your presence, $N. Let us put the fear of the Earth Mother into the Grimtotem.', `VerifiedBuild`=59297 WHERE `ID`=27276; -- Together Again
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for freeing him, $N. Those Grimtotem would have killed him in cold blood.', `VerifiedBuild`=59297 WHERE `ID`=25872; -- The Brave and the Bold
UPDATE `quest_offer_reward` SET `RewardText`='It is oil! You\'re the best, $N!$B$BToo bad I\'m going to have to send you off now.', `VerifiedBuild`=59297 WHERE `ID`=25826; -- Deliver the Goods
UPDATE `quest_offer_reward` SET `RewardText`='That\'ll teach those scurvy dogs! You have my thanks, $N.', `VerifiedBuild`=59297 WHERE `ID`=25589; -- A Little Payback
UPDATE `quest_offer_reward` SET `RewardText`='Do you hear that, $N? That\'s the sweet hum of the refrigeration kicking in.$B$BWe\'ll be able to store our inventory down there in no time. Thank you!', `VerifiedBuild`=59297 WHERE `ID`=28047; -- Freezing the Pipes
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. They gave their lives for ice cream.', `VerifiedBuild`=59297 WHERE `ID`=28051; -- We All Scream for Ice Cream... and then Die!
UPDATE `quest_offer_reward` SET `RewardText`='You saved my Speedbarge!$B$B<Razzeric $G embraces you in a manly hug : grabs you for a big hug and a kiss;!>$B$BI can\'t begin to tell you how relieved I am, Captain $N!', `VerifiedBuild`=59297 WHERE `ID`=25543; -- Circle the Wagons... er, Boats
UPDATE `quest_offer_reward` SET `RewardText`='$N, you\'re back! Balgor made it down before you, and he\'s already eaten two bowls of raptor stew. Considering that his appetite hasn\'t suffered, I\'m sure he will be fit to travel in no time.$B$BI\'ll make sure that this artifact is taken care of. You\'ve done us a great service today.', `VerifiedBuild`=59297 WHERE `ID`=29112; -- Demon Seed
UPDATE `quest_offer_reward` SET `RewardText`='$N, you came for me!$B$B<Balgor sobs in relief.>', `VerifiedBuild`=59297 WHERE `ID`=29110; -- Mor'shan Caravan Rescue
UPDATE `quest_offer_reward` SET `RewardText`='This is terrible news! $N, at least you arrived safely.', `VerifiedBuild`=59297 WHERE `ID`=29109; -- Mor'shan Caravan Pick-Up
UPDATE `quest_offer_reward` SET `RewardText`='Nicely done. I\'m sure you\'ve struck fear into the surviving centaurs, $N. With their greatest warriors slain, they will either stop their advances or lash out at us in a foolhardy strike.$B$BI hope for the latter.', `VerifiedBuild`=59297 WHERE `ID`=855; -- Centaur Bracers
UPDATE `quest_offer_reward` SET `RewardText`='I commend you, $N. These centaur are undisciplined and cannot focus their rage as the orcs can, but they are fierce nonetheless.  In defeating them, your valor is proven.', `VerifiedBuild`=59297 WHERE `ID`=852; -- Hezrul Bloodmark
UPDATE `quest_offer_reward` SET `RewardText`='Hello $N. I have heard of your deeds from Darsok. You are a valuable $c of the Horde, indeed.', `VerifiedBuild`=59297 WHERE `ID`=29095; -- Report to Thork
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. This old orc will sleep more safely at night.', `VerifiedBuild`=59297 WHERE `ID`=29090; -- A Burning Threat
UPDATE `quest_offer_reward` SET `RewardText`='Nice work, $N!$B$BOh, the Baron tried to stop you, did he? Well, I hope you gave him a pounding.$B$BNow, I promised you a cut of the goods you recovered. Let\'s see... what\'s one percent of a half percent? Ah, here you go.', `VerifiedBuild`=59297 WHERE `ID`=14050; -- Gazlowe's Fortune
UPDATE `quest_offer_reward` SET `RewardText`='Hah! Beautiful work, $N. Those Alliance cretins will never trace this back to me. Meanwhile, it\'s back to business as usual: smuggling, double-dealing, price-gouging... I\'ve got a lot of work to catch up on.$B$BHere, I\'ll let you in on a cut of my future profits. Enjoy!', `VerifiedBuild`=59297 WHERE `ID`=14042; -- Ammo Kerblammo
UPDATE `quest_offer_reward` SET `RewardText`='Look at that. We\'re loaded! In mutiny, you gotta make the money first. Then when you get the money, you get the power. Let\'s go get some power, $N...', `VerifiedBuild`=59297 WHERE `ID`=14056; -- Glomp is Sitting On It
UPDATE `quest_offer_reward` SET `RewardText`='<Gazrog opens the lockbox and begins counting up the silver while you relate your story.>$B$BWhat!? Raptors? Just the raptors? Assaulting our caravans and looting them? Perhaps they are as intelligent as the rumors say. As if we didn\'t have enough problems, now we\'ve got to deal with brainy lizards with a lust for coin.$B$BHere, $N - you\'ve earned a share of the rescued silver. Thank you.', `VerifiedBuild`=59297 WHERE `ID`=14067; -- The Stolen Silver
UPDATE `quest_offer_reward` SET `RewardText`='Explosive spore clouds? You don\'t say ... tell me more. Choking? Stinging? Burning of the eyes? Was there itching? Nausea? Mortification? Delightful, DELIGHTFUL! You\'ve certainly earned your commission, $N.$B$BThat skin rash of yours should pass in a day or two.', `VerifiedBuild`=59297 WHERE `ID`=13998; -- In Fungus We Trust
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. Studying the beasts of an area can tell much about the area itself. We shall see what tale these shells tell, and possibly unravel the mystery of what\'s happening in the barrens.$B$BPlease accept my gratitude for your aid... and perhaps you can use these coins. I find that I do not need them.', `VerifiedBuild`=59297 WHERE `ID`=880; -- Altered Beings
UPDATE `quest_offer_reward` SET `RewardText`='So you\'ve been to the nests and placed the feathers of your prey within them. That took a fair portion of courage, no doubt about it.$B$BDo you feel a little tougher, $N? Because you look tougher now then when you first came here.  I guess the Barrens is doing its job.', `VerifiedBuild`=59297 WHERE `ID`=905; -- Into the Raptor's Den
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $N. Did you look through these? They\'re barely legible - more like angry graffiti than war plans. Hatred, jealousy, rage, personal conflicts - it\'s a wonder Verog can keep these centaur from killing each other, much less form them into an army.$B$BWe can use this to our advantage.', `VerifiedBuild`=59297 WHERE `ID`=14072; -- Flushing Out Verog
UPDATE `quest_offer_reward` SET `RewardText`='Ah, yes. These are good specimens. Potent.$B$BI am Forsaken, and we honor our contracts. Here is your reward, $N.', `VerifiedBuild`=59297 WHERE `ID`=848; -- Fungal Spores
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N. Kodobane is just one strand of a tangled thread - there are other Kolkar leaders to kill elsewhere in the Barrens. Seek out my companions at the other oases if you wish to press the assault.', `VerifiedBuild`=59297 WHERE `ID`=850; -- Kolkar Leaders
UPDATE `quest_offer_reward` SET `RewardText`='Not bad, $N. Those zhevra hold a lot of strength in their legs. I\'ve seen them knock even a tauren on its haunches!$B$BIt looks like you have some strength in you too.', `VerifiedBuild`=59297 WHERE `ID`=845; -- The Zhevra
UPDATE `quest_offer_reward` SET `RewardText`='Ah, I see you\'ve been busy. I hope you learned a lot from this prey, $N. You\'ll need the strength and cunning of beasts like these to serve my beloved Horde.', `VerifiedBuild`=59297 WHERE `ID`=903; -- Hunting the Huntress
UPDATE `quest_offer_reward` SET `RewardText`='Haha! Thank you, $N! This will help us greatly. I\'ll get these supplies packed up and on their way to the Crossroads immediately. ', `VerifiedBuild`=59297 WHERE `ID`=5041; -- Supplies for the Crossroads
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N. Without Kreenig to orchestrate the raids, my grunts should be able to keep Far Watch secure. Your people should be proud to count you among them. ', `VerifiedBuild`=59297 WHERE `ID`=872; -- The Far Watch Offensive
UPDATE `quest_offer_reward` SET `RewardText`='You have done well, $N. Those insolent quilboars will finally learn that the might of the Horde is not to be ignored.', `VerifiedBuild`=59297 WHERE `ID`=871; -- In Defense of Far Watch
UPDATE `quest_offer_reward` SET `RewardText`='Very good, $N. That\'s one less thing to worry about on the road. ', `VerifiedBuild`=59297 WHERE `ID`=844; -- Plainstrider Menace
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=59069 WHERE `ID`=25095; -- Thunderdrome: Sarinexx!
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=59069 WHERE `ID`=25094; -- Thunderdrome: Zumonga!
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=59069 WHERE `ID`=25067; -- Thunderdrome: The Ginormus!
UPDATE `quest_offer_reward` SET `RewardText`='Now you truly know what it means to be a member of the Horde, $N. ', `VerifiedBuild`=59297 WHERE `ID`=26115; -- To Be Horde...
UPDATE `quest_offer_reward` SET `RewardText`='You saw with your own eyes, $N. General Grebo attacked us!$B$B<Masha cries.>$B$BNow what will we do? Surely the Warchief will have us all executed for treason.', `VerifiedBuild`=59297 WHERE `ID`=26099; -- Is This Justice?
UPDATE `quest_offer_reward` SET `RewardText`='You possess quite a talent for destruction, $N. Whatever Alliance remain after your rampage across Battlescar Valley will be dealt with by the bomb.', `VerifiedBuild`=59297 WHERE `ID`=26082; -- To Battlescar!
UPDATE `quest_offer_reward` SET `RewardText`='Lok\'tar ogar! You are the embodiment of what it means to be a Horde soldier, $N. If only we had more like you, this war would be over and Kalimdor would belong to the Horde - UNCONTESTED!$B$BRise now as a champion of Krom\'gar!', `VerifiedBuild`=59297 WHERE `ID`=26073; -- All's Quiet on the Southern Front
UPDATE `quest_offer_reward` SET `RewardText`='<Alto clenches the bullet in his palm as you tell your story.>$B$BGann? Dead? I ... I should\'ve known. His temper... his recklessness. I knew someday it would get the better of him.$B$BBut it sounds as though you\'ve already gifted him with vengeance. Thank you, $N!$B$BTurn your attention now to Dustwallow. If the Alliance finishes their cursed road through here, all your victories in the Barrens may have been for nothing. ', `VerifiedBuild`=59297 WHERE `ID`=25292; -- Next of Kin
UPDATE `quest_offer_reward` SET `RewardText`='You have done it!  You have defeated the Kolkar!$B$BI will be sure Thrall receives word of your actions here, $N.$B$BStand tall.  You do yourself, and the Horde, proud.', `VerifiedBuild`=59297 WHERE `ID`=4021; -- Counterattack!
UPDATE `quest_offer_reward` SET `RewardText`='Bael\'dun? Destroyed?$B$B<Wincing in pain, Gann twists his head to peer behind him, where plumes of smoke darken the skyline.>$B$B$N, my friend. You have avenged Taurajo and avenged the Tauren people. The invaders will not soon recover from that blow. Thank you.$B$B<Gann closes his eyes, his head tipping forward as his breath gives way to a series of ragged coughs.>', `VerifiedBuild`=59297 WHERE `ID`=24747; -- Sabotage!
UPDATE `quest_offer_reward` SET `RewardText`='Let\'s see, let\'s see.$B$BIt looks like the artillery shells are prepped here, then loaded into the secure magazine...$B$B<Weezil rubs his hands together.>$B$B$N, are you ready to blow some stuff up?', `VerifiedBuild`=59297 WHERE `ID`=24685; -- Dwarf Fortress
UPDATE `quest_offer_reward` SET `RewardText`='<Calder grasps the gigantic heart in both hands, squeezing it and listening to the valves slurp and squish.>$B$B<His pale mask of a face splits open into an enormous, childlike grin.>$B$BIt is so very important to love one\'s work, wouldn\'t you agree, $N?$B$B<Calder chucks the heart over his shoulder into a waist-high pile of entrails.>', `VerifiedBuild`=59297 WHERE `ID`=24620; -- Hearts-is-Hearts
UPDATE `quest_offer_reward` SET `RewardText`='<Upon hearing the news, Bloodhilt snorts. His eyes gleam. He tips his head back and bellows a wet, cackling laugher that echoes between the blackened walls of Desolation hold and reverberates throughout the hills beyond.>$B$BSo it is done! The Butcher of Taurajo is felled at last. Cut down in the streets like a dog. Fitting.$B$BYou have done well, $N. You\'ve sowed fear into our enemies, and soon we will reap the harvest!', `VerifiedBuild`=59297 WHERE `ID`=24637; -- The Butcher of Taurajo
UPDATE `quest_offer_reward` SET `RewardText`='Excellent! You\'re my kind of $c, $N.$B$BWith your help, we will throw these invaders back into the sea.', `VerifiedBuild`=59297 WHERE `ID`=24618; -- Claim the Battle Scar
UPDATE `quest_offer_reward` SET `RewardText`='<Calder peers into the sack of extremities and licks his lips with a dry, black tongue.>$B$BOh my. This is exciting.$B$B Aren\'t you excited, $N?', `VerifiedBuild`=59297 WHERE `ID`=24619; -- Parts-is-Parts
UPDATE `quest_offer_reward` SET `RewardText`='What? He attacked you with a dozen boars? I guess quilboar have their own ideas of what \"single combat\" means.$B$BStill, the Bristleback will be left reeling after the blow you delivered. It will not be long before a new champion rises amongst them to stir up trouble... but at least this buys us some time to get these refugees relocated safely.$B$BThank you, $N. The survivors owe you a great debt.', `VerifiedBuild`=59297 WHERE `ID`=24534; -- Speaking Their Language
UPDATE `quest_offer_reward` SET `RewardText`='It\'s bad enough to have one\'s village sacked... but to spend the following night in a quilboar cage? I\'m glad you were there to help, $N.', `VerifiedBuild`=59297 WHERE `ID`=24529; -- Bad to Worse
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. But now on to the larger question:$B$BWhere is this overgrowth coming from? And why is it raging out of control?', `VerifiedBuild`=59297 WHERE `ID`=24539; -- When Plants Attack
UPDATE `quest_offer_reward` SET `RewardText`='So my sister recognized the old signals? Her hunter\'s eyes are as sharp as ever.$B$B$N, when we first set up this camp we were at the edge of this jungle. Now look at it!$B$BSomething is amiss.', `VerifiedBuild`=59297 WHERE `ID`=24515; -- Signals in the Sky
UPDATE `quest_offer_reward` SET `RewardText`='Good, good. We\'ve got to keep Honor\'s Stand isolated.$B$BAlone ... afraid ... $N, if we keep up the pressure, maybe someday they\'ll simply surrender the pass.', `VerifiedBuild`=59297 WHERE `ID`=24519; -- Stalling the Survey
UPDATE `quest_offer_reward` SET `RewardText`='Excellent, $N. It will be some time before we can assault the hold proper, but until then, we must teach them to fear the Barrens.', `VerifiedBuild`=59297 WHERE `ID`=24517; -- Put the Fear in Them
UPDATE `quest_offer_reward` SET `RewardText`='<Kilrok pages through the plans you discovered.>$B$BThis explains much, $N. No wonder our foes are so hellbent on taking the southern Barrens. It\'s at the center of their plans for the continent!$B$BBut they didn\'t account for us, did they $c? ', `VerifiedBuild`=59297 WHERE `ID`=24518; -- The Low Road
UPDATE `quest_offer_reward` SET `RewardText`='<Onatay looks over the fresh hides, nodding her head slowly.>$B$BYes $N, I can work with these. You work fast!$B$BThese hides will help us hold out for reinforcements longer. Thank you.', `VerifiedBuild`=59297 WHERE `ID`=24514; -- Raptor Scraps
UPDATE `quest_offer_reward` SET `RewardText`='So the Alliance is probing the twists and turns of the high road?$B$BEven if they were to map it out, they couldn\'t attack these hills in numbers. This is our land, $N. And they will pay dearly for presuming otherwise.', `VerifiedBuild`=59297 WHERE `ID`=24505; -- Holdout at Hunter's Hill
UPDATE `quest_offer_reward` SET `RewardText`='From up here I got the perfect view of the havoc you just caused, $N. Our lost brothers reclaimed some of their dignity, and the Alliance dogs were sent scrambling. Sharp work, my friend!$B$BIf the Alliance sleeps comfortably at night, we are not doing our job.$B$BWe will never let up.$B$BWe will never give in.', `VerifiedBuild`=59297 WHERE `ID`=24512; -- Warriors' Redemption
UPDATE `quest_offer_reward` SET `RewardText`='You have them? I\'ll take your word for it. Hearing Peake scream like one of his victims is reward enough for me.$B$BNow leave me be, $N. I do not wish to be a burden to my clan.', `VerifiedBuild`=59297 WHERE `ID`=24513; -- Eye for an Eye
UPDATE `quest_offer_reward` SET `RewardText`='This is very interesting information indeed, $N.  This sheds some light on the presence of the Twilight\'s Hammer in Silithus and will undoubtedly help us in our struggle against them.  Your efforts will be handsomely rewarded, $c.', `VerifiedBuild`=59185 WHERE `ID`=8287; -- A Terrible Purpose
UPDATE `quest_offer_reward` SET `RewardText`='Yes! These are the parts to the book!  Let\'s get started then, $N.$B$BSwap every third word with words from the second chapter... then swap every other word with words from the first chapter...  Wait, did I get that backwards?', `VerifiedBuild`=59185 WHERE `ID`=8279; -- The Twilight Lexicon
UPDATE `quest_offer_reward` SET `RewardText`='<Commander Mar\'alith\'s voice rings out from the shard.>$B$BWhether she is alive or dead, I must do what is right. She must be found. Alas, I am bound by duty to this outpost. Will you help me once more, $N?', `VerifiedBuild`=59185 WHERE `ID`=8304; -- Dearest Natalia
UPDATE `quest_offer_reward` SET `RewardText`='That was a task well performed, $N.  Your slaying of the Twilight geolords must have dealt a grievous blow to the cult.  Let us hope their plans are slowed...', `VerifiedBuild`=59185 WHERE `ID`=8320; -- Twilight Geolords
UPDATE `quest_offer_reward` SET `RewardText`='Impressive, $c... most impressive!  If Stinglasher is indeed one of their strongest creatures, the study of the beast will prove to be quite valuable in time.  It\'s now my charge to make sure we defend ourselves long enough to take advantage of it.$B$BPlease accept this coin bounty as a token of the entire camp\'s thanks, $N.  Well done.', `VerifiedBuild`=59297 WHERE `ID`=25369; -- Stinglasher
UPDATE `quest_offer_reward` SET `RewardText`='As promised, you have your choice, $N. The muisek of the creatures has been forever sealed into the power of these weapons.$B$BYou may now wield their energy as your own. Use it well.', `VerifiedBuild`=59297 WHERE `ID`=25391; -- Weapons of Spirit
UPDATE `quest_offer_reward` SET `RewardText`='Just imagine the possibilities of what we now possess, $N. Along with the materials that you have collected, I will be able to forever trap the muisek of these creatures into whatever I wish.', `VerifiedBuild`=59297 WHERE `ID`=25346; -- Mountain Giant Muisek
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. Now the spiritual powers of the faerie dragon will be available to us.$B$BI hope you willing to perform another task for me.', `VerifiedBuild`=59297 WHERE `ID`=25345; -- Faerie Dragon Muisek
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. This is my first time working with treant muisek...', `VerifiedBuild`=59297 WHERE `ID`=25338; -- Treant Muisek
UPDATE `quest_offer_reward` SET `RewardText`='Excellent, excellent!  These are going to work out incredibly well - I can already tell that they\'re going to be much harder when properly cured.$B$BThanks again for your aid, $N.  Here - please take one of my latest creations.', `VerifiedBuild`=59297 WHERE `ID`=25453; -- Improved Quality
UPDATE `quest_offer_reward` SET `RewardText`='This is an incredible find!  I believe this is the finest yeti hide specimen I have ever seen!$B$BIndeed, this is certainly worthy of an appropriate bounty.  I normally don\'t pay that much for a single hide, but I\'m confident I can make something special from it.  Thanks for thinking of me on this, $N!', `VerifiedBuild`=59297 WHERE `ID`=25454; -- Perfect Yeti Hide
UPDATE `quest_offer_reward` SET `RewardText`='Scrumdillyriffic!  These cores will keep me working for some time.  Add to that the benefit of there now being fewer elementals along the coast, and I might no longer cry myself to sleep at the prospect of having set up shop in perhaps the worst place imaginable!$B$BThank you, $N, for your efforts on my behalf.  While it certainly straps me financially to do this, allow me to show you some gratitude you may understand and appreciate... loot!', `VerifiedBuild`=59297 WHERE `ID`=25466; -- Even More Fuel for the Zapping
UPDATE `quest_offer_reward` SET `RewardText`='Splendifimous!  Not only am I glad to see that you\'ve returned with the residue, but also with all your major appendages intact!  That is, well, there was never any danger in using the Ultra-Shrinker, now was there!$B$BI do appreciate your effort on my behalf, $N.  Truly, you are a friend to goblins everywhere.  Accept this as a token of my appreciation!', `VerifiedBuild`=59297 WHERE `ID`=25465; -- Still With The Zapped Giants
UPDATE `quest_offer_reward` SET `RewardText`='As my master told me...$B$BUpon a violent death, the muisek of a creature may escape and seek revenge. Shrinking the creatures, as you did, $N, prevents the muisek from escaping. Now we may use it as we please!', `VerifiedBuild`=59297 WHERE `ID`=25336; -- Testing the Vessel
UPDATE `quest_offer_reward` SET `RewardText`='You have proven yourself to be a trustworthy and dependable ally, $N. ', `VerifiedBuild`=59297 WHERE `ID`=25209; -- The Gordunni Threat
UPDATE `quest_offer_reward` SET `RewardText`='Now I know that Edana is truly dead. This heart, I will keep it in memory of what you did here for me, $N. Thank you.', `VerifiedBuild`=59297 WHERE `ID`=25340; -- Dark Heart
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. You have put an old tauren\'s mind at peace.', `VerifiedBuild`=59297 WHERE `ID`=25339; -- Vengeance on the Northspring
UPDATE `quest_offer_reward` SET `RewardText`='Well, my entire operation\'s nearly been ruined. But you came through in the clinch, $N.$B$BIt could\'ve been worse! I gotta hand it to you.', `VerifiedBuild`=59297 WHERE `ID`=28368; -- Fire in the Hole!
UPDATE `quest_offer_reward` SET `RewardText`='This will do nicely, $N.', `VerifiedBuild`=59297 WHERE `ID`=28119; -- Purity From Corruption
UPDATE `quest_offer_reward` SET `RewardText`='Good, $N! With their numbers weakened, we can soon begin our assault on their forces deep within Shadow Hold.', `VerifiedBuild`=59297 WHERE `ID`=28121; -- Forces of Jaedenar
UPDATE `quest_offer_reward` SET `RewardText`='<Krog listens to your report.>$B$BI\'m impressed, $N. I would\'ve thought that the Grimtotem criminals would\'ve been more difficult to locate. The Alliance are truly incompetent.$B$BIn truth, I just sought to answer the death of one of my men, but this situation has been more fortunate than expected. If the Grimtotem choose to retaliate, it will likely be against the Alliance. Perhaps we will soon have the manpower to drive the scum from these shores once and for all.', `VerifiedBuild`=59297 WHERE `ID`=27297; -- Justice Dispensed
UPDATE `quest_offer_reward` SET `RewardText`='I commend you, $N.  This was not an easy mission.  But the documents you gained are valued greatly by our superiors.', `VerifiedBuild`=59297 WHERE `ID`=1202; -- The Theramore Docks
UPDATE `quest_offer_reward` SET `RewardText`='<Brogg listens as you recount your experience at the entrance to Onyxia\'s lair.>$B$BBrogg know Onyxia dead. Brogg know her brood still there. Brogg not let them forget the Stonemaul.$B$BBrogg is grateful for your help, $N, and he will never forget what you have done for him. Brogg will never give up his quest to bring Stonemaul back where they belong.', `VerifiedBuild`=59297 WHERE `ID`=27411; -- Challenge to the Black Flight
UPDATE `quest_offer_reward` SET `RewardText`='You have Brogg\'s thanks, $N. Once Brogg adds their magic to the totem, it will be able to redeem the spirits of Brogg\'s fallen friends.', `VerifiedBuild`=59297 WHERE `ID`=27409; -- The Essence of Enmity
UPDATE `quest_offer_reward` SET `RewardText`='You have Brogg\'s thanks, $N. Brogg has big plans for clan banner.', `VerifiedBuild`=59297 WHERE `ID`=27408; -- Banner of the Stonemaul
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $N.  Our agent, Marg Nighteye, was stationed outside Theramore.  He was charged to spy on the city.  $B$BThis is his latest report, and it may be his last -- from your testimony, I fear that Marg met his end in the swamp...', `VerifiedBuild`=59297 WHERE `ID`=27244; -- The Lost Report
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N! As soon as Ithania has had time to rest and my preparations are complete, we\'ll depart this sodden wasteland and head back to civilization.', `VerifiedBuild`=59297 WHERE `ID`=9437; -- Twilight of the Dawn Runner
UPDATE `quest_offer_reward` SET `RewardText`='It worked?$B$B<Mordant clears his throat.>$B$BI mean... it worked! Jarl and I are in your debt, $N. Now the only remaining problem is my friend\'s taste in furniture, and I\'m afraid that won\'t be solved as easily.', `VerifiedBuild`=59297 WHERE `ID`=27190; -- Cleansing Witch Hill
UPDATE `quest_offer_reward` SET `RewardText`='<Mordant produces a small sheet of paper and a pen, beginning to scribble down notes on your findings.>$B$BFrom your findings, the spirits in this place must amount to everyone who ever lived on this land, not just the previous occupants.$B$BSomething has been corrupting and killing them. Those who follow don\'t learn the truth until it\'s too late. We have to put an end to this, $N!', `VerifiedBuild`=59297 WHERE `ID`=27188; -- What's Haunting Witch Hill?
UPDATE `quest_offer_reward` SET `Emote2`=0, `RewardText`='There it is!  Looks like you got some of it on you too.  Kinda slimey, eh?$B$BWell, thanks a lot for all the trouble, $N.  This stuff will be worth a fortune... if I can convince the centaurs what it is!', `VerifiedBuild`=59297 WHERE `ID`=6134; -- Ghost-o-plasm Round Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59297 WHERE `ID`=5581; -- Portals of the Legion
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59297 WHERE `ID`=5501; -- Bone Collector
UPDATE `quest_offer_reward` SET `RewardText`='It is good that you have come.$b$bThere is grave danger looming here.', `VerifiedBuild`=59297 WHERE `ID`=14255; -- Ethel Rethor
UPDATE `quest_offer_reward` SET `Emote1`=0, `RewardText`='Grah... very well.$b$bI\'ll remove the bounty I had placed upon your head. Though I am sorely tempted to end your life anyway, just on principle.$b$bBe sure that you never raise my ire again, $n. Now, get out of my sight...', `VerifiedBuild`=59297 WHERE `ID`=13842; -- Dread Head Redemption
UPDATE `quest_offer_reward` SET `RewardText`='This globe... it is most disturbing.  Many of the more powerful elementals receive their power and energy through such devices.  To find one like this nearly intact is one thing - to find it so tainted is another.$B$BI will see that this globe is studied properly by the Earthen Ring.  Perhaps we can bring an end to this corruption of the elements.  Please - accept this as a fair exchange for bringing this globe to the attention of the Earthen Ring.', `VerifiedBuild`=59297 WHERE `ID`=824; -- Je'neu of the Earthen Ring
UPDATE `quest_offer_reward` SET `RewardText`='Fools!!$b$bThis Draaka woman has allowed herself to be manipulated by a demon!$b$b<Garrosh studies you for a moment.>$b$bAnd I smell its taint on you as well, $c....', `VerifiedBuild`=59297 WHERE `ID`=13841; -- All Apologies
UPDATE `quest_offer_reward` SET `RewardText`='These are perfect, $N! Thanks for helping me out!$B$BOh, and this is for your time...', `VerifiedBuild`=59297 WHERE `ID`=6441; -- Satyr Horns
UPDATE `quest_offer_reward` SET `RewardText`='You find a nasty ball of water and decide to bring it to me?  Who am I, the Earthen Ring or something?$B$BActually, that does give me an idea... perhaps you do need the Earthen Ring for this.  I mean, if it helps clear up the situation at the lake for good, then I\'m all for it.$B$BYou know who the Earthen Ring are, $N?', `VerifiedBuild`=59297 WHERE `ID`=1918; -- The Befouled Element
UPDATE `quest_offer_reward` SET `RewardText`='You found my brother!  He was captured by the Thistlefurs?  That is terrible news to hear, for although many furbolgs are noble creatures, the Thistlefurs are corrupt.$B$BThank you for rescuing my brother, $N.  I do not want to think of how they treated poor Ruul.  He will likely sleep long after this ordeal...', `VerifiedBuild`=59297 WHERE `ID`=6482; -- Freedom to Ruul
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $N.  Issuing that challenge to the Foulwealds and defeating their leader sends them a strong message:$B$BThe Horde is not to be trifled with.$B$BI don\'t believe that tribe will be giving us much trouble for a long time.', `VerifiedBuild`=59297 WHERE `ID`=6621; -- King of the Foulweald
UPDATE `quest_offer_reward` SET `RewardText`='Well, look at this! Little Tweedle has really come through this time. This stuff blew up Astranaar, you say?$b$bAs you can see, we don\'t need any help taking over Silverwind Refuge, but Tweedle always did think small.$b$bIf this stuff\'s really as good as you say, there\'s no limit to what we might do....', `VerifiedBuild`=59297 WHERE `ID`=13974; -- Tweedle's Tiny Parcel
UPDATE `quest_offer_reward` SET `RewardText`='You acquitted yourself well in battle on the field. However, I\'m afraid that Lord Magmathar has taken notice of you and the destruction that you\'ve wreaked upon his minions.$B$BYou will have to deal with him or he is sure to burn you alive, $N.', `VerifiedBuild`=59297 WHERE `ID`=13884; -- Put Out The Fire
UPDATE `quest_offer_reward` SET `RewardText`='You found them!  Thank you!  Thank you, $N!  You do not know how great a thing you have done for me.$B$BA troll without $ghis:her; charm is like an orc without $ghis:her; battle scars...$B$BWorthless.', `VerifiedBuild`=59297 WHERE `ID`=6462; -- Troll Charm
UPDATE `quest_offer_reward` SET `RewardText`='We could use more of your kind around here, $N. Thank you for your help.', `VerifiedBuild`=59297 WHERE `ID`=6442; -- Naga at the Zoram Strand
UPDATE `quest_offer_reward` SET `RewardText`='I have witnessed many naga attacks since I arrived here. It puts my mind at ease that Vorsha will no longer roam freely.$B$BWe are in your debt, $N.', `VerifiedBuild`=59297 WHERE `ID`=6641; -- Vorsha the Lasher

DELETE FROM `quest_greeting` WHERE `ID` IN (3449, 48333, 48459, 48339, 48349, 11596) AND `Type`=0 OR `ID`=206585 AND `Type`=1;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(3449, 0, 0, 0, 'Slitting throats and stabbing backs are what I do best. I don\'t suppose you want to help with some of that, do you?', 59297), -- Darsok Swiftdagger
(48333, 0, 0, 0, 'You gotta help me! Please!', 59297), -- Foreman Pikwik
(48459, 0, 396, 0, 'It\'s wonderful to see this forest grow and flourish.$B$BEvery little bit we purify brings me so much joy.', 59297), -- Tender Puregrove
(48339, 0, 1, 0, 'Greetings, $c. Have you come to cleanse the forest?', 59297), -- Elessa Starbreeze
(48349, 0, 1, 0, 'There is a different satisfaction in hunting demons than in hunting noble beasts. Not everyone can appreciate it.', 59297), -- Hurak Wildhorn
(11596, 0, 1, 0, 'My business plan never accounted for housing giant kodos... maybe I should have gone into the underwater basket weaving business instead.', 59297), -- Smeed Scrabblescrew
(206585, 1, 0, 0, '<A voice bellows from inside the wooden totem>$B$BYou stand before the mighty Ruumbo!', 59297); -- Totem of Ruumbo

UPDATE `quest_greeting` SET `Greeting`='The land, the water, and the sky are all as one. It is your eyes that deceive you with such separation. The Earthmother is all those things and more.', `VerifiedBuild`=59297 WHERE `ID`=3338 AND `Type`=0; -- Sergra Darkthorn
UPDATE `quest_greeting` SET `GreetEmoteType`=1, `VerifiedBuild`=59297 WHERE `ID`=4792 AND `Type`=0; -- "Swamp Eye" Jarl

DELETE FROM `quest_details` WHERE `ID` IN (28856 /*The Sands of Silithus*/, 13850 /*Toxic Tolerance*/, 13906 /*They Grow Up So Fast*/, 13887 /*Venomhide Eggs*/, 648 /*Rescue OOX-17/TN!*/, 28161 /*Spread the Word*/, 27330 /*Invoking the Serpent*/, 27358 /*The Captive Bride*/, 27328 /*Grimtotem Chiefs: The Chief of Chiefs*/, 27324 /*Grimtotem Chiefs: Grundig Darkcloud*/, 27321 /*The Writ of History*/, 27326 /*The Drums of War*/, 27317 /*The Rattle of Bones*/, 28284 /*What's that Rattle?*/, 27319 /*Grimtotem Chiefs: Elder Stormhoof*/, 27315 /*Grimtotem Chiefs: Isha Gloomaxe*/, 27313 /*Darkcloud Grimtotem*/, 27311 /*No Weapons For You!*/, 27276 /*Together Again*/, 25874 /*Horn of the Traitor*/, 25872 /*The Brave and the Bold*/, 25870 /*Grimtotem in the Post*/, 25836 /*Free Freewind Post*/, 25826 /*Deliver the Goods*/, 25814 /*Go Blow that Horn*/, 25799 /*Defend the Drill*/, 25797 /*Eminent Domain*/, 25791 /*Back to Riznek*/, 25779 /*Fake Gold for Black Gold*/, 25775 /*Fool's Gold*/, 25757 /*Get Koalbeard!*/, 25628 /*Two-Tusk Takedown*/, 25610 /*Sunken Treasure*/, 28042 /*Special Delivery for Brivelthwerp*/, 25589 /*A Little Payback*/, 25596 /*Where's Synge?*/, 25745 /*Negotiations*/, 25586 /*Quiet the Cannons*/, 25543 /*Circle the Wagons... er, Boats*/, 25533 /*Pirate Accuracy Increasing*/, 25526 /*In the Outhouse*/, 25518 /*Bar Fight!*/, 25516 /*Down in the Deeps*/, 25505 /*Do Me a Favor?*/, 25489 /*Two If By Boat*/, 27062 /*Looming Threat*/, 25487 /*The Grimtotem are Coming*/, 13991 /*The Purloined Payroll*/, 25107 /*The Grand Tablet*/, 25069 /*The Secrets of Uldum*/, 25068 /*The Crumbling Past*/, 25017 /*Ancient Obstacles*/, 25020 /*Fragments of Language*/, 25019 /*Laying Claim*/, 25018 /*Andoren Will Know*/, 25014 /*Sandscraper's Treasure*/, 25001 /*Sandscraper*/, 24963 /*Maul 'Em With Kindness*/, 24957 /*Get The Centipaarty Started*/, 24955 /*Un-Chartered*/, 24905 /*Returning a Favor*/, 25103 /*Bootlegger Outpost*/, 24950 /*Captain Dreadbeard*/, 25541 /*Filling Our Pockets*/, 25534 /*Going Off-Task*/, 24949 /*Booty Duty*/, 24928 /*To The Ground!*/, 24927 /*Dead Man's Chest*/, 24947 /*Momentum*/, 24910 /*Rocket Rescue*/, 24907 /*Puddle Stomping*/, 24906 /*Seaside Salvage*/, 26134 /*Nothing Left for You Here*/, 26115 /*To Be Horde...*/, 26101 /*Might Makes Right*/, 26100 /*The General is Dead*/, 26099 /*Is This Justice?*/, 26098 /*Betrayal at the Grove*/, 26097 /*Proof of Lies*/, 26082 /*To Battlescar!*/, 26077 /*Final Delivery*/, 26076 /*Spy Infestation*/, 26075 /*The Turd Problem*/, 26074 /*Beginning of the End*/, 26073 /*All's Quiet on the Southern Front*/, 26068 /*Kobold Fury!*/, 26067 /*Jin'Zil's Blessing*/, 26066 /*Reinforcements...*/, 26062 /*Da Voodoo: Resonite Crystal*/, 26064 /*Fight On Their Stomachs*/, 26061 /*Da Voodoo: Ram Horns*/, 26060 /*Da Voodoo: Stormer Heart*/, 26063 /*The Queen and Her Court*/, 26059 /*Eyes and Ears: Malaka'jin*/, 26058 /*In Defense of Krom'gar Fortress*/, 26048 /*Spare Parts Up In Here!*/, 26046 /*Between a Rock and a Hard Place*/, 26047 /*And That's Why They Call Them Peons...*/, 26045 /*I Got Your Parts Right Here...*/, 26044 /*Where Are the Parts?*/, 26028 /*Mr. D's Wild Ride*/, 26020 /*Report to Bombgutz*/, 26011 /*Enemy of the Horde: Marshal Paltrow*/, 26026 /*Dream of a Better Tomorrow*/, 26010 /*Ashes to Ashes*/, 26004 /*Krom'gar Fortress*/, 26002 /*Alliance Attack Plans*/, 26003 /*Lessons from the Lost Isles*/, 26001 /*The Missing Blastgineer*/, 25999 /*Barrier to Entry*/, 25292 /*Next of Kin*/, 24747 /*Sabotage!*/, 24685 /*Dwarf Fortress*/, 24633 /*Mahka's Plea*/, 24608 /*Mangletooth*/, 24603 /*Don't Stop Bereavin'*/, 24621 /*Smarts-is-Smarts*/, 24632 /*Tauren Vengeance*/, 24637 /*The Butcher of Taurajo*/, 24667 /*Firestone Point*/, 24620 /*Hearts-is-Hearts*/, 24634 /*Intelligence Warfare*/, 24618 /*Claim the Battle Scar*/, 24807 /*Winnoa Pineforest*/, 24619 /*Parts-is-Parts*/, 24654 /*Silithissues*/, 24591 /*Changing of the Gar'dul*/, 24577 /*Desolation Hold Inspection*/, 24573 /*Honoring the Dead*/, 24572 /*Taking Back Taurajo*/, 24569 /*Siegebreaker*/, 24552 /*Lion's Pride*/, 24546 /*A Line in the Dirt*/, 24543 /*A Family Divided*/, 24534 /*Speaking Their Language*/, 24542 /*A Curious Bloom*/, 24519 /*Stalling the Survey*/, 24518 /*The Low Road*/, 24514 /*Raptor Scraps*/, 24515 /*Signals in the Sky*/, 24513 /*Eye for an Eye*/, 24512 /*Warriors' Redemption*/, 25284 /*Feeding the Fear*/, 24505 /*Holdout at Hunter's Hill*/, 24504 /*Clear the High Road*/, 28296 /*Meetup with the Caravan*/, 9416 /*Report to General Kirika*/, 25487 /*The Grimtotem are Coming*/, 25383 /*Ysondre's Farewell*/, 25391 /*Weapons of Spirit*/, 25369 /*Stinglasher*/, 25367 /*Zukk'ash Infestation*/, 25362 /*A Grim Discovery*/, 25346 /*Mountain Giant Muisek*/, 25645 /*Return to Sage Palerunner*/, 25366 /*The Battle Plans*/, 25361 /*A New Cloak's Sheen*/, 25345 /*Faerie Dragon Muisek*/, 25375 /*Taming The Tamers*/, 25378 /*Ysondre's Call*/, 25374 /*Sasquatch Sighting*/, 25365 /*Woodpaw Investigation*/, 25364 /*Alpha Strike*/, 25643 /*The Darkmist Ruins*/, 27132 /*The Highborne*/, 27130 /*Saving Warpwood*/, 25363 /*War on the Woodpaw*/, 25356 /*To the Summit*/, 25349 /*Twisted Sisters*/, 25373 /*The Hilltop Threat*/, 25338 /*Treant Muisek*/, 25387 /*To Camp Mojache*/, 25329 /*Might of the Stonemaul*/, 25641 /*The Flow of Muisek*/, 25454 /*Perfect Yeti Hide*/, 25453 /*Improved Quality*/, 25344 /*Ogre Abduction*/, 25337 /*Hippogryph Muisek*/, 25252 /*Rulers of Dire Maul*/, 25342 /*Talk to Swar'jan*/, 25452 /*The Mark of Quality*/, 25336 /*Testing the Vessel*/, 27134 /*Ogre in the Field*/, 25341 /*The Gordunni Orb*/, 25209 /*The Gordunni Threat*/, 25386 /*To Stonemaul Hold*/, 25250 /*Sealing the Dream*/, 25241 /*The Land, Corrupted*/, 25237 /*Tears of Stone*/, 25230 /*More Than Illness*/, 25210 /*Signs of Change*/, 25340 /*Dark Heart*/, 25339 /*Vengeance on the Northspring*/, 28373 /*Timbermaw Hold*/, 28368 /*Fire in the Hole!*/, 28340 /*A Bomb Deal*/, 28335 /*Turn It Off! Turn It Off!*/, 28380 /*Pikwik in Peril*/, 28339 /*Is Your Oil Running?*/, 28336 /*Slap and Cap*/, 28370 /*Wisp-napping*/, 28357 /*Take it to the Tree*/, 28334 /*A Flare Fight*/, 28333 /*It's Time to Oil Up*/, 28372 /*Back to Business*/, 27297 /*Justice Dispensed*/, 27296 /*Raze Direhorn Post!*/, 27295 /*Seek Out Tabetha*/, 27293 /*The Grimtotem Plot*/, 27294 /*More than Coincidence*/, 27292 /*Return to Krog*/, 27418 /*Challenge Overlord Mok'Morokk*/, 7490 /*Victory for the Horde*/, 27415 /*The Brood of Onyxia*/, 27417 /*The Brood of Onyxia*/, 27416 /*The Brood of Onyxia*/, 27258 /*The Black Shield*/, 27261 /*Questioning Reethe*/, 1202 /*The Theramore Docks*/, 1168 /*Army of the Black Dragon*/, 27257 /*The Black Shield*/, 27244 /*The Lost Report*/, 27256 /*The Black Shield*/, 27306 /*Talk to Ogron*/, 27255 /*The Black Shield*/, 27414 /*Identifying the Brood*/, 27182 /*The Hermit of Witch Hill*/, 27229 /*SMASH BROODQUEEN*/, 27254 /*The Black Shield*/, 14217 /*Satyrical Offerings*/, 14344 /*Jugkar's Undoing*/, 14346 /*Cleansing Our Crevasse*/, 14343 /*Maurin's Concoction*/, 14342 /*Infernal Encroachment*/, 14341 /*Smeed's Harnesses*/, 5501 /*Bone Collector*/, 26016 /*Orders from Base Camp*/, 14227 /*Putting Their Heads Together*/, 14232 /*Ears Are Burning*/, 14225 /*You'll Know It When You See It*/, 14223 /*Peace of Mind*/, 14255 /*Ethel Rethor*/, 14217 /*Satyrical Offerings*/, 14198 /*Rider on the Storm*/, 14196 /*Firestarter*/, 14195 /*All Becoming Clearer*/, 14360 /*Nothing a Couple of Melons Won't Fix*/, 14213 /*Ten Pounds of Flesh*/, 14219 /*To the Hilt!*/, 14191 /*Furien's Footsteps*/, 14189 /*Translation*/, 14188 /*Avenge Furien!*/, 14184 /*My Time Has Passed*/, 13842 /*Dread Head Redemption*/, 25999 /*Barrier to Entry*/, 6441 /*Satyr Horns*/, 13806 /*Demon Duty*/, 24 /*Shadumbra's Head*/, 13962 /*Stalemate*/, 6621 /*King of the Foulweald*/, 23 /*Ursangous's Paw*/, 13983 /*Building Your Own Coffin*/, 13980 /*They're Out There!*/, 1918 /*The Befouled Element*/, 26416 /*Well, Come to the Jungle*/, 13977 /*Mass Production*/, 13967 /*Thinning the... Herd?*/, 25945 /*We're Here to Do One Thing, Maybe Two...*/, 13888 /*Vortex*/, 13974 /*Tweedle's Tiny Parcel*/, 13879 /*Thunder Peak*/, 13958 /*Condition Critical!*/, 13947 /*Blastranaar!*/, 13944 /*Small Stature, Short Fuse*/, 13943 /*Breathing Room*/, 13942 /*Set Us Up the Bomb*/, 13936 /*Tweedle's Dumb*/, 13923 /*To Hellscream's Watch*/, 13920 /*Before You Go...*/, 13901 /*Deep Despair*/, 26894 /*Blackfathom Deeps*/, 13890 /*Keep the Fires Burning*/, 13883 /*Lousy Pieces of Ship*/, 26890 /*The Essence of Aku'Mai*/, 13873 /*Sheelah's Last Wish*/, 13871 /*Security!*/, 13870 /*As Good as it Gets*/, 13865 /*Wet Work*/, 13815 /*Making Stumps*/, 13841 /*All Apologies*/, 6544 /*Torek's Assault*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(28856, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Sands of Silithus
(13850, 274, 0, 0, 0, 0, 0, 0, 0, 59069), -- Toxic Tolerance
(13906, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- They Grow Up So Fast
(13887, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- Venomhide Eggs
(648, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Rescue OOX-17/TN!
(28161, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Spread the Word
(27330, 273, 274, 25, 0, 0, 0, 0, 0, 59297), -- Invoking the Serpent
(27358, 5, 1, 273, 0, 0, 0, 0, 0, 59297), -- The Captive Bride
(27328, 1, 274, 0, 0, 0, 0, 0, 0, 59297), -- Grimtotem Chiefs: The Chief of Chiefs
(27324, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Grimtotem Chiefs: Grundig Darkcloud
(27321, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Writ of History
(27326, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Drums of War
(27317, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Rattle of Bones
(28284, 6, 0, 0, 0, 0, 0, 0, 0, 59297), -- What's that Rattle?
(27319, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Grimtotem Chiefs: Elder Stormhoof
(27315, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Grimtotem Chiefs: Isha Gloomaxe
(27313, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Darkcloud Grimtotem
(27311, 6, 0, 0, 0, 0, 0, 0, 0, 59297), -- No Weapons For You!
(27276, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Together Again
(25874, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Horn of the Traitor
(25872, 5, 274, 0, 0, 1000, 0, 0, 0, 59297), -- The Brave and the Bold
(25870, 5, 0, 0, 0, 0, 0, 0, 0, 59297), -- Grimtotem in the Post
(25836, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Free Freewind Post
(25826, 25, 0, 0, 0, 0, 0, 0, 0, 59297), -- Deliver the Goods
(25814, 1, 25, 0, 0, 0, 0, 0, 0, 59297), -- Go Blow that Horn
(25799, 5, 1, 0, 0, 0, 0, 0, 0, 59297), -- Defend the Drill
(25797, 15, 25, 0, 0, 0, 0, 0, 0, 59297), -- Eminent Domain
(25791, 36, 0, 0, 0, 0, 0, 0, 0, 59297), -- Back to Riznek
(25779, 25, 11, 0, 0, 0, 0, 0, 0, 59297), -- Fake Gold for Black Gold
(25775, 274, 6, 25, 0, 0, 0, 0, 0, 59297), -- Fool's Gold
(25757, 5, 6, 274, 0, 0, 0, 0, 0, 59297), -- Get Koalbeard!
(25628, 1, 25, 0, 0, 0, 0, 0, 0, 59297), -- Two-Tusk Takedown
(25610, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Sunken Treasure
(28042, 1, 273, 25, 0, 0, 0, 0, 0, 59297), -- Special Delivery for Brivelthwerp
(25589, 6, 0, 0, 0, 0, 0, 0, 0, 59297), -- A Little Payback
(25596, 6, 1, 5, 0, 0, 0, 0, 0, 59297), -- Where's Synge?
(25745, 4, 1, 25, 0, 0, 0, 0, 0, 59297), -- Negotiations
(25586, 5, 1, 25, 0, 0, 0, 0, 0, 59297), -- Quiet the Cannons
(25543, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Circle the Wagons... er, Boats
(25533, 5, 25, 0, 0, 0, 0, 0, 0, 59297), -- Pirate Accuracy Increasing
(25526, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- In the Outhouse
(25518, 15, 0, 0, 0, 0, 0, 0, 0, 59297), -- Bar Fight!
(25516, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Down in the Deeps
(25505, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Do Me a Favor?
(25489, 6, 0, 0, 0, 0, 0, 0, 0, 59297), -- Two If By Boat
(27062, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Looming Threat
(25487, 15, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Grimtotem are Coming
(13991, 273, 1, 0, 0, 0, 900, 0, 0, 59297), -- The Purloined Payroll
(25107, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Grand Tablet
(25069, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Secrets of Uldum
(25068, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Crumbling Past
(25017, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Ancient Obstacles
(25020, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Fragments of Language
(25019, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Laying Claim
(25018, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Andoren Will Know
(25014, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Sandscraper's Treasure
(25001, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Sandscraper
(24963, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Maul 'Em With Kindness
(24957, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Get The Centipaarty Started
(24955, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Un-Chartered
(24905, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Returning a Favor
(25103, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Bootlegger Outpost
(24950, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Captain Dreadbeard
(25541, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Filling Our Pockets
(25534, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Going Off-Task
(24949, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Booty Duty
(24928, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- To The Ground!
(24927, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Dead Man's Chest
(24947, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Momentum
(24910, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Rocket Rescue
(24907, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Puddle Stomping
(24906, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Seaside Salvage
(26134, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Nothing Left for You Here
(26115, 5, 0, 0, 0, 0, 0, 0, 0, 59297), -- To Be Horde...
(26101, 273, 1, 0, 0, 0, 0, 0, 0, 59297), -- Might Makes Right
(26100, 1, 18, 20, 0, 0, 3000, 3000, 0, 59297), -- The General is Dead
(26099, 1, 18, 1, 0, 0, 0, 0, 0, 59297), -- Is This Justice?
(26098, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Betrayal at the Grove
(26097, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Proof of Lies
(26082, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- To Battlescar!
(26077, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Final Delivery
(26076, 396, 5, 1, 0, 0, 0, 0, 0, 59297), -- Spy Infestation
(26075, 24, 1, 1, 4, 0, 0, 0, 0, 59297), -- The Turd Problem
(26074, 1, 1, 66, 0, 0, 0, 0, 0, 59297), -- Beginning of the End
(26073, 1, 2, 0, 0, 0, 0, 0, 0, 59297), -- All's Quiet on the Southern Front
(26068, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Kobold Fury!
(26067, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Jin'Zil's Blessing
(26066, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Reinforcements...
(26062, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Da Voodoo: Resonite Crystal
(26064, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Fight On Their Stomachs
(26061, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Da Voodoo: Ram Horns
(26060, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Da Voodoo: Stormer Heart
(26063, 1, 1, 6, 5, 0, 0, 0, 0, 59297), -- The Queen and Her Court
(26059, 374, 1, 0, 0, 0, 0, 0, 0, 59297), -- Eyes and Ears: Malaka'jin
(26058, 5, 1, 1, 0, 0, 0, 0, 0, 59297), -- In Defense of Krom'gar Fortress
(26048, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Spare Parts Up In Here!
(26046, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Between a Rock and a Hard Place
(26047, 5, 1, 1, 0, 0, 0, 0, 0, 59297), -- And That's Why They Call Them Peons...
(26045, 1, 1, 273, 0, 0, 0, 0, 0, 59297), -- I Got Your Parts Right Here...
(26044, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Where Are the Parts?
(26028, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Mr. D's Wild Ride
(26020, 273, 1, 25, 0, 0, 0, 0, 0, 59297), -- Report to Bombgutz
(26011, 1, 1, 5, 0, 0, 0, 0, 0, 59297), -- Enemy of the Horde: Marshal Paltrow
(26026, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Dream of a Better Tomorrow
(26010, 1, 1, 5, 0, 0, 0, 0, 0, 59297), -- Ashes to Ashes
(26004, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Krom'gar Fortress
(26002, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Alliance Attack Plans
(26003, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Lessons from the Lost Isles
(26001, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Missing Blastgineer
(25999, 5, 1, 25, 0, 0, 0, 0, 0, 59297), -- Barrier to Entry
(25292, 1, 274, 0, 0, 0, 0, 0, 0, 59297), -- Next of Kin
(24747, 11, 1, 273, 0, 0, 0, 0, 0, 59297), -- Sabotage!
(24685, 5, 1, 0, 0, 0, 0, 0, 0, 59297), -- Dwarf Fortress
(24633, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Mahka's Plea
(24608, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Mangletooth
(24603, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Don't Stop Bereavin'
(24621, 5, 1, 0, 0, 0, 0, 0, 0, 59297), -- Smarts-is-Smarts
(24632, 1, 273, 0, 0, 0, 0, 0, 0, 59297), -- Tauren Vengeance
(24637, 5, 15, 0, 0, 0, 0, 0, 0, 59297), -- The Butcher of Taurajo
(24667, 1, 273, 0, 0, 0, 0, 0, 0, 59297), -- Firestone Point
(24620, 11, 1, 0, 0, 0, 0, 0, 0, 59297), -- Hearts-is-Hearts
(24634, 1, 5, 0, 0, 0, 0, 0, 0, 59297), -- Intelligence Warfare
(24618, 25, 5, 0, 0, 0, 0, 0, 0, 59297), -- Claim the Battle Scar
(24807, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Winnoa Pineforest
(24619, 6, 1, 0, 0, 0, 0, 0, 0, 59297), -- Parts-is-Parts
(24654, 5, 274, 1, 0, 0, 0, 0, 0, 59297), -- Silithissues
(24591, 274, 1, 0, 0, 0, 0, 0, 0, 59297), -- Changing of the Gar'dul
(24577, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Desolation Hold Inspection
(24573, 1, 274, 0, 0, 0, 0, 0, 0, 59297), -- Honoring the Dead
(24572, 1, 15, 25, 0, 0, 0, 0, 0, 59297), -- Taking Back Taurajo
(24569, 273, 1, 66, 0, 0, 0, 0, 0, 59297), -- Siegebreaker
(24552, 1, 6, 0, 0, 0, 0, 0, 0, 59297), -- Lion's Pride
(24546, 5, 1, 25, 0, 0, 0, 0, 0, 59297), -- A Line in the Dirt
(24543, 1, 5, 0, 0, 0, 0, 0, 0, 59297), -- A Family Divided
(24534, 1, 25, 5, 0, 0, 0, 0, 0, 59297), -- Speaking Their Language
(24542, 1, 5, 273, 0, 0, 0, 0, 0, 59297), -- A Curious Bloom
(24519, 6, 1, 0, 0, 0, 0, 0, 0, 59297), -- Stalling the Survey
(24518, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Low Road
(24514, 1, 273, 0, 0, 0, 0, 0, 0, 59297), -- Raptor Scraps
(24515, 1, 6, 0, 0, 0, 0, 0, 0, 59297), -- Signals in the Sky
(24513, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Eye for an Eye
(24512, 25, 1, 274, 0, 0, 0, 0, 0, 59297), -- Warriors' Redemption
(25284, 1, 273, 0, 0, 0, 0, 0, 0, 59297), -- Feeding the Fear
(24505, 1, 273, 0, 0, 0, 0, 0, 0, 59297), -- Holdout at Hunter's Hill
(24504, 1, 66, 0, 0, 0, 0, 0, 0, 59297), -- Clear the High Road
(28296, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Meetup with the Caravan
(9416, 25, 1, 0, 0, 0, 0, 0, 0, 59185), -- Report to General Kirika
(25383, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ysondre's Farewell
(25391, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Weapons of Spirit
(25369, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Stinglasher
(25367, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Zukk'ash Infestation
(25362, 5, 1, 1, 5, 0, 0, 0, 0, 59297), -- A Grim Discovery
(25346, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Mountain Giant Muisek
(25645, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Return to Sage Palerunner
(25366, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Battle Plans
(25361, 2, 1, 1, 0, 0, 0, 0, 0, 59297), -- A New Cloak's Sheen
(25345, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Faerie Dragon Muisek
(25375, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Taming The Tamers
(25378, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ysondre's Call
(25374, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Sasquatch Sighting
(25365, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Woodpaw Investigation
(25364, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Alpha Strike
(25643, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Darkmist Ruins
(27132, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Highborne
(27130, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Saving Warpwood
(25363, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- War on the Woodpaw
(25356, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- To the Summit
(25349, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Twisted Sisters
(25373, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Hilltop Threat
(25338, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Treant Muisek
(25387, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- To Camp Mojache
(25329, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Might of the Stonemaul
(25641, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Flow of Muisek
(25454, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Perfect Yeti Hide
(25453, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Improved Quality
(25344, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ogre Abduction
(25337, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Hippogryph Muisek
(25252, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Rulers of Dire Maul
(25342, 5, 0, 0, 0, 0, 0, 0, 0, 59297), -- Talk to Swar'jan
(25452, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Mark of Quality
(25336, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Testing the Vessel
(27134, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ogre in the Field
(25341, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Gordunni Orb
(25209, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Gordunni Threat
(25386, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- To Stonemaul Hold
(25250, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Sealing the Dream
(25241, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Land, Corrupted
(25237, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Tears of Stone
(25230, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- More Than Illness
(25210, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Signs of Change
(25340, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Dark Heart
(25339, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Vengeance on the Northspring
(28373, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Timbermaw Hold
(28368, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Fire in the Hole!
(28340, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- A Bomb Deal
(28335, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Turn It Off! Turn It Off!
(28380, 25, 0, 0, 0, 0, 0, 0, 0, 59297), -- Pikwik in Peril
(28339, 5, 0, 0, 0, 0, 0, 0, 0, 59297), -- Is Your Oil Running?
(28336, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Slap and Cap
(28370, 6, 0, 0, 0, 0, 0, 0, 0, 59297), -- Wisp-napping
(28357, 274, 0, 0, 0, 0, 0, 0, 0, 59297), -- Take it to the Tree
(28334, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- A Flare Fight
(28333, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- It's Time to Oil Up
(28372, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Back to Business
(27297, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Justice Dispensed
(27296, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Raze Direhorn Post!
(27295, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Seek Out Tabetha
(27293, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- The Grimtotem Plot
(27294, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- More than Coincidence
(27292, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Return to Krog
(27418, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Challenge Overlord Mok'Morokk
(7490, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Victory for the Horde
(27415, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- The Brood of Onyxia
(27417, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- The Brood of Onyxia
(27416, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Brood of Onyxia
(27258, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Black Shield
(27261, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Questioning Reethe
(1202, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Theramore Docks
(1168, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Army of the Black Dragon
(27257, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Black Shield
(27244, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Lost Report
(27256, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Black Shield
(27306, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Talk to Ogron
(27255, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Black Shield
(27414, 1, 1, 1, 0, 0, 0, 0, 0, 59297), -- Identifying the Brood
(27182, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- The Hermit of Witch Hill
(27229, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- SMASH BROODQUEEN
(27254, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Black Shield
(14217, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Satyrical Offerings
(14344, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Jugkar's Undoing
(14346, 396, 396, 5, 1, 0, 0, 1000, 0, 59297), -- Cleansing Our Crevasse
(14343, 396, 0, 0, 0, 0, 0, 0, 0, 59297), -- Maurin's Concoction
(14342, 5, 5, 0, 0, 0, 0, 0, 0, 59297), -- Infernal Encroachment
(14341, 396, 0, 0, 0, 0, 0, 0, 0, 59297), -- Smeed's Harnesses
(5501, 5, 1, 0, 0, 0, 0, 0, 0, 59297), -- Bone Collector
(26016, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Orders from Base Camp
(14227, 396, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Putting Their Heads Together
(14232, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ears Are Burning
(14225, 396, 0, 0, 0, 0, 0, 0, 0, 59297), -- You'll Know It When You See It
(14223, 396, 396, 5, 0, 0, 500, 500, 0, 59297), -- Peace of Mind
(14255, 396, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Ethel Rethor
(14198, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Rider on the Storm
(14196, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Firestarter
(14195, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- All Becoming Clearer
(14360, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Nothing a Couple of Melons Won't Fix
(14213, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ten Pounds of Flesh
(14219, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- To the Hilt!
(14191, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Furien's Footsteps
(14189, 396, 396, 0, 0, 0, 500, 0, 0, 59297), -- Translation
(14188, 5, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Avenge Furien!
(14184, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- My Time Has Passed
(13842, 5, 396, 0, 0, 0, 500, 0, 0, 59297), -- Dread Head Redemption
(6441, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Satyr Horns
(13806, 1, 5, 1, 0, 0, 1500, 1000, 0, 59297), -- Demon Duty
(24, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Shadumbra's Head
(13962, 396, 396, 0, 0, 0, 0, 0, 0, 59297), -- Stalemate
(6621, 5, 0, 0, 0, 0, 0, 0, 0, 59297), -- King of the Foulweald
(23, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Ursangous's Paw
(13983, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Building Your Own Coffin
(13980, 396, 396, 0, 0, 0, 1000, 0, 0, 59297), -- They're Out There!
(1918, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- The Befouled Element
(26416, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Well, Come to the Jungle
(13977, 5, 396, 396, 0, 0, 1000, 1000, 0, 59297), -- Mass Production
(13967, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Thinning the... Herd?
(25945, 1, 5, 1, 15, 0, 0, 0, 0, 59297), -- We're Here to Do One Thing, Maybe Two...
(13888, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Vortex
(13974, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Tweedle's Tiny Parcel
(13879, 396, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Thunder Peak
(13958, 396, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Condition Critical!
(13947, 6, 396, 5, 0, 0, 1000, 1000, 0, 59297), -- Blastranaar!
(13944, 5, 5, 5, 0, 0, 1000, 1000, 0, 59297), -- Small Stature, Short Fuse
(13943, 396, 5, 0, 0, 0, 1000, 0, 0, 59297), -- Breathing Room
(13942, 5, 396, 5, 0, 0, 1000, 1000, 0, 59297), -- Set Us Up the Bomb
(13936, 5, 5, 0, 0, 0, 1000, 0, 0, 59297), -- Tweedle's Dumb
(13923, 396, 396, 0, 0, 0, 500, 0, 0, 59297), -- To Hellscream's Watch
(13920, 1, 0, 0, 0, 0, 0, 0, 0, 59297), -- Before You Go...
(13901, 396, 5, 0, 0, 0, 500, 0, 0, 59297), -- Deep Despair
(26894, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- Blackfathom Deeps
(13890, 396, 397, 0, 0, 0, 500, 0, 0, 59297), -- Keep the Fires Burning
(13883, 5, 396, 0, 0, 0, 1000, 0, 0, 59297), -- Lousy Pieces of Ship
(26890, 1, 1, 0, 0, 0, 0, 0, 0, 59297), -- The Essence of Aku'Mai
(13873, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- Sheelah's Last Wish
(13871, 5, 5, 5, 0, 0, 500, 500, 0, 59297), -- Security!
(13870, 1, 1, 0, 0, 0, 1000, 0, 0, 59297), -- As Good as it Gets
(13865, 1, 1, 0, 0, 0, 1000, 0, 0, 59297), -- Wet Work
(13815, 1, 1, 0, 0, 0, 1000, 0, 0, 59297), -- Making Stumps
(13841, 0, 0, 0, 0, 0, 0, 0, 0, 59297), -- All Apologies
(6544, 5, 1, 0, 0, 0, 0, 0, 0, 59297); -- Torek's Assault

UPDATE `quest_details` SET `Emote1`=5, `Emote3`=153, `EmoteDelay2`=500, `EmoteDelay3`=500, `VerifiedBuild`=59297 WHERE `ID`=25; -- Simmer Down Now
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=59297 WHERE `ID`=6482; -- Freedom to Ruul
UPDATE `quest_details` SET `Emote1`=5, `VerifiedBuild`=59297 WHERE `ID`=216; -- Between a Rock and a Thistlefur
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=59297 WHERE `ID`=6641; -- Vorsha the Lasher
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=59297 WHERE `ID`=6442; -- Naga at the Zoram Strand

DELETE FROM `quest_request_items` WHERE `ID` IN (24723 /*The Western Pylon*/, 24722 /*The Northern Pylon*/, 24707 /*The Ballad of Maximillian*/, 24705 /*Town Dwellers Were Made to be Saved*/, 25487 /*The Grimtotem are Coming*/, 29111 /*Mor'shan Caravan Delivery*/, 29109 /*Mor'shan Caravan Pick-Up*/, 29094 /*The Short Way Home*/, 25032 /*Secrets in the Oasis*/, 26068 /*Kobold Fury!*/, 26067 /*Jin'Zil's Blessing*/, 26066 /*Reinforcements...*/, 26064 /*Fight On Their Stomachs*/, 26063 /*The Queen and Her Court*/, 26062 /*Da Voodoo: Resonite Crystal*/, 26061 /*Da Voodoo: Ram Horns*/, 26060 /*Da Voodoo: Stormer Heart*/, 26048 /*Spare Parts Up In Here!*/, 26047 /*And That's Why They Call Them Peons...*/, 26046 /*Between a Rock and a Hard Place*/, 26045 /*I Got Your Parts Right Here...*/, 26026 /*Dream of a Better Tomorrow*/, 26011 /*Enemy of the Horde: Marshal Paltrow*/, 26004 /*Krom'gar Fortress*/, 26002 /*Alliance Attack Plans*/, 25999 /*Barrier to Entry*/, 14217 /*Satyrical Offerings*/, 13944 /*Small Stature, Short Fuse*/, 13621 /*Gorat's Vengeance*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24723, 0, 0, 0, 0, 'Something to report, $N?', 59069), -- The Western Pylon
(24722, 0, 0, 0, 0, 'Yes, $N?', 59069), -- The Northern Pylon
(24707, 0, 0, 0, 0, 'We should attempt the slaying one more time, I think.', 59069), -- The Ballad of Maximillian
(24705, 0, 0, 0, 0, 'The cries of distressed damsels are still carried by the wind into my ears.  We must find them, and quickly!', 59069), -- Town Dwellers Were Made to be Saved
(25487, 0, 6, 0, 0, 'Thank you, friend, but could you help us with a few more of the Grimtotem?', 59297), -- The Grimtotem are Coming
(29111, 0, 0, 0, 0, 'The Burning Blade will not be happy to find their spoils gone.', 59297), -- Mor'shan Caravan Delivery
(29109, 0, 0, 0, 0, 'Mor\'shan Ramparts is in dire need of supplies. Speak to Rocco Whipshank at the northern-most point of the Crossroads. He should be waiting for you by the side of the road.', 59297), -- Mor'shan Caravan Pick-Up
(29094, 0, 0, 0, 0, 'I designed the Silver Bullet X-831 myself. Isn\'t she a beauty? ', 59297), -- The Short Way Home
(25032, 0, 0, 0, 0, 'Don\'t be gawkin\' here at me all day, mon. Best get goin\'.', 59069), -- Secrets in the Oasis
(26068, 0, 5, 0, 0, 'On my mark, unleash kobold hell!', 59297), -- Kobold Fury!
(26067, 0, 5, 0, 0, 'Hurry, $N!', 59297), -- Jin'Zil's Blessing
(26066, 0, 1, 0, 0, 'Do not dilly-dally, $N.', 59297), -- Reinforcements...
(26064, 5, 5, 0, 0, 'I need eggs!', 59297), -- Fight On Their Stomachs
(26063, 0, 0, 0, 0, 'Have you killed Silith for Darn?', 59297), -- The Queen and Her Court
(26062, 5, 5, 0, 0, 'I need the resonite crystals!', 59297), -- Da Voodoo: Resonite Crystal
(26061, 0, 0, 0, 0, 'I need the Stonetalon ram horns!', 59297), -- Da Voodoo: Ram Horns
(26060, 25, 25, 0, 0, 'I need the cliff stormer heart.', 59297), -- Da Voodoo: Stormer Heart
(26048, 6, 0, 0, 0, 'Get my parts?', 0), -- Spare Parts Up In Here!
(26047, 0, 6, 0, 0, 'Did you find my peons?', 59297), -- And That's Why They Call Them Peons...
(26046, 0, 25, 0, 0, 'Those elementals aren\'t going to kill themselves, buddy.', 59297), -- Between a Rock and a Hard Place
(26045, 6, 6, 0, 0, 'How\'s that part hunt going?', 59297), -- I Got Your Parts Right Here...
(26026, 1, 1, 0, 0, 'Mr. D is so sad. We need to make him happy!', 59297), -- Dream of a Better Tomorrow
(26011, 0, 6, 0, 0, 'Is Paltrow dead?', 59297), -- Enemy of the Horde: Marshal Paltrow
(26004, 6, 0, 0, 0, 'What is the meaning of this interruption? Why does this grunt stand before Overlord Krom\'gar?', 0), -- Krom'gar Fortress
(26002, 0, 0, 0, 0, 'Did you find Fuzzwhistle?', 0), -- Alliance Attack Plans
(25999, 0, 6, 0, 0, 'What do you have to report, grunt?', 59297), -- Barrier to Entry
(14217, 0, 0, 0, 0, 'The brazier silently awaits an offering.', 59297), -- Satyrical Offerings
(13944, 0, 0, 0, 0, 'What have you done, $r?', 59297), -- Small Stature, Short Fuse
(13621, 0, 0, 0, 0, 'What have you learned, $r?', 59297); -- Gorat's Vengeance

UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=351;
UPDATE `quest_request_items` SET `CompletionText`='The fabled Rattle of Bones, $N!' WHERE `ID`=27317;
UPDATE `quest_request_items` SET `CompletionText`='We need to kill more of the Grimtotem, $N.', `VerifiedBuild`=59297 WHERE `ID`=27313; -- Darkcloud Grimtotem
UPDATE `quest_request_items` SET `CompletionText`='$N? What news do you have?' WHERE `ID`=25874;
UPDATE `quest_request_items` SET `CompletionText`='$N, you gotta quiet a few more of those cannons or we don\'t stand a chance!\n', `VerifiedBuild`=59297 WHERE `ID`=25586; -- Quiet the Cannons
UPDATE `quest_request_items` SET `CompletionText`='Arnak must fall, $N, if we are to win the battle against the Grimtotem.', `VerifiedBuild`=59297 WHERE `ID`=27328; -- Grimtotem Chiefs: The Chief of Chiefs
UPDATE `quest_request_items` SET `CompletionText`='$N, we must find and kill Grundig Darkcloud.', `VerifiedBuild`=59297 WHERE `ID`=27324; -- Grimtotem Chiefs: Grundig Darkcloud
UPDATE `quest_request_items` SET `CompletionText`='How goes your search for the supplies, $N? I trust the quilboar fall under your strength easily.', `VerifiedBuild`=59297 WHERE `ID`=5041; -- Supplies for the Crossroads
UPDATE `quest_request_items` SET `CompletionText`='The quilboar will pay for this, $N. I swear it.', `VerifiedBuild`=59297 WHERE `ID`=899; -- Consumed by Hatred
UPDATE `quest_request_items` SET `CompletionText`='Cut off the head of their leader, and chaos ensues, $N. Learn this lesson well. It will aid you in the future.', `VerifiedBuild`=59297 WHERE `ID`=872; -- The Far Watch Offensive
UPDATE `quest_request_items` SET `CompletionText`='Do you have the nugget slugs, $N?  I\'ve been eyeing this Samophlange and I can\'t wait to tinker with it.', `VerifiedBuild`=59297 WHERE `ID`=29027; -- Nugget Slugs
UPDATE `quest_request_items` SET `CompletionText`='How goes your hunting, $N?', `VerifiedBuild`=59297 WHERE `ID`=855; -- Centaur Bracers
UPDATE `quest_request_items` SET `CompletionText`='Did you find Verog, $N?', `VerifiedBuild`=59297 WHERE `ID`=851; -- Verog the Dervish
UPDATE `quest_request_items` SET `CompletionText`='I\'m going to close my eyes, $N. And when I open them, I expect to see wall-to-wall treasure. Deal?', `VerifiedBuild`=59297 WHERE `ID`=14050; -- Gazlowe's Fortune
UPDATE `quest_request_items` SET `CompletionText`='You\'ve gotta have heart, $N. All you really need is heart.', `VerifiedBuild`=59297 WHERE `ID`=24620; -- Hearts-is-Hearts
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59297 WHERE `ID`=24542; -- A Curious Bloom
UPDATE `quest_request_items` SET `CompletionText`='Thank you for helping me with this grim business, $N.', `VerifiedBuild`=59297 WHERE `ID`=24525; -- Keeping the Dogs at Bay
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `CompletionText`='Hail, $c. Did Nura send you?', `VerifiedBuild`=59297 WHERE `ID`=24504; -- Clear the High Road
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=0, `VerifiedBuild`=59185 WHERE `ID`=9422; -- Scouring the Desert
UPDATE `quest_request_items` SET `CompletionText`='$N, have you yet defeated Vyral the Vile?  Do you have his signet ring?', `VerifiedBuild`=59185 WHERE `ID`=8321; -- Vyral the Vile
UPDATE `quest_request_items` SET `CompletionText`='How goes the hunt, $N?  Are you here to report your success?', `VerifiedBuild`=59297 WHERE `ID`=25367; -- Zukk'ash Infestation
UPDATE `quest_request_items` SET `CompletionText`='What\'s this, $N - you\'ve got something special for me?' WHERE `ID`=25454;
UPDATE `quest_request_items` SET `CompletionText`='Did you find the documents, $N?  They hold information vital to the stability of the Alliance and, hence, vital to the security of the Horde.', `VerifiedBuild`=59297 WHERE `ID`=1202; -- The Theramore Docks
UPDATE `quest_request_items` SET `CompletionText`='Did you find the infiltrators, $N?', `VerifiedBuild`=59297 WHERE `ID`=1201; -- Theramore Spies
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `VerifiedBuild`=59297 WHERE `ID`=5501; -- Bone Collector
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=0, `VerifiedBuild`=59297 WHERE `ID`=5581; -- Portals of the Legion
UPDATE `quest_request_items` SET `CompletionText`='Did you find the charms, $N?  Every moment the furbolgs possess those sacred items, my blood boils with rage!', `VerifiedBuild`=59297 WHERE `ID`=6462; -- Troll Charm
UPDATE `quest_request_items` SET `CompletionText`='I hope you can be quick about getting those horns, $N. I\'m heading back to Ratchet soon!', `VerifiedBuild`=59297 WHERE `ID`=6441; -- Satyr Horns
UPDATE `quest_request_items` SET `CompletionText`='Did you defeat Chief Murgut, $N?  Did you retrieve his foulweald totem?', `VerifiedBuild`=59297 WHERE `ID`=6621; -- King of the Foulweald
UPDATE `quest_request_items` SET `CompletionText`='How goes your search for the crystals, $N? Do you think they\'ll make an item we can use to stop the naga?', `VerifiedBuild`=59297 WHERE `ID`=26890; -- The Essence of Aku'Mai
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `VerifiedBuild`=59297 WHERE `ID`=13865; -- Wet Work
UPDATE `quest_request_items` SET `CompletionText`='Have you brought me the head of the enemy, $r?', `VerifiedBuild`=59297 WHERE `ID`=13842; -- Dread Head Redemption
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `CompletionText`='Those dreadlords must die soon, $N!', `VerifiedBuild`=59297 WHERE `ID`=26449; -- Never Again!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=0, `VerifiedBuild`=59297 WHERE `ID`=13815; -- Making Stumps
UPDATE `quest_request_items` SET `CompletionText`='You kill dem outrunners, $N.', `VerifiedBuild`=59297 WHERE `ID`=6503; -- Ashenvale Outrunners

DELETE FROM `creature_questender` WHERE (`id`=39605 AND `quest` IN (13842,13841)) OR (`id`=12736 AND `quest` IN (824,26894));
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(39605, 13842, 59297), -- Dread Head Redemption ended by Garrosh Hellscream
(12736, 824, 59297), -- Je'neu of the Earthen Ring ended by Je'neu Sancrea
(39605, 13841, 59297), -- All Apologies ended by Garrosh Hellscream
(12736, 26894, 59297); -- Blackfathom Deeps ended by Je'neu Sancrea
