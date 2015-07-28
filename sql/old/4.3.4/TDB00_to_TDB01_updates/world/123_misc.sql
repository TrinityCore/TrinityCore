UPDATE `gameobject_template` SET `castBarCaption`='Gathering', `data3`=0, `data6`=26321, `data14`=24982, `WDBVerified`=15595 WHERE `entry`=176206; -- Davil's Libram
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=177045; -- Haunted Trap
UPDATE `gameobject_template` SET `castBarCaption`='Grabbing', `data3`=0, `data14`=37379, `WDBVerified`=15595 WHERE `entry`=176207; -- Redpath's Shield
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176270; -- Campfire

UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=41, `faction_A`=2070, `faction_H`=2070, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768 WHERE `entry`=44458; -- Del Gahrron
UPDATE `creature_template` SET `minlevel`=37 WHERE `entry`=1824; -- Plague Lurker
UPDATE `creature_template` SET `maxlevel`=37 WHERE `entry`=4472; -- Haunting Vision
UPDATE `creature_template` SET `minlevel`=38 WHERE `entry`=1804; -- Wailing Death
UPDATE `creature_template` SET `minlevel`=38 WHERE `entry`=44443; -- Cult-Sworn Warlock
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=37888; -- Frax Bucketdrop
UPDATE `creature_template` SET `gossip_menu_id`=12032 WHERE `entry`=44232; -- Janice Myers
UPDATE `creature_template` SET `minlevel`=42 WHERE `entry`=45664; -- Landlocked Grouper
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=44230; -- Richard Trueflight
UPDATE `creature_template` SET `maxlevel`=43 WHERE `entry`=8535; -- Putrid Shrieker
UPDATE `creature_template` SET `gossip_menu_id`=12022 WHERE `entry`=45417; -- Fiona
UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `VehicleId`=1103 WHERE `entry`=45416; -- Fiona's Caravan Harness
UPDATE `creature_template` SET `gossip_menu_id`=12035, `npcflag`=3, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768 WHERE `entry`=45400; -- Fiona's Caravan
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=2.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45433; -- Preston
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=2.8, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768 WHERE `entry`=45434; -- Argyle
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=16134; -- Rimblat Earthshatter
UPDATE `creature_template` SET `maxlevel`=43 WHERE `entry`=8565; -- Pathstrider
UPDATE `creature_template` SET `maxlevel`=43 WHERE `entry`=8563; -- Woodsman
UPDATE `creature_template` SET `speed_run`=0.888888 WHERE `entry`=17878; -- Scourge Siege Engineer
UPDATE `creature_template` SET `maxlevel`=43 WHERE `entry`=8564; -- Ranger
UPDATE `creature_template` SET `minlevel`=45 WHERE `entry`=8547; -- Death Cultist
UPDATE `creature_template` SET `maxlevel`=44 WHERE `entry`=8553; -- Necromancer
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=44233; -- William Kielar Jr.
UPDATE `creature_template` SET `gossip_menu_id`=12086 WHERE `entry`=45828; -- Argent Apothecary Judkins

UPDATE `creature_model_info` SET `bounding_radius`=1 WHERE `modelid`=33314;
UPDATE `creature_model_info` SET `bounding_radius`=1 WHERE `modelid`=33315;

DELETE FROM `npc_vendor` WHERE `entry` IN (45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 45500, 47139, 47139, 47139, 47139, 47139, 47139, 47139, 47139, 47139, 45451, 45451, 45451, 45451, 45451, 45451, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47149, 47148, 47148, 47148, 47148, 47148, 47148, 47148, 47148, 47148, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47142, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47144, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 47165, 45417, 45417, 45417, 45417, 45417, 45417, 45417, 45417, 45417, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47166, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47164, 47167, 47167, 47167, 47167, 47167, 47167, 47167, 47167, 47167, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47104, 47106, 47106, 47106, 47106, 47106, 47106, 47106, 47106, 47105, 47105, 47105, 47105, 47105, 47105, 47105, 47105, 47105);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 45500 (Urk Gagbaz)
(45500, 2423, 1, 0, 0, 1), -- Brigandine Vest
(45500, 2424, 2, 0, 0, 1), -- Brigandine Belt
(45500, 2425, 3, 0, 0, 1), -- Brigandine Leggings
(45500, 2426, 4, 0, 0, 1), -- Brigandine Boots
(45500, 2427, 5, 0, 0, 1), -- Brigandine Bracers
(45500, 2428, 6, 0, 0, 1), -- Brigandine Gloves
(45500, 3894, 7, 0, 0, 1), -- Brigandine Helm
(45500, 8094, 8, 0, 0, 1), -- Platemail Armor
(45500, 8088, 9, 0, 0, 1), -- Platemail Belt
(45500, 8093, 10, 0, 0, 1), -- Platemail Leggings
(45500, 8089, 11, 0, 0, 1), -- Platemail Boots
(45500, 8090, 12, 0, 0, 1), -- Platemail Bracers
(45500, 8091, 13, 0, 0, 1), -- Platemail Gloves
(45500, 8092, 14, 0, 0, 1), -- Platemail Helm
(45500, 17190, 15, 0, 0, 1), -- Ornate Buckler
(45500, 2451, 16, 0, 0, 1), -- Crested Heater Shield
-- 47139 (Gerald Fairbanks)
(47139, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(47139, 1205, 2, 0, 0, 1), -- Melon Juice
(47139, 1708, 3, 0, 0, 1), -- Sweet Nectar
(47139, 1645, 4, 0, 0, 1), -- Moonberry Juice
(47139, 4542, 5, 0, 0, 1), -- Moist Cornbread
(47139, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(47139, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(47139, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(47139, 4470, 9, 0, 0, 1), -- Simple Wood
-- 45451 (Argus Highbeacon)
(45451, 2901, 1, 0, 0, 1), -- Mining Pick
(45451, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(45451, 2880, 3, 0, 0, 1), -- Weak Flux
(45451, 3466, 4, 0, 0, 1), -- Strong Flux
(45451, 18567, 5, 0, 0, 1), -- Elemental Flux
(45451, 3857, 6, 0, 0, 1), -- Coal
-- 47149 (Kathryn Humphries)
(47149, 853, 1, 0, 0, 1), -- Hatchet
(47149, 2029, 2, 0, 0, 1), -- Cleaver
(47149, 927, 3, 0, 0, 1), -- Double Axe
(47149, 1196, 4, 0, 0, 1), -- Tabar
(47149, 2025, 5, 0, 0, 1), -- Bearded Axe
(47149, 926, 6, 0, 0, 1), -- Battle Axe
(47149, 15810, 7, 0, 0, 1), -- Short Spear
(47149, 15811, 8, 0, 0, 1), -- Heavy Spear
(47149, 2524, 9, 0, 0, 1), -- Truncheon
(47149, 2532, 10, 0, 0, 1), -- Morning Star
(47149, 2525, 11, 0, 0, 1), -- War Hammer
(47149, 2533, 12, 0, 0, 1), -- War Maul
(47149, 2527, 13, 0, 0, 1), -- Battle Staff
(47149, 2535, 14, 0, 0, 1), -- War Staff
-- 47148 (Donovan Minewell)
(47148, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(47148, 1205, 2, 0, 0, 1), -- Melon Juice
(47148, 1708, 3, 0, 0, 1), -- Sweet Nectar
(47148, 1645, 4, 0, 0, 1), -- Moonberry Juice
(47148, 4542, 5, 0, 0, 1), -- Moist Cornbread
(47148, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(47148, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(47148, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(47148, 4470, 9, 0, 0, 1), -- Simple Wood
-- 47142 (Rahmalaha)
(47142, 4540, 1, 0, 0, 1), -- Tough Hunk of Bread
(47142, 4541, 2, 0, 0, 1), -- Freshly Baked Bread
(47142, 4542, 3, 0, 0, 1), -- Moist Cornbread
(47142, 4544, 4, 0, 0, 1), -- Mulgore Spice Bread
(47142, 4601, 5, 0, 0, 1), -- Soft Banana Bread
(47142, 8950, 6, 0, 0, 1), -- Homemade Cherry Pie
(47142, 4604, 7, 0, 0, 1), -- Forest Mushroom Cap
(47142, 4605, 8, 0, 0, 1), -- Red-Speckled Mushroom
(47142, 4606, 9, 0, 0, 1), -- Spongy Morel
(47142, 4607, 10, 0, 0, 1), -- Delicious Cave Mold
(47142, 4608, 11, 0, 0, 1), -- Raw Black Truffle
(47142, 8948, 12, 0, 0, 1), -- Dried King Bolete
(47142, 159, 13, 0, 0, 1), -- Refreshing Spring Water
(47142, 1179, 14, 0, 0, 1), -- Ice Cold Milk
(47142, 1205, 15, 0, 0, 1), -- Melon Juice
(47142, 1708, 16, 0, 0, 1), -- Sweet Nectar
(47142, 1645, 17, 0, 0, 1), -- Moonberry Juice
(47142, 8766, 18, 0, 0, 1), -- Morning Glory Dew
-- 47144 (Patricia Marshall)
(47144, 2520, 1, 0, 0, 1), -- Broadsword
(47144, 2528, 2, 0, 0, 1), -- Falchion
(47144, 2526, 3, 0, 0, 1), -- Main Gauche
(47144, 2534, 4, 0, 0, 1), -- Rondel
(47144, 15810, 5, 0, 0, 1), -- Short Spear
(47144, 15811, 6, 0, 0, 1), -- Heavy Spear
(47144, 17188, 7, 0, 0, 1), -- Ringed Buckler
(47144, 17192, 8, 0, 0, 1), -- Reinforced Targe
(47144, 17189, 9, 0, 0, 1), -- Metal Buckler
(47144, 17190, 10, 0, 0, 1), -- Ornate Buckler
(47144, 2445, 11, 0, 0, 1), -- Large Metal Shield
(47144, 2446, 12, 0, 0, 1), -- Kite Shield
(47144, 2448, 13, 0, 0, 1), -- Heavy Pavise
(47144, 2451, 14, 0, 0, 1), -- Crested Heater Shield
-- 47165 (Casey Tipple)
(47165, 117, 1, 0, 0, 1), -- Tough Jerky
(47165, 2287, 2, 0, 0, 1), -- Haunch of Meat
(47165, 3770, 3, 0, 0, 1), -- Mutton Chop
(47165, 3771, 4, 0, 0, 1), -- Wild Hog Shank
(47165, 4599, 5, 0, 0, 1), -- Cured Ham Steak
(47165, 8952, 6, 0, 0, 1), -- Roasted Quail
(47165, 4536, 7, 0, 0, 1), -- Shiny Red Apple
(47165, 4537, 8, 0, 0, 1), -- Tel'Abim Banana
(47165, 4538, 9, 0, 0, 1), -- Snapvine Watermelon
(47165, 4539, 10, 0, 0, 1), -- Goldenbark Apple
(47165, 4602, 11, 0, 0, 1), -- Moon Harvest Pumpkin
(47165, 8953, 12, 0, 0, 1), -- Deep Fried Plantains
(47165, 159, 13, 0, 0, 1), -- Refreshing Spring Water
(47165, 1179, 14, 0, 0, 1), -- Ice Cold Milk
(47165, 1205, 15, 0, 0, 1), -- Melon Juice
(47165, 1708, 16, 0, 0, 1), -- Sweet Nectar
(47165, 1645, 17, 0, 0, 1), -- Moonberry Juice
(47165, 8766, 18, 0, 0, 1), -- Morning Glory Dew
-- 45417 (Fiona)
(45417, 1844, 1, 0, 0, 1), -- Tanned Leather Bracers
(45417, 7339, 2, 0, 0, 1), -- Miniscule Diamond Ring
(45417, 2321, 3, 0, 0, 1), -- Fine Thread
(45417, 3466, 4, 0, 0, 1), -- Strong Flux
(45417, 4539, 5, 0, 0, 1), -- Goldenbark Apple
(45417, 8950, 6, 0, 0, 1), -- Homemade Cherry Pie
(45417, 1179, 7, 0, 0, 1), -- Ice Cold Milk
(45417, 1708, 8, 0, 0, 1), -- Sweet Nectar
(45417, 1645, 9, 0, 0, 1), -- Moonberry Juice
-- 47166 (Dorris Manchester)
(47166, 3023, 1, 0, 0, 1), -- Large Bore Blunderbuss
(47166, 3024, 2, 0, 0, 1), -- BKP 2700 "Enforcer"
(47166, 3025, 3, 0, 0, 1), -- BKP 42 "Ultra"
(47166, 853, 4, 0, 0, 1), -- Hatchet
(47166, 2029, 5, 0, 0, 1), -- Cleaver
(47166, 927, 6, 0, 0, 1), -- Double Axe
(47166, 1196, 7, 0, 0, 1), -- Tabar
(47166, 2025, 8, 0, 0, 1), -- Bearded Axe
(47166, 926, 9, 0, 0, 1), -- Battle Axe
(47166, 5740, 10, 0, 0, 1), -- Red Fireworks Rocket
-- 47164 (James Litman)
(47164, 7005, 1, 0, 0, 1), -- Skinning Knife
(47164, 6256, 2, 0, 0, 1), -- Fishing Pole
(47164, 2901, 3, 0, 0, 1), -- Mining Pick
(47164, 5956, 4, 0, 0, 1), -- Blacksmith Hammer
(47164, 6217, 5, 0, 0, 1), -- Copper Rod
(47164, 2320, 6, 0, 0, 1), -- Coarse Thread
(47164, 2321, 7, 0, 0, 1), -- Fine Thread
(47164, 4291, 8, 0, 0, 1), -- Silken Thread
(47164, 8343, 9, 0, 0, 1), -- Heavy Silken Thread
(47164, 14341, 10, 0, 0, 1), -- Rune Thread
(47164, 2678, 11, 0, 0, 1), -- Mild Spices
(47164, 2880, 12, 0, 0, 1), -- Weak Flux
(47164, 3466, 13, 0, 0, 1), -- Strong Flux
(47164, 3857, 14, 0, 0, 1), -- Coal
(47164, 2324, 15, 0, 0, 1), -- Bleach
(47164, 2604, 16, 0, 0, 1), -- Red Dye
(47164, 2325, 17, 0, 0, 1), -- Black Dye
(47164, 4341, 18, 0, 0, 1), -- Yellow Dye
(47164, 4342, 19, 0, 0, 1), -- Purple Dye
(47164, 4340, 20, 0, 0, 1), -- Gray Dye
(47164, 3371, 21, 0, 0, 1), -- Crystal Vial
(47164, 4289, 22, 0, 0, 1), -- Salt
(47164, 4399, 23, 0, 0, 1), -- Wooden Stock
(47164, 4400, 24, 0, 0, 1), -- Heavy Stock
(47164, 6530, 25, 0, 0, 1), -- Nightcrawlers
(47164, 6532, 26, 0, 0, 1), -- Bright Baubles
-- 47167 (Brett Nelson)
(47167, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(47167, 1205, 2, 0, 0, 1), -- Melon Juice
(47167, 1708, 3, 0, 0, 1), -- Sweet Nectar
(47167, 1645, 4, 0, 0, 1), -- Moonberry Juice
(47167, 4542, 5, 0, 0, 1), -- Moist Cornbread
(47167, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(47167, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(47167, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(47167, 4470, 9, 0, 0, 1), -- Simple Wood
-- 47104 (Anthony Waler)
(47104, 2901, 1, 0, 0, 1), -- Mining Pick
(47104, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(47104, 6217, 3, 0, 0, 1), -- Copper Rod
(47104, 2320, 4, 0, 0, 1), -- Coarse Thread
(47104, 2321, 5, 0, 0, 1), -- Fine Thread
(47104, 4291, 6, 0, 0, 1), -- Silken Thread
(47104, 2678, 7, 0, 0, 1), -- Mild Spices
(47104, 2880, 8, 0, 0, 1), -- Weak Flux
(47104, 3466, 9, 0, 0, 1), -- Strong Flux
(47104, 3857, 10, 0, 0, 1), -- Coal
(47104, 2324, 11, 0, 0, 1), -- Bleach
(47104, 3371, 12, 0, 0, 1), -- Crystal Vial
(47104, 4289, 13, 0, 0, 1), -- Salt
(47104, 4399, 14, 0, 0, 1), -- Wooden Stock
(47104, 4400, 15, 0, 0, 1), -- Heavy Stock
(47104, 6530, 16, 0, 0, 1), -- Nightcrawlers
(47104, 6532, 17, 0, 0, 1), -- Bright Baubles
(47104, 39354, 18, 0, 0, 1), -- Light Parchment
-- 47106 (Christine Gade)
(47106, 17188, 1, 0, 0, 1), -- Ringed Buckler
(47106, 17192, 2, 0, 0, 1), -- Reinforced Targe
(47106, 17189, 3, 0, 0, 1), -- Metal Buckler
(47106, 17190, 4, 0, 0, 1), -- Ornate Buckler
(47106, 2445, 5, 0, 0, 1), -- Large Metal Shield
(47106, 2446, 6, 0, 0, 1), -- Kite Shield
(47106, 2448, 7, 0, 0, 1), -- Heavy Pavise
(47106, 2451, 8, 0, 0, 1), -- Crested Heater Shield
-- 47105 (Marc Daiton)
(47105, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(47105, 1205, 2, 0, 0, 1), -- Melon Juice
(47105, 1708, 3, 0, 0, 1), -- Sweet Nectar
(47105, 1645, 4, 0, 0, 1), -- Moonberry Juice
(47105, 4542, 5, 0, 0, 1), -- Moist Cornbread
(47105, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(47105, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(47105, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(47105, 4470, 9, 0, 0, 1); -- Simple Wood

DELETE FROM `npc_text` WHERE `ID` IN (17855, 16694, 16963, 16958, 16947, 16966);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(17855, '', 'Welcome to the Menders'' Stead, $c.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17855
(16694, '''Ey, mon!  You come to help Zen''Kiki out?', '', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16694
(16963, 'It''s good to have traveling companions.  The road gets lonely out here.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16963
(16958, 'Hey boss.  You need someone to help drive the caravan, you just let ol'' Beezil know.', '', 0, 1, 3, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16958
(16947, '', 'Why would he run off like that?!', 0, 1, 5, 0, 0, 0, 0, 0, '', 'Promise me you''ll find him, $N.', 0, 1, 1, 0, 0, 0, 0, 0, '', '<Fiona is rather upset.  She doesn''t seem to be in the mood to talk.>', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 16947
(16966, 'I don''t get many visitors this deep in the Plaguewood.  Abominations, mostly.$b$bCan I help you with something?', '', 0, 1, 2, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 16966

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=12032 AND `id`=1) OR (`menu_id`=3651 AND `id`=1) OR (`menu_id`=3651 AND `id`=2) OR (`menu_id`=12022 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(12032, 1, 2, 'Show me where I can fly.', 0, 0, ''), -- Janice Myers
(3651, 1, 0, 'Betina, I''d like a replacement Seal of the Dawn please!', 0, 0, ''), -- Betina Bigglezink
(3651, 2, 0, 'Betina, I''d like a replacement Rune of the Dawn please!', 0, 0, ''), -- Betina Bigglezink
(12022, 0, 1, 'Let me see what you have for sale, Fiona.', 0, 0, ''); -- Fiona


DELETE FROM `creature_equip_template` WHERE `entry` IN (47758, 47757, 44458, 47756, 44443, 44443, 44443, 47060, 11063, 47139, 47060, 47060, 47060, 51986, 47060, 51986, 47060, 45451, 47060, 47060, 10667, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 11035, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47149, 47060, 47060, 47060, 47060, 47060, 47060, 47148, 47153, 47060, 47060, 47060, 47060, 47060, 47060, 45735, 47142, 47144, 47060, 47060, 47060, 8527, 8527, 8527, 8527, 8527, 8527, 8527, 8527, 45482, 45451, 46022, 47060, 47165, 47060, 47167, 47060, 47164, 47060, 47060, 47166, 47060, 47060, 47060, 47060, 8565, 8563, 47060, 47060, 8564, 8565, 8563, 8564, 8565, 8563, 8523, 8523, 8523, 8547, 8523, 45897, 45897, 45897, 45897, 8523, 8523, 8523, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 8523, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 45897, 8523, 45897, 45897, 45897, 45897, 45897, 8523, 8553, 8523, 8523, 8523, 47104, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47060, 47105, 47060, 47106, 45828, 8523);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(47758, 1903, 13611, 0), -- Gurt
(47757, 1906, 0, 0), -- George Randolph
(44458, 57762, 0, 0), -- Del Gahrron
(47756, 13861, 0, 0), -- Chad Fillmore
(44443, 41176, 0, 0), -- Cult-Sworn Warlock
(47060, 42544, 42543, 2551), -- Argent Sentry
(11063, 1899, 1985, 0), -- Carlin Redpath
(47139, 1906, 0, 0), -- Gerald Fairbanks
(51986, 42544, 42543, 0), -- Argent Sentry
(45451, 6224, 0, 0), -- Argus Highbeacon
(10667, 12591, 0, 0), -- Chromie
(11035, 5287, 0, 0), -- Betina Bigglezink
(47149, 45123, 42543, 0), -- Kathryn Humphries
(47148, 1906, 0, 0), -- Donovan Minewell
(47153, 1910, 0, 0), -- Cabe Minewell
(45735, 49311, 0, 0), -- Gamella Cracklefizz
(47142, 1906, 0, 0), -- Rahmalaha
(47144, 45123, 42543, 0), -- Patricia Marshall
(8527, 3361, 1985, 0), -- Scourge Guard
(45482, 0, 0, 49761), -- Argent Officer Irizarry
(46022, 31824, 0, 0), -- Beezil Linkspanner
(47165, 2197, 0, 0), -- Casey Tipple
(47167, 1906, 0, 0), -- Brett Nelson
(47164, 1910, 0, 0), -- James Litman
(47166, 45123, 42543, 0), -- Dorris Manchester
(8565, 12993, 12991, 0), -- Pathstrider
(8563, 5286, 0, 0), -- Woodsman
(8564, 11763, 0, 5259), -- Ranger
(8523, 1899, 0, 0), -- Scourge Soldier
(8547, 6224, 0, 0), -- Death Cultist
(45897, 49801, 0, 0), -- Plaguewood Reanimator
(8553, 2559, 0, 0), -- Necromancer
(47104, 1910, 0, 0), -- Anthony Waler
(47105, 1906, 0, 0), -- Marc Daiton
(47106, 45123, 42543, 0), -- Christine Gade
(45828, 52358, 0, 0); -- Argent Apothecary Judkins

DELETE FROM `gameobject` WHERE `guid`=2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
-- (@OGUID+0, 181688, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1), -- 0 (Area: -Unknown-) - !!! transport !!!
(2, 38927, 0, 1, 1, -6382.94, 1252.1, 8.22664, 4.572764, 0, 0, 0, 1, 120, 255, 1); -- Newman's Landing (Area: -Unknown-)
-- (@OGUID+1, 181689, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 120, 255, 1); -- 0 (Area: -Unknown-) - !!! transport !!!

UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `speed_walk`=1.428571, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=4624; -- Booty Bay Bruiser
UPDATE `creature_template` SET `minlevel`=49, `maxlevel`=49, `faction_A`=120, `faction_H`=120, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=26081; -- High Admiral "Shelly" Jorrik

DELETE FROM `creature_template_addon` WHERE `entry` IN (4624, 4624, 26081);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(4624, 0, 0x0, 0x1, ''), -- Booty Bay Bruiser
(26081, 0, 0x0, 0x1, ''); -- High Admiral "Shelly" Jorrik

UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=23509;

SET @CGUID := 6;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 4624, 0, 1, 1, -6373.525, 1267.883, 7.270858, 2.391101, 120, 0, 0), -- Booty Bay Bruiser (Area: -Unknown-)
(@CGUID+1, 4624, 0, 1, 1, -6378.611, 1263.205, 7.270857, 3.036873, 120, 0, 0), -- Booty Bay Bruiser (Area: -Unknown-)
(@CGUID+2, 26081, 0, 1, 1, -6378.076, 1268.465, 7.270858, 2.443461, 120, 0, 0); -- High Admiral "Shelly" Jorrik (Area: -Unknown-)

DELETE FROM `npc_vendor` WHERE `entry` IN (26081, 26081, 26081, 26081, 26081, 26081, 26081);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 26081 (High Admiral "Shelly" Jorrik)
(26081, 2901, 1, 0, 0, 1), -- Mining Pick
(26081, 5956, 2, 0, 0, 1), -- Blacksmith Hammer
(26081, 2880, 3, 0, 0, 1), -- Weak Flux
(26081, 3466, 4, 0, 0, 1), -- Strong Flux
(26081, 18567, 5, 0, 0, 1), -- Elemental Flux
(26081, 3857, 6, 0, 0, 1), -- Coal
(26081, 10858, 37, 1, 0, 1); -- Plans: Solid Iron Maul

DELETE FROM `creature_equip_template` WHERE `entry` IN (4624, 4624, 26081);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(4624, 3361, 0, 2552), -- Booty Bay Bruiser
(26081, 19022, 0, 0); -- High Admiral "Shelly" Jorrik

UPDATE `creature_template` SET `minlevel`=53, `speed_walk`=0.9920629, `dynamicflags`=0 WHERE `entry`=11516; -- Timbermaw Warder
UPDATE `creature_template` SET `minlevel`=48, `maxlevel`=48, `speed_walk`=0.9920629, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=7158; -- Deadwood Shaman
UPDATE `creature_template` SET `gossip_menu_id`=3626, `npcflag`=147, `speed_walk`=0.9920629, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11557; -- Meilosh
UPDATE `creature_template` SET `gossip_menu_id`=3625, `npcflag`=643, `speed_walk`=0.9920629, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11555; -- Gorn One Eye
UPDATE `creature_template` SET `speed_walk`=0.9920629, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11553; -- Timbermaw Woodbender
UPDATE `creature_template` SET `gossip_menu_id`=6801, `speed_walk`=0.9920629, `speed_run`=0.666668, `rangeattacktime`=2000, `dynamicflags`=0 WHERE `entry`=11558; -- Kernda
UPDATE `creature_template` SET `minlevel`=53, `maxlevel`=53, `speed_walk`=0.9920629, `dynamicflags`=0 WHERE `entry`=11552; -- Timbermaw Mystic
UPDATE `creature_template` SET `speed_walk`=0.9920629, `dynamicflags`=0 WHERE `entry`=11556; -- Salfa
UPDATE `creature_template` SET `minlevel`=50, `speed_walk`=0.9920629, `dynamicflags`=0 WHERE `entry`=7440; -- Winterfall Den Watcher

DELETE FROM `npc_vendor` WHERE `entry` IN (11555, 11555, 11555, 11555, 11555, 11555, 11555, 11555, 11555, 11555, 11555);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
-- 11557 (Meilosh)
-- 11555 (Gorn One Eye)
(11555, 159, 1, 0, 0, 1), -- Refreshing Spring Water
(11555, 1205, 2, 0, 0, 1), -- Melon Juice
(11555, 1708, 3, 0, 0, 1), -- Sweet Nectar
(11555, 1645, 4, 0, 0, 1), -- Moonberry Juice
(11555, 4542, 5, 0, 0, 1), -- Moist Cornbread
(11555, 4601, 6, 0, 0, 1), -- Soft Banana Bread
(11555, 4497, 7, 0, 0, 1), -- Heavy Brown Bag
(11555, 4499, 8, 0, 0, 1), -- Huge Brown Sack
(11555, 4470, 9, 0, 0, 1), -- Simple Wood
(11555, 16768, 10, 0, 0, 1), -- Furbolg Medicine Pouch
(11555, 16769, 11, 0, 0, 1); -- Furbolg Medicine Totem

UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=4401; -- 4401
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=4398; -- 4398
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=8124; -- 8124
UPDATE `npc_text` SET `WDBVerified`=15595 WHERE `ID`=4395; -- 4395

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=3626 AND `id`=0) OR (`menu_id`=3626 AND `id`=1) OR (`menu_id`=3625 AND `id`=0) OR (`menu_id`=3624 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(3626, 0, 3, 'I''d like to train.', 0, 0, ''), -- Meilosh
(3626, 1, 1, 'Let me browse your goods.', 0, 0, ''), -- Meilosh
(3625, 0, 1, 'I would like to buy from you.', 0, 0, ''), -- Gorn One Eye
(3624, 0, 0, 'What about the Winterfall furbolg?', 0, 0, ''); -- Salfa

DELETE FROM `creature_equip_template` WHERE `entry`=7158;
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(7158, 5303, 0, 0); -- Deadwood Shaman
