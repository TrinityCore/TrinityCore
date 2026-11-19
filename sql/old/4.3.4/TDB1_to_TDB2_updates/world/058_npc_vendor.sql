DELETE FROM `npc_vendor` WHERE (`entry`=5817 AND `slot`=0) OR (`entry`=3335 AND `slot`=0) OR (`entry`=24935 AND `slot`=0) OR (`entry`=3313 AND `slot`=0) OR (`entry`=21643 AND `slot`=1);

DELETE FROM `npc_vendor` WHERE `entry` IN (16388, 17518, 14754, 23157, 33599, 32641, 19186, 49406, 28057, 20916, 12793, 29945, 36365, 5191, 44034, 10666, 33996, 2135, 50304, 4775, 38978, 45498, 45491, 45484, 10055, 4731, 55264, 14845, 2136, 5190, 39033, 3367, 32413, 32412, 28796, 24147);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 16388 (Koren)
(16388, 2528, 1, 0, 0, 1), -- Falchion
(16388, 2529, 2, 0, 0, 1), -- Zweihander
(16388, 2530, 3, 0, 0, 1), -- Francisca
(16388, 2531, 4, 0, 0, 1), -- Great Axe
(16388, 2532, 5, 0, 0, 1), -- Morning Star
(16388, 2533, 6, 0, 0, 1), -- War Maul
(16388, 2534, 7, 0, 0, 1), -- Rondel
(16388, 2535, 8, 0, 0, 1), -- War Staff
(16388, 29010, 9, 0, 0, 1), -- Wicked Throwing Dagger
(16388, 25876, 10, 0, 0, 1), -- Gleaming Throwing Axe
(16388, 31393, 11, 0, 0, 1), -- Plans: Iceguard Breastplate
(16388, 31395, 12, 0, 0, 1), -- Plans: Iceguard Helm
(16388, 31394, 13, 0, 0, 1), -- Plans: Iceguard Leggings
-- 17518 (Ythyar)
(17518, 17037, 1, 0, 0, 1), -- Hornbeam Seed
(17518, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(17518, 17032, 3, 0, 0, 1), -- Rune of Portals
(17518, 17020, 4, 0, 0, 1), -- Arcane Powder
(17518, 17030, 5, 0, 0, 1), -- Ankh
(17518, 25902, 6, 0, 0, 1), -- Design: Powerful Earthstorm Diamond
(17518, 25903, 7, 0, 0, 1), -- Design: Bracing Earthstorm Diamond
(17518, 22535, 8, 0, 0, 1), -- Formula: Enchant Ring - Striking
-- 14754 (Kelm Hargunth)
(14754, 21566, 1, 0, 1055, 1), -- Rune of Perfection
(14754, 21565, 2, 0, 1054, 1), -- Rune of Perfection
(14754, 19062, 5, 0, 0, 1), -- Warsong Gulch Field Ration
(14754, 19061, 6, 0, 0, 1), -- Warsong Gulch Iron Ration
(14754, 19060, 7, 0, 0, 1), -- Warsong Gulch Enriched Ration
(14754, 19068, 8, 0, 0, 1), -- Warsong Gulch Silk Bandage
(14754, 19067, 9, 0, 0, 1), -- Warsong Gulch Mageweave Bandage
(14754, 19066, 10, 0, 0, 1), -- Warsong Gulch Runecloth Bandage
(14754, 17349, 11, 0, 460, 1), -- Superior Healing Draught
(14754, 17352, 12, 0, 460, 1), -- Superior Mana Draught
(14754, 20426, 13, 0, 822, 1), -- Advisor's Ring
(14754, 19521, 14, 0, 838, 1), -- Advisor's Ring
(14754, 19520, 15, 0, 884, 1), -- Advisor's Ring
(14754, 19519, 16, 0, 930, 1), -- Advisor's Ring
(14754, 19518, 17, 0, 491, 1), -- Advisor's Ring
(14754, 20427, 18, 0, 823, 1), -- Battle Healer's Cloak
(14754, 19529, 19, 0, 839, 1), -- Battle Healer's Cloak
(14754, 19528, 20, 0, 885, 1), -- Battle Healer's Cloak
(14754, 19527, 21, 0, 931, 1), -- Battle Healer's Cloak
(14754, 19526, 22, 0, 492, 1), -- Battle Healer's Cloak
(14754, 20429, 23, 0, 822, 1), -- Legionnaire's Band
(14754, 19513, 24, 0, 838, 1), -- Legionnaire's Band
(14754, 19512, 25, 0, 884, 1), -- Legionnaire's Band
(14754, 19511, 26, 0, 930, 1), -- Legionnaire's Band
(14754, 19510, 27, 0, 491, 1), -- Legionnaire's Band
(14754, 20442, 28, 0, 822, 1), -- Scout's Medallion
(14754, 19537, 29, 0, 838, 1), -- Scout's Medallion
(14754, 19536, 30, 0, 884, 1), -- Scout's Medallion
(14754, 19535, 31, 0, 930, 1), -- Scout's Medallion
(14754, 19534, 32, 0, 491, 1), -- Scout's Medallion
(14754, 17348, 33, 0, 1564, 1), -- Major Healing Draught
(14754, 17351, 34, 0, 1564, 1), -- Major Mana Draught
(14754, 20425, 35, 0, 821, 1), -- Advisor's Gnarled Staff
(14754, 19569, 36, 0, 837, 1), -- Advisor's Gnarled Staff
(14754, 19568, 37, 0, 883, 1), -- Advisor's Gnarled Staff
(14754, 19567, 38, 0, 929, 1), -- Advisor's Gnarled Staff
(14754, 19566, 39, 0, 490, 1), -- Advisor's Gnarled Staff
(14754, 20430, 40, 0, 826, 1), -- Legionnaire's Sword
(14754, 19553, 41, 0, 871, 1), -- Legionnaire's Sword
(14754, 19552, 42, 0, 917, 1), -- Legionnaire's Sword
(14754, 19551, 43, 0, 968, 1), -- Legionnaire's Sword
(14754, 19550, 44, 0, 747, 1), -- Legionnaire's Sword
(14754, 20437, 45, 0, 826, 1), -- Outrider's Bow
(14754, 19561, 46, 0, 871, 1), -- Outrider's Bow
(14754, 19560, 47, 0, 917, 1), -- Outrider's Bow
(14754, 19559, 48, 0, 968, 1), -- Outrider's Bow
(14754, 19558, 49, 0, 747, 1), -- Outrider's Bow
(14754, 20441, 50, 0, 826, 1), -- Scout's Blade
(14754, 19545, 51, 0, 871, 1), -- Scout's Blade
(14754, 19544, 52, 0, 917, 1), -- Scout's Blade
(14754, 19543, 53, 0, 968, 1), -- Scout's Blade
(14754, 19542, 54, 0, 747, 1), -- Scout's Blade
(14754, 19505, 55, 0, 202, 1), -- Warsong Battle Tabard
(14754, 19581, 56, 0, 989, 1), -- Berserker Bracers
(14754, 19580, 57, 0, 990, 1), -- Berserker Bracers
(14754, 19578, 58, 0, 488, 1), -- Berserker Bracers
(14754, 19597, 59, 0, 989, 1), -- Dryad's Wrist Bindings
(14754, 19596, 60, 0, 990, 1), -- Dryad's Wrist Bindings
(14754, 19595, 61, 0, 488, 1), -- Dryad's Wrist Bindings
(14754, 19590, 62, 0, 989, 1), -- Forest Stalker's Bracers
(14754, 19589, 63, 0, 990, 1), -- Forest Stalker's Bracers
(14754, 19587, 64, 0, 488, 1), -- Forest Stalker's Bracers
(14754, 19584, 65, 0, 989, 1), -- Windtalker's Wristguards
(14754, 19583, 66, 0, 990, 1), -- Windtalker's Wristguards
(14754, 19582, 67, 0, 488, 1), -- Windtalker's Wristguards
(14754, 22747, 68, 0, 748, 1), -- Outrider's Silk Leggings
(14754, 22741, 69, 0, 748, 1), -- Outrider's Lizardhide Pants
(14754, 22740, 70, 0, 748, 1), -- Outrider's Leather Pants
(14754, 22676, 71, 0, 748, 1), -- Outrider's Mail Leggings
(14754, 22673, 72, 0, 748, 1), -- Outrider's Chain Leggings
(14754, 22651, 73, 0, 748, 1), -- Outrider's Plate Legguards
(14754, 30498, 74, 0, 748, 1), -- Outrider's Lamellar Legguards
-- 23157 (Aluyen)
(23157, 17037, 1, 0, 0, 1), -- Hornbeam Seed
(23157, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(23157, 17032, 3, 0, 0, 1), -- Rune of Portals
(23157, 17020, 4, 0, 0, 1), -- Arcane Powder
(23157, 17030, 5, 0, 0, 1), -- Ankh
-- 33599 (Brollen Wheatbeard)
(33599, 2901, 1, 0, 0, 1), -- Mining Pick
(33599, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(33599, 2880, 3, 0, 0, 1), -- Weak Flux
(33599, 3466, 4, 0, 0, 1), -- Strong Flux
(33599, 18567, 5, 0, 0, 1), -- Elemental Flux
(33599, 3857, 6, 0, 0, 1), -- Coal
-- 32641 (Drix Blackwrench)
(32641, 14341, 1, 0, 0, 1), -- Rune Thread
(32641, 38426, 2, 0, 0, 1), -- Eternium Thread
(32641, 3371, 3, 0, 0, 1), -- Crystal Vial
(32641, 6532, 4, 0, 0, 1), -- Bright Baubles
(32641, 39354, 5, 0, 0, 1), -- Light Parchment
(32641, 10648, 6, 0, 0, 1), -- Common Parchment
(32641, 39501, 7, 0, 0, 1), -- Heavy Parchment
(32641, 39502, 8, 0, 0, 1), -- Resilient Parchment
(32641, 17034, 9, 0, 0, 1), -- Maple Seed
(32641, 17031, 10, 0, 0, 1), -- Rune of Teleportation
(32641, 17032, 11, 0, 0, 1), -- Rune of Portals
(32641, 17020, 12, 0, 0, 1), -- Arcane Powder
(32641, 17030, 13, 0, 0, 1), -- Ankh
-- 19186 (Kylene)
(19186, 2723, 1, 0, 0, 1), -- Bottle of Pinot Noir
(19186, 2593, 2, 0, 0, 1), -- Flask of Port
(19186, 2596, 3, 0, 0, 1), -- Skin of Dwarven Stout
(19186, 2594, 4, 0, 0, 1), -- Flagon of Mead
(19186, 2595, 5, 0, 0, 1), -- Jug of Bourbon
-- 49406
(49406, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(49406, 58274, 2, 0, 0, 1), -- Fresh Water
(49406, 58275, 3, 0, 0, 1), -- Hardtack
(49406, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(49406, 4470, 5, 0, 0, 1), -- Simple Wood
(49406, 58256, 6, 0, 0, 1), -- Sparkling Oasis Water
(49406, 58257, 7, 0, 0, 1), -- Highland Spring Water
(49406, 65892, 8, 0, 0, 1), -- Pyrium-Laced Crystalline Vial
(49406, 65893, 9, 0, 0, 1), -- Sands of Time
-- 28057 (Garmin Herzog)
(28057, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 20916 (Xerintha Ravenoak)
(20916, 8932, 1, 0, 0, 1), -- Alterac Swiss
(20916, 27857, 2, 0, 0, 1), -- Garadar Sharp
(20916, 29448, 3, 0, 0, 1), -- Mag'har Mild Cheese
(20916, 8766, 4, 0, 0, 1), -- Morning Glory Dew
(20916, 28399, 5, 0, 0, 1), -- Filtered Draenic Water
(20916, 27860, 6, 0, 0, 1), -- Purified Draenic Water
(20916, 31675, 477, 1, 0, 1), -- Recipe: Mok'Nathal Shortribs
(20916, 31674, 478, 1, 0, 1), -- Recipe: Crunchy Serpent
-- 12793 (Brave Stonehide)
(12793, 44957, 1, 0, 2588, 1), -- Greater Inscription of the Gladiator
(12793, 18839, 2, 0, 460, 1), -- Combat Healing Potion
(12793, 18841, 3, 0, 460, 1), -- Combat Mana Potion
(12793, 31853, 4, 0, 1653, 1), -- Major Combat Healing Potion
(12793, 31855, 5, 0, 1653, 1), -- Major Combat Mana Potion
(12793, 32455, 6, 0, 460, 1), -- Star's Lament
(12793, 32453, 7, 0, 1564, 1), -- Star's Tears
(12793, 15197, 8, 0, 1007, 1), -- Scout's Tabard
(12793, 15199, 9, 0, 1006, 1), -- Stone Guard's Herald
(12793, 18607, 10, 0, 3327, 1), -- Horde Battle Standard
-- 29945 (Marksman Udabu)
(29945, 3025, 1, 0, 0, 1), -- BKP 42 "Ultra"
-- 36365
(36365, 38682, 1741, 0, 0, 1), -- Enchanting Vellum
(36365, 6217, 1742, 0, 0, 1), -- Copper Rod
(36365, 10940, 1743, 4, 0, 1), -- Strange Dust
(36365, 10938, 1744, 1, 0, 1), -- Lesser Magic Essence
(36365, 4470, 1745, 0, 0, 1), -- Simple Wood
(36365, 11291, 1746, 0, 0, 1), -- Star Wood
(36365, 20758, 1747, 0, 0, 1), -- Formula: Minor Wizard Oil
(36365, 20752, 1748, 0, 0, 1), -- Formula: Minor Mana Oil
(36365, 20753, 1749, 0, 0, 1), -- Formula: Lesser Wizard Oil
(36365, 22307, 1750, 0, 0, 1), -- Pattern: Enchanted Mageweave Pouch
-- 5191 (Shalumon)
(5191, 5976, 1, 0, 0, 1), -- Guild Tabard
(5191, 31779, 2, 0, 0, 1), -- Aldor Tabard
(5191, 31804, 3, 0, 0, 1), -- Cenarion Expedition Tabard
(5191, 31776, 4, 0, 0, 1), -- Consortium Tabard
(5191, 31777, 5, 0, 0, 1), -- Keepers of Time Tabard
(5191, 31778, 6, 0, 0, 1), -- Lower City Tabard
(5191, 32828, 7, 0, 1958, 1), -- Ogri'la Tabard
(5191, 31780, 8, 0, 0, 1), -- Scryers Tabard
(5191, 31781, 9, 0, 0, 1), -- Sha'tar Tabard
(5191, 32445, 10, 0, 0, 1), -- Skyguard Tabard
(5191, 31775, 11, 0, 1994, 1), -- Sporeggar Tabard
(5191, 35221, 12, 0, 0, 1), -- Tabard of the Shattered Sun
(5191, 23999, 13, 0, 0, 1), -- Honor Hold Tabard
(5191, 31774, 14, 0, 0, 1), -- Kurenai Tabard
(5191, 19506, 15, 0, 205, 1), -- Silverwing Battle Tabard
(5191, 19032, 16, 0, 1003, 1), -- Stormpike Battle Tabard
(5191, 15196, 17, 0, 1007, 1), -- Private's Tabard
(5191, 15198, 18, 0, 1006, 1), -- Knight's Colors
-- 44034 (Franklin Brinklestein)
(44034, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(44034, 4540, 2, 0, 0, 1), -- Tough Hunk of Bread
(44034, 4496, 3, 0, 0, 1), -- Small Brown Pouch
(44034, 4498, 4, 0, 0, 1), -- Brown Leather Satchel
(44034, 4470, 5, 0, 0, 1), -- Simple Wood
(44034, 5042, 6, 0, 0, 1), -- Red Ribboned Wrapping Paper
(44034, 7005, 7, 0, 0, 1), -- Skinning Knife
(44034, 2901, 8, 0, 0, 1), -- Mining Pick
(44034, 5956, 9, 0, 0, 1), -- Blacksmith Hammer
(44034, 6256, 10, 0, 0, 1), -- Fishing Pole
(44034, 6217, 11, 0, 0, 1), -- Copper Rod
(44034, 2678, 12, 0, 0, 1), -- Mild Spices
(44034, 30817, 13, 0, 0, 1), -- Simple Flour
(44034, 2320, 14, 0, 0, 1), -- Coarse Thread
(44034, 2880, 15, 0, 0, 1), -- Weak Flux
(44034, 3371, 16, 0, 0, 1), -- Crystal Vial
(44034, 4289, 17, 0, 0, 1), -- Salt
(44034, 6529, 18, 0, 0, 1), -- Shiny Bauble
(44034, 2604, 19, 0, 0, 1), -- Red Dye
(44034, 2324, 20, 0, 0, 1), -- Bleach
(44034, 6260, 21, 0, 0, 1), -- Blue Dye
(44034, 10648, 22, 0, 0, 1), -- Common Parchment
(44034, 39354, 23, 0, 0, 1), -- Light Parchment
-- 10666 (Gordo)
(10666, 4604, 1, 0, 0, 1), -- Forest Mushroom Cap
(10666, 4605, 2, 0, 0, 1), -- Red-Speckled Mushroom
(10666, 4606, 3, 0, 0, 1), -- Spongy Morel
(10666, 4607, 4, 0, 0, 1), -- Delicious Cave Mold
(10666, 4608, 5, 0, 0, 1), -- Raw Black Truffle
(10666, 8948, 6, 0, 0, 1), -- Dried King Bolete
-- 33996 (William Saldean)
(33996, 4540, 1, 0, 0, 1), -- Tough Hunk of Bread
(33996, 4541, 2, 0, 0, 1), -- Freshly Baked Bread
(33996, 4542, 3, 0, 0, 1), -- Moist Cornbread
(33996, 4544, 4, 0, 0, 1), -- Mulgore Spice Bread
(33996, 4601, 5, 0, 0, 1), -- Soft Banana Bread
(33996, 8950, 6, 0, 0, 1), -- Homemade Cherry Pie
(33996, 11109, 7, 0, 0, 1), -- Special Chicken Feed
-- 2135 (Abe Winters)
(2135, 2398, 1, 0, 0, 1), -- Light Chain Armor
(2135, 2399, 2, 0, 0, 1), -- Light Chain Belt
(2135, 2400, 3, 0, 0, 1), -- Light Chain Leggings
(2135, 2401, 4, 0, 0, 1), -- Light Chain Boots
(2135, 2402, 5, 0, 0, 1), -- Light Chain Bracers
(2135, 2403, 6, 0, 0, 1), -- Light Chain Gloves
(2135, 17185, 7, 0, 0, 1), -- Round Buckler
(2135, 2376, 8, 0, 0, 1), -- Worn Heater Shield
-- 50304 (Captain Donald Adams)
(50304, 45583, 1, 0, 0, 1), -- Undercity Tabard
(50304, 67529, 2, 0, 0, 1), -- Undercity Satchel
(50304, 64922, 3, 0, 0, 1), -- Mantle of Undercity
(50304, 64921, 4, 0, 0, 1), -- Cape of Undercity
(50304, 64920, 5, 0, 0, 1), -- Shroud of Undercity
-- 4775 (Felicia Doan)
(4775, 20975, 1, 1, 0, 1), -- Design: The Jade Eye
(4775, 7005, 2, 0, 0, 1), -- Skinning Knife
(4775, 6256, 3, 0, 0, 1), -- Fishing Pole
(4775, 6217, 4, 0, 0, 1), -- Copper Rod
(4775, 5956, 5, 0, 0, 1), -- Blacksmith Hammer
(4775, 2901, 6, 0, 0, 1), -- Mining Pick
(4775, 2320, 7, 0, 0, 1), -- Coarse Thread
(4775, 2321, 8, 0, 0, 1), -- Fine Thread
(4775, 4291, 9, 0, 0, 1), -- Silken Thread
(4775, 8343, 10, 0, 0, 1), -- Heavy Silken Thread
(4775, 14341, 11, 0, 0, 1), -- Rune Thread
(4775, 2678, 12, 0, 0, 1), -- Mild Spices
(4775, 2880, 13, 0, 0, 1), -- Weak Flux
(4775, 3466, 14, 0, 0, 1), -- Strong Flux
(4775, 3857, 15, 0, 0, 1), -- Coal
(4775, 2604, 16, 0, 0, 1), -- Red Dye
(4775, 2325, 17, 0, 0, 1), -- Black Dye
(4775, 4341, 18, 0, 0, 1), -- Yellow Dye
(4775, 4342, 19, 0, 0, 1), -- Purple Dye
(4775, 4340, 20, 0, 0, 1), -- Gray Dye
(4775, 3371, 21, 0, 0, 1), -- Crystal Vial
(4775, 4289, 22, 0, 0, 1), -- Salt
(4775, 4399, 23, 0, 0, 1), -- Wooden Stock
(4775, 4400, 24, 0, 0, 1), -- Heavy Stock
(4775, 6530, 25, 0, 0, 1), -- Nightcrawlers
(4775, 6532, 26, 0, 0, 1), -- Bright Baubles
-- 38978 (Apprentice Crispin)
(38978, 22250, 1, 0, 0, 1), -- Herb Pouch
(38978, 3371, 2, 0, 0, 1), -- Crystal Vial
-- 45498 ("Salty" Rocka)
(45498, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 45491 (Apothecary Harrington)
(45491, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(45491, 1179, 2, 0, 0, 1), -- Ice Cold Milk
(45491, 4540, 3, 0, 0, 1), -- Tough Hunk of Bread
(45491, 4541, 4, 0, 0, 1), -- Freshly Baked Bread
(45491, 4496, 5, 0, 0, 1), -- Small Brown Pouch
(45491, 4498, 6, 0, 0, 1), -- Brown Leather Satchel
(45491, 4470, 7, 0, 0, 1), -- Simple Wood
(45491, 5042, 8, 0, 0, 1), -- Red Ribboned Wrapping Paper
-- 45484 (Provisioner Angelus)
(45484, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(45484, 1179, 2, 0, 0, 1), -- Ice Cold Milk
(45484, 4540, 3, 0, 0, 1), -- Tough Hunk of Bread
(45484, 4541, 4, 0, 0, 1), -- Freshly Baked Bread
(45484, 4496, 5, 0, 0, 1), -- Small Brown Pouch
(45484, 4498, 6, 0, 0, 1), -- Brown Leather Satchel
(45484, 4470, 7, 0, 0, 1), -- Simple Wood
(45484, 5042, 8, 0, 0, 1), -- Red Ribboned Wrapping Paper
(45484, 1205, 9, 0, 0, 1), -- Melon Juice
(45484, 4542, 10, 0, 0, 1), -- Moist Cornbread
(45484, 5048, 11, 0, 0, 1), -- Blue Ribboned Wrapping Paper
-- 10055 (Morganus)
(10055, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 4731 (Zachariah Post)
(4731, 46308, 1, 0, 0, 1), -- Black Skeletal Horse
(4731, 13333, 2, 0, 0, 1), -- Brown Skeletal Horse
(4731, 13332, 3, 0, 0, 1), -- Blue Skeletal Horse
(4731, 13331, 4, 0, 0, 1), -- Red Skeletal Horse
(4731, 47101, 5, 0, 0, 1), -- Ochre Skeletal Warhorse
(4731, 13334, 6, 0, 0, 1), -- Green Skeletal Warhorse
(4731, 18791, 7, 0, 0, 1), -- Purple Skeletal Warhorse
-- 55264 (Sazz Coincatcher)
(55264, 78899, 2, 0, 0, 1), -- Pouch o' Tokens
(55264, 78905, 9, 0, 0, 1), -- Sack o' Tokens
-- 14845 (Stamp Thunderhorn)
(14845, 19223, 1, 0, 0, 1), -- Darkmoon Dog
(14845, 19304, 2, 0, 0, 1), -- Spiced Beef Jerky
(14845, 19305, 3, 0, 0, 1), -- Pickled Kodo Foot
(14845, 19224, 4, 0, 0, 1), -- Red Hot Wings
(14845, 19306, 5, 0, 0, 1), -- Crunchy Frog
(14845, 19225, 6, 0, 0, 1), -- Deep Fried Candybar
(14845, 33246, 7, 0, 0, 1), -- Funnel Cake
(14845, 33254, 8, 0, 0, 1), -- Forest Strider Drumstick
(14845, 44940, 9, 0, 0, 1), -- Corn-Breaded Sausage
(14845, 73260, 10, 0, 0, 1), -- Salty Sea Dog
-- 2136 (Oliver Dwor)
(2136, 2488, 1, 0, 0, 1), -- Gladius
(2136, 2489, 2, 0, 0, 1), -- Two-Handed Sword
(2136, 2490, 3, 0, 0, 1), -- Tomahawk
(2136, 2491, 4, 0, 0, 1), -- Large Axe
(2136, 2492, 5, 0, 0, 1), -- Cudgel
(2136, 2493, 6, 0, 0, 1), -- Wooden Mallet
(2136, 2494, 7, 0, 0, 1), -- Stiletto
(2136, 2495, 8, 0, 0, 1), -- Walking Stick
(2136, 25872, 9, 0, 0, 1), -- Balanced Throwing Dagger
(2136, 29007, 10, 0, 0, 1), -- Weighted Throwing Axe
-- 5190 (Merill Pleasance)
(5190, 5976, 1, 0, 0, 1), -- Guild Tabard
(5190, 31779, 2, 0, 0, 1), -- Aldor Tabard
(5190, 31804, 3, 0, 0, 1), -- Cenarion Expedition Tabard
(5190, 31776, 4, 0, 0, 1), -- Consortium Tabard
(5190, 31777, 5, 0, 0, 1), -- Keepers of Time Tabard
(5190, 31778, 6, 0, 0, 1), -- Lower City Tabard
(5190, 32828, 7, 0, 1958, 1), -- Ogri'la Tabard
(5190, 31780, 8, 0, 0, 1), -- Scryers Tabard
(5190, 31781, 9, 0, 0, 1), -- Sha'tar Tabard
(5190, 32445, 10, 0, 0, 1), -- Skyguard Tabard
(5190, 31775, 11, 0, 1994, 1), -- Sporeggar Tabard
(5190, 35221, 12, 0, 0, 1), -- Tabard of the Shattered Sun
(5190, 31773, 13, 0, 0, 1), -- Mag'har Tabard
(5190, 24004, 14, 0, 0, 1), -- Thrallmar Tabard
(5190, 19505, 15, 0, 202, 1), -- Warsong Battle Tabard
(5190, 19031, 16, 0, 1003, 1), -- Frostwolf Battle Tabard
(5190, 15197, 17, 0, 1007, 1), -- Scout's Tabard
(5190, 15199, 18, 0, 1006, 1), -- Stone Guard's Herald
-- 39033 (Sortura)
(39033, 193, 1, 0, 0, 1), -- Tattered Cloth Vest
(39033, 3595, 2, 0, 0, 1), -- Tattered Cloth Belt
(39033, 194, 3, 0, 0, 1), -- Tattered Cloth Pants
(39033, 195, 4, 0, 0, 1), -- Tattered Cloth Boots
(39033, 3596, 5, 0, 0, 1), -- Tattered Cloth Bracers
(39033, 711, 6, 0, 0, 1), -- Tattered Cloth Gloves
(39033, 85, 7, 0, 0, 1), -- Dirty Leather Vest
(39033, 1835, 8, 0, 0, 1), -- Dirty Leather Belt
(39033, 209, 9, 0, 0, 1), -- Dirty Leather Pants
(39033, 210, 10, 0, 0, 1), -- Dirty Leather Boots
(39033, 1836, 11, 0, 0, 1), -- Dirty Leather Bracers
(39033, 714, 12, 0, 0, 1), -- Dirty Leather Gloves
-- 21643
(21643, 31951, 1, 0, 0, 1), -- 31951
-- 3367
(3367, 20856, 1, 1, 0, 1), -- 20856
(3367, 7005, 2, 0, 0, 1), -- 7005
(3367, 6256, 3, 0, 0, 1), -- 6256
(3367, 6217, 4, 0, 0, 1), -- 6217
(3367, 5956, 5, 0, 0, 1), -- 5956
(3367, 2901, 6, 0, 0, 1), -- 2901
(3367, 2320, 7, 0, 0, 1), -- 2320
(3367, 2321, 8, 0, 0, 1), -- 2321
(3367, 4291, 9, 0, 0, 1), -- 4291
(3367, 8343, 10, 0, 0, 1), -- 8343
(3367, 14341, 11, 0, 0, 1), -- 14341
(3367, 2678, 12, 0, 0, 1), -- 2678
(3367, 2880, 13, 0, 0, 1), -- 2880
(3367, 3466, 14, 0, 0, 1), -- 3466
(3367, 3857, 15, 0, 0, 1), -- 3857
(3367, 2604, 16, 0, 0, 1), -- 2604
(3367, 2325, 17, 0, 0, 1), -- 2325
(3367, 4341, 18, 0, 0, 1), -- 4341
(3367, 4342, 19, 0, 0, 1), -- 4342
(3367, 4340, 20, 0, 0, 1), -- 4340
(3367, 3371, 21, 0, 0, 1), -- 3371
(3367, 4289, 22, 0, 0, 1), -- 4289
(3367, 4399, 23, 0, 0, 1), -- 4399
(3367, 4400, 24, 0, 0, 1), -- 4400
(3367, 6530, 25, 0, 0, 1), -- 6530
(3367, 6532, 26, 0, 0, 1), -- 6532
-- 32413 (Isirami Fairwind)
(32413, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(32413, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(32413, 33445, 3, 0, 0, 1), -- Honeymint Tea
(32413, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(32413, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
(32413, 33443, 6, 0, 0, 1), -- Sour Goat Cheese
(32413, 35952, 7, 0, 0, 1), -- Briny Hardcheese
(32413, 33454, 8, 0, 0, 1), -- Salted Venison
(32413, 35953, 9, 0, 0, 1), -- Mead Basted Caribou
-- 32412 (Mato)
(32412, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(32412, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(32412, 33445, 3, 0, 0, 1), -- Honeymint Tea
(32412, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(32412, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
(32412, 33443, 6, 0, 0, 1), -- Sour Goat Cheese
(32412, 35952, 7, 0, 0, 1), -- Briny Hardcheese
(32412, 33454, 8, 0, 0, 1), -- Salted Venison
(32412, 35953, 9, 0, 0, 1), -- Mead Basted Caribou
-- 28796 (Arlen Brighthammer)
(28796, 2901, 1, 0, 0, 1), -- Mining Pick
(28796, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(28796, 2880, 3, 0, 0, 1), -- Weak Flux
(28796, 3466, 4, 0, 0, 1), -- Strong Flux
(28796, 18567, 5, 0, 0, 1), -- Elemental Flux
(28796, 3857, 6, 0, 0, 1), -- Coal
-- 24147 (Tara Cooper)
(24147, 14341, 1, 0, 0, 1), -- Rune Thread
(24147, 3371, 2, 0, 0, 1), -- Crystal Vial
(24147, 6532, 3, 0, 0, 1), -- Bright Baubles
(24147, 10648, 4, 0, 0, 1), -- Common Parchment
(24147, 38426, 5, 0, 0, 1), -- Eternium Thread
(24147, 39354, 6, 0, 0, 1), -- Light Parchment
(24147, 39501, 7, 0, 0, 1), -- Heavy Parchment
(24147, 39502, 8, 0, 0, 1); -- Resilient Parchment
