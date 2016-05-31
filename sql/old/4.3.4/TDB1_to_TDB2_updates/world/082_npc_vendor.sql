DELETE FROM `npc_vendor` WHERE (`entry`=55264 AND `slot`=6) OR (`entry`=55264 AND `slot`=13) OR (`entry`=3323 AND `slot`=0) OR (`entry`=3350 AND `slot`=0) OR (`entry`=3351 AND `slot`=0) OR (`entry`=5611 AND `slot`=0);

DELETE FROM `npc_vendor` WHERE `entry` IN (55305, 29926, 29904, 29905, 29908, 35291, 33866, 33869, 3358, 50482, 57922, 46572, 27816, 48510, 3405, 3361, 3360, 4043, 3409, 5812, 3356, 3362);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 55264 (Sazz Coincatcher)
(55264, 78903, 6, 0, 0, 1), -- Pouch o' Tokens
(55264, 78909, 13, 0, 0, 1), -- Sack o' Tokens
-- 55305 (Carl Goodup)
(55305, 73762, 1, 0, 3700, 1), -- Darkmoon Balloon
(55305, 75040, 2, 0, 0, 1), -- Flimsy Darkmoon Balloon
(55305, 75041, 3, 0, 0, 1), -- Flimsy Green Balloon
(55305, 75042, 4, 0, 0, 1), -- Flimsy Yellow Balloon
-- 29926 (Gunda Boldhammer)
(29926, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(29926, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(29926, 33445, 3, 0, 0, 1), -- Honeymint Tea
(29926, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(29926, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
-- 29904 (Smilin' Slirk Brassknob)
(29904, 35954, 1, 0, 0, 1), -- Sweetened Goat's Milk
(29904, 33444, 2, 0, 0, 1), -- Pungent Seal Whey
(29904, 33445, 3, 0, 0, 1), -- Honeymint Tea
(29904, 33449, 4, 0, 0, 1), -- Crusty Flatbread
(29904, 35950, 5, 0, 0, 1), -- Sweet Potato Bread
-- 29905 (Grillix Bonesaw)
(29905, 33454, 1, 0, 0, 1), -- Salted Venison
(29905, 35953, 2, 0, 0, 1), -- Mead Basted Caribou
-- 29908 (Plip Fatpurse)
(29908, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(29908, 35954, 2, 0, 0, 1), -- Sweetened Goat's Milk
(29908, 33449, 3, 0, 0, 1), -- Crusty Flatbread
(29908, 60335, 4, 0, 0, 1), -- Thick Hide Pack
(29908, 4470, 5, 0, 0, 1), -- Simple Wood
-- 35291 (Moonbell)
(35291, 37460, 1, 0, 0, 1), -- Rope Pet Leash
-- 33866 (Akrittok)
(33866, 33451, 1, 0, 0, 1), -- Fillet of Icefin
(33866, 35951, 2, 0, 0, 1), -- Poached Emperor Salmon
(33866, 33454, 3, 0, 0, 1), -- Salted Venison
(33866, 35953, 4, 0, 0, 1), -- Mead Basted Caribou
(33866, 33449, 5, 0, 0, 1), -- Crusty Flatbread
(33866, 35950, 6, 0, 0, 1), -- Sweet Potato Bread
(33866, 33443, 7, 0, 0, 1), -- Sour Goat Cheese
(33866, 35952, 8, 0, 0, 1), -- Briny Hardcheese
(33866, 35949, 9, 0, 0, 1), -- Tundra Berries
(33866, 35948, 10, 0, 0, 1), -- Savory Snowplum
(33866, 33452, 11, 0, 0, 1), -- Honey-Spiced Lichen
(33866, 35947, 12, 0, 0, 1), -- Sparkling Frostcap
-- 33869 (Torngasak)
(33869, 40035, 1, 0, 0, 1), -- Honey Mead
(33869, 40036, 2, 0, 0, 1), -- Snowplum Brandy
(33869, 40042, 3, 0, 0, 1), -- Caraway Burnwine
(33869, 35954, 4, 0, 0, 1), -- Sweetened Goat's Milk
(33869, 33444, 5, 0, 0, 1), -- Pungent Seal Whey
(33869, 33445, 6, 0, 0, 1), -- Honeymint Tea
-- 3358 (Gorina)
(3358, 2901, 1, 0, 0, 1), -- Mining Pick
(3358, 30746, 2, 0, 0, 1), -- Mining Sack
(3358, 2880, 3, 0, 0, 1), -- Weak Flux
(3358, 3466, 4, 0, 0, 1), -- Strong Flux
(3358, 3857, 5, 0, 0, 1), -- Coal
(3358, 20824, 6, 0, 0, 1), -- Simple Grinder
(3358, 20815, 7, 0, 0, 1), -- Jeweler's Kit
-- 50482 (Marith Lazuria)
(50482, 20815, 1, 0, 0, 1), -- Jeweler's Kit
(50482, 20824, 2, 0, 0, 1), -- Simple Grinder
(50482, 52188, 3, 0, 0, 1), -- Jeweler's Setting
(50482, 52196, 4, 0, 3232, 1), -- Chimera's Eye
(50482, 52381, 5, 0, 2972, 1), -- Design: Bold Chimera's Eye
(50482, 52449, 6, 0, 2972, 1), -- Design: Brilliant Chimera's Eye
(50482, 52447, 7, 0, 2972, 1), -- Design: Delicate Chimera's Eye
(50482, 52448, 8, 0, 2972, 1), -- Design: Flashing Chimera's Eye
(50482, 52459, 9, 0, 2972, 1), -- Design: Fractured Chimera's Eye
(50482, 52457, 10, 0, 2972, 1), -- Design: Mystic Chimera's Eye
(50482, 52450, 11, 0, 2972, 1), -- Design: Precise Chimera's Eye
(50482, 52458, 12, 0, 2972, 1), -- Design: Quick Chimera's Eye
(50482, 52454, 13, 0, 2972, 1), -- Design: Rigid Chimera's Eye
(50482, 52456, 14, 0, 2972, 1), -- Design: Smooth Chimera's Eye
(50482, 52451, 15, 0, 2972, 1), -- Design: Solid Chimera's Eye
(50482, 52452, 16, 0, 2972, 1), -- Design: Sparkling Chimera's Eye
(50482, 52453, 17, 0, 2972, 1), -- Design: Stormy Chimera's Eye
(50482, 52455, 18, 0, 2972, 1), -- Design: Subtle Chimera's Eye
(50482, 52398, 19, 0, 2970, 1), -- Design: Fractured Amberjewel
(50482, 52396, 20, 0, 2970, 1), -- Design: Mystic Amberjewel
(50482, 52397, 21, 0, 2970, 1), -- Design: Quick Amberjewel
(50482, 52395, 22, 0, 2970, 1), -- Design: Smooth Amberjewel
(50482, 52394, 23, 0, 2970, 1), -- Design: Subtle Amberjewel
(50482, 52409, 24, 0, 2970, 1), -- Design: Accurate Demonseye
(50482, 52401, 25, 0, 2970, 1), -- Design: Defender's Demonseye
(50482, 52405, 26, 0, 2970, 1), -- Design: Etched Demonseye
(50482, 52408, 27, 0, 2970, 1), -- Design: Veiled Demonseye
(50482, 52406, 28, 0, 2970, 1), -- Design: Glinting Demonseye
(50482, 52403, 29, 0, 2970, 1), -- Design: Guardian's Demonseye
(50482, 52407, 30, 0, 2970, 1), -- Design: Retaliating Demonseye
(50482, 52404, 31, 0, 2970, 1), -- Design: Purified Demonseye
(50482, 52400, 32, 0, 2970, 1), -- Design: Shifting Demonseye
(50482, 52399, 33, 0, 2970, 1), -- Design: Sovereign Demonseye
(50482, 52402, 34, 0, 2970, 1), -- Design: Timeless Demonseye
(50482, 52428, 35, 0, 2970, 1), -- Design: Forceful Dream Emerald
(50482, 52425, 36, 0, 2970, 1), -- Design: Jagged Dream Emerald
(50482, 52429, 37, 0, 2970, 1), -- Design: Lightning Dream Emerald
(50482, 52424, 38, 0, 2970, 1), -- Design: Nimble Dream Emerald
(50482, 52426, 39, 0, 2970, 1), -- Design: Piercing Dream Emerald
(50482, 52430, 40, 0, 2970, 1), -- Design: Puissant Dream Emerald
(50482, 52423, 41, 0, 2970, 1), -- Design: Regal Dream Emerald
(50482, 52432, 42, 0, 2970, 1), -- Design: Sensei's Dream Emerald
(50482, 52427, 43, 0, 2970, 1), -- Design: Steady Dream Emerald
(50482, 68742, 44, 0, 2970, 1), -- Design: Vivid Dream Emerald
(50482, 52431, 45, 0, 2970, 1), -- Design: Zen Dream Emerald
(50482, 52419, 46, 0, 2970, 1), -- Design: Adept Ember Topaz
(50482, 52421, 47, 0, 2970, 1), -- Design: Artful Ember Topaz
(50482, 52417, 48, 0, 2970, 1), -- Design: Reckless Ember Topaz
(50482, 52413, 49, 0, 2970, 1), -- Design: Deadly Ember Topaz
(50482, 52416, 50, 0, 2970, 1), -- Design: Deft Ember Topaz
(50482, 52415, 51, 0, 2970, 1), -- Design: Fierce Ember Topaz
(50482, 52420, 52, 0, 2970, 1), -- Design: Fine Ember Topaz
(50482, 52412, 53, 0, 2970, 1), -- Design: Inscribed Ember Topaz
(50482, 52422, 54, 0, 2970, 1), -- Design: Keen Ember Topaz
(50482, 68360, 55, 0, 2970, 1), -- Design: Lucent Ember Topaz
(50482, 52410, 56, 0, 2970, 1), -- Design: Polished Ember Topaz
(50482, 52414, 57, 0, 2970, 1), -- Design: Potent Ember Topaz
(50482, 52418, 58, 0, 2970, 1), -- Design: Skillful Ember Topaz
(50482, 52411, 59, 0, 2970, 1), -- Design: Resolute Ember Topaz
(50482, 68361, 60, 0, 2970, 1), -- Design: Resplendent Ember Topaz
(50482, 68359, 61, 0, 2970, 1), -- Design: Willful Ember Topaz
(50482, 52362, 62, 0, 2970, 1), -- Design: Bold Inferno Ruby
(50482, 52387, 63, 0, 2970, 1), -- Design: Brilliant Inferno Ruby
(50482, 52380, 64, 0, 2970, 1), -- Design: Delicate Inferno Ruby
(50482, 52384, 65, 0, 2970, 1), -- Design: Flashing Inferno Ruby
(50482, 52389, 66, 0, 2970, 1), -- Design: Precise Inferno Ruby
(50482, 52393, 67, 0, 2970, 1), -- Design: Rigid Ocean Sapphire
(50482, 52390, 68, 0, 2970, 1), -- Design: Solid Ocean Sapphire
(50482, 52391, 69, 0, 2970, 1), -- Design: Sparkling Ocean Sapphire
(50482, 52392, 70, 0, 2970, 1), -- Design: Stormy Ocean Sapphire
(50482, 52437, 71, 0, 2971, 1), -- Design: Austere Shadowspirit Diamond
(50482, 52435, 72, 0, 2971, 1), -- Design: Bracing Shadowspirit Diamond
(50482, 52434, 73, 0, 2971, 1), -- Design: Chaotic Shadowspirit Diamond
(50482, 52441, 74, 0, 2971, 1), -- Design: Destructive Shadowspirit Diamond
(50482, 52438, 75, 0, 2971, 1), -- Design: Effulgent Shadowspirit Diamond
(50482, 52439, 76, 0, 2971, 1), -- Design: Ember Shadowspirit Diamond
(50482, 52443, 77, 0, 2971, 1), -- Design: Enigmatic Shadowspirit Diamond
(50482, 52436, 78, 0, 2971, 1), -- Design: Eternal Shadowspirit Diamond
(50482, 52433, 79, 0, 2971, 1), -- Design: Fleet Shadowspirit Diamond
(50482, 52445, 80, 0, 2971, 1), -- Design: Forlorn Shadowspirit Diamond
(50482, 52444, 81, 0, 2971, 1), -- Design: Impassive Shadowspirit Diamond
(50482, 52442, 82, 0, 2971, 1), -- Design: Powerful Shadowspirit Diamond
(50482, 52440, 83, 0, 2971, 1), -- Design: Revitalizing Shadowspirit Diamond
(50482, 69853, 84, 0, 2973, 1), -- Design: Punisher's Band
(50482, 52460, 85, 0, 2973, 1), -- Design: Elementium Destroyer's Ring
(50482, 52461, 86, 0, 2973, 1), -- Design: Band of Blades
(50482, 52463, 87, 0, 2973, 1), -- Design: Elementium Moebius Band
(50482, 52462, 88, 0, 2973, 1), -- Design: Ring of Warring Elements
(50482, 52467, 89, 0, 2973, 1), -- Design: Elementium Guardian
(50482, 52465, 90, 0, 2973, 1), -- Design: Entwined Elementium Choker
(50482, 52464, 91, 0, 2973, 1), -- Design: Brazen Elementium Medallion
(50482, 52466, 92, 0, 2973, 1), -- Design: Eye of Many Deaths
-- 57922 (Taryssa Lazuria)
(57922, 71949, 1, 0, 2971, 1), -- Tome of Burning Jewels
(57922, 71943, 2, 0, 2973, 1), -- Design: Bold Queen's Garnet
(57922, 71941, 3, 0, 2973, 1), -- Design: Brilliant Queen's Garnet
(57922, 71939, 4, 0, 2973, 1), -- Design: Delicate Queen's Garnet
(57922, 71942, 5, 0, 2973, 1), -- Design: Flashing Queen's Garnet
(57922, 71940, 6, 0, 2973, 1), -- Design: Precise Queen's Garnet
(57922, 71917, 7, 0, 2973, 1), -- Design: Adept Lava Coral
(57922, 71919, 8, 0, 2973, 1), -- Design: Artful Lava Coral
(57922, 71912, 9, 0, 2973, 1), -- Design: Champion's Lava Coral
(57922, 71906, 10, 0, 2973, 1), -- Design: Crafty Lava Coral
(57922, 71905, 11, 0, 2973, 1), -- Design: Deadly Lava Coral
(57922, 71913, 12, 0, 2973, 1), -- Design: Deft Lava Coral
(57922, 71916, 13, 0, 2973, 1), -- Design: Fierce Lava Coral
(57922, 71920, 14, 0, 2973, 1), -- Design: Fine Lava Coral
(57922, 71908, 15, 0, 2973, 1), -- Design: Inscribed Lava Coral
(57922, 71918, 16, 0, 2973, 1), -- Design: Keen Lava Coral
(57922, 71922, 17, 0, 2973, 1), -- Design: Lucent Lava Coral
(57922, 71909, 18, 0, 2973, 1), -- Design: Polished Lava Coral
(57922, 71907, 19, 0, 2973, 1), -- Design: Potent Lava Coral
(57922, 71915, 20, 0, 2973, 1), -- Design: Reckless Lava Coral
(57922, 71910, 21, 0, 2973, 1), -- Design: Resolute Lava Coral
(57922, 71926, 22, 0, 2973, 1), -- Design: Resplendent Lava Coral
(57922, 71921, 23, 0, 2973, 1), -- Design: Skillful Lava Coral
(57922, 71925, 24, 0, 2973, 1), -- Design: Splendid Lava Coral
(57922, 71911, 25, 0, 2973, 1), -- Design: Stalwart Lava Coral
(57922, 71923, 26, 0, 2973, 1), -- Design: Tenuous Lava Coral
(57922, 71914, 27, 0, 2973, 1), -- Design: Wicked Lava Coral
(57922, 71924, 28, 0, 2973, 1), -- Design: Willful Lava Coral
(57922, 71928, 29, 0, 2973, 1), -- Design: Accurate Shadow Spinel
(57922, 71937, 30, 0, 2973, 1), -- Design: Defender's Shadow Spinel
(57922, 71931, 31, 0, 2973, 1), -- Design: Etched Shadow Spinel
(57922, 71927, 32, 0, 2973, 1), -- Design: Glinting Shadow Spinel
(57922, 71935, 33, 0, 2973, 1), -- Design: Guardian's Shadow Spinel
(57922, 71932, 34, 0, 2973, 1), -- Design: Mysterious Shadow Spinel
(57922, 71933, 35, 0, 2973, 1), -- Design: Purified Shadow Spinel
(57922, 71930, 36, 0, 2973, 1), -- Design: Retaliating Shadow Spinel
(57922, 71934, 37, 0, 2973, 1), -- Design: Shifting Shadow Spinel
(57922, 71938, 38, 0, 2973, 1), -- Design: Sovereign Shadow Spinel
(57922, 71936, 39, 0, 2973, 1), -- Design: Timeless Shadow Spinel
(57922, 71929, 40, 0, 2973, 1), -- Design: Veiled Shadow Spinel
(57922, 71947, 41, 0, 2973, 1), -- Design: Fractured Lightstone
(57922, 71948, 42, 0, 2973, 1), -- Design: Mystic Lightstone
(57922, 71946, 43, 0, 2973, 1), -- Design: Quick Lightstone
(57922, 71944, 44, 0, 2973, 1), -- Design: Smooth Lightstone
(57922, 71945, 45, 0, 2973, 1), -- Design: Subtle Lightstone
(57922, 71821, 46, 0, 2973, 1), -- Design: Rigid Deepholm Iolite
(57922, 71886, 47, 0, 2973, 1), -- Design: Solid Deepholm Iolite
(57922, 71885, 48, 0, 2973, 1), -- Design: Sparkling Deepholm Iolite
(57922, 71884, 49, 0, 2973, 1), -- Design: Stormy Deepholm Iolite
(57922, 71893, 50, 0, 2973, 1), -- Design: Balanced Elven Peridot
(57922, 71898, 51, 0, 2973, 1), -- Design: Energized Elven Peridot
(57922, 71901, 52, 0, 2973, 1), -- Design: Forceful Elven Peridot
(57922, 71891, 53, 0, 2973, 1), -- Design: Infused Elven Peridot
(57922, 71899, 54, 0, 2973, 1), -- Design: Jagged Elven Peridot
(57922, 71889, 55, 0, 2973, 1), -- Design: Lightning Elven Peridot
(57922, 71887, 56, 0, 2973, 1), -- Design: Misty Elven Peridot
(57922, 71902, 57, 0, 2973, 1), -- Design: Nimble Elven Peridot
(57922, 71888, 58, 0, 2973, 1), -- Design: Piercing Elven Peridot
(57922, 71903, 59, 0, 2973, 1), -- Design: Puissant Elven Peridot
(57922, 71896, 60, 0, 2973, 1), -- Design: Radiant Elven Peridot
(57922, 71900, 61, 0, 2973, 1), -- Design: Regal Elven Peridot
(57922, 71890, 62, 0, 2973, 1), -- Design: Sensei's Elven Peridot
(57922, 71897, 63, 0, 2973, 1), -- Design: Shattered Elven Peridot
(57922, 71904, 64, 0, 2973, 1), -- Design: Steady Elven Peridot
(57922, 71895, 65, 0, 2973, 1), -- Design: Turbid Elven Peridot
(57922, 71894, 66, 0, 2973, 1), -- Design: Vivid Elven Peridot
(57922, 71892, 67, 0, 2973, 1), -- Design: Zen Elven Peridot
-- 46572 (Goram)
(46572, 69209, 1, 0, 0, 1), -- Illustrious Guild Tabard
(46572, 69210, 2, 0, 0, 1), -- Renowned Guild Tabard
(46572, 63353, 3, 0, 0, 1), -- Shroud of Cooperation
(46572, 63207, 5, 0, 0, 1), -- Wrap of Unity
(46572, 65274, 7, 0, 0, 1), -- Cloak of Coordination
(46572, 65362, 9, 0, 0, 1), -- Guild Page
(46572, 65364, 10, 0, 0, 1), -- Guild Herald
(46572, 63138, 13, 0, 0, 1), -- Dark Phoenix Hatchling
(46572, 63398, 14, 0, 0, 1), -- Armadillo Pup
(46572, 64400, 18, 0, 0, 1), -- Banner of Cooperation
(46572, 64401, 19, 0, 0, 1), -- Standard of Unity
(46572, 64402, 20, 0, 0, 1), -- Battle Standard of Coordination
(46572, 62800, 21, 0, 0, 1), -- Recipe: Seafood Magnifique Feast
(46572, 62799, 22, 0, 0, 1), -- Recipe: Broiled Dragon Feast
(46572, 65435, 23, 0, 0, 1), -- Recipe: Cauldron of Battle
(46572, 65498, 24, 0, 0, 1), -- Recipe: Big Cauldron of Battle
(46572, 69892, 28, 0, 0, 1), -- Ripped Sandstorm Cloak
(46572, 62038, 29, 0, 0, 1), -- Worn Stoneskin Gargoyle Cape
(46572, 62039, 30, 0, 0, 1), -- Inherited Cape of the Black Baron
(46572, 62040, 31, 0, 0, 1), -- Ancient Bloodmoon Cloak
(46572, 69887, 32, 0, 0, 1), -- Burnished Helm of Might
(46572, 61958, 33, 0, 0, 1), -- Tattered Dreadmist Mask
(46572, 61942, 34, 0, 0, 1), -- Preened Tribal War Feathers
(46572, 61937, 35, 0, 0, 1), -- Stained Shadowcraft Cap
(46572, 61936, 36, 0, 0, 1), -- Mystical Coif of Elements
(46572, 61935, 37, 0, 0, 1), -- Tarnished Raging Berserker's Helm
(46572, 61931, 38, 0, 0, 1), -- Polished Helm of Valor
(46572, 67107, 39, 0, 0, 1), -- Reins of the Kor'kron Annihilator
(46572, 63125, 41, 0, 0, 1), -- Reins of the Dark Phoenix
(46572, 71033, 42, 0, 0, 1), -- Lil' Tarecgosa
-- 27816 (Brew Vendor)
(27816, 37905, 2, 0, 0, 1), -- Draenic Pale Ale
-- 48510 (Kall Worthaton)
(48510, 62461, 1, 0, 0, 1), -- Goblin Trike Key
(48510, 62462, 2, 0, 0, 1), -- Goblin Turbo-Trike Key
-- 3405 (Zeal'aya)
(3405, 17034, 1, 0, 0, 1), -- Maple Seed
(3405, 17031, 2, 0, 0, 1), -- Rune of Teleportation
(3405, 17032, 3, 0, 0, 1), -- Rune of Portals
(3405, 17020, 4, 0, 0, 1), -- Arcane Powder
(3405, 17030, 5, 0, 0, 1), -- Ankh
-- 3361 (Shoma)
(3361, 851, 1, 0, 0, 1), -- Cutlass
(3361, 2027, 2, 0, 0, 1), -- Scimitar
(3361, 923, 3, 0, 0, 1), -- Longsword
(3361, 1198, 4, 0, 0, 1), -- Claymore
(3361, 2024, 5, 0, 0, 1), -- Espadon
(3361, 922, 6, 0, 0, 1), -- Dacian Falx
(3361, 2207, 7, 0, 0, 1), -- Jambiya
(3361, 2208, 8, 0, 0, 1), -- Poniard
(3361, 2209, 9, 0, 0, 1), -- Kris
(3361, 2520, 10, 0, 0, 1), -- Broadsword
(3361, 2528, 11, 0, 0, 1), -- Falchion
(3361, 2526, 12, 0, 0, 1), -- Main Gauche
(3361, 2534, 13, 0, 0, 1), -- Rondel
(3361, 15905, 14, 0, 0, 1), -- Right-Handed Brass Knuckles
(3361, 15906, 15, 0, 0, 1), -- Left-Handed Brass Knuckles
(3361, 15903, 16, 0, 0, 1), -- Right-Handed Claw
(3361, 15907, 17, 0, 0, 1), -- Left-Handed Claw
(3361, 15904, 18, 0, 0, 1), -- Right-Handed Blades
(3361, 15909, 19, 0, 0, 1), -- Left-Handed Blades
-- 3360 (Koru)
(3360, 852, 1, 0, 0, 1), -- Mace
(3360, 1197, 2, 0, 0, 1), -- Giant Mace
(3360, 2028, 3, 0, 0, 1), -- Hammer
(3360, 925, 4, 0, 0, 1), -- Flail
(3360, 2026, 5, 0, 0, 1), -- Rock Hammer
(3360, 924, 6, 0, 0, 1), -- Maul
(3360, 854, 7, 0, 0, 1), -- Quarter Staff
(3360, 2030, 8, 0, 0, 1), -- Gnarled Staff
(3360, 928, 9, 0, 0, 1), -- Long Staff
-- 4043 (Galthuk)
(4043, 2521, 1, 0, 0, 1), -- Flamberge
(4043, 2529, 2, 0, 0, 1), -- Zweihander
(4043, 2523, 3, 0, 0, 1), -- Bullova
(4043, 2531, 4, 0, 0, 1), -- Great Axe
(4043, 2525, 5, 0, 0, 1), -- War Hammer
(4043, 2533, 6, 0, 0, 1), -- War Maul
-- 3409 (Zendo'jian)
(3409, 853, 1, 0, 0, 1), -- Hatchet
(3409, 2029, 2, 0, 0, 1), -- Cleaver
(3409, 927, 3, 0, 0, 1), -- Double Axe
(3409, 1196, 4, 0, 0, 1), -- Tabar
(3409, 2025, 5, 0, 0, 1), -- Bearded Axe
(3409, 926, 6, 0, 0, 1), -- Battle Axe
(3409, 2507, 7, 0, 0, 1), -- Laminated Recurve Bow
(3409, 3026, 8, 0, 0, 1), -- Reinforced Bow
(3409, 25872, 9, 0, 0, 1), -- Balanced Throwing Dagger
(3409, 25861, 10, 0, 0, 1), -- Crude Throwing Axe
(3409, 25873, 11, 0, 0, 1), -- Keen Throwing Knife
(3409, 25875, 12, 0, 0, 1), -- Deadly Throwing Axe
(3409, 25876, 13, 0, 0, 1), -- Gleaming Throwing Axe
(3409, 2495, 14, 0, 0, 1), -- Walking Stick
(3409, 854, 15, 0, 0, 1), -- Quarter Staff
(3409, 2030, 16, 0, 0, 1), -- Gnarled Staff
(3409, 928, 17, 0, 0, 1), -- Long Staff
-- 5812 (Tumi)
(5812, 2392, 1, 0, 0, 1), -- Light Mail Armor
(5812, 2393, 2, 0, 0, 1), -- Light Mail Belt
(5812, 2394, 3, 0, 0, 1), -- Light Mail Leggings
(5812, 2395, 4, 0, 0, 1), -- Light Mail Boots
(5812, 2396, 5, 0, 0, 1), -- Light Mail Bracers
(5812, 2397, 6, 0, 0, 1), -- Light Mail Gloves
(5812, 847, 7, 0, 0, 1), -- Chainmail Armor
(5812, 1845, 8, 0, 0, 1), -- Chainmail Belt
(5812, 848, 9, 0, 0, 1), -- Chainmail Pants
(5812, 849, 10, 0, 0, 1), -- Chainmail Boots
(5812, 1846, 11, 0, 0, 1), -- Chainmail Bracers
(5812, 850, 12, 0, 0, 1), -- Chainmail Gloves
(5812, 2417, 13, 0, 0, 1), -- Augmented Chain Vest
(5812, 2419, 14, 0, 0, 1), -- Augmented Chain Belt
(5812, 2418, 15, 0, 0, 1), -- Augmented Chain Leggings
(5812, 2420, 16, 0, 0, 1), -- Augmented Chain Boots
(5812, 2421, 17, 0, 0, 1), -- Augmented Chain Bracers
(5812, 2422, 18, 0, 0, 1), -- Augmented Chain Gloves
(5812, 3891, 19, 0, 0, 1), -- Augmented Chain Helm
(5812, 17189, 20, 0, 0, 1), -- Metal Buckler
(5812, 2448, 21, 0, 0, 1), -- Heavy Pavise
(5812, 2153, 22, 0, 0, 1), -- Polished Scale Vest
(5812, 2148, 23, 0, 0, 1), -- Polished Scale Belt
(5812, 2152, 24, 0, 0, 1), -- Polished Scale Leggings
(5812, 2149, 25, 0, 0, 1), -- Polished Scale Boots
(5812, 2150, 26, 0, 0, 1), -- Polished Scale Bracers
(5812, 2151, 27, 0, 0, 1), -- Polished Scale Gloves
(5812, 17192, 28, 0, 0, 1), -- Reinforced Targe
(5812, 2446, 29, 0, 0, 1), -- Kite Shield
(5812, 285, 30, 0, 0, 1), -- Scalemail Vest
(5812, 1853, 31, 0, 0, 1), -- Scalemail Belt
(5812, 286, 32, 0, 0, 1), -- Scalemail Pants
(5812, 287, 33, 0, 0, 1), -- Scalemail Boots
(5812, 1852, 34, 0, 0, 1), -- Scalemail Bracers
(5812, 718, 35, 0, 0, 1), -- Scalemail Gloves
(5812, 62265, 36, 0, 0, 1), -- Grunt's Chain Vest
(5812, 62260, 37, 0, 0, 1), -- Grunt's Chain Belt
(5812, 62264, 38, 0, 0, 1), -- Grunt's Chain Leggings
(5812, 62261, 39, 0, 0, 1), -- Grunt's Chain Boots
(5812, 62262, 40, 0, 0, 1), -- Grunt's Chain Bracers
(5812, 62263, 41, 0, 0, 1), -- Grunt's Chain Gloves
(5812, 62266, 42, 0, 0, 1), -- Grunt's Chain Circlet
(5812, 62253, 43, 0, 0, 1), -- Grunt's Plate Armor
(5812, 62254, 44, 0, 0, 1), -- Grunt's Plate Belt
(5812, 62258, 45, 0, 0, 1), -- Grunt's Plate Leggings
(5812, 62255, 46, 0, 0, 1), -- Grunt's Plate Boots
(5812, 62256, 47, 0, 0, 1), -- Grunt's Plate Bracers
(5812, 62257, 48, 0, 0, 1), -- Grunt's Plate Gloves
(5812, 62259, 49, 0, 0, 1), -- Grunt's Plate Helm
(5812, 17190, 50, 0, 0, 1), -- Ornate Buckler
(5812, 2451, 51, 0, 0, 1), -- Crested Heater Shield
-- 3356 (Sumi)
(3356, 2901, 1, 0, 0, 1), -- Mining Pick
(3356, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(3356, 2880, 3, 0, 0, 1), -- Weak Flux
(3356, 3466, 4, 0, 0, 1), -- Strong Flux
(3356, 18567, 5, 0, 0, 1), -- Elemental Flux
(3356, 3857, 6, 0, 0, 1), -- Coal
(3356, 12162, 43, 1, 0, 1), -- Plans: Hardened Iron Shortsword
(3356, 66117, 7, 0, 3312, 1), -- Plans: Vicious Pyrium Bracers
(3356, 66118, 8, 0, 3312, 1), -- Plans: Vicious Pyrium Gauntlets
(3356, 66125, 9, 0, 3312, 1), -- Plans: Vicious Ornate Pyrium Bracers
(3356, 66126, 10, 0, 3312, 1), -- Plans: Vicious Ornate Pyrium Gauntlets
(3356, 66103, 11, 0, 3312, 1), -- Plans: Pyrium Weapon Chain
(3356, 66119, 12, 0, 3312, 1), -- Plans: Vicious Pyrium Belt
(3356, 66107, 13, 0, 3312, 1), -- Plans: Elementium Girdle of Pain
(3356, 66105, 14, 0, 3312, 1), -- Plans: Hardened Elementium Girdle
(3356, 66109, 15, 0, 3312, 1), -- Plans: Light Elementium Belt
(3356, 66127, 16, 0, 3312, 1), -- Plans: Vicious Ornate Pyrium Belt
(3356, 66120, 17, 0, 3313, 1), -- Plans: Vicious Pyrium Boots
(3356, 67603, 18, 0, 3313, 1), -- Plans: Elementium Gutslicer
(3356, 67606, 19, 0, 3314, 1), -- Plans: Forged Elementium Mindcrusher
(3356, 66113, 20, 0, 3313, 1), -- Plans: Elementium Bonesplitter
(3356, 66106, 21, 0, 3313, 1), -- Plans: Elementium Deathplate
(3356, 66111, 22, 0, 3313, 1), -- Plans: Elementium Hammer
(3356, 66104, 23, 0, 3313, 1), -- Plans: Hardened Elementium Hauberk
(3356, 66108, 24, 0, 3313, 1), -- Plans: Light Elementium Chestguard
(3356, 66128, 25, 0, 3313, 1), -- Plans: Vicious Ornate Pyrium Boots
(3356, 66121, 26, 0, 3313, 1), -- Plans: Vicious Pyrium Shoulders
(3356, 66115, 27, 0, 3313, 1), -- Plans: Elementium Earthguard
(3356, 66112, 28, 0, 3313, 1), -- Plans: Elementium Poleaxe
(3356, 66114, 29, 0, 3313, 1), -- Plans: Elementium Shank
(3356, 66110, 30, 0, 3313, 1), -- Plans: Elementium Spellblade
(3356, 66116, 31, 0, 3313, 1), -- Plans: Elementium Stormshield
(3356, 66129, 32, 0, 3313, 1), -- Plans: Vicious Ornate Pyrium Shoulders
(3356, 66124, 33, 0, 3314, 1), -- Plans: Vicious Pyrium Breastplate
(3356, 66123, 34, 0, 3314, 1), -- Plans: Vicious Pyrium Helm
(3356, 66122, 35, 0, 3314, 1), -- Plans: Vicious Pyrium Legguards
(3356, 66100, 36, 0, 3314, 1), -- Plans: Ebonsteel Belt Buckle
(3356, 66132, 37, 0, 3314, 1), -- Plans: Vicious Ornate Pyrium Breastplate
(3356, 66131, 38, 0, 3314, 1), -- Plans: Vicious Ornate Pyrium Helm
(3356, 66130, 39, 0, 3314, 1), -- Plans: Vicious Ornate Pyrium Legguards
(3356, 66101, 40, 0, 3314, 1), -- Plans: Pyrium Shield Spike
-- 3362 (Ogunaro Wolfrunner)
(3362, 1132, 1, 0, 0, 1), -- Horn of the Timber Wolf
(3362, 5665, 2, 0, 0, 1), -- Horn of the Dire Wolf
(3362, 5668, 3, 0, 0, 1), -- Horn of the Brown Wolf
(3362, 46099, 4, 0, 0, 1), -- Horn of the Black Wolf
(3362, 18796, 5, 0, 0, 1), -- Horn of the Swift Brown Wolf
(3362, 18798, 6, 0, 0, 1), -- Horn of the Swift Gray Wolf
(3362, 18797, 7, 0, 0, 1); -- Horn of the Swift Timber Wolf
