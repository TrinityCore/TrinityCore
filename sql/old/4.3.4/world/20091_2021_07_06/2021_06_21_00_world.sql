UPDATE `quest_offer_reward` SET `VerifiedBuild`=0; -- Clean incorrect data

DELETE FROM `quest_offer_reward` WHERE `ID` IN (8579 /*Mortal Champions*/, 27582 /*Infiltrating Shadowforge City*/, 27352 /*Liquid Gold*/, 27359 /*Argent Reinforcements*/, 27228 /*Man Against Abomination*/, 27230 /*Weapons for War*/, 27227 /*Lord Aurius Rivendare*/, 26969 /*Primal Strike*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(8579, 0, 0, 0, 0, 0, 0, 0, 0, 'I see that you\'re no ordinary mortal, $N.  Your chances against the Old God, however infinitely small, are greater than ours at this point.  After all, while he expects dragons at his doorstep, he is not prepared for someone like you.$B$BJust as Anachronos and Staghelm defeated the Qiraji a thousand years ago through the alliance of mortal and dragon races, we too shall form a pact.  Gain the trust of the Bronze Dragonflight and you\'ll gain our trust.  Only then we shall make a true champion out of you.', 13596), -- Mortal Champions
(27582, 0, 0, 0, 0, 0, 0, 0, 0, 'Beyond this door lies the commander of the Dark Iron Army, surrounded by trained soldiers. Are you up for a little killing?', 13596), -- Infiltrating Shadowforge City
(27352, 4, 0, 0, 0, 0, 0, 0, 0, 'Excellent! I think the holy water will prove devastating in large volumes.', 13596), -- Liquid Gold
(27359, 1, 0, 0, 0, 0, 0, 0, 0, 'Oh my... the banshees are very tortured souls indeed. Merely holding their essence is emotionally painful...$B$BEnough of that for now. I\'ll get to work on counteracting their magic, then we\'ll have a portal up and running in no time. Stratholme will be ours soon, I just know it.', 13596), -- Argent Reinforcements
(27228, 1, 0, 0, 0, 0, 0, 0, 0, 'I respect the power you demonstrated in killing Ramstein. With proper rage backing your actions, I think even the Scourge can know fear.', 13596), -- Man Against Abomination
(27230, 1, 0, 0, 0, 0, 0, 0, 0, 'Great! Without a steady flow of their weapons, we\'ll win through attrition!', 13596), -- Weapons for War
(27227, 1, 0, 0, 0, 0, 0, 0, 0, 'Stratholme will become a paragon of all that is good in this world. You have my thanks for your part in this mission.', 13596), -- Lord Aurius Rivendare
(26969, 1, 1, 0, 0, 0, 0, 0, 0, 'It is a pleasure to teach such a capable student. As long as you continue the traditons faithfully, the shamanic arts will never be lost to our people again. Return to me when you need further training.', 13596); -- Primal Strike

UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13596 WHERE `ID`=9371; -- Botanist Taerix

DELETE FROM `quest_offer_reward` WHERE `ID` IN (26219 /*Full Circle*/, 26005 /*A Breath of Fresh Air*/, 25626 /*Visions of the Past: Rise from the Deep*/, 25911 /*Welcome News*/, 25898 /*Honor and Privilege*/, 25894 /*Hostile Waters*/, 25895 /*Come Prepared*/, 25897 /*Unfurling Plan*/, 25893 /*Desperate Plan*/, 25892 /*Losing Ground*/, 25755 /*Visions of the Past: The Slaughter of Biel'aran Ridge*/, 25754 /*Gauging Success*/, 25753 /*Fallen But Not Forgotten*/, 25752 /*Swift Action*/, 25748 /*Clear Goals*/, 25749 /*Not Entirely Unprepared*/, 25751 /*Properly Inspired*/, 25747 /*Looking Forward*/, 25760 /*Visions of the Past: The Invasion of Vashj'ir*/, 27716 /*Piece of the Past*/, 25581 /*An Occupation of Time*/, 25583 /*Upon the Scene of Battle*/, 25582 /*A Better Vantage*/, 25579 /*Caught Off-Guard*/, 25580 /*Swift Approach*/, 27211 /*Propaganda War*/, 27210 /*Traitors Among Us*/, 24612 /*A Gift for High Overlord Saurfang*/, 28466 /*Weapons of Darkness*/, 27593 /*Rebirth of the K.E.F.*/, 27591 /*The Dark Iron Pact*/, 27589 /*The Grim Guzzler*/, 27585 /*The 109th Division*/, 24614 /*A Gift for the High Chieftain*/, 27992 /*Magnets, How Do They Work?*/, 27949 /*The Forgotten*/, 27944 /*Thinning the Brood*/, 27971 /*Rattling Their Cages*/, 27987 /*Cannonball!*/, 28130 /*Not The Friendliest Town*/, 26536 /*Thunder Falls*/, 26177 /*Feeling Crabby?*/, 26144 /*Prisoners*/, 26193 /*Defending the Rift*/, 26181 /*Back to Darkbreak Cove*/, 26132 /*Fiends from the Netherworld*/, 26070 /*Clearing the Defiled*/, 26056 /*The Wavespeaker*/, 25983 /*Promontory Point*/, 25987 /*Put It On*/, 25981 /*Those Aren't Masks*/, 25950 /*Sira'kess Slaying*/, 25977 /*A Standard Day for Azrajar*/, 25975 /*Treasure Reclamation*/, 26080 /*One Last Favor*/, 26021 /*The Brothers Digsong 2: Eel-Egg-Trick Boogaloo*/, 26017 /*A Lure*/, 26019 /*Enormous Eel Egg*/, 26018 /*Coldlights Out*/, 26015 /*Phosphora Hunting*/, 26014 /*The Brothers Digsong*/, 26106 /*Fuel-ology 101*/, 26103 /*Bio-Fuel*/, 26105 /*Claim Korthun's End*/, 28845 /*The Vortex Pinnacle*/, 28295 /*Meetup with the Caravan*/, 26726 /*Triumphant Return*/, 26714 /*Darkblaze, Brood of the Worldbreaker*/, 26713 /*Showdown at Stonewatch*/, 26708 /*AHHHHHHHHHHHH! AHHHHHHHHH!!!*/, 26694 /*The Grand Magus Doane*/, 26692 /*Shadowhide Extinction*/, 26693 /*The Dark Tower*/, 26668 /*Detonation*/, 26651 /*To Win a War, You Gotta Become War*/, 26646 /*Prisoners of War*/, 26637 /*Bravo Company Field Kit: Chloroform*/, 26638 /*Hunting the Hunters*/, 26640 /*Unspeakable Atrocities*/, 26636 /*Bravo Company Field Kit: Camouflage*/, 26639 /*Point of Contact: Brubaker*/, 26616 /*It's Never Over*/, 26607 /*They Drew First Blood*/, 26563 /*Return of the Bravo Company*/, 26562 /*And Last But Not Least... Danforth*/, 26561 /*Krakauer*/, 26569 /*Surveying Equipment*/, 26573 /*His Heart Must Be In It*/, 26560 /*Jorgensen*/, 26587 /*Breaking Out is Hard to Do*/, 26571 /*Weapons of War*/, 26586 /*In Search of Bravo Company*/, 26520 /*Saving Foreman Oslow*/, 26570 /*Render's Army*/, 26513 /*Like a Fart in the Wind*/, 26568 /*This Ain't My War*/, 26567 /*John J. Keeshan*/, 26545 /*Yowler Must Die!*/, 26519 /*He Who Controls the Ettins*/, 26544 /*They've Wised Up...*/, 26514 /*Canyon Romp*/, 26512 /*Tuning the Gnomecorder*/, 26510 /*We Must Prepare!*/, 26511 /*Lake Everstill Clean Up*/, 26505 /*Parker's Report*/, 26508 /*Nida's Necklace*/, 26506 /*Franks and Beans*/, 26504 /*Wanted: Redridge Gnolls*/, 26503 /*Still Assessing the Threat*/, 26509 /*An Unwelcome Guest*/, 26365 /*Hero's Call: Redridge Mountains!*/, 27621 /*Firebeard's Patrol*/, 27545 /*The Way is Open*/, 27537 /*Any Portal in a Storm*/, 27538 /*The Perfect Poultice*/, 27468 /*Siege Tank Rescue*/, 27178 /*Naga Reinforcements*/, 27177 /*Salvage Operation*/, 27200 /*Siren's Song*/, 27516 /*Wings Over Highbank*/, 27515 /*Roots'll Do 'Er*/, 27514 /*Bird Down! Bird Down!*/, 27433 /*Shredderectomy*/, 27366 /*Landgrab*/, 27341 /*Scouting the Shore*/, 27338 /*Our Boys on the Shore*/, 28599 /*Kurdran's Waitin'*/, 28598 /*Aiming High*/, 28597 /*Burnin' at Both Ends*/, 28596 /*Welcome to Highbank!*/, 28832 /*Twilight Shores*/, 28238 /*Twilight Shores*/, 27106 /*A Villain Unmasked*/, 27092 /*Cataclysm in the Catacombs*/, 27072 /*The Old Barracks*/, 28807 /*Expert Opinion*/, 27060 /*Unholy Cow*/, 27064 /*He's Holding Out on Us*/, 27044 /*Peasant Problems*/, 27038 /*Missing Parts*/, 26997 /*The Usual Suspects*/, 26975 /*Rallying the Fleet*/, 26977 /*Twilight Investigation*/, 26960 /*My Son, the Prince*/, 27398 /*The Battle Is Won, The War Goes On*/, 26190 /*A Fisherman's Feast*/, 26442 /*Rock Lobster*/, 28409 /*Something Brewed*/, 28411 /*Something Stewed*/, 28408 /*Something Bold*/, 28172 /*Done Nothing Wrong*/, 28174 /*Burning Vengeance*/, 28666 /*Hero's Call: Burning Steppes!*/, 27830 /*Their Hunt Continues*/, 27829 /*The Wrath of a Dragonflight*/, 27834 /*Baelog, the Glass Cannon*/, 27828 /*Eric, the Utility Dwarf*/, 27835 /*Olaf, the Big Fella'*/, 27827 /*The Swift, the Fierce, and the Stout*/, 27826 /*Into the Dragon's Mouth*/, 27794 /*Return to Blam*/, 27912 /*The Titans' Trove*/, 27763 /*To Fuselight Proper*/, 27762 /*Fuselight, Ho!*/, 28579 /*Hero's Call: Badlands!*/, 27455 /*Boys Will Be Boys*/, 27555 /*Fiona's Lucky Charm*/, 27450 /*Frederick's Fish Fancy*/, 27454 /*Just a Drop in the Bucket*/, 27453 /*Catalysm*/, 27452 /*Dark Garb*/, 27451 /*To Kill With Purpose*/, 27449 /*Honor and Strength*/, 27448 /*The Trek Continues*/, 27382 /*Rough Roads*/, 27432 /*Zaeldarr the Outcast*/, 27383 /*Little Pamela*/, 27381 /*Traveling Companions*/, 27373 /*Onward, to Light's Hope Chapel*/, 27372 /*A Gift For Fiona*/, 27371 /*What I Do Best*/, 27370 /*Tarenar Sunstrike*/, 27369 /*Greasing the Wheel*/, 27368 /*Just Encased*/, 27367 /*Gidwin Goldbraids*/, 27683 /*Into the Woods*/, 27166 /*Go Fletch!*/, 27158 /*The Battle for Andorhal*/, 26327 /*Anvilmar the Hero*/, 27833 /*Half-Ton Holdouts*/, 27825 /*Survival of the Fattest*/, 27824 /*The Good Stuff*/, 27823 /*A Dwarf's Got Needs*/, 27051 /*Through Persistence*/, 27050 /*Fungal Fury*/, 27049 /*Soft Rock*/, 27047 /*Motes*/, 27046 /*Fear of Boring*/, 27048 /*Underground Economy*/, 26761 /*Threat to the Kingdom*/, 26370 /*Return to Sentinel Hill*/, 26322 /*Rise of the Brotherhood*/, 25540 /*Bellies Await*/, 25538 /*Odor Coater*/, 25537 /*Art of Attraction*/, 25536 /*Cold Welcome*/, 25539 /*Clamming Up*/, 25535 /*A Powerful Need To Eat*/, 25922 /*Waking the Beast*/, 25921 /*Overseer Idra'kess*/, 25920 /*Still Valuable*/, 25918 /*Hopelessly Gearless*/, 25919 /*Body Blows*/, 25917 /*We Are Not Alone*/, 25916 /*Breaking Through*/, 25909 /*Capture the Crab*/, 25885 /*What? What? In My Gut...?*/, 25888 /*Decompression*/, 25824 /*Debriefing*/, 25812 /*Spelunking*/, 25467 /*Kliklak's Craw*/, 25377 /*The Horde's Hoard*/, 25558 /*All or Nothing*/, 25547 /*On Our Own Terms*/, 25545 /*To Arms!*/, 25564 /*Stormwind Elite Aquatic and Land Forces*/, 25546 /*Traveling on Our Stomachs*/, 25357 /*Buy Us Some Time*/, 28292 /*That's No Pyramid!*/, 27787 /*Skullcrusher the Mountain*/, 27784 /*The Hammer of Twilight*/, 27782 /*Mathias Needs You*/, 27745 /*A Fiery Reunion*/, 27744 /*Rune Ruination*/, 27742 /*A Little on the Side*/, 27743 /*While We're Here*/, 27720 /*Mr. Goldmine's Wild Ride*/, 27711 /*Back to the Elementium Depths*/, 27702 /*Coup de Grace*/, 27700 /*Dragon, Unchained*/, 27688 /*Distract Them for Me*/, 27659 /*Portal Overload*/, 27719 /*Water of Life*/, 27661 /*Fire the Cannon*/, 27695 /*The Elementium Axe*/, 27654 /*Bring the Hammer Down*/, 27652 /*Dark Assassins*/, 27657 /*Help from the Earthcaller*/, 27636 /*Just You and Mathias*/, 27502 /*Up to the Citadel*/, 27500 /*Four Heads are Better than None*/, 27498 /*Signal the Attack*/, 27494 /*Move the Mountain*/, 27490 /*SI:7 Drop*/, 27496 /*Call in the Artillery*/, 27492 /*Ogres & Ettins*/, 28248 /*Victors' Point*/, 28109 /*Pressing Forward*/, 28108 /*If The Key Fits*/, 28107 /*Paving the Way*/, 28104 /*Precious Goods*/, 28103 /*Easy Pickings*/, 28101 /*Mathias' Command*/, 27485 /*Warm Welcome*/, 27374 /*The Maw of Madness*/, 28655 /*Wild, Wild, Wildhammer Wedding*/, 28410 /*Something Stolen*/, 28413 /*Words and Music By...*/, 28407 /*The Bachelorette*/, 27651 /*Doing It Like a Dunwald*/, 27649 /*A Steady Supply*/, 27650 /*Home Again*/, 27648 /*Once More Into The Fire*/, 27641 /*While Meeting The Family*/, 27647 /*Anything But Water*/, 27642 /*Sifting Through The Wreckage*/, 27646 /*Finding Beak*/, 28378 /*Find Fanny*/, 28379 /*Ogre Bashin'*/, 28377 /*Rescue at Glopgut's Hollow*/, 28346 /*The Bachelor*/, 28294 /*The Kirthaven Summit*/, 28282 /*Narkrall, The Drake-Tamer*/, 28281 /*Last Stand at Thundermar*/, 28280 /*Tear Them From the Sky!*/, 28212 /*Hot Stuff*/, 28211 /*Tempered in Elemental Flame*/, 28216 /*Magmalord Falthazar*/, 28244 /*Eye Spy*/, 28243 /*The Eyes Have It*/, 28215 /*Potential Energy*/, 28242 /*We All Must Sacrifice*/, 28241 /*A Vision of Twilight*/, 27752 /*Fight Like a Wildhammer*/, 27754 /*Dragonmaw Takedown*/, 27753 /*Never Leave a Dinner Behind*/, 28369 /*My Sister, Fanny*/, 28001 /*A Coward's Due*/, 27643 /*Donnelly Dunwald*/, 27645 /*Cayden Dunwald*/, 27644 /*Eoin Dunwald*/, 27640 /*Dunwalds Don't Die*/, 27817 /*Dropping the Hammer*/, 27816 /*Personal Request*/, 27812 /*The Loyalty of Clan Mullan*/, 27811 /*The Scent of Battle*/, 27810 /*The Fighting Spirit*/, 27815 /*Somethin' for the Boys*/, 28234 /*They Took Me Pants!*/, 28233 /*The Lost Brother*/, 27814 /*Anything We Can Get*/, 27813 /*Death Worthy of a Dragonmaw*/, 27809 /*Firebeard Bellows*/, 27807 /*Clan Mullan*/, 27999 /*The Fate of the Doyles*/, 27808 /*Stubborn as a Doyle*/, 27805 /*Small Comforts*/, 27806 /*Honorable Bearing*/, 27803 /*Welcome Relief*/, 27804 /*The Only Homes We Have*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(26219, 1, 0, 0, 0, 0, 0, 0, 0, 'Vell done, Private $n.$B$BThe cavern is ours, but the beast escaped. Should it raise its ugly head again, ve vill make with blastink it out of the vater.', 13623), -- Full Circle
(26005, 1, 0, 0, 0, 0, 0, 0, 0, 'You made it out! Good to see you, $n.$B$BIt\'s good to be out of the water for a bit, and to have some resources at our disposal again. I\'m sure many of the boys would give anything to turn around and head home after what we\'ve been through, but we still have a grim task ahead.$B$BWhat about you? Want to stick it through to the end with us? I wouldn\'t blame you if you\'ve had your fill.', 13623), -- A Breath of Fresh Air
(25626, 1, 0, 0, 0, 0, 0, 0, 0, 'Minions of the Old God? Two very potent foes have joined forces then. Their hope to defeat the Tidehunter may not be so foolish after all.$B$B$n, we can\'t let that happen. If Azshara defeats the Tidehunter and takes his power for herself, I\'m not sure any number of us could ever hope to oppose her on the seas.$B$BThe first step is clear at least - we need to hunt down the fiend that destroyed our ships. The navy was confident enough to bring in a new fleet, perhaps they have a plan.', 13623), -- Visions of the Past: Rise from the Deep
(25911, 1, 0, 0, 0, 0, 0, 0, 0, 'That is the best news I\'ve heard in what seems like an eternity. We\'ll get the survivors moving over there to the surface as soon as possible. Perhaps we can forget that this whole nightmare ever happened.$B$BThank you, $n. I\'m not sure there\'s anything I can do to repay you for everything you\'ve managed to accomplish in this ocean, but I will try to find a way.$B$BYou should consider meeting us at the ships later, when you finish saying your goodbyes to the naga.', 13623), -- Welcome News
(25898, 1, 0, 0, 0, 0, 0, 0, 0, 'Perfect! There\'s no way they missed that, fighting or not.', 13623), -- Honor and Privilege
(25894, 1, 0, 0, 0, 0, 0, 0, 0, 'Less gill goblins is good!$B$BI\'m glad that they\'re so primitive. I don\'t think I\'d want to be dealing with a race of aquatic tech-freaks right now. Not at all.', 13623), -- Hostile Waters
(25895, 1, 0, 0, 0, 0, 0, 0, 0, 'Let me see, let me see... flare gun... balloon... no rope. Never any rope. Terribly impractical if you do ask me. Rope should be mandatory.', 13623), -- Come Prepared
(25897, 1, 0, 0, 0, 0, 0, 0, 0, 'This is great! I love it. It should work per... ewww! Is this stuff braided with hair?$B$BDoesn\'t matter. Almost done. This thing will be ready in the twist of a rope.', 13623), -- Unfurling Plan
(25893, 1, 0, 0, 0, 0, 0, 0, 0, 'Impeccable timing. Like clockwork! Trouble comes. You come. Save the day.  Clockwork!$B$BWe\'ve devised our brilliant plan. Gloriously simple, barring the hostility of local life. Simpler yet with a you available! ', 13623), -- Desperate Plan
(25892, 1, 0, 0, 0, 0, 0, 0, 0, 'You made it! After the attack at the forward post, I thought we might be the only ones left. I\'m very glad to see you.', 13623), -- Losing Ground
(25755, 6, 0, 0, 0, 0, 0, 0, 0, 'You\'re finished! Just in time. I don\'t think we could have held them much longer.$B$BAn artifact? Could this be something we can use against the naga? I suppose that would require finding it.$B$BWe may have to attend to more pressing matters first, until an opportunity to pursue this further presents itself.', 13623), -- Visions of the Past: The Slaughter of Biel'aran Ridge
(25754, 6, 1, 0, 0, 0, 60, 0, 0, 'Still so many? They must want something very important here to come in such numbers.$B$BI will be honest with you, $n, because you deserve at least that: I don\'t know how much hope there is. We will retreat shortly, but we won\'t be able to defend ourselves when they strike back. We don\'t have anywhere to run... we\'re running out of options.$B$BI\'m sorry, I should keep such thoughts to myself. Do me a favor and don\'t mention any of that to the men. I\'ll figure something out.', 13623), -- Gauging Success
(25753, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you. Truly.$B$BWe need to get these men moving as soon as possible. I\'ll meet you back at the forward post soon, I\'m sure.', 13623), -- Fallen But Not Forgotten
(25752, 1, 0, 0, 0, 0, 0, 0, 0, 'You did great up there! You devastated their ranks, but there were far more than we accounted for, and most of our men went down out there in the masses of naga.$B$BWe\'ll need to hold this position as long as possible to buy them time. Hopefully some of them will still make it to the rendezvous.', 13623), -- Swift Action
(25748, 1, 0, 0, 0, 0, 0, 0, 0, 'More naga are amassing to the south than reported too it seems. We shall have to move quickly then.', 13623), -- Clear Goals
(25749, 1, 0, 0, 0, 0, 0, 0, 0, 'You are perhaps the most dependable person I\'ve ever met. I wish I could have more men half as thorough as you.', 13623), -- Not Entirely Unprepared
(25751, 1, 0, 0, 0, 0, 0, 0, 0, 'You are brave indeed! I\'ve seen you battling all manner of murloc, naga, and pointy-toothed fish, but that was nothing! The way you just sling those kelp bulbs under your arm like that is a whole new kind of fearless. BOOM! You could blow up at any second.$B$BYou\'re my kind of $r.', 13623), -- Properly Inspired
(25747, 1, 0, 0, 0, 0, 0, 0, 0, 'Good to see you again, $c. I almost thought we\'d lost you to the Wavespeaker\'s fool errand.$B$BDid anything come of it?', 13623), -- Looking Forward
(25760, 6, 0, 0, 0, 0, 0, 0, 0, 'A Battlemaiden? I never heard of such a thing.$B$BThe way you explain it, it sounds like the naga forces are far greater in scope than the Admiral could possibly have realized. We might be able to learn more through the blade if we can find other locations where this Battlemaiden was present, but the information you gave me makes me fear for the admiral and his soldiers. We must warn them.', 13623), -- Visions of the Past: The Invasion of Vashj'ir
(27716, 1, 0, 0, 0, 0, 0, 0, 0, 'Brilliant! It will take me a while to translate, but this is precisely the kind of find I was hoping for.$B$BThere\'s no knowing if we will make it out of this place, but if it comes down to it, I will find a way to float this to the surface in hopes that it will one day be found.$B$BThank you again, $n. Here... perhaps I have something that may be of use to you.', 13623), -- Piece of the Past
(25581, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you so much for taking this seriously.$B$BThis is some of the first definitive proof of other members of the Vashj family. Very interesting. And I\'d never even heard of either of the other two figures you mentioned until now.$B$BSo much of our history was lost during the sundering - it\'s exciting to have a chance at reclaiming some of it.', 13623), -- An Occupation of Time
(25583, 1, 1, 0, 0, 0, 60, 0, 0, 'Interesting indeed.$B$BThe remains you describe sound much like the sea vrykul we encountered in Northrend. I highly doubt we will be striking any alliances with their sort, no matter the cause. Still, this information may prove useful in the future.$B$BI will think on it further if time permits. Thank you for bringing it to my attention.', 13623), -- Upon the Scene of Battle
(25582, 1, 0, 0, 0, 0, 0, 0, 0, 'This is good intel. You have a sharp eye, $c.$B$BIt sounds like the building tucked under the terrace at the far end of the ruins will make a suitable forward post. I will send some men immediately to start defensive preparations and we will reposition there as soon as possible.', 13623), -- A Better Vantage
(25579, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent work, $c.$B$BI will get some of our own patrols out to make sure that no more naga get within sight of this cave. We should have the area secured within the hour.', 13623), -- Caught Off-Guard
(25580, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $n, and just in time too. The Admiral just started sending more men out. Strong sword arms to be sure, but I doubt they possess quite the same awareness and finesse that you do.$B$BWe were lucky to have you here when things went south. I suspect you will have a large role to play in things to come as well.', 13623), -- Swift Approach
(27211, 1, 1, 0, 0, 0, 0, 0, 0, '<The SI:7 agent nods in approval.>$B$BExcellent. All that remains is to discredit the deserters so that they\'ll never gain a foothold in Theramore again, and I have just the plan to do it.', 13623), -- Propaganda War
(27210, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $N. I think we managed to catch them off guard. Their agents probably thought themselves safe within the city walls.$B$BGiven time, the agitators will return and spread their lies again. We\'ll use the time you\'ve bought to shut out the deserters further.', 13623), -- Traitors Among Us
(24612, 2, 0, 0, 0, 0, 0, 0, 0, 'My \"thanks\" for this Lovely Charm Bracelet.', 13623), -- A Gift for High Overlord Saurfang
(28466, 1, 1, 0, 0, 0, 0, 0, 0, 'Without those weapons, the Dark Irons will never be a match for the Horde. You have served your brothers and sisters well this day, $N.', 13623), -- Weapons of Darkness
(27593, 396, 396, 71, 2, 0, 0, 0, 0, 'A true $c if I\'ve ever seen one! You\'ve done the impossible! I knew we could count on you.$B$B<Warlord Goretooth pauses, smiling.>$B$BAnd with that, I\'d like for you to be the first to know that the Kargath Expeditionary Force is now officially back in business!$B$BI extend to you my personal gratitude for your efforts here. Remember always our motto: \"First in, last out, always victorious. Remember always Kargath.\"$B$BYou are dismissed.', 13623), -- Rebirth of the K.E.F.
(27591, 0, 0, 0, 0, 0, 0, 0, 0, 'I cannot proceed any further alone, regardless of my combat experience. The Lyceum has proven too difficult for me. If you are here, though...you might be the key to all of this.', 13623), -- The Dark Iron Pact
(27589, 0, 0, 0, 0, 0, 0, 0, 0, 'I hear quite the commotion coming from the Grim Guzzler. I see you\'ve been hard at work.$B$BIf you\'ll direct your attention opposite me, you\'ll notice that we have bigger issues to worry about than toying with drunkards.', 13623), -- The Grim Guzzler
(27585, 0, 0, 0, 0, 0, 0, 0, 0, 'Up ahead is the Grim Guzzler. A disgusting bar full of all our enemies, intoxicated and therefore unfit for proper battle.$B$B<Hierophant Theodora Mulvadania grins.>$B$BRipe for the slaughter.', 13623), -- The 109th Division
(24614, 2, 0, 0, 0, 0, 0, 0, 0, 'My thanks for this Lovely Charm Bracelet.', 13623), -- A Gift for the High Chieftain
(27992, 0, 0, 0, 0, 0, 0, 0, 0, 'These parts will really help us out, $n!  Who would have thought you can find stuff this useful in all that old junk?', 13623), -- Magnets, How Do They Work?
(27949, 0, 0, 0, 0, 0, 0, 0, 0, 'May their souls rest in peace.', 13623), -- The Forgotten
(27944, 0, 0, 0, 0, 0, 0, 0, 0, 'Nice work on those spiders $n.  At this rate, we will be taking that forest in no time.', 13623), -- Thinning the Brood
(27971, 0, 0, 0, 0, 0, 0, 0, 0, 'Nice work on the undead up there $n.  We really appreciate the help.', 13623), -- Rattling Their Cages
(27987, 0, 0, 0, 0, 0, 0, 0, 0, 'Good job on the recovery effort $n. These cannonballs should last us a while.', 13623), -- Cannonball!
(28130, 0, 0, 0, 0, 0, 0, 0, 0, 'Told you that village was full of wackos.  Nice job clearing it out $n.', 13623), -- Not The Friendliest Town
(26536, 1, 1, 5, 0, 0, 0, 0, 0, 'These perch look great $N.  Why don\'t you join us for a fish fry tonight?', 13623), -- Thunder Falls
(26177, 2, 0, 0, 0, 0, 0, 0, 0, 'These crabs look great!  I will clean these up and make sure that the King hears about your contribution.  Thanks!', 13623), -- Feeling Crabby?
(26144, 0, 0, 0, 0, 0, 0, 0, 0, 'A job well done. Now you don\'t need to worry about what would have happened to them if you hadn\'t been around.$B$BThe last one was even appreciative enough to give you a reward they\'d kept hidden on their person.', 13623), -- Prisoners
(26193, 396, 0, 0, 0, 0, 0, 0, 0, 'NO!$b$bThis is NOT over!', 13623), -- Defending the Rift
(26181, 0, 0, 0, 0, 0, 0, 0, 0, 'Hello again, $c.$B$BI felt L\'ghorek die. A shame that such a magnificent being is gone.$B$BIf we do not assist Neptulon, we will all meet the same fate.', 13623), -- Back to Darkbreak Cove
(26132, 1, 0, 0, 0, 0, 0, 0, 0, 'The last thing we needed was a bunch of summoned creatures swarming our forces during the final assault.', 13623), -- Fiends from the Netherworld
(26070, 1, 0, 0, 0, 0, 0, 0, 0, 'Good enough for me.$B$BDon\'t get too complacent, $N. The hard part\'s about to come.', 13623), -- Clearing the Defiled
(26056, 1, 0, 0, 0, 0, 0, 0, 0, 'I sure am glad you\'re here!', 13623), -- The Wavespeaker
(25983, 66, 0, 0, 0, 0, 0, 0, 0, 'That\'s very disturbing news, but I believe our Earthen Ring friends here have a plan.$B$BAnd now that you\'re here....', 13623), -- Promontory Point
(25987, 5, 6, 0, 0, 0, 0, 0, 0, 'What happened? That thing wasn\'t completely dead! Maybe I should stick to mechanical stuff.$B$BIt gave you a vision? Of killing all of us?! That doesn\'t sound good.$B$BWell, in any case, that Earthen Ring fellow, Erunak Stonespeaker, wants these specimens all taken out to him. I\'ll make sure he gets them. I don\'t want them anywhere near me.', 13623), -- Put It On
(25981, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, they\'re ugly, but they mostly look harmless. Smelly though.$B$BHere, let me clean the gilblin stuff out of these. I\'ve got an idea....', 13623), -- Those Aren't Masks
(25950, 4, 6, 0, 0, 0, 0, 0, 0, 'Chicken and rice, $N! That will show those sorry and sad snakes who\'s the ol\' pitch and toss!$B$BNow it\'s bird lime for that tiddlywink. Finger and thumb or plink plonk?', 13623), -- Sira'kess Slaying
(25977, 6, 0, 0, 0, 0, 0, 0, 0, 'Nice Uncle Bob of pokin\' their general.$B$B<The lieutenant shakes her head and grins.>', 13623), -- A Standard Day for Azrajar
(25975, 1, 0, 0, 0, 0, 0, 0, 0, 'That should be enough for now. We know where there\'s more should the need arise.', 13623), -- Treasure Reclamation
(26080, 0, 0, 0, 0, 0, 0, 0, 0, 'I see.  Yes, I am rememberink now... Humphrey and Oskar vere not the strongest svimmers.$b$bThe reconnaissance is helpful, and the extra fish look very tasty.  If you are seeink Mister Digsong before he returns, please send him my thanks.', 13623), -- One Last Favor
(26021, 0, 0, 0, 0, 0, 0, 0, 0, 'Oskar\'s alive?  Wait... what did ya say?  Ya let him FLOAT AWAY AGAIN?!$b$bWell... ya held up your end of the bargain, and I appreciate everything ya\'ve done, $N.$b$bHere... take this.  I\'ve only been hanging onto it as ballast, but it doesn\'t seem to be doing much good.', 13623), -- The Brothers Digsong 2: Eel-Egg-Trick Boogaloo
(26017, 0, 0, 0, 0, 0, 0, 0, 0, 'Ya did good, $N!  Ya did real good!', 13623), -- A Lure
(26019, 0, 0, 0, 0, 0, 0, 0, 0, 'Whaaa... an egg?  An EEL egg?$b$b<Even upside-down, you can see the gears in Humphrey\'s head turning.>$b$bWe can definitely do something with this!  Get ready kid, \'cause it\'s time for some good ol\'-fashioned Digsong revenge!', 13623), -- Enormous Eel Egg
(26018, 0, 0, 0, 0, 0, 0, 0, 0, '<Humphrey listens as you recount your fights with the Coldlight murlocs.>$b$bHmm... they sound like regular ol\' murlocs... just underwater.  That\'ll make Cap\'n Glovaal happy.', 13623), -- Coldlights Out
(26015, 0, 0, 0, 0, 0, 0, 0, 0, '<Humphrey grabs the phosphora from you and attaches it to an unusual device.>$b$bThere ya go.  It\'s beautiful!  Oskar would be proud.', 13623), -- Phosphora Hunting
(26014, 18, 18, 18, 0, 0, 3000, 5000, 0, 'Of course we haven\'t returned yet!  We\'ve had our fair share of setbacks... not the least of which was the passing of my dear brother Oskar.$b$b<Humphrey sniffles loudly.>$b$bHe lost his grip and floated away, the poor lad!  He thought he\'d grab some fish to bring back to the captain, but he floated off, and was eaten by one o\' those... those great-eels!  Bwaaaah ha ha haaaah!', 13623), -- The Brothers Digsong
(26106, 0, 0, 0, 0, 0, 0, 0, 0, 'Have you considered a career in science, $N?  If you ever get tired of this $c nonsense, come see me!  I could use an assistant with your devotion to experimentation and the scientific method.', 13623), -- Fuel-ology 101
(26103, 0, 0, 0, 0, 0, 0, 0, 0, '<Engineer Hexascrub sticks a finger into each sample and sniffs it.>$b$bYes, I think this will do.', 13623), -- Bio-Fuel
(26105, 273, 396, 0, 0, 0, 0, 0, 0, 'You did well, $N.  We need to be especially wary of Horde attacks right now.  The Pincer X2 has plenty of firepower at sea, but in the back of this cave, she is exceptionally vulnerable.', 13623), -- Claim Korthun's End
(28845, 0, 0, 0, 0, 0, 0, 0, 0, 'You actually came here looking for me?', 13623), -- The Vortex Pinnacle
(28295, 6, 0, 0, 0, 0, 0, 0, 0, 'Harrison sent you, hmm?$b$bHow fortunate!', 13623), -- Meetup with the Caravan
(26726, 1, 1, 2, 0, 0, 0, 0, 0, 'They will never be forgotten, $N. What you and the rest of Bravo Company sacrificed in order to save Redridge will be a tale told for ages to come.$B$BWhile I can in no way make up for the loss of your friends, I feel that you must be rewarded for such a heroic deed. These are Keeshan\'s possessions - the only things we found when we dredged the lake for his body. Troteman has informed me that Keeshan would have wanted you to take something as the lone surviving member of Bravo Company. Remember them, $N!', 13623), -- Triumphant Return
(26714, 1, 66, 0, 0, 0, 0, 0, 0, '<A single tear rolls down Troteman\'s left cheek.>$B$BThey died in defense of the Alliance. In defense of our kingdom! Heroes, all of them, and they will be laid to rest as such.', 13623), -- Darkblaze, Brood of the Worldbreaker
(26713, 0, 0, 0, 0, 0, 0, 0, 0, '<The Bravo Company field kit beeps loudly.>$B$BCome in, $N. Are you there? If you can hear me: Blackrock has the upper hand. I repeat. Blackrock has the upper hand. GET BRAVO COMPANY OUT OF TH...$B$B<Troteman cuts out.>', 13623), -- Showdown at Stonewatch
(26708, 1, 0, 0, 0, 0, 0, 0, 0, 'The only thing left to deal with now are the orcs holding out at Stonewatch Keep.', 13623), -- AHHHHHHHHHHHH! AHHHHHHHHH!!!
(26694, 0, 0, 0, 0, 0, 0, 0, 0, 'He teleported away? Mentioned Darkblaze? What the hell is going on here.$B$BLooks like it\'s time to strap in and finish this nonsense.', 13623), -- The Grand Magus Doane
(26692, 1, 0, 0, 0, 0, 0, 0, 0, 'We\'re closing in on the Blackrock high command. There\'s nowhere left for those dogs to run.', 13623), -- Shadowhide Extinction
(26693, 1, 0, 0, 0, 0, 0, 0, 0, '<Keeshan comes in over the Bravo Company field kit.>$B$BNow that the easy part is over, it\'s time for phase two.', 13623), -- The Dark Tower
(26668, 0, 0, 0, 0, 0, 0, 0, 0, 'Did you see those orcs explode? THAT\'S HOW WE DO IT IN BRAVO COMPANY! Now to clean up the rest of these jackasses.', 13623), -- Detonation
(26651, 1, 0, 0, 0, 0, 0, 0, 0, 'And now, we blow the whole damned thing up.', 13623), -- To Win a War, You Gotta Become War
(26646, 0, 0, 0, 0, 0, 0, 0, 0, '<The radio on the Bravo Company field kit crackles.>$B$BLooks like the P.O.W.s are free. Time to initiate Operation: End All.', 13623), -- Prisoners of War
(26637, 5, 0, 0, 0, 0, 0, 0, 0, 'Perfect. Those orcs won\'t know what hit \'em - literally. I\'ll need a few minutes to get these in working order and then I\'ll put them in the Bravo Company field kit.', 13623), -- Bravo Company Field Kit: Chloroform
(26638, 1, 0, 0, 0, 0, 0, 0, 0, 'Great work, $N. We need to move quickly before they send for reinforcements.', 13623), -- Hunting the Hunters
(26640, 5, 6, 0, 0, 0, 0, 0, 0, '<Keeshan reads the report.>$B$BDAMN IT! This just got complicated. We\'ve got prisoners of war to rescue before we can blow up the valley. Not to mention the orcs have black dragons on their side.$B$BAre you ready, $N?', 13623), -- Unspeakable Atrocities
(26636, 1, 0, 0, 0, 0, 0, 0, 0, 'Nice job, rookie. I\'m gonna go ahead and put the camo in the box. We should be ready soon.', 13623), -- Bravo Company Field Kit: Camouflage
(26639, 0, 0, 0, 0, 0, 0, 0, 0, 'Brubaker is dead. It looks like the orcs are attempting to send a message with this grisly display. Upon closer examination you notice something in Brubaker\'s pouch.', 13623), -- Point of Contact: Brubaker
(26616, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s orc killin\' time.', 13623), -- It's Never Over
(26607, 1, 1, 25, 0, 0, 0, 0, 0, '<Keeshan takes the bundle from you and opens it.>$B$BMy bow... and knife! Where did you...$B$BJade\'s amulet... My darling Jade.$B$B<Keeshan picks up his red headband.>$B$BWe got orcs to kill.', 13623), -- They Drew First Blood
(26563, 66, 1, 1, 0, 0, 0, 0, 0, '<Colonel Troteman salutes.>$B$BUnbelievable work, $N. You\'ve managed to rescue the entire Bravo Company from the clutches of the Blackrock orcs? With Keeshan\'s team rescued and Keeshan\'s belongings returned, there\'s no way Keeshan could refuse us.', 13623), -- Return of the Bravo Company
(26562, 1, 1, 0, 0, 0, 0, 0, 0, 'About damn time you sissies showed up. My arms were gettin\' tired.\n', 13623), -- And Last But Not Least... Danforth
(26561, 0, 0, 0, 0, 0, 0, 0, 0, 'Wha... Where am I? What happened? Messner? Jorgensen?$B$BOH MY GOSH! We have to get to Danforth! It might already be too late!\n', 13623), -- Krakauer
(26569, 4, 1, 273, 0, 0, 0, 0, 0, 'Fantastic work, $N! These will come in handy for our next project, the Lakeshire SUPER BRIDGE, meant to traverse the length of Lake Everstill. It should be done in 20 or so years. Give or take a decade or two.', 13623), -- Surveying Equipment
(26573, 1, 1, 0, 0, 0, 0, 0, 0, 'I hope with these items and with his crew all rescued he\'ll have a change of heart. We can\'t do this without Keeshan.  ', 13623), -- His Heart Must Be In It
(26560, 5, 0, 0, 0, 0, 0, 0, 0, 'I know where they\'re holding Krakauer and Danforth. We gotta hurry. They were prepping those two for a sacrifice!', 13623), -- Jorgensen
(26587, 15, 0, 0, 0, 0, 0, 0, 0, 'IT\'S PAYBACK TIME!', 13623), -- Breaking Out is Hard to Do
(26571, 0, 0, 0, 0, 0, 0, 0, 0, '<The gnomecorder buzzes with energy.>$B$BCome in, $N. Do you copy? Troteman here! Great job on getting Keeshan\'s weapons back! Now there\'s one final mission you have to run. Are you up to the challenge?', 13623), -- Weapons of War
(26586, 6, 5, 1, 0, 0, 0, 0, 0, 'Keeshan? You mean JOHNNY\'S ALIVE? You bet your sweet behind I\'ll help, but first you gotta get me out of this damned cage.', 13623), -- In Search of Bravo Company
(26520, 5, 0, 0, 0, 0, 0, 0, 0, 'You used an ettin to remove the boulder that was crushing Foreman Oslow? Incredible work, $N! Oslow will be grateful once he regains his composure.', 13623), -- Saving Foreman Oslow
(26570, 1, 1, 0, 0, 0, 0, 0, 0, 'You\'ve probably bought us another day, maybe two. Nice work, $N.', 13623), -- Render's Army
(26513, 2, 1, 0, 0, 0, 0, 0, 0, 'Thank you, citizen. Without you, we would have starved or worse, been forced to go out and get food for ourselves.', 13623), -- Like a Fart in the Wind
(26568, 1, 1, 0, 0, 0, 0, 0, 0, '<Troteman sighs.>$B$BI\'m not giving up on him, $N, and I\'m not giving up on Redridge. We need to boost his spirits... Rouse the slumbering monster within him!', 13623), -- This Ain't My War
(26567, 0, 0, 0, 0, 0, 0, 0, 0, 'Help you? Help these people? These people that would rather spit on me than crack a smile?', 13623), -- John J. Keeshan
(26545, 5, 1, 1, 0, 0, 0, 0, 0, '<Magistrate Solomon takes the plans from you and begins reading.>$B$BShadowhide army!? Damn those orcs to hell! These invasion plans speak of a massive build up of orcish and gnoll forces in the east. Looks like Gath\'Ilzogg, the Blackrock general, is preparing to march his armies across Lakeshire and attack Stormwind directly!', 13623), -- Yowler Must Die!
(26519, 0, 0, 0, 0, 0, 0, 0, 0, '<The orb hisses as you touch it.>', 13623), -- He Who Controls the Ettins
(26544, 0, 0, 0, 0, 0, 0, 0, 0, '<The gnomecorder buzzes and whirs.>$B$BJust put the missive in the little compartment and I\'ll read it. I am fluent in orcish.$B$B<You hear a distraught yell in the background.>$B$BIt looks like these orcs are here under the direct command of Yowler. That means Yowler must have the orc invasion plan.', 13623), -- They've Wised Up...
(26514, 0, 0, 0, 0, 0, 0, 0, 0, '<The gnomecorder crackles and pops.>$B$BGood work, $N. I\'ve just been handed some important information. It would appear that our most hated enemy, the Blackrock orcs, have wised up...$B$B<The gnomecorder whirs as a compartment opens up.>$B$BI\'ve transferred a few silver over to you for the gnome, erm, gnoll kills.', 13623), -- Canyon Romp
(26512, 0, 0, 0, 0, 0, 0, 0, 0, '<The gnomecorder crackles and pops.>$B$BCan you hear me, $N? Is this thing on? Ah, yes, I see you there now.$B$BLet\'s get to work!', 13623), -- Tuning the Gnomecorder
(26510, 5, 1, 0, 0, 0, 0, 0, 0, 'Excellent! Let me make a few adjustments here and we should be good to go.', 13623), -- We Must Prepare!
(26511, 1, 0, 0, 0, 0, 0, 0, 0, 'That ought to teach those murlocs a lesson. Hopefully the next time they decide to raid our town they\'ll think twice.$B$BWe both know that won\'t happen.', 13623), -- Lake Everstill Clean Up
(26505, 1, 1, 6, 5, 0, 0, 0, 0, '<Magistrate Solomon puts on his monocle.>$B$BOh, you\'re not Conacher. What have you got there?$B$B<Magistrate Solomon takes Parker\'s report from you.>$B$BOh for pity\'s sake. Yowler? AGAIN?', 13623), -- Parker's Report
(26508, 4, 1, 6, 0, 0, 0, 0, 0, 'Thank you for finding my necklace $G mister : miss; $c... you are very kind!  My kitty thanks you too - isn\'t that right Effsee?', 13623), -- Nida's Necklace
(26506, 4, 1, 2, 0, 0, 0, 0, 0, 'PERFECT! I\'ll put these in the pot right away. Dinner should be ready in a few hours.$B$BThank you, darling!', 13623), -- Franks and Beans
(26504, 0, 0, 0, 0, 0, 0, 0, 0, 'A job well done deserves a reward, wouldn\'t you say?$B$BDon\'t spend this all in one place, $c. Better to spread it around, if you catch my drift.', 13623), -- Wanted: Redridge Gnolls
(26503, 0, 0, 0, 0, 0, 0, 0, 0, 'I knew it! Looks like Yowler is behind this uprising - which is incredible, because we keep killing gnolls named Yowler. I don\'t know how many sons the original Yowler had, but it\'s got to be close to a hundred.$B$BWell, looks like we got ourselves another Yowler to kill.$B$BMagistrate Solomon must be notified.', 13623), -- Still Assessing the Threat
(26509, 4, 0, 0, 0, 0, 0, 0, 0, 'Finally the menace is laid to rest!  Thank you, $n, you have done me a great service.  The garden shall be in full bloom this season!', 13623), -- An Unwelcome Guest
(26365, 0, 0, 0, 0, 0, 0, 0, 0, 'Heard Westfall was in some deep doody.$B$B<Parker doesn\'t even turn to face you.>$B$BWell, we got our own set of problems here. See them gnolls out there? Looks like they\'re actin\' up again. I don\'t like it. Don\'t like it one bit.', 13623), -- Hero's Call: Redridge Mountains!
(27621, 6, 396, 0, 0, 0, 60, 0, 0, 'Come to join the patrol, $glad:lass;? Glad to have ya.$B$BI need some bodies helpin\' to get our defenses under control here. Help me out and I\'ll see if I can\'t find some more prestigious work for ya.', 13623), -- Firebeard's Patrol
(27545, 4, 1, 0, 0, 0, 0, 0, 0, 'Ho! I knew you were a $c I could count on, $N. Use that portal anytime you need to get from Stormwind back to the Highlands.$B$BNow then, time to get to business. We need to locate and unite the lost Wildhammer clans scattered around the Highlands. Talking with Thordun here is a good start!', 13623), -- The Way is Open
(27537, 5, 1, 0, 0, 0, 0, 0, 0, 'My word, $N. These elemental energies are so powerful, so chaotic - no wonder the Twilight\'s Hammer has chosen to build their stronghold here!$B$BI should be able to channel these energies into something more benign and productive though. Let\'s give it a try...', 13623), -- Any Portal in a Storm
(27538, 6, 1, 273, 0, 0, 0, 0, 0, 'Oh... mud. You brought me mud?$B$BWow - this stuff oozes with power! I see what Thordun was saying, now. I\'ll distribute this to all of the healers. Our wounded will be on their feet in no time!', 13623), -- The Perfect Poultice
(27468, 274, 5, 0, 0, 0, 0, 0, 0, 'Yep, one more tank limpin\' back home for repairs.$B$BAll these trees an\' stumps an\' mud an\' rock - you couldnae drive a golfball into this turf, much less a tank.$B$BWe\'re gonna need a new approach.', 13623), -- Siege Tank Rescue
(27178, 4, 1, 0, 0, 0, 0, 0, 0, 'That\'ll send \'em packing, $N! Cho\'gall won\'t be able to count on the naga to back him up in this fight. From here on out, it\'s just us versus the Twilight\'s Hammer.$B$B<Simon pauses, his jaw tightening.>$B$B...And the Horde.', 13623), -- Naga Reinforcements
(27177, 5, 1, 0, 0, 0, 0, 0, 0, 'Look at all this! You were able to recover more than I thought. We can outfit a whole squad of marines with this stuff.$B$BWe have the gear. If we only had some way to bolster our numbers here in the Highlands...', 13623), -- Salvage Operation
(27200, 274, 2, 0, 0, 0, 0, 0, 0, 'She had me under her spell, $N. I wouldn\'t have made it out of there alive if it weren\'t for you. Thank you!$B$BMaybe the rest of the Alliance fleet can finally anchor here in peace...', 13623), -- Siren's Song
(27516, 5, 1, 0, 0, 0, 0, 0, 0, 'Well done, $N! Aiding that downed gryphon-rider has given us our first contact with the old Wildhammer clans. We\'ll be able to find out who\'s still left, and in what numbers.$B$BOur campaign is looking up!', 13623), -- Wings Over Highbank
(27515, 5, 1, 0, 0, 0, 0, 0, 0, 'Oh, that\'s the stuff all right! Hope ya didn\'t eat any. Gives you the cramps something awful but it does wonders for birds.', 13623), -- Roots'll Do 'Er
(27514, 6, 274, 0, 0, 0, 0, 0, 0, 'Aw dang crap it all. You\'re just an Alliance $c. I was hoping for a rescue.', 13623), -- Bird Down! Bird Down!
(27433, 6, 5, 0, 0, 0, 0, 0, 0, 'Oh aye, tha\'s the stuff! A good engineer can make anything outta just about anything.$B$BThis here doo-jicker could recouple a busted cylinder casing... Oh! And who doesn\'t want a dongle? ...And you can fashion this jobby into a ... thing.$B$B<Flintlocke sticks one of the grease-smeared engine parts into his mouth.>$B$BYep, perfect.', 13623), -- Shredderectomy
(27366, 1, 273, 0, 0, 0, 0, 0, 0, 'Dead? By the dozen?$B$BIt\'s a start, $c. It\'s a start.', 13623), -- Landgrab
(27341, 273, 1, 0, 0, 0, 0, 0, 0, 'That\'s the lay of the land, soldier. If you\'re having trouble fighting here on the coast, you might consider pitching in and helping us take and hold that hill.', 13623), -- Scouting the Shore
(27338, 5, 0, 0, 0, 0, 0, 0, 0, 'Keep your head down \'fore you lose it, $c!$B$BThis is MY beach.$B$BThe Horde WANTS my beach.$B$BThey will NOT have my beach.$B$BIs the beach situation clear?', 13623), -- Our Boys on the Shore
(28599, 1, 0, 0, 0, 0, 0, 0, 0, 'The King himself sent you? Good to hear that Stormwind is secure.$B$BI was expecting more in the way of troops, but word is that the Alliance fleet was ambushed by the Horde on the way here. They gave as good as they got, but the fleet is in shambles.$B$BIf we\'re to make any forward progress here in the Highlands, we\'re going to need the help of heroes like you.', 13623), -- Kurdran's Waitin'
(28598, 1, 0, 0, 0, 0, 0, 0, 0, '<Flintlocke wipes tears from his eyes.>$B$BOh, $N. $N!$B$BThat ... were beautiful.', 13623), -- Aiming High
(28597, 5, 0, 0, 0, 0, 0, 0, 0, 'Aye, that\'ll do \'er.$B$B<Flintlocke stuffs some of the powder in his mouth.>$B$BOhhh, fresh. Heady. Redridge fine grain with a hint of Westfall sulphur and a mild aftertaste. Highbank gets the good stuff. ', 13623), -- Burnin' at Both Ends
(28596, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s more like it. We should be able to mop this up from here.', 13623), -- Welcome to Highbank!
(28832, 5, 0, 0, 0, 0, 0, 0, 0, 'You two are the last thing I expected to see fall from the sky. Highbank is under attack!', 13623), -- Twilight Shores
(28238, 6, 1, 0, 0, 0, 0, 0, 0, 'A ride to the Highlands, then? I\'ve just the thing!$B$BI\'ll make room for yeh in me seaplane. I\'ll have to ditch the cat-food I was packing, yeh know, in case we crash in the mountains and ain\'t rescued fer weeks.$B$BOn second thought, jes\' keep the cat food on yer lap, aye. ', 13623), -- Twilight Shores
(27106, 274, 6, 1, 0, 0, 0, 0, 0, 'Samuelson - corrupted by the Twilight\'s Hammer? This must have been going on for years. Right here in my very keep!$B$BI am grateful that you and my son were able to get to the bottom of this before my city was brought to harm. I\'ve underestimated how much Anduin has grown - his command of the holy light just saved my life, if not the entire kingdom.$B$BAs for you - words alone can\'t do justice to your heroism this day. Thank you, $c.', 13623), -- A Villain Unmasked
(27092, 0, 0, 0, 0, 0, 0, 0, 0, '<3 ... 2 ... 1 ...>$B$B<You wet your fingers and snuff out the fuse. The cathedral is saved!>$B$BUnderneath the powder kegs you find a heap of notes and papers. Apparently the cultists were trying to destroy the evidence behind them.>', 13623), -- Cataclysm in the Catacombs
(27072, 5, 0, 0, 0, 0, 0, 0, 0, '<You slap Bauden around until he wakes up.>$B$B$C? What are you doing here?$B$BI\'m SI:7 Agent Jack Bauden. This is the longest day of my life.', 13623), -- The Old Barracks
(28807, 1, 6, 0, 0, 0, 0, 0, 0, 'Anduin has been investigating the Twilight\'s Hammer? Weren\'t you supposed to keep him OUT of trouble?$B$BHmmm. Let me see those badges you\'ve discovered.', 13623), -- Expert Opinion
(27060, 1, 6, 0, 0, 0, 0, 0, 0, 'That was a close one! I can\'t believe you stood your ground against so many at once.$B$BIt looks like this site was used for some kind of twisted Twilight\'s Hammer initiation ritual. They\'re definitely active in Stormwind. What\'s this?$B$B<Anduin finds a badge resting on the shrine.>$B$BThis badge shows a crossed axe and hammer. It looks old. If we keep poking around, we might figure out what it means...', 13623), -- Unholy Cow
(27064, 1, 6, 0, 0, 0, 0, 0, 0, 'This is REALLY suspicious, $N! Samuelson doesn\'t have a shred of info here about the Twilight Hammer - it\'s almost like he\'s not investigating them. Yet he\'s got a complete catalog of the missing explosives.$B$B<Anduin pulls a medallion from the files.>$B$BAnd I found this funny badge with a symbol on it: A crossed axe and hammer.$B$BIt all means something, but what?', 13623), -- He's Holding Out on Us
(27044, 16, 0, 0, 0, 0, 0, 0, 0, '<On seeing the Prince Regent, Farmer Wollerton collapses awkwardly down on one knee.>$B$BY- Y- Your highness!', 13623), -- Peasant Problems
(27038, 1, 5, 15, 0, 0, 0, 0, 0, '<Flintlocke greedily digs through the machine parts, tossing choice picks over his shoulder.>$B$BOh aye, \'ere\'s the stuff.$B$B<He sticks his head all the way into one of the crates.>$B$BBut where\'s me powder? Everything\'s here but for the powder. I need explosives, $gman:woman;!$B$BYou tell the King, no powder, no power. I need me some kersplosions or I ain\'t leavin\' port.', 13623), -- Missing Parts
(26997, 6, 5, 0, 0, 0, 0, 0, 0, 'This doesn\'t make any sense, $N.$B$BWhy was Samuelson sending us out here on a wild goose chase?$B$BSomething doesn\'t feel right. We should poke around on our own...', 13623), -- The Usual Suspects
(26975, 2, 1, 0, 0, 0, 0, 0, 0, '<Graves bows respectfully to the Prince.>$B$BPlease understand your highness, the men are working double-shifts. The scale of your father\'s operation is enormous.$B$BBut we will endeavor to wrap things up. I give you my word.', 13623), -- Rallying the Fleet
(26977, 1, 273, 0, 0, 0, 0, 0, 0, 'Hmmm, yes? My investigation of the Twilight\'s Hammer. Of course.$B$BYour assistance will be valuable. ', 13623), -- Twilight Investigation
(26960, 6, 1, 0, 0, 0, 0, 0, 0, 'Excellent, Anduin will learn a lot by shadowing you.$B$BRemember, stay within the city\'s borders. Keep him out of trouble. And above all else, guard him with your life.$B$B<King Wrynn turns his attention to his son.>$B$BAnduin, no adventures! Stay close to $N and return to the keep should you see any trouble.', 13623), -- My Son, the Prince
(27398, 0, 0, 0, 0, 0, 0, 0, 0, 'Your aid is most timely, $N.', 13623), -- The Battle Is Won, The War Goes On
(26190, 1, 1, 4, 0, 0, 0, 0, 0, 'Thank you, $N.  I will get to work scaling these for the King right away.  ', 13623), -- A Fisherman's Feast
(26442, 1, 1, 5, 0, 0, 0, 0, 0, 'Looks like the traps are working!  Thanks $N!', 13623), -- Rock Lobster
(28409, 6, 274, 0, 0, 0, 0, 0, 0, 'Ahh, Russell the Bard is always raving about Thundermar Lager. I guess it doesn\'t have the kick of a good Wildhammer brew, but he goes on and on about the \"body\" or \"flavor.\" I guess we\'ll find out, eh?', 13623), -- Something Brewed
(28411, 5, 1, 0, 0, 0, 0, 0, 0, 'Lookat that! You\'re practically bent double under the weight of all that meat. I\'d better get my people cooking.', 13623), -- Something Stewed
(28408, 1, 273, 0, 0, 0, 0, 0, 0, 'Ah, you work fast. Bold feathers for a bold woman. Well done!', 13623), -- Something Bold
(28172, 2, 0, 0, 0, 0, 0, 0, 0, 'I will see to it that these dragons are taken care of.', 13623), -- Done Nothing Wrong
(28174, 0, 0, 0, 0, 0, 0, 0, 0, 'So you\'re in, then?$b$bGood.', 13623), -- Burning Vengeance
(28666, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s time for the Blackrock orcs to feel the full wrath of the Alliance. They will pay for what they\'ve done.', 13623), -- Hero's Call: Burning Steppes!
(27830, 1, 0, 0, 0, 0, 0, 0, 0, 'Two more dangerous black dragons have been removed from this egg hunt.  Your greatest task, however, still awaits.', 13623), -- Their Hunt Continues
(27829, 4, 0, 0, 0, 0, 0, 0, 0, 'One less dragon to worry about, one step closer to redemption.  Onward, my soldiers!', 13623), -- The Wrath of a Dragonflight
(27834, 1, 1, 0, 0, 0, 0, 0, 0, 'I think you\'re ready, $N.  You\'re getting the hang of this.', 13623), -- Baelog, the Glass Cannon
(27828, 1, 2, 0, 0, 0, 0, 0, 0, 'I\'m not what you\'d call \"very strong\" or \"battle-hardened\", but I get the job done my own way.$b$bLookin\' forward to fightin\' with you.  I never fought with a fancy-lookin\' $c before.', 13623), -- Eric, the Utility Dwarf
(27835, 1, 0, 0, 0, 0, 0, 0, 0, 'See?  No need to worry when Olaf is around.  Just let me know, and I\'ll protect you from the monsters.', 13623), -- Olaf, the Big Fella'
(27827, 1, 22, 0, 0, 0, 0, 0, 0, 'You\'re the $r we\'ve been waiting for?  It\'s about time you got here.  My legs could use a stretch.$b$bCome on boys!  Let\'s go kill us some black dragons!', 13623), -- The Swift, the Fierce, and the Stout
(27826, 0, 0, 0, 0, 0, 0, 0, 0, 'I\'ll take that egg out of your hands now.  We need to get this egg incubated... and hidden, quickly.  There are lots of angry dragons looking for this.$b$bIt\'s good to see you again, by the way.', 13623), -- Into the Dragon's Mouth
(27794, 6, 1, 0, 0, 0, 0, 0, 0, 'Just one tiny little device?$b$bI never did understand those titans.$b$bVery well!  Let\'s see what this peeper can do.', 13623), -- Return to Blam
(27912, 0, 0, 0, 0, 0, 0, 0, 0, 'You peer into the chest...', 13623), -- The Titans' Trove
(27763, 2, 0, 0, 0, 0, 0, 0, 0, 'Welcome to Fuselight!', 13623), -- To Fuselight Proper
(27762, 2, 0, 0, 0, 0, 0, 0, 0, 'Nice landing!', 13623), -- Fuselight, Ho!
(28579, 1, 0, 0, 0, 0, 0, 0, 0, 'You must be here to help Fuselight! Let\'s get you to the Badlands right away.', 13623), -- Hero's Call: Badlands!
(27455, 4, 1, 0, 0, 0, 0, 0, 0, 'I can\'t believe it.  We\'re literally FEET away from becoming sworn members of the Argent Crusade.$b$bWe\'d be in there already if it weren\'t for Tarenar\'s dallying.  If he doesn\'t quit chatting with the locals soon, I\'m going to head in there myself.', 13623), -- Boys Will Be Boys
(27555, 0, 0, 0, 0, 0, 0, 0, 0, 'Fiona has left some of her charms inside the caravan.$b$bAs a trader, she seems to be pretty good with money.  Maybe carrying one of her charms will help out with your finances.', 13623), -- Fiona's Lucky Charm
(27450, 1, 1, 0, 0, 0, 0, 0, 0, 'Hmm... they didn\'t survive the trip out of the water as well as I had hoped.$b$bOh well!  Seafood salad for Frederick tonight!', 13623), -- Frederick's Fish Fancy
(27454, 4, 0, 0, 0, 0, 0, 0, 0, 'It should take them weeks to get their operation running again.  Thank you, $N.', 13623), -- Just a Drop in the Bucket
(27453, 1, 1, 0, 0, 0, 0, 0, 0, 'Uh oh... it looks like we may have gathered a little too much coagulated rot.  Oh well, we\'ll just have to improvise, then!$b$bWhat could possibly go wrong?', 13623), -- Catalysm
(27452, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'ve got both pieces!  Good.  These will help when trying to sneak into their death camp.', 13623), -- Dark Garb
(27451, 274, 1, 1, 0, 0, 0, 0, 0, 'Hello!  It\'s me.  Hope you don\'t mind a little home-brewed magic to allow me to communicate with you in the field.  It\'ll save us both some time.$b$bWe\'re going to incorporate that living rot into a mixture that\'ll ruin their next batch of plague.  That\'ll show them!', 13623), -- To Kill With Purpose
(27449, 2, 0, 0, 0, 0, 0, 0, 0, 'Yes, you are indeed strong... and I submit to you.$b$bI will join you and your friend, the worgen.  My strength is yours.', 13623), -- Honor and Strength
(27448, 2, 0, 0, 0, 0, 0, 0, 0, 'We\'ve enjoyed having you ride with us, $N.  Hopefully, once Gidwin and Tarenar join the Argent Crusade, we can continue to travel together.', 13623), -- The Trek Continues
(27382, 2, 1, 0, 0, 0, 0, 0, 0, 'Of course a young $r like you would have no trouble taking care of a few wild animals.  With the roads clear, my journey to the next tower will be much easier.', 13623), -- Rough Roads
(27432, 4, 0, 0, 0, 0, 0, 0, 0, 'Great, you got him!  And I hope you taught his gang a lesson too!', 13623), -- Zaeldarr the Outcast
(27383, 1, 0, 0, 0, 0, 0, 0, 0, 'Hello.  I\'m Pamela, what\'s your name?', 13623), -- Little Pamela
(27381, 6, 1, 0, 0, 0, 0, 0, 0, 'Argus Highbeacon... that old guy on the top of the tower?  Great!$b$bA man his age must have been in the Argent Crusade for a long time.  Maybe he can put in the good word for us at Light\'s Hope.', 13623), -- Traveling Companions
(27373, 1, 0, 0, 0, 0, 0, 0, 0, 'Hope the ride wasn\'t too bumpy for you.$b$bHave a look around the tower while the horses rest.  It\'s no Light\'s Hope Chapel, but I\'m sure you can find some way to keep yourself busy.', 13623), -- Onward, to Light's Hope Chapel
(27372, 1, 0, 0, 0, 0, 0, 0, 0, 'Why, this is exactly what I needed!  Fine, I\'ll forgive Tarenar for running off.$b$b$N, you\'re welcome to join us anytime.', 13623), -- A Gift For Fiona
(27371, 0, 0, 0, 0, 0, 0, 0, 0, 'Five should be good enough.$b$bYikes, look at the time!  I need to head back to camp.', 13623), -- What I Do Best
(27370, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ve found them, $r.  The Scourge.  How I\'ve longed for this day.', 13623), -- Tarenar Sunstrike
(27369, 0, 0, 0, 0, 0, 0, 0, 0, 'I\'ll tear that pint-size paladin to shreds before he... wait a minute are those Banshee\'s Bells?  You brought these for me?$b$bOh, Gidwin asked you to get them for me!  That sweet little guy.  Alright.  He\'s off the hook for now.', 13623), -- Greasing the Wheel
(27368, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'re back?!  Thank the Light!$b$bBefore you throw that acid on me, I need to ask: Are you the $g guy: girl; who was here before, or are you one of those eight-legged cowards?  I need to know whether or not I should smack you on my way out.', 13623), -- Just Encased
(27367, 0, 0, 0, 0, 0, 0, 0, 0, '$g Tarenar?: Fiona?;  Is that you?$b$bWhoever you are, would you mind helping me out of this thing?', 13623), -- Gidwin Goldbraids
(27683, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes?', 13623), -- Into the Woods
(27166, 0, 0, 0, 0, 0, 0, 0, 0, 'I will have my fletchers get to work on these.$b$bI\'m glad to see you being so useful right away, $N.  Perhaps later I will have some more exciting tasks for you.', 13623), -- Go Fletch!
(27158, 396, 0, 0, 0, 0, 0, 0, 0, 'It\'s about time you arrived, $c.', 13623), -- The Battle for Andorhal
(26327, 0, 0, 0, 0, 0, 0, 0, 0, 'Well met! If you\'ve got a weapon on you, I\'ll take any help I can get clearing out these crazed fools!', 13623), -- Anvilmar the Hero
(27833, 21, 21, 21, 0, 0, 0, 0, 0, 'Thank you, $r.  However, I\'m afraid I don\'t have much to give you, other than this passionate round of applause.$b$b<Terrance looks down into his bags.>$b$bOh, I do have these.  Here, take your pick.', 13623), -- Half-Ton Holdouts
(27825, 1, 0, 0, 0, 0, 0, 0, 0, 'I imagine those ogres weren\'t too much trouble for you.  Here - some coin for your troubles.', 13623), -- Survival of the Fattest
(27824, 0, 0, 0, 0, 0, 0, 0, 0, 'Now here\'s some treasure!  I was beginning to worry that these weren\'t titan ruins at all!$b$bI\'ll show these to Durdin.  Thanks again, $N.', 13623), -- The Good Stuff
(27823, 1, 5, 0, 0, 0, 0, 0, 0, '<Sigrun instantly downs a dusty mug of shadowstout.>$b$bWow, this stuff is strong!  I knew they had beer, but I never expected them to have shadowstout!  That\'s my favorite shadowbeer!', 13623), -- A Dwarf's Got Needs
(27051, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $r. We will weed the rest out of their possession in time.', 13623), -- Through Persistence
(27050, 1, 0, 0, 0, 0, 0, 0, 0, 'You are proficient at stepping on things. You would make an excellent giant.', 13623), -- Fungal Fury
(27049, 1, 0, 0, 0, 0, 0, 0, 0, 'Once the growth starts, it is near impossible to stomp back into submission. Through persistence our realm will one day be cleansed.', 13623), -- Soft Rock
(27047, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $r. These will do well.', 13623), -- Motes
(27046, 1, 0, 0, 0, 0, 0, 0, 0, 'You wage a war that we cannot. Thank you for your help.', 13623), -- Fear of Boring
(27048, 5, 0, 0, 0, 0, 0, 0, 0, 'Well played!$B$BI\'ve got this pretty sweet deal going. A bunch of shmucks go up there to Therazane\'s Throne and give all kinds of gold to D\'lom for who-knows-what kinda crap. He forks all that cash over to me for these crystals. I go home freakin\' rich for a couple chunks of rock.$B$BDon\'t tell no one though. I don\'t want no competition springin\' up.$B$BThink you can come back later to help me get another load of crystals out?', 13623), -- Underground Economy
(26761, 1, 1, 5, 0, 0, 0, 0, 0, 'I heard about the Defias making a return. Terrible news. I wish I had better news, but it would appear that Lakeshire is under attack! We are losing citizens left and right. Our own guards are spread far too thin to handle the situation. We need a hero to step up!', 13623), -- Threat to the Kingdom
(26370, 1, 1, 0, 0, 0, 0, 0, 0, 'Five years of work burned to the ground in five minutes. Damn the Defias!$B$BAnd this is only the beginning, $N! We have a long, hard road ahead of us.', 13623), -- Return to Sentinel Hill
(26322, 5, 1, 0, 0, 0, 0, 0, 0, 'I will deploy a battalion of soldiers to Westfall at once! With the Defias Brotherhood reborn, an old threat to the kingdom is renewed.', 13623), -- Rise of the Brotherhood
(25540, 1, 0, 0, 0, 0, 0, 0, 0, 'This is wonderful. I will begin cooking them immediately. It is good to know that of our many fears, starvation shall no longer need to be one of them.$B$BI imagine the Admiral will have much work for you. Let me trouble you no further for a while.', 13623), -- Bellies Await
(25538, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done my odorific associate. You are both swift and assiduous, if I do say so myself. May your future travels be rampant with inspiration and opulence.', 13623), -- Odor Coater
(25537, 1, 0, 0, 0, 0, 0, 0, 0, 'Superb! Chemicals abound!$B$BMy instantaneous chemical synthesizer is already pre-tested and prepared. Your deployment compound shall be ready in the blink of an eye!', 13623), -- Art of Attraction
(25536, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for stepping up to take care of this, $c. I know there are a lot of concerns swarming us right now, but maintaining the safety of the survivors is paramount.', 13623), -- Cold Welcome
(25539, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, indeed. This is an entirely unshameful amount of clams to have gathered. The survivors back at the cave will surely be grateful.', 13623), -- Clamming Up
(25535, 1, 0, 0, 0, 0, 0, 0, 0, 'More help! Superb! We can certainly use it, I\'ll tell you that much.', 13623), -- A Powerful Need To Eat
(25922, 66, 1, 0, 0, 0, 0, 0, 0, 'It appears that I owe you my life, yet again.  Thank the Light that you found me before you and your shaman activated those bio-defenses.', 13623), -- Waking the Beast
(25921, 1, 1, 0, 0, 0, 1000, 0, 0, 'No need to bring me up to speed... Nespirah has been narrating your adventures as they happened, and Captain Taylor filled me in on the rest.$b$b<Duarn closes his eyes and nods.>$b$bNespirah says that she is quite grateful, and that she has a small surprise ready for the naga.', 13623), -- Overseer Idra'kess
(25920, 4, 0, 0, 0, 0, 0, 0, 0, 'Brilliant work!$b$b<Valoren tucks the pearls away beneath her armor.>$b$bNow I just need you and Captain Taylor to get me safely out of here.  I can handle the studies from there on.', 13623), -- Still Valuable
(25918, 1, 0, 0, 0, 2, 0, 0, 0, '<Admiral Dvorek admires the polearms you present him.>$b$bOh, I\'m sorry.  I was just imagining what these will look like with little bits of naga stuck to the ends of them.  Thank you, $N.  We\'ll put these to good use.', 13623), -- Hopelessly Gearless
(25919, 0, 0, 0, 0, 0, 0, 0, 0, 'Hopefully we made some progress.  I\'m not sure how we\'ll know when the creature wakes up, but something tells me that it will be pretty obvious when it does.', 13623), -- Body Blows
(25917, 5, 0, 0, 0, 0, 0, 0, 0, '$N... is that you?', 13623), -- We Are Not Alone
(25916, 0, 0, 0, 0, 0, 0, 0, 0, 'I had assumed that the naga were only here for those pearls.  No, this makes much more sense.  If they had Nespirah\'s power under their control, the amount of damage the naga could do would be catastrophic!$b$bSomething must be done.', 13623), -- Breaking Through
(25909, 1, 0, 0, 0, 0, 0, 0, 0, '<Duarn looks at the crab and disguises a frown.>$b$bIt doesn\'t look very impressive, does it?', 13623), -- Capture the Crab
(25885, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes, yes. This is the stuff.$b$bMaybe I can gradually eat less of it and avoid that side-effect.$b$bThank you, $n.', 13623), -- What? What? In My Gut...?
(25888, 396, 0, 0, 0, 0, 0, 0, 0, 'Let us hope for the safety of those released prisoners.$b$bIn return for your noble efforts, please accept this gift.', 13623), -- Decompression
(25824, 0, 0, 0, 0, 0, 0, 0, 0, 'Well, it\'s not encouraging, but it\'s something...', 13623), -- Debriefing
(25812, 0, 0, 0, 0, 0, 0, 0, 0, 'A... a $r? Here?$b$bI must be mad...', 13623), -- Spelunking
(25467, 0, 0, 0, 0, 0, 0, 0, 0, 'The satisfying sound of a chest unlocking is followed by the sight of once-hidden treasure.', 13623), -- Kliklak's Craw
(25377, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve discovered lost treasure!$b$bYour mind reels at the thought of what else might be hidden in the depths of the sea.', 13623), -- The Horde's Hoard
(25558, 396, 0, 0, 0, 0, 0, 0, 0, 'The Earthen Ring has received my distress message and sent help - just in time it would seem.$b$bHopefully more can be sent soon. We are but few against a great many.', 13623), -- All or Nothing
(25547, 396, 0, 0, 0, 0, 0, 0, 0, 'No time to address the troops now.$b$bJust as well. They know what must be done.', 13623), -- On Our Own Terms
(25545, 0, 0, 0, 0, 0, 0, 0, 0, 'Well done, $c!$b$bThanks to you, my men will be ready to confront the enemy when they attack.', 13623), -- To Arms!
(25564, 0, 0, 0, 0, 0, 0, 0, 0, 'Everything here seems to be in working order.', 13623), -- Stormwind Elite Aquatic and Land Forces
(25546, 0, 0, 0, 0, 0, 0, 0, 0, 'This should help relieve our exhaustion.$b$bAgain, we thank you.', 13623), -- Traveling on Our Stomachs
(25357, 0, 0, 0, 0, 0, 0, 0, 0, 'Let\'s hope your efforts prove to be enough of a diversion...', 13623), -- Buy Us Some Time
(28292, 6, 0, 0, 0, 0, 0, 0, 0, 'Uldum? What about it?', 13623), -- That's No Pyramid!
(27787, 4, 0, 0, 0, 0, 0, 0, 0, 'You did it, $g lad : lass;! You beat that damned gronn and sent Cho\'gall packing into the Twilight Bastion.$B$BDon\'t you worry. With your help and that of your friends, we\'ll get in there and we\'ll kill Cho\'gall once and for all!', 13623), -- Skullcrusher the Mountain
(27784, 0, 0, 0, 0, 0, 0, 0, 0, 'The Hammer of Twilight floats in the middle of the altar, unprotected....', 13623), -- The Hammer of Twilight
(27782, 1, 0, 0, 0, 0, 0, 0, 0, 'Good, you\'re back. We know where Cho\'gall\'s ultimate weapon is located!', 13623), -- Mathias Needs You
(27745, 4, 6, 0, 0, 0, 0, 0, 0, 'We survived and all of the portals are now shutdown!$B$BYou don\'t think Magmatooth is going to hold a grudge, do you?', 13623), -- A Fiery Reunion
(27744, 4, 6, 0, 0, 0, 1000, 0, 0, 'That\'ll teach \'em to move in on our territory!$B$BWhat\'s that over across the way?', 13623), -- Rune Ruination
(27742, 1, 0, 0, 0, 0, 0, 0, 0, '<Goldmine slyly looks at the pile of Elementium shards.>$B$BHmm, I don\'t think that stuff\'s going to sell for much. I better give you your cut right now so you don\'t feel ripped off.', 13623), -- A Little on the Side
(27743, 14, 0, 0, 0, 0, 0, 0, 0, 'They had it coming to them.', 13623), -- While We're Here
(27720, 5, 18, 0, 0, 0, 0, 0, 0, 'Oh no! My weapons and totems!$B$BThey\'re destroyed!!!', 13623), -- Mr. Goldmine's Wild Ride
(27711, 4, 0, 0, 0, 0, 0, 0, 0, '$N, glad you\'re back! Have I got something fun for us to do!', 13623), -- Back to the Elementium Depths
(27702, 273, 0, 0, 0, 0, 0, 0, 0, 'Our efforts to improve relations with the red dragons has really paid off, $N.', 13623), -- Coup de Grace
(27700, 6, 0, 0, 0, 0, 0, 0, 0, 'Isn\'t she a beauty?$B$BLet\'s see what she does now that she\'s free.', 13623), -- Dragon, Unchained
(27688, 1, 0, 0, 0, 0, 0, 0, 0, 'That takes care of most of their leaders outside of the Bastion of Twilight.$B$BWe work well together, $N.', 13623), -- Distract Them for Me
(27659, 1, 0, 0, 0, 0, 0, 0, 0, 'The last portal is deep within the mine here, but we\'ll deal with that in a bit.', 13623), -- Portal Overload
(27719, 6, 0, 0, 0, 0, 0, 0, 0, 'The Hammer of Twilight? And you say you got this information out of a drowned Wildhammer dwarf?$B$BYou\'re kidding, right?', 13623), -- Water of Life
(27661, 33, 0, 0, 0, 0, 0, 0, 0, 'I am pleased. Lord Cannon was always an unworthy adversary.$B$BVery well, $r, I will help you gain the information which you seek.', 13623), -- Fire the Cannon
(27695, 273, 274, 0, 0, 0, 0, 0, 0, 'That thing looks sharp. Sharp enough to the do deed, at least.$B$BBut if I\'m a judge of weaponry, that\'s not what Cho\'gall\'s after.', 13623), -- The Elementium Axe
(27654, 274, 0, 0, 0, 0, 0, 0, 0, 'None of us are too good to get our hands a little dirty. Or bloody, in this case.', 13623), -- Bring the Hammer Down
(27652, 6, 0, 0, 0, 0, 0, 0, 0, 'I\'m not sure what I\'m going to do with all of these. I\'ll probably fence them and donate the proceeds to the Stormwind orphanage.$B$BNow to find someone sick enough to buy such a thing. It\'ll probably be a goblin. Or, a gnome warlock.', 13623), -- Dark Assassins
(27657, 1, 0, 0, 0, 0, 0, 0, 0, '$N! I\'m glad you\'re here.$B$BOf course, I\'m more than happy to lend you whatever assistance that I can.', 13623), -- Help from the Earthcaller
(27636, 6, 0, 0, 0, 0, 0, 0, 0, 'Where are the rest of my people?', 13623), -- Just You and Mathias
(27502, 0, 0, 0, 0, 0, 0, 0, 0, 'Oh no!', 13623); -- Up to the Citadel

INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27500, 1, 273, 0, 0, 1000, 0, 0, 0, '<The paladin frowns.>$B$BThat\'s quite a gruesome trophy collection you have there. I would have believed you if you had simply said they were dead. Regardless, thank you for having the foresight to take care of them.$B$BThe Twilight Gate will soon be ours. Time to move up to the Twilight Citadel.', 13623), -- Four Heads are Better than None
(27498, 0, 0, 0, 0, 0, 0, 0, 0, 'The horns have been sounded. Victor\'s Point should launch their attack at any moment.$B$BNow there\'s only one thing left to take care of.', 13623), -- Signal the Attack
(27494, 0, 0, 0, 0, 0, 0, 0, 0, 'Success!', 13623), -- Move the Mountain
(27490, 1, 274, 0, 0, 0, 0, 0, 0, 'That must have been deadly.$B$BWhile I don\'t approve of their methods, no one can question the effectiveness of Master Mathias Shaw and his SI:7. Not to mention that you\'re here. Our victory is all but assured.', 13623), -- SI:7 Drop
(27496, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks to you, our cannoneers hit their marks. Tell me about the situation within the Twilight Gate.', 13623), -- Call in the Artillery
(27492, 273, 0, 0, 0, 0, 0, 0, 0, 'That\'s the spirit, $g lad : lass;! Today\'s already shaping up to be a good one.', 13623), -- Ogres & Ettins
(28248, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'ve done well, $n. We\'re in the process of preparing the attack now.', 13623), -- Victors' Point
(28109, 1, 0, 0, 0, 0, 0, 0, 0, 'The gate is clear. Once your people finish clearing the canyon, we will speak to your leaders about the next move.', 13623), -- Pressing Forward
(28108, 1, 0, 0, 0, 0, 0, 0, 0, 'Like a well-oiled machine.', 13623), -- If The Key Fits
(28107, 1, 0, 0, 0, 0, 0, 0, 0, 'We make it look easy.', 13623), -- Paving the Way
(28104, 1, 0, 0, 0, 0, 0, 0, 0, 'Good going.$B$BDoesn\'t look like much, does it?', 13623), -- Precious Goods
(28103, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent. Now we can start pushing our ground forces up towards Grim Batol.', 13623), -- Easy Pickings
(28101, 1, 0, 0, 0, 0, 0, 0, 0, 'The red dragons have agreed to help! No small feat, I\'m sure. You have the thanks of the Alliance.$B$BWe\'d already laid out plans for our ambush on a Twilight caravan by the time the dragons contacted us. They\'re helping by cutting off their retreat.$B$BThe battle still rages. You can definitely be of aid.', 13623), -- Mathias' Command
(27485, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'m glad Lira didn\'t scare you off. I won\'t say her concerns aren\'t warranted, but we have a common enemy. She is perhaps a bit overzealous.', 13623), -- Warm Welcome
(27374, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome, $Gbrotha:sista;. You\'ve chosen a harsh time to be joinin\' us, but that is to our fortune. We could use ya help.', 13623), -- The Maw of Madness
(28655, 4, 1, 5, 0, 0, 0, 0, 0, 'We did it, $N! Fighting that ... thing side-by-side really brought all the Wildhammers together. The heads of the families are more united than I\'ve ever seen them. Drink up, $N, and celebrate!!$B$BOf course, our work is only beginning. I\'ll rally our new Wildhammer reinforcements with the rest of the Alliance and prepare to storm the Twilight Bastion.$B$BI\'m sure we\'ll meet again soon. ', 13623), -- Wild, Wild, Wildhammer Wedding
(28410, 273, 1, 0, 0, 0, 0, 0, 0, 'Oh, aye! Kilts for the gents, gowns for the bridesmaids.$B$BJust don\'t tell the ladies they\'re wearing clothes fit for a blimp.', 13623), -- Something Stolen
(28413, 6, 11, 0, 0, 0, 0, 0, 0, 'Well, it\'s catchy, that\'s for sure.$B$BBut is it a classic?', 13623), -- Words and Music By...
(28407, 15, 1, 274, 0, 0, 0, 0, 0, '<Fanny throws her arms up, exasperated.>$B$BYou, Kurdran, Firebeard, and now my brother - everyone\'s got wedding fever!$B$BFine, fine, I\'ll marry Keegan Firebeard. But only \'cuz he\'s strong and handsome, with a jaw that can cut gravel and an arse like an anvil. Not for any political reasons.$B$BWe\'re going to need your help, though. We got a whole lotta wedding to put together, and not a lot of time to do it.', 13623), -- The Bachelorette
(27651, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks for your help. You\'ve got a warrior\'s spirit in ya - you coulda fooled me for a Wildhammer if it weren\'t for your... well.. you know.$B$BI know Firebeard sent you to unite us. My love for that dwarf runs shallow, but you know now we\'ve got plenty of reasons to make enemies of Twilight. If you see him, tell him that when the battle starts, the Dunwald family will be there.', 13623), -- Doing It Like a Dunwald
(27649, 5, 0, 0, 0, 0, 0, 0, 0, 'Woooooh! That\'s exactly what my belly needs!$B$BYou get me all the nice things.', 13623), -- A Steady Supply
(27650, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you for bandin\' my brothers back together. I know they\'re tough, but they\'re even tougher when they\'re side by side, and there\'s a lot of Twilight out there.$B$BYou\'re good to put a gal\'s heart at ease.', 13623), -- Home Again
(27648, 1, 0, 0, 0, 0, 0, 0, 0, 'A thing of beauty, isn\'t it? An\' they keep comin\' back for more. Love it!$B$BI\'ll go find Keely and settle her nerves in a bit. Just one more go through the row.', 13623), -- Once More Into The Fire
(27641, 5, 0, 0, 0, 0, 0, 0, 0, 'Now that\'s what I\'m talkin\' about $glad:lass;. My kinda $r.', 13623), -- While Meeting The Family
(27647, 1, 0, 0, 0, 0, 0, 0, 0, 'Donnelly\'s belly! That\'s more like it. Good to not be dyin\' of the thirst again.$B$BHere, have some. Good ol\' Eoin\'s never so impolite as ta not share!', 13623), -- Anything But Water
(27642, 1, 0, 0, 0, 0, 0, 0, 0, 'That many dead, eh? Not seemin\' likely that anyone outside of me brothers fought through it then. I guess I already expected as much.$B$BThanks for takin\' the time to look for me.', 13623), -- Sifting Through The Wreckage
(27646, 5, 0, 0, 0, 0, 0, 0, 0, 'You found\'m! You found Beak! I like you, new friend!$B$BI\'m gonna go show Keely. Keely like Beak too.', 13623), -- Finding Beak
(28378, 4, 1, 5, 0, 0, 0, 0, 0, 'Fanny is safe! I hear Firebeard was in there with you? Nice to hear he\'s finally pulling his weight.$B$BWait, why are you looking at me like that, $n? Do you know something I don\'t? ', 13623), -- Find Fanny
(28379, 4, 1, 0, 0, 0, 0, 0, 0, 'Har! My men could learn a lot by watching you work. Well done.', 13623), -- Ogre Bashin'
(28377, 6, 5, 0, 0, 0, 0, 0, 0, 'Good to have you fighting at my side again, $N!$B$BAnd I see the Firebeards have come as well. I suppose they\'ll provide a distraction while me and my boys do the heavy lifting.', 13623), -- Rescue at Glopgut's Hollow
(28346, 6, 1, 274, 0, 0, 0, 0, 0, 'What? Kurdran\'s talkin\' marriage!? Didn\'t he just see me an\' ol\' Thunderface tearing each other new ones?$B$BThe only eligible Thundermar is Fanny. Now, I\'ll give you this, she\'s got the looks allright. All lumpy in the right places, if you hear me. But she\'s not got that somethun\' somethun\' a Firebeard looks for in a woman, right?', 13623), -- The Bachelor
(28294, 3, 273, 1, 0, 0, 0, 0, 0, 'Hello, $c! Keegan Firebeard here has told me all about your heroics down south. Thank you for all of your efforts on behalf of the Wildhammer.$B$BI see Colin Thundermar is right behind you. The summit is ready to begin! Please stay and let\'s see how things unfold...', 13623), -- The Kirthaven Summit
(28282, 4, 5, 0, 0, 0, 0, 0, 0, 'We did it, $N! Narkrall Rakeclaw lies dead at my feet, and Thundermar has weathered a storm of drakes!$B$BThis wouldn\'t have been possible if it weren\'t for the help of the Alliance. I owe you a debt that I don\'t think can ever be repaid.', 13623), -- Narkrall, The Drake-Tamer
(28281, 4, 1, 0, 0, 0, 0, 0, 0, 'You sure know your way around a battlefield, $c. It looks like they\'re about to fall back.$B$BAll we need is one decisive blow...', 13623), -- Last Stand at Thundermar
(28280, 4, 1, 0, 0, 0, 0, 0, 0, 'You did it, $N! Alliance ingenuity to the rescue.$B$BOf course, I don\'t have anything to help you fight the dismounted riders now that they\'re on the ground. You\'re a $c; improvise!', 13623), -- Tear Them From the Sky!
(28212, 66, 1, 0, 0, 0, 0, 0, 0, 'Marvelous! I\'ll smelt this down into a delicious soup. An angry soup. Of molten metal.', 13623), -- Hot Stuff
(28211, 6, 5, 0, 0, 0, 0, 0, 0, 'Look at that - OW! Pointy! Hot!$B$BThese spears should cut through that dragonhide like an electric cheese-slicing apparatus through butter.', 13623), -- Tempered in Elemental Flame
(28216, 274, 1, 0, 0, 0, 0, 0, 0, 'Aye, that\'s him. Can you believe this thing was human once?$B$BThat\'s the Twilight\'s Hammer for you. What they don\'t destroy, they corrupt.$B$BThank you, $c.', 13623), -- Magmalord Falthazar
(28244, 6, 5, 0, 0, 0, 0, 0, 0, 'What did you see, $N? Cho\'gall? Wait - he saw YOU!?$B$BOh aye, that wee sneaky eye! It looks both ways. That cheeky looker! Where\'s me hammer!?', 13623), -- Eye Spy
(28243, 6, 274, 0, 0, 0, 0, 0, 0, 'You found one? A gen-u-ine Eye of Twilight? Lemme see.$B$BOh Gods. It\'s lookin\' at me. It\'s lookin\' right back!$B$BI need a drink. Can you face that thing toward the wall or somethin\'?', 13623), -- The Eyes Have It
(28215, 4, 5, 1, 0, 0, 0, 0, 0, 'Terrific! These coils will decompress with the force of a thousand suns!$B$BThat\'s just a rough approximation of course, don\'t hold me accountable for those numbers.', 13623), -- Potential Energy
(28242, 0, 0, 0, 0, 0, 0, 0, 0, '<The Eye glimmers darkly, colors swirling about its dusky surface.>$B$BAh, the succulent thrill of life extinguished. Do you feel it, $c? Do you relish it as I do?$B$BNo, I see not. You fight to protect the lives of others. Pity.', 13623), -- We All Must Sacrifice
(28241, 0, 0, 0, 0, 0, 0, 0, 0, '<The Eye sits before you, humming ominously with dark energies.>$B$B<Without warning, the orb rotates, as if to look at you. You sense a malevolent presence, as though the orb is alive.>', 13623), -- A Vision of Twilight
(27752, 273, 4, 0, 0, 0, 0, 0, 0, 'Oh aye ... we get a few of these kegs out to the boys on the front and we\'re gonna see some fireworks. Thank you, $N!', 13623), -- Fight Like a Wildhammer
(27754, 1, 11, 0, 0, 0, 0, 0, 0, 'Look at that! That\'s quite a collection of trophies you have there.$B$BI\'ll spread the word. If a single Alliance $c can do this, imagine what the rest of your lot can accomplish!', 13623), -- Dragonmaw Takedown
(27753, 273, 1, 0, 0, 0, 0, 0, 0, 'It\'s good - hardly a worm or weevil to be found!$B$BThis is a lifesaver to the folk who fled here for survival.', 13623), -- Never Leave a Dinner Behind
(28369, 0, 0, 0, 0, 0, 0, 0, 0, 'Me brother sent you? Good! I could use a $c. Can ya hold yer own in a fight?', 13623), -- My Sister, Fanny
(28001, 5, 15, 0, 0, 0, 0, 0, 0, 'Here here, WOT!? He calls ME a COWARD!?$B$BJust like a Firebeard, all hot air and not a lick of sense. I\'ve been bearing the brunt of a Dragonmaw invasion from the south, much of Thundermar is in ruins, and do any of the other clans stick up to help? NO! Ol\' Thundermar is on his own he is, and you\'d better believe I\'m usin\' everything in my arsenal just to stem the tide.', 13623), -- A Coward's Due
(27643, 1, 0, 0, 0, 0, 0, 0, 0, 'Hi friend! I don\'t think I know you... I\'m Donnelly Dunwald.$B$BWhat\'s your name? I don\'t think I know you... Do I know you?', 13623), -- Donnelly Dunwald
(27645, 1, 0, 0, 0, 0, 0, 0, 0, 'Well look at ya, all geared and fancy. Keely send you to keep an eye on old Cayden, eh? Won\'t be needin\' it. I got these louts handled.$B$BHahah! They chose the wrong dwarf to be ambushin\' today! Ahahahahah!', 13623), -- Cayden Dunwald
(27644, 1, 0, 0, 0, 0, 0, 0, 0, 'Of all the buildings in all the towns to collapse, why\'d it have to be this one?!', 13623), -- Eoin Dunwald
(27640, 1, 0, 0, 0, 0, 0, 0, 0, 'If it\'s Dunwalds you be lookin\' for, it\'s Dunwalds you\'ve found. A couple of\'m anyway. I can\'t find me other brothers for the life of me.', 13623), -- Dunwalds Don't Die
(27817, 1, 0, 0, 0, 0, 0, 0, 0, 'Now that\'s how it\'s done, $g lad:lass;!$B$BWith a real gryphon wing back together, we can take the fight to the rest of the Twilight. You\'re welcome to fly with us anytime.', 13623), -- Dropping the Hammer
(27816, 1, 0, 0, 0, 0, 0, 0, 0, 'It seems you had some luck bringin\' riders back. Well timed too - we just pushed the elementals back, so we should have the arm room to lead an attack right away.$B$BThank you, $n. You\'re a good $r.', 13623), -- Personal Request
(27812, 1, 0, 0, 0, 0, 0, 0, 0, 'Ya got the Mullans. Good news! They\'re worth more than their weight in a fight, and they ain\'t exactly skinny.', 13623), -- The Loyalty of Clan Mullan
(27811, 1, 0, 0, 0, 0, 0, 0, 0, 'Good on you. I always feel like a part of me is missing when my gryphon isn\'t nearby. I can\'t speak for Duglas or the rest of the clan, but I\'ll be ready to ride at Firebeard\'s call.', 13623), -- The Scent of Battle
(27810, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s the stuff! Not half bad. You\'ve got a bit of fight in ya after all.', 13623), -- The Fighting Spirit
(27815, 5, 0, 0, 0, 0, 0, 0, 0, 'Hah! Looks like their raid went mighty well then. I\'ll have to buy ol\' Forgehammer a round once we finish with this mess.', 13623), -- Somethin' for the Boys
(28234, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you!  Now turn around so I can put\'em on.', 13623), -- They Took Me Pants!
(28233, 6, 396, 0, 0, 0, 60, 0, 0, 'Don\'t be looking!  I\'m not wearin\' me pants!', 13623), -- The Lost Brother
(27814, 0, 0, 0, 0, 0, 0, 0, 0, 'Yer a good $glad:lass;.  Have me thanks and a little gold for yer troubles.', 13623), -- Anything We Can Get
(27813, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s more like it. Let\'s finish gatherin\' up supplies and get back to Keegan.', 13623), -- Death Worthy of a Dragonmaw
(27809, 1, 0, 0, 0, 0, 0, 0, 0, 'Bout that time, eh? Help us wrap things up then.', 13623), -- Firebeard Bellows
(27807, 6, 0, 0, 0, 0, 0, 0, 0, 'Iain sent ya?$B$BYou don\'t look like a Firebeard to me. Why exactly should I be listenin\' to anything you say?', 13623), -- Clan Mullan
(27999, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s a right shame. Stubborn as they were to speak to, they were just as stubborn in a fight. Would have been good to have \'em.$B$BOnce this is done, we\'ll have to send some boys out to bring them back for a proper send off.', 13623), -- The Fate of the Doyles
(27808, 0, 0, 0, 0, 0, 0, 0, 0, 'It seems the Doyles suffered the worst of the attacking Twilight drakes.$B$BIt\'s clear that they fought to the end: not a single rider\'s footprint more than a few yards from his gryphon. It\'s doubtful there were any survivors.', 13623), -- Stubborn as a Doyle
(27805, 275, 0, 0, 0, 0, 0, 0, 0, 'You are very generous. Thank you.$B$BThere\'s a lot of darkness in our world these days. We appreciate the light that you\'ve brought here.', 13623), -- Small Comforts
(27806, 1, 0, 0, 0, 0, 0, 0, 0, 'Greetings, $r. Sent by Keegan?', 13623), -- Honorable Bearing
(27803, 396, 0, 0, 0, 0, 0, 0, 0, 'Good work, $gboy:girl;. Good to have another capable set of hands about.', 13623), -- Welcome Relief
(27804, 396, 0, 0, 0, 0, 0, 0, 0, 'Thanks for your help. Every little bit makes a difference.$B$BWe\'ll keep the water going until we can push the Twilight back.', 13623); -- The Only Homes We Have

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `RewardText`='Our Expedition made it safely through the Portal and set up a new base called Thrallmar. Yet as you can see, the Burning Legion moved in and cut us off from our brothers. Clearly, the demons hope to retake the Dark Portal and prevent us from gathering reinforcements from Azeroth.\n', `VerifiedBuild`=13623 WHERE `ID`=9407; -- Through the Dark Portal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `RewardText`='This is far worse than what was noted in Luther\'s journal. They\'ve got this place covered in Scourge and are infecting everything they touch.$B$B<Ickoris nods.>$B$BIt gets worse - if you can imagine such a thing...', `VerifiedBuild`=13623 WHERE `ID`=11686; -- The Warsong Farms
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=11656; -- Burn in Effigy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=12465; -- Plunderbeard's Journal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=12466; -- Chasing Icestorm: The 7th Legion Front
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=12467; -- Chasing Icestorm: Thel'zan's Phylactery
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=13623 WHERE `ID`=11634; -- Wind Master To'bor
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=273, `RewardText`='Well done!  I could almost feel the tremors of the explosions from here!$B$BNow, we have one more bombing mission for you...', `VerifiedBuild`=13623 WHERE `ID`=10208; -- Disrupt Their Reinforcements
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=13623 WHERE `ID`=9572; -- Weaken the Ramparts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='<Buck listens as you recount your findings.>$B$BI think you may have found the proof we need for this Shango. And I think I have an idea as to where we can find him.', `VerifiedBuild`=13623 WHERE `ID`=12550; -- Dreadsaber Mastery: Stalking the Prey
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='<Grimbooze gives the cask a shake.>$B$BThere\'s something in here, but the million gold question is, can you drink it? Don\'t you go anywhere; you\'ll be responsible for overseeing the sampling of the product, too.', `VerifiedBuild`=13623 WHERE `ID`=12644; -- Still At It
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='<Hemet listens as you describe what you learned.>$B$BWay to go, $g lad:lass;. No dead rhino tells Hemet Nesingwary where and what he can hunt. We\'ll show that heap o\' bones.', `VerifiedBuild`=13623 WHERE `ID`=12544; -- The Bones of Nozronn
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='Each prisoner saved is one less undead aberration that we have to deal with, $N. You\'ve done a great service for the Horde.', `VerifiedBuild`=13623 WHERE `ID`=11676; -- Merciful Freedom
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='You\'re a true hero, $N. My kodos would have died out there without you. You have my thanks and the thanks of all the soldiers and journeymen that will use these kodos to strengthen our presence in Northrend!', `VerifiedBuild`=13623 WHERE `ID`=11690; -- Bring 'Em Back Alive
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12439; -- A Disturbance In The West
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12440; -- To Stars' Rest!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12472; -- Finality
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12520; -- Rhino Mastery: The Test
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12523; -- Have a Part, Give a Part
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12526; -- Rhino Mastery: The Chase
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12543; -- An Offering for Soo-rahm
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12549; -- Dreadsaber Mastery: Becoming a Predator
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12556; -- Rhino Mastery: The Kill
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12558; -- Dreadsaber Mastery: Ready to Pounce
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12589; -- Kick, What Kick?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12595; -- In Search of Bigger Game
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12603; -- Sharpening Your Talons
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=13623 WHERE `ID`=12634; -- Some Make Lemonade, Some Make Liquor
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=13623 WHERE `ID`=10129; -- Mission: Gateways Murketh and Shaadraz
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=13623 WHERE `ID`=10162; -- Mission: The Abyssal Shelf
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=18, `RewardText`='You\'re not Snivel. He was supposed to be here an hour ago! What have you done with him?$B$B<Roka seems to calm down when you tell her that you\'re looking for Snivel, too. Then, tears start to well up in her eyes.>$B$BThis isn\'t like my sweet Snivel. Do you think something\'s happened to him?', `VerifiedBuild`=13623 WHERE `ID`=24850; -- Snivel's Sweetheart
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `RewardText`='Ah, so you slew that villain, Kruush!  Well done, $N!  Well done!  His death will defang those cursed worg riders.  In fact, I hope you took a few of them out during your foray into Zeth\'Gor!$B$BHere\'s your reward.  You earned every piece of it!', `VerifiedBuild`=13623 WHERE `ID`=10809; -- Wanted: Worg Master Kruush
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='<Brann looks at the disk as you hold it up.>$B$BI can\'t tell if there\'s anything stored there or not! You have to tell me what happened.$B$B<You describe the data retrieval process.>$B$BSo it worked? At least we can count on Mimir to be systematic. Can\'t say that for the rest of these Keepers from what I\'ve been hearing... ', `VerifiedBuild`=13623 WHERE `ID`=12860; -- Data Mining
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='<Taleris shouts to several of the blood elves at the outpost.>$B$BGet her inside and see to her wounds!$B$B<Taleris turns back to you.>$B$BShe\'s fortunate that you found her when you did, $c. I don\'t think she\'d have lasted much longer out there.$B$BCan you make out what she was saying? ', `VerifiedBuild`=13623 WHERE `ID`=9375; -- The Road to Falcon Watch
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ah, a report from Albreck?  Very good.  The Royal Apothecary Society works feverishly to determine how the orcs of Hellfire Peninsula became fel orcs.  Their betrayal is unforgivable... and we must ensure that our orc friends are forever safe from future corruption.', `VerifiedBuild`=13623 WHERE `ID`=10835; -- Apothecary Antonivich
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ah, yes.  Just as some who lost a hand or a leg in battle will oftentimes feel their severed limb, I wonder if Grillok still clutched at his lost eye in his dark, dark dreams...$B$BI too will dream on this, and if fortune is with us then perhaps I will learn what drew Grillok and the Bleeding Hollow orcs to succumb to demons.', `VerifiedBuild`=13623 WHERE `ID`=10834; -- Grillok "Darkeye"
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Before you say anything, do not assume me as foolish as most of the Oracles you\'ve met. I\'ve been into the world a bit, I\'ve learned your language, and I\'m not easily duped.$B$BI knew the Mosswalkers were dead before we ever came, though I didn\'t know that the undead were behind it.$B$BThey are not supposed to be able to enter this land... the destruction of the Lifeblood Pillar must have allowed them in somehow. We must see to it that they leave.', `VerifiedBuild`=13623 WHERE `ID`=12578; -- The Angry Gorloc
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Grim news, $G lad:lass;. Those iron dwarves seem to be increasing in numbers... we\'ve been seeing them all over the mountains. I smell war coming.$B$BThank you for dealing with this bunch... a little more time bought.', `VerifiedBuild`=13623 WHERE `ID`=12876; -- Unwelcome Guests
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ha! Grand tale $G lad:lass;... perhaps ye have a bit of frostborn blood in ye, eh? Yer not just talk anyway, and that\'s what I needed to hear.', `VerifiedBuild`=13623 WHERE `ID`=12874; -- Fervor of the Frostborn
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='It good to see you again. I knew you not a traitor, I glad Zepik prove me right.$B$BI hear you Lich Hunter now - that pretty good! You make Harkek proud.', `VerifiedBuild`=13623 WHERE `ID`=12692; -- Return of the Lich Hunter
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Now that\'s a meal! If anything good came of the shipwreck, it\'s got to be that we\'ve been spared eating nothing but salt beef for the next month! Thank you again, $N.', `VerifiedBuild`=13623 WHERE `ID`=12804; -- A Steak Fit for a Hunter
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='So you\'re the one responsible for clearing out Felspark, eh?  That\'s good to hear - we need soldiers like you who can take these fiends head on!', `VerifiedBuild`=13623 WHERE `ID`=10124; -- Forward Base: Reaver's Fall
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Someone is using the Forge of Wills to create this army... Ulduar is no longer safe.$B$B$R, I am pleased that you were able to reach the core before these abominations were.', `VerifiedBuild`=13623 WHERE `ID`=12879; -- Fury of the Frostborn King
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='The heavens, in their countless stars, hold answers to earthly mysteries, $N.  Might, then, the wise, and the lucky, gaze up and find truth?', `VerifiedBuild`=13623 WHERE `ID`=8713; -- Starsong the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='The news you bear forth is grave indeed. I do not know the fate of the remaining watchers, but their absence spells dark times for all of the lands of Azeroth.$B$BI shall examine the knowledge contained in the databank that you have returned and attempt to fully assess the situation. I believe I am in possession of knowledge that you deem more pertinent at this moment however, so I shall allow you to partake in said wisdom first.', `VerifiedBuild`=13623 WHERE `ID`=12986; -- Fate of the Titans
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='These should do the job. I was concerned that the rangers might be short on arrows for a while, but that\'s one less thing I have to worry about. Thank you for your help, $c.', `VerifiedBuild`=13623 WHERE `ID`=9381; -- Trueflight Arrows
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Two out of three drinkers agree, eh? Not bad for a first try. Not bad at all. I suppose I\'ll have to whip up something else for Tamara by way of apology.$B$BNow... what should we call this creation?', `VerifiedBuild`=13623 WHERE `ID`=12645; -- The Taste Test
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Very good.  Now I can more easily perform my tests...$B$BThank you, $N.  Your talents are considerable.', `VerifiedBuild`=13623 WHERE `ID`=10538; -- Boiling Blood
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='We\'ve already lost many brave warriors to this cursed wasteland. I have little interest in sending more untested recruits to the slaughter.$B$B<Nazgrel glares at you sternly through his ragged wolf-mask>$B$BStill, if General Krakork sent you to me, he must have seen something in you. What say you then, $n? Will you serve your warchief with honor?', `VerifiedBuild`=13623 WHERE `ID`=10291; -- Report to Nazgrel
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Well done, $N.  Your soul is burdened with many deaths... and the Demonaic Scryer will now perform its duties for you.$B$BLet us hope you are ready for the coming trial...', `VerifiedBuild`=13623 WHERE `ID`=10864; -- A Burden of Souls
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You... you\'re not a member of the Explorers\' League, at least not one I remember. But, if you recovered the communicator, they must\'ve sent you. Good, that\'s almost what I was hoping for.$B$B', `VerifiedBuild`=13623 WHERE `ID`=12855; -- Sniffing Out the Perpetrator
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=9376; -- A Pilgrim's Plight
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=10450; -- Bonechewer Blood
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=11661; -- Orabus the Helmsman
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12528; -- Playing Along
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12529; -- The Ape Hunter's Slave
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12530; -- Tormenting the Softknuckles
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12532; -- Flown the Coop!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12533; -- The Wasp Hunter's Apprentice
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12535; -- Mischief in the Making
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12536; -- A Rough Ride
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12551; -- Crocolisk Mastery: The Trial
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12569; -- Crocolisk Mastery: The Ambush
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12574; -- Back So Soon?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12576; -- Forced Hand
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12579; -- Lifeblood of the Mosswalker Shrine
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12580; -- The Mosswalker Savior
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12605; -- Securing the Bait
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12858; -- Pieces to the Puzzle
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12869; -- Pushed Too Far
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=12973; -- The Brothers Bronzebeard
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=13623 WHERE `ID`=24636; -- Bonbon Blitz
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=10087; -- Burn It Up... For the Horde!
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=10123; -- Felspark Ravine
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=66, `Emote4`=1, `RewardText`='Wintergarde is saved because of you, $N. To think that one $g man:woman; could so swiftly turn the tides of battle is hard for most to comprehend; yet here we are - victorious! You have managed to restore the faith of these people and earned the respect of your commanding officers.$B$B<Halford salutes.> $B$BLord Fordragon has returned to Angrathar to prepare our forces for the destruction of the Wrathgate and has requested that you join him! I couldn\'t recommend a better soldier for the job, $N.\n', `VerifiedBuild`=13623 WHERE `ID`=12473; -- An End And A Beginning
UPDATE `quest_offer_reward` SET `Emote1`=4, `EmoteDelay1`=4000, `VerifiedBuild`=13623 WHERE `ID`=10390; -- Forge Camp: Mageddon
UPDATE `quest_offer_reward` SET `Emote1`=4, `RewardText`='This stuff is great!  A little bent and a little burnt, but I\'ve never let low grade materials stop me from making precision high explosives.$B$BThanks, $n.  You really have an eye for quality trash!', `VerifiedBuild`=13623 WHERE `ID`=10086; -- I Work... For the Horde!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=13623 WHERE `ID`=4295; -- Rocknot's Ale
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `RewardText`='THEY HAVE A PIT LORD?!$B$B<Nazgrel notices the glances of the others assembled and lowers his voice to a whisper.>$B$BThat seals it.  They must be using the blood from this pit lord to create new fel orcs that are somehow not aligned with the Burning Legion.  And if they can do this to the Mag\'har brown orcs, they can do it to us!$B$BWe\'ll have to strike at the heart of their military might, and soon!', `VerifiedBuild`=13623 WHERE `ID`=9608; -- Heart of Rage
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=11636; -- Magic Carpet Ride
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=13623 WHERE `ID`=11705; -- Foolish Endeavors
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `EmoteDelay2`=30, `VerifiedBuild`=13623 WHERE `ID`=12538; -- The Mist Isn't Listening
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `RewardText`='So, you\'ve come to concede already?$B$B<Drostan\'s jaw drops as you tell him you\'ve already made all your kills.>$B$BNo way! How in Azeroth did you do that? I just made my 58th. So close!$B$BBut fair\'s fair. I underestimated you, $N, but you\'ve earned this victory fair and square.', `VerifiedBuild`=13623 WHERE `ID`=12592; -- The Great Hunter's Challenge
UPDATE `quest_offer_reward` SET `Emote1`=5, `EmoteDelay1`=20, `VerifiedBuild`=13623 WHERE `ID`=12572; -- Gods like Shiny Things
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='Hah!  I could see the smoke and flames of Zeth\'Gor from here!  May the Bleeding Hollow fiends burn to ash and drift far from the sight of any true orc!$B$BThank you, $N.  You helped burn away an afront to every orc\'s spirit.', `VerifiedBuild`=13623 WHERE `ID`=10792; -- Zeth'Gor Must Burn!
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='It\'s about time someone came out here.  I sent that report to Stonebreaker Hold over a week ago!$B$BBlood elves and their bureaucracy!', `VerifiedBuild`=13623 WHERE `ID`=10039; -- Speak with Scout Neftis
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='You\'re brilliant, $G lad:lass;! Brilliant! This will be a glorious day indeed.$B$BQuickly, hand me the core before those iron dwarves make their way down here.', `VerifiedBuild`=13623 WHERE `ID`=12880; -- The Master Explorer
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=13623 WHERE `ID`=11688; -- Damned Filthy Swine
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=13623 WHERE `ID`=12534; -- The Sapphire Queen
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=13623 WHERE `ID`=12573; -- Making Peace
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=13623 WHERE `ID`=12575; -- The Lost Mistwhisper Treasure
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=13623 WHERE `ID`=12871; -- Aid from the Explorers' League
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=13623 WHERE `ID`=11642; -- Tank Ain't Gonna Fix Itself
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `RewardText`='I\'ll rally what troops I can and send them to aid Orion\'s forces at the Dark Portal. The Legion will not soon forget the battle cry of the Horde! As for you $n, you\'ve done a great service for Thrallmar this day. I expect you\'ll be a great help to us here... if you have the wits to survive, that is.', `VerifiedBuild`=13623 WHERE `ID`=10289; -- Journey to Thrallmar
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `RewardText`='That\'s it! That\'s the first half of Norgannon\'s keystone. Well done, $N. When I get back to Ironforge, I\'m going to have you inducted as an honorary member in the Explorers\' League!', `VerifiedBuild`=13623 WHERE `ID`=12872; -- Norgannon's Shell
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=66, `Emote3`=1, `Emote4`=5, `RewardText`='No doubt you saw the Legion\'s warriors dotting the landscape on your flight from the Dark Portal. Though we defeated them at the Battle of Mount Hyjal some five years past, the cursed demons just keep coming back for more. If it\'s a challenge they crave, then the Horde will answer in kind!$B$BWe orcs have more than just a score to settle with the Legion. What about you, $n? Shall I tell you of our enemy?', `VerifiedBuild`=13623 WHERE `ID`=10121; -- Eradicate the Burning Legion
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`='Drom\'s ring? I am to assume Drom is not well if he did not introduce you directly. I am sorry to hear of that. Drom is a noble dwarf, if an inquisitive one.$B$BOn what business have you come then?', `VerifiedBuild`=13623 WHERE `ID`=12877; -- The Lonesome Watcher
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`='Good, you finally made it back!  Okay, what did you figure out?  Who are they?', `VerifiedBuild`=13623 WHERE `ID`=10041; -- Who Are They?
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`='So you\'re Orion\'s new messenger? I pray you fare better than the last one he sent, $c.  With the Legion pressing in, you\'d never make it to Thrallmar on foot. Say the word, and my faithful wyvern will deliver you there safely.', `VerifiedBuild`=13623 WHERE `ID`=10120; -- Arrival in Outland
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`='You help us? You welcome then, dryskin.', `VerifiedBuild`=13623 WHERE `ID`=12570; -- Fortunate Misunderstandings
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=11703; -- Get to Getry
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=12531; -- The Underground Menace
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=12540; -- Just Following Orders
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=12571; -- Make the Bad Snake Go Away
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=12577; -- Home Time!
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=13623 WHERE `ID`=12873; -- The Frostborn King
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=13623 WHERE `ID`=12539; -- Hoofing It
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=11, `EmoteDelay1`=1000, `EmoteDelay2`=4000, `RewardText`='You have saved my life\'s work $N.  $B$BThey called me insane, they laughed at me, they thought I was mad for my obsession with the Void Ridge and Warp Fields.  Now with this soul shard I can unlock the secrets of the voidwalkers.  I will command the power of the abyss.  ', `VerifiedBuild`=13623 WHERE `ID`=10295; -- From the Abyss
UPDATE `quest_offer_reward` SET `Emote1`=11, `EmoteDelay1`=4000, `RewardText`='Excellent, the warp rift generator is almost complete.  There is only one final ingredient we require.  Soon we shall be able to open up a warp rift to the deepest parts of the abyss.  $B$BWho knows what strange creature may come through?  Think of it $N, the power such knowledge will bring is limitless.  ', `VerifiedBuild`=13623 WHERE `ID`=10294; -- Void Ridge
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=18, `VerifiedBuild`=13623 WHERE `ID`=24851; -- Hot On The Trail
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='Nice work, $N.  I could almost hear the battles waged at those forts.  I wish I was there to see them!', `VerifiedBuild`=13623 WHERE `ID`=13409; -- Hellfire Fortifications
UPDATE `quest_offer_reward` SET `Emote1`=113, `EmoteDelay1`=6000, `RewardText`='Praise the ancients, you\'ve done it, $N! The Legion has suffered a terrible defeat - and Thrallmar is safe once again. Ah, if I had but a hundred warriors with your heart and cunning, this broken land would be tamed already! I salute you.  $B$B<Nazgrel salutes you crisply>\n', `VerifiedBuild`=13623 WHERE `ID`=10392; -- Doorway to the Abyss
UPDATE `quest_offer_reward` SET `Emote1`=153, `VerifiedBuild`=13623 WHERE `ID`=12537; -- Lightning Definitely Strikes Twice
UPDATE `quest_offer_reward` SET `Emote1`=273, `RewardText`='I am indebted to you, $n.  You have again braved Zeth\'Gor and held its darkness close to your heart.  I will study the eye and perhaps pierce the secrets of its master, Grillok.$B$BLet us hope that he can no longer use its magic!', `VerifiedBuild`=13623 WHERE `ID`=10813; -- The Eyes of Grillok
UPDATE `quest_offer_reward` SET `EmoteDelay1`=2000, `VerifiedBuild`=13623 WHERE `ID`=10278; -- The Warp Rifts
UPDATE `quest_offer_reward` SET `EmoteDelay1`=4000, `VerifiedBuild`=13623 WHERE `ID`=10258; -- Honor the Fallen
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=13623 WHERE `ID`=10442; -- Helping the Cenarion Post
UPDATE `quest_offer_reward` SET `RewardText`='<Drom coughs up a bit of blood.>$B$BNorgannon\'s Core, eh? I\'ve spent a fair number of days trying to find anything I could about it myself, but it seems to be one of the relics that\'s still guarded. With reason I suppose.$B$BIf King Stormheart sent you, he surely must see something noble in ye... and I\'m not one to refuse my king.', `VerifiedBuild`=13623 WHERE `ID`=12875; -- An Experienced Guide
UPDATE `quest_offer_reward` SET `RewardText`='<Inside Artruis\'s Phylactery you see what seems like an endless void... and you think you hear screaming in the distance from somewhere inside.>$B$B<As you\'re about to leave, you see an object floating in the void, just barely in reach.>', `VerifiedBuild`=13623 WHERE `ID`=12581; -- A Hero's Burden
UPDATE `quest_offer_reward` SET `RewardText`='<You insert the disk into the console. Suddenly, lights on its surface illuminate and a mechanical voice speaks.>$B$BInventor\'s disk authenticated. Welcome back, Keeper Mimir.', `VerifiedBuild`=13623 WHERE `ID`=13415; -- The Library Console
UPDATE `quest_offer_reward` SET `RewardText`='Ah ha! So, that\'s it! They\'re planning on invading Uldum.$B$BWhat\'s worse is that the pyramid inside the Maker\'s Terrace at Uldum can be reconfigured to become a weapon. A weapon that is capable of destroying all life on Azeroth!', `VerifiedBuild`=13623 WHERE `ID`=27040; -- Decryption Made Easy
UPDATE `quest_offer_reward` SET `RewardText`='Ahh yes. That\'ll save me hours.$b$bTake this for your trouble, friend. And keep an eye out for more element 115. I\'ll take all you can find.', `VerifiedBuild`=13623 WHERE `ID`=12443; -- Seeking Solvent
UPDATE `quest_offer_reward` SET `RewardText`='Good job, $N.  That should teach the rock flayers to stay far away from us.', `VerifiedBuild`=13623 WHERE `ID`=9340; -- The Great Fissure
UPDATE `quest_offer_reward` SET `RewardText`='Muradin lives? Could it be? I must notify King Bronzebeard at once!$B$BI need to consult the orb. There must be more information - somewhere!\n', `VerifiedBuild`=13623 WHERE `ID`=12478; -- Frostmourne Cavern
UPDATE `quest_offer_reward` SET `RewardText`='The spirits are closer to finding peace and have bestowed their favor onto us.$B$BA humiliating blow to our enemy that their own ancestors would side against them, even if only temporarily.', `VerifiedBuild`=13623 WHERE `ID`=11506; -- Spirits of Auchindoun
UPDATE `quest_offer_reward` SET `RewardText`='This commendation is only given to those who have gone above and beyond the call of duty in the name of the Alliance. I could count the number of times I\'ve handed this one out on one hand, $N, and never has anyone been more deserving than you! Congratulations!$B$BNow, let us look upon the Wrathgate. Does it look familiar? It should. That strange ore you found at the Wintergarde Mine is exactly what the Wrathgate is made from. We will find its weakness and expose it for all to see! First, though...', `VerifiedBuild`=13623 WHERE `ID`=12474; -- To Fordragon Hold!
UPDATE `quest_offer_reward` SET `RewardText`='Welcome to Falcon Watch, $r.  All our Horde allies are welcome here, especially those recommended by Martik.', `VerifiedBuild`=13623 WHERE `ID`=9498; -- Falcon Watch
UPDATE `quest_offer_reward` SET `RewardText`='You got his ledger? Really? That\'s great, $n. There\'s probably loads of good information in here.', `VerifiedBuild`=13623 WHERE `ID`=24576; -- A Friendly Chat...
UPDATE `quest_offer_reward` SET `RewardText`='You got it, huh? Good job, kid. Top notch. Let\'s see what we got here.\n\n<He cracks open the crate and rummages around inside.>', `VerifiedBuild`=13623 WHERE `ID`=24541; -- Pilfering Perfume
UPDATE `quest_offer_reward` SET `RewardText`='You\'re a brave $c, $N.  That savage beast took many of my best hunters\' lives.$B$BTake this reward, you\'ve earned it.', `VerifiedBuild`=13623 WHERE `ID`=9466; -- Wanted: Blacktalon the Savage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9345; -- Preparing the Salve
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9366; -- In Need of Felblood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9370; -- The Cleansing Must Be Stopped
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9374; -- Arelion's Journal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9387; -- Source of the Corruption
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9391; -- Marking the Path
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9396; -- Magic of the Arakkoa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9397; -- Birds of a Feather
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9472; -- Arelion's Mistress
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9483; -- Life's Finer Pleasures
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9720; -- Balance Must Be Preserved
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9724; -- Warning the Cenarion Circle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9731; -- Drain Schematics
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9732; -- Return to the Marsh
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9769; -- There's No Explanation for Fashion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9770; -- Menacing Marshfangs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9771; -- Searching for Scout Jyoba
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9772; -- Jyoba's Report
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9773; -- No More Mushrooms!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9774; -- Thick Hydra Scales
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9775; -- Report to Shadow Hunter Denjai
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9784; -- Identify Plant Parts
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9785; -- Blessings of the Ancients
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9817; -- Leader of the Bloodscale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9828; -- Withered Basidium
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9898; -- Nothin' Says Lovin' Like a Big Stinger
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9899; -- A Job Undone
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=9912; -- The Cenarion Expedition
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10103; -- Report to Zurai
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10132; -- Colossal Menace
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10211; -- City of Light
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10213; -- Investigate the Crash
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10220; -- Make Them Listen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10229; -- Decipher the Tome
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10230; -- The Battle Horn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10242; -- Spinebreaker Post
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10250; -- Bloody Vengeance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10286; -- Arelion's Secret
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10287; -- The Mistress Revealed
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10347; -- Return to the Abyssal Shelf
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10351; -- Natural Remedies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10388; -- Return to Thrallmar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10391; -- Cannons of Rage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10393; -- Vile Plans
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10449; -- Apothecary Zelana
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=10551; -- Allegiance to the Aldor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12142; -- Pest Control
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12143; -- Canyon Chase
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12146; -- Disturbing Implications
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12237; -- Flight of the Wintergarde Defender
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12251; -- Return to the High Commander
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12253; -- Rescue from Town Square
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12258; -- The Fate of the Dead
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12269; -- Not In Our Mine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12272; -- The Bleeding Ore
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12275; -- The Demo-gnome
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12276; -- The Search for Slinkin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12277; -- Leave Nothing to Chance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12281; -- Understanding the Scourge War Machine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12282; -- Imprints on the Past
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12287; -- Orik Trueheart and the Forgotten Shore
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12290; -- The Murkweed Elixir
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12291; -- The Forgotten Tale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12301; -- The Truth Shall Set Us Free
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12305; -- Parting Thoughts
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12309; -- Find Durkon!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12311; -- The Noble's Crypt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12312; -- Secrets of the Scourge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12319; -- Mystery of the Tome
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12320; -- Understanding the Language of Death
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12321; -- A Righteous Sermon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12325; -- Into Hostile Territory
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12326; -- Steamtank Surprise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12454; -- Cycle of Life
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12455; -- Scattered To The Wind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12457; -- The Chain Gun And You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12458; -- Seeds of the Lashers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12462; -- Breaking Off A Piece
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12463; -- Plunderbeard Must Be Found!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12475; -- What Secrets Men Hide
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12476; -- The Return of the Crusade?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12477; -- The Path of Redemption
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12495; -- Audience With The Dragon Queen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12499; -- Return To Angrathar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12560; -- Crocolisk Mastery: The Plan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12624; -- It Could Be Anywhere!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12671; -- Reconnaissance Flight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12696; -- Aerial Surveillance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12699; -- An Embarrassing Incident
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12789; -- Into the Breach!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=12878; -- The Hidden Relic
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=27004; -- The Twilight Plot
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=27006; -- Fly Over
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=27042; -- Fight Fire and Water and Air with...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=13623 WHERE `ID`=27058; -- The Wrong Sequence

DELETE FROM `quest_offer_reward` WHERE `ID` IN (27576 /*Patchwork Command*/, 27508 /*Far from the Nest*/, 27507 /*Encroaching Twilight*/, 27509 /*Breach in the Defenses*/, 27564 /*In Defense of the Redoubt*/, 27505 /*Draconic Mending*/, 27506 /*Life from Death*/, 27504 /*Even Dragons Bleed*/, 27486 /*Warm Welcome*/, 28170 /*Night Terrors*/, 28166 /*Thog's Nightlight*/, 28151 /*Dressed to Kill*/, 28149 /*Whispers in the Wind*/, 28147 /*Purple is Your Color*/, 27380 /*Nightmare*/, 27379 /*The Terrors of Iso'rath*/, 27378 /*The Worldbreaker*/, 27377 /*Devoured*/, 27376 /*The Maw of Iso'rath*/, 27300 /*Pushing Back*/, 27303 /*Mercy for the Bound*/, 27302 /*Simple Solutions*/, 27301 /*Unbroken*/, 27299 /*Torn Ground*/, 27375 /*The Weeping Wound*/, 28133 /*Fury Unbound*/, 28123 /*The Demon Chain*/, 27955 /*Eye Spy*/, 27954 /*The Eyes Have It*/, 27945 /*Paint it Black*/, 28043 /*How to Maim Your Dragon*/, 28038 /*Blood in the Highlands*/, 28041 /*Bait and Throttle*/, 27951 /*We All Must Sacrifice*/, 27947 /*A Vision of Twilight*/, 27747 /*Total War*/, 27929 /*Drag 'em Down*/, 27751 /*Crushing the Wildhammer*/, 27750 /*War Forage*/, 27690 /*Narkrall, the Drake-Tamer*/, 27611 /*Blood on the Sand*/, 27610 /*Scouting the Shore*/, 27607 /*The Southern Flank*/, 27606 /*Blast Him!*/, 27584 /*Blood in the Surf*/, 27586 /*Shells on the Sea Shore*/, 27583 /*The Northern Flank*/, 28909 /*Sauranok Will Point the Way*/, 25985 /*Wings Over Mount Hyjal*/, 25165 /*Never Trust a Big Barb and a Smile*/, 26858 /*Taragaman the Hungerer*/, 26856 /*Repel the Invasion*/, 26230 /*Feast or Famine*/, 26192 /*Orphans Like Cookies Too!*/, 26420 /*Diggin' For Worms*/, 26396 /*Return to Argus*/, 26395 /*Dungar Longdrink*/, 26913 /*Charging into Battle*/, 13975 /*Crossroads Caravan Delivery*/, 13949 /*Crossroads Caravan Pickup*/, 26878 /*Disciples of Naralex*/, 13969 /*Grol'dom's Missing Kodo*/, 13968 /*The Tortusk Takedown*/, 13963 /*By Hook Or By Crook*/, 13961 /*Drag it Out of Them*/, 13973 /*The Grol'dom Militia*/, 27043 /*Fight Fire and Water and Air with...*/, 26642 /*Preserving the Barrens*/, 26378 /*Hero's Call: Westfall!*/, 26152 /*Wanted: James Clark*/, 26150 /*A Visit With Maybell*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(27576, 1, 0, 0, 0, 0, 0, 0, 0, 'You got the dragons in the game! Good on you.$B$BWe\'d already laid out plans for our ambush by the time the dragons contacted us. They\'re helping by cutting off their retreat.$B$BIt\'s not too late for you to join in on the fun though. We saved some for you.', 14333), -- Patchwork Command
(27508, 1, 0, 0, 0, 0, 0, 0, 0, 'I don\'t know if you did this for me or the young inside these eggs, but it doesn\'t really matter, either way it\'s clear that you want to be an ally of our flight. I appreciate that.$B$BI cannot forgive the attacks by your allies against my brood, but for now, it seems you have chosen the right side.', 14333), -- Far from the Nest
(27507, 1, 0, 0, 0, 0, 0, 0, 0, 'You have a talent for killing I see. In times like these, that has its place.', 14333), -- Encroaching Twilight
(27509, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done. Thank you, $r.$B$BI will not be so foolish as to let such an oversight happen again.', 14333), -- Breach in the Defenses
(27564, 1, 0, 0, 0, 0, 0, 0, 0, 'I hope you\'re as tough as your gear suggests. The Twilight\'s Hammer have made their way within the redoubt somehow and I need someone to hunt them down.', 14333), -- In Defense of the Redoubt
(27505, 1, 0, 0, 0, 0, 0, 0, 0, 'We will take Grim Batol back from the Twilight\'s Hammer and their allies. It may take time, but this is one charge that we cannot forsake.', 14333), -- Draconic Mending
(27506, 1, 0, 0, 0, 0, 0, 0, 0, 'In this, we deny Deathwing the destruction that he so passionately seeks. In this, life continues.', 14333), -- Life from Death
(27504, 1, 0, 0, 0, 0, 0, 0, 0, 'Calen has become very trusting. It is not often that strangers are permitted within the redoubt.', 14333), -- Even Dragons Bleed
(27486, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'m glad Lira didn\'t scare you off. I won\'t say her concerns aren\'t warranted, but we have a common enemy. She is perhaps a bit overzealous.', 14333), -- Warm Welcome
(28170, 4, 1, 5, 0, 0, 0, 0, 0, 'You see! De dead be nothing to be scared of. You brought de light to de darkness, mon, and never flinched.$B$BWe can use dis cave now as a base of operations in de northern Highlands. You\'re de best, $N!', 14333), -- Night Terrors
(28166, 1, 273, 0, 0, 0, 0, 0, 0, 'Ah, dis be it, mon.$B$B<The lens glows brightly in Buunu\'s hands, casting unearthly rays of light across the shadowy cave mouth.>$B$BWe be ready to bring dem spirits out de shadows now.', 14333), -- Thog's Nightlight
(28151, 11, 1, 0, 0, 0, 0, 0, 0, 'Hah! I\'m sure Twilight\'s Hammer wanted to number those ogres among their ranks. Now they\'ll probably have to fight them off instead.$B$BThis is good, $N. With one well-placed $c we managed to do the work of a small army. I\'ll let Warlord Krogg know of your work here!', 14333), -- Dressed to Kill
(28149, 6, 5, 0, 0, 0, 0, 0, 0, 'Dat\'s de stuff, mon!$B$BNow can you hear dem? De spirits, dey be talkin\', but dey say nothing nice.$B$BLet us bring dem to de light.', 14333), -- Whispers in the Wind
(28147, 6, 1, 0, 0, 0, 0, 0, 0, 'What did you manage to get? I suppose we can piece something together from this.$B$BAfter all, you\'re not joining the cult. We just need to fool a few ogres.', 14333), -- Purple is Your Color
(27380, 1, 0, 0, 0, 0, 0, 0, 0, 'You saved many of my closest allies today, $n. I can only imagine what horrors you witnessed within Iso\'rath, but you have the thanks of all of the Earthen Ring.', 14333), -- Nightmare
(27379, 1, 0, 0, 0, 0, 0, 0, 0, 'United with the Earthen Ring, we can survive the horrors of Iso\'rath. Now it is time to turn our vengeance upon him!', 14333), -- The Terrors of Iso'rath
(27378, 5, 0, 0, 0, 0, 0, 0, 0, 'You\'re awake! Thank the elements. I\'d almost lost all hope.', 14333), -- The Worldbreaker
(27377, 5, 0, 0, 0, 0, 0, 0, 0, 'I\'ve brought you back from the brink of death, hero!$B$BDeathwing is upon us! We need your help.', 14333), -- Devoured
(27376, 1, 0, 0, 0, 0, 0, 0, 0, 'The tentacles swept us off of our gryphons as well! They were far more nimble than we anticipated.$B$BNo matter. We were prepared for this possibility. I can summon the elemental from here if you can keep me safe.', 14333), -- The Maw of Iso'rath
(27300, 1, 0, 0, 0, 0, 0, 0, 0, 'Revenge is bittersweet, but I\'m glad we be havin\' someone as powerful as you do see dis done.', 14333), -- Pushing Back
(27303, 2, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $n. You are quite capable. I\'m extremely grateful that you\'ve chosen to aid us.', 14333), -- Mercy for the Bound
(27302, 5, 0, 0, 0, 0, 0, 0, 0, 'Now that\'s what I\'m talkin\' about! Can you think of all the uses for this stuff? I definitely can\'t. But I can think of a lot, and I\'m liking the possibilities.', 14333), -- Simple Solutions
(27301, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank the elements that you\'ve come. Did my brothers send you?', 14333), -- Unbroken
(27299, 1, 0, 0, 0, 0, 0, 0, 0, 'Tank ya, $c. A bit of breathin\' room helps a lot.', 14333), -- Torn Ground
(27375, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome, $Gbrotha:sista;. You\'ve chosen a harsh time to be joinin\' us, but that is to our fortune. We could use ya help.', 14333), -- The Weeping Wound
(28133, 1, 273, 66, 0, 0, 0, 0, 0, 'Once free of the chain, Torth died rather than submit again. I admire the creature. I will have his hide fashioned into a set of armor.$B$BThis much is clear to me now: The Dragonmaw cannot stand alone if the Alliance backs the Wildhammer. Narkrall proved that. And you have proven the might of the Horde, again and again.$B$BI will rebuild our drake wings and take up position outside the Bastion of Twilight. You should continue to help out here in the Gullet and elsewhere in the Highlands.', 14333), -- Fury Unbound
(28123, 273, 1, 0, 0, 0, 0, 0, 0, '<Zaela takes the gore-spattered length of chain and wraps it around her hand and wrist.>$B$BIf the stories are true, $N, it was on this length of chain that Deathwing had once fastened the Demon Soul, forged in his bid to control the other dragonflights. The Demon Soul has long been destroyed but perhaps this hunk of elementium holds some residual power...$B$BYou\'ve done a great thing today.', 14333), -- The Demon Chain
(27955, 6, 5, 15, 0, 0, 0, 0, 0, 'You\'ve gone pale, $c. What did the Eye show you?$B$BYou saw Cho\'gall? Wait - Cho\'gall saw you? He\'s watching us? He\'s watching us right now!?$B$BDamn this stupid dark magic! I\'m going to have to infiltrate Cho\'gall\'s stronghold myself.', 14333), -- Eye Spy
(27954, 6, 273, 0, 0, 0, 0, 0, 0, 'You found one? I\'ve been searching everywhere. Give it here!$B$BSome of these eyes are won over with riddles or verse. Others require magic. What did this one demand? Ah, it\'s no matter. What matters is that it\'s ours. ', 14333), -- The Eyes Have It
(27945, 1, 274, 0, 0, 0, 0, 0, 0, '<Mallia removes her eyepatch and holds the black diamond before her empty eye socket.>$B$BWhat have we, what have we - breaches, the breaches number three. Two heads, one wholly given to its master. I see the future. A hammer united. A mountain shattered. Oh - OH!$B$B<Mallia drops the diamond to the floor, covering her face with her hands.>', 14333), -- Paint it Black
(28043, 1, 5, 0, 0, 0, 0, 0, 0, 'That was an impressive aerial display, $N, but I wish it had come at a better time.$B$BNarkrall is a great warrior, but he\'s also an impatient fool. He\'s about to get himself killed ... and we\'re about to lose one of our most important weapons in the battle for the Highlands!', 14333), -- How to Maim Your Dragon
(28038, 6, 1, 0, 0, 0, 0, 0, 0, 'Hey, you\'re one $gbig strong heap of:lovely killing machine,; $c. Can you handle the crucible? We got bookies standing by!', 14333), -- Blood in the Highlands
(28041, 0, 0, 0, 0, 0, 0, 0, 0, '<You gather up the fresh carcass.>', 14333), -- Bait and Throttle
(27951, 0, 0, 0, 0, 0, 0, 0, 0, '<The Eye glimmers darkly, colors swirling about its dusky surface.>$B$BAh, the succulent thrill of life extinguished. Do you feel it, $c? Do you relish it as I do?$B$BNo, I see not. You fight to protect the lives of others. Pity.', 14333), -- We All Must Sacrifice
(27947, 0, 0, 0, 0, 0, 0, 0, 0, '<The Eye sits before you, humming ominously with dark energies.>$B$B<Without warning, the orb rotates, as if to look at you. You sense a malevolent presence, as though the orb is alive.>', 14333), -- A Vision of Twilight
(27747, 11, 1, 0, 0, 0, 0, 0, 0, 'Yes, yes. Burn them out, as you would flush groundhogs from their holes...$B$BWell done, $N.', 14333), -- Total War
(27929, 6, 1, 0, 0, 0, 0, 0, 0, 'You look a little battered. Those dwarves didn\'t give you any challenge, did they?$B$BStill, that was an impressive show.', 14333), -- Drag 'em Down
(27751, 273, 1, 0, 0, 0, 0, 0, 0, '<Narkrall clenches the insignias in his weathered hand.>$B$BSo, $c. There\'s more to you than meets the eye.$B$BMaybe your Horde can stand with the best of my warriors. Let\'s try you out...', 14333), -- Crushing the Wildhammer
(27750, 4, 1, 0, 0, 0, 0, 0, 0, '<Griff greedily snatches the heap of food, enough to feed dozens of men.>$B$BGreat! Did you get any for yourself?', 14333), -- War Forage
(27690, 6, 1, 0, 0, 0, 0, 0, 0, '<Narkrall sizes you up.>$B$BAnother mewling Horde whelp? Zaela saps our strength by diluting our forces with the weak. Very well, $c. Prove yourself to me, and show me what your Horde is made of. ', 14333), -- Narkrall, the Drake-Tamer
(27611, 66, 1, 0, 0, 0, 0, 0, 0, 'Good, good. Let them reap what they sow!', 14333), -- Blood on the Sand
(27610, 273, 1, 0, 0, 0, 0, 0, 0, 'Good work, $c. Now you know the lay of the land.$B$BIf you\'re ever having difficulty fighting here on the Twilight Shores, remember that capturing and holding the Beach Head will give all Horde forces here a combat advantage!', 14333), -- Scouting the Shore
(27607, 66, 1, 0, 0, 0, 0, 0, 0, 'Good timing, $c. We were just about to unleash a counter-attack.', 14333), -- The Southern Flank
(27606, 4, 1, 0, 0, 0, 0, 0, 0, 'Boom baby, boom!$B$BWhat? You killed the Fathom-Lord already?$B$BI suppose we should stop shelling his corpse, then.', 14333), -- Blast Him!
(27584, 1, 273, 0, 0, 0, 0, 0, 0, '<Gralok sizes you up.>$B$BYou\'re a true fighter, $n. I liked watching you work. Perhaps the Dragonmaw really DO belong in your Horde. ', 14333), -- Blood in the Surf
(27586, 1, 4, 0, 0, 0, 0, 0, 0, 'Oh yeah. YEAH! These are DEFINITELY going to kill somebody.$B$BProbably naga.', 14333), -- Shells on the Sea Shore
(27583, 6, 1, 0, 0, 0, 0, 0, 0, 'Warlord Zaela sent you? Good.$B$BIf you Horde are as strong as your Warchief promised, I expect to see some bloodshed on these shores.', 14333), -- The Northern Flank
(28909, 273, 0, 0, 0, 0, 0, 0, 0, '<Sauranok nods toward you.>$B$B$C.', 14333), -- Sauranok Will Point the Way
(25985, 1, 2, 0, 0, 0, 0, 0, 0, 'Oh, you were sent here by Tiala? A wonderful student, she\'ll do many great things.$B$BAlthough I sense even greater potential from you.$B$BPlease, stay a while in our shrine. There\'s much to do, but you can\'t accomplish anything with a troubled mind.', 14333), -- Wings Over Mount Hyjal
(25165, 71, 0, 0, 0, 0, 0, 0, 0, 'This is it!  The scorpid juju Bom\'bay been waitin\' for!  Now we gonna fix you right up, $c.$b$bYou come back to Bom\'bay when you be needin\' a pickup.  Bom\'bay got the spells to fix ya!', 14333), -- Never Trust a Big Barb and a Smile
(26858, 4, 1, 0, 0, 0, 0, 0, 0, 'My children will sing songs of your glories, $N!', 14333), -- Taragaman the Hungerer
(26856, 2, 1, 0, 0, 0, 0, 0, 0, 'You\'ve done it, $N! You\'ve upturned the Searing Blade\'s invasion before it could even start! Take this, as a token of my thanks.', 14333), -- Repel the Invasion
(26230, 396, 0, 0, 0, 0, 0, 0, 0, 'Just smellin\' you comin\' got my stomach rumblin\'! We\'re gonna eat like kings tonight!', 14333), -- Feast or Famine
(26192, 1, 1, 4, 0, 0, 0, 0, 0, 'These sacks look like just enough, $N.  Can\'t wait to see the smiles on the orphans\' faces.', 14333), -- Orphans Like Cookies Too!
(26420, 1, 1, 5, 0, 0, 0, 0, 0, 'Those look like some nice bass, $N.  Let\'s fry em\' up and see how they taste!', 14333), -- Diggin' For Worms
(26396, 4, 2, 0, 0, 0, 1000, 0, 0, 'Great, you brought the armor!  We\'ll get this divvied to those who need it immediately.$B$BThank you, $N.  Your efforts have been a great help to us.  And now that you\'re no stranger to gryphons, I hope you\'ll come and lend your aid to Goldshire often!', 14333), -- Return to Argus
(26395, 1, 0, 0, 0, 0, 0, 0, 0, 'A crate for Goldshire, eh?  People sure are getting lazy. Have you been to Goldshire before?  If so, then it\'s no problem, my friend.  I have plenty of gryphons trained to fly that route!', 14333), -- Dungar Longdrink
(26913, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'re a quick learner, $N. Return to me as you grow stronger and I\'ll show you other combat techniques.', 14333), -- Charging into Battle
(13975, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s about time we got some supplies through here. It\'s bad enough to be severed from Mulgore, but this city would fall apart if we lost our trade with Orgrimmar.', 14333), -- Crossroads Caravan Delivery
(13949, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'re a sight, $r. That\'s the first caravan to make it through this week!', 14333), -- Crossroads Caravan Pickup
(26878, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes, $c? What brings you to this place?', 14333), -- Disciples of Naralex
(13969, 0, 0, 0, 0, 0, 0, 0, 0, 'This poor battered kodo looks to be on the verge of death, but is still breathing. The Razormane haven\'t even plundered its cargo yet. If it can be revived, you may be able to save the entire shipment.', 14333), -- Grol'dom's Missing Kodo
(13968, 6, 1, 0, 0, 0, 1200, 0, 0, 'Ah, so Tortusk behaved as I expected? Went right for your throat? It is good that he\'s dead.$B$BThe Razormane quilboar have been separated from their leadership in the southern Barrens, no doubt allowing an animal like him to come to power. Perhaps without his influence we can start a dialogue with the survivors... Although hotter heads may prevail. ', 14333), -- The Tortusk Takedown
(13963, 11, 1, 0, 0, 0, 1500, 0, 0, 'Very interesting - our brute here seems both enthralled and terrified of the one they call \"Tortusk.\" A powerful leader can inspire his people to acts of greatness or atrocity... but we orcs would know that more than others.$B$BWe should turn our attention to this Tortusk problem.', 14333), -- By Hook Or By Crook
(13961, 22, 6, 0, 0, 0, 700, 0, 0, 'Oh my. We want to question this quilboar, not tenderize him!', 14333), -- Drag it Out of Them
(13973, 5, 273, 0, 0, 0, 800, 0, 0, 'I see you\'ve left a string of corpses in your wake, $r. I couldn\'t have done better. The livestock may be lost, but the land remains ours - thank you!', 14333), -- The Grol'dom Militia
(27043, 273, 1, 0, 0, 0, 1000, 0, 0, 'An excellent display of $c prowess.$B$B<The Reliquary eyes you up and down.>$B$BI believe that a reward is in order. Something appropriate for a $g powerful man : lovely lady; such as yourself.', 14333), -- Fight Fire and Water and Air with...
(26642, 6, 5, 0, 0, 0, 0, 0, 0, 'A fresh recruit from Orgrimmar is it?$B$B<Kargal sizes you up.>$B$BI\'ll take what I can get. Keeping the roads open has been a nightmare.', 14333), -- Preserving the Barrens
(26378, 1, 0, 0, 0, 0, 0, 0, 0, 'Murder, rookie. That\'s what you\'re looking at on the ground in front of us.', 14333), -- Hero's Call: Westfall!
(26152, 15, 0, 0, 0, 0, 0, 0, 0, 'And justice is served!', 14333), -- Wanted: James Clark
(26150, 1, 24, 0, 0, 0, 0, 0, 0, 'William sent you? Bless his soul. I... I\'m ok... It\'s just... Well...', 14333); -- A Visit With Maybell

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=273, `RewardText`='This is useless. Look at the date on this letter. The Furlbrows have been squatting on the Jansen Steed for five years.$B$BThey never could quite get their wagon... fixed.', `VerifiedBuild`=14333 WHERE `ID`=184; -- Furlbrow's Deed
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=800, `RewardText`='Well done, $N. Without Kreenig to orchestrate the raids, my grunts should be able to keep Far Watch secure. Your people should be proud to count you among them. ', `VerifiedBuild`=14333 WHERE `ID`=872; -- The Far Watch Offensive
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='As you experience what Shadowglen has to teach you, come see me--I will be able to help you understand more about your role as a hunter and what you are capable of.$B$BThese are dangerous times, $N, do not take for granted the skill of your pets--there are things in this world more dangerous than you can imagine. Go with Elune and return to me again.', `VerifiedBuild`=14333 WHERE `ID`=3117; -- Etched Sigil
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14333 WHERE `ID`=899; -- Consumed by Hatred
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14333 WHERE `ID`=26947; -- A Woodsman's Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Excellent! Thanks to you, I should be able to complete the order in time. To show my gratitude, I would like to offer some coin as compensation for your troubles.$B$BThank you and farewell.', `VerifiedBuild`=14333 WHERE `ID`=5545; -- A Bundle of Trouble
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Hah!  I guess she liked it!  Nothing brings red to a lady\'s cheeks like a big, juicy steak!$B$BThank you, $N.  You\'ve done me a great service.  Here is some money for your trouble, and don\'t be surprised if I invite you to my wedding!', `VerifiedBuild`=14333 WHERE `ID`=6386; -- Return to Razor Hill
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='My heart goes out to those two poor souls, Maybell and Tommy Joe.  I remember being young and in love, once.$B$BThere must be something I can do to help them!  Let me think...', `VerifiedBuild`=14333 WHERE `ID`=107; -- Note to William
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya casts - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=14333 WHERE `ID`=24765; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Oh, wonderful!  Those are fine cuts!  These are from Grimtak, are they?  That orc sure knows his way into a lady\'s heart...$B$BOh, I can\'t wait to cook it.  But not too much!  Meat is best served rare, don\'t you think?', `VerifiedBuild`=14333 WHERE `ID`=6384; -- Ride to Orgrimmar
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='So you\'ve been to the nests and placed the feathers of your prey within them. That took a fair portion of courage, no doubt about it.$B$BDo you feel a little tougher, $N? Because you look tougher now then when you first came here.  I guess the Barrens is doing its job.', `VerifiedBuild`=14333 WHERE `ID`=905; -- Into the Raptor's Den
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='This is bad news.  What\'s next, dragons?!?  We\'ll have to increase our patrols near that mine.  Thanks for your efforts, $N.  And hold a moment... I might have another task for you.', `VerifiedBuild`=14333 WHERE `ID`=62; -- The Fargodeep Mine
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Yes, I spoke with Remy.  I respect him as a merchant, though all reports of Murlocs to the east have been sketchy at best.$B$BYour concerns are noted, but unless I receive a military report of a murloc threat, we can\'t afford to send more troops east.', `VerifiedBuild`=14333 WHERE `ID`=40; -- A Fishy Peril
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You found him?  Well done, $N.  He won\'t be \"collecting\" from the Elwynn Mines again!$B$BAnd this ring you found is interesting... it\'s a membership ring for the old Stonemason\'s Guild in Stormwind. I haven\'t seen one of these in years, since back in the days when the Defias Brotherhood used to infest this land.', `VerifiedBuild`=14333 WHERE `ID`=147; -- Manhunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You have to get this meat to Orgrimmar?  That is no problem.  For a small fee, my wind rider can take you there.', `VerifiedBuild`=14333 WHERE `ID`=6365; -- Meats to Orgrimmar
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You have to get this to Razor Hill in Durotar?  Yes, I can get you there...', `VerifiedBuild`=14333 WHERE `ID`=6385; -- Doras the Wind Rider Master
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You\'ve beaten Echeyakee, and though his days of hunting are over... his spirit is with you. He will show you the strength found in subtlety, and the honor in mercy.$B$BI underestimated you, $c. The Horde is fortunate to have you in its ranks.', `VerifiedBuild`=14333 WHERE `ID`=881; -- Echeyakee
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=14333 WHERE `ID`=24767; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=14333 WHERE `ID`=28490; -- Hero's Call: Darkshore!
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`='Thanks, $N!  And come back if you want to trade again.', `VerifiedBuild`=14333 WHERE `ID`=16; -- Give Gerard a Drink
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`='You were busy hunting kobolds, were you?  Thanks for the candles, $N, and here\'s your reward...', `VerifiedBuild`=14333 WHERE `ID`=60; -- Kobold Candles
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2, `EmoteDelay2`=1000, `RewardText`='Aha!  So Grimand finally finished my axe!  I can\'t wait to try it against some troggs and kobolds!$B$BMany thanks, $N.  It was a long distance to travel for this delivery.   Here are some coins for your efforts.', `VerifiedBuild`=14333 WHERE `ID`=353; -- Stormpike's Delivery
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2, `RewardText`='Oh...my!  I feel guilty deceiving my family, but my feelings for Tommy Joe are too strong to ignore.$B$BThank you, $N.  I\'ll drink this liquor as soon as I have the chance and sneak away to my love.$B$BAnd for you... please take this.', `VerifiedBuild`=14333 WHERE `ID`=114; -- The Escape
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11, `RewardText`='Haha! Thank you, $N! This will help us greatly. I\'ll get these supplies packed up and on their way to the Crossroads immediately. ', `VerifiedBuild`=14333 WHERE `ID`=5041; -- Supplies for the Crossroads
UPDATE `quest_offer_reward` SET `Emote1`=4, `RewardText`='You got them.  Good show!  Now, just one moment while I concoct the potion...', `VerifiedBuild`=14333 WHERE `ID`=112; -- Collecting Kelp
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=14333 WHERE `ID`=24768; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='Kobolds at the Jasperlode Mine, you say?  Curses!  The situation is worsening by the minute!$B$BThank you for the report, $N.  But I wish that the news you brought was good news.', `VerifiedBuild`=14333 WHERE `ID`=76; -- The Jasperlode Mine
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=14333 WHERE `ID`=24766; -- The Arts of a Druid
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have a wild look about ya though. Fierce eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=14333 WHERE `ID`=24764; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=14333 WHERE `ID`=24769; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='I see you\'ve been busy!  You have our thanks, $N.', `VerifiedBuild`=14333 WHERE `ID`=11; -- Riverpaw Gnoll Bounty
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='Thanks a lot for the help, $N.  Something in the forest must be making these animals so bold.$B$BWhatever it is, I hope it stays there.', `VerifiedBuild`=14333 WHERE `ID`=52; -- Protect the Frontier
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='You have the fins?  Great!  Marshal Dughan is anxious about the Murloc situation in eastern Elwynn, and I\'d like to tell him that it\'s becoming under control.$B$BYour actions have helped realize that.', `VerifiedBuild`=14333 WHERE `ID`=46; -- Bounty on Murlocs
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=14333 WHERE `ID`=14402; -- Ready to Go
UPDATE `quest_offer_reward` SET `RewardText`='A disciple of the arcane always finds a way forward.  I\'m glad to see you, $N.', `VerifiedBuild`=14333 WHERE `ID`=14277; -- Arcane Inquiries
UPDATE `quest_offer_reward` SET `RewardText`='Ah!  I can\'t stand us being apart.  I have to see her!!', `VerifiedBuild`=14333 WHERE `ID`=106; -- Young Lovers
UPDATE `quest_offer_reward` SET `RewardText`='Ah, so you\'ve seen Renato?  Well here you are, $gsir:ma\'am;.  A bottle of our special pinot noir.  You\'ll not find its equal in all of Azeroth!', `VerifiedBuild`=14333 WHERE `ID`=332; -- Wine Shop Advert
UPDATE `quest_offer_reward` SET `RewardText`='Ah, thank you for the marker.  Please feel free to pick your choice of armor.$B$BLuck to you, brave $c.  And may this armor serve you well.', `VerifiedBuild`=14333 WHERE `ID`=59; -- Cloth and Leather Armor
UPDATE `quest_offer_reward` SET `RewardText`='Ah, these are nice scraps, if a little rough...$B$BHere you are!', `VerifiedBuild`=14333 WHERE `ID`=83; -- Fine Linen Goods
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, user $N.  We must obtain access to the fusion core now.', `VerifiedBuild`=14333 WHERE `ID`=27777; -- Core Access Codes
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N. You\'ve turned out to be quite an asset to this garrison. It\'s time for you to train!', `VerifiedBuild`=14333 WHERE `ID`=28774; -- Lions for Lambs
UPDATE `quest_offer_reward` SET `RewardText`='Get yourself squared away, learn the layout of the land, and come back to me whenever you need training. I\'ll be here night or day.$B$BThe Knights of the Silver Hand have done well in making this place fairly safe, but as you meet the other citizens, I think you\'ll find they all have problems they could use some help with--help a warrior can give them. Good luck.', `VerifiedBuild`=14333 WHERE `ID`=3100; -- Simple Letter
UPDATE `quest_offer_reward` SET `RewardText`='Good to see you again, $N. Now we\'ll get somewhere.', `VerifiedBuild`=14333 WHERE `ID`=26834; -- Down Into the Chasm
UPDATE `quest_offer_reward` SET `RewardText`='Hm... I have heard of this \"Collector\" but I don\'t know whom he\'s working for.  Thank you for the schedule.  It will help us solve this mystery.', `VerifiedBuild`=14333 WHERE `ID`=123; -- The Collector
UPDATE `quest_offer_reward` SET `RewardText`='I am in control, user $N.  But I cannot keep the core temperature stable indefinitely.', `VerifiedBuild`=14333 WHERE `ID`=27778; -- Hacking the Wibson
UPDATE `quest_offer_reward` SET `RewardText`='It is done, user $N.  I thank you for your assistance with this unfortunate task.', `VerifiedBuild`=14333 WHERE `ID`=27779; -- Gnomebliteration
UPDATE `quest_offer_reward` SET `RewardText`='It says here that Harlan\'s business is booming.  That\'s good news, but I wonder why people have need of all that armor.  I\'ve heard nothing of open war...is there something the nobles aren\'t telling us?$B$BWell, thank you for bringing the request.  Here\'s your payment, and I\'ll see to it that Harlan gets his supplies.', `VerifiedBuild`=14333 WHERE `ID`=333; -- Harlan Needs a Resupply
UPDATE `quest_offer_reward` SET `RewardText`='Marshall Dughan sent you, eh?  Well you\'re not from the army, but if Dughan sent you then that\'s good enough for me!$B$BOur situation is, to say the least, a stressed one.  I hope you can give us a hand.', `VerifiedBuild`=14333 WHERE `ID`=239; -- Westbrook Garrison Needs Help!
UPDATE `quest_offer_reward` SET `RewardText`='Mm, yum!  This pie is the best!$B$BI think my memory is coming back to me...', `VerifiedBuild`=14333 WHERE `ID`=84; -- Back to Billy
UPDATE `quest_offer_reward` SET `RewardText`='Oh, blast!  I thought forgetting my kit would free me from work.  Now I guess I\'ll have to help the Larsons with their sewing...$B$BOh, well.  Fun will come later I guess.', `VerifiedBuild`=14333 WHERE `ID`=334; -- Package for Thurman
UPDATE `quest_offer_reward` SET `RewardText`='Oh, you found it!  Thank you, thank you dear!$B$BHere, take this.  It was my husband\'s and he always said it was lucky.  If only he didn\'t forget it on his last campaign! *sniff*', `VerifiedBuild`=14333 WHERE `ID`=87; -- Goldtooth
UPDATE `quest_offer_reward` SET `RewardText`='Thank goodness!  That pig was getting so big she\'d have eaten our whole crop!  Thank you, $N.$B$BNow, do any of these suit you?', `VerifiedBuild`=14333 WHERE `ID`=88; -- Princess Must Die!
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. We\'ve never had such a problem in Deepholm before the destruction of the World Pillar.$B$BYour Earthen Ring must repair the damage before it\'s too late.', `VerifiedBuild`=14333 WHERE `ID`=26792; -- Fungal Monstrosities
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. Without all of their giants, Therazane\'s forces will have a harder time taking Stonehearth.$B$BNow, if you please, hand back the axe. I\'ll keep it safe until you can rescue the Stonefather.', `VerifiedBuild`=14333 WHERE `ID`=27932; -- The Axe of Earthly Sundering
UPDATE `quest_offer_reward` SET `RewardText`='Thanks for the dust, $N.  Here\'s your cash, and...here is a token from associates of mine.  You might find it useful...useful.', `VerifiedBuild`=14333 WHERE `ID`=47; -- Gold Dust Exchange
UPDATE `quest_offer_reward` SET `RewardText`='That was a nice bit of work, $N.$B$BWith our constructs back up and running behind their main lines, it\'s only a matter of time now before we make the big push through and rescue the Stonefather.', `VerifiedBuild`=14333 WHERE `ID`=26762; -- Reactivate the Constructs
UPDATE `quest_offer_reward` SET `RewardText`='That\'s a great start, $N, but we\'re going to need you to fly over into the town and stir up some trouble.', `VerifiedBuild`=14333 WHERE `ID`=26755; -- Keep Them off the Front
UPDATE `quest_offer_reward` SET `RewardText`='Though this wild boar meat is bland, simmer it enough in the right spices and it sure does make for some tasty pie!', `VerifiedBuild`=14333 WHERE `ID`=86; -- Pie for Billy
UPDATE `quest_offer_reward` SET `RewardText`='Yes, murlocs have settled in and around the streams of eastern Elwynn.  We don\'t know why they are here, but they are aggressive and at least semi-intelligent.', `VerifiedBuild`=14333 WHERE `ID`=35; -- Further Concerns
UPDATE `quest_offer_reward` SET `RewardText`='You find around the neck of the corpse a metal medallion inscribed with the words: \"Footman Rolf Hartford.\"', `VerifiedBuild`=14333 WHERE `ID`=45; -- Discover Rolf's Fate
UPDATE `quest_offer_reward` SET `RewardText`='You have confirmed my fears, $N.  The murlocs are a threat we cannot ignore.', `VerifiedBuild`=14333 WHERE `ID`=71; -- Report to Thomas
UPDATE `quest_offer_reward` SET `RewardText`='You have my thanks, $N. You\'ve made all the difference, and the fate of these cowardly stone trogg ambushers is set in stone.$B$BNow we must get about the business of retaking Stonehearth.', `VerifiedBuild`=14333 WHERE `ID`=26499; -- Stonefather's Boon
UPDATE `quest_offer_reward` SET `RewardText`='You lost a what?  Well I didn\'t take no necklace, because I ain\'t no thief!$B$BI might know who did but...<grin>...I\'m too hungry to remember.', `VerifiedBuild`=14333 WHERE `ID`=85; -- Lost Necklace
UPDATE `quest_offer_reward` SET `RewardText`='You\'re here to help with my delivery?  Very good!', `VerifiedBuild`=14333 WHERE `ID`=1097; -- Elmore's Task
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done what few others could have. Defeating Avalanchion was no small feat.$B$BI\'m impressed, $N. Will you help us with our war against the stone troggs so that we can rescue the Stonefather?', `VerifiedBuild`=14333 WHERE `ID`=27935; -- Bring Down the Avalanche
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=37; -- Find the Lost Guards
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=111; -- Speak with Gramma
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=14281; -- Frost Nova
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=14288; -- Safety in Numbers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26484; -- To Stonehearth's Aid
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26500; -- We're Surrounded
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26501; -- Sealing the Way
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26502; -- Thunder Stones
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26537; -- Shatter Them!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26564; -- Fixer Upper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26577; -- Rocky Upheaval
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26578; -- Doomshrooms
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26579; -- Gone Soft
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26580; -- Familiar Intruders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26581; -- A Head Full of Wind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26582; -- Unnatural Causes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26583; -- Wrath of the Fungalmancer
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26584; -- Shaken and Stirred
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26585; -- Corruption Destruction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26591; -- Battlefront Triage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26625; -- Troggzor the Earthinator
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26632; -- Close Escort
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26709; -- The Stone Throne
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26750; -- At the Stonemother's Call
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26752; -- Audience with the Stonemother
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26770; -- Mystic Masters
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26791; -- Sprout No More
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26827; -- Rallying the Earthen Ring
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26828; -- Our Part of the Bargain
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26829; -- The Stone March
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26831; -- The Twilight Flight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26832; -- Therazane's Mercy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26833; -- Word In Stone
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26875; -- Undying Twilight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=26971; -- The Binding
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=27126; -- Rush Delivery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=27748; -- Fortune and Glory
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=27931; -- The Quaking Fields
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=27933; -- Elemental Ore
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=27934; -- One With the Ground
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28271; -- Reduced Productivity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28272; -- Missing Pieces
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28273; -- Friend of a Friend
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28274; -- Two Tents
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28350; -- Master Trapper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28351; -- Unlimited Potential
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28352; -- Camel Tow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28353; -- Jonesy Sent For You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28363; -- Stirred the Hornet's Nest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28367; -- Shroud of the Makers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28402; -- Schnottz So Fast
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28403; -- Bad Datas
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28404; -- I'll Do It By Hand
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28482; -- Sullah's Gift
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28497; -- Fire From the Sky
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28612; -- Harrison Jones and the Temple of Uldum
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28613; -- See You on the Other Side!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28621; -- Put That Baby in the Cradle!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28622; -- Three if by Air
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28633; -- The Coffer of Promise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28789; -- Join the Battle!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28797; -- They Sent Assassins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28813; -- Fear No Evil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14333 WHERE `ID`=28823; -- The Rear is Clear
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=6000, `RewardText`='You smell terrible.  But you found my keys!  Thank you so much.  Now I can get my shredder started and make some money.  Pretty soon I will have enough money to leave Outland.  I don\'t know why you stay; I hate this place.  Wouldn\'t you rather be back in Booty Bay?  $B$BMaybe do some fishing?', `VerifiedBuild`=14480 WHERE `ID`=10629; -- Shizz Work
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `RewardText`='Felt good, didn\'t it? You\'re not one of them anymore, $N. You\'re Scourge. You\'re one of us. Forever... ', `VerifiedBuild`=14480 WHERE `ID`=12746; -- A Special Surprise
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='Well done, $N.  Your actions in the field are instrumental in our battle for Hellfire Peninsula.', `VerifiedBuild`=14480 WHERE `ID`=13410; -- Hellfire Fortifications
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `EmoteDelay3`=1000, `EmoteDelay4`=1000, `VerifiedBuild`=14480 WHERE `ID`=9587; -- Dark Tidings
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=14480 WHERE `ID`=9589; -- The Blood is Life
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=14480 WHERE `ID`=9607; -- Heart of Rage
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=14480 WHERE `ID`=9575; -- Weaken the Ramparts
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=14480 WHERE `ID`=10159; -- Keep Thornfang Hill Clear!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9351; -- Voidwalkers Gone Wild
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9355; -- A Job for an Intelligent Man
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9372; -- Demonic Contamination
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9373; -- Missing Missive
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9418; -- Avruu's Orb
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9420; -- The Finest Down
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9424; -- Makuru's Vengeance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9430; -- Sha'naar Relics
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9543; -- Atonement
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9545; -- The Seer's Relic
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=9563; -- Gaining Mirren's Trust
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10050; -- Unyielding Souls
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10057; -- Looking to the Leadership
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10079; -- When This Mine's a-Rockin'
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10093; -- The Temple of Telhamat
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10099; -- The Mastermind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10255; -- Testing the Antidote
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10399; -- The Heart of Darkness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10403; -- Naladu
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=10630; -- Beneath Thrallmar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12593; -- In Service Of The Lich King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12619; -- The Emblazoned Runeblade
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12636; -- The Eye Of Acherus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12641; -- Death Comes From On High
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12657; -- The Might Of The Scourge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12670; -- The Scarlet Harvest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12678; -- If Chaos Drives, Let Suffering Hold The Reins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12679; -- Tonight We Dine In Havenshire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12680; -- Grand Theft Palomino
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12687; -- Into the Realm of Shadows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12697; -- Gothik the Harvester
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12698; -- The Gift That Keeps On Giving
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12700; -- An Attack Of Opportunity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12701; -- Massacre At Light's Point
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12706; -- Victory At Death's Breach!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12711; -- Abandoned Mail
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12714; -- The Will Of The Lich King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12715; -- The Crypt of Remembrance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12716; -- The Plaguebringer's Request
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12717; -- Noth's Special Brew
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12718; -- More Skulls For Brew
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12719; -- Nowhere To Run And Nowhere To Hide
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12720; -- How To Win Friends And Influence Enemies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12722; -- Lambs To The Slaughter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12723; -- Behind Scarlet Lines
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12724; -- The Path Of The Righteous Crusader
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12725; -- Brothers In Death
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12727; -- Bloody Breakout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12733; -- Death's Challenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12738; -- A Cry For Vengeance!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12751; -- A Sort Of Homecoming
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12754; -- Ambush At The Overlook
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12755; -- A Meeting With Fate
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12756; -- The Scarlet Onslaught Emerges
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12757; -- Scarlet Armies Approach...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12778; -- The Scarlet Apocalypse
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12842; -- Runeforging: Preparation For Battle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12848; -- The Endless Hunger
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12849; -- The Power Of Blood, Frost And Unholy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=12850; -- Report To Scourge Commander Thalanor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=13165; -- Taking Back Acherus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=14480 WHERE `ID`=13166; -- The Battle For The Ebon Hold
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15050 WHERE `ID`=10271; -- Getting Down to Business
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15050 WHERE `ID`=10273; -- Troublesome Distractions
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15050 WHERE `ID`=10274; -- Securing the Celestial Ridge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15050 WHERE `ID`=24506; -- Inside the Frozen Citadel
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15050 WHERE `ID`=10524; -- Thunderlord Clan Artifacts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15050 WHERE `ID`=10526; -- The Thunderspike
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=9920; -- Mo'mor the Breaker
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=9923; -- HELP!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=9954; -- Corki's Ransom
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=10270; -- A Not-So-Modest Proposal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=10272; -- A Promising Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=25465; -- Still With The Zapped Giants
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `RewardText`='It is good to hear of all your moves against the fel orcs, $N.  The apothecaries have spent much time and resources studying the cause of their corruption, and although such information is invaluable... my orc blood burns to strike a severe blow against these betrayers!$B$BListen close, and I will explain my task...', `VerifiedBuild`=15050 WHERE `ID`=10875; -- Report to Nazgrel
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=4000, `VerifiedBuild`=15050 WHERE `ID`=10238; -- How to Serve Goblins
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8635; -- Splitrock the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8636; -- Rumblerock the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8642; -- Silvervein the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8643; -- Highpeak the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8647; -- Bellowrage the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8648; -- Darkcore the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8649; -- Stormbrow the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8651; -- Ironband the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8652; -- Graveborn the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8653; -- Goldwell the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8654; -- Primestone the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8670; -- Runetotem the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8671; -- Ragetotem the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8672; -- Stonespire the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8673; -- Bloodhoof the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8674; -- Winterhoof the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8675; -- Skychaser the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8676; -- Wildmane the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8678; -- Wheathoof the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8679; -- Grimtotem the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8680; -- Windtotem the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8681; -- Thunderhorn the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8682; -- Skyseer the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8683; -- Dawnstrider the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8684; -- Dreamseer the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8685; -- Mistwalker the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8686; -- High Mountain the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8715; -- Bladeleaf the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8716; -- Starglade the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8717; -- Moonwarden the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8718; -- Bladeswift the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8720; -- Skygleam the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8721; -- Starweave the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8723; -- Nightwind the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8724; -- Morningdew the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8725; -- Riversong the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8726; -- Brightspear the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=8866; -- Bronzebeard the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=9924; -- Corki's Gone Missing Again!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=10810; -- Damaged Mask
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=10812; -- Mystery Mask
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=10821; -- You're Fired!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=10838; -- The Demoniac Scryer
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13012; -- Sardis the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13013; -- Beldak the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13014; -- Morthie the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13015; -- Fargal the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13016; -- Northal the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13018; -- Sandrene the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13019; -- Thoim the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13020; -- Stonebeard the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13021; -- Igasho the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13024; -- Wanikaya the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13025; -- Lunaro the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13026; -- Bluewolf the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13027; -- Tauros the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13028; -- Graymane the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13029; -- Pamuya the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13030; -- Whurain the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13031; -- Skywarden the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13032; -- Muraco the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13033; -- Arp the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=13542; -- Against the Wind
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25394; -- More Than Illness
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25396; -- Tears of Stone
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25397; -- The Land, Corrupted
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25407; -- Forces of Nature: Wisps
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25409; -- Forces of Nature: Hippogryphs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25410; -- Forces of Nature: Treants
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25429; -- Zukk'ash Infestation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25431; -- Stinglasher
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25434; -- Taming The Tamers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25436; -- Spiteful Sisters
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25437; -- Ysondre's Call
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25458; -- General Skessesh
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25468; -- Forces of Nature: Faerie Dragons
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=25469; -- Forces of Nature: Mountain Giants
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=26914; -- Corruption
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29734; -- Deepforge the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29735; -- Stonebrand the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29736; -- Darkfeather the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29737; -- Firebeard the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29738; -- Moonlance the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29739; -- Windsong the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29740; -- Evershade the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29741; -- Sekhemi the Elder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=29742; -- Menkhaf the Elder
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15050 WHERE `ID`=10281; -- Formal Introductions
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=400, `VerifiedBuild`=15050 WHERE `ID`=25654; -- Dark Heart
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15050 WHERE `ID`=8868; -- Elune's Blessing
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15050 WHERE `ID`=13518; -- The Last Wave of Survivors
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15050 WHERE `ID`=13543; -- Three Hammers to Break
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15050 WHERE `ID`=13605; -- The Last Refugee
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15050 WHERE `ID`=25448; -- The Northspring Menace
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay1`=2000, `EmoteDelay2`=4000, `VerifiedBuild`=15050 WHERE `ID`=10236; -- Outland Sucks!
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=25450; -- Improved Quality
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=25466; -- Even More Fuel for the Zapping
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15050 WHERE `ID`=25333; -- Might of the Sentinels
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15050 WHERE `ID`=25398; -- Sealing the Dream
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=4, `EmoteDelay1`=500, `EmoteDelay2`=1000, `VerifiedBuild`=15050 WHERE `ID`=9406; -- The Mag'har
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=9918; -- Not On My Watch!
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2, `EmoteDelay2`=2000, `VerifiedBuild`=15050 WHERE `ID`=13558; -- Call Down the Thunder
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=25, `EmoteDelay2`=1000, `VerifiedBuild`=15050 WHERE `ID`=10525; -- Vision Guide
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=30, `VerifiedBuild`=15050 WHERE `ID`=12469; -- Return to Sender
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15050 WHERE `ID`=13547; -- Coaxing the Spirits
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15050 WHERE `ID`=25447; -- Signs of Change
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15050 WHERE `ID`=25449; -- The Mark of Quality
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15050 WHERE `ID`=25486; -- The Grimtotem are Coming
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=10819; -- Felsworn Gas Mask
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15050 WHERE `ID`=10820; -- Deceive thy Enemy
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15050 WHERE `ID`=25426; -- War on the Woodpaw
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15050 WHERE `ID`=26402; -- General Shandris Feathermoon
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=10876; -- The Foot of the Citadel
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25304; -- The Battle of Sardor
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25399; -- Hatecrest Forces
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25400; -- The Gordunni Threat
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25406; -- Gordok Guards
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25427; -- Alpha Strike
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25433; -- Sasquatch Sighting
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25438; -- Ysondre's Farewell
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15050 WHERE `ID`=25463; -- Report to Silvia
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15050 WHERE `ID`=25403; -- Ogre Abduction
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15050 WHERE `ID`=11051; -- Banish More Demons
UPDATE `quest_offer_reward` SET `EmoteDelay2`=4000, `VerifiedBuild`=15050 WHERE `ID`=10136; -- Cruel's Intentions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8645; -- Obsidian the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8646; -- Hammershout the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8650; -- Snowcrown the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8677; -- Darkhorn the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8688; -- Windrun the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8714; -- Moonstrike the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8719; -- Bladesing the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8722; -- Meadowrun the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8867; -- Lunar Fireworks
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8871; -- The Lunar Festival
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8872; -- The Lunar Festival
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8874; -- The Lunar Festival
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=8883; -- Valadar Starsong
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9400; -- The Assassin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9401; -- A Strange Weapon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9405; -- The Warchief's Mandate
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9410; -- A Spirit Guide
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9793; -- The Fate of Tuurem
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=9955; -- Cho'war the Pillager
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10389; -- The Agony and the Darkness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10658; -- More Sunfury Signets
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10659; -- Single Sunfury Signet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10904; -- Harvesting the Fel Ammunition
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10910; -- Death's Door
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10911; -- Fire At Will!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=10912; -- The Hound-Master
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12043; -- Nozzlerust Defense
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12044; -- Stocking Up
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12045; -- Shaved Ice
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12046; -- Soft Packaging
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12047; -- Something That Doesn't Melt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=12049; -- Hard to Swallow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13573; -- Malfurion's Return
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13575; -- The Land Is in Their Blood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13576; -- Mutual Aid
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13577; -- The Last Wildkin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13579; -- Protector of Ameth'Aran
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13580; -- Soothing the Elements
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13581; -- The Blackwood Pledge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13583; -- The Wildkin's Oath
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13584; -- Calming the Earth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13585; -- Sworn to Protect
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13586; -- The Emerald Dream
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13587; -- The Waking Nightmare
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13588; -- The Eye of All Storms
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13902; -- Mounting the Offensive
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=13940; -- Leaving the Dream
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25208; -- Tell Silvia
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25401; -- The Gordunni Orb
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25402; -- Estulan's Examination
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25432; -- It's Not "Ogre" Yet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25475; -- Find OOX-22/FE!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=25481; -- To New Thalanaar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=26574; -- Adella's Covert Camp
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29219; -- Bwemba's Spirit
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29220; -- To Bambala
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29221; -- Serpents and Poison
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29222; -- Spirits Are With Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29223; -- Nesingwary Will Know
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29226; -- Track the Tracker
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29227; -- The Hunter's Revenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29228; -- Follow That Cat
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29230; -- Mauti
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29231; -- How's the Hunter Holding Up?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29232; -- Bury Me With Me Boots...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29233; -- Warn Grom'gol
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29235; -- Defend Grom'gol
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29236; -- To Hardwrench Hideaway
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29237; -- Voodoo Zombies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29238; -- Bad Supplies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29250; -- Making Contact
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29252; -- Booty Bay's Interests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29253; -- A Shiny Reward
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29268; -- Some Good Will Come
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15050 WHERE `ID`=29688; -- Advancing the Campaign

DELETE FROM `quest_offer_reward` WHERE `ID`=24591;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(24591, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve just learned a little something about the inner workings of Horde high command.$B$BWarlord Bloodhilt is in charge of Desolation Hold now. He may have more for you to do in the courtyard below. ', 15354); -- Changing of the Gar'dul

UPDATE `quest_offer_reward` SET `Emote1`=0, `RewardText`='You were sent from on high?  Truly my mission is blessed!  I am trying to save the Bloodmaul from annihilation by the Bladespire clan, and Gruul\'s sons, who are backing them.$B$BI trust that you will be the one to aid our secret society and deliver us into freedom.', `VerifiedBuild`=15354 WHERE `ID`=11057; -- The Trouble Below
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=27789; -- Troggish Troubles
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15354 WHERE `ID`=28115; -- Past Their Prime
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=25, `VerifiedBuild`=15354 WHERE `ID`=28144; -- Thieving Little Monsters!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=274, `VerifiedBuild`=15354 WHERE `ID`=28197; -- Discretion is Key
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=8314; -- Unraveling the Mystery
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11711; -- Coward Delivery... Under 30 Minutes or it's Free
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11720; -- The Invasion of Gammoth
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11892; -- The Assassination of Harold Lane
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11916; -- Hellscream's Champion
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=24555; -- What The Dragons Know
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=24560; -- Tempering The Blade
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=24562; -- Journey To The Sunwell
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=26884; -- Researching the Corruption
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15354 WHERE `ID`=24598; -- The Purification of Quel'Delar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15354 WHERE `ID`=28237; -- A Blight Upon the Land
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `Emote4`=66, `VerifiedBuild`=15354 WHERE `ID`=26882; -- Blackfathom Villainy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=11869; -- Happy as a Clam
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=26543; -- Clammy Hands
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=26556; -- No Dumping Allowed
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=26557; -- A Staggering Effort
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=26572; -- A Golden Opportunity
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=26588; -- A Furious Catch
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=28111; -- Trouble at Azurelode
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15354 WHERE `ID`=28196; -- The Battle for Hillsbrad
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=28156; -- Deep Mine Rescue
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=8304; -- Dearest Natalia
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=21, `VerifiedBuild`=15354 WHERE `ID`=28146; -- Coastal Delicacies!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15354 WHERE `ID`=28636; -- Silence of the Dwarves
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='<Chu\'a\'lor nods his heads at you in satisfaction at your accomplishment.>$B$BYou have a quick mind, $N.  It took us much longer to successfully make use of the relic.$B$BNow that you know how, you can do so as much as you care to.  Just remember that they require an apexis shard to power them.', `VerifiedBuild`=15354 WHERE `ID`=11058; -- An Apexis Relic
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='<Chu\'a\'lor\'s left head begins to speak.>$B$BThese will do fine.$B$BRemember, $N, the value of the shard is not in what it can purchase for you.  It is not even in what it can potentially do for you when properly forged, though there is some debate over that.$B$B<His right head finishes,...>$B$BThe true value is in the journey to attain the shard.', `VerifiedBuild`=15354 WHERE `ID`=11025; -- The Crystals
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='Hey, $g man : girl;, that\'s great.  We hear you\'ve been doing good things.  That\'s cool.  We\'ve got a feeling that you\'re going to make things right for us here in Ogri\'la, and keep us safe, and everything nice and mellow.$B$BHere, take this.  It\'s nothing much, just a care package that we whipped up as a thanks for your effort.$B$BFeel free to look around at our goods.  We have a lot of really choice stuff that you\'re gonna want to get.', `VerifiedBuild`=15354 WHERE `ID`=11091; -- A Special Thank You
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`='Indeed, it must have been a difficult struggle, $c.  I feel greatly relieved now that he will not be breathing down our necks here.$B$BI will send this skull down to Chort for safekeeping.  I\'m beginning to think that with your help, we might just pull this off.', `VerifiedBuild`=15354 WHERE `ID`=10995; -- Grulloc Has Two Skulls
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=7848; -- Attunement to the Core
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=8306; -- Into The Maw of Madness
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=8310; -- Breaking the Code
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=9419; -- Scouring the Desert
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11722; -- Trophies of Gammoth
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11865; -- Unfit for Death
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11868; -- The Culler Cometh
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11870; -- The Abandoned Reach
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11871; -- Not On Our Watch
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11876; -- Help Those That Cannot Help Themselves
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11884; -- Nedar, Lord of Rhinos...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24451; -- An Audience With The Arcanist
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24556; -- A Suitable Disguise
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24557; -- The Silver Covenant's Scheme
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24558; -- Return To Myralion Sunblaze
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24559; -- Reforging The Sword
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24561; -- The Halls Of Reflection
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24799; -- A Victory For The Sunreavers
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=27792; -- All's Fair in Love, War, and Archaeology
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28138; -- Human Infestation
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28199; -- For Science!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28472; -- Words of the High Chief
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28479; -- The Ruins of Kel'Theril
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28634; -- Extinction
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28701; -- Out of Harm's Way
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28782; -- A Bird of Legend
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28841; -- The Arcane Storm Within
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=29445; -- An Intriguing Grimoire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=29457; -- The Enemy's Insignia
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=29509; -- Putting the Crunch in the Frog
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=29510; -- Putting Trash to Good Use
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `Emote3`=16, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `RewardText`='It is over then.  You have freed us from the shackles of our enslavement to the Sons of Gruul.  You have given the Bloodmaul Clan a reprieve from certain extinction.$B$BWords cannot describe the extent of the debt that ALL of the ogres of the Blade\'s Edge Mountains, Bloodmaul and Bladespire alike, owe you, $N.$B$BLook down, even now the ogres gather to pay you tribute.  Let Gruul and his puppet, the old king, Maulgar, cower within their lair.  Go to the ogres below as our new $g king : queen;!', `VerifiedBuild`=15354 WHERE `ID`=11000; -- Into the Soulgrinder
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=500, `VerifiedBuild`=15354 WHERE `ID`=8320; -- Twilight Geolords
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `RewardText`='Patrolling the high road is grave business, but it must be done. These narrow mountain trails are, for the time being, one of our only lifelines into Stonetalon. They must be preserved.$B$BThank you.', `VerifiedBuild`=15354 WHERE `ID`=24504; -- Clear the High Road
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15354 WHERE `ID`=919; -- Timberling Sprouts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15354 WHERE `ID`=10997; -- Even Gronn Have Standards
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15354 WHERE `ID`=28522; -- Winterfall Activity
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15354 WHERE `ID`=24546; -- A Line in the Dirt
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15354 WHERE `ID`=28647; -- The Durnholde Challenge: D-1000
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=11, `VerifiedBuild`=15354 WHERE `ID`=11719; -- A Suitable Test Subject
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=15, `VerifiedBuild`=15354 WHERE `ID`=11866; -- Ears of Our Enemies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=15, `VerifiedBuild`=15354 WHERE `ID`=11867; -- Can't Get Ear-nough...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=273, `VerifiedBuild`=15354 WHERE `ID`=24572; -- Taking Back Taurajo
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `RewardText`='So my sister recognized the old signals? Her hunter\'s eyes are as sharp as ever.$B$B$N, when we first set up this camp we were at the edge of this jungle. Now look at it!$B$BSomething is amiss.', `VerifiedBuild`=15354 WHERE `ID`=24515; -- Signals in the Sky
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15354 WHERE `ID`=8309; -- Glyph Chasing
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15354 WHERE `ID`=11714; -- Vermin Extermination
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15354 WHERE `ID`=28703; -- Step Into My Barrow
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15354 WHERE `ID`=11080; -- The Relic's Emanation
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15354 WHERE `ID`=28460; -- Threat of the Winterfall
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15354 WHERE `ID`=29520; -- Banners, Banners Everywhere!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `VerifiedBuild`=15354 WHERE `ID`=14383; -- The Terrible Tinkers of the Ruined Reaches
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21, `RewardText`='<Calder peers into the sack of extremities and licks his lips with a dry, black tongue.>$B$BOh my. This is exciting.$B$B Aren\'t you excited, $N?', `VerifiedBuild`=15354 WHERE `ID`=24619; -- Parts-is-Parts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21, `VerifiedBuild`=15354 WHERE `ID`=11872; -- The Nefarious Clam Master...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25, `VerifiedBuild`=15354 WHERE `ID`=24684; -- A Weezil in the Henhouse
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `RewardText`='Good, good. We\'ve got to keep Honor\'s Stand isolated.$B$BAlone ... afraid ... $N, if we keep up the pressure, maybe someday they\'ll simply surrender the pass.', `VerifiedBuild`=15354 WHERE `ID`=24519; -- Stalling the Survey
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `RewardText`='You have them? I\'ll take your word for it. Hearing Peake scream like one of his victims is reward enough for me.$B$BNow leave me be, $N. I do not wish to be a burden to my clan.', `VerifiedBuild`=15354 WHERE `ID`=24513; -- Eye for an Eye
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `RewardText`='You\'re covered in hot tar and bug juice! Don\'t worry, friend. It\'ll come off.$B$BSomeday.', `VerifiedBuild`=15354 WHERE `ID`=24654; -- Silithissues
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15354 WHERE `ID`=309; -- Protecting the Shipment
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15354 WHERE `ID`=28230; -- Protocol
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15354 WHERE `ID`=28331; -- Helcular's Rod Giveth...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `RewardText`='<Kilrok pages through the plans you discovered.>$B$BThis explains much, $N. No wonder our foes are so hellbent on taking the southern Barrens. It\'s at the center of their plans for the continent!$B$BBut they didn\'t account for us, did they $c? ', `VerifiedBuild`=15354 WHERE `ID`=24518; -- The Low Road
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `VerifiedBuild`=15354 WHERE `ID`=14385; -- Azsharite Experiment Number One
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=2561; -- Druid of the Claw
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=6608; -- You Too Good.
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=8277; -- Deadly Desert Venom
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=8321; -- Vyral the Vile
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=9826; -- Contact from Dalaran
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=10996; -- Maggoc's Treasure Chest
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=10998; -- Grim(oire) Business
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13479; -- The Great Egg Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13483; -- Spring Gatherers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13503; -- A Tisket, a Tasket, a Noblegarden Basket
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13647; -- Joining the Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13650; -- Keep Your Hands Off The Goods!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13826; -- Nat Pagle, Angler Extreme
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13832; -- Jewel Of The Sewers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=13836; -- Disarmed!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=14370; -- Mysterious Azsharite
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25369; -- Stinglasher
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25378; -- Ysondre's Call
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25629; -- Her Lady's Hand
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25722; -- Sedimentary, My Dear
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25723; -- Thresh Out of Luck
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25725; -- Fenbush Berries
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25726; -- A Dumpy Job
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25733; -- Get Out Of Here, Stalkers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25734; -- Down In Thelgen Rock
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25735; -- Incendicite Ore
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25777; -- Onwards to Menethil
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25800; -- When Life Gives You Crabs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25805; -- Return the Statuette
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25860; -- At All Costs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25951; -- Final Judgment
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25968; -- Desperate Plan
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25969; -- Hostile Waters
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25970; -- Come Prepared
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25971; -- Unfurling Plan
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25972; -- Honor and Privilege
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=25973; -- Welcome News
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26006; -- A Breath of Fresh Air
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26013; -- Assault on the Sanctum
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26135; -- Visions of the Past: Rise from the Deep
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26843; -- A Tiny, Clever Commander
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26844; -- Kobold and Kobolder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26845; -- Who's In Charge Here?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26846; -- A Nasty Exploit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26927; -- Suddenly, Murlocs!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=26932; -- Buzz Off
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27025; -- Thistle While You Work
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27030; -- Foxtails By The Handful
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27031; -- Wing Nut
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27764; -- A Strange Request
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27765; -- First Sample: Wild Eggs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27766; -- Second Sample: Whelps
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27770; -- Lifting the Veil
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27771; -- Third Sample: Implanted Eggs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=27791; -- Dustwind Dig
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28208; -- Winna's Kitten
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28213; -- Hazzard Disposal
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28257; -- The Fall of Tichondrius
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28382; -- Enemy at our Roots
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28383; -- Wisps of the Woods
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28469; -- Winterfall Runners
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28471; -- The Final Piece
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28513; -- Pride of the Highborne
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28629; -- Are We There, Yeti?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28631; -- The Perfect Horns
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28837; -- Altered Beasts
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28838; -- The Owlbeasts' Defense
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28847; -- The Pursuit of Umbranse
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=28848; -- Trailing the Spiritspeaker
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29181; -- Druids of the Talon
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29182; -- Flight of the Storm Crows
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29214; -- The Shadow Wardens
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29215; -- The Hunt Begins
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29246; -- Relieving the Pain
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=29247; -- Treating the Wounds
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `RewardText`='Mog\'dorg sent a message ahead, saying that I should expect you.  I am glad that you came.$B$BWith the Sons of Gruul destroyed, it is only a matter of time - a short amount at that - before the various inhabitants of this mountain terrace, and the one to the north, decide to prey upon our ogre brothers down below.$B$BI trust that you will help us to prevent that, $N.', `VerifiedBuild`=15354 WHERE `ID`=11009; -- Ogre Heaven
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=28656; -- Strange Life Forces
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `RewardText`='So the Alliance is probing the twists and turns of the high road?$B$BEven if they were to map it out, they couldn\'t attack these hills in numbers. This is our land, $N. And they will pay dearly for presuming otherwise.', `VerifiedBuild`=15354 WHERE `ID`=24505; -- Holdout at Hunter's Hill
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11061; -- A Father's Duty
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=11, `VerifiedBuild`=15354 WHERE `ID`=11066; -- Wrangle More Aether Rays!
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=25, `VerifiedBuild`=15354 WHERE `ID`=28856; -- The Sands of Silithus
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=918; -- Timberling Seeds
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=8280; -- Securing the Supply Lines
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=8318; -- Secret Communication
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=9825; -- Restless Activity
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=26883; -- Twilight Falls
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=27774; -- Easily Swayed
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15354 WHERE `ID`=28842; -- Umbranse's Deliverance
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15354 WHERE `ID`=28489; -- Stagwiches
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='Excellent! You\'re my kind of $c, $N.$B$BWith your help, we will throw these invaders back into the sea.', `VerifiedBuild`=15354 WHERE `ID`=24618; -- Claim the Battle Scar
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `RewardText`='Gahk like whip.  Maybe Gahk take whip and beat demons with it!$B$BMe say to $r that $r summon demon chiefs anytime $r have friends and many shards.', `VerifiedBuild`=15354 WHERE `ID`=11079; -- A Fel Whip For Gahk
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11721; -- Gammothra the Tormentor
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=25367; -- Zukk'ash Infestation
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=27775; -- When the Going Gets Tough, Cheat
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=27776; -- It's Goat Time, Baby
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=25, `RewardText`='Woo hoo!  Nice job, $N!  Those rays are going to make excellent mounts!$B$BStick around kid... the Sha\'tari Skyguard can always use a $g man : woman; of your obvious talents!', `VerifiedBuild`=15354 WHERE `ID`=11065; -- Wrangle Some Aether Rays!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15354 WHERE `ID`=8278; -- Noggle's Last Hope
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15354 WHERE `ID`=8281; -- Stepping Up Security
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15354 WHERE `ID`=14371; -- A Gigantic Snack
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15354 WHERE `ID`=25815; -- The Third Fleet
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=20, `VerifiedBuild`=15354 WHERE `ID`=28192; -- No One Here Gets Out Alive
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=274, `RewardText`='Is this from Crawgol? Wonderful! Despite all the turmoil in the world, we can\'t turn our back on the silithid threat. It is important to have people like Crawgol studying our enemy closely and learning its secrets for the fight ahead!$B$B<Tauna opens the book and glances over the first page. Her face falls.>$B$BOh. Well. I suppose it\'s something, at least. ', `VerifiedBuild`=15354 WHERE `ID`=24667; -- Firestone Point
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15354 WHERE `ID`=6607; -- Nat Pagle, Angler Extreme
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28325; -- Green Living
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `VerifiedBuild`=15354 WHERE `ID`=26885; -- Knowledge in the Deeps
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=28324; -- Studies in Lethality
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=273, `VerifiedBuild`=15354 WHERE `ID`=28168; -- Trouble at the Sludge Fields
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=20, `Emote3`=274, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=28495; -- A Fighting Chance
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274, `Emote3`=11, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=28356; -- Preemptive Strike
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274, `VerifiedBuild`=15354 WHERE `ID`=13639; -- Resupplying the Excavation
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274, `VerifiedBuild`=15354 WHERE `ID`=14377; -- Befriending Giants
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=13648; -- WANTED: The Dark Iron Spy
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=13655; -- Explorers' League Document (2 of 6)
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=13656; -- Explorers' League Document (1 of 6)
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=25721; -- Fight the Flood
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=25727; -- Drungeld Glowerglare
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=25736; -- The Floodsurge Core
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=28235; -- Burnside Must Fall
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=28467; -- Mystery Goo
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=28540; -- Doin' De E'ko Magic
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15354 WHERE `ID`=28718; -- Where There's Smoke, There's Delicious Meat
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=15, `VerifiedBuild`=15354 WHERE `ID`=11864; -- A Mission Statement
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15354 WHERE `ID`=11879; -- Kaw the Mammoth Destroyer
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15354 WHERE `ID`=11724; -- Massive Moth Omelet?
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15354 WHERE `ID`=28096; -- Welcome to the Machine
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `RewardText`='Let\'s see, let\'s see.$B$BIt looks like the artillery shells are prepped here, then loaded into the secure magazine...$B$B<Weezil rubs his hands together.>$B$B$N, are you ready to blow some stuff up?', `VerifiedBuild`=15354 WHERE `ID`=24685; -- Dwarf Fortress
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=12117; -- Travel to Moa'ki Harbor
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28635; -- A Haunting in Hillsbrad
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=27772; -- The Venerable Doctor Blam
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=25, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=28620; -- Eastpoint Tower
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=273, `Emote3`=1, `RewardText`='What? He attacked you with a dozen boars? I guess quilboar have their own ideas of what \"single combat\" means.$B$BStill, the Bristleback will be left reeling after the blow you delivered. It will not be long before a new champion rises amongst them to stir up trouble... but at least this buys us some time to get these refugees relocated safely.$B$BThank you, $N. The survivors owe you a great debt.', `VerifiedBuild`=15354 WHERE `ID`=24534; -- Speaking Their Language
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`='Oh dear. It seems the forces at work here are a bit difficult to control...$B$BPlease, don\'t bother Naralex with this. It will only upset him.', `VerifiedBuild`=15354 WHERE `ID`=24566; -- Sowing a Solution
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15354 WHERE `ID`=9175; -- The Lady's Necklace
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15354 WHERE `ID`=11996; -- Your Presence is Required at Agmar's Hammer
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15354 WHERE `ID`=26864; -- The Bearer of Gnoll-edge
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15354 WHERE `ID`=29829; -- Discretion is Key
UPDATE `quest_offer_reward` SET `Emote1`=7, `VerifiedBuild`=15354 WHERE `ID`=26929; -- A Load of Croc
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15354 WHERE `ID`=29272; -- Need... Water... Badly...
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `RewardText`='<Bloodhilt looks at the badges, then allows them to spill from his hands onto the sands below. His lips curl open into a toothy grin.>$B$BNow THIS is what I like to see, $c! What is your name again?$B$BYou will go far here.', `VerifiedBuild`=15354 WHERE `ID`=24551; -- Meet the New Boss
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `RewardText`='From up here I got the perfect view of the havoc you just caused, $N. Our lost brothers reclaimed some of their dignity, and the Alliance dogs were sent scrambling. Sharp work, my friend!$B$BIf the Alliance sleeps comfortably at night, we are not doing our job.$B$BWe will never let up.$B$BWe will never give in.', `VerifiedBuild`=15354 WHERE `ID`=24512; -- Warriors' Redemption
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `RewardText`='Hah! The fool didn\'t destroy these orders.$B$BLet\'s see what we can learn...', `VerifiedBuild`=15354 WHERE `ID`=24634; -- Intelligence Warfare
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=25284; -- Feeding the Fear
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=11, `VerifiedBuild`=15354 WHERE `ID`=28722; -- Yetiphobia
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=15, `Emote3`=5, `Emote4`=1, `RewardText`='<Upon hearing the news, Bloodhilt snorts. His eyes gleam. He tips his head back and bellows a wet, cackling laugher that echoes between the blackened walls of Desolation hold and reverberates throughout the hills beyond.>$B$BSo it is done! The Butcher of Taurajo is felled at last. Cut down in the streets like a dog. Fitting.$B$BYou have done well, $N. You\'ve sowed fear into our enemies, and soon we will reap the harvest!', `VerifiedBuild`=15354 WHERE `ID`=24637; -- The Butcher of Taurajo
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15354 WHERE `ID`=26868; -- Axis of Awful
UPDATE `quest_offer_reward` SET `Emote1`=13, `VerifiedBuild`=15354 WHERE `ID`=11028; -- Countdown to Doom
UPDATE `quest_offer_reward` SET `Emote1`=15, `Emote2`=6, `RewardText`='Very good. Now, should they storm the gates, they will have to do so with infantry.$B$BDo you think they have the stomach for that?', `VerifiedBuild`=15354 WHERE `ID`=24569; -- Siegebreaker
UPDATE `quest_offer_reward` SET `Emote1`=15, `VerifiedBuild`=15354 WHERE `ID`=24608; -- Mangletooth
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=14310; -- Segmentation Fault: Core Dumped
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=4, `Emote3`=6, `Emote4`=5, `VerifiedBuild`=15354 WHERE `ID`=11716; -- The Wondrous Bloodspore
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=28114; -- Glorious Harvest
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15354 WHERE `ID`=192; -- Panther Prowess
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15354 WHERE `ID`=8313; -- Sharing the Knowledge
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15354 WHERE `ID`=28742; -- Shy-Rotam
UPDATE `quest_offer_reward` SET `Emote1`=22, `VerifiedBuild`=15354 WHERE `ID`=28828; -- You Gotta Have Eggs
UPDATE `quest_offer_reward` SET `Emote1`=24, `Emote2`=274, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=28484; -- The Heart of the Matter
UPDATE `quest_offer_reward` SET `Emote1`=24, `VerifiedBuild`=15354 WHERE `ID`=25820; -- A Mother's Worries
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `Emote3`=1, `Emote4`=274, `VerifiedBuild`=15354 WHERE `ID`=28209; -- Freedom for Lydon
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `Emote3`=66, `RewardText`='<Gann looks you up and down.>$B$BWe could use your help, $c. But this is not a skirmish. We fight here to strike a killing blow... or die trying.', `VerifiedBuild`=15354 WHERE `ID`=24632; -- Tauren Vengeance
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24563; -- Thalorien Dawnseeker
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15354 WHERE `ID`=27016; -- The Joy of Boar Hunting
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `RewardText`='<Calder grasps the gigantic heart in both hands, squeezing it and listening to the valves slurp and squish.>$B$B<His pale mask of a face splits open into an enormous, childlike grin.>$B$BIt is so very important to love one\'s work, wouldn\'t you agree, $N?$B$B<Calder chucks the heart over his shoulder into a waist-high pile of entrails.>', `VerifiedBuild`=15354 WHERE `ID`=24620; -- Hearts-is-Hearts
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `RewardText`='<Tomusa snorts as he takes back his hook.>$B$BVengeance feels hollow. Still. I could not allow them to go unpunished.', `VerifiedBuild`=15354 WHERE `ID`=24631; -- Flightmare
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=9415; -- Report to Marshal Bluewall
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24529; -- Bad to Worse
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=28487; -- Humbert's Personal Problems
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`='<Winnoa bows her head.>$B$BThank you.', `VerifiedBuild`=15354 WHERE `ID`=24573; -- Honoring the Dead
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15354 WHERE `ID`=25364; -- Alpha Strike
UPDATE `quest_offer_reward` SET `Emote1`=68, `Emote2`=30, `Emote3`=1, `EmoteDelay2`=3000, `RewardText`='<Kirge listens intently and then falls to one knee.>$B$BAlive! My boy still lives! Praise to the earthmother, I still have a son.$B$B<Kirge composes himself.>$B$B$C, my boy\'s mother didn\'t make it out of Taurajo alive. I will avenge her death, even if it means my son grows up without either of his parents. ', `VerifiedBuild`=15354 WHERE `ID`=24543; -- A Family Divided
UPDATE `quest_offer_reward` SET `Emote1`=71, `VerifiedBuild`=15354 WHERE `ID`=8317; -- Kitchen Assistance
UPDATE `quest_offer_reward` SET `Emote1`=92, `Emote2`=397, `VerifiedBuild`=15354 WHERE `ID`=26928; -- Smells Like A Plan
UPDATE `quest_offer_reward` SET `Emote1`=113, `VerifiedBuild`=15354 WHERE `ID`=8283; -- Wanted - Deathclasp, Terror of the Sands
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `RewardText`='Ah yes... I see a cunning in your eyes that was not present before. Well done, $c.', `VerifiedBuild`=15354 WHERE `ID`=24552; -- Lion's Pride
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `RewardText`='So it is done.$B$BNormally these scavengers are part of the Earthmother\'s cycle of life. But on the heels of the devastation wracked by both the Alliance and the cataclysm, their numbers grow overwhelming. It is good to thin them out.', `VerifiedBuild`=15354 WHERE `ID`=24525; -- Keeping the Dogs at Bay
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24517; -- Put the Fear in Them
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=24542; -- A Curious Bloom
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=4, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=28485; -- Yetimus the Yeti Lord
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=6, `RewardText`='Thank you, $N. But now on to the larger question:$B$BWhere is this overgrowth coming from? And why is it raging out of control?', `VerifiedBuild`=15354 WHERE `ID`=24539; -- When Plants Attack
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=66, `Emote3`=1, `RewardText`='<Onatay looks over the fresh hides, nodding her head slowly.>$B$BYes $N, I can work with these. You work fast!$B$BThese hides will help us hold out for reinforcements longer. Thank you.', `VerifiedBuild`=15354 WHERE `ID`=24514; -- Raptor Scraps
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15354 WHERE `ID`=28342; -- Fel To Pieces
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15354 WHERE `ID`=28386; -- Borrowed Bombs
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15354 WHERE `ID`=28625; -- Chop Chop
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=28332; -- Helcular's Command
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `RewardText`='<Gar\'dul breaks into a sweat.>$B$BLook - ah - let\'s not discuss this here, in front of the men...', `VerifiedBuild`=15354 WHERE `ID`=24577; -- Desolation Hold Inspection
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=5, `Emote3`=479, `Emote4`=14, `VerifiedBuild`=15354 WHERE `ID`=28639; -- Ursius
UPDATE `quest_offer_reward` SET `Emote1`=274, `VerifiedBuild`=15354 WHERE `ID`=11930; -- Across Transborea
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=274, `VerifiedBuild`=15354 WHERE `ID`=28231; -- Do it for Twinkles
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15354 WHERE `ID`=29316; -- Back to Basics
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15354 WHERE `ID`=29321; -- Happy as a Clam Digger
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=25780; -- Assault on Menethil Keep
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=26842; -- Out of Gnoll-where
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=28654; -- The Heart of the Matter
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=28746; -- Penetrating Their Defenses
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29345; -- Pond Predators
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29346; -- The Ring's the Thing
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29354; -- Shiny Baubles
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29358; -- Pining for Nuts
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29362; -- "Magic" Mushrooms
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29363; -- Mulgore Spice Bread
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15354 WHERE `ID`=29543; -- Invading the Citadel
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `RewardText`='Despite how Keller cares to characterize it, I prefer to think of our missions as research-oriented.$B$BBut yes, we do resupply the Skyguard while we\'re there.  That is if we can stay long enough to do so.$B$BYou look like you\'d be willing to keep the ethereals off of our backs.  If you can manage to for long enough, we\'ll sell you surplus items that we create at the crystalforge, so bring your apexis shards and crystals!$B$BWe leave in $4581d.', `VerifiedBuild`=15354 WHERE `ID`=11119; -- Assault on Bash'ir Landing!
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `RewardText`='Welcome ta the Skyguard Outpost!  I built it with me own hands ya know.$B$BYeah, the whole thing!$B$B<The sky commander looks serious.>$B$BSo, ye must be lookin\' ta spoil for a fight if ye\'re here talkin\' ta me.  It was kind of old Chu\'a\'lor ta send ye along.  We can always use fresh meat for the grinder around here.$B$BIf ye don\'t mind, I\'d like ya ta start by having a talk with my sergeant across the way: Vanderlip.  Don\'t mind her tongue, though it be sharper than the greatsword she be carrying.', `VerifiedBuild`=15354 WHERE `ID`=11062; -- The Skyguard Outpost
UPDATE `quest_offer_reward` SET `Emote2`=6, `RewardText`='You\'re a lifesaver, $N.  Our boys are going to be so excited to hear the news!$B$BOK, so one down and one to go.  We did tell you about the other magical flask that they\'re going to need, didn\'t we?', `VerifiedBuild`=15354 WHERE `ID`=11030; -- Our Boy Wants To Be A Skyguard Ranger
UPDATE `quest_offer_reward` SET `Emote2`=6, `VerifiedBuild`=15354 WHERE `ID`=11023; -- Bomb Them Again!
UPDATE `quest_offer_reward` SET `RewardText`='$N! You did it! How will we ever repay you?', `VerifiedBuild`=15354 WHERE `ID`=26836; -- Rescue the Stonefather... and Flint
UPDATE `quest_offer_reward` SET `RewardText`='$N, we have good news and a slight problem....', `VerifiedBuild`=15354 WHERE `ID`=26835; -- A Slight Problem
UPDATE `quest_offer_reward` SET `RewardText`='<Calder holds the brains in an outstretched hand while withdrawing a gore-caked multi-tool from his belt.>$B$BWonderful work! Now the secret here is to leave the reptilian nervous systems intact while removing the higher cognitive functions. We can\'t have our new friend developing a conscience or remembering he\'s Alliance...$B$B<Calder digs and snips at the brain, removing large chunks.>$B$BAnd... we\'re finished! How lovely.', `VerifiedBuild`=15354 WHERE `ID`=24621; -- Smarts-is-Smarts
UPDATE `quest_offer_reward` SET `RewardText`='<Naralex slowly takes the squirming heart from you, visibly disturbed.>$B$BI\'ve been a fool. The one truth I did not want to accept has been staring me in the face this entire time...this foul thing is proof of that.$B$BYou and I have much work to do.', `VerifiedBuild`=15354 WHERE `ID`=24574; -- To Harvest Chaos
UPDATE `quest_offer_reward` SET `RewardText`='Bael\'dun? Destroyed?$B$B<Wincing in pain, Gann twists his head to peer behind him, where plumes of smoke darken the skyline.>$B$B$N, my friend. You have avenged Taurajo and avenged the Tauren people. The invaders will not soon recover from that blow. Thank you.$B$B<Gann closes his eyes, his head tipping forward as his breath gives way to a series of ragged coughs.>', `VerifiedBuild`=15354 WHERE `ID`=24747; -- Sabotage!
UPDATE `quest_offer_reward` SET `RewardText`='I could feel what occured from here, $c. It bristled every hair I have.$B$BI\'m overjoyed to hear you succeeded in pushing those horrors back, and I\'ll be sure to scour the area for any stray deviate creatures.', `VerifiedBuild`=15354 WHERE `ID`=24807; -- Winnoa Pineforest
UPDATE `quest_offer_reward` SET `RewardText`='Our $g hero : heroine; returns!$B$BYou have saved my people, $N. You have earned that which you seek.', `VerifiedBuild`=15354 WHERE `ID`=27937; -- The Hero Returns
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $n. I\'m pleased to see you return intact; the viciousness I\'ve been seeing among these creatures is startling.', `VerifiedBuild`=15354 WHERE `ID`=24565; -- Biological Intervention
UPDATE `quest_offer_reward` SET `RewardText`='The Middle Fragment of the World Pillar!$B$BThank you, $N. I can only imagine what you had to go through to get this to us. I\'ll see to it that it\'s placed within the center of the chamber.', `VerifiedBuild`=15354 WHERE `ID`=27938; -- The Middle Fragment
UPDATE `quest_offer_reward` SET `RewardText`='These are blood shards. They used to be found all over the Barrens.$B$BIt\'s said they were formed from the blood of Agamaggan, the great demigod that the quilboar sprang from. I knew the quilboar prized them, but nobody would think they\'d take the time and care to carve them like this one...$B$BThere may be more to learn here.', `VerifiedBuild`=15354 WHERE `ID`=24606; -- Blood of the Barrens
UPDATE `quest_offer_reward` SET `RewardText`='We\'ve done it! The nightmare\'s connection to this place has been severed. The rest of the land is safe from this intrusion now, and in time, the abberations here will be subsumed by the balance of nature.$B$BI cannot thank you enough, $n. By helping to restore order here, you\'ve let me make amends for my foolish actions.', `VerifiedBuild`=15354 WHERE `ID`=24601; -- The Nightmare Scar
UPDATE `quest_offer_reward` SET `RewardText`='Well, well, well, I guess you had it in you after all.  Good work.  Maybe Old Man Keller was wrong about you after all.$B$B<Sky Sergeant Vanderlip smirks.>', `VerifiedBuild`=15354 WHERE `ID`=11010; -- Bombing Run
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=8228; -- Could I get a Fishing Flier?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=8282; -- Noggle's Lost Satchel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=8284; -- The Twilight Mystery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=8307; -- Desert Recipe
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9824; -- Arcane Disturbances
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9829; -- Khadgar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9962; -- The Ring of Blood: Brokentoe
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9967; -- The Ring of Blood: The Blue Brothers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9970; -- The Ring of Blood: Rokdar the Sundered Lord
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9972; -- The Ring of Blood: Skra'gath
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9973; -- The Ring of Blood: The Warmaul Champion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=9977; -- The Ring of Blood: The Final Challenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=10729; -- Path of the Violet Mage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11610; -- Leading the Ancestors Home
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11717; -- Pollen from the Source
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11878; -- Khu'nok Will Know
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11949; -- Not Without a Fight!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11950; -- Muahit's Wisdom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11961; -- Spirits Watch Over Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=11968; -- The Tides Turn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=12779; -- An End To All Things...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=12800; -- The Lich King's Command
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=12801; -- The Light of Dawn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=13090; -- Northern Cooking
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=13571; -- Fletcher's Lost and Found
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=13830; -- The Ghostfish
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=14308; -- When Science Attacks
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24431; -- Waterlogged Recipe
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24570; -- Adder Subtraction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24571; -- Lashvine Seeds
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24603; -- Don't Stop Bereavin'
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24604; -- Concern for Mankrik
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24815; -- Choose Your Path
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24819; -- A Change of Heart
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=24824; -- The Disturbed Earth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25118; -- Looking for Lurkers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25366; -- The Battle Plans
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25374; -- Sasquatch Sighting
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25375; -- Taming The Tamers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25379; -- Taerar's Fall
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25383; -- Ysondre's Farewell
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25801; -- Claws from the Deep
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25802; -- Reclaiming Goods
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25803; -- The Search Continues
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25804; -- Search More Hovels
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=25896; -- Devout Assembly
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26194; -- Defending the Rift
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26312; -- Crumbling Defenses
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26313; -- Core of Our Troubles
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26314; -- On Even Ground
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26315; -- Imposing Confrontation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26326; -- The Very Earth Beneath Our Feet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26328; -- Rocky Relations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26375; -- Loose Stones
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26376; -- Hatred Runs Deep
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26377; -- Unsolid Ground
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26426; -- Violent Gale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26436; -- Entrenched
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26437; -- Making Things Crystal Clear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26438; -- Intervention
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26439; -- Putting the Pieces Together
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26440; -- Clingy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26441; -- So Big, So Round...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26507; -- Petrified Delicacies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26575; -- Rock Bottom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26576; -- Steady Hand
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26656; -- Don't. Stop. Moving.
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26657; -- Hard Falls
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26658; -- Fragile Values
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26659; -- Resonating Blow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26860; -- Thelsamar Blood Sausages
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26863; -- Filthy Paws
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26869; -- Depth of the Depths
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26871; -- A Rock Amongst Many
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26881; -- In Search of Aluwyn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=26961; -- Gathering Idols
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27693; -- The Warden's Game
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27709; -- The Sentinel's Game
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27756; -- The Foreman
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27758; -- The Carpenter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27769; -- Rhea Revealed
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27781; -- The Machination
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27785; -- The Admiral
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27790; -- The Defias Kingpin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27793; -- Ancient Protectors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27796; -- The Warden's Pawn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27797; -- The Sentinel's Pawn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=27952; -- The Explorers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28189; -- Do the Right Thing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28190; -- The Tainted Ooze
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28206; -- Little Girl Lost
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28207; -- A Slimy Situation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28214; -- Cleanup at Bloodvenom Post
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28217; -- Wanted: The Demon Hunter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28218; -- A Destiny of Flame and Sorrow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28219; -- Buzzers for Baby
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28220; -- Seeking Soil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28221; -- These Roots Were Made For Stompin'
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28222; -- Singin' in the Sun
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28224; -- The Last Protector
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28228; -- Rejoining the Forest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28229; -- Nature and Nurture
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28256; -- The Skull of Gul'dan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28261; -- Deceivers In Our Midst
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28264; -- Navarax's Gambit
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28305; -- The Fate of Bloodvenom Post
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28337; -- The Shredders of Irontree
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28341; -- Collecting Corruption
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28358; -- Hunting the Damned
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28359; -- The Core of Kroshius
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28381; -- The Denmother
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28384; -- Into the Clearing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28385; -- Oil and Irony
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28464; -- Falling to Corruption
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28470; -- High Chief Winterfall
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28518; -- Legacy of the High Elves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28519; -- Pain of the Blood Elves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28530; -- Scalding Signs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28534; -- Descendants of the Highborne
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28535; -- Descendants of the High Elves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28536; -- The Curse of Zin-Malor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28537; -- In Pursuit of Shades
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28609; -- Hammer Time
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28610; -- Rubble Trouble
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28618; -- Boulder Delivery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28624; -- Kilram's Boast
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28626; -- Tree Delivery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28627; -- Seril's Boast
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28628; -- Ice Delivery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28630; -- Echo Three
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28632; -- Fresh From The Hills
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28637; -- A Taste for Bear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28638; -- The Owls Have It
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28640; -- Fresh Frostsabers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28641; -- Pride of the Dinner Table
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28643; -- The Durnholde Challenge: Zephyrus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28644; -- The Durnholde Challenge: Teracula
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28645; -- The Durnholde Challenge: Bloodvenom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28646; -- The Durnholde Challenge: Infernus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28674; -- Starfall Village
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28676; -- Exterminators at Work
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28706; -- Spray it Forward
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28707; -- Spray it Again
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28710; -- Spray it One More Time
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28719; -- A Little Gamy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28745; -- Screechy Keen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28753; -- Doing it the Hard Way
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28829; -- Razor Beak and Antlers Pointy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28830; -- Chips off the Old Block
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28831; -- Damn You, Frostilicus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28839; -- Magic Prehistoric
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28840; -- Winterwater
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=28869; -- Pebble
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=29245; -- The Mysterious Seed
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=29249; -- Planting Season
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15354 WHERE `ID`=29254; -- Little Lasher

DELETE FROM `quest_offer_reward` WHERE `ID` IN (14001 /*Goblin Escape Pods*/, 14113 /*Life of the Party*/, 14013 /*Charge*/, 14109 /*The New You*/, 26712 /*Off to the Bank*/, 28870 /*Return to the Lost City*/, 27187 /*Do the World a Favor*/, 26125 /*Secure Seabrush*/, 27717 /*Piece of the Past*/, 25441 /*Vortex*/, 25439 /*Vengeful Heart*/, 25359 /*Toshe's Vengeance*/, 25456 /*Back in One Piece*/, 25217 /*Totem Modification*/, 25360 /*Crabby Patrons*/, 25218 /*Undersea Inflation*/, 25216 /*The Great Sambino*/, 25219 /*Don't be Shellfish*/, 25220 /*Slippery Threat*/, 25215 /*A Distracting Scent*/, 25222 /*Silver Tide Hollow*/, 25221 /*Rundown*/, 25164 /*Backed Into a Corner*/, 25334 /*The Looming Threat*/, 25471 /*Across the Great Divide*/, 26008 /*Decompression*/, 26040 /*What? What? In My Gut...?*/, 27708 /*The Warden's Time*/, 25884 /*Come Hell or High Water*/, 25883 /*How Disarming*/, 25887 /*Wake of Destruction*/, 25419 /*Lady La-La's Medallion*/, 26007 /*Debriefing*/, 25941 /*Rest For the Weary*/, 25936 /*Pay It Forward*/, 25929 /*Sea Legs*/, 25924 /*Call of Duty*/, 27718 /*Warchief's Command: Vashj'ir!*/, 28805 /*The Eye of the Storm*/, 28790 /*A Personal Summons*/, 28293 /*That's No Pyramid!*/, 27059 /*The Wrong Sequence*/, 27041 /*Decryption Made Easy*/, 27008 /*Fly Over*/, 27005 /*The Twilight Plot*/, 28866 /*Into the Stonecore*/, 27953 /*The Reliquary*/, 27102 /*Maziel's Ascendancy*/, 27101 /*Maziel's Revelation*/, 27100 /*Twilight Research*/, 27722 /*Warchief's Command: Deepholm!*/, 27442 /*The War Has Many Fronts*/, 27940 /*Dirty Birds*/, 25275 /*Report to the Labor Captain*/, 25243 /*She Loves Me, She Loves Me NOT!*/, 25203 /*What Kind of Name is Chip, Anyway?*/, 25073 /*Sen'jin Village*/, 24814 /*An Ancient Enemy*/, 24812 /*No More Mercy*/, 24813 /*Territorial Fetish*/, 25035 /*Breaking the Line*/, 24626 /*Young and Vicious*/, 24625 /*Consort of the Sea Witch*/, 24624 /*Mercy for the Lost*/, 24623 /*Saving the Young*/, 24622 /*A Troll's Truest Companion*/, 24640 /*The Arts of a Warrior*/, 25612 /*Return from the Firelands*/, 25354 /*Sweeping the Shelf*/, 25617 /*Into the Maw!*/, 25355 /*Lightning in a Bottle*/, 25277 /*Cleaning House*/, 25279 /*The Shrine Reclaimed*/, 25272 /*Lycanthoth the Corruptor*/, 25270 /*Howling Mad*/, 25269 /*The Voice of Lo'Gosh*/, 27721 /*Warchief's Command: Mount Hyjal!*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(14001, 4, 6, 0, 0, 0, 2000, 0, 0, 'Oh, thank heavens that you survived, $N! I thought for sure that you\'d drowned when I saw you go over the side!$B$B<Sassy\'s eyes fill up with tears as she hugs you.>$B$BLook at all of these folks you saved!', 15595), -- Goblin Escape Pods
(14113, 4, 6, 0, 0, 0, 0, 0, 0, 'Very nicely done, $g sir : ma\'am;. The party appears to have been a smashing success!$B$BEr... what\'s that?', 15595), -- Life of the Party
(14013, 33, 0, 0, 0, 0, 0, 0, 0, 'Warrior-Matic NX-01 is programmed to serve.$B$BReturn anytime you seek more training. This unit will teach you what it knows.', 15595), -- Charge
(14109, 4, 0, 0, 0, 0, 0, 0, 0, 'Oh, you are going to look so fine, but not as gorgeous as me! You\'re going to replace the Trade Prince any day now at the rate you\'re going!$B$BI can\'t wait to not have to work anymore! You\'re going to buy me everything that I want, right babe?$B$BLet me have all that stuff and I\'ll help you get into it right before the party.', 15595), -- The New You
(26712, 25, 5, 0, 0, 0, 0, 0, 0, 'Oh, it\'s you, sir! Sorry, I didn\'t recognize you at first with all of these commoners milling about.$B$BYou people cool your heels! $N is here!$B$BHere are your macaroons, $g sir : ma\'am;. Come back anytime if you need more.', 15595), -- Off to the Bank
(28870, 0, 0, 0, 0, 0, 0, 0, 0, 'Hail, $N.  Nadun spoke highly of you.$B$BAre you here to aid us?', 15595), -- Return to the Lost City
(27187, 0, 0, 0, 0, 0, 0, 0, 0, 'The world is a better place because of your deeds here today.', 15595), -- Do the World a Favor
(26125, 273, 396, 0, 0, 0, 0, 0, 0, 'You did well, $N.  We need to be especially wary of Alliance attacks right now.  The Verne\'s got plenty of firepower out at sea, but in the back of this cave, she\'s far too vulnerable.', 15595), -- Secure Seabrush
(27717, 1, 0, 0, 0, 0, 0, 0, 0, 'Brilliant! I can\'t have expected much more with the tools I gave you.$B$BI should be able to fill in the blanks and get this all written out shortly. There\'s no knowing if we will make it out of this place, but if it comes down to it, I will find a way to float this to the surface in hopes that it will one day be found.$B$BThank you again, $n. You\'re not bad.', 15595), -- Piece of the Past
(25441, 1, 0, 0, 0, 0, 0, 0, 0, 'Too often, we are mistaken for druidic types. Perhaps that\'s true for some shaman, but do not let yourself be plagued by the ignorant belief that we are always peaceful.$B$BNothing about what I do is harmonious. I command the elements to my will. There is nothing offered in return. I would have it no other way.', 15595), -- Vortex
(25439, 1, 0, 0, 0, 0, 0, 0, 0, 'Good to have a real warrior at my side. Too often, my shaman brethren can\'t seem to stomach the work.', 15595), -- Vengeful Heart
(25359, 1, 0, 0, 0, 0, 0, 0, 0, 'I remember you. You were there when they attacked us back in the cave.$B$BGood to have you with me, $c. Ready for a little vengeance?', 15595), -- Toshe's Vengeance
(25456, 1, 0, 0, 0, 0, 0, 0, 0, 'Sam\'s in one piece then? And his poor assistant Felice? Good to hear.$B$BI hope that one day he\'ll learn to respect the elements as more than just a tool.', 15595), -- Back in One Piece
(25217, 1, 0, 0, 0, 0, 0, 0, 0, 'Another sample. Brilliant! The rocky riches of the sea shall soon be mine!', 15595), -- Totem Modification
(25360, 1, 0, 0, 0, 0, 0, 0, 0, 'Does everything down here only come in jumbo size? Oooh! That\'s a thought. Maybe there are some hunky sea goblins around here somewhere.$B$BThanks, by the way.', 15595), -- Crabby Patrons
(25218, 1, 0, 0, 0, 0, 0, 0, 0, 'Ya know, I should have given you a weight belt so that you wouldn\'t just float away, air balloon and all. Lucky for me you came down here with armor and all! Hah!', 15595), -- Undersea Inflation
(25216, 1, 0, 0, 0, 0, 0, 0, 0, 'Another fan of the Great Sambino! Come all this way for an autograph perhaps? I\'m far too busy to be signing anything... move along now.', 15595), -- The Great Sambino
(25219, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you. Seriously. If I would have had to endure another shipwreckee laughing at me, I swear I would have gored someone.$B$BI\'ll let you know if I come up with anything.', 15595), -- Don't be Shellfish
(25220, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $c. There are still much bigger predators we\'ll have to keep an eye out for, but this will at least give us a bit of peace of mind around the cave.', 15595), -- Slippery Threat
(25215, 1, 0, 0, 0, 0, 0, 0, 0, 'It shouldn\'t take long to cleanse the water. Thank you for your help.', 15595), -- A Distracting Scent
(25222, 1, 0, 0, 0, 0, 0, 0, 0, 'A friendly face! Welcome!$B$BVery kind of you to come check on us. We\'re fine. A naga scouting force did find us, but I\'m pretty sure none escaped. We should be safe for now.', 15595), -- Silver Tide Hollow
(25221, 1, 0, 0, 0, 0, 0, 0, 0, 'Swift work. Very impressive.$B$BThat Fathom-Lord got away... I don\'t see him anywhere. He\'s most certainly the key to finding our captured friends.$B$BI will hunt him down. He cannot stay hidden for long.', 15595), -- Rundown
(25164, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'m glad you were here, mon.$B$BToshe be lookin\' like he wants to chase dem down. You should go help\'em.', 15595), -- Backed Into a Corner
(25334, 1, 0, 0, 0, 0, 0, 0, 0, 'We\'d all suspected da naga, but I knew nothin\' of the Twilight Cult bein\' beneath the waves. Somehow dey are corruptin\' and pervertin\' the elements, makin\' demselves into dese horrors.$B$BWe goin\' ta have to be fightin\' both of dese threats to stand a chance of bringin\' peace ta Vashj\'ir. We don\'t have da men ta do that yet.$B$BCome, $c, we got much ta do.', 15595), -- The Looming Threat
(25471, 1, 0, 0, 0, 0, 0, 0, 0, 'Ello, mon! You look a bit more capable then most of dem coming through here.$B$BCome rest a bit. Make yaself at home.', 15595), -- Across the Great Divide
(26008, 396, 0, 0, 0, 0, 0, 0, 0, 'Let us hope for the safety of those released prisoners.$b$bIn return for your noble efforts, please accept this gift.', 15595), -- Decompression
(26040, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes, yes. This is the stuff.$b$bMaybe I can wean off of it and avoid the side-effect.$b$bThank you, $n.', 15595), -- What? What? In My Gut...?
(27708, 0, 0, 0, 0, 0, 0, 0, 0, 'It is good that this operation has been undone.$b$bSoon, I must move on...', 15595), -- The Warden's Time
(25884, 396, 0, 0, 0, 0, 0, 0, 0, 'The waters surrounding the Holding Pens are red with the blood of the naga.$b$bRendel would be proud!', 15595), -- Come Hell or High Water
(25883, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'re confident that your assault on the naga armaments has made an impact on their effectiveness.', 15595), -- How Disarming
(25887, 0, 0, 0, 0, 0, 0, 0, 0, 'It is as it should be.$b$bNow the way is clear to deal these naga a crippling blow.', 15595), -- Wake of Destruction
(25419, 396, 0, 0, 0, 0, 0, 0, 0, 'This treasure was obviously crafted by the local water-goblins for a female they regarded highly.', 15595), -- Lady La-La's Medallion
(26007, 0, 0, 0, 0, 0, 0, 0, 0, 'Well, it\'s not encouraging, but it\'s something...', 15595), -- Debriefing
(25941, 396, 0, 0, 0, 0, 0, 0, 0, 'I hear you, $r.$b$bI understand the urgency, but these men are in no condition to fight.', 15595), -- Rest For the Weary
(25936, 396, 0, 0, 0, 0, 0, 0, 0, 'While you were away, I was able to revive some of the fallen warriors.$b$bWe\'ll need every hand if we are to survive here.', 15595), -- Pay It Forward
(25929, 396, 0, 0, 0, 0, 0, 0, 0, 'Here you are, $c. With this you should find maneuvering in the sea to be nearly effortless. $b$bNow we must get to work. There is much to be done in little time.', 15595), -- Sea Legs
(25924, 396, 0, 0, 0, 0, 0, 0, 0, 'Not exactly the battle you had anticipated, I\'ll wager. But a battle nonetheless, as you shall soon see....', 15595), -- Call of Duty
(27718, 66, 0, 0, 0, 0, 0, 0, 0, 'Lok\'tar, $g brother:sister;! You have arrived just in time.', 15595), -- Warchief's Command: Vashj'ir!
(28805, 6, 0, 0, 0, 0, 0, 0, 0, 'Now that your eyes have seen the truth, where will you choose to serve?', 15595), -- The Eye of the Storm
(28790, 396, 0, 0, 0, 0, 0, 0, 0, 'May your sense of honor and duty serve Azeroth well, $c.', 15595), -- A Personal Summons
(28293, 6, 0, 0, 0, 0, 0, 0, 0, 'Uldum? What about Uldum? Speak quickly!', 15595), -- That's No Pyramid!
(27059, 4, 0, 0, 0, 0, 0, 0, 0, 'You did it! Excellent work, $g my boy : young lady;. You found out what the Twilight\'s Hammer were up to and you stopped them dead in their tracks!$B$B<Examiner Rowe pats you on the back with his bony hand.>$B$BNow I\'m certain that I have something around here for you.$B$B<He begins rummaging around for your reward.>', 15595), -- The Wrong Sequence
(27041, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah ha! So, that\'s it! They\'re planning on invading Uldum.$B$BWhat\'s worse is that the pyramid inside the Maker\'s Rise at Uldum can be reconfigured to become a weapon. A weapon that is capable of destroying all life on Azeroth!', 15595), -- Decryption Made Easy
(27008, 1, 0, 0, 0, 0, 0, 0, 0, 'A waygate?! They unearthed a Titan waygate.$B$BThis is very interesting and potentially very bad.', 15595), -- Fly Over
(27005, 5, 0, 0, 0, 1000, 0, 0, 0, '<The examiner takes a look at the plans that you hand to him.>$B$BThis is just gibberish!$B$BWhat does this even say? What language is that?', 15595), -- The Twilight Plot
(28866, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s about time they sent someone to help.$B$BMillhouse Manastorm?  It sounds like we\'re both after the same person.', 15595), -- Into the Stonecore
(27953, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, it\'s about time someone came to speak with us on matters most urgent.', 15595), -- The Reliquary
(27102, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve disposed of an enemy before he could grow more powerful.  By eliminating Maziel you\'ve also ensured that his powers will not be used against the Earthen Ring.', 15595), -- Maziel's Ascendancy
(27101, 0, 0, 0, 0, 0, 0, 0, 0, 'Maziel\'s journal appears to be undamaged by the mercury. ', 15595), -- Maziel's Revelation
(27100, 0, 0, 0, 0, 0, 0, 0, 0, 'The notes deal with High Cultist Maziel\'s research on the elemental properties of quicksilver.$B$BHis obsession with the subject borders on the insane.', 15595), -- Twilight Research
(27722, 1, 0, 0, 0, 0, 0, 0, 0, 'Our world is in danger, $N! We need the help of great heroes, like you, to save it!', 15595), -- Warchief's Command: Deepholm!
(27442, 0, 0, 0, 0, 0, 0, 0, 0, 'Your aid is most timely, $N.', 15595), -- The War Has Many Fronts
(27940, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve made the Cradle of the Ancients a somewhat less despicable place to travel through.', 15595), -- Dirty Birds
(25275, 5, 25, 1, 0, 0, 0, 0, 0, '$N? The $N?!$B$B<The labor captain eyes you up and down.>$B$BThe rumors are already flying about you. I don\'t know if I should be thankful or frightened that you\'re here. At least we don\'t have any volcanoes in Azshara!$B$BHonestly, I can\'t believe you\'re showing your face here... Trade Prince Gallywix has setup shop atop the mountain!', 15595), -- Report to the Labor Captain
(25243, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'m sure she deserved it, $N. She should never have betrayed you like that.$B$BIt gives me the shivers to think that she might have kissed that monster, the Trade Prince!', 15595), -- She Loves Me, She Loves Me NOT!
(25203, 1, 0, 0, 0, 0, 0, 0, 0, 'There\'s no two ways about it... he got exactly what he deserved.', 15595), -- What Kind of Name is Chip, Anyway?
(25073, 1, 0, 0, 0, 0, 0, 0, 0, 'Welcome, young $r.$B$BYa come highly recommended, mon. It\'s nice ta finally be meetin\' ya in person.', 15595), -- Sen'jin Village
(24814, 1, 0, 0, 0, 0, 0, 0, 0, 'Tha power dat burst forth when tha Sea Witch died was immense. I can use dis power ta enact a vision of places far away.$B$BObserve, youngblood. I want ya ta be here when I make contact wit\' Thrall, perhaps it will be grantin\' ya insight as well.', 15595), -- An Ancient Enemy
(24812, 1, 0, 0, 0, 0, 0, 0, 0, 'Well fought, young $r.', 15595), -- No More Mercy
(24813, 1, 0, 0, 0, 0, 0, 0, 0, 'Dat should keep dem at bay.', 15595), -- Territorial Fetish
(25035, 1, 0, 0, 0, 0, 0, 0, 0, 'Good to have ya, $G brotha:sista;.$B$BVol\'jin makes us all proud in dese moments. It feels good ta be tacklin\' threats head on.', 15595), -- Breaking the Line
(24626, 0, 0, 0, 0, 0, 0, 0, 0, 'Swiftclaw! Kijara was tellin\' me about him and he sounded like he\'d be a handful. I don\'t mind da challenge - it\'s da spirited ones like dat that be makin\' da bravest and truest companions when real times of need be comin\'.$B$BTank ya, hon. Ya\'ve been very helpful.', 15595), -- Young and Vicious
(24625, 1, 273, 0, 0, 0, 60, 0, 0, 'Well done, $n! Dis naga has set us back quite some time, but nothin\' will be holdin\' us down foreva.$B$BIt\'s good ta be havin\' ya wit us, $n. Ya have a fierce heart within ya.', 15595), -- Consort of the Sea Witch
(24624, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $c.$B$BIt will be takin\' brave and determined people like you ta drive da Darkspear up again. I hope dere are more people even half as dedicated to come.', 15595), -- Mercy for the Lost
(24623, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank ya so much! They can be vicious when provoked, but most of da time dey don\'t know betta.', 15595), -- Saving the Young
(24622, 3, 0, 0, 0, 0, 0, 0, 0, 'Nice ta see new faces \'round here, mon. It\'s easy ta get ta feelin\' isolated since we left Orgrimmar.', 15595), -- A Troll's Truest Companion
(24640, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 15595), -- The Arts of a Warrior
(25612, 1, 5, 0, 0, 0, 0, 0, 0, 'They\'re moving supplies to Hyjal straight from the elemental planes? Devious.$B$BYou\'ve made Lo\'Gosh proud by sealing that flamegate, $N, but there may be more portals to seal. You should check with the other shrines!', 15595), -- Return from the Firelands
(25354, 1, 66, 0, 0, 0, 0, 0, 0, 'Impressive, $N. Very impressive.$B$BYou embody all of the strength of the wolf ancient, and possess the wisdom to use your powers well. I salute you.', 15595), -- Sweeping the Shelf
(25617, 2, 1, 274, 0, 0, 0, 0, 0, 'Ah, you are the champion Lo\'Gosh promised! Your eyes don\'t deceive you: you have entered the Firelands, an elemental plane of molten stone and fire. We\'ve got our work cut out for us here.$B$BPut aside your differences with the Alliance, there\'s plenty of danger to go around.$B$BAnd take this: the Fang of Lo\'Gosh will allow you to channel the ancient\'s power here within the Firelands. Use it well!', 15595), -- Into the Maw!
(25355, 0, 0, 0, 0, 0, 0, 0, 0, 'So, it is true! You indeed carry lightning in your hands.$B$BYou are the chosen one, $N. You will be my champion, and carry my vengeance to realms where I cannot tread...', 15595), -- Lightning in a Bottle
(25277, 4, 1, 0, 0, 0, 0, 0, 0, 'Hah! So you really sent some heads rolling, did you?$B$BIt was said during the War of the Ancients that Lo\'Gosh fought demons for ten days solid. Hopefully you weren\'t fighting that long...', 15595), -- Cleaning House
(25279, 4, 1, 5, 0, 0, 0, 0, 0, '$N, it was incredible! For a fleeting moment I saw Lo\'Gosh through the trees - a creature of both fury and light. My cage collapsed and the vandals melted like wax under the kiss of his claws, their screams and howls echoing through the valley... Was that your work?', 15595), -- The Shrine Reclaimed
(25272, 0, 0, 0, 0, 0, 0, 0, 0, 'You were brave to face down Lycanthoth, $N. Like myself, he was a primal force of nature... but his origins were from a darker place.$B$BThose who birthed that beast reached deep into the blackness, channeling powers never intended for this world.$B$BCome, $c. Climb onto my back, and let us show these beasts the true face of ferocity!', 15595), -- Lycanthoth the Corruptor
(25270, 1, 273, 0, 0, 0, 0, 0, 0, '<Takrik examines the incense.>$B$BDisgusting. This is like the incense we burn when we wish to commune with the spirits... but it\'s... befouled.', 15595), -- Howling Mad
(25269, 15, 1, 0, 0, 0, 0, 0, 0, 'Lok\'tar, $c! Don\'t worry about this cage - these animals will come to fear me before long.$B$BMy first priority is to clear this filth away from my beloved shrine.', 15595), -- The Voice of Lo'Gosh
(27721, 5, 0, 0, 0, 0, 0, 0, 0, 'We knew the Horde would send help and not a moment too soon!', 15595); -- Warchief's Command: Mount Hyjal!

UPDATE `quest_offer_reward` SET `Emote1`=0, `Emote2`=0, `RewardText`='Felendren\'s head... you are to be commended, $N.  You\'ve succeeded where others, like Felendren, have utterly failed.  Perhaps you are truly ready to be a contributing member of blood elf society.$B$BYour success here means that you are capable of surviving the greater threats that lurk in Eversong... and believe me, there are plenty to face.', `VerifiedBuild`=15595 WHERE `ID`=8335; -- Felendren the Banished
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11073; -- Terokk's Downfall
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11074; -- Tokens of the Descendants
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11085; -- Escape from Skettis
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11377; -- Revenge is Tasty
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11379; -- Super Hot Stew
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11380; -- Manalicious
UPDATE `quest_offer_reward` SET `Emote1`=0, `VerifiedBuild`=15595 WHERE `ID`=11381; -- Soup for the Soul
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12650; -- Plundering Their Own
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=9762; -- The Unwritten Prophecy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=11333; -- Into the World of Spirits
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=12034; -- Victory Nears...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=29311; -- The Rest is History
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=2, `VerifiedBuild`=15595 WHERE `ID`=11983; -- Blood Oath of the Horde
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15595 WHERE `ID`=9453; -- Find Acteon!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=15595 WHERE `ID`=12200; -- Emerald Dragon Tears
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=15, `VerifiedBuild`=15595 WHERE `ID`=11244; -- Rescuing the Rescuers
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=25, `VerifiedBuild`=15595 WHERE `ID`=27147; -- Kirtonos the Herald
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=66, `VerifiedBuild`=15595 WHERE `ID`=12500; -- Return To Angrathar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=66, `VerifiedBuild`=15595 WHERE `ID`=13157; -- The Crusaders' Pinnacle
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=274, `VerifiedBuild`=15595 WHERE `ID`=11228; -- Hell Has Frozen Over...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=60, `EmoteDelay3`=60, `VerifiedBuild`=15595 WHERE `ID`=24429; -- A Most Puzzling Circumstance
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=60, `EmoteDelay3`=60, `VerifiedBuild`=15595 WHERE `ID`=24511; -- Echoes of Tortured Souls
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=3098; -- Glyphic Scroll
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=3120; -- Verdant Sigil
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9452; -- Red Snapper - Very Tasty!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9506; -- A Small Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9512; -- Cookie's Jumbo Gumbo
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9515; -- Warlord Sriss'tiz
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9666; -- Declaration of Power
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9668; -- Report to Exarch Admetius
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9986; -- Stymying the Arakkoa
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9992; -- Olemba Seeds
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9993; -- Olemba Seed Oil
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9998; -- Unruly Neighbors
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10002; -- The Firewing Liaison
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10007; -- Thinning the Ranks
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10012; -- Fel Orc Plans
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10016; -- Timber Worg Tails
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10028; -- Vessels of Power
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10066; -- Oh, the Tangled Webs They Weave
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10067; -- Fouled Water Spirits
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10176; -- Ar'kelos the Guardian
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10256; -- Finding the Keymaster
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11055; -- The Booterang: A Cure For The Common Worthless Peon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11278; -- Return to Valgarde
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11290; -- Dragonflayer Battle Plans
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11344; -- Anguish of Nifflevar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11474; -- Problems on the High Bluff
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12039; -- Black Blood of Yogg-Saron
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12089; -- Wanted: Magister Keldonus
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12096; -- Strengthen the Ancients
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12132; -- The Power to Destroy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12197; -- We Have the Power
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13045; -- Into The Wild Green Yonder
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13105; -- Once More Unto The Breach, Hero
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13122; -- The Scourgestone
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13125; -- The Air Stands Still
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13139; -- Into The Frozen Heart Of Northrend
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=14102; -- Mistcaller Yngvar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=24476; -- Tempering The Blade
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=25933; -- Help for the Quarry
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26214; -- Hot On the Trail: Murlocs
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=27146; -- Doctor Theolen Krastinov, the Butcher
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=27342; -- In Time, All Will Be Revealed
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=27438; -- The Great Escape
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=9313; -- Travel to Azure Watch
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=29273; -- How Hot
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=26220; -- Everything Is Better with Bacon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=26226; -- Crawfish Creole
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=26227; -- Careful, This Fruit Bites Back
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=26233; -- Stealing From Our Own
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=26235; -- Even Thieves Get Hungry
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=9759; -- Ending Their World
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=11448; -- The Explorers' League Outpost
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=12069; -- Return of the High Chief
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=12218; -- Spread the Good Word
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=26899; -- The Enemy of My Enemy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `Emote4`=274, `VerifiedBuild`=15595 WHERE `ID`=12066; -- The Focus on the Beach
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=9395; -- Saltheril's Haven
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15595 WHERE `ID`=12635; -- Relics of the Snow Leopard Goddess
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=15, `VerifiedBuild`=15595 WHERE `ID`=9544; -- The Prophecy of Akida
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=15, `VerifiedBuild`=15595 WHERE `ID`=12063; -- Strength of Icemist
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25, `Emote4`=6, `VerifiedBuild`=15595 WHERE `ID`=27099; -- No Escape
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15595 WHERE `ID`=11975; -- Now, When I Grow Up...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=66, `VerifiedBuild`=15595 WHERE `ID`=12903; -- That's What Friends Are For...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=69, `VerifiedBuild`=15595 WHERE `ID`=12064; -- Chains of the Anub'ar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=274, `Emote4`=5, `VerifiedBuild`=15595 WHERE `ID`=27056; -- Belmont's Report
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay1`=60, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=24802; -- Wrath of the Lich King
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=12820; -- A Delicate Touch
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=13418; -- Preparations for War
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=25956; -- Upon the Scene of Battle
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9311; -- Blood Elf Spy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9994; -- What Are These Things?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9996; -- Attack on Firewing Point
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10033; -- Wanted: Bonelashers Dead!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10266; -- Request for Assistance
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10310; -- Sabotage the Warp-Gate!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10444; -- Report to the Allerian Post
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12005; -- Prevent the Accord
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=25995; -- Overseer Idra'kess
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=29134; -- A Wrinkle in Time
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=29563; -- Lost in Action
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=29570; -- Rescuing the Expedition
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=313; -- Forced to Watch from Afar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=433; -- The Public Servant
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=3091; -- Simple Note
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=8336; -- A Fistful of Slivers
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=8346; -- Thirst Unending
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=8564; -- Priest Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9530; -- I've Got a Plant
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9579; -- Galaen's Fate
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9602; -- Deliver Them From Evil...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9648; -- Mac'Aree Mushroom Menagerie
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9667; -- Saving Princess Stillpine
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9676; -- Paladin Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9696; -- Translations...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9698; -- Audience with the Prophet
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9699; -- Truth or Fiction
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9711; -- Matis the Cruel
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9746; -- Limits of Physical Exhaustion
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9760; -- Vindicator's Rest
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9779; -- Intercepting the Message
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10063; -- Explorers' League, Is That Something for Gnomes?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10209; -- Summoner Kanthin's Prize
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10223; -- Down With Daellis
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10297; -- The Opening of the Dark Portal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10320; -- Destroy Naberius!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11003; -- The Fall of Magtheridon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11015; -- Netherwing Crystals
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11076; -- Picking Up The Pieces...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11255; -- Prisoners of Wyrmskull
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11265; -- Of Keys and Cages
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11269; -- Down to the Wire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11271; -- Hasty Preparations
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11281; -- Mimicking Nature's Call
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11284; -- The Yeti Next Door
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11296; -- Rivenwood Captives
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11298; -- What's in That Brew?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11300; -- Stunning Defeat at the Ring
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11301; -- Brains! Brains! Brains!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11302; -- The Enigmatic Frost Nymphs
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11311; -- Suppressing the Elements
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11312; -- The Frozen Glade
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11314; -- The Fallen Sisters
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11315; -- Wild Vines
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11329; -- I'll Try Anything!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11350; -- The Book of Runes
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11351; -- Mastering the Runes
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11352; -- The Rune of Command
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11365; -- March of the Giants
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11367; -- Demolishing Megalith
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11394; -- And You Thought Murlocs Smelled Bad!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11410; -- The One That Got Away
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11418; -- We Call Him Steelfeather
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11433; -- Sleeping Giants
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11475; -- Tools to Get the Job Done
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11477; -- Out of My Element?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11573; -- Orfus of Kamagua
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11877; -- Sunfury Attack Plans
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12026; -- The Damaged Journal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12054; -- Deciphering the Journal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12056; -- Marked for Death: High Cultist Zangus
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12057; -- The Flesh-Bound Tome
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12058; -- The Runic Prophecies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12073; -- Pounding the Iron
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12100; -- Containing the Rot
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12101; -- The Good Doctor...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12102; -- In Search of the Ruby Lilac
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12104; -- Return to Soar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12125; -- In Service of Blood
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12126; -- In Service of the Unholy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12127; -- In Service of Frost
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12140; -- All Hail Roanauk!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12196; -- From the Ground Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12198; -- ... Or Maybe We Don't
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12199; -- Bringing Down the Iron Thane
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12201; -- The Overseer's Shadow
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12202; -- Cultivating an Image
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12203; -- Loken's Orders
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12221; -- The Forsaken Blight
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12256; -- The Flamebinders' Secrets
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12257; -- A Show of Strength
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12259; -- The Thane of Voldrune
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12289; -- Kick 'Em While They're Down
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12433; -- Seeking Solvent
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12504; -- Argent Crusade, We Are Leaving!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12598; -- Throwing Down
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12609; -- Stocking the Shelves
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12629; -- You Can Run, But You Can't Hide
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12648; -- Dressing Down
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12673; -- It Rolls Downhill
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12740; -- Parachutes for the Argent Crusade
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12884; -- The Ebon Watch
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12913; -- Speak Orcish, Man!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12917; -- Speaking with the Wind's Voice
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12930; -- Rare Earth
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12957; -- Slaves of the Stormforged
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12965; -- The Gifts of Loken
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12979; -- Armor of Darkness
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12980; -- The Armor's Secrets
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12988; -- Destroy the Forges!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12991; -- Hit Them Where it Hurts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12993; -- A Colossal Threat
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12998; -- The Heart of the Storm
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13008; -- Scourge Tactics
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13037; -- Memories of Stormhoof
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13038; -- Distortions in Time
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13048; -- Where Time Went Wrong
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13049; -- The Hero's Arms
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13058; -- Changing the Wind's Course
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13110; -- The Restless Dead
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13118; -- The Purging Of Scourgeholme
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13130; -- The Stone That Started A Revolution
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13285; -- Forging the Keystone
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13426; -- Xarantaur, the Witness
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13641; -- The Seer's Crystal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13654; -- There's Something About the Squire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13663; -- The Black Knight's Orders
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13664; -- The Black Knight's Fall
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13674; -- A Worthy Weapon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13678; -- Up To The Challenge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13680; -- The Aspirant's Challenge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13696; -- A Valiant Of Silvermoon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13722; -- The Valiant's Charge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13740; -- A Champion Rises
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13769; -- A Worthy Weapon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13772; -- The Grand Melee
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13784; -- A Worthy Weapon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13787; -- The Grand Melee
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13809; -- Threat From Above
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13811; -- Among the Champions
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13829; -- Mastery Of Melee
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13838; -- Mastery Of The Shield-Breaker
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13839; -- Mastery Of The Charge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13857; -- At The Enemy's Gates
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13859; -- At The Enemy's Gates
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13862; -- Battle Before The Citadel
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13913; -- They Took Our Gnomes
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13926; -- Little Orphan Roo Of The Oracles
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13929; -- The Biggest Tree Ever!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13933; -- The Bronze Dragonshrine
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13937; -- A Trip To The Wonderworks
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13950; -- Playmates!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13956; -- Meeting a Great One
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13959; -- Back To The Orphanage
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14016; -- The Black Knight's Curse
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14017; -- The Black Knight's Fate
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14092; -- Breakfast Of Champions
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14101; -- Drottinn Hrothgar
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14104; -- Ornolf The Scarred
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14105; -- Deathspeaker Kharos
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14107; -- The Fate Of The Fallen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14140; -- Stop The Aggressors
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14141; -- Gormok Wants His Snobolds
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14142; -- You've Really Done It This Time, Kul
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14145; -- What Do You Feed a Yeti, Anyway?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=14438; -- Sharing the Land
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24461; -- Reforging The Sword
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24480; -- The Halls Of Reflection
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24962; -- Trail-Worn Scroll
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24964; -- The Thrill of the Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24965; -- Magic Training
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24973; -- Night Web's Hollow
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25006; -- The Grasp Weakens
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25012; -- Take to the Skies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25195; -- That's the End of That Raptor
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25236; -- Thunder Down Under
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25616; -- Hellscream's Legacy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25642; -- Don't Look Them in the Eyes
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25662; -- Free Our Sisters
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25667; -- Culling the Wendigos
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25668; -- Pilfered Supplies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25728; -- Mr. P's Wild Ride
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25768; -- Bombs Away: Mirkfallon Post!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25792; -- Pushing Forward
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25808; -- Is This Thing On?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25821; -- A Special Kind of Job
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25834; -- Death by Proxy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25839; -- The Ultrasafe Personnel Launcher
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25840; -- Eliminate the Resistance
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25841; -- Strike From Above
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25847; -- Grimtotem Supremacy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25905; -- Rams on the Lam
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25913; -- Putting Them to Rest
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25914; -- Back to the Depths!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25925; -- Thal'darah's Vengeance
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25932; -- It's Raid Night Every Night
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25937; -- Priceless Treasures
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25978; -- Entombed in Ice
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25979; -- Dealing with the Surge
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25986; -- Trouble at the Lake
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26232; -- Lou's Parting Thoughts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26241; -- Westfall Stew
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26270; -- You Have Our Thanks
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26271; -- Feeding the Hungry and the Hopeless
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26297; -- The Dawning of a New Day
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26371; -- The Legend of Captain Grayson
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26380; -- Bound for Kharanos
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26600; -- A Giant's Feast
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26605; -- Grubby Little Paws
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26888; -- Nightmare of the Deeps
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26948; -- Moonfire
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26966; -- The Light's Power
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27015; -- Consecrated Note
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27020; -- The First Lesson
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27023; -- The Way of the Sunwalkers
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27345; -- The F.C.D.
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27405; -- Fall Back!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27406; -- A Man Named Godfrey
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27961; -- Out of Place
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27962; -- A Lumbering Relic
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28126; -- Dousing the Flames of Protection
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28741; -- Ascendant Lord Obsidius
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28827; -- To the Depths
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29161; -- Those Bears Up There
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29176; -- The Fallen Chieftain
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29190; -- Let's Go Fly a Kite
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29191; -- You Scream, I Scream...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29331; -- Elemental Bonds: The Vow
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29443; -- A Curious Crystal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29444; -- An Exotic Egg
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29446; -- A Wondrous Weapon
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29451; -- The Master Strategist
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29464; -- Tools of Divination
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29568; -- A Necessary Evil
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29605; -- Brother Against Brother
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=29608; -- Allies in Dalaran
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11264; -- Necro Overlord Mezhen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=1000, `RewardText`='The Grimtotem...$B$B<Mull scowls.>$B$BI\'d hoped to see the end of my days before Tauren attacked other Tauren senselessly on the very plains of Mulgore.  But be proud, $N.  You have done a great thing for the land, and for our people.', `VerifiedBuild`=15595 WHERE `ID`=24440; -- Winterhoof Cleansing
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9856; -- Windroc Mastery
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10031; -- Helping the Lost Find Their Way
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12554; -- Malas the Corrupter
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=486; -- Ursal the Mauler
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=13624; -- A Squad of Your Own
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=24994; -- Doom Weed
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26237; -- Times are Tough
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26870; -- Cleansing the Caverns
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=28853; -- Kill the Courier
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=29177; -- Vigilance on Wings
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9294; -- Healing the Lake
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=25607; -- Ze Gnomecorder
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15595 WHERE `ID`=12931; -- Fighting Back
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15595 WHERE `ID`=13007; -- The Iron Colossus
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15595 WHERE `ID`=25741; -- Preparations for the Future
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4, `VerifiedBuild`=15595 WHERE `ID`=27142; -- The Lich, Ras Frostwhisper
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10515; -- A Lesson Learned
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12136; -- The Translated Tome
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=25997; -- Dark Iron Scheming
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=21, `Emote4`=21, `VerifiedBuild`=15595 WHERE `ID`=26989; -- The Gilneas Liberation Front
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=25, `VerifiedBuild`=15595 WHERE `ID`=432; -- Those Blasted Troggs!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=12685; -- You Reap What You Sow
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=14014; -- Get Our Stuff Back!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9312; -- The Emitter
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `EmoteDelay2`=3000, `VerifiedBuild`=15595 WHERE `ID`=11307; -- Field Test
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `RewardText`='I can\'t believe it! It was the gnome all along... I should have known!', `VerifiedBuild`=15595 WHERE `ID`=9531; -- Tree's Company
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=6610; -- Clamlette Surprise
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=9473; -- An Alternative Alternative
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=10346; -- Return to the Abyssal Shelf
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=12053; -- The Might of the Horde
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=13034; -- The Witness and the Hero
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=25650; -- Orders from High Command
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=26324; -- Where Is My Warfleet?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=26391; -- Extinguishing Hope
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=26549; -- Madness
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=27726; -- Hero's Call: Mount Hyjal!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=28056; -- Rise, Obsidion
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=12496; -- Audience With The Dragon Queen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=1, `EmoteDelay3`=2000, `VerifiedBuild`=15595 WHERE `ID`=12124; -- Informing the Queen
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9700; -- I Shoot Magic Into the Darkness
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=12205; -- Wanted: The Scarlet Onslaught
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `EmoteDelay2`=120, `VerifiedBuild`=15595 WHERE `ID`=12818; -- Clean Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9409; -- Urgent Delivery!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9727; -- Now That We're Still Friends...
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12708; -- Enchanted Tiki Warriors
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=11343; -- The Echo of Ymiron
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12095; -- To Dragon's Fall
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12209; -- Materiel Plunder
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12637; -- Near Miss
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=25205; -- The Wolf and The Kodo
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=26293; -- Machines of War
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=26296; -- Evidence Collection
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=26539; -- Stalled Negotiations
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=27963; -- A New Master... But Who?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=28653; -- Shadow Priest Sarvis
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12214; -- Fresh Remounts
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=14031; -- Capturing the Unknown
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=11155; -- Shoveltusk Soup Again?
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=24489; -- Trolling for Information
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=26604; -- Protecting Her Royal Highness Poobah
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=26840; -- Return to the Highlands
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=18, `VerifiedBuild`=15595 WHERE `ID`=26087; -- "Glow-Juice"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21, `VerifiedBuild`=15595 WHERE `ID`=25260; -- Fizzled
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21, `VerifiedBuild`=15595 WHERE `ID`=27976; -- Curse These Fat Fingers
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21, `VerifiedBuild`=15595 WHERE `ID`=27977; -- Recon Essentials
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25, `VerifiedBuild`=15595 WHERE `ID`=27181; -- Excising the Taint
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=6324; -- Return to Morris
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `VerifiedBuild`=15595 WHERE `ID`=13602; -- Naga of the Strand
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `VerifiedBuild`=15595 WHERE `ID`=28028; -- Siege!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66, `VerifiedBuild`=15595 WHERE `ID`=29128; -- The Protectors of Hyjal
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=71, `VerifiedBuild`=15595 WHERE `ID`=25823; -- The Unrelenting Horde
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=14303; -- Back to Aggra
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15595 WHERE `ID`=10624; -- A Haunted History
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15595 WHERE `ID`=25879; -- The Lumbering Oaf Problem
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=273, `VerifiedBuild`=15595 WHERE `ID`=26786; -- Securing the Beach Head
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=14234; -- The Enemy of My Enemy
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=11257; -- Gruesome, But Necessary
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=11999; -- Rifle the Bodies
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=25793; -- The Deep Reaches
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=28854; -- Closing a Dark Chapter
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=397, `VerifiedBuild`=15595 WHERE `ID`=25844; -- Sating the Savage Beast
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=2, `VerifiedBuild`=15595 WHERE `ID`=25992; -- Hopelessly Gearless
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=200, `VerifiedBuild`=15595 WHERE `ID`=2499; -- Oakenscowl
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11286; -- The Artifacts of Steel Gate
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11399; -- Bring Down Those Shields
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=13921; -- He Who Would Be Forgiven
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=24954; -- Children of a Turtle God
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=25266; -- Warchief's Emissary
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ah, a new bundle of hides.  I will get to work on these immediately!$B$BThank you, $gbrother:sister;.  You have done me a great service.  Here are some coins to pay for your time and travel costs.', `VerifiedBuild`=15595 WHERE `ID`=6362; -- Ride to Thunder Bluff
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Ah, it\'s here!  I have waited for this rare earth for quite some time.  I hope it\'s still fresh...$B$BThank you for bringing it to me, $N.  You are a $r who is generous with $ghis:her; time.', `VerifiedBuild`=15595 WHERE `ID`=997; -- Denalan's Earth
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya attacks - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=15595 WHERE `ID`=24777; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='These keys are held by the most ancient members of the blue dragonflight. Only they are entrusted with them by their master, Malygos.$B$BThis is the break that we\'ve been waiting for to strike at the Aspect of Magic!$B$B<The queen of dragons studies you for a brief moment.>$B$BYou are not able to use the key as-is to access the Focusing Iris, but I can imbue you with a portion of my power; enough to enable you to use it to open the iris a fraction.$B$BIt will be enough to draw Malygos\'s ire!', `VerifiedBuild`=15595 WHERE `ID`=13372; -- The Key to the Focusing Iris
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='These keys are held by the most ancient members of the blue dragonflight. Only they are entrusted with them by their master, Malygos.$B$BThis is the break that we\'ve been waiting for to strike at the Aspect of Magic!$B$B<The queen of dragons studies you for a brief moment.>$B$BYou are not able to use the key as-is to access the Focusing Iris, but I can imbue you with a portion of my power; enough to enable you to use it to open the iris a fraction.$B$BIt will be enough to draw Malygos\'s ire!', `VerifiedBuild`=15595 WHERE `ID`=13375; -- The Heroic Key to the Focusing Iris
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=182; -- The Troll Menace
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=218; -- Ice and Fire
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=412; -- Operation Recombobulation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=488; -- Zenn's Bidding
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=489; -- Seek Redemption!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=922; -- Rellian Greenspyre
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=929; -- Teldrassil: The Refusal of the Aspects
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=933; -- Teldrassil: The Coming Dawn
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=935; -- The Waters of Teldrassil
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=937; -- The Enchanted Glade
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=2159; -- Dolanaar Delivery
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=2280; -- The Platinum Discs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6321; -- Supplying Brill
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6323; -- Ride to the Undercity
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6341; -- To Darnassus
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6342; -- An Unexpected Gift
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6343; -- Return to Nyoma
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6344; -- Reminders of Home
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6361; -- A Bundle of Hides
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6387; -- Honor Students
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6388; -- Gryth Thurden
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6391; -- Ride to Ironforge
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=6392; -- Return to Gremlock
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=7383; -- Teldrassil: The Burden of the Kaldorei
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=8486; -- Arcane Instability
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=8887; -- Captain Kelisendra's Lost Rutters
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9130; -- Goods from Silvermoon City
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9135; -- Return to Sathiel
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9280; -- Replenishing the Healing Crystals
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9293; -- What Must Be Done...
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9303; -- Inoculation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9305; -- Spare Parts
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9314; -- Word from Azure Watch
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9339; -- A Thief's Reward
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9365; -- A Thief's Reward
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9454; -- The Great Moongraze Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9456; -- Nightstalker Clean Up, Isle 2...
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9514; -- Rune Covered Tablet
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9548; -- Pilfered Equipment
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9557; -- Deciphering the Book
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9567; -- Know Thine Enemy
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9569; -- Containing the Threat
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9574; -- Victims of Corruption
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9576; -- Cruelfin's Necklace
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9580; -- The Bear Necessities
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9581; -- Learning from the Crystals
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9584; -- The Second Sample
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9585; -- The Final Sample
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9594; -- Signs of the Legion
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9603; -- Beds, Bandages, and Beyond
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9604; -- On the Wings of a Hippogryph
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9605; -- Hippogryph Master Stephanos
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9606; -- Return to Caregiver Chellan
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9624; -- A Favorite Treat
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9628; -- Salvaging the Data
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9632; -- Newfound Allies
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9634; -- Alien Predators
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9641; -- Irradiated Crystal Shards
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9642; -- More Irradiated Crystal Shards
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9643; -- Constrictor Vines
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9646; -- WANTED: Deathclaw
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9647; -- Culling the Flutterers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9674; -- The Bloodcursed Naga
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9789; -- Clefthoof Mastery
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9799; -- Botanical Legwork
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9850; -- Clefthoof Mastery
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9855; -- Windroc Mastery
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=9913; -- The Consortium Needs You!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10069; -- Ways of the Light
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10072; -- Learning the Word
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10201; -- And Now, the Moment of Truth
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10311; -- Drijya Needs Your Help
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10324; -- The Great Moongraze Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=10428; -- The Missing Fisherman
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11167; -- The New Plague
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11168; -- Spiking the Mix
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11176; -- See to the Operations
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11233; -- Landing the Killing Blow
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11234; -- Report to Anselm
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11256; -- Skorn Must Fall!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11258; -- Burn Skorn, Burn!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11259; -- Towers of Certain Doom
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11261; -- The Conqueror of Skorn!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11263; -- Dealing With Gjalerbron
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11270; -- War is Hell
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11275; -- Making the Horn
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11285; -- Baleheim Must Burn!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11303; -- The Ambush
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11366; -- The Lodestone
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11397; -- And You Thought Murlocs Smelled Bad!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11423; -- The Enemy's Legacy
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=11668; -- Shrimpin' Ain't Easy
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12144; -- Pest Control
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12145; -- Canyon Chase
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12147; -- Disturbing Implications
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12242; -- Vordrassil's Seeds
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12247; -- Children of Ursoc
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12250; -- Vordrassil's Seeds
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12260; -- The Perfect Dissemblance
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12412; -- My Enemy's Friend
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12415; -- The Horse Hollerer
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12448; -- Heated Battle
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12449; -- Return to the Earth
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12450; -- Through Fields of Flame
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12481; -- Adding Injury to Insult
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12508; -- Mopping Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12510; -- Precious Elemental Fluids
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12553; -- Skimmer Spinnerets
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12582; -- Frenzyheart Champion
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12597; -- Something for the Pain
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12599; -- Creature Comforts
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12610; -- Clipping Their Wings
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12627; -- Breaking Through Jin'Alai
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12630; -- Kickin' Nass and Takin' Manes
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12640; -- Sealing the Rifts
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12652; -- Feedin' Da Goolz
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12767; -- Speak with your Ambassador
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12827; -- Reclaimed Rations
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12828; -- Ample Inspiration
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12829; -- Moving In
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12830; -- Ore Repossession
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12832; -- Bitter Departure
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12851; -- Going Bearback
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12882; -- Ancient Relics
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12920; -- Catching up with Brann
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12926; -- Pieces of the Puzzle
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12927; -- Data Mining
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12964; -- The Dark Ore
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=12984; -- Valduran the Stormborn
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13000; -- Emergency Measures
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13060; -- When All Else Fails
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13073; -- The Keeper's Favor
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13074; -- Hope Within the Emerald Nightmare
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13076; -- Time Yet Remains
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13077; -- The Touch of an Aspect
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13078; -- Dahlia's Tears
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13080; -- Hope Yet Remains
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13083; -- Light Within the Darkness
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13112; -- Infused Mushroom Meatloaf
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13113; -- Convention at the Legerdemain
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13114; -- Sewer Stew
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13549; -- Tails Up
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13594; -- Don't Forget the Horde
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13642; -- Bathed in Light
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13731; -- The Valiant's Challenge
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13922; -- In the Hands of the Perverse
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13928; -- Recover the Fallen
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13945; -- Resident Danger
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=13946; -- Nature's Reprisal
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=14039; -- Home of the Kaldorei
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=14242; -- Precious Cargo
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=14473; -- It's Our Problem Now
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=23733; -- Rites of the Earthmother
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24215; -- Rite of the Winds
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24486; -- Make Hay While the Sun Shines
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24487; -- Whitebeard Needs Ye
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24492; -- Pack Your Bags
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24507; -- The Path to the Citadel
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24530; -- Oh, A Hunter's Life For Me
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24586; -- Razorscale Must Die!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24639; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24641; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24713; -- Frostmourne
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24779; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24816; -- Who's Top of the Food Chain Now?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24856; -- Invasion Imminent!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24861; -- Last Rites, First Rites
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24924; -- Oomlot Village
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24945; -- Three Little Pygmies
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24946; -- Rockin' Powder
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24958; -- Volcanoth!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24975; -- Fields of Grief
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24976; -- Variety is the Spice of Death
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24979; -- A Scarlet Letter
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24980; -- The Scarlet Palisade
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24981; -- A Thorn in our Side
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24983; -- Forsaken Duties
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24988; -- The Chill of Death
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24990; -- Darkhound Pounding
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24991; -- Garren's Haunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24996; -- Holland's Experiment
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=24997; -- Graverobbers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25009; -- At War With The Scarlet Crusade
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25010; -- A Deadly New Ally
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25011; -- To Bigger and Better Things
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25046; -- A Daughter's Embrace
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25089; -- Beyond the Graves
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25099; -- Borrow Bastia
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25111; -- Scavengers Scavenged
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25122; -- Morale Boost
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25167; -- Breaking the Chain
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25169; -- The War of Northwatch Aggression
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25171; -- Riding On
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25176; -- Exploiting the Situation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25178; -- Shipwreck Searching
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25179; -- Loss Reduction
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25190; -- Raggaran's Rage
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25192; -- Raggaran's Fury
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25193; -- Lost But Not Forgotten
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25194; -- Unbidden Visitors
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25196; -- The Dranosh'ar Blockade
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25200; -- Shredder Shutdown
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25202; -- The Fastest Way to His Heart
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25213; -- The Slave Pits
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25232; -- The Burning Blade
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25244; -- What Kind of Name is Candy, Anyway?
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25257; -- Ghislania
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25258; -- Griswold Hanniston
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25259; -- Gaur Icehorn
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25281; -- Pay It Forward
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25371; -- The Abyssal Ride
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25440; -- Fathom-Lord Zin'jatar
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25442; -- A Pearl of Wisdom
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25592; -- Deep Attraction
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25593; -- Shelled Salvation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25594; -- Crafty Crabs
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25595; -- Something Edible
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25613; -- Do Yourself a Favor
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25619; -- Reoccupation
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25620; -- The Revered Lady
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25637; -- To the Fathom-Lord's Call
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25640; -- Bombs Away: Windshear Mine!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25649; -- Minx'll Fix It
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25658; -- Built to Last
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25673; -- Just Ask Alice
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25724; -- Frostmane Aggression
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25766; -- Arcane Legacy
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25769; -- Fallowmere Beckons
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25837; -- A Proper Peace Offerin'
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25858; -- By Her Lady's Word
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25859; -- No Trespass Forgiven
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25861; -- Setting An Example
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25862; -- Stolen Property
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25863; -- Chosen Burden
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25882; -- A Hand at the Ranch
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25890; -- Nespirah
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25907; -- Slave Labor
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25952; -- Caught Off-Guard
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25953; -- Swift Approach
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25954; -- An Occupation of Time
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25955; -- A Better Vantage
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25958; -- Looking Forward
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25959; -- Clear Goals
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25960; -- Not Entirely Unprepared
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25962; -- Properly Inspired
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25963; -- Swift Action
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25964; -- Fallen But Not Forgotten
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25967; -- Losing Ground
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25982; -- Those Aren't Masks
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=25989; -- Capture the Crab
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26012; -- Trouble at Wyrmrest
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26057; -- The Wavespeaker
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26071; -- Clearing the Defiled
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26072; -- Into the Totem
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26089; -- Die Fishman Die
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26096; -- Scalding Shrooms
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26111; -- ... It Will Come
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26130; -- Unplug L'ghorek
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26133; -- Fiends from the Netherworld
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26191; -- The Culmination of Our Efforts
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26221; -- Full Circle
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26393; -- A Swift Message
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26394; -- Continue to Stormwind
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26477; -- Search the Bole
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26599; -- The Captain's Chest
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26602; -- A Dish Best Served Huge
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26610; -- Bloodsail Treachery
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26612; -- Details of the Attack
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26617; -- An Old Sea Dog
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26624; -- Getting In With the Bloodsail
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26710; -- Lost In The Deeps
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26801; -- Scourge on our Perimeter
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26802; -- The Damned
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26826; -- Dask "The Flask" Gobfizzle
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26887; -- Filling Our Pockets
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26916; -- Mastering the Arcane
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=26917; -- The Hunter's Path
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27024; -- Partners in Crime
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27029; -- Cure the Scourge
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27097; -- Rise, Forsaken
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27108; -- Lethtendris's Web
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27139; -- Hobart Needs You
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27192; -- The Great Fras Siabi
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27863; -- The Crucible of Carnage: The Bloodeye Bruiser!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27865; -- The Crucible of Carnage: The Wayward Wildhammer!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27866; -- The Crucible of Carnage: Calder's Creation!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27867; -- The Crucible of Carnage: The Earl of Evisceration!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27868; -- The Crucible of Carnage: The Twilight Terror!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27980; -- The Spiders Have to Go
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=27986; -- In the Hall of the Mountain-Lord
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28044; -- Touch the Untouchable
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28155; -- Lord Banehollow
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28390; -- Glop, Son of Glop
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28492; -- Hero's Call: Ashenvale!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28517; -- The Howling Oak
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28543; -- Hero's Call: Felwood!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28544; -- Hero's Call: Winterspring!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28557; -- Warchief's Command: Uldum!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28559; -- Hero's Call: Bloodmyst Isle!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28583; -- Krazzworks
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28590; -- Reprisal
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28591; -- Off The Wall
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28593; -- Of Utmost Importance
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28594; -- Highbank, Crybank
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28702; -- Hero's Call: The Cape of Stranglethorn!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28708; -- Hero's Call: Outland!
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28714; -- Fel Moss Corruption
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28723; -- Priestess of the Moon
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28725; -- The Woodland Protector
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28726; -- Webwood Corruption
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28728; -- Signs of Things to Come
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28729; -- Teldrassil: Crown of Azeroth
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28730; -- Precious Waters
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28731; -- Teldrassil: Passing Awareness
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28760; -- Vengeance for Orsis
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=28779; -- A Long Way from Home
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29122; -- Echoes of Nemesis
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29123; -- Rage Against the Flames
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29125; -- Between the Trees
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29126; -- The Power of Malorne
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29127; -- Rage Against the Flames
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29137; -- Breach in the Defenses
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29138; -- Burn Victims
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29139; -- Aggressive Growth
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29141; -- The Harder They Fall
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29142; -- Traitors Return
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29143; -- Wisp Away
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29147; -- Call the Flock
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29149; -- Rage Against the Flames
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29162; -- Nature's Blessing
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29163; -- Rage Against the Flames
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29167; -- The Banshee Queen
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29179; -- Hostile Elements
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29203; -- Into the Depths
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29205; -- The Forlorn Spire
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29206; -- Into the Fire
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29210; -- Enduring the Heat
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29248; -- Releasing the Pressure
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29265; -- Fire Flowers
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29279; -- Filling the Moonwell
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29280; -- Nourishing Waters
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29281; -- Additional Armaments
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29282; -- Well Armed
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29283; -- Calling the Ancients
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29284; -- Aid of the Ancients
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29287; -- Peaked Interest
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29288; -- Starting Young
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29290; -- Fire in the Skies
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29293; -- Singed Wings
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29296; -- Territorial Birds
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29304; -- The Dogs of War
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29337; -- Into Constant Earth
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29439; -- The Call of the World-Shaman
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29440; -- The Call of the World-Shaman
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29565; -- The Heart of the Matter
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29573; -- Safety is Job One
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29574; -- Intriguing Specimens
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29575; -- Undercutting the Competition
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29583; -- Eckert the Mad
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29590; -- The Dead Watcher
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29591; -- Raging Spirits
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29596; -- The End of the Exarch
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29606; -- Terokk's Legacy
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29607; -- Eyes of Desire
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29613; -- A Proper Fate
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29614; -- Containment is Key
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29615; -- Windcaller Claw and the Water Thief
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29642; -- Trouble at Auchindoun
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=15595 WHERE `ID`=29691; -- Bring Me A Shrubbery!
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `Emote4`=4, `VerifiedBuild`=15595 WHERE `ID`=28035; -- The Mountain-Lord's Support
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=11289; -- Guided by Honor
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10022; -- The Elusive Ironjaw
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10257; -- Capturing the Keystone
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12503; -- Defend the Stand
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=29276; -- The Flame Spider Queen
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=26473; -- Bathran's Hair
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11268; -- The Walking Dead
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12527; -- Gluttonous Lurkers
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13040; -- Curing The Incurable
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13673; -- A Blade Fit For A Champion
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13783; -- A Blade Fit For A Champion
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13794; -- Eadric the Pure
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25261; -- Margoz
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25889; -- Save the Children!
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26538; -- Emergency Aid
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26606; -- Mukla's Demise
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28119; -- Purity From Corruption
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28608; -- The Shadow Grave
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=13630; -- The Reason Why
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=13632; -- Rear Guard Duty
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=100, `VerifiedBuild`=15595 WHERE `ID`=932; -- Twisted Hatred
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=100, `VerifiedBuild`=15595 WHERE `ID`=2518; -- Tears of the Moon
UPDATE `quest_offer_reward` SET `Emote1`=2, `EmoteDelay1`=200, `VerifiedBuild`=15595 WHERE `ID`=2459; -- Ferocitas the Dream Eater
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`='Thank you, $N.  The purity with which these beasts hunt is vital in the creation of the next cleansing totem.$B$BThe Thunderhorn Well is a symbol of my own tribe, and to know it is being desecrated by our own kind raises a fury in me I haven\'t felt for years.', `VerifiedBuild`=15595 WHERE `ID`=24441; -- Thunderhorn Totem
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=172; -- Children's Week
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=761; -- Swoop Hunting
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=923; -- Mossy Tumors
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=2158; -- Rest and Relaxation
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=2541; -- The Sleeping Druid
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=8480; -- Lost Armaments
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=10686; -- The Warden's Cage
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=10896; -- The Infested Protectors
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=11882; -- Playing with Fire
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=11964; -- Incense for the Summer Scorchlings
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=11972; -- Shards of Ahune
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=12248; -- Vordrassil's Sapling
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=12623; -- To the Witch Doctor
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=12794; -- The Magical Kingdom of Dalaran
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=13115; -- Cheese for Glowergold
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=13867; -- Culling the Furbolg Threat
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=14243; -- Warchief's Revenge
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=24471; -- Aid for the Wounded
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=25093; -- The Heads of the SI:7
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=25189; -- Spirits Be Praised
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=26065; -- Free Wil'hai
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=26452; -- Gurubashi Challenge
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=26453; -- A Helping Hand
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=26470; -- Retaking Mystral Lake
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=26872; -- Deviate Hides
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=28030; -- They Build a Better Bullet
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=28724; -- Iverron's Antidote
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=29433; -- Test Your Strength
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=29434; -- Tonk Commander
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=29436; -- The Humanoid Cannonball
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=29455; -- Target: Turtle
UPDATE `quest_offer_reward` SET `Emote1`=2, `VerifiedBuild`=15595 WHERE `ID`=29463; -- It's Hammer Time
UPDATE `quest_offer_reward` SET `Emote1`=3, `VerifiedBuild`=15595 WHERE `ID`=24490; -- A Trip to Ironforge
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15595 WHERE `ID`=11277; -- The Depths of Depravity
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=15595 WHERE `ID`=12232; -- Bombard the Ballistae
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=273, `VerifiedBuild`=15595 WHERE `ID`=9523; -- Precious and Fragile Things Need Special Handling
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=500, `EmoteDelay3`=500, `VerifiedBuild`=15595 WHERE `ID`=8886; -- Grimscale Pirates!
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12662; -- Bringing Down Heb'Jin
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=5502; -- A Warden of the Horde
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12097; -- Sarathstra, Scourge of the North
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=9852; -- The Ultimate Bloodsport
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=9740; -- The Sun Gate
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=11426; -- Locating the Mechanism
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15595 WHERE `ID`=12555; -- A Tangled Skein
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=25, `Emote4`=1, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=12273; -- The Denouncement
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15595 WHERE `ID`=26621; -- Insurrection
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10446; -- The Final Code
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=11396; -- Bring Down Those Shields
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=29567; -- Stalk the Stalker
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9513; -- Reclaiming the Ruins
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11243; -- If Valgarde Falls...
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12211; -- Let Them Not Rise!
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12516; -- Too Much of a Good Thing
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12978; -- Facing the Storm
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13135; -- It Could Kill Us All
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26784; -- Muddied Waters
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26891; -- Amongst the Ruins
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26995; -- Guts and Gore
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27070; -- A Fool's Errand
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28121; -- Forces of Jaedenar
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28128; -- The Inner Circle
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=13924; -- All's Well
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=13853; -- Return Fire
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26466; -- Ruuzel
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=4, `Emote3`=4, `Emote4`=4, `EmoteDelay2`=1000, `EmoteDelay3`=1500, `EmoteDelay4`=2000, `VerifiedBuild`=15595 WHERE `ID`=26091; -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `Emote3`=1, `Emote4`=273, `VerifiedBuild`=15595 WHERE `ID`=26229; -- "I TAKE Candle!"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `Emote3`=273, `EmoteDelay3`=2000, `VerifiedBuild`=15595 WHERE `ID`=28032; -- The Mysteries of the Fire-Gizzard
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=7905; -- The Darkmoon Faire
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=7926; -- The Darkmoon Faire
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=11420; -- The Path to Payback
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=14474; -- Goblin Escape Pods
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=13698; -- Explosives Shredding
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=25974; -- Sira'kess Slaying
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=14238; -- Infrared = Infradead
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=27622; -- Mo' Better Shredder
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=94, `VerifiedBuild`=15595 WHERE `ID`=12707; -- Wooly Justice
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=396, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=26288; -- Jango Spothide
UPDATE `quest_offer_reward` SET `Emote1`=4, `RewardText`='The Malt is brewed, the Boars are dead$bAnd before all is done and anything said$bWe will have to fight for first dibs$bOn these savory Beer Basted Boar Ribs!', `VerifiedBuild`=15595 WHERE `ID`=384; -- Beer Basted Boar Ribs
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=2438; -- The Emerald Dreamcatcher
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=8468; -- Wanted: Thaelis the Hungerer
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=9283; -- Rescue the Survivors!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=9549; -- Artifacts of the Blacksilt
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=9562; -- Murlocs... Why Here? Why Now?
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=9629; -- Catch and Release
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=9851; -- Clefthoof Mastery
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11008; -- Fires Over Skettis
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11190; -- One Size Does Not Fit All
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11227; -- Let Them Eat Crow
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11230; -- Ambushed!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11232; -- Guide Our Sights
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11306; -- Apply Heat and Stir
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=11310; -- Warning: Some Assembly Required
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=12427; -- The Conquest Pit: Bear Wrestling!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=13116; -- Mustard Dogs!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=14012; -- Corruption
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=14239; -- Don't Go Into the Light!
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=24642; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=24671; -- Cluster Cluck
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=24744; -- The Biggest Egg Ever
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=24780; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=24974; -- Ever So Lonely
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25050; -- Rocket Rescue
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25058; -- Mine Disposal, the Goblin Way
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25066; -- The Pride of Kezan
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25251; -- Final Confrontation
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25522; -- Gargantapid
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25767; -- Capturing Memories
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25851; -- Dances with Grimtotem
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=25994; -- Still Valuable
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=26361; -- Smoot's Samophlange
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=26389; -- Blackrock Invasion
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=26614; -- Keep An Eye Out
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=26892; -- Deep in the Deeps
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=26976; -- Battle for the Scarlet Monastery
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=27145; -- Plagued Hatchlings...For Now
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=15595 WHERE `ID`=28595; -- Krazz Works!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=9694; -- Blood Watch
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=12709; -- Hexed Caches
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=15595 WHERE `ID`=12061; -- Projections and Plans
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=70, `VerifiedBuild`=15595 WHERE `ID`=11443; -- Daggercap Divin'
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=10042; -- Kill the Shadow Council!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12110; -- The End of the Line
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12252; -- Torture the Torturer
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9748; -- Don't Drink the Water
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10953; -- Visit the Throne of the Elements
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11276; -- And Then There Were Two...
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11465; -- The Ransacked Caravan
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11978; -- Into the Fold
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12036; -- From the Depths of Azjol-Nerub
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12048; -- Scourge Armaments
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12919; -- The Storm King's Vengeance
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26464; -- The Lost Gem
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26598; -- The Heart of Mokk
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=27226; -- Hair of the Dog
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=29275; -- Fandral's Methods
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=25652; -- Commandeer That Balloon!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=5, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=12596; -- Pa'Troll
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=25876; -- It's Up There!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=66, `VerifiedBuild`=15595 WHERE `ID`=13141; -- The Battle For Crusaders' Pinnacle
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=66, `VerifiedBuild`=15595 WHERE `ID`=27094; -- Deeper into Darkness
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=26337; -- Beating the Market
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=26992; -- Agony Abounds
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=26998; -- Iterating Upon Success
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=12721; -- Rampage
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=27290; -- To Forsaken Forward Command
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=397, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=25267; -- Message for Saurfang
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=12583; -- Crashed Sprayer
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=930; -- The Glowing Fruit
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9324; -- Stealing Orgrimmar's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9325; -- Stealing Thunder Bluff's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9326; -- Stealing the Undercity's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9330; -- Stealing Stormwind's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9331; -- Stealing Ironforge's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9332; -- Stealing Darnassus's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9683; -- Ending the Bloodcurse
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10231; -- What Book? I Don't See Any Book.
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10333; -- Help Mama Wheeler
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11279; -- Green Eggs and Whelps
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11395; -- It's a Scourge Device
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11398; -- It's a Scourge Device
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11669; -- Felblood Fillet
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11933; -- Stealing the Exodar's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11935; -- Stealing Silvermoon's Flame
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12091; -- Wanted: Dreadtalon
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12244; -- Shredder Repair
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12296; -- Life or Death
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12895; -- The Missing Bronzebeard
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13274; -- The Core's Keeper
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25822; -- Armaments for War
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25912; -- Seen Better Days
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25931; -- Brood of Seldarria
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26320; -- A Vision of the Past
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26622; -- Death to Mor'ghor
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27045; -- Waiting to Exsanguinate
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27082; -- Playing Dirty
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26465; -- The Ancient Statuettes
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26475; -- Elune's Tear
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=4, `Emote3`=1, `Emote4`=25, `VerifiedBuild`=15595 WHERE `ID`=13343; -- Mystery of the Infinite, Redux
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=4, `VerifiedBuild`=15595 WHERE `ID`=26266; -- Hope for the People
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9537; -- Show Gnomercy
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=5, `EmoteDelay2`=500, `VerifiedBuild`=15595 WHERE `ID`=25651; -- Oh, the Insanity!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=5, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=25657; -- Dah, Nunt... Dah, Nunt...
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=12274; -- A Fall From Grace
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11324; -- Alpha Worg
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=25730; -- BEWARE OF CRAGJAW!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=27140; -- Alexi's Gambit
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=26388; -- Twilight Skies
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=14245; -- It's a Town-In-A-Box
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9133; -- Fly to Silvermoon City
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=14248; -- Help Wanted
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=9756; -- What We Don't Know...
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=11267; -- The Frost Wyrm and its Master
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=14021; -- Miner Troubles
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=14236; -- Weed Whacker
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=15, `Emote3`=5, `Emote4`=5, `VerifiedBuild`=15595 WHERE `ID`=27195; -- Nowhere to Run
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=15, `VerifiedBuild`=15595 WHERE `ID`=25934; -- World First: Gnomegen
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=15, `VerifiedBuild`=15595 WHERE `ID`=26358; -- Ready the Air Force
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=18, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=24897; -- Get Back to Town
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=18, `VerifiedBuild`=15595 WHERE `ID`=27981; -- Heat That Just Don't Quit
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=21, `VerifiedBuild`=15595 WHERE `ID`=26964; -- Warchief's Command: Silverpine Forest!
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=25, `Emote3`=10, `VerifiedBuild`=15595 WHERE `ID`=28034; -- Lunk's Adventure: Rendan's Weakness
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=13273; -- Going After the Core
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=26540; -- Dangerous Compassion
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=396, `EmoteDelay2`=500, `VerifiedBuild`=15595 WHERE `ID`=25794; -- Undersea Sanctuary
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13132; -- Vengeance Be Mine!
UPDATE `quest_offer_reward` SET `Emote1`=5, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11393; -- Where is Explorer Jaren?
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`='The relics are intact! Well, indeed, that is something.$b$bYou have put my mind at ease, $r. Please accept this as my gift to you.', `VerifiedBuild`=15595 WHERE `ID`=14354; -- Elune's Gifts
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=476; -- Gnarlpine Corruption
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=7737; -- Gaining Even More Acceptance
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=8482; -- Incriminating Documents
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=8483; -- The Dwarven Spy
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=9463; -- Medicinal Purpose
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=9990; -- Investigate Tuurem
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=10038; -- Speak with Private Weeks
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=11175; -- My Daughter
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=11229; -- The Windrunner Fleet
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=11266; -- Gjalerbron Attack Plans
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=11304; -- New Agamand
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12037; -- Search and Rescue
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12059; -- A Strange Device
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12283; -- The Truth Will Out
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12552; -- Death to the Necromagi
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12821; -- Opening the Backdoor
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12822; -- Know No Fear
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12823; -- A Flawless Plan
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12826; -- Slightly Unstable
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=12836; -- Expression of Gratitude
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=13604; -- Archivum Data Disc
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=13662; -- Gaining Acceptance
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=14005; -- The Vengeance of Elune
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=14326; -- Meet Me Up Top
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=14387; -- Lay of the Land
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=14445; -- Farewell, For Now
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24682; -- The Pit of Saron
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24712; -- Deliverance from the Pit
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24741; -- Trading Up
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24778; -- The Arts of a Hunter
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24859; -- Naga Hide
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24864; -- Irresistible Pool Pony
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24868; -- Surrender or Else!
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24925; -- Free the Captives
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24937; -- Oomlot Dealt With
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=24952; -- Rocket Boot Boost
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25100; -- Let's Ride
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25121; -- Momentum
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25123; -- Throw It On the Ground!
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25184; -- Wild Mine Cart Ride
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25187; -- Lost in the Floods
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25188; -- Watershed Patrol
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25256; -- Sent for Help
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25263; -- Arnak Fireblade
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25811; -- Shuttin Her Down
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25875; -- Gnome on the Inside
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25877; -- No Time for Goodbyes!
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25878; -- Schemin' That Sabotage
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25935; -- Hungry Pups
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25947; -- Finders, Keepers
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=25991; -- We Are Not Alone
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=26372; -- Pre-Flight Checklist
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27180; -- Honor the Dead
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27472; -- Rise, Godfrey
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27685; -- Good Deed Left Undone
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27727; -- Hero's Call: Deepholm!
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27958; -- A Proper Antivenom
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=27964; -- Dig-Boss Dinwhisker
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=28715; -- Demonic Thieves
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=28727; -- Vile Touch
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=28849; -- Twilight Skies
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=29243; -- Strike at the Heart
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=29305; -- Strike at the Heart
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=29328; -- Elemental Bonds: Desire
UPDATE `quest_offer_reward` SET `Emote1`=5, `VerifiedBuild`=15595 WHERE `ID`=29763; -- Stealing Their Thunder
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=2, `VerifiedBuild`=15595 WHERE `ID`=9689; -- Razormaw
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=4, `VerifiedBuild`=15595 WHERE `ID`=25152; -- Your Place In The World
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=25, `VerifiedBuild`=15595 WHERE `ID`=10253; -- Levixus the Soul Caller
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=10005; -- Letting Earthbinder Tavgren Know
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=12271; -- The Rod of Compulsion
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9622; -- Warn Your People
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12090; -- Wanted: Gigantaur
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=25765; -- Tell 'Em Koko Sent You
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26479; -- Return to Raene
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12506; -- Trouble at the Altar of Sseratus
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=9671; -- Urgent Delivery
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=12084; -- Atop the Woodlands
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=26311; -- Unfamiliar Waters
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=11, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=12230; -- Stealing from the Siegesmiths
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=15, `VerifiedBuild`=15595 WHERE `ID`=25891; -- Last Ditch Effort
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15595 WHERE `ID`=12245; -- No Mercy for the Captured
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=10519; -- The Cipher of Damnation - Truth and History
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=9687; -- Restoring Sanctity
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=26798; -- Saurfang Will be Pleased
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=25965; -- Gauging Success
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9134; -- Skymistress Gloaming
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12239; -- The Spy in New Hearthglen
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=9672; -- The Bloodcurse Legacy
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10514; -- I Was A Lot Of Things...
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12122; -- Gaining an Audience
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12512; -- Leave No One Behind
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12912; -- A Great Storm Approaches
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13623; -- Delivery for Orendil
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13646; -- Astranaar Bound
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25845; -- Terms of Service
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25988; -- Put It On
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26286; -- In Defense of Westfall
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26291; -- Big Trouble in Moonbrook
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26611; -- The Baron Must Be Told
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28055; -- Sweet, Horrible Freedom
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=28057; -- Kill 'em With Sleep Deprivation
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=931; -- The Shimmering Frond
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=12769; -- The Steward of Wyrmrest Temple
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=26474; -- Orendil's Cure
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=25038; -- Gordo's Task
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26619; -- You Say You Want a Revolution
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=26209; -- Murder Was The Case That They Gave Me
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have a wild look about ya though. Fierce eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=15595 WHERE `ID`=24776; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually look ta be in shape though. Steady hands. Fierce eyes. I may be able ta turn ya into a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=15595 WHERE `ID`=24607; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=1000, `RewardText`='Well, that\'s good and bad news, now isn\'t it?  We\'ve dealt them a blow, but with the Burning Legion running free all over the Netherstorm - and getting closer to us here - well, I don\'t know how it\'s going to go.$B$BI have a feeling that we\'re going to have to change gears here for a while.  Hope you\'ll be able to help us out, $N.', `VerifiedBuild`=15595 WHERE `ID`=10232; -- In A Scrap With The Legion
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=12254; -- Without a Prayer
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=12584; -- Pure Evil
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=12928; -- Norgannon's Shell
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=13039; -- Defending The Vanguard
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=26257; -- It's Alive!
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11, `EmoteDelay2`=3000, `VerifiedBuild`=15595 WHERE `ID`=11241; -- Trail of Fire
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=11657; -- Torch Catching
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=11, `VerifiedBuild`=15595 WHERE `ID`=11923; -- Torch Catching
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=21, `Emote3`=6, `VerifiedBuild`=15595 WHERE `ID`=26478; -- Playing Possum
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=25, `Emote3`=66, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=25669; -- Rumble in the Lumber... Mill
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=113, `VerifiedBuild`=15595 WHERE `ID`=24470; -- Give 'em What-For
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=274, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15595 WHERE `ID`=10513; -- Oronok Torn-heart
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=274, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=13072; -- A Hero Remains
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=12008; -- Agmar's Hammer
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=274, `VerifiedBuild`=15595 WHERE `ID`=26213; -- Hot On the Trail: The Riverpaw Clan
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=396, `EmoteDelay2`=500, `VerifiedBuild`=15595 WHERE `ID`=27699; -- Shark Weak
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=26295; -- Propaganda
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=100, `VerifiedBuild`=15595 WHERE `ID`=840; -- Conscript of the Horde
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=25109; -- The Gallywix Labor Mine
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=12505; -- New Orders for Sergeant Stackhammer
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=9455; -- Strange Findings
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=9703; -- The Cryo-Core
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=10040; -- Who Are They?
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=11317; -- The Cleansing
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=12304; -- Beachfront Property
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=12461; -- Report to the Ruby Dragonshrine
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=12824; -- Demolitionist Extraordinaire
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=13207; -- Halls of Stone
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=13617; -- West to the Strand
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=14235; -- The Vicious Vale
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=24643; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=24781; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=24961; -- The Truth of the Grave
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25032; -- Secrets in the Oasis
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25214; -- Escape Velocity
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25264; -- Ak'Zeloth
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25732; -- A Bone to Pick
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25908; -- Stick it to Them
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25957; -- Visions of the Past: The Invasion of Vashj'ir
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=25966; -- Visions of the Past: The Slaughter of Biel'aran Ridge
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=26385; -- Breaking Waves of Change
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=26456; -- Report from the Northern Front
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=26476; -- Dryad Delivery
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=27194; -- Cornered and Crushed!
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=27956; -- Lunk's Task
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=27965; -- Thorium Point: The Seat of the Brotherhood
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=28099; -- Rasha'krak
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=28826; -- The Eye of the Storm
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=15595 WHERE `ID`=29327; -- Elemental Bonds: Doubt
UPDATE `quest_offer_reward` SET `Emote1`=7, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12857; -- Wanted: Ragemane's Flipper
UPDATE `quest_offer_reward` SET `Emote1`=7, `VerifiedBuild`=15595 WHERE `ID`=25021; -- Blood to Thrive
UPDATE `quest_offer_reward` SET `Emote1`=7, `VerifiedBuild`=15595 WHERE `ID`=25026; -- Darkest Mojo
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11097; -- The Deadliest Trap Ever Laid
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26910; -- Etched Letter
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=2, `VerifiedBuild`=15595 WHERE `ID`=29274; -- Hounds of Shannox
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=4, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12285; -- Do Unto Others
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=12243; -- Fire Upon the Waters
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=12819; -- Just Around the Corner
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=871; -- In Defense of Far Watch
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12240; -- A Means to an End
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26294; -- Weapons of Mass Dysfunction
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=5, `Emote3`=25, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12085; -- A Letter for Home
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=29263; -- A Bitter Pill
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12659; -- Scalps!
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=25, `VerifiedBuild`=15595 WHERE `ID`=12622; -- The Leaders at Jin'Alai
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=25, `VerifiedBuild`=15595 WHERE `ID`=27088; -- It's Only Poisonous if You Ingest It
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=14019; -- Monkey Business
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=25025; -- Sang'thraze the Deflector
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=25976; -- Treasure Reclamation
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=25980; -- A Standard Day for Azrajar
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=28584; -- Quality Construction
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=28589; -- Everything But the Kitchen Sink
UPDATE `quest_offer_reward` SET `Emote1`=11, `VerifiedBuild`=15595 WHERE `ID`=28592; -- Parting Packages
UPDATE `quest_offer_reward` SET `Emote1`=14, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11299; -- The Ring of Judgment
UPDATE `quest_offer_reward` SET `Emote1`=15, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11453; -- The Slumbering King
UPDATE `quest_offer_reward` SET `Emote1`=15, `Emote2`=1, `Emote3`=66, `VerifiedBuild`=15595 WHERE `ID`=25846; -- Grundig Darkcloud, Chieftain of the Grimtotem
UPDATE `quest_offer_reward` SET `Emote1`=15, `Emote2`=396, `Emote3`=153, `VerifiedBuild`=15595 WHERE `ID`=27850; -- The Defias Kingpin
UPDATE `quest_offer_reward` SET `Emote1`=15, `VerifiedBuild`=15595 WHERE `ID`=25265; -- Victory!
UPDATE `quest_offer_reward` SET `Emote1`=15, `VerifiedBuild`=15595 WHERE `ID`=25848; -- Downfall
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=1, `Emote3`=15, `VerifiedBuild`=15595 WHERE `ID`=9706; -- Galaen's Journal - The Fate of Vindicator Saruan
UPDATE `quest_offer_reward` SET `Emote1`=18, `Emote2`=6, `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=13645; -- To Raene Wolfrunner
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=15595 WHERE `ID`=11470; -- There Exists No Honor Among Birds
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=9663; -- The Kessel Run
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26873; -- Preemptive Methods
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=11460; -- Trust is Earned
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10035; -- Torgos!
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26788; -- Cementing Our Victory
UPDATE `quest_offer_reward` SET `Emote1`=21, `EmoteDelay1`=1, `VerifiedBuild`=15595 WHERE `ID`=29438; -- He Shoots, He Scores!
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=314; -- Protecting the Herd
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=483; -- The Relics of Wakening
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=24477; -- Dwarven Artifacts
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=24995; -- Off the Scales
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25013; -- A Little Oomph
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25049; -- Puddle Stomping
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25054; -- Lootin' Plunder
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25056; -- Grisly Grizzlies
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25112; -- Butcherbot
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=25521; -- I'm With Scorpid
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=26613; -- Up to Snuff
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=26886; -- Going Off-Task
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=27019; -- Scourge of the Downs
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=27110; -- The Madness Within
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=28713; -- The Balance of Nature
UPDATE `quest_offer_reward` SET `Emote1`=21, `VerifiedBuild`=15595 WHERE `ID`=29317; -- Fish Head
UPDATE `quest_offer_reward` SET `Emote1`=22, `Emote2`=18, `Emote3`=274, `VerifiedBuild`=15595 WHERE `ID`=11280; -- Draconis Gastritis
UPDATE `quest_offer_reward` SET `Emote1`=22, `VerifiedBuild`=15595 WHERE `ID`=24473; -- Lockdown in Anvilmar
UPDATE `quest_offer_reward` SET `Emote1`=24, `VerifiedBuild`=15595 WHERE `ID`=25227; -- Thonk
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `Emote3`=11, `VerifiedBuild`=15595 WHERE `ID`=27073; -- Give 'em Hell!
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24535; -- Thalorien Dawnseeker
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26252; -- Heart of the Watcher
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=6, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=27098; -- Lordaeron
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12910; -- Sniffing Out the Perpetrator
UPDATE `quest_offer_reward` SET `Emote1`=25, `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=12514; -- Mushroom Mixer
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=11390; -- I've Got a Flying Machine!
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=13872; -- Worgen Wisdom
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=14240; -- To the Cliffs
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=25024; -- Repel the Paratroopers
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=25938; -- Help for Desolace
UPDATE `quest_offer_reward` SET `Emote1`=25, `VerifiedBuild`=15595 WHERE `ID`=28588; -- Wildhammer Infestation
UPDATE `quest_offer_reward` SET `Emote1`=30, `VerifiedBuild`=15595 WHERE `ID`=25358; -- Nerve Tonic
UPDATE `quest_offer_reward` SET `Emote1`=33, `VerifiedBuild`=15595 WHERE `ID`=13644; -- That Which Has Risen
UPDATE `quest_offer_reward` SET `Emote1`=51, `VerifiedBuild`=15595 WHERE `ID`=13796; -- The Forest Heart
UPDATE `quest_offer_reward` SET `Emote1`=53, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12916; -- Our Only Hope
UPDATE `quest_offer_reward` SET `Emote1`=53, `VerifiedBuild`=15595 WHERE `ID`=11295; -- The Offensive Begins
UPDATE `quest_offer_reward` SET `Emote1`=53, `VerifiedBuild`=15595 WHERE `ID`=13047; -- The Reckoning
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=11980; -- Pride of the Horde
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12072; -- Blightbeasts be Damned!
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=12224; -- The Kor'kron Vanguard!
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=28494; -- Warchief's Command: Northern Barrens!
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13070; -- A Cold Front Approaches
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13676; -- Training In The Field
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13771; -- A Valiant's Field Training
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13786; -- A Valiant's Field Training
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=13810; -- Taking Battle To The Enemy
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=24970; -- No Better Than the Zombies
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25996; -- Waking the Beast
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=6, `VerifiedBuild`=15595 WHERE `ID`=12071; -- Attack by Air! 
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=15, `VerifiedBuild`=15595 WHERE `ID`=13935; -- Defend the Tree!
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=487; -- The Road to Darnassus
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=11006; -- More Shadow Dust
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=12562; -- The Drakkari Do Not Need Water Elementals!
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=13180; -- Slay them all!
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=13709; -- Valiant Of Thunder Bluff
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=14237; -- Forward Movement
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=24491; -- Follow that Gyro-Copter!
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=24998; -- Maggot Eye
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=25173; -- From Bad to Worse
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=25177; -- Storming the Beaches
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=25984; -- Promontory Point
UPDATE `quest_offer_reward` SET `Emote1`=66, `VerifiedBuild`=15595 WHERE `ID`=28717; -- Warchief's Command: Twilight Highlands!
UPDATE `quest_offer_reward` SET `Emote1`=71, `Emote2`=16, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=24942; -- Zombies vs. Super Booster Rocket Boots
UPDATE `quest_offer_reward` SET `Emote1`=71, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13131; -- Junk in My Trunk
UPDATE `quest_offer_reward` SET `Emote1`=71, `VerifiedBuild`=15595 WHERE `ID`=24940; -- Up the Volcano
UPDATE `quest_offer_reward` SET `Emote1`=71, `VerifiedBuild`=15595 WHERE `ID`=25390; -- A Girl's Best Friend
UPDATE `quest_offer_reward` SET `Emote1`=71, `VerifiedBuild`=15595 WHERE `ID`=25598; -- Ain't Too Proud to Beg
UPDATE `quest_offer_reward` SET `Emote1`=94, `VerifiedBuild`=15595 WHERE `ID`=25170; -- Cleaning Up the Coastline
UPDATE `quest_offer_reward` SET `Emote1`=153, `VerifiedBuild`=15595 WHERE `ID`=13063; -- Deemed Worthy
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10026; -- Magical Disturbances
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=28060; -- Twisted Twilight Ties
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=4, `VerifiedBuild`=15595 WHERE `ID`=12268; -- Pieces Parts
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15595 WHERE `ID`=11260; -- Stop the Ascension!
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=66, `VerifiedBuild`=15595 WHERE `ID`=26374; -- Ready the Ground Troops
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `EmoteDelay2`=800, `VerifiedBuild`=15595 WHERE `ID`=844; -- Plainstrider Menace
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=12033; -- Message from the West
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=25880; -- Warn Master Thal'darah
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26319; -- Secrets Revealed
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12901; -- Making Something Out Of Nothing
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13044; -- If There Are Survivors...
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=13849; -- Astranaar's Burning!
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=13979; -- The Goblin Braintrust
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=24929; -- Send a Message
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=25115; -- Blisterpaw Butchery
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=25201; -- The Ultimate Footbomb Uniform
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=26122; -- Environmental Awareness
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=26889; -- All Cheered Out
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=28054; -- Slavery is Bad
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=28148; -- Culling the Corrupted
UPDATE `quest_offer_reward` SET `Emote1`=273, `VerifiedBuild`=15595 WHERE `ID`=28586; -- Pool Pony Rescue
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `Emote3`=5, `Emote4`=274, `VerifiedBuild`=15595 WHERE `ID`=26228; -- Livin' the Life
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `Emote3`=24, `VerifiedBuild`=15595 WHERE `ID`=26215; -- Meet Two-Shoed Lou
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=26830; -- Traitor's Bait
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `Emote3`=273, `VerifiedBuild`=15595 WHERE `ID`=26965; -- The Warchief Cometh
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=25168; -- Purge the Valley
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=27423; -- Resistance is Futile
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=2, `VerifiedBuild`=15595 WHERE `ID`=13626; -- Respect for the Fallen
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=29326; -- The Nordrassil Summit
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=15, `VerifiedBuild`=15595 WHERE `ID`=25900; -- Making Contact
UPDATE `quest_offer_reward` SET `Emote1`=274, `VerifiedBuild`=15595 WHERE `ID`=11254; -- The Dragonskin Map
UPDATE `quest_offer_reward` SET `Emote1`=274, `VerifiedBuild`=15595 WHERE `ID`=12246; -- A Possible Link
UPDATE `quest_offer_reward` SET `Emote1`=274, `VerifiedBuild`=15595 WHERE `ID`=13607; -- The Celestial Planetarium
UPDATE `quest_offer_reward` SET `Emote1`=274, `VerifiedBuild`=15595 WHERE `ID`=25007; -- East... Always to the East
UPDATE `quest_offer_reward` SET `Emote1`=388, `VerifiedBuild`=15595 WHERE `ID`=11170; -- Test at Sea
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=26292; -- To Moonbrook!
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=26347; -- Keeper of the Flame
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=12937; -- Relief for the Fallen
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=5, `VerifiedBuild`=15595 WHERE `ID`=26390; -- Ending the Invasion!
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10839; -- Veil Skith: Darkstone of Terokk
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10847; -- The Eyes of Skettis
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10848; -- Veil Rhaze: Unliving Evil
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10849; -- Seek Out Kirrik
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10861; -- Veil Lithic: Preemptive Strike
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10874; -- Veil Shalas: Signal Fires
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10879; -- The Skettis Offensive
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10889; -- Return to Shattrath
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=12115; -- Koltira and the Language of Death
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `EmoteDelay2`=500, `VerifiedBuild`=15595 WHERE `ID`=25587; -- Gimme Shelter!
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=29539; -- Heart of Rage
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12914; -- Gymer's Salvation
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12924; -- Forging an Alliance
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12975; -- In Memoriam
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12976; -- A Monument to the Fallen
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12985; -- Forging a Head
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=12987; -- Mounting Hodir's Helm
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13001; -- Raising Hodir's Spear
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13010; -- Krolmir, Hammer of Storms
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13011; -- Jormuttar is Soo Fat...
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13094; -- Have They No Shame?
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13124; -- The Struggle Persists
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13126; -- A Unified Front
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13151; -- A Royal Escort
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=13420; -- Everfrost
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=25029; -- Deaths in the Family
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=26287; -- The Westfall Brigade
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=29314; -- Remembering the Ancestors
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=29830; -- Containment
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=29833; -- Unfinished Business
UPDATE `quest_offer_reward` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=15595 WHERE `ID`=29861; -- Whatever it Takes!
UPDATE `quest_offer_reward` SET `Emote1`=396, `RewardText`='Welcome to Nijel\'s Point, $r.$b$bNow, let\'s see about getting you briefed on our situation here.', `VerifiedBuild`=15595 WHERE `ID`=14384; -- Rerouted!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=11424; -- Shield Hill
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=12856; -- Cold Hearted
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=13127; -- Mage-Lord Urom
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=13128; -- A Wing and a Prayer
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=13149; -- Dispelling Illusions
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=13421; -- Remember Everfrost!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=14095; -- Identifying the Remains
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=14108; -- Get Kraken!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=14136; -- Rescue at Sea
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=14244; -- Up, Up & Away!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=14482; -- Call of Duty
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=24432; -- Sea Legs
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=24901; -- Town-In-A-Box: Under Attack
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=24960; -- The Wakening
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=24978; -- Reaping the Reapers
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25005; -- Speak with Sevren
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25023; -- Old Friends
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25031; -- Head for the Mills
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25072; -- A Few Good Goblins
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25388; -- A Case of Crabs
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25459; -- Ophidophobia
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25477; -- Better Late Than Dead
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25602; -- Can't Start a Fire Without a Spark
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25670; -- DUN-dun-DUN-dun-DUN-dun
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25743; -- Decisions, Decisions
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25948; -- Bring It On!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=25949; -- Blood and Thunder!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=26086; -- Orako
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=28376; -- Myzerian's Head
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=28749; -- The Battle for Andorhal
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=28825; -- A Personal Summons
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29129; -- A Legendary Engagement
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29315; -- Fungus Among Us
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29319; -- Tadpole Terror
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29320; -- Like Pike?
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29322; -- Time for Slime
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29332; -- Lily, Oh Lily
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29333; -- Escargot A Go-Go
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29334; -- Roach Coach
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29338; -- Into Unrelenting Flame
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29360; -- Would You Like Some Flies With That?
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29361; -- Moat Monster!
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29364; -- Corn Mash
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29365; -- Perfectly Picked Portions
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29528; -- War on the Ramparts
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29529; -- Demons in the Citadel
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29538; -- Make Them Bleed
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29540; -- The Breaker
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29564; -- A Brother Betrayed
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29594; -- Hitting Them Where It Hurts
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29834; -- Gal'darah Must Pay
UPDATE `quest_offer_reward` SET `Emote1`=396, `VerifiedBuild`=15595 WHERE `ID`=29844; -- For Posterity
UPDATE `quest_offer_reward` SET `Emote1`=397, `VerifiedBuild`=15595 WHERE `ID`=26090; -- I Brought You This Egg
UPDATE `quest_offer_reward` SET `Emote1`=430, `Emote2`=18, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=28732; -- This Can Only Mean One Thing...
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=3104; -- Glyphic Letter
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10942; -- Children's Week
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=10967; -- Back to the Orphanage
UPDATE `quest_offer_reward` SET `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=11086; -- Disrupting the Twilight Portal
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=8330; -- Solanian's Belongings
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10945; -- Hch'uu and the Mushroom People
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10951; -- A Trip to the Dark Portal
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=10963; -- Time to Visit the Caverns
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11020; -- A Slow Death
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11035; -- The Not-So-Friendly Skies...
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11067; -- Dragonmaw Race: Trope the Filth-Belcher
UPDATE `quest_offer_reward` SET `Emote2`=1, `VerifiedBuild`=15595 WHERE `ID`=11077; -- Dragons are the Least of Our Problems
UPDATE `quest_offer_reward` SET `Emote2`=66, `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=54; -- Report to Goldshire
UPDATE `quest_offer_reward` SET `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=8345; -- The Shrine of Dath'Remar
UPDATE `quest_offer_reward` SET `EmoteDelay1`=60, `VerifiedBuild`=15595 WHERE `ID`=12262; -- No One to Save You
UPDATE `quest_offer_reward` SET `EmoteDelay1`=60, `VerifiedBuild`=15595 WHERE `ID`=12264; -- Culling the Damned
UPDATE `quest_offer_reward` SET `EmoteDelay1`=120, `VerifiedBuild`=15595 WHERE `ID`=12263; -- The Best of Intentions
UPDATE `quest_offer_reward` SET `EmoteDelay1`=500, `VerifiedBuild`=15595 WHERE `ID`=9423; -- Return to Obadei
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11188; -- Two Wrongs...
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000, `VerifiedBuild`=15595 WHERE `ID`=11236; -- Necro Overlord Mezhen
UPDATE `quest_offer_reward` SET `EmoteDelay1`=2000, `VerifiedBuild`=15595 WHERE `ID`=12297; -- Of Traitors and Treason
UPDATE `quest_offer_reward` SET `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=12419; -- The Fate of the Ruby Dragonshrine
UPDATE `quest_offer_reward` SET `EmoteDelay2`=60, `VerifiedBuild`=15595 WHERE `ID`=12853; -- Luxurious Getaway!
UPDATE `quest_offer_reward` SET `EmoteDelay2`=300, `VerifiedBuild`=15595 WHERE `ID`=12050; -- Lumber Hack
UPDATE `quest_offer_reward` SET `EmoteDelay2`=500, `VerifiedBuild`=15595 WHERE `ID`=12152; -- Jin'arrak's End
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9854; -- Windroc Mastery
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=9978; -- By Any Means Necessary
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10030; -- Recover the Bones
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10443; -- Helping the Cenarion Post
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=11330; -- Absholutely... Thish Will Work!
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12007; -- Sacrifices Must be Made
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12029; -- Seared Scourge
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=12470; -- Mystery of the Infinite
UPDATE `quest_offer_reward` SET `EmoteDelay2`=2000, `VerifiedBuild`=15595 WHERE `ID`=11218; -- Danger! Explosives!
UPDATE `quest_offer_reward` SET `RewardText`='$N!  It\'s you!  My regiment was ambushed on our way here.$B$BOur captain was slain, leaving me in command... until you got here, that is... sir!', `VerifiedBuild`=15595 WHERE `ID`=28561; -- Nahom Must Hold
UPDATE `quest_offer_reward` SET `RewardText`='$N!  Where have you been?$B$BAnyway... it\'s great to see you in one piece.', `VerifiedBuild`=15595 WHERE `ID`=14265; -- Your Instructor
UPDATE `quest_offer_reward` SET `RewardText`='$N! Is it true you led an assault against a twilight dragon?$B$BYou are truly a herald of the ancients!', `VerifiedBuild`=15595 WHERE `ID`=25795; -- Return to the Shrine
UPDATE `quest_offer_reward` SET `RewardText`='$N!!!  You ARE alive!$B$BI thought I was having dreams about the old days when I heard your voice...', `VerifiedBuild`=15595 WHERE `ID`=14336; -- Kill or Be Killed
UPDATE `quest_offer_reward` SET `RewardText`='$N!$B$BGenn... they\'ve taken Genn... they\'ve taken... our king!', `VerifiedBuild`=15595 WHERE `ID`=24672; -- Onwards and Upwards
UPDATE `quest_offer_reward` SET `RewardText`='$N!$B$BYou were able to earn the ancient\'s trust?$B$BWonderful! We are one step closer to taking back this mountain...', `VerifiedBuild`=15595 WHERE `ID`=25520; -- An Ancient Awakens
UPDATE `quest_offer_reward` SET `RewardText`='$N, it was astounding! Goldrinn himself appeared to free us, his white fur bright like the summer moon. Our cages collapsed and the vandals melted like wax under the kiss of his claws. He was beautiful, $N. Beautiful!', `VerifiedBuild`=15595 WHERE `ID`=25280; -- The Shrine Reclaimed
UPDATE `quest_offer_reward` SET `RewardText`='$N.  I\'ve heard much about you.$B$BI understand you were crucial in my family\'s survival during the outbreak in Gilneas City.', `VerifiedBuild`=15595 WHERE `ID`=14465; -- To Greymane Manor
UPDATE `quest_offer_reward` SET `RewardText`='$Ndamus?  Let us hope your parents brought you into this world with more than just a ridiculous name.', `VerifiedBuild`=15595 WHERE `ID`=25276; -- Your New Identity
UPDATE `quest_offer_reward` SET `RewardText`='<Chief Hawkwind holds the mane of Thornmantle over his head.>$B$BThe Chief of the Bristleback is slain. Greatmother Hawkwind\'s spirit has been avenged!', `VerifiedBuild`=15595 WHERE `ID`=14460; -- Rite of Honor
UPDATE `quest_offer_reward` SET `RewardText`='<Jadi kicks open one of the crates and picks up a curved dagger within. She immediately winces in pain.>$B$BAugh! Cursed - this metal is cursed - it bites!$B$B<When the dagger falls to the ground, it shatters, as if made of brittle glass.>$B$BWhat demented workmanship is this? $N, I\'ve never fought any foe like this before.', `VerifiedBuild`=15595 WHERE `ID`=25234; -- In the Rear With the Gear
UPDATE `quest_offer_reward` SET `RewardText`='<The Arch Druid inspects the seedlings.>$B$BThese seedlings have survived an apocalypse. Even a handful hold great power. Life always replenishes itself, often stronger than before.$B$BOnce the way is clear, we will use these to perform a miracle on this mountain, $N. You will see.', `VerifiedBuild`=15595 WHERE `ID`=25491; -- Durable Seeds
UPDATE `quest_offer_reward` SET `RewardText`='<Thrall\'s muscles strain as primal energy flows through him.  His eyes shift your way, acknowledging your arrival.>$B$BIt is good to see you, $N.', `VerifiedBuild`=15595 WHERE `ID`=27203; -- The Maelstrom
UPDATE `quest_offer_reward` SET `RewardText`='After filling it with liquid from the melons, you proceed to wash your eyes from the ancient font.$b$bUpon opening your eyes, you are able to see the spirits of ancient elves, still faithfully carrying out rituals to their goddess.', `VerifiedBuild`=15595 WHERE `ID`=14193; -- Nothing a Couple of Melons Won't Fix
UPDATE `quest_offer_reward` SET `RewardText`='Ah yes, yes... the secret strength of Nemesis, unearthed here in these caverns.$B$BWe know all that we need to know, $N. It is time to finish this.', `VerifiedBuild`=15595 WHERE `ID`=25915; -- The Strength of Tortolla
UPDATE `quest_offer_reward` SET `RewardText`='Ah, $N! I was hoping to see you out here.$B$BWhat, Omnuron calls this a \'fact-finding mission?\' Bah! Facts are best found on corpses.$B$BLet\'s do some damage.', `VerifiedBuild`=15595 WHERE `ID`=25740; -- Fact-Finding Mission
UPDATE `quest_offer_reward` SET `RewardText`='Alysra\'s decision might not have been the wisest, $N.  Yet there is little time to worry about that now.$B$BI bring important discoveries from the Emerald Dream.', `VerifiedBuild`=15595 WHERE `ID`=25578; -- Return to Nordrassil
UPDATE `quest_offer_reward` SET `RewardText`='Are you ready to set sail, $N?  Your people have been granted shelter in the lands of the kaldorei.$B$BDo not worry, $r.  Your people will get a chance to fight for Gilneas again.  This time, with the full strength of the Alliance.', `VerifiedBuild`=15595 WHERE `ID`=14434; -- Rut'theran Village
UPDATE `quest_offer_reward` SET `RewardText`='Brace yourself, $N.$B$BHere they come.', `VerifiedBuild`=15595 WHERE `ID`=14212; -- Sacrifices
UPDATE `quest_offer_reward` SET `RewardText`='By relieving Tortolla of his final burdens you have acquired for us a formidable ally... and the final piece of the puzzle.$B$BSteel yourself, $N. The most difficult part of our journey is to begin.$B$BWe will bring the fight to their stronghold.', `VerifiedBuild`=15595 WHERE `ID`=25653; -- The Ancients are With Us
UPDATE `quest_offer_reward` SET `RewardText`='By the wings of Aviana - you were born to fly, $N!$B$BQuickly, let\'s get back out there and hit them again...', `VerifiedBuild`=15595 WHERE `ID`=25544; -- Wave Two
UPDATE `quest_offer_reward` SET `RewardText`='Desecrate the Alliance\'s Elwynn Forest bonfire!', `VerifiedBuild`=15595 WHERE `ID`=11745; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `RewardText`='Desecrate the Horde\'s Hillsbrad Foothills bonfire!', `VerifiedBuild`=15595 WHERE `ID`=11776; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `RewardText`='Desecrate the Netherstorm bonfire!', `VerifiedBuild`=15595 WHERE `ID`=11759; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N!  You\'ve outdone yourself this time.', `VerifiedBuild`=15595 WHERE `ID`=25308; -- Seeds of Discord
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N.  Or should I say: \"$N\"damus?$B$BGive me a minute to read these.', `VerifiedBuild`=15595 WHERE `ID`=25296; -- Gather the Intelligence
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N.  Our troops will hear of your deeds.', `VerifiedBuild`=15595 WHERE `ID`=28483; -- Bleeding the Enemy
UPDATE `quest_offer_reward` SET `RewardText`='Excellent job, $N.  You might not think this adds up to much, but this might very well be the difference between life and death to one of our soldiers.', `VerifiedBuild`=15595 WHERE `ID`=28200; -- The Element of Supplies
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  I think I speak for everyone when I say the sooner we get out of here, the better.', `VerifiedBuild`=15595 WHERE `ID`=14463; -- Horses for Duskhaven
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  Our plan\'s almost come together.', `VerifiedBuild`=15595 WHERE `ID`=25314; -- Speech Writing for Dummies
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  We might win this one yet.', `VerifiedBuild`=15595 WHERE `ID`=25608; -- Slash and Burn
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N.  We shall soon claim victory in Hyjal.$B$BIt has been an honor to fight along your side.', `VerifiedBuild`=15595 WHERE `ID`=25550; -- Magma Monarch
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N. You\'ve turned out to be quite an asset to this garrison. It\'s time for you to train!', `VerifiedBuild`=15595 WHERE `ID`=28759; -- Lions for Lambs
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $N. You\'ve turned out to be quite an asset to this garrison. It\'s time for you to train!', `VerifiedBuild`=15595 WHERE `ID`=28769; -- Lions for Lambs
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $Ndamus.  I\'m having the servants you chose for me briefed on their new duties.', `VerifiedBuild`=15595 WHERE `ID`=25330; -- Waste of Flesh
UPDATE `quest_offer_reward` SET `RewardText`='Excellent work, $Ndamus.  We must show all would-be competitors that we are not ones to give up easily.', `VerifiedBuild`=15595 WHERE `ID`=25310; -- The Greater of Two Evils
UPDATE `quest_offer_reward` SET `RewardText`='Excellent, $N.  That should put a stop to the attacks once we finish these elementals off.', `VerifiedBuild`=15595 WHERE `ID`=25574; -- Flames from Above
UPDATE `quest_offer_reward` SET `RewardText`='Excellent, $N.  This will be a great weapon against the enemy forces.', `VerifiedBuild`=15595 WHERE `ID`=25472; -- The Flameseer's Staff
UPDATE `quest_offer_reward` SET `RewardText`='Excellent, $N.  We will make our way out of here soon enough.', `VerifiedBuild`=15595 WHERE `ID`=28105; -- Kavem the Callous
UPDATE `quest_offer_reward` SET `RewardText`='Forsaken!  Quick, $N!  We must mount a defense.', `VerifiedBuild`=15595 WHERE `ID`=14321; -- Invasion
UPDATE `quest_offer_reward` SET `RewardText`='Good job, $N.  Thanks to you, many Gilneans will live to see another day.', `VerifiedBuild`=15595 WHERE `ID`=14098; -- Evacuate the Merchant Square
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $N. There\'s a chance the forest will recover from this yet.$B$BNow, there\'s something else I need you to take care of for me...', `VerifiedBuild`=15595 WHERE `ID`=25492; -- Firebreak
UPDATE `quest_offer_reward` SET `RewardText`='Good work, $n.  Those beasts could have been a greater threat than the quilboar themselves, if we had not taken action now.', `VerifiedBuild`=15595 WHERE `ID`=14459; -- The Battleboars
UPDATE `quest_offer_reward` SET `RewardText`='Great job, $N.  We\'ve heard rumors of survivors further in the mountains.  Now we\'ll be able to send scouts there.', `VerifiedBuild`=15595 WHERE `ID`=24501; -- Queen-Sized Troubles
UPDATE `quest_offer_reward` SET `RewardText`='Great news, $N.  I\'ve sent the remaining militia to the shore to meet the Forsaken force head on.', `VerifiedBuild`=15595 WHERE `ID`=14366; -- Holding Steady
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Arathi Highlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11804; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Arathi Highlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11840; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Ashenvale flame.', `VerifiedBuild`=15595 WHERE `ID`=11805; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Ashenvale flame.', `VerifiedBuild`=15595 WHERE `ID`=11841; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Azuremyst Isle flame.', `VerifiedBuild`=15595 WHERE `ID`=11806; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Badlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11842; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Barrens flame.', `VerifiedBuild`=15595 WHERE `ID`=11859; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Blade\'s Edge Mountains flame.', `VerifiedBuild`=15595 WHERE `ID`=11807; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Blade\'s Edge Mountains flame.', `VerifiedBuild`=15595 WHERE `ID`=11843; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Blasted Lands flame.', `VerifiedBuild`=15595 WHERE `ID`=11808; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Bloodmyst Isle flame.', `VerifiedBuild`=15595 WHERE `ID`=11809; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Borean Tundra flame.', `VerifiedBuild`=15595 WHERE `ID`=13485; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Borean Tundra flame.', `VerifiedBuild`=15595 WHERE `ID`=13493; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Burning Steppes flame.', `VerifiedBuild`=15595 WHERE `ID`=11810; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Burning Steppes flame.', `VerifiedBuild`=15595 WHERE `ID`=11844; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Crystalsong Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=13491; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Crystalsong Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=13499; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Darkshore flame.', `VerifiedBuild`=15595 WHERE `ID`=11811; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Desolace flame.', `VerifiedBuild`=15595 WHERE `ID`=11812; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Desolace flame.', `VerifiedBuild`=15595 WHERE `ID`=11845; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Dragonblight flame.', `VerifiedBuild`=15595 WHERE `ID`=13487; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Dragonblight flame.', `VerifiedBuild`=15595 WHERE `ID`=13495; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Dun Morogh flame.', `VerifiedBuild`=15595 WHERE `ID`=11813; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Durotar flame.', `VerifiedBuild`=15595 WHERE `ID`=11846; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Duskwood flame.', `VerifiedBuild`=15595 WHERE `ID`=11814; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Dustwallow Marsh flame.', `VerifiedBuild`=15595 WHERE `ID`=11815; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Dustwallow Marsh flame.', `VerifiedBuild`=15595 WHERE `ID`=11847; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Elwynn Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=11816; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Eversong Woods flame.', `VerifiedBuild`=15595 WHERE `ID`=11848; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Feralas flame.', `VerifiedBuild`=15595 WHERE `ID`=11817; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Feralas flame.', `VerifiedBuild`=15595 WHERE `ID`=11849; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Ghostlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11850; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Grizzly Hills flame.', `VerifiedBuild`=15595 WHERE `ID`=13489; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Grizzly Hills flame.', `VerifiedBuild`=15595 WHERE `ID`=13497; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Hellfire Peninsula flame.', `VerifiedBuild`=15595 WHERE `ID`=11818; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Hellfire Peninsula flame.', `VerifiedBuild`=15595 WHERE `ID`=11851; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Hillsbrad Foothills flame.', `VerifiedBuild`=15595 WHERE `ID`=11853; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Hinterlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11826; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Hinterlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11860; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Howling Fjord flame.', `VerifiedBuild`=15595 WHERE `ID`=13488; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Howling Fjord flame.', `VerifiedBuild`=15595 WHERE `ID`=13496; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Loch Modan flame.', `VerifiedBuild`=15595 WHERE `ID`=11820; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Mulgore flame.', `VerifiedBuild`=15595 WHERE `ID`=11852; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Nagrand flame.', `VerifiedBuild`=15595 WHERE `ID`=11821; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Nagrand flame.', `VerifiedBuild`=15595 WHERE `ID`=11854; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Netherstorm flame.', `VerifiedBuild`=15595 WHERE `ID`=11830; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Netherstorm flame.', `VerifiedBuild`=15595 WHERE `ID`=11835; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Redridge Mountains flame.', `VerifiedBuild`=15595 WHERE `ID`=11822; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Shadowmoon Valley flame.', `VerifiedBuild`=15595 WHERE `ID`=11823; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Shadowmoon Valley flame.', `VerifiedBuild`=15595 WHERE `ID`=11855; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Sholazar Basin flame.', `VerifiedBuild`=15595 WHERE `ID`=13486; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Sholazar Basin flame.', `VerifiedBuild`=15595 WHERE `ID`=13494; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Silithus flame.', `VerifiedBuild`=15595 WHERE `ID`=11831; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Silithus flame.', `VerifiedBuild`=15595 WHERE `ID`=11836; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Silverpine Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=11584; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Stonetalon Mountains flame.', `VerifiedBuild`=15595 WHERE `ID`=11856; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Storm Peaks flame.', `VerifiedBuild`=15595 WHERE `ID`=13490; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Storm Peaks flame.', `VerifiedBuild`=15595 WHERE `ID`=13498; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Stranglethorn Vale flame.', `VerifiedBuild`=15595 WHERE `ID`=11832; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Stranglethorn Vale flame.', `VerifiedBuild`=15595 WHERE `ID`=11837; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Swamp of Sorrows flame.', `VerifiedBuild`=15595 WHERE `ID`=11857; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Tanaris flame.', `VerifiedBuild`=15595 WHERE `ID`=11833; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Tanaris flame.', `VerifiedBuild`=15595 WHERE `ID`=11838; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Teldrassil flame.', `VerifiedBuild`=15595 WHERE `ID`=11824; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Terokkar Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=11825; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Terokkar Forest flame.', `VerifiedBuild`=15595 WHERE `ID`=11858; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Tirisfal Glades flame.', `VerifiedBuild`=15595 WHERE `ID`=11862; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Western Plaguelands flame.', `VerifiedBuild`=15595 WHERE `ID`=11827; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Westfall flame.', `VerifiedBuild`=15595 WHERE `ID`=11583; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Wetlands flame.', `VerifiedBuild`=15595 WHERE `ID`=11828; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Winterspring flame.', `VerifiedBuild`=15595 WHERE `ID`=11834; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Winterspring flame.', `VerifiedBuild`=15595 WHERE `ID`=11839; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Zangarmarsh flame.', `VerifiedBuild`=15595 WHERE `ID`=11829; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Zangarmarsh flame.', `VerifiedBuild`=15595 WHERE `ID`=11863; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Zul\'Drak flame.', `VerifiedBuild`=15595 WHERE `ID`=13492; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Honor the Zul\'Drak flame.', `VerifiedBuild`=15595 WHERE `ID`=13500; -- Honor the Flame
UPDATE `quest_offer_reward` SET `RewardText`='Hyjal has been saved, $N.  And it\'s all thanks to you.', `VerifiedBuild`=15595 WHERE `ID`=25551; -- The Firelord
UPDATE `quest_offer_reward` SET `RewardText`='I am glad to have you here, $N.  We\'re surrounded by Forsaken on all sides and can use all the help we can get.', `VerifiedBuild`=15595 WHERE `ID`=24677; -- Flank the Forsaken
UPDATE `quest_offer_reward` SET `RewardText`='I am thankful, $N.  I will deliver my findings to our people.', `VerifiedBuild`=15595 WHERE `ID`=25321; -- Twilight Captivity
UPDATE `quest_offer_reward` SET `RewardText`='I can breathe a sigh of relief for now, $N.  The Shadow Council will be held off for the time being.$B$BThey are murderers and cowards and your display of courage will keep them at bay.', `VerifiedBuild`=15595 WHERE `ID`=10878; -- Before Darkness Falls
UPDATE `quest_offer_reward` SET `RewardText`='I knew we could count on you.  You\'ve done well, $N.', `VerifiedBuild`=15595 WHERE `ID`=24646; -- Take Back What's Ours
UPDATE `quest_offer_reward` SET `RewardText`='I need you to pull through, $N.  This dosage is strong enough to kill a horse.$B$BBut I know you.  I know what you\'re made of.  You will be fine.$B$BTrust me.  I know what you\'re going through.$B$BNow drink up and close your eyes.', `VerifiedBuild`=15595 WHERE `ID`=14375; -- Last Chance at Humanity
UPDATE `quest_offer_reward` SET `RewardText`='I thank you for what you\'ve done, $N.  You can count on my vote when High Council convenes.', `VerifiedBuild`=15595 WHERE `ID`=27738; -- The Pit of Scales
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Orsis was punished for not joining the forces of Deathwing.$B$BPrince Nadun has offered my people refuge in his city.  I must go there and tend the survivors.', `VerifiedBuild`=15595 WHERE `ID`=27519; -- Under the Choking Sands
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Our men and women will have a last good meal before they set off for battle.', `VerifiedBuild`=15595 WHERE `ID`=24675; -- Last Meal
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Our people will no longer suffer under that monstrosity\'s yoke.', `VerifiedBuild`=15595 WHERE `ID`=24674; -- Slaves to No One
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  These savages must be punished for what they\'ve done here.', `VerifiedBuild`=15595 WHERE `ID`=28502; -- The Bandit Warlord
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  This will make our prophetic visions that much clearer.', `VerifiedBuild`=15595 WHERE `ID`=27836; -- Stopping the Spread
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N.  Your fighting prowess is admirable.  You will be crucial to putting a halt to the elemental onslaught.', `VerifiedBuild`=15595 WHERE `ID`=25460; -- The Earth Rises
UPDATE `quest_offer_reward` SET `RewardText`='I thank you, $N. Those little bears are shaken up but they\'ll survive.$B$BAt least the ones that hit the mat.', `VerifiedBuild`=15595 WHERE `ID`=25462; -- The Bears Up There
UPDATE `quest_offer_reward` SET `RewardText`='I wish it could\'ve been avoided, $N.  Let us ensure this is resolved without further bloodshed.', `VerifiedBuild`=15595 WHERE `ID`=24592; -- Betrayal at Tempest's Reach
UPDATE `quest_offer_reward` SET `RewardText`='I\'ve been expecting you, $N.  Do not be alarmed.$B$BMy name is Belysra.  I am a priestess of the moon... a night elf.$B$BYou might not know my people, but the destinies of our two races have been linked since the Curse befell you.', `VerifiedBuild`=15595 WHERE `ID`=24578; -- The Blackwald
UPDATE `quest_offer_reward` SET `RewardText`='It is a great honor to meet you, $N!  I\'ve heard much about you.', `VerifiedBuild`=15595 WHERE `ID`=28198; -- The Weakest Link
UPDATE `quest_offer_reward` SET `RewardText`='It is done then, $N.  You are one of us now.', `VerifiedBuild`=15595 WHERE `ID`=24593; -- Neither Human Nor Beast
UPDATE `quest_offer_reward` SET `RewardText`='It is done! We\'ll seal this fiery hole up behind us and let the minions of the Twilight\'s Hammer discover the corpses we left behind. We couldn\'t have done it without you, $N!', `VerifiedBuild`=15595 WHERE `ID`=25600; -- Forgemaster Pyrendius
UPDATE `quest_offer_reward` SET `RewardText`='It\'s almost over, $N.  Only one obstacle remains between us and survival.', `VerifiedBuild`=15595 WHERE `ID`=24681; -- They Have Allies, But So Do We
UPDATE `quest_offer_reward` SET `RewardText`='It\'s done, $N.  The dead return to their slumber.', `VerifiedBuild`=15595 WHERE `ID`=24679; -- Patriarch's Blessing
UPDATE `quest_offer_reward` SET `RewardText`='It\'s good to see you again, $N.', `VerifiedBuild`=15595 WHERE `ID`=24680; -- Keel Harbor
UPDATE `quest_offer_reward` SET `RewardText`='It\'s good to see you made it, $N.  It looks like most everybody did.$B$BWe\'re not doing too bad so far for an emergency evacuation.', `VerifiedBuild`=15595 WHERE `ID`=24483; -- Stormglen
UPDATE `quest_offer_reward` SET `RewardText`='It\'s no use, $N!  They\'re not letting up.', `VerifiedBuild`=15595 WHERE `ID`=14093; -- All Hell Breaks Loose
UPDATE `quest_offer_reward` SET `RewardText`='Look, $N!  Look at what\'s become of Duskhaven!$B$BLook at what\'s become of the last safe place in Gilneas!', `VerifiedBuild`=15595 WHERE `ID`=14467; -- Alas, Gilneas!
UPDATE `quest_offer_reward` SET `RewardText`='Magistrix Erona told me you\'d be along quick enough, $N.  The Falthrien Academy to our west - the huge floating building with the ornate spires - is in bad shape.  You\'re going to be leading the effort to recapture it from one of the Wretched - a blood elf who has forever succumbed to their basest cravings.$B$BI hope you\'re ready to work.  This is not only going to be a lesson about danger, but also of what happens when you forsake the realities of who you are.', `VerifiedBuild`=15595 WHERE `ID`=8327; -- Report to Lanthan Perilon
UPDATE `quest_offer_reward` SET `RewardText`='More trials lay ahead, $n. I hope you\'re prepared.', `VerifiedBuild`=15595 WHERE `ID`=14458; -- Go to Adana
UPDATE `quest_offer_reward` SET `RewardText`='My children are safe!  You\'ve done a wonderful thing, $N.  I don\'t know how to thank you!', `VerifiedBuild`=15595 WHERE `ID`=14368; -- Save the Children!
UPDATE `quest_offer_reward` SET `RewardText`='No need to fill me in on the events in Orsis, $N.$B$BI\'ve heard about them already.  And about you.  Any enemy of Al\'Akir is a friend of mine.', `VerifiedBuild`=15595 WHERE `ID`=27631; -- The High Commander's Vote
UPDATE `quest_offer_reward` SET `RewardText`='Not bad, $N.  It\'s a good thing you\'re on our side.', `VerifiedBuild`=15595 WHERE `ID`=14369; -- Unleash the Beast
UPDATE `quest_offer_reward` SET `RewardText`='Oi, $N!  I was told I\'d have company soon.', `VerifiedBuild`=15595 WHERE `ID`=26247; -- Diplomacy First
UPDATE `quest_offer_reward` SET `RewardText`='Oi, this was a heavy one!  He nearly broke me gryphon\'s back!$B$BAre you ready to interrogate the ogre, $N?', `VerifiedBuild`=15595 WHERE `ID`=26250; -- On Second Thought, Take One Prisoner
UPDATE `quest_offer_reward` SET `RewardText`='So the harpies are tools of some sort of dragon - \"Sethria.\"$B$BBut what are the dragons doing to those eggs? And what\'s this \'special\' egg that Sethria wanted so badly?$B$BThis is beyond me, $N. I\'ve given a report to Skylord Omnuron - he\'ll know what to do next.', `VerifiedBuild`=15595 WHERE `ID`=25731; -- A Bird in Hand
UPDATE `quest_offer_reward` SET `RewardText`='So, it is true! You indeed carry lightning in your hands.$B$BYou are the chosen one, $N. You will be my champion, and carry my vengeance to realms where I cannot tread...', `VerifiedBuild`=15595 WHERE `ID`=25353; -- Lightning in a Bottle
UPDATE `quest_offer_reward` SET `RewardText`='Spectacular flying, $N! Their screeches of anguish echoed about this light-forsaken cavern.$B$BBut our work is not yet finished...', `VerifiedBuild`=15595 WHERE `ID`=25525; -- Wave One
UPDATE `quest_offer_reward` SET `RewardText`='Stay back! Don\'t make me...$B$BIs it you?  By the Light!  It\'s you, $N!', `VerifiedBuild`=15595 WHERE `ID`=14406; -- The Crowley Orchard
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  It will take some time, but I\'ll try to make sense of what we have.', `VerifiedBuild`=15595 WHERE `ID`=24495; -- Pieces of the Past
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  Let us hope this works.', `VerifiedBuild`=15595 WHERE `ID`=24602; -- Laid to Rest
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  We might yet save Iset.', `VerifiedBuild`=15595 WHERE `ID`=28145; -- Venomblood Antidote
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N.  We need all the power we can muster to keep Deepholm stable.', `VerifiedBuild`=15595 WHERE `ID`=27136; -- Elemental Energy
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. I worry that our actions here may be too little, too late, but nature always has a way of rebuilding itself that never ceases to amaze.', `VerifiedBuild`=15595 WHERE `ID`=25255; -- Harrying the Hunters
UPDATE `quest_offer_reward` SET `RewardText`='Thank you, $N. You\'ve given us the opportunity to try to reclaim the upper hand.', `VerifiedBuild`=15595 WHERE `ID`=25381; -- Fighting Fire With ... Anything
UPDATE `quest_offer_reward` SET `RewardText`='Thanks for stopping, $N.  Our carriage got hit pretty bad.$B$BThe one in front of us got it worse.', `VerifiedBuild`=15595 WHERE `ID`=24438; -- Exodus
UPDATE `quest_offer_reward` SET `RewardText`='That ought to get the dragon\'s attention, $N.', `VerifiedBuild`=15595 WHERE `ID`=26857; -- Abyssion's Minions
UPDATE `quest_offer_reward` SET `RewardText`='That should be enough to lure the beast, $N.', `VerifiedBuild`=15595 WHERE `ID`=26766; -- Big Game, Big Bait
UPDATE `quest_offer_reward` SET `RewardText`='That was nasty work, $N, but it had to be done.$B$BAnd if Aviana is truly to be resurrected, then perhaps your actions have enabled Blaithe to someday come back as well?$B$BNow let\'s see if we can contact our long lost guardian...', `VerifiedBuild`=15595 WHERE `ID`=25664; -- A Prayer and a Wing
UPDATE `quest_offer_reward` SET `RewardText`='That was some fancy bladework, $N!$B$BThere\'s one less threat for us to worry about in Hyjal.', `VerifiedBuild`=15595 WHERE `ID`=25761; -- Disassembly
UPDATE `quest_offer_reward` SET `RewardText`='The Forsaken are here in full strength, $N.  We barely have enough men to hold them back.', `VerifiedBuild`=15595 WHERE `ID`=14367; -- The Allens' Storm Cellar
UPDATE `quest_offer_reward` SET `RewardText`='The land is clearly still in great upheaval if it took such effort to calm.$B$BRemember this, $n.  Do not forget seeing the fate of those who would scar the Earth Mother.', `VerifiedBuild`=15595 WHERE `ID`=14491; -- The Restless Earth
UPDATE `quest_offer_reward` SET `RewardText`='The ocean, $N.  It swallowed everything... the land... the Forsaken... our men!', `VerifiedBuild`=15595 WHERE `ID`=14396; -- As the Land Shatters
UPDATE `quest_offer_reward` SET `RewardText`='The tower and surrounding areas should now be relatively secure, though only for the time being.  You have done well in providing us with a buffer of security, but we will need to reassert control over the entire isle if we are to survive here in the long run.  This will involve tackling much greater threats than errant mana wyrms and lynxes.$B$BTake this, $N - you will no doubt make good use of it for the tasks to come.', `VerifiedBuild`=15595 WHERE `ID`=8326; -- Unfortunate Measures
UPDATE `quest_offer_reward` SET `RewardText`='There is still great power present in his blood, $N.  I can sense it even now.$B$BYet there is also much corruption.  I am not sure we can salvage the Earthwarder\'s essence from this.', `VerifiedBuild`=15595 WHERE `ID`=26259; -- Blood of the Earthwarder
UPDATE `quest_offer_reward` SET `RewardText`='There you are, $N.  I\'ve been expecting you.$B$BI got word of your recovery and... wait -- do you feel that?', `VerifiedBuild`=15595 WHERE `ID`=14466; -- The King's Observatory
UPDATE `quest_offer_reward` SET `RewardText`='There you are, $Ndamus.  I\'ve been meaning to talk to you about something.$B$BI heard about the unfortunate incident that befell our poor friend, Okrog.$B$B<Mylva looks to her left, then her right.  She finally nods and shoots a sly wink in your direction.>$B$BYou might be a better pupil than I had thought.', `VerifiedBuild`=15595 WHERE `ID`=25601; -- Head of the Class
UPDATE `quest_offer_reward` SET `RewardText`='They couldn\'t be saved, $N.  The ancient curse that fell upon them is irrevocable.', `VerifiedBuild`=15595 WHERE `ID`=27755; -- The Curse of the Tombs
UPDATE `quest_offer_reward` SET `RewardText`='They... they\'ve stopped coming.$B$BNo, $N.  That\'s not a good thing.', `VerifiedBuild`=15595 WHERE `ID`=14222; -- Last Stand
UPDATE `quest_offer_reward` SET `RewardText`='They\'re moving supplies to Hyjal straight from the elemental planes? That explains so much.$B$BYou\'ve made Goldrinn proud by sealing that flamegate, $N, but there may be more portals to seal. You should check with the other shrines!', `VerifiedBuild`=15595 WHERE `ID`=25611; -- Return from the Firelands
UPDATE `quest_offer_reward` SET `RewardText`='This development is troubling, $N.  We must act swiftly.', `VerifiedBuild`=15595 WHERE `ID`=25424; -- Return to Alysra
UPDATE `quest_offer_reward` SET `RewardText`='This is great, $N.  I should be able to finish the repairs in no time.', `VerifiedBuild`=15595 WHERE `ID`=14404; -- Not Quite Shipshape
UPDATE `quest_offer_reward` SET `RewardText`='This is just the beginning, $N.  If Deathwing\'s minions can bury entire cities, we have little chance of defeating them through conventional means.', `VerifiedBuild`=15595 WHERE `ID`=27628; -- Send Word to Phaoris
UPDATE `quest_offer_reward` SET `RewardText`='This is the key, $N! With the seedlings you collected for me earlier, the animals you\'ve saved from around Hyjal, and the Heart of the Forest you\'ve just discovered, we can rejuvenate this land right from under the feet of Twilight\'s Hammer. Imagine their astonishment to see their work undone, as life triumphs over chaos...$B$BI will begin the ceremony at once!', `VerifiedBuild`=15595 WHERE `ID`=25372; -- Aessina's Miracle
UPDATE `quest_offer_reward` SET `RewardText`='This is the place.  Our scouts confirmed the presence of high-ranking Twilight officers nearby as well as potential trogg hunting parties.$B$BBe on the lookout, $N.', `VerifiedBuild`=15595 WHERE `ID`=27007; -- Silvermarsh Rendezvous
UPDATE `quest_offer_reward` SET `RewardText`='This is... most interesting.  And when I say interesting, I mean more disturbing than anything else.$B$BOur efforts to reassert control over the isle in the time following the destruction of the Sunwell have been a challenge.  I suspect that whatever foul source is corrupting the isle is at the heart of it all; this sliver may be of some aid in uncovering what\'s really going on.$B$BYou were wise to bring this to me, $N.  Take this as compensation for your diligence.  Thank you.', `VerifiedBuild`=15595 WHERE `ID`=8338; -- Tainted Arcane Sliver
UPDATE `quest_offer_reward` SET `RewardText`='Um... hi.  My name is Randis, and I guess you\'re looking after me?  You\'re an adventurer, like my mom and dad were.  I\'m happy to meet you.$B$BI hope we\'ll have a lot of fun together.  I have some things I\'d like to do, and the matron says you\'ll be like a big $G brother : sister; to me during this week.  I\'d like that a whole bunch, yes $G sir : ma\'am;.', `VerifiedBuild`=15595 WHERE `ID`=1468; -- Children's Week
UPDATE `quest_offer_reward` SET `RewardText`='Very well, it looks like it\'s time.  Stay and watch if you so please.', `VerifiedBuild`=15595 WHERE `ID`=28533; -- The High Council's Decision
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $N!  We held Nahom.', `VerifiedBuild`=15595 WHERE `ID`=28501; -- The Defense of Nahom
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $N! Aviana\'s Egg should soon be tucked safely in the boughs of her shrine.$B$BDo you think this means she\'ll really return to us?', `VerifiedBuild`=15595 WHERE `ID`=25764; -- Egg Hunt
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $N.  Thanks to you a good man has survived.', `VerifiedBuild`=15595 WHERE `ID`=14154; -- By the Skin of His Teeth
UPDATE `quest_offer_reward` SET `RewardText`='We did it, $N.  We\'ve started the evacuation.  If we leave soon we\'ll leave the Forsaken fleet in the dust.', `VerifiedBuild`=15595 WHERE `ID`=26706; -- Endgame
UPDATE `quest_offer_reward` SET `RewardText`='We have our answers, $N.  Let\'s report back.', `VerifiedBuild`=15595 WHERE `ID`=26254; -- Some Spraining to Do
UPDATE `quest_offer_reward` SET `RewardText`='We were bound to run into the Twilight\'s Hammer sooner or later, $N.  If they\'re behind this, it\'s quite likely that the World Pillar fragment is in their possession.', `VerifiedBuild`=15595 WHERE `ID`=26248; -- All Our Friends Are Dead
UPDATE `quest_offer_reward` SET `RewardText`='We\'re left with very few choices, $N.  What we do next will be a critical decision.', `VerifiedBuild`=15595 WHERE `ID`=14294; -- Time to Regroup
UPDATE `quest_offer_reward` SET `RewardText`='We\'ve given them everything we have... yet still they come.  Do not worry, $N.  We\'ll slay many more before today is over.', `VerifiedBuild`=15595 WHERE `ID`=14221; -- Never Surrender, Sometimes Retreat
UPDATE `quest_offer_reward` SET `RewardText`='Welcome to your first true test as a tauren.', `VerifiedBuild`=15595 WHERE `ID`=14449; -- The First Step
UPDATE `quest_offer_reward` SET `RewardText`='Well done! How does it feel?$B$BIt is challenging to master flight in this burning wasteland, but it is the only way.$B$BI hope you\'re ready for battle, $N...', `VerifiedBuild`=15595 WHERE `ID`=25523; -- Flight in the Firelands
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  Here\'s to hoping the trap performs as well when we try it on Abyssion.', `VerifiedBuild`=15595 WHERE `ID`=26771; -- Testing the Trap
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  The Twilight\'s Hammer is an evil that we must fight anywhere we find them.', `VerifiedBuild`=15595 WHERE `ID`=26251; -- Take No Prisoners
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  The expedition has already doomed itself.$B$BThere is no need for it to endanger the rest of the world as well.', `VerifiedBuild`=15595 WHERE `ID`=27761; -- A Disarming Distraction
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  The scout never had a chance.', `VerifiedBuild`=15595 WHERE `ID`=24616; -- Losing Your Tail
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  This will help us turn the tide against the enemy.', `VerifiedBuild`=15595 WHERE `ID`=25323; -- Flamebreaker
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  We cannot afford to lose any further ground in Hyjal.$B$BBy stopping Baron Geddon we will have dealt a huge blow to the enemy.', `VerifiedBuild`=15595 WHERE `ID`=25464; -- The Return of Baron Geddon
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  We\'ll make sure Krennan makes it out of the city alive.', `VerifiedBuild`=15595 WHERE `ID`=14293; -- Save Krennan Aranas
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $N.  You might be a bloody beast, but you\'re our beast.', `VerifiedBuild`=15595 WHERE `ID`=14382; -- Two By Sea
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n. Respect your prey, and the danger it carries, but never fear it. In fear, you become prey yourself.', `VerifiedBuild`=15595 WHERE `ID`=14456; -- Rite of Courage
UPDATE `quest_offer_reward` SET `RewardText`='What manner of creature are you?  You will leave the king\'s lands before...$B$BWait!  You are that $N I\'ve heard so much about.$B$BYou must pardon my lack of hospitality.  We have seen all manner of hostile intruders since the barrier around Uldum failed.', `VerifiedBuild`=15595 WHERE `ID`=27629; -- The Vizier's Vote
UPDATE `quest_offer_reward` SET `RewardText`='What? Blackhorn helped you combat the inferno but escaped in the process? That crafty weasel!$B$BIt\'s not your fault, $N. He\'d probably been plotting this the moment he saw the flames begin creeping up the mountain. We\'ll have to deal with him later.', `VerifiedBuild`=15595 WHERE `ID`=29066; -- Good News... and Bad News
UPDATE `quest_offer_reward` SET `RewardText`='Why thank you, $N.  I hope you didn\'t peek!$B$BWhere are your manners, dear?', `VerifiedBuild`=15595 WHERE `ID`=14399; -- Grandma's Lost It Alright
UPDATE `quest_offer_reward` SET `RewardText`='With the ritual completed, you are awarded a divine gift.$b$bYou can\'t help but to feel a great sense of honor as you receive one of Elune\'s boons.', `VerifiedBuild`=15595 WHERE `ID`=14357; -- To the Hilt!
UPDATE `quest_offer_reward` SET `RewardText`='Wonderful! Still sharp. A little blood on the fletching, but they\'ll fly true.$B$BThank you, $N. Our defense of Hyjal can continue.', `VerifiedBuild`=15595 WHERE `ID`=25901; -- Hyjal Recycling Program
UPDATE `quest_offer_reward` SET `RewardText`='Yes, $N!  Just like old times...$B$BI\'m going to have to work hard at not shooting you, but Krennan explained everything to us.', `VerifiedBuild`=15595 WHERE `ID`=14347; -- Hold the Line
UPDATE `quest_offer_reward` SET `RewardText`='Yes, $N.  I can feel the disruption in the river fading.$B$BYet, I feel the source of this taint still lingers.', `VerifiedBuild`=15595 WHERE `ID`=27837; -- Trespassers in the Water
UPDATE `quest_offer_reward` SET `RewardText`='You and me, $N.  We make a great team...$B$BIt\'s good to have you back.', `VerifiedBuild`=15595 WHERE `ID`=14348; -- You Can't Take 'Em Alone
UPDATE `quest_offer_reward` SET `RewardText`='You are a born leader, $N.  It\'ll be good to have you by our side when war comes to these lands.', `VerifiedBuild`=15595 WHERE `ID`=28201; -- Ploughshares to Swords
UPDATE `quest_offer_reward` SET `RewardText`='You are a valuable ally, $N.  We are one step closer to defeating the enemy.', `VerifiedBuild`=15595 WHERE `ID`=28480; -- Lieutenants of Darkness
UPDATE `quest_offer_reward` SET `RewardText`='You are as good as I remember, $N.  It is good to have you back.', `VerifiedBuild`=15595 WHERE `ID`=24627; -- At Our Doorstep
UPDATE `quest_offer_reward` SET `RewardText`='You continue to prove to be a valuable ally, $N.  ', `VerifiedBuild`=15595 WHERE `ID`=27520; -- Minions of Al'Akir
UPDATE `quest_offer_reward` SET `RewardText`='You continue to prove your prowess, $N.  At this rate Hyjal might survive this ordeal after all.', `VerifiedBuild`=15595 WHERE `ID`=25549; -- The Sanctum of the Prophets
UPDATE `quest_offer_reward` SET `RewardText`='You definitely got the ettin angry, $N.   I heard him myself.$B$BLet\'s hope this works.', `VerifiedBuild`=15595 WHERE `ID`=24472; -- Introductions Are in Order
UPDATE `quest_offer_reward` SET `RewardText`='You did it, $N!  Excellent!', `VerifiedBuild`=15595 WHERE `ID`=28486; -- Salhet's Gambit
UPDATE `quest_offer_reward` SET `RewardText`='You did it, $N.  That should take the wind out of their sails.', `VerifiedBuild`=15595 WHERE `ID`=14386; -- Leader of the Pack
UPDATE `quest_offer_reward` SET `RewardText`='You did well, $N.  I will take Fandral to Moonglade myself.$B$BHis prison will be far enough from the battlefront there.', `VerifiedBuild`=15595 WHERE `ID`=25325; -- Through the Dream
UPDATE `quest_offer_reward` SET `RewardText`='You did well, $N.  I\'ve a new target for you.', `VerifiedBuild`=15595 WHERE `ID`=25548; -- Might of the Firelord
UPDATE `quest_offer_reward` SET `RewardText`='You did what was necessary, $N.  I can tell you\'re the sort of $c I\'ll get along with well.', `VerifiedBuild`=15595 WHERE `ID`=26244; -- The Earth Claims All
UPDATE `quest_offer_reward` SET `RewardText`='You did what you could, $N.  With any luck a few others will find their way to shore.', `VerifiedBuild`=15595 WHERE `ID`=14395; -- Gasping for Breath
UPDATE `quest_offer_reward` SET `RewardText`='You have my thanks, $N.', `VerifiedBuild`=15595 WHERE `ID`=25531; -- Twilight Riot
UPDATE `quest_offer_reward` SET `RewardText`='You present me with the most difficult choice of my life, $N.', `VerifiedBuild`=15595 WHERE `ID`=24903; -- Vengeance or Survival
UPDATE `quest_offer_reward` SET `RewardText`='You think you\'re ready for the next step then, $Ndamus?$B$BLet\'s see what you\'re capable of.', `VerifiedBuild`=15595 WHERE `ID`=25291; -- Twilight Training
UPDATE `quest_offer_reward` SET `RewardText`='You were brave to face down Lycanthoth, $N. Like myself, he was a primal force of nature... but his origins were from a darker place.$B$BThose who birthed that beast reached deep into the blackness, channeling powers never intended for this world.$B$BCome, $c. Climb onto my back, and let us show these beasts the true face of ferocity!', `VerifiedBuild`=15595 WHERE `ID`=25273; -- Lycanthoth the Corruptor
UPDATE `quest_offer_reward` SET `RewardText`='You were right to come to me with this, $N.  This represents a great threat to us if we do not act swiftly and boldly.', `VerifiedBuild`=15595 WHERE `ID`=25644; -- The Twilight Egg
UPDATE `quest_offer_reward` SET `RewardText`='You\'re a peach, $N.  Thanks!', `VerifiedBuild`=15595 WHERE `ID`=14400; -- I Can't Wear This
UPDATE `quest_offer_reward` SET `RewardText`='You\'re all right, $N!  I\'ve been waiting for this day for a long time, it truly is great to see you friend.$B$BI\'ve heard of what you\'ve done and I\'m thankful... especially for Lorna -- she\'s all I\'ve left.  I will send for her right away.', `VerifiedBuild`=15595 WHERE `ID`=24617; -- Tal'doren, the Wild Home
UPDATE `quest_offer_reward` SET `RewardText`='You\'re here, $N.  Most everyone made it through, but now we\'re stuck here... surrounded by our own... dead!', `VerifiedBuild`=15595 WHERE `ID`=24678; -- Knee-Deep
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve arrived just in time, $N.  ', `VerifiedBuild`=15595 WHERE `ID`=28623; -- The Push Westward
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve arrived just in time, $N.  All our resources are tied up keeping the rift stable.$B$BWe need someone like you to help us recover the fragments of the World Pillar.', `VerifiedBuild`=15595 WHERE `ID`=27123; -- Deepholm, Realm of Earth
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve arrived just in time, $N.', `VerifiedBuild`=15595 WHERE `ID`=25317; -- Protect the World Tree
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve bought us a little time, $N, but we\'ve got even bigger problems to deal with now.', `VerifiedBuild`=15595 WHERE `ID`=28757; -- Beating Them Back!
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve bought us a little time, $N, but we\'ve got even bigger problems to deal with now.', `VerifiedBuild`=15595 WHERE `ID`=28767; -- Beating Them Back!
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done it again, $N.  The freed villagers are eager to help us against the Forsaken in any way they can.', `VerifiedBuild`=15595 WHERE `ID`=24575; -- Liberation Day
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done it again, $N.  You have my thanks.', `VerifiedBuild`=15595 WHERE `ID`=24468; -- Stranded at the Marsh
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  Almost everybody managed to make it through.  ', `VerifiedBuild`=15595 WHERE `ID`=24920; -- Slowing the Inevitable
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  But I fear the battle is far from over.', `VerifiedBuild`=15595 WHERE `ID`=25319; -- War on the Twilight's Hammer
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  The spiders are everywhere, however, and I\'m afraid we\'ve barely put a dent in their numbers.', `VerifiedBuild`=15595 WHERE `ID`=24484; -- Pest Control
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  We cannot allow the Twilight\'s Hammer spies this close to the world tree!', `VerifiedBuild`=15595 WHERE `ID`=25370; -- Inciting the Elements
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  We will use this to draw out the Twilight matriarch.', `VerifiedBuild`=15595 WHERE `ID`=25552; -- Brood of Evil
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve done well, $N.  You\'ve done more than could be asked of any Gilnean.$B$BWe\'re running low on ammunition.  It\'s time to regroup inside now.', `VerifiedBuild`=15595 WHERE `ID`=14218; -- By Blood and Ash
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve fought well, $n. We may yet be saved.', `VerifiedBuild`=15595 WHERE `ID`=14452; -- Rite of Strength
UPDATE `quest_offer_reward` SET `RewardText`='You\'ve succeeded, $Ndamus.  You\'re ready for the next step.', `VerifiedBuild`=15595 WHERE `ID`=25299; -- Mental Training: Speaking the Truth to Power
UPDATE `quest_offer_reward` SET `RewardText`='Your efforts in repairing the World Pillar are invaluable, $N.  Once the Temple of Earth\'s structure is stable again, the rift between the worlds will begin to stabilize.', `VerifiedBuild`=15595 WHERE `ID`=26876; -- The World Pillar Fragment
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=315; -- The Perfect Stout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=351; -- Find OOX-17/TN!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=475; -- A Troubling Breeze
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=743; -- Dangers of the Windfury
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=749; -- The Ravaged Caravan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=751; -- The Ravaged Caravan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=834; -- Winds in the Desert
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=835; -- Securing the Lines
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=927; -- The Moss-twined Heart
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=938; -- Mist
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=941; -- Planting the Heart
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=2278; -- The Platinum Discs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=2399; -- The Sprouted Fronds
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=3108; -- Etched Rune
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=3361; -- A Refugee's Quandary
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=6322; -- Michael Garrett
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=7787; -- Rise, Thunderfury!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8325; -- Reclaiming Sunstrider Isle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8334; -- Aggression
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8347; -- Aiding the Outrunners
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8350; -- Completing the Delivery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8463; -- Unstable Mana Crystals
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8472; -- Major Malfunction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8475; -- The Dead Scar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8491; -- Pelt Collection
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8892; -- Situation at Sunsail Anchorage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=8895; -- Delivery to the North Sanctum
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9035; -- Roadside Ambush
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9062; -- Soaked Pages
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9064; -- Taking the Fall
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9066; -- Swift Discipline
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9076; -- Wretched Ringleader
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9119; -- Malfunction at the West Sanctum
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9252; -- Defending Fairbreeze Village
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9256; -- Fairbreeze Village
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9309; -- The Missing Scout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9349; -- Ravager Egg Roundup
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9352; -- Darnassian Intrusions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9356; -- Smooth as Butter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9358; -- Ranger Sareyn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9361; -- Helboar, the Other White Meat
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9383; -- An Ambitious Plan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9385; -- Rampaging Ravagers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9390; -- In Search of Sedai
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9398; -- Deadly Predators
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9399; -- Cruel Taskmasters
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9417; -- The Arakkoa Threat
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9426; -- The Pools of Aggonar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9427; -- Cleansing the Waters
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9490; -- The Rock Flayer Matriarch
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9505; -- The Prophecy of Velen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9527; -- All That Remains
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9538; -- Learning the Language
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9539; -- Totem of Coo
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9540; -- Totem of Tikti
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9541; -- Totem of Yor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9542; -- Totem of Vark
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9550; -- A Map to Where?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9558; -- The Longbeards
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9559; -- Stillpine Hold
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9560; -- Beasts of the Apocalypse!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9561; -- Nolkai's Words
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9564; -- Gurf's Dignity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9565; -- Search Stillpine Hold
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9566; -- Blood Crystals
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9570; -- The Kurken is Lurkin'
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9571; -- The Kurken's Hide
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9573; -- Chieftain Oomooroo
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9578; -- Searching for Galaen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9616; -- Bandits!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9620; -- The Missing Survey Team
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9623; -- Coming of Age
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9625; -- Elekks Are Serious Business
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9644; -- Nightbane
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9649; -- Ysera's Tears
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9669; -- The Missing Expedition
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9682; -- The Hopeless Ones...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9688; -- Into the Dream
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9693; -- What Argus Means to Me
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9704; -- Slain by the Wretched
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9705; -- Package Recovery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9716; -- Disturbance at Umbrafen Lake
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9718; -- As the Crow Flies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9728; -- A Warm Welcome
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9730; -- Leader of the Darkcrest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9741; -- Critters of the Void
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9747; -- The Umbrafen Tribe
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9752; -- Escape from Umbrafen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9753; -- What We Know...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9761; -- Clearing the Way
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9788; -- A Damp, Dark Place
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9798; -- Blood Elf Plans
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9802; -- Plants of Zangarmarsh
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9831; -- Entry Into Karazhan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9857; -- Talbuk Mastery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9858; -- Talbuk Mastery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9859; -- Talbuk Mastery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9861; -- The Howling Wind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9862; -- Murkblood Corrupters
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9894; -- Safeguarding the Watchers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9895; -- The Dying Balance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9951; -- It's Watching You!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9957; -- What's Wrong at Cenarion Thicket?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9968; -- Strange Energy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9971; -- Clues in the Thicket
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=9979; -- Wind Trader Lathrai
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10047; -- The Path of Glory
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10055; -- Waste Not, Want Not
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10058; -- An Old Gift
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10064; -- Talk to the Hand
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10065; -- Cutting a Path
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10078; -- Laying Waste to the Unwanted
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10096; -- Saving the Sporeloks
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10112; -- A Personal Favor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10134; -- Crimson Crystal Clue
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10140; -- Journey to Honor Hold
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10141; -- The Legion Reborn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10142; -- The Path of Anguish
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10143; -- Expedition Point
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10144; -- Disrupt Their Reinforcements
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10146; -- Mission: The Murketh and Shaadraz Gateways
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10160; -- Know your Enemy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10161; -- In Case of Emergency...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10163; -- Mission: The Abyssal Shelf
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10200; -- Return to Thalodien
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10227; -- I See Dead Draenei
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10228; -- Ezekiel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10254; -- Force Commander Danath
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10288; -- Arrival in Outland
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10303; -- The Blood Elves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10330; -- Shutting Down Manaforge Coruu
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10340; -- Shatter Point
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10344; -- Wing Commander Gryphongar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10349; -- The Earthbinder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10367; -- A Traitor Among Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10368; -- The Dreghood Elders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10369; -- Arzeth's Demise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10382; -- Go to the Front
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10394; -- Disruption - Forge Camp: Mageddon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10395; -- The Dark Missive
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10396; -- Enemy of my Enemy...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10397; -- Invasion Point: Annihilator
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10419; -- Arcane Tomes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10478; -- More Warbeads!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10482; -- Fel Orc Scavengers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10483; -- Ill Omens
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10484; -- Cursed Talismans
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10485; -- Warlord of the Bleeding Hollow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10622; -- Proof of Allegiance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10628; -- Akama
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10685; -- The Ashtongue Corruptors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10840; -- The Tomb of Lights
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10842; -- Vengeful Souls
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10852; -- Missing Friends
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10863; -- Secrets of the Arakkoa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10869; -- Thin the Flock
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10873; -- Taken in the Night
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10877; -- The Dread Relic
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10880; -- Cabal Orders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10881; -- The Shadow Tomb
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10887; -- Escaping the Tomb
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10895; -- Zeth'Gor Must Burn!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10903; -- Return to Honor Hold
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10909; -- Fel Spirits
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10913; -- An Improper Burial
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10916; -- Digging for Prayer Beads
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10922; -- Digging Through Bones
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10929; -- Fumping
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10930; -- The Big Bone Worm
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10935; -- The Exorcism of Colonel Jules
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=10936; -- Trollbane is Looking for You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11050; -- Accepting All Eggs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11154; -- Scare the Guano Out of Them!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11157; -- The Clutches of Evil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11182; -- Root Causes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11187; -- Mage-Lieutenant Malister
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11199; -- Report to Scout Knowles
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11202; -- Mission: Eternal Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11221; -- Reports from the Field
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11224; -- Send Them Packing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11231; -- Of Keys and Cages
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11235; -- Dealing With Gjalerbron
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11237; -- Gjalerbron Attack Plans
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11238; -- The Frost Wyrm and its Master
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11239; -- In Service to the Light
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11240; -- Leader of the Deranged
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11245; -- Towers of Certain Doom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11246; -- Gruesome, But Necessary
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11247; -- Burn Skorn, Burn!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11248; -- Operation: Skornful Wrath
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11249; -- Stop the Ascension!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11250; -- All Hail the Conqueror of Skorn!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11251; -- Fresh Legs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11253; -- Sniff Out the Enemy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11273; -- The Human League
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11274; -- Zedd's Probably Dead
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11282; -- A Lesson in Fear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11283; -- Baleheim Bodycount
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11288; -- The Shining Light
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11291; -- To Westguard Keep!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11292; -- Preying Upon the Weak
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11305; -- A Tailor-Made Formula
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11308; -- Time for Cleanup
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11309; -- Parts for the Job
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11313; -- Spirits of the Ice
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11316; -- Spawn of the Twisted Glade
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11319; -- Seeds of the Blacksouled Keepers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11322; -- The Cleansing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11323; -- In Worg's Clothing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11325; -- In Worg's Clothing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11326; -- Alpha Worg
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11327; -- Mission: Package Retrieval
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11328; -- Mission: Forsaken Intel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11331; -- You Tell Him ...Hic!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11332; -- Mission: Plague This!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11346; -- The Book of Runes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11348; -- The Rune of Command
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11349; -- Mastering the Runes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11355; -- March of the Giants
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11358; -- The Lodestone
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11359; -- Demolishing Megalith
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11391; -- Steel Gate Patrol
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11406; -- Everything Must Be Ready
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11414; -- Brother Betrayers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11415; -- Brother Betrayers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11416; -- Eyes of the Eagle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11417; -- Eyes of the Eagle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11421; -- It Goes to 11...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11422; -- Trident of the Son
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11427; -- Meet Lieutenant Icehammer...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11428; -- Keeper Witherleaf
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11429; -- Drop It then Rock It!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11430; -- Harpoon Master Yavus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11432; -- Sleeping Giants
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11434; -- Forgotten Treasure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11436; -- Let's Go Surfing Now
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11452; -- The Slumbering King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11455; -- The Fragrance of Money
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11456; -- Feeding the Survivors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11457; -- Arming Kamagua
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11458; -- Avenge Iskaal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11459; -- Zeh'gehn Sez
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11464; -- Gambling Debt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11466; -- Jack Likes His Drink
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11467; -- Dead Man's Debt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11468; -- Falcon Versus Hawk
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11469; -- Swabbin' Soap
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11471; -- The Jig is Up
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11472; -- The Way to His Heart...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11473; -- A Traitor Among Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11476; -- A Carver and a Croaker
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11479; -- "Crowleg" Dan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11480; -- Meet Number Two
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11483; -- We Can Rebuild It
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11484; -- We Have the Technology
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11485; -- Iron Rune Constructs and You: Rocket Jumping
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11489; -- Iron Rune Constructs and You: Collecting Data
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11491; -- Iron Rune Constructs and You: The Bluff
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11494; -- Lightning Infused Relics
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11495; -- The Delicate Sound of Thunder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11501; -- News From the East
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11504; -- The Dead Rise!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11507; -- Elder Atuik and Kamagua
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11508; -- Grezzix Spindlesnap
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11509; -- Street "Cred"
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11510; -- "Scoodles"
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11511; -- The Staff of Storm's Fury
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11512; -- The Frozen Heart of Isuldof
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11519; -- The Lost Shield of the Aesirites
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11527; -- Mutiny on the Mercy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11529; -- Sorlof's Booty
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11530; -- The Shield of the Aesirites
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11548; -- Your Continued Support
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11557; -- Exalted Among All Combatants
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11567; -- The Ancient Armor of the Kvaldir
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11568; -- A Return to Resting
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11572; -- Return to Atuik
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11580; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11581; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11672; -- Enlistment Day
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11727; -- A Time for Heroes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11731; -- Torch Tossing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11732; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11734; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11735; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11736; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11737; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11738; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11739; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11740; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11741; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11742; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11743; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11744; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11746; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11747; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11749; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11750; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11751; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11752; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11753; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11754; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11755; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11756; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11757; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11758; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11760; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11761; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11762; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11763; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11764; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11765; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11766; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11767; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11768; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11769; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11770; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11771; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11772; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11773; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11774; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11775; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11777; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11778; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11779; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11780; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11781; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11782; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11783; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11784; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11786; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11787; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11789; -- A Soldier in Need
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11791; -- Notify Arlos
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11797; -- The Siege
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11799; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11800; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11801; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11802; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11803; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11886; -- Unusual Activity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11889; -- Death From Above
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11891; -- An Innocent Disguise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11897; -- Plug the Sinkholes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11901; -- Military?  What Military?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11902; -- Pernicious Evidence
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11905; -- Postponing the Inevitable
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11911; -- Quickening
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11915; -- Playing with Fire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11920; -- Cultists Among Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11922; -- Torch Tossing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11928; -- Farshire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11945; -- Preparing for the Worst
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11954; -- Striking Back
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11958; -- Let Nothing Go To Waste
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11959; -- Slay Loguhn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11960; -- Planning for the Future
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11966; -- Incense for the Festival Scorchlings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11971; -- The Spinner of Summer Tales
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11973; -- Prisoner of War
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11981; -- Find Kurun!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11982; -- Raining Down Destruction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11984; -- Filling the Cages
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11985; -- Into the Breach
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11986; -- The Damaged Journal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11988; -- The Runic Keystone
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11989; -- Truce?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11990; -- Vial of Visions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11991; -- Subject to Interpretation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11993; -- The Runic Prophecies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=11998; -- Softening the Blow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12002; -- Brothers in Battle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12003; -- Uncovering the Tunnels
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12009; -- Tua'kea's Crab Traps
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12010; -- The Fate of Orlond
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12011; -- Signs of Big Watery Trouble
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12012; -- Inform the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12014; -- Steady as a Rock?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12016; -- The Bait
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12017; -- Meat on the Hook
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12028; -- Spiritual Insight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12030; -- Elder Mana'loa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12031; -- Freedom for the Lingering
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12032; -- Conversing With the Depths
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12042; -- Heart of the Ancients
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12052; -- Harp on This!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12068; -- Voices From the Dust
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12070; -- Rallying the Troops
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12074; -- An Expedient Ally
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12075; -- Slim Pickings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12076; -- Messy Business
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12077; -- Apply This Twice A Day
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12078; -- Worm Wrangler
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12079; -- Stomping Grounds
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12080; -- Really Big Worm
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12081; -- Gavrock
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12082; -- Dun-da-Dun-tah!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12093; -- Runes of Compulsion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12094; -- Latent Power
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12099; -- Free at Last
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12105; -- Descent into Darkness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12106; -- Search Indu'le Village
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12109; -- Report to Gryan Stoutmantle... Again
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12111; -- Where the Wild Things Roam
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12112; -- Stiff Negotiations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12113; -- Nice to Meat You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12114; -- Therapy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12116; -- It Takes Guts....
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12120; -- Drak'aguul's Mallet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12121; -- See You on the Other Side
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12128; -- Check Up on Raegar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12129; -- The Perfect Plan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12130; -- Why Fabricate When You Can Appropriate?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12131; -- We Have the Power
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12134; -- Sasha's Hunt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12137; -- Chill Out, Mon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12138; -- ... Or Maybe We Don't
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12141; -- A Diplomatic Mission
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12148; -- One of a Kind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12149; -- Mighty Magnataur
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12150; -- Reclusive Runemaster
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12151; -- Wanton Warlord
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12153; -- The Iron Thane and His Anvil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12154; -- Blackout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12158; -- Hollowstone Mine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12159; -- Souls at Unrest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12160; -- A Name from the Past
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12161; -- Ruuna the Blind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12164; -- Hour of the Worg
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12165; -- An Intriguing Plan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12176; -- A Minor Substitution
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12177; -- Jun'ik's Coverup
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12178; -- Delivery to Krenna
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12180; -- The Captive Prospectors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12183; -- Looking the Part
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12184; -- Cultivating an Image
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12185; -- Put on Your Best Face for Loken
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12190; -- Say Hello to My Little Friend
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12204; -- In the Name of Loken
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12210; -- Troll Season!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12212; -- Replenishing the Storehouse
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12215; -- Them or Us!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12216; -- Take Their Rear!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12217; -- Eagle Eyes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12219; -- The Failed World Tree
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12220; -- A Dark Influence
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12222; -- Secrets of the Flamebinders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12223; -- Thinning the Ranks
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12225; -- Mmm... Amberseeds!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12226; -- Just Passing Through
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12227; -- Doing Your Duty
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12234; -- Need to Know
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12236; -- Ursoc, the Bear God
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12241; -- Destroy the Sapling
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12255; -- The Thane of Voldrune
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12261; -- No Place to Run
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12265; -- Defiling the Defilers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12266; -- Tales of Destruction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12267; -- Neltharion's Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12279; -- A Bear of an Appetite
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12292; -- Local Support
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12293; -- Close the Deal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12294; -- A Tentative Pact
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12295; -- An Exercise in Diplomacy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12299; -- Northern Hospitality
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12300; -- Test of Mettle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12302; -- Words of Warning
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12307; -- Wolfsbane Root
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12308; -- Escape from Silverbrook
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12310; -- A Swift Response
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12327; -- Out of Body Experience
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12328; -- Ruuna's Request
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12329; -- Fate and Coincidence
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12330; -- Anatoly Will Talk
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12372; -- Defending Wyrmrest Temple
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12411; -- A Sister's Pledge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12413; -- Attack on Silverbrook
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12414; -- Mounting Up
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12422; -- Tactical Clemency
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12423; -- Mikhail's Journal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12424; -- Gorgonna
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12428; -- The Conquest Pit: Mad Furbolg Fighting
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12429; -- The Conquest Pit: Blood and Metal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12430; -- The Conquest Pit: Death Is Likely
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12431; -- The Conquest Pit: Final Showdown
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12435; -- Report to Lord Afrasastrasz
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12444; -- Blackriver Skirmish
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12447; -- The Obsidian Dragonshrine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12453; -- Eyes Above
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12459; -- That Which Creates Can Also Destroy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12471; -- Cruelty of the Kvaldir
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12482; -- Against Nifflevar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12483; -- Shimmercap Stew
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12484; -- Scourgekabob
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12497; -- Galakrond and the Scourge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12498; -- On Ruby Wings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12517; -- Rogues Deck
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12542; -- The Call Of The Crusade
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12545; -- The Cleansing Of Jintha'kalar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12557; -- Lab Work
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12565; -- The Blessing of Zim'Abwa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12566; -- Help for Camp Winterhoof
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12606; -- Cocooned!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12615; -- The Blessing of Zim'Torga
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12628; -- To Speak With Har'koa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12631; -- An Invitation, of Sorts...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12632; -- But First My Offspring
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12639; -- The Frozen Earth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12642; -- Spirit of Rhunok
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12646; -- My Prophet, My Enemy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12647; -- An End to the Suffering
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12653; -- Back to Har'koa
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12655; -- The Blessing of Zim'Rhuk
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12661; -- Infiltrating Voltarus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12664; -- Dark Horizon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12665; -- I Sense a Disturbance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12666; -- Preparations for the Underworld
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12667; -- Seek the Wind Serpent Goddess
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12668; -- Foundation for Revenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12669; -- So Far, So Bad
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12672; -- Setting the Stage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12674; -- Hell Hath a Fury
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12675; -- One Last Thing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12676; -- Sabotage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12677; -- Hazardous Materials
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12684; -- Blood of a Dead God
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12686; -- Zero Tolerance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12690; -- Fuel for the Fire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12710; -- Disclosure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12712; -- The Key of Warlord Zol'Maz
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12713; -- Betrayal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12729; -- The Gods Have Spoken
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12730; -- Convocation at Zol'Heb
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12790; -- Learning to Leave and Return: the Magical Way
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12795; -- Taking a Stand
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12799; -- Siphoning the Spirits
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12802; -- My Heart is in Your Hands
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12831; -- Only Partly Forgotten
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12841; -- The Crone's Bargain
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12843; -- They Took Our Men!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12844; -- Equipment Recovery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12846; -- Leave No Goblin Behind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12859; -- This Just In: Fire Still Hot!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12861; -- Trolls Is Gone Crazy!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12883; -- Orders From Drakuru
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12886; -- The Drakkensryd
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12894; -- Crusader Forward Camp
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12900; -- Making a Harness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12902; -- In Search Of Answers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12904; -- Light Won't Grant Me Vengeance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12905; -- Mildred the Cruel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12906; -- Discipline
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12907; -- Examples to be Made
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12908; -- A Certain Prisoner
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12909; -- The Nose Knows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12915; -- Mending Fences
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12921; -- A Change of Scenery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12922; -- The Refiner's Fire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12925; -- Aberrations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12942; -- Off With Their Black Wings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12953; -- Valkyrion Must Burn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12956; -- A Spark of Hope
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12966; -- You Can't Miss Him
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12967; -- Battling the Elements
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12968; -- Yulda's Folly
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12969; -- Is That Your Goblin?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12970; -- The Hyldsmeet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12971; -- Taking on All Challengers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12972; -- You'll Need a Bear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12977; -- Blowing Hodir's Horn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12981; -- Hot and Cold
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12983; -- The Last of Her Kind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12989; -- The Slithering Darkness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12994; -- Spy Hunter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12996; -- The Warm-Up 
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=12997; -- Into the Pit
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13005; -- The Earthen Oath
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13006; -- Polishing the Helm
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13009; -- A New Beginning
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13035; -- Loken's Lackeys
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13036; -- Honor Above All Else
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13046; -- Feeding Arngrim
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13050; -- Veranus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13051; -- Territorial Trespass
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13054; -- The Missing Tracker
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13055; -- Cave Medicine
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13056; -- There's Always Time for Revenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13057; -- The Terrace of the Makers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13061; -- Prepare for Glory
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13062; -- Lok'lira's Parting Gift
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13064; -- Sibling Rivalry
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13068; -- A Tale of Valor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13075; -- The Boon of Remulos
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13079; -- The Boon of Alexstrasza
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13081; -- The Will of the Naaru
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13082; -- The Boon of A'dal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13086; -- The Last Line Of Defense
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13129; -- Head Games
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13187; -- The Faceless Ones
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13226; -- Judgment Day Comes!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13416; -- The Library Console
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13422; -- Maintaining Discipline
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13424; -- Back to the Pit
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13425; -- The Aberrations Must Die
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13440; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13441; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13442; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13443; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13444; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13445; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13446; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13447; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13449; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13450; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13451; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13453; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13454; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13455; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13457; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13458; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13559; -- Hodir's Tribute
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13595; -- Of Their Own Design
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13631; -- All Is Well That Ends Well
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13634; -- The Black Knight of Silverpine?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13643; -- The Stories Dead Men Tell
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13677; -- Learning The Reins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13833; -- Blood Is Thicker
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13834; -- Dangerously Delicious
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13845; -- Sealed Vial of Poison
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13868; -- Corrupting Influence?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13919; -- A Trip to the Moonwell
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=13954; -- The Dragon Queen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14069; -- Good Help is Hard to Find
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14070; -- Do it Yourself
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14071; -- Rolling with my Homies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14075; -- Trouble in the Mines
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14078; -- Lockdown!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14091; -- Something's Amiss
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14094; -- Salvage the Supplies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14099; -- Royal Orders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14110; -- The New You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14115; -- Pirate Party Crashers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14116; -- The Uninvited Guest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14120; -- A Bazillion Macaroons?!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14121; -- Robbing Hoods
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14122; -- The Great Bank Heist
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14123; -- Waltz Right In
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14124; -- Liberate the Kaja'mite
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14125; -- 447
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14126; -- Life Savings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14138; -- Taking Care of Business
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14153; -- Life of the Party
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14157; -- Old Divisions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14159; -- The Rebel Lord's Arsenal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14204; -- From the Shadows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14214; -- Message to Greymane
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14233; -- Orcs Can Write?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14241; -- Get to the Gyrochoppa!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14266; -- Charge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14280; -- The Winds Know Your Name... Apparently
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14283; -- Moonfire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14286; -- Safety in Numbers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14291; -- Safety in Numbers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14313; -- Among Humans Again
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14320; -- In Need of Ingredients
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14358; -- Ten Pounds of Flesh
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14359; -- Blessings From Above
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14397; -- Evacuation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14398; -- Grandma Wahl
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14401; -- Grandma's Cat
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14403; -- The Hayward Brothers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14405; -- Escape By Sea
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14412; -- Washed Up
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14416; -- The Hungry Ettin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14455; -- Stop the Thorncallers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=14461; -- Feed of Evil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=20440; -- Poison Water
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24469; -- Hold the Line!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24474; -- First Things First: We're Gonna Need Some Beer
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24475; -- All the Other Stuff
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24488; -- The Replacements
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24493; -- Don't Forget About Us
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24502; -- Necessary Roughness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24503; -- Fourth and Goal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24520; -- Give Sassy the News
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24567; -- Report for Tryouts
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24628; -- Preparations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24673; -- Return to Stormglen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24676; -- Push Them Out
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24817; -- A Goblin in Shark's Clothing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24852; -- Our Tribe, Imprisoned
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24858; -- Bilgewater Cartel Represent
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24902; -- The Hunt For Sylvanas
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24904; -- The Battle for Gilneas City
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24930; -- While You're At It
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24931; -- Gazer Tag
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24932; -- Cutting Losses
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24933; -- Chicken of the Desert
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24951; -- A Great Idea
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24953; -- Just Trying to Kill Some Bugs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24959; -- Fresh out of the Grave
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24971; -- Assault on the Rotbrain Encampment
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24972; -- Vital Intelligence
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24977; -- Johaan's Experiment
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24982; -- The New Forsaken
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24989; -- Return to the Magistrate
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=24999; -- Planting the Seed of Fear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25003; -- The Family Crypt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25004; -- The Mills Overrun
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25037; -- Crab Fishin'
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25048; -- Seaside Salvage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25052; -- Dead Man's Chest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25053; -- To The Ground!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25061; -- Land's End
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25064; -- Moraya
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25090; -- A Putrid Task
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25091; -- Sandsorrow Watch
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25098; -- The Warchief Wants You
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25110; -- Kaja'Cola Gives You IDEAS! (TM)
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25125; -- Light at the End of the Tunnel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25166; -- Captain Dreadbeard
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25204; -- Release the Valves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25206; -- Ignoring the Warnings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25207; -- Good-bye, Sweet Oil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25223; -- Trial By Fire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25224; -- In Bloom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25233; -- End of the Supply Line
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25262; -- Skull Rock
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25268; -- The Voice of Goldrinn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25271; -- Goldrinn's Ferocity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25274; -- Signed in Blood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25278; -- Cleaning House
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25294; -- Walking the Dog
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25297; -- From the Mouth of Madness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25298; -- Free Your Mind, the Rest Follows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25300; -- The Eye of Twilight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25301; -- Mastering Puppets
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25303; -- Elementary!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25309; -- Spiritual Training: Mercy is for the Weak
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25311; -- Twilight Territory
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25312; -- Return to Duskwhisper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25315; -- Graduation Speech
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25316; -- As Hyjal Burns
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25320; -- The Captured Scout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25324; -- A Prisoner of Interest
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25328; -- Gar'gol's Gotta Go
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25332; -- Get Me Outta Here!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25352; -- Sweeping the Shelf
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25382; -- Disrupting the Rituals
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25385; -- Save the Wee Animals
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25389; -- A Taste For Tail
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25392; -- Oh, Deer!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25404; -- If You're Not Against Us...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25405; -- Rest For the Weary
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25408; -- Seeds of Their Demise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25411; -- A New Master
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25412; -- The Name Never Spoken
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25428; -- Black Heart of Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25430; -- Emerald Allies
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25473; -- Kaja'Cola
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25490; -- Smashing Through Ashes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25493; -- Fresh Bait
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25494; -- A Champion's Collar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25496; -- Grudge Match
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25499; -- Agility Training: Run Like Hell!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25502; -- Prepping the Soil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25507; -- Hell's Shells
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25509; -- Physical Training: Forced Labor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25510; -- Tortolla Speaks
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25514; -- Breaking the Bonds
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25519; -- Children of Tortolla
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25553; -- Death to the Broodmother
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25554; -- Secrets of the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25555; -- The Gatekeeper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25560; -- Egg Wave
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25575; -- Forged of Shadow and Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25576; -- Rage of the Wolf Ancient
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25577; -- Crushing the Cores
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25584; -- The Return of the Ancients
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25597; -- Commander Jarod Shadowsong
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25599; -- Cindermaul, the Portal Master
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25614; -- The Only Way Down is in a Body Bag
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25615; -- Return to Stardust
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25618; -- Into the Maw!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25621; -- Field Test: Gnomecorder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25622; -- Burn, Baby, Burn!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25630; -- The Fires of Mount Hyjal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25638; -- A Desperate Plea
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25646; -- Windshear Mine Cleanup
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25647; -- Illegible Orc Letter
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25655; -- The Wormwing Problem
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25656; -- Scrambling for Eggs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25659; -- Not Soon Forgotten
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25663; -- An Offering for Aviana
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25665; -- A Plea From Beyond
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25729; -- Gerenzo the Traitor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25739; -- If the Horde Don't Get You...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25746; -- Sethria's Brood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25758; -- A Gap in Their Armor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25763; -- The Codex of Shadows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25776; -- Sethria's Demise
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25806; -- They Put the Assass in... Never Mind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25807; -- An Ancient Reborn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25809; -- Leave No Man Behind! 
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25810; -- The Hatchery Must Burn
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25830; -- The Last Living Lorekeeper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25832; -- Return to Aviana
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25838; -- Help from Steelgrill's Depot
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25842; -- Firefight
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25843; -- Tortolla's Revenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25881; -- Lost Wardens
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25886; -- Pressing the Advantage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25899; -- Breakthrough
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25904; -- The Hammer and the Key
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25906; -- The Third Flamegate
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25910; -- The Time for Mercy has Passed
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25923; -- Finish Nemesis
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25928; -- Tortolla's Triumph
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25930; -- Ascending the Vale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25940; -- Last Stand at Whistling Grove
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25990; -- Breaking Through
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=25993; -- Body Blows
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26000; -- Spelunking
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26088; -- Here Fishie Fishie
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26092; -- Orako's Report
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26126; -- The Perfect Fuel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26129; -- Brothers In Arms
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26140; -- Communing with the Ancient
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26141; -- Runestones of Binding
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26142; -- Ascend No More!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26143; -- All that Rises
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26149; -- Prisoners
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26154; -- Twilight Extermination
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26182; -- Back to the Tenebrous Cavern
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26236; -- Shakedown at the Saldean's
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26245; -- Gunship Down
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26246; -- Captain's Log
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26249; -- The Admiral's Cabin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26255; -- Return to the Temple of Earth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26256; -- Bleed the Bloodshaper
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26258; -- Deathwing's Fall
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26260; -- The Forgemaster's Log
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26261; -- Question the Slaves
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26289; -- Find Agent Kearnen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26290; -- Secrets of the Tower
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26335; -- Ready the Navy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26348; -- The Coast Isn't Clear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26349; -- The Coastal Menace
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26353; -- Captain Sanders' Hidden Treasure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26354; -- Captain Sanders' Hidden Treasure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26355; -- Captain Sanders' Hidden Treasure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26356; -- Captain Sanders' Hidden Treasure
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26409; -- Where's Goldmine?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26410; -- Explosive Bonding Compound
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26411; -- Apply and Flash Dry
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26413; -- Take Him to the Earthcaller
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26427; -- Without a Captain or Crew
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26463; -- Finding Teronis
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26597; -- Stranglethorn Fever
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26601; -- Mok'rash the Cleaver
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26603; -- Message in a Bottle
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26608; -- Negotiations Terminated
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26609; -- The Bloodsail Buccaneers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26711; -- Off to the Bank
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26768; -- To Catch a Dragon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26799; -- Those That Couldn't Be Saved
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26800; -- Recruitment
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26861; -- Block the Gates
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26994; -- Without Rhyme or Reason
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=26996; -- Right Under Their Noses
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27003; -- Easy Money
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27009; -- The Coldbringer
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27010; -- Quicksilver Submersion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27022; -- Extinguishing the Idol
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27039; -- Dangerous Intentions
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27061; -- The Twilight Overlook
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27065; -- The Warchief's Fleet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27068; -- Chief Ukorz Sandscalp
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27069; -- Steel Thunder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27071; -- Wrath of the Sandfury
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27076; -- Breaking and Entering
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27093; -- Lost in the Darkness
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27095; -- Skitterweb Menace
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27096; -- Orcs are in Order
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27109; -- The Warped Defender
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27111; -- The Treasure of the Shen'dralar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27112; -- The Cursed Remains
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27113; -- The Shen'dralar Ancient
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27135; -- Something that Burns
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27141; -- Premature Explosionation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27143; -- Barov Family Fortune
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27148; -- School's Out Forever
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27176; -- Just the Tip
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27179; -- Field Work
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27193; -- Seek and Destroy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27196; -- On to Something
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27231; -- Reinforcements from Fenris
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27232; -- The Waters Run Red...
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27333; -- Losing Ground
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27349; -- Break in Communications: Dreadwatch Outpost
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27350; -- Break in Communications: Rutsak's Guard
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27360; -- Vengeance for Our Soldiers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27364; -- On Whose Orders?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27401; -- What Tomorrow Brings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27431; -- Tipping the Balance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27444; -- The False Warchief
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27445; -- General Drakkisath, Hand of Nefarian
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27491; -- Kor'kron Drop
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27493; -- Ogres & Ettins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27495; -- Move the Mountain
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27497; -- Call in the Artillery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27499; -- Signal the Attack
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27501; -- Four Heads are Better than None
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27503; -- Up to the Citadel
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27511; -- The Thrill of Discovery
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27517; -- Be Prepared
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27541; -- Lessons From the Past
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27549; -- By the Light of the Stars
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27568; -- Infiltrating Shadowforge City
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27569; -- Dark Iron Tacticians
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27571; -- The Grim Guzzler
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27573; -- The Dark Iron Pact
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27595; -- The Prophet Hadassi
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27602; -- The Prophet's Dying Words
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27604; -- Jammal'an the Prophet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27605; -- Eranikus
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27623; -- Colossal Guardians
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27624; -- After the Fall
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27630; -- The High Priest's Vote
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27632; -- Tanotep's Son
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27633; -- The Blood God Hakkar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27638; -- Just You and Garona
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27653; -- Dark Assassins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27655; -- Bring the Hammer Down
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27658; -- Help from the Earthcaller
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27660; -- Spirit of the Loch
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27662; -- Unbinding
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27669; -- Do the Honors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27679; -- The Chamber of Khaz'mul
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27680; -- Archaedas, The Ancient Stone Watcher
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27681; -- Behind Closed Doors
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27682; -- We Require More Minerals
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27689; -- Distract Them for Me
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27692; -- Princess Theradras
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27696; -- The Elementium Axe
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27697; -- Corruption in Maraudon
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27701; -- Dragon, Unchained
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27706; -- The Scepter of Orsis
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27707; -- Neferset Prison
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27729; -- Once More, With Eeling
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27733; -- The Good Ol' Switcheroo
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27737; -- By Fire Be Saved!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27739; -- The Gnoll King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27760; -- Artificial Intelligence
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27838; -- The Root of the Corruption
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27839; -- Ancient Weapons
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27842; -- Only the Beginning
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27844; -- Traitors!!!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27847; -- Not Quite There
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27848; -- Good Intentions...Poor Execution
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27874; -- Aviana's Legacy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27899; -- That Gleam in his Eye
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27900; -- I've Got This Guy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27901; -- They Don't Know What They've Got Here
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27903; -- Ignition
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27905; -- Tailgunner!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27917; -- Sniffing Them Out
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27920; -- Armored to the Teeth
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27921; -- Fighting Tooth and Claw
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27922; -- Traitors!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27923; -- Smoke in Their Eyes
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27924; -- Budd's Plan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27926; -- Eastern Hospitality
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27928; -- A Favor for the Furrier
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27939; -- The Desert Fox
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27941; -- Fashionism
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27942; -- Idolatry
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27943; -- Angered Spirits
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27950; -- Gobbles!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27957; -- Lunk No Kill
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27959; -- Lunk's Adventure: Spider Rider
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27960; -- The Fewer, the Better
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27968; -- Fury of the Pack
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27969; -- Make Yourself Useful
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27974; -- This Land is Our Land
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27979; -- Dark Ministry
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27982; -- Twilight Collars
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27983; -- Lunk's Adventure: Cranky Little Dwarfs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27984; -- Lunthistle's Tale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27985; -- Prayer to Elune
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27988; -- Plague...Plague Everywhere!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27989; -- Ruumbo Demands Honey
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27990; -- Battlezone
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27993; -- Take it to 'Em!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27994; -- Ruumbo Demands Justice
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27995; -- Dance for Ruumbo!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27996; -- Orders Are For the Living
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27997; -- The Corruption of the Jadefire
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=27998; -- Sweet, Merciless Revenge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28000; -- Do the Imp-Possible
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28002; -- Crisis Management
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28029; -- Set Them Ablaze!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28033; -- Deceit
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28049; -- See the Invisible
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28052; -- Operation: Stir the Cauldron
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28053; -- Lunk Like Your Style
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28061; -- Minions of Calcinder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28062; -- From Whence He Came
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28064; -- Welcome to the Brotherhood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28090; -- Precious Goods
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28091; -- Easy Pickings
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28092; -- If The Key Fits
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28093; -- Pressing Forward
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28094; -- Paving the Way
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28097; -- The Gates of Grim Batol
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28100; -- A Talking Totem
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28112; -- Escape From the Lost City
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28116; -- Crying Violet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28129; -- The Demon Prince
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28131; -- Twin Temptresses
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28132; -- Efficient Excavations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28134; -- Impending Retribution
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28135; -- Al'Akir's Vengeance
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28141; -- Relics of the Sun King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28150; -- An Arcane Ally
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28153; -- Shadow Lord Fel'dan
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28171; -- And the Sky Streaked Red
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28173; -- Blackout
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28175; -- Shining Through the Dark
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28176; -- Following the Young Home
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28187; -- Missed Me By Zhat Much!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28191; -- A Fitting End
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28193; -- Lockdown!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28194; -- The Great Escape
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28195; -- Sending a Message
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28210; -- Shaping Up
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28247; -- Last of Her Kind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28249; -- Crushblow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28250; -- Thieving Little Pluckers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28267; -- Firing Squad
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28269; -- Meet Me In Vir'sar
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28276; -- Salhet's Secret
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28277; -- Salhet the Tactician
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28291; -- Return to Camp
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28349; -- Megs in Marketing
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28498; -- The Secret of Nahom
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28499; -- Punish the Trespassers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28500; -- The Cypher of Keset
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28520; -- The Fall of Neferset City
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28611; -- The Defilers' Ritual
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28652; -- Caretaker Caice
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28657; -- A Huge Problem
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28658; -- Swamp Bait
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28659; -- The Leftovers
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28660; -- Clearing the Depths
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28661; -- The Imprisoned Archmage
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28662; -- Learning From The Past
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28663; -- D-Block
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28664; -- Svarnos
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28665; -- Cursed Shackles
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28668; -- Prison Revolt
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28669; -- The Warden
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28670; -- Food From Below
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28672; -- The Executor In the Field
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28678; -- Captain P. Harris
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28679; -- Rattling Their Cages
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28680; -- Boosting Morale
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28681; -- Shark Tank
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28682; -- Claiming The Keep
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28683; -- Thinning the Brood
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28684; -- A Sticky Task
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28685; -- Leave No Weapon Behind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28686; -- Not The Friendliest Town
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28687; -- Teach A Man To Fish.... Or Steal
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28689; -- The Forgotten
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28690; -- Salvaging the Remains
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28691; -- First Lieutenant Connor
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28692; -- Magnets, How Do They Work?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28693; -- Finish The Job
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28694; -- Watch Out For Splinters!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28695; -- WANTED: Foreman Wellson
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28696; -- Bombs Away!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28697; -- Ghostbuster
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28698; -- Cannonball!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28700; -- Taking the Overlook Back
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28712; -- Enter the Dragon Queen
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28735; -- To the Chamber of Incineration!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28737; -- What Is This Place?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28738; -- The Twilight Forge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28740; -- Do My Eyes Deceive Me?
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28758; -- Battle of Life and Death
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28780; -- Join the Battle!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28781; -- Targets of Opportunity
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28783; -- The Source of Their Power
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28784; -- Join the Battle!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28791; -- They Sent Assassins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28792; -- They Sent Assassins
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28806; -- Fear No Evil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28808; -- Fear No Evil
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28814; -- Followers and Leaders
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28815; -- Twilight Documents
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28817; -- The Rear is Clear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28818; -- The Rear is Clear
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28833; -- Rescue the Earthspeaker!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28843; -- Sins of the Sea Witch
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28850; -- The Prison Rooftop
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28868; -- The View from Down Here
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28884; -- Victory in Tol Barad
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28910; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28911; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28913; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28914; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28916; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28917; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28918; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28919; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28920; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28922; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28924; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28925; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28926; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28927; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28928; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28929; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28930; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28932; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28943; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28944; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28945; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28946; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28947; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28948; -- Desecrate this Fire!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28949; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=28950; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29030; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29031; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29036; -- Honor the Flame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29071; -- Make Haste to Stormwind!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29092; -- Inform the Elder
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29101; -- Punting Season
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29146; -- Ridin' the Rocketway
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29148; -- Wings Aflame
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29156; -- The Troll Incursion
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29159; -- Pyrorachnophobia
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29160; -- Egg-stinction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29164; -- Perfecting Your Howl
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29165; -- The Call of the Pack
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29166; -- Supplies for the Other Side
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29189; -- Wicked Webs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29192; -- The Wardens are Watching
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29211; -- Solar Core Destruction
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29255; -- Embergris
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29257; -- Steal Magmolias
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29264; -- Flamewakers of the Molten Flow
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29278; -- Living Obsidium
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29295; -- The Bigger They Are
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29297; -- Bye Bye Burdy
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29298; -- A Smoke-Stained Locket
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29299; -- Some Like It Hot
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29302; -- Unlocking the Secrets Within
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29303; -- Tragedy and Family
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29310; -- The Tipping Point
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29329; -- Elemental Bonds: Patience
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29330; -- Elemental Bonds: Fury
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29335; -- Into Slashing Winds
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29336; -- Into Coaxing Tides
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29412; -- Blown Away
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29452; -- Your Time Has Come
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29764; -- Disarmament
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29803; -- Ears of the Lich King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29807; -- Death to the Traitor King
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29808; -- Don't Forget the Eggs!
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29811; -- The Gatewatcher's Talisman
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29825; -- Pupil No More
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29826; -- Reclaiming Ahn'Kahet
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29828; -- What the Scourge Dred
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29839; -- One of a Kind
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29848; -- The Forlorn Watcher
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29850; -- Corrupt Constructs
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29851; -- Champion of the Tournament
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29860; -- Diametrically Opposed
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=29864; -- Working at the Source
UPDATE `quest_offer_reward` SET `VerifiedBuild`=15595 WHERE `ID`=30120; -- Cleansing Drak'Tharon
