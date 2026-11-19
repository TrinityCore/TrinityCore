-- Update Vendor 53641 1294 1295 1291
DELETE FROM `npc_vendor` WHERE `entry` IN (53641, 1294, 1295, 1291);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(53641, 48, 52533, 0, 0, 1, 0, 0, 48001), -- Squire's Boots
(53641, 47, 43, 0, 0, 1, 0, 0, 48001), -- Squire's Boots
(53641, 46, 23477, 0, 0, 1, 0, 0, 48001), -- Squire's Pants
(53641, 45, 44, 0, 0, 1, 0, 0, 48001), -- Squire's Pants
(53641, 44, 58242, 0, 0, 1, 0, 0, 48001), -- Squire's Vest
(53641, 43, 58233, 0, 0, 1, 0, 0, 48001), -- Squire's Vest
(53641, 42, 40, 0, 0, 1, 0, 0, 48001), -- Recruit's Boots
(53641, 41, 23475, 0, 0, 1, 0, 0, 48001), -- Recruit's Boots
(53641, 40, 6122, 0, 0, 1, 0, 0, 48001), -- Recruit's Boots
(53641, 39, 6121, 0, 0, 1, 0, 0, 48001), -- Recruit's Pants
(53641, 38, 23474, 0, 0, 1, 0, 0, 48001), -- Recruit's Pants
(53641, 37, 39, 0, 0, 1, 0, 0, 48001), -- Recruit's Pants
(53641, 36, 58244, 0, 0, 1, 0, 0, 48001), -- Recruit's Vest
(53641, 35, 58231, 0, 0, 1, 0, 0, 48001), -- Recruit's Vest
(53641, 34, 58243, 0, 0, 1, 0, 0, 48001), -- Recruit's Vest
(53641, 33, 2448, 0, 0, 1, 0, 0, 48001), -- Heavy Pavise
(53641, 32, 17189, 0, 0, 1, 0, 0, 48001), -- Metal Buckler
(53641, 31, 3891, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Helm
(53641, 30, 2422, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Gloves
(53641, 29, 2421, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Bracers
(53641, 28, 2420, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Boots
(53641, 27, 2418, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Leggings
(53641, 26, 2419, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Belt
(53641, 25, 2417, 0, 0, 1, 0, 0, 48001), -- Augmented Chain Vest
(53641, 24, 2451, 0, 0, 1, 0, 0, 48001), -- Crested Heater Shield
(53641, 23, 17190, 0, 0, 1, 0, 0, 48001), -- Ornate Buckler
(53641, 22, 8092, 0, 0, 1, 0, 0, 48001), -- Platemail Helm
(53641, 21, 8091, 0, 0, 1, 0, 0, 48001), -- Platemail Gloves
(53641, 20, 8090, 0, 0, 1, 0, 0, 48001), -- Platemail Bracers
(53641, 19, 8089, 0, 0, 1, 0, 0, 48001), -- Platemail Boots
(53641, 18, 8093, 0, 0, 1, 0, 0, 48001), -- Platemail Leggings
(53641, 17, 8088, 0, 0, 1, 0, 0, 48001), -- Platemail Belt
(53641, 16, 8094, 0, 0, 1, 0, 0, 48001), -- Platemail Armor
(53641, 15, 3894, 0, 0, 1, 0, 0, 48001), -- Brigandine Helm
(53641, 14, 2428, 0, 0, 1, 0, 0, 48001), -- Brigandine Gloves
(53641, 13, 2427, 0, 0, 1, 0, 0, 48001), -- Brigandine Bracers
(53641, 12, 2426, 0, 0, 1, 0, 0, 48001), -- Brigandine Boots
(53641, 11, 2425, 0, 0, 1, 0, 0, 48001), -- Brigandine Leggings
(53641, 10, 2424, 0, 0, 1, 0, 0, 48001), -- Brigandine Belt
(53641, 9, 2423, 0, 0, 1, 0, 0, 48001), -- Brigandine Vest
(53641, 8, 2446, 0, 0, 1, 0, 1, 48001), -- Kite Shield
(53641, 7, 17192, 0, 0, 1, 0, 1, 48001), -- Reinforced Targe
(53641, 6, 2151, 0, 0, 1, 0, 1, 48001), -- Polished Scale Gloves
(53641, 5, 2150, 0, 0, 1, 0, 1, 48001), -- Polished Scale Bracers
(53641, 4, 2149, 0, 0, 1, 0, 1, 48001), -- Polished Scale Boots
(53641, 3, 2152, 0, 0, 1, 0, 1, 48001), -- Polished Scale Leggings
(53641, 2, 2148, 0, 0, 1, 0, 1, 48001), -- Polished Scale Belt
(53641, 1, 2153, 0, 0, 1, 0, 1, 48001), -- Polished Scale Vest
(1294, 29, 52539, 0, 0, 1, 0, 0, 48001), -- Primal Pants
(1294, 28, 52540, 0, 0, 1, 0, 0, 48001), -- Primal Boots
(1294, 27, 52535, 0, 0, 1, 0, 0, 48001), -- Primal Pants
(1294, 26, 52538, 0, 0, 1, 0, 0, 48001), -- Primal Robe
(1294, 25, 52534, 0, 0, 1, 0, 0, 48001), -- Primal Robe
(1294, 24, 23348, 0, 0, 1, 0, 0, 48001), -- Scout's Boots
(1294, 23, 23344, 0, 0, 1, 0, 0, 48001), -- Scout's Pants
(1294, 22, 58240, 0, 0, 1, 0, 0, 48001), -- Scout's Vest
(1294, 21, 129, 0, 0, 1, 0, 0, 48001), -- Rugged Trapper's Boots
(1294, 20, 147, 0, 0, 1, 0, 0, 48001), -- Rugged Trapper's Pants
(1294, 19, 58232, 0, 0, 1, 0, 0, 48001), -- Rugged Trapper's Vest
(1294, 18, 718, 0, 0, 1, 0, 1, 48001), -- Scalemail Gloves
(1294, 17, 1852, 0, 0, 1, 0, 1, 48001), -- Scalemail Bracers
(1294, 16, 287, 0, 0, 1, 0, 1, 48001), -- Scalemail Boots
(1294, 15, 286, 0, 0, 1, 0, 1, 48001), -- Scalemail Pants
(1294, 14, 1853, 0, 0, 1, 0, 1, 48001), -- Scalemail Belt
(1294, 13, 285, 0, 0, 1, 0, 1, 48001), -- Scalemail Vest
(1294, 12, 850, 0, 0, 1, 0, 0, 48001), -- Chainmail Gloves
(1294, 11, 1846, 0, 0, 1, 0, 0, 48001), -- Chainmail Bracers
(1294, 10, 849, 0, 0, 1, 0, 0, 48001), -- Chainmail Boots
(1294, 9, 848, 0, 0, 1, 0, 0, 48001), -- Chainmail Pants
(1294, 8, 1845, 0, 0, 1, 0, 0, 48001), -- Chainmail Belt
(1294, 7, 847, 0, 0, 1, 0, 0, 48001), -- Chainmail Armor
(1294, 6, 2397, 0, 0, 1, 0, 0, 48001), -- Light Mail Gloves
(1294, 5, 2396, 0, 0, 1, 0, 0, 48001), -- Light Mail Bracers
(1294, 4, 2395, 0, 0, 1, 0, 0, 48001), -- Light Mail Boots
(1294, 3, 2394, 0, 0, 1, 0, 0, 48001), -- Light Mail Leggings
(1294, 2, 2393, 0, 0, 1, 0, 0, 48001), -- Light Mail Belt
(1294, 1, 2392, 0, 0, 1, 0, 0, 48001), -- Light Mail Armor
(1295, 23, 6124, 0, 0, 1, 0, 0, 48001), -- Novice's Pants
(1295, 22, 6123, 0, 0, 1, 0, 0, 48001), -- Novice's Robe
(1295, 21, 47, 0, 0, 1, 0, 0, 48001), -- Footpad's Shoes
(1295, 20, 48, 0, 0, 1, 0, 0, 48001), -- Footpad's Pants
(1295, 19, 58234, 0, 0, 1, 0, 0, 48001), -- Footpad's Vest
(1295, 18, 239, 0, 0, 1, 0, 0, 48001), -- Cured Leather Gloves
(1295, 17, 1850, 0, 0, 1, 0, 0, 48001), -- Cured Leather Bracers
(1295, 16, 238, 0, 0, 1, 0, 0, 48001), -- Cured Leather Boots
(1295, 15, 237, 0, 0, 1, 0, 0, 48001), -- Cured Leather Pants
(1295, 14, 1849, 0, 0, 1, 0, 0, 48001), -- Cured Leather Belt
(1295, 13, 236, 0, 0, 1, 0, 0, 48001), -- Cured Leather Armor
(1295, 12, 844, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Gloves
(1295, 11, 1844, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Bracers
(1295, 10, 843, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Boots
(1295, 9, 845, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Pants
(1295, 8, 1843, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Belt
(1295, 7, 846, 0, 0, 1, 0, 1, 48001), -- Tanned Leather Jerkin
(1295, 6, 797, 0, 0, 1, 0, 1, 48001), -- Rough Leather Gloves
(1295, 5, 1840, 0, 0, 1, 0, 1, 48001), -- Rough Leather Bracers
(1295, 4, 796, 0, 0, 1, 0, 1, 48001), -- Rough Leather Boots
(1295, 3, 798, 0, 0, 1, 0, 1, 48001), -- Rough Leather Pants
(1295, 2, 1839, 0, 0, 1, 0, 1, 48001), -- Rough Leather Belt
(1295, 1, 799, 0, 0, 1, 0, 1, 48001), -- Rough Leather Vest
(1291, 42, 6118, 0, 0, 1, 0, 0, 48001), -- Squire's Pants
(1291, 41, 23349, 0, 0, 1, 0, 0, 48001), -- -Unknown-
(1291, 40, 23350, 0, 0, 1, 0, 0, 48001), -- Battleworn Pants
(1291, 39, 23478, 0, 0, 1, 0, 0, 48001), -- Recruit's Pants
(1291, 38, 23479, 0, 0, 1, 0, 0, 48001), -- Recruit's Robe
(1291, 37, 23472, 0, 0, 1, 0, 0, 48001), -- -Unknown-
(1291, 36, 23471, 0, 0, 1, 0, 0, 48001), -- Rugged Trapper's Pants
(1291, 35, 59, 0, 0, 1, 0, 0, 48001), -- Acolyte's Shoes
(1291, 34, 1396, 0, 0, 1, 0, 0, 48001), -- Acolyte's Pants
(1291, 33, 23322, 0, 0, 1, 0, 0, 48001), -- Acolyte's Robe
(1291, 32, 57, 0, 0, 1, 0, 0, 48001), -- Acolyte's Robe
(1291, 31, 52554, 0, 0, 1, 0, 0, 48001), -- Apprentice's Boots
(1291, 30, 52553, 0, 0, 1, 0, 0, 48001), -- Apprentice's Robe
(1291, 29, 55, 0, 0, 1, 0, 0, 48001), -- Apprentice's Boots
(1291, 28, 1395, 0, 0, 1, 0, 0, 48001), -- Apprentice's Pants
(1291, 27, 56, 0, 0, 1, 0, 0, 48001), -- Apprentice's Robe
(1291, 26, 6116, 0, 0, 1, 0, 0, 48001), -- Apprentice's Robe
(1291, 25, 52, 0, 0, 1, 0, 0, 48001), -- Neophyte's Pants
(1291, 24, 51, 0, 0, 1, 0, 0, 48001), -- Neophyte's Boots
(1291, 23, 6098, 0, 0, 1, 0, 0, 48001), -- Neophyte's Robe
(1291, 22, 6119, 0, 0, 1, 0, 0, 48001), -- Neophyte's Robe
(1291, 21, 203, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Gloves
(1291, 20, 3598, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Bracers
(1291, 19, 202, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Shoes
(1291, 18, 201, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Pants
(1291, 17, 3597, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Belt
(1291, 16, 200, 0, 0, 1, 0, 0, 48001), -- Thick Cloth Vest
(1291, 15, 16060, 0, 0, 1, 0, 0, 48001), -- Common White Shirt
(1291, 14, 3428, 0, 0, 1, 0, 0, 48001), -- Common Gray Shirt
(1291, 13, 16059, 0, 0, 1, 0, 0, 48001), -- Common Brown Shirt
(1291, 12, 839, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Gloves
(1291, 11, 3590, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Bracers
(1291, 10, 840, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Shoes
(1291, 9, 838, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Pants
(1291, 8, 3589, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Belt
(1291, 7, 837, 0, 0, 1, 0, 0, 48001), -- Heavy Weave Armor
(1291, 6, 793, 0, 0, 1, 0, 0, 48001), -- Knitted Gloves
(1291, 5, 3603, 0, 0, 1, 0, 0, 48001), -- Knitted Bracers
(1291, 4, 792, 0, 0, 1, 0, 0, 48001), -- Knitted Sandals
(1291, 3, 794, 0, 0, 1, 0, 0, 48001), -- Knitted Pants
(1291, 2, 3602, 0, 0, 1, 0, 0, 48001), -- Knitted Belt
(1291, 1, 795, 0, 0, 1, 0, 0, 48001); -- Knitted Tunic
