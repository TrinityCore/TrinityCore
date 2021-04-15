UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (89822, 90238, 90309, 90426, 90481, 90553, 90584, 90963, 90974, 90991, 90993, 91290, 91291, 91292, 91299, 91324, 91351, 91913, 91923, 91935, 92055, 92120, 92338, 92545, 92805, 93396, 94605, 94686, 95424, 96014, 96147);

DELETE FROM `creature_queststarter` WHERE `id` IN (89822, 90238, 90309, 90426, 90481, 90553, 90584, 90963, 90974, 90991, 90993, 91290, 91291, 91292, 91299, 91324, 91351, 91913, 91923, 91935, 92055, 92120, 92338, 92545, 92805, 93396, 94605, 94686, 95424, 96014, 96147);
DELETE FROM `creature_questender` WHERE `id` IN (89822, 90238, 90309, 90426, 90481, 90553, 90963, 90974, 90991, 90993, 91290, 91291, 91292, 91299, 91324, 91351, 91913, 91923, 91935, 92055, 92120, 92338, 92545, 92805, 93396, 94605, 94686, 95424, 96014, 96147);

INSERT INTO `creature_queststarter` VALUES
(89822, 37890), -- Draka, Obstacle Course
(90238, 37934), -- Shadow Hunter Mutumba, In, Through, and Beyond!
(90238, 37935), -- Shadow Hunter Mutumba, The Assault Base
(90309, 38421), -- Exarch Yrel, Garrison Campaign: Onslaught at Auchindoun
(90309, 38560), -- Exarch Yrel, Garrison Campaign: The Bane of the Bleeding Hollow
(90309, 38561), -- Exarch Yrel, Garrison Campaign: The Warlock
(90309, 39422), -- Exarch Yrel, Shipyard Report
(90309, 38581), -- Exarch Yrel, The Battle for the West
(90426, 38428), -- Abandoned Fel Pup, A Fel Puppy Of My Own
(90481, 38415), -- Draka, Garrison Campaign: Onslaught at Auchindoun
(90481, 38453), -- Draka, Garrison Campaign: The Bane of the Bleeding Hollow
(90481, 38458), -- Draka, Garrison Campaign: The Warlock
(90481, 39423), -- Draka, Shipyard Report
(90481, 38577), -- Draka, The Battle for the West
(90553, 38001), -- Durotan, Commander in the Field!
(90584, 38578), -- Goi'orsh, A Message of Terrible Import
(90963, 39313), -- Angar Steelbellow, Bring the Reinforcements
(90974, 39568), -- Vindicator Krethos, A Little Wetwork
(90974, 39567), -- Vindicator Krethos, Bloodied Blades of Zeth'Gol
(90974, 39569), -- Vindicator Krethos, Breaking Their Fel Bonds
(90974, 39571), -- Vindicator Krethos, Disarming Sha'naar
(90974, 39573), -- Vindicator Krethos, Harnessing Their Power
(90974, 39574), -- Vindicator Krethos, Pressing the Attack
(90974, 39570), -- Vindicator Krethos, Secrets of the Shadow Council
(90991, 38599), -- Lil' Trix, Infrastructure Improvements
(90993, 39315), -- Fraggs, Bring the Reinforcements
(91290, 38267), -- Reshad, Friends Above
(91290, 37687), -- Reshad, Garrison Campaign: In the Shadows
(91291, 38213), -- Reshad, Get a Clue
(91292, 38269), -- Reshad, Friends Above
(91292, 37688), -- Reshad, Garrison Campaign: In the Shadows
(91299, 38271), -- Ariok, Following the Bloody Path
(91324, 38274), -- Braknoth, The Eye of Kilrogg
(91351, 38272), -- Ariok, The Bleeding Hollow
(91913, 38436), -- Exarch Yrel, Obstacle Course
(91923, 38444), -- Exarch Naielle, In, Through, and Beyond!
(91923, 38445), -- Exarch Naielle, The Assault Base
(91935, 38446), -- Exarch Maladaar, Commander in the Field!
(92055, 38462), -- Oronok Torn-heart, Breaching the Barrier
(92120, 38463), -- Oronok Torn-heart, The Cipher of Damnation
(92120, 39394), -- Oronok Torn-heart, The Cipher of Damnation
(92338, 39395), -- Oronok Torn-heart, Oronok's Offer
(92545, 38603), -- Norman Powerspark, Setting the Signal
(92805, 39565), -- Z'tenga the Walker, Rumble in the Jungle
(93396, 39532), -- Nimi Brightcastle, Bringing Down the Iron Horde
(93396, 39519), -- Nimi Brightcastle, Demonslayer of Tanaan
(93396, 39529), -- Nimi Brightcastle, Tooth and Claw
(94605, 39177), -- Apexis Gemcutter, Ruined Construct
(94686, 39176), -- Sun-Sage Chakkis, Mastery Of Taladite
(95424, 39432), -- Dawn-Seeker Krisek, Unknowable Power
(95424, 39433), -- Dawn-Seeker Krisek, Unseen Influence
(96014, 39510), -- Shadow Hunter Denjai, A Little Wetwork
(96014, 39511), -- Shadow Hunter Denjai, Blood of Fallen Brothers
(96014, 39509), -- Shadow Hunter Denjai, Bloodied Blades of Zeth'Gol
(96014, 39513), -- Shadow Hunter Denjai, Disarming Sha'naar
(96014, 39514), -- Shadow Hunter Denjai, Harnessing Their Power
(96014, 39526), -- Shadow Hunter Denjai, Pressing the Attack
(96014, 39512), -- Shadow Hunter Denjai, Secrets of the Shadow Council
(96147, 39586), -- Parvink, Bringing Down the Iron Horde
(96147, 39581), -- Parvink, Demonslayer of Tanaan
(96147, 39582); -- Parvink, Tooth and Claw

INSERT INTO `creature_questender` VALUES
(89822, 37889), -- Draka, The Invasion of Tanaan
(90238, 37934), -- Shadow Hunter Mutumba, In, Through, and Beyond!
(90238, 37890), -- Shadow Hunter Mutumba, Obstacle Course
(90309, 37891), -- Exarch Yrel, Assault on Ironhold Harbor
(90309, 38440), -- Exarch Yrel, Assault on The Fel Forge
(90309, 38250), -- Exarch Yrel, Assault on the Ruins of Kra'nak
(90309, 37968), -- Exarch Yrel, Assault on the Temple of Sha'naar
(90309, 38585), -- Exarch Yrel, Assault on the Throne of Kil'jaeden
(90309, 38046), -- Exarch Yrel, Battle At The Iron Front
(90309, 38045), -- Exarch Yrel, Bleeding the Bleeding Hollow
(90309, 38446), -- Exarch Yrel, Commander in the Field!
(90309, 38445), -- Exarch Yrel, The Assault Base
(90309, 38996), -- Exarch Yrel, Your Orders, General?
(90426, 38428), -- Abandoned Fel Pup, A Fel Puppy Of My Own
(90481, 37940), -- Draka, Assault on Ironhold Harbor
(90481, 38441), -- Draka, Assault on The Fel Forge
(90481, 38252), -- Draka, Assault on the Ruins of Kra'nak
(90481, 38449), -- Draka, Assault on the Temple of Sha'naar
(90481, 38586), -- Draka, Assault on the Throne of Kil'jaeden
(90481, 38047), -- Draka, Battle At The Iron Front
(90481, 38044), -- Draka, Bleeding the Bleeding Hollow
(90481, 38001), -- Draka, Commander in the Field!
(90481, 37935), -- Draka, The Assault Base
(90481, 38989), -- Draka, Your Orders, General?
(90553, 38577), -- Durotan, The Battle for the West
(90963, 39313), -- Angar Steelbellow, Bring the Reinforcements
(90974, 39568), -- Vindicator Krethos, A Little Wetwork
(90974, 39567), -- Vindicator Krethos, Bloodied Blades of Zeth'Gol
(90974, 39569), -- Vindicator Krethos, Breaking Their Fel Bonds
(90974, 39571), -- Vindicator Krethos, Disarming Sha'naar
(90974, 39573), -- Vindicator Krethos, Harnessing Their Power
(90974, 39601), -- Vindicator Krethos, I Sunk Your Battleship
(90974, 39574), -- Vindicator Krethos, Pressing the Attack
(90974, 39570), -- Vindicator Krethos, Secrets of the Shadow Council
(90991, 38599), -- Lil' Trix, Infrastructure Improvements
(90993, 39315), -- Fraggs, Bring the Reinforcements
(91290, 37687), -- Reshad, Garrison Campaign: In the Shadows
(91291, 38267), -- Reshad, Friends Above
(91291, 38269), -- Reshad, Friends Above
(91292, 37688), -- Reshad, Garrison Campaign: In the Shadows
(91299, 38270), -- Ariok, Finding the Killer
(91324, 38272), -- Braknoth, The Bleeding Hollow
(91351, 38271), -- Ariok, Following the Bloody Path
(91913, 37839), -- Exarch Yrel, Light Be With You
(91913, 38435), -- Exarch Yrel, The Invasion of Tanaan
(91923, 38444), -- Exarch Naielle, In, Through, and Beyond!
(91923, 38436), -- Exarch Naielle, Obstacle Course
(91935, 38581), -- Exarch Maladaar, The Battle for the West
(92055, 38458), -- Oronok Torn-heart, Garrison Campaign: The Warlock
(92055, 38561), -- Oronok Torn-heart, Garrison Campaign: The Warlock
(92120, 38462), -- Oronok Torn-heart, Breaching the Barrier
(92338, 39395), -- Oronok Torn-heart, Oronok's Offer
(92545, 38603), -- Norman Powerspark, Setting the Signal
(92805, 39565), -- Z'tenga the Walker, Rumble in the Jungle
(93396, 39532), -- Nimi Brightcastle, Bringing Down the Iron Horde
(93396, 39519), -- Nimi Brightcastle, Demonslayer of Tanaan
(93396, 39529), -- Nimi Brightcastle, Tooth and Claw
(94605, 39176), -- Apexis Gemcutter, Mastery Of Taladite
(94686, 39175), -- Sun-Sage Chakkis, Gems of the Apexis
(94686, 39195), -- Sun-Sage Chakkis, Gems of the Apexis
(94686, 39177), -- Sun-Sage Chakkis, Ruined Construct
(95424, 39432), -- Dawn-Seeker Krisek, Unknowable Power
(95424, 39433), -- Dawn-Seeker Krisek, Unseen Influence
(96014, 39510), -- Shadow Hunter Denjai, A Little Wetwork
(96014, 39511), -- Shadow Hunter Denjai, Blood of Fallen Brothers
(96014, 39509), -- Shadow Hunter Denjai, Bloodied Blades of Zeth'Gol
(96014, 39513), -- Shadow Hunter Denjai, Disarming Sha'naar
(96014, 39514), -- Shadow Hunter Denjai, Harnessing Their Power
(96014, 39604), -- Shadow Hunter Denjai, I Sunk Your Battleship
(96014, 39526), -- Shadow Hunter Denjai, Pressing the Attack
(96014, 39512), -- Shadow Hunter Denjai, Secrets of the Shadow Council
(96147, 39586), -- Parvink, Bringing Down the Iron Horde
(96147, 39581), -- Parvink, Demonslayer of Tanaan
(96147, 39582); -- Parvink, Tooth and Claw
