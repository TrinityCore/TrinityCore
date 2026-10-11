-- 
SET NAMES 'utf8';
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (93844,100239,100240,100241,101122,101127,101430,101875,101897,101899,105085,105694,105813,105910,105911,105912,105967,105968,106172,106209,106245,106246,106347,108434,111906,116308,124252,125180,125181,125192,125193,125287,129422,129914,129915,129917,130726,188725,189558,191654,191661,194785,194787,194792,195836,195837,195838,195839,199541,199566,199800,200177,200726,201152,201153,201545,206150,206167,206168,206441,208186,209296,209297,211015,213791,214263,214677,214769,215091,215137,215172,215173,215174,215187,215198,215277,215913,216247,216303,216466,216467,216468,216639,218367,218626,219881,221708,223205,225768,226666,226667,226668,226937,226938,226939,226941,226942,227859,227860,228553,228570,229307,229328,229340,229341,229342,229386,229791,232087,232088,232094,232161,232163,232164,232307,232310,232312,232314,232315,232316,232317,232320,232321,237257,237881,237882,237884,238039,240758,240759,241073,241084,243693,244393,244922,250662)) OR (`ID`=2 AND `CreatureID` IN (214769,250662));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(93844, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Baine Bloodhoof
(100239, 1, 163831, 0, 0, 163832, 0, 0, 0, 0, 0, 62876), -- Lady Liadrin
(100240, 1, 105940, 0, 0, 126759, 0, 0, 0, 0, 0, 62876), -- Vindicator Boros
(100241, 1, 42322, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Aponi Brightmane
(101122, 1, 72863, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Twilight Shadowcaster
(101127, 1, 41343, 0, 0, 15909, 0, 0, 0, 0, 0, 62876), -- Twilight Bladetwister
(101430, 1, 71559, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Shadowlord Slaghammer
(101875, 1, 72863, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Twilight Ritualist
(101897, 1, 126747, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Borgoth the Master Reaver
(101899, 1, 71559, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Shadowlord Slaghammer
(105085, 1, 0, 0, 0, 118005, 0, 0, 0, 0, 0, 62876), -- Spiritwalker Graysky
(105694, 1, 126520, 0, 0, 73435, 0, 0, 0, 0, 0, 62876), -- Cato
(105813, 1, 85428, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Orik Trueheart
(105910, 1, 85428, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Orik Trueheart
(105911, 1, 85428, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Orik Trueheart
(105912, 1, 126520, 0, 0, 73435, 0, 0, 0, 0, 0, 62876), -- Cato
(105967, 1, 62902, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Restless Tombguard
(105968, 1, 56230, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Spectral Windshaper
(106172, 1, 129727, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Runeshaper Griselda
(106209, 1, 108923, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Lord Maxwell Tyrosus
(106245, 1, 0, 0, 0, 0, 0, 0, 107289, 0, 0, 62876), -- Inna the Cryptstalker
(106246, 1, 0, 0, 0, 0, 0, 0, 107289, 0, 0, 62876), -- Shae
(106347, 1, 111373, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Spectral Champion
(108434, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Mayla Highmountain
(111906, 1, 17383, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Ashtongue Warrior
(116308, 1, 65492, 0, 0, 111717, 0, 0, 0, 0, 0, 62876), -- Karam Magespear
(124252, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 62876), -- Spiritwalker Ebonhorn
(125180, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Mayla Highmountain
(125181, 1, 0, 0, 0, 118005, 0, 0, 0, 0, 0, 62876), -- Spiritwalker Ebonhorn
(125192, 1, 12754, 0, 0, 0, 0, 0, 14642, 0, 0, 62876), -- Bluffwatcher
(125193, 1, 5288, 0, 0, 0, 0, 0, 49462, 0, 0, 62876), -- Honor Guard
(125287, 1, 13339, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Archdruid Hamuul Runetotem
(129422, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Baine Bloodhoof
(129914, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Baine Bloodhoof
(129915, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Mayla Highmountain
(129917, 1, 13339, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Archdruid Hamuul Runetotem
(130726, 1, 141595, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Qy'telek
(188725, 1, 192564, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Embertooth Spearhunter
(189558, 1, 10826, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Warden Dialash
(191654, 1, 107670, 0, 0, 110340, 0, 0, 0, 0, 0, 62876), -- Rimebound Controller
(191661, 1, 110890, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Cragsworn Stoneshaper
(194785, 1, 192499, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Timewalker Historian
(194787, 1, 178670, 0, 0, 107158, 0, 0, 0, 0, 0, 62876), -- Timewalker Warden
(194792, 1, 107284, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Timewalker Resistance Fighter
(195836, 1, 107670, 0, 0, 110340, 0, 0, 0, 0, 0, 62876), -- Rimebound Controller
(195837, 1, 110958, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Rimebound Subjugator
(195838, 1, 110890, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Cragsworn Stoneshaper
(195839, 1, 193827, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Cragsworn Conqueror
(199541, 1, 191418, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Tarnormu
(199566, 1, 73442, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Mankrik
(199800, 1, 199304, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Stormbound Striker
(200177, 1, 107284, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Timewalker Resistance Defender
(200726, 1, 191418, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Cormormu
(201152, 1, 156312, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Stormbound Sorcerer
(201153, 1, 199316, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Stormbound Reaver
(201545, 1, 110890, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Shapemaster Za'lani
(206150, 1, 155770, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Erol Ellimoore
(206167, 1, 118568, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Anxious Farmer
(206168, 1, 118559, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Anxious Farmer
(206441, 1, 155770, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Auebry Irongear
(208186, 1, 220478, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Yorvas Flintstrike
(209296, 1, 103000, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Awakaya
(209297, 1, 159087, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Skodu
(211015, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Gulcan the Steelhand
(213791, 1, 9482, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Zi'guma
(214263, 1, 50431, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Waxface
(214677, 1, 156987, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Invading Hurler
(214769, 1, 220493, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Stillpond Fishscrounger
(214769, 2, 5281, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Stillpond Fishscrounger
(215091, 1, 220493, 0, 0, 0, 0, 0, 220454, 0, 0, 62876), -- Rallied Recruit
(215137, 1, 220493, 0, 0, 0, 0, 0, 220454, 0, 0, 62876), -- Rallied Recruit
(215172, 1, 1265, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Valeir Steelshot
(215173, 1, 1265, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Lallie Fireclad
(215174, 1, 1265, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Gaeret Velhan
(215187, 1, 118400, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Overlord Geya'rah
(215198, 1, 126133, 0, 0, 0, 0, 0, 115029, 0, 0, 62876), -- Mag'har Grunt
(215277, 1, 110039, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Adelgonn
(215913, 1, 155770, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Berenike Wiskervale
(216247, 1, 221770, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Nerubian Ambusher
(216303, 1, 191276, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Kobold Looter
(216466, 1, 155788, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Unbound Fighter
(216467, 1, 155788, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Unbound Stormrider
(216468, 1, 165264, 0, 0, 165264, 0, 0, 0, 0, 0, 62876), -- Horde Wolfaxe
(216639, 1, 155794, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Master Tidesage
(218367, 1, 0, 0, 0, 0, 0, 0, 222897, 0, 0, 62876), -- Earthen Trainee
(218626, 1, 159591, 0, 0, 119202, 0, 0, 0, 0, 0, 62876), -- 7th Legion Soldier
(219881, 1, 166995, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Drowned Arathi
(221708, 1, 220500, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sir Alastair Purefire
(223205, 1, 150577, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- High Exarch Turalyon
(225768, 1, 226855, 0, 0, 0, 0, 0, 228221, 0, 0, 62876), -- Greedy Turncoat
(226666, 1, 166997, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Partially Teleported Murloc
(226667, 1, 192563, 0, 0, 192565, 0, 0, 0, 0, 0, 62876), -- Partially Teleported Gnoll
(226668, 1, 166849, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Partially Teleported Trogg
(226937, 1, 93376, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Evil Blue
(226938, 1, 194893, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Evil Rivet
(226939, 1, 184297, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Evil Arnott
(226941, 1, 163866, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Evil Kralla
(226942, 1, 216765, 0, 0, 127348, 0, 0, 0, 0, 0, 62876), -- Evil Crags
(227859, 1, 159591, 0, 0, 119202, 0, 0, 0, 0, 0, 62876), -- 7th Legion Soldier
(227860, 1, 126133, 0, 0, 0, 0, 0, 115029, 0, 0, 62876), -- Mag'har Grunt
(228553, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- General Rakera
(228570, 1, 106105, 0, 0, 102179, 0, 0, 0, 0, 0, 62876), -- Grand Vindicator Sorvos
(229307, 1, 191604, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Veteran Blood Knight
(229328, 1, 132170, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Suramar Chronomancer
(229340, 1, 109638, 0, 0, 7188, 0, 0, 0, 0, 0, 62876), -- Stormwind Knight
(229341, 1, 155687, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Hallowfall Lightblade
(229342, 1, 153585, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Zandalari Prelate
(229386, 1, 212992, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Mehlar Dawnblade
(229791, 1, 221769, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Nerubian Venomweb
(232087, 1, 214500, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sureki Marauder
(232088, 1, 214502, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sureki Weavelasher
(232094, 1, 221768, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sureki Acolyte
(232161, 1, 214503, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sureki Raider
(232163, 1, 224511, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Sureki Eradicator
(232164, 1, 224495, 0, 0, 224495, 0, 0, 0, 0, 0, 62876), -- Sureki Venomblade
(232307, 1, 232795, 0, 0, 232795, 0, 0, 232796, 0, 0, 62876), -- Arathi Scout
(232310, 1, 232801, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Crusader
(232312, 1, 232794, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Recruit
(232314, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Sky Knight
(232315, 1, 232795, 0, 0, 232792, 0, 0, 0, 0, 0, 62876), -- Arathi Priest
(232316, 1, 232798, 0, 0, 232793, 0, 0, 0, 0, 0, 62876), -- Arathi Knight
(232317, 1, 232797, 0, 0, 194330, 0, 0, 0, 0, 0, 62876), -- Arathi Adherent
(232320, 1, 232800, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Cleric
(232321, 1, 232799, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Knight
(237257, 1, 191690, 0, 0, 192135, 0, 0, 0, 0, 0, 62876), -- Construct of Soridormi
(237881, 1, 224529, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Veteran Sureki Eradicator
(237882, 1, 224518, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Veteran Sureki Raider
(237884, 1, 224535, 0, 0, 224535, 0, 0, 0, 0, 0, 62876), -- Veteran Sureki Shadowstalker
(238039, 1, 213615, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Arathi Worker
(240758, 1, 216397, 0, 0, 216397, 0, 0, 0, 0, 0, 62876), -- Construct of Soridormi
(240759, 1, 207988, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Construct of Soridormi
(241073, 1, 232801, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Aegor Irynbawnd
(241084, 1, 0, 0, 0, 0, 0, 0, 155818, 0, 0, 62876), -- Basir the Hammer
(243693, 1, 169455, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Relaxing Earthen
(244393, 1, 238393, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Portalmaster Halsan
(244922, 1, 240515, 0, 0, 240488, 0, 0, 0, 0, 0, 62876), -- Shadowguard Phaseblade
(250662, 1, 237803, 0, 0, 209920, 0, 0, 0, 0, 0, 62876), -- Adventurer's Echo
(250662, 2, 238005, 1, 0, 0, 0, 0, 0, 0, 0, 62876); -- Adventurer's Echo

UPDATE `creature_equip_template` SET `VerifiedBuild`=62876 WHERE (`ID`=1 AND `CreatureID` IN (2947,2948,2985,2988,2997,2998,2999,3001,3002,3003,3004,3005,3007,3008,3009,3010,3011,3012,3013,3014,3015,3016,3017,3018,3019,3020,3021,3022,3023,3024,3025,3026,3027,3028,3029,3054,3055,3063,3064,3065,3067,3076,3077,3078,3081,3083,3092,3093,3095,3212,3215,3217,3220,3221,3222,3223,3224,3232,3282,3283,3284,3286,3369,3399,3400,3404,3405,3442,3445,3501,3688,3884,4708,4943,5054,5189,5411,5594,5599,5640,5859,5899,5938,5939,5940,6290,6410,6568,6746,6747,7089,7311,7733,7799,7823,7824,7873,8124,8126,8128,8129,8131,8362,8363,8364,8398,8401,8404,8661,8736,9460,9985,9988,10054,10086,10278,10600,10881,11047,11071,11084,11814,12789,12793,12794,12795,14567,14743,15116,16014,16222,16800,16801,16802,19860,20672,21448,28126,30706,34261,34503,34674,34698,34723,34770,36644,36648,36825,36827,36828,37137,37153,37159,37170,37204,37560,37585,37660,37661,37811,37847,37908,37909,37922,37923,37924,37925,37926,37933,37971,37977,38070,38327,38534,38535,39034,39118,39154,39156,39178,40216,40558,40589,40809,41421,41431,41439,41458,43001,43013,43418,43613,43945,43953,43957,44305,44975,45008,45015,45019,45023,45029,45081,45086,45093,45094,45095,45137,45138,45139,45271,45272,45274,45347,45381,45383,45385,45410,45418,45540,45545,45546,45548,45549,45552,45553,45558,45563,45565,45566,45814,45830,45907,46078,46080,46082,51143,51372,51637,52170,52356,52357,52386,52651,53081,54472,54473,57801,68979,69323,69977,71000,71006,71010,71012,71384,73590,88084,88086,88089,88090,88094,88099,88100,88115,88782,88783,88798,88888,88970,89023,89341,89680,89846,91095,91459,93622,93805,94351,94846,95186,95191,95937,96470,97003,97666,98159,99386,99574,99581,99652,99708,100237,100357,100520,100780,102274,102623,103733,104220,105759,107251,107342,107367,108188,108190,108871,108875,109154,109159,109174,109368,109372,109647,109650,109652,110365,110726,110728,110870,111484,111485,111523,111653,111750,111869,111871,111872,112530,112531,112972,113597,113633,113634,113679,113707,114841,114866,114883,114885,114887,114897,114926,114927,114929,115381,115526,115684,115691,115926,116050,116116,116117,116118,116206,116360,116658,117246,117412,122130,126719,126720,126735,126774,128877,128991,128994,129009,129013,129022,129023,129024,129025,129026,129030,129121,129244,129252,129254,130133,130135,130142,130183,130201,131309,131420,131425,131478,131529,131530,131859,132177,132180,133127,133168,135205,135207,135208,135973,135976,140913,144769,145098,145199,145209,145230,145417,145424,147277,147289,147291,171791,173279,175050,176554,184168,184170,187013,187025,187041,187127,187264,187265,187266,187391,187397,187407,189165,189298,193458,194876,194877,197533,197783,201492,202656,204127,204188,205067,206129,206130,206135,206164,206165,206466,206883,208037,208054,208620,209901,210980,211016,211546,211777,212435,212436,212708,212800,212971,212973,213129,213145,213183,213197,213237,213400,213403,213405,213406,213408,213685,214019,214380,214392,214429,214435,214444,214465,214544,214545,214556,214557,214558,214559,214560,214561,214919,214995,215135,215236,215239,215242,215243,215301,215306,215523,215527,215567,215651,215652,215727,215931,216001,216035,216036,216045,216061,216094,216138,216156,216218,216584,216892,216897,217128,217151,217445,217447,217450,217451,217485,217516,217517,217518,217519,217541,217570,217602,217622,217639,217722,217730,217919,217961,217983,217989,217990,217992,218078,218079,218299,218375,218412,218431,218432,218441,218487,218488,218508,218509,218522,218541,218658,218723,219119,219266,219710,219805,219861,219862,219864,219870,219933,219934,219935,219939,220011,220246,220249,220252,220302,220569,220574,220718,220990,220991,220992,221187,221363,221383,221385,221411,221551,221793,221980,221982,222104,222180,222677,222678,222681,222683,222688,222692,222693,222724,222813,222834,223063,223144,223148,223154,223211,223244,223274,223365,223455,223457,223524,224149,224394,224424,224493,224741,224742,224744,224845,224846,224966,225485,225555,225571,225576,225578,225679,225680,225681,225687,225695,225760,225787,225797,225798,225809,225857,225879,226065,226217,226458,226509,226588,226658,226708,226727,226787,226791,226811,226813,226845,226846,226873,226876,226930,226931,226935,227047,227242,227477,227499,227523,227527,227544,227797,228117,228119,228296,228322,228325,228554,228560,228561,228563,228564,228568,228569,228571,228572,228590,228664,229299,229385,229489,230942,231542,231692,232313,232749,233379,234231,234774,234939,234986,235409,236059,236060,236061,238771,238772,238773,238888,239196,239197,239198,239199,239202,239833,240852,240909,240910,240912,240979,241079,241081,241086,241094,241095,241096,241099,241102,241104,241105,241106,241107,241340,241344,241865,241948,241949,241950,242016,243253,250729,250730,250731,250733,250765,250766,250767,250769)) OR (`ID`=2 AND `CreatureID` IN (30611,37922,41431,71000,71012,88782,99386,169177,213129,214465,217450,219709,238885,241102,241355)) OR (`ID`=3 AND `CreatureID` IN (37922,41431,238885)) OR (`ID`=5 AND `CreatureID` IN (41431,217450)) OR (`ID`=8 AND `CreatureID` IN (76168,238885)) OR (`ID`=4 AND `CreatureID` IN (169177,238885)) OR (`ID`=6 AND `CreatureID`=169177) OR (`ID`=7 AND `CreatureID` IN (219982,238885));

DELETE FROM `quest_template_locale` WHERE (`locale`='deDE' AND `ID` IN (53292,41304,44024,41266));
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(53292, 'deDE', 'Blühender Sirenendorn', '', '', '', '', '', '', '', '', 62876),
(41304, 'deDE', 'Blühende Sternlichtrosen', '', '', '', '', '', '', '', '', 62876),
(44024, 'deDE', 'GESUCHT: Shal\'an', '', '', '', '', '', '', '', '', 62876),
(41266, 'deDE', 'Angeln vom Floß', '', '', '', '', '', '', '', '', 62876);

UPDATE `quest_template_locale` SET `VerifiedBuild`=63163 WHERE (`locale`='deDE' AND `ID` IN (47561,57562,47135,67009,75119,82234,70172,74988,76394,83529,73698,70075,82041,67039,78434,81501,81805,70529,81808,70654,70625,81854,75062,70064,48286,83102,69942,82364,48374,71205,85487,91205,48466,67026,70712,70429,70639,70417,67014,70110,66070,81802));
UPDATE `quest_template_locale` SET `VerifiedBuild`=62876 WHERE (`locale`='deDE' AND `ID` IN (48698,56400,53759,54468,54414,54328,54091,52882,52879,52229,53832,53707,51627,52874,53313,53274,51287,51976,52063,52880,52347,52346,52757,52199,52459,52322,52306,52209,51462,51972,51970,51905,51895,51893,51890,51874,51847,51844,51811,51779,51765,51759,51745,51742,51654,51646,50164,51623,51611,51610,51505,51457,54707,54664,54645,54154,51049,51048,51042,51037,51629,53299,53322,51856,49888,52370,52351,52350,51011,52410,52337,52394,52393,52425,52420,52395,50999,52832,52007,52248,52169,51763,51792,51791,51124,51429,51116,51098,51097,51096,51118,51444,51379,51322,51330,51239,50633,50571,50287,50872,50866,50854,50717,50695,50592,50566,50513,50511,50510,50501,50499,50496,50461,44624,45542,45035,46942,46105,46814,46360,45921,45922,45924,46164,46066,46136,46134,45988,45837,44748,44802,44856,44759,44012,41458,43429,41532,41441,41433,41438,41434,44305,44302,44292,41347,41349,41637,41674,41638,41219,44190,41526,44158,41705,41240,41677,41671,43620,44054,44027,44017,43714,43453,42176,42442,43621,41428,43460,43457,41836,43455,43452,43434,43431,43427,43426,43324,43175,43091,41563,41634,41664,41654,41675,41287,41651,41311,41326,42880,42953,42927,41336,41551,41502,41482,41274,41514,42018,42148,41944,40278,41935,41895,42015,41955,41844,41828,41560,41549,41597,41701,41511,41209,41461,41078,40951,41011,40298,40280,48725));

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='deDE' AND `ID` IN (87475,87477,87480,91173,49614,49354,49613,49973,48079,42017,42005,49756,48067,48066,83496,83495,91855,91093,84365,74376,91484,91477,76588,79173,76997,88916,89349,89332,84776,82706,83771,84370,85664,84789,84784,85871,84782,84779,53763,53762,53761,54058,54118,84371,40710,81510,81514,82678));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(87475, 'deDE', 'Ein weiterer Sieg über die Sureki! Mereldars Verteidiger werden sich um die restlichen Neruber außerhalb der Mauern kümmern.\n\nDas Volk von Mereldar steht in Eurer Schuld.', 63305),
(87477, 'deDE', 'Gut gemacht, $gSoldat:Soldatin;! Der Schwarm wurde fürs Erste verlangsamt.\n\nZweifelsohne nähern sich uns just in diesem Moment noch mehr von den Biestern aus den Tiefen von Azj-Kahet.\n\nWenn sie auftauchen, werden die Strahlen der Flamme gewappnet sein!', 63305),
(87480, 'deDE', 'Eure Bemühungen, die Belagerung von Dunelles Güte zu vereiteln, waren ein Segen für ganz Heilsturz.\n\nWäre der Dämmersturm erloschen, hätte tiefe Finsternis den östlichen Teil von Heilsturz verschlungen.\n\nHabt Dank, $n.', 63305),
(91173, 'deDE', 'Ihr habt einen Augenblick des Friedens für uns herausgeschunden.\n\nRuht Euch aus, doch achtet stets darauf, dass Eure Klinge geschliffen ist.', 63305),
(49614, 'deDE', 'Und so endet die Geschichte darüber, wie die Nachtgeborenen der Horde beigetreten sind.\n\nIch kann mir nicht vorstellen, wo wir heute ohne Leute wie Oculeth und Thalyssra wären!\n\nWir haben den Nachtgeborenen unser stark verbessertes Teleportationssystem zu verdanken.\n\nVergesst das nie, $n. Wir müssen uns immer daran erinnern, warum wir alle Teil der Horde sind... und bleiben müssen.', 63305),
(49354, 'deDE', 'Das kam nicht unbedingt unerwartet.', 63305),
(49613, 'deDE', 'Gut, wir sind alle da. Unsere Gäste sollten in Kürze eintreffen.', 63305),
(49973, 'deDE', 'Die Stadt Suramar bietet einen prächtigen Anblick. Ich hoffe Silbermond stößt bei ihnen nicht auf Enttäuschung.', 63305),
(48079, 'deDE', 'Ebenhorn hat uralte Zauberschutze erwähnt, die am Hochberg aufrechterhalten werden müssen. Diese Zauberschutze sollen eine große Finsternis zurückhalten.$b$bDas steht vielleicht im Zusammenhang mit der bösen Macht, die sich seiner bemächtigt hat.$b$bWir müssen darauf hoffen, dass uns Geistwandler Grauhimmel mehr darüber erzählen kann.', 63305),
(42017, 'deDE', 'Es ermutigt mich, dass Eure Suche von Erfolg gekrönt war, $n. Wir haben Eure Rückkehr erwartet.', 63305),
(42005, 'deDE', 'Ich glaube, ich habe bereits eine Spur zu der Insel. In der Taverne war ein mächtiger Krieger, der auf einer Insel in Sturmheim ins Grab eines Vrykulkönigs eingedrungen ist.$b$bDas muss die sein, nach der wir suchen!', 63305),
(49756, 'deDE', 'Gute Arbeit, $n. Meine Leute werden ab hier übernehmen.', 63305),
(48067, 'deDE', 'Die Alten Götter sind für ihre Hinterlist und Falschheit bekannt. Und jetzt dieser direkte Angriff...$b$bWonach auch immer sie suchen... sie wollen es unbedingt.', 63305),
(48066, 'deDE', 'Seid willkommen, $n.$b$bMayla zählt Euch zu ihren treuesten Verbündeten. Dank Eurer Gegenwart sollte es möglich sein, sie von den Vorzügen eines Beitritts zur Horde zu überzeugen.', 63305),
(83496, 'deDE', 'Ein paar Problemchen, aber nichts, was nicht durch gute, altmodische Teamarbeit gemeistert werden konnte! Wir waren großartig!', 63305),
(83495, 'deDE', 'Gut gemacht!\n\nNicht das, was ich erwartet hatte, aber ich muss sagen, der Schnurrbart hat mir sehr gut gefallen!', 63305),
(91855, 'deDE', 'Ihr macht Helden überall alle Ehre. Habt Dank.', 62876),
(91093, 'deDE', 'Eure Unterstützung kommt sehr gelegen, $r. Der Bund hat eine weise Entscheidung getroffen, Euch darum zu bitten, uns bei unseren Bemühungen zu assistieren.', 62876),
(84365, 'deDE', 'Ich habe gehört, dass sich Verstärkung der Insel nähert. Ihr kennt Khaz Algar in- und auswendig. Sie werden euer Wissen brauchen.', 62876),
(74376, 'deDE', 'Faszinierend! Ich werde meine Befunde an die anderen Forscher in Valdrakken weitergeben.', 63305),
(91484, 'deDE', 'Wir haben eine Schwachstelle in der Werkstatt von Schmiedeweber Araz gefunden, die Euch Zugang zu einer weiteren Konsole in der Nähe verschafft. Bleibt am Ball. Wir geben Euch Bescheid, sobald die ganze Anlage unter unserer Kontrolle ist. Viel Erfolg bei der Jagd!', 63305),
(91477, 'deDE', 'Hört gut zu: Wir haben neue Technologie beschafft, die Euch helfen kann, die Schattenwache zu besiegen. Macht das Beste draus.', 63305),
(76588, 'deDE', 'Fantastische Arbeit, das sind zwei Bedrohungen weniger, um die wir uns kümmern müssen!', 63305),
(79173, 'deDE', 'Ihr habt deutlich mehr wiedererlangt, als wir uns erhoffen konnten. Ich habe einige der überschüssigen Dinge beiseite gelegt, damit Ihr sie haben könnt.', 63305),
(76997, 'deDE', 'Die Zeit an Eurer Seite ist eine viel bessere Ausbildung als ich diesen Rekruten jemals bieten könnte. Einer von Ihnen wird hier bleiben, um Euch weiterhin zur Seite zu stehen.', 63305),
(88916, 'deDE', 'Sich in die finsteren Tiefen von Azj-Kahet zu wagen, ist keine leichte Aufgabe, $gSoldat:Soldatin;.\n\nEure Arbeit dort unten hat dem Volk von Heilsturz eine kleine Verschnaufpause verschafft.', 63163),
(89349, 'deDE', 'Eure beispielhafte Hilfe ist nicht unbemerkt geblieben, $n. Ich hoffe, dass diese Belohnung Euch gute Dienste leistet.', 63163),
(89332, 'deDE', 'Der Heiligen Flamme sei Dank für Eure Unterstützung. Der Krieg geht weiter, doch wenigstens ist die Schlacht gewonnen.', 63163),
(84776, 'deDE', 'Ihr habt überlebt! Großartig!', 63163),
(82706, 'deDE', 'Da haben wir heute ein paar hübsche Orte zu erkunden. Das ist immer eine gute Sache. Da kommt mein altes Blut in Wallung.', 63163),
(83771, 'deDE', 'Gute Arbeit. Ich gebe Euch Bescheid, wenn ich noch mehr Unterstützung brauche.', 63163),
(84370, 'deDE', 'Erstaunlich! Das ist es, was ich übersehen habe. \n\nDie Karte, die Finley gefunden hat, ist chiffriert. Aber dieser Schlüssel ist unvollständig... Wenn Ihr da draußen noch mehr findet, bringt sie bitte zu mir. Ich werde diese Karte entschlüsseln, so wahr ich Elise Sternensucher heiße.', 63163),
(85664, 'deDE', 'Mir ist zu Ohren gekommen, dass jemand den Machenschaften des Ordens der Nacht ein Ende gesetzt hat. Gute Arbeit.', 63163),
(84789, 'deDE', 'Welche Bedeutung hatten die letzten Worte von Xal\'atath an N\'Zoth? Sah sie ihre zukünftige Zusammenarbeit voraus?\n\nWar das von Anfang an ihr Plan?', 62876),
(84784, 'deDE', 'Ich habe keine Zweifel, dass Lord N\'Zoth diese Xal\'atath auch ohne die Hilfe seiner Gebrüder vernichten könnte, hätte sie uns nicht derartig infiltriert.', 62876),
(85871, 'deDE', 'Ihr seid mit dem Staub der Schatten bedeckt wie das Blut Eurer Feinde. Gut.', 62876),
(84782, 'deDE', 'Ihr seid auserwählt, so bemitleidenswert Ihr auch seid. Ihr solltet dankbar sein.', 62876),
(84779, 'deDE', 'Ich glaube, die Informationen, die meine Lehrensucherkollegen und ich gefunden haben, sind vollkommen neu. Was ihre Bedeutung betrifft, bin ich mir noch unsicher, aber vielleicht könnt Ihr das ja entscheiden.', 62876),
(53763, 'deDE', '<Talanji lauscht Euren Erzählungen über Xal\'atath und N\'Zoth.>\n\nZandalar hat sich immer noch nich\' ganz vom Befall Uldirs durch den Alten Gott erholt. Wenn sich \'n weiterer erhebt...\n\nDas sind sehr bedrohliche Nachrichten. Diese Flut könn\'n wir nur gemeinsam abwend\'n.', 62876),
(53762, 'deDE', 'Ein weiterer Beweis dafür, dass Ihr und ich gemeinsam Großes erreichen können, $n.\n\nSo viele Möglichkeiten...', 62876),
(53761, 'deDE', 'Ich habe keine Sekunde an Euch gezweifelt.', 62876),
(54058, 'deDE', 'Lasst Euch nicht ablenken. Es gibt noch viel für uns zu tun.', 62876),
(54118, 'deDE', 'Ah... schon viel besser. Wie grausam von Euch, mich in einem solchen Zustand zu belassen!\n\nAber wir können später in Erinnerungen schwelgen. Ihr habt zweifelsohne eine Menge Fragen. Und wie Ihr wisst, biete ich unzählige Antworten.', 62876),
(84371, 'deDE', 'Xal\'atath war eine mächtige Waffe und... gesprächige Präsenz.', 62876),
(40710, 'deDE', 'Ihr habt ein beachtliches Talent für diese Art von Aufgaben an den Tag gelegt.\n\nEs ist erfreulich, denn wir werden Euch noch mehr abverlangen müssen, wenn wir diesen Konflikt überleben wollen.', 62876),
(81510, 'deDE', 'Mit dieser Maschine könnt Ihr Euch auf ganz Khaz Algar bewegen. Wir geben Euch Bescheid, wenn wir neue dafür Teile haben.\n\nDa das nun geklärt wäre: ab in die Tiefen!', 62876),
(81514, 'deDE', 'Das hat uns ganz schön was eingebracht! Wollt Ihr Euch noch mehr amüsieren?', 62876),
(82678, 'deDE', 'Die sind perfekt! Bei diesen Teilen ist die Korrosion minimal. Wir sollten sämtliche Informationen retten können, die sie enthalten!\n\nJetzt legen wir seit langem vergrabenes Wissen frei, $p!', 62876);

DELETE FROM `quest_objectives_locale` WHERE (`ID`=341060 AND `locale`='deDE');
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(341060, 'deDE', 53292, 0, 'Blühenden Sirenendorn gesammelt', 62876);

UPDATE `quest_objectives_locale` SET `VerifiedBuild`=63163 WHERE (`locale`='deDE' AND `ID` IN (290863,428710,428709,434860,449612,449611,449613,430054,434674,434673,451136,451135,451134,433307,430672,430671,430670,430669,429829,430648,449217,449216,449215,428874,428873,428872,444402,448482,448841,431129,430583,448844,430914,430926,430920,430685,449025,449020,449010,449005,448922,449040,449028,434921,434920,434919,430884,429521,449912,449911,449910,449909,449908,449906,431589,432307,456776,456775,456774,456284,456942,428781,430899,430422,430750,430407,428727,430529,430528,430527,430526,430525,429835,427035,423863,423862,423861,448838));
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=63305 WHERE (`ID`=281597 AND `locale`='deDE');
UPDATE `quest_objectives_locale` SET `VerifiedBuild`=62876 WHERE (`locale`='deDE' AND `ID` IN (390768,342199,342198,342195,387114,340204,352810,352782,342093,341818,336548,340159,340158,340157,340156,340155,335305,335304,340437,337935,339717,338353,338384,338383,335977,335976,337242,337241,337111,337009,336992,336598,296286,336541,387917,387569,386321,386297,341826,336552,341072,337419,337757,337756,338536,337147,337078,338091,338090,338089,338088,338087,337177,338071,338069,338068,338067,338066,337176,341206,335630,335629,335416,335229,333390,333125,312149,312067,312066,312065,312064,312063,333601,333595,333559,288113,288112,288111,289881,289880,289858,289683,289314,289200,288975,288973,288778,286912,287730,287176,287008,286919,288151,285257,286309,282717,282707,285557,286204,286191,285690,285285,284226,285558,282463,282462,285292,285289,282901,285287,285284,285261,285259,285255,285254,285171,285173,288525,285072,285037,282520,284857,284856,282433,282470,283523,283502,283500,283394,283393,283392,283391,283390,283771,283163,280583,283135,283134,283031,283381,283198,283196,282517,282699,282697,282467,282025,281925,281806,281859,281804,281747,281729,281634,280633,280585));

DELETE FROM `quest_greeting_locale` WHERE (`ID`=226919 AND `Type`=0 AND `locale`='deDE') OR (`ID`=230321 AND `Type`=0 AND `locale`='deDE');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(226919, 0, 'deDE', 'Es gibt immer mehr zu tun.', 63163),
(230321, 0, 'deDE', 'Vergesst nicht, wo Ihr steht.', 62876);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='deDE' AND `ID` IN (83495,89332,82706,84370,84784,53762,53761,54058,84371,82678));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(83495, 'deDE', 'Werft den Schalter herum!', 63305),
(89332, 'deDE', 'Jeder Schlag, den wir den restlichen Sureki versetzen können, schwächt sie in Heilsturz. Bitte beeilt Euch!', 63163),
(82706, 'deDE', 'Gefährliche Erkundung? Ums nackte Überleben kämpfen? Da fühlt sich dieser alte Zwerg lebendig!', 63163),
(84370, 'deDE', 'Diese Karte ergibt keinen Sinn... Champion! Ich hoffe, es gibt gute Nachrichten?', 63163),
(84784, 'deDE', 'Verschwendet nicht die Zeit von Lord N\'Zoth.', 62876),
(53762, 'deDE', 'Die Krone ist in unseren Händen viel nützlicher als in den Klauen eines übergroßen Siltfressers.', 62876),
(53761, 'deDE', 'Befindet sich der Dreizack in Eurem Besitz?', 62876),
(54058, 'deDE', 'So eine Abwechslung kann ganz belebend sein, oder, $n?', 62876),
(84371, 'deDE', 'Xal\'atath war eine wahrlich rätselhafte Kreatur. Ich frage mich, ob der Hohepriester sich je ausgemalt hat, wie weit sie gehen würde...', 62876),
(82678, 'deDE', 'Habt Ihr vielleicht etwas gefunden?', 62876);

DELETE FROM `page_text_locale` WHERE (`locale`='deDE' AND `ID` IN (9243,9141,5278,5272,5271,10001,10000,9999,9803,9975,9974,9973,5246,5247,5245));
INSERT INTO `page_text_locale` (`ID`, `Text`, `locale`, `VerifiedBuild`) VALUES
(9243, 'Hier steht Korrag, Wächter des Nordens, ein Sturmreiter.\n\nMöge uns sein Blick auf ewig beschützen.', 'deDE', 62876),
(9141, 'Ich grüße Euch, $n.\n\nMich hat Kunde von Euren mutigen Taten in unserem schönen Lande erreicht, genau wie von Euren jüngsten Abkommen mit den Individuen \"Die Weberin\" und \"Der General\".\n\nIch möchte behaupten, dass nun meine Wenigkeit an der Reihe ist.\n\nBitte sucht den Bau in der Stadt der Fäden auf. Gehe ich recht in der Annahme, dass Ihr Pheromone von Anub\'azal erlangt habt? Dies sollte genügen, um Euch Schatten in jenem Bau zu verschaffen, jedoch nirgendwo anders. Falls wir bei unserer Unterredung zu einer Übereinkunft kommen, wäre ich willens, Euch etwas Substanzielleres zur Verfügung zu stellen.\n\nAch, eines noch. Falls Ihr noch Zweifel an unserem Gespräch hegt, wisset, dass ich über Informationen zu Eurem vermissten kleinen Lord aus Sturmwind verfüge. Informationen, die Ihr höchstwahrscheinlich nirgendwo anders in Erfahrung bringen könntet.', 'deDE', 62876),
(5278, 'Enttäuscht, aber nicht entmutigt errichtete Yrgrim einen Schrein für Tyr und begrub sich selbst mit seinen Waffen darin, um auf eine Zeit zu warten, in der ein wahrer Champion sich zeigen würde.\n\nWer die Türen zu öffnen versuchte, wurde von den läuternden Flammen der Türzauberschutze verbrannt. Nur jene mit starkem Willen und reinem Herzen würden den Flammen widerstehen können.\n\nUnd sollte es jemand schaffen, so wird Yrgrim im Inneren warten.', 'deDE', 63305),
(5272, 'Auf einer Steininsel erbaute Yrgrim eine Arena. Er verkündete seinen Brüdern, dass er einen Nachfolger mit starkem Willen und Körper suchte, der ein reines Herz habe. Jeder würde seine Prüfungen absolvieren müssen, um seine Waffen beanspruchen zu können.\n\nViele der Berserker und Drachenreiter gingen auf Yrgrims Herausforderung ein, doch sie alle versagten und starben. Yrgrim hielt seine Prüfungen jahrelang ab, bis keine Herausforderer mehr kamen.\n\nDanach zog Yrgrim sich in einen Schrein zurück, den er selbst erbaut hatte. Er erschuf eine Tür, die über Geist und Körper eines jeden, der vor ihr stand, Urteil fällte. Wer ihrem Blick standhielt, durfte eintreten.', 'deDE', 63305),
(5271, 'Nach Tyrs Fall half Yrgrim der Wahrheitssuchende seinen Brüdern in Tirisfal und sicherte so ihr Überleben in der neuen Welt.\n\nIn dem Wissen, dass andere seines Volkes aus dem Norden geflüchtet waren, suchte er nach ihnen und hoffte, jemanden zu finden, an den er seine Waffen weitergeben könnte.\n\nSchließlich erreichte er Sturmheim und die starken Nachfahren seines Volks. Dies war eine Gruppe, in der er einen Würdigen zu finden hoffte.', 'deDE', 63305),
(10001, 'Was war das für eine ungewöhnliche Abmachung? In den nachfolgenden Jahren entdeckten die Lehrensucher eine uralte Geschichte aus der Zeit, als das Schwarze Imperium noch immer über ganz Azeroth herrschte. Die Geschichte sprach von Xal\'atath, einer Kreatur der Leere, und ihrem Verrat an den Alten Göttern. Auch wenn die Alten Götter nur selten zusammenarbeiteten, schien Xal\'atath eine ausreichende Bedrohung für sie zu sein, um sich zusammenzuschließen. Sie versammelten sich in Ny\'alotha und nahmen Xal\'atath gefangen.\n\nAls Strafe für ihren Verrat banden sie sie an die Klinge des Schwarzen Imperiums. Doch sie schien davon kaum beeindruckt zu sein. Stattdessen nahm sie insgeheim Kontakt zu N\'Zoth auf und bot ihm Macht und Ruhm, wenn er sie aufsuchen und das Versprochene einfordern würde.\n\nWar das die Abmachung, die N\'Zoth erfüllte, als er sie befreit hatte? Was war Xal\'atath? Was hat sie dazu bewogen, die Alten Götter zu verraten?\n\nDiese Fragen bleiben weiterhin offen, aber eines steht fest: Xal\'atath ist eine Gefahr, die nicht unterschätzt werden darf.', 'deDE', 62876),
(10000, 'Kurz nachdem die Invasion der Legion besiegt worden war, brach in Azeroth der Vierte Krieg aus. Horde und Allianz standen sich als Feinde gegenüber... und gaben so Xal\'atath eine Chance. Sie suchte jemanden, der ihr helfen würde, ihre Macht wiederherzustellen, und bot im Austausch selbst Macht an. So wurde sie nicht nur wiederhergestellt, sondern machte sich auch den Körper eines gefallenen Elfen zu eigen, auch wenn sie noch immer an die Klinge gebunden war.\n\nDoch nicht für lange Zeit. Xal\'atath brachte ihren Champion dazu, mächtige Artefakte zu sammeln, mit deren Hilfe sie den Weg dafür ebnete, N\'Zoth zu befreien und eine geheimnisvolle Abmachung zu erfüllen. Was das auch für eine Abmachung gewesen sein mag, N\'Zoth hielt sich daran und befreite Xal\'atath endlich aus der Klinge.', 'deDE', 62876),
(9999, 'Xal\'atath tauchte zum ersten Mal während der dritten Invasion der Legion auf. Ein Hohepriester suchte weit und breit nach einer mächtigen Waffe, um die Heere der Legion zu bekämpfen. Er fand Xal\'atath, die Klinge des Schwarzen Imperiums. Es war nicht nur eine mächtige Waffe, sondern schien sogar einen eigenen Willen zu haben.\n\nWährend der Hohepriester die Welt bereiste, flüsterte die Klinge oft in seinem Verstand von einer dunklen Vergangenheit und zukünftigen Versprechungen. Doch als die Schlachten endeten und Sargeras, der Anführer der Brennenden Legion, besiegt war, verlor auch die Schwarze Klinge ihre Macht.\n\nDie Klinge galt als verloren, doch das war sie nicht. Sie war lediglich geschwächt.', 'deDE', 62876),
(9803, 'Während des Transports alle Gliedmaßen innerhalb des Raketenbohrers behalten.\n\nSicherheitsgurte werden möglicherweise am Zielort zur Verfügung gestellt.\n\nWenn keine Sitze zur Verfügung stehen, können sie am Zielort gekauft werden.\n\nRaketenbohrer arbeiten bei gefährlichen Lärmpegeln.\n\nWarnsirenen sind möglicherweise deaktiviert, um die Fahrzeugführer nicht zu erschrecken.\n\nRaketenbohrer bewegen sich mit hoher Geschwindigkeit und kommen schlagartig zum Stehen. \n\nUngeplante Stopps können von ungeplanten Explosionen begleitet werden. \n\nEs kann vorkommen, dass ein gewisses Maß an Sicherheit besteht.\n\nUngültig wo verboten.', 'deDE', 62876),
(9975, 'Große Schlachten wurden geschlagen und Gehöfte gingen verloren. Doch am Ende blieben die Arathi standhaft.\n\nUnd als die Armeen des Reiches zurückkehrten und ihr Licht auf die vom Kampf gezeichneten Häuser fiel, trauerte die Kaiserin. In ihrem gerechten Bestreben, das Reich vor äußeren Bedrohungen zu schützen, hatte sie die im Inneren lauernde Dunkelheit übersehen.\n\nLobend erklärte die Kaiserin die von den Menschen vollbrachte Tat als eine, die der Heiligung würdig war.\n\nDurch ihre Hand wurde sie zum \"Strahlen der Flamme\" erklärt: Ein Edikt, das alle Arathi, ob jung oder alt, trainiert oder untrainiert, geschworen haben.\n\nSollte das Licht des Reiches aus irgendeinem Grund abwesend oder erloschen sein, kann das Edikt der Strahlen der Flamme erlassen werden, um das Volk zu mobilisieren und das Reich zu schützen.', 'deDE', 63163),
(9974, 'Als die Schatten näher kamen, waren es die alten Kriegsveteranen, Soldaten, die als zu alt oder zu verwundet galten, um in den Krieg zu ziehen, die die erste Fackel entzündeten.\n\nSie zogen ihre staubigen, abgenutzten Rüstungen an und zückten ihre kampferprobten Klingen. Dann trommelten sie den Rest des einfachen Volkes zusammen.\n\nHandwerker, Bauern und Arbeiter sammelten sich, um ihre Worte zu hören:\n\n\"Das Licht der Kaiserin mag weit entfernt und verblasst sein, aber die Heilige Flamme brennt noch. Die Dunkelheit mag nun näher rücken, aber wir haben noch immer unsere eigene Flamme. Wir leuchten mit unserer eigenen Strahlkraft. Wir werden nicht wanken!\"\n\nDurch das Strahlen ihrer Flammen schloss sich das einfache Volk mit den Veteranen zusammen, und gemeinsam hielten jeder Bedrohung stand.', 'deDE', 63163),
(9973, 'Mögen die Strahlen der Flamme uns daran erinnern, dass selbst in den dunkelsten Zeiten eine einzige Fackel die Dunkelheit vertreiben kann.\n\nVor langer Zeit, im Zeitalter des Aufruhrs und der Zwietracht, rückten ferne Gegner gegen unser großes Reich vor. Die Kaiserin war entschlossen, sich ihren Gegnern zu stellen, versammelte ihre Armeen und berief alle verfügbaren Soldaten ein.\n\nDie geballte Macht des Reiches marschierte in den Krieg und das Licht ihrer Fackeln am Horizont wurde immer schwächer. Die Zurückgebliebenen wurden von Dunkelheit umhüllt.\n\nEs gab keine Soldaten oder Wachen mehr, die sie beschützen konnten, und den Schwachen im ganzen Land drohten überall Gefahren.', 'deDE', 63163),
(5246, 'Auf Befehl des Diakons haben wir eine kleine Basis errichtet. Er ist unbeirrbar, also ist dies sicher der richtige Weg für den Schattenhammer. Wir werden für unsere Feinde sichtbar sein, doch er glaubt, dass es das Risiko wert ist.\n\nEine Art von zerbrochenem Siegel führt zu einem Komplex unter dem See. Der See selbst sieht aus, als hätte es hier vor einigen Jahrtausenden eine titanische Explosion gegeben. Irgendwie wusste der Schattendiakon von diesem Ort und dass C\'Thraxxi hier starb. Sein Plan ist wagemutig. Er wird die Schwarze Klinge nutzen, um das uralte Wesen wiederzubeleben und den Schattenhammer zu höchster Macht auferstehen zu lassen.\n\nMorgen gehe ich hinein, um die Truppen zu befehligen, die den oberen Bereich absichern. Er hat die Zauberschutze bereits geschwächt und bereitet sich darauf vor, den unteren Bereich zu betreten.', 'deDE', 62876),
(5247, 'Der Schattendiakon war ein vorsichtiger und berechnender Meister, der die Stille der Schatten direkten Handlungen vorzog. Seitdem er die Klinge fand, hat sich sein ganzes Wesen verändert. Arrogant, dominant, verwegen. Er verfolgt nun einen kühnen Plan, der die Macht des Schattenhammers wiederherstellen soll.\n\nDer Name der Klinge ist Xal\'atath. Sie stammt aus einem Zeitalter, bevor die meisten unserer Völker existierten. Wir verfügen nur über einige Kritzeleien ihrer früheren Hüter. Obwohl es größtenteils das Gestammel jener ist, deren Wille zu schwach war, die Klinge zu führen, sprechen viele jedoch von denselben Dingen.\n\nSie sprechen vom Schwarzen Imperium, von einer Zeit, da unsere wahren Meister ganz Azeroth beherrschten. Gewaltige Opfer, lebende Gebäude gefüllt mit Leerenenergien. Manchmal können wir hören, wie der Schattendiakon in seinem Zelt mit... jemandem spricht. Auch er hat die Pracht des Schwarzen Imperiums erwähnt.', 'deDE', 62876),
(5245, 'Gelobt sei der neue Anführer! Er, der einst die Hand des Zwielichtvaters war, der Schattendiakon, hat entschieden, dass es an der Zeit ist, unseren vergangenen Ruhm zurückzugewinnen!\n\nWährend der Zwielichtvater uns verließ, um Todesschwinge zu dienen, behielt der Schattendiakon seine \"Rolle\" als Bischof in Sturmwind bei. Er fuhr dort bis zum Sturz Todesschwinges und des Zwielichtvaters mit der Infiltration und der Rekrutierung fort. Dann befahl er den Überresten unserer Organisation, abzutauchen und unseren Widersachern ihren vorläufigen Sieg zu gönnen.\n\nDoch dann fand er sie oder vielleicht fand sie ihn. Die Schwarze Klinge...', 'deDE', 62876);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (87475 /*Sureki Incursion: Hold the Wall*/, 87477 /*Sureki Incursion: Southern Swarm*/, 87480 /*Sureki Incursion: The Eastern Assault*/, 91173 /*The Flame Burns Eternal*/, 49614 /*The Nightborne*/, 49354 /*Remember the Sunwell*/, 49613 /*Silvermoon City*/, 49973 /*Thalyssra's Estate*/, 48079 /*Return to Highmountain*/, 49756 /*Dark Forces*/, 48067 /*Shadow Over Thunder Bluff*/, 48066 /*A Feast for Our Kin*/, 83496 /*Warbands: Spacetime is Money*/, 83495 /*Warbands: Twinsposition*/, 84365 /*Something on the Horizon*/, 81510 /*Ship It!*/, 81514 /*Bountiful Delves*/, 82678 /*Archives: The First Disc*/, 83333 /*Gearing Up for Trouble*/, 85649 /*Delver's Call: The Waterworks*/, 74376 /*Coalesced Storm Remnants*/, 91484 /*Hacking the Forgeweaver*/, 91477 /*Behind Enemy Lines II*/, 76588 /*Defender of the Flame*/, 79173 /*Supply the Effort*/, 76997 /*Lost in Shadows*/, 88916 /*Radiant Incursion: Sureki's End*/, 89349 /*Flame's Radiance Stipend*/, 89332 /*Boot Camp*/, 84776 /*A Call to Delves*/, 83771 /*Delver's Call: Tak-Rethan Abyss*/, 85664 /*Delver's Call: Nightfall Sanctum*/, 84789 /*Lorewalking: The Blade's Downfall*/, 84784 /*Lorewalking: The Blade's Nemeses*/, 85871 /*Lorewalking: The Blade's Forces*/, 84782 /*Lorewalking: The Blade's Past*/, 84779 /*Lorewalking: The Blade's Gambit*/, 53763 /*Twist the Knife*/, 53762 /*The Tempest Crown*/, 53761 /*The Pirate's Treasure*/, 54058 /*Unintended Consequences*/, 54118 /*Every Little Death Helps*/, 84371 /*Lorewalking: The Blade and the High Priest*/, 89493 /*Welcome to the Field*/, 85005 /*A Radiant Call*/, 85648 /*Delver's Call: Earthcrawl Mines*/, 82296 /*The Power of Creation*/, 88803 /*Timely Assistance*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(87475, 1005, 0, 0, 0, 0, 0, 0, 0, 'Ein weiterer Sieg über die Sureki! Mereldars Verteidiger werden sich um die restlichen Neruber außerhalb der Mauern kümmern.\n\nDas Volk von Mereldar steht in Eurer Schuld.', 63305), -- Sureki Incursion: Hold the Wall
(87477, 1005, 0, 0, 0, 0, 0, 0, 0, 'Gut gemacht, $gSoldat:Soldatin;! Der Schwarm wurde fürs Erste verlangsamt.\n\nZweifelsohne nähern sich uns just in diesem Moment noch mehr von den Biestern aus den Tiefen von Azj-Kahet.\n\nWenn sie auftauchen, werden die Strahlen der Flamme gewappnet sein!', 63305), -- Sureki Incursion: Southern Swarm
(87480, 1005, 0, 0, 0, 0, 0, 0, 0, 'Eure Bemühungen, die Belagerung von Dunelles Güte zu vereiteln, waren ein Segen für ganz Heilsturz.\n\nWäre der Dämmersturm erloschen, hätte tiefe Finsternis den östlichen Teil von Heilsturz verschlungen.\n\nHabt Dank, $n.', 63305), -- Sureki Incursion: The Eastern Assault
(91173, 66, 0, 0, 0, 0, 0, 0, 0, 'Ihr habt einen Augenblick des Friedens für uns herausgeschunden.\n\nRuht Euch aus, doch achtet stets darauf, dass Eure Klinge geschliffen ist.', 63305), -- The Flame Burns Eternal
(49614, 0, 0, 0, 0, 0, 0, 0, 0, 'Und so endet die Geschichte darüber, wie die Nachtgeborenen der Horde beigetreten sind.\n\nIch kann mir nicht vorstellen, wo wir heute ohne Leute wie Oculeth und Thalyssra wären!\n\nWir haben den Nachtgeborenen unser stark verbessertes Teleportationssystem zu verdanken.\n\nVergesst das nie, $n. Wir müssen uns immer daran erinnern, warum wir alle Teil der Horde sind... und bleiben müssen.', 63305), -- The Nightborne
(49354, 1, 0, 0, 0, 0, 0, 0, 0, 'Das kam nicht unbedingt unerwartet.', 63305), -- Remember the Sunwell
(49613, 0, 0, 0, 0, 0, 0, 0, 0, 'Gut, wir sind alle da. Unsere Gäste sollten in Kürze eintreffen.', 63305), -- Silvermoon City
(49973, 0, 0, 0, 0, 0, 0, 0, 0, 'Die Stadt Suramar bietet einen prächtigen Anblick. Ich hoffe Silbermond stößt bei ihnen nicht auf Enttäuschung.', 63305), -- Thalyssra's Estate
(48079, 1, 1, 0, 0, 0, 0, 0, 0, 'Ebenhorn hat uralte Zauberschutze erwähnt, die am Hochberg aufrechterhalten werden müssen. Diese Zauberschutze sollen eine große Finsternis zurückhalten.$b$bDas steht vielleicht im Zusammenhang mit der bösen Macht, die sich seiner bemächtigt hat.$b$bWir müssen darauf hoffen, dass uns Geistwandler Grauhimmel mehr darüber erzählen kann.', 63305), -- Return to Highmountain
(49756, 1, 6, 0, 0, 0, 0, 0, 0, 'Gute Arbeit, $n. Meine Leute werden ab hier übernehmen.', 63305), -- Dark Forces
(48067, 1, 1, 0, 0, 0, 0, 0, 0, 'Die Alten Götter sind für ihre Hinterlist und Falschheit bekannt. Und jetzt dieser direkte Angriff...$b$bWonach auch immer sie suchen... sie wollen es unbedingt.', 63305), -- Shadow Over Thunder Bluff
(48066, 1, 1, 0, 0, 0, 0, 0, 0, 'Seid willkommen, $n.$b$bMayla zählt Euch zu ihren treuesten Verbündeten. Dank Eurer Gegenwart sollte es möglich sein, sie von den Vorzügen eines Beitritts zur Horde zu überzeugen.', 63305), -- A Feast for Our Kin
(83496, 603, 0, 0, 0, 0, 0, 0, 0, 'Ein paar Problemchen, aber nichts, was nicht durch gute, altmodische Teamarbeit gemeistert werden konnte! Wir waren großartig!', 63305), -- Warbands: Spacetime is Money
(83495, 1, 0, 0, 0, 0, 0, 0, 0, 'Gut gemacht!\n\nNicht das, was ich erwartet hatte, aber ich muss sagen, der Schnurrbart hat mir sehr gut gefallen!', 63305), -- Warbands: Twinsposition
(84365, 1, 0, 0, 0, 0, 0, 0, 0, 'Ich habe gehört, dass sich Verstärkung der Insel nähert. Ihr kennt Khaz Algar in- und auswendig. Sie werden euer Wissen brauchen.', 62876), -- Something on the Horizon
(81510, 1, 25, 0, 0, 0, 0, 0, 0, 'Mit dieser Maschine könnt Ihr Euch auf ganz Khaz Algar bewegen. Wir geben Euch Bescheid, wenn wir neue dafür Teile haben.\n\nDa das nun geklärt wäre: ab in die Tiefen!', 62876), -- Ship It!
(81514, 604, 0, 0, 0, 0, 0, 0, 0, 'Das hat uns ganz schön was eingebracht! Wollt Ihr Euch noch mehr amüsieren?', 62876), -- Bountiful Delves
(82678, 1, 0, 0, 0, 0, 0, 0, 0, 'Die sind perfekt! Bei diesen Teilen ist die Korrosion minimal. Wir sollten sämtliche Informationen retten können, die sie enthalten!\n\nJetzt legen wir seit langem vergrabenes Wissen frei, $p!', 62876), -- Archives: The First Disc
(83333, 4, 1, 0, 0, 0, 0, 0, 0, 'The machine continues in its duties once again.\n\nThank you again for your assistance.', 62876), -- Gearing Up for Trouble
(85649, 1022, 0, 0, 0, 0, 0, 0, 0, 'Commendable work within the Waterworks.', 62876), -- Delver's Call: The Waterworks
(74376, 0, 0, 0, 0, 0, 0, 0, 0, 'Faszinierend! Ich werde meine Befunde an die anderen Forscher in Valdrakken weitergeben.', 63305), -- Coalesced Storm Remnants
(91484, 0, 0, 0, 0, 0, 0, 0, 0, 'Wir haben eine Schwachstelle in der Werkstatt von Schmiedeweber Araz gefunden, die Euch Zugang zu einer weiteren Konsole in der Nähe verschafft. Bleibt am Ball. Wir geben Euch Bescheid, sobald die ganze Anlage unter unserer Kontrolle ist. Viel Erfolg bei der Jagd!', 63305), -- Hacking the Forgeweaver
(91477, 0, 0, 0, 0, 0, 0, 0, 0, 'Hört gut zu: Wir haben neue Technologie beschafft, die Euch helfen kann, die Schattenwache zu besiegen. Macht das Beste draus.', 63305), -- Behind Enemy Lines II
(76588, 0, 0, 0, 0, 0, 0, 0, 0, 'Fantastische Arbeit, das sind zwei Bedrohungen weniger, um die wir uns kümmern müssen!', 63305), -- Defender of the Flame
(79173, 1, 0, 0, 0, 0, 0, 0, 0, 'Ihr habt deutlich mehr wiedererlangt, als wir uns erhoffen konnten. Ich habe einige der überschüssigen Dinge beiseite gelegt, damit Ihr sie haben könnt.', 63305), -- Supply the Effort
(76997, 1, 0, 0, 0, 0, 0, 0, 0, 'Die Zeit an Eurer Seite ist eine viel bessere Ausbildung als ich diesen Rekruten jemals bieten könnte. Einer von Ihnen wird hier bleiben, um Euch weiterhin zur Seite zu stehen.', 63305), -- Lost in Shadows
(88916, 66, 0, 0, 0, 0, 0, 0, 0, 'Sich in die finsteren Tiefen von Azj-Kahet zu wagen, ist keine leichte Aufgabe, $gSoldat:Soldatin;.\n\nEure Arbeit dort unten hat dem Volk von Heilsturz eine kleine Verschnaufpause verschafft.', 63163), -- Radiant Incursion: Sureki's End
(89349, 0, 0, 0, 0, 0, 0, 0, 0, 'Eure beispielhafte Hilfe ist nicht unbemerkt geblieben, $n. Ich hoffe, dass diese Belohnung Euch gute Dienste leistet.', 63163), -- Flame's Radiance Stipend
(89332, 4, -1, 0, 0, 0, 0, 0, 0, 'Der Heiligen Flamme sei Dank für Eure Unterstützung. Der Krieg geht weiter, doch wenigstens ist die Schlacht gewonnen.', 63163), -- Boot Camp
(84776, 1, 0, 0, 0, 0, 0, 0, 0, 'Ihr habt überlebt! Großartig!', 63163), -- A Call to Delves
(83771, 1022, 0, 0, 0, 0, 0, 0, 0, 'Gute Arbeit. Ich gebe Euch Bescheid, wenn ich noch mehr Unterstützung brauche.', 63163), -- Delver's Call: Tak-Rethan Abyss
(85664, 1, 0, 0, 0, 0, 0, 0, 0, 'Mir ist zu Ohren gekommen, dass jemand den Machenschaften des Ordens der Nacht ein Ende gesetzt hat. Gute Arbeit.', 63163), -- Delver's Call: Nightfall Sanctum
(84789, 1, 0, 0, 0, 0, 0, 0, 0, 'Welche Bedeutung hatten die letzten Worte von Xal\'atath an N\'Zoth? Sah sie ihre zukünftige Zusammenarbeit voraus?\n\nWar das von Anfang an ihr Plan?', 62876), -- Lorewalking: The Blade's Downfall
(84784, 1, 0, 0, 0, 0, 0, 0, 0, 'Ich habe keine Zweifel, dass Lord N\'Zoth diese Xal\'atath auch ohne die Hilfe seiner Gebrüder vernichten könnte, hätte sie uns nicht derartig infiltriert.', 62876), -- Lorewalking: The Blade's Nemeses
(85871, 1, 0, 0, 0, 0, 0, 0, 0, 'Ihr seid mit dem Staub der Schatten bedeckt wie das Blut Eurer Feinde. Gut.', 62876), -- Lorewalking: The Blade's Forces
(84782, 1, 0, 0, 0, 0, 0, 0, 0, 'Ihr seid auserwählt, so bemitleidenswert Ihr auch seid. Ihr solltet dankbar sein.', 62876), -- Lorewalking: The Blade's Past
(84779, 1, 0, 0, 0, 0, 0, 0, 0, 'Ich glaube, die Informationen, die meine Lehrensucherkollegen und ich gefunden haben, sind vollkommen neu. Was ihre Bedeutung betrifft, bin ich mir noch unsicher, aber vielleicht könnt Ihr das ja entscheiden.', 62876), -- Lorewalking: The Blade's Gambit
(53763, 1, 1, 0, 0, 0, 0, 0, 0, '<Talanji lauscht Euren Erzählungen über Xal\'atath und N\'Zoth.>\n\nZandalar hat sich immer noch nich\' ganz vom Befall Uldirs durch den Alten Gott erholt. Wenn sich \'n weiterer erhebt...\n\nDas sind sehr bedrohliche Nachrichten. Diese Flut könn\'n wir nur gemeinsam abwend\'n.', 62876), -- Twist the Knife
(53762, 1, 1, 0, 0, 0, 0, 0, 0, 'Ein weiterer Beweis dafür, dass Ihr und ich gemeinsam Großes erreichen können, $n.\n\nSo viele Möglichkeiten...', 62876), -- The Tempest Crown
(53761, 1, 1, 0, 0, 0, 0, 0, 0, 'Ich habe keine Sekunde an Euch gezweifelt.', 62876), -- The Pirate's Treasure
(54058, 1, 1, 0, 0, 0, 0, 0, 0, 'Lasst Euch nicht ablenken. Es gibt noch viel für uns zu tun.', 62876), -- Unintended Consequences
(54118, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah... schon viel besser. Wie grausam von Euch, mich in einem solchen Zustand zu belassen!\n\nAber wir können später in Erinnerungen schwelgen. Ihr habt zweifelsohne eine Menge Fragen. Und wie Ihr wisst, biete ich unzählige Antworten.', 62876), -- Every Little Death Helps
(84371, 1, 0, 0, 0, 0, 0, 0, 0, 'Xal\'atath war eine mächtige Waffe und... gesprächige Präsenz.', 62876), -- Lorewalking: The Blade and the High Priest
(89493, 0, 0, 0, 0, 0, 0, 0, 0, 'Welcome, cadet! Glad to have you here. \n\nNo time like the present to get in there. Fight the Sureki with everything you\'ve got--we\'re counting on you.', 62876), -- Welcome to the Field
(85005, 66, 0, 0, 0, 0, 0, 0, 0, 'I see you received my message $p, wonderful! We can always use more capable soldiers among the ranks of the Flame\'s Radiance.', 62876), -- A Radiant Call
(85648, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s one less issue to deal with.', 62876), -- Delver's Call: Earthcrawl Mines
(82296, 0, 0, 0, 0, 0, 0, 0, 0, 'Ah, the Catalyst. It\'s a marvel that even words struggle to capture. \n\nPicture this, young one. Long before our city\'s foundations were laid, Titans roamed this land. Masters of the innovation, they forged wonders beyond imagination. And amidst their great works, they crafted the Catalyst.\n\nAnd now its very power belongs to you.', 62876), -- The Power of Creation
(88803, 0, 0, 0, 0, 0, 0, 0, 0, 'You may call upon this aid for any vision.', 62876); -- Timely Assistance

UPDATE `quest_offer_reward` SET `RewardText`='Es ermutigt mich, dass Eure Suche von Erfolg gekrönt war, $n. Wir haben Eure Rückkehr erwartet.', `VerifiedBuild`=63305 WHERE `ID`=42017; -- Shrine of the Truthguard
UPDATE `quest_offer_reward` SET `RewardText`='Ich glaube, ich habe bereits eine Spur zu der Insel. In der Taverne war ein mächtiger Krieger, der auf einer Insel in Sturmheim ins Grab eines Vrykulkönigs eingedrungen ist.$b$bDas muss die sein, nach der wir suchen!', `VerifiedBuild`=63305 WHERE `ID`=42005; -- The End of the Saga
UPDATE `quest_offer_reward` SET `RewardText`='Ihr macht Helden überall alle Ehre. Habt Dank.', `VerifiedBuild`=62876 WHERE `ID`=91855; -- Worldsoul: K'aresh World Quests
UPDATE `quest_offer_reward` SET `RewardText`='Eure Unterstützung kommt sehr gelegen, $r. Der Bund hat eine weise Entscheidung getroffen, Euch darum zu bitten, uns bei unseren Bemühungen zu assistieren.', `VerifiedBuild`=62876 WHERE `ID`=91093; -- More Than Just a Phase
UPDATE `quest_offer_reward` SET `VerifiedBuild`=62876 WHERE `ID` IN (91525, 83275, 91624, 83759, 87336, 87335, 87332, 87329);
UPDATE `quest_offer_reward` SET `RewardText`='Hmm, as I suspected. Yes... I need to adjust this here... done.\n\nThe good news is that this upgrade will nae make yer belt explode! I thought there was a small chance, but no longer. Yer data proved that I set the power too high. So... good thing I had ye do tha\' extra check, right?', `VerifiedBuild`=62876 WHERE `ID`=91030; -- New Titan Directives
UPDATE `quest_offer_reward` SET `RewardText`='Ihr habt ein beachtliches Talent für diese Art von Aufgaben an den Tag gelegt.\n\nEs ist erfreulich, denn wir werden Euch noch mehr abverlangen müssen, wenn wir diesen Konflikt überleben wollen.', `VerifiedBuild`=62876 WHERE `ID`=40710; -- Blade in Twilight
UPDATE `quest_offer_reward` SET `RewardText`='Here, yes... With that information I can make some final tweaks. And adding this directive...\n\nAh! That should do it. If you insert this into yer durable information storage container, it should update the effectiveness of the device\'s, um... effects.', `VerifiedBuild`=62876 WHERE `ID`=91026; -- Gathering an Upgrade
UPDATE `quest_offer_reward` SET `RewardText`='Thank you for dealing with that threat. One day they won\'t be such a malfunction in our systems.', `VerifiedBuild`=62876 WHERE `ID`=83758; -- Delver's Call: Fungal Folly
UPDATE `quest_offer_reward` SET `RewardText`='Attach the device. Yes! The device is powered on. \n\nOkay... If I just start the initialization sequence... and it\'s up. There are already two discs inside. And the menu will list areas where other miniature titan discs can be found. I\'m thinkin\' I can improve the device, but I need time. Find me later and see.', `VerifiedBuild`=62876 WHERE `ID`=91009; -- Durable Information Storage Container

DELETE FROM `quest_greeting` WHERE (`ID`=230321 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(230321, 0, 0, 0, 'Vergesst nicht, wo Ihr steht.', 62876); -- 230321

UPDATE `quest_greeting` SET `Greeting`='Yes?', `VerifiedBuild`=62876 WHERE (`ID`=224566 AND `Type`=0); -- 224566
UPDATE `quest_greeting` SET `VerifiedBuild`=62876 WHERE (`ID`=455716 AND `Type`=1);

DELETE FROM `quest_details` WHERE `ID` IN (87477 /*Sureki Incursion: Southern Swarm*/, 87475 /*Sureki Incursion: Hold the Wall*/, 87480 /*Sureki Incursion: The Eastern Assault*/, 49614 /*The Nightborne*/, 49354 /*Remember the Sunwell*/, 49613 /*Silvermoon City*/, 41884 /*Dark Tales*/, 48079 /*Return to Highmountain*/, 49756 /*Dark Forces*/, 48067 /*Shadow Over Thunder Bluff*/, 83496 /*Warbands: Spacetime is Money*/, 83495 /*Warbands: Twinsposition*/, 83465 /*Ara-Kara, City of Echoes*/, 83357 /*The Very Best*/, 91484 /*Hacking the Forgeweaver*/, 91477 /*Behind Enemy Lines II*/, 83102 /*Bismuth is Business*/, 81510 /*Ship It!*/, 83333 /*Gearing Up for Trouble*/, 85649 /*Delver's Call: The Waterworks*/, 74376 /*Coalesced Storm Remnants*/, 83497 /*A Concerned Friend*/, 76588 /*Defender of the Flame*/, 76997 /*Lost in Shadows*/, 88916 /*Radiant Incursion: Sureki's End*/, 88945 /*Radiant Incursion: Rak-Zakaz*/, 88711 /*Radiant Incursion: Toxins and Pheromones*/, 91173 /*The Flame Burns Eternal*/, 83276 /*Saving Private Spindle*/, 85664 /*Delver's Call: Nightfall Sanctum*/, 84789 /*Lorewalking: The Blade's Downfall*/, 84784 /*Lorewalking: The Blade's Nemeses*/, 85871 /*Lorewalking: The Blade's Forces*/, 84782 /*Lorewalking: The Blade's Past*/, 53763 /*Twist the Knife*/, 53762 /*The Tempest Crown*/, 53761 /*The Pirate's Treasure*/, 54058 /*Unintended Consequences*/, 54118 /*Every Little Death Helps*/, 84779 /*Lorewalking: The Blade's Gambit*/, 89332 /*Boot Camp*/, 89331 /*Flame Fortification*/, 80184 /*Preserving in Battle*/, 80189 /*Preserving Teamwork*/, 84490 /*The Great Vault*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(87477, 603, 0, 0, 0, 0, 0, 0, 0, 63305), -- Sureki Incursion: Southern Swarm
(87475, 603, 0, 0, 0, 0, 0, 0, 0, 63305), -- Sureki Incursion: Hold the Wall
(87480, 603, 0, 0, 0, 0, 0, 0, 0, 63305), -- Sureki Incursion: The Eastern Assault
(49614, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- The Nightborne
(49354, 1, 1, 0, 0, 0, 0, 0, 0, 63305), -- Remember the Sunwell
(49613, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Silvermoon City
(41884, 113, 1, 0, 0, 0, 0, 0, 0, 63305), -- Dark Tales
(48079, 669, 0, 0, 0, 0, 0, 0, 0, 63305), -- Return to Highmountain
(49756, 669, 0, 0, 0, 0, 0, 0, 0, 63305), -- Dark Forces
(48067, 6, 603, 0, 0, 0, 1500, 0, 0, 63305), -- Shadow Over Thunder Bluff
(83496, 603, 0, 0, 0, 0, 0, 0, 0, 63305), -- Warbands: Spacetime is Money
(83495, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- Warbands: Twinsposition
(83465, 1, 0, 0, 0, 0, 0, 0, 0, 63163), -- Ara-Kara, City of Echoes
(83357, 1, 0, 0, 0, 0, 0, 0, 0, 63163), -- The Very Best
(91484, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Hacking the Forgeweaver
(91477, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Behind Enemy Lines II
(83102, 1, 0, 0, 0, 0, 0, 0, 0, 63163), -- Bismuth is Business
(81510, 4, 11, 0, 0, 0, 0, 0, 0, 62876), -- Ship It!
(83333, 1, 273, 1, 0, 0, 0, 0, 0, 62876), -- Gearing Up for Trouble
(85649, 5, 1, 1, 0, 0, 0, 0, 0, 62876), -- Delver's Call: The Waterworks
(74376, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Coalesced Storm Remnants
(83497, 1, 1, 0, 0, 0, 500, 0, 0, 63305), -- A Concerned Friend
(76588, 0, 0, 0, 0, 0, 0, 0, 0, 63305), -- Defender of the Flame
(76997, 1, 0, 0, 0, 0, 0, 0, 0, 63305), -- Lost in Shadows
(88916, 603, 66, 0, 0, 0, 0, 0, 0, 63163), -- Radiant Incursion: Sureki's End
(88945, 5, 0, 0, 0, 0, 0, 0, 0, 63163), -- Radiant Incursion: Rak-Zakaz
(88711, 5, 1, 0, 0, 0, 0, 0, 0, 63163), -- Radiant Incursion: Toxins and Pheromones
(91173, 6, 0, 0, 0, 0, 0, 0, 0, 63163), -- The Flame Burns Eternal
(83276, 0, 0, 0, 0, 0, 0, 0, 0, 63163), -- Saving Private Spindle
(85664, 5, 1, 1, 0, 0, 0, 0, 0, 63163), -- Delver's Call: Nightfall Sanctum
(84789, 1, 1, 0, 0, 0, 500, 0, 0, 62876), -- Lorewalking: The Blade's Downfall
(84784, 1, 1, 0, 0, 0, 500, 0, 0, 62876), -- Lorewalking: The Blade's Nemeses
(85871, 1, 1, 0, 0, 0, 500, 0, 0, 62876), -- Lorewalking: The Blade's Forces
(84782, 1, 1, 0, 0, 0, 500, 0, 0, 62876), -- Lorewalking: The Blade's Past
(53763, 6, 1, 0, 0, 0, 0, 0, 0, 62876), -- Twist the Knife
(53762, 6, 1, 0, 0, 0, 0, 0, 0, 62876), -- The Tempest Crown
(53761, 1, 6, 0, 0, 0, 0, 0, 0, 62876), -- The Pirate's Treasure
(54058, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Unintended Consequences
(54118, 0, 0, 0, 0, 0, 0, 0, 0, 62876), -- Every Little Death Helps
(84779, 1, 1, 0, 0, 0, 500, 0, 0, 62876), -- Lorewalking: The Blade's Gambit
(89332, 5, 0, 0, 0, 0, 0, 0, 0, 62876), -- Boot Camp
(89331, 5, 0, 0, 0, 0, 0, 0, 0, 62876), -- Flame Fortification
(80184, 1, 1, 0, 0, 0, 0, 0, 0, 62876), -- Preserving in Battle
(80189, 1, 1, 0, 0, 0, 0, 0, 0, 62876), -- Preserving Teamwork
(84490, 1, 0, 0, 0, 0, 0, 0, 0, 62876); -- The Great Vault

UPDATE `quest_details` SET `VerifiedBuild`=63305 WHERE `ID`=42017;
UPDATE `quest_details` SET `VerifiedBuild`=63163 WHERE `ID` IN (84638, 82679, 81990, 83771);
UPDATE `quest_details` SET `VerifiedBuild`=62876 WHERE `ID` IN (91031, 40710, 85005, 83275, 91030, 85648, 83758, 91026, 83759, 91009, 86363, 88803, 90719, 87336, 87335, 87332);

DELETE FROM `quest_request_items` WHERE `ID` IN (91089 /*Defeating Ky'veza*/, 83495 /*Warbands: Twinsposition*/, 82678 /*Archives: The First Disc*/, 84784 /*Lorewalking: The Blade's Nemeses*/, 89332 /*Boot Camp*/, 84371 /*Lorewalking: The Blade and the High Priest*/, 54058 /*Unintended Consequences*/, 53762 /*The Tempest Crown*/, 53761 /*The Pirate's Treasure*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(91089, 0, 0, 0, 0, '', 62876), -- Defeating Ky'veza
(83495, 0, 603, 0, 0, 'Werft den Schalter herum!', 62876), -- Warbands: Twinsposition
(82678, 0, 0, 0, 0, 'Habt Ihr vielleicht etwas gefunden?', 0), -- Archives: The First Disc
(84784, 0, 0, 0, 0, 'Verschwendet nicht die Zeit von Lord N\'Zoth.', 62876), -- Lorewalking: The Blade's Nemeses
(89332, 0, 1, 0, 0, 'Jeder Schlag, den wir den restlichen Sureki versetzen können, schwächt sie in Heilsturz. Bitte beeilt Euch!', 62876), -- Boot Camp
(84371, 0, 0, 0, 0, 'Xal\'atath war eine wahrlich rätselhafte Kreatur. Ich frage mich, ob der Hohepriester sich je ausgemalt hat, wie weit sie gehen würde...', 62876), -- Lorewalking: The Blade and the High Priest
(54058, 1, 0, 0, 0, 'So eine Abwechslung kann ganz belebend sein, oder, $n?', 0), -- Unintended Consequences
(53762, 1, 1, 0, 0, 'Die Krone ist in unseren Händen viel nützlicher als in den Klauen eines übergroßen Siltfressers.', 62876), -- The Tempest Crown
(53761, 1, 1, 0, 0, 'Befindet sich der Dreizack in Eurem Besitz?', 62876); -- The Pirate's Treasure

UPDATE `quest_request_items` SET `CompletionText`='Diese Karte ergibt keinen Sinn... Champion! Ich hoffe, es gibt gute Nachrichten?' WHERE `ID`=84370;

DELETE FROM `quest_description_conditional` WHERE (`QuestId`=91138 AND `PlayerConditionId`=140702 AND `QuestgiverCreatureId`=245915 AND `locale`='deDE') OR (`QuestId`=90705 AND `PlayerConditionId`=20069 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=82680 AND `PlayerConditionId`=125262 AND `QuestgiverCreatureId`=224394 AND `locale`='deDE') OR (`QuestId`=83247 AND `PlayerConditionId`=124163 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=82340 AND `PlayerConditionId`=124295 AND `QuestgiverCreatureId`=223723 AND `locale`='deDE') OR (`QuestId`=80176 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=219135 AND `locale`='deDE') OR (`QuestId`=80175 AND `PlayerConditionId`=41725 AND `QuestgiverCreatureId`=215335 AND `locale`='deDE') OR (`QuestId`=83770 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=211721 AND `locale`='deDE') OR (`QuestId`=83755 AND `PlayerConditionId`=125358 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=83761 AND `PlayerConditionId`=125358 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=78177 AND `PlayerConditionId`=44108 AND `QuestgiverCreatureId`=212162 AND `locale`='deDE') OR (`QuestId`=75890 AND `PlayerConditionId`=110815 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=85879 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=237659 AND `locale`='deDE');
INSERT INTO `quest_description_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(91138, 140702, 245915, 'deDE', 'Was für ein winziges Teilchen. Und bar jeder Macht, die T\'uure einst nährte. Aber trotzdem ein unschätzbar wertvolles Relikt.\n\nWie Ihr ja wisst, hat dieser Naaru als Hüter von T\'uures Vermächtnis Dunkelheit und Licht lediglich als Aspekte einer größeren Wahrheit betrachtet.\n\nWas die Kraft zur Schöpfung besitzt, kann diese ebenso zur Zerstörung einsetzen. Demonstriert diese Lektion, dann werdet Ihr Euch selbst besser verstehen sowie den großen Naaru, dessen Opfer der Vernichtung eines gesamten Planeten Einhalt gebot.', 0, 62876), -- I am the Creator and Destroyer
(90705, 20069, 0, 'deDE', 'Interessiert Ihr euch für die Geschichte Eurer Welt? Würdet Ihr gern mehr erfahren?\n\nLehrensucher Cho ist herumgereist, um Geschichten von wichtigen historischen Ereignissen und Figuren aus Azeroth und darüber hinaus zusammenzutragen. Besucht ihn doch mal in Eurer Hauptstadt. Er teilt sicher gern eine Erzählung aus der Vergangenheit mit Euch.\n\nOder sogar mehr als eine! Er plaudert wirklich gern.\n\nSagt ihm, dass Assistentin Lali Euch schickt.', 0, 62876), -- Lorewalking
(82680, 125262, 224394, 'deDE', 'Hallo! Da seid Ihr ja wieder, $n.\n\nSchade, ich habe leider keine Elementare für Euch, um Euch in Form zu bringen...\n\nAber ich möchte Euch um einen anderen Gefallen bitten, wenn Ihr mögt.\n\nEin Freund von mir, Olbarig, lebt auf den Drei Schilden. Er erforscht dort die wilden Wolkenkrähen, und wir reden ab und zu über sie.\n\nAber ich habe schon lange nichts mehr von ihm gehört. Würdet Ihr für mich nach ihm sehen?', 0, 62876), -- Birdman of the Three Shields
(83247, 124163, 0, 'deDE', 'Das Reich der Arathi beruht auf dem Glauben an den Kaiser und das Licht. Wenn mein Ältester jemals sehen würde, was Ihr treibt, würde er mich auffordern, Euch auf der Stelle niederzuschlagen.\n\nAber meine bessere Hälfte würde mich auffordern, offener zu sein. Wir müssen uns aufeinander verlassen, um hier zu überleben.\n\n Ich will eine bessere Version meiner selbst sein. Für sie.\n\nEinige der Salamanther in Schmuggelstieg haben uns geplagt. Tötet sie und bringt mir einen Beweis für ihren Tod.', 0, 62876), -- Suspicious Minds
(82340, 124295, 223723, 'deDE', 'Fröhliche Grüße! Es ist so schön, Euch wiederzusehen, $n. Dies ist meine Teestube, die ich auch als Behandlungszimmer nutze. Ein sicherer Ort für jeden!\n\nIhr habt Ralph schon einmal geholfen, und ich frage mich, ob Ihr auch noch einem meiner Patienten helfen würdet. Vi\'azl hat eine Todesangst vor Kreaturen mit weniger Gliedmaßen als üblich. Ich glaube, diese Angst hat sich zu einer krankhaften Phobie gegen Verstümmelung entwickelt. Ich versuche, diesem Phänomen auf den Grund zu gehen.\n\nWärt Ihr bereit, mit ihm zu sprechen und ihm zu beweisen, dass man sich vor Euch, einer Person mit weniger als acht Beinen, nicht fürchten muss?', 0, 62876), -- Loss of Limb
(80176, 41725, 219135, 'deDE', 'Ich habe es fast! Und als $uMagierkollege:Magierkollegin; seid Ihr genau $uder:die; Richtige, um mir zu helfen!\n\nIch erschaffe eine neue Art Teleportationszauber, damit wir zurück zum Reich kommen.\n\nIch glaube, diese Krabben könnten der Schlüssel sein. Sie verströmen pure arkane Teleportationsmagie!\n\nWir brauchen weitere Proben, die ich studieren kann.\n\nNehmt diesen Fokus. Mit dem könnt Ihr arkane Spuren sehen. Es gibt hier nicht viele andere arkane Quellen, also sollten Euch sämtliche Spuren direkt zu den betroffenen Krabben führen!', 0, 62876), -- Arcane Trickles
(80175, 41725, 215335, 'deDE', 'Ich möchte Euch bitten, nach jemandem zu sehen. Er ist ein Magier... der einzige in unseren Reihen. Alle anderen sind beim Absturz gestorben.\n\nEr versucht, ein Portal nach Hause ins Reich zu erschaffen, damit wir Verstärkung bekommen und einen Weg dorthin und zurück haben.\n\nWir wissen alle, dass es ein vergebliches Unterfangen ist, aber er will einfach nicht aufgeben.\n\nVielleicht würde ihm ein Gespräch mit $geinem erfahrenen Magier:einer erfahrenen Magierin; die Augen vor der Realität öffnen. Würdet Ihr ihm ins Gewissen reden?', 0, 62876), -- The Last Mage
(83770, 0, 211721, 'deDE', 'Viele von uns Überlebenden haben Geschichten über das Spiralgewebe gehört. Es scheint ein Ort zu sein, an dem die Neruber große Militäroperationen durchführen.\n\nDen Kampf zu ihnen zu bringen, könnte die Kriegspläne der Neruber ernsthaft durchkreuzen.', 0, 63163), -- Delver's Call: Spiral Weave
(83755, 125358, 0, 'deDE', 'Schön, Euch wiederzusehen! Ich habe versucht, unseren Freund \"Zekvir\" aufzuspüren.\n\nDiese Leute vom Orden der Nacht haben vielleicht Informationen über Zekvir.\n\nGehen wir zu diesem Nachtsturzsanktum und sehen, was wir herausfinden können.', 0, 63163), -- Delves: Nightfall Sanctum
(83761, 125358, 0, 'deDE', 'Wer hätte gedacht, dass ich es mir in der Höhle eines Nerubers gemütlich machen würde!\n\nDie Weberin hat mir einen Tipp gegeben, wie wir mehr über diesen Zekvir in Erfahrung bringen können.\n\nAnscheinend gibt es einen Ort, der Tiefenfestung genannt wird, wo es Aufzeichnungen über ihn geben könnte. \n\nLasst uns dort nachsehen, was wir finden können!', 0, 63163), -- Delves: The Underkeep
(78177, 44108, 212162, 'deDE', '$n, die Zeit ist endlich gekommen, nach Hause zurückzukehren. Die Verlassenen haben dem Land wie versprochen den Rücken gekehrt.\n\nLeider haben die Kämpfer des Scharlachroten Kreuzzugs ihren Abzug ausgenutzt und die Stadt zu ihrer eigenen Festung auserkoren. Wir werden sie alle vertreiben.\n\nStatten wir ihnen einen Besuch ab und zeigen wir ihnen, was es heißt, es sich mit einem Gilneer zu verscherzen.', 0, 63305), -- To Gilneas
(75890, 110815, 0, 'deDE', '<Eine elegante Handschrift füllt die Schriftrolle.>\n\n$n,\n\nes ist lange her, seit wir das letzte Mal sprachen. Ich wäre nicht hier, hättet Ihr mir vor langer Zeit nicht in Jaedenar geholfen, und ich habe Euch nicht vergessen.\n\nWie es scheint, wird Eure Stärke erneut in der Schattenfeste benötigt: die Wächterinnen brauchen Euch.\n\nTrefft mich bei der Botschaft von Sturmwind. Tyrande hat die Wächterinnen zum Handeln aufgerufen, und Eure Hilfe wäre sehr willkommen.\n\nArko\'narin Sternschatten', 0, 63163), -- The Clarion Call
(85879, 0, 237659, 'deDE', 'Riecht Ihr das? Das ist der Geruch des Profits, den wir machen werden... und jeder Menge biologisch gefährlicher Abfallprodukte, aber hey, wo ist der Unterschied?\n\nWenn Ihr beim Müll schaufeln Kohle scheffeln wollt, dann sucht mich draußen auf. Macht nichts aus, wenn der Job bereits gestartet starten hat. Solange Ihr Euch beteiligt, erhaltet Ihr Euren Anteil.', 0, 63163); -- Reduce, Reuse, Resell

DELETE FROM `quest_completion_log_conditional` WHERE (`QuestId`=74381 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=40710 AND `PlayerConditionId`=128374 AND `QuestgiverCreatureId`=231891 AND `locale`='deDE') OR (`QuestId`=83140 AND `PlayerConditionId`=125495 AND `QuestgiverCreatureId`=225587 AND `locale`='deDE') OR (`QuestId`=90705 AND `PlayerConditionId`=20069 AND `QuestgiverCreatureId`=0 AND `locale`='deDE') OR (`QuestId`=84645 AND `PlayerConditionId`=132845 AND `QuestgiverCreatureId`=229951 AND `locale`='deDE') OR (`QuestId`=84643 AND `PlayerConditionId`=132845 AND `QuestgiverCreatureId`=229951 AND `locale`='deDE');
INSERT INTO `quest_completion_log_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(74381, 0, 0, 'deDE', '', 0, 63305), -- Hidden Legacies
(40710, 128374, 231891, 'deDE', 'Verwendet die Fähigkeit \"Sprecht mit Lehrensucher Cho\", um fortzufahren.', 0, 62876), -- Blade in Twilight
(83140, 125495, 225587, 'deDE', 'Trefft Euch mit Gazlowe im nordwestlichen Lager der Venture Company.', 0, 63163), -- Hostile Work Environment
(90705, 20069, 0, 'deDE', 'Sucht Lehrensucher Cho in Dornogal oder Orgrimmar auf.', 0, 62876), -- Lorewalking
(84645, 132845, 229951, 'deDE', 'Trefft Hauptmann Roderick Bräustein in der Kaserne von Stromgarde.', 0, 63163), -- Deputy Delivery
(84643, 132845, 229951, 'deDE', 'Trefft Hauptmann Roderick Bräustein in der Kaserne von Stromgarde.', 0, 63163); -- Curfew Kerfuffle

DELETE FROM `quest_offer_reward_conditional` WHERE (`QuestId`=87475 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=241344 AND `locale`='deDE') OR (`QuestId`=87477 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=241340 AND `locale`='deDE') OR (`QuestId`=87480 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=241093 AND `locale`='deDE') OR (`QuestId`=88916 AND `PlayerConditionId`=0 AND `QuestgiverCreatureId`=241100 AND `locale`='deDE') OR (`QuestId`=53763 AND `PlayerConditionId`=128374 AND `QuestgiverCreatureId`=231891 AND `locale`='deDE') OR (`QuestId`=53763 AND `PlayerConditionId`=128374 AND `QuestgiverCreatureId`=228832 AND `locale`='deDE') OR (`QuestId`=40710 AND `PlayerConditionId`=128374 AND `QuestgiverCreatureId`=231891 AND `locale`='deDE');
INSERT INTO `quest_offer_reward_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(87475, 0, 241344, 'deDE', 'Exzellente Arbeit, $n. Unsere Verstärkung wird von hier an übernehmen.\n\nMyltons Berichte wiesen auf eine weitaus größere Streitmacht westlich der Ehrengründe hin, daher müssen wir wachsam bleiben und diese Mauern halten.\n\nMöge die Heilige Flamme Eure Klinge lenken.', 0, 63305), -- Sureki Incursion: Hold the Wall
(87477, 0, 241340, 'deDE', 'Lady Faerin hatte recht mit Euch, $n. Wir schulden Euch Dank.\n\nIhr habt Tenirs Aufstieg und Beledars Schatz wertvolle Zeit verschafft.\n\nAb hier übernehmen wir.', 0, 63305), -- Sureki Incursion: Southern Swarm
(87480, 0, 241093, 'deDE', 'Die Bewohner von Dunelles Güte danken Euch, $n.\n\nWir werden Lothars Landung gemeinsam mit unseren Verbündeten bei den Irdenen halten und die Stadt darunter befestigen.\n\nMöge das Licht der Heiligen Flamme stets mit Euch sein.', 0, 63305), -- Sureki Incursion: The Eastern Assault
(88916, 0, 241100, 'deDE', 'Viele Lampenanzünder und Soldaten haben ihr Leben auf dem Friedhof verloren, den sie \"Ende der Arathi\" nennen.\n\nIm Namen derer, die in der Dunkelheit verschollen sind, und jener, die hier an der Front kämpfen, danke ich Euch.', 0, 63163), -- Radiant Incursion: Sureki's End
(53763, 128374, 231891, 'deDE', 'N\'Zoths Gabe war eine dunkle, wohl wahr.', 1, 62876), -- Twist the Knife
(53763, 128374, 228832, 'deDE', 'N\'Zoths Gabe war eine dunkle, wohl wahr.', 0, 62876), -- Twist the Knife
(40710, 128374, 231891, 'deDE', 'Zu diesem Zeitpunkt führte der Hohepriester seinen Kampf gegen die Legion fort, zusammen mit Xal\'atath an seiner Seite.', 0, 62876); -- Blade in Twilight

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=2215 AND `QuestLineId` IN (5652,5648,5596)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5654,5653,5651,5649,5648,5647,5646,5644,5634,5628,5620,5619,5618,5613,5612,5610,5607,5603,5601,5600,5591,5574,5565,5562,5559,5552,5543,5542,5541,5532,5527,5524,5522,5512,5509)) OR (`UIMapId`=627 AND `QuestLineId` IN (222,87,86)) OR (`UIMapId`=750 AND `QuestLineId` IN (932,377,307,145)) OR (`UIMapId`=652 AND `QuestLineId` IN (932,377,145)) OR (`UIMapId`=630 AND `QuestLineId` IN (5638,222,87,86)) OR (`UIMapId`=10 AND `QuestLineId` IN (5638,1267,1108,811,550)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5652,5648,5596)) OR (`UIMapId`=2085 AND `QuestLineId` IN (5570,1323)) OR (`UIMapId`=95 AND `QuestLineId` IN (5697,811)) OR (`UIMapId`=2381 AND `QuestLineId`=5673) OR (`UIMapId`=862 AND `QuestLineId`=618) OR (`UIMapId`=20 AND `QuestLineId`=1377) OR (`UIMapId`=2269 AND `QuestLineId`=5666) OR (`UIMapId`=2404 AND `QuestLineId` IN (1129,533,346));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(2215, 5652, 63305),
(2215, 5648, 63305),
(2215, 5596, 63305),
(2371, 5654, 63305),
(2371, 5653, 63305),
(2371, 5651, 63305),
(2371, 5649, 63305),
(2371, 5648, 63305),
(2371, 5647, 63305),
(2371, 5646, 63305),
(2371, 5644, 63305),
(2371, 5634, 63305),
(2371, 5628, 63305),
(2371, 5620, 63305),
(2371, 5619, 63305),
(2371, 5618, 63305),
(2371, 5613, 63305),
(2371, 5612, 63305),
(2371, 5610, 63305),
(2371, 5607, 63305),
(2371, 5603, 63305),
(2371, 5601, 63305),
(2371, 5600, 63305),
(2371, 5591, 63305),
(2371, 5574, 63305),
(2371, 5565, 63305),
(2371, 5562, 63305),
(2371, 5559, 63305),
(2371, 5552, 63305),
(2371, 5543, 63305),
(2371, 5542, 63305),
(2371, 5541, 63305),
(2371, 5532, 63305),
(2371, 5527, 63305),
(2371, 5524, 63305),
(2371, 5522, 63305),
(2371, 5512, 63305),
(2371, 5509, 63305),
(627, 222, 63305),
(627, 87, 63305),
(627, 86, 63305),
(750, 932, 63305),
(750, 377, 63305),
(750, 307, 63305),
(750, 145, 63305),
(652, 932, 63305),
(652, 377, 63305),
(652, 145, 63305),
(630, 5638, 63305),
(630, 222, 63305),
(630, 87, 63305),
(630, 86, 63305),
(10, 5638, 63305),
(10, 1267, 63305),
(10, 1108, 63305),
(10, 811, 63305),
(10, 550, 63305),
(2214, 5652, 62876),
(2214, 5648, 62876),
(2214, 5596, 62876),
(2085, 5570, 63305),
(2085, 1323, 63305),
(95, 5697, 63305),
(95, 811, 63305),
(2381, 5673, 62876),
(862, 618, 62876),
(20, 1377, 62876),
(2269, 5666, 62876),
(2404, 1129, 62876),
(2404, 533, 62876),
(2404, 346, 62876);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63305 WHERE (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5711,5697,5694,5691,5686,5685,5684,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5651,5647,5644,5642,5641,5638,5634,5631,5630,5628,5627,5626,5624,5622,5621,5620,5619,5617,5615,5614,5611,5610,5609,5608,5607,5606,5605,5603,5602,5601,5600,5598,5597,5593,5591,5590,5574,5572,5565,5563,5562,5559,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416)) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=85 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5538,5519,5513,5504,5482,5459,5389,5387,1311,1295,1289,1267,1129,1108,1107,1003,973,919,811,802,796,780,636,612,550,546,539,516,377,300,290,263,261,260,531)) OR (`UIMapId`=627 AND `QuestLineId` IN (346,313,312,311,310,304,296,293,275,236,295)) OR (`UIMapId`=680 AND `QuestLineId` IN (5691,5673,5519,5385,5375,923,912,906,805,796,788,787,377,343,342,341,340,339,332,330,328,325,324,321,316,315,310,306,292,288,287,286,285,284,283,282,280,279,276,253,252,251,249,247,238,236,231,225,211,206,205,204,203,202,201,200,191,190,189,188,185,184,182,181,179,177,176,175,158,156,155,154,153,152,148,138,137,135,134,133,132,97,96,95,94,82)) OR (`UIMapId`=650 AND `QuestLineId` IN (5385,5375,932,923,912,805,790,377,343,342,339,333,329,325,323,321,315,310,308,307,304,296,294,280,253,251,247,238,236,211,206,205,203,192,191,190,189,188,187,186,185,184,182,181,179,178,177,176,175,148,146,145,144,143,138,137,135,134,133,132,130,127,97,96,95,94,93,89)) OR (`UIMapId`=634 AND `QuestLineId` IN (5691,5673,5519,5385,5375,932,923,912,805,796,787,377,343,342,341,339,333,329,325,323,321,315,310,307,305,294,292,288,287,286,285,284,283,282,280,279,252,251,249,247,238,211,206,205,204,203,202,201,200,182,181,179,178,177,176,175,158,156,155,154,153,152,148,146,145,144,143,138,137,135,134,133,132,130,127,97,96,95,94,93,89)) OR (`UIMapId`=630 AND `QuestLineId` IN (5519,5513,1251,1247,1246,1234,796,364,359,346,340,336,333,332,331,330,329,328,327,326,325,324,323,322,321,319,316,313,312,311,310,309,306,304,303,302,297,296,294,293,292,291,288,287,286,285,284,283,282,280,279,278,276,275,257,256,255,254,253,252,251,250,249,247,238,236,227,226,225,221,211,206,205,204,203,202,201,200,186,182,181,180,179,178,177,176,175,158,156,155,154,153,152,144,130,97,96,95,94,82,295)) OR (`UIMapId`=10 AND `QuestLineId` IN (5593,5538,5519,5513,5504,5499,5459,5430,5389,5387,5382,1311,1295,1289,1227,1129,1107,1003,973,931,919,805,802,796,780,636,612,584,564,563,546,539,531,526,519,518,516,509,377,376,346,300,290,263,261,260,231,130)) OR (`UIMapId`=199 AND `QuestLineId` IN (5504,5499,5430,5407,5389,1400,1227,1129,931,873,734,612,584,564,563,526,525,521,520,519,518,509,377,290,231)) OR (`UIMapId`=88 AND `QuestLineId` IN (5389,931,612,564,526,377,231)) OR (`UIMapId`=7 AND `QuestLineId` IN (5407,5389,1129,931,612,564,526,525,520,519,518,509,377,290,231)) OR (`UIMapId`=71 AND `QuestLineId` IN (5386,5377,1029,1016,1012,950,906,780,545,534,521,512,511,291,290,289,176)) OR (`UIMapId`=2025 AND `QuestLineId` IN (5570,5569,5568,5538,5511,5476,5467,5462,5455,5397,5394,5381,5368,5354,1413,1404,1398,1397,1396,1395,1394,1393,1392,1377,1376,1375,1374,1368,1367,1364,1362,1333,1331,1325,1324,1323,1310,1308,1306,1305,1304,1303,1302,1301,1300,1299,1289,926)) OR (`UIMapId`=2112 AND `QuestLineId` IN (5570,5538,5511,5476,5455,5381,5368,5354,1413,1398,1397,1395,1392,1375,1374,1368,1367,1362,1333,1331,1325,1324,1310,1308)) OR (`UIMapId`=95 AND `QuestLineId` IN (1216,569,444));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63163 WHERE (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5711,5697,5694,5691,5686,5685,5684,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5651,5647,5644,5642,5641,5638,5634,5631,5630,5628,5627,5626,5624,5622,5621,5620,5619,5617,5615,5614,5611,5610,5609,5608,5607,5606,5605,5603,5602,5601,5600,5598,5597,5593,5591,5590,5574,5572,5565,5563,5562,5559,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416)) OR (`UIMapId`=2248 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5606,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2016 AND `QuestLineId`=1235) OR (`UIMapId`=2339 AND `QuestLineId` IN (5799,5732,5716,5697,5691,5690,5684,5673,5664,5630,5617,5605,5572,5551,5550,5544,5540,5539,5533,5531,5525,5523,5513,1416)) OR (`UIMapId`=1525 AND `QuestLineId` IN (5691,1257,1252,1247,1245,1241,1235,1223,1221,1220,1211,1210,1204,1196,1193,1192,1191,1190,1185,1184,1183,1182,1181,1180,1178,1177,1172,1147,1145,1144,1143,1142,1141,1137,1121,1092,1069,1065,1041,1040,1039,1038,1026,1024,1018,1017,1005,998,996,995,994,985)) OR (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5906,5900,5803,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5717,5716,5715,5705,5703,5699,5696,5695,5694,5693,5690,5686,5685,5683,5672,5669,5668,5666,5663,5662,5661,5660,5659,5655,5653,5651,5649,5648,5647,5646,5644,5642,5641,5634,5631,5630,5623,5622,5618,5617,5615,5614,5613,5612,5611,5607,5601,5600,5598,5593,5591,5574,5565,5562,5559,5558,5552,5551,5550,5545,5544,5543,5542,5541,5534,5531,5530,5529,5526,5525,5524,5523,5521,5520,5512,5506)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5715,5711,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5678,5673,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5651,5647,5646,5642,5641,5638,5634,5631,5630,5628,5627,5626,5625,5624,5623,5622,5621,5620,5619,5617,5615,5614,5611,5609,5608,5606,5605,5603,5602,5601,5600,5598,5597,5593,5591,5590,5574,5572,5565,5563,5562,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=62876 WHERE (`UIMapId`=2371 AND `QuestLineId` IN (5953,5906,5900,5803,5799,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5732,5717,5716,5715,5711,5705,5703,5699,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5683,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5642,5641,5638,5631,5630,5627,5617,5615,5614,5609,5605,5602,5598,5597,5593,5572,5563,5558,5551,5550,5544,5540,5539,5535,5534,5533,5531,5530,5529,5526,5525,5523,5521,5520,5513,5506,1416)) OR (`UIMapId`=2472 AND `QuestLineId` IN (5780,5703,5699,5695,5690)) OR (`UIMapId`=2346 AND `QuestLineId` IN (5900,5776,5772,5741,5694,5686,5685,5669,5668,5663,5662,5661,5660,5659,5642,5641,5631,5615,5614)) OR (`UIMapId`=2214 AND `QuestLineId` IN (5900,5803,5799,5791,5782,5780,5779,5776,5772,5763,5744,5742,5741,5736,5734,5733,5732,5717,5716,5711,5705,5697,5696,5695,5694,5693,5691,5690,5686,5685,5684,5678,5673,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5651,5647,5646,5642,5641,5638,5634,5631,5630,5628,5627,5626,5625,5624,5623,5622,5621,5620,5619,5617,5615,5614,5611,5609,5608,5606,5605,5603,5602,5601,5600,5598,5597,5593,5591,5590,5574,5572,5565,5563,5562,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416,5710,5903)) OR (`UIMapId`=2215 AND `QuestLineId` IN (5900,5799,5776,5772,5741,5732,5716,5711,5697,5694,5691,5686,5685,5684,5673,5672,5671,5670,5669,5668,5666,5664,5663,5662,5661,5660,5659,5655,5654,5653,5651,5647,5644,5642,5641,5638,5634,5631,5630,5628,5627,5626,5624,5622,5621,5620,5619,5617,5615,5614,5611,5610,5609,5608,5607,5606,5605,5603,5602,5601,5600,5598,5597,5593,5591,5590,5574,5572,5565,5563,5562,5559,5558,5552,5551,5550,5544,5542,5540,5539,5535,5534,5533,5532,5531,5530,5529,5527,5526,5525,5524,5523,5522,5521,5520,5513,5512,5509,5506,1416,5903,5710)) OR (`UIMapId`=2255 AND `QuestLineId` IN (5906,5900,5803,5791,5782,5780,5779,5776,5772,5770,5763,5744,5742,5741,5735,5734,5733,5717,5716,5715,5705,5703,5699,5696,5695,5694,5693,5690,5686,5685,5683,5672,5669,5668,5666,5663,5662,5661,5660,5659,5655,5653,5651,5649,5648,5647,5646,5644,5642,5641,5634,5631,5630,5623,5622,5618,5617,5615,5614,5613,5612,5611,5607,5601,5600,5598,5593,5591,5574,5565,5562,5559,5558,5552,5551,5550,5545,5544,5543,5542,5541,5534,5531,5530,5529,5526,5525,5524,5523,5521,5520,5512,5506,5903)) OR (`UIMapId`=2367 AND `QuestLineId` IN (5551,5523)) OR (`UIMapId`=862 AND `QuestLineId` IN (5424,5423,5421,5409,5403,5402,5401,5400,941,919,900,880,868,864,805,796,795,780,779,757,735,734,630,611,609,608,607,606,605,596,595,594,527,524,373,349,338,334,320)) OR (`UIMapId`=2248 AND `QuestLineId`=5903) OR (`UIMapId`=2250 AND `QuestLineId`=5666) OR (`UIMapId`=2404 AND `QuestLineId` IN (5697,5691,5673,5638,5593,5519,5513,5511,5482,5382,5377,1289,1276,1267,1108,1030,957,926,858,576,546,539,526,300,289,262,240));

DELETE FROM `ui_map_quest` WHERE (`UIMapId`=2215 AND `QuestId` IN (79232,86610,82448,82552,84241)) OR (`UIMapId`=2371 AND `QuestId` IN (79232,83930,84241,81750,83529,83079)) OR (`UIMapId`=2248 AND `QuestId`=84241) OR (`UIMapId`=2214 AND `QuestId` IN (79232,84241)) OR (`UIMapId`=2255 AND `QuestId`=82448);
INSERT INTO `ui_map_quest` (`UIMapId`, `QuestId`, `VerifiedBuild`) VALUES
(2215, 79232, 63305), -- Those Who Fell
(2371, 79232, 63305), -- Those Who Fell
(2371, 83930, 63305), -- Deworming Solution
(2215, 86610, 63163), -- Nor Void of Night
(2215, 82448, 63163), -- Book It to the Library
(2215, 82552, 63163), -- All Worked Up
(2371, 84241, 62876), -- Shoreline Stand
(2248, 84241, 62876), -- Shoreline Stand
(2214, 79232, 62876), -- Those Who Fell
(2214, 84241, 62876), -- Shoreline Stand
(2215, 84241, 62876), -- Shoreline Stand
(2371, 81750, 63305), -- Cloud Farming
(2255, 82448, 63163), -- Book It to the Library
(2371, 83529, 63163), -- Hallowfall Fishing Derby
(2371, 83079, 63163); -- Mineral Buildup

UPDATE `ui_map_quest` SET `VerifiedBuild`=63305 WHERE (`UIMapId`=2215 AND `QuestId` IN (84680,84248,82470,83537,83028,82523,83930,82288,82778,81750)) OR (`UIMapId`=2339 AND `QuestId`=82470) OR (`UIMapId`=2248 AND `QuestId` IN (84680,84248,82470,83537,83028,82523,83930,82288)) OR (`UIMapId`=2371 AND `QuestId` IN (84680,84248,82470,83537,83028,82523,82288,82778));
UPDATE `ui_map_quest` SET `VerifiedBuild`=63163 WHERE (`UIMapId`=2215 AND `QuestId` IN (84680,84248,81750,82519,81767,82256,84001,83827,81854,84429,81656,81620,83529)) OR (`UIMapId`=2248 AND `QuestId` IN (84680,84248,86707,82448,81854,84429,81656,81620,83529,83079)) OR (`UIMapId`=2339 AND `QuestId` IN (82448,81854)) OR (`UIMapId`=2371 AND `QuestId` IN (84001,83827,82448,84429,81656,81620,82519,81767)) OR (`UIMapId`=2255 AND `QuestId` IN (86610,81854,82552,82519,81767,82256,84429,81656,81620,83529)) OR (`UIMapId`=2214 AND `QuestId` IN (84001,83827,82448,81854,84429,82552,81656,81620));
UPDATE `ui_map_quest` SET `VerifiedBuild`=62876 WHERE (`UIMapId`=2371 AND `QuestId` IN (83028,82258)) OR (`UIMapId`=2248 AND `QuestId`=82258) OR (`UIMapId`=2214 AND `QuestId` IN (83028,82552,81656,82258,81620,81854)) OR (`UIMapId`=2215 AND `QuestId` IN (81854,83028,81656,83532)) OR (`UIMapId`=2255 AND `QuestId` IN (81854,83028,82552,81656,83532));

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2802127 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733232 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733224 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733295 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733296 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733294 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733293 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733417 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733415 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733418 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733206 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733205 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733242 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733240 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733222 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733221 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733219 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2733220 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778316 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2735114 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2791476 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2791475 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2791473 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2735125 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2791493 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2779561 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778348 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778349 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2791489 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778182 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2777565 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778345 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778344 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778346 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778347 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2779290 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778341 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2778308 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2735122 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2735123 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2774083 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2728962 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773255 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2771858 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2729262 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2771859 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2729254 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773980 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2729260 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2729261 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2728960 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773800 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773951 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773207 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2728958 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2773785 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2729183 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2771856 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2840256 /*Map: 2738 (K'aresh) - Phase: 0*/, 2840250 /*Map: 2951 (Voidrazor Sanctuary) - Phase: 0*/, 2680734 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680750 /*Map: 2738 (K'aresh) - Phase: 0*/, 2680753 /*Map: 2738 (K'aresh) - Phase: 0*/, 2597233 /*Map: 2738 (K'aresh) - Phase: 0*/, 2597234 /*Map: 2738 (K'aresh) - Phase: 0*/, 2597224 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692197 /*Map: 2738 (K'aresh) - Phase: 0*/, 2692196 /*Map: 2738 (K'aresh) - Phase: 0*/, 2597225 /*Map: 2738 (K'aresh) - Phase: 0*/, 2597232 /*Map: 2738 (K'aresh) - Phase: 0*/, 2713735 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2713736 /*Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)*/, 2827946 /*Map: 2552 (Khaz Algar (Surface)) - Phase: 0*/, 2519853 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2519846 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523113 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2562663 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523110 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523111 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523075 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2570006 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523076 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2562665 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523079 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523071 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523069 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2570067 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523081 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523067 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2569870 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523112 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523066 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523078 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523077 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2570615 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523074 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523073 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2570070 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523070 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2523064 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2570005 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2769145 /*Map: 2738 (K'aresh) - Phase: 0*/, 2792163 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792162 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792159 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792160 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2792161 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2791088 /*Map: 2738 (K'aresh) - Phase: 26414*/, 2395266 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2395129 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2395130 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2420464 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2420666 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2535215 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2420662 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2420665 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2420660 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2395267 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2395235 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784694 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784693 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2801505 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784743 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2801576 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784718 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784717 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2784720 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2780380 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2780306 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2780378 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2744135 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2728957 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2744136 /*Map: 2601 (Khaz Algar) - Phase: 0*/, 2579974 /*Map: 2801 (Ny'alotha, the Waking City) - Phase: 0*/, 2600910 /*Map: 0 (Eastern Kingdoms) - Phase: 0*/, 2579767 /*Map: 2801 (Ny'alotha, the Waking City) - Phase: 2605 (Cosmetic - NEVER)*/, 2579784 /*Map: 2801 (Ny'alotha, the Waking City) - Phase: 2605 (Cosmetic - NEVER)*/, 1674814 /*Map: 1643 (Kul Tiras) - Phase: 12633*/, 1688276 /*Map: 1642 (Zandalar) - Phase: 0*/, 1684931 /*Map: 1643 (Kul Tiras) - Phase: 0*/, 2596282 /*Map: 0 (Eastern Kingdoms) - Phase: 0*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2802127, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733232, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733224, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733295, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733296, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733294, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733293, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733417, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733415, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733418, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733206, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733205, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733242, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733240, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733222, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733221, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733219, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2733220, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778316, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2735114, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2791476, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2791475, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2791473, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2735125, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2791493, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2779561, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778348, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778349, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2791489, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778182, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2777565, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778345, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778344, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778346, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778347, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2779290, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778341, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2778308, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2735122, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2735123, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2774083, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2728962, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773255, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2771858, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2729262, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2771859, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2729254, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773980, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2729260, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2729261, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2728960, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773800, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773951, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773207, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2728958, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2773785, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2729183, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2771856, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2840256, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2840250, 2951, 0, 0, 0, 63305), -- Map: 2951 (Voidrazor Sanctuary) - Phase: 0
(2680734, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2680750, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2680753, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2597233, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2597234, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2597224, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2692197, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2692196, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2597225, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2597232, 2738, 0, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 0
(2713735, 2738, 25157, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2713736, 2738, 25157, 0, 0, 62876), -- Map: 2738 (K'aresh) - Phase: 25157 (K'aresh - Untethered Space)
(2827946, 2552, 0, 0, 0, 62876), -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
(2519853, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2519846, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523113, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2562663, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523110, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523111, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523075, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2570006, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523076, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2562665, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523079, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523071, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523069, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2570067, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523081, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523067, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2569870, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523112, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523066, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523078, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523077, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2570615, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523074, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523073, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2570070, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523070, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2523064, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2570005, 2601, 0, 0, 0, 62876), -- Map: 2601 (Khaz Algar) - Phase: 0
(2769145, 2738, 0, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 0
(2792163, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2792162, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2792159, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2792160, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2792161, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2791088, 2738, 26414, 0, 0, 63305), -- Map: 2738 (K'aresh) - Phase: 26414
(2395266, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2395129, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2395130, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2420464, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2420666, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2535215, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2420662, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2420665, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2420660, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2395267, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2395235, 2601, 0, 0, 0, 63305), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784694, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784693, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2801505, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784743, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2801576, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784718, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784717, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2784720, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2780380, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2780306, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2780378, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2744135, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2728957, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2744136, 2601, 0, 0, 0, 63163), -- Map: 2601 (Khaz Algar) - Phase: 0
(2579974, 2801, 0, 0, 0, 62876), -- Map: 2801 (Ny'alotha, the Waking City) - Phase: 0
(2600910, 0, 0, 0, 0, 62876), -- Map: 0 (Eastern Kingdoms) - Phase: 0
(2579767, 2801, 2605, 0, 0, 62876), -- Map: 2801 (Ny'alotha, the Waking City) - Phase: 2605 (Cosmetic - NEVER)
(2579784, 2801, 2605, 0, 0, 62876), -- Map: 2801 (Ny'alotha, the Waking City) - Phase: 2605 (Cosmetic - NEVER)
(1674814, 1643, 12633, 0, 0, 62876), -- Map: 1643 (Kul Tiras) - Phase: 12633
(1688276, 1642, 0, 0, 0, 62876), -- Map: 1642 (Zandalar) - Phase: 0
(1684931, 1643, 0, 0, 0, 62876), -- Map: 1643 (Kul Tiras) - Phase: 0
(2596282, 0, 0, 0, 0, 62876); -- Map: 0 (Eastern Kingdoms) - Phase: 0

UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2771059, 2737295, 2397210, 2678277, 2775279, 1415148, 1415554, 1147030, 1151003, 1351521, 1351792, 1478244, 1478764, 1507741, 2539963, 2540136, 2538346, 2539653, 2674550, 2674549, 2721780, 2347280, 2537241, 2539844, 2528174, 2265375, 2370969, 2361526, 2370952, 2370939, 2341010, 2378883, 2351713, 1328068, 2328843, 2339065, 2323812, 2158408, 1653920, 1654832, 1654831, 1653214, 1655211, 144608, 1409970, 1431565, 1409971, 1409964, 1409969, 1351520, 2224293, 2294862, 2795428, 2792164, 2792165, 2791090, 2791089, 2792158, 2792153, 2392815, 2358746, 2348054, 2348156, 2348127, 2357469, 2418524, 2418523, 2417611, 2421421, 2348241, 2834477, 2834475, 2513682, 2412477, 2415060, 2415057, 2415055);
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1409964, 1409971, 2540136, 2158408, 1653920, 1654832, 1654831, 1409970, 1478244, 1507741, 1409969, 1351520); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1415148, 1649726); -- Map: 530 (Outland) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=994858; -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1145889, 1145890); -- Map: 571 (Northrend) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1022523, 1431813, 1147030); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (1328079, 1306711, 1663963); -- Map: 1642 (Zandalar) - Phase: 0
UPDATE `spawn_tracking_template` SET `MapId`=1, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2675100, 2675101); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2240785, 2349078); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId`=2535890; -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63305 WHERE `SpawnTrackingId` IN (2513682, 2412477, 2415060, 2415057, 2415055); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2537241, 2535890, 2528174, 2539844, 2674550, 2674549, 2721780, 2347280, 2737295, 2771526, 2678920, 2265375, 2370969, 2361526, 2370952, 2370939, 2341010, 2378883, 2351713, 1328068, 2328843, 2339065, 2323812, 1653214, 1655211, 144608, 1431565, 1478764, 2477190, 2834477, 2834475, 2775279, 2678277, 2771059, 2349497, 2779024, 2779041, 2549634, 2353554, 2408551, 2423559, 2440569, 2406561, 2454476, 2452137, 2399830, 2386212, 2394453, 2418988, 2421816, 2408218, 2448084);
UPDATE `spawn_tracking_template` SET `MapId`=1, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2675100, 2675101); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2540136, 2158408, 1653920, 1654832, 1654831, 1409970, 1478244, 1507741, 1409971, 1409964, 1409969, 1351520); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2240785, 2349078); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (2513682, 2412477, 2415060, 2415057, 2415055); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (1663963, 1328079, 1306711); -- Map: 1642 (Zandalar) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId`=1649726; -- Map: 530 (Outland) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (1431813, 1147030); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=63163 WHERE `SpawnTrackingId` IN (1145889, 1145890); -- Map: 571 (Northrend) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2771291, 2786958, 2784580, 2774664, 2713749, 2713734, 2713733, 2674550, 2674549, 2721780, 2567053, 2505658, 2827942, 2867936, 2867940, 2867925, 2867922, 2867944, 2867905, 2775279, 2678277, 2771059, 2265375, 2370969, 2361526, 2370952, 2370939, 2341010, 2378883, 2351713, 1328068, 2328843, 2339065, 2323812, 1653214, 1655211, 144608, 1431565, 1478764, 2834476, 2535890, 2528174, 2470213, 2469495, 2513682, 2412477, 2415060, 2415057, 2415055, 2475980, 2478351, 2478325, 2478254, 2478011, 2478523, 2494921, 2693580, 2693521, 2693582, 2693575, 2693578, 2439892, 2401280, 2523037, 2538294, 1681906, 1681907, 1681908, 1452170, 1682765, 1652868, 1651043, 1651433, 1656856, 1716449, 1685511, 1688277, 1210557, 1205109, 2534227, 2496880, 2549586, 2512633, 2453932, 2721717);
UPDATE `spawn_tracking_template` SET `MapId`=1, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2675100, 2675101); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2540136, 1653920, 1654832, 1654831, 1409970, 1478244, 1507741, 1409971, 1409964, 1409969, 1351520, 2474893); -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2240785, 2349078); -- Map: 2444 (Dragon Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2513682, 2412477, 2415060, 2415057, 2415055, 2513652, 2566037); -- Map: 2601 (Khaz Algar) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0 WHERE `SpawnTrackingId`=2158408;
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1663963, 1328079, 1306711, 1452170, 1681459, 1666378, 1668186); -- Map: 1642 (Zandalar) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId`=1649726; -- Map: 530 (Outland) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1431813, 1147030, 1108102, 1108104, 2413352, 2455708, 2417601, 2417593); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1145889, 1145890); -- Map: 571 (Northrend) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2505658, 2535890); -- Map: 2552 (Khaz Algar (Surface)) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (2577108, 1119723, 2474917); -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=13121, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1681906, 1681907, 1681908); -- Map: 1643 (Kul Tiras) - Phase: 13121
UPDATE `spawn_tracking_template` SET `PhaseId`=0, `VerifiedBuild`=62876 WHERE `SpawnTrackingId` IN (1656856, 1716449, 1652868, 1682765); -- Map: 1643 (Kul Tiras) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=2539963 AND `QuestObjectiveId`=451196) OR (`SpawnTrackingId`=2538346 AND `QuestObjectiveId` IN (451192,451191)) OR (`SpawnTrackingId`=2840256 AND `QuestObjectiveId`=462182) OR (`SpawnTrackingId`=2840250 AND `QuestObjectiveId`=462182) OR (`SpawnTrackingId`=2412477 AND `QuestObjectiveId`=452865) OR (`SpawnTrackingId`=2415060 AND `QuestObjectiveId`=445785) OR (`SpawnTrackingId`=2415057 AND `QuestObjectiveId`=445784) OR (`SpawnTrackingId`=2415055 AND `QuestObjectiveId`=445786) OR (`SpawnTrackingId`=2347280 AND `QuestObjectiveId`=448321) OR (`SpawnTrackingId`=2579767 AND `QuestObjectiveId`=453131);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(2539963, 451196, 63305), -- 2539963
(2538346, 451192, 63305), -- 2538346
(2538346, 451191, 63305), -- 2538346
(2840256, 462182, 63305), -- 2840256
(2840250, 462182, 63305), -- 2840250
(2412477, 452865, 63305), -- 2412477
(2415060, 445785, 63305), -- 2415060
(2415057, 445784, 63305), -- 2415057
(2415055, 445786, 63305), -- 2415055
(2347280, 448321, 62876), -- 2347280
(2579767, 453131, 62876); -- 2579767

UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63305 WHERE (`QuestObjectiveId`=294324 AND `SpawnTrackingId`=1415554) OR (`QuestObjectiveId`=283388 AND `SpawnTrackingId`=1147030) OR (`QuestObjectiveId`=461360 AND `SpawnTrackingId` IN (2675100,2675101,2674550,2674549)) OR (`QuestObjectiveId`=447801 AND `SpawnTrackingId` IN (2370969,2361526,2370952,2370939)) OR (`QuestObjectiveId`=435777 AND `SpawnTrackingId`=2339065) OR (`QuestObjectiveId`=451884 AND `SpawnTrackingId`=2158408) OR (`QuestObjectiveId`=352976 AND `SpawnTrackingId`=1654832) OR (`QuestObjectiveId`=352974 AND `SpawnTrackingId`=1654831) OR (`QuestObjectiveId`=388427 AND `SpawnTrackingId`=1663963) OR (`QuestObjectiveId`=353017 AND `SpawnTrackingId`=1655211) OR (`QuestObjectiveId`=337137 AND `SpawnTrackingId`=1478764) OR (`QuestObjectiveId`=333785 AND `SpawnTrackingId`=1507741) OR (`QuestObjectiveId`=283331 AND `SpawnTrackingId`=1145890);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63163 WHERE (`QuestObjectiveId`=461360 AND `SpawnTrackingId` IN (2675100,2675101,2674550,2674549)) OR (`QuestObjectiveId`=447801 AND `SpawnTrackingId` IN (2370969,2361526,2370952,2370939)) OR (`QuestObjectiveId`=435777 AND `SpawnTrackingId`=2339065) OR (`QuestObjectiveId`=451884 AND `SpawnTrackingId`=2158408) OR (`QuestObjectiveId`=352976 AND `SpawnTrackingId`=1654832) OR (`QuestObjectiveId`=352974 AND `SpawnTrackingId`=1654831) OR (`QuestObjectiveId`=388427 AND `SpawnTrackingId`=1663963) OR (`QuestObjectiveId`=353017 AND `SpawnTrackingId`=1655211) OR (`QuestObjectiveId`=337137 AND `SpawnTrackingId`=1478764) OR (`QuestObjectiveId`=333785 AND `SpawnTrackingId`=1507741) OR (`QuestObjectiveId`=283331 AND `SpawnTrackingId`=1145890) OR (`QuestObjectiveId`=448961 AND `SpawnTrackingId`=2477190) OR (`QuestObjectiveId`=450240 AND `SpawnTrackingId` IN (2423559,2440569,2406561,2454476,2452137,2399830,2386212,2394453,2418988,2421816,2408218,2448084));
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=62876 WHERE (`QuestObjectiveId`=461043 AND `SpawnTrackingId`=2784580) OR (`QuestObjectiveId`=462038 AND `SpawnTrackingId` IN (2867936,2867940,2867925,2867922,2867944,2867905)) OR (`QuestObjectiveId`=461360 AND `SpawnTrackingId` IN (2675100,2675101,2674550,2674549)) OR (`QuestObjectiveId`=447801 AND `SpawnTrackingId` IN (2370969,2361526,2370952,2370939)) OR (`QuestObjectiveId`=435777 AND `SpawnTrackingId`=2339065) OR (`QuestObjectiveId`=352976 AND `SpawnTrackingId`=1654832) OR (`QuestObjectiveId`=352974 AND `SpawnTrackingId`=1654831) OR (`QuestObjectiveId`=388427 AND `SpawnTrackingId`=1663963) OR (`QuestObjectiveId`=353017 AND `SpawnTrackingId`=1655211) OR (`QuestObjectiveId`=337137 AND `SpawnTrackingId`=1478764) OR (`QuestObjectiveId`=333785 AND `SpawnTrackingId`=1507741) OR (`QuestObjectiveId`=283331 AND `SpawnTrackingId`=1145890) OR (`QuestObjectiveId`=449752 AND `SpawnTrackingId`=2494921) OR (`QuestObjectiveId`=462035 AND `SpawnTrackingId` IN (2867936,2867940,2867925,2867922,2867944,2867905)) OR (`QuestObjectiveId`=281356 AND `SpawnTrackingId` IN (1205109,1108102));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (124442, 128486, 127914, 117750, 117749, 127911, 114494, 129778, 128485, 126216, 125240, 126249, 126250, 126251, 129070, 129073, 129071, 129072, 122087, 122089, 126210, 114746, 126319, 125242, 125241, 128475, 120432, 129956, 129842, 122161, 121899, 128449, 128457, 108105, 119767, 128461, 114802, 108119, 122159, 128159, 120393, 120374, 128473, 120173, 131768, 122156, 122157, 93141, 116340, 121426, 131935, 117662, 131922, 128364, 111248, 111421, 109003, 110718, 110683, 111400, 106126, 90737, 114913, 129084, 120363, 131806, 123246, 119693, 128488, 128413, 123244, 116150, 131887, 131898, 128162, 127456, 127534, 123340, 128445, 128472, 128464, 91672, 89580, 128161, 128152, 128143, 128154, 116643, 128480, 128155, 123306, 97448, 124367, 130312, 128149, 124227, 121364, 122404, 128407, 128462, 129508, 124291, 122019, 118860, 127400, 123505, 118423, 122104, 118422, 118486, 118586, 79674, 123252, 128708, 112819, 131903, 131928, 131319, 131377, 123810, 79463, 115696, 131894, 116659, 91118, 127876, 128363, 128371, 123002, 106190, 128470, 124382, 119008, 124393, 123268, 119006, 118373, 118221, 124557, 123602, 123603, 123747, 123601, 131896, 131897, 115990, 120243, 116563, 116704, 91671, 116705, 116708, 118540, 118539, 118537, 118538, 92860, 92858, 92861, 92859, 116709, 118394, 121403, 128453, 131927, 131905, 118391, 98916, 123230, 124063, 118723, 118724, 118375, 129685, 120342, 122828, 118668, 114998, 114997, 118374, 123038, 106619);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(124442, 0.889685809612274169, 0, 0, 62876),
(128486, 0.305999994277954101, 1.5, 0, 62876),
(127914, 0.347222000360488891, 1.5, 0, 62876),
(117750, 0.663779318332672119, 1.424999952316284179, 0, 62876),
(117749, 0.312499791383743286, 1.349999904632568359, 0, 62876),
(127911, 0.208000004291534423, 1.5, 0, 62876),
(114494, 0.160127446055412292, 0, 0, 62876),
(129778, 0.999469935894012451, 1.330000042915344238, 0, 62876),
(128485, 0.347222030162811279, 1.5, 0, 62876),
(126216, 1.433340787887573242, 1, 0, 62876),
(125240, 0.5, 9, 0, 62876),
(126249, 0.790720283985137939, 1.5, 0, 62876),
(126250, 0.790720343589782714, 1.5, 0, 62876),
(126251, 0.790720343589782714, 1.50000011920928955, 0, 62876),
(129070, 0.5, 9, 0, 62876),
(129073, 0.306000024080276489, 1.50000011920928955, 0, 62876),
(129071, 0.948864340782165527, 1.799999952316284179, 0, 62876),
(129072, 0.698715150356292724, 1.5, 0, 62876),
(122087, 6.911696910858154296, 0, 0, 62876),
(122089, 2.766842365264892578, 0, 0, 62876),
(126210, 1.043526291847229003, 1, 0, 62876),
(114746, 0.24063478410243988, 0, 0, 62876),
(126319, 0.208000004291534423, 1.5, 0, 62876),
(125242, 4.17236948013305664, 3, 0, 62876),
(125241, 11.80086803436279296, 7, 0, 62876),
(128475, 0.305999964475631713, 1.5, 0, 62876),
(120432, 0.347000002861022949, 1.5, 0, 62876),
(129956, 0.863881826400756835, 14, 0, 62876),
(129842, 0.305999994277954101, 1.5, 0, 62876),
(122161, 1.366205096244812011, 1.75, 0, 62876),
(121899, 1.65874183177947998, 2, 0, 62876),
(128449, 0.208000004291534423, 1.5, 0, 62876),
(128457, 0.698715090751647949, 1.5, 0, 62876),
(108105, 0.300000011920928955, 0, 0, 62876),
(119767, 0.5, 1, 0, 62876),
(128461, 0.208000004291534423, 1.5, 0, 62876),
(114802, 1.652143120765686035, 0.800000011920928955, 0, 62876),
(108119, 1.265631079673767089, 0.900000035762786865, 0, 62876),
(122159, 1.366205096244812011, 1.75, 0, 62876),
(128159, 0.208000004291534423, 1.5, 0, 62876),
(120393, 0.347000002861022949, 1.5, 0, 62876),
(120374, 0.5, 1, 0, 62876),
(128473, 0.305999994277954101, 1.5, 0, 62876),
(120173, 0.08749999850988388, 0.375, 0, 62876),
(131768, 0.74140477180480957, 0, 0, 62876),
(122156, 1.366205096244812011, 1.75, 0, 62876),
(122157, 1.366205096244812011, 1.75, 0, 62876),
(93141, 0.305999994277954101, 1.5, 0, 62876),
(116340, 0.382999986410140991, 1.5, 0, 62876),
(121426, 1, 1.5, 0, 62876),
(131935, 0.347222000360488891, 1.5, 0, 62876),
(117662, 0.948864400386810302, 1.80000007152557373, 0, 62876),
(131922, 0.347222000360488891, 1.5, 0, 62876),
(128364, 0.966191768646240234, 0, 0, 62876),
(111248, 1.755318164825439453, 3, 0, 62876),
(111421, 1.63746809959411621, 3, 0, 62876),
(109003, 1.129799962043762207, 3.079999923706054687, 0, 62876),
(110718, 1.755318164825439453, 3, 0, 62876),
(110683, 0.722000002861022949, 2, 0, 62876),
(111400, 4.316836357116699218, 0, 0, 62876),
(106126, 0.722000002861022949, 2, 0, 62876),
(90737, 1.954756975173950195, 1.27500009536743164, 0, 62876),
(114913, 1.990490317344665527, 2.40000009536743164, 0, 62876),
(129084, 3.785482406616210937, 0, 0, 62876),
(120363, 4.17236948013305664, 3, 0, 62876),
(131806, 0.889685809612274169, 0, 0, 62876),
(123246, 0.347000002861022949, 1.5, 0, 62876),
(119693, 0.375, 0.375, 0, 62876),
(128488, 0.305999994277954101, 1.5, 0, 62876),
(128413, 0.698715090751647949, 1.5, 0, 62876),
(123244, 0.347000002861022949, 1.5, 0, 62876),
(116150, 5.708419322967529296, 5, 0, 62876),
(131887, 0.347000002861022949, 1.5, 0, 62876),
(131898, 0.698000013828277587, 3, 0, 62876),
(128162, 0.347222000360488891, 1.50000011920928955, 0, 62876),
(127456, 0.208000004291534423, 1.5, 0, 62876),
(127534, 0.208000004291534423, 1.5, 0, 62876),
(123340, 0.305999994277954101, 1.5, 0, 62876),
(128445, 0.698715090751647949, 1.50000011920928955, 0, 62876),
(128472, 0.347222000360488891, 1.5, 0, 62876),
(128464, 0.347222000360488891, 1.5, 0, 62876),
(91672, 0.236000001430511474, 1.5, 0, 62876),
(89580, 0.347222000360488891, 1.5, 0, 62876),
(128161, 0.347222000360488891, 1.5, 0, 62876),
(128152, 0.305999994277954101, 1.5, 0, 62876),
(128143, 0.698715090751647949, 1.5, 0, 62876),
(128154, 0.305999994277954101, 1.5, 0, 62876),
(116643, 0.413213968276977539, 0, 0, 62876),
(128480, 0.208000004291534423, 1.5, 0, 62876),
(128155, 0.698715090751647949, 1.5, 0, 62876),
(123306, 11.80086803436279296, 7, 0, 62876),
(97448, 0.349999994039535522, 0, 0, 62876),
(124367, 0.381700009107589721, 1.65000009536743164, 0, 62876),
(130312, 1.888888955116271972, 2, 0, 62876),
(128149, 0.347222000360488891, 1.5, 0, 62876),
(124227, 1.5, 30, 0, 62876),
(121364, 0.165866807103157043, 1, 0, 62876),
(122404, 10.01248931884765625, 10, 0, 62876),
(128407, 0.305999994277954101, 1.5, 0, 62876),
(128462, 0.208000004291534423, 1.5, 0, 62876),
(129508, 0.395186424255371093, 1, 0, 62876),
(124291, 2.8288726806640625, 1, 0, 62876),
(122019, 0.400000005960464477, 0.60000002384185791, 0, 62876),
(118860, 1.689352035522460937, 3, 0, 62876),
(127400, 0.089572466909885406, 0, 0, 62876),
(123505, 0.375, 1.125, 0, 62876),
(118423, 0.347000002861022949, 1.5, 0, 62876),
(122104, 0.400000005960464477, 0.040000002831220626, 0, 62876),
(118422, 0.347000002861022949, 1.5, 0, 62876),
(118486, 0.260100007057189941, 1.27500009536743164, 0, 62876),
(118586, 0.676373958587646484, 0, 0, 62876),
(79674, 1.347197294235229492, 3.5, 0, 62876),
(123252, 1, 1.5, 0, 62876),
(128708, 10.29815196990966796, 9, 0, 62876),
(112819, 0.999469876289367675, 1.330000042915344238, 0, 62876),
(131903, 0.305999994277954101, 1.5, 0, 62876),
(131928, 0.347222000360488891, 1.5, 0, 62876),
(131319, 15, 1, 0, 62876),
(131377, 2, 1.799999833106994628, 0, 62876),
(123810, 0.889685750007629394, 0, 0, 62876),
(79463, 0.305999994277954101, 1.5, 0, 62876),
(115696, 0.305999994277954101, 1.5, 0, 62876),
(131894, 0.305999994277954101, 1.5, 0, 62876),
(116659, 0.305999994277954101, 1.5, 0, 62876),
(91118, 5.722690582275390625, 1, 0, 62876),
(127876, 0.382999986410140991, 1.5, 0, 62876),
(128363, 0.966191768646240234, 0, 0, 62876),
(128371, 0.966191768646240234, 0, 0, 62876),
(123002, 5.723157882690429687, 10, 0, 62876),
(106190, 1.132115364074707031, 1.5, 0, 62876),
(128470, 0.347222000360488891, 1.5, 0, 62876),
(124382, 2.232307195663452148, 1.299999952316284179, 0, 62876),
(119008, 0.208000004291534423, 1.5, 0, 62876),
(124393, 1, 0, 0, 62876),
(123268, 2.308222770690917968, 1.5, 0, 62876),
(119006, 0.208000004291534423, 1.5, 0, 62876),
(118373, 0.310000002384185791, 1, 0, 62876),
(118221, 0.077500000596046447, 0.25, 0, 62876),
(124557, 0.382999986410140991, 1.5, 0, 62876),
(123602, 0.305999994277954101, 1.5, 0, 62876),
(123603, 0.305999994277954101, 1.5, 0, 62876),
(123747, 0.305999994277954101, 1.5, 0, 62876),
(123601, 0.305999994277954101, 1.5, 0, 62876),
(131896, 0.382999986410140991, 1.5, 0, 62876),
(131897, 0.382999986410140991, 1.5, 0, 62876),
(115990, 0.5, 1, 0, 62876),
(120243, 1, 0, 0, 62876),
(116563, 1.83703017234802246, 0, 0, 62876),
(116704, 0.388999998569488525, 1.5, 0, 62876),
(91671, 0.372000008821487426, 1.5, 0, 62876),
(116705, 0.388999998569488525, 1.5, 0, 62876),
(116708, 0.305999994277954101, 1.5, 0, 62876),
(118540, 0.347000002861022949, 1.5, 0, 62876),
(118539, 0.347000002861022949, 1.5, 0, 62876),
(118537, 0.347000002861022949, 1.5, 0, 62876),
(118538, 0.347000002861022949, 1.5, 0, 62876),
(92860, 0.419988274574279785, 1.5, 0, 62876),
(92858, 0.419988274574279785, 1.5, 0, 62876),
(92861, 0.335298478603363037, 1.5, 0, 62876),
(92859, 0.335298478603363037, 1.5, 0, 62876),
(116709, 0.305999994277954101, 1.5, 0, 62876),
(118394, 1.689352035522460937, 0, 0, 62876),
(121403, 0.347000002861022949, 1.5, 0, 62876),
(128453, 0.347222000360488891, 1.5, 0, 62876),
(131927, 0.347222000360488891, 1.5, 0, 62876),
(131905, 0.236000001430511474, 1.5, 0, 62876),
(118391, 0.483442813158035278, 0, 0, 62876),
(98916, 1.553661823272705078, 0, 0, 62876),
(123230, 0.347000002861022949, 1.5, 0, 62876),
(124063, 0.74140477180480957, 0, 0, 62876),
(118723, 0.698715090751647949, 1.5, 0, 62876),
(118724, 0.698715090751647949, 1.5, 0, 62876),
(118375, 0.363503575325012207, 0, 0, 62876),
(129685, 0.366300106048583984, 0, 0, 62876),
(120342, 2.40000009536743164, 1.60000002384185791, 0, 62876),
(122828, 1, 1, 0, 62876),
(118668, 0.347222000360488891, 1.5, 0, 62876),
(114998, 1.299999952316284179, 1.299999952316284179, 0, 62876),
(114997, 1.299999952316284179, 1.299999952316284179, 0, 62876),
(118374, 0.363503575325012207, 0, 0, 62876),
(123038, 1, 0, 0, 62876),
(106619, 0.227289453148841857, 0, 0, 62876);

UPDATE `creature_model_info` SET `VerifiedBuild`=62876 WHERE `DisplayID` IN (68857, 119225, 10990, 63538, 2421, 51272, 114316, 117231, 121355, 121362, 90594, 121092, 119256, 119254, 116479, 119255, 116354, 119243, 116409, 121040, 115024, 119758, 116356, 119252, 118257, 122040, 117464, 127572, 127582, 41853, 120434, 121368, 119086, 106893, 62629, 119157, 120246, 117909, 117896, 117898, 81138, 116273, 115211, 115212, 115399, 115401, 117069, 60800, 83614, 83616, 121457, 33293, 119410, 119412, 102532, 106817, 103323, 87605, 122158, 103557, 36345, 115166, 121319, 37363, 113074, 117267, 118400, 114804, 119280, 114646, 119283, 120015, 114805, 113897, 117232, 95789, 119857, 120575, 120576, 120564, 120561, 120579, 119715, 120563, 120565, 120013, 120562, 114658, 106562, 127580, 127576, 106822, 106818, 114793, 104048, 114795, 114790, 114792, 102507, 104049, 102508, 104046, 102530, 106016, 128487, 119382, 93071, 120970, 117747, 111509, 114809, 109358, 128476, 92988, 93688, 99862, 114815, 108505, 32254, 112157, 122570, 116976, 71930, 109008, 109009, 116848, 40263, 121847, 115189, 115217, 115185, 120103, 115209, 121096, 115362, 118318, 119421, 119238, 114828, 9028, 114823, 103321, 6297, 103280, 103316, 106816, 103281, 102533, 69254, 103904, 122169, 122162, 122163, 122160, 122171, 122166, 91673, 86432, 128450, 128151, 128451, 120467, 121347, 78851, 115029, 119426, 119876, 78244, 119231, 121043, 119431, 120386, 119307, 120387, 120061, 123251, 123800, 124638, 125896, 22899, 121372, 126081, 126077, 126078, 125898, 126080, 117989, 124322, 125897, 126082, 124372, 22992, 114687, 117395, 116114, 120980, 119082, 107030, 112539, 117174, 120877, 116113, 116227, 119078, 117748, 128210, 32406, 32409, 114474, 79638, 104031, 104531, 104530, 103873, 122155, 114822, 114817, 114819, 103863, 117017, 114821, 117018, 116602, 116601, 116630, 117019, 117020, 116849, 77525, 90103, 114824, 100074, 86343, 93140, 108504, 86342, 119337, 119338, 30313, 100600, 117305, 122500, 121671, 117303, 117301, 91669, 97915, 117299, 117306, 117308, 117298, 117307, 117304, 117309, 117302, 122499, 122501, 117300, 105389, 114139, 119083, 114826, 117291, 91384, 84523, 114820, 114800, 81975, 114818, 114816, 51144, 118576, 103558, 103559, 114825, 106638, 114930, 114827, 104532, 104533, 4589, 118317, 117951, 91385, 41795, 105489, 117606, 117605, 117610, 107116, 102874, 120469, 116115, 120821, 78832, 118233, 118849, 110061, 81056, 113980, 114365, 121775, 114114, 114116, 114189, 109001, 121361, 121370, 122670, 101440, 121446, 121151, 57021, 91870, 91862, 91872, 102882, 103226, 102898, 121210, 120660, 109002, 108970, 102880, 112729, 121021, 117482, 91866, 91868, 103218, 101042, 107048, 102975, 102883, 102974, 102903, 107046, 102979, 102897, 102978, 102955, 35044, 102565, 103217, 103216, 102884, 116308, 102942, 102944, 103219, 102900, 103228, 103213, 103214, 124391, 107114, 103222, 121447, 114922, 116360, 120034, 124620, 103250, 115226, 90583, 117489, 117490, 115190, 119076, 115242, 112187, 103254, 112188, 102564, 110383, 103223, 103220, 103224, 108973, 106988, 108976, 106986, 108314, 106985, 106992, 103221, 106994, 106987, 106991, 107128, 106989, 124392, 91387, 109799, 110394, 110392, 106118, 106132, 110398, 106034, 107908, 107776, 106145, 106033, 108355, 106130, 106129, 105441, 108207, 106120, 106116, 106114, 106117, 106125, 106122, 106028, 106131, 106036, 106020, 106115, 10008, 106133, 108354, 106128, 106134, 106047, 106121, 6091, 59531, 110393, 103826, 117495, 117480, 9033, 110090, 102515, 1963, 107226, 84246, 103829, 107223, 104672, 84986, 104673, 82974, 6093, 96559, 82993, 59539, 106135, 103817, 102997, 103004, 103006, 103827, 108833, 103814, 108654, 105538, 108826, 104665, 104667, 104724, 104666, 103845, 104664, 104725, 108123, 105553, 102833, 103844, 104648, 100537, 106561, 120443, 104474, 104475, 104472, 100336, 104473, 120442, 100222, 110395, 109403, 103515, 102071, 106838, 106834, 110391, 106731, 106839, 106740, 64987, 102198, 105791, 108054, 106769, 103816, 105789, 106744, 104931, 104937, 108213, 120440, 120441, 120427, 120425, 120426, 120428, 122462, 120439, 117483, 120429, 102562, 102559, 106608, 110013, 104722, 106594, 106674, 111717, 104647, 108828, 104657, 106595, 106609, 121425, 107025, 104723, 105552, 103468, 108324, 119327, 120473, 117260, 80967, 110012, 58595, 109719, 106310, 106890, 107026, 104934, 107023, 121993, 120458, 118609, 120433, 120459, 120430, 83699, 117485, 117496, 114659, 120437, 119162, 119161, 117612, 114928, 120438, 120472, 110932, 100359, 103055, 115766, 104932, 106842, 104463, 113909, 100702, 101135, 102940, 104951, 107027, 104344, 104451, 119067, 114927, 119660, 119066, 100414, 113669, 112292, 111430, 104308, 103828, 104947, 106636, 104926, 108926, 92146, 116648, 111423, 114914, 70178, 108918, 105401, 112189, 114937, 103508, 104379, 106647, 104927, 102777, 106646, 104133, 106426, 106565, 107700, 104171, 104924, 110855, 110686, 106448, 114915, 106494, 104939, 107024, 103479, 104923, 104175, 108149, 102675, 102140, 110069, 104238, 110071, 110604, 105787, 108141, 108156, 106489, 100197, 104925, 106872, 104933, 104208, 102674, 108135, 108158, 108150, 102138, 107779, 104209, 109442, 108045, 117262, 106487, 108154, 109472, 104929, 104334, 102693, 104928, 110432, 101643, 108915, 105218, 108157, 108146, 104224, 107010, 119087, 104165, 120664, 29404, 121445, 119251, 117611, 106564, 117202, 86488, 116542, 75007, 7920, 128409, 128415, 128697, 128599, 127579, 128639, 117827, 123337, 128643, 128600, 128422, 127571, 128648, 128649, 128646, 127573, 128414, 128408, 128425, 128698, 128597, 128592, 128598, 128427, 128424, 128423, 127581, 127575, 123343, 128645, 127570, 45386, 120413, 25002, 126209, 128218, 128219, 127552, 120411, 128220, 128482, 117161, 22388, 121059, 121865, 120036, 64392, 121160, 117608, 114939, 116111, 116112, 103853, 103851, 119070, 102506, 128443, 60714, 117241, 115351, 119512, 115331, 119518, 119513, 122660, 128467, 117259, 128494, 127546, 127544, 123346, 128214, 128212, 128215, 118736, 126126, 30754, 19074, 72658, 128492, 128142, 119935, 115777, 121802, 128986, 115026, 118720, 121365, 117876, 117875, 117879, 122705, 124589, 124607, 35319, 128090, 128089, 48650, 128594, 128454, 117888, 119311, 114127, 80502, 86476, 47252, 5187, 128595, 127458, 114131, 115438, 128493, 128146, 128474, 418, 38185, 2538, 115213, 127548, 127542, 128440, 115101, 128156, 123339, 127543, 128491, 42430, 128147, 117705, 122995, 128567, 128213, 128568, 117278, 130204, 101285, 112678, 128444, 82763, 82726, 82793, 82713, 34693, 86434, 34564, 34551, 34673, 34565, 111075, 90304, 94166, 115758, 128460, 127459, 128483, 128153, 128441, 5207, 77510, 114943, 121450, 114944, 121887, 73673, 114650, 60652, 78969, 76605, 119987, 30631, 30628, 30630, 63775, 30629, 30616, 99828, 99833, 89800, 89801, 99827, 16777, 16824, 16809, 16781, 16788, 16817, 99826, 99832, 17122, 19707, 99830, 99829, 17547, 18144, 99831, 83279, 114406, 81965, 109361, 115199, 70013, 72001, 72002, 71988, 73592, 70880, 71989, 70017, 70015, 70018, 118235, 74040, 71685, 73940, 59116, 68661, 71895, 62591, 115208, 66272, 72199, 67342, 66836, 67132, 62592, 69435, 70590, 71437, 67551, 73499, 70443, 66271, 66547, 28435, 70752, 70019, 41395, 114966, 118017, 57485, 118960, 114436, 114417, 118507, 127125, 122657, 121642, 121643, 114694, 117541, 70179, 91386, 83032, 83040, 68890, 83039, 83010, 70460, 70459, 16269, 71875, 66556, 44552, 71986, 70020, 72936, 66267, 61927, 70747, 71655, 10191, 73504, 66265, 70750, 71600, 70748, 70749, 70627, 70128, 71120, 66567, 66261, 66575, 71121, 71123, 66573, 70758, 66262, 71122, 118219, 72004, 19589, 63525, 70878, 70760, 71118, 70924, 72003, 70757, 118220, 71793, 71582, 72010, 69923, 45448, 2598, 66268, 66264, 70562, 71944, 69488, 68010, 70486, 73503, 73500, 66246, 73514, 71580, 66589, 66275, 63526, 63866, 21888, 70948, 60863, 40584, 69721, 47652, 69317, 46525, 70516, 63336, 46523, 39623, 46522, 46524, 57062, 47403, 47953, 36331, 47954, 19706, 66974, 58159, 63624, 70011, 47670, 70014, 71231, 70016, 66859, 70012, 71587, 67365, 51815, 82270, 26740, 63738, 59602, 32808, 115369, 115348, 117518, 66144, 63946, 63943, 66323, 64339, 70616, 124555, 65050, 33309, 67702, 4614, 115094, 117062, 114626, 115093, 115577, 75006, 121162, 116439, 116441, 115722, 116440, 121161, 117470, 113275, 64194, 128406, 128484, 128404, 88695, 128411, 128410, 117318, 105577, 93507, 28817, 15786, 121358, 121359, 115591, 117710, 108455, 115041, 118871, 118610, 117280, 115144, 127554, 127551, 128569, 128145, 115088, 128140, 8840, 719, 68608, 5108, 66237, 66019, 66295, 65470, 70156, 65483, 70380, 66300, 65706, 65466, 65705, 72888, 66294, 66299, 65996, 65469, 65468, 66394, 65471, 68220, 66392, 67045, 66305, 66302, 65770, 66319, 68343, 65533, 66389, 63859, 70920, 70221, 64387, 70371, 65754, 68368, 5379, 40713, 66142, 68367, 66143, 69587, 64660, 74405, 67044, 64304, 68370, 65393, 64335, 65389, 65455, 66746, 40716, 70909, 68157, 61204, 47992, 32234, 64595, 66625, 66370, 34706, 101147, 101144, 69191, 68398, 43491, 68538, 65052, 68236, 71134, 71829, 69740, 68526, 70584, 40094, 70817, 35802, 72720, 66667, 72734, 68238, 63621, 72041, 68237, 55080, 40090, 68239, 64541, 51301, 32807, 60047, 67465, 65204, 47695, 68040, 63524, 64719, 64001, 62068, 116686, 122088, 120491, 116685, 120465, 120466, 116348, 67171, 65308, 23748, 127457, 123342, 127539, 127553, 115370, 115364, 27215, 116508, 62762, 69896, 104502, 104505, 114483, 116912, 69522, 115167, 115120, 115170, 123088, 115482, 117887, 122678, 117227, 122684, 122668, 119414, 115435, 115442, 115460, 120399, 122677, 121534, 47711, 117878, 117228, 121366, 117886, 69516, 94760, 115174, 114305, 115173, 129846, 117086, 32023, 61702, 37136, 62359, 63124, 64953, 120352, 48106, 64891, 65094, 124020, 69569, 69539, 69538, 114698, 114691, 114710, 114709, 114735, 4878, 69233, 115502, 44479, 68213, 34670, 115501, 60968, 91910, 69155, 62305, 63585, 24574, 61970, 115472, 40155, 45937, 115473, 69196, 53878, 49084, 16943, 38638, 84933, 73789, 61819, 69306, 62259, 67597, 69709, 66811, 119988, 69897, 66815, 70510, 66814, 61814, 61283, 61286, 31018, 66813, 45882, 41300, 68659, 15395, 15396, 15394, 70070, 60914, 680, 540, 486, 61304, 61100, 115361, 64417, 61101, 62070, 61099, 62261, 54644, 69851, 31215, 61102, 71004, 70986, 61693, 32568, 61123, 63166, 61097, 60845, 69860, 43100, 65790, 61095, 61098, 39553, 67421, 66809, 67258, 60891, 22590, 31291, 61096, 120909, 104833, 115252, 66644, 67345, 89347, 84240, 99814, 15237, 4231, 8631, 9132, 96327, 96332, 24979, 27599, 96329, 96330, 27589, 27153, 70436, 96326, 96086, 37795, 34561, 34558, 34557, 34555, 99139, 99138, 100500, 72174, 79321, 98009, 34566, 34562, 93431, 93425, 93421, 93435, 93430, 93419, 66157, 34842, 34843, 36170, 34421, 34569, 34567, 34593, 29968, 93434, 36169, 34841, 35250, 99513, 35249, 34695, 34568, 27164, 34694, 37725, 37723, 28300, 32996, 48528, 48527, 34219, 34214, 48526, 19217, 48525, 86688, 22602, 99374, 12676, 12675, 12671, 34220, 12677, 113851, 113850, 81307, 99511, 34266, 6060, 34204, 34268, 83011, 27252, 99510, 34203, 81306, 99509, 2735, 2734, 34206, 34222, 2957, 99508, 34246, 4358, 34245, 11734, 38008, 34241, 34242, 34247, 9261, 34243, 3759, 110481, 81973, 32265, 1250, 80093, 32263, 82697, 77903, 80474, 3915, 7234, 7238, 3911, 33587, 33590, 33582, 7054, 29351, 37699, 29336, 2187, 6076, 3912, 7035, 3919, 115483, 7237, 3918, 115504, 115469, 115503, 115430, 4098, 115499, 7233, 114962, 37798, 115257, 1747, 1043, 48620, 48622, 4442, 2710, 48590, 48623, 48544, 48589, 1973, 48592, 48547, 48546, 48545, 48621, 115253, 106598, 48865, 48591, 1343, 178, 6087, 29806, 4199, 4261, 11859, 11860, 37912, 36174, 23873, 29224, 37808, 48643, 48642, 48640, 48641, 1453, 48630, 29371, 48632, 48631, 48629, 30549, 1105, 788, 30559, 115616, 30560, 30569, 30543, 30526, 114553, 30568, 30546, 86966, 80087, 80381, 79091, 79072, 80090, 80088, 80390, 80335, 80425, 51414, 80336, 80343, 80344, 80339, 80327, 80319, 80454, 79092, 3824, 121116, 121115, 120323, 6078, 114411, 118179, 121117, 79166, 1056, 161, 115358, 115365, 114655, 89583, 66591, 128175, 37013, 33524, 3550, 121406, 123338, 127577, 127578, 117403, 9742, 5372, 2100, 2090, 37345, 2951, 37342, 9337, 112857, 112855, 114768, 107801, 3777, 4608, 3782, 4299, 3811, 30395, 30394, 30393, 10188, 81208, 28067, 82296, 82295, 82293, 82294, 81080, 100883, 90950, 84511, 84516, 84518, 81102, 80533, 85176, 85034, 85036, 85033, 81873, 85030, 85032, 85178, 85177, 81872, 2108, 2116, 64916, 2118, 26775, 23830, 89340, 88954, 89339, 38006, 38010, 37400, 7628, 3129, 7627, 7626, 2092, 2083, 2110, 38011, 3002, 5487, 2127, 2109, 2132, 88823, 127826, 2133, 5847, 10614, 2126, 10577, 10617, 2101, 2099, 2094, 2129, 2117, 2093, 2114, 2119, 10586, 123798, 7624, 81375, 7622, 7623, 9272, 88820, 2091, 78352, 78353, 88821, 88822, 67397, 126578, 125618, 125654, 127172, 126579, 125617, 95141, 126787, 126043, 126789, 126580, 125738, 125739, 123782, 103326, 126788, 126790, 113941, 115009, 125751, 125298, 2120, 7629, 4519, 107800, 105525, 118589, 67543, 104638, 117904, 67558, 119990, 123047, 88960, 88962, 86489, 127938, 128126, 127778, 124582, 128738, 128442, 120916, 115500, 115431, 115439, 115461, 115154, 115434, 114146, 115498, 115496, 115478, 115028, 115497, 115479, 59003, 115153, 14853, 117166, 118674, 115410, 118145, 117275, 128570, 117861, 112833, 119202, 119200, 28628, 67534, 67003, 121045, 121046, 122701, 117463, 122706, 120593, 122671, 122708, 122683, 122691, 122674, 122703, 122676, 125210, 122710, 122696, 122695, 128696, 122943, 122944, 122685, 122673, 122700, 122702, 121730, 122694, 118635, 122682, 122669, 122697, 122675, 120222, 122679, 119423, 119417, 119413, 119429, 119422, 119840, 121354, 121352, 119418, 122711, 122707, 122709, 115428, 40906, 44108, 2125, 106644, 2107, 2124, 2140, 2095, 2089, 2085, 2086, 2111, 10689, 2088, 2097, 2084, 37343, 38009, 33430, 103878, 1351, 10877, 1221, 115210, 111022, 43948, 103881, 103879, 115218, 67794, 37197, 67792, 1451, 3795, 35612, 4604, 4992, 3806, 3796, 1678, 10181, 10182, 3802, 3800, 3803, 125707, 11054, 3804, 9269, 4265, 3814, 4605, 3775, 4300, 11902, 12246, 11641, 5507, 4298, 5486, 3807, 12241, 32080, 3784, 14579, 14578, 14349, 109480, 33509, 3820, 3822, 37561, 30271, 109990, 33510, 3826, 3821, 10052, 10051, 120470, 118001, 119425, 118142, 122681, 115956, 104631, 3794, 9935, 9936, 10050, 10049, 121132, 115288, 122667, 115995, 116276, 118172, 122704, 3783, 3780, 117877, 118186, 117881, 116020, 117882, 122699, 115535, 115527, 115526, 115538, 126168, 117237, 30392, 67793, 67795, 119007, 78383, 1624, 67389, 67454, 66990, 643, 1230, 115124, 1059, 2237, 115172, 118141, 32021, 74864, 118143, 1454, 1547, 1228, 45958, 1220, 1229, 115592, 29358, 117769, 29356, 29357, 30701, 115584, 4434, 125235, 125694, 125687, 125226, 125223, 125709, 125260, 125708, 120037, 1978, 125692, 112396, 112385, 115402, 2702, 120493, 115077, 115396, 115583, 125722, 123566, 125724, 123567, 1538, 1977, 117109, 115547, 125856, 115548, 117767, 117768, 117111, 4270, 124551, 85707, 110132, 124547, 120790, 124552, 115549, 117766, 119357, 119352, 110133, 119299, 119372, 119296, 119297, 120154, 119300, 119298, 119347, 119349, 110134, 108077, 117110, 117764, 82892, 119295, 119344, 119363, 115342, 117108, 117765, 115550, 115406, 77497, 82893, 120315, 103338, 30837, 115404, 113982, 114837, 91864, 30836, 30831, 1532, 103499, 30835, 30854, 30832, 30855, 119234, 119235, 114779, 120245, 114619, 33778, 30788, 120326, 120186, 120223, 115962, 116567, 115544, 122680, 30834, 31412, 30914, 30823, 118395, 122672, 115545, 30824, 120248, 33787, 33782, 30913, 17612, 30892, 30830, 30829, 115375, 30873, 118421, 30853, 29313, 30871, 118416, 118420, 4536, 101255, 2193, 30870, 27913, 2768, 31340, 31338, 31336, 31339, 10918, 119711, 4473, 69105, 40543, 40976, 117869, 119774, 15137, 118138, 112485, 112486, 79780, 119896, 30796, 6114, 118630, 30789, 1274, 6096, 119415, 119419, 118255, 121287, 118864, 119232, 119237, 121431, 119229, 4658, 119427, 118862, 118417, 107719, 110442, 110431, 121050, 119230, 107720, 30828, 57486, 53767, 118547, 75596, 118548, 71577, 121429, 1964, 119707, 105566, 115083, 120175, 117558, 119741, 118229, 6108, 115092, 116614, 120276, 120278, 115073, 118626, 120277, 117940, 118379, 115521, 115522, 105564, 112398, 109505, 117939, 33920, 115080, 117525, 112397, 92704, 121223, 116678, 116677, 114697, 116632, 116635, 120416, 114690, 122664, 114692, 116541, 115332, 114087, 116689, 115717, 116633, 120552, 121224, 119072, 120554, 114855, 117207, 112392, 120551, 120553, 120556, 120345, 117195, 116650, 116959, 115719, 117203, 102548, 117196, 118619, 117194, 119955, 45584, 22175, 45583, 45132, 10230, 11791, 118132, 120409, 120424, 115032, 115025, 115033, 119306, 119408, 115030, 116277, 91670, 34448, 89582, 48009, 90726, 72563, 83393, 90730, 83392, 66276, 10239, 31669, 128211, 89581, 10241, 10228, 10234, 10238, 10227, 31641, 10233, 32460, 111900, 114089, 114091, 118175, 118389, 120263, 10235, 10240, 10231, 117524, 124306, 118975, 115520, 115523, 10236, 31636, 121402, 127535, 122420, 122419, 4308, 117406, 16869, 31668, 32459, 10653, 2739, 9899, 32458, 31639, 32457, 118454, 19634, 38548, 110448, 117437, 119502, 110445, 73244, 35732, 33694, 10991, 34947, 61037, 67185, 67184, 35822, 2705, 37526, 33720, 34548, 12340, 119432, 3247, 123225, 35628, 32662, 481, 32454, 35629, 2308, 37583, 32513, 32661, 35577, 2491, 12341, 10825, 36034, 32663, 30755, 32453, 32455, 8392, 36273, 115495, 117175, 114678, 14557, 122125, 117287, 113189, 37686, 120915, 114725, 91619, 67186, 66979, 117140, 118173, 115969, 116434, 102556, 114703, 115409, 116611, 112386, 71056, 122629, 122627, 120937, 115407, 102375, 115403, 119708, 115250, 112387, 118218, 115405, 124021, 123226, 119495, 60653, 120128, 120127, 124065, 124061, 110046, 68303, 67658, 115007, 119004, 118215, 118599, 118590, 119003, 121385, 117116, 115251, 117903, 106637, 117906, 114548, 118607, 114547, 117900, 117899, 118667, 118271, 42362, 118600, 118662, 118666, 118588, 118665, 490, 66978, 7114, 92155, 66400, 441, 160, 115575, 487, 7348, 114654, 78384, 76336, 122652, 116450, 103342, 105003, 37687, 66989, 23952, 66991, 23372, 66992, 110446, 34159, 45879, 118598, 103340, 1536, 5228, 7345, 7217, 14668, 29472, 31319, 36616, 15324, 8010, 7342, 7175, 32076, 6880, 7341, 7215, 11689, 7216, 31113, 25118, 7343, 31940, 2410, 2405, 2785, 6882, 6473, 7335, 7182, 118608, 114995, 104632, 113043, 116272, 114550, 115004, 114999, 117901, 379, 116285, 120979, 84427, 23304, 57807, 65355, 65630, 15998, 115372, 120910, 120935, 69149, 54441, 109507, 116451, 109510, 112391, 37604, 119450, 119448, 119992, 114551, 22966, 120925, 33618, 31945, 6079, 29077, 18290, 1159, 6883, 7340, 45907, 14774, 30091, 11375, 47459, 47458, 36873, 31353, 31317, 19229, 31943, 31944, 7346, 11376, 9259, 120950, 120969, 120986, 120976, 11377);
UPDATE `creature_model_info` SET `BoundingRadius`=1, `VerifiedBuild`=62876 WHERE `DisplayID`=65967;
UPDATE `creature_model_info` SET `BoundingRadius`=1.491308569908142089, `CombatReach`=1.20000004768371582, `VerifiedBuild`=62876 WHERE `DisplayID`=114546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.843754053115844726, `CombatReach`=0.60000002384185791, `VerifiedBuild`=62876 WHERE `DisplayID`=107062;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=62876 WHERE `DisplayID`=69732;
UPDATE `creature_model_info` SET `BoundingRadius`=1.638525962829589843, `VerifiedBuild`=62876 WHERE `DisplayID`=113610;
UPDATE `creature_model_info` SET `BoundingRadius`=2.768550872802734375, `CombatReach`=3, `VerifiedBuild`=62876 WHERE `DisplayID` IN (103227, 103229, 103230);
UPDATE `creature_model_info` SET `BoundingRadius`=2.966680288314819335, `CombatReach`=7, `VerifiedBuild`=62876 WHERE `DisplayID`=102566;
UPDATE `creature_model_info` SET `BoundingRadius`=0.186000004410743713, `CombatReach`=0.60000002384185791, `VerifiedBuild`=62876 WHERE `DisplayID`=35107;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=20, `VerifiedBuild`=62876 WHERE `DisplayID`=107793;
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=62876 WHERE `DisplayID`=110381;
UPDATE `creature_model_info` SET `CombatReach`=2, `VerifiedBuild`=62876 WHERE `DisplayID`=109798;
UPDATE `creature_model_info` SET `BoundingRadius`=1.445090293884277343, `CombatReach`=3.614285707473754882, `VerifiedBuild`=62876 WHERE `DisplayID`=105444;
UPDATE `creature_model_info` SET `BoundingRadius`=2.246654272079467773, `CombatReach`=1.60000002384185791, `VerifiedBuild`=62876 WHERE `DisplayID`=100208;
UPDATE `creature_model_info` SET `BoundingRadius`=0.900171220302581787, `CombatReach`=5, `VerifiedBuild`=62876 WHERE `DisplayID`=106944;
UPDATE `creature_model_info` SET `BoundingRadius`=1.817795753479003906, `CombatReach`=1.666666746139526367, `VerifiedBuild`=62876 WHERE `DisplayID`=84999;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=3.000000238418579101, `VerifiedBuild`=62876 WHERE `DisplayID`=47808;
UPDATE `creature_model_info` SET `CombatReach`=3.60000014305114746, `VerifiedBuild`=62876 WHERE `DisplayID` IN (103018, 106887);
UPDATE `creature_model_info` SET `BoundingRadius`=0.645600020885467529, `CombatReach`=1.760000109672546386, `VerifiedBuild`=62876 WHERE `DisplayID`=105886;
UPDATE `creature_model_info` SET `BoundingRadius`=7.536656856536865234, `CombatReach`=5.333333492279052734, `VerifiedBuild`=62876 WHERE `DisplayID`=68923;
UPDATE `creature_model_info` SET `BoundingRadius`=0.205233380198478698, `CombatReach`=0.800000011920928955, `VerifiedBuild`=62876 WHERE `DisplayID`=106631;
UPDATE `creature_model_info` SET `BoundingRadius`=0.865084528923034667, `CombatReach`=0.375, `VerifiedBuild`=62876 WHERE `DisplayID` IN (103842, 103841);
UPDATE `creature_model_info` SET `BoundingRadius`=0.175450429320335388, `VerifiedBuild`=62876 WHERE `DisplayID`=108827;
UPDATE `creature_model_info` SET `BoundingRadius`=0.542733669281005859, `VerifiedBuild`=62876 WHERE `DisplayID`=100338;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=10, `VerifiedBuild`=62876 WHERE `DisplayID`=90866;
UPDATE `creature_model_info` SET `BoundingRadius`=1.954756975173950195, `CombatReach`=1.27500009536743164, `VerifiedBuild`=62876 WHERE `DisplayID`=90732;
UPDATE `creature_model_info` SET `BoundingRadius`=1.776800870895385742, `CombatReach`=3.499999761581420898, `VerifiedBuild`=62876 WHERE `DisplayID`=109315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID` IN (48011, 84505);
UPDATE `creature_model_info` SET `BoundingRadius`=3.128043651580810546, `VerifiedBuild`=62876 WHERE `DisplayID`=66835;
UPDATE `creature_model_info` SET `BoundingRadius`=1.604452252388000488, `VerifiedBuild`=62876 WHERE `DisplayID`=64629;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028736352920532226, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID`=61928;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID`=112725;
UPDATE `creature_model_info` SET `BoundingRadius`=1.111697077751159667, `VerifiedBuild`=62876 WHERE `DisplayID` IN (63606, 63607);
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044, `VerifiedBuild`=62876 WHERE `DisplayID`=118402;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288985848426818847, `CombatReach`=2, `VerifiedBuild`=62876 WHERE `DisplayID` IN (92767, 93172);
UPDATE `creature_model_info` SET `BoundingRadius`=0.938599944114685058, `CombatReach`=3.899999856948852539, `VerifiedBuild`=62876 WHERE `DisplayID`=83258;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955, `VerifiedBuild`=62876 WHERE `DisplayID`=70663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.366332471370697021, `VerifiedBuild`=62876 WHERE `DisplayID`=101743;
UPDATE `creature_model_info` SET `BoundingRadius`=1.805753946304321289, `VerifiedBuild`=62876 WHERE `DisplayID` IN (62207, 26566);
UPDATE `creature_model_info` SET `BoundingRadius`=0.519897818565368652, `VerifiedBuild`=62876 WHERE `DisplayID`=101022;
UPDATE `creature_model_info` SET `BoundingRadius`=1.042681217193603515, `VerifiedBuild`=62876 WHERE `DisplayID`=68393;
UPDATE `creature_model_info` SET `BoundingRadius`=2.085362434387207031, `VerifiedBuild`=62876 WHERE `DisplayID`=64328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.473002493381500244, `CombatReach`=0.33000001311302185, `VerifiedBuild`=62876 WHERE `DisplayID`=116507;
UPDATE `creature_model_info` SET `BoundingRadius`=1.437936067581176757, `VerifiedBuild`=62876 WHERE `DisplayID`=69234;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID` IN (64954, 89310, 79077, 88826);
UPDATE `creature_model_info` SET `BoundingRadius`=0.954134941101074218, `VerifiedBuild`=62876 WHERE `DisplayID` IN (69471, 69536);
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=9, `VerifiedBuild`=62876 WHERE `DisplayID`=67130;
UPDATE `creature_model_info` SET `BoundingRadius`=1.495757341384887695, `CombatReach`=1, `VerifiedBuild`=62876 WHERE `DisplayID`=90741;
UPDATE `creature_model_info` SET `BoundingRadius`=4.071453094482421875, `CombatReach`=5.800000667572021484, `VerifiedBuild`=62876 WHERE `DisplayID`=90723;
UPDATE `creature_model_info` SET `BoundingRadius`=4.515233993530273437, `VerifiedBuild`=62876 WHERE `DisplayID`=61622;
UPDATE `creature_model_info` SET `BoundingRadius`=0.985639452934265136, `VerifiedBuild`=62876 WHERE `DisplayID` IN (28515, 88817);
UPDATE `creature_model_info` SET `BoundingRadius`=0.153734982013702392, `VerifiedBuild`=62876 WHERE `DisplayID`=89348;
UPDATE `creature_model_info` SET `BoundingRadius`=0.344117641448974609, `VerifiedBuild`=62876 WHERE `DisplayID`=89361;
UPDATE `creature_model_info` SET `BoundingRadius`=3.028752803802490234, `VerifiedBuild`=62876 WHERE `DisplayID`=77554;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=62876 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.975292801856994628, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID`=84924;
UPDATE `creature_model_info` SET `BoundingRadius`=9.030467987060546875, `VerifiedBuild`=62876 WHERE `DisplayID`=89133;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID` IN (72564, 87571, 47995, 87573, 87572, 87574);
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID` IN (89018, 48010);
UPDATE `creature_model_info` SET `BoundingRadius`=0.465000003576278686, `VerifiedBuild`=62876 WHERE `DisplayID`=82274;
UPDATE `creature_model_info` SET `BoundingRadius`=0.340000003576278686, `CombatReach`=1.5, `VerifiedBuild`=62876 WHERE `DisplayID`=86790;
UPDATE `creature_model_info` SET `BoundingRadius`=0.618137657642364501, `CombatReach`=0.625, `VerifiedBuild`=62876 WHERE `DisplayID`=80306;
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=62876 WHERE `DisplayID`=81646;
UPDATE `creature_model_info` SET `BoundingRadius`=0.985639452934265136, `CombatReach`=1, `VerifiedBuild`=62876 WHERE `DisplayID`=88816;
UPDATE `creature_model_info` SET `BoundingRadius`=0.973670184612274169, `VerifiedBuild`=62876 WHERE `DisplayID`=71273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.52041703462600708, `CombatReach`=0.73499995470046997, `VerifiedBuild`=62876 WHERE `DisplayID`=120068;
UPDATE `creature_model_info` SET `BoundingRadius`=1.316326498985290527, `CombatReach`=1.096938729286193847, `VerifiedBuild`=62876 WHERE `DisplayID`=1100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.979709923267364501, `CombatReach`=1.724999904632568359, `VerifiedBuild`=62876 WHERE `DisplayID`=66588;
UPDATE `creature_model_info` SET `BoundingRadius`=0.384999990463256835, `CombatReach`=1.65000009536743164, `VerifiedBuild`=62876 WHERE `DisplayID`=119182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.262499988079071044, `CombatReach`=0.375, `VerifiedBuild`=62876 WHERE `DisplayID`=35804;

UPDATE `quest_visual_effect` SET `VerifiedBuild`=63163 WHERE (`Index`=0 AND `ID` IN (290863,431727,430525,429835,427035,423863,423862,423861,428709,434674,434673,445159,445158,436834,433262,429829,430648,449217,449216,449215,428874,428873,428872,448482,430914,430926,430920,449040,449028,434921,434920,434919,430893,430890,292571,449908,449906,431589,432307,456284,456942)) OR (`Index`=1 AND `ID` IN (427035,423863,423862,428709,445158,436834,433262,449217,449216,430914,430926,434921,434920)) OR (`Index`=3 AND `ID` IN (423863,433262,449217,430914)) OR (`Index`=2 AND `ID` IN (423863,433262,449217,430914,434921));
UPDATE `quest_visual_effect` SET `VerifiedBuild`=63305 WHERE (`ID`=281597 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=62876 WHERE (`Index`=0 AND `ID` IN (387247,342093,341096,341024,340437,337935,338355,338383,335976,337628,341704,336598,296286,388096,387917,387916,336552,341072,341117,341060,295504,295503,337757,338536,338211,337078,335874,341206,335630,335416,333390,333125,333107,289127,289856,289700,289314,288975,288973,288778,287730,287176,286309,282717,284226,282463,282462,285072,285037,282146,284857,284856,282433,283523,283502,283500,283390,283163,283031,283198,282025,281859,281804,281634,280633,280585)) OR (`Index`=1 AND `ID` IN (338536,335630,335416,333390,287730,287176,286309,282717,284857)) OR (`Index`=2 AND `ID` IN (333390,286309,284857)) OR (`Index`=3 AND `ID`=284857);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=63163 WHERE (`Idx`=0 AND `GameObjectEntry` IN (562348,507470,411930,423978,461482,416310,451327,415584,411623,425875,423979,424343,532318,517405,532323,532322,532321,532317,517407,517410));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=62876 WHERE (`Idx`=0 AND `GameObjectEntry` IN (454189,423978,423977,416310,469901,532323,532322,532321,532318,532317,517405,517407,517410,507470,411624,411623,425875,307066,279388,281105,281104,281103,424343,423979,499022)) OR (`Idx`=10 AND `GameObjectEntry`=499022) OR (`Idx`=9 AND `GameObjectEntry`=499022) OR (`Idx`=8 AND `GameObjectEntry`=499022) OR (`Idx`=7 AND `GameObjectEntry`=499022) OR (`Idx`=6 AND `GameObjectEntry`=499022) OR (`Idx`=5 AND `GameObjectEntry`=499022) OR (`Idx`=4 AND `GameObjectEntry`=499022) OR (`Idx`=3 AND `GameObjectEntry`=499022) OR (`Idx`=2 AND `GameObjectEntry`=499022) OR (`Idx`=1 AND `GameObjectEntry`=499022);
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63305 WHERE (`Idx`=0 AND `GameObjectEntry` IN (411930,424343,423978,423979,411623,252692,250240,246266,250239,247412,251046,251034,251035,246702,249000,247023,249345,251774,245507,266103,247050,247609,250576,266619,249729,250417,244824,245368,249464,249467,240346,250096,250095,250093,239745,246127,289645,105176,177794,323537,208875,208867,2910,2912,202467,202478,202477,201924,205421,205416,203228,206835,206832,206834,377081,376412,378780,378474,376501,376368,374994,203969,469901,507470,532323,532322,532321,532318,532317,517405,517407,517410));

DELETE FROM `page_text` WHERE `ID` IN (9818 /*9818*/, 9817 /*9817*/, 9816 /*9816*/, 9815 /*9815*/, 9814 /*9814*/, 9813 /*9813*/, 9812 /*9812*/, 9811 /*9811*/, 9810 /*9810*/, 9809 /*9809*/, 9808 /*9808*/, 9807 /*9807*/, 9806 /*9806*/, 9805 /*9805*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(9818, '<This page has the last remnants of legible writing on it. It\'s clear that whoever was writing this likely used pieces of charcoal, as most of the words are smudged badly. Some words are also written in a crimson-brown, along with a few splotches on the page and smell faintly metallic.>\n\nDuke is gone. The crew is gone. Everyone is gone.\nAnd I-\n\n-but the song. I can near hear it now. When I sleep it\'s louder. It\'s calling, a sweet gentle song, just like Esther would sing. The isle itself-\n\n-find it I will. followed the song and dug till my hands bled-\n\n-ond it. A door-\n\n-ories were true- all of them...\n\n<The rest of the page is illegible and covered in a dark stain.>', 0, 0, 0, 62876), -- 9818
(9817, '<The next sentence seems to be written so shakily it\'s hard to make out the letters.>\n\n-gone. They\'re all GONE. I was up in the the sleeping quarters making the lunch since it was my turn and- there was this loud bang or screech or-\n\n<The sentence seems to trail off.>\n\nI... don\'t know. They are all gone. Like they were never here to begin with. I must have ran over this entire island looking for them. I... put some stakes out back in the graveyard just in case but, they can\'t just have just...disappeared. That doesn\'t make any sense. Even all their bags and tools are still there an-\n\n-to leave. Can\'t stay. The isle is coming for me next.\n\nThe Duke ran off when the bang happened. Ain\'t seen him since. I can\'t go back. Found a cave on the windward side of Tempest\'s Crest. Running outta supplies to write with.\n\nI must survive. The ship will be here soon.\n\nKrolusks are prowl\'n outside. Ate one yesterday, and I can feel their eyes watching me.', 9818, 0, 0, 62876), -- 9817
(9816, '<Dirt makes the next entry hard to read, along with shaky handwriting.>\n\n-happened so fast. One minute I\'m swinging a pickaxe, next a giant rock hand crushes the poor Ashvane bloke next to me. A monstrosity like I never seen before... and made of Azerite no less! Killed over half the people we had left before we backed it into that cave. The Overseer\'s quick thinking is all that saved the rest of us what with the explosives we threw at it. Caved in the mound on it, seas take it. There are less than a handful of us left now. Thank the sea Minnow, Wiggins and Lesa made it out safe. Dunno what I\'d do without \'em at this point...\n\n-buried. Not much left, but it felt wrong not to have anything. Spirits are at an all-time low it seems-', 9817, 0, 0, 62876), -- 9816
(9815, 'The longer we stay on this forsaken isle the more strained things seem to be getting between us and the remaining Ashvane. Had to break up several fights over the last few days, an that brute Fently only seems to fan the flames. Even The Duke doesn\'t seem to like\'em an\' that\'s a telling sign to me. Still, they\'re-', 9816, 0, 1, 62876), -- 9815
(9814, '<It seems like a fair amount of time has passed between entries.>\n\nBeen mining for what feels like ages. We even used what timbers we had to build a makeshift living space for those of us left. Seemed a better idea to chance it with them -what did that Ashvane call\'em... wyverns I think- than down near the shores when the storm rolls in. We even repurposed the crow\'s nest up on Tempest\'s Crest to watch for the return ship. Nothing yet though...', 9815, 0, 0, 62876), -- 9814
(9813, '<The writing on this page seems a bit shaky.>\n\n-even know where to begin. With the fallout of the storm not only did we have to cannibalize my dear Maiden\'s Whisper, but with all the azerite there ain\'t enough space for us all to go back on the one remaining vessel. And with another storm on the horizon we...drew lots. I was one of the unlucky ones \'selected\' to stay behind and help mine the small lot of azerite that\'s left. Most of the crew decided to go, but bless their hearts Wiggins, Lesa and Minnow all stayed. The Duke too. \"We\'ll be back fer ya\" they say. I...wish I could believe that to be true.\n\nEsther give me strength.', 9814, 0, 1, 62876), -- 9813
(9812, '-ast smashed to pieces by the storm! Came outta nowhere, an my poor Maiden\'s Wh-\n\n-reckons we should repair with what little we have. Most of the timbers are ruined an there is precious little on this island we can get to that\'s not near those flying beasts. The railway timbers aren\'t seaworthy so there\'s no options left. Still, Lesa has the right of it. If we have enough to repair the other ship th-\n\n<The rest of the page is illegible.>', 9813, 0, 0, 62876), -- 9812
(9811, 'Told them, I did. Something about this place just ain\'t right. Las night Wiggans came running over all in a huff about some golden man or some such. Them Ashvane reckoned he\'s taken leave of his senses, but I believe him. I\'ve know Wiggins for years an he ain\'t a coward, an he\'s the least superstitious of us. If he saw something then there\'s something out there...\n\n<Blotches in various parts of the page make it hard to read.>\n-e lost so many in the storm- plucked right off the deck. Crawled right up out of the ocean an\' up the boats they did. Terrors I haven\'t seen the likes of before- crabs as big as the hull, giant serpent-like bugs - and the wailing! If I wasn\'t convince this isle is bad news, I certainly believe now.', 9812, 0, 1, 62876), -- 9811
(9810, '<A large ink smudge covers the next few sentences.>\n\n-starting to wonder if the old tales about this place were true. Minnow was out yesterday and said they spotted sirens off the shore. Not a huge surprise given the name of this place, but similar to the other creatures they seem more wary of us. With the other wildlife acting the way it does, it\'s down right eerie...almost like they\'re waiting for something...', 9811, 0, 0, 62876), -- 9810
(9809, 'There\'s something right unnatural about this isle. Even as the forest starts to thin, still seems to me that things are too still. The flying beasts even seem to keep their distance, unless one o\' those Ashvane get too close. Unfortunately we\'ve lost a few of them that way. At least the krolusks are manageable, but even they seem to have a certain wariness and intelligence about them I ain\'t ever seen in the ones back in Boralus. It\'s a bit unnerving to have one o\' them stare you down with those glinting eyes in the night. Just...watching...waiting it seems like. I ain\'t never seen The Duke so on edge. I\'ve suggested we place scouts, an\' the Ashvane seemed to agree thank the seas.', 9810, 0, 1, 62876), -- 9809
(9808, '-scout reported back- wells of azerite they say! We began offloading the supplies and chopping the timbers. A bit sad to see the trees fall, but that\'s the price of progress I suppose. One o\' the Overseers...Katya I think her name was, began planning a railway type system to get from the azerite to the ships so we don\'t have to haul it all on our backs. A right smart lass she is, but a bit mean too. Seems to be the way with these Ashvane folk, but I shouldn\'t be casting stones as Esther would say.', 9809, 0, 0, 62876), -- 9808
(9807, '<The first legible entry seems to be near the middle of the page.>\n\n-s fair skies for such a strange place. For such a small isle, it\'s covered in a dense forest. Even from the boat I don\'t think any wind rustles through those trees. It seems to me like the whole isle is holding its breath, but for what I couldn\'t say.\n---\nWe went to set anchor in the sheltered bay on the leeward side but was greeted by a graveyard of other ships. An ill omen to be sure, and none too friendly for docking. We managed to navigate to the windward side and as promised we landed her on the beach head with the other ship-\n\n<A watery stain has blurred much of the ink together.>', 9808, 0, 1, 62876), -- 9807
(9806, '<Part of the next entry is smudged.>\n\n-en my job to reassure the crew, and I understand the doubt but we\'ve been paid hefty coin for this venture. My mates are some of the best on the seas and if anyone can get these Ashvane where they want to go it\'s my crew. Still I feel uneasy trying to find this isle. Even if there is that azermite or whatever rock out there. I don\'t reckon it\'s worth the risk, what with all the stories. But mayhaps I should be more like Minnow; they were givin\'n me an\' Lesa a hard time for be\'n \'superstitious old fogies\'. That got a good laugh outta the crew. I reckon Minnow ain\'t more than a decade younger than Lesa, and you should have seen the face Lesa made. It had Minnow runn\'n  for the mast!', 9807, 0, 0, 62876), -- 9806
(9805, 'I ain\'t trying to claim I\'ll be any good at this, but I promised my beloved Esther I would try, bless her heart. I never really put pen to paper before, but now\'s as good a time as any I suppose. \'It\'ll help you sort your thoughts while out at sea\' she said. Ah, I hope she\'s doing well an\' those gulls aren\'t given\' her too much of a bother.\n\n As it stands, I\'ve been gone for months an\' I hope after this last shipment we\'ll be headed home. These Ashvane are a tough lot, an\' I\'m not sure it was a right good idea to help them on this venture, but here we are.', 9806, 0, 0, 62876); -- 9805

SET NAMES 'latin1';
