-- 
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (87368,88869,88870,88889,88913,89002,89004,89005,89006,89017,89134,89344,89402,89663,90401,90403,90897,90898,90983,91481,91519,91553,91558,92312,92359,92367,92374,92381,92682,92685,92703,92765,93325,93468,93684,93686,93836,93846,94172,94977,95055,95078,95094,95111,95204,95259,95289,95392,95723,95724,95753,95780,95804,95859,95921,96071,96075,96076,96078,96144,96164,96314,96318,96387,96453,96506,96514,96523,96676,97064,97241,97316,97344,97352,97355,97407,97418,97442,97506,97544,97558,97661,97817,97923,98013,98015,98607,98609,98610,98717,98773,98788,98904,98934,99083,99095,99109,99137,99138,99153,99190,99219,99221,99619,99745,99746,99747,99748,99781,99782,99783,99784,100054,100223,100224,100351,100491,100578,101259,101286,101388,101651,101653,101654,101656,101657,101742,101822,101858,102259,102395,102397,102400,102728,103215,103438,103439,103444,103445,103457,103986,103991,103994,104012,104013,104043,104046,104049,104050,104535,104714,104936,104937,104968,105106,105110,105243,105294,105948,106070,106071,106073,106135,106195,106204,106981,106982,106984,107390,107391,107425,107551,107569,107593,107674,107675,107704,108069,108305,108663,109163,109189,109970,110038,110629,110630,110631,110632,110633,110634,110658,110806,111165,111336,111830,111831,111928,112310,112417,112738,112877,112902,113933,140493,140494,149486,151040,154819,207438,241725,241743,241744,242263,242265,242266,242276,242278,242280,242299,244262,249116,249118,249552,249553,249554,249555,249556,249557,249866,249867,249893,249894,249895,249896,249897,249905,249910,249915,249916,249920,249921,249924,249929,249940,249943,249944,249945,249947,249948,249952,249953)) OR (`ID`=2 AND `CreatureID` IN (91481,95055,107390,107391)) OR (`ID`=3 AND `CreatureID` IN (107390,107391)) OR (`ID`=4 AND `CreatureID` IN (107390,107391));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(87368, 1, 0, 0, 0, 95495, 0, 0, 0, 0, 0, 63834), -- Drowned Magister
(88869, 1, 13753, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Prince Farondis
(88870, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hatecoil Ambusher
(88889, 1, 13753, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Prince Farondis
(88913, 1, 37021, 0, 0, 37032, 0, 0, 0, 0, 0, 63834), -- Boss Whalebelly
(89002, 1, 13753, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Prince Farondis
(89004, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hatecoil Myrmidon
(89005, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hatecoil Myrmidon
(89006, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hatecoil Myrmidon
(89017, 1, 88553, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Okuna Longtusk
(89134, 1, 104096, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Elder Aldryth
(89344, 1, 54820, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hatecoil Myrmidon
(89402, 1, 49687, 0, 0, 40596, 0, 0, 0, 0, 0, 63834), -- Nightwatcher Idri
(89663, 1, 13612, 0, 0, 2716, 0, 0, 0, 0, 0, 63834), -- Magister Garuhod
(90401, 1, 122430, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Allari the Souleater
(90403, 1, 122430, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Allari the Souleater
(90897, 1, 88794, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Azurewing Keeper
(90898, 1, 88794, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Azurewing Keeper
(90983, 1, 128359, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kor'vas Bloodthorn
(91481, 1, 0, 0, 0, 0, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(91481, 2, 0, 0, 0, 0, 0, 0, 112340, 0, 0, 63834), -- Commander Lorna Crowley
(91519, 1, 0, 0, 0, 0, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(91553, 1, 0, 0, 0, 0, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(91558, 1, 0, 0, 0, 0, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(92312, 1, 33598, 0, 0, 0, 0, 0, 112340, 0, 0, 63834), -- Drekirjar Galeborn
(92359, 1, 81396, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Drekirjar Felblade
(92367, 1, 111373, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Tideskorn Longaxe
(92374, 1, 33598, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Drekirjar Galeborn
(92381, 1, 42920, 0, 0, 49638, 0, 0, 0, 0, 0, 63834), -- Drekirjar Shieldbearer
(92682, 1, 33544, 0, 0, 33544, 0, 0, 0, 0, 0, 63834), -- Helmouth Raider
(92685, 1, 43580, 0, 0, 34217, 0, 0, 0, 0, 0, 63834), -- Captain Brvet
(92703, 1, 33213, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Helmouth Raider
(92765, 1, 43580, 0, 0, 33220, 0, 0, 0, 0, 0, 63834), -- Torvald the Defiant
(93325, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Khadgar
(93468, 1, 109613, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Seska Seafang
(93684, 1, 55146, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Malicious Sprite
(93686, 1, 132258, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Jinikki the Puncturer
(93836, 1, 93596, 0, 0, 93596, 0, 0, 0, 0, 0, 63834), -- Torok Bloodtotem
(93846, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mayla Highmountain
(94172, 1, 34816, 0, 0, 34816, 0, 0, 0, 0, 0, 63834), -- Fallen Guardian
(94977, 1, 108924, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Commander Jarod Shadowsong
(95055, 1, 242578, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dark Manifestation
(95055, 2, 242556, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dark Manifestation
(95078, 1, 82383, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Highmountain Shaman
(95094, 1, 108924, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Commander Jarod Shadowsong
(95111, 1, 5278, 0, 0, 0, 0, 0, 15460, 0, 0, 63834), -- Hemet Nesingwary
(95204, 1, 105954, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Oubdob da Smasher
(95259, 1, 107327, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Navarrogg
(95289, 1, 127986, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Maiev Shadowsong
(95392, 1, 107327, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Navarrogg
(95723, 1, 0, 0, 0, 0, 0, 0, 114913, 0, 0, 63834), -- Ellias
(95724, 1, 0, 0, 0, 0, 0, 0, 28772, 0, 0, 63834), -- Laeni Silvershot
(95753, 1, 36606, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Deepcavern Murloc
(95780, 1, 52962, 0, 0, 52962, 0, 0, 0, 0, 0, 63834), -- Guhruhlruhlruh
(95804, 1, 46737, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Genn Greymane
(95859, 1, 65492, 0, 0, 111717, 0, 0, 0, 0, 0, 63834), -- Greywatch Guard
(95921, 1, 30147, 0, 0, 61512, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(96071, 1, 81396, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancient Ruler
(96075, 1, 107703, 0, 0, 107703, 0, 0, 0, 0, 0, 63834), -- Ancient Ruler
(96076, 1, 124548, 0, 0, 89116, 0, 0, 0, 0, 0, 63834), -- Ancient Ruler
(96078, 1, 242578, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Player Copy Controller
(96144, 1, 242578, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Player Copy Controller
(96164, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 63834), -- Spiritwalker Ebonhorn
(96314, 1, 129275, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- God-King Skovald
(96318, 1, 129899, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Huln Highmountain
(96387, 1, 133778, 0, 0, 133778, 0, 0, 0, 0, 0, 63834), -- Igrul the Scalebane
(96453, 1, 107327, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Stonedark Drogbar
(96506, 1, 58367, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Highmountain Warbrave
(96514, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mayla Highmountain
(96523, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mayla Highmountain
(96676, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 63834), -- Spiritwalker Ebonhorn
(97064, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mucksnout Scavenger
(97241, 1, 127332, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Understone Breacher
(97316, 1, 55369, 0, 0, 119725, 0, 0, 0, 0, 0, 63834), -- Rivermane Shaman
(97344, 1, 82383, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Jale Rivermane
(97352, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mayla Highmountain
(97355, 1, 55369, 0, 0, 119725, 0, 0, 0, 0, 0, 63834), -- Rivermane Shaman
(97407, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0, 63834), -- Lasan Skyhorn
(97418, 1, 128278, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Marakhan
(97442, 1, 132179, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dargrul
(97506, 1, 55369, 0, 0, 119725, 0, 0, 0, 0, 0, 63834), -- Rivermane Shaman
(97544, 1, 14487, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Bloodtotem Warmonger
(97558, 1, 124548, 0, 0, 89116, 0, 0, 0, 0, 0, 63834), -- Ashildir
(97661, 1, 2023, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mucksnout Aggressor
(97817, 1, 128808, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Highmountain Survivalist
(97923, 1, 118803, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rensar Greathoof
(98013, 1, 9477, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Zen'tabra
(98015, 1, 46837, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Sigrid
(98607, 1, 57252, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Scout Brownmane
(98609, 1, 57252, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Scout Proudhill
(98610, 1, 57252, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Scout Cloudeye
(98717, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0, 63834), -- Lasan Skyhorn
(98773, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0, 63834), -- Lasan Skyhorn
(98788, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Warbrave
(98904, 1, 14487, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Bloodtotem Warmonger
(98934, 1, 14487, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Bloodtotem Warmonger
(99083, 1, 0, 0, 0, 0, 0, 0, 82594, 0, 0, 63834), -- Pinerock Hunter
(99095, 1, 0, 0, 0, 0, 0, 0, 82594, 0, 0, 63834), -- Addie Fizzlebog
(99109, 1, 0, 0, 0, 0, 0, 0, 82594, 0, 0, 63834), -- Pinerock Hunter
(99137, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Warbrave
(99138, 1, 133778, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rebel Drogbar
(99153, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 63834), -- Spiritwalker Ebonhorn
(99190, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 63834), -- Spiritwalker Ebonhorn
(99219, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0, 63834), -- Skyhorn Interceptor
(99221, 1, 55369, 0, 0, 119725, 0, 0, 0, 0, 0, 63834), -- Rivermane Shaman
(99619, 1, 107327, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Navarrogg
(99745, 1, 118559, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Snazzle Shinyfinder
(99746, 1, 1904, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Trytooth Hardchisel
(99747, 1, 2715, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kindle Candlecrafter
(99748, 1, 112140, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dug Digger
(99781, 1, 118559, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Snazzle Shinyfinder
(99782, 1, 1904, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Trytooth Hardchisel
(99783, 1, 112140, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dug Digger
(99784, 1, 2715, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kindle Candlecrafter
(100054, 1, 124065, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Feltotem Warmonger
(100223, 1, 36476, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Vrykul Earthshaper Spirit
(100224, 1, 51431, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Vrykul Earthmaiden Spirit
(100351, 1, 132101, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Avatar of Vengeance
(100491, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0, 63834), -- Sentry Sprydash
(100578, 1, 15229, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Revil Kost
(101259, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lea Stonepaw
(101286, 1, 15229, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Revil Kost
(101388, 1, 88790, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rothoof Shadowstalker
(101651, 1, 94846, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Belysra Starbreeze
(101653, 1, 14881, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Sentinel Mysara
(101654, 1, 14881, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Sentinel Daressa
(101656, 1, 132474, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Valorn Stillbough
(101657, 1, 132474, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ariden
(101742, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lea Stonepaw
(101822, 1, 30147, 0, 0, 61512, 0, 0, 110180, 0, 0, 63834), -- Commander Lorna Crowley
(101858, 1, 128360, 0, 0, 128370, 0, 0, 0, 0, 0, 63834), -- Jace Darkweaver
(102259, 1, 45630, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Enchanted Axe
(102395, 1, 127832, 0, 0, 127832, 0, 0, 0, 0, 0, 63834), -- Infiltrator Assassin
(102397, 1, 124026, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Wrathlord Bulwark
(102400, 1, 107434, 0, 0, 110794, 0, 0, 0, 0, 0, 63834), -- Eredar Shadow Mender
(102728, 1, 91759, 0, 0, 91759, 0, 0, 0, 0, 0, 63834), -- Eredar Shadowguard
(103215, 1, 134847, 0, 0, 52524, 0, 0, 0, 0, 0, 63834), -- Forsaken Deathwarder
(103438, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0, 63834), -- Sentry Wendade
(103439, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0, 63834), -- Sentry Dangard
(103444, 1, 0, 0, 0, 0, 0, 0, 112578, 0, 0, 63834), -- Sentry Frazblink
(103445, 1, 0, 0, 0, 0, 0, 0, 65972, 0, 0, 63834), -- Sentry Captain Seldranath
(103457, 1, 134850, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Forsaken Bishop
(103986, 1, 13709, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Windcaller Yessendra
(103991, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ivy Leafrunner
(103994, 1, 2200, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Zen'Balai
(104012, 1, 57020, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Zen'tabra
(104013, 1, 57020, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rufus Claybourne
(104043, 1, 43219, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Zen'kiki
(104046, 1, 13709, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ysiel Windsinger
(104049, 1, 10619, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Windcaller Kaldon
(104050, 1, 13061, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kelek Skykeeper
(104535, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lea Stonepaw
(104714, 1, 60765, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Champion
(104936, 1, 1904, 0, 0, 1904, 0, 0, 0, 0, 0, 63834), -- Ancestral Warrior
(104937, 1, 20556, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Shaman
(104968, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lea Stonepaw
(105106, 1, 1904, 0, 0, 1904, 0, 0, 0, 0, 0, 63834), -- Ancestral Warrior
(105110, 1, 20556, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Shaman
(105243, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lea Stonepaw
(105294, 1, 88790, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rothoof Shadowstalker
(105948, 1, 118803, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Sylendra Gladesong
(106070, 1, 5600, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Broll Bearmantle
(106071, 1, 5600, 0, 0, 11505, 0, 0, 0, 0, 0, 63834), -- Broll Bearmantle
(106073, 1, 118803, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Sylendra Gladesong
(106135, 1, 12322, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Bashana Runetotem
(106195, 1, 133776, 0, 0, 133776, 0, 0, 0, 0, 0, 63834), -- Mightstone Berserker
(106204, 1, 13339, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archdruid Hamuul Runetotem
(106981, 1, 33213, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Captain Hring
(106982, 1, 107112, 0, 0, 107112, 0, 0, 0, 0, 0, 63834), -- Reaver Jdorn
(106984, 1, 134725, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Soultrapper Mevra
(107390, 1, 110040, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107390, 2, 140688, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107390, 3, 111526, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107390, 4, 127527, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107391, 1, 140688, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107391, 2, 110040, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107391, 3, 111526, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107391, 4, 127527, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ashen Druid
(107425, 1, 10612, 0, 0, 10612, 0, 0, 0, 0, 0, 63834), -- Rexxar
(107551, 1, 127651, 0, 0, 127651, 0, 0, 0, 0, 0, 63834), -- Wrathblade Invader
(107569, 1, 3935, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Cursed Crewman
(107593, 1, 28365, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Algromon
(107674, 1, 111585, 0, 0, 0, 0, 0, 42484, 0, 0, 63834), -- Snaggle Sixtrigger
(107675, 1, 0, 0, 0, 0, 0, 0, 110600, 0, 0, 63834), -- Rax Sixtrigger
(107704, 1, 132179, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Dargrul
(108069, 1, 119206, 0, 0, 118005, 0, 0, 0, 0, 0, 63834), -- Highmountain Spiritwalker
(108305, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mayla Highmountain
(108663, 1, 124524, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lochaber
(109163, 1, 33213, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Captain Dargun
(109189, 1, 37029, 0, 0, 37029, 0, 0, 0, 0, 0, 63834), -- Captain Tevaris
(109970, 1, 107416, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mook Laborer
(110038, 1, 111585, 0, 0, 0, 0, 0, 42484, 0, 0, 63834), -- Snaggle Sixtrigger
(110629, 1, 45726, 0, 0, 45727, 0, 0, 0, 0, 0, 63834), -- Kirin Tor Battle-Mage
(110630, 1, 45726, 0, 0, 45727, 0, 0, 0, 0, 0, 63834), -- Kirin Tor Battle-Mage
(110631, 1, 0, 0, 0, 0, 0, 0, 59367, 0, 0, 63834), -- Gnomeregan Tinkerer
(110632, 1, 0, 0, 0, 0, 0, 0, 59367, 0, 0, 63834), -- Gnomeregan Tinkerer
(110633, 1, 1899, 0, 0, 117413, 0, 0, 0, 0, 0, 63834), -- Stormwind Knight
(110634, 1, 1899, 0, 0, 117413, 0, 0, 0, 0, 0, 63834), -- Stormwind Knight
(110658, 1, 108924, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Commander Jarod Shadowsong
(110806, 1, 3935, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Cursed Crewman
(111165, 1, 139160, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Lady Keletress
(111336, 1, 34816, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Risen Bones
(111830, 1, 14881, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Grovewarden Sentinel
(111831, 1, 14881, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Grovewarden Sentinel
(111928, 1, 134721, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Helarjar Mystcaller
(112310, 1, 0, 0, 0, 0, 0, 0, 36628, 0, 0, 63834), -- Fredo the Patron
(112417, 1, 20556, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Ancestral Shaman
(112738, 1, 124379, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Acolyte of Sael'orn
(112877, 1, 12754, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Thunder Bluff Brave
(112902, 1, 140546, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Earthen Ring Shaman
(113933, 1, 19980, 0, 0, 19980, 0, 0, 0, 0, 0, 63834), -- Valerie Langrom
(140493, 1, 102581, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Veteran Commando
(140494, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Grizzled Berserker
(149486, 1, 42507, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rosaline Madison
(151040, 1, 0, 0, 0, 0, 0, 0, 155816, 0, 0, 63834), -- Lieutenant Tarenfold
(154819, 1, 164729, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Zanj'ir Poker
(207438, 1, 18983, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Headless Horseman
(241725, 1, 124524, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Fel Lord Nezmet
(241743, 1, 23998, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Khadgar
(241744, 1, 191228, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Momentus
(242263, 1, 12182, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Ansirem Runeweaver
(242265, 1, 50725, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Karlain
(242266, 1, 35781, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Modera
(242276, 1, 12182, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Ansirem Runeweaver
(242278, 1, 50725, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Karlain
(242280, 1, 35781, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Modera
(242299, 1, 23998, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Archmage Khadgar
(244262, 1, 43617, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kirin Tor Guardian
(249116, 1, 82810, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Felguard Invader
(249118, 1, 79734, 0, 0, 79735, 0, 0, 0, 0, 0, 63834), -- Wrathguard
(249552, 1, 134639, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Icks
(249553, 1, 57584, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Bragund Brightlink
(249554, 1, 94564, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Matilda Brightlink
(249555, 1, 17383, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Jawknee
(249556, 1, 34285, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Valaden Silverblade
(249557, 1, 12403, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Kerta the Bold
(249866, 1, 13861, 0, 0, 13862, 0, 0, 0, 0, 0, 63834), -- Marcella Bloom
(249867, 1, 88550, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Li-An Skymirror
(249893, 1, 25839, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Hannis Shoalwalker
(249894, 1, 1117, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Marcia Chase
(249895, 1, 34292, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Naseev
(249896, 1, 90145, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Rafael Langrom
(249897, 1, 90145, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Valerie Langrom
(249905, 1, 31824, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Didi the Wrench
(249910, 1, 2715, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Giada Goldleash
(249915, 1, 2714, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Tiffy Trapspring
(249916, 1, 13612, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Christi Stockton
(249920, 1, 1908, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mei Francis
(249921, 1, 25519, 0, 0, 25519, 0, 0, 0, 0, 0, 63834), -- Savash Windcaller
(249924, 1, 6233, 0, 0, 0, 0, 0, 0, 0, 0, 63834); -- Aerith Primrose

INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(249929, 1, 124382, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Amazing Zanzo
(249940, 1, 3699, 0, 0, 12870, 0, 0, 0, 0, 0, 63834), -- Patricia Egan
(249943, 1, 2183, 0, 0, 2183, 0, 0, 0, 0, 0, 63834), -- Sister Might
(249944, 1, 0, 0, 0, 0, 0, 0, 14105, 0, 0, 63834), -- Aemara
(249945, 1, 0, 0, 0, 0, 0, 0, 44715, 0, 0, 63834), -- Dagna Flintlock
(249947, 1, 44091, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Crimson Pilgrim
(249948, 1, 0, 0, 0, 0, 0, 0, 6231, 0, 0, 63834), -- Wanda Chanter
(249952, 1, 18822, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Classic Larry
(249953, 1, 36750, 0, 0, 0, 0, 0, 0, 0, 0, 63834); -- Archmage Celindra

UPDATE `creature_equip_template` SET `VerifiedBuild`=63834 WHERE (`ID`=1 AND `CreatureID` IN (6086,26548,31788,31789,31791,31792,31793,66460,86563,88110,88115,88859,88863,88867,88890,88908,88916,88932,88933,88936,88937,89009,89050,89051,89056,89057,89058,89098,89257,89326,89341,89362,89398,89640,89678,89759,89819,90040,90164,90255,90317,90516,90621,90622,90624,90661,90677,90705,90708,90709,90710,90711,90712,90713,90714,90734,90749,90866,90948,91036,91222,91244,91353,91403,91424,91429,91556,91566,91575,91588,91657,91949,91951,91970,92074,92122,92335,92557,92558,92564,92586,92617,92620,92763,92842,92877,92889,92920,92930,92931,92932,92933,92950,92987,93011,93027,93104,93173,93225,93326,93337,93354,93377,93446,93479,93485,93486,93490,93496,93498,93506,93563,93578,93620,93687,93688,93704,93708,93719,93779,93805,93826,93833,93959,93960,93961,93962,93989,94091,94094,94101,94114,94209,94223,94255,94271,94275,94318,94409,94434,94561,94571,94579,94580,94610,94846,94970,95277,95438,95791,95852,95873,95889,95891,95956,96049,96289,96307,96441,96473,96494,96499,96500,96502,96513,96520,96591,96853,96877,96888,96984,96986,97181,97258,97433,97443,97447,97496,97498,97502,97503,97510,97521,97525,97526,97546,97553,97598,97601,97662,97664,97665,97666,97695,97712,97794,97796,97798,97871,97901,97903,97940,97955,97974,97988,98020,98188,98189,98227,98228,98229,98256,98258,98259,98262,98263,98290,98292,98354,98456,98457,98458,98459,98460,98484,98486,98622,98737,98804,98825,99460,99542,99592,99711,99875,99918,99919,100063,100323,100346,100352,100357,100358,100395,100399,100428,100429,100430,100449,100454,100456,100458,100460,100471,100493,100494,100520,100530,100534,100633,100634,100675,100697,100704,100707,100708,100729,100754,100850,100936,100937,100938,100973,100975,100978,100980,100981,100993,101004,101055,101061,101064,101163,101282,101644,101645,101713,101746,101747,101787,101790,101794,101944,101946,101976,102107,102114,102278,102282,102302,102554,102591,102628,102701,102702,102703,102704,102705,102726,102988,103023,103048,103075,103135,103136,103162,103276,103277,103302,103322,103325,103334,103372,103427,103476,103477,103591,103654,103656,103657,103659,103693,103698,103699,103700,103702,103706,103707,103708,103715,103716,103719,103721,103837,103838,103886,103972,104886,105057,105163,105164,105165,105166,105174,105175,105179,105181,105182,105183,105188,105190,105192,105196,105200,105203,105205,105206,105680,105687,105903,106109,106111,106244,106752,106753,106881,106915,106990,107245,107362,107363,107403,107673,107768,107823,107826,107829,107833,107835,107839,107841,107962,108051,108140,108141,108142,108143,108145,108328,108481,108488,108489,108490,108491,108525,108584,108586,108587,108588,108705,108722,108723,108742,108745,108746,108747,108748,108749,108750,108751,108752,108753,108754,108755,108756,108757,108758,108759,108767,108911,109225,109386,109412,109586,109587,109591,109592,109604,110615,110616,110617,110799,110941,111085,111087,111088,111149,111154,111155,111156,111167,111332,111418,111459,111460,111600,112311,112317,112423,112424,112477,112788,112879,112920,112921,113034,113036,113037,113038,113392,113404,113528,113530,113531,113558,113561,113564,113566,113929,113931,113934,113986,114098,114099,114100,114101,114109,114110,114246,114325,114326,114401,114466,114469,114479,114639,114754,114755,114756,114758,114760,114761,114762,114763,114764,114814,115172,115242,115732,117654,118177,118806,119484,121235,122072,123169,123244,124306,124695,125210,125878,125955,125957,125960,126020,126170,126308,128629,128630,129486,129627,129749,129750,129753,129836,129870,129906,129981,130006,130008,130039,130073,130075,130079,130088,130094,130098,130189,130190,130395,130531,130641,130694,130695,130700,130897,130952,131020,131103,131163,131165,131166,131290,131302,131446,131496,132118,132160,132163,132226,132619,133282,133441,133940,134055,134141,134425,134426,134623,134631,134696,134704,134721,134722,134723,134725,134729,134747,134838,134847,134999,135000,135107,135401,135520,135612,135614,135618,135675,135677,135678,135681,135682,135792,135857,135860,135874,135889,135939,135973,136052,136061,136318,136421,136439,136451,136462,136463,136519,136584,136633,137094,137104,137134,137144,137265,137266,137268,137282,137293,137294,137295,137298,137299,137300,137301,137315,137317,137447,137621,137679,137755,137797,137821,137822,137823,138028,138245,138544,139095,139096,139144,139177,139375,139714,139803,139926,139967,140284,140313,140350,140796,140906,141002,141006,141080,141085,141091,141143,141147,141274,141353,141485,141519,141552,141603,141646,142167,142180,142276,142371,142490,142607,142611,142644,142754,142773,142955,142961,142967,143098,143128,143152,143186,143248,143250,143336,143535,143574,143746,143793,143842,143846,143856,143892,144212,144213,144310,145728,145730,148911,148912,149045,149459,151173,152079,152080,152081,160101,176241,197951,231840)) OR (`ID`=6 AND `CreatureID` IN (18927,27893,89110,89111,135792)) OR (`ID`=3 AND `CreatureID` IN (27893,89112,89113,92617,99386,123641,126582,133325,134838,135509,135678,138544,139095)) OR (`ID`=18 AND `CreatureID`=76168) OR (`ID`=24 AND `CreatureID`=76168) OR (`ID`=27 AND `CreatureID`=76168) OR (`ID`=40 AND `CreatureID`=76168) OR (`ID`=2 AND `CreatureID` IN (88084,89110,89111,90866,92617,96494,107826,107839,107841,123642,126581,134838,135678,135792,136633,137679,138544,139088,143892)) OR (`ID`=4 AND `CreatureID` IN (89104,89110,89112,89113,135792)) OR (`ID`=5 AND `CreatureID` IN (89104,89110,89112,135792,139088)) OR (`ID`=9 AND `CreatureID`=135792) OR (`ID`=10 AND `CreatureID`=135792) OR (`ID`=8 AND `CreatureID`=139088);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (89469 /*Infinite Research: Dungeoneers Wanted, Heroic*/, 44076 /*Darkheart Thicket: Essence of Regrowth*/, 42234 /*The Valarjar*/, 46798 /*Paragon of the Valarjar*/, 90100 /*Infinite Research: Combat Studies, Rare Elites*/, 90115 /*Infinite Research: Combat Studies, Groverunner*/, 90102 /*Infinite Research: Champion of the Broken Isles*/, 42420 /*Court of Farondis*/, 91844 /*Infinite Research Promotion: Honorary Chronographer*/, 93120 /*Infinite Research: Special Assignment, A World to Explore*/, 89665 /*Infinite Research: Time to Raid, Tormented Guardians*/, 92439 /*Infinite Research: Combat Studies, Felrunner*/, 44232 /*The Grove Provides*/, 40654 /*Druids of the Claw*/, 91639 /*Embrace Your Own Legend*/, 91613 /*Infinite Research Promotion: Timely Assistant*/, 93114 /*Infinite Research: Special Assignment, Sampling the World*/, 93113 /*Infinite Research: Special Assignment, Rare Dare*/, 93112 /*Infinite Research: Special Assignment, Fel Skies*/, 42037 /*Gathering the Dreamweavers*/, 42039 /*Champion: Sylendra Gladesong*/, 42038 /*Champion: Broll Bearmantle*/, 42036 /*Idol of the Wilds*/, 93116 /*Infinite Research: Special Assignment, Here to Slay*/, 93056 /*A Lesson in Alacrity*/, 44106 /*Archdruid of Lore*/, 42033 /*Malorne's Refuge*/, 43980 /*Another Weapon of Old*/, 93055 /*Extracurriculars*/, 91061 /*Infinite Chaos*/, 91631 /*Epoch Progress*/, 44284 /*The Emerald Nightmare: Piercing the Veil*/, 44283 /*The Emerald Nightmare: Piercing the Veil*/, 91632 /*The End of an Epoch Journey*/, 93118 /*Infinite Research: Special Assignment, Power Overwhelming*/, 93117 /*Infinite Research: Special Assignment, Boss Rush*/, 45088 /*Trial of Valor: The Lost Army*/, 90892 /*Clearing the Skies: A Fel of a Time*/, 92563 /*Awoken by Accessory*/, 92430 /*Embracing the Infinite Chaos*/, 89418 /*A Fixed Point in Time*/, 89417 /*Infinite Meetings*/, 89416 /*Eternal Gratitude*/, 89415 /*Storm the Citadel*/, 89414 /*Not A Memento Too Soon*/, 89413 /*Obliterate, Then Iterate*/, 89412 /*Get Plenty of Exorcise*/, 90901 /*As A Matter of Artifact*/, 89411 /*Scavenger Hunting*/, 90659 /*Something Borrowed*/, 89409 /*Infinite Bronze*/, 89408 /*Threadbare*/, 89407 /*Thrift*/, 89406 /*Seal and Protect*/, 89405 /*Mean Streets of Dalaran*/, 89404 /*Time Crisis*/, 89524 /*Infinite Research: Maw of Souls, Normal*/, 90108 /*Infinite Research: Artifact Collector*/, 90109 /*Infinite Research: Clear the Skies*/, 42430 /*The Fangs of Ashamane*/, 42440 /*The Shrine in Peril*/, 42438 /*Seeds of Renewal*/, 42439 /*Aid for the Ashen*/, 42428 /*The Shrine of Ashamane*/, 91722 /*Shape a New Legend*/, 89550 /*Infinite Research: Halls of Valor, Normal*/, 89551 /*Infinite Research: Halls of Valor, Heroic*/, 89517 /*Infinite Research: Assault on Violet Hold, Heroic*/, 89549 /*Infinite Research: Neltharion's Lair, Heroic*/, 44431 /*More Weapons of Old*/, 44075 /*Halls of Valor: Essence of Ferocity*/, 44074 /*Neltharion's Lair: Essence of Tenacity*/, 44285 /*The Emerald Nightmare: Piercing the Veil*/, 41918 /*The Dreamer Returns*/, 40647 /*When Dreams Become Nightmares*/, 41792 /*The Third Trial of Ursol*/, 41791 /*The Second Trial of Ursol*/, 41790 /*The First Trial of Ursol*/, 41782 /*To The Hills*/, 42044 /*A Dying Dream*/, 42042 /*Teensy Weensies!*/, 42043 /*Cleaning Up*/, 42041 /*Enduring the Nightmare*/, 42040 /*The Way to Nordrassil*/, 91721 /*Surpass Your Own Legend*/, 41468 /*Mistress of the Claw*/, 43991 /*The Protectors*/, 92440 /*Infinite Research: Combat Studies, Stormrunner*/, 43331 /*Time to Collect*/, 39305 /*Empty Nest*/, 42425 /*Going Down, Going Up*/, 40071 /*Tamer Takedown*/, 40070 /*Eagle Egg Recovery*/, 40069 /*Fledgling Worm Guts*/, 42857 /*Moist Around the Hedges*/, 42884 /*Grassroots Effort*/, 42883 /*All Grell Broke Loose*/, 42865 /*Grell to Pay*/, 42035 /*Tracking the Enemy*/, 42034 /*Grip of Nightmare*/, 91955 /*Just Between Us*/, 92688 /*Bronze Simulacrum*/, 42031 /*Dire Growth*/, 42032 /*Sampling the Nightmare*/, 42588 /*Branching Out*/, 42586 /*A Glade Defense*/, 42585 /*Recruiting the Troops*/, 42584 /*Sister Lilith*/, 42583 /*Rise, Champions*/, 40650 /*Champion: Zen'tabra*/, 42096 /*Champion: Naralex*/, 40653 /*Making Trails*/, 40652 /*Word on the Winds*/, 41332 /*Ascending The Circle*/, 41255 /*Sowing The Seed*/, 40900 /*The Burden Borne*/, 40838 /*The Dark Riders*/, 40837 /*The Deadwind Hunt*/, 40835 /*Disturbing the Past*/, 40834 /*Following the Curse*/, 40785 /*A Foe of the Dark*/, 40784 /*Its Rightful Place*/, 40783 /*The Scythe of Elune*/, 40646 /*Weapons of Legend*/, 53720 /*Allegiance of Kul Tiras*/, 54851 /*Blessing of the Tides*/, 54735 /*A Worthy Crew*/, 54734 /*Summons from Dorian*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(89469, 1, 0, 0, 0, 0, 0, 0, 0, 'You have no idea how happy this will make Moratari.', 63834), -- Infinite Research: Dungeoneers Wanted, Heroic
(44076, 0, 0, 0, 0, 0, 0, 0, 0, 'I am sad to hear of Oakheart\'s demise, but his soul will live on.', 63834), -- Darkheart Thicket: Essence of Regrowth
(42234, 0, 0, 0, 0, 0, 0, 0, 0, 'The valarjar thank you.', 63834), -- The Valarjar
(46798, 0, 0, 0, 0, 0, 0, 0, 0, 'Greetings, $ct $n.$b$bFor some time now you have been a paragon to Odyn and a hero to the Valarjar. Our gratitude goes beyond anything mere words can define.$b$bTake these trophies as a token of our gratitude and a share in the spoils of war. The more you aid us, the more we can provide you.', 63834), -- Paragon of the Valarjar
(90100, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $p. Moratari will be overjoyed to see these new data points.', 63834), -- Infinite Research: Combat Studies, Rare Elites
(90115, 1, 0, 0, 0, 0, 0, 0, 0, 'Impressive. I can sense your power. This is a most critical addition to our research.', 63834), -- Infinite Research: Combat Studies, Groverunner
(90102, 1, 0, 0, 0, 0, 0, 0, 0, 'Your legend has grown, $p. The timeline reverberates with not just the substance of your deeds, but it compounds as it impacts those around you. This has been a most fruitful addition to our research.', 63834), -- Infinite Research: Champion of the Broken Isles
(42420, 0, 0, 0, 0, 0, 0, 0, 0, 'The Court of Farondis thanks you.', 63834), -- Court of Farondis
(91844, 1, 0, 0, 0, 0, 0, 0, 0, '$n, you have been an excellent assistant with our research. I think you deserve a promotion.\n\nFrom now on, you will be able to take on more research assignments simultaneously.\n\nIt\'s ironic, isn\'t it, that we never seem to have enough time. Make good use of your time here. Don\'t make me regret granting you this power.', 63834), -- Infinite Research Promotion: Honorary Chronographer
(93120, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63834), -- Infinite Research: Special Assignment, A World to Explore
(89665, 1, 0, 0, 0, 0, 0, 0, 0, 'The sum strength of a group of timerunners armed with potent artifacts is greater than that of the individuals. Much greater than anticipated. Intriguing.', 63834), -- Infinite Research: Time to Raid, Tormented Guardians
(92439, 1, 0, 0, 0, 0, 0, 0, 0, 'Impressive. I can sense your power. This is a most critical addition to our research.', 63796), -- Infinite Research: Combat Studies, Felrunner
(44232, 1, 0, 0, 0, 0, 0, 0, 0, 'We are with you, $n.', 63796), -- The Grove Provides
(40654, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent. Soon enough, the Druids of the Claw will bolster our ranks.', 63796), -- Druids of the Claw
(91639, 1, 0, 0, 0, 0, 0, 0, 0, 'You have grown stronger, but your artifact is stronger yet.\n\nIt would appear that my hypothesis holds true--artifacts appear to be the key to protecting Azeroth.', 63796), -- Embrace Your Own Legend
(91613, 1, 0, 0, 0, 0, 0, 0, 0, '$n, you have been an excellent assistant with our research. I think you deserve a promotion.\n\nFrom now on, you will be able to take on more research assignments simultaneously.\n\nIt\'s ironic, isn\'t it, that we never seem to have enough time. Make good use of your time here. Don\'t make me regret granting you this power.', 63796), -- Infinite Research Promotion: Timely Assistant
(93114, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Sampling the World
(93113, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Rare Dare
(93112, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Fel Skies
(42037, 0, 0, 0, 0, 0, 0, 0, 0, 'Good, the druids have gathered. Even now, they should be flocking to Nordrassil to prepare for the ritual.', 63796), -- Gathering the Dreamweavers
(42039, 1, 66, 0, 0, 0, 500, 0, 0, '$n, I owe you my life. Your actions gave me a second chance, and it is a chance I have no intention of squandering.$B$BWith your help, we were able to recover the Idol of the Wild. Such a sacred relic would have been a devastating loss had it fallen into the wrong hands.$B$BNow, I will see this journey through to its end.$B$BLet me fight for you. If there is anyone who can defeat the Nightmare, I believe it is you.', 63796), -- Champion: Sylendra Gladesong
(42038, 1, 66, 0, 0, 0, 500, 0, 0, 'I have seen enough of the Nightmare to know that it is not an idle threat. Within its grasp, even the strongest become their own worst enemies.$B$BYou, however, have displayed courage and fortitude even in the face of this great danger. I feel faith that you will lead us to victory against our enemy.$B$B$n, I wish to pledge my loyalty in service of you and the druidic order', 63796), -- Champion: Broll Bearmantle
(42036, 0, 0, 0, 0, 0, 0, 0, 0, 'The Idol... so relieved am I to see it in your hands, $n.$B$BWe will keep it here at the Dreamgrove for safekeeping.', 63796), -- Idol of the Wilds
(93116, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Here to Slay
(93056, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes, now you are prepared.', 63796), -- A Lesson in Alacrity
(44106, 0, 0, 0, 0, 0, 0, 0, 0, 'Welcome, $n. News of your heroism spreads from the Dreamgrove.', 63796), -- Archdruid of Lore
(42033, 0, 0, 0, 0, 0, 0, 0, 0, 'I\'m glad you are here, $n, but if only we had arrived earlier! This place was in chaos when I arrived.$B$BThe survivors claim they were attacked by satyr, but how can this be? No satyrs have roamed these woods since ancient times.', 63704), -- Malorne's Refuge
(43980, 1, 0, 0, 0, 0, 0, 0, 0, 'A sound choice.', 63704), -- Another Weapon of Old
(93055, 1, 0, 0, 0, 0, 0, 0, 0, 'Hopefully this diversion has been enlightening.', 63704), -- Extracurriculars
(91061, 1, 0, 0, 0, 0, 0, 0, 0, 'You are braver than I thought, $n.\n\nPlease continue to experiment. I will not let us enter dangerous futures unprepared.', 63704), -- Infinite Chaos
(91631, 1, 0, 0, 0, 0, 0, 0, 0, 'Your power grows stronger, $p.\n\nPlease, take this token of our gratitude for your assistance with our research. Let it echo with every you that exists in the fractures of this timeline.', 63704), -- Epoch Progress
(44284, 0, 0, 0, 0, 0, 0, 0, 0, 'Incredible... where did you find these? With these Essences, I will be able to open the way directly to the heart of the Nightmare. Let us make haste!', 63834), -- The Emerald Nightmare: Piercing the Veil
(44283, 0, 0, 0, 0, 0, 0, 0, 0, 'Incredible... where did you find these? With these Essences, I will be able to open the way directly to the heart of the Nightmare. Let us make haste!', 63834), -- The Emerald Nightmare: Piercing the Veil
(91632, 1, 0, 0, 0, 0, 0, 0, 0, 'You have reached your full potential, $p. Or have you? Perhaps this is only the beginning of your journey through this epoch.\n\nPlease, take this token of our gratitude for your assistance with our research. Let it echo with every you that exists in the fractures of this timeline.', 63796), -- The End of an Epoch Journey
(93118, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Power Overwhelming
(93117, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent progress. Here are the spoils of your victory.', 63796), -- Infinite Research: Special Assignment, Boss Rush
(45088, 0, 0, 0, 0, 0, 0, 0, 0, 'With these souls returned to the Halls of Valor my forces return to their former strength. As promised, the bounty is yours.', 63796), -- Trial of Valor: The Lost Army
(90892, 0, 0, 0, 0, 0, 0, 0, 0, '<The skies are a little clearer now. The infinites might be interested in trading with this extra bronze I\'ve collected.>', 63704), -- Clearing the Skies: A Fel of a Time
(92563, 1, 0, 0, 0, 0, 0, 0, 0, 'Fascinating, it seems as though the magic of your new accessory is capable of awakening otherwise inaccessible powers of your artifact weapon, or even enhancing them beyond their limits!\n\nI wonder if all jewelry has this same connection to your artifact weapon. Please do keep me informed of any more anomalies.', 63704), -- Awoken by Accessory
(92430, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent timing, $p. Now the research can begin.', 63704), -- Embracing the Infinite Chaos
(89418, 1, 0, 0, 0, 0, 0, 0, 0, 'And here we are, back where it all started.\n\nIn a moment a messenger will come looking for you and your legend will begin to unfold.\n\n<Moratari smiles broadly at you, beaming with excitement.>\n\nAren\'t you excited? I know I am.\n\nOh, and if you need anything, just come by the Infinite Bazaar. We\'re always waiting.\n\nGood luck!', 63660), -- A Fixed Point in Time
(89417, 1, 0, 0, 0, 0, 0, 0, 0, 'As you can see, $n, there are many minds at work here in the infinite dragonflight. Minds that are all working to answer some pressing questions.\n\nWhat knowledge can we gain to prepare us for even greater threats?\n\nWould we have triumphed if things had been worse?\n\nWhat are the implications of Sargeras\'s sword being plunged into Azeroth, and was it the artifacts that saved Azeroth or something else?\n\nEr, I mean... Forget I said anything. What sword?', 63660), -- Infinite Meetings
(89416, 1, 0, 0, 0, 0, 0, 0, 0, 'Moratari has kept me apprised of your endeavors in this timeline, $n.\n\nKnow that I am pleased.\n\nDalaran will recover in time. Speaking of, I will accelerate the timeline until after the cleanup is complete.', 63660), -- Eternal Gratitude
(89415, 1, 0, 0, 0, 0, 0, 0, 0, 'We make a good team, $n.\n\nThe Kirin Tor will handle the remaining Legion forces from here. For now my attention must turn to restoring the wards to their full strength.', 63660), -- Storm the Citadel
(89414, 1, 0, 0, 0, 0, 0, 0, 0, 'It has been a hard day, $n, but our resolve is soon to be rewarded.\n\nWith the Legion distracted by your timely heroics, I was able to stretch out my arcane power and divine the mastermind behind the Legion incursion into our beloved city.', 63660), -- Not A Memento Too Soon
(89413, 1, 0, 0, 0, 0, 0, 0, 0, 'Bronze can be spent at the infinite bazaar on many pretty things.\n\nWhenever you find junk, just summon the Unraveling Sands.\n\nJunk goes in, pretty bronze comes out.\n\nIs convenient, yes?', 63660), -- Obliterate, Then Iterate
(89412, 1, 0, 0, 0, 0, 0, 0, 0, 'I can sense the power emanating from your artifact from here. Good.\n\nI\'ve also noted that it hasn\'t fractured under the power load yet. Also good.\n\nLet me just make a note of that for Moratari\'s records. Very good.', 63660), -- Get Plenty of Exorcise
(90901, 1, 0, 0, 0, 0, 0, 0, 0, 'As you gather infinite power do not forget to focus it into your artifact.\n\nThe more power you invest, the swifter you will gather more infinite power and grow your artifact\'s legend--and your own.', 63660), -- As A Matter of Artifact
(89411, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. Good. You do well. Artifact grows stronger. Almost as strong as Erus.\n\n<Erus laughs at his own boast.>', 63660), -- Scavenger Hunting
(90659, 1, 0, 0, 0, 0, 0, 0, 0, 'Intriguing. This artifact\'s potential has been deepened, perhaps by the fraying of this timeline. It can harness more power than any incarnation of it that I have yet encountered.\n\nLet me record that data point for Moratari.\n\nOh, important reminder--don\'t forget to recover the bronze simulacrum later or things might get... funky.\n\nAnd lastly, maybe don\'t mention to people how you got that. It could ruin the experiment.', 63660), -- Something Borrowed
(89409, 1, 0, 0, 0, 0, 0, 0, 0, 'Now that you have infinite bronze we can get you an artifact in order to properly carry out our tests.\n\nThen you\'ll have no problem living up to your own legend, $n.', 63660), -- Infinite Bronze
(89408, 1, 0, 0, 0, 0, 0, 0, 0, 'These threads contain traces of potential epoch energy. To access their power we\'ll need to infuse them into a stabilizing material, such as infinite bronze, in order to anchor them in place.\n\nThey\'ll lose some of their potency, but at least they will be sufficient for our needs.', 63660), -- Threadbare
(89407, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine collection of epoch objects.', 63660), -- Thrift
(89406, 1, 0, 0, 0, 0, 0, 0, 0, 'I think this is magnificent!\n\nYou\'re the perfect control group to test our theories on the importance of artifacts in the grand scheme of the flow of timelines.', 63660), -- Seal and Protect
(89405, 0, 0, 0, 0, 0, 0, 0, 0, 'Well met, $n, and splendid work. You took the pressure off us just long enough to get a handle on this whole debacle.', 63660), -- Mean Streets of Dalaran
(89404, 1, 0, 0, 0, 0, 0, 0, 0, '$n! You surely are a welcome sight to see on this dark day. Our teleportation spell went awry and now the Legion is invading Dalaran.', 63660), -- Time Crisis
(89524, 1, 0, 0, 0, 0, 0, 0, 0, 'Very good results. Exceeds expectations.', 63834), -- Infinite Research: Maw of Souls, Normal
(90108, 1, 0, 0, 0, 0, 0, 0, 0, 'You have quite the collection now, $p. All that remains to be seen is whether you prefer one artifact over the other.', 63834), -- Infinite Research: Artifact Collector
(90109, 1, 0, 0, 0, 0, 0, 0, 0, 'Good. Nothing dramatic occured when you gathered the residual time motes. If you start to feel anything strange, do let us know though.', 63834), -- Infinite Research: Clear the Skies
(42430, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ve heard from Delandros about how you rescued the Ashen and protected the shrine.$b$bWe all owe you a great deal for your heroism, $n. And it seems that you were able to recover the Fangs as well!$B$BI suspect this war is far from over.', 63834), -- The Fangs of Ashamane
(42440, 1, 0, 0, 0, 0, 0, 0, 0, 'What? Verstok fled with the Fangs? That fool, he\'s going to get himself killed!', 63834), -- The Shrine in Peril
(42438, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $n.$b$bMy heart weeps for those who we\'ve lost this day. The Legion will pay for this, I swear it!', 63834), -- Seeds of Renewal
(42439, 1, 2, 0, 0, 0, 0, 0, 0, '<Delandros nods.>$b$bThank you, hero. Now that my people are safe we might be able to turn the tide of this battle.', 63834), -- Aid for the Ashen
(42428, 1, 0, 0, 0, 0, 0, 0, 0, 'Rensar sent you? As much as I\'d like to help, whatever you need is going to have to wait. As you can see, we have bigger problems.$b$bActually, we could really use your help. If you could lend us your aid then I\'ll do all that I can to help you with whatever it is you\'re here for.$b$bWould this be acceptable?', 63834), -- The Shrine of Ashamane
(91722, 1, 0, 0, 0, 0, 0, 0, 0, 'Humbling.\n\nIt is the very nature of finite existence that is the answer.\n\nMortality is the flame that shines brightest because it is free to choose a single moment of glory, rather than be burdened by the weight of eternity.\n\nChoose your moment well, $p, and nothing, not even time, will be able to stop you.', 63834), -- Shape a New Legend
(89550, 1, 0, 0, 0, 0, 0, 0, 0, 'Very good results. Exceeds expectations.', 63834), -- Infinite Research: Halls of Valor, Normal
(89551, 1, 0, 0, 0, 0, 0, 0, 0, 'Very good results. Exceeds expectations.', 63834), -- Infinite Research: Halls of Valor, Heroic
(89517, 1, 0, 0, 0, 0, 0, 0, 0, 'Very good results. Exceeds expectations.', 63834), -- Infinite Research: Assault on Violet Hold, Heroic
(89549, 1, 0, 0, 0, 0, 0, 0, 0, 'Very good results. Exceeds expectations.', 63834), -- Infinite Research: Neltharion's Lair, Heroic
(44431, 1, 0, 0, 0, 0, 0, 0, 0, 'A sound choice.', 63834), -- More Weapons of Old
(44075, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent, Arch Druid.', 63834), -- Halls of Valor: Essence of Ferocity
(44074, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you, Archdruid.', 63834), -- Neltharion's Lair: Essence of Tenacity
(44285, 0, 0, 0, 0, 0, 0, 0, 0, 'Incredible... where did you find these? With these Essences, I will be able to open the way directly to the heart of the Nightmare. Let us make haste!', 63834), -- The Emerald Nightmare: Piercing the Veil
(41918, 0, 0, 0, 0, 0, 0, 0, 0, 'So, Xavius is behind this. A thousand deaths isn\'t enough of a punishment for that defiler!$b$bBut, you have returned with the claws, that is not an accomplishment that even I could have performed.$b$bYou are truly the hero we need to face the Legion.', 63834), -- The Dreamer Returns
(40647, 1, 0, 0, 0, 0, 0, 0, 0, 'I owe you my life, $n. If it wasn\'t for your actions I\'d be dead or worse.$b$bThat traitor, Xavius, may have taken Ursoc but at least we were able to recover the claws. Hope is not lost to us yet.', 63834), -- When Dreams Become Nightmares
(41792, 1, 0, 0, 0, 0, 0, 0, 0, 'You have passed every trial I\'ve placed before you and emerged victorious. You are worthy indeed of my brother\'s legacy, and have earned my blessing!$b$bGo, seek out the claws and claim them as your own.', 63834), -- The Third Trial of Ursol
(41791, 1, 0, 0, 0, 0, 0, 0, 0, 'Well done, $n. You handled yourself with honor!$b$bYou\'ve done well so far, yet a single trial remains before I will give you my blessing.', 63834), -- The Second Trial of Ursol
(41790, 1, 0, 0, 0, 0, 0, 0, 0, 'You are powerful indeed, but strength alone will not impress me.', 63834), -- The First Trial of Ursol
(41782, 4, 0, 0, 0, 0, 0, 0, 0, 'Excellent! We will need this water to enter the Emerald Dream. I\'ve prepared offerings for Ursol, brother of Ursoc. We will need his help to bypass the magical wards placed upon the claws.\n\nGive me a moment... and let us hope Ursol will aid us.', 63834), -- To The Hills
(42044, 0, 0, 0, 0, 0, 0, 0, 0, 'Today I grieve for a fallen ally, one who has wandered these forests for eons.$B$BHe can now be at peace, knowing he gave his life to protect this sacred place.', 63834), -- A Dying Dream
(42042, 0, 0, 0, 0, 0, 0, 0, 0, 'Yay, they\'re saved! Thank you!', 63834), -- Teensy Weensies!
(42043, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent work, $n. I knew that Elune\'s power could purify the nightmare\'s taint. Her blessing is strong here.', 63834), -- Cleaning Up
(42041, 0, 0, 0, 0, 0, 0, 0, 0, 'Good, I already feel the Nightmare\'s power waning.', 63834), -- Enduring the Nightmare
(42040, 0, 0, 0, 0, 0, 0, 0, 0, 'Something isn\'t right here, $n. This isn\'t the Dream. Could Xavius\' creatures have invaded our sanctuary? How did they get past our protective wards?', 63834), -- The Way to Nordrassil
(91721, 1, 0, 0, 0, 0, 0, 0, 0, 'I admit. I am pleasantly surprised to be proven wrong. Your power has grown and I cannot say with certainty which is the greater. You, or the weapon you wield.', 63834), -- Surpass Your Own Legend
(41468, 1, 0, 0, 0, 0, 0, 0, 0, 'The Claws of Ursoc?$b$bI thought I\'d go the rest of my days without hearing of them again. Is our situation truly so dire? They were sealed away for good reason!', 63834), -- Mistress of the Claw
(43991, 0, 0, 0, 0, 0, 0, 0, 0, 'Did you sense the protectors of the wilds? Their presence is ever with us.', 63834), -- The Protectors
(92440, 1, 0, 0, 0, 0, 0, 0, 0, 'Impressive. I can sense your power. This is a most critical addition to our research.', 63834), -- Infinite Research: Combat Studies, Stormrunner
(43331, 517, 0, 0, 0, 0, 0, 0, 0, 'With the Sixtrigger brothers ended, you\'re finally able to collect your payment for services rendered.$B$BYou rummage through their most prized possessions and take your pick.', 63834), -- Time to Collect
(39305, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks to you, the great eagles of Highmountain will live on.$b$bOne of the eggs I thought was too damaged to salvage appears to be hatching...', 63796), -- Empty Nest
(42425, 1, 0, 0, 0, 0, 0, 0, 0, 'I can\'t believe it! I hoped it would work, but I couldn\'t be sure.\n\nYou recovered heirlooms passed down by my family for many generations.\n\nI thought them lost forever.', 63796), -- Going Down, Going Up
(40071, 1, 0, 0, 0, 0, 0, 0, 0, 'Korgrul deserved his fate. Thank you, $n.', 63796), -- Tamer Takedown
(40070, 1, 0, 0, 0, 0, 0, 0, 0, 'These eggs are in poor condition, $n. Some are cracked and spoiled, while others are cold to the touch.$b$bYet there is still hope. I believe a few of the eggs you recovered can be saved.', 63796), -- Eagle Egg Recovery
(40069, 1, 0, 0, 0, 0, 0, 0, 0, 'Those worm guts will be perfect for a special sort of rope.', 63796), -- Fledgling Worm Guts
(42857, 396, 0, 0, 0, 0, 0, 0, 0, 'Ah yes, this is the grell food supply. Perhaps I can use this to lure them away. Thank you.', 63704), -- Moist Around the Hedges
(42884, 1, 0, 0, 0, 0, 0, 0, 0, 'The grell trapped our young within the huts. They are no longer at risk, thanks to your generous efforts.', 63704), -- Grassroots Effort
(42883, 603, 0, 0, 0, 0, 0, 0, 0, 'Thank you, $n. You are welcome in our village anytime.', 63704), -- All Grell Broke Loose
(42865, 1, 0, 0, 0, 0, 0, 0, 0, 'I don\'t know if grell have mothers, but I hope that one never kissed his mother with his mouth.', 63704), -- Grell to Pay
(42035, 0, 0, 0, 0, 0, 0, 0, 0, 'Look what we dragged in.', 63704), -- Tracking the Enemy
(42034, 0, 0, 0, 0, 0, 0, 0, 0, 'The satyr have never been this bold, or powerful. They took us completely by surprise, and our magic could not withstand their attacks. Without you, I would not have survived.$B$BI have only one purpose now - to recover that idol.', 63704), -- Grip of Nightmare
(91955, 1, 0, 0, 0, 0, 0, 0, 0, 'Success!\n\nIt\'s almost a shame to destroy such a beautiful replica.\n\nBut you have the real thing, so I say scrap it and rejoice at the bounty of beautiful bronze!', 63704), -- Just Between Us
(92688, 603, 0, 0, 0, 0, 0, 0, 0, 'YES! Erus will scrap!', 63704), -- Bronze Simulacrum
(42031, 0, 0, 0, 0, 0, 0, 0, 0, 'You were just with Naralex? What were the results of the sampling?', 63704), -- Dire Growth
(42032, 0, 0, 0, 0, 0, 0, 0, 0, 'Our champions returned from Shaladrassil just moments ago, Archdruid. The journey was a great success!', 63704), -- Sampling the Nightmare
(42588, 0, 0, 0, 0, 0, 0, 0, 0, 'Well done! I see that Leafbeard\'s advice has already been useful.', 63704), -- Branching Out
(42586, 0, 0, 0, 0, 0, 0, 0, 0, 'Not only was the mission a success, but our champions recovered an inscribed leaf of ancient knowledge. These may be of great interest to Leafbeard the Storied, the Ancient of Lore who resides to the north.', 63704), -- A Glade Defense
(42585, 0, 0, 0, 0, 0, 0, 0, 0, 'Well done. I knew that Sister Lilith would come through for us.', 63704), -- Recruiting the Troops
(42584, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent, $n. Zen\'tabra has done well.', 63704), -- Sister Lilith
(42583, 0, 0, 0, 0, 0, 0, 0, 0, 'Good. I know Zen\'tabra and Naralex, and they will serve the Dreamgrove bravely.', 63704), -- Rise, Champions
(40650, 1, 0, 0, 0, 0, 0, 0, 0, 'I ben tinkin\' for a while, $n. I set aside my walking staff a long time ago for a life of peace, seekin\' to teach da druidic arts in my twilight years.$B$BBut now, war has come to tear my home to shreds, and I can\'t watch that happen.$B$BMy staff and I are ready for another journey with you, $n.', 63704), -- Champion: Zen'tabra
(42096, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ve watched you rise up the ranks for a long time, $n. With you leading our order, I know we are in good hands.$B$BCount me as one of your champions, Archdruid.', 63704), -- Champion: Naralex
(40653, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes, I agree. That is a good place to focus our initial efforts.$b$bAs new threats arise, I will bring them to your attention. Elune guide your path, $ct.', 63704), -- Making Trails
(40652, 1, 0, 0, 0, 0, 0, 0, 0, 'Greetings, $ct.$b$bThe threats we face are numerous. We must act quickly.', 63704), -- Word on the Winds
(41332, 1, 0, 0, 0, 0, 0, 0, 0, 'Congratulations, $ct $n.$b$bWe will be counting on you in the days ahead.', 63704), -- Ascending The Circle
(41255, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent. There\'s no time to waste.', 63704), -- Sowing The Seed
(40900, 0, 0, 0, 0, 0, 0, 0, 0, 'The Scythe of Elune!$b$bI never thought I would see that weapon used without turning its wielder into a savage beast, but you\'ve brought balance to its primal nature.$b$bElune has certainly guided your hand, $n. You\'ve accomplished what no druid has done before!', 63704), -- The Burden Borne
(40838, 0, 0, 0, 0, 0, 0, 0, 0, 'Today was a great blow against the Dark Riders, and a victory for the people of Duskwood. $B$BThey are in your debt, as am I.', 63704), -- The Dark Riders
(40837, 0, 0, 0, 0, 0, 0, 0, 0, 'The worgen appear to be drawn to the catacombs beneath Karazhan.$B$BCould it be...', 63704), -- The Deadwind Hunt
(40835, 0, 0, 0, 0, 0, 0, 0, 0, 'Dark energy hums from the journal, which appears to be the writings of Ariden, and chronicles his time in Deadwind Pass. One entry in particular stands out:$B$B\"The Nightbane have become restless of late, and whispers abound that the Scythe of Elune have left Darnassus. It must be coming nearer, for the worgen are constantly drawn to it. They will lead me to it.$B$BThose cursed night elves think the weapon is safe in their care. They will soon find how wrong they are\"', 63704), -- Disturbing the Past
(40834, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s strange that the Dark Riders haven\'t followed us here, but I will take whatever boon I can get.$B$BI believe the key to finding the Dark Riders is here somewhere. Let us begin our search.', 63704), -- Following the Curse
(40785, 0, 0, 0, 0, 0, 0, 0, 0, 'So I was correct, and the Scythe is your quarry.  Know that in order to retrieve it, we must do what no denizen of Duskwood has ever attempted.$B$BWe must hunt the Dark Riders.$B$BI have been tracking them for some time since my encounter with them while hunting down the Wolf Cult.  They are a blight upon these lands, and they hold no right to the artifacts they hoard.$B$BIf we wish to recover this artifact, we will need to find their lair. Fortunately, I may just have the clue we need.', 63704), -- A Foe of the Dark
(40784, 0, 0, 0, 0, 0, 0, 0, 0, 'Valorn...$B$BThat was.. a Dark Rider!$B$BBut how did they reach us here, under the protection of the grove?', 63704), -- Its Rightful Place
(40783, 0, 0, 0, 0, 0, 0, 0, 0, 'Well met, champion. $B$BAre you ready for the burden you must bear?', 63704), -- The Scythe of Elune
(40646, 1, 0, 0, 0, 0, 0, 0, 0, 'Excellent choice, $n!$b$bWith the power of that weapon in your hands we will be able to bring balance back to Azeroth.', 63704), -- Weapons of Legend
(53720, 1, 2, 0, 0, 0, 0, 0, 0, 'I accept this gesture in the spirit in which it was made, $n.\n\nThe Kul Tirans have been valuable allies, and now we have a physical manifestation of that bond.\n\nI thank you for your continued support of the Alliance. We continue to grow with your aid.', 63660), -- Allegiance of Kul Tiras
(54851, 1, 2, 0, 0, 0, 0, 0, 0, 'It has been so long since I have seen such a rite performed. I was only a child.\n\nIt means a great deal to me to have had your help in this. Thank you.', 63660), -- Blessing of the Tides
(54735, 273, 0, 0, 0, 0, 0, 0, 0, 'This is a fine group you\'ve assembled. Very well done.', 63660), -- A Worthy Crew
(54734, 274, 0, 0, 0, 0, 0, 0, 0, 'I\'m not fond of nobles sticking their nose in my work before it\'s finished. Deal with this.', 63660); -- Summons from Dorian

UPDATE `quest_offer_reward` SET `VerifiedBuild`=63834 WHERE `ID` IN (40077, 40567, 40794, 38203, 42369, 42367, 42368, 42375, 38237, 38232, 38460, 37657, 37659, 37654, 38857, 37566, 37565, 37538, 37536, 37510, 37542, 37528, 37507, 37496, 37470, 37530, 37469, 37730, 37729, 42371, 42370, 37518, 37678, 37736, 37468, 37467, 37486, 42694, 42692, 42693, 37497, 37257, 38407, 37492, 37728, 37727, 37733, 37256, 37690, 42756, 42567, 38014, 38015, 37862, 37861, 37959, 37960, 37857, 37957, 37859, 37856, 37855, 42271, 37991, 37853, 38443, 37449, 37450, 37656, 36920, 37660, 37658, 37653, 38834, 41220, 39718, 42630, 39772, 40345, 40339, 39769, 39768, 39765, 39656, 40000, 39670, 39386, 40228, 39867, 39178, 40216, 39124, 39123, 39392, 39859, 40170, 37860, 42220, 39781, 40072, 44545, 39774, 39773, 39764, 39780, 40594);
UPDATE `quest_offer_reward` SET `VerifiedBuild`=63796 WHERE `ID` IN (39321, 38910, 42233, 39318, 38913, 44009, 40890, 43596, 38684, 41893, 41724, 43576, 41708, 38671, 41707, 39731, 41056, 38753, 38582, 38595, 38663, 38662, 38655, 38641, 38377, 38322, 39354, 38225, 38235, 38147, 38144, 38145, 38143, 38246, 38922, 38455, 42622, 39580, 39579, 39577, 39578, 40219, 39575, 38916, 39992, 40388, 39990, 39988, 40112, 39983, 40520, 42590, 39133, 39134, 40167, 40515, 42596, 38909, 39027, 39043, 39026, 39025, 42104, 39498, 39487, 39489, 39488, 39661, 39572, 39277, 39614, 39323, 39316, 39496, 39491, 39272, 39490, 38911, 38907, 39733, 42751, 42786, 42750, 42747, 42748, 38719, 38721, 38724, 38717, 38714, 38715, 38718, 38691, 38644, 39117, 38646, 38645, 38647, 38643, 38743, 38687, 43702, 42512, 42088, 39776, 39777, 39862, 38915, 39387, 39456, 40230, 40102, 40049, 40047, 40045, 39437, 39438, 39439, 39440, 40229, 39426, 39588, 39425, 39391, 39381, 39860, 39455, 39374, 39873, 39372, 39373, 38912, 39322, 39429);
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=63704 WHERE `ID`=45727; -- Uniting the Isles
UPDATE `quest_offer_reward` SET `VerifiedBuild`=63704 WHERE `ID` IN (42483, 39792, 39786, 39793, 39787, 42447, 42445, 42446, 42444, 39789, 42641, 42645, 42639, 42635, 40044, 43595, 40046, 39984, 39405, 39122, 39092, 39063, 39062, 39472, 39060, 39061, 40005, 40004, 40003, 40002, 40001, 39059, 40078, 39855, 39853, 39851, 39850, 39849, 39857, 39848, 38347, 38324, 38339, 39837, 38818, 38815, 38823, 38816, 38817, 39791, 38811, 38808, 38810, 39788, 38778, 39796, 39804, 39803, 38624, 39652, 38413, 40568, 38414, 38412, 38342, 38410, 38405, 38318, 38312, 38473, 39597, 39594, 39593, 39592, 39591, 39595, 39590, 38331, 38210, 39775, 38060, 38058, 38059, 38057, 38053, 38558, 38036, 38052, 39800, 38206, 38035, 38142, 40573, 39384, 39383, 38382, 38384, 40221, 38862, 40220, 40122, 39735, 40645, 40644, 41106, 40643, 44663, 44120, 40593, 40517, 42740);
UPDATE `quest_offer_reward` SET `RewardText`='Well that was most noble of you to save these ancient relics from a water-logged fate.$B$BI will be sure that the Explorers\' League puts these to good use!', `VerifiedBuild`=63704 WHERE `ID`=42640; -- The Value of Knowledge
UPDATE `quest_offer_reward` SET `VerifiedBuild`=63660 WHERE `ID` IN (42782, 40519);

DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (107392,106482,108434,91172,107498,94561,93826,93805,108072,94318,97480,91531,97270,93446,91249,91519,90866)) OR (`Type`=1 AND `ID`=243836);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(107392, 0, 0, 0, 'The Ashen will protect Ashamane\'s legacy, no matter what.', 63834), -- 107392
(106482, 0, 1, 50, 'If we do not stop Xavius, the Nightmare will consume all of Azeroth.', 63834), -- 106482
(108434, 0, 0, 0, 'Dargrul the Underking is using my people as fodder for his new toy and army. He thinks by defeating us it will prepare him for the coming of the Burning Legion.$b$bWhen I\'m done with him, he will wish he had faced the Burning Legion instead.', 63796), -- 108434
(91172, 0, 0, 0, '', 63796), -- 91172
(107498, 0, 0, 0, 'Caw?', 63704), -- 107498
(94561, 0, 0, 0, 'My duty is to the Chieftain of Highmountain and no other.', 63796), -- 94561
(93826, 0, 0, 0, 'Dargrul the Underking is using my people as fodder for his new toy and army. He thinks by defeating us it will prepare him for the coming of the Burning Legion.$b$bWhen I\'m done with him, he will wish he had faced the Burning Legion instead.', 63796), -- 93826
(93805, 0, 0, 0, 'It was I who told the Chieftains and the Underking that we would need to give the Hammer of Khaz\'goroth to outsiders so that the Legion could be defeated. I just did not understand how violent the Underking\'s response would be.', 63796), -- 93805
(108072, 0, 0, 0, 'What-ho traveller! What brings you to these dusty ruins?', 63704), -- 108072
(94318, 0, 0, 0, 'We must act swiftly if we wish to apprehend the Banshee Queen. $B$BAre you prepared to answer the call of duty, $c?', 63704), -- 94318
(97480, 0, 0, 0, 'We face a formidable foe, but we must not let Helya win.', 63704), -- 97480
(91531, 0, 0, 0, 'I\'m sure ye don\'t belong here in Helheim, just like me.  $B$BI just hope Helya agrees with us.', 63704), -- 91531
(97270, 0, 0, 0, 'What have you uncovered in Haustvald, outsider?', 63704), -- 97270
(93446, 0, 0, 0, 'The Mystics have committed an unforgivable heresy here. The Valkyra will not forget this trespass.', 63704), -- 93446
(91249, 0, 0, 0, 'You... $B$BYou are not like the others.', 63704), -- 91249
(91519, 0, 0, 0, 'We\'re almost there, just one small problem...', 63704), -- 91519
(243836, 1, 0, 0, 'This cannot be! What kind of gall does this Skovald have to disregard these ancient rites! $B$BThis must not stand!', 63704), -- 243836
(90866, 0, 0, 0, 'Those freaks managed to blow what was left of our ammunition stores; it\'s a miracle the ship held together as long as she did!', 63704); -- 90866


DELETE FROM `quest_details` WHERE `ID` IN (44486 /*Fel-Ravaged Tome*/, 82809 /*Gryphons of a Feather*/, 46798 /*Paragon of the Valarjar*/, 90115 /*Infinite Research: Combat Studies, Groverunner*/, 90108 /*Infinite Research: Artifact Collector*/, 90102 /*Infinite Research: Champion of the Broken Isles*/, 89517 /*Infinite Research: Assault on Violet Hold, Heroic*/, 89665 /*Infinite Research: Time to Raid, Tormented Guardians*/, 40071 /*Tamer Takedown*/, 40070 /*Eagle Egg Recovery*/, 40069 /*Fledgling Worm Guts*/, 43331 /*Time to Collect*/, 92440 /*Infinite Research: Combat Studies, Stormrunner*/, 44284 /*The Emerald Nightmare: Piercing the Veil*/, 44232 /*The Grove Provides*/, 91721 /*Surpass Your Own Legend*/, 92439 /*Infinite Research: Combat Studies, Felrunner*/, 90100 /*Infinite Research: Combat Studies, Rare Elites*/, 42037 /*Gathering the Dreamweavers*/, 40654 /*Druids of the Claw*/, 43991 /*The Protectors*/, 93118 /*Infinite Research: Special Assignment, Power Overwhelming*/, 93117 /*Infinite Research: Special Assignment, Boss Rush*/, 89469 /*Infinite Research: Dungeoneers Wanted, Heroic*/, 93056 /*A Lesson in Alacrity*/, 39354 /*Wisp in the Willows*/, 42034 /*Grip of Nightmare*/, 41468 /*Mistress of the Claw*/, 45727 /*Uniting the Isles*/, 93116 /*Infinite Research: Special Assignment, Here to Slay*/, 93114 /*Infinite Research: Special Assignment, Sampling the World*/, 42483 /*Put It All on Red*/, 39786 /*A Stone Cold Gamble*/, 39792 /*A Stack of Racks*/, 42447 /*Dances With Ravenbears*/, 42445 /*Nithogg's Tribute*/, 42446 /*Singed Feathers*/, 42444 /*Plight of the Blackfeather*/, 44285 /*The Emerald Nightmare: Piercing the Veil*/, 89551 /*Infinite Research: Halls of Valor, Heroic*/, 93120 /*Infinite Research: Special Assignment, A World to Explore*/, 44283 /*The Emerald Nightmare: Piercing the Veil*/, 42590 /*Moozy's Reunion*/, 42751 /*Moon Reaver*/, 42786 /*Grotesque Remains*/, 42750 /*Dreamcatcher*/, 42747 /*Where the Wildkin Are*/, 42748 /*Emerald Sisters*/, 39787 /*Rigging the Wager*/, 39793 /*Only the Finest*/, 39789 /*Eating Into Our Business*/, 43596 /*Maw of Souls: Piercing the Mists*/, 40044 /*Shadows in the Mists*/, 43595 /*To Honor the Fallen*/, 40046 /*Scavenging the Shallows*/, 39984 /*Remnants of the Past*/, 93055 /*Extracurriculars*/, 91061 /*Infinite Chaos*/, 93113 /*Infinite Research: Special Assignment, Rare Dare*/, 93112 /*Infinite Research: Special Assignment, Fel Skies*/, 92430 /*Embracing the Infinite Chaos*/, 92563 /*Awoken by Accessory*/, 90754 /*Skyriding*/, 91639 /*Embrace Your Own Legend*/, 90892 /*Clearing the Skies: A Fel of a Time*/, 89418 /*A Fixed Point in Time*/, 91955 /*Just Between Us*/, 89417 /*Infinite Meetings*/, 89416 /*Eternal Gratitude*/, 89415 /*Storm the Citadel*/, 89414 /*Not A Memento Too Soon*/, 89413 /*Obliterate, Then Iterate*/, 89411 /*Scavenger Hunting*/, 89412 /*Get Plenty of Exorcise*/, 90901 /*As A Matter of Artifact*/, 90659 /*Something Borrowed*/, 89409 /*Infinite Bronze*/, 89408 /*Threadbare*/, 89407 /*Thrift*/, 89406 /*Seal and Protect*/, 89405 /*Mean Streets of Dalaran*/, 89404 /*Time Crisis*/, 42454 /*The Hammer of Khaz'goroth*/, 42430 /*The Fangs of Ashamane*/, 42440 /*The Shrine in Peril*/, 42438 /*Seeds of Renewal*/, 42439 /*Aid for the Ashen*/, 42428 /*The Shrine of Ashamane*/, 89524 /*Infinite Research: Maw of Souls, Normal*/, 90109 /*Infinite Research: Clear the Skies*/, 44431 /*More Weapons of Old*/, 43349 /*The Aegis of Aggramar*/, 89549 /*Infinite Research: Neltharion's Lair, Heroic*/, 89550 /*Infinite Research: Halls of Valor, Normal*/, 41918 /*The Dreamer Returns*/, 40647 /*When Dreams Become Nightmares*/, 41792 /*The Third Trial of Ursol*/, 41791 /*The Second Trial of Ursol*/, 41790 /*The First Trial of Ursol*/, 42045 /*Communing With Malorne*/, 42044 /*A Dying Dream*/, 42042 /*Teensy Weensies!*/, 42043 /*Cleaning Up*/, 42041 /*Enduring the Nightmare*/, 42040 /*The Way to Nordrassil*/, 91722 /*Shape a New Legend*/, 41782 /*To The Hills*/, 44076 /*Darkheart Thicket: Essence of Regrowth*/, 44074 /*Neltharion's Lair: Essence of Tenacity*/, 44077 /*Eye of Azshara: Essence of Balance*/, 44075 /*Halls of Valor: Essence of Ferocity*/, 39305 /*Empty Nest*/, 42425 /*Going Down, Going Up*/, 44106 /*Archdruid of Lore*/, 38862 /*Thieving Thistleleaf*/, 40220 /*Thorny Dancing*/, 40221 /*Spread Your Lunarwings and Fly*/, 42857 /*Moist Around the Hedges*/, 42884 /*Grassroots Effort*/, 42865 /*Grell to Pay*/, 42883 /*All Grell Broke Loose*/, 42036 /*Idol of the Wilds*/, 42035 /*Tracking the Enemy*/, 44009 /*A Falling Star*/, 42033 /*Malorne's Refuge*/, 42031 /*Dire Growth*/, 42032 /*Sampling the Nightmare*/, 42588 /*Branching Out*/, 42586 /*A Glade Defense*/, 42585 /*Recruiting the Troops*/, 42584 /*Sister Lilith*/, 43980 /*Another Weapon of Old*/, 42583 /*Rise, Champions*/, 40653 /*Making Trails*/, 40652 /*Word on the Winds*/, 41332 /*Ascending The Circle*/, 41255 /*Sowing The Seed*/, 92688 /*Bronze Simulacrum*/, 40900 /*The Burden Borne*/, 40838 /*The Dark Riders*/, 40837 /*The Deadwind Hunt*/, 40835 /*Disturbing the Past*/, 40834 /*Following the Curse*/, 40785 /*A Foe of the Dark*/, 40784 /*Its Rightful Place*/, 40783 /*The Scythe of Elune*/, 44663 /*In the Blink of an Eye*/, 53720 /*Allegiance of Kul Tiras*/, 54851 /*Blessing of the Tides*/, 54735 /*A Worthy Crew*/, 54734 /*Summons from Dorian*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(44486, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Fel-Ravaged Tome
(82809, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Gryphons of a Feather
(46798, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Paragon of the Valarjar
(90115, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Combat Studies, Groverunner
(90108, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Artifact Collector
(90102, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Champion of the Broken Isles
(89517, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Assault on Violet Hold, Heroic
(89665, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Time to Raid, Tormented Guardians
(40071, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Tamer Takedown
(40070, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Eagle Egg Recovery
(40069, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Fledgling Worm Guts
(43331, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- Time to Collect
(92440, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Combat Studies, Stormrunner
(44284, 1, 0, 0, 0, 50, 0, 0, 0, 63796), -- The Emerald Nightmare: Piercing the Veil
(44232, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- The Grove Provides
(91721, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Surpass Your Own Legend
(92439, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Combat Studies, Felrunner
(90100, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Combat Studies, Rare Elites
(42037, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- Gathering the Dreamweavers
(40654, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Druids of the Claw
(43991, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- The Protectors
(93118, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Special Assignment, Power Overwhelming
(93117, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Special Assignment, Boss Rush
(89469, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Dungeoneers Wanted, Heroic
(93056, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- A Lesson in Alacrity
(39354, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Wisp in the Willows
(42034, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Grip of Nightmare
(41468, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Mistress of the Claw
(45727, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Uniting the Isles
(93116, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Infinite Research: Special Assignment, Here to Slay
(93114, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Infinite Research: Special Assignment, Sampling the World
(42483, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Put It All on Red
(39786, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- A Stone Cold Gamble
(39792, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- A Stack of Racks
(42447, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Dances With Ravenbears
(42445, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Nithogg's Tribute
(42446, 403, 0, 0, 0, 0, 0, 0, 0, 63704), -- Singed Feathers
(42444, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Plight of the Blackfeather
(44285, 1, 0, 0, 0, 50, 0, 0, 0, 63834), -- The Emerald Nightmare: Piercing the Veil
(89551, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Halls of Valor, Heroic
(93120, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Infinite Research: Special Assignment, A World to Explore
(44283, 1, 0, 0, 0, 50, 0, 0, 0, 63796), -- The Emerald Nightmare: Piercing the Veil
(42590, 2, 1, 0, 0, 0, 3000, 0, 0, 63796), -- Moozy's Reunion
(42751, 603, 0, 0, 0, 0, 0, 0, 0, 63796), -- Moon Reaver
(42786, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- Grotesque Remains
(42750, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- Dreamcatcher
(42747, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Where the Wildkin Are
(42748, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Emerald Sisters
(39787, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Rigging the Wager
(39793, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Only the Finest
(39789, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Eating Into Our Business
(43596, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Maw of Souls: Piercing the Mists
(40044, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Shadows in the Mists
(43595, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- To Honor the Fallen
(40046, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Scavenging the Shallows
(39984, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Remnants of the Past
(93055, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Extracurriculars
(91061, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Infinite Chaos
(93113, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Infinite Research: Special Assignment, Rare Dare
(93112, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Infinite Research: Special Assignment, Fel Skies
(92430, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Embracing the Infinite Chaos
(92563, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Awoken by Accessory
(90754, 1, 0, 0, 0, 0, 0, 0, 0, 63660), -- Skyriding
(91639, 1, 0, 0, 0, 0, 0, 0, 0, 63660), -- Embrace Your Own Legend
(90892, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Clearing the Skies: A Fel of a Time
(89418, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- A Fixed Point in Time
(91955, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Just Between Us
(89417, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Infinite Meetings
(89416, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Eternal Gratitude
(89415, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Storm the Citadel
(89414, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Not A Memento Too Soon
(89413, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Obliterate, Then Iterate
(89411, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Scavenger Hunting
(89412, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Get Plenty of Exorcise
(90901, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- As A Matter of Artifact
(90659, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Something Borrowed
(89409, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Infinite Bronze
(89408, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Threadbare
(89407, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Thrift
(89406, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Seal and Protect
(89405, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Mean Streets of Dalaran
(89404, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Time Crisis
(42454, 5, 1, 0, 0, 0, 0, 0, 0, 63834), -- The Hammer of Khaz'goroth
(42430, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Fangs of Ashamane
(42440, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Shrine in Peril
(42438, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Seeds of Renewal
(42439, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Aid for the Ashen
(42428, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Shrine of Ashamane
(89524, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Maw of Souls, Normal
(90109, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Clear the Skies
(44431, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- More Weapons of Old
(43349, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Aegis of Aggramar
(89549, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Neltharion's Lair, Heroic
(89550, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Infinite Research: Halls of Valor, Normal
(41918, 1, 603, 273, 0, 0, 900, 500, 0, 63834), -- The Dreamer Returns
(40647, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- When Dreams Become Nightmares
(41792, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Third Trial of Ursol
(41791, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Second Trial of Ursol
(41790, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- The First Trial of Ursol
(42045, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Communing With Malorne
(42044, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- A Dying Dream
(42042, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Teensy Weensies!
(42043, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Cleaning Up
(42041, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Enduring the Nightmare
(42040, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- The Way to Nordrassil
(91722, 1, 0, 0, 0, 0, 0, 0, 0, 63834), -- Shape a New Legend
(41782, 1, 6, 0, 0, 0, 500, 0, 0, 63834), -- To The Hills
(44076, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Darkheart Thicket: Essence of Regrowth
(44074, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Neltharion's Lair: Essence of Tenacity
(44077, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Eye of Azshara: Essence of Balance
(44075, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Halls of Valor: Essence of Ferocity
(39305, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Empty Nest
(42425, 1, 0, 0, 0, 0, 0, 0, 0, 63796), -- Going Down, Going Up
(44106, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Archdruid of Lore
(38862, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Thieving Thistleleaf
(40220, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Thorny Dancing
(40221, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Spread Your Lunarwings and Fly
(42857, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Moist Around the Hedges
(42884, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Grassroots Effort
(42865, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Grell to Pay
(42883, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- All Grell Broke Loose
(42036, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Idol of the Wilds
(42035, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Tracking the Enemy
(44009, 1, 1, 1, 0, 0, 0, 0, 0, 63704), -- A Falling Star
(42033, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Malorne's Refuge
(42031, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Dire Growth
(42032, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Sampling the Nightmare
(42588, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Branching Out
(42586, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- A Glade Defense
(42585, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Recruiting the Troops
(42584, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Sister Lilith
(43980, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Another Weapon of Old
(42583, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Rise, Champions
(40653, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Making Trails
(40652, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Word on the Winds
(41332, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Ascending The Circle
(41255, 1, 0, 0, 0, 0, 0, 0, 0, 63704), -- Sowing The Seed
(92688, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Bronze Simulacrum
(40900, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- The Burden Borne
(40838, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- The Dark Riders
(40837, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- The Deadwind Hunt
(40835, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Disturbing the Past
(40834, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Following the Curse
(40785, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- A Foe of the Dark
(40784, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Its Rightful Place
(40783, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- The Scythe of Elune
(44663, 1, 1, 0, 0, 0, 500, 0, 0, 63704), -- In the Blink of an Eye
(53720, 1, 0, 0, 0, 0, 0, 0, 0, 63660), -- Allegiance of Kul Tiras
(54851, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Blessing of the Tides
(54735, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- A Worthy Crew
(54734, 0, 0, 0, 0, 0, 0, 0, 0, 63660); -- Summons from Dorian

UPDATE `quest_details` SET `VerifiedBuild`=63834 WHERE `ID` IN (40077, 38203, 42367, 42368, 42369, 42375, 38237, 38232, 38460, 40794, 37659, 42220, 37657, 37654, 38857, 37566, 37565, 37538, 37536, 37510, 37542, 37528, 37507, 38286, 37470, 37530, 37469, 37730, 37729, 42371, 42370, 37518, 37678, 37736, 37468, 37467, 42694, 42692, 42693, 37486, 37497, 37496, 38407, 37492, 37728, 37727, 37257, 37733, 37256, 42756, 42567, 38014, 38015, 37862, 37861, 37860, 37959, 37960, 37857, 37957, 37859, 37856, 37855, 37690, 42271, 37991, 37853, 38443, 37449, 37450, 37656, 36920, 37660, 37658, 37653, 38834, 41220, 42630, 39772, 40345, 40339, 39769, 39768, 39765, 39656, 40000, 39670, 39386, 40228, 39178, 39867, 39123, 39124, 39392, 40216, 39859, 40170, 39718, 39774, 39773, 39764, 39781, 39780);
UPDATE `quest_details` SET `VerifiedBuild`=63796 WHERE `ID` IN (39429, 39321, 38910, 39318, 44545, 44004, 43702, 38684, 41893, 41724, 43576, 41708, 38671, 41707, 41056, 38753, 38582, 38595, 38663, 38655, 38662, 38641, 38377, 38322, 38225, 38235, 38147, 38144, 38145, 38143, 38246, 39580, 39579, 39577, 39578, 40219, 39575, 42622, 38916, 39992, 40388, 39990, 39988, 40112, 39983, 39133, 39134, 40520, 40167, 42596, 40515, 38913, 38912, 38909, 39027, 39043, 39026, 39025, 42104, 39498, 39487, 39489, 39488, 39661, 39572, 39323, 39277, 39316, 39614, 39496, 39272, 39490, 39491, 38911, 38907, 39733, 38721, 38719, 38724, 38717, 38715, 38714, 38718, 38691, 39117, 38646, 38644, 38647, 38645, 38643, 40890, 40567, 38743, 38687, 40594, 42512, 42088, 39862, 39777, 39776, 38915, 40230, 40102, 40049, 40047, 40045, 39437, 39438, 39439, 39440, 39456, 40229, 39426, 39588, 39425, 39391, 39381, 39860, 39455, 39374, 39873, 39373, 39372, 39387, 39322);
UPDATE `quest_details` SET `VerifiedBuild`=63704 WHERE `ID` IN (40122, 39731, 45088, 42645, 42641, 42639, 42635, 42640, 39122, 39092, 39405, 39063, 39062, 39472, 40072, 40005, 40004, 40003, 40002, 39061, 39060, 40001, 39059, 40078, 39855, 39853, 39851, 39850, 39849, 39857, 39848, 38347, 38324, 38339, 39837, 38818, 38815, 38823, 38816, 38817, 39791, 38811, 38808, 38810, 39788, 38778, 39796, 39804, 39803, 38624, 39652, 40568, 38413, 38414, 38412, 38342, 38410, 38405, 38318, 38312, 38473, 39597, 39594, 39593, 39592, 39591, 39595, 39590, 38331, 38210, 38060, 38059, 38057, 38058, 38558, 38053, 38036, 38052, 39800, 38206, 38922, 38455, 40573, 39384, 39383, 38142, 38382, 38384, 38035, 39735, 40646, 40645, 40644, 41106, 40643, 44120, 40593, 40517);
UPDATE `quest_details` SET `VerifiedBuild`=63660 WHERE `ID` IN (42740, 42782, 40519);

DELETE FROM `quest_request_items` WHERE `ID` IN (42440 /*The Shrine in Peril*/, 42439 /*Aid for the Ashen*/, 42438 /*Seeds of Renewal*/, 42425 /*Going Down, Going Up*/, 42420 /*Court of Farondis*/, 90659 /*Something Borrowed*/, 44285 /*The Emerald Nightmare: Piercing the Veil*/, 44284 /*The Emerald Nightmare: Piercing the Veil*/, 44283 /*The Emerald Nightmare: Piercing the Veil*/, 38460 /*Let's Make A Deal*/, 38413 /*Wings of Liberty*/, 38412 /*Above the Winter Moonlight*/, 92440 /*Infinite Research: Combat Studies, Stormrunner*/, 42234 /*The Valarjar*/, 92439 /*Infinite Research: Combat Studies, Felrunner*/, 38331 /*Havi's Test*/, 40219 /*In Defiance of Deathwing*/, 44076 /*Darkheart Thicket: Essence of Regrowth*/, 44075 /*Halls of Valor: Essence of Ferocity*/, 44074 /*Neltharion's Lair: Essence of Tenacity*/, 38206 /*Making the Rounds*/, 43991 /*The Protectors*/, 42044 /*A Dying Dream*/, 42043 /*Cleaning Up*/, 42042 /*Teensy Weensies!*/, 42041 /*Enduring the Nightmare*/, 42036 /*Idol of the Wilds*/, 42031 /*Dire Growth*/, 38147 /*Entangled Dreams*/, 40071 /*Tamer Takedown*/, 40070 /*Eagle Egg Recovery*/, 40069 /*Fledgling Worm Guts*/, 39990 /*Huln's War - Reinforcements*/, 41893 /*Given to Corruption*/, 90115 /*Infinite Research: Combat Studies, Groverunner*/, 90109 /*Infinite Research: Clear the Skies*/, 90108 /*Infinite Research: Artifact Collector*/, 90102 /*Infinite Research: Champion of the Broken Isles*/, 90100 /*Infinite Research: Combat Studies, Rare Elites*/, 37957 /*Runas the Shamed*/, 41792 /*The Third Trial of Ursol*/, 41791 /*The Second Trial of Ursol*/, 41790 /*The First Trial of Ursol*/, 41782 /*To The Hills*/, 91955 /*Just Between Us*/, 37656 /*Fel Machinations*/, 91722 /*Shape a New Legend*/, 91721 /*Surpass Your Own Legend*/, 91639 /*Embrace Your Own Legend*/, 43331 /*Time to Collect*/, 89665 /*Infinite Research: Time to Raid, Tormented Guardians*/, 39456 /*Unexpected Allies*/, 39455 /*Cave of the Blood Trial*/, 54851 /*Blessing of the Tides*/, 41332 /*Ascending The Circle*/, 39387 /*The Skies of Highmountain*/, 89551 /*Infinite Research: Halls of Valor, Heroic*/, 89550 /*Infinite Research: Halls of Valor, Normal*/, 89549 /*Infinite Research: Neltharion's Lair, Heroic*/, 89524 /*Infinite Research: Maw of Souls, Normal*/, 89517 /*Infinite Research: Assault on Violet Hold, Heroic*/, 39305 /*Empty Nest*/, 45088 /*Trial of Valor: The Lost Army*/, 54735 /*A Worthy Crew*/, 54734 /*Summons from Dorian*/, 89469 /*Infinite Research: Dungeoneers Wanted, Heroic*/, 89417 /*Infinite Meetings*/, 89415 /*Storm the Citadel*/, 89413 /*Obliterate, Then Iterate*/, 89412 /*Get Plenty of Exorcise*/, 89411 /*Scavenger Hunting*/, 89409 /*Infinite Bronze*/, 89408 /*Threadbare*/, 89407 /*Thrift*/, 89406 /*Seal and Protect*/, 93120 /*Infinite Research: Special Assignment, A World to Explore*/, 93118 /*Infinite Research: Special Assignment, Power Overwhelming*/, 93117 /*Infinite Research: Special Assignment, Boss Rush*/, 93116 /*Infinite Research: Special Assignment, Here to Slay*/, 93114 /*Infinite Research: Special Assignment, Sampling the World*/, 93113 /*Infinite Research: Special Assignment, Rare Dare*/, 93112 /*Infinite Research: Special Assignment, Fel Skies*/, 42884 /*Grassroots Effort*/, 42883 /*All Grell Broke Loose*/, 42865 /*Grell to Pay*/, 42857 /*Moist Around the Hedges*/, 93055 /*Extracurriculars*/, 91061 /*Infinite Chaos*/, 38909 /*Get to High Ground*/, 40838 /*The Dark Riders*/, 40783 /*The Scythe of Elune*/, 90901 /*As A Matter of Artifact*/, 40647 /*When Dreams Become Nightmares*/, 40568 /*Fury of the Storm*/, 92688 /*Bronze Simulacrum*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(42440, 0, 0, 0, 0, 'Did you check on that disturbance?', 63834), -- The Shrine in Peril
(42439, 0, 0, 0, 0, 'Did you have any success out there?', 63834), -- Aid for the Ashen
(42438, 0, 0, 0, 0, 'Have the Tel\'andu seeds?', 63834), -- Seeds of Renewal
(42425, 1, 1, 0, 0, 'I have never been particularly fond of heights.', 63834), -- Going Down, Going Up
(42420, 0, 0, 0, 0, 'Return to me when you have finished aiding the Court of Farondis, $n.', 63834), -- Court of Farondis
(90659, 0, 0, 0, 0, 'Every artifacts needs a mighty hero to wield it.', 63834), -- Something Borrowed
(44285, 0, 0, 0, 0, 'If only Cenarius were with us, we could confront Xavius at once.', 63834), -- The Emerald Nightmare: Piercing the Veil
(44284, 0, 0, 0, 0, 'If only Cenarius were with us, we could confront Xavius at once.', 63834), -- The Emerald Nightmare: Piercing the Veil
(44283, 0, 0, 0, 0, 'If only Cenarius were with us, we could confront Xavius at once.', 63834), -- The Emerald Nightmare: Piercing the Veil
(38460, 0, 0, 0, 0, 'Yeah! Yeah! You read the contract? I made it myself. Really good binding clauses in there.', 63834), -- Let's Make A Deal
(38413, 0, 0, 0, 0, 'What news do you bring of my brothers and sisters?', 63834), -- Wings of Liberty
(38412, 0, 0, 0, 0, '', 63834), -- Above the Winter Moonlight
(92440, 0, 1, 0, 0, 'Remember to pace yourself, the journey is just as important as the destination.', 63834), -- Infinite Research: Combat Studies, Stormrunner
(42234, 0, 0, 0, 0, 'Return to me when you have finished aiding the Valarjar, $n.', 63834), -- The Valarjar
(92439, 0, 1, 0, 0, 'Remember to pace yourself, the journey is just as important as the destination.', 63834), -- Infinite Research: Combat Studies, Felrunner
(38331, 0, 0, 0, 0, 'Smells good, doesn\'t it?', 63834), -- Havi's Test
(40219, 0, 0, 0, 0, 'You are learning parts of our history few outsiders have ever known.', 63834), -- In Defiance of Deathwing
(44076, 0, 0, 0, 0, 'My heart aches for those fallen to the Nightmare.', 63834), -- Darkheart Thicket: Essence of Regrowth
(44075, 0, 0, 0, 0, 'It takes a ferocious beast to take down another ferocious beast.', 63834), -- Halls of Valor: Essence of Ferocity
(44074, 0, 0, 0, 0, 'Stand firm, druid.', 63834), -- Neltharion's Lair: Essence of Tenacity
(38206, 0, 0, 0, 0, 'As soon as preparations are complete, we set out for Stormheim.', 63834), -- Making the Rounds
(43991, 0, 0, 0, 0, 'Did you find the druidic stones? A sapling needs to be nurtured, and a candle lit with arcane fire. A tenacious guardian may only appear to one as tenacious as itself, and a ferocious hunter often camouflages itself in the shadows.', 63834), -- The Protectors
(42044, 0, 0, 0, 0, 'No one is safe from the Nightmare.', 63834), -- A Dying Dream
(42043, 0, 0, 0, 0, 'Did you restore the Dream?', 63834), -- Cleaning Up
(42042, 0, 0, 0, 0, 'Ohhh, the teensy weensy fae dragons are so cute! Are they all right?', 63834), -- Teensy Weensies!
(42041, 0, 0, 0, 0, 'Is it done?', 63834), -- Enduring the Nightmare
(42036, 0, 0, 0, 0, 'Did you recover the Idol of the Wilds?', 0), -- Idol of the Wilds
(42031, 0, 0, 0, 0, 'I have never seen anything like this...', 63834), -- Dire Growth
(38147, 0, 0, 0, 0, 'Someone entangled us within a sinister spell.', 63834), -- Entangled Dreams
(40071, 0, 0, 0, 0, 'Put an end to Tamer Korgrul, so that we may also put an end to the training of siege worms.', 63834), -- Tamer Takedown
(40070, 1, 1, 0, 0, 'If the pilfered eggs are not recovered, the eagle may go extinct.', 63834), -- Eagle Egg Recovery
(40069, 1, 1, 0, 0, 'What are their guts for? Well, you\'ll see. You might not like it, but you will soon find out.', 63834), -- Fledgling Worm Guts
(39990, 0, 0, 0, 0, 'This shouldn\'t take long. Please do not allow them to interrupt my spell.', 63834), -- Huln's War - Reinforcements
(41893, 0, 0, 0, 0, 'Is it done, then?', 63834), -- Given to Corruption
(90115, 0, 1, 0, 0, 'Remember to pace yourself, the journey is just as important as the destination.', 63834), -- Infinite Research: Combat Studies, Groverunner
(90109, 0, 1, 0, 0, 'This timeline is pockmarked with time motes. Gather as many as you can.', 63834), -- Infinite Research: Clear the Skies
(90108, 0, 1, 0, 0, 'By their very nature these artifacts are no easy task to acquire, but if anyone can do it, you can.', 63834), -- Infinite Research: Artifact Collector
(90102, 0, 1, 0, 0, 'The Broken Isles yearn for a champion to save them. Is your legend up to the challenge?', 63834), -- Infinite Research: Champion of the Broken Isles
(90100, 0, 1, 0, 0, 'We need more fight data to complete our study, and time is running short.', 63834), -- Infinite Research: Combat Studies, Rare Elites
(37957, 0, 0, 0, 0, 'Ah, Stella. Always so quick to act. She is still young.', 63834), -- Runas the Shamed
(41792, 0, 0, 0, 0, '<The ancient stares at you expectantly.>', 63834), -- The Third Trial of Ursol
(41791, 0, 0, 0, 0, '<The ancient stares at you expectantly.>', 63834), -- The Second Trial of Ursol
(41790, 0, 0, 0, 0, '<The ancient stares at you expectantly.>', 63834), -- The First Trial of Ursol
(41782, 0, 0, 0, 0, 'Did you get the moonwell water? It is essential for our task!', 0), -- To The Hills
(91955, 0, 1, 0, 0, 'I can still smell the bronze used to make that simulacrum. Have you recovered it yet?', 63834), -- Just Between Us
(37656, 0, 396, 0, 0, 'If we\'re to defeat the Legion, we need to know exactly what they\'re up to.', 63834), -- Fel Machinations
(91722, 0, 1, 0, 0, 'An artifact cannot empower itself. Its power grows only when its wielder performs great deeds with it.', 63834), -- Shape a New Legend
(91721, 0, 1, 0, 0, 'The person wielding an artifact is of some importance. But how much? Which legend is the greater?\n\nLet us find out together.', 63834), -- Surpass Your Own Legend
(91639, 0, 1, 0, 0, 'We are on a journey of learning and discovery. Let us walk it together.', 63834), -- Embrace Your Own Legend
(43331, 26, 0, 0, 0, 'This seems to be where the Sixtrigger brothers keep their most prized spoils.', 0), -- Time to Collect
(89665, 0, 1, 0, 0, 'Time is running short and we need that group data, $p.', 63834), -- Infinite Research: Time to Raid, Tormented Guardians
(39456, 0, 0, 0, 0, 'Has Torok agreed to join us?', 63834), -- Unexpected Allies
(39455, 0, 0, 0, 0, 'Are you afraid of the dark?', 63834), -- Cave of the Blood Trial
(54851, 0, 0, 0, 0, 'I chose you for this honor to thank you for all you have done for my people, and all that you have done for me.', 63834), -- Blessing of the Tides
(41332, 0, 0, 0, 0, 'Yes?', 63834), -- Ascending The Circle
(39387, 0, 0, 0, 0, 'Have you had any luck with Lasan?', 63834), -- The Skies of Highmountain
(89551, 0, 1, 0, 0, 'Well, you aren\'t dead. That\'s a good sign.', 63834), -- Infinite Research: Halls of Valor, Heroic
(89550, 0, 1, 0, 0, 'Well, you aren\'t dead. That\'s a good sign.', 63834), -- Infinite Research: Halls of Valor, Normal
(89549, 0, 1, 0, 0, 'Well, you aren\'t dead. That\'s a good sign.', 63834), -- Infinite Research: Neltharion's Lair, Heroic
(89524, 0, 1, 0, 0, 'Well, you aren\'t dead. That\'s a good sign.', 63834), -- Infinite Research: Maw of Souls, Normal
(89517, 0, 1, 0, 0, 'Well, you aren\'t dead. That\'s a good sign.', 63834), -- Infinite Research: Assault on Violet Hold, Heroic
(39305, 0, 1, 0, 0, 'If there\'s any hope for those eggs hatching, they\'ll need to be returned to their nest.', 63834), -- Empty Nest
(45088, 0, 0, 0, 0, 'Bring me the souls of my lost Valarjar. Only then will I reward you with the blessed armor you desire.', 63834), -- Trial of Valor: The Lost Army
(54735, 0, 0, 0, 0, 'Have you found a suitable crew?', 63834), -- A Worthy Crew
(54734, 0, 0, 0, 0, 'I see my little helper found you just fine.', 0), -- Summons from Dorian
(89469, 0, 1, 0, 0, 'Fear is expected, but results are necessary. Find a group and face the terror. If not for me, then do it for Moratari and the data points.', 63834), -- Infinite Research: Dungeoneers Wanted, Heroic
(89417, 0, 0, 0, 0, 'As their name would suggest, the infinite dragonflight is certainly not lacking in numbers.', 63834), -- Infinite Meetings
(89415, 0, 0, 0, 0, 'With Nezmet dead, Dalaran is saved.', 63834), -- Storm the Citadel
(89413, 0, 0, 0, 0, 'Happy scrapping!', 63834), -- Obliterate, Then Iterate
(89412, 0, 0, 0, 0, 'Sealing those Legion portals will slow them down considerably.', 63834), -- Get Plenty of Exorcise
(89411, 0, 0, 0, 0, 'One demon\'s trash is an infinite dragon\'s bronze.', 63834), -- Scavenger Hunting
(89409, 0, 0, 0, 0, 'Infinite bronze, a material loaded with potential.', 63834), -- Infinite Bronze
(89408, 0, 0, 0, 0, 'With this source of power Momentus should have what he needs to help you get an artifact.', 63834), -- Threadbare
(89407, 0, 0, 0, 0, 'These objects are loaded with epoch significance.', 63834), -- Thrift
(89406, 0, 0, 0, 0, 'Reinforcing the magical barriers should hold the Legion at bay until Khadgar can get this situation sorted out.', 63834), -- Seal and Protect
(93120, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, A World to Explore
(93118, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Power Overwhelming
(93117, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Boss Rush
(93116, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Here to Slay
(93114, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Sampling the World
(93113, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Rare Dare
(93112, 0, 0, 0, 0, 'With great power comes, in this timeline, even more power.', 63834), -- Infinite Research: Special Assignment, Fel Skies
(42884, 0, 0, 0, 0, 'My old bones need more rest than I would care to admit.', 63834), -- Grassroots Effort
(42883, 0, 0, 0, 0, 'The grell can sometimes be a terrible nuisance.', 63834), -- All Grell Broke Loose
(42865, 0, 0, 0, 0, 'I miss the days when grell kept to themselves and played tricks on the night elves.', 63834), -- Grell to Pay
(42857, 0, 0, 0, 0, 'You have found a fruit that might be of interest to me?', 0), -- Moist Around the Hedges
(93055, 0, 0, 0, 0, 'Back so soon? Perhaps I miscalculated how long you would spend procrastinating.', 63834), -- Extracurriculars
(91061, 0, 6, 0, 0, 'Have you seen the dark times that could have been?', 63834), -- Infinite Chaos
(38909, 0, 0, 0, 0, 'Have you had any luck with the Rivermane?', 63834), -- Get to High Ground
(40838, 0, 0, 0, 0, 'It is done.', 63834), -- The Dark Riders
(40783, 0, 0, 0, 0, 'The champion arrives. I hope you are prepared for this burden.', 63834), -- The Scythe of Elune
(90901, 0, 0, 0, 0, 'Unlocking the full potential of your artifact will be key to understanding their impact on this timeline.', 63834), -- As A Matter of Artifact
(40647, 0, 0, 0, 0, 'Have you retrieved the Claws of Ursoc?', 63834), -- When Dreams Become Nightmares
(40568, 0, 0, 0, 0, 'Are we rid of the Felskorn threat?', 63834), -- Fury of the Storm
(92688, 0, 0, 0, 0, 'You have something for Erus?', 0); -- Bronze Simulacrum

UPDATE `quest_request_items` SET `VerifiedBuild`=63834 WHERE `ID` IN (40520, 40517, 42447, 42446, 42445, 38558, 42375, 42371, 42370, 42369, 42368, 42367, 38455, 40345, 40339, 38405, 38347, 38339, 38324, 40230, 40228, 40221, 40220, 40216, 40170, 40167, 38235, 42088, 38225, 38203, 40102, 38145, 38144, 40049, 40047, 40046, 40045, 40044, 40002, 40000, 38053, 38052, 38036, 38035, 38015, 38014, 37960, 37959, 39867, 39862, 39853, 39851, 39850, 39849, 39848, 39793, 39792, 39788, 37856, 39787, 39786, 39777, 39776, 41707, 39774, 39768, 39765, 39764, 43595, 39670, 37736, 37729, 37728, 37727, 39656, 39614, 37678, 39593, 39592, 39591, 37658, 39588, 37657, 37653, 39491, 39490, 39489, 39488, 39487, 37542, 37528, 39440, 39439, 37507, 39438, 39437, 39429, 39426, 39425, 37492, 37486, 37469, 39392, 39391, 39374, 39373, 39372, 39354, 39321, 39318, 39316, 39277, 39272, 37257, 37256, 39178, 41106, 39134, 39133, 39124, 39123, 39117, 39061, 39060, 39043, 42748, 42747, 42694, 42693, 42692, 38810, 38808, 42645, 42641, 38778, 42639, 42635, 42630, 42622, 42596, 42590, 38684, 38671, 40594, 38662, 38655, 38647, 38646, 38645);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=63834 WHERE `ID`=37450; -- Saving Stellagosa

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=739 AND `QuestLineId` IN (5920,336,247,211,206,205,181)) OR (`UIMapId`=630 AND `QuestLineId` IN (5758,5761,5762,5757,5752,5760,5753,5927)) OR (`UIMapId`=680 AND `QuestLineId` IN (5762,5761,5752,5927,5924,5913,5911,5912)) OR (`UIMapId`=641 AND `QuestLineId` IN (5758,5922,5919,5918,5911,5765,5913,5912,5915)) OR (`UIMapId`=650 AND `QuestLineId` IN (5927,5922,5915,5921,5919,5918,5923,5924,5916,5914)) OR (`UIMapId`=750 AND `QuestLineId` IN (5915,5918,5914)) OR (`UIMapId`=627 AND `QuestLineId`=5927) OR (`UIMapId`=634 AND `QuestLineId` IN (5927,5922,5921,5919,5918,5915,5923,5924,5926,5925)) OR (`UIMapId`=652 AND `QuestLineId` IN (5918,89,5915)) OR (`UIMapId`=657 AND `QuestLineId`=148) OR (`UIMapId`=655 AND `QuestLineId`=89) OR (`UIMapId`=649 AND `QuestLineId`=135) OR (`UIMapId`=731 AND `QuestLineId` IN (5385,5375,923,143)) OR (`UIMapId`=2403 AND `QuestLineId` IN (5697,5691,5673,346)) OR (`UIMapId`=692 AND `QuestLineId`=5819) OR (`UIMapId`=659 AND `QuestLineId` IN (145,5917)) OR (`UIMapId`=706 AND `QuestLineId`=5806) OR (`UIMapId`=46 AND `QuestLineId`=947) OR (`UIMapId`=80 AND `QuestLineId` IN (5886,5882,210));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(739, 5920, 63834),
(739, 336, 63834),
(739, 247, 63834),
(739, 211, 63834),
(739, 206, 63834),
(739, 205, 63834),
(739, 181, 63834),
(630, 5758, 63834),
(630, 5761, 63834),
(630, 5762, 63834),
(630, 5757, 63834),
(630, 5752, 63834),
(630, 5760, 63834),
(630, 5753, 63834),
(680, 5762, 63834),
(680, 5761, 63834),
(680, 5752, 63834),
(641, 5758, 63834),
(650, 5927, 63834),
(650, 5922, 63834),
(750, 5915, 63834),
(650, 5915, 63834),
(650, 5921, 63834),
(650, 5919, 63834),
(650, 5918, 63834),
(630, 5927, 63834),
(680, 5927, 63834),
(627, 5927, 63834),
(634, 5927, 63834),
(634, 5922, 63834),
(634, 5921, 63834),
(634, 5919, 63834),
(634, 5918, 63834),
(634, 5915, 63834),
(650, 5923, 63796),
(634, 5923, 63796),
(750, 5918, 63796),
(641, 5922, 63796),
(641, 5919, 63796),
(641, 5918, 63796),
(634, 5924, 63796),
(680, 5924, 63796),
(641, 5911, 63796),
(641, 5765, 63796),
(641, 5913, 63704),
(641, 5912, 63704),
(680, 5913, 63704),
(680, 5911, 63704),
(680, 5912, 63704),
(634, 5926, 63704),
(641, 5915, 63834),
(650, 5924, 63796),
(652, 5918, 63796),
(652, 89, 63796),
(657, 148, 63796),
(650, 5916, 63796),
(750, 5914, 63796),
(650, 5914, 63796),
(655, 89, 63796),
(634, 5925, 63704),
(649, 135, 63704),
(731, 5385, 63834),
(731, 5375, 63834),
(731, 923, 63834),
(731, 143, 63834),
(2403, 5697, 63834),
(2403, 5691, 63834),
(2403, 5673, 63834),
(2403, 346, 63834),
(692, 5819, 63834),
(652, 5915, 63796),
(659, 145, 63796),
(659, 5917, 63796),
(706, 5806, 63796),
(46, 947, 63704),
(80, 5886, 63704),
(80, 5882, 63704),
(80, 210, 63704);

UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63704 WHERE (`UIMapId`=627 AND `QuestLineId`=275) OR (`UIMapId`=47 AND `QuestLineId` IN (957,566,425,421,414,289,210)) OR (`UIMapId`=80 AND `QuestLineId` IN (538,510));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63796 WHERE (`UIMapId`=652 AND `QuestLineId` IN (377,145));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63834 WHERE (`UIMapId`=2371 AND `QuestLineId` IN (5703,5699,5695)) OR (`UIMapId`=2403 AND `QuestLineId` IN (5638,5593,5538,5519,5513,5504,5482,5459,1295,1289,1267,1108,1107,546,539,377,300,290,263,260)) OR (`UIMapId`=830 AND `QuestLineId` IN (5482,371,369,368,367,366,365,363,362,361,359,358,357,353,348,345)) OR (`UIMapId`=116 AND `QuestLineId` IN (5718,537,536,529,528,167));
UPDATE `ui_map_quest_line` SET `VerifiedBuild`=63660 WHERE (`UIMapId`=942 AND `QuestLineId` IN (5693,5673,5452,5450,5388,5371,922,916,906,887,881,851,794,745,744,740,583,577,442,5451,5436,5435,738,591,582)) OR (`UIMapId`=895 AND `QuestLineId` IN (5673,5449,5447,5432,5388,5384,5382,5380,5379,5378,5377,5376,5375,5374,5373,5372,5371,1104,1030,1004,1000,940,939,930,929,922,921,916,911,909,907,904,903,901,896,887,873,851,849,848,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,619,616,613,603,592,589,583,442,5448,5446,5443,5441,5440,5437,5436,5435,5434,5433,5431,591,586)) OR (`UIMapId`=1161 AND `QuestLineId` IN (5382,5380,5379,5378,5377,5376,5375,5374,5372,5371,1030,1004,1000,940,939,930,922,921,916,909,907,904,901,896,887,851,849,847,845,843,810,797,785,746,745,737,638,633,632,628,624,621,589,442)) OR (`UIMapId`=84 AND `QuestLineId`=916) OR (`UIMapId`=896 AND `QuestLineId` IN (5673,5449,5447,5432,5388,5384,5376,5373,5372,5371,1104,1000,940,922,916,911,903,901,887,851,847,845,843,745,592,442,5448,5446,5443,5441,5440,5437,5435,5433,591));


UPDATE `ui_map_quest` SET `VerifiedBuild`=63834 WHERE (`UIMapId`=2371 AND `QuestId` IN (85960,83537,83101,83048,82256));

DELETE FROM `spawn_tracking_template` WHERE `SpawnTrackingId` IN (2769319 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 1173931 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173941 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173930 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173937 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173920 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173938 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173939 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1173919 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1099172 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099171 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099176 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099170 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099198 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099184 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099186 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099182 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099191 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1099185 /*Map: 1220 (Broken Isles) - Phase: 5501*/, 1175551 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127326 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127324 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127323 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127317 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127319 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127327 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127311 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127314 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127315 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127313 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127322 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127318 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040705 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040704 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1175544 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127320 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1175542 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040703 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127321 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1085210 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127325 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1086667 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127316 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040710 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1127312 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040463 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1084696 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1111107 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1084707 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1014307 /*Map: 1220 (Broken Isles) - Phase: 4715*/, 1013857 /*Map: 1220 (Broken Isles) - Phase: 4992*/, 1023840 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1023358 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1023357 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1023360 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1023838 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1174833 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1174834 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1174838 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1174837 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1215387 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215408 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215407 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215416 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215418 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215409 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215410 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215388 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215414 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215403 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215411 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215413 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215412 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215415 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215419 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215420 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215406 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 1215405 /*Map: 1220 (Broken Isles) - Phase: 7112*/, 2838035 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 1174835 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1174820 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1057130 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057131 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057127 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1199058 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057126 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057138 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057137 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1057136 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1002831 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1002830 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1020050 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1003222 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1003126 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1002841 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1020044 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1020051 /*Map: 1463 (Helhiem Exterior Area) - Phase: 0*/, 1054020 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1054022 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1054029 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1197461 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1054028 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053829 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1054021 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1197460 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1197459 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053704 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053698 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053699 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1028778 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053700 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053701 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053702 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1053703 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1193163 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1193161 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1193178 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1006997 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1003723 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1006993 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 1003728 /*Map: 1220 (Broken Isles) - Phase: 7610*/, 999466 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999467 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1000215 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999470 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999468 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999465 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999459 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999461 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999460 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999458 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040941 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1040945 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1007682 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1007683 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1007673 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1129366 /*Map: 1220 (Broken Isles) - Phase: 0*/, 2805486 /*Map: 1220 (Broken Isles) - Phase: 26494*/, 2769322 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2769474 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2769568 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2769514 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2769473 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2769484 /*Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)*/, 2803973 /*Map: 1220 (Broken Isles) - Phase: 26517 (Cosmetic - See Moratari in The Chamber of the Guardian)*/, 2803972 /*Map: 1220 (Broken Isles) - Phase: 26516*/, 2803977 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803976 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2914947 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2914948 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2914946 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2914944 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803898 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803897 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803896 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803895 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803893 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803891 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803892 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803890 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803877 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803876 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803882 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803875 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803871 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803974 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 2803975 /*Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)*/, 1073202 /*Map: 1481 (Mardum) - Phase: 5310 (The Invasion Begins - Dispair Ridge Spawns)*/, 1156067 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155898 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155899 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155913 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155889 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155890 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155833 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155249 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1156079 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155834 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1156078 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1229073 /*Map: 1220 (Broken Isles) - Phase: 7099*/, 1202599 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1166150 /*Map: 1220 (Broken Isles) - Phase: 6505*/, 1166149 /*Map: 1220 (Broken Isles) - Phase: 6505*/, 1166147 /*Map: 1220 (Broken Isles) - Phase: 6505*/, 1166148 /*Map: 1220 (Broken Isles) - Phase: 6505*/, 1000619 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1000603 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1000602 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019503 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019508 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019511 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019500 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019493 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1019491 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1096479 /*Map: 1220 (Broken Isles) - Phase: 0*/, 980464 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1096478 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1096481 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1096480 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1002252 /*Map: 1220 (Broken Isles) - Phase: 6338*/, 1002216 /*Map: 1220 (Broken Isles) - Phase: 6338*/, 1002305 /*Map: 1220 (Broken Isles) - Phase: 6338*/, 991203 /*Map: 1220 (Broken Isles) - Phase: 0*/, 991208 /*Map: 1220 (Broken Isles) - Phase: 0*/, 991196 /*Map: 1220 (Broken Isles) - Phase: 0*/, 991198 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1020935 /*Map: 1220 (Broken Isles) - Phase: 0*/, 991195 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1097024 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995719 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995720 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1097025 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995599 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995607 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995605 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995603 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997517 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995609 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995601 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997510 /*Map: 1220 (Broken Isles) - Phase: 0*/, 995610 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1020220 /*Map: 1220 (Broken Isles) - Phase: 0*/, 998799 /*Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)*/, 998795 /*Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)*/, 998796 /*Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)*/, 1157747 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1157745 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1157749 /*Map: 1220 (Broken Isles) - Phase: 0*/, 999806 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997183 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997184 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997185 /*Map: 1220 (Broken Isles) - Phase: 0*/, 996758 /*Map: 1220 (Broken Isles) - Phase: 0*/, 996753 /*Map: 1220 (Broken Isles) - Phase: 0*/, 996757 /*Map: 1220 (Broken Isles) - Phase: 0*/, 996751 /*Map: 1220 (Broken Isles) - Phase: 0*/, 996754 /*Map: 1220 (Broken Isles) - Phase: 0*/, 997573 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155143 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155146 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155142 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155141 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155144 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1154598 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155140 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1155150 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1034384 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1035076 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1039487 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1039486 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1035087 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1035088 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1072879 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1035082 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1035089 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1137131 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1137138 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1137137 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1137135 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1137136 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1055602 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1048497 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1048491 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1048504 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074266 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074265 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074272 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074271 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074267 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1074268 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226589 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226584 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226553 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226585 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226586 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226588 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226591 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1226590 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1097906 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1038046 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1038045 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1027074 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1038037 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1027071 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1027070 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1027072 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1236453 /*Map: 1220 (Broken Isles) - Phase: 6523*/, 1236448 /*Map: 1220 (Broken Isles) - Phase: 6523*/, 1236454 /*Map: 1220 (Broken Isles) - Phase: 6523*/, 1069726 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1101699 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1101679 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1136358 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068647 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068646 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1136346 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1136361 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068645 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068635 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1136342 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068676 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068678 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068677 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068657 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068649 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1068658 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1136368 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109326 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109327 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109328 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109329 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109347 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109363 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109346 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109368 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109372 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1109369 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1167651 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1167652 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1167840 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1167736 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1167843 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1036303 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1198476 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1198477 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1198981 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1198478 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1198983 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1197948 /*Map: 1220 (Broken Isles) - Phase: 6988*/, 1197956 /*Map: 1220 (Broken Isles) - Phase: 6988*/, 1197938 /*Map: 1220 (Broken Isles) - Phase: 6988*/, 1197936 /*Map: 1220 (Broken Isles) - Phase: 6988*/, 1197944 /*Map: 1220 (Broken Isles) - Phase: 6988*/, 1147767 /*Map: 1220 (Broken Isles) - Phase: 0*/, 2769321 /*Map: 1220 (Broken Isles) - Phase: 0*/, 1111534 /*Map: 1 (Kalimdor) - Phase: 0*/, 1119186 /*Map: 0 (Eastern Kingdoms) - Phase: 5677*/, 1858656 /*Map: 0 (Eastern Kingdoms) - Phase: 5680*/, 1111608 /*Map: 1 (Kalimdor) - Phase: 0*/, 1253986 /*Map: 0 (Eastern Kingdoms) - Phase: 7260*/, 1098587 /*Map: 0 (Eastern Kingdoms) - Phase: 5513*/);
INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(2769319, 1220, 25667, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(1173931, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173941, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173930, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173937, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173920, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173938, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173939, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1173919, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1099172, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099171, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099176, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099170, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099198, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099184, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099186, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099182, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099191, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1099185, 1220, 5501, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 5501
(1175551, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127326, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127324, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127323, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127317, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127319, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127327, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127311, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127314, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127315, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127313, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127322, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127318, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1040705, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1040704, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1175544, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127320, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1175542, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1040703, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127321, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1085210, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127325, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1086667, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127316, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1040710, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1127312, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1040463, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1084696, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1111107, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1084707, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1014307, 1220, 4715, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 4715
(1013857, 1220, 4992, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 4992
(1023840, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1023358, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1023357, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1023360, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1023838, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1174833, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1174834, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1174838, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1174837, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1215387, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215408, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215407, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215416, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215418, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215409, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215410, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215388, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215414, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215403, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215411, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215413, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215412, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215415, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215419, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215420, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215406, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(1215405, 1220, 7112, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7112
(2838035, 1220, 25667, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(1174835, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1174820, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1057130, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057131, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057127, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1199058, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057126, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057138, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057137, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1057136, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1002831, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1002830, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1020050, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1003222, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1003126, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1002841, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1020044, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1020051, 1463, 0, 0, 0, 63704), -- Map: 1463 (Helhiem Exterior Area) - Phase: 0
(1054020, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1054022, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1054029, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1197461, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1054028, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053829, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1054021, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1197460, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1197459, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053704, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053698, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053699, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1028778, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053700, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053701, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053702, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1053703, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1193163, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1193161, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1193178, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1006997, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1003723, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1006993, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(1003728, 1220, 7610, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 7610
(999466, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999467, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1000215, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999470, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999468, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999465, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999459, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999461, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999460, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(999458, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1040941, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1040945, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1007682, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1007683, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1007673, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1129366, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(2805486, 1220, 26494, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26494
(2769322, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2769474, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2769568, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2769514, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2769473, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2769484, 1220, 25667, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 25667 (Cosmetic - See Infinite Bazaar GameObjects and Creatures)
(2803973, 1220, 26517, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26517 (Cosmetic - See Moratari in The Chamber of the Guardian)
(2803972, 1220, 26516, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26516
(2803977, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803976, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2914947, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2914948, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2914946, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2914944, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803898, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803897, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803896, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803895, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803893, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803891, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803892, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803890, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803877, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803876, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803882, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803875, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803871, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803974, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(2803975, 1220, 26208, 0, 0, 63660), -- Map: 1220 (Broken Isles) - Phase: 26208 (Dalaran - Remix Legion Invasion)
(1073202, 1481, 5310, 0, 0, 63834), -- Map: 1481 (Mardum) - Phase: 5310 (The Invasion Begins - Dispair Ridge Spawns)
(1156067, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155898, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155899, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155913, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155889, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155890, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155833, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155249, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1156079, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155834, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1156078, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1229073, 1220, 7099, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 7099
(1202599, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1166150, 1220, 6505, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6505
(1166149, 1220, 6505, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6505
(1166147, 1220, 6505, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6505
(1166148, 1220, 6505, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6505
(1000619, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1000603, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1000602, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019503, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019508, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019511, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019500, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019493, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1019491, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1096479, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(980464, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1096478, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1096481, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1096480, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1002252, 1220, 6338, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6338
(1002216, 1220, 6338, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6338
(1002305, 1220, 6338, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6338
(991203, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(991208, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(991196, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(991198, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1020935, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(991195, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1097024, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995719, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995720, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1097025, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995599, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995607, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995605, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995603, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997517, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995609, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995601, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997510, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(995610, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1020220, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(998799, 1220, 4476, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)
(998795, 1220, 4476, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)
(998796, 1220, 4476, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 4476 (Cosmetic - See Agapanthus and wounded whelplings)
(1157747, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1157745, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1157749, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(999806, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997183, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997184, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997185, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(996758, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(996753, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(996757, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(996751, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(996754, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(997573, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155143, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155146, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155142, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155141, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155144, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1154598, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155140, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1155150, 1220, 0, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 0
(1034384, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1035076, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1039487, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1039486, 1220, 0, 0, 0, 63796); -- Map: 1220 (Broken Isles) - Phase: 0

INSERT INTO `spawn_tracking_template` (`SpawnTrackingId`, `MapId`, `PhaseId`, `PhaseGroup`, `PhaseUseFlags`, `VerifiedBuild`) VALUES
(1035087, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1035088, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1072879, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1035082, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1035089, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1137131, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1137138, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1137137, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1137135, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1137136, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1055602, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1048497, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1048491, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1048504, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074266, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074265, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074272, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074271, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074267, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1074268, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226589, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226584, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226553, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226585, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226586, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226588, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226591, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1226590, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1097906, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1038046, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1038045, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1027074, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1038037, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1027071, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1027070, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1027072, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1236453, 1220, 6523, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6523
(1236448, 1220, 6523, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6523
(1236454, 1220, 6523, 0, 0, 63834), -- Map: 1220 (Broken Isles) - Phase: 6523
(1069726, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1101699, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1101679, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1136358, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068647, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068646, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1136346, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1136361, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068645, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068635, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1136342, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068676, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068678, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068677, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068657, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068649, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1068658, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1136368, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109326, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109327, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109328, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109329, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109347, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109363, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109346, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109368, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109372, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1109369, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1167651, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1167652, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1167840, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1167736, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1167843, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1036303, 1220, 0, 0, 0, 63796), -- Map: 1220 (Broken Isles) - Phase: 0
(1198476, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1198477, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1198981, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1198478, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1198983, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1197948, 1220, 6988, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 6988
(1197956, 1220, 6988, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 6988
(1197938, 1220, 6988, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 6988
(1197936, 1220, 6988, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 6988
(1197944, 1220, 6988, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 6988
(1147767, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(2769321, 1220, 0, 0, 0, 63704), -- Map: 1220 (Broken Isles) - Phase: 0
(1111534, 1, 0, 0, 0, 63704), -- Map: 1 (Kalimdor) - Phase: 0
(1119186, 0, 5677, 0, 0, 63704), -- Map: 0 (Eastern Kingdoms) - Phase: 5677
(1858656, 0, 5680, 0, 0, 63704), -- Map: 0 (Eastern Kingdoms) - Phase: 5680
(1111608, 1, 0, 0, 0, 63704), -- Map: 1 (Kalimdor) - Phase: 0
(1253986, 0, 7260, 0, 0, 63704), -- Map: 0 (Eastern Kingdoms) - Phase: 7260
(1098587, 0, 5513, 0, 0, 63704); -- Map: 0 (Eastern Kingdoms) - Phase: 5513

UPDATE `spawn_tracking_template` SET `PhaseId`=6475 WHERE `SpawnTrackingId`=1149855;
UPDATE `spawn_tracking_template` SET `PhaseUseFlags`=1 WHERE `SpawnTrackingId`=1174115;
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63834 WHERE `SpawnTrackingId` IN (1046965, 1046990, 1026192, 995726, 994872, 994873, 994871, 994869, 1240221, 1232926, 1090799, 1232927, 999700, 1067907, 1057874, 1054901, 1223544, 1232933, 1208326, 1208597, 1207847, 1097321, 1102449, 1095967, 1139712, 1082534, 1266818, 1266881, 1042465, 1053493, 1053492, 1053491, 1029001, 1077247, 1071452, 992268, 968765, 999940, 997179, 997062, 997063, 1261399, 1261400, 1165423, 1165424, 1165625, 1165746, 1165663, 1165777, 1000682, 1000683, 979387, 1157259, 1156615, 1002126, 994336, 1019105, 1019353, 1019322, 1019259, 968989, 1199941, 969096, 967974, 968064, 965521, 993308, 967373, 968248, 965206, 967276, 964181, 1002103, 1002100, 1002099, 1001742, 991341, 1002064, 991342, 964498, 1166146, 1166222, 1166154, 1166403, 1166469, 1166401, 1166402, 990695, 991359, 991352, 991356, 992171, 964937, 964630, 1191364, 1177023, 1182904, 1182903, 1182902, 1184238, 1212279, 1177022, 1177200, 1177197, 1177189, 992166, 969462, 959101, 981812, 963105, 991218, 989270, 989326, 962761, 1175483, 1194661, 1173310, 1173708, 1173371, 1173368, 1173370, 1173369, 1173580, 1017990, 992311, 1173754, 991938, 994944, 995666, 995667, 995727, 995777, 996955, 1020194, 1020219, 996686, 995645, 993036, 995590, 999215, 997065, 992313, 992312, 1017590, 994605, 1116384, 997574, 997291, 997160, 994943, 994955, 995746, 995743, 995742, 995737, 1143201, 999805, 995284, 995168, 995167, 995166, 1017609, 947998, 1155124, 1210548, 1127449, 1174591, 1174592, 1053138, 1051292, 1051345, 1051740, 1090166, 1090165, 1090137, 1088341, 1102188, 1051232, 1047691, 1067736, 1027850, 1082328, 1032550, 1030128, 1040677, 1056868, 1081973, 1028015, 1013897, 1170464, 1170518, 1167428, 1169454, 1237440, 1169414, 1167111, 1234674, 1260903, 1260904, 1260902, 1260901, 1135947, 1135299, 1135846, 1135295, 1065637, 1052854, 1054678, 1095965);
UPDATE `spawn_tracking_template` SET `PhaseId`=6495 WHERE `SpawnTrackingId`=1165906;
UPDATE `spawn_tracking_template` SET `PhaseId`=7480 WHERE `SpawnTrackingId`=1237927;
UPDATE `spawn_tracking_template` SET `PhaseId`=6669 WHERE `SpawnTrackingId`=1175420;
UPDATE `spawn_tracking_template` SET `PhaseId`=7132 WHERE `SpawnTrackingId`=1216496;
UPDATE `spawn_tracking_template` SET `PhaseId`=5422 WHERE `SpawnTrackingId`=1063686;
UPDATE `spawn_tracking_template` SET `PhaseId`=7965 WHERE `SpawnTrackingId`=1266169;
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63796 WHERE `SpawnTrackingId` IN (1016102, 1240221, 1174140, 1045487, 1130256, 1176099, 1176725, 1234492, 1082479, 1176050, 1175673, 1080676, 1046569, 1174565, 1045481, 1174203, 1174202, 1174139, 1047339, 1079692, 1066368, 1067308, 1066297, 1067105, 1269496, 1269494, 1066386, 1098090, 1098124, 1098300, 1027489, 1028768, 1084993, 1042553, 1173035, 1065739, 1022586, 1035471, 1026186, 1028968, 1092466, 1032033, 1064537, 1151977, 1033402, 1033401, 1033400, 1099177, 1098811, 1085886, 1047777, 1040538, 1041055, 1034109, 1034655, 1034632, 1042552, 1022568, 1034659, 1032292, 1032291, 1033467, 1032299, 1041035, 1107555, 1067052, 1055680, 1151362, 1082746, 1085044, 1120564, 1081444, 1055809, 1068068, 1078072, 1126749, 1050464, 1177196, 1193463, 1193462, 1195269, 1177241, 1193495, 1193493, 1193490, 1014304, 1033002, 1014337, 1032516, 1032512, 1033003, 1013874, 1032998, 1012704, 1196204, 1012702, 1013894, 1013858, 1031660, 1010696, 1028967, 1028241, 1010697, 1024725, 1027609, 1010694, 1011397, 1028239, 1011431, 1139718, 1118811, 1139712, 1082534, 1138394, 1054156, 1218279, 1209689, 1253897, 1251076, 1249453, 1232453, 1050875, 1232933, 1232927, 1232926, 1137720, 1067701, 1009845, 1153688, 1067907, 246472, 2722630, 2722647, 1780509, 1167032, 1068545, 1069732, 1036431, 1036446, 1157379, 1157378, 1157377, 1208326, 1208597, 1207847, 1076800, 1231003, 1013897, 1142547, 1139470, 1137293, 1031312, 1034067, 1124347, 1011721, 1149386, 1011473, 1012413, 1011931, 1011441, 1076817, 1011504, 1094774, 1013163, 1000294, 1002063, 1226645, 1226607, 999965, 1000408, 1020927, 1001827, 1000552, 1000866, 999818, 1001497, 999809, 1080492, 1020151, 1020965, 1022887, 1003673, 1156626, 1022880, 1097321, 1102449, 1095967, 1057874, 1088186, 1150819, 1150437, 1150082, 1091812, 1057836, 1091807, 1051972, 1082684, 1082686, 1036468, 1082778, 1082777, 1260937, 1260934, 1068709, 1079340, 1085150, 1084717, 1073377, 1039773, 1050730, 1050729, 1050727, 1039613, 1039471, 1087548, 1040050, 1087547, 1035324, 1130022, 1055464, 1038650, 1035372, 1035373, 1035374, 1069125, 1035062, 1069251, 1069248, 1069250, 1069232, 1055691, 1063570, 1035278, 1035767, 1068910, 1166938, 1034579, 1267684);
UPDATE `spawn_tracking_template` SET `PhaseId`=4898, `VerifiedBuild`=63796 WHERE `SpawnTrackingId`=1022523; -- Map: 1220 (Broken Isles) - Phase: 4898
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63796 WHERE `SpawnTrackingId` IN (1079692, 1156626, 1067907); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=5331, `VerifiedBuild`=63796 WHERE `SpawnTrackingId`=1075507; -- Map: 1515 (Huln's War) - Phase: 5331
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63704 WHERE `SpawnTrackingId` IN (1170397, 1053992, 1170332, 1170168, 1169602, 1174519, 1169236, 1174887, 1174883, 1174880, 1174878, 1174159, 1174449, 1067701, 1009845, 1068568, 1068567, 1068566, 1068564, 1066979, 1068961, 1067199, 1067198, 1067197, 1067192, 1027977, 1040802, 1040686, 1028379, 1027901, 1027897, 1027895, 1027894, 1022338, 1040801, 1037851, 1037850, 1037846, 1037844, 1037840, 1200467, 1200470, 1026971, 1040587, 1099374, 1067907, 1067905, 1008770, 1067165, 1067172, 1065841, 1065264, 1066266, 1068031, 1027284, 1027285, 1027286, 1041895, 1071572, 1071534, 1057956, 1005815, 1057955, 1057954, 1057953, 1057281, 1057238, 1057952, 1003164, 1001964, 1016548, 1016711, 1018680, 1055024, 1054695, 1016741, 1018074, 1018073, 1017076, 1019072, 1054611, 1013301, 1013300, 1012971, 1054939, 1054940, 1054938, 1071481, 1052731, 1047302, 1004668, 1047159, 1052391, 1001079, 1052281, 1052273, 1052246, 1052214, 1004349, 1004952, 1005449, 1002873, 1074423, 1009740, 1002706, 1002518, 1004047, 1004040, 1002704, 1002765, 1005320, 1000853, 1044242, 1046543, 1044227, 1044239, 1043683, 1045997, 1043940, 1043849, 1043850, 1043843, 1043841, 1042505, 1042708, 1045633, 1043984, 1044023, 1212098, 1212072, 1212109, 1212050, 1212090, 1212044, 1055104, 998750, 999105, 1000133, 999141, 1009258, 1007988, 999136, 998268, 1069733, 1232453, 1050875, 1148537, 1129368, 1002258, 1002063, 1147933, 1147957, 1148536, 1170409, 1172984, 1170394, 1168959, 1168260, 1168973, 1167987, 1253897, 1251076, 1249453, 1022887, 1020151, 1022880, 1036167, 1036293, 1081866, 1099333, 1099684, 1036137, 1081863, 1099334, 1036133, 1036136, 1003673, 999965, 1025404, 1020265, 1019058, 1019061, 1019059, 1202891, 1019060, 1198167, 1203424, 1197928, 1156626, 1149386, 1209523, 1209522, 1157614, 1067529, 1153687, 1157615, 1082746, 1085044, 1120564, 1081444, 1055809, 1068068, 1078072, 1126749, 1050464, 1133627, 1067005, 1129947, 1105807, 1118290, 1102602, 1118158, 1118157, 1118156, 1118155, 1102662, 1096900, 1120550, 1119291, 1119190, 1130034, 1119349, 1128716, 1107037, 1107035, 1127450, 1127717, 1127973, 1125868, 1126306, 1125892, 1248490, 1719591, 1103904, 1106592, 1103758, 1754467, 1111827, 1177495, 1195731);
UPDATE `spawn_tracking_template` SET `PhaseId`=5213, `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1057271; -- Map: 1463 (Helhiem Exterior Area) - Phase: 5213
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63704 WHERE `SpawnTrackingId` IN (1010997, 998268, 1216698); -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=5191, `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1002774; -- Map: 1463 (Helhiem Exterior Area) - Phase: 5191
UPDATE `spawn_tracking_template` SET `PhaseId`=5192, `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1056075; -- Map: 1463 (Helhiem Exterior Area) - Phase: 5192
UPDATE `spawn_tracking_template` SET `PhaseId`=5189, `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1055024; -- Map: 1463 (Helhiem Exterior Area) - Phase: 5189
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63660 WHERE `SpawnTrackingId` IN (1177495, 1195731, 1754467, 1173160, 1193016, 1193017, 1193018, 1193021, 1193020, 1193019, 1192898, 1192897, 1192896, 1191347, 1191359, 1717498, 1731862, 1717268, 1731623, 1731609, 1717016, 1716719, 1717499);
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63660 WHERE `SpawnTrackingId`=1173160; -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1142548; -- Map: 1220 (Broken Isles) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1135947; -- Map: 571 (Northrend) - Phase: 0
UPDATE `spawn_tracking_template` SET `PhaseId`=6355, `VerifiedBuild`=63834 WHERE `SpawnTrackingId` IN (1151180, 1150233); -- Map: 1540 (Emerald Dreamway) - Phase: 6355
UPDATE `spawn_tracking_template` SET `PhaseId`=6466, `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1150232; -- Map: 1540 (Emerald Dreamway) - Phase: 6466
UPDATE `spawn_tracking_template` SET `PhaseId`=7401, `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1232933; -- Map: 1540 (Emerald Dreamway) - Phase: 7401
UPDATE `spawn_tracking_template` SET `PhaseId`=7403, `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1232927; -- Map: 1540 (Emerald Dreamway) - Phase: 7403
UPDATE `spawn_tracking_template` SET `PhaseId`=7402 WHERE `SpawnTrackingId`=1232932;
UPDATE `spawn_tracking_template` SET `PhaseId`=7404, `VerifiedBuild`=63834 WHERE `SpawnTrackingId`=1232926; -- Map: 1540 (Emerald Dreamway) - Phase: 7404
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63704 WHERE `SpawnTrackingId` IN (1104920, 1119190); -- Map: 0 (Eastern Kingdoms) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1107035; -- Map: 1 (Kalimdor) - Phase: 0
UPDATE `spawn_tracking_template` SET `VerifiedBuild`=63704 WHERE `SpawnTrackingId`=1719603; -- Map: 1 (Kalimdor) - Phase: 0

DELETE FROM `spawn_tracking_quest_objective` WHERE (`QuestObjectiveId`=278347 AND `SpawnTrackingId`=1013858) OR (`QuestObjectiveId`=278346 AND `SpawnTrackingId`=1013857) OR (`QuestObjectiveId`=285322 AND `SpawnTrackingId`=1010697) OR (`QuestObjectiveId`=466016 AND `SpawnTrackingId`=2769319) OR (`QuestObjectiveId`=466015 AND `SpawnTrackingId`=1004341) OR (`QuestObjectiveId`=462108 AND `SpawnTrackingId`=2838035) OR (`QuestObjectiveId`=462107 AND `SpawnTrackingId`=2769319) OR (`QuestObjectiveId`=278471 AND `SpawnTrackingId`=1054020) OR (`QuestObjectiveId`=280241 AND `SpawnTrackingId`=1129366) OR (`QuestObjectiveId`=461121 AND `SpawnTrackingId`=2769320) OR (`QuestObjectiveId`=464406 AND `SpawnTrackingId`=2769474) OR (`QuestObjectiveId`=464405 AND `SpawnTrackingId`=2769568) OR (`QuestObjectiveId`=464404 AND `SpawnTrackingId`=2769514) OR (`QuestObjectiveId`=464403 AND `SpawnTrackingId`=2769473) OR (`QuestObjectiveId`=461062 AND `SpawnTrackingId`=2769322) OR (`QuestObjectiveId`=461060 AND `SpawnTrackingId`=2769484) OR (`QuestObjectiveId`=463667 AND `SpawnTrackingId` IN (2914947,2914948,2914946,2914944)) OR (`QuestObjectiveId`=461244 AND `SpawnTrackingId`=2803977) OR (`QuestObjectiveId`=460982 AND `SpawnTrackingId`=2803898) OR (`QuestObjectiveId`=460981 AND `SpawnTrackingId`=2803897) OR (`QuestObjectiveId`=460980 AND `SpawnTrackingId`=2803896) OR (`QuestObjectiveId`=460979 AND `SpawnTrackingId`=2803895) OR (`QuestObjectiveId`=460984 AND `SpawnTrackingId`=2803893) OR (`QuestObjectiveId`=460899 AND `SpawnTrackingId`=2803891) OR (`QuestObjectiveId`=460898 AND `SpawnTrackingId`=2803892) OR (`QuestObjectiveId`=460897 AND `SpawnTrackingId`=2803890) OR (`QuestObjectiveId`=461223 AND `SpawnTrackingId`=2803972) OR (`QuestObjectiveId`=460790 AND `SpawnTrackingId`=2803975) OR (`QuestObjectiveId`=277505 AND `SpawnTrackingId` IN (1116384,994605)) OR (`QuestObjectiveId`=282060 AND `SpawnTrackingId`=947998) OR (`QuestObjectiveId`=462039 AND `SpawnTrackingId`=1004341) OR (`QuestObjectiveId`=393623 AND `SpawnTrackingId`=1858656) OR (`QuestObjectiveId`=281065 AND `SpawnTrackingId`=1098587);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1013858, 278347, 63796), -- 1013858
(1013857, 278346, 63796), -- 1013857
(1010697, 285322, 63796), -- 1010697
(2769319, 466016, 63704), -- 2769319
(1004341, 466015, 63704), -- 1004341
(2838035, 462108, 63704), -- 2838035
(2769319, 462107, 63704), -- 2769319
(1054020, 278471, 63704), -- 1054020
(1129366, 280241, 63704), -- 1129366
(2769320, 461121, 63660), -- 2769320
(2769474, 464406, 63660), -- 2769474
(2769568, 464405, 63660), -- 2769568
(2769514, 464404, 63660), -- 2769514
(2769473, 464403, 63660), -- 2769473
(2769322, 461062, 63660), -- 2769322
(2769484, 461060, 63660), -- 2769484
(2914947, 463667, 63660), -- 2914947
(2914948, 463667, 63660), -- 2914948
(2914946, 463667, 63660), -- 2914946
(2914944, 463667, 63660), -- 2914944
(2803977, 461244, 63660), -- 2803977
(2803898, 460982, 63660), -- 2803898
(2803897, 460981, 63660), -- 2803897
(2803896, 460980, 63660), -- 2803896
(2803895, 460979, 63660), -- 2803895
(2803893, 460984, 63660), -- 2803893
(2803891, 460899, 63660), -- 2803891
(2803892, 460898, 63660), -- 2803892
(2803890, 460897, 63660), -- 2803890
(2803972, 461223, 63660), -- 2803972
(2803975, 460790, 63660), -- 2803975
(1116384, 277505, 63834), -- 1116384
(994605, 277505, 63834), -- 994605
(947998, 282060, 63834), -- 947998
(1004341, 462039, 63704), -- 1004341
(1858656, 393623, 63704), -- 1858656
(1098587, 281065, 63704); -- 1098587

UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63834 WHERE (`SpawnTrackingId`=1046990 AND `QuestObjectiveId`=279765) OR (`SpawnTrackingId`=1090799 AND `QuestObjectiveId`=286231) OR (`SpawnTrackingId`=999734 AND `QuestObjectiveId`=286272) OR (`SpawnTrackingId`=999700 AND `QuestObjectiveId`=286230) OR (`SpawnTrackingId`=1054901 AND `QuestObjectiveId`=279973) OR (`SpawnTrackingId`=994872 AND `QuestObjectiveId`=280839) OR (`SpawnTrackingId`=994873 AND `QuestObjectiveId`=280838) OR (`SpawnTrackingId`=994871 AND `QuestObjectiveId`=280837) OR (`SpawnTrackingId`=994869 AND `QuestObjectiveId`=277088) OR (`SpawnTrackingId`=1223544 AND `QuestObjectiveId`=286720) OR (`SpawnTrackingId`=1232933 AND `QuestObjectiveId`=286245) OR (`SpawnTrackingId`=1232932 AND `QuestObjectiveId`=286244) OR (`SpawnTrackingId`=1232927 AND `QuestObjectiveId`=286243) OR (`SpawnTrackingId`=1232926 AND `QuestObjectiveId`=286073) OR (`SpawnTrackingId`=1208597 AND `QuestObjectiveId`=285180) OR (`SpawnTrackingId`=1102449 AND `QuestObjectiveId`=280942) OR (`SpawnTrackingId`=1082534 AND `QuestObjectiveId` IN (280866,286274)) OR (`SpawnTrackingId`=1266818 AND `QuestObjectiveId`=287483) OR (`SpawnTrackingId`=1266881 AND `QuestObjectiveId`=288967) OR (`SpawnTrackingId`=1042465 AND `QuestObjectiveId`=281824) OR (`SpawnTrackingId`=1053493 AND `QuestObjectiveId`=279937) OR (`SpawnTrackingId`=1053492 AND `QuestObjectiveId`=279936) OR (`SpawnTrackingId`=1053491 AND `QuestObjectiveId`=279935) OR (`SpawnTrackingId`=1077247 AND `QuestObjectiveId`=280292) OR (`SpawnTrackingId`=992268 AND `QuestObjectiveId`=283624) OR (`SpawnTrackingId`=968765 AND `QuestObjectiveId` IN (283623,276466)) OR (`SpawnTrackingId`=997179 AND `QuestObjectiveId`=277504) OR (`SpawnTrackingId`=997062 AND `QuestObjectiveId`=277503) OR (`SpawnTrackingId`=997063 AND `QuestObjectiveId`=277502) OR (`SpawnTrackingId`=1261399 AND `QuestObjectiveId`=287416) OR (`SpawnTrackingId`=1261400 AND `QuestObjectiveId`=287260) OR (`SpawnTrackingId`=996959 AND `QuestObjectiveId`=283924) OR (`SpawnTrackingId`=1154363 AND `QuestObjectiveId`=284104) OR (`SpawnTrackingId`=1165625 AND `QuestObjectiveId` IN (284121,284120,284119,284125)) OR (`SpawnTrackingId`=1165746 AND `QuestObjectiveId`=284121) OR (`SpawnTrackingId`=1165663 AND `QuestObjectiveId`=284120) OR (`SpawnTrackingId`=1165777 AND `QuestObjectiveId`=284119) OR (`SpawnTrackingId`=1000682 AND `QuestObjectiveId`=277564) OR (`SpawnTrackingId`=1000683 AND `QuestObjectiveId`=277563) OR (`SpawnTrackingId`=994336 AND `QuestObjectiveId`=277332) OR (`SpawnTrackingId`=1019353 AND `QuestObjectiveId`=278525) OR (`SpawnTrackingId`=1019322 AND `QuestObjectiveId`=278524) OR (`SpawnTrackingId`=1019259 AND `QuestObjectiveId`=278523) OR (`SpawnTrackingId`=968064 AND `QuestObjectiveId`=276388) OR (`SpawnTrackingId`=967974 AND `QuestObjectiveId`=276389) OR (`SpawnTrackingId`=993308 AND `QuestObjectiveId`=276360) OR (`SpawnTrackingId`=968248 AND `QuestObjectiveId`=276420) OR (`SpawnTrackingId`=967373 AND `QuestObjectiveId`=276353) OR (`SpawnTrackingId`=965206 AND `QuestObjectiveId`=276311) OR (`SpawnTrackingId`=964181 AND `QuestObjectiveId`=276356) OR (`SpawnTrackingId`=967276 AND `QuestObjectiveId` IN (276733,277634,277633,277631,277630,277629,276735)) OR (`SpawnTrackingId`=1002100 AND `QuestObjectiveId` IN (277634,277633)) OR (`SpawnTrackingId`=1002099 AND `QuestObjectiveId` IN (277631,277630)) OR (`SpawnTrackingId`=1001742 AND `QuestObjectiveId`=277629) OR (`SpawnTrackingId`=964498 AND `QuestObjectiveId`=276801) OR (`SpawnTrackingId`=1166146 AND `QuestObjectiveId` IN (276800,276799,276798,284150)) OR (`SpawnTrackingId`=1166154 AND `QuestObjectiveId` IN (284162,284160,284158)) OR (`SpawnTrackingId`=1166403 AND `QuestObjectiveId`=284161) OR (`SpawnTrackingId`=1166469 AND `QuestObjectiveId`=284149) OR (`SpawnTrackingId`=1166401 AND `QuestObjectiveId`=284159) OR (`SpawnTrackingId`=1166402 AND `QuestObjectiveId`=284157) OR (`SpawnTrackingId`=990695 AND `QuestObjectiveId`=276816) OR (`SpawnTrackingId`=991359 AND `QuestObjectiveId`=276815) OR (`SpawnTrackingId`=991352 AND `QuestObjectiveId`=276814) OR (`SpawnTrackingId`=991356 AND `QuestObjectiveId`=276813) OR (`SpawnTrackingId`=964937 AND `QuestObjectiveId`=276307) OR (`SpawnTrackingId`=964630 AND `QuestObjectiveId` IN (276307,276977)) OR (`SpawnTrackingId`=1182904 AND `QuestObjectiveId`=284615) OR (`SpawnTrackingId`=1182903 AND `QuestObjectiveId`=284614) OR (`SpawnTrackingId`=1182902 AND `QuestObjectiveId`=284613) OR (`SpawnTrackingId`=1184238 AND `QuestObjectiveId`=284620) OR (`SpawnTrackingId`=1177200 AND `QuestObjectiveId`=284601) OR (`SpawnTrackingId`=1177197 AND `QuestObjectiveId`=284600) OR (`SpawnTrackingId`=1177189 AND `QuestObjectiveId`=284599) OR (`SpawnTrackingId`=992166 AND `QuestObjectiveId`=285258) OR (`SpawnTrackingId`=969462 AND `QuestObjectiveId`=276767) OR (`SpawnTrackingId`=959101 AND `QuestObjectiveId`=276977) OR (`SpawnTrackingId`=963105 AND `QuestObjectiveId`=276292) OR (`SpawnTrackingId`=991218 AND `QuestObjectiveId`=276797) OR (`SpawnTrackingId`=962761 AND `QuestObjectiveId`=276231) OR (`SpawnTrackingId`=1194661 AND `QuestObjectiveId`=284713) OR (`SpawnTrackingId`=1173310 AND `QuestObjectiveId`=284709) OR (`SpawnTrackingId`=1173371 AND `QuestObjectiveId`=284448) OR (`SpawnTrackingId`=1173368 AND `QuestObjectiveId`=284447) OR (`SpawnTrackingId`=1173370 AND `QuestObjectiveId`=284446) OR (`SpawnTrackingId`=1173369 AND `QuestObjectiveId`=284444) OR (`SpawnTrackingId`=994944 AND `QuestObjectiveId`=277089) OR (`SpawnTrackingId`=995666 AND `QuestObjectiveId`=277147) OR (`SpawnTrackingId`=995667 AND `QuestObjectiveId`=277148) OR (`SpawnTrackingId`=995727 AND `QuestObjectiveId`=276926) OR (`SpawnTrackingId`=995726 AND `QuestObjectiveId`=276926) OR (`SpawnTrackingId`=995645 AND `QuestObjectiveId`=277240) OR (`SpawnTrackingId`=995590 AND `QuestObjectiveId`=277141) OR (`SpawnTrackingId`=996955 AND `QuestObjectiveId`=277268) OR (`SpawnTrackingId`=1020194 AND `QuestObjectiveId`=277268) OR (`SpawnTrackingId`=1020219 AND `QuestObjectiveId`=277268) OR (`SpawnTrackingId`=996686 AND `QuestObjectiveId`=277268) OR (`SpawnTrackingId`=997065 AND `QuestObjectiveId`=277270) OR (`SpawnTrackingId`=992311 AND `QuestObjectiveId`=277118) OR (`SpawnTrackingId`=994605 AND `QuestObjectiveId`=286100) OR (`SpawnTrackingId`=997574 AND `QuestObjectiveId`=277301) OR (`SpawnTrackingId`=997291 AND `QuestObjectiveId`=277456) OR (`SpawnTrackingId`=997160 AND `QuestObjectiveId`=277290) OR (`SpawnTrackingId`=994955 AND `QuestObjectiveId`=286117) OR (`SpawnTrackingId`=995746 AND `QuestObjectiveId`=277160) OR (`SpawnTrackingId`=995743 AND `QuestObjectiveId`=277159) OR (`SpawnTrackingId`=995742 AND `QuestObjectiveId`=277158) OR (`SpawnTrackingId`=995737 AND `QuestObjectiveId`=277156) OR (`SpawnTrackingId`=1143201 AND `QuestObjectiveId`=277152) OR (`SpawnTrackingId`=999805 AND `QuestObjectiveId`=277151) OR (`SpawnTrackingId`=995168 AND `QuestObjectiveId`=277133) OR (`SpawnTrackingId`=995167 AND `QuestObjectiveId`=277132) OR (`SpawnTrackingId`=995166 AND `QuestObjectiveId`=277117) OR (`SpawnTrackingId`=1155124 AND `QuestObjectiveId`=283876) OR (`SpawnTrackingId`=1210548 AND `QuestObjectiveId`=285280) OR (`SpawnTrackingId`=1127449 AND `QuestObjectiveId`=286236) OR (`SpawnTrackingId`=1174592 AND `QuestObjectiveId`=284495) OR (`SpawnTrackingId`=1051292 AND `QuestObjectiveId`=279925) OR (`SpawnTrackingId`=1051345 AND `QuestObjectiveId`=279924) OR (`SpawnTrackingId`=1090166 AND `QuestObjectiveId`=280727) OR (`SpawnTrackingId`=1090165 AND `QuestObjectiveId`=280724) OR (`SpawnTrackingId`=1090137 AND `QuestObjectiveId`=280725) OR (`SpawnTrackingId`=1088341 AND `QuestObjectiveId` IN (280921,280723,280722,280721,280717,280716,280715,280714,280713)) OR (`SpawnTrackingId`=1102188 AND `QuestObjectiveId`=280920) OR (`SpawnTrackingId`=1051232 AND `QuestObjectiveId`=279915) OR (`SpawnTrackingId`=1082328 AND `QuestObjectiveId`=280452) OR (`SpawnTrackingId`=1030128 AND `QuestObjectiveId`=279028) OR (`SpawnTrackingId`=1056868 AND `QuestObjectiveId`=280061) OR (`SpawnTrackingId`=1081973 AND `QuestObjectiveId`=282894) OR (`SpawnTrackingId`=1028015 AND `QuestObjectiveId`=280420) OR (`SpawnTrackingId`=1013897 AND `QuestObjectiveId`=283302) OR (`SpawnTrackingId`=1170518 AND `QuestObjectiveId` IN (284395,284394)) OR (`SpawnTrackingId`=1169454 AND `QuestObjectiveId`=284222) OR (`SpawnTrackingId`=1167111 AND `QuestObjectiveId`=284195) OR (`SpawnTrackingId`=1234674 AND `QuestObjectiveId`=286292) OR (`SpawnTrackingId`=1243153 AND `QuestObjectiveId`=283554) OR (`SpawnTrackingId`=1260903 AND `QuestObjectiveId`=287145) OR (`SpawnTrackingId`=1260904 AND `QuestObjectiveId`=287144) OR (`SpawnTrackingId`=1260902 AND `QuestObjectiveId`=287143) OR (`SpawnTrackingId`=1260901 AND `QuestObjectiveId`=287142) OR (`SpawnTrackingId`=1135299 AND `QuestObjectiveId` IN (281105,281151)) OR (`SpawnTrackingId`=1135947 AND `QuestObjectiveId`=282844) OR (`SpawnTrackingId`=1135295 AND `QuestObjectiveId`=282904) OR (`SpawnTrackingId`=1151180 AND `QuestObjectiveId`=283634) OR (`SpawnTrackingId`=1054678 AND `QuestObjectiveId`=279965) OR (`SpawnTrackingId`=1095965 AND `QuestObjectiveId`=280018);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63796 WHERE (`QuestObjectiveId`=285282 AND `SpawnTrackingId`=1016102) OR (`QuestObjectiveId`=284530 AND `SpawnTrackingId` IN (1234492,1176099)) OR (`QuestObjectiveId`=279737 AND `SpawnTrackingId` IN (1234492,1176050)) OR (`QuestObjectiveId`=279736 AND `SpawnTrackingId` IN (1234492,1175673)) OR (`QuestObjectiveId`=279761 AND `SpawnTrackingId` IN (1234492,1046569)) OR (`QuestObjectiveId`=279760 AND `SpawnTrackingId` IN (1174565,1234492)) OR (`QuestObjectiveId`=284500 AND `SpawnTrackingId` IN (1234492,1174203)) OR (`QuestObjectiveId`=284499 AND `SpawnTrackingId` IN (1234492,1174202)) OR (`QuestObjectiveId`=284489 AND `SpawnTrackingId` IN (1234492,1174139)) OR (`QuestObjectiveId`=279812 AND `SpawnTrackingId`=1234492) OR (`QuestObjectiveId`=279777 AND `SpawnTrackingId` IN (1047339,1045481)) OR (`QuestObjectiveId`=279776 AND `SpawnTrackingId`=1047339) OR (`QuestObjectiveId`=280144 AND `SpawnTrackingId`=1067308) OR (`QuestObjectiveId`=280160 AND `SpawnTrackingId` IN (1067105,1269496,1269494)) OR (`QuestObjectiveId`=280397 AND `SpawnTrackingId`=1079692) OR (`QuestObjectiveId`=278977 AND `SpawnTrackingId`=1028768) OR (`QuestObjectiveId`=280857 AND `SpawnTrackingId`=1098090) OR (`QuestObjectiveId`=280856 AND `SpawnTrackingId`=1098124) OR (`QuestObjectiveId`=280855 AND `SpawnTrackingId`=1098300) OR (`QuestObjectiveId`=280365 AND `SpawnTrackingId`=1079692) OR (`QuestObjectiveId`=284436 AND `SpawnTrackingId`=1084993) OR (`QuestObjectiveId`=284435 AND `SpawnTrackingId`=1173035) OR (`QuestObjectiveId`=284454 AND `SpawnTrackingId`=1065739) OR (`QuestObjectiveId`=281830 AND `SpawnTrackingId`=1130256) OR (`QuestObjectiveId`=278984 AND `SpawnTrackingId`=1028968) OR (`QuestObjectiveId`=284250 AND `SpawnTrackingId` IN (1032033,1026186)) OR (`QuestObjectiveId`=278827 AND `SpawnTrackingId` IN (1032033,1064537)) OR (`QuestObjectiveId`=279160 AND `SpawnTrackingId`=1033402) OR (`QuestObjectiveId`=279159 AND `SpawnTrackingId`=1033401) OR (`QuestObjectiveId`=278830 AND `SpawnTrackingId`=1033400) OR (`QuestObjectiveId`=279635 AND `SpawnTrackingId`=1040538) OR (`QuestObjectiveId`=279197 AND `SpawnTrackingId`=1034632) OR (`QuestObjectiveId`=280577 AND `SpawnTrackingId`=1032292) OR (`QuestObjectiveId`=280576 AND `SpawnTrackingId`=1032291) OR (`QuestObjectiveId`=280575 AND `SpawnTrackingId`=1033467) OR (`QuestObjectiveId`=280574 AND `SpawnTrackingId`=1032299) OR (`QuestObjectiveId`=279644 AND `SpawnTrackingId`=1041035) OR (`QuestObjectiveId`=283696 AND `SpawnTrackingId`=1151362) OR (`QuestObjectiveId`=279996 AND `SpawnTrackingId` IN (1082746,1085044,1120564,1081444,1055809,1068068,1078072,1126749,1050464)) OR (`QuestObjectiveId`=284761 AND `SpawnTrackingId`=1193463) OR (`QuestObjectiveId`=284694 AND `SpawnTrackingId`=1193462) OR (`QuestObjectiveId`=284693 AND `SpawnTrackingId`=1193495) OR (`QuestObjectiveId`=284692 AND `SpawnTrackingId`=1193493) OR (`QuestObjectiveId`=284691 AND `SpawnTrackingId`=1193490) OR (`QuestObjectiveId`=278336 AND `SpawnTrackingId`=1014340) OR (`QuestObjectiveId`=279137 AND `SpawnTrackingId`=1032516) OR (`QuestObjectiveId`=279136 AND `SpawnTrackingId`=1032512) OR (`QuestObjectiveId`=278328 AND `SpawnTrackingId`=1032515) OR (`QuestObjectiveId`=278322 AND `SpawnTrackingId`=1013894) OR (`QuestObjectiveId`=278318 AND `SpawnTrackingId`=1013630) OR (`QuestObjectiveId`=278317 AND `SpawnTrackingId`=1036491) OR (`QuestObjectiveId`=278316 AND `SpawnTrackingId`=1013614) OR (`QuestObjectiveId`=278345 AND `SpawnTrackingId`=1031660) OR (`QuestObjectiveId`=278327 AND `SpawnTrackingId`=1028967) OR (`QuestObjectiveId`=278927 AND `SpawnTrackingId`=1027609) OR (`QuestObjectiveId`=279633 AND `SpawnTrackingId`=1010697) OR (`QuestObjectiveId`=280866 AND `SpawnTrackingId`=1082534) OR (`QuestObjectiveId`=278376 AND `SpawnTrackingId`=1054156) OR (`QuestObjectiveId`=283121 AND `SpawnTrackingId`=1138394) OR (`QuestObjectiveId`=285468 AND `SpawnTrackingId`=1209689) OR (`QuestObjectiveId`=287539 AND `SpawnTrackingId` IN (1253897,1251076)) OR (`QuestObjectiveId`=286220 AND `SpawnTrackingId`=1232453) OR (`QuestObjectiveId`=286103 AND `SpawnTrackingId`=1050875) OR (`QuestObjectiveId`=286245 AND `SpawnTrackingId`=1232933) OR (`QuestObjectiveId`=286244 AND `SpawnTrackingId`=1232932) OR (`QuestObjectiveId`=286243 AND `SpawnTrackingId`=1232927) OR (`QuestObjectiveId`=286073 AND `SpawnTrackingId`=1232926) OR (`QuestObjectiveId`=457870 AND `SpawnTrackingId`=2722647) OR (`QuestObjectiveId`=280266 AND `SpawnTrackingId`=1069732) OR (`QuestObjectiveId`=284000 AND `SpawnTrackingId`=1157379) OR (`QuestObjectiveId`=283999 AND `SpawnTrackingId`=1157378) OR (`QuestObjectiveId`=283998 AND `SpawnTrackingId`=1157377) OR (`QuestObjectiveId`=285180 AND `SpawnTrackingId`=1208597) OR (`QuestObjectiveId`=280335 AND `SpawnTrackingId`=1076800) OR (`QuestObjectiveId`=283030 AND `SpawnTrackingId`=1013897) OR (`QuestObjectiveId`=283037 AND `SpawnTrackingId`=1137293) OR (`QuestObjectiveId`=284254 AND `SpawnTrackingId`=1067534) OR (`QuestObjectiveId`=283927 AND `SpawnTrackingId`=1149386) OR (`QuestObjectiveId`=278367 AND `SpawnTrackingId`=1012413) OR (`QuestObjectiveId`=278279 AND `SpawnTrackingId`=1011931) OR (`QuestObjectiveId`=278477 AND `SpawnTrackingId` IN (1094774,1013163)) OR (`QuestObjectiveId`=277776 AND `SpawnTrackingId`=1002063) OR (`QuestObjectiveId`=285981 AND `SpawnTrackingId`=1226607) OR (`QuestObjectiveId`=285989 AND `SpawnTrackingId`=1226607) OR (`QuestObjectiveId`=277541 AND `SpawnTrackingId`=1000408) OR (`QuestObjectiveId`=278646 AND `SpawnTrackingId`=1020927) OR (`QuestObjectiveId`=278645 AND `SpawnTrackingId`=1001827) OR (`QuestObjectiveId`=277559 AND `SpawnTrackingId`=1000552) OR (`QuestObjectiveId`=277536 AND `SpawnTrackingId`=999818) OR (`QuestObjectiveId`=277574 AND `SpawnTrackingId`=1020965) OR (`QuestObjectiveId`=280942 AND `SpawnTrackingId`=1102449) OR (`QuestObjectiveId`=283622 AND `SpawnTrackingId`=1150819) OR (`QuestObjectiveId`=283617 AND `SpawnTrackingId`=1150437) OR (`QuestObjectiveId`=283606 AND `SpawnTrackingId`=1150082) OR (`QuestObjectiveId`=280044 AND `SpawnTrackingId`=1057836) OR (`QuestObjectiveId`=279939 AND `SpawnTrackingId`=1051972) OR (`QuestObjectiveId`=280505 AND `SpawnTrackingId`=1082684) OR (`QuestObjectiveId`=280504 AND `SpawnTrackingId`=1082686) OR (`QuestObjectiveId`=287413 AND `SpawnTrackingId`=1260937) OR (`QuestObjectiveId`=287248 AND `SpawnTrackingId`=1260934) OR (`QuestObjectiveId`=280474 AND `SpawnTrackingId`=1079340) OR (`QuestObjectiveId`=280561 AND `SpawnTrackingId`=1084717) OR (`QuestObjectiveId`=282672 AND `SpawnTrackingId`=1073377) OR (`QuestObjectiveId`=279424 AND `SpawnTrackingId`=1039613) OR (`QuestObjectiveId`=279871 AND `SpawnTrackingId`=1050730) OR (`QuestObjectiveId`=279870 AND `SpawnTrackingId`=1050729) OR (`QuestObjectiveId`=279869 AND `SpawnTrackingId`=1050727) OR (`QuestObjectiveId`=279428 AND `SpawnTrackingId`=1039773) OR (`QuestObjectiveId`=279427 AND `SpawnTrackingId`=1039471) OR (`QuestObjectiveId`=280680 AND `SpawnTrackingId`=1087547) OR (`QuestObjectiveId`=280843 AND `SpawnTrackingId`=1087548) OR (`QuestObjectiveId`=280678 AND `SpawnTrackingId`=1087548) OR (`QuestObjectiveId`=282885 AND `SpawnTrackingId`=1055464) OR (`QuestObjectiveId`=279393 AND `SpawnTrackingId`=1038650) OR (`QuestObjectiveId`=279327 AND `SpawnTrackingId`=1035372) OR (`QuestObjectiveId`=279326 AND `SpawnTrackingId`=1035373) OR (`QuestObjectiveId`=279328 AND `SpawnTrackingId`=1035374) OR (`QuestObjectiveId`=280040 AND `SpawnTrackingId`=1069125) OR (`QuestObjectiveId`=280039 AND `SpawnTrackingId`=1069248) OR (`QuestObjectiveId`=280041 AND `SpawnTrackingId`=1069232) OR (`QuestObjectiveId`=279991 AND `SpawnTrackingId`=1055691) OR (`QuestObjectiveId`=280076 AND `SpawnTrackingId`=1063570) OR (`QuestObjectiveId`=279308 AND `SpawnTrackingId`=1035767) OR (`QuestObjectiveId`=279190 AND `SpawnTrackingId`=1068910) OR (`QuestObjectiveId`=284190 AND `SpawnTrackingId`=1166938) OR (`QuestObjectiveId`=280509 AND `SpawnTrackingId`=1082778) OR (`QuestObjectiveId`=280508 AND `SpawnTrackingId`=1082777) OR (`QuestObjectiveId`=280358 AND `SpawnTrackingId`=1082777) OR (`QuestObjectiveId`=279206 AND `SpawnTrackingId`=1034579) OR (`QuestObjectiveId`=288972 AND `SpawnTrackingId`=1267684);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63704 WHERE (`QuestObjectiveId`=279946 AND `SpawnTrackingId`=1053992) OR (`QuestObjectiveId`=284517 AND `SpawnTrackingId`=1169236) OR (`QuestObjectiveId`=284515 AND `SpawnTrackingId`=1174159) OR (`QuestObjectiveId`=286640 AND `SpawnTrackingId`=1174887) OR (`QuestObjectiveId`=286639 AND `SpawnTrackingId`=1174883) OR (`QuestObjectiveId`=286638 AND `SpawnTrackingId`=1174880) OR (`QuestObjectiveId`=286637 AND `SpawnTrackingId`=1174878) OR (`QuestObjectiveId`=280198 AND `SpawnTrackingId`=1068568) OR (`QuestObjectiveId`=280197 AND `SpawnTrackingId`=1068567) OR (`QuestObjectiveId`=280196 AND `SpawnTrackingId`=1068566) OR (`QuestObjectiveId`=280195 AND `SpawnTrackingId`=1068564) OR (`QuestObjectiveId`=280186 AND `SpawnTrackingId`=1068961) OR (`QuestObjectiveId`=280148 AND `SpawnTrackingId`=1067199) OR (`QuestObjectiveId`=280147 AND `SpawnTrackingId`=1067198) OR (`QuestObjectiveId`=280146 AND `SpawnTrackingId`=1067197) OR (`QuestObjectiveId`=280145 AND `SpawnTrackingId`=1067192) OR (`QuestObjectiveId`=278952 AND `SpawnTrackingId`=1040802) OR (`QuestObjectiveId`=278973 AND `SpawnTrackingId`=1028379) OR (`QuestObjectiveId`=278942 AND `SpawnTrackingId`=1027901) OR (`QuestObjectiveId`=278941 AND `SpawnTrackingId`=1027897) OR (`QuestObjectiveId`=278940 AND `SpawnTrackingId`=1027895) OR (`QuestObjectiveId`=278939 AND `SpawnTrackingId`=1027894) OR (`QuestObjectiveId`=284930 AND `SpawnTrackingId`=1040801) OR (`QuestObjectiveId`=284929 AND `SpawnTrackingId`=1037851) OR (`QuestObjectiveId`=284928 AND `SpawnTrackingId`=1037850) OR (`QuestObjectiveId`=284927 AND `SpawnTrackingId`=1037846) OR (`QuestObjectiveId`=284926 AND `SpawnTrackingId`=1037844) OR (`QuestObjectiveId`=284925 AND `SpawnTrackingId`=1037840) OR (`QuestObjectiveId`=279631 AND `SpawnTrackingId`=1099374) OR (`QuestObjectiveId`=280182 AND `SpawnTrackingId`=1008770) OR (`QuestObjectiveId`=280181 AND `SpawnTrackingId`=1067165) OR (`QuestObjectiveId`=280180 AND `SpawnTrackingId`=1067172) OR (`QuestObjectiveId`=280179 AND `SpawnTrackingId`=1065841) OR (`QuestObjectiveId`=280178 AND `SpawnTrackingId`=1065264) OR (`QuestObjectiveId`=280174 AND `SpawnTrackingId`=1068571) OR (`QuestObjectiveId`=280173 AND `SpawnTrackingId`=1068570) OR (`QuestObjectiveId`=280172 AND `SpawnTrackingId`=1068569) OR (`QuestObjectiveId`=280170 AND `SpawnTrackingId`=1068031) OR (`QuestObjectiveId`=280169 AND `SpawnTrackingId`=1066266) OR (`QuestObjectiveId`=278871 AND `SpawnTrackingId`=1027284) OR (`QuestObjectiveId`=278870 AND `SpawnTrackingId`=1027285) OR (`QuestObjectiveId`=278869 AND `SpawnTrackingId`=1027286) OR (`QuestObjectiveId`=280283 AND `SpawnTrackingId` IN (1071572,1071534)) OR (`QuestObjectiveId`=280035 AND `SpawnTrackingId`=1057956) OR (`QuestObjectiveId`=280031 AND `SpawnTrackingId`=1005815) OR (`QuestObjectiveId`=280025 AND `SpawnTrackingId`=1057955) OR (`QuestObjectiveId`=280024 AND `SpawnTrackingId`=1057954) OR (`QuestObjectiveId`=280023 AND `SpawnTrackingId`=1057953) OR (`QuestObjectiveId`=280021 AND `SpawnTrackingId`=1057281) OR (`QuestObjectiveId`=280017 AND `SpawnTrackingId`=1057952) OR (`QuestObjectiveId`=277732 AND `SpawnTrackingId`=1001964) OR (`QuestObjectiveId`=280004 AND `SpawnTrackingId`=1016548) OR (`QuestObjectiveId`=278476 AND `SpawnTrackingId`=1018680) OR (`QuestObjectiveId`=284811 AND `SpawnTrackingId`=1018074) OR (`QuestObjectiveId`=284810 AND `SpawnTrackingId`=1018073) OR (`QuestObjectiveId`=284809 AND `SpawnTrackingId`=1017076) OR (`QuestObjectiveId`=278466 AND `SpawnTrackingId`=1013301) OR (`QuestObjectiveId`=278465 AND `SpawnTrackingId`=1013300) OR (`QuestObjectiveId`=278464 AND `SpawnTrackingId`=1012971) OR (`QuestObjectiveId`=278492 AND `SpawnTrackingId`=1054939) OR (`QuestObjectiveId`=278491 AND `SpawnTrackingId`=1054940) OR (`QuestObjectiveId`=278432 AND `SpawnTrackingId`=1054938) OR (`QuestObjectiveId`=279981 AND `SpawnTrackingId`=1071481) OR (`QuestObjectiveId`=278235 AND `SpawnTrackingId`=1004668) OR (`QuestObjectiveId`=279774 AND `SpawnTrackingId`=1052391) OR (`QuestObjectiveId`=279773 AND `SpawnTrackingId`=1047159) OR (`QuestObjectiveId`=279899 AND `SpawnTrackingId`=1052281) OR (`QuestObjectiveId`=279898 AND `SpawnTrackingId`=1052273) OR (`QuestObjectiveId`=279897 AND `SpawnTrackingId`=1052246) OR (`QuestObjectiveId`=279896 AND `SpawnTrackingId`=1052214) OR (`QuestObjectiveId`=277831 AND `SpawnTrackingId`=1004349) OR (`QuestObjectiveId`=277830 AND `SpawnTrackingId`=1004952) OR (`QuestObjectiveId`=277827 AND `SpawnTrackingId`=1005449) OR (`QuestObjectiveId`=277826 AND `SpawnTrackingId`=1004952) OR (`QuestObjectiveId`=277825 AND `SpawnTrackingId`=1074423) OR (`QuestObjectiveId`=277721 AND `SpawnTrackingId`=1009740) OR (`QuestObjectiveId`=280858 AND `SpawnTrackingId`=1002765) OR (`QuestObjectiveId`=279892 AND `SpawnTrackingId`=1005320) OR (`QuestObjectiveId`=277816 AND `SpawnTrackingId`=1004047) OR (`QuestObjectiveId`=277815 AND `SpawnTrackingId`=1004040) OR (`QuestObjectiveId`=277814 AND `SpawnTrackingId`=1002704) OR (`QuestObjectiveId`=279738 AND `SpawnTrackingId`=1044242) OR (`QuestObjectiveId`=279732 AND `SpawnTrackingId`=1043683) OR (`QuestObjectiveId`=279739 AND `SpawnTrackingId`=1045997) OR (`QuestObjectiveId`=279725 AND `SpawnTrackingId`=1043849) OR (`QuestObjectiveId`=279726 AND `SpawnTrackingId`=1043850) OR (`QuestObjectiveId`=279724 AND `SpawnTrackingId`=1043843) OR (`QuestObjectiveId`=279722 AND `SpawnTrackingId`=1043841) OR (`QuestObjectiveId`=279721 AND `SpawnTrackingId`=1042505) OR (`QuestObjectiveId`=279720 AND `SpawnTrackingId`=1042708) OR (`QuestObjectiveId`=279716 AND `SpawnTrackingId`=1045633) OR (`QuestObjectiveId`=279715 AND `SpawnTrackingId`=1043984) OR (`QuestObjectiveId`=279714 AND `SpawnTrackingId`=1044023) OR (`QuestObjectiveId`=285319 AND `SpawnTrackingId` IN (1212098,1212072)) OR (`QuestObjectiveId`=285318 AND `SpawnTrackingId` IN (1212109,1212050)) OR (`QuestObjectiveId`=285317 AND `SpawnTrackingId` IN (1212090,1212044)) OR (`QuestObjectiveId`=277473 AND `SpawnTrackingId`=999105) OR (`QuestObjectiveId`=278188 AND `SpawnTrackingId`=999105) OR (`QuestObjectiveId`=278005 AND `SpawnTrackingId`=1007988) OR (`QuestObjectiveId`=277451 AND `SpawnTrackingId`=999136) OR (`QuestObjectiveId`=286405 AND `SpawnTrackingId`=1069733) OR (`QuestObjectiveId`=279839 AND `SpawnTrackingId`=1069733) OR (`QuestObjectiveId`=286220 AND `SpawnTrackingId`=1232453) OR (`QuestObjectiveId`=286103 AND `SpawnTrackingId`=1050875) OR (`QuestObjectiveId`=279833 AND `SpawnTrackingId`=1129368) OR (`QuestObjectiveId`=280339 AND `SpawnTrackingId`=1002258) OR (`QuestObjectiveId`=283489 AND `SpawnTrackingId`=1147957) OR (`QuestObjectiveId`=279945 AND `SpawnTrackingId`=1172984) OR (`QuestObjectiveId`=284235 AND `SpawnTrackingId`=1168260) OR (`QuestObjectiveId`=287539 AND `SpawnTrackingId` IN (1253897,1251076)) OR (`QuestObjectiveId`=280887 AND `SpawnTrackingId`=1036293) OR (`QuestObjectiveId`=280885 AND `SpawnTrackingId`=1081866) OR (`QuestObjectiveId`=280890 AND `SpawnTrackingId`=1099333) OR (`QuestObjectiveId`=279313 AND `SpawnTrackingId`=1036137) OR (`QuestObjectiveId`=280436 AND `SpawnTrackingId`=1081863) OR (`QuestObjectiveId`=279312 AND `SpawnTrackingId`=1036136) OR (`QuestObjectiveId`=280415 AND `SpawnTrackingId` IN (1019058,1019061,1019059,1202891,1019060)) OR (`QuestObjectiveId`=284843 AND `SpawnTrackingId`=1197928) OR (`QuestObjectiveId`=283927 AND `SpawnTrackingId`=1149386) OR (`QuestObjectiveId`=285214 AND `SpawnTrackingId`=1209523) OR (`QuestObjectiveId`=284252 AND `SpawnTrackingId`=1209522) OR (`QuestObjectiveId`=285215 AND `SpawnTrackingId`=1157614) OR (`QuestObjectiveId`=284253 AND `SpawnTrackingId`=1067534) OR (`QuestObjectiveId`=284430 AND `SpawnTrackingId`=1067529) OR (`QuestObjectiveId`=284429 AND `SpawnTrackingId`=1067534) OR (`QuestObjectiveId`=284428 AND `SpawnTrackingId`=1153687) OR (`QuestObjectiveId`=284427 AND `SpawnTrackingId`=1067534) OR (`QuestObjectiveId`=284426 AND `SpawnTrackingId`=1157614) OR (`QuestObjectiveId`=284425 AND `SpawnTrackingId`=1157615) OR (`QuestObjectiveId`=280133 AND `SpawnTrackingId` IN (1082746,1085044,1120564,1081444,1055809,1068068,1078072,1126749,1050464)) OR (`QuestObjectiveId`=282142 AND `SpawnTrackingId`=1067534) OR (`QuestObjectiveId`=282128 AND `SpawnTrackingId`=1129947) OR (`QuestObjectiveId`=281291 AND `SpawnTrackingId`=1105807) OR (`QuestObjectiveId`=281320 AND `SpawnTrackingId`=1118158) OR (`QuestObjectiveId`=281319 AND `SpawnTrackingId`=1118157) OR (`QuestObjectiveId`=281318 AND `SpawnTrackingId`=1118156) OR (`QuestObjectiveId`=281317 AND `SpawnTrackingId`=1118155) OR (`QuestObjectiveId`=281281 AND `SpawnTrackingId`=1120550) OR (`QuestObjectiveId`=281198 AND `SpawnTrackingId`=1119349) OR (`QuestObjectiveId`=282041 AND `SpawnTrackingId`=1128716) OR (`QuestObjectiveId`=281071 AND `SpawnTrackingId`=1127450) OR (`QuestObjectiveId`=281958 AND `SpawnTrackingId`=1107037) OR (`QuestObjectiveId`=281070 AND `SpawnTrackingId`=1127717) OR (`QuestObjectiveId`=281865 AND `SpawnTrackingId`=1125868) OR (`QuestObjectiveId`=281904 AND `SpawnTrackingId`=1126306) OR (`QuestObjectiveId`=281864 AND `SpawnTrackingId`=1125892) OR (`QuestObjectiveId`=286744 AND `SpawnTrackingId`=1248490) OR (`QuestObjectiveId`=286773 AND `SpawnTrackingId` IN (1719603,1719591)) OR (`QuestObjectiveId`=281187 AND `SpawnTrackingId`=1111827) OR (`QuestObjectiveId`=284779 AND `SpawnTrackingId`=1195731);
UPDATE `spawn_tracking_quest_objective` SET `VerifiedBuild`=63660 WHERE (`QuestObjectiveId`=284779 AND `SpawnTrackingId`=1195731) OR (`QuestObjectiveId`=284738 AND `SpawnTrackingId` IN (1193016,1193017,1193018,1193021,1193020,1193019)) OR (`QuestObjectiveId`=284737 AND `SpawnTrackingId` IN (1192898,1192897,1192896)) OR (`QuestObjectiveId`=284736 AND `SpawnTrackingId` IN (1191347,1191359)) OR (`QuestObjectiveId`=388348 AND `SpawnTrackingId`=1731862) OR (`QuestObjectiveId`=388347 AND `SpawnTrackingId`=1717498) OR (`QuestObjectiveId`=388313 AND `SpawnTrackingId`=1717268) OR (`QuestObjectiveId`=388314 AND `SpawnTrackingId`=1731623) OR (`QuestObjectiveId`=388312 AND `SpawnTrackingId`=1731609) OR (`QuestObjectiveId`=388311 AND `SpawnTrackingId`=1717016);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (115603, 130099, 110488, 109301, 120489, 128360, 129122, 122784, 137491, 128260, 128259, 128257, 114260, 137489, 137488, 131983, 114465, 80808, 114133, 131778, 137485);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(115603, 0.314999997615814208, 1.349999904632568359, 0, 63834),
(130099, 0.5, 0.5, 0, 63834),
(110488, 0.378777623176574707, 0.974999964237213134, 0, 63834),
(109301, 0.447770565748214721, 0.60000002384185791, 0, 63834),
(120489, 1.483475446701049804, 0, 0, 63834),
(128360, 0.290918290615081787, 0, 0, 63834),
(129122, 40, 8, 0, 63834),
(122784, 1.798517942428588867, 5.599999904632568359, 0, 63834),
(137491, 0.386561989784240722, 0, 0, 63834),
(128260, 0.249600008130073547, 1.80000007152557373, 0, 63834),
(128259, 0.367200016975402832, 1.80000007152557373, 0, 63834),
(128257, 0.367200016975402832, 1.80000007152557373, 0, 63834),
(114260, 0.336600005626678466, 1.65000009536743164, 0, 63834),
(137489, 0.529763579368591308, 0.900000035762786865, 0, 63834),
(137488, 0.88293921947479248, 1.5, 0, 63834),
(131983, 0.305999994277954101, 1.5, 0, 63834),
(114465, 0.300000011920928955, 0, 0, 63834),
(80808, 0.542188048362731933, 0.75, 0, 63834),
(114133, 0.208000004291534423, 1.5, 0, 63834),
(131778, 40, 8, 0, 63834),
(137485, 1.452710270881652832, 1.5, 0, 63834);

UPDATE `creature_model_info` SET `VerifiedBuild`=63834 WHERE `DisplayID` IN (102521, 71860, 72132, 72133, 62217, 28012, 28011, 51660, 60089, 16178, 60080, 73920, 67392, 2421, 62250, 69615, 62029, 62272, 61624, 61625, 61629, 69756, 61627, 62271, 61630, 61626, 72385, 67521, 58481, 53503, 61601, 64265, 71016, 61866, 61209, 66731, 66730, 66734, 66732, 66735, 66733, 61056, 70282, 61401, 70135, 69903, 61173, 61750, 61748, 65642, 70509, 44691, 70508, 69922, 61740, 57027, 40607, 95929, 10690, 67717, 69857, 25252, 69979, 73025, 69830, 88061, 62541, 60081, 69969, 69978, 30754, 69980, 59611, 64002, 61733, 61731, 61745, 61283, 68476, 68409, 29849, 68655, 72248, 48226, 62584, 34069, 43199, 48317, 62385, 25195, 72247, 67737, 65728, 68225, 67483, 64669, 66029, 66186, 67736, 67621, 64044, 68187, 62706, 64142, 63141, 67564, 67433, 27767, 67422, 14255, 2727, 67630, 67563, 68302, 87426, 46458, 64735, 72244, 41574, 65302, 65215, 48529, 25774, 28213, 62641, 74699, 74072, 73942, 68688, 39769, 12869, 62545, 70359, 66390, 65993, 70383, 70537, 64845, 65983, 70507, 70918, 63496, 27791, 70917, 24384, 24301, 63385, 74058, 70919, 9904, 24387, 63376, 66111, 61276, 129133, 66176, 63912, 66422, 62780, 65802, 39162, 65824, 53093, 70778, 63267, 27570, 65727, 67168, 66723, 68357, 68085, 68096, 68355, 68183, 68177, 5126, 73490, 70637, 1109, 113609, 66512, 63255, 25940, 65687, 70331, 985, 63347, 64589, 71147, 63370, 25771, 63335, 46930, 58886, 42149, 61352, 39016, 50919, 73725, 63471, 68001, 67995, 68002, 67997, 67996, 2153, 64565, 67535, 83911, 63566, 62601, 67238, 62598, 62599, 62600, 70491, 63106, 68198, 61825, 40753, 32183, 67626, 55720, 29780, 62362, 63111, 65137, 65078, 84934, 84680, 66141, 68180, 68173, 68171, 68170, 18100, 33753, 60536, 33754, 67962, 68123, 68115, 7042, 70395, 72984, 74251, 68326, 39696, 68297, 58781, 68124, 68113, 69312, 69308, 69310, 66767, 66674, 67913, 1866, 2087, 47165, 72980, 72979, 66675, 68309, 44876, 68310, 68174, 60541, 58325, 58780, 68129, 68135, 68126, 68122, 68120, 68118, 68117, 68112, 63552, 58275, 60593, 67725, 20228, 66737, 54194, 58777, 60576, 68150, 67754, 44905, 2325, 35929, 67970, 65087, 28288, 29000, 64736, 60766, 69816, 40192, 69485, 69504, 69511, 68601, 70677, 70676, 64646, 87556, 32939, 25341, 56327, 70399, 62550, 68949, 27715, 27714, 27713, 27712, 27717, 27716, 81469, 88702, 83932, 65867, 83362, 88431, 81267, 83306, 83305, 88432, 81277, 88430, 23304, 84427, 81320, 57807, 88685, 87218, 83820, 123991, 82178, 82179, 19785, 77489, 88828, 45513, 87648, 87788, 87050, 83812, 87795, 74793, 79970, 81168, 79969, 87815, 66653, 21859, 21858, 18054, 100163, 100177, 100186, 100185, 36792, 36791, 100178, 78428, 86725, 66746, 20857, 26566, 74395, 64391, 67335, 67284, 66061, 66060, 66059, 66058, 30239, 40077, 67704, 67703, 32511, 67344, 67509, 67476, 1198, 67507, 2676, 67510, 67508, 1197, 66322, 14315, 65070, 73636, 73923, 73996, 73919, 70059, 73914, 73995, 24135, 67592, 66659, 65058, 65044, 66753, 66319, 65996, 67133, 119938, 67881, 65056, 70034, 123205, 123203, 119937, 123200, 69492, 68991, 82874, 83233, 53768, 63487, 63485, 63483, 70071, 68730, 69972, 39421, 69420, 62703, 25898, 67129, 62280, 119939, 72065, 34770, 70560, 123211, 123068, 123202, 61370, 61189, 61350, 63369, 66648, 65972, 46298, 5553, 14615, 4846, 4845, 4847, 68111, 65518, 63857, 66243, 33184, 68201, 65260, 31998, 65461, 123197, 123194, 72109, 119202, 123204, 72108, 73206, 123192, 105803, 123208, 123193, 123199, 123198, 64764, 63792, 123206, 123210, 123209, 119936, 123207, 64690, 64783, 73956, 65455, 38042, 30760, 30761, 61894, 99873, 81441, 75946, 20853, 15550, 17275, 13529, 10649, 11769, 10646, 58796, 21136, 15477, 16430, 10254, 81444, 8572, 30781, 123201, 123195, 30782, 30784, 90628, 81443, 72028, 72022, 2289, 82132, 71594, 70640, 65170, 67029, 43281, 71871, 31863, 69866, 67537, 67006, 69864, 69868, 66036, 73728, 42568, 62609, 64334, 64676, 64530, 66624, 66617, 66625, 67999, 70909, 32234, 21382, 60652, 123120, 123119, 68410, 123126, 88705, 66381, 123173, 66616, 66382, 87603, 29756, 85339, 85046, 85040, 60604, 72864, 72871, 63995, 64561, 66224, 63860, 63988, 64559, 72865, 64405, 21362, 72285, 72866, 72872, 72869, 66615, 119951, 64601, 70536, 123127, 123118, 63606, 60783, 60782, 60772, 60781, 33224, 64548, 64366, 66759, 80388, 93311, 60098, 68985, 50910, 63393, 64444, 123121, 64445, 29422, 63659, 13109, 41876, 52834, 123122, 43164, 15984, 32257, 32256, 68114, 63264, 71659, 65593, 32255, 32258, 63715, 9492, 75078, 119950, 123116, 41669, 68419, 90691, 37730, 123124, 90959, 87425, 86520, 84013, 83933, 83934, 41326, 79041, 79043, 83929, 79406, 88704, 83643, 86176, 79040, 79404, 86175, 52520, 45159, 77487, 82052, 81340, 80587, 81259, 87647, 80824, 81748, 123161, 24925, 71721, 62849, 68732, 67196, 56533, 45157, 44634, 45156, 45158, 63497, 21122, 54756, 1994, 87922, 84805, 31994, 86549, 80049, 87921, 83843, 2836, 87920, 72817, 72819, 72820, 81725, 81143, 51502, 81148, 78671, 81146, 77955, 81147, 80053, 88362, 84087, 84085, 80055, 78623, 79042, 78624, 81150, 44168, 78625, 82184, 51294, 85629, 79195, 87979, 81966, 81965, 81964, 86952, 79375, 81994, 82000, 80703, 79369, 80928, 79368, 24932, 16356, 64978, 81154, 79477, 77902, 88203, 88242, 88189, 88187, 63972, 78473, 78047, 78051, 86942, 63970, 81743, 82186, 81746, 78048, 81742, 78052, 84088, 78049, 78050, 82795, 84086, 81358, 81356, 63901, 70942, 64397, 65481, 60265, 65769, 65214, 30262, 64656, 123163, 70227, 70226, 59585, 71923, 119945, 64374, 66178, 65775, 93437, 62748, 32680, 60411, 57434, 61348, 65199, 34004, 62092, 34005, 60474, 60528, 57429, 60005, 60462, 60414, 58340, 60731, 59933, 60405, 60489, 60552, 57298, 59980, 59976, 60018, 60597, 60402, 60045, 60524, 60443, 60539, 81459, 68088, 68206, 36511, 4341, 31251, 123170, 84807, 81458, 80402, 81460, 81357, 81210, 81461, 36547, 75372, 79070, 79068, 40093, 79071, 77482, 79069, 85811, 63016, 82845, 82019, 78240, 75377, 81799, 78151, 75374, 75699, 79559, 85664, 86618, 39109, 1939, 88191, 88491, 85640, 85658, 80177, 85655, 85659, 73084, 73083, 73079, 73176, 67315, 53598, 34881, 34889, 87049, 87062, 85654, 88195, 87053, 88156, 85661, 87052, 77054, 88153, 87907, 88503, 87054, 82543, 76858, 82539, 87659, 88241, 76550, 79541, 87948, 94462, 94459, 87596, 91012, 91011, 91009, 165, 84166, 64074, 84173, 84174, 87565, 60256, 77041, 31847, 84415, 5565, 89604, 32778, 86168, 87599, 86443, 76907, 87649, 78482, 83664, 84559, 87584, 87583, 85642, 87601, 78472, 87600, 87612, 93838, 82545, 82148, 85962, 85963, 85964, 87794, 84544, 76422, 87376, 87375, 87713, 84110, 84557, 73473, 74998, 68981, 68984, 68983, 67758, 67759, 123165, 58049, 71735, 94544, 30507, 68987, 68986, 29615, 71718, 71717, 71716, 66411, 71733, 71732, 71731, 71538, 71715, 123169, 67676, 71662, 68828, 71030, 71032, 71741, 69438, 63751, 62586, 65948, 84555, 84554, 53108, 88690, 88528, 85758, 84139, 81312, 81313, 55345, 86439, 83521, 88825, 82995, 87495, 90161, 83532, 83093, 85228, 82026, 82025, 82024, 80893, 93865, 38801, 87422, 58202, 53107, 86471, 81291, 83531, 83533, 85767, 86764, 87581, 88502, 88264, 86763, 77496, 87786, 77466, 88271, 77936, 85967, 77691, 88262, 78964, 77940, 81166, 87628, 87781, 87796, 77532, 87797, 24052, 87780, 87793, 87790, 88318, 88317, 87630, 87634, 39631, 88493, 87611, 76552, 81194, 87769, 33519, 87690, 82813, 84069, 77851, 81807, 87791, 87792, 87549, 87183, 87638, 88050, 77523, 26353, 88049, 91067, 85771, 86472, 88265, 86640, 80178, 87632, 85396, 87636, 87622, 82134, 87602, 86638, 85714, 44575, 84812, 77698, 77052, 84142, 86027, 86641, 90653, 81589, 25880, 76871, 88134, 81353, 83301, 83303, 84064, 88139, 15136, 80247, 42365, 83983, 88278, 88140, 83304, 83985, 81354, 83984, 34450, 87614, 81352, 41325, 77043, 88137, 83302, 88136, 88446, 88135, 84437, 88141, 87699, 85896, 83641, 88450, 85898, 88451, 85890, 85893, 88445, 85897, 83982, 81351, 85895, 88456, 85894, 88557, 88550, 83834, 80858, 85656, 89042, 89037, 89035, 88411, 78466, 85900, 84504, 41408, 87613, 86950, 85368, 82340, 78483, 84084, 84470, 85369, 77498, 65464, 87757, 85657, 79390, 88302, 83892, 83893, 83909, 85400, 84529, 83890, 85347, 87568, 87582, 79313, 75047, 82234, 87668, 82665, 82538, 90693, 85281, 89751, 96674, 105588, 87670, 75814, 85329, 85306, 85332, 45263, 93455, 88608, 88489, 85509, 87897, 82544, 64668, 73108, 73441, 27956, 27962, 26310, 65174, 73446, 73449, 73442, 73444, 73448, 73447, 73450, 73445, 73443, 54918, 65053, 71649, 64788, 85510, 85559, 82541, 85512, 85513, 81345, 88154, 84073, 85515, 85653, 85516, 85639, 88605, 85636, 82540, 78963, 87394, 84072, 85622, 85620, 88614, 84075, 84074, 76890, 85307, 85406, 73007, 85315, 88496, 78478, 84284, 88621, 88303, 88486, 87392, 88613, 78479, 80182, 87395, 80180, 85283, 85271, 82546, 85301, 85273, 84262, 88484, 83883, 88610, 93508, 83862, 81802, 84339, 76547, 77055, 89034, 86026, 85268, 85267, 93521, 76518, 85437, 85266, 52582, 88607, 85493, 85892, 82950, 77053, 85441, 88609, 85549, 88298, 86025, 85548, 88611, 85550, 85547, 85044, 84201, 88199, 79064, 88321, 88294, 93453, 88200, 78475, 78806, 87817, 78962, 81207, 84551, 78471, 88279, 87891, 88185, 88495, 85045, 83889, 78967, 69960, 88079, 87687, 88044, 88548, 88192, 87928, 87925, 88074, 87686, 87030, 78481, 93450, 88547, 88190, 92705, 80747, 78994, 84263, 80754, 88612, 87689, 88615, 87924, 88604, 88073, 81321, 87909, 88606, 80846, 87910, 84412, 84092, 78223, 84091, 80857, 82693, 73171, 73170, 79015, 78835, 61205, 73006, 73005, 707, 61206, 70333, 35424, 80854, 80749, 79871, 80751, 25878, 29835, 25655, 29834, 65511, 83697, 34274, 83696, 82955, 82956, 119944, 81878, 87420, 81861, 87397, 82738, 83197, 82869, 87421, 80287, 60371, 82006, 82004, 77484, 71246, 82005, 83520, 43110, 87590, 82003, 82909, 75383, 57795, 57554, 88623, 86711, 81278, 83307, 88739, 83292, 81201, 33826, 82103, 85053, 82100, 86349, 88697, 81288, 86311, 81283, 86307, 81282, 86309, 123162, 102070, 64638, 64018, 90695, 43156, 45887, 46887, 73043, 43932, 73058, 70163, 70165, 73067, 73065, 16239, 88680, 85042, 88681, 78928, 85041, 81663, 71828, 87006, 87014, 32187, 75365, 82550, 88429, 71701, 981, 83768, 79014, 85817, 85797, 83771, 88525, 21936, 76549, 81349, 81350, 88639, 84293, 85145, 65163, 25594, 65172, 86533, 85152, 65768, 88698, 81713, 65083, 24946, 25633, 65219, 83548, 40000, 81928, 64191, 65039, 85649, 86734, 79058, 86735, 86737, 86736, 79059, 82937, 90896, 66764, 123167, 77946, 123164, 80850, 123168, 71673, 69945, 77396, 87111, 90894, 87518, 69690, 68116, 76995, 76994, 81061, 123166, 62732, 42855, 42744, 86475, 80766, 80735, 84790, 76993, 76992, 81522, 76671, 80733, 80926, 80768, 81576, 80767, 85026, 85022, 85023, 80734, 80765, 84419, 84505, 81080, 70157, 84893, 86473, 28016, 81872, 85032, 81873, 85178, 83401, 79804, 79807, 85177, 83399, 83402, 85030, 85176, 85031, 79806, 25843, 67955, 86197, 77269, 79540, 80444, 80653, 88527, 79522, 79523, 81078, 40025, 70445, 8014, 77050, 77051, 79281, 765, 53282, 79552, 81082, 65939, 78630, 78633, 78631, 78632, 78641, 88295, 68514, 68515, 81085, 10579, 80701, 68516, 81262, 29419, 81338, 10824, 36060, 68517, 65573, 23966, 30500, 83325, 81198, 36700, 1964, 29253, 81202, 88566, 86530, 52738, 6106, 81083, 88563, 81084, 81688, 81145, 81658, 30222, 1963, 4652, 85206, 88564, 84246, 82237, 88695, 75329, 69, 106517, 85208, 87763, 85207, 76548, 86974, 5369, 82312, 86531, 85149, 85151, 57480, 87015, 85150, 85702, 85115, 84777, 84296, 81373, 85413, 81362, 84294, 88644, 56645, 81374, 81294, 25092, 84454, 84444, 81366, 81368, 87386, 81364, 83979, 84725, 81363, 84567, 84349, 84546, 78480, 86489, 84436, 81372, 87456, 31979, 84568, 88428, 84564, 76875, 85519, 84545, 84547, 81567, 90951, 84566, 88427, 65560, 81369, 64814, 84548, 87370, 82001, 58380, 52599, 64016, 52598, 10612, 36499, 65082, 65129, 37737, 66004, 88679, 83273, 88625, 88682, 83815, 65770, 65767, 67164, 73076, 25293, 63676, 25255, 67163, 65068, 64570, 62785, 21950, 70397, 65084, 28317, 73073, 63468, 55806, 11343, 26335, 25616, 26390, 25622, 26376, 15505, 25644, 26378, 85200, 27849, 84083, 90852, 76601, 30098, 25613, 68639, 73169, 72234, 72228, 73089, 47035, 73276, 73277, 72227, 72232, 73070, 73072, 73069, 73071, 72230, 73090, 73166, 73075, 73074, 66652, 26075, 25645, 27782, 63050, 28433, 25648, 45425, 25619, 109774, 62622, 65756, 63430, 65171, 65173, 25668, 73053, 73068, 73066, 73054, 66292, 23289, 21120, 26992, 63408, 27101, 99629, 90149, 80752, 90814, 90999, 88619, 87519, 1070, 80753, 7763, 8714, 62219, 63095, 62651, 63096, 63094, 75361, 67127, 67198, 58232, 29310, 18526, 73062, 73282, 71620, 73188, 73186, 73051, 29417, 73050, 73082, 73177, 73064, 73275, 14780, 73088, 73080, 66896, 73085, 66934, 66933, 73047, 73049, 73174, 73281, 63488, 66895, 64753, 73168, 73087, 73274, 66932, 73060, 73178, 66898, 73086, 73081, 70533, 45101, 73052, 27913, 73175, 73059, 73272, 95171, 73183, 73189, 73181, 19071, 72903, 19073, 70741, 63038, 63921, 63920, 63736, 70703, 75299, 44978, 45192, 44979, 71615, 44980, 44977, 64938, 22351, 7006, 80352, 70626, 26991, 73184, 66086, 26990, 74437, 66015, 24351, 105247, 34446, 34537, 34439, 70771, 27894, 26989, 60498, 34535, 34438, 70330, 34440, 70770, 34536, 57267, 1505, 70573, 33770, 57255, 70302, 16936, 58500, 61504, 57242, 59971, 60519, 70413, 25851, 70297, 61187, 60560, 60041, 60543, 60409, 70305, 3098, 59189, 60466, 14753, 59187, 57249, 61502, 70625, 60070, 58261, 14613, 14614, 70329, 70325, 60487, 60075, 58682, 58990, 58467, 58690, 58502, 61371, 61356, 58457, 58786, 70327, 70317, 70309, 70308, 70319, 70307, 70303, 70320, 70349, 70351, 122493, 70298, 70313, 70306, 23073, 70323, 59188, 70304, 70328, 70311, 70300, 70326, 70315, 70312, 70324, 70316, 70299, 70321, 23072, 70318, 70314, 70310, 70350, 122124, 80809, 80957, 21908, 80812, 129131, 108777, 124292, 120332, 71264, 71263, 71260, 70121, 71269, 71261, 71262, 65596, 102298, 64661, 71258, 66240, 119057, 25877, 26311, 29145, 64023, 26321, 72772, 61872, 65488, 68051, 68045, 62395, 59734, 63592, 63935, 120339, 119051, 119121, 65131, 66369, 61698, 72961, 66396, 60079, 65683, 63986, 68669, 65981, 65697, 23856, 64599, 64416, 122121, 119099, 64417, 66377, 64766, 64029, 9129, 64294, 60791, 69985, 68169, 64781, 69982, 64762);
UPDATE `creature_model_info` SET `BoundingRadius`=0.405183523893356323, `VerifiedBuild`=63834 WHERE `DisplayID`=66191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `VerifiedBuild`=63834 WHERE `DisplayID`=24608;
UPDATE `creature_model_info` SET `BoundingRadius`=1.189880013465881347, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID`=69678;
UPDATE `creature_model_info` SET `BoundingRadius`=3.315983533859252929, `VerifiedBuild`=63834 WHERE `DisplayID`=69683;
UPDATE `creature_model_info` SET `BoundingRadius`=4.891517162322998046, `VerifiedBuild`=63834 WHERE `DisplayID`=73609;
UPDATE `creature_model_info` SET `BoundingRadius`=1.166556477546691894, `CombatReach`=1, `VerifiedBuild`=63834 WHERE `DisplayID`=25245;
UPDATE `creature_model_info` SET `BoundingRadius`=41.50489044189453125, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID`=65043;
UPDATE `creature_model_info` SET `BoundingRadius`=0.954134941101074218, `VerifiedBuild`=63834 WHERE `DisplayID`=73941;
UPDATE `creature_model_info` SET `BoundingRadius`=0.902500033378601074, `CombatReach`=3.75, `VerifiedBuild`=63834 WHERE `DisplayID` IN (74357, 66146);
UPDATE `creature_model_info` SET `BoundingRadius`=0.837016999721527099, `CombatReach`=0, `VerifiedBuild`=63834 WHERE `DisplayID`=88975;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=63834 WHERE `DisplayID` IN (531, 70398, 66751, 68712, 70424);
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1, `VerifiedBuild`=63834 WHERE `DisplayID`=25814;
UPDATE `creature_model_info` SET `BoundingRadius`=0.936534702777862548, `VerifiedBuild`=63834 WHERE `DisplayID`=63891;
UPDATE `creature_model_info` SET `BoundingRadius`=2.0625, `CombatReach`=6.1875, `VerifiedBuild`=63834 WHERE `DisplayID`=68197;
UPDATE `creature_model_info` SET `BoundingRadius`=0.583500027656555175, `CombatReach`=2.25, `VerifiedBuild`=63834 WHERE `DisplayID`=69088;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID` IN (67188, 69943);
UPDATE `creature_model_info` SET `BoundingRadius`=6.527835845947265625, `CombatReach`=10.5, `VerifiedBuild`=63834 WHERE `DisplayID`=67150;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=63834 WHERE `DisplayID` IN (65520, 69691);
UPDATE `creature_model_info` SET `BoundingRadius`=1.441844582557678222, `VerifiedBuild`=63834 WHERE `DisplayID`=69056;
UPDATE `creature_model_info` SET `BoundingRadius`=1.70543670654296875, `CombatReach`=3, `VerifiedBuild`=63834 WHERE `DisplayID` IN (72063, 68683);
UPDATE `creature_model_info` SET `BoundingRadius`=1.108533859252929687, `CombatReach`=1.949999928474426269, `VerifiedBuild`=63834 WHERE `DisplayID`=68839;
UPDATE `creature_model_info` SET `BoundingRadius`=0.852718353271484375, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=68838;
UPDATE `creature_model_info` SET `BoundingRadius`=1.076429367065429687, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=88873;
UPDATE `creature_model_info` SET `BoundingRadius`=2.167345762252807617, `VerifiedBuild`=63834 WHERE `DisplayID`=66340;
UPDATE `creature_model_info` SET `BoundingRadius`=1.258555769920349121, `VerifiedBuild`=63834 WHERE `DisplayID`=65104;
UPDATE `creature_model_info` SET `BoundingRadius`=0.14100000262260437, `CombatReach`=0.60000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID`=15092;
UPDATE `creature_model_info` SET `BoundingRadius`=0.872500002384185791, `CombatReach`=3.75, `VerifiedBuild`=63834 WHERE `DisplayID`=67732;
UPDATE `creature_model_info` SET `BoundingRadius`=0.698000013828277587, `CombatReach`=3, `VerifiedBuild`=63834 WHERE `DisplayID` IN (67331, 67332, 66532);
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `VerifiedBuild`=63834 WHERE `DisplayID` IN (67330, 67329);
UPDATE `creature_model_info` SET `BoundingRadius`=1.179895997047424316, `VerifiedBuild`=63834 WHERE `DisplayID`=64568;
UPDATE `creature_model_info` SET `BoundingRadius`=0.83760005235671997, `CombatReach`=3.60000014305114746, `VerifiedBuild`=63834 WHERE `DisplayID` IN (65889, 65446);
UPDATE `creature_model_info` SET `BoundingRadius`=0.866400063037872314, `CombatReach`=3.60000014305114746, `VerifiedBuild`=63834 WHERE `DisplayID` IN (65883, 65884);
UPDATE `creature_model_info` SET `BoundingRadius`=3.49729776382446289, `CombatReach`=3.20000004768371582, `VerifiedBuild`=63834 WHERE `DisplayID`=70500;
UPDATE `creature_model_info` SET `BoundingRadius`=1.669736146926879882, `CombatReach`=3.5, `VerifiedBuild`=63834 WHERE `DisplayID`=69803;
UPDATE `creature_model_info` SET `BoundingRadius`=1.7618865966796875, `VerifiedBuild`=63834 WHERE `DisplayID`=69849;
UPDATE `creature_model_info` SET `BoundingRadius`=1.478459119796752929, `VerifiedBuild`=63834 WHERE `DisplayID`=68423;
UPDATE `creature_model_info` SET `BoundingRadius`=1.631958961486816406, `CombatReach`=2.625, `VerifiedBuild`=63834 WHERE `DisplayID`=72106;
UPDATE `creature_model_info` SET `BoundingRadius`=1.719884991645812988, `CombatReach`=2.25, `VerifiedBuild`=63834 WHERE `DisplayID`=72107;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=68452;
UPDATE `creature_model_info` SET `BoundingRadius`=2.745749950408935546, `VerifiedBuild`=63834 WHERE `DisplayID`=68366;
UPDATE `creature_model_info` SET `BoundingRadius`=7.520761013031005859, `CombatReach`=4, `VerifiedBuild`=63834 WHERE `DisplayID`=68680;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID` IN (67289, 69950, 70134, 69944, 69953, 69949);
UPDATE `creature_model_info` SET `BoundingRadius`=2.997439146041870117, `CombatReach`=1.918367385864257812, `VerifiedBuild`=63834 WHERE `DisplayID`=62722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.272727280855178833, `VerifiedBuild`=63834 WHERE `DisplayID`=74652;
UPDATE `creature_model_info` SET `BoundingRadius`=0.548455715179443359, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID`=41000;
UPDATE `creature_model_info` SET `BoundingRadius`=2.092338085174560546, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID`=70951;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=68735;
UPDATE `creature_model_info` SET `BoundingRadius`=0.704830348491668701, `VerifiedBuild`=63834 WHERE `DisplayID`=12337;
UPDATE `creature_model_info` SET `BoundingRadius`=2.293179988861083984, `CombatReach`=3, `VerifiedBuild`=63834 WHERE `DisplayID`=70370;
UPDATE `creature_model_info` SET `BoundingRadius`=3.124989748001098632, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID` IN (52835, 52656);
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599251747131347, `CombatReach`=1.75, `VerifiedBuild`=63834 WHERE `DisplayID`=342;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID` IN (59186, 59973, 57432, 69951, 66527, 66529, 66530, 66528, 69952, 69946, 69948);
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=26186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID` IN (60500, 58774, 59433);
UPDATE `creature_model_info` SET `BoundingRadius`=0.208027213811874389, `CombatReach`=0.75, `VerifiedBuild`=63834 WHERE `DisplayID`=51414;
UPDATE `creature_model_info` SET `BoundingRadius`=4.419252872467041015, `CombatReach`=3.20000004768371582, `VerifiedBuild`=63834 WHERE `DisplayID`=15275;
UPDATE `creature_model_info` SET `BoundingRadius`=4, `CombatReach`=6, `VerifiedBuild`=63834 WHERE `DisplayID`=71738;
UPDATE `creature_model_info` SET `BoundingRadius`=0.463576048612594604, `VerifiedBuild`=63834 WHERE `DisplayID`=53517;
UPDATE `creature_model_info` SET `BoundingRadius`=0.678850829601287841, `CombatReach`=1.60000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID`=87760;
UPDATE `creature_model_info` SET `BoundingRadius`=1.60000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID` IN (87972, 79380);
UPDATE `creature_model_info` SET `BoundingRadius`=1.158940076828002929, `VerifiedBuild`=63834 WHERE `DisplayID`=52600;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `VerifiedBuild`=63834 WHERE `DisplayID` IN (87182, 30212);
UPDATE `creature_model_info` SET `BoundingRadius`=1.593959927558898925, `CombatReach`=1.125, `VerifiedBuild`=63834 WHERE `DisplayID`=80750;
UPDATE `creature_model_info` SET `BoundingRadius`=0.490500271320343017, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=83522;
UPDATE `creature_model_info` SET `BoundingRadius`=1.10000002384185791, `CombatReach`=1.10000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID`=80391;
UPDATE `creature_model_info` SET `BoundingRadius`=0.901417970657348632, `CombatReach`=0.774999976158142089, `VerifiedBuild`=63834 WHERE `DisplayID`=70945;
UPDATE `creature_model_info` SET `BoundingRadius`=0.909640252590179443, `VerifiedBuild`=63834 WHERE `DisplayID`=70258;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277777612209320068, `CombatReach`=1.20000004768371582, `VerifiedBuild`=63834 WHERE `DisplayID`=70164;
UPDATE `creature_model_info` SET `BoundingRadius`=1.329424977302551269, `CombatReach`=1.60000002384185791, `VerifiedBuild`=63834 WHERE `DisplayID`=81269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.207999989390373229, `CombatReach`=1.5, `VerifiedBuild`=63834 WHERE `DisplayID`=87079;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1, `VerifiedBuild`=63834 WHERE `DisplayID`=70111;
UPDATE `creature_model_info` SET `BoundingRadius`=0.773123979568481445, `VerifiedBuild`=63834 WHERE `DisplayID`=65892;
UPDATE `creature_model_info` SET `BoundingRadius`=0.42790001630783081, `CombatReach`=1.65000009536743164, `VerifiedBuild`=63834 WHERE `DisplayID` IN (72568, 72544, 72580);
UPDATE `creature_model_info` SET `BoundingRadius`=0.722000002861022949, `CombatReach`=3, `DisplayID_Other_Gender`=0, `VerifiedBuild`=63834 WHERE `DisplayID`=15342;
UPDATE `creature_model_info` SET `BoundingRadius`=1.597905278205871582, `CombatReach`=2.25, `VerifiedBuild`=63834 WHERE `DisplayID`=88565;
UPDATE `creature_model_info` SET `BoundingRadius`=12.43618392944335937, `CombatReach`=7.959183216094970703, `VerifiedBuild`=63834 WHERE `DisplayID`=62707;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=63834 WHERE `DisplayID`=60964;
UPDATE `creature_model_info` SET `BoundingRadius`=1.169553518295288085, `VerifiedBuild`=63834 WHERE `DisplayID`=65597;
UPDATE `creature_model_info` SET `BoundingRadius`=0.314999997615814208, `CombatReach`=1.349999904632568359, `VerifiedBuild`=63834 WHERE `DisplayID` IN (69757, 43763);
UPDATE `creature_model_info` SET `BoundingRadius`=0.287755131721496582, `VerifiedBuild`=63834 WHERE `DisplayID`=42412;
UPDATE `creature_model_info` SET `BoundingRadius`=0.358935773372650146, `VerifiedBuild`=63834 WHERE `DisplayID`=64045;
UPDATE `creature_model_info` SET `BoundingRadius`=0.200000002980232238, `CombatReach`=2, `VerifiedBuild`=63834 WHERE `DisplayID`=72110;
UPDATE `creature_model_info` SET `BoundingRadius`=0.060000002384185791, `CombatReach`=0.300000011920928955, `VerifiedBuild`=63834 WHERE `DisplayID`=72111;
UPDATE `creature_model_info` SET `BoundingRadius`=0.542188048362731933, `CombatReach`=0.75, `VerifiedBuild`=63834 WHERE `DisplayID`=80804;
UPDATE `creature_model_info` SET `BoundingRadius`=0.430722951889038085, `VerifiedBuild`=63834 WHERE `DisplayID`=106239;

UPDATE `quest_objectives` SET `VerifiedBuild`=63660 WHERE `ID`=293581; -- 293581
UPDATE `quest_objectives` SET `VerifiedBuild`=63660 WHERE `ID`=289061; -- 289061

DELETE FROM `gameobject_template` WHERE `entry` IN (403998 /*Doodad_MonestaryBossDoor01*/, 403983 /*Graveyard Door*/, 403984 /*Doodad_MonestarySecretDoor01*/, 404000 /*Doodad_ScarletCathedralDoor01*/, 531131 /*Portal to the Infinite Bazaar*/, 532266 /*Temporal Knot*/, 529680 /*Infinite Bronze*/, 527832 /*Anchoring Materials*/, 529686 /*Fibers and Threads*/, 529678 /*Infusing Crystals*/, 529397 /*Curio Lockbox*/, 529396 /*Weapon Crate*/, 527833 /*Archeology Chest*/, 529651 /*Forge*/, 539217 /*Magical Barrier*/, 268755 /*Hunter's Feast*/, 527836 /*Magical Barrier*/, 554969 /*Bronze Barrier*/, 539069 /*Invisible Collision*/, 539205 /*Invisible Collision*/, 539072 /*Invisible Collision*/, 529213 /*Magical Barrier*/, 566784 /*Legion Portal*/, 539071 /*Invisible Collision*/, 529211 /*Magical Barrier*/, 276451 /*Fire*/, 554972 /*Barrier*/, 250894 /*Training Troops*/, 250965 /*Campfire*/, 252166 /*The Hunter's Guide to Being Useful*/, 250896 /*Training Troops*/, 252009 /*Projector*/, 250976 /*Cookpot*/, 250895 /*Training Troops*/, 246673 /*Shield*/, 266165 /*Mana Pylon*/, 266164 /*Mana Pylon*/, 266163 /*Mana Pylon*/, 266162 /*Mana Pylon*/, 250443 /*Zim'Abwa*/, 250444 /*Wanted!*/, 364897 /*Gunship Portal*/, 364898 /*Alliance Gunship Portal Effects*/, 322765 /*Rowboat*/, 322768 /*Captain's Helm*/, 322766 /*Rigging*/, 322708 /*Rowboat*/, 322698 /*[DNT] Covered Log Pile 03*/, 322697 /*[DNT] Covered Log Pile 01*/, 322694 /*Fog Ward*/, 320955 /*Kul Tiran Flagship*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `RequiredLevel`, `ContentTuningId`, `VerifiedBuild`) VALUES
(403998, 0, 443, 'Doodad_MonestaryBossDoor01', '', '', '', 0.999999582767486572, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Doodad_MonestaryBossDoor01
(403983, 0, 6628, 'Graveyard Door', '', '', '', 0.49551895260810852, 0, 5705968, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Graveyard Door
(403984, 0, 441, 'Doodad_MonestarySecretDoor01', '', '', '', 0.999999463558197021, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Doodad_MonestarySecretDoor01
(404000, 0, 1207, 'Doodad_ScarletCathedralDoor01', '', '', '', 0.999999821186065673, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Doodad_ScarletCathedralDoor01
(531131, 22, 76125, 'Portal to the Infinite Bazaar', 'questinteract', '', '', 1, 1231368, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Portal to the Infinite Bazaar
(532266, 22, 76125, 'Temporal Knot', 'questinteract', '', '', 1, 1232595, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Temporal Knot
(529680, 10, 450, 'Infinite Bronze', 'questinteract', 'Forging', '', 0.25, 4075, 89409, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 289586, 0, 0, 0, 0, 0, 1, 0, 139159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Infinite Bronze
(527832, 10, 68160, 'Anchoring Materials', 'questinteract', '', '', 0.25, 4074, 89409, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 139157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Anchoring Materials
(529686, 10, 71301, 'Fibers and Threads', 'questinteract', 'Separating', '', 0.25, 4072, 89409, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 289584, 0, 0, 0, 0, 0, 1, 0, 139156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Fibers and Threads
(529678, 10, 104406, 'Infusing Crystals', '', '', '', 0.25, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Infusing Crystals
(529397, 3, 88504, 'Curio Lockbox', 'questinteract', 'Rummaging.', '', 1, 4077, 0, 1, 0, 1, 1, 0, 0, 89407, 0, 0, 0, 0, 0, 289894, 0, 0, 139082, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 133371, 0, 0, 0, 0, 10, 3382, 63660), -- Curio Lockbox
(529396, 3, 32553, 'Weapon Crate', 'questinteract', 'Rummaging.', '', 1, 4077, 0, 1, 0, 1, 1, 0, 0, 89407, 0, 0, 0, 0, 0, 289894, 0, 0, 139079, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 133373, 0, 0, 0, 0, 10, 3382, 63660), -- Weapon Crate
(527833, 3, 15578, 'Archeology Chest', 'questinteract', 'Rummaging.', '', 1, 4077, 0, 1, 0, 1, 1, 0, 0, 89407, 0, 0, 0, 0, 0, 289894, 0, 0, 139081, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 133374, 0, 0, 0, 0, 10, 3382, 63660), -- Archeology Chest
(529651, 10, 32610, 'Forge', 'questinteract', 'Heating', '', 1.20000004768371582, 4071, 89409, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 289583, 0, 0, 0, 0, 0, 1, 0, 138974, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Forge
(539217, 5, 103436, 'Magical Barrier', '', '', '', 0.649999976158142089, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Magical Barrier
(268755, 10, 41465, 'Hunter\'s Feast', '', '', '', 0.5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 238551, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 344, 63660), -- Hunter's Feast
(527836, 5, 103436, 'Magical Barrier', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Magical Barrier
(554969, 0, 6391, 'Bronze Barrier', '', '', '', 3, 0, 0, 1, 0, 0, 0, 0, 21439, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Bronze Barrier
(539069, 0, 6391, 'Invisible Collision', '', '', '', 3, 0, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Invisible Collision
(539205, 0, 6391, 'Invisible Collision', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Invisible Collision
(539072, 0, 6391, 'Invisible Collision', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Invisible Collision
(529213, 5, 103436, 'Magical Barrier', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Magical Barrier
(566784, 5, 111107, 'Legion Portal', '', '', '', 0.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Legion Portal
(539071, 0, 6391, 'Invisible Collision', '', '', '', 1.5, 0, 0, 0, 0, 0, 0, 0, 5793, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Invisible Collision
(529211, 5, 103436, 'Magical Barrier', '', '', '', 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Magical Barrier
(276451, 5, 24564, 'Fire', '', '', '', 0.25, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Fire
(554972, 0, 7299, 'Barrier', '', '', '', 3, 0, 0, 1, 0, 0, 0, 0, 21439, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Barrier
(250894, 45, 9510, 'Training Troops', '', '', '', 1, 143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 339, 63834), -- Training Troops
(250965, 8, 16847, 'Campfire', '', '', '', 1.019999980926513671, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Campfire
(252166, 9, 18715, 'The Hunter\'s Guide to Being Useful', '', '', '', 0.5, 5331, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 339, 63834), -- The Hunter's Guide to Being Useful
(250896, 45, 9510, 'Training Troops', '', '', '', 1, 228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 339, 63834), -- Training Troops
(252009, 5, 29574, 'Projector', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Projector
(250976, 8, 32263, 'Cookpot', '', '', '', 0.529999971389770507, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Cookpot
(250895, 45, 9510, 'Training Troops', '', '', '', 1, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 339, 63834), -- Training Troops
(246673, 5, 19872, 'Shield', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 347, 63834), -- Shield
(266165, 5, 26475, 'Mana Pylon', 'questinteract', '', '', 1.20000004768371582, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mana Pylon
(266164, 5, 26475, 'Mana Pylon', 'questinteract', '', '', 1.20000004768371582, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mana Pylon
(266163, 5, 26475, 'Mana Pylon', 'questinteract', '', '', 1.20000004768371582, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mana Pylon
(266162, 5, 26475, 'Mana Pylon', 'questinteract', '', '', 1.20000004768371582, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63834), -- Mana Pylon
(250443, 2, 7936, 'Zim\'Abwa', '', '', '', 1.740000009536743164, 0, 9021, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 48, 63834), -- Zim'Abwa
(250444, 2, 3053, 'Wanted!', '', '', '', 1, 1634, 9155, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 48, 63834), -- Wanted!
(364897, 22, 9086, 'Gunship Portal', '', '', '', 1, 346250, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1207, 63704), -- Gunship Portal
(364898, 1, 9089, 'Alliance Gunship Portal Effects', '', '', '', 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63704), -- Alliance Gunship Portal Effects
(322765, 10, 44134, 'Rowboat', 'questinteract', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 292833, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 68215, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 674, 63660), -- Rowboat
(322768, 10, 55430, 'Captain\'s Helm', 'questinteract', 'Setting Sail', '', 1.5, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 289979, 0, 0, 0, 171382, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 674, 63660), -- Captain's Helm
(322766, 10, 55428, 'Rigging', 'questinteract', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 292833, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 68215, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 674, 63660), -- Rigging
(322708, 10, 44134, 'Rowboat', 'questinteract', '', '', 1, 1634, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 289960, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 674, 63660), -- Rowboat
(322698, 5, 55401, '[DNT] Covered Log Pile 03', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- [DNT] Covered Log Pile 03
(322697, 5, 55399, '[DNT] Covered Log Pile 01', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- [DNT] Covered Log Pile 01
(322694, 5, 50437, 'Fog Ward', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660), -- Fog Ward
(320955, 43, 54186, 'Kul Tiran Flagship', '', '', '', 1, 1926, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63660); -- Kul Tiran Flagship

UPDATE `gameobject_template` SET `VerifiedBuild`=63834 WHERE `entry` IN (186328, 186327, 186269, 181191, 214508, 253171, 253170, 266294, 254132, 254130, 243795, 245392, 245391, 267403, 267404, 260302, 251545, 249968, 251538, 250974, 258066, 258065, 251544, 249966, 249967, 251542, 251546, 251543, 239743, 258954, 251351, 253538, 247338, 375181, 253540, 253539, 253550, 241859, 239970, 255795, 253564, 253552, 253551, 253548, 239987, 245572, 245573, 245574, 239959, 245057, 258067, 254063, 251681, 248587, 245229, 243877, 243876, 243875, 245228, 246992, 246993, 246999, 246998, 247385, 247002, 246996, 246990, 246997, 247005, 247544, 193615, 193611, 246994, 246995, 247000, 246040, 190014, 190016, 190015, 191201, 188251, 188250, 188249, 188248, 188247, 188246, 188245, 188517, 188516, 188515, 188428, 192588, 188136, 191276, 189991, 191277, 191329, 192717, 191278, 247070);
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=186314; -- Loosely Turned Soil
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (246486, 246485); -- Spire of Woe
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=246401; -- Doodad_7LG_Legion_Portal002
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (244692, 244694, 246309); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=242326; -- Ley Portal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=243993; -- Gate of the Candleking
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (250541, 245548, 250102, 265526); -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63796 WHERE `entry`=243802; -- Powered Console
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (244913, 265526, 245528, 245524, 250541, 245550, 241152, 245548); -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (247017, 247016); -- Drogbar Weight
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=246807; -- EXIT
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=247695; -- Elementium Slats
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (251031, 251125, 250978, 250994); -- Highmountain Brazier
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry` IN (250996, 251217, 250979, 250916, 250998); -- Highmountain Brazier
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63796 WHERE `entry` IN (250995, 251000); -- Spirit Journey Borders
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=245054; -- Hammer of Khaz'goroth
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (245601, 242667, 242663, 245534, 245535, 244909, 251780); -- Small Treasure Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=63796 WHERE `entry` IN (245229, 243877, 243876, 243875, 245228, 245057, 244816, 260310, 215168, 215170, 248587, 260302, 251545, 249968, 251544, 251538, 250974, 249966, 249967, 251542, 251546, 251543, 260309, 266294, 250962, 250961, 250954, 250953, 250956, 250952, 250955, 250960, 250959, 250958, 250957, 250948, 250946, 250943, 250928, 250945, 250944, 250939, 250938, 250929, 250977, 250947, 250942, 250941, 250927, 250930, 268698, 268697, 250966, 250951, 250950, 250926, 250917, 299273, 258067, 258066, 258065, 267404, 244785);
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (245059, 245058); -- Titan Waygate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=250905; -- Small Ceremonial Drum
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=250904; -- Medium Ceremonial Drum
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=250903; -- Large Ceremonial Drum
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=245400; -- Emerald Dream Portal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=247876; -- The Skyhorn
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=243698; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=245620; -- Mu'sha's Tears
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=245621; -- Bottle of Airspark
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=246716; -- Hammer FX
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245602; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245543; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243639; -- Siphoning Crystal
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63796 WHERE `entry`=247106; -- Drogbar Idol
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=245530; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63796 WHERE `entry`=247105; -- Drogbar Netting
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=61691, `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63796 WHERE `entry`=243712; -- Fishing Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (248597, 248770); -- Cooking Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (246256, 244430); -- Collision Wall
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=266304; -- Arcane Disk
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=243993; -- Gate of the Candleking
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=243368; -- Wooden Barricade
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=252838; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=45, `ContentTuningId`=335, `VerifiedBuild`=63796 WHERE `entry`=252432; -- Shimmering Ancient Mana Cluster
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry`=251300; -- Bramble Wall
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (243318, 243317, 243319, 243316); -- Prison Gate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry`=241638; -- Stareye's Orders
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=242449; -- Barrel of Corn
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=241639; -- Warden's Glaive
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry`=248534; -- Tears of Elune
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=250554; -- Zeppelin
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=252239; -- Shipwreck Debris
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (244913, 241152, 241280); -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (244909, 250987, 233107, 251713, 251780, 251792, 241206); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry` IN (251008, 258850, 258849, 258851); -- Ancient Dreyrgrot Tablet
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=251007; -- Crate of Ancient Relics
UPDATE `gameobject_template` SET `VerifiedBuild`=63704 WHERE `entry` IN (242572, 244483, 241686, 241833, 241832, 259816, 241783, 241774, 241771, 241688, 241729, 259815, 241755, 241693, 241683, 240604, 241779, 244587, 241782, 241763, 244866, 244864, 244863, 244862, 244861, 244860, 243835, 244479, 242517, 242486, 242483, 242243, 240285, 240284, 241630, 256939, 239959, 245573, 245574, 245572, 246569, 193019, 176574, 37118, 176464, 22738, 22753, 22743, 22712, 22710, 22709, 22749, 22748, 22747, 22746, 22745, 22707, 22580, 22579, 22578, 170001, 22750, 22737, 22735, 22733, 22732, 22588, 22587, 22582, 22581, 22567, 22566, 22565, 22564, 22563, 22534, 22533, 22531, 22530, 3798, 3797, 22742, 22740, 22739, 22752, 22711, 22708, 20689, 18090, 32107, 18089, 177256, 177255, 221526, 177254, 247070, 180684, 195218, 177273, 195219, 177278, 259438, 176559, 176560, 201520, 201516, 200314, 200313, 200312, 200308, 200307, 200306, 200315, 200310, 201647, 201645, 201644, 201643, 201642, 201657, 201655, 201661, 201641, 201665, 201654, 201662, 201663, 201822, 201652, 201648, 201649, 201653, 201664, 201656, 201646, 201660, 201658, 201671, 201669, 201659, 201670, 201843, 259880, 201651, 201668, 201667, 201666, 201650, 3800, 3799, 201690, 201689, 201688, 201685, 201677, 201692, 201687, 201682, 201678, 201675, 201672, 201694, 201693, 201691, 201686, 201684, 201683, 201681, 201680, 201679, 201676, 201674, 201673, 200311, 200309, 201445, 201420, 201419, 201418, 201416, 201415, 206560, 201453, 201452, 201451, 201450, 201449, 201448, 201447, 201446, 201544, 201543, 201536, 201535, 201534, 201533, 201532, 201531, 201530, 201529, 201528, 201527, 201542, 201540, 201539, 201537, 201526, 201525, 201524, 201560, 201559, 201558, 201557, 201556, 201555, 201553, 201552, 201551, 201541, 201538, 201519, 201518, 201515, 201502, 201499, 201554, 201550, 201549, 201548, 201547, 201546, 201545, 201521, 201510, 201507, 201505, 201504, 201498, 201422, 201523, 201522, 201512, 201501, 201497, 201496, 201495, 201488, 201509, 201508, 201506, 201503, 201494, 201493, 201492, 201491, 201490, 201489, 201511, 201500, 202009, 202007, 206623, 202008, 202031, 202029, 202022, 202017, 202016, 202015, 202012, 254234, 242549, 254275, 255203, 251604, 254017, 254252, 254016, 254251, 251513, 254250, 254018, 240211, 240214, 254015, 254124, 258322, 258321, 258320, 258319, 258287, 258277, 258276, 258275, 258234, 258233, 175741, 175727, 175724, 258308, 258312, 258318, 258313, 258309, 258281, 258310, 258317, 258315, 175740, 258305, 258307, 258304, 258283, 258282, 258316, 258306, 258284, 202018, 202036, 202013, 202014, 202021, 202030, 202019, 202020, 202033, 202032, 202034, 201980, 202035, 201981, 202028, 202027, 202026, 202025, 202024, 202023, 201514, 201513, 197143, 197175, 197122, 197174, 197188, 197137, 197124, 197172, 197145, 197121, 197149, 197117, 197142, 197132, 197146, 197139, 197173, 197148, 197187, 197131, 197116, 197147, 197135, 205106, 197189, 197133, 197150, 197120, 197118, 205107, 197190);
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=244903; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251571; -- Ashilvara, Verse 1
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=244565; -- Kvaldir Spoils
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=244559; -- Helya's Altar
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=267952; -- Stolen Crate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=240603; -- Cursed Seaweed
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=241267; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=240586; -- Cursed Bones
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=241216; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=241778; -- Colborn's Cage
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=241272; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63704 WHERE `entry`=240649; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry` IN (241872, 241874, 241873, 241871, 241870); -- Ashildir's Bones
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=241866; -- Soulthorn
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=250574; -- Bedroll
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (250573, 250564, 250563, 250561); -- Baskets
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=250571; -- Sled
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=250567; -- Bow
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=250566; -- Hides
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63704 WHERE `entry`=268408; -- Thorim's Flame
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (240650, 244337, 244336, 244335); -- Ritual Circle
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=241279; -- Intact Thorignir Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=240681; -- Oiled Cloak
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=240677; -- Climbing Treads
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=243802; -- Powered Console
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=243836; -- Yotnar's Head
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=243820; -- Yotnar's Right Arm
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=243823; -- Yotnar's  Left Foot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=243822; -- Yotnar's Right Foot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=240286; -- Crystal Oscillator
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=241275; -- Skyfire Medical Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=242380; -- Volatile Flare
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=240210; -- Skyfire Parachute
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=244823; -- The Skyfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=252142; -- Backpack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=244567; -- Portal to The Skyfire
UPDATE `gameobject_template` SET `VerifiedBuild`=63660 WHERE `entry` IN (197124, 201523, 201506, 201508, 201509, 201522, 201513, 201512, 201503, 201500, 201511, 201422, 452030, 281864, 278329, 227909, 227908, 227907, 227906, 278333, 278332, 278331, 278330, 278328, 278327, 278326, 278325, 278324, 278310, 205105, 205104, 201446, 204988, 204987, 201485, 201484, 201483, 201482, 201481, 201480, 201479, 201478, 201477, 201476, 201475, 201474, 201463, 201462, 201461, 201453, 201452, 201451, 201450, 201449, 201448, 201447, 201445, 206560, 203976, 202274, 202273, 202272, 202271, 202270, 202267, 201419, 201416, 201415, 201496, 201495, 201494, 201493, 201491, 201490, 201489, 201488, 201420, 201418, 201417, 201514, 197133, 197132, 197131, 201492, 197190, 197189, 197188, 197187, 197139, 197137, 197122, 197121, 202028, 202027, 206623, 202026, 202025, 202024, 202023, 202008, 201421, 202032, 202009, 202007, 201460, 201459, 201458, 201457, 201456, 201455, 201454, 202036, 202035, 202034, 202033, 202031, 202030, 202029, 202022, 202021, 202020, 202019, 202018, 202017, 202016, 202015, 202014, 202013, 202012, 201981, 201980, 297574, 297573, 297572, 297571, 297570, 297569, 297568, 297567, 297566, 297565, 297564, 297563, 297562, 258320, 258233, 258321, 258322, 258319, 258287, 258284, 258283, 258282, 258281, 258277, 258276, 258275, 258234, 175741, 175740, 175727, 175724, 258318, 258317, 258316, 258315, 258313, 258312, 258310, 258309, 258308, 258307, 258306, 258305, 258304, 170351, 170350, 170349, 170348, 170347, 22638, 22623, 22622, 22606, 22605, 22604, 22603, 22602, 22776, 177504, 177503, 177502, 177501, 177500, 177499, 177498, 177497, 177496, 177495, 177494, 142075, 22813, 22812, 22811, 22806, 22804, 22803, 22783, 22777, 22775, 22774, 22773, 22772, 4087, 123244, 4090, 4089, 4088, 22535, 170073, 22538, 3799, 204796, 22537, 3800, 22536, 197144, 197141, 197145, 197143, 197142, 197175, 197174, 197173, 197172, 197147, 197146, 197120, 197118, 197117, 197116, 197149, 197148, 205107, 205106, 197150, 197135, 195257, 195273, 195266, 195253, 195256, 195259, 367950, 209125, 259438, 278907, 278855, 278773, 293498, 294893, 294892, 290440, 281638, 293775, 290974, 293759, 209116, 195264, 195260, 195263, 195254, 195255, 284465, 282469, 284464, 291210, 282470, 282468, 302840, 295320, 295196, 295197, 295188, 295190, 278527, 303031, 303030, 303029, 278539, 278538, 303070, 303069, 303068, 295337, 295334, 295333, 295327, 295348, 295338, 279694, 303159, 303158, 279695, 303138, 303137, 295347, 295346, 295343, 295342, 295330, 295328, 295341, 295340, 295339, 295336, 295332, 295329, 295345, 295344, 295335, 278919, 301053, 295474, 295484, 294727, 294734, 301045, 301042, 301044, 294400, 301043, 301052, 301051, 301050, 299319, 299318, 299317, 299316, 299315, 299309, 299308, 299307, 299306, 296949, 294382, 294375, 294374, 299312, 299311, 297784, 297724, 294383, 299320, 299310, 296952, 294379, 294377, 294376, 297278, 297277, 297268, 297249, 297234, 297233, 297229, 297192, 297177, 294389, 294274, 294263, 294262, 294261, 294260, 294256, 294254, 294395, 294258, 294255, 294403, 294259, 294265, 294266, 297178, 294257, 294264, 294267, 294268, 294272, 294273, 297176, 297179, 294392, 297197, 294393, 294391, 297167, 297252, 297232, 297250, 297236, 297231, 297240, 297273, 297215, 294462, 294463, 294464, 294465, 297214, 297228, 297283, 298987, 297263, 297163, 298984, 298983, 297275, 298985, 298986, 298988, 297257, 297173, 297224, 297160, 295022, 294807, 295025, 295024, 295023, 294905, 294973, 294963, 294954, 294951, 294949, 294898, 294891, 294890, 294889, 294888, 294887, 294275, 295414, 321797, 321795, 321760, 239174, 288469, 288433, 239179, 239178, 316427, 294899, 316429, 294897, 294896, 294952, 294950, 292870, 292871, 292872, 296460, 296478, 302940, 302949, 302948, 302947, 302946, 302945, 302944, 302942, 302941, 299253, 299252, 299251, 295409, 295364, 295363, 295362, 295357, 294900, 281065, 299250, 299344, 295358, 295361, 295360, 302950, 299255, 299254, 298980, 299256, 292869, 188215, 301131, 301130, 301129, 299265, 299264, 299263, 295481, 295469, 295411, 299343, 299262, 299261, 295432, 294546, 294545, 294544, 294543, 229465, 302858, 302857, 282465, 280662, 294856, 294857, 369893, 301135, 301127, 299342, 299260, 299259, 299258, 299257, 297145, 296155, 294976, 294974, 294975, 299322, 294953, 294948, 298883, 298881, 298882, 298884, 298885, 298886, 303049, 365064, 323531, 295417, 295408, 365067, 365068, 365065, 365066, 365069, 302790, 302791, 365070, 303146, 365071, 295018, 294998, 295419, 301128, 295420, 294999, 295019, 295399, 295398, 321754, 321720, 301134, 321753, 321724, 321734, 321733, 321719, 321721, 321732, 321755, 290675, 321735, 321725, 321718, 317398, 312156, 295012, 294901, 303042, 295400, 294956, 292695, 303056, 303053, 303047, 303045, 303043, 303041, 295161, 295160, 295159, 295158, 295157, 295156, 295155, 294955, 281095, 295732, 295722, 295734, 295723, 295733, 295721, 303057, 295728, 295725, 295726, 295724, 295730, 295731, 303060, 295729, 295727, 303040, 295013, 295122, 295124, 295123, 299285, 299284, 299283, 299280, 297169, 295468, 295001, 295000, 294940, 294938, 294840, 294390, 294369, 303066, 295154, 295153, 295151, 295148, 295147, 295146, 295143, 295141, 295149, 295142, 295152, 295150, 295144, 295145, 303065, 295520, 295519, 295518, 295517, 303077, 303076, 294805, 294743, 294723, 294402, 303075, 303143, 303142, 303074, 303051, 303044, 299314, 299313, 298873, 294724, 294397, 294396, 321747, 303127, 303125, 303122, 303121, 303064, 303063, 303128, 303126, 303054, 303050, 303048, 294860, 299282, 299281, 294942, 294859, 294866, 298975, 298969, 298974, 298968, 298976, 298970, 298973, 303062, 298971, 298977, 298972, 295027, 316428, 303073, 303058, 294990, 294879, 294878, 294876, 294875, 294873, 294872, 294871, 297635, 293755, 292915, 269098, 295456, 295453, 295119, 295118, 295117, 295026, 294988, 294987, 294979, 294880, 294877, 294874, 294869, 294867, 294862, 294861, 288632, 213637, 294982, 294808, 295116, 295457, 295079, 295454, 295080, 294943, 294962, 294967, 294958, 295478, 294957, 294964, 295479, 295002, 302797, 302796, 295003, 295109, 302799, 295008, 295010, 302798, 302801, 295108, 295107, 302802, 302800, 302803, 294914, 302792, 294912, 294911, 294915, 302952, 295085, 295418, 302951, 302793, 295011, 301137, 295464, 294972, 302795, 294907, 295475, 294913, 294908, 302794, 294916, 294910, 301136, 295036, 295037, 295043, 295040, 295039, 295038, 294909, 282258, 236184, 294865, 294917, 294882, 294965, 294918, 295029, 294881, 295031, 294966, 295032, 295030, 279593, 294944, 295120, 295121, 335634, 335633, 294971, 295716, 335630, 335631, 335632, 295714, 294997, 294996, 294995, 294994, 294970, 294969, 294968, 295715, 295365, 295016, 295015, 294993, 294992, 294960, 294234, 294233, 294232, 294231, 287123, 282246, 316675, 303012, 303010, 303009, 303003, 303000, 295460, 295114, 295113, 295112, 295111, 295110, 295017, 294978, 294937, 294930, 294904, 294903, 294902, 294847, 294920, 303006, 302999, 303011, 303002, 303013, 303005, 302995, 303004, 294488, 294490, 302994, 294489, 294482, 302998, 294481, 294483, 294485, 294486, 294484, 294493, 294492, 294491, 294487, 303001, 303008, 302996, 294977, 303007, 302997, 294835, 294858, 303084, 294924, 294936, 294961, 294244, 294243, 294242, 294241, 295415, 294906, 295467, 294245, 294240, 295021, 294253, 295401, 294239, 295402, 295717, 295718, 295719, 295720, 294247, 294246, 294248, 294237, 294238, 295020, 295486, 295476, 303085, 295777, 295776, 295775, 295774, 295773, 295772, 295771, 295770, 295769, 295767, 295765, 295764, 295759, 295758, 295755, 295754, 295753, 295487, 295473, 295471, 295462, 301133, 295768, 295766, 295763, 295762, 295761, 295760, 295757, 295756, 295470, 295461, 295028, 294946, 301132, 294927, 295098, 281464, 295097, 295096, 294947, 281609, 295815, 295816, 280586, 294716, 296839, 296838, 296837, 296836, 296835, 296834, 294715, 280546, 295800, 295799, 295798, 296878, 296852, 296849, 296851, 296850, 280648, 280647, 279578, 280587, 282256, 280917, 282255, 280915, 280912, 296847, 296841, 296840, 296739, 296738, 296853, 296842, 296848, 296845, 296844, 296843, 292545, 291132, 279335, 296621, 296620, 296593, 296592, 295814, 295813, 295812, 295811, 295810, 294461, 278506, 296618, 296250, 296249, 296248, 296247, 296246, 296245, 296595, 296594, 296864, 295784, 295783, 295782, 296615, 295805, 296868, 296862, 293202, 294208, 293777, 302804, 294207, 294206, 293778, 280645, 297142, 296854, 291015, 297143, 297709, 291014, 291016, 291017, 316904, 295179, 295178, 293132, 276256, 297132, 292547, 303145, 272201, 272200, 295265, 295264, 295303, 295302, 295301, 295300, 295299, 295298, 295297, 295296, 295263, 295262, 295225, 295224, 295223, 295222, 295212, 295211, 287435, 277514, 295295, 295294, 295293, 295292, 295220, 295216, 295215, 295214, 295213, 295210, 295209, 295208, 295207, 278778, 302839, 280693, 297479, 293406, 279289, 278528, 296901, 296900, 295802, 295801, 290442, 290441, 277420, 272174, 295095, 295094, 295093, 295092, 295091, 295089, 295088, 295087, 278524, 278523, 278475, 271125, 278572, 295090, 295086, 290901, 290453, 290413, 278848, 272199, 272178, 272177, 272176, 277271, 226941, 297628, 316972, 297632, 286966, 294278, 294277, 294276, 294281, 294279, 294289, 294282, 294291, 294287, 294280, 294290, 294283, 294288, 287254, 294470, 278374, 278373, 278372, 294468, 294469, 278371, 294467, 286964, 295132, 295131, 295130, 295129, 295128, 295127, 295126, 295125, 290900, 279316, 295804, 295803, 277331, 277330, 297630, 287329, 276868, 276872, 276645, 276871, 276867, 276403, 297137, 288489, 288491, 288488, 297136, 296271, 276733, 288490, 277596, 277595, 295199, 295198, 295203, 295202, 295290, 295204, 295291, 295194, 295186, 295195, 295193, 295187, 295185, 295253, 295252, 295170, 295164, 295167, 295166, 295169, 295163, 295165, 295168, 295192, 295289, 292913, 279587, 279594, 295189, 295184, 292912, 281014, 279586, 296825, 296824, 296823, 295205, 295191, 295180, 295256, 295255, 295201, 302767, 295318, 295254, 295315, 292873, 295171, 234207, 297937, 278695, 207440, 207453, 302838, 207438, 279319, 279318, 297149, 289357, 289355, 297148, 289358, 296614, 296612, 296613, 296590, 293781, 293780, 295058, 293779, 293782, 295059, 296866, 281892, 281158, 294209, 296861, 296860, 291052, 291051, 291049, 279372, 295781, 295778, 278822, 278424, 295905, 295903, 295904, 294466, 288592, 278425, 296902, 296863, 296229, 296228, 295057, 295052, 295049, 295048, 296865, 295056, 295055, 295054, 295053, 295051, 295050, 287188, 296230, 302766, 284701, 290623, 281703, 287192, 294711, 294714, 294713, 317053, 322681, 277419, 316864, 317058, 317062, 322682, 317047, 317048, 317061, 317060, 317050, 296619, 294712, 296877, 296059);
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=339222; -- Mechagnome
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=316736; -- Kul Tiran
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298865; -- Dark Iron Dwarf
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273855; -- Lightforged Draenei
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273853; -- Void Elf
UPDATE `gameobject_template` SET `RequiredLevel`=1, `VerifiedBuild`=63660 WHERE `entry`=278311; -- Bonfire
UPDATE `gameobject_template` SET `RequiredLevel`=15, `VerifiedBuild`=63660 WHERE `entry`=211319; -- Relief Bucket
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251347; -- Submarine
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251088; -- Rune
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251254; -- Grilled Fish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251251; -- Baked Fowl
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251255; -- Ribs
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251253; -- Fried Rice
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=258301; -- Noodle Cart
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251250; -- Baked Fish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251247; -- Pandaren Barrel 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251252; -- Dumplings
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=258302; -- Bubbling Pot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251246; -- Pandaren Barrel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251241; -- Rug
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251240; -- Draenei Wagon
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251237; -- Draenei Crate 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251236; -- Draenei Crate 1
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (251235, 251234, 251233); -- Light-Infused Crystals
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251232; -- Basket Closed
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251231; -- Basket Empty
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251230; -- Draenei Barrel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251228; -- Draenei Pillow 3
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251227; -- Draenei Pillow 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251226; -- Draenei Pillow 1
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (251224, 251223, 251225); -- Draenei Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251229; -- Draenei Table
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251242; -- Crystal Bucket
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251238; -- Supply Stack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (258255, 258254, 278571); -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251244; -- Draenei Wagon 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (251022, 251021, 251023); -- Medical Supply Crate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (257880, 257881); -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251195; -- Keg of Armor Polish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (259041, 250660); -- Alliance Battleship
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=257879; -- Anvil
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=257878; -- Forge
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=251146; -- 7.0 Pre-Launch - Stormwind - Template
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=348, `VerifiedBuild`=63660 WHERE `entry`=244530; -- Burnt Crates
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63660 WHERE `entry`=246854; -- Dalaran
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63660 WHERE `entry`=259143; -- Dalaran Alchemy Station
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63660 WHERE `entry` IN (254259, 254258); -- Grate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=348, `VerifiedBuild`=63660 WHERE `entry`=244528; -- Burnt Trade Cart
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (245530, 244928); -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=239120; -- Okuna Longtusk's Pack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (240619, 245534, 245535, 244909, 250108, 251780, 245601); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63834 WHERE `entry`=266945; -- Alchemy Table
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=252794; -- Artifact Research Notes
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=245039; -- Tales of the Hunt
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=252185; -- Requisitioned Seal of Fate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=258965; -- Stand
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=258963; -- Rope
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=247539; -- Plaque
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=252005; -- Requisitioned Armaments
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63834 WHERE `entry`=246674; -- Fish Rack
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63834 WHERE `entry`=246683; -- Fish Pile
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=268345; -- Fel Pool
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63834 WHERE `entry`=244875; -- Legion Anvil
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=268232; -- Fel Spike
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=251623; -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244577; -- Felspike 1.5
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244552; -- Incense
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (244551, 244550, 244548); -- Dreamcatcher
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=243402; -- Navarrogg's Cage
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245531; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244553; -- Felspike 1.0
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry` IN (248774, 257983, 249898); -- Cooking Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244625; -- Cup
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244576; -- Felspike 0.5
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63834 WHERE `entry`=251541; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63834 WHERE `entry`=251539; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245536; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=243559; -- Statue of Liftbrul
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=255828; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=243565; -- Drogbar Weight
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245532; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=254291; -- Sleeping Stone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244627; -- Felpool
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry` IN (250916, 250979); -- Highmountain Brazier
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245602; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245543; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63834 WHERE `entry`=248094; -- Touch of Drog-Grog
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=259043; -- Legion Banner 02
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=250560; -- Legion Banner
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=246566; -- Spire of Woe A
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=246567; -- Spire of Woe B
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (244440, 244439, 244441); -- Legion Communicator
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (241757, 241756, 241751); -- Legion Gateway Activator
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (242990, 242987, 242989, 244916); -- Jailer Cage
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=245045; -- Rockslide
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry` IN (244604, 244601); -- Spire Stabilizer
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=243873; -- Legion Portal
UPDATE `gameobject_template` SET `RequiredLevel`=8, `VerifiedBuild`=63834 WHERE `entry`=245170; -- Demon Ward
UPDATE `gameobject_template` SET `Data18`=682, `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=253957; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=249380; -- Legion Communicator
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=250107; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63834 WHERE `entry`=252574; -- Mysterious Pearl
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=252159; -- Timeworn Songflower
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=250361; -- Sabotaged Portal Stabilizer
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=240346; -- Olive Sprig
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=250080; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=249997; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=240638; -- Disputed Treasure
UPDATE `gameobject_template` SET `RequiredLevel`=1, `VerifiedBuild`=63834 WHERE `entry`=2061; -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=250374; -- Draconic Compendium, Volume III
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=250372; -- Courtship Rituals of the Skrog
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=250373; -- Encyclopedia Azsunica (K-M)
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry` IN (251122, 251121, 251118, 251120, 251117, 251113); -- Ancient Highborne Tome
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry` IN (245486, 245484, 245485, 245483, 239341); -- Tidestone Shard
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244850; -- Pile of Herbs
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=250094; -- Runas' Blanket
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63834 WHERE `entry`=249702; -- Stolen Ley Crystals
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=240033; -- Dim Ley Crystal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=251656; -- Damaged Thunderfury
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63834 WHERE `entry`=251784; -- Vile Spirit Converter
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=250448; -- Imp in a Jar
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63834 WHERE `entry`=250375; -- Dimensional Anchor
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=250433; -- Felforge
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=239455; -- Fel Lock
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=251662; -- rock
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=240222; -- Cache of Infernals
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (240075, 240123, 240121, 240122); -- Soul Harvester
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=331, `VerifiedBuild`=63834 WHERE `entry`=240012; -- Soul Gem
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=243562; -- Crate of Khadgar's Whiskers
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=239456; -- Nether Crucible
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (239338, 239332); -- Soul Gem
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=250087; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=239692; -- Arcane-infused Egg
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63834 WHERE `entry`=249786; -- Leyworm Tunnel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=240267; -- Cracked Ley Crystal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=251643; -- Felblaze Portal Effect
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245543; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245602; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (250978, 251125, 251031, 250994); -- Highmountain Brazier
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (245058, 245059); -- Titan Waygate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=253998; -- Free lootz ahead.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=253997; -- Adventurers this way.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=246461; -- Greystone Enclave
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=248784; -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=268759; -- Firmament Stone in Highmountain
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=254125; -- Firmament Stone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=241635; -- Large Metal Scrap
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=241634; -- Medium Metal Scrap
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=241633; -- Small Metal Scrap
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (244336, 244337); -- Ritual Circle
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=247876; -- The Skyhorn
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245554; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=245357; -- Candleking's Special Candle
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=244430; -- Collision Wall
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=243465; -- Dusty Boot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=253996; -- Definitely not a trap.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=253995; -- If Rich, Please Take
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry`=253994; -- Seemingly Unguarded Treasure
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63834 WHERE `entry`=243698; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry` IN (244841, 244419); -- Eagle Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=243465; -- Dusty Boot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=193978; -- Cask of Peaked Dalaran Red
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63796 WHERE `entry`=251539; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245536; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63796 WHERE `entry`=251541; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=255828; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (244550, 244551, 244548); -- Dreamcatcher
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=243402; -- Navarrogg's Cage
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244553; -- Felspike 1.0
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245532; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=254291; -- Sleeping Stone
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245533; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=248774; -- Cooking Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244625; -- Cup
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244576; -- Felspike 0.5
UPDATE `gameobject_template` SET `Data0`=99, `Data3`=0, `Data6`=0, `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243401; -- Harpy Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244627; -- Felpool
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245554; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=245357; -- Candleking's Special Candle
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245554; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245543; -- Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry` IN (240650, 244335, 244337, 244336); -- Ritual Circle
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=268408; -- Thorim's Flame
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=241279; -- Intact Thorignir Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry`=246578; -- Nightmare Roots
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=248416; -- Shadowfen Heirlooms
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry` IN (243954, 243952, 243953); -- Twisted Root
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63796 WHERE `entry`=241682; -- Dry Harpy Nest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=242279; -- Bramble Wall
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=242275; -- Nightmare Totem
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251643; -- Felblaze Portal Effect
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=254086; -- Glaive
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=243297; -- Scroll
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=254081; -- Weapon Rack
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=254080; -- Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry` IN (254084, 254085); -- Satchel
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=254082; -- Table
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=243305; -- Book
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63704 WHERE `entry`=253168; -- Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63704 WHERE `entry`=250610; -- Target
UPDATE `gameobject_template` SET `RequiredLevel`=1, `VerifiedBuild`=63704 WHERE `entry`=186812; -- Refreshment Table
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=250548; -- Hammer of Khaz'goroth
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245602; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63834 WHERE `entry`=245543; -- Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=66197, `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=250386; -- Fangs of Ashamane
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=250824; -- Platform
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry` IN (250641, 250638); -- Ruined Switch
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry` IN (250639, 250640); -- Orb Light
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry` IN (250632, 250876); -- Door
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=249494; -- Legion Gate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=250643; -- Fog
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=249733; -- Plasmatic Laser Bolt
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63834 WHERE `entry` IN (249414, 249405); -- Energetic Shard
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=247695; -- Elementium Slats
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=246807; -- EXIT
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=65797, `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248853; -- Claws of Ursoc
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248823; -- Ancient Barrier
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=624, `VerifiedBuild`=63834 WHERE `entry` IN (253172, 253173); -- Door
UPDATE `gameobject_template` SET `RequiredLevel`=15, `ContentTuningId`=47, `VerifiedBuild`=63834 WHERE `entry`=253174; -- Portal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248827; -- Cylinder Collision
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry` IN (248824, 248825); -- Stone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248400; -- Bowl
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=248399; -- Fish Bones
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248376; -- Spell Focus
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248066; -- Stone Monolith
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63834 WHERE `entry`=190535; -- Zim'Abwa
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=248779; -- PLACEHOLDER Tree
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=248778; -- Dreamway Portal
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63834 WHERE `entry`=190602; -- Zim'Torga
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (248057, 248056); -- Bear Totem
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=247069; -- Nightmare Thorns
UPDATE `gameobject_template` SET `RequiredLevel`=70, `VerifiedBuild`=63834 WHERE `entry`=388904; -- Ancient Ebon Spear
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63834 WHERE `entry`=248583; -- Flask of Moonwell Water
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63834 WHERE `entry` IN (251947, 251870); -- The Sixtriggers' Premium Stash
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=250566; -- Hides
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=251877; -- Vrykul Weapon Rack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63834 WHERE `entry`=251872; -- Crate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63834 WHERE `entry` IN (251868, 251869); -- Gold Pile
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=334, `VerifiedBuild`=63834 WHERE `entry`=251871; -- Crates
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry` IN (250573, 250564, 250563, 250561); -- Baskets
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63834 WHERE `entry`=250571; -- Sled
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63834 WHERE `entry` IN (244463, 244460); -- Shard Caller Idol
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=253998; -- Free lootz ahead.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=253997; -- Adventurers this way.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=253996; -- Definitely not a trap.
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=253995; -- If Rich, Please Take
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=253994; -- Seemingly Unguarded Treasure
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=266945; -- Alchemy Table
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=250866; -- Parachute
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=251215; -- Conjured Fel Chili
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=246852; -- Soul Spike
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63796 WHERE `entry`=246384; -- Serpent Idol
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63796 WHERE `entry`=250975; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=63796 WHERE `entry`=250967; -- Forge
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63796 WHERE `entry`=267067; -- Uncharged Totem
UPDATE `gameobject_template` SET `RequiredLevel`=45, `ContentTuningId`=347, `VerifiedBuild`=63796 WHERE `entry`=248401; -- Shipwrecked Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=245350; -- Shipwrecked Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243973; -- Rod of Bearing
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243972; -- Wheel of Fortitude
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243971; -- Chains of Resistance
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry` IN (247811, 247810, 247809); -- Tink Rock
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry` IN (247800, 247799, 247798); -- Bop Rock
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry` IN (247785, 247784, 247780); -- Clomp Rock
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=255829; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=250263; -- Weapon Rack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243559; -- Statue of Liftbrul
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=243565; -- Drogbar Weight
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245532; -- Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=255828; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63796 WHERE `entry`=251541; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=268345; -- Fel Pool
UPDATE `gameobject_template` SET `RequiredLevel`=5, `VerifiedBuild`=63796 WHERE `entry`=244875; -- Legion Anvil
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=268232; -- Fel Spike
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245531; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63796 WHERE `entry`=251623; -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244577; -- Felspike 1.5
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63796 WHERE `entry`=244552; -- Incense
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=333, `VerifiedBuild`=63796 WHERE `entry`=250413; -- Oren's Prized Possessions
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=63796 WHERE `entry`=251539; -- Blacksmith's Anvil
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245536; -- Glimmering Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245554; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=245554; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data12`=682, `RequiredLevel`=10, `ContentTuningId`=682, `VerifiedBuild`=63796 WHERE `entry`=253993; -- Crusty Kvaldir Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=242279; -- Bramble Wall
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=242275; -- Nightmare Totem
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63704 WHERE `entry`=243776; -- Dust Bunny
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63704 WHERE `entry` IN (251419, 251425); -- Moist Grizzlecomb
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63704 WHERE `entry`=251434; -- Snarled Bramble
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=332, `VerifiedBuild`=63704 WHERE `entry`=241133; -- Raw Meat
UPDATE `gameobject_template` SET `Data1`=0, `Data3`=1, `Data26`=0, `Data30`=64246, `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry`=246437; -- The Scythe of Elune
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry`=252770; -- Base
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry`=246436; -- The Scythe of Elune
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry` IN (245969, 246034, 247322); -- Portcullis
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry`=245793; -- Battered Journal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=339, `VerifiedBuild`=63704 WHERE `entry`=245789; -- Battered Journal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=245785; -- Compass
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=245786; -- Relic Box
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=245788; -- Fur Blanket
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=245787; -- Fine Boots
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=22706; -- Faustin's Alchemy Set
UPDATE `gameobject_template` SET `RequiredLevel`=1, `VerifiedBuild`=63704 WHERE `entry`=321; -- Tear of Tilloa
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=247862; -- Door
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (247069, 250363); -- Nightmare Thorns
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (247053, 251241); -- Rug
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=246960; -- Fish Pile
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63704 WHERE `entry`=246683; -- Fish Pile
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63704 WHERE `entry`=272487; -- Oddly-Colored Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=247042; -- Zen'tabra Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=247040; -- Zen'tabra's Tent
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=247045; -- Zen'tabra's Moss Bed
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=247052; -- Pillow
UPDATE `gameobject_template` SET `RequiredLevel`=45, `VerifiedBuild`=63704 WHERE `entry`=272434; -- Water Stone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=259143; -- Dalaran Alchemy Station
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry` IN (254258, 254259); -- Grate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=246854; -- Dalaran
UPDATE `gameobject_template` SET `IconName`='questinteract', `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=246706; -- Demon Portal
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=2657; -- Legends of the Earth
UPDATE `gameobject_template` SET `type`=0, `Data7`=0, `VerifiedBuild`=63704 WHERE `entry`=259879; -- Collision Wall
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=245640; -- Varian's Coffin
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=245649; -- Flowers (Bunch)
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=245687; -- Large Wreath
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=356, `VerifiedBuild`=63704 WHERE `entry`=246274; -- Gunship
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=252303; -- Draenei First Aid Cot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=642, `VerifiedBuild`=63704 WHERE `entry`=251426; -- Fel Fire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=1207, `VerifiedBuild`=63704 WHERE `entry`=240215; -- Ashes of a Fallen Crusader
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=1207, `VerifiedBuild`=63704 WHERE `entry`=240194; -- Spire of Woe
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=1207, `VerifiedBuild`=63704 WHERE `entry` IN (248819, 240535); -- Legion Cage
UPDATE `gameobject_template` SET `RequiredLevel`=15, `VerifiedBuild`=63704 WHERE `entry`=211319; -- Relief Bucket
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251347; -- Submarine
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251088; -- Rune
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251247; -- Pandaren Barrel 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251254; -- Grilled Fish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251246; -- Pandaren Barrel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251251; -- Baked Fowl
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=258301; -- Noodle Cart
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251255; -- Ribs
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=258302; -- Bubbling Pot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251253; -- Fried Rice
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251250; -- Baked Fish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251252; -- Dumplings
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251232; -- Basket Closed
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251240; -- Draenei Wagon
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251237; -- Draenei Crate 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251236; -- Draenei Crate 1
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (251235, 251234, 251233); -- Light-Infused Crystals
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251231; -- Basket Empty
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251230; -- Draenei Barrel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251229; -- Draenei Table
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251228; -- Draenei Pillow 3
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251227; -- Draenei Pillow 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251226; -- Draenei Pillow 1
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (251224, 251223, 251225); -- Draenei Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251242; -- Crystal Bucket
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (251023, 251022, 251021); -- Medical Supply Crate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251146; -- 7.0 Pre-Launch - Stormwind - Template
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251238; -- Supply Stack
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251244; -- Draenei Wagon 2
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=257879; -- Anvil
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=251195; -- Keg of Armor Polish
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (257881, 257880); -- 7.0 Pre-Launch - Orgrimmar - Template Object
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry`=257878; -- Forge
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (258255, 258254); -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63704 WHERE `entry` IN (259041, 250660); -- Alliance Battleship
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=293501; -- Forge
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=293500; -- Anvil
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=30, `ContentTuningId`=188, `VerifiedBuild`=63660 WHERE `entry`=279042; -- Smuggler's Stash
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293965; -- Scrimshaw Cache
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry` IN (291246, 291244); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=282153; -- Sunken Strongbox
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=189, `VerifiedBuild`=63660 WHERE `entry`=278808; -- Gryphon Nest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=186, `VerifiedBuild`=63660 WHERE `entry`=280649; -- Smuggler's Cache
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=281080; -- Corrupting Pylon
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273799; -- Bundle of Vellum
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (291201, 275074, 291257, 275070, 273955, 291204, 291211, 275076, 291263, 291267); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=277515; -- Tethering Post
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272755; -- Hovering Bloodflies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293688; -- Vigil Hill Documents
UPDATE `gameobject_template` SET `RequiredLevel`=1, `VerifiedBuild`=63660 WHERE `entry`=267540; -- Pirate Sails
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry` IN (293846, 303018, 293838, 293844, 293840, 303017, 293842); -- Ordinary Pebble
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293131; -- Pepe
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=325968; -- Portal to Exodar
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=325967; -- Portal to Ironforge
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293552; -- Portal to Stormwind
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry` IN (303207, 320928); -- Meeting Stone
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=316423; -- Sack of Dried Star Moss
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=316422; -- Crate of Test Vials
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=316424; -- Sand Shifter Scales
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=316430; -- Storm Silver Shards
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=279717; -- Bloodbound Ledger
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=278570; -- Ancient Journal
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=306854; -- Time Rift Spell Focus
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry` IN (323548, 313618); -- Crate of Bones
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=323383; -- Pail of Scales
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=312208; -- Bucket of Hides
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=321730; -- Tea Mug
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=241319; -- Libram
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=296223; -- A Copy of Steamy Romance Novel
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (290782, 290781, 290780, 290777); -- Ball and Chain
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=292910; -- Shipping Contracts
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=288641; -- WANTED: Gryphon 'Nappers
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=281230; -- Formal Invitation
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=297905; -- Jay's Songbook
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=281909; -- Abandoned Axe
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=281647; -- Posted Notice
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=280603; -- Ritual Effigy
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280929; -- Rough Map
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=296162; -- Bee Pheromones
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281646; -- Honey Vat
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281234; -- Misplaced Flask
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280646; -- Brewmaster's Treatise Vol. 1
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281213; -- Honey Soaked Boot
UPDATE `gameobject_template` SET `RequiredLevel`=30, `ContentTuningId`=188, `VerifiedBuild`=63660 WHERE `entry`=287531; -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=290537; -- Help Wanted
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280727; -- Charred Note
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280927; -- Thundershot Rifle
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280925; -- Tidal Blade
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280545; -- Harpoons
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280926; -- Abyssal Spear
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=278762; -- Stormsong Proclamation
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293349; -- Discarded Lunchbox
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=286952; -- Lichen-Covered Chest
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=244983; -- Dirty Pocketwatch
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=290820; -- River Carnations
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281482; -- Preserved Bramble Spores
UPDATE `gameobject_template` SET `Data19`=2, `RequiredLevel`=30, `ContentTuningId`=188, `VerifiedBuild`=63660 WHERE `entry`=281494; -- Frosty Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276838; -- Stirring Bone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=287941; -- Bag of Horse Treats
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276262; -- Trogg Cage
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278813; -- Post
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276270; -- Soup Stone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=287404; -- Riverbottom Nest
UPDATE `gameobject_template` SET `RequiredLevel`=35, `VerifiedBuild`=63660 WHERE `entry`=297826; -- Wicker Totem
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (290146, 290145); -- Abandoned Effigy
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276206; -- Bundle of Wicker
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276205; -- Bones
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276204; -- Fruit
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276203; -- Herbs
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276202; -- Grain
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276201; -- Scrolls
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276200; -- Entrails
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272422; -- Gentle's Spellbook
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=298769; -- Old Hat
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=302779; -- Bloody Banner
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298459; -- Heartsbane Scroll
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (278670, 272198, 278671); -- Cursed Charm
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272462; -- Rancher's Letter
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278418; -- Mayor Striggs
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=277380; -- Tainted Pig Feed
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (290419, 292523); -- Wanted Poster
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278516; -- Adventurer's Society Loot Stash
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278417; -- Mr. Munchykins
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272179; -- Mayor's Bulletin
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278669; -- Fallhaven Ledger
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272461; -- Ava's Note
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272196; -- Cursed Effigy
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=271176; -- Bewitching Fetish
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=277192; -- Disturbing Charm
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=272459; -- Farmer's Journal
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=298766; -- Old Crossbow
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298909; -- Reinforced Hide
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (279322, 279323, 279321); -- Heartsbane Focus
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278379; -- Lucille's Notes
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=279388; -- Lucille's Pack
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278378; -- Candle
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (279337, 279327, 279330); -- Heartsbane Grimoire
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=279329; -- Heartsbane Scrolls
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry` IN (279326, 279324); -- Heartsbane Fetish
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278321; -- Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (294125, 276242); -- Anchor Weed
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=284422; -- Crate of Azerite
UPDATE `gameobject_template` SET `RequiredLevel`=50, `ContentTuningId`=464, `VerifiedBuild`=63660 WHERE `entry`=290610; -- Azerite Node
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=277329; -- Ancient Sarcophagus
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276873; -- Hardened Lockbox
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=277273; -- Suspiciously Protruding Book
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276869; -- Wrapped Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276870; -- Cask of Salted Fish
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276874; -- Bucket of Grain
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=278432; -- Obviously Safe Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276622; -- Rich Storm Silver Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276258; -- "Genuine Titan Disc"
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276254; -- Beginner's Guide to Archaeology
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276251; -- Excavation Inventory
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276255; -- Is it a Rock? How to Identify Relics
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276257; -- "Ancient Potsherds"
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276247; -- Child-sized Backpack
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276259; -- "Relic of the Makers"
UPDATE `gameobject_template` SET `RequiredLevel`=20, `VerifiedBuild`=63660 WHERE `entry`=276253; -- Half-eaten Journal
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=278295; -- Crypt Door
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=290611; -- Azerite Chunk
UPDATE `gameobject_template` SET `RequiredLevel`=10, `ContentTuningId`=186, `VerifiedBuild`=63660 WHERE `entry` IN (273905, 273910); -- Small Treasure Chest
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273798; -- Jar of Blubber
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273212; -- Infested Cargo
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=273270; -- Harbor Seaweed
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=289361; -- WANTED: Quartermaster Ssylis
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278252; -- Job Flyer
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=297933; -- Dusty Songbook
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (276236, 281079); -- Star Moss
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=289313; -- WANTED: The Hornet
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278257; -- Beehive
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278399; -- Great Sea Catfish School
UPDATE `gameobject_template` SET `RequiredLevel`=40, `VerifiedBuild`=63660 WHERE `entry`=243439; -- Bones
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278777; -- Spotted Gryphon Egg
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276618; -- Platinum Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278357; -- Bloodied Boot
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278809; -- Roughneck Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278359; -- Roughneck Axe
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278361; -- Discarded Rucksack
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=309572; -- Antique Telescope
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278721; -- Snow Mound
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276238; -- Winter's Kiss
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=287331; -- Grain Sack
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281486; -- Quill Venom
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281473; -- Giant-Sized Totem
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=282477; -- Stolen Stormsong Supplies
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=282478; -- Empty Crate
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298913; -- Ensorcelled Runes
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry` IN (294537, 282457, 294536, 294535); -- Brambleguard Totem
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=293350; -- Carved Wooden Chest
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281912; -- Simmering Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281887; -- Stinky Potion
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281911; -- Bubbling Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=278433; -- Earthen Pillar
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280553; -- Tarnished Locket
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=281888; -- Pot of Viscous Goop
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298914; -- Rainbow Shell Pendant
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=280552; -- Battered Sword
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=325418; -- Boiling Cauldron
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276620; -- Storm Silver Seam
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298911; -- Folded Steel Plating
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276619; -- Monelite Seam
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=299009; -- Jitterplant
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry` IN (287467, 287468, 287463); -- Old Ship Part
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=278827; -- Sack of Grain
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=328429; -- Large Jelly Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=30, `ContentTuningId`=188, `VerifiedBuild`=63660 WHERE `entry`=292815; -- Horde Mortar
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=278824; -- Horde Explosive
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276617; -- Storm Silver Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry`=326165; -- Prospectable Rock
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=293499; -- Nesingwary's Campfire
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry`=288157; -- Wanted: Yarsel'ghun
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298910; -- Lightstep Insole
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298915; -- Capacity Draught
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276621; -- Rich Monelite Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=298912; -- Spring-Loaded Spikes
UPDATE `gameobject_template` SET `RequiredLevel`=30, `VerifiedBuild`=63660 WHERE `entry` IN (287196, 287187, 287190, 287193, 287191); -- Rebel Weaponry
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=299008; -- Charged Lodestone
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278405; -- Frenzied Fangtooth School
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276240; -- Sea Stalks
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278406; -- Lane Snapper School
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry` IN (316789, 322188, 322187); -- Fog Ward
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276239; -- Siren's Sting
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276616; -- Monelite Deposit
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=276234; -- Riverbud
UPDATE `gameobject_template` SET `RequiredLevel`=10, `VerifiedBuild`=63660 WHERE `entry`=278402; -- Tiragarde Perch School
UPDATE `gameobject_template` SET `RequiredLevel`=50, `VerifiedBuild`=63660 WHERE `entry` IN (327231, 327230); -- Jelly Deposit

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (529397,529396,527833));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(529397, 0, 243601, 63660), -- Curio Lockbox
(529396, 0, 243604, 63660), -- Weapon Crate
(527833, 0, 243607, 63660); -- Archeology Chest

UPDATE `gameobject_questitem` SET `VerifiedBuild`=63834 WHERE (`Idx`=0 AND `GameObjectEntry` IN (240346,250374,250372,250373,245486,245484,245485,245483,239341,249702,240033,251656,251784,243562,239692,240267,241635,241634,241633,245357,249462,249733,247695,248583));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63796 WHERE (`Idx`=0 AND `GameObjectEntry` IN (244841,245357,241279,248416,243954,243952,243953,247695,250905,250904,250903,245620,243639,243712,242449,241639,243973,243972,243971,250413,249462));
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63704 WHERE (`Idx`=0 AND `GameObjectEntry` IN (241279,251008,258850,258849,258851,251007,240586,241872,241874,241873,241871,241870,241866,240681,240677,243820,243823,243822,240286,241275,251419,321));
UPDATE `gameobject_questitem` SET `ItemId`=142312, `VerifiedBuild`=63704 WHERE (`GameObjectEntry`=267952 AND `Idx`=0); -- Stolen Crate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=63660 WHERE (`Idx`=0 AND `GameObjectEntry` IN (273799,293688,316423,316422,316424,316430,323548,323383,313618,312208,281909,280646,280927,280925,280545,280926,290820,276838,276270,278418,278417,279388,284422,276258,276254,276255,276257,276259,276253,273798,273270,278257,278777,282477,280553,280552,287467,287468,287463,278827,278824,326165,287196,287187,287190,287193,287191));

DELETE FROM `page_text` WHERE `ID`=10047;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(10047, '$n,\n\nYou have much work ahead of you so I\'ll be brief.\n\nIn addition to an overall greater danger in this timeline, certain enemies will be empowered with one, two, or even four experimental changes.\n\nShould this timeline prove too difficult, you may use the research console at our Infinite Bazaar near Dalaran to exit the experiment. I have also ensured safe passage in the event of your untimely demise--you will understand should ill fate befall you.\n\nBest of luck,\nEternus', 0, 0, 0, 63704); -- 10047

UPDATE `page_text` SET `VerifiedBuild`=63834 WHERE `ID` IN (5310, 5309, 5308);
UPDATE `page_text` SET `VerifiedBuild`=63796 WHERE `ID`=5158;
UPDATE `page_text` SET `VerifiedBuild`=63704 WHERE `ID` IN (5231, 5234, 5233);
UPDATE `page_text` SET `Text`='The box contains various magical looking trinkets and baubles.\n\nUpon closer inspection, these \"relics\" appear to be nothing more than clever forgeries.', `VerifiedBuild`=63704 WHERE `ID`=5232; -- 5232

