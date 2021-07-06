UPDATE `quest_details` SET `VerifiedBuild`=0;

DELETE FROM `quest_details` WHERE `ID` IN (26230 /*Feast or Famine*/, 26420 /*Diggin' For Worms*/, 14281 /*Frost Nova*/, 13991 /*The Purloined Payroll*/, 26192 /*Orphans Like Cookies Too!*/, 28090 /*Precious Goods*/, 28091 /*Easy Pickings*/, 27576 /*Patchwork Command*/, 27508 /*Far from the Nest*/, 27509 /*Breach in the Defenses*/, 27507 /*Encroaching Twilight*/, 27564 /*In Defense of the Redoubt*/, 27506 /*Life from Death*/, 27505 /*Draconic Mending*/, 27504 /*Even Dragons Bleed*/, 28170 /*Night Terrors*/, 28166 /*Thog's Nightlight*/, 28151 /*Dressed to Kill*/, 27486 /*Warm Welcome*/, 27380 /*Nightmare*/, 27379 /*The Terrors of Iso'rath*/, 27378 /*The Worldbreaker*/, 27377 /*Devoured*/, 27376 /*The Maw of Iso'rath*/, 27303 /*Mercy for the Bound*/, 27301 /*Unbroken*/, 27302 /*Simple Solutions*/, 27300 /*Pushing Back*/, 27299 /*Torn Ground*/, 28147 /*Purple is Your Color*/, 28149 /*Whispers in the Wind*/, 28133 /*Fury Unbound*/, 27955 /*Eye Spy*/, 27375 /*The Weeping Wound*/, 28123 /*The Demon Chain*/, 28043 /*How to Maim Your Dragon*/, 27954 /*The Eyes Have It*/, 27951 /*We All Must Sacrifice*/, 27947 /*A Vision of Twilight*/, 27945 /*Paint it Black*/, 28038 /*Blood in the Highlands*/, 28041 /*Bait and Throttle*/, 27750 /*War Forage*/, 27747 /*Total War*/, 27929 /*Drag 'em Down*/, 27751 /*Crushing the Wildhammer*/, 27611 /*Blood on the Sand*/, 27610 /*Scouting the Shore*/, 27690 /*Narkrall, the Drake-Tamer*/, 27606 /*Blast Him!*/, 27586 /*Shells on the Sea Shore*/, 27584 /*Blood in the Surf*/, 27607 /*The Southern Flank*/, 27583 /*The Northern Flank*/, 28909 /*Sauranok Will Point the Way*/, 184 /*Furlbrow's Deed*/, 11 /*Riverpaw Gnoll Bounty*/, 147 /*Manhunt*/, 123 /*The Collector*/, 71 /*Report to Thomas*/, 45 /*Discover Rolf's Fate*/, 5545 /*A Bundle of Trouble*/, 26378 /*Hero's Call: Westfall!*/, 845 /*The Zhevra*/, 903 /*Hunting the Huntress*/, 848 /*Fungal Spores*/, 870 /*The Forgotten Pools*/, 13975 /*Crossroads Caravan Delivery*/, 13961 /*Drag it Out of Them*/, 13949 /*Crossroads Caravan Pickup*/, 5041 /*Supplies for the Crossroads*/, 26878 /*Disciples of Naralex*/, 26947 /*A Woodsman's Training*/, 3117 /*Etched Sigil*/, 13970 /*Animal Services*/, 13969 /*Grol'dom's Missing Kodo*/, 13968 /*The Tortusk Takedown*/, 13963 /*By Hook Or By Crook*/, 905 /*Into the Raptor's Den*/, 46 /*Bounty on Murlocs*/, 52 /*Protect the Frontier*/, 59 /*Cloth and Leather Armor*/, 83 /*Fine Linen Goods*/, 26152 /*Wanted: James Clark*/, 27047 /*Motes*/, 27046 /*Fear of Boring*/, 1097 /*Elmore's Task*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26230, 396, 396, 396, 0, 0, 0, 0, 0, 14333), -- Feast or Famine
(26420, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- Diggin' For Worms
(14281, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Frost Nova
(13991, 273, 1, 0, 0, 0, 900, 0, 0, 14333), -- The Purloined Payroll
(26192, 5, 1, 1, 1, 0, 0, 0, 0, 14333), -- Orphans Like Cookies Too!
(28090, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Precious Goods
(28091, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Easy Pickings
(27576, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Patchwork Command
(27508, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Far from the Nest
(27509, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Breach in the Defenses
(27507, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Encroaching Twilight
(27564, 5, 25, 0, 0, 0, 60, 0, 0, 14333), -- In Defense of the Redoubt
(27506, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Life from Death
(27505, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Draconic Mending
(27504, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Even Dragons Bleed
(28170, 1, 25, 5, 0, 0, 0, 0, 0, 14333), -- Night Terrors
(28166, 1, 273, 0, 0, 0, 0, 0, 0, 14333), -- Thog's Nightlight
(28151, 1, 11, 0, 0, 0, 0, 0, 0, 14333), -- Dressed to Kill
(27486, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Warm Welcome
(27380, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Nightmare
(27379, 5, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Terrors of Iso'rath
(27378, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Worldbreaker
(27377, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Devoured
(27376, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Maw of Iso'rath
(27303, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Mercy for the Bound
(27301, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Unbroken
(27302, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Simple Solutions
(27300, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Pushing Back
(27299, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Torn Ground
(28147, 1, 25, 0, 0, 0, 0, 0, 0, 14333), -- Purple is Your Color
(28149, 6, 1, 273, 0, 0, 0, 0, 0, 14333), -- Whispers in the Wind
(28133, 1, 274, 0, 0, 0, 0, 0, 0, 14333), -- Fury Unbound
(27955, 5, 6, 25, 0, 0, 0, 0, 0, 14333), -- Eye Spy
(27375, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- The Weeping Wound
(28123, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- The Demon Chain
(28043, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- How to Maim Your Dragon
(27954, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Eyes Have It
(27951, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- We All Must Sacrifice
(27947, 6, 5, 0, 0, 0, 0, 0, 0, 14333), -- A Vision of Twilight
(27945, 1, 274, 0, 0, 0, 0, 0, 0, 14333), -- Paint it Black
(28038, 6, 5, 25, 0, 0, 0, 0, 0, 14333), -- Blood in the Highlands
(28041, 1, 274, 5, 0, 0, 0, 0, 0, 14333), -- Bait and Throttle
(27750, 1, 274, 0, 0, 0, 0, 0, 0, 14333), -- War Forage
(27747, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- Total War
(27929, 6, 5, 0, 0, 0, 0, 0, 0, 14333), -- Drag 'em Down
(27751, 5, 1, 6, 0, 0, 0, 0, 0, 14333), -- Crushing the Wildhammer
(27611, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- Blood on the Sand
(27610, 1, 274, 0, 0, 0, 0, 0, 0, 14333), -- Scouting the Shore
(27690, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- Narkrall, the Drake-Tamer
(27606, 1, 11, 5, 0, 0, 0, 0, 0, 14333), -- Blast Him!
(27586, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- Shells on the Sea Shore
(27584, 25, 5, 15, 0, 0, 0, 0, 0, 14333), -- Blood in the Surf
(27607, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Southern Flank
(27583, 1, 5, 0, 0, 0, 0, 0, 0, 14333), -- The Northern Flank
(28909, 6, 1, 0, 0, 0, 0, 0, 0, 14333), -- Sauranok Will Point the Way
(184, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Furlbrow's Deed
(11, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Riverpaw Gnoll Bounty
(147, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Manhunt
(123, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Collector
(71, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Report to Thomas
(45, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Discover Rolf's Fate
(5545, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- A Bundle of Trouble
(26378, 1, 1, 0, 0, 0, 0, 0, 0, 14333), -- Hero's Call: Westfall!
(845, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Zhevra
(903, 5, 0, 0, 0, 100, 0, 0, 0, 14333), -- Hunting the Huntress
(848, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Fungal Spores
(870, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- The Forgotten Pools
(13975, 11, 1, 0, 0, 0, 900, 0, 0, 14333), -- Crossroads Caravan Delivery
(13961, 396, 0, 0, 0, 0, 0, 0, 0, 14333), -- Drag it Out of Them
(13949, 1, 25, 0, 0, 100, 900, 0, 0, 14333), -- Crossroads Caravan Pickup
(5041, 1, 1, 0, 0, 0, 500, 0, 0, 14333), -- Supplies for the Crossroads
(26878, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Disciples of Naralex
(26947, 1, 1, 0, 0, 0, 0, 0, 0, 14333), -- A Woodsman's Training
(3117, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Etched Sigil
(13970, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Animal Services
(13969, 6, 273, 0, 0, 0, 1000, 0, 0, 14333), -- Grol'dom's Missing Kodo
(13968, 274, 1, 0, 0, 0, 1000, 0, 0, 14333), -- The Tortusk Takedown
(13963, 1, 274, 0, 0, 300, 1000, 0, 0, 14333), -- By Hook Or By Crook
(905, 5, 0, 0, 0, 0, 0, 0, 0, 14333), -- Into the Raptor's Den
(46, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Bounty on Murlocs
(52, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Protect the Frontier
(59, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Cloth and Leather Armor
(83, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Fine Linen Goods
(26152, 0, 0, 0, 0, 0, 0, 0, 0, 14333), -- Wanted: James Clark
(27047, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Motes
(27046, 1, 0, 0, 0, 0, 0, 0, 0, 14333), -- Fear of Boring
(1097, 0, 0, 0, 0, 0, 0, 0, 0, 14333); -- Elmore's Task

UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=475; -- A Troubling Breeze
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=488; -- Zenn's Bidding
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=14277; -- Arcane Inquiries
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=14288; -- Safety in Numbers
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=14402; -- Ready to Go
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25223; -- Trial By Fire
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25224; -- In Bloom
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25274; -- Signed in Blood
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25276; -- Your New Identity
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25291; -- Twilight Training
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25294; -- Walking the Dog
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25296; -- Gather the Intelligence
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25299; -- Mental Training: Speaking the Truth to Power
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25308; -- Seeds of Discord
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25309; -- Spiritual Training: Mercy is for the Weak
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25310; -- The Greater of Two Evils
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25311; -- Twilight Territory
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25314; -- Speech Writing for Dummies
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25315; -- Graduation Speech
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25330; -- Waste of Flesh
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25494; -- A Champion's Collar
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25496; -- Grudge Match
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25499; -- Agility Training: Run Like Hell!
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25509; -- Physical Training: Forced Labor
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25531; -- Twilight Riot
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25548; -- Might of the Firelord
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25549; -- The Sanctum of the Prophets
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25550; -- Magma Monarch
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25551; -- The Firelord
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25552; -- Brood of Evil
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25553; -- Death to the Broodmother
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25554; -- Secrets of the Flame
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25555; -- The Gatekeeper
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25597; -- Commander Jarod Shadowsong
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25601; -- Head of the Class
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25608; -- Slash and Burn
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25644; -- The Twilight Egg
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25653; -- The Ancients are With Us
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25915; -- The Strength of Tortolla
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25923; -- Finish Nemesis
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=25928; -- Tortolla's Triumph
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26578; -- Doomshrooms
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26579; -- Gone Soft
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26580; -- Familiar Intruders
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26581; -- A Head Full of Wind
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26582; -- Unnatural Causes
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26583; -- Wrath of the Fungalmancer
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26584; -- Shaken and Stirred
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26585; -- Corruption Destruction
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26709; -- The Stone Throne
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26750; -- At the Stonemother's Call
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26752; -- Audience with the Stonemother
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26827; -- Rallying the Earthen Ring
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26828; -- Our Part of the Bargain
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26829; -- The Stone March
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26831; -- The Twilight Flight
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26832; -- Therazane's Mercy
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26833; -- Word In Stone
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26875; -- Undying Twilight
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=26971; -- The Binding
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27748; -- Fortune and Glory
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27755; -- The Curse of the Tombs
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27760; -- Artificial Intelligence
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27761; -- A Disarming Distraction
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27777; -- Core Access Codes
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27778; -- Hacking the Wibson
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27779; -- Gnomebliteration
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27836; -- Stopping the Spread
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27837; -- Trespassers in the Water
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=27838; -- The Root of the Corruption
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28271; -- Reduced Productivity
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28272; -- Missing Pieces
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28351; -- Unlimited Potential
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28352; -- Camel Tow
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28353; -- Jonesy Sent For You
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28363; -- Stirred the Hornet's Nest
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28367; -- Shroud of the Makers
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28402; -- Schnottz So Fast
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28403; -- Bad Datas
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28404; -- I'll Do It By Hand
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28480; -- Lieutenants of Darkness
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28482; -- Sullah's Gift
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28483; -- Bleeding the Enemy
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28486; -- Salhet's Gambit
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28497; -- Fire From the Sky
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28498; -- The Secret of Nahom
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28499; -- Punish the Trespassers
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28500; -- The Cypher of Keset
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28501; -- The Defense of Nahom
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28520; -- The Fall of Neferset City
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28533; -- The High Council's Decision
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28561; -- Nahom Must Hold
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28611; -- The Defilers' Ritual
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28612; -- Harrison Jones and the Temple of Uldum
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28613; -- See You on the Other Side!
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28621; -- Put That Baby in the Cradle!
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28622; -- Three if by Air
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28623; -- The Push Westward
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28633; -- The Coffer of Promise
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28654; -- The Heart of the Matter
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28845; -- The Vortex Pinnacle
UPDATE `quest_details` SET `VerifiedBuild`=14333 WHERE `ID`=28870; -- Return to the Lost City

DELETE FROM `quest_details` WHERE `ID` IN (10403 /*Naladu*/, 10630 /*Beneath Thrallmar*/, 12746 /*A Special Surprise*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10403, 0, 0, 0, 0, 0, 0, 0, 0, 14480), -- Naladu
(10630, 0, 0, 0, 0, 0, 0, 0, 0, 14480), -- Beneath Thrallmar
(12746, 1, 1, 1, 1, 0, 0, 0, 0, 14480); -- A Special Surprise

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14480 WHERE `ID`=9418; -- Avruu's Orb
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14480 WHERE `ID`=9420; -- The Finest Down
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14480 WHERE `ID`=9430; -- Sha'naar Relics
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14480 WHERE `ID`=9543; -- Atonement
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14480 WHERE `ID`=10255; -- Testing the Antidote
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14480 WHERE `ID`=13188; -- Where Kings Walk
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=14480 WHERE `ID`=13410; -- Hellfire Fortifications
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9355; -- A Job for an Intelligent Man
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9373; -- Missing Missive
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9385; -- Rampaging Ravagers
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9563; -- Gaining Mirren's Trust
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9575; -- Weaken the Ramparts
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9589; -- The Blood is Life
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=9607; -- Heart of Rage
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10057; -- Looking to the Leadership
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10079; -- When This Mine's a-Rockin'
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10099; -- The Mastermind
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10344; -- Wing Commander Gryphongar
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10346; -- Return to the Abyssal Shelf
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10367; -- A Traitor Among Us
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10368; -- The Dreghood Elders
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10369; -- Arzeth's Demise
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10382; -- Go to the Front
UPDATE `quest_details` SET `VerifiedBuild`=14480 WHERE `ID`=10400; -- Overlord

DELETE FROM `quest_details` WHERE `ID` IN (28871 /*Crushing the Wildhammer*/, 28873 /*Another Maw to Feed*/, 24755 /*More Than Expected*/, 24752 /*The Arts of a Mage*/, 24754 /*Proving Pit*/, 24753 /*A Rough Start*/, 24751 /*The Basics: Hitting Things*/, 24750 /*The Rise of the Darkspear*/, 27067 /*Moonfire*/, 3094 /*Verdant Note*/, 24769 /*More Than Expected*/, 24766 /*The Arts of a Druid*/, 24768 /*Proving Pit*/, 24767 /*A Rough Start*/, 24765 /*The Basics: Hitting Things*/, 24764 /*The Rise of the Darkspear*/, 26145 /*The Trogg Threat*/, 26146 /*In Defense of the King's Lands*/, 13635 /*South Gate Status Report*/, 26855 /*A Pilot's Revenge*/, 26854 /*The Lost Pilot*/, 12038 /*Seared Scourge*/, 11909 /*Defeat the Gearmaster*/, 11907 /*The Sub-Chieftains*/, 11633 /*Blending In*/, 11630 /*The Bad Earth*/, 11899 /*Souls of the Decursed*/, 11906 /*Cleaning Up the Pools*/, 11896 /*Weakness to Lightning*/, 11628 /*Shrouds of the Scourge*/, 11895 /*Master the Storm*/, 11894 /*Patching Up*/, 11689 /*Return with the Bad News*/, 11687 /*The Doctor and the Lich-Lord*/, 11893 /*The Power of the Elements*/, 11685 /*The Heart of the Elements*/, 11887 /*Emergency Supplies*/, 11683 /*Fallen Necropolis*/, 11678 /*Find Bristlehorn*/, 11677 /*Stop the Plague*/, 11675 /*A Proper Death*/, 28527 /*Warchief's Command: Silithus!*/, 28459 /*Stones of Binding*/, 14059 /*We're Out of Cranberry Chutney Again?*/, 14037 /*Spice Bread Stuffing*/, 14058 /*She Says Potato*/, 28226 /*Scrapped Golems*/, 28225 /*Prove Yer Allegiance*/, 28436 /*Taking the Horn For Ourselves*/, 28435 /*The Kodocaller's Horn*/, 28434 /*Strategic Cuts*/, 28433 /*Grunt Work*/, 28432 /*Into the Black Tooth Hovel*/, 28431 /*A Perfect Costume*/, 28427 /*A Needle in a Hellhole*/, 28426 /*Chiselgrip, the Heart of the Steppes*/, 28425 /*Return to Ariok*/, 28424 /*Shadow Boxing*/, 28423 /*Warlocks Have the Neatest Stuff*/, 28422 /*The Sand, the Cider, and the Orb*/, 28421 /*Mud Hunter*/, 28420 /*A Future Project*/, 28419 /*Stocking Up*/, 27523 /*Duskwing, Oh How I Hate Thee...*/, 28755 /*Annals of the Silver Hand*/, 27526 /*Gidwin's Fate Revealed*/, 27551 /*The Baroness' Missive*/, 27185 /*Cutting the Competition*/, 27223 /*Retribution*/, 27305 /*Of Love and Family*/, 27208 /*The Dreadlord Balnazzar*/, 27192 /*The Great Fras Siabi*/, 27539 /*Add 'em to the Pile*/, 27529 /*Defenders of Darrowshire*/, 27528 /*Scourged Mass*/, 27525 /*Guardians of Stratholme*/, 27524 /*Blind Fury*/, 27422 /*A City Under Siege*/, 27521 /*Wretched Hive of Scum and Villainy*/, 27522 /*Beat it Out of Them*/, 27489 /*Nobody to Blame but Myself*/, 27488 /*Impatience*/, 27487 /*Ix'lar the Underlord*/, 27479 /*Righteous Indignation*/, 27466 /*Argent Call: Northdale*/, 27477 /*The Corpulent One*/, 27457 /*An Opportune Alliance*/, 28756 /*Aberrations of Bone*/, 13790 /*Among the Champions*/, 13852 /*At The Enemy's Gates*/, 14090 /*Gormok Wants His Snobolds*/, 14077 /*The Light's Mercy*/, 12568 /*Troll Patrol: Done to Death*/, 12564 /*Troll Patrol: Something for the Pain*/, 12585 /*Troll Patrol: Creature Comforts*/, 13789 /*Taking Battle To The Enemy*/, 14096 /*You've Really Done It This Time, Kul*/, 13746 /*A Blade Fit For A Champion*/, 13749 /*A Valiant's Field Training*/, 12546 /*Reclamation*/, 12797 /*Back Through the Waygate*/, 12547 /*The Activation Rune*/, 12581 /*A Hero's Burden*/, 12579 /*Lifeblood of the Mosswalker Shrine*/, 12580 /*The Mosswalker Savior*/, 12578 /*The Angry Gorloc*/, 12577 /*Home Time!*/, 12576 /*Forced Hand*/, 12575 /*The Lost Mistwhisper Treasure*/, 12574 /*Back So Soon?*/, 12573 /*Making Peace*/, 12572 /*Gods like Shiny Things*/, 12571 /*Make the Bad Snake Go Away*/, 12570 /*Fortunate Misunderstandings*/, 12540 /*Just Following Orders*/, 12539 /*Hoofing It*/, 12538 /*The Mist Isn't Listening*/, 12537 /*Lightning Definitely Strikes Twice*/, 12536 /*A Rough Ride*/, 12535 /*Mischief in the Making*/, 12531 /*The Underground Menace*/, 12532 /*Flown the Coop!*/, 12534 /*The Sapphire Queen*/, 12533 /*The Wasp Hunter's Apprentice*/, 12530 /*Tormenting the Softknuckles*/, 12548 /*The Etymidian*/, 12691 /*A Timeworn Coffer*/, 12613 /*Powering the Waygate - The Makers' Overlook*/, 12559 /*Powering the Waygate - The Makers' Perch*/, 12621 /*Freya's Pact*/, 12620 /*The Lifewarden's Wrath*/, 12614 /*Post-partum Aggression*/, 12658 /*My Pet Roc*/, 12607 /*A Mammoth Undertaking*/, 12683 /*Burning to Help*/, 12681 /*Reagent Agent*/, 12605 /*Securing the Bait*/, 12603 /*Sharpening Your Talons*/, 12660 /*Weapons of Destruction*/, 12617 /*Exterminate the Intruders*/, 12608 /*Cultist Incursion*/, 12805 /*Salvaging Life's Strength*/, 12612 /*The Fallen Pillar*/, 12611 /*Returned Sevenfold*/, 12645 /*The Taste Test*/, 12595 /*In Search of Bigger Game*/, 12529 /*The Ape Hunter's Slave*/, 12528 /*Playing Along*/, 12569 /*Crocolisk Mastery: The Ambush*/, 12556 /*Rhino Mastery: The Kill*/, 12644 /*Still At It*/, 12544 /*The Bones of Nozronn*/, 12560 /*Crocolisk Mastery: The Plan*/, 12671 /*Reconnaissance Flight*/, 12803 /*Force of Nature*/, 12699 /*An Embarrassing Incident*/, 12558 /*Dreadsaber Mastery: Ready to Pounce*/, 12543 /*An Offering for Soo-rahm*/, 12592 /*The Great Hunter's Challenge*/, 12804 /*A Steak Fit for a Hunter*/, 12634 /*Some Make Lemonade, Some Make Liquor*/, 12551 /*Crocolisk Mastery: The Trial*/, 12550 /*Dreadsaber Mastery: Stalking the Prey*/, 12526 /*Rhino Mastery: The Chase*/, 12520 /*Rhino Mastery: The Test*/, 12549 /*Dreadsaber Mastery: Becoming a Predator*/, 12589 /*Kick, What Kick?*/, 12696 /*Aerial Surveillance*/, 12525 /*Wipe That Grin Off His Face*/, 12688 /*Engineering a Disaster*/, 10295 /*From the Abyss*/, 14022 /*Pilgrim's Bounty*/, 13657 /*Explorers' League Document (3 of 6)*/, 27037 /*Vyrin's Revenge*/, 27036 /*Vyrin's Revenge*/, 27116 /*The Winds of Loch Modan*/, 27115 /*Ando's Call*/, 27078 /*Gor'kresh*/, 27075 /*Servants of Cho'gall*/, 27077 /*Clutching at Chaos*/, 27074 /*Fight the Hammer*/, 27035 /*Standing Up*/, 13659 /*Explorers' League Document (6 of 6)*/, 27034 /*He's That Age*/, 27033 /*Skystrider's Heart*/, 27031 /*Wing Nut*/, 13658 /*Explorers' League Document (4 of 6)*/, 13660 /*Explorers' League Document (5 of 6)*/, 26932 /*Buzz Off*/, 13636 /*Stormpike's Orders*/, 10597 /*Setting Up the Bomb*/, 10633 /*Teron Gorefiend - Lore and Legend*/, 10672 /*Frankly, It Makes No Sense...*/, 10596 /*To Legion Hold*/, 10702 /*A Grunt's Work...*/, 10595 /*Besieged!*/, 10647 /*Wanted: Uvuros, Scourge of Shadowmoon*/, 10760 /*The Sketh'lon Wreckage*/, 10624 /*A Haunted History*/, 10660 /*What Strange Creatures...*/, 10834 /*Grillok "Darkeye"*/, 10813 /*The Eyes of Grillok*/, 10792 /*Zeth'Gor Must Burn!*/, 27930 /*Devastation*/, 27858 /*Rheastrasza's Gift*/, 27832 /*The Hidden Clutch*/, 27831 /*The Sorrow and the Fury*/, 27830 /*Their Hunt Continues*/, 27829 /*The Wrath of a Dragonflight*/, 27828 /*Eric, the Utility Dwarf*/, 27834 /*Baelog, the Glass Cannon*/, 27835 /*Olaf, the Big Fella'*/, 27827 /*The Swift, the Fierce, and the Stout*/, 27826 /*Into the Dragon's Mouth*/, 27794 /*Return to Blam*/, 27824 /*The Good Stuff*/, 27715 /*The Day that Deathwing Came: What Really Happened*/, 27714 /*The Day that Deathwing Came: The Real Story*/, 27833 /*Half-Ton Holdouts*/, 28512 /*To the Aid of the Thorium Brotherhood*/, 27825 /*Survival of the Fattest*/, 12563 /*Troll Patrol*/, 13891 /*The Devourer of Darkshore*/, 13898 /*The Tides Turn Against Us*/, 13899 /*The Darkscale Warlord*/, 13953 /*Naga In Our Midst*/, 13885 /*In Defense of Darkshore*/, 13925 /*An Ounce of Prevention*/, 13882 /*The Seeds of Life*/, 13895 /*The Slumbering Ancients*/, 13910 /*A New Home*/, 13918 /*The Titans' Terminal*/, 13909 /*Got Some Flotsam?*/, 13912 /*Swamped Secrets*/, 13911 /*The Absent-Minded Prospector*/, 13907 /*Sweeping Clean the Ruins*/, 13893 /*Soggoth and Kronn*/, 13546 /*The Defiler*/, 13572 /*Jadefire Braziers*/, 13545 /*Cleansing the Afflicted*/, 13896 /*Unearthed Knowledge*/, 13544 /*The Bear's Blessing*/, 13948 /*Stepping Up Surveillance*/, 13526 /*The Bear's Paw*/, 13583 /*The Wildkin's Oath*/, 13582 /*Elune's Fire*/, 13561 /*Solace for the Highborne*/, 13528 /*Buzzbox 723*/, 13527 /*No Accounting for Taste*/, 13521 /*Buzzbox 413*/, 13520 /*The Boon of the Seas*/, 14316 /*Cenarion Property*/, 14314 /*Breakout!*/, 14312 /*An Introduction Is In Order*/, 14309 /*Calming the Kodo*/, 14311 /*Taking Part*/, 14307 /*Stubborn Winds*/, 14304 /*Blood Theory*/, 14305 /*A Time to Reap*/, 14306 /*Pulling Weeds*/, 13515 /*Ending the Threat*/, 13514 /*The Ancients' Ire*/, 13590 /*The Front Line*/, 13512 /*Strategic Strikes*/, 13513 /*On the Brink*/, 13844 /*The Looting of Althalaxx*/, 13507 /*Denying Manpower*/, 13509 /*War Supplies*/, 13505 /*Remnants of the Highborne*/, 13504 /*Shatterspear Laborers*/, 13589 /*The Shatterspear Invaders*/, 13560 /*An Ocean Not So Deep*/, 13523 /*Power Over the Tides*/, 13599 /*Grimclaw's Return*/, 13569 /*The Ritual Bond*/, 13598 /*Unsavory Remedies*/, 13566 /*Ritual Materials*/, 13565 /*Twice Removed*/, 13562 /*The Final Flame of Bashal'Aran*/, 13564 /*A Lost Companion*/, 13563 /*A Love Eternal*/, 13831 /*A Troubling Prescription*/, 13557 /*Bearer of Good Fortune*/, 13529 /*The Corruption's Source*/, 13554 /*A Cure In The Dark*/, 27530 /*The Corpsebeasts*/, 27527 /*Journey's End*/, 12436 /*Supplemental Income*/, 12175 /*Gray Worg Hides*/, 12468 /*The Conqueror's Task*/, 13189 /*Saurfang's Blessing*/, 12747 /*A Special Surprise*/, 9146 /*Report to Captain Helios*/, 9143 /*Dealing with Zeb'Sora*/, 9216 /*Rotting Hearts*/, 9218 /*Spinal Dust*/, 11729 /*The Ultrasonic Screwdriver*/, 27713 /*The Day that Deathwing Came*/, 28322 /*The Spoils of War*/, 28321 /*Glory Amidst Chaos*/, 28320 /*Assault on Dreadmaul Rock*/, 28327 /*Locked and Loaded*/, 28319 /*A Delivery for Xi'lun*/, 28318 /*A Delivery for Neeralak*/, 28317 /*A Delivery for Thorg'izog*/, 28326 /*Placing the Pawns*/, 28316 /*A Deal With a Dragon*/, 28315 /*Draconic Vanguard*/, 28314 /*Blood Tour*/, 28313 /*A Heap of Delicious Worg*/, 28312 /*Latent Demons of the Land*/, 28311 /*Blackened Ashes*/, 28415 /*SEVEN! YUP!*/, 28310 /*Morgan's Vigil*/, 28286 /*Enough Damage For One Day*/, 28279 /*Abuse of Power*/, 28278 /*I Am the Law and I Am the Lash*/, 28266 /*Trial by Magma*/, 28265 /*General Thorg'izog*/, 28253 /*Taking the Horn For Ourselves*/, 28252 /*The Kodocaller's Horn*/, 28246 /*Strategic Cuts*/, 28245 /*Grunt Work*/, 28239 /*Into the Black Tooth Hovel*/, 28202 /*A Perfect Costume*/, 28254 /*A Needle in a Hellhole*/, 28227 /*Golem Training*/, 28184 /*Chiselgrip, the Heart of the Steppes*/, 28183 /*Return to Keeshan*/, 28182 /*Shadow Boxing*/, 28181 /*Warlocks Have the Neatest Stuff*/, 28179 /*Mud Hunter*/, 28178 /*A Future Project*/, 28177 /*Stocking Up*/, 28172 /*Done Nothing Wrong*/, 28416 /*Burning Vengeance*/, 27469 /*Friends on The Other Side*/, 27471 /*Blackrock Anomaly*/, 26171 /*You Are Rakh'likh, Demon*/, 26170 /*The Final Ritual*/, 25706 /*Neptool's Revenge*/, 26163 /*Time is Short*/, 25705 /*False Idols*/, 25703 /*Atrocities*/, 25702 /*Home... Gone... Naga...*/, 10748 /*Maxnar Must Die!*/, 10722 /*Meeting at the Blackwing Coven*/, 10893 /*Longtail is the Lynchpin*/, 10894 /*Wyrmskull Watcher*/, 10747 /*Whelps of the Wyrmcult*/, 10719 /*Did You Get The Note?*/, 10717 /*Poaching from Poachers*/, 10713 /*...and a Time for Action*/, 10607 /*Whispers of the Raven God*/, 10771 /*From the Ashes*/, 10770 /*Little Embers*/, 10796 /*Crush the Bloodmaul Camp!*/, 10795 /*A Date with Dorgok*/, 10753 /*Culling the Wild*/, 10567 /*Creating the Pendant*/, 10682 /*A Time for Negotiation...*/, 10712 /*Test Flight: Ruuan Weald*/, 10675 /*Show Them Gnome Mercy!*/, 10711 /*Test Flight: Razaan's Landing*/, 10671 /*More than a Pound of Flesh*/, 10674 /*Trapping the Light Fantastic*/, 10632 /*Cutting Your Teeth*/, 10620 /*Ridgespine Menace*/, 10657 /*Ride the Lightning*/, 10710 /*Test Flight: The Singing Ridge*/, 10557 /*Test Flight: The Zephyrium Capacitorium*/, 10594 /*Gauging the Resonant Frequency*/, 10584 /*Picking Up Some Power Converters*/, 27763 /*To Fuselight Proper*/, 27453 /*Catalysm*/, 27450 /*Frederick's Fish Fancy*/, 27481 /*Out of the Ziggurat*/, 27449 /*Honor and Strength*/, 27452 /*Dark Garb*/, 27451 /*To Kill With Purpose*/, 12041 /*The Lost Empire*/, 13182 /*Don't Forget the Eggs!*/, 12040 /*An Enemy in Arthas*/, 11592 /*We Strike!*/, 13204 /*Funky Fungi*/, 25719 /*Demoniac Vessel*/, 25718 /*How Best to Proceed*/, 13190 /*All Things in Good Time*/, 26049 /*The Princess Unleashed*/, 26038 /*Attack on the Tower*/, 26346 /*Myzrael's Tale*/, 26042 /*Breaking the Keystone*/, 26037 /*Trelane's Defenses*/, 26095 /*Stromgarde Badges*/, 26036 /*Wand over Fist*/, 26117 /*For Southshore*/, 26116 /*Kinelory Strikes*/, 26114 /*Quae Trusts You*/, 26110 /*Just Like Old Times*/, 26041 /*Stones of Binding*/, 26039 /*The Princess Trapped*/, 26341 /*The Stone Shards*/, 26982 /*The Scarlet Monastery*/, 24540 /*War Dance*/, 6364 /*Return to Varg*/, 24550 /*Journey into Thunder Bluff*/, 24524 /*Wildmane Cleansing*/, 861 /*The Hunter's Way*/, 773 /*Rite of Wisdom*/, 24523 /*Wildmane Totem*/, 20441 /*Rite of Vision*/, 24457 /*Rite of Vision*/, 27978 /*Ghostbuster*/, 27975 /*WANTED: Foreman Wellson*/, 28165 /*D-Block*/, 28185 /*Svarnos*/, 26190 /*A Fisherman's Feast*/, 543 /*The Perenolde Tiara*/, 270 /*The Doomed Fleet*/, 27156 /*It's About Time!*/, 14036 /*Pilgrim's Bounty*/, 11639 /*Revenge Upon Magmoth*/, 11635 /*Farseer Grimwalker's Spirit*/, 11631 /*Vision of Air*/, 11629 /*Return to the Spirit Talker*/, 11569 /*Keymaster Urmgrgl*/, 11570 /*Escape from the Winterfin Caverns*/, 11566 /*Surrender... Not!*/, 11565 /*The Spare Suit*/, 11564 /*Succulent Orca Stew*/, 11563 /*Grmmurggll Mrllggrl Glrggl!!!*/, 11562 /*I'm Being Blackmailed By My Cleaner*/, 11560 /*Oh Noes, the Tadpoles!*/, 11561 /*Them!*/, 11559 /*Winterfin Commerce*/, 11649 /*Motes of the Enraged*/, 9499 /*Falcon Watch*/, 9590 /*The Blood is Life*/, 9588 /*Dark Tidings*/, 25717 /*The Demons and the Druid*/, 25701 /*You Are Rakh'likh, Demon*/, 25700 /*Loramus Thalipedes Awaits*/, 25698 /*The Amulet of Sevine*/, 25699 /*The Amulet of Grol*/, 25697 /*The Amulet of Allistarj*/, 29402 /*Taking Precautions*/, 29399 /*Shopping Around*/, 29398 /*Fencing the Goods*/, 27460 /*Soft Landing*/, 27459 /*The Brotherhood of Light*/, 27458 /*Smokey and the Bandage*/, 28505 /*The Battle for Andorhal*/, 8353 /*Chicken Clucking for a Mint*/, 29103 /*Serpents and Poison*/, 11131 /*Stop the Fires!*/, 8356 /*Flexing for Nougat*/, 29392 /*Missing Heirlooms*/, 29144 /*Clean Up in Stormwind*/, 29054 /*Stink Bombs Away!*/, 29430 /*A Friend in Need*/, 8311 /*Hallow's End Treats for Jesper!*/, 29371 /*A Time to Lose*/, 29075 /*A Time to Gain*/, 29074 /*A Season for Celebration*/, 10290 /*In Search of Farahlite*/, 10429 /*When Nature Goes Too Far*/, 13111 /*One of a Kind*/, 13556 /*Eggs for Dubra'Jin*/, 13098 /*For Posterity*/, 12891 /*I Have an Idea, But First...*/, 13227 /*Judgment Day Comes!*/, 12892 /*It's All Fun and Games*/, 13419 /*Preparations for War*/, 26644 /*Attracting Attention*/, 26634 /*The Bane of Many A Pirate*/, 26635 /*Cannonball Swim*/, 26633 /*Swabbing Duty*/, 26631 /*Your First Day as a Pirate*/, 26595 /*Kill-Collect*/, 26594 /*Return to MacKinley*/, 29153 /*Booty Bay's Interests*/, 26814 /*High Priest Venoxis*/, 26813 /*Plunging Into Zul'Gurub*/, 26812 /*High Priestess Jeklik*/, 26811 /*Through the Troll Hole*/, 26810 /*Eliminate the Outcast*/, 26809 /*Backdoor Dealings*/, 26808 /*Maywiki*/, 26819 /*Akiris by the Bundle*/, 26820 /*If They're Just Going to Leave Them Lying Around...*/, 26816 /*Recipe for Disaster*/, 26821 /*Airwyn Bantamflax*/, 26824 /*Results: Inconclusive*/, 26818 /*Plush Pelts*/, 26815 /*Zanzil's Secret*/, 26817 /*Perfectly Pure*/, 29152 /*Making Contact*/, 29151 /*Bad Supplies*/, 29150 /*Voodoo Zombies*/, 29133 /*To the Digsite*/, 29131 /*Defend the Rebel Camp*/, 29124 /*Warn the Rebel Camp*/, 29121 /*Bury Me With Me Boots...*/, 29213 /*How's the Hunter Holding Up?*/, 29120 /*Mauti*/, 29116 /*Follow That Cat*/, 29115 /*The Hunter's Revenge*/, 29114 /*Track the Tracker*/, 29105 /*Nesingwary Will Know*/, 29104 /*Spirits Are With Us*/, 27415 /*The Brood of Onyxia*/, 27417 /*The Brood of Onyxia*/, 27416 /*The Brood of Onyxia*/, 27256 /*The Black Shield*/, 27306 /*Talk to Ogron*/, 27255 /*The Black Shield*/, 14064 /*Sharing a Bountiful Feast*/, 29318 /*Ribs for the Sentinels*/, 9803 /*Messenger to the Feralfen*/, 14289 /*Safety in Numbers*/, 14279 /*Learning the Word*/, 14278 /*Seek the Sister*/, 13153 /*Warding the Warriors*/, 13186 /*Stop the Siege*/, 13177 /*No Mercy for the Merciless*/, 26628 /*Death From Below*/, 26052 /*Speak to Shakes*/, 26051 /*Sunken Treasure*/, 26055 /*Drowned Sorrows*/, 26050 /*Goggle Boggle*/, 25868 /*Yorla Darksnare*/, 25867 /*Gnoll Escape*/, 25866 /*Dark Iron Trappers*/, 25855 /*Gizmos and Gadgets*/, 25865 /*The Mosshide Job*/, 25857 /*Hunting Horrorjaw*/, 25856 /*Crocolisk Hides*/, 25864 /*Dinosaur Crisis*/, 25854 /*I'll Call Him Bitey*/, 26139 /*Into Arathi*/, 26128 /*The Battle of Thandol Span*/, 26127 /*The Twilight's Hammer Revealed*/, 26327 /*Anvilmar the Hero*/, 26196 /*Longbraid the Grim*/, 25939 /*For Peat's Sake*/, 25927 /*The Threat of Flame*/, 25926 /*Mired in Hatred*/, 26120 /*The Crazed Dragonmaw*/, 26195 /*Who Wards The Greenwarden*/, 26189 /*The Angerfang Menace*/, 25853 /*Tooling Around*/, 25850 /*Strike the Earth!*/, 25849 /*When Archaeology Attacks*/, 25819 /*The Eye of Paleth*/, 25818 /*Lifting the Curse*/, 25817 /*The Cursed Crew*/, 26955 /*Zen'Kiki and the Cultists*/, 27055 /*Students of Krastinov*/, 27054 /*Desperate Acts*/, 27057 /*Return to the Stead*/, 27370 /*Tarenar Sunstrike*/, 27367 /*Gidwin Goldbraids*/, 27144 /*The Reckoning*/, 27090 /*Andorhal, Once and For All*/, 27089 /*Ace in the Hole*/, 27087 /*Lindsay Ravensun, Revealed*/, 27085 /*Supporting the Troops*/, 27086 /*Ashes to Ashes*/, 27084 /*The Farmers' Militia*/, 27083 /*The Battle Resumes!*/, 27155 /*Turning Yourself In*/, 27154 /*Bagging Bisp*/, 27153 /*The Good People of Hearthglen*/, 27152 /*Unusual Behavior... Even For Gnolls*/, 26938 /*Combat Training*/, 26937 /*When Death is Not Enough*/, 26979 /*Strange New Faces*/, 27017 /*Memories from a Lost Past*/, 27053 /*Gahrron's Withering Cauldron*/, 26930 /*After the Crusade*/, 27683 /*Into the Woods*/, 26926 /*Victory, For Now*/, 27157 /*Drudges... <Sigh>*/, 27151 /*Taelan Fordring's Legacy*/, 26957 /*The Long Trip Home*/, 27012 /*A Gnoll's Resolve*/, 27011 /*Redpine Thievery*/, 27002 /*An Audience with the Highlord*/, 27001 /*This Means WAR (Wild Arachnid Roundup)*/, 27013 /*Too Close for Comfort*/, 27000 /*Learning the Ropes*/, 26954 /*A Different Approach*/, 26935 /*Northridge Lumber Mill*/, 26956 /*I Ain't Sayin' You a Gourd-Digger...*/, 26953 /*Zen'Kiki, the Druid*/, 26999 /*A New Era for the Plaguelands*/, 26952 /*The Menders' Stead*/, 26978 /*Who Needs Cauldrons?*/, 26933 /*Foes Before Hoes*/, 26925 /*Araj the Summoner*/, 27117 /*Brute Strength*/, 26924 /*Scholomancer*/, 26923 /*War Machines*/, 26921 /*Scourge First... Alliance Later*/, 26922 /*The Endless Flow*/, 26920 /*The Battle for Andorhal*/, 26934 /*Latent Disease*/, 26931 /*Foxes and Hounds*/, 11593 /*The Honored Dead*/, 11594 /*Put Them to Rest*/, 10095 /*Into the Heart of the Labyrinth*/, 10091 /*The Soul Devices*/, 10094 /*The Codex of Blood*/, 10178 /*Find Spy To'gun*/, 27467 /*Buried Blades*/, 27465 /*Argent Call: The Noxious Glade*/, 27464 /*Argent Call: The Trial of the Crypt*/, 27463 /*A Boyhood Dream*/, 27455 /*Boys Will Be Boys*/, 27390 /*The Battle of Darrowshire*/, 27421 /*Amidst Death, Life*/, 27420 /*Postponing the Inevitable*/, 27448 /*The Trek Continues*/, 27544 /*Cenarion Tenacity*/, 27389 /*Marauders of Darrowshire*/, 27388 /*Heroes of Darrowshire*/, 27387 /*Villains of Darrowshire*/, 27386 /*A Strange Historian*/, 27385 /*Uncle Carlin*/, 27392 /*I'm Not Supposed to Tell You This*/, 27384 /*Pamela's Doll*/, 27382 /*Rough Roads*/, 27383 /*Little Pamela*/, 27381 /*Traveling Companions*/, 27432 /*Zaeldarr the Outcast*/, 27373 /*Onward, to Light's Hope Chapel*/, 27372 /*A Gift For Fiona*/, 27371 /*What I Do Best*/, 27369 /*Greasing the Wheel*/, 27368 /*Just Encased*/, 27534 /*Augustus' Receipt Book*/, 27533 /*A Fate Worse Than Butchery*/, 27535 /*Just a Little Touched*/, 27531 /*Counter-Plague Research*/, 27762 /*Fuselight, Ho!*/, 27620 /*Like Rats*/, 27617 /*Befouled No More*/, 27618 /*Argent Upheaval*/, 27612 /*Victory From Within*/, 27613 /*The Assassin*/, 27619 /*The Commander*/, 27616 /*The Huntsman*/, 27615 /*The Wrathcaster*/, 27614 /*Scarlet Salvage*/, 27462 /*To Take the Barracks*/, 27461 /*To Take the Abbey*/, 27456 /*Gathering Some Grub(s)*/, 27880 /*Half-Ton Holdouts*/, 27927 /*Down to the Scar*/, 27879 /*Survival of the Fattest*/, 28069 /*Adventurers Wanted: Blackrock Depths*/, 28417 /*Done Nothing Wrong*/, 28418 /*Burning Vengeance*/, 28299 /*Meet with Kranosh*/, 28677 /*Warchief's Command: Swamp of Sorrows!*/, 28667 /*Warchief's Command: Burning Steppes!*/, 14023 /*Spice Bread Stuffing*/, 28821 /*The Rear is Clear*/, 28811 /*Fear No Evil*/, 28795 /*They Sent Assassins*/, 28787 /*Join the Battle!*/, 26915 /*The Deepest Cut*/, 28772 /*Lions for Lambs*/, 28764 /*Beating Them Back!*/, 26804 /*Flight to Razor Hill*/, 26803 /*Missing Reports*/, 14011 /*Primal Strike*/, 26212 /*Lard Lost His Lunch*/, 26959 /*Stripping Their Defenses*/, 26240 /*Stomp To My Beat*/, 26223 /*Stalking the Stalkers*/, 26987 /*The Right Way*/, 26211 /*Snapjaws, Mon!*/, 26210 /*Gammerita, Mon!*/, 26030 /*Sigil of Strom*/, 26025 /*The Traitor Orc*/, 26023 /*The Forsaken Trollbane*/, 26027 /*Call to Arms*/, 26430 /*Revantusk Village*/, 26950 /*The Dark Side of the Light*/, 26986 /*Into the Scarlet Monastery*/, 26429 /*Crush the Witherbark*/, 26108 /*Guile of the Raptor*/, 14065 /*Sharing a Bountiful Feast*/, 26909 /*The Stone Shards*/, 26107 /*Raising Spirits*/, 4601 /*The Sparklematic 5200!*/, 26428 /*To Steal From Thieves*/, 26053 /*Clearing the Highlands*/, 26022 /*First Blood*/, 9173 /*Retaking Windrunner Spire*/, 9163 /*Into Occupied Territory*/, 9207 /*Underlight Ore Samples*/, 27365 /*A Fitting Weapon*/, 10166 /*Whitebark's Memory*/, 8474 /*Old Whitebark's Pendant*/, 26778 /*The Cries of the Dead*/, 26725 /*Guided by the Light*/, 26724 /*The Lurking Lich*/, 26793 /*The Weathered Grave*/, 26723 /*The Fate of Morbent Fel*/, 26760 /*Cry For The Moon*/, 26735 /*The Fate of Kurzen*/, 26787 /*Bear In Mind*/, 26721 /*The Jitters-Bugs*/, 26720 /*A Curse We Cannot Lift*/, 26838 /*Rebels Without a Clue*/, 26777 /*Soothing Spirits*/, 26719 /*Delivery to Master Harris*/, 26717 /*The Yorgen Worgen*/, 26707 /*A Deadly Vine*/, 25235 /*Vulgar Vul'Gol*/, 26785 /*Part of the Pack*/, 26674 /*Mistmantle's Revenge*/, 26672 /*Clawing at the Truth*/, 26671 /*The Fate of Stalvan Mistmantle*/, 26727 /*The Embalmer's Revenge*/, 26681 /*Note to the Mayor*/, 26677 /*Ghoulish Effigy*/, 26670 /*Roland's Doom*/, 26669 /*In A Dark Corner*/, 26680 /*Ogre Thieves*/, 26676 /*Juice Delivery*/, 26661 /*Gather Rot Blossoms*/, 26660 /*Zombie Juice*/, 26655 /*Deliver the Thread*/, 26654 /*Return the Comb*/, 26652 /*Ghost Hair Thread*/, 26667 /*The Stolen Letters*/, 26685 /*Classy Glass*/, 26684 /*The Insane Ghoul*/, 26653 /*Supplies from Darkshire*/, 26683 /*Look To The Stars*/, 26666 /*The Legend of Stalvan*/, 26686 /*Bones That Walk*/, 26645 /*The Night Watch*/, 26627 /*The Hermit*/, 26691 /*Worgen in the Woods*/, 26623 /*Dusky Crab Cakes*/, 26620 /*Seasoned Wolf Kabobs*/, 26690 /*Vile and Tainted*/, 26618 /*Wolves at Our Heels*/, 26689 /*The Rotting Orchard*/, 26688 /*Worgen in the Woods*/, 14041 /*Cranberry Chutney*/, 14062 /*Don't Forget The Stuffing!*/, 14040 /*Pumpkin Pie*/, 28571 /*Warchief's Command: Hillsbrad Foothills!*/, 14061 /*Can't Get Enough Turkey*/, 27987 /*Cannonball!*/, 27691 /*Marshfin Madness*/, 27740 /*Baba Bogbrew*/, 27600 /*In With a Bang*/, 27599 /*Can't Take It With Them*/, 27598 /*Kill Gil*/, 27597 /*Crazy Larry*/, 27663 /*Tastes Like Strider*/, 27536 /*Mostly Harmless*/, 27656 /*Croc-Out*/, 27587 /*Maliciously Delicious*/, 27851 /*Cutting Supply*/, 27849 /*Assault on Stonard*/, 27918 /*The Harborage*/, 27845 /*Marking the Fallen*/, 27843 /*Reinforcements Denied*/, 27795 /*Tides of Darkness*/, 27840 /*Draenethyst Crystals*/, 27860 /*The Lost Ones*/, 27822 /*Lumbering Oafs*/, 27821 /*Orcs and Humans*/, 24913 /*Remember the Light*/, 27904 /*Breath of Mist*/, 27902 /*The Purespring*/, 27876 /*Secrets of the Mire*/, 27875 /*Prayerblossom*/, 26779 /*Zul'Mamwe Mambo*/, 26368 /*Venomous Secrets*/, 26367 /*Ongo'longo's Revenge*/, 26308 /*It's Ours Now*/, 26309 /*Dark Vessels*/, 26307 /*Death to the Vilebranch*/, 26310 /*All That Skitters*/, 26366 /*Heads Up*/, 26306 /*Start Taking Back*/, 26357 /*Faces of Evil*/, 26283 /*Prime Slime*/, 26268 /*Skulk Rock Supplies*/, 26267 /*Skulk Rock Clean-Up*/, 26224 /*Hunt the Savages*/, 26988 /*Moving Things Along*/, 26263 /*Thornar Thunderclash*/, 26238 /*The Savage Dwarves*/, 12541 /*Troll Patrol: The Alchemist's Apprentice*/, 9493 /*Pride of the Fel Horde*/, 12791 /*The Magical Kingdom of Dalaran*/, 11647 /*Neutralizing the Cauldrons*/, 11641 /*A Courageous Strike*/, 11640 /*Words of Power*/, 11695 /*The Horn of Elemental Fury*/, 12189 /*Imbeciles Abound!*/, 12488 /*The High Executor Needs You*/, 11979 /*The Taunka and the Tauren*/, 13682 /*Threat From Above*/, 14080 /*Stop The Aggressors*/, 13750 /*The Grand Melee*/, 13747 /*A Worthy Weapon*/, 10296 /*The Black Morass*/, 10285 /*Return to Andormu*/, 10284 /*Escape from Durnholde*/, 10283 /*Taretha's Diversion*/, 29439 /*The Call of the World-Shaman*/, 26776 /*Ghaliri*/, 26775 /*Be Raptor*/, 26780 /*Nighttime in the Jungle*/, 26774 /*Mind Control*/, 26773 /*See Raptor*/, 26772 /*Mind Vision*/, 26749 /*Priestess Thaalia*/, 26984 /*An Old, Crazed Friend*/, 26781 /*The Mind's Eye*/, 26944 /*Exploring Gnomeregan*/, 26805 /*To the Cape!*/, 26782 /*The Mosh'Ogg Bounty*/, 26748 /*Bloodlord Mandokir*/, 26751 /*Population Con-Troll*/, 26747 /*A Physical Specimen*/, 26731 /*The Altar of Naias*/, 26746 /*A Nose for This Sort of Thing*/, 26730 /*You Can Take the Murloc Out of the Ocean...*/, 26743 /*Sacred to the Bloodscalp*/, 26745 /*Favored Skull*/, 26742 /*Bloodscalp Insight*/, 26729 /*Water Elementals*/, 26737 /*Stopping Kurzen's Legacy*/, 26744 /*Deep Roots*/, 26734 /*The Source of the Madness*/, 26765 /*Return to Corporal Kaleb*/, 26739 /*I Think She's Hungry*/, 26736 /*Spared from Madness*/, 26733 /*Control Sample*/, 26738 /*Just Hatched*/, 26763 /*Venture Company Mining*/, 28671 /*Warchief's Command: Blasted Lands!*/, 27402 /*Token of Power*/, 27282 /*Kranosh's Behest*/, 28790 /*A Personal Summons*/, 13277 /*Against the Giants*/, 13355 /*Cannot Reproduce*/, 13354 /*Chain of Command*/, 13352 /*Drag and Drop*/, 13351 /*Sneak Preview*/, 13261 /*Volatility*/, 13264 /*That's Abominable!*/, 13283 /*King of the Mountain*/, 13310 /*Assault by Air*/, 13301 /*Assault by Ground*/, 13293 /*Get to Ymirheim!*/, 13239 /*Volatility*/, 13237 /*Poke and Prod*/, 13234 /*Make Them Pay!*/, 13260 /*Takes One to Know One*/, 13238 /*Good For Something?*/, 13330 /*Blood of the Chosen*/, 13340 /*Joining the Assault*/, 13230 /*Avenge Me!*/, 13302 /*Slaves to Saronite*/, 13258 /*Opportunity*/, 13228 /*The Broken Front*/, 13224 /*Orgrim's Hammer*/, 13213 /*Battle at Valhalas*/, 13142 /*Banshee's Revenge*/, 13104 /*Once More Unto The Breach, Hero*/, 13481 /*Let's Get Out of Here!*/, 13235 /*The Flesh Giant Champion*/, 13220 /*Putting Olakin Back Together Again*/, 13212 /*He's Gone to Pieces*/, 13144 /*Killing Two Scourge With One Skeleton*/, 13152 /*A Visit to the Doctor*/, 13211 /*By Fire Be Purged*/, 13140 /*The Runesmiths of Malykriss*/, 13138 /*I'm Smelting... Smelting!*/, 13136 /*Jagged Shards*/, 13134 /*Spill Their Blood*/, 13120 /*Death's Gaze*/, 13119 /*Destroying the Altars*/, 13117 /*Where Are They Coming From?*/, 13137 /*Not-So-Honorable Combat*/, 13133 /*Find the Ancient Hero*/, 12852 /*The Admiral Revealed*/, 12847 /*Second Chances*/, 12815 /*No Fly Zone*/, 12813 /*From Their Corpses, Rise!*/, 12840 /*In Strict Confidence*/, 12814 /*You'll Need a Gryphon*/, 12839 /*The Grand (Admiral's) Plan*/, 12838 /*Intelligence Gathering*/, 12810 /*Blood in the Water*/, 12807 /*The Story Thus Far...*/, 13121 /*Through the Eye*/, 13091 /*The Art of Being a Water Terror*/, 13059 /*Revenge for the Vargul*/, 12806 /*To the Rise with all Due Haste!*/, 13043 /*The Sum is Greater than the Parts*/, 13042 /*Deep in the Bowels of The Underhalls*/, 13092 /*Reading the Bones*/, 12992 /*Crush Dem Vrykuls!*/, 13084 /*Vandalizing Jotunheim*/, 12982 /*Ebon Blade Prisoners*/, 13085 /*Vaelen Has Returned*/, 12951 /*Let the Baron Know*/, 12949 /*Get the Key*/, 12943 /*Shadow Vault Decree*/, 12999 /*The Bone Witch*/, 12955 /*Eliminate the Competition*/, 12939 /*Honor Challenge*/, 13106 /*Blackwatch*/, 12938 /*The Duke*/, 12899 /*The Shadow Vault*/, 10392 /*Doorway to the Abyss*/, 10391 /*Cannons of Rage*/, 10393 /*Vile Plans*/, 9608 /*Heart of Rage*/, 10864 /*A Burden of Souls*/, 10230 /*The Battle Horn*/, 10229 /*Decipher the Tome*/, 10835 /*Apothecary Antonivich*/, 14128 /*Return of the Highborne?*/, 14127 /*Return of the Highborne?*/, 26397 /*Walk With The Earth Mother*/, 14060 /*Easy As Pie*/, 14043 /*Candied Sweet Potatoes*/, 28820 /*The Rear is Clear*/, 28810 /*Fear No Evil*/, 28794 /*They Sent Assassins*/, 28786 /*Join the Battle!*/, 26919 /*Learning the Word*/, 28771 /*Lions for Lambs*/, 28763 /*Beating Them Back!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(28871, 5, 1, 6, 0, 0, 0, 0, 0, 14545), -- Crushing the Wildhammer
(28873, 1, 274, 0, 0, 0, 0, 0, 0, 14545), -- Another Maw to Feed
(24755, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- More Than Expected
(24752, 1, 1, 0, 0, 0, 60, 0, 0, 14545), -- The Arts of a Mage
(24754, 1, 1, 0, 0, 0, 60, 0, 0, 14545), -- Proving Pit
(24753, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Rough Start
(24751, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Basics: Hitting Things
(24750, 1, 1, 1, 0, 0, 60, 60, 0, 14545), -- The Rise of the Darkspear
(27067, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Moonfire
(3094, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Verdant Note
(24769, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- More Than Expected
(24766, 1, 1, 0, 0, 0, 60, 0, 0, 14545), -- The Arts of a Druid
(24768, 1, 1, 0, 0, 0, 60, 0, 0, 14545), -- Proving Pit
(24767, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Rough Start
(24765, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Basics: Hitting Things
(24764, 1, 1, 1, 0, 0, 60, 60, 0, 14545), -- The Rise of the Darkspear
(26145, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Trogg Threat
(26146, 5, 1, 1, 0, 0, 0, 0, 0, 14545), -- In Defense of the King's Lands
(13635, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- South Gate Status Report
(26855, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Pilot's Revenge
(26854, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Lost Pilot
(12038, 6, 1, 0, 0, 0, 0, 0, 0, 14545), -- Seared Scourge
(11909, 1, 1, 1, 5, 0, 0, 0, 0, 14545), -- Defeat the Gearmaster
(11907, 1, 1, 1, 5, 0, 0, 0, 0, 14545), -- The Sub-Chieftains
(11633, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Blending In
(11630, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Bad Earth
(11899, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Souls of the Decursed
(11906, 1, 1, 1, 0, 1000, 0, 0, 0, 14545), -- Cleaning Up the Pools
(11896, 25, 1, 5, 0, 0, 0, 0, 0, 14545), -- Weakness to Lightning
(11628, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Shrouds of the Scourge
(11895, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Master the Storm
(11894, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Patching Up
(11689, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return with the Bad News
(11687, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Doctor and the Lich-Lord
(11893, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Power of the Elements
(11685, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Heart of the Elements
(11887, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Emergency Supplies
(11683, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Fallen Necropolis
(11678, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Find Bristlehorn
(11677, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Stop the Plague
(11675, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- A Proper Death
(28527, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warchief's Command: Silithus!
(28459, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stones of Binding
(14059, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- We're Out of Cranberry Chutney Again?
(14037, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Spice Bread Stuffing
(14058, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- She Says Potato
(28226, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Scrapped Golems
(28225, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Prove Yer Allegiance
(28436, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Taking the Horn For Ourselves
(28435, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Kodocaller's Horn
(28434, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Strategic Cuts
(28433, 5, 397, 0, 0, 0, 0, 0, 0, 14545), -- Grunt Work
(28432, 1, 1, 22, 0, 0, 0, 0, 0, 14545), -- Into the Black Tooth Hovel
(28431, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Perfect Costume
(28427, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Needle in a Hellhole
(28426, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Chiselgrip, the Heart of the Steppes
(28425, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to Ariok
(28424, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Shadow Boxing
(28423, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warlocks Have the Neatest Stuff
(28422, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Sand, the Cider, and the Orb
(28421, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mud Hunter
(28420, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Future Project
(28419, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Stocking Up
(27523, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Duskwing, Oh How I Hate Thee...
(28755, 1, 6, 0, 0, 0, 0, 0, 0, 14545), -- Annals of the Silver Hand
(27526, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gidwin's Fate Revealed
(27551, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Baroness' Missive
(27185, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Cutting the Competition
(27223, 1, 1, 1, 397, 0, 0, 0, 0, 14545), -- Retribution
(27305, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Of Love and Family
(27208, 1, 1, 1, 397, 0, 0, 0, 0, 14545), -- The Dreadlord Balnazzar
(27192, 1, 1, 5, 20, 0, 0, 0, 0, 14545), -- The Great Fras Siabi
(27539, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Add 'em to the Pile
(27529, 5, 1, 0, 0, 0, 0, 0, 0, 14545), -- Defenders of Darrowshire
(27528, 396, 0, 0, 0, 0, 0, 0, 0, 14545), -- Scourged Mass
(27525, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Guardians of Stratholme
(27524, 1, 2, 0, 0, 0, 0, 0, 0, 14545), -- Blind Fury
(27422, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A City Under Siege
(27521, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wretched Hive of Scum and Villainy
(27522, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Beat it Out of Them
(27489, 1, 22, 273, 0, 0, 0, 0, 0, 14545), -- Nobody to Blame but Myself
(27488, 1, 5, 1, 0, 0, 0, 0, 0, 14545), -- Impatience
(27487, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- Ix'lar the Underlord
(27479, 5, 25, 5, 0, 0, 0, 0, 0, 14545), -- Righteous Indignation
(27466, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Argent Call: Northdale
(27477, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- The Corpulent One
(27457, 1, 6, 1, 0, 0, 0, 0, 0, 14545), -- An Opportune Alliance
(28756, 1, 6, 0, 0, 0, 0, 0, 0, 14545), -- Aberrations of Bone
(13790, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Among the Champions
(13852, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- At The Enemy's Gates
(14090, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Gormok Wants His Snobolds
(14077, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Light's Mercy
(12568, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- Troll Patrol: Done to Death
(12564, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Troll Patrol: Something for the Pain
(12585, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Troll Patrol: Creature Comforts
(13789, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Taking Battle To The Enemy
(14096, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- You've Really Done It This Time, Kul
(13746, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Blade Fit For A Champion
(13749, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Valiant's Field Training
(12546, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Reclamation
(12797, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Back Through the Waygate
(12547, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Activation Rune
(12581, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Hero's Burden
(12579, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Lifeblood of the Mosswalker Shrine
(12580, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Mosswalker Savior
(12578, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Angry Gorloc
(12577, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Home Time!
(12576, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Forced Hand
(12575, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Lost Mistwhisper Treasure
(12574, 1, 0, 0, 0, 60, 0, 0, 0, 14545), -- Back So Soon?
(12573, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Making Peace
(12572, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gods like Shiny Things
(12571, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Make the Bad Snake Go Away
(12570, 6, 0, 0, 0, 0, 0, 0, 0, 14545), -- Fortunate Misunderstandings
(12540, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Just Following Orders
(12539, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Hoofing It
(12538, 1, 273, 0, 0, 0, 60, 0, 0, 14545), -- The Mist Isn't Listening
(12537, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Lightning Definitely Strikes Twice
(12536, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Rough Ride
(12535, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mischief in the Making
(12531, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Underground Menace
(12532, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Flown the Coop!
(12534, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Sapphire Queen
(12533, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Wasp Hunter's Apprentice
(12530, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Tormenting the Softknuckles
(12548, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Etymidian
(12691, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Timeworn Coffer
(12613, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Powering the Waygate - The Makers' Overlook
(12559, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Powering the Waygate - The Makers' Perch
(12621, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Freya's Pact
(12620, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Lifewarden's Wrath
(12614, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Post-partum Aggression
(12658, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- My Pet Roc
(12607, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Mammoth Undertaking
(12683, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Burning to Help
(12681, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Reagent Agent
(12605, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Securing the Bait
(12603, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Sharpening Your Talons
(12660, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Weapons of Destruction
(12617, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Exterminate the Intruders
(12608, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Cultist Incursion
(12805, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Salvaging Life's Strength
(12612, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Fallen Pillar
(12611, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Returned Sevenfold
(12645, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Taste Test
(12595, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- In Search of Bigger Game
(12529, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Ape Hunter's Slave
(12528, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Playing Along
(12569, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Crocolisk Mastery: The Ambush
(12556, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Rhino Mastery: The Kill
(12644, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Still At It
(12544, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Bones of Nozronn
(12560, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Crocolisk Mastery: The Plan
(12671, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Reconnaissance Flight
(12803, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Force of Nature
(12699, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- An Embarrassing Incident
(12558, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dreadsaber Mastery: Ready to Pounce
(12543, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- An Offering for Soo-rahm
(12592, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Great Hunter's Challenge
(12804, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Steak Fit for a Hunter
(12634, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Some Make Lemonade, Some Make Liquor
(12551, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Crocolisk Mastery: The Trial
(12550, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Dreadsaber Mastery: Stalking the Prey
(12526, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Rhino Mastery: The Chase
(12520, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Rhino Mastery: The Test
(12549, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Dreadsaber Mastery: Becoming a Predator
(12589, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Kick, What Kick?
(12696, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Aerial Surveillance
(12525, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Wipe That Grin Off His Face
(12688, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Engineering a Disaster
(10295, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- From the Abyss
(14022, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Pilgrim's Bounty
(13657, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Explorers' League Document (3 of 6)
(27037, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vyrin's Revenge
(27036, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vyrin's Revenge
(27116, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Winds of Loch Modan
(27115, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ando's Call
(27078, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gor'kresh
(27075, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Servants of Cho'gall
(27077, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Clutching at Chaos
(27074, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Fight the Hammer
(27035, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Standing Up
(13659, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Explorers' League Document (6 of 6)
(27034, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- He's That Age
(27033, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Skystrider's Heart
(27031, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wing Nut
(13658, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Explorers' League Document (4 of 6)
(13660, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Explorers' League Document (5 of 6)
(26932, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Buzz Off
(13636, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stormpike's Orders
(10597, 1, 1, 25, 0, 0, 0, 0, 0, 14545), -- Setting Up the Bomb
(10633, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Teron Gorefiend - Lore and Legend
(10672, 1, 1, 273, 17, 0, 0, 0, 0, 14545), -- Frankly, It Makes No Sense...
(10596, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- To Legion Hold
(10702, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- A Grunt's Work...
(10595, 5, 1, 25, 0, 0, 0, 0, 0, 14545), -- Besieged!
(10647, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wanted: Uvuros, Scourge of Shadowmoon
(10760, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Sketh'lon Wreckage
(10624, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Haunted History
(10660, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- What Strange Creatures...
(10834, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Grillok "Darkeye"
(10813, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Eyes of Grillok
(10792, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Zeth'Gor Must Burn!
(27930, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Devastation
(27858, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rheastrasza's Gift
(27832, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Hidden Clutch
(27831, 1, 18, 1, 1, 0, 0, 0, 0, 14545), -- The Sorrow and the Fury
(27830, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Their Hunt Continues
(27829, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Wrath of a Dragonflight
(27828, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Eric, the Utility Dwarf
(27834, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Baelog, the Glass Cannon
(27835, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- Olaf, the Big Fella'
(27827, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Swift, the Fierce, and the Stout
(27826, 4, 5, 1, 1, 3000, 0, 0, 0, 14545), -- Into the Dragon's Mouth
(27794, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to Blam
(27824, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Good Stuff
(27715, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- The Day that Deathwing Came: What Really Happened
(27714, 5, 25, 0, 0, 0, 0, 0, 0, 14545), -- The Day that Deathwing Came: The Real Story
(27833, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Half-Ton Holdouts
(28512, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- To the Aid of the Thorium Brotherhood
(27825, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Survival of the Fattest
(12563, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Troll Patrol
(13891, 274, 5, 0, 0, 200, 800, 0, 0, 14545), -- The Devourer of Darkshore
(13898, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Tides Turn Against Us
(13899, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Darkscale Warlord
(13953, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Naga In Our Midst
(13885, 1, 397, 0, 0, 0, 1200, 0, 0, 14545), -- In Defense of Darkshore
(13925, 1, 6, 0, 0, 0, 900, 0, 0, 14545), -- An Ounce of Prevention
(13882, 1, 0, 0, 0, 50, 0, 0, 0, 14545), -- The Seeds of Life
(13895, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Slumbering Ancients
(13910, 25, 274, 0, 0, 0, 600, 0, 0, 14545), -- A New Home
(13918, 1, 25, 273, 0, 0, 1000, 300, 0, 14545), -- The Titans' Terminal
(13909, 6, 1, 0, 0, 0, 600, 0, 0, 14545), -- Got Some Flotsam?
(13912, 1, 273, 6, 0, 50, 500, 600, 0, 14545), -- Swamped Secrets
(13911, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Absent-Minded Prospector
(13907, 1, 5, 0, 0, 0, 500, 0, 0, 14545), -- Sweeping Clean the Ruins
(13893, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Soggoth and Kronn
(13546, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Defiler
(13572, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Jadefire Braziers
(13545, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Cleansing the Afflicted
(13896, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Unearthed Knowledge
(13544, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Bear's Blessing
(13948, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stepping Up Surveillance
(13526, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Bear's Paw
(13583, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Wildkin's Oath
(13582, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Elune's Fire
(13561, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Solace for the Highborne
(13528, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Buzzbox 723
(13527, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- No Accounting for Taste
(13521, 5, 0, 0, 0, 0, 0, 0, 0, 14545); -- Buzzbox 413

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13520, 2, 1, 0, 0, 0, 60, 0, 0, 14545), -- The Boon of the Seas
(14316, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Cenarion Property
(14314, 396, 396, 0, 0, 0, 1000, 0, 0, 14545), -- Breakout!
(14312, 2, 396, 0, 0, 0, 1000, 0, 0, 14545), -- An Introduction Is In Order
(14309, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Calming the Kodo
(14311, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Taking Part
(14307, 396, 396, 0, 0, 0, 1000, 0, 0, 14545), -- Stubborn Winds
(14304, 396, 396, 0, 0, 0, 1000, 0, 0, 14545), -- Blood Theory
(14305, 396, 396, 0, 0, 0, 1000, 0, 0, 14545), -- A Time to Reap
(14306, 396, 1, 0, 0, 0, 0, 0, 0, 14545), -- Pulling Weeds
(13515, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ending the Threat
(13514, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Ancients' Ire
(13590, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Front Line
(13512, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Strategic Strikes
(13513, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- On the Brink
(13844, 3, 396, 273, 0, 100, 800, 500, 0, 14545), -- The Looting of Althalaxx
(13507, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Denying Manpower
(13509, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- War Supplies
(13505, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Remnants of the Highborne
(13504, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Shatterspear Laborers
(13589, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Shatterspear Invaders
(13560, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- An Ocean Not So Deep
(13523, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Power Over the Tides
(13599, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Grimclaw's Return
(13569, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Ritual Bond
(13598, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Unsavory Remedies
(13566, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ritual Materials
(13565, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Twice Removed
(13562, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Final Flame of Bashal'Aran
(13564, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Lost Companion
(13563, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Love Eternal
(13831, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Troubling Prescription
(13557, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bearer of Good Fortune
(13529, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Corruption's Source
(13554, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Cure In The Dark
(27530, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Corpsebeasts
(27527, 1, 1, 25, 4, 0, 0, 0, 0, 14545), -- Journey's End
(12436, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Supplemental Income
(12175, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gray Worg Hides
(12468, 274, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Conqueror's Task
(13189, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Saurfang's Blessing
(12747, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- A Special Surprise
(9146, 6, 0, 0, 0, 0, 0, 0, 0, 14545), -- Report to Captain Helios
(9143, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dealing with Zeb'Sora
(9216, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rotting Hearts
(9218, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Spinal Dust
(11729, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Ultrasonic Screwdriver
(27713, 1, 14, 0, 0, 0, 0, 0, 0, 14545), -- The Day that Deathwing Came
(28322, 1, 1, 2, 0, 0, 0, 0, 0, 14545), -- The Spoils of War
(28321, 1, 1, 4, 0, 0, 0, 0, 0, 14545), -- Glory Amidst Chaos
(28320, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Assault on Dreadmaul Rock
(28327, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Locked and Loaded
(28319, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Delivery for Xi'lun
(28318, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- A Delivery for Neeralak
(28317, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- A Delivery for Thorg'izog
(28326, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Placing the Pawns
(28316, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Deal With a Dragon
(28315, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Draconic Vanguard
(28314, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Blood Tour
(28313, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Heap of Delicious Worg
(28312, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Latent Demons of the Land
(28311, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Blackened Ashes
(28415, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- SEVEN! YUP!
(28310, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Morgan's Vigil
(28286, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Enough Damage For One Day
(28279, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Abuse of Power
(28278, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- I Am the Law and I Am the Lash
(28266, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Trial by Magma
(28265, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- General Thorg'izog
(28253, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Taking the Horn For Ourselves
(28252, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Kodocaller's Horn
(28246, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Strategic Cuts
(28245, 5, 397, 0, 0, 0, 0, 0, 0, 14545), -- Grunt Work
(28239, 1, 1, 22, 0, 0, 0, 0, 0, 14545), -- Into the Black Tooth Hovel
(28202, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Perfect Costume
(28254, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Needle in a Hellhole
(28227, 1, 1, 273, 0, 0, 0, 0, 0, 14545), -- Golem Training
(28184, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Chiselgrip, the Heart of the Steppes
(28183, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to Keeshan
(28182, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Shadow Boxing
(28181, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warlocks Have the Neatest Stuff
(28179, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mud Hunter
(28178, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Future Project
(28177, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Stocking Up
(28172, 1, 1, 5, 1, 0, 0, 0, 0, 14545), -- Done Nothing Wrong
(28416, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Burning Vengeance
(27469, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Friends on The Other Side
(27471, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Blackrock Anomaly
(26171, 397, 396, 396, 397, 0, 0, 0, 0, 14545), -- You Are Rakh'likh, Demon
(26170, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Final Ritual
(25706, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Neptool's Revenge
(26163, 396, 397, 396, 0, 0, 0, 0, 0, 14545), -- Time is Short
(25705, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- False Idols
(25703, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Atrocities
(25702, 51, 51, 0, 0, 1000, 1000, 0, 0, 14545), -- Home... Gone... Naga...
(10748, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Maxnar Must Die!
(10722, 5, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Meeting at the Blackwing Coven
(10893, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Longtail is the Lynchpin
(10894, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Wyrmskull Watcher
(10747, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Whelps of the Wyrmcult
(10719, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Did You Get The Note?
(10717, 2, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Poaching from Poachers
(10713, 1, 25, 1, 0, 0, 1000, 1000, 0, 14545), -- ...and a Time for Action
(10607, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Whispers of the Raven God
(10771, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- From the Ashes
(10770, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Little Embers
(10796, 1, 1, 0, 0, 0, 1000, 0, 0, 14545), -- Crush the Bloodmaul Camp!
(10795, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- A Date with Dorgok
(10753, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Culling the Wild
(10567, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Creating the Pendant
(10682, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Time for Negotiation...
(10712, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Test Flight: Ruuan Weald
(10675, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Show Them Gnome Mercy!
(10711, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Test Flight: Razaan's Landing
(10671, 1, 1, 6, 0, 0, 1000, 1000, 0, 14545), -- More than a Pound of Flesh
(10674, 1, 1, 6, 0, 0, 1000, 1000, 0, 14545), -- Trapping the Light Fantastic
(10632, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Cutting Your Teeth
(10620, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Ridgespine Menace
(10657, 1, 1, 25, 0, 0, 1000, 1000, 0, 14545), -- Ride the Lightning
(10710, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Test Flight: The Singing Ridge
(10557, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Test Flight: The Zephyrium Capacitorium
(10594, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- Gauging the Resonant Frequency
(10584, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Picking Up Some Power Converters
(27763, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- To Fuselight Proper
(27453, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Catalysm
(27450, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Frederick's Fish Fancy
(27481, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Out of the Ziggurat
(27449, 1, 25, 23, 0, 0, 0, 0, 0, 14545), -- Honor and Strength
(27452, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Dark Garb
(27451, 1, 1, 1, 5, 0, 0, 0, 0, 14545), -- To Kill With Purpose
(12041, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- The Lost Empire
(13182, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Don't Forget the Eggs!
(12040, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- An Enemy in Arthas
(11592, 25, 1, 6, 0, 0, 0, 0, 0, 14545), -- We Strike!
(13204, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Funky Fungi
(25719, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Demoniac Vessel
(25718, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- How Best to Proceed
(13190, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- All Things in Good Time
(26049, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Princess Unleashed
(26038, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Attack on the Tower
(26346, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Myzrael's Tale
(26042, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Breaking the Keystone
(26037, 6, 1, 1, 0, 0, 0, 0, 0, 14545), -- Trelane's Defenses
(26095, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stromgarde Badges
(26036, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Wand over Fist
(26117, 11, 1, 6, 0, 0, 0, 0, 0, 14545), -- For Southshore
(26116, 6, 0, 0, 0, 0, 0, 0, 0, 14545), -- Kinelory Strikes
(26114, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Quae Trusts You
(26110, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Just Like Old Times
(26041, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stones of Binding
(26039, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Princess Trapped
(26341, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Stone Shards
(26982, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Scarlet Monastery
(24540, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- War Dance
(6364, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to Varg
(24550, 29, 0, 0, 0, 0, 0, 0, 0, 14545), -- Journey into Thunder Bluff
(24524, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wildmane Cleansing
(861, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Hunter's Way
(773, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rite of Wisdom
(24523, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wildmane Totem
(20441, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rite of Vision
(24457, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rite of Vision
(27978, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ghostbuster
(27975, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- WANTED: Foreman Wellson
(28165, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- D-Block
(28185, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Svarnos
(26190, 5, 1, 1, 1, 0, 0, 0, 0, 14545), -- A Fisherman's Feast
(543, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Perenolde Tiara
(270, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Doomed Fleet
(27156, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- It's About Time!
(14036, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Pilgrim's Bounty
(11639, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- Revenge Upon Magmoth
(11635, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Farseer Grimwalker's Spirit
(11631, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vision of Air
(11629, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to the Spirit Talker
(11569, 36, 0, 0, 0, 0, 0, 0, 0, 14545), -- Keymaster Urmgrgl
(11570, 389, 0, 0, 0, 0, 0, 0, 0, 14545), -- Escape from the Winterfin Caverns
(11566, 1, 5, 0, 0, 0, 0, 0, 0, 14545), -- Surrender... Not!
(11565, 389, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Spare Suit
(11564, 389, 0, 0, 0, 0, 0, 0, 0, 14545), -- Succulent Orca Stew
(11563, 54, 36, 0, 0, 0, 0, 0, 0, 14545), -- Grmmurggll Mrllggrl Glrggl!!!
(11562, 1, 1, 20, 0, 0, 0, 0, 0, 14545), -- I'm Being Blackmailed By My Cleaner
(11560, 1, 1, 25, 0, 0, 0, 0, 0, 14545), -- Oh Noes, the Tadpoles!
(11561, 35, 36, 0, 0, 0, 0, 0, 0, 14545), -- Them!
(11559, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Winterfin Commerce
(11649, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Motes of the Enraged
(9499, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Falcon Watch
(9590, 1, 1, 0, 0, 0, 1000, 0, 0, 14545), -- The Blood is Life
(9588, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dark Tidings
(25717, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- The Demons and the Druid
(25701, 397, 396, 396, 397, 0, 0, 0, 0, 14545), -- You Are Rakh'likh, Demon
(25700, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Loramus Thalipedes Awaits
(25698, 396, 396, 1, 0, 0, 0, 0, 0, 14545), -- The Amulet of Sevine
(25699, 153, 396, 396, 0, 0, 0, 0, 0, 14545), -- The Amulet of Grol
(25697, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- The Amulet of Allistarj
(29402, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Taking Precautions
(29399, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Shopping Around
(29398, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Fencing the Goods
(27460, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Soft Landing
(27459, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Brotherhood of Light
(27458, 6, 1, 5, 0, 0, 0, 0, 0, 14545), -- Smokey and the Bandage
(28505, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Battle for Andorhal
(8353, 5, 1, 0, 0, 0, 0, 0, 0, 14545), -- Chicken Clucking for a Mint
(29103, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Serpents and Poison
(11131, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stop the Fires!
(8356, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Flexing for Nougat
(29392, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Missing Heirlooms
(29144, 5, 1, 0, 0, 0, 0, 0, 0, 14545), -- Clean Up in Stormwind
(29054, 5, 1, 0, 0, 0, 0, 0, 0, 14545), -- Stink Bombs Away!
(29430, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Friend in Need
(8311, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Hallow's End Treats for Jesper!
(29371, 70, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Time to Lose
(29075, 70, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Time to Gain
(29074, 70, 1, 0, 0, 0, 3, 0, 0, 14545), -- A Season for Celebration
(10290, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- In Search of Farahlite
(10429, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- When Nature Goes Too Far
(13111, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- One of a Kind
(13556, 6, 5, 1, 0, 0, 0, 0, 0, 14545), -- Eggs for Dubra'Jin
(13098, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- For Posterity
(12891, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- I Have an Idea, But First...
(13227, 5, 1, 1, 5, 0, 0, 0, 0, 14545), -- Judgment Day Comes!
(12892, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- It's All Fun and Games
(13419, 5, 1, 5, 0, 0, 60, 60, 0, 14545), -- Preparations for War
(26644, 18, 396, 113, 0, 0, 0, 0, 0, 14545), -- Attracting Attention
(26634, 397, 396, 396, 0, 0, 0, 0, 0, 14545), -- The Bane of Many A Pirate
(26635, 5, 18, 5, 0, 0, 0, 0, 0, 14545), -- Cannonball Swim
(26633, 22, 22, 0, 0, 0, 0, 0, 0, 14545), -- Swabbing Duty
(26631, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Your First Day as a Pirate
(26595, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Kill-Collect
(26594, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to MacKinley
(29153, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Booty Bay's Interests
(26814, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- High Priest Venoxis
(26813, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Plunging Into Zul'Gurub
(26812, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- High Priestess Jeklik
(26811, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Through the Troll Hole
(26810, 25, 396, 2, 0, 0, 0, 0, 0, 14545), -- Eliminate the Outcast
(26809, 66, 396, 396, 0, 0, 0, 0, 0, 14545), -- Backdoor Dealings
(26808, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Maywiki
(26819, 6, 1, 1, 0, 0, 0, 0, 0, 14545), -- Akiris by the Bundle
(26820, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- If They're Just Going to Leave Them Lying Around...
(26816, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Recipe for Disaster
(26821, 6, 1, 1, 0, 0, 0, 0, 0, 14545), -- Airwyn Bantamflax
(26824, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Results: Inconclusive
(26818, 397, 396, 5, 0, 0, 0, 0, 0, 14545), -- Plush Pelts
(26815, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Zanzil's Secret
(26817, 396, 397, 396, 0, 0, 0, 0, 0, 14545), -- Perfectly Pure
(29152, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Making Contact
(29151, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bad Supplies
(29150, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Voodoo Zombies
(29133, 0, 0, 0, 0, 0, 0, 0, 0, 14545); -- To the Digsite

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29131, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Defend the Rebel Camp
(29124, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Warn the Rebel Camp
(29121, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bury Me With Me Boots...
(29213, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- How's the Hunter Holding Up?
(29120, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mauti
(29116, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Follow That Cat
(29115, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Hunter's Revenge
(29114, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Track the Tracker
(29105, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Nesingwary Will Know
(29104, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Spirits Are With Us
(27415, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Brood of Onyxia
(27417, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Brood of Onyxia
(27416, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Brood of Onyxia
(27256, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Black Shield
(27306, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Talk to Ogron
(27255, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Black Shield
(14064, 378, 0, 0, 0, 0, 0, 0, 0, 14545), -- Sharing a Bountiful Feast
(29318, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Ribs for the Sentinels
(9803, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Messenger to the Feralfen
(14289, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Safety in Numbers
(14279, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Learning the Word
(14278, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Seek the Sister
(13153, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Warding the Warriors
(13186, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stop the Siege
(13177, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- No Mercy for the Merciless
(26628, 5, 25, 5, 0, 0, 0, 0, 0, 14545), -- Death From Below
(26052, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Speak to Shakes
(26051, 1, 29, 0, 0, 0, 0, 0, 0, 14545), -- Sunken Treasure
(26055, 1, 18, 1, 0, 0, 0, 0, 0, 14545), -- Drowned Sorrows
(26050, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Goggle Boggle
(25868, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Yorla Darksnare
(25867, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gnoll Escape
(25866, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dark Iron Trappers
(25855, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gizmos and Gadgets
(25865, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Mosshide Job
(25857, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Hunting Horrorjaw
(25856, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Crocolisk Hides
(25864, 396, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dinosaur Crisis
(25854, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- I'll Call Him Bitey
(26139, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Into Arathi
(26128, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Battle of Thandol Span
(26127, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Twilight's Hammer Revealed
(26327, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Anvilmar the Hero
(26196, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Longbraid the Grim
(25939, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- For Peat's Sake
(25927, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Threat of Flame
(25926, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mired in Hatred
(26120, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Crazed Dragonmaw
(26195, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Who Wards The Greenwarden
(26189, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Angerfang Menace
(25853, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Tooling Around
(25850, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Strike the Earth!
(25849, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- When Archaeology Attacks
(25819, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Eye of Paleth
(25818, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Lifting the Curse
(25817, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Cursed Crew
(26955, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Zen'Kiki and the Cultists
(27055, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Students of Krastinov
(27054, 1, 25, 1, 0, 0, 0, 0, 0, 14545), -- Desperate Acts
(27057, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return to the Stead
(27370, 1, 1, 6, 0, 0, 0, 0, 0, 14545), -- Tarenar Sunstrike
(27367, 1, 5, 1, 274, 0, 0, 0, 0, 14545), -- Gidwin Goldbraids
(27144, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Reckoning
(27090, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Andorhal, Once and For All
(27089, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Ace in the Hole
(27087, 397, 396, 0, 0, 0, 0, 0, 0, 14545), -- Lindsay Ravensun, Revealed
(27085, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Supporting the Troops
(27086, 397, 396, 0, 0, 0, 0, 0, 0, 14545), -- Ashes to Ashes
(27084, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- The Farmers' Militia
(27083, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Battle Resumes!
(27155, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Turning Yourself In
(27154, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bagging Bisp
(27153, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Good People of Hearthglen
(27152, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Unusual Behavior... Even For Gnolls
(26938, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Combat Training
(26937, 1, 1, 22, 0, 0, 0, 0, 0, 14545), -- When Death is Not Enough
(26979, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Strange New Faces
(27017, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Memories from a Lost Past
(27053, 5, 1, 1, 1, 0, 0, 0, 0, 14545), -- Gahrron's Withering Cauldron
(26930, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- After the Crusade
(27683, 1, 1, 6, 0, 0, 0, 0, 0, 14545), -- Into the Woods
(26926, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Victory, For Now
(27157, 66, 1, 6, 0, 0, 0, 0, 0, 14545), -- Drudges... <Sigh>
(27151, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Taelan Fordring's Legacy
(26957, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Long Trip Home
(27012, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- A Gnoll's Resolve
(27011, 1, 396, 396, 0, 0, 0, 0, 0, 14545), -- Redpine Thievery
(27002, 5, 1, 1, 0, 0, 0, 0, 0, 14545), -- An Audience with the Highlord
(27001, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- This Means WAR (Wild Arachnid Roundup)
(27013, 396, 396, 25, 0, 0, 0, 0, 0, 14545), -- Too Close for Comfort
(27000, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Learning the Ropes
(26954, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- A Different Approach
(26935, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Northridge Lumber Mill
(26956, 1, 1, 479, 0, 0, 0, 0, 0, 14545), -- I Ain't Sayin' You a Gourd-Digger...
(26953, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Zen'Kiki, the Druid
(26999, 1, 1, 273, 0, 0, 0, 0, 0, 14545), -- A New Era for the Plaguelands
(26952, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Menders' Stead
(26978, 6, 22, 1, 0, 0, 0, 0, 0, 14545), -- Who Needs Cauldrons?
(26933, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Foes Before Hoes
(26925, 1, 5, 0, 0, 0, 0, 0, 0, 14545), -- Araj the Summoner
(27117, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Brute Strength
(26924, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Scholomancer
(26923, 1, 1, 397, 0, 0, 0, 0, 0, 14545), -- War Machines
(26921, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Scourge First... Alliance Later
(26922, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Endless Flow
(26920, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- The Battle for Andorhal
(26934, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Latent Disease
(26931, 1, 5, 1, 0, 0, 0, 0, 0, 14545), -- Foxes and Hounds
(11593, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Honored Dead
(11594, 1, 6, 0, 0, 0, 0, 0, 0, 14545), -- Put Them to Rest
(10095, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Into the Heart of the Labyrinth
(10091, 5, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- The Soul Devices
(10094, 1, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- The Codex of Blood
(10178, 15, 1, 1, 18, 0, 0, 0, 0, 14545), -- Find Spy To'gun
(27467, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Buried Blades
(27465, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Argent Call: The Noxious Glade
(27464, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Argent Call: The Trial of the Crypt
(27463, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Boyhood Dream
(27455, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Boys Will Be Boys
(27390, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Battle of Darrowshire
(27421, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Amidst Death, Life
(27420, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Postponing the Inevitable
(27448, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Trek Continues
(27544, 1, 1, 6, 1, 0, 0, 0, 0, 14545), -- Cenarion Tenacity
(27389, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Marauders of Darrowshire
(27388, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Heroes of Darrowshire
(27387, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Villains of Darrowshire
(27386, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Strange Historian
(27385, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Uncle Carlin
(27392, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- I'm Not Supposed to Tell You This
(27384, 1, 18, 1, 0, 0, 0, 0, 0, 14545), -- Pamela's Doll
(27382, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Rough Roads
(27383, 1, 1, 6, 0, 0, 0, 0, 0, 14545), -- Little Pamela
(27381, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Traveling Companions
(27432, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Zaeldarr the Outcast
(27373, 1, 5, 1, 0, 0, 0, 0, 0, 14545), -- Onward, to Light's Hope Chapel
(27372, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Gift For Fiona
(27371, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- What I Do Best
(27369, 2, 1, 25, 1, 0, 0, 0, 0, 14545), -- Greasing the Wheel
(27368, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Just Encased
(27534, 1, 5, 0, 0, 0, 0, 0, 0, 14545), -- Augustus' Receipt Book
(27533, 24, 11, 1, 0, 0, 0, 0, 0, 14545), -- A Fate Worse Than Butchery
(27535, 1, 6, 0, 0, 0, 0, 0, 0, 14545), -- Just a Little Touched
(27531, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Counter-Plague Research
(27762, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Fuselight, Ho!
(27620, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- Like Rats
(27617, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Befouled No More
(27618, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Argent Upheaval
(27612, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Victory From Within
(27613, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Assassin
(27619, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Commander
(27616, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Huntsman
(27615, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Wrathcaster
(27614, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Scarlet Salvage
(27462, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- To Take the Barracks
(27461, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- To Take the Abbey
(27456, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Gathering Some Grub(s)
(27880, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Half-Ton Holdouts
(27927, 1, 1, 273, 0, 0, 0, 0, 0, 14545), -- Down to the Scar
(27879, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Survival of the Fattest
(28069, 15, 0, 0, 0, 0, 0, 0, 0, 14545), -- Adventurers Wanted: Blackrock Depths
(28417, 1, 1, 5, 1, 0, 0, 0, 0, 14545), -- Done Nothing Wrong
(28418, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Burning Vengeance
(28299, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Meet with Kranosh
(28677, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warchief's Command: Swamp of Sorrows!
(28667, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warchief's Command: Burning Steppes!
(14023, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Spice Bread Stuffing
(28821, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Rear is Clear
(28811, 6, 5, 5, 20, 0, 0, 0, 0, 14545), -- Fear No Evil
(28795, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- They Sent Assassins
(28787, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Join the Battle!
(26915, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Deepest Cut
(28772, 274, 1, 25, 5, 0, 0, 0, 0, 14545), -- Lions for Lambs
(28764, 6, 2, 1, 5, 0, 0, 0, 0, 14545), -- Beating Them Back!
(26804, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Flight to Razor Hill
(26803, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Missing Reports
(14011, 2, 25, 0, 0, 0, 0, 0, 0, 14545), -- Primal Strike
(26212, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Lard Lost His Lunch
(26959, 1, 1, 4, 0, 0, 0, 0, 0, 14545), -- Stripping Their Defenses
(26240, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Stomp To My Beat
(26223, 1, 1, 5, 0, 0, 0, 0, 0, 14545), -- Stalking the Stalkers
(26987, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Right Way
(26211, 1, 1, 1, 5, 0, 0, 0, 0, 14545), -- Snapjaws, Mon!
(26210, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Gammerita, Mon!
(26030, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Sigil of Strom
(26025, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Traitor Orc
(26023, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Forsaken Trollbane
(26027, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Call to Arms
(26430, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Revantusk Village
(26950, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Dark Side of the Light
(26986, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Into the Scarlet Monastery
(26429, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Crush the Witherbark
(26108, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Guile of the Raptor
(14065, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Sharing a Bountiful Feast
(26909, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Stone Shards
(26107, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Raising Spirits
(4601, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Sparklematic 5200!
(26428, 15, 1, 1, 0, 0, 0, 0, 0, 14545), -- To Steal From Thieves
(26053, 15, 6, 1, 0, 0, 0, 0, 0, 14545), -- Clearing the Highlands
(26022, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- First Blood
(9173, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Retaking Windrunner Spire
(9163, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Into Occupied Territory
(9207, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Underlight Ore Samples
(27365, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Fitting Weapon
(10166, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Whitebark's Memory
(8474, 6, 0, 0, 0, 0, 0, 0, 0, 14545), -- Old Whitebark's Pendant
(26778, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Cries of the Dead
(26725, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Guided by the Light
(26724, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Lurking Lich
(26793, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Weathered Grave
(26723, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Fate of Morbent Fel
(26760, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Cry For The Moon
(26735, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- The Fate of Kurzen
(26787, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bear In Mind
(26721, 18, 20, 0, 0, 0, 0, 0, 0, 14545), -- The Jitters-Bugs
(26720, 396, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Curse We Cannot Lift
(26838, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Rebels Without a Clue
(26777, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Soothing Spirits
(26719, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Delivery to Master Harris
(26717, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Yorgen Worgen
(26707, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Deadly Vine
(25235, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vulgar Vul'Gol
(26785, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Part of the Pack
(26674, 1, 1, 25, 0, 0, 0, 0, 0, 14545), -- Mistmantle's Revenge
(26672, 1, 22, 25, 0, 0, 0, 0, 0, 14545), -- Clawing at the Truth
(26671, 1, 22, 25, 0, 0, 0, 0, 0, 14545), -- The Fate of Stalvan Mistmantle
(26727, 5, 1, 5, 0, 0, 0, 0, 0, 14545), -- The Embalmer's Revenge
(26681, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Note to the Mayor
(26677, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ghoulish Effigy
(26670, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Roland's Doom
(26669, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- In A Dark Corner
(26680, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ogre Thieves
(26676, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Juice Delivery
(26661, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Gather Rot Blossoms
(26660, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Zombie Juice
(26655, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Deliver the Thread
(26654, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return the Comb
(26652, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ghost Hair Thread
(26667, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Stolen Letters
(26685, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Classy Glass
(26684, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Insane Ghoul
(26653, 18, 0, 0, 0, 0, 0, 0, 0, 14545), -- Supplies from Darkshire
(26683, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Look To The Stars
(26666, 1, 1, 1, 25, 0, 0, 0, 0, 14545), -- The Legend of Stalvan
(26686, 5, 25, 0, 0, 0, 0, 0, 0, 14545), -- Bones That Walk
(26645, 1, 5, 0, 0, 0, 0, 0, 0, 14545), -- The Night Watch
(26627, 25, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Hermit
(26691, 66, 0, 0, 0, 0, 0, 0, 0, 14545), -- Worgen in the Woods
(26623, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Dusky Crab Cakes
(26620, 1, 1, 0, 0, 0, 0, 0, 0, 14545); -- Seasoned Wolf Kabobs

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26690, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vile and Tainted
(26618, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Wolves at Our Heels
(26689, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Rotting Orchard
(26688, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Worgen in the Woods
(14041, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Cranberry Chutney
(14062, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Don't Forget The Stuffing!
(14040, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Pumpkin Pie
(28571, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warchief's Command: Hillsbrad Foothills!
(14061, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Can't Get Enough Turkey
(27987, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Cannonball!
(27691, 396, 0, 0, 0, 0, 0, 0, 0, 14545), -- Marshfin Madness
(27740, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Baba Bogbrew
(27600, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- In With a Bang
(27599, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Can't Take It With Them
(27598, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Kill Gil
(27597, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Crazy Larry
(27663, 25, 1, 0, 0, 0, 0, 0, 0, 14545), -- Tastes Like Strider
(27536, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Mostly Harmless
(27656, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Croc-Out
(27587, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Maliciously Delicious
(27851, 25, 0, 0, 0, 0, 0, 0, 0, 14545), -- Cutting Supply
(27849, 25, 0, 0, 0, 0, 0, 0, 0, 14545), -- Assault on Stonard
(27918, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Harborage
(27845, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Marking the Fallen
(27843, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Reinforcements Denied
(27795, 25, 0, 0, 0, 0, 0, 0, 0, 14545), -- Tides of Darkness
(27840, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Draenethyst Crystals
(27860, 5, 1, 1, 0, 0, 1000, 1000, 0, 14545), -- The Lost Ones
(27822, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Lumbering Oafs
(27821, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Orcs and Humans
(24913, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Remember the Light
(27904, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Breath of Mist
(27902, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Purespring
(27876, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Secrets of the Mire
(27875, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Prayerblossom
(26779, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Zul'Mamwe Mambo
(26368, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Venomous Secrets
(26367, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Ongo'longo's Revenge
(26308, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- It's Ours Now
(26309, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Dark Vessels
(26307, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Death to the Vilebranch
(26310, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- All That Skitters
(26366, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Heads Up
(26306, 25, 0, 0, 0, 0, 0, 0, 0, 14545), -- Start Taking Back
(26357, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Faces of Evil
(26283, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Prime Slime
(26268, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Skulk Rock Supplies
(26267, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Skulk Rock Clean-Up
(26224, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Hunt the Savages
(26988, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Moving Things Along
(26263, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Thornar Thunderclash
(26238, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Savage Dwarves
(12541, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Troll Patrol: The Alchemist's Apprentice
(9493, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Pride of the Fel Horde
(12791, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Magical Kingdom of Dalaran
(11647, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Neutralizing the Cauldrons
(11641, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Courageous Strike
(11640, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Words of Power
(11695, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Horn of Elemental Fury
(12189, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Imbeciles Abound!
(12488, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The High Executor Needs You
(11979, 5, 1, 1, 1, 0, 0, 0, 0, 14545), -- The Taunka and the Tauren
(13682, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Threat From Above
(14080, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Stop The Aggressors
(13750, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Grand Melee
(13747, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Worthy Weapon
(10296, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Black Morass
(10285, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Return to Andormu
(10284, 1, 1, 1, 5, 0, 0, 0, 0, 14545), -- Escape from Durnholde
(10283, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Taretha's Diversion
(29439, 1, 6, 25, 0, 0, 0, 0, 0, 14545), -- The Call of the World-Shaman
(26776, 94, 273, 94, 0, 0, 500, 500, 0, 14545), -- Ghaliri
(26775, 94, 273, 94, 0, 0, 500, 500, 0, 14545), -- Be Raptor
(26780, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Nighttime in the Jungle
(26774, 94, 273, 94, 0, 0, 500, 500, 0, 14545), -- Mind Control
(26773, 94, 273, 94, 0, 0, 500, 500, 0, 14545), -- See Raptor
(26772, 94, 273, 94, 0, 0, 500, 500, 0, 14545), -- Mind Vision
(26749, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Priestess Thaalia
(26984, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- An Old, Crazed Friend
(26781, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Mind's Eye
(26944, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Exploring Gnomeregan
(26805, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- To the Cape!
(26782, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Mosh'Ogg Bounty
(26748, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Bloodlord Mandokir
(26751, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Population Con-Troll
(26747, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Physical Specimen
(26731, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Altar of Naias
(26746, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Nose for This Sort of Thing
(26730, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- You Can Take the Murloc Out of the Ocean...
(26743, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Sacred to the Bloodscalp
(26745, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Favored Skull
(26742, 2, 1, 1, 0, 0, 0, 0, 0, 14545), -- Bloodscalp Insight
(26729, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Water Elementals
(26737, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Stopping Kurzen's Legacy
(26744, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Deep Roots
(26734, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Source of the Madness
(26765, 5, 2, 0, 0, 0, 0, 0, 0, 14545), -- Return to Corporal Kaleb
(26739, 396, 0, 0, 0, 0, 0, 0, 0, 14545), -- I Think She's Hungry
(26736, 1, 1, 25, 273, 0, 0, 0, 0, 14545), -- Spared from Madness
(26733, 432, 432, 5, 1, 0, 0, 0, 0, 14545), -- Control Sample
(26738, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Just Hatched
(26763, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Venture Company Mining
(28671, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Warchief's Command: Blasted Lands!
(27402, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Token of Power
(27282, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Kranosh's Behest
(28790, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Personal Summons
(13277, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Against the Giants
(13355, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Cannot Reproduce
(13354, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Chain of Command
(13352, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Drag and Drop
(13351, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Sneak Preview
(13261, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Volatility
(13264, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- That's Abominable!
(13283, 25, 1, 1, 0, 0, 0, 0, 0, 14545), -- King of the Mountain
(13310, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Assault by Air
(13301, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Assault by Ground
(13293, 5, 274, 25, 0, 0, 0, 0, 0, 14545), -- Get to Ymirheim!
(13239, 396, 396, 396, 396, 0, 0, 0, 0, 14545), -- Volatility
(13237, 396, 396, 396, 0, 0, 0, 0, 0, 14545), -- Poke and Prod
(13234, 5, 5, 5, 0, 0, 100, 100, 0, 14545), -- Make Them Pay!
(13260, 396, 396, 0, 0, 0, 0, 0, 0, 14545), -- Takes One to Know One
(13238, 396, 396, 396, 0, 0, 0, 100, 0, 14545), -- Good For Something?
(13330, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Blood of the Chosen
(13340, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Joining the Assault
(13230, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Avenge Me!
(13302, 5, 1, 6, 0, 0, 0, 0, 0, 14545), -- Slaves to Saronite
(13258, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Opportunity
(13228, 6, 5, 5, 0, 0, 0, 0, 0, 14545), -- The Broken Front
(13224, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Orgrim's Hammer
(13213, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- Battle at Valhalas
(13142, 25, 1, 1, 0, 0, 0, 0, 0, 14545), -- Banshee's Revenge
(13104, 1, 1, 397, 0, 0, 0, 0, 0, 14545), -- Once More Unto The Breach, Hero
(13481, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Let's Get Out of Here!
(13235, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Flesh Giant Champion
(13220, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Putting Olakin Back Together Again
(13212, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- He's Gone to Pieces
(13144, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Killing Two Scourge With One Skeleton
(13152, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- A Visit to the Doctor
(13211, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- By Fire Be Purged
(13140, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- The Runesmiths of Malykriss
(13138, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- I'm Smelting... Smelting!
(13136, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Jagged Shards
(13134, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Spill Their Blood
(13120, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Death's Gaze
(13119, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Destroying the Altars
(13117, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Where Are They Coming From?
(13137, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Not-So-Honorable Combat
(13133, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Find the Ancient Hero
(12852, 1, 1, 25, 0, 0, 0, 0, 0, 14545), -- The Admiral Revealed
(12847, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Second Chances
(12815, 25, 1, 0, 0, 0, 0, 0, 0, 14545), -- No Fly Zone
(12813, 1, 274, 5, 25, 0, 0, 0, 0, 14545), -- From Their Corpses, Rise!
(12840, 1, 25, 5, 0, 0, 0, 0, 0, 14545), -- In Strict Confidence
(12814, 6, 1, 0, 0, 0, 0, 0, 0, 14545), -- You'll Need a Gryphon
(12839, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Grand (Admiral's) Plan
(12838, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Intelligence Gathering
(12810, 1, 1, 25, 0, 0, 0, 0, 0, 14545), -- Blood in the Water
(12807, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Story Thus Far...
(13121, 1, 1, 1, 0, 0, 0, 0, 0, 14545), -- Through the Eye
(13091, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- The Art of Being a Water Terror
(13059, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Revenge for the Vargul
(12806, 1, 6, 1, 0, 0, 0, 0, 0, 14545), -- To the Rise with all Due Haste!
(13043, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Sum is Greater than the Parts
(13042, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Deep in the Bowels of The Underhalls
(13092, 1, 25, 0, 0, 0, 2000, 0, 0, 14545), -- Reading the Bones
(12992, 33, 0, 0, 0, 0, 0, 0, 0, 14545), -- Crush Dem Vrykuls!
(13084, 1, 25, 11, 0, 0, 0, 0, 0, 14545), -- Vandalizing Jotunheim
(12982, 1, 25, 5, 0, 0, 0, 0, 0, 14545), -- Ebon Blade Prisoners
(13085, 5, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vaelen Has Returned
(12951, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Let the Baron Know
(12949, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Get the Key
(12943, 1, 25, 1, 0, 0, 0, 2000, 0, 14545), -- Shadow Vault Decree
(12999, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Bone Witch
(12955, 7, 1, 25, 0, 0, 2000, 0, 0, 14545), -- Eliminate the Competition
(12939, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- Honor Challenge
(13106, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Blackwatch
(12938, 25, 11, 1, 0, 0, 2000, 0, 0, 14545), -- The Duke
(12899, 1, 1, 0, 0, 0, 2000, 0, 0, 14545), -- The Shadow Vault
(10392, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Doorway to the Abyss
(10391, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Cannons of Rage
(10393, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Vile Plans
(9608, 1, 6, 0, 0, 0, 1000, 0, 0, 14545), -- Heart of Rage
(10864, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- A Burden of Souls
(10230, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Battle Horn
(10229, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Decipher the Tome
(10835, 1, 0, 0, 0, 0, 0, 0, 0, 14545), -- Apothecary Antonivich
(14128, 1, 25, 0, 0, 0, 0, 0, 0, 14545), -- Return of the Highborne?
(14127, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Return of the Highborne?
(26397, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- Walk With The Earth Mother
(14060, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Easy As Pie
(14043, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Candied Sweet Potatoes
(28820, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- The Rear is Clear
(28810, 6, 5, 5, 20, 0, 0, 0, 0, 14545), -- Fear No Evil
(28794, 0, 0, 0, 0, 0, 0, 0, 0, 14545), -- They Sent Assassins
(28786, 1, 1, 1, 1, 0, 0, 0, 0, 14545), -- Join the Battle!
(26919, 1, 1, 0, 0, 0, 0, 0, 0, 14545), -- Learning the Word
(28771, 274, 1, 25, 5, 0, 0, 0, 0, 14545), -- Lions for Lambs
(28763, 6, 2, 1, 5, 0, 0, 0, 0, 14545); -- Beating Them Back!

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=744; -- Preparation for Ceremony
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9545; -- The Seer's Relic
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9587; -- Dark Tidings
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9739; -- The Sporelings' Plight
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9743; -- Natural Enemies
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9763; -- The Warlord's Hideout
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9785; -- Blessings of the Ancients
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9806; -- Fertile Spores
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9808; -- Glowcap Mushrooms
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9827; -- Withered Basidium
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=9919; -- Sporeggar
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=12561; -- An Issue of Trust
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=12624; -- It Could Be Anywhere!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=12722; -- Lambs To The Slaughter
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=12738; -- A Cry For Vengeance!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=14545 WHERE `ID`=13167; -- Death to the Traitor King
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=10165; -- Undercutting the Competition
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=10216; -- Safety Is Job One
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=10218; -- Someone Else's Hard Work Pays Off
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12755; -- A Meeting With Fate
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12778; -- The Scarlet Apocalypse
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=14545 WHERE `ID`=12715; -- The Crypt of Remembrance
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=14545 WHERE `ID`=12725; -- Brothers In Death
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=14545 WHERE `ID`=12850; -- Report To Scourge Commander Thalanor
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=15, `VerifiedBuild`=14545 WHERE `ID`=12756; -- The Scarlet Onslaught Emerges
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=25, `VerifiedBuild`=14545 WHERE `ID`=12754; -- Ambush At The Overlook
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=66, `VerifiedBuild`=14545 WHERE `ID`=12751; -- A Sort Of Homecoming
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=273, `VerifiedBuild`=14545 WHERE `ID`=12720; -- How To Win Friends And Influence Enemies
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9780; -- Umbrafen Eel Filets
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9792; -- A Message to Telaar
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9830; -- Stinger Venom
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9833; -- Lines of Communication
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9834; -- Natural Armor
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9839; -- Overlord Gorefist
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9902; -- The Terror of Marshlight Lake
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9905; -- Maktu's Revenge
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=10282; -- Old Hillsbrad
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=10355; -- Withered Flesh
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12706; -- Victory At Death's Breach!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12717; -- Noth's Special Brew
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12719; -- Nowhere To Run And Nowhere To Hide
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12723; -- Behind Scarlet Lines
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12724; -- The Path Of The Righteous Crusader
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12727; -- Bloody Breakout
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12757; -- Scarlet Armies Approach...
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=13166; -- The Battle For The Ebon Hold
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=273, `Emote4`=25, `VerifiedBuild`=14545 WHERE `ID`=12714; -- The Will Of The Lich King
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14545 WHERE `ID`=12521; -- Where in the World is Hemet Nesingwary?
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14545 WHERE `ID`=12523; -- Have a Part, Give a Part
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14545 WHERE `ID`=12524; -- Venture Co. Misadventure
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=14545 WHERE `ID`=12654; -- The Part-time Hunter
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=14545 WHERE `ID`=12716; -- The Plaguebringer's Request
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `EmoteDelay2`=2000, `EmoteDelay3`=1000, `VerifiedBuild`=14545 WHERE `ID`=833; -- A Sacred Burial
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=12238; -- Cleansing Drak'Tharon
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=14545 WHERE `ID`=10277; -- The Caverns of Time
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=14545 WHERE `ID`=11451; -- Alicia's Poem
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12697; -- Gothik the Harvester
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12700; -- An Attack Of Opportunity
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=9896; -- Blacksting's Bane
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `VerifiedBuild`=14545 WHERE `ID`=12522; -- Need an Engine, Take an Engine
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=25, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12698; -- The Gift That Keeps On Giving
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=14545 WHERE `ID`=13159; -- Containment
UPDATE `quest_details` SET `Emote1`=5, `VerifiedBuild`=14545 WHERE `ID`=12489; -- Welcome to Sholazar Basin
UPDATE `quest_details` SET `Emote1`=274, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=14545 WHERE `ID`=12701; -- Massacre At Light's Point
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `Emote4`=397, `VerifiedBuild`=14545 WHERE `ID`=12779; -- An End To All Things...
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `VerifiedBuild`=14545 WHERE `ID`=13158; -- Discretion is Key
UPDATE `quest_details` SET `Emote3`=1, `VerifiedBuild`=14545 WHERE `ID`=10098; -- Terokk's Legacy
UPDATE `quest_details` SET `EmoteDelay1`=5000, `VerifiedBuild`=14545 WHERE `ID`=10294; -- Void Ridge
UPDATE `quest_details` SET `EmoteDelay2`=1000, `VerifiedBuild`=14545 WHERE `ID`=9572; -- Weaken the Ramparts
UPDATE `quest_details` SET `EmoteDelay4`=0, `VerifiedBuild`=14545 WHERE `ID`=12657; -- The Might Of The Scourge
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=743; -- Dangers of the Windfury
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=749; -- The Ravaged Caravan
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=761; -- Swoop Hunting
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=2159; -- Dolanaar Delivery
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=3102; -- Encrypted Letter
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=3103; -- Hallowed Letter
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=8563; -- Warlock Training
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9349; -- Ravager Egg Roundup
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9351; -- Voidwalkers Gone Wild
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9356; -- Smooth as Butter
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9361; -- Helboar, the Other White Meat
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9427; -- Cleansing the Waters
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9701; -- Observing the Sporelings
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9702; -- A Question of Gluttony
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9708; -- Familiar Fungi
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9709; -- Stealing Back the Mushrooms
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9717; -- Oh, It's On!
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9719; -- Stalk the Stalker
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9738; -- Lost in Action
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=9911; -- The Count of the Marshes
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10073; -- Corruption
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10097; -- Brother Against Brother
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10161; -- In Case of Emergency...
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10213; -- Investigate the Crash
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10227; -- I See Dead Draenei
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10228; -- Ezekiel
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10231; -- What Book? I Don't See Any Book.
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10250; -- Bloody Vengeance
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=10258; -- Honor the Fallen
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11356; -- Costumed Orphan Matron
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11360; -- Fire Brigade Practice
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11377; -- Revenge is Tasty
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11485; -- Iron Rune Constructs and You: Rocket Jumping
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11489; -- Iron Rune Constructs and You: Collecting Data
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11491; -- Iron Rune Constructs and You: The Bluff
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11494; -- Lightning Infused Relics
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11495; -- The Delicate Sound of Thunder
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=11501; -- News From the East
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12007; -- Sacrifices Must be Made
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12029; -- Seared Scourge
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12483; -- Shimmercap Stew
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12484; -- Scourgekabob
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12593; -- In Service Of The Lich King
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12619; -- The Emblazoned Runeblade
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12636; -- The Eye Of Acherus
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12641; -- Death Comes From On High
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12670; -- The Scarlet Harvest
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12678; -- If Chaos Drives, Let Suffering Hold The Reins
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12679; -- Tonight We Dine In Havenshire
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12680; -- Grand Theft Palomino
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12687; -- Into the Realm of Shadows
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12733; -- Death's Challenge
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12802; -- My Heart is in Your Hands
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12842; -- Runeforging: Preparation For Battle
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=12848; -- The Endless Hunger
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=13008; -- Scourge Tactics
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=13036; -- Honor Above All Else
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14222; -- Last Stand
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14313; -- Among Humans Again
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14320; -- In Need of Ingredients
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14321; -- Invasion
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14336; -- Kill or Be Killed
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14347; -- Hold the Line
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14348; -- You Can't Take 'Em Alone
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14366; -- Holding Steady
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14367; -- The Allens' Storm Cellar
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14368; -- Save the Children!
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14369; -- Unleash the Beast
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14382; -- Two By Sea
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14386; -- Leader of the Pack
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14395; -- Gasping for Breath
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14396; -- As the Land Shatters
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14397; -- Evacuation
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14398; -- Grandma Wahl
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14399; -- Grandma's Lost It Alright
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14400; -- I Can't Wear This
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14401; -- Grandma's Cat
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14403; -- The Hayward Brothers
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14404; -- Not Quite Shipshape
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14405; -- Escape By Sea
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14406; -- The Crowley Orchard
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14412; -- Washed Up
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14416; -- The Hungry Ettin
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14465; -- To Greymane Manor
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=14466; -- The King's Observatory
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24438; -- Exodus
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24468; -- Stranded at the Marsh
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24472; -- Introductions Are in Order
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24483; -- Stormglen
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24484; -- Pest Control
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24495; -- Pieces of the Past
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24501; -- Queen-Sized Troubles
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24575; -- Liberation Day
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24578; -- The Blackwald
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24592; -- Betrayal at Tempest's Reach
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24593; -- Neither Human Nor Beast
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24616; -- Losing Your Tail
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24617; -- Tal'doren, the Wild Home
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24627; -- At Our Doorstep
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24628; -- Preparations
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24646; -- Take Back What's Ours
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24672; -- Onwards and Upwards
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24673; -- Return to Stormglen
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24674; -- Slaves to No One
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24675; -- Last Meal
UPDATE `quest_details` SET `VerifiedBuild`=14545 WHERE `ID`=24677; -- Flank the Forsaken

DELETE FROM `quest_details` WHERE `ID`=14007;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14007, 2, 25, 0, 0, 0, 0, 0, 0, 15005); -- Steady Shot

DELETE FROM `quest_details` WHERE `ID` IN (25476 /*Rescue OOX-22/FE!*/, 25450 /*Improved Quality*/, 25475 /*Find OOX-22/FE!*/, 25466 /*Even More Fuel for the Zapping*/, 25465 /*Still With The Zapped Giants*/, 25437 /*Ysondre's Call*/, 25436 /*Spiteful Sisters*/, 25431 /*Stinglasher*/, 25429 /*Zukk'ash Infestation*/, 25433 /*Sasquatch Sighting*/, 25434 /*Taming The Tamers*/, 25427 /*Alpha Strike*/, 25468 /*Forces of Nature: Faerie Dragons*/, 25469 /*Forces of Nature: Mountain Giants*/, 25333 /*Might of the Sentinels*/, 25208 /*Tell Silvia*/, 25403 /*Ogre Abduction*/, 25410 /*Forces of Nature: Treants*/, 25406 /*Gordok Guards*/, 25402 /*Estulan's Examination*/, 25409 /*Forces of Nature: Hippogryphs*/, 25400 /*The Gordunni Threat*/, 25401 /*The Gordunni Orb*/, 26574 /*Adella's Covert Camp*/, 25407 /*Forces of Nature: Wisps*/, 25350 /*The Lost Apprentice*/, 27133 /*Eyes in the Sky*/, 25394 /*More Than Illness*/, 25448 /*The Northspring Menace*/, 25654 /*Dark Heart*/, 27129 /*Saving Warpwood*/, 27131 /*The Highborne*/, 27063 /*Looming Threat*/, 25447 /*Signs of Change*/, 13588 /*The Eye of All Storms*/, 13940 /*Leaving the Dream*/, 13587 /*The Waking Nightmare*/, 13586 /*The Emerald Dream*/, 28788 /*Join the Battle!*/, 26914 /*Corruption*/, 13578 /*Aroom's Farewell*/, 13581 /*The Blackwood Pledge*/, 13580 /*Soothing the Elements*/, 13576 /*Mutual Aid*/, 13585 /*Sworn to Protect*/, 13584 /*Calming the Earth*/, 13579 /*Protector of Ameth'Aran*/, 13575 /*The Land Is in Their Blood*/, 13577 /*The Last Wildkin*/, 9923 /*HELP!*/, 8872 /*The Lunar Festival*/, 8868 /*Elune's Blessing*/, 8874 /*The Lunar Festival*/, 13881 /*Consumed*/, 13892 /*Leave No Tracks*/, 13525 /*What's Happening to the Blackwood Furbolg?*/, 13902 /*Mounting the Offensive*/, 13558 /*Call Down the Thunder*/, 13543 /*Three Hammers to Break*/, 13573 /*Malfurion's Return*/, 13542 /*Against the Wind*/, 27265 /*Lord Grayson Shadowbreaker*/, 13605 /*The Last Refugee*/, 13547 /*Coaxing the Spirits*/, 29253 /*A Shiny Reward*/, 24511 /*Echoes of Tortured Souls*/, 10629 /*Shizz Work*/, 10238 /*How to Serve Goblins*/, 10236 /*Outland Sucks!*/, 10876 /*The Foot of the Citadel*/, 10875 /*Report to Nazgrel*/, 9406 /*The Mag'har*/, 10838 /*The Demoniac Scryer*/, 9410 /*A Spirit Guide*/, 9405 /*The Warchief's Mandate*/, 9401 /*A Strange Weapon*/, 10389 /*The Agony and the Darkness*/, 10136 /*Cruel's Intentions*/, 29688 /*Advancing the Campaign*/, 10274 /*Securing the Celestial Ridge*/, 10273 /*Troublesome Distractions*/, 10272 /*A Promising Start*/, 10281 /*Formal Introductions*/, 10271 /*Getting Down to Business*/, 10270 /*A Not-So-Modest Proposal*/, 10526 /*The Thunderspike*/, 10525 /*Vision Guide*/, 10524 /*Thunderlord Clan Artifacts*/, 29250 /*Making Contact*/, 29238 /*Bad Supplies*/, 29237 /*Voodoo Zombies*/, 29236 /*To Hardwrench Hideaway*/, 29235 /*Defend Grom'gol*/, 29233 /*Warn Grom'gol*/, 29232 /*Bury Me With Me Boots...*/, 29231 /*How's the Hunter Holding Up?*/, 29230 /*Mauti*/, 29228 /*Follow That Cat*/, 29227 /*The Hunter's Revenge*/, 29226 /*Track the Tracker*/, 29223 /*Nesingwary Will Know*/, 29222 /*Spirits Are With Us*/, 29221 /*Serpents and Poison*/, 29220 /*To Bambala*/, 12469 /*Return to Sender*/, 10912 /*The Hound-Master*/, 10911 /*Fire At Will!*/, 10904 /*Harvesting the Fel Ammunition*/, 10910 /*Death's Door*/, 10821 /*You're Fired!*/, 10820 /*Deceive thy Enemy*/, 10819 /*Felsworn Gas Mask*/, 10812 /*Mystery Mask*/, 10810 /*Damaged Mask*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25476, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Rescue OOX-22/FE!
(25450, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Improved Quality
(25475, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Find OOX-22/FE!
(25466, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Even More Fuel for the Zapping
(25465, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Still With The Zapped Giants
(25437, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Ysondre's Call
(25436, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Spiteful Sisters
(25431, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Stinglasher
(25429, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Zukk'ash Infestation
(25433, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Sasquatch Sighting
(25434, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Taming The Tamers
(25427, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Alpha Strike
(25468, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Forces of Nature: Faerie Dragons
(25469, 66, 0, 0, 0, 0, 0, 0, 0, 15050), -- Forces of Nature: Mountain Giants
(25333, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Might of the Sentinels
(25208, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Tell Silvia
(25403, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Ogre Abduction
(25410, 66, 0, 0, 0, 0, 0, 0, 0, 15050), -- Forces of Nature: Treants
(25406, 25, 0, 0, 0, 0, 0, 0, 0, 15050), -- Gordok Guards
(25402, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Estulan's Examination
(25409, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Forces of Nature: Hippogryphs
(25400, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Gordunni Threat
(25401, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Gordunni Orb
(26574, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Adella's Covert Camp
(25407, 66, 0, 0, 0, 0, 0, 0, 0, 15050), -- Forces of Nature: Wisps
(25350, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Lost Apprentice
(27133, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Eyes in the Sky
(25394, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- More Than Illness
(25448, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Northspring Menace
(25654, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Dark Heart
(27129, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Saving Warpwood
(27131, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Highborne
(27063, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Looming Threat
(25447, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Signs of Change
(13588, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Eye of All Storms
(13940, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Leaving the Dream
(13587, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Waking Nightmare
(13586, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Emerald Dream
(28788, 1, 1, 1, 1, 0, 0, 0, 0, 15050), -- Join the Battle!
(26914, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Corruption
(13578, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Aroom's Farewell
(13581, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Blackwood Pledge
(13580, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Soothing the Elements
(13576, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Mutual Aid
(13585, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Sworn to Protect
(13584, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Calming the Earth
(13579, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Protector of Ameth'Aran
(13575, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Land Is in Their Blood
(13577, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Last Wildkin
(9923, 5, 1, 0, 0, 0, 0, 0, 0, 15050), -- HELP!
(8872, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Lunar Festival
(8868, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Elune's Blessing
(8874, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Lunar Festival
(13881, 1, 6, 0, 0, 50, 800, 0, 0, 15050), -- Consumed
(13892, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Leave No Tracks
(13525, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- What's Happening to the Blackwood Furbolg?
(13902, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Mounting the Offensive
(13558, 1, 1, 25, 0, 0, 0, 0, 0, 15050), -- Call Down the Thunder
(13543, 1, 25, 0, 0, 0, 0, 0, 0, 15050), -- Three Hammers to Break
(13573, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Malfurion's Return
(13542, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Against the Wind
(27265, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Lord Grayson Shadowbreaker
(13605, 1, 5, 25, 0, 0, 0, 0, 0, 15050), -- The Last Refugee
(13547, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Coaxing the Spirits
(29253, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- A Shiny Reward
(24511, 5, 1, 1, 0, 0, 60, 60, 0, 15050), -- Echoes of Tortured Souls
(10629, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Shizz Work
(10238, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- How to Serve Goblins
(10236, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Outland Sucks!
(10876, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Foot of the Citadel
(10875, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Report to Nazgrel
(9406, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Mag'har
(10838, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Demoniac Scryer
(9410, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- A Spirit Guide
(9405, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Warchief's Mandate
(9401, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- A Strange Weapon
(10389, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Agony and the Darkness
(10136, 6, 1, 1, 0, 0, 0, 0, 0, 15050), -- Cruel's Intentions
(29688, 1, 1, 0, 0, 0, 0, 0, 0, 15050), -- Advancing the Campaign
(10274, 1, 1, 1, 0, 0, 0, 0, 0, 15050), -- Securing the Celestial Ridge
(10273, 1, 1, 1, 0, 0, 0, 0, 0, 15050), -- Troublesome Distractions
(10272, 2, 1, 1, 0, 0, 0, 0, 0, 15050), -- A Promising Start
(10281, 1, 1, 1, 0, 0, 0, 0, 0, 15050), -- Formal Introductions
(10271, 1, 1, 1, 0, 0, 0, 0, 0, 15050), -- Getting Down to Business
(10270, 1, 1, 1, 0, 0, 0, 0, 0, 15050), -- A Not-So-Modest Proposal
(10526, 1, 1, 1, 0, 0, 1000, 1000, 0, 15050), -- The Thunderspike
(10525, 5, 1, 1, 0, 0, 0, 0, 0, 15050), -- Vision Guide
(10524, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Thunderlord Clan Artifacts
(29250, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Making Contact
(29238, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Bad Supplies
(29237, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Voodoo Zombies
(29236, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- To Hardwrench Hideaway
(29235, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Defend Grom'gol
(29233, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Warn Grom'gol
(29232, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Bury Me With Me Boots...
(29231, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- How's the Hunter Holding Up?
(29230, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Mauti
(29228, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Follow That Cat
(29227, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Hunter's Revenge
(29226, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Track the Tracker
(29223, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Nesingwary Will Know
(29222, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Spirits Are With Us
(29221, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Serpents and Poison
(29220, 396, 396, 0, 0, 0, 300, 0, 0, 15050), -- To Bambala
(12469, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Return to Sender
(10912, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- The Hound-Master
(10911, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Fire At Will!
(10904, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Harvesting the Fel Ammunition
(10910, 0, 0, 0, 0, 0, 0, 0, 0, 15050), -- Death's Door
(10821, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- You're Fired!
(10820, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Deceive thy Enemy
(10819, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Felsworn Gas Mask
(10812, 1, 0, 0, 0, 0, 0, 0, 0, 15050), -- Mystery Mask
(10810, 1, 0, 0, 0, 0, 0, 0, 0, 15050); -- Damaged Mask

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15050 WHERE `ID`=12043; -- Nozzlerust Defense
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15050 WHERE `ID`=12046; -- Soft Packaging
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=12044; -- Stocking Up
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15050 WHERE `ID`=12049; -- Hard to Swallow
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15050 WHERE `ID`=11129; -- Kyle's Gone Missing!
UPDATE `quest_details` SET `Emote1`=5, `VerifiedBuild`=15050 WHERE `ID`=12047; -- Something That Doesn't Melt
UPDATE `quest_details` SET `Emote1`=6, `VerifiedBuild`=15050 WHERE `ID`=12045; -- Shaved Ice
UPDATE `quest_details` SET `Emote2`=25, `VerifiedBuild`=15050 WHERE `ID`=11051; -- Banish More Demons
UPDATE `quest_details` SET `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15050 WHERE `ID`=10039; -- Speak with Scout Neftis
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=9987; -- Stymying the Arakkoa
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=10033; -- Wanted: Bonelashers Dead!
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=12050; -- Lumber Hack
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=12052; -- Harp on This!
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24602; -- Laid to Rest
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24676; -- Push Them Out
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24678; -- Knee-Deep
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24679; -- Patriarch's Blessing
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24680; -- Keel Harbor
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24681; -- They Have Allies, But So Do We
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24902; -- The Hunt For Sylvanas
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24903; -- Vengeance or Survival
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24904; -- The Battle for Gilneas City
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=24920; -- Slowing the Inevitable
UPDATE `quest_details` SET `VerifiedBuild`=15050 WHERE `ID`=26706; -- Endgame

DELETE FROM `quest_details` WHERE `ID` IN (25985 /*Wings Over Mount Hyjal*/, 12867 /*Baby Stealers*/, 12868 /*Sirana Iceshriek*/, 29535 /*Make Them Bleed*/, 29536 /*Heart of Rage*/, 29537 /*Mind the Gap*/, 12858 /*Pieces to the Puzzle*/, 28542 /*Warchief's Command: Felwood!*/, 24635 /*A Cloudlet of Classy Cologne*/, 24612 /*A Gift for High Overlord Saurfang*/, 25438 /*Ysondre's Farewell*/, 24850 /*Snivel's Sweetheart*/, 24541 /*Pilfering Perfume*/, 24536 /*Something Stinks*/, 25095 /*Thunderdrome: Sarinexx!*/, 25094 /*Thunderdrome: Zumonga!*/, 25103 /*Bootlegger Outpost*/, 24950 /*Captain Dreadbeard*/, 25541 /*Filling Our Pockets*/, 25534 /*Going Off-Task*/, 24927 /*Dead Man's Chest*/, 24928 /*To The Ground!*/, 24949 /*Booty Duty*/, 25556 /*Into Zul'Farrak*/, 28504 /*Warchief's Command: Thousand Needles!*/, 26967 /*Battle for the Scarlet Monastery*/, 24636 /*Bonbon Blitz*/, 10106 /*Hellfire Fortifications*/, 10443 /*Helping the Cenarion Post*/, 9426 /*The Pools of Aggonar*/, 9383 /*An Ambitious Plan*/, 37 /*Find the Lost Guards*/, 239 /*Westbrook Garrison Needs Help!*/, 114 /*The Escape*/, 112 /*Collecting Kelp*/, 87 /*Goldtooth*/, 84 /*Back to Billy*/, 86 /*Pie for Billy*/, 107 /*Note to William*/, 111 /*Speak with Gramma*/, 85 /*Lost Necklace*/, 88 /*Princess Must Die!*/, 106 /*Young Lovers*/, 35 /*Further Concerns*/, 40 /*A Fishy Peril*/, 76 /*The Jasperlode Mine*/, 26150 /*A Visit With Maybell*/, 26396 /*Return to Argus*/, 24657 /*A Friendly Chat...*/, 24849 /*Hot On The Trail*/, 24848 /*Fireworks At The Gilded Rose*/, 24656 /*Pilfering Perfume*/, 333 /*Harlan Needs a Resupply*/, 334 /*Package for Thurman*/, 24655 /*Something Stinks*/, 8871 /*The Lunar Festival*/, 332 /*Wine Shop Advert*/, 28823 /*The Rear is Clear*/, 28813 /*Fear No Evil*/, 28797 /*They Sent Assassins*/, 28789 /*Join the Battle!*/, 26913 /*Charging into Battle*/, 28774 /*Lions for Lambs*/, 28766 /*Beating Them Back!*/, 24452 /*Profitability Scouting*/, 14472 /*In The Face!*/, 14471 /*First Degree Mortar*/, 14470 /*Military Breakthrough*/, 14469 /*Hand-me-downs*/, 14468 /*Another Warm Body*/, 14194 /*Refleshification*/, 14192 /*Prismbreak*/, 14190 /*The Perfect Prism*/, 14165 /*Stone Cold*/, 14161 /*Basilisk Bashin'*/, 14197 /*A Quota to Meet*/, 14162 /*Report to Horzak*/, 14155 /*Arborcide*/, 14146 /*Defend the Gates!*/, 14135 /*Up a Tree*/, 14134 /*The Captain's Logs*/, 14117 /*The Eyes of Ashenvale*/, 14118 /*Venison for the Troops*/, 24638 /*Crushing the Crown*/, 6386 /*Return to Razor Hill*/, 24576 /*A Friendly Chat...*/, 24851 /*Hot On The Trail*/, 28496 /*Warchief's Command: Azshara!*/, 6385 /*Doras the Wind Rider Master*/, 6384 /*Ride to Orgrimmar*/, 6365 /*Meats to Orgrimmar*/, 24787 /*More Than Expected*/, 24784 /*Learnin' tha Word*/, 24786 /*Proving Pit*/, 24785 /*A Rough Start*/, 24783 /*The Basics: Hitting Things*/, 24782 /*The Rise of the Darkspear*/, 28935 /*Crushing the Crown*/, 24615 /*A Gift for the Regent Lord of Quel'Thalas*/, 495 /*The Crown of Will*/, 24613 /*A Gift for the Banshee Queen*/, 24629 /*A Perfect Puff of Perfume*/, 24614 /*A Gift for the High Chieftain*/, 14483 /*Something is in the Air (and it Ain't Love)*/, 29644 /*Into the Heart of the Labyrinth*/, 29641 /*The Soul Devices*/, 29645 /*Ambassador Hellmaw*/, 29640 /*Find Spy To'gun*/, 29643 /*The Codex of Blood*/, 28063 /*Leave No Weapon Behind*/, 28130 /*Not The Friendliest Town*/, 28162 /*Swamp Bait*/, 28122 /*A Huge Problem*/, 28163 /*The Leftovers*/, 28117 /*Clearing the Depths*/, 28120 /*Learning From The Past*/, 28118 /*The Imprisoned Archmage*/, 10553 /*Voren'thal the Seer*/, 10211 /*City of Light*/, 30105 /*The Twilight Prophet*/, 30103 /*To Wyrmrest!*/, 29156 /*The Troll Incursion*/, 29387 /*Guardians of Hyjal: Firelands Invasion!*/, 30095 /*The End Time*/, 28655 /*Wild, Wild, Wildhammer Wedding*/, 28410 /*Something Stolen*/, 28411 /*Something Stewed*/, 28409 /*Something Brewed*/, 28408 /*Something Bold*/, 28413 /*Words and Music By...*/, 28407 /*The Bachelorette*/, 28378 /*Find Fanny*/, 28379 /*Ogre Bashin'*/, 28377 /*Rescue at Glopgut's Hollow*/, 28346 /*The Bachelor*/, 28294 /*The Kirthaven Summit*/, 28282 /*Narkrall, The Drake-Tamer*/, 28281 /*Last Stand at Thundermar*/, 28280 /*Tear Them From the Sky!*/, 28244 /*Eye Spy*/, 28243 /*The Eyes Have It*/, 28242 /*We All Must Sacrifice*/, 28215 /*Potential Energy*/, 28211 /*Tempered in Elemental Flame*/, 28212 /*Hot Stuff*/, 28216 /*Magmalord Falthazar*/, 28241 /*A Vision of Twilight*/, 27753 /*Never Leave a Dinner Behind*/, 27752 /*Fight Like a Wildhammer*/, 27754 /*Dragonmaw Takedown*/, 28369 /*My Sister, Fanny*/, 27651 /*Doing It Like a Dunwald*/, 27650 /*Home Again*/, 27646 /*Finding Beak*/, 27649 /*A Steady Supply*/, 27647 /*Anything But Water*/, 27648 /*Once More Into The Fire*/, 27642 /*Sifting Through The Wreckage*/, 27641 /*While Meeting The Family*/, 27643 /*Donnelly Dunwald*/, 27644 /*Eoin Dunwald*/, 27645 /*Cayden Dunwald*/, 27640 /*Dunwalds Don't Die*/, 28001 /*A Coward's Due*/, 27817 /*Dropping the Hammer*/, 27816 /*Personal Request*/, 27815 /*Somethin' for the Boys*/, 27812 /*The Loyalty of Clan Mullan*/, 27999 /*The Fate of the Doyles*/, 27811 /*The Scent of Battle*/, 27810 /*The Fighting Spirit*/, 28234 /*They Took Me Pants!*/, 27814 /*Anything We Can Get*/, 28233 /*The Lost Brother*/, 27813 /*Death Worthy of a Dragonmaw*/, 27808 /*Stubborn as a Doyle*/, 27807 /*Clan Mullan*/, 27809 /*Firebeard Bellows*/, 27805 /*Small Comforts*/, 27806 /*Honorable Bearing*/, 27803 /*Welcome Relief*/, 27804 /*The Only Homes We Have*/, 27621 /*Firebeard's Patrol*/, 27545 /*The Way is Open*/, 27200 /*Siren's Song*/, 5561 /*Kodo Roundup*/, 27538 /*The Perfect Poultice*/, 27537 /*Any Portal in a Storm*/, 27516 /*Wings Over Highbank*/, 27515 /*Roots'll Do 'Er*/, 27468 /*Siege Tank Rescue*/, 27514 /*Bird Down! Bird Down!*/, 27433 /*Shredderectomy*/, 27341 /*Scouting the Shore*/, 27366 /*Landgrab*/, 27178 /*Naga Reinforcements*/, 27177 /*Salvage Operation*/, 27338 /*Our Boys on the Shore*/, 28599 /*Kurdran's Waitin'*/, 28598 /*Aiming High*/, 28597 /*Burnin' at Both Ends*/, 28596 /*Welcome to Highbank!*/, 28832 /*Twilight Shores*/, 28238 /*Twilight Shores*/, 27106 /*A Villain Unmasked*/, 27092 /*Cataclysm in the Catacombs*/, 27072 /*The Old Barracks*/, 28807 /*Expert Opinion*/, 27060 /*Unholy Cow*/, 27064 /*He's Holding Out on Us*/, 27044 /*Peasant Problems*/, 27038 /*Missing Parts*/, 26997 /*The Usual Suspects*/, 26975 /*Rallying the Fleet*/, 26977 /*Twilight Investigation*/, 26960 /*My Son, the Prince*/, 28716 /*Hero's Call: Twilight Highlands!*/, 28558 /*Hero's Call: Uldum!*/, 9960 /*What's Wrong at Cenarion Thicket?*/, 10034 /*Wanted: Bonelashers Dead!*/, 25693 /*Enhancing the Stone*/, 25696 /*The Sunveil Excursion*/, 9400 /*The Assassin*/, 10390 /*Forge Camp: Mageddon*/, 13409 /*Hellfire Fortifications*/, 9498 /*Falcon Watch*/, 29542 /*Invading the Citadel*/, 10347 /*Return to the Abyssal Shelf*/, 10388 /*Return to Thrallmar*/, 10162 /*Mission: The Abyssal Shelf*/, 29530 /*Demons in the Citadel*/, 29593 /*Hitting Them Where It Hurts*/, 29527 /*War on the Ramparts*/, 10129 /*Mission: Gateways Murketh and Shaadraz*/, 10208 /*Disrupt Their Reinforcements*/, 10449 /*Apothecary Zelana*/, 10124 /*Forward Base: Reaver's Fall*/, 10087 /*Burn It Up... For the Horde!*/, 10123 /*Felspark Ravine*/, 10450 /*Bonechewer Blood*/, 10121 /*Eradicate the Burning Legion*/, 10086 /*I Work... For the Horde!*/, 10291 /*Report to Nazgrel*/, 10289 /*Journey to Thrallmar*/, 10120 /*Arrival in Outland*/, 25695 /*Watching Our Back*/, 25694 /*Protecting Our Rear*/, 9407 /*Through the Dark Portal*/, 25691 /*The Charred Granite of the Dark Portal*/, 25692 /*The Vile Blood of Demons*/, 25689 /*Time is Short*/, 25688 /*The Altar of Storms*/, 25687 /*Not Just Any Body*/, 25686 /*Blood Ritual*/, 25771 /*One Draenei's Junk...*/, 25690 /*A Bloodmage's Gotta Eat Too*/, 25685 /*The First Step*/, 25684 /*Attune the Bloodstone*/, 25683 /*The Dreadmaul Furnace*/, 25682 /*Mission Complete*/, 25681 /*Some People Just Need Killing*/, 25680 /*That's Not Us*/, 25679 /*Into the Mountain*/, 25678 /*Pick Your Fate*/, 25677 /*It's All Mine*/, 27852 /*Orcs and Humans*/, 27853 /*Lumbering Oafs*/, 25675 /*Ogre Combat*/, 25676 /*Heartstrike*/, 25674 /*Futile Pride*/, 9416 /*Report to General Kirika*/, 12866 /*Stemming the Aggressors*/, 12855 /*Sniffing Out the Perpetrator*/, 12865 /*Loyal Companions*/, 12864 /*Missing Scouts*/, 12854 /*On Brann's Trail*/, 12863 /*Offering Thanks*/, 12870 /*Ancient Relics*/, 12833 /*Overstock*/, 12862 /*When All Else Fails*/, 28477 /*Twilight Scheming*/, 24695 /*Ever Watching From Above*/, 24694 /*The Shaper's Terrace*/, 24722 /*The Northern Pylon*/, 24718 /*The Mighty U'cha*/, 24926 /*Serving A-Me 01*/, 24715 /*Repairing A-Me 01*/, 24714 /*Chasing A-Me 01*/, 24717 /*The Apes of Un'Goro*/, 24699 /*Gormashh the Glutinous*/, 24700 /*Hard to Harvest*/, 24737 /*Super Sticky*/, 24701 /*Marshal's Refuse*/, 24693 /*Mossy Pile*/, 9363 /*Warning Fairbreeze Village*/, 9360 /*Amani Invasion*/, 9255 /*Research Notes*/, 8488 /*Unexpected Results*/, 8890 /*Word from the Spire*/, 8894 /*Cleaning up the Grounds*/, 8891 /*Abandoned Investigations*/, 9394 /*Where's Wyllithen?*/, 8889 /*Deactivating the Spire*/, 8888 /*The Magister's Apprentice*/, 8477 /*The Spearcrafter's Hammer*/, 8476 /*Amani Encroachment*/, 29401 /*Blown Away*/, 25515 /*Down in the Deeps*/, 25517 /*Bar Fight!*/, 25504 /*Do Me a Favor?*/, 25488 /*Two If By Boat*/, 25486 /*The Grimtotem are Coming*/, 25481 /*To New Thalanaar*/, 25426 /*War on the Woodpaw*/, 25432 /*It's Not "Ogre" Yet*/, 9396 /*Magic of the Arakkoa*/, 9366 /*In Need of Felblood*/, 9387 /*Source of the Corruption*/, 9374 /*Arelion's Journal*/, 10103 /*Report to Zurai*/, 9340 /*The Great Fissure*/, 9466 /*Wanted: Blacktalon the Savage*/, 9381 /*Trueflight Arrows*/, 9397 /*Birds of a Feather*/, 10442 /*Helping the Cenarion Post*/, 9345 /*Preparing the Salve*/, 10809 /*Wanted: Worg Master Kruush*/, 27727 /*Hero's Call: Deepholm!*/, 9171 /*Culinary Crunch*/, 9155 /*Down the Dead Scar*/, 9193 /*Investigate the Amani Catacombs*/, 9199 /*Troll Juju*/, 9192 /*Trouble at the Underlight Mines*/, 9160 /*Investigate An'daroth*/, 9145 /*Help Ranger Valanna!*/, 9150 /*Salvaging the Past*/, 9140 /*Windrunner Village*/, 9149 /*The Plagued Coast*/, 9156 /*Wanted: Knucklerot and Luzran*/, 9139 /*Goldenmist Village*/, 9148 /*Delivery to Tranquillien*/, 8490 /*Powering our Defenses*/, 9147 /*The Fallen Courier*/, 8479 /*Zul'Marosh*/, 29836 /*Just Checkin'*/, 12501 /*Troll Patrol*/, 12507 /*Strange Mojo*/, 9152 /*Tomber's Supplies*/, 9138 /*Suncrown Village*/, 9758 /*Return to Arcanist Vandril*/, 9327 /*The Forsaken*/, 8487 /*Corrupted Soil*/, 8473 /*A Somber Task*/, 24805 /*Uncommon Scents*/, 10070 /*Steady Shot*/, 9393 /*Hunter Training*/, 24691 /*Peculiar Delicacies*/, 24692 /*The Fledgling Colossus*/, 24721 /*The Eastern Pylon*/, 24855 /*Aberrant Flora*/, 24690 /*Blazerunner*/, 24687 /*Bouquets of Death*/, 13917 /*Gorishi Grub*/, 24865 /*Is This Stuff Still Good?*/, 24723 /*The Western Pylon*/, 24709 /*A Tale of Two Shovels*/, 24708 /*The Fossil-Finder 3000*/, 24707 /*The Ballad of Maximillian*/, 24706 /*The Spirits of Golakka Hot Springs*/, 24730 /*Roll the Bones*/, 24704 /*The Evil Dragons of Un'Goro Crater*/, 24705 /*Damsels Were Made to be Saved*/, 24703 /*An Important Lesson*/, 24736 /*Shizzle's Flyer*/, 24866 /*An Abandoned Research Camp*/, 24697 /*How to Make Meat Fresh Again*/, 28859 /*The Dunes of Silithus*/, 24720 /*Crystals of Power*/, 24740 /*Volcanic Activity*/, 24742 /*Finding the Source*/, 24689 /*Flowing to the North*/, 24733 /*The Bait for Lar'korwi*/, 13906 /*They Grow Up So Fast*/, 24686 /*Carried on the Waves*/, 24732 /*The Scent of Lar'korwi*/, 13887 /*Venomhide Eggs*/, 13850 /*Toxic Tolerance*/, 24731 /*The Fare of Lar'korwi*/, 24719 /*Claws of White*/, 12792 /*First Things First*/, 12643 /*Silver Lining*/, 12638 /*Close Call*/, 12633 /*Darkness Calling*/, 25250 /*Sealing the Dream*/, 25237 /*Tears of Stone*/, 25241 /*The Land, Corrupted*/, 25230 /*More Than Illness*/, 25339 /*Vengeance on the Northspring*/, 25340 /*Dark Heart*/, 25210 /*Signs of Change*/, 12174 /*High Commander Halford Wyrmbane*/, 12171 /*Of Traitors and Treason*/, 12172 /*Attunement to Dalaran*/, 11693 /*Oh Great... Plagued Magnataur!*/, 11798 /*The Gearmaster*/, 11725 /*Finding Pilot Tailspin*/, 11788 /*Lefty Loosey, Righty Tighty*/, 11692 /*Check in With Bixie*/, 11645 /*Dirty, Stinkin' Snobolds!*/, 11710 /*What's the Matter with the Transmatter?*/, 11704 /*King Mrgl-Mrgl*/, 11712 /*Re-Cursive*/, 27593 /*Rebirth of the K.E.F.*/, 27591 /*The Dark Iron Pact*/, 27589 /*The Grim Guzzler*/, 27585 /*The 109th Division*/, 27582 /*Infiltrating Shadowforge City*/, 27581 /*Twilight?! No!*/, 27603 /*The Sealed Gate*/, 27579 /*Into the Prison*/, 24905 /*Returning a Favor*/, 27230 /*Weapons for War*/, 27227 /*Lord Aurius Rivendare*/, 27228 /*Man Against Abomination*/, 27359 /*Argent Reinforcements*/, 11708 /*The Mechagnomes*/, 28545 /*Warchief's Command: Winterspring!*/, 28526 /*Warchief's Command: Un'Goro Crater!*/, 26187 /*The Downfall of Marl Wormthorn*/, 26962 /*Stripping Their Offense*/, 26186 /*Demoniac Vessel*/, 26185 /*Advice from the Cenarion Circle*/, 25772 /*Kum'isha's Endeavors*/, 26184 /*Wormthorn's Dream*/, 26162 /*The Altar of Storms*/, 26161 /*Not Just Any Body*/, 26175 /*Surwich*/, 26166 /*Enhancing the Stone*/, 26174 /*Watching Our Back*/, 26164 /*The Charred Granite of the Dark Portal*/, 26165 /*The Vile Blood of Demons*/, 26167 /*The Amulet of Allistarj*/, 26168 /*The Amulet of Sevine*/, 26169 /*The Amulet of Grol*/, 26160 /*Blood Ritual*/, 27567 /*Twilight?! No!*/, 26159 /*The First Step*/, 26172 /*A Bloodmage's Gotta Eat Too*/, 26158 /*Attune the Bloodstone*/, 26157 /*Kasim Sharim*/, 25716 /*Cultists at our Doorstep*/, 25714 /*Watcher Mahar Ba*/, 25708 /*Our Fallen Friends*/, 25709 /*Curtail the Darktail*/, 25713 /*Remove Their Arms*/, 25712 /*Nethergarde Reigns*/, 25711 /*Eliminate the Okril'lon*/, 25710 /*Minor Distractions*/, 25715 /*A Closer Look*/, 28398 /*The Pyromancer's Grimoire*/, 28673 /*Hero's Call: Blasted Lands!*/, 28180 /*The Sand, the Cider, and the Orb*/, 26642 /*Preserving the Barrens*/, 28510 /*Warchief's Command: Feralas!*/, 28554 /*Warchief's Command: Dustwallow Marsh!*/, 27124 /*Unfinished Gordok Business*/, 27119 /*The Gordok Ogre Suit*/, 27125 /*King of the Gordok*/, 24663 /*Crushing the Crown*/, 24597 /*A Gift for the King of Stormwind*/, 25672 /*Carcass Collection*/, 25661 /*With a Little Help...*/, 25660 /*Haunted*/, 25627 /*Two-Tusk Takedown*/, 25609 /*Sunken Treasure*/, 11881 /*Load'er Up!*/, 11674 /*Sage Highmesa is Missing*/, 11890 /*What Are They Up To?*/, 11684 /*Scouting the Sinkholes*/, 11709 /*Nork Bloodfrenzy's Charge*/, 11705 /*Foolish Endeavors*/, 11703 /*Get to Getry*/, 11690 /*Bring 'Em Back Alive*/, 11662 /*Seek Out Karuk!*/, 11652 /*The Plains of Nasam*/, 11651 /*Tanks a lot...*/, 11656 /*Burn in Effigy*/, 11661 /*Orabus the Helmsman*/, 11664 /*Escaping the Mist*/, 11643 /*Mobu's Pneumatic Tank Transjigamarig*/, 11644 /*Super Strong Metal Plates!*/, 11642 /*Tank Ain't Gonna Fix Itself*/, 11655 /*Into the Mist*/, 11660 /*Horn of the Ancient Mariner*/, 29658 /*The Calculator*/, 29659 /*Lost Treasure*/, 29657 /*With Great Power, Comes Great Responsibility*/, 11676 /*Merciful Freedom*/, 11686 /*The Warsong Farms*/, 11688 /*Damned Filthy Swine*/, 11636 /*Magic Carpet Ride*/, 11634 /*Wind Master To'bor*/, 11574 /*Too Close For Comfort*/, 12486 /*To Bor'gorok Outpost, Quickly!*/, 13095 /*Have They No Shame?*/, 29681 /*Maximum Security Breakout*/, 29675 /*Hey There Dalliah*/, 29674 /*Unbound Darkness*/, 28374 /*Weeding the Lawn*/, 28361 /*Squirrely Clean*/, 28360 /*Running Their Course*/, 28341 /*Collecting Corruption*/, 28342 /*Fel To Pieces*/, 28358 /*Hunting the Damned*/, 28359 /*The Core of Kroshius*/, 28305 /*The Fate of Bloodvenom Post*/, 28288 /*Open Their Eyes*/, 11618 /*Reinforcements Incoming...*/, 11616 /*Message to Hellscream*/, 11615 /*Nerub'ar Secrets*/, 29609 /*Friends in Dalaran*/, 11614 /*Untold Truths*/, 11602 /*Cutting Off the Source*/, 11608 /*Bury Those Cockroaches!*/, 11888 /*Ride to Taunka'le Village*/, 11611 /*Taken by the Scourge*/, 11606 /*Patience is a Virtue that We Don't Need*/, 11598 /*Taking Back Mightstone Quarry*/, 11596 /*The Defense of Warsong Hold*/, 11585 /*Hellscream's Vigil*/, 13206 /*Disarmament*/, 30112 /*A Score to Settle*/, 11262 /*Ingvar Must Die!*/, 10458 /*Enraged Spirits of Fire and Earth*/, 13614 /*Algalon*/, 25366 /*The Battle Plans*/, 25375 /*Taming The Tamers*/, 25374 /*Sasquatch Sighting*/, 25378 /*Ysondre's Call*/, 25365 /*Woodpaw Investigation*/, 25364 /*Alpha Strike*/, 29599 /*Escape from Durnholde*/, 24500 /*Wrath of the Lich King*/, 24711 /*Frostmourne*/, 24710 /*Deliverance from the Pit*/, 24498 /*The Path to the Citadel*/, 24683 /*The Pit of Saron*/, 24499 /*Echoes of Tortured Souls*/, 25591 /*Thunderdrome: Grudge Match!*/, 25107 /*The Grand Tablet*/, 25070 /*What Lies Within*/, 25069 /*The Secrets of Uldum*/, 25068 /*The Crumbling Past*/, 25017 /*Ancient Obstacles*/, 25020 /*Fragments of Language*/, 25019 /*Laying Claim*/, 25018 /*Andoren Will Know*/, 25014 /*Sandscraper's Treasure*/, 25001 /*Sandscraper*/, 24963 /*Maul 'Em With Kindness*/, 24957 /*Get The Centipaarty Started*/, 24955 /*Un-Chartered*/, 25391 /*Weapons of Spirit*/, 25362 /*A Grim Discovery*/, 25346 /*Mountain Giant Muisek*/, 25361 /*A New Cloak's Sheen*/, 25345 /*Faerie Dragon Muisek*/, 25338 /*Treant Muisek*/, 25349 /*Twisted Sisters*/, 25373 /*The Hilltop Threat*/, 25643 /*The Darkmist Ruins*/, 27130 /*Saving Warpwood*/, 27132 /*The Highborne*/, 25363 /*War on the Woodpaw*/, 25387 /*To Camp Mojache*/, 25329 /*Might of the Stonemaul*/, 25344 /*Ogre Abduction*/, 25342 /*Talk to Swar'jan*/, 25252 /*Rulers of Dire Maul*/, 25641 /*The Flow of Muisek*/, 25337 /*Hippogryph Muisek*/, 25452 /*The Mark of Quality*/, 25336 /*Testing the Vessel*/, 25209 /*The Gordunni Threat*/, 25341 /*The Gordunni Orb*/, 25386 /*To Stonemaul Hold*/, 24947 /*Momentum*/, 24910 /*Rocket Rescue*/, 27128 /*King of the Gordok*/, 24907 /*Puddle Stomping*/, 24906 /*Seaside Salvage*/, 26417 /*Northern Stranglethorn: The Fallen Empire*/, 13842 /*Dread Head Redemption*/, 26416 /*Well, Come to the Jungle*/, 25 /*Simmer Down Now*/, 13967 /*Thinning the... Herd?*/, 25945 /*We're Here to Do One Thing, Maybe Two...*/, 13870 /*As Good as it Gets*/, 13865 /*Wet Work*/, 13815 /*Making Stumps*/, 6441 /*Satyr Horns*/, 13806 /*Demon Duty*/, 13841 /*All Apologies*/, 13798 /*Rain of Destruction*/, 13797 /*Dirty Deeds*/, 26449 /*Never Again!*/, 13808 /*Mission Improbable*/, 13848 /*Bad News Bear-er*/, 13751 /*Tell No One!*/, 26447 /*Diabolical Plans*/, 6544 /*Torek's Assault*/, 13801 /*Dead Elves Walking*/, 13730 /*Playing With Felfire*/, 13805 /*Pierce Their Heart!*/, 26448 /*Destroy the Legion*/, 6503 /*Ashenvale Outrunners*/, 13803 /*Blood of the Weak*/, 13712 /*To the Rescue!*/, 13653 /*Crisis at Splintertree*/, 13651 /*Needs a Little Lubrication*/, 2 /*Sharptalon's Claw*/, 13640 /*Management Material*/, 13628 /*Got Wood?*/, 13621 /*Gorat's Vengeance*/, 13620 /*To Dinah, at Once!*/, 13619 /*Final Report*/, 13618 /*Find Gorat!*/, 13612 /*Mor'shan Defense*/, 13615 /*Empty Quivers*/, 13613 /*Rescue the Fallen*/, 28493 /*Warchief's Command: Ashenvale!*/, 24645 /*Crushing the Crown*/, 14422 /*Raptor Raptor Rocket*/, 14408 /*Nine's Plan*/, 14262 /*To Gut a Fish*/, 14267 /*Investigating the Sea Shrine*/, 14258 /*Mortar the Point*/, 14216 /*Mystery of the Sarcen Stone*/, 14424 /*Need More Science*/, 14423 /*Dozercism*/, 14209 /*Gunk in the Trunk*/, 14215 /*Memories of the Dead*/, 14201 /*A Thousand Stories in the Sand*/, 14202 /*Survey the Lakeshore*/, 24453 /*Private Chat*/, 28582 /*Hero's Call: Searing Gorge!*/, 8873 /*The Lunar Festival*/, 28048 /*That Smart One's Gotta Go*/, 28047 /*Freezing the Pipes*/, 28051 /*We All Scream for Ice Cream... and then Die!*/, 28045 /*The Greatest Flavor in the World!*/, 27677 /*Archaedas, The Ancient Stone Watcher*/, 27672 /*The Chamber of Khaz'mul*/, 27676 /*Behind Closed Doors*/, 27673 /*It's What's Inside That Counts*/, 25304 /*The Battle of Sardor*/, 26985 /*Pitting Madness Against Madness*/, 25463 /*Report to Silvia*/, 25399 /*Hatecrest Forces*/, 25458 /*General Skessesh*/, 25449 /*The Mark of Quality*/, 26402 /*General Shandris Feathermoon*/, 25398 /*Sealing the Dream*/, 25396 /*Tears of Stone*/, 25397 /*The Land, Corrupted*/, 26974 /*The False Champion*/, 28934 /*Crushing the Crown*/, 24804 /*Uncommon Scents*/, 11571 /*Learning to Communicate*/, 11627 /*Boiling Point*/, 11702 /*King Mrgl-Mrgl*/, 11591 /*Report to Steeljaw's Caravan*/, 11624 /*The Sky Will Know*/, 10984 /*Speak with the Ogre*/, 29685 /*Hard to Kill*/, 11490 /*The Scryer's Scryer*/, 29686 /*A Radical Notion*/, 29687 /*Twisted Associations*/, 29684 /*Severed Communications*/, 10297 /*The Opening of the Dark Portal*/, 10279 /*To The Master's Lair*/, 28509 /*Warchief's Command: Tanaris!*/, 11575 /*Nick of Time*/, 9933 /*Message to Telaar*/, 9955 /*Cho'war the Pillager*/, 9931 /*Returning the Favor*/, 9932 /*Body of Evidence*/, 9927 /*Ruthless Cunning*/, 9928 /*Armaments for Deception*/, 9954 /*Corki's Ransom*/, 10108 /*Diplomatic Measures*/, 9999 /*Buying Time*/, 9991 /*Survey the Land*/, 9956 /*The Ravaged Caravan*/, 9982 /*He Called Himself Altruis...*/, 9922 /*The Twin Clefts of Nagrand*/, 9924 /*Corki's Gone Missing Again!*/, 24665 /*Crushing the Crown*/, 27436 /*The Shadow-Walker's Task*/, 29571 /*Defending the Wilds*/, 9869 /*The Throne of the Elements*/, 9878 /*Solving the Problem*/, 9874 /*Stopping the Spread*/, 9921 /*The Ruins of Burning Blade*/, 9920 /*Mo'mor the Breaker*/, 9918 /*Not On My Watch!*/, 10115 /*Daggerfen Deviance*/, 26386 /*Surkhan*/, 26362 /*Be Raptor*/, 26405 /*Zul'Mamwe Mambo*/, 26304 /*Nighttime in the Jungle*/, 26360 /*Mind Control*/, 26359 /*See Raptor*/, 26351 /*Mind Vision*/, 26350 /*Priestess Hu'rala*/, 208 /*Big Game Hunter*/, 197 /*Raptor Mastery*/, 196 /*Raptor Prowess*/, 26345 /*Excelsior*/, 192 /*Panther Prowess*/, 195 /*Raptor Stalking*/, 26344 /*Some Assembly Required*/, 26352 /*Cozzle's Plan*/, 26403 /*Venture Company Mining*/, 26305 /*Saving Yenniku*/, 26400 /*The Universal Key*/, 26303 /*The Mind's Eye*/, 26404 /*Above My Pay Grade*/, 26399 /*The Mosh'Ogg Bounty*/, 26334 /*Bloodlord Mandokir*/, 26302 /*Chasing Yenniku's Fate*/, 188 /*Tiger Mastery*/, 187 /*Tiger Prowess*/, 191 /*Panther Stalking*/, 186 /*Tiger Stalking*/, 26269 /*The Green Hills of Stranglethorn*/, 194 /*Raptor Hunting*/, 583 /*Welcome to the Jungle*/, 26343 /*Supply and Demand*/, 28549 /*Warchief's Command: Southern Barrens!*/, 28548 /*Warchief's Command: Desolace!*/, 26301 /*Speaking with Nezzliok*/, 26332 /*Skullsplitter Mojo*/, 26338 /*Population Con-Troll*/, 26340 /*The Hunt*/, 26300 /*Nezzliok Will Know*/, 26330 /*Who's a Big Troll?*/, 26407 /*Mosh'Ogg Handiwork*/, 24647 /*Crushing the Crown*/, 28532 /*Warchief's Command: Stonetalon Mountains!*/, 9457 /*An Unusual Patron*/, 26325 /*A Nose for This Sort of Thing*/, 26299 /*Headhunting*/, 26323 /*Favored Skull*/, 26298 /*Hunt for Yenniku*/, 26281 /*The Defense of Grom'gol: Trollish Thievery*/, 26321 /*I Think She's Hungry*/, 26279 /*The Defense of Grom'gol: Ogre Oppression*/, 26280 /*The Defense of Grom'gol: Murloc Menace*/, 26317 /*A Lashtail Hatchling*/, 26278 /*The Defense of Grom'gol: Raptor Risk*/, 28031 /*Special Delivery for Brivelthwerp*/, 25744 /*Negotiations*/, 25588 /*A Little Payback*/, 25590 /*Where's Wizzle?*/, 25585 /*Quiet the Cannons*/, 25542 /*Circle the Wagons... er, Boats*/, 25532 /*Pirate Accuracy Increasing*/, 25524 /*In the Outhouse*/, 1456 /*The Karnitol Shipwreck*/, 26903 /*Willix the Importer*/, 26905 /*Agamaggan's Charge*/, 26901 /*Going, Going, Guano!*/, 26907 /*Take Them Down!*/, 26906 /*Agamaggan*/, 28550 /*Hero's Call: Southern Barrens!*/, 14257 /*Slitherblade Slaughter*/, 1455 /*The Karnitol Shipwreck*/, 14256 /*The Emerging Threat*/, 26993 /*Compendium of the Fallen*/, 26973 /*The Only True Path*/, 26942 /*The G-Team*/, 26941 /*The G-Team*/, 26939 /*The G-Team*/, 26972 /*The Dark Side of the Light*/, 29309 /*The Stuff of Legends*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25985, 1, 273, 0, 0, 0, 0, 0, 0, 15211), -- Wings Over Mount Hyjal
(12867, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Baby Stealers
(12868, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sirana Iceshriek
(29535, 396, 396, 0, 0, 0, 1000, 0, 0, 15211), -- Make Them Bleed
(29536, 396, 396, 0, 0, 0, 1000, 0, 0, 15211), -- Heart of Rage
(29537, 396, 396, 0, 0, 0, 1000, 0, 0, 15211), -- Mind the Gap
(12858, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Pieces to the Puzzle
(28542, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Felwood!
(24635, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Cloudlet of Classy Cologne
(24612, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Gift for High Overlord Saurfang
(25438, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ysondre's Farewell
(24850, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Snivel's Sweetheart
(24541, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Pilfering Perfume
(24536, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Something Stinks
(25095, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Thunderdrome: Sarinexx!
(25094, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Thunderdrome: Zumonga!
(25103, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Bootlegger Outpost
(24950, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Captain Dreadbeard
(25541, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Filling Our Pockets
(25534, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Going Off-Task
(24927, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Dead Man's Chest
(24928, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- To The Ground!
(24949, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Booty Duty
(25556, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Into Zul'Farrak
(28504, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Thousand Needles!
(26967, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Battle for the Scarlet Monastery
(24636, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Bonbon Blitz
(10106, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hellfire Fortifications
(10443, 1, 1, 6, 0, 0, 1000, 1000, 0, 15211), -- Helping the Cenarion Post
(9426, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Pools of Aggonar
(9383, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- An Ambitious Plan
(37, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Find the Lost Guards
(239, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Westbrook Garrison Needs Help!
(114, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Escape
(112, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Collecting Kelp
(87, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Goldtooth
(84, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Back to Billy
(86, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Pie for Billy
(107, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Note to William
(111, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Speak with Gramma
(85, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Lost Necklace
(88, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Princess Must Die!
(106, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Young Lovers
(35, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Further Concerns
(40, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Fishy Peril
(76, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Jasperlode Mine
(26150, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- A Visit With Maybell
(26396, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Return to Argus
(24657, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- A Friendly Chat...
(24849, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hot On The Trail
(24848, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Fireworks At The Gilded Rose
(24656, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Pilfering Perfume
(333, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Harlan Needs a Resupply
(334, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Package for Thurman
(24655, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Something Stinks
(8871, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Lunar Festival
(332, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Wine Shop Advert
(28823, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Rear is Clear
(28813, 6, 5, 5, 20, 0, 0, 0, 0, 15211), -- Fear No Evil
(28797, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- They Sent Assassins
(28789, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Join the Battle!
(26913, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Charging into Battle
(28774, 274, 1, 25, 5, 0, 0, 0, 0, 15211), -- Lions for Lambs
(28766, 6, 2, 1, 5, 0, 0, 0, 0, 15211), -- Beating Them Back!
(24452, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Profitability Scouting
(14472, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- In The Face!
(14471, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- First Degree Mortar
(14470, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Military Breakthrough
(14469, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hand-me-downs
(14468, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Another Warm Body
(14194, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Refleshification
(14192, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Prismbreak
(14190, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Perfect Prism
(14165, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Stone Cold
(14161, 1, 6, 0, 0, 0, 0, 0, 0, 15211), -- Basilisk Bashin'
(14197, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- A Quota to Meet
(14162, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Report to Horzak
(14155, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Arborcide
(14146, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Defend the Gates!
(14135, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Up a Tree
(14134, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Captain's Logs
(14117, 274, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Eyes of Ashenvale
(14118, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Venison for the Troops
(24638, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(6386, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Return to Razor Hill
(24576, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- A Friendly Chat...
(24851, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hot On The Trail
(28496, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Azshara!
(6385, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Doras the Wind Rider Master
(6384, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ride to Orgrimmar
(6365, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Meats to Orgrimmar
(24787, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- More Than Expected
(24784, 1, 1, 0, 0, 0, 60, 0, 0, 15211), -- Learnin' tha Word
(24786, 1, 1, 0, 0, 0, 60, 0, 0, 15211), -- Proving Pit
(24785, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Rough Start
(24783, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Basics: Hitting Things
(24782, 1, 1, 1, 0, 0, 60, 60, 0, 15211), -- The Rise of the Darkspear
(28935, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(24615, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Gift for the Regent Lord of Quel'Thalas
(495, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Crown of Will
(24613, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Gift for the Banshee Queen
(24629, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Perfect Puff of Perfume
(24614, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Gift for the High Chieftain
(14483, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Something is in the Air (and it Ain't Love)
(29644, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Into the Heart of the Labyrinth
(29641, 1, 1, 0, 0, 0, 1000, 1000, 0, 15211), -- The Soul Devices
(29645, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ambassador Hellmaw
(29640, 1, 1, 0, 18, 0, 0, 0, 0, 15211), -- Find Spy To'gun
(29643, 0, 0, 0, 0, 0, 1000, 1000, 0, 15211), -- The Codex of Blood
(28063, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Leave No Weapon Behind
(28130, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Not The Friendliest Town
(28162, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Swamp Bait
(28122, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Huge Problem
(28163, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Leftovers
(28117, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Clearing the Depths
(28120, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Learning From The Past
(28118, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Imprisoned Archmage
(10553, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Voren'thal the Seer
(10211, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- City of Light
(30105, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Twilight Prophet
(30103, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- To Wyrmrest!
(29156, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Troll Incursion
(29387, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Guardians of Hyjal: Firelands Invasion!
(30095, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The End Time
(28655, 1, 274, 6, 0, 0, 0, 0, 0, 15211), -- Wild, Wild, Wildhammer Wedding
(28410, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Something Stolen
(28411, 274, 5, 0, 0, 0, 0, 0, 0, 15211), -- Something Stewed
(28409, 5, 25, 0, 0, 0, 0, 0, 0, 15211), -- Something Brewed
(28408, 1, 274, 0, 0, 0, 0, 0, 0, 15211), -- Something Bold
(28413, 1, 6, 0, 0, 0, 0, 0, 0, 15211), -- Words and Music By...
(28407, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Bachelorette
(28378, 6, 5, 0, 0, 0, 0, 0, 0, 15211), -- Find Fanny
(28379, 274, 5, 0, 0, 0, 0, 0, 0, 15211), -- Ogre Bashin'
(28377, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Rescue at Glopgut's Hollow
(28346, 274, 6, 0, 0, 0, 0, 0, 0, 15211), -- The Bachelor
(28294, 6, 1, 5, 0, 0, 0, 0, 0, 15211), -- The Kirthaven Summit
(28282, 1, 274, 15, 0, 0, 0, 0, 0, 15211), -- Narkrall, The Drake-Tamer
(28281, 5, 274, 0, 0, 0, 0, 0, 0, 15211), -- Last Stand at Thundermar
(28280, 5, 25, 15, 0, 0, 0, 0, 0, 15211), -- Tear Them From the Sky!
(28244, 5, 6, 25, 0, 0, 0, 0, 0, 15211), -- Eye Spy
(28243, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Eyes Have It
(28242, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- We All Must Sacrifice
(28215, 6, 5, 0, 0, 0, 0, 0, 0, 15211), -- Potential Energy
(28211, 1, 273, 0, 0, 0, 0, 0, 0, 15211), -- Tempered in Elemental Flame
(28212, 1, 274, 0, 0, 0, 0, 0, 0, 15211), -- Hot Stuff
(28216, 1, 274, 5, 0, 0, 0, 0, 0, 15211), -- Magmalord Falthazar
(28241, 6, 5, 0, 0, 0, 0, 0, 0, 15211), -- A Vision of Twilight
(27753, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Never Leave a Dinner Behind
(27752, 1, 274, 5, 0, 0, 0, 0, 0, 15211), -- Fight Like a Wildhammer
(27754, 5, 1, 274, 0, 0, 0, 0, 0, 15211), -- Dragonmaw Takedown
(28369, 1, 273, 0, 0, 0, 0, 0, 0, 15211), -- My Sister, Fanny
(27651, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Doing It Like a Dunwald
(27650, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Home Again
(27646, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Finding Beak
(27649, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Steady Supply
(27647, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Anything But Water
(27648, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Once More Into The Fire
(27642, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sifting Through The Wreckage
(27641, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- While Meeting The Family
(27643, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Donnelly Dunwald
(27644, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Eoin Dunwald
(27645, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Cayden Dunwald
(27640, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Dunwalds Don't Die
(28001, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Coward's Due
(27817, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Dropping the Hammer
(27816, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Personal Request
(27815, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Somethin' for the Boys
(27812, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Loyalty of Clan Mullan
(27999, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Fate of the Doyles
(27811, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Scent of Battle
(27810, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Fighting Spirit
(28234, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- They Took Me Pants!
(27814, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Anything We Can Get
(28233, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- The Lost Brother
(27813, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Death Worthy of a Dragonmaw
(27808, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Stubborn as a Doyle
(27807, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Clan Mullan
(27809, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Firebeard Bellows
(27805, 6, 0, 0, 0, 0, 0, 0, 0, 15211), -- Small Comforts
(27806, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Honorable Bearing
(27803, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- Welcome Relief
(27804, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Only Homes We Have
(27621, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Firebeard's Patrol
(27545, 1, 273, 0, 0, 0, 0, 0, 0, 15211), -- The Way is Open
(27200, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Siren's Song
(5561, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Kodo Roundup
(27538, 1, 274, 0, 0, 0, 0, 0, 0, 15211), -- The Perfect Poultice
(27537, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Any Portal in a Storm
(27516, 1, 273, 4, 0, 0, 0, 0, 0, 15211), -- Wings Over Highbank
(27515, 5, 274, 0, 0, 0, 0, 0, 0, 15211), -- Roots'll Do 'Er
(27468, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Siege Tank Rescue
(27514, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Bird Down! Bird Down!
(27433, 1, 274, 0, 0, 0, 0, 0, 0, 15211), -- Shredderectomy
(27341, 1, 274, 0, 0, 0, 0, 0, 0, 15211), -- Scouting the Shore
(27366, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Landgrab
(27178, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Naga Reinforcements
(27177, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- Salvage Operation
(27338, 274, 5, 1, 0, 0, 0, 0, 0, 15211), -- Our Boys on the Shore
(28599, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Kurdran's Waitin'
(28598, 1, 6, 4, 0, 0, 0, 0, 0, 15211), -- Aiming High
(28597, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Burnin' at Both Ends
(28596, 66, 0, 0, 0, 0, 0, 0, 0, 15211), -- Welcome to Highbank!
(28832, 1, 274, 11, 0, 0, 0, 0, 0, 15211), -- Twilight Shores
(28238, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Twilight Shores
(27106, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Villain Unmasked
(27092, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Cataclysm in the Catacombs
(27072, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Old Barracks
(28807, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Expert Opinion
(27060, 5, 274, 0, 0, 0, 0, 0, 0, 15211), -- Unholy Cow
(27064, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- He's Holding Out on Us
(27044, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- Peasant Problems
(27038, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Missing Parts
(26997, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- The Usual Suspects
(26975, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Rallying the Fleet
(26977, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- Twilight Investigation
(26960, 1, 6, 0, 0, 0, 0, 0, 0, 15211), -- My Son, the Prince
(28716, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Twilight Highlands!
(28558, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Uldum!
(9960, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- What's Wrong at Cenarion Thicket?
(10034, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Wanted: Bonelashers Dead!
(25693, 432, 1, 0, 0, 0, 0, 0, 0, 15211), -- Enhancing the Stone
(25696, 396, 432, 396, 0, 0, 0, 0, 0, 15211), -- The Sunveil Excursion
(9400, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Assassin
(10390, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Forge Camp: Mageddon
(13409, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hellfire Fortifications
(9498, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Falcon Watch
(29542, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Invading the Citadel
(10347, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Return to the Abyssal Shelf
(10388, 66, 0, 0, 0, 5000, 0, 0, 0, 15211), -- Return to Thrallmar
(10162, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Mission: The Abyssal Shelf
(29530, 396, 0, 0, 0, 0, 1000, 0, 0, 15211), -- Demons in the Citadel
(29593, 396, 6, 0, 0, 0, 0, 0, 0, 15211), -- Hitting Them Where It Hurts
(29527, 396, 0, 0, 0, 0, 1000, 0, 0, 15211), -- War on the Ramparts
(10129, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- Mission: Gateways Murketh and Shaadraz
(10208, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Disrupt Their Reinforcements
(10449, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Apothecary Zelana
(10124, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- Forward Base: Reaver's Fall
(10087, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Burn It Up... For the Horde!
(10123, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Felspark Ravine
(10450, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Bonechewer Blood
(10121, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Eradicate the Burning Legion
(10086, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- I Work... For the Horde!
(10291, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Report to Nazgrel
(10289, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- Journey to Thrallmar
(10120, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- Arrival in Outland
(25695, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Watching Our Back
(25694, 1, 1, 66, 0, 0, 0, 0, 0, 15211), -- Protecting Our Rear
(9407, 1, 1, 1, 25, 0, 0, 0, 0, 15211), -- Through the Dark Portal
(25691, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Charred Granite of the Dark Portal
(25692, 1, 1, 0, 0, 0, 0, 0, 0, 15211); -- The Vile Blood of Demons

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25689, 396, 397, 396, 0, 0, 0, 0, 0, 15211), -- Time is Short
(25688, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Altar of Storms
(25687, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Not Just Any Body
(25686, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Blood Ritual
(25771, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- One Draenei's Junk...
(25690, 1, 1, 6, 0, 0, 0, 0, 0, 15211), -- A Bloodmage's Gotta Eat Too
(25685, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The First Step
(25684, 1, 1, 5, 0, 0, 0, 0, 0, 15211), -- Attune the Bloodstone
(25683, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Dreadmaul Furnace
(25682, 6, 0, 0, 0, 0, 0, 0, 0, 15211), -- Mission Complete
(25681, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Some People Just Need Killing
(25680, 1, 1, 6, 1, 0, 0, 0, 0, 15211), -- That's Not Us
(25679, 1, 2, 0, 0, 0, 0, 0, 0, 15211), -- Into the Mountain
(25678, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Pick Your Fate
(25677, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- It's All Mine
(27852, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Orcs and Humans
(27853, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Lumbering Oafs
(25675, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Ogre Combat
(25676, 274, 1, 1, 0, 0, 0, 0, 0, 15211), -- Heartstrike
(25674, 1, 36, 1, 0, 0, 0, 0, 0, 15211), -- Futile Pride
(9416, 25, 1, 0, 0, 0, 0, 0, 0, 15211), -- Report to General Kirika
(12866, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Stemming the Aggressors
(12855, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Sniffing Out the Perpetrator
(12865, 5, 0, 0, 0, 0, 0, 0, 0, 15211), -- Loyal Companions
(12864, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Missing Scouts
(12854, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- On Brann's Trail
(12863, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Offering Thanks
(12870, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ancient Relics
(12833, 3, 6, 0, 0, 0, 120, 0, 0, 15211), -- Overstock
(12862, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- When All Else Fails
(28477, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Twilight Scheming
(24695, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ever Watching From Above
(24694, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Shaper's Terrace
(24722, 1, 1, 66, 0, 0, 0, 0, 0, 15211), -- The Northern Pylon
(24718, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mighty U'cha
(24926, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Serving A-Me 01
(24715, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Repairing A-Me 01
(24714, 18, 1, 1, 0, 0, 0, 0, 0, 15211), -- Chasing A-Me 01
(24717, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Apes of Un'Goro
(24699, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Gormashh the Glutinous
(24700, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hard to Harvest
(24737, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Super Sticky
(24701, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Marshal's Refuse
(24693, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Mossy Pile
(9363, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Warning Fairbreeze Village
(9360, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Amani Invasion
(9255, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Research Notes
(8488, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Unexpected Results
(8890, 1, 1, 0, 0, 0, 500, 0, 0, 15211), -- Word from the Spire
(8894, 5, 1, 0, 0, 0, 500, 0, 0, 15211), -- Cleaning up the Grounds
(8891, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Abandoned Investigations
(9394, 1, 6, 0, 0, 0, 1000, 0, 0, 15211), -- Where's Wyllithen?
(8889, 1, 1, 6, 0, 0, 500, 500, 0, 15211), -- Deactivating the Spire
(8888, 1, 1, 1, 0, 0, 500, 500, 0, 15211), -- The Magister's Apprentice
(8477, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Spearcrafter's Hammer
(8476, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Amani Encroachment
(29401, 3, 396, 25, 0, 0, 1000, 1000, 0, 15211), -- Blown Away
(25515, 1, 25, 273, 0, 1000, 0, 0, 0, 15211), -- Down in the Deeps
(25517, 15, 0, 0, 0, 0, 0, 0, 0, 15211), -- Bar Fight!
(25504, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Do Me a Favor?
(25488, 6, 0, 0, 0, 0, 0, 0, 0, 15211), -- Two If By Boat
(25486, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Grimtotem are Coming
(25481, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- To New Thalanaar
(25426, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- War on the Woodpaw
(25432, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- It's Not "Ogre" Yet
(9396, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Magic of the Arakkoa
(9366, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- In Need of Felblood
(9387, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Source of the Corruption
(9374, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Arelion's Journal
(10103, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Report to Zurai
(9340, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Great Fissure
(9466, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Wanted: Blacktalon the Savage
(9381, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Trueflight Arrows
(9397, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Birds of a Feather
(10442, 1, 6, 0, 0, 0, 1000, 0, 0, 15211), -- Helping the Cenarion Post
(9345, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Preparing the Salve
(10809, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Wanted: Worg Master Kruush
(27727, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Deepholm!
(9171, 5, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Culinary Crunch
(9155, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Down the Dead Scar
(9193, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Investigate the Amani Catacombs
(9199, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Troll Juju
(9192, 1, 5, 0, 0, 0, 1000, 0, 0, 15211), -- Trouble at the Underlight Mines
(9160, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Investigate An'daroth
(9145, 5, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Help Ranger Valanna!
(9150, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Salvaging the Past
(9140, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Windrunner Village
(9149, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Plagued Coast
(9156, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Wanted: Knucklerot and Luzran
(9139, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Goldenmist Village
(9148, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Delivery to Tranquillien
(8490, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Powering our Defenses
(9147, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Fallen Courier
(8479, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Zul'Marosh
(29836, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- Just Checkin'
(12501, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Troll Patrol
(12507, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Strange Mojo
(9152, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tomber's Supplies
(9138, 1, 5, 0, 0, 0, 1000, 0, 0, 15211), -- Suncrown Village
(9758, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Return to Arcanist Vandril
(9327, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Forsaken
(8487, 1, 5, 0, 0, 0, 100, 0, 0, 15211), -- Corrupted Soil
(8473, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Somber Task
(24805, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Uncommon Scents
(10070, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Steady Shot
(9393, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hunter Training
(24691, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Peculiar Delicacies
(24692, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Fledgling Colossus
(24721, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Eastern Pylon
(24855, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Aberrant Flora
(24690, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Blazerunner
(24687, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Bouquets of Death
(13917, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Gorishi Grub
(24865, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Is This Stuff Still Good?
(24723, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Western Pylon
(24709, 1, 274, 22, 0, 0, 0, 0, 0, 15211), -- A Tale of Two Shovels
(24708, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Fossil-Finder 3000
(24707, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Ballad of Maximillian
(24706, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Spirits of Golakka Hot Springs
(24730, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Roll the Bones
(24704, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Evil Dragons of Un'Goro Crater
(24705, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Damsels Were Made to be Saved
(24703, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- An Important Lesson
(24736, 4, 1, 0, 0, 0, 0, 0, 0, 15211), -- Shizzle's Flyer
(24866, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- An Abandoned Research Camp
(24697, 3, 1, 1, 0, 0, 0, 0, 0, 15211), -- How to Make Meat Fresh Again
(28859, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Dunes of Silithus
(24720, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crystals of Power
(24740, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Volcanic Activity
(24742, 6, 4, 0, 0, 0, 0, 0, 0, 15211), -- Finding the Source
(24689, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Flowing to the North
(24733, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Bait for Lar'korwi
(13906, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- They Grow Up So Fast
(24686, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Carried on the Waves
(24732, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Scent of Lar'korwi
(13887, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Venomhide Eggs
(13850, 274, 0, 0, 0, 0, 0, 0, 0, 15211), -- Toxic Tolerance
(24731, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Fare of Lar'korwi
(24719, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Claws of White
(12792, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- First Things First
(12643, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Silver Lining
(12638, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Close Call
(12633, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Darkness Calling
(25250, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sealing the Dream
(25237, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tears of Stone
(25241, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Land, Corrupted
(25230, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- More Than Illness
(25339, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Vengeance on the Northspring
(25340, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Dark Heart
(25210, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Signs of Change
(12174, 1, 5, 1, 0, 0, 0, 0, 0, 15211), -- High Commander Halford Wyrmbane
(12171, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Of Traitors and Treason
(12172, 2, 1, 1, 25, 0, 0, 0, 0, 15211), -- Attunement to Dalaran
(11693, 1, 1, 25, 0, 0, 0, 0, 0, 15211), -- Oh Great... Plagued Magnataur!
(11798, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Gearmaster
(11725, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Finding Pilot Tailspin
(11788, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Lefty Loosey, Righty Tighty
(11692, 4, 5, 6, 1, 0, 0, 0, 0, 15211), -- Check in With Bixie
(11645, 5, 6, 1, 1, 0, 0, 0, 0, 15211), -- Dirty, Stinkin' Snobolds!
(11710, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- What's the Matter with the Transmatter?
(11704, 5, 1, 1, 0, 0, 0, 0, 0, 15211), -- King Mrgl-Mrgl
(11712, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Re-Cursive
(27593, 396, 396, 396, 113, 0, 0, 0, 0, 15211), -- Rebirth of the K.E.F.
(27591, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- The Dark Iron Pact
(27589, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- The Grim Guzzler
(27585, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- The 109th Division
(27582, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Infiltrating Shadowforge City
(27581, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Twilight?! No!
(27603, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- The Sealed Gate
(27579, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Into the Prison
(24905, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Returning a Favor
(27230, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Weapons for War
(27227, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Lord Aurius Rivendare
(27228, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Man Against Abomination
(27359, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Argent Reinforcements
(11708, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mechagnomes
(28545, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Winterspring!
(28526, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Un'Goro Crater!
(26187, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- The Downfall of Marl Wormthorn
(26962, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Stripping Their Offense
(26186, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- Demoniac Vessel
(26185, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Advice from the Cenarion Circle
(25772, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Kum'isha's Endeavors
(26184, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Wormthorn's Dream
(26162, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Altar of Storms
(26161, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Not Just Any Body
(26175, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- Surwich
(26166, 432, 1, 0, 0, 0, 0, 0, 0, 15211), -- Enhancing the Stone
(26174, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Watching Our Back
(26164, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Charred Granite of the Dark Portal
(26165, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Vile Blood of Demons
(26167, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- The Amulet of Allistarj
(26168, 396, 396, 1, 0, 0, 0, 0, 0, 15211), -- The Amulet of Sevine
(26169, 153, 396, 396, 0, 0, 0, 0, 0, 15211), -- The Amulet of Grol
(26160, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Blood Ritual
(27567, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Twilight?! No!
(26159, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The First Step
(26172, 1, 1, 6, 0, 0, 0, 0, 0, 15211), -- A Bloodmage's Gotta Eat Too
(26158, 1, 1, 5, 0, 0, 0, 0, 0, 15211), -- Attune the Bloodstone
(26157, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Kasim Sharim
(25716, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Cultists at our Doorstep
(25714, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Watcher Mahar Ba
(25708, 1, 92, 1, 0, 0, 0, 0, 0, 15211), -- Our Fallen Friends
(25709, 1, 1, 0, 0, 0, 1111, 0, 0, 15211), -- Curtail the Darktail
(25713, 1, 1, 0, 0, 0, 888, 0, 0, 15211), -- Remove Their Arms
(25712, 396, 396, 0, 0, 0, 555, 0, 0, 15211), -- Nethergarde Reigns
(25711, 25, 1, 1, 0, 0, 0, 0, 0, 15211), -- Eliminate the Okril'lon
(25710, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Minor Distractions
(25715, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- A Closer Look
(28398, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Pyromancer's Grimoire
(28673, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Blasted Lands!
(28180, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Sand, the Cider, and the Orb
(26642, 2, 1, 0, 0, 0, 0, 0, 0, 15211), -- Preserving the Barrens
(28510, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Feralas!
(28554, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Dustwallow Marsh!
(27124, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Unfinished Gordok Business
(27119, 1, 1, 6, 1, 0, 0, 0, 0, 15211), -- The Gordok Ogre Suit
(27125, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- King of the Gordok
(24663, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(24597, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Gift for the King of Stormwind
(25672, 1, 273, 25, 0, 0, 0, 0, 0, 15211), -- Carcass Collection
(25661, 273, 11, 0, 0, 0, 0, 0, 0, 15211), -- With a Little Help...
(25660, 6, 25, 0, 0, 0, 0, 0, 0, 15211), -- Haunted
(25627, 1, 25, 0, 0, 0, 0, 0, 0, 15211), -- Two-Tusk Takedown
(25609, 0, 0, 0, 0, 0, 1000, 0, 0, 15211), -- Sunken Treasure
(11881, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Load'er Up!
(11674, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Sage Highmesa is Missing
(11890, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- What Are They Up To?
(11684, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Scouting the Sinkholes
(11709, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Nork Bloodfrenzy's Charge
(11705, 1, 1, 6, 1, 0, 0, 0, 0, 15211), -- Foolish Endeavors
(11703, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Get to Getry
(11690, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Bring 'Em Back Alive
(11662, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Seek Out Karuk!
(11652, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- The Plains of Nasam
(11651, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Tanks a lot...
(11656, 1, 1, 5, 0, 0, 0, 0, 0, 15211), -- Burn in Effigy
(11661, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Orabus the Helmsman
(11664, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Escaping the Mist
(11643, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Mobu's Pneumatic Tank Transjigamarig
(11644, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Super Strong Metal Plates!
(11642, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tank Ain't Gonna Fix Itself
(11655, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Into the Mist
(11660, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Horn of the Ancient Mariner
(29658, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Calculator
(29659, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Lost Treasure
(29657, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- With Great Power, Comes Great Responsibility
(11676, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Merciful Freedom
(11686, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Warsong Farms
(11688, 5, 1, 1, 5, 0, 0, 0, 0, 15211); -- Damned Filthy Swine

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11636, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Magic Carpet Ride
(11634, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Wind Master To'bor
(11574, 5, 5, 1, 0, 0, 1000, 1000, 0, 15211), -- Too Close For Comfort
(12486, 6, 1, 1, 25, 0, 2000, 0, 0, 15211), -- To Bor'gorok Outpost, Quickly!
(13095, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Have They No Shame?
(29681, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Maximum Security Breakout
(29675, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hey There Dalliah
(29674, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Unbound Darkness
(28374, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Weeding the Lawn
(28361, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- Squirrely Clean
(28360, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Running Their Course
(28341, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Collecting Corruption
(28342, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Fel To Pieces
(28358, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hunting the Damned
(28359, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Core of Kroshius
(28305, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Fate of Bloodvenom Post
(28288, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Open Their Eyes
(11618, 1, 1, 1, 25, 0, 0, 0, 0, 15211), -- Reinforcements Incoming...
(11616, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Message to Hellscream
(11615, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Nerub'ar Secrets
(29609, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Friends in Dalaran
(11614, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Untold Truths
(11602, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Cutting Off the Source
(11608, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- Bury Those Cockroaches!
(11888, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Ride to Taunka'le Village
(11611, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Taken by the Scourge
(11606, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Patience is a Virtue that We Don't Need
(11598, 1, 1, 1, 25, 0, 0, 0, 0, 15211), -- Taking Back Mightstone Quarry
(11596, 1, 274, 1, 1, 0, 0, 0, 0, 15211), -- The Defense of Warsong Hold
(11585, 5, 1, 1, 66, 0, 0, 0, 0, 15211), -- Hellscream's Vigil
(13206, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- Disarmament
(30112, 6, 25, 0, 0, 0, 3000, 0, 0, 15211), -- A Score to Settle
(11262, 396, 396, 0, 0, 0, 500, 0, 0, 15211), -- Ingvar Must Die!
(10458, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Enraged Spirits of Fire and Earth
(13614, 1, 25, 0, 0, 0, 1000, 0, 0, 15211), -- Algalon
(25366, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Battle Plans
(25375, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Taming The Tamers
(25374, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sasquatch Sighting
(25378, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ysondre's Call
(25365, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Woodpaw Investigation
(25364, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Alpha Strike
(29599, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Escape from Durnholde
(24500, 0, 0, 0, 0, 60, 0, 0, 0, 15211), -- Wrath of the Lich King
(24711, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Frostmourne
(24710, 1, 1, 0, 0, 0, 60, 0, 0, 15211), -- Deliverance from the Pit
(24498, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Path to the Citadel
(24683, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Pit of Saron
(24499, 1, 1, 1, 0, 0, 60, 60, 0, 15211), -- Echoes of Tortured Souls
(25591, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Thunderdrome: Grudge Match!
(25107, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Grand Tablet
(25070, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- What Lies Within
(25069, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Secrets of Uldum
(25068, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Crumbling Past
(25017, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ancient Obstacles
(25020, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Fragments of Language
(25019, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Laying Claim
(25018, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Andoren Will Know
(25014, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sandscraper's Treasure
(25001, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sandscraper
(24963, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Maul 'Em With Kindness
(24957, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Get The Centipaarty Started
(24955, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Un-Chartered
(25391, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Weapons of Spirit
(25362, 5, 1, 1, 5, 0, 0, 0, 0, 15211), -- A Grim Discovery
(25346, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Mountain Giant Muisek
(25361, 2, 1, 1, 0, 0, 0, 0, 0, 15211), -- A New Cloak's Sheen
(25345, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Faerie Dragon Muisek
(25338, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Treant Muisek
(25349, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Twisted Sisters
(25373, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Hilltop Threat
(25643, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Darkmist Ruins
(27130, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Saving Warpwood
(27132, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Highborne
(25363, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- War on the Woodpaw
(25387, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- To Camp Mojache
(25329, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Might of the Stonemaul
(25344, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ogre Abduction
(25342, 5, 0, 0, 0, 0, 0, 0, 0, 15211), -- Talk to Swar'jan
(25252, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Rulers of Dire Maul
(25641, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Flow of Muisek
(25337, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hippogryph Muisek
(25452, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mark of Quality
(25336, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Testing the Vessel
(25209, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Gordunni Threat
(25341, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Gordunni Orb
(25386, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- To Stonemaul Hold
(24947, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Momentum
(24910, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Rocket Rescue
(27128, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- King of the Gordok
(24907, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Puddle Stomping
(24906, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Seaside Salvage
(26417, 1, 25, 1, 0, 0, 0, 0, 0, 15211), -- Northern Stranglethorn: The Fallen Empire
(13842, 5, 396, 0, 0, 0, 500, 0, 0, 15211), -- Dread Head Redemption
(26416, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Well, Come to the Jungle
(25, 5, 1, 153, 0, 0, 500, 500, 0, 15211), -- Simmer Down Now
(13967, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Thinning the... Herd?
(25945, 1, 5, 1, 15, 0, 0, 0, 0, 15211), -- We're Here to Do One Thing, Maybe Two...
(13870, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- As Good as it Gets
(13865, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Wet Work
(13815, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Making Stumps
(6441, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Satyr Horns
(13806, 1, 5, 1, 0, 0, 1500, 1000, 0, 15211), -- Demon Duty
(13841, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- All Apologies
(13798, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Rain of Destruction
(13797, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Dirty Deeds
(26449, 5, 1, 1, 0, 0, 1000, 1000, 0, 15211), -- Never Again!
(13808, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Mission Improbable
(13848, 396, 396, 0, 0, 0, 1000, 0, 0, 15211), -- Bad News Bear-er
(13751, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tell No One!
(26447, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Diabolical Plans
(6544, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Torek's Assault
(13801, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Dead Elves Walking
(13730, 1, 1, 0, 0, 0, 500, 0, 0, 15211), -- Playing With Felfire
(13805, 1, 153, 5, 0, 0, 1000, 1000, 0, 15211), -- Pierce Their Heart!
(26448, 5, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Destroy the Legion
(6503, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Ashenvale Outrunners
(13803, 5, 0, 0, 0, 0, 0, 0, 0, 15211), -- Blood of the Weak
(13712, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- To the Rescue!
(13653, 1, 5, 1, 0, 0, 500, 500, 0, 15211), -- Crisis at Splintertree
(13651, 1, 1, 0, 0, 0, 500, 0, 0, 15211), -- Needs a Little Lubrication
(2, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sharptalon's Claw
(13640, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Management Material
(13628, 1, 1, 0, 0, 0, 500, 0, 0, 15211), -- Got Wood?
(13621, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Gorat's Vengeance
(13620, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- To Dinah, at Once!
(13619, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Final Report
(13618, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Find Gorat!
(13612, 5, 1, 1, 0, 0, 500, 500, 0, 15211), -- Mor'shan Defense
(13615, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Empty Quivers
(13613, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Rescue the Fallen
(28493, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Ashenvale!
(24645, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(14422, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Raptor Raptor Rocket
(14408, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Nine's Plan
(14262, 388, 1, 0, 0, 0, 0, 0, 0, 15211), -- To Gut a Fish
(14267, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Investigating the Sea Shrine
(14258, 11, 5, 0, 0, 0, 0, 0, 0, 15211), -- Mortar the Point
(14216, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Mystery of the Sarcen Stone
(14424, 18, 5, 0, 0, 0, 0, 0, 0, 15211), -- Need More Science
(14423, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Dozercism
(14209, 6, 274, 0, 0, 0, 0, 0, 0, 15211), -- Gunk in the Trunk
(14215, 432, 1, 0, 0, 0, 0, 0, 0, 15211), -- Memories of the Dead
(14201, 1, 273, 0, 0, 0, 0, 0, 0, 15211), -- A Thousand Stories in the Sand
(14202, 275, 25, 0, 0, 0, 0, 0, 0, 15211), -- Survey the Lakeshore
(24453, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Private Chat
(28582, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Searing Gorge!
(8873, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Lunar Festival
(28048, 5, 0, 0, 0, 0, 0, 0, 0, 15211), -- That Smart One's Gotta Go
(28047, 1, 273, 25, 0, 0, 0, 0, 0, 15211), -- Freezing the Pipes
(28051, 18, 6, 0, 0, 0, 0, 0, 0, 15211), -- We All Scream for Ice Cream... and then Die!
(28045, 5, 274, 15, 0, 0, 0, 0, 0, 15211), -- The Greatest Flavor in the World!
(27677, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Archaedas, The Ancient Stone Watcher
(27672, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Chamber of Khaz'mul
(27676, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Behind Closed Doors
(27673, 396, 396, 396, 397, 0, 0, 0, 0, 15211), -- It's What's Inside That Counts
(25304, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Battle of Sardor
(26985, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Pitting Madness Against Madness
(25463, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Report to Silvia
(25399, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hatecrest Forces
(25458, 15, 0, 0, 0, 0, 0, 0, 0, 15211), -- General Skessesh
(25449, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mark of Quality
(26402, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- General Shandris Feathermoon
(25398, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Sealing the Dream
(25396, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tears of Stone
(25397, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Land, Corrupted
(26974, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The False Champion
(28934, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(24804, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Uncommon Scents
(11571, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Learning to Communicate
(11627, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Boiling Point
(11702, 5, 1, 1, 0, 0, 0, 0, 0, 15211), -- King Mrgl-Mrgl
(11591, 5, 1, 1, 0, 0, 0, 0, 0, 15211), -- Report to Steeljaw's Caravan
(11624, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Sky Will Know
(10984, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Speak with the Ogre
(29685, 1, 1, 0, 0, 0, 1000, 0, 0, 15211), -- Hard to Kill
(11490, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Scryer's Scryer
(29686, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- A Radical Notion
(29687, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- Twisted Associations
(29684, 396, 0, 0, 0, 0, 1000, 1000, 0, 15211), -- Severed Communications
(10297, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Opening of the Dark Portal
(10279, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- To The Master's Lair
(28509, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Tanaris!
(11575, 5, 5, 1, 0, 0, 1000, 1000, 0, 15211), -- Nick of Time
(9933, 1, 1, 1, 2, 0, 0, 0, 0, 15211), -- Message to Telaar
(9955, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Cho'war the Pillager
(9931, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Returning the Favor
(9932, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Body of Evidence
(9927, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Ruthless Cunning
(9928, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Armaments for Deception
(9954, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Corki's Ransom
(10108, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Diplomatic Measures
(9999, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Buying Time
(9991, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Survey the Land
(9956, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Ravaged Caravan
(9982, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- He Called Himself Altruis...
(9922, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Twin Clefts of Nagrand
(9924, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Corki's Gone Missing Again!
(24665, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(27436, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Shadow-Walker's Task
(29571, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Defending the Wilds
(9869, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- The Throne of the Elements
(9878, 1, 1, 1, 25, 0, 0, 0, 0, 15211), -- Solving the Problem
(9874, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Stopping the Spread
(9921, 1, 1, 1, 5, 0, 0, 0, 0, 15211), -- The Ruins of Burning Blade
(9920, 5, 1, 0, 0, 0, 0, 0, 0, 15211), -- Mo'mor the Breaker
(9918, 1, 1, 1, 1, 0, 0, 0, 0, 15211), -- Not On My Watch!
(10115, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Daggerfen Deviance
(26386, 94, 273, 94, 0, 0, 500, 500, 0, 15211), -- Surkhan
(26362, 94, 273, 94, 0, 0, 500, 500, 0, 15211), -- Be Raptor
(26405, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- Zul'Mamwe Mambo
(26304, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Nighttime in the Jungle
(26360, 94, 273, 94, 0, 0, 500, 500, 0, 15211), -- Mind Control
(26359, 94, 273, 94, 0, 0, 500, 500, 0, 15211), -- See Raptor
(26351, 94, 273, 94, 0, 0, 500, 500, 0, 15211), -- Mind Vision
(26350, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Priestess Hu'rala
(208, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Big Game Hunter
(197, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Raptor Mastery
(196, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Raptor Prowess
(26345, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Excelsior
(192, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Panther Prowess
(195, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Raptor Stalking
(26344, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Some Assembly Required
(26352, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Cozzle's Plan
(26403, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Venture Company Mining
(26305, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Saving Yenniku
(26400, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Universal Key
(26303, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mind's Eye
(26404, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Above My Pay Grade
(26399, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Mosh'Ogg Bounty
(26334, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Bloodlord Mandokir
(26302, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Chasing Yenniku's Fate
(188, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tiger Mastery
(187, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Tiger Prowess
(191, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Panther Stalking
(186, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Tiger Stalking
(26269, 5, 18, 1, 0, 0, 0, 0, 0, 15211), -- The Green Hills of Stranglethorn
(194, 6, 1, 0, 0, 0, 0, 0, 0, 15211), -- Raptor Hunting
(583, 2, 1, 1, 0, 0, 0, 0, 0, 15211), -- Welcome to the Jungle
(26343, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Supply and Demand
(28549, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Southern Barrens!
(28548, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Warchief's Command: Desolace!
(26301, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Speaking with Nezzliok
(26332, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Skullsplitter Mojo
(26338, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Population Con-Troll
(26340, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- The Hunt
(26300, 396, 396, 396, 0, 0, 0, 0, 0, 15211), -- Nezzliok Will Know
(26330, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Who's a Big Troll?
(26407, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Mosh'Ogg Handiwork
(24647, 1, 5, 0, 0, 0, 0, 0, 0, 15211), -- Crushing the Crown
(28532, 1, 1, 1, 0, 0, 0, 0, 0, 15211); -- Warchief's Command: Stonetalon Mountains!

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9457, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- An Unusual Patron
(26325, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Nose for This Sort of Thing
(26299, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Headhunting
(26323, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Favored Skull
(26298, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Hunt for Yenniku
(26281, 396, 396, 396, 113, 0, 0, 0, 0, 15211), -- The Defense of Grom'gol: Trollish Thievery
(26321, 396, 0, 0, 0, 0, 0, 0, 0, 15211), -- I Think She's Hungry
(26279, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- The Defense of Grom'gol: Ogre Oppression
(26280, 396, 396, 0, 0, 0, 0, 0, 0, 15211), -- The Defense of Grom'gol: Murloc Menace
(26317, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Lashtail Hatchling
(26278, 113, 396, 396, 0, 0, 0, 0, 0, 15211), -- The Defense of Grom'gol: Raptor Risk
(28031, 1, 273, 6, 0, 0, 0, 0, 0, 15211), -- Special Delivery for Brivelthwerp
(25744, 4, 1, 25, 0, 0, 0, 0, 0, 15211), -- Negotiations
(25588, 6, 0, 0, 0, 0, 0, 0, 0, 15211), -- A Little Payback
(25590, 6, 1, 5, 0, 0, 0, 0, 0, 15211), -- Where's Wizzle?
(25585, 5, 1, 25, 0, 0, 0, 0, 0, 15211), -- Quiet the Cannons
(25542, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Circle the Wagons... er, Boats
(25532, 5, 25, 0, 0, 0, 0, 0, 0, 15211), -- Pirate Accuracy Increasing
(25524, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- In the Outhouse
(1456, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Karnitol Shipwreck
(26903, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Willix the Importer
(26905, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Agamaggan's Charge
(26901, 1, 1, 1, 0, 0, 0, 0, 0, 15211), -- Going, Going, Guano!
(26907, 1, 0, 0, 0, 0, 0, 0, 0, 15211), -- Take Them Down!
(26906, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Agamaggan
(28550, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- Hero's Call: Southern Barrens!
(14257, 396, 396, 396, 0, 0, 500, 0, 0, 15211), -- Slitherblade Slaughter
(1455, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Karnitol Shipwreck
(14256, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- The Emerging Threat
(26993, 0, 0, 0, 0, 0, 0, 0, 0, 15211), -- Compendium of the Fallen
(26973, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Only True Path
(26942, 1, 1, 11, 0, 0, 0, 0, 0, 15211), -- The G-Team
(26941, 1, 1, 11, 0, 0, 0, 0, 0, 15211), -- The G-Team
(26939, 1, 1, 11, 0, 0, 0, 0, 0, 15211), -- The G-Team
(26972, 1, 1, 0, 0, 0, 0, 0, 0, 15211), -- The Dark Side of the Light
(29309, 1, 0, 0, 0, 0, 0, 0, 0, 15211); -- The Stuff of Legends

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9731; -- Drain Schematics
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9800; -- A Rare Bean
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9819; -- The Tortured Earth
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9912; -- The Cenarion Expedition
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9936; -- Wanted: Giselda the Crone
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=9940; -- Wanted: Zorbo the Advisor
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=10017; -- Strained Supplies
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=10412; -- Firewing Signets
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=10416; -- Synthesis of Power
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=10476; -- Fierce Enemies
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11096; -- Threat from Above
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11599; -- Thassarian, My Brother
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11600; -- The Late William Allerton
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11601; -- Lost and Found
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11603; -- In Wine, Truth
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11619; -- Gamel the Cruel
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11620; -- A Father's Words
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11625; -- The Trident of Naz'jan
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11626; -- The Emissary
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11680; -- Taking Wing
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11733; -- Traversing the Rift
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11793; -- Further Investigation
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11794; -- The Hunt is On
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11873; -- Give Fizzcrank the News
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11904; -- Fruits of Our Labor
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11927; -- Word on the Street
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11932; -- Cowards and Fools
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11938; -- Buying Some Time
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11940; -- Drake Hunt
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11941; -- Puzzling...
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11942; -- Words of Power
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11943; -- The Cell
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11944; -- Surrounded!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11956; -- Finding the Phylactery
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11962; -- One Last Delivery
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11963; -- Weapons for Farshire
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11965; -- Call to Arms!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=11967; -- Mustering the Reds
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12006; -- Avenge this Atrocity!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12013; -- End Arcanimus
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12035; -- Repurposed Technology
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12055; -- A Strange Device
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12086; -- The Son of Karkut
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12088; -- Thassarian, the Death Knight
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15211 WHERE `ID`=12107; -- The End of the Line
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15211 WHERE `ID`=10113; -- The Nesingwary Safari
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15211 WHERE `ID`=12954; -- The Amphitheater of Anguish: Yggdras!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15211 WHERE `ID`=9805; -- Blessing of Incineratus
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15211 WHERE `ID`=12235; -- Naxxramas and the Fall of Wintergarde
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5, `VerifiedBuild`=15211 WHERE `ID`=12237; -- Flight of the Wintergarde Defender
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9777; -- Fulgor Spores
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9781; -- Too Many Mouths to Feed
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9782; -- The Dead Mire
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9783; -- An Unnatural Drought
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9786; -- The Boha'mu Ruins
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9787; -- Idols of the Feralfen
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9790; -- Diaphanous Wings
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9793; -- The Fate of Tuurem
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9794; -- No Time for Curiosity
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9801; -- Gathering the Reagents
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9804; -- Agitated Spirits of Skysong
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9815; -- Muck Diving
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9835; -- Ango'rosh Encroachment
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9848; -- Secrets of the Daggerfen
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=9938; -- Wanted: Durn the Hungerer
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=10116; -- Wanted: Chieftain Mummaki
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=12000; -- Rifle the Bodies
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=12511; -- The Hills Have Us
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25, `Emote4`=1, `VerifiedBuild`=15211 WHERE `ID`=12060; -- Projections and Plans
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15211 WHERE `ID`=12458; -- Seeds of the Lashers
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=9776; -- The Orebor Harborage
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=9791; -- Menacing Marshfangs
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=9901; -- Unfinished Business
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11713; -- Scouting the Sinkholes
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11715; -- Fueling the Project
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11718; -- A Bot in Mammoth's Clothing
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11723; -- Deploy the Shake-n-Quake!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11726; -- A Little Bit of Spice
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11728; -- Lupus Pupus
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11795; -- Emergency Protocol: Section 8.2, Paragraph C
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=11796; -- Emergency Protocol: Section 8.2, Paragraph D
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=12728; -- Monitoring the Rift: Winterfin Cavern
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=6, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=12098; -- Search Indu'le Village
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=11604; -- A Deserter
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=11681; -- Rescuing Evanor
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=11910; -- Secrets of the Ancients
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=11969; -- Springing the Trap
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=12019; -- Last Rites
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=12416; -- Heated Battle
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15211 WHERE `ID`=12460; -- Report to the Ruby Dragonshrine
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=2, `VerifiedBuild`=15211 WHERE `ID`=12119; -- Gaining an Audience
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=11044; -- Visions of Destruction
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=11046; -- Chief Apothecary Hildagard
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=11039; -- Report to Spymaster Thalodien
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=11042; -- A Mystifying Vision
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15211 WHERE `ID`=12166; -- The Liquid Fire of Elune
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=25, `VerifiedBuild`=15211 WHERE `ID`=9917; -- Do My Eyes Deceive Me
UPDATE `quest_details` SET `Emote1`=25, `Emote2`=1, `VerifiedBuild`=15211 WHERE `ID`=12004; -- Prevent the Accord
UPDATE `quest_details` SET `EmoteDelay1`=2000, `VerifiedBuild`=15211 WHERE `ID`=10278; -- The Warp Rifts
UPDATE `quest_details` SET `EmoteDelay1`=6000, `VerifiedBuild`=15211 WHERE `ID`=10220; -- Make Them Listen
UPDATE `quest_details` SET `EmoteDelay2`=1000, `VerifiedBuild`=15211 WHERE `ID`=9732; -- Return to the Marsh
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=54; -- Report to Goldshire
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=185; -- Tiger Hunting
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=190; -- Panther Hunting
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=2158; -- Rest and Relaxation
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=3100; -- Simple Letter
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8326; -- Unfortunate Measures
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8327; -- Report to Lanthan Perilon
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8335; -- Felendren the Banished
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8338; -- Tainted Arcane Sliver
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8347; -- Aiding the Outrunners
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8350; -- Completing the Delivery
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8867; -- Lunar Fireworks
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=8883; -- Valadar Starsong
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9372; -- Demonic Contamination
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9390; -- In Search of Sedai
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9398; -- Deadly Predators
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9399; -- Cruel Taskmasters
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9423; -- Return to Obadei
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9436; -- Bloodscalp Insight
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9490; -- The Rock Flayer Matriarch
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9704; -- Slain by the Wretched
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9705; -- Package Recovery
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9724; -- Warning the Cenarion Circle
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9728; -- A Warm Welcome
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9752; -- Escape from Umbrafen
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9769; -- There's No Explanation for Fashion
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9770; -- Menacing Marshfangs
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9773; -- No More Mushrooms!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9774; -- Thick Hydra Scales
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9775; -- Report to Shadow Hunter Denjai
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9788; -- A Damp, Dark Place
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9796; -- News from Zangarmarsh
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9818; -- The Underneath
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9894; -- Safeguarding the Watchers
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=9895; -- The Dying Balance
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10037; -- Rather Be Fishin'
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10047; -- The Path of Glory
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10050; -- Unyielding Souls
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10058; -- An Old Gift
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10078; -- Laying Waste to the Unwanted
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10093; -- The Temple of Telhamat
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10119; -- Through the Dark Portal
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10132; -- Colossal Menace
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10159; -- Keep Thornfang Hill Clear!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10180; -- Can't Stay Away
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10242; -- Spinebreaker Post
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10349; -- The Earthbinder
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10351; -- Natural Remedies
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10483; -- Ill Omens
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10484; -- Cursed Talismans
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10485; -- Warlord of the Bleeding Hollow
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10538; -- Boiling Blood
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10847; -- The Eyes of Skettis
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10903; -- Return to Honor Hold
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10909; -- Fel Spirits
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10916; -- Digging for Prayer Beads
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10917; -- The Outcast's Plight
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10935; -- The Exorcism of Colonel Jules
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10936; -- Trollbane is Looking for You
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10937; -- Drill the Drillmaster
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=10983; -- Mog'dorg the Wizened
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11576; -- Monitoring the Rift: Cleftcliff Anomaly
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11582; -- Monitoring the Rift: Sundered Chasm
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11587; -- Prison Break
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11590; -- Abduction
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11613; -- Karuk's Oath
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11646; -- The Borean Inquisition
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11648; -- The Art of Persuasion
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11663; -- Sharing Intelligence
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11671; -- A Race Against Time
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11679; -- Reforging the Key
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11682; -- Dragonspeak
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11727; -- A Time for Heroes
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11789; -- A Soldier in Need
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11791; -- Notify Arlos
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11792; -- Enemies of the Light
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11797; -- The Siege
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11889; -- Death From Above
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11897; -- Plug the Sinkholes
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11900; -- Reading the Meters
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11901; -- Military?  What Military?
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11902; -- Pernicious Evidence
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11903; -- It's Time for Action
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11908; -- Reference Material
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11912; -- Nuts for Berries
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11913; -- Take No Chances
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11914; -- Keep the Secret Safe
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11918; -- Basic Training
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11919; -- Drake Hunt
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11920; -- Cultists Among Us
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11928; -- Farshire
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11931; -- Cracking the Code
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11936; -- Hatching a Plan
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11945; -- Preparing for the Worst
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11946; -- Keristrasza
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11951; -- Bait and Switch
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11957; -- Saragosa's End
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=11973; -- Prisoner of War
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12105; -- Descent into Darkness
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12109; -- Report to Gryan Stoutmantle... Again
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12141; -- A Diplomatic Mission
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12210; -- Troll Season!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12212; -- Replenishing the Storehouse
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12215; -- Them or Us!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12216; -- Take Their Rear!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12217; -- Eagle Eyes
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12222; -- Secrets of the Flamebinders
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12223; -- Thinning the Ranks
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12225; -- Mmm... Amberseeds!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12226; -- Just Passing Through
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12227; -- Doing Your Duty
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12255; -- The Thane of Voldrune
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12292; -- Local Support
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12293; -- Close the Deal
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12294; -- A Tentative Pact
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12295; -- An Exercise in Diplomacy
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12299; -- Northern Hospitality
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12300; -- Test of Mettle
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12302; -- Words of Warning
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12307; -- Wolfsbane Root
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12308; -- Escape from Silverbrook
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12444; -- Blackriver Skirmish
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12447; -- The Obsidian Dragonshrine
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12470; -- Mystery of the Infinite
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12471; -- Cruelty of the Kvaldir
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12766; -- Speak with your Ambassador
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12790; -- Learning to Leave and Return: the Magical Way
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12857; -- Wanted: Ragemane's Flipper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12859; -- This Just In: Fire Still Hot!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12861; -- Trolls Is Gone Crazy!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12883; -- Orders From Drakuru
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12884; -- The Ebon Watch
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12894; -- Crusader Forward Camp
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12901; -- Making Something Out Of Nothing
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12902; -- In Search Of Answers
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=12903; -- That's What Friends Are For...
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=13094; -- Have They No Shame?
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=13408; -- Hellfire Fortifications
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=13418; -- Preparations for War
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=24589; -- Lord Jaraxxus Must Die!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25233; -- End of the Supply Line
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25234; -- In the Rear With the Gear
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25255; -- Harrying the Hunters
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25268; -- The Voice of Goldrinn
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25271; -- Goldrinn's Ferocity
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25273; -- Lycanthoth the Corruptor
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25278; -- Cleaning House
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25280; -- The Shrine Reclaimed
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25297; -- From the Mouth of Madness
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25298; -- Free Your Mind, the Rest Follows
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25300; -- The Eye of Twilight
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25301; -- Mastering Puppets
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25303; -- Elementary!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25312; -- Return to Duskwhisper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25317; -- Protect the World Tree
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25319; -- War on the Twilight's Hammer
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25320; -- The Captured Scout
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25321; -- Twilight Captivity
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25323; -- Flamebreaker
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25324; -- A Prisoner of Interest
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25325; -- Through the Dream
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25328; -- Gar'gol's Gotta Go
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25332; -- Get Me Outta Here!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25352; -- Sweeping the Shelf
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25353; -- Lightning in a Bottle
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25370; -- Inciting the Elements
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25372; -- Aessina's Miracle
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25381; -- Fighting Fire With ... Anything
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25382; -- Disrupting the Rituals
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25385; -- Save the Wee Animals
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25392; -- Oh, Deer!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25404; -- If You're Not Against Us...
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25408; -- Seeds of Their Demise
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25411; -- A New Master
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25412; -- The Name Never Spoken
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25424; -- Return to Alysra
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25428; -- Black Heart of Flame
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25430; -- Emerald Allies
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25460; -- The Earth Rises
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25462; -- The Bears Up There
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25464; -- The Return of Baron Geddon
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25472; -- The Flameseer's Staff
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25490; -- Smashing Through Ashes
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25491; -- Durable Seeds
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25492; -- Firebreak
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25493; -- Fresh Bait
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25502; -- Prepping the Soil
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25507; -- Hell's Shells
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25510; -- Tortolla Speaks
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25514; -- Breaking the Bonds
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25519; -- Children of Tortolla
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25520; -- An Ancient Awakens
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25523; -- Flight in the Firelands
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25525; -- Wave One
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25544; -- Wave Two
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25560; -- Egg Wave
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25574; -- Flames from Above
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25575; -- Forged of Shadow and Flame
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25576; -- Rage of the Wolf Ancient
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25577; -- Crushing the Cores
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25578; -- Return to Nordrassil
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25584; -- The Return of the Ancients
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25599; -- Cindermaul, the Portal Master
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25600; -- Forgemaster Pyrendius
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25611; -- Return from the Firelands
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25618; -- Into the Maw!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25630; -- The Fires of Mount Hyjal
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25655; -- The Wormwing Problem
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25656; -- Scrambling for Eggs
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25663; -- An Offering for Aviana
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25664; -- A Prayer and a Wing
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25665; -- A Plea From Beyond
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25731; -- A Bird in Hand
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25740; -- Fact-Finding Mission
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25746; -- Sethria's Brood
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25758; -- A Gap in Their Armor
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25761; -- Disassembly
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25763; -- The Codex of Shadows
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25764; -- Egg Hunt
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25776; -- Sethria's Demise
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25795; -- Return to the Shrine
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25807; -- An Ancient Reborn
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25810; -- The Hatchery Must Burn
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25830; -- The Last Living Lorekeeper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25832; -- Return to Aviana
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25842; -- Firefight
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25843; -- Tortolla's Revenge
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25881; -- Lost Wardens
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25886; -- Pressing the Advantage
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25899; -- Breakthrough
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25901; -- Hyjal Recycling Program
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25904; -- The Hammer and the Key
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25906; -- The Third Flamegate
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25910; -- The Time for Mercy has Passed
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=25940; -- Last Stand at Whistling Grove
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26244; -- The Earth Claims All
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26245; -- Gunship Down
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26246; -- Captain's Log
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26247; -- Diplomacy First
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26248; -- All Our Friends Are Dead
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26249; -- The Admiral's Cabin
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26250; -- On Second Thought, Take One Prisoner
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26251; -- Take No Prisoners
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26254; -- Some Spraining to Do
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26255; -- Return to the Temple of Earth
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26256; -- Bleed the Bloodshaper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26258; -- Deathwing's Fall
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26259; -- Blood of the Earthwarder
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26260; -- The Forgemaster's Log
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26261; -- Question the Slaves
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26409; -- Where's Goldmine?
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26410; -- Explosive Bonding Compound
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26411; -- Apply and Flash Dry
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26413; -- Take Him to the Earthcaller
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26427; -- Without a Captain or Crew
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26484; -- To Stonehearth's Aid
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26499; -- Stonefather's Boon
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26500; -- We're Surrounded
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26501; -- Sealing the Way
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26502; -- Thunder Stones
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26537; -- Shatter Them!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26564; -- Fixer Upper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26591; -- Battlefront Triage
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26625; -- Troggzor the Earthinator
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26632; -- Close Escort
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26755; -- Keep Them off the Front
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26762; -- Reactivate the Constructs
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26766; -- Big Game, Big Bait
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26768; -- To Catch a Dragon
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26770; -- Mystic Masters
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26771; -- Testing the Trap
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26791; -- Sprout No More
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26792; -- Fungal Monstrosities
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26834; -- Down Into the Chasm
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26835; -- A Slight Problem
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26857; -- Abyssion's Minions
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26861; -- Block the Gates
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=26876; -- The World Pillar Fragment
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27003; -- Easy Money
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27007; -- Silvermarsh Rendezvous
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27010; -- Quicksilver Submersion
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27061; -- The Twilight Overlook
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27123; -- Deepholm, Realm of Earth
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27126; -- Rush Delivery
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27135; -- Something that Burns
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27136; -- Elemental Energy
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27141; -- Premature Explosionation
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27176; -- Just the Tip
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27179; -- Field Work
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27187; -- Do the World a Favor
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27196; -- On to Something
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27203; -- The Maelstrom
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27431; -- Tipping the Balance
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27511; -- The Thrill of Discovery
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27517; -- Be Prepared
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27519; -- Under the Choking Sands
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27520; -- Minions of Al'Akir
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27541; -- Lessons From the Past
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27549; -- By the Light of the Stars
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27595; -- The Prophet Hadassi
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27602; -- The Prophet's Dying Words
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27623; -- Colossal Guardians
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27624; -- After the Fall
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27628; -- Send Word to Phaoris
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27629; -- The Vizier's Vote
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27630; -- The High Priest's Vote
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27631; -- The High Commander's Vote
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27632; -- Tanotep's Son
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27669; -- Do the Honors
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27706; -- The Scepter of Orsis
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27707; -- Neferset Prison
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27738; -- The Pit of Scales
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27839; -- Ancient Weapons
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27899; -- That Gleam in his Eye
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27900; -- I've Got This Guy
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27901; -- They Don't Know What They've Got Here
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27903; -- Ignition
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27905; -- Tailgunner!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27922; -- Traitors!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27923; -- Smoke in Their Eyes
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27924; -- Budd's Plan
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27926; -- Eastern Hospitality
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27928; -- A Favor for the Furrier
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27931; -- The Quaking Fields
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27932; -- The Axe of Earthly Sundering
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27933; -- Elemental Ore
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27934; -- One With the Ground
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27935; -- Bring Down the Avalanche
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27939; -- The Desert Fox
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27941; -- Fashionism
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27942; -- Idolatry
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27943; -- Angered Spirits
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27950; -- Gobbles!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27969; -- Make Yourself Useful
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27990; -- Battlezone
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=27993; -- Take it to 'Em!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28002; -- Crisis Management
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28105; -- Kavem the Callous
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28112; -- Escape From the Lost City
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28132; -- Efficient Excavations
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28134; -- Impending Retribution
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28135; -- Al'Akir's Vengeance
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28141; -- Relics of the Sun King
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28145; -- Venomblood Antidote
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28187; -- Missed Me By Zhat Much!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28193; -- Lockdown!
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28194; -- The Great Escape
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28195; -- Sending a Message
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28198; -- The Weakest Link
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28200; -- The Element of Supplies
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28201; -- Ploughshares to Swords
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28210; -- Shaping Up
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28250; -- Thieving Little Pluckers
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28267; -- Firing Squad
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28269; -- Meet Me In Vir'sar
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28273; -- Friend of a Friend
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28274; -- Two Tents
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28276; -- Salhet's Secret
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28277; -- Salhet the Tactician
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28291; -- Return to Camp
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28350; -- Master Trapper
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28502; -- The Bandit Warlord
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=28866; -- Into the Stonecore
UPDATE `quest_details` SET `VerifiedBuild`=15211 WHERE `ID`=29066; -- Good News... and Bad News

DELETE FROM `quest_details` WHERE `ID` IN (13413 /*Aces High!*/, 9829 /*Khadgar*/, 9826 /*Contact from Dalaran*/, 9825 /*Restless Activity*/, 9824 /*Arcane Disturbances*/, 14388 /*Azsharite Experiment Number Two*/, 14383 /*The Terrible Tinkers of the Ruined Reaches*/, 14385 /*Azsharite Experiment Number One*/, 14377 /*Befriending Giants*/, 14371 /*A Gigantic Snack*/, 14370 /*Mysterious Azsharite*/, 14310 /*Segmentation Fault: Core Dumped*/, 14322 /*Bad Science! Bad!*/, 14308 /*When Science Attacks*/, 25723 /*Thresh Out of Luck*/, 25722 /*Sedimentary, My Dear*/, 25721 /*Fight the Flood*/, 27026 /*Defcon: Bobcat*/, 27032 /*Bird is the Word*/, 27356 /*The Circle's Future*/, 27016 /*The Joy of Boar Hunting*/, 27028 /*Hornet Hunting*/, 27030 /*Foxtails By The Handful*/, 27025 /*Thistle While You Work*/, 25383 /*Ysondre's Farewell*/, 25379 /*Taerar's Fall*/, 25369 /*Stinglasher*/, 25367 /*Zukk'ash Infestation*/, 9175 /*The Lady's Necklace*/, 28356 /*Preemptive Strike*/, 26588 /*A Furious Catch*/, 6608 /*You Too Good.*/, 24431 /*Waterlogged Recipe*/, 26079 /*Wanted!  Otto and Falconcrest*/, 26943 /*Home Sweet Gnome*/, 26336 /*Shakes O'Breen*/, 26024 /*Wanted!  Marez Cowl*/, 26113 /*Quae and Kinelory*/, 26093 /*Northfold Manor*/, 26035 /*Worth Its Weight in Gold*/, 8168 /*The Battle for Arathi Basin!*/, 25805 /*Return the Statuette*/, 26882 /*Blackfathom Villainy*/, 25804 /*Search More Hovels*/, 25803 /*The Search Continues*/, 25801 /*Claws from the Deep*/, 25802 /*Reclaiming Goods*/, 28237 /*A Blight Upon the Land*/, 28235 /*Burnside Must Fall*/, 28231 /*Do it for Twinkles*/, 28230 /*Protocol*/, 28209 /*Freedom for Lydon*/, 28206 /*Little Girl Lost*/, 28196 /*The Battle for Hillsbrad*/, 28189 /*Do the Right Thing*/, 28199 /*For Science!*/, 28197 /*Discretion is Key*/, 28192 /*No One Here Gets Out Alive*/, 28168 /*Trouble at the Sludge Fields*/, 28156 /*Deep Mine Rescue*/, 28138 /*Human Infestation*/, 28144 /*Thieving Little Monsters!*/, 28146 /*Coastal Delicacies!*/, 28115 /*Past Their Prime*/, 28114 /*Glorious Harvest*/, 28111 /*Trouble at Azurelode*/, 28096 /*Welcome to the Machine*/, 28331 /*Helcular's Rod Giveth...*/, 28332 /*Helcular's Command*/, 28325 /*Green Living*/, 28324 /*Studies in Lethality*/, 28620 /*Eastpoint Tower*/, 28619 /*Warchief's Command: Arathi Highlands!*/, 28495 /*A Fighting Chance*/, 28487 /*Humbert's Personal Problems*/, 28485 /*Yetimus the Yeti Lord*/, 28484 /*The Heart of the Matter*/, 28489 /*Stagwiches*/, 29316 /*Back to Basics*/, 29321 /*Happy as a Clam Digger*/, 26488 /*Big Gulp*/, 8314 /*Unraveling the Mystery*/, 8306 /*Into The Maw of Madness*/, 8285 /*The Deserter*/, 8284 /*The Twilight Mystery*/, 9419 /*Scouring the Desert*/, 8278 /*Noggle's Last Hope*/, 8281 /*Stepping Up Security*/, 26557 /*A Staggering Effort*/, 29247 /*Treating the Wounds*/, 28637 /*A Taste for Bear*/, 28638 /*The Owls Have It*/, 28828 /*You Gotta Have Eggs*/, 28640 /*Fresh Frostsabers*/, 28610 /*Rubble Trouble*/, 28609 /*Hammer Time*/, 28848 /*Trailing the Spiritspeaker*/, 28537 /*In Pursuit of Shades*/, 28536 /*The Curse of Zin-Malor*/, 28519 /*Pain of the Blood Elves*/, 28535 /*Descendants of the High Elves*/, 28518 /*Legacy of the High Elves*/, 28534 /*Descendants of the Highborne*/, 28513 /*Pride of the Highborne*/, 28479 /*The Ruins of Kel'Theril*/, 28472 /*Words of the High Chief*/, 28471 /*The Final Piece*/, 28470 /*High Chief Winterfall*/, 28530 /*Scalding Signs*/, 28469 /*Winterfall Runners*/, 28467 /*Mystery Goo*/, 29345 /*Pond Predators*/, 29363 /*Mulgore Spice Bread*/, 26012 /*Trouble at Wyrmrest*/, 29354 /*Shiny Baubles*/, 29358 /*Pining for Nuts*/, 29346 /*The Ring's the Thing*/, 29362 /*"Magic" Mushrooms*/, 13832 /*Jewel Of The Sewers*/, 13479 /*The Great Egg Hunt*/, 29272 /*Need... Water... Badly...*/, 29182 /*Flight of the Storm Crows*/, 26543 /*Clammy Hands*/, 29279 /*Filling the Moonwell*/, 29283 /*Calling the Ancients*/, 29246 /*Relieving the Pain*/, 26572 /*A Golden Opportunity*/, 27254 /*The Black Shield*/, 193 /*Panther Mastery*/, 26556 /*No Dumping Allowed*/, 13503 /*A Tisket, a Tasket, a Noblegarden Basket*/, 29254 /*Little Lasher*/, 29249 /*Planting Season*/, 29245 /*The Mysterious Seed*/, 13483 /*Spring Gatherers*/, 11996 /*Your Presence is Required at Agmar's Hammer*/, 11930 /*Across Transborea*/, 11892 /*The Assassination of Harold Lane*/, 12117 /*Travel to Moa'ki Harbor*/, 11872 /*The Nefarious Clam Master...*/, 11871 /*Not On Our Watch*/, 11870 /*The Abandoned Reach*/, 11879 /*Kaw the Mammoth Destroyer*/, 11878 /*Khu'nok Will Know*/, 11868 /*The Culler Cometh*/, 11884 /*Nedar, Lord of Rhinos...*/, 11865 /*Unfit for Death*/, 11869 /*Happy as a Clam*/, 11876 /*Help Those That Cannot Help Themselves*/, 11866 /*Ears of Our Enemies*/, 11916 /*Hellscream's Champion*/, 11722 /*Trophies of Gammoth*/, 11724 /*Massive Moth Omelet?*/, 11721 /*Gammothra the Tormentor*/, 11720 /*The Invasion of Gammoth*/, 11719 /*A Suitable Test Subject*/, 11717 /*Pollen from the Source*/, 11716 /*The Wondrous Bloodspore*/, 11714 /*Vermin Extermination*/, 11711 /*Coward Delivery... Under 30 Minutes or it's Free*/, 13090 /*Northern Cooking*/, 29215 /*The Hunt Begins*/, 27912 /*The Titans' Trove*/, 29357 /*Spice Bread Aplenty*/, 27793 /*Ancient Protectors*/, 27693 /*The Warden's Game*/, 27709 /*The Sentinel's Game*/, 27797 /*The Sentinel's Pawn*/, 27796 /*The Warden's Pawn*/, 27823 /*A Dwarf's Got Needs*/, 27792 /*All's Fair in Love, War, and Archaeology*/, 27791 /*Dustwind Dig*/, 27789 /*Troggish Troubles*/, 27772 /*The Venerable Doctor Blam*/, 27769 /*Rhea Revealed*/, 27771 /*Third Sample: Implanted Eggs*/, 27770 /*Lifting the Veil*/, 27766 /*Second Sample: Whelps*/, 27765 /*First Sample: Wild Eggs*/, 27764 /*A Strange Request*/, 27776 /*It's Goat Time, Baby*/, 27775 /*When the Going Gets Tough, Cheat*/, 27774 /*Easily Swayed*/, 26451 /*Gurubashi Challenge: Free-For-All Arena Combat*/, 28869 /*Pebble*/, 13647 /*Joining the Hunt*/, 26961 /*Gathering Idols*/, 13650 /*Keep Your Hands Off The Goods!*/, 309 /*Protecting the Shipment*/, 27790 /*The Defias Kingpin*/, 27785 /*The Admiral*/, 27781 /*The Machination*/, 27758 /*The Carpenter*/, 27756 /*The Foreman*/, 13639 /*Resupplying the Excavation*/, 13656 /*Explorers' League Document (1 of 6)*/, 26868 /*Axis of Awful*/, 13655 /*Explorers' League Document (2 of 6)*/, 26929 /*A Load of Croc*/, 26928 /*Smells Like A Plan*/, 26927 /*Suddenly, Murlocs!*/, 26864 /*The Bearer of Gnoll-edge*/, 26846 /*A Nasty Exploit*/, 26863 /*Filthy Paws*/, 26845 /*Who's In Charge Here?*/, 26844 /*Kobold and Kobolder*/, 25118 /*Looking for Lurkers*/, 26843 /*A Tiny, Clever Commander*/, 13648 /*WANTED: The Dark Iron Spy*/, 26860 /*Thelsamar Blood Sausages*/, 26842 /*Out of Gnoll-where*/, 7383 /*Teldrassil: The Burden of the Kaldorei*/, 922 /*Rellian Greenspyre*/, 918 /*Timberling Seeds*/, 919 /*Timberling Sprouts*/, 28718 /*Where There's Smoke, There's Delicious Meat*/, 28710 /*Spray it One More Time*/, 28707 /*Spray it Again*/, 28706 /*Spray it Forward*/, 28703 /*Step Into My Barrow*/, 28701 /*Out of Harm's Way*/, 28676 /*Exterminators at Work*/, 28674 /*Starfall Village*/, 28847 /*The Pursuit of Umbranse*/, 28628 /*Ice Delivery*/, 28722 /*Yetiphobia*/, 28630 /*Echo Three*/, 28629 /*Are We There, Yeti?*/, 28631 /*The Perfect Horns*/, 28857 /*Blasted Lands: The Other Side of the World*/, 28856 /*The Sands of Silithus*/, 28632 /*Fresh From The Hills*/, 28627 /*Seril's Boast*/, 28626 /*Tree Delivery*/, 28625 /*Chop Chop*/, 28624 /*Kilram's Boast*/, 28618 /*Boulder Delivery*/, 26006 /*A Breath of Fresh Air*/, 25951 /*Final Judgment*/, 25860 /*At All Costs*/, 25629 /*Her Lady's Hand*/, 25896 /*Devout Assembly*/, 26135 /*Visions of the Past: Rise from the Deep*/, 25973 /*Welcome News*/, 25972 /*Honor and Privilege*/, 25971 /*Unfurling Plan*/, 25969 /*Hostile Waters*/, 25970 /*Come Prepared*/, 29457 /*The Enemy's Insignia*/, 29510 /*Putting Trash to Good Use*/, 29509 /*Putting the Crunch in the Frog*/, 28540 /*Doin' De E'ko Magic*/, 28464 /*Falling to Corruption*/, 28656 /*Strange Life Forces*/, 28386 /*Borrowed Bombs*/, 28385 /*Oil and Irony*/, 28337 /*The Shredders of Irontree*/, 28384 /*Into the Clearing*/, 28383 /*Wisps of the Woods*/, 28382 /*Enemy at our Roots*/, 28381 /*The Denmother*/, 28264 /*Navarax's Gambit*/, 28261 /*Deceivers In Our Midst*/, 28257 /*The Fall of Tichondrius*/, 28256 /*The Skull of Gul'dan*/, 28218 /*A Destiny of Flame and Sorrow*/, 28228 /*Rejoining the Forest*/, 28224 /*The Last Protector*/, 28221 /*These Roots Were Made For Stompin'*/, 28222 /*Singin' in the Sun*/, 28219 /*Buzzers for Baby*/, 28220 /*Seeking Soil*/, 28214 /*Cleanup at Bloodvenom Post*/, 28213 /*Hazzard Disposal*/, 28208 /*Winna's Kitten*/, 27352 /*Liquid Gold*/, 28190 /*The Tainted Ooze*/, 28207 /*A Slimy Situation*/, 24608 /*Mangletooth*/, 24603 /*Don't Stop Bereavin'*/, 25292 /*Next of Kin*/, 24747 /*Sabotage!*/, 24685 /*Dwarf Fortress*/, 24621 /*Smarts-is-Smarts*/, 24632 /*Tauren Vengeance*/, 24637 /*The Butcher of Taurajo*/, 24667 /*Firestone Point*/, 24620 /*Hearts-is-Hearts*/, 24618 /*Claim the Battle Scar*/, 24634 /*Intelligence Warfare*/, 24619 /*Parts-is-Parts*/, 24591 /*Changing of the Gar'dul*/, 24654 /*Silithissues*/, 24577 /*Desolation Hold Inspection*/, 24573 /*Honoring the Dead*/, 24572 /*Taking Back Taurajo*/, 24569 /*Siegebreaker*/, 24546 /*A Line in the Dirt*/, 24552 /*Lion's Pride*/, 24807 /*Winnoa Pineforest*/, 24601 /*The Nightmare Scar*/, 24574 /*To Harvest Chaos*/, 24566 /*Sowing a Solution*/, 24543 /*A Family Divided*/, 24542 /*A Curious Bloom*/, 24534 /*Speaking Their Language*/, 24519 /*Stalling the Survey*/, 24518 /*The Low Road*/, 24514 /*Raptor Scraps*/, 24515 /*Signals in the Sky*/, 24513 /*Eye for an Eye*/, 24512 /*Warriors' Redemption*/, 25284 /*Feeding the Fear*/, 24505 /*Holdout at Hunter's Hill*/, 24504 /*Clear the High Road*/, 28647 /*The Durnholde Challenge: D-1000*/, 28646 /*The Durnholde Challenge: Infernus*/, 28645 /*The Durnholde Challenge: Bloodvenom*/, 28644 /*The Durnholde Challenge: Teracula*/, 28636 /*Silence of the Dwarves*/, 28634 /*Extinction*/, 28643 /*The Durnholde Challenge: Zephyrus*/, 28635 /*A Haunting in Hillsbrad*/, 26034 /*The Twilight Destroyer*/, 8317 /*Kitchen Assistance*/, 8313 /*Sharing the Knowledge*/, 8307 /*Desert Recipe*/, 28753 /*Doing it the Hard Way*/, 28746 /*Penetrating Their Defenses*/, 29175 /*Break Their Spirits*/, 24585 /*Flame Leviathan Must Die!*/, 11009 /*Ogre Heaven*/, 11000 /*Into the Soulgrinder*/, 10998 /*Grim(oire) Business*/, 11091 /*A Special Thank You*/, 11080 /*The Relic's Emanation*/, 11058 /*An Apexis Relic*/, 10997 /*Even Gronn Have Standards*/, 10996 /*Maggoc's Treasure Chest*/, 10995 /*Grulloc Has Two Skulls*/, 24653 /*Echoes of Agamaggan*/, 24606 /*Blood of the Barrens*/, 29219 /*Bwemba's Spirit*/, 24799 /*A Victory For The Sunreavers*/, 24598 /*The Purification of Quel'Delar*/, 24563 /*Thalorien Dawnseeker*/, 25816 /*Cursed to Roam*/, 25815 /*The Third Fleet*/, 25800 /*When Life Gives You Crabs*/, 25820 /*A Mother's Worries*/, 25780 /*Assault on Menethil Keep*/, 25777 /*Onwards to Menethil*/, 25736 /*The Floodsurge Core*/, 25733 /*Get Out Of Here, Stalkers*/, 25735 /*Incendicite Ore*/, 25734 /*Down In Thelgen Rock*/, 25726 /*A Dumpy Job*/, 25727 /*Drungeld Glowerglare*/, 25725 /*Fenbush Berries*/, 8277 /*Deadly Desert Venom*/, 8280 /*Securing the Supply Lines*/, 8320 /*Twilight Geolords*/, 8318 /*Secret Communication*/, 9415 /*Report to Marshal Bluewall*/, 28639 /*Ursius*/, 28782 /*A Bird of Legend*/, 28742 /*Shy-Rotam*/, 28641 /*Pride of the Dinner Table*/, 28745 /*Screechy Keen*/, 28719 /*A Little Gamy*/, 28842 /*Umbranse's Deliverance*/, 28841 /*The Arcane Storm Within*/, 28831 /*Damn You, Frostilicus*/, 28830 /*Chips off the Old Block*/, 28840 /*Winterwater*/, 28829 /*Razor Beak and Antlers Pointy*/, 28839 /*Magic Prehistoric*/, 28838 /*The Owlbeasts' Defense*/, 28837 /*Altered Beasts*/, 24561 /*The Halls Of Reflection*/, 24560 /*Tempering The Blade*/, 24559 /*Reforging The Sword*/, 24558 /*Return To Myralion Sunblaze*/, 24451 /*An Audience With The Arcanist*/, 24556 /*A Suitable Disguise*/, 24557 /*The Silver Covenant's Scheme*/, 24562 /*Journey To The Sunwell*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13413, 396, 396, 0, 0, 0, 0, 0, 0, 15354), -- Aces High!
(9829, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Khadgar
(9826, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Contact from Dalaran
(9825, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Restless Activity
(9824, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Arcane Disturbances
(14388, 6, 1, 0, 0, 0, 0, 0, 0, 15354), -- Azsharite Experiment Number Two
(14383, 388, 5, 0, 0, 0, 0, 0, 0, 15354), -- The Terrible Tinkers of the Ruined Reaches
(14385, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Azsharite Experiment Number One
(14377, 396, 5, 0, 0, 0, 0, 0, 0, 15354), -- Befriending Giants
(14371, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- A Gigantic Snack
(14370, 5, 6, 0, 0, 0, 0, 0, 0, 15354), -- Mysterious Azsharite
(14310, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Segmentation Fault: Core Dumped
(14322, 5, 0, 0, 0, 0, 0, 0, 0, 15354), -- Bad Science! Bad!
(14308, 5, 15, 0, 0, 0, 0, 0, 0, 15354), -- When Science Attacks
(25723, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Thresh Out of Luck
(25722, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Sedimentary, My Dear
(25721, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Fight the Flood
(27026, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Defcon: Bobcat
(27032, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Bird is the Word
(27356, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Circle's Future
(27016, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Joy of Boar Hunting
(27028, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Hornet Hunting
(27030, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Foxtails By The Handful
(27025, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Thistle While You Work
(25383, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Ysondre's Farewell
(25379, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Taerar's Fall
(25369, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Stinglasher
(25367, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Zukk'ash Infestation
(9175, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Lady's Necklace
(28356, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Preemptive Strike
(26588, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- A Furious Catch
(6608, 1, 1, 1, 5, 0, 0, 0, 0, 15354), -- You Too Good.
(24431, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Waterlogged Recipe
(26079, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Wanted!  Otto and Falconcrest
(26943, 1, 11, 1, 5, 0, 0, 0, 0, 15354), -- Home Sweet Gnome
(26336, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Shakes O'Breen
(26024, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Wanted!  Marez Cowl
(26113, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Quae and Kinelory
(26093, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Northfold Manor
(26035, 1, 1, 6, 0, 0, 0, 0, 0, 15354), -- Worth Its Weight in Gold
(8168, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Battle for Arathi Basin!
(25805, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Return the Statuette
(26882, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Blackfathom Villainy
(25804, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Search More Hovels
(25803, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Search Continues
(25801, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Claws from the Deep
(25802, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Reclaiming Goods
(28237, 1, 1, 25, 0, 0, 0, 0, 0, 15354), -- A Blight Upon the Land
(28235, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Burnside Must Fall
(28231, 396, 396, 396, 15, 0, 0, 0, 0, 15354), -- Do it for Twinkles
(28230, 1, 1, 5, 0, 0, 0, 0, 0, 15354), -- Protocol
(28209, 5, 1, 5, 0, 0, 0, 0, 0, 15354), -- Freedom for Lydon
(28206, 1, 1, 1, 20, 0, 0, 0, 0, 15354), -- Little Girl Lost
(28196, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Battle for Hillsbrad
(28189, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Do the Right Thing
(28199, 1, 1, 11, 11, 0, 0, 0, 0, 15354), -- For Science!
(28197, 5, 6, 1, 25, 0, 0, 0, 0, 15354), -- Discretion is Key
(28192, 1, 6, 274, 5, 0, 0, 0, 0, 15354), -- No One Here Gets Out Alive
(28168, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Trouble at the Sludge Fields
(28156, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Deep Mine Rescue
(28138, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Human Infestation
(28144, 1, 1, 5, 0, 0, 0, 0, 0, 15354), -- Thieving Little Monsters!
(28146, 1, 1, 5, 0, 0, 0, 0, 0, 15354), -- Coastal Delicacies!
(28115, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Past Their Prime
(28114, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Glorious Harvest
(28111, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Trouble at Azurelode
(28096, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Welcome to the Machine
(28331, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Helcular's Rod Giveth...
(28332, 1, 1, 1, 5, 0, 0, 0, 0, 15354), -- Helcular's Command
(28325, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Green Living
(28324, 1, 273, 1, 1, 0, 0, 0, 0, 15354), -- Studies in Lethality
(28620, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Eastpoint Tower
(28619, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Warchief's Command: Arathi Highlands!
(28495, 5, 1, 1, 0, 0, 0, 0, 0, 15354), -- A Fighting Chance
(28487, 24, 1, 6, 273, 0, 0, 0, 0, 15354), -- Humbert's Personal Problems
(28485, 1, 1, 5, 1, 0, 0, 0, 0, 15354), -- Yetimus the Yeti Lord
(28484, 274, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Heart of the Matter
(28489, 6, 274, 1, 273, 0, 0, 0, 0, 15354), -- Stagwiches
(29316, 396, 396, 396, 0, 0, 0, 0, 0, 15354), -- Back to Basics
(29321, 396, 396, 0, 0, 0, 0, 0, 0, 15354), -- Happy as a Clam Digger
(26488, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Big Gulp
(8314, 5, 1, 1, 1, 0, 0, 0, 0, 15354), -- Unraveling the Mystery
(8306, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Into The Maw of Madness
(8285, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Deserter
(8284, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Twilight Mystery
(9419, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Scouring the Desert
(8278, 274, 6, 0, 0, 0, 1000, 0, 0, 15354), -- Noggle's Last Hope
(8281, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Stepping Up Security
(26557, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- A Staggering Effort
(29247, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Treating the Wounds
(28637, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Taste for Bear
(28638, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Owls Have It
(28828, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- You Gotta Have Eggs
(28640, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Fresh Frostsabers
(28610, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Rubble Trouble
(28609, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Hammer Time
(28848, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Trailing the Spiritspeaker
(28537, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- In Pursuit of Shades
(28536, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Curse of Zin-Malor
(28519, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pain of the Blood Elves
(28535, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Descendants of the High Elves
(28518, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Legacy of the High Elves
(28534, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Descendants of the Highborne
(28513, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pride of the Highborne
(28479, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Ruins of Kel'Theril
(28472, 1, 2, 0, 0, 0, 0, 0, 0, 15354), -- Words of the High Chief
(28471, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Final Piece
(28470, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- High Chief Winterfall
(28530, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Scalding Signs
(28469, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Winterfall Runners
(28467, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Mystery Goo
(29345, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pond Predators
(29363, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- Mulgore Spice Bread
(26012, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Trouble at Wyrmrest
(29354, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- Shiny Baubles
(29358, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pining for Nuts
(29346, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Ring's the Thing
(29362, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- "Magic" Mushrooms
(13832, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Jewel Of The Sewers
(13479, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Great Egg Hunt
(29272, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Need... Water... Badly...
(29182, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Flight of the Storm Crows
(26543, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Clammy Hands
(29279, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Filling the Moonwell
(29283, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Calling the Ancients
(29246, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Relieving the Pain
(26572, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- A Golden Opportunity
(27254, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Black Shield
(193, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Panther Mastery
(26556, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- No Dumping Allowed
(13503, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Tisket, a Tasket, a Noblegarden Basket
(29254, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Little Lasher
(29249, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Planting Season
(29245, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Mysterious Seed
(13483, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Spring Gatherers
(11996, 1, 66, 0, 0, 0, 0, 0, 0, 15354), -- Your Presence is Required at Agmar's Hammer
(11930, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Across Transborea
(11892, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Assassination of Harold Lane
(12117, 15, 6, 1, 0, 0, 0, 0, 0, 15354), -- Travel to Moa'ki Harbor
(11872, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Nefarious Clam Master...
(11871, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Not On Our Watch
(11870, 1, 1, 5, 0, 0, 0, 0, 0, 15354), -- The Abandoned Reach
(11879, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Kaw the Mammoth Destroyer
(11878, 1, 1, 1, 2, 0, 0, 0, 0, 15354), -- Khu'nok Will Know
(11868, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Culler Cometh
(11884, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Nedar, Lord of Rhinos...
(11865, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Unfit for Death
(11869, 1, 1, 1, 5, 0, 0, 0, 0, 15354), -- Happy as a Clam
(11876, 1, 1, 1, 5, 0, 0, 0, 0, 15354), -- Help Those That Cannot Help Themselves
(11866, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Ears of Our Enemies
(11916, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Hellscream's Champion
(11722, 1, 1, 2, 0, 0, 0, 0, 0, 15354), -- Trophies of Gammoth
(11724, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Massive Moth Omelet?
(11721, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Gammothra the Tormentor
(11720, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Invasion of Gammoth
(11719, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- A Suitable Test Subject
(11717, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Pollen from the Source
(11716, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Wondrous Bloodspore
(11714, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Vermin Extermination
(11711, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- Coward Delivery... Under 30 Minutes or it's Free
(13090, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Northern Cooking
(29215, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Hunt Begins
(27912, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Titans' Trove
(29357, 396, 396, 396, 396, 0, 0, 0, 0, 15354), -- Spice Bread Aplenty
(27793, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Ancient Protectors
(27693, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Warden's Game
(27709, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Sentinel's Game
(27797, 1, 6, 0, 0, 0, 0, 0, 0, 15354), -- The Sentinel's Pawn
(27796, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Warden's Pawn
(27823, 1, 1, 6, 0, 0, 0, 0, 0, 15354), -- A Dwarf's Got Needs
(27792, 1, 5, 1, 0, 0, 0, 0, 0, 15354), -- All's Fair in Love, War, and Archaeology
(27791, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Dustwind Dig
(27789, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Troggish Troubles
(27772, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Venerable Doctor Blam
(27769, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Rhea Revealed
(27771, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Third Sample: Implanted Eggs
(27770, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Lifting the Veil
(27766, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Second Sample: Whelps
(27765, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- First Sample: Wild Eggs
(27764, 1, 1, 6, 0, 0, 0, 0, 0, 15354), -- A Strange Request
(27776, 5, 1, 1, 0, 0, 0, 0, 0, 15354), -- It's Goat Time, Baby
(27775, 5, 1, 1, 0, 0, 0, 0, 0, 15354), -- When the Going Gets Tough, Cheat
(27774, 1, 1, 5, 0, 0, 0, 0, 0, 15354), -- Easily Swayed
(26451, 396, 396, 66, 0, 0, 0, 0, 0, 15354), -- Gurubashi Challenge: Free-For-All Arena Combat
(28869, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pebble
(13647, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Joining the Hunt
(26961, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Gathering Idols
(13650, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Keep Your Hands Off The Goods!
(309, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Protecting the Shipment
(27790, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Defias Kingpin
(27785, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Admiral
(27781, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Machination
(27758, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Carpenter
(27756, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Foreman
(13639, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Resupplying the Excavation
(13656, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Explorers' League Document (1 of 6)
(26868, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Axis of Awful
(13655, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Explorers' League Document (2 of 6)
(26929, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Load of Croc
(26928, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Smells Like A Plan
(26927, 1, 25, 0, 0, 0, 0, 0, 0, 15354), -- Suddenly, Murlocs!
(26864, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Bearer of Gnoll-edge
(26846, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Nasty Exploit
(26863, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Filthy Paws
(26845, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Who's In Charge Here?
(26844, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Kobold and Kobolder
(25118, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Looking for Lurkers
(26843, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Tiny, Clever Commander
(13648, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- WANTED: The Dark Iron Spy
(26860, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Thelsamar Blood Sausages
(26842, 396, 0, 0, 0, 0, 0, 0, 0, 15354), -- Out of Gnoll-where
(7383, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Teldrassil: The Burden of the Kaldorei
(922, 1, 2, 0, 0, 0, 0, 0, 0, 15354), -- Rellian Greenspyre
(918, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Timberling Seeds
(919, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Timberling Sprouts
(28718, 6, 1, 1, 1, 0, 0, 0, 0, 15354), -- Where There's Smoke, There's Delicious Meat
(28710, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Spray it One More Time
(28707, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Spray it Again
(28706, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Spray it Forward
(28703, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Step Into My Barrow
(28701, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Out of Harm's Way
(28676, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Exterminators at Work
(28674, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Starfall Village
(28847, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Pursuit of Umbranse
(28628, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Ice Delivery
(28722, 1, 11, 11, 0, 0, 0, 0, 0, 15354), -- Yetiphobia
(28630, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Echo Three
(28629, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Are We There, Yeti?
(28631, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Perfect Horns
(28857, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Blasted Lands: The Other Side of the World
(28856, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Sands of Silithus
(28632, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Fresh From The Hills
(28627, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Seril's Boast
(28626, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Tree Delivery
(28625, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Chop Chop
(28624, 5, 0, 0, 0, 0, 0, 0, 0, 15354), -- Kilram's Boast
(28618, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Boulder Delivery
(26006, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Breath of Fresh Air
(25951, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Final Judgment
(25860, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- At All Costs
(25629, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Her Lady's Hand
(25896, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Devout Assembly
(26135, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Visions of the Past: Rise from the Deep
(25973, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Welcome News
(25972, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Honor and Privilege
(25971, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Unfurling Plan
(25969, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Hostile Waters
(25970, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Come Prepared
(29457, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Enemy's Insignia
(29510, 1, 1, 1, 0, 0, 0, 0, 0, 15354); -- Putting Trash to Good Use

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29509, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Putting the Crunch in the Frog
(28540, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Doin' De E'ko Magic
(28464, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Falling to Corruption
(28656, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Strange Life Forces
(28386, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Borrowed Bombs
(28385, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Oil and Irony
(28337, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Shredders of Irontree
(28384, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Into the Clearing
(28383, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Wisps of the Woods
(28382, 274, 0, 0, 0, 0, 0, 0, 0, 15354), -- Enemy at our Roots
(28381, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Denmother
(28264, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Navarax's Gambit
(28261, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Deceivers In Our Midst
(28257, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Fall of Tichondrius
(28256, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Skull of Gul'dan
(28218, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Destiny of Flame and Sorrow
(28228, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Rejoining the Forest
(28224, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Last Protector
(28221, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- These Roots Were Made For Stompin'
(28222, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Singin' in the Sun
(28219, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Buzzers for Baby
(28220, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Seeking Soil
(28214, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Cleanup at Bloodvenom Post
(28213, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Hazzard Disposal
(28208, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Winna's Kitten
(27352, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Liquid Gold
(28190, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Tainted Ooze
(28207, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Slimy Situation
(24608, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Mangletooth
(24603, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Don't Stop Bereavin'
(25292, 1, 274, 0, 0, 0, 0, 0, 0, 15354), -- Next of Kin
(24747, 11, 1, 273, 0, 0, 0, 0, 0, 15354), -- Sabotage!
(24685, 5, 1, 0, 0, 0, 0, 0, 0, 15354), -- Dwarf Fortress
(24621, 5, 1, 0, 0, 0, 0, 0, 0, 15354), -- Smarts-is-Smarts
(24632, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- Tauren Vengeance
(24637, 5, 15, 0, 0, 0, 0, 0, 0, 15354), -- The Butcher of Taurajo
(24667, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- Firestone Point
(24620, 11, 1, 0, 0, 0, 0, 0, 0, 15354), -- Hearts-is-Hearts
(24618, 25, 5, 0, 0, 0, 0, 0, 0, 15354), -- Claim the Battle Scar
(24634, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- Intelligence Warfare
(24619, 6, 1, 0, 0, 0, 0, 0, 0, 15354), -- Parts-is-Parts
(24591, 274, 1, 0, 0, 0, 0, 0, 0, 15354), -- Changing of the Gar'dul
(24654, 5, 274, 1, 0, 0, 0, 0, 0, 15354), -- Silithissues
(24577, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Desolation Hold Inspection
(24573, 1, 274, 0, 0, 0, 0, 0, 0, 15354), -- Honoring the Dead
(24572, 1, 15, 25, 0, 0, 0, 0, 0, 15354), -- Taking Back Taurajo
(24569, 273, 1, 66, 0, 0, 0, 0, 0, 15354), -- Siegebreaker
(24546, 5, 1, 25, 0, 0, 0, 0, 0, 15354), -- A Line in the Dirt
(24552, 1, 6, 0, 0, 0, 0, 0, 0, 15354), -- Lion's Pride
(24807, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Winnoa Pineforest
(24601, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Nightmare Scar
(24574, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- To Harvest Chaos
(24566, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Sowing a Solution
(24543, 1, 5, 0, 0, 0, 0, 0, 0, 15354), -- A Family Divided
(24542, 1, 5, 273, 0, 0, 0, 0, 0, 15354), -- A Curious Bloom
(24534, 1, 25, 5, 0, 0, 0, 0, 0, 15354), -- Speaking Their Language
(24519, 6, 1, 0, 0, 0, 0, 0, 0, 15354), -- Stalling the Survey
(24518, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Low Road
(24514, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- Raptor Scraps
(24515, 1, 6, 0, 0, 0, 0, 0, 0, 15354), -- Signals in the Sky
(24513, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Eye for an Eye
(24512, 25, 1, 274, 0, 0, 0, 0, 0, 15354), -- Warriors' Redemption
(25284, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- Feeding the Fear
(24505, 1, 273, 0, 0, 0, 0, 0, 0, 15354), -- Holdout at Hunter's Hill
(24504, 1, 66, 0, 0, 0, 0, 0, 0, 15354), -- Clear the High Road
(28647, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Durnholde Challenge: D-1000
(28646, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Durnholde Challenge: Infernus
(28645, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Durnholde Challenge: Bloodvenom
(28644, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Durnholde Challenge: Teracula
(28636, 1, 274, 1, 273, 0, 0, 0, 0, 15354), -- Silence of the Dwarves
(28634, 1, 1, 273, 5, 0, 0, 0, 0, 15354), -- Extinction
(28643, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Durnholde Challenge: Zephyrus
(28635, 1, 1, 6, 0, 0, 0, 0, 0, 15354), -- A Haunting in Hillsbrad
(26034, 5, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Twilight Destroyer
(8317, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Kitchen Assistance
(8313, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Sharing the Knowledge
(8307, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Desert Recipe
(28753, 396, 396, 396, 0, 0, 500, 500, 0, 15354), -- Doing it the Hard Way
(28746, 396, 396, 0, 0, 0, 1000, 0, 0, 15354), -- Penetrating Their Defenses
(29175, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Break Their Spirits
(24585, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Flame Leviathan Must Die!
(11009, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Ogre Heaven
(11000, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Into the Soulgrinder
(10998, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Grim(oire) Business
(11091, 2, 1, 1, 0, 0, 0, 0, 0, 15354), -- A Special Thank You
(11080, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Relic's Emanation
(11058, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- An Apexis Relic
(10997, 6, 1, 1, 0, 0, 0, 0, 0, 15354), -- Even Gronn Have Standards
(10996, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Maggoc's Treasure Chest
(10995, 1, 6, 1, 0, 0, 0, 0, 0, 15354), -- Grulloc Has Two Skulls
(24653, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Echoes of Agamaggan
(24606, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Blood of the Barrens
(29219, 6, 396, 396, 0, 0, 300, 300, 0, 15354), -- Bwemba's Spirit
(24799, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- A Victory For The Sunreavers
(24598, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- The Purification of Quel'Delar
(24563, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Thalorien Dawnseeker
(25816, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Cursed to Roam
(25815, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Third Fleet
(25800, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- When Life Gives You Crabs
(25820, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Mother's Worries
(25780, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Assault on Menethil Keep
(25777, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Onwards to Menethil
(25736, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- The Floodsurge Core
(25733, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Get Out Of Here, Stalkers
(25735, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Incendicite Ore
(25734, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Down In Thelgen Rock
(25726, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Dumpy Job
(25727, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Drungeld Glowerglare
(25725, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Fenbush Berries
(8277, 20, 6, 0, 0, 0, 1000, 0, 0, 15354), -- Deadly Desert Venom
(8280, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Securing the Supply Lines
(8320, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Twilight Geolords
(8318, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Secret Communication
(9415, 1, 11, 0, 0, 0, 0, 0, 0, 15354), -- Report to Marshal Bluewall
(28639, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Ursius
(28782, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Bird of Legend
(28742, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Shy-Rotam
(28641, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Pride of the Dinner Table
(28745, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- Screechy Keen
(28719, 1, 0, 0, 0, 0, 0, 0, 0, 15354), -- A Little Gamy
(28842, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Umbranse's Deliverance
(28841, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Arcane Storm Within
(28831, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Damn You, Frostilicus
(28830, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Chips off the Old Block
(28840, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Winterwater
(28829, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Razor Beak and Antlers Pointy
(28839, 0, 0, 0, 0, 0, 0, 0, 0, 15354), -- Magic Prehistoric
(28838, 1, 1, 1, 1, 0, 0, 0, 0, 15354), -- The Owlbeasts' Defense
(28837, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Altered Beasts
(24561, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Halls Of Reflection
(24560, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Tempering The Blade
(24559, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- Reforging The Sword
(24558, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- Return To Myralion Sunblaze
(24451, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- An Audience With The Arcanist
(24556, 1, 1, 0, 0, 0, 0, 0, 0, 15354), -- A Suitable Disguise
(24557, 1, 1, 1, 0, 0, 0, 0, 0, 15354), -- The Silver Covenant's Scheme
(24562, 1, 1, 1, 0, 0, 0, 0, 0, 15354); -- Journey To The Sunwell

UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=264; -- Until Death Do Us Part
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=7848; -- Attunement to the Core
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=8282; -- Noggle's Lost Satchel
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=8283; -- Wanted - Deathclasp, Terror of the Sands
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=11949; -- Not Without a Fight!
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=11961; -- Spirits Watch Over Us
UPDATE `quest_details` SET `Emote1`=0, `VerifiedBuild`=15354 WHERE `ID`=11968; -- The Tides Turn
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=9967; -- The Ring of Blood: The Blue Brothers
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=6, `VerifiedBuild`=15354 WHERE `ID`=8304; -- Dearest Natalia
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=15, `VerifiedBuild`=15354 WHERE `ID`=12801; -- The Light of Dawn
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=9970; -- The Ring of Blood: Rokdar the Sundered Lord
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=9972; -- The Ring of Blood: Skra'gath
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=9977; -- The Ring of Blood: The Final Challenge
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11610; -- Leading the Ancestors Home
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=13165; -- Taking Back Acherus
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=6, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=9973; -- The Ring of Blood: The Warmaul Champion
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=8321; -- Vyral the Vile
UPDATE `quest_details` SET `Emote1`=1, `VerifiedBuild`=15354 WHERE `ID`=11950; -- Muahit's Wisdom
UPDATE `quest_details` SET `Emote1`=3, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11119; -- Assault on Bash'ir Landing!
UPDATE `quest_details` SET `Emote1`=3, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=11065; -- Wrangle Some Aether Rays!
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=1, `VerifiedBuild`=15354 WHERE `ID`=9962; -- The Ring of Blood: Brokentoe
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `VerifiedBuild`=15354 WHERE `ID`=11062; -- The Skyguard Outpost
UPDATE `quest_details` SET `Emote1`=25, `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=11010; -- Bombing Run
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `Emote4`=397, `VerifiedBuild`=15354 WHERE `ID`=12800; -- The Lich King's Command
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11030; -- Our Boy Wants To Be A Skyguard Ranger
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11059; -- Guardian of the Monument
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11061; -- A Father's Duty
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11078; -- To Rule The Skies
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `VerifiedBuild`=15354 WHERE `ID`=11079; -- A Fel Whip For Gahk
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=11023; -- Bomb Them Again!
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=6, `VerifiedBuild`=15354 WHERE `ID`=11066; -- Wrangle More Aether Rays!
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=840; -- Conscript of the Horde
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=937; -- The Enchanted Glade
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=997; -- Denalan's Earth
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=2518; -- Tears of the Moon
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10055; -- Waste Not, Want Not
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10140; -- Journey to Honor Hold
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10141; -- The Legion Reborn
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10142; -- The Path of Anguish
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10143; -- Expedition Point
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10146; -- Mission: The Murketh and Shaadraz Gateways
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10160; -- Know your Enemy
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10254; -- Force Commander Danath
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10288; -- Arrival in Outland
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10340; -- Shatter Point
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10482; -- Fel Orc Scavengers
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=10895; -- Zeth'Gor Must Burn!
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=11056; -- Hazzik's Bargain
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=11958; -- Let Nothing Go To Waste
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=12082; -- Dun-da-Dun-tah!
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=12995; -- Leave Our Mark
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=13069; -- Shoot 'Em Up
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=13071; -- Vile Like Fire!
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=13830; -- The Ghostfish
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=13834; -- Dangerously Delicious
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14078; -- Lockdown!
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14091; -- Something's Amiss
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14093; -- All Hell Breaks Loose
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14094; -- Salvage the Supplies
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14098; -- Evacuate the Merchant Square
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14099; -- Royal Orders
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14154; -- By the Skin of His Teeth
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14157; -- Old Divisions
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14159; -- The Rebel Lord's Arsenal
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14204; -- From the Shadows
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14212; -- Sacrifices
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14214; -- Message to Greymane
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14218; -- By Blood and Ash
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14221; -- Never Surrender, Sometimes Retreat
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14293; -- Save Krennan Aranas
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=14294; -- Time to Regroup
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=24930; -- While You're At It
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26129; -- Brothers In Arms
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26312; -- Crumbling Defenses
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26313; -- Core of Our Troubles
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26314; -- On Even Ground
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26315; -- Imposing Confrontation
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26326; -- The Very Earth Beneath Our Feet
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26328; -- Rocky Relations
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26375; -- Loose Stones
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26376; -- Hatred Runs Deep
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26377; -- Unsolid Ground
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26426; -- Violent Gale
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26436; -- Entrenched
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26437; -- Making Things Crystal Clear
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26438; -- Intervention
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26439; -- Putting the Pieces Together
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26440; -- Clingy
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26441; -- So Big, So Round...
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26507; -- Petrified Delicacies
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26575; -- Rock Bottom
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26576; -- Steady Hand
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26577; -- Rocky Upheaval
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26656; -- Don't. Stop. Moving.
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26657; -- Hard Falls
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26658; -- Fragile Values
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26659; -- Resonating Blow
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26836; -- Rescue the Stonefather... and Flint
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26869; -- Depth of the Depths
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=26871; -- A Rock Amongst Many
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=27004; -- The Twilight Plot
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=27937; -- The Hero Returns
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=27938; -- The Middle Fragment
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=27952; -- The Explorers
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=28824; -- Wayward Child
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=28850; -- The Prison Rooftop
UPDATE `quest_details` SET `VerifiedBuild`=15354 WHERE `ID`=29123; -- Rage Against the Flames

DELETE FROM `quest_details` WHERE `ID` IN (26380 /*Bound for Kharanos*/, 24469 /*Hold the Line!*/, 1654 /*The Test of Righteousness*/, 25932 /*It's Raid Night Every Night*/, 433 /*The Public Servant*/, 25937 /*Priceless Treasures*/, 26131 /*Reinforcements for Loch Modan*/, 29355 /*Can't Get Enough Spice Bread*/, 4512 /*A Little Slime Goes a Long Way*/, 29347 /*Live Bait*/, 13425 /*The Aberrations Must Die*/, 14145 /*What Do You Feed a Yeti, Anyway?*/, 14136 /*Rescue at Sea*/, 14142 /*You've Really Done It This Time, Kul*/, 13811 /*Among the Champions*/, 13862 /*Battle Before The Citadel*/, 13809 /*Threat From Above*/, 13810 /*Taking Battle To The Enemy*/, 14107 /*The Fate Of The Fallen*/, 14104 /*Ornolf The Scarred*/, 931 /*The Shimmering Frond*/, 938 /*Mist*/, 941 /*Planting the Heart*/, 26383 /*Breaking Waves of Change*/, 6343 /*Return to Nyoma*/, 6342 /*An Unexpected Gift*/, 487 /*The Road to Darnassus*/, 486 /*Ursal the Mauler*/, 13946 /*Nature's Reprisal*/, 932 /*Twisted Hatred*/, 2459 /*Ferocitas the Dream Eater*/, 13945 /*Resident Danger*/, 483 /*The Relics of Wakening*/, 930 /*The Glowing Fruit*/, 927 /*The Moss-twined Heart*/, 476 /*Gnarlpine Corruption*/, 2438 /*The Emerald Dreamcatcher*/, 6341 /*To Darnassus*/, 489 /*Seek Redemption!*/, 929 /*Teldrassil: The Refusal of the Aspects*/, 6344 /*Reminders of Home*/, 28731 /*Teldrassil: Passing Awareness*/, 28730 /*Precious Waters*/, 28729 /*Teldrassil: Crown of Azeroth*/, 28728 /*Signs of Things to Come*/, 28727 /*Vile Touch*/, 28726 /*Webwood Corruption*/, 28725 /*The Woodland Protector*/, 28724 /*Iverron's Antidote*/, 28723 /*Priestess of the Moon*/, 26948 /*Moonfire*/, 3120 /*Verdant Sigil*/, 28715 /*Demonic Thieves*/, 28714 /*Fel Moss Corruption*/, 28713 /*The Balance of Nature*/, 29445 /*An Intriguing Grimoire*/, 351 /*Find OOX-17/TN!*/, 27071 /*Wrath of the Sandfury*/, 27076 /*Breaking and Entering*/, 27070 /*A Fool's Errand*/, 27068 /*Chief Ukorz Sandscalp*/, 29463 /*It's Hammer Time*/, 29436 /*The Humanoid Cannonball*/, 29438 /*He Shoots, He Scores!*/, 29434 /*Tonk Commander*/, 29455 /*Target: Turtle*/, 29433 /*Test Your Strength*/, 13422 /*Maintaining Discipline*/, 14102 /*Mistcaller Yngvar*/, 27445 /*General Drakkisath, Hand of Nefarian*/, 27444 /*The False Warchief*/, 27440 /*Trolls, Ogres, and Orcs, Oh My!*/, 27596 /*The Heart of the Mountain*/, 29211 /*Solar Core Destruction*/, 29206 /*Into the Fire*/, 29205 /*The Forlorn Spire*/, 29263 /*A Bitter Pill*/, 29138 /*Burn Victims*/, 29141 /*The Harder They Fall*/, 29179 /*Hostile Elements*/, 29139 /*Aggressive Growth*/, 29255 /*Embergris*/, 29162 /*Nature's Blessing*/, 29128 /*The Protectors of Hyjal*/, 29161 /*Those Bears Up There*/, 29163 /*Rage Against the Flames*/, 25275 /*Report to the Labor Captain*/, 25267 /*Message for Saurfang*/, 25266 /*Warchief's Emissary*/, 25265 /*Victory!*/, 25251 /*Final Confrontation*/, 25214 /*Escape Velocity*/, 25244 /*What Kind of Name is Candy, Anyway?*/, 25213 /*The Slave Pits*/, 25207 /*Good-bye, Sweet Oil*/, 25202 /*The Fastest Way to His Heart*/, 25204 /*Release the Valves*/, 25201 /*The Ultimate Footbomb Uniform*/, 25200 /*Shredder Shutdown*/, 25184 /*Wild Mine Cart Ride*/, 25125 /*Light at the End of the Tunnel*/, 25123 /*Throw It On the Ground!*/, 25122 /*Morale Boost*/, 25110 /*Kaja'Cola Gives You IDEAS! (TM)*/, 27024 /*Partners in Crime*/, 27029 /*Cure the Scourge*/, 27009 /*The Coldbringer*/, 27111 /*The Treasure of the Shen'dralar*/, 27110 /*The Madness Within*/, 27113 /*The Shen'dralar Ancient*/, 27112 /*The Cursed Remains*/, 27109 /*The Warped Defender*/, 29443 /*A Curious Crystal*/, 29203 /*Into the Depths*/, 29331 /*Elemental Bonds: The Vow*/, 29330 /*Elemental Bonds: Fury*/, 29338 /*Into Unrelenting Flame*/, 29329 /*Elemental Bonds: Patience*/, 29337 /*Into Constant Earth*/, 29328 /*Elemental Bonds: Desire*/, 29336 /*Into Coaxing Tides*/, 29327 /*Elemental Bonds: Doubt*/, 29335 /*Into Slashing Winds*/, 29326 /*The Nordrassil Summit*/, 28741 /*Ascendant Lord Obsidius*/, 28740 /*Do My Eyes Deceive Me?*/, 28738 /*The Twilight Forge*/, 28737 /*What Is This Place?*/, 28490 /*Hero's Call: Darkshore!*/, 28517 /*The Howling Oak*/, 14291 /*Safety in Numbers*/, 14283 /*Moonfire*/, 14280 /*The Winds Know Your Name... Apparently*/, 29830 /*Containment*/, 29102 /*To Fort Livingston*/, 29100 /*Bwemba's Spirit*/, 25998 /*Get to the Airfield*/, 25997 /*Dark Iron Scheming*/, 25979 /*Dealing with the Surge*/, 25978 /*Entombed in Ice*/, 25986 /*Trouble at the Lake*/, 432 /*Those Blasted Troggs!*/, 25933 /*Help for the Quarry*/, 314 /*Protecting the Herd*/, 25905 /*Rams on the Lam*/, 25882 /*A Hand at the Ranch*/, 28868 /*The View from Down Here*/, 25841 /*Strike From Above*/, 25840 /*Eliminate the Resistance*/, 25839 /*The Ultrasafe Personnel Launcher*/, 25838 /*Help from Steelgrill's Depot*/, 412 /*Operation Recombobulation*/, 25792 /*Pushing Forward*/, 25668 /*Pilfered Supplies*/, 313 /*Forced to Watch from Afar*/, 25667 /*Culling the Wendigos*/, 315 /*The Perfect Stout*/, 25724 /*Frostmane Aggression*/, 384 /*Beer Basted Boar Ribs*/, 6392 /*Return to Gremlock*/, 6388 /*Gryth Thurden*/, 6391 /*Ride to Ironforge*/, 6387 /*Honor Students*/, 24493 /*Don't Forget About Us*/, 24492 /*Pack Your Bags*/, 24491 /*Follow that Gyro-Copter!*/, 24490 /*A Trip to Ironforge*/, 24489 /*Trolling for Information*/, 24487 /*Whitebeard Needs Ye*/, 24530 /*Oh, A Hunter's Life For Me*/, 24475 /*All the Other Stuff*/, 24486 /*Make Hay While the Sun Shines*/, 24477 /*Dwarven Artifacts*/, 24474 /*First Things First: We're Gonna Need Some Beer*/, 24473 /*Lockdown in Anvilmar*/, 24471 /*Aid for the Wounded*/, 24470 /*Give 'em What-For*/, 29861 /*Whatever it Takes!*/, 29860 /*Diametrically Opposed*/, 29862 /*Clearing the Way*/, 27022 /*Extinguishing the Idol*/, 27019 /*Scourge of the Downs*/, 10210 /*A'dal*/, 10134 /*Crimson Crystal Clue*/, 9417 /*The Arakkoa Threat*/, 9325 /*Stealing Thunder Bluff's Flame*/, 9324 /*Stealing Orgrimmar's Flame*/, 29030 /*Honor the Flame*/, 28783 /*The Source of Their Power*/, 28781 /*Targets of Opportunity*/, 11316 /*Spawn of the Twisted Glade*/, 11319 /*Seeds of the Blacksouled Keepers*/, 11418 /*We Call Him Steelfeather*/, 11314 /*The Fallen Sisters*/, 11315 /*Wild Vines*/, 11313 /*Spirits of the Ice*/, 11292 /*Preying Upon the Weak*/, 11269 /*Down to the Wire*/, 11355 /*March of the Giants*/, 11346 /*The Book of Runes*/, 11302 /*The Enigmatic Frost Nymphs*/, 11284 /*The Yeti Next Door*/, 11410 /*The One That Got Away*/, 11329 /*I'll Try Anything!*/, 12118 /*Travel to Moa'ki Harbor*/, 29811 /*The Gatewatcher's Talisman*/, 29808 /*Don't Forget the Eggs!*/, 29807 /*Death to the Traitor King*/, 11237 /*Gjalerbron Attack Plans*/, 11504 /*The Dead Rise!*/, 11573 /*Orfus of Kamagua*/, 11396 /*Bring Down Those Shields*/, 11395 /*It's a Scourge Device*/, 11394 /*And You Thought Murlocs Smelled Bad!*/, 11391 /*Steel Gate Patrol*/, 11390 /*I've Got a Flying Machine!*/, 11322 /*The Cleansing*/, 11154 /*Scare the Guano Out of Them!*/, 11176 /*See to the Operations*/, 11393 /*Where is Explorer Jaren?*/, 11175 /*My Daughter*/, 11484 /*We Have the Technology*/, 11483 /*We Can Rebuild It*/, 11477 /*Out of My Element?*/, 11465 /*The Ransacked Caravan*/, 11460 /*Trust is Earned*/, 11475 /*Tools to Get the Job Done*/, 11474 /*Problems on the High Bluff*/, 11427 /*Meet Lieutenant Icehammer...*/, 11291 /*To Westguard Keep!*/, 11251 /*Fresh Legs*/, 11426 /*Locating the Mechanism*/, 11344 /*Anguish of Nifflevar*/, 11290 /*Dragonflayer Battle Plans*/, 11448 /*The Explorers' League Outpost*/, 11278 /*Return to Valgarde*/, 11300 /*Stunning Defeat at the Ring*/, 11299 /*The Ring of Judgment*/, 11289 /*Guided by Honor*/, 11288 /*The Shining Light*/, 11277 /*The Depths of Depravity*/, 11276 /*And Then There Were Two...*/, 11274 /*Zedd's Probably Dead*/, 11343 /*The Echo of Ymiron*/, 11443 /*Daggercap Divin'*/, 11273 /*The Human League*/, 11420 /*The Path to Payback*/, 11333 /*Into the World of Spirits*/, 11255 /*Prisoners of Wyrmskull*/, 11244 /*Rescuing the Rescuers*/, 11243 /*If Valgarde Falls...*/, 29608 /*Allies in Dalaran*/, 11228 /*Hell Has Frozen Over...*/, 28709 /*Hero's Call: Northrend!*/, 11182 /*Root Causes*/, 11190 /*One Size Does Not Fit All*/, 11155 /*Shoveltusk Soup Again?*/, 11157 /*The Clutches of Evil*/, 29763 /*Stealing Their Thunder*/, 29764 /*Disarmament*/, 29803 /*Ears of the Lich King*/, 11468 /*Falcon Versus Hawk*/, 24522 /*Journey To The Sunwell*/, 24480 /*The Halls Of Reflection*/, 27726 /*Hero's Call: Mount Hyjal!*/, 28825 /*A Personal Summons*/, 29864 /*Working at the Source*/, 13131 /*Junk in My Trunk*/, 13132 /*Vengeance Be Mine!*/, 13128 /*A Wing and a Prayer*/, 13127 /*Mage-Lord Urom*/, 13126 /*A Unified Front*/, 13124 /*The Struggle Persists*/, 12770 /*Reallocating Resources*/, 12249 /*Ursoc, the Bear God*/, 12250 /*Vordrassil's Seeds*/, 12248 /*Vordrassil's Sapling*/, 13207 /*Halls of Stone*/, 29848 /*The Forlorn Watcher*/, 29850 /*Corrupt Constructs*/, 12296 /*Life or Death*/, 29834 /*Gal'darah Must Pay*/, 29839 /*One of a Kind*/, 29844 /*For Posterity*/, 30120 /*Cleansing Drak'Tharon*/, 29828 /*What the Scourge Dred*/, 13129 /*Head Games*/, 12794 /*The Magical Kingdom of Dalaran*/, 13187 /*The Faceless Ones*/, 29826 /*Reclaiming Ahn'Kahet*/, 29825 /*Pupil No More*/, 24959 /*Fresh out of the Grave*/, 28608 /*The Shadow Grave*/, 13522 /*Threat from the Water*/, 13518 /*The Last Wave of Survivors*/, 26385 /*Breaking Waves of Change*/, 14266 /*Charge*/, 14129 /*Runaway Shredder!*/, 25243 /*She Loves Me, She Loves Me NOT!*/, 25203 /*What Kind of Name is Chip, Anyway?*/, 25109 /*The Gallywix Labor Mine*/, 25100 /*Let's Ride*/, 25099 /*Borrow Bastia*/, 25098 /*The Warchief Wants You*/, 25066 /*The Pride of Kezan*/, 25058 /*Mine Disposal, the Goblin Way*/, 25093 /*The Heads of the SI:7*/, 25024 /*Repel the Paratroopers*/, 25023 /*Old Friends*/, 24958 /*Volcanoth!*/, 24954 /*Children of a Turtle God*/, 24952 /*Rocket Boot Boost*/, 24946 /*Rockin' Powder*/, 24945 /*Three Little Pygmies*/, 24942 /*Zombies vs. Super Booster Rocket Boots*/, 24940 /*Up the Volcano*/, 24937 /*Oomlot Dealt With*/, 24864 /*Irresistible Pool Pony*/, 24859 /*Naga Hide*/, 24858 /*Bilgewater Cartel Represent*/, 24856 /*Invasion Imminent!*/, 24817 /*A Goblin in Shark's Clothing*/, 24816 /*Who's Top of the Food Chain Now?*/, 24744 /*The Biggest Egg Ever*/, 24741 /*Trading Up*/, 24671 /*Cluster Cluck*/, 27139 /*Hobart Needs You*/, 14245 /*It's a Town-In-A-Box*/, 14244 /*Up, Up & Away!*/, 14445 /*Farewell, For Now*/, 14243 /*Warchief's Revenge*/, 14326 /*Meet Me Up Top*/, 14242 /*Precious Cargo*/, 14241 /*Get to the Gyrochoppa!*/, 14240 /*To the Cliffs*/, 14238 /*Infrared = Infradead*/, 14237 /*Forward Movement*/, 14303 /*Back to Aggra*/, 14236 /*Weed Whacker*/, 14235 /*The Vicious Vale*/, 14234 /*The Enemy of My Enemy*/, 14233 /*Orcs Can Write?*/, 14031 /*Capturing the Unknown*/, 14021 /*Miner Troubles*/, 14248 /*Help Wanted*/, 14019 /*Monkey Business*/, 14473 /*It's Our Problem Now*/, 14014 /*Get Our Stuff Back!*/, 14001 /*Goblin Escape Pods*/, 14126 /*Life Savings*/, 14125 /*447*/, 14124 /*Liberate the Kaja'mite*/, 14123 /*Waltz Right In*/, 14121 /*Robbing Hoods*/, 14122 /*The Great Bank Heist*/, 14120 /*A Bazillion Macaroons?!*/, 14116 /*The Uninvited Guest*/, 14115 /*Pirate Party Crashers*/, 14113 /*Life of the Party*/, 14013 /*Charge*/, 14109 /*The New You*/, 24520 /*Give Sassy the News*/, 24503 /*Fourth and Goal*/, 24502 /*Necessary Roughness*/, 24488 /*The Replacements*/, 26712 /*Off to the Bank*/, 14070 /*Do it Yourself*/, 24567 /*Report for Tryouts*/, 14071 /*Rolling with my Homies*/, 28349 /*Megs in Marketing*/, 25473 /*Kaja'Cola*/, 14069 /*Good Help is Hard to Find*/, 14075 /*Trouble in the Mines*/, 14138 /*Taking Care of Business*/, 10072 /*Learning the Word*/, 8564 /*Priest Training*/, 8346 /*Thirst Unending*/, 8336 /*A Fistful of Slivers*/, 8330 /*Solanian's Belongings*/, 12978 /*Facing the Storm*/, 12965 /*The Gifts of Loken*/, 12964 /*The Dark Ore*/, 12957 /*Slaves of the Stormforged*/, 12937 /*Relief for the Fallen*/, 12931 /*Fighting Back*/, 13112 /*Infused Mushroom Meatloaf*/, 13426 /*Xarantaur, the Witness*/, 13285 /*Forging the Keystone*/, 13274 /*The Core's Keeper*/, 13273 /*Going After the Core*/, 12928 /*Norgannon's Shell*/, 13416 /*The Library Console*/, 12927 /*Data Mining*/, 12926 /*Pieces of the Puzzle*/, 12920 /*Catching up with Brann*/, 12930 /*Rare Earth*/, 12917 /*Speaking with the Wind's Voice*/, 12913 /*Speak Orcish, Man!*/, 12910 /*Sniffing Out the Perpetrator*/, 12909 /*The Nose Knows*/, 13056 /*There's Always Time for Revenge*/, 13055 /*Cave Medicine*/, 12895 /*The Missing Bronzebeard*/, 12882 /*Ancient Relics*/, 13000 /*Emergency Measures*/, 13054 /*The Missing Tracker*/, 12846 /*Leave No Goblin Behind*/, 13060 /*When All Else Fails*/, 12824 /*Demolitionist Extraordinaire*/, 12823 /*A Flawless Plan*/, 12822 /*Know No Fear*/, 29159 /*Pyrorachnophobia*/, 29276 /*The Flame Spider Queen*/, 29278 /*Living Obsidium*/, 29304 /*The Dogs of War*/, 29299 /*Some Like It Hot*/, 29177 /*Vigilance on Wings*/, 29165 /*The Call of the Pack*/, 29166 /*Supplies for the Other Side*/, 29164 /*Perfecting Your Howl*/, 12821 /*Opening the Backdoor*/, 12832 /*Bitter Departure*/, 12831 /*Only Partly Forgotten*/, 12829 /*Moving In*/, 12830 /*Ore Repossession*/, 12820 /*A Delicate Touch*/, 12826 /*Slightly Unstable*/, 12828 /*Ample Inspiration*/, 12819 /*Just Around the Corner*/, 12844 /*Equipment Recovery*/, 12843 /*They Took Our Men!*/, 12827 /*Reclaimed Rations*/, 12836 /*Expression of Gratitude*/, 12818 /*Clean Up*/, 29833 /*Unfinished Business*/, 12730 /*Convocation at Zol'Heb*/, 12729 /*The Gods Have Spoken*/, 12721 /*Rampage*/, 12707 /*Wooly Justice*/, 12708 /*Enchanted Tiki Warriors*/, 12712 /*The Key of Warlord Zol'Maz*/, 12709 /*Hexed Caches*/, 12685 /*You Reap What You Sow*/, 12684 /*Blood of a Dead God*/, 12675 /*One Last Thing*/, 12674 /*Hell Hath a Fury*/, 12668 /*Foundation for Revenge*/, 12672 /*Setting the Stage*/, 12667 /*Seek the Wind Serpent Goddess*/, 12666 /*Preparations for the Underworld*/, 12665 /*I Sense a Disturbance*/, 12653 /*Back to Har'koa*/, 12647 /*An End to the Suffering*/, 12646 /*My Prophet, My Enemy*/, 12662 /*Bringing Down Heb'Jin*/, 12659 /*Scalps!*/, 28692 /*Magnets, How Do They Work?*/, 28691 /*First Lieutenant Connor*/, 28686 /*Not The Friendliest Town*/, 28685 /*Leave No Weapon Behind*/, 28684 /*A Sticky Task*/, 28694 /*Watch Out For Splinters!*/, 10201 /*And Now, the Moment of Truth*/, 11669 /*Felblood Fillet*/, 9832 /*The Second and Third Fragments*/, 13116 /*Mustard Dogs!*/, 12639 /*The Frozen Earth*/, 12640 /*Sealing the Rifts*/, 12655 /*The Blessing of Zim'Rhuk*/, 13549 /*Tails Up*/, 12650 /*Plundering Their Own*/, 12642 /*Spirit of Rhunok*/, 12632 /*But First My Offspring*/, 12635 /*Relics of the Snow Leopard Goddess*/, 12628 /*To Speak With Har'koa*/, 12555 /*A Tangled Skein*/, 12584 /*Pure Evil*/, 12583 /*Crashed Sprayer*/, 12554 /*Malas the Corrupter*/, 12552 /*Death to the Necromagi*/, 12553 /*Skimmer Spinnerets*/, 12606 /*Cocooned!*/, 12598 /*Throwing Down*/, 12512 /*Leave No One Behind*/, 12599 /*Creature Comforts*/, 12557 /*Lab Work*/, 12610 /*Clipping Their Wings*/, 12609 /*Stocking the Shelves*/, 12799 /*Siphoning the Spirits*/, 12622 /*The Leaders at Jin'Alai*/, 12615 /*The Blessing of Zim'Torga*/, 12627 /*Breaking Through Jin'Alai*/, 12527 /*Gluttonous Lurkers*/, 12500 /*Return To Angrathar*/, 12496 /*Audience With The Dragon Queen*/, 12224 /*The Kor'kron Vanguard!*/, 29148 /*Wings Aflame*/, 29147 /*Call the Flock*/, 29149 /*Rage Against the Flames*/, 9831 /*Entry Into Karazhan*/, 29642 /*Trouble at Auchindoun*/, 11514 /*Maintaining the Sunwell Portal*/, 11877 /*Sunfury Attack Plans*/, 13676 /*Training In The Field*/, 13677 /*Learning The Reins*/, 13674 /*A Worthy Weapon*/, 28690 /*Salvaging the Remains*/, 28683 /*Thinning the Brood*/, 28679 /*Rattling Their Cages*/, 28697 /*Ghostbuster*/, 13114 /*Sewer Stew*/, 29143 /*Wisp Away*/, 11003 /*The Fall of Magtheridon*/, 13384 /*Judgment at the Eye of Eternity*/, 13372 /*The Key to the Focusing Iris*/, 12623 /*To the Witch Doctor*/, 12516 /*Too Much of a Good Thing*/, 12508 /*Mopping Up*/, 12504 /*Argent Crusade, We Are Leaving!*/, 12514 /*Mushroom Mixer*/, 12510 /*Precious Elemental Fluids*/, 12565 /*The Blessing of Zim'Abwa*/, 12506 /*Trouble at the Altar of Sseratus*/, 12597 /*Something for the Pain*/, 12596 /*Pa'Troll*/, 12505 /*New Orders for Sergeant Stackhammer*/, 12562 /*The Drakkari Do Not Need Water Elementals!*/, 12740 /*Parachutes for the Argent Crusade*/, 12503 /*Defend the Stand*/, 12919 /*The Storm King's Vengeance*/, 12916 /*Our Only Hope*/, 12914 /*Gymer's Salvation*/, 12912 /*A Great Storm Approaches*/, 12904 /*Light Won't Grant Me Vengeance*/, 12795 /*Taking a Stand*/, 12630 /*Kickin' Nass and Takin' Manes*/, 12713 /*Betrayal*/, 12710 /*Disclosure*/, 12690 /*Fuel for the Fire*/, 12676 /*Sabotage*/, 12686 /*Zero Tolerance*/, 12677 /*Hazardous Materials*/, 12673 /*It Rolls Downhill*/, 12669 /*So Far, So Bad*/, 29315 /*Fungus Among Us*/, 25012 /*Take to the Skies*/, 25011 /*To Bigger and Better Things*/, 29446 /*A Wondrous Weapon*/, 25046 /*A Daughter's Embrace*/, 25013 /*A Little Oomph*/, 25010 /*A Deadly New Ally*/, 27998 /*Sweet, Merciless Revenge*/, 27996 /*Orders Are For the Living*/, 27988 /*Plague...Plague Everywhere!*/, 27974 /*This Land is Our Land*/, 25009 /*At War With The Scarlet Crusade*/, 25056 /*Grisly Grizzlies*/, 12433 /*Seeking Solvent*/, 12058 /*The Runic Prophecies*/, 12073 /*Pounding the Iron*/, 12054 /*Deciphering the Journal*/, 12026 /*The Damaged Journal*/, 12431 /*The Conquest Pit: Final Showdown*/, 12430 /*The Conquest Pit: Death Is Likely*/, 12429 /*The Conquest Pit: Blood and Metal*/, 12428 /*The Conquest Pit: Mad Furbolg Fighting*/, 12427 /*The Conquest Pit: Bear Wrestling!*/, 12178 /*Delivery to Krenna*/, 12203 /*Loken's Orders*/, 12202 /*Cultivating an Image*/, 12201 /*The Overseer's Shadow*/, 12204 /*In the Name of Loken*/, 12199 /*Bringing Down the Iron Thane*/, 12198 /*... Or Maybe We Don't*/, 12197 /*We Have the Power*/, 12196 /*From the Ground Up*/, 13673 /*A Blade Fit For A Champion*/, 13678 /*Up To The Challenge*/, 13838 /*Mastery Of The Shield-Breaker*/, 13839 /*Mastery Of The Charge*/, 13829 /*Mastery Of Melee*/, 9544 /*The Prophecy of Akida*/, 9542 /*Totem of Vark*/, 9541 /*Totem of Yor*/, 9540 /*Totem of Tikti*/, 9539 /*Totem of Coo*/, 9538 /*Learning the Language*/, 28559 /*Hero's Call: Bloodmyst Isle!*/, 14039 /*Home of the Kaldorei*/, 935 /*The Waters of Teldrassil*/, 14005 /*The Vengeance of Elune*/, 2561 /*Druid of the Claw*/, 2541 /*The Sleeping Druid*/, 28659 /*The Leftovers*/, 28657 /*A Huge Problem*/, 28658 /*Swamp Bait*/, 28662 /*Learning From The Past*/, 28661 /*The Imprisoned Archmage*/, 28660 /*Clearing the Depths*/, 29243 /*Strike at the Heart*/, 29275 /*Fandral's Methods*/, 29210 /*Enduring the Heat*/, 29160 /*Egg-stinction*/, 29297 /*Bye Bye Burdy*/, 29192 /*The Wardens are Watching*/, 29257 /*Steal Magmolias*/, 29122 /*Echoes of Nemesis*/, 29101 /*Punting Season*/, 28682 /*Claiming The Keep*/, 28700 /*Taking the Overlook Back*/, 29189 /*Wicked Webs*/, 29142 /*Traitors Return*/, 29126 /*The Power of Malorne*/, 29127 /*Rage Against the Flames*/, 29125 /*Between the Trees*/, 28687 /*Teach A Man To Fish.... Or Steal*/, 28695 /*WANTED: Foreman Wellson*/, 13115 /*Cheese for Glowergold*/, 28884 /*Victory in Tol Barad*/, 28681 /*Shark Tank*/, 28680 /*Boosting Morale*/, 12236 /*Ursoc, the Bear God*/, 12213 /*The Darkness Beneath*/, 12207 /*Vordrassil's Fall*/, 12425 /*Ruuna the Blind*/, 12453 /*Eyes Above*/, 12422 /*Tactical Clemency*/, 12424 /*Gorgonna*/, 12413 /*Attack on Silverbrook*/, 12423 /*Mikhail's Journal*/, 12412 /*My Enemy's Friend*/, 12451 /*Onward to Camp Oneqwah*/, 12259 /*The Thane of Voldrune*/, 12177 /*Jun'ik's Coverup*/, 12257 /*A Show of Strength*/, 12256 /*The Flamebinders' Secrets*/, 12176 /*A Minor Substitution*/, 28693 /*Finish The Job*/, 13113 /*Convention at the Legerdemain*/, 12112 /*Stiff Negotiations*/, 13343 /*Mystery of the Infinite, Redux*/, 12273 /*The Denouncement*/, 12285 /*Do Unto Others*/, 12283 /*The Truth Will Out*/, 12274 /*A Fall From Grace*/, 12260 /*The Perfect Dissemblance*/, 12271 /*The Rod of Compulsion*/, 12254 /*Without a Prayer*/, 12239 /*The Spy in New Hearthglen*/, 12252 /*Torture the Torturer*/, 12245 /*No Mercy for the Captured*/, 12234 /*Need to Know*/, 12214 /*Fresh Remounts*/, 12243 /*Fire Upon the Waters*/, 12240 /*A Means to an End*/, 12221 /*The Forsaken Blight*/, 12232 /*Bombard the Ballistae*/, 12230 /*Stealing from the Siegesmiths*/, 12218 /*Spread the Good Word*/, 12200 /*Emerald Dragon Tears*/, 12211 /*Let Them Not Rise!*/, 12205 /*Wanted: The Scarlet Onslaught*/, 12209 /*Materiel Plunder*/, 12124 /*Informing the Queen*/, 12769 /*The Steward of Wyrmrest Temple*/, 12450 /*Through Fields of Flame*/, 12449 /*Return to the Earth*/, 12448 /*Heated Battle*/, 12461 /*Report to the Ruby Dragonshrine*/, 12767 /*Speak with your Ambassador*/, 12122 /*Gaining an Audience*/, 12110 /*The End of the Line*/, 12106 /*Search Indu'le Village*/, 12085 /*A Letter for Home*/, 12096 /*Strengthen the Ancients*/, 12084 /*Atop the Woodlands*/, 12066 /*The Focus on the Beach*/, 12061 /*Projections and Plans*/, 12059 /*A Strange Device*/, 12136 /*The Translated Tome*/, 12132 /*The Power to Destroy*/, 12147 /*Disturbing Implications*/, 12145 /*Canyon Chase*/, 12144 /*Pest Control*/, 12097 /*Sarathstra, Scourge of the North*/, 26013 /*Assault on the Sanctum*/, 12127 /*In Service of Frost*/, 12126 /*In Service of the Unholy*/, 12125 /*In Service of Blood*/, 12111 /*Where the Wild Things Roam*/, 12095 /*To Dragon's Fall*/, 12104 /*Return to Soar*/, 12304 /*Beachfront Property*/, 12115 /*Koltira and the Language of Death*/, 12140 /*All Hail Roanauk!*/, 12072 /*Blightbeasts be Damned!*/, 12071 /*Attack by Air! */, 12069 /*Return of the High Chief*/, 12057 /*The Flesh-Bound Tome*/, 12064 /*Chains of the Anub'ar*/, 12063 /*Strength of Icemist*/, 12005 /*Prevent the Accord*/, 12053 /*The Might of the Horde*/, 12102 /*In Search of the Ruby Lilac*/, 12048 /*Scourge Armaments*/, 12101 /*The Good Doctor...*/, 12056 /*Marked for Death: High Cultist Zangus*/, 12100 /*Containing the Rot*/, 12039 /*Black Blood of Yogg-Saron*/, 12036 /*From the Depths of Azjol-Nerub*/, 12091 /*Wanted: Dreadtalon*/, 12090 /*Wanted: Gigantaur*/, 12089 /*Wanted: Magister Keldonus*/, 12033 /*Message from the West*/, 12034 /*Victory Nears...*/, 11999 /*Rifle the Bodies*/, 12008 /*Agmar's Hammer*/, 11983 /*Blood Oath of the Horde*/, 11978 /*Into the Fold*/, 11980 /*Pride of the Horde*/, 29137 /*Breach in the Defenses*/, 2499 /*Oakenscowl*/, 933 /*Teldrassil: The Coming Dawn*/, 923 /*Mossy Tumors*/, 353 /*Stormpike's Delivery*/, 28562 /*Hero's Call: Westfall!*/, 7905 /*The Darkmoon Faire*/, 27865 /*The Crucible of Carnage: The Wayward Wildhammer!*/, 27863 /*The Crucible of Carnage: The Bloodeye Bruiser!*/, 26233 /*Stealing From Our Own*/, 11423 /*The Enemy's Legacy*/, 12482 /*Against Nifflevar*/, 11310 /*Warning: Some Assembly Required*/, 26226 /*Crawfish Creole*/, 11309 /*Parts for the Job*/, 11308 /*Time for Cleanup*/, 11307 /*Field Test*/, 11306 /*Apply Heat and Stir*/, 11280 /*Draconis Gastritis*/, 26227 /*Careful, This Fruit Bites Back*/, 12481 /*Adding Injury to Insult*/, 11424 /*Shield Hill*/, 11279 /*Green Eggs and Whelps*/, 11305 /*A Tailor-Made Formula*/, 11303 /*The Ambush*/, 11285 /*Baleheim Must Burn!*/, 11283 /*Baleheim Bodycount*/, 12566 /*Help for Camp Winterhoof*/, 11282 /*A Lesson in Fear*/, 11304 /*New Agamand*/, 11295 /*The Offensive Begins*/, 11170 /*Test at Sea*/, 11254 /*The Dragonskin Map*/, 11168 /*Spiking the Mix*/, 11234 /*Report to Anselm*/, 11241 /*Trail of Fire*/, 11233 /*Landing the Killing Blow*/, 11232 /*Guide Our Sights*/, 11230 /*Ambushed!*/, 11229 /*The Windrunner Fleet*/, 11253 /*Sniff Out the Enemy*/, 11221 /*Reports from the Field*/, 11167 /*The New Plague*/, 11270 /*War is Hell*/, 11227 /*Let Them Eat Crow*/, 11433 /*Sleeping Giants*/, 11453 /*The Slumbering King*/, 11268 /*The Walking Dead*/, 11264 /*Necro Overlord Mezhen*/, 11265 /*Of Keys and Cages*/, 11263 /*Dealing With Gjalerbron*/, 11261 /*The Conqueror of Skorn!*/, 11259 /*Towers of Certain Doom*/, 11258 /*Burn Skorn, Burn!*/, 11257 /*Gruesome, But Necessary*/, 11324 /*Alpha Worg*/, 11367 /*Demolishing Megalith*/, 11366 /*The Lodestone*/, 11352 /*The Rune of Command*/, 11260 /*Stop the Ascension!*/, 11256 /*Skorn Must Fall!*/, 11417 /*Eyes of the Eagle*/, 11415 /*Brother Betrayers*/, 11323 /*In Worg's Clothing*/, 11351 /*Mastering the Runes*/, 11365 /*March of the Giants*/, 11350 /*The Book of Runes*/, 11312 /*The Frozen Glade*/, 11281 /*Mimicking Nature's Call*/, 11311 /*Suppressing the Elements*/, 11267 /*The Frost Wyrm and its Master*/, 11275 /*Making the Horn*/, 11271 /*Hasty Preparations*/, 11266 /*Gjalerbron Attack Plans*/, 11296 /*Rivenwood Captives*/, 11317 /*The Cleansing*/, 11286 /*The Artifacts of Steel Gate*/, 11301 /*Brains! Brains! Brains!*/, 11298 /*What's in That Brew?*/, 11397 /*And You Thought Murlocs Smelled Bad!*/, 11399 /*Bring Down Those Shields*/, 11398 /*It's a Scourge Device*/, 11422 /*Trident of the Son*/, 12432 /*Riding the Red Rocket*/, 28698 /*Cannonball!*/, 28696 /*Bombs Away!*/, 26220 /*Everything Is Better with Bacon*/, 10625 /*Spectrecles*/, 29650 /*Fel Ember*/, 8702 /*Ring of Unspoken Names*/, 8710 /*Kris of Unspoken Names*/, 8694 /*Shroud of Unspoken Names*/, 26235 /*Even Thieves Get Hungry*/, 7926 /*The Darkmoon Faire*/, 26899 /*The Enemy of My Enemy*/, 26892 /*Deep in the Deeps*/, 26888 /*Nightmare of the Deeps*/, 26891 /*Amongst the Ruins*/, 27850 /*The Defias Kingpin*/, 27848 /*Good Intentions...Poor Execution*/, 27844 /*Traitors!!!*/, 27842 /*Only the Beginning*/, 27847 /*Not Quite There*/, 29616 /*Storming the Steamvault*/, 9747 /*The Umbrafen Tribe*/, 29568 /*A Necessary Evil*/, 29570 /*Rescuing the Expedition*/, 29691 /*Bring Me A Shrubbery!*/, 29567 /*Stalk the Stalker*/, 29615 /*Windcaller Claw and the Water Thief*/, 29614 /*Containment is Key*/, 29613 /*A Proper Fate*/, 29564 /*A Brother Betrayed*/, 29565 /*The Heart of the Matter*/, 29563 /*Lost in Action*/, 29305 /*Strike at the Heart*/, 29296 /*Territorial Birds*/, 29287 /*Peaked Interest*/, 29273 /*How Hot*/, 29264 /*Flamewakers of the Molten Flow*/, 29265 /*Fire Flowers*/, 26862 /*Elemental Tampering*/, 26856 /*Repel the Invasion*/, 26858 /*Taragaman the Hungerer*/, 26865 /*Enemies Below*/, 24981 /*A Thorn in our Side*/, 29290 /*Fire in the Skies*/, 29274 /*Hounds of Shannox*/, 28689 /*The Forgotten*/, 28678 /*Captain P. Harris*/, 29293 /*Singed Wings*/, 29295 /*The Bigger They Are*/, 24713 /*Frostmourne*/, 2280 /*The Platinum Discs*/, 2278 /*The Platinum Discs*/, 27680 /*Archaedas, The Ancient Stone Watcher*/, 27679 /*The Chamber of Khaz'mul*/, 27682 /*We Require More Minerals*/, 27681 /*Behind Closed Doors*/, 29332 /*Lily, Oh Lily*/, 29507 /*Fun for the Little Ones*/, 29520 /*Banners, Banners Everywhere!*/, 29464 /*Tools of Divination*/, 29360 /*Would You Like Some Flies With That?*/, 29288 /*Starting Young*/, 29333 /*Escargot A Go-Go*/, 28543 /*Hero's Call: Felwood!*/, 25061 /*Land's End*/, 24953 /*Just Trying to Kill Some Bugs*/, 24951 /*A Great Idea*/, 24931 /*Gazer Tag*/, 24933 /*Chicken of the Desert*/, 25072 /*A Few Good Goblins*/, 24932 /*Cutting Losses*/, 26889 /*All Cheered Out*/, 25166 /*Captain Dreadbeard*/, 26887 /*Filling Our Pockets*/, 26886 /*Going Off-Task*/, 25054 /*Lootin' Plunder*/, 25053 /*To The Ground!*/, 25052 /*Dead Man's Chest*/, 25032 /*Secrets in the Oasis*/, 25026 /*Darkest Mojo*/, 25025 /*Sang'thraze the Deflector*/, 25522 /*Gargantapid*/, 25521 /*I'm With Scorpid*/, 25021 /*Blood to Thrive*/, 25121 /*Momentum*/, 25091 /*Sandsorrow Watch*/, 25115 /*Blisterpaw Butchery*/, 648 /*Rescue OOX-17/TN!*/, 25111 /*Scavengers Scavenged*/, 25112 /*Butcherbot*/, 25050 /*Rocket Rescue*/, 25049 /*Puddle Stomping*/, 25048 /*Seaside Salvage*/, 28155 /*Lord Banehollow*/, 28153 /*Shadow Lord Fel'dan*/, 28131 /*Twin Temptresses*/, 28128 /*The Inner Circle*/, 28129 /*The Demon Prince*/, 28126 /*Dousing the Flames of Protection*/, 28119 /*Purity From Corruption*/, 28102 /*Fight the Power*/, 28113 /*Break the Unbreakable*/, 28044 /*Touch the Untouchable*/, 28049 /*See the Invisible*/, 28000 /*Do the Imp-Possible*/, 28150 /*An Arcane Ally*/, 27995 /*Dance for Ruumbo!*/, 27989 /*Ruumbo Demands Honey*/, 27994 /*Ruumbo Demands Justice*/, 28148 /*Culling the Corrupted*/, 28100 /*A Talking Totem*/, 27997 /*The Corruption of the Jadefire*/, 28116 /*Crying Violet*/, 28121 /*Forces of Jaedenar*/, 29851 /*Champion of the Tournament*/, 28670 /*Food From Below*/, 28669 /*The Warden*/, 28668 /*Prison Revolt*/, 13279 /*Basic Chemistry*/, 28665 /*Cursed Shackles*/, 28664 /*Svarnos*/, 28663 /*D-Block*/, 29135 /*All-Seeing Eye*/, 29134 /*A Wrinkle in Time*/, 29129 /*A Legendary Engagement*/, 28843 /*Sins of the Sea Witch*/, 28833 /*Rescue the Earthspeaker!*/, 29319 /*Tadpole Terror*/, 29322 /*Time for Slime*/, 5502 /*A Warden of the Horde*/, 29191 /*You Scream, I Scream...*/, 29190 /*Let's Go Fly a Kite*/, 29167 /*The Banshee Queen*/, 29176 /*The Fallen Chieftain*/, 29146 /*Ridin' the Rocketway*/, 172 /*Children's Week*/, 29361 /*Moat Monster!*/, 29107 /*Malfurion Has Returned!*/, 29106 /*The Biggest Diamond Ever!*/, 29093 /*Cruisin' the Chasm*/, 29412 /*Blown Away*/, 11975 /*Now, When I Grow Up...*/, 13959 /*Back To The Orphanage*/, 13937 /*A Trip To The Wonderworks*/, 13956 /*Meeting a Great One*/, 13954 /*The Dragon Queen*/, 13950 /*Playmates!*/, 13933 /*The Bronze Dragonshrine*/, 13929 /*The Biggest Tree Ever!*/, 13926 /*Little Orphan Roo Of The Oracles*/, 24712 /*Deliverance from the Pit*/, 24507 /*The Path to the Citadel*/, 24682 /*The Pit of Saron*/, 9558 /*The Longbeards*/, 24974 /*Ever So Lonely*/, 24975 /*Fields of Grief*/, 24978 /*Reaping the Reapers*/, 24972 /*Vital Intelligence*/, 24971 /*Assault on the Rotbrain Encampment*/, 24970 /*No Better Than the Zombies*/, 24973 /*Night Web's Hollow*/, 26802 /*The Damned*/, 28672 /*The Executor In the Field*/, 28564 /*Hero's Call: Duskwood!*/, 26994 /*Without Rhyme or Reason*/, 26976 /*Battle for the Scarlet Monastery*/, 26873 /*Preemptive Methods*/, 26872 /*Deviate Hides*/, 26870 /*Cleansing the Caverns*/, 10399 /*The Heart of Darkness*/, 10395 /*The Dark Missive*/, 10397 /*Invasion Point: Annihilator*/, 10396 /*Enemy of my Enemy...*/, 10394 /*Disruption - Forge Camp: Mageddon*/, 10163 /*Mission: The Abyssal Shelf*/, 10144 /*Disrupt Their Reinforcements*/, 29543 /*Invading the Citadel*/, 25067 /*Thunderdrome: The Ginormus!*/, 9453 /*Find Acteon!*/, 9452 /*Red Snapper - Very Tasty!*/, 9314 /*Word from Azure Watch*/, 9313 /*Travel to Azure Watch*/, 9312 /*The Emitter*/, 9798 /*Blood Elf Plans*/, 9311 /*Blood Elf Spy*/, 10303 /*The Blood Elves*/, 9294 /*Healing the Lake*/, 9309 /*The Missing Scout*/, 26966 /*The Light's Power*/, 9799 /*Botanical Legwork*/, 9293 /*What Must Be Done...*/, 10302 /*Volatile Mutations*/, 9303 /*Inoculation*/, 9305 /*Spare Parts*/, 9283 /*Rescue the Survivors!*/, 9409 /*Urgent Delivery!*/, 9280 /*Replenishing the Healing Crystals*/, 9279 /*You Survived!*/, 9689 /*Razormaw*/, 9688 /*Into the Dream*/, 9683 /*Ending the Bloodcurse*/, 9682 /*The Hopeless Ones...*/, 9674 /*The Bloodcursed Naga*/, 9687 /*Restoring Sanctity*/, 9561 /*Nolkai's Words*/, 9557 /*Deciphering the Book*/, 9698 /*Audience with the Prophet*/, 9711 /*Matis the Cruel*/, 28492 /*Hero's Call: Ashenvale!*/, 9696 /*Translations...*/, 9759 /*Ending Their World*/, 10065 /*Cutting a Path*/, 9741 /*Critters of the Void*/, 10066 /*Oh, the Tangled Webs They Weave*/, 10067 /*Fouled Water Spirits*/, 9761 /*Clearing the Way*/, 9706 /*Galaen's Journal - The Fate of Vindicator Saruan*/, 11707 /*Distress Call*/, 29539 /*Heart of Rage*/, 29540 /*The Breaker*/, 29538 /*Make Them Bleed*/, 6607 /*Nat Pagle, Angler Extreme*/, 27183 /*Marsh Frog Legs*/, 1201 /*Theramore Spies*/, 11215 /*Help Mudsprocket*/, 26991 /*Enemies Abroad*/, 26682 /*A Shambling Threat*/, 27253 /*Inspecting the Ruins*/, 25051 /*Darkmist Extermination*/, 27424 /*Overlord Mok'Morokk's Concern*/, 27260 /*Lieutenant Paval Reethe*/, 27259 /*Suspicious Hoofprints*/, 27347 /*Corrosion Prevention*/, 27348 /*Secure the Cargo!*/, 27336 /*The Grimtotem Weapon*/, 27339 /*The Reagent Thief*/, 27346 /*The Zeppelin Crash*/, 27340 /*Direhorn Raiders*/, 27407 /*Bloodfen Feathers*/, 25478 /*To the Summit*/, 27413 /*Catch a Dragon by the Tail*/, 24684 /*A Weezil in the Henhouse*/, 24604 /*Concern for Mankrik*/, 26908 /*Feeling Thorny*/, 24824 /*The Disturbed Earth*/, 24631 /*Flightmare*/, 24551 /*Meet the New Boss*/, 24565 /*Biological Intervention*/, 24571 /*Lashvine Seeds*/, 24570 /*Adder Subtraction*/, 24539 /*When Plants Attack*/, 24525 /*Keeping the Dogs at Bay*/, 24529 /*Bad to Worse*/, 24517 /*Put the Fear in Them*/, 27592 /*Drinks on the Rocks*/, 29529 /*Demons in the Citadel*/, 29594 /*Hitting Them Where It Hurts*/, 29528 /*War on the Ramparts*/, 26173 /*Protecting Our Rear*/, 28708 /*Hero's Call: Outland!*/, 14034 /*Club Foote*/, 14045 /*Find Baron Longshore*/, 895 /*WANTED: Cap'n Garvey*/, 865 /*It's Gotta be the Horn*/, 891 /*A Captain's Vengeance*/, 14066 /*Investigate the Wreckage*/, 13998 /*In Fungus We Trust*/, 13988 /*A Growing Problem*/, 881 /*Echeyakee*/, 29090 /*A Burning Threat*/, 29086 /*Competition Schmompetition*/, 29021 /*Samophlange*/, 858 /*Ignition*/, 899 /*Consumed by Hatred*/, 26000 /*Spelunking*/, 25743 /*Decisions, Decisions*/, 25732 /*A Bone to Pick*/, 25670 /*DUN-dun-DUN-dun-DUN-dun*/, 27699 /*Shark Weak*/, 25794 /*Undersea Sanctuary*/, 25638 /*A Desperate Plea*/, 25657 /*Dah, Nunt... Dah, Nunt...*/, 25651 /*Oh, the Insanity!*/, 25358 /*Nerve Tonic*/, 25459 /*Ophidophobia*/, 25389 /*A Taste For Tail*/, 25390 /*A Girl's Best Friend*/, 25388 /*A Case of Crabs*/, 25598 /*Ain't Too Proud to Beg*/, 25587 /*Gimme Shelter!*/, 27685 /*Good Deed Left Undone*/, 25371 /*The Abyssal Ride*/, 25477 /*Better Late Than Dead*/, 25949 /*Blood and Thunder!*/, 25948 /*Bring It On!*/, 25316 /*As Hyjal Burns*/, 6363 /*Tal the Wind Rider Master*/, 26180 /*Supervisor Fizsprocket*/, 26179 /*The Venture Co.*/, 24456 /*Thunderhorn Cleansing*/, 6362 /*Ride to Thunder Bluff*/, 6361 /*A Bundle of Hides*/, 26188 /*Mazzranache*/, 751 /*The Ravaged Caravan*/, 24441 /*Thunderhorn Totem*/, 24440 /*Winterhoof Cleansing*/, 14491 /*The Restless Earth*/, 20440 /*Poison Water*/, 14438 /*Sharing the Land*/, 24215 /*Rite of the Winds*/, 23733 /*Rites of the Earthmother*/, 24861 /*Last Rites, First Rites*/, 14460 /*Rite of Honor*/, 27020 /*The First Lesson*/, 3091 /*Simple Note*/, 14461 /*Feed of Evil*/, 14459 /*The Battleboars*/, 14455 /*Stop the Thorncallers*/, 14456 /*Rite of Courage*/, 14458 /*Go to Adana*/, 24852 /*Our Tribe, Imprisoned*/, 14452 /*Rite of Strength*/, 14449 /*The First Step*/, 27578 /*Morgan's Fruition*/, 27573 /*The Dark Iron Pact*/, 27571 /*The Grim Guzzler*/, 28735 /*To the Chamber of Incineration!*/, 13083 /*Light Within the Darkness*/, 13082 /*The Boon of A'dal*/, 13081 /*The Will of the Naaru*/, 13080 /*Hope Yet Remains*/, 13079 /*The Boon of Alexstrasza*/, 13078 /*Dahlia's Tears*/, 13077 /*The Touch of an Aspect*/, 13076 /*Time Yet Remains*/, 13075 /*The Boon of Remulos*/, 13074 /*Hope Within the Emerald Nightmare*/, 13073 /*The Keeper's Favor*/, 13072 /*A Hero Remains*/, 13225 /*The Skybreaker*/, 13068 /*A Tale of Valor*/, 13157 /*The Crusaders' Pinnacle*/, 13141 /*The Battle For Crusaders' Pinnacle*/, 13139 /*Into The Frozen Heart Of Northrend*/, 13125 /*The Air Stands Still*/, 13110 /*The Restless Dead*/, 13135 /*It Could Kill Us All*/, 13130 /*The Stone That Started A Revolution*/, 13118 /*The Purging Of Scourgeholme*/, 13122 /*The Scourgestone*/, 13105 /*Once More Unto The Breach, Hero*/, 13086 /*The Last Line Of Defense*/, 13070 /*A Cold Front Approaches*/, 13045 /*Into The Wild Green Yonder*/, 13044 /*If There Are Survivors...*/, 13040 /*Curing The Incurable*/, 13039 /*Defending The Vanguard*/, 28522 /*Winterfall Activity*/, 28524 /*Delivery for Donova*/, 28460 /*Threat of the Winterfall*/, 28544 /*Hero's Call: Winterspring!*/, 27605 /*Eranikus*/, 27633 /*The Blood God Hakkar*/, 27604 /*Jammal'an the Prophet*/, 27569 /*Dark Iron Tacticians*/, 27568 /*Infiltrating Shadowforge City*/, 25152 /*Your Place In The World*/, 25232 /*The Burning Blade*/, 25256 /*Sent for Help*/, 9852 /*The Ultimate Bloodsport*/, 9859 /*Talbuk Mastery*/, 9856 /*Windroc Mastery*/, 9851 /*Clefthoof Mastery*/, 9858 /*Talbuk Mastery*/, 9850 /*Clefthoof Mastery*/, 9861 /*The Howling Wind*/, 9802 /*Plants of Zangarmarsh*/, 28595 /*Krazz Works!*/, 28592 /*Parting Packages*/, 28594 /*Highbank, Crybank*/, 28593 /*Of Utmost Importance*/, 28591 /*Off The Wall*/, 28590 /*Reprisal*/, 28589 /*Everything But the Kitchen Sink*/, 28586 /*Pool Pony Rescue*/, 28584 /*Quality Construction*/, 28588 /*Wildhammer Infestation*/, 28583 /*Krazzworks*/, 27622 /*Mo' Better Shredder*/, 24802 /*Wrath of the Lich King*/, 26452 /*Gurubashi Challenge*/, 29036 /*Honor the Flame*/, 26356 /*Captain Sanders' Hidden Treasure*/, 26355 /*Captain Sanders' Hidden Treasure*/, 26354 /*Captain Sanders' Hidden Treasure*/, 26347 /*Keeper of the Flame*/, 26349 /*The Coastal Menace*/, 26348 /*The Coast Isn't Clear*/, 26322 /*Rise of the Brotherhood*/, 26320 /*A Vision of the Past*/, 26319 /*Secrets Revealed*/, 26297 /*The Dawning of a New Day*/, 26296 /*Evidence Collection*/, 26295 /*Propaganda*/, 26292 /*To Moonbrook!*/, 26291 /*Big Trouble in Moonbrook*/, 26365 /*Hero's Call: Redridge Mountains!*/, 26593 /*Scaring Shaky*/, 26596 /*The Call of Kalimdor*/, 26630 /*Looks Like a Tauren Pirate to Me*/, 26629 /*Seeing Where Your Loyalties Lie*/, 26624 /*Getting In With the Bloodsail*/, 26614 /*Keep An Eye Out*/, 26613 /*Up to Snuff*/, 26612 /*Details of the Attack*/, 26611 /*The Baron Must Be Told*/, 26617 /*An Old Sea Dog*/, 26610 /*Bloodsail Treachery*/, 26609 /*The Bloodsail Buccaneers*/, 26601 /*Mok'rash the Cleaver*/, 26602 /*A Dish Best Served Huge*/, 27159 /*Scourge First... Horde Later*/, 28749 /*The Battle for Andorhal*/, 26600 /*A Giant's Feast*/, 26606 /*Mukla's Demise*/, 26605 /*Grubby Little Paws*/, 26604 /*Protecting Her Royal Highness Poobah*/, 26603 /*Message in a Bottle*/, 26822 /*Good-Fer-Nothin' Slither-Dogs*/, 26823 /*Too Big For His Britches*/, 26826 /*Dask "The Flask" Gobfizzle*/, 26597 /*Stranglethorn Fever*/, 26599 /*The Captain's Chest*/, 9622 /*Warn Your People*/, 9571 /*The Kurken's Hide*/, 9570 /*The Kurken is Lurkin'*/, 9566 /*Blood Crystals*/, 9565 /*Search Stillpine Hold*/, 9573 /*Chieftain Oomooroo*/, 9564 /*Gurf's Dignity*/, 9562 /*Murlocs... Why Here? Why Now?*/, 9560 /*Beasts of the Apocalypse!*/, 9623 /*Coming of Age*/, 9602 /*Deliver Them From Evil...*/, 9537 /*Show Gnomercy*/, 9559 /*Stillpine Hold*/, 9527 /*All That Remains*/, 9515 /*Warlord Sriss'tiz*/, 9514 /*Rune Covered Tablet*/, 9531 /*Tree's Company*/, 9530 /*I've Got a Plant*/, 9523 /*Precious and Fragile Things Need Special Handling*/, 9513 /*Reclaiming the Ruins*/, 9506 /*A Small Start*/, 9512 /*Cookie's Jumbo Gumbo*/, 10428 /*The Missing Fisherman*/, 9456 /*Nightstalker Clean Up, Isle 2...*/, 9455 /*Strange Findings*/, 9505 /*The Prophecy of Velen*/, 9473 /*An Alternative Alternative*/, 10324 /*The Great Moongraze Hunt*/, 9454 /*The Great Moongraze Hunt*/, 9463 /*Medicinal Purpose*/, 9606 /*Return to Caregiver Chellan*/, 9605 /*Hippogryph Master Stephanos*/, 9604 /*On the Wings of a Hippogryph*/, 9603 /*Beds, Bandages, and Beyond*/, 14361 /*Peace of Mind*/, 14365 /*Ethel Rethor*/, 1454 /*The Karnitol Shipwreck*/, 14359 /*Blessings From Above*/, 14357 /*To the Hilt!*/, 14358 /*Ten Pounds of Flesh*/, 14193 /*Nothing a Couple of Melons Won't Fix*/, 14354 /*Elune's Gifts*/, 14387 /*Lay of the Land*/, 14384 /*Rerouted!*/, 25852 /*All's Clear*/, 25851 /*Dances with Grimtotem*/, 25848 /*Downfall*/, 25847 /*Grimtotem Supremacy*/, 25846 /*Grundig Darkcloud, Chieftain of the Grimtotem*/, 25823 /*The Unrelenting Horde*/, 25822 /*Armaments for War*/, 25845 /*Terms of Service*/, 25844 /*Sating the Savage Beast*/, 25837 /*A Proper Peace Offerin'*/, 25834 /*Death by Proxy*/, 25821 /*A Special Kind of Job*/, 25808 /*Is This Thing On?*/, 25806 /*They Put the Assass in... Never Mind*/, 25809 /*Leave No Man Behind! */, 25811 /*Shuttin Her Down*/, 25793 /*The Deep Reaches*/, 25912 /*Seen Better Days*/, 25914 /*Back to the Depths!*/, 25913 /*Putting Them to Rest*/, 25931 /*Brood of Seldarria*/, 25935 /*Hungry Pups*/, 25934 /*World First: Gnomegen*/, 25938 /*Help for Desolace*/, 25930 /*Ascending the Vale*/, 25925 /*Thal'darah's Vengeance*/, 25891 /*Last Ditch Effort*/, 25889 /*Save the Children!*/, 25880 /*Warn Master Thal'darah*/, 25877 /*No Time for Goodbyes!*/, 25876 /*It's Up There!*/, 25879 /*The Lumbering Oaf Problem*/, 25878 /*Schemin' That Sabotage*/, 25875 /*Gnome on the Inside*/, 25768 /*Bombs Away: Mirkfallon Post!*/, 25769 /*Fallowmere Beckons*/, 25765 /*Tell 'Em Koko Sent You*/, 25767 /*Capturing Memories*/, 25766 /*Arcane Legacy*/, 25728 /*Mr. P's Wild Ride*/, 25741 /*Preparations for the Future*/, 25739 /*If the Horde Don't Get You...*/, 25729 /*Gerenzo the Traitor*/, 25730 /*BEWARE OF CRAGJAW!*/, 25669 /*Rumble in the Lumber... Mill*/, 25673 /*Just Ask Alice*/, 25662 /*Free Our Sisters*/, 25652 /*Commandeer That Balloon!*/, 25650 /*Orders from High Command*/, 25649 /*Minx'll Fix It*/, 25647 /*Illegible Orc Letter*/, 25646 /*Windshear Mine Cleanup*/, 25642 /*Don't Look Them in the Eyes*/, 25640 /*Bombs Away: Windshear Mine!*/, 25622 /*Burn, Baby, Burn!*/, 25621 /*Field Test: Gnomecorder*/, 25616 /*Hellscream's Legacy*/, 25615 /*Return to Stardust*/, 25614 /*The Only Way Down is in a Body Bag*/, 26395 /*Dungar Longdrink*/, 26394 /*Continue to Stormwind*/, 47 /*Gold Dust Exchange*/, 26393 /*A Swift Message*/, 62 /*The Fargodeep Mine*/, 60 /*Kobold Candles*/, 26390 /*Ending the Invasion!*/, 26391 /*Extinguishing Hope*/, 26389 /*Blackrock Invasion*/, 28818 /*The Rear is Clear*/, 28808 /*Fear No Evil*/, 28792 /*They Sent Assassins*/, 28784 /*Join the Battle!*/, 26916 /*Mastering the Arcane*/, 28769 /*Lions for Lambs*/, 28757 /*Beating Them Back!*/, 25007 /*East... Always to the East*/, 25006 /*The Grasp Weakens*/, 25005 /*Speak with Sevren*/, 25029 /*Deaths in the Family*/, 25004 /*The Mills Overrun*/, 25003 /*The Family Crypt*/, 25031 /*Head for the Mills*/, 24999 /*Planting the Seed of Fear*/, 24995 /*Off the Scales*/, 24997 /*Graverobbers*/, 24994 /*Doom Weed*/, 26964 /*Warchief's Command: Silverpine Forest!*/, 24991 /*Garren's Haunt*/, 24996 /*Holland's Experiment*/, 24990 /*Darkhound Pounding*/, 6324 /*Return to Morris*/, 6322 /*Michael Garrett*/, 6323 /*Ride to the Undercity*/, 6321 /*Supplying Brill*/, 24983 /*Forsaken Duties*/, 24982 /*The New Forsaken*/, 25090 /*A Putrid Task*/, 25038 /*Gordo's Task*/, 24977 /*Johaan's Experiment*/, 24976 /*Variety is the Spice of Death*/, 24980 /*The Scarlet Palisade*/, 24979 /*A Scarlet Letter*/, 24964 /*The Thrill of the Hunt*/, 24961 /*The Truth of the Grave*/, 24962 /*Trail-Worn Scroll*/, 26801 /*Scourge on our Perimeter*/, 28653 /*Shadow Priest Sarvis*/, 26800 /*Recruitment*/, 25089 /*Beyond the Graves*/, 24960 /*The Wakening*/, 28652 /*Caretaker Caice*/, 26799 /*Those That Couldn't Be Saved*/, 27475 /*Unyielding Servitors*/, 27474 /*Breaking the Barrier*/, 27472 /*Rise, Godfrey*/, 27438 /*The Great Escape*/, 27423 /*Resistance is Futile*/, 27406 /*A Man Named Godfrey*/, 27405 /*Fall Back!*/, 27401 /*What Tomorrow Brings*/, 27364 /*On Whose Orders?*/, 27360 /*Vengeance for Our Soldiers*/, 27350 /*Break in Communications: Rutsak's Guard*/, 27349 /*Break in Communications: Dreadwatch Outpost*/, 27345 /*The F.C.D.*/, 27333 /*Losing Ground*/, 27342 /*In Time, All Will Be Revealed*/, 27290 /*To Forsaken Forward Command*/, 27226 /*Hair of the Dog*/, 27232 /*The Waters Run Red...*/, 27195 /*Nowhere to Run*/, 27194 /*Cornered and Crushed!*/, 27193 /*Seek and Destroy*/, 27181 /*Excising the Taint*/, 27231 /*Reinforcements from Fenris*/, 27180 /*Honor the Dead*/, 27098 /*Lordaeron*/, 27099 /*No Escape*/, 27097 /*Rise, Forsaken*/, 27096 /*Orcs are in Order*/, 27094 /*Deeper into Darkness*/, 27093 /*Lost in the Darkness*/, 27095 /*Skitterweb Menace*/, 27088 /*It's Only Poisonous if You Ingest It*/, 27082 /*Playing Dirty*/, 27073 /*Give 'em Hell!*/, 27069 /*Steel Thunder*/, 27065 /*The Warchief's Fleet*/, 27056 /*Belmont's Report*/, 27045 /*Waiting to Exsanguinate*/, 27039 /*Dangerous Intentions*/, 26998 /*Iterating Upon Success*/, 26995 /*Guts and Gore*/, 26992 /*Agony Abounds*/, 26989 /*The Gilneas Liberation Front*/, 26965 /*The Warchief Cometh*/, 24989 /*Return to the Magistrate*/, 24988 /*The Chill of Death*/, 24998 /*Maggot Eye*/, 9625 /*Elekks Are Serious Business*/, 28557 /*Warchief's Command: Uldum!*/, 28293 /*That's No Pyramid!*/, 27059 /*The Wrong Sequence*/, 27041 /*Decryption Made Easy*/, 27043 /*Fight Fire and Water and Air with...*/, 27008 /*Fly Over*/, 27005 /*The Twilight Plot*/, 27953 /*The Reliquary*/, 27102 /*Maziel's Ascendancy*/, 27101 /*Maziel's Revelation*/, 27100 /*Twilight Research*/, 27722 /*Warchief's Command: Deepholm!*/, 26194 /*Defending the Rift*/, 26182 /*Back to the Tenebrous Cavern*/, 26143 /*All that Rises*/, 26154 /*Twilight Extermination*/, 26149 /*Prisoners*/, 26142 /*Ascend No More!*/, 26141 /*Runestones of Binding*/, 26140 /*Communing with the Ancient*/, 26133 /*Fiends from the Netherworld*/, 26130 /*Unplug L'ghorek*/, 26111 /*... It Will Come*/, 26065 /*Free Wil'hai*/, 26096 /*Scalding Shrooms*/, 26072 /*Into the Totem*/, 26057 /*The Wavespeaker*/, 26071 /*Clearing the Defiled*/, 25984 /*Promontory Point*/, 25988 /*Put It On*/, 28814 /*Followers and Leaders*/, 28815 /*Twilight Documents*/, 25976 /*Treasure Reclamation*/, 25982 /*Those Aren't Masks*/, 25980 /*A Standard Day for Azrajar*/, 25974 /*Sira'kess Slaying*/, 26092 /*Orako's Report*/, 26091 /*Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo*/, 26090 /*I Brought You This Egg*/, 26088 /*Here Fishie Fishie*/, 26089 /*Die Fishman Die*/, 26087 /*"Glow-Juice"*/, 26086 /*Orako*/, 26126 /*The Perfect Fuel*/, 26125 /*Secure Seabrush*/, 26124 /*Secure Seabrush*/, 26122 /*Environmental Awareness*/, 26221 /*Full Circle*/, 25968 /*Desperate Plan*/, 25967 /*Losing Ground*/, 25861 /*Setting An Example*/, 25863 /*Chosen Burden*/, 25862 /*Stolen Property*/, 25859 /*No Trespass Forgiven*/, 25858 /*By Her Lady's Word*/, 25966 /*Visions of the Past: The Slaughter of Biel'aran Ridge*/, 25964 /*Fallen But Not Forgotten*/, 25965 /*Gauging Success*/, 25963 /*Swift Action*/, 25962 /*Properly Inspired*/, 25960 /*Not Entirely Unprepared*/, 25959 /*Clear Goals*/, 25958 /*Looking Forward*/, 25659 /*Not Soon Forgotten*/, 25658 /*Built to Last*/, 25637 /*To the Fathom-Lord's Call*/, 25620 /*The Revered Lady*/, 25619 /*Reoccupation*/, 25957 /*Visions of the Past: The Invasion of Vashj'ir*/, 25956 /*Upon the Scene of Battle*/, 27717 /*Piece of the Past*/, 25954 /*An Occupation of Time*/, 25953 /*Swift Approach*/, 25952 /*Caught Off-Guard*/, 25955 /*A Better Vantage*/, 25595 /*Something Edible*/, 25594 /*Crafty Crabs*/, 25593 /*Shelled Salvation*/, 25592 /*Deep Attraction*/, 25996 /*Waking the Beast*/, 25995 /*Overseer Idra'kess*/, 25992 /*Hopelessly Gearless*/, 25994 /*Still Valuable*/, 25993 /*Body Blows*/, 25991 /*We Are Not Alone*/, 25990 /*Breaking Through*/, 25989 /*Capture the Crab*/, 25908 /*Stick it to Them*/, 25907 /*Slave Labor*/, 25900 /*Making Contact*/, 25890 /*Nespirah*/, 25442 /*A Pearl of Wisdom*/, 25440 /*Fathom-Lord Zin'jatar*/, 25441 /*Vortex*/, 25439 /*Vengeful Heart*/, 25359 /*Toshe's Vengeance*/, 25456 /*Back in One Piece*/, 25217 /*Totem Modification*/, 25360 /*Crabby Patrons*/, 25218 /*Undersea Inflation*/, 25219 /*Don't be Shellfish*/, 25220 /*Slippery Threat*/, 25216 /*The Great Sambino*/, 25215 /*A Distracting Scent*/, 25222 /*Silver Tide Hollow*/, 25221 /*Rundown*/, 25164 /*Backed Into a Corner*/, 25334 /*The Looming Threat*/, 25471 /*Across the Great Divide*/, 27708 /*The Warden's Time*/, 25883 /*How Disarming*/, 26008 /*Decompression*/, 25884 /*Come Hell or High Water*/, 26040 /*What? What? In My Gut...?*/, 25887 /*Wake of Destruction*/, 25419 /*Lady La-La's Medallion*/, 26007 /*Debriefing*/, 27729 /*Once More, With Eeling*/, 25942 /*Buy Us Some Time*/, 25943 /*Traveling on Our Stomachs*/, 25941 /*Rest For the Weary*/, 25936 /*Pay It Forward*/, 25929 /*Sea Legs*/, 25924 /*Call of Duty*/, 27718 /*Warchief's Command: Vashj'ir!*/, 28816 /*To the Depths*/, 28805 /*The Eye of the Storm*/, 28854 /*Closing a Dark Chapter*/, 28852 /*Soften them Up*/, 28853 /*Kill the Courier*/, 11668 /*Shrimpin' Ain't Easy*/, 28779 /*A Long Way from Home*/, 28760 /*Vengeance for Orsis*/, 26710 /*Lost In The Deeps*/, 13424 /*Back to the Pit*/, 14140 /*Stop The Aggressors*/, 14141 /*Gormok Wants His Snobolds*/, 14101 /*Drottinn Hrothgar*/, 27142 /*The Lich, Ras Frostwhisper*/, 27140 /*Alexi's Gambit*/, 27147 /*Kirtonos the Herald*/, 27148 /*School's Out Forever*/, 27143 /*Barov Family Fortune*/, 27146 /*Doctor Theolen Krastinov, the Butcher*/, 27145 /*Plagued Hatchlings...For Now*/, 13973 /*The Grol'dom Militia*/, 872 /*The Far Watch Offensive*/, 844 /*Plainstrider Menace*/, 871 /*In Defense of Far Watch*/, 25264 /*Ak'Zeloth*/, 28494 /*Warchief's Command: Northern Barrens!*/, 25263 /*Arnak Fireblade*/, 25259 /*Gaur Icehorn*/, 25258 /*Griswold Hanniston*/, 25257 /*Ghislania*/, 25262 /*Skull Rock*/, 25261 /*Margoz*/, 25206 /*Ignoring the Warnings*/, 28817 /*The Rear is Clear*/, 28806 /*Fear No Evil*/, 28791 /*They Sent Assassins*/, 28780 /*Join the Battle!*/, 26917 /*The Hunter's Path*/, 26910 /*Etched Letter*/, 28759 /*Lions for Lambs*/, 28767 /*Beating Them Back!*/, 29444 /*An Exotic Egg*/, 27692 /*Princess Theradras*/, 25129 /*Sarkoth*/, 25126 /*Cutting Teeth*/, 25205 /*The Wolf and The Kodo*/, 25236 /*Thunder Down Under*/, 25260 /*Fizzled*/, 835 /*Securing the Lines*/, 834 /*Winds in the Desert*/, 25196 /*The Dranosh'ar Blockade*/, 24929 /*Send a Message*/, 24925 /*Free the Captives*/, 24924 /*Oomlot Village*/, 24901 /*Town-In-A-Box: Under Attack*/, 24897 /*Get Back to Town*/, 24868 /*Surrender or Else!*/, 25195 /*That's the End of That Raptor*/, 25194 /*Unbidden Visitors*/, 25192 /*Raggaran's Fury*/, 25190 /*Raggaran's Rage*/, 25189 /*Spirits Be Praised*/, 25193 /*Lost But Not Forgotten*/, 25188 /*Watershed Patrol*/, 25187 /*Lost in the Floods*/, 25227 /*Thonk*/, 25179 /*Loss Reduction*/, 25178 /*Shipwreck Searching*/, 25177 /*Storming the Beaches*/, 25176 /*Exploiting the Situation*/, 25173 /*From Bad to Worse*/, 25171 /*Riding On*/, 25169 /*The War of Northwatch Aggression*/, 25168 /*Purge the Valley*/, 25165 /*Never Trust a Big Barb and a Smile*/, 27023 /*The Way of the Sunwalkers*/, 27015 /*Consecrated Note*/, 27104 /*Alzzin the Wildshaper*/, 27105 /*An Unwelcome Guest*/, 27103 /*Shards of the Felvine*/, 27108 /*Lethtendris's Web*/, 27107 /*Pusillin The Thief*/, 26996 /*Right Under Their Noses*/, 27697 /*Corruption in Maraudon*/, 14474 /*Goblin Escape Pods*/, 14153 /*Life of the Party*/, 14110 /*The New You*/, 14012 /*Corruption*/, 26711 /*Off to the Bank*/, 24965 /*Magic Training*/, 3098 /*Glyphic Scroll*/, 27737 /*By Fire Be Saved!*/, 27739 /*The Gnoll King*/, 27733 /*The Good Ol' Switcheroo*/, 26884 /*Researching the Corruption*/, 26881 /*In Search of Aluwyn*/, 26883 /*Twilight Falls*/, 26885 /*Knowledge in the Deeps*/, 27968 /*Fury of the Pack*/, 27921 /*Fighting Tooth and Claw*/, 27920 /*Armored to the Teeth*/, 27917 /*Sniffing Them Out*/, 14095 /*Identifying the Remains*/, 14108 /*Get Kraken!*/, 11076 /*Picking Up The Pieces...*/, 11055 /*The Booterang: A Cure For The Common Worthless Peon*/, 11015 /*Netherwing Crystals*/, 14092 /*Breakfast Of Champions*/, 28064 /*Welcome to the Brotherhood*/, 28061 /*Minions of Calcinder*/, 28062 /*From Whence He Came*/, 28060 /*Twisted Twilight Ties*/, 28057 /*Kill 'em With Sleep Deprivation*/, 28056 /*Rise, Obsidion*/, 28055 /*Sweet, Horrible Freedom*/, 28054 /*Slavery is Bad*/, 28052 /*Operation: Stir the Cauldron*/, 28035 /*The Mountain-Lord's Support*/, 28034 /*Lunk's Adventure: Rendan's Weakness*/, 28033 /*Deceit*/, 28032 /*The Mysteries of the Fire-Gizzard*/, 28030 /*They Build a Better Bullet*/, 28029 /*Set Them Ablaze!*/, 28028 /*Siege!*/, 27986 /*In the Hall of the Mountain-Lord*/, 27985 /*Prayer to Elune*/, 27984 /*Lunthistle's Tale*/, 27982 /*Twilight Collars*/, 27979 /*Dark Ministry*/, 27983 /*Lunk's Adventure: Cranky Little Dwarfs*/, 27977 /*Recon Essentials*/, 27981 /*Heat That Just Don't Quit*/, 27976 /*Curse These Fat Fingers*/, 28099 /*Rasha'krak*/, 27470 /*A Potential Ally*/, 27980 /*The Spiders Have to Go*/, 27965 /*Thorium Point: The Seat of the Brotherhood*/, 27959 /*Lunk's Adventure: Spider Rider*/, 27958 /*A Proper Antivenom*/, 27964 /*Dig-Boss Dinwhisker*/, 27962 /*A Lumbering Relic*/, 27961 /*Out of Place*/, 27963 /*A New Master... But Who?*/, 27960 /*The Fewer, the Better*/, 27956 /*Lunk's Task*/, 11054 /*Overseeing and You: Making the Right Choices*/, 28390 /*Glop, Son of Glop*/, 27051 /*Through Persistence*/, 13611 /*Mimiron's Sigil*/, 13610 /*Thorim's Sigil*/, 13609 /*Hodir's Sigil*/, 13606 /*Freya's Sigil*/, 13607 /*The Celestial Planetarium*/, 13631 /*All Is Well That Ends Well*/, 13604 /*Archivum Data Disc*/, 14105 /*Deathspeaker Kharos*/, 13180 /*Slay them all!*/, 13183 /*Victory in Wintergrasp*/, 10341 /*Kick Them While They're Down*/, 10338 /*Shutting Down Manaforge Duro*/, 10310 /*Sabotage the Warp-Gate!*/, 10433 /*Keeping Up Appearances*/, 10348 /*New Opportunities*/, 10417 /*Run a Diagnostic!*/, 10267 /*Rightful Repossession*/, 10311 /*Drijya Needs Your Help*/, 10234 /*One Demon's Trash...*/, 10257 /*Capturing the Keystone*/, 10256 /*Finding the Keymaster*/, 10200 /*Return to Thalodien*/, 10176 /*Ar'kelos the Guardian*/, 30097 /*Archival Purposes*/, 30096 /*Murozond*/, 29388 /*Guardians of Hyjal: Firelands Invasion!*/, 29157 /*The Zandalari Menace*/, 29440 /*The Call of the World-Shaman*/, 13771 /*A Valiant's Field Training*/, 13769 /*A Worthy Weapon*/, 13857 /*At The Enemy's Gates*/, 13772 /*The Grand Melee*/, 13385 /*Heroic Judgment at the Eye of Eternity*/, 13375 /*The Heroic Key to the Focusing Iris*/, 10733 /*Down the Violet Path*/, 24429 /*A Most Puzzling Circumstance*/, 14017 /*The Black Knight's Fate*/, 14016 /*The Black Knight's Curse*/, 13664 /*The Black Knight's Fall*/, 13663 /*The Black Knight's Orders*/, 13276 /*That's Abominable!*/, 13368 /*No Rest For The Wicked*/, 13365 /*Not a Bug*/, 13353 /*Drag and Drop*/, 13654 /*There's Something About the Squire*/, 13643 /*The Stories Dead Men Tell*/, 13641 /*The Seer's Crystal*/, 13634 /*The Black Knight of Silverpine?*/, 13794 /*Eadric the Pure*/, 13720 /*The Valiant's Charge*/, 13709 /*Valiant Of Thunder Bluff*/, 13740 /*A Champion Rises*/, 13731 /*The Valiant's Challenge*/, 13859 /*At The Enemy's Gates*/, 13787 /*The Grand Melee*/, 13784 /*A Worthy Weapon*/, 13786 /*A Valiant's Field Training*/, 13836 /*Disarmed!*/, 11954 /*Striking Back*/, 12012 /*Inform the Elder*/, 11891 /*An Innocent Disguise*/, 11925 /*More Torch Catching*/, 11926 /*More Torch Tossing*/, 11933 /*Stealing the Exodar's Flame*/, 9332 /*Stealing Darnassus's Flame*/, 9331 /*Stealing Ironforge's Flame*/, 9330 /*Stealing Stormwind's Flame*/, 11667 /*The One That Got Away*/, 13783 /*A Blade Fit For A Champion*/, 24582 /*Instructor Razuvious Must Die!*/, 13046 /*Feeding Arngrim*/, 13006 /*Polishing the Helm*/, 12994 /*Spy Hunter*/, 12977 /*Blowing Hodir's Horn*/, 12981 /*Hot and Cold*/, 9893 /*Obsidian Warbeads*/, 29031 /*Honor the Flame*/, 9913 /*The Consortium Needs You!*/, 11972 /*Shards of Ahune*/, 13047 /*The Reckoning*/, 13035 /*Loken's Lackeys*/, 13005 /*The Earthen Oath*/, 13057 /*The Terrace of the Makers*/, 12953 /*Valkyrion Must Burn*/, 13010 /*Krolmir, Hammer of Storms*/, 12968 /*Yulda's Folly*/, 12942 /*Off With Their Black Wings*/, 12925 /*Aberrations*/, 13051 /*Territorial Trespass*/, 13050 /*Veranus*/, 13003 /*Thrusting Hodir's Spear*/, 12987 /*Mounting Hodir's Helm*/, 12976 /*A Monument to the Fallen*/, 12975 /*In Memoriam*/, 13009 /*A New Beginning*/, 12985 /*Forging a Head*/, 13420 /*Everfrost*/, 12967 /*Battling the Elements*/, 13001 /*Raising Hodir's Spear*/, 13011 /*Jormuttar is Soo Fat...*/, 12966 /*You Can't Miss Him*/, 12924 /*Forging an Alliance*/, 12956 /*A Spark of Hope*/, 12922 /*The Refiner's Fire*/, 12915 /*Mending Fences*/, 13064 /*Sibling Rivalry*/, 12886 /*The Drakkensryd*/, 13423 /*Defending Your Title*/, 13062 /*Lok'lira's Parting Gift*/, 13061 /*Prepare for Glory*/, 12997 /*Into the Pit*/, 12996 /*The Warm-Up */, 12989 /*The Slithering Darkness*/, 12983 /*The Last of Her Kind*/, 12900 /*Making a Harness*/, 13063 /*Deemed Worthy*/, 12856 /*Cold Hearted*/, 12851 /*Going Bearback*/, 12972 /*You'll Need a Bear*/, 12971 /*Taking on All Challengers*/, 12970 /*The Hyldsmeet*/, 12969 /*Is That Your Goblin?*/, 12921 /*A Change of Scenery*/, 12908 /*A Certain Prisoner*/, 12907 /*Examples to be Made*/, 12906 /*Discipline*/, 12905 /*Mildred the Cruel*/, 12841 /*The Crone's Bargain*/, 13722 /*The Valiant's Charge*/, 13696 /*A Valiant Of Silvermoon*/, 13680 /*The Aspirant's Challenge*/, 13058 /*Changing the Wind's Course*/, 13049 /*The Hero's Arms*/, 13048 /*Where Time Went Wrong*/, 13038 /*Distortions in Time*/, 13037 /*Memories of Stormhoof*/, 13034 /*The Witness and the Hero*/, 13007 /*The Iron Colossus*/, 12998 /*The Heart of the Storm*/, 12993 /*A Colossal Threat*/, 12991 /*Hit Them Where it Hurts*/, 12988 /*Destroy the Forges!*/, 12984 /*Valduran the Stormborn*/, 12980 /*The Armor's Secrets*/, 12979 /*Armor of Darkness*/, 12664 /*Dark Horizon*/, 12661 /*Infiltrating Voltarus*/, 12652 /*Feedin' Da Goolz*/, 12648 /*Dressing Down*/, 12629 /*You Can Run, But You Can't Hide*/, 12637 /*Near Miss*/, 12631 /*An Invitation, of Sorts...*/, 29282 /*Well Armed*/, 29320 /*Like Pike?*/, 29334 /*Roach Coach*/, 24622 /*A Troll's Truest Companion*/, 25037 /*Crab Fishin'*/, 25064 /*Moraya*/, 24781 /*More Than Expected*/, 24778 /*The Arts of a Hunter*/, 24780 /*Proving Pit*/, 24779 /*A Rough Start*/, 24777 /*The Basics: Hitting Things*/, 24776 /*The Rise of the Darkspear*/, 29317 /*Fish Head*/, 29364 /*Corn Mash*/, 13845 /*Sealed Vial of Poison*/, 29284 /*Aid of the Ancients*/, 29311 /*The Rest is History*/, 29310 /*The Tipping Point*/, 29303 /*Tragedy and Family*/, 29302 /*Unlocking the Secrets Within*/, 29348 /*The Race to Restock*/, 29365 /*Perfectly Picked Portions*/, 29298 /*A Smoke-Stained Locket*/, 29281 /*Additional Armaments*/, 29280 /*Nourishing Waters*/, 29248 /*Releasing the Pressure*/, 26840 /*Return to the Highlands*/, 26830 /*Traitor's Bait*/, 26798 /*Saurfang Will be Pleased*/, 26784 /*Muddied Waters*/, 26788 /*Cementing Our Victory*/, 26786 /*Securing the Beach Head*/, 26622 /*Death to Mor'ghor*/, 26621 /*Insurrection*/, 26619 /*You Say You Want a Revolution*/, 26608 /*Negotiations Terminated*/, 26540 /*Dangerous Compassion*/, 26549 /*Madness*/, 26538 /*Emergency Aid*/, 26539 /*Stalled Negotiations*/, 26388 /*Twilight Skies*/, 28849 /*Twilight Skies*/, 26372 /*Pre-Flight Checklist*/, 26337 /*Beating the Market*/, 26361 /*Smoot's Samophlange*/, 26335 /*Ready the Navy*/, 26358 /*Ready the Air Force*/, 26374 /*Ready the Ground Troops*/, 26324 /*Where Is My Warfleet?*/, 26294 /*Weapons of Mass Dysfunction*/, 26311 /*Unfamiliar Waters*/, 26293 /*Machines of War*/, 28717 /*Warchief's Command: Twilight Highlands!*/, 7787 /*Rise, Thunderfury!*/, 26382 /*Can't Make An Omelette Without...*/, 26225 /*Pupellyverbos Port*/, 26290 /*Secrets of the Tower*/, 26289 /*Find Agent Kearnen*/, 26288 /*Jango Spothide*/, 26286 /*In Defense of Westfall*/, 26371 /*The Legend of Captain Grayson*/, 26287 /*The Westfall Brigade*/, 26271 /*Feeding the Hungry and the Hopeless*/, 26266 /*Hope for the People*/, 26270 /*You Have Our Thanks*/, 26257 /*It's Alive!*/, 26252 /*Heart of the Watcher*/, 26241 /*Westfall Stew*/, 26237 /*Times are Tough*/, 26236 /*Shakedown at the Saldean's*/, 26232 /*Lou's Parting Thoughts*/, 26229 /*"I TAKE Candle!"*/, 26228 /*Livin' the Life*/, 26215 /*Meet Two-Shoed Lou*/, 26353 /*Captain Sanders' Hidden Treasure*/, 26214 /*Hot On the Trail: Murlocs*/, 26213 /*Hot On the Trail: The Riverpaw Clan*/, 26209 /*Murder Was The Case That They Gave Me*/, 13964 /*To the Spire*/, 13965 /*Check in on the Edunes*/, 26480 /*Dartol's Rod*/, 26479 /*Return to Raene*/, 26478 /*Playing Possum*/, 26477 /*Search the Bole*/, 26454 /*A Shameful Waste*/, 13874 /*A Not-So-Charmed Life*/, 26476 /*Dryad Delivery*/, 13872 /*Worgen Wisdom*/, 13981 /*They Set Them Up The Bomb!*/, 26456 /*Report from the Northern Front*/, 13924 /*All's Well*/, 13935 /*Defend the Tree!*/, 13928 /*Recover the Fallen*/, 13922 /*In the Hands of the Perverse*/, 13868 /*Corrupting Influence?*/, 13921 /*He Who Would Be Forgiven*/, 13919 /*A Trip to the Moonwell*/, 13853 /*Return Fire*/, 26475 /*Elune's Tear*/, 13867 /*Culling the Furbolg Threat*/, 13849 /*Astranaar's Burning!*/, 26453 /*A Helping Hand*/, 13646 /*Astranaar Bound*/, 13645 /*To Raene Wolfrunner*/, 26474 /*Orendil's Cure*/, 13626 /*Respect for the Fallen*/, 13644 /*That Which Has Risen*/, 26464 /*The Lost Gem*/, 13624 /*A Squad of Your Own*/, 13632 /*Rear Guard Duty*/, 13630 /*The Reason Why*/, 26463 /*Finding Teronis*/, 13642 /*Bathed in Light*/, 26466 /*Ruuzel*/, 26897 /*Blackfathom Deeps*/, 13602 /*Naga of the Strand*/, 26465 /*The Ancient Statuettes*/, 13617 /*West to the Strand*/, 13623 /*Delivery for Orendil*/, 13595 /*Of Their Own Design*/, 26473 /*Bathran's Hair*/, 13594 /*Don't Forget the Horde*/, 9740 /*The Sun Gate*/, 9746 /*Limits of Physical Exhaustion*/, 9748 /*Don't Drink the Water*/, 9703 /*The Cryo-Core*/, 9700 /*I Shoot Magic Into the Darkness*/, 9699 /*Truth or Fiction*/, 9760 /*Vindicator's Rest*/, 9756 /*What We Don't Know...*/, 9779 /*Intercepting the Message*/, 9753 /*What We Know...*/, 9647 /*Culling the Flutterers*/, 9669 /*The Missing Expedition*/, 10064 /*Talk to the Hand*/, 9585 /*The Final Sample*/, 9550 /*A Map to Where?*/, 9549 /*Artifacts of the Blacksilt*/, 9548 /*Pilfered Equipment*/, 9579 /*Galaen's Fate*/, 9584 /*The Second Sample*/, 9628 /*Salvaging the Data*/, 9672 /*The Bloodcurse Legacy*/, 9580 /*The Bear Necessities*/, 9643 /*Constrictor Vines*/, 9632 /*Newfound Allies*/, 9620 /*The Missing Survey Team*/, 9649 /*Ysera's Tears*/, 9578 /*Searching for Galaen*/, 9574 /*Victims of Corruption*/, 9569 /*Containing the Threat*/, 9594 /*Signs of the Legion*/, 9576 /*Cruelfin's Necklace*/, 10063 /*Explorers' League, Is That Something for Gnomes?*/, 9646 /*WANTED: Deathclaw*/, 9567 /*Know Thine Enemy*/, 9629 /*Catch and Release*/, 9648 /*Mac'Aree Mushroom Menagerie*/, 9641 /*Irradiated Crystal Shards*/, 9694 /*Blood Watch*/, 9581 /*Learning from the Crystals*/, 9693 /*What Argus Means to Me*/, 9668 /*Report to Exarch Admetius*/, 9667 /*Saving Princess Stillpine*/, 9666 /*Declaration of Power*/, 9663 /*The Kessel Run*/, 9624 /*A Favorite Treat*/, 9634 /*Alien Predators*/, 9616 /*Bandits!*/, 9144 /*Missing in the Ghostlands*/, 9359 /*Farstrider Retreat*/, 9067 /*The Party Never Ends*/, 9076 /*Wretched Ringleader*/, 8887 /*Captain Kelisendra's Lost Rutters*/, 8480 /*Lost Armaments*/, 8886 /*Grimscale Pirates!*/, 9253 /*Runewarden Deryan*/, 9252 /*Defending Fairbreeze Village*/, 9135 /*Return to Sathiel*/, 9134 /*Skymistress Gloaming*/, 9133 /*Fly to Silvermoon City*/, 8491 /*Pelt Collection*/, 9254 /*The Wayward Apprentice*/, 9395 /*Saltheril's Haven*/, 9258 /*The Scorched Grove*/, 9358 /*Ranger Sareyn*/, 9130 /*Goods from Silvermoon City*/, 8892 /*Situation at Sunsail Anchorage*/, 9256 /*Fairbreeze Village*/, 8483 /*The Dwarven Spy*/, 8482 /*Incriminating Documents*/, 8486 /*Arcane Instability*/, 9066 /*Swift Discipline*/, 8475 /*The Dead Scar*/, 9064 /*Taking the Fall*/, 9062 /*Soaked Pages*/, 9035 /*Roadside Ambush*/, 9119 /*Malfunction at the West Sanctum*/, 9352 /*Darnassian Intrusions*/, 8895 /*Delivery to the North Sanctum*/, 8463 /*Unstable Mana Crystals*/, 8468 /*Wanted: Thaelis the Hungerer*/, 8472 /*Major Malfunction*/, 10069 /*Ways of the Light*/, 9676 /*Paladin Training*/, 27399 /*The Battle Is Won, The War Goes On*/, 9720 /*Balance Must Be Preserved*/, 29566 /*Checking Up*/, 9718 /*As the Crow Flies*/, 9716 /*Disturbance at Umbrafen Lake*/, 9817 /*Leader of the Bloodscale*/, 9730 /*Leader of the Darkcrest*/, 27940 /*Dirty Birds*/, 27661 /*Fire the Cannon*/, 27703 /*Coup de Grace*/, 27701 /*Dragon, Unchained*/, 27662 /*Unbinding*/, 27660 /*Spirit of the Loch*/, 27659 /*Portal Overload*/, 27696 /*The Elementium Axe*/, 27689 /*Distract Them for Me*/, 27658 /*Help from the Earthcaller*/, 27655 /*Bring the Hammer Down*/, 27653 /*Dark Assassins*/, 27638 /*Just You and Garona*/, 27503 /*Up to the Citadel*/, 27501 /*Four Heads are Better than None*/, 27499 /*Signal the Attack*/, 27495 /*Move the Mountain*/, 27491 /*Kor'kron Drop*/, 27497 /*Call in the Artillery*/, 27493 /*Ogres & Ettins*/, 28249 /*Crushblow*/, 28247 /*Last of Her Kind*/, 28176 /*Following the Young Home*/, 28175 /*Shining Through the Dark*/, 28173 /*Blackout*/, 28191 /*A Fitting End*/, 28171 /*And the Sky Streaked Red*/, 28758 /*Battle of Life and Death*/, 28712 /*Enter the Dragon Queen*/, 28093 /*Pressing Forward*/, 28094 /*Paving the Way*/, 28092 /*If The Key Fits*/, 28097 /*The Gates of Grim Batol*/, 24535 /*Thalorien Dawnseeker*/, 10012 /*Fel Orc Plans*/, 10022 /*The Elusive Ironjaw*/, 10002 /*The Firewing Liaison*/, 10007 /*Thinning the Ranks*/, 9996 /*Attack on Firewing Point*/, 29575 /*Undercutting the Competition*/, 29573 /*Safety is Job One*/, 29574 /*Intriguing Specimens*/, 10863 /*Secrets of the Arakkoa*/, 10869 /*Thin the Flock*/, 10038 /*Speak with Private Weeks*/, 9992 /*Olemba Seeds*/, 9998 /*Unruly Neighbors*/, 10016 /*Timber Worg Tails*/, 9986 /*Stymying the Arakkoa*/, 29583 /*Eckert the Mad*/, 10444 /*Report to the Allerian Post*/, 9994 /*What Are These Things?*/, 9990 /*Investigate Tuurem*/, 10881 /*The Shadow Tomb*/, 10880 /*Cabal Orders*/, 10852 /*Missing Friends*/, 10839 /*Veil Skith: Darkstone of Terokk*/, 10035 /*Torgos!*/, 29607 /*Eyes of Desire*/, 29605 /*Brother Against Brother*/, 29606 /*Terokk's Legacy*/, 29598 /*Taretha's Diversion*/, 10042 /*Kill the Shadow Council!*/, 29591 /*Raging Spirits*/, 29590 /*The Dead Watcher*/, 29596 /*The End of the Exarch*/, 10028 /*Vessels of Power*/, 10005 /*Letting Earthbinder Tavgren Know*/, 10040 /*Who Are They?*/, 10923 /*Evil Draws Near*/, 10877 /*The Dread Relic*/, 10251 /*The Master's Grand Design?*/, 10874 /*Veil Shalas: Signal Fires*/, 10887 /*Escaping the Tomb*/, 10446 /*The Final Code*/, 24476 /*Tempering The Blade*/, 8309 /*Glyph Chasing*/, 8310 /*Breaking the Code*/, 28865 /*Call of the Warmatron*/, 14482 /*Call of Duty*/, 28514 /*Mouton Flamestar*/, 24461 /*Reforging The Sword*/, 11657 /*Torch Catching*/, 29092 /*Inform the Elder*/, 11882 /*Playing with Fire*/, 11935 /*Stealing Silvermoon's Flame*/, 9326 /*Stealing the Undercity's Flame*/, 25546 /*Traveling on Our Stomachs*/, 25357 /*Buy Us Some Time*/, 25405 /*Rest For the Weary*/, 25281 /*Pay It Forward*/, 24432 /*Sea Legs*/, 28827 /*To the Depths*/, 28826 /*The Eye of the Storm*/, 25170 /*Cleaning Up the Coastline*/, 25167 /*Breaking the Chain*/, 25073 /*Sen'jin Village*/, 24814 /*An Ancient Enemy*/, 24813 /*Territorial Fetish*/, 24812 /*No More Mercy*/, 25035 /*Breaking the Line*/, 24626 /*Young and Vicious*/, 24624 /*Mercy for the Lost*/, 24625 /*Consort of the Sea Witch*/, 24623 /*Saving the Young*/, 24643 /*More Than Expected*/, 24640 /*The Arts of a Warrior*/, 24642 /*Proving Pit*/, 24641 /*A Rough Start*/, 24639 /*The Basics: Hitting Things*/, 24607 /*The Rise of the Darkspear*/, 13151 /*A Royal Escort*/, 13149 /*Dispelling Illusions*/, 10705 /*Seer Udalo*/, 10628 /*Akama*/, 10622 /*Proof of Allegiance*/, 10686 /*The Warden's Cage*/, 10546 /*Borak, Son of Oronok*/, 10527 /*Ar'tor, Son of Oronok*/, 10521 /*Grom'tor, Son of Oronok*/, 10519 /*The Cipher of Damnation - Truth and History*/, 10515 /*A Lesson Learned*/, 10514 /*I Was A Lot Of Things...*/, 11548 /*Your Continued Support*/, 12517 /*Rogues Deck*/, 29456 /*A Captured Banner*/, 13223 /*Defend the Siege*/, 29451 /*The Master Strategist*/, 25613 /*Do Yourself a Favor*/, 26470 /*Retaking Mystral Lake*/, 25607 /*Ze Gnomecorder*/, 13913 /*They Took Our Gnomes*/, 13979 /*The Goblin Braintrust*/, 25612 /*Return from the Firelands*/, 25617 /*Into the Maw!*/, 25355 /*Lightning in a Bottle*/, 25354 /*Sweeping the Shelf*/, 25277 /*Cleaning House*/, 25279 /*The Shrine Reclaimed*/, 25272 /*Lycanthoth the Corruptor*/, 25270 /*Howling Mad*/, 25269 /*The Voice of Lo'Gosh*/, 27721 /*Warchief's Command: Mount Hyjal!*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26380, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Bound for Kharanos
(24469, 22, 397, 0, 0, 0, 0, 0, 0, 15595), -- Hold the Line!
(1654, 6, 2, 1, 6, 0, 0, 0, 0, 15595), -- The Test of Righteousness
(25932, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- It's Raid Night Every Night
(433, 1, 5, 6, 0, 0, 0, 0, 0, 15595), -- The Public Servant
(25937, 1, 18, 1, 0, 0, 0, 0, 0, 15595), -- Priceless Treasures
(26131, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Reinforcements for Loch Modan
(29355, 396, 396, 396, 396, 0, 0, 0, 0, 15595), -- Can't Get Enough Spice Bread
(4512, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- A Little Slime Goes a Long Way
(29347, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Live Bait
(13425, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Aberrations Must Die
(14145, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- What Do You Feed a Yeti, Anyway?
(14136, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rescue at Sea
(14142, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- You've Really Done It This Time, Kul
(13811, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Among the Champions
(13862, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Battle Before The Citadel
(13809, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Threat From Above
(13810, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Taking Battle To The Enemy
(14107, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Fate Of The Fallen
(14104, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Ornolf The Scarred
(931, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Shimmering Frond
(938, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mist
(941, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Planting the Heart
(26383, 5, 1, 0, 0, 0, 60, 0, 0, 15595), -- Breaking Waves of Change
(6343, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Nyoma
(6342, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Unexpected Gift
(487, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Road to Darnassus
(486, 1, 1, 29, 0, 0, 0, 0, 0, 15595), -- Ursal the Mauler
(13946, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nature's Reprisal
(932, 2, 0, 0, 0, 500, 0, 0, 0, 15595), -- Twisted Hatred
(2459, 15, 1, 0, 0, 0, 100, 0, 0, 15595), -- Ferocitas the Dream Eater
(13945, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Resident Danger
(483, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Relics of Wakening
(930, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Glowing Fruit
(927, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Moss-twined Heart
(476, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gnarlpine Corruption
(2438, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Emerald Dreamcatcher
(6341, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- To Darnassus
(489, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Seek Redemption!
(929, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Teldrassil: The Refusal of the Aspects
(6344, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Reminders of Home
(28731, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Teldrassil: Passing Awareness
(28730, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Precious Waters
(28729, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Teldrassil: Crown of Azeroth
(28728, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Signs of Things to Come
(28727, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vile Touch
(28726, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Webwood Corruption
(28725, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Woodland Protector
(28724, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Iverron's Antidote
(28723, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Priestess of the Moon
(26948, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Moonfire
(3120, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Verdant Sigil
(28715, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Demonic Thieves
(28714, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fel Moss Corruption
(28713, 2, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Balance of Nature
(29445, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- An Intriguing Grimoire
(351, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Find OOX-17/TN!
(27071, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wrath of the Sandfury
(27076, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Breaking and Entering
(27070, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Fool's Errand
(27068, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chief Ukorz Sandscalp
(29463, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's Hammer Time
(29436, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Humanoid Cannonball
(29438, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- He Shoots, He Scores!
(29434, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tonk Commander
(29455, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Target: Turtle
(29433, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Test Your Strength
(13422, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maintaining Discipline
(14102, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mistcaller Yngvar
(27445, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- General Drakkisath, Hand of Nefarian
(27444, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The False Warchief
(27440, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trolls, Ogres, and Orcs, Oh My!
(27596, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Heart of the Mountain
(29211, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Solar Core Destruction
(29206, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into the Fire
(29205, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Forlorn Spire
(29263, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- A Bitter Pill
(29138, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Burn Victims
(29141, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Harder They Fall
(29179, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hostile Elements
(29139, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Aggressive Growth
(29255, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Embergris
(29162, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Nature's Blessing
(29128, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Protectors of Hyjal
(29161, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Those Bears Up There
(29163, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Rage Against the Flames
(25275, 25, 1, 15, 0, 0, 0, 0, 0, 15595), -- Report to the Labor Captain
(25267, 25, 11, 0, 0, 1000, 0, 0, 0, 15595), -- Message for Saurfang
(25266, 396, 397, 2, 0, 0, 0, 0, 0, 15595), -- Warchief's Emissary
(25265, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Victory!
(25251, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Final Confrontation
(25214, 274, 25, 0, 0, 0, 0, 0, 0, 15595), -- Escape Velocity
(25244, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- What Kind of Name is Candy, Anyway?
(25213, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- The Slave Pits
(25207, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Good-bye, Sweet Oil
(25202, 274, 273, 0, 0, 0, 0, 0, 0, 15595), -- The Fastest Way to His Heart
(25204, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Release the Valves
(25201, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Ultimate Footbomb Uniform
(25200, 274, 25, 0, 0, 0, 0, 0, 0, 15595), -- Shredder Shutdown
(25184, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wild Mine Cart Ride
(25125, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Light at the End of the Tunnel
(25123, 274, 0, 0, 0, 0, 0, 0, 0, 15595), -- Throw It On the Ground!
(25122, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Morale Boost
(25110, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kaja'Cola Gives You IDEAS! (TM)
(27024, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Partners in Crime
(27029, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Cure the Scourge
(27009, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- The Coldbringer
(27111, 1, 2, 0, 0, 0, 0, 0, 0, 15595), -- The Treasure of the Shen'dralar
(27110, 6, 1, 1, 2, 500, 1000, 1500, 2000, 15595), -- The Madness Within
(27113, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Shen'dralar Ancient
(27112, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Cursed Remains
(27109, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warped Defender
(29443, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Curious Crystal
(29203, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into the Depths
(29331, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Bonds: The Vow
(29330, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Bonds: Fury
(29338, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- Into Unrelenting Flame
(29329, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Bonds: Patience
(29337, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into Constant Earth
(29328, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Bonds: Desire
(29336, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Into Coaxing Tides
(29327, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Bonds: Doubt
(29335, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into Slashing Winds
(29326, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Nordrassil Summit
(28741, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ascendant Lord Obsidius
(28740, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Do My Eyes Deceive Me?
(28738, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Twilight Forge
(28737, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- What Is This Place?
(28490, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Darkshore!
(28517, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Howling Oak
(14291, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Safety in Numbers
(14283, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Moonfire
(14280, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Winds Know Your Name... Apparently
(29830, 5, 396, 396, 0, 0, 0, 0, 0, 15595), -- Containment
(29102, 396, 396, 0, 0, 0, 300, 0, 0, 15595), -- To Fort Livingston
(29100, 6, 396, 396, 0, 0, 300, 300, 0, 15595), -- Bwemba's Spirit
(25998, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Get to the Airfield
(25997, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Dark Iron Scheming
(25979, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Dealing with the Surge
(25978, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Entombed in Ice
(25986, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Trouble at the Lake
(432, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Those Blasted Troggs!
(25933, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Help for the Quarry
(314, 5, 1, 20, 0, 0, 0, 0, 0, 15595), -- Protecting the Herd
(25905, 396, 1, 0, 0, 0, 0, 0, 0, 15595), -- Rams on the Lam
(25882, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- A Hand at the Ranch
(28868, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The View from Down Here
(25841, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Strike From Above
(25840, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Eliminate the Resistance
(25839, 1, 25, 5, 0, 0, 0, 0, 0, 15595), -- The Ultrasafe Personnel Launcher
(25838, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Help from Steelgrill's Depot
(412, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Operation Recombobulation
(25792, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Pushing Forward
(25668, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Pilfered Supplies
(313, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Forced to Watch from Afar
(25667, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Culling the Wendigos
(315, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Perfect Stout
(25724, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Frostmane Aggression
(384, 1, 6, 1, 0, 0, 0, 0, 0, 15595), -- Beer Basted Boar Ribs
(6392, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Gremlock
(6388, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gryth Thurden
(6391, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ride to Ironforge
(6387, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Honor Students
(24493, 1, 3, 0, 0, 0, 0, 0, 0, 15595), -- Don't Forget About Us
(24492, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pack Your Bags
(24491, 430, 1, 25, 0, 0, 0, 0, 0, 15595), -- Follow that Gyro-Copter!
(24490, 1, 5, 6, 66, 0, 0, 0, 0, 15595), -- A Trip to Ironforge
(24489, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trolling for Information
(24487, 2, 1, 0, 0, 0, 0, 0, 0, 15595), -- Whitebeard Needs Ye
(24530, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Oh, A Hunter's Life For Me
(24475, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- All the Other Stuff
(24486, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Make Hay While the Sun Shines
(24477, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dwarven Artifacts
(24474, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- First Things First: We're Gonna Need Some Beer
(24473, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lockdown in Anvilmar
(24471, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Aid for the Wounded
(24470, 396, 397, 0, 0, 0, 0, 0, 0, 15595), -- Give 'em What-For
(29861, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Whatever it Takes!
(29860, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Diametrically Opposed
(29862, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Clearing the Way
(27022, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Extinguishing the Idol
(27019, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Scourge of the Downs
(10210, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A'dal
(10134, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crimson Crystal Clue
(9417, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Arakkoa Threat
(9325, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Thunder Bluff's Flame
(9324, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Orgrimmar's Flame
(29030, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Honor the Flame
(28783, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Source of Their Power
(28781, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Targets of Opportunity
(11316, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spawn of the Twisted Glade
(11319, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Seeds of the Blacksouled Keepers
(11418, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- We Call Him Steelfeather
(11314, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Fallen Sisters
(11315, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Wild Vines
(11313, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spirits of the Ice
(11292, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Preying Upon the Weak
(11269, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Down to the Wire
(11355, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- March of the Giants
(11346, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Book of Runes
(11302, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Enigmatic Frost Nymphs
(11284, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Yeti Next Door
(11410, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The One That Got Away
(11329, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- I'll Try Anything!
(12118, 15, 6, 1, 0, 0, 0, 0, 0, 15595), -- Travel to Moa'ki Harbor
(29811, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Gatewatcher's Talisman
(29808, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Don't Forget the Eggs!
(29807, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Death to the Traitor King
(11237, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gjalerbron Attack Plans
(11504, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Dead Rise!
(11573, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Orfus of Kamagua
(11396, 69, 30, 6, 0, 0, 2000, 0, 0, 15595), -- Bring Down Those Shields
(11395, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's a Scourge Device
(11394, 1, 5, 6, 0, 0, 0, 0, 0, 15595), -- And You Thought Murlocs Smelled Bad!
(11391, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Steel Gate Patrol
(11390, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- I've Got a Flying Machine!
(11322, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- The Cleansing
(11154, 25, 5, 20, 0, 0, 0, 0, 0, 15595), -- Scare the Guano Out of Them!
(11176, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- See to the Operations
(11393, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Where is Explorer Jaren?
(11175, 6, 1, 20, 0, 0, 0, 0, 0, 15595), -- My Daughter
(11484, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- We Have the Technology
(11483, 6, 6, 273, 1, 0, 0, 0, 0, 15595), -- We Can Rebuild It
(11477, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Out of My Element?
(11465, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Ransacked Caravan
(11460, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Trust is Earned
(11475, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Tools to Get the Job Done
(11474, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Problems on the High Bluff
(11427, 6, 1, 1, 1, 0, 0, 0, 0, 15595), -- Meet Lieutenant Icehammer...
(11291, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- To Westguard Keep!
(11251, 396, 1, 25, 1, 0, 500, 500, 0, 15595), -- Fresh Legs
(11426, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Locating the Mechanism
(11344, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Anguish of Nifflevar
(11290, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Dragonflayer Battle Plans
(11448, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Explorers' League Outpost
(11278, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Return to Valgarde
(11300, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Stunning Defeat at the Ring
(11299, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Ring of Judgment
(11289, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Guided by Honor
(11288, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Shining Light
(11277, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Depths of Depravity
(11276, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- And Then There Were Two...
(11274, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Zedd's Probably Dead
(11343, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Echo of Ymiron
(11443, 6, 1, 24, 0, 0, 0, 0, 0, 15595), -- Daggercap Divin'
(11273, 5, 1, 1, 6, 0, 0, 0, 0, 15595), -- The Human League
(11420, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Path to Payback
(11333, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Into the World of Spirits
(11255, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Prisoners of Wyrmskull
(11244, 1, 1, 1, 5, 0, 0, 0, 0, 15595); -- Rescuing the Rescuers

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11243, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- If Valgarde Falls...
(29608, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Allies in Dalaran
(11228, 5, 274, 25, 273, 0, 1000, 1000, 1000, 15595), -- Hell Has Frozen Over...
(28709, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Northrend!
(11182, 33, 0, 0, 0, 0, 0, 0, 0, 15595), -- Root Causes
(11190, 6, 5, 1, 0, 0, 0, 0, 0, 15595), -- One Size Does Not Fit All
(11155, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Shoveltusk Soup Again?
(11157, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Clutches of Evil
(29763, 0, 0, 0, 0, 0, 1000, 1000, 0, 15595), -- Stealing Their Thunder
(29764, 5, 396, 0, 0, 0, 0, 0, 0, 15595), -- Disarmament
(29803, 0, 0, 0, 0, 0, 3000, 0, 0, 15595), -- Ears of the Lich King
(11468, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Falcon Versus Hawk
(24522, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Journey To The Sunwell
(24480, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Halls Of Reflection
(27726, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Mount Hyjal!
(28825, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Personal Summons
(29864, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Working at the Source
(13131, 5, 396, 0, 0, 0, 0, 0, 0, 15595), -- Junk in My Trunk
(13132, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Vengeance Be Mine!
(13128, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- A Wing and a Prayer
(13127, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Mage-Lord Urom
(13126, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- A Unified Front
(13124, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- The Struggle Persists
(12770, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Reallocating Resources
(12249, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ursoc, the Bear God
(12250, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vordrassil's Seeds
(12248, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vordrassil's Sapling
(13207, 5, 396, 0, 0, 0, 0, 0, 0, 15595), -- Halls of Stone
(29848, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Forlorn Watcher
(29850, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Corrupt Constructs
(12296, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Life or Death
(29834, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Gal'darah Must Pay
(29839, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- One of a Kind
(29844, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- For Posterity
(30120, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- Cleansing Drak'Tharon
(29828, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- What the Scourge Dred
(13129, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Head Games
(12794, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Magical Kingdom of Dalaran
(13187, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Faceless Ones
(29826, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reclaiming Ahn'Kahet
(29825, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pupil No More
(24959, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fresh out of the Grave
(28608, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Shadow Grave
(13522, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Threat from the Water
(13518, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Last Wave of Survivors
(26385, 5, 2, 0, 0, 0, 60, 0, 0, 15595), -- Breaking Waves of Change
(14266, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Charge
(14129, 6, 0, 0, 0, 0, 0, 0, 0, 15595), -- Runaway Shredder!
(25243, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- She Loves Me, She Loves Me NOT!
(25203, 5, 29, 0, 0, 0, 0, 0, 0, 15595), -- What Kind of Name is Chip, Anyway?
(25109, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Gallywix Labor Mine
(25100, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Let's Ride
(25099, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Borrow Bastia
(25098, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warchief Wants You
(25066, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Pride of Kezan
(25058, 274, 1, 273, 6, 0, 0, 0, 0, 15595), -- Mine Disposal, the Goblin Way
(25093, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- The Heads of the SI:7
(25024, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Repel the Paratroopers
(25023, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Old Friends
(24958, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Volcanoth!
(24954, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Children of a Turtle God
(24952, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rocket Boot Boost
(24946, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rockin' Powder
(24945, 1, 5, 0, 0, 0, 1000, 0, 0, 15595), -- Three Little Pygmies
(24942, 274, 0, 0, 0, 0, 0, 0, 0, 15595), -- Zombies vs. Super Booster Rocket Boots
(24940, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Up the Volcano
(24937, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Oomlot Dealt With
(24864, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- Irresistible Pool Pony
(24859, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Naga Hide
(24858, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bilgewater Cartel Represent
(24856, 11, 1, 0, 0, 0, 0, 0, 0, 15595), -- Invasion Imminent!
(24817, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Goblin in Shark's Clothing
(24816, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Who's Top of the Food Chain Now?
(24744, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Biggest Egg Ever
(24741, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trading Up
(24671, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cluster Cluck
(27139, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hobart Needs You
(14245, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's a Town-In-A-Box
(14244, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Up, Up & Away!
(14445, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Farewell, For Now
(14243, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warchief's Revenge
(14326, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Meet Me Up Top
(14242, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Precious Cargo
(14241, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Get to the Gyrochoppa!
(14240, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Cliffs
(14238, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Infrared = Infradead
(14237, 1, 11, 0, 0, 0, 0, 0, 0, 15595), -- Forward Movement
(14303, 6, 1, 5, 0, 0, 0, 0, 0, 15595), -- Back to Aggra
(14236, 5, 0, 0, 0, 1000, 0, 0, 0, 15595), -- Weed Whacker
(14235, 1, 25, 0, 0, 0, 1000, 0, 0, 15595), -- The Vicious Vale
(14234, 6, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Enemy of My Enemy
(14233, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Orcs Can Write?
(14031, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Capturing the Unknown
(14021, 1, 25, 5, 0, 0, 0, 0, 0, 15595), -- Miner Troubles
(14248, 5, 6, 5, 0, 0, 2000, 2000, 0, 15595), -- Help Wanted
(14019, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Monkey Business
(14473, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- It's Our Problem Now
(14014, 5, 25, 0, 0, 0, 0, 0, 0, 15595), -- Get Our Stuff Back!
(14001, 5, 6, 0, 0, 0, 2000, 0, 0, 15595), -- Goblin Escape Pods
(14126, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Life Savings
(14125, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447
(14124, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Liberate the Kaja'mite
(14123, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- Waltz Right In
(14121, 5, 18, 0, 0, 0, 2000, 0, 0, 15595), -- Robbing Hoods
(14122, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Great Bank Heist
(14120, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Bazillion Macaroons?!
(14116, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Uninvited Guest
(14115, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crashers
(14113, 5, 17, 0, 0, 0, 0, 0, 0, 15595), -- Life of the Party
(14013, 34, 0, 0, 0, 0, 0, 0, 0, 15595), -- Charge
(14109, 6, 0, 0, 0, 0, 0, 0, 0, 15595), -- The New You
(24520, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Give Sassy the News
(24503, 397, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fourth and Goal
(24502, 397, 0, 0, 0, 0, 0, 0, 0, 15595), -- Necessary Roughness
(24488, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Replacements
(26712, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Off to the Bank
(14070, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Do it Yourself
(24567, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Report for Tryouts
(14071, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rolling with my Homies
(28349, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs in Marketing
(25473, 6, 5, 6, 0, 0, 0, 0, 0, 15595), -- Kaja'Cola
(14069, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Good Help is Hard to Find
(14075, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trouble in the Mines
(14138, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Taking Care of Business
(10072, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Learning the Word
(8564, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Priest Training
(8346, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Thirst Unending
(8336, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Fistful of Slivers
(8330, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Solanian's Belongings
(12978, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Facing the Storm
(12965, 5, 5, 0, 0, 0, 0, 0, 0, 15595), -- The Gifts of Loken
(12964, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Dark Ore
(12957, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Slaves of the Stormforged
(12937, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Relief for the Fallen
(12931, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fighting Back
(13112, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Infused Mushroom Meatloaf
(13426, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Xarantaur, the Witness
(13285, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Forging the Keystone
(13274, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Core's Keeper
(13273, 1, 4, 0, 0, 0, 0, 0, 0, 15595), -- Going After the Core
(12928, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Norgannon's Shell
(13416, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Library Console
(12927, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Data Mining
(12926, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Pieces of the Puzzle
(12920, 25, 5, 0, 0, 0, 0, 0, 0, 15595), -- Catching up with Brann
(12930, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rare Earth
(12917, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Speaking with the Wind's Voice
(12913, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Speak Orcish, Man!
(12910, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Sniffing Out the Perpetrator
(12909, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Nose Knows
(13056, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- There's Always Time for Revenge
(13055, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cave Medicine
(12895, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Missing Bronzebeard
(12882, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ancient Relics
(13000, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Emergency Measures
(13054, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Missing Tracker
(12846, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Leave No Goblin Behind
(13060, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- When All Else Fails
(12824, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Demolitionist Extraordinaire
(12823, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Flawless Plan
(12822, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Know No Fear
(29159, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pyrorachnophobia
(29276, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Flame Spider Queen
(29278, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Living Obsidium
(29304, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dogs of War
(29299, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Some Like It Hot
(29177, 378, 5, 0, 0, 0, 0, 0, 0, 15595), -- Vigilance on Wings
(29165, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Call of the Pack
(29166, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Supplies for the Other Side
(29164, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Perfecting Your Howl
(12821, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Opening the Backdoor
(12832, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bitter Departure
(12831, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Only Partly Forgotten
(12829, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Moving In
(12830, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ore Repossession
(12820, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Delicate Touch
(12826, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slightly Unstable
(12828, 5, 1, 0, 0, 0, 60, 0, 0, 15595), -- Ample Inspiration
(12819, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Just Around the Corner
(12844, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Equipment Recovery
(12843, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- They Took Our Men!
(12827, 5, 1, 0, 0, 0, 60, 0, 0, 15595), -- Reclaimed Rations
(12836, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Expression of Gratitude
(12818, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Clean Up
(29833, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Unfinished Business
(12730, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Convocation at Zol'Heb
(12729, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- The Gods Have Spoken
(12721, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rampage
(12707, 25, 5, 1, 1, 0, 0, 0, 0, 15595), -- Wooly Justice
(12708, 1, 1, 5, 6, 0, 0, 0, 0, 15595), -- Enchanted Tiki Warriors
(12712, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Key of Warlord Zol'Maz
(12709, 1, 1, 6, 2, 0, 0, 0, 0, 15595), -- Hexed Caches
(12685, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- You Reap What You Sow
(12684, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood of a Dead God
(12675, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- One Last Thing
(12674, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hell Hath a Fury
(12668, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Foundation for Revenge
(12672, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Setting the Stage
(12667, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Seek the Wind Serpent Goddess
(12666, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Preparations for the Underworld
(12665, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- I Sense a Disturbance
(12653, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Back to Har'koa
(12647, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- An End to the Suffering
(12646, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- My Prophet, My Enemy
(12662, 6, 274, 25, 1, 2000, 0, 0, 0, 15595), -- Bringing Down Heb'Jin
(12659, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Scalps!
(28692, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magnets, How Do They Work?
(28691, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- First Lieutenant Connor
(28686, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Not The Friendliest Town
(28685, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Leave No Weapon Behind
(28684, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Sticky Task
(28694, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Watch Out For Splinters!
(10201, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- And Now, the Moment of Truth
(11669, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Felblood Fillet
(9832, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Second and Third Fragments
(13116, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mustard Dogs!
(12639, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Frozen Earth
(12640, 25, 5, 0, 0, 0, 0, 0, 0, 15595), -- Sealing the Rifts
(12655, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Blessing of Zim'Rhuk
(13549, 1, 1, 6, 25, 0, 0, 0, 0, 15595), -- Tails Up
(12650, 1, 1, 273, 0, 0, 0, 0, 0, 15595), -- Plundering Their Own
(12642, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spirit of Rhunok
(12632, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- But First My Offspring
(12635, 2, 1, 6, 0, 0, 0, 0, 0, 15595), -- Relics of the Snow Leopard Goddess
(12628, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- To Speak With Har'koa
(12555, 5, 1, 273, 0, 0, 0, 0, 0, 15595), -- A Tangled Skein
(12584, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Pure Evil
(12583, 1, 6, 29, 0, 0, 0, 0, 0, 15595), -- Crashed Sprayer
(12554, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Malas the Corrupter
(12552, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- Death to the Necromagi
(12553, 6, 1, 274, 1, 0, 0, 0, 0, 15595), -- Skimmer Spinnerets
(12606, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Cocooned!
(12598, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- Throwing Down
(12512, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Leave No One Behind
(12599, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Creature Comforts
(12557, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Lab Work
(12610, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Clipping Their Wings
(12609, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Stocking the Shelves
(12799, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Siphoning the Spirits
(12622, 6, 11, 1, 0, 0, 0, 0, 0, 15595), -- The Leaders at Jin'Alai
(12615, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Blessing of Zim'Torga
(12627, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- Breaking Through Jin'Alai
(12527, 1, 6, 5, 0, 0, 0, 0, 0, 15595), -- Gluttonous Lurkers
(12500, 1, 1, 2, 0, 0, 0, 0, 0, 15595), -- Return To Angrathar
(12496, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Audience With The Dragon Queen
(12224, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Kor'kron Vanguard!
(29148, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Wings Aflame
(29147, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- Call the Flock
(29149, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Rage Against the Flames
(9831, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Entry Into Karazhan

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29642, 1, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Trouble at Auchindoun
(11514, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maintaining the Sunwell Portal
(11877, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Sunfury Attack Plans
(13676, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training In The Field
(13677, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Learning The Reins
(13674, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Worthy Weapon
(28690, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Salvaging the Remains
(28683, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thinning the Brood
(28679, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rattling Their Cages
(28697, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ghostbuster
(13114, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sewer Stew
(29143, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wisp Away
(11003, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Fall of Magtheridon
(13384, 1, 274, 25, 0, 0, 0, 2000, 0, 15595), -- Judgment at the Eye of Eternity
(13372, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Key to the Focusing Iris
(12623, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- To the Witch Doctor
(12516, 1, 1, 6, 25, 0, 0, 0, 0, 15595), -- Too Much of a Good Thing
(12508, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Mopping Up
(12504, 6, 1, 1, 1, 2000, 0, 0, 0, 15595), -- Argent Crusade, We Are Leaving!
(12514, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Mushroom Mixer
(12510, 1, 1, 1, 1, 2000, 0, 0, 0, 15595), -- Precious Elemental Fluids
(12565, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Blessing of Zim'Abwa
(12506, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Trouble at the Altar of Sseratus
(12597, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Something for the Pain
(12596, 1, 5, 6, 1, 0, 0, 0, 0, 15595), -- Pa'Troll
(12505, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- New Orders for Sergeant Stackhammer
(12562, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Drakkari Do Not Need Water Elementals!
(12740, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Parachutes for the Argent Crusade
(12503, 1, 6, 25, 1, 0, 0, 0, 0, 15595), -- Defend the Stand
(12919, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Storm King's Vengeance
(12916, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Our Only Hope
(12914, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Gymer's Salvation
(12912, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- A Great Storm Approaches
(12904, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Light Won't Grant Me Vengeance
(12795, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Taking a Stand
(12630, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Kickin' Nass and Takin' Manes
(12713, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Betrayal
(12710, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Disclosure
(12690, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fuel for the Fire
(12676, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sabotage
(12686, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Zero Tolerance
(12677, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hazardous Materials
(12673, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It Rolls Downhill
(12669, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- So Far, So Bad
(29315, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fungus Among Us
(25012, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Take to the Skies
(25011, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- To Bigger and Better Things
(29446, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Wondrous Weapon
(25046, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Daughter's Embrace
(25013, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Little Oomph
(25010, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Deadly New Ally
(27998, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sweet, Merciless Revenge
(27996, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Orders Are For the Living
(27988, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Plague...Plague Everywhere!
(27974, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- This Land is Our Land
(25009, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- At War With The Scarlet Crusade
(25056, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Grisly Grizzlies
(12433, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Seeking Solvent
(12058, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Runic Prophecies
(12073, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Pounding the Iron
(12054, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Deciphering the Journal
(12026, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Damaged Journal
(12431, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Conquest Pit: Final Showdown
(12430, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Conquest Pit: Death Is Likely
(12429, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Conquest Pit: Blood and Metal
(12428, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Conquest Pit: Mad Furbolg Fighting
(12427, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Conquest Pit: Bear Wrestling!
(12178, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Delivery to Krenna
(12203, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Loken's Orders
(12202, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Cultivating an Image
(12201, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Overseer's Shadow
(12204, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- In the Name of Loken
(12199, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Bringing Down the Iron Thane
(12198, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- ... Or Maybe We Don't
(12197, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- We Have the Power
(12196, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- From the Ground Up
(13673, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Blade Fit For A Champion
(13678, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Up To The Challenge
(13838, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Mastery Of The Shield-Breaker
(13839, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Mastery Of The Charge
(13829, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Mastery Of Melee
(9544, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Prophecy of Akida
(9542, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totem of Vark
(9541, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totem of Yor
(9540, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totem of Tikti
(9539, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totem of Coo
(9538, 5, 1, 1, 5, 0, 0, 0, 0, 15595), -- Learning the Language
(28559, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Bloodmyst Isle!
(14039, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Home of the Kaldorei
(935, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Waters of Teldrassil
(14005, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Vengeance of Elune
(2561, 2, 0, 0, 0, 0, 0, 0, 0, 15595), -- Druid of the Claw
(2541, 2, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Sleeping Druid
(28659, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Leftovers
(28657, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Huge Problem
(28658, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Swamp Bait
(28662, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Learning From The Past
(28661, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Imprisoned Archmage
(28660, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Clearing the Depths
(29243, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strike at the Heart
(29275, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Fandral's Methods
(29210, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Enduring the Heat
(29160, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Egg-stinction
(29297, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bye Bye Burdy
(29192, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Wardens are Watching
(29257, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Steal Magmolias
(29122, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Echoes of Nemesis
(29101, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Punting Season
(28682, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Claiming The Keep
(28700, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Taking the Overlook Back
(29189, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wicked Webs
(29142, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Traitors Return
(29126, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Power of Malorne
(29127, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Rage Against the Flames
(29125, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Between the Trees
(28687, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Teach A Man To Fish.... Or Steal
(28695, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- WANTED: Foreman Wellson
(13115, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cheese for Glowergold
(28884, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Victory in Tol Barad
(28681, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shark Tank
(28680, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Boosting Morale
(12236, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ursoc, the Bear God
(12213, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Darkness Beneath
(12207, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vordrassil's Fall
(12425, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ruuna the Blind
(12453, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Eyes Above
(12422, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tactical Clemency
(12424, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gorgonna
(12413, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Attack on Silverbrook
(12423, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mikhail's Journal
(12412, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- My Enemy's Friend
(12451, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Onward to Camp Oneqwah
(12259, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Thane of Voldrune
(12177, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jun'ik's Coverup
(12257, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Show of Strength
(12256, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Flamebinders' Secrets
(12176, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Minor Substitution
(28693, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Finish The Job
(13113, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Convention at the Legerdemain
(12112, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stiff Negotiations
(13343, 5, 25, 1, 5, 0, 2000, 0, 0, 15595), -- Mystery of the Infinite, Redux
(12273, 5, 25, 1, 1, 0, 0, 0, 0, 15595), -- The Denouncement
(12285, 1, 25, 1, 5, 0, 0, 0, 0, 15595), -- Do Unto Others
(12283, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Truth Will Out
(12274, 1, 1, 5, 1, 0, 0, 1000, 0, 15595), -- A Fall From Grace
(12260, 6, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Perfect Dissemblance
(12271, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Rod of Compulsion
(12254, 1, 1, 1, 6, 0, 0, 0, 0, 15595), -- Without a Prayer
(12239, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Spy in New Hearthglen
(12252, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Torture the Torturer
(12245, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- No Mercy for the Captured
(12234, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Need to Know
(12214, 3, 1, 6, 1, 0, 0, 0, 0, 15595), -- Fresh Remounts
(12243, 25, 1, 5, 11, 0, 0, 0, 0, 15595), -- Fire Upon the Waters
(12240, 1, 1, 1, 6, 0, 0, 0, 0, 15595), -- A Means to an End
(12221, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Forsaken Blight
(12232, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bombard the Ballistae
(12230, 5, 1, 25, 1, 0, 0, 0, 0, 15595), -- Stealing from the Siegesmiths
(12218, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Spread the Good Word
(12200, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Emerald Dragon Tears
(12211, 274, 1, 1, 25, 0, 0, 0, 0, 15595), -- Let Them Not Rise!
(12205, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wanted: The Scarlet Onslaught
(12209, 6, 1, 1, 6, 0, 0, 0, 0, 15595), -- Materiel Plunder
(12124, 273, 1, 1, 0, 2000, 0, 0, 0, 15595), -- Informing the Queen
(12769, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Steward of Wyrmrest Temple
(12450, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Through Fields of Flame
(12449, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to the Earth
(12448, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Heated Battle
(12461, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Report to the Ruby Dragonshrine
(12767, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Speak with your Ambassador
(12122, 5, 1, 1, 2, 0, 0, 0, 0, 15595), -- Gaining an Audience
(12110, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The End of the Line
(12106, 1, 6, 5, 0, 0, 0, 0, 0, 15595), -- Search Indu'le Village
(12085, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Letter for Home
(12096, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Strengthen the Ancients
(12084, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Atop the Woodlands
(12066, 1, 6, 1, 0, 0, 0, 0, 0, 15595), -- The Focus on the Beach
(12061, 1, 1, 25, 1, 0, 0, 0, 0, 15595), -- Projections and Plans
(12059, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Strange Device
(12136, 1, 1, 2, 0, 0, 0, 0, 0, 15595), -- The Translated Tome
(12132, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Power to Destroy
(12147, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Disturbing Implications
(12145, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Canyon Chase
(12144, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pest Control
(12097, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Sarathstra, Scourge of the North
(26013, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Assault on the Sanctum
(12127, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- In Service of Frost
(12126, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- In Service of the Unholy
(12125, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- In Service of Blood
(12111, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Where the Wild Things Roam
(12095, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- To Dragon's Fall
(12104, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Return to Soar
(12304, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Beachfront Property
(12115, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Koltira and the Language of Death
(12140, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- All Hail Roanauk!
(12072, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Blightbeasts be Damned!
(12071, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Attack by Air! 
(12069, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Return of the High Chief
(12057, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Flesh-Bound Tome
(12064, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Chains of the Anub'ar
(12063, 2, 1, 20, 1, 0, 0, 0, 0, 15595), -- Strength of Icemist
(12005, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- Prevent the Accord
(12053, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- The Might of the Horde
(12102, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- In Search of the Ruby Lilac
(12048, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Scourge Armaments
(12101, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Good Doctor...
(12056, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Marked for Death: High Cultist Zangus
(12100, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Containing the Rot
(12039, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Black Blood of Yogg-Saron
(12036, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- From the Depths of Azjol-Nerub
(12091, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wanted: Dreadtalon
(12090, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wanted: Gigantaur
(12089, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wanted: Magister Keldonus
(12033, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Message from the West
(12034, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Victory Nears...
(11999, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rifle the Bodies
(12008, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Agmar's Hammer
(11983, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Blood Oath of the Horde
(11978, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Into the Fold
(11980, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Pride of the Horde
(29137, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Breach in the Defenses
(2499, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Oakenscowl
(933, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Teldrassil: The Coming Dawn
(923, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mossy Tumors
(353, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stormpike's Delivery
(28562, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Westfall!
(7905, 5, 1, 5, 0, 0, 0, 0, 0, 15595), -- The Darkmoon Faire
(27865, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Crucible of Carnage: The Wayward Wildhammer!
(27863, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Crucible of Carnage: The Bloodeye Bruiser!
(26233, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Stealing From Our Own
(11423, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Enemy's Legacy
(12482, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Against Nifflevar
(11310, 11, 1, 0, 0, 0, 3000, 0, 0, 15595), -- Warning: Some Assembly Required
(26226, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Crawfish Creole
(11309, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Parts for the Job
(11308, 6, 1, 0, 0, 0, 3000, 0, 0, 15595), -- Time for Cleanup
(11307, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Field Test
(11306, 21, 1, 0, 0, 0, 3000, 0, 0, 15595), -- Apply Heat and Stir
(11280, 5, 6, 1, 0, 0, 0, 0, 0, 15595), -- Draconis Gastritis
(26227, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Careful, This Fruit Bites Back
(12481, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Adding Injury to Insult
(11424, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shield Hill
(11279, 1, 6, 25, 0, 0, 0, 0, 0, 15595), -- Green Eggs and Whelps
(11305, 6, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Tailor-Made Formula
(11303, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Ambush
(11285, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Baleheim Must Burn!
(11283, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Baleheim Bodycount
(12566, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Help for Camp Winterhoof
(11282, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Lesson in Fear
(11304, 274, 1, 0, 0, 0, 3000, 0, 0, 15595); -- New Agamand

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11295, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Offensive Begins
(11170, 11, 0, 0, 0, 0, 0, 0, 0, 15595), -- Test at Sea
(11254, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dragonskin Map
(11168, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spiking the Mix
(11234, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Report to Anselm
(11241, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trail of Fire
(11233, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- Landing the Killing Blow
(11232, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Guide Our Sights
(11230, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ambushed!
(11229, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Windrunner Fleet
(11253, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sniff Out the Enemy
(11221, 25, 1, 0, 0, 0, 300, 0, 0, 15595), -- Reports from the Field
(11167, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The New Plague
(11270, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- War is Hell
(11227, 274, 1, 0, 0, 0, 3000, 0, 0, 15595), -- Let Them Eat Crow
(11433, 1, 273, 25, 0, 0, 0, 0, 0, 15595), -- Sleeping Giants
(11453, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Slumbering King
(11268, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- The Walking Dead
(11264, 5, 25, 5, 0, 0, 0, 0, 0, 15595), -- Necro Overlord Mezhen
(11265, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Of Keys and Cages
(11263, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- Dealing With Gjalerbron
(11261, 1, 25, 6, 0, 0, 0, 0, 0, 15595), -- The Conqueror of Skorn!
(11259, 66, 1, 1, 0, 0, 0, 0, 0, 15595), -- Towers of Certain Doom
(11258, 1, 6, 66, 0, 0, 0, 0, 0, 15595), -- Burn Skorn, Burn!
(11257, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Gruesome, But Necessary
(11324, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alpha Worg
(11367, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Demolishing Megalith
(11366, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Lodestone
(11352, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Rune of Command
(11260, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stop the Ascension!
(11256, 25, 1, 66, 0, 0, 0, 0, 0, 15595), -- Skorn Must Fall!
(11417, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Eyes of the Eagle
(11415, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brother Betrayers
(11323, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- In Worg's Clothing
(11351, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mastering the Runes
(11365, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- March of the Giants
(11350, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Book of Runes
(11312, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Frozen Glade
(11281, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mimicking Nature's Call
(11311, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Suppressing the Elements
(11267, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- The Frost Wyrm and its Master
(11275, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Making the Horn
(11271, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hasty Preparations
(11266, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gjalerbron Attack Plans
(11296, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- Rivenwood Captives
(11317, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- The Cleansing
(11286, 1, 5, 6, 0, 0, 0, 0, 0, 15595), -- The Artifacts of Steel Gate
(11301, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Brains! Brains! Brains!
(11298, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- What's in That Brew?
(11397, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- And You Thought Murlocs Smelled Bad!
(11399, 69, 30, 6, 0, 0, 2000, 0, 0, 15595), -- Bring Down Those Shields
(11398, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's a Scourge Device
(11422, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trident of the Son
(12432, 5, 1, 1, 5, 0, 0, 0, 0, 15595), -- Riding the Red Rocket
(28698, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cannonball!
(28696, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bombs Away!
(26220, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Everything Is Better with Bacon
(10625, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Spectrecles
(29650, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fel Ember
(8702, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ring of Unspoken Names
(8710, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kris of Unspoken Names
(8694, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shroud of Unspoken Names
(26235, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Even Thieves Get Hungry
(7926, 5, 1, 5, 0, 0, 0, 0, 0, 15595), -- The Darkmoon Faire
(26899, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Enemy of My Enemy
(26892, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deep in the Deeps
(26888, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Nightmare of the Deeps
(26891, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Amongst the Ruins
(27850, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Defias Kingpin
(27848, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Good Intentions...Poor Execution
(27844, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Traitors!!!
(27842, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Only the Beginning
(27847, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Not Quite There
(29616, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Storming the Steamvault
(9747, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Umbrafen Tribe
(29568, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Necessary Evil
(29570, 1, 1, 0, 0, 0, 1000, 1000, 0, 15595), -- Rescuing the Expedition
(29691, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bring Me A Shrubbery!
(29567, 1, 1, 0, 0, 0, 1000, 1000, 0, 15595), -- Stalk the Stalker
(29615, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Windcaller Claw and the Water Thief
(29614, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Containment is Key
(29613, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- A Proper Fate
(29564, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- A Brother Betrayed
(29565, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Heart of the Matter
(29563, 396, 396, 0, 0, 0, 1000, 1000, 0, 15595), -- Lost in Action
(29305, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strike at the Heart
(29296, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Territorial Birds
(29287, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Peaked Interest
(29273, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- How Hot
(29264, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Flamewakers of the Molten Flow
(29265, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fire Flowers
(26862, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Elemental Tampering
(26856, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Repel the Invasion
(26858, 1, 1, 1, 4, 0, 0, 0, 0, 15595), -- Taragaman the Hungerer
(26865, 15, 0, 0, 0, 0, 0, 0, 0, 15595), -- Enemies Below
(24981, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Thorn in our Side
(29290, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire in the Skies
(29274, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hounds of Shannox
(28689, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Forgotten
(28678, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain P. Harris
(29293, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Singed Wings
(29295, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Bigger They Are
(24713, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frostmourne
(2280, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Platinum Discs
(2278, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Platinum Discs
(27680, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Archaedas, The Ancient Stone Watcher
(27679, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Chamber of Khaz'mul
(27682, 396, 396, 396, 397, 0, 0, 0, 0, 15595), -- We Require More Minerals
(27681, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- Behind Closed Doors
(29332, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lily, Oh Lily
(29507, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fun for the Little Ones
(29520, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Banners, Banners Everywhere!
(29464, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Tools of Divination
(29360, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Would You Like Some Flies With That?
(29288, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Starting Young
(29333, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Escargot A Go-Go
(28543, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Felwood!
(25061, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Land's End
(24953, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Just Trying to Kill Some Bugs
(24951, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Great Idea
(24931, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gazer Tag
(24933, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chicken of the Desert
(25072, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Few Good Goblins
(24932, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cutting Losses
(26889, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- All Cheered Out
(25166, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Dreadbeard
(26887, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Filling Our Pockets
(26886, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Going Off-Task
(25054, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lootin' Plunder
(25053, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- To The Ground!
(25052, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dead Man's Chest
(25032, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Secrets in the Oasis
(25026, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Darkest Mojo
(25025, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sang'thraze the Deflector
(25522, 18, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gargantapid
(25521, 20, 0, 0, 0, 0, 0, 0, 0, 15595), -- I'm With Scorpid
(25021, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood to Thrive
(25121, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Momentum
(25091, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sandsorrow Watch
(25115, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blisterpaw Butchery
(648, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rescue OOX-17/TN!
(25111, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Scavengers Scavenged
(25112, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Butcherbot
(25050, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rocket Rescue
(25049, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Puddle Stomping
(25048, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Seaside Salvage
(28155, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lord Banehollow
(28153, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shadow Lord Fel'dan
(28131, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twin Temptresses
(28128, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Inner Circle
(28129, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Demon Prince
(28126, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Dousing the Flames of Protection
(28119, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Purity From Corruption
(28102, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fight the Power
(28113, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Break the Unbreakable
(28044, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Touch the Untouchable
(28049, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- See the Invisible
(28000, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Do the Imp-Possible
(28150, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Arcane Ally
(27995, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dance for Ruumbo!
(27989, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ruumbo Demands Honey
(27994, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ruumbo Demands Justice
(28148, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Culling the Corrupted
(28100, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Talking Totem
(27997, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Corruption of the Jadefire
(28116, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crying Violet
(28121, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Forces of Jaedenar
(29851, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Champion of the Tournament
(28670, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Food From Below
(28669, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warden
(28668, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Prison Revolt
(13279, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Basic Chemistry
(28665, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cursed Shackles
(28664, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Svarnos
(28663, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- D-Block
(29135, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- All-Seeing Eye
(29134, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- A Wrinkle in Time
(29129, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Legendary Engagement
(28843, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sins of the Sea Witch
(28833, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rescue the Earthspeaker!
(29319, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tadpole Terror
(29322, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time for Slime
(5502, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Warden of the Horde
(29191, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- You Scream, I Scream...
(29190, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Let's Go Fly a Kite
(29167, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Banshee Queen
(29176, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Fallen Chieftain
(29146, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Ridin' the Rocketway
(172, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Children's Week
(29361, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Moat Monster!
(29107, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Malfurion Has Returned!
(29106, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Biggest Diamond Ever!
(29093, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Cruisin' the Chasm
(29412, 3, 396, 25, 0, 0, 1000, 1000, 0, 15595), -- Blown Away
(11975, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Now, When I Grow Up...
(13959, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Back To The Orphanage
(13937, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Trip To The Wonderworks
(13956, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Meeting a Great One
(13954, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Dragon Queen
(13950, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Playmates!
(13933, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Bronze Dragonshrine
(13929, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Biggest Tree Ever!
(13926, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Little Orphan Roo Of The Oracles
(24712, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Deliverance from the Pit
(24507, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Path to the Citadel
(24682, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Pit of Saron
(9558, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Longbeards
(24974, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Ever So Lonely
(24975, 6, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fields of Grief
(24978, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reaping the Reapers
(24972, 1, 1, 66, 0, 0, 0, 0, 0, 15595), -- Vital Intelligence
(24971, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Assault on the Rotbrain Encampment
(24970, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- No Better Than the Zombies
(24973, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Night Web's Hollow
(26802, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Damned
(28672, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Executor In the Field
(28564, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Duskwood!
(26994, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Without Rhyme or Reason
(26976, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Battle for the Scarlet Monastery
(26873, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Preemptive Methods
(26872, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Deviate Hides
(26870, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Cleansing the Caverns
(10399, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Heart of Darkness
(10395, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dark Missive
(10397, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Invasion Point: Annihilator
(10396, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Enemy of my Enemy...
(10394, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Disruption - Forge Camp: Mageddon
(10163, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mission: The Abyssal Shelf
(10144, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Disrupt Their Reinforcements
(29543, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Invading the Citadel
(25067, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thunderdrome: The Ginormus!
(9453, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Find Acteon!
(9452, 5, 6, 1, 25, 0, 0, 0, 0, 15595), -- Red Snapper - Very Tasty!
(9314, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Word from Azure Watch
(9313, 1, 1, 2, 0, 0, 1000, 1000, 0, 15595), -- Travel to Azure Watch
(9312, 1, 6, 0, 0, 0, 1000, 0, 0, 15595), -- The Emitter
(9798, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood Elf Plans
(9311, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood Elf Spy
(10303, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Blood Elves
(9294, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Healing the Lake
(9309, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Missing Scout
(26966, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Light's Power
(9799, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Botanical Legwork
(9293, 6, 1, 18, 0, 0, 1000, 1000, 0, 15595), -- What Must Be Done...
(10302, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Volatile Mutations
(9303, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Inoculation
(9305, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spare Parts
(9283, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rescue the Survivors!
(9409, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Urgent Delivery!
(9280, 1, 0, 0, 0, 0, 0, 0, 0, 15595); -- Replenishing the Healing Crystals

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9279, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- You Survived!
(9689, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Razormaw
(9688, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Into the Dream
(9683, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Ending the Bloodcurse
(9682, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Hopeless Ones...
(9674, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Bloodcursed Naga
(9687, 1, 1, 0, 1, 0, 0, 0, 0, 15595), -- Restoring Sanctity
(9561, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nolkai's Words
(9557, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deciphering the Book
(9698, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Audience with the Prophet
(9711, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Matis the Cruel
(28492, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Ashenvale!
(9696, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Translations...
(9759, 274, 1, 1, 6, 0, 0, 0, 0, 15595), -- Ending Their World
(10065, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cutting a Path
(9741, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Critters of the Void
(10066, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Oh, the Tangled Webs They Weave
(10067, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Fouled Water Spirits
(9761, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Clearing the Way
(9706, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Galaen's Journal - The Fate of Vindicator Saruan
(11707, 6, 5, 1, 0, 0, 0, 0, 0, 15595), -- Distress Call
(29539, 396, 0, 0, 0, 0, 1000, 0, 0, 15595), -- Heart of Rage
(29540, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- The Breaker
(29538, 396, 396, 0, 0, 0, 1000, 1000, 0, 15595), -- Make Them Bleed
(6607, 1, 1, 5, 1, 0, 0, 0, 0, 15595), -- Nat Pagle, Angler Extreme
(27183, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Marsh Frog Legs
(1201, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Theramore Spies
(11215, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Help Mudsprocket
(26991, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Enemies Abroad
(26682, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Shambling Threat
(27253, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Inspecting the Ruins
(25051, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Darkmist Extermination
(27424, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Overlord Mok'Morokk's Concern
(27260, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lieutenant Paval Reethe
(27259, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Suspicious Hoofprints
(27347, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Corrosion Prevention
(27348, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Secure the Cargo!
(27336, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Grimtotem Weapon
(27339, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Reagent Thief
(27346, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Zeppelin Crash
(27340, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Direhorn Raiders
(27407, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Bloodfen Feathers
(25478, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Summit
(27413, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Catch a Dragon by the Tail
(24684, 274, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Weezil in the Henhouse
(24604, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Concern for Mankrik
(26908, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Feeling Thorny
(24824, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Disturbed Earth
(24631, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- Flightmare
(24551, 66, 1, 0, 0, 0, 0, 0, 0, 15595), -- Meet the New Boss
(24565, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Biological Intervention
(24571, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lashvine Seeds
(24570, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Adder Subtraction
(24539, 274, 1, 0, 0, 0, 0, 0, 0, 15595), -- When Plants Attack
(24525, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- Keeping the Dogs at Bay
(24529, 1, 15, 0, 0, 0, 0, 0, 0, 15595), -- Bad to Worse
(24517, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- Put the Fear in Them
(27592, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Drinks on the Rocks
(29529, 396, 0, 0, 0, 0, 1000, 1000, 0, 15595), -- Demons in the Citadel
(29594, 396, 6, 0, 0, 0, 0, 0, 0, 15595), -- Hitting Them Where It Hurts
(29528, 396, 0, 0, 0, 0, 1000, 1000, 0, 15595), -- War on the Ramparts
(26173, 1, 1, 66, 0, 0, 0, 0, 0, 15595), -- Protecting Our Rear
(28708, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Outland!
(14034, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Club Foote
(14045, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Find Baron Longshore
(895, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- WANTED: Cap'n Garvey
(865, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's Gotta be the Horn
(891, 1, 5, 1, 5, 0, 0, 0, 0, 15595), -- A Captain's Vengeance
(14066, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Investigate the Wreckage
(13998, 11, 0, 0, 0, 500, 0, 0, 0, 15595), -- In Fungus We Trust
(13988, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Growing Problem
(881, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Echeyakee
(29090, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Burning Threat
(29086, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Competition Schmompetition
(29021, 1, 1, 6, 1, 0, 0, 0, 0, 15595), -- Samophlange
(858, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ignition
(899, 15, 1, 25, 0, 0, 800, 0, 0, 15595), -- Consumed by Hatred
(26000, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spelunking
(25743, 5, 396, 396, 0, 0, 1000, 1000, 0, 15595), -- Decisions, Decisions
(25732, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- A Bone to Pick
(25670, 396, 396, 5, 396, 0, 500, 500, 500, 15595), -- DUN-dun-DUN-dun-DUN-dun
(27699, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shark Weak
(25794, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Undersea Sanctuary
(25638, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Desperate Plea
(25657, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Dah, Nunt... Dah, Nunt...
(25651, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Oh, the Insanity!
(25358, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nerve Tonic
(25459, 396, 396, 396, 0, 0, 500, 1000, 0, 15595), -- Ophidophobia
(25389, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Taste For Tail
(25390, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Girl's Best Friend
(25388, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- A Case of Crabs
(25598, 396, 396, 0, 0, 0, 500, 0, 0, 15595), -- Ain't Too Proud to Beg
(25587, 5, 1, 1, 0, 0, 500, 500, 0, 15595), -- Gimme Shelter!
(27685, 396, 396, 396, 0, 0, 500, 500, 0, 15595), -- Good Deed Left Undone
(25371, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Abyssal Ride
(25477, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Better Late Than Dead
(25949, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood and Thunder!
(25948, 5, 275, 0, 0, 0, 500, 0, 0, 15595), -- Bring It On!
(25316, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- As Hyjal Burns
(6363, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tal the Wind Rider Master
(26180, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Supervisor Fizsprocket
(26179, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Venture Co.
(24456, 50, 50, 50, 1, 0, 0, 0, 0, 15595), -- Thunderhorn Cleansing
(6362, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ride to Thunder Bluff
(6361, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Bundle of Hides
(26188, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mazzranache
(751, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Ravaged Caravan
(24441, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thunderhorn Totem
(24440, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Winterhoof Cleansing
(14491, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Restless Earth
(20440, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Poison Water
(14438, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sharing the Land
(24215, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rite of the Winds
(23733, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rites of the Earthmother
(24861, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Last Rites, First Rites
(14460, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rite of Honor
(27020, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The First Lesson
(3091, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Simple Note
(14461, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Feed of Evil
(14459, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Battleboars
(14455, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stop the Thorncallers
(14456, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rite of Courage
(14458, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Go to Adana
(24852, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Our Tribe, Imprisoned
(14452, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rite of Strength
(14449, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The First Step
(27578, 396, 396, 396, 113, 0, 0, 0, 0, 15595), -- Morgan's Fruition
(27573, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- The Dark Iron Pact
(27571, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- The Grim Guzzler
(28735, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Chamber of Incineration!
(13083, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Light Within the Darkness
(13082, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Boon of A'dal
(13081, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Will of the Naaru
(13080, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hope Yet Remains
(13079, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Boon of Alexstrasza
(13078, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dahlia's Tears
(13077, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Touch of an Aspect
(13076, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Time Yet Remains
(13075, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Boon of Remulos
(13074, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hope Within the Emerald Nightmare
(13073, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Keeper's Favor
(13072, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Hero Remains
(13225, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Skybreaker
(13068, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Tale of Valor
(13157, 1, 1, 66, 0, 0, 0, 0, 0, 15595), -- The Crusaders' Pinnacle
(13141, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Battle For Crusaders' Pinnacle
(13139, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Into The Frozen Heart Of Northrend
(13125, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Air Stands Still
(13110, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Restless Dead
(13135, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- It Could Kill Us All
(13130, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Stone That Started A Revolution
(13118, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Purging Of Scourgeholme
(13122, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Scourgestone
(13105, 1, 1, 397, 0, 0, 0, 0, 0, 15595), -- Once More Unto The Breach, Hero
(13086, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Last Line Of Defense
(13070, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- A Cold Front Approaches
(13045, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Into The Wild Green Yonder
(13044, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- If There Are Survivors...
(13040, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Curing The Incurable
(13039, 274, 1, 1, 0, 0, 0, 0, 0, 15595), -- Defending The Vanguard
(28522, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Winterfall Activity
(28524, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Delivery for Donova
(28460, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Threat of the Winterfall
(28544, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Winterspring!
(27605, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Eranikus
(27633, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Blood God Hakkar
(27604, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Jammal'an the Prophet
(27569, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- Dark Iron Tacticians
(27568, 5, 396, 396, 18, 0, 0, 0, 0, 15595), -- Infiltrating Shadowforge City
(25152, 1, 1, 11, 25, 0, 0, 0, 0, 15595), -- Your Place In The World
(25232, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Burning Blade
(25256, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sent for Help
(9852, 5, 1, 6, 0, 0, 1000, 1000, 0, 15595), -- The Ultimate Bloodsport
(9859, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Talbuk Mastery
(9856, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Windroc Mastery
(9851, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Clefthoof Mastery
(9858, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Talbuk Mastery
(9850, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Clefthoof Mastery
(9861, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Howling Wind
(9802, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Plants of Zangarmarsh
(28595, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Krazz Works!
(28592, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Parting Packages
(28594, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Highbank, Crybank
(28593, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Of Utmost Importance
(28591, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Off The Wall
(28590, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reprisal
(28589, 5, 1, 25, 0, 0, 0, 0, 0, 15595), -- Everything But the Kitchen Sink
(28586, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pool Pony Rescue
(28584, 6, 1, 25, 0, 0, 0, 0, 0, 15595), -- Quality Construction
(28588, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wildhammer Infestation
(28583, 4, 5, 1, 0, 0, 0, 0, 0, 15595), -- Krazzworks
(27622, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Mo' Better Shredder
(24802, 0, 0, 0, 0, 60, 0, 0, 0, 15595), -- Wrath of the Lich King
(26452, 66, 396, 0, 0, 0, 0, 0, 0, 15595), -- Gurubashi Challenge
(29036, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Honor the Flame
(26356, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Sanders' Hidden Treasure
(26355, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Sanders' Hidden Treasure
(26354, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Sanders' Hidden Treasure
(26347, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Keeper of the Flame
(26349, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Coastal Menace
(26348, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Coast Isn't Clear
(26322, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rise of the Brotherhood
(26320, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- A Vision of the Past
(26319, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Secrets Revealed
(26297, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Dawning of a New Day
(26296, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Evidence Collection
(26295, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Propaganda
(26292, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- To Moonbrook!
(26291, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Big Trouble in Moonbrook
(26365, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hero's Call: Redridge Mountains!
(26593, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Scaring Shaky
(26596, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Call of Kalimdor
(26630, 1, 24, 1, 0, 0, 0, 0, 0, 15595), -- Looks Like a Tauren Pirate to Me
(26629, 396, 396, 396, 396, 0, 0, 0, 0, 15595), -- Seeing Where Your Loyalties Lie
(26624, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Getting In With the Bloodsail
(26614, 6, 1, 1, 6, 0, 0, 0, 0, 15595), -- Keep An Eye Out
(26613, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Up to Snuff
(26612, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Details of the Attack
(26611, 5, 6, 5, 0, 0, 0, 0, 0, 15595), -- The Baron Must Be Told
(26617, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Old Sea Dog
(26610, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bloodsail Treachery
(26609, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Bloodsail Buccaneers
(26601, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mok'rash the Cleaver
(26602, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Dish Best Served Huge
(27159, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Scourge First... Horde Later
(28749, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Battle for Andorhal
(26600, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Giant's Feast
(26606, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mukla's Demise
(26605, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Grubby Little Paws
(26604, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Protecting Her Royal Highness Poobah
(26603, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Message in a Bottle
(26822, 34, 24, 1, 1, 0, 0, 0, 0, 15595), -- Good-Fer-Nothin' Slither-Dogs
(26823, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Too Big For His Britches
(26826, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dask "The Flask" Gobfizzle
(26597, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stranglethorn Fever
(26599, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Captain's Chest
(9622, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Warn Your People
(9571, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Kurken's Hide
(9570, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Kurken is Lurkin'
(9566, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blood Crystals
(9565, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Search Stillpine Hold
(9573, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chieftain Oomooroo
(9564, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gurf's Dignity
(9562, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Murlocs... Why Here? Why Now?
(9560, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Beasts of the Apocalypse!
(9623, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Coming of Age
(9602, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Deliver Them From Evil...
(9537, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Show Gnomercy
(9559, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stillpine Hold
(9527, 1, 1, 1, 0, 0, 0, 0, 0, 15595); -- All That Remains

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9515, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warlord Sriss'tiz
(9514, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rune Covered Tablet
(9531, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Tree's Company
(9530, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- I've Got a Plant
(9523, 6, 6, 1, 5, 0, 0, 0, 0, 15595), -- Precious and Fragile Things Need Special Handling
(9513, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reclaiming the Ruins
(9506, 1, 1, 1, 6, 0, 0, 0, 0, 15595), -- A Small Start
(9512, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cookie's Jumbo Gumbo
(10428, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- The Missing Fisherman
(9456, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Nightstalker Clean Up, Isle 2...
(9455, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strange Findings
(9505, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Prophecy of Velen
(9473, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- An Alternative Alternative
(10324, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Great Moongraze Hunt
(9454, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Great Moongraze Hunt
(9463, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Medicinal Purpose
(9606, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Caregiver Chellan
(9605, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hippogryph Master Stephanos
(9604, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- On the Wings of a Hippogryph
(9603, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Beds, Bandages, and Beyond
(14361, 396, 396, 5, 0, 0, 500, 500, 0, 15595), -- Peace of Mind
(14365, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Ethel Rethor
(1454, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Karnitol Shipwreck
(14359, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blessings From Above
(14357, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Hilt!
(14358, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ten Pounds of Flesh
(14193, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nothing a Couple of Melons Won't Fix
(14354, 5, 396, 396, 0, 0, 500, 500, 0, 15595), -- Elune's Gifts
(14387, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Lay of the Land
(14384, 5, 396, 66, 0, 0, 0, 0, 0, 15595), -- Rerouted!
(25852, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- All's Clear
(25851, 66, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dances with Grimtotem
(25848, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Downfall
(25847, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Grimtotem Supremacy
(25846, 1, 1, 66, 0, 0, 0, 0, 0, 15595), -- Grundig Darkcloud, Chieftain of the Grimtotem
(25823, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Unrelenting Horde
(25822, 273, 1, 0, 0, 0, 0, 0, 0, 15595), -- Armaments for War
(25845, 1, 1, 397, 0, 0, 0, 0, 0, 15595), -- Terms of Service
(25844, 396, 5, 0, 0, 0, 0, 0, 0, 15595), -- Sating the Savage Beast
(25837, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Proper Peace Offerin'
(25834, 6, 1, 0, 273, 0, 0, 0, 0, 15595), -- Death by Proxy
(25821, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Special Kind of Job
(25808, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Is This Thing On?
(25806, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- They Put the Assass in... Never Mind
(25809, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Leave No Man Behind! 
(25811, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Shuttin Her Down
(25793, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Deep Reaches
(25912, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Seen Better Days
(25914, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Back to the Depths!
(25913, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Putting Them to Rest
(25931, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brood of Seldarria
(25935, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hungry Pups
(25934, 2, 1, 1, 0, 0, 0, 0, 0, 15595), -- World First: Gnomegen
(25938, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Help for Desolace
(25930, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Ascending the Vale
(25925, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Thal'darah's Vengeance
(25891, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Last Ditch Effort
(25889, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Save the Children!
(25880, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Warn Master Thal'darah
(25877, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- No Time for Goodbyes!
(25876, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- It's Up There!
(25879, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Lumbering Oaf Problem
(25878, 6, 5, 0, 0, 0, 0, 0, 0, 15595), -- Schemin' That Sabotage
(25875, 1, 1, 25, 0, 0, 0, 0, 0, 15595), -- Gnome on the Inside
(25768, 1, 1, 1, 113, 0, 0, 0, 0, 15595), -- Bombs Away: Mirkfallon Post!
(25769, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fallowmere Beckons
(25765, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tell 'Em Koko Sent You
(25767, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Capturing Memories
(25766, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Arcane Legacy
(25728, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mr. P's Wild Ride
(25741, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Preparations for the Future
(25739, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- If the Horde Don't Get You...
(25729, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gerenzo the Traitor
(25730, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- BEWARE OF CRAGJAW!
(25669, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Rumble in the Lumber... Mill
(25673, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Just Ask Alice
(25662, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Free Our Sisters
(25652, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Commandeer That Balloon!
(25650, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Orders from High Command
(25649, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Minx'll Fix It
(25647, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Illegible Orc Letter
(25646, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Windshear Mine Cleanup
(25642, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Don't Look Them in the Eyes
(25640, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bombs Away: Windshear Mine!
(25622, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Burn, Baby, Burn!
(25621, 4, 1, 1, 0, 0, 0, 0, 0, 15595), -- Field Test: Gnomecorder
(25616, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Hellscream's Legacy
(25615, 1, 2, 0, 0, 0, 0, 0, 0, 15595), -- Return to Stardust
(25614, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Only Way Down is in a Body Bag
(26395, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dungar Longdrink
(26394, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Continue to Stormwind
(47, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gold Dust Exchange
(26393, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Swift Message
(62, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Fargodeep Mine
(60, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kobold Candles
(26390, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Ending the Invasion!
(26391, 1, 1, 20, 0, 0, 0, 0, 0, 15595), -- Extinguishing Hope
(26389, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Blackrock Invasion
(28818, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Rear is Clear
(28808, 6, 5, 5, 20, 0, 0, 0, 0, 15595), -- Fear No Evil
(28792, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- They Sent Assassins
(28784, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Join the Battle!
(26916, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Mastering the Arcane
(28769, 274, 1, 25, 5, 0, 0, 0, 0, 15595), -- Lions for Lambs
(28757, 6, 2, 1, 5, 0, 0, 0, 0, 15595), -- Beating Them Back!
(25007, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- East... Always to the East
(25006, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Grasp Weakens
(25005, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Speak with Sevren
(25029, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deaths in the Family
(25004, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Mills Overrun
(25003, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Family Crypt
(25031, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Head for the Mills
(24999, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Planting the Seed of Fear
(24995, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Off the Scales
(24997, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Graverobbers
(24994, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Doom Weed
(26964, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Silverpine Forest!
(24991, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Garren's Haunt
(24996, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Holland's Experiment
(24990, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Darkhound Pounding
(6324, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Morris
(6322, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Michael Garrett
(6323, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ride to the Undercity
(6321, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Supplying Brill
(24983, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forsaken Duties
(24982, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- The New Forsaken
(25090, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Putrid Task
(25038, 35, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gordo's Task
(24977, 6, 1, 11, 0, 0, 0, 0, 0, 15595), -- Johaan's Experiment
(24976, 6, 1, 11, 0, 0, 0, 0, 0, 15595), -- Variety is the Spice of Death
(24980, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Scarlet Palisade
(24979, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Scarlet Letter
(24964, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Thrill of the Hunt
(24961, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Truth of the Grave
(24962, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trail-Worn Scroll
(26801, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Scourge on our Perimeter
(28653, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Shadow Priest Sarvis
(26800, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Recruitment
(25089, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Beyond the Graves
(24960, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- The Wakening
(28652, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Caretaker Caice
(26799, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Those That Couldn't Be Saved
(27475, 457, 457, 457, 0, 0, 0, 0, 0, 15595), -- Unyielding Servitors
(27474, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Breaking the Barrier
(27472, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Rise, Godfrey
(27438, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Great Escape
(27423, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Resistance is Futile
(27406, 1, 1, 1, 273, 0, 0, 0, 0, 15595), -- A Man Named Godfrey
(27405, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fall Back!
(27401, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- What Tomorrow Brings
(27364, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- On Whose Orders?
(27360, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vengeance for Our Soldiers
(27350, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Break in Communications: Rutsak's Guard
(27349, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Break in Communications: Dreadwatch Outpost
(27345, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The F.C.D.
(27333, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Losing Ground
(27342, 1, 1, 1, 273, 0, 0, 0, 0, 15595), -- In Time, All Will Be Revealed
(27290, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- To Forsaken Forward Command
(27226, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Hair of the Dog
(27232, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Waters Run Red...
(27195, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Nowhere to Run
(27194, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cornered and Crushed!
(27193, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Seek and Destroy
(27181, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Excising the Taint
(27231, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reinforcements from Fenris
(27180, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Honor the Dead
(27098, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lordaeron
(27099, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- No Escape
(27097, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Rise, Forsaken
(27096, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Orcs are in Order
(27094, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deeper into Darkness
(27093, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lost in the Darkness
(27095, 15, 1, 5, 0, 0, 0, 0, 0, 15595), -- Skitterweb Menace
(27088, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- It's Only Poisonous if You Ingest It
(27082, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Playing Dirty
(27073, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Give 'em Hell!
(27069, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Steel Thunder
(27065, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Warchief's Fleet
(27056, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Belmont's Report
(27045, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Waiting to Exsanguinate
(27039, 6, 1, 0, 0, 0, 0, 0, 0, 15595), -- Dangerous Intentions
(26998, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Iterating Upon Success
(26995, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Guts and Gore
(26992, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Agony Abounds
(26989, 1, 5, 1, 397, 0, 0, 0, 0, 15595), -- The Gilneas Liberation Front
(26965, 1, 1, 66, 0, 0, 0, 0, 0, 15595), -- The Warchief Cometh
(24989, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to the Magistrate
(24988, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Chill of Death
(24998, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maggot Eye
(9625, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Elekks Are Serious Business
(28557, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Uldum!
(28293, 274, 25, 0, 0, 0, 0, 0, 0, 15595), -- That's No Pyramid!
(27059, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Wrong Sequence
(27041, 6, 0, 0, 0, 0, 0, 0, 0, 15595), -- Decryption Made Easy
(27043, 6, 1, 25, 0, 0, 0, 0, 0, 15595), -- Fight Fire and Water and Air with...
(27008, 6, 6, 0, 0, 0, 0, 0, 0, 15595), -- Fly Over
(27005, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- The Twilight Plot
(27953, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- The Reliquary
(27102, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maziel's Ascendancy
(27101, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maziel's Revelation
(27100, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Research
(27722, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Deepholm!
(26194, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defending the Rift
(26182, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Back to the Tenebrous Cavern
(26143, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- All that Rises
(26154, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Extermination
(26149, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Prisoners
(26142, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ascend No More!
(26141, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Runestones of Binding
(26140, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Communing with the Ancient
(26133, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Fiends from the Netherworld
(26130, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Unplug L'ghorek
(26111, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- ... It Will Come
(26065, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Free Wil'hai
(26096, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Scalding Shrooms
(26072, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- Into the Totem
(26057, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Wavespeaker
(26071, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Clearing the Defiled
(25984, 5, 25, 0, 0, 0, 0, 0, 0, 15595), -- Promontory Point
(25988, 273, 6, 0, 0, 0, 0, 0, 0, 15595), -- Put It On
(28814, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Followers and Leaders
(28815, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Documents
(25976, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Treasure Reclamation
(25982, 5, 6, 0, 0, 0, 0, 0, 0, 15595), -- Those Aren't Masks
(25980, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Standard Day for Azrajar
(25974, 6, 1, 0, 0, 0, 0, 0, 0, 15595), -- Sira'kess Slaying
(26092, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Orako's Report
(26091, 432, 1, 1, 0, 0, 0, 0, 0, 15595), -- Here Fishie Fishie 2: Eel-Egg-Trick Boogaloo
(26090, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- I Brought You This Egg
(26088, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Here Fishie Fishie
(26089, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Die Fishman Die
(26087, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- "Glow-Juice"
(26086, 14, 396, 6, 0, 0, 1000, 0, 0, 15595), -- Orako
(26126, 6, 1, 1, 25, 0, 0, 0, 0, 15595), -- The Perfect Fuel
(26125, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Secure Seabrush
(26124, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Secure Seabrush
(26122, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Environmental Awareness
(26221, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Full Circle
(25968, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Desperate Plan
(25967, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Losing Ground
(25861, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Setting An Example
(25863, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chosen Burden
(25862, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stolen Property
(25859, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- No Trespass Forgiven
(25858, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- By Her Lady's Word
(25966, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Visions of the Past: The Slaughter of Biel'aran Ridge
(25964, 36, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fallen But Not Forgotten
(25965, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gauging Success
(25963, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Swift Action
(25962, 5, 0, 0, 0, 0, 0, 0, 0, 15595); -- Properly Inspired

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25960, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Not Entirely Unprepared
(25959, 1, 1, 1, 0, 0, 60, 60, 0, 15595), -- Clear Goals
(25958, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Looking Forward
(25659, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Not Soon Forgotten
(25658, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Built to Last
(25637, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Fathom-Lord's Call
(25620, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Revered Lady
(25619, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Reoccupation
(25957, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Visions of the Past: The Invasion of Vashj'ir
(25956, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Upon the Scene of Battle
(27717, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Piece of the Past
(25954, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Occupation of Time
(25953, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Swift Approach
(25952, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Caught Off-Guard
(25955, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Better Vantage
(25595, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Something Edible
(25594, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crafty Crabs
(25593, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shelled Salvation
(25592, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Deep Attraction
(25996, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Waking the Beast
(25995, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Overseer Idra'kess
(25992, 1, 15, 390, 1, 0, 0, 0, 0, 15595), -- Hopelessly Gearless
(25994, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Still Valuable
(25993, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Body Blows
(25991, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- We Are Not Alone
(25990, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Breaking Through
(25989, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Capture the Crab
(25908, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stick it to Them
(25907, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Slave Labor
(25900, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Making Contact
(25890, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Nespirah
(25442, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Pearl of Wisdom
(25440, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fathom-Lord Zin'jatar
(25441, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vortex
(25439, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vengeful Heart
(25359, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Toshe's Vengeance
(25456, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Back in One Piece
(25217, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Totem Modification
(25360, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crabby Patrons
(25218, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Undersea Inflation
(25219, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Don't be Shellfish
(25220, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slippery Threat
(25216, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Great Sambino
(25215, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Distracting Scent
(25222, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Silver Tide Hollow
(25221, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rundown
(25164, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Backed Into a Corner
(25334, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Looming Threat
(25471, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Across the Great Divide
(27708, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warden's Time
(25883, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- How Disarming
(26008, 5, 396, 0, 0, 0, 0, 0, 0, 15595), -- Decompression
(25884, 396, 396, 5, 0, 0, 500, 1000, 0, 15595), -- Come Hell or High Water
(26040, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- What? What? In My Gut...?
(25887, 396, 5, 396, 0, 0, 0, 0, 0, 15595), -- Wake of Destruction
(25419, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lady La-La's Medallion
(26007, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Debriefing
(27729, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Once More, With Eeling
(25942, 396, 396, 396, 0, 0, 500, 500, 0, 15595), -- Buy Us Some Time
(25943, 396, 396, 396, 0, 0, 500, 500, 0, 15595), -- Traveling on Our Stomachs
(25941, 396, 396, 396, 0, 0, 500, 500, 0, 15595), -- Rest For the Weary
(25936, 396, 396, 5, 0, 500, 500, 0, 0, 15595), -- Pay It Forward
(25929, 396, 396, 396, 0, 0, 500, 500, 0, 15595), -- Sea Legs
(25924, 5, 5, 396, 0, 0, 1000, 1000, 0, 15595), -- Call of Duty
(27718, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Vashj'ir!
(28816, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- To the Depths
(28805, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- The Eye of the Storm
(28854, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Closing a Dark Chapter
(28852, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Soften them Up
(28853, 273, 1, 0, 0, 0, 0, 0, 0, 15595), -- Kill the Courier
(11668, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Shrimpin' Ain't Easy
(28779, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Long Way from Home
(28760, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vengeance for Orsis
(26710, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lost In The Deeps
(13424, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Back to the Pit
(14140, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Stop The Aggressors
(14141, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Gormok Wants His Snobolds
(14101, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Drottinn Hrothgar
(27142, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Lich, Ras Frostwhisper
(27140, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alexi's Gambit
(27147, 5, 1, 1, 1, 0, 0, 0, 0, 15595), -- Kirtonos the Herald
(27148, 1, 1, 25, 0, 0, 0, 0, 0, 15595), -- School's Out Forever
(27143, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- Barov Family Fortune
(27146, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Doctor Theolen Krastinov, the Butcher
(27145, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Plagued Hatchlings...For Now
(13973, 5, 25, 0, 0, 0, 1000, 0, 0, 15595), -- The Grol'dom Militia
(872, 1, 5, 1, 0, 0, 1000, 800, 0, 15595), -- The Far Watch Offensive
(844, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Plainstrider Menace
(871, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- In Defense of Far Watch
(25264, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Ak'Zeloth
(28494, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Northern Barrens!
(25263, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arnak Fireblade
(25259, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gaur Icehorn
(25258, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Griswold Hanniston
(25257, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Ghislania
(25262, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Skull Rock
(25261, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Margoz
(25206, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ignoring the Warnings
(28817, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Rear is Clear
(28806, 6, 5, 5, 20, 0, 0, 0, 0, 15595), -- Fear No Evil
(28791, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- They Sent Assassins
(28780, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Join the Battle!
(26917, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Hunter's Path
(26910, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Etched Letter
(28759, 274, 1, 25, 5, 0, 0, 0, 0, 15595), -- Lions for Lambs
(28767, 6, 2, 1, 5, 0, 0, 0, 0, 15595), -- Beating Them Back!
(29444, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- An Exotic Egg
(27692, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Princess Theradras
(25129, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sarkoth
(25126, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cutting Teeth
(25205, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Wolf and The Kodo
(25236, 1, 1, 22, 0, 0, 0, 0, 0, 15595), -- Thunder Down Under
(25260, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Fizzled
(835, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Securing the Lines
(834, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Winds in the Desert
(25196, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dranosh'ar Blockade
(24929, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Send a Message
(24925, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Free the Captives
(24924, 6, 25, 0, 0, 0, 0, 0, 0, 15595), -- Oomlot Village
(24901, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Town-In-A-Box: Under Attack
(24897, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Get Back to Town
(24868, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- Surrender or Else!
(25195, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- That's the End of That Raptor
(25194, 1, 275, 1, 0, 0, 0, 0, 0, 15595), -- Unbidden Visitors
(25192, 22, 0, 0, 0, 0, 0, 0, 0, 15595), -- Raggaran's Fury
(25190, 1, 15, 0, 0, 0, 0, 0, 0, 15595), -- Raggaran's Rage
(25189, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spirits Be Praised
(25193, 1, 18, 1, 0, 0, 0, 0, 0, 15595), -- Lost But Not Forgotten
(25188, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Watershed Patrol
(25187, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Lost in the Floods
(25227, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thonk
(25179, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Loss Reduction
(25178, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Shipwreck Searching
(25177, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Storming the Beaches
(25176, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Exploiting the Situation
(25173, 5, 1, 15, 0, 0, 0, 0, 0, 15595), -- From Bad to Worse
(25171, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Riding On
(25169, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The War of Northwatch Aggression
(25168, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Purge the Valley
(25165, 94, 94, 0, 0, 0, 0, 0, 0, 15595), -- Never Trust a Big Barb and a Smile
(27023, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Way of the Sunwalkers
(27015, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Consecrated Note
(27104, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alzzin the Wildshaper
(27105, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Unwelcome Guest
(27103, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Shards of the Felvine
(27108, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lethtendris's Web
(27107, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Pusillin The Thief
(26996, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Right Under Their Noses
(27697, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Corruption in Maraudon
(14474, 5, 6, 0, 0, 0, 2000, 0, 0, 15595), -- Goblin Escape Pods
(14153, 5, 17, 0, 0, 0, 0, 0, 0, 15595), -- Life of the Party
(14110, 6, 0, 0, 0, 0, 0, 0, 0, 15595), -- The New You
(14012, 2, 25, 0, 0, 0, 0, 0, 0, 15595), -- Corruption
(26711, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Off to the Bank
(24965, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Magic Training
(3098, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Glyphic Scroll
(27737, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- By Fire Be Saved!
(27739, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Gnoll King
(27733, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Good Ol' Switcheroo
(26884, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Researching the Corruption
(26881, 1, 1, 1, 29, 0, 0, 0, 0, 15595), -- In Search of Aluwyn
(26883, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Falls
(26885, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Knowledge in the Deeps
(27968, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fury of the Pack
(27921, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fighting Tooth and Claw
(27920, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Armored to the Teeth
(27917, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sniffing Them Out
(14095, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Identifying the Remains
(14108, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Get Kraken!
(11076, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Picking Up The Pieces...
(11055, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Booterang: A Cure For The Common Worthless Peon
(11015, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Netherwing Crystals
(14092, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Breakfast Of Champions
(28064, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Welcome to the Brotherhood
(28061, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Minions of Calcinder
(28062, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- From Whence He Came
(28060, 1, 1, 5, 1, 0, 0, 0, 0, 15595), -- Twisted Twilight Ties
(28057, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- Kill 'em With Sleep Deprivation
(28056, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Rise, Obsidion
(28055, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sweet, Horrible Freedom
(28054, 1, 24, 5, 1, 0, 0, 0, 0, 15595), -- Slavery is Bad
(28052, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Operation: Stir the Cauldron
(28035, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Mountain-Lord's Support
(28034, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lunk's Adventure: Rendan's Weakness
(28033, 24, 1, 6, 0, 0, 0, 0, 0, 15595), -- Deceit
(28032, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Mysteries of the Fire-Gizzard
(28030, 1, 1, 11, 0, 0, 0, 0, 0, 15595), -- They Build a Better Bullet
(28029, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Set Them Ablaze!
(28028, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- Siege!
(27986, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- In the Hall of the Mountain-Lord
(27985, 6, 1, 0, 0, 0, 0, 0, 0, 15595), -- Prayer to Elune
(27984, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lunthistle's Tale
(27982, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Collars
(27979, 1, 1, 25, 0, 0, 0, 0, 0, 15595), -- Dark Ministry
(27983, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Lunk's Adventure: Cranky Little Dwarfs
(27977, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Recon Essentials
(27981, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Heat That Just Don't Quit
(27976, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Curse These Fat Fingers
(28099, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Rasha'krak
(27470, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Potential Ally
(27980, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Spiders Have to Go
(27965, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Thorium Point: The Seat of the Brotherhood
(27959, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Lunk's Adventure: Spider Rider
(27958, 1, 5, 1, 0, 0, 0, 0, 0, 15595), -- A Proper Antivenom
(27964, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Dig-Boss Dinwhisker
(27962, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Lumbering Relic
(27961, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Out of Place
(27963, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- A New Master... But Who?
(27960, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Fewer, the Better
(27956, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Lunk's Task
(11054, 6, 1, 1, 1, 0, 0, 0, 0, 15595), -- Overseeing and You: Making the Right Choices
(28390, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Glop, Son of Glop
(27051, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Through Persistence
(13611, 1, 6, 0, 0, 0, 1000, 0, 0, 15595), -- Mimiron's Sigil
(13610, 1, 4, 0, 0, 0, 1000, 0, 0, 15595), -- Thorim's Sigil
(13609, 5, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Hodir's Sigil
(13606, 1, 25, 0, 0, 0, 1000, 0, 0, 15595), -- Freya's Sigil
(13607, 1, 5, 6, 0, 0, 1000, 1000, 0, 15595), -- The Celestial Planetarium
(13631, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- All Is Well That Ends Well
(13604, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Archivum Data Disc
(14105, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Deathspeaker Kharos
(13180, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slay them all!
(13183, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Victory in Wintergrasp
(10341, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kick Them While They're Down
(10338, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shutting Down Manaforge Duro
(10310, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Sabotage the Warp-Gate!
(10433, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Keeping Up Appearances
(10348, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- New Opportunities
(10417, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Run a Diagnostic!
(10267, 1, 15, 1, 0, 0, 1000, 1000, 0, 15595), -- Rightful Repossession
(10311, 1, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Drijya Needs Your Help
(10234, 6, 11, 1, 0, 0, 1000, 1000, 0, 15595), -- One Demon's Trash...
(10257, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Capturing the Keystone
(10256, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Finding the Keymaster
(10200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Thalodien
(10176, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Ar'kelos the Guardian
(30097, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Archival Purposes
(30096, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Murozond
(29388, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Guardians of Hyjal: Firelands Invasion!
(29157, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Zandalari Menace
(29440, 1, 6, 25, 0, 0, 0, 0, 0, 15595), -- The Call of the World-Shaman
(13771, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Valiant's Field Training
(13769, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Worthy Weapon
(13857, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- At The Enemy's Gates
(13772, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Grand Melee
(13385, 1, 274, 25, 0, 0, 0, 2000, 0, 15595), -- Heroic Judgment at the Eye of Eternity
(13375, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Heroic Key to the Focusing Iris
(10733, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Down the Violet Path
(24429, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Most Puzzling Circumstance
(14017, 1, 1, 0, 0, 0, 0, 0, 0, 15595); -- The Black Knight's Fate

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14016, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Black Knight's Curse
(13664, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Black Knight's Fall
(13663, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Black Knight's Orders
(13276, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- That's Abominable!
(13368, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- No Rest For The Wicked
(13365, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Not a Bug
(13353, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Drag and Drop
(13654, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- There's Something About the Squire
(13643, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Stories Dead Men Tell
(13641, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Seer's Crystal
(13634, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Black Knight of Silverpine?
(13794, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Eadric the Pure
(13720, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Valiant's Charge
(13709, 396, 1, 0, 0, 0, 0, 0, 0, 15595), -- Valiant Of Thunder Bluff
(13740, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Champion Rises
(13731, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Valiant's Challenge
(13859, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- At The Enemy's Gates
(13787, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Grand Melee
(13784, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Worthy Weapon
(13786, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Valiant's Field Training
(13836, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Disarmed!
(11954, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- Striking Back
(12012, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Inform the Elder
(11891, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- An Innocent Disguise
(11925, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- More Torch Catching
(11926, 2, 0, 0, 0, 0, 0, 0, 0, 15595), -- More Torch Tossing
(11933, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing the Exodar's Flame
(9332, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Darnassus's Flame
(9331, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Ironforge's Flame
(9330, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Stormwind's Flame
(11667, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The One That Got Away
(13783, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Blade Fit For A Champion
(24582, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Instructor Razuvious Must Die!
(13046, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Feeding Arngrim
(13006, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Polishing the Helm
(12994, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spy Hunter
(12977, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blowing Hodir's Horn
(12981, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hot and Cold
(9893, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Obsidian Warbeads
(29031, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Honor the Flame
(9913, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Consortium Needs You!
(11972, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shards of Ahune
(13047, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Reckoning
(13035, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Loken's Lackeys
(13005, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Earthen Oath
(13057, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Terrace of the Makers
(12953, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Valkyrion Must Burn
(13010, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Krolmir, Hammer of Storms
(12968, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Yulda's Folly
(12942, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Off With Their Black Wings
(12925, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Aberrations
(13051, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Territorial Trespass
(13050, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veranus
(13003, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thrusting Hodir's Spear
(12987, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Mounting Hodir's Helm
(12976, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- A Monument to the Fallen
(12975, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- In Memoriam
(13009, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- A New Beginning
(12985, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Forging a Head
(13420, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Everfrost
(12967, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Battling the Elements
(13001, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Raising Hodir's Spear
(13011, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Jormuttar is Soo Fat...
(12966, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- You Can't Miss Him
(12924, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Forging an Alliance
(12956, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Spark of Hope
(12922, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Refiner's Fire
(12915, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mending Fences
(13064, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sibling Rivalry
(12886, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Drakkensryd
(13423, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defending Your Title
(13062, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lok'lira's Parting Gift
(13061, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Prepare for Glory
(12997, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into the Pit
(12996, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warm-Up 
(12989, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Slithering Darkness
(12983, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Last of Her Kind
(12900, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Making a Harness
(13063, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Deemed Worthy
(12856, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Cold Hearted
(12851, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Going Bearback
(12972, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- You'll Need a Bear
(12971, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Taking on All Challengers
(12970, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Hyldsmeet
(12969, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Is That Your Goblin?
(12921, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Change of Scenery
(12908, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Certain Prisoner
(12907, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Examples to be Made
(12906, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Discipline
(12905, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mildred the Cruel
(12841, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Crone's Bargain
(13722, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Valiant's Charge
(13696, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Valiant Of Silvermoon
(13680, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Aspirant's Challenge
(13058, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Changing the Wind's Course
(13049, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Hero's Arms
(13048, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Where Time Went Wrong
(13038, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Distortions in Time
(13037, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Memories of Stormhoof
(13034, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Witness and the Hero
(13007, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Iron Colossus
(12998, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Heart of the Storm
(12993, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Colossal Threat
(12991, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hit Them Where it Hurts
(12988, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Destroy the Forges!
(12984, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Valduran the Stormborn
(12980, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Armor's Secrets
(12979, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Armor of Darkness
(12664, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dark Horizon
(12661, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Infiltrating Voltarus
(12652, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Feedin' Da Goolz
(12648, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Dressing Down
(12629, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- You Can Run, But You Can't Hide
(12637, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Near Miss
(12631, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Invitation, of Sorts...
(29282, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Well Armed
(29320, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Like Pike?
(29334, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach Coach
(24622, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Troll's Truest Companion
(25037, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crab Fishin'
(25064, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Moraya
(24781, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- More Than Expected
(24778, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- The Arts of a Hunter
(24780, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Proving Pit
(24779, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Rough Start
(24777, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Basics: Hitting Things
(24776, 1, 1, 1, 0, 0, 60, 60, 0, 15595), -- The Rise of the Darkspear
(29317, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fish Head
(29364, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Corn Mash
(13845, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sealed Vial of Poison
(29284, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Aid of the Ancients
(29311, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Rest is History
(29310, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Tipping Point
(29303, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Tragedy and Family
(29302, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Unlocking the Secrets Within
(29348, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Race to Restock
(29365, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Perfectly Picked Portions
(29298, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Smoke-Stained Locket
(29281, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Additional Armaments
(29280, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Nourishing Waters
(29248, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Releasing the Pressure
(26840, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Return to the Highlands
(26830, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- Traitor's Bait
(26798, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Saurfang Will be Pleased
(26784, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Muddied Waters
(26788, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Cementing Our Victory
(26786, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- Securing the Beach Head
(26622, 1, 5, 15, 0, 0, 0, 0, 0, 15595), -- Death to Mor'ghor
(26621, 1, 11, 25, 0, 0, 0, 0, 0, 15595), -- Insurrection
(26619, 1, 25, 66, 0, 0, 0, 0, 0, 15595), -- You Say You Want a Revolution
(26608, 1, 66, 0, 0, 0, 0, 0, 0, 15595), -- Negotiations Terminated
(26540, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Dangerous Compassion
(26549, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Madness
(26538, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- Emergency Aid
(26539, 1, 25, 273, 0, 0, 0, 0, 0, 15595), -- Stalled Negotiations
(26388, 1, 4, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Skies
(28849, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Twilight Skies
(26372, 273, 1, 0, 0, 0, 0, 0, 0, 15595), -- Pre-Flight Checklist
(26337, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Beating the Market
(26361, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Smoot's Samophlange
(26335, 1, 274, 5, 0, 0, 0, 0, 0, 15595), -- Ready the Navy
(26358, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Ready the Air Force
(26374, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- Ready the Ground Troops
(26324, 1, 5, 25, 0, 0, 0, 0, 0, 15595), -- Where Is My Warfleet?
(26294, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Weapons of Mass Dysfunction
(26311, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Unfamiliar Waters
(26293, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Machines of War
(28717, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warchief's Command: Twilight Highlands!
(7787, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rise, Thunderfury!
(26382, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Can't Make An Omelette Without...
(26225, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pupellyverbos Port
(26290, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Secrets of the Tower
(26289, 1, 1, 1, 25, 0, 0, 0, 0, 15595), -- Find Agent Kearnen
(26288, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- Jango Spothide
(26286, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- In Defense of Westfall
(26371, 6, 1, 19, 0, 0, 0, 0, 0, 15595), -- The Legend of Captain Grayson
(26287, 396, 396, 396, 0, 0, 0, 0, 0, 15595), -- The Westfall Brigade
(26271, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Feeding the Hungry and the Hopeless
(26266, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Hope for the People
(26270, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- You Have Our Thanks
(26257, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- It's Alive!
(26252, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Heart of the Watcher
(26241, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Westfall Stew
(26237, 1, 1, 5, 20, 0, 0, 0, 0, 15595), -- Times are Tough
(26236, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Shakedown at the Saldean's
(26232, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Lou's Parting Thoughts
(26229, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- "I TAKE Candle!"
(26228, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Livin' the Life
(26215, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Meet Two-Shoed Lou
(26353, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Sanders' Hidden Treasure
(26214, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Hot On the Trail: Murlocs
(26213, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Hot On the Trail: The Riverpaw Clan
(26209, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Murder Was The Case That They Gave Me
(13964, 5, 1, 0, 0, 0, 0, 0, 0, 15595), -- To the Spire
(13965, 6, 2, 1, 0, 0, 0, 0, 0, 15595), -- Check in on the Edunes
(26480, 6, 1, 1, 0, 0, 0, 0, 0, 15595), -- Dartol's Rod
(26479, 4, 1, 0, 0, 0, 0, 0, 0, 15595), -- Return to Raene
(26478, 1, 1, 18, 1, 0, 0, 0, 0, 15595), -- Playing Possum
(26477, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Search the Bole
(26454, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Shameful Waste
(13874, 1, 1, 25, 0, 0, 1000, 0, 0, 15595), -- A Not-So-Charmed Life
(26476, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Dryad Delivery
(13872, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Worgen Wisdom
(13981, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- They Set Them Up The Bomb!
(26456, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Report from the Northern Front
(13924, 16, 2, 0, 0, 0, 1000, 0, 0, 15595), -- All's Well
(13935, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defend the Tree!
(13928, 1, 1, 25, 0, 0, 0, 0, 0, 15595), -- Recover the Fallen
(13922, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- In the Hands of the Perverse
(13868, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Corrupting Influence?
(13921, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- He Who Would Be Forgiven
(13919, 274, 6, 25, 0, 0, 1000, 0, 0, 15595), -- A Trip to the Moonwell
(13853, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return Fire
(26475, 18, 1, 20, 0, 0, 1000, 2000, 0, 15595), -- Elune's Tear
(13867, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Culling the Furbolg Threat
(13849, 5, 0, 0, 0, 0, 0, 0, 0, 15595), -- Astranaar's Burning!
(26453, 1, 274, 1, 0, 0, 0, 0, 0, 15595), -- A Helping Hand
(13646, 4, 2, 1, 0, 0, 0, 0, 0, 15595), -- Astranaar Bound
(13645, 6, 2, 0, 0, 0, 0, 0, 0, 15595), -- To Raene Wolfrunner
(26474, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Orendil's Cure
(13626, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Respect for the Fallen
(13644, 33, 0, 0, 0, 0, 0, 0, 0, 15595), -- That Which Has Risen
(26464, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Lost Gem
(13624, 5, 1, 25, 0, 0, 0, 0, 0, 15595), -- A Squad of Your Own
(13632, 1, 25, 2, 0, 0, 0, 0, 0, 15595), -- Rear Guard Duty
(13630, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- The Reason Why
(26463, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- Finding Teronis
(13642, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- Bathed in Light
(26466, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Ruuzel
(26897, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Blackfathom Deeps
(13602, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Naga of the Strand
(26465, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- The Ancient Statuettes
(13617, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- West to the Strand
(13623, 25, 1, 0, 0, 0, 0, 0, 0, 15595), -- Delivery for Orendil
(13595, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Of Their Own Design
(26473, 1, 1, 6, 0, 0, 0, 0, 0, 15595), -- Bathran's Hair
(13594, 25, 6, 0, 0, 0, 0, 0, 0, 15595), -- Don't Forget the Horde
(9740, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Sun Gate
(9746, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Limits of Physical Exhaustion
(9748, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Don't Drink the Water
(9703, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Cryo-Core
(9700, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- I Shoot Magic Into the Darkness
(9699, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Truth or Fiction
(9760, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Vindicator's Rest
(9756, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- What We Don't Know...
(9779, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Intercepting the Message
(9753, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- What We Know...
(9647, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Culling the Flutterers
(9669, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Missing Expedition
(10064, 1, 1, 1, 0, 0, 0, 0, 0, 15595); -- Talk to the Hand

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9585, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Final Sample
(9550, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Map to Where?
(9549, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Artifacts of the Blacksilt
(9548, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pilfered Equipment
(9579, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Galaen's Fate
(9584, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Second Sample
(9628, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Salvaging the Data
(9672, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Bloodcurse Legacy
(9580, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Bear Necessities
(9643, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Constrictor Vines
(9632, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Newfound Allies
(9620, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Missing Survey Team
(9649, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Ysera's Tears
(9578, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Searching for Galaen
(9574, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Victims of Corruption
(9569, 15, 0, 0, 0, 0, 0, 0, 0, 15595), -- Containing the Threat
(9594, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Signs of the Legion
(9576, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cruelfin's Necklace
(10063, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Explorers' League, Is That Something for Gnomes?
(9646, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- WANTED: Deathclaw
(9567, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Know Thine Enemy
(9629, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Catch and Release
(9648, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Mac'Aree Mushroom Menagerie
(9641, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Irradiated Crystal Shards
(9694, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Blood Watch
(9581, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Learning from the Crystals
(9693, 6, 1, 1, 1, 0, 0, 0, 0, 15595), -- What Argus Means to Me
(9668, 1, 1, 0, 274, 0, 0, 0, 0, 15595), -- Report to Exarch Admetius
(9667, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Saving Princess Stillpine
(9666, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Declaration of Power
(9663, 1, 1, 1, 5, 0, 0, 0, 0, 15595), -- The Kessel Run
(9624, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Favorite Treat
(9634, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Alien Predators
(9616, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bandits!
(9144, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Missing in the Ghostlands
(9359, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Farstrider Retreat
(9067, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Party Never Ends
(9076, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wretched Ringleader
(8887, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Captain Kelisendra's Lost Rutters
(8480, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lost Armaments
(8886, 5, 1, 6, 0, 0, 500, 500, 0, 15595), -- Grimscale Pirates!
(9253, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Runewarden Deryan
(9252, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defending Fairbreeze Village
(9135, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return to Sathiel
(9134, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Skymistress Gloaming
(9133, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fly to Silvermoon City
(8491, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pelt Collection
(9254, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Wayward Apprentice
(9395, 5, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Saltheril's Haven
(9258, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Scorched Grove
(9358, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ranger Sareyn
(9130, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goods from Silvermoon City
(8892, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Situation at Sunsail Anchorage
(9256, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fairbreeze Village
(8483, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dwarven Spy
(8482, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Incriminating Documents
(8486, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Arcane Instability
(9066, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Swift Discipline
(8475, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dead Scar
(9064, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Taking the Fall
(9062, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Soaked Pages
(9035, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roadside Ambush
(9119, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Malfunction at the West Sanctum
(9352, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Darnassian Intrusions
(8895, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Delivery to the North Sanctum
(8463, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Unstable Mana Crystals
(8468, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Wanted: Thaelis the Hungerer
(8472, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Major Malfunction
(10069, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Ways of the Light
(9676, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Paladin Training
(27399, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Battle Is Won, The War Goes On
(9720, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Balance Must Be Preserved
(29566, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Checking Up
(9718, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- As the Crow Flies
(9716, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Disturbance at Umbrafen Lake
(9817, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Leader of the Bloodscale
(9730, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Leader of the Darkcrest
(27940, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dirty Birds
(27661, 34, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fire the Cannon
(27703, 396, 273, 0, 0, 0, 0, 0, 0, 15595), -- Coup de Grace
(27701, 396, 0, 0, 0, 0, 0, 0, 0, 15595), -- Dragon, Unchained
(27662, 273, 25, 0, 0, 0, 0, 0, 0, 15595), -- Unbinding
(27660, 274, 1, 0, 0, 0, 0, 0, 0, 15595), -- Spirit of the Loch
(27659, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Portal Overload
(27696, 274, 396, 6, 0, 0, 0, 0, 0, 15595), -- The Elementium Axe
(27689, 1, 397, 0, 0, 0, 0, 0, 0, 15595), -- Distract Them for Me
(27658, 396, 274, 0, 0, 0, 1000, 0, 0, 15595), -- Help from the Earthcaller
(27655, 274, 397, 0, 0, 0, 0, 0, 0, 15595), -- Bring the Hammer Down
(27653, 273, 6, 0, 0, 0, 1000, 0, 0, 15595), -- Dark Assassins
(27638, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Just You and Garona
(27503, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Up to the Citadel
(27501, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Four Heads are Better than None
(27499, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Signal the Attack
(27495, 1, 25, 15, 0, 0, 0, 0, 0, 15595), -- Move the Mountain
(27491, 1, 25, 1, 0, 0, 0, 0, 0, 15595), -- Kor'kron Drop
(27497, 274, 1, 0, 0, 0, 0, 0, 0, 15595), -- Call in the Artillery
(27493, 25, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ogres & Ettins
(28249, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Crushblow
(28247, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Last of Her Kind
(28176, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Following the Young Home
(28175, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Shining Through the Dark
(28173, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Blackout
(28191, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Fitting End
(28171, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- And the Sky Streaked Red
(28758, 5, 25, 0, 0, 0, 0, 0, 0, 15595), -- Battle of Life and Death
(28712, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Enter the Dragon Queen
(28093, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pressing Forward
(28094, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Paving the Way
(28092, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- If The Key Fits
(28097, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Gates of Grim Batol
(24535, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Thalorien Dawnseeker
(10012, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fel Orc Plans
(10022, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Elusive Ironjaw
(10002, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- The Firewing Liaison
(10007, 274, 1, 1, 0, 0, 0, 0, 0, 15595), -- Thinning the Ranks
(9996, 1, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Attack on Firewing Point
(29575, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Undercutting the Competition
(29573, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Safety is Job One
(29574, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Intriguing Specimens
(10863, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Secrets of the Arakkoa
(10869, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Thin the Flock
(10038, 1, 25, 1, 0, 0, 1000, 1000, 0, 15595), -- Speak with Private Weeks
(9992, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Olemba Seeds
(9998, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Unruly Neighbors
(10016, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Timber Worg Tails
(9986, 5, 1, 1, 0, 0, 0, 0, 0, 15595), -- Stymying the Arakkoa
(29583, 1, 1, 5, 0, 0, 0, 0, 0, 15595), -- Eckert the Mad
(10444, 5, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Report to the Allerian Post
(9994, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- What Are These Things?
(9990, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Investigate Tuurem
(10881, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Shadow Tomb
(10880, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Cabal Orders
(10852, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Missing Friends
(10839, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veil Skith: Darkstone of Terokk
(10035, 1, 1, 0, 0, 0, 1000, 0, 0, 15595), -- Torgos!
(29607, 1, 6, 0, 0, 0, 0, 0, 0, 15595), -- Eyes of Desire
(29605, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Brother Against Brother
(29606, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Terokk's Legacy
(29598, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Taretha's Diversion
(10042, 5, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Kill the Shadow Council!
(29591, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- Raging Spirits
(29590, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dead Watcher
(29596, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The End of the Exarch
(10028, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Vessels of Power
(10005, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Letting Earthbinder Tavgren Know
(10040, 6, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- Who Are They?
(10923, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Evil Draws Near
(10877, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Dread Relic
(10251, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Master's Grand Design?
(10874, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Veil Shalas: Signal Fires
(10887, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Escaping the Tomb
(10446, 5, 1, 1, 0, 0, 1000, 1000, 0, 15595), -- The Final Code
(24476, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Tempering The Blade
(8309, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Glyph Chasing
(8310, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Breaking the Code
(28865, 1, 1, 6, 5, 0, 0, 0, 0, 15595), -- Call of the Warmatron
(14482, 5, 396, 1, 0, 0, 0, 0, 0, 15595), -- Call of Duty
(28514, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Mouton Flamestar
(24461, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Reforging The Sword
(11657, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Torch Catching
(29092, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Inform the Elder
(11882, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Playing with Fire
(11935, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing Silvermoon's Flame
(9326, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Stealing the Undercity's Flame
(25546, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Traveling on Our Stomachs
(25357, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Buy Us Some Time
(25405, 396, 396, 0, 0, 0, 1000, 0, 0, 15595), -- Rest For the Weary
(25281, 1, 5, 0, 0, 0, 1000, 0, 0, 15595), -- Pay It Forward
(24432, 396, 396, 396, 0, 0, 1000, 1000, 0, 15595), -- Sea Legs
(28827, 396, 396, 0, 0, 0, 500, 0, 0, 15595), -- To the Depths
(28826, 396, 396, 396, 0, 0, 1000, 1000, 0, 15595), -- The Eye of the Storm
(25170, 94, 94, 94, 0, 0, 0, 0, 0, 15595), -- Cleaning Up the Coastline
(25167, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Breaking the Chain
(25073, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sen'jin Village
(24814, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- An Ancient Enemy
(24813, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Territorial Fetish
(24812, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- No More Mercy
(25035, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Breaking the Line
(24626, 1, 6, 1, 0, 0, 60, 60, 0, 15595), -- Young and Vicious
(24624, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Mercy for the Lost
(24625, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Consort of the Sea Witch
(24623, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Saving the Young
(24643, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- More Than Expected
(24640, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- The Arts of a Warrior
(24642, 1, 1, 0, 0, 0, 60, 0, 0, 15595), -- Proving Pit
(24641, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Rough Start
(24639, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Basics: Hitting Things
(24607, 1, 1, 1, 0, 0, 60, 60, 0, 15595), -- The Rise of the Darkspear
(13151, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- A Royal Escort
(13149, 396, 396, 0, 0, 0, 0, 0, 0, 15595), -- Dispelling Illusions
(10705, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Seer Udalo
(10628, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Akama
(10622, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Proof of Allegiance
(10686, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Warden's Cage
(10546, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Borak, Son of Oronok
(10527, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Ar'tor, Son of Oronok
(10521, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- Grom'tor, Son of Oronok
(10519, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- The Cipher of Damnation - Truth and History
(10515, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- A Lesson Learned
(10514, 1, 1, 1, 1, 0, 0, 0, 0, 15595), -- I Was A Lot Of Things...
(11548, 6, 1, 0, 0, 0, 1500, 0, 0, 15595), -- Your Continued Support
(12517, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rogues Deck
(29456, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- A Captured Banner
(13223, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defend the Siege
(29451, 1, 1, 0, 0, 0, 0, 0, 0, 15595), -- The Master Strategist
(25613, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- Do Yourself a Favor
(26470, 66, 1, 0, 0, 0, 0, 0, 0, 15595), -- Retaking Mystral Lake
(25607, 274, 1, 11, 6, 1000, 1000, 1000, 1000, 15595), -- Ze Gnomecorder
(13913, 1, 1, 1, 0, 0, 0, 0, 0, 15595), -- They Took Our Gnomes
(13979, 5, 25, 0, 0, 0, 0, 0, 0, 15595), -- The Goblin Braintrust
(25612, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Return from the Firelands
(25617, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Into the Maw!
(25355, 1, 25, 0, 0, 0, 0, 0, 0, 15595), -- Lightning in a Bottle
(25354, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Sweeping the Shelf
(25277, 1, 273, 0, 0, 0, 0, 0, 0, 15595), -- Cleaning House
(25279, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- The Shrine Reclaimed
(25272, 1, 5, 0, 0, 0, 0, 0, 0, 15595), -- Lycanthoth the Corruptor
(25270, 5, 1, 274, 0, 0, 0, 0, 0, 15595), -- Howling Mad
(25269, 1, 274, 0, 0, 0, 0, 0, 0, 15595), -- The Voice of Lo'Gosh
(27721, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Warchief's Command: Mount Hyjal!

UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=749; -- The Ravaged Caravan
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=761; -- Swoop Hunting
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9390; -- In Search of Sedai
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9398; -- Deadly Predators
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9399; -- Cruel Taskmasters
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9423; -- Return to Obadei
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9427; -- Cleansing the Waters
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9490; -- The Rock Flayer Matriarch
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9563; -- Gaining Mirren's Trust
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9752; -- Escape from Umbrafen
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9788; -- A Damp, Dark Place
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=9857; -- Talbuk Mastery
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10033; -- Wanted: Bonelashers Dead!
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10112; -- A Personal Favor
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10346; -- Return to the Abyssal Shelf
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10367; -- A Traitor Among Us
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10368; -- The Dreghood Elders
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10369; -- Arzeth's Demise
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10878; -- Before Darkness Falls
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10896; -- The Infested Protectors
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11008; -- Fires Over Skettis
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11077; -- Dragons are the Least of Our Problems
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11089; -- The Soul Cannon of Reth'hedron
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11097; -- The Deadliest Trap Ever Laid
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11202; -- Mission: Eternal Flame
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11249; -- Stop the Ascension!
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11325; -- In Worg's Clothing
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11326; -- Alpha Worg
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11328; -- Mission: Forsaken Intel
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11332; -- Mission: Plague This!
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11414; -- Brother Betrayers
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11416; -- Eyes of the Eagle
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11434; -- Forgotten Treasure
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11452; -- The Slumbering King
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11455; -- The Fragrance of Money
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11456; -- Feeding the Survivors
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11457; -- Arming Kamagua
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11458; -- Avenge Iskaal
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11459; -- Zeh'gehn Sez
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11464; -- Gambling Debt
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11466; -- Jack Likes His Drink
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11467; -- Dead Man's Debt
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11473; -- A Traitor Among Us
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11476; -- A Carver and a Croaker
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11479; -- "Crowleg" Dan
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11480; -- Meet Number Two
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11727; -- A Time for Heroes
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11731; -- Torch Tossing
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11789; -- A Soldier in Need
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11792; -- Enemies of the Light
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11797; -- The Siege
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11901; -- Military?  What Military?
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11902; -- Pernicious Evidence
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11903; -- It's Time for Action
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11908; -- Reference Material
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11913; -- Take No Chances
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11920; -- Cultists Among Us
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11922; -- Torch Tossing
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11923; -- Torch Catching
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11928; -- Farshire
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11945; -- Preparing for the Worst
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11973; -- Prisoner of War
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=11981; -- Find Kurun!
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12011; -- Signs of Big Watery Trouble
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12014; -- Steady as a Rock?
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12031; -- Freedom for the Lingering
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12032; -- Conversing With the Depths
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12105; -- Descent into Darkness
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12141; -- A Diplomatic Mission
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12160; -- A Name from the Past
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12185; -- Put on Your Best Face for Loken
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12225; -- Mmm... Amberseeds!
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12294; -- A Tentative Pact
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12295; -- An Exercise in Diplomacy
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12308; -- Escape from Silverbrook
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12372; -- Defending Wyrmrest Temple
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12419; -- The Fate of the Ruby Dragonshrine
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12435; -- Report to Lord Afrasastrasz
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12802; -- My Heart is in Your Hands
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12857; -- Wanted: Ragemane's Flipper
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=12883; -- Orders From Drakuru
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=13094; -- Have They No Shame?
UPDATE `quest_details` SET `Emote1`=0, `Emote2`=0, `Emote3`=0, `VerifiedBuild`=15595 WHERE `ID`=11905; -- Postponing the Inevitable
UPDATE `quest_details` SET `Emote1`=0, `Emote2`=0, `Emote3`=0, `VerifiedBuild`=15595 WHERE `ID`=11911; -- Quickening
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=488; -- Zenn's Bidding
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=937; -- The Enchanted Glade
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=2159; -- Dolanaar Delivery
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=2518; -- Tears of the Moon
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=6462; -- Troll Charm
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=9385; -- Rampaging Ravagers
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11471; -- The Jig is Up
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11613; -- Karuk's Oath
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11672; -- Enlistment Day
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11791; -- Notify Arlos
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11889; -- Death From Above
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11897; -- Plug the Sinkholes
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11915; -- Playing with Fire
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11964; -- Incense for the Summer Scorchlings
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11966; -- Incense for the Festival Scorchlings
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=11971; -- The Spinner of Summer Tales
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12050; -- Lumber Hack
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12075; -- Slim Pickings
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12076; -- Messy Business
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12077; -- Apply This Twice A Day
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12079; -- Stomping Grounds
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12080; -- Really Big Worm
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12082; -- Dun-da-Dun-tah!
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12116; -- It Takes Guts....
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12134; -- Sasha's Hunt
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12137; -- Chill Out, Mon
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12148; -- One of a Kind
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12149; -- Mighty Magnataur
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12150; -- Reclusive Runemaster
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12151; -- Wanton Warlord
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12158; -- Hollowstone Mine
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12159; -- Souls at Unrest
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12161; -- Ruuna the Blind
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12164; -- Hour of the Worg
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12215; -- Them or Us!
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12219; -- The Failed World Tree
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12220; -- A Dark Influence
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12246; -- A Possible Link
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12247; -- Children of Ursoc
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12261; -- No Place to Run
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12262; -- No One to Save You
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12263; -- The Best of Intentions
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12264; -- Culling the Damned
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12265; -- Defiling the Defilers
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12266; -- Tales of Destruction
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12267; -- Neltharion's Flame
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12293; -- Close the Deal
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12299; -- Northern Hospitality
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12300; -- Test of Mettle
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12302; -- Words of Warning
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12307; -- Wolfsbane Root
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12310; -- A Swift Response
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12327; -- Out of Body Experience
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12328; -- Ruuna's Request
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12329; -- Fate and Coincidence
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12330; -- Anatoly Will Talk
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12411; -- A Sister's Pledge
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12444; -- Blackriver Skirmish
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12447; -- The Obsidian Dragonshrine
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12459; -- That Which Creates Can Also Destroy
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12471; -- Cruelty of the Kvaldir
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=12484; -- Scourgekabob
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9894; -- Safeguarding the Watchers
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11348; -- The Rune of Command
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11349; -- Mastering the Runes
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11358; -- The Lodestone
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11359; -- Demolishing Megalith
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11406; -- Everything Must Be Ready
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11428; -- Keeper Witherleaf
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11501; -- News From the East
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11880; -- The Multiphase Survey
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11982; -- Raining Down Destruction
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11985; -- Into the Breach
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11986; -- The Damaged Journal
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11988; -- The Runic Keystone
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11993; -- The Runic Prophecies
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=11998; -- Softening the Blow
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12002; -- Brothers in Battle
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12003; -- Uncovering the Tunnels
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12010; -- The Fate of Orlond
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12029; -- Seared Scourge
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12070; -- Rallying the Troops
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12081; -- Gavrock
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12093; -- Runes of Compulsion
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12094; -- Latent Power
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12099; -- Free at Last
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12121; -- See You on the Other Side
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12128; -- Check Up on Raegar
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12129; -- The Perfect Plan
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12130; -- Why Fabricate When You Can Appropriate?
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12131; -- We Have the Power
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12138; -- ... Or Maybe We Don't
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12153; -- The Iron Thane and His Anvil
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12154; -- Blackout
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12180; -- The Captive Prospectors
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12183; -- Looking the Part
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12184; -- Cultivating an Image
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12212; -- Replenishing the Storehouse
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12216; -- Take Their Rear!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12217; -- Eagle Eyes
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12222; -- Secrets of the Flamebinders
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12223; -- Thinning the Ranks
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12226; -- Just Passing Through
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12255; -- The Thane of Voldrune
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12279; -- A Bear of an Appetite
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=12414; -- Mounting Up
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10227; -- I See Dead Draenei
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10228; -- Ezekiel
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11240; -- Leader of the Deranged
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11246; -- Gruesome, But Necessary
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11430; -- Harpoon Master Yavus
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11436; -- Let's Go Surfing Now
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11470; -- There Exists No Honor Among Birds
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11472; -- The Way to His Heart...
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11485; -- Iron Rune Constructs and You: Rocket Jumping
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11489; -- Iron Rune Constructs and You: Collecting Data
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11519; -- The Lost Shield of the Aesirites
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11527; -- Mutiny on the Mercy
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11529; -- Sorlof's Booty
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11567; -- The Ancient Armor of the Kvaldir
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11568; -- A Return to Resting
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11572; -- Return to Atuik
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11665; -- Crocolisks in the City
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11958; -- Let Nothing Go To Waste
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11959; -- Slay Loguhn
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=11960; -- Planning for the Future
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12007; -- Sacrifices Must be Made
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12497; -- Galakrond and the Scourge
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12498; -- On Ruby Wings
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12542; -- The Call Of The Crusade
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12859; -- This Just In: Fire Still Hot!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12861; -- Trolls Is Gone Crazy!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12884; -- The Ebon Watch
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=12887; -- It's All Fun and Games
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=10231; -- What Book? I Don't See Any Book.
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11491; -- Iron Rune Constructs and You: The Bluff
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11494; -- Lightning Infused Relics
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11495; -- The Delicate Sound of Thunder
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11507; -- Elder Atuik and Kamagua
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11508; -- Grezzix Spindlesnap
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11509; -- Street "Cred"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11510; -- "Scoodles"
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=12545; -- The Cleansing Of Jintha'kalar
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=12902; -- In Search Of Answers
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=13036; -- Honor Above All Else
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=2 WHERE `ID`=11530; -- The Shield of the Aesirites
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=11511; -- The Staff of Storm's Fury
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=11512; -- The Frozen Heart of Isuldof
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=12894; -- Crusader Forward Camp
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=5 WHERE `ID`=11231; -- Of Keys and Cages
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `Emote4`=5 WHERE `ID`=12289; -- Kick 'Em While They're Down
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=5, `Emote4`=25 WHERE `ID`=12297; -- Of Traitors and Treason
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=475; -- A Troubling Breeze
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=11199; -- Report to Scout Knowles
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=11218; -- Danger! Explosives!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=11235; -- Dealing With Gjalerbron
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=12017; -- Meat on the Hook
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=273 WHERE `ID`=11886; -- Unusual Activity
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=274 WHERE `ID`=11429; -- Drop It then Rock It!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=12227; -- Doing Your Duty
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=1 WHERE `ID`=11239; -- In Service to the Light
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=1 WHERE `ID`=12298; -- High Commander Halford Wyrmbane
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=5, `Emote3`=389 WHERE `ID`=11224; -- Send Them Packing
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=11327; -- Mission: Package Retrieval
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=6, `Emote3`=1 WHERE `ID`=12009; -- Tua'kea's Crab Traps
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=6, `Emote3`=1 WHERE `ID`=12028; -- Spiritual Insight
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=6, `Emote3`=66 WHERE `ID`=11247; -- Burn Skorn, Burn!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=25 WHERE `ID`=11331; -- You Tell Him ...Hic!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=25, `Emote3`=1 WHERE `ID`=11238; -- The Frost Wyrm and its Master
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=25, `Emote3`=5 WHERE `ID`=11469; -- Swabbin' Soap
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=25, `Emote3`=6 WHERE `ID`=11250; -- All Hail the Conqueror of Skorn!
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=273, `Emote3`=1 WHERE `ID`=12790; -- Learning to Leave and Return: the Magical Way
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=273, `Emote3`=25 WHERE `ID`=11432; -- Sleeping Giants
UPDATE `quest_details` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=743; -- Dangers of the Windfury
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=3361; -- A Refugee's Quandary
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=12052; -- Harp on This!
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=12078; -- Worm Wrangler
UPDATE `quest_details` SET `Emote1`=5 WHERE `ID`=12853; -- Luxurious Getaway!
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=12016; -- The Bait
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=12268; -- Pieces Parts
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11421; -- It Goes to 11...
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=12210; -- Troll Season!
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=13008; -- Scourge Tactics
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=13226; -- Judgment Day Comes!
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=5, `Emote4`=0, `EmoteDelay2`=60, `EmoteDelay3`=60 WHERE `ID`=13418; -- Preparations for War
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=25, `Emote4`=1 WHERE `ID`=12470; -- Mystery of the Infinite
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=5, `Emote3`=6, `Emote4`=1 WHERE `ID`=12244; -- Shredder Repair
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=25, `Emote3`=5 WHERE `ID`=11236; -- Necro Overlord Mezhen
UPDATE `quest_details` SET `Emote1`=5, `Emote3`=1, `VerifiedBuild`=15595 WHERE `ID`=8334; -- Aggression
UPDATE `quest_details` SET `Emote1`=6 WHERE `ID`=11525; -- Further Conversions
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=11188; -- Two Wrongs...
UPDATE `quest_details` SET `Emote1`=6, `Emote2`=11, `Emote3`=1, `Emote4`=1 WHERE `ID`=11068; -- Dragonmaw Race: Corlok the Vet
UPDATE `quest_details` SET `Emote1`=15, `Emote2`=1 WHERE `ID`=11187; -- Mage-Lieutenant Malister
UPDATE `quest_details` SET `Emote1`=15, `Emote2`=1, `Emote3`=1 WHERE `ID`=12030; -- Elder Mana'loa
UPDATE `quest_details` SET `Emote1`=24, `Emote2`=1, `Emote3`=1 WHERE `ID`=10026; -- Magical Disturbances
UPDATE `quest_details` SET `Emote1`=25, `Emote2`=1, `Emote3`=66 WHERE `ID`=11248; -- Operation: Skornful Wrath
UPDATE `quest_details` SET `Emote1`=66 WHERE `ID`=12109; -- Report to Gryan Stoutmantle... Again
UPDATE `quest_details` SET `Emote1`=66 WHERE `ID`=12292; -- Local Support
UPDATE `quest_details` SET `Emote1`=66, `Emote2`=1, `Emote3`=1 WHERE `ID`=11245; -- Towers of Certain Doom
UPDATE `quest_details` SET `Emote1`=274, `Emote2`=6 WHERE `ID`=11330; -- Absholutely... Thish Will Work!
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=0, `VerifiedBuild`=15595 WHERE `ID`=10889; -- Return to Shattrath
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396 WHERE `ID`=10847; -- The Eyes of Skettis
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396 WHERE `ID`=12483; -- Shimmercap Stew
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396 WHERE `ID`=12901; -- Making Something Out Of Nothing
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `Emote4`=6 WHERE `ID`=12903; -- That's What Friends Are For...
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10848; -- Veil Rhaze: Unliving Evil
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10849; -- Seek Out Kirrik
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10861; -- Veil Lithic: Preemptive Strike
UPDATE `quest_details` SET `Emote1`=396, `Emote2`=396, `Emote3`=396, `VerifiedBuild`=15595 WHERE `ID`=10879; -- The Skettis Offensive
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=10967; -- Back to the Orphanage
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=11387; -- Wanted: Tempest-Forge Destroyers
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=10942; -- Children's Week
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=10951; -- A Trip to the Dark Portal
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=10953; -- Visit the Throne of the Elements
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=10963; -- Time to Visit the Caverns
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11020; -- A Slow Death
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11035; -- The Not-So-Friendly Skies...
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11064; -- Dragonmaw Race: The Ballad of Oldie McOld
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11067; -- Dragonmaw Race: Trope the Filth-Belcher
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11377; -- Revenge is Tasty
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1 WHERE `ID`=11379; -- Super Hot Stew
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=10945; -- Hch'uu and the Mushroom People
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=11086; -- Disrupting the Twilight Portal
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=8345; -- The Shrine of Dath'Remar
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=5, `VerifiedBuild`=15595 WHERE `ID`=8325; -- Reclaiming Sunstrider Isle
UPDATE `quest_details` SET `Emote2`=1, `Emote3`=6 WHERE `ID`=11378; -- Wanted: The Epoch Hunter's Head
UPDATE `quest_details` SET `EmoteDelay1`=1500 WHERE `ID`=840; -- Conscript of the Horde
UPDATE `quest_details` SET `EmoteDelay2`=1000, `EmoteDelay3`=1000, `VerifiedBuild`=15595 WHERE `ID`=10031; -- Helping the Lost Find Their Way
UPDATE `quest_details` SET `EmoteDelay2`=1000, `VerifiedBuild`=15595 WHERE `ID`=10030; -- Recover the Bones
UPDATE `quest_details` SET `EmoteDelay2`=3000, `EmoteDelay3`=5000 WHERE `ID`=10873; -- Taken in the Night
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9424; -- Makuru's Vengeance
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9697; -- Watcher Leesa'oh
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9727; -- Now That We're Still Friends...
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9789; -- Clefthoof Mastery
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9854; -- Windroc Mastery
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9855; -- Windroc Mastery
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9951; -- It's Watching You!
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9957; -- What's Wrong at Cenarion Thicket?
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9968; -- Strange Energy
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9971; -- Clues in the Thicket
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9978; -- By Any Means Necessary
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=9979; -- Wind Trader Lathrai
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=10096; -- Saving the Sporeloks
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=10840; -- The Tomb of Lights
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=10842; -- Vengeful Souls
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=10929; -- Fumping
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=10930; -- The Big Bone Worm
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=11984; -- Filling the Cages
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=11989; -- Truce?
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=11990; -- Vial of Visions
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=11991; -- Subject to Interpretation
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12037; -- Search and Rescue
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12042; -- Heart of the Ancients
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12068; -- Voices From the Dust
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12113; -- Nice to Meat You
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12114; -- Therapy
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12120; -- Drak'aguul's Mallet
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12152; -- Jin'arrak's End
UPDATE `quest_details` SET `VerifiedBuild`=15595 WHERE `ID`=12190; -- Say Hello to My Little Friend
