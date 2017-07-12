-- Tailoring trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201039 OR `SpellID`= -201039;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
( 1103, -201039, 0, 0, 0, 0), -- Eldrin
( 1346, -201039, 0, 0, 0, 0), -- Georgio Bolero
( 2399, -201039, 0, 0, 0, 0), -- Daryl Stack
( 2627, -201039, 0, 0, 0, 0), -- Grarnik Goodstitch
( 3004, -201039, 0, 0, 0, 0), -- Tepa
( 3363, -201039, 0, 0, 0, 0), -- Magar
( 3484, -201039, 0, 0, 0, 0), -- Kil'hala
( 3523, -201039, 0, 0, 0, 0), -- Bowen Brisboise
( 3704, -201039, 0, 0, 0, 0), -- Mahani
( 4159, -201039, 0, 0, 0, 0), -- Me'lynn
( 4193, -201039, 0, 0, 0, 0), -- Grondal Moonbreeze
( 4576, -201039, 0, 0, 0, 0), -- Josef Gregorian
( 4578, -201039, 0, 0, 0, 0), -- Josephine Lister
( 5153, -201039, 0, 0, 0, 0), -- Jormund Stonebrow
( 9584, -201039, 0, 0, 0, 0), -- Jalane Ayrole
(11052, -201039, 0, 0, 0, 0), -- Timothy Worthington
(11557, -201039, 0, 0, 0, 0), -- Meilosh
(16366, -201039, 0, 0, 0, 0), -- Sempstress Ambershine
(16640, -201039, 0, 0, 0, 0), -- Keelen Sheets
(16729, -201039, 0, 0, 0, 0), -- Refik
(17487, -201039, 0, 0, 0, 0), -- Erin Kelly
(18749, -201039, 0, 0, 0, 0), -- Dalinna
(18772, -201039, 0, 0, 0, 0), -- Hama
(26914, -201039, 0, 0, 0, 0), -- Benjamin Clegg
(26964, -201039, 0, 0, 0, 0), -- Alexandra McQueen
(26969, -201039, 0, 0, 0, 0), -- Raenah
(27001, -201039, 0, 0, 0, 0), -- Darin Goodstitch
(28699, -201039, 0, 0, 0, 0), -- Charles Worth
(33580, -201039, 0, 0, 0, 0), -- Dustin Vail
(33613, -201039, 0, 0, 0, 0), -- Tailoring book shelf
(33636, -201039, 0, 0, 0, 0), -- Miralisse
(33684, -201039, 0, 0, 0, 0), -- Weaver Aoa
(43428, -201039, 0, 0, 0, 0), -- Faeyrin Willowmoon
(44783, -201039, 0, 0, 0, 0), -- Hiwahi Three-Feathers
(45559, -201039, 0, 0, 0, 0), -- Nivi Weavewell
(84619, -201039, 0, 0, 0, 0), -- Daryl Stack
(85910, -201039, 0, 0, 0, 0), -- Joshua Fuesting
(86004, -201039, 0, 0, 0, 0), -- Saesha Silverblood
(93525, -201039, 0, 0, 0, 0), -- Ainderu Summerleaf
(93542, -201039, 0, 0, 0, 0), -- Tanithria
(95794, -201039, 0, 0, 0, 0), -- Kil'hala
(98908, -201039, 0, 0, 0, 0), -- Ainderu Summerleaf
(98912, -201039, 0, 0, 0, 0), -- Charles Worth

-- Tailoring spells
(201039,   2385,      50, 197,  10,  0), -- Brown Linen Vest
(201039,   2386,     200, 197,  65,  0), -- Linen Boots
(201039,   2392,      50, 197,  40,  0), -- Red Linen Shirt
(201039,   2393,      25, 197,   1,  0), -- White Linen Shirt
(201039,   2394,      50, 197,  40,  0), -- Blue Linen Shirt
(201039,   2395,     300, 197,  70,  0), -- Barbaric Linen Vest
(201039,   2396,     200, 197,  70,  0), -- Green Linen Shirt
(201039,   2397,     200, 197,  60,  0), -- Reinforced Linen Cape
(201039,   2399,     300, 197,  85,  0), -- Green Woolen Vest
(201039,   2401,     300, 197,  95,  0), -- Woolen Boots
(201039,   2402,     250, 197,  75,  0), -- Woolen Cape
(201039,   2406,     200, 197, 100,  0), -- Gray Woolen Shirt
(201039,   2964,     100, 197,  75,  0), -- Bolt of Woolen Cloth
(201039,   3755,     100, 197,  45,  0), -- Linen Bag
(201039,   3757,     200, 197,  80,  0), -- Woolen Bag
(201039,   3813,     800, 197, 150,  0), -- Small Silk Pack
(201039,   3839,     500, 197, 125,  0), -- Bolt of Silk Cloth
(201039,   3840,     100, 197,  35,  0), -- Heavy Linen Gloves
(201039,   3841,     200, 197,  60,  0), -- Green Linen Bracers
(201039,   3842,     300, 197,  70,  0), -- Handstitched Linen Britches
(201039,   3843,     400, 197,  85,  0), -- Heavy Woolen Gloves
(201039,   3845,     300, 197,  80,  0), -- Soft-soled Linen Boots
(201039,   3848,     500, 197, 110,  0), -- Double-stitched Woolen Shoulders
(201039,   3850,     500, 197, 110,  0), -- Heavy Woolen Pants
(201039,   3852,     750, 197, 130,  0), -- Gloves of Meditation
(201039,   3855,     750, 197, 125,  0), -- Spidersilk Boots
(201039,   3859,     750, 197, 150,  0), -- Azure Silk Vest
(201039,   3861,    1000, 197, 185,  0), -- Long Silken Cloak
(201039,   3865,    1000, 197, 175,  0), -- Bolt of Mageweave
(201039,   3866,     250, 197, 110,  0), -- Stylish Red Shirt
(201039,   3871,     500, 197, 170,  0), -- Formal White Shirt
(201039,   3911,      10,   0,   0,  5), -- Apprentice Tailor
(201039,   3912,     500, 197,  50, 10), -- Journeyman Tailor
(201039,   3913,    5000, 197, 125, 20), -- Expert Tailor
(201039,   3914,      50, 197,  30,  0), -- Brown Linen Pants
(201039,   3915,      25, 197,   1,  0), -- Brown Linen Shirt
(201039,   6521,     400, 197,  90,  0), -- Pearl-clasped Cloak
(201039,   6690,    1000, 197, 135,  0), -- Lesser Wizard's Robe
(201039,   7623,      50, 197,  30,  0), -- Brown Linen Robe
(201039,   7624,      50, 197,  30,  0), -- White Linen Robe
(201039,   8465,      50, 197,  40,  0), -- Simple Dress
(201039,   8467,     250, 197, 110,  0), -- White Woolen Dress
(201039,   8483,     500, 197, 160,  0), -- White Swashbuckler's Shirt
(201039,   8489,     750, 197, 175,  0), -- Red Swashbuckler's Shirt
(201039,   8758,     600, 197, 140,  0), -- Azure Silk Pants
(201039,   8760,     600, 197, 145,  0), -- Azure Silk Hood
(201039,   8762,     750, 197, 160,  0), -- Silk Headband
(201039,   8764,     900, 197, 170,  0), -- Earthen Vest
(201039,   8766,    1000, 197, 175,  0), -- Azure Silk Belt
(201039,   8770,    1000, 197, 190,  0), -- Robe of Power
(201039,   8772,    1000, 197, 175,  0), -- Crimson Silk Belt
(201039,   8774,    1000, 197, 180,  0), -- Green Silken Shoulders
(201039,   8776,      50, 197,  15,  0), -- Linen Belt
(201039,   8791,    2500, 197, 185,  0), -- Crimson Silk Vest
(201039,   8799,    3000, 197, 195,  0), -- Crimson Silk Pantaloons
(201039,   8804,    5000, 197, 210,  0), -- Crimson Silk Gloves
(201039,  12045,      50, 197,  20,  0), -- Simple Linen Boots
(201039,  12046,     300, 197,  75,  0), -- Simple Kilt
(201039,  12048,    4000, 197, 205,  0), -- Black Mageweave Vest
(201039,  12049,    4000, 197, 205,  0), -- Black Mageweave Leggings
(201039,  12050,    4000, 197, 210,  0), -- Black Mageweave Robe
(201039,  12052,    5000, 197, 210,  0), -- Shadoweave Pants
(201039,  12053,    5000, 197, 215,  0), -- Black Mageweave Gloves
(201039,  12055,    5500, 197, 215,  0), -- Shadoweave Robe
(201039,  12061,    2500, 197, 215,  0), -- Orange Mageweave Shirt
(201039,  12065,    5000, 197, 225,  0), -- Mageweave Bag
(201039,  12067,    5000, 197, 225,  0), -- Dreamweave Gloves
(201039,  12069,    5000, 197, 225,  0), -- Cindercloth Robe
(201039,  12070,    5000, 197, 225,  0), -- Dreamweave Vest
(201039,  12071,    6000, 197, 225,  0), -- Shadoweave Gloves
(201039,  12072,    6000, 197, 230,  0), -- Black Mageweave Headband
(201039,  12073,    6000, 197, 230,  0), -- Black Mageweave Boots
(201039,  12074,    6000, 197, 230,  0), -- Black Mageweave Shoulders
(201039,  12076,    6500, 197, 235,  0), -- Shadoweave Shoulders
(201039,  12077,    5000, 197, 235,  0), -- Simple Black Dress
(201039,  12079,    6500, 197, 235,  0), -- Red Mageweave Bag
(201039,  12082,    7000, 197, 240,  0), -- Shadoweave Boots
(201039,  12088,    7500, 197, 245,  0), -- Cindercloth Boots
(201039,  12092,    7500, 197, 250,  0), -- Dreamweave Circlet
(201039,  12181,   50000, 197, 200, 35), -- Artisan Tailor
(201039,  18401,   10000, 197, 250,  0), -- Bolt of Runecloth
(201039,  18402,   10000, 197, 255,  0), -- Runecloth Belt
(201039,  18403,   10000, 197, 255,  0), -- Frostweave Tunic
(201039,  18406,   10000, 197, 260,  0), -- Runecloth Robe
(201039,  18407,   10000, 197, 260,  0), -- Runecloth Tunic
(201039,  18409,   10000, 197, 265,  0), -- Runecloth Cloak
(201039,  18410,   10000, 197, 265,  0), -- Ghostweave Belt
(201039,  18411,   10000, 197, 265,  0), -- Frostweave Gloves
(201039,  18413,   10000, 197, 270,  0), -- Ghostweave Gloves
(201039,  18414,   10000, 197, 270,  0), -- Brightcloth Robe
(201039,  18415,   10000, 197, 270,  0), -- Brightcloth Gloves
(201039,  18416,   12500, 197, 275,  0), -- Ghostweave Vest
(201039,  18417,   12500, 197, 275,  0), -- Runecloth Gloves
(201039,  18420,   12500, 197, 275,  0), -- Brightcloth Cloak
(201039,  18421,   12500, 197, 275,  0), -- Wizardweave Leggings
(201039,  18423,   15000, 197, 280,  0), -- Runecloth Boots
(201039,  18424,   15000, 197, 280,  0), -- Frostweave Pants
(201039,  18437,   15000, 197, 285,  0), -- Felcloth Boots
(201039,  18438,   15000, 197, 285,  0), -- Runecloth Pants
(201039,  18441,   15000, 197, 290,  0), -- Ghostweave Pants
(201039,  18442,   15000, 197, 290,  0), -- Felcloth Hood
(201039,  18444,   15000, 197, 295,  0), -- Runecloth Headband
(201039,  18446,   15000, 197, 300,  0), -- Wizardweave Robe
(201039,  18449,   15000, 197, 300,  0), -- Runecloth Shoulders
(201039,  18450,   15000, 197, 300,  0), -- Wizardweave Turban
(201039,  18451,   15000, 197, 300,  0), -- Felcloth Robe
(201039,  18453,   15000, 197, 300,  0), -- Felcloth Shoulders
(201039,  26745,   20000, 197, 300,  0), -- Bolt of Netherweave
(201039,  26746,   15000, 197, 315,  0), -- Netherweave Bag
(201039,  26764,   15000, 197, 310,  0), -- Netherweave Bracers
(201039,  26765,   15000, 197, 310,  0), -- Netherweave Belt
(201039,  26770,   20000, 197, 320,  0), -- Netherweave Gloves
(201039,  26771,   20000, 197, 325,  0), -- Netherweave Pants
(201039,  26772,   20000, 197, 335,  0), -- Netherweave Boots
(201039,  26791,  100000, 197, 275, 50), -- Master Tailor
(201039,  31460,   20000, 197, 300,  0), -- Netherweave Net
(201039,  51308,  350000, 197, 350, 65), -- Grand Master Tailor
(201039,  55898,   50000, 197, 360,  0), -- Frostweave Net
(201039,  55899,   50000, 197, 350,  0), -- Bolt of Frostweave
(201039,  55900,  125000, 197, 400,  0), -- Bolt of Imbued Frostweave
(201039,  55901,   50000, 197, 395,  0), -- Duskweave Leggings
(201039,  55902,   50000, 197, 350,  0), -- Frostwoven Shoulders
(201039,  55903,   50000, 197, 360,  0), -- Frostwoven Robe
(201039,  55904,   50000, 197, 360,  0), -- Frostwoven Gloves
(201039,  55906,   50000, 197, 375,  0), -- Frostwoven Boots
(201039,  55907,   50000, 197, 380,  0), -- Frostwoven Cowl
(201039,  55908,   50000, 197, 370,  0), -- Frostwoven Belt
(201039,  55910,   80000, 197, 385,  0), -- Mystic Frostwoven Shoulders
(201039,  55911,   80000, 197, 390,  0), -- Mystic Frostwoven Robe
(201039,  55913,   80000, 197, 385,  0), -- Mystic Frostwoven Wristwraps
(201039,  55914,   50000, 197, 395,  0), -- Duskweave Belt
(201039,  55919,  100000, 197, 395,  0), -- Duskweave Cowl
(201039,  55920,   50000, 197, 400,  0), -- Duskweave Wristwraps
(201039,  55921,  100000, 197, 405,  0), -- Duskweave Robe
(201039,  55922,  100000, 197, 405,  0), -- Duskweave Gloves
(201039,  55923,  100000, 197, 410,  0), -- Duskweave Shoulders
(201039,  55924,  125000, 197, 410,  0), -- Duskweave Boots
(201039,  55925,  125000, 197, 415,  0), -- Black Duskweave Leggings
(201039,  55941,  125000, 197, 420,  0), -- Black Duskweave Robe
(201039,  55943,  125000, 197, 415,  0), -- Black Duskweave Wristwraps
(201039,  55995,   50000, 197, 400,  0), -- Yellow Lumberjack Shirt
(201039,  56000,   50000, 197, 400,  0), -- Green Workman's Shirt
(201039,  56001,  100000, 197, 415,  0), -- Moonshroud
(201039,  56002,  100000, 197, 415,  0), -- Ebonweave
(201039,  56003,  100000, 197, 415,  0), -- Spellweave
(201039,  56007,   80000, 197, 410,  0), -- Frostweave Bag
(201039,  56008,  100000, 197, 400,  0), -- Shining Spellthread
(201039,  56010,  100000, 197, 400,  0), -- Azure Spellthread
(201039,  56014,  100000, 197, 390,  0), -- Cloak of the Moon
(201039,  56015,  100000, 197, 395,  0), -- Cloak of Frozen Spirits
(201039,  56018,  100000, 197, 425,  0), -- Hat of Wintry Doom
(201039,  56019,  100000, 197, 420,  0), -- Silky Iceshard Boots
(201039,  56020,  100000, 197, 420,  0), -- Deep Frozen Cord
(201039,  56021,  100000, 197, 425,  0), -- Frostmoon Pants
(201039,  56022,  100000, 197, 420,  0), -- Light Blessed Mittens
(201039,  56023,  100000, 197, 420,  0), -- Aurora Slippers
(201039,  56024,  200000, 197, 440,  0), -- Moonshroud Robe
(201039,  56025,  200000, 197, 435,  0), -- Moonshroud Gloves
(201039,  56026,  200000, 197, 440,  0), -- Ebonweave Robe
(201039,  56027,  200000, 197, 435,  0), -- Ebonweave Gloves
(201039,  56028,  200000, 197, 440,  0), -- Spellweave Robe
(201039,  56029,  200000, 197, 435,  0), -- Spellweave Gloves
(201039,  56030,   50000, 197, 380,  0), -- Frostwoven Leggings
(201039,  56031,   50000, 197, 350,  0), -- Frostwoven Wristwraps
(201039,  56034,  100000, 197, 405,  0), -- Master's Spellthread
(201039,  56039,  100000, 197, 405,  0), -- Sanctified Spellthread
(201039,  59582,  100000, 197, 415,  0), -- Frostsavage Belt
(201039,  59583,  100000, 197, 415,  0), -- Frostsavage Bracers
(201039,  59584,  100000, 197, 420,  0), -- Frostsavage Shoulders
(201039,  59585,  100000, 197, 420,  0), -- Frostsavage Boots
(201039,  59586,  100000, 197, 420,  0), -- Frostsavage Gloves
(201039,  59587,  100000, 197, 420,  0), -- Frostsavage Robe
(201039,  59588,  120000, 197, 420,  0), -- Frostsavage Leggings
(201039,  59589,  120000, 197, 420,  0), -- Frostsavage Cowl
(201039,  60969,  105000, 197, 300,  0), -- Flying Carpet
(201039,  60971,  150000, 197, 425,  0), -- Magnificent Flying Carpet
(201039,  60990,  180000, 197, 420,  0), -- Glacial Waistband
(201039,  60993,  180000, 197, 425,  0), -- Glacial Robe
(201039,  60994,  180000, 197, 420,  0), -- Glacial Slippers
(201039,  63742,     750, 197, 125,  0), -- Spidersilk Drape
(201039,  64729,  100000, 197, 400,  0), -- Frostguard Drape
(201039,  64730,  100000, 197, 405,  0), -- Cloak of Crimson Snow
(201039,  74964,  100000, 197, 425,  0), -- Bolt of Embersilk Cloth
(201039,  75141,  150000, 197, 515,  0), -- Dream of Skywall
(201039,  75142,  150000, 197, 505,  0), -- Dream of Deepholm
(201039,  75144,  150000, 197, 500,  0), -- Dream of Hyjal
(201039,  75145,  150000, 197, 510,  0), -- Dream of Ragnaros
(201039,  75146,  150000, 197, 500,  0), -- Dream of Azshara
(201039,  75157,  500000, 197, 425, 80), -- Illustrious Grand Master Tailor
(201039,  75247,  100000, 197, 425,  0), -- Embersilk Net
(201039,  75248,  120000, 197, 445,  0), -- Deathsilk Belt
(201039,  75249,  120000, 197, 445,  0), -- Deathsilk Bracers
(201039,  75250,  120000, 197, 450,  0), -- Enchanted Spellthread
(201039,  75251,  120000, 197, 455,  0), -- Deathsilk Shoulders
(201039,  75252,  120000, 197, 455,  0), -- Deathsilk Boots
(201039,  75253,  120000, 197, 460,  0), -- Deathsilk Gloves
(201039,  75254,  120000, 197, 460,  0), -- Deathsilk Leggings
(201039,  75255,  120000, 197, 460,  0), -- Ghostly Spellthread
(201039,  75256,  120000, 197, 465,  0), -- Deathsilk Cowl
(201039,  75257,  120000, 197, 465,  0), -- Deathsilk Robe
(201039,  75258,  120000, 197, 470,  0), -- Spiritmend Belt
(201039,  75259,  120000, 197, 470,  0), -- Spiritmend Bracers
(201039,  75260,  120000, 197, 475,  0), -- Spiritmend Shoulders
(201039,  75261,  120000, 197, 475,  0), -- Spiritmend Boots
(201039,  75262,  150000, 197, 480,  0), -- Spiritmend Gloves
(201039,  75263,  150000, 197, 480,  0), -- Spiritmend Leggings
(201039,  75264,  150000, 197, 480,  0), -- Embersilk Bag
(201039,  75265,  150000, 197, 480,  0), -- Otherworldly Bag
(201039,  75266,  150000, 197, 485,  0), -- Spiritmend Cowl
(201039,  75267,  150000, 197, 485,  0), -- Spiritmend Robe
(201039,  75268,  150000, 197, 490,  0), -- Hyjal Expedition Bag
(201039,  75269,  180000, 197, 510,  0), -- Vicious Fireweave Belt
(201039,  75270,  150000, 197, 500,  0), -- Vicious Embersilk Bracers
(201039,  75290,  150000, 197, 500,  0), -- Vicious Fireweave Bracers
(201039,  75291,  190000, 197, 505,  0), -- Vicious Embersilk Shoulders
(201039,  75292,  180000, 197, 510,  0), -- Vicious Fireweave Shoulders
(201039,  75293,  180000, 197, 510,  0), -- Vicious Embersilk Belt
(201039,  75294,  180000, 197, 515,  0), -- Vicious Fireweave Boots
(201039,  75295,  180000, 515, 480,  0), -- Vicious Embersilk Gloves
(201039,  75296,  180000, 197, 520,  0), -- Vicious Fireweave Gloves
(201039,  75297,  180000, 197, 520,  0), -- Vicious Embersilk Boots
(201039,  94743,  240000, 197, 525,  0), -- Dream of Destruction
(201039,  99537,  150000, 197, 490,  0), -- Vicious Embersilk Cape
(201039, 110427,  600000, 197, 500, 85), -- Zen Master Tailor
(201039, 125523,   24000, 197, 555,  0), -- Windwool Hood
(201039, 125524,   24000, 197, 535,  0), -- Windwool Shoulders
(201039, 125525,   24000, 197, 555,  0), -- Windwool Tunic
(201039, 125526,   24000, 197, 535,  0), -- Windwool Gloves
(201039, 125527,   24000, 197, 545,  0), -- Windwool Pants
(201039, 125528,   24000, 197, 525,  0), -- Windwool Bracers
(201039, 125529,   24000, 197, 545,  0), -- Windwool Boots
(201039, 125530,   24000, 197, 535,  0), -- Windwool Belt
(201039, 125551,   24000, 197, 500,  0), -- Bolt of Windwool Cloth
(201039, 125552,   24000, 197, 530,  0), -- Pearlescent Spellthread
(201039, 125553,   24000, 197, 550,  0), -- Cerulean Spellthread
(201039, 125557,  240000, 197, 550,  0), -- Imperial Silk
(201039, 130325,  240000, 197, 560,  0), -- Song of Harmony
(201039, 134585,  180000, 197, 515,  0), -- Bipsi's Gloves
(201039, 186091, 2000000, 197,   1,  0), -- Silkweave Shade
(201039, 186094, 2000000, 197,   1,  0), -- Silkweave Flourish
(201039, 186097, 2000000, 197,   1,  0), -- Silkweave Cover
(201039, 186100, 2000000, 197,   1,  0); -- Silkweave Drape
