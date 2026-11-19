DELETE FROM `npc_vendor` WHERE (`entry`=12795 AND `slot`=0) OR (`entry`=6929 AND `slot`=0) OR (`entry`=3364 AND `slot`=0) OR (`entry`=52809 AND `slot`=1);

DELETE FROM `npc_vendor` WHERE `entry` IN (48531, 4553, 31031, 29906, 29548, 33026, 3322, 57262, 48617, 48886, 24188, 24067, 24028, 29476, 28831, 24291, 24141, 49787, 4220, 31911, 48356, 28716, 29962, 4730, 33980, 35344, 31557, 3369, 32540, 53528, 6735, 19330, 16824, 52818, 35507, 23367, 18993, 35101, 35290, 28685, 29532, 19011, 20241, 32334, 47267, 14624, 38853, 36717, 36779, 25032, 18907, 21172, 28718, 8403, 40160, 18756, 3613, 3610, 4167, 17485, 28870, 28868, 28589, 11185, 4203, 32287, 3609, 19239, 23489, 22227, 21019, 33669, 29547, 27019, 27022, 27021, 26567, 29636, 32564, 35131, 27026, 49519, 43408, 41903, 29261, 45408, 27133, 26707, 26936, 29277, 26868, 27134, 33865, 58153, 18382);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 48531
(48531, 63518, 1, 0, 3009, 1), -- Hellscream's Reach Commendation
(48531, 64993, 2, 0, 3010, 1), -- Hellscream's Reach Mana Potion
(48531, 64994, 3, 0, 3010, 1), -- Hellscream's Reach Healing Potion
(48531, 64995, 4, 0, 3015, 1), -- Hellscream's Reach Bandage
(48531, 63378, 5, 0, 3013, 1), -- Hellscream's Reach Tabard
(48531, 64997, 6, 0, 3013, 1), -- Tol Barad Searchlight
(48531, 65176, 7, 0, 3013, 1), -- Baradin Grunt's Talisman
(48531, 64996, 8, 0, 3012, 1), -- Rustberg Gull
(48531, 63376, 9, 0, 3012, 1), -- Hellscream's Reach Battle Standard
(48531, 62454, 10, 0, 3007, 1), -- Blade of the Fearless
(48531, 62456, 11, 0, 3007, 1), -- Dagger of Restless Nights
(48531, 62457, 12, 0, 3007, 1), -- Ravening Slicer
(48531, 62455, 13, 0, 3007, 1), -- Spear of Trailing Shadows
(48531, 62460, 14, 0, 3007, 1), -- Sky Piercer
(48531, 62459, 15, 0, 3007, 1), -- Shimmering Morningstar
(48531, 62458, 16, 0, 3007, 1), -- Insidious Staff
(48531, 68740, 17, 0, 3007, 1), -- Darkheart Hacker
(48531, 62467, 18, 0, 3014, 1), -- Mandala of Stirring Patterns
(48531, 62466, 19, 0, 3014, 1), -- Mirror of Broken Images
(48531, 62464, 20, 0, 3014, 1), -- Impatience of Youth
(48531, 62465, 21, 0, 3014, 1), -- Stump of Time
(48531, 62463, 22, 0, 3014, 1), -- Unsolvable Riddle
(48531, 64999, 23, 0, 3022, 1), -- Reins of the Spectral Wolf
(48531, 65356, 24, 0, 3011, 1), -- Reins of the Drake of the West Wind
(48531, 68769, 25, 0, 3013, 1), -- Arcanum of Vicious Agility
(48531, 68770, 26, 0, 3013, 1), -- Arcanum of Vicious Intellect
(48531, 68768, 27, 0, 3013, 1), -- Arcanum of Vicious Strength
(48531, 68774, 28, 0, 3352, 1), -- Greater Inscription of Vicious Agility
(48531, 68772, 29, 0, 3352, 1), -- Greater Inscription of Vicious Intellect
(48531, 68773, 30, 0, 3352, 1), -- Greater Inscription of Vicious Strength
-- 4553 (Ronald Burch)
(4553, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(4553, 30817, 2, 0, 0, 1), -- Simple Flour
(4553, 2678, 3, 0, 0, 1), -- Mild Spices
(4553, 21099, 4, 0, 0, 1), -- Recipe: Smoked Sagefish
(4553, 21219, 5, 0, 0, 1), -- Recipe: Sagefish Delight
(4553, 6330, 6, 0, 0, 1), -- Recipe: Bristle Whisker Catfish
(4553, 6368, 7, 0, 0, 1), -- Recipe: Rainbow Fin Albacore
(4553, 68689, 8, 0, 3323, 1), -- Imported Supplies
(4553, 65513, 9, 0, 3024, 1), -- Crate of Tasty Meat
(4553, 65406, 10, 0, 3322, 1), -- Recipe: Whitecrest Gumbo
(4553, 65407, 11, 0, 3322, 1), -- Recipe: Lavascale Fillet
(4553, 65409, 12, 0, 3322, 1), -- Recipe: Lavascale Minestrone
(4553, 65410, 13, 0, 3322, 1), -- Recipe: Salted Eye
(4553, 65411, 14, 0, 3322, 1), -- Recipe: Broiled Mountain Trout
(4553, 65412, 15, 0, 3322, 1), -- Recipe: Lightly Fried Lurker
(4553, 65413, 16, 0, 3322, 1), -- Recipe: Seasoned Crab
(4553, 65414, 17, 0, 3322, 1), -- Recipe: Starfire Espresso
(4553, 65408, 18, 0, 3322, 1), -- Recipe: Feathered Lure
(4553, 65415, 19, 0, 3322, 1), -- Recipe: Highland Spirits
(4553, 65416, 20, 0, 3322, 1), -- Recipe: Lurker Lunch
(4553, 65417, 21, 0, 3322, 1), -- Recipe: Pickled Guppy
(4553, 65418, 22, 0, 3322, 1), -- Recipe: Hearty Seafood Soup
(4553, 65419, 23, 0, 3322, 1), -- Recipe: Tender Baked Turtle
(4553, 65420, 24, 0, 3322, 1), -- Recipe: Mushroom Sauce Mudfish
(4553, 65421, 25, 0, 3322, 1), -- Recipe: Severed Sagefish Head
(4553, 65422, 26, 0, 3322, 1), -- Recipe: Delicious Sagefish Tail
(4553, 65423, 27, 0, 3322, 1), -- Recipe: Fish Fry
(4553, 68688, 28, 0, 3322, 1), -- Recipe: Scalding Murglesnout
(4553, 65424, 29, 0, 3322, 1), -- Recipe: Blackbelly Sushi
(4553, 65425, 30, 0, 3322, 1), -- Recipe: Skewered Eel
(4553, 65426, 31, 0, 3322, 1), -- Recipe: Baked Rockfish
(4553, 65427, 32, 0, 3322, 1), -- Recipe: Basilisk Liverdog
(4553, 65428, 33, 0, 3322, 1), -- Recipe: Grilled Dragon
(4553, 65429, 34, 0, 3322, 1), -- Recipe: Beer-Basted Crocolisk
(4553, 65430, 35, 0, 3322, 1), -- Recipe: Crocolisk Au Gratin
(4553, 65431, 36, 0, 3322, 1), -- Recipe: Chocolate Cookie
(4553, 65432, 37, 0, 3023, 1), -- Recipe: Fortune Cookie
(4553, 65433, 38, 0, 3023, 1), -- Recipe: South Island Iced Tea
-- 31031 (Misensi)
(31031, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(31031, 30817, 2, 0, 0, 1), -- Simple Flour
(31031, 2678, 3, 0, 0, 1), -- Mild Spices
(31031, 43007, 4, 0, 2480, 1), -- Northern Spices
(31031, 43018, 5, 0, 2478, 1), -- Recipe: Mega Mammoth Meal
(31031, 43019, 6, 0, 2478, 1), -- Recipe: Tender Shoveltusk Steak
(31031, 43020, 7, 0, 2478, 1), -- Recipe: Spiced Worm Burger
(31031, 43021, 8, 0, 2478, 1), -- Recipe: Very Burnt Worg
(31031, 44954, 9, 0, 2478, 1), -- Recipe: Worg Tartare
(31031, 43022, 10, 0, 2478, 1), -- Recipe: Mighty Rhino Dogs
(31031, 43023, 11, 0, 2478, 1), -- Recipe: Poached Northern Sculpin
(31031, 43024, 12, 0, 2478, 1), -- Recipe: Firecracker Salmon
(31031, 43025, 13, 0, 2478, 1), -- Recipe: Spicy Blue Nettlefish
(31031, 43026, 14, 0, 2478, 1), -- Recipe: Imperial Manta Steak
(31031, 43027, 15, 0, 2478, 1), -- Recipe: Spicy Fried Herring
(31031, 43028, 16, 0, 2478, 1), -- Recipe: Rhinolicious Wormsteak
(31031, 43029, 17, 0, 2478, 1), -- Recipe: Critter Bites
(31031, 43030, 18, 0, 2478, 1), -- Recipe: Hearty Rhino
(31031, 43031, 19, 0, 2478, 1), -- Recipe: Snapper Extreme
(31031, 43032, 20, 0, 2478, 1), -- Recipe: Blackened Worg Steak
(31031, 43033, 21, 0, 2478, 1), -- Recipe: Cuttlesteak
(31031, 43034, 22, 0, 2478, 1), -- Recipe: Spiced Mammoth Treats
(31031, 43035, 23, 0, 2478, 1), -- Recipe: Blackened Dragonfin
(31031, 43036, 24, 0, 2478, 1), -- Recipe: Dragonfin Filet
(31031, 43037, 25, 0, 2478, 1), -- Recipe: Tracker Snacks
(31031, 43505, 26, 0, 2478, 1), -- Recipe: Gigantic Feast
(31031, 43506, 27, 0, 2478, 1), -- Recipe: Small Feast
(31031, 43017, 28, 0, 2479, 1), -- Recipe: Fish Feast
(31031, 46349, 29, 0, 2670, 1), -- Chef's Hat
-- 29906 (Heksi)
(29906, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 29548 (Aimee)
(29548, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(29548, 42439, 2, 0, 0, 1), -- Big Berry Pie
(29548, 42436, 3, 0, 0, 1), -- Chocolate Celebration Cake
(29548, 42438, 4, 0, 0, 1), -- Lovely Cake
(29548, 42428, 5, 0, 0, 1), -- Carrot Cupcake
(29548, 42429, 6, 0, 0, 1), -- Red Velvet Cupcake
(29548, 42430, 7, 0, 0, 1), -- Dalaran Doughnut
(29548, 42431, 8, 0, 0, 1), -- Dalaran Brownie
(29548, 74921, 9, 0, 0, 1), -- Darkmoon Doughnut
-- 33026 (Sarah Brady)
(33026, 40035, 1, 0, 0, 1), -- Honey Mead
(33026, 40036, 2, 0, 0, 1), -- Snowplum Brandy
(33026, 40042, 3, 0, 0, 1), -- Caraway Burnwine
(33026, 2723, 4, 0, 0, 1), -- Bottle of Pinot Noir
(33026, 2593, 5, 0, 0, 1), -- Flask of Port
(33026, 2596, 6, 0, 0, 1), -- Skin of Dwarven Stout
(33026, 2594, 7, 0, 0, 1), -- Flagon of Mead
(33026, 2595, 8, 0, 0, 1), -- Jug of Bourbon
-- 3322 (Kaja)
(3322, 2509, 1, 0, 0, 1), -- Ornate Blunderbuss
(3322, 2511, 2, 0, 0, 1), -- Hunter's Boomstick
(3322, 3023, 3, 0, 0, 1), -- Large Bore Blunderbuss
(3322, 3024, 4, 0, 0, 1), -- BKP 2700 "Enforcer"
(3322, 3025, 5, 0, 0, 1), -- BKP 42 "Ultra"
(3322, 3026, 6, 0, 0, 1), -- Reinforced Bow
(3322, 3027, 7, 0, 0, 1), -- Heavy Recurve Bow
(3322, 11307, 57, 1, 0, 1), -- Massive Longbow
-- 57262
(57262, 59231, 1, 0, 0, 1), -- Oily Giblets
(57262, 59232, 2, 0, 0, 1), -- Unidentifiable Meat Dish
(57262, 59227, 3, 0, 0, 1), -- Rock-Hard Biscuit
(57262, 59228, 4, 0, 0, 1), -- Vile Purple Fungus
(57262, 59229, 5, 0, 0, 1), -- Murky Water
(57262, 59230, 6, 0, 0, 1), -- Fungus Squeezings
-- 48617
(48617, 65904, 1, 0, 0, 1), -- Tabard of Ramkahen
(48617, 62439, 2, 0, 0, 1), -- Belt of the Stargazer
(48617, 62438, 3, 0, 0, 1), -- Drystone Greaves
(48617, 62437, 4, 0, 0, 1), -- Shroud of the Dead
(48617, 62436, 5, 0, 0, 1), -- Ammunae's Blessing
(48617, 62441, 6, 0, 0, 1), -- Robes of Orsis
(48617, 62440, 7, 0, 0, 1), -- Red Rock Band
(48617, 62446, 8, 0, 0, 1), -- Quicksand Belt
(48617, 62445, 9, 0, 0, 1), -- Sash of Prophecy
(48617, 62450, 10, 0, 0, 1), -- Desert Walker Sandals
(48617, 62449, 11, 0, 0, 1), -- Sandguard Bracers
(48617, 62448, 12, 0, 0, 1), -- Sun King's Girdle
(48617, 62447, 13, 0, 0, 1), -- Gift of Nadun
(48617, 68766, 14, 0, 0, 1), -- Arcanum of the Ramkahen
(48617, 63045, 16, 0, 0, 1), -- Reins of the Tan Riding Camel
(48617, 63044, 17, 0, 0, 1), -- Reins of the Brown Riding Camel
-- 48886
(48886, 58274, 1, 0, 0, 1), -- Fresh Water
(48886, 58256, 2, 0, 0, 1), -- Sparkling Oasis Water
(48886, 58257, 3, 0, 0, 1), -- Highland Spring Water
(48886, 58277, 4, 0, 0, 1), -- Simmered Squid
(48886, 58262, 5, 0, 0, 1), -- Sliced Raw Billfish
(48886, 58263, 6, 0, 0, 1), -- Grilled Shark
(48886, 58275, 7, 0, 0, 1), -- Hardtack
(48886, 58260, 8, 0, 0, 1), -- Pine Nut Bread
(48886, 58261, 9, 0, 0, 1), -- Buttery Wheat Roll
-- 24188 (Samuel Rosemond)
(24188, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(24188, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(24188, 33449, 3, 0, 0, 1), -- Crusty Flatbread
(24188, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(24188, 4470, 5, 0, 0, 1), -- Simple Wood
(24188, 14341, 6, 0, 0, 1), -- Rune Thread
(24188, 38426, 7, 0, 0, 1), -- Eternium Thread
(24188, 3371, 8, 0, 0, 1), -- Crystal Vial
(24188, 6532, 9, 0, 0, 1), -- Bright Baubles
(24188, 39354, 10, 0, 0, 1), -- Light Parchment
(24188, 10648, 11, 0, 0, 1), -- Common Parchment
(24188, 39501, 12, 0, 0, 1), -- Heavy Parchment
(24188, 39502, 13, 0, 0, 1), -- Resilient Parchment
-- 24067 (Mahana Frosthoof)
(24067, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 24028 (Talu Frosthoof)
(24028, 2504, 1, 0, 0, 1), -- Worn Shortbow
(24028, 2505, 2, 0, 0, 1), -- Polished Shortbow
(24028, 2506, 3, 0, 0, 1), -- Hornwood Recurve Bow
(24028, 2507, 4, 0, 0, 1), -- Laminated Recurve Bow
(24028, 3026, 5, 0, 0, 1), -- Reinforced Bow
(24028, 3027, 6, 0, 0, 1), -- Heavy Recurve Bow
-- 29476 (Dagna Flintlock)
(29476, 44635, 1, 0, 0, 1), -- Dalaran Rifle
-- 28831 (Yamuna)
(28831, 7005, 1, 0, 0, 1), -- Skinning Knife
(28831, 6256, 2, 0, 0, 1), -- Fishing Pole
(28831, 6217, 3, 0, 0, 1), -- Copper Rod
(28831, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(28831, 2901, 5, 0, 0, 1), -- Mining Pick
(28831, 2320, 6, 0, 0, 1), -- Coarse Thread
(28831, 2321, 7, 0, 0, 1), -- Fine Thread
(28831, 4291, 8, 0, 0, 1), -- Silken Thread
(28831, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(28831, 14341, 10, 0, 0, 1), -- Rune Thread
(28831, 2678, 11, 0, 0, 1), -- Mild Spices
(28831, 2880, 12, 0, 0, 1), -- Weak Flux
(28831, 3466, 13, 0, 0, 1), -- Strong Flux
(28831, 3857, 14, 0, 0, 1), -- Coal
(28831, 2604, 15, 0, 0, 1), -- Red Dye
(28831, 2325, 16, 0, 0, 1), -- Black Dye
(28831, 4341, 17, 0, 0, 1), -- Yellow Dye
(28831, 4342, 18, 0, 0, 1), -- Purple Dye
(28831, 4340, 19, 0, 0, 1), -- Gray Dye
(28831, 3371, 20, 0, 0, 1), -- Crystal Vial
(28831, 4289, 21, 0, 0, 1), -- Salt
(28831, 4399, 22, 0, 0, 1), -- Wooden Stock
(28831, 4400, 23, 0, 0, 1), -- Heavy Stock
(28831, 6530, 24, 0, 0, 1), -- Nightcrawlers
(28831, 6532, 25, 0, 0, 1), -- Bright Baubles
(28831, 38426, 26, 0, 0, 1), -- Eternium Thread
(28831, 39354, 27, 0, 0, 1), -- Light Parchment
(28831, 10648, 28, 0, 0, 1), -- Common Parchment
(28831, 39501, 29, 0, 0, 1), -- Heavy Parchment
(28831, 39502, 30, 0, 0, 1), -- Resilient Parchment
-- 24291 (Anton)
(24291, 33612, 1, 0, 0, 1), -- Fresh Pound of Flesh
(24291, 2287, 2, 0, 0, 1), -- Haunch of Meat
(24291, 4599, 3, 0, 0, 1), -- Cured Ham Steak
(24291, 12037, 4, 10, 0, 1), -- Mystery Meat
-- 24141 (Stephen Barone)
(24141, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(24141, 28399, 2, 0, 0, 1), -- Filtered Draenic Water
(24141, 27855, 3, 0, 0, 1), -- Mag'har Grainbread
(24141, 4499, 4, 0, 0, 1), -- Huge Brown Sack
(24141, 30744, 5, 0, 0, 1), -- Draenic Leather Pack
(24141, 4470, 6, 0, 0, 1), -- Simple Wood
(24141, 35954, 7, 0, 0, 1), -- Sweetened Goat's Milk
(24141, 33449, 8, 0, 0, 1), -- Crusty Flatbread
(24141, 60335, 9, 0, 0, 1), -- Thick Hide Pack
-- 49787
(49787, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(49787, 30817, 2, 0, 0, 1), -- Simple Flour
(49787, 2678, 3, 0, 0, 1), -- Mild Spices
(49787, 61982, 4, 0, 0, 1), -- Fizzy Fruit Wine
(49787, 61983, 5, 0, 0, 1), -- Imported Ale
(49787, 61984, 6, 0, 0, 1), -- Potent Pineapple Punch
(49787, 61985, 7, 0, 0, 1), -- Banana Cocktail
(49787, 61986, 8, 0, 0, 1), -- Coconut Rum
-- 4220 (Cyroen)
(4220, 17034, 1, 0, 0, 1), -- Maple Seed
(4220, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(4220, 17032, 3, 0, 0, 1), -- Rune of Portals
(4220, 17020, 4, 0, 0, 1), -- Arcane Powder
(4220, 17030, 5, 0, 0, 1), -- Ankh
-- 31911 (Tanak)
(31911, 44072, 1, 0, 0, 1), -- Roasted Mystery Beast
(31911, 41561, 2, 0, 0, 1), -- Design: Reckless Huge Citrine
(31911, 44064, 3, 0, 0, 1), -- Nepeta Leaf
(31911, 44117, 4, 0, 0, 1), -- Azure Strappy Pants
(31911, 44123, 5, 0, 0, 1), -- Discarded Titanium Legplates
(31911, 44120, 6, 0, 0, 1), -- Giant-Sized Gauntlets
(31911, 44116, 7, 0, 0, 1), -- Muddied Crimson Gloves
(31911, 44122, 8, 0, 0, 1), -- Scavenged Feathery Leggings
(31911, 44121, 9, 0, 0, 1), -- Sparkly Shiny Gloves
(31911, 44118, 10, 0, 0, 1), -- Stolen Vrykul Harpoon
(31911, 44717, 11, 0, 0, 1), -- Disgusting Jar
(31911, 41723, 12, 0, 0, 1), -- Design: Jagged Forest Emerald
(31911, 44073, 13, 0, 0, 1), -- Frenzyheart Insignia of Fury
-- 48356
(48356, 2901, 1, 0, 0, 1), -- Mining Pick
(48356, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(48356, 2880, 3, 0, 0, 1), -- Weak Flux
(48356, 3466, 4, 0, 0, 1), -- Strong Flux
(48356, 18567, 5, 0, 0, 1), -- Elemental Flux
(48356, 3857, 6, 0, 0, 1), -- Coal
-- 28716 (Palja Amboss)
(28716, 2901, 1, 0, 0, 1), -- Mining Pick
(28716, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(28716, 2880, 3, 0, 0, 1), -- Weak Flux
(28716, 3466, 4, 0, 0, 1), -- Strong Flux
(28716, 18567, 5, 0, 0, 1), -- Elemental Flux
(28716, 3857, 6, 0, 0, 1), -- Coal
-- 29962 (Horgoru the Collector)
(29962, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(29962, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(29962, 33449, 3, 0, 0, 1), -- Crusty Flatbread
(29962, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(29962, 4470, 5, 0, 0, 1), -- Simple Wood
-- 4730 (Lelanai)
(4730, 47100, 1, 0, 0, 1), -- Reins of the Striped Dawnsaber
(4730, 8631, 2, 0, 0, 1), -- Reins of the Striped Frostsaber
(4730, 8632, 3, 0, 0, 1), -- Reins of the Spotted Frostsaber
(4730, 8629, 4, 0, 0, 1), -- Reins of the Striped Nightsaber
(4730, 18902, 5, 0, 0, 1), -- Reins of the Swift Stormsaber
(4730, 18767, 6, 0, 0, 1), -- Reins of the Swift Mistsaber
(4730, 18766, 7, 0, 0, 1), -- Reins of the Swift Frostsaber
-- 33980
(33980, 46325, 1, 0, 0, 1), -- Withers
-- 35344 (Bognar Ironfoot)
(35344, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 31557 (Uda the Beast)
(31557, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(31557, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(31557, 33445, 3, 0, 0, 1), -- Honeymint Tea
(31557, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(31557, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
(31557, 33443, 6, 0, 0, 1), -- Sour Goat Cheese
(31557, 35952, 7, 0, 0, 1), -- Briny Hardcheese
(31557, 33454, 8, 0, 0, 1), -- Salted Venison
(31557, 35953, 9, 0, 0, 1), -- Mead Basted Caribou
-- 3369 (Gotri)
(3369, 4496, 1, 0, 0, 1), -- Small Brown Pouch
(3369, 4498, 2, 0, 0, 1), -- Brown Leather Satchel
(3369, 4497, 3, 0, 0, 1), -- Heavy Brown Bag
(3369, 4499, 4, 0, 0, 1), -- Huge Brown Sack
(3369, 60335, 5, 0, 0, 1), -- Thick Hide Pack
(3369, 30746, 6, 0, 0, 1), -- Mining Sack
(3369, 30745, 7, 0, 0, 1), -- Heavy Toolbox
(3369, 30748, 8, 0, 0, 1), -- Enchanter's Satchel
(3369, 30747, 9, 0, 0, 1), -- Gem Pouch
-- 32540 (Lillehoff)
(32540, 44137, 1, 0, 0, 1), -- Arcanum of the Frosty Soul
(32540, 44131, 2, 0, 0, 1), -- Lesser Inscription of the Axe
(32540, 44130, 3, 0, 0, 1), -- Lesser Inscription of the Crag
(32540, 44132, 4, 0, 0, 1), -- Lesser Inscription of the Pinnacle
(32540, 44129, 5, 0, 0, 1), -- Lesser Inscription of the Storm 
(32540, 44510, 6, 0, 0, 1), -- Pattern: Mammoth Mining Bag
(32540, 44189, 7, 0, 0, 1), -- Giant Ring Belt
(32540, 44190, 8, 0, 0, 1), -- Spaulders of Frozen Knives
(32540, 44080, 9, 0, 0, 1), -- Reins of the Ice Mammoth
(32540, 44193, 11, 0, 0, 1), -- Broken Stalactite
(32540, 44194, 12, 0, 0, 1), -- Giant-Friend Kilt
(32540, 44195, 13, 0, 0, 1), -- Spaulders of the Giant Lords
(32540, 44192, 14, 0, 0, 1), -- Stalactite Chopper
(32540, 44086, 15, 0, 0, 1), -- Reins of the Grand Ice Mammoth
(32540, 42184, 17, 0, 0, 1), -- Pattern: Glacial Bag
(32540, 41720, 18, 0, 0, 1), -- Design: Smooth Autumn's Glow
(32540, 50335, 23, 0, 0, 1), -- Greater Inscription of the Axe
(32540, 50336, 24, 0, 0, 1), -- Greater Inscription of the Crag
(32540, 50337, 25, 0, 0, 1), -- Greater Inscription of the Pinnacle
(32540, 50338, 26, 0, 0, 1), -- Greater Inscription of the Storm
-- 53528
(53528, 69920, 1, 0, 0, 1), -- Thrice-Spiced Crunchy Stew
(53528, 4604, 2, 0, 0, 1), -- Forest Mushroom Cap
(53528, 4605, 3, 0, 0, 1), -- Red-Speckled Mushroom
(53528, 4606, 4, 0, 0, 1), -- Spongy Morel
(53528, 4607, 5, 0, 0, 1), -- Delicious Cave Mold
(53528, 4608, 6, 0, 0, 1), -- Raw Black Truffle
(53528, 8948, 7, 0, 0, 1), -- Dried King Bolete
(53528, 27859, 8, 0, 0, 1), -- Zangar Caps
(53528, 33452, 9, 0, 0, 1), -- Honey-Spiced Lichen
(53528, 35947, 10, 0, 0, 1), -- Sparkling Frostcap
(53528, 58266, 11, 0, 0, 1), -- Violet Morel
(53528, 58267, 12, 0, 0, 1), -- Scarlet Polypore
(53528, 159, 13, 0, 0, 1), -- Refreshing Spring Water
(53528, 1179, 14, 0, 0, 1), -- Ice Cold Milk
(53528, 1205, 15, 0, 0, 1), -- Melon Juice
(53528, 1708, 16, 0, 0, 1), -- Sweet Nectar
(53528, 1645, 17, 0, 0, 1), -- Moonberry Juice
(53528, 8766, 18, 0, 0, 1), -- Morning Glory Dew
(53528, 28399, 19, 0, 0, 1), -- Filtered Draenic Water
(53528, 58274, 20, 0, 0, 1), -- Fresh Water
(53528, 33444, 21, 0, 0, 1), -- Pungent Seal Whey
(53528, 33445, 22, 0, 0, 1), -- Honeymint Tea
(53528, 58256, 23, 0, 0, 1), -- Sparkling Oasis Water
(53528, 58257, 24, 0, 0, 1), -- Highland Spring Water
-- 6735 (Innkeeper Saelienne)
(6735, 4536, 1, 0, 0, 1), -- Shiny Red Apple
(6735, 4537, 2, 0, 0, 1), -- Tel'Abim Banana
(6735, 4538, 3, 0, 0, 1), -- Snapvine Watermelon
(6735, 4539, 4, 0, 0, 1), -- Goldenbark Apple
(6735, 4602, 5, 0, 0, 1), -- Moon Harvest Pumpkin
(6735, 8953, 6, 0, 0, 1), -- Deep Fried Plantains
(6735, 27856, 7, 0, 0, 1), -- Skethyl Berries
(6735, 35949, 8, 0, 0, 1), -- Tundra Berries
(6735, 35948, 9, 0, 0, 1), -- Savory Snowplum
(6735, 58264, 10, 0, 0, 1), -- Sour Green Apple
(6735, 58265, 11, 0, 0, 1), -- Highland Pomegranate
(6735, 159, 12, 0, 0, 1), -- Refreshing Spring Water
(6735, 1179, 13, 0, 0, 1), -- Ice Cold Milk
(6735, 1205, 14, 0, 0, 1), -- Melon Juice
(6735, 1708, 15, 0, 0, 1), -- Sweet Nectar
(6735, 1645, 16, 0, 0, 1), -- Moonberry Juice
(6735, 8766, 17, 0, 0, 1), -- Morning Glory Dew
(6735, 28399, 18, 0, 0, 1), -- Filtered Draenic Water
(6735, 58274, 19, 0, 0, 1), -- Fresh Water
(6735, 33444, 20, 0, 0, 1), -- Pungent Seal Whey
(6735, 33445, 21, 0, 0, 1), -- Honeymint Tea
(6735, 58256, 22, 0, 0, 1), -- Sparkling Oasis Water
(6735, 58257, 23, 0, 0, 1), -- Highland Spring Water
-- 19330 (Lisrythe Bloodwatch)
(19330, 28458, 1, 0, 0, 1), -- Bold Tourmaline
(19330, 28461, 2, 0, 0, 1), -- Brilliant Tourmaline
(19330, 28459, 3, 0, 0, 1), -- Delicate Tourmaline
(19330, 28463, 4, 0, 0, 1), -- Solid Zircon
(19330, 28464, 5, 0, 0, 1), -- Sparkling Zircon
(19330, 28468, 6, 0, 0, 1), -- Rigid Zircon
(19330, 28467, 7, 0, 0, 1), -- Smooth Amber
(19330, 28470, 8, 0, 0, 1), -- Subtle Amber
-- 16824 (Master Sergeant Lorin Thalmerok)
(16824, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 52809
(52809, 69231, 1, 0, 0, 1), -- -Unknown-
-- 52818
(52818, 69243, 1, 0, 0, 1), -- Ice Cream Cake Slice
(52818, 69244, 2, 0, 0, 1), -- Ice Cream Bar
(52818, 33234, 3, 0, 0, 1), -- Iced Berry Slush
(52818, 69233, 4, 0, 0, 1), -- Cone of Cold
-- 35507 (Enchanter Isian)
(35507, 69889, 1, 0, 3318, 1), -- Burnished Breastplate of Might
(35507, 69890, 2, 0, 3318, 1), -- Burnished Pauldrons of Might
(35507, 48685, 3, 0, 3318, 1), -- Polished Breastplate of Valor
(35507, 42949, 4, 0, 3318, 1), -- Polished Spaulders of Valor
(35507, 42950, 5, 0, 3318, 1), -- Champion Herod's Shoulder
(35507, 48677, 6, 0, 3318, 1), -- Champion's Deathdealer Breastplate
(35507, 42951, 7, 0, 3318, 1), -- Mystical Pauldrons of Elements
(35507, 48683, 8, 0, 3318, 1), -- Mystical Vest of Elements
(35507, 48687, 9, 0, 3318, 1), -- Preened Ironfeather Breastplate
(35507, 42984, 10, 0, 3318, 1), -- Preened Ironfeather Shoulders
(35507, 42952, 11, 0, 3318, 1), -- Stained Shadowcraft Spaulders
(35507, 48689, 12, 0, 3318, 1), -- Stained Shadowcraft Tunic
(35507, 42985, 13, 0, 3318, 1), -- Tattered Dreadmist Mantle
(35507, 48691, 14, 0, 3318, 1), -- Tattered Dreadmist Robe
(35507, 42944, 15, 0, 3318, 1), -- Balanced Heartseeker
(35507, 42943, 16, 0, 2551, 1), -- Bloodied Arcanite Reaper
(35507, 42946, 17, 0, 2551, 1), -- Charmed Ancient Bone Bow
(35507, 42948, 18, 0, 3319, 1), -- Devout Aurastone Hammer
(35507, 42947, 19, 0, 2551, 1), -- Dignified Headmaster's Charge
(35507, 48718, 20, 0, 2551, 1), -- Repurposed Lava Dredger
(35507, 42945, 21, 0, 3318, 1), -- Venerable Dal'Rend's Sacred Charge
(35507, 48716, 22, 0, 3318, 1), -- Venerable Mass of McGowan
(35507, 69893, 23, 0, 3318, 1), -- Bloodsoaked Skullforge Reaver
(35507, 42992, 24, 0, 3319, 1), -- Discerning Eye of the Beast
(35507, 42991, 25, 0, 3319, 1), -- Swift Hand of Justice
-- 23367 (Grella)
(23367, 32722, 1, 0, 0, 1), -- Enriched Terocone Juice
(23367, 32721, 2, 0, 0, 1), -- Skyguard Rations
(23367, 32538, 3, 0, 0, 1), -- Skywitch's Drape
(23367, 32539, 4, 0, 0, 1), -- Skyguard's Drape
(23367, 38628, 5, 0, 0, 1), -- Nether Ray Fry
(23367, 32319, 6, 0, 0, 1), -- Blue Riding Nether Ray
(23367, 32314, 7, 0, 0, 1), -- Green Riding Nether Ray
(23367, 32316, 8, 0, 0, 1), -- Purple Riding Nether Ray
(23367, 32317, 9, 0, 0, 1), -- Red Riding Nether Ray
(23367, 32318, 10, 0, 0, 1), -- Silver Riding Nether Ray
(23367, 32445, 11, 0, 0, 1), -- Skyguard Tabard
(23367, 32771, 12, 0, 0, 1), -- Airman's Ribbon of Gallantry
(23367, 32770, 13, 0, 0, 1), -- Skyguard Silver Cross
-- 18993 (Naka)
(18993, 159, 2, 0, 0, 1), -- Refreshing Spring Water
(18993, 30817, 3, 0, 0, 1), -- Simple Flour
(18993, 2678, 4, 0, 0, 1), -- Mild Spices
-- 35101 (Grunda Bronzewing)
(35101, 25471, 1, 0, 0, 1), -- Ebon Gryphon
(35101, 25470, 2, 0, 0, 1), -- Golden Gryphon
(35101, 25472, 3, 0, 0, 1), -- Snowy Gryphon
(35101, 25473, 4, 0, 0, 1), -- Swift Blue Gryphon
(35101, 25528, 5, 0, 0, 1), -- Swift Green Gryphon
(35101, 25529, 6, 0, 0, 1), -- Swift Purple Gryphon
(35101, 25527, 7, 0, 0, 1), -- Swift Red Gryphon
-- 35290 (Steen Horngrass)
(35290, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 28685 (Narisa Redgold)
(28685, 40035, 1, 0, 0, 1), -- Honey Mead
(28685, 40036, 2, 0, 0, 1), -- Snowplum Brandy
(28685, 40042, 3, 0, 0, 1), -- Caraway Burnwine
(28685, 35954, 4, 0, 0, 1), -- Sweetened Goat's Milk
(28685, 33444, 5, 0, 0, 1), -- Pungent Seal Whey
(28685, 33445, 6, 0, 0, 1), -- Honeymint Tea
(28685, 33449, 7, 0, 0, 1), -- Crusty Flatbread
(28685, 35950, 8, 0, 0, 1), -- Sweet Potato Bread
(28685, 35949, 9, 0, 0, 1), -- Tundra Berries
(28685, 35948, 10, 0, 0, 1), -- Savory Snowplum
(28685, 33452, 11, 0, 0, 1), -- Honey-Spiced Lichen
(28685, 35947, 12, 0, 0, 1), -- Sparkling Frostcap
-- 29532 (Ajay Green)
(29532, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(29532, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(29532, 33445, 3, 0, 0, 1), -- Honeymint Tea
(29532, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(29532, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
(29532, 33443, 6, 0, 0, 1), -- Sour Goat Cheese
(29532, 35952, 7, 0, 0, 1), -- Briny Hardcheese
(29532, 33454, 8, 0, 0, 1), -- Salted Venison
(29532, 35953, 9, 0, 0, 1), -- Mead Basted Caribou
-- 19011 (Osrok the Immovable)
(19011, 2901, 1, 0, 0, 1), -- Mining Pick
(19011, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(19011, 2880, 3, 0, 0, 1), -- Weak Flux
(19011, 3466, 4, 0, 0, 1), -- Strong Flux
(19011, 18567, 5, 0, 0, 1), -- Elemental Flux
(19011, 3857, 6, 0, 0, 1), -- Coal
(19011, 30777, 7, 0, 0, 1), -- Aldor Heavy Belt
(19011, 30771, 8, 0, 0, 1), -- Heavy Draenic Bracers
(19011, 30765, 9, 0, 0, 1), -- Heavy Draenic Breastplate
(19011, 30775, 10, 0, 0, 1), -- Layered Bone Shield
(19011, 30781, 11, 0, 0, 1), -- Mag'hari Chain Vest
(19011, 30784, 12, 0, 0, 1), -- Worn Mag'hari Gauntlets
-- 20241 (Provisioner Nasela)
(20241, 25741, 1, 0, 0, 1), -- Pattern: Netherfury Belt
(20241, 34174, 2, 0, 0, 1), -- Pattern: Drums of Restoration
(20241, 34172, 3, 0, 0, 1), -- Pattern: Drums of Speed
(20241, 29664, 4, 0, 0, 1), -- Pattern: Reinforced Mining Bag
(20241, 25742, 5, 0, 0, 1), -- Pattern: Netherfury Leggings
(20241, 29145, 6, 0, 0, 1), -- Band of Ancestral Spirits
(20241, 29141, 7, 0, 0, 1), -- Tempest Leggings
(20241, 29147, 8, 0, 0, 1), -- Talbuk Hide Spaulders
(20241, 25743, 9, 0, 0, 1), -- Pattern: Netherfury Boots
(20241, 29139, 10, 0, 0, 1), -- Ceremonial Cover
(20241, 29137, 11, 0, 0, 1), -- Hellscream's Will
(20241, 29135, 12, 0, 0, 1), -- Earthcaller's Headdress
(20241, 31829, 13, 0, 0, 1), -- Reins of the Cobalt Riding Talbuk
(20241, 31831, 14, 0, 0, 1), -- Reins of the Silver Riding Talbuk
(20241, 31833, 15, 0, 0, 1), -- Reins of the Tan Riding Talbuk
(20241, 31835, 16, 0, 0, 1), -- Reins of the White Riding Talbuk
(20241, 29102, 17, 0, 0, 1), -- Reins of the Cobalt War Talbuk
(20241, 29104, 18, 0, 0, 1), -- Reins of the Silver War Talbuk
(20241, 29105, 19, 0, 0, 1), -- Reins of the Tan War Talbuk
(20241, 29103, 20, 0, 0, 1), -- Reins of the White War Talbuk
(20241, 31773, 21, 0, 0, 1), -- Mag'har Tabard
(20241, 22917, 22, 0, 0, 1), -- Recipe: Transmute Primal Fire to Earth
-- 32334 (Nixi Fireclaw)
(32334, 43236, 1, 0, 2483, 1), -- Star's Sorrow
(32334, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(32334, 33444, 3, 0, 0, 1), -- Pungent Seal Whey
(32334, 33445, 4, 0, 0, 1), -- Honeymint Tea
-- 47267
(47267, 2901, 1, 0, 0, 1), -- Mining Pick
(47267, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(47267, 2880, 3, 0, 0, 1), -- Weak Flux
(47267, 3466, 4, 0, 0, 1), -- Strong Flux
(47267, 18567, 5, 0, 0, 1), -- Elemental Flux
(47267, 3857, 6, 0, 0, 1), -- Coal
-- 14624 (Master Smith Burninate)
(14624, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(14624, 1205, 2, 0, 0, 1), -- Melon Juice
(14624, 1708, 3, 0, 0, 1), -- Sweet Nectar
(14624, 1645, 4, 0, 0, 1), -- Moonberry Juice
(14624, 4542, 5, 0, 0, 1), -- Moist Cornbread
(14624, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(14624, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(14624, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(14624, 4470, 9, 0, 0, 1), -- Simple Wood
(14624, 117, 10, 0, 0, 1), -- Tough Jerky
(14624, 2287, 11, 0, 0, 1), -- Haunch of Meat
(14624, 3770, 12, 0, 0, 1), -- Mutton Chop
(14624, 3771, 13, 0, 0, 1), -- Wild Hog Shank
(14624, 4599, 14, 0, 0, 1), -- Cured Ham Steak
(14624, 8952, 15, 0, 0, 1), -- Roasted Quail
(14624, 1179, 16, 0, 0, 1), -- Ice Cold Milk
(14624, 8766, 17, 0, 0, 1), -- Morning Glory Dew
(14624, 2901, 18, 0, 0, 1), -- Mining Pick
(14624, 5956, 19, 0, 0, 1), -- Blacksmith Hammer
(14624, 2880, 20, 0, 0, 1), -- Weak Flux
(14624, 3466, 21, 0, 0, 1), -- Strong Flux
(14624, 18567, 22, 0, 0, 1), -- Elemental Flux
(14624, 3857, 23, 0, 0, 1), -- Coal
-- 38853
(38853, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(38853, 4540, 2, 0, 0, 1), -- Tough Hunk of Bread
(38853, 4496, 3, 0, 0, 1), -- Small Brown Pouch
(38853, 4498, 4, 0, 0, 1), -- Brown Leather Satchel
(38853, 4470, 5, 0, 0, 1), -- Simple Wood
(38853, 5042, 6, 0, 0, 1), -- Red Ribboned Wrapping Paper
(38853, 7005, 7, 0, 0, 1), -- Skinning Knife
(38853, 2901, 8, 0, 0, 1), -- Mining Pick
(38853, 5956, 9, 0, 0, 1), -- Blacksmith Hammer
(38853, 6256, 10, 0, 0, 1), -- Fishing Pole
(38853, 6217, 11, 0, 0, 1), -- Copper Rod
(38853, 2678, 12, 0, 0, 1), -- Mild Spices
(38853, 30817, 13, 0, 0, 1), -- Simple Flour
(38853, 2320, 14, 0, 0, 1), -- Coarse Thread
(38853, 2880, 15, 0, 0, 1), -- Weak Flux
(38853, 3371, 16, 0, 0, 1), -- Crystal Vial
(38853, 4289, 17, 0, 0, 1), -- Salt
(38853, 6529, 18, 0, 0, 1), -- Shiny Bauble
(38853, 2604, 19, 0, 0, 1), -- Red Dye
(38853, 2324, 20, 0, 0, 1), -- Bleach
(38853, 6260, 21, 0, 0, 1), -- Blue Dye
(38853, 10648, 22, 0, 0, 1), -- Common Parchment
(38853, 39354, 23, 0, 0, 1), -- Light Parchment
-- 36717
(36717, 2488, 1, 0, 0, 1), -- Gladius
(36717, 2489, 2, 0, 0, 1), -- Two-Handed Sword
(36717, 2490, 3, 0, 0, 1), -- Tomahawk
(36717, 2491, 4, 0, 0, 1), -- Large Axe
(36717, 2492, 5, 0, 0, 1), -- Cudgel
(36717, 2493, 6, 0, 0, 1), -- Wooden Mallet
(36717, 2494, 7, 0, 0, 1), -- Stiletto
(36717, 2495, 8, 0, 0, 1), -- Walking Stick
(36717, 25872, 9, 0, 0, 1), -- Balanced Throwing Dagger
(36717, 29007, 10, 0, 0, 1), -- Weighted Throwing Axe
-- 36779
(36779, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(36779, 4540, 2, 0, 0, 1), -- Tough Hunk of Bread
(36779, 4496, 3, 0, 0, 1), -- Small Brown Pouch
(36779, 4498, 4, 0, 0, 1), -- Brown Leather Satchel
(36779, 4470, 5, 0, 0, 1), -- Simple Wood
(36779, 5042, 6, 0, 0, 1), -- Red Ribboned Wrapping Paper
(36779, 7005, 7, 0, 0, 1), -- Skinning Knife
(36779, 2901, 8, 0, 0, 1), -- Mining Pick
(36779, 5956, 9, 0, 0, 1), -- Blacksmith Hammer
(36779, 6256, 10, 0, 0, 1), -- Fishing Pole
(36779, 6217, 11, 0, 0, 1), -- Copper Rod
(36779, 2678, 12, 0, 0, 1), -- Mild Spices
(36779, 30817, 13, 0, 0, 1), -- Simple Flour
(36779, 2320, 14, 0, 0, 1), -- Coarse Thread
(36779, 2880, 15, 0, 0, 1), -- Weak Flux
(36779, 3371, 16, 0, 0, 1), -- Crystal Vial
(36779, 4289, 17, 0, 0, 1), -- Salt
(36779, 6529, 18, 0, 0, 1), -- Shiny Bauble
(36779, 2604, 19, 0, 0, 1), -- Red Dye
(36779, 2324, 20, 0, 0, 1), -- Bleach
(36779, 6260, 21, 0, 0, 1), -- Blue Dye
(36779, 10648, 22, 0, 0, 1), -- Common Parchment
(36779, 39354, 23, 0, 0, 1), -- Light Parchment
-- 25032 (Eldara Dawnrunner)
(25032, 34780, 1, 0, 0, 1), -- Naaru Ration
(25032, 34872, 2, 0, 0, 1), -- Formula: Void Shatter
(25032, 35500, 3, 0, 0, 1), -- Formula: Enchant Chest - Dodge
(25032, 35505, 4, 0, 0, 1), -- Design: Ember Skyfire Diamond
(25032, 35502, 5, 0, 0, 1), -- Design: Eternal Earthstorm Diamond
(25032, 29193, 6, 0, 0, 1), -- Arcanum of the Gladiator
(25032, 35697, 7, 0, 0, 1), -- Design: Figurine - Crimson Serpent
(25032, 35699, 8, 0, 0, 1), -- Design: Figurine - Seaspray Albatross
(25032, 35695, 9, 0, 0, 1), -- Design: Figurine - Empyrean Tortoise
(25032, 35696, 10, 0, 0, 1), -- Design: Figurine - Khorium Boar
(25032, 35698, 11, 0, 0, 1), -- Design: Figurine - Shadowsong Panther
(25032, 35708, 12, 0, 0, 1), -- Design: Regal Talasite
(25032, 35769, 13, 0, 0, 1), -- Design: Forceful Seaspray Emerald
(25032, 35766, 14, 0, 0, 1), -- Design: Steady Seaspray Emerald
(25032, 35767, 15, 0, 0, 1), -- Design: Reckless Pyrestone
(25032, 35768, 16, 0, 0, 1), -- Design: Quick Lionseye
(25032, 34673, 17, 0, 0, 1), -- Legionfoe
(25032, 34670, 18, 0, 0, 1), -- Seeker's Gavel
(25032, 34667, 19, 0, 0, 1), -- Archmage's Guile
(25032, 34674, 20, 0, 0, 1), -- Truestrike Crossbow
(25032, 34671, 21, 0, 0, 1), -- K'iru's Presage
(25032, 34665, 22, 0, 0, 1), -- Bombardier's Blade
(25032, 34666, 23, 0, 0, 1), -- The Sunbreaker
(25032, 34672, 24, 0, 0, 1), -- Inuuro's Blade
(25032, 34675, 25, 0, 0, 1), -- Sunward Crest
(25032, 34676, 26, 0, 0, 1), -- Dawnforged Defender
(25032, 34678, 27, 0, 0, 1), -- Shattered Sun Pendant of Acumen
(25032, 34677, 28, 0, 0, 1), -- Shattered Sun Pendant of Restoration
(25032, 34680, 29, 0, 0, 1), -- Shattered Sun Pendant of Resolve
(25032, 34679, 30, 0, 0, 1), -- Shattered Sun Pendant of Might
(25032, 35755, 31, 0, 0, 1), -- Recipe: Assassin's Alchemist Stone
(25032, 35752, 32, 0, 0, 1), -- Recipe: Guardian's Alchemist Stone
(25032, 35754, 33, 0, 0, 1), -- Recipe: Redeemer's Alchemist Stone
(25032, 35753, 34, 0, 0, 1), -- Recipe: Sorcerer's Alchemist Stone
(25032, 35221, 35, 0, 0, 1), -- Tabard of the Shattered Sun
-- 18907 (Innkeeper Coryth Stoktron)
(18907, 8950, 1, 0, 0, 1), -- Homemade Cherry Pie
(18907, 27855, 2, 0, 0, 1), -- Mag'har Grainbread
(18907, 29449, 3, 0, 0, 1), -- Bladespire Bagel
(18907, 8766, 4, 0, 0, 1), -- Morning Glory Dew
(18907, 28399, 5, 0, 0, 1), -- Filtered Draenic Water
(18907, 27860, 6, 0, 0, 1), -- Purified Draenic Water
(18907, 159, 7, 0, 0, 1), -- Refreshing Spring Water
(18907, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(18907, 30744, 9, 0, 0, 1), -- Draenic Leather Pack
(18907, 4470, 10, 0, 0, 1), -- Simple Wood
(18907, 14341, 11, 0, 0, 1), -- Rune Thread
(18907, 3371, 12, 0, 0, 1), -- Crystal Vial
(18907, 6532, 13, 0, 0, 1), -- Bright Baubles
(18907, 10648, 14, 0, 0, 1), -- Common Parchment
(18907, 29112, 15, 0, 0, 1), -- Cenarion Spirits
-- 21172 (Sarinei Whitestar)
(21172, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(21172, 28399, 2, 0, 0, 1), -- Filtered Draenic Water
(21172, 27855, 3, 0, 0, 1), -- Mag'har Grainbread
(21172, 4499, 4, 0, 0, 1), -- Huge Brown Sack
(21172, 30744, 5, 0, 0, 1), -- Draenic Leather Pack
(21172, 4470, 6, 0, 0, 1), -- Simple Wood
-- 28718 (Ranid Glowergold)
(28718, 7005, 1, 0, 0, 1), -- Skinning Knife
(28718, 2320, 2, 0, 0, 1), -- Coarse Thread
(28718, 2321, 3, 0, 0, 1), -- Fine Thread
(28718, 4291, 4, 0, 0, 1), -- Silken Thread
(28718, 8343, 5, 0, 0, 1), -- Heavy Silken Thread
(28718, 14341, 6, 0, 0, 1), -- Rune Thread
(28718, 4289, 7, 0, 0, 1), -- Salt
(28718, 38426, 8, 0, 0, 1), -- Eternium Thread
(28718, 2325, 9, 0, 0, 1), -- Black Dye
(28718, 6260, 10, 0, 0, 1), -- Blue Dye
(28718, 2604, 11, 0, 0, 1), -- Red Dye
(28718, 2605, 12, 0, 0, 1), -- Green Dye
(28718, 4340, 13, 0, 0, 1), -- Gray Dye
(28718, 4341, 14, 0, 0, 1), -- Yellow Dye
(28718, 6261, 15, 0, 0, 1), -- Orange Dye
(28718, 4342, 16, 0, 0, 1), -- Purple Dye
(28718, 10290, 17, 0, 0, 1), -- Pink Dye
-- 8403 (Jeremiah Payson)
(8403, 10393, 1, 0, 0, 1), -- Cockroach
-- 18756 (Haris Pilton)
(18756, 38082, 2257, 0, 0, 1), -- "Gigantique" Bag
(18756, 51809, 2258, 0, 0, 1), -- Portable Hole
(18756, 38091, 2259, 1, 0, 1), -- Gold Eternium Band
(18756, 37934, 2260, 1, 0, 1), -- Noble's Elementium Signet
(18756, 38090, 2261, 1, 0, 1), -- Sapphire Pinky Ring
(18756, 71037, 2262, 0, 0, 1), -- -Unknown-
-- 40160 (Frozo the Renowned)
(40160, 45087, 1, 0, 2987, 1), -- Runed Orb
(40160, 47556, 2, 0, 2986, 1), -- Crusader Orb
(40160, 35625, 3, 0, 2985, 1), -- Eternal Life
(40160, 35627, 4, 0, 2985, 1), -- Eternal Shadow
(40160, 36860, 5, 0, 2985, 1), -- Eternal Fire
(40160, 35622, 6, 0, 2985, 1), -- Eternal Water
(40160, 35623, 7, 0, 2985, 1), -- Eternal Air
(40160, 35624, 8, 0, 2985, 1), -- Eternal Earth
(40160, 36908, 9, 0, 2985, 1), -- Frost Lotus
(40160, 54798, 10, 0, 2986, 1), -- Pattern: Frosty Flying Carpet
-- 3613 (Meri Ironweave)
(3613, 2392, 1, 0, 0, 1), -- Light Mail Armor
(3613, 2393, 2, 0, 0, 1), -- Light Mail Belt
(3613, 2394, 3, 0, 0, 1), -- Light Mail Leggings
(3613, 2395, 4, 0, 0, 1), -- Light Mail Boots
(3613, 2396, 5, 0, 0, 1), -- Light Mail Bracers
(3613, 2397, 6, 0, 0, 1), -- Light Mail Gloves
(3613, 17186, 7, 0, 0, 1), -- Small Targe
(3613, 1201, 8, 0, 0, 1), -- Dull Heater Shield
-- 3610 (Jeena Featherbow)
(3610, 2506, 1, 0, 0, 1), -- Hornwood Recurve Bow
(3610, 2507, 2, 0, 0, 1), -- Laminated Recurve Bow
-- 4167 (Dendrythis)
(4167, 16166, 1, 0, 0, 1), -- Bean Soup
(4167, 16167, 2, 0, 0, 1), -- Versicolor Treat
(4167, 16170, 3, 0, 0, 1), -- Steamed Mandu
(4167, 16169, 4, 0, 0, 1), -- Wild Ricecake
(4167, 16168, 5, 0, 0, 1), -- Heaven Peach
(4167, 21030, 6, 0, 0, 1), -- Darnassus Kimchi Pie
(4167, 21033, 7, 0, 0, 1), -- Radish Kimchi
(4167, 21031, 8, 0, 0, 1), -- Cabbage Kimchi
(4167, 159, 9, 0, 0, 1), -- Refreshing Spring Water
(4167, 1179, 10, 0, 0, 1), -- Ice Cold Milk
(4167, 1205, 11, 0, 0, 1), -- Melon Juice
(4167, 1708, 12, 0, 0, 1), -- Sweet Nectar
(4167, 1645, 13, 0, 0, 1), -- Moonberry Juice
(4167, 8766, 14, 0, 0, 1), -- Morning Glory Dew
-- 17485 (Esbina)
(17485, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 28870 (Corpsedust)
(28870, 17034, 1, 0, 0, 1), -- Maple Seed
(28870, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(28870, 17032, 3, 0, 0, 1), -- Rune of Portals
(28870, 17020, 4, 0, 0, 1), -- Arcane Powder
(28870, 17030, 5, 0, 0, 1), -- Ankh
-- 28868 (Mulch)
(28868, 22250, 1, 0, 0, 1), -- Herb Pouch
(28868, 3371, 2, 0, 0, 1), -- Crystal Vial
-- 28589 (Gristlegut)
(28589, 38698, 1, 0, 0, 1), -- Bitter Plasma
(28589, 38706, 2, 0, 0, 1), -- Bowels 'n' Brains
-- 11185 (Xizzer Fizzbolt)
(11185, 32381, 1134, 1, 0, 1), -- Schematic: Fused Wiring
(11185, 16046, 1128, 1, 0, 1), -- Schematic: Masterwork Target Dummy
(11185, 18656, 1131, 1, 0, 1), -- Schematic: Powerful Seaforium Charge
(11185, 18652, 1133, 1, 0, 1), -- Schematic: Gyrofreeze Ice Reflector
(11185, 16050, 1130, 1, 0, 1), -- Schematic: Delicate Arcanite Converter
(11185, 5956, 1087, 0, 0, 1), -- Blacksmith Hammer
(11185, 2901, 1088, 0, 0, 1), -- Mining Pick
(11185, 4399, 1089, 0, 0, 1), -- Wooden Stock
(11185, 4400, 1090, 0, 0, 1), -- Heavy Stock
(11185, 40533, 1091, 0, 0, 1), -- Walnut Stock
(11185, 39684, 1092, 0, 0, 1), -- Hair Trigger
(11185, 2880, 1093, 0, 0, 1), -- Weak Flux
(11185, 3466, 1094, 0, 0, 1), -- Strong Flux
(11185, 10648, 1095, 0, 0, 1), -- Common Parchment
(11185, 10647, 1096, 0, 0, 1), -- Engineer's Ink
(11185, 4382, 1097, 1, 0, 1), -- Bronze Framework
(11185, 4357, 1098, 4, 0, 1), -- Rough Blasting Powder
(11185, 4364, 1099, 4, 0, 1), -- Coarse Blasting Powder
-- 4203 (Ariyell Skyshadow)
(4203, 851, 1, 0, 0, 1), -- Cutlass
(4203, 2027, 2, 0, 0, 1), -- Scimitar
(4203, 923, 3, 0, 0, 1), -- Longsword
(4203, 1198, 4, 0, 0, 1), -- Claymore
(4203, 2024, 5, 0, 0, 1), -- Espadon
(4203, 922, 6, 0, 0, 1), -- Dacian Falx
(4203, 2207, 7, 0, 0, 1), -- Jambiya
(4203, 2208, 8, 0, 0, 1), -- Poniard
(4203, 2209, 9, 0, 0, 1), -- Kris
(4203, 853, 10, 0, 0, 1), -- Hatchet
(4203, 2029, 11, 0, 0, 1), -- Cleaver
(4203, 927, 12, 0, 0, 1), -- Double Axe
(4203, 1196, 13, 0, 0, 1), -- Tabar
(4203, 2025, 14, 0, 0, 1), -- Bearded Axe
(4203, 926, 15, 0, 0, 1), -- Battle Axe
(4203, 852, 16, 0, 0, 1), -- Mace
(4203, 2028, 17, 0, 0, 1), -- Hammer
(4203, 925, 18, 0, 0, 1), -- Flail
(4203, 1197, 19, 0, 0, 1), -- Giant Mace
(4203, 2026, 20, 0, 0, 1), -- Rock Hammer
(4203, 924, 21, 0, 0, 1), -- Maul
(4203, 854, 22, 0, 0, 1), -- Quarter Staff
(4203, 2030, 23, 0, 0, 1), -- Gnarled Staff
(4203, 928, 24, 0, 0, 1), -- Long Staff
(4203, 2507, 25, 0, 0, 1), -- Laminated Recurve Bow
(4203, 3026, 26, 0, 0, 1), -- Reinforced Bow
(4203, 15905, 27, 0, 0, 1), -- Right-Handed Brass Knuckles
(4203, 15906, 28, 0, 0, 1), -- Left-Handed Brass Knuckles
(4203, 15903, 29, 0, 0, 1), -- Right-Handed Claw
(4203, 15907, 30, 0, 0, 1), -- Left-Handed Claw
(4203, 15904, 31, 0, 0, 1), -- Right-Handed Blades
(4203, 15909, 32, 0, 0, 1), -- Left-Handed Blades
(4203, 25872, 33, 0, 0, 1), -- Balanced Throwing Dagger
(4203, 25861, 34, 0, 0, 1), -- Crude Throwing Axe
(4203, 25873, 35, 0, 0, 1), -- Keen Throwing Knife
(4203, 25875, 36, 0, 0, 1), -- Deadly Throwing Axe
(4203, 25876, 37, 0, 0, 1), -- Gleaming Throwing Axe
-- 32287 (Archmage Alvareaux)
(32287, 43157, 1, 0, 0, 1), -- Tabard of the Kirin Tor
(32287, 44170, 2, 0, 0, 1), -- Helm of the Majestic Stag
(32287, 44166, 3, 0, 0, 1), -- Lightblade Rivener
(32287, 44167, 4, 0, 0, 1), -- Shroud of Dedicated Research
(32287, 44171, 5, 0, 0, 1), -- Spaulders of Grounded Lightning
(32287, 44141, 6, 0, 0, 1), -- Arcanum of the Flame's Soul
(32287, 44173, 7, 0, 0, 1), -- Flameheart Spell Scalpel
(32287, 44176, 8, 0, 0, 1), -- Girdle of the Warrior Magi
(32287, 42188, 9, 0, 0, 1), -- Pattern: Sapphire Spellthread
(32287, 44179, 10, 0, 0, 1), -- Mind-Expanding Leggings
(32287, 44174, 11, 0, 0, 1), -- Stave of Shrouded Mysteries
(32287, 44181, 12, 0, 0, 1), -- Ghostflicker Waistband
(32287, 44180, 13, 0, 0, 1), -- Robes of Crackling Flame
(32287, 44183, 14, 0, 0, 1), -- Fireproven Gauntlets
(32287, 44182, 15, 0, 0, 1), -- Boots of Twinkling Stars
(32287, 41718, 16, 0, 0, 1), -- Design: Brilliant Scarlet Ruby
(32287, 44159, 17, 0, 0, 1), -- Arcanum of Burning Mysteries
-- 3609 (Shalomon)
(3609, 2488, 1, 0, 0, 1), -- Gladius
(3609, 2489, 2, 0, 0, 1), -- Two-Handed Sword
(3609, 2490, 3, 0, 0, 1), -- Tomahawk
(3609, 2491, 4, 0, 0, 1), -- Large Axe
(3609, 2492, 5, 0, 0, 1), -- Cudgel
(3609, 2493, 6, 0, 0, 1), -- Wooden Mallet
(3609, 2494, 7, 0, 0, 1), -- Stiletto
(3609, 2495, 8, 0, 0, 1), -- Walking Stick
(3609, 25872, 9, 0, 0, 1), -- Balanced Throwing Dagger
(3609, 29007, 10, 0, 0, 1), -- Weighted Throwing Axe
-- 19239 (Mahir Redstroke)
(19239, 2526, 1, 0, 0, 1), -- Main Gauche
(19239, 2534, 2, 0, 0, 1), -- Rondel
(19239, 29010, 3, 0, 0, 1), -- Wicked Throwing Dagger
-- 23489 (Drake Dealer Hurlunk)
(23489, 32858, 1, 0, 0, 1), -- Reins of the Azure Netherwing Drake
(23489, 32859, 2, 0, 0, 1), -- Reins of the Cobalt Netherwing Drake
(23489, 32857, 3, 0, 0, 1), -- Reins of the Onyx Netherwing Drake
(23489, 32860, 4, 0, 0, 1), -- Reins of the Purple Netherwing Drake
(23489, 32861, 5, 0, 0, 1), -- Reins of the Veridian Netherwing Drake
(23489, 32862, 6, 0, 0, 1), -- Reins of the Violet Netherwing Drake
-- 22227 (Markus Scylan)
(22227, 28458, 1, 0, 0, 1), -- Bold Tourmaline
(22227, 28461, 2, 0, 0, 1), -- Brilliant Tourmaline
(22227, 28459, 3, 0, 0, 1), -- Delicate Tourmaline
(22227, 28463, 4, 0, 0, 1), -- Solid Zircon
(22227, 28464, 5, 0, 0, 1), -- Sparkling Zircon
(22227, 28468, 6, 0, 0, 1), -- Rigid Zircon
(22227, 28467, 7, 0, 0, 1), -- Smooth Amber
(22227, 28470, 8, 0, 0, 1), -- Subtle Amber
-- 21019 (Sixx)
(21019, 29901, 1, 0, 0, 1), -- Blue Moth Egg
(21019, 29904, 2, 0, 0, 1), -- White Moth Egg
(21019, 29903, 3, 0, 0, 1), -- Yellow Moth Egg
-- 33669 (Demolisher Engineer Blastwrench)
(33669, 14341, 1, 0, 0, 1), -- Rune Thread
(33669, 38426, 2, 0, 0, 1), -- Eternium Thread
(33669, 3371, 3, 0, 0, 1), -- Crystal Vial
(33669, 6532, 4, 0, 0, 1), -- Bright Baubles
(33669, 39354, 5, 0, 0, 1), -- Light Parchment
(33669, 10648, 6, 0, 0, 1), -- Common Parchment
(33669, 39501, 7, 0, 0, 1), -- Heavy Parchment
(33669, 39502, 8, 0, 0, 1), -- Resilient Parchment
(33669, 5956, 9, 0, 0, 1), -- Blacksmith Hammer
(33669, 2901, 10, 0, 0, 1), -- Mining Pick
(33669, 4399, 11, 0, 0, 1), -- Wooden Stock
(33669, 4400, 12, 0, 0, 1), -- Heavy Stock
(33669, 40533, 13, 0, 0, 1), -- Walnut Stock
(33669, 39684, 14, 0, 0, 1), -- Hair Trigger
(33669, 2880, 15, 0, 0, 1), -- Weak Flux
(33669, 3466, 16, 0, 0, 1), -- Strong Flux
(33669, 10647, 17, 0, 0, 1), -- Engineer's Ink
(33669, 4357, 18, 3, 0, 1), -- Rough Blasting Powder
(33669, 4364, 19, 2, 0, 1), -- Coarse Blasting Powder
(33669, 17037, 20, 0, 0, 1), -- Hornbeam Seed
(33669, 17031, 21, 0, 0, 1), -- Rune of Teleportation
(33669, 17032, 22, 0, 0, 1), -- Rune of Portals
(33669, 17020, 23, 0, 0, 1), -- Arcane Powder
(33669, 17030, 24, 0, 0, 1), -- Ankh
(33669, 17034, 25, 0, 0, 1), -- Maple Seed
-- 29547 (Applebough)
(29547, 43088, 1, 0, 0, 1), -- Dalaran Apple Bowl
(29547, 43086, 2, 0, 0, 1), -- Fresh Apple Juice
(29547, 4536, 3, 0, 0, 1), -- Shiny Red Apple
(29547, 4537, 4, 0, 0, 1), -- Tel'Abim Banana
(29547, 4538, 5, 0, 0, 1), -- Snapvine Watermelon
(29547, 4539, 6, 0, 0, 1), -- Goldenbark Apple
(29547, 4602, 7, 0, 0, 1), -- Moon Harvest Pumpkin
(29547, 8953, 8, 0, 0, 1), -- Deep Fried Plantains
(29547, 27856, 9, 0, 0, 1), -- Skethyl Berries
(29547, 29450, 10, 0, 0, 1), -- Telaari Grapes
(29547, 35949, 11, 0, 0, 1), -- Tundra Berries
(29547, 35948, 12, 0, 0, 1), -- Savory Snowplum
-- 27019 (Siegesmith Gulda)
(27019, 2901, 1, 0, 0, 1), -- Mining Pick
(27019, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(27019, 2880, 3, 0, 0, 1), -- Weak Flux
(27019, 3466, 4, 0, 0, 1), -- Strong Flux
(27019, 18567, 5, 0, 0, 1), -- Elemental Flux
(27019, 3857, 6, 0, 0, 1), -- Coal
-- 27022 (Afha)
(27022, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(27022, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(27022, 33449, 3, 0, 0, 1), -- Crusty Flatbread
(27022, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(27022, 4470, 5, 0, 0, 1), -- Simple Wood
-- 27021 (Tradesman Kontor)
(27021, 7005, 1, 0, 0, 1), -- Skinning Knife
(27021, 6256, 2, 0, 0, 1), -- Fishing Pole
(27021, 6217, 3, 0, 0, 1), -- Copper Rod
(27021, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(27021, 2901, 5, 0, 0, 1), -- Mining Pick
(27021, 2320, 6, 0, 0, 1), -- Coarse Thread
(27021, 2321, 7, 0, 0, 1), -- Fine Thread
(27021, 4291, 8, 0, 0, 1), -- Silken Thread
(27021, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(27021, 14341, 10, 0, 0, 1), -- Rune Thread
(27021, 2678, 11, 0, 0, 1), -- Mild Spices
(27021, 2880, 12, 0, 0, 1), -- Weak Flux
(27021, 3466, 13, 0, 0, 1), -- Strong Flux
(27021, 3857, 14, 0, 0, 1), -- Coal
(27021, 2604, 15, 0, 0, 1), -- Red Dye
(27021, 2325, 16, 0, 0, 1), -- Black Dye
(27021, 4341, 17, 0, 0, 1), -- Yellow Dye
(27021, 4342, 18, 0, 0, 1), -- Purple Dye
(27021, 4340, 19, 0, 0, 1), -- Gray Dye
(27021, 3371, 20, 0, 0, 1), -- Crystal Vial
(27021, 4289, 21, 0, 0, 1), -- Salt
(27021, 4399, 22, 0, 0, 1), -- Wooden Stock
(27021, 4400, 23, 0, 0, 1), -- Heavy Stock
(27021, 6530, 24, 0, 0, 1), -- Nightcrawlers
(27021, 6532, 25, 0, 0, 1), -- Bright Baubles
(27021, 38426, 26, 0, 0, 1), -- Eternium Thread
(27021, 39354, 27, 0, 0, 1), -- Light Parchment
(27021, 10648, 28, 0, 0, 1), -- Common Parchment
(27021, 39501, 29, 0, 0, 1), -- Heavy Parchment
(27021, 39502, 30, 0, 0, 1), -- Resilient Parchment
-- 26567 (Aegalas)
(26567, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(26567, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(26567, 33445, 3, 0, 0, 1), -- Honeymint Tea
(26567, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(26567, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
(26567, 33443, 6, 0, 0, 1), -- Sour Goat Cheese
(26567, 35952, 7, 0, 0, 1), -- Briny Hardcheese
(26567, 33451, 8, 0, 0, 1), -- Fillet of Icefin
(26567, 35951, 9, 0, 0, 1), -- Poached Emperor Salmon
(26567, 35949, 10, 0, 0, 1), -- Tundra Berries
(26567, 35948, 11, 0, 0, 1), -- Savory Snowplum
(26567, 33454, 12, 0, 0, 1), -- Salted Venison
(26567, 35953, 13, 0, 0, 1), -- Mead Basted Caribou
-- 29636 (Hagatha Moorehead)
(29636, 17034, 1, 0, 0, 1), -- Maple Seed
(29636, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(29636, 17032, 3, 0, 0, 1), -- Rune of Portals
(29636, 17020, 4, 0, 0, 1), -- Arcane Powder
(29636, 17030, 5, 0, 0, 1), -- Ankh
-- 32564 (Logistics Officer Silverstone)
(32564, 38464, 1, 0, 0, 1), -- Gnomish Magician's Quill
(32564, 38455, 2, 0, 0, 1), -- Hammer of the Alliance Vanguard
(32564, 38463, 3, 0, 0, 1), -- Lordaeron's Resolve 
(32564, 38459, 4, 0, 0, 1), -- Orb of the Eastern Kingdoms
(32564, 38457, 5, 0, 0, 1), -- Sawed-Off Hand Cannon
(32564, 38453, 6, 0, 0, 1), -- Shield of the Lion-Hearted
(32564, 38465, 7, 0, 0, 1), -- Vanguard Soldier's Dagger
(32564, 44503, 8, 0, 0, 1), -- Schematic: Mekgineer's Chopper
(32564, 44937, 9, 0, 0, 1), -- Plans: Titanium Plating
(32564, 50372, 11, 0, 0, 1), -- Arcanum of the Savage Gladiator
-- 35131 (Durgan Thunderbeak)
(35131, 25471, 1, 0, 0, 1), -- Ebon Gryphon
(35131, 25470, 2, 0, 0, 1), -- Golden Gryphon
(35131, 25472, 3, 0, 0, 1), -- Snowy Gryphon
(35131, 25473, 4, 0, 0, 1), -- Swift Blue Gryphon
(35131, 25528, 5, 0, 0, 1), -- Swift Green Gryphon
(35131, 25529, 6, 0, 0, 1), -- Swift Purple Gryphon
(35131, 25527, 7, 0, 0, 1), -- Swift Red Gryphon
-- 27026 (Rohesia Werner)
(27026, 7005, 1, 0, 0, 1), -- Skinning Knife
(27026, 6256, 2, 0, 0, 1), -- Fishing Pole
(27026, 6217, 3, 0, 0, 1), -- Copper Rod
(27026, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(27026, 2901, 5, 0, 0, 1), -- Mining Pick
(27026, 2320, 6, 0, 0, 1), -- Coarse Thread
(27026, 2321, 7, 0, 0, 1), -- Fine Thread
(27026, 4291, 8, 0, 0, 1), -- Silken Thread
(27026, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(27026, 14341, 10, 0, 0, 1), -- Rune Thread
(27026, 2678, 11, 0, 0, 1), -- Mild Spices
(27026, 2880, 12, 0, 0, 1), -- Weak Flux
(27026, 3466, 13, 0, 0, 1), -- Strong Flux
(27026, 3857, 14, 0, 0, 1), -- Coal
(27026, 2604, 15, 0, 0, 1), -- Red Dye
(27026, 2325, 16, 0, 0, 1), -- Black Dye
(27026, 4341, 17, 0, 0, 1), -- Yellow Dye
(27026, 4342, 18, 0, 0, 1), -- Purple Dye
(27026, 4340, 19, 0, 0, 1), -- Gray Dye
(27026, 3371, 20, 0, 0, 1), -- Crystal Vial
(27026, 4289, 21, 0, 0, 1), -- Salt
(27026, 4399, 22, 0, 0, 1), -- Wooden Stock
(27026, 4400, 23, 0, 0, 1), -- Heavy Stock
(27026, 6530, 24, 0, 0, 1), -- Nightcrawlers
(27026, 6532, 25, 0, 0, 1), -- Bright Baubles
(27026, 38426, 26, 0, 0, 1), -- Eternium Thread
(27026, 39354, 27, 0, 0, 1), -- Light Parchment
(27026, 10648, 28, 0, 0, 1), -- Common Parchment
(27026, 39501, 29, 0, 0, 1), -- Heavy Parchment
(27026, 39502, 30, 0, 0, 1), -- Resilient Parchment
-- 49519
(49519, 58278, 1, 0, 0, 1), -- Tropical Sunfruit
(49519, 58264, 2, 0, 0, 1), -- Sour Green Apple
(49519, 58265, 3, 0, 0, 1), -- Highland Pomegranate
(49519, 58276, 4, 0, 0, 1), -- Gilnean White
(49519, 58258, 5, 0, 0, 1), -- Smoked String Cheese
(49519, 58259, 6, 0, 0, 1), -- Highland Sheep Cheese
(49519, 58280, 7, 0, 0, 1), -- Stewed Rabbit
(49519, 58268, 8, 0, 0, 1), -- Roasted Beef
(49519, 58269, 9, 0, 0, 1), -- Massive Turkey Leg
(49519, 58274, 10, 0, 0, 1), -- Fresh Water
(49519, 58256, 11, 0, 0, 1), -- Sparkling Oasis Water
(49519, 58257, 12, 0, 0, 1), -- Highland Spring Water
-- 43408
(43408, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 41903
(41903, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 29261 (Windle Sparkshine)
(29261, 44435, 1, 0, 0, 1), -- Windle's Lighter
-- 45408
(45408, 65907, 1, 0, 0, 1), -- Tabard of Therazane
(45408, 62342, 2, 0, 0, 1), -- Lesser Inscription of Charged Lodestone
(45408, 62344, 3, 0, 0, 1), -- Lesser Inscription of Jagged Stone
(45408, 62347, 4, 0, 0, 1), -- Lesser Inscription of Shattered Crystal
(45408, 62321, 5, 0, 0, 1), -- Lesser Inscription of Unbreakable Quartz
(45408, 62350, 6, 0, 0, 1), -- Gorsik's Band of Shattering
(45408, 62348, 7, 0, 0, 1), -- Terrath's Signet of Balance
(45408, 62352, 8, 0, 0, 1), -- Diamant's Ring of Temperance
(45408, 62351, 9, 0, 0, 1), -- Felsen's Ring of Resolve
(45408, 62343, 10, 0, 0, 1), -- Greater Inscription of Charged Lodestone
(45408, 62345, 11, 0, 0, 1), -- Greater Inscription of Jagged Stone
(45408, 62346, 12, 0, 0, 1), -- Greater Inscription of Shattered Crystal
(45408, 62333, 13, 0, 0, 1), -- Greater Inscription of Unbreakable Quartz
-- 27133 (Seer Yagnar)
(27133, 17034, 1, 0, 0, 1), -- Maple Seed
(27133, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(27133, 17032, 3, 0, 0, 1), -- Rune of Portals
(27133, 17020, 4, 0, 0, 1), -- Arcane Powder
(27133, 17030, 5, 0, 0, 1), -- Ankh
-- 26707 (Litoko Icetotem)
(26707, 2435, 1, 0, 0, 1), -- Embroidered Armor
(26707, 3587, 2, 0, 0, 1), -- Embroidered Belt
(26707, 2437, 3, 0, 0, 1), -- Embroidered Pants
(26707, 2438, 4, 0, 0, 1), -- Embroidered Boots
(26707, 3588, 5, 0, 0, 1), -- Embroidered Bracers
(26707, 2440, 6, 0, 0, 1), -- Embroidered Gloves
(26707, 3892, 7, 0, 0, 1), -- Embroidered Hat
(26707, 2470, 8, 0, 0, 1), -- Reinforced Leather Vest
(26707, 2471, 9, 0, 0, 1), -- Reinforced Leather Belt
(26707, 2472, 10, 0, 0, 1), -- Reinforced Leather Pants
(26707, 2473, 11, 0, 0, 1), -- Reinforced Leather Boots
(26707, 2474, 12, 0, 0, 1), -- Reinforced Leather Bracers
(26707, 2475, 13, 0, 0, 1), -- Reinforced Leather Gloves
(26707, 3893, 14, 0, 0, 1), -- Reinforced Leather Cap
-- 26936 (Chaska Frosthoof)
(26936, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(26936, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(26936, 33449, 3, 0, 0, 1), -- Crusty Flatbread
(26936, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(26936, 4470, 5, 0, 0, 1), -- Simple Wood
-- 29277 (Datalore Smallsphere)
(29277, 14341, 1, 0, 0, 1), -- Rune Thread
(29277, 3371, 2, 0, 0, 1), -- Crystal Vial
(29277, 6532, 3, 0, 0, 1), -- Bright Baubles
(29277, 10648, 4, 0, 0, 1), -- Common Parchment
(29277, 38426, 5, 0, 0, 1), -- Eternium Thread
(29277, 39354, 6, 0, 0, 1), -- Light Parchment
(29277, 39501, 7, 0, 0, 1), -- Heavy Parchment
(29277, 39502, 8, 0, 0, 1), -- Resilient Parchment
-- 26868 (Provisioner Lorkran)
(26868, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(26868, 30817, 2, 0, 0, 1), -- Simple Flour
(26868, 2678, 3, 0, 0, 1), -- Mild Spices
(26868, 21099, 4, 0, 0, 1), -- Recipe: Smoked Sagefish
(26868, 21219, 5, 0, 0, 1), -- Recipe: Sagefish Delight
(26868, 33454, 6, 0, 0, 1), -- Salted Venison
(26868, 35953, 7, 0, 0, 1), -- Mead Basted Caribou
-- 27134 (Smith Prigka)
(27134, 2901, 1, 0, 0, 1), -- Mining Pick
(27134, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(27134, 2880, 3, 0, 0, 1), -- Weak Flux
(27134, 3466, 4, 0, 0, 1), -- Strong Flux
(27134, 18567, 5, 0, 0, 1), -- Elemental Flux
(27134, 3857, 6, 0, 0, 1), -- Coal
-- 33865 (Makuli)
(33865, 33451, 1, 0, 0, 1), -- Fillet of Icefin
(33865, 35951, 2, 0, 0, 1), -- Poached Emperor Salmon
(33865, 33454, 3, 0, 0, 1), -- Salted Venison
(33865, 35953, 4, 0, 0, 1), -- Mead Basted Caribou
(33865, 33449, 5, 0, 0, 1), -- Crusty Flatbread
(33865, 35950, 6, 0, 0, 1), -- Sweet Potato Bread
(33865, 33443, 7, 0, 0, 1), -- Sour Goat Cheese
(33865, 35952, 8, 0, 0, 1), -- Briny Hardcheese
(33865, 35949, 9, 0, 0, 1), -- Tundra Berries
(33865, 35948, 10, 0, 0, 1), -- Savory Snowplum
(33865, 33452, 11, 0, 0, 1), -- Honey-Spiced Lichen
(33865, 35947, 12, 0, 0, 1), -- Sparkling Frostcap
-- 58153
(58153, 78890, 1, 0, 3819, 1), -- Crystalline Geode
(58153, 78891, 2, 0, 3820, 1), -- Elementium-Coated Geode
-- 18382 (Mycah)
(18382, 30156, 1, 0, 100, 1), -- Recipe: Clam Bar
(18382, 24539, 2, 0, 102, 1), -- Marsh Lichen
(18382, 25548, 3, 0, 100, 1), -- Tallstalk Mushroom
(18382, 25550, 4, 0, 100, 1), -- Redcap Toadstool
(18382, 25827, 5, 0, 103, 1), -- Muck-Covered Drape
(18382, 25828, 6, 0, 104, 1), -- Petrified Lichen Guard
(18382, 29149, 7, 0, 1076, 1), -- Sporeling's Firestick
(18382, 29150, 8, 0, 1077, 1), -- Hardened Stone Shard
(18382, 22916, 9, 0, 103, 1), -- Recipe: Transmute Primal Earth to Water
(18382, 38229, 10, 0, 103, 1), -- Pattern: Mycah's Botanical Bag
(18382, 22906, 11, 0, 388, 1), -- Recipe: Shrouding Potion
(18382, 31775, 12, 0, 1994, 1), -- Sporeggar Tabard
(18382, 34478, 13, 0, 388, 1); -- Tiny Sporebat
