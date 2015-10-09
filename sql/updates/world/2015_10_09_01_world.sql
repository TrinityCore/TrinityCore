UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (70859, 70860, 70909, 70910, 70941, 72230, 72274, 72814, 72836, 72837, 72874, 72890, 72940, 72976, 73097, 73480, 74000, 74163, 74223, 74253, 74272, 74273, 74330, 74409, 74635, 74651, 74977, 75177, 75186, 75188, 75606, 76111, 76240, 76411, 76484, 76487, 76557, 76609, 76662, 76720, 76730, 76862, 76889, 77160, 77167, 77209, 77210, 77217, 77367, 77377, 77378, 77730, 77733, 77789, 77928, 77998, 78056, 78208, 78209, 78222, 78239, 78272, 78323, 78428, 78466, 78487, 78553, 78554, 78558, 78559, 78560, 78563, 78564, 78568, 78569, 78659, 78785, 78989, 78994, 78996, 79047, 79229, 79457, 79492, 79537, 79675, 79740, 79774, 79815, 79826, 79836, 79857, 79858, 79862, 79892, 79896, 79917, 79953, 79971, 80193, 80260, 80341, 80389, 80456, 80521, 80617, 80632, 81086, 81152, 81166, 81209, 81210, 81492, 81678, 81688, 81912, 81981, 82123, 82270, 82302, 82447, 82466, 82851, 83006, 83482, 83491, 83858, 83899, 83900, 84247, 84248, 84268, 84286, 84494, 84511, 84524, 84689, 84739, 84747, 84776, 84857, 84889, 84928, 84929, 84947, 84967, 85048, 85106, 85213, 85247, 85344, 85369, 85413, 85414, 85418, 85439, 85440, 85708, 85751, 85777, 85882, 85984, 86272, 86629, 86677, 86803, 86806, 86832, 86884, 86927, 86933, 86934, 86945, 86946, 86964, 86973, 86974, 86979, 87112, 87113, 87114, 87115, 87116, 87117, 87118, 87119, 87120, 87121, 87122, 87206, 87207, 87208, 87209, 87210, 87211, 87212, 87213, 87214, 87215, 87216, 87217, 87225, 87242, 87305, 87971, 87991, 87992, 87994, 87995, 87996, 87997, 87998, 87999, 88000, 88001, 88002, 88003, 88004, 88005, 88006, 88007, 88009, 88013, 88017, 88022, 88023, 88024, 88025, 88026, 88027, 88112, 88145, 88147, 88223, 88228, 88395, 88458, 88545, 88546, 88892, 90675, 90894, 91014, 91015, 91016, 91017, 91020, 91024, 91025, 91026, 91070, 91071, 91072, 91242, 91361, 91362, 91363, 91364, 91404, 91589, 92213, 92219, 92400, 94429, 94789, 94801, 94870, 95659);

DELETE FROM `creature_queststarter` WHERE `id` IN (56541, 57913, 69522, 70859, 70860, 70909, 70910, 70941, 72230, 72274, 72814, 72836, 72837, 72874, 72890, 72940, 72976, 73097, 73480, 74000, 74163, 74222, 74223, 74253, 74272, 74273, 74330, 74358, 74367, 74409, 74507, 74635, 74651, 74808, 74977, 75177, 75186, 75188, 75606, 76111, 76240, 76411, 76484, 76487, 76557, 76609, 76622, 76662, 76720, 76730, 76862, 76889, 76941, 77160, 77167, 77209, 77210, 77217, 77354, 77356, 77359, 77363, 77365, 77367, 77372, 77377, 77378, 77382, 77383, 77730, 77733, 77789, 77928, 77998, 78056, 78185, 78192, 78208, 78209, 78222, 78239, 78272, 78323, 78423, 78428, 78430, 78466, 78487, 78553, 78554, 78558, 78559, 78560, 78563, 78564, 78568, 78569, 78573, 78659, 78746, 78785, 78985, 78989, 78994, 78996, 79047, 79229, 79252, 79415, 79457, 79492, 79537, 79661, 79675, 79740, 79774, 79813, 79815, 79821, 79826, 79829, 79832, 79834, 79836, 79857, 79858, 79862, 79864, 79867, 79892, 79896, 79899, 79917, 79953, 79971, 80163, 80193, 80260, 80265, 80341, 80389, 80456, 80470, 80521, 80568, 80617, 80632, 80645, 81086, 81152, 81153, 81166, 81209, 81210, 81492, 81678, 81688, 81761, 81762, 81763, 81912, 81981, 82123, 82270, 82302, 82447, 82466, 82776, 82833, 82851, 83006, 83482, 83491, 83858, 83899, 83900, 84247, 84248, 84268, 84286, 84494, 84511, 84524, 84684, 84689, 84739, 84747, 84776, 84811, 84857, 84889, 84928, 84929, 84947, 84967, 85048, 85106, 85213, 85247, 85344, 85369, 85413, 85414, 85418, 85439, 85440, 85708, 85751, 85777, 85882, 85984, 86272, 86589, 86614, 86629, 86677, 86803, 86806, 86832, 86884, 86927, 86933, 86934, 86945, 86946, 86964, 86973, 86974, 86979, 87112, 87113, 87114, 87115, 87116, 87117, 87118, 87119, 87120, 87121, 87122, 87206, 87207, 87208, 87209, 87210, 87211, 87212, 87213, 87214, 87215, 87216, 87217, 87225, 87242, 87247, 87305, 87971, 87991, 87992, 87994, 87995, 87996, 87997, 87998, 87999, 88000, 88001, 88002, 88003, 88004, 88005, 88006, 88007, 88009, 88013, 88017, 88022, 88023, 88024, 88025, 88026, 88027, 88112, 88145, 88147, 88223, 88228, 88395, 88458, 88545, 88546, 88705, 88892, 89753, 89763, 89793, 89805, 89806, 90675, 90894, 91014, 91015, 91016, 91017, 91020, 91024, 91025, 91026, 91070, 91071, 91072, 91195, 91196, 91242, 91361, 91362, 91363, 91364, 91404, 91589, 92213, 92219, 92223, 92400, 94429, 94789, 94801, 94870, 95659);
DELETE FROM `creature_questender` WHERE `id` IN (70859, 70860, 70909, 70910, 70941, 72230, 72274, 72814, 72836, 72837, 72874, 72890, 72940, 72976, 73097, 73480, 74000, 74163, 74223, 74253, 74272, 74273, 74330, 74409, 74635, 74651, 74977, 75177, 75186, 75188, 75606, 76111, 76240, 76411, 76484, 76487, 76557, 76609, 76662, 76720, 76730, 76862, 76889, 77160, 77167, 77209, 77210, 77217, 77367, 77377, 77378, 77730, 77733, 77789, 77928, 77998, 78056, 78208, 78209, 78222, 78239, 78272, 78323, 78428, 78466, 78487, 78553, 78554, 78558, 78559, 78560, 78563, 78564, 78568, 78569, 78659, 78785, 78989, 78994, 78996, 79047, 79229, 79457, 79492, 79537, 79675, 79740, 79774, 79815, 79826, 79836, 79857, 79858, 79862, 79892, 79896, 79917, 79953, 79971, 80193, 80260, 80341, 80389, 80456, 80521, 80617, 80632, 81086, 81152, 81166, 81209, 81210, 81492, 81678, 81688, 81912, 81981, 82123, 82270, 82302, 82447, 82466, 82851, 83006, 83482, 83491, 83858, 83899, 83900, 84247, 84248, 84268, 84286, 84494, 84511, 84524, 84689, 84739, 84747, 84776, 84857, 84889, 84928, 84929, 84947, 84967, 85048, 85106, 85213, 85247, 85344, 85369, 85413, 85414, 85418, 85439, 85440, 85708, 85751, 85777, 85882, 85984, 86272, 86629, 86677, 86803, 86806, 86832, 86884, 86927, 86933, 86934, 86945, 86946, 86964, 86973, 86974, 86979, 87112, 87113, 87114, 87115, 87116, 87117, 87118, 87119, 87120, 87121, 87122, 87206, 87207, 87208, 87209, 87210, 87211, 87212, 87213, 87214, 87215, 87216, 87217, 87225, 87242, 87305, 87971, 87991, 87992, 87994, 87995, 87996, 87997, 87998, 87999, 88000, 88001, 88002, 88003, 88004, 88005, 88006, 88007, 88009, 88013, 88017, 88022, 88023, 88024, 88025, 88026, 88027, 88112, 88145, 88147, 88223, 88228, 88395, 88458, 88545, 88546, 88892, 90675, 90894, 91014, 91015, 91016, 91017, 91020, 91024, 91025, 91026, 91070, 91071, 91072, 91242, 91361, 91362, 91363, 91364, 91404, 91589, 92213, 92219, 92400, 94429, 94789, 94801, 94870, 95659);

INSERT INTO `creature_queststarter` VALUES
(56541, 31342), -- Master Snowdrift, The Path to Respect Lies in Violence
(57913, 30102), -- Chromie, The Hour of Twilight
(69522, 32497), -- Dread Wastes Flame Guardian, Honor the Flame
(70859, 34364), -- Thrall, For the Horde!
(70860, 32783), -- Durotan, Ga'nar's Vengeance
(70860, 34380), -- Durotan, Rally the Frostwolves
(70860, 33468), -- Durotan, Save Wolf Home
(70860, 32989), -- Durotan, Securing the South
(70860, 33526), -- Durotan, These Colors Don't Run
(70909, 32791), -- Ga'nar, Let the Hunt Begin!
(70910, 32794), -- Ga'nar, Wrath of Gronn
(70941, 32795), -- Ga'nar, The Eldest
(70941, 32796), -- Ga'nar, To the Garrison
(72230, 33444), -- Draka, Eatercology
(72230, 32980), -- Draka, Eaters of the Elements
(72274, 32991), -- Lokra, Into the Boneslag
(72274, 32992), -- Lokra, Moving Target
(72274, 32993), -- Lokra, The Strength of Our Bonds
(72274, 32990), -- Lokra, They Who Held Fast
(72814, 34216), -- Cordana Felsong, Safe Passage
(72836, 34228), -- Cordana Felsong, A Clew of Worms
(72836, 34292), -- Cordana Felsong, Eliminate the Shadow Council
(72836, 34277), -- Cordana Felsong, Stop the Flow
(72837, 34278), -- Farseer Urquan, Desecration of the Dead
(72837, 34229), -- Farseer Urquan, The Sleeper Has Awakened
(72837, 34227), -- Farseer Urquan, What Must Be Done
(72874, 34280), -- Archmage Khadgar, All is Revealed
(72874, 34230), -- Archmage Khadgar, Eye Need That
(72874, 34291), -- Archmage Khadgar, Have a Heart
(72890, 33483), -- Mulverick, Mulverick's Plight
(72940, 33493), -- Frostwolf Champion, Return to the Pack
(72940, 33828), -- Frostwolf Champion, The Master Siegesmith
(72976, 33125), -- Outrider Urukag, A Proper Parting
(72976, 33132), -- Outrider Urukag, Gut Guttra
(73097, 32994), -- Frostwolf Champion, Enfilade
(73097, 33785), -- Frostwolf Champion, Karg Unchained
(73097, 33826), -- Frostwolf Champion, Where's My Wolf?!
(73480, 34293), -- Image of Archmage Khadgar, Eliminate the Shadow Council
(73480, 34294), -- Image of Archmage Khadgar, The Fel Crystals
(73480, 34295), -- Image of Archmage Khadgar, To Capture Gul'dan
(74000, 32792), -- Ga'nar, Leave Nothing Behind!
(74163, 33010), -- Durotan, The Iron Wolf
(74163, 37291), -- Durotan, Thunderlord Invasion!
(74222, 32929), -- Ligra the Unyielding, They Rely on Numbers
(74223, 32804), -- Kal'gor the Honorable, Articles of the Fallen
(74253, 32983), -- Farseer Drek'Thar, In the Shadow of Giants
(74253, 32984), -- Farseer Drek'Thar, The Ascent
(74272, 33473), -- Farseer Drek'Thar, Back to Bladespire Citadel
(74272, 33470), -- Farseer Drek'Thar, Pool of Visions
(74273, 33546), -- Durotan, Deeds Left Undone
(74330, 32985), -- Farseer Drek'Thar, Fury of Frostfire
(74358, 33013), -- Wounded Frostwolf Shaman, Of Fire and Thunder
(74367, 33513), -- Koristrasza, Blackthorn's Lieutenants
(74367, 33514), -- Koristrasza, The Ritual
(74409, 34673), -- Zeya, The Rise of Aku'mai
(74507, 33807), -- Wor'gol Defender, Free Our Brothers and Sisters
(74635, 33454), -- Igrimar the Resolute, The Cure
(74635, 33467), -- Igrimar the Resolute, The Fall of the Warlord
(74635, 33450), -- Igrimar the Resolute, The Warlord's Guard
(74651, 33469), -- Draka, The Farseer
(74808, 32979), -- Thrall, Garrison Campaign: Farseer's Rock
(74977, 33838), -- Initiate Na'Shra, Smeltcraft
(75177, 33408), -- Durotan, Great Balls of Fire!
(75177, 33527), -- Durotan, Last Steps
(75186, 33344), -- Thrall, Armed and Dangerous
(75186, 33410), -- Thrall, The Butcher of Bladespire
(75186, 33622), -- Thrall, To the Slaughter
(75188, 33657), -- Durotan, Moving In
(75606, 34672), -- Sentinel Aluwyn, The Rise of Aku'mai
(76111, 35496), -- Enohar Thunderbrew, Enohar's Revenge
(76240, 33526), -- Durotan, These Colors Don't Run
(76411, 33815), -- Farseer Drek'Thar, A Song of Frost and Fire
(76411, 34379), -- Farseer Drek'Thar, Den of Wolves
(76484, 34867), -- Durotan, The Secrets of Gorgrond
(76487, 34124), -- Lokra, The Battle of Thunder Pass
(76557, 33784), -- Durotan, Gormaul Tower
(76609, 35764), -- Okrilla, Okrilla's Revenge
(76609, 35761), -- Okrilla, Ransacking Nethergarde
(76622, 33427), -- Thrall, Ours is the Fury
(76662, 33898), -- Gol'kosh the Axe, Slaying Slavers
(76720, 34123), -- Thrall, To Thunder Pass
(76730, 37563), -- Makar Stonebinder, The Frostwolves Stand Ready
(76862, 33915), -- Gog'rak, Young Hearts
(76889, 33929), -- Shivertail, Shivertail's Den
(76941, 33955), -- Kar'lak, Missing Pack
(77160, 34030), -- Hansel Heavyhands, The Captive Engineer
(77160, 34029), -- Hansel Heavyhands, The Prototype
(77167, 34048), -- Dark Iron Golem, "Mole Machine, Go Home"
(77167, 34033), -- Dark Iron Golem, And The Mole You Rode In On
(77167, 34032), -- Dark Iron Golem, Privileged Information
(77167, 34031), -- Dark Iron Golem, Something to Remember Me By
(77209, 36592), -- Baros Alexston, Bigger is Better
(77209, 34587), -- Baros Alexston, Build Your Barracks
(77209, 36100), -- Baros Alexston, Building for Professions
(77209, 36160), -- Baros Alexston, Garrison Campaign: Every Rose Has Its Thorn
(77209, 34026), -- Baros Alexston, Garrison Campaign: Seismic Matters
(77209, 39195), -- Baros Alexston, Gems of the Apexis
(77209, 35176), -- Baros Alexston, Keeping it Together
(77209, 36615), -- Baros Alexston, My Very Own Castle
(77209, 37288), -- Baros Alexston, Resources in Ashran
(77209, 35166), -- Baros Alexston, Ship Salvage
(77210, 34264), -- Scout Ruk'Gan, A Collection of Coils
(77210, 34070), -- Scout Ruk'Gan, At the End of Your Rope
(77210, 34073), -- Scout Ruk'Gan, Burn Them Down
(77210, 34093), -- Scout Ruk'Gan, Getting the Points
(77210, 34066), -- Scout Ruk'Gan, Savage Vengeance
(77210, 34072), -- Scout Ruk'Gan, Tar Get of Opportunity
(77210, 34075), -- Scout Ruk'Gan, Vul'gath's End
(77217, 34027), -- Jr. Surveyor Dorn, Groundbreaking Data
(77217, 34028), -- Jr. Surveyor Dorn, These Look Familiar...
(77354, 36645), -- Ayada the White, Your First Enchanting Work Order
(77356, 36644), -- Costan Highwall, Your First Jewelcrafting Work Order
(77359, 35168), -- Auria Irondreamer, Your First Blacksmithing Work Order
(77363, 36641), -- Mary Kearie, Your First Alchemy Work Order
(77365, 36646), -- Zaren Hoffle, Your First Engineering Work Order
(77367, 36848), -- Archmage Kem, Ogre Waygates
(77367, 38354), -- Archmage Kem, Portable Portals
(77372, 36647), -- Eric Broadoak, Your First Inscription Work Order
(77377, 38175), -- Kristen Stoneforge, Scrap Meltdown
(77377, 37092), -- Kristen Stoneforge, Scraps of Iron
(77378, 37086), -- Hennick Helmsley, Salvaging the Situation
(77382, 36643), -- Christopher Macdonald, Your First Tailoring Work Order
(77383, 36642), -- Anders Longstitch, Your First Leatherworking Work Order
(77730, 34192), -- Timothy Leens, Things Are Not Goren Our Way
(77733, 36517), -- Ron Ashton, Abyssal Gulper Eel
(77733, 36515), -- Ron Ashton, Blackwater Whiptail
(77733, 36514), -- Ron Ashton, Blind Lake Sturgeon
(77733, 36513), -- Ron Ashton, Fat Sleeper
(77733, 36510), -- Ron Ashton, Fire Ammonite
(77733, 36511), -- Ron Ashton, Jawless Skulker
(77733, 34194), -- Ron Ashton, Looking For Help
(77789, 34774), -- Blingtron 5000, Blingtron 5000
(77928, 34041), -- Gazlowe, Four Finger Discount
(77928, 34035), -- Gazlowe, I Know The Drill!
(77928, 34040), -- Gazlowe, Maker's Mark
(77998, 34321), -- Molthron, Ashes Of The Past
(77998, 34325), -- Molthron, Flames Of The Earth
(78056, 34285), -- Owynn Graddock, Gearing Up
(78056, 34281), -- Owynn Graddock, Out of the Chains
(78185, 34286), -- Owynn Graddock, Seeking the Truth
(78192, 34335), -- Choluna, Garrison Campaign: Crows In The Field
(78208, 34344), -- Shadow Hunter Rala, Lurkers
(78208, 34731), -- Shadow Hunter Rala, Oath of Shadow Hunter Rala
(78208, 34345), -- Shadow Hunter Rala, Poulticide
(78208, 34348), -- Shadow Hunter Rala, The Real Prey
(78209, 34346), -- Shadow Hunter Mala, Frosted Fury
(78222, 33119), -- Guse, Slavery and Strife
(78239, 34362), -- Owynn Graddock, The Shadow Gate
(78272, 34402), -- Durotan, Of Wolves and Warriors
(78323, 34042), -- Goblin Engineer, A Fellow Gearhead
(78323, 34078), -- Goblin Engineer, Payment Due for Services Rendered
(78323, 34039), -- Goblin Engineer, Wanted: Overlord Blackhammer
(78423, 36881), -- Archmage Khadgar, The Dark Portal
(78428, 34287), -- Orlana Strongbrow, Cleansing the Souls
(78428, 34469), -- Orlana Strongbrow, Cleansing the Souls
(78428, 34289), -- Orlana Strongbrow, Soulgrinder Survivor
(78428, 34319), -- Orlana Strongbrow, Soulgrinder Survivor
(78428, 34288), -- Orlana Strongbrow, The Totems That Bind
(78428, 34318), -- Orlana Strongbrow, The Totems That Bind
(78430, 34439), -- Cordana Felsong, The Battle of the Forge
(78466, 34592), -- Gazlowe, A Gronnling Problem
(78466, 36706), -- Gazlowe, Ashran Appearance
(78466, 34375), -- Gazlowe, Back to Work
(78466, 36567), -- Gazlowe, Bigger is Better
(78466, 34461), -- Gazlowe, Build Your Barracks
(78466, 37669), -- Gazlowe, Building for Professions
(78466, 34378), -- Gazlowe, Establish Your Garrison
(78466, 39175), -- Gazlowe, Gems of the Apexis
(78466, 36614), -- Gazlowe, My Very Own Fortress
(78466, 34765), -- Gazlowe, The Den of Skog
(78466, 37290), -- Gazlowe, Upgrades in Ashran
(78466, 34861), -- Gazlowe, We Need An Army
(78466, 34824), -- Gazlowe, What We Got
(78466, 34822), -- Gazlowe, What We Need
(78487, 34653), -- Rokhan, Arakkoa Exodus
(78487, 36136), -- Rokhan, Garrison Campaign: Awakening
(78487, 35876), -- Rokhan, Garrison Campaign: Darktide Roost
(78487, 35843), -- Rokhan, Garrison Campaign: Deep Recon
(78487, 34034), -- Rokhan, Garrison Campaign: Grinding Gears
(78487, 34309), -- Rokhan, Garrison Campaign: The Search for Shadow Hunter Bwu'ja
(78487, 34681), -- Rokhan, It's a Matter of Strategy
(78487, 34794), -- Rokhan, Taking the Fight to Nagrand
(78487, 34823), -- Rokhan, The Ogron Live?
(78487, 34736), -- Rokhan, We Be Needin' Supplies
(78553, 35005), -- Thrall, Prepare for Battle
(78553, 34739), -- Thrall, The Shadowmoon Clan
(78554, 35019), -- Vindicator Maraad, Prepare for Battle
(78554, 34432), -- Vindicator Maraad, The Shadowmoon Clan
(78558, 35933), -- Archmage Khadgar, Azeroth's Last Stand
(78558, 34392), -- Archmage Khadgar, Onslaught's End
(78558, 34420), -- Archmage Khadgar, The Cost of War
(78558, 34393), -- Archmage Khadgar, The Portal's Power
(78559, 34423), -- Archmage Khadgar, Altar Altercation
(78559, 34422), -- Archmage Khadgar, Blaze of Glory
(78560, 34427), -- Archmage Khadgar, A Potential Ally
(78560, 34478), -- Archmage Khadgar, A Potential Ally
(78560, 34429), -- Archmage Khadgar, Kill Your Hundred
(78560, 34425), -- Archmage Khadgar, The Kargathar Proving Grounds
(78563, 35747), -- Archmage Khadgar, Taking a Trip to the Top of the Tank
(78564, 36171), -- Sergeant Crowler, Botani Invasion!
(78564, 36376), -- Sergeant Crowler, Goren Invasion!
(78564, 36655), -- Sergeant Crowler, Iron Horde Invasion!
(78564, 36650), -- Sergeant Crowler, Ogre Invasion!
(78564, 36830), -- Sergeant Crowler, Shadow Council Invasion!
(78564, 36412), -- Sergeant Crowler, Shadowmoon Invasion!
(78568, 34958), -- Thaelin Darkanvil, The Shadow of the Worldbreaker
(78569, 34987), -- Hansel Heavyhands, The Gunpowder Plot
(78573, 34421), -- Korag, Bled Dry
(78659, 34315), -- Shadow Hunter Bwu'ja, Gearing Up
(78659, 34314), -- Shadow Hunter Bwu'ja, Out of the Chains
(78746, 34316), -- Shadow Hunter Bwu'ja, Seeking the Truth
(78785, 34381), -- Shadow Hunter Bwu'ja, The Shadow Gate
(78985, 34309), -- Shadow Hunter Moj'jar, Garrison Campaign: The Search for Shadow Hunter Bwu'ja
(78989, 36207), -- Axe-Shaper Kugra, Waruk the Frostforger
(78994, 34434), -- Yrel, Yrel
(78994, 34740), -- Yrel, Yrel
(78996, 34442), -- Farseer Drek'Thar, Ga'nar of the Frostwolf
(79047, 34732), -- Mulverick, Mulverick's Offer of Service
(79047, 33484), -- Mulverick, The Slavemaster's Demise
(79229, 32981), -- Gronnstalker Rokash, Only the Winner
(79252, 34209), -- Cordana Felsong, Vouchsafe Our Arrival
(79415, 33807), -- Durotan, Free Our Brothers and Sisters
(79457, 34778), -- Vindicator Maraad, Migrant Workers
(79457, 35174), -- Vindicator Maraad, Pale Moonlight
(79457, 34646), -- Vindicator Maraad, Qiana Moonshadow
(79492, 34733), -- Dagg, Services of Dagg
(79537, 34436), -- Exarch Maladaar, Keli'dan the Breaker
(79661, 34431), -- Luuka, Masters of Shadow
(79661, 34737), -- Luuka, Masters of Shadow
(79675, 34741), -- Lady Liadrin, Keli'dan the Breaker
(79740, 36248), -- Warmaster Zog, A Stolen Heart
(79740, 36261), -- Warmaster Zog, Garrison Campaign: Missing Grunt
(79740, 34775), -- Warmaster Zog, Mission Probable
(79740, 38427), -- Warmaster Zog, New Goods
(79740, 37434), -- Warmaster Zog, Proving Grounds
(79740, 36242), -- Warmaster Zog, Where There Is Smoke...
(79740, 34462), -- Warmaster Zog, Winds of Change
(79774, 36653), -- Sergeant Grimjaw, Botani Invasion!
(79774, 35142), -- Sergeant Grimjaw, Goren Invasion!
(79774, 35935), -- Sergeant Grimjaw, Iron Horde Invasion!
(79774, 36623), -- Sergeant Grimjaw, Ogre Invasion!
(79774, 36831), -- Sergeant Grimjaw, Shadow Council Invasion!
(79774, 36414), -- Sergeant Grimjaw, Shadowmoon Invasion!
(79813, 37568), -- Albert de Hyde, Your First Alchemy Work Order
(79815, 38188), -- Grun'lek, Scrap Meltdown
(79815, 37043), -- Grun'lek, Scraps of Iron
(79821, 37570), -- Yukla Greenshadow, Your First Enchanting Work Order
(79826, 37571), -- Pozzlow, Your First Engineering Work Order
(79829, 37572), -- Urgra, Your First Inscription Work Order
(79832, 37573), -- Dorogarr, Your First Jewelcrafting Work Order
(79834, 37574), -- Murne Greenhoof, Your First Leatherworking Work Order
(79836, 36848), -- Gez'la, Ogre Waygates
(79836, 38351), -- Gez'la, Portable Portals
(79857, 37045), -- Lumba the Crusher, Salvaging the Situation
(79858, 40329), -- Serr'ah, Battle Pet Tamers: Warlords
(79858, 37645), -- Serr'ah, Mastering the Menagerie
(79858, 36469), -- Serr'ah, Pets Versus Pests
(79858, 36662), -- Serr'ah, Scrappin'
(79858, 38242), -- Serr'ah, Unearthed Magic
(79862, 37060), -- Yorn Longhoof, Lost in Transition
(79864, 37575), -- Warra the Weaver, Your First Tailoring Work Order
(79867, 37569), -- Orgek Ironhand, Your First Blacksmithing Work Order
(79892, 35075), -- Mak'jin, Abyssal Gulper Eel
(79892, 35074), -- Mak'jin, Blackwater Whiptail
(79892, 35073), -- Mak'jin, Blind Lake Sturgeon
(79892, 35072), -- Mak'jin, Fat Sleeper
(79892, 35066), -- Mak'jin, Fire Ammonite
(79892, 35071), -- Mak'jin, Jawless Skulker
(79892, 34758), -- Mak'jin, Looking For Help
(79896, 36132), -- Mokugg Lagerpounder, Anglin' In Our Garrison
(79896, 36141), -- Mokugg Lagerpounder, Icespine Stingers
(79896, 36131), -- Mokugg Lagerpounder, Proving Your Worth
(79899, 34516), -- Bazwix, My Precious!
(79917, 34925), -- Ga'nar, Polishing the Iron Throne
(79917, 34437), -- Ga'nar, The Prodigal Frostwolf
(79953, 36624), -- Lieutenant Thorn, Ashran Appearance
(79953, 34692), -- Lieutenant Thorn, Delegating on Draenor
(79953, 38408), -- Lieutenant Thorn, New Goods
(79953, 37433), -- Lieutenant Thorn, Proving Grounds
(79971, 36608), -- Rak'jin, Finding Nat Pagle
(79971, 36612), -- Rak'jin, Luring Nat
(80163, 34820), -- Ken Loggin, Lost Lumberjacks
(80193, 34874), -- Kirin Tor Magus, Next Steps
(80260, 34875), -- Magister Serena, Next Steps
(80265, 34805), -- Reshad, Echo Hunters
(80341, 34858), -- Horde Grunt, Prized Repossessions
(80341, 34855), -- Horde Grunt, Punching Through
(80341, 34860), -- Horde Grunt, Supply Recovery
(80341, 34870), -- Horde Grunt, The Lord of the Gordunni
(80389, 34712), -- Kirin Tor Magus, Due Cause to Celebrate
(80389, 34890), -- Kirin Tor Magus, The Final Step
(80456, 33816), -- Farseer Drek'Thar, Honor Has Its Rewards
(80470, 34838), -- Kaliri Egg, Ikky's Egg
(80521, 34445), -- Thaelin Darkanvil, A Taste of Iron
(80521, 34446), -- Thaelin Darkanvil, The Home Stretch
(80521, 35884), -- Thaelin Darkanvil, The Home Stretch
(80568, 33075), -- Yrel, A Hero's Welcome
(80617, 34711), -- Kirin Tor Magus, Due Cause to Celebrate
(80617, 34912), -- Kirin Tor Magus, The Final Step
(80632, 34978), -- Alliance Soldier, Prized Repossessions
(80632, 34979), -- Alliance Soldier, Punching Through
(80632, 34980), -- Alliance Soldier, The Lord of the Gordunni
(80645, 33359), -- Cordana Felsong, Meet Us at Starfall Outpost
(81086, 35061), -- Uruk Foecleaver, The Pride of Lok-rath
(81086, 35097), -- Uruk Foecleaver, The Pride of Lok-rath
(81152, 33814), -- Scout Valdez, Fast Expansion
(81153, 33814), -- Scout Valdez, Fast Expansion
(81166, 35103), -- Refugee Lo'nash, The Alchemist
(81209, 35104), -- Kadar, The Apprentice
(81210, 35106), -- Ang'kra, Avenge and Reclaim
(81492, 34653), -- Bodrick Grey, Arakkoa Exodus
(81492, 36134), -- Bodrick Grey, Garrison Campaign: Awakening
(81492, 35861), -- Bodrick Grey, Garrison Campaign: Darktide Roost
(81492, 35837), -- Bodrick Grey, Garrison Campaign: Deep Recon
(81492, 34284), -- Bodrick Grey, Garrison Campaign: The Search for Owynn Graddock
(81492, 37184), -- Bodrick Grey, Taking the Fight to Nagrand
(81492, 37183), -- Bodrick Grey, The Critical Path
(81678, 33412), -- Snowrunner Rolga, Mopping Up
(81688, 35154), -- Gorsol, Things Are Not Goren Our Way
(81761, 35241), -- Ashka, Vengeance for the Fallen
(81762, 35240), -- Taag, Bled Dry
(81763, 35242), -- Rephuura, Vengeance for the Fallen
(81912, 34779), -- Foreman Zipfizzle, Circle the Wagon
(81981, 34193), -- Tarnon, Clearing the Garden
(82123, 35261), -- Inactive Apexis Destroyer, Shot-Caller
(82270, 35460), -- Vindicator Maraad, Attack of the Iron Horde
(82270, 36307), -- Vindicator Maraad, Investigating the Invasion
(82270, 35463), -- Vindicator Maraad, Subversive Scouts
(82270, 35462), -- Vindicator Maraad, Under Siege
(82302, 33706), -- Birchus, Laying Dionor to Rest
(82302, 36443), -- Birchus, Laying Dionor to Rest
(82447, 35494), -- Commander Vines, Mementos of the Fallen
(82466, 35343), -- Aenir, The Young Alchemist
(82776, 36163), -- Deedree, Garrison Campaign: The Exarch's Call
(82833, 35736), -- Tattered Journal Page, Writing in the Snow
(82833, 35737), -- Tattered Journal Page, Writing in the Snow
(82851, 35745), -- Thrall, Attack of the Iron Horde
(82851, 36292), -- Thrall, Investigating the Invasion
(82851, 35748), -- Thrall, Subversive Scouts
(82851, 35746), -- Thrall, Under Siege
(83006, 39107), -- Griftah, An Even Bigga Score
(83006, 37284), -- Griftah, Da Big Score
(83482, 36256), -- Yu'rina the Mystic, The Arakkoan Enchanter
(83491, 36310), -- Eileese Shadowsong, The Arakkoan Enchanter
(83858, 35988), -- Khadgar's Servant, Call of the Archmage
(83858, 35679), -- Khadgar's Servant, Garrison Campaign: The Fall of Shattrath
(83858, 35680), -- Khadgar's Servant, Garrison Campaign: The Fall of Shattrath
(83858, 35185), -- Khadgar's Servant, Garrison Campaign: The Sargerei
(83858, 35186), -- Khadgar's Servant, Garrison Campaign: The Sargerei
(83899, 36047), -- Dark Ranger Velonara, We Have Him Now
(83900, 36048), -- Hulda Shadowblade, We Have Him Now
(84247, 36137), -- Lumber Lord Oktron, Easing into Lumberjacking
(84247, 36142), -- Lumber Lord Oktron, Sharper Blades, Bigger Timber
(84247, 36182), -- Lumber Lord Oktron, Tree-i-cide
(84247, 36138), -- Lumber Lord Oktron, Turning Timber into Profit
(84248, 36189), -- Justin Timberlord, Easing into Lumberjacking
(84248, 36194), -- Justin Timberlord, Sharper Blades, Bigger Timber
(84248, 36195), -- Justin Timberlord, Tree-i-cide
(84248, 36192), -- Justin Timberlord, Turning Timber into Profit
(84268, 38408), -- Lieutenant Thorn, New Goods
(84286, 37091), -- Zee, Unconventional Inventions
(84494, 36238), -- Waruk the Frostforger, Mending A Broken Heart
(84494, 36230), -- Waruk the Frostforger, The Restless Spirit
(84511, 36162), -- Lieutenant Thorn, A Stolen Heart
(84524, 36274), -- Homer Stonefield, Bigger Trap, Better Rewards
(84524, 36271), -- Homer Stonefield, Breaking into the Trap Game
(84524, 36272), -- Homer Stonefield, Feeding An Army
(84684, 36161), -- Lieutenant Thorn, Where There Is Smoke...
(84689, 36419), -- Trega, Dyed in the Fur
(84689, 36417), -- Trega, From Their Cold Dead Hands
(84739, 36257), -- Arcanist Delath, Failed Apprentice
(84747, 36260), -- Torag Stonefury, Oru'kai's Scepter
(84776, 36262), -- Aerun, Ameeka, Master Tailor
(84811, 35505), -- Thuldren, Lost Lumberjack
(84857, 37087), -- Kyra Goldhands, Lost in Transition
(84889, 36813), -- Phylarch the Evergreen, Subversive Infestation
(84928, 35745), -- Thrall, Attack of the Iron Horde
(84928, 35751), -- Thrall, Attack on Nethergarde
(84928, 35762), -- Thrall, Death to the Dreadmaul
(84928, 35763), -- Thrall, Gar'mak Bladetwist
(84928, 35750), -- Thrall, Lunatic Lieutenants
(84928, 35760), -- Thrall, Toothsmash the Annihilator
(84928, 35746), -- Thrall, Under Siege
(84928, 36940), -- Thrall, Warning the Warchief
(84929, 35460), -- Vindicator Maraad, Attack of the Iron Horde
(84929, 35488), -- Vindicator Maraad, Death to the Dreadmaul
(84929, 35492), -- Vindicator Maraad, For Nethergarde!
(84929, 35500), -- Vindicator Maraad, Gar'mak Bladetwist
(84929, 35486), -- Vindicator Maraad, Lunatic Lieutenants
(84929, 36941), -- Vindicator Maraad, Report to the King
(84929, 35495), -- Vindicator Maraad, Toothsmash the Annihilator
(84929, 35462), -- Vindicator Maraad, Under Siege
(84947, 37119), -- Lysa Serion, The Headhunter's Harvest
(84967, 36352), -- "Appraiser" Sazsel Stickyfingers, Locating the Lapidarist
(85048, 36346), -- Farmer Lok'lub, Bigger Trap, Better Rewards
(85048, 36345), -- Farmer Lok'lub, Breaking into the Trap Game
(85048, 36344), -- Farmer Lok'lub, Feeding An Army
(85106, 36380), -- Gem Grinder Orolak, Diamonds Are Forever
(85106, 36378), -- Gem Grinder Orolak, No Pressure, No Diamonds
(85213, 35464), -- Bodrick Grey, Ending Executions
(85213, 36379), -- Bodrick Grey, Peeking into the Portal
(85247, 35744), -- Rokhan, Ending Executions
(85247, 36382), -- Rokhan, Peeking into the Portal
(85344, 36404), -- Naron Bloomthistle, Clearing the Garden
(85369, 37044), -- Vee, Unconventional Inventions
(85413, 36448), -- Weldon Barov, Reduction in Force
(85414, 36449), -- Alexi Barov, Reduction in Force
(85418, 36483), -- Lio the Lioness, Battle Pet Roundup
(85418, 40329), -- Lio the Lioness, Battle Pet Tamers: Warlords
(85418, 37644), -- Lio the Lioness, Mastering the Menagerie
(85418, 36423), -- Lio the Lioness, Pets Versus Pests
(85418, 38241), -- Lio the Lioness, Unearthed Magic
(85439, 36457), -- Raleigh Puule, Bypassing Security
(85440, 36475), -- Nicholaus Page, Stealing the Declaration
(85708, 36608), -- Segumi, Finding Nat Pagle
(85708, 36870), -- Segumi, Luring Nat
(85751, 36516), -- Gaoda Hidecleaver, Cut 'Em Out!
(85777, 36522), -- Ahm, Solidarity in Death
(85882, 36594), -- Blixthraz Blastcharge, "Spare" Parts
(85882, 36627), -- Blixthraz Blastcharge, Big Frostfire Gun
(85984, 36611), -- Nat Pagle, A True Draenor Angler
(85984, 36802), -- Nat Pagle, Abyssal Gulper Lunker
(85984, 36803), -- Nat Pagle, Blackwater Whiptail Lunker
(85984, 36804), -- Nat Pagle, Blind Lake Lunker
(85984, 36805), -- Nat Pagle, Fat Sleeper Lunker
(85984, 39283), -- Nat Pagle, Felmouth Frenzy Lunker
(85984, 36800), -- Nat Pagle, Fire Ammonite Lunker
(85984, 36806), -- Nat Pagle, Jawless Skulker Lunker
(85984, 38406), -- Nat Pagle, Sea Scorpion Lunker
(86272, 36702), -- Meatball, Meatball
(86589, 36861), -- Watchman Tilnia, Pinchwhistle Gearworks
(86614, 36862), -- Murla Longeye, Pinchwhistle Gearworks
(86629, 36897), -- Raza'kul, Nemesis: Becoming Death
(86629, 36923), -- Raza'kul, Nemesis: Becoming Death
(86629, 36925), -- Raza'kul, Nemesis: Becoming Death
(86629, 36927), -- Raza'kul, Nemesis: Becoming Death
(86629, 36929), -- Raza'kul, Nemesis: Becoming Death
(86629, 36931), -- Raza'kul, Nemesis: Becoming Death
(86629, 36933), -- Raza'kul, Nemesis: Becoming Death
(86629, 36930), -- Raza'kul, Nemesis: Draenei Destroyer
(86629, 36924), -- Raza'kul, Nemesis: Dwarfstalker
(86629, 36926), -- Raza'kul, Nemesis: Gnomebane
(86629, 36889), -- Raza'kul, Nemesis: Hunter - Hunted
(86629, 36921), -- Raza'kul, Nemesis: Manslayer
(86629, 36932), -- Raza'kul, Nemesis: Scourge of the Kaldorei
(86629, 36934), -- Raza'kul, Nemesis: Terror of the Tushui
(86629, 36928), -- Raza'kul, Nemesis: Worgen Hunter
(86629, 36874), -- Raza'kul, Warlord of Draenor
(86677, 36957), -- Kuros, Nemesis: Becoming Death
(86677, 36959), -- Kuros, Nemesis: Becoming Death
(86677, 36961), -- Kuros, Nemesis: Becoming Death
(86677, 36963), -- Kuros, Nemesis: Becoming Death
(86677, 36965), -- Kuros, Nemesis: Becoming Death
(86677, 36967), -- Kuros, Nemesis: Becoming Death
(86677, 36969), -- Kuros, Nemesis: Becoming Death
(86677, 36960), -- Kuros, Nemesis: Death Stalker
(86677, 36955), -- Kuros, Nemesis: Hunter - Hunted
(86677, 36968), -- Kuros, Nemesis: Huojin's Fall
(86677, 36970), -- Kuros, Nemesis: Killer of Kezan
(86677, 36964), -- Kuros, Nemesis: Orcslayer
(86677, 36958), -- Kuros, Nemesis: Slayer of Sin'dorei
(86677, 36962), -- Kuros, Nemesis: The Butcher
(86677, 36966), -- Kuros, Nemesis: Troll Hunter
(86677, 36876), -- Kuros, Warlord of Draenor
(86803, 37062), -- Fayla Fairfeather, Tricks of the Trade
(86806, 37014), -- Ancient Trading Mechanism, Auctioning for Parts
(86832, 31034), -- Vol'jin, Enemies Below
(86832, 26293), -- Vol'jin, Machines of War
(86832, 25275), -- Vol'jin, Report to the Labor Captain
(86832, 26840), -- Vol'jin, Return to the Highlands
(86832, 28909), -- Vol'jin, Sauranok Will Point the Way
(86832, 26830), -- Vol'jin, Traitor's Bait
(86832, 26324), -- Vol'jin, Where Is My Warfleet?
(86884, 25267), -- Darkspear Loyalist, Message for Vol'jin
(86927, 37080), -- Stormshield Death Knight, Glorious Slaughter
(86927, 37129), -- Stormshield Death Knight, Unwelcome Memories
(86933, 37081), -- Warspear Magus, Burning Rage
(86933, 37131), -- Warspear Magus, The Dark Lady's Concern
(86934, 37127), -- Sha'tari Defender, The Light of Exodus
(86934, 37047), -- Sha'tari Defender, The Light's Gift
(86945, 37070), -- Sunsworn Warlock, Power of the Nether
(86945, 37128), -- Sunsworn Warlock, Settling Grievances
(86946, 37137), -- Outcast Talonpriest, Scrying Hard or Hardly Scrying
(86946, 37182), -- Outcast Talonpriest, Scrying Hard or Hardly Scrying
(86946, 37084), -- Outcast Talonpriest, The Shadows Call
(86964, 37085), -- Bloodmane Earthbinder, Fury of the Clan
(86964, 37140), -- Bloodmane Earthbinder, Leorajh's Prayer Beads
(86964, 37181), -- Bloodmane Earthbinder, Leorajh's Prayer Beads
(86973, 36913), -- Keegan Firebeard, Besting a Boar
(86973, 36997), -- Keegan Firebeard, Boar Training: Bulbapore
(86973, 36998), -- Keegan Firebeard, Boar Training: Cruel Ogres
(86973, 36999), -- Keegan Firebeard, Boar Training: Darkwing Roc
(86973, 36996), -- Keegan Firebeard, Boar Training: Gezz'ran
(86973, 37002), -- Keegan Firebeard, Boar Training: Ironbore
(86973, 37000), -- Keegan Firebeard, Boar Training: Moth of Wrath
(86973, 37003), -- Keegan Firebeard, Boar Training: Orc Hunters
(86973, 36995), -- Keegan Firebeard, Boar Training: Riplash
(86973, 37004), -- Keegan Firebeard, Boar Training: The Garn
(86973, 37001), -- Keegan Firebeard, Boar Training: Thundercall
(86973, 36916), -- Keegan Firebeard, Capturing a Clefthoof
(86973, 36987), -- Keegan Firebeard, Clefthoof Training: Bulbapore
(86973, 36988), -- Keegan Firebeard, Clefthoof Training: Cruel Ogres
(86973, 36989), -- Keegan Firebeard, Clefthoof Training: Darkwing Roc
(86973, 36986), -- Keegan Firebeard, Clefthoof Training: Gezz'ran
(86973, 36983), -- Keegan Firebeard, Clefthoof Training: Great-Tusk
(86973, 36992), -- Keegan Firebeard, Clefthoof Training: Ironbore
(86973, 36990), -- Keegan Firebeard, Clefthoof Training: Moth of Wrath
(86973, 36993), -- Keegan Firebeard, Clefthoof Training: Orc Hunters
(86973, 36984), -- Keegan Firebeard, Clefthoof Training: Rakkiri
(86973, 36985), -- Keegan Firebeard, Clefthoof Training: Riplash
(86973, 36994), -- Keegan Firebeard, Clefthoof Training: The Garn
(86973, 36991), -- Keegan Firebeard, Clefthoof Training: Thundercall
(86973, 37015), -- Keegan Firebeard, Elekk Training: Cruel Ogres
(86973, 37016), -- Keegan Firebeard, Elekk Training: Darkwing Roc
(86973, 37019), -- Keegan Firebeard, Elekk Training: Ironbore
(86973, 37017), -- Keegan Firebeard, Elekk Training: Moth of Wrath
(86973, 37020), -- Keegan Firebeard, Elekk Training: Orc Hunters
(86973, 37021), -- Keegan Firebeard, Elekk Training: The Garn
(86973, 37018), -- Keegan Firebeard, Elekk Training: Thundercall
(86973, 36915), -- Keegan Firebeard, Entangling an Elekk
(86974, 36918), -- Fanny Firebeard, Requisition a Riverbeast
(86974, 37006), -- Fanny Firebeard, Riverbeast Training: Bulbapore
(86974, 37007), -- Fanny Firebeard, Riverbeast Training: Cruel Ogres
(86974, 37008), -- Fanny Firebeard, Riverbeast Training: Darkwing Roc
(86974, 37005), -- Fanny Firebeard, Riverbeast Training: Gezz'ran
(86974, 37011), -- Fanny Firebeard, Riverbeast Training: Ironbore
(86974, 37009), -- Fanny Firebeard, Riverbeast Training: Moth of Wrath
(86974, 37012), -- Fanny Firebeard, Riverbeast Training: Orc Hunters
(86974, 37013), -- Fanny Firebeard, Riverbeast Training: The Garn
(86974, 37010), -- Fanny Firebeard, Riverbeast Training: Thundercall
(86974, 36975), -- Fanny Firebeard, Talbuk Training: Bulbapore
(86974, 36976), -- Fanny Firebeard, Talbuk Training: Cruel Ogres
(86974, 36977), -- Fanny Firebeard, Talbuk Training: Darkwing Roc
(86974, 36974), -- Fanny Firebeard, Talbuk Training: Gezz'ran
(86974, 36971), -- Fanny Firebeard, Talbuk Training: Great-Tusk
(86974, 36980), -- Fanny Firebeard, Talbuk Training: Ironbore
(86974, 36978), -- Fanny Firebeard, Talbuk Training: Moth of Wrath
(86974, 36981), -- Fanny Firebeard, Talbuk Training: Orc Hunters
(86974, 36972), -- Fanny Firebeard, Talbuk Training: Rakkiri
(86974, 36973), -- Fanny Firebeard, Talbuk Training: Riplash
(86974, 36982), -- Fanny Firebeard, Talbuk Training: The Garn
(86974, 36979), -- Fanny Firebeard, Talbuk Training: Thundercall
(86974, 36911), -- Fanny Firebeard, Taming a Talbuk
(86974, 37122), -- Fanny Firebeard, Teeth of a Predator
(86974, 37121), -- Fanny Firebeard, The Black Claw
(86974, 37022), -- Fanny Firebeard, Wolf Training: Cruel Ogres
(86974, 37023), -- Fanny Firebeard, Wolf Training: Darkwing Roc
(86974, 37026), -- Fanny Firebeard, Wolf Training: Ironbore
(86974, 37024), -- Fanny Firebeard, Wolf Training: Moth of Wrath
(86974, 37027), -- Fanny Firebeard, Wolf Training: Orc Hunters
(86974, 37028), -- Fanny Firebeard, Wolf Training: The Garn
(86974, 37025), -- Fanny Firebeard, Wolf Training: Thundercall
(86974, 36914), -- Fanny Firebeard, Wrangling a Wolf
(86979, 36944), -- Tormak the Scarred, Besting a Boar
(86979, 37034), -- Tormak the Scarred, Boar Training: Bulbapore
(86979, 37035), -- Tormak the Scarred, Boar Training: Cruel Ogres
(86979, 37036), -- Tormak the Scarred, Boar Training: Darkwing Roc
(86979, 37033), -- Tormak the Scarred, Boar Training: Gezz'ran
(86979, 37039), -- Tormak the Scarred, Boar Training: Ironbore
(86979, 37037), -- Tormak the Scarred, Boar Training: Moth of Wrath
(86979, 37040), -- Tormak the Scarred, Boar Training: Orc Hunters
(86979, 37032), -- Tormak the Scarred, Boar Training: Riplash
(86979, 37041), -- Tormak the Scarred, Boar Training: The Garn
(86979, 37038), -- Tormak the Scarred, Boar Training: Thundercall
(86979, 36912), -- Tormak the Scarred, Capturing a Clefthoof
(86979, 37052), -- Tormak the Scarred, Clefthoof Training: Bulbapore
(86979, 37053), -- Tormak the Scarred, Clefthoof Training: Cruel Ogres
(86979, 37054), -- Tormak the Scarred, Clefthoof Training: Darkwing Roc
(86979, 37051), -- Tormak the Scarred, Clefthoof Training: Gezz'ran
(86979, 37048), -- Tormak the Scarred, Clefthoof Training: Great-Tusk
(86979, 37057), -- Tormak the Scarred, Clefthoof Training: Ironbore
(86979, 37055), -- Tormak the Scarred, Clefthoof Training: Moth of Wrath
(86979, 37058), -- Tormak the Scarred, Clefthoof Training: Orc Hunters
(86979, 37049), -- Tormak the Scarred, Clefthoof Training: Rakkiri
(86979, 37050), -- Tormak the Scarred, Clefthoof Training: Riplash
(86979, 37059), -- Tormak the Scarred, Clefthoof Training: The Garn
(86979, 37056), -- Tormak the Scarred, Clefthoof Training: Thundercall
(86979, 37063), -- Tormak the Scarred, Elekk Training: Cruel Ogres
(86979, 37064), -- Tormak the Scarred, Elekk Training: Darkwing Roc
(86979, 37067), -- Tormak the Scarred, Elekk Training: Ironbore
(86979, 37065), -- Tormak the Scarred, Elekk Training: Moth of Wrath
(86979, 37068), -- Tormak the Scarred, Elekk Training: Orc Hunters
(86979, 37069), -- Tormak the Scarred, Elekk Training: The Garn
(86979, 37066), -- Tormak the Scarred, Elekk Training: Thundercall
(86979, 36946), -- Tormak the Scarred, Entangling an Elekk
(87112, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87113, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87114, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87115, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87116, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87117, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87118, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87119, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87120, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87121, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87122, 37205), -- Gargra, Gargra
(87206, 36948), -- Ancient Trading Mechanism, Auctioning for Parts
(87207, 37088), -- Trader Joseph, Tricks of the Trade
(87208, 37088), -- Trader Joseph, Tricks of the Trade
(87209, 37088), -- Trader Joseph, Tricks of the Trade
(87210, 37088), -- Trader Joseph, Tricks of the Trade
(87211, 37088), -- Trader Joseph, Tricks of the Trade
(87212, 37088), -- Trader Joseph, Tricks of the Trade
(87213, 37088), -- Trader Joseph, Tricks of the Trade
(87214, 37088), -- Trader Joseph, Tricks of the Trade
(87215, 37088), -- Trader Joseph, Tricks of the Trade
(87216, 37088), -- Trader Joseph, Tricks of the Trade
(87217, 37088), -- Trader Joseph, Tricks of the Trade
(87225, 37029), -- Goraluk Anvilcrack, Sigil of the Black Hand
(87225, 37030), -- Goraluk Anvilcrack, Sigil of the Black Hand (Heroic)
(87225, 37031), -- Goraluk Anvilcrack, Sigil of the Black Hand (Mythic)
(87242, 36945), -- Sage Paluna, Requisition a Riverbeast
(87242, 37072), -- Sage Paluna, Riverbeast Training: Bulbapore
(87242, 37073), -- Sage Paluna, Riverbeast Training: Cruel Ogres
(87242, 37074), -- Sage Paluna, Riverbeast Training: Darkwing Roc
(87242, 37071), -- Sage Paluna, Riverbeast Training: Gezz'ran
(87242, 37077), -- Sage Paluna, Riverbeast Training: Ironbore
(87242, 37075), -- Sage Paluna, Riverbeast Training: Moth of Wrath
(87242, 37078), -- Sage Paluna, Riverbeast Training: Orc Hunters
(87242, 37079), -- Sage Paluna, Riverbeast Training: The Garn
(87242, 37076), -- Sage Paluna, Riverbeast Training: Thundercall
(87242, 37097), -- Sage Paluna, Talbuk Training: Bulbapore
(87242, 37098), -- Sage Paluna, Talbuk Training: Cruel Ogres
(87242, 37099), -- Sage Paluna, Talbuk Training: Darkwing Roc
(87242, 37096), -- Sage Paluna, Talbuk Training: Gezz'ran
(87242, 37093), -- Sage Paluna, Talbuk Training: Great-Tusk
(87242, 37102), -- Sage Paluna, Talbuk Training: Ironbore
(87242, 37100), -- Sage Paluna, Talbuk Training: Moth of Wrath
(87242, 37103), -- Sage Paluna, Talbuk Training: Orc Hunters
(87242, 37094), -- Sage Paluna, Talbuk Training: Rakkiri
(87242, 37095), -- Sage Paluna, Talbuk Training: Riplash
(87242, 37104), -- Sage Paluna, Talbuk Training: The Garn
(87242, 37101), -- Sage Paluna, Talbuk Training: Thundercall
(87242, 36917), -- Sage Paluna, Taming a Talbuk
(87242, 37124), -- Sage Paluna, Teeth of a Predator
(87242, 37123), -- Sage Paluna, The Black Claw
(87242, 37105), -- Sage Paluna, Wolf Training: Cruel Ogres
(87242, 37106), -- Sage Paluna, Wolf Training: Darkwing Roc
(87242, 37109), -- Sage Paluna, Wolf Training: Ironbore
(87242, 37107), -- Sage Paluna, Wolf Training: Moth of Wrath
(87242, 37110), -- Sage Paluna, Wolf Training: Orc Hunters
(87242, 37111), -- Sage Paluna, Wolf Training: The Garn
(87242, 37108), -- Sage Paluna, Wolf Training: Thundercall
(87242, 36950), -- Sage Paluna, Wrangling a Wolf
(87247, 37082), -- Gharg, Call of the Gladiator
(87305, 37046), -- Akanja, The Headhunter's Harvest
(87971, 37204), -- Firaga, Rekindling an Old Flame
(87991, 37228), -- Cro Threadstrong, A Fruitful Proposition
(87991, 37152), -- Cro Threadstrong, Cro's Revenge
(87992, 37229), -- Olaf, Like A Dwarf In A Mine
(87992, 37153), -- Olaf, Time-Lost Vikings
(87994, 37230), -- Moroes, Bloody Expensive
(87994, 37157), -- Moroes, Feeling A Bit Morose
(87995, 37155), -- Fleet Master Seahorn, The Brass Compass
(87995, 37231), -- Fleet Master Seahorn, The Search Continues
(87996, 37232), -- Lilian Voss, Soulcarver Voss
(87996, 37156), -- Lilian Voss, The Soulcutter
(87997, 37154), -- Leonid Barthalomew the Revered, The Cure For Death
(87997, 37233), -- Leonid Barthalomew the Revered, Vessel of Virtue
(87998, 37158), -- Sunwalker Dezco, Gloriously Incandescent
(87998, 37234), -- Sunwalker Dezco, The Dark Within
(87999, 37235), -- Skylord Omnuron, A Plea to the Sky
(87999, 37159), -- Skylord Omnuron, Aviana's Request
(88000, 37161), -- Finkle Einhorn, Family Traditions
(88000, 37236), -- Finkle Einhorn, Like Father, Like Son
(88001, 37237), -- Maximillian of Northshire, A Hero's Quest is Never Complete
(88001, 37162), -- Maximillian of Northshire, Damsels and Dragons
(88002, 37238), -- Highlord Darion Mograine, Secrets of Soulbinding
(88002, 37163), -- Highlord Darion Mograine, Shadowy Secrets
(88003, 37239), -- Cowled Ranger, Fate of the Fallen
(88003, 37164), -- Cowled Ranger, The Huntresses
(88004, 37165), -- Zen'kiki, Cenarion Concerns
(88004, 37240), -- Zen'kiki, The Leaf-Reader
(88005, 37241), -- Lorewalker Cho, Lessons of the Past
(88005, 37166), -- Lorewalker Cho, Titanic Evolution
(88006, 37167), -- Lonika Stillblade, And No Maces!
(88006, 37242), -- Lonika Stillblade, Learning Is Painful
(88007, 37243), -- Gamon, An Axe to Grind
(88007, 37160), -- Gamon, Cleaving Time
(88009, 37179), -- Millhouse Manastorm, For The Children!
(88013, 37142), -- Lunk, Ogre Ancestry
(88017, 37145), -- Budd, Budd's Gambit
(88022, 37146), -- Johnny Awesome, Go Fetch
(88023, 37147), -- Taoshi, Sky Dancers
(88024, 37244), -- Oralius, Flamefly Trap
(88024, 37148), -- Oralius, Oralius' Adventure
(88025, 37150), -- Mylune, For the Birds
(88025, 37227), -- Mylune, Put a Bird on It
(88026, 37151), -- John J. Keeshan, Cold Steel
(88026, 37209), -- John J. Keeshan, Cold Steel Part II
(88027, 37149), -- Impsy, The Void-Gate
(88027, 37245), -- Impsy, Whispers in the Darkness
(88112, 34409), -- Morthis Whisperwing, Garrison Campaign: Crows In The Field
(88145, 37270), -- Alchemy Follower - Alliance, Alchemy Experiment
(88147, 37563), -- Makar Stonebinder, The Frostwolves Stand Ready
(88223, 37289), -- Sergeant Crowler, Shadowmoon Invasion!
(88228, 37291), -- Sergeant Grimjaw, Thunderlord Invasion!
(88395, 35786), -- Blood Guard Reejah, Bronze Victory
(88395, 35788), -- Blood Guard Reejah, Gold Victory
(88395, 35787), -- Blood Guard Reejah, Silver Victory
(88458, 37305), -- Corporal Oslo, Bronze Victory
(88458, 37307), -- Corporal Oslo, Gold Victory
(88458, 37306), -- Corporal Oslo, Silver Victory
(88545, 37320), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: A Fine Choker
(88545, 37321), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: A Yellow Brighter Than Gold
(88545, 37323), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: Blue the Shade of Sky and Sea
(88545, 37319), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: Wedding Bands
(88545, 37324), -- Jewelcrafting Follower - Alliance, Out of Stock: Blackrock Ore
(88545, 37325), -- Jewelcrafting Follower - Alliance, Out of Stock: True Iron Ore
(88546, 37320), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: A Fine Choker
(88546, 37321), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: A Yellow Brighter Than Gold
(88546, 37323), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: Blue the Shade of Sky and Sea
(88546, 37319), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: Wedding Bands
(88546, 37324), -- Jewelcrafting Follower - Horde, Out of Stock: Blackrock Ore
(88546, 37325), -- Jewelcrafting Follower - Horde, Out of Stock: True Iron Ore
(88705, 32309), -- Kranosh, A Tale of Six Masters
(88705, 32317), -- Kranosh, Seeking the Soulstones
(88892, 35985), -- Nixxie, Garrison Campaign: The Broken Precipice
(88892, 36117), -- Nixxie, Garrison Campaign: The Broken Precipice
(89753, 37757), -- High Overlord Saurfang, Arcane Sanctum: Ko'ragh
(89753, 37780), -- High Overlord Saurfang, Auchindoun
(89753, 37765), -- High Overlord Saurfang, Blackhand's Crucible: Blackhand
(89753, 37781), -- High Overlord Saurfang, Bloodmaul Slag Mines
(89753, 39231), -- High Overlord Saurfang, Destructor's Rise
(89753, 37782), -- High Overlord Saurfang, Grimrail Depot
(89753, 37758), -- High Overlord Saurfang, Imperator's Rise: Imperator Mar'gok
(89753, 37764), -- High Overlord Saurfang, Iron Assembly: Admiral Gar'an
(89753, 37783), -- High Overlord Saurfang, Iron Docks
(89753, 39225), -- High Overlord Saurfang, Maw of Souls
(89753, 39221), -- High Overlord Saurfang, Pits of Mannoroth
(89753, 37784), -- High Overlord Saurfang, Shadowmoon Burial Grounds
(89753, 37785), -- High Overlord Saurfang, Skyreach
(89753, 37762), -- High Overlord Saurfang, Slagworks: Heart of the Mountain
(89753, 39228), -- High Overlord Saurfang, Temple of Tyranny
(89753, 37763), -- High Overlord Saurfang, The Black Forge: Kromog
(89753, 39232), -- High Overlord Saurfang, The Black Gate
(89753, 37786), -- High Overlord Saurfang, The Everbloom
(89753, 37787), -- High Overlord Saurfang, Upper Blackrock Spire
(89753, 37756), -- High Overlord Saurfang, Walled City: Brackenspore
(89763, 37767), -- Muradin Bronzebeard, Arcane Sanctum: Ko'ragh
(89763, 37796), -- Muradin Bronzebeard, Auchindoun
(89763, 37772), -- Muradin Bronzebeard, Blackhand's Crucible: Blackhand
(89763, 37795), -- Muradin Bronzebeard, Bloodmaul Slag Mines
(89763, 39259), -- Muradin Bronzebeard, Destructor's Rise
(89763, 37794), -- Muradin Bronzebeard, Grimrail Depot
(89763, 37768), -- Muradin Bronzebeard, Imperator's Rise: Imperator Mar'gok
(89763, 37771), -- Muradin Bronzebeard, Iron Assembly: Admiral Gar'an
(89763, 37793), -- Muradin Bronzebeard, Iron Docks
(89763, 39253), -- Muradin Bronzebeard, Maw of Souls
(89763, 39250), -- Muradin Bronzebeard, Pits of Mannoroth
(89763, 37792), -- Muradin Bronzebeard, Shadowmoon Burial Grounds
(89763, 37791), -- Muradin Bronzebeard, Skyreach
(89763, 37769), -- Muradin Bronzebeard, Slagworks: Heart of the Mountain
(89763, 39256), -- Muradin Bronzebeard, Temple of Tyranny
(89763, 37770), -- Muradin Bronzebeard, The Black Forge: Kromog
(89763, 39260), -- Muradin Bronzebeard, The Black Gate
(89763, 37790), -- Muradin Bronzebeard, The Everbloom
(89763, 37789), -- Muradin Bronzebeard, Upper Blackrock Spire
(89763, 37766), -- Muradin Bronzebeard, Walled City: Brackenspore
(89793, 37848), -- Harrison Jones, Treasure Contract: Amulet of Rukhmar
(89793, 37881), -- Harrison Jones, Treasure Contract: Explosive Discoveries
(89793, 37788), -- Harrison Jones, Treasure Contract: Gutrek's Cleaver
(89793, 37973), -- Harrison Jones, Treasure Contract: The Artificer
(89793, 37941), -- Harrison Jones, Treasure Contract: The Infected Orc
(89793, 37914), -- Harrison Jones, Treasure Contract: The Thunderlord Sage
(89805, 37773), -- Renzik "The Shiv", Death to Amethon!
(89805, 37774), -- Renzik "The Shiv", Death to Gor'thul!
(89805, 37778), -- Renzik "The Shiv", Death to Hivelord Ik'rix!
(89805, 37775), -- Renzik "The Shiv", Death to Nullifier Darkoor!
(89805, 37948), -- Renzik "The Shiv", Death to Nullifier Darkoor!
(89805, 37777), -- Renzik "The Shiv", Death to Tremor!
(89805, 37776), -- Renzik "The Shiv", Death to Undertow!
(89806, 37813), -- Shadow Hunter Ty'jin, Death to Amethon!
(89806, 37814), -- Shadow Hunter Ty'jin, Death to Gor'thul!
(89806, 37818), -- Shadow Hunter Ty'jin, Death to Hivelord Ik'rix!
(89806, 37815), -- Shadow Hunter Ty'jin, Death to Nullifier Darkoor!
(89806, 37949), -- Shadow Hunter Ty'jin, Death to Nullifier Darkoor!
(89806, 37817), -- Shadow Hunter Ty'jin, Death to Tremor!
(89806, 37816), -- Shadow Hunter Ty'jin, Death to Undertow!
(90675, 38299), -- Erris the Collector, Critters of Draenor
(90894, 38243), -- Alexi Hackercam, A Bit of Ore
(91014, 38299), -- Erris the Collector, Critters of Draenor
(91015, 38299), -- Erris the Collector, Critters of Draenor
(91016, 38299), -- Erris the Collector, Critters of Draenor
(91017, 38299), -- Erris the Collector, Critters of Draenor
(91020, 38290), -- Enchantress Ismae, Some Dust
(91024, 38287), -- Jake the Fox, Raw Beast Hides
(91025, 38293), -- Dorothy "Two", Sumptuous Fur
(91026, 38300), -- Kura Thunderhoof, Critters of Draenor
(91070, 37062), -- Fayla Fairfeather, Tricks of the Trade
(91071, 37088), -- Trader Joseph, Tricks of the Trade
(91072, 37961), -- Drix Bassbolter, Bringing the Bass
(91072, 38306), -- Drix Bassbolter, Mystery Notebook
(91195, 37757), -- High Overlord Saurfang, Arcane Sanctum: Ko'ragh
(91195, 37780), -- High Overlord Saurfang, Auchindoun
(91195, 37765), -- High Overlord Saurfang, Blackhand's Crucible: Blackhand
(91195, 37781), -- High Overlord Saurfang, Bloodmaul Slag Mines
(91195, 39231), -- High Overlord Saurfang, Destructor's Rise
(91195, 37782), -- High Overlord Saurfang, Grimrail Depot
(91195, 37758), -- High Overlord Saurfang, Imperator's Rise: Imperator Mar'gok
(91195, 37764), -- High Overlord Saurfang, Iron Assembly: Admiral Gar'an
(91195, 37783), -- High Overlord Saurfang, Iron Docks
(91195, 39225), -- High Overlord Saurfang, Maw of Souls
(91195, 39221), -- High Overlord Saurfang, Pits of Mannoroth
(91195, 37784), -- High Overlord Saurfang, Shadowmoon Burial Grounds
(91195, 37785), -- High Overlord Saurfang, Skyreach
(91195, 37762), -- High Overlord Saurfang, Slagworks: Heart of the Mountain
(91195, 39228), -- High Overlord Saurfang, Temple of Tyranny
(91195, 37763), -- High Overlord Saurfang, The Black Forge: Kromog
(91195, 39232), -- High Overlord Saurfang, The Black Gate
(91195, 37786), -- High Overlord Saurfang, The Everbloom
(91195, 37787), -- High Overlord Saurfang, Upper Blackrock Spire
(91195, 37756), -- High Overlord Saurfang, Walled City: Brackenspore
(91196, 37767), -- Muradin Bronzebeard, Arcane Sanctum: Ko'ragh
(91196, 37796), -- Muradin Bronzebeard, Auchindoun
(91196, 37772), -- Muradin Bronzebeard, Blackhand's Crucible: Blackhand
(91196, 37795), -- Muradin Bronzebeard, Bloodmaul Slag Mines
(91196, 39259), -- Muradin Bronzebeard, Destructor's Rise
(91196, 37794), -- Muradin Bronzebeard, Grimrail Depot
(91196, 37768), -- Muradin Bronzebeard, Imperator's Rise: Imperator Mar'gok
(91196, 37771), -- Muradin Bronzebeard, Iron Assembly: Admiral Gar'an
(91196, 37793), -- Muradin Bronzebeard, Iron Docks
(91196, 39253), -- Muradin Bronzebeard, Maw of Souls
(91196, 39250), -- Muradin Bronzebeard, Pits of Mannoroth
(91196, 37792), -- Muradin Bronzebeard, Shadowmoon Burial Grounds
(91196, 37791), -- Muradin Bronzebeard, Skyreach
(91196, 37769), -- Muradin Bronzebeard, Slagworks: Heart of the Mountain
(91196, 39256), -- Muradin Bronzebeard, Temple of Tyranny
(91196, 37770), -- Muradin Bronzebeard, The Black Forge: Kromog
(91196, 39260), -- Muradin Bronzebeard, The Black Gate
(91196, 37790), -- Muradin Bronzebeard, The Everbloom
(91196, 37789), -- Muradin Bronzebeard, Upper Blackrock Spire
(91196, 37766), -- Muradin Bronzebeard, Walled City: Brackenspore
(91242, 38256), -- Solog Roark, Hook, Line, and... Sink Him!
(91242, 38572), -- Solog Roark, Hook, Line, and... Sink Him!
(91242, 38258), -- Solog Roark, Nothing Remains
(91242, 38573), -- Solog Roark, Nothing Remains
(91361, 38300), -- Kura Thunderhoof, Critters of Draenor
(91362, 38300), -- Kura Thunderhoof, Critters of Draenor
(91363, 38300), -- Kura Thunderhoof, Critters of Draenor
(91364, 38300), -- Kura Thunderhoof, Critters of Draenor
(91404, 38296), -- Samantha Scarlet, Herbs Galore
(91589, 38356), -- Fix "Smallie" Biggswrench, Bringing the Bass
(91589, 38344), -- Fix "Smallie" Biggswrench, Mystery Notebook
(92213, 39057), -- Archmage Khadgar, Command of the Seas
(92213, 39003), -- Archmage Khadgar, Cooking the Books
(92213, 39004), -- Archmage Khadgar, Darkness Incarnate
(92213, 37840), -- Archmage Khadgar, Draenor's Blessing
(92213, 37839), -- Archmage Khadgar, Light Be With You
(92213, 39697), -- Archmage Khadgar, Master vs. Commander
(92213, 39002), -- Archmage Khadgar, Ogres of the Deep
(92213, 39001), -- Archmage Khadgar, To Farahlon!
(92213, 39000), -- Archmage Khadgar, We Don't Need No Library Card
(92219, 38259), -- King Varian Wrynn, All Hands on Deck
(92219, 38257), -- King Varian Wrynn, We Need a Shipwright
(92223, 37848), -- Surveyor Daltry, Treasure Contract: Amulet of Rukhmar
(92223, 37881), -- Surveyor Daltry, Treasure Contract: Explosive Discoveries
(92223, 37788), -- Surveyor Daltry, Treasure Contract: Gutrek's Cleaver
(92223, 37973), -- Surveyor Daltry, Treasure Contract: The Artificer
(92223, 37941), -- Surveyor Daltry, Treasure Contract: The Infected Orc
(92223, 37914), -- Surveyor Daltry, Treasure Contract: The Thunderlord Sage
(92400, 38574), -- Vol'jin, All Hands on Deck
(92400, 38568), -- Vol'jin, We Need a Shipwright
(94429, 39242), -- Solog Roark, Ship Shape
(94429, 39054), -- Solog Roark, Shipbuilding
(94429, 39241), -- Solog Roark, Shipbuilding
(94429, 39276), -- Solog Roark, Strange Tools
(94429, 37889), -- Solog Roark, The Invasion of Tanaan
(94789, 39401), -- Rolosh Wavechaser, Destroying the Competition
(94789, 39675), -- Rolosh Wavechaser, Equipping Our Fleet
(94789, 39604), -- Rolosh Wavechaser, I Sunk Your Battleship
(94789, 39674), -- Rolosh Wavechaser, If At First You Fail, Try Again!
(94789, 39236), -- Rolosh Wavechaser, Let's Get To Work
(94789, 39243), -- Rolosh Wavechaser, Naval Commander
(94789, 39246), -- Rolosh Wavechaser, Naval Domination
(94789, 39245), -- Rolosh Wavechaser, Upgrading The Fleet
(94801, 39676), -- Kronk Rustspark, A True Naval Commander
(94870, 39020), -- Seer Kazal, A Burning Path Through Time
(94870, 39040), -- Seer Kazal, A Call to Battle
(94870, 39021), -- Seer Kazal, A Frozen Path Through Time
(94870, 39034), -- Seer Kazal, Emissary of War
(94870, 39041), -- Seer Kazal, The Arena Calls
(94870, 39033), -- Seer Kazal, The Time to Strike
(94870, 39042), -- Seer Kazal, The Very Best
(95659, 39502), -- Archmage Khadgar, The Fel Spire
(95659, 39504), -- Archmage Khadgar, The Fel Spire
(95659, 39505), -- Archmage Khadgar, The Fel Spire
(95659, 39499), -- Archmage Khadgar, Well of Souls
(95659, 39500), -- Archmage Khadgar, Well of Souls
(95659, 39501); -- Archmage Khadgar, Well of Souls

INSERT INTO `creature_questender` VALUES
(70859, 34402), -- Thrall, Of Wolves and Warriors
(70860, 33473), -- Durotan, Back to Bladespire Citadel
(70860, 34379), -- Durotan, Den of Wolves
(70860, 33657), -- Durotan, Moving In
(70909, 32783), -- Ga'nar, Ga'nar's Vengeance
(70910, 32792), -- Ga'nar, Leave Nothing Behind!
(70941, 32795), -- Ga'nar, The Eldest
(70941, 32794), -- Ga'nar, Wrath of Gronn
(72230, 33444), -- Draka, Eatercology
(72230, 32979), -- Draka, Garrison Campaign: Farseer's Rock
(72274, 32991), -- Lokra, Into the Boneslag
(72274, 32992), -- Lokra, Moving Target
(72274, 32989), -- Lokra, Securing the South
(72274, 32990), -- Lokra, They Who Held Fast
(72814, 34209), -- Cordana Felsong, Vouchsafe Our Arrival
(72836, 34292), -- Cordana Felsong, Eliminate the Shadow Council
(72836, 34293), -- Cordana Felsong, Eliminate the Shadow Council
(72836, 34277), -- Cordana Felsong, Stop the Flow
(72837, 34228), -- Farseer Urquan, A Clew of Worms
(72837, 34278), -- Farseer Urquan, Desecration of the Dead
(72837, 34216), -- Farseer Urquan, Safe Passage
(72837, 34229), -- Farseer Urquan, The Sleeper Has Awakened
(72874, 34280), -- Archmage Khadgar, All is Revealed
(72874, 34230), -- Archmage Khadgar, Eye Need That
(72874, 34295), -- Archmage Khadgar, To Capture Gul'dan
(72874, 34227), -- Archmage Khadgar, What Must Be Done
(72890, 33119), -- Mulverick, Slavery and Strife
(72940, 33828), -- Frostwolf Champion, The Master Siegesmith
(72976, 33125), -- Outrider Urukag, A Proper Parting
(72976, 33132), -- Outrider Urukag, Gut Guttra
(73097, 32994), -- Frostwolf Champion, Enfilade
(73097, 33785), -- Frostwolf Champion, Karg Unchained
(73097, 33826), -- Frostwolf Champion, Where's My Wolf?!
(73480, 34291), -- Image of Archmage Khadgar, Have a Heart
(73480, 34294), -- Image of Archmage Khadgar, The Fel Crystals
(74000, 32791), -- Ga'nar, Let the Hunt Begin!
(74163, 33493), -- Durotan, Return to the Pack
(74163, 32796), -- Durotan, To the Garrison
(74223, 32804), -- Kal'gor the Honorable, Articles of the Fallen
(74223, 32929), -- Kal'gor the Honorable, They Rely on Numbers
(74253, 32980), -- Farseer Drek'Thar, Eaters of the Elements
(74253, 32983), -- Farseer Drek'Thar, In the Shadow of Giants
(74272, 33816), -- Farseer Drek'Thar, Honor Has Its Rewards
(74272, 33470), -- Farseer Drek'Thar, Pool of Visions
(74272, 33469), -- Farseer Drek'Thar, The Farseer
(74273, 33526), -- Durotan, These Colors Don't Run
(74330, 32985), -- Farseer Drek'Thar, Fury of Frostfire
(74330, 32984), -- Farseer Drek'Thar, The Ascent
(74409, 34673), -- Zeya, The Rise of Aku'mai
(74635, 33412), -- Igrimar the Resolute, Mopping Up
(74635, 33454), -- Igrimar the Resolute, The Cure
(74635, 33450), -- Igrimar the Resolute, The Warlord's Guard
(74651, 33807), -- Draka, Free Our Brothers and Sisters
(74651, 33468), -- Draka, Save Wolf Home
(74977, 33838), -- Initiate Na'Shra, Smeltcraft
(75177, 33344), -- Durotan, Armed and Dangerous
(75177, 33546), -- Durotan, Deeds Left Undone
(75177, 33622), -- Durotan, To the Slaughter
(75186, 33408), -- Thrall, Great Balls of Fire!
(75186, 33410), -- Thrall, The Butcher of Bladespire
(75188, 33527), -- Durotan, Last Steps
(75606, 26897), -- Sentinel Aluwyn, Blackfathom Deeps
(75606, 34672), -- Sentinel Aluwyn, The Rise of Aku'mai
(76111, 35496), -- Enohar Thunderbrew, Enohar's Revenge
(76240, 33784), -- Durotan, Gormaul Tower
(76411, 33868), -- Farseer Drek'Thar, The Home of the Frostwolves
(76484, 34124), -- Durotan, The Battle of Thunder Pass
(76487, 34730), -- Lokra, Blood Oath of Lokra
(76487, 34123), -- Lokra, To Thunder Pass
(76557, 34380), -- Durotan, Rally the Frostwolves
(76609, 35764), -- Okrilla, Okrilla's Revenge
(76609, 35761), -- Okrilla, Ransacking Nethergarde
(76662, 33898), -- Gol'kosh the Axe, Slaying Slavers
(76720, 33010), -- Thrall, The Iron Wolf
(76730, 37563), -- Makar Stonebinder, The Frostwolves Stand Ready
(76862, 33915), -- Gog'rak, Young Hearts
(76889, 33955), -- Shivertail, Missing Pack
(76889, 33929), -- Shivertail, Shivertail's Den
(77160, 34029), -- Hansel Heavyhands, The Prototype
(77160, 34028), -- Hansel Heavyhands, These Look Familiar...
(77167, 34048), -- Dark Iron Golem, "Mole Machine, Go Home"
(77167, 34032), -- Dark Iron Golem, Privileged Information
(77167, 34031), -- Dark Iron Golem, Something to Remember Me By
(77209, 36592), -- Baros Alexston, Bigger is Better
(77209, 33111), -- Baros Alexston, Bounty: Twisted Ancient
(77209, 36100), -- Baros Alexston, Building for Professions
(77209, 34586), -- Baros Alexston, Establish Your Garrison
(77209, 33814), -- Baros Alexston, Fast Expansion
(77209, 35176), -- Baros Alexston, Keeping it Together
(77209, 36615), -- Baros Alexston, My Very Own Castle
(77209, 35166), -- Baros Alexston, Ship Salvage
(77209, 35905), -- Baros Alexston, Supply Drop
(77210, 34067), -- Scout Ruk'Gan, A Collection of Coils
(77210, 34264), -- Scout Ruk'Gan, A Collection of Coils
(77210, 34070), -- Scout Ruk'Gan, At the End of Your Rope
(77210, 34073), -- Scout Ruk'Gan, Burn Them Down
(77210, 34069), -- Scout Ruk'Gan, Getting the Points
(77210, 34093), -- Scout Ruk'Gan, Getting the Points
(77210, 34066), -- Scout Ruk'Gan, Savage Vengeance
(77210, 34072), -- Scout Ruk'Gan, Tar Get of Opportunity
(77210, 34102), -- Scout Ruk'Gan, The Mark of Defiance
(77210, 34075), -- Scout Ruk'Gan, Vul'gath's End
(77217, 34026), -- Jr. Surveyor Dorn, Garrison Campaign: Seismic Matters
(77217, 34027), -- Jr. Surveyor Dorn, Groundbreaking Data
(77367, 36848), -- Archmage Kem, Ogre Waygates
(77367, 38354), -- Archmage Kem, Portable Portals
(77377, 38175), -- Kristen Stoneforge, Scrap Meltdown
(77377, 37092), -- Kristen Stoneforge, Scraps of Iron
(77378, 37086), -- Hennick Helmsley, Salvaging the Situation
(77730, 34192), -- Timothy Leens, Things Are Not Goren Our Way
(77733, 36517), -- Ron Ashton, Abyssal Gulper Eel
(77733, 36202), -- Ron Ashton, Anglin' In Our Garrison
(77733, 36515), -- Ron Ashton, Blackwater Whiptail
(77733, 36514), -- Ron Ashton, Blind Lake Sturgeon
(77733, 36513), -- Ron Ashton, Fat Sleeper
(77733, 36510), -- Ron Ashton, Fire Ammonite
(77733, 36511), -- Ron Ashton, Jawless Skulker
(77789, 34774), -- Blingtron 5000, Blingtron 5000
(77928, 34034), -- Gazlowe, Garrison Campaign: Grinding Gears
(77928, 34035), -- Gazlowe, I Know The Drill!
(77998, 34321), -- Molthron, Ashes Of The Past
(77998, 34325), -- Molthron, Flames Of The Earth
(78056, 34284), -- Owynn Graddock, Garrison Campaign: The Search for Owynn Graddock
(78056, 34285), -- Owynn Graddock, Gearing Up
(78056, 34281), -- Owynn Graddock, Out of the Chains
(78208, 34344), -- Shadow Hunter Rala, Lurkers
(78208, 34731), -- Shadow Hunter Rala, Oath of Shadow Hunter Rala
(78208, 34345), -- Shadow Hunter Rala, Poulticide
(78208, 34348), -- Shadow Hunter Rala, The Real Prey
(78208, 34736), -- Shadow Hunter Rala, We Be Needin' Supplies
(78209, 34346), -- Shadow Hunter Mala, Frosted Fury
(78222, 33484), -- Guse, The Slavemaster's Demise
(78239, 34286), -- Owynn Graddock, Seeking the Truth
(78272, 33815), -- Durotan, A Song of Frost and Fire
(78323, 34042), -- Goblin Engineer, A Fellow Gearhead
(78323, 34041), -- Goblin Engineer, Four Finger Discount
(78323, 34040), -- Goblin Engineer, Maker's Mark
(78323, 34039), -- Goblin Engineer, Wanted: Overlord Blackhammer
(78428, 34287), -- Orlana Strongbrow, Cleansing the Souls
(78428, 34469), -- Orlana Strongbrow, Cleansing the Souls
(78428, 34288), -- Orlana Strongbrow, The Totems That Bind
(78428, 34318), -- Orlana Strongbrow, The Totems That Bind
(78466, 34592), -- Gazlowe, A Gronnling Problem
(78466, 34375), -- Gazlowe, Back to Work
(78466, 36567), -- Gazlowe, Bigger is Better
(78466, 34461), -- Gazlowe, Build Your Barracks
(78466, 37669), -- Gazlowe, Building for Professions
(78466, 34378), -- Gazlowe, Establish Your Garrison
(78466, 34364), -- Gazlowe, For the Horde!
(78466, 36614), -- Gazlowe, My Very Own Fortress
(78466, 34078), -- Gazlowe, Payment Due for Services Rendered
(78466, 34765), -- Gazlowe, The Den of Skog
(78466, 34960), -- Gazlowe, The Land Provides
(78466, 34824), -- Gazlowe, What We Got
(78466, 34822), -- Gazlowe, What We Need
(78487, 37993), -- Rokhan, Amulet of Rukhmar: The Apexis Device
(78487, 37757), -- Rokhan, Arcane Sanctum: Ko'ragh
(78487, 37780), -- Rokhan, Auchindoun
(78487, 37765), -- Rokhan, Blackhand's Crucible: Blackhand
(78487, 37781), -- Rokhan, Bloodmaul Slag Mines
(78487, 37994), -- Rokhan, Dark Grimoire: Breaching the Barrier
(78487, 37813), -- Rokhan, Death to Amethon!
(78487, 37814), -- Rokhan, Death to Gor'thul!
(78487, 37818), -- Rokhan, Death to Hivelord Ik'rix!
(78487, 37815), -- Rokhan, Death to Nullifier Darkoor!
(78487, 37949), -- Rokhan, Death to Nullifier Darkoor!
(78487, 37817), -- Rokhan, Death to Tremor!
(78487, 37816), -- Rokhan, Death to Undertow!
(78487, 39231), -- Rokhan, Destructor's Rise
(78487, 37997), -- Rokhan, Dream of Argus: The Crystal Reborn
(78487, 37782), -- Rokhan, Grimrail Depot
(78487, 37995), -- Rokhan, Gronnsbane: The Blessing of Beasts
(78487, 37992), -- Rokhan, Gutrek's Cleaver: The Spirit Forge
(78487, 37758), -- Rokhan, Imperator's Rise: Imperator Mar'gok
(78487, 35846), -- Rokhan, Intercepting the Orders
(78487, 37764), -- Rokhan, Iron Assembly: Admiral Gar'an
(78487, 37783), -- Rokhan, Iron Docks
(78487, 39225), -- Rokhan, Maw of Souls
(78487, 36602), -- Rokhan, News from Nagrand
(78487, 36607), -- Rokhan, News from Nagrand
(78487, 35537), -- Rokhan, News from Spires of Arak
(78487, 36494), -- Rokhan, News from Talador
(78487, 36290), -- Rokhan, Out of the Shadows
(78487, 39221), -- Rokhan, Pits of Mannoroth
(78487, 35845), -- Rokhan, Plans of War
(78487, 35842), -- Rokhan, Putting Down the Packleader
(78487, 37784), -- Rokhan, Shadowmoon Burial Grounds
(78487, 37785), -- Rokhan, Skyreach
(78487, 37762), -- Rokhan, Slagworks: Heart of the Mountain
(78487, 39228), -- Rokhan, Temple of Tyranny
(78487, 37763), -- Rokhan, The Black Forge: Kromog
(78487, 39232), -- Rokhan, The Black Gate
(78487, 37786), -- Rokhan, The Everbloom
(78487, 34823), -- Rokhan, The Ogron Live?
(78487, 37996), -- Rokhan, The Silent Skull: Taking from the Taker
(78487, 37787), -- Rokhan, Upper Blackrock Spire
(78487, 37756), -- Rokhan, Walled City: Brackenspore
(78487, 33918), -- Rokhan, Wanted: Grondo's Bounty
(78487, 35736), -- Rokhan, Writing in the Snow
(78553, 35005), -- Thrall, Prepare for Battle
(78553, 35241), -- Thrall, Vengeance for the Fallen
(78554, 35019), -- Vindicator Maraad, Prepare for Battle
(78554, 35242), -- Vindicator Maraad, Vengeance for the Fallen
(78558, 34392), -- Archmage Khadgar, Onslaught's End
(78558, 34398), -- Archmage Khadgar, The Dark Portal
(78558, 36881), -- Archmage Khadgar, The Dark Portal
(78558, 34393), -- Archmage Khadgar, The Portal's Power
(78559, 34422), -- Archmage Khadgar, Blaze of Glory
(78559, 34421), -- Archmage Khadgar, Bled Dry
(78559, 35240), -- Archmage Khadgar, Bled Dry
(78559, 34420), -- Archmage Khadgar, The Cost of War
(78560, 34423), -- Archmage Khadgar, Altar Altercation
(78560, 34425), -- Archmage Khadgar, The Kargathar Proving Grounds
(78563, 34446), -- Archmage Khadgar, The Home Stretch
(78563, 35884), -- Archmage Khadgar, The Home Stretch
(78564, 36171), -- Sergeant Crowler, Botani Invasion!
(78564, 36376), -- Sergeant Crowler, Goren Invasion!
(78564, 36655), -- Sergeant Crowler, Iron Horde Invasion!
(78564, 36650), -- Sergeant Crowler, Ogre Invasion!
(78564, 36830), -- Sergeant Crowler, Shadow Council Invasion!
(78564, 36412), -- Sergeant Crowler, Shadowmoon Invasion!
(78568, 34958), -- Thaelin Darkanvil, The Shadow of the Worldbreaker
(78569, 34987), -- Hansel Heavyhands, The Gunpowder Plot
(78659, 34309), -- Shadow Hunter Bwu'ja, Garrison Campaign: The Search for Shadow Hunter Bwu'ja
(78659, 34315), -- Shadow Hunter Bwu'ja, Gearing Up
(78659, 34314), -- Shadow Hunter Bwu'ja, Out of the Chains
(78785, 34316), -- Shadow Hunter Bwu'ja, Seeking the Truth
(78989, 36238), -- Axe-Shaper Kugra, Mending A Broken Heart
(78989, 36205), -- Axe-Shaper Kugra, The Fractured Hammer
(78994, 34434), -- Yrel, Yrel
(78994, 34740), -- Yrel, Yrel
(78996, 34427), -- Farseer Drek'Thar, A Potential Ally
(78996, 34439), -- Farseer Drek'Thar, The Battle of the Forge
(78996, 34437), -- Farseer Drek'Thar, The Prodigal Frostwolf
(79047, 34732), -- Mulverick, Mulverick's Offer of Service
(79047, 33483), -- Mulverick, Mulverick's Plight
(79229, 35341), -- Gronnstalker Rokash, Defection of Gronnstalker Rokash
(79229, 32981), -- Gronnstalker Rokash, Only the Winner
(79457, 34587), -- Vindicator Maraad, Build Your Barracks
(79457, 35174), -- Vindicator Maraad, Pale Moonlight
(79492, 34733), -- Dagg, Services of Dagg
(79537, 34478), -- Exarch Maladaar, A Potential Ally
(79537, 34431), -- Exarch Maladaar, Masters of Shadow
(79675, 34737), -- Lady Liadrin, Masters of Shadow
(79740, 36248), -- Warmaster Zog, A Stolen Heart
(79740, 34775), -- Warmaster Zog, Mission Probable
(79740, 33427), -- Warmaster Zog, Ours is the Fury
(79740, 36342), -- Warmaster Zog, Primal Fury
(79740, 37434), -- Warmaster Zog, Proving Grounds
(79740, 37192), -- Warmaster Zog, Sanketsu, The Burning Blade
(79740, 34341), -- Warmaster Zog, The Beating Heart
(79740, 34861), -- Warmaster Zog, We Need An Army
(79740, 36242), -- Warmaster Zog, Where There Is Smoke...
(79740, 34462), -- Warmaster Zog, Winds of Change
(79774, 36653), -- Sergeant Grimjaw, Botani Invasion!
(79774, 35142), -- Sergeant Grimjaw, Goren Invasion!
(79774, 35935), -- Sergeant Grimjaw, Iron Horde Invasion!
(79774, 36623), -- Sergeant Grimjaw, Ogre Invasion!
(79774, 36831), -- Sergeant Grimjaw, Shadow Council Invasion!
(79774, 36414), -- Sergeant Grimjaw, Shadowmoon Invasion!
(79815, 38188), -- Grun'lek, Scrap Meltdown
(79815, 37043), -- Grun'lek, Scraps of Iron
(79826, 37590), -- Pozzlow, Your Second Engineering Work Order
(79836, 36848), -- Gez'la, Ogre Waygates
(79836, 38351), -- Gez'la, Portable Portals
(79857, 37045), -- Lumba the Crusher, Salvaging the Situation
(79858, 40329), -- Serr'ah, Battle Pet Tamers: Warlords
(79858, 37645), -- Serr'ah, Mastering the Menagerie
(79858, 36469), -- Serr'ah, Pets Versus Pests
(79858, 36662), -- Serr'ah, Scrappin'
(79858, 38242), -- Serr'ah, Unearthed Magic
(79862, 37060), -- Yorn Longhoof, Lost in Transition
(79892, 35075), -- Mak'jin, Abyssal Gulper Eel
(79892, 36132), -- Mak'jin, Anglin' In Our Garrison
(79892, 35074), -- Mak'jin, Blackwater Whiptail
(79892, 35073), -- Mak'jin, Blind Lake Sturgeon
(79892, 35072), -- Mak'jin, Fat Sleeper
(79892, 35066), -- Mak'jin, Fire Ammonite
(79892, 35071), -- Mak'jin, Jawless Skulker
(79896, 36141), -- Mokugg Lagerpounder, Icespine Stingers
(79896, 34758), -- Mokugg Lagerpounder, Looking For Help
(79896, 36131), -- Mokugg Lagerpounder, Proving Your Worth
(79917, 34442), -- Ga'nar, Ga'nar of the Frostwolf
(79917, 34925), -- Ga'nar, Polishing the Iron Throne
(79953, 34692), -- Lieutenant Thorn, Delegating on Draenor
(79953, 37433), -- Lieutenant Thorn, Proving Grounds
(79971, 36612), -- Rak'jin, Luring Nat
(79971, 36609), -- Rak'jin, The Great Angler Returns
(80193, 34634), -- Kirin Tor Magus, Creating the Ink
(80193, 34635), -- Kirin Tor Magus, Forming the Scroll
(80193, 34636), -- Kirin Tor Magus, Gathering the Spark
(80260, 34609), -- Magister Serena, Creating the Ink
(80260, 34612), -- Magister Serena, Forming the Scroll
(80260, 34619), -- Magister Serena, Gathering the Spark
(80341, 34858), -- Horde Grunt, Prized Repossessions
(80341, 34855), -- Horde Grunt, Punching Through
(80341, 34860), -- Horde Grunt, Supply Recovery
(80389, 34889), -- Kirin Tor Magus, Orbs of Power
(80389, 34890), -- Kirin Tor Magus, The Final Step
(80389, 34888), -- Kirin Tor Magus, Vicious Viziers
(80389, 34887), -- Kirin Tor Magus, While We're in the Neighborhood
(80456, 33816), -- Farseer Drek'Thar, Honor Has Its Rewards
(80521, 34445), -- Thaelin Darkanvil, A Taste of Iron
(80521, 35747), -- Thaelin Darkanvil, Taking a Trip to the Top of the Tank
(80617, 34911), -- Kirin Tor Magus, Orbs of Power
(80617, 34912), -- Kirin Tor Magus, The Final Step
(80617, 34910), -- Kirin Tor Magus, Vicious Viziers
(80617, 34909), -- Kirin Tor Magus, While We're in the Neighborhood
(80632, 34978), -- Alliance Soldier, Prized Repossessions
(80632, 34979), -- Alliance Soldier, Punching Through
(80632, 34977), -- Alliance Soldier, Supply Recovery
(81086, 35060), -- Uruk Foecleaver, Terms of Surrender
(81086, 35096), -- Uruk Foecleaver, Terms of Surrender
(81152, 36679), -- Scout Valdez, Assault on Darktide Roost
(81152, 36681), -- Scout Valdez, Assault on Lost Veil Anzu
(81152, 36675), -- Scout Valdez, Assault on Magnarok
(81152, 36678), -- Scout Valdez, Assault on Mok'gol Watchpost
(81152, 36682), -- Scout Valdez, Assault on Pillars of Fate
(81152, 36649), -- Scout Valdez, Assault on Shattrath Harbor
(81152, 36683), -- Scout Valdez, Assault on Skettis
(81152, 36680), -- Scout Valdez, Assault on Socrethar's Rise
(81152, 36648), -- Scout Valdez, Assault on Stonefury Cliffs
(81152, 36677), -- Scout Valdez, Assault on the Broken Precipice
(81152, 36676), -- Scout Valdez, Assault on the Everbloom Wilds
(81152, 36685), -- Scout Valdez, Assault on the Heart of Shattrath
(81152, 36674), -- Scout Valdez, Assault on the Iron Siegeworks
(81152, 36686), -- Scout Valdez, Assault on the Pit
(81152, 36684), -- Scout Valdez, Battle in Ashran
(81152, 36687), -- Scout Valdez, Challenge at the Ring of Blood
(81152, 38196), -- Scout Valdez, Missive: Assault on Darktide Roost
(81152, 38198), -- Scout Valdez, Missive: Assault on Lost Veil Anzu
(81152, 38190), -- Scout Valdez, Missive: Assault on Magnarok
(81152, 38195), -- Scout Valdez, Missive: Assault on Mok'gol Watchpost
(81152, 38199), -- Scout Valdez, Missive: Assault on Pillars of Fate
(81152, 38201), -- Scout Valdez, Missive: Assault on Shattrath Harbor
(81152, 38200), -- Scout Valdez, Missive: Assault on Skettis
(81152, 38197), -- Scout Valdez, Missive: Assault on Socrethar's Rise
(81152, 38189), -- Scout Valdez, Missive: Assault on Stonefury Cliffs
(81152, 38193), -- Scout Valdez, Missive: Assault on the Broken Precipice
(81152, 38192), -- Scout Valdez, Missive: Assault on the Everbloom Wilds
(81152, 38191), -- Scout Valdez, Missive: Assault on the Iron Siegeworks
(81166, 35058), -- Refugee Lo'nash, The Mysterious Flask
(81209, 35103), -- Kadar, The Alchemist
(81210, 35106), -- Ang'kra, Avenge and Reclaim
(81210, 35104), -- Ang'kra, The Apprentice
(81492, 37852), -- Bodrick Grey, Amulet of Rukhmar: The Apexis Device
(81492, 37767), -- Bodrick Grey, Arcane Sanctum: Ko'ragh
(81492, 37796), -- Bodrick Grey, Auchindoun
(81492, 37772), -- Bodrick Grey, Blackhand's Crucible: Blackhand
(81492, 37795), -- Bodrick Grey, Bloodmaul Slag Mines
(81492, 37885), -- Bodrick Grey, Dark Grimoire: Breaching the Barrier
(81492, 37773), -- Bodrick Grey, Death to Amethon!
(81492, 37774), -- Bodrick Grey, Death to Gor'thul!
(81492, 37778), -- Bodrick Grey, Death to Hivelord Ik'rix!
(81492, 37775), -- Bodrick Grey, Death to Nullifier Darkoor!
(81492, 37948), -- Bodrick Grey, Death to Nullifier Darkoor!
(81492, 37777), -- Bodrick Grey, Death to Tremor!
(81492, 37776), -- Bodrick Grey, Death to Undertow!
(81492, 39259), -- Bodrick Grey, Destructor's Rise
(81492, 37979), -- Bodrick Grey, Dream of Argus: The Crystal Reborn
(81492, 37794), -- Bodrick Grey, Grimrail Depot
(81492, 37919), -- Bodrick Grey, Gronnsbane: The Blessing of Beasts
(81492, 37811), -- Bodrick Grey, Gutrek's Cleaver: The Spirit Forge
(81492, 37768), -- Bodrick Grey, Imperator's Rise: Imperator Mar'gok
(81492, 35840), -- Bodrick Grey, Intercepting the Orders
(81492, 37771), -- Bodrick Grey, Iron Assembly: Admiral Gar'an
(81492, 37793), -- Bodrick Grey, Iron Docks
(81492, 39253), -- Bodrick Grey, Maw of Souls
(81492, 36601), -- Bodrick Grey, News from Nagrand
(81492, 36606), -- Bodrick Grey, News from Nagrand
(81492, 35554), -- Bodrick Grey, News from Spires of Arak
(81492, 36495), -- Bodrick Grey, News from Talador
(81492, 36289), -- Bodrick Grey, Out of the Shadows
(81492, 39250), -- Bodrick Grey, Pits of Mannoroth
(81492, 35839), -- Bodrick Grey, Plans of War
(81492, 35841), -- Bodrick Grey, Putting Down the Packleader
(81492, 37792), -- Bodrick Grey, Shadowmoon Burial Grounds
(81492, 37791), -- Bodrick Grey, Skyreach
(81492, 37769), -- Bodrick Grey, Slagworks: Heart of the Mountain
(81492, 39256), -- Bodrick Grey, Temple of Tyranny
(81492, 37770), -- Bodrick Grey, The Black Forge: Kromog
(81492, 39260), -- Bodrick Grey, The Black Gate
(81492, 37790), -- Bodrick Grey, The Everbloom
(81492, 37945), -- Bodrick Grey, The Silent Skull: Taking from the Taker
(81492, 37789), -- Bodrick Grey, Upper Blackrock Spire
(81492, 37766), -- Bodrick Grey, Walled City: Brackenspore
(81492, 35737), -- Bodrick Grey, Writing in the Snow
(81678, 33467), -- Snowrunner Rolga, The Fall of the Warlord
(81688, 35154), -- Gorsol, Things Are Not Goren Our Way
(81912, 34778), -- Foreman Zipfizzle, Migrant Workers
(81981, 34193), -- Tarnon, Clearing the Garden
(82123, 35259), -- Inactive Apexis Destroyer, Sol Sisters
(82270, 35460), -- Vindicator Maraad, Attack of the Iron Horde
(82270, 36498), -- Vindicator Maraad, Iron Horde Invasion
(82270, 35463), -- Vindicator Maraad, Subversive Scouts
(82270, 35462), -- Vindicator Maraad, Under Siege
(82302, 33706), -- Birchus, Laying Dionor to Rest
(82302, 36443), -- Birchus, Laying Dionor to Rest
(82302, 33695), -- Birchus, Taking the Death Bloom
(82302, 36442), -- Birchus, Taking the Death Bloom
(82447, 35494), -- Commander Vines, Mementos of the Fallen
(82466, 35342), -- Aenir, The Mysterious Flask
(82851, 35745), -- Thrall, Attack of the Iron Horde
(82851, 36499), -- Thrall, Iron Horde Invasion
(82851, 35748), -- Thrall, Subversive Scouts
(82851, 35746), -- Thrall, Under Siege
(83006, 39107), -- Griftah, An Even Bigga Score
(83006, 37284), -- Griftah, Da Big Score
(83006, 37285), -- Griftah, If You're Sure
(83482, 36255), -- Yu'rina the Mystic, Enchanted Highmaul Bracer
(83491, 36308), -- Eileese Shadowsong, Enchanted Highmaul Bracer
(83858, 35196), -- Khadgar's Servant, Forging Ahead
(83858, 35197), -- Khadgar's Servant, Forging Ahead
(83899, 36028), -- Dark Ranger Velonara, Gardul Venomshiv
(83900, 36029), -- Hulda Shadowblade, Gardul Venomshiv
(84247, 36137), -- Lumber Lord Oktron, Easing into Lumberjacking
(84247, 36385), -- Lumber Lord Oktron, Legacy of the Ancients
(84247, 36142), -- Lumber Lord Oktron, Sharper Blades, Bigger Timber
(84247, 36182), -- Lumber Lord Oktron, Tree-i-cide
(84247, 36138), -- Lumber Lord Oktron, Turning Timber into Profit
(84248, 36189), -- Justin Timberlord, Easing into Lumberjacking
(84248, 36385), -- Justin Timberlord, Legacy of the Ancients
(84248, 36194), -- Justin Timberlord, Sharper Blades, Bigger Timber
(84248, 36195), -- Justin Timberlord, Tree-i-cide
(84248, 36192), -- Justin Timberlord, Turning Timber into Profit
(84268, 36162), -- Lieutenant Thorn, A Stolen Heart
(84268, 36341), -- Lieutenant Thorn, Primal Fury
(84268, 37191), -- Lieutenant Thorn, Sanketsu, The Burning Blade
(84286, 37091), -- Zee, Unconventional Inventions
(84494, 36230), -- Waruk the Frostforger, The Restless Spirit
(84494, 36207), -- Waruk the Frostforger, Waruk the Frostforger
(84511, 36161), -- Lieutenant Thorn, Where There Is Smoke...
(84524, 36274), -- Homer Stonefield, Bigger Trap, Better Rewards
(84524, 36271), -- Homer Stonefield, Breaking into the Trap Game
(84524, 36272), -- Homer Stonefield, Feeding An Army
(84689, 36419), -- Trega, Dyed in the Fur
(84689, 36417), -- Trega, From Their Cold Dead Hands
(84689, 36301), -- Trega, Trega's Tailoring Kit
(84739, 36260), -- Arcanist Delath, Oru'kai's Scepter
(84739, 36256), -- Arcanist Delath, The Arakkoan Enchanter
(84747, 36257), -- Torag Stonefury, Failed Apprentice
(84776, 36236), -- Aerun, The Cryptic Tome of Tailoring
(84857, 37087), -- Kyra Goldhands, Lost in Transition
(84889, 36813), -- Phylarch the Evergreen, Subversive Infestation
(84928, 35751), -- Thrall, Attack on Nethergarde
(84928, 35762), -- Thrall, Death to the Dreadmaul
(84928, 35763), -- Thrall, Gar'mak Bladetwist
(84928, 36292), -- Thrall, Investigating the Invasion
(84928, 35750), -- Thrall, Lunatic Lieutenants
(84928, 35760), -- Thrall, Toothsmash the Annihilator
(84929, 35488), -- Vindicator Maraad, Death to the Dreadmaul
(84929, 35492), -- Vindicator Maraad, For Nethergarde!
(84929, 35500), -- Vindicator Maraad, Gar'mak Bladetwist
(84929, 36307), -- Vindicator Maraad, Investigating the Invasion
(84929, 35486), -- Vindicator Maraad, Lunatic Lieutenants
(84929, 35495), -- Vindicator Maraad, Toothsmash the Annihilator
(84947, 37119), -- Lysa Serion, The Headhunter's Harvest
(84967, 36314), -- "Appraiser" Sazsel Stickyfingers, The Intricate Pendant
(85048, 36346), -- Farmer Lok'lub, Bigger Trap, Better Rewards
(85048, 36345), -- Farmer Lok'lub, Breaking into the Trap Game
(85048, 36344), -- Farmer Lok'lub, Feeding An Army
(85106, 36380), -- Gem Grinder Orolak, Diamonds Are Forever
(85106, 36352), -- Gem Grinder Orolak, Locating the Lapidarist
(85106, 36378), -- Gem Grinder Orolak, No Pressure, No Diamonds
(85213, 35464), -- Bodrick Grey, Ending Executions
(85213, 36379), -- Bodrick Grey, Peeking into the Portal
(85247, 35744), -- Rokhan, Ending Executions
(85247, 36382), -- Rokhan, Peeking into the Portal
(85344, 36404), -- Naron Bloomthistle, Clearing the Garden
(85369, 37044), -- Vee, Unconventional Inventions
(85413, 36448), -- Weldon Barov, Reduction in Force
(85414, 36449), -- Alexi Barov, Reduction in Force
(85418, 36483), -- Lio the Lioness, Battle Pet Roundup
(85418, 40329), -- Lio the Lioness, Battle Pet Tamers: Warlords
(85418, 37644), -- Lio the Lioness, Mastering the Menagerie
(85418, 36423), -- Lio the Lioness, Pets Versus Pests
(85418, 38241), -- Lio the Lioness, Unearthed Magic
(85439, 36435), -- Raleigh Puule, Unintelligible Intelligence
(85440, 36457), -- Nicholaus Page, Bypassing Security
(85440, 36475), -- Nicholaus Page, Stealing the Declaration
(85708, 36870), -- Segumi, Luring Nat
(85708, 36882), -- Segumi, The Great Angler Returns
(85751, 36505), -- Gaoda Hidecleaver, A Warrior's Shroud
(85751, 36516), -- Gaoda Hidecleaver, Cut 'Em Out!
(85777, 36522), -- Ahm, Solidarity in Death
(85882, 36594), -- Blixthraz Blastcharge, "Spare" Parts
(85882, 36627), -- Blixthraz Blastcharge, Big Frostfire Gun
(85882, 36589), -- Blixthraz Blastcharge, Heavy Arms
(85984, 36611), -- Nat Pagle, A True Draenor Angler
(85984, 36802), -- Nat Pagle, Abyssal Gulper Lunker
(85984, 36616), -- Nat Pagle, An Angler on Our Team
(85984, 36803), -- Nat Pagle, Blackwater Whiptail Lunker
(85984, 36804), -- Nat Pagle, Blind Lake Lunker
(85984, 36805), -- Nat Pagle, Fat Sleeper Lunker
(85984, 39283), -- Nat Pagle, Felmouth Frenzy Lunker
(85984, 36800), -- Nat Pagle, Fire Ammonite Lunker
(85984, 36806), -- Nat Pagle, Jawless Skulker Lunker
(85984, 38406), -- Nat Pagle, Sea Scorpion Lunker
(86272, 36702), -- Meatball, Meatball
(86629, 36897), -- Raza'kul, Nemesis: Becoming Death
(86629, 36923), -- Raza'kul, Nemesis: Becoming Death
(86629, 36925), -- Raza'kul, Nemesis: Becoming Death
(86629, 36927), -- Raza'kul, Nemesis: Becoming Death
(86629, 36929), -- Raza'kul, Nemesis: Becoming Death
(86629, 36931), -- Raza'kul, Nemesis: Becoming Death
(86629, 36933), -- Raza'kul, Nemesis: Becoming Death
(86629, 36930), -- Raza'kul, Nemesis: Draenei Destroyer
(86629, 36924), -- Raza'kul, Nemesis: Dwarfstalker
(86629, 36926), -- Raza'kul, Nemesis: Gnomebane
(86629, 36889), -- Raza'kul, Nemesis: Hunter - Hunted
(86629, 36921), -- Raza'kul, Nemesis: Manslayer
(86629, 36932), -- Raza'kul, Nemesis: Scourge of the Kaldorei
(86629, 36934), -- Raza'kul, Nemesis: Terror of the Tushui
(86629, 36928), -- Raza'kul, Nemesis: Worgen Hunter
(86629, 36874), -- Raza'kul, Warlord of Draenor
(86677, 36957), -- Kuros, Nemesis: Becoming Death
(86677, 36959), -- Kuros, Nemesis: Becoming Death
(86677, 36961), -- Kuros, Nemesis: Becoming Death
(86677, 36963), -- Kuros, Nemesis: Becoming Death
(86677, 36965), -- Kuros, Nemesis: Becoming Death
(86677, 36967), -- Kuros, Nemesis: Becoming Death
(86677, 36969), -- Kuros, Nemesis: Becoming Death
(86677, 36960), -- Kuros, Nemesis: Death Stalker
(86677, 36955), -- Kuros, Nemesis: Hunter - Hunted
(86677, 36968), -- Kuros, Nemesis: Huojin's Fall
(86677, 36970), -- Kuros, Nemesis: Killer of Kezan
(86677, 36964), -- Kuros, Nemesis: Orcslayer
(86677, 36958), -- Kuros, Nemesis: Slayer of Sin'dorei
(86677, 36962), -- Kuros, Nemesis: The Butcher
(86677, 36966), -- Kuros, Nemesis: Troll Hunter
(86677, 36876), -- Kuros, Warlord of Draenor
(86803, 37062), -- Fayla Fairfeather, Tricks of the Trade
(86806, 37014), -- Ancient Trading Mechanism, Auctioning for Parts
(86832, 24612), -- Vol'jin, A Gift for the Warchief
(86832, 13841), -- Vol'jin, All Apologies
(86832, 13842), -- Vol'jin, Dread Head Redemption
(86832, 9626), -- Vol'jin, Meeting the Warchief
(86832, 25267), -- Vol'jin, Message for Vol'jin
(86832, 7783), -- Vol'jin, The Lord of Blackrock
(86832, 26798), -- Vol'jin, The Warchief Will be Pleased
(86832, 26830), -- Vol'jin, Traitor's Bait
(86832, 26397), -- Vol'jin, Walk With The Earth Mother
(86832, 13189), -- Vol'jin, Warchief's Blessing
(86832, 28717), -- Vol'jin, Warchief's Command: Twilight Highlands!
(86832, 36940), -- Vol'jin, Warning the Warchief
(86832, 26294), -- Vol'jin, Weapons of Mass Dysfunction
(86884, 25266), -- Darkspear Loyalist, Warchief's Emissary
(86927, 37080), -- Stormshield Death Knight, Glorious Slaughter
(86927, 37129), -- Stormshield Death Knight, Unwelcome Memories
(86933, 37081), -- Warspear Magus, Burning Rage
(86933, 37131), -- Warspear Magus, The Dark Lady's Concern
(86934, 37127), -- Sha'tari Defender, The Light of Exodus
(86934, 37047), -- Sha'tari Defender, The Light's Gift
(86945, 37070), -- Sunsworn Warlock, Power of the Nether
(86945, 37128), -- Sunsworn Warlock, Settling Grievances
(86946, 37137), -- Outcast Talonpriest, Scrying Hard or Hardly Scrying
(86946, 37182), -- Outcast Talonpriest, Scrying Hard or Hardly Scrying
(86946, 37084), -- Outcast Talonpriest, The Shadows Call
(86964, 37085), -- Bloodmane Earthbinder, Fury of the Clan
(86964, 37140), -- Bloodmane Earthbinder, Leorajh's Prayer Beads
(86964, 37181), -- Bloodmane Earthbinder, Leorajh's Prayer Beads
(86973, 36913), -- Keegan Firebeard, Besting a Boar
(86973, 36997), -- Keegan Firebeard, Boar Training: Bulbapore
(86973, 36998), -- Keegan Firebeard, Boar Training: Cruel Ogres
(86973, 36999), -- Keegan Firebeard, Boar Training: Darkwing Roc
(86973, 36996), -- Keegan Firebeard, Boar Training: Gezz'ran
(86973, 37002), -- Keegan Firebeard, Boar Training: Ironbore
(86973, 37000), -- Keegan Firebeard, Boar Training: Moth of Wrath
(86973, 37003), -- Keegan Firebeard, Boar Training: Orc Hunters
(86973, 36995), -- Keegan Firebeard, Boar Training: Riplash
(86973, 37004), -- Keegan Firebeard, Boar Training: The Garn
(86973, 37001), -- Keegan Firebeard, Boar Training: Thundercall
(86973, 36916), -- Keegan Firebeard, Capturing a Clefthoof
(86973, 36987), -- Keegan Firebeard, Clefthoof Training: Bulbapore
(86973, 36988), -- Keegan Firebeard, Clefthoof Training: Cruel Ogres
(86973, 36989), -- Keegan Firebeard, Clefthoof Training: Darkwing Roc
(86973, 36986), -- Keegan Firebeard, Clefthoof Training: Gezz'ran
(86973, 36983), -- Keegan Firebeard, Clefthoof Training: Great-Tusk
(86973, 36992), -- Keegan Firebeard, Clefthoof Training: Ironbore
(86973, 36990), -- Keegan Firebeard, Clefthoof Training: Moth of Wrath
(86973, 36993), -- Keegan Firebeard, Clefthoof Training: Orc Hunters
(86973, 36984), -- Keegan Firebeard, Clefthoof Training: Rakkiri
(86973, 36985), -- Keegan Firebeard, Clefthoof Training: Riplash
(86973, 36994), -- Keegan Firebeard, Clefthoof Training: The Garn
(86973, 36991), -- Keegan Firebeard, Clefthoof Training: Thundercall
(86973, 37015), -- Keegan Firebeard, Elekk Training: Cruel Ogres
(86973, 37016), -- Keegan Firebeard, Elekk Training: Darkwing Roc
(86973, 37019), -- Keegan Firebeard, Elekk Training: Ironbore
(86973, 37017), -- Keegan Firebeard, Elekk Training: Moth of Wrath
(86973, 37020), -- Keegan Firebeard, Elekk Training: Orc Hunters
(86973, 37021), -- Keegan Firebeard, Elekk Training: The Garn
(86973, 37018), -- Keegan Firebeard, Elekk Training: Thundercall
(86973, 36915), -- Keegan Firebeard, Entangling an Elekk
(86974, 36918), -- Fanny Firebeard, Requisition a Riverbeast
(86974, 37006), -- Fanny Firebeard, Riverbeast Training: Bulbapore
(86974, 37007), -- Fanny Firebeard, Riverbeast Training: Cruel Ogres
(86974, 37008), -- Fanny Firebeard, Riverbeast Training: Darkwing Roc
(86974, 37005), -- Fanny Firebeard, Riverbeast Training: Gezz'ran
(86974, 37011), -- Fanny Firebeard, Riverbeast Training: Ironbore
(86974, 37009), -- Fanny Firebeard, Riverbeast Training: Moth of Wrath
(86974, 37012), -- Fanny Firebeard, Riverbeast Training: Orc Hunters
(86974, 37013), -- Fanny Firebeard, Riverbeast Training: The Garn
(86974, 37010), -- Fanny Firebeard, Riverbeast Training: Thundercall
(86974, 36975), -- Fanny Firebeard, Talbuk Training: Bulbapore
(86974, 36976), -- Fanny Firebeard, Talbuk Training: Cruel Ogres
(86974, 36977), -- Fanny Firebeard, Talbuk Training: Darkwing Roc
(86974, 36974), -- Fanny Firebeard, Talbuk Training: Gezz'ran
(86974, 36971), -- Fanny Firebeard, Talbuk Training: Great-Tusk
(86974, 36980), -- Fanny Firebeard, Talbuk Training: Ironbore
(86974, 36978), -- Fanny Firebeard, Talbuk Training: Moth of Wrath
(86974, 36981), -- Fanny Firebeard, Talbuk Training: Orc Hunters
(86974, 36972), -- Fanny Firebeard, Talbuk Training: Rakkiri
(86974, 36973), -- Fanny Firebeard, Talbuk Training: Riplash
(86974, 36982), -- Fanny Firebeard, Talbuk Training: The Garn
(86974, 36979), -- Fanny Firebeard, Talbuk Training: Thundercall
(86974, 36911), -- Fanny Firebeard, Taming a Talbuk
(86974, 37122), -- Fanny Firebeard, Teeth of a Predator
(86974, 37121), -- Fanny Firebeard, The Black Claw
(86974, 37022), -- Fanny Firebeard, Wolf Training: Cruel Ogres
(86974, 37023), -- Fanny Firebeard, Wolf Training: Darkwing Roc
(86974, 37026), -- Fanny Firebeard, Wolf Training: Ironbore
(86974, 37024), -- Fanny Firebeard, Wolf Training: Moth of Wrath
(86974, 37027), -- Fanny Firebeard, Wolf Training: Orc Hunters
(86974, 37028), -- Fanny Firebeard, Wolf Training: The Garn
(86974, 37025), -- Fanny Firebeard, Wolf Training: Thundercall
(86974, 36914), -- Fanny Firebeard, Wrangling a Wolf
(86979, 36944), -- Tormak the Scarred, Besting a Boar
(86979, 37034), -- Tormak the Scarred, Boar Training: Bulbapore
(86979, 37035), -- Tormak the Scarred, Boar Training: Cruel Ogres
(86979, 37036), -- Tormak the Scarred, Boar Training: Darkwing Roc
(86979, 37033), -- Tormak the Scarred, Boar Training: Gezz'ran
(86979, 37039), -- Tormak the Scarred, Boar Training: Ironbore
(86979, 37037), -- Tormak the Scarred, Boar Training: Moth of Wrath
(86979, 37040), -- Tormak the Scarred, Boar Training: Orc Hunters
(86979, 37032), -- Tormak the Scarred, Boar Training: Riplash
(86979, 37041), -- Tormak the Scarred, Boar Training: The Garn
(86979, 37038), -- Tormak the Scarred, Boar Training: Thundercall
(86979, 36912), -- Tormak the Scarred, Capturing a Clefthoof
(86979, 37052), -- Tormak the Scarred, Clefthoof Training: Bulbapore
(86979, 37053), -- Tormak the Scarred, Clefthoof Training: Cruel Ogres
(86979, 37054), -- Tormak the Scarred, Clefthoof Training: Darkwing Roc
(86979, 37051), -- Tormak the Scarred, Clefthoof Training: Gezz'ran
(86979, 37048), -- Tormak the Scarred, Clefthoof Training: Great-Tusk
(86979, 37057), -- Tormak the Scarred, Clefthoof Training: Ironbore
(86979, 37055), -- Tormak the Scarred, Clefthoof Training: Moth of Wrath
(86979, 37058), -- Tormak the Scarred, Clefthoof Training: Orc Hunters
(86979, 37049), -- Tormak the Scarred, Clefthoof Training: Rakkiri
(86979, 37050), -- Tormak the Scarred, Clefthoof Training: Riplash
(86979, 37059), -- Tormak the Scarred, Clefthoof Training: The Garn
(86979, 37056), -- Tormak the Scarred, Clefthoof Training: Thundercall
(86979, 37063), -- Tormak the Scarred, Elekk Training: Cruel Ogres
(86979, 37064), -- Tormak the Scarred, Elekk Training: Darkwing Roc
(86979, 37067), -- Tormak the Scarred, Elekk Training: Ironbore
(86979, 37065), -- Tormak the Scarred, Elekk Training: Moth of Wrath
(86979, 37068), -- Tormak the Scarred, Elekk Training: Orc Hunters
(86979, 37069), -- Tormak the Scarred, Elekk Training: The Garn
(86979, 37066), -- Tormak the Scarred, Elekk Training: Thundercall
(86979, 36946), -- Tormak the Scarred, Entangling an Elekk
(87112, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87113, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87114, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87115, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87116, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87117, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87118, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87119, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87120, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87121, 37062), -- Fayla Fairfeather, Tricks of the Trade
(87122, 37205), -- Gargra, Gargra
(87206, 36948), -- Ancient Trading Mechanism, Auctioning for Parts
(87207, 37088), -- Trader Joseph, Tricks of the Trade
(87208, 37088), -- Trader Joseph, Tricks of the Trade
(87209, 37088), -- Trader Joseph, Tricks of the Trade
(87210, 37088), -- Trader Joseph, Tricks of the Trade
(87211, 37088), -- Trader Joseph, Tricks of the Trade
(87212, 37088), -- Trader Joseph, Tricks of the Trade
(87213, 37088), -- Trader Joseph, Tricks of the Trade
(87214, 37088), -- Trader Joseph, Tricks of the Trade
(87215, 37088), -- Trader Joseph, Tricks of the Trade
(87216, 37088), -- Trader Joseph, Tricks of the Trade
(87217, 37088), -- Trader Joseph, Tricks of the Trade
(87225, 37029), -- Goraluk Anvilcrack, Sigil of the Black Hand
(87225, 37030), -- Goraluk Anvilcrack, Sigil of the Black Hand (Heroic)
(87225, 37031), -- Goraluk Anvilcrack, Sigil of the Black Hand (Mythic)
(87242, 36945), -- Sage Paluna, Requisition a Riverbeast
(87242, 37072), -- Sage Paluna, Riverbeast Training: Bulbapore
(87242, 37073), -- Sage Paluna, Riverbeast Training: Cruel Ogres
(87242, 37074), -- Sage Paluna, Riverbeast Training: Darkwing Roc
(87242, 37071), -- Sage Paluna, Riverbeast Training: Gezz'ran
(87242, 37077), -- Sage Paluna, Riverbeast Training: Ironbore
(87242, 37075), -- Sage Paluna, Riverbeast Training: Moth of Wrath
(87242, 37078), -- Sage Paluna, Riverbeast Training: Orc Hunters
(87242, 37079), -- Sage Paluna, Riverbeast Training: The Garn
(87242, 37076), -- Sage Paluna, Riverbeast Training: Thundercall
(87242, 37097), -- Sage Paluna, Talbuk Training: Bulbapore
(87242, 37098), -- Sage Paluna, Talbuk Training: Cruel Ogres
(87242, 37099), -- Sage Paluna, Talbuk Training: Darkwing Roc
(87242, 37096), -- Sage Paluna, Talbuk Training: Gezz'ran
(87242, 37093), -- Sage Paluna, Talbuk Training: Great-Tusk
(87242, 37102), -- Sage Paluna, Talbuk Training: Ironbore
(87242, 37100), -- Sage Paluna, Talbuk Training: Moth of Wrath
(87242, 37103), -- Sage Paluna, Talbuk Training: Orc Hunters
(87242, 37094), -- Sage Paluna, Talbuk Training: Rakkiri
(87242, 37095), -- Sage Paluna, Talbuk Training: Riplash
(87242, 37104), -- Sage Paluna, Talbuk Training: The Garn
(87242, 37101), -- Sage Paluna, Talbuk Training: Thundercall
(87242, 36917), -- Sage Paluna, Taming a Talbuk
(87242, 37124), -- Sage Paluna, Teeth of a Predator
(87242, 37123), -- Sage Paluna, The Black Claw
(87242, 37105), -- Sage Paluna, Wolf Training: Cruel Ogres
(87242, 37106), -- Sage Paluna, Wolf Training: Darkwing Roc
(87242, 37109), -- Sage Paluna, Wolf Training: Ironbore
(87242, 37107), -- Sage Paluna, Wolf Training: Moth of Wrath
(87242, 37110), -- Sage Paluna, Wolf Training: Orc Hunters
(87242, 37111), -- Sage Paluna, Wolf Training: The Garn
(87242, 37108), -- Sage Paluna, Wolf Training: Thundercall
(87242, 36950), -- Sage Paluna, Wrangling a Wolf
(87305, 37046), -- Akanja, The Headhunter's Harvest
(87971, 37204), -- Firaga, Rekindling an Old Flame
(87991, 37228), -- Cro Threadstrong, A Fruitful Proposition
(87991, 37152), -- Cro Threadstrong, Cro's Revenge
(87992, 37229), -- Olaf, Like A Dwarf In A Mine
(87992, 37153), -- Olaf, Time-Lost Vikings
(87994, 37230), -- Moroes, Bloody Expensive
(87994, 37157), -- Moroes, Feeling A Bit Morose
(87995, 37155), -- Fleet Master Seahorn, The Brass Compass
(87995, 37231), -- Fleet Master Seahorn, The Search Continues
(87996, 37232), -- Lilian Voss, Soulcarver Voss
(87996, 37156), -- Lilian Voss, The Soulcutter
(87997, 37154), -- Leonid Barthalomew the Revered, The Cure For Death
(87997, 37233), -- Leonid Barthalomew the Revered, Vessel of Virtue
(87998, 37158), -- Sunwalker Dezco, Gloriously Incandescent
(87998, 37234), -- Sunwalker Dezco, The Dark Within
(87999, 37235), -- Skylord Omnuron, A Plea to the Sky
(87999, 37159), -- Skylord Omnuron, Aviana's Request
(88000, 37161), -- Finkle Einhorn, Family Traditions
(88000, 37236), -- Finkle Einhorn, Like Father, Like Son
(88001, 37237), -- Maximillian of Northshire, A Hero's Quest is Never Complete
(88001, 37162), -- Maximillian of Northshire, Damsels and Dragons
(88002, 37238), -- Highlord Darion Mograine, Secrets of Soulbinding
(88002, 37163), -- Highlord Darion Mograine, Shadowy Secrets
(88003, 37239), -- Cowled Ranger, Fate of the Fallen
(88003, 37164), -- Cowled Ranger, The Huntresses
(88004, 37165), -- Zen'kiki, Cenarion Concerns
(88004, 37240), -- Zen'kiki, The Leaf-Reader
(88005, 37241), -- Lorewalker Cho, Lessons of the Past
(88005, 37166), -- Lorewalker Cho, Titanic Evolution
(88006, 37167), -- Lonika Stillblade, And No Maces!
(88006, 37242), -- Lonika Stillblade, Learning Is Painful
(88007, 37243), -- Gamon, An Axe to Grind
(88007, 37160), -- Gamon, Cleaving Time
(88009, 37179), -- Millhouse Manastorm, For The Children!
(88013, 37142), -- Lunk, Ogre Ancestry
(88017, 37145), -- Budd, Budd's Gambit
(88022, 37146), -- Johnny Awesome, Go Fetch
(88023, 37147), -- Taoshi, Sky Dancers
(88024, 37244), -- Oralius, Flamefly Trap
(88024, 37148), -- Oralius, Oralius' Adventure
(88025, 37150), -- Mylune, For the Birds
(88025, 37227), -- Mylune, Put a Bird on It
(88026, 37151), -- John J. Keeshan, Cold Steel
(88026, 37209), -- John J. Keeshan, Cold Steel Part II
(88027, 37149), -- Impsy, The Void-Gate
(88027, 37245), -- Impsy, Whispers in the Darkness
(88112, 34410), -- Morthis Whisperwing, The Beating Heart
(88145, 37270), -- Alchemy Follower - Alliance, Alchemy Experiment
(88147, 37563), -- Makar Stonebinder, The Frostwolves Stand Ready
(88223, 33814), -- Sergeant Crowler, Fast Expansion
(88223, 37289), -- Sergeant Crowler, Shadowmoon Invasion!
(88228, 37291), -- Sergeant Grimjaw, Thunderlord Invasion!
(88395, 35786), -- Blood Guard Reejah, Bronze Victory
(88395, 35788), -- Blood Guard Reejah, Gold Victory
(88395, 35787), -- Blood Guard Reejah, Silver Victory
(88458, 37305), -- Corporal Oslo, Bronze Victory
(88458, 37307), -- Corporal Oslo, Gold Victory
(88458, 37306), -- Corporal Oslo, Silver Victory
(88545, 37320), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: A Fine Choker
(88545, 37321), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: A Yellow Brighter Than Gold
(88545, 37323), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: Blue the Shade of Sky and Sea
(88545, 37319), -- Jewelcrafting Follower - Alliance, Jewelcrafting Special Order: Wedding Bands
(88545, 37324), -- Jewelcrafting Follower - Alliance, Out of Stock: Blackrock Ore
(88545, 37325), -- Jewelcrafting Follower - Alliance, Out of Stock: True Iron Ore
(88546, 37320), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: A Fine Choker
(88546, 37321), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: A Yellow Brighter Than Gold
(88546, 37323), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: Blue the Shade of Sky and Sea
(88546, 37319), -- Jewelcrafting Follower - Horde, Jewelcrafting Special Order: Wedding Bands
(88546, 37324), -- Jewelcrafting Follower - Horde, Out of Stock: Blackrock Ore
(88546, 37325), -- Jewelcrafting Follower - Horde, Out of Stock: True Iron Ore
(88892, 37516), -- Nixxie, News for Nixxie
(88892, 37517), -- Nixxie, News for Nixxie
(90675, 38299), -- Erris the Collector, Critters of Draenor
(90894, 38243), -- Alexi Hackercam, A Bit of Ore
(91014, 38299), -- Erris the Collector, Critters of Draenor
(91015, 38299), -- Erris the Collector, Critters of Draenor
(91016, 38299), -- Erris the Collector, Critters of Draenor
(91017, 38299), -- Erris the Collector, Critters of Draenor
(91020, 38290), -- Enchantress Ismae, Some Dust
(91024, 38287), -- Jake the Fox, Raw Beast Hides
(91025, 38293), -- Dorothy "Two", Sumptuous Fur
(91026, 38300), -- Kura Thunderhoof, Critters of Draenor
(91070, 37062), -- Fayla Fairfeather, Tricks of the Trade
(91071, 37088), -- Trader Joseph, Tricks of the Trade
(91072, 37961), -- Drix Bassbolter, Bringing the Bass
(91242, 38259), -- Solog Roark, All Hands on Deck
(91242, 38574), -- Solog Roark, All Hands on Deck
(91242, 38256), -- Solog Roark, Hook, Line, and... Sink Him!
(91242, 38572), -- Solog Roark, Hook, Line, and... Sink Him!
(91242, 38255), -- Solog Roark, The Train Gang
(91242, 38571), -- Solog Roark, The Train Gang
(91361, 38300), -- Kura Thunderhoof, Critters of Draenor
(91362, 38300), -- Kura Thunderhoof, Critters of Draenor
(91363, 38300), -- Kura Thunderhoof, Critters of Draenor
(91364, 38300), -- Kura Thunderhoof, Critters of Draenor
(91404, 38296), -- Samantha Scarlet, Herbs Galore
(91589, 38356), -- Fix "Smallie" Biggswrench, Bringing the Bass
(92213, 39057), -- Archmage Khadgar, Command of the Seas
(92213, 39003), -- Archmage Khadgar, Cooking the Books
(92213, 39004), -- Archmage Khadgar, Darkness Incarnate
(92213, 37840), -- Archmage Khadgar, Draenor's Blessing
(92213, 39697), -- Archmage Khadgar, Master vs. Commander
(92213, 37841), -- Archmage Khadgar, The Final Assault
(92213, 37835), -- Archmage Khadgar, The Shadow War
(92213, 39000), -- Archmage Khadgar, We Don't Need No Library Card
(92219, 38253), -- King Varian Wrynn, Garrison Campaign: War Council
(92219, 38258), -- King Varian Wrynn, Nothing Remains
(92400, 38567), -- Vol'jin, Garrison Campaign: War Council
(92400, 38573), -- Vol'jin, Nothing Remains
(94429, 39082), -- Solog Roark, Let's Get To Work
(94429, 39236), -- Solog Roark, Let's Get To Work
(94429, 39242), -- Solog Roark, Ship Shape
(94429, 39054), -- Solog Roark, Shipbuilding
(94429, 39241), -- Solog Roark, Shipbuilding
(94789, 39676), -- Rolosh Wavechaser, A True Naval Commander
(94789, 39401), -- Rolosh Wavechaser, Destroying the Competition
(94789, 39674), -- Rolosh Wavechaser, If At First You Fail, Try Again!
(94789, 39243), -- Rolosh Wavechaser, Naval Commander
(94789, 39246), -- Rolosh Wavechaser, Naval Domination
(94789, 39423), -- Rolosh Wavechaser, Shipyard Report
(94789, 39245), -- Rolosh Wavechaser, Upgrading The Fleet
(94801, 38932), -- Kronk Rustspark, Equipment Blueprint: Bilge Pump
(94801, 39368), -- Kronk Rustspark, Equipment Blueprint: Blast Furnace
(94801, 39366), -- Kronk Rustspark, Equipment Blueprint: Felsmoke Launchers
(94801, 39365), -- Kronk Rustspark, Equipment Blueprint: Ghostly Spyglass
(94801, 39364), -- Kronk Rustspark, Equipment Blueprint: Gyroscopic Internal Stabilizer
(94801, 39356), -- Kronk Rustspark, Equipment Blueprint: High Intensity Fog Lights
(94801, 39363), -- Kronk Rustspark, Equipment Blueprint: Ice Cutter
(94801, 39355), -- Kronk Rustspark, Equipment Blueprint: Trained Shark Tank
(94801, 39360), -- Kronk Rustspark, Equipment Blueprint: True Iron Rudder
(94801, 39359), -- Kronk Rustspark, Equipment Blueprint: Tuskarr Fishing Net
(94801, 39358), -- Kronk Rustspark, Equipment Blueprint: Unsinkable
(94801, 39675), -- Kronk Rustspark, Equipping Our Fleet
(94870, 39020), -- Seer Kazal, A Burning Path Through Time
(94870, 39040), -- Seer Kazal, A Call to Battle
(94870, 39021), -- Seer Kazal, A Frozen Path Through Time
(94870, 39034), -- Seer Kazal, Emissary of War
(94870, 39041), -- Seer Kazal, The Arena Calls
(94870, 39033), -- Seer Kazal, The Time to Strike
(94870, 39042), -- Seer Kazal, The Very Best
(95659, 39502), -- Archmage Khadgar, The Fel Spire
(95659, 39504), -- Archmage Khadgar, The Fel Spire
(95659, 39499), -- Archmage Khadgar, Well of Souls
(95659, 39500), -- Archmage Khadgar, Well of Souls
(95659, 39501); -- Archmage Khadgar, Well of Souls
