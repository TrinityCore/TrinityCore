DELETE FROM `quest_offer_reward` WHERE `ID` IN (28750, 28570, 28344, 9177, 28428, 28553);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28750, 396, 0, 0, 0, 0, 0, 0, 0, 'It\'s about time you arrived, $c.', 58558), -- The Battle for Andorhal
(28570, 6, 0, 0, 0, 0, 0, 0, 0, 'Time is money, $c... and I\'ve got plenty of each.$b$bWhat can I do for you?', 58558), -- The Bogpaddle Bullet
(28344, 0, 0, 0, 0, 0, 0, 0, 0, '*GASP*$B$BHELP!$B$BDROWNING!$B$B*GURGLE*', 59069), -- Can You Smell What the Lok'tar is Cooking?
(9177, 1, 0, 0, 0, 0, 0, 0, 0, '<Sylvanas takes the necklace from your grasp.>$B$BIt can\'t be! After all this time, I thought it was lost forever.$B$B<After a lingering moment the Lady seems to become aware once again of her surroundings, composing herself.>$B$BYou thought this would amuse me? Do you think I long for a time before I was the queen of the Forsaken? Like you, it means nothing to me, and Alleria Windrunner is a long dead memory!$B$B<She drops the amulet to the ground.>$B$BYou may now remove yourself from my presence, $c.', 59069), -- Journey to Undercity
(28428, 1, 5, 0, 0, 0, 0, 0, 0, 'That\'s it?  That\'s your disguise?  I\'m feeling less confident about our chances.$b$bBut still confident.', 58558), -- A Perfect Costume
(28553, 0, 0, 0, 0, 0, 0, 0, 0, 'Well, well, well... look what the Ruag dragged in!', 58558); -- Okrilla and the Blasted Lands

UPDATE `quest_offer_reward` SET `RewardText`='You have gone above and beyond, $N.  Not only have we set back the Cult of the Damned in their crusade to re-plague the plaguelands, but you have uncovered another set of dire plans: they continue to re-animate the dead!$b$bYour name will definitely be mentioned when this information is presented to Highlord Fordring, $N.  You have my thanks, and the blessing of the Argent Crusade.', `VerifiedBuild`=58558 WHERE `ID`=27055; -- Students of Krastinov
UPDATE `quest_offer_reward` SET `RewardText`='By the grace of the Earthmother, he\'s done it!  Thank you, $N!$b$bI admit, I had nearly given up hope on Zen\'Kiki.  It is only due to your patience and diligence that he has come into his own as a druid and member of the Cenarion Circle.  And that\'s without even mentioning the good you\'ve done for nature.$b$bYou have my admiration and respect.', `VerifiedBuild`=58558 WHERE `ID`=26955; -- Zen'Kiki and the Cultists
UPDATE `quest_offer_reward` SET `RewardText`='You won\'t be taking me anywhere, $N.$b$bWhile Koltira prances about with his playmate, Thassarian, I plan to win this battle.  Then I\'ll make Koltira suffer for his weakness.$b$bDon\'t believe me?  Fine, I\'ll let you in on a little secret...', `VerifiedBuild`=58558 WHERE `ID`=27087; -- Lindsay Ravensun, Revealed
UPDATE `quest_offer_reward` SET `RewardText`='You fight well, $N.  I wish I had your ability... and your bravery.', `VerifiedBuild`=58558 WHERE `ID`=27085; -- Supporting the Troops
UPDATE `quest_offer_reward` SET `RewardText`='This... Gloria used to read from this prayer book every night!  How had I forgotten?  She was so devout, $N.$b$b<Del\'s eyes turn to the finger painting.>$b$bOh...$b$bThis painting... my daughter, Andrea... she loved to... to paint...', `VerifiedBuild`=58558 WHERE `ID`=27017; -- Memories from a Lost Past
UPDATE `quest_offer_reward` SET `RewardText`='It would appear that I arrived before you, $N.$b$bField Agent Kaartish gave me the details about my old home.  It seems my battles with the Scourge aren\'t quite over yet.', `VerifiedBuild`=58558 WHERE `ID`=26957; -- The Long Trip Home
UPDATE `quest_offer_reward` SET `RewardText`='I\'m already aware of your actions, $N.  I welcome you into my town, give you my blessing, and what do you do?$b$bYou slay the traitor that we\'ve been hunting down for weeks.  Well done.  Your heroism is budding much earlier than even I had anticipated.', `VerifiedBuild`=58558 WHERE `ID`=27155; -- Turning Yourself In
UPDATE `quest_offer_reward` SET `RewardText`='I suppose that we can take his aggression as an admission of guilt.  You alright, $N?', `VerifiedBuild`=58558 WHERE `ID`=27154; -- Bagging Bisp
UPDATE `quest_offer_reward` SET `RewardText`='Did you notice, $N?  Many names were mentioned, but one name was mentioned far more than the others.$b$bBisp.', `VerifiedBuild`=58558 WHERE `ID`=27153; -- The Good People of Hearthglen
UPDATE `quest_offer_reward` SET `RewardText`='I must admit, $N... I have been using my mind vision spell to keep tabs on you.  And I must say... the number of gnolls you found on the trail is truly staggering!', `VerifiedBuild`=58558 WHERE `ID`=27151; -- Taelan Fordring's Legacy
UPDATE `quest_offer_reward` SET `RewardText`='$N.  It is truly a pleasure.$b$bI know you are young, and still training, but I\'ve had my eye on you.  We among the Argent Crusade are always looking for promising new recruits, and you have indeed shown great promise.  I have no immediate tasks for you, but merely wished to meet you in person, and see for myself what type of $r you really were.$b$bFor the time being, the amenities of Hearthglen are yours to enjoy.  I look forward to our next meeting, $N.  You are dismissed.', `VerifiedBuild`=58558 WHERE `ID`=27002; -- An Audience with the Highlord
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  I\'ll be throwing these in the fire.  We don\'t want those gnolls just sneaking in and stealing them back.', `VerifiedBuild`=58558 WHERE `ID`=27012; -- A Gnoll's Resolve
UPDATE `quest_offer_reward` SET `RewardText`='That\'s much more like it!  Now my lumberjacks can get to work again.$b$bNice riding out there, $N.  You cut a pretty impressive silhouette on that mustang.', `VerifiedBuild`=58558 WHERE `ID`=27001; -- This Means WAR (Wild Arachnid Roundup)
UPDATE `quest_offer_reward` SET `RewardText`='I feel a bit more relieved, $N.  Thank you.', `VerifiedBuild`=58558 WHERE `ID`=27013; -- Too Close for Comfort
UPDATE `quest_offer_reward` SET `RewardText`='This will be more than enough, $N.  Now, I will need some time to perform my studies.', `VerifiedBuild`=58558 WHERE `ID`=26999; -- A New Era for the Plaguelands
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for your help, $N.  I know that picking vegetables isn\'t the most heroic task imaginable, but even the humblest tasks have their rewards.', `VerifiedBuild`=58558 WHERE `ID`=26956; -- I Ain't Sayin' You a Gourd-Digger...
UPDATE `quest_offer_reward` SET `RewardText`='I am able to communicate with you through the Val\'kyr, $N.  You have done well.$b$bRemain on Felstone Field.  We must now teach these newly-converted Forsaken how to fight.', `VerifiedBuild`=58558 WHERE `ID`=26937; -- When Death is Not Enough
UPDATE `quest_offer_reward` SET `RewardText`='$N.  The Dark Lady watches over you.', `VerifiedBuild`=58558 WHERE `ID`=26979; -- Strange New Faces
UPDATE `quest_offer_reward` SET `RewardText`='Word arrived shortly before you did, $N.  With the Scourge ejected from Andorhal, the Forsaken has cemented its foothold in Lordaeron.', `VerifiedBuild`=58558 WHERE `ID`=26926; -- Victory, For Now
UPDATE `quest_offer_reward` SET `RewardText`='Excellently done, $N.', `VerifiedBuild`=58558 WHERE `ID`=27117; -- Brute Strength
UPDATE `quest_offer_reward` SET `RewardText`='Excellently done, $N.  And now, with the leader of the Scourge forces eliminated from Andorhal, we bide our time.', `VerifiedBuild`=58558 WHERE `ID`=26924; -- Scholomancer
UPDATE `quest_offer_reward` SET `RewardText`='Araj dead... this is good.  The Royal Apothecary Society has done its part.  As have you, $N.', `VerifiedBuild`=58558 WHERE `ID`=26925; -- Araj the Summoner
UPDATE `quest_offer_reward` SET `RewardText`='You may not act quickly, but at least you do not fail me.$b$bVery well.  I will have a more important task for you, $N, when the time is right.', `VerifiedBuild`=58558 WHERE `ID`=26921; -- Scourge First... Alliance Later
UPDATE `quest_offer_reward` SET `RewardText`='$N!  You\'re awake!  We found you bobbing in the harbor, shortly after the remaining attackers had turned tail.  We were worried about you for a while there...$b$bI\'ve been meaning to thank you, $N.  Not only did you provide us with the intelligence to prepare for this attack, but you helped fight off the Bloodsail AND the Brashtide.  Your name will always be remembered here in Booty Bay.$b$bWe here in Booty Bay pride ourselves on our booty.  Care to take first pick?', `VerifiedBuild`=58558 WHERE `ID`=26703; -- Bloodsail's End
UPDATE `quest_offer_reward` SET `RewardText`='Attacking your former crewmen...$b$bYou really have grown into a real pirate, $N!', `VerifiedBuild`=58558 WHERE `ID`=26700; -- The Damsel's (Bad) Luck
UPDATE `quest_offer_reward` SET `RewardText`='We need to keep moving, $N.  Booty Bay won\'t hold out for much longer.', `VerifiedBuild`=58558 WHERE `ID`=26699; -- Turning the Brashtide
UPDATE `quest_offer_reward` SET `RewardText`='You brought them!  I\'m beginning to think the tide is turning in our favor, $N.', `VerifiedBuild`=58558 WHERE `ID`=26695; -- Prepare for Takeoff
UPDATE `quest_offer_reward` SET `RewardText`='<The Baron quickly empties his cup.>$b$bAH!  Much better, $N.  Now, let\'s get down to business.  I believe that you and I have a town to save.', `VerifiedBuild`=58558 WHERE `ID`=26679; -- Return to Revilgaz
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  The eternal battle wages on, but we\'ve tipped the scales in favor of the pirates today.  Firallon will be happy to hear the news.', `VerifiedBuild`=58558 WHERE `ID`=26648; -- Our Mortal Enemies
UPDATE `quest_offer_reward` SET `RewardText`='I like the cut of your gib, $N.', `VerifiedBuild`=58558 WHERE `ID`=26647; -- Ol' Blasty
UPDATE `quest_offer_reward` SET `RewardText`='Thanks, $N.  I\'d been hearing whispers about \"Pretty Boy\" and a \"boo-box\".  I don\'t think I want to go in the boo-box.', `VerifiedBuild`=58558 WHERE `ID`=26635; -- Cannonball Swim
UPDATE `quest_offer_reward` SET `RewardText`='That should fool that Bloodsail dimwit.$b$bThis was fun, $N.', `VerifiedBuild`=58558 WHERE `ID`=26630; -- Looks Like a Tauren Pirate to Me
UPDATE `quest_offer_reward` SET `RewardText`='I can\'t believe my fortune, $N!  Meeting you has turned my luck to the better, make no mistake there!$B$BIf I ever get a new ship and you\'re looking to sail the seas, you would be my honored guest.', `VerifiedBuild`=58558 WHERE `ID`=26602; -- A Dish Best Served Huge
UPDATE `quest_offer_reward` SET `RewardText`='Great!  I can get a good price for these, especially for what\'s inside Maury\'s foot!  Thanks much, $N!$B$BI hope those three learned their lesson: don\'t bet something you can\'t afford to lose.$B$BAnd maybe it\'s too late for them, but...they should be careful of who they gamble with.', `VerifiedBuild`=58558 WHERE `ID`=26595; -- Kill-Collect
UPDATE `quest_offer_reward` SET `RewardText`='$N, you have saved me from a great dishonor. If it was within my power, I would offer you a place among my tribe. But for now, all I can only offer you is this token for the courage and nobility you have shown.', `VerifiedBuild`=58558 WHERE `ID`=26606; -- Mukla's Demise
UPDATE `quest_offer_reward` SET `RewardText`='Heh heh, well done!  And when you showed Shaky those giblets, how hard did he shake?$B$BHah!  He\'s so easy to read, when I play cards with him I can\'t help but win!$B$BThanks for your help, $N.  Now it\'s your turn to get paid...', `VerifiedBuild`=58558 WHERE `ID`=26594; -- Return to MacKinley
UPDATE `quest_offer_reward` SET `RewardText`='<Flem feels the hides and smiles to himself.>$b$bExcellent work, $N!  These reagents will serve perfectly.$b$b<You detect a hint of shame in Flem\'s eyes, almost as if there\'s something he\'s not telling you.>', `VerifiedBuild`=58558 WHERE `ID`=26434; -- Primal Reagents of Power
UPDATE `quest_offer_reward` SET `RewardText`='Nice work, $N.  Now I\'ve just got to decide what to do with all of these...', `VerifiedBuild`=58558 WHERE `ID`=26450; -- If They're Just Going to Leave Them Lying Around...
UPDATE `quest_offer_reward` SET `RewardText`='<Ruag reads over the report.>$b$bI see.  Thank you for this information, $N.', `VerifiedBuild`=58558 WHERE `ID`=27916; -- Ruag's Report
UPDATE `quest_offer_reward` SET `RewardText`='I was wondering when reinforcements would show up. Suit up, $N. It\'s time to dispense some justice!', `VerifiedBuild`=59069 WHERE `ID`=28089; -- Warchief's Command: Hillsbrad Foothills!
UPDATE `quest_offer_reward` SET `RewardText`='News of your conquest in Silverpine emboldens us, $N. We are prepared to fight at your command and beat back the last remaining vestiges of humanity in Hillsbrad.', `VerifiedBuild`=59069 WHERE `ID`=27746; -- Empire of Dirt
UPDATE `quest_offer_reward` SET `RewardText`='I know that face, $N. This head belongs to a former Gilnean known as Sean Dempsey. He was imprisoned with Crowley before the great outbreak.$B$B<Godfrey pauses to think for a moment.>$B$BI wonder if it would be possible to put him back together. The rest of him must be in the belly of these crocolisks.', `VerifiedBuild`=59069 WHERE `ID`=27574; -- I Never Forget a Face
UPDATE `quest_offer_reward` SET `RewardText`='The part of me that was Gilnean died at Tempest\'s Reach. Only vengeance remains, $N. To that end, we have work to do. Spare me your pointless queries.', `VerifiedBuild`=59069 WHERE `ID`=27550; -- Pyrewood's Fall
UPDATE `quest_offer_reward` SET `Emote2`=1, `RewardText`='The hour of victory approaches, $N. Godfrey has devised a plan to decimate our enemies. I am sending you into the field with him and his men to bring the rebel insurgents to their knees and seal the fate of the Alliance filth encroaching upon our lands.$B$BOur final march begins when you are ready.', `VerifiedBuild`=59069 WHERE `ID`=27542; -- Taking the Battlefront
UPDATE `quest_offer_reward` SET `RewardText`='Had I not witnessed what you did with my own eyes I would not have believed it, $N. Now, with the Ambermill magi on our side, there is but one thing left to do before we retake Gilneas and send those Alliance dogs running for Stormwind.', `VerifiedBuild`=59069 WHERE `ID`=27518; -- Transdimensional Warfare: Chapter III
UPDATE `quest_offer_reward` SET `RewardText`='<The Banshee Queen\'s voice invades your thoughts.>$B$BExcellent work, $N. Now to eject them into our waiting hands!', `VerifiedBuild`=59069 WHERE `ID`=27513; -- Transdimensional Warfare: Chapter II
UPDATE `quest_offer_reward` SET `RewardText`='Perfect. I hope this wasn\'t too much trouble to come by, $N. Relios was a pupil of mine back when I was a mortal man thereby making him a competent and formidable adversary. I suppose I could have warned you ahead of time.$B$BNow, let us see the ring.$B$B<Dalar trails the ring across the spine of the codex.>$B$BThere we are...', `VerifiedBuild`=59069 WHERE `ID`=27478; -- Relios the Relic Keeper
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N. The praise the Banshee Queen lavishes upon you is apparently not unfounded.', `VerifiedBuild`=59069 WHERE `ID`=27475; -- Unyielding Servitors
UPDATE `quest_offer_reward` SET `RewardText`='I had no doubt that you would succeed, $N. I hope you can understand why I kept the true purpose of your mission a secret. Should Crowley and Bloodfang have found out about our plan, they would have surely gotten to Godfrey first and disposed of the body.$B$BStand by, $N. The time of their rebirth is at hand.', `VerifiedBuild`=59069 WHERE `ID`=27438; -- The Great Escape
UPDATE `quest_offer_reward` SET `RewardText`='Here we are, $N. He is a little rotted, but no worse for the wear. We must hurry before the Alliance finds us!', `VerifiedBuild`=59069 WHERE `ID`=27406; -- A Man Named Godfrey
UPDATE `quest_offer_reward` SET `RewardText`='No time to bask in the battle glory, $N. We have a job to do. I have no doubt more of those beasts are on the way.', `VerifiedBuild`=59069 WHERE `ID`=27423; -- Resistance is Futile
UPDATE `quest_offer_reward` SET `RewardText`='Forward Commander Onslaught fought until the bitter end, $N. It took a pack of bloodthirsty worgen to finally bring him down. We must not let his death, or the death of all of our soldiers in Gilneas, go in vain. Our mission MUST succeed.$B$BNow I will reveal to you why we are here.', `VerifiedBuild`=59069 WHERE `ID`=27405; -- Fall Back!
UPDATE `quest_offer_reward` SET `RewardText`='Though we were shamed in battle, the enemy was not victorious. I will not soon forget this, $N.$B$BIf I make it back to Silverpine I will likely retire from the service. War is not in my blood.', `VerifiedBuild`=59069 WHERE `ID`=27360; -- Vengeance for Our Soldiers
UPDATE `quest_offer_reward` SET `RewardText`='<The F.C.D. crackles with electricity.>$B$BAn Alliance armada is en route? How could this have happened?$B$B<Forward Commander Onslaught cuts out for a moment. You hear worgen howling in the background.>$B$BYou\'ve got to hurry, $N. We\'re being overrun up here at Forward Command.', `VerifiedBuild`=59069 WHERE `ID`=27364; -- On Whose Orders?
UPDATE `quest_offer_reward` SET `RewardText`='<The F.C.D. crackles with static.>$B$BDreadwatch is lost? This is bad, $N. Real bad.$B$BIf Dreadwatch is compromised it means we\'ve lost Gilneas City.', `VerifiedBuild`=59069 WHERE `ID`=27349; -- Break in Communications: Dreadwatch Outpost
UPDATE `quest_offer_reward` SET `RewardText`='That towering behemoth has killed hundreds of Forsaken soldiers. You\'ve done a great thing, $N.', `VerifiedBuild`=59069 WHERE `ID`=27322; -- Korok the Colossus
UPDATE `quest_offer_reward` SET `RewardText`='If I could still breathe I\'d let out a sigh of relief.$B$BDon\'t get too comfortable, though, $N, your mission here has just begun.', `VerifiedBuild`=59069 WHERE `ID`=27333; -- Losing Ground
UPDATE `quest_offer_reward` SET `RewardText`='Well if it isn\'t $Nnub!$B$BI hope you\'re ready for battle, because that\'s all you\'ll find in this hellhole. We\'re at the heart of contested territory and these worgen mongrels won\'t give an inch!', `VerifiedBuild`=59069 WHERE `ID`=27290; -- To Forsaken Forward Command
UPDATE `quest_offer_reward` SET `RewardText`='<The Banshee Queen\'s voice invades your thoughts.>$B$BYou have avenged the fallen, $N, but there is more to be done.', `VerifiedBuild`=59069 WHERE `ID`=27181; -- Excising the Taint
UPDATE `quest_offer_reward` SET `RewardText`='Though you killed a large number of the newly turned worgen, many more are sure to appear. Still, their assault will have softened. Well done, $N!', `VerifiedBuild`=59069 WHERE `ID`=27232; -- The Waters Run Red...
UPDATE `quest_offer_reward` SET `RewardText`='It would seem that Crowley is more formidable than I anticipated. Still, he is a man - flesh and bone - full of secrets. Secrets that I know all about...$B$BYou have served me well, $N. I could use someone of your ability at the Sepulcher. I have a plan to deal with Crowley and his insurgents once and for all. Will you help?', `VerifiedBuild`=59069 WHERE `ID`=27099; -- No Escape
UPDATE `quest_offer_reward` SET `RewardText`='I see everything, $N. Through Agatha all is known to me.', `VerifiedBuild`=59069 WHERE `ID`=27097; -- Rise, Forsaken
UPDATE `quest_offer_reward` SET `RewardText`='<Sylvanas raises an eyebrow.>$B$BSo the orcs are in order?$B$B<Sylvanas reads the commendation letter.>$B$BRecovered their supplies? Killed a dozen worgen? Toppled an ettin? Freed their soldiers and destroyed the Skitterweb matriarch?$B$BI say this rarely, $N, but I am impressed. Perhaps your ability matches your aspirations. We shall see, for now you will be tested!', `VerifiedBuild`=59069 WHERE `ID`=27096; -- Orcs are in Order
UPDATE `quest_offer_reward` SET `RewardText`='Lok\'tar, $N! Once the ale wears off my orcs will be ready!', `VerifiedBuild`=59069 WHERE `ID`=27093; -- Lost in the Darkness
UPDATE `quest_offer_reward` SET `RewardText`='You rescued our orcs and killed the Skitterweb matriarch? We owe you a great debt of gratitude. You\'ve saved us all from certain execution, $N. I\'m sure we can rouse these drunken idiots now.', `VerifiedBuild`=59069 WHERE `ID`=27094; -- Deeper into Darkness
UPDATE `quest_offer_reward` SET `RewardText`='Alas, poor Yorick! I knew her, $N. An assassin of infinite courage...$B$BNow, tell me what\'s going on? What did you and Yorick discover?', `VerifiedBuild`=59069 WHERE `ID`=27045; -- Waiting to Exsanguinate
UPDATE `quest_offer_reward` SET `RewardText`='Potent enough to exterminate a thousand murlocs! I think I\'ll put that on the label. You\'ve done well, $N, and great work around here gets rewarded.', `VerifiedBuild`=59069 WHERE `ID`=26998; -- Iterating Upon Success
UPDATE `quest_offer_reward` SET `RewardText`='$Nnub has returned! And in one piece!$B$BDefender of Silverpine! Redeemer of the Horde! $Nnub, your bravery must be rewarded!', `VerifiedBuild`=59069 WHERE `ID`=26989; -- The Gilneas Liberation Front
UPDATE `quest_offer_reward` SET `RewardText`='Our task is complete, and it\'s all thanks to you, $N.  I\'d like to offer you your choice from our coffers.  In addition, I intend to make you a full-fledged member of our order.$b$bWelcome to the Thorium Brotherhood, $N.  I\'m proud to call you a $g brother: sister;.', `VerifiedBuild`=58558 WHERE `ID`=28064; -- Welcome to the Brotherhood
UPDATE `quest_offer_reward` SET `RewardText`='A fight well-fought, $N!  I\'m beginning to feel the tide turn.$b$bNow, when you\'re ready, let\'s hit these Dark Irons where it really hurts!', `VerifiedBuild`=58558 WHERE `ID`=28056; -- Rise, Obsidion
UPDATE `quest_offer_reward` SET `RewardText`='Well, here we are.$b$bI hope you\'re ready, $N.', `VerifiedBuild`=58558 WHERE `ID`=28052; -- Operation: Stir the Cauldron
UPDATE `quest_offer_reward` SET `RewardText`='<Hansel weighs the stone in his hands.>$b$bThis thing is strange, $N.  I don\'t know what to make of it.  It ain\'t natural, that\'s for sure.', `VerifiedBuild`=58558 WHERE `ID`=27979; -- Dark Ministry
UPDATE `quest_offer_reward` SET `RewardText`='Balance is restored - for now.  We may call on you again in the future, $N.', `VerifiedBuild`=58558 WHERE `ID`=26338; -- Population Con-Troll
UPDATE `quest_offer_reward` SET `RewardText`='I can feel the raw power contained in this gem, $N. I\'ll send it to Silvermoon for our magisters to study further, but I am sure it will prove useful in our struggle against the Amani.$B$BYour help has been invaluable in procuring this gem, and I will see to it that the Farstriders know the name of the $r who made this find possible.', `VerifiedBuild`=58558 WHERE `ID`=9457; -- An Unusual Patron
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  I will inspect these heads to ensure poor Yenniku was spared the headhunter\'s axe.', `VerifiedBuild`=58558 WHERE `ID`=26299; -- Headhunting
UPDATE `quest_offer_reward` SET `RewardText`='Well done. Now, this is curious...$B$BThe inscription on this totem is in a language no troll could ever hope to learn, but one that is known to us. It names the bearer as an ally of a water elemental named Naias and marks him as one worthy to channel his power.$B$BThis is most unexpected, but not entirely bad, $N. With your help, I\'d like to pursue this further.', `VerifiedBuild`=58558 WHERE `ID`=9436; -- Bloodscalp Insight
UPDATE `quest_offer_reward` SET `RewardText`='<Aggro\'gosh salutes you.>$b$bThe Horde thanks you, $N.  Grom\'gol is protected, if only for today.', `VerifiedBuild`=58558 WHERE `ID`=26281; -- The Defense of Grom'gol: Trollish Thievery
UPDATE `quest_offer_reward` SET `RewardText`='These are good tusks, $N.  You prove that you have the strength to hunt the Bloodscalps.$B$BAnd that is good, because you are not done hunting them.', `VerifiedBuild`=58558 WHERE `ID`=26298; -- Hunt for Yenniku
UPDATE `quest_offer_reward` SET `RewardText`='She looks bigger already!  You can see, these raptors grow quickly.  You are lucky to have found such a strong companion.$b$bKeep her by your side as long as you can, $N.  I\'m sure she will prove to be an asset in the future.', `VerifiedBuild`=58558 WHERE `ID`=26321; -- I Think She's Hungry
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work. Hopefully the raids will stop for now.$b$bI have one more task for you, $N.', `VerifiedBuild`=58558 WHERE `ID`=26280; -- The Defense of Grom'gol: Murloc Menace
UPDATE `quest_offer_reward` SET `RewardText`='Yes, the little one seems to have taken a liking to you.  I suppose that one raptor alone and raised among orcs is much less deadly than a whole pack of them.  Keep her, $N... she may come in handy.$b$bIn fact...', `VerifiedBuild`=58558 WHERE `ID`=26317; -- A Lashtail Hatchling
UPDATE `quest_offer_reward` SET `RewardText`='My mother\'s spirit rests well tonight, $N.$b$bAs will I.', `VerifiedBuild`=58558 WHERE `ID`=26304; -- Nighttime in the Jungle
UPDATE `quest_offer_reward` SET `RewardText`='What a shame, yes.$b$bThis is what the spirits wanted, yes.$b$bMaybe when you are stronger, you will go into Zul\'Gurub and take back your $N\'aka from Mandokir, yes.$b$bFor now, Priestess give you this.', `VerifiedBuild`=58558 WHERE `ID`=26362; -- Be Raptor
UPDATE `quest_offer_reward` SET `RewardText`='Hold on, next part is tough, yes.$b$bLots of chances to fail, yes.$b$bBut $N and $N\'aka going to be reunited... yes they will.', `VerifiedBuild`=58558 WHERE `ID`=26360; -- Mind Control
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done it!  You freed Yenniku from the will of Zanzil and the tyranny of the Skullsplitter, and completed the mission I had thought was so hopeless.  Zanzil still looms a threat in the Cape of Stranglethorn, but for now, I at least know that the soul of my chief\'s son is free.$B$BOur tribe will remember your name in songs, $N, and we will etch your tale in stone so that it will live forever.', `VerifiedBuild`=58558 WHERE `ID`=26305; -- Saving Yenniku
UPDATE `quest_offer_reward` SET `RewardText`='A fuel regulator?  This seems important.  At least, I hope it is.$b$bWe may not have ended the Venture Company\'s operations, but we at least slowed them down.  Thank you, $N.', `VerifiedBuild`=58558 WHERE `ID`=26352; -- Cozzle's Plan
UPDATE `quest_offer_reward` SET `RewardText`='You retrieved the eye!  Your might is the stuff of legends, $N!$B$BAnd in getting the Eye, you must have defeated Mai\'Zoth and sent him to the Nether.  That is why the spirits would not mention him before.$B$BIt is good that he is gone from the world of flesh and bone, but now that he is in the realm of spirits...I fear he will begin a new reign.$B$BBut that is a worry for another time.', `VerifiedBuild`=58558 WHERE `ID`=26303; -- The Mind's Eye
UPDATE `quest_offer_reward` SET `RewardText`='You have proven a worthy ally to the Revantusk, $N. Well done.', `VerifiedBuild`=59069 WHERE `ID`=26224; -- Hunt the Savages
UPDATE `quest_offer_reward` SET `RewardText`='This is the first time anyone has actually completed the challenge. You truly are a powerful $c, $N. As promised, choose your reward.', `VerifiedBuild`=59069 WHERE `ID`=28647; -- The Durnholde Challenge: D-1000
UPDATE `quest_offer_reward` SET `RewardText`='With the fingers destroyed and the hand shattered, the Stormpike will have no choice but to scurry back to their cave in Alterac Valley.$B$B<Cromush spits.>$B$BWarchief Hellscream will hear about your bravery, $N.$B$BAnd rest assured that he will know of the Frostwolf clan\'s treason!', `VerifiedBuild`=59069 WHERE `ID`=28616; -- Stormpike Apocalypse
UPDATE `quest_offer_reward` SET `RewardText`='So it\'s true, you did kill the beast! The people of Hillsbrad are indebted to you, $N. You have made the land safer for our citizens.$B$BTake whatever you may desire from our coffers.', `VerifiedBuild`=59069 WHERE `ID`=28485; -- Yetimus the Yeti Lord
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N! I promise you that this is the last time I take this gear off.', `VerifiedBuild`=59069 WHERE `ID`=28487; -- Humbert's Personal Problems
UPDATE `quest_offer_reward` SET `RewardText`='WHAT!? No, don\'t tell me that, $N! It can\'t be true! My... I... I would never...$B$BI won\'t give up, $c. Just you wait and see. I will save those fawns!', `VerifiedBuild`=59069 WHERE `ID`=28495; -- A Fighting Chance
UPDATE `quest_offer_reward` SET `RewardText`='Look upon the carnage, $N. You and I make quite the team!$B$BNow to find those plans and deal with their leaders.', `VerifiedBuild`=59069 WHERE `ID`=28397; -- They Will Never Expect This...
UPDATE `quest_offer_reward` SET `RewardText`='Perhaps with Chet vanquished, the lethality levels of this place will decrease a tad faster. A job well done, $N!', `VerifiedBuild`=59069 WHERE `ID`=28330; -- Trail of Filth
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N. You are incredibly resilient to this blight. We\'ll have to take you in for testing some time.', `VerifiedBuild`=59069 WHERE `ID`=28325; -- Green Living
UPDATE `quest_offer_reward` SET `RewardText`='I will deliver this head to the Banshee Queen personally. Of course I will make mention of your part in all of this, $N.$B$BAs for your reward - take from Stillwater\'s cache whatever you desire. You earned it.', `VerifiedBuild`=59069 WHERE `ID`=28237; -- A Blight Upon the Land
UPDATE `quest_offer_reward` SET `RewardText`='<Lydon takes the key from you.>$B$BI\'ll let myself out, thanks.$B$BI have never been so angry! Stillwater won\'t get away with this. I will present his head to the Banshee Queen myself.$B$BYou and I will work together, $n.$B$BI don\'t know about this one over here, but I\'d prefer he stayed behind.', `VerifiedBuild`=59069 WHERE `ID`=28209; -- Freedom for Lydon
UPDATE `quest_offer_reward` SET `RewardText`='<Johnny is sobbing loudly.>$B$BTw... Twinkles!!!! Th... It killed her!$B$B<Johnny continues to cry>', `VerifiedBuild`=59069 WHERE `ID`=28206; -- A Lost Lad
UPDATE `quest_offer_reward` SET `RewardText`='<Warden Stillwater flips through the journal, reading under his breath.>$B$BRamblings of a mad man! Clearly he had been ingesting the mushrooms. It is good that you brought this to me, $N. I will burn it myself!', `VerifiedBuild`=59069 WHERE `ID`=28196; -- The Battle for Hillsbrad
UPDATE `quest_offer_reward` SET `RewardText`='This should keep it happy and content for a few days. You\'ve done a good thing here, $N!', `VerifiedBuild`=59069 WHERE `ID`=28146; -- Coastal Delicacies!
UPDATE `quest_offer_reward` SET `RewardText`='Just in time, $N!  I was about ready to start digging a hole for our friend here.$B$BMy potion seems to be working; he\'s coming to.$B$BHey, I think he\'s trying to get your attention.  Why don\'t you talk to him?', `VerifiedBuild`=59069 WHERE `ID`=9147; -- The Fallen Courier
UPDATE `quest_offer_reward` SET `RewardText`='Help me, stranger.  I must... reach Tranquillien... I cannot fail.$B$B<The blood elf falls back into unconsciousness as his eyes go blank.>', `VerifiedBuild`=59069 WHERE `ID`=9144; -- Missing in the Ghostlands
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=100, `RewardText`='It is done then.  The foul traitor got what he deserved.$B$BYou\'ve been of great service to the blood elves and to the Horde.  Dar\'Khan was Thrall\'s excuse to deny them entry into our alliance.  You\'ve now cleared the way for a new Horde, $N.$B$BI also see that Lor\'themar has additional news that will greatly improve his relations with the orc Warchief.  Excellent!', `VerifiedBuild`=59069 WHERE `ID`=9812; -- Envoy to the Horde
UPDATE `quest_offer_reward` SET `RewardText`='So you killed Dar\'Khan, $r?  Impressive.  I\'ve a feeling my people and yours will soon get to be very good friends.', `VerifiedBuild`=59069 WHERE `ID`=9811; -- Friend of the Sin'dorei
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=1000, `VerifiedBuild`=59069 WHERE `ID`=9169; -- Deactivate An'owyn
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N.  Without your help those prisoners would\'ve lost their minds and souls to the Scourge.', `VerifiedBuild`=59069 WHERE `ID`=9164; -- Captives at Deatholme
UPDATE `quest_offer_reward` SET `RewardText`='Dar\'Khan\'s armies will soon fall.  The Scourge shall not stand a chance against the combined might of the sin\'dorei and the Forsaken.', `VerifiedBuild`=59069 WHERE `ID`=9170; -- Dar'Khan's Lieutenants
UPDATE `quest_offer_reward` SET `RewardText`='Janeda\'s sending you to rescue the Deatholme prisoners?  She must think very highly of you, $N.', `VerifiedBuild`=59069 WHERE `ID`=9877; -- A Restorative Draught
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=59069 WHERE `ID`=9166; -- Deliver the Plans to An'telas
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=59069 WHERE `ID`=9277; -- Assault on Zeb'Nowa
UPDATE `quest_offer_reward` SET `RewardText`='The Scourge has felt our wrath, $N.  It won\'t be long before their cursed citadel lies in ruins.$B$BWith their numbers weakened, it is time to launch an attack on more strategic targets.', `VerifiedBuild`=59069 WHERE `ID`=9220; -- War on Deatholme
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='My apprentice was unable to take care of this herself?  I shall have a word with her when she returns then, gnolls or not.  Speaking of which, why didn\'t she return with you?$B$B<The magister sighs.>$B$BThat one is a handful, and is going to be quite a challenge to properly train.  Thank you, $c, for bringing these samples to me.  We are hoping that we can uncover some special property from them that will help in the fight against the Scourge.$B$BPlease take this coin as a token of my appreciation.', `VerifiedBuild`=59069 WHERE `ID`=9207; -- Underlight Ore Samples
UPDATE `quest_offer_reward` SET `RewardText`='Thanks for giving me a hand, $N.  I was dreading the thought of venturing into the woods this close to Deatholme.', `VerifiedBuild`=59069 WHERE `ID`=9281; -- Clearing the Way
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59069 WHERE `ID`=9175; -- The Lady's Necklace
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9173; -- Retaking Windrunner Spire
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9163; -- Into Occupied Territory
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=59069 WHERE `ID`=9140; -- Windrunner Village
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9192; -- Trouble at the Underlight Mines
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9160; -- Investigate An'daroth
UPDATE `quest_offer_reward` SET `RewardText`='Not bad, $N.  Keep it up, we could use a few more people like you around here.', `VerifiedBuild`=59069 WHERE `ID`=9155; -- Down the Dead Scar
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9139; -- Goldenmist Village
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='With the rest of my supplies here, I can finally open shop. I\'m sure that the high executor will be most pleased to hear that the war on Dar\'Khan and the Scourge can commence.$B$BAnd, of course, there\'s the small matter of your recompense. Very well, $c, here is the coin that I alluded to. Do be sure to drop by should you find yourself in need of any trade goods.', `VerifiedBuild`=59069 WHERE `ID`=9152; -- Tomber's Supplies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=59069 WHERE `ID`=9171; -- Culinary Crunch
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Disgusting, but necessary I can assure you. You have done us good service by investigating this matter, $c. Please, take this as a token of our generosity and appreciation.', `VerifiedBuild`=59069 WHERE `ID`=9193; -- Investigate the Amani Catacombs
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Mummies being raised by troll priests... clever! The Shadowpine trolls must be trying to bolster their numbers through necromantic means. I\'d wager that these oracles were using the juju in their reanimation ritual.$B$BOnce again you perform your duty as befits a $c of your growing reputation. Take this with our gratitude.', `VerifiedBuild`=59069 WHERE `ID`=9199; -- Troll Juju
UPDATE `quest_offer_reward` SET `RewardText`='Ah... Luzran and Knucklerot!  Not looking so tough anymore, are you?  I can see you\'re still looking ugly as ever.$B$BTake one of these rewards, $N.  You\'ve earned it.', `VerifiedBuild`=59069 WHERE `ID`=9156; -- Wanted: Knucklerot and Luzran
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9276; -- Attack on Zeb'Tela
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve taken your task seriously and thus I\'d like to present you with suitable rewards.  We need more allies with your courage and determination, $N.', `VerifiedBuild`=59069 WHERE `ID`=9159; -- Curbing the Plague
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=59069 WHERE `ID`=9275; -- A Little Dash of Seasoning
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ah, Kel\'gash\'s head is what smelled so bad. That\'s a nice piece of work there, $c!$B$BWith their chieftain dead, the Shadowpine trolls should be in total disarray. Combined with your recent efforts to decimate their numbers, this should be the perfect opportunity to launch our counter-offensive against them and wipe them out for good.$B$BYou have my thanks, $N. Might I interest you in one of these?', `VerifiedBuild`=59069 WHERE `ID`=9215; -- Bring Me Kel'gash's Head!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9214; -- Shadowpine Weaponry
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You\'re quite the $g hero : heroine;, $c, to get her out of there alive.  I suppose we\'ll have to mount an offensive to clear out those catacombs too.  As if we didn\'t have enough trouble with the living trolls!$B$BYou\'ve done a great thing today, I should reward you.  Take your pick from any of these.', `VerifiedBuild`=59069 WHERE `ID`=9212; -- Escape from the Catacombs
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='That\'s dire news indeed -- I completely overestimated Tomathren\'s ability to lead.  I\'ll see to it that a group is dispatched to safely bring him and Valanna back in.$B$BUnfortunately, we never heard from Ranger Salissa, so I fear the worst in her case.$B$BYou\'ve done the Farstriders a great service this day, $c.  Please take one of these as a small token of our appreciation.', `VerifiedBuild`=59069 WHERE `ID`=9146; -- Report to Captain Helios
UPDATE `quest_offer_reward` SET `RewardText`='I appreciate your help, $N.  It pains me to see the spirits of my ancestors in their pitiful state.  May they finally get the rest they deserve.', `VerifiedBuild`=59069 WHERE `ID`=9274; -- Spirits of the Drowned
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9315; -- Anok'suten
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9138; -- Suncrown Village
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9143; -- Dealing with Zeb'Sora
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve avenged our deaths and broken Aquantion\'s grasp on our souls.  We may finally rest.', `VerifiedBuild`=59069 WHERE `ID`=9174; -- Vanquishing Aquantion
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  It\'s important that the plague doesn\'t spread to the healthy wildlife in Eversong.  I have more work for you if you\'re looking for something to do.', `VerifiedBuild`=59069 WHERE `ID`=9158; -- Bearers of the Plague
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59069 WHERE `ID`=9758; -- Return to Arcanist Vandril
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `RewardText`='We Forsaken are here because of a common enemy with the blood elves: Dar\'Khan!  He has returned and now commands the Scourge that are invading this land from his steadfast, Deatholme, to the south.$B$BLady Sylvanas Windrunner, who originally hails from these lands, and used to be an elf, has a history with Dar\'Khan and wants him dead!$B$BWe will defeat him, $c, and you will help us do it!', `VerifiedBuild`=59069 WHERE `ID`=9329; -- The Forsaken
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  Are you certain you haven\'t done this before?', `VerifiedBuild`=58558 WHERE `ID`=27389; -- Marauders of Darrowshire
UPDATE `quest_offer_reward` SET `RewardText`='The sooner those Scourge are pushed out of the Fungal Vale, the sooner we can heal it.$b$bThank you, $N.', `VerifiedBuild`=58558 WHERE `ID`=27420; -- Postponing the Inevitable
UPDATE `quest_offer_reward` SET `RewardText`='It should take them weeks to get their operation running again.  Thank you, $N.', `VerifiedBuild`=58558 WHERE `ID`=27454; -- Just a Drop in the Bucket
UPDATE `quest_offer_reward` SET `RewardText`='You are well on your way to becoming a true champion of the Light, $N.  Well done.', `VerifiedBuild`=58558 WHERE `ID`=27615; -- The Wrathcaster
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  I will deliver these to Tyrosus when we return.', `VerifiedBuild`=58558 WHERE `ID`=27614; -- Scarlet Salvage
UPDATE `quest_offer_reward` SET `RewardText`='<Eitrigg looks over the devastation below.>$b$bOur job is almost done, $N.  It\'s time to deliver the deathblow.', `VerifiedBuild`=58558 WHERE `ID`=28454; -- Assault on Dreadmaul Rock
UPDATE `quest_offer_reward` SET `RewardText`='$N\'s here!  We can get started.$b$bThis is our big moment, $N.  I hope you are prepared.', `VerifiedBuild`=58558 WHERE `ID`=28453; -- Locked and Loaded
UPDATE `quest_offer_reward` SET `RewardText`='Good, you\'re back.$b$bI hope you\'ve still got that disguise.  You\'re going back undercover, $N.', `VerifiedBuild`=58558 WHERE `ID`=28449; -- Placing the Pawns
UPDATE `quest_offer_reward` SET `RewardText`='Your kill count is adding up, $N.  We\'re chipping away at them.$b$bAnd we are going to win.', `VerifiedBuild`=58558 WHERE `ID`=28447; -- Draconic Vanguard
UPDATE `quest_offer_reward` SET `RewardText`='This meat looks good... but I think it needs a little \"seasoning\".  I\'ll make sure that gets taken care of.$b$bThank you, $N.', `VerifiedBuild`=58558 WHERE `ID`=28445; -- A Heap of Delicious Worg
UPDATE `quest_offer_reward` SET `RewardText`='Are you alright?$b$bGood.  You were strong out there, $N.  Strong, and wise.$b$bNow pack up your things.  We\'re moving out of here.', `VerifiedBuild`=58558 WHERE `ID`=28441; -- Enough Damage For One Day
UPDATE `quest_offer_reward` SET `RewardText`='Without those sergeants, Thorg\'izog will be hard-pressed getting his troops ready for battle.$b$bAlready the dominoes are beginning to fall, $N.', `VerifiedBuild`=58558 WHERE `ID`=28440; -- Abuse of Power
UPDATE `quest_offer_reward` SET `RewardText`='Yer a lifesaver, $N.  With golems like these, we won\'t have to worry about Dark Irons, Blackrock orcs... maybe even dragons!$b$bIf ye ever need anything from the Thorium Brotherhood, don\'t hesitate to ask.  That goes for yer friends, too.', `VerifiedBuild`=58558 WHERE `ID`=28227; -- Golem Training
UPDATE `quest_offer_reward` SET `RewardText`='This is exactly what we need.$b$bDon\'t worry, $N... the killing will come soon enough.', `VerifiedBuild`=58558 WHERE `ID`=28421; -- Mud Hunter
UPDATE `quest_offer_reward` SET `RewardText`='Believe me, $N... I\'m just as anxious to get to the killing as you are.  We\'ve got to keep to the plan.  The armageddon will come soon enough.$b$bI\'ll keep these hides here.', `VerifiedBuild`=58558 WHERE `ID`=28420; -- A Future Project
UPDATE `quest_offer_reward` SET `RewardText`='Hopefully, with this druid out of the picture, we can get back to our digging.  The world is full of powerful artifacts, $N.  You just need to be willing to do what it takes to get to them.$b$bFeel free to take one of these.  The Reliquary is always happy to share some of its trove with fellow members of the Horde.', `VerifiedBuild`=58558 WHERE `ID`=25720; -- The Downfall of Marl Wormthorn
UPDATE `quest_offer_reward` SET `RewardText`='Brilliantly done, $N.  We have what we need to break the worgen\'s trance.', `VerifiedBuild`=58558 WHERE `ID`=25719; -- Demoniac Vessel
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.$b$bI should be a bit more up-front with you.  The demons were a nuisance, but they are not the real problem.  That worgen druid is our problem.', `VerifiedBuild`=58558 WHERE `ID`=25717; -- The Demons and the Druid
UPDATE `quest_offer_reward` SET `RewardText`='These are perfect, $N.  Lynnore and I will eat well for the next several days.', `VerifiedBuild`=58558 WHERE `ID`=25690; -- A Bloodmage's Gotta Eat Too
UPDATE `quest_offer_reward` SET `RewardText`='I think you\'re ready, $N.  You\'re getting the hang of this.', `VerifiedBuild`=58558 WHERE `ID`=27892; -- Jurrix the Striker
UPDATE `quest_offer_reward` SET `RewardText`='<Myzrael speaks through the stone.>$B$BYou have done it!  You opened the Stones of Binding!  I can feel the shackles about me loosen, and freedom draws ever closer.$B$BYou are a noble $c, $N.  My rescuer!', `VerifiedBuild`=59069 WHERE `ID`=26041; -- Stones of Binding
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=59069 WHERE `ID`=6622; -- Triage

DELETE FROM `quest_greeting` WHERE `ID` IN (45878, 1938, 45474, 49243, 10926) AND `Type`=0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(45878, 0, 1, 0, 'This better be important.', 59069), -- Lord Godfrey
(1938, 0, 0, 0, 'They say that I was named after the magical city of Dalaran. I say that they named Dalaran after me!', 59069), -- Dalar Dawnweaver
(45474, 0, 1, 0, 'Our mission is clear. We must not fail.', 59069), -- Deathstalker Commander Belmont
(49243, 0, 6, 0, 'What brings you to Eastpoint Tower?', 59069), -- Captain Jekyll
(10926, 0, 0, 0, 'I never feel warm anymore...', 58558); -- Pamela Redpath

DELETE FROM `quest_details` WHERE `ID` IN (27144 /*The Reckoning*/, 27090 /*Andorhal, Once and For All*/, 27089 /*Ace in the Hole*/, 27087 /*Lindsay Ravensun, Revealed*/, 27085 /*Supporting the Troops*/, 27086 /*Ashes to Ashes*/, 27084 /*The Farmers' Militia*/, 27083 /*The Battle Resumes!*/, 26938 /*Combat Training*/, 26937 /*When Death is Not Enough*/, 26952 /*The Menders' Stead*/, 26979 /*Strange New Faces*/, 26978 /*Who Needs Cauldrons?*/, 26933 /*Foes Before Hoes*/, 26930 /*After the Crusade*/, 26934 /*Latent Disease*/, 26931 /*Foxes and Hounds*/, 26926 /*Victory, For Now*/, 26925 /*Araj the Summoner*/, 27117 /*Brute Strength*/, 26924 /*Scholomancer*/, 26923 /*War Machines*/, 26921 /*Scourge First... Alliance Later*/, 26922 /*The Endless Flow*/, 28750 /*The Battle for Andorhal*/, 26555 /*High Priest Venoxis*/, 26554 /*Plunging Into Zul'Gurub*/, 26553 /*High Priestess Jeklik*/, 26552 /*Through the Troll Hole*/, 26535 /*Recipe for Disaster*/, 26551 /*Eliminate the Outcast*/, 26534 /*Let's See What You've Got, Zanzil*/, 26435 /*I'm A Huge Liar and a Fraud*/, 26550 /*Backdoor Dealings*/, 26533 /*Zanzil's Secret*/, 26495 /*Chabal*/, 26494 /*Mixmaster Jasper*/, 26592 /*Diffractory Chromascope*/, 26434 /*Primal Reagents of Power*/, 26493 /*There's Somebody Out There Who Wants It*/, 26433 /*The Holy Water of Clarity*/, 26450 /*If They're Just Going to Leave Them Lying Around...*/, 26487 /*Akiris by the Bundle*/, 8553 /*Okrilla and the Blasted Lands*/, 27916 /*Ruag's Report*/, 27911 /*With Dying Breath*/, 27910 /*Last Regrets*/, 27909 /*The Purespring*/, 27907 /*Prayerblossom*/, 27908 /*Secrets of the Mire*/, 27906 /*Neeka Bloodscar*/, 27857 /*We're Under Attack!*/, 27856 /*Marking the Fallen*/, 27855 /*Reinforcements Denied*/, 27854 /*Tides of Darkness*/, 27853 /*Lumbering Oafs*/, 27852 /*Orcs and Humans*/, 27871 /*To Stonard*/, 28096 /*Welcome to the Machine*/, 27423 /*Resistance is Futile*/, 28515 /*Mouton Flamestar*/, 26301 /*Speaking with Nezzliok*/, 26332 /*Skullsplitter Mojo*/, 26338 /*Population Con-Troll*/, 26340 /*The Hunt*/, 26330 /*Who's a Big Troll?*/, 26300 /*Nezzliok Will Know*/, 9457 /*An Unusual Patron*/, 26325 /*A Nose for This Sort of Thing*/, 26299 /*Headhunting*/, 26323 /*Favored Skull*/, 26298 /*Hunt for Yenniku*/, 26281 /*The Defense of Grom'gol: Trollish Thievery*/, 26407 /*Mosh'Ogg Handiwork*/, 26321 /*I Think She's Hungry*/, 26280 /*The Defense of Grom'gol: Murloc Menace*/, 26279 /*The Defense of Grom'gol: Ogre Oppression*/, 26317 /*A Lashtail Hatchling*/, 26278 /*The Defense of Grom'gol: Raptor Risk*/, 26386 /*Surkhan*/, 26362 /*Be Raptor*/, 26304 /*Nighttime in the Jungle*/, 26352 /*Cozzle's Plan*/, 26405 /*Zul'Mamwe Mambo*/, 26360 /*Mind Control*/, 26359 /*See Raptor*/, 26305 /*Saving Yenniku*/, 26403 /*Venture Company Mining*/, 26400 /*The Universal Key*/, 26303 /*The Mind's Eye*/, 26351 /*Mind Vision*/, 26404 /*Above My Pay Grade*/, 26399 /*The Mosh'Ogg Bounty*/, 26350 /*Priestess Hu'rala*/, 26334 /*Bloodlord Mandokir*/, 26302 /*Chasing Yenniku's Fate*/, 26419 /*Shadra the Venom Queen*/, 26558 /*Summoning Shadra*/, 26418 /*The Shell of Shadra*/, 26387 /*Starvation Diet*/, 26406 /*The Fang of Shadra*/, 26381 /*The Eye of Shadra*/, 26384 /*Darkcleric Marnal*/, 26369 /*Hunt the Keeper*/, 26363 /*Summit of Fate*/, 26368 /*Venomous Secrets*/, 26309 /*Dark Vessels*/, 26308 /*It's Ours Now*/, 26367 /*Ongo'longo's Revenge*/, 26307 /*Death to the Vilebranch*/, 26310 /*All That Skitters*/, 26357 /*Faces of Evil*/, 26366 /*Heads Up*/, 26306 /*Start Taking Back*/, 26432 /*The Fall of Jintha'Alor*/, 26283 /*Prime Slime*/, 26268 /*Skulk Rock Supplies*/, 26267 /*Skulk Rock Clean-Up*/, 26224 /*Hunt the Savages*/, 26240 /*Stomp To My Beat*/, 26988 /*Moving Things Along*/, 26987 /*The Right Way*/, 26223 /*Stalking the Stalkers*/, 26263 /*Thornar Thunderclash*/, 26238 /*The Savage Dwarves*/, 26212 /*Lard Lost His Lunch*/, 26211 /*Snapjaws, Mon!*/, 26210 /*Gammerita, Mon!*/, 28647 /*The Durnholde Challenge: D-1000*/, 28646 /*The Durnholde Challenge: Infernus*/, 28645 /*The Durnholde Challenge: Bloodvenom*/, 28644 /*The Durnholde Challenge: Teracula*/, 28636 /*Silence of the Dwarves*/, 28634 /*Extinction*/, 28643 /*The Durnholde Challenge: Zephyrus*/, 28635 /*A Haunting in Hillsbrad*/, 28616 /*Stormpike Apocalypse*/, 28605 /*Domination*/, 28604 /*Deception and Trickery*/, 28603 /*Infiltration*/, 28566 /*Decimation*/, 28538 /*Cry of the Banshee*/, 28556 /*Breaking the Hand*/, 28506 /*March of the Stormpike*/, 7124 /*Capture a Mine*/, 7101 /*Towers and Bunkers*/, 7082 /*The Graveyards of Alterac*/, 7161 /*Proving Grounds*/, 28600 /*Matters of Loyalty*/, 7142 /*The Battle for Alterac*/, 28495 /*A Fighting Chance*/, 28485 /*Yetimus the Yeti Lord*/, 28487 /*Humbert's Personal Problems*/, 28484 /*The Heart of the Matter*/, 28587 /*Aid of the Frostwolf*/, 28489 /*Stagwiches*/, 28620 /*Eastpoint Tower*/, 28400 /*Heroes of the Horde!*/, 28397 /*They Will Never Expect This...*/, 28375 /*The Road to Purgation*/, 28355 /*Terrible Little Creatures*/, 28356 /*Preemptive Strike*/, 28330 /*Trail of Filth*/, 28354 /*Kasha Will Fly Again*/, 28348 /*Stormpike Rendezvous*/, 28345 /**Gurgle* HELP! *Gurgle**/, 28329 /*Angry Scrubbing Bubbles*/, 28344 /*Can You Smell What the Lok'tar is Cooking?*/, 28332 /*Helcular's Command*/, 28331 /*Helcular's Rod Giveth...*/, 28324 /*Studies in Lethality*/, 28325 /*Green Living*/, 28251 /*Trouble at Southshore*/, 28237 /*A Blight Upon the Land*/, 28235 /*Burnside Must Fall*/, 28231 /*Do it for Twinkles*/, 28230 /*Protocol*/, 28209 /*Freedom for Lydon*/, 28206 /*A Lost Lad*/, 28189 /*Do the Right Thing*/, 28196 /*The Battle for Hillsbrad*/, 28199 /*For Science!*/, 28197 /*Discretion is Key*/, 28192 /*No One Here Gets Out Alive*/, 28168 /*Trouble at the Sludge Fields*/, 28154 /*Muckgill's Flipper or Something...*/, 28156 /*Deep Mine Rescue*/, 28146 /*Coastal Delicacies!*/, 28144 /*Thieving Little Monsters!*/, 28138 /*Human Infestation*/, 28115 /*Past Their Prime*/, 28114 /*Glorious Harvest*/, 28111 /*Trouble at Azurelode*/, 28096 /*Welcome to the Machine*/, 495 /*The Crown of Will*/, 26867 /*Enemies Below*/, 9813 /*Meeting the Warchief*/, 9812 /*Envoy to the Horde*/, 9811 /*Friend of the Sin'dorei*/, 9167 /*The Traitor's Destruction*/, 9164 /*Captives at Deatholme*/, 9176 /*The Twin Ziggurats*/, 9169 /*Deactivate An'owyn*/, 9172 /*Report to Magister Kaendris*/, 9162 /*Hints of the Past*/, 9877 /*A Restorative Draught*/, 9170 /*Dar'Khan's Lieutenants*/, 9177 /*Journey to Undercity*/, 9166 /*Deliver the Plans to An'telas*/, 9175 /*The Lady's Necklace*/, 9163 /*Into Occupied Territory*/, 9281 /*Clearing the Way*/, 9207 /*Underlight Ore Samples*/, 9140 /*Windrunner Village*/, 9160 /*Investigate An'daroth*/, 9220 /*War on Deatholme*/, 9277 /*Assault on Zeb'Nowa*/, 9159 /*Curbing the Plague*/, 9274 /*Spirits of the Drowned*/, 9315 /*Anok'suten*/, 9758 /*Return to Arcanist Vandril*/, 9329 /*The Forsaken*/, 28456 /*The Spoils of War*/, 28455 /*Glory Amidst Chaos*/, 28454 /*Assault on Dreadmaul Rock*/, 28453 /*Locked and Loaded*/, 28452 /*A Delivery for Xi'lun*/, 28451 /*A Delivery for Neeralak*/, 28450 /*A Delivery for Thorg'izog*/, 28449 /*Placing the Pawns*/, 28448 /*A Deal With a Dragon*/, 28447 /*Draconic Vanguard*/, 28446 /*Blood Tour*/, 28445 /*A Heap of Delicious Worg*/, 28443 /*Blackened Ashes*/, 28444 /*Latent Demons of the Land*/, 28570 /*The Bogpaddle Bullet*/, 28491 /*Not Fireflies, Flameflies*/, 28442 /*Flame Crest*/, 28441 /*Enough Damage For One Day*/, 28440 /*Abuse of Power*/, 28439 /*I Am the Law and I Am the Lash*/, 28438 /*Trial by Magma*/, 28437 /*General Thorg'izog*/, 28436 /*Taking the Horn For Ourselves*/, 28435 /*The Kodocaller's Horn*/, 28434 /*Strategic Cuts*/, 28433 /*Grunt Work*/, 28432 /*Into the Black Tooth Hovel*/, 28428 /*A Perfect Costume*/, 28427 /*A Needle in a Hellhole*/, 28426 /*Chiselgrip, the Heart of the Steppes*/, 28425 /*Return to Ariok*/, 28424 /*Shadow Boxing*/, 28423 /*Warlocks Have the Neatest Stuff*/, 28422 /*The Sand, the Cider, and the Orb*/, 28421 /*Mud Hunter*/, 28420 /*A Future Project*/, 28419 /*Stocking Up*/, 28418 /*Burning Vengeance*/, 28417 /*Done Nothing Wrong*/, 25682 /*Mission Complete*/, 25681 /*Some People Just Need Killing*/, 25680 /*That's Not Us*/, 25679 /*Into the Mountain*/, 25678 /*Pick Your Fate*/, 25677 /*It's All Mine*/, 25675 /*Ogre Combat*/, 25676 /*Heartstrike*/, 25674 /*Futile Pride*/, 25720 /*The Downfall of Marl Wormthorn*/, 25719 /*Demoniac Vessel*/, 25718 /*How Best to Proceed*/, 25717 /*The Demons and the Druid*/, 25701 /*You Are Rakh'likh, Demon*/, 25700 /*Loramus Thalipedes Awaits*/, 25699 /*The Amulet of Grol*/, 25697 /*The Amulet of Allistarj*/, 25698 /*The Amulet of Sevine*/, 25696 /*The Sunveil Excursion*/, 25695 /*Watching Our Back*/, 25693 /*Enhancing the Stone*/, 25694 /*Protecting Our Rear*/, 25692 /*The Vile Blood of Demons*/, 25691 /*The Charred Granite of the Dark Portal*/, 25689 /*Time is Short*/, 25688 /*The Altar of Storms*/, 25687 /*Not Just Any Body*/, 25686 /*Blood Ritual*/, 25690 /*A Bloodmage's Gotta Eat Too*/, 25685 /*The First Step*/, 25684 /*Attune the Bloodstone*/, 25683 /*The Dreadmaul Furnace*/, 25682 /*Mission Complete*/, 27898 /*Rheastrasza's Gift*/, 27897 /*The Hidden Clutch*/, 27896 /*The Sorrow and the Fury*/, 27895 /*Their Hunt Continues*/, 27894 /*The Wrath of a Dragonflight*/, 27893 /*Gargal, the Behemoth*/, 27892 /*Jurrix the Striker*/, 27891 /*Amakkar, Jack of All Trades*/, 27879 /*Survival of the Fattest*/, 27890 /*The Bad Dogs*/, 27880 /*Half-Ton Holdouts*/, 27889 /*New Kargath*/, 27888 /*Return to Blam*/, 27913 /*The Titans' Trove*/, 27887 /*Ancient Protectors*/, 27885 /*The Warden's Game*/, 27886 /*The Sentinel's Game*/, 27884 /*The Sentinel's Pawn*/, 27883 /*The Warden's Pawn*/, 27882 /*It's Not About History, It's About Power*/, 27881 /*Bloodwatcher Point*/, 27877 /*The Morons' League*/, 27878 /*Forcible Acquisition*/, 26027 /*Call to Arms*/, 26030 /*Sigil of Strom*/, 26025 /*The Traitor Orc*/, 26023 /*The Forsaken Trollbane*/, 26053 /*Clearing the Highlands*/, 26022 /*First Blood*/, 26912 /*The Princess Unleashed*/, 26911 /*Myzrael's Tale*/, 26108 /*Guile of the Raptor*/, 6622 /*Triage*/, 26986 /*Into the Scarlet Monastery*/, 26430 /*Revantusk Village*/, 26429 /*Crush the Witherbark*/, 26107 /*Raising Spirits*/, 26083 /*Hello Lolo*/, 26084 /*Hammerfall*/, 26081 /*Alina's Reward*/, 26033 /*Trol'kalar*/, 26032 /*Sigil of Arathor*/, 26029 /*The Real Threat*/, 26031 /*Sigil of Thoradin*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27144, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Reckoning
(27090, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Andorhal, Once and For All
(27089, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Ace in the Hole
(27087, 397, 396, 0, 0, 0, 0, 0, 0, 58558), -- Lindsay Ravensun, Revealed
(27085, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Supporting the Troops
(27086, 397, 396, 0, 0, 0, 0, 0, 0, 58558), -- Ashes to Ashes
(27084, 396, 396, 396, 0, 0, 0, 0, 0, 58558), -- The Farmers' Militia
(27083, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Battle Resumes!
(26938, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Combat Training
(26937, 1, 1, 22, 0, 0, 0, 0, 0, 58558), -- When Death is Not Enough
(26952, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Menders' Stead
(26979, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Strange New Faces
(26978, 6, 22, 1, 0, 0, 0, 0, 0, 58558), -- Who Needs Cauldrons?
(26933, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Foes Before Hoes
(26930, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- After the Crusade
(26934, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Latent Disease
(26931, 1, 5, 1, 0, 0, 0, 0, 0, 58558), -- Foxes and Hounds
(26926, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- Victory, For Now
(26925, 1, 5, 0, 0, 0, 0, 0, 0, 58558), -- Araj the Summoner
(27117, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- Brute Strength
(26924, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- Scholomancer
(26923, 1, 1, 397, 0, 0, 0, 0, 0, 58558), -- War Machines
(26921, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Scourge First... Alliance Later
(26922, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Endless Flow
(28750, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Battle for Andorhal
(26555, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- High Priest Venoxis
(26554, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Plunging Into Zul'Gurub
(26553, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- High Priestess Jeklik
(26552, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Through the Troll Hole
(26535, 5, 0, 0, 0, 0, 0, 0, 0, 58558), -- Recipe for Disaster
(26551, 25, 396, 2, 0, 0, 0, 0, 0, 58558), -- Eliminate the Outcast
(26534, 1, 432, 432, 1, 0, 0, 0, 0, 58558), -- Let's See What You've Got, Zanzil
(26435, 18, 24, 1, 0, 0, 0, 0, 0, 58558), -- I'm A Huge Liar and a Fraud
(26550, 66, 396, 396, 0, 0, 0, 0, 0, 58558), -- Backdoor Dealings
(26533, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Zanzil's Secret
(26495, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Chabal
(26494, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Mixmaster Jasper
(26592, 397, 396, 5, 0, 0, 0, 0, 0, 58558), -- Diffractory Chromascope
(26434, 397, 396, 5, 0, 0, 0, 0, 0, 58558), -- Primal Reagents of Power
(26493, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- There's Somebody Out There Who Wants It
(26433, 396, 397, 396, 0, 0, 0, 0, 0, 58558), -- The Holy Water of Clarity
(26450, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- If They're Just Going to Leave Them Lying Around...
(26487, 6, 1, 1, 0, 0, 0, 0, 0, 58558), -- Akiris by the Bundle
(27916, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Ruag's Report
(27911, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- With Dying Breath
(27910, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Last Regrets
(27909, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Purespring
(27907, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Prayerblossom
(27908, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Secrets of the Mire
(27906, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Neeka Bloodscar
(27857, 25, 0, 0, 0, 0, 0, 0, 0, 58558), -- We're Under Attack!
(27856, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Marking the Fallen
(27855, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Reinforcements Denied
(27854, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Tides of Darkness
(27853, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Lumbering Oafs
(27852, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Orcs and Humans
(27871, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- To Stonard
(27423, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Resistance is Futile
(28515, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Mouton Flamestar
(26301, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Speaking with Nezzliok
(26332, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Skullsplitter Mojo
(26338, 396, 396, 396, 0, 0, 0, 0, 0, 58558), -- Population Con-Troll
(26340, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Hunt
(26330, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Who's a Big Troll?
(26300, 396, 396, 396, 0, 0, 0, 0, 0, 58558), -- Nezzliok Will Know
(9457, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- An Unusual Patron
(26325, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- A Nose for This Sort of Thing
(26299, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Headhunting
(26323, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Favored Skull
(26298, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Hunt for Yenniku
(26281, 396, 396, 396, 113, 0, 0, 0, 0, 58558), -- The Defense of Grom'gol: Trollish Thievery
(26407, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Mosh'Ogg Handiwork
(26321, 396, 0, 0, 0, 0, 0, 0, 0, 58558), -- I Think She's Hungry
(26280, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- The Defense of Grom'gol: Murloc Menace
(26279, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- The Defense of Grom'gol: Ogre Oppression
(26317, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- A Lashtail Hatchling
(26278, 113, 396, 396, 0, 0, 0, 0, 0, 58558), -- The Defense of Grom'gol: Raptor Risk
(26386, 94, 273, 94, 0, 0, 500, 500, 0, 58558), -- Surkhan
(26362, 94, 273, 94, 0, 0, 500, 500, 0, 58558), -- Be Raptor
(26304, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Nighttime in the Jungle
(26352, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Cozzle's Plan
(26405, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- Zul'Mamwe Mambo
(26360, 94, 273, 94, 0, 0, 500, 500, 0, 58558), -- Mind Control
(26359, 94, 273, 94, 0, 0, 500, 500, 0, 58558), -- See Raptor
(26305, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Saving Yenniku
(26403, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Venture Company Mining
(26400, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Universal Key
(26303, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Mind's Eye
(26351, 94, 273, 94, 0, 0, 500, 500, 0, 58558), -- Mind Vision
(26404, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Above My Pay Grade
(26399, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Mosh'Ogg Bounty
(26350, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Priestess Hu'rala
(26334, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Bloodlord Mandokir
(26302, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Chasing Yenniku's Fate
(26419, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Shadra the Venom Queen
(26558, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Summoning Shadra
(26418, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Shell of Shadra
(26387, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Starvation Diet
(26406, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Fang of Shadra
(26381, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Eye of Shadra
(26384, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Darkcleric Marnal
(26369, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Hunt the Keeper
(26363, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Summit of Fate
(26368, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Venomous Secrets
(26309, 1, 1, 1, 1, 0, 0, 0, 0, 59069), -- Dark Vessels
(26308, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- It's Ours Now
(26367, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Ongo'longo's Revenge
(26307, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Death to the Vilebranch
(26310, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- All That Skitters
(26357, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Faces of Evil
(26366, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Heads Up
(26306, 25, 0, 0, 0, 0, 0, 0, 0, 59069), -- Start Taking Back
(26432, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Fall of Jintha'Alor
(26283, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Prime Slime
(26268, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Skulk Rock Supplies
(26267, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Skulk Rock Clean-Up
(26224, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Hunt the Savages
(26240, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Stomp To My Beat
(26988, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- Moving Things Along
(26987, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- The Right Way
(26223, 1, 1, 5, 0, 0, 0, 0, 0, 59069), -- Stalking the Stalkers
(26263, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Thornar Thunderclash
(26238, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Savage Dwarves
(26212, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Lard Lost His Lunch
(26211, 1, 1, 1, 5, 0, 0, 0, 0, 59069), -- Snapjaws, Mon!
(26210, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Gammerita, Mon!
(28647, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Durnholde Challenge: D-1000
(28646, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Durnholde Challenge: Infernus
(28645, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Durnholde Challenge: Bloodvenom
(28644, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- The Durnholde Challenge: Teracula
(28636, 1, 274, 1, 273, 0, 0, 0, 0, 59069), -- Silence of the Dwarves
(28634, 1, 1, 273, 5, 0, 0, 0, 0, 59069), -- Extinction
(28643, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- The Durnholde Challenge: Zephyrus
(28635, 1, 1, 6, 0, 0, 0, 0, 0, 59069), -- A Haunting in Hillsbrad
(28616, 1, 273, 16, 15, 0, 0, 0, 0, 59069), -- Stormpike Apocalypse
(28605, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Domination
(28604, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- Deception and Trickery
(28603, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Infiltration
(28566, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Decimation
(28538, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Cry of the Banshee
(28556, 1, 25, 1, 1, 0, 0, 0, 0, 59069), -- Breaking the Hand
(28506, 1, 1, 1, 1, 0, 0, 0, 0, 59069), -- March of the Stormpike
(7124, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Capture a Mine
(7101, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Towers and Bunkers
(7082, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Graveyards of Alterac
(7161, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Proving Grounds
(28600, 274, 1, 1, 0, 0, 0, 0, 0, 59069), -- Matters of Loyalty
(7142, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Battle for Alterac
(28495, 5, 1, 1, 0, 0, 0, 0, 0, 59069), -- A Fighting Chance
(28485, 1, 1, 5, 1, 0, 0, 0, 0, 59069), -- Yetimus the Yeti Lord
(28487, 24, 1, 6, 273, 0, 0, 0, 0, 59069), -- Humbert's Personal Problems
(28484, 274, 1, 1, 0, 0, 0, 0, 0, 59069), -- The Heart of the Matter
(28587, 1, 1, 5, 15, 0, 0, 0, 0, 59069), -- Aid of the Frostwolf
(28489, 6, 274, 1, 273, 0, 0, 0, 0, 59069), -- Stagwiches
(28620, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Eastpoint Tower
(28400, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Heroes of the Horde!
(28397, 1, 1, 274, 5, 0, 0, 0, 0, 59069), -- They Will Never Expect This...
(28375, 273, 1, 1, 0, 0, 0, 0, 0, 59069), -- The Road to Purgation
(28355, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Terrible Little Creatures
(28356, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Preemptive Strike
(28330, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Trail of Filth
(28354, 1, 20, 273, 1, 0, 0, 0, 0, 59069), -- Kasha Will Fly Again
(28348, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Stormpike Rendezvous
(28345, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- *Gurgle* HELP! *Gurgle*
(28329, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Angry Scrubbing Bubbles
(28344, 1, 6, 1, 273, 0, 0, 0, 0, 59069), -- Can You Smell What the Lok'tar is Cooking?
(28332, 1, 1, 1, 5, 0, 0, 0, 0, 59069), -- Helcular's Command
(28331, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Helcular's Rod Giveth...
(28324, 1, 273, 1, 1, 0, 0, 0, 0, 59069), -- Studies in Lethality
(28325, 1, 1, 1, 1, 0, 0, 0, 0, 59069), -- Green Living
(28251, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Trouble at Southshore
(28237, 1, 1, 25, 0, 0, 0, 0, 0, 59069), -- A Blight Upon the Land
(28235, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Burnside Must Fall
(28231, 396, 396, 396, 15, 0, 0, 0, 0, 59069), -- Do it for Twinkles
(28230, 1, 1, 5, 0, 0, 0, 0, 0, 59069), -- Protocol
(28209, 5, 1, 5, 0, 0, 0, 0, 0, 59069), -- Freedom for Lydon
(28206, 1, 1, 1, 20, 0, 0, 0, 0, 59069), -- A Lost Lad
(28189, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Do the Right Thing
(28196, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Battle for Hillsbrad
(28199, 1, 1, 11, 11, 0, 0, 0, 0, 59069), -- For Science!
(28197, 5, 6, 1, 25, 0, 0, 0, 0, 59069), -- Discretion is Key
(28192, 1, 6, 274, 5, 0, 0, 0, 0, 59069), -- No One Here Gets Out Alive
(28168, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Trouble at the Sludge Fields
(28154, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Muckgill's Flipper or Something...
(28156, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Deep Mine Rescue
(28146, 1, 1, 5, 0, 0, 0, 0, 0, 59069), -- Coastal Delicacies!
(28144, 1, 1, 5, 0, 0, 0, 0, 0, 59069), -- Thieving Little Monsters!
(28138, 1, 1, 1, 1, 0, 0, 0, 0, 59069), -- Human Infestation
(28115, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Past Their Prime
(28114, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Glorious Harvest
(28111, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Trouble at Azurelode
(28096, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Welcome to the Machine
(495, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Crown of Will
(26867, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Enemies Below
(9813, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Meeting the Warchief
(9812, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Envoy to the Horde
(9811, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Friend of the Sin'dorei
(9167, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Traitor's Destruction
(9164, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Captives at Deatholme
(9176, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Twin Ziggurats
(9169, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Deactivate An'owyn
(9172, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Report to Magister Kaendris
(9162, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Hints of the Past
(9877, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- A Restorative Draught
(9170, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Dar'Khan's Lieutenants
(9177, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Journey to Undercity
(9166, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Deliver the Plans to An'telas
(9175, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Lady's Necklace
(9163, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Into Occupied Territory
(9281, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Clearing the Way
(9207, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Underlight Ore Samples
(9140, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Windrunner Village
(9160, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Investigate An'daroth
(9220, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- War on Deatholme
(9277, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Assault on Zeb'Nowa
(9159, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Curbing the Plague
(9274, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Spirits of the Drowned
(9315, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Anok'suten
(9758, 1, 1, 0, 0, 0, 1000, 0, 0, 59069), -- Return to Arcanist Vandril
(9329, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Forsaken
(28456, 1, 1, 2, 0, 0, 0, 0, 0, 58558), -- The Spoils of War
(28455, 1, 1, 4, 0, 0, 0, 0, 0, 58558), -- Glory Amidst Chaos
(28454, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Assault on Dreadmaul Rock
(28453, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Locked and Loaded
(28452, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- A Delivery for Xi'lun
(28451, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- A Delivery for Neeralak
(28450, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- A Delivery for Thorg'izog
(28449, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Placing the Pawns
(28448, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- A Deal With a Dragon
(28447, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Draconic Vanguard
(28446, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Blood Tour
(28445, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- A Heap of Delicious Worg
(28443, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Blackened Ashes
(28444, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Latent Demons of the Land
(28570, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Bogpaddle Bullet
(28491, 1, 1, 1, 1, 0, 0, 0, 0, 58558), -- Not Fireflies, Flameflies
(28442, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Flame Crest
(28441, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Enough Damage For One Day
(28440, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Abuse of Power
(28439, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- I Am the Law and I Am the Lash
(28438, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Trial by Magma
(28437, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- General Thorg'izog
(28436, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Taking the Horn For Ourselves
(28435, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Kodocaller's Horn
(28434, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Strategic Cuts
(28433, 5, 397, 0, 0, 0, 0, 0, 0, 58558), -- Grunt Work
(28432, 1, 1, 22, 0, 0, 0, 0, 0, 58558), -- Into the Black Tooth Hovel
(28428, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- A Perfect Costume
(28427, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- A Needle in a Hellhole
(28426, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Chiselgrip, the Heart of the Steppes
(28425, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Return to Ariok
(28424, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Shadow Boxing
(28423, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Warlocks Have the Neatest Stuff
(28422, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Sand, the Cider, and the Orb
(28421, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Mud Hunter
(28420, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- A Future Project
(28419, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Stocking Up
(28418, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Burning Vengeance
(28417, 1, 1, 5, 1, 0, 0, 0, 0, 58558), -- Done Nothing Wrong
(25681, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Some People Just Need Killing
(25680, 1, 1, 6, 1, 0, 0, 0, 0, 58558), -- That's Not Us
(25679, 1, 2, 0, 0, 0, 0, 0, 0, 58558), -- Into the Mountain
(25678, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Pick Your Fate
(25677, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- It's All Mine
(25675, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Ogre Combat
(25676, 274, 1, 1, 0, 0, 0, 0, 0, 58558), -- Heartstrike
(25674, 1, 36, 1, 0, 0, 0, 0, 0, 58558), -- Futile Pride
(25720, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- The Downfall of Marl Wormthorn
(25719, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- Demoniac Vessel
(25718, 396, 396, 396, 0, 0, 0, 0, 0, 58558), -- How Best to Proceed
(25717, 396, 396, 396, 0, 0, 0, 0, 0, 58558), -- The Demons and the Druid
(25701, 397, 396, 396, 397, 0, 0, 0, 0, 58558), -- You Are Rakh'likh, Demon
(25700, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Loramus Thalipedes Awaits
(25699, 153, 396, 396, 0, 0, 0, 0, 0, 58558), -- The Amulet of Grol
(25697, 396, 396, 0, 0, 0, 0, 0, 0, 58558), -- The Amulet of Allistarj
(25698, 396, 396, 1, 0, 0, 0, 0, 0, 58558), -- The Amulet of Sevine
(25696, 396, 432, 396, 0, 0, 0, 0, 0, 58558), -- The Sunveil Excursion
(25695, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Watching Our Back
(25693, 432, 1, 0, 0, 0, 0, 0, 0, 58558), -- Enhancing the Stone
(25694, 1, 1, 66, 0, 0, 0, 0, 0, 58558), -- Protecting Our Rear
(25692, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Vile Blood of Demons
(25691, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Charred Granite of the Dark Portal
(25689, 396, 397, 396, 0, 0, 0, 0, 0, 58558), -- Time is Short
(25688, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Altar of Storms
(25687, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Not Just Any Body
(25686, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Blood Ritual
(25690, 1, 1, 6, 0, 0, 0, 0, 0, 58558), -- A Bloodmage's Gotta Eat Too
(25685, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The First Step
(25684, 1, 1, 5, 0, 0, 0, 0, 0, 58558), -- Attune the Bloodstone
(25683, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- The Dreadmaul Furnace
(25682, 6, 0, 0, 0, 0, 0, 0, 0, 58558), -- Mission Complete
(27898, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- Rheastrasza's Gift
(27897, 1, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Hidden Clutch
(27896, 1, 18, 1, 1, 0, 0, 0, 0, 58558), -- The Sorrow and the Fury
(27895, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Their Hunt Continues
(27894, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Wrath of a Dragonflight
(27893, 1, 1, 5, 0, 0, 0, 0, 0, 58558), -- Gargal, the Behemoth
(27892, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Jurrix the Striker
(27891, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Amakkar, Jack of All Trades
(27879, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- Survival of the Fattest
(27890, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Bad Dogs
(27880, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Half-Ton Holdouts
(27889, 4, 5, 1, 1, 3000, 0, 0, 0, 58558), -- New Kargath
(27888, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Return to Blam
(27913, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Titans' Trove
(27887, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- Ancient Protectors
(27885, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Warden's Game
(27886, 0, 0, 0, 0, 0, 0, 0, 0, 58558), -- The Sentinel's Game
(27884, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Sentinel's Pawn
(27883, 1, 1, 0, 0, 0, 0, 0, 0, 58558), -- The Warden's Pawn
(27882, 1, 5, 1, 0, 0, 0, 0, 0, 58558), -- It's Not About History, It's About Power
(27881, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Bloodwatcher Point
(27877, 1, 1, 6, 0, 0, 0, 0, 0, 58558), -- The Morons' League
(27878, 1, 1, 1, 0, 0, 0, 0, 0, 58558), -- Forcible Acquisition
(26027, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- Call to Arms
(26030, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Sigil of Strom
(26025, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Traitor Orc
(26023, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Forsaken Trollbane
(26053, 15, 6, 1, 0, 0, 0, 0, 0, 59069), -- Clearing the Highlands
(26022, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- First Blood
(26912, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Princess Unleashed
(26911, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Myzrael's Tale
(26108, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Guile of the Raptor
(6622, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Triage
(26986, 1, 1, 0, 0, 0, 0, 0, 0, 59069), -- Into the Scarlet Monastery
(26430, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Revantusk Village
(26429, 1, 1, 1, 0, 0, 0, 0, 0, 59069), -- Crush the Witherbark
(26107, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Raising Spirits
(26083, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Hello Lolo
(26084, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- Hammerfall
(26081, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Alina's Reward
(26033, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Trol'kalar
(26032, 1, 0, 0, 0, 0, 0, 0, 0, 59069), -- Sigil of Arathor
(26029, 0, 0, 0, 0, 0, 0, 0, 0, 59069), -- The Real Threat
(26031, 1, 0, 0, 0, 0, 0, 0, 0, 59069); -- Sigil of Thoradin

UPDATE `quest_details` SET `Emote2`=1, `VerifiedBuild`=59069 WHERE `ID`=27746; -- Empire of Dirt
UPDATE `quest_details` SET `Emote1`=1, `Emote3`=1, `VerifiedBuild`=59069 WHERE `ID`=27601; -- Cities in Dust

DELETE FROM `quest_request_items` WHERE `ID` IN (26700 /*The Damsel's (Bad) Luck*/, 26699 /*Turning the Brashtide*/, 27232 /*The Waters Run Red...*/, 27231 /*Reinforcements from Fenris*/, 28115 /*Past Their Prime*/,28428/*A Perfect Costume*/, 27715 /*The Day that Deathwing Came: What Really Happened*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26700, 0, 0, 0, 0, 'You\'re really going to attack your former crew?', 58558), -- The Damsel's (Bad) Luck
(26699, 0, 0, 0, 0, 'Seahorn can\'t do everything on his own, $N.  I\'m going to need you to kill SOME of these pirates.', 58558), -- Turning the Brashtide
(27232, 0, 0, 0, 0, 'Is it done?', 59069), -- The Waters Run Red...
(27231, 0, 0, 0, 0, 'Report?', 59069), -- Reinforcements from Fenris
(28115, 0, 274, 0, 0, 'Don\'t worry, $c. We\'ll never run out of bears.', 59069), -- Past Their Prime
(28428, 0, 0, 0, 0, 'We\'re not done yet, you little $c!', 58558), -- A Perfect Costume
(27715, 0, 0, 0, 0, 'I seem to have lost my place... let\'s see... where was I...', 58558); -- The Day that Deathwing Came: What Really Happened

UPDATE `quest_request_items` SET `CompletionText`='I see you\'re still carrying some of those drums with you, $N.  Don\'t return until they\'ve all been placed.', `VerifiedBuild`=58558 WHERE `ID`=26978; -- Who Needs Cauldrons?
UPDATE `quest_request_items` SET `CompletionText`='Have you lost your way, $N?', `VerifiedBuild`=58558 WHERE `ID`=26937; -- When Death is Not Enough
UPDATE `quest_request_items` SET `CompletionText`='Have you seen the camp yet, $N?', `VerifiedBuild`=58558 WHERE `ID`=26930; -- After the Crusade
UPDATE `quest_request_items` SET `CompletionText`='I know what those devices sound like when they\'ve blown up... and I haven\'t heard that sound yet.  Get back out there, $N.', `VerifiedBuild`=58558 WHERE `ID`=26922; -- The Endless Flow
UPDATE `quest_request_items` SET `CompletionText`='Thin out the Scourge forces, $N.  Our victory depends on keeping their numbers down.', `VerifiedBuild`=58558 WHERE `ID`=26921; -- Scourge First... Alliance Later
UPDATE `quest_request_items` SET `CompletionText`='You will find them to the west, $N.  Do not fail me.', `VerifiedBuild`=58558 WHERE `ID`=27086; -- Ashes to Ashes
UPDATE `quest_request_items` SET `CompletionText`='Stand at attention, $Nnub!', `VerifiedBuild`=59069 WHERE `ID`=26965; -- The Warchief Cometh
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=27478; -- Relios the Relic Keeper
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=457, `VerifiedBuild`=59069 WHERE `ID`=27475; -- Unyielding Servitors
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=27474; -- Breaking the Barrier
UPDATE `quest_request_items` SET `CompletionText`='What have you to report, $Nnub?', `VerifiedBuild`=59069 WHERE `ID`=26989; -- The Gilneas Liberation Front
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=27342; -- In Time, All Will Be Revealed
UPDATE `quest_request_items` SET `CompletionText`='Do not fail me, $N. If we can bend this Bloodscalp magic to our will, my people may yet eliminate the Amani threat.', `VerifiedBuild`=58558 WHERE `ID`=9436; -- Bloodscalp Insight
UPDATE `quest_request_items` SET `CompletionText`='Where is $N\'aka?', `VerifiedBuild`=58558 WHERE `ID`=26362; -- Be Raptor
UPDATE `quest_request_items` SET `CompletionText`='We appreciate what you\'re doing for us here in Grom\'gol, $N.', `VerifiedBuild`=58558 WHERE `ID`=26338; -- Population Con-Troll
UPDATE `quest_request_items` SET `CompletionText`='$N.  Kin\'weelay told me you set out to capture Yenniku.$B$BIs it true?  Do you have him?' WHERE `ID`=26305;
UPDATE `quest_request_items` SET `CompletionText`='Please, $N... put out the awful fires.', `VerifiedBuild`=58558 WHERE `ID`=26304; -- Nighttime in the Jungle
UPDATE `quest_request_items` SET `CompletionText`='Greetings, $N.  The spirits sing praise of your bravery, yet they tell me no tales of your quest against Mai\'Zoth.$B$BDo you have the Eye?', `VerifiedBuild`=58558 WHERE `ID`=26303; -- The Mind's Eye
UPDATE `quest_request_items` SET `CompletionText`='$N.  I fear for our chief\'s son.  Do you have the shrunken heads so I may inspect them?', `VerifiedBuild`=58558 WHERE `ID`=26299; -- Headhunting
UPDATE `quest_request_items` SET `CompletionText`='Beware the murloc fighter, $N.  In my experience his size usually belies his strength.', `VerifiedBuild`=58558 WHERE `ID`=26280; -- The Defense of Grom'gol: Murloc Menace
UPDATE `quest_request_items` SET `CompletionText`='I need Mizjah to be cleaned of ogres, $N.  Now get to it!', `VerifiedBuild`=58558 WHERE `ID`=26279; -- The Defense of Grom'gol: Ogre Oppression
UPDATE `quest_request_items` SET `CompletionText`='I start you out with the simplest task for a reason, $N.  Do not fail me.', `VerifiedBuild`=58558 WHERE `ID`=26278; -- The Defense of Grom'gol: Raptor Risk
UPDATE `quest_request_items` SET `CompletionText`='What news of Naias, $N?', `VerifiedBuild`=58558 WHERE `ID`=9457; -- An Unusual Patron
UPDATE `quest_request_items` SET `CompletionText`='$N.  Kin\'weelay told me you set out to capture Yenniku.$B$BIs it true?  Do you have him?' WHERE `ID`=26305;
UPDATE `quest_request_items` SET `CompletionText`='Please, $N... put out the awful fires.', `VerifiedBuild`=58558 WHERE `ID`=26304; -- Nighttime in the Jungle
UPDATE `quest_request_items` SET `CompletionText`='Greetings, $N.  The spirits sing praise of your bravery, yet they tell me no tales of your quest against Mai\'Zoth.$B$BDo you have the Eye?', `VerifiedBuild`=58558 WHERE `ID`=26303; -- The Mind's Eye
UPDATE `quest_request_items` SET `CompletionText`='Where is $N\'aka?', `VerifiedBuild`=58558 WHERE `ID`=26362; -- Be Raptor
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=5, `VerifiedBuild`=59069 WHERE `ID`=7082; -- The Graveyards of Alterac
UPDATE `quest_request_items` SET `CompletionText`='Recover our \"supplies,\" $N!', `VerifiedBuild`=59069 WHERE `ID`=28144; -- Thieving Little Monsters!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=28114; -- Glorious Harvest
UPDATE `quest_request_items` SET `CompletionText`='I\'m practically naked here, $N. Help me out, eh?', `VerifiedBuild`=59069 WHERE `ID`=28487; -- Humbert's Personal Problems
UPDATE `quest_request_items` SET `CompletionText`='Bring me yeti hearts, $N.', `VerifiedBuild`=59069 WHERE `ID`=28484; -- The Heart of the Matter
UPDATE `quest_request_items` SET `CompletionText`='Wake up! Wake up, $N! This is not a dream. You really are entrenched in the midst of a raging battle!' WHERE `ID`=7161; -- Proving Grounds
UPDATE `quest_request_items` SET `CompletionText`='Do not waste my time, $N.' WHERE `ID`=28237;
UPDATE `quest_request_items` SET `CompletionText`='Do not waste my time, $N.', `VerifiedBuild`=59069 WHERE `ID`=28230; -- Protocol
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='We will not suffer the dwarves in our home!  Fall upon our foes and defeat their leader, general Stormpike!', `VerifiedBuild`=59069 WHERE `ID`=7142; -- The Battle for Alterac
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You haven\'t yet captured a mine, $N!  Find one that we do not control and defeat it\'s leader!', `VerifiedBuild`=59069 WHERE `ID`=7124; -- Capture a Mine
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You haven\'t yet assaulted a bunker, $N!  Are you waiting for others to claim your glory?', `VerifiedBuild`=59069 WHERE `ID`=7101; -- Towers and Bunkers
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9148;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='I was told a visitor from Quel\'Thalas was coming.  I was expecting a blood elf, to tell you the truth.$B$BWhat news do you bring?' WHERE `ID`=9812; -- Envoy to the Horde
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9220; -- War on Deatholme
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='You seek audience with me, $c?  I do not recall hearing of an appointment.' WHERE `ID`=9811; -- Friend of the Sin'dorei
UPDATE `quest_request_items` SET `CompletionText`='You\'ve procured more spinal dust?  I can use as much of it as you bring me.' WHERE `ID`=9219; -- More Spinal Dust
UPDATE `quest_request_items` SET `CompletionText`='You\'ve brought more ghoul hearts?  I can use as many as you can collect, $N.' WHERE `ID`=9217; -- More Rotting Hearts
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9215; -- Bring Me Kel'gash's Head!
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9214; -- Shadowpine Weaponry
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9207; -- Underlight Ore Samples
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59069 WHERE `ID`=9199; -- Troll Juju
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59069 WHERE `ID`=9193; -- Investigate the Amani Catacombs
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='Is it good news, or bad, $g my good man : darling;?', `VerifiedBuild`=59069 WHERE `ID`=9192; -- Trouble at the Underlight Mines
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `CompletionText`='And you are?$B$BWhat\'s that you have there? That necklace looks somehow familiar. Give it here!' WHERE `ID`=9177; -- Journey to Undercity
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9176; -- The Twin Ziggurats
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID` IN (9175, 9166);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9173; -- Retaking Windrunner Spire
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN (9172, 9162, 9148);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59069 WHERE `ID`=9171; -- Culinary Crunch
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='Have you succeeded in severing the Scourge\'s chain of command, $N?  Are Dar\'Khan\'s lieutenants dead?', `VerifiedBuild`=59069 WHERE `ID`=9170; -- Dar'Khan's Lieutenants
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9169; -- Deactivate An'owyn
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9167; -- The Traitor's Destruction
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9163; -- Into Occupied Territory
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='$C, what word do you bring concerning An\'daroth and what the night elves were up to there?', `VerifiedBuild`=59069 WHERE `ID`=9160; -- Investigate An'daroth
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9159; -- Curbing the Plague
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9158; -- Bearers of the Plague
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9156; -- Wanted: Knucklerot and Luzran
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59069 WHERE `ID`=9152; -- Tomber's Supplies
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9150; -- Salvaging the Past
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9149; -- The Plagued Coast
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9143; -- Dealing with Zeb'Sora
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9140; -- Windrunner Village
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=59069 WHERE `ID`=9139; -- Goldenmist Village
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `CompletionText`='With your aid we\'ll get the Scourge problem contained, $c.  Dar\'Khan will be dealt with!$B$BHave you handled the Nerubian problem at Suncrown Village yet?', `VerifiedBuild`=59069 WHERE `ID`=9138; -- Suncrown Village
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9281; -- Clearing the Way
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9277; -- Assault on Zeb'Nowa
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9276; -- Attack on Zeb'Tela
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `VerifiedBuild`=59069 WHERE `ID`=9275; -- A Little Dash of Seasoning
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `VerifiedBuild`=59069 WHERE `ID`=9274; -- Spirits of the Drowned
UPDATE `quest_request_items` SET `CompletionText`='You\'ve arrived, $N.' WHERE `ID`=28448;
UPDATE `quest_request_items` SET `CompletionText`='Come on, $N, there\'s still more of them left.  Our job isn\'t done.', `VerifiedBuild`=58558 WHERE `ID`=28447; -- Draconic Vanguard
UPDATE `quest_request_items` SET `CompletionText`='I haven\'t time for this, $N.  You came here for a reason, and it wasn\'t to chat.  Get back to work.', `VerifiedBuild`=58558 WHERE `ID`=25720; -- The Downfall of Marl Wormthorn
UPDATE `quest_request_items` SET `CompletionText`='Dawnflight\'s plan is a good one.  Do you have the vessel, $N?', `VerifiedBuild`=58558 WHERE `ID`=25719; -- Demoniac Vessel
UPDATE `quest_request_items` SET `CompletionText`='The forest is not yet cleared of the taint, $N.  Do as I say, and then we may proceed with our mission.', `VerifiedBuild`=58558 WHERE `ID`=25717; -- The Demons and the Druid
UPDATE `quest_request_items` SET `CompletionText`='Did you get a look at those plans, $N?', `VerifiedBuild`=58558 WHERE `ID`=25695; -- Watching Our Back
UPDATE `quest_request_items` SET `CompletionText`='You have not yet killed these demons.  $N!  Get back to the field!', `VerifiedBuild`=58558 WHERE `ID`=25694; -- Protecting Our Rear
UPDATE `quest_request_items` SET `CompletionText`='I haven\'t time for this, $N.  You came here for a reason, and it wasn\'t to chat.  Get back to work.', `VerifiedBuild`=58558 WHERE `ID`=25720; -- The Downfall of Marl Wormthorn
UPDATE `quest_request_items` SET `CompletionText`='Dawnflight\'s plan is a good one.  Do you have the vessel, $N?', `VerifiedBuild`=58558 WHERE `ID`=25719; -- Demoniac Vessel
UPDATE `quest_request_items` SET `CompletionText`='The forest is not yet cleared of the taint, $N.  Do as I say, and then we may proceed with our mission.', `VerifiedBuild`=58558 WHERE `ID`=25717; -- The Demons and the Druid
UPDATE `quest_request_items` SET `CompletionText`='Did you get a look at those plans, $N?', `VerifiedBuild`=58558 WHERE `ID`=25695; -- Watching Our Back
UPDATE `quest_request_items` SET `CompletionText`='You have not yet killed these demons.  $N!  Get back to the field!', `VerifiedBuild`=58558 WHERE `ID`=25694; -- Protecting Our Rear
UPDATE `quest_request_items` SET `CompletionText`='We\'re not through yet, $N.', `VerifiedBuild`=58558 WHERE `ID`=27891; -- Amakkar, Jack of All Trades
UPDATE `quest_request_items` SET `CompletionText`='That\'s some precious cargo you carry there, $N.' WHERE `ID`=27889;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=6, `CompletionText`='You have not yet performed your mission, $N.  Assault each of the four bases of which I spoke, and return to me after you have done so!', `VerifiedBuild`=59069 WHERE `ID`=8120; -- The Battle for Arathi Basin!
 
DELETE FROM `creature_queststarter` WHERE (`id`=44462 AND `quest`=27683) OR (`id`=45315 AND `quest`=27345) OR (`id`=48470 AND `quest`=28400) OR (`id`=16252 AND `quest`=9177);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(44462, 27683, 58558), -- Into the Woods offered by Jearl Donald
(45315, 27345, 59069), -- The F.C.D. offered by Forward Commander Onslaught
(48470, 28400, 59069), -- Heroes of the Horde! offered by Kingslayer Orkus
(16252, 9177, 59069); -- Journey to Undercity offered by High Executor Mavren
