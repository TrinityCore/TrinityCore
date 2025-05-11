DELETE FROM `quest_offer_reward` WHERE `ID` IN (27953, 28790, 27712, 28602, 27717, 26124);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27953, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, it\'s about time someone came to speak with us on matters most urgent.', 59734), -- The Reliquary
(28790, 396, 0, 0, 0, 0, 0, 0, 0, 'May your sense of honor and duty serve Azeroth well, $c.', 59185), -- A Personal Summons
(27712, 4, 0, 0, 0, 0, 0, 0, 0, '$N, glad you\'re back! Have I got something fun for us to do!', 59185), -- Back to the Elementium Depths
(28602, 1, 0, 0, 0, 0, 0, 0, 0, 'Something tells me I\'m going to need this.', 59185), -- Be Prepared
(27717, 1, 0, 0, 0, 0, 0, 0, 0, 'Brilliant! I can\'t have expected much more with the tools I gave you.$B$BI should be able to fill in the blanks and get this all written out shortly. There\'s no knowing if we will make it out of this place, but if it comes down to it, I will find a way to float this to the surface in hopes that it will one day be found.$B$BThank you again, $n. You\'re not bad.', 59185), -- Piece of the Past
(26124, 273, 396, 0, 0, 0, 0, 0, 0, 'You did well, $N.  We need to be especially wary of Alliance attacks right now.  The Verne\'s got plenty of firepower out at sea, but in the back of this cave, she\'s far too vulnerable.', 59185); -- Secure Seabrush

UPDATE `quest_offer_reward` SET `RewardText`='Our world is in danger, $N! We need the help of great heroes, like you, to save it!', `VerifiedBuild`=59734 WHERE `ID`=27722; -- Warchief's Command: Deepholm!
UPDATE `quest_offer_reward` SET `Emote1`=430, `Emote2`=18, `Emote3`=5, `VerifiedBuild`=59185 WHERE `ID`=28732; -- This Can Only Mean One Thing...
UPDATE `quest_offer_reward` SET `RewardText`='They\'re moving supplies to Hyjal straight from the elemental planes? Devious.$B$BYou\'ve made Lo\'Gosh proud by sealing that flamegate, $N, but there may be more portals to seal. You should check with the other shrines!', `VerifiedBuild`=59185 WHERE `ID`=25612; -- Return from the Firelands
UPDATE `quest_offer_reward` SET `RewardText`='Impressive, $N. Very impressive.$B$BYou embody all of the strength of the wolf ancient, and possess the wisdom to use your powers well. I salute you.', `VerifiedBuild`=59185 WHERE `ID`=25354; -- Sweeping the Shelf
UPDATE `quest_offer_reward` SET `RewardText`='So, it is true! You indeed carry lightning in your hands.$B$BYou are the chosen one, $N. You will be my champion, and carry my vengeance to realms where I cannot tread...', `VerifiedBuild`=59185 WHERE `ID`=25355; -- Lightning in a Bottle
UPDATE `quest_offer_reward` SET `RewardText`='$N, it was incredible! For a fleeting moment I saw Lo\'Gosh through the trees - a creature of both fury and light. My cage collapsed and the vandals melted like wax under the kiss of his claws, their screams and howls echoing through the valley... Was that your work?', `VerifiedBuild`=59185 WHERE `ID`=25279; -- The Shrine Reclaimed
UPDATE `quest_offer_reward` SET `RewardText`='You were brave to face down Lycanthoth, $N. Like myself, he was a primal force of nature... but his origins were from a darker place.$B$BThose who birthed that beast reached deep into the blackness, channeling powers never intended for this world.$B$BCome, $c. Climb onto my back, and let us show these beasts the true face of ferocity!', `VerifiedBuild`=59185 WHERE `ID`=25272; -- Lycanthoth the Corruptor
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for answering our call for aid, $N.', `VerifiedBuild`=59185 WHERE `ID`=29389; -- Guardians of Hyjal: Firelands Invasion!
UPDATE `quest_offer_reward` SET `RewardText`='Your aid is most timely, $N.', `VerifiedBuild`=59185 WHERE `ID`=27399; -- The Battle Is Won, The War Goes On
UPDATE `quest_offer_reward` SET `RewardText`='Hyjal has been saved, $N.  And it\'s all thanks to you.', `VerifiedBuild`=59185 WHERE `ID`=25551; -- The Firelord
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  We shall soon claim victory in Hyjal.$B$BIt has been an honor to fight along your side.', `VerifiedBuild`=59185 WHERE `ID`=25550; -- Magma Monarch
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  We will use this to draw out the Twilight matriarch.', `VerifiedBuild`=59185 WHERE `ID`=25552; -- Brood of Evil
UPDATE `quest_offer_reward` SET `RewardText`='You continue to prove your prowess, $N.  At this rate Hyjal might survive this ordeal after all.', `VerifiedBuild`=59185 WHERE `ID`=25549; -- The Sanctum of the Prophets
UPDATE `quest_offer_reward` SET `RewardText`='You were right to come to me with this, $N.  This represents a great threat to us if we do not act swiftly and boldly.', `VerifiedBuild`=59185 WHERE `ID`=25644; -- The Twilight Egg
UPDATE `quest_offer_reward` SET `RewardText`='You did well, $N.  I\'ve a new target for you.', `VerifiedBuild`=59185 WHERE `ID`=25548; -- Might of the Firelord
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  We might win this one yet.', `VerifiedBuild`=59185 WHERE `ID`=25608; -- Slash and Burn
UPDATE `quest_offer_reward` SET `RewardText`='You have my thanks, $N.', `VerifiedBuild`=59185 WHERE `ID`=25531; -- Twilight Riot
UPDATE `quest_offer_reward` SET `RewardText`='There you are, $Ndamus.  I\'ve been meaning to talk to you about something.$B$BI heard about the unfortunate incident that befell our poor friend, Okrog.$B$B<Mylva looks to her left, then her right.  She finally nods and shoots a sly wink in your direction.>$B$BYou might be a better pupil than I had thought.', `VerifiedBuild`=59185 WHERE `ID`=25601; -- Head of the Class
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  Our plan\'s almost come together.', `VerifiedBuild`=59185 WHERE `ID`=25314; -- Speech Writing for Dummies
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $Ndamus.  We must show all would-be competitors that we are not ones to give up easily.', `VerifiedBuild`=59185 WHERE `ID`=25310; -- The Greater of Two Evils
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N!  You\'ve outdone yourself this time.', `VerifiedBuild`=59185 WHERE `ID`=25308; -- Seeds of Discord
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve succeeded, $Ndamus.  You\'re ready for the next step.', `VerifiedBuild`=59185 WHERE `ID`=25299; -- Mental Training: Speaking the Truth to Power
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N.  Or should I say: \"$N\"damus?$B$BGive me a minute to read these.', `VerifiedBuild`=59185 WHERE `ID`=25296; -- Gather the Intelligence
UPDATE `quest_offer_reward` SET `RewardText`='This is a disaster, $N!$B$BOur air fleet was decimated. And reports are coming in that our navy was attacked - unprovoked - by the Alliance in open water.$B$BAnd what of Hellscream? Is the Warchief dead?', `VerifiedBuild`=59185 WHERE `ID`=26388; -- Twilight Skies
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N! Most of my soldiers have already reported for duty, some a little worse for the wear.$B$BOne night in Bilgewater makes a hard orc humble.$B$BStill, fresh fighting in the Twilight Highlands should restore discipline.', `VerifiedBuild`=59185 WHERE `ID`=26374; -- Ready the Ground Troops
UPDATE `quest_offer_reward` SET `RewardText`='What, another message from Hellscream? His patience is thinner than calf\'s hide.$B$BHave you ever worked with goblins before? Everywhere is another hidden cost! Our ships lie half-assembled and the air fleet is scattered to the winds.$B$BIf this invasion is going to happen, I\'m going to need your help.', `VerifiedBuild`=59185 WHERE `ID`=26324; -- Where Is My Warfleet?
UPDATE `quest_offer_reward` SET `RewardText`='<Garrosh laughs.>$B$BInstilled a little discipline in them, did you? Good, good!$B$BEveryone pulls their weight in my Horde, from the smallest peon to the proudest warrior. I tolerate nothing less.$B$BOur preparations for the invasion are almost complete.', `VerifiedBuild`=59185 WHERE `ID`=26294; -- Weapons of Mass Dysfunction
UPDATE `quest_offer_reward` SET `RewardText`='Busy now. Go away.$B$BWait, what? Hellscream sent you? What - uh - what can I do for you? Him? Us?', `VerifiedBuild`=59185 WHERE `ID`=26293; -- Machines of War
UPDATE `quest_offer_reward` SET `RewardText`='Soon, the assault on the Twilight Highlands will begin, and I intend for you to be a part of it.', `VerifiedBuild`=59185 WHERE `ID`=28717; -- Warchief's Command: Twilight Highlands!
UPDATE `quest_offer_reward` SET `RewardText`='You did it, $N! You beat that damned gronn and sent Cho\'gall packing into the Twilight Bastion.$B$BDon\'t you worry. With your help and that of your friends, we\'ll get in there and we\'ll kill Cho\'gall once and for all!', `VerifiedBuild`=59185 WHERE `ID`=27788; -- Skullcrusher the Mountain
UPDATE `quest_offer_reward` SET `RewardText`='That takes care of most of their leaders outside of the Bastion of Twilight. Not bad work, $N. Not bad at all.', `VerifiedBuild`=59185 WHERE `ID`=27689; -- Distract Them for Me
UPDATE `quest_offer_reward` SET `RewardText`='$N! I\'m glad you\'re here.$B$BOf course, I\'m more than willing to help you in any way that I can.', `VerifiedBuild`=59185 WHERE `ID`=27658; -- Help from the Earthcaller
UPDATE `quest_offer_reward` SET `RewardText`='You see! De dead be nothing to be scared of. You brought de light to de darkness, mon, and never flinched.$B$BWe can use dis cave now as a base of operations in de northern Highlands. You\'re de best, $N!', `VerifiedBuild`=59185 WHERE `ID`=28170; -- Night Terrors
UPDATE `quest_offer_reward` SET `RewardText`='Hah! I\'m sure Twilight\'s Hammer wanted to number those ogres among their ranks. Now they\'ll probably have to fight them off instead.$B$BThis is good, $N. With one well-placed $c we managed to do the work of a small army. I\'ll let Warlord Krogg know of your work here!', `VerifiedBuild`=59185 WHERE `ID`=28151; -- Dressed to Kill
UPDATE `quest_offer_reward` SET `RewardText`='<Zaela takes the gore-spattered length of chain and wraps it around her hand and wrist.>$B$BIf the stories are true, $N, it was on this length of chain that Deathwing had once fastened the Demon Soul, forged in his bid to control the other dragonflights. The Demon Soul has long been destroyed but perhaps this hunk of elementium holds some residual power...$B$BYou\'ve done a great thing today.', `VerifiedBuild`=59185 WHERE `ID`=28123; -- The Demon Chain
UPDATE `quest_offer_reward` SET `RewardText`='Thanks, $N! Now if we could just get the Krazzworks stable so that our people would stop being thrown off of the platforms.', `VerifiedBuild`=59185 WHERE `ID`=28586; -- Pool Pony Rescue
UPDATE `quest_offer_reward` SET `RewardText`='You got the chops for killing dwarves, that\'s for sure, $N. This is a good thing.$B$BNext up, more dwarf slayage!', `VerifiedBuild`=59185 WHERE `ID`=28588; -- Wildhammer Infestation
UPDATE `quest_offer_reward` SET `RewardText`='What\'s this? The \"$N-o-matic:\" a shredder with an integrated missile platform?$B$BBah! Already patented by Labor Captain Grabbit in Azshara. Worthless!$B$BWhat I really need is a machine that knocks dwarves from the sky.', `VerifiedBuild`=59185 WHERE `ID`=28583; -- Krazzworks
UPDATE `quest_offer_reward` SET `RewardText`='That was an impressive aerial display, $N, but I wish it had come at a better time.$B$BNarkrall is a great warrior, but he\'s also an impatient fool. He\'s about to get himself killed ... and we\'re about to lose one of our most important weapons in the battle for the Highlands!', `VerifiedBuild`=59185 WHERE `ID`=28043; -- How to Maim Your Dragon
UPDATE `quest_offer_reward` SET `RewardText`='Yes, yes. Burn them out, as you would flush groundhogs from their holes...$B$BWell done, $N.', `VerifiedBuild`=59185 WHERE `ID`=27747; -- Total War
UPDATE `quest_offer_reward` SET `RewardText`='That\'s right baby! That\'s right! Cold steel and hot death!$B$BWhat should we name our new creation? The Gnugatron? No - better - the $N-o-matic. That\'s got a ring to it.', `VerifiedBuild`=59185 WHERE `ID`=27622; -- Mo' Better Shredder
UPDATE `quest_offer_reward` SET `RewardText`='$N! I trust Orgrimmar fares well?$B$BAs you can see, construction of Dragonmaw Port continues at a breakneck pace. If my people questioned the Horde\'s power before... the sight of this imposing edifice and the speed in which it was constructed leaves no doubt.$B$BA new day dawns for the Dragonmaw.', `VerifiedBuild`=59185 WHERE `ID`=26840; -- Return to the Highlands
UPDATE `quest_offer_reward` SET `RewardText`='Sauranok, Sauranok. His own visions worked against him. Twilight\'s Hammer probably corrupted him from afar. Bah! Weak! We\'ll speak his name no more.$B$BI told him you were investigating the airship docks, $N. To flush him out. Yes, I used you as bait. You served your Horde well, and deserve a reward for outing this viper from our midst.', `VerifiedBuild`=59185 WHERE `ID`=26830; -- Traitor's Bait
UPDATE `quest_offer_reward` SET `RewardText`='$C, you\'ve returned from Dragonmaw. The portal is functioning then? Good.$B$BBefore you return to your work there, we\'ve got some dirty business to clean up right here in Orgrimmar...', `VerifiedBuild`=59185 WHERE `ID`=26798; -- The Warchief Will be Pleased
UPDATE `quest_offer_reward` SET `RewardText`='<Ornak allows the muck to drip from his fingertips.>$B$BNow that\'s the stuff! I\'ll start mixing and diluting this with gravel and water. Just a few handfuls of this can enhance enough cement for an entire stone tower.$B$BWe\'ve got big plans for this port, $N. You\'ll see!', `VerifiedBuild`=59185 WHERE `ID`=26788; -- Cementing Our Victory
UPDATE `quest_offer_reward` SET `RewardText`='Your Warchief is decisive, $N. He makes things happen. I like him.$B$BLet\'s talk about this portal that he wants!', `VerifiedBuild`=59185 WHERE `ID`=26786; -- Securing the Beach Head
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N! You have done the Horde proud in my absence.$B$BThe Dragonmaw have joined us, with Zaela as their new leader. Blood was shed, but casualties were low, and we have their complete loyalty.$B$BOur Horde grows stronger!', `VerifiedBuild`=59185 WHERE `ID`=26622; -- Death to Mor'ghor
UPDATE `quest_offer_reward` SET `RewardText`='We\'ve lost a lot of good orcs, but the fight is going our way, $N.$B$BMor\'ghor\'s regime is collapsing. All that remains is to destroy the beast himself.', `VerifiedBuild`=59185 WHERE `ID`=26621; -- Insurrection
UPDATE `quest_offer_reward` SET `RewardText`='$N, what are your people doing? Are you attacking the Dragonmaw or are you here to rid us of Mor\'ghor\'s corruption?$B$B<Zaela listens to the plan.>$B$BAh, I see now. I like the way you think. Warchief Mor\'ghor won\'t even know what hit him.$B$BLet\'s do this!', `VerifiedBuild`=59185 WHERE `ID`=26619; -- You Say You Want a Revolution
UPDATE `quest_offer_reward` SET `RewardText`='Wake up, $N! We don\'t have much time.$B$BI rescued your gear for you.$B$BAt least now you\'ve seen the foolishness of our leader first-hand. His blood is contaminated, his rage is unquenchable -- and he\'ll destroy us all trying to defeat the Horde!', `VerifiedBuild`=59185 WHERE `ID`=26549; -- Madness
UPDATE `quest_offer_reward` SET `RewardText`='You could be one of the very first mortals to set foot in Uldum in millenia. Just think of the treasures that await us!', `VerifiedBuild`=59185 WHERE `ID`=28557; -- Warchief's Command: Uldum!
UPDATE `quest_offer_reward` SET `RewardText`='<Captain Vilethorn admires the polearms you present him.>$b$bOh, I\'m sorry.  I was just imagining what these will look like with little bits of naga stuck to the ends of them.  Thank you, $N.  We\'ll put these to good use.', `VerifiedBuild`=59185 WHERE `ID`=25992; -- Hopelessly Gearless
UPDATE `quest_offer_reward` SET `RewardText`='$N... is that you?', `VerifiedBuild`=59185 WHERE `ID`=25991; -- We Are Not Alone
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N... although I\'m afraid I haven\'t been nearly as productive as you have.', `VerifiedBuild`=59185 WHERE `ID`=25907; -- Slave Labor
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.$B$BThese nightmarish creatures that rise from below give me pause. I fear that our efforts will be for nothing.', `VerifiedBuild`=59185 WHERE `ID`=26065; -- Free Wil'hai
UPDATE `quest_offer_reward` SET `RewardText`='Well done.$B$BDon\'t get too full of yourself, $N. The hard part\'s about to come.', `VerifiedBuild`=59185 WHERE `ID`=26071; -- Clearing the Defiled
UPDATE `quest_offer_reward` SET `RewardText`='Nice, $N! That will show those naga who\'s the boss!$B$BNow it\'s time for that drink. You want rum or wine?', `VerifiedBuild`=59185 WHERE `ID`=25974; -- Sira'kess Slaying
UPDATE `quest_offer_reward` SET `RewardText`='This is his report?!  That idiot...$b$bI suppose we can use the food.  Thanks, $N.  You\'ve done as well as can be expected.', `VerifiedBuild`=59185 WHERE `ID`=26092; -- Orako's Report
UPDATE `quest_offer_reward` SET `RewardText`='<Orako is busy playing with Wolf.>$b$bOh, thank you, $N!  I knew Wolf was alive!$b$bHere, take one of these.  I don\'t need them anymore.', `VerifiedBuild`=59185 WHERE `ID`=26091; -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
UPDATE `quest_offer_reward` SET `RewardText`='That\'s it.  Starting today, I\'m shifting the Verne over to bio-fuel.  I\'ll send some men up to harvest more oil.$b$bThink of all the sea creatures that we\'ve saved today, $N!', `VerifiedBuild`=59185 WHERE `ID`=26126; -- The Perfect Fuel
UPDATE `quest_offer_reward` SET `RewardText`='They may think they\'ve won, but my axe and I have something to say about that!', `VerifiedBuild`=59185 WHERE `ID`=26194; -- Defending the Rift

DELETE FROM `quest_details` WHERE `ID` IN (27046 /*Fear of Boring*/, 27399 /*The Battle Is Won, The War Goes On*/, 27788 /*Skullcrusher the Mountain*/, 27786 /*The Hammer of Twilight*/, 27783 /*Garona Needs You*/, 28885 /*Mr. Goldmine's Wild Ride*/, 27712 /*Back to the Elementium Depths*/, 27703 /*Coup de Grace*/, 27701 /*Dragon, Unchained*/, 27798 /*Water of Life*/, 27696 /*The Elementium Axe*/, 27689 /*Distract Them for Me*/, 27658 /*Help from the Earthcaller*/, 27655 /*Bring the Hammer Down*/, 27653 /*Dark Assassins*/, 27638 /*Just You and Garona*/, 27503 /*Up to the Citadel*/, 27501 /*Four Heads are Better than None*/, 27499 /*Signal the Attack*/, 27495 /*Move the Mountain*/, 27491 /*Kor'kron Drop*/, 27497 /*Call in the Artillery*/, 27493 /*Ogres & Ettins*/, 28249 /*Crushblow*/, 28247 /*Last of Her Kind*/, 28176 /*Following the Young Home*/, 28093 /*Pressing Forward*/, 28094 /*Paving the Way*/, 28092 /*If The Key Fits*/, 28097 /*The Gates of Grim Batol*/, 28090 /*Precious Goods*/, 28091 /*Easy Pickings*/, 27576 /*Patchwork Command*/, 27486 /*Warm Welcome*/, 28038 /*Blood in the Highlands*/, 27611 /*Blood on the Sand*/, 27610 /*Scouting the Shore*/, 27939 /*The Desert Fox*/, 27928 /*A Favor for the Furrier*/, 27926 /*Eastern Hospitality*/, 28845 /*The Vortex Pinnacle*/, 28602 /*Be Prepared*/, 26008 /*Decompression*/, 26040 /*What? What? In My Gut...?*/, 26007 /*Debriefing*/, 26000 /*Spelunking*/, 26122 /*Environmental Awareness*/, 26221 /*Full Circle*/, 27442 /*The War Has Many Fronts*/, 26006 /*A Breath of Fresh Air*/, 25951 /*Final Judgement*/, 25860 /*At All Costs*/, 25629 /*Her Lady's Hand*/, 25896 /*Devout Assembly*/, 26135 /*Visions of the Past: Rise from the Deep*/, 25973 /*Welcome News*/, 25972 /*Honor and Privilege*/, 25969 /*Hostile Waters*/, 25971 /*Unfurling Plan*/, 25970 /*Come Prepared*/, 25968 /*Desperate Plan*/, 25967 /*Losing Ground*/, 25861 /*Setting An Example*/, 25863 /*Chosen Burden*/, 25862 /*Stolen Property*/, 25859 /*No Trespass Forgiven*/, 25858 /*By Her Lady's Word*/, 25966 /*Visions of the Past: The Slaughter of Biel'aran Ridge*/, 25964 /*Fallen But Not Forgotten*/, 25965 /*Gauging Success*/, 25963 /*Swift Action*/, 25962 /*Properly Inspired*/, 25960 /*Not Entirely Unprepared*/, 25959 /*Clear Goals*/, 25958 /*Looking Forward*/, 25659 /*Not Soon Forgotten*/, 25658 /*Built to Last*/, 25637 /*To the Fathom-Lord's Call*/, 25620 /*The Revered Lady*/, 25619 /*Reoccupation*/, 25957 /*Visions of the Past: The Invasion of Vashj'ir*/, 27717 /*Piece of the Past*/, 25956 /*Upon the Scene of Battle*/, 25953 /*Swift Approach*/, 25952 /*Caught Off-Guard*/, 25955 /*A Better Vantage*/, 25954 /*An Occupation of Time*/, 25594 /*Crafty Crabs*/, 25595 /*Something Edible*/, 25593 /*Shelled Salvation*/, 25592 /*Deep Attraction*/, 25996 /*Waking the Beast*/, 25995 /*Overseer Idra'kess*/, 25994 /*Still Valuable*/, 25992 /*Hopelessly Gearless*/, 25993 /*Body Blows*/, 25991 /*We Are Not Alone*/, 25990 /*Breaking Through*/, 25989 /*Capture the Crab*/, 26194 /*Defending the Rift*/, 26182 /*Back to the Tenebrous Cavern*/, 26143 /*All that Rises*/, 26154 /*Twilight Extermination*/, 26149 /*Prisoners*/, 26142 /*Ascend No More!*/, 26141 /*Runestones of Binding*/, 26140 /*Communing with the Ancient*/, 26133 /*Fiends from the Netherworld*/, 26130 /*Unplug L'ghorek*/, 26065 /*Free Wil'hai*/, 26111 /*... It Will Come*/, 26096 /*Scalding Shrooms*/, 26072 /*Into the Totem*/, 26057 /*The Wavespeaker*/, 26071 /*Clearing the Defiled*/, 25984 /*Promontory Point*/, 25988 /*Put It On*/, 25976 /*Treasure Reclamation*/, 25982 /*Those Aren't Masks*/, 25974 /*Sira'kess Slaying*/, 25980 /*A Standard Day for Azrajar*/, 26092 /*Orako's Report*/, 26091 /*Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo*/, 26090 /*I Brought You This Egg*/, 26089 /*Die Fishman Die*/, 26088 /*Here Fishie Fishie*/, 26087 /*"Glow-Juice"*/, 26086 /*Orako*/, 26126 /*The Perfect Fuel*/, 26124 /*Secure Seabrush*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(27046, 1, 0, 0, 0, 0, 0, 0, 0, 59734), -- Fear of Boring
(27399, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Battle Is Won, The War Goes On
(27788, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Skullcrusher the Mountain
(27786, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Hammer of Twilight
(27783, 273, 6, 0, 0, 0, 0, 0, 0, 59185), -- Garona Needs You
(28885, 1, 11, 0, 0, 0, 0, 0, 0, 59185), -- Mr. Goldmine's Wild Ride
(27712, 6, 397, 0, 0, 0, 0, 0, 0, 59185), -- Back to the Elementium Depths
(27703, 396, 273, 0, 0, 0, 0, 0, 0, 59185), -- Coup de Grace
(27701, 396, 0, 0, 0, 0, 0, 0, 0, 59185), -- Dragon, Unchained
(27798, 34, 0, 0, 0, 0, 0, 0, 0, 59185), -- Water of Life
(27696, 274, 396, 6, 0, 0, 0, 0, 0, 59185), -- The Elementium Axe
(27689, 1, 397, 0, 0, 0, 0, 0, 0, 59185), -- Distract Them for Me
(27658, 396, 274, 0, 0, 0, 1000, 0, 0, 59185), -- Help from the Earthcaller
(27655, 274, 397, 0, 0, 0, 0, 0, 0, 59185), -- Bring the Hammer Down
(27653, 273, 6, 0, 0, 0, 1000, 0, 0, 59185), -- Dark Assassins
(27638, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Just You and Garona
(27503, 1, 25, 0, 0, 0, 0, 0, 0, 59185), -- Up to the Citadel
(27501, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Four Heads are Better than None
(27499, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Signal the Attack
(27495, 1, 25, 15, 0, 0, 0, 0, 0, 59185), -- Move the Mountain
(27491, 1, 25, 1, 0, 0, 0, 0, 0, 59185), -- Kor'kron Drop
(27497, 274, 1, 0, 0, 0, 0, 0, 0, 59185), -- Call in the Artillery
(27493, 25, 0, 0, 0, 0, 0, 0, 0, 59185), -- Ogres & Ettins
(28249, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Crushblow
(28247, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Last of Her Kind
(28176, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Following the Young Home
(28093, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Pressing Forward
(28094, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Paving the Way
(28092, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- If The Key Fits
(28097, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Gates of Grim Batol
(28090, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Precious Goods
(28091, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Easy Pickings
(27576, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Patchwork Command
(27486, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Warm Welcome
(28038, 6, 5, 25, 0, 0, 0, 0, 0, 59185), -- Blood in the Highlands
(27611, 1, 5, 0, 0, 0, 0, 0, 0, 59185), -- Blood on the Sand
(27610, 1, 274, 0, 0, 0, 0, 0, 0, 59185), -- Scouting the Shore
(27939, 396, 396, 6, 0, 0, 500, 1000, 0, 59185), -- The Desert Fox
(27928, 396, 396, 396, 0, 0, 500, 500, 0, 59185), -- A Favor for the Furrier
(27926, 396, 6, 396, 0, 0, 500, 500, 0, 59185), -- Eastern Hospitality
(28845, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Vortex Pinnacle
(28602, 396, 0, 0, 0, 0, 0, 0, 0, 59185), -- Be Prepared
(26008, 5, 396, 0, 0, 0, 0, 0, 0, 59185), -- Decompression
(26040, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- What? What? In My Gut...?
(26007, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Debriefing
(26000, 396, 0, 0, 0, 0, 0, 0, 0, 59185), -- Spelunking
(26122, 5, 1, 1, 1, 0, 0, 0, 0, 59185), -- Environmental Awareness
(26221, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Full Circle
(27442, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The War Has Many Fronts
(26006, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Breath of Fresh Air
(25951, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Final Judgement
(25860, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- At All Costs
(25629, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Her Lady's Hand
(25896, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Devout Assembly
(26135, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Visions of the Past: Rise from the Deep
(25973, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Welcome News
(25972, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Honor and Privilege
(25969, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Hostile Waters
(25971, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Unfurling Plan
(25970, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Come Prepared
(25968, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Desperate Plan
(25967, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Losing Ground
(25861, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Setting An Example
(25863, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Chosen Burden
(25862, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Stolen Property
(25859, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- No Trespass Forgiven
(25858, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- By Her Lady's Word
(25966, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Visions of the Past: The Slaughter of Biel'aran Ridge
(25964, 36, 0, 0, 0, 0, 0, 0, 0, 59185), -- Fallen But Not Forgotten
(25965, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Gauging Success
(25963, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Swift Action
(25962, 5, 0, 0, 0, 0, 0, 0, 0, 59185), -- Properly Inspired
(25960, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Not Entirely Unprepared
(25959, 1, 1, 1, 0, 0, 60, 60, 0, 59185), -- Clear Goals
(25958, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Looking Forward
(25659, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Not Soon Forgotten
(25658, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Built to Last
(25637, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- To the Fathom-Lord's Call
(25620, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Revered Lady
(25619, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Reoccupation
(25957, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Visions of the Past: The Invasion of Vashj'ir
(27717, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Piece of the Past
(25956, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Upon the Scene of Battle
(25953, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Swift Approach
(25952, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Caught Off-Guard
(25955, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Better Vantage
(25954, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- An Occupation of Time
(25594, 5, 0, 0, 0, 0, 0, 0, 0, 59185), -- Crafty Crabs
(25595, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Something Edible
(25593, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Shelled Salvation
(25592, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Deep Attraction
(25996, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Waking the Beast
(25995, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Overseer Idra'kess
(25994, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Still Valuable
(25992, 1, 15, 390, 1, 0, 0, 0, 0, 59185), -- Hopelessly Gearless
(25993, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Body Blows
(25991, 1, 1, 1, 0, 0, 0, 0, 0, 59185), -- We Are Not Alone
(25990, 1, 1, 1, 0, 0, 0, 0, 0, 59185), -- Breaking Through
(25989, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Capture the Crab
(26194, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Defending the Rift
(26182, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Back to the Tenebrous Cavern
(26143, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- All that Rises
(26154, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Twilight Extermination
(26149, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Prisoners
(26142, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Ascend No More!
(26141, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Runestones of Binding
(26140, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Communing with the Ancient
(26133, 1, 25, 0, 0, 0, 0, 0, 0, 59185), -- Fiends from the Netherworld
(26130, 1, 25, 0, 0, 0, 0, 0, 0, 59185), -- Unplug L'ghorek
(26065, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- Free Wil'hai
(26111, 25, 1, 0, 0, 0, 0, 0, 0, 59185), -- ... It Will Come
(26096, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Scalding Shrooms
(26072, 25, 1, 0, 0, 0, 0, 0, 0, 59185), -- Into the Totem
(26057, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Wavespeaker
(26071, 1, 6, 0, 0, 0, 0, 0, 0, 59185), -- Clearing the Defiled
(25984, 5, 25, 0, 0, 0, 0, 0, 0, 59185), -- Promontory Point
(25988, 273, 6, 0, 0, 0, 0, 0, 0, 59185), -- Put It On
(25976, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Treasure Reclamation
(25982, 5, 6, 0, 0, 0, 0, 0, 0, 59185), -- Those Aren't Masks
(25974, 6, 1, 0, 0, 0, 0, 0, 0, 59185), -- Sira'kess Slaying
(25980, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Standard Day for Azrajar
(26092, 1, 1, 0, 0, 0, 0, 0, 0, 59185), -- Orako's Report
(26091, 432, 1, 1, 0, 0, 0, 0, 0, 59185), -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
(26090, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- I Brought You This Egg
(26089, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Die Fishman Die
(26088, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- Here Fishie Fishie
(26087, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- "Glow-Juice"
(26086, 14, 396, 6, 0, 0, 1000, 0, 0, 59185), -- Orako
(26126, 6, 1, 1, 25, 0, 0, 0, 0, 59185), -- The Perfect Fuel
(26124, 0, 0, 0, 0, 0, 0, 0, 0, 59185); -- Secure Seabrush

DELETE FROM `quest_request_items` WHERE `ID` IN (26632 /*Close Escort*/, 26501 /*Sealing the Way*/, 27935 /*Bring Down the Avalanche*/, 27010 /*Quicksilver Submersion*/, 26752 /*Audience with the Stonemother*/, 25412 /*The Name Never Spoken*/, 29197 /*Caught Unawares*/, 29177 /*Vigilance on Wings*/, 27380 /*Nightmare*/, 27744 /*Rune Ruination*/, 27865 /*The Crucible of Carnage: The Wayward Wildhammer!*/, 28367 /*Shroud of the Makers*/, 28520 /*The Fall of Neferset City*/, 28602 /*Be Prepared*/, 25858 /*By Her Lady's Word*/, 25637 /*To the Fathom-Lord's Call*/, 27717 /*Piece of the Past*/, 25969 /*Hostile Waters*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26501, 0, 6, 0, 0, 'I know that Crag Rockcrusher sent you, $r. Are all of the entrances sealed in Stonehearth behind us?', 59734), -- Sealing the Way
(27935, 0, 397, 0, 0, 'You have to go back and reduce Avalanchion to dust or he will attack us!', 59734), -- Bring Down the Avalanche
(26752, 0, 0, 0, 0, 'Be patient, mon.', 59734), -- Audience with the Stonemother
(26632, 0, 5, 0, 0, 'Where\'s the catapult? You have to go back and get it.', 59185), -- Close Escort
(27010, 0, 0, 0, 0, 'Yes, $N?', 59185), -- Quicksilver Submersion
(25412, 0, 6, 0, 0, 'A name, $n. We need a name.', 59185), -- The Name Never Spoken
(29197, 0, 0, 0, 0, 'There isn\'t time! Move!', 59185), -- Caught Unawares
(29177, 0, 6, 0, 0, 'Our vigilance must not fall. Especially not now, in this most trying of times!', 59185), -- Vigilance on Wings
(27380, 0, 1, 0, 0, 'The battle is not over. The shaman within Iso\'rath need you!', 59185), -- Nightmare
(27744, 0, 1, 0, 0, 'We still have some runes to destroy, $N.', 59185), -- Rune Ruination
(27865, 0, 1, 0, 0, 'No payout until the fight\'s over, $g man:lady;.', 59185), -- The Crucible of Carnage: The Wayward Wildhammer!
(28367, 0, 0, 0, 0, 'What\'s new, $n?', 59185), -- Shroud of the Makers
(28520, 0, 0, 0, 0, 'It is good to see you again, friend.', 59185), -- The Fall of Neferset City
(28602, 0, 0, 0, 0, 'How goes the search?', 59185), -- Be Prepared
(25858, 0, 1, 0, 0, 'It seems I beat you to the fight yet again. I\'m sure you defeated scores of vrykul on your way here, or some other such nonsense.$B$BIt is good to have you by my side again, Battlemaiden.', 59185), -- By Her Lady's Word
(25637, 0, 1, 0, 0, 'So I am to be graced by the presence of the Battlemaiden?$B$BThe Kvaldir stream endlessly into the sharp ends of our weapons. Please welcome yourself to some of the glory.', 59185), -- To the Fathom-Lord's Call
(27717, 1, 0, 0, 0, 'Hah! Did you see the captain giving me dirty looks and decide to throw some sympathy my way? I\'ve pretty much lost hope of making him understand that these ruins offer us some opportunity to salvage some usefulness out of this whole mess.$B$BI\'d actually hoped that you might turn up again - you seem like the only one I can rely on. Wait... what\'s that you have there?', 0), -- Piece of the Past
(25969, 0, 1, 0, 0, 'These scroungers seem intensely curious about our equipment. Sometimes suicidally so. I wonder what attracts them to it so much.', 59185); -- Hostile Waters

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnIncompleteDelay`=1000, `VerifiedBuild`=59734 WHERE `ID`=26502; -- Thunder Stones
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59734 WHERE `ID`=27938; -- The Middle Fragment
UPDATE `quest_request_items` SET `CompletionText`='You must rescue Stonefather Oremantle. There\'s no time to waste, $N!', `VerifiedBuild`=59734 WHERE `ID`=26836; -- Rescue the Stonefather... and Flint
UPDATE `quest_request_items` SET `CompletionText`='Did you find suitable servants for me, $Ndamus?', `VerifiedBuild`=59185 WHERE `ID`=25330; -- Waste of Flesh
UPDATE `quest_request_items` SET `CompletionText`='Continue the fight, $N. Only a short while longer now.', `VerifiedBuild`=59185 WHERE `ID`=29195; -- A Ritual of Flame
UPDATE `quest_request_items` SET `CompletionText`='Well, $N?', `VerifiedBuild`=59185 WHERE `ID`=25314; -- Speech Writing for Dummies
UPDATE `quest_request_items` SET `CompletionText`='Well, $Ndamus.  Is it done?', `VerifiedBuild`=59185 WHERE `ID`=25309; -- Spiritual Training: Mercy is for the Weak
UPDATE `quest_request_items` SET `CompletionText`='Is it done yet, $N?', `VerifiedBuild`=59185 WHERE `ID`=25308; -- Seeds of Discord
UPDATE `quest_request_items` SET `CompletionText`='Did you get the documents, $N?', `VerifiedBuild`=59185 WHERE `ID`=25296; -- Gather the Intelligence
UPDATE `quest_request_items` SET `CompletionText`='Yes, $Ndamus?', `VerifiedBuild`=59185 WHERE `ID`=25224; -- In Bloom
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $N.', `VerifiedBuild`=59185 WHERE `ID`=25608; -- Slash and Burn
UPDATE `quest_request_items` SET `CompletionText`='Is it done yet, $N?', `VerifiedBuild`=59185 WHERE `ID`=25574; -- Flames from Above
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $N?', `VerifiedBuild`=59185 WHERE `ID`=25555; -- The Gatekeeper
UPDATE `quest_request_items` SET `CompletionText`='Did you succeed in your task, $N?', `VerifiedBuild`=59185 WHERE `ID`=25554; -- Secrets of the Flame
UPDATE `quest_request_items` SET `CompletionText`='It\'s good to see you, $N.', `VerifiedBuild`=59185 WHERE `ID`=25553; -- Death to the Broodmother
UPDATE `quest_request_items` SET `CompletionText`='Yes, $N?', `VerifiedBuild`=59185 WHERE `ID`=25551; -- The Firelord
UPDATE `quest_request_items` SET `CompletionText`='Yes, $N?', `VerifiedBuild`=59185 WHERE `ID`=25550; -- Magma Monarch
UPDATE `quest_request_items` SET `CompletionText`='Keep it up, $N.', `VerifiedBuild`=59185 WHERE `ID`=25549; -- The Sanctum of the Prophets
UPDATE `quest_request_items` SET `CompletionText`='What news do you bring, $N?', `VerifiedBuild`=59185 WHERE `ID`=25548; -- Might of the Firelord
UPDATE `quest_request_items` SET `CompletionText`='Is it done yet, $Ndamus?', `VerifiedBuild`=59185 WHERE `ID`=25509; -- Physical Training: Forced Labor
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $Ndamus?  Did our little champ make it out ok?', `VerifiedBuild`=59185 WHERE `ID`=25496; -- Grudge Match
UPDATE `quest_request_items` SET `CompletionText`='$N, I understand you\'re going to speak with our \"Warchief\" about joining your Horde.$B$BBe careful, $c.$B$BSee me afterwards... ', `VerifiedBuild`=59185 WHERE `ID`=26549; -- Madness
UPDATE `quest_request_items` SET `CompletionText`='I need you to get those Kor\'kon assassins safely to their destination, $N.', `VerifiedBuild`=59185 WHERE `ID`=27491; -- Kor'kron Drop
UPDATE `quest_request_items` SET `CompletionText`='Good to see you\'re still alive, $c. How goes your investigation?', `VerifiedBuild`=59185 WHERE `ID`=26830; -- Traitor's Bait
UPDATE `quest_request_items` SET `CompletionText`='What\'s the state of the beach head, $N?', `VerifiedBuild`=59185 WHERE `ID`=27610; -- Scouting the Shore
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $N.  Have you completed the task I request of you?', `VerifiedBuild`=59185 WHERE `ID`=28134; -- Impending Retribution
UPDATE `quest_request_items` SET `CompletionText`='Did you get the pieces, $N?', `VerifiedBuild`=59185 WHERE `ID`=27924; -- Budd's Plan
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $N?', `VerifiedBuild`=59185 WHERE `ID`=27923; -- Smoke in Their Eyes
UPDATE `quest_request_items` SET `CompletionText`='What did you witness, $N?', `VerifiedBuild`=59185 WHERE `ID`=27922; -- Traitors!
UPDATE `quest_request_items` SET `CompletionText`='I thank you for your help, $N.', `VerifiedBuild`=59185 WHERE `ID`=27519; -- Under the Choking Sands
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $N.', `VerifiedBuild`=59185 WHERE `ID`=28502; -- The Bandit Warlord
UPDATE `quest_request_items` SET `CompletionText`='Did you see, $N?', `VerifiedBuild`=59185 WHERE `ID`=28277; -- Salhet the Tactician
UPDATE `quest_request_items` SET `CompletionText`='Have you succeeded, $N?', `VerifiedBuild`=59185 WHERE `ID`=27836; -- Stopping the Spread
UPDATE `quest_request_items` SET `CompletionText`='Is it done, $N?', `VerifiedBuild`=59185 WHERE `ID`=28611; -- The Defilers' Ritual
UPDATE `quest_request_items` SET `CompletionText`='You\'ve returned, $N.  How are the recruitment efforts faring?', `VerifiedBuild`=59185 WHERE `ID`=28201; -- Ploughshares to Swords
UPDATE `quest_request_items` SET `CompletionText`='How much plunder did you get, $N?', `VerifiedBuild`=59185 WHERE `ID`=25976; -- Treasure Reclamation
UPDATE `quest_request_items` SET `CompletionText`='We haven\'t found the right combination yet, $N.  Keep at it!  I\'m sure you can figure it out!', `VerifiedBuild`=59185 WHERE `ID`=26126; -- The Perfect Fuel
UPDATE `quest_request_items` SET `CompletionText`='Do you have it, $N?$B$BWith the Unfathomable\'s brain, we still may yet be able to communicate with L\'ghorek, the dying ancient one in front of us.', `VerifiedBuild`=59185 WHERE `ID`=26111; -- ... It Will Come
UPDATE `quest_request_items` SET `CompletionText`='Save my wolf, $N.', `VerifiedBuild`=59185 WHERE `ID`=26091; -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
UPDATE `quest_request_items` SET `CompletionText`='Kill those fish-men, $N.', `VerifiedBuild`=59185 WHERE `ID`=26089; -- Die Fishman Die
UPDATE `quest_request_items` SET `CompletionText`='You\'d better keep trying, $N.  These naga aren\'t going anywhere unless you wake the creature up.', `VerifiedBuild`=59185 WHERE `ID`=25993; -- Body Blows
UPDATE `quest_request_items` SET `CompletionText`='The ritual is not yet complete, $N.', `VerifiedBuild`=59185 WHERE `ID`=25990; -- Breaking Through

DELETE FROM `creature_questender` WHERE `id`=39605 AND `quest` IN (26294,28717,26830,26798);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(39605, 26294, 59185), -- Weapons of Mass Dysfunction ended by Garrosh Hellscream
(39605, 28717, 59185), -- Warchief's Command: Twilight Highlands! ended by Garrosh Hellscream
(39605, 26830, 59185), -- Traitor's Bait ended by Garrosh Hellscream
(39605, 26798, 59185); -- The Warchief Will be Pleased ended by Garrosh Hellscream
