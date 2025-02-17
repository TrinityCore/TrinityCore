-- The Return of Quel'Delar quest chain

-- Quest request items / CompletionText
DELETE FROM `quest_request_items` WHERE `ID` IN 
(14443,14457,20438,24454,24554,24557,24556,24558,24461,24476,24480,24522,24535,24559,24560,24561,24562,24563,24553,24564,24594,24595,24596,24598,24795,24796,24798,24799,24800,24801);
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
-- The Battered Hilt quest chain
(14443, 0, 0, "What is it that you have there?", 12340),                           -- The Battered Hilt (A)
(14457, 0, 0, "Did you find anything of use on that agent?", 12340),               -- The Sunreaver Plan (A)
(20438, 0, 0, "Was Shandy able to help you get a Sunreaver tabard?", 12340),       -- A Suitable Disguise (A)
(24454, 0, 0, "We've been expecting your return. What has kept you?", 12340),      -- Return To Caladis Brightspear
(24554, 0, 0, "What have you discovered?", 12340),                                 -- The Battered Hilt (H)
(24557, 0, 0, "Did you find anything of use on that agent?", 12340),               -- The Silver Covenant's Scheme (H)
(24556, 0, 0, "Was Shandy able to help you get a Silver Covenant tabard?", 12340), -- A Suitable Disguise (H)
(24558, 0, 0, "We've been expecting your return. What has kept you?", 12340),      -- Return To Myralion Sunblaze
-- Reforging The Sword quest chain
(24461, 0, 0, "Were you able to reconstruct Quel'Delar?", 12340),                             -- Reforging The Sword (A)
(24476, 0, 0, "Until the sword is tempered, it will be useless.", 12340),                     -- Tempering The Blade (A)
(24480, 0, 0, "What happened inside the Halls of Reflection?", 12340),                        -- The Halls Of Reflection (A)
(24522, 0, 0, "What brings you here?", 12340),                                                -- Journey To The Sunwell (A)
(24535, 0, 0, "Did you visit the ground where Thalorien fell defending the Sunwell?", 12340), -- Thalorien Dawnseeker (A)
(24559, 0, 0, "Were you able to reconstruct Quel'Delar?", 12340),                             -- Reforging The Sword (H)
(24560, 0, 0, "Until the sword is tempered, it will be useless.", 12340),                     -- Tempering The Blade (H)
(24561, 0, 0, "What happened inside the Halls of Reflection?", 12340),                        -- The Halls Of Reflection (H)
(24562, 0, 0, "What brings you here?", 12340),                                                -- Journey To The Sunwell (H)
(24563, 0, 0, "Did you visit the ground where Thalorien fell defending the Sunwell?", 12340), -- Thalorien Dawnseeker (H)
-- The Purification of Quel'Delar
(24553, 0, 0, "What happened during your time in the Sunwell?", 12340),  -- Alliance { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24564, 0, 0, "What happened inside the Sunwell?", 12340),               -- Orc, Undead, Tauren, Troll { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24594, 0, 0, "You have returned from the Sunwell?", 12340),             -- Blood Elf { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24595, 0, 0, "Tell me of what happened in the Sunwell, $n.", 12340),    -- Alliance { Priest | Shaman | Druid }
(24596, 0, 0, "What happened during your visit to the Sunwell?", 12340), -- Blood Elf (Priest)
(24598, 0, 0, "What news do you bring from the Sunwell?", 12340),        -- Orc, Undead, Tauren, Troll {Priest | Shaman | Druid}
-- A Victory For The { Silver Covenant | Sunreavers }
(24795, 0, 0, "Is it true that you have restored Quel'Delar?", 12340),   -- Alliance { Priest | Shaman | Druid }
(24796, 0, 0, "Is it true that you have restored Quel'Delar?", 12340),   -- Alliance { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24798, 0, 0, "Is it true that you have restored Quel'Delar?", 12340),   -- Blood Elf (Priest)
(24799, 0, 0, "Is it true that you have restored Quel'Delar?", 12340),   -- Orc, Undead, Tauren, Troll { Priest | Shaman | Druid }
(24800, 0, 0, "Is it true that you have restored Quel'Delar?", 12340),   -- Blood Elf { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24801, 0, 0, "Is it true that you have restored Quel'Delar?", 12340);   -- Orc, Undead, Tauren, Troll { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }

-- Quest 20439 "A Meeting With The Magister" and 24451 "An Audience With The Arcanist" contain text, but with errata and copypasta
UPDATE `quest_request_items` SET `CompletionText`= "Did you recover the book from Wyrmrest?" WHERE `ID` = 24451;
UPDATE `quest_offer_reward` SET `RewardText`= "Excellent work. Now that this is in our hands, we must get it to Caladis Brightspear as soon as possible. We can't risk the book falling back into Sunreaver hands.$B$BI'll ensure that Shandy Glossgleam gets his tabard back without incident, along with a healthy reward for his help." WHERE `ID` = 20439;
UPDATE `quest_offer_reward` SET `RewardText`= "Excellent work. Now that this is in our hands, we must get it to Myralion Sunblaze as soon as possible. We can't risk the Silver Covenant taking the book from us again.$B$BI'll get that tabard back to Shandy and see that he's well compensated for his assistance. Once the book is in Myralion's hands, the Silver Covenant won't be a threat anymore." WHERE `ID` = 24451;

-- Arcanist Tybalin has wrong gossip_menu_option text, because 1) OptionBroadcastTextID 36824 is the Alliance Player gossip option text, and 2) copypasta + name change:
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID` = 36829, `OptionText`="I'll deliver the tome to our contacts in Icecrown, arcanist." WHERE `MenuID` = 10858 AND `OptionID` = 0;

-- Magister Hathorel gossip_menu_option text is correct from broadcast_text, but has different content (copypasta + name change) in the gossip_menu_option table:
UPDATE `gossip_menu_option` SET `OptionText`="Would you renew my Silver Covenant disguise, Magister Hathorel?" WHERE `MenuID` = 10857 AND `OptionID` = 1;

-- Quest offer reward / RewardText
DELETE FROM `quest_offer_reward` WHERE `ID` IN 
(14443,14444,14457,20438,24454,24554,24555,24557,24556,24558,24461,24476,24480,24522,24535,24559,24560,24561,24562,24563,24553,24564,24594,24595,24596,24598,24795,24796,24798,24799,24800,24801);
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
-- The Battered Hilt quest chain
(14443, 0,0,0,0,0,0,0,0, "<Caladis takes the hilt from you and slowly turns it over in his hands.>$B$BThis seems somehow familiar, as though I should know its origins. You say you recovered this in the citadel? Most intriguing.$B$BThere are few who possess the ability to make such a blade. Perhaps they can tell us something about your find.", 12340),
(14444, 0,0,0,0,0,0,0,0, "We can't let that book remain in Sunreaver hands. If we hope to identify the sword and use it to our advantage, we have to find a way to capture the book Krasus lent them.", 12340),
(14457, 0,0,0,0,0,0,0,0, "<Arcanist Tybalin examines the captured orders.>$B$B$BThe agent you intercepted was supposed to transport the Wyrmrest Tome to Icecrown, after meeting with one Magister Hathorel in Sunreaver's Sanctuary. We have to get that book, $n, and this is our chance. It's not going to be easy, though.", 12340),
(20438, 0,0,0,0,0,0,0,0, "I knew Shandy would find a way to come through for us. Let me get this enchanted and ready for you to use. The sooner you get done with the tabard, the sooner we can get it back to Shandy and the better the chances that its owner will never have missed it.", 12340),
(24454, 0,0,0,0,0,0,0,0, "<Caladis accepts the heavy book and begins leafing through it.>$B$BI knew the symbols on the blade were familiar. The weapon was most certainly forged by the dragons and gifted to one of the mortal races, but which blade is this, and how did it come to rest in Icecrown?", 12340),
(24554, 0,0,0,0,0,0,0,0, "<Myralion takes the hilt from you and scrutinizes the artifact.>$B$BThis came from the citadel? What was it doing there? This blade is certainly not of Scourge manufacture.$B$BWeapons of this quality can only be crafted by a few of Azeroth's creatures. We will have to consult them and see if they can help us identify it.", 12340),
(24555, 0,0,0,0,0,0,0,0, "We must recover that book from the Silver Covenant. Without that book from Krasus, we stand little chance of solving the mystery of the sword in Icecrown or unlocking its power.", 12340),
(24557, 0,0,0,0,0,0,0,0, "<Magister Hathorel reads the captured orders.>$B$BThe agent you intercepted was supposed to deliver the Wyrmrest tome to Icecrown, after meeting with one Arcanist Tybalin inside the Silver Enclave. We have to reclaim that book, $n, and we only have one chance before it leaves the city. We have to work quickly.", 12340),
(24556, 0,0,0,0,0,0,0,0, "I knew Shandy would find a way to make it work. Let me get this enchanted and ready for you to use. With any luck, the tabard's owner won't even know it's missing and Shandy will cover the rest of our tracks.", 12340),
(24558, 0,0,0,0,0,0,0,0, "<Myralion accepts the heavy book and begins leafing through it.>$B$BThose symbols on the blade seemed familiar and now there's little wonder why. This is certainly a dragon blade, gifted to one of the mortal races, but which blade is this, and how did it come to rest in Icecrown?", 12340),
-- Reforging the Sword / Journey To The Sunwell quest chain
(24461, 0,0,0,0,0,0,0,0, "You have remade the blade of Quel'Delar, although Blood-Queen Lana'thel proclaimed we could not! The blade must still be tempered, but she and her master will not stand in our way!", 12340),
(24476, 0,0,0,0,0,0,0,0, "I... I don't understand. Tempering the sword should've restored the blade to its original condition. What has happened here?", 12340),
(24480, 0,0,0,0,0,0,0,0, "I had not thought it possible for evil to take hold in such a sword, but I suppose it was naive of me. If the greatest of dragonkind's creations could be corrupted and turned against them, why not a mere sword?$B$BUther's advice is wise, $n, and I would urge you to heed it quickly.", 12340),
(24522, 0,0,0,0,0,0,0,0, "Admit you to the Sunwell? That's impossible! The Sunwell is the most sacred and important site of our people. We have only recently reclaimed it with the help of the Shattered Sun Offensive. It is not a place for tourists or travelers.", 12340),
(24535, 0,0,0,0,0,0,0,0, "I confess that I did not expect Thalorien's spirit to recognize you as the heir to Quel'Delar, but I defer to his judgment. You may enter the Sunwell, but I remind you that you are a guest in our most sacred of precincts, and you should act accordingly.", 12340),
(24559, 0,0,0,0,0,0,0,0, "You have remade the blade of Quel'Delar in defiance of that Blood-Queen Lana'thel's pronouncement! Now, the blade must be tempered before we can show her the folly of her words.", 0),
(24560, 0,0,0,0,0,0,0,0, "Tempering the sword should've restored the blade. Why hasn't it worked?", 12340),
(24561, 0,0,0,0,0,0,0,0, "How can evil take root in such a sword? I would not have thought it possible if the evidence wasn't here before my eyes. If the greatest of dragonkind's creations could be corrupted and turned against them, why not a mere sword?$B$BI believe Uther is right. You must heed his advice quickly, $n.", 12340),
(24562, 0,0,0,0,0,0,0,0, "I hope you understand that I can't just admit you to the Sunwell, $n. This is the most sacred place known to the sin'dorei and we have only recently regained control over it.$B$BYou would raise the hopes of our people with tales of Quel'Delar? Without proof of the truth of your claims, I see no reason to take you at your word.", 12340),
(24563, 0,0,0,0,0,0,0,0, "You truly do carry Quel'Delar. This is a great day for all of Quel'Thalas and the sin'dorei. You have my leave to enter the Sunwell and finish the sword's restoration. Keep your head high, $n. The children of Silvermoon have dreamt of this day for years.", 12340),
-- The Purification of Quel'Delar
(24553, 0,0,0,0,0,0,0,0, "This is unbelievable, $n. You've really done it! All of the quel'dorei have heard of Thalorien Dawnseeker and Quel'Delar, but no one ever thought the sword would be restored.", 12340), -- Alliance { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24564, 0,0,0,0,0,0,0,0, "Am I truly laying my eyes upon the weapon of Thalorien Dawnseeker? This is a wondrous day for the Sunreavers and for all sin'dorei!", 12340), -- Orc, Undead, Tauren, Troll { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24594, 0,0,0,0,0,0,0,0, "Am I truly laying my eyes upon the weapon of Thalorien Dawnseeker? This is a wondrous day for the Sunreavers and for all sin'dorei!", 12340), -- Blood Elf { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24595, 0,0,0,0,0,0,0,0, "This is unbelievable, $n. You've really done it! All of the quel'dorei have heard of Thalorien Dawnseeker and Quel'Delar, but no one ever thought the sword would be restored.", 12340), -- Alliance { Priest | Shaman | Druid }
(24596, 0,0,0,0,0,0,0,0, "Am I truly laying my eyes upon the weapon of Thalorien Dawnseeker? This is a wondrous day for the Sunreavers and for all sin'dorei!", 12340), -- Blood Elf (Priest)
(24598, 0,0,0,0,0,0,0,0, "Am I truly laying my eyes upon the weapon of Thalorien Dawnseeker? This is a wondrous day for the Sunreavers and for all sin'dorei!", 12340), -- Orc, Undead, Tauren, Troll { Priest | Shaman | Druid }
-- A Victory For The { Silver Covenant | Sunreavers }
(24795, 0,0,0,0,0,0,0,0, "That a weapon of such power has been redeemed from the clutches of evil is a great omen in these times, $n. With Quel'Delar and staunch Silver Covenant allies at our side, the Lich King will have good reason to fear.$B$BThe crusade maintains an arsenal of exceptional weapons for our strongest allies. Allow me to offer you your choice from among them in return for entrusting us with the care of Quel'Delar.", 12340), -- Alliance { Priest | Shaman | Druid }
(24796, 0,0,0,0,0,0,0,0, "This is nothing short of an amazing accomplishment, $n. The day that Thalorien and Anasterian fell, the same day that Quel'Delar was lost, was one of the darkest of my life. To see Quel'Delar restored... it is beyond words.$B$BWithout a doubt, you are meant to be the true bearer of the blade. Quel'Delar's magic is already adapting the blade to your skills and your strengths.", 12340), -- Alliance { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24798, 0,0,0,0,0,0,0,0, "That a weapon of such power has been redeemed from the clutches of evil is a great omen in these times, $n. With Quel'Delar and staunch Sunreaver allies at our side, the Lich King will have good reason to fear.$B$BThe crusade maintains an arsenal of exceptional weapons for our strongest allies. Allow me to offer you your choice from among them in return for entrusting us with the care of Quel'Delar.", 12340), -- Blood Elf (Priest)
(24799, 0,0,0,0,0,0,0,0, "That a weapon of such power has been redeemed from the clutches of evil is a great omen in these times, $n. With Quel'Delar and staunch Sunreaver allies at our side, the Lich King will have good reason to fear.$B$BThe crusade maintains an arsenal of exceptional weapons for our strongest allies. Allow me to offer you your choice from among them in return for entrusting us with the care of Quel'Delar.", 12340), -- Orc, Undead, Tauren, Troll { Priest | Shaman | Druid }
(24800, 0,0,0,0,0,0,0,0, "Quel'Delar rises again, as we sin'dorei have risen from the ashes of defeat and betrayal. The heart and the weapon of Thalorien Dawnseeker are both with you, $n.$B$BI see the blade has already started adapting itself to your strengths, $n. Hold your head high and always keep Quel'Delar at your side.", 12340), -- Blood Elf { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
(24801, 0,0,0,0,0,0,0,0, "Quel'Delar rises again, as the sin'dorei have risen from the ashes of defeat and betrayal. Yet, somehow, the weapon of Thalorien Dawnseeker has chosen to serve an outsider.$B$BBe at ease, $n. I do not mean to diminish your accomplishment, for you have done what none of my brothers could, although I do not know why. You are clearly meant to be its bearer; the blade is already adapting itself to your abilities. Wield Quel'Delar proudly against our common foes.", 12340); -- Orc, Undead, Tauren, Troll { Warrior | Paladin | Hunter | Rogue | Death Knight | Mage | Warlock }
