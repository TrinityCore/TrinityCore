DELETE FROM `spell_loot_template` WHERE `entry` IN (60445,73500,78866,80615,85325,85435,95399,95406,99438,99500,109946,109947,109948,109954);
INSERT INTO `spell_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- Dalaran Fountain (retreived from TDB47)
(60445,11025,100,1,0,-11025,1), -- Dalaran fountain Fishing Reference
-- Abyssal Clam
(73500,62791,100,1,0,1,1), -- Blood Shrimp
(73500,52338,1.4,1,0,1,1), -- Darkfathom Pearl
(73500,52339,1  ,1,0,1,1), -- Flawless Pearl
-- Transmute; Living Elements
(78866,52325,25,1,1,14,16), -- Volatile Fire
(78866,52326,25,1,1,14,16), -- Volatile Water
(78866,52327,25,1,1,14,16), -- Volatile Earth
(78866,52328,25,1,1,14,16), -- Volatile Air
-- Royal Monkfish
(80615,58864,100,1,0,1,1), -- Precious Locket
-- Landro's Gift Box
(85325,45047,0,1,1,50,50), -- Sandbox Tiger
(85325,35223,0,1,1,50,50), -- Papa Hummel's Old-Fashioned Pet Biscuit
(85325,46779,0,1,1,50,50), -- Path of Cenarius
-- Mounts
(85325,23720,1,1,2,1,1), -- Riding Turtle
(85325,49284,1,1,2,1,1), -- Reins of the Swift Spectral Tiger
(85325,49283,1,1,2,1,1), -- Reins of the Spectral Tiger
(85325,49286,1,1,2,1,1), -- X-51 Nether-Rocket X-TREME
(85325,49285,1,1,2,1,1), -- X-51 Nether-Rocket
(85325,49282,1,1,2,1,1), -- Big Battle Bear
-- Landro's Loot Box
(85435,45047,0,1,1,50,50), -- Sandbox Tiger
(85435,35223,0,1,1,50,50), -- Papa Hummel's Old-Fashioned Pet Biscuit
(85435,46779,0,1,1,50,50), -- Path of Cenarius
-- Rare chance on:
(85435,32588,1,1,2,1,1), -- Banana Charm
(85435,34493,1,1,2,1,1), -- Dragon Kite
(85435,38050,1,1,2,1,1), -- Soul-Trader Beacon
-- DND ones, dont care
(95399,52983,100,1,0,1,1), -- Cinderbloom
(95406,52988,100,1,0,1,1), -- Whiptail
-- Fillet Blind Cavefish
(99438,69935,90,1,0,1,1), -- Poshken's Ring
(99438,69955,75,1,1,1,1), -- Slimey Locket
(99438,58866,25,1,1,1,1), -- Set of Rusty Keys
-- Mulgore Pine Nuts
(99500,69988,100,1,0,5,5), -- Pine Nuts
-- Crystalline Geode <Random Cata Gem>
(109946,52177,0,1,1,1,2), -- Carnelian
(109946,52178,0,1,1,1,2), -- Zephyrite
(109946,52179,0,1,1,1,2), -- Alicite
(109946,52180,0,1,1,1,2), -- Nightstone
(109946,52181,0,1,1,1,2), -- Hessonite
(109946,52182,0,1,1,1,2), -- Jasper
(109946,52190,5,1,2,1,1), -- Inferno Ruby
(109946,52191,5,1,2,1,1), -- Ocean Sapphire
(109946,52192,5,1,2,1,1), -- Dream Emerald
(109946,52193,5,1,2,1,1), -- Ember Topaz
(109946,52194,5,1,2,1,1), -- Demonseye
(109946,52195,5,1,2,1,1), -- Amberjewel
(109946,71805,1,1,3,1,1), -- Queen's Garnet
(109946,71809,1,1,3,1,1), -- Shadow Spinel
(109946,71808,1,1,3,1,1), -- Lava Coral
(109946,71806,1,1,3,1,1), -- Lightstone
(109946,71810,1,1,3,1,1), -- Elven Peridot
(109946,71807,1,1,3,1,1), -- Deepholm Iolite
-- Elementium Coated Geode <Prime Epic Gem>
(109947,71805,0,1,1,1,1), -- Queen's Garnet
(109947,71809,0,1,1,1,1), -- Shadow Spinel
(109947,71808,0,1,1,1,1), -- Lava Coral
-- Perfect Geode <Random Epic Gem>
(109948,71805,1,1,3,1,1), -- Queen's Garnet
(109948,71809,1,1,3,1,1), -- Shadow Spinel
(109948,71808,1,1,3,1,1), -- Lava Coral
(109948,71806,1,1,3,1,1), -- Lightstone
(109948,71810,1,1,3,1,1), -- Elven Peridot
(109948,71807,1,1,3,1,1), -- Deepholm Iolite
-- Elementium Gem Cluster
(109954,77951,100,1,0,3,9); -- Shadowy Gem
