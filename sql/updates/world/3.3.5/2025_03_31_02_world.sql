-- "The Balance of Nature" (456) - Completion Text, missing double spacing
UPDATE `quest_request_items` SET `CompletionText`="There is still work to be done, $N.  Return to me once you have thinned the nightsaber and thistle boar populations." WHERE `ID`=456;

-- "The Balance of Nature" (457) - Completion Text, missing double spacing
UPDATE `quest_request_items` SET `CompletionText`="Your task is not yet complete, $N.  Return to me once 5 mangy nightsabers and 5 thistle boars have been killed." WHERE `ID`=457;

-- "The Balance of Nature" (457) - Reward Text, missing double spacing and should have $c instead of $C
UPDATE `quest_offer_reward` SET `RewardText`="You have proven your dedication to nature well, $N.  A young $c like yourself has a promising future." WHERE `ID`=457;

-- "The Woodland Protector" (458) - Reward Text, should have $r instead of $R
UPDATE `quest_offer_reward` SET `RewardText`="I see you found me, young $r. Melithar is a wise druid to have sent you." WHERE `ID`=458;

-- "The Woodland Protector" (459) - Quest Description, fixed incorrect usage of $b.
UPDATE `quest_template` SET `QuestDescription`="Something evil is brewing in the forests of Teldrassil.  Look long the hills to where the peaceful furbolgs used to dwell.  They have deserted their homes and are amassing under the name of the Gnarlpine tribe.$b$bOnly the corruption of wicked Fel Moss could cause such a transformation.  The grells and grellkin have infested the area and are threatening the residents of Shadowglen.$b$bEngage these grells and grellkin, $N, and see if they are indeed caught under the enchantment of the wicked Fel Moss." WHERE `Id`=459;

-- "The Woodland Protector" (459) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Satisfy my suspicions, $N.  Bring to me 8 Fel Moss." WHERE `ID`=459;

-- "The Woodland Protector" (459) - Reward Text, missing double spacing
UPDATE `quest_offer_reward` SET `RewardText`="Your service to the creatures of Shadowglen is worthy of reward, $N.$b$bYou confirmed my fears, however.  If the grells have become tainted by the Fel Moss, one can only imagine what has become of the Gnarlpine tribe of furbolgs who once lived here.$b$bShould you find yourself in Dolanaar, able $C, seek out the knowledgeable druid, Athridas Bearmantle.  He shares our concern for the well being of the forest." WHERE `ID`=459;

-- "A Troubling Breeze" - Reward Text, missing double spacing
UPDATE `quest_offer_reward` SET `RewardText`="Thank the forest spirits you are here!  I knew Athridas would sense trouble and send help." WHERE `ID`=475;

-- "Gnarlpine Corruption" (476) - Reward Text, missing double spacing
UPDATE `quest_offer_reward` SET `RewardText`="By the stars!  This is quite disturbing indeed!" WHERE `ID`=476;

-- "The Relics of Wakening" (483) - Reward Text, missing double spacing and should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="You have succeeded, young $c!  Well done.  And just in time I might add." WHERE `ID`=483;

-- "Ursal the Mauler" (486) - Reward Text, missing double spacing, should have $c instead of $C and $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="$N you have proven yourself a most worthy and able $c.  A $r who follows the path of honor as sure as you do is certain to find great glory in this world.$b$bMay the forest spirits protect you wherever your travels may take you." WHERE `ID`=486;

-- "The Road to Darnassus" (487) - Reward Text, missing double spacing and should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="You have served the good people of Dolanaar and Darnassus well, brave $c.  As a member of the Sentinel force of Teldrassil I salute your efforts." WHERE `ID`=487;

-- "Zenn's Bidding" (488) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you been a busy little bee, $N?  I've been waiting for you to bring me what I need." WHERE `ID`=488;

-- "Zenn's Bidding" (488) - Reward Text, missing double spacing and should have $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="Ha ha!  Well, done indeed.$b$bWho would have ever guessed that I, Zenn Foulhoof, would have a $r to do my bidding?  Certainly not me!  But so it goes... this beloved world of ours is full of surprises.$b$bThree cheers for the naive and gullible!" WHERE `ID`=488;

-- "Seek Redemption!" (489) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="What do you have for me, $N?  A lovely snack I presume?" WHERE `ID`=489;

-- "Seek Redemption!" (489) - Reward Text, missing double spacing and should have $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, what a sweet $r!  I knew you would come in handy!" WHERE `ID`=489;

-- "Webwood Venom" (916) - Reward Text, missing double spacing
UPDATE `quest_offer_reward` SET `RewardText`="Thank you, $N.  When I return to Darnassus I will compare the venom within these sacs with the venom of other spiders.  It is my belief that it will have properties linked to the recent growth of our new world tree." WHERE `ID`=916;

-- "Webwood Egg" (917) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you been inside the Shadowthread Cave, $N?  Did you find a spider egg?" WHERE `ID`=917;

-- "Webwood Egg" (917) - Reward Text, missing double spacing
UPDATE `quest_offer_reward` SET `RewardText`="Ah, very good.  I will have this egg and the venom transported to Darnassus, then return there when my studies are done here.  I expect to find out a great deal from these specimens, $N.  You have been a great help to me." WHERE `ID`=917;

-- "Timberling Seeds" (918) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Do you have the seeds?  I am eager to plant them." WHERE `ID`=918;

-- "Timberling Seeds" (918) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You got them.  This is good!$b$bI will plant these seeds in special soil I have prepared.  I believe the seeds will sprout into timberlings who are much more docile.  Perhaps later you can see the results!" WHERE `ID`=918;

-- "Timberling Sprouts" (919) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Hello, $N.  Have you found any sprouts near the waters?" WHERE `ID`=919;

-- "Timberling Sprouts" (919) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="That's a lot!  I'm afraid they're spreading at a dangerous rate.  I hope I can solve the riddle of what is tainting them.$b$bThank you for your help, $N.  The land is a cleaner place from your efforts." WHERE `ID`=919;

-- "Rellian Greenspyre" (922) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, a timberling seed?  I wanted to try growing one of these to help Denalan with his studies.$b$bBut I'm afraid I've discovered that a corruption has grown in many of the timberlings, and seeds from such creatures carry their parent's taint.  They are beyond my talents to repair.$b$bDenalan is very skilled with things that grow.  He may find a cure for future timberlings.  He may be their only hope." WHERE `ID`=922;

-- "Tumors" (923) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you been to Wellspring Lake, $N?  Have you been hunting the timberlings there?" WHERE `ID`=923;

-- "Tumors" (923) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Well done!  These tumors are the symptom of the timberling's disease.  They are filled with a poison that we must cleanse from our new land.$b$bI will dispose of these tumors.  Thank you, $N." WHERE `ID`=923;

-- "The Moss-twined Heart" (927) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="$N!  You have something for me?" WHERE `ID`=927;

-- "The Moss-twined Heart" (927) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="...What is this?  A timberling heart??  It's covered with a foul moss!$b$bThank you for bringing this to me, $N.  I will examine the heart and, if fortune shines, determine the nature of the moss about it." WHERE `ID`=927;

-- "Crown of the Earth" (928) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="Greetings, $c. For what purpose do I owe the pleasure of our meeting?" WHERE `ID`=928;

-- "The Glowing Fruit" (930) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="$N, you look like you have something to tell me.  Do you have news concerning the timberlings?" WHERE `ID`=930;

-- "The Glowing Fruit" (930) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You found this on Teldrassil?  Intriguing... this fruit is exotic.  Perhaps its seeds were brought here from far off.  Perhaps even as far as Azeroth!  And there's something about this fruit... it seems to have reacted very strangely with the soil of Teldrassil.$b$bThank you, $N.  Now if you'll excuse me, I must study this further..." WHERE `ID`=930;

-- "The Shimmering Frond" (931) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Where did you get this?  I haven't seen a plant like this since a sojourn I made to the Swamp of Sorrows... decades ago!  It's amazing that a specimen made its way to Teldrassil.  And it's grown to such a size!$b$bThank you, $N.  Forgive my shortness of words, but there is a test I would like to perform on this frond..." WHERE `ID`=931;

-- "Teldrassil" (940) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="Hmm... You come with the spirit of the forest strongly within you, $c. What business do you have with the Arch Druid of the Kaldorei?" WHERE `ID`=940;

-- "Planting the Heart" (941) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You place the heart within the planter, and it quickly digs itself in!$b$bA few seconds later it wriggles back out, cleansed.  It pulses slightly... beckoning for you to take it." WHERE `ID`=941;

-- "Denalan's Earth" (997) - Reward Text, missing double spacing and should have $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, it's here!  I have waited for this rare earth for quite some time.  I hope it's still fresh...$b$bThank you for bringing it to me, $N.  You are a $r who is generous with $Ghis:her; time." WHERE `ID`=997;

-- "The New Frontier" (1047) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="What makes you think I wish to be pestered by the likes of you, $c?  Wait - let me stop the important duties I attend to on a daily basis so I can help you locate a doodad somewhere.  By all means, the welfare of Darnassus - nay, all of Teldrassil - should come second to the acquisition of a bauble for your collection.$b$bThe fools in Moonglade waste my time with their call for assistance, and now I must endure this?" WHERE `ID`=1047;

-- "Vorlus Vilehoof" (1683) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Do you have the horn, $N?  Is our moonwell free of the fiend Vorlus?" WHERE `ID`=1683;

-- "Vorlus Vilehoof" (1683) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Well done, $N.  It is good to know Vorlus is defeated and our moonwell cleansed, and it is good to see young warriors eager to keep our beloved Teldrassil free of corruption.$B$BNow let us begin your training..." WHERE ID=1683;

-- "Elanaria" (1684) - Reward Text, missing double spacing and should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="I bid you greetings, $N.  Your name rings loudly in Darnassus, for you show promise.  But we shall soon see if you possess the strength of will to follow the path of the $c." WHERE ID=1684;

-- "The Shade of Elura" (1686) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you defeated the Shade of Elura, $N?  And do you have the lost elunite ore?" WHERE `ID`=1686;

-- "Smith Mathiel" (1692) - Completion Text, missing double spacing and should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="Greetings, young $c.  How might my skills serve you?" WHERE `ID`=1692;

-- "Smith Mathiel" (1692) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, elunite ore.  This is a fine metal to work with, for it is blessed by the goddess Elune herself.  It would be an honor to craft weapons with it.$B$BPlease wait while I work..." WHERE ID=1692;

-- "Weapons of Elunite" (1693) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="$N, I have crafted these weapons with the elunite you brought to me.  Please, take whichever most suits you.$B$BAnd I must thank you.  Working with elunite is both an honor and a pleasure." WHERE ID=1693;

-- "The Apple Falls" (2241) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="Had I saved every flower that dolt, Jannok, had sent me, I would have had the means to open a shop. Regardless, it seems as if Jannok's latest courier may prove to be useful.$b$bInterested in some work, $c?" WHERE `ID`=2241;

-- "Erion Shadewhisper" (2259) - Reward Text, should have $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="It is time to branch out, $r - the world awaits." WHERE `ID`=2259;

-- "Ferocitas the Dream Eater" (2459) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Ferocitas and the Gnarlpine Mystics must return what is mine.  Please retrieve the emerald so that I may repair my emerald dreamcatcher." WHERE `ID`=2459;

-- "Ferocitas the Dream Eater" (2459) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Now I can repair my dreamcatcher.  Thank you, $N." WHERE `ID`=2459;

-- "Oakenscowl" (2499) - Completion Text, should have $r instead of $R.
UPDATE `quest_request_items` SET `CompletionText`="Have you located Oakenscowl yet, $r?" WHERE `ID`=2499;

-- Druid of the Claw (2561) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="I am finally free of the control of the Gnarlpine. Thank you, $N.$b$bMy spirit may now rest peacefully forever in the Emerald Dream.$b$bPerhaps one day we may meet again, young $c. But, for now, please accept this reward as a symbol of my gratitude." WHERE `ID`=2561;

-- "Simple Sigil" (3116) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="Soon you will see others from different races in the boughs of our home--do not let it cause any prejudice within you. They are welcome. They will aid us when they can. Not all of them will be altruistic, but they should be granted some amount of trust.$b$bBut none of this matters now. Now we must focus on you, and how you can aid our people. I am here for that very purpose. I will train you in the ways of a $c as you become stronger. Return to me whenever you wish and I will do what I can to aid you." WHERE `ID`=3116;

-- "Etched Sigil" (3117) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="You've arrived, and none too soon, $N. Welcome to Shadowglen.$B$BI trust my sigil found you in good spirits and health?$B$BAs I said previously, I am here to train you as a $c; to tame beasts to aid you in battle; to use a bow with unerring accuracy; to respect the lands which we call home and also the lands beyond." WHERE `ID`=3117;

-- "Etched Sigil" (3117) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="As you experience what Shadowglen has to teach you, come see me--I will be able to help you understand more about your role as a $c and what you are capable of.$B$BThese are dangerous times, $N, do not take for granted the skill of your pets--there are things in this world more dangerous than you can imagine. Go with Elune and return to me again." WHERE `ID`=3117;

-- "Verdant Sigil" (3120) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="Ah, young $c. I see you're eager to continue your studies. Good.$b$bI wonder, have you spent much time in the Emerald Dream already? Perhaps you're not prepared for that yet... In time, I'm sure.$b$bBut until then, we should discuss other matters." WHERE `ID`=3120;

-- "Un'Goro Soil" (3764) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Ah yes, the dirt.  The Arch Druid wants twenty loads per adventurer, and twenty loads he shall get.  Let those who conspire against us fall to the wayside!" WHERE `ID`=3764;

-- "Un'Goro Soil" (3764) - Reward Text, missing double spacing and should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="Unload your precious cargo here, noble $c.  It must have been quite the burden... not unlike the burden I carry being a visionary.  Here is an honorarium for your work, as dictated by the Arch Druid himself.$B$BArch Druid Staghelm wants to speak with you again $N, but for his next task you will be aided if you have a journeyman's understanding of Herbalism.  If you don't know it though, you will still be able to aid the Circle!" WHERE `ID`=3764;

-- "Morrowgrain Research" (3781) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Peace and serenity be yours, friend.  You are here on business from the Arch Druid himself, yes?" WHERE `ID`=3781;

-- "Morrowgrain Research" (3781) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Yes, this voucher is good for twenty packets of seeds.  If you run out, we have more that can be provided.  Unfortunately though, Tharlendris seeds are quite costly to produce in significant numbers.  This is why the Cenarion Circle asks that those who are assisting us help out by offsetting some of the cost.$B$BThose who return with morrowgrain find that the reward the Arch Druid offers far makes up for the cost." WHERE ID=3781;

-- "Calm Before the Storm" (4510) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="Elune'adore, $c.  What may I do for you today?" WHERE `ID`=4510;

-- "Aquatic Form" (5061) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Very impressive, $N.  You are ready to learn your aquatic form, and it is my pleasure to teach it to you.$B$BAlso, in recognition of your achievement during the two trials, I give you this item.  I hope you'll find it to be a welcome addition to your gear as a protector of nature and a keeper of the balance." WHERE `ID`=5061;

-- "Heeding the Call" (5923,5924,5925) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="I am glad you found your way here today, young $c.  The time has come for you to take a large step into a much larger world.$B$BInside each of Cenarius' children is the call to serve nature.  Animals and plants are our friends as well as our charges.  We choose to devote our lives as preservers of balance for their sakes as well as our own.  Your first step into this world will be to learn of the ways of the bear, and to learn strength of body and heart.$B$BReady yourself!" WHERE `ID` IN (5923,5924,5925);

-- "Back to Darnassus" (5931) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Welcome back, $N.  I sense that your first meeting with the Great Bear Spirit is the same as it is with all druids when they first start down the path of the Claw... a little bewildering, but very intense.  I know it was that way with me.$B$BThe Great Bear Spirit has been a part of Azeroth as long as Azeroth has existed in the heavens.  We have come to rely on its wisdom and its power to fuel our purpose.  The time has now come for your first test of this purpose.  Listen closely..." WHERE `ID`=5931;

-- "Body and Heart" (6001) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="When you have faced the challenge that lies before you, your understanding of strenght of body and strenght of heart will be fully realized.  Until that time, I cannot help you further." WHERE `ID`=6001;

-- "Body and Heart" (6001) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You have finally taken your large step into a much larger world, $N.  I sense the teaching of the Great Bear Spirit within you, and I sense that you have received the strength that Lunaclaw possessed.$B$BThere are no further obstacles in your way... let me now teach you what it means to be a $C of the Claw!" WHERE `ID`=6001;

-- "Taming the Beast" (6063) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="You will learn, $N, and one day you will be a great $c." WHERE `ID`=6063;

-- "Taming the Beast" (6101) - Completion Text, should have $r instead of $R.
UPDATE `quest_request_items` SET `CompletionText`="Understanding the balance between nature and oneself is a way of life for every $r." WHERE `ID`=6101;

-- "Training the Beast" (6103) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="A fledgling $c. I see. Yes. I can bestow you with the skills you need to train and guide your pet. Not only will you be able to teach your pet new abilities, you will now be able to feed your pet, as well as revive it, should it fall in battle.$B$BRemember, $N, always respect the balance and live in awe of nature around you. Now, go forth. We shall speak again, at a later date." WHERE ID=6103;

-- "The Bounty of Teldrassil" (6341) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="How may I help you?  Are you in need of transport?" WHERE `ID`=6341;

-- "The Bounty of Teldrassil" (6341) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, you wish to get this to Auberdine?  Very well..." WHERE `ID`=6341;

-- "Return to Nessa" (6343) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="$N, you're back from Auberdine?  Did you speak with Laird?" WHERE `ID`=6343;

-- "Return to Nessa" (6343) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="This is very interesting.  The fish here are large, but I didn't think the difference in bounties between here and the mainland was so great.  There must be a reason for this...$B$BWell thank you, $N.  I will discuss with the villagers the news you brought.  Perhaps, one day, we will find the root of this oddity.  But until then, we shall reap its benefits!" WHERE `ID`=6343;

-- "Nessa Shadowsong" (6344) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Yes, I have need of a courier who will take a package to Darkshore.  Will you help me?" WHERE `ID`=6344;

-- "The New Frontier" (6761) - Reward Text, missing double spacing AND should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="Yes $c, thank you for coming.  I apologize about the misunderstanding... the air is thick with mistrust between the Arch Druid here and Keeper Remulos in Moonglade.  Each suspect the other of chicanery, and the fact that strange corruptions of Teldrassil continue unabated are still an issue here.  It does little to quell mistrust.$B$BRegardless, our duty to the Cenarion Circle remains... even if those who lead it may disagree with one another." WHERE `ID`=6761;
