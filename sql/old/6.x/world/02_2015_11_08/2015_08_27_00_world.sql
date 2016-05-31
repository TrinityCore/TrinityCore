UPDATE `creature_template` SET `npcflag` = 2 WHERE `entry` IN (69742, 70166, 70551, 72373, 72755, 74888, 75081, 75120, 75469, 75644, 75913, 76067, 76447, 76452, 76616, 76746, 76904, 77161, 77775, 77777, 77778, 77781, 77791, 77792, 77831, 77857, 78207, 78470, 78495, 78520, 78538, 78561, 78562, 78792, 78810, 78821, 78937, 79315, 79316, 79337, 79604, 79608, 79814, 79817, 79820, 79830, 79831, 79833, 79863, 79897, 80159, 80746, 80987, 81123, 81193, 81292, 81324, 81412, 81415, 81600, 81674, 81913, 81915, 81948, 82070, 82214, 82227, 82252, 82375, 82509, 82612, 82622, 82664, 82669, 82720, 83820, 84259, 84261, 84270, 84492, 84728, 84892, 84973, 84975, 85130, 85190, 85206, 85378, 85379, 85749, 85840, 86366, 86696, 88173, 88193, 88392, 88570, 89400, 90644, 91029, 91030, 91031, 91033, 91034, 92317, 93658, 93659);

DELETE FROM `creature_questender` WHERE `id` IN (69741, 69742, 70166, 70296, 70301, 70320, 70551, 70552, 72373, 72755, 73136, 74888, 75081, 75120, 75469, 75644, 75913, 76067, 76447, 76452, 76616, 76746, 76904, 77161, 77775, 77777, 77778, 77781, 77791, 77792, 77831, 77857, 78207, 78470, 78495, 78520, 78538, 78561, 78562, 78792, 78810, 78821, 78937, 79315, 79316, 79337, 79604, 79608, 79814, 79817, 79820, 79830, 79831, 79833, 79863, 79897, 80159, 80746, 80987, 81123, 81193, 81292, 81324, 81412, 81415, 81600, 81674, 81913, 81915, 81948, 82070, 82214, 82227, 82252, 82375, 82509, 82612, 82622, 82664, 82669, 82720, 83820, 84259, 84261, 84270, 84492, 84728, 84892, 84973, 84975, 85130, 85190, 85206, 85378, 85379, 85484, 85749, 85840, 85849, 86366, 86696, 88173, 88193, 88392, 88570, 89400, 90644, 91029, 91030, 91031, 91033, 91034, 92317, 93658, 93659);
INSERT INTO `creature_questender` VALUES
(69741, 32652), -- Lady Jaina Proudmoore, To the Skies!
(69742, 32277), -- Lor'themar Theron, To the Skies!
(70166, 32325), -- Jubeka Shadowbreaker, Infiltrating the Black Temple
(70296, 32665), -- Mei Lin, Learn To Ride
(70301, 32667), -- Softpaws, Learn To Ride
(70320, 32296), -- Taoshi, Treasures of the Thunder King
(70551, 32292), -- Scout Captain Elsia, Forge Ahead!
(70551, 32722), -- Scout Captain Elsia, Forge Ahead!
(70552, 32587), -- Scout Captain Daelin, Forge Ahead!
(70552, 32724), -- Scout Captain Daelin, Forge Ahead!
(72373, 32993), -- Karg Bloodfury, The Strength of Our Bonds
(72755, 32976), -- Rolo's Treasure, Rolo's Riddle
(73136, 33138), -- Lorewalker Cho, Why Do We Fight?
(74888, 33513), -- Koristrasza, Blackthorn's Lieutenants
(74888, 33514), -- Koristrasza, The Ritual
(75081, 33525), -- Young Orc Woman, Treasure: Orc Couple
(75120, 33531), -- Clumsy Cragmaul Brute, Treasure: Fallen Ogre
(75469, 33579), -- Raksi, What the Draenei Found
(75644, 33649), -- Iron Scout, Treasure: Torched Iron Horde Scout
(75913, 33761), -- Crystal-Shaper Barum, Barum's Notes
(75913, 33740), -- Crystal-Shaper Barum, Burning Sky
(75913, 33734), -- Crystal-Shaper Barum, Pieces of Us
(76067, 33081), -- Yrel, Escape From Shaz'gul
(76447, 33833), -- Eremor, Wanted: Kuu'rat's Tusks
(76452, 34729), -- Weaponsmith Na'Shra, Blood Oath of Na'Shra
(76616, 33816), -- Farseer Drek'Thar, Honor Has Its Rewards
(76746, 33919), -- Der'shway, Wanted: Gutsmash the Destroyer
(76904, 33931), -- Deceptia, This Is Not a Quest
(77161, 34033), -- Thaelin Darkanvil, And The Mole You Rode In On
(77161, 34030), -- Thaelin Darkanvil, The Captive Engineer
(77775, 36644), -- Kaya Solasen, Your First Jewelcrafting Work Order
(77775, 36842), -- Kaya Solasen, Your Second Jewelcrafting Work Order
(77777, 36647), -- Kurt Broadoak, Your First Inscription Work Order
(77777, 36841), -- Kurt Broadoak, Your Second Inscription Work Order
(77778, 36643), -- Kaylie Macdonald, Your First Tailoring Work Order
(77778, 36845), -- Kaylie Macdonald, Your Second Tailoring Work Order
(77781, 36645), -- Garm, Your First Enchanting Work Order
(77781, 36839), -- Garm, Your Second Enchanting Work Order
(77791, 36641), -- Peter Kearie, Your First Alchemy Work Order
(77791, 36838), -- Peter Kearie, Your Second Alchemy Work Order
(77792, 35168), -- Yulia Samras, Your First Blacksmithing Work Order
(77792, 35172), -- Yulia Samras, Your Second Blacksmithing Work Order
(77831, 36646), -- Helayn Whent, Your First Engineering Work Order
(77831, 36840), -- Helayn Whent, Your Second Engineering Work Order
(77857, 35009), -- Ka'alu, Call of the Raven Mother
(78207, 36642), -- Marianne Levine, Your First Leatherworking Work Order
(78207, 36844), -- Marianne Levine, Your Second Leatherworking Work Order
(78470, 34362), -- Owynn Graddock, The Shadow Gate
(78495, 36692), -- Shadow Hunter Ukambe, Assault on Darktide Roost
(78495, 36690), -- Shadow Hunter Ukambe, Assault on Lost Veil Anzu
(78495, 36697), -- Shadow Hunter Ukambe, Assault on Magnarok
(78495, 36693), -- Shadow Hunter Ukambe, Assault on Mok'gol Watchpost
(78495, 36689), -- Shadow Hunter Ukambe, Assault on Pillars of Fate
(78495, 36667), -- Shadow Hunter Ukambe, Assault on Shattrath Harbor
(78495, 36688), -- Shadow Hunter Ukambe, Assault on Skettis
(78495, 36691), -- Shadow Hunter Ukambe, Assault on Socrethar's Rise
(78495, 36669), -- Shadow Hunter Ukambe, Assault on Stonefury Cliffs
(78495, 36694), -- Shadow Hunter Ukambe, Assault on the Broken Precipice
(78495, 36695), -- Shadow Hunter Ukambe, Assault on the Everbloom Wilds
(78495, 36699), -- Shadow Hunter Ukambe, Assault on the Heart of Shattrath
(78495, 36696), -- Shadow Hunter Ukambe, Assault on the Iron Siegeworks
(78495, 36701), -- Shadow Hunter Ukambe, Assault on the Pit
(78495, 36698), -- Shadow Hunter Ukambe, Battle in Ashran
(78495, 36700), -- Shadow Hunter Ukambe, Challenge at the Ring of Blood
(78495, 38182), -- Shadow Hunter Ukambe, Missive: Assault on Darktide Roost
(78495, 38184), -- Shadow Hunter Ukambe, Missive: Assault on Lost Veil Anzu
(78495, 38177), -- Shadow Hunter Ukambe, Missive: Assault on Magnarok
(78495, 38181), -- Shadow Hunter Ukambe, Missive: Assault on Mok'gol Watchpost
(78495, 38185), -- Shadow Hunter Ukambe, Missive: Assault on Pillars of Fate
(78495, 38187), -- Shadow Hunter Ukambe, Missive: Assault on Shattrath Harbor
(78495, 38186), -- Shadow Hunter Ukambe, Missive: Assault on Skettis
(78495, 38183), -- Shadow Hunter Ukambe, Missive: Assault on Socrethar's Rise
(78495, 38176), -- Shadow Hunter Ukambe, Missive: Assault on Stonefury Cliffs
(78495, 38180), -- Shadow Hunter Ukambe, Missive: Assault on the Broken Precipice
(78495, 38179), -- Shadow Hunter Ukambe, Missive: Assault on the Everbloom Wilds
(78495, 38178), -- Shadow Hunter Ukambe, Missive: Assault on the Iron Siegeworks
(78520, 34351), -- Soulbinder Tuulani, We Must Construct Additional Pylons
(78538, 34447), -- Vindicator Doruu, Kaelynara Sunchaser
(78538, 34448), -- Vindicator Doruu, Kaelynara Sunchaser
(78538, 34399), -- Vindicator Doruu, Trouble In The Mine
(78561, 34429), -- Archmage Khadgar, Kill Your Hundred
(78562, 34436), -- Archmage Khadgar, Keli'dan the Breaker
(78562, 34741), -- Archmage Khadgar, Keli'dan the Breaker
(78792, 34381), -- Shadow Hunter Bwu'ja, The Shadow Gate
(78810, 34289), -- Owynn Graddock, Soulgrinder Survivor
(78821, 34319), -- Shadow Hunter Bwu'ja, Soulgrinder Survivor
(78937, 34450), -- Rexxar, Rylak Rescue
(79315, 34739), -- Olin Umberhide, The Shadowmoon Clan
(79316, 34432), -- Qiana Moonshadow, The Shadowmoon Clan
(79337, 35883), -- Pitfighter Vaandaam, The Fists of Vaandaam
(79604, 33731), -- Durotan, The Battle for Shattrath
(79608, 34099), -- Yrel, The Battle for Shattrath
(79814, 37568), -- Keyana Tone, Your First Alchemy Work Order
(79814, 36838), -- Keyana Tone, Your Second Alchemy Work Order
(79817, 37569), -- Kinja, Your First Blacksmithing Work Order
(79817, 35172), -- Kinja, Your Second Blacksmithing Work Order
(79820, 37570), -- Garra, Your First Enchanting Work Order
(79820, 36839), -- Garra, Your Second Enchanting Work Order
(79830, 37573), -- Elrondir Surrion, Your First Jewelcrafting Work Order
(79830, 36842), -- Elrondir Surrion, Your Second Jewelcrafting Work Order
(79831, 37572), -- Y'rogg, Your First Inscription Work Order
(79831, 36841), -- Y'rogg, Your Second Inscription Work Order
(79833, 37574), -- Yanney, Your First Leatherworking Work Order
(79833, 36844), -- Yanney, Your Second Leatherworking Work Order
(79863, 37575), -- Turga, Your First Tailoring Work Order
(79863, 36845), -- Turga, Your Second Tailoring Work Order
(79897, 34516), -- Bazwix, My Precious!
(80159, 33461), -- Arsenio Zerep, Gloomshade Game Hunter
(80746, 34924), -- Vakora of the Flock, The Egg Thieves
(80746, 36790), -- Vakora of the Flock, The Initiate's Revenge
(80987, 35262), -- Rangari Kaalya, Service of Rangari Kaalya
(80987, 35834), -- Rangari Kaalya, Wake of the Genesaur
(81123, 35068), -- Captain "Victorious" Chong, If They Won't Surrender...
(81123, 35067), -- Captain "Victorious" Chong, Silence the War Machines
(81123, 35069), -- Captain "Victorious" Chong, Terror of Nagrand
(81193, 35100), -- Blood Guard Ehanes, If They Won't Surrender...
(81193, 35099), -- Blood Guard Ehanes, Silence the War Machines
(81193, 35101), -- Blood Guard Ehanes, Terror of Nagrand
(81193, 35271), -- Blood Guard Ehanes, The Warsong Threat
(81292, 33834), -- Dyuna, Wanted: Kliaa's Stinger
(81324, 37332), -- Rangari Sheera, Fungal Bundle
(81412, 35169), -- Vindicator Yrel, And Justice for Thrall
(81415, 35171), -- Durotan, And Justice for Thrall
(81600, 35208), -- Burrian Coalpart, Dark Iron Down
(81674, 35870), -- Nisha, Basilisk Butcher
(81674, 35026), -- Nisha, On the Mend
(81913, 35275), -- Shadow Hunter Ukambe, Inspecting the Troops
(81915, 35276), -- Jasper Fel, Inspecting the Troops
(81948, 34646), -- Qiana Moonshadow, Qiana Moonshadow
(82070, 35317), -- Farseer Drek'Thar, The Dark Heart of Oshu'gun
(82214, 35396), -- Vindicator Nobundo, The Dark Heart of Oshu'gun
(82227, 33836), -- Orrin, Wanted: Maa'run's Hoof
(82252, 35386), -- Captain Washburn, The Warsong Threat
(82375, 35482), -- Admiral Taylor, Admiral Taylor
(82375, 36183), -- Admiral Taylor, Admiral Taylor
(82509, 35634), -- Darkscryer Raastok, Control is King
(82612, 35672), -- Hutou Featherwind, Wanted: Venombarb
(82622, 35670), -- Killga, Wanted: Spineslicer's Husk
(82664, 35675), -- Quartermaster Jolie, Wanted: Spineslicer's Husk
(82669, 35676), -- Falrogh the Drunk, Wanted: Venombarb
(82720, 35671), -- Shadow-Sage Iskar, A Gathering of Shadows
(83820, 36037), -- High Centurion Tormmok, A Centurion Without a Cause
(84259, 36166), -- Lunzul, No Time to Waste
(84261, 36165), -- Kolrigg Stoktron, No Time to Waste
(84270, 36160), -- Baros Alexston, Garrison Campaign: Every Rose Has Its Thorn
(84492, 36185), -- Garaal, Fair Trade
(84728, 36241), -- Ardule D'na, The Power of Preservation
(84892, 36296), -- Phylarch the Evergreen, Phylarch the Evergreen
(84973, 36164), -- Exarch Akama, The Trial of Courage
(84975, 36167), -- Exarch Naielle, The Trial of Heart
(85130, 35654), -- Glirin, Chapter I: Plant Food
(85130, 35651), -- Glirin, Chapter II: The Harvest
(85130, 35650), -- Glirin, Chapter III: Ritual of the Charred
(85130, 35652), -- Glirin, Growing Wood
(85190, 36375), -- Sethekk Idol, Spires - Treasure 026 - Sethekk Idol
(85206, 36377), -- Rukhmar's Image, Spires - Treasure 049 - Rukhmar's Image
(85378, 36429), -- Weldon Barov, The Rise and Fall of Barov Industries: Weldon Barov
(85379, 36427), -- Alexi Barov, The Rise and Fall of Barov Industries: Alexi Barov
(85484, 36477), -- Chester, Broken Promises
(85749, 36791), -- Gimlet Ginfizz, Phantom Potion
(85749, 36741), -- Gimlet Ginfizz, Vintage Free Action Potion
(85840, 37290), -- Torgg Flexington, Upgrades in Ashran
(85849, 37288), -- Kinkade Jakobs, Resources in Ashran
(86366, 36935), -- Tyra Silverblood, Phantom Potion
(86366, 36742), -- Tyra Silverblood, Vintage Free Action Potion
(86696, 37571), -- Garbra Fizzwonk, Your First Engineering Work Order
(88173, 37276), -- Dark Ranger Velonara, Standing United
(88193, 37281), -- Hulda Shadowblade, Standing United
(88392, 37270), -- Alchemy Follower - Horde, Alchemy Experiment
(88570, 36055), -- Fate-Twister Tiklal, Sealing Fate: Apexis Crystals
(88570, 37458), -- Fate-Twister Tiklal, Sealing Fate: Extended Honor
(88570, 36056), -- Fate-Twister Tiklal, Sealing Fate: Garrison Resources
(88570, 36054), -- Fate-Twister Tiklal, Sealing Fate: Gold
(88570, 37452), -- Fate-Twister Tiklal, Sealing Fate: Heap of Apexis Crystals
(88570, 36057), -- Fate-Twister Tiklal, Sealing Fate: Honor
(88570, 37455), -- Fate-Twister Tiklal, Sealing Fate: Immense Fortune of Gold
(88570, 37459), -- Fate-Twister Tiklal, Sealing Fate: Monumental Honor
(88570, 37453), -- Fate-Twister Tiklal, Sealing Fate: Mountain of Apexis Crystals
(88570, 37454), -- Fate-Twister Tiklal, Sealing Fate: Piles of Gold
(88570, 37456), -- Fate-Twister Tiklal, Sealing Fate: Stockpiled Garrison Resources
(88570, 37457), -- Fate-Twister Tiklal, Sealing Fate: Tremendous Garrison Resources
(89400, 38223), -- Reshad, Dark Ascension
(90644, 38578), -- Lagar the Wise, A Message of Terrible Import
(91029, 38290), -- Rath'thul Moonvale, Some Dust
(91030, 38243), -- Trixxy Volt, A Bit of Ore
(91031, 38296), -- Nicholas Mitrik, Herbs Galore
(91033, 38287), -- Zeezu, Raw Beast Hides
(91034, 38293), -- Calvo Klyne, Sumptuous Fur
(92317, 38274), -- Ariok, The Eye of Kilrogg
(93658, 39394), -- Exarch Yrel, The Cipher of Damnation
(93659, 38463); -- Farseer Drek'Thar, The Cipher of Damnation
