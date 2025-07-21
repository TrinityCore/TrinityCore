-- "The Absent Minded Prospector" (741) - Completion Text, should have $r instead of $R.
UPDATE `quest_request_items` SET `CompletionText`="What can I do for you, $r?" WHERE `ID`=741; 

-- "Therylune's Escape" (945) - Completion Text, missing text entirely.
UPDATE `quest_request_items` SET `CompletionText`="My sister likes to wander, but she's been gone for a long time now..." WHERE `ID`=945;

-- "Therylune's Escape" (945) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="My sister was where??  Therylune doesn't mind getting herself dirty, but still!  That's a long way to wander, and the Master's Glaive is an unwholesome place...$B$BWell thank you, $N.  It was very nice of you to let me know she's all right." WHERE `ID`=945;

-- "Cave Mushrooms" (947) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Do you have my mushrooms, $N?  Have you been to the cave?" WHERE `ID`=947; 

-- "Cave Mushrooms" (947) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Many thanks, $N.  These mushrooms are fine specimens!$b$bAnd when you were at Cliffspring Falls, did you find anything to confirm the warnings of the Ancients?$b$bThe Ancients are wise, but I had hoped that, this time, they were wrong." WHERE `ID`=947; 

-- "Onu" (948) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="$N.  You are here.$b$bGood.$b$bWe have matters...to discuss.  You and I." WHERE `ID`=948;

-- "Return to Onu" (950) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="$N.  You return." WHERE `ID`=950; 

-- "Return to Onu" (950) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="A chaotic, primal magic surrounds this parchment of scribbles.  I sense the work of the old ones in it.$b$bLet us hope it reveals the purpose of the Twilight's Hammer in Darkshore..." WHERE `ID`=950;

-- "Mathystra Relics" (951) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="$N.  Has your rooting through the Ruins of Mathystra been fruitful?" WHERE `ID`=951; 

-- "Mathystra Relics" (951) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Thank you.  These relics are from a time when Mathystra shone.  That once great bastion of the elves has faded, but shards of its magic remain.  Let us hope we can unlock the secrets of that place before our enemies...$b$bBe vigilant, $N." WHERE `ID`=951;

-- "The Tower of Althalaxx" (967) - Completion Text, should have $c instead of $C.
UPDATE `quest_request_items` SET `CompletionText`="You have some business with me, $c?" WHERE `ID`=967;

-- "Deep Ocean, Vast Sea" (982) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="The captains of those ships were good night elves, and they deserve a better fate than they were given.  Perhaps tending to their personal effects will be the best way to put their spirits to rest." WHERE `ID`=982; 

-- "Deep Ocean, Vast Sea" (982) - Reward Text, missing double spacing and gender discrepancy.
UPDATE `quest_offer_reward` SET `RewardText`="You've done us here in Auberdine a great service, $glad:lass;.  We'll make sure that their effects are properly taken care of.$b$bAs for you, please have this.  It is the least I can do for someone with the bravery to set things right." WHERE `ID`=982; 

-- "Trek to Ashenvale" (990) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="Ah, a $c from Darkshore. Selarin has done well to send you here so quickly, $N. I wish your trip here wasn't under such dire stress. Perhaps with your help we can improve matters.$B$BI would start my visit by speaking to the other citizens of Astranaar. Some could surely use your aid." WHERE `ID`=990;

-- "Gaffer Jacks" (1579) - Reward Text, should have $r instead of $R.
UPDATE `quest_offer_reward` SET `RewardText`="I can't believe you found them! You must be the luckiest $r in Kalimdor!" WHERE `ID`=1579; 

-- "Electropellers" (1580) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Did you find any electropellers?  I'll need them if I'm to continue my research on duck decoys..." WHERE `ID`=1580; 

-- "Electropellers" (1580) - Reward Text, missing double spacing and gender discrepancy.
UPDATE `quest_offer_reward` SET `RewardText`="I can't believe it!  You found them!  You are the best fisherman I've ever seen!$b$bThank you, $N.  And here, take these.  Although you're so good and you probably don't need them, they will help you with your fishing." WHERE `ID`=1580; 

-- "Cleansing of the Infected" (2138) - Reward Text, partial text is missing.
UPDATE `quest_offer_reward` SET `RewardText`="You have done Auberdine a great service, $N, but your task is not yet complete.$b$bReturn to me once you have rested.$b$b...and $N, prepare your mind and soul for more bloodshed." WHERE `ID`=2138;

-- "Washed Ashore" (3524) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="It is only recently that these creatures started landing on the coast of Darkshore in such alarming numbers.  I can't help but think that this is an ill omen of some sort.  Recovering a sample of that creature's bones to the south would help us in Darnassus assess this situation!" WHERE `ID`=3524; 

-- "Washed Ashore" (3524) - Reward Text, partial text is missing.
UPDATE `quest_offer_reward` SET `RewardText`="I hope the murloc did not give you much trouble in collecting this for us!  I will be sure to get this on the next hippogryph to Darnassus.  The Temple of the Moon has given me some funds to hand out for assistance; please have some with our thanks.$B$BYour success here emboldens me to offer you a chance to aid the Temple of the Moon further, if you are interested..." WHERE `ID`=3524;

-- "Washed Ashore" (4681) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Once you have investigated the creature's remains in the water to the west of here, I should be able to file a proper report with the Temple of the Moon in Darnassus.  Perhaps then we will be closer to discovering the reason why these unfortunate creatures choose to end their lives beached on the coast of Darkshore." WHERE `ID`=4681; 

-- "Washed Ashore" (4681) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You've been a tremendous help here today; we now have a solid chance at unlocking the mystery of why these creatures choose to beach themselves on the cost of Darkshore.  The idea that they might be fleeing the area around Teldrassil is disturbing.  Should you come across others in your travels, please let me know.  Our research here is but in its infancy.$B$BOn behalf of the Temple of the Moon, please accept this as thanks for the effort you have given.  Thank you, $N!" WHERE `ID`=4681; 

-- "Beached Sea Creature" (4723) - Completion Text, correct text.
UPDATE `quest_request_items` SET `CompletionText`="Perhaps one day we'll find a means to prevent these poor creatures from ending their lives needlessly on the coast of Darkshore.  Until then, we must continue our research!$b$bGreetings $N - what news do you bring?" WHERE `ID`=4723; 

-- "Beached Sea Creature" (4723) - Reward Text, correct text.
UPDATE `quest_offer_reward` SET `RewardText`="Another discovery - well done $N!  These remains will be properly studied once they get to Darnassus.  Please accept this small honorarium in exchange for the remains you have provided for our study." WHERE `ID`=4723; 

-- "Beached Sea Turtle" (4725) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="It is a pleasure to see you again, $N.  We are making great strives in uncovering the mystery of why majestic sea creatures beach themselves on the Darkshore coastline, but with every question answered, two more are raised it seems.$b$bAre you here to offer us more aid in our research?" WHERE `ID`=4725; 

-- "Beached Sea Turtle" (4725) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="I have heard of the kinds of carriages found on the back of the turtle you found.  Those I do believe are naga carriages, used both in battle and in transportation of their supplies on to land.  The markings on the box you found are of the naga; this would explain their invasive presence in far-northern Darkshore.$b$bI will send this box to Darnassus along with the rest of your discoveries.  This is for you - thank you again for your assistance." WHERE `ID`=4725;

-- "Beached Sea Turtle" (4727) - Completion Text, correct text.
UPDATE `quest_request_items` SET `CompletionText`="Hello once again $N - have you found any more beached creatures that the Temple of the Moon should know about?" WHERE `ID`=4727; 

-- "Beached Sea Turtle" (4727) - Reward Text, correct text.
UPDATE `quest_offer_reward` SET `RewardText`="It is interesting that the murlocs were not present at this site; we will keep this in mind as we study this creature's remains!  Thank you for your effort, $N; the Temple of the Moon would like for me to give you this, as compensation for your time." WHERE `ID`=4727;

-- "WANTED: Murkdeep!" (4740) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Greetings $c - what may the Sentinels assist you with today?  Perhaps you are here to inquire about the bounty on Murkdeep?" WHERE `ID`=4740; 

-- "WANTED: Murkdeep!" (4740) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Well, looks like you're here to more than just inquire!  The citizens will be delighted to know that tonight they will sleep a little bit more soundly and safer.$b$bYou've acted as the executioner of justice for the people of Auberdine today, $N.  For that, I would like to offer you this as a suitable reward... for a true hero of the Auberdine people." WHERE `ID`=4740; 

-- "The Cliffspring River" (4762) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="It's no surprise how tainted this water is, but just look at how putrid it is becoming!  It would seem that action is needed sooner than later, eh $N?$b$bTo our east is Felwood; it is the real source of this corruption, one that I have seen in times past.  I predict this sample will confirm this.  We might be able to enact a cure for it here, but in order to even try we will need assistance.  When that time comes $N, I hope you will be able to give the aid we need." WHERE `ID`=4762; 

-- "The Blackwood Corrupted" (4763) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="The Talisman of Corruption is a sinister device that only serves to pervert the balance of nature.  When you obtain this item from whatever satyr is tormenting the furbolgs and bring it to me for disposal, we will have won a great victory this day!" WHERE `ID`=4763; 

-- "The Blackwood Corrupted" (4763) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="We have just begun this war to reclaim our forest from the forces of corruption, but a battle this day has been won! $N, the people of Auberdine owe you a debt of gratitude that will never be easily repaid.  Please accept this along with our thanks.  What we have learned here today may one day free our furbolg friends from the shackles of torment permanently." WHERE `ID`=4763;

-- "The Red Crystal" (4811) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="What do you have to report on that red crystal?  Does it even really exist?" WHERE `ID`=4811; 

-- "The Red Crystal" (4811) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="So the crystal exists, $N?  Fascinating... anyway, your task has been well executed; good work!$B$BWhat exactly is this crystal?  This is but a single question in a sea of questions.  Another question that comes to mind is why the moonkin would be drawn to this object?  Is the crystal benign in nature, or does it hold a more sinister purpose?$B$BI have many more questions, but we're going to need to examine that crystal closely to get some answers." WHERE `ID`=4811; 

-- "As Water Cascades" (4812) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="The crystal looks very alien against the wooded scenery of Darkshore.  You think you hear a very slight humming coming from deep within it." WHERE `ID`=4812; 

-- "As Water Cascades" (4812) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="You have made it once more to the mysterious crystal.  Removing the stopper on the tube of moonwell water, you gingerly pour the contents out over the top of the crystal.  As the water cascades down its lattices, you see the opaque surface turn transparent..." WHERE `ID`=4812; 

-- "The Fragments Within" (4813) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="Well, it would seem that even though we know more about this crystal, more unanswered questions are the result!$B$BI'll take the information you've uncovered to the council here in Auberdine.  Perhaps they'll know a course of action to follow on this crystal.  Well, that is if there is one to be taken; for now, the threat remains far enough to our east to be out of harm's way.$B$BAs for you, please have this.  Consider it a reward for a job well done, $N." WHERE `ID`=4813;

-- "One Shot.  One Kill." (5713) - Reward Text, should have $c instead of $C.
UPDATE `quest_offer_reward` SET `RewardText`="You bring most welcome news $c. It is good to hear that Aynasha is alive and well thanks to you. I would hope that you might accept a reward for your valor. May Elune watch over you and light your path." WHERE `ID`=5713;

-- "The Principal Source" (6122) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="You're the one that the Cenarion Circle in Moonglade sent?  That's wonderful!  We've quite the crisis our hands here regarding the poor deer, and we're happy for all the help we can get.$B$BDo you have the sample of water that Dendrite Starblaze said you'd have?  He notified me that you'd draw one so we could work on a cure together..." WHERE `ID`=6122;

-- "The Principal Source" (6122) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="By Elune, this water is disgusting!  No wonder the deer are sick.$B$BSomething is polluting the water, and in turn corrupting Darkshore's entire water table.  Sick deer have been seen all over area, and not just by the river.  While this water is most likely a primary source of the sickness spreading, there's something else at work here.$B$BThis water, believe it or not, will help us formulate a cure.  While I research this water, I have need of some items to formulate a cure..." WHERE `ID`=6122;

-- "Gathering the Cure" (6123) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you got the reagents I need to make the salve?  The deer aren't getting any better on their own, so we better hurry to help them out!" WHERE `ID`=6123;

-- "Gathering the Cure" (6123) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="This is good, $N, so much so that it should be enough to make some ample doses of the salve - at least enough to start to make a difference.$B$BMaking a cure for poisons can be quite difficult at times because each one often requires a very specific antidote to counteract it.  Imagine being able to cure a poison at will without having to worry about the exact ingredients of what the antidote must be!$B$BNow, let me get to work on this!" WHERE `ID`=6123;

-- "Curing the Sick" (6124) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you completed what was asked of you by Alanndarian Nightsong of Auberdine?  Your work is not complete unless it is." WHERE `ID`=6124;

-- "Flight to Auberdine" (6342) - Completion Text, missing double spacing.
UPDATE `quest_request_items` SET `CompletionText`="Have you come from Teldrassil?  Tell me, how is the fishing there?" WHERE `ID`=6342;

-- "Flight to Auberdine" (6342) - Reward Text, missing double spacing.
UPDATE `quest_offer_reward` SET `RewardText`="A package from Nessa?  Thank you, $N!  She told me she would send me samples of the fish caught near Rut'theran village.  She thinks they may be very different from the fish caught here...$b$bMy!  This jawbone is nearly twice the size of the same fish found here.  And these scales are as big as a closed fist!  Amazing!" WHERE `ID`=6342;
