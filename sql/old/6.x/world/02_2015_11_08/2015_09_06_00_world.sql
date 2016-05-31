UPDATE `creature_template` SET `npcflag` = `npcflag`|2 WHERE entry IN (75028, 75119, 75121, 75246, 75249, 75250, 75256, 75288, 75311, 75323, 75324, 75389, 75392, 75803, 75804, 75805, 75806, 75808, 75873, 75874, 75896, 75924, 75941, 75958, 75959, 75968, 76665, 76790, 76804, 76826, 77031, 77082, 77580, 77581, 77582, 77629, 77737, 77799, 77853, 77869, 78028, 78082, 78083, 78102, 78482, 78513, 78515, 78519, 78534, 78577, 79133, 79159, 79176, 79210, 79329, 79356, 79392, 79393, 79434, 79573, 79612, 79618, 79627, 79689, 79696, 79724, 79853, 79870, 79901, 79921, 79963, 79978, 79979, 80028, 80142, 80229, 80339, 80342, 80390, 80396, 80553, 80607, 80608, 80623, 80627, 80628, 80630, 80672, 80833, 80854, 80965, 80966, 80968, 81789, 83823, 83929, 86442, 86522, 86949, 87125, 87764, 90233, 90237, 91750, 91751);

DELETE FROM `creature_queststarter` WHERE `id` IN (75028, 75119, 75121, 75246, 75249, 75250, 75256, 75288, 75311, 75323, 75324, 75389, 75392, 75803, 75804, 75805, 75806, 75808, 75873, 75874, 75896, 75924, 75941, 75958, 75959, 75968, 76665, 76790, 76804, 76826, 77031, 77082, 77580, 77581, 77582, 77629, 77737, 77799, 77853, 77869, 78028, 78082, 78083, 78102, 78482, 78513, 78515, 78519, 78534, 78577, 79133, 79159, 79176, 79210, 79329, 79356, 79392, 79393, 79434, 79573, 79612, 79618, 79627, 79689, 79696, 79724, 79853, 79870, 79901, 79921, 79963, 79978, 79979, 80028, 80142, 80229, 80339, 80342, 80390, 80396, 80553, 80607, 80608, 80623, 80627, 80628, 80630, 80672, 80833, 80854, 80965, 80966, 80968, 81789, 83823, 83929, 86442, 86522, 86949, 87125, 87764, 90233, 90237, 91750, 91751);
DELETE FROM `creature_questender` WHERE `id` IN (75028, 75119, 75121, 75246, 75249, 75250, 75256, 75311, 75323, 75324, 75389, 75392, 75803, 75804, 75805, 75806, 75808, 75874, 75896, 75924, 75941, 75958, 75959, 75968, 76665, 76804, 76826, 77031, 77082, 77580, 77581, 77582, 77629, 77737, 77799, 77853, 77869, 78028, 78082, 78083, 78102, 78482, 78513, 78515, 78519, 78534, 79133, 79159, 79176, 79210, 79329, 79356, 79392, 79393, 79434, 79612, 79618, 79853, 79870, 79901, 79921, 79963, 79978, 79979, 80028, 80142, 80229, 80339, 80342, 80390, 80396, 80553, 80607, 80608, 80623, 80627, 80628, 80630, 80672, 80833, 80854, 80965, 80966, 80968, 83823, 83929, 86949, 87125, 90233, 90237, 91750, 91751);

INSERT INTO `creature_queststarter` VALUES
(75028, 35683), -- Exarch Maladaar, Reclaiming the City
(75028, 35685), -- Exarch Maladaar, Socrethar's Demise
(75119, 34407), -- Exarch Maladaar, Holding the Line
(75119, 34452), -- Exarch Maladaar, Light's Rest
(75121, 34418), -- Lady Liadrin, Holding the Line
(75121, 34451), -- Lady Liadrin, Sunsworn Camp
(75246, 34242), -- Lady Liadrin, Scheduled Pickup
(75249, 33972), -- Mehlar Dawnblade, Vile Defilers
(75250, 34240), -- Exarch Maladaar, Scheduled Pickup
(75256, 33958), -- Soulbinder Nyami, Into the Hollow
(75256, 33970), -- Soulbinder Nyami, Into the Hollow
(75288, 33580), -- Shadow-Sage Iskar, The Purge of Veil Shadar
(75311, 33578), -- Raksi, Pyrophobia
(75311, 33579), -- Raksi, What the Draenei Found
(75323, 33581), -- Darkscryer Raastok, Forbidden Knowledge
(75324, 33582), -- Kura the Blind, Kura's Vengeance
(75389, 34122), -- Lady Liadrin, Ogre Diplomacy
(75389, 34144), -- Lady Liadrin, Retribution for the Light
(75392, 34157), -- Exarch Maladaar, Into the Heart of Madness
(75392, 35227), -- Exarch Maladaar, Ogre Diplomacy
(75392, 35254), -- Exarch Maladaar, Retribution for the Light
(75803, 34959), -- Vindicator Maraad, Dreadpiston
(75803, 34963), -- Vindicator Maraad, Khadgar's Plan
(75803, 34087), -- Vindicator Maraad, Through the Looking Glass
(75803, 34088), -- Vindicator Maraad, Too Many Irons in the Fire
(75804, 34089), -- Yrel, In Short Supply
(75804, 34095), -- Yrel, Iron Them Out
(75805, 33731), -- Archmage Khadgar, The Battle for Shattrath
(75805, 34099), -- Archmage Khadgar, The Battle for Shattrath
(75806, 35226), -- Durotan, Old Friends, New Enemies
(75806, 33754), -- Durotan, Through the Looking Glass
(75806, 33722), -- Durotan, Too Many Irons in the Fire
(75808, 33735), -- Draka, In Short Supply
(75808, 33736), -- Draka, Iron Them Out
(75873, 33721), -- Gazlowe, Gazlowe's Solution
(75874, 34096), -- Thaelin Darkanvil, An Eye for a Spy
(75874, 34097), -- Thaelin Darkanvil, Born to Shred
(75874, 34098), -- Thaelin Darkanvil, Engineering Her Demise
(75874, 34947), -- Thaelin Darkanvil, Shredder Manual
(75874, 34090), -- Thaelin Darkanvil, Thaelin's Quick Fix
(75874, 34094), -- Thaelin Darkanvil, Vol. X Pages ?
(75896, 33740), -- Crystal-Shaper Barum, Burning Sky
(75896, 33734), -- Crystal-Shaper Barum, Pieces of Us
(75924, 34948), -- Gazlowe, Shredder Manual
(75924, 33724), -- Gazlowe, Vol. X Pages ?
(75941, 33728), -- Gazlowe, An Eye for a Spy
(75941, 33729), -- Gazlowe, Born to Shred
(75941, 33730), -- Gazlowe, Engineering Her Demise
(75958, 34950), -- Durotan, Dreadpiston
(75959, 34962), -- Durotan, Khadgar's Plan
(75968, 33730), -- Iron Shredder Prototype, Engineering Her Demise
(75968, 34098), -- Iron Shredder Prototype, Engineering Her Demise
(76665, 33874), -- Seer Malune, Aruumel's Rest
(76665, 33873), -- Seer Malune, Cure of Aruunem
(76665, 33872), -- Seer Malune, Dust of the Dead
(76790, 33530), -- Yuuri, Nightmare in the Tomb
(76804, 35684), -- Lady Liadrin, Reclaiming the City
(76804, 35687), -- Lady Liadrin, Socrethar's Demise
(76826, 33882), -- Caleb, Just Peachicky
(76826, 33884), -- Caleb, Sher'KHAAAAAAANNNN!
(77031, 33973), -- Ahm, Dying Wish
(77082, 34326), -- Restalaan, Changing the Tide
(77082, 33976), -- Restalaan, The Final Piece
(77580, 34706), -- Lady Liadrin, Come Together
(77581, 34707), -- Exarch Maladaar, Come Together
(77582, 34154), -- Soulbinder Nyami, Destination: Unknown
(77582, 34564), -- Soulbinder Nyami, Destination: Unknown
(77629, 34164), -- Kor'thos Dawnfury, Book Burning
(77737, 34351), -- Soulbinder Tuulani, We Must Construct Additional Pylons
(77799, 34092), -- Restalaan, Desperate Measures
(77853, 36027), -- Image of Archmage Vargoth, The Staff of Archmage Vargoth
(77869, 34508), -- Soulbinder Tuulani, Restalaan, Captain of the Guard
(78028, 33967), -- Soulbinder Tuulani, Antivenin
(78028, 33971), -- Soulbinder Tuulani, Antivenin
(78082, 34234), -- Vindicator Kaluud, Payback
(78083, 34013), -- Defender Artaal, Never Forget
(78102, 33969), -- Vindicator Namuun, Vile Defilers
(78482, 33917), -- Vindicator Nobundo, Disrupting the Flow
(78513, 34415), -- Archmage Elandra, An'dure The Giant
(78513, 34403), -- Archmage Elandra, Arcane Essence
(78513, 34406), -- Archmage Elandra, Caught In The Chaos
(78513, 34448), -- Archmage Elandra, Kaelynara Sunchaser
(78515, 34414), -- Manduil Skycaller, An'dure The Giant
(78515, 34401), -- Manduil Skycaller, Arcane Essence
(78515, 34404), -- Manduil Skycaller, Crystals of Unusual Power
(78515, 34447), -- Manduil Skycaller, Kaelynara Sunchaser
(78519, 33920), -- Soulbinder Nyami, The Heart of Auchindoun
(78534, 34400), -- Ageilaa, Frenzied Manafeeders
(78534, 34399), -- Ageilaa, Trouble In The Mine
(78577, 35249), -- Mehlar Dawnblade, Powering the Defenses
(79133, 34631), -- Foreman Eksos, An Audience With The Archmage
(79133, 34558), -- Foreman Eksos, At Your Command
(79133, 34563), -- Foreman Eksos, The Quarry Quandary
(79159, 35045), -- Apprentice Miall, In Ared's Memory
(79176, 34632), -- Foreman Grobash, An Audience With The Archmage
(79176, 34566), -- Foreman Grobash, At Your Command
(79176, 34569), -- Foreman Grobash, The Quarry Quandary
(79210, 35102), -- Morketh Bladehowl, Unleashed Steel
(79329, 34624), -- Miall, Gas Guzzlers
(79329, 34578), -- Miall, Going to the Gordunni
(79329, 34573), -- Miall, Iridium Recovery
(79329, 34571), -- Miall, Out of Jovite
(79356, 34579), -- Morketh Bladehowl, Gas Guzzlers
(79356, 34837), -- Morketh Bladehowl, Going to the Gordunni
(79356, 34576), -- Morketh Bladehowl, Iridium Recovery
(79356, 34577), -- Morketh Bladehowl, Out of Jovite
(79392, 34609), -- Magister Serena, Creating the Ink
(79392, 34612), -- Magister Serena, Forming the Scroll
(79392, 34619), -- Magister Serena, Gathering the Spark
(79393, 34634), -- Magister Krelas, Creating the Ink
(79393, 34635), -- Magister Krelas, Forming the Scroll
(79393, 34636), -- Magister Krelas, Gathering the Spark
(79434, 36512), -- Soulbinder Tuulani, Together We Are Strong
(79573, 34685), -- Kalaam, As the Smoke Rises
(79612, 34696), -- Knight-Lord Dranarus, The Lady of Light
(79618, 35554), -- Vindicator Icia, News from Spires of Arak
(79618, 34701), -- Vindicator Icia, Speaker for the Dead
(79627, 35537), -- Shadow Hunter Kajassa, News from Spires of Arak
(79627, 34683), -- Shadow Hunter Kajassa, One Step Ahead
(79689, 34709), -- Aeun, Every Bit Counts
(79696, 34710), -- Ranger Belonis, Every Bit Counts
(79724, 33871), -- Elumm, Seek Out the Seer
(79724, 34721), -- Elumm, Seek Out the Seer
(79853, 35238), -- Pleasure-Bot 8000, New Owner
(79853, 35239), -- Pleasure-Bot 8000, New Owner
(79870, 34751), -- Ziz Fizziks, Clear!
(79901, 34761), -- Torben Zapblast, Clear!
(79921, 34766), -- Provisioner Naya, Logistical Nightmare
(79921, 34803), -- Provisioner Naya, Send Them Running
(79963, 34804), -- Quartermaster O'Riley, Not In Your House
(79963, 34773), -- Quartermaster O'Riley, Why Is The Brew Gone?
(79978, 34776), -- Aeda Brightdawn, Gatekeepers of Auchindoun
(79978, 36518), -- Aeda Brightdawn, The True Path
(79979, 34777), -- Defender Illona, Gatekeepers of Auchindoun
(79979, 36519), -- Defender Illona, The True Path
(80028, 34801), -- Nadur, A Pilgrimage Gone Awry
(80028, 34802), -- Nadur, A Pilgrimage Gone Awry
(80142, 34814), -- Archmage Khadgar, Making Acquaintances
(80142, 34815), -- Archmage Khadgar, Making Acquaintances
(80229, 34840), -- Morketh Bladehowl, Dropping Bombs
(80339, 34858), -- Morketh Bladehowl, Prized Repossessions
(80339, 34855), -- Morketh Bladehowl, Punching Through
(80339, 34860), -- Morketh Bladehowl, Supply Recovery
(80342, 34971), -- Morketh Bladehowl, The Only Way to Travel
(80390, 34889), -- Magister Krelas, Orbs of Power
(80390, 34888), -- Magister Krelas, Vicious Viziers
(80390, 34887), -- Magister Krelas, While We're in the Neighborhood
(80396, 34879), -- Magister Krelas, Dropping In
(80553, 34949), -- Magister Krelas, Joining the Ranks
(80607, 34913), -- Magister Serena, Dropping In
(80608, 34911), -- Magister Serena, Orbs of Power
(80608, 34910), -- Magister Serena, Vicious Viziers
(80608, 34909), -- Magister Serena, While We're in the Neighborhood
(80623, 34972), -- Morketh Bladehowl, Armor Up
(80627, 34976), -- Miall, Dropping Bombs
(80628, 34978), -- Miall, Prized Repossessions
(80628, 34979), -- Miall, Punching Through
(80628, 34977), -- Miall, Supply Recovery
(80630, 34981), -- Miall, The Only Way to Travel
(80672, 34993), -- Magister Serena, Joining the Ranks
(80833, 34107), -- Beastmaster Tagh, Wanted: Hilaani
(80833, 34108), -- Beastmaster Tagh, Wanted: Kil'uun
(80833, 34106), -- Beastmaster Tagh, Wanted: Ra'tok the Hammer
(80854, 34104), -- Patrick Messer, Wanted: Hilaani
(80854, 34103), -- Patrick Messer, Wanted: Kil'uun
(80854, 34105), -- Patrick Messer, Wanted: Ra'tok the Hammer
(80965, 34878), -- Magister Krelas, The Foot of the Fortress
(80966, 34908), -- Magister Serena, The Foot of the Fortress
(80968, 34982), -- Miall, Armor Up
(81789, 34458), -- Vindicator Kaluud, Powering the Defenses
(83823, 36014), -- Archmage Khadgar, Blackhand's Secret
(83823, 37836), -- Archmage Khadgar, Breaking Badness
(83823, 35990), -- Archmage Khadgar, Core of Flame
(83823, 35991), -- Archmage Khadgar, Core of Iron
(83823, 35992), -- Archmage Khadgar, Core of Life
(83823, 36158), -- Archmage Khadgar, Draenor's Secret Power
(83823, 35997), -- Archmage Khadgar, Empire's Fall
(83823, 35994), -- Archmage Khadgar, Eyes of the Archmage
(83823, 36010), -- Archmage Khadgar, Flamebender's Tome
(83823, 36000), -- Archmage Khadgar, Fugitive Dragon
(83823, 36009), -- Archmage Khadgar, Heart of the Fury
(83823, 35989), -- Archmage Khadgar, Khadgar's Task
(83823, 35998), -- Archmage Khadgar, Legacy of the Sorcerer Kings
(83823, 36013), -- Archmage Khadgar, Might of the Elemental Lords
(83823, 37834), -- Archmage Khadgar, Orb of Dominion
(83823, 36017), -- Archmage Khadgar, Prisoner of the Mind
(83823, 36012), -- Archmage Khadgar, Reverse Piracy
(83823, 36157), -- Archmage Khadgar, Spires of the Betrayer
(83823, 35993), -- Archmage Khadgar, Tackling Teron'gor
(83823, 36005), -- Archmage Khadgar, The Scrying Game
(83823, 36016), -- Archmage Khadgar, The Unbroken Circle
(83823, 37964), -- Archmage Khadgar, To Gul'dan!
(83823, 36007), -- Archmage Khadgar, Touch of the Kirin-Tor
(83929, 36006), -- Cordana Felsong, Hunter: Hunted
(86442, 36801), -- Sloan McCoy, One Step Ahead
(86522, 36843), -- Akhan, They Came From Above
(86949, 34472), -- Zooti Fizzlefury, Temporal Juxtaposition
(87125, 37208), -- Taralune, Taralune
(87764, 37191), -- Sanketsu, Sanketsu, The Burning Blade
(87764, 37192), -- Sanketsu, Sanketsu, The Burning Blade
(90233, 37837), -- Archmage Khadgar, An Inside Job
(90233, 37841), -- Archmage Khadgar, The Final Assault
(90237, 37838), -- Garona Halforcen, My Garona
(91750, 38416), -- Lady Liadrin, Secrets of the Sargerei
(91750, 38417), -- Lady Liadrin, The Sargerei Menace
(91751, 38562), -- Exarch Yrel, Secrets of the Sargerei
(91751, 38565); -- Exarch Yrel, The Sargerei Menace

INSERT INTO `creature_questender` VALUES
(75028, 37553), -- Exarch Maladaar, Essence of the Iron Conqueror
(75028, 37557), -- Exarch Maladaar, Essence of the Iron Conqueror
(75028, 37555), -- Exarch Maladaar, Essence of the Iron Protector
(75028, 37559), -- Exarch Maladaar, Essence of the Iron Protector
(75028, 37554), -- Exarch Maladaar, Essence of the Iron Vanquisher
(75028, 37558), -- Exarch Maladaar, Essence of the Iron Vanquisher
(75028, 35679), -- Exarch Maladaar, Garrison Campaign: The Fall of Shattrath
(75028, 35683), -- Exarch Maladaar, Reclaiming the City
(75028, 35685), -- Exarch Maladaar, Socrethar's Demise
(75119, 34407), -- Exarch Maladaar, Holding the Line
(75119, 33530), -- Exarch Maladaar, Nightmare in the Tomb
(75119, 34701), -- Exarch Maladaar, Speaker for the Dead
(75121, 34418), -- Lady Liadrin, Holding the Line
(75121, 34696), -- Lady Liadrin, The Lady of Light
(75246, 34451), -- Lady Liadrin, Sunsworn Camp
(75249, 33972), -- Mehlar Dawnblade, Vile Defilers
(75250, 34452), -- Exarch Maladaar, Light's Rest
(75256, 33958), -- Soulbinder Nyami, Into the Hollow
(75256, 33970), -- Soulbinder Nyami, Into the Hollow
(75311, 33578), -- Raksi, Pyrophobia
(75323, 33581), -- Darkscryer Raastok, Forbidden Knowledge
(75324, 33582), -- Kura the Blind, Kura's Vengeance
(75389, 34122), -- Lady Liadrin, Ogre Diplomacy
(75389, 34144), -- Lady Liadrin, Retribution for the Light
(75392, 35227), -- Exarch Maladaar, Ogre Diplomacy
(75392, 35254), -- Exarch Maladaar, Retribution for the Light
(75803, 34959), -- Vindicator Maraad, Dreadpiston
(75803, 34098), -- Vindicator Maraad, Engineering Her Demise
(75803, 36801), -- Vindicator Maraad, One Step Ahead
(75803, 34087), -- Vindicator Maraad, Through the Looking Glass
(75803, 34088), -- Vindicator Maraad, Too Many Irons in the Fire
(75804, 34089), -- Yrel, In Short Supply
(75804, 34095), -- Yrel, Iron Them Out
(75805, 34962), -- Archmage Khadgar, Khadgar's Plan
(75805, 34963), -- Archmage Khadgar, Khadgar's Plan
(75806, 34683), -- Durotan, One Step Ahead
(75806, 33754), -- Durotan, Through the Looking Glass
(75808, 33735), -- Draka, In Short Supply
(75808, 33736), -- Draka, Iron Them Out
(75874, 34096), -- Thaelin Darkanvil, An Eye for a Spy
(75874, 34097), -- Thaelin Darkanvil, Born to Shred
(75874, 34091), -- Thaelin Darkanvil, Decommissioned Mission
(75874, 34090), -- Thaelin Darkanvil, Thaelin's Quick Fix
(75874, 34094), -- Thaelin Darkanvil, Vol. X Pages ?
(75896, 34685), -- Crystal-Shaper Barum, As the Smoke Rises
(75896, 36843), -- Crystal-Shaper Barum, They Came From Above
(75924, 33720), -- Gazlowe, Decommissioned Mission
(75924, 33721), -- Gazlowe, Gazlowe's Solution
(75941, 33728), -- Gazlowe, An Eye for a Spy
(75941, 33729), -- Gazlowe, Born to Shred
(75941, 33724), -- Gazlowe, Vol. X Pages ?
(75958, 35226), -- Durotan, Old Friends, New Enemies
(75958, 33722), -- Durotan, Too Many Irons in the Fire
(75959, 34950), -- Durotan, Dreadpiston
(75959, 33730), -- Durotan, Engineering Her Demise
(75968, 33729), -- Iron Shredder Prototype, Born to Shred
(75968, 34097), -- Iron Shredder Prototype, Born to Shred
(76665, 33874), -- Seer Malune, Aruumel's Rest
(76665, 33873), -- Seer Malune, Cure of Aruunem
(76665, 33872), -- Seer Malune, Dust of the Dead
(76665, 33871), -- Seer Malune, Seek Out the Seer
(76665, 34721), -- Seer Malune, Seek Out the Seer
(76804, 37540), -- Lady Liadrin, Essence of the Iron Conqueror
(76804, 37551), -- Lady Liadrin, Essence of the Iron Conqueror
(76804, 37543), -- Lady Liadrin, Essence of the Iron Protector
(76804, 37547), -- Lady Liadrin, Essence of the Iron Protector
(76804, 37541), -- Lady Liadrin, Essence of the Iron Vanquisher
(76804, 37549), -- Lady Liadrin, Essence of the Iron Vanquisher
(76804, 35680), -- Lady Liadrin, Garrison Campaign: The Fall of Shattrath
(76804, 35684), -- Lady Liadrin, Reclaiming the City
(76804, 35687), -- Lady Liadrin, Socrethar's Demise
(76826, 33944), -- Caleb, And the Elekk Too?!
(76826, 33882), -- Caleb, Just Peachicky
(76826, 33884), -- Caleb, Sher'KHAAAAAAANNNN!
(77031, 33973), -- Ahm, Dying Wish
(77082, 34508), -- Restalaan, Restalaan, Captain of the Guard
(77082, 33976), -- Restalaan, The Final Piece
(77580, 34144), -- Lady Liadrin, Retribution for the Light
(77581, 35254), -- Exarch Maladaar, Retribution for the Light
(77582, 34157), -- Soulbinder Nyami, Into the Heart of Madness
(77629, 34164), -- Kor'thos Dawnfury, Book Burning
(77737, 34458), -- Soulbinder Tuulani, Powering the Defenses
(77737, 35249), -- Soulbinder Tuulani, Powering the Defenses
(77799, 34326), -- Restalaan, Changing the Tide
(77799, 34092), -- Restalaan, Desperate Measures
(77853, 34472), -- Image of Archmage Vargoth, Temporal Juxtaposition
(77853, 36027), -- Image of Archmage Vargoth, The Staff of Archmage Vargoth
(77869, 34240), -- Soulbinder Tuulani, Scheduled Pickup
(77869, 34242), -- Soulbinder Tuulani, Scheduled Pickup
(78028, 33967), -- Soulbinder Tuulani, Antivenin
(78028, 33971), -- Soulbinder Tuulani, Antivenin
(78082, 34234), -- Vindicator Kaluud, Payback
(78083, 34013), -- Defender Artaal, Never Forget
(78102, 33969), -- Vindicator Namuun, Vile Defilers
(78482, 33917), -- Vindicator Nobundo, Disrupting the Flow
(78513, 34415), -- Archmage Elandra, An'dure The Giant
(78513, 34403), -- Archmage Elandra, Arcane Essence
(78513, 34406), -- Archmage Elandra, Caught In The Chaos
(78515, 34414), -- Manduil Skycaller, An'dure The Giant
(78515, 34401), -- Manduil Skycaller, Arcane Essence
(78515, 34404), -- Manduil Skycaller, Crystals of Unusual Power
(78519, 33920), -- Soulbinder Nyami, The Heart of Auchindoun
(78534, 34709), -- Ageilaa, Every Bit Counts
(78534, 34710), -- Ageilaa, Every Bit Counts
(78534, 34400), -- Ageilaa, Frenzied Manafeeders
(79133, 34558), -- Foreman Eksos, At Your Command
(79133, 34676), -- Foreman Eksos, The Critical Path
(79133, 37183), -- Foreman Eksos, The Critical Path
(79159, 34563), -- Apprentice Miall, The Quarry Quandary
(79176, 34566), -- Foreman Grobash, At Your Command
(79176, 34681), -- Foreman Grobash, It's a Matter of Strategy
(79176, 36953), -- Foreman Grobash, It's a Matter of Strategy
(79210, 34569), -- Morketh Bladehowl, The Quarry Quandary
(79329, 34624), -- Miall, Gas Guzzlers
(79329, 35045), -- Miall, In Ared's Memory
(79329, 34573), -- Miall, Iridium Recovery
(79329, 34571), -- Miall, Out of Jovite
(79356, 34579), -- Morketh Bladehowl, Gas Guzzlers
(79356, 34576), -- Morketh Bladehowl, Iridium Recovery
(79356, 34577), -- Morketh Bladehowl, Out of Jovite
(79356, 35102), -- Morketh Bladehowl, Unleashed Steel
(79392, 34815), -- Magister Serena, Making Acquaintances
(79393, 34814), -- Magister Krelas, Making Acquaintances
(79434, 34154), -- Soulbinder Tuulani, Destination: Unknown
(79434, 34564), -- Soulbinder Tuulani, Destination: Unknown
(79434, 36512), -- Soulbinder Tuulani, Together We Are Strong
(79612, 34706), -- Knight-Lord Dranarus, Come Together
(79618, 34707), -- Vindicator Icia, Come Together
(79853, 35238), -- Pleasure-Bot 8000, New Owner
(79853, 35239), -- Pleasure-Bot 8000, New Owner
(79870, 34751), -- Ziz Fizziks, Clear!
(79901, 34761), -- Torben Zapblast, Clear!
(79921, 34766), -- Provisioner Naya, Logistical Nightmare
(79921, 34803), -- Provisioner Naya, Send Them Running
(79963, 34804), -- Quartermaster O'Riley, Not In Your House
(79963, 34773), -- Quartermaster O'Riley, Why Is The Brew Gone?
(79978, 34776), -- Aeda Brightdawn, Gatekeepers of Auchindoun
(79978, 36518), -- Aeda Brightdawn, The True Path
(79979, 34777), -- Defender Illona, Gatekeepers of Auchindoun
(79979, 36519), -- Defender Illona, The True Path
(80028, 34801), -- Nadur, A Pilgrimage Gone Awry
(80028, 34802), -- Nadur, A Pilgrimage Gone Awry
(80142, 34631), -- Archmage Khadgar, An Audience With The Archmage
(80142, 34632), -- Archmage Khadgar, An Audience With The Archmage
(80229, 34837), -- Morketh Bladehowl, Going to the Gordunni
(80339, 34840), -- Morketh Bladehowl, Dropping Bombs
(80342, 34870), -- Morketh Bladehowl, The Lord of the Gordunni
(80390, 34879), -- Magister Krelas, Dropping In
(80396, 34878), -- Magister Krelas, The Foot of the Fortress
(80553, 34712), -- Magister Krelas, Due Cause to Celebrate
(80553, 34949), -- Magister Krelas, Joining the Ranks
(80607, 34908), -- Magister Serena, The Foot of the Fortress
(80608, 34913), -- Magister Serena, Dropping In
(80623, 34972), -- Morketh Bladehowl, Armor Up
(80623, 34971), -- Morketh Bladehowl, The Only Way to Travel
(80627, 34578), -- Miall, Going to the Gordunni
(80628, 34976), -- Miall, Dropping Bombs
(80630, 34980), -- Miall, The Lord of the Gordunni
(80672, 34711), -- Magister Serena, Due Cause to Celebrate
(80672, 34993), -- Magister Serena, Joining the Ranks
(80833, 34107), -- Beastmaster Tagh, Wanted: Hilaani
(80833, 34108), -- Beastmaster Tagh, Wanted: Kil'uun
(80833, 34106), -- Beastmaster Tagh, Wanted: Ra'tok the Hammer
(80854, 34104), -- Patrick Messer, Wanted: Hilaani
(80854, 34103), -- Patrick Messer, Wanted: Kil'uun
(80854, 34105), -- Patrick Messer, Wanted: Ra'tok the Hammer
(80965, 34874), -- Magister Krelas, Next Steps
(80966, 34875), -- Magister Serena, Next Steps
(80968, 34982), -- Miall, Armor Up
(80968, 34981), -- Miall, The Only Way to Travel
(83823, 36014), -- Archmage Khadgar, Blackhand's Secret
(83823, 37836), -- Archmage Khadgar, Breaking Badness
(83823, 35988), -- Archmage Khadgar, Call of the Archmage
(83823, 39019), -- Archmage Khadgar, Call of the Archmage
(83823, 35990), -- Archmage Khadgar, Core of Flame
(83823, 35991), -- Archmage Khadgar, Core of Iron
(83823, 35992), -- Archmage Khadgar, Core of Life
(83823, 36158), -- Archmage Khadgar, Draenor's Secret Power
(83823, 35997), -- Archmage Khadgar, Empire's Fall
(83823, 35994), -- Archmage Khadgar, Eyes of the Archmage
(83823, 36010), -- Archmage Khadgar, Flamebender's Tome
(83823, 36009), -- Archmage Khadgar, Heart of the Fury
(83823, 35989), -- Archmage Khadgar, Khadgar's Task
(83823, 35998), -- Archmage Khadgar, Legacy of the Sorcerer Kings
(83823, 36013), -- Archmage Khadgar, Might of the Elemental Lords
(83823, 37834), -- Archmage Khadgar, Orb of Dominion
(83823, 36004), -- Archmage Khadgar, Power Unleashed
(83823, 36017), -- Archmage Khadgar, Prisoner of the Mind
(83823, 36012), -- Archmage Khadgar, Reverse Piracy
(83823, 36157), -- Archmage Khadgar, Spires of the Betrayer
(83823, 35993), -- Archmage Khadgar, Tackling Teron'gor
(83823, 37835), -- Archmage Khadgar, The Shadow War
(83823, 36016), -- Archmage Khadgar, The Unbroken Circle
(83823, 36007), -- Archmage Khadgar, Touch of the Kirin-Tor
(83823, 36018), -- Archmage Khadgar, We're Not Finished...
(83929, 36006), -- Cordana Felsong, Hunter: Hunted
(83929, 36005), -- Cordana Felsong, The Scrying Game
(86949, 34464), -- Zooti Fizzlefury, Mysterious Boots
(86949, 34465), -- Zooti Fizzlefury, Mysterious Hat
(86949, 34463), -- Zooti Fizzlefury, Mysterious Ring
(86949, 34466), -- Zooti Fizzlefury, Mysterious Staff
(87125, 37208), -- Taralune, Taralune
(90233, 37837), -- Archmage Khadgar, An Inside Job
(90233, 37964), -- Archmage Khadgar, To Gul'dan!
(90237, 37838), -- Garona Halforcen, My Garona
(91750, 38415), -- Lady Liadrin, Garrison Campaign: Onslaught at Auchindoun
(91750, 38416), -- Lady Liadrin, Secrets of the Sargerei
(91751, 38421), -- Exarch Yrel, Garrison Campaign: Onslaught at Auchindoun
(91751, 38562); -- Exarch Yrel, Secrets of the Sargerei
