-- Blood Feeders (6461), Xen'zilla at Malaka'Jin, CompletionText contains typos
UPDATE `quest_request_items` SET `CompletionText`="Hey mon, have you slain the hairy blood feeders? I fear none here in Stonetalon but I don't go walking around here at night... if you know what I mean mon!$b$bAs long as I stay off their dinner plate then all is well.$b$bGood luck to you, $c!" WHERE `ID`=6461;

-- RewardText contains typos and invalid text suggesting multiple item rewards.
UPDATE `quest_offer_reward` SET `RewardText`="Sweet, mon! Good news, perhaps we will have fewer unwanted dinner guests tonight.$b$bMany thanks, $N. We are forever in your debt." WHERE `ID`=6461;

-- Foul Magics (673), Tor'gan at Hammerfall, incorrect CompletionText, should use NPC reference (warlock), not player class
UPDATE `quest_request_items` SET `CompletionText`="The burning in my blood... it grows by the day. The warlock must be stopped." WHERE `ID`=673;

-- "released them" instead of "released us" (Tor'gan is a Darkspear troll, not an orc).
UPDATE `quest_offer_reward` SET `RewardText`="My restless nights will turn to peaceful slumber when I have destroyed this orb. Thank you, $n. It is a chilling reminder of the terrible power the demons held over the orcs before Hellscream released them from their curse." WHERE `ID`=673;

-- Camp Narache, quest 24857 should talk about tauren, not player race:
UPDATE `quest_offer_reward` SET `RewardText`="This is quite alarming indeed! But with this information we can call on our brethren from Bloodhoof Village to help thwart the attack. You have saved the lives of many tauren, $N." WHERE `ID`=24857;

-- Valormok, Ag'tor Bloodfist, quest 3504 (Betrayed) & 3507 (Betrayed (4)), referenced NPC Magus Rimtori is a mage and does not change to be the same class as player!
UPDATE `quest_request_items` SET `CompletionText`="Ah, Belgrom wizened up and finally sent someone not in his ranks to aid us, did he?$b$bThis camp used to be a dozen warriors strong, $N, but now they're all dead. That mage, Rimtori, has slain them all. She played Belgrom like a lute... seduced him even. It's none of my business, but between you and I, she is quite the temptress. That's probably why I'm still out here helping Belgrom--I probably would have done the same thing." WHERE `ID`=3504;
UPDATE `quest_offer_reward` SET `RewardText`="HAHA! Look at you now, pathetic woman! I spit on your remains!$b$bThank you, $N. Thank you from the bottom of my heart! This is indeed a great day!$b$bI would give you a kingdom if it were in my power! But perhaps you will settle for this.$b$b<Belgrom looks down at the head of the mage who had betrayed him.>$b$bHaha! Stupid blood elf, look at you now... in a burlap sack and missing your body! You should never have betrayed Belgrom!" WHERE `ID`=3507;

-- Orgrimmar, Delivery to Jes'rimon (3541), misunderstood use of gender alternatives ($gdad:mon). "mon" is a troll slang word, like "dude":
UPDATE `quest_request_items` SET `CompletionText`= "Yes, what you be needin', mon? I got many tings to be takin' care of today, and you not be on me agenda as one of them. Pester me, and I make sure that changes." WHERE `ID`=3541;

-- Blasted Lands, quest "To Serve Kum'Isha" (2521), CompletionText cuts short at the end, as well as 'tau(ren)' is referenced instead of player race.
UPDATE `quest_request_items` SET `CompletionText`= "I have dedicated my life to the search of flawless draenethyst spheres. A lifetime, $r!" WHERE `ID`=2521;
