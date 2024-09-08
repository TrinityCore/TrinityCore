-- 
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=16 AND `Entry` IN (214608,214441,214020,214012,213390,213143,211306,210512,210261,210231,209800,209789,209333,209090,208478,208461,208459,208445,208367,208365,208363,207800,207796,207341,206187,206172,205478,205327,204931,203832,203812,203230,202971,202969,202824,202815,202814,202668,202375,202167,202155,201934,201774,201773,201754,201668,201579,201320,201261,200943,200927,200926,200918,200913,200912,200840,200836,199812,199703,199659,199549,199547,199224,198370,197671,197298,197278,197145,195000,194991,194990,194647,193760,193413,192934,191856,191714,191510,191448,191232,191230,191225,191222,191215,191206,190690,190688,190686,190588,190586,190496,190245,189813,189492,189234,188026,187967,187772,187771,187768,187767,187638,187593,185863,185005,184986,184972,184792,184746,184622,184522,184415,184143,184140,184126,183992,183974,183945,183870,183840,183839,183787,183745,183707,183697,183688,183672,183637,183501,183409,183320,183138,182822,182778,182777,182311,182305,182169,182074,182071,182053,182045,181859,181856,181850,181551,181549,181548,181546,181399,181398,181395,181244,181224,181047,181011,180990,180906,180840,180773,180543,180474,180473,180323,180209,180172,180076,180069,179963,179935,179934,179927,179917,179847,179597,179177,179124,179010,178550,178506,178378,178335,177668,177594,177289,177287,177268,177240,177117,177104,177095,177094,177045,176974,176973,176929,176703,176605,176581,176531,176523,176311,176129,176128,176026,176016,175861,175731,175730,175729,175728,175727,175726,175725,175611,175559,175474,174878,174842,174335,174162,174161,173568,173546,173484,173469,173466,173464,173448,173434,173298,173280,173276,173178,173175,173120,173119,172877,172858,172145,171990,171801,171577,171557,171287,170710,170404,170200,170199,170197));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(214608, 16, 9, 8, 1, 265609, 2097256, 128), -- Screaming Soul
(214441, 16, 9, 3.75, 1, 264013, 2097160, 128), -- Scorched Treant
(214020, 16, 9, 60, 1, 263438, 18874376, 144), -- Manifested Monarch
(214012, 16, 9, 50.40000152587890625, 1, 263426, 2097256, 128), -- Dark Colossus
(213390, 16, 9, 300, 1, 262785, 2097224, 0), -- Pip
(213143, 16, 9, 16, 1, 262543, 2097256, 65664), -- Manifested Dream
(211306, 16, 9, 3.460000038146972656, 1, 261043, 2097224, 132), -- Fiery Vines
(210512, 16, 9, 2, 1, 262214, 2101320, 128), -- Ashen Treant
(210261, 16, 9, 1, 1, 265499, 1610613776, 134), -- Flame Orb
(210231, 16, 9, 3.5, 1, 263606, 2097160, 128), -- Tainted Lasher
(209800, 16, 9, 22, 1, 240117, 2097224, 144), -- Cycle Warden
(209789, 16, 9, 1, 1, 240101, 18874376, 144), -- Nascent Preserver
(209333, 16, 9, 560, 1, 262366, 2097260, 128), -- Gnarlroot
(209090, 16, 9, 734.4000244140625, 1, 262230, 2097228, 128), -- Tindral Sageswift
(208478, 16, 9, 610, 1, 260216, 2097228, 128), -- Volcoross
(208461, 16, 9, 12, 1, 262218, 2101320, 128), -- Scorching Roots
(208459, 16, 9, 10, 1, 262208, 2101320, 128), -- Fiery Treant
(208445, 16, 9, 810, 1, 262204, 2097260, 128), -- Larodar, Keeper of the Flame
(208367, 16, 9, 310, 1, 260684, 2097260, 128), -- Pip
(208365, 16, 9, 310, 1, 260683, 2097260, 128), -- Aerwynn
(208363, 16, 9, 310, 1, 260685, 2097260, 128), -- Urctos
(207800, 16, 9, 0.95999997854232788, 1, 263187, 2101368, 67108992), -- Spirit of the Kaldorei
(207796, 16, 9, 50.40000152587890625, 1, 263207, 2097256, 128), -- Burning Colossus
(207341, 16, 9, 2, 1, 261797, 0, 128), -- Blistering Spear
(206187, 16, 9, 1, 1, 235405, 16778240, 144), -- Dream Tether
(206172, 16, 9, 709, 1, 262938, 2097260, 128), -- Nymue
(205478, 16, 9, 35, 1, 234849, 2097224, 0), -- Conduit Guardian
(205327, 16, 9, 3, 1, 263202, 2097256, 128), -- Raging Ember
(204931, 16, 9, 1120, 1, 264610, 2097260, 69760), -- Fyrakk
(203832, 16, 9, 1, 1, 234144, 1073741824, 128), -- Dread Rift
(203812, 16, 9, 42.75, 1, 234236, 2097224, 128), -- Voice From Beyond
(203230, 16, 9, 5, 1, 233881, 128, 16512), -- Dragonfire Golem
(202971, 16, 9, 8, 1, 234894, 2097224, 128), -- Null Glimmer
(202969, 16, 9, 25, 1, 234890, 2097224, 128), -- Empty Recollection
(202824, 16, 9, 2, 1, 234944, 16777216, 144), -- Erratic Remnant
(202815, 16, 9, 1, 1, 231831, 2097256, 128), -- Void Bomb
(202814, 16, 9, 7, 1, 234232, 2097160, 144), -- Twisted Aberration
(202668, 16, 9, 1, 1, 235086, 2097256, 128), -- Astral Formation
(202375, 16, 9, 580, 1, 234081, 2097228, 128), -- Zskarn
(202167, 16, 9, 1, 1, 234146, 1075839080, 8388736), -- Ray of Anguish
(202155, 16, 9, 1, 1, 231827, 2097256, 128), -- Scorching Bomb
(201934, 16, 9, 630, 1, 234171, 2097228, 128), -- Shadowflame Amalgamation
(201774, 16, 9, 260, 1, 234166, 2097228, 128), -- Essence of Shadow
(201773, 16, 9, 260, 1, 234169, 2097228, 128), -- Eternal Blaze
(201754, 16, 9, 860, 1, 233716, 2097228, 65664), -- Sarkareth
(201668, 16, 9, 741, 1, 234228, 2097228, 128), -- Neltharion
(201579, 16, 9, 770, 1, 234922, 2097228, 128), -- Magmorax
(201320, 16, 9, 839.29998779296875, 1, 234375, 2097228, 128), -- Rashok
(201261, 16, 9, 540, 1, 234283, 2097228, 67108992), -- Kazzara, the Hellforged
(200943, 16, 9, 25.5, 1, 229519, 2097256, 65664), -- Electrified Colossal Stormfiend
(200927, 16, 9, 1215, 1, 263548, 2097260, 128), -- Smolderon
(200926, 16, 9, 715, 1, 261255, 2097260, 128), -- Igira the Cruel
(200918, 16, 9, 200, 1, 233908, 2097228, 128), -- Rionthus
(200913, 16, 9, 200, 1, 233907, 2097228, 128), -- Thadrion
(200912, 16, 9, 200, 1, 233906, 2097228, 128), -- Neldris
(200840, 16, 9, 12, 1, 234095, 2097224, 128), -- Flamebound Huntsman
(200836, 16, 9, 13, 1, 234091, 2097216, 4224), -- Obsidian Guard
(199812, 16, 9, 8, 1, 234097, 270532680, 128), -- Zaqali Wallclimber
(199703, 16, 9, 5.90000009536743164, 1, 234313, 2097224, 128), -- Magma Mystic
(199659, 16, 9, 248, 1, 234320, 2097228, 65664), -- Warlord Kagni
(199549, 16, 9, 5.599999904632568359, 1, 228004, 2097256, 65664), -- Flamesworn Herald
(199547, 16, 9, 6.75, 1, 227998, 2097256, 65664), -- Frostforged Zealot
(199224, 16, 9, 25, 1, 227649, 16778240, 144), -- Thunderstorm
(198370, 16, 9, 60, 1, 226745, 2097256, 65664), -- Concentrated Storm
(197671, 16, 9, 21.60000038146972656, 1, 226020, 2097224, 128), -- Volatile Infuser
(197298, 16, 9, 7.75, 1, 230028, 6291560, 128), -- Nascent Proto-Dragon
(197278, 16, 9, 25, 1, 225613, 16778240, 144), -- Thunderstorm
(197145, 16, 9, 25.5, 1, 226076, 2097256, 65664), -- Colossal Stormfiend
(195000, 16, 9, 25, 1, 223236, 16778240, 144), -- Rushing Winds Helper
(194991, 16, 9, 5.40000009536743164, 1, 227073, 2097256, 65664), -- Oathsworn Vanguard
(194990, 16, 9, 3.779999971389770507, 1, 227069, 2097256, 65664), -- Stormseeker Acolyte
(194647, 16, 9, 9.5, 1, 224983, 2097224, 128), -- Thunder Caller
(193760, 16, 9, 11.25, 1, 227065, 2097256, 65664), -- Surging Ruiner
(193413, 16, 9, 25, 1, 221632, 16778240, 144), -- Thunderstorm
(192934, 16, 9, 21.60000038146972656, 1, 221947, 2097224, 128), -- Volatile Infuser
(191856, 16, 9, 25, 1, 220120, 16778240, 144), -- Raging Tempest
(191714, 16, 9, 3.40000009536743164, 1, 227034, 2097256, 128), -- Seeking Stormling
(191510, 16, 9, 4, 1, 230031, 2097256, 129), -- Smoldering Hellion
(191448, 16, 9, 1, 1, 225742, 2097224, 128), -- Greatstaff of the Broodkeeper
(191232, 16, 9, 20.12999916076660156, 1, 224779, 6291528, 128), -- Drakonid Stormbringer
(191230, 16, 9, 18.07999992370605468, 1, 224777, 6291528, 128), -- Dragonspawn Flamebender
(191225, 16, 9, 22.8600006103515625, 1, 224775, 6291528, 128), -- Tarasek Earthreaver
(191222, 16, 9, 25.97999954223632812, 1, 224778, 6291528, 128), -- Juvenile Frost Proto-Dragon
(191215, 16, 9, 6.820000171661376953, 1, 225561, 6291528, 128), -- Tarasek Legionnaire
(191206, 16, 9, 4.119999885559082031, 1, 225557, 6291528, 128), -- Primalist Mage
(190690, 16, 9, 76, 1, 228192, 2097256, 129), -- Thundering Ravager
(190688, 16, 9, 76, 1, 228191, 2097256, 129), -- Blazing Fiend
(190686, 16, 9, 76, 1, 228190, 2097256, 129), -- Frozen Destroyer
(190588, 16, 9, 76, 1, 228189, 2097256, 129), -- Tectonic Crusher
(190586, 16, 9, 6, 1, 230029, 2097256, 129), -- Earth Breaker
(190496, 16, 9, 610, 1, 227984, 2097228, 128), -- Terros
(190245, 16, 9, 672.9000244140625, 1, 226287, 2097228, 128), -- Broodkeeper Diurna
(189813, 16, 9, 582, 1, 224928, 2097228, 128), -- Dathea, Ascended
(189492, 16, 9, 938.5, 1, 226069, 2097228, 65664), -- Raszageth
(189234, 16, 9, 28, 1, 229785, 2097224, 128), -- Frostbreath Arachnid
(188026, 16, 9, 2, 1, 226443, 64, 128), -- Frost Tomb
(187967, 16, 9, 595, 1, 227335, 2099276, 65664), -- Sennarth
(187772, 16, 9, 205, 1, 224094, 2097228, 128), -- Opalfang
(187771, 16, 9, 205, 1, 224102, 2097260, 128), -- Kadros Icewrath
(187768, 16, 9, 205, 1, 224106, 2097260, 128), -- Dathea Stormlash
(187767, 16, 9, 205, 1, 224098, 2097260, 128), -- Embar Firepath
(187638, 16, 9, 3, 1, 227873, 0, 128), -- Flamescale Tarasek
(187593, 16, 9, 10, 1, 229973, 72, 128), -- Primal Flame
(185863, 16, 8, 1, 1, 210154, 1610612752, 134), -- Ephemeral Mote
(185005, 16, 8, 20, 1, 209130, 2097256, 128), -- Anduin's Grief
(184986, 16, 9, 580, 1, 227593, 2097260, 65665), -- Kurog Grimtotem
(184972, 16, 9, 270, 1, 227865, 2097228, 128), -- Eranog
(184792, 16, 8, 9.5, 1, 208872, 2099304, 128), -- Cartel Overseer
(184746, 16, 8, 5.25, 1, 208808, 2099304, 128), -- Cartel Plunderer
(184622, 16, 8, 6, 1, 208790, 2097256, 128), -- Incarnation of Torment
(184522, 16, 8, 45.29925155639648437, 1, 211386, 2097352, 128), -- Vigilant Custodian
(184415, 16, 7, 3, 1, 208462, 1612709976, 6), -- Sinful Projection
(184143, 16, 8, 65.5, 1, 208049, 2088, 67108992), -- Hyperlight Archon
(184140, 16, 8, 14.5, 1, 208042, 2088, 128), -- Xy Acolyte
(184126, 16, 8, 26, 1, 213631, 2097224, 128), -- Defense Matrix Automa
(183992, 16, 8, 4.194373607635498046, 1, 211383, 2097352, 128), -- Automated Defense Matrix
(183974, 16, 8, 5.25, 1, 207870, 2099304, 128), -- Cartel Plunderer
(183945, 16, 8, 5.25, 1, 208927, 2097224, 128), -- Unstable Matter
(183870, 16, 8, 7.5, 1, 209568, 0, 128), -- Engine Core
(183840, 16, 8, 15, 1, 207728, 2099304, 128), -- Hyperlight Curator
(183839, 16, 8, 5.25, 1, 207723, 2099304, 128), -- Cartel Plunderer
(183787, 16, 8, 18, 1, 207698, 2097224, 0), -- Harbinger of Oblivion
(183745, 16, 8, 18, 1, 213622, 1075839048, 128), -- Protoform Schematic
(183707, 16, 8, 9.199999809265136718, 1, 207567, 2099304, 128), -- Xy Spellslinger
(183697, 16, 8, 15, 1, 207553, 2099304, 128), -- Hyperlight Curator
(183688, 16, 8, 3, 1, 207540, 2097184, 128), -- Stasis Trap
(183672, 16, 8, 240, 1, 207521, 2097260, 0), -- Remornia
(183637, 16, 8, 10000, 1, 214611, 1073741824, 128), -- Azeroth
(183501, 16, 8, 430, 1, 208917, 270532716, 65664), -- Artificer Xy'mox
(183409, 16, 8, 2.349999904632568359, 1, 207238, 2097224, 67108992), -- Pinning Weapon
(183320, 16, 8, 1.799999952316284179, 1, 207139, 2097256, 128), -- Exploding Corpse
(183138, 16, 8, 10, 1, 207655, 2097224, 128), -- Inchoate Shadow
(182822, 16, 8, 5.52500009536743164, 1, 208994, 2101484, 128), -- Withering Seed
(182778, 16, 8, 1.10000002384185791, 1, 208921, 2097224, 128), -- Collapsing Quasar
(182777, 16, 8, 623.29498291015625, 1, 208576, 2097260, 128), -- Rygelon
(182311, 16, 8, 18.87470054626464843, 1, 211385, 2097352, 128), -- Pre-Fabricated Sentry
(182305, 16, 8, 0.200000002980232238, 1, 206118, 2097256, 128), -- Ascended Projection
(182169, 16, 8, 520, 1, 210013, 2097260, 128), -- Lihuvim
(182074, 16, 8, 15, 1, 213637, 2101320, 128), -- Acquisitions Automa
(182071, 16, 8, 20, 1, 213634, 2097224, 128), -- Guardian Automa
(182053, 16, 8, 7, 1, 213628, 2097256, 128), -- Degeneration Automa
(182045, 16, 8, 8.399999618530273437, 1, 205847, 2097256, 128), -- Necrotic Ritualist
(181859, 16, 8, 5, 1, 209595, 2097224, 128), -- Volatile Materium
(181856, 16, 8, 5.872122764587402343, 1, 209596, 2097352, 128), -- Point Defense Drone
(181850, 16, 8, 18.87467765808105468, 1, 211384, 2097352, 128), -- Pre-Fabricated Sentry
(181551, 16, 8, 191.25, 1, 208980, 270532716, 65664), -- Prototype of Duty
(181549, 16, 8, 191.25, 1, 208976, 2097260, 65664), -- Prototype of War
(181548, 16, 8, 230.625, 1, 208984, 270532716, 65664), -- Prototype of Absolution
(181546, 16, 8, 230.625, 1, 208988, 270532716, 65664), -- Prototype of Renewal
(181399, 16, 8, 615.5999755859375, 1, 207709, 2097260, 65664), -- Kin'tessa
(181398, 16, 8, 615.5999755859375, 1, 207705, 2097260, 65664), -- Mal'Ganis
(181395, 16, 8, 536, 1, 209582, 2097260, 128), -- Skolex
(181244, 16, 8, 9, 1, 208999, 2097224, 128), -- Domination Core
(181224, 16, 8, 650, 1, 209008, 2097260, 128), -- Dausegne
(181047, 16, 8, 420, 1, 209532, 2097260, 0), -- Halondrus
(181011, 16, 8, 60, 1, 209575, 2097768, 0), -- Ancient Guardian
(180990, 16, 8, 1008, 1, 206008, 2097260, 128), -- The Jailer
(180906, 16, 8, 626.4000244140625, 1, 209528, 2097260, 65664), -- Halondrus
(180840, 16, 8, 2.5, 1, 204509, 2097224, 0), -- Frostbound Devoted
(180773, 16, 8, 576, 1, 209878, 2097260, 65664), -- Vigilant Guardian
(180543, 16, 9, 1, 1, 204859, 0, 0), -- Fate Fragment
(180474, 16, 8, 7, 1, 204133, 2097224, 0), -- Soul Reaver
(180473, 16, 8, 16, 1, 204128, 2097224, 0), -- Unstoppable Abomination
(180323, 16, 8, 24, 1, 204740, 72, 128), -- Fatespawn Monstrosity
(180209, 16, 8, 10, 1, 203854, 2097224, 0), -- Ner'zhul's Lament
(180172, 16, 8, 10, 1, 203863, 0, 2), -- Tortured Soul
(180076, 16, 8, 5, 1, 203712, 538968136, 16582), -- Mr. Bigglesworth
(180069, 16, 8, 5, 1, 203701, 538968136, 16582), -- Mr. Bigglesworth
(179963, 16, 8, 0.400000005960464477, 1, 203543, 2097224, 128), -- Terror Orb
(179935, 16, 8, 50, 1, 203510, 2097224, 0), -- Baneful Whirl
(179934, 16, 8, 50, 1, 203505, 2097224, 0), -- Spinning Scourge
(179927, 16, 8, 50, 1, 203494, 0, 0), -- Spinning Scourge
(179917, 16, 8, 50, 1, 203476, 2097224, 0), -- Vortex of Suffering
(179847, 16, 8, 9, 1, 205004, 2097224, 128), -- Shadowsteel Horror
(179597, 16, 8, 5, 1, 203128, 2097260, 1), -- Boss Transform Lich
(179177, 16, 8, 18.04999923706054687, 1, 202696, 2097256, 128), -- Mawsworn Overlord
(179124, 16, 8, 11, 0, 204824, 72, 128), -- Shade of Destiny
(179010, 16, 8, 5, 1, 204958, 72, 128), -- Fatespawn Anomaly
(178550, 16, 8, 2.5, 1, 202056, 16778240, 16), -- Phylactery
(178506, 16, 8, 2, 1, 202008, 2097224, 128), -- Frostbound Devoted
(178378, 16, 8, 2.02500009536743164, 1, 201736, 2097224, 0), -- Anguished Remnant
(178335, 16, 8, 5, 1, 201641, 2097260, 1), -- Boss Transform Old
(177668, 16, 8, 5, 1, 200923, 16778240, 144), -- Pain Cone Brain
(177594, 16, 8, 16.14999961853027343, 1, 201728, 2097256, 128), -- Mawsworn Agonizer
(177289, 16, 8, 500, 1, 201482, 1075839048, 132), -- Rattlecage of Agony
(177287, 16, 8, 500, 1, 201486, 1075839048, 132), -- Malicious Gauntlet
(177268, 16, 8, 500, 1, 201490, 1075839048, 16777348), -- Helm of Suffering
(177240, 16, 8, 30, 1, 201494, 2097224, 128), -- Agent of Malevolence
(177117, 16, 8, 1.799999952316284179, 1, 201498, 2097224, 128), -- Orb of Torment
(177104, 16, 8, 5, 1, 200158, 16778240, 144), -- Pain Cone A
(177095, 16, 8, 130, 1, 203564, 2097260, 65664), -- Kyra
(177094, 16, 8, 110, 1, 203560, 2097260, 65664), -- Signe
(177045, 16, 8, 5, 1, 200083, 538968136, 16582), -- Mr. Bigglesworth
(176974, 16, 8, 7, 1, 200008, 2097256, 129), -- Soul Reaver
(176973, 16, 8, 16, 1, 200003, 2097256, 129), -- Unstoppable Abomination
(176929, 16, 8, 65, 1, 199885, 2097260, 129), -- Remnant of Kel'Thuzad
(176703, 16, 8, 2.5, 1, 199655, 2097256, 128), -- Frostbound Devoted
(176605, 16, 8, 2.25, 1, 199603, 16778240, 144), -- Soul Shard
(176581, 16, 8, 5.849999904632568359, 1, 204771, 2097224, 67113090), -- Spiked Ball
(176531, 16, 8, 47.20000076293945312, 1, 203487, 2097260, 128), -- Deathseeker Eye
(176523, 16, 8, 459, 1, 204770, 2097260, 128), -- Painsmith Raznal
(176311, 16, 8, 15, 1, 200140, 2097224, 0), -- Hand of the Jailer
(176129, 16, 8, 12, 1, 198778, 2097256, 128), -- Stone Legion Skirmisher
(176128, 16, 8, 10, 1, 198775, 2097224, 0), -- Stone Legion Commando
(176026, 16, 8, 22.5, 1, 199574, 0, 0), -- Dancing Fools
(176016, 16, 8, 20, 1, 198683, 0, 0), -- Waltzing Venthyr
(175861, 16, 8, 6, 1, 198508, 16778240, 144), -- Glacial Spike
(175731, 16, 8, 560, 1, 203273, 2097260, 65664), -- Guardian of the First Ones
(175730, 16, 8, 490, 0, 204222, 2097260, 65664), -- Fatescribe Roh-Kalo
(175729, 16, 8, 418, 1, 201502, 2097260, 65664), -- Remnant of Ner'zhul
(175728, 16, 8, 500, 1, 202260, 2097260, 65664), -- Garrosh Hellscream
(175727, 16, 8, 580, 1, 201083, 270532716, 65664), -- Soulrender Dormazain
(175726, 16, 8, 365, 1, 201795, 2097260, 65664), -- Skyja
(175725, 16, 8, 318, 1, 202713, 2097260, 65664), -- Eye of the Jailer
(175611, 16, 8, 700, 1, 202112, 2097260, 65664), -- The Tarragrue
(175559, 16, 8, 99.75, 1, 199599, 2097260, 129), -- Kel'Thuzad
(175474, 16, 8, 2, 1, 198095, 2097224, 0), -- Belligerent Waiter
(174878, 16, 8, 2, 1, 196987, 2097224, 0), -- Belligerent Waiter
(174842, 16, 8, 2, 1, 196942, 2097224, 0), -- Belligerent Waiter
(174335, 16, 8, 13.5, 1, 196380, 2097256, 128), -- Stone Legion Skirmisher
(174162, 16, 8, 18, 1, 199590, 2097224, 0), -- Countess Gloomveil
(174161, 16, 8, 18, 1, 199591, 2097224, 0), -- Lady Sinsear
(173568, 16, 8, 6, 1, 195236, 270532680, 0), -- Anima Crazed Worker
(173546, 16, 8, 1, 1, 195210, 0, 0), -- Stone Breaker's Combo Stalker
(173484, 16, 8, 4, 1, 195144, 0, 0), -- Conjured Manifestation
(173469, 16, 8, 40, 1, 195124, 270532680, 0), -- Kullan
(173466, 16, 8, 40, 1, 195128, 270532680, 0), -- Fara
(173464, 16, 8, 40, 1, 195132, 270532680, 0), -- Deplina
(173448, 16, 8, 40, 1, 195137, 270532680, 0), -- Dragost
(173434, 16, 8, 400, 1, 195062, 2097260, 0), -- General Grashaal
(173298, 16, 8, 400, 1, 194919, 2097260, 0), -- General Kaal
(173280, 16, 8, 8, 1, 196376, 2097256, 0), -- Stone Legion Skirmisher
(173276, 16, 8, 8, 1, 194893, 2097256, 0), -- Stone Legion Commando
(173178, 16, 8, 32, 1, 194787, 2097768, 0), -- Stone Legion Goliath
(173175, 16, 8, 1, 1, 194780, 0, 0), -- Aerial Bombardment Stalker
(173120, 16, 8, 10, 1, 194719, 2097224, 0), -- General Draven
(173119, 16, 8, 10, 0.338862448930740356, 194714, 2097228, 0), -- Prince Renathal
(172877, 16, 8, 1, 1, 194431, 0, 128), -- Breath of Corruption
(172858, 16, 8, 40, 1, 194435, 2097768, 128), -- Stone Legion Goliath
(172145, 16, 8, 300, 1, 193653, 2097260, 0), -- Shriekwing
(171990, 16, 8, 2.5, 1, 193491, 2097224, 16), -- Unyielding Shield
(171801, 16, 8, 500, 1, 193277, 1075839100, 33554566), -- Hidden Desire
(171577, 16, 8, 6, 1, 193029, 2101368, 128), -- Ripped Soul
(171557, 16, 8, 184, 1, 192999, 2097256, 128), -- Shade of Bargast
(171287, 16, 8, 1, 1, 194439, 0, 0), -- Reverberating Leap Stalker
(170710, 16, 8, 1, 1, 193586, 2097224, 0), -- Sinister Reflection
(170404, 16, 8, 10, 1, 194443, 2097224, 128), -- General Draven
(170200, 16, 8, 60, 1, 191425, 0, 128), -- Focused Anima
(170199, 16, 8, 19.79999923706054687, 1, 191420, 2097160, 4224), -- Harnessed Specter
(170197, 16, 8, 9, 1, 191414, 2097160, 4224); -- Conjured Manifestation

UPDATE `creature_template_difficulty` SET `HealthModifier`=10 WHERE (`Entry`=183033 AND `DifficultyID`=16); -- Grim Reflection
UPDATE `creature_template_difficulty` SET `TypeFlags`=1610612816 WHERE (`Entry`=180803 AND `DifficultyID`=16); -- Throne of the Damned
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175481 AND `DifficultyID`=16); -- Rendle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=175200 AND `DifficultyID`=16); -- [DNT] Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174733 AND `DifficultyID`=16); -- Sludgefist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174338 AND `DifficultyID`=16); -- Stinky Feedhauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174208 AND `DifficultyID`=16); -- Court Executor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199589 WHERE (`Entry`=174134 AND `DifficultyID`=16); -- Lord Evershade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199588 WHERE (`Entry`=174126 AND `DifficultyID`=16); -- Baron Duskhollow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174100 AND `DifficultyID`=16); -- Nathrian Singuard
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174080 AND `DifficultyID`=16); -- The Blood Lantern
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174017 AND `DifficultyID`=16); -- Anima Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=174012 AND `DifficultyID`=16); -- Executrix Ophelia
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173973 AND `DifficultyID`=16); -- Nathrian Tracker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=16 AND `Entry` IN (173969,173951,173941)); -- Anima Glimmer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=195541 WHERE (`Entry`=173802 AND `DifficultyID`=16); -- Carved Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173770 AND `DifficultyID`=16); -- Blazing Brazier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173769 AND `DifficultyID`=16); -- Smoldering Brazier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173768 AND `DifficultyID`=16); -- Fiery Brazier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173767 AND `DifficultyID`=16); -- Embered Brazier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173633 AND `DifficultyID`=16); -- Nathrian Archivist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173613 AND `DifficultyID`=16); -- Nathrian Registrar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173609 AND `DifficultyID`=16); -- Nathrian Conservator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173604 AND `DifficultyID`=16); -- Sinister Antiquarian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173382 AND `DifficultyID`=16); -- Soul Pedestal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=194703 WHERE (`Entry`=173112 AND `DifficultyID`=16); -- Pierced Soul
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=173053 AND `DifficultyID`=16); -- Afterimage of Lord Stavros
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`DifficultyID`=16 AND `Entry` IN (172976,172660)); -- Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=172803 AND `DifficultyID`=16); -- Afterimage of Baroness Frieda
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=171764 AND `DifficultyID`=16); -- Left Hand Chains
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8 WHERE (`Entry`=171763 AND `DifficultyID`=16); -- Right Hand Chains

