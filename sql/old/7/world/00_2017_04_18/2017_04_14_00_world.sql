-- 
-- Cooking trainers
DELETE FROM `npc_trainer` WHERE `ID`= 202004 OR `SpellID`= -202004;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
( 1355, -202004, 0, 0, 0, 0), -- Cook Ghilm 
( 1382, -202004, 0, 0, 0, 0), -- Mudduk
( 1430, -202004, 0, 0, 0, 0), -- Tomas
( 1699, -202004, 0, 0, 0, 0), -- Gremlock Pilsnor 
( 3026, -202004, 0, 0, 0, 0), -- Aska Mistrunner
( 3067, -202004, 0, 0, 0, 0), -- Pyall Silentstride 
( 3087, -202004, 0, 0, 0, 0), -- Crystal Boughman
( 3399, -202004, 0, 0, 0, 0), -- Zamja
( 3966, -202004, 0, 0, 0, 0), -- Kaleem 
( 4210, -202004, 0, 0, 0, 0), -- Alegorn
( 4552, -202004, 0, 0, 0, 0), -- Eunice Burch
( 4894, -202004, 0, 0, 0, 0), -- Craig Nollward
( 5036, -202004, 0, 0, 0, 0), -- World Cooking Trainer  
( 5159, -202004, 0, 0, 0, 0), -- Daryl Riknussun 
( 5482, -202004, 0, 0, 0, 0), -- Stephen Ryback 
( 6286, -202004, 0, 0, 0, 0), -- Zarrin 
( 8306, -202004, 0, 0, 0, 0), -- Duhng
(16277, -202004, 0, 0, 0, 0), -- Quarelestra
(16676, -202004, 0, 0, 0, 0), -- Sylann 
(16719, -202004, 0, 0, 0, 0), -- Mumman
(18987, -202004, 0, 0, 0, 0), -- Gaston
(18988, -202004, 0, 0, 0, 0), -- Baxter
(19185, -202004, 0, 0, 0, 0), -- Jack Trapper 
(19369, -202004, 0, 0, 0, 0), -- Celie Steelwing 
(26905, -202004, 0, 0, 0, 0), -- Brom Brewbaster
(26953, -202004, 0, 0, 0, 0), -- Thomas Kolichio
(26972, -202004, 0, 0, 0, 0), -- Orn Tenderhoof
(26989, -202004, 0, 0, 0, 0), -- Rollick MacKreel
(28705, -202004, 0, 0, 0, 0), -- Katherine Lee
(29631, -202004, 0, 0, 0, 0), -- Awilo Lon'gomba 
(33587, -202004, 0, 0, 0, 0), -- Bethany Cromwell
(34708, -202004, 0, 0, 0, 0), -- Caitrin Ironkettle  
(34710, -202004, 0, 0, 0, 0), -- Ellen Moore 
(34711, -202004, 0, 0, 0, 0), -- Mary Allerton 
(34712, -202004, 0, 0, 0, 0), -- Roberta Carter
(34713, -202004, 0, 0, 0, 0), -- Ondani Greatmill
(34714, -202004, 0, 0, 0, 0), -- Mahara Goldwheat
(34785, -202004, 0, 0, 0, 0), -- Alnar Whitebough 
(34786, -202004, 0, 0, 0, 0), -- Alice Rigsdale 
(45550, -202004, 0, 0, 0, 0), -- Zarbo Porkpatty
(46709, -202004, 0, 0, 0, 0), -- Arugi
(47405, -202004, 0, 0, 0, 0), -- The Chef
(49789, -202004, 0, 0, 0, 0), -- Allison
(50567, -202004, 0, 0, 0, 0), -- Fielding Chesterhill
(85925, -202004, 0, 0, 0, 0), -- Elton Black
(86029, -202004, 0, 0, 0, 0), -- Guy Fireeye
(93534, -202004, 0, 0, 0, 0), -- Katherine Lee
(95981, -202004, 0, 0, 0, 0), -- Duhng
(98527, -202004, 0, 0, 0, 0), -- Pyall Silentstride
(99330, -202004, 0, 0, 0, 0), -- Katherine Lee
(99843, -202004, 0, 0, 0, 0), -- Cook Ghilm
(99991, -202004, 0, 0, 0, 0), -- Gremlock Pilsnor

 -- Cooking spells
(202004,   2539,     50, 185,  10,  5), -- Spiced Wolf Meat
(202004,   2541,    100, 185,  50,  5), -- Coyote Steak
(202004,   2544,    200, 185,  75,  5), -- Crab Cake
(202004,   2546,    150, 185,  80, 10), -- Dry Pork Ribs
(202004,   2550,     10,   0,   0,  5), -- Apprentice Cooking
(202004,   3102,    500, 185,  50, 10), -- Journeyman Cooking
(202004,   3399,    450, 185, 150, 10), -- Tasty Lion Steak
(202004,   3400,    500, 185, 175, 20), -- Soothing Turtle Bisque
(202004,   3413,   5000, 185, 125, 20), -- Expert Cooking
(202004,   4094,    500, 185, 175, 20), -- Barbecued Buzzard Wing
(202004,   6412,     50, 185,  10,  5), -- Kaldorei Spider Kabob
(202004,   6415,    100, 185,  50,  5), -- Fillet of Frenzy
(202004,   6499,    100, 185,  50,  5), -- Boiled Clams
(202004,   6500,    300, 185, 125, 10), -- Goblin Deviled Clams
(202004,  18238,   5000, 185, 225, 20), -- Spotted Yellowtail
(202004,  18240,   6000, 185, 240, 35), -- Grilled Squid
(202004,  18243,   6500, 185, 250, 35), -- Nightfin Soup
(202004,  18244,   6500, 185, 250, 35), -- Poached Sunscale Salmon
(202004,  18260,  50000, 185, 200, 35), -- Artisan Cooking
(202004,  21175,   4000, 185, 200, 20), -- Spider Sausage
(202004,  33359, 100000, 185, 275, 50), -- Master Cooking
(202004,  37836,     10, 185,   1,  5), -- Spice Bread
(202004,  42296,  15000, 185, 320, 50), -- Stewed Trout
(202004,  42302,  20000, 185, 350, 50), -- Fisherman's Feast
(202004,  42305,  20000, 185, 350, 50), -- Hot Buttered Trout
(202004,  45549,  20000, 185, 350, 50), -- Mammoth Meal
(202004,  45550,  20000, 185, 350, 50), -- Shoveltusk Steak
(202004,  45551,  20000, 185, 350, 50), -- Worm Delight
(202004,  45552,  20000, 185, 350, 50), -- Roasted Worg
(202004,  45553,  20000, 185, 350, 50), -- Rhino Dogs
(202004,  45554,  50000, 185, 375, 50), -- Great Feast
(202004,  45560,  10000, 185, 350, 50), -- Smoked Rockfin
(202004,  45561,  10000, 185, 350, 50), -- Grilled Bonescale
(202004,  45562,  10000, 185, 350, 50), -- Sauteed Goby
(202004,  45563,  20000, 185, 350, 50), -- Grilled Sculpin
(202004,  45564,  20000, 185, 350, 50), -- Smoked Salmon
(202004,  45565,  20000, 185, 350, 50), -- Poached Nettlefish
(202004,  45566,  20000, 185, 350, 50), -- Pickled Fangtooth
(202004,  45569,  20000, 185, 350, 50), -- Baked Manta Ray
(202004,  46684,   6500, 185, 250, 35), -- Charred Bear Kabobs
(202004,  46688,   6500, 185, 250, 35), -- Juicy Bear Burger
(202004,  51296, 350000, 185, 350, 65), -- Grand Master Cooking
(202004,  58065,  20000, 185, 350, 50), -- Dalaran Clam Chowder
(202004,  64358,  50000, 185, 400, 65), -- Black Jelly
(202004,  88006,  35000, 185, 425, 65), -- Blackened Surprise
(202004,  88015,  30000, 185, 415, 65), -- Darkbrew Lager
(202004,  88053, 500000, 185, 425, 80), -- Illustrious Grand Master Cooking
(202004,  93741,     80, 185,  40,  5), -- Venison Jerky
(202004, 104237,  40000, 185, 270, 35), -- Golden Carp Consomme
(202004, 104297,  40000, 185, 300, 35), -- Fish Cake
(202004, 104298,  38000, 185, 525, 85), -- Charbroiled Tiger Steak
(202004, 104299,  38000, 185, 550, 85), -- Eternal Blossom Fish
(202004, 104300,  38000, 185, 600, 85), -- Black Pepper Ribs and Shrimp
(202004, 104301,  38000, 185, 525, 85), -- Sauteed Carrots
(202004, 104302,  38000, 185, 550, 85), -- Valley Stir Fry
(202004, 104303,  38000, 185, 600, 85), -- Sea Mist Rice Noodles
(202004, 104304,  38000, 185, 525, 85), -- Swirling Mist Soup
(202004, 104305,  38000, 185, 550, 85), -- Braised Turtle
(202004, 104306,  38000, 185, 600, 85), -- Mogu Fish Stew
(202004, 104307,  38000, 185, 525, 85), -- Shrimp Dumplings
(202004, 104308,  38000, 185, 550, 85), -- Fire Spirit Salmon
(202004, 104309,  38000, 185, 600, 85), -- Steamed Crab Surprise
(202004, 104310,  38000, 185, 525, 85), -- Wildfowl Roast
(202004, 104311,  38000, 185, 550, 85), -- Twin Fish Platter
(202004, 104312,  38000, 185, 600, 85), -- Chun Tian Spring Rolls
(202004, 104381, 600000, 185, 500, 85), -- Zen Master Cooking
(202004, 124052,  38000, 185, 525, 85), -- Ginseng Tea
(202004, 124053,  38000, 185, 550, 85), -- Jade Witch Brew
(202004, 124054,  38000, 185, 600, 85), -- Mad Brewer's Breakfast
(202004, 124223,   3600, 185, 550, 85), -- Pounded Rice Cake
(202004, 124224,   4000, 185, 550, 85), -- Yak Cheese Curds
(202004, 124225,   3600, 185, 550, 85), -- Toasted Fish Jerky
(202004, 124226,   4000, 185, 550, 85), -- Dried Peaches
(202004, 124227,   3600, 185, 550, 85), -- Dried Needle Mushrooms
(202004, 124228,   4000, 185, 550, 85), -- Boiled Silkworm Pupa
(202004, 124229,   5000, 185, 360, 50), -- Red Bean Bun
(202004, 124230,  21300, 185, 480, 85), -- Tangy Yogurt
(202004, 124231,  21300, 185, 420, 65), -- Green Curry Fish
(202004, 124232,  21300, 185, 425, 65), -- Peach Pie
(202004, 124233,   5000, 185, 330, 50), -- Blanched Needle Mushrooms
(202004, 124234,  21300, 185, 390, 65), -- Skewered Peanut Chicken
(202004, 125067,   3600, 185, 550, 85), -- Perfectly Cooked Instant Noodles
(202004, 125078,   4000, 185, 240, 35), -- Roasted Barley Tea
(202004, 125080,  32500, 185, 550, 85), -- Pearl Milk Tea
(202004, 125117,    100, 185, 550, 85), -- Sliced Peaches
(202004, 125121,  32500, 185, 550, 85), -- Wildfowl Ginseng Soup
(202004, 125122,  32500, 185, 520, 85), -- Rice Pudding
(202004, 125141,  38000, 185, 575, 85), -- Banquet of the Grill
(202004, 125595,  38000, 185, 575, 85), -- Great Banquet of the Wok
(202004, 125596,  38000, 185, 575, 85), -- Banquet of the Pot
(202004, 125598,  38000, 185, 575, 85), -- Banquet of the Steamer
(202004, 125600,  38000, 185, 575, 85), -- Banquet of the Oven
(202004, 125602,  38000, 185, 575, 85); -- Banquet of the Brew

-- Skinning trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201036 OR `SpellID`= -201036;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
(  1292, -201036, 0, 0, 0, 0), -- Maris Granger
(  6242, -201036, 0, 0, 0, 0), -- World Skinning Trainer
(  6287, -201036, 0, 0, 0, 0), -- Radnaal Maneweaver
(  6288, -201036, 0, 0, 0, 0), -- Jayla
(  6289, -201036, 0, 0, 0, 0), -- Rand Rhobart
(  6290, -201036, 0, 0, 0, 0), -- Yonn Deepcut
(  6291, -201036, 0, 0, 0, 0), -- Balthus Stoneflayer
(  6292, -201036, 0, 0, 0, 0), -- Eladriel
(  6295, -201036, 0, 0, 0, 0), -- Wilma Ranthal
(  6306, -201036, 0, 0, 0, 0), -- Helene Peltskinner
(  6387, -201036, 0, 0, 0, 0), -- Dranh
(  7087, -201036, 0, 0, 0, 0), -- Killian Hagey
(  7088, -201036, 0, 0, 0, 0), -- Thuwd
(  7089, -201036, 0, 0, 0, 0), -- Mooranta
(  8144, -201036, 0, 0, 0, 0), -- Kulleg Stonehorn
(  8777, -201036, 0, 0, 0, 0), -- Seinrick Coulthane
( 12030, -201036, 0, 0, 0, 0), -- Malux
( 16273, -201036, 0, 0, 0, 0), -- Mathreyn
( 16692, -201036, 0, 0, 0, 0), -- Tyn
( 16763, -201036, 0, 0, 0, 0), -- Remere
( 17441, -201036, 0, 0, 0, 0), -- Gurf
( 18755, -201036, 0, 0, 0, 0), -- Moorutu
( 18777, -201036, 0, 0, 0, 0), -- Jelena Nightsky
( 19180, -201036, 0, 0, 0, 0), -- Seymour
( 26913, -201036, 0, 0, 0, 0), -- Frederic Burrhus
( 26963, -201036, 0, 0, 0, 0), -- Roberta Jacks
( 26986, -201036, 0, 0, 0, 0), -- Tiponi Stormwhisper
( 27000, -201036, 0, 0, 0, 0), -- Trapper Jack
( 28696, -201036, 0, 0, 0, 0), -- Derik Marks
( 33641, -201036, 0, 0, 0, 0), -- Irduil
( 33683, -201036, 0, 0, 0, 0), -- Dremm
( 44782, -201036, 0, 0, 0, 0), -- Rento
( 53437, -201036, 0, 0, 0, 0), -- Humbert Tanwell
( 65144, -201036, 0, 0, 0, 0), -- Tapin Wildbeard
( 66981, -201036, 0, 0, 0, 0), -- Trapper Ri
( 67026, -201036, 0, 0, 0, 0), -- Hao of the Stag's Horns
( 85923, -201036, 0, 0, 0, 0), -- Rangari Laandon
( 86028, -201036, 0, 0, 0, 0), -- Kondal Huntsworn
( 93541, -201036, 0, 0, 0, 0), -- Kondal Huntsworn
( 98720, -201036, 0, 0, 0, 0), -- Ske'rit
( 98721, -201036, 0, 0, 0, 0), -- Seymour
( 98722, -201036, 0, 0, 0, 0), -- Agnes
( 98791, -201036, 0, 0, 0, 0), -- Glielle
( 98936, -201036, 0, 0, 0, 0), -- Derik Marks

 -- Skinning spells
(201036,     8613,        10,     0,     0,    5), -- Apprentice Skinning
(201036,     8617,       500,   393,    50,   10), -- Journeyman Skinning    
(201036,     8618,      5000,   393,   125,   20), -- Expert Skinning
(201036,    10768,     50000,   393,   200,   35), -- Artisan Skinning
(201036,    32678,    100000,   393,   275,   50), -- Master Skinning
(201036,    50305,    350000,   393,   350,   65), -- Grand Master Skinning
(201036,    74522,    500000,   393,   425,   80), -- Illustrious Grand Master Skinning
(201036,   102216,    600000,   393,   500,   85); -- Zen Master Skinning

-- Herbalism trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201018 OR `SpellID`= -201018;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
(   812, -201018, 0, 0, 0, 0), -- Alma Jainrose 
(   908, -201018, 0, 0, 0, 0), -- Flora Silverwind
(  1218, -201018, 0, 0, 0, 0), -- Herbalist Pomeroy
(  1458, -201018, 0, 0, 0, 0), -- Telurinon Moonshadow
(  1473, -201018, 0, 0, 0, 0), -- Kali Healtouch
(  2114, -201018, 0, 0, 0, 0), -- Faruza
(  2390, -201018, 0, 0, 0, 0), -- Aranae Venomblood
(  2856, -201018, 0, 0, 0, 0), -- Angrun
(  3013, -201018, 0, 0, 0, 0), -- Komin Winterhoof
(  3185, -201018, 0, 0, 0, 0), -- Mishiki
(  3404, -201018, 0, 0, 0, 0), -- Jandi
(  3604, -201018, 0, 0, 0, 0), -- Malorne Bladeleaf
(  3965, -201018, 0, 0, 0, 0), -- Cylania Rootstalker
(  4204, -201018, 0, 0, 0, 0), -- Firodren Mooncaller
(  4614, -201018, 0, 0, 0, 0), -- Martha Alliestar
(  4898, -201018, 0, 0, 0, 0), -- Brant Jasperbloom
(  4998, -201018, 0, 0, 0, 0), -- World Herbalism Trainer
(  5137, -201018, 0, 0, 0, 0), -- Shylamiir
(  5566, -201018, 0, 0, 0, 0), -- Tannysa
(  8146, -201018, 0, 0, 0, 0), -- Ruw
( 16527, -201018, 0, 0, 0, 0), -- Outland Herbalism Trainer
( 16644, -201018, 0, 0, 0, 0), -- Botanist Nathera
( 16736, -201018, 0, 0, 0, 0), -- Cemmorhan
( 17434, -201018, 0, 0, 0, 0), -- Morae
( 17983, -201018, 0, 0, 0, 0), -- Heur
( 18748, -201018, 0, 0, 0, 0), -- Ruak Stronghorn
( 18776, -201018, 0, 0, 0, 0), -- Rorelien
( 26910, -201018, 0, 0, 0, 0), -- Fayin Whisperleaf
( 26958, -201018, 0, 0, 0, 0), -- Marjory Kains
( 26974, -201018, 0, 0, 0, 0), -- Tansy Wildmane
( 26994, -201018, 0, 0, 0, 0), -- Kirea Moondancer
( 28704, -201018, 0, 0, 0, 0), -- Dorothy Egan
( 33639, -201018, 0, 0, 0, 0), -- Botanist Alaenra
( 33678, -201018, 0, 0, 0, 0), -- Jijia
( 46741, -201018, 0, 0, 0, 0), -- Muraga
( 65141, -201018, 0, 0, 0, 0), -- Survivalist Tylania
( 65877, -201018, 0, 0, 0, 0), -- Han Flowerbloom
( 66980, -201018, 0, 0, 0, 0), -- Grower Miao
( 67025, -201018, 0, 0, 0, 0), -- Orchard Keeper Li Mei
( 84620, -201018, 0, 0, 0, 0), -- Aranae Venomblood
( 85921, -201018, 0, 0, 0, 0), -- Jie Wildblossom
( 86006, -201018, 0, 0, 0, 0), -- Anthony Allain
( 92459, -201018, 0, 0, 0, 0), -- Dorothy Egan
( 92464, -201018, 0, 0, 0, 0), -- Kuhuine Tenderstride
( 98135, -201018, 0, 0, 0, 0), -- Wildcrafter Osme
( 99167, -201018, 0, 0, 0, 0), -- Dorothy Egan
( 99903, -201018, 0, 0, 0, 0), -- Sprig Hashhoof
(110345, -201018, 0, 0, 0, 0), -- Aranae Venomblood

 -- Herbalism spells
(201018,    2366,        100,      0,    0,    5), -- Apprentice Herbalism
(201018,    2368,        500,    182,   50,   10), -- Journeyman Herbalism
(201018,    3570,      25000,    182,  200,   20), -- Artisan Herbalism
(201018,   11993,      10000,    182,  125,   35), -- Expert Herbalism
(201018,   28695,     100000,    182,  275,   50), -- Master Herbalism
(201018,   50300,     150000,    182,  350,   65), -- Grand Master Herbalism
(201018,   74519,     250000,    182,  425,   80), -- Illustrious Grand Master Herbalism
(201018,  110413,     300000,    182,  500,   85); -- Zen Master Herbalism

-- Leatherworking trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201027 OR `SpellID`= -201027;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
( 1385, -201027, 0, 0, 0, 0), -- Brawn 
( 1632, -201027, 0, 0, 0, 0), -- Adele Fielder
( 3007, -201027, 0, 0, 0, 0), -- Una
( 3069, -201027, 0, 0, 0, 0), -- Chaw Stronghide
( 3365, -201027, 0, 0, 0, 0), -- Karolek
( 3549, -201027, 0, 0, 0, 0), -- Shelene Rhobart
( 3605, -201027, 0, 0, 0, 0), -- Nadyia Maneweaver
( 3703, -201027, 0, 0, 0, 0), -- Krulmoo Fullmoon
( 3967, -201027, 0, 0, 0, 0), -- Aayndia Floralwind
( 4212, -201027, 0, 0, 0, 0), -- Telonis
( 4588, -201027, 0, 0, 0, 0), -- Arthur Moore
( 5040, -201027, 0, 0, 0, 0), -- World Leatherworking Trainer
( 5127, -201027, 0, 0, 0, 0), -- Fimble Finespindle
( 5564, -201027, 0, 0, 0, 0), -- Simon Tanner
( 5784, -201027, 0, 0, 0, 0), -- Waldor
( 7866, -201027, 0, 0, 0, 0), -- Peter Galen
( 7867, -201027, 0, 0, 0, 0), -- Thorkaf Dragoneye
( 7868, -201027, 0, 0, 0, 0), -- Sarah Tanner
( 7869, -201027, 0, 0, 0, 0), -- Brumn Winterhoof
( 7870, -201027, 0, 0, 0, 0), -- Caryssia Moonhunter
( 7871, -201027, 0, 0, 0, 0), -- Se'Jib
( 8153, -201027, 0, 0, 0, 0), -- Narv Hidecrafter
(11097, -201027, 0, 0, 0, 0), -- Drakk Stonehand
(11098, -201027, 0, 0, 0, 0), -- Hahrana Ironhide
(16278, -201027, 0, 0, 0, 0), -- Sathein
(16688, -201027, 0, 0, 0, 0), -- Lynalis
(16728, -201027, 0, 0, 0, 0), -- Akham
(17442, -201027, 0, 0, 0, 0), -- Moordo
(18754, -201027, 0, 0, 0, 0), -- Barim Spilthoof
(18771, -201027, 0, 0, 0, 0), -- Brumman
(19187, -201027, 0, 0, 0, 0), -- Darmari
(21087, -201027, 0, 0, 0, 0), -- Grikka
(26911, -201027, 0, 0, 0, 0), -- Bernadette Dexter
(26961, -201027, 0, 0, 0, 0), -- Gunter Hansen
(26996, -201027, 0, 0, 0, 0), -- Awan Iceborn
(26998, -201027, 0, 0, 0, 0), -- Rosemary Bovard
(28400, -201027, 0, 0, 0, 0), -- Northrend Leatherworking Trainer
(28700, -201027, 0, 0, 0, 0), -- Diane Cannings
(29507, -201027, 0, 0, 0, 0), -- Manfred Staller
(29508, -201027, 0, 0, 0, 0), -- Andellion
(29509, -201027, 0, 0, 0, 0), -- Namha Moonwater
(33581, -201027, 0, 0, 0, 0), -- Kul'de
(33635, -201027, 0, 0, 0, 0), -- Daenril
(33681, -201027, 0, 0, 0, 0), -- Korim
(65121, -201027, 0, 0, 0, 0), -- Clean Pelt
(85920, -201027, 0, 0, 0, 0), -- Jistun Sharpfeather
(86032, -201027, 0, 0, 0, 0), -- Burga Stronghide
(93523, -201027, 0, 0, 0, 0), -- Namha Moonwater
(98948, -201027, 0, 0, 0, 0), -- Hrul Sharphoof
(98950, -201027, 0, 0, 0, 0), -- Namha Moonwater
(98958, -201027, 0, 0, 0, 0), -- Andellion
(98964, -201027, 0, 0, 0, 0), -- Celea
(98969, -201027, 0, 0, 0, 0), -- Stalriss Dawnrunner
(99073, -201027, 0, 0, 0, 0), -- Manfred Staller

 -- Leatherworking spells
(201027,     2108,         10,           165,             0,           5), -- Apprentice Leatherworking
(201027,     2153,         50,           165,            15,           5), -- Handstitched Leather Pants
(201027,     3753,         75,           165,            25,           5), -- Handstitched Leather Belt
(201027,     3816,         50,           165,            35,           5), -- Cured Light Hide
(201027,     2160,        100,           165,            40,           5), -- Embossed Leather Vest
(201027,     3104,        500,           165,            50,          10), -- Journeyman Leatherworking
(201027,     2161,        100,           165,            55,           5), -- Embossed Leather Boots
(201027,     3756,        150,           165,            55,           5), -- Embossed Leather Gloves
(201027,   226105,        100,           165,            55,           5), -- Light Scale Gloves
(201027,     2162,        100,           165,            60,           5), -- Embossed Leather Cloak
(201027,     9065,        150,           165,            70,           5), -- Light Leather Bracers
(201027,   226106,        150,           165,            70,           5), -- Light Scale Bracers
(201027,   226107,        150,           165,            70,           5), -- Light Scale Belt
(201027,     3759,        200,           165,            75,           5), -- Embossed Leather Pants
(201027,     3763,        300,           165,            80,          10), -- Fine Leather Belt
(201027,     2159,        250,           165,            85,          10), -- Fine Leather Cloak
(201027,     3761,        350,           165,            85,          10), -- Fine Leather Tunic
(201027,   226108,        350,           165,            85,          10), -- Light Scale Jerkin
(201027,   226114,        350,           165,            85,          10), -- Crackling Scale Breastplate
(201027,   226109,        350,           165,            90,          10), -- Light Scale Boots
(201027,   226110,        350,           165,            90,          10), -- Shamanic Treads
(201027,     9068,        400,           165,            95,          10), -- Light Leather Pants
(201027,   226112,        400,           165,            95,          10), -- Chain Hauberk
(201027,   226113,        400,           165,            95,          10), -- Chain Boots
(201027,     2165,        250,           165,           100,          20), -- Medium Armor Kit
(201027,     2167,        350,           165,           100,          20), -- Dark Leather Boots
(201027,     3817,        200,           165,           100,          20), -- Cured Medium Hide
(201027,    20648,        500,           165,           100,          20), -- Medium Leather
(201027,   226115,        350,           165,           100,          20), -- Blue Chain Leggings
(201027,   226111,        350,           165,           105,          20), -- Light Scale Pants
(201027,   226116,        350,           165,           105,          20), -- Chain Bracers
(201027,     2168,        350,           165,           110,          20), -- Dark Leather Cloak
(201027,   226117,        350,           165,           110,          20), -- Chain Leggings
(201027,     7135,        400,           165,           115,          20), -- Dark Leather Pants
(201027,   226118,        400,           165,           115,          20), -- Chain Gauntlets
(201027,     2166,        450,           165,           120,          20), -- Toughened Leather Armor
(201027,     9074,        500,           165,           120,          20), -- Nimble Leather Gloves
(201027,   226119,        500,           165,           120,          20), -- Chain Belt
(201027,     3766,        400,           165,           125,          20), -- Dark Leather Belt
(201027,     3811,       5000,           165,           125,          20), -- Expert Leatherworking
(201027,     9145,        500,           165,           125,          20), -- Fletcher's Gloves
(201027,   226120,        500,           165,           125,          20), -- Spritescale Epaulets
(201027,     3768,        500,           165,           130,          20), -- Hillman's Shoulders
(201027,   226121,        500,           165,           130,          20), -- Chain Pauldrons
(201027,     3770,        500,           165,           135,          20), -- Toughened Leather Gloves
(201027,   226122,        500,           165,           135,          20), -- Element Grips
(201027,   226123,        500,           165,           140,          20), -- Heavy Scale Gauntlets
(201027,     3764,        500,           165,           145,          20), -- Hillman's Leather Gloves
(201027,     3760,        600,           165,           150,          20), -- Hillman's Cloak
(201027,     3780,        750,           165,           150,          20), -- Heavy Armor Kit
(201027,     3818,        500,           165,           150,          20), -- Cured Heavy Hide
(201027,    20649,       1000,           165,           150,          20), -- Heavy Leather
(201027,   226124,        700,           165,           150,          20), -- Heavy Scale Wraps
(201027,     3774,       1000,           165,           160,          25), -- Green Leather Belt
(201027,     7147,       1000,           165,           160,          25), -- Guardian Pants
(201027,   226127,       1100,           165,           160,          25), -- Spritescale Cinch
(201027,   226128,       1100,           165,           165,          25), -- Heavy Scale Shirt
(201027,   226129,       1100,           165,           165,          25), -- Heavy Scale Pauldrons
(201027,   226130,       1100,           165,           165,          25), -- Spritescale Jerkin
(201027,     7151,       1200,           165,           175,          25), -- Barbaric Shoulders
(201027,     9196,       1500,           165,           175,          25), -- Dusky Leather Armor
(201027,     3776,       1200,           165,           180,          25), -- Green Leather Bracers
(201027,     9198,       2000,           165,           180,          25), -- Frost Leather Cloak
(201027,   226131,       1500,           165,           180,          25), -- Spritescale Gloves
(201027,     9201,       2000,           165,           185,          25), -- Dusky Bracers
(201027,   226132,       1500,           165,           185,          25), -- Heavy Scale Belt
(201027,   226133,       1500,           165,           185,          25), -- Spritescale Wraps
(201027,     6661,       2000,           165,           190,          25), -- Barbaric Harness
(201027,     7156,       2400,           165,           190,          25), -- Guardian Gloves
(201027,   226134,       2400,           165,           190,          25), -- Heavy Scale Boots
(201027,   226135,       2400,           165,           190,          25), -- Heavy Scale Hood
(201027,   226136,       2400,           165,           190,          25), -- Spritescale Circlet
(201027,   226137,       2400,           165,           190,          25), -- Spritescale Boots
(201027,     9206,       2500,           165,           195,          25), -- Dusky Belt
(201027,    10482,       2000,           165,           200,          35), -- Cured Thick Hide
(201027,    10487,       2000,           165,           200,          35), -- Thick Armor Kit
(201027,    10662,      50000,           165,           200,          35), -- Artisan Leatherworking
(201027,    20650,       4000,           165,           200,          35), -- Thick Leather
(201027,    10499,       3000,           165,           205,          35), -- Nightscape Tunic
(201027,    10507,       3000,           165,           205,          35), -- Nightscape Headband
(201027,    10511,       3000,           165,           210,          35), -- Turtle Scale Breastplate
(201027,    10518,       3500,           165,           210,          35), -- Turtle Scale Bracers
(201027,    10548,       4000,           165,           230,          35), -- Nightscape Pants
(201027,    10552,       4000,           165,           230,          35), -- Turtle Scale Helm
(201027,    10630,      10000,           165,           230,          35), -- Gauntlets of the Sea
(201027,    10556,       4500,           165,           235,          35), -- Turtle Scale Leggings
(201027,    10558,       4500,           165,           235,          35), -- Nightscape Boots
(201027,    10632,      10000,           165,           250,          35), -- Helm of Fire
(201027,    10647,      10000,           165,           250,          35), -- Feathered Breastplate
(201027,    10650,      10000,           165,           250,          35), -- Dragonscale Breastplate
(201027,    19047,       5000,           165,           250,          35), -- Cured Rugged Hide
(201027,    19058,       5000,           165,           250,          35), -- Rugged Armor Kit
(201027,    22331,       5000,           165,           250,          35), -- Rugged Leather
(201027,    36074,      10000,           165,           260,          35), -- Blackstorm Leggings
(201027,    36075,      10000,           165,           260,          35), -- Wildfeather Leggings
(201027,    36076,      10000,           165,           260,          35), -- Dragonstrike Leggings
(201027,    19052,      10000,           165,           265,          35), -- Wicked Leather Bracers
(201027,    19055,     100000,           165,           275,          50), -- Master Leatherworking
(201027,    32549,      10000,           165,           275,          50), -- Runic Leather Bracers
(201027,    19071,      10000,           165,           280,          50), -- Wicked Leather Headband
(201027,    19072,      10000,           165,           280,          50), -- Runic Leather Belt
(201027,    24655,      30000,           165,           280,          50), -- Green Dragonscale Gauntlets
(201027,    19082,      15000,           165,           290,          50), -- Runic Leather Headband
(201027,    19083,      15000,           165,           290,          50), -- Wicked Leather Pants
(201027,    19091,      15000,           165,           300,          50), -- Runic Leather Pants
(201027,    19092,      15000,           165,           300,          50), -- Wicked Leather Belt
(201027,    19098,      15000,           165,           300,          50), -- Wicked Leather Armor
(201027,    19102,      15000,           165,           300,          50), -- Runic Leather Armor
(201027,    19103,      15000,           165,           300,          50), -- Runic Leather Shoulders
(201027,    24654,      50000,           165,           300,          50), -- Blue Dragonscale Leggings
(201027,    32454,      10000,           165,           300,          50), -- Knothide Leather
(201027,    32456,      15000,           165,           300,          50), -- Knothide Armor Kit
(201027,    32462,      15000,           165,           300,          50), -- Felscale Gloves
(201027,    32466,      15000,           165,           300,          50), -- Scaled Draenic Pants
(201027,    32470,      15000,           165,           300,          50), -- Thick Draenic Gloves
(201027,    32478,      15000,           165,           300,          50), -- Wild Draenish Boots
(201027,    45100,      15000,           165,           300,          50), -- Leatherworker's Satchel
(201027,   163225,      10000,           165,           300,          50), -- Thick Clefthoof Leather
(201027,   163226,      10000,           165,           300,          50), -- Crystal Infused Leather
(201027,   163228,      10000,           165,           300,          50), -- Fel Scales
(201027,   163229,      10000,           165,           300,          50), -- Fel Hide
(201027,   163230,      10000,           165,           300,          50), -- Nether Dragonscales
(201027,   163231,      10000,           165,           300,          50), -- Cobra Scales
(201027,   163232,      10000,           165,           300,          50), -- Wind Scales
(201027,    32463,      18000,           165,           310,          50), -- Felscale Boots
(201027,    32467,      18000,           165,           310,          50), -- Scaled Draenic Gloves
(201027,    32479,      18000,           165,           310,          50), -- Wild Draenish Gloves
(201027,    32471,      18000,           165,           315,          50), -- Thick Draenic Pants
(201027,    32464,      20000,           165,           320,          50), -- Felscale Pants
(201027,    32472,      20000,           165,           320,          50), -- Thick Draenic Boots
(201027,    32480,      20000,           165,           320,          50), -- Wild Draenish Leggings
(201027,    32455,      20000,           165,           325,          50), -- Heavy Knothide Leather
(201027,    32468,      20000,           165,           325,          50), -- Scaled Draenic Vest
(201027,    32473,      25000,           165,           330,          50), -- Thick Draenic Vest
(201027,    32481,      25000,           165,           330,          50), -- Wild Draenish Vest
(201027,    36077,      40000,           165,           330,          50), -- Primalstorm Breastplate
(201027,    36078,      40000,           165,           330,          50), -- Living Crystal Breastplate
(201027,    36079,      40000,           165,           330,          50), -- Golden Dragonstrike Breastplate
(201027,    32465,      25000,           165,           335,          50), -- Felscale Breastplate
(201027,    32469,      25000,           165,           335,          50), -- Scaled Draenic Boots
(201027,    35540,      20000,           165,           340,          50), -- Drums of War
(201027,    44770,      50000,           165,           350,          65), -- Glove Reinforcements
(201027,    44970,      50000,           165,           350,          65), -- Heavy Knothide Armor Kit
(201027,    50962,      50000,           165,           350,          65), -- Borean Armor Kit
(201027,    51302,     350000,           165,           350,          65), -- Grand Master Leatherworking
(201027,    64661,      50000,           165,           350,          65), -- Borean Leather
(201027,   163222,      50000,           165,           350,          65), -- Icy Dragonscale
(201027,   163223,      50000,           165,           350,          65), -- Nerubian Chitin
(201027,   163224,      50000,           165,           350,          65), -- Jormungar Scale
(201027,    50939,      30000,           165,           370,          65), -- Iceborne Leggings
(201027,    50941,      30000,           165,           370,          65), -- Iceborne Gloves
(201027,    50944,      30000,           165,           370,          65), -- Arctic Chestpiece
(201027,    50948,      30000,           165,           370,          65), -- Arctic Boots
(201027,    50951,      30000,           165,           370,          65), -- Frostscale Leggings
(201027,    50955,      30000,           165,           370,          65), -- Frostscale Belt
(201027,    50957,      30000,           165,           370,          65), -- Nerubian Legguards
(201027,    50959,      30000,           165,           370,          65), -- Nerubian Gloves
(201027,    50938,      30000,           165,           375,          65), -- Iceborne Chestguard
(201027,    50942,      30000,           165,           375,          65), -- Iceborne Boots
(201027,    50945,      30000,           165,           375,          65), -- Arctic Leggings
(201027,    50947,      30000,           165,           375,          65), -- Arctic Gloves
(201027,    50950,      30000,           165,           375,          65), -- Frostscale Chestguard
(201027,    50952,      30000,           165,           375,          65), -- Frostscale Shoulders
(201027,    50956,      30000,           165,           375,          65), -- Nerubian Chestguard
(201027,    50961,      30000,           165,           375,          65), -- Nerubian Belt
(201027,    50940,      30000,           165,           380,          65), -- Iceborne Shoulderpads
(201027,    50943,      30000,           165,           380,          65), -- Iceborne Belt
(201027,    50946,      30000,           165,           380,          65), -- Arctic Shoulderpads
(201027,    50949,      30000,           165,           380,          65), -- Arctic Belt
(201027,    50953,      30000,           165,           380,          65), -- Frostscale Gloves
(201027,    50954,      30000,           165,           380,          65), -- Frostscale Boots
(201027,    50958,      30000,           165,           380,          65), -- Nerubian Shoulders
(201027,    50960,      30000,           165,           380,          65), -- Nerubian Boots
(201027,    60631,      80000,           165,           380,          65), -- Cloak of Harsh Winds
(201027,    51571,      30000,           165,           385,          65), -- Arctic Wristguards
(201027,    51572,      30000,           165,           385,          65), -- Arctic Helm
(201027,    60599,      30000,           165,           385,          65), -- Frostscale Bracers
(201027,    60600,      30000,           165,           385,          65), -- Frostscale Helm
(201027,    60607,      30000,           165,           385,          65), -- Iceborne Wristguards
(201027,    60608,      30000,           165,           385,          65), -- Iceborne Helm
(201027,    60622,      30000,           165,           385,          65), -- Nerubian Bracers
(201027,    60624,      30000,           165,           385,          65), -- Nerubian Helm
(201027,    50936,      80000,           165,           390,          65), -- Heavy Borean Leather
(201027,    50963,      80000,           165,           395,          65), -- Heavy Borean Armor Kit
(201027,    51569,      80000,           165,           395,          65), -- Dark Arctic Leggings
(201027,    51570,      80000,           165,           395,          65), -- Dark Arctic Chestpiece
(201027,    55199,      80000,           165,           395,          65), -- Cloak of Tormented Skies
(201027,    60601,      80000,           165,           395,          65), -- Dark Frostscale Leggings
(201027,    60604,      80000,           165,           395,          65), -- Dark Frostscale Breastplate
(201027,    60611,      80000,           165,           395,          65), -- Dark Iceborne Leggings
(201027,    60613,      80000,           165,           395,          65), -- Dark Iceborne Chestguard
(201027,    60627,      80000,           165,           395,          65), -- Dark Nerubian Leggings
(201027,    60629,      80000,           165,           395,          65), -- Dark Nerubian Chestpiece
(201027,    50966,      50000,           165,           400,          65), -- Nerubian Leg Armor
(201027,    51568,     100000,           165,           400,          65), -- Black Chitinguard Boots
(201027,    60605,     100000,           165,           400,          65), -- Dragonstompers
(201027,    60620,     100000,           165,           400,          65), -- Bugsquashers
(201027,    60630,      80000,           165,           400,          65), -- Scaled Icewalkers
(201027,    50964,      50000,           165,           405,          65), -- Jormungar Leg Armor
(201027,    60643,      50000,           165,           415,          65), -- Pack of Endless Pockets
(201027,    60651,     100000,           165,           420,          65), -- Virulent Spaulders
(201027,    60652,     100000,           165,           420,          65), -- Eaglebane Bracers
(201027,    60658,     200000,           165,           420,          65), -- Nightshock Girdle
(201027,    60665,     100000,           165,           420,          65), -- Seafoam Gauntlets
(201027,    60666,      80000,           165,           420,          65), -- Jormscale Footpads
(201027,    60671,     100000,           165,           420,          65), -- Purehorn Spaulders
(201027,    50965,      80000,           165,           425,          80), -- Frosthide Leg Armor
(201027,    50967,      80000,           165,           425,          80), -- Icescale Leg Armor
(201027,    60649,     100000,           165,           425,          80), -- Razorstrike Breastplate
(201027,    60655,     200000,           165,           425,          80), -- Nightshock Hood
(201027,    60660,     100000,           165,           425,          80), -- Leggings of Visceral Strikes
(201027,    60669,     100000,           165,           425,          80), -- Wildscale Breastplate
(201027,    62448,      80000,           165,           425,          80), -- Earthen Leg Armor
(201027,    78379,      75000,           165,           425,          80), -- Savage Armor Kit
(201027,    81199,     500000,           165,           425,          80), -- Illustrious Grand Master Leatherworking
(201027,    84950,      75000,           165,           425,          80), -- Savage Leather
(201027,   163216,      75000,           165,           425,          80), -- Blackened Dragonscale
(201027,   163218,      75000,           165,           425,          80), -- Deepsea Scale
(201027,    60637,     200000,           165,           440,          80), -- Ice Striker's Cloak
(201027,    60640,     200000,           165,           440,          80), -- Durable Nerubhide Cape
(201027,    69386,     200000,           165,           450,          80), -- Drums of Forgotten Kings
(201027,    69388,     200000,           165,           450,          80), -- Drums of the Wild
(201027,    78398,      75000,           165,           450,          80), -- Darkbrand Bracers
(201027,    78410,      75000,           165,           450,          80), -- Tsunami Boots
(201027,    78415,      75000,           165,           455,          80), -- Tsunami Shoulders
(201027,    78416,      75000,           165,           455,          80), -- Darkbrand Belt
(201027,    78380,      75000,           165,           460,          80), -- Savage Cloak
(201027,    78388,      75000,           165,           460,          80), -- Tsunami Bracers
(201027,    78399,      75000,           165,           465,          80), -- Darkbrand Gloves
(201027,    78407,      75000,           165,           465,          80), -- Darkbrand Boots
(201027,    78396,      75000,           165,           470,          80), -- Tsunami Belt
(201027,    78405,      75000,           165,           470,          80), -- Hardened Scale Cloak
(201027,    78406,      85000,           165,           475,          80), -- Tsunami Gloves
(201027,    78411,      85000,           165,           475,          80), -- Darkbrand Shoulders
(201027,    78419,      85000,           165,           475,          80), -- Scorched Leg Armor
(201027,    78420,      85000,           165,           480,          80), -- Twilight Leg Armor
(201027,    78427,      85000,           165,           480,          80), -- Tsunami Leggings
(201027,    78428,      85000,           165,           480,          80), -- Darkbrand Chestguard
(201027,    78432,      85000,           165,           485,          80), -- Tsunami Helm
(201027,    78433,      85000,           165,           485,          80), -- Darkbrand Leggings
(201027,    78436,      85000,           165,           485,          80), -- Heavy Savage Leather
(201027,    78437,      85000,           165,           485,          80), -- Heavy Savage Armor Kit
(201027,    78423,      85000,           165,           490,          80), -- Tsunami Chestguard
(201027,    78424,      85000,           165,           490,          80), -- Darkbrand Helm
(201027,    78438,      85000,           165,           495,          80), -- Cloak of Beasts
(201027,    78439,      85000,           165,           495,          80), -- Cloak of War
(201027,    99535,     100000,           165,           500,          85), -- Vicious Hide Cloak
(201027,    99536,     100000,           165,           500,          85), -- Vicious Fur Cloak
(201027,   110423,     600000,           165,           500,          85), -- Zen Master Leatherworking
(201027,   124627,      50000,           165,           500,          85), -- Exotic Leather
(201027,   163220,      50000,           165,           500,          85), -- Prismatic Scale
(201027,   124577,      50000,           165,           525,          85), -- Misthide Boots
(201027,   124584,      50000,           165,           525,          85), -- Stormscale Bracers
(201027,   124628,      50000,           165,           525,          85), -- Sha Armor Kit
(201027,   124576,      50000,           165,           530,          85), -- Misthide Bracers
(201027,   124586,      50000,           165,           530,          85), -- Stormscale Belt
(201027,   124126,      50000,           165,           535,          85), -- Brutal Leg Armor
(201027,   124578,      50000,           165,           535,          85), -- Misthide Belt
(201027,   124585,      50000,           165,           535,          85), -- Stormscale Boots
(201027,   124572,      50000,           165,           540,          85), -- Misthide Shoulders
(201027,   124574,      50000,           165,           540,          85), -- Misthide Gloves
(201027,   124582,      50000,           165,           540,          85), -- Stormscale Gloves
(201027,   124124,      50000,           165,           545,          85), -- Sha-Touched Leg Armor
(201027,   124580,      50000,           165,           545,          85), -- Stormscale Shoulders
(201027,   124575,      50000,           165,           550,          85), -- Misthide Leggings
(201027,   124579,      50000,           165,           550,          85), -- Stormscale Helm
(201027,   124636,      50000,           165,           550,          85), -- Stormscale Drape
(201027,   131865,      50000,           165,           550,          85), -- Magnificent Hide
(201027,   124125,      50000,           165,           555,          85), -- Toughened Leg Armor
(201027,   124571,      50000,           165,           555,          85), -- Misthide Helm
(201027,   124581,      50000,           165,           555,          85), -- Stormscale Chestguard
(201027,   124635,      50000,           165,           555,          85), -- Misthide Drape
(201027,   124573,      50000,           165,           560,          85), -- Misthide Chestguard
(201027,   124583,      50000,           165,           560,          85), -- Stormscale Leggings
(201027,   124637,      50000,           165,           560,          85); -- Quick Strike Cloak

-- Alchemy trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201001 OR `SpellID`= -201001;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
(  1215, -201001, 0, 0, 0, 0), -- Alchemist Mallory
(  1386, -201001, 0, 0, 0, 0), -- Rogvar
(  1470, -201001, 0, 0, 0, 0), -- Ghak Healtouch
(  2132, -201001, 0, 0, 0, 0), -- Carolai Anise
(  2391, -201001, 0, 0, 0, 0), -- Serge Hinott
(  3009, -201001, 0, 0, 0, 0), -- Jaxin Chong
(  1632, -201001, 0, 0, 0, 0), -- Bena Winterhoof
(  3184, -201001, 0, 0, 0, 0), -- Miao'zan
(  3347, -201001, 0, 0, 0, 0), -- Yelmak
(  3603, -201001, 0, 0, 0, 0), -- Cyndra Kindwhisper
(  3964, -201001, 0, 0, 0, 0), -- Kylanna
(  4160, -201001, 0, 0, 0, 0), -- Ainethil
(  4611, -201001, 0, 0, 0, 0), -- Doctor Herbert Halsey
(  4900, -201001, 0, 0, 0, 0), -- Alchemist Narett
(  5032, -201001, 0, 0, 0, 0), -- World Alchemy Trainer
(  5177, -201001, 0, 0, 0, 0), -- Tally Berryfizz
(  5499, -201001, 0, 0, 0, 0), -- Lilyssia Nightbreeze
(  7948, -201001, 0, 0, 0, 0), -- Kylanna Windwhisper
( 12020, -201001, 0, 0, 0, 0), -- Moonglade Alchemy Trainer
( 16161, -201001, 0, 0, 0, 0), -- Arcanist Sheynathren
( 16487, -201001, 0, 0, 0, 0), -- Master Alchemist
( 16588, -201001, 0, 0, 0, 0), -- Apothecary Antonivich
( 16642, -201001, 0, 0, 0, 0), -- Camberon
( 16723, -201001, 0, 0, 0, 0), -- Lucc
( 17215, -201001, 0, 0, 0, 0), -- Daedal
( 18802, -201001, 0, 0, 0, 0), -- Alchemist Gribble
( 19052, -201001, 0, 0, 0, 0), -- Lorokeem
( 26903, -201001, 0, 0, 0, 0), -- Lanolis Dewdrop
( 26951, -201001, 0, 0, 0, 0), -- Wilhelmina Renel
( 26975, -201001, 0, 0, 0, 0), -- Arthur Henslowe
( 26987, -201001, 0, 0, 0, 0), -- Falorn Nightwhisper
( 27023, -201001, 0, 0, 0, 0), -- Apothecary Bressa
( 27029, -201001, 0, 0, 0, 0), -- Apothecary Wormwick
( 28703, -201001, 0, 0, 0, 0), -- Linzy Blackbolt
( 33588, -201001, 0, 0, 0, 0), -- Crystal Brightspark
( 33630, -201001, 0, 0, 0, 0), -- Aelthin
( 33674, -201001, 0, 0, 0, 0), -- Alchemist Kanhu
( 65186, -201001, 0, 0, 0, 0), -- Poisoncrafter Kil'zit
( 84615, -201001, 0, 0, 0, 0), -- Serge Hinott
( 85905, -201001, 0, 0, 0, 0), -- Jaiden Trask
( 86009, -201001, 0, 0, 0, 0), -- Kristoph Cossey
( 92456, -201001, 0, 0, 0, 0), -- Linzy Blackbolt
( 92458, -201001, 0, 0, 0, 0), -- Deucus Valdera
( 95782, -201001, 0, 0, 0, 0), -- Deucus Valdera
( 97609, -201001, 0, 0, 0, 0), -- Serge Hinott
( 99157, -201001, 0, 0, 0, 0), -- Linzy Blackbolt
( 113372, -201001, 0, 0, 0, 0), -- Deucus Valdera

(201001,     2259,         10,           171,             0,           5), -- Apprentice Alchemy
(201001,     3170,         50,           171,            15,           5), -- Weak Troll's Blood Elixir
(201001,     2331,        100,           171,            20,           5), -- Minor Mana Potion
(201001,     2332,        150,           171,            40,           5), -- Minor Rejuvenation Potion
(201001,     3101,        500,           171,            50,           5), -- Journeyman Alchemy
(201001,     2334,        250,           171,            50,           5), -- Elixir of Minor Fortitude
(201001,     2337,       1000,           171,            55,           5), -- Lesser Healing Potion
(201001,     7836,        250,           171,            80,          10), -- Blackmouth Oil
(201001,     7179,        450,           171,            90,          10), -- Elixir of Water Breathing
(201001,     3171,        500,           171,            90,          10), -- Elixir of Wisdom
(201001,     7841,       1000,           171,           100,          10), -- Swim Speed Potion
(201001,     3173,       1500,           171,           120,          10), -- Healing Potion
(201001,     3447,       4000,           171,           110,          10), -- Lesser Mana Potion
(201001,     3464,       5000,           171,           125,          20), -- Expert Alchemy
(201001,     3176,       1500,           171,           125,          20), -- Strong Troll's Blood Elixir
(201001,     7837,       1000,           171,           130,          20), -- Fire Oil
(201001,     3177,       2000,           171,           130,          20), -- Elixir of Defense
(201001,    63732,       2000,           171,           135,          20), -- Elixir of Minor Accuracy
(201001,     7845,       3000,           171,           140,          20), -- Elixir of Firepower
(201001,     7181,       5000,           171,           155,          20), -- Greater Healing Potion
(201001,     3452,       5000,           171,           160,          20), -- Mana Potion
(201001,     3448,       5000,           171,           165,          20), -- Lesser Invisibility Potion
(201001,     3449,       5000,           171,           165,          20), -- Shadow Oil
(201001,     3450,       6000,           171,           175,          20), -- Elixir of Fortitude
(201001,    11449,       6500,           171,           185,          20), -- Elixir of Agility
(201001,    11450,       7500,           171,           195,          20), -- Elixir of Greater Defense
(201001,    11611,      50000,           171,           200,          35), -- Artisan Alchemy
(201001,    12609,       8000,           171,           200,          35), -- Catseye Elixir
(201001,    11448,       9000,           171,           205,          35), -- Greater Mana Potion
(201001,    11451,       8000,           171,           205,          35), -- Oil of Immolation
(201001,    22808,      10000,           171,           215,          35), -- Elixir of Greater Water Breathing
(201001,    11457,      10000,           171,           215,          35), -- Superior Healing Potion
(201001,    15833,      10000,           171,           230,          35), -- Dreamless Sleep Potion
(201001,    11460,       5000,           171,           230,          35), -- Elixir of Detect Undead
(201001,    11461,      10000,           171,           235,          35), -- Arcane Elixir
(201001,    11465,      12000,           171,           235,          35), -- Elixir of Greater Intellect
(201001,    11467,      12000,           171,           240,          35), -- Elixir of Greater Agility
(201001,    17551,      15000,           171,           250,          35), -- Stonescale Oil
(201001,    11478,      14000,           171,           250,          35), -- Elixir of Detect Demon
(201001,    17552,      15000,           171,           255,          35), -- Mighty Rage Potion
(201001,    17553,      15000,           171,           260,          35), -- Superior Mana Potion
(201001,    17555,      15000,           171,           270,          35), -- Elixir of the Sages
(201001,    28596,     100000,           171,           275,          50), -- Master Alchemy
(201001,    17557,      20000,           171,           275,          50), -- Elixir of Brute Force
(201001,    17556,      20000,           171,           275,          50), -- Major Healing Potion
(201001,    17573,      20000,           171,           285,          50), -- Greater Arcane Elixir
(201001,    17572,      20000,           171,           285,          50), -- Purification Potion
(201001,   114786,      20000,           171,           300,          50), -- Alchemist's Flask
(201001,    33740,      20000,           171,           300,          50), -- Adept's Elixir
(201001,    33738,      20000,           171,           300,          50), -- Onslaught Elixir
(201001,    33732,      20000,           171,           300,          50), -- Volatile Healing Potion
(201001,    28544,      25000,           171,           305,          50), -- Elixir of Major Strength
(201001,    28545,      25000,           171,           310,          50), -- Elixir of Healing Power
(201001,    39636,      25000,           171,           310,          50), -- Elixir of Major Fortitude
(201001,    33733,      25000,           171,           310,          50), -- Unstable Mana Potion
(201001,    33741,      30000,           171,           315,          50), -- Elixir of Mastery
(201001,    39638,      30000,           171,           320,          50), -- Elixir of Draenic Wisdom
(201001,    45061,      35000,           171,           325,          50), -- Mad Alchemist's Potion
(201001,    38070,      20000,           171,           325,          50), -- Mercurial Stone
(201001,    28551,      50000,           171,           325,          50), -- Super Healing Potion
(201001,    51304,     350000,           171,           350,          65), -- Grand Master Alchemy
(201001,    53838,      40000,           171,           350,          65), -- Resurgent Healing Potion
(201001,    53841,      40000,           171,           355,          65), -- Wrath Elixir
(201001,    53839,      40000,           171,           360,          65), -- Icy Mana Potion
(201001,    53842,      40000,           171,           365,          65), -- Spellpower Elixir
(201001,    62409,      60000,           171,           375,          65), -- Ethereal Oil
(201001,    53848,      60000,           171,           375,          65), -- Guru's Elixir
(201001,    53899,      60000,           171,           375,          65), -- Lesser Flask of Toughness
(201001,    53812,      60000,           171,           375,          65), -- Pygmy Oil
(201001,    53900,     120000,           171,           380,          65), -- Potion of Nightmares
(201001,    54218,     120000,           171,           385,          65), -- Elixir of Mighty Strength
(201001,    53847,      65000,           171,           385,          65), -- Elixir of Spirit
(201001,    53898,     120000,           171,           390,          65), -- Elixir of Mighty Fortitude
(201001,    53840,     120000,           171,           395,          65), -- Elixir of Mighty Agility
(201001,    60367,     120000,           171,           395,          65), -- Elixir of Mighty Thoughts
(201001,    53905,     120000,           171,           395,          65), -- Indestructible Potion
(201001,    60350,     150000,           171,           395,          65), -- Transmute: Titanium
(201001,    60893,     200000,           171,           400,          65), -- Northrend Alchemy Research
(201001,    60403,     200000,           171,           400,          65), -- Indestructible Alchemist Stone
(201001,    60396,     200000,           171,           400,          65), -- Mercurial Alchemist Stone
(201001,    60405,     200000,           171,           400,          65), -- Mighty Alchemist Stone
(201001,    53836,     150000,           171,           405,          65), -- Runic Healing Potion
(201001,    58871,     150000,           171,           410,          65), -- Endless Healing Potion
(201001,    58868,     150000,           171,           410,          65), -- Endless Mana Potion
(201001,    53837,     150000,           171,           410,          65), -- Runic Mana Potion
(201001,    80731,     500000,           171,           425,          80), -- Illustrious Grand Master Alchemy
(201001,    57427,     150000,           171,           425,          80), -- Transmute: Earthsiege Diamond
(201001,    93935,     150000,           171,           425,          80), -- Draught of War
(201001,    57425,     150000,           171,           430,          80), -- Transmute: Skyflare Diamond
(201001,    53903,     180000,           171,           435,          80), -- Flask of Endless Rage
(201001,    54213,     150000,           171,           435,          80), -- Flask of Pure Mojo
(201001,    53902,     150000,           171,           435,          80), -- Flask of Stoneblood
(201001,    53901,     180000,           171,           435,          80), -- Flask of the Frost Wyrm
(201001,    66658,     200000,           171,           450,          80), -- Transmute: Ametrine
(201001,    66662,     200000,           171,           450,          80), -- Transmute: Dreadstone
(201001,    66664,     200000,           171,           450,          80), -- Transmute: Eye of Zul
(201001,    66660,     200000,           171,           450,          80), -- Transmute: King's Amber
(201001,    66663,     200000,           171,           450,          80), -- Transmute: Majestic Zircon
(201001,    80478,     150000,           171,           450,          80), -- Earthen Potion
(201001,    80477,     150000,           171,           450,          80), -- Ghost Elixir
(201001,    80479,     150000,           171,           455,          80), -- Deathblood Venom
(201001,    80480,     150000,           171,           455,          80), -- Elixir of the Naga
(201001,    80481,     160000,           171,           460,          80), -- Volcanic Potion
(201001,    80269,     160000,           171,           460,          80), -- Potion of Illusion
(201001,    80484,     160000,           171,           465,          80), -- Elixir of the Cobra
(201001,    80482,     160000,           171,           465,          80), -- Potion of Concentration
(201001,    80486,     160000,           171,           470,          80), -- Deepstone Oil
(201001,    80487,     160000,           171,           470,          80), -- Mysterious Potion
(201001,    80488,     160000,           171,           475,          80), -- Elixir of Deep Earth
(201001,    80490,     160000,           171,           475,          80), -- Mighty Rejuvenation Potion
(201001,    80491,     175000,           171,           480,          80), -- Elixir of Impossible Accuracy
(201001,    80492,     175000,           171,           480,          80), -- Prismatic Elixir
(201001,    80494,     175000,           171,           485,          80), -- Mythical Mana Potion
(201001,    80495,     175000,           171,           485,          80), -- Potion of the Tol'vir
(201001,    78866,     175000,           171,           485,          80), -- Transmute: Living Elements
(201001,    80493,     175000,           171,           490,          80), -- Elixir of Mighty Speed
(201001,    80496,     175000,           171,           490,          80), -- Golemblood Potion
(201001,    80497,     175000,           171,           495,          80), -- Elixir of the Master
(201001,    80498,     175000,           171,           495,          80), -- Mythical Healing Potion
(201001,   105206,     600000,           171,           500,          85), -- Zen Master Alchemy
(201001,    94162,     200000,           171,           500,          85), -- Flask of Flowing Water
(201001,    80719,     200000,           171,           500,          85), -- Flask of Steelskin
(201001,    80508,     100000,           171,           500,          85), -- Lifebound Alchemist Stone
(201001,    96253,     100000,           171,           500,          85), -- Quicksilver Alchemist Stone
(201001,    96254,     100000,           171,           500,          85), -- Vibrant Alchemist Stone
(201001,    96252,     100000,           171,           500,          85), -- Volatile Alchemist Stone
(201001,   136197,     100000,           171,           500,          85), -- Zen Alchemist Stone
(201001,   114751,     200000,           171,           500,          85), -- Alchemist's Rejuvenation
(201001,   114752,     200000,           171,           500,          85), -- Master Healing Potion
(201001,    80251,     200000,           171,           505,          85), -- Transmute: Dream Emerald
(201001,    80720,     200000,           171,           505,          85), -- Flask of the Draconic Mind
(201001,    80250,     200000,           171,           510,          85), -- Transmute: Ember Topaz
(201001,    80721,     200000,           171,           510,          85), -- Flask of the Winds
(201001,    80723,     200000,           171,           510,          85), -- Flask of Titanic Strength
(201001,    80248,     200000,           171,           515,          85), -- Transmute: Demonseye
(201001,    80246,     200000,           171,           515,          85), -- Transmute: Ocean Sapphire
(201001,    80247,     200000,           171,           520,          85), -- Transmute: Amberjewel
(201001,    80244,     200000,           171,           520,          85), -- Transmute: Pyrium Bar
(201001,    80245,     250000,           171,           525,          85), -- Transmute: Inferno Ruby
(201001,    80237,     250000,           171,           525,          85), -- Transmute: Shadowspirit Diamond
(201001,    80243,     250000,           171,           525,          85), -- Transmute: Truegold
(201001,    80725,     250000,           171,           525,          85), -- Potion of Deepholm
(201001,    80726,     250000,           171,           525,          85); -- Potion of Treasure Finding

-- Inscription trainers
DELETE FROM `npc_trainer` WHERE `ID`= 201021 OR `SpellID`= -201021;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
( 25263, -201021, 0, 0, 0, 0), -- World Inscription Trainer
( 26916, -201021, 0, 0, 0, 0), -- Mindri Dinkles
( 26959, -201021, 0, 0, 0, 0), -- Booker Kells
( 26977, -201021, 0, 0, 0, 0), -- Adelene Sunlance
( 26995, -201021, 0, 0, 0, 0), -- Tink Brightbolt
( 28702, -201021, 0, 0, 0, 0), -- Professor Pallin
( 30706, -201021, 0, 0, 0, 0), -- Jo'mah
( 30709, -201021, 0, 0, 0, 0), -- Poshken Hardbinder
( 30710, -201021, 0, 0, 0, 0), -- Zantasia
( 30711, -201021, 0, 0, 0, 0), -- Margaux Parchley
( 30713, -201021, 0, 0, 0, 0), -- Catarina Stanford
( 30715, -201021, 0, 0, 0, 0), -- Feyden Darkin
( 30716, -201021, 0, 0, 0, 0), -- Thoth
( 30717, -201021, 0, 0, 0, 0), -- Elise Brightletter
( 30721, -201021, 0, 0, 0, 0), -- Michael Schwan
( 30722, -201021, 0, 0, 0, 0), -- Neferatti
( 33603, -201021, 0, 0, 0, 0), -- Arthur Denny
( 33638, -201021, 0, 0, 0, 0), -- Scribe Lanloer
( 33679, -201021, 0, 0, 0, 0), -- Recorder Lidio
( 46716, -201021, 0, 0, 0, 0), -- Nerog
( 56065, -201021, 0, 0, 0, 0), -- Inkmaster Wei
( 62327, -201021, 0, 0, 0, 0), -- Scribe Rinji
( 64691, -201021, 0, 0, 0, 0), -- Lorewalker Huynh
( 85911, -201021, 0, 0, 0, 0), -- Scribe Chi-Yuan
( 86015, -201021, 0, 0, 0, 0), -- Joro'man
( 92195, -201021, 0, 0, 0, 0), -- Professor Pallin
( 99169, -201021, 0, 0, 0, 0), -- Professor Pallin



(201021,    45357,         10,           773,             0,           5), -- Apprentice Inscription
(201021,    52843,         50,           773,             1,           5), -- Moonglow Ink
(201021,    58472,         50,           773,            15,           5), -- Scroll of Agility
(201021,    58484,         50,           773,            15,           5), -- Scroll of Strength
(201021,    48248,         50,           773,            35,           5), -- Scroll of Recall
(201021,    52739,        150,           773,            35,           5), -- Enchanting Vellum
(201021,    45358,        500,           773,            50,           5), -- Journeyman Inscription
(201021,    53462,        300,           773,            75,          10), -- Midnight Ink
(201021,    50598,        400,           773,            75,          10), -- Scroll of Intellect II
(201021,    50612,        400,           773,            75,          10), -- Scroll of Stamina II
(201021,    50605,        400,           773,            75,          10), -- Scroll of Versatility II
(201021,    92026,        400,           773,            75,          10), -- Vanishing Powder
(201021,    58485,        400,           773,            80,          10), -- Scroll of Strength II
(201021,    57703,        400,           773,            85,          10), -- Hunter's Ink
(201021,    58473,        400,           773,            85,          10), -- Scroll of Agility II
(201021,    58565,        500,           773,            85,          10), -- Mystic Tome
(201021,    48247,        500,           773,            85,          10), -- Mysterious Tarot
(201021,    57704,        400,           773,           100,          10), -- Lion's Ink
(201021,    45359,        500,           773,           125,          20), -- Expert Inscription
(201021,    57706,        750,           773,           125,          20), -- Dawnstar Ink
(201021,    59478,        750,           773,           125,          20), -- Book of Survival
(201021,    59475,        750,           773,           125,          20), -- Tome of the Dawn
(201021,    59480,        750,           773,           125,          20), -- Strange Tarot
(201021,    57707,        750,           773,           150,          20), -- Jadefire Ink
(201021,    50614,        750,           773,           155,          20), -- Scroll of Stamina III
(201021,    50606,        750,           773,           155,          20), -- Scroll of Versatility III
(201021,    50599,        750,           773,           165,          20), -- Scroll of Intellect III
(201021,    58486,        750,           773,           170,          20), -- Scroll of Strength III
(201021,    57708,        750,           773,           175,          20), -- Royal Ink
(201021,    58476,        750,           773,           175,          20), -- Scroll of Agility III
(201021,    59486,        750,           773,           175,          20), -- Royal Guide of Escape Routes
(201021,    59484,        750,           773,           175,          20), -- Tome of Kings
(201021,    59487,        750,           773,           175,          20), -- Arcane Tarot
(201021,    45360,      50000,           773,           200,          35), -- Artisan Inscription
(201021,    57709,       3000,           773,           200,          35), -- Celestial Ink
(201021,    59387,       3000,           773,           200,          35), -- Certificate of Ownership
(201021,    60336,       3000,           773,           200,          35), -- Scroll of Recall II
(201021,    50616,       4500,           773,           205,          35), -- Scroll of Stamina IV
(201021,    50607,       4500,           773,           210,          35), -- Scroll of Versatility IV
(201021,    50600,       4500,           773,           215,          35), -- Scroll of Intellect IV
(201021,    58487,       4500,           773,           220,          35), -- Scroll of Strength IV
(201021,    57710,       6000,           773,           225,          35), -- Fiery Ink
(201021,    58478,       4500,           773,           225,          35), -- Scroll of Agility IV
(201021,    59490,       6000,           773,           225,          35), -- Book of Stars
(201021,    59489,       6000,           773,           225,          35), -- Fire Eater's Guide
(201021,    59491,       6000,           773,           225,          35), -- Shadowy Tarot
(201021,    57711,      10000,           773,           250,          35), -- Shimmering Ink
(201021,    50617,      10000,           773,           250,          35), -- Scroll of Stamina V
(201021,    50608,      10000,           773,           255,          35), -- Scroll of Versatility V
(201021,    50601,      10000,           773,           260,          35), -- Scroll of Intellect V
(201021,    58488,      10000,           773,           270,          35), -- Scroll of Strength V
(201021,    58480,      10000,           773,           250,          35), -- Scroll of Agility V
(201021,    45361,     100000,           773,           275,          50), -- Master Inscription
(201021,    59502,      10000,           773,           275,          50), -- Darkmoon Card
(201021,    59494,      10000,           773,           275,          50), -- Manual of Clouds
(201021,    59493,      10000,           773,           275,          50), -- Stormbound Tome
(201021,    57712,      10000,           773,           275,          50), -- Ink of the Sky
(201021,    57713,      20000,           773,           290,          50), -- Ethereal Ink
(201021,    50618,      20000,           773,           290,          50), -- Scroll of Stamina VI
(201021,    50609,      20000,           773,           295,          50), -- Scroll of Versatility VI
(201021,    50602,      20000,           773,           300,          50), -- Scroll of Intellect VI
(201021,    58489,      20000,           773,           305,          50), -- Scroll of Strength VI
(201021,    58481,      20000,           773,           310,          50), -- Scroll of Agility VI
(201021,    57714,      20000,           773,           325,          50), -- Darkflame Ink
(201021,    59496,      20000,           773,           325,          50), -- Book of Clever Tricks
(201021,    59495,      20000,           773,           325,          50), -- Hellfire Tome
(201021,    59503,      20000,           773,           325,          50), -- Greater Darkmoon Card
(201021,    45363,     350000,           773,           350,          65), -- Grand Master Inscription
(201021,    57715,      50000,           773,           350,          65), -- Ink of the Sea
(201021,    60337,      50000,           773,           350,          65), -- Scroll of Recall III
(201021,    50619,      50000,           773,           350,          65), -- Scroll of Stamina VII
(201021,    64053,      50000,           773,           350,          65), -- Twilight Tome
(201021,    50610,      50000,           773,           355,          65), -- Scroll of Versatility VII
(201021,    50603,      50000,           773,           360,          65), -- Scroll of Intellect VII
(201021,    58490,      50000,           773,           365,          65), -- Scroll of Strength VII
(201021,    58482,      50000,           773,           370,          65), -- Scroll of Agility VII
(201021,    57716,      50000,           773,           375,          65), -- Snowfall Ink
(201021,    61117,      75000,           773,           400,          65), -- Master's Inscription of the Axe
(201021,    61118,      75000,           773,           400,          65), -- Master's Inscription of the Crag
(201021,    61119,      75000,           773,           400,          65), -- Master's Inscription of the Pinnacle
(201021,    61120,      75000,           773,           400,          65), -- Master's Inscription of the Storm
(201021,    50620,      60000,           773,           400,          65), -- Scroll of Stamina VIII
(201021,    59498,      60000,           773,           400,          65), -- Faces of Doom
(201021,    59497,      60000,           773,           400,          65), -- Iron-bound Tome
(201021,    59504,      60000,           773,           400,          65), -- Darkmoon Card of the North
(201021,    50611,      60000,           773,           405,          65), -- Scroll of Versatility VIII
(201021,    50604,      60000,           773,           410,          65), -- Scroll of Intellect VIII
(201021,    58491,      60000,           773,           415,          65), -- Scroll of Strength VIII
(201021,    58483,      60000,           773,           420,          65), -- Scroll of Agility VIII
(201021,    86008,     500000,           773,           425,          80), -- Illustrious Grand Master Inscription
(201021,    86004,      80000,           773,           425,          80), -- Blackfallow Ink
(201021,    69385,     120000,           773,           440,          80), -- Runescroll of Fortitude
(201021,    89368,      80000,           773,           445,          80), -- Scroll of Intellect IX
(201021,    89373,      80000,           773,           450,          80), -- Scroll of Protection IX
(201021,    86609,      80000,           773,           450,          80), -- Mysterious Fortune Card
(201021,    89371,      80000,           773,           455,          80), -- Scroll of Versatility IX
(201021,    89372,      80000,           773,           460,          80), -- Scroll of Stamina IX
(201021,    89369,      80000,           773,           465,          80), -- Scroll of Strength IX
(201021,    86005,      90000,           773,           475,          80), -- Inferno Ink
(201021,    86616,      90000,           773,           475,          80), -- Book of Blood
(201021,    86640,      90000,           773,           475,          80), -- Lord Rottington's Pressed Wisp Book
(201021,    86648,      90000,           773,           480,          80), -- Key to the Planes
(201021,   105206,     600000,           773,           500,          85), -- Zen Master Inscription
(201021,    86403,      75000,           773,           500,          85), -- Felfire Inscription
(201021,    86402,      75000,           773,           500,          85), -- Inscription of the Earth Prince
(201021,    86401,      75000,           773,           500,          85), -- Lionsmane Inscription
(201021,    86375,      75000,           773,           500,          85), -- Swiftsteel Inscription
(201021,    85785,     120000,           773,           500,          85), -- Runescroll of Fortitude II
(201021,    86654,     100000,           773,           500,          85), -- Forged Documents
(201021,    89244,     100000,           773,           500,          85), -- Forged Documents
(201021,   111646,     200000,           773,           500,          85), -- Starlight Ink
(201021,   111645,     200000,           773,           500,          85), -- Ink of Dreams
(201021,    86649,     120000,           773,           505,          85), -- Runed Staff
(201021,    86643,     120000,           773,           510,          85), -- Battle Tome
(201021,    86642,     120000,           773,           510,          85), -- Divine Companion
(201021,    86641,     120000,           773,           510,          85), -- Dungeoneering Guide
(201021,    86652,     150000,           773,           515,          85), -- Rosethorn Staff
(201021,    86653,     150000,           773,           515,          85), -- Silver Inlaid Staff
(201021,    86615,     200000,           773,           525,          85), -- Darkmoon Card of Destruction
(201021,   112996,     500000,           773,           525,          85), -- Scroll of Wisdom
(201021,   127018,     200000,           773,           540,          85), -- Crane Wing Inscription
(201021,   127019,     200000,           773,           540,          85), -- Ox Horn Inscription
(201021,   127017,     200000,           773,           540,          85), -- Tiger Claw Inscription
(201021,   127016,     200000,           773,           540,          85), -- Tiger Fang Inscription
(201021,   111920,     200000,           773,           560,          85), -- Ghost Iron Staff
(201021,   111908,     200000,           773,           560,          85), -- Inscribed Fan
(201021,   111917,     200000,           773,           560,          85), -- Rain Poppy Staff
(201021,   111909,     200000,           773,           560,          85), -- Inscribed Jade Fan
(201021,   111910,     200000,           773,           560,          85), -- Inscribed Red Fan
(201021,   111918,     200000,           773,           560,          85), -- Inscribed Crane Staff
(201021,   111919,     200000,           773,           560,          85), -- Inscribed Serpent Staff
(201021,   111921,     200000,           773,           560,          85), -- Inscribed Tiger Staff
(201021,   126995,     200000,           773,           570,          85), -- Greater Crane Wing Inscription
(201021,   126994,     200000,           773,           570,          85), -- Greater Ox Horn Inscription
(201021,   126996,     200000,           773,           570,          85), -- Greater Tiger Claw Inscription
(201021,   126997,     200000,           773,           570,          85), -- Greater Tiger Fang Inscription
(201021,   127023,     200000,           773,           575,          85), -- Secret Crane Wing Inscription
(201021,   127024,     200000,           773,           575,          85), -- Secret Ox Horn Inscription
(201021,   127021,     200000,           773,           575,          85), -- Secret Tiger Claw Inscription
(201021,   127020,     200000,           773,           575,          85), -- Secret Tiger Fang Inscription
(201021,   112045,     200000,           773,           580,          85), -- Runescroll of Fortitude III
(201021,   111830,     200000,           773,           600,          85), -- Darkmoon Card of Mists
(201021,   127009,      50000,           773,           600,          85), -- Chi-ji Kite
(201021,   126988,      50000,           773,           600,          85), -- Origami Crane
(201021,   126989,      50000,           773,           600,          85), -- Origami Frog
(201021,   127007,      50000,           773,           600,          85); -- Yu'lon Kite

-- Archaeology trainers
DELETE FROM `npc_trainer` WHERE `ID` = 202013 OR `SpellID` = -202013;
INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES
(39718,   -202013, 0, 0, 0, 0), -- Doktor Professor Ironpants
(44238,   -202013, 0, 0, 0, 0), -- Harrison Jones
(47346,   -202013, 0, 0, 0, 0), -- Elynara
(47382,   -202013, 0, 0, 0, 0), -- Adam Hossack
(47568,   -202013, 0, 0, 0, 0), -- Ian Thomas Wall
(47569,   -202013, 0, 0, 0, 0), -- Hammon the Jaded
(47570,   -202013, 0, 0, 0, 0), -- Diya
(47571,   -202013, 0, 0, 0, 0), -- Belloc Brightblade
(47572,   -202013, 0, 0, 0, 0), -- Otoh Greyhide
(47573,   -202013, 0, 0, 0, 0), -- Sirabel
(47574,   -202013, 0, 0, 0, 0), -- Gerdra Fardelve
(47575,   -202013, 0, 0, 0, 0), -- Boduro the Seeker
(47576,   -202013, 0, 0, 0, 0), -- Falda Fardelve
(47577,   -202013, 0, 0, 0, 0), -- Lindarel
(47578,   -202013, 0, 0, 0, 0), -- Hugen Goldwise
(47579,   -202013, 0, 0, 0, 0), -- Dariness the Learned
(47683,   -202013, 0, 0, 0, 0), -- Lady Ironpants
(51997,   -202013, 0, 0, 0, 0), -- Stephanie Krutsick
(53421,   -202013, 0, 0, 0, 0), -- Faena Woolybush
(64922,   -202013, 0, 0, 0, 0), -- Brann Bronzebeard
(67586,   -202013, 0, 0, 0, 0), -- Elynara
(67837,   -202013, 0, 0, 0, 0), -- Elynara
(85927,   -202013, 0, 0, 0, 0), -- Manda Darlowe
(86033,   -202013, 0, 0, 0, 0), -- Reena Cogscrap
(93538,   -202013, 0, 0, 0, 0), -- Dariness the Learned

-- Archaeology spells
(202013,  78670,    100,   0,   0,  5), -- Apprentice Archaeology
(202013,  88961,    500, 794,  50, 10), -- Journeyman Archaeology
(202013,  89718,   5000, 794, 200, 20), -- Artisan Archaeology
(202013,  89719,  25000, 794, 125, 35), -- Expert Archaeology
(202013,  89720, 100000, 794, 275, 50), -- Master Archaeology
(202013,  89721, 150000, 794, 350, 65), -- Grand Master Archaeology
(202013,  89722, 250000, 794, 425, 80), -- Illustrious Grand Master Fishing
(202013, 110393, 600000, 794, 500, 85); -- Zen Master Archaeology
