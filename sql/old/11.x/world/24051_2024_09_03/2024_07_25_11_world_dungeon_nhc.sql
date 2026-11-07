-- 
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (185259,174212,171038,170997,169929,167617,167114,166895,165564,165535,165525,165406,164910,164130,163471,163087,163061,162050,162045,145806,144311,141303,141072,140912,140902,140837,140615,139834,139371,139314,139304,139284,137086,136520,136387,136380,135456,135444,135398,135353,135050,135029,134986,134985,134602,134598,134518,134405,134400,134399,134391,134388,133927,131140,131009,130738,129878,129566,128819,128817,116652,113771,113538,112742,112502,111361,111196,111066,111057,111052,111021,109908,109550,108460,103831,103597,103271,103199,103194,102734,102637,102568,102482,102481,101857,101841,101739,101660,101652,101642,101641,101416,100857,100818,100528,100393,99957,99728,99725,99704,99676,99675,99645,99644,99363,99362,99356,99354,98940,98776,98187,97849,97674,97576,96581,96580,96579,96128,96127,96105,95877,95876,94912,92440,92351,90999,86554,86552,86547,85025,84987,84986,84554,84552,84550,84387,76559,67093,65337,65111,63560,63106,62795,62633,62632,62348,62205,61929,61928,61910,61701,61699,61670,61634,61623,61567,61485,61484,61448,61436,61434,61177,60447,59835,59801,59800,59794,59778,59210,59208,59207,59206,59205,58764,58495,58108,56930,56929,56920,56919,56918,56917,56912,56911,56897,56896,56895,56889,56877,56636,56589,45279,24675,24674));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(185259, 1, 6, 30, 1, 209401, 1075839048, 0), -- Arcane Bomb
(174212, 1, 8, 40, 1, 195975, 2097224, 128), -- Azoras
(171038, 1, 8, 8, 1, 192420, 32, 4194304), -- Jenny Chu
(170997, 1, 8, 2, 1, 192357, 1610612752, 6), -- Soul Crystal
(169929, 1, 8, 8, 1, 191131, 2097224, 0), -- Chamber Sentinel
(167617, 1, 8, 5, 1, 190391, 2097224, 0), -- Depraved Shaper
(167114, 1, 8, 5, 1, 191534, 2097224, 128), -- Enlightened Spinemaw Gorger
(166895, 1, 8, 3, 1, 190416, 2097224, 0), -- Animated Dreadbat
(165564, 1, 8, 1, 1, 186123, 16778240, 16), -- Shadow Rupture
(165535, 1, 8, 1, 1, 186091, 0, 0), -- Bombing Run Stalker
(165525, 1, 8, 150, 1, 186078, 0, 128), -- Myskia
(165406, 1, 8, 1, 1, 185954, 0, 0), -- Growing Mistrust
(164910, 1, 8, 2, 1, 185421, 2097224, 0), -- Unburdened Manifestation
(164130, 1, 8, 1, 1, 184756, 16778240, 144), -- Soulless Shell
(163471, 1, 8, 8, 1, 189962, 2097224, 0), -- Dark Dreadnought
(163087, 1, 8, 5, 1, 191768, 2097256, 0), -- Client Scene Zombie
(163061, 1, 8, 1, 1, 189922, 2097224, 128), -- Janari
(162050, 1, 8, 0.5, 1, 182150, 2097224, 0), -- Released Manifestation
(162045, 1, 8, 5, 1, 182133, 2097224, 0), -- Ravenous Dreadbat
(145806, 1, 7, 31655.587890625, 1, 158750, 536870928, 6), -- 7th Legion Airship
(144311, 1, 7, 5, 1, 157010, 2097224, 0), -- Orb Guardian
(141303, 1, 7, 39, 1, 148328, 0, 0), -- B.O.O.M.B.A.
(141072, 1, 7, 1, 1, 154404, 0, 0), -- Big Bomb
(140912, 1, 7, 25, 1, 147911, 0, 0), -- Rally Bigbombs
(140902, 1, 7, 25, 1, 147898, 0, 0), -- Vog'rish, the Ascended
(140837, 1, 7, 4, 1, 147830, 0, 0), -- Enslaved Rockfury
(140615, 1, 7, 25, 1, 147584, 0, 0), -- Butchie
(139834, 1, 7, 28, 1, 146688, 2097224, 128), -- Merektha
(139371, 1, 7, 8, 1, 146179, 270532680, 0), -- Charged Spire
(139314, 1, 7, 1, 1, 146116, 2097224, 0), -- Prince
(139304, 1, 7, 8, 1, 146103, 2097352, 0), -- Solid Snake
(139284, 1, 7, 3, 1, 146080, 2097224, 128), -- Plague Doctor
(137086, 1, 7, 5, 1, 143532, 270532680, 0), -- Static Charge
(136520, 1, 7, 6, 1, 142835, 2097224, 0), -- Bilge Rat Party Animal
(136387, 1, 7, 2, 1, 142690, 2097224, 128), -- Electrified Wyrm
(136380, 1, 9, 35, 1, 142680, 72, 0), -- Rezan
(135456, 1, 7, 100, 1, 141684, 1344274504, 0), -- Chaotic Spark
(135444, 1, 7, 0.5, 1, 143147, 0, 0), -- Cyclone Totem
(135398, 1, 7, 5, 1, 141974, 270532680, 0), -- Charged Spark
(135353, 1, 7, 8, 1, 142052, 0, 0), -- Veteran Man O' War
(135050, 1, 7, 8, 1, 149138, 270532712, 0), -- Dread Captain Vandegrim
(135029, 1, 7, 4, 1, 141153, 0, 0), -- A Knot of Snakes
(134986, 1, 7, 8, 1, 143144, 0, 0), -- Greater Air Elemental
(134985, 1, 7, 4, 1, 143104, 0, 0), -- Dervish
(134602, 1, 7, 4, 1, 143107, 2097224, 0), -- Shrouded Fang
(134598, 1, 7, 5, 1, 143129, 270532680, 0), -- Warrior
(134518, 1, 7, 4, 1, 140625, 0, 0), -- Egg
(134405, 1, 7, 4, 1, 140507, 0, 0), -- Snake
(134400, 1, 7, 4, 1, 140510, 0, 0), -- Snake
(134399, 1, 7, 4, 1, 140513, 0, 0), -- Snake
(134391, 1, 7, 4, 1, 140516, 0, 128), -- Conductive Coiler
(134388, 1, 7, 1, 1, 140525, 0, 0), -- A Knot of Snakes
(133927, 1, 7, 5, 1, 144536, 0, 0), -- Grotesque Experiment
(131140, 1, 7, 2, 1, 136988, 0, 0), -- Fatal Corruption
(131009, 1, 7, 2.660000085830688476, 1, 136957, 2097224, 128), -- Spirit of Gold
(130738, 1, 7, 2, 1, 155494, 1075839048, 0), -- Corrupted Gold
(129878, 1, 7, 3, 1, 135478, 2097224, 128), -- Reanimated Raptor
(129566, 1, 7, 3, 1, 135138, 2097224, 0), -- Reanimated Raptor
(128819, 1, 7, 3, 1, 134801, 2097224, 128), -- Ancient Dry Bones
(128817, 1, 7, 3, 1, 134800, 2097224, 128), -- Ancient Dry Bones
(116652, 1, 6, 5, 1, 120408, 2097224, 0), -- Treasure Goblin
(113771, 1, 6, 3, 1, 117032, 2097224, 0), -- Stone Warden
(113538, 1, 6, 5, 1, 116757, 2097224, 0), -- Mightstone Breaker
(112742, 1, 6, 0.300000011920928955, 1, 116851, 8, 0), -- Broodling
(112502, 1, 6, 5, 1, 115214, 2097224, 0), -- Blightfang Screecher
(111361, 1, 6, 30, 1, 117919, 2097224, 0), -- Kelorn Nightblade
(111196, 1, 6, 0.275000005960464477, 1, 113361, 2097224, 0), -- Plagued Rat
(111066, 1, 6, 0.550000011920928955, 1, 113229, 2097224, 0), -- Sludge
(111057, 1, 6, 9.900000572204589843, 1, 113231, 2099304, 0), -- The Rat King
(111052, 1, 6, 9.900000572204589843, 1, 113232, 2097224, 0), -- Silver Serpent
(111021, 1, 6, 9.900000572204589843, 1, 113233, 2097224, 16), -- Sludge Face
(109908, 1, 6, 0.100000001490116119, 1, 112032, 0, 0), -- Nightmare Abomination
(109550, 1, 6, 10, 1, 116887, 2097224, 0), -- Dark Hunter
(108460, 1, 6, 5, 1, 110291, 2097224, 0), -- Injured Preserver Druid
(103831, 1, 6, 5, 1, 104893, 2097224, 128), -- Rockbound Pelter
(103597, 1, 6, 5, 1, 117957, 2097224, 0), -- Understone Lasher
(103271, 1, 6, 18, 0.000375158997485414, 117925, 2097224, 0), -- Kraxa
(103199, 1, 6, 18, 0.000375158997485414, 117913, 2097224, 0), -- Ragoul
(103194, 1, 6, 0.75, 7, 115817, 1088, 0), -- Inquisitor's Eye
(102734, 1, 9, 2, 1, 194932, 0, 128), -- T.L. Bret
(102637, 1, 6, 35, 1, 109799, 2097224, 128), -- Tirathon Saltheril
(102568, 1, 6, 8, 1, 109762, 8, 0), -- Grimhorn the Enslaver
(102482, 1, 6, 35, 1, 116869, 2097224, 128), -- Faceless Monstrosity
(102481, 1, 6, 32, 1, 116866, 2097224, 128), -- Crypt Lord
(101857, 1, 6, 5, 1, 104456, 2097224, 0), -- Dreadsoul Grovetender
(101841, 1, 6, 3, 1, 104454, 2097224, 0), -- Image of Mythana
(101739, 1, 6, 1, 1, 104452, 0, 0), -- Spider Form
(101660, 1, 6, 20, 1, 104448, 2097480, 0), -- Rage Rot
(101652, 1, 6, 5, 1, 104663, 2097224, 0), -- Colossal Charskin
(101642, 1, 6, 1, 1, 104446, 0, 0), -- Mythana's Tentacle
(101641, 1, 6, 17, 1, 104444, 2097224, 0), -- Mythana
(101416, 1, 6, 8, 1, 109768, 8, 0), -- Dreadlord Dolus
(100857, 1, 6, 5, 1, 109771, 72, 0), -- Blackguard
(100818, 1, 6, 3.20000004768371582, 1, 104657, 120, 128), -- Bellowing Idol
(100528, 1, 6, 0.5, 1, 106409, 2097224, 0), -- Hatespawn Whelpling
(100393, 1, 6, 0.288749992847442626, 1, 112949, 2097224, 128), -- Dread Felbat
(99957, 1, 6, 5, 1, 109780, 2097224, 0), -- Fel-Infused Fury
(99728, 1, 6, 3.846149921417236328, 1, 109786, 8, 0), -- Grimguard
(99725, 1, 6, 2.307689905166625976, 1, 109894, 8, 0), -- Mistress of Misery
(99704, 1, 6, 2.849999904632568359, 173.764007568359375, 110806, 0, 128), -- Shadowmoon Warlock
(99676, 1, 6, 3, 173.764007568359375, 109738, 2097224, 128), -- Mogu'shan Secret-Keeper
(99675, 1, 6, 4, 1, 109741, 66121, 128), -- Enormous Stone Quilen
(99645, 1, 6, 2.849999904632568359, 1, 109756, 0, 128), -- Shadowmoon Technician
(99644, 1, 6, 3.299999952316284179, 1, 109759, 0, 128), -- Felguard Annihilator
(99363, 1, 6, 0.5, 1, 106401, 2097224, 0), -- Vilethorn Sapling
(99362, 1, 6, 24, 1, 106399, 2097480, 0), -- Kudzilla
(99356, 1, 6, 4.5, 1, 104440, 2097480, 0), -- Vilethorn Rooter
(99354, 1, 6, 10, 1, 106395, 2097224, 0), -- Cinderbark Ancient
(98940, 1, 6, 5, 1, 109729, 2097224, 0), -- Shadow Hunter
(98776, 1, 6, 0.275000005960464477, 1, 108539, 2097224, 0), -- Felswarm Imp
(98187, 1, 6, 13, 1, 109648, 2097224, 0), -- Glayvianna Soulrender
(97849, 1, 6, 5, 1, 109705, 2097224, 0), -- Shadowy Seductress
(97674, 1, 6, 5, 1, 109714, 2097224, 0), -- Brood Mother
(97576, 1, 6, 35, 1, 109717, 2097224, 128), -- Tirathon Saltheril
(96581, 1, 6, 8, 1, 109680, 2097224, 0), -- Primordial Dragon
(96580, 1, 6, 8, 1, 109683, 2097224, 0), -- Albrecht "Full Metal" Finklestein
(96579, 1, 6, 10, 1, 116884, 2097224, 0), -- Frenzied Animus
(96128, 1, 6, 1.538460016250610351, 1, 109692, 2097224, 128), -- Viletongue Devourer
(96127, 1, 6, 5, 1, 109695, 2097224, 128), -- Felsworn Screecher
(96105, 1, 6, 5, 1, 109649, 2097224, 0), -- Elite Satyr
(95877, 1, 6, 8, 1, 109665, 2097224, 0), -- Dreadlord
(95876, 1, 6, 5, 1, 109668, 2097224, 0), -- Satyr
(94912, 1, 6, 3, 1, 107186, 2097224, 128), -- Rotdrool Grabber
(92440, 1, 6, 5, 1, 104615, 2097224, 0), -- Understone Drudge
(92351, 1, 6, 5, 1, 104613, 2097224, 0), -- Understone Drummer
(90999, 1, 6, 8, 1, 104597, 2097736, 0), -- Crystal Giant
(86554, 1, 5, 6, 1, 85125, 2097224, 128), -- Venom-Crazed Pale Hulk
(86552, 1, 5, 0.699999988079071044, 1, 85120, 2097224, 128), -- Gorged Burster
(86547, 1, 5, 1, 1, 85117, 2097224, 128), -- Venom Sprayer
(85025, 1, 5, 3, 1, 84789, 2097224, 0), -- Spore Image
(84987, 1, 5, 3, 1, 84771, 2097224, 0), -- Spore Image
(84986, 1, 5, 3, 1, 84774, 2097224, 0), -- Spore Image
(84554, 1, 5, 3, 1, 84811, 2097224, 128), -- Venom-Crazed Pale One
(84552, 1, 5, 2, 1, 84814, 2097224, 128), -- Toxic Spiderling
(84550, 1, 5, 25, 1, 84817, 2097224, 128), -- Xeri'tac
(84387, 1, 5, 35, 1, 84762, 2097224, 128), -- Spore Image
(76559, 1, 5, 6.5, 1, 88165, 2129992, 0), -- Solar Reflector
(67093, 1, 4, 2.5, 1, 65456, 2097224, 0), -- Sik'thik Battle-Mender
(65337, 1, 4, 5, 1, 65492, 0, 0), -- Serpent's Spine Defender
(65111, 1, 4, 4, 1, 65490, 0, 0), -- Serpent's Spine Defender
(63560, 1, 4, 3, 1, 65502, 0, 0), -- Krik'thik Infiltrator
(63106, 1, 4, 3, 1, 65460, 0, 0), -- Sik'thik Swarmer
(62795, 1, 4, 3.5, 1, 65461, 0, 0), -- Sik'thik Warden
(62633, 1, 4, 2, 1, 65451, 2097224, 0), -- Sik'thik Builder
(62632, 1, 4, 3.5, 1, 65450, 2097224, 0), -- Sik'thik Engineer
(62348, 1, 4, 0.400000005960464477, 1, 65454, 2097224, 0), -- Sik'thik Soldier
(62205, 1, 4, 25, 1, 65452, 2147483752, 128), -- Wing Leader Ner'onok
(61929, 1, 4, 2.5, 1, 65468, 2097256, 0), -- Sik'thik Amber-Weaver
(61928, 1, 4, 2.5, 1, 65467, 2097256, 0), -- Sik'thik Guardian
(61910, 1, 4, 1, 1, 65466, 2097256, 0), -- Resin Flake
(61701, 1, 4, 12, 1, 65464, 0, 0), -- Sik'thik Warrior
(61699, 1, 4, 10, 1, 65462, 0, 0), -- Sik'thik Amberwing
(61670, 1, 4, 2.5, 1, 65463, 0, 0), -- Sik'thik Demolisher
(61634, 1, 4, 25, 1, 65465, 2097224, 128), -- Commander Vo'jak
(61623, 1, 4, 0.150000005960464477, 1, 65469, 2097256, 0), -- Sap Globule
(61567, 1, 4, 25, 6, 65470, 2097256, 128), -- Vizier Jin'bak
(61485, 1, 4, 55, 1, 65458, 270532680, 128), -- General Pa'valak
(61484, 1, 4, 0.050000000745058059, 1, 65457, 2097224, 128), -- Sik'thik Amber-Sapper
(61448, 1, 4, 0.400000005960464477, 1, 65459, 2097224, 128), -- Sik'thik Soldier
(61436, 1, 4, 3.5, 1, 65455, 2097224, 0), -- Sik'thik Bladedancer
(61434, 1, 4, 3.5, 1, 65453, 2097224, 0), -- Sik'thik Vanguard
(61177, 1, 4, 42, 1, 65472, 65609, 0), -- Raigonn
(60447, 1, 4, 8, 1, 65482, 0, 0), -- Krik'thik Saboteur
(59835, 1, 4, 0.25, 1, 65479, 0, 0), -- Krik'thik Swarmer
(59801, 1, 4, 2.5, 1, 65485, 0, 0), -- Krik'thik Wind Shaper
(59800, 1, 4, 2.5, 1, 65484, 0, 0), -- Krik'thik Rager
(59794, 1, 4, 2.5, 1, 65486, 0, 0), -- Krik'thik Disruptor
(59778, 1, 4, 2.5, 1, 65487, 0, 0), -- Krik'thik Striker
(59210, 1, 4, 8, 1, 65488, 0, 0), -- Volatile Munitions
(59208, 1, 4, 1, 1, 65495, 0, 0), -- Mantid Munitions
(59207, 1, 4, 1, 1, 65501, 0, 0), -- Mantid Munitions
(59206, 1, 4, 1, 1, 65497, 0, 0), -- Mantid Munitions
(59205, 1, 4, 1, 1, 65499, 0, 0), -- Mantid Munitions
(58764, 1, 4, 0.100000001490116119, 1, 65475, 1024, 0), -- Screeching Swarm
(58495, 1, 9, 10.14999961853027343, 1, 117539, 0, 0), -- ScottG Test
(58108, 1, 4, 2.5, 1, 65483, 0, 0), -- Krik'thik Infiltrator
(56930, 1, 4, 2.5, 1, 65478, 72, 0), -- Krik'thik Swarm Bringer
(56929, 1, 4, 0.400000005960464477, 1, 65476, 72, 0), -- Krik'thik Protectorate
(56920, 1, 4, 1, 1, 65494, 0, 0), -- Mantid Munitions
(56919, 1, 4, 1, 1, 65500, 0, 0), -- Mantid Munitions
(56918, 1, 4, 1, 1, 65496, 0, 0), -- Mantid Munitions
(56917, 1, 4, 8, 1, 65493, 0, 0), -- Stable Munitions
(56912, 1, 4, 0.200000002980232238, 1, 65477, 72, 0), -- Krik'thik Engulfer
(56911, 1, 4, 1, 1, 65498, 0, 0), -- Mantid Munitions
(56897, 1, 4, 32, 1, 65473, 65609, 0), -- Raigonn
(56896, 1, 4, 8, 1, 65489, 0, 0), -- Volatile Munitions
(56895, 1, 4, 6.5, 1, 65471, 72, 0), -- Weak Spot
(56889, 1, 4, 4, 1, 65491, 0, 0), -- Serpent's Spine Defender
(56877, 1, 4, 42, 1, 65474, 2147549257, 128), -- Raigonn
(56636, 1, 4, 23, 20, 65503, 2097224, 128), -- Commander Ri'mok
(56589, 1, 4, 25, 1, 65504, 2097224, 128), -- Striker Ga'dok
(45279, 1, 3, 0.200000002980232238, 7, 65445, 72, 0), -- Storm Surge
(24675, 1, 1, 2.5, 1, 194861, 64, 0), -- Phoenix Egg
(24674, 1, 1, 12.5, 1, 194858, 72, 0); -- Phoenix

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=230345 AND `DifficultyID`=0); -- [DNT] Smoke Screen Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=220592 AND `DifficultyID`=0); -- 5.0 Scenario - Invisible Stalker - Large AOI
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=214209 AND `DifficultyID`=0) OR (`Entry`=40634 AND `DifficultyID`=1); -- Naz'jar Tempest Witch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=214140 AND `DifficultyID`=0) OR (`Entry`=40577 AND `DifficultyID`=1); -- Naz'jar Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=214117 AND `DifficultyID`=0); -- Stormflurry Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=214100 AND `DifficultyID`=0); -- Drowned Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=213942 AND `DifficultyID`=0); -- Sludge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=213806 AND `DifficultyID`=0); -- Splotch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=213770 AND `DifficultyID`=0); -- Ink of Ozumat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (213689,85024,85023,85022,85021,85020,85019,85018)) OR (`DifficultyID`=1 AND `Entry` IN (84985,84984,84983,84386)); -- Spore Image
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=213607 AND `DifficultyID`=0); -- Deep Sea Murloc
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=213219 AND `DifficultyID`=0); -- Bubbling Ooze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=212981 AND `DifficultyID`=0); -- Hapless Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212792 AND `DifficultyID`=0); -- Abyssal Strike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212778 AND `DifficultyID`=0); -- Minion of Ghur'sha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212775 AND `DifficultyID`=0); -- Faceless Seer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212691 AND `DifficultyID`=0); -- Electrified Behemoth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212681 AND `DifficultyID`=0); -- Vicious Snap Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212675 AND `DifficultyID`=0) OR (`Entry`=40633 AND `DifficultyID`=1); -- Naz'jar Honor Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=212673 AND `DifficultyID`=0); -- Naz'jar Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=212483 AND `DifficultyID`=0); -- Gnarled Roots
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (209892,199000)); -- Chrono-Lord Deios
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (209717,206422,204836,204535,204401,200313)) OR (`DifficultyID`=1 AND `Entry` IN (194737,194736)); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209396 AND `DifficultyID`=0); -- [DNT] Black Hole
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209376 AND `DifficultyID`=0); -- Succulent Young
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209373 AND `DifficultyID`=0); -- [DNT] Hatchling Spawner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209369 AND `DifficultyID`=0); -- The Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209349 AND `DifficultyID`=0); -- Anomaly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209251 AND `DifficultyID`=0); -- Dimension Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209222 AND `DifficultyID`=0); -- Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209221 AND `DifficultyID`=0); -- Light Lich
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209215 AND `DifficultyID`=0); -- Light Knight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (209208,203679)); -- Anduin Lothar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (209207,203678)); -- Grommash Hellscream
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209170 AND `DifficultyID`=0); -- Loose Time
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209166 AND `DifficultyID`=0); -- Bronze Initiate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209165 AND `DifficultyID`=0); -- Bronze Acolyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=209038 AND `DifficultyID`=0); -- Time-Lost Artifact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208994 AND `DifficultyID`=0) OR (`Entry`=189363 AND `DifficultyID`=1); -- Infected Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208945 AND `DifficultyID`=0); -- Dwarven Bomber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208698 AND `DifficultyID`=0); -- Infinite Riftmage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208440 AND `DifficultyID`=0); -- Infinite Slayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (208439,207942,205747,205135,204449,204390)); -- Chromie
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208438 AND `DifficultyID`=0); -- Infinite Saboteur
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208348 AND `DifficultyID`=0); -- Lost Slime
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (208273,208250)); -- Infused Hourglass
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208208 AND `DifficultyID`=0); -- Alliance Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208207 AND `DifficultyID`=0); -- Alliance Destroyer Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208193 AND `DifficultyID`=0); -- Paladin of the Silver Hand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208191 AND `DifficultyID`=0); -- Infinite Militant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208190 AND `DifficultyID`=0); -- Infinite Stalwart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208189 AND `DifficultyID`=0); -- Infinite Scaleconjuror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (208188,203696)); -- Slime
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208165 AND `DifficultyID`=0); -- Alliance Knight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208061 AND `DifficultyID`=0); -- Temporal Rift
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=208060 AND `DifficultyID`=0); -- Infinite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207969 AND `DifficultyID`=0); -- Horde Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207859 AND `DifficultyID`=0); -- [DNT] Cosmetic Portal Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207670 AND `DifficultyID`=0); -- Time-Lost Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207669 AND `DifficultyID`=0); -- Time-Lost Infinite Executioner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207668 AND `DifficultyID`=0); -- Time-Lost Infinite Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207667 AND `DifficultyID`=0); -- Time-Lost Infinite Chronomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207666 AND `DifficultyID`=0); -- Time-Lost Infinite Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (207639,207638,204751,198997)); -- Blight of Galakrond
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207600 AND `DifficultyID`=0); -- Time-Lost Rift Lord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=207177 AND `DifficultyID`=0); -- Infinite Watchkeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (207133,206238,198996)); -- Manifested Timeways
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206976 AND `DifficultyID`=0); -- Timeless Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206352 AND `DifficultyID`=0); -- Alliance Archer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206351 AND `DifficultyID`=0); -- Alliance Conjuror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206230 AND `DifficultyID`=0); -- Infinite Diversionist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206214 AND `DifficultyID`=0); -- Infinite Infiltrator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206195 AND `DifficultyID`=0); -- Tyr's Throne of Time
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206140 AND `DifficultyID`=0); -- Coalesced Time
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206074 AND `DifficultyID`=0); -- Pendule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206070 AND `DifficultyID`=0); -- Chronaxie
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206068 AND `DifficultyID`=0); -- Temporal Fusion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206066 AND `DifficultyID`=0); -- Timestream Leech
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206065 AND `DifficultyID`=0); -- Interval
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206064 AND `DifficultyID`=0); -- Coalesced Moment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=206063 AND `DifficultyID`=0); -- Temporal Deviation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205819 AND `DifficultyID`=0); -- Slime Blaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205804 AND `DifficultyID`=0); -- Risen Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205790 AND `DifficultyID`=0); -- Time-Lost Smack-o-Tron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205788,199763)); -- Ysera
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205787,204392,204391,199754)); -- Nozdormu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205786,199756)); -- Neltharion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205785,199755)); -- Malygos
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205784 AND `DifficultyID`=0); -- Infinite Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=205744 AND `DifficultyID`=0); -- Declan Senal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=205743 AND `DifficultyID`=0); -- Jahden Fla
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=205741 AND `DifficultyID`=0); -- Rana the Cutta
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=205738 AND `DifficultyID`=0); -- Camilla Darksky
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205727 AND `DifficultyID`=0); -- Time-Lost Rocketeer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205723 AND `DifficultyID`=0); -- Time-Lost Aerobot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205697,205639)); -- Time Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205691,204918)); -- Iridikron's Creation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205655 AND `DifficultyID`=0); -- Pocket Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205459 AND `DifficultyID`=0); -- Time Fracture
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205435 AND `DifficultyID`=0); -- Epoch Ripper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205408 AND `DifficultyID`=0); -- Infinite Timeslicer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205384 AND `DifficultyID`=0); -- Infinite Chronoweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (205380,199753)); -- Alexstrasza
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205366 AND `DifficultyID`=0); -- Time-Lost Wakethrasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205365 AND `DifficultyID`=0); -- Time-Lost Tidehunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205363 AND `DifficultyID`=0); -- Time-Lost Waveshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205337 AND `DifficultyID`=0); -- Infinite Timebender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=205326 AND `DifficultyID`=0) OR (`Entry`=45477 AND `DifficultyID`=1); -- Gust Soldier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205265 AND `DifficultyID`=0); -- Time-Displaced Trooper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205259 AND `DifficultyID`=0); -- Infinite Warder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205216 AND `DifficultyID`=0); -- Infinite Commando
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205212 AND `DifficultyID`=0); -- Infinite Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205208 AND `DifficultyID`=0); -- Time Rift
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205158 AND `DifficultyID`=0); -- Spurlok, Timesworn Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205152 AND `DifficultyID`=0); -- Lerai, Timesworn Maiden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205151 AND `DifficultyID`=0); -- Tyr's Vanguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205128 AND `DifficultyID`=0); -- Essence of Galakrond
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=205126 AND `DifficultyID`=0); -- Essence Vessel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204658 AND `DifficultyID`=0); -- Infinite Protector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204653 AND `DifficultyID`=0); -- Infinite Gatekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (204536,204176)); -- Blight Chunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (204459,198933)); -- Iridikron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=204337 AND `DifficultyID`=0) OR (`Entry`=45704 AND `DifficultyID`=1); -- Lurking Tempest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204262 AND `DifficultyID`=0); -- Necrofrost
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204218 AND `DifficultyID`=0); -- Might of the Drogbar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204206 AND `DifficultyID`=0); -- Horde Farseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=204030 AND `DifficultyID`=0); -- Goblin Sapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203863 AND `DifficultyID`=0); -- Battlefield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203862 AND `DifficultyID`=0); -- Horde Destroyer Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203861 AND `DifficultyID`=0); -- Horde Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203857 AND `DifficultyID`=0); -- Horde Warlock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203799 AND `DifficultyID`=0); -- Horde Axe Thrower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203763 AND `DifficultyID`=0); -- Alliance Footman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203688 AND `DifficultyID`=0); -- Horde Grunt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=203446 AND `DifficultyID`=0); -- Time Traps
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (202789,198999)); -- Morchie
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=202685 AND `DifficultyID`=0); -- Corrupted Bronze Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (201903,201576)); -- Infinite Oathstone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201811 AND `DifficultyID`=0); -- Hourglass
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201805 AND `DifficultyID`=0); -- Sand Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201792 AND `DifficultyID`=0); -- Ahnzon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201790 AND `DifficultyID`=0); -- Loszkeleth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201788 AND `DifficultyID`=0); -- Dazhak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201756 AND `DifficultyID`=0); -- Familiar Face
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201223 AND `DifficultyID`=0); -- Infinite Twilight Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=201222 AND `DifficultyID`=0); -- Valow, Timesworn Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200948 AND `DifficultyID`=1); -- Nokhud Apprentice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200945 AND `DifficultyID`=1); -- Nokhud Warmonger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200944 AND `DifficultyID`=1); -- Nokhud Fighter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200942 AND `DifficultyID`=1); -- Bakar Companion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200941 AND `DifficultyID`=1); -- Teerai Conscript
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200940 AND `DifficultyID`=1); -- Teerai Watcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200821 AND `DifficultyID`=1); -- Teerai Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200796 AND `DifficultyID`=1); -- Domesticated Argali
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200786 AND `DifficultyID`=1); -- Caravan Wagon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200785 AND `DifficultyID`=1); -- Pack Musken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200761 AND `DifficultyID`=1); -- Wild Ohuna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=200443 AND `DifficultyID`=1); -- [DNT] Shattered Soul Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=200388 AND `DifficultyID`=1); -- Malformed Sha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228959 WHERE (`Entry`=200387 AND `DifficultyID`=1); -- Shambling Infester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (200382,188087)); -- Ruby Scaleguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (200380,190207)); -- Primalist Cinderweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (200379,190206)); -- Primalist Flamedancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228688 WHERE (`Entry`=200137 AND `DifficultyID`=1); -- Depraved Mistweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228679 WHERE (`Entry`=200131 AND `DifficultyID`=1); -- Sha-Touched Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228670 WHERE (`Entry`=200126 AND `DifficultyID`=1); -- Fallen Waterspeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (200035,76057)); -- Carrion Worm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199916,194330,192481,189299)); -- Decaying Slime
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199791,190485)); -- Erkhart Stormvein
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199790,193934,190484)) OR (`DifficultyID`=0 AND `Entry`=193435); -- Kyrakka
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199789,199788,194667,194654)); -- Radiant Drake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199749 AND `DifficultyID`=0); -- Timestream Anomaly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199748 AND `DifficultyID`=0); -- Timeline Marauder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199747 AND `DifficultyID`=0); -- Infinite Dragonspawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199719 AND `DifficultyID`=1); -- Nokhud Wardog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199718 AND `DifficultyID`=1); -- Nokhud Huntmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry`=199717) OR (`DifficultyID`=0 AND `Entry` IN (199595,193565)); -- Nokhud Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199716 AND `DifficultyID`=1); -- Nokhud Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199715 AND `DifficultyID`=1); -- Nokhud Battleguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199677 AND `DifficultyID`=1); -- Teleporter Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199619 AND `DifficultyID`=1); -- Baqir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199618 AND `DifficultyID`=1); -- Carseng
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199617 AND `DifficultyID`=1); -- Huraq
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199616 AND `DifficultyID`=1); -- Washengtu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199615 AND `DifficultyID`=1); -- Salukan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199614,186737)); -- Telash Greywing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry`=199610) OR (`DifficultyID`=1 AND `Entry` IN (196116,187160)); -- Crystal Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199594 AND `DifficultyID`=1); -- Shikaar Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199545,195434,195432,194715,194714,194713,194712,194618,194602)) OR (`DifficultyID`=0 AND `Entry`=197300); -- Book of Translocation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199498,192845)); -- Ohn'ir Windcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199496 AND `DifficultyID`=1); -- Fire Goal Throw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199495 AND `DifficultyID`=1); -- Wind Goal Throw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199368 AND `DifficultyID`=1); -- Hardened Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (199325,186808)) OR (`DifficultyID`=1 AND `Entry`=196484); -- Nokhud Stormcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (199322,196306,192848)); -- Shikaar Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (199321,199320,193467)) OR (`DifficultyID`=1 AND `Entry`=192791); -- Nokhud Warspear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199037 AND `DifficultyID`=1); -- Primalist Shocktrooper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=199001 AND `DifficultyID`=0); -- Time-Lost Battlefield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198998 AND `DifficultyID`=0); -- Tyr, the Infinite Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198995 AND `DifficultyID`=0); -- Chronikar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=198927 AND `DifficultyID`=1); -- Temporal Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198661 AND `DifficultyID`=0); -- Snowman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198610 AND `DifficultyID`=0); -- Nascent Ruby Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198599 AND `DifficultyID`=0); -- Seared Ruby Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198598 AND `DifficultyID`=0); -- Tempered Ruby Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198596 AND `DifficultyID`=0); -- Chilled Ruby Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198527 AND `DifficultyID`=1); -- Flow Control Unit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198445 AND `DifficultyID`=0); -- Reverse Polymorphic Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198422 AND `DifficultyID`=1); -- Tome of Transmogrification
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198267 AND `DifficultyID`=1); -- Taruk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198253 AND `DifficultyID`=1); -- Twister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198213 AND `DifficultyID`=1) OR (`Entry`=186173 AND `DifficultyID`=0); -- Vault Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198047 AND `DifficultyID`=1); -- Tempest Channeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198044 AND `DifficultyID`=1); -- Tainted War Axe of Berke
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198032 AND `DifficultyID`=1); -- Dragon's Eruption
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=198030 AND `DifficultyID`=1); -- Tainted Bow of Sartaq
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197985 AND `DifficultyID`=1); -- Flame Channeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197983 AND `DifficultyID`=1); -- Tainted Spear of Tolui
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197982 AND `DifficultyID`=1); -- Storm Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=197915 AND `DifficultyID`=1); -- Lindormi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197882 AND `DifficultyID`=1); -- Dracthyr Freshscale
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=3.5 WHERE (`Entry`=197857 AND `DifficultyID`=1); -- Gutstabber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197802 AND `DifficultyID`=1); -- Well-Fed Duckling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197782 AND `DifficultyID`=1); -- Intake Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197779 AND `DifficultyID`=1); -- Purge Intakes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197774 AND `DifficultyID`=0); -- Toxic Swogmother
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197717 AND `DifficultyID`=1); -- Nascent Ruby Egg
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=197711 AND `DifficultyID`=1); -- Lindormi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197709 AND `DifficultyID`=1); -- Draconic Tincture
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197698 AND `DifficultyID`=1); -- Thunderhead
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197697 AND `DifficultyID`=1); -- Flamegullet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197668 AND `DifficultyID`=0); -- Storm Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197654 AND `DifficultyID`=1); -- Infused Mushroom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197643 AND `DifficultyID`=1); -- Icy Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197560 AND `DifficultyID`=1); -- Limited Immortality Device
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197535 AND `DifficultyID`=1); -- High Channeler Ryvati
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197509 AND `DifficultyID`=1); -- Primal Thundercloud
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197407 AND `DifficultyID`=1); -- Vandalized Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197406 AND `DifficultyID`=1); -- Aggravated Skitterfly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197405 AND `DifficultyID`=1); -- Puzzle Box
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197404 AND `DifficultyID`=1); -- Gnawed Bone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197402 AND `DifficultyID`=1); -- Chewed Up Plush
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197401 AND `DifficultyID`=1); -- Squeaky Murloc
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197399 AND `DifficultyID`=0); -- Nourishing Leafling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (197398,196642)); -- Hungry Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197389 AND `DifficultyID`=1); -- Wild Hyena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197337 AND `DifficultyID`=1); -- Burning 3 Books
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (197335,196288,196267)); -- Bertinuat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (197334,196289,196268)); -- Sentiu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197333 AND `DifficultyID`=1); -- Burning 1 Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (197332,196290,196260)); -- Japukitat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197219 AND `DifficultyID`=1); -- Vile Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197204 AND `DifficultyID`=1); -- Vault Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197199 AND `DifficultyID`=1); -- Resilient Mushroom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197193 AND `DifficultyID`=1); -- Chief Softpaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=197150 AND `DifficultyID`=0); -- Floating Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (197081,188046,187482)); -- Sindragosa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196981 AND `DifficultyID`=1); -- Red Dragonflight Recruiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196979 AND `DifficultyID`=1); -- Green Dragonflight Recruiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196978 AND `DifficultyID`=1); -- Blue Dragonflight Recruiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196977 AND `DifficultyID`=1); -- Bronze Dragonflight Recruiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196974 AND `DifficultyID`=1); -- Black Dragonflight Recruiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196947 AND `DifficultyID`=1); -- Goal of the Rushing Winds
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196869 AND `DifficultyID`=1); -- Black Dragonflight Alumni
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196868 AND `DifficultyID`=1); -- Bronze Dragonflight Alumni
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196866 AND `DifficultyID`=1); -- Blue Dragonflight Alumni
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (196865,196864)); -- Red Dragonflight Alumni
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196823 AND `DifficultyID`=0) OR (`Entry`=190085 AND `DifficultyID`=1); -- Grounding Spear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (196798,196045)); -- Corrupted Manafiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196717 AND `DifficultyID`=1); -- Power Device
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196712 AND `DifficultyID`=1); -- Nullification Device
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196696 AND `DifficultyID`=0); -- Geode Chunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196694 AND `DifficultyID`=1); -- Arcane Forager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196693 AND `DifficultyID`=1); -- Shimmering Geode
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196671 AND `DifficultyID`=1); -- Arcane Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196664 AND `DifficultyID`=1); -- Arcane Rift Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196657 AND `DifficultyID`=1); -- Furious Storm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196645 AND `DifficultyID`=1); -- Desecrated Bakar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196644 AND `DifficultyID`=0); -- Raging Protodragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196597 AND `DifficultyID`=0); -- Great Ohuna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196577 AND `DifficultyID`=1); -- Spellbound Battleaxe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196576 AND `DifficultyID`=1); -- Spellbound Scepter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196559 AND `DifficultyID`=1); -- Volatile Sapling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196548 AND `DifficultyID`=1); -- Ancient Branch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196482 AND `DifficultyID`=1); -- Overgrown Ancient
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196463 AND `DifficultyID`=1); -- Pattern Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196441 AND `DifficultyID`=1); -- Cosmetic Taxi Path Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196374 AND `DifficultyID`=1); -- Condensed Decay
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196372 AND `DifficultyID`=1); -- [DNT] Orbiting Decay
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196263 AND `DifficultyID`=1); -- Nokhud Neophyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196229 AND `DifficultyID`=1); -- Ohn'ir Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196211 AND `DifficultyID`=1); -- Cosmetic Barrier Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196205 AND `DifficultyID`=1); -- Errant Pages
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196203 AND `DifficultyID`=1); -- Ethereal Restorer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196202 AND `DifficultyID`=1); -- Spectral Invoker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196200 AND `DifficultyID`=1); -- Algeth'ar Echoknight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196198 AND `DifficultyID`=0); -- Algeth'ar Security
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (196117,187139)); -- Crystal Thrasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (196115,191164)); -- Arcane Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196113 AND `DifficultyID`=1); -- Impact Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196102 AND `DifficultyID`=1); -- Conjured Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196044 AND `DifficultyID`=1); -- Unruly Textbook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196043 AND `DifficultyID`=1); -- Primalist Infuser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=196008 AND `DifficultyID`=1); -- Infused Globule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195949 AND `DifficultyID`=0); -- [DNT] Necro Ash Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195945 AND `DifficultyID`=1); -- [DNT] Brazier Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195942 AND `DifficultyID`=1); -- [DNT] Bonepile Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195933 AND `DifficultyID`=1); -- Gravelord Monkh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195932 AND `DifficultyID`=1); -- [DNT] Maruuk Weapon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195931 AND `DifficultyID`=1); -- [DNT] Teera Weapon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195930 AND `DifficultyID`=1); -- Soulharvester Mandakh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195929 AND `DifficultyID`=1); -- Soulharvester Tumen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195928 AND `DifficultyID`=1); -- Soulharvester Duuren
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195927 AND `DifficultyID`=1); -- Soulharvester Galtmaa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195919 AND `DifficultyID`=1); -- Burning Chain Caster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195902 AND `DifficultyID`=1); -- [DNT] Spear Weapon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=10 WHERE (`Entry`=195878 AND `DifficultyID`=1); -- Ukhel Beastcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195877 AND `DifficultyID`=1); -- Risen Mystic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195876 AND `DifficultyID`=1); -- Desecrated Ohuna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=1.25 WHERE (`Entry`=195875 AND `DifficultyID`=1); -- Desecrated Bakar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195855 AND `DifficultyID`=1); -- Risen Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195851 AND `DifficultyID`=1); -- Ukhel Deathspeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195847 AND `DifficultyID`=0); -- Ukhel Willcrusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195842 AND `DifficultyID`=1); -- Ukhel Corruptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195821,195820,195580)); -- Nokhud Saboteur
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195810 AND `DifficultyID`=0); -- Ascendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195799,195798,195797)); -- Shikaar Lancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195697 AND `DifficultyID`=1); -- Thunderbeast Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195696 AND `DifficultyID`=1); -- Primalist Thunderbeast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195638 AND `DifficultyID`=1); -- Polymorphic Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195587 AND `DifficultyID`=1); -- Headteacher Doragosa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195579 AND `DifficultyID`=1); -- Primal Gust
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195578 AND `DifficultyID`=1); -- Ice Boulder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195569 AND `DifficultyID`=1); -- Jump Pad Visual
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195564,192864)); -- Jump Pad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195495 AND `DifficultyID`=0); -- Oddly Shaped Rock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195441 AND `DifficultyID`=1); -- [DNT] Wind Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195416 AND `DifficultyID`=1); -- Magic Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195399,190366)); -- Curious Swoglet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195336 AND `DifficultyID`=0); -- Dummy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (195320,195318,193529)); -- Crumbling Cave Rock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195265 AND `DifficultyID`=1); -- Stormcaller Arynga
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195222,187021)); -- Rotbow Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195138 AND `DifficultyID`=1); -- Detonating Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (195135,185529)); -- Bracken Warscourge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=195119 AND `DifficultyID`=1); -- Primalist Shockcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194978 AND `DifficultyID`=1); -- Arcane Eruption
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194900 AND `DifficultyID`=0) OR (`Entry`=194897 AND `DifficultyID`=1); -- Stormsurge Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194898 AND `DifficultyID`=1); -- Primalist Arcblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194896 AND `DifficultyID`=1); -- Primal Stormshield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194895 AND `DifficultyID`=1); -- Unstable Squall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194894 AND `DifficultyID`=1); -- Primalist Stormspeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194883 AND `DifficultyID`=1); -- Cosmetic Flavor[DNT]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194835 AND `DifficultyID`=1); -- Sparks
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194833 AND `DifficultyID`=1); -- Swoglet Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194826 AND `DifficultyID`=1); -- Ping Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194825 AND `DifficultyID`=1); -- Maruukai Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194824 AND `DifficultyID`=1); -- Okir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194823 AND `DifficultyID`=1); -- Hearthkeeper Berulan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194822 AND `DifficultyID`=1); -- Maruukai Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194816 AND `DifficultyID`=1); -- Forgewrought Monstrosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194806 AND `DifficultyID`=1); -- Crackling Vortex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194745 AND `DifficultyID`=1); -- Rotfang Hyena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194735 AND `DifficultyID`=0) OR (`Entry`=194687 AND `DifficultyID`=1); -- Majordomo Selistra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194725 AND `DifficultyID`=0); -- Cleansing Cauldron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194675 AND `DifficultyID`=1); -- Decaying Cauldron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194642 AND `DifficultyID`=0); -- Core Fragment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (194622,190205)); -- Scorchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (194487,194241,187224)); -- Vile Rothexer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194469 AND `DifficultyID`=1); -- Fledgling Slasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194467 AND `DifficultyID`=1); -- Brackenhide Slasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194389 AND `DifficultyID`=1); -- Lava Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194373 AND `DifficultyID`=1); -- Brackenhide Gnoll
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194367 AND `DifficultyID`=1); -- Dragonkiller Lance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194355 AND `DifficultyID`=0); -- Infuser Sariya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194317 AND `DifficultyID`=1); -- Stormcaller Boroo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194316 AND `DifficultyID`=1); -- Stormcaller Zarii
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194315 AND `DifficultyID`=1); -- Stormcaller Solongo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (194273,187238)); -- Witherling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194256 AND `DifficultyID`=1); -- Bloodthirsty Cub
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194218 AND `DifficultyID`=1); -- Tsunami Generator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (194186,191726,186694)); -- Slain Tuskarr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194184 AND `DifficultyID`=1); -- Ritual Focus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194181 AND `DifficultyID`=1); -- Vexamus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=194029 AND `DifficultyID`=0) OR (`Entry`=190409 AND `DifficultyID`=1); -- Zahkrana
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193944 AND `DifficultyID`=1); -- Qalashi Lavamancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193800 AND `DifficultyID`=0); -- Pillar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193799 AND `DifficultyID`=1); -- Rotchanting Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193572 AND `DifficultyID`=1); -- Nokhud Warsmith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193555 AND `DifficultyID`=1) OR (`Entry`=186643 AND `DifficultyID`=0); -- Nokhud Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193553 AND `DifficultyID`=1) OR (`Entry`=186811 AND `DifficultyID`=0); -- Nokhud Warhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193544 AND `DifficultyID`=0); -- Nokhud Houndsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193462 AND `DifficultyID`=1); -- Batak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193457 AND `DifficultyID`=1); -- Balara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193373 AND `DifficultyID`=1); -- Nokhud Thunderfist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193352 AND `DifficultyID`=1); -- Hextrick Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193295 AND `DifficultyID`=0); -- Gold Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193293 AND `DifficultyID`=1); -- Qalashi Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=193291 AND `DifficultyID`=1); -- Apex Blazewing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (193033,191750)); -- Spell Bunny
UPDATE `creature_template_difficulty` SET `TypeFlags`=268435456 WHERE (`Entry`=193008 AND `DifficultyID`=1); -- Goru the Shepherd
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192955 AND `DifficultyID`=1); -- Draconic Illusion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192852 AND `DifficultyID`=1); -- Teerai Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192851 AND `DifficultyID`=1); -- Boku
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192850 AND `DifficultyID`=1); -- Khansguard Jebotai
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192849 AND `DifficultyID`=1); -- Khansguard Akato
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192847 AND `DifficultyID`=1); -- Tigari Khan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192846 AND `DifficultyID`=1); -- Sansok Khan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192803 AND `DifficultyID`=1); -- War Ohuna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192800 AND `DifficultyID`=1); -- Nokhud Lancemaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192796 AND `DifficultyID`=1); -- Nokhud Hornsounder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192794 AND `DifficultyID`=1); -- Nokhud Beastmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192789 AND `DifficultyID`=1); -- Nokhud Longbow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192788 AND `DifficultyID`=1); -- Qalashi Thaumaturge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192787 AND `DifficultyID`=1); -- Qalashi Spinecrusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192786 AND `DifficultyID`=1); -- Qalashi Plunderer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192784 AND `DifficultyID`=0); -- Qalashi Earthbinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192783 AND `DifficultyID`=0); -- Loyal Warhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192782 AND `DifficultyID`=0); -- Molten Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192781 AND `DifficultyID`=1); -- Ore Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192680 AND `DifficultyID`=1); -- Guardian Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192622 AND `DifficultyID`=0); -- Stomach
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=192528 AND `DifficultyID`=1); -- Winds of the Isles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=226392 WHERE (`Entry`=192464 AND `DifficultyID`=1); -- Raging Ember
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=7.5 WHERE (`Entry`=192333 AND `DifficultyID`=1); -- Alpha Eagle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=2.5 WHERE (`Entry`=192329 AND `DifficultyID`=1); -- Territorial Eagle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191936 AND `DifficultyID`=1); -- Dulox
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191935 AND `DifficultyID`=1); -- Koflo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191933 AND `DifficultyID`=1); -- Malinor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191932 AND `DifficultyID`=1); -- Dra'zish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191926 AND `DifficultyID`=1); -- Fishface
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191921 AND `DifficultyID`=1); -- Treasure Pile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191882 AND `DifficultyID`=1); -- [DNT] Spear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191847 AND `DifficultyID`=1); -- Nokhud Plainstomper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191752 AND `DifficultyID`=1); -- Focus of Decay
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191739 AND `DifficultyID`=1); -- Scalebane Lieutenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191736 AND `DifficultyID`=1); -- Crawth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191631 AND `DifficultyID`=1) OR (`Entry`=187820 AND `DifficultyID`=0); -- Ball
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191610 AND `DifficultyID`=1); -- Goal of the Searing Blaze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191574 AND `DifficultyID`=1); -- Choking Rotcloud
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191559 AND `DifficultyID`=0); -- Ember of Ignarus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191498 AND `DifficultyID`=1); -- Qalashi Mammoth Trainer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191484 AND `DifficultyID`=0); -- Rotting Geyser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191472 AND `DifficultyID`=0); -- Glacial Surge Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191320 AND `DifficultyID`=0); -- Erratic Sprout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191313 AND `DifficultyID`=1); -- Bubbling Sapling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry`=191253) OR (`DifficultyID`=1 AND `Entry` IN (189896,189162)); -- Infusion Pool
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191243 AND `DifficultyID`=1); -- Wild Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=191207 AND `DifficultyID`=1); -- Khanam Matra Sarest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (191046,180315)); -- Shady Dealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (191045,151812)); -- Detect-o-Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190926 AND `DifficultyID`=0); -- Time Vortex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190923 AND `DifficultyID`=1); -- Zephyrling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (190736,190735,190734,190733,190732)); -- Curio
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (190630,190023)); -- Lava Tentacles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190609 AND `DifficultyID`=1); -- Echo of Doragosa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (190596,190374)); -- Sands of Time
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190517 AND `DifficultyID`=1); -- Azure Vaults Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190510 AND `DifficultyID`=1); -- Vault Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190509 AND `DifficultyID`=1); -- Ley-Line Sprout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190490 AND `DifficultyID`=0); -- Lifewater Spring
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=1 WHERE (`Entry`=190426 AND `DifficultyID`=1); -- Decay Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190412 AND `DifficultyID`=1); -- Amella
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190411 AND `DifficultyID`=1); -- Xius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190410 AND `DifficultyID`=1); -- Akxall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190408 AND `DifficultyID`=1); -- Commander Lethanak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=2.5 WHERE (`Entry`=190407 AND `DifficultyID`=1); -- Aqua Rager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190406 AND `DifficultyID`=1); -- Aqualing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15 WHERE (`Entry`=190405 AND `DifficultyID`=1); -- Infuser Sariya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190404 AND `DifficultyID`=1); -- Subterranean Proto-Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9 WHERE (`Entry`=190403 AND `DifficultyID`=1); -- Glacial Proto-Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190401 AND `DifficultyID`=1); -- Gusting Proto-Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190400 AND `DifficultyID`=1); -- Mother Elion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190397 AND `DifficultyID`=1); -- Ruby Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190382 AND `DifficultyID`=1); -- Ruby Nurse Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190381 AND `DifficultyID`=1); -- Rotburst Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4.5 WHERE (`Entry`=190377 AND `DifficultyID`=1); -- Primalist Icecaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190373 AND `DifficultyID`=1); -- Primalist Galesinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190371 AND `DifficultyID`=1); -- Primalist Earthshaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190370 AND `DifficultyID`=1); -- Squallbringer Cyraz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190368 AND `DifficultyID`=1); -- Flamecaller Aymi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190362 AND `DifficultyID`=1); -- Dazzling Dragonfly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190359 AND `DifficultyID`=1); -- Skulking Zealot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190358 AND `DifficultyID`=0); -- Spineslinger Mantis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=3.75 WHERE (`Entry`=190348 AND `DifficultyID`=1); -- Primalist Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190345 AND `DifficultyID`=1); -- Primalist Geomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190342 AND `DifficultyID`=1); -- Containment Apparatus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190340 AND `DifficultyID`=1); -- Refti Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190294 AND `DifficultyID`=1); -- Nokhud Stormcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190187 AND `DifficultyID`=1); -- Draconic Image
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190099 AND `DifficultyID`=1); -- Terrified Cub
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190060 AND `DifficultyID`=1); -- Onyx Clutchwarden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190059 AND `DifficultyID`=1); -- Ruby Clutchwarden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190055 AND `DifficultyID`=1); -- Azure Clutchwarden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190054 AND `DifficultyID`=1); -- Bronze Clutchwarden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190051 AND `DifficultyID`=1); -- Emerald Clutchwarden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190034 AND `DifficultyID`=1); -- Blazebound Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190019 AND `DifficultyID`=0); -- Spark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=190016 AND `DifficultyID`=0); -- Seed of Everburning Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189940 AND `DifficultyID`=1); -- [DNT] FX Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189905 AND `DifficultyID`=1); -- High Thaumaturge Fural
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (189903,189595)); -- Infused Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189901 AND `DifficultyID`=1); -- Warlord Sargha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry`=189900) OR (`DifficultyID`=1 AND `Entry` IN (83765,81283)); -- Grom'kar Footsoldier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=1 AND `Entry` IN (189893,187894)); -- Infused Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189886 AND `DifficultyID`=1); -- Blazebound Firestorm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189874 AND `DifficultyID`=1); -- Slain Boar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189786 AND `DifficultyID`=1); -- Blazing Aegis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189729 AND `DifficultyID`=1); -- Primal Tsunami
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189727 AND `DifficultyID`=1); -- Khajin the Unyielding
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189722 AND `DifficultyID`=1); -- Gulping Goliath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189719 AND `DifficultyID`=1); -- Watcher Irideus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189670 AND `DifficultyID`=0); -- Headmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189669 AND `DifficultyID`=1); -- Binding Spear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189668 AND `DifficultyID`=1); -- Professor Maxdormu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189667 AND `DifficultyID`=1); -- Professor Ichistrasz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189555 AND `DifficultyID`=1); -- Astral Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189550 AND `DifficultyID`=0); -- Bludgeoning Rock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189531 AND `DifficultyID`=1); -- Decayed Elder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189514 AND `DifficultyID`=0); -- Goal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189494 AND `DifficultyID`=0); -- Diseased Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189478 AND `DifficultyID`=1); -- Forgemaster Gorek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189475 AND `DifficultyID`=0); -- Ignarus, Forge Awakened
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189474 AND `DifficultyID`=1); -- The Scorching Forge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189472 AND `DifficultyID`=1); -- Qalashi Lavabearer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189471 AND `DifficultyID`=1); -- Qalashi Blacksmith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189470 AND `DifficultyID`=1); -- Lava Flare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189467 AND `DifficultyID`=1); -- Qalashi Bonesplitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189466 AND `DifficultyID`=1); -- Irontorch Commander
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189464 AND `DifficultyID`=1); -- Qalashi Irontorch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189342 AND `DifficultyID`=1); -- Burning Chain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189340 AND `DifficultyID`=1); -- Chargath, Bane of Scales
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189318 AND `DifficultyID`=1); -- Infected Bear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189316 AND `DifficultyID`=0); -- Rotted Boar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189267 AND `DifficultyID`=0); -- zzREUSE
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189266 AND `DifficultyID`=1); -- Qalashi Trainee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189265 AND `DifficultyID`=1); -- Qalashi Bonetender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189247 AND `DifficultyID`=1); -- Tamed Phoenix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189235 AND `DifficultyID`=1); -- Overseer Lahar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189232 AND `DifficultyID`=1); -- Kokia Blazehoof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189227 AND `DifficultyID`=1); -- Qalashi Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=189219 AND `DifficultyID`=1); -- Qalashi Goulash
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=188252 AND `DifficultyID`=1); -- Melidrussa Chillworn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=188244 AND `DifficultyID`=1); -- Primal Juggernaut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=228518 WHERE (`Entry`=188100 AND `DifficultyID`=1); -- Shrieking Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=188086 AND `DifficultyID`=1); -- Ruby Sitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=188067 AND `DifficultyID`=1); -- Flashfrost Chillweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=188011 AND `DifficultyID`=1); -- Primal Terrasentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187999 AND `DifficultyID`=1); -- Shrieking Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187969 AND `DifficultyID`=1); -- Flashfrost Earthshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187897 AND `DifficultyID`=1); -- Defier Draghar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187895 AND `DifficultyID`=1); -- Ohn'ahra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187782 AND `DifficultyID`=0); -- [DNT] Thorny Trapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (187694,187053)); -- Vehicle
UPDATE `creature_template_difficulty` SET `TypeFlags2`=64 WHERE (`Entry`=187678 AND `DifficultyID`=1); -- Alexstrasza the Life-Binder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (187421,179743)); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187315 AND `DifficultyID`=1); -- Disease Slasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187287 AND `DifficultyID`=1); -- Professor Mystakria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187246 AND `DifficultyID`=1); -- Nullmagic Hornswog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187242 AND `DifficultyID`=1); -- Tarasek Looter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187240 AND `DifficultyID`=1); -- Drakonid Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187231 AND `DifficultyID`=1); -- Wither Biter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187199 AND `DifficultyID`=0); -- Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187192 AND `DifficultyID`=1); -- Rageclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=228515 WHERE (`Entry`=187159 AND `DifficultyID`=1); -- Shrieking Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187155 AND `DifficultyID`=1); -- Rune Seal Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187154 AND `DifficultyID`=1); -- Unstable Curator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=187033 AND `DifficultyID`=1); -- Stinkbreath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186951 AND `DifficultyID`=0); -- [DNT] Accidental Amalgamation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186813 AND `DifficultyID`=0); -- Air Revenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186812 AND `DifficultyID`=0); -- Primal Air Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186810 AND `DifficultyID`=0); -- Nokhud Houndmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186809 AND `DifficultyID`=0); -- Nokhud Bodyguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186807 AND `DifficultyID`=0); -- Nokhud Darkcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186806 AND `DifficultyID`=0); -- Nokhud Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186803 AND `DifficultyID`=0); -- Nokhud Tombraider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186793 AND `DifficultyID`=1); -- [DNT] Corpse Post
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186766 AND `DifficultyID`=1); -- Captive Tuskarr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186741 AND `DifficultyID`=1); -- Arcane Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186740 AND `DifficultyID`=1); -- Arcane Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186739 AND `DifficultyID`=1); -- Azureblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186738 AND `DifficultyID`=1); -- Umbrelskul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=1.799999952316284179 WHERE (`Entry`=186696 AND `DifficultyID`=1); -- Quaking Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186666 AND `DifficultyID`=1); -- Gwybod
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186665 AND `DifficultyID`=1); -- Ginger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186644 AND `DifficultyID`=1); -- Leymor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186616 AND `DifficultyID`=1); -- Granyth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186615 AND `DifficultyID`=1); -- The Raging Tempest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186610 AND `DifficultyID`=0); -- Nokhud Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186580 AND `DifficultyID`=0); -- Grimtotem Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186566 AND `DifficultyID`=0); -- Grimtotem Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186565 AND `DifficultyID`=0); -- Gorm Grimtotem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186563 AND `DifficultyID`=0); -- Cor Grimtotem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186561 AND `DifficultyID`=0); -- Grimtotem Kodomaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186560 AND `DifficultyID`=0); -- Grimtotem Earthcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186559 AND `DifficultyID`=0); -- Grimtotem Warbull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186475 AND `DifficultyID`=0); -- Earthen Shaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186474 AND `DifficultyID`=0); -- Earthen Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186425 AND `DifficultyID`=0); -- Living Rubble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186339 AND `DifficultyID`=1); -- Teera
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186338 AND `DifficultyID`=1); -- Maruuk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186284 AND `DifficultyID`=1); -- Gutchewer Bear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`DifficultyID`=0 AND `Entry` IN (186254,186253,186252)); -- Boss 3
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186246 AND `DifficultyID`=1); -- Fleshripper Vulture
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186243 AND `DifficultyID`=0); -- Gutbutcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186242 AND `DifficultyID`=1); -- Skulking Gutstabber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186229 AND `DifficultyID`=1); -- Wilted Oak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186227 AND `DifficultyID`=1); -- Monstrous Decay
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186226 AND `DifficultyID`=1); -- Fetid Rotsinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186221 AND `DifficultyID`=0); -- Rusted Cedar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186220 AND `DifficultyID`=1); -- Brackenhide Shaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186208 AND `DifficultyID`=1); -- Rotbow Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186206 AND `DifficultyID`=1); -- Cruel Bonecrusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186193 AND `DifficultyID`=0); -- Vile Clawslasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186191 AND `DifficultyID`=1); -- Decay Speaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186185 AND `DifficultyID`=0); -- Burning Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=186159 AND `DifficultyID`=1) OR (`Entry`=175799 AND `DifficultyID`=0); -- Unstable Goods
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186151 AND `DifficultyID`=1); -- Balakar Khan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=225404 WHERE (`Entry`=186125 AND `DifficultyID`=1); -- Tricktotem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=225400 WHERE (`Entry`=186124 AND `DifficultyID`=1); -- Gashtooth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=225408 WHERE (`Entry`=186122 AND `DifficultyID`=1); -- Rira Hackclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=221950 WHERE (`Entry`=186121 AND `DifficultyID`=1); -- Decatriarch Wratheye
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=236908 WHERE (`Entry`=186120 AND `DifficultyID`=1); -- Treemouth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=186116 AND `DifficultyID`=1); -- Gutshot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185691 AND `DifficultyID`=1); -- Vicious Hyena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185657 AND `DifficultyID`=0); -- Aberrant Decay
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185656 AND `DifficultyID`=1); -- Filth Caller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185534 AND `DifficultyID`=1); -- Bonebolt Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185528 AND `DifficultyID`=1); -- Trickclaw Mystic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=185508 AND `DifficultyID`=1); -- Claw Fighter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=184587 AND `DifficultyID`=1); -- Ta'piks
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=183425 AND `DifficultyID`=1); -- Wholesome Host
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=207259 WHERE (`Entry`=183424 AND `DifficultyID`=1); -- Virtuous Gentleman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=207254 WHERE (`Entry`=183423 AND `DifficultyID`=1); -- Reformed Bachelor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (182668,182667,182160)); -- Invasion Beacon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=34.65000152587890625 WHERE (`Entry`=181861 AND `DifficultyID`=1); -- Magmatusk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9 WHERE (`Entry`=181751 AND `DifficultyID`=0); -- Djaradin Lietenant Caster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180869 AND `DifficultyID`=0); -- Exotic Goods
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180868 AND `DifficultyID`=0); -- Weapons Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180867 AND `DifficultyID`=0); -- Cartel Reveler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180863,178433,177269)) OR (`DifficultyID`=0 AND `Entry`=177078); -- So'leah
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180756 AND `DifficultyID`=1); -- Shady Solicitor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180755 AND `DifficultyID`=1); -- High Roller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180754 AND `DifficultyID`=1); -- Questionable Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180751 AND `DifficultyID`=1); -- Speakeasy Handler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180750 AND `DifficultyID`=1); -- Au'manal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180713 AND `DifficultyID`=0) OR (`Entry`=177807 AND `DifficultyID`=1); -- Customs Security
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180640 AND `DifficultyID`=0); -- Stormbound Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (180637,180636,180635)); -- Escaped Bounty
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180634 AND `DifficultyID`=0); -- Delayed Cartel Fe Aquisitions
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180618 AND `DifficultyID`=1); -- Cartel Negotiator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180617 AND `DifficultyID`=1); -- Hired Scoundrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180616 AND `DifficultyID`=1); -- Trade Prince Gallywix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180615 AND `DifficultyID`=0); -- Oasis Hostess
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180614 AND `DifficultyID`=1); -- Oasis Server
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180613 AND `DifficultyID`=1); -- Oasis Host
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180612,179386)); -- Corsair Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180595 AND `DifficultyID`=1); -- Harp of Marasmius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180594 AND `DifficultyID`=1); -- Vulpera Flute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180593 AND `DifficultyID`=1); -- Eye of Valinor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180592 AND `DifficultyID`=0); -- Chunk of Jade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180591 AND `DifficultyID`=0); -- Bones of Mortanis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180590 AND `DifficultyID`=1); -- Demon Skull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180589 AND `DifficultyID`=1); -- Kleia's Special Cake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180588 AND `DifficultyID`=1); -- Plate of Ripe Purians
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180587 AND `DifficultyID`=1); -- Bolt of Kyrian Brightweave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180586 AND `DifficultyID`=1); -- Bolt of Silk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180585 AND `DifficultyID`=1); -- Denathrius' Private Diary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180584 AND `DifficultyID`=0); -- A History of Maldraxxus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180582 AND `DifficultyID`=1); -- Vial of Nurgash's Blood
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180581 AND `DifficultyID`=1); -- Potion of Invisibility
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180580 AND `DifficultyID`=1); -- Myza's Special Spice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180579 AND `DifficultyID`=1); -- Aromatic Spices
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180578 AND `DifficultyID`=1); -- Perfect Replica of Remornia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180572 AND `DifficultyID`=1); -- Boopers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180571 AND `DifficultyID`=1); -- Beeyuh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180567 AND `DifficultyID`=1); -- Frenzied Nightclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180566 AND `DifficultyID`=1); -- Rat of Unusual Size
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180565 AND `DifficultyID`=1); -- Bazaar Vagabond
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180564 AND `DifficultyID`=0) OR (`Entry`=180117 AND `DifficultyID`=1); -- Meat Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180563 AND `DifficultyID`=1); -- Backalley Schemer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180562,180114)); -- Fruit Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180561 AND `DifficultyID`=1); -- Oasis Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180558 AND `DifficultyID`=0); -- Mo'Leah
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180510 AND `DifficultyID`=1); -- Toxic Saurid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180495 AND `DifficultyID`=1); -- Enraged Direhorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180494 AND `DifficultyID`=0); -- Festerhide Grizzly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180486 AND `DifficultyID`=0) OR (`Entry`=177609 AND `DifficultyID`=1); -- Dirtwhistle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180485 AND `DifficultyID`=0) OR (`Entry`=177325 AND `DifficultyID`=1); -- Hips
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180484 AND `DifficultyID`=0) OR (`Entry`=177611 AND `DifficultyID`=1); -- Vilt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180470 AND `DifficultyID`=0) OR (`Entry`=177327 AND `DifficultyID`=1); -- Verethian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180444 AND `DifficultyID`=1); -- Hired Runner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180443 AND `DifficultyID`=1); -- Exotic Reseller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180442 AND `DifficultyID`=1); -- Novice Acquirer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180433 AND `DifficultyID`=1); -- Wandering Pulsar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180432 AND `DifficultyID`=1); -- Devoted Accomplice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180431 AND `DifficultyID`=1); -- Focused Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180429 AND `DifficultyID`=1); -- Adorned Starseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180419 AND `DifficultyID`=0); -- Scrupulous Inspector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180406 AND `DifficultyID`=0); -- Underenthused Watch Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180399 AND `DifficultyID`=0) OR (`Entry`=177329 AND `DifficultyID`=1); -- Evaile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180390 AND `DifficultyID`=1); -- Dantun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180348 AND `DifficultyID`=1); -- Cartel Muscle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180345 AND `DifficultyID`=0); -- Door to Customs Enforcement
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180336 AND `DifficultyID`=1); -- Cartel Wiseguy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180335 AND `DifficultyID`=1); -- Cartel Smuggler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180328 AND `DifficultyID`=1); -- Au'ri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180327 AND `DifficultyID`=1); -- Au'mba
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180322 AND `DifficultyID`=1); -- Fe'tajid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180320 AND `DifficultyID`=1); -- Illicit Purveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180317 AND `DifficultyID`=1); -- Illicit Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180314 AND `DifficultyID`=1); -- Patio Waiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180310 AND `DifficultyID`=1); -- Shop Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180302,180301,180296)) OR (`DifficultyID`=0 AND `Entry` IN (180300,180299,180298,180297)); -- Leader Au'llano
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180295 AND `DifficultyID`=1); -- Xy'rihn the Keen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180286 AND `DifficultyID`=1); -- Leader Xy'viler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180284 AND `DifficultyID`=1); -- Artificer Xy'mox
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180268 AND `DifficultyID`=1); -- Ta'sam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180267 AND `DifficultyID`=1); -- Ta'rex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180266 AND `DifficultyID`=1); -- Ta'ules
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180263 AND `DifficultyID`=1); -- Lounging Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180261 AND `DifficultyID`=1); -- Market Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180260 AND `DifficultyID`=1); -- Spice Trader Au'saar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180258,180257)); -- Wealthy Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180255 AND `DifficultyID`=0) OR (`Entry`=180254 AND `DifficultyID`=1); -- Waiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180253 AND `DifficultyID`=1); -- Attentive Waitstaff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180250 AND `DifficultyID`=1); -- Elite Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180249 AND `DifficultyID`=1); -- Market Server
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180248 AND `DifficultyID`=1); -- Hungry Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180247 AND `DifficultyID`=1); -- Hungry Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180244 AND `DifficultyID`=1); -- Culinary Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180243 AND `DifficultyID`=1); -- Market Chef
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180241,180215)); -- Export Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180228 AND `DifficultyID`=1); -- Export Supervisor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180216 AND `DifficultyID`=0); -- Voracious Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180212 AND `DifficultyID`=0); -- Expendable Lackey
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180161 AND `DifficultyID`=1) OR (`Entry`=179945 AND `DifficultyID`=0); -- Shopkeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180159,176562)); -- Brawling Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180158,176561)); -- Unruly Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180156 AND `DifficultyID`=1); -- Enthusiastic Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180153 AND `DifficultyID`=1); -- Aqir Impaler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180152,179011)); -- Shipping Facilitator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180151,179519)); -- Al'dalil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (180150,180149)); -- Relaxed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180148 AND `DifficultyID`=1); -- Coin Changer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180147 AND `DifficultyID`=1); -- Well-informed Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180131 AND `DifficultyID`=0); -- Glow Stick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180130 AND `DifficultyID`=1); -- Antique Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180129 AND `DifficultyID`=1); -- Toy Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180128 AND `DifficultyID`=0); -- Elekk Plushie
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180119 AND `DifficultyID`=0); -- Amani Dragonhawk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180118 AND `DifficultyID`=0); -- Wriggling Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180110 AND `DifficultyID`=0); -- Organic Fruit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180109 AND `DifficultyID`=0); -- Dragonhawk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180100 AND `DifficultyID`=0); -- Bloodthirsty Pengling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180098 AND `DifficultyID`=0); -- Abyssal Nightmare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180097 AND `DifficultyID`=0); -- Curious Voidstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180095 AND `DifficultyID`=1); -- Ankylodon Bull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180094 AND `DifficultyID`=0); -- Shardhide Pulverizer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180092 AND `DifficultyID`=1); -- Giant Hive Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180091 AND `DifficultyID`=1); -- Ancient Core Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=180015 AND `DifficultyID`=1); -- Burly Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (179991,179990)); -- Tazavesh Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179983 AND `DifficultyID`=1); -- Dozing Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179982 AND `DifficultyID`=1); -- Hungry Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179981 AND `DifficultyID`=1); -- Chef
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179970 AND `DifficultyID`=0); -- Browsing Shopper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179957 AND `DifficultyID`=0); -- Invis Destruction Tracker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179955 AND `DifficultyID`=1); -- Sorting Device Visual Stalkers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179954 AND `DifficultyID`=1); -- Beam Splicer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179951 AND `DifficultyID`=0); -- Overenthused Watch Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179950 AND `DifficultyID`=0); -- City Guard Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179949 AND `DifficultyID`=0); -- City Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (179948,179947)); -- Impressed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179946 AND `DifficultyID`=0); -- Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179933 AND `DifficultyID`=0); -- Summoned Lackey
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179932 AND `DifficultyID`=0); -- Acquisitionist Xy'rahn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179909 AND `DifficultyID`=1); -- Curious Onlooker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179908 AND `DifficultyID`=1); -- Distressed Merchant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179893 AND `DifficultyID`=1); -- Cartel Skulker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179886 AND `DifficultyID`=1); -- Auction Bidder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (179844,179843)); -- Shocklight Barrier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179842 AND `DifficultyID`=1); -- Commerce Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179841 AND `DifficultyID`=1); -- Veteran Sparkcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179840 AND `DifficultyID`=1); -- Market Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179837 AND `DifficultyID`=1); -- Tracker Zo'korss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179821 AND `DifficultyID`=1); -- Commander Zo'far
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179799 AND `DifficultyID`=1); -- Portal Authority Tunnelmancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179796 AND `DifficultyID`=1); -- Ta'leesa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179795 AND `DifficultyID`=1); -- Ta'speri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179792 AND `DifficultyID`=1); -- Horn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179786 AND `DifficultyID`=1); -- Replace Trumpet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179785 AND `DifficultyID`=1); -- Replace Saxophone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179783 AND `DifficultyID`=1) OR (`Entry`=176566 AND `DifficultyID`=0); -- Guitar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179778 AND `DifficultyID`=1); -- Rift Blast Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179738 AND `DifficultyID`=1); -- Captain Caulle Whiphook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179733 AND `DifficultyID`=1); -- Invigorating Fish Stick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179654 AND `DifficultyID`=1); -- Invis Flee Point
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179551 AND `DifficultyID`=1); -- Speakeasy Security
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179399 AND `DifficultyID`=1); -- Drunk Pirate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179388 AND `DifficultyID`=1); -- Hourglass Tidesage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179387 AND `DifficultyID`=0); -- Corsair Sniper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179334 AND `DifficultyID`=1); -- Portalmancer Zo'honn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179269 AND `DifficultyID`=1); -- Oasis Security
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179122 AND `DifficultyID`=1); -- Body Armor Right
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179121 AND `DifficultyID`=1); -- Zo'phex Cosmetic Summon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179014 AND `DifficultyID`=1); -- [DNT] Pickup Yellow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179013 AND `DifficultyID`=1); -- [DNT] Pickup Purple
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=179012 AND `DifficultyID`=1); -- [DNT] Pickup Blue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178976 AND `DifficultyID`=1); -- [DNT] Pickup Orange
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178962 AND `DifficultyID`=1); -- Xy'aro
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178788 AND `DifficultyID`=0); -- Portalmancer Zo'nyy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (178549,178391)); -- Customs Watch-Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178545 AND `DifficultyID`=1); -- Watch-Agent Summon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178544 AND `DifficultyID`=0); -- Portalmancer Zo'dahh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178435 AND `DifficultyID`=0) OR (`Entry`=177500 AND `DifficultyID`=1); -- Corsair Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178432 AND `DifficultyID`=0); -- Call Elevator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178394 AND `DifficultyID`=1); -- Cartel Lackey
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (178393,177815)); -- Customs Anklebinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178392 AND `DifficultyID`=1); -- Gatewarden Zo'mazz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178388 AND `DifficultyID`=1); -- Bazaar Strongarm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178322 AND `DifficultyID`=0); -- Damaged Flask
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178321 AND `DifficultyID`=1); -- Threadbare Cloth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178320 AND `DifficultyID`=1); -- Stale Bread
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178319 AND `DifficultyID`=1); -- Worn Journal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178318 AND `DifficultyID`=1); -- Common Drum
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178317 AND `DifficultyID`=1); -- Dusty Skull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178316 AND `DifficultyID`=1); -- Cheap Spices
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178315 AND `DifficultyID`=1); -- Cracked Warhammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178310 AND `DifficultyID`=1); -- Balanced Sword
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178171 AND `DifficultyID`=1); -- Stormforged Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178166 AND `DifficultyID`=0); -- Wavemaster Llorg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178165 AND `DifficultyID`=1); -- Coastwalker Goliath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178163 AND `DifficultyID`=1); -- Murkbrine Shorerunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (178160,176446)); -- Fulfillment Drone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178142 AND `DifficultyID`=1); -- Murkbrine Fishmancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178141 AND `DifficultyID`=1); -- Murkbrine Scalebinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178139 AND `DifficultyID`=1); -- Murkbrine Shellcrusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178133 AND `DifficultyID`=1); -- Murkbrine Wavejumper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178001 AND `DifficultyID`=1); -- Dull Opal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=178000 AND `DifficultyID`=0); -- Xy'daro
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177999 AND `DifficultyID`=1); -- Xy'darid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177998 AND `DifficultyID`=1); -- Xy'nara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177996 AND `DifficultyID`=1); -- Bazaar Shopper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177995 AND `DifficultyID`=1); -- Xy'zaro
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177994 AND `DifficultyID`=1); -- Xy'har
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177885 AND `DifficultyID`=0); -- Market Abstractor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177884 AND `DifficultyID`=0); -- Market Regulator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177883 AND `DifficultyID`=0); -- Market Limitor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177882 AND `DifficultyID`=0); -- Market Binder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177881 AND `DifficultyID`=0); -- Market Radiator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177880 AND `DifficultyID`=0); -- Market Diffuser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177879 AND `DifficultyID`=0); -- Market Conveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177875 AND `DifficultyID`=0); -- Market Disorientor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177874 AND `DifficultyID`=0); -- Market Distractionary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177872 AND `DifficultyID`=0); -- Cartel Neophyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177871 AND `DifficultyID`=0); -- Cartel Brightcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177870 AND `DifficultyID`=0); -- Cartel Grandcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177869 AND `DifficultyID`=0); -- Cartel Spellfist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177868 AND `DifficultyID`=1); -- Creature Collector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177867 AND `DifficultyID`=0); -- Cartel Battlemancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177866 AND `DifficultyID`=0); -- Cartel Substantiator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177865 AND `DifficultyID`=0); -- Cartel Manifestor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177864 AND `DifficultyID`=0); -- Cartel Appropriator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177821 AND `DifficultyID`=1); -- Progenitor Relic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177817 AND `DifficultyID`=1); -- Support Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177816 AND `DifficultyID`=1); -- Interrogation Specialist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177808 AND `DifficultyID`=1); -- Armored Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177806 AND `DifficultyID`=0); -- Customs Shiftdodger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177802 AND `DifficultyID`=0); -- Security Specialist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177801 AND `DifficultyID`=0); -- Customs Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177760 AND `DifficultyID`=1); -- Xy'kitaab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177757 AND `DifficultyID`=1); -- Xy'tadir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177756 AND `DifficultyID`=1); -- Xy'aqida
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177755 AND `DifficultyID`=1); -- Xy'jahid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177753 AND `DifficultyID`=1); -- Xy'mal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177752 AND `DifficultyID`=1); -- Xy'ghana
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177716 AND `DifficultyID`=1); -- So' Cartel Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177672 AND `DifficultyID`=1); -- Terminal Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177608 AND `DifficultyID`=1); -- Trumpet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177607 AND `DifficultyID`=1); -- Saxophone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177255 AND `DifficultyID`=1); -- Contraband Auctioneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=177085 AND `DifficultyID`=0); -- Archanic Beacon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176896 AND `DifficultyID`=1); -- Edge of Annihilation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176712 AND `DifficultyID`=0); -- Corsair Kegkeep
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176705 AND `DifficultyID`=1); -- Venza Goldfuse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176660 AND `DifficultyID`=1); -- Replace Guitar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176616 AND `DifficultyID`=1); -- Speakeasy Drinksmith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176615 AND `DifficultyID`=1); -- Waffles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176565 AND `DifficultyID`=1); -- Disruptive Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=1 AND `Entry` IN (176564,176563)); -- Zo'gron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176557 AND `DifficultyID`=0); -- Body Armor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176556 AND `DifficultyID`=1); -- Alcruux
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176555 AND `DifficultyID`=1); -- Achillite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176551 AND `DifficultyID`=1); -- Vault Purifier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=0 AND `Entry` IN (176550,176549,176433,176432,176431,176430)) OR (`DifficultyID`=1 AND `Entry` IN (176217,175806)); -- So'azmi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176540 AND `DifficultyID`=1); -- Body Armor Left
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176534 AND `DifficultyID`=1); -- Arm Right
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176519 AND `DifficultyID`=1); -- Customer VO Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176517 AND `DifficultyID`=0); -- Warlord Actris
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176515 AND `DifficultyID`=0); -- Grovetender Silandra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176514 AND `DifficultyID`=1); -- Angry Customer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176513 AND `DifficultyID`=0); -- Father Winter's Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176512 AND `DifficultyID`=0); -- Skeletal Courier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176511 AND `DifficultyID`=0); -- Necrolord Nevin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176510 AND `DifficultyID`=0); -- Aspirant Benitos
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176509 AND `DifficultyID`=0); -- Muckface
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176445 AND `DifficultyID`=1); -- Au'myza
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176438 AND `DifficultyID`=1); -- Arm Left
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176398 AND `DifficultyID`=1); -- Shipped Livestock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176397 AND `DifficultyID`=1); -- Holding Pen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176396 AND `DifficultyID`=1); -- Defective Sorter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176395 AND `DifficultyID`=1); -- Overloaded Mailemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176394 AND `DifficultyID`=1); -- P.O.S.T. Worker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176384 AND `DifficultyID`=1); -- Katy Stampwhistle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176341 AND `DifficultyID`=0); -- Corsair Sharpshooter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176327 AND `DifficultyID`=0); -- Portal Vehicle Vehicle Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176323 AND `DifficultyID`=0); -- Hooktail's Treasure
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176321 AND `DifficultyID`=0); -- Package Passenger Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176320 AND `DifficultyID`=0); -- Portal Vehicle Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176302 AND `DifficultyID`=1); -- Corsair Cannoneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176178 AND `DifficultyID`=1); -- Hourglass Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176127 AND `DifficultyID`=0); -- Chain Letter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=176126 AND `DifficultyID`=1); -- Purged by Fire Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175796 AND `DifficultyID`=1); -- Mailroom Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175736 AND `DifficultyID`=1); -- Delivery Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175681 AND `DifficultyID`=0); -- Portal Indicator Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175677 AND `DifficultyID`=1); -- Smuggled Creature
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175667 AND `DifficultyID`=1); -- Titanic Defense Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175663 AND `DifficultyID`=1); -- Hylbrande
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175646 AND `DifficultyID`=1); -- P.O.S.T. Master
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175616 AND `DifficultyID`=1); -- Zo'phex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175576 AND `DifficultyID`=1); -- Containment Cell
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175546 AND `DifficultyID`=1); -- Timecap'n Hooktail
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=193826, `TypeFlags`=2097224 WHERE (`Entry`=172312 AND `DifficultyID`=1); -- Spinemaw Gorger
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=193775 WHERE (`Entry`=172265 AND `DifficultyID`=1); -- Remnant of Fury
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=193266 WHERE (`Entry`=171799 AND `DifficultyID`=1); -- Depths Warden
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=192872, `TypeFlags`=2097224 WHERE (`Entry`=171452 AND `DifficultyID`=1); -- Stonewall Gargon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=171322 AND `DifficultyID`=1); -- Global Affix Stalker
UPDATE `creature_template_difficulty` SET `HealthModifier`=10 WHERE (`Entry`=170082 AND `DifficultyID`=1); -- Baron Halis
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189978 WHERE (`Entry`=168798 AND `DifficultyID`=1); -- Anima Font
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=196514 WHERE (`Entry`=168747 AND `DifficultyID`=1); -- Venomfang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=168694 AND `DifficultyID`=1); -- Knight of the Ebon Blade
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189485 WHERE (`Entry`=168594 AND `DifficultyID`=1); -- Chamber Sentinel
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189479 WHERE (`Entry`=168591 AND `DifficultyID`=1); -- Ravenous Dreadbat
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=188857 WHERE (`Entry`=168058 AND `DifficultyID`=1); -- Infused Quill-feather
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189085 WHERE (`Entry`=167956 AND `DifficultyID`=1); -- Dark Acolyte
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189088 WHERE (`Entry`=167955 AND `DifficultyID`=1); -- Sanguine Cadet
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195441 WHERE (`Entry`=167898 AND `DifficultyID`=1); -- Manifestation of Envy
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=190395 WHERE (`Entry`=167615 AND `DifficultyID`=1); -- Depraved Darkblade
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191538, `TypeFlags`=2097224 WHERE (`Entry`=167113 AND `DifficultyID`=1); -- Spinemaw Acidgullet
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191542, `TypeFlags`=2097224 WHERE (`Entry`=167111 AND `DifficultyID`=1); -- Spinemaw Staghorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=166916 AND `DifficultyID`=1); -- Horde Sparring Partner
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189084 WHERE (`Entry`=166396 AND `DifficultyID`=1); -- Noble Skirmisher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195506 WHERE (`Entry`=166304 AND `DifficultyID`=1); -- Mistveil Stinger
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195510 WHERE (`Entry`=166301 AND `DifficultyID`=1); -- Mistveil Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195489 WHERE (`Entry`=166299 AND `DifficultyID`=1); -- Mistveil Tender
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195483 WHERE (`Entry`=166276 AND `DifficultyID`=1); -- Mistveil Guardian
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195502 WHERE (`Entry`=166275 AND `DifficultyID`=1); -- Mistveil Shaper
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=196898 WHERE (`Entry`=165913 AND `DifficultyID`=1); -- Ghastly Parishioner
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195450 WHERE (`Entry`=165777 AND `DifficultyID`=1); -- Unleashed Suffering Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195454 WHERE (`Entry`=165770 AND `DifficultyID`=1); -- Telekinetic Toss Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195458 WHERE (`Entry`=165737 AND `DifficultyID`=1); -- Sinstone Statue
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191518 WHERE (`Entry`=165560 AND `DifficultyID`=1); -- Gormling Larva
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191336 WHERE (`Entry`=165532 AND `DifficultyID`=1); -- Plague Crash Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189863 WHERE (`Entry`=165410 AND `DifficultyID`=1); -- High Adjudicator Aleez
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=186234 WHERE (`Entry`=165408 AND `DifficultyID`=1); -- Halkias
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191490, `TypeFlags`=0 WHERE (`Entry`=165251 AND `DifficultyID`=1); -- Illusionary Vulpin
UPDATE `creature_template_difficulty` SET `HealthModifier`=20 WHERE (`Entry`=165147 AND `DifficultyID`=1); -- Soulfused Construct
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=185360 WHERE (`Entry`=164852 AND `DifficultyID`=1); -- Regal Mistdancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=164577 AND `DifficultyID`=1); -- Alliance Sparring Partner
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191522 WHERE (`Entry`=164517 AND `DifficultyID`=1); -- Tred'ova
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191486 WHERE (`Entry`=164501 AND `DifficultyID`=1); -- Mistcaller
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189641 WHERE (`Entry`=164363 AND `DifficultyID`=1); -- Undying Stonefiend
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189632 WHERE (`Entry`=164218 AND `DifficultyID`=1); -- Lord Chamberlain
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=188490 WHERE (`Entry`=164185 AND `DifficultyID`=1); -- Echelon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (163746,152703)); -- Walkie Shockie X1
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189918, `TypeFlags`=2097224 WHERE (`Entry`=163077 AND `DifficultyID`=1); -- Azules
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=195493 WHERE (`Entry`=163058 AND `DifficultyID`=1); -- Mistveil Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=162916 AND `DifficultyID`=0) OR (`Entry`=150253 AND `DifficultyID`=1); -- Weaponized Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=162748 AND `DifficultyID`=0); -- Chains of Agony
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=191745 WHERE (`Entry`=162317 AND `DifficultyID`=1); -- Gorechop
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=192396 WHERE (`Entry`=162309 AND `DifficultyID`=1); -- Kul'tharok
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182290 WHERE (`Entry`=162158 AND `DifficultyID`=1); -- Starving Prisoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=162152 AND `DifficultyID`=0); -- Voice of the Corruptor
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189082 WHERE (`Entry`=162100 AND `DifficultyID`=1); -- Kryxis the Voracious
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189926 WHERE (`Entry`=162061 AND `DifficultyID`=1); -- Devos
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189930 WHERE (`Entry`=162060 AND `DifficultyID`=1); -- Oryphrion
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189934 WHERE (`Entry`=162059 AND `DifficultyID`=1); -- Kin-Tara
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=189938 WHERE (`Entry`=162058 AND `DifficultyID`=1); -- Ventunax
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182166 WHERE (`Entry`=162057 AND `DifficultyID`=1); -- Chamber Sentinel
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182154 WHERE (`Entry`=162051 AND `DifficultyID`=1); -- Frenzied Ghoul
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182146 WHERE (`Entry`=162049 AND `DifficultyID`=1); -- Vestige of Doubt
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182141 WHERE (`Entry`=162047 AND `DifficultyID`=1); -- Insatiable Brute
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182126 WHERE (`Entry`=162041 AND `DifficultyID`=1); -- Grubby Dirtcruncher
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182122 WHERE (`Entry`=162040 AND `DifficultyID`=1); -- Grand Overseer
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182118 WHERE (`Entry`=162039 AND `DifficultyID`=1); -- Wicked Oppressor
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=182114 WHERE (`Entry`=162038 AND `DifficultyID`=1); -- Regal Mistdancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161719 AND `DifficultyID`=0); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161520 AND `DifficultyID`=0); -- N'Zoth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161510 AND `DifficultyID`=0); -- Mindrend Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161502 AND `DifficultyID`=0); -- Ravenous Fleshfiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161437 AND `DifficultyID`=0); -- Explosive Scarab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161408 AND `DifficultyID`=0); -- Malicious Growth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161244 AND `DifficultyID`=0); -- Blood of the Corruptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161243 AND `DifficultyID`=0); -- Samh'rek, Beckoner of Chaos
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161241 AND `DifficultyID`=0); -- Voidweaver Mal'thir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161209 AND `DifficultyID`=0); -- Ny'alothan Rift
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (161169,161168)); -- Entropic Spire of Ny'alotha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (161167,161166)); -- Defiled Spire of Ny'alotha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (161164,161163)); -- Cursed Spire of Ny'alotha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161148 AND `DifficultyID`=0); -- Dark Gateway
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (161143,160984)); -- Brutal Spire of Ny'alotha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=161124 AND `DifficultyID`=0); -- Urg'roth, Breaker of Heroes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=160257 AND `DifficultyID`=0); -- Cultist Boss - Azshara Visual Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=160036 AND `DifficultyID`=0); -- Cultist Boss - Arena Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=159861 AND `DifficultyID`=0); -- Ghost Summon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=158111 AND `DifficultyID`=0); -- Trialmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=157900 AND `DifficultyID`=0) OR (`Entry`=153930 AND `DifficultyID`=1); -- Cone Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (156178,143629)) OR (`DifficultyID`=1 AND `Entry`=139963); -- Queen Azshara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155911 AND `DifficultyID`=1) OR (`Entry`=150261 AND `DifficultyID`=0); -- Grease Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155910 AND `DifficultyID`=1); -- Welding Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155909 AND `DifficultyID`=1); -- Shock Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155867 AND `DifficultyID`=0); -- Mechaspider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155775 AND `DifficultyID`=0) OR (`Entry`=153854 AND `DifficultyID`=1); -- Tinkmaster Overspark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155773 AND `DifficultyID`=0) OR (`Entry`=153851 AND `DifficultyID`=1); -- Prince Erazmin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155772 AND `DifficultyID`=0) OR (`Entry`=153853 AND `DifficultyID`=1); -- Gila Crosswires
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (155771,154293)) OR (`DifficultyID`=1 AND `Entry`=153852); -- Gazlowe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155766 AND `DifficultyID`=0); -- Rebuilt Mechagorilla
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155765 AND `DifficultyID`=0); -- Recalibrated Sparkweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155760 AND `DifficultyID`=0); -- Tank Buster MK2
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155645 AND `DifficultyID`=0); -- Walkie Shockie X2
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155595 AND `DifficultyID`=1); -- Sacred Gear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155543 AND `DifficultyID`=1); -- Helpless Critter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155434 AND `DifficultyID`=0); -- Emissary of the Tides
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155433 AND `DifficultyID`=0); -- Void-Touched Emissary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155432 AND `DifficultyID`=0); -- Enchanted Emissary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155405 AND `DifficultyID`=1); -- Clockwork Giant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155402 AND `DifficultyID`=1); -- Bolten Springspark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155401 AND `DifficultyID`=1); -- Repeating Wrenchbot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155400 AND `DifficultyID`=1); -- Knuckles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155399 AND `DifficultyID`=1) OR (`Entry`=150625 AND `DifficultyID`=0); -- Pistonhead Recycler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155398 AND `DifficultyID`=1); -- Flux
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155397 AND `DifficultyID`=1); -- Giddy Gallon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155396 AND `DifficultyID`=1); -- Bondo Bigblock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155394 AND `DifficultyID`=1); -- Stolen Royal Vendorbot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155390 AND `DifficultyID`=1); -- Grizzek Fizzwrench
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155389 AND `DifficultyID`=1); -- Ham
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155388 AND `DifficultyID`=1); -- Sapphronetta Flivvers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155387 AND `DifficultyID`=1); -- Barcinski Keenwatts
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155386 AND `DifficultyID`=1); -- Christy Punchcog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155385 AND `DifficultyID`=1); -- Carlton Corebuilder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155384 AND `DifficultyID`=1); -- Assembler I-Ming
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155383 AND `DifficultyID`=1); -- Ricket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155381 AND `DifficultyID`=1); -- Pascal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155380 AND `DifficultyID`=1); -- Princess Wiggles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155379 AND `DifficultyID`=1); -- Niru Datagear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155378 AND `DifficultyID`=1); -- Smiles Cracklekey
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155376 AND `DifficultyID`=1); -- Hacker Rutledge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155375 AND `DifficultyID`=1); -- Gill the Drill
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155374 AND `DifficultyID`=1); -- Waren Gearhart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155372 AND `DifficultyID`=1); -- Izira Gearsworn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155369 AND `DifficultyID`=1); -- Pristy Quickcharge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155368 AND `DifficultyID`=1); -- Flip Quickcharge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155366 AND `DifficultyID`=1); -- Recycler Kerchunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155364 AND `DifficultyID`=1); -- Rustbolt Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155351 AND `DifficultyID`=0); -- Image of Azshara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (155130,155056)); -- Robo-Waste
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155094 AND `DifficultyID`=1); -- Mechagon Trooper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155090 AND `DifficultyID`=1); -- Anodized Coilbearer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=155066 AND `DifficultyID`=1); -- The Under Junk Furnace
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=154947 AND `DifficultyID`=1); -- Sentry Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (154759,154746,154741)) OR (`DifficultyID`=0 AND `Entry`=153289); -- Squirt Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (154758,154744,150168)); -- Toxic Monstrosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=154671 AND `DifficultyID`=0); -- Toxic Pool
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=154663 AND `DifficultyID`=1); -- Gnome-Eating Droplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=154603 AND `DifficultyID`=1); -- Draw In Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=154351 AND `DifficultyID`=0); -- Shock Beam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153886 AND `DifficultyID`=1); -- Jump Point Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153876 AND `DifficultyID`=1); -- Hacker Bassblast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153803 AND `DifficultyID`=1); -- Mechacycle Charge Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153761 AND `DifficultyID`=1); -- Smoke Cloud Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153756 AND `DifficultyID`=1); -- Mechacycle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153755 AND `DifficultyID`=1); -- Naeno Megacrash
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153736 AND `DifficultyID`=1); -- Begin Detonation Sequence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153386 AND `DifficultyID`=1); -- Toxic Puddle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153377 AND `DifficultyID`=1); -- Goop
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153320 AND `DifficultyID`=1); -- Toxic Wave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153245 AND `DifficultyID`=1); -- Stolen Shock Coil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153235 AND `DifficultyID`=0); -- Mechagon Welder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153222 AND `DifficultyID`=1); -- Disable Furnace Vents
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (153204,153203,153202,145313)); -- Piston Smasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (153196,150547)); -- Scrapbone Grunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=153172 AND `DifficultyID`=1); -- Stolen Scrapbot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152707 AND `DifficultyID`=0); -- Area Denial Bot Tesla Coil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152533 AND `DifficultyID`=0); -- Hunter-Killer - Crawling Static Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152518 AND `DifficultyID`=1); -- Hunter-Killer - Vent Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152514 AND `DifficultyID`=1); -- Defense Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (152482,152481,152473,150125)); -- Magnetocraft
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (152470,144300)); -- Mechagon Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152455 AND `DifficultyID`=1); -- Tussle Tonks Arena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152443 AND `DifficultyID`=0) OR (`Entry`=151659 AND `DifficultyID`=1); -- Rocket Tonk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152442 AND `DifficultyID`=0) OR (`Entry`=151658 AND `DifficultyID`=1); -- Strider Tonk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152438 AND `DifficultyID`=0); -- Seeker of Visions
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152435 AND `DifficultyID`=0) OR (`Entry`=151657 AND `DifficultyID`=1); -- Bomb Tonk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152272 AND `DifficultyID`=1); -- Hunter-Killer - Arena Center Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152160 AND `DifficultyID`=1); -- Spider Tank Tesla Coil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152138 AND `DifficultyID`=1); -- Overcharge Station
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (152137,150397)); -- King Mechagon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152132 AND `DifficultyID`=1); -- Magnetic Coil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152082 AND `DifficultyID`=1); -- Statue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152033 AND `DifficultyID`=1); -- Inconspicuous Plant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152029 AND `DifficultyID`=0) OR (`Entry`=144298 AND `DifficultyID`=1); -- Defense Bot Mk III
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152024 AND `DifficultyID`=0); -- Junker Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152023 AND `DifficultyID`=1); -- Junker Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=152009 AND `DifficultyID`=1); -- Malfunctioning Scrapbot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151930 AND `DifficultyID`=1); -- Furnace Flames
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (151853,151302)); -- Klax-o-Tron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151776 AND `DifficultyID`=1); -- Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151773 AND `DifficultyID`=1); -- Junkyard D.0.G.
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151655 AND `DifficultyID`=1); -- High-Explosive Rocket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151654 AND `DifficultyID`=1); -- Deuce Mecha-Buffer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151649 AND `DifficultyID`=1); -- Defense Bot Mk I
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151648 AND `DifficultyID`=1); -- Tussle Tonks Fanatic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151613 AND `DifficultyID`=1); -- Anti-Personnel Squirrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151579 AND `DifficultyID`=1); -- Shield Generator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151479 AND `DifficultyID`=1); -- Pilot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151478 AND `DifficultyID`=1); -- Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151476 AND `DifficultyID`=1); -- Blastatron X-80
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151325 AND `DifficultyID`=1); -- Alarm-o-Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151282 AND `DifficultyID`=1); -- Room Flush
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151217 AND `DifficultyID`=1); -- Wally
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151168 AND `DifficultyID`=1); -- Annihilo-tron 5000
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=151135 AND `DifficultyID`=1); -- Input Panel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150852 AND `DifficultyID`=1); -- Blade Launcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150769 AND `DifficultyID`=0); -- Trogg Salamander
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150712 AND `DifficultyID`=1); -- Trixie Tazer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150709 AND `DifficultyID`=1); -- Pascal-K1N6
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150694 AND `DifficultyID`=1); -- Wendy Cogsworth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150692 AND `DifficultyID`=1); -- Animated Hand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150654 AND `DifficultyID`=1); -- Rusty Mechaspider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150648 AND `DifficultyID`=1); -- Rustbolt Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150624 AND `DifficultyID`=0); -- Junker Harvester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150586 AND `DifficultyID`=0); -- Trogg Boar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150520 AND `DifficultyID`=1); -- Cubed Clutter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150485 AND `DifficultyID`=1); -- Plasma Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150442 AND `DifficultyID`=1); -- Flying Claw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150396 AND `DifficultyID`=1); -- Aerial Unit R-21/X
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150297 AND `DifficultyID`=1); -- Mechagon Renormalizer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150295 AND `DifficultyID`=1); -- Tank Buster MK1
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150293 AND `DifficultyID`=1); -- Mechagon Prowler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150292 AND `DifficultyID`=1); -- Mechagon Cavalry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150276 AND `DifficultyID`=1); -- Heavy Scrapbot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150255 AND `DifficultyID`=0); -- Junker Jeep
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150254 AND `DifficultyID`=1); -- Scraphound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150251 AND `DifficultyID`=1); -- Pistonhead Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150250 AND `DifficultyID`=1); -- Pistonhead Blaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150249 AND `DifficultyID`=1); -- Pistonhead Scrapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150223 AND `DifficultyID`=0); -- Enslaved Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150222 AND `DifficultyID`=1); -- Gunker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150195 AND `DifficultyID`=1); -- Gnome-Eating Slime
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150194 AND `DifficultyID`=0); -- Slime-Animated Skeleton
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150190 AND `DifficultyID`=1); -- HK-8 Aerial Oppression Unit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150182 AND `DifficultyID`=0) OR (`Entry`=145312 AND `DifficultyID`=1); -- Buzz Saw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150169 AND `DifficultyID`=1); -- Toxic Lurker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150166 AND `DifficultyID`=0) OR (`Entry`=150165 AND `DifficultyID`=1); -- Slime Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150163 AND `DifficultyID`=0); -- Sludge Droplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150160 AND `DifficultyID`=1); -- Scrapbone Bully
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150159 AND `DifficultyID`=1); -- King Gobbamak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150154 AND `DifficultyID`=1); -- Saurolisk Bonenipper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150153 AND `DifficultyID`=0); -- Trogg Mounted Lieutenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150146 AND `DifficultyID`=1); -- Scrapbone Shaman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150143 AND `DifficultyID`=1); -- Scrapbone Grinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=150142 AND `DifficultyID`=1); -- Scrapbone Trashtosser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (150048,86237)) OR (`DifficultyID`=1 AND `Entry` IN (79497,76407)); -- Ner'zhul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (149770,138050)); -- Hook Point Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (149768,141495,138004)) OR (`DifficultyID`=0 AND `Entry` IN (144347,141565,141282)); -- Kul Tiran Footman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=148894 AND `DifficultyID`=0); -- Lost Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=148893 AND `DifficultyID`=0); -- Tormented Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (148716,148439)); -- Risen Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (148714,138148)); -- Bwonsamdi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=146951 AND `DifficultyID`=1); -- Laser Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=146950 AND `DifficultyID`=1); -- Laser Cassis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=145885 AND `DifficultyID`=1); -- Maximum Thrust Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=145854 AND `DifficultyID`=1); -- B.4.T.T.L.3. Bots Arena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=145560 AND `DifficultyID`=1); -- Magneto-Arm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (145506,145503)); -- Discombobulator Beam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=145306 AND `DifficultyID`=0) OR (`Entry`=126841 AND `DifficultyID`=1); -- Sharkbait
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=145185 AND `DifficultyID`=1); -- Gnomercy 4.U.
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144596 AND `DifficultyID`=0); -- Chest o' Booty
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144363,144305,143990,143484,142442)); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144306,133912)); -- Bloodsworn Defiler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144303 AND `DifficultyID`=1); -- G.U.A.R.D.
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144302 AND `DifficultyID`=0); -- Rapid Response Bot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144301 AND `DifficultyID`=1); -- Living Waste
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144299 AND `DifficultyID`=1); -- Workshop Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144297 AND `DifficultyID`=0); -- Mechagon Gyro-Engineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144296 AND `DifficultyID`=1); -- Spider Tank
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144295 AND `DifficultyID`=1); -- Mechagon Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144294 AND `DifficultyID`=1); -- Mechagon Tinkerer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144293 AND `DifficultyID`=1); -- Waste Processing Unit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=156976 WHERE (`Entry`=144286 AND `DifficultyID`=1); -- Asset Manager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144249 AND `DifficultyID`=1); -- Omega Buster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144248 AND `DifficultyID`=1); -- Head Machinist Sparkflux
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144246 AND `DifficultyID`=1); -- K.U.-J.0.
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144244 AND `DifficultyID`=1); -- The Platinum Pummeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144243 AND `DifficultyID`=1); -- Drix Bassbolter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=156919 WHERE (`Entry`=144232 AND `DifficultyID`=1); -- Rowdy Reveler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=156915 WHERE (`Entry`=144231 AND `DifficultyID`=1); -- Rowdy Reveler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144230 AND `DifficultyID`=1); -- Cleanup Stalker [DNT]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144218 AND `DifficultyID`=0); -- G'huun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=159542 WHERE (`Entry`=144171 AND `DifficultyID`=1); -- Taelia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144170,141938,128967)); -- Ashvane Sniper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144169,128969)); -- Ashvane Commander
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144168,137517)); -- Ashvane Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry`=144167) OR (`DifficultyID`=0 AND `Entry` IN (138019,132530,132481)); -- Kul Tiran Vanguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry`=144160) OR (`DifficultyID`=1 AND `Entry` IN (129766,128650)); -- Chopper Redhook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=144158 AND `DifficultyID`=1) OR (`Entry`=128649 AND `DifficultyID`=0); -- Sergeant Bainbridge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (144071,129370)); -- Irontide Waveshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143974 AND `DifficultyID`=1); -- Fireworks!
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143934 AND `DifficultyID`=1); -- Bloodcrazed Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143854 AND `DifficultyID`=0); -- Blightwing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143767 AND `DifficultyID`=0) OR (`Entry`=131670 AND `DifficultyID`=1); -- Heartsbane Vinetwister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143766 AND `DifficultyID`=0); -- Heartsbane Runeweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143693 AND `DifficultyID`=1); -- Snake Statue [DNT]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (143660,143656)) OR (`DifficultyID`=1 AND `Entry` IN (141204,141203,141202,141196)); -- Tidal Surge Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143657 AND `DifficultyID`=1); -- Brine Pool Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143618 AND `DifficultyID`=1); -- Unstable Ordnance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143577 AND `DifficultyID`=1); -- Rezan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143486 AND `DifficultyID`=0); -- Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (143421,138247,135258)); -- Irontide Marauder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143155 AND `DifficultyID`=0) OR (`Entry`=131383 AND `DifficultyID`=1); -- Sporecaller Zancha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=143024 AND `DifficultyID`=0); -- Ancient Trinket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142929 AND `DifficultyID`=1); -- Energy Fragment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142728 AND `DifficultyID`=0); -- Miasma
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142635 AND `DifficultyID`=1); -- Extra-Strength Kaja'Cola
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=153878 WHERE (`Entry`=142625 AND `DifficultyID`=1); -- Ledley the Bold
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142587 AND `DifficultyID`=0); -- Devouring Maggot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142538 AND `DifficultyID`=0); -- Goblin River Boat Crewman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142529 AND `DifficultyID`=0); -- Goblin River Boat Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (142512,141547)); -- Nathanos Blightcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142510 AND `DifficultyID`=0); -- Kul Tiran Houndmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (142486,141497)); -- Jaina Proudmoore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142479 AND `DifficultyID`=1); -- Pirate Corpse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142461 AND `DifficultyID`=0); -- Bored Barkeep
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142460 AND `DifficultyID`=0); -- Haughty Host
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142447 AND `DifficultyID`=1); -- Kul Tiran Executioner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142446 AND `DifficultyID`=0); -- Harbor Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142445 AND `DifficultyID`=0); -- Donald Harris
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142443 AND `DifficultyID`=0); -- Allison Weber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142441 AND `DifficultyID`=0); -- Katherine Proudmoore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=142293 AND `DifficultyID`=1) OR (`Entry`=141284 AND `DifficultyID`=0); -- Kul Tiran Wavetender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141978 AND `DifficultyID`=1); -- Vig'Goth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (141939,138255,136665,135263)) OR (`DifficultyID`=0 AND `Entry`=135413); -- Ashvane Spotter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141929 AND `DifficultyID`=0); -- Wise Tu'aka
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141896 AND `DifficultyID`=0); -- Lady Ha'ti
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141890 AND `DifficultyID`=0); -- Lord Azi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141851 AND `DifficultyID`=0); -- Spawn of G'huun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141834 AND `DifficultyID`=1) OR (`Entry`=141805 AND `DifficultyID`=0); -- Threshanator 3000
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141827 AND `DifficultyID`=1); -- Worn Auto Hammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141825 AND `DifficultyID`=1); -- Strange Vile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141806 AND `DifficultyID`=0); -- Malfunctioning Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141800 AND `DifficultyID`=0); -- Brutik Blackanvil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141792 AND `DifficultyID`=0); -- Liz Vilepot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141639 AND `DifficultyID`=0); -- Ryla Sunwalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141637 AND `DifficultyID`=0); -- Krowl Darkmane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141636 AND `DifficultyID`=0); -- Alaria Nightwind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141635 AND `DifficultyID`=0); -- Fiz Silvercog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141634 AND `DifficultyID`=0); -- Olson Brightshield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141633 AND `DifficultyID`=1); -- Mance Sunfury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141631 AND `DifficultyID`=1); -- Boro Ironhoof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141629 AND `DifficultyID`=1); -- Zuwana Vileblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141627 AND `DifficultyID`=1); -- Blix Rocketspark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141625 AND `DifficultyID`=1); -- Thrak Ironfang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (141591,141589,136631)) OR (`DifficultyID`=1 AND `Entry`=136630); -- Tara Swiftblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (141566,138278)) OR (`DifficultyID`=1 AND `Entry` IN (138002,133990)); -- Scrimshaw Gutter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry`=141532) OR (`DifficultyID`=1 AND `Entry` IN (138464,136483)); -- Ashvane Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141496 AND `DifficultyID`=0) OR (`Entry`=136724 AND `DifficultyID`=1); -- Priscilla Ashvane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (141493,136692)); -- Taelia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (141285,132532,132491)); -- Kul Tiran Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141283 AND `DifficultyID`=0); -- Kul Tiran Halberd
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141160 AND `DifficultyID`=1); -- Catalyst Pipe Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141100 AND `DifficultyID`=0); -- Untainted Spirit Pterrodax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141086 AND `DifficultyID`=0); -- Untainted Spirit Guide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (141041,141028)); -- Void Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (141016,140999)) OR (`DifficultyID`=0 AND `Entry`=140967); -- Shrine's Breath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=141005 AND `DifficultyID`=0); -- Foot Scorcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140775 AND `DifficultyID`=0); -- Resonant Pillar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140753 AND `DifficultyID`=0); -- Mysterious Spore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140593 AND `DifficultyID`=0); -- Restless Horror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140535 AND `DifficultyID`=1); -- Banana Trap Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (140447,137626,137625,137614)); -- Demolishing Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140319 AND `DifficultyID`=1); -- Hobart Grapplehammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140145 AND `DifficultyID`=1); -- Mature Krolusk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140144 AND `DifficultyID`=1); -- Idler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140138 AND `DifficultyID`=1); -- Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140136 AND `DifficultyID`=1); -- Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140123 AND `DifficultyID`=0); -- Weaponmaster Halu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140119 AND `DifficultyID`=1); -- Scaled Krolusk Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140038 AND `DifficultyID`=1); -- Abyssal Eel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140037 AND `DifficultyID`=1); -- Blessed Tidesage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=140036 AND `DifficultyID`=1); -- Abyssal Channeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139986 AND `DifficultyID`=1); -- Shrine of the Storm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139971 AND `DifficultyID`=1); -- Rexxar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139970 AND `DifficultyID`=1); -- Brother Pike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146817 WHERE (`Entry`=139949 AND `DifficultyID`=1); -- Plague Doctor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146811 WHERE (`Entry`=139946 AND `DifficultyID`=1); -- Heart Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139830 AND `DifficultyID`=1); -- Kul Tiran Engineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139800 AND `DifficultyID`=1); -- Galecaller Apprentice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139799 AND `DifficultyID`=1); -- Ironhull Apprentice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (139778,139733)); -- Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (139737,134060)); -- Lord Stormsong
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139626 AND `DifficultyID`=1); -- Dredged Sailor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139581 AND `DifficultyID`=0) OR (`Entry`=139572 AND `DifficultyID`=1); -- Murky Water
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139553 AND `DifficultyID`=1); -- Siege Cannon Bombardment Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146251 WHERE (`Entry`=139425 AND `DifficultyID`=1); -- Crazed Incubator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146245 WHERE (`Entry`=139422 AND `DifficultyID`=1); -- Scaled Krolusk Tamer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139308 AND `DifficultyID`=0); -- Snake Eater
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139300 AND `DifficultyID`=0); -- Solid Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (139277,139276,139247,139246,136687,133003)); -- Dread Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139244 AND `DifficultyID`=0); -- Submerge Visual Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146043 WHERE (`Entry`=139194 AND `DifficultyID`=1); -- Rotmaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (139163,136154,135336)) OR (`DifficultyID`=0 AND `Entry`=135060); -- Eye of Sethraliss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139160 AND `DifficultyID`=0) OR (`Entry`=136975 AND `DifficultyID`=1); -- Heavy Ordnance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145915 WHERE (`Entry`=139131 AND `DifficultyID`=1); -- Polarized Spire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139127 AND `DifficultyID`=0); -- Volatile Pod
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145891 WHERE (`Entry`=139110 AND `DifficultyID`=1); -- Spark Channeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139109 AND `DifficultyID`=1); -- Spiderling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (139108,136108)); -- Loose Spark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146444 WHERE (`Entry`=139097 AND `DifficultyID`=1); -- Sandswept Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=139055 AND `DifficultyID`=0) OR (`Entry`=136696 AND `DifficultyID`=1); -- Proudmoore Elite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138975 AND `DifficultyID`=1); -- Kultiran Corpse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138950 AND `DifficultyID`=1) OR (`Entry`=138087 AND `DifficultyID`=0); -- Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138740 AND `DifficultyID`=1); -- Musashitake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138719 AND `DifficultyID`=0); -- Serve Sharkbait's Meal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138718 AND `DifficultyID`=1); -- Sharkbait's Empty Dish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138705 AND `DifficultyID`=1); -- Gourmet Parrot Chow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145434 WHERE (`Entry`=138676 AND `DifficultyID`=1); -- Bilge Rat Party Animal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138538 AND `DifficultyID`=1); -- Abyssal Reach
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (138493,133943)); -- Minion of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (138489,137020)); -- Shadow of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (138465,136549)); -- Ashvane Cannoneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138463 AND `DifficultyID`=1); -- Whirlpool of Blades
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145086 WHERE (`Entry`=138369 AND `DifficultyID`=1); -- Footbomb Hooligan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (138368,138325)); -- Iron Volley Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=145081 WHERE (`Entry`=138367 AND `DifficultyID`=1); -- Whiskey Stevo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (138338,133836)); -- Reanimated Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138314 AND `DifficultyID`=0); -- Patches
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138281 AND `DifficultyID`=1); -- Faceless Corruptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (138254,137521,129989,129928)); -- Irontide Powdershot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138250 AND `DifficultyID`=0); -- Pool of Darkness
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138187 AND `DifficultyID`=1); -- Grotesque Horror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138120 AND `DifficultyID`=1); -- City Pup
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138119 AND `DifficultyID`=1); -- Stablehand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138083 AND `DifficultyID`=0) OR (`Entry`=137926 AND `DifficultyID`=1); -- Pile of Gold
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144774 WHERE (`Entry`=138082 AND `DifficultyID`=1); -- Belligerent Supporter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144754 WHERE (`Entry`=138068 AND `DifficultyID`=1); -- Posh Vacationer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144749 WHERE (`Entry`=138066 AND `DifficultyID`=1); -- Posh Vacationer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144744 WHERE (`Entry`=138064 AND `DifficultyID`=1); -- Posh Vacationer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144740 WHERE (`Entry`=138063 AND `DifficultyID`=1); -- Posh Vacationer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144735 WHERE (`Entry`=138061 AND `DifficultyID`=1); -- Venture Co. Longshoreman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138057 AND `DifficultyID`=1); -- Oil Spew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138054 AND `DifficultyID`=1); -- Venture Co. Jalopy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138053 AND `DifficultyID`=1); -- Stalled Trike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138052 AND `DifficultyID`=1); -- Jump Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138049 AND `DifficultyID`=0) OR (`Entry`=138047 AND `DifficultyID`=1); -- Razdunk's Ride
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138046 AND `DifficultyID`=1); -- Boralus Civilian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138035 AND `DifficultyID`=1); -- Patrick Markson
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=138034 AND `DifficultyID`=1); -- Sara Bartlett
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137996 AND `DifficultyID`=1); -- Black Powder Special Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (137994,136776)); -- Mine Cart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137991 AND `DifficultyID`=1); -- Mining Charge Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137989 AND `DifficultyID`=0); -- Embalming Fluid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137969 AND `DifficultyID`=0); -- Interment Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137942 AND `DifficultyID`=0); -- Test Missile Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144572 WHERE (`Entry`=137940 AND `DifficultyID`=1); -- Safety Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137879 AND `DifficultyID`=0); -- Lost Relic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137876 AND `DifficultyID`=0); -- Tear Gas Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137857 AND `DifficultyID`=0); -- Krolusk Larva
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137805 AND `DifficultyID`=1); -- Black Blood
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137801 AND `DifficultyID`=0); -- Cleansing Font
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137772 AND `DifficultyID`=0); -- Portal to Gorak Tul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144521 WHERE (`Entry`=137716 AND `DifficultyID`=1); -- Bottom Feeder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144518 WHERE (`Entry`=137713 AND `DifficultyID`=1); -- Big Money Crab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137652 AND `DifficultyID`=0); -- Untainted Guard Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137651 AND `DifficultyID`=0); -- Untainted Priest Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137650 AND `DifficultyID`=0); -- Untainted Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137641 AND `DifficultyID`=1); -- Crimsonwood Kit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137627 AND `DifficultyID`=0); -- Constricting Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137623 AND `DifficultyID`=1); -- Teleport Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137591 AND `DifficultyID`=0); -- Healing Tide Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137589 AND `DifficultyID`=0); -- Dinoling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137588 AND `DifficultyID`=1); -- Gasping Flounder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137516 AND `DifficultyID`=1); -- Ashvane Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137515 AND `DifficultyID`=0); -- Quest 3
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137514 AND `DifficultyID`=0); -- Quest 2
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137513 AND `DifficultyID`=1); -- Drill Smash Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137512 AND `DifficultyID`=0); -- Quest 1
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137511 AND `DifficultyID`=1); -- Bilge Rat Cutthroat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137493 AND `DifficultyID`=0); -- Call of the Deep Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137490 AND `DifficultyID`=0); -- Ravenous Eel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137487 AND `DifficultyID`=0); -- Skeletal Hunting Raptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137486 AND `DifficultyID`=0); -- Queen Patlaa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137485 AND `DifficultyID`=0); -- Bloodsworn Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137484 AND `DifficultyID`=0); -- King A'akul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137478 AND `DifficultyID`=0); -- Queen Wasi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137474 AND `DifficultyID`=0); -- King Timalji
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137473 AND `DifficultyID`=0); -- Guard Captain Atu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137458 AND `DifficultyID`=1); -- Rotting Spore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137456 AND `DifficultyID`=1) OR (`Entry`=131015 AND `DifficultyID`=0); -- Azerite Catalyst Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137452 AND `DifficultyID`=1); -- Spray Sessile Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (137437,137425)) OR (`DifficultyID`=1 AND `Entry`=137405); -- Gripping Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137396 AND `DifficultyID`=0); -- Repair Parts
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143699 WHERE (`Entry`=137233 AND `DifficultyID`=1); -- Plague Toad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143667 WHERE (`Entry`=137204 AND `DifficultyID`=1); -- Hoodoo Hexer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137143 AND `DifficultyID`=1); -- Sunken Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (137123,133599)); -- Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137118 AND `DifficultyID`=1); -- Broken Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137103 AND `DifficultyID`=1); -- Blood Visage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137101 AND `DifficultyID`=0); -- Disciple of Vol'zith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137098 AND `DifficultyID`=0); -- Liskorath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137093 AND `DifficultyID`=1); -- Thrashing Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137051 AND `DifficultyID`=1); -- Ancient Mindbender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=137036 AND `DifficultyID`=1); -- Awoken Void
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144560 WHERE (`Entry`=137029 AND `DifficultyID`=1); -- Ordnance Specialist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136984 AND `DifficultyID`=0); -- Reban
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136976 AND `DifficultyID`=0); -- T'zala
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136961 AND `DifficultyID`=1); -- Waken the Void
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136952 AND `DifficultyID`=0); -- Force Cannon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136945 AND `DifficultyID`=0); -- Corvus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144605 WHERE (`Entry`=136934 AND `DifficultyID`=1); -- Weapons Tester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136913 AND `DifficultyID`=0); -- Goo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136899 AND `DifficultyID`=1); -- Dread Boat Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136795 AND `DifficultyID`=0); -- Spear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136737 AND `DifficultyID`=1); -- Innocent Commoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (136735,130027)); -- Ashvane Marine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136698 AND `DifficultyID`=0); -- Dark Ranger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144587 WHERE (`Entry`=136688 AND `DifficultyID`=1); -- Fanatical Driller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144515 WHERE (`Entry`=136643 AND `DifficultyID`=1); -- Azerite Extractor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136637 AND `DifficultyID`=1); -- Mining Charge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136541 AND `DifficultyID`=0); -- Bile Oozeling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=149065 WHERE (`Entry`=136539 AND `DifficultyID`=1); -- Booty Fanatic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136513 AND `DifficultyID`=1); -- The Rockchain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136505 AND `DifficultyID`=1); -- Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry`=136500) OR (`DifficultyID`=1 AND `Entry` IN (129883,129804)); -- Fracking Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136484 AND `DifficultyID`=0); -- Drust Death Lens Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144563 WHERE (`Entry`=136470 AND `DifficultyID`=1); -- Refreshment Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136460 AND `DifficultyID`=1); -- Dread Ship
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136436 AND `DifficultyID`=0); -- Burning Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142697 WHERE (`Entry`=136391 AND `DifficultyID`=1); -- Heart Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136363 AND `DifficultyID`=1); -- Jellyfish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136353 AND `DifficultyID`=1); -- Colossal Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136347 AND `DifficultyID`=1); -- Tidesage Initiate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142614 WHERE (`Entry`=136319 AND `DifficultyID`=1); -- Center Jewel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136314 AND `DifficultyID`=0); -- Blowback
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (136297,136083)); -- Forgotten Denizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (136295,136100)); -- Sunken Denizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136291 AND `DifficultyID`=1); -- Statue Eyes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142553 WHERE (`Entry`=136266 AND `DifficultyID`=1); -- Defense Ward
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136264 AND `DifficultyID`=0); -- Half-Finished Mummy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136256 AND `DifficultyID`=0); -- Coffin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142535 WHERE (`Entry`=136251 AND `DifficultyID`=1); -- Grounding Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142531 WHERE (`Entry`=136250 AND `DifficultyID`=1); -- Hoodoo Hexer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136249 AND `DifficultyID`=1); -- Guardian Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136214 AND `DifficultyID`=1); -- Windspeaker Heldis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136188 AND `DifficultyID`=1); -- Bound Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136186 AND `DifficultyID`=1); -- Tidesage Spiritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136160 AND `DifficultyID`=0); -- King Dazar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144545 WHERE (`Entry`=136139 AND `DifficultyID`=1); -- Mechanized Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136135 AND `DifficultyID`=1); -- Dice Dealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136111 AND `DifficultyID`=0); -- Talking Head Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136107 AND `DifficultyID`=1); -- Piece of Eight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136098 AND `DifficultyID`=0); -- Hastily Buried Treasure
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136095 AND `DifficultyID`=0); -- Secret Treasure Map
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136089 AND `DifficultyID`=0); -- Sethrak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=136078 AND `DifficultyID`=0); -- High Quality Shovel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143150 WHERE (`Entry`=136076 AND `DifficultyID`=1); -- Agitated Nimbus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144566 WHERE (`Entry`=136006 AND `DifficultyID`=1); -- Rowdy Reveler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144569 WHERE (`Entry`=136005 AND `DifficultyID`=1); -- Rowdy Reveler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135989,127879)); -- Shieldbearer of Zul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135987 AND `DifficultyID`=1); -- Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135978 AND `DifficultyID`=1); -- Bilge Rat Grog Jerk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144554 WHERE (`Entry`=135975 AND `DifficultyID`=1); -- Off-Duty Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142224 WHERE (`Entry`=135971 AND `DifficultyID`=1); -- Faithless Conscript
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135942 AND `DifficultyID`=0); -- Bilge Rat Padfoot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135938 AND `DifficultyID`=1); -- Bilge Rat Party Animal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135903 AND `DifficultyID`=0); -- Manifestation of the Deep
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142095 WHERE (`Entry`=135849 AND `DifficultyID`=1); -- Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142089 WHERE (`Entry`=135846 AND `DifficultyID`=1); -- Sand-Crusted Striker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135820 AND `DifficultyID`=0) OR (`Entry`=134572 AND `DifficultyID`=1); -- Merektha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135779,135699)); -- Ashvane Jailer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135765 AND `DifficultyID`=0); -- Torrent Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135764 AND `DifficultyID`=0); -- Explosive Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135761 AND `DifficultyID`=0); -- Thundering Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135759 AND `DifficultyID`=0); -- Earthwall Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135734 AND `DifficultyID`=0); -- Fog Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135707 AND `DifficultyID`=0); -- Flynn Fairwind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135706,127485)); -- Bilge Rat Looter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=141864 WHERE (`Entry`=135641 AND `DifficultyID`=1); -- Heart of Sethraliss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (135636,135634,135630,135628)); -- Horde Hostage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135635,135633,135629,135624)); -- Alliance Hostage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135573 AND `DifficultyID`=0); -- Taloc
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135563 AND `DifficultyID`=0); -- Dread Manifestation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=141772 WHERE (`Entry`=135562 AND `DifficultyID`=1); -- Venomous Ophidian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=141767 WHERE (`Entry`=135560 AND `DifficultyID`=1); -- Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135535,127479)); -- The Sand Queen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135475 AND `DifficultyID`=0); -- Kula the Butcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135472 AND `DifficultyID`=0); -- Zanazal the Wise
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135470 AND `DifficultyID`=0); -- Aka'ali the Conqueror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135451 AND `DifficultyID`=0); -- Filthy Bucket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135448 AND `DifficultyID`=0); -- Gol'than the Malodorous
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=158755 WHERE (`Entry`=135445 AND `DifficultyID`=1); -- Energy Core
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135406 AND `DifficultyID`=0); -- Animated Gold
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135366 AND `DifficultyID`=1); -- Blacktooth Arsonist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135322 AND `DifficultyID`=0); -- The Golden Serpent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135289 AND `DifficultyID`=1); -- Ashvane Trainee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135273 AND `DifficultyID`=0); -- Invisible Stalker (Scale x0.5)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135265 AND `DifficultyID`=1); -- Foraging Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (135254,130087,129369)); -- Irontide Raider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135251 AND `DifficultyID`=0); -- First Guard Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135245 AND `DifficultyID`=1); -- Bilge Rat Demolisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135241 AND `DifficultyID`=1); -- Bilge Rat Pillager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135239 AND `DifficultyID`=0); -- Spectral Witch Doctor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135237 AND `DifficultyID`=0); -- Ash Pile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135235 AND `DifficultyID`=0); -- Spectral Beastmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135231 AND `DifficultyID`=0); -- Spectral Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135219 AND `DifficultyID`=1); -- Befouled Spirit Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135204 AND `DifficultyID`=0); -- Spectral Hex Priest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135195 AND `DifficultyID`=0); -- Drustvar Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135192 AND `DifficultyID`=0); -- Honored Raptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135178 AND `DifficultyID`=1); -- Rotten Bile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135169 AND `DifficultyID`=1); -- Spirit Drain Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135167 AND `DifficultyID`=0); -- Spectral Berserker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135052 AND `DifficultyID`=1); -- Blight Toad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143120 WHERE (`Entry`=135007 AND `DifficultyID`=1); -- Orb Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=135005 AND `DifficultyID`=0); -- Entangler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134994 AND `DifficultyID`=0); -- Spectral Headhunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134993 AND `DifficultyID`=0); -- Mchimba the Embalmer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143098 WHERE (`Entry`=134991 AND `DifficultyID`=1); -- Sandfury Stonefist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143101 WHERE (`Entry`=134990 AND `DifficultyID`=1); -- Charged Dust Devil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134828 AND `DifficultyID`=1); -- Aqualing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134739 AND `DifficultyID`=0); -- Purification Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134732 AND `DifficultyID`=0); -- Desiccation Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134714 AND `DifficultyID`=1); -- Static-charged Dervish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134701 AND `DifficultyID`=1); -- Blood Effigy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143141 WHERE (`Entry`=134691 AND `DifficultyID`=1); -- Static-charged Dervish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143138 WHERE (`Entry`=134686 AND `DifficultyID`=1); -- Mature Krolusk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146999 WHERE (`Entry`=134629 AND `DifficultyID`=1); -- Scaled Krolusk Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134617 AND `DifficultyID`=1); -- Krolusk Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143132 WHERE (`Entry`=134616 AND `DifficultyID`=1); -- Krolusk Pup
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134612 AND `DifficultyID`=0); -- Grasping Tentacles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143095 WHERE (`Entry`=134600 AND `DifficultyID`=1); -- Sandswept Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142370 WHERE (`Entry`=134599 AND `DifficultyID`=1); -- Imbued Stormcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140621 WHERE (`Entry`=134517 AND `DifficultyID`=1); -- Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140617 WHERE (`Entry`=134516 AND `DifficultyID`=1); -- Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134514 AND `DifficultyID`=1); -- Abyssal Cultist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146045 WHERE (`Entry`=134487 AND `DifficultyID`=1); -- Merektha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134424 AND `DifficultyID`=0); -- Waterfall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134423 AND `DifficultyID`=1); -- Abyss Dweller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134419 AND `DifficultyID`=1); -- Titan Keeper Hezrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134418 AND `DifficultyID`=1); -- Drowned Depthbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134417 AND `DifficultyID`=1); -- Deepsea Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140519 WHERE (`Entry`=134390 AND `DifficultyID`=1); -- Sand-crusted Striker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140522 WHERE (`Entry`=134389 AND `DifficultyID`=1); -- Venomous Ophidian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140528 WHERE (`Entry`=134378 AND `DifficultyID`=1); -- Egg Marker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140531 WHERE (`Entry`=134364 AND `DifficultyID`=1); -- Faithless Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134338 AND `DifficultyID`=1); -- Tidesage Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134331 AND `DifficultyID`=0); -- King Rahu'ai
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134284 AND `DifficultyID`=1); -- Fallen Deathspeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134273 AND `DifficultyID`=0); -- Shambling Horror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134268 AND `DifficultyID`=0); -- Fungal Spore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134251 AND `DifficultyID`=0); -- Seneschal M'bara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144539 WHERE (`Entry`=134232 AND `DifficultyID`=1); -- Hired Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134184 AND `DifficultyID`=0); -- Rotten Food
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (134182,134179)); -- Enchanted Mask
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134174 AND `DifficultyID`=0); -- Shadow-Borne Witch Doctor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134173 AND `DifficultyID`=1); -- Animated Droplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134158 AND `DifficultyID`=0); -- Shadow-Borne Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134157 AND `DifficultyID`=0); -- Shadow-Borne Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134154 AND `DifficultyID`=0); -- Gluttonous Worm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134150 AND `DifficultyID`=1); -- Runecarver Sorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134144 AND `DifficultyID`=1); -- Living Current
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134139 AND `DifficultyID`=1); -- Shrine Templar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134137 AND `DifficultyID`=1); -- Temple Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134115 AND `DifficultyID`=0); -- Sacrificial Acolyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134112 AND `DifficultyID`=0); -- Matron Christiane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134102 AND `DifficultyID`=0); -- Locust Swarm Generator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134100 AND `DifficultyID`=0); -- Locust Swarm Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134097 AND `DifficultyID`=0); -- Swarming Locust
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134069 AND `DifficultyID`=1); -- Vol'zith the Whisperer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134063 AND `DifficultyID`=1); -- Brother Ironhull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134058 AND `DifficultyID`=1); -- Galecaller Faye
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134056 AND `DifficultyID`=1); -- Aqu'sirr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (134025,133972)); -- Heavy Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=134021 AND `DifficultyID`=1); -- Revitalizing Brew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144524 WHERE (`Entry`=134012 AND `DifficultyID`=1); -- Taskmaster Askari
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144575 WHERE (`Entry`=134005 AND `DifficultyID`=1); -- Shalebiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133978 AND `DifficultyID`=0); -- Stonespike Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144581 WHERE (`Entry`=133963 AND `DifficultyID`=1); -- Test Subject
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140423 WHERE (`Entry`=133944 AND `DifficultyID`=1); -- Aspix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133935 AND `DifficultyID`=0); -- Animated Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133870 AND `DifficultyID`=1); -- Diseased Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133852 AND `DifficultyID`=1); -- Living Rot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133835 AND `DifficultyID`=1); -- Feral Bloodswarmer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133817 AND `DifficultyID`=0); -- Unbound Wraith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133753 AND `DifficultyID`=1); -- Leech Globule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133685 AND `DifficultyID`=1); -- Befouled Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133663 AND `DifficultyID`=1); -- Fanatical Headhunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133642 AND `DifficultyID`=0); -- Skeletal Headhunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133636 AND `DifficultyID`=1); -- Flames
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133605 AND `DifficultyID`=0); -- Escaped Convict
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133597 AND `DifficultyID`=0); -- Tiragarde Barracuda
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144527 WHERE (`Entry`=133593 AND `DifficultyID`=1); -- Expert Technician
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133573 AND `DifficultyID`=0); -- Spotlight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133482 AND `DifficultyID`=1); -- Crawler Mine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144599 WHERE (`Entry`=133463 AND `DifficultyID`=1); -- Venture Co. War Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144596 WHERE (`Entry`=133436 AND `DifficultyID`=1); -- Venture Co. Skyscorcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144584 WHERE (`Entry`=133432 AND `DifficultyID`=1); -- Venture Co. Alchemist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144593 WHERE (`Entry`=133430 AND `DifficultyID`=1); -- Venture Co. Mastermind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140534 WHERE (`Entry`=133392 AND `DifficultyID`=1); -- Avatar of Sethraliss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140537 WHERE (`Entry`=133389 AND `DifficultyID`=1); -- Galvazzt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140504 WHERE (`Entry`=133384 AND `DifficultyID`=1); -- Merektha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=140426 WHERE (`Entry`=133379 AND `DifficultyID`=1); -- Adderis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133361 AND `DifficultyID`=1); -- Wasting Servant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144530 WHERE (`Entry`=133345 AND `DifficultyID`=1); -- Feckless Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133219 AND `DifficultyID`=0); -- Rummy Mancomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=133007 AND `DifficultyID`=1); -- Unbound Abomination
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132713 AND `DifficultyID`=1); -- Mogul Razdunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132626 AND `DifficultyID`=0); -- Reality Tear Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (132586,132581)); -- Kul Tiran Grappleshot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (132585,129937)); -- Irontide Grappleshot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132550 AND `DifficultyID`=0); -- Grapple Rifle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132398 AND `DifficultyID`=1); -- Blood Wave Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132338 AND `DifficultyID`=1); -- Homing Missile Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132271 AND `DifficultyID`=1); -- Micro Missile Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132258 AND `DifficultyID`=1); -- Center Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132137 AND `DifficultyID`=1); -- Cosmetic Blood Tick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132126 AND `DifficultyID`=1); -- Gilded Priestess
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132080 AND `DifficultyID`=1); -- Blood Tick Larva
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144509 WHERE (`Entry`=132056 AND `DifficultyID`=1); -- Venture Co. Skyscorcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132053 AND `DifficultyID`=0); -- Book of Binding
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132051 AND `DifficultyID`=1); -- Blood Tick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=132013 AND `DifficultyID`=0); -- Strafing Run Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131973 AND `DifficultyID`=1); -- Big Red Rocket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131924 AND `DifficultyID`=0); -- Propellant Blast Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131887 AND `DifficultyID`=0); -- Hanging Man
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131856 AND `DifficultyID`=1); -- Ashvane Quartermaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131818 AND `DifficultyID`=1); -- Marked Sister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131817 AND `DifficultyID`=1); -- Cragmaw the Infested
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131788 AND `DifficultyID`=0) OR (`Entry`=131597 AND `DifficultyID`=1); -- Spore Pod
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131785 AND `DifficultyID`=0); -- Buzzing Drone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131762 AND `DifficultyID`=0); -- Delicious Chicken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131742 AND `DifficultyID`=0); -- Cooked Chicken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131732 AND `DifficultyID`=0); -- Raw Chicken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131731 AND `DifficultyID`=0); -- Sown Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131611 AND `DifficultyID`=0); -- Roast Chef Rhonda
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131607 AND `DifficultyID`=0); -- Sauciere Samuel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131601 AND `DifficultyID`=0); -- Executive Chef Daniel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131588 AND `DifficultyID`=0); -- Mindless Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131492 AND `DifficultyID`=1); -- Devout Blood Priest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (131445,131444)); -- Block Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131436 AND `DifficultyID`=1); -- Chosen Blood Matron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131402 AND `DifficultyID`=1); -- Underrot Tick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131318 AND `DifficultyID`=1); -- Elder Leaxa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131289 AND `DifficultyID`=1); -- Shadowflame
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=0 AND `Entry` IN (131123,131119)); -- Enchanted Tiki Mask
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131112 AND `DifficultyID`=1); -- Cutwater Striker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=131089 AND `DifficultyID`=0) OR (`Entry`=122970 AND `DifficultyID`=1); -- Shadowblade Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130945 AND `DifficultyID`=0); -- Spray Fixate Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130912 AND `DifficultyID`=0); -- Shadowblade Razi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130909 AND `DifficultyID`=1); -- Fetid Maggot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130903 AND `DifficultyID`=0) OR (`Entry`=130902 AND `DifficultyID`=1); -- Creepy Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=235014 WHERE (`Entry`=130896 AND `DifficultyID`=1); -- Blackout Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=155165 WHERE (`Entry`=130850 AND `DifficultyID`=1); -- Irontide Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130686 AND `DifficultyID`=1); -- Mountaintop Croaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130681 AND `DifficultyID`=1); -- Glitterlight Flitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130680 AND `DifficultyID`=1); -- Goldshell Scuttler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130679 AND `DifficultyID`=1); -- Temple Snake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130678 AND `DifficultyID`=1); -- Poisonous Gekkota
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144590 WHERE (`Entry`=130661 AND `DifficultyID`=1); -- Venture Co. Earthshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130655 AND `DifficultyID`=0); -- Bobby Howlis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144602 WHERE (`Entry`=130653 AND `DifficultyID`=1); -- Wanton Sapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144578 WHERE (`Entry`=130635 AND `DifficultyID`=1); -- Stonefury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130597 AND `DifficultyID`=0) OR (`Entry`=129985 AND `DifficultyID`=1); -- Tiki Mask
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130582 AND `DifficultyID`=1); -- Despondent Scallywag
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130536 AND `DifficultyID`=1); -- Freehold Jail
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146640 WHERE (`Entry`=130522 AND `DifficultyID`=1); -- Freehold Shipmate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (130521,127119)); -- Freehold Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144542 WHERE (`Entry`=130488 AND `DifficultyID`=1); -- Mech Jockey
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144548 WHERE (`Entry`=130485 AND `DifficultyID`=1); -- Mechanized Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130467 AND `DifficultyID`=1); -- Murphy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130438 AND `DifficultyID`=0); -- Venture Co. Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144551 WHERE (`Entry`=130437 AND `DifficultyID`=1); -- Mine Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144557 WHERE (`Entry`=130436 AND `DifficultyID`=1); -- Off-Duty Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144512 WHERE (`Entry`=130435 AND `DifficultyID`=1); -- Addled Thug
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=136059 WHERE (`Entry`=130404 AND `DifficultyID`=1); -- Vermin Trapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130400 AND `DifficultyID`=1); -- Irontide Crusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130353 AND `DifficultyID`=0); -- Smoldering Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130207 AND `DifficultyID`=1); -- Enchanted Brine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130172 AND `DifficultyID`=1); -- Ken "the Pig Thrower"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130157 AND `DifficultyID`=1); -- Shell Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130155 AND `DifficultyID`=0); -- Shell Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130153 AND `DifficultyID`=0); -- Venomspine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130152 AND `DifficultyID`=0); -- Dehydrated Venomspine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130150 AND `DifficultyID`=0); -- Crashing Wave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130099 AND `DifficultyID`=1); -- Lightning
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130090 AND `DifficultyID`=1); -- Gukguk "The Motivator"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130086 AND `DifficultyID`=1); -- Davey "Two Eyes"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130028 AND `DifficultyID`=1); -- Ashvane Priest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130026 AND `DifficultyID`=1); -- Bilge Rat Seaspeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=130025 AND `DifficultyID`=1); -- Irontide Thug
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=136241 WHERE (`Entry`=130024 AND `DifficultyID`=1); -- Soggy Shiprat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135784 WHERE (`Entry`=130012 AND `DifficultyID`=1); -- Irontide Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135744 WHERE (`Entry`=130011 AND `DifficultyID`=1); -- Irontide Buccaneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (129996,129879)); -- Irontide Cleaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129939 AND `DifficultyID`=0); -- Mug of Caustic Grog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129859 AND `DifficultyID`=0); -- Cutwater Wake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (129825,82472)) OR (`DifficultyID`=1 AND `Entry` IN (80940,79888)); -- Iron Infantry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (129824,79878)) OR (`DifficultyID`=1 AND `Entry` IN (80935,79720)); -- Grom'kar Boomer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (129823,79877)) OR (`DifficultyID`=1 AND `Entry` IN (80936,79739)); -- Grom'kar Grenadier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (129822,79819)) OR (`DifficultyID`=1 AND `Entry` IN (80937,77483)); -- Grom'kar Gunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144497 WHERE (`Entry`=129802 AND `DifficultyID`=1); -- Earthrager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129797 AND `DifficultyID`=0); -- Snipe Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142997 WHERE (`Entry`=129788 AND `DifficultyID`=1); -- Irontide Bonesaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129785 AND `DifficultyID`=0); -- Suppression Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129765 AND `DifficultyID`=1); -- Meat Hook Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=136356 WHERE (`Entry`=129758 AND `DifficultyID`=1); -- Irontide Grenadier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=155049 WHERE (`Entry`=129747 AND `DifficultyID`=1); -- Swiftwind Saber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143003 WHERE (`Entry`=129743 AND `DifficultyID`=1); -- Sharkbait
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=143000 WHERE (`Entry`=129732 AND `DifficultyID`=1); -- Skycap'n Kragg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129699 AND `DifficultyID`=1); -- Ludwig Von Tortollan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (129697,129437)); -- Munitions Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129673 AND `DifficultyID`=1); -- Stevin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129645 AND `DifficultyID`=1); -- Gryff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129640 AND `DifficultyID`=1); -- Snarling Dockhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142994 WHERE (`Entry`=129602 AND `DifficultyID`=1); -- Irontide Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129601 AND `DifficultyID`=1); -- Cutwater Harpooner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129600 AND `DifficultyID`=1); -- Bilge Rat Brinescale
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129599 AND `DifficultyID`=1); -- Cutwater Knife Juggler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129598 AND `DifficultyID`=1); -- Freehold Pack Mule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=146637 WHERE (`Entry`=129559 AND `DifficultyID`=1); -- Cutwater Duelist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129553 AND `DifficultyID`=1); -- Dinomancer Kish'o
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129552 AND `DifficultyID`=1); -- Monzumi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129551 AND `DifficultyID`=0); -- Bilge Rat Mixologist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=147212 WHERE (`Entry`=129550 AND `DifficultyID`=1); -- Bilge Rat Padfoot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=147208 WHERE (`Entry`=129548 AND `DifficultyID`=1); -- Blacktooth Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129547 AND `DifficultyID`=1); -- Blacktooth Knuckleduster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=157190 WHERE (`Entry`=129529 AND `DifficultyID`=1); -- Blacktooth Scrapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=136125 WHERE (`Entry`=129527 AND `DifficultyID`=1); -- Bilge Rat Buccaneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=147199 WHERE (`Entry`=129526 AND `DifficultyID`=1); -- Bilge Rat Swabby
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `HealthModifier`=1.75, `CreatureDifficultyID`=135082 WHERE (`Entry`=129517 AND `DifficultyID`=1); -- Reanimated Raptor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129481 AND `DifficultyID`=0); -- Empty Mug
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129480 AND `DifficultyID`=0); -- Keg of Caustic Grog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129448 AND `DifficultyID`=1); -- Hammer Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129441 AND `DifficultyID`=1); -- Otis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129374 AND `DifficultyID`=1); -- Scrimshaw Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129373 AND `DifficultyID`=1); -- Dockhound Packmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129372 AND `DifficultyID`=1); -- Blacktar Bomber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129371 AND `DifficultyID`=1); -- Riptide Shredder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129367 AND `DifficultyID`=1); -- Bilge Rat Tempest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129366 AND `DifficultyID`=1); -- Bilge Rat Buccaneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129359 AND `DifficultyID`=1); -- Sawtooth Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129352 AND `DifficultyID`=1); -- Wodin the Troll-Servant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129350 AND `DifficultyID`=1); -- Gurgthock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (129274,129271)); -- Massive Blast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129272 AND `DifficultyID`=1); -- Explosive Munitions
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129246 AND `DifficultyID`=1); -- Azerite Footbomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144506 WHERE (`Entry`=129232 AND `DifficultyID`=1); -- Mogul Razdunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144503 WHERE (`Entry`=129231 AND `DifficultyID`=1); -- Rixxa Fluxflame
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144500 WHERE (`Entry`=129227 AND `DifficultyID`=1); -- Azerokk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=144494 WHERE (`Entry`=129214 AND `DifficultyID`=1); -- Coin-Operated Crowd Pummeler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129213 AND `DifficultyID`=0); -- Brutikus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=129208 AND `DifficultyID`=1); -- Dread Captain Lockwood
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=155495 WHERE (`Entry`=128956 AND `DifficultyID`=1); -- Blood-Tainted Cauldron of Gold
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128772 AND `DifficultyID`=1); -- Mudwallow Frog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128652 AND `DifficultyID`=1); -- Viq'Goth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128651 AND `DifficultyID`=1); -- Hadal Darkfathom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142991 WHERE (`Entry`=128551 AND `DifficultyID`=1); -- Irontide Mastiff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128455 AND `DifficultyID`=1); -- T'lonja
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128435 AND `DifficultyID`=1); -- Toxic Saurid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=128434 AND `DifficultyID`=1); -- Feasting Skyscreamer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=127949 AND `DifficultyID`=1); -- Void Manifestation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=127911 AND `DifficultyID`=0); -- Void-Blade Zedaat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=127906 AND `DifficultyID`=0); -- Twilight-Harbinger Tharuul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127799 AND `DifficultyID`=1); -- Dazar'ai Honor Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127757 AND `DifficultyID`=1); -- Reanimated Honor Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127503 AND `DifficultyID`=1); -- Overseer Korgus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127499 AND `DifficultyID`=1); -- Ashvane Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127497 AND `DifficultyID`=1); -- Ashvane Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127490 AND `DifficultyID`=1); -- Knight Captain Valyri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127488 AND `DifficultyID`=1); -- Ashvane Flamecaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127486 AND `DifficultyID`=1); -- Ashvane Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127484 AND `DifficultyID`=1); -- Jes Howlis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127482 AND `DifficultyID`=1); -- Sewer Vicejaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127480 AND `DifficultyID`=1); -- Stinging Parasite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127477 AND `DifficultyID`=1); -- Saltwater Snapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127381 AND `DifficultyID`=1); -- Silt Crab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127352 AND `DifficultyID`=1); -- Risen Honor Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (127315,125977)); -- Reanimation Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=127124 AND `DifficultyID`=1); -- Freehold Barhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135767 WHERE (`Entry`=127111 AND `DifficultyID`=1); -- Irontide Oarsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135771 WHERE (`Entry`=127106 AND `DifficultyID`=1); -- Irontide Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135337 WHERE (`Entry`=126983 AND `DifficultyID`=1); -- Harlan Sweete
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=126969 AND `DifficultyID`=1); -- Trothak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=126957 AND `DifficultyID`=0); -- Serpent's Bay Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142988 WHERE (`Entry`=126928 AND `DifficultyID`=1); -- Irontide Corsair
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135763 WHERE (`Entry`=126919 AND `DifficultyID`=1); -- Irontide Stormcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142984 WHERE (`Entry`=126918 AND `DifficultyID`=1); -- Irontide Crackshot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135754 WHERE (`Entry`=126848 AND `DifficultyID`=1); -- Captain Eudora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135250 WHERE (`Entry`=126847 AND `DifficultyID`=1); -- Captain Raoul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=135284 WHERE (`Entry`=126845 AND `DifficultyID`=1); -- Captain Jolly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=126832 AND `DifficultyID`=1); -- Skycap'n Kragg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=126831 AND `DifficultyID`=0); -- Bay Gull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`DifficultyID`=1 AND `Entry` IN (126734,125868)); -- Echo of Shadra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=126664 AND `DifficultyID`=1); -- Doomwing Raven
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=126283 AND `DifficultyID`=0); -- Urjad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125981 AND `DifficultyID`=1); -- Fragmented Voidling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (125860,122571)); -- Rift Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125857 AND `DifficultyID`=1); -- Lashing Voidling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125846 AND `DifficultyID`=0); -- Void Flayer(IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125845 AND `DifficultyID`=0); -- Void Discharge (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125844 AND `DifficultyID`=0); -- Shadowguard Voidbender (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=125828 AND `DifficultyID`=1); -- Soulspawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125615 AND `DifficultyID`=0); -- Shadowguard Voidtender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125340 AND `DifficultyID`=1); -- Shadewing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=125293 AND `DifficultyID`=0); -- Echo of Zuraal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (125081,122407)); -- Warp Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (125080,122560,122408)); -- Shadow Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (125079,122410)) OR (`DifficultyID`=0 AND `Entry`=125003); -- Skyfin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124967 AND `DifficultyID`=0); -- Shadow-Weaver Essence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124964 AND `DifficultyID`=0); -- Unstable Dark Matter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124947 AND `DifficultyID`=1); -- Void Flayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124880 AND `DifficultyID`=0); -- War-Adept Essence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124875 AND `DifficultyID`=0); -- Shadowguard Subjugator (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124874 AND `DifficultyID`=0); -- Viceroy Nezhar (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124873 AND `DifficultyID`=0); -- Darkfang (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124872 AND `DifficultyID`=0); -- Saprish (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124871 AND `DifficultyID`=0); -- Zuraal the Ascended (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124870 AND `DifficultyID`=0); -- L'ura (IGC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124745 AND `DifficultyID`=1); -- Greater Rift Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124729 AND `DifficultyID`=1) OR (`Entry`=122314 AND `DifficultyID`=0); -- L'ura
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124309 AND `DifficultyID`=0) OR (`Entry`=122056 AND `DifficultyID`=1); -- Viceroy Nezhar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=124171 AND `DifficultyID`=1); -- Shadowguard Subjugator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=123411 AND `DifficultyID`=0); -- Rejuvenated Voidlord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=123072 AND `DifficultyID`=0); -- Grimghast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=123050 AND `DifficultyID`=1); -- Waning Void
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122986 AND `DifficultyID`=1); -- Wild Skyscreamer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122984 AND `DifficultyID`=1); -- Dazar'ai Colossus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122979 AND `DifficultyID`=0); -- Phoenix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122976 AND `DifficultyID`=0); -- Goldtalon Scytheclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122975 AND `DifficultyID`=0); -- Goldtalon Gutripper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122973 AND `DifficultyID`=1); -- Dazar'ai Confessor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122972 AND `DifficultyID`=1); -- Dazar'ai Augur
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122971 AND `DifficultyID`=1); -- Dazar'ai Juggernaut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122969 AND `DifficultyID`=1); -- Zanchuli Witch-Doctor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122968 AND `DifficultyID`=1); -- Yazma
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=142330 WHERE (`Entry`=122967 AND `DifficultyID`=1); -- Priestess Alun'za
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=122965 AND `DifficultyID`=1); -- Vol'kaal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=134802 WHERE (`Entry`=122963 AND `DifficultyID`=1); -- Rezan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122895 AND `DifficultyID`=0); -- Empowered Umbral Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122827 AND `DifficultyID`=1); -- Umbral Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122716 AND `DifficultyID`=1); -- Coalesced Void
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122482 AND `DifficultyID`=1); -- Dark Aberration
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122478 AND `DifficultyID`=1); -- Void Discharge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122457 AND `DifficultyID`=1); -- Darkcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122456 AND `DifficultyID`=0); -- Voidmaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122423 AND `DifficultyID`=1); -- Grand Shadow-Weaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122421 AND `DifficultyID`=1); -- Umbral War-Adept
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122413 AND `DifficultyID`=1); -- Shadowguard Riftstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122412 AND `DifficultyID`=1); -- Bound Voidlord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122405 AND `DifficultyID`=1); -- Shadowguard Conjurer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122404 AND `DifficultyID`=1); -- Shadowguard Voidbender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122403 AND `DifficultyID`=1); -- Shadowguard Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122401 AND `DifficultyID`=1); -- Shadowguard Trickster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122398 AND `DifficultyID`=1); -- Sapped Voidlord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122322 AND `DifficultyID`=1); -- Famished Broken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122319 AND `DifficultyID`=1); -- Darkfang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122316 AND `DifficultyID`=1); -- Saprish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=122313 AND `DifficultyID`=1); -- Zuraal the Ascended
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (121713,118834)); -- Fel Portal Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (121711,118716)); -- Bilespray Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121583 AND `DifficultyID`=0); -- Noxious Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121569 AND `DifficultyID`=0); -- Vilebark Walker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (121554,121553)); -- Dreadhunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121393 AND `DifficultyID`=0); -- Nourishing Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121392 AND `DifficultyID`=0); -- Biographical Animated Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121384 AND `DifficultyID`=0); -- Fictional Animated Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121364 AND `DifficultyID`=0); -- Satirical Animated Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (121318,119978,119169)); -- Fulminating Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (121231,121069,120556,120405,119930,118642)); -- Dreadwing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=121167 AND `DifficultyID`=0); -- Searing Overfiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120779,118724)); -- Helblaze Felbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120778,120550,118690)); -- Wrathguard Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120770,120374,119952)) OR (`DifficultyID`=1 AND `Entry` IN (102368,102272)); -- Felguard Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120727 AND `DifficultyID`=0); -- Book of Everlasting Silence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120717 AND `DifficultyID`=0); -- Mistress Dominix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120716 AND `DifficultyID`=0); -- Dreadspeaker Serilis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120715 AND `DifficultyID`=0); -- Raga'yut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120713 AND `DifficultyID`=0); -- Wa'glur
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120712 AND `DifficultyID`=0); -- Larithia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=120652 AND `DifficultyID`=1); -- Global Affix Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120650 AND `DifficultyID`=0); -- Arcane Horror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120646 AND `DifficultyID`=0); -- Book of Arcane Monstrosities
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120371,118717)); -- Helblaze Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120366,118714)); -- Hellblaze Temptress
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (120300,100525)); -- Glowing Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120274 AND `DifficultyID`=0); -- Felstrider Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (120016,118706)); -- Necrotic Spiderling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=120014 AND `DifficultyID`=0); -- Choking Vines
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=119977 AND `DifficultyID`=0); -- Stranglevine Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=119923 AND `DifficultyID`=0); -- Helblaze Soulmender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=119871 AND `DifficultyID`=0); -- Over Fiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=119157 AND `DifficultyID`=0); -- Felguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=119144 AND `DifficultyID`=0); -- Succulent Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118805 AND `DifficultyID`=0); -- Hellblaze Feaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118804 AND `DifficultyID`=0); -- Domatrax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118802 AND `DifficultyID`=0); -- Hellblaze Mistress
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118801 AND `DifficultyID`=0); -- Imp
UPDATE `creature_template_difficulty` SET `TypeFlags2`=8192 WHERE (`Entry`=118791 AND `DifficultyID`=1); -- Sturdy Love Fool
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118723 AND `DifficultyID`=0); -- Gazerax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (118719,101923)) OR (`DifficultyID`=1 AND `Entry`=98792); -- Wyrmtongue Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118718 AND `DifficultyID`=0); -- Book of Eternal Winter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118713 AND `DifficultyID`=0); -- Felstrider Orbcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118712 AND `DifficultyID`=0); -- Felstrider Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118705 AND `DifficultyID`=0); -- Nal'asha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118704 AND `DifficultyID`=0); -- Dul'zak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118703 AND `DifficultyID`=0); -- Felborne Botanist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=118700 AND `DifficultyID`=0); -- Felblight Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=117590 AND `DifficultyID`=0); -- Shadow of Mephistroth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=117578 AND `DifficultyID`=1); -- Rusty Keys
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=117194 AND `DifficultyID`=0); -- Thrashbite the Scornful
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=117193 AND `DifficultyID`=0); -- Agronox
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116944 AND `DifficultyID`=0); -- Mephistroth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (116865,116864,116551)); -- Flying Tome
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116804 AND `DifficultyID`=1); -- Scene Actor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116802 AND `DifficultyID`=1); -- Rodent of Usual Size
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116574 AND `DifficultyID`=1); -- Silver Forks
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116573 AND `DifficultyID`=1); -- R.L Cooper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116563 AND `DifficultyID`=1); -- Ancient Core Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116562 AND `DifficultyID`=1); -- Flamewaker Centurion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116561 AND `DifficultyID`=1); -- Unbound Pyrelord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116550 AND `DifficultyID`=1); -- Spectral Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `ManaModifier`=1, `CreatureDifficultyID`=120523 WHERE (`Entry`=116549 AND `DifficultyID`=1); -- Backup Singer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116495 AND `DifficultyID`=1); -- Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (116494,115831,114252)); -- Mana Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116491 AND `DifficultyID`=1); -- Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116447 AND `DifficultyID`=0); -- Mysterious Book
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116418 AND `DifficultyID`=1); -- Ethereal Thief
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (116259,115501,115496)) OR (`DifficultyID`=0 AND `Entry` IN (115510,115497)); -- Archmage Khadgar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (116124,115491,115487,115426)) OR (`DifficultyID`=0 AND `Entry`=114463); -- Medivh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116003 AND `DifficultyID`=1); -- The Big Bad Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=116002 AND `DifficultyID`=1); -- The Crone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115986 AND `DifficultyID`=1); -- Grandmother
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115984 AND `DifficultyID`=1); -- Tinhead
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115983 AND `DifficultyID`=1); -- Roar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115982 AND `DifficultyID`=1); -- Strawman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115981 AND `DifficultyID`=1); -- Dorothee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115976 AND `DifficultyID`=1); -- Julianne
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115967 AND `DifficultyID`=1); -- Romulo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115789 AND `DifficultyID`=1); -- Demonic Rift
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120555 WHERE (`Entry`=115765 AND `DifficultyID`=1); -- Abstract Nullifier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120578 WHERE (`Entry`=115757 AND `DifficultyID`=1); -- Wrathguard Flamebringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115746 AND `DifficultyID`=1); -- Burning Tiles
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115743 AND `DifficultyID`=1); -- Legion Console
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115734 AND `DifficultyID`=1); -- Shadow Spitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115730 AND `DifficultyID`=1); -- Felguard Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115725 AND `DifficultyID`=0); -- Twisted Gazer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115694 AND `DifficultyID`=1); -- Soul Harvester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115533 AND `DifficultyID`=1); -- Gleeful Immolator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115493 AND `DifficultyID`=1); -- Demonic Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115490 AND `DifficultyID`=1); -- Prince Llane Wrynn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115489 AND `DifficultyID`=1); -- Anduin Lothar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120570 WHERE (`Entry`=115488 AND `DifficultyID`=1); -- Infused Pyromancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120599 WHERE (`Entry`=115486 AND `DifficultyID`=1); -- Erudite Slayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120574, `TypeFlags`=2097224 WHERE (`Entry`=115484 AND `DifficultyID`=1); -- Fel Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115427 AND `DifficultyID`=1); -- Nielas Aran
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120591 WHERE (`Entry`=115419 AND `DifficultyID`=1); -- Ancient Tome
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120587 WHERE (`Entry`=115418 AND `DifficultyID`=1); -- Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120582 WHERE (`Entry`=115417 AND `DifficultyID`=1); -- Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120621 WHERE (`Entry`=115407 AND `DifficultyID`=1); -- Rook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120612 WHERE (`Entry`=115406 AND `DifficultyID`=1); -- Knight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120604 WHERE (`Entry`=115402 AND `DifficultyID`=1); -- Bishop
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120608 WHERE (`Entry`=115401 AND `DifficultyID`=1); -- Bishop
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120616 WHERE (`Entry`=115395 AND `DifficultyID`=1); -- Queen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120624 WHERE (`Entry`=115388 AND `DifficultyID`=1); -- King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115386 AND `DifficultyID`=1); -- Chest Board
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115274 AND `DifficultyID`=1); -- Fel Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (115234,115212)); -- Inverted Arcanymo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115213 AND `DifficultyID`=0); -- Image of Arcanagos
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (115124,115123,115118,115057,115034,115033,115032,115030,97689)); -- Web
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120470 WHERE (`Entry`=115115 AND `DifficultyID`=1); -- Coldmist Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (115113,115105,115103,115101,115013)); -- Soul Fragment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115063 AND `DifficultyID`=1); -- Greater Shadowbat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115062 AND `DifficultyID`=1); -- Shadowbat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115061 AND `DifficultyID`=1); -- Dreadbeast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115059 AND `DifficultyID`=1); -- Shadowbeast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115038 AND `DifficultyID`=1); -- Image of Medivh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115022 AND `DifficultyID`=1); -- The Monkey King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120478 WHERE (`Entry`=115020 AND `DifficultyID`=1); -- Arcanid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120474 WHERE (`Entry`=115019 AND `DifficultyID`=1); -- Coldmist Widow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115016 AND `DifficultyID`=0); -- Mok-Mok the Entertaining
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115007 AND `DifficultyID`=1); -- Hozen Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=115005 AND `DifficultyID`=1); -- Caged Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114947 AND `DifficultyID`=0); -- Woeful Healer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114940 AND `DifficultyID`=1); -- Phantom Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114938 AND `DifficultyID`=1); -- Dancing Vehicle Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114913 AND `DifficultyID`=1); -- Command Ship
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114906 AND `DifficultyID`=0); -- Restless Bones
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114903 AND `DifficultyID`=0); -- Bonecurse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114895 AND `DifficultyID`=0); -- Nightbane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114844 AND `DifficultyID`=1); -- Spell Shade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114843 AND `DifficultyID`=1); -- Shadow Pillager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114842 AND `DifficultyID`=1); -- Homunculus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114839 AND `DifficultyID`=1); -- Chaotic Sentience
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114835 AND `DifficultyID`=1); -- Mana Feeder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114834 AND `DifficultyID`=1); -- Arcane Watchman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114833 AND `DifficultyID`=1); -- Upside Down Trash Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114815 AND `DifficultyID`=1) OR (`Entry`=114800 AND `DifficultyID`=0); -- Koren
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120462 WHERE (`Entry`=114804 AND `DifficultyID`=1); -- Spectral Charger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `ManaModifier`=1, `CreatureDifficultyID`=120466 WHERE (`Entry`=114803 AND `DifficultyID`=1); -- Spectral Stable Hand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120454 WHERE (`Entry`=114802 AND `DifficultyID`=1); -- Spectral Journeyman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120458 WHERE (`Entry`=114801 AND `DifficultyID`=1); -- Spectral Apprentice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114799 AND `DifficultyID`=1); -- Calliard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114796 AND `DifficultyID`=1); -- Wholesome Hostess
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120499 WHERE (`Entry`=114794 AND `DifficultyID`=1); -- Skeletal Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120511 WHERE (`Entry`=114792 AND `DifficultyID`=1); -- Virtuous Lady
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114790 AND `DifficultyID`=1); -- Viz'aduum the Watcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120515 WHERE (`Entry`=114783 AND `DifficultyID`=1); -- Reformed Maiden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=1.649999976158142089, `CreatureDifficultyID`=118194 WHERE (`Entry`=114716 AND `DifficultyID`=1); -- Ghostly Baker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120495 WHERE (`Entry`=114715 AND `DifficultyID`=1); -- Ghostly Chef
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120503 WHERE (`Entry`=114714 AND `DifficultyID`=1); -- Ghostly Steward
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114675 AND `DifficultyID`=1); -- Guardian's Image
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114668 AND `DifficultyID`=0); -- Nether-Touched Warlock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114659 AND `DifficultyID`=0); -- Nether-Touched Necrolyte
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114658 AND `DifficultyID`=0); -- Nether-Touched Warlord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114653 AND `DifficultyID`=1); -- Flower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118113 WHERE (`Entry`=114650 AND `DifficultyID`=1); -- Phantom Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114649 AND `DifficultyID`=1); -- Potter Golem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114648 AND `DifficultyID`=1); -- Aron Gillwort
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114647 AND `DifficultyID`=1); -- Willy Zulemore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114646 AND `DifficultyID`=1); -- Babby Yikes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114644 AND `DifficultyID`=0); -- Nether-Touched Cleric
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114643 AND `DifficultyID`=0); -- Nether-Touched Conjurer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114642 AND `DifficultyID`=0); -- Nether-Touched King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114637 AND `DifficultyID`=1); -- Spectral Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118093 WHERE (`Entry`=114636 AND `DifficultyID`=1); -- Phantom Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118085 WHERE (`Entry`=114634 AND `DifficultyID`=1); -- Undying Servant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118078 WHERE (`Entry`=114633 AND `DifficultyID`=1); -- Spectral Valet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114632 AND `DifficultyID`=1); -- Spectral Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120482 WHERE (`Entry`=114629 AND `DifficultyID`=1); -- Spectral Retainer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120490 WHERE (`Entry`=114628 AND `DifficultyID`=1); -- Skeletal Waiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120547 WHERE (`Entry`=114627 AND `DifficultyID`=1); -- Shrieking Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=5.076900005340576171, `CreatureDifficultyID`=120543 WHERE (`Entry`=114626 AND `DifficultyID`=1); -- Forlorn Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118088 WHERE (`Entry`=114625 AND `DifficultyID`=1); -- Phantom Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120486 WHERE (`Entry`=114624 AND `DifficultyID`=1); -- Arcane Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114616 AND `DifficultyID`=1); -- Sebastian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.030800104141235351, `CreatureDifficultyID`=120532 WHERE (`Entry`=114584 AND `DifficultyID`=1); -- Phantom Crew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114583 AND `DifficultyID`=0); -- Adem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114556 AND `DifficultyID`=1); -- Mae Stance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114555 AND `DifficultyID`=1); -- Gillian Voltzman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114554 AND `DifficultyID`=1); -- Peta Venkner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114552 AND `DifficultyID`=1); -- Egona Spangly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114551 AND `DifficultyID`=1); -- Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114545 AND `DifficultyID`=1); -- Bella
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120507 WHERE (`Entry`=114544 AND `DifficultyID`=1); -- Skeletal Usher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120539 WHERE (`Entry`=114542 AND `DifficultyID`=1); -- Ghostly Philanthropist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120519 WHERE (`Entry`=114541 AND `DifficultyID`=1); -- Spectral Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120527 WHERE (`Entry`=114526 AND `DifficultyID`=1); -- Ghostly Understudy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114522 AND `DifficultyID`=1); -- Mrs. Cauldrons
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114520 AND `DifficultyID`=1); -- Figero
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114516 AND `DifficultyID`=0) OR (`Entry`=98677 AND `DifficultyID`=1); -- Rook Spiderling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114486 AND `DifficultyID`=1); -- Crone's Broom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114471 AND `DifficultyID`=1); -- Wash Away
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (114462,114247)); -- The Curator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114408 AND `DifficultyID`=1); -- Will Breaker Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120566 WHERE (`Entry`=114364 AND `DifficultyID`=1); -- Mana-Gorged Wyrm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (114354,98272)); -- Immoliant Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (114353,114352,114347,99953)); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114350 AND `DifficultyID`=1); -- Shade of Medivh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114339 AND `DifficultyID`=1) OR (`Entry`=114335 AND `DifficultyID`=0); -- Barnes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `ManaModifier`=0.117299996316432952, `CreatureDifficultyID`=120562 WHERE (`Entry`=114338 AND `DifficultyID`=1); -- Mana Confluence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=120551 WHERE (`Entry`=114334 AND `DifficultyID`=1); -- Damaged Golem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114330 AND `DifficultyID`=1); -- Babblet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114329 AND `DifficultyID`=1); -- Luminore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114328 AND `DifficultyID`=1); -- Coggleston
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114327 AND `DifficultyID`=1); -- Whirling Edge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114324 AND `DifficultyID`=1); -- Winged Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114321 AND `DifficultyID`=1); -- Lord Crispin Ference
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114320 AND `DifficultyID`=1); -- Lord Robin Daris
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114319 AND `DifficultyID`=1); -- Lady Keira Berrybuck
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114318 AND `DifficultyID`=1); -- Baron Rafe Dreuger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114317 AND `DifficultyID`=1); -- Lady Catriona Von'Indi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114316 AND `DifficultyID`=1); -- Baroness Dorothea Millstipe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114315 AND `DifficultyID`=1); -- Intangible Pressence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114312 AND `DifficultyID`=1); -- Moroes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.75, `CreatureDifficultyID`=117626, `TypeFlags`=270532680 WHERE (`Entry`=114289 AND `DifficultyID`=1); -- Skeletal Sorcerer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=1.10000002384185791, `ManaModifier`=0.065200001001358032, `CreatureDifficultyID`=117623, `TypeFlags`=2097224 WHERE (`Entry`=114288 AND `DifficultyID`=1); -- Skeletal Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114284 AND `DifficultyID`=1); -- Elfyra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (114273,114272)) OR (`DifficultyID`=1 AND `Entry`=114262); -- Attumen the Huntsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114266 AND `DifficultyID`=1); -- Shoreline Tidespeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114265 AND `DifficultyID`=1); -- Gang Ruffian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114264 AND `DifficultyID`=1); -- Midnight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114261 AND `DifficultyID`=1); -- Toe Knee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114260 AND `DifficultyID`=1); -- Mrrgria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114251 AND `DifficultyID`=1); -- Galindre
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=114249 AND `DifficultyID`=1); -- Volatile Energy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117304 WHERE (`Entry`=113998 AND `DifficultyID`=1); -- Mightstone Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113971 AND `DifficultyID`=1); -- Maiden of Virtue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113742 AND `DifficultyID`=1); -- War Drums Warrior Anchor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113699 AND `DifficultyID`=0); -- Forgotten Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113552 AND `DifficultyID`=1); -- Overloaded Lens
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=116753 WHERE (`Entry`=113537 AND `DifficultyID`=1); -- Emberhusk Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=116749 WHERE (`Entry`=113536 AND `DifficultyID`=1); -- Emberhusk Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (113526,100701)); -- Spiritwalker Ebonhorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (113506,113206)); -- Drogbar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=116526 WHERE (`Entry`=113398 AND `DifficultyID`=1); -- Bloodtainted Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113204 AND `DifficultyID`=1); -- Scaly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=116261 WHERE (`Entry`=113197 AND `DifficultyID`=1); -- Understone Drudge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113173 AND `DifficultyID`=0); -- Navarogg Spawn Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=113111 AND `DifficultyID`=1); -- Saltscale Swarmer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112741 AND `DifficultyID`=1); -- Wrathguard Decimator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112739 AND `DifficultyID`=1); -- Shadowy Overfiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112738 AND `DifficultyID`=1); -- Acolyte of Sael'orn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112733 AND `DifficultyID`=1); -- Venomhide Shadowspinner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112732 AND `DifficultyID`=1); -- Brood of Sael'orn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=118467 WHERE (`Entry`=112725 AND `DifficultyID`=1); -- Kalyndras
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (112699,112697,107435)); -- Suspicious Noble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112687 AND `DifficultyID`=1); -- Enveloping Winds
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=112668 AND `DifficultyID`=1); -- Infernal Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111882 AND `DifficultyID`=1); -- Sparky
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111865 AND `DifficultyID`=1); -- Sticky Vehicle Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111864 AND `DifficultyID`=1); -- Sticky
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111861 AND `DifficultyID`=1); -- Slinky
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111746 AND `DifficultyID`=1); -- Mushroom Merchant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111706 AND `DifficultyID`=1); -- Boulder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (111563,104246)); -- Duskwatch Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111290 AND `DifficultyID`=0); -- Braxas the Fleshcarver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111193 AND `DifficultyID`=0); -- Quivering Egg Sac
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111068 AND `DifficultyID`=1); -- Archmage Galeorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111042 AND `DifficultyID`=1); -- Nightmare Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=111008 AND `DifficultyID`=0); -- Hatespawn Abomination
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=113148 WHERE (`Entry`=111001 AND `DifficultyID`=1); -- Horror Corrupted Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110995 AND `DifficultyID`=0); -- Ranger General Feleor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110993 AND `DifficultyID`=0); -- General Tel'arn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110983 AND `DifficultyID`=0); -- Winter Veil Talixae Flamewreath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110966 AND `DifficultyID`=0); -- Vicious Manafang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (110960,107470)); -- Haughty Aristocrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110959 AND `DifficultyID`=1); -- Wealthy Elite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (110958,107472)); -- Fancy Noble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110908 AND `DifficultyID`=1); -- Spellblade Aluriel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110907 AND `DifficultyID`=1); -- Star Augur Etraeus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110443 AND `DifficultyID`=1); -- Elisande
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=110403 AND `DifficultyID`=1); -- Streetsweeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (109137,105778)); -- Angry Crowd
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108926 AND `DifficultyID`=0); -- Lava Geyser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108796 AND `DifficultyID`=0); -- Arcanist Malrodi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108794 AND `DifficultyID`=0); -- Shroudseeker's Shadow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108740 AND `DifficultyID`=1); -- Velimar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108727 AND `DifficultyID`=0); -- Diseased Pustule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108701 AND `DifficultyID`=0); -- Ataxius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108543 AND `DifficultyID`=0); -- Dread Captain Thedon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108541 AND `DifficultyID`=0); -- Dread Corsair
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108531 AND `DifficultyID`=0); -- Dread Ship Krazatoa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108494 AND `DifficultyID`=0); -- Soulfiend Tagerma
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108406 AND `DifficultyID`=1); -- Arcane Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108154 AND `DifficultyID`=1); -- Arcane Keys
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=108151 AND `DifficultyID`=0); -- Gerenth the Vile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (107638,100403)); -- Druidic Preserver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=107486 AND `DifficultyID`=1); -- Chatty Rumormonger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry`=107442) OR (`DifficultyID`=0 AND `Entry` IN (107424,107422,107419,107418,107417,107416,107414,107413,107412,107411,107410,107409,107408,107406,107404,107393)); -- Suspicious Suramar Noble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (107291,106586,106585,106584)); -- Watchful Oculus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=107288 AND `DifficultyID`=0); -- Vilethorn Sapling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=107114 AND `DifficultyID`=1); -- Tormenting Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109792 WHERE (`Entry`=107101 AND `DifficultyID`=1); -- Fel Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=107073 AND `DifficultyID`=1); -- Duskwatch Reinforcement
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (106787,106786,106785)); -- Bitterbrine Slave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108566 WHERE (`Entry`=106546 AND `DifficultyID`=1); -- Astral Spark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=106468 AND `DifficultyID`=1); -- Ly'leth Lunastre
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=106320 AND `DifficultyID`=1); -- Volynd Stormbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=106237 AND `DifficultyID`=0); -- Flat-Footed Duskwatch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108563 WHERE (`Entry`=106059 AND `DifficultyID`=1); -- Warp Shade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108518 WHERE (`Entry`=105952 AND `DifficultyID`=1); -- Withered Manawraith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108556 WHERE (`Entry`=105921 AND `DifficultyID`=1); -- Nightborne Spellsword
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108558 WHERE (`Entry`=105915 AND `DifficultyID`=1); -- Nightborne Reclaimer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108551 WHERE (`Entry`=105876 AND `DifficultyID`=1); -- Enchanted Broodling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105811 AND `DifficultyID`=0); -- Razor Shards Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105766 AND `DifficultyID`=1); -- Blightshard Shaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105765 AND `DifficultyID`=1); -- Gale Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105754 AND `DifficultyID`=1); -- Image of Advisor Melandrus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105744 AND `DifficultyID`=1); -- Blaze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105743 AND `DifficultyID`=1); -- Whipsnap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105742 AND `DifficultyID`=1); -- Turbax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105741 AND `DifficultyID`=1); -- Slimetail
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (105738,102228)) OR (`DifficultyID`=0 AND `Entry`=103593); -- Stonedark Slave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106931 WHERE (`Entry`=105720 AND `DifficultyID`=1); -- Understone Drudge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105715 AND `DifficultyID`=1); -- Watchful Inquisitor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108545 WHERE (`Entry`=105706 AND `DifficultyID`=1); -- Priestess of Misery
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105705 AND `DifficultyID`=1); -- Bound Energy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105704 AND `DifficultyID`=1); -- Arcane Manifestation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105703 AND `DifficultyID`=1); -- Mana Wyrm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105699 AND `DifficultyID`=1); -- Mana Saber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105688 AND `DifficultyID`=1); -- REUSE
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108543 WHERE (`Entry`=105682 AND `DifficultyID`=1); -- Felguard Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108525 WHERE (`Entry`=105651 AND `DifficultyID`=1); -- Dreadborne Seer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106845 WHERE (`Entry`=105636 AND `DifficultyID`=1); -- Understone Drudge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106840 WHERE (`Entry`=105633 AND `DifficultyID`=1); -- Understone Drudge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108541 WHERE (`Entry`=105629 AND `DifficultyID`=1); -- Wyrmtongue Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108537 WHERE (`Entry`=105617 AND `DifficultyID`=1); -- Eredar Chaosbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105410 AND `DifficultyID`=1); -- Suramar Musician
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=105300 AND `DifficultyID`=1); -- Ularogg Cragshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104918 AND `DifficultyID`=1); -- Vigilant Duskwatch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104822 AND `DifficultyID`=1); -- Flame of Woe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (104400,104384)); -- Resonant Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104300 AND `DifficultyID`=1); -- Shadow Mistress
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104295 AND `DifficultyID`=1); -- Blazing Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109796 WHERE (`Entry`=104293 AND `DifficultyID`=1); -- Avatar of Shadow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104278 AND `DifficultyID`=1); -- Felbound Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104277 AND `DifficultyID`=1); -- Legion Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104275 AND `DifficultyID`=1); -- Imacu'tya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104274 AND `DifficultyID`=1); -- Baalgar the Watchful
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104273 AND `DifficultyID`=1); -- Jazshariu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104270 AND `DifficultyID`=1); -- Guardian Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104251 AND `DifficultyID`=1); -- Duskwatch Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104247 AND `DifficultyID`=1); -- Duskwatch Arcanist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104218 AND `DifficultyID`=1); -- Advisor Melandrus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104217 AND `DifficultyID`=1); -- Talixae Flamewreath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=104215 AND `DifficultyID`=1); -- Patrol Captain Gerdo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (103860,99018,99013)); -- Drelanim Whisperwind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (103857,100759)); -- Fel Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (103801,99802)); -- Arthfael
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103662 AND `DifficultyID`=1); -- Secret Door Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103605 AND `DifficultyID`=0); -- Shroudseeker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103574 AND `DifficultyID`=0); -- Gold Pile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117273 WHERE (`Entry`=103561 AND `DifficultyID`=1); -- Shadow Beast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117954 WHERE (`Entry`=103459 AND `DifficultyID`=1); -- Rockback Snapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103381 AND `DifficultyID`=0); -- Jailer Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103344 AND `DifficultyID`=1); -- Oakheart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103342 AND `DifficultyID`=1); -- Elune's Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117910 WHERE (`Entry`=103247 AND `DifficultyID`=1); -- Ultanok
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108671 WHERE (`Entry`=103130 AND `DifficultyID`=1); -- Timeless Wraith
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103102 AND `DifficultyID`=1); -- Lost Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103093 AND `DifficultyID`=1); -- Safety Net
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=103045 AND `DifficultyID`=0); -- Plaguemaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102991 AND `DifficultyID`=0); -- Nightmare Sphere
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=112035 WHERE (`Entry`=102962 AND `DifficultyID`=1); -- Nightmare Abomination
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102941 AND `DifficultyID`=0); -- Congealed Blood
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102851 AND `DifficultyID`=1); -- Shield Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102788 AND `DifficultyID`=1); -- Felspite Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102781 AND `DifficultyID`=1); -- Fel Bat Pup
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102644,102643)); -- Glaive
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109802 WHERE (`Entry`=102584 AND `DifficultyID`=1); -- Malignant Defiler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109805 WHERE (`Entry`=102583 AND `DifficultyID`=1); -- Fel Scorcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102572 AND `DifficultyID`=1); -- Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109765 WHERE (`Entry`=102566 AND `DifficultyID`=1); -- Grimhorn the Enslaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102540 AND `DifficultyID`=0); -- Blistering Beetle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102475 AND `DifficultyID`=0); -- Genius Engineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102472 AND `DifficultyID`=0); -- Wretched Fleshbeast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102471 AND `DifficultyID`=0); -- Darkfallen Handmaiden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102470 AND `DifficultyID`=0); -- Frost Wyrm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102446 AND `DifficultyID`=1); -- Fel Lord Betrug
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=107507, `TypeFlags`=2097224 WHERE (`Entry`=102434 AND `DifficultyID`=1); -- Phase Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102431 AND `DifficultyID`=1); -- Blood-Princess Thal'ena
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104644 WHERE (`Entry`=102430 AND `DifficultyID`=1); -- Tarspitter Slug
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104642 WHERE (`Entry`=102404 AND `DifficultyID`=1); -- Stoneclaw Grubmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102400 AND `DifficultyID`=1); -- Eredar Shadow Mender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102398 AND `DifficultyID`=1); -- Blazing Infernal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102397 AND `DifficultyID`=1); -- Wrathlord Bulwark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102395 AND `DifficultyID`=1); -- Infiltrator Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=107505 WHERE (`Entry`=102387 AND `DifficultyID`=1); -- Sael'orn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102380 AND `DifficultyID`=1); -- Shadow Council Warlock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102377 AND `DifficultyID`=1); -- Fel Inciter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102376 AND `DifficultyID`=0); -- Wrathguard Bladeweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102373 AND `DifficultyID`=1); -- Corrosive Felhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102372 AND `DifficultyID`=1); -- Felhound Mage Slayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102370,102270)); -- Eredar Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102369,102269)); -- Felstalker Ravener
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102367 AND `DifficultyID`=0) OR (`Entry`=102273 AND `DifficultyID`=1); -- Doomguard Infiltrator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108568 WHERE (`Entry`=102351 AND `DifficultyID`=1); -- Mana Wyrm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102337,102335)); -- Portal Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (102336,102302)); -- Portal Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102310 AND `DifficultyID`=1); -- Beam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=103079, `TypeFlags`=1024 WHERE (`Entry`=102306 AND `DifficultyID`=1); -- Swirling Pool
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102301 AND `DifficultyID`=0); -- Ice Block
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104640 WHERE (`Entry`=102295 AND `DifficultyID`=1); -- Emberhusk Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104638 WHERE (`Entry`=102287 AND `DifficultyID`=1); -- Emberhusk Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102282 AND `DifficultyID`=1); -- Lord Malgath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106435 WHERE (`Entry`=102277 AND `DifficultyID`=1); -- Deadeye Decoy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102271 AND `DifficultyID`=0); -- Spitting Scarab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102266 AND `DifficultyID`=1); -- Violet Hold Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104636 WHERE (`Entry`=102253 AND `DifficultyID`=1); -- Understone Demolisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102246 AND `DifficultyID`=1); -- Anub'esset
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104634 WHERE (`Entry`=102232 AND `DifficultyID`=1); -- Rockbound Trapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102169 AND `DifficultyID`=0); -- Black Bile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102158 AND `DifficultyID`=0); -- Congealed Goo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102139 AND `DifficultyID`=0); -- Reinforced Thorium Rocket Chicken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102138 AND `DifficultyID`=0); -- Vanguard Ixxilon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102136 AND `DifficultyID`=0); -- Overloaded Elementium Squirrel Bomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102103 AND `DifficultyID`=0); -- Thorium Rocket Chicken
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102095 AND `DifficultyID`=1); -- Risen Lancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102094 AND `DifficultyID`=1); -- Risen Swordsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102043 AND `DifficultyID`=0); -- Elementium Squirrel Bomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=102019 AND `DifficultyID`=1); -- Stormforged Obliterator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101995 AND `DifficultyID`=1); -- Festerface
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101994 AND `DifficultyID`=1); -- Faceless Tendril
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106403 WHERE (`Entry`=101991 AND `DifficultyID`=1); -- Nightmare Dweller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101976 AND `DifficultyID`=1); -- Millificent Manastorm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101958 AND `DifficultyID`=1); -- Root Burst Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101951 AND `DifficultyID`=1); -- Shivermaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101950 AND `DifficultyID`=1); -- Mindflayer Kaahrj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101839 AND `DifficultyID`=1); -- Risen Companion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=102424 WHERE (`Entry`=101814 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101756 AND `DifficultyID`=1); -- Hallucinated Poisonheart Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104450 WHERE (`Entry`=101679 AND `DifficultyID`=1); -- Dreadsoul Poisoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101659 AND `DifficultyID`=1); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (101640,101638,96648)) OR (`DifficultyID`=0 AND `Entry` IN (100659,97590,97234,97233,97066)); -- Chosen of Eyir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (101639,95832)) OR (`DifficultyID`=0 AND `Entry`=97251); -- Valarjar Shieldmaiden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101637 AND `DifficultyID`=1) OR (`Entry`=97253 AND `DifficultyID`=0); -- Valarjar Aspirant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101593 AND `DifficultyID`=1); -- Crystal Wall Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101591 AND `DifficultyID`=0); -- Ash'Golm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101549 AND `DifficultyID`=1); -- Arcane Minion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101548 AND `DifficultyID`=1); -- Updraft
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=102078 WHERE (`Entry`=101504 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=102076 WHERE (`Entry`=101502 AND `DifficultyID`=1); -- Helya's Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104661 WHERE (`Entry`=101476 AND `DifficultyID`=1); -- Molten Charskin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101467 AND `DifficultyID`=0); -- Jaggen-Ra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101445 AND `DifficultyID`=1); -- Vileshard Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104632 WHERE (`Entry`=101438 AND `DifficultyID`=1); -- Vileshard Chunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104630 WHERE (`Entry`=101437 AND `DifficultyID`=1); -- Burning Geode
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101414 AND `DifficultyID`=1); -- Saltscale Skulker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101411 AND `DifficultyID`=0); -- Gom Crabbar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106441 WHERE (`Entry`=101329 AND `DifficultyID`=1); -- Nightmare Bindings
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101326 AND `DifficultyID`=1); -- Honored Ancestor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101085 AND `DifficultyID`=1); -- Bear Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101078 AND `DifficultyID`=1); -- Acid Breath Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104659 WHERE (`Entry`=101075 AND `DifficultyID`=1); -- Wormspeaker Devout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=113131, `TypeFlags2`=0 WHERE (`Entry`=101074 AND `DifficultyID`=1); -- Hatespawn Whelpling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106421 WHERE (`Entry`=101072 AND `DifficultyID`=1); -- Corrupted Dragon Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101070 AND `DifficultyID`=0); -- Razormaw Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101054 AND `DifficultyID`=1); -- Soul of Ravencrest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101028 AND `DifficultyID`=1); -- Image of Latosius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=101008 AND `DifficultyID`=1); -- Stinging Swarm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100994 AND `DifficultyID`=1); -- Cloud of Hypnosis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100991 AND `DifficultyID`=1); -- Strangling Roots
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100960 AND `DifficultyID`=1); -- Vile Mushroom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100894 AND `DifficultyID`=1); -- Referee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100892 AND `DifficultyID`=0); -- Prancing Escape Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (100861,98965)); -- Kur'talos Ravencrest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100763 AND `DifficultyID`=0); -- Nightmare Bear Form
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100739 AND `DifficultyID`=0); -- Nightmare Cat Form
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100713 AND `DifficultyID`=1); -- Rockbait Fisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100700 AND `DifficultyID`=1); -- Navarrogg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106439 WHERE (`Entry`=100652 AND `DifficultyID`=1); -- Malfurion Stormrage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100575 AND `DifficultyID`=1); -- Spear of Light
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106433 WHERE (`Entry`=100539 AND `DifficultyID`=1); -- Taintheart Deadeye
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106417 WHERE (`Entry`=100533 AND `DifficultyID`=1); -- Corrupted Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=113086 WHERE (`Entry`=100532 AND `DifficultyID`=1); -- Bloodtainted Burster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106413 WHERE (`Entry`=100531 AND `DifficultyID`=1); -- Bloodtainted Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=113084 WHERE (`Entry`=100529 AND `DifficultyID`=1); -- Hatespawn Slime
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106431 WHERE (`Entry`=100527 AND `DifficultyID`=1); -- Dreadfire Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106429 WHERE (`Entry`=100526 AND `DifficultyID`=1); -- Tormented Bloodseeker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (100486,98280)); -- Risen Arcanist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100485 AND `DifficultyID`=1); -- Soul-torn Vanguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100484 AND `DifficultyID`=0); -- Vilewood Treant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (100436,98696)); -- Illysanna Ravencrest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100404 AND `DifficultyID`=1); -- Perserver Ray Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104442 WHERE (`Entry`=100400 AND `DifficultyID`=1); -- Dead Perserver Druid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100389 AND `DifficultyID`=0); -- Cruel Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109774 WHERE (`Entry`=100364 AND `DifficultyID`=1); -- Spirit of Vengeance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=4, `CreatureDifficultyID`=100872, `TypeFlags`=104, `TypeFlags2`=128 WHERE (`Entry`=100362 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100871, `TypeFlags2`=128 WHERE (`Entry`=100361 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=4, `CreatureDifficultyID`=100870, `TypeFlags`=104, `TypeFlags2`=128 WHERE (`Entry`=100360 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100869, `TypeFlags2`=128 WHERE (`Entry`=100359 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=4, `CreatureDifficultyID`=100864, `TypeFlags`=104, `TypeFlags2`=128 WHERE (`Entry`=100354 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100863, `TypeFlags2`=128 WHERE (`Entry`=100353 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109777 WHERE (`Entry`=100351 AND `DifficultyID`=1); -- Avatar of Vengeance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100336 AND `DifficultyID`=1); -- Creeping Doom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100285 AND `DifficultyID`=1); -- Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100250 AND `DifficultyID`=1); -- Binder Ashioi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100249 AND `DifficultyID`=1); -- Channeler Varisz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100248 AND `DifficultyID`=1); -- Ritualist Lesha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=100216 AND `DifficultyID`=1); -- Hatecoil Wrangler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100697, `TypeFlags2`=128 WHERE (`Entry`=100188 AND `DifficultyID`=1); -- Piercing Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109783 WHERE (`Entry`=99956 AND `DifficultyID`=1); -- Fel-Infused Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99922 AND `DifficultyID`=1); -- Ebonclaw Packmate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (99891,97788,97068)); -- Storm Drake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99873 AND `DifficultyID`=1); -- Moonbeak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99872 AND `DifficultyID`=1); -- Marin Bladewing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99870 AND `DifficultyID`=1); -- Malace Shade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (99868,95674)); -- Fenryr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99865 AND `DifficultyID`=0); -- Glazer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (99858,98538)); -- Lady Velandras Ravencrest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (99857,98521)); -- Lord Etheldrin Ravencrest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99852 AND `DifficultyID`=1); -- Monsoon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99837 AND `DifficultyID`=1); -- Qiraji Mindslayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99828 AND `DifficultyID`=1); -- Trained Hawk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99806 AND `DifficultyID`=1); -- Ozruk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99804 AND `DifficultyID`=1); -- Valarjar Falconer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100311, `TypeFlags2`=128 WHERE (`Entry`=99803 AND `DifficultyID`=1); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=4, `CreatureDifficultyID`=100309, `TypeFlags`=2097256, `TypeFlags2`=128 WHERE (`Entry`=99801 AND `DifficultyID`=1); -- Destructor Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100308, `TypeFlags2`=128 WHERE (`Entry`=99800 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99721 AND `DifficultyID`=0); -- Dark Iron Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99697 AND `DifficultyID`=0); -- Mobile Alert System
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99696 AND `DifficultyID`=0); -- Son of Arugal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99695 AND `DifficultyID`=0); -- Molten Colossus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99692 AND `DifficultyID`=0); -- Kor'kron Shadowmage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99685 AND `DifficultyID`=0); -- Viscidus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99684 AND `DifficultyID`=0); -- Amani'shi Warbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99683 AND `DifficultyID`=0); -- Amani Bear Mount
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99682 AND `DifficultyID`=0); -- Tormented Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99681 AND `DifficultyID`=0); -- Wailing Guardsman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99680 AND `DifficultyID`=0); -- Ghostly Commander
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109735 WHERE (`Entry`=99678 AND `DifficultyID`=1); -- Lingering Corruption
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99677 AND `DifficultyID`=0); -- Eye Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99664 AND `DifficultyID`=1); -- Restless Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99663 AND `DifficultyID`=0); -- Frustrated Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109744 WHERE (`Entry`=99657 AND `DifficultyID`=1); -- Deranged Mindflayer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109747 WHERE (`Entry`=99655 AND `DifficultyID`=1); -- Void-Touched Juggernaut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109750 WHERE (`Entry`=99651 AND `DifficultyID`=1); -- Faceless Voidcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109753 WHERE (`Entry`=99649 AND `DifficultyID`=1); -- Dreadlord Mendacius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99648 AND `DifficultyID`=0); -- Flesh Golemn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99646 AND `DifficultyID`=0); -- Gastropod
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99643 AND `DifficultyID`=0); -- Krustallos
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99642 AND `DifficultyID`=0); -- Bandit Lord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99641 AND `DifficultyID`=0); -- Pillager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (99630,99629,95940)); -- Bitterbrine Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99611 AND `DifficultyID`=0); -- Dantalionax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (99488,99486)); -- Bradley Mk III Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99487 AND `DifficultyID`=0); -- Main Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99453 AND `DifficultyID`=0); -- Fire Cloud
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99447 AND `DifficultyID`=0); -- Skeletal Sorcerer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99444 AND `DifficultyID`=0); -- Storm Gale
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99426 AND `DifficultyID`=1); -- Staellis Rivermoor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99392 AND `DifficultyID`=0); -- Plane
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99390 AND `DifficultyID`=0); -- Moto
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99388 AND `DifficultyID`=0); -- Demolisher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99382 AND `DifficultyID`=0); -- Warhead
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99381 AND `DifficultyID`=0); -- Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99380 AND `DifficultyID`=0); -- Bradley Mk III
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99378 AND `DifficultyID`=0); -- Corrupted Stag [PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99373 AND `DifficultyID`=0); -- Nightmare Imp [PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99369 AND `DifficultyID`=0); -- Corrupted Bat [PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99368 AND `DifficultyID`=0); -- Corrupted Wasp Swarmer[PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99367 AND `DifficultyID`=0); -- Corrupted Wasp Elite [PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106427 WHERE (`Entry`=99366 AND `DifficultyID`=1); -- Taintheart Summoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106425 WHERE (`Entry`=99365 AND `DifficultyID`=1); -- Taintheart Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99364 AND `DifficultyID`=0); -- Nightmare Felstalker[PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99361 AND `DifficultyID`=0); -- Corrupted Vine[PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106397 WHERE (`Entry`=99360 AND `DifficultyID`=1); -- Vilethorn Blossom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=112921 WHERE (`Entry`=99359 AND `DifficultyID`=1); -- Rotheart Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=110453 WHERE (`Entry`=99358 AND `DifficultyID`=1); -- Rotheart Dryad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99355 AND `DifficultyID`=0); -- Corrupted Treant [PH]
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99300 AND `DifficultyID`=0); -- Water Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99277 AND `DifficultyID`=1); -- Freeze Statue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99240 AND `DifficultyID`=1); -- Countermeasures
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109720 WHERE (`Entry`=99233 AND `DifficultyID`=1); -- Ember
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99202 AND `DifficultyID`=0); -- Vardalla
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99201 AND `DifficultyID`=0); -- Nuada
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106419 WHERE (`Entry`=99200 AND `DifficultyID`=1); -- Dresaron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99198 AND `DifficultyID`=1); -- Tirathon Saltheril
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=106437, `TypeFlags2`=128 WHERE (`Entry`=99192 AND `DifficultyID`=1); -- Shade of Xavius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=99090 AND `DifficultyID`=1); -- Soul Echoes Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98970 AND `DifficultyID`=1); -- Latosius
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109723 WHERE (`Entry`=98963 AND `DifficultyID`=1); -- Blazing Imp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109726 WHERE (`Entry`=98954 AND `DifficultyID`=1); -- Felsworn Myrmidon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98949 AND `DifficultyID`=1); -- Smashspite the Hateful
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109732 WHERE (`Entry`=98926 AND `DifficultyID`=1); -- Shadow Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98900 AND `DifficultyID`=1); -- Wyrmtongue Trickster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98848 AND `DifficultyID`=0); -- Corrupted Runecarver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98813 AND `DifficultyID`=1); -- Bloodscent Felhound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98810 AND `DifficultyID`=1); -- Wrathguard Bladelord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98806 AND `DifficultyID`=1); -- Soul Essence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98780 AND `DifficultyID`=0); -- Slavering Felbat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108527 WHERE (`Entry`=98770 AND `DifficultyID`=1); -- Wrathguard Felblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.5, `CreatureDifficultyID`=99267, `TypeFlags`=2097224, `TypeFlags2`=128 WHERE (`Entry`=98761 AND `DifficultyID`=1); -- Soul Fragment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108552 WHERE (`Entry`=98759 AND `DifficultyID`=1); -- Vicious Manafang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108564 WHERE (`Entry`=98756 AND `DifficultyID`=1); -- Arcane Anomaly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108516 WHERE (`Entry`=98733 AND `DifficultyID`=1); -- Withered Fiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108520 WHERE (`Entry`=98732 AND `DifficultyID`=1); -- Plagued Rat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108514 WHERE (`Entry`=98728 AND `DifficultyID`=1); -- Acidic Bile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98706 AND `DifficultyID`=1); -- Commander Shemdah'sohn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=1.299999952316284179, `CreatureDifficultyID`=99199, `TypeFlags`=2097224, `TypeFlags2`=128 WHERE (`Entry`=98693 AND `DifficultyID`=1); -- Shackled Servitor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98691 AND `DifficultyID`=1); -- Risen Scout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98682 AND `DifficultyID`=0); -- Curse of the Witch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98681 AND `DifficultyID`=1); -- Rook Spinner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98637 AND `DifficultyID`=0); -- Ancient Widow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98542 AND `DifficultyID`=1); -- Amalgam of Souls
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98535 AND `DifficultyID`=0); -- Imp Mother Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109698 WHERE (`Entry`=98533 AND `DifficultyID`=1); -- Foul Mother
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108605 WHERE (`Entry`=98435 AND `DifficultyID`=1); -- Unstable Oozeling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108603 WHERE (`Entry`=98426 AND `DifficultyID`=1); -- Unstable Ooze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108510 WHERE (`Entry`=98425 AND `DifficultyID`=1); -- Unstable Amalgamation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104628 WHERE (`Entry`=98406 AND `DifficultyID`=1); -- Embershard Scorpion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104625 WHERE (`Entry`=98384 AND `DifficultyID`=1); -- Razormouth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98370 AND `DifficultyID`=1); -- Ghostly Councilor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98368 AND `DifficultyID`=1); -- Ghostly Protector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98366 AND `DifficultyID`=1); -- Ghostly Retainer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=4, `CreatureDifficultyID`=98869, `TypeFlags`=104, `TypeFlags2`=128 WHERE (`Entry`=98363 AND `DifficultyID`=1); -- Grasping Tentacle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98362 AND `DifficultyID`=1); -- Troubled Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98293 AND `DifficultyID`=1); -- Saltsea Globule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98275 AND `DifficultyID`=1); -- Risen Archer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98271 AND `DifficultyID`=1); -- Felsworn Infester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98246 AND `DifficultyID`=0); -- Risen Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98243 AND `DifficultyID`=1); -- Soul-Torn Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108572, `TypeFlags2`=128 WHERE (`Entry`=98208 AND `DifficultyID`=1); -- Advisor Vandros
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108554, `TypeFlags2`=128 WHERE (`Entry`=98207 AND `DifficultyID`=1); -- Nal'tira
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108547, `TypeFlags2`=128 WHERE (`Entry`=98206 AND `DifficultyID`=1); -- General Xakal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108560, `TypeFlags2`=128 WHERE (`Entry`=98205 AND `DifficultyID`=1); -- Corstilax
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=108570 WHERE (`Entry`=98203 AND `DifficultyID`=1); -- Ivanyr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98201 AND `DifficultyID`=1); -- Enraged Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109647 WHERE (`Entry`=98177 AND `DifficultyID`=1); -- Glayvianna Soulrender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=98173 AND `DifficultyID`=1); -- Mystic Ssa'veh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=1 AND `Entry` IN (98118,98082)); -- Lens
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104655 WHERE (`Entry`=98081 AND `DifficultyID`=1); -- Bellowing Idol
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97960 AND `DifficultyID`=1); -- Dancing Blade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97916 AND `DifficultyID`=1); -- Quake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97853 AND `DifficultyID`=1); -- Sand Dune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97844 AND `DifficultyID`=1); -- Call the Seas
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97795 AND `DifficultyID`=1); -- Static Field
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97739 AND `DifficultyID`=1); -- Tidal Wave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=105456 WHERE (`Entry`=97720 AND `DifficultyID`=1); -- Blightshard Skitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97713 AND `DifficultyID`=1); -- Lightning Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=207476 WHERE (`Entry`=97691 AND `DifficultyID`=1); -- Arcane Bomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97681 AND `DifficultyID`=1); -- Demon Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109708 WHERE (`Entry`=97678 AND `DifficultyID`=1); -- Aranasi Broodmother
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109711 WHERE (`Entry`=97677 AND `DifficultyID`=1); -- Barbed Spiderling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97673 AND `DifficultyID`=1); -- Mystic Tornado
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97269 AND `DifficultyID`=1); -- Hatecoil Crestrider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97264 AND `DifficultyID`=1); -- Hatecoil Shellbreaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97263 AND `DifficultyID`=1); -- Sinkhole
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97260 AND `DifficultyID`=1); -- Arcane Hydra Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97259 AND `DifficultyID`=1); -- Blazing Hydra Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97232 AND `DifficultyID`=0) OR (`Entry`=97197 AND `DifficultyID`=1); -- Valarjar Purifier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97219 AND `DifficultyID`=1) OR (`Entry`=95807 AND `DifficultyID`=0); -- Solsten
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97202 AND `DifficultyID`=1) OR (`Entry`=95672 AND `DifficultyID`=0); -- Olmyr the Enlightened
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97173 AND `DifficultyID`=1); -- Restless Tides
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97172 AND `DifficultyID`=1); -- Saltsea Droplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97171 AND `DifficultyID`=1); -- Hatecoil Arcanist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97170 AND `DifficultyID`=1); -- Hatecoil Wavebinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=97598, `TypeFlags`=1024 WHERE (`Entry`=97099 AND `DifficultyID`=1); -- Swirling Pool
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97087 AND `DifficultyID`=1); -- Valarjar Champion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97084 AND `DifficultyID`=1); -- King Tor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97083 AND `DifficultyID`=1); -- King Ranulf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=97081 AND `DifficultyID`=1); -- King Bjorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96934 AND `DifficultyID`=1); -- Valarjar Trapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96933 AND `DifficultyID`=0); -- Underlings
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=249.600006103515625, `CreatureDifficultyID`=97258, `TypeFlags`=2097260, `TypeFlags2`=128 WHERE (`Entry`=96759 AND `DifficultyID`=1); -- Helya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96677 AND `DifficultyID`=1); -- Steeljaw Grizzly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96664 AND `DifficultyID`=1); -- Valarjar Runecarver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109671 WHERE (`Entry`=96657 AND `DifficultyID`=1); -- Blade Dancer Illianna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96647 AND `DifficultyID`=0); -- Earlnoc the Beastbreaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96646 AND `DifficultyID`=0) OR (`Entry`=95833 AND `DifficultyID`=1); -- Hyrja
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96640 AND `DifficultyID`=1); -- Valarjar Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96611 AND `DifficultyID`=1); -- Angerhoof Bull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96609 AND `DifficultyID`=1); -- Gildedfur Stag
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96608 AND `DifficultyID`=1); -- Ebonclaw Worg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109674 WHERE (`Entry`=96587 AND `DifficultyID`=1); -- Felsworn Infester
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109677 WHERE (`Entry`=96584 AND `DifficultyID`=1); -- Immoliant Fury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96574 AND `DifficultyID`=1); -- Stormforged Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96524 AND `DifficultyID`=1); -- Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=103788, `TypeFlags2`=128 WHERE (`Entry`=96512 AND `DifficultyID`=1); -- Archdruid Glaidalis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109689 WHERE (`Entry`=96480 AND `DifficultyID`=1); -- Viletongue Belcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104623 WHERE (`Entry`=96247 AND `DifficultyID`=1); -- Vileshard Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96241 AND `DifficultyID`=1); -- Hatred
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=96028 AND `DifficultyID`=1); -- Wrath of Azshara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109650 WHERE (`Entry`=96015 AND `DifficultyID`=1); -- Inquisitor Tormentorum
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95947 AND `DifficultyID`=1); -- Mak'rana Hardshell
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95939 AND `DifficultyID`=1); -- Skrog Tidestomper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95920 AND `DifficultyID`=1); -- Animated Storm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109653, `TypeFlags2`=128 WHERE (`Entry`=95888 AND `DifficultyID`=1); -- Cordana Felsong
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109656, `TypeFlags2`=128 WHERE (`Entry`=95887 AND `DifficultyID`=1); -- Glazer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109659, `TypeFlags2`=128 WHERE (`Entry`=95886 AND `DifficultyID`=1); -- Ash'Golm
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=109662, `TypeFlags2`=128 WHERE (`Entry`=95885 AND `DifficultyID`=1); -- Tirathon Saltheril
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95883 AND `DifficultyID`=0); -- Lieutenant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95878 AND `DifficultyID`=0); -- Soldier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95861 AND `DifficultyID`=1); -- Hatecoil Oracle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95843 AND `DifficultyID`=1); -- King Haldor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95842 AND `DifficultyID`=1); -- Valarjar Thundercaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95834 AND `DifficultyID`=1); -- Valarjar Mystic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95831 AND `DifficultyID`=0); -- Ascended Valkyra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104438 WHERE (`Entry`=95779 AND `DifficultyID`=1); -- Festerhide Grizzly
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104436 WHERE (`Entry`=95772 AND `DifficultyID`=1); -- Frenzied Nightclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104434 WHERE (`Entry`=95771 AND `DifficultyID`=1); -- Dreadsoul Ruiner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=111971 WHERE (`Entry`=95769 AND `DifficultyID`=1); -- Mindshattered Screecher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=111973 WHERE (`Entry`=95766 AND `DifficultyID`=1); -- Crazed Razorbeak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95676 AND `DifficultyID`=1); -- Odyn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=95675 AND `DifficultyID`=1); -- God-King Skovald
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=94968 AND `DifficultyID`=1); -- Valarjar Stormrider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=94960 AND `DifficultyID`=1); -- Hymdall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=94331 AND `DifficultyID`=1); -- Petrifying Crystal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=94224 AND `DifficultyID`=1); -- Petrifying Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104621 WHERE (`Entry`=92612 AND `DifficultyID`=1); -- Mightstone Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104619 WHERE (`Entry`=92610 AND `DifficultyID`=1); -- Understone Drummer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104617 WHERE (`Entry`=92538 AND `DifficultyID`=1); -- Tarspitter Grub
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`DifficultyID`=0 AND `Entry` IN (92497,92490)); -- Coiled Rope
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=92473 AND `DifficultyID`=1); -- Empty Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=107197 WHERE (`Entry`=92387 AND `DifficultyID`=1); -- Drums of War
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104611 WHERE (`Entry`=92350 AND `DifficultyID`=1); -- Understone Drudge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91808 AND `DifficultyID`=1); -- Serpentrix
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91797 AND `DifficultyID`=1); -- King Deepbeard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91796 AND `DifficultyID`=1); -- Skrog Wavecrasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91794 AND `DifficultyID`=1); -- Saltscale Lurker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91793 AND `DifficultyID`=1); -- Seaspray Crab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91792 AND `DifficultyID`=1); -- Stormwake Hydra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91790 AND `DifficultyID`=1); -- Mak'rana Siltwalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91789 AND `DifficultyID`=1); -- Lady Hatecoil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91788 AND `DifficultyID`=0); -- Shellmaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91787 AND `DifficultyID`=1); -- Cove Seagull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91786 AND `DifficultyID`=1); -- Gritslime Snail
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91785 AND `DifficultyID`=1); -- Wandering Shellback
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91784 AND `DifficultyID`=1); -- Warlord Parjesh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91783 AND `DifficultyID`=1); -- Hatecoil Stormweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91782 AND `DifficultyID`=1); -- Hatecoil Crusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6 WHERE (`Entry`=91781 AND `DifficultyID`=1); -- Hatecoil Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=5, `CreatureDifficultyID`=104609 WHERE (`Entry`=91332 AND `DifficultyID`=1); -- Stoneclaw Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104607 WHERE (`Entry`=91008 AND `DifficultyID`=1); -- Rockbound Pelter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104652, `TypeFlags2`=128 WHERE (`Entry`=91007 AND `DifficultyID`=1); -- Dargrul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104605 WHERE (`Entry`=91006 AND `DifficultyID`=1); -- Rockback Gnasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104650, `TypeFlags2`=128 WHERE (`Entry`=91005 AND `DifficultyID`=1); -- Naraxas
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104648, `TypeFlags2`=128 WHERE (`Entry`=91004 AND `DifficultyID`=1); -- Ularogg Cragshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104646, `TypeFlags2`=128 WHERE (`Entry`=91003 AND `DifficultyID`=1); -- Rokmora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104603 WHERE (`Entry`=91002 AND `DifficultyID`=1); -- Rotdrool Grabber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104601 WHERE (`Entry`=91001 AND `DifficultyID`=1); -- Tarspitter Lurker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104599 WHERE (`Entry`=91000 AND `DifficultyID`=1); -- Vileshard Hulk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104594 WHERE (`Entry`=90998 AND `DifficultyID`=1); -- Blightshard Shaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=104592 WHERE (`Entry`=90997 AND `DifficultyID`=1); -- Mightstone Breaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (89184,89183,89182,89181,89180)) OR (`DifficultyID`=1 AND `Entry` IN (83033,83032,83030,81120)); -- The Grimrail
UPDATE `creature_template_difficulty` SET `HealthModifier`=10 WHERE (`Entry`=89089 AND `DifficultyID`=1); -- Prince Farondis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=89022 AND `DifficultyID`=1); -- Wolf Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=89021 AND `DifficultyID`=1); -- Rylak Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=89012 AND `DifficultyID`=1); -- Ravenous Wolf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=89011 AND `DifficultyID`=1); -- Rylak Skyterror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (89003,75507)); -- Weeping Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88862 AND `DifficultyID`=1); -- Enchanted Waters
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry`=88858) OR (`DifficultyID`=1 AND `Entry` IN (75966,75451)); -- Defiled Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88758 AND `DifficultyID`=1); -- Ogre Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry`=88662) OR (`DifficultyID`=1 AND `Entry` IN (77961,77695,76592)); -- Auchenai Arbiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry`=88661) OR (`DifficultyID`=1 AND `Entry` IN (77960,77696)); -- Auchenai Soulpriest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (88660,76573)) OR (`DifficultyID`=1 AND `Entry` IN (77704,76572)); -- Auchenai Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88659 AND `DifficultyID`=0) OR (`Entry`=76595 AND `DifficultyID`=1); -- Sargerei Soulpriest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (88658,77080)); -- Sargerei Arbiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88656 AND `DifficultyID`=0) OR (`Entry`=77935 AND `DifficultyID`=1); -- Sargerei Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88622 AND `DifficultyID`=0); -- Winter Veil Commander Tharbek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88621 AND `DifficultyID`=0); -- Winter Veil Ner'zhul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88620 AND `DifficultyID`=0); -- Winter Veil Oshir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88619 AND `DifficultyID`=0); -- Winter Veil Gug'rokk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88618 AND `DifficultyID`=0); -- Winter Veil Soulbinder Nyami
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88218 AND `DifficultyID`=1); -- Iron Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=88163 AND `DifficultyID`=1); -- Grom'kar Cinderseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=87252 AND `DifficultyID`=1); -- Unruly Ogron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=87219 AND `DifficultyID`=1); -- Auchindoun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (87218,75927)) OR (`DifficultyID`=0 AND `Entry`=86219); -- Azzakel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=87142 AND `DifficultyID`=1); -- Trash Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (87075,77963,77694,76596)); -- Auchenai Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (87074,76263)); -- Sargerei Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (87073,77042)); -- Sargerei Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=87069 AND `DifficultyID`=0) OR (`Entry`=79248 AND `DifficultyID`=1); -- Soulbinder Tuulani
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86919 AND `DifficultyID`=0); -- Empowered Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86918 AND `DifficultyID`=1); -- Uncharged Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86809 AND `DifficultyID`=1); -- Grom'kar Incinerator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86684 AND `DifficultyID`=1); -- Feral Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86622 AND `DifficultyID`=0); -- Health Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86565 AND `DifficultyID`=1); -- Whirling Chains
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86534 AND `DifficultyID`=1); -- Hammer Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86533 AND `DifficultyID`=0); -- Awbee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86526 AND `DifficultyID`=1); -- Grom'kar Chainmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86427 AND `DifficultyID`=0); -- Ground
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86372 AND `DifficultyID`=1); -- Melded Berserker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86253 AND `DifficultyID`=0); -- Warlord Zaela
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86252,77063)) OR (`DifficultyID`=1 AND `Entry`=76585); -- Ragewing the Untamed
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86251 AND `DifficultyID`=0) OR (`Entry`=79912 AND `DifficultyID`=1); -- Commander Tharbek
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86250 AND `DifficultyID`=0); -- Kyrak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86249 AND `DifficultyID`=0) OR (`Entry`=76413 AND `DifficultyID`=1); -- Orebender Gor'ashan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry`=86248) OR (`DifficultyID`=1 AND `Entry` IN (84336,83846)); -- Yalnu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86247,84666)); -- Xeri'tac
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86246 AND `DifficultyID`=0) OR (`Entry`=82682 AND `DifficultyID`=1); -- Archmage Sol
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86245 AND `DifficultyID`=0) OR (`Entry`=83894 AND `DifficultyID`=1); -- Dulhu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86244 AND `DifficultyID`=0) OR (`Entry`=83893 AND `DifficultyID`=1); -- Earthshaper Telu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86243 AND `DifficultyID`=0) OR (`Entry`=83892 AND `DifficultyID`=1); -- Life Warden Gola
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86242 AND `DifficultyID`=0) OR (`Entry`=81522 AND `DifficultyID`=1); -- Witherbark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86236 AND `DifficultyID`=0) OR (`Entry`=75452 AND `DifficultyID`=1); -- Bonemaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86235 AND `DifficultyID`=0) OR (`Entry`=75829 AND `DifficultyID`=1); -- Nhallish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86234 AND `DifficultyID`=0) OR (`Entry`=75509 AND `DifficultyID`=1); -- Sadana Bloodfury
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86233 AND `DifficultyID`=0) OR (`Entry`=83612 AND `DifficultyID`=1); -- Skulloc
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86232 AND `DifficultyID`=0) OR (`Entry`=79852 AND `DifficultyID`=1); -- Oshir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86231 AND `DifficultyID`=0) OR (`Entry`=80805 AND `DifficultyID`=1); -- Makogg Emberblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86230 AND `DifficultyID`=0) OR (`Entry`=80816 AND `DifficultyID`=1); -- Ahri'ok Dugru
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86229 AND `DifficultyID`=0) OR (`Entry`=81305 AND `DifficultyID`=1); -- Fleshrender Nok'gar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86228 AND `DifficultyID`=0) OR (`Entry`=80005 AND `DifficultyID`=1); -- Skylord Tovra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86227 AND `DifficultyID`=0) OR (`Entry`=79545 AND `DifficultyID`=1); -- Nitrogg Thundertower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86226 AND `DifficultyID`=0) OR (`Entry`=77816 AND `DifficultyID`=1); -- Borka the Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86224 AND `DifficultyID`=0) OR (`Entry`=74790 AND `DifficultyID`=1); -- Gug'rokk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86223,81679)) OR (`DifficultyID`=1 AND `Entry`=75786); -- Roltall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86222 AND `DifficultyID`=0) OR (`Entry`=74787 AND `DifficultyID`=1); -- Slave Watcher Crushto
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86221 AND `DifficultyID`=0) OR (`Entry`=74475 AND `DifficultyID`=1); -- Magmolatus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86220,77835,77814,77811)) OR (`DifficultyID`=1 AND `Entry`=77734); -- Teron'gor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86218,76329)) OR (`DifficultyID`=1 AND `Entry` IN (77810,76177)); -- Soulbinder Nyami
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=86217 AND `DifficultyID`=0) OR (`Entry`=75839 AND `DifficultyID`=1); -- Vigilant Kaathar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=0 AND `Entry` IN (86013,86011)); -- Loading Chain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85993 AND `DifficultyID`=1); -- Slag Crucible
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85541 AND `DifficultyID`=1); -- Portal to Shadowmoon Valley
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85496 AND `DifficultyID`=1); -- Undermage Kesalon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=84820 WHERE (`Entry`=85232 AND `DifficultyID`=1); -- Infested Venomfang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (85194,84499)); -- Entanglement
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (85188,76157)); -- Black Iron Leadbelcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85170 AND `DifficultyID`=1); -- Fire Orchid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85116 AND `DifficultyID`=1); -- Golden Lion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85107 AND `DifficultyID`=1); -- Font of Life Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=85105 AND `DifficultyID`=1); -- Glowbulb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84990 AND `DifficultyID`=1); -- Addled Arcanomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84989 AND `DifficultyID`=1); -- Infested Icecaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (84978,83624)); -- Bloodmaul Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84964 AND `DifficultyID`=1); -- Colossal Blow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84957 AND `DifficultyID`=1); -- Putrid Pyromancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84869 AND `DifficultyID`=0); -- Entangling Vine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84848 AND `DifficultyID`=1); -- Red Arrow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (84782,81273)); -- Reshad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84767 AND `DifficultyID`=1); -- Twisted Abomination
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84677 AND `DifficultyID`=1); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84664 AND `DifficultyID`=1); -- Grow Weapon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84520 AND `DifficultyID`=1); -- Pitwarden Gwarnok
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84475 AND `DifficultyID`=0) OR (`Entry`=77035 AND `DifficultyID`=1); -- Black Iron Dreadweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84464 AND `DifficultyID`=1); -- Backdraft
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84462 AND `DifficultyID`=0) OR (`Entry`=77034 AND `DifficultyID`=1); -- Black Iron Veteran
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84401 AND `DifficultyID`=1); -- Swift Sproutling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84400 AND `DifficultyID`=1); -- Flourishing Ancient
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84399 AND `DifficultyID`=1); -- Vicious Mandragora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84358 AND `DifficultyID`=1); -- Lady Baihu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84329 AND `DifficultyID`=1); -- Kirin Tor Battle-Mage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84215 AND `DifficultyID`=1); -- Blackhand's Might Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (84109,84030)); -- Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84028 AND `DifficultyID`=1); -- Siegemaster Rokra
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=84008 AND `DifficultyID`=1); -- Bramble Patch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83816 AND `DifficultyID`=1); -- World Trigger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83808 AND `DifficultyID`=1); -- Exploding Flames
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83789 AND `DifficultyID`=1); -- Board the Grimrail
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83787 AND `DifficultyID`=0); -- Lightning Cage Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83782 AND `DifficultyID`=0); -- Lightning Cage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83778,83672)); -- Troop Transport
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83777 AND `DifficultyID`=1); -- Ironhoof Packbeast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83776,81279)) OR (`DifficultyID`=0 AND `Entry`=83767); -- Grom'kar Flameslinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83775,83761,83578)); -- Ogron Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83766 AND `DifficultyID`=0) OR (`Entry`=83025 AND `DifficultyID`=1); -- Grom'kar Battlemaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83764,83028)); -- Grom'kar Deadeye
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83763,81432)); -- Grom'kar Technician
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83762,83697)); -- Grom'kar Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83757,83756,83755,83753)); -- Dragonspawn Refugee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83752,82556,76018)); -- Drakonid Monstrosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83747,83671)); -- Train
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83745,76801)); -- Ragewing Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83709 AND `DifficultyID`=0); -- Iron Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83682 AND `DifficultyID`=1); -- Guncar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83676 AND `DifficultyID`=1); -- Flatbed
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83673 AND `DifficultyID`=1); -- Engine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83650 AND `DifficultyID`=1); -- Earth Crush Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83623,75210)); -- Bloodmaul Warder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83622,75272)); -- Bloodmaul Ogre Mage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83621,74349)); -- Bloodmaul Magma Binder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83620,75814,75214)) OR (`DifficultyID`=0 AND `Entry`=75505); -- Bloodmaul Earthbreaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83616 AND `DifficultyID`=1); -- Zoggosh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83613 AND `DifficultyID`=1); -- Koramar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83480,82429)); -- Black Iron Wyrm Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83479,82428,77180)); -- Emberscale Ironflight
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83392 AND `DifficultyID`=1); -- Rampaging Clefthoof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83390 AND `DifficultyID`=1); -- Thunderlord Wrangler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83389 AND `DifficultyID`=1); -- Ironwing Flamespitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83050 AND `DifficultyID`=1); -- Hissing Crate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (83027,79905)); -- Grimrail Depot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=83026 AND `DifficultyID`=1); -- Siegemaster Olugar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82846 AND `DifficultyID`=1); -- Frozen Rain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82735 AND `DifficultyID`=0) OR (`Entry`=77075 AND `DifficultyID`=1); -- Leeroy Jenkins
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (82721,78843)); -- Blackrock Turret
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82681 AND `DifficultyID`=1); -- Shield Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82597 AND `DifficultyID`=1); -- Grom'kar Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82594 AND `DifficultyID`=1); -- Grimrail Loader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82590 AND `DifficultyID`=1); -- Grimrail Scout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82579 AND `DifficultyID`=1); -- Grom'kar Far Seer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82480 AND `DifficultyID`=1); -- Emberscale Matron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82418 AND `DifficultyID`=1); -- Black Iron Rageguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82376 AND `DifficultyID`=1); -- Shadow-Sage Iskar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82184 AND `DifficultyID`=1); -- Ability Sequencer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82097 AND `DifficultyID`=0); -- Sapling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82086 AND `DifficultyID`=0); -- Thornvine Flytrap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82039 AND `DifficultyID`=1); -- Rockspine Stinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=82030 AND `DifficultyID`=0); -- Rockspine Bloodletter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81985 AND `DifficultyID`=1); -- Everbloom Cultivator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81984 AND `DifficultyID`=1); -- Gnarlroot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81983 AND `DifficultyID`=1); -- Verdant Mandragora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81904 AND `DifficultyID`=0); -- Podling Sprout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81903 AND `DifficultyID`=1); -- Vibrant Axebeak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81881 AND `DifficultyID`=1); -- Mouth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81872 AND `DifficultyID`=0); -- Podling Thorntwister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81871 AND `DifficultyID`=0); -- Podling Poisonspitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81869 AND `DifficultyID`=0); -- Podling Shrubterror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81864 AND `DifficultyID`=1); -- Dreadpetal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81834 AND `DifficultyID`=1); -- Priceless Paraphernalia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81832 AND `DifficultyID`=1); -- Shredding Swipes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (81821,81638)); -- Aqueous Globule
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81820 AND `DifficultyID`=1); -- Everbloom Mender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81819 AND `DifficultyID`=1); -- Everbloom Naturalist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81767 AND `DifficultyID`=1); -- Bloodmaul Flamespeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81750 AND `DifficultyID`=1); -- Bloodmaul Ogron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (81737,81564)); -- Unchecked Growth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81603 AND `DifficultyID`=1); -- Champion Druna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81439 AND `DifficultyID`=1); -- Iron Owl
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81407 AND `DifficultyID`=1); -- Grimrail Bombardier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81298 AND `DifficultyID`=0); -- Teleport Transform
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81297 AND `DifficultyID`=1); -- Dreadfang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81293 AND `DifficultyID`=1); -- Iron Star Mk. III
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81247 AND `DifficultyID`=1); -- Iron Star
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81236 AND `DifficultyID`=1); -- Grimrail Technician
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81235 AND `DifficultyID`=1); -- Grimrail Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81221 AND `DifficultyID`=0); -- Iron Horde Warmachine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81212 AND `DifficultyID`=1); -- Grimrail Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81139 AND `DifficultyID`=0) OR (`Entry`=75976 AND `DifficultyID`=1); -- Low-Born Arakkoa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81088 AND `DifficultyID`=1); -- Arakkoa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (81081,81080,81049)) OR (`DifficultyID`=0 AND `Entry`=79051); -- Kaliri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81048 AND `DifficultyID`=1); -- Kaliri Perch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81040 AND `DifficultyID`=1); -- Spinning Slash
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=81032 AND `DifficultyID`=0) OR (`Entry`=75242 AND `DifficultyID`=1); -- Croman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80938 AND `DifficultyID`=1); -- Grom'kar Hulk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80918 AND `DifficultyID`=1); -- Grimrail Siege Gun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80875 AND `DifficultyID`=1); -- Bombsquad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80808 AND `DifficultyID`=1); -- Neesa Nox
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80703 AND `DifficultyID`=0); -- Windfury Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80678 AND `DifficultyID`=1); -- Black Iron Flame Reaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80649 AND `DifficultyID`=1); -- Black Iron Wyrmcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80603 AND `DifficultyID`=0); -- Siege Engine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80518 AND `DifficultyID`=1); -- Better Position Location
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80410 AND `DifficultyID`=0); -- Return to Ground
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80347 AND `DifficultyID`=1); -- Black Iron Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80334 AND `DifficultyID`=1); -- Face Center
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80333 AND `DifficultyID`=1); -- Jump To Location
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80307 AND `DifficultyID`=0); -- Imbued Iron Axe Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80231 AND `DifficultyID`=0); -- Incinerating Breath Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=83386 WHERE (`Entry`=80098 AND `DifficultyID`=1); -- Ironbarb Skyreaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80040 AND `DifficultyID`=0); -- Black Iron Juggernaut
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=80004 AND `DifficultyID`=1); -- Rakun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79985 AND `DifficultyID`=0); -- Roof Walk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79889 AND `DifficultyID`=1); -- Rending Slashes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79850 AND `DifficultyID`=0); -- Verticle Hang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79548 AND `DifficultyID`=1); -- Assault Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (79511,76220)); -- Blazing Trickster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (79510,76260)); -- Cackling Pyromaniac
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (79508,77905)); -- Felborne Abyssal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (79507,76259)); -- Felguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79505 AND `DifficultyID`=1); -- Pile of Ash
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87650 WHERE (`Entry`=79469 AND `DifficultyID`=1); -- Whirling Dervish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79468 AND `DifficultyID`=0); -- Storm Harbinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87652 WHERE (`Entry`=79467 AND `DifficultyID`=1); -- Adept of the Dawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87646 WHERE (`Entry`=79466 AND `DifficultyID`=1); -- Initiate of the Rising Sun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87645 WHERE (`Entry`=79463 AND `DifficultyID`=1); -- Radiant Supernova
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87644 WHERE (`Entry`=79462 AND `DifficultyID`=1); -- Blinding Solar Flare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87654 WHERE (`Entry`=79303 AND `DifficultyID`=1); -- Adorned Bladetalon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79122 AND `DifficultyID`=0); -- Upper Blackrock Spire Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79121 AND `DifficultyID`=0); -- Shaper Dungeon [PH] Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79120 AND `DifficultyID`=0); -- Iron Depot Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79118 AND `DifficultyID`=0); -- Shadowmoon Burial Grounds Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79117 AND `DifficultyID`=0); -- Auchindoun Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79116 AND `DifficultyID`=0); -- Iron Docks Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79115 AND `DifficultyID`=0); -- Bloodmaul Slag Mines Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79093 AND `DifficultyID`=1); -- Skyreach Sun Talon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79053 AND `DifficultyID`=0); -- Dread Ravens
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79052 AND `DifficultyID`=0); -- Skyreach Constructs
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79050 AND `DifficultyID`=0); -- High Arakkoa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79049 AND `DifficultyID`=0); -- Skyreach Slaves
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=79048 AND `DifficultyID`=0); -- Skyreach Overseers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78933 AND `DifficultyID`=1); -- Herald of Sunrise
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87649 WHERE (`Entry`=78932 AND `DifficultyID`=1); -- Driving Gale-Caller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78925 AND `DifficultyID`=0); -- Spires of Arak Credit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78898 AND `DifficultyID`=0); -- Skyreach Life Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78897 AND `DifficultyID`=0); -- Skyreach Life Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78848 AND `DifficultyID`=0); -- Burning Wrathbringer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78735 AND `DifficultyID`=1); -- Zar'shuul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78734 AND `DifficultyID`=1); -- Zipteq
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78731 AND `DifficultyID`=1); -- Khatuun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78728 AND `DifficultyID`=1); -- Shaadum
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78437 AND `DifficultyID`=1); -- Gul'kosh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78342 AND `DifficultyID`=1); -- Electrified Spear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78302 AND `DifficultyID`=0); -- Auchindoun Teleporter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (78095,77948)); -- Auchenai Hoplite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=78094 AND `DifficultyID`=0) OR (`Entry`=77949 AND `DifficultyID`=1); -- Auchenai Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (78093,77950)); -- Auchenai Zealot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (77962,77693,76632)); -- Auchenai Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77952 AND `DifficultyID`=1); -- Auchenai Soulbinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77951 AND `DifficultyID`=1); -- Auchenai Spirit-Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77947 AND `DifficultyID`=1); -- Auchenai Cleric
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77933 AND `DifficultyID`=1); -- Auchenai Anchorite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77927 AND `DifficultyID`=1); -- Son of the Beast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77907 AND `DifficultyID`=0); -- Frenzied Dread Raven
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77890 AND `DifficultyID`=1); -- Durag the Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77889 AND `DifficultyID`=1); -- Grom'tash the Destructor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77832 AND `DifficultyID`=1); -- Soul Aegis
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77819 AND `DifficultyID`=1); -- Auchenai Vigilant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77812 AND `DifficultyID`=1); -- Sargerei Soulbinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77808 AND `DifficultyID`=1); -- Demonic Circle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77803 AND `DifficultyID`=1); -- Railmaster Rocketspark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77762 AND `DifficultyID`=1); -- Vindicator Iruun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77756 AND `DifficultyID`=1); -- Arcanist Joraa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77752 AND `DifficultyID`=1); -- Mender Elum
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77743 AND `DifficultyID`=1); -- High Soulpriest Durem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77700 AND `DifficultyID`=1); -- Shadowmoon Exhumer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77676 AND `DifficultyID`=1); -- Water Burst
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77605 AND `DifficultyID`=1); -- Whirling Dervish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=88166 WHERE (`Entry`=77559 AND `DifficultyID`=1); -- Solar Magnifier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77543 AND `DifficultyID`=1); -- Interior Focus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (77398,76285)); -- Arakkoa Magnifying Glass
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77340 AND `DifficultyID`=0); -- Fledged Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77134 AND `DifficultyID`=1); -- Sargerei Cleric
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77133 AND `DifficultyID`=0); -- Sargerei Hoplite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77132 AND `DifficultyID`=0); -- Sargerei Zealot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77131 AND `DifficultyID`=1); -- Sargerei Spirit-Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77130 AND `DifficultyID`=0); -- Sargerei Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=83394 WHERE (`Entry`=77120 AND `DifficultyID`=1); -- Warlord Zaela
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=83378 WHERE (`Entry`=77096 AND `DifficultyID`=1); -- Vilemaw Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77081 AND `DifficultyID`=0); -- The Lanticore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77037 AND `DifficultyID`=1); -- Black Iron Elite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77036 AND `DifficultyID`=1); -- Black Iron Summoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77033 AND `DifficultyID`=1); -- Black Iron Siegebreaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=77006 AND `DifficultyID`=1); -- Corpse Skitterling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76935 AND `DifficultyID`=1); -- Black Iron Drake-Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76885 AND `DifficultyID`=1); -- Fire Storm Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76837 AND `DifficultyID`=1); -- Engulfing Fire Invisible Stalker L to R
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76813 AND `DifficultyID`=1); -- Engulfing Fire Invisible Stalker R to L
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76778 AND `DifficultyID`=1); -- Life-Pact Familiar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76775 AND `DifficultyID`=0); -- Prism Crafter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76773 AND `DifficultyID`=1); -- Black Iron Apprentice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76696 AND `DifficultyID`=1); -- Emberscale Adolescent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76694 AND `DifficultyID`=1); -- Emberscale Whelpling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76693 AND `DifficultyID`=0); -- Black Iron Flame Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76655 AND `DifficultyID`=1); -- Warden's Hammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76605 AND `DifficultyID`=0); -- Prophetic Vision
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76599 AND `DifficultyID`=1); -- Black Iron Groundshaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76598 AND `DifficultyID`=0) OR (`Entry`=76518 AND `DifficultyID`=1); -- Ritual of Bones
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76568 AND `DifficultyID`=1); -- Liberated Souls Spawner/Cleans up fight on Death
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76514 AND `DifficultyID`=1); -- Malevolence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76466 AND `DifficultyID`=1); -- Psyfiend
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76464 AND `DifficultyID`=1); -- Lightning Field
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76462 AND `DifficultyID`=1); -- Omen of Death
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76446 AND `DifficultyID`=1); -- Shadowmoon Dominator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76444 AND `DifficultyID`=1); -- Subjugated Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76417 AND `DifficultyID`=1); -- Power Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76400 AND `DifficultyID`=1); -- Disturbed Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76396 AND `DifficultyID`=1); -- Rune Glow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76379 AND `DifficultyID`=0) OR (`Entry`=76143 AND `DifficultyID`=1); -- Rukhran
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76376 AND `DifficultyID`=1); -- Skyreach Arcanologist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76367 AND `DifficultyID`=1); -- Sun Construct Energizer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76327 AND `DifficultyID`=0); -- Fallen Soulpriest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76318 AND `DifficultyID`=0); -- Baleful Soulpriest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76315 AND `DifficultyID`=0); -- Black Iron Cannon Base
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76314 AND `DifficultyID`=1); -- Sentry Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (76310,76309,76307,76306,76146,76145)) OR (`DifficultyID`=0 AND `Entry`=76308); -- Grand Defense Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76297 AND `DifficultyID`=1); -- Fallen Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76296 AND `DifficultyID`=0); -- Twisted Magus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76294 AND `DifficultyID`=1); -- Fallen Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76293 AND `DifficultyID`=1); -- Fallen Arbiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76292 AND `DifficultyID`=1); -- Skyreach Shield Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76284 AND `DifficultyID`=0); -- Spiteful Arbiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76283 AND `DifficultyID`=0); -- Malefic Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76275 AND `DifficultyID`=0); -- Shadow Skeleton Transform
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76269 AND `DifficultyID`=1); -- Shackled Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76267 AND `DifficultyID`=1); -- Solar Zealot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76266 AND `DifficultyID`=1); -- High Sage Viryx
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76253 AND `DifficultyID`=1); -- Dread Raven Hatchling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76252 AND `DifficultyID`=0); -- Initiate of the Dawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76250 AND `DifficultyID`=1); -- Inhale
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76227 AND `DifficultyID`=0); -- Solar Flare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76222 AND `DifficultyID`=0); -- Rallying Banner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76216 AND `DifficultyID`=1); -- Claws of Argus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87653 WHERE (`Entry`=76205 AND `DifficultyID`=1); -- Blooded Bladefeather
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76197 AND `DifficultyID`=1); -- Fel Spark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76191 AND `DifficultyID`=0); -- Necrotic Pitch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76190 AND `DifficultyID`=1); -- Liberated Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76181 AND `DifficultyID`=1); -- Ragemaw Worg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76179 AND `DifficultyID`=1); -- Black Iron Grunt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76176 AND `DifficultyID`=1); -- Black Iron Berserker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76154 AND `DifficultyID`=1); -- Skyreach Raven Whisperer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76152 AND `DifficultyID`=1); -- Wind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76151 AND `DifficultyID`=1); -- Black Iron Warcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87660 WHERE (`Entry`=76149 AND `DifficultyID`=1); -- Dread Raven
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76142 AND `DifficultyID`=1); -- Skyreach Sun Construct Prototype
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76141 AND `DifficultyID`=1); -- Araknath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87656 WHERE (`Entry`=76132 AND `DifficultyID`=1); -- Soaring Chakram Master
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76121 AND `DifficultyID`=1) OR (`Entry`=76096 AND `DifficultyID`=0); -- Young Kaliri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76119 AND `DifficultyID`=1); -- Arakkoa Pincer Birds Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=87655 WHERE (`Entry`=76116 AND `DifficultyID`=1); -- Diving Chakram Spinner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76106 AND `DifficultyID`=0); -- Blinding Ray
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76104 AND `DifficultyID`=1); -- Monstrous Corpse Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76102 AND `DifficultyID`=1); -- Air Familiar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76101 AND `DifficultyID`=1); -- Black Iron Engineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76100 AND `DifficultyID`=1); -- Black Iron Alchemist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76099 AND `DifficultyID`=0); -- Black Iron Emissary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76097 AND `DifficultyID`=1); -- Solar Familiar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76095 AND `DifficultyID`=0); -- Windborne Crafter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=88085 WHERE (`Entry`=76094 AND `DifficultyID`=1); -- Sun Trinket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76093 AND `DifficultyID`=0); -- Illuminated Crafter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=88167 WHERE (`Entry`=76087 AND `DifficultyID`=1); -- Defense Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76071 AND `DifficultyID`=1); -- Holy Shield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76052 AND `DifficultyID`=1); -- Dark Eclipse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=76047 AND `DifficultyID`=0) OR (`Entry`=75981 AND `DifficultyID`=1); -- Daggerfall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=83367 WHERE (`Entry`=76021 AND `DifficultyID`=1); -- Kyrak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75979 AND `DifficultyID`=1); -- Exhumed Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75977 AND `DifficultyID`=1); -- Defiled Burial Site
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75975 AND `DifficultyID`=1); -- Skyreach Overlord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5, `CreatureDifficultyID`=88159 WHERE (`Entry`=75964 AND `DifficultyID`=1); -- Ranjit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75899 AND `DifficultyID`=1); -- Possessed Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75865 AND `DifficultyID`=1); -- Heat Wave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75857 AND `DifficultyID`=1); -- Unstable Magma Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (75854,75853,75828)); -- Fiery Boulder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75846 AND `DifficultyID`=1); -- Lava Explosion Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75820 AND `DifficultyID`=1); -- Vengeful Magma Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75778 AND `DifficultyID`=1); -- Shadow Rune
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75760 AND `DifficultyID`=0); -- Cinderweb Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75754 AND `DifficultyID`=1); -- Cinderling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75729 AND `DifficultyID`=1); -- Restless Wanderer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75728 AND `DifficultyID`=1); -- Lost Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75715 AND `DifficultyID`=1); -- Reanimated Ritual Bones
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75713 AND `DifficultyID`=1); -- Shadowmoon Bone-Mender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75652 AND `DifficultyID`=1); -- Void Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (75647,75646)); -- Fleeing Miner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75587 AND `DifficultyID`=0); -- Floating Dagger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75586 AND `DifficultyID`=1); -- Neutral Miner Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75585 AND `DifficultyID`=1); -- Horde Miner Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75584 AND `DifficultyID`=1); -- Alliance Miner Spawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75506 AND `DifficultyID`=1); -- Shadowmoon Loyalist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75499 AND `DifficultyID`=1); -- Ogre Wheel Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75497 AND `DifficultyID`=0); -- Bloodmaul "Supplies"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75460 AND `DifficultyID`=0); -- Crystalline Basilisk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75459 AND `DifficultyID`=1); -- Plagued Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (75454,75427,75199,75196,75195,75192)) OR (`DifficultyID`=0 AND `Entry` IN (75201,75200,75197,75175)); -- Enslaved Miner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (75426,75193)); -- Bloodmaul Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75406 AND `DifficultyID`=1); -- Slagna
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75374 AND `DifficultyID`=1); -- Cave Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75360 AND `DifficultyID`=1); -- Searing Ember
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75327 AND `DifficultyID`=1); -- Pillar of Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75303 AND `DifficultyID`=1); -- Wheel of Pain Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75252 AND `DifficultyID`=1); -- Wheel of Pain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75243 AND `DifficultyID`=0); -- Slag Kindling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75222 AND `DifficultyID`=0); -- Bloodmaul Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75219 AND `DifficultyID`=0); -- Bloodmaul Forge-Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75211 AND `DifficultyID`=1); -- Magma Lord
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75209 AND `DifficultyID`=1); -- Molten Earth Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75198 AND `DifficultyID`=1); -- Bloodmaul Geomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75194 AND `DifficultyID`=1); -- Gnasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75191 AND `DifficultyID`=1); -- Bloodmaul Slaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75174 AND `DifficultyID`=0); -- Dead Goren Burrow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75148 AND `DifficultyID`=0); -- Boulder Debris
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75140 AND `DifficultyID`=0); -- Goren Spawner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=75041 AND `DifficultyID`=0); -- Shardling Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74967 AND `DifficultyID`=1); -- Magma Eruption
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74927 AND `DifficultyID`=1); -- Unstable Slag
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74904 AND `DifficultyID`=0); -- Ground Slam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74791 AND `DifficultyID`=0); -- Hovel Door
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74786 AND `DifficultyID`=0); -- Mok'luk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74766 AND `DifficultyID`=1); -- Shatter Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74579 AND `DifficultyID`=1); -- Molten Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74571 AND `DifficultyID`=1); -- Calamity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74570 AND `DifficultyID`=1); -- Ruination
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=74366 AND `DifficultyID`=1); -- Forgemaster Gog'duh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`DifficultyID`=1 AND `Entry` IN (74357,74356,74355)); -- Captured Miner
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=73718 AND `DifficultyID`=1); -- Southsea Lookout
UPDATE `creature_template_difficulty` SET `HealthModifier`=15 WHERE (`Entry`=73704 AND `DifficultyID`=1); -- Stinkbraid
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=73703 AND `DifficultyID`=1); -- Southsea Plunderer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=73349 AND `DifficultyID`=1); -- Tormented Initiate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=73342 AND `DifficultyID`=1); -- Fallen Pool Tender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (73330,61348)); -- Lorewalker Cho
UPDATE `creature_template_difficulty` SET `HealthModifier`=40 WHERE (`Entry`=73279 AND `DifficultyID`=1); -- Evermaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=73260 AND `DifficultyID`=1); -- Lesser Contaminated Puddle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (73226,73197)); -- Lesser Sha Puddle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (73192,65297)) OR (`DifficultyID`=0 AND `Entry`=71881); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=73191 AND `DifficultyID`=1); -- Aqueous Defender
UPDATE `creature_template_difficulty` SET `HealthModifier`=1 WHERE (`Entry`=73018 AND `DifficultyID`=1); -- Spectral Brewmaster
UPDATE `creature_template_difficulty` SET `HealthModifier`=30 WHERE (`Entry`=72970 AND `DifficultyID`=1); -- Golganarr
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=72876 AND `DifficultyID`=1); -- Crimsonscale Firestorm
UPDATE `creature_template_difficulty` SET `HealthModifier`=1 WHERE (`Entry`=72843 AND `DifficultyID`=1); -- Ironfur Grazer
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=72842 AND `DifficultyID`=1); -- Ironfur Herdling
UPDATE `creature_template_difficulty` SET `HealthModifier`=1 WHERE (`Entry`=72807 AND `DifficultyID`=1); -- Crag Stalker
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=72777 AND `DifficultyID`=1); -- Gulp Frog
UPDATE `creature_template_difficulty` SET `HealthModifier`=5 WHERE (`Entry`=72765 AND `DifficultyID`=1); -- Elder Great Turtle
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=72764 AND `DifficultyID`=1); -- Great Turtle
UPDATE `creature_template_difficulty` SET `HealthModifier`=300 WHERE (`Entry`=71955 AND `DifficultyID`=1); -- Yu'lon
UPDATE `creature_template_difficulty` SET `HealthModifier`=325 WHERE (`Entry`=71954 AND `DifficultyID`=1); -- Niuzao
UPDATE `creature_template_difficulty` SET `HealthModifier`=300 WHERE (`Entry`=71953 AND `DifficultyID`=1); -- Xuen
UPDATE `creature_template_difficulty` SET `HealthModifier`=300 WHERE (`Entry`=71952 AND `DifficultyID`=1); -- Chi-Ji
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71590 AND `DifficultyID`=0); -- Ominous Glow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71589 AND `DifficultyID`=0) OR (`Entry`=70643 AND `DifficultyID`=1); -- Big Blossom Digger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71496 AND `DifficultyID`=0); -- 5.3 Heroic Scenario Final Boss Proxy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71492 AND `DifficultyID`=0); -- Maragor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71491 AND `DifficultyID`=0); -- Guardian of Sacrifice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71490,71489)); -- Fire Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71485 AND `DifficultyID`=0); -- Ghost Pirate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71452 AND `DifficultyID`=0); -- Admiral Yell Listener
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71450 AND `DifficultyID`=0); -- Female Goblin Heavy Armored
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71449 AND `DifficultyID`=0); -- Male Goblin Heavy Armored
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71446 AND `DifficultyID`=0); -- Shattered Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71445 AND `DifficultyID`=0); -- Horde Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71442,71030)); -- Overseer Elaglo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71440 AND `DifficultyID`=1); -- Shimmerweed Basket
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71437 AND `DifficultyID`=0); -- Big Blossom Keg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71436,67426)); -- Admiral Hagman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71401 AND `DifficultyID`=0); -- Proto-Drake Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71369 AND `DifficultyID`=0); -- Builder Dumont
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71367 AND `DifficultyID`=0); -- Horde Squallshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71366,71365,71364,71331,71167,67343)); -- Transport Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71360 AND `DifficultyID`=0); -- Kor'kron Elite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71359 AND `DifficultyID`=0); -- The Big One 4000
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71358 AND `DifficultyID`=0); -- Crafty the Ambitious
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71342 AND `DifficultyID`=1); -- Jerry the Snail
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71338 AND `DifficultyID`=0); -- Goblin Male Illusion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71337 AND `DifficultyID`=0); -- Goblin Female Illusion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71334 AND `DifficultyID`=0); -- Poison Bolt Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71332 AND `DifficultyID`=0); -- Transport Cannon (NYI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71330 AND `DifficultyID`=0); -- Lieutenant Fizzboil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71329 AND `DifficultyID`=0); -- Lieutenant Boltblaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71328 AND `DifficultyID`=0); -- Lieutenant Fuseblast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71327,69211)); -- Admiral Hodgson
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71326 AND `DifficultyID`=0); -- Lieutenant Parker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71323 AND `DifficultyID`=0); -- Glacial Freeze Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71312 AND `DifficultyID`=0); -- Alliance Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71311,70755)); -- Explosive Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71303 AND `DifficultyID`=0); -- Whale Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71302 AND `DifficultyID`=0); -- Malevolent Force
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71296 AND `DifficultyID`=0); -- Emergency Teleporter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71294,71287)); -- Turtle Jetski
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71289 AND `DifficultyID`=0); -- Sea Turtle Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71286 AND `DifficultyID`=0); -- Turtle Jetski Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71280 AND `DifficultyID`=0) OR (`Entry`=60984 AND `DifficultyID`=1); -- Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71268,71267,71247)); -- Cursed Pirate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71265 AND `DifficultyID`=0); -- Mega Goblin Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71262 AND `DifficultyID`=0); -- Ruined Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71246 AND `DifficultyID`=0); -- Norushen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71245 AND `DifficultyID`=0); -- Kor'kron Dark Shaman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71244 AND `DifficultyID`=0); -- Kor'kron Shadowblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71221 AND `DifficultyID`=0); -- Mantid Bomb Throw Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71209,71032)); -- Pandaria Artifacts
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71208,71031)); -- Proto-Drake Eggs
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71203,70901)); -- Supply Crates
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71197 AND `DifficultyID`=0); -- Broken Proto-Drake Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71195 AND `DifficultyID`=0); -- Battery
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71177 AND `DifficultyID`=0); -- Malkorok
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71176 AND `DifficultyID`=0); -- Cannon Balls
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71175 AND `DifficultyID`=0); -- Pool Pony
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71174 AND `DifficultyID`=0); -- Mantid Bomb
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=71143 AND `DifficultyID`=1); -- Windfeather Chick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71123 AND `DifficultyID`=0); -- Echo of Y'Shaarj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71112 AND `DifficultyID`=0); -- Quivering Blood
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (71111,70824)); -- Fiery Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71106 AND `DifficultyID`=0); -- Barrel of Explosives
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71097 AND `DifficultyID`=0); -- Ragefire Peon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71054 AND `DifficultyID`=0); -- Barrel of Oranges
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=71024 AND `DifficultyID`=0); -- Bombs Away Target Dummy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70988 AND `DifficultyID`=0); -- Ice Spike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70987 AND `DifficultyID`=0); -- Solid Ice
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70982 AND `DifficultyID`=0); -- Frost Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70979 AND `DifficultyID`=0); -- Water Elemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70963 AND `DifficultyID`=0); -- Lieutenant Fizzel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70959 AND `DifficultyID`=0); -- Urtharges the Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70956 AND `DifficultyID`=0); -- Grizzle Gearslip
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70894 AND `DifficultyID`=0); -- Gunpowder Drop Visual Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70893 AND `DifficultyID`=0); -- Lieutenant Blasthammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70889 AND `DifficultyID`=0); -- Explosives Stash Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70877 AND `DifficultyID`=0); -- Volatile Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70822 AND `DifficultyID`=0); -- Earthborn Hatred
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70801 AND `DifficultyID`=1); -- Mountaineer Grimbolt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (70800,70133)); -- Dark Iron Mountaineer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70799 AND `DifficultyID`=1); -- King Varian Wrynn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70798 AND `DifficultyID`=0); -- Kor'kron Emberguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70797 AND `DifficultyID`=0); -- Crate of Artifacts
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70795 AND `DifficultyID`=0); -- Emberdeep Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70792 AND `DifficultyID`=0); -- Scroll Artifact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70791 AND `DifficultyID`=0); -- Book Artifact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70789 AND `DifficultyID`=1); -- Zandalari Rage Banner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70788 AND `DifficultyID`=0); -- Vase Artifact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70787 AND `DifficultyID`=0); -- Skullcrusher Gundu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70785 AND `DifficultyID`=0); -- Failed Experiment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70775 AND `DifficultyID`=0); -- Horde Deckhand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70762 AND `DifficultyID`=0); -- Lieutenant Sparklighter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70754 AND `DifficultyID`=0); -- Barrel Fuse Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70746 AND `DifficultyID`=1); -- Frostmane Flesh-Eater
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70745 AND `DifficultyID`=1); -- Scout Forgefellow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70744 AND `DifficultyID`=1); -- Scout Boldbrew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70741 AND `DifficultyID`=0); -- Hamfisted Bruiser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70709 AND `DifficultyID`=1); -- Pyromancer Flamehearth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70708 AND `DifficultyID`=1); -- Cabalist Doombrow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70706 AND `DifficultyID`=1); -- Trillium-Bladed Rock Cutter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70705 AND `DifficultyID`=0); -- Goblin Mechanic
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70704 AND `DifficultyID`=0); -- Endless Waves Spawn Location
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70703 AND `DifficultyID`=0); -- Core Spider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70702 AND `DifficultyID`=0); -- Flame Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70701 AND `DifficultyID`=0); -- Orc Support
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70700 AND `DifficultyID`=0); -- Orc Caster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70698 AND `DifficultyID`=0); -- Orc Fighter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70695 AND `DifficultyID`=0); -- Endless Waves Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70691 AND `DifficultyID`=0); -- Mouth of Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70690 AND `DifficultyID`=0); -- Blood of Y'Shaarj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70684 AND `DifficultyID`=1); -- Frostmane Mauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70683 AND `DifficultyID`=0); -- Dark Shaman Xorenth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70682 AND `DifficultyID`=1); -- Thunderhoof Supply Kodo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (70672,67403)); -- Bomb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70665 AND `DifficultyID`=0); -- Kor'kron Dire Soldier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70663 AND `DifficultyID`=0); -- Embercore
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70662 AND `DifficultyID`=0); -- Detonator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70613 AND `DifficultyID`=0); -- Female Goblin Medium Armored
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70612 AND `DifficultyID`=0); -- Male Goblin Medium Armored
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70611 AND `DifficultyID`=0); -- Male Goblin Caster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70610 AND `DifficultyID`=0); -- Female Goblin Caster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70609 AND `DifficultyID`=0); -- Ticker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70608 AND `DifficultyID`=0); -- Volt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70607 AND `DifficultyID`=0); -- Patch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70606 AND `DifficultyID`=0); -- Newt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70605 AND `DifficultyID`=0); -- Grit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70602 AND `DifficultyID`=1); -- Scout Stonebeard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70597 AND `DifficultyID`=1); -- Roasting Spit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70595 AND `DifficultyID`=1); -- Frostmane Prowler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70544 AND `DifficultyID`=1); -- Hekima the Wise
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70543 AND `DifficultyID`=0); -- Zandalari Hatemonger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70475 AND `DifficultyID`=0); -- Sanofal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70474 AND `DifficultyID`=1); -- Farastu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70473 AND `DifficultyID`=1); -- Frostmane Headhunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70471 AND `DifficultyID`=1); -- Frostmane Berserker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70469 AND `DifficultyID`=0); -- Ice-Caller Kufungi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70468 AND `DifficultyID`=1); -- Bonechiller Barafu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70465 AND `DifficultyID`=1); -- Frostmane Bonechiller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70464 AND `DifficultyID`=1); -- Frostmane Witch Doctor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70463 AND `DifficultyID`=1); -- Frostmane Snowstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70355 AND `DifficultyID`=0); -- Reliquary Pick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70279 AND `DifficultyID`=1); -- Moira Thaurissan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=70275 AND `DifficultyID`=1); -- Dark Iron Forgeguard
UPDATE `creature_template_difficulty` SET `HealthModifier`=15 WHERE (`Entry`=70003 AND `DifficultyID`=1); -- Molthor
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=70002 AND `DifficultyID`=1); -- Lu-Ban
UPDATE `creature_template_difficulty` SET `HealthModifier`=15 WHERE (`Entry`=70001 AND `DifficultyID`=1); -- Backbreaker Uru
UPDATE `creature_template_difficulty` SET `HealthModifier`=15 WHERE (`Entry`=69999 AND `DifficultyID`=1); -- God-Hulk Ramuk
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=69997 AND `DifficultyID`=1); -- Progenitus
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=69664 AND `DifficultyID`=1); -- Mumta
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69601 AND `DifficultyID`=0); -- Heavy Explosives
UPDATE `creature_template_difficulty` SET `HealthModifier`=3 WHERE (`Entry`=69532 AND `DifficultyID`=1); -- Beastcaller Pakutesh
UPDATE `creature_template_difficulty` SET `HealthModifier`=3 WHERE (`Entry`=69531 AND `DifficultyID`=1); -- Anki
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69231 AND `DifficultyID`=0); -- Alliance Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (69203,69194)); -- Alliance Cannoneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69202 AND `DifficultyID`=0); -- Alliance Squallshaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69197 AND `DifficultyID`=0); -- Alliance Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=69196 AND `DifficultyID`=0); -- Alliance Swashbuckler
UPDATE `creature_template_difficulty` SET `HealthModifier`=350 WHERE (`Entry`=69099 AND `DifficultyID`=1); -- Nalak
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=68701 AND `DifficultyID`=0); -- Burning Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=5 WHERE (`Entry`=68553 AND `DifficultyID`=1); -- SLG Generic MoP (Large AOI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67923 AND `DifficultyID`=0); -- Mage McMage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67632,67400,63896)); -- Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67613,67358)); -- Rowboat
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=67586 AND `DifficultyID`=1); -- Elynara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67411 AND `DifficultyID`=0); -- Emote Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67405 AND `DifficultyID`=0); -- Horde Demolitionist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67394 AND `DifficultyID`=0); -- Plant Explosives
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67393 AND `DifficultyID`=0); -- Sail Fire Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67392 AND `DifficultyID`=0); -- Fire Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67391 AND `DifficultyID`=0); -- Lieutenant Drak'on
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67368 AND `DifficultyID`=0); -- Parrot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67366 AND `DifficultyID`=0); -- Horde Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67364,67360)); -- Horde Cannoneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67361 AND `DifficultyID`=0); -- Horde Swashbuckler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67341 AND `DifficultyID`=0); -- Cannon Exploder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67328 AND `DifficultyID`=0); -- Rope Anchor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67326 AND `DifficultyID`=0); -- Blacksmith Anvil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67311 AND `DifficultyID`=0); -- Healing Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=67231 AND `DifficultyID`=1); -- Trial of the King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (67221,60575)); -- Terracotta Boss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67083,65225)); -- Shado-Pan Initiate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67082,61814)); -- Jin Ironfist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67081 AND `DifficultyID`=0); -- Forgotten King
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67029,62477)); -- Jibberwing Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (67028,62478)); -- Trained Jibberwing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=67027 AND `DifficultyID`=0); -- Jungle Brewstealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7 WHERE (`Entry`=67023 AND `DifficultyID`=0); -- Challengers' Armory
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66999 AND `DifficultyID`=0); -- Swallowed Spearscamp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66991 AND `DifficultyID`=0); -- Twister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66962 AND `DifficultyID`=0); -- Wind Slash
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=66948 AND `DifficultyID`=1); -- Twisted Corpse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66772 AND `DifficultyID`=0); -- Beast of Jade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66756 AND `DifficultyID`=0); -- Cursed Brew Bubble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66703 AND `DifficultyID`=0); -- Fireworks Specialist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66702 AND `DifficultyID`=0); -- Marista Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66701 AND `DifficultyID`=0); -- Brewmaster Boat
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.300000011920928955 WHERE (`DifficultyID`=1 AND `Entry` IN (66484,66284)); -- Thunder Hold Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66458 AND `DifficultyID`=0); -- Professor Whom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=66413 AND `DifficultyID`=1); -- Yeasty Brew Alemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66402 AND `DifficultyID`=0); -- Swallowed Brewstealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66392 AND `DifficultyID`=0); -- Slimy Fish-Getter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66378 AND `DifficultyID`=0); -- Wounded Shado-Pan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (66252,62484)); -- Unga Jungle Brew Keg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=66195 AND `DifficultyID`=0); -- Unga Rocket Surgeon
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`DifficultyID`=1 AND `Entry` IN (65915,65906)); -- Strongarm Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65803 AND `DifficultyID`=1); -- Cobalt Mine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65652 AND `DifficultyID`=0); -- Unga Keg-Haver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65607 AND `DifficultyID`=0); -- Sha Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (65603,65590)); -- Lightning Trap
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65581 AND `DifficultyID`=0); -- Essence of Hate
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (65556,61709)); -- Spawn of Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65554 AND `DifficultyID`=0); -- Evil Force
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (65522,59487)); -- Bubble Shield
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65449 AND `DifficultyID`=0); -- Goblin Crew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65447 AND `DifficultyID`=0); -- Goblin Marine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65446 AND `DifficultyID`=0); -- Goblin Captain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65443 AND `DifficultyID`=0); -- Bomb Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=65402 AND `DifficultyID`=1); -- Gurthan Swiftblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=65393 AND `DifficultyID`=1); -- East Temple - Corrupted Waters Stalker - MW
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=65392 AND `DifficultyID`=1); -- Nibbler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (65376,65375,59075)); -- Ancestral Brewmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (65362,57109)); -- Minion of Doubt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65338 AND `DifficultyID`=0); -- Mirror Image
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=65317 AND `DifficultyID`=1); -- Xiang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65316 AND `DifficultyID`=0); -- Shield Captain Zeren
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65304 AND `DifficultyID`=0); -- Hateful Monstrosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65295 AND `DifficultyID`=0); -- Mistweaver Nian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65294 AND `DifficultyID`=0); -- Matriarch Scorpid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65293 AND `DifficultyID`=1); -- Infinite Energy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65272 AND `DifficultyID`=0); -- Ook Ya
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65271 AND `DifficultyID`=0); -- Mayor Lin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65270 AND `DifficultyID`=0); -- Mai the Jade Shaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (65244,61791)); -- Novice Snow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65228 AND `DifficultyID`=1); -- Mogu Runes (Pitch Forward 180) DNT
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65227 AND `DifficultyID`=1); -- Mogu Runes (Pitch Forward 120) DNT
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65213 AND `DifficultyID`=0); -- Gluttonous Cove Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=65119 AND `DifficultyID`=0); -- Wave of Pain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (64947,64061)); -- Mogu'shan Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64912,64162)); -- Binan Fisherman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64911,64089)); -- Xuen Shield Bearer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64910,64189)); -- Tian Mistweaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64909,63897)); -- Damaged Cannon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64908,63946)); -- Tian Disciple
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64907,63940,63931)); -- Fireworks Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64906,63929,63889)); -- Krasarang Wild Brew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64904 AND `DifficultyID`=0); -- Vale Marksmen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64903 AND `DifficultyID`=0); -- Jovial Villagers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64901 AND `DifficultyID`=0); -- Brewmaster Boof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64894 AND `DifficultyID`=0); -- Final Challenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64893 AND `DifficultyID`=0); -- Binan Village Roof Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64825 AND `DifficultyID`=1); -- Leng Windstaff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64627 AND `DifficultyID`=0); -- Bananamancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64600 AND `DifficultyID`=1); -- Mogu Runes (Vertical Visual)
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=64599 AND `DifficultyID`=1); -- Ambersmith Zikk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64556,62465)); -- Captain Ook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (64548,61551,61450)); -- Kargesh Grunt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (64547,61549,61447)); -- Gurthan Scrapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64529 AND `DifficultyID`=1); -- Mogu Runes (Horizontal Visual)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64526 AND `DifficultyID`=1); -- Ancient Mogu Artifact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=64432 AND `DifficultyID`=1); -- Sinan the Dreamer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=64399 AND `DifficultyID`=1); -- Master Windstrong
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (64361,59704)); -- Chen Stormstout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64308 AND `DifficultyID`=0); -- Storm Cloud
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64286,64281)); -- Satay Byu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64280 AND `DifficultyID`=0); -- Maki Waterblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64278 AND `DifficultyID`=0); -- J. Shine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64271 AND `DifficultyID`=0); -- Oil Slick
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64268,64264)); -- Qobi's Axe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (64266,64265)); -- Fire Line
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=64250 AND `DifficultyID`=1); -- Beacon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (64243,61431,61399)); -- Glintrok Scout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64217 AND `DifficultyID`=0); -- Jovial Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64211 AND `DifficultyID`=0); -- Cianz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64209 AND `DifficultyID`=0); -- Yaungol Boat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64185 AND `DifficultyID`=0); -- Bataari War Yeti
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64183 AND `DifficultyID`=1); -- Enormous Stone Quilen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64165 AND `DifficultyID`=0); -- Bataari Outrunner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64068 AND `DifficultyID`=1); -- Mogu'shan Engine Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64063 AND `DifficultyID`=1); -- Mogu'shan Arcanist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64017 AND `DifficultyID`=0); -- Derpa Derpa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=64016 AND `DifficultyID`=0); -- Pulse Wave Emitter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (63985,62784,62783)); -- Binan Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63952 AND `DifficultyID`=0); -- Vale Marksman
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63951 AND `DifficultyID`=0); -- Mortar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63941 AND `DifficultyID`=0); -- Sack of Grain
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63922 AND `DifficultyID`=0); -- Briaw Shan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63918 AND `DifficultyID`=0); -- Brew Strike
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63874 AND `DifficultyID`=0); -- Spawn Burrowed
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63873 AND `DifficultyID`=0); -- Ball Lightning
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63872 AND `DifficultyID`=0); -- Batu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63843 AND `DifficultyID`=0); -- Pure Water Globe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63828 AND `DifficultyID`=0); -- Vial of Pure Water
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63826 AND `DifficultyID`=0); -- Tart's Boat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63823 AND `DifficultyID`=0); -- Waterspout
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63819 AND `DifficultyID`=0); -- Fireworks Launcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63818 AND `DifficultyID`=0); -- Commander Hsieh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63817 AND `DifficultyID`=0); -- Binan Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63815 AND `DifficultyID`=0); -- Puli the Even Handed
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63814 AND `DifficultyID`=0); -- Poppers
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63813 AND `DifficultyID`=0); -- Hozen Snot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63812 AND `DifficultyID`=0); -- Apothecary Cheng
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63811 AND `DifficultyID`=0); -- Assistant Buzaki
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=63808 AND `DifficultyID`=1); -- Faintly Glowing Gem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63743 AND `DifficultyID`=0); -- Dirty Virmen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63741 AND `DifficultyID`=0); -- Burrow Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=63739 AND `DifficultyID`=1); -- Quilen Statue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63544 AND `DifficultyID`=0); -- Trailblaze
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.300000011920928955 WHERE (`Entry`=63540 AND `DifficultyID`=1); -- Young Windward Tiger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63539 AND `DifficultyID`=0); -- Flamecoaxing Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63534 AND `DifficultyID`=0); -- Flame Wall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63529 AND `DifficultyID`=0); -- Karsar the Bloodletter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63528 AND `DifficultyID`=0); -- Warbringer Qobi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63527 AND `DifficultyID`=0); -- Bataari Yaungol
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63526 AND `DifficultyID`=0); -- Bataari Flamecaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63521 AND `DifficultyID`=0); -- Disturbed Saurok
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63520 AND `DifficultyID`=0); -- Li Te
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63519 AND `DifficultyID`=0); -- Water Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63518 AND `DifficultyID`=0); -- Den Mother Moof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63511 AND `DifficultyID`=0); -- Face Snake
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=63367 AND `DifficultyID`=1); -- Brewmaster Boof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63334 AND `DifficultyID`=0); -- Xuen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63318 AND `DifficultyID`=0); -- Chagan Firehoof
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63316 AND `DifficultyID`=0); -- Cloudbender Kobo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63315 AND `DifficultyID`=0); -- Gurgthock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63314 AND `DifficultyID`=0); -- Wodin the Troll-Servant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63313 AND `DifficultyID`=0); -- Little Liuyang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63312 AND `DifficultyID`=0); -- Jol'Grum
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63311 AND `DifficultyID`=0); -- Scar-Shell
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63256 AND `DifficultyID`=0); -- Unga Hozekateer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=63093 AND `DifficultyID`=1); -- Jade Quilen Referee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (63092,63091)); -- Jade Quilen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=63028 AND `DifficultyID`=0); -- Stolen Unga Brew Keg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62990 AND `DifficultyID`=0); -- Kiri Jade-Eyes
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62989 AND `DifficultyID`=0); -- Stonecutter Lon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62988 AND `DifficultyID`=0); -- Barrel-Chest Huo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62945 AND `DifficultyID`=0); -- Bloodthirsty Prowler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62807 AND `DifficultyID`=0); -- Hungry Virmen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62793 AND `DifficultyID`=0); -- Assistant Tart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62787 AND `DifficultyID`=0); -- Assistant Kieu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62785 AND `DifficultyID`=0); -- Mayor Bramblestaff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62713 AND `DifficultyID`=0); -- Unstable Keg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62706 AND `DifficultyID`=0); -- Cowardly Zue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62705 AND `DifficultyID`=0); -- Brew Defender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62683,62500,62496,62487)); -- Zip Line
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62682 AND `DifficultyID`=0); -- Burgled Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62637 AND `DifficultyID`=0); -- Cursed Brew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62623 AND `DifficultyID`=0); -- Jade Blaze
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62619 AND `DifficultyID`=0); -- Jade Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62614 AND `DifficultyID`=0); -- Ook Barrel Dest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62611 AND `DifficultyID`=0); -- Big Red Bird
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62610 AND `DifficultyID`=0); -- Spawn of Doubt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62604 AND `DifficultyID`=0); -- Riding Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62590 AND `DifficultyID`=0); -- Unga Scallywag
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62569 AND `DifficultyID`=0); -- Rik Rik
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62561 AND `DifficultyID`=0); -- Cannon Impact
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62560 AND `DifficultyID`=0); -- Flare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62557,62469)); -- Unga Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62535 AND `DifficultyID`=0); -- Cove Shark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62508 AND `DifficultyID`=0); -- Unga Brewstealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62507 AND `DifficultyID`=0); -- Generic Invisible Man
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62506 AND `DifficultyID`=0); -- Hozen Pirate Ship
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62505 AND `DifficultyID`=0); -- Trapping Keg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62504 AND `DifficultyID`=0); -- Ookie's Orange
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62503,62499)); -- Unga Beachbummer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62502,62482)); -- Hozen Swing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62501,62493)); -- Monkey Island Totem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62498 AND `DifficultyID`=0); -- Chihozen Binono
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62497 AND `DifficultyID`=0); -- Unga Keg-Blocker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62495 AND `DifficultyID`=0); -- Unga Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62494 AND `DifficultyID`=0); -- Unga Nibstabber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62492 AND `DifficultyID`=0); -- Unga Totemchipper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62491,62467)); -- Brewmaster Bo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62490 AND `DifficultyID`=0); -- Ambushing Spearscamp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62488 AND `DifficultyID`=0); -- Grooka Grooka
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62486 AND `DifficultyID`=0); -- Oku-Oku
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62485 AND `DifficultyID`=0); -- Gagoon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62483 AND `DifficultyID`=0); -- Hozen Totem Fire Effect
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62481,62474)); -- Unga Spearscamp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62480,62479,62476)); -- Trained Jungle Lory
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62475 AND `DifficultyID`=0); -- Unga Bird-Haver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62473 AND `DifficultyID`=0); -- Mad Eye
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62472 AND `DifficultyID`=0); -- Ookie's Cleaver Bunny Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62471 AND `DifficultyID`=0); -- Ookie's Cleaver Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62470 AND `DifficultyID`=0); -- Powder Keg Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62468 AND `DifficultyID`=0); -- Ookie
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62466 AND `DifficultyID`=0); -- Ba-Bam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62365 AND `DifficultyID`=0); -- Foreman Mann
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (62360,62358,56658)); -- Corrupt Droplet
UPDATE `creature_template_difficulty` SET `HealthModifier`=12 WHERE (`Entry`=62351 AND `DifficultyID`=1); -- Salyin Warmonger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62254 AND `DifficultyID`=0); -- Quilen Watcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=62249 AND `DifficultyID`=1); -- Serpent Trainer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=62231 AND `DifficultyID`=1); -- Yu'lon Priest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62230 AND `DifficultyID`=0); -- Crypt Scarab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=62229 AND `DifficultyID`=1); -- Yu'lon Disciple
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=62171 AND `DifficultyID`=1); -- Serpent Warrior
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=0 AND `Entry` IN (62134,61783,61766,61418)); -- Crypt Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62104 AND `DifficultyID`=0); -- Orange Highlight Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62055 AND `DifficultyID`=0); -- Cloud of Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62015 AND `DifficultyID`=0); -- Dark Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62009 AND `DifficultyID`=0); -- Shadows of Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=62004 AND `DifficultyID`=1); -- Ghost Essence
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61989,61334)); -- Cursed Mogu Sculpture
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61947 AND `DifficultyID`=1); -- Kargesh Ribcrusher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61946 AND `DifficultyID`=1); -- Harthak Stormcaller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61945 AND `DifficultyID`=1); -- Gurthan Iron Maw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61885 AND `DifficultyID`=0); -- Pool of Life
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61884,61398)); -- Xin the Weaponmaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61804 AND `DifficultyID`=0); -- Murdered Shado-Pan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61707 AND `DifficultyID`=0); -- Abomination of Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61679 AND `DifficultyID`=1); -- Crossbow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61626 AND `DifficultyID`=1); -- Whilring Dervish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61610 AND `DifficultyID`=0); -- Seething Sha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61565 AND `DifficultyID`=0); -- Quilen Statue
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61550,61449)); -- Harthak Adept
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61499 AND `DifficultyID`=1); -- Ring of Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61478 AND `DifficultyID`=1); -- Referee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61462 AND `DifficultyID`=0); -- Meila
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61461 AND `DifficultyID`=0); -- Portly Shung
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61457 AND `DifficultyID`=0); -- Terror Shards
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61455 AND `DifficultyID`=1); -- Gurthan Quilen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61453 AND `DifficultyID`=1); -- Mu'Shiba
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61451 AND `DifficultyID`=1); -- Animated Axe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61445 AND `DifficultyID`=1); -- Haiyan the Unstoppable
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61444 AND `DifficultyID`=1); -- Ming the Cunning
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61442 AND `DifficultyID`=1); -- Kuai the Brute
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61433 AND `DifficultyID`=1); -- Animated Staff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61432,61246)); -- Glintrok Pillager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61429,60708)); -- Meng the Demented
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61427,60710)); -- Subetai the Swift
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61423,60709)); -- Qiang the Merciless
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61421,60701)); -- Zian of the Endless Shadow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61415 AND `DifficultyID`=1); -- Giant Cave Bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61414 AND `DifficultyID`=0); -- Doom Bloom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61392 AND `DifficultyID`=1); -- Harthak Flameseeker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61389 AND `DifficultyID`=1); -- Kargesh Highguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61387 AND `DifficultyID`=1); -- Quilen Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61352 AND `DifficultyID`=1); -- Story Time
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61350 AND `DifficultyID`=0); -- Graceful Swan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61347 AND `DifficultyID`=1); -- Kingsguard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61346 AND `DifficultyID`=0); -- Scribe Rinji
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61345 AND `DifficultyID`=1); -- Mogu Archer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61343 AND `DifficultyID`=0); -- La the Gentle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61342 AND `DifficultyID`=0); -- Woodcarver Liupo
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61341 AND `DifficultyID`=1); -- Mounted Mogu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61340,61216)); -- Glintrok Hexxer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61339,61239)); -- Glintrok Oracle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61338,61240)); -- Glintrok Skulker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (61337,61242)); -- Glintrok Ironhide
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61330 AND `DifficultyID`=1); -- Energy Vortex Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61250 AND `DifficultyID`=1); -- Sorcerer Mogu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61247 AND `DifficultyID`=1); -- Glintrok Greenhorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=61243 AND `DifficultyID`=1); -- Gekkan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61223 AND `DifficultyID`=0); -- [DND] Monster Target (Wood)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61204 AND `DifficultyID`=0); -- Unconscious Monk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61203 AND `DifficultyID`=0); -- Brewmaster Tzu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61202 AND `DifficultyID`=0); -- Greenstone Monk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61183 AND `DifficultyID`=0); -- Belligerent Blossom
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61182 AND `DifficultyID`=0); -- Unconscious Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61180 AND `DifficultyID`=0); -- Greenstone Villager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61174 AND `DifficultyID`=0); -- Cursed Jade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61159 AND `DifficultyID`=0); -- Greenstone Terror
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61157 AND `DifficultyID`=0); -- Sassy Seedling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61156 AND `DifficultyID`=0); -- Vengeful Hui
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61155 AND `DifficultyID`=0); -- Wily Woodling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61140,60143)); -- Gara'jal the Spiritbinder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61139 AND `DifficultyID`=1); -- Shan-xi Watershaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (61134,60241)); -- Lightning Charge
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61131 AND `DifficultyID`=1); -- Mogu'shan Secret-Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=61124 AND `DifficultyID`=1); -- Phase Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60960 AND `DifficultyID`=1); -- Core Target Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60958 AND `DifficultyID`=1); -- Pinning Arrow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60942 AND `DifficultyID`=1); -- Volley
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (60940,60184)); -- Shadowy Minion
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60913 AND `DifficultyID`=1); -- Energy Charge
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.20000004768371582 WHERE (`DifficultyID`=1 AND `Entry` IN (60878,60877)); -- Alliance Priest
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=60858 AND `DifficultyID`=1); -- Deepscale Fleshripper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60847 AND `DifficultyID`=1); -- Flanking Mogu
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.20000004768371582 WHERE (`DifficultyID`=1 AND `Entry` IN (60834,60770)); -- Horde Druid
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=60780 AND `DifficultyID`=1); -- Deepscale Ravager
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60776 AND `DifficultyID`=1); -- Empyreal Focus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (60768,60397)); -- Emperor's Strength
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60731 AND `DifficultyID`=1); -- Undying Shadows
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60648 AND `DifficultyID`=1); -- Ancient Mogu Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (60644,60395,60394,60393,60392,60391,60390,60389,60388,60387)); -- Troll Explosives
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=60578 AND `DifficultyID`=1); -- Priestess Summerpetal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60576 AND `DifficultyID`=1); -- Stone Quilen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (60559,60558)); -- Zandalari Spirit
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`DifficultyID`=1 AND `Entry` IN (60513,60512,60240)); -- Spirit Totem
UPDATE `creature_template_difficulty` SET `HealthModifier`=325 WHERE (`Entry`=60491 AND `DifficultyID`=1); -- Sha of Anger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60438 AND `DifficultyID`=1); -- Wildfire Spark
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60410 AND `DifficultyID`=1); -- Elegon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60402 AND `DifficultyID`=1); -- Zandalari Fire-Dancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60400 AND `DifficultyID`=1); -- Jan-xi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60399 AND `DifficultyID`=1); -- Qin-xi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60398 AND `DifficultyID`=1); -- Emperor's Courage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60396 AND `DifficultyID`=1); -- Emperor's Rage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60386 AND `DifficultyID`=1); -- Zandalari Terror Rider
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60385 AND `DifficultyID`=1); -- Zandalari War Wyvern
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60384 AND `DifficultyID`=1); -- Zandalari Pterror Wing
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60381 AND `DifficultyID`=1); -- Zandalari Infiltrator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60375 AND `DifficultyID`=1); -- Zandalari Skullcharger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=60276 AND `DifficultyID`=1); -- Hozen Clinger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (60208,59461,59460,59459,59458,56631)); -- Hopling
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=157853 WHERE (`Entry`=60107 AND `DifficultyID`=1); -- Dashing Strike Back Stalker
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=157856 WHERE (`Entry`=60106 AND `DifficultyID`=1); -- Commander Durand
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60089 AND `DifficultyID`=1); -- Stone Guard Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60051 AND `DifficultyID`=1); -- Cobalt Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60047 AND `DifficultyID`=1); -- Amethyst Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60043 AND `DifficultyID`=1); -- Jade Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=60009 AND `DifficultyID`=1); -- Feng the Accursed
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=59915 AND `DifficultyID`=1); -- Jasper Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59891 AND `DifficultyID`=1); -- Fallen Jin'yu
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59873,56511)); -- Corrupt Living Water
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59824 AND `DifficultyID`=1); -- Golden Hopling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59822 AND `DifficultyID`=1); -- Auntie Stormstout
UPDATE `creature_template_difficulty` SET `HealthModifier`=5 WHERE (`Entry`=59756 AND `DifficultyID`=1); -- Chibee
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59726 AND `DifficultyID`=1); -- Peril
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59684,57097,56927)); -- Hozen Party Animal
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=158021 WHERE (`Entry`=59683 AND `DifficultyID`=1); -- Exploding Shot Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59605 AND `DifficultyID`=1); -- Sodden Hozen Brawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59598,58319)); -- Lesser Sha
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=59584 AND `DifficultyID`=1); -- Fisherman Haito
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59555,58865,58856)); -- Haunting Sha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59553 AND `DifficultyID`=1); -- The Songbird Queen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59552 AND `DifficultyID`=1); -- The Crybaby Hozen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59551,59426)); -- Bopper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59547 AND `DifficultyID`=1); -- Jiang
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59546 AND `DifficultyID`=1); -- The Talking Fish
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59545 AND `DifficultyID`=1); -- The Golden Beetle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59544 AND `DifficultyID`=1); -- The Nodding Tiger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59539 AND `DifficultyID`=1); -- Big Ol' Hammer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59522,56748)); -- Sudsy Brew Alemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59521 AND `DifficultyID`=1); -- Bubbling Brew Alemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59518 AND `DifficultyID`=1); -- Bloated Brew Alemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59512 AND `DifficultyID`=1); -- Wall of Suds
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59510 AND `DifficultyID`=1); -- Sudsy Stalker Vehicle
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=158024 WHERE (`Entry`=59507 AND `DifficultyID`=1); -- Scorched Earth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59482 AND `DifficultyID`=1); -- Bloated Stalker
UPDATE `creature_template_difficulty` SET `TypeFlags2`=134217750 WHERE (`Entry`=59481 AND `DifficultyID`=1); -- World Trigger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59479 AND `DifficultyID`=1); -- Yan-Zhu the Uncasked
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59464,56718)); -- Hopper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59429 AND `DifficultyID`=1); -- Explosive Brew Barrel
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=158046 WHERE (`Entry`=59155 AND `DifficultyID`=1); -- Book Case
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59149 AND `DifficultyID`=1); -- Wise Dragon
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.300000011920928955, `ManaModifier`=1 WHERE (`Entry`=59103 AND `DifficultyID`=1); -- Forest Cub
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59074 AND `DifficultyID`=1); -- Uncle Gao
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`DifficultyID`=1 AND `Entry` IN (59051,56871)); -- Strife
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=59018 AND `DifficultyID`=1); -- Tracking Carrot
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=58826 AND `DifficultyID`=1); -- Zao Sunseeker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=58815 AND `DifficultyID`=1); -- Swirling Sunfire
UPDATE `creature_template_difficulty` SET `TypeFlags`=2147483721 WHERE (`Entry`=58474 AND `DifficultyID`=1); -- Bloodtip
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.5 WHERE (`Entry`=58219 AND `DifficultyID`=1); -- Saltback Yearling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=57478 AND `DifficultyID`=1); -- Invisible Stalker
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=57405 AND `DifficultyID`=1); -- Silkmaster Tsai
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=57080 AND `DifficultyID`=1); -- Corrupted Scroll
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56924 AND `DifficultyID`=1); -- Inflamed Hozen Brawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56915 AND `DifficultyID`=1); -- Sun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56882 AND `DifficultyID`=1); -- Well
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56874 AND `DifficultyID`=1); -- Moon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56873 AND `DifficultyID`=1); -- Heroine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56872 AND `DifficultyID`=1); -- Osong
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56867 AND `DifficultyID`=1); -- Fiery Trickster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56865 AND `DifficultyID`=1); -- Aqua Dancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56863 AND `DifficultyID`=1); -- Sleepy Hozen Brawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56862 AND `DifficultyID`=1); -- Drunken Hozen Brawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56861 AND `DifficultyID`=1); -- Eagle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56849 AND `DifficultyID`=1); -- Hozen Bouncer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56843 AND `DifficultyID`=1); -- Lorewalker Stonestep
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228851 WHERE (`Entry`=56835 AND `DifficultyID`=1); -- Jade Dragon Wave Summoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56821 AND `DifficultyID`=1); -- Barrel Explosion Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228918 WHERE (`Entry`=56816 AND `DifficultyID`=1); -- Dragon Wave Summoner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56792 AND `DifficultyID`=1); -- Figment of Doubt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228923 WHERE (`Entry`=56789 AND `DifficultyID`=1); -- Dragon Wave
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56783 AND `DifficultyID`=1); -- Hozen Hollerer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56762 AND `DifficultyID`=1); -- Yu'lon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228844 WHERE (`Entry`=56732 AND `DifficultyID`=1); -- Liu Flameheart
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56731 AND `DifficultyID`=1); -- Habanero Brew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56717 AND `DifficultyID`=1); -- Hoptallus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56682 AND `DifficultyID`=1); -- Rolling Barrel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56637 AND `DifficultyID`=1); -- Ook-Ook
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56586 AND `DifficultyID`=1); -- Fountain Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56574 AND `DifficultyID`=1); -- Firehose Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56542 AND `DifficultyID`=1); -- Splash Stalker
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.300000011920928955 WHERE (`Entry`=56526 AND `DifficultyID`=1); -- Tawnyhide Fawn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4, `CreatureDifficultyID`=228571 WHERE (`Entry`=56448 AND `DifficultyID`=1); -- Wise Mari
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=4 WHERE (`Entry`=56439 AND `DifficultyID`=1); -- Sha of Doubt
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=56406 AND `DifficultyID`=1); -- Rivett Clutchpop
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=56303 AND `DifficultyID`=1); -- Alliance Infiltrator
UPDATE `creature_template_difficulty` SET `HealthModifier`=3 WHERE (`Entry`=55693 AND `DifficultyID`=1); -- Alliance Scout
UPDATE `creature_template_difficulty` SET `HealthModifier`=1 WHERE (`Entry`=55692 AND `DifficultyID`=1); -- Ambushing Jinyu
UPDATE `creature_template_difficulty` SET `HealthModifier`=15 WHERE (`Entry`=55686 AND `DifficultyID`=1); -- Riko
UPDATE `creature_template_difficulty` SET `HealthModifier`=10 WHERE (`Entry`=55335 AND `DifficultyID`=1); -- Rell Nightwind
UPDATE `creature_template_difficulty` SET `HealthModifier`=2 WHERE (`Entry`=55286 AND `DifficultyID`=1); -- Sully "The Pickle" McLeary
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=53488 AND `DifficultyID`=0); -- Summon Enabler Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=52019 AND `DifficultyID`=1); -- Skyfall Nova
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (51395,51391)); -- Bubble Generator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=51157 AND `DifficultyID`=1); -- Golden Orb
UPDATE `creature_template_difficulty` SET `HealthModifier`=8 WHERE (`Entry`=50358 AND `DifficultyID`=1); -- Haywire Sunreaver Construct
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (50278,40584,39616)); -- Naz'jar Invader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=50276 AND `DifficultyID`=1); -- Naz'jar Spiritmender
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=50272 AND `DifficultyID`=0); -- Legionnaire Nazgrim
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=50270 AND `DifficultyID`=1); -- Captain Taylor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=49943 AND `DifficultyID`=1); -- Itesh
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (48983,40597)); -- Geyser
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=47342 AND `DifficultyID`=1); -- Twister
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=47305 AND `DifficultyID`=1); -- Air Current
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=47238 AND `DifficultyID`=1); -- Whipping Wind
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (47085,47000)); -- Grounding Field
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=46492 AND `DifficultyID`=1); -- Unstable Grounding Field
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=46387 AND `DifficultyID`=1); -- Storm Target
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=46007 AND `DifficultyID`=1); -- Ertan's Vortex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45991 AND `DifficultyID`=1); -- Zephyr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45981 AND `DifficultyID`=1); -- Skyfall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45935 AND `DifficultyID`=1); -- Temple Adept
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45932 AND `DifficultyID`=1); -- Skyfall Star
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45930 AND `DifficultyID`=1); -- Minister of Air
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45928 AND `DifficultyID`=1); -- Executor of the Caliph
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45926 AND `DifficultyID`=1); -- Servant of Asaad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45924 AND `DifficultyID`=1); -- Turbulent Squall
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45922 AND `DifficultyID`=1); -- Empyrean Assassin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45919 AND `DifficultyID`=1); -- Young Storm Dragon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45917 AND `DifficultyID`=1); -- Cloud Prince
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45915 AND `DifficultyID`=1); -- Armored Mistral
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45912 AND `DifficultyID`=1); -- Wild Vortex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (45672,45620)); -- Naz'jar Soldier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45621 AND `DifficultyID`=1); -- Elemental Guard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45572 AND `DifficultyID`=1); -- Howling Gale
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45504 AND `DifficultyID`=1); -- Slipstream Landing Zone
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45455 AND `DifficultyID`=1); -- Slipstream
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=45030 AND `DifficultyID`=1); -- Ozumat Vehicle, Big
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=44864 AND `DifficultyID`=1); -- Ozumat Combat Trigger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=44752 AND `DifficultyID`=1); -- Faceless Sapper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=44656 AND `DifficultyID`=1); -- Ozumat Add Spawner
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=44581 AND `DifficultyID`=1); -- Ozumat Vehicle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (44566,40655)); -- Ozumat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=44404 AND `DifficultyID`=1); -- Naz'jar Frost Witch
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=43878 AND `DifficultyID`=1); -- Grand Vizier Ertan
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=43875 AND `DifficultyID`=1); -- Asaad
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=43873 AND `DifficultyID`=1); -- Altairus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=43202 AND `DifficultyID`=0); -- Elevator Construction Chief
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=42844 AND `DifficultyID`=1); -- Invisible Stalker (Cataclysm Boss, Ignore Combat)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=41206 AND `DifficultyID`=0); -- World Invisible Trigger (flying)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=41201 AND `DifficultyID`=1); -- Noxious Mire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (41139,41096)); -- Naz'jar Oracle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40943 AND `DifficultyID`=1); -- Gilgoblin Aquamage
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40936 AND `DifficultyID`=1); -- Faceless Watcher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40935 AND `DifficultyID`=1); -- Gilgoblin Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40925 AND `DifficultyID`=1); -- Tainted Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40923 AND `DifficultyID`=1); -- Unstable Corruption
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40825 AND `DifficultyID`=1); -- Erunak Stonespeaker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40792 AND `DifficultyID`=1); -- Neptulon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40788 AND `DifficultyID`=1); -- Mindbender Ghur'sha
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40784 AND `DifficultyID`=1); -- Dark Fissure
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40765 AND `DifficultyID`=1); -- Commander Ulthok
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`DifficultyID`=1 AND `Entry` IN (40586,39959)); -- Lady Naz'jar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=40579 AND `DifficultyID`=1); -- Deep Murloc Hunter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=39960 AND `DifficultyID`=1); -- Deep Murloc Drudge
UPDATE `creature_template_difficulty` SET `TypeFlags2`=128 WHERE (`Entry`=36296 AND `DifficultyID`=1); -- Apothecary Hummel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=36171 AND `DifficultyID`=1); -- World Trigger (Infinite AOI)
UPDATE `creature_template_difficulty` SET `HealthModifier`=50 WHERE (`Entry`=28511 AND `DifficultyID`=1); -- Eye of Acherus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=22517 AND `DifficultyID`=0); -- World Trigger (Large AOI)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=22515 AND `DifficultyID`=0); -- World Trigger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=21252 AND `DifficultyID`=1); -- World Trigger (Not Immune PC)
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=3 WHERE (`Entry`=18721 AND `DifficultyID`=0); -- World Trigger (Friendly + Invis Man)
UPDATE `creature_template_difficulty` SET `TypeFlags2`=67108864 WHERE (`Entry`=17364 AND `DifficultyID`=1); -- Totem of Vark
UPDATE `creature_template_difficulty` SET `TypeFlags2`=67108864 WHERE (`Entry`=17363 AND `DifficultyID`=1); -- Totem of Yor
UPDATE `creature_template_difficulty` SET `TypeFlags2`=67108864 WHERE (`Entry`=17362 AND `DifficultyID`=1); -- Totem of Tikti
UPDATE `creature_template_difficulty` SET `TypeFlags2`=67108864 WHERE (`Entry`=17361 AND `DifficultyID`=1); -- Totem of Coo
UPDATE `creature_template_difficulty` SET `TypeFlags`=536870912, `TypeFlags2`=67108864 WHERE (`Entry`=17360 AND `DifficultyID`=1); -- Totem of Akida
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=5052 AND `DifficultyID`=1); -- Edward Remington
UPDATE `creature_template_difficulty` SET `TypeFlags`=134217728 WHERE (`Entry`=5047 AND `DifficultyID`=1); -- Ellaercia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=0 WHERE (`Entry`=309 AND `DifficultyID`=1); -- "Buried Upside-Down" Vehicle

